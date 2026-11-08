#include "native_animation.h"
#include <stdio.h>
#include <string.h>
bool g_native_blocks_enabled=true;
unsigned animation_oracle_stop;
void ref_animation_quat(CPUState*);
void ref_animation_constant(CPUState*);
void ref_animation_channels(CPUState*);
#define CHECK(x) do{if(!(x)){fprintf(stderr,"animation FAIL %d: %s\n",__LINE__,#x);return 1;}}while(0)
static int compare(CPUState* actual,CPUState* expected,u8* a,u8* b,u32 size){
    expected->ram=a;
    if(memcmp(actual,expected,sizeof(*actual)) || memcmp(a,b,size)){
        fprintf(stderr,"PC %08X/%08X budget %lld/%lld CR %08X/%08X\n",actual->pc,expected->pc,actual->downcount,expected->downcount,actual->cr,expected->cr);
        for(u32 i=0;i<32;i++){
            if(actual->gpr[i]!=expected->gpr[i])fprintf(stderr,"r%u %08X/%08X\n",i,actual->gpr[i],expected->gpr[i]);
            if(memcmp(actual->fpr+i,expected->fpr+i,8) || memcmp(actual->ps1+i,expected->ps1+i,8))fprintf(stderr,"f%u %.17g/%.17g ps1 %.17g/%.17g\n",i,actual->fpr[i],expected->fpr[i],actual->ps1[i],expected->ps1[i]);
        }
        for(u32 i=0;i<size;i++)if(a[i]!=b[i]){fprintf(stderr,"RAM %X %02X/%02X\n",i,a[i],b[i]);break;}
        return 1;
    }return 0;
}
static CPUState seed(u8* ram,u32 size){
    CPUState c={0};c.ram=ram;c.ram_size=size;c.msr=0x2000;c.lr=0x81800000;c.downcount=1024;c.cr=0x13579BDF;c.fpscr=0x1F000;
    for(u32 i=0;i<32;i++){c.fpr[i]=i/16.;c.ps1[i]=-(double)i/8.;c.gpr[i]=0xA5000000+i*4;}
    return c;
}
int main(void){
    u8 a[8192]={0},b[8192];u32 cases=0;g_fast_float_enabled=true;
    for(u32 n=0;n<512;n++)for(u32 alias=0;alias<4;alias++)for(u32 route=0;route<2;route++){
        CPUState c=seed(a,sizeof(a));c.pc=0x80283A70;c.gpr[4]=0x80000100;c.gpr[5]=0x80000200;
        c.gpr[3]=alias==0 ? 0x80000300:alias==1 ? c.gpr[4]:alias==2 ? c.gpr[5]:c.gpr[4]+4;
        for(u32 i=0;i<8;i++){float x=((int)((n*37+i*59)%257)-128)/64.f;u32 bits;memcpy(&bits,&x,4);mem_write32(&c,(i<4 ? c.gpr[4]:c.gpr[5])+(i&3)*4,bits);}
        memcpy(b,a,sizeof(a));CPUState expected=c;expected.ram=b;ref_animation_quat(&expected);
        if(route)c.downcount-=33;CHECK(native_quaternion(&c,route!=0));CHECK(!compare(&c,&expected,a,b,sizeof(a)));cases++;
    }
    for(u32 kind=0;kind<3;kind++)for(u32 n=1;n<=16;n++)for(u32 sample=0;sample<32;sample++)for(u32 budget=0;budget<3;budget++){
        CPUState c=seed(a,sizeof(a));c.gpr[1]=0x80001E00;c.gpr[3]=0x80000100;c.gpr[4]=0x80000400;c.gpr[5]=0x80001000;
        c.downcount=budget==0 ? 1024:budget==1 ? -240:-300;c.gpr[11]=0x43300000;c.gpr[12]=0x43300000;c.fpr[13]=c.fpr[11]=4503601774854144.;c.fpr[2]=c.ps1[2]=1./64.;c.ctr=n;
        c.gpr[25]=24;c.gpr[27]=8;c.gpr[28]=16;c.gpr[26]=0x80000108;c.gpr[29]=0;c.gpr[30]=n;c.gpr[31]=0;
        c.fpr[1]=c.ps1[1]=.125;c.fpr[7]=c.ps1[7]=.25;c.fpr[8]=c.ps1[8]=.375;c.fpr[9]=c.ps1[9]=.5;
        for(u32 i=0;i<512;i++)mem_write16(&c,0x80000100+i*2,(u16)(sample*1951+i*2137));
        mem_write16(&c,c.gpr[3]+4,12);mem_write16(&c,c.gpr[3]+6,kind==1 ? 0xFFFF:(u16)(0xA55Au^sample));
        memcpy(b,a,sizeof(a));CPUState expected=c;expected.ram=b;
        if(kind==0){c.pc=expected.pc=0x802524D0;animation_oracle_stop=0;ref_animation_constant(&expected);animation_oracle_stop=0x802524E4;ref_animation_constant(&c);}
        else{c.pc=expected.pc=0x80252808;animation_oracle_stop=0;ref_animation_channels(&expected);animation_oracle_stop=(kind==1 || (mem_read16(&c,c.gpr[3]+6)&1)) ? 0x80252848:0x802528CC;ref_animation_channels(&c);}
        animation_oracle_stop=0;CHECK(native_animation_channels(&c));CHECK(!compare(&c,&expected,a,b,sizeof(a)));cases++;
    }
    CPUState c=seed(a,sizeof(a));CPUState original=c;c.pc=original.pc=0x80283A70;g_fast_float_enabled=false;
    CHECK(!native_quaternion(&c,false) && !memcmp(&c,&original,sizeof(c)));
    printf("[Native animation] %u complete CPU/RAM oracle comparisons: quaternion aliases, constant/mixed channels, budget exits passed\n",cases);return 0;
}
