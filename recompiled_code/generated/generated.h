// DolRecomp output
// cpu: gekko

#ifndef RECOMP_GENERATED_H
#define RECOMP_GENERATED_H

#define DOLRECOMP_CPU_GEKKO 1
#define DOLRECOMP_CPU_NAME "gekko"

#include <string.h>
#include <math.h>
#ifndef DOLRECOMP_CPU_HEADER
#define DOLRECOMP_CPU_HEADER "cpu/cpu.h"
#endif
#include DOLRECOMP_CPU_HEADER

#ifndef DOLRECOMP_C_LOOP_CYCLE_BUDGET
#define DOLRECOMP_C_LOOP_CYCLE_BUDGET 256
#endif

/* Cross-chunk calls turn guest recursion into host recursion, and a
   chunk frame is not small. Without a ceiling a deep guest call chain
   overflows the host stack, which is a crash rather than a slow
   emulator. Past the limit the call site falls back to returning to
   the chassis, which is always correct -- ctx->pc already names the
   target, so the chassis simply dispatches it as it did before.
   The counter is plain static, not atomic: the chassis runs the module
   on one CPU thread. */
#ifndef DOLRECOMP_C_MAX_CALL_DEPTH
#define DOLRECOMP_C_MAX_CALL_DEPTH 24
#endif
extern unsigned dolrecomp_call_depth;
static inline int dolrecomp_call_enter(void) {
    if (dolrecomp_call_depth >= (unsigned)DOLRECOMP_C_MAX_CALL_DEPTH)
        return 0;
    dolrecomp_call_depth++;
    return 1;
}
static inline void dolrecomp_call_leave(void) {
    if (dolrecomp_call_depth)
        dolrecomp_call_depth--;
}

static inline u32 dolrecomp_rotl32(u32 value, u32 sh) {
    sh &= 31u;
    return sh ? ((value << sh) | (value >> (32u - sh))) : value;
}

static inline f64 dolrecomp_f32_from_bits(u32 bits) {
    u64 x = bits;
    u64 exp = (x >> 23) & 0xFFu;
    u64 frac = x & 0x007FFFFFu;
    u64 result;
    if (exp > 0 && exp < 255) {
        u64 y = !(exp >> 7);
        u64 z = (y << 61) | (y << 60) | (y << 59);
        result = ((x & 0xC0000000u) << 32) | z |
                 ((x & 0x3FFFFFFFu) << 29);
    } else if (exp == 0 && frac != 0) {
        exp = 1023 - 126;
        do {
            frac <<= 1;
            exp -= 1;
        } while ((frac & 0x00800000u) == 0);
        result = ((x & 0x80000000u) << 32) | (exp << 52) |
                 ((frac & 0x007FFFFFu) << 29);
    } else {
        u64 y = exp >> 7;
        u64 z = (y << 61) | (y << 60) | (y << 59);
        result = ((x & 0xC0000000u) << 32) | z |
                 ((x & 0x3FFFFFFFu) << 29);
    }
    f64 value;
    memcpy(&value, &result, sizeof(value));
    return value;
}

static inline u32 dolrecomp_f32_to_bits(f64 value) {
    u64 bits;
    memcpy(&bits, &value, sizeof(bits));
    u32 exp = (u32)((bits >> 52) & 0x7FFu);
    if (exp > 896 || (bits & 0x7FFFFFFFFFFFFFFFull) == 0) {
        return (u32)(((bits >> 32) & 0xC0000000u) |
                     ((bits >> 29) & 0x3FFFFFFFu));
    }
    if (exp >= 874) {
        u32 result =
            (u32)(0x80000000u | ((bits & 0x000FFFFFFFFFFFFFull) >> 21));
        result >>= 905 - exp;
        result |= (u32)((bits >> 32) & 0x80000000u);
        return result;
    }
    return (u32)(((bits >> 32) & 0xC0000000u) |
                 ((bits >> 29) & 0x3FFFFFFFu));
}

static inline f64 dolrecomp_f64_from_bits(u64 bits) {
    f64 value;
    memcpy(&value, &bits, sizeof(value));
    return value;
}

static inline u64 dolrecomp_f64_to_bits(f64 value) {
    u64 bits;
    memcpy(&bits, &value, sizeof(bits));
    return bits;
}

