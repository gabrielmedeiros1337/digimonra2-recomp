#include "generated_float_adapter.h"
#undef dolrecomp_f32_from_bits
#undef dolrecomp_f32_to_bits
#include <stdio.h>
#if defined(_MSC_VER) && defined(_M_X64)
#include <xmmintrin.h>
#endif
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#x);return 1;}}while(0)
static int compare(u32 input,u64 wide) {
    f64 expected=dolrecomp_f32_from_bits(input),actual=platform_f32_from_bits(input);
    CHECK(!memcmp(&actual,&expected,8));
    f64 value;memcpy(&value,&wide,8);CHECK(platform_f32_to_bits(value)==dolrecomp_f32_to_bits(value));return 0;
}
int main(void) {
    g_float_bits_enabled=true;
    u64 seed=0x12345678ABCDEF91ull,cases=0;
#if defined(_MSC_VER) && defined(_M_X64)
    u32 saved=_mm_getcsr();
#endif
    for(u32 rn=0;rn<4;rn++)for(u32 flush=0;flush<2;flush++) {
#if defined(_MSC_VER) && defined(_M_X64)
        u32 control=(saved&~0xE07Fu)|(rn<<13)|(flush ? 0x8040u:0u);_mm_setcsr(control);
#endif
        const u32 fractions[]={0,1,2,0x1FFFFFu,0x3FFFFFu,0x400000u,0x7FFFFEu,0x7FFFFFu};
        for(u32 sign=0;sign<2;sign++)for(u32 exponent=0;exponent<2048;exponent++)for(u32 f=0;f<8;f++) {
            u32 input=(sign<<31)|((exponent&255u)<<23)|fractions[f];
            u64 wide=((u64)sign<<63)|((u64)exponent<<52)|((u64)fractions[f]<<29)|(f&1 ? 0x1FFFFFFFu:0u);
            CHECK(compare(input,wide)==0);cases++;
        }
        for(u32 i=0;i<262144;i++) {
            seed=seed*6364136223846793005ull+1442695040888963407ull;
            CHECK(compare((u32)(seed>>17),seed)==0);cases++;
        }
        // All helpers above are integer/bit moves, including signaling NaNs.
#if defined(_MSC_VER) && defined(_M_X64)
        CHECK(_mm_getcsr()==control);
#endif
    }
    g_float_bits_enabled=false;
    for(u32 i=0;i<1024;i++){seed=seed*6364136223846793005ull+1;CHECK(compare((u32)seed,seed)==0);}
    g_float_bits_enabled=true;
#if defined(_MSC_VER) && defined(_M_X64)
    _mm_setcsr(saved);
#endif
    printf("[Native float bits] %llu pairs: all exponent/sign boundaries, random payloads, rounding/FTZ/DAZ and unchanged FP flags passed\n",cases);return 0;
}
