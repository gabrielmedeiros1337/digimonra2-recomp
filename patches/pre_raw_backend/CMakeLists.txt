cmake_minimum_required(VERSION 3.20)
project(DigimonRecompTest C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

# Paths
set(DOLRECOMP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ModernGekko-Template/lib/DolRecomp")
set(GENERATED_DIR "${CMAKE_CURRENT_SOURCE_DIR}/recompiled_code/generated")
set(SDL2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/SDL2")

# Include directories
include_directories(
    ${DOLRECOMP_DIR}/src
    ${GENERATED_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src_test
    ${SDL2_DIR}/include
)

# Collect all chunk source files
file(GLOB CHUNK_SOURCES "${GENERATED_DIR}/chunks/*.c")

# DolRecomp CPU source
set(CPU_SOURCES
    ${DOLRECOMP_DIR}/src/cpu/cpu.c
)

# Test harness executable
add_executable(digimon_test
    src_test/frame_timing.c
    src_test/gx_frame.c
    src_test/cpu_frame.c
    src_test/test_main.c
    src_test/dol_loader.c
    src_test/dvd_vfs.c
    src_test/video_audio.c
    src_test/ax_hle.c
    src_test/platform_tests.c
    src_test/native_ram.c
    src_test/native_blocks.c
    src_test/native_float.c
    src_test/hot_float.c
    src_test/native_copy.c
    src_test/sdk_floor.c
    src_test/sdk_vec.c
    src_test/sdk_mtx44.c
    src_test/skinning_environment.c
    src_test/skinning_accumulate.c
    src_test/paired_skinning.c
    src_test/locked_cache.c
    src_test/os_context.c
    src_test/hle_callbacks.c
    src_test/input.c
    src_test/gx_gl.c
    src_test/gx_pipe.c
    src_test/vertex_completion.c
    ${GENERATED_DIR}/generated.c
    ${CHUNK_SOURCES}
    ${CPU_SOURCES}
)

target_compile_definitions(digimon_test PRIVATE DOLRECOMP_RAM_TRACKING=0)

target_link_libraries(digimon_test PRIVATE
    opengl32
    "${SDL2_DIR}/lib/x64/SDL2.lib"
    "${SDL2_DIR}/lib/x64/SDL2main.lib"
)

if(MSVC)
    # Recovered O2 baseline; preserve runtime arithmetic contracts.
    string(REPLACE " /Ob2 " " " CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
    set_property(SOURCE ${CPU_SOURCES} APPEND PROPERTY COMPILE_OPTIONS /Ob3 /Oi)
    target_compile_options(digimon_test PRIVATE /MP /O2 /W3 /wd4996)
    target_link_options(digimon_test PRIVATE "/MAP:$<TARGET_FILE_DIR:digimon_test>/digimon_test.map")
    # Small, bounded RAM helpers only; keep large exceptional FP helpers out of line.
    foreach(CHUNK_SOURCE IN LISTS CHUNK_SOURCES)
        set_property(SOURCE "${CHUNK_SOURCE}" APPEND PROPERTY COMPILE_OPTIONS /FIprimary_ram.h)
    endforeach()
    option(DIGIMON_NATIVE_RAM_FASTPATH "Experimental bounded RAM adapter (no measured combat gain)" OFF)
    if(DIGIMON_NATIVE_RAM_FASTPATH)
        foreach(CHUNK_SOURCE IN LISTS CHUNK_SOURCES)
            if(CHUNK_SOURCE MATCHES "_(801C34C0|8020B4C0|8023B4C0|802434C0|802474C0|8024B4C0|802734C0|802774C0|802834C0|8028B4C0)\\.c$")
                set_property(SOURCE "${CHUNK_SOURCE}" APPEND PROPERTY COMPILE_DEFINITIONS DOLRECOMP_CPU_HEADER="cpu_native_adapter.h")
            endif()
        endforeach()
    endif()
    option(DIGIMON_NATIVE_BLOCK_ENTRIES "Reach SIMD loops through intra-chunk branches" ON)
    if(DIGIMON_NATIVE_BLOCK_ENTRIES)
        set_property(SOURCE src_test/platform_tests.c APPEND PROPERTY COMPILE_DEFINITIONS DIGIMON_TEST_BLOCK_ADAPTER=1)
        foreach(CHUNK_SOURCE IN LISTS CHUNK_SOURCES)
            if(CHUNK_SOURCE MATCHES "_(8024B4C0|802B34C0)\\.c$")
                set_property(SOURCE "${CHUNK_SOURCE}" PROPERTY COMPILE_DEFINITIONS DOLRECOMP_CPU_HEADER="cpu_block_adapter.h")
                if(DIGIMON_NATIVE_RAM_FASTPATH AND CHUNK_SOURCE MATCHES "_8024B4C0\\.c$")
                    set_property(SOURCE "${CHUNK_SOURCE}" APPEND PROPERTY COMPILE_DEFINITIONS DIGIMON_NATIVE_RAM_IN_BLOCK=1)
                endif()
            endif()
        endforeach()
    endif()
    foreach(CHUNK_SOURCE IN LISTS CHUNK_SOURCES)
        if(CHUNK_SOURCE MATCHES "_(8023B4C0|802474C0|8024B4C0)\\.c$")
            set_property(SOURCE "${CHUNK_SOURCE}" APPEND PROPERTY COMPILE_OPTIONS /FInative_copy_adapter.h)
        endif()
    endforeach()
    option(DIGIMON_ENABLE_IPO "Inline CPU/memory helpers across generated chunks in Release" ON)
    foreach(CHUNK_SOURCE IN LISTS CHUNK_SOURCES)
        if(CHUNK_SOURCE MATCHES "_(8028B4C0|8029B4C0)\\.c$")
            set_property(SOURCE "${CHUNK_SOURCE}" PROPERTY COMPILE_DEFINITIONS DOLRECOMP_CPU_HEADER="cpu_math_adapter.h")
        endif()
    endforeach()
    # Compact hot paths only. Exceptional mappings stay out of line; avoid
    # force-inlining the entire reference runtime into every chunk.
    foreach(CHUNK_SOURCE IN LISTS CHUNK_SOURCES)
        set_property(SOURCE "${CHUNK_SOURCE}" APPEND PROPERTY COMPILE_OPTIONS /FIhot_float_adapter.h)
    endforeach()
    option(DIGIMON_NATIVE_FLOAT_BITS "Experimental compact float bit mappings (no measured combat gain)" OFF)
    if(DIGIMON_NATIVE_FLOAT_BITS)
        target_compile_definitions(digimon_test PRIVATE DIGIMON_FLOAT_BITS_COMPILED=1)
        foreach(CHUNK_SOURCE IN LISTS CHUNK_SOURCES)
            if(CHUNK_SOURCE MATCHES "_(801034C0|801C34C0|801CB4C0|8020B4C0|8023B4C0|8023F4C0|802434C0|802474C0|8024B4C0|802734C0|802774C0|802834C0|8028B4C0|8029B4C0)\\.c$")
                set_property(SOURCE "${CHUNK_SOURCE}" APPEND PROPERTY COMPILE_OPTIONS /FIgenerated_float_adapter.h)
            endif()
        endforeach()
    endif()
    if(DIGIMON_ENABLE_IPO)
        set_property(TARGET digimon_test PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
    endif()
    set(DIGIMON_PGO_MODE "OFF" CACHE STRING "Release PGO mode: OFF, GENERATE or USE")
    set_property(CACHE DIGIMON_PGO_MODE PROPERTY STRINGS OFF GENERATE USE)
    set(DIGIMON_PGO_DATABASE "${CMAKE_BINARY_DIR}/pgo/digimon_test.pgd" CACHE FILEPATH "MSVC PGO database")
    set(DIGIMON_PGO_COUNTS "" CACHE STRING "Captured PGC files for USE (semicolon-separated)")
    if(NOT DIGIMON_PGO_MODE MATCHES "^(OFF|GENERATE|USE)$")
        message(FATAL_ERROR "DIGIMON_PGO_MODE must be OFF, GENERATE or USE")
    endif()
    if(NOT DIGIMON_PGO_MODE STREQUAL "OFF")
        if(NOT DIGIMON_ENABLE_IPO)
            message(FATAL_ERROR "PGO requires DIGIMON_ENABLE_IPO=ON")
        endif()
        get_filename_component(PGO_DIRECTORY "${DIGIMON_PGO_DATABASE}" DIRECTORY)
        file(MAKE_DIRECTORY "${PGO_DIRECTORY}")
        target_link_options(digimon_test PRIVATE "$<$<CONFIG:Release>:/LTCG>" "$<$<CONFIG:Release>:/INCREMENTAL:NO>")
        if(DIGIMON_PGO_MODE STREQUAL "GENERATE")
            # Use MSVC's lightweight statistical counters for training. Counter
            # precision across workers affects optimization data, not guest state.
            target_link_options(digimon_test PRIVATE "$<$<CONFIG:Release>:/FASTGENPROFILE:PGD=${DIGIMON_PGO_DATABASE}>")
        else()
            if(NOT EXISTS "${DIGIMON_PGO_DATABASE}")
                message(FATAL_ERROR "PGO database missing; build GENERATE and collect training first")
            endif()
            if(NOT DIGIMON_PGO_COUNTS)
                message(FATAL_ERROR "USE requires DIGIMON_PGO_COUNTS with captured PGC files")
            endif()
            # Stage a fresh database per link. MSVC automatically merges PGCs;
            # reusing a merged database produces duplicate/missing-data warnings.
            get_filename_component(MSVC_TOOL_DIRECTORY "${CMAKE_C_COMPILER}" DIRECTORY)
            string(SHA256 PGO_INPUT_HASH "${DIGIMON_PGO_DATABASE};${DIGIMON_PGO_COUNTS}")
            string(SUBSTRING "${PGO_INPUT_HASH}" 0 12 PGO_INPUT_HASH)
            set(PGO_USE_DIRECTORY "${CMAKE_BINARY_DIR}/pgo_use/${PGO_INPUT_HASH}")
            set(PGO_USE_DATABASE "${PGO_USE_DIRECTORY}/digimon_test.pgd")
            file(MAKE_DIRECTORY "${PGO_USE_DIRECTORY}")
            add_custom_command(TARGET digimon_test PRE_LINK
                COMMAND ${CMAKE_COMMAND} -E copy "${DIGIMON_PGO_DATABASE}" "${PGO_USE_DATABASE}"
                COMMAND "${MSVC_TOOL_DIRECTORY}/pgomgr.exe" /clear "${PGO_USE_DATABASE}")
            set(PGO_COUNT_INDEX 0)
            foreach(PGO_COUNT_FILE IN LISTS DIGIMON_PGO_COUNTS)
                if(NOT EXISTS "${PGO_COUNT_FILE}")
                    message(FATAL_ERROR "Captured PGC missing: ${PGO_COUNT_FILE}")
                endif()
                math(EXPR PGO_COUNT_INDEX "${PGO_COUNT_INDEX} + 1")
                add_custom_command(TARGET digimon_test PRE_LINK
                    COMMAND ${CMAKE_COMMAND} -E copy "${PGO_COUNT_FILE}" "${PGO_USE_DIRECTORY}/digimon_test!${PGO_COUNT_INDEX}.pgc")
            endforeach()
            target_link_options(digimon_test PRIVATE "$<$<CONFIG:Release>:/USEPROFILE:PGD=${PGO_USE_DATABASE}>")
        endif()
    endif()
endif()

set(XXHASH_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ModernGekko-Template/lib/ModernGekko/vendor/dolphin/Externals/xxhash/xxHash")
if(EXISTS "${XXHASH_DIR}/xxhash.h")
    set_property(SOURCE src_test/gx_pipe.c src_test/gx_gl.c APPEND PROPERTY INCLUDE_DIRECTORIES "${XXHASH_DIR}")
    set_property(SOURCE src_test/gx_pipe.c src_test/gx_gl.c APPEND PROPERTY COMPILE_DEFINITIONS DIGIMON_XXHASH=1)
endif()

# The executable must find the same SDL version used at link time.
add_custom_command(TARGET digimon_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SDL2_DIR}/lib/x64/SDL2.dll" "$<TARGET_FILE_DIR:digimon_test>")

if(MSVC AND DIGIMON_PGO_MODE STREQUAL "GENERATE")
    get_filename_component(MSVC_TOOL_DIRECTORY "${CMAKE_C_COMPILER}" DIRECTORY)
    if(NOT EXISTS "${MSVC_TOOL_DIRECTORY}/pgort140.dll")
        message(FATAL_ERROR "MSVC PGO runtime pgort140.dll not found beside cl.exe")
    endif()
    add_custom_command(TARGET digimon_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${MSVC_TOOL_DIRECTORY}/pgort140.dll" "$<TARGET_FILE_DIR:digimon_test>")
endif()

# Freely generated DSP coefficients shipped by the pinned Dolphin checkout.
set(DSP_COEFFICIENTS "${CMAKE_CURRENT_SOURCE_DIR}/ModernGekko-Template/lib/ModernGekko/vendor/dolphin/Data/Sys/GC/dsp_coef.bin")
if(EXISTS "${DSP_COEFFICIENTS}")
    add_custom_command(TARGET digimon_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${DSP_COEFFICIENTS}" "$<TARGET_FILE_DIR:digimon_test>")
endif()

enable_testing()
add_executable(locked_cache_contracts src_test/locked_cache_tests.c src_test/locked_cache.c ${CPU_SOURCES})
if(MSVC)
    target_compile_options(locked_cache_contracts PRIVATE /O2 /W3 /wd4996)
endif()
add_test(NAME locked_cache_contracts COMMAND locked_cache_contracts)
add_executable(native_ram_contracts src_test/native_ram_tests.c src_test/native_ram.c ${CPU_SOURCES})
if(MSVC)
    target_compile_options(native_ram_contracts PRIVATE /O2 /W3 /wd4996)
endif()
add_test(NAME native_ram_contracts COMMAND native_ram_contracts)
add_test(NAME platform_contracts COMMAND digimon_test --self-test)

add_test(NAME platform_contracts_opengl COMMAND digimon_test --self-test)
set_tests_properties(platform_contracts_opengl PROPERTIES ENVIRONMENT "TEST_OPENGL=1")

add_executable(vertex_completion_contracts src_test/vertex_completion_tests.c src_test/vertex_completion.c)
target_link_libraries(vertex_completion_contracts PRIVATE "${SDL2_DIR}/lib/x64/SDL2.lib")
if(MSVC)
    target_compile_options(vertex_completion_contracts PRIVATE /O2 /W3 /wd4996)
endif()
add_custom_command(TARGET vertex_completion_contracts POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2_DIR}/lib/x64/SDL2.dll" "$<TARGET_FILE_DIR:vertex_completion_contracts>")
add_test(NAME vertex_completion_contracts COMMAND vertex_completion_contracts)

# Independent SDK oracle: the unchanged generated instruction sequence, test-only.
file(GLOB MTX44_CHUNK "${GENERATED_DIR}/chunks/*_802B34C0.c")
list(LENGTH MTX44_CHUNK MTX44_CHUNK_COUNT)
if(NOT MTX44_CHUNK_COUNT EQUAL 1)
    message(FATAL_ERROR "Expected one SDK matrix chunk")
endif()
file(READ "${MTX44_CHUNK}" MTX44_CHUNK_TEXT)
string(FIND "${MTX44_CHUNK_TEXT}" "label_802B4D08:" MTX44_BEGIN)
string(FIND "${MTX44_CHUNK_TEXT}" "label_802B4E0C:" MTX44_END)
if(MTX44_BEGIN LESS 0 OR MTX44_END LESS MTX44_BEGIN)
    message(FATAL_ERROR "SDK matrix oracle boundaries missing")
endif()
math(EXPR MTX44_LENGTH "${MTX44_END}-${MTX44_BEGIN}")
string(SUBSTRING "${MTX44_CHUNK_TEXT}" ${MTX44_BEGIN} ${MTX44_LENGTH} MTX44_BODY)
string(REGEX MATCHALL "// 802B[0-9A-F]+:" MTX44_INSTRUCTIONS "${MTX44_BODY}")
list(LENGTH MTX44_INSTRUCTIONS MTX44_COUNT)
if(NOT MTX44_COUNT EQUAL 65)
    message(FATAL_ERROR "SDK matrix oracle instruction count changed")
endif()
set(MTX44_REFERENCE "${CMAKE_BINARY_DIR}/mtx44_reference.c")
set(MTX44_REFERENCE_TEXT "#include \"cpu/cpu.h\"
void test_mtx44_original(CPUState* ctx){
${MTX44_BODY}
return_dispatch_802B34C0:return;
}
")
if(EXISTS "${MTX44_REFERENCE}")
    file(READ "${MTX44_REFERENCE}" MTX44_PREVIOUS)
endif()
if(NOT MTX44_PREVIOUS STREQUAL MTX44_REFERENCE_TEXT)
    file(WRITE "${MTX44_REFERENCE}" "${MTX44_REFERENCE_TEXT}")
endif()
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${MTX44_CHUNK}")
add_executable(sdk_mtx44_contracts src_test/sdk_mtx44_tests.c src_test/sdk_mtx44.c src_test/locked_cache.c "${MTX44_REFERENCE}" ${CPU_SOURCES})
if(MSVC)
    target_compile_options(sdk_mtx44_contracts PRIVATE /O2 /W3 /wd4996 /wd4102)
endif()
add_test(NAME sdk_mtx44_contracts COMMAND sdk_mtx44_contracts)
add_executable(native_float_contracts src_test/native_float_tests.c src_test/native_float.c)
file(READ "${GENERATED_DIR}/generated.h" GENERATED_FLOAT_HEADER)
string(FIND "${GENERATED_FLOAT_HEADER}" "static inline f64 dolrecomp_f32_from_bits" FLOAT_REFERENCE_START)
string(FIND "${GENERATED_FLOAT_HEADER}" "static inline f64 dolrecomp_f64_from_bits" FLOAT_REFERENCE_END)
if(FLOAT_REFERENCE_START LESS 0 OR FLOAT_REFERENCE_END LESS FLOAT_REFERENCE_START)
    message(FATAL_ERROR "Cannot extract original generated float bit helpers")
endif()
math(EXPR FLOAT_REFERENCE_LENGTH "${FLOAT_REFERENCE_END}-${FLOAT_REFERENCE_START}")
string(SUBSTRING "${GENERATED_FLOAT_HEADER}" ${FLOAT_REFERENCE_START} ${FLOAT_REFERENCE_LENGTH} FLOAT_REFERENCE_BODY)
set(FLOAT_REFERENCE_TEXT "#include \"cpu/cpu.h\"\n${FLOAT_REFERENCE_BODY}")
set(FLOAT_REFERENCE_PATH "${CMAKE_BINARY_DIR}/float_bits_reference.h")
set(FLOAT_REFERENCE_OLD "")
if(EXISTS "${FLOAT_REFERENCE_PATH}")
    file(READ "${FLOAT_REFERENCE_PATH}" FLOAT_REFERENCE_OLD)
endif()
if(NOT FLOAT_REFERENCE_TEXT STREQUAL FLOAT_REFERENCE_OLD)
    file(WRITE "${FLOAT_REFERENCE_PATH}" "${FLOAT_REFERENCE_TEXT}")
endif()
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${GENERATED_DIR}/generated.h")
target_include_directories(native_float_contracts PRIVATE "${CMAKE_BINARY_DIR}")
target_compile_definitions(native_float_contracts PRIVATE DIGIMON_FLOAT_BITS_REFERENCE=1)
if(MSVC)
    target_compile_options(native_float_contracts PRIVATE /O2 /W3)
endif()
add_test(NAME native_float_contracts COMMAND native_float_contracts)
add_executable(gx_gpu_xf_contracts src_test/gx_gl_xf_tests.c src_test/gx_gl.c src_test/frame_timing.c)
target_link_libraries(gx_gpu_xf_contracts PRIVATE opengl32 "${SDL2_DIR}/lib/x64/SDL2.lib")
if(MSVC)
    target_compile_options(gx_gpu_xf_contracts PRIVATE /O2 /W3 /wd4996)
endif()
add_custom_command(TARGET gx_gpu_xf_contracts POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2_DIR}/lib/x64/SDL2.dll" "$<TARGET_FILE_DIR:gx_gpu_xf_contracts>")
add_test(NAME gx_gpu_xf_contracts COMMAND gx_gpu_xf_contracts)

# Independent oracle copied from the protected generated source, never patched there.
file(GLOB BOUNDS_CHUNK "${GENERATED_DIR}/chunks/*_802774C0.c")
file(READ "${BOUNDS_CHUNK}" BOUNDS_SOURCE)
set(BOUNDS_REFERENCE_TEXT "#include \"float_bits_reference.h\"\n#define DOLRECOMP_C_LOOP_CYCLE_BUDGET 256\nextern bool g_bounds_oracle_stop;\n")
foreach(SPEC "min;80278E10;80278EF4;80278E30" "max;80278EF4;80279000;80278F10")
    list(GET SPEC 0 NAME)
    list(GET SPEC 1 FIRST)
    list(GET SPEC 2 LAST)
    list(GET SPEC 3 STOP)
    string(FIND "${BOUNDS_SOURCE}" "label_${FIRST}:" BEGIN)
    string(FIND "${BOUNDS_SOURCE}" "label_${LAST}:" END)
    math(EXPR LENGTH "${END}-${BEGIN}")
    string(SUBSTRING "${BOUNDS_SOURCE}" ${BEGIN} ${LENGTH} BODY)
    string(REPLACE "label_${STOP}:" "label_${STOP}: if(g_bounds_oracle_stop){ctx->pc=0x${STOP}u;return;}" BODY "${BODY}")
    string(APPEND BOUNDS_REFERENCE_TEXT "void ref_bounds_${NAME}(CPUState* ctx){\n${BODY}\nreturn_dispatch_802774C0:return;\n}\n")
endforeach()
file(GLOB AABB_CHUNK "${GENERATED_DIR}/chunks/*_802734C0.c")
file(READ "${AABB_CHUNK}" AABB_SOURCE)
foreach(SPEC "expand;80276CC0;80276D6C" "union;80276D6C;80276E20")
    list(GET SPEC 0 NAME)
    list(GET SPEC 1 FIRST)
    list(GET SPEC 2 LAST)
    string(FIND "${AABB_SOURCE}" "label_${FIRST}:" BEGIN)
    string(FIND "${AABB_SOURCE}" "label_${LAST}:" END)
    math(EXPR LENGTH "${END}-${BEGIN}")
    string(SUBSTRING "${AABB_SOURCE}" ${BEGIN} ${LENGTH} BODY)
    string(APPEND BOUNDS_REFERENCE_TEXT "void ref_aabb_${NAME}(CPUState* ctx){\n${BODY}\nreturn_dispatch_802734C0:return;\n}\n")
endforeach()
set(BOUNDS_REFERENCE "${CMAKE_BINARY_DIR}/bounds_reference.c")
if(EXISTS "${BOUNDS_REFERENCE}")
    file(READ "${BOUNDS_REFERENCE}" BOUNDS_PREVIOUS)
endif()
if(NOT BOUNDS_PREVIOUS STREQUAL BOUNDS_REFERENCE_TEXT)
    file(WRITE "${BOUNDS_REFERENCE}" "${BOUNDS_REFERENCE_TEXT}")
endif()
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${BOUNDS_CHUNK}")
add_executable(sdk_bounds_contracts src_test/sdk_bounds_tests.c src_test/sdk_bounds.c "${BOUNDS_REFERENCE}" ${CPU_SOURCES})
if(MSVC)
    target_compile_options(sdk_bounds_contracts PRIVATE /O2 /W3 /wd4996 /wd4102)
endif()
target_include_directories(sdk_bounds_contracts PRIVATE "${CMAKE_BINARY_DIR}")
add_test(NAME sdk_bounds_contracts COMMAND sdk_bounds_contracts)

string(FIND "${GENERATED_FLOAT_HEADER}" "static inline u32 dolrecomp_rotl32" FULL_FIRST)
string(FIND "${GENERATED_FLOAT_HEADER}" "// Function entry points" FULL_LAST)
math(EXPR FULL_LENGTH "${FULL_LAST}-${FULL_FIRST}")
string(SUBSTRING "${GENERATED_FLOAT_HEADER}" ${FULL_FIRST} ${FULL_LENGTH} FULL_BODY)
file(WRITE "${CMAKE_BINARY_DIR}/full_bits_reference.h" "#include \"cpu/cpu.h\"\n${FULL_BODY}")
# Independent, unchanged guest oracles for native floor and matrix-copy loops.
file(GLOB TOP_CHUNK "${GENERATED_DIR}/chunks/*_8029B4C0.c")
file(READ "${TOP_CHUNK}" TOP_SOURCE)
string(FIND "${TOP_SOURCE}" "label_8029D888:" FIRST)
string(FIND "${TOP_SOURCE}" "label_8029D9F4:" LAST)
math(EXPR LENGTH "${LAST}-${FIRST}")
string(SUBSTRING "${TOP_SOURCE}" ${FIRST} ${LENGTH} BODY)
string(REPLACE "label_8029D88C:" "label_8029D88C: if(g_floor_oracle_stop){ctx->pc=0x8029D88Cu;return;}" BODY "${BODY}")
set(TOP_TEXT "#include \"full_bits_reference.h\"\n#define DOLRECOMP_C_LOOP_CYCLE_BUDGET 256\nextern bool g_floor_oracle_stop;\nvoid ref_floor(CPUState* ctx){\n${BODY}\nreturn_dispatch_8029B4C0:return;\n}\n")
set(N 0)
foreach(SPEC "8023B4C0;8023DA4C" "8023B4C0;8023DCC4" "802474C0;8024B138" "8024B4C0;8024D468")
    list(GET SPEC 0 BASE)
    list(GET SPEC 1 LOOP)
    file(GLOB CHUNK "${GENERATED_DIR}/chunks/*_${BASE}.c")
    file(READ "${CHUNK}" SOURCE)
    string(FIND "${SOURCE}" "static void loop_${LOOP}(CPUState* ctx) {" FIRST)
    string(SUBSTRING "${SOURCE}" ${FIRST} -1 REST)
    string(FIND "${REST}" "\nstatic void " LAST)
    string(SUBSTRING "${REST}" 0 ${LAST} BODY)
    string(REPLACE "static void loop_${LOOP}" "void ref_copy_${N}" BODY "${BODY}")
    string(APPEND TOP_TEXT "${BODY}\n")
    math(EXPR N "${N}+1")
endforeach()
file(GLOB VEC_CHUNK "${GENERATED_DIR}/chunks/*_8028B4C0.c")
file(READ "${VEC_CHUNK}" VEC_SOURCE)
foreach(SPEC "0;8028BEDC;8028BF58" "1;8028BF58;8028BFD4")
    list(GET SPEC 0 NAME)
    list(GET SPEC 1 FIRST)
    list(GET SPEC 2 LAST)
    string(FIND "${VEC_SOURCE}" "label_${FIRST}:" BEGIN)
    string(FIND "${VEC_SOURCE}" "label_${LAST}:" END)
    math(EXPR LENGTH "${END}-${BEGIN}")
    string(SUBSTRING "${VEC_SOURCE}" ${BEGIN} ${LENGTH} BODY)
    string(APPEND TOP_TEXT "void ref_vec_${NAME}(CPUState* ctx){\n${BODY}\nreturn_dispatch_8028B4C0:return;\n}\n")
endforeach()
set(TOP_REFERENCE "${CMAKE_BINARY_DIR}/native_top_reference.c")
file(WRITE "${TOP_REFERENCE}" "${TOP_TEXT}")
add_executable(native_top_contracts src_test/native_top_tests.c src_test/native_copy.c src_test/sdk_floor.c src_test/sdk_vec.c "${TOP_REFERENCE}" ${CPU_SOURCES})
target_include_directories(native_top_contracts PRIVATE "${CMAKE_BINARY_DIR}")
if(MSVC)
    target_compile_options(native_top_contracts PRIVATE /O2 /W3 /wd4102)
endif()
add_test(NAME native_top_contracts COMMAND native_top_contracts)
add_executable(gx_async_contracts src_test/gx_decode_async_tests.c src_test/gx_decode_async.c)
target_link_libraries(gx_async_contracts PRIVATE "${SDL2_DIR}/lib/x64/SDL2.lib")
add_custom_command(TARGET gx_async_contracts POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2_DIR}/lib/x64/SDL2.dll" "$<TARGET_FILE_DIR:gx_async_contracts>")
add_test(NAME gx_async_contracts COMMAND gx_async_contracts)

add_executable(hot_float_contracts src_test/hot_float_tests.c src_test/hot_float.c src_test/native_float.c ${CPU_SOURCES})
target_include_directories(hot_float_contracts PRIVATE "${CMAKE_BINARY_DIR}")
target_compile_definitions(hot_float_contracts PRIVATE DIGIMON_FLOAT_BITS_REFERENCE=1)
if(MSVC)
    target_compile_options(hot_float_contracts PRIVATE /O2 /W3)
endif()
add_test(NAME hot_float_contracts COMMAND hot_float_contracts)

add_executable(gx_images_contracts src_test/gx_images_tests.c src_test/gx_images.c ${CPU_SOURCES})
if(MSVC)
    target_compile_options(gx_images_contracts PRIVATE /O2 /W3)
endif()
add_test(NAME gx_images_contracts COMMAND gx_images_contracts)



add_executable(frame_pipeline_contracts src_test/frame_pipeline_tests.c src_test/gx_frame.c src_test/cpu_frame.c src_test/frame_timing.c)
target_link_libraries(frame_pipeline_contracts PRIVATE "${SDL2_DIR}/lib/x64/SDL2.lib")
if(MSVC)
    target_compile_options(frame_pipeline_contracts PRIVATE /O2 /W3)
endif()
add_custom_command(TARGET frame_pipeline_contracts POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2_DIR}/lib/x64/SDL2.dll" "$<TARGET_FILE_DIR:frame_pipeline_contracts>")
add_test(NAME frame_pipeline_contracts COMMAND frame_pipeline_contracts)