static inline f64 dolrecomp_ps_from_bits(u32 bits) {
    return dolrecomp_f32_from_bits(bits);
}

static inline u32 dolrecomp_ps_to_bits(f64 value) {
    return dolrecomp_f32_to_bits(value);
}


// Function entry points
void func_80003100(CPUState* ctx);
void func_800034C0(CPUState* ctx);
void func_800074C0(CPUState* ctx);
void func_8000B4C0(CPUState* ctx);
void func_8000F4C0(CPUState* ctx);
void func_800134C0(CPUState* ctx);
void func_800174C0(CPUState* ctx);
void func_8001B4C0(CPUState* ctx);
void func_8001F4C0(CPUState* ctx);
void func_800234C0(CPUState* ctx);
void func_800274C0(CPUState* ctx);
void func_8002B4C0(CPUState* ctx);
void func_8002F4C0(CPUState* ctx);
void func_800334C0(CPUState* ctx);
void func_800374C0(CPUState* ctx);
void func_8003B4C0(CPUState* ctx);
void func_8003F4C0(CPUState* ctx);
void func_800434C0(CPUState* ctx);
void func_800474C0(CPUState* ctx);
void func_8004B4C0(CPUState* ctx);
void func_8004F4C0(CPUState* ctx);
void func_800534C0(CPUState* ctx);
void func_800574C0(CPUState* ctx);
void func_8005B4C0(CPUState* ctx);
void func_8005F4C0(CPUState* ctx);
void func_800634C0(CPUState* ctx);
void func_800674C0(CPUState* ctx);
void func_8006B4C0(CPUState* ctx);
void func_8006F4C0(CPUState* ctx);
void func_800734C0(CPUState* ctx);
void func_800774C0(CPUState* ctx);
void func_8007B4C0(CPUState* ctx);
void func_8007F4C0(CPUState* ctx);
void func_800834C0(CPUState* ctx);
void func_800874C0(CPUState* ctx);
void func_8008B4C0(CPUState* ctx);
void func_8008F4C0(CPUState* ctx);
void func_800934C0(CPUState* ctx);
void func_800974C0(CPUState* ctx);
void func_8009B4C0(CPUState* ctx);
void func_8009F4C0(CPUState* ctx);
void func_800A34C0(CPUState* ctx);
void func_800A74C0(CPUState* ctx);
void func_800AB4C0(CPUState* ctx);
void func_800AF4C0(CPUState* ctx);
void func_800B34C0(CPUState* ctx);
void func_800B74C0(CPUState* ctx);
void func_800BB4C0(CPUState* ctx);
void func_800BF4C0(CPUState* ctx);
void func_800C34C0(CPUState* ctx);
void func_800C74C0(CPUState* ctx);
void func_800CB4C0(CPUState* ctx);
void func_800CF4C0(CPUState* ctx);
void func_800D34C0(CPUState* ctx);
void func_800D74C0(CPUState* ctx);
void func_800DB4C0(CPUState* ctx);
void func_800DF4C0(CPUState* ctx);
void func_800E34C0(CPUState* ctx);
void func_800E74C0(CPUState* ctx);
void func_800EB4C0(CPUState* ctx);
void func_800EF4C0(CPUState* ctx);
void func_800F34C0(CPUState* ctx);
void func_800F74C0(CPUState* ctx);
void func_800FB4C0(CPUState* ctx);
void func_800FF4C0(CPUState* ctx);
void func_801034C0(CPUState* ctx);
void func_801074C0(CPUState* ctx);
void func_8010B4C0(CPUState* ctx);
void func_8010F4C0(CPUState* ctx);
void func_801134C0(CPUState* ctx);
void func_801174C0(CPUState* ctx);
void func_8011B4C0(CPUState* ctx);
void func_8011F4C0(CPUState* ctx);
void func_801234C0(CPUState* ctx);
void func_801274C0(CPUState* ctx);
void func_8012B4C0(CPUState* ctx);
void func_8012F4C0(CPUState* ctx);
void func_801334C0(CPUState* ctx);
void func_801374C0(CPUState* ctx);
void func_8013B4C0(CPUState* ctx);
void func_8013F4C0(CPUState* ctx);
void func_801434C0(CPUState* ctx);
void func_801474C0(CPUState* ctx);
void func_8014B4C0(CPUState* ctx);
void func_8014F4C0(CPUState* ctx);
void func_801534C0(CPUState* ctx);
void func_801574C0(CPUState* ctx);
void func_8015B4C0(CPUState* ctx);
void func_8015F4C0(CPUState* ctx);
void func_801634C0(CPUState* ctx);
void func_801674C0(CPUState* ctx);
void func_8016B4C0(CPUState* ctx);
void func_8016F4C0(CPUState* ctx);
void func_801734C0(CPUState* ctx);
void func_801774C0(CPUState* ctx);
void func_8017B4C0(CPUState* ctx);
void func_8017F4C0(CPUState* ctx);
void func_801834C0(CPUState* ctx);
void func_801874C0(CPUState* ctx);
void func_8018B4C0(CPUState* ctx);
void func_8018F4C0(CPUState* ctx);
void func_801934C0(CPUState* ctx);
void func_801974C0(CPUState* ctx);
void func_8019B4C0(CPUState* ctx);
void func_8019F4C0(CPUState* ctx);
void func_801A34C0(CPUState* ctx);
void func_801A74C0(CPUState* ctx);
void func_801AB4C0(CPUState* ctx);
void func_801AF4C0(CPUState* ctx);
void func_801B34C0(CPUState* ctx);
void func_801B74C0(CPUState* ctx);
void func_801BB4C0(CPUState* ctx);
void func_801BF4C0(CPUState* ctx);
void func_801C34C0(CPUState* ctx);
void func_801C74C0(CPUState* ctx);
void func_801CB4C0(CPUState* ctx);
void func_801CF4C0(CPUState* ctx);
void func_801D34C0(CPUState* ctx);
void func_801D74C0(CPUState* ctx);
void func_801DB4C0(CPUState* ctx);
void func_801DF4C0(CPUState* ctx);
void func_801E34C0(CPUState* ctx);
void func_801E74C0(CPUState* ctx);
void func_801EB4C0(CPUState* ctx);
void func_801EF4C0(CPUState* ctx);
void func_801F34C0(CPUState* ctx);
void func_801F74C0(CPUState* ctx);
void func_801FB4C0(CPUState* ctx);
void func_801FF4C0(CPUState* ctx);
void func_802034C0(CPUState* ctx);
void func_802074C0(CPUState* ctx);
void func_8020B4C0(CPUState* ctx);
void func_8020F4C0(CPUState* ctx);
void func_802134C0(CPUState* ctx);
void func_802174C0(CPUState* ctx);
void func_8021B4C0(CPUState* ctx);
void func_8021F4C0(CPUState* ctx);
void func_802234C0(CPUState* ctx);
void func_802274C0(CPUState* ctx);
void func_8022B4C0(CPUState* ctx);
void func_8022F4C0(CPUState* ctx);
void func_802334C0(CPUState* ctx);
void func_802374C0(CPUState* ctx);
void func_8023B4C0(CPUState* ctx);
void func_8023F4C0(CPUState* ctx);
void func_802434C0(CPUState* ctx);
void func_802474C0(CPUState* ctx);
void func_8024B4C0(CPUState* ctx);
void func_8024F4C0(CPUState* ctx);
void func_802534C0(CPUState* ctx);
void func_802574C0(CPUState* ctx);
void func_8025B4C0(CPUState* ctx);
void func_8025F4C0(CPUState* ctx);
void func_802634C0(CPUState* ctx);
void func_802674C0(CPUState* ctx);
void func_8026B4C0(CPUState* ctx);
void func_8026F4C0(CPUState* ctx);
void func_802734C0(CPUState* ctx);
void func_802774C0(CPUState* ctx);
void func_8027B4C0(CPUState* ctx);
void func_8027F4C0(CPUState* ctx);
void func_802834C0(CPUState* ctx);
void func_802874C0(CPUState* ctx);
void func_8028B4C0(CPUState* ctx);
void func_8028F4C0(CPUState* ctx);
void func_802934C0(CPUState* ctx);
void func_802974C0(CPUState* ctx);
void func_8029B4C0(CPUState* ctx);
void func_8029F4C0(CPUState* ctx);
void func_802A34C0(CPUState* ctx);
void func_802A74C0(CPUState* ctx);
void func_802AB4C0(CPUState* ctx);
void func_802AF4C0(CPUState* ctx);
void func_802B34C0(CPUState* ctx);
void func_802B74C0(CPUState* ctx);
void func_802BB4C0(CPUState* ctx);
void func_802BF4C0(CPUState* ctx);
void func_802C34C0(CPUState* ctx);
void func_802C74C0(CPUState* ctx);
void func_802CB4C0(CPUState* ctx);
void func_802CF4C0(CPUState* ctx);
void func_802D34C0(CPUState* ctx);
void func_802D74C0(CPUState* ctx);
void func_802DB4C0(CPUState* ctx);
void func_802DF4C0(CPUState* ctx);

