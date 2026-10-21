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
    src_test/test_main.c
    src_test/dol_loader.c
    src_test/dvd_vfs.c
    src_test/video_audio.c
    src_test/input.c
    src_test/gx_pipe.c
    ${GENERATED_DIR}/generated.c
    ${CHUNK_SOURCES}
    ${CPU_SOURCES}
)

target_link_libraries(digimon_test PRIVATE
    "${SDL2_DIR}/lib/x64/SDL2.lib"
    "${SDL2_DIR}/lib/x64/SDL2main.lib"
)

if(MSVC)
    target_compile_options(digimon_test PRIVATE /MP /O2 /W3 /wd4996)
endif()
