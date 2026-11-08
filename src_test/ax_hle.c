#include "ax_hle.h"
#include <stdio.h>
#include <string.h>

#define AX_SAMPLES 160u
#define PB_WORDS 122u
static s32 s_mix[9][AX_SAMPLES];
static AXHleStats s_stats;
static u32 s_compressor_release;
static s16 s_src_coefficients[2048];
static bool s_has_coefficients;
bool ax_hle_load_coefficients(const char* path) {
    FILE* file=fopen(path,"rb");if(!file)return false;
    u8 data[4096];bool ok=fread(data,1,sizeof(data),file)==sizeof(data) && fgetc(file)==EOF;
    fclose(file);if(!ok)return false;
    for(u32 i=0;i<2048;i++)s_src_coefficients[i]=(s16)((u16)data[i*2]<<8|data[i*2+1]);
    s_has_coefficients=true;return true;
}
const AXHleStats* ax_hle_stats(void) { return &s_stats; }
static bool ram_range(CPUState* cpu, u32 address, u32 length) {
    u32 offset = address & 0x1FFFFFFFu;
    return offset <= cpu->ram_size && length <= cpu->ram_size - offset;
}
static u32 guest(u32 address) { return (address & 0x1FFFFFFFu) | GC_RAM_BASE; }
static u32 pair(const u16* words, u32 index) { return ((u32)words[index] << 16) | words[index+1]; }
static void set_pair(u16* words, u32 index, u32 value) { words[index] = (u16)(value >> 16); words[index+1] = (u16)value; }
static s16 clamp16(s64 value) { return (s16)(value < -32768 ? -32768 : value > 32767 ? 32767 : value); }

static s16 source_sample(u16* pb, const u8* aram, u32 aram_size) {
    u32 cursor = pair(pb,61), end = pair(pb,59);
    if (cursor > end) {
        if (!pb[55]) { if (pb[7]) s_stats.ended++; pb[7] = 0; return 0; }
        cursor = pair(pb,57);
        pb[80] = pb[90];
        if (pb[8] != 1) { pb[81] = pb[91]; pb[82] = pb[92]; }
        else pb[97]++;
    }
    s32 sample = 0;
    if (pb[56] == 0xA) {
        u64 offset = (u64)cursor * 2;
        if (offset + 1 >= aram_size) { pb[7] = 0; return 0; }
        sample = (s16)(((u16)aram[offset] << 8) | aram[offset+1]);
        cursor++;
    } else if (pb[56] == 0x19) {
        if (cursor >= aram_size) { pb[7] = 0; return 0; }
        sample = (s8)aram[cursor++] * 256;
    } else if (pb[56] == 0) {
        if ((cursor & 15u) < 2) {
            if (cursor / 2 >= aram_size) { pb[7] = 0; return 0; }
            pb[80] = aram[cursor / 2]; cursor = (cursor & ~15u) + 2;
        }
        if (cursor / 2 >= aram_size) { pb[7] = 0; return 0; }
        u32 byte = aram[cursor / 2];
        s32 nibble = (s32)((byte >> ((cursor & 1) ? 0 : 4)) & 15u);
        if (nibble & 8) nibble -= 16;
        u32 predictor = (pb[80] >> 4) & 7u, scale = 1u << (pb[80] & 15u);
        s64 accum = (s64)nibble * scale * 2048 + (s64)(s16)pb[63+predictor*2] * (s16)pb[81] +
                    (s64)(s16)pb[64+predictor*2] * (s16)pb[82] + 1024;
        sample = clamp16(accum >> 11);
        pb[82] = pb[81]; pb[81] = (u16)sample;
        cursor++;
    } else { pb[7] = 0; return 0; }
    set_pair(pb,61,cursor);
    if (cursor > end && !pb[55]) { if (pb[7]) s_stats.ended++; pb[7] = 0; }
    return (s16)sample;
}