#define DOLRECOMP_ENTRY_POINT 0x80003100u

typedef void (*DolRecompFunction)(CPUState* ctx);

#if defined(__GNUC__) || defined(__clang__)
#define DOLRECOMP_UNUSED __attribute__((unused))
#else
#define DOLRECOMP_UNUSED
#endif

#if defined(DOLRECOMP_ENABLE_REPLACEMENTS)
int dolrecomp_dispatch_replacement(CPUState* ctx, u32 address);
#else
static inline int dolrecomp_dispatch_replacement(CPUState* ctx, u32 address) {
    (void)ctx;
    (void)address;
    return 0;
}
#endif

static inline DolRecompFunction dolrecomp_find_original(u32 address) {
    if (address >= 0x80003100u && address < 0x800034C0u && ((address - 0x80003100u) & 3u) == 0u) return func_80003100;
    {
        u32 offset = address - 0x800034C0u;
        if (offset < 0x002DDE80u && (offset & 3u) == 0u) {
            static const DolRecompFunction chunk_functions[] = {
                func_800034C0,
                func_800074C0,
                func_8000B4C0,
                func_8000F4C0,
                func_800134C0,
                func_800174C0,
                func_8001B4C0,
                func_8001F4C0,
                func_800234C0,
                func_800274C0,
                func_8002B4C0,
                func_8002F4C0,
                func_800334C0,
                func_800374C0,
                func_8003B4C0,
                func_8003F4C0,
                func_800434C0,
                func_800474C0,
                func_8004B4C0,
                func_8004F4C0,
                func_800534C0,
                func_800574C0,
                func_8005B4C0,
                func_8005F4C0,
                func_800634C0,
                func_800674C0,
                func_8006B4C0,
                func_8006F4C0,
                func_800734C0,
                func_800774C0,
                func_8007B4C0,
                func_8007F4C0,
                func_800834C0,
                func_800874C0,
                func_8008B4C0,
                func_8008F4C0,
                func_800934C0,
                func_800974C0,
                func_8009B4C0,
                func_8009F4C0,
                func_800A34C0,
                func_800A74C0,
                func_800AB4C0,
                func_800AF4C0,
                func_800B34C0,
                func_800B74C0,
                func_800BB4C0,
                func_800BF4C0,
                func_800C34C0,
                func_800C74C0,
                func_800CB4C0,
                func_800CF4C0,
                func_800D34C0,
                func_800D74C0,
                func_800DB4C0,
                func_800DF4C0,
                func_800E34C0,
                func_800E74C0,
                func_800EB4C0,
                func_800EF4C0,
                func_800F34C0,
                func_800F74C0,
                func_800FB4C0,
                func_800FF4C0,
                func_801034C0,
                func_801074C0,
                func_8010B4C0,
                func_8010F4C0,
                func_801134C0,
                func_801174C0,
                func_8011B4C0,
                func_8011F4C0,
                func_801234C0,
                func_801274C0,
                func_8012B4C0,
                func_8012F4C0,
                func_801334C0,
                func_801374C0,
                func_8013B4C0,
                func_8013F4C0,
                func_801434C0,
                func_801474C0,
                func_8014B4C0,
                func_8014F4C0,
                func_801534C0,
                func_801574C0,
                func_8015B4C0,
                func_8015F4C0,
                func_801634C0,
                func_801674C0,
                func_8016B4C0,
                func_8016F4C0,
                func_801734C0,
                func_801774C0,
                func_8017B4C0,
                func_8017F4C0,
                func_801834C0,
                func_801874C0,
                func_8018B4C0,
                func_8018F4C0,
                func_801934C0,
                func_801974C0,
                func_8019B4C0,
                func_8019F4C0,
                func_801A34C0,
                func_801A74C0,
                func_801AB4C0,
                func_801AF4C0,
                func_801B34C0,
                func_801B74C0,
                func_801BB4C0,
                func_801BF4C0,
                func_801C34C0,
                func_801C74C0,
                func_801CB4C0,
                func_801CF4C0,
                func_801D34C0,
                func_801D74C0,
                func_801DB4C0,
                func_801DF4C0,
                func_801E34C0,
                func_801E74C0,
                func_801EB4C0,
                func_801EF4C0,
                func_801F34C0,
                func_801F74C0,
                func_801FB4C0,
                func_801FF4C0,
                func_802034C0,
                func_802074C0,
                func_8020B4C0,
                func_8020F4C0,
                func_802134C0,
                func_802174C0,
                func_8021B4C0,
                func_8021F4C0,
                func_802234C0,
                func_802274C0,
                func_8022B4C0,
                func_8022F4C0,
                func_802334C0,
                func_802374C0,
                func_8023B4C0,
                func_8023F4C0,
                func_802434C0,
                func_802474C0,
                func_8024B4C0,
                func_8024F4C0,
                func_802534C0,
                func_802574C0,
                func_8025B4C0,
                func_8025F4C0,
                func_802634C0,
                func_802674C0,
                func_8026B4C0,
                func_8026F4C0,
                func_802734C0,
                func_802774C0,
                func_8027B4C0,
                func_8027F4C0,
                func_802834C0,
                func_802874C0,
                func_8028B4C0,
                func_8028F4C0,
                func_802934C0,
                func_802974C0,
                func_8029B4C0,
                func_8029F4C0,
                func_802A34C0,
                func_802A74C0,
                func_802AB4C0,
                func_802AF4C0,
                func_802B34C0,
                func_802B74C0,
                func_802BB4C0,
                func_802BF4C0,
                func_802C34C0,
                func_802C74C0,
                func_802CB4C0,
                func_802CF4C0,
                func_802D34C0,
                func_802D74C0,
                func_802DB4C0,
                func_802DF4C0,
            };
            return chunk_functions[offset / 0x00004000u];
        }
    }
    return NULL;
}

