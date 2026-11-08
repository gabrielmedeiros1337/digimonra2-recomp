#ifndef DOLRECOMP_PSQ_FAST_H
#define DOLRECOMP_PSQ_FAST_H
#include <string.h>
#if defined(_MSC_VER) && defined(_M_X64)
#include <intrin.h>
#endif

/* CPUState and the public memory/PSQ declarations precede this private header.
 * Device accesses always fall back. An external_pointer provider explicitly
 * opts a memory region (such as locked cache) into coherent direct accesses. */
static inline u8* psq_direct_pointer(CPUState* cpu,u32 ea,u32 bytes) {
    u32 offset=ea&0x3FFFFFFFu;
    if((ea&0x80000000u) && offset<=cpu->ram_size && bytes<=cpu->ram_size-offset)
        return cpu->ram+offset;
    return cpu->external_pointer ? (u8*)cpu->external_pointer(cpu,ea,bytes) : 0;
}
static inline u32 psq_read_be(const u8* p,u32 size) {
    if(size==1)return p[0];
#if defined(_MSC_VER) && defined(_M_X64)
    if(size==2){u16 value;memcpy(&value,p,2);return _byteswap_ushort(value);}
    u32 value;memcpy(&value,p,4);return _byteswap_ulong(value);
#else
    if(size==2)return ((u32)p[0]<<8)|p[1];
    return ((u32)p[0]<<24)|((u32)p[1]<<16)|((u32)p[2]<<8)|p[3];
#endif
}
static inline void psq_write_be(u8* p,u32 value,u32 size) {
    ppc_mark_host_write(p,size);
#if defined(_MSC_VER) && defined(_M_X64)
    if(size==1){p[0]=(u8)value;return;}
    if(size==2){u16 encoded=_byteswap_ushort((u16)value);memcpy(p,&encoded,2);return;}
    value=_byteswap_ulong(value);memcpy(p,&value,4);
#else
    for(u32 i=0;i<size;i++)p[i]=(u8)(value>>((size-1u-i)*8u));
#endif
}
static inline bool psq_direct_enabled(CPUState* cpu,bool indexed) {
    return (cpu->hid2&PPC_HID2_PSE) && (indexed || (cpu->hid2&PPC_HID2_LSQE));
}
static inline f64 psq_direct_integer(u32 raw,u32 type,int scale) {
    s32 value=type==6 ? (s8)raw : type==7 ? (s16)raw : (s32)raw;
    u64 factor_bits=(u64)(1023-scale)<<52;f64 factor;memcpy(&factor,&factor_bits,8);
    // All integer formats/scales produce normal, exactly representable f32.
    return (f64)value*factor;
}
static inline u32 psq_direct_quantize(f64 value,u32 type,int scale) {
    s64 minimum=type==6 ? -128 : type==7 ? -32768 : 0;
    s64 maximum=type==4 ? 255 : type==5 ? 65535 : type==6 ? 127 : 32767;
    u64 raw;memcpy(&raw,&value,8);u64 magnitude=raw&0x7FFFFFFFFFFFFFFFull;
    if(magnitude>0x7FF0000000000000ull)return (u32)maximum;
    if(magnitude==0x7FF0000000000000ull)return (u32)((raw>>63) ? minimum : maximum);
    u64 bits=(u64)(1023+scale)<<52;f64 factor;memcpy(&factor,&bits,8);
    f64 scaled=value*factor;
    if(scaled<=minimum)return (u32)minimum;
    if(scaled>=maximum)return (u32)maximum;
    return (u32)(s64)scaled;
}
static inline bool psq_direct_load(CPUState* cpu,u8 d,u32 ea,bool w,u8 index,bool indexed) {
    u32 gqr=cpu->gqr[index&7u],type=(gqr>>16)&7u;
    if(!psq_direct_enabled(cpu,indexed) || (type && type<4) || (!type && (ea&3u)))return false;
    u32 size=!type ? 4u : (type==4 || type==6) ? 1u : 2u;
    const u8* p=psq_direct_pointer(cpu,ea,w ? size : size*2u);if(!p)return false;
    u32 raw0=psq_read_be(p,size),raw1=w ? 0 : psq_read_be(p+size,size);
    if(!type) {
        u32 e0=(raw0>>23)&255u,e1=(raw1>>23)&255u;
        // Bit-exact scalar extension handles NaNs and subnormals, independent
        // of host DAZ/FTZ. Normal values and signed zeros convert exactly.
        if(e0==255u || (!e0 && (raw0&0x7FFFFFu)) ||
           (!w && (e1==255u || (!e1 && (raw1&0x7FFFFFu)))))return false;
        f32 first,second;memcpy(&first,&raw0,4);memcpy(&second,&raw1,4);
        cpu->fpr[d]=(f64)first;cpu->ps1[d]=w ? 1.0 : (f64)second;
    } else {
        int scale=(int)((gqr>>24)&63u);if(scale&32)scale-=64;
        cpu->fpr[d]=psq_direct_integer(raw0,type,scale);
        cpu->ps1[d]=w ? 1.0 : psq_direct_integer(raw1,type,scale);
    }
    return true;
}
static inline bool psq_direct_store(CPUState* cpu,u8 s,u32 ea,bool w,u8 index,bool indexed) {
    u32 gqr=cpu->gqr[index&7u],type=gqr&7u;
    if(!psq_direct_enabled(cpu,indexed) || (type && type<4) || (!type && (ea&3u)) ||
       cpu->reserve_valid || g_mem_write_journal)return false;
    u32 size=!type ? 4u : (type==4 || type==6) ? 1u : 2u;
    u8* p=psq_direct_pointer(cpu,ea,w ? size : size*2u);if(!p)return false;
    u32 first,second=0;
    if(!type) {
        f32 value=(f32)cpu->fpr[s];memcpy(&first,&value,4);
        if(!(first&0x7F800000u) && (first&0x7FFFFFu))first=0;
        if(!w){value=(f32)cpu->ps1[s];memcpy(&second,&value,4);if(!(second&0x7F800000u) && (second&0x7FFFFFu))second=0;}
    } else {
        int scale=(int)((gqr>>8)&63u);if(scale&32)scale-=64;
        first=psq_direct_quantize(cpu->fpr[s],type,scale);
        if(!w)second=psq_direct_quantize(cpu->ps1[s],type,scale);
    }
    psq_write_be(p,first,size);if(!w)psq_write_be(p+size,second,size);
    return true;
}
#endif