static bool process_voices(CPUState* cpu, const u8* aram, u32 aram_size, u32 address) {
    static const u8 volume_slot[9] = {0,1,7,2,3,8,4,5,6};
    static const u8 depop_slot[9] = {0,3,6,1,4,7,2,5,8};
    static const u16 route[9] = {1,2,4,16,32,128,512,1024,4096};
    static const u16 ramp[9] = {8,8,8,64,64,256,2048,2048,8192};
    u32 visited = 0;
    bool old_layout = false;
    static u32 logs;
    if (logs++ < 4) printf("[AX PB list] address=%08X\n",address);
    while (address) {
        if (++visited > 1024 || !ram_range(cpu,address,PB_WORDS*2)) return false;
        u16 pb[PB_WORDS]; u32 base = guest(address);
        for (u32 i=0;i<PB_WORDS;i++) pb[i] = mem_read16(cpu,base+i*2);
        if (logs < 6 && visited < 3) {
            printf("[AX PB] %08X:",address); for (u32 z=0;z<20;z++) printf(" %04X",pb[z]); printf("\n");
        }
        if (pb[7] == 1) s_stats.voices++;
        u32 next = pair(pb,0), updates = pair(pb,39), update_index = 0;
        if (next > address && next-address == 236u) old_layout = true;
        if (old_layout) pb[97] = pb[93];
        for (u32 ms=0;ms<5;ms++) {
            u32 count = pb[34+ms];
            if (count > 32 || !ram_range(cpu,updates+update_index*4,count*4)) return false;
            for (u32 i=0;i<count;i++,update_index++) {
                u32 offset = mem_read16(cpu,guest(updates+update_index*4));
                if (offset >= PB_WORDS) return false;
                pb[offset] = mem_read16(cpu,guest(updates+update_index*4+2));
            }
            for (u32 i=0;i<32;i++) {
                if (pb[7] != 1) break;
                u32 fraction = pb[85], ratio = pair(pb,83);
                if (ratio > 0x40000u) ratio = 0x40000u;
                fraction += pb[4] == 2 ? 0x10000u : ratio;
                s16 sample = (s16)pb[89];
                while (fraction >= 0x10000u) {
                    sample = source_sample(pb,aram,aram_size);
                    pb[86]=pb[87]; pb[87]=pb[88]; pb[88]=pb[89]; pb[89]=(u16)sample;
                    fraction -= 0x10000u;
                    if (!pb[7]) break;
                }
                fraction &= 0xFFFFu; // A stopped voice may leave unused whole samples in the phase.
                pb[85] = (u16)fraction;
                if(pb[4]==0 && s_has_coefficients && pb[5]<4) {
                    u32 coefficient=pb[5]*512u+(fraction>>9)*4u;
                    s64 filtered=0;
                    for(u32 tap=0;tap<4;tap++)filtered+=(s64)(s16)pb[86+tap]*s_src_coefficients[coefficient+tap];
                    sample=clamp16(filtered>>15);
                } else if (pb[4] != 2) sample = (s16)(((s64)(s16)pb[86]*(65536u-fraction) +
                                               (s64)(s16)pb[87]*fraction) >> 16);
                s32 enveloped = clamp16((s32)sample * (s16)pb[50] >> 15);
                pb[50] = (u16)(pb[50] + (s16)pb[51]);
                if(!old_layout && pb[93]) {
                    enveloped=clamp16(((s64)pb[95]*enveloped+(s64)(s16)pb[96]*(s16)pb[94])>>15);
                    pb[94]=(u16)enveloped;
                }
                for (u32 channel=0;channel<9;channel++) {
                    bool enabled = (pb[6] & route[channel]) != 0;
                    if (old_layout) {
                        u32 control = pb[6]; bool dpl = (control & 16u) != 0;
                        bool aux_a = dpl ? (control & 7u) == 1 : (control & 1u) != 0;
                        bool aux_b = dpl ? (control & 6u) == 0 : (control & 2u) != 0;
                        enabled = channel < 2 || (channel == 2 && !dpl && (control & 4u)) ||
                            ((channel == 3 || channel == 4) && aux_a) ||
                            (channel == 5 && aux_a && (dpl || (control & 4u))) ||
                            ((channel == 6 || channel == 7) && aux_b) ||
                            (channel == 8 && aux_b && !dpl && (control & 4u));
                    }
                    if (!enabled) continue;
                    u32 volume = 9 + volume_slot[channel]*2;
                    s16 contribution=clamp16((s64)enveloped * pb[volume] >> 15);
                    s_mix[channel][ms*32+i] += contribution;
                    pb[41+depop_slot[channel]]=(u16)contribution;
                    if (old_layout ? (pb[6] & 8u) != 0 : (pb[6] & ramp[channel]) != 0) pb[volume] = (u16)(pb[volume] + (s16)pb[volume+1]);
                }
            }
        }
        /* Only the mutable DSP prefix is returned; never touch SDK-side bookkeeping. */
        for (u32 i=0;i<93;i++) mem_write16(cpu,base+i*2,pb[i]);
        mem_write16(cpu,base+(old_layout ? 93u : 97u)*2,pb[97]);
        if(!old_layout)mem_write16(cpu,base+94u*2,pb[94]);
        address = next;
    }
    return true;
}