static inline int dolrecomp_call_original(CPUState* ctx, u32 address) {
    DolRecompFunction fn = dolrecomp_find_original(address);
    if (!fn) return 0;
    ctx->pc = address;
    fn(ctx);
    return 1;
}

static inline bool dolrecomp_physical_pc_alias(CPUState* ctx, u32 address, u32* alias_out) {
    if (address < ctx->ram_size) {
        *alias_out = address | GC_RAM_BASE;
        return *alias_out != address;
    }
    return false;
}

static inline int dolrecomp_call(CPUState* ctx, u32 address) {
    u32 alias;
    ctx->pc = address;
    if (dolrecomp_dispatch_replacement(ctx, address)) return 1;
    if (ctx->host_call && ppc_host_call(ctx, address)) return 1;
    if (dolrecomp_call_original(ctx, address)) return 1;
    if (dolrecomp_physical_pc_alias(ctx, address, &alias)) {
        ctx->pc = alias;
        if (dolrecomp_dispatch_replacement(ctx, alias)) return 1;
        if (ctx->host_call && ppc_host_call(ctx, alias)) return 1;
        if (dolrecomp_call_original(ctx, alias)) return 1;
    }
    return 0;
}

static inline DOLRECOMP_UNUSED int dolrecomp_run_blocks(CPUState* ctx, u32 max_blocks) {
    u32 blocks = 0;
    while (max_blocks == 0u || blocks < max_blocks) {
        if (!dolrecomp_call(ctx, ctx->pc)) return 0;
        if (ctx->exception) return 0;
        blocks++;
    }
    return 1;
}

#undef DOLRECOMP_UNUSED

#endif /* RECOMP_GENERATED_H */

// end
