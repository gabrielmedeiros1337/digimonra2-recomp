#define HOT_FLOAT_NO_REDIRECT
#include "hot_float_adapter.h"
extern bool g_float_bits_enabled;
#define platform_f32_from_bits hot_f32_from_bits
#define platform_f32_to_bits hot_f32_to_bits
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
static int arithmetic_contracts(void);
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
    CHECK(arithmetic_contracts()==0);
    printf("[Native float bits] %llu pairs: all exponent/sign boundaries, random payloads, rounding/FTZ/DAZ and unchanged FP flags passed\n",cases);return 0;
}

static int arithmetic_contracts(void){
    CPUState seed={0};u8 memory[64]={0};seed.ram=memory;seed.ram_size=sizeof(memory);seed.msr=0x2000u;seed.hid2=PPC_HID2_PSE|PPC_HID2_LSQE;u32 cases=0;
    for(u32 mode=0;mode<2;mode++)for(u32 i=0;i<512;i++)for(u32 op=0;op<11;op++){
        seed.fpr[2]=((int)(i%37)-18)/8.;seed.fpr[3]=((int)(i%23)-11)/16.;seed.fpr[4]=((int)(i%17)-8)/32.;seed.fpscr=0x1F000u;
        CPUState expected=seed,actual=seed;g_fast_float_enabled=mode!=0;
        switch(op){
        case 0:ppc_fadds(&expected,20,2,3);hot_ppc_fadds(&actual,20,2,3);break;
        case 1:ppc_fsubs(&expected,20,2,3);hot_ppc_fsubs(&actual,20,2,3);break;
        case 2:ppc_fmuls(&expected,20,2,3);hot_ppc_fmuls(&actual,20,2,3);break;
        case 3:ppc_fdivs(&expected,20,2,3);hot_ppc_fdivs(&actual,20,2,3);break;
        case 4:ppc_fadd(&expected,20,2,3);hot_ppc_fadd(&actual,20,2,3);break;
        case 5:ppc_fsub(&expected,20,2,3);hot_ppc_fsub(&actual,20,2,3);break;
        case 6:ppc_fmul(&expected,20,2,3);hot_ppc_fmul(&actual,20,2,3);break;
        case 7:ppc_fdiv(&expected,20,2,3);hot_ppc_fdiv(&actual,20,2,3);break;
        case 8:ppc_frsp(&expected,20,2);hot_frsp(&actual,20,2);break;
        case 9:case 10:{f64 a,b;bool x=ppc_fma(&expected,seed.fpr[2],seed.fpr[3],seed.fpr[4],op==9,(i&1)!=0,(i&2)!=0,&a),y=hot_fma(&actual,seed.fpr[2],seed.fpr[3],seed.fpr[4],op==9,(i&1)!=0,(i&2)!=0,&b);CHECK(x==y && !memcmp(&a,&b,8));break;}
        }
        CHECK(!memcmp(&actual,&expected,sizeof(actual)));cases++;
    }
    for(u32 i=0;i<256;i++)for(u32 w=0;w<2;w++){
        u32 bits=i%3 ? 0x3F800000u+i*751:0x7F800001u;
        mem_write32(&seed,0x80000000u,bits);mem_write32(&seed,0x80000004u,bits^0x80000000u);
        CPUState expected=seed,actual=seed;
        bool a=ppc_psq_load_inline(&expected,4,0x80000000u,w!=0,0,false,0x80002000u);
        bool b=hot_psq_load(&actual,4,0x80000000u,w!=0,0,false,0x80002000u);
        CHECK(a==b && !memcmp(&actual,&expected,sizeof(actual)));cases++;
    }
    g_fast_float_enabled=false;printf("[Hot float arithmetic] %u full CPU cases: strict/fast scalar/FMA and normal/exceptional PSQ passed\n",cases);return 0;
}
