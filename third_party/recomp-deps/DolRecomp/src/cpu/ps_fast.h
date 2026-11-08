#ifndef DOLRECOMP_PS_FAST_H
#define DOLRECOMP_PS_FAST_H
#include <string.h>
#if defined(_MSC_VER) && defined(_M_X64)
#include <intrin.h>
#include <immintrin.h>
#endif
#if defined(_MSC_VER) && defined(_M_X64)
static __forceinline bool host_fma_available(void) {
    static int available = -1;
    if (available < 0) {
        int info[4];
        __cpuid(info, 1);
        available = (info[2] & ((1 << 12) | (1 << 27) | (1 << 28))) ==
                    ((1 << 12) | (1 << 27) | (1 << 28));
        if (available)
            available = (_xgetbv(0) & 6) == 6;
    }
    return available != 0;
}

static __forceinline bool exact_normal_single(f64 value) {
    u64 bits; memcpy(&bits, &value, sizeof(bits));
    u64 magnitude = bits & 0x7FFFFFFFFFFFFFFFull;
    u32 exponent = (u32)(magnitude >> 52);
    return magnitude == 0 || ((bits & 0x1FFFFFFFull) == 0 && exponent >= 897 && exponent <= 1150);
}

static __forceinline u32 ps_fast_classify(__m128 value) {
    u32 bits = (u32)_mm_cvtsi128_si32(_mm_castps_si128(value));
    u32 sign = bits >> 31, exponent = bits & 0x7F800000u, fraction = bits & 0x007FFFFFu;
    if (exponent == 0x7F800000u) return fraction ? 0x11u : (sign ? 0x09u : 0x05u);
    if (!exponent) return fraction ? (sign ? 0x18u : 0x14u) : (sign ? 0x12u : 0x02u);
    return sign ? 0x08u : 0x04u;
}

static __forceinline void write_paired_vector(CPUState* cpu, u8 d, __m128 result) {
    __m128d widened = _mm_cvtps_pd(result);
    cpu->fpr[d] = _mm_cvtsd_f64(widened);
    cpu->ps1[d] = _mm_cvtsd_f64(_mm_unpackhi_pd(widened, widened));
    if(!g_fast_float_enabled)cpu->fpscr = (cpu->fpscr & ~0x1F000u) | (ps_fast_classify(result) << 12);
}

static __forceinline bool paired_binary_fast(CPUState* cpu, u8 d, u8 a, u8 b, int operation, int scalar) {
    f64 a0 = cpu->fpr[a], a1 = cpu->ps1[a];
    f64 b0 = scalar == 1 ? cpu->ps1[b] : cpu->fpr[b];
    f64 b1 = scalar == 0 ? cpu->fpr[b] : cpu->ps1[b];
    if (!g_fast_float_enabled && (!exact_normal_single(a0) || !exact_normal_single(a1) ||
        !exact_normal_single(b0) || !exact_normal_single(b1)))
        return false;
    __m128 av = _mm_cvtpd_ps(_mm_set_pd(a1, a0));
    __m128 bv = _mm_cvtpd_ps(_mm_set_pd(b1, b0));
    __m128 result = operation == 0 ? _mm_add_ps(av, bv) :
                    operation == 1 ? _mm_sub_ps(av, bv) : _mm_mul_ps(av, bv);
    write_paired_vector(cpu, d, result);
    return true;
}

static __forceinline bool paired_sum_fast(CPUState* cpu, u8 d, u8 a, u8 c, u8 b, bool high) {
    f64 av = cpu->fpr[a], bv = cpu->ps1[b], cv = high ? cpu->fpr[c] : cpu->ps1[c];
    if (!g_fast_float_enabled && (!exact_normal_single(av) || !exact_normal_single(bv) || !exact_normal_single(cv)))
        return false;
    __m128 sum = _mm_add_ss(_mm_set_ss((f32)av), _mm_set_ss((f32)bv));
    __m128 copied = _mm_set_ss((f32)cv);
    write_paired_vector(cpu, d, high ? _mm_unpacklo_ps(copied, sum) : _mm_unpacklo_ps(sum, copied));
    return true;
}

/* For exact binary32 inputs, a fused binary32 operation is precisely the
 * result of the scalar single-FMA path (including its nearest-even tie fix).
 * Preserve that path for wider operands, NaNs and subnormal inputs. */
static __forceinline bool paired_fma_fast(CPUState* cpu, u8 d, u8 a, u8 c, u8 b,
                            bool subtract, bool negative, int scalar) {
    if (!host_fma_available())
        return false;
    f64 a0 = cpu->fpr[a], a1 = cpu->ps1[a];
    f64 b0 = cpu->fpr[b], b1 = cpu->ps1[b];
    f64 c0 = scalar == 1 ? cpu->ps1[c] : cpu->fpr[c];
    f64 c1 = scalar == 0 ? cpu->fpr[c] : cpu->ps1[c];
    if (!g_fast_float_enabled && (!exact_normal_single(a0) || !exact_normal_single(a1) ||
        !exact_normal_single(b0) || !exact_normal_single(b1) ||
        !exact_normal_single(c0) || !exact_normal_single(c1)))
        return false;
    __m128 av = _mm_cvtpd_ps(_mm_set_pd(a1, a0));
    __m128 bv = _mm_cvtpd_ps(_mm_set_pd(b1, b0));
    __m128 cv = _mm_cvtpd_ps(_mm_set_pd(c1, c0));
    if (subtract)
        bv = _mm_xor_ps(bv, _mm_set1_ps(-0.0f));
    __m128 result = _mm_fmadd_ps(av, cv, bv);
    if (negative)
        result = _mm_xor_ps(result, _mm_set1_ps(-0.0f));
    write_paired_vector(cpu, d, result);
    return true;
}

#endif
#endif