static bool transfer_mix(CPUState* cpu, u32 address, u32 first, u32 channels, bool write, bool add) {
    if (!ram_range(cpu,address,channels*AX_SAMPLES*4)) return false;
    for (u32 channel=0;channel<channels;channel++) for (u32 i=0;i<AX_SAMPLES;i++) {
        u32 at = guest(address+(channel*AX_SAMPLES+i)*4);
        if (write) mem_write32(cpu,at,(u32)s_mix[first+channel][i]);
        else if (add) s_mix[channel][i] += (s32)mem_read32(cpu,at);
        else s_mix[first+channel][i] = (s32)mem_read32(cpu,at);
    }
    return true;
}

bool ax_hle_execute(CPUState* cpu, const u8* aram, u32 aram_size, u32 address, u32 words) {
    s_stats.lists++;
    u16 commands[512]; u32 pc=0, pb_address=0, budget=2048;
    if (!words || words > 512 || !ram_range(cpu,address,words*2)) return false;
    for (u32 i=0;i<words;i++) commands[i] = mem_read16(cpu,guest(address+i*2));
    if (s_stats.lists < 5) { printf("[AX list] %08X words=%u:",address,words); for (u32 z=0;z<words && z<48;z++) printf(" %04X",commands[z]); printf("\n"); }
    while (pc < words && budget--) {
        u32 op=commands[pc++], arguments=0;
        static const u8 lengths[20]={2,5,2,0,4,4,2,2,10,2,0,0,0,3,4,0,4,2,4,12};
        if (op>=20) { fprintf(stderr,"[AX] Unsupported command %04X at %08X word %u\n",op,address,pc-1); return false; }
        arguments=lengths[op]; if (arguments > words-pc) return false;
        const u16* args=commands+pc; pc+=arguments;
        u32 a=arguments>=2 ? pair(args,0) : 0, b=arguments>=4 ? pair(args,2) : 0;
        switch (op) {
        case 0:
            memset(s_mix,0,sizeof(s_mix));
            if (a) {
                if (!ram_range(cpu,a,54)) return false;
                for (u32 ch=0;ch<9;ch++) {
                    s32 value=(s32)mem_read32(cpu,guest(a+ch*6));
                    s16 delta=(s16)mem_read16(cpu,guest(a+ch*6+4));
                    if (value) for (u32 i=0;i<AX_SAMPLES;i++) s_mix[ch][i]=(s32)((u32)value+i*(s32)delta);
                }
            }
            break;
        case 1: {
            if (!ram_range(cpu,a,3*AX_SAMPLES*4)) return false;
            for (u32 bus=0;bus<3;bus++) for (u32 ch=0;ch<3;ch++) for (u32 i=0;i<AX_SAMPLES;i++)
                s_mix[bus*3+ch][i] += (s32)((s64)(s32)mem_read32(cpu,guest(a+(ch*AX_SAMPLES+i)*4))*args[2+bus] >> 15);
            break;
        }
        case 2: pb_address=a; break;
        case 3: if (!process_voices(cpu,aram,aram_size,pb_address)) return false; break;
        case 4: case 5:
            if (a && !transfer_mix(cpu,a,op==4 ? 3 : 6,3,true,false)) return false;
            if (b && !transfer_mix(cpu,b,0,3,false,true)) return false;
            break;
        case 6: if (!transfer_mix(cpu,a,0,3,true,false)) return false; break;
        case 7: case 17:
            if (!ram_range(cpu,a,AX_SAMPLES*4)) return false;
            for (u32 i=0;i<AX_SAMPLES;i++) {
                s32 value=(s32)mem_read32(cpu,guest(a+i*4));
                s_mix[0][i]=op==17 ? -value : value; s_mix[1][i]=value; s_mix[2][i]=0;
            }
            break;
        case 9: if (!transfer_mix(cpu,a,0,3,false,true)) return false; break;
        case 13:
            words=args[2]; address=a; pc=0;
            if (!words || words>512 || !ram_range(cpu,address,words*2)) return false;
            for (u32 i=0;i<words;i++) commands[i]=mem_read16(cpu,guest(address+i*2));
            break;
        case 14:
            if (!ram_range(cpu,a,AX_SAMPLES*4) || !ram_range(cpu,b,AX_SAMPLES*4)) return false;
            for (u32 i=0;i<AX_SAMPLES;i++) {
                u32 peak=(u32)(s_mix[0][i]<0 ? -(s64)s_mix[0][i] : s_mix[0][i]);
                if (peak>s_stats.peak) s_stats.peak=peak;
                mem_write32(cpu,guest(a+i*4),(u32)s_mix[2][i]);
                mem_write16(cpu,guest(b+i*4),(u16)clamp16(s_mix[1][i]));
                mem_write16(cpu,guest(b+i*4+2),(u16)clamp16(s_mix[0][i]));
            }
            break;
        case 15: return true;
        case 16:
            if (!transfer_mix(cpu,a,6,2,true,false)) return false;
            if (!ram_range(cpu,b,2*AX_SAMPLES*4)) return false;
            for (u32 ch=0;ch<2;ch++) for (u32 i=0;i<AX_SAMPLES;i++) {
                s32 sample=(s32)mem_read32(cpu,guest(b+(ch*AX_SAMPLES+i)*4));
                s_mix[6+ch][i]=sample; s_mix[ch][i]+=sample;
            }
            break;
        case 18: {
            bool attack=false;
            for(u32 i=0;i<AX_SAMPLES;i++)
                if(s_mix[0][i]>(s32)args[0] || s_mix[0][i]<-(s32)args[0] ||
                   s_mix[1][i]>(s32)args[0] || s_mix[1][i]<-(s32)args[0]) {attack=true;break;}
            u32 entry;
            if(attack) {entry=s_compressor_release;s_compressor_release=args[1];}
            else if(s_compressor_release) {entry=11u+--s_compressor_release;}
            else break;
            u32 table=pair(args,2)+entry*AX_SAMPLES*2u;
            if(!ram_range(cpu,table,AX_SAMPLES*2u))return false;
            for(u32 i=0;i<AX_SAMPLES;i++) {
                u16 gain=mem_read16(cpu,guest(table+i*2));
                s_mix[0][i]=(s32)((s64)s_mix[0][i]*gain>>15);
                s_mix[1][i]=(s32)((s64)s_mix[1][i]*gain>>15);
            }
            break;
        }
        case 19:
            if (!transfer_mix(cpu,pair(args,0),3,3,true,false)) return false;
            if (!transfer_mix(cpu,pair(args,2),8,1,true,false)) return false;
            for (u32 ch=0;ch<4;ch++) {
                u32 source=pair(args,4+ch*2);
                if (!ram_range(cpu,source,AX_SAMPLES*4)) return false;
                for (u32 i=0;i<AX_SAMPLES;i++) s_mix[ch<2 ? ch : ch+4][i]+=(s32)mem_read32(cpu,guest(source+i*4));
            }
            break;
        /* 08/0A/0B/0C are reserved. */
        default: break;
        }
    }
    return false;
}
