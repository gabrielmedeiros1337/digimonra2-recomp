// DolRecomp output
#include "../generated.h"

static void loop_8015F628(CPUState* ctx) {
label_8015F628:
    ctx->downcount -= 8;
    ctx->pc = 0x8015F628u;
    // 8015F628: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 8015F62C: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 8015F630: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x8015F634u;
    // 8015F634: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 8015F638: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 8015F63C: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 8015F640: cmpw    r9, r8
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8015F644: bc    4, 2, 0x8015F628
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8015F628u;
                return;
            }
            goto label_8015F628;
        }
    }

    ctx->pc = 0x8015F648u;
}

static void loop_8016027C(CPUState* ctx) {
label_8016027C:
    ctx->downcount -= 8;
    ctx->pc = 0x8016027Cu;
    // 8016027C: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 80160280: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 80160284: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x80160288u;
    // 80160288: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 8016028C: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 80160290: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 80160294: cmpw    r9, r8
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80160298: bc    4, 2, 0x8016027C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8016027Cu;
                return;
            }
            goto label_8016027C;
        }
    }

    ctx->pc = 0x8016029Cu;
}

static void loop_80160D9C(CPUState* ctx) {
label_80160D9C:
    ctx->downcount -= 8;
    ctx->pc = 0x80160D9Cu;
    // 80160D9C: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 80160DA0: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 80160DA4: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x80160DA8u;
    // 80160DA8: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 80160DAC: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 80160DB0: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 80160DB4: cmpw    r9, r8
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80160DB8: bc    4, 2, 0x80160D9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80160D9Cu;
                return;
            }
            goto label_80160D9C;
        }
    }

    ctx->pc = 0x80160DBCu;
}

static void loop_801615EC(CPUState* ctx) {
label_801615EC:
    ctx->downcount -= 8;
    ctx->pc = 0x801615ECu;
    // 801615EC: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 801615F0: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 801615F4: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x801615F8u;
    // 801615F8: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 801615FC: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 80161600: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 80161604: cmpw    r9, r8
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80161608: bc    4, 2, 0x801615EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801615ECu;
                return;
            }
            goto label_801615EC;
        }
    }

    ctx->pc = 0x8016160Cu;
}

static void loop_80162150(CPUState* ctx) {
label_80162150:
    ctx->downcount -= 16;
    ctx->pc = 0x80162150u;
    // 80162150: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 80162154: addic.  r11, r11, -24
    {
        u64 a = ctx->gpr[11];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[11] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    ctx->pc = 0x80162158u;
    // 80162158: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8016215Cu;
    // 8016215C: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80162160u;
    // 80162160: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80162164u;
    // 80162164: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80162168u;
    // 80162168: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8016216Cu;
    // 8016216C: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80162170u;
    // 80162170: stw     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80162174u;
    // 80162174: lwz     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80162178u;
    // 80162178: stw     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8016217Cu;
    // 8016217C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 80162180: addi    r3, r3, 24
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(24);

    ctx->pc = 0x80162184u;
    // 80162184: stw     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80162188: addi    r9, r9, 24
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(24);

    // 8016218C: bc    4, 2, 0x80162150
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80162150u;
                return;
            }
            goto label_80162150;
        }
    }

    ctx->pc = 0x80162190u;
}

static void loop_80162404(CPUState* ctx) {
label_80162404:
    ctx->downcount -= 8;
    ctx->pc = 0x80162404u;
    // 80162404: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 80162408: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 8016240C: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x80162410u;
    // 80162410: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 80162414: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 80162418: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 8016241C: cmpw    r9, r8
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80162420: bc    4, 2, 0x80162404
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80162404u;
                return;
            }
            goto label_80162404;
        }
    }

    ctx->pc = 0x80162424u;
}

static void loop_801624F4(CPUState* ctx) {
label_801624F4:
    ctx->downcount -= 4;
    ctx->pc = 0x801624F4u;
    // 801624F4: stw     r9, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    // 801624F8: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

    // 801624FC: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80162500: bc    4, 2, 0x801624F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801624F4u;
                return;
            }
            goto label_801624F4;
        }
    }

    ctx->pc = 0x80162504u;
}

static void loop_80162538(CPUState* ctx) {
label_80162538:
    ctx->downcount -= 4;
    ctx->pc = 0x80162538u;
    // 80162538: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8016253Cu;
    // 8016253C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80162540: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

    // 80162544: bc    16, 0, 0x80162538
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80162538u;
                return;
            }
            goto label_80162538;
        }
    }

    ctx->pc = 0x80162548u;
}

static void loop_80162584(CPUState* ctx) {
label_80162584:
    ctx->downcount -= 4;
    ctx->pc = 0x80162584u;
    // 80162584: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80162588: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

    // 8016258C: cmpw    r4, r31
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80162590: bc    4, 2, 0x80162584
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80162584u;
                return;
            }
            goto label_80162584;
        }
    }

    ctx->pc = 0x80162594u;
}

static void loop_8016263C(CPUState* ctx) {
label_8016263C:
    ctx->downcount -= 4;
    ctx->pc = 0x8016263Cu;
    // 8016263C: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80162640u;
    // 80162640: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80162644: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

    // 80162648: bc    16, 0, 0x8016263C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8016263Cu;
                return;
            }
            goto label_8016263C;
        }
    }

    ctx->pc = 0x8016264Cu;
}

void func_8015F4C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x8015F4C0u: goto label_8015F4C0;
    case 0x8015F4C4u: goto label_8015F4C4;
    case 0x8015F4C8u: goto label_8015F4C8;
    case 0x8015F4CCu: goto label_8015F4CC;
    case 0x8015F4D0u: goto label_8015F4D0;
    case 0x8015F4D4u: goto label_8015F4D4;
    case 0x8015F4D8u: goto label_8015F4D8;
    case 0x8015F4DCu: goto label_8015F4DC;
    case 0x8015F4E0u: goto label_8015F4E0;
    case 0x8015F4E4u: goto label_8015F4E4;
    case 0x8015F4E8u: goto label_8015F4E8;
    case 0x8015F4ECu: goto label_8015F4EC;
    case 0x8015F4F0u: goto label_8015F4F0;
    case 0x8015F4F4u: goto label_8015F4F4;
    case 0x8015F4F8u: goto label_8015F4F8;
    case 0x8015F4FCu: goto label_8015F4FC;
    case 0x8015F500u: goto label_8015F500;
    case 0x8015F504u: goto label_8015F504;
    case 0x8015F508u: goto label_8015F508;
    case 0x8015F50Cu: goto label_8015F50C;
    case 0x8015F510u: goto label_8015F510;
    case 0x8015F514u: goto label_8015F514;
    case 0x8015F518u: goto label_8015F518;
    case 0x8015F51Cu: goto label_8015F51C;
    case 0x8015F520u: goto label_8015F520;
    case 0x8015F524u: goto label_8015F524;
    case 0x8015F528u: goto label_8015F528;
    case 0x8015F52Cu: goto label_8015F52C;
    case 0x8015F530u: goto label_8015F530;
    case 0x8015F534u: goto label_8015F534;
    case 0x8015F538u: goto label_8015F538;
    case 0x8015F53Cu: goto label_8015F53C;
    case 0x8015F540u: goto label_8015F540;
    case 0x8015F544u: goto label_8015F544;
    case 0x8015F548u: goto label_8015F548;
    case 0x8015F54Cu: goto label_8015F54C;
    case 0x8015F550u: goto label_8015F550;
    case 0x8015F554u: goto label_8015F554;
    case 0x8015F558u: goto label_8015F558;
    case 0x8015F55Cu: goto label_8015F55C;
    case 0x8015F560u: goto label_8015F560;
    case 0x8015F564u: goto label_8015F564;
    case 0x8015F568u: goto label_8015F568;
    case 0x8015F56Cu: goto label_8015F56C;
    case 0x8015F570u: goto label_8015F570;
    case 0x8015F574u: goto label_8015F574;
    case 0x8015F578u: goto label_8015F578;
    case 0x8015F57Cu: goto label_8015F57C;
    case 0x8015F580u: goto label_8015F580;
    case 0x8015F584u: goto label_8015F584;
    case 0x8015F588u: goto label_8015F588;
    case 0x8015F58Cu: goto label_8015F58C;
    case 0x8015F590u: goto label_8015F590;
    case 0x8015F594u: goto label_8015F594;
    case 0x8015F598u: goto label_8015F598;
    case 0x8015F59Cu: goto label_8015F59C;
    case 0x8015F5A0u: goto label_8015F5A0;
    case 0x8015F5A4u: goto label_8015F5A4;
    case 0x8015F5A8u: goto label_8015F5A8;
    case 0x8015F5ACu: goto label_8015F5AC;
    case 0x8015F5B0u: goto label_8015F5B0;
    case 0x8015F5B4u: goto label_8015F5B4;
    case 0x8015F5B8u: goto label_8015F5B8;
    case 0x8015F5BCu: goto label_8015F5BC;
    case 0x8015F5C0u: goto label_8015F5C0;
    case 0x8015F5C4u: goto label_8015F5C4;
    case 0x8015F5C8u: goto label_8015F5C8;
    case 0x8015F5CCu: goto label_8015F5CC;
    case 0x8015F5D0u: goto label_8015F5D0;
    case 0x8015F5D4u: goto label_8015F5D4;
    case 0x8015F5D8u: goto label_8015F5D8;
    case 0x8015F5DCu: goto label_8015F5DC;
    case 0x8015F5E0u: goto label_8015F5E0;
    case 0x8015F5E4u: goto label_8015F5E4;
    case 0x8015F5E8u: goto label_8015F5E8;
    case 0x8015F5ECu: goto label_8015F5EC;
    case 0x8015F5F0u: goto label_8015F5F0;
    case 0x8015F5F4u: goto label_8015F5F4;
    case 0x8015F5F8u: goto label_8015F5F8;
    case 0x8015F5FCu: goto label_8015F5FC;
    case 0x8015F600u: goto label_8015F600;
    case 0x8015F604u: goto label_8015F604;
    case 0x8015F608u: goto label_8015F608;
    case 0x8015F60Cu: goto label_8015F60C;
    case 0x8015F610u: goto label_8015F610;
    case 0x8015F614u: goto label_8015F614;
    case 0x8015F618u: goto label_8015F618;
    case 0x8015F61Cu: goto label_8015F61C;
    case 0x8015F620u: goto label_8015F620;
    case 0x8015F624u: goto label_8015F624;
    case 0x8015F628u: goto label_8015F628;
    case 0x8015F62Cu: goto label_8015F62C;
    case 0x8015F630u: goto label_8015F630;
    case 0x8015F634u: goto label_8015F634;
    case 0x8015F638u: goto label_8015F638;
    case 0x8015F63Cu: goto label_8015F63C;
    case 0x8015F640u: goto label_8015F640;
    case 0x8015F644u: goto label_8015F644;
    case 0x8015F648u: goto label_8015F648;
    case 0x8015F64Cu: goto label_8015F64C;
    case 0x8015F650u: goto label_8015F650;
    case 0x8015F654u: goto label_8015F654;
    case 0x8015F658u: goto label_8015F658;
    case 0x8015F65Cu: goto label_8015F65C;
    case 0x8015F660u: goto label_8015F660;
    case 0x8015F664u: goto label_8015F664;
    case 0x8015F668u: goto label_8015F668;
    case 0x8015F66Cu: goto label_8015F66C;
    case 0x8015F670u: goto label_8015F670;
    case 0x8015F674u: goto label_8015F674;
    case 0x8015F678u: goto label_8015F678;
    case 0x8015F67Cu: goto label_8015F67C;
    case 0x8015F680u: goto label_8015F680;
    case 0x8015F684u: goto label_8015F684;
    case 0x8015F688u: goto label_8015F688;
    case 0x8015F68Cu: goto label_8015F68C;
    case 0x8015F690u: goto label_8015F690;
    case 0x8015F694u: goto label_8015F694;
    case 0x8015F698u: goto label_8015F698;
    case 0x8015F69Cu: goto label_8015F69C;
    case 0x8015F6A0u: goto label_8015F6A0;
    case 0x8015F6A4u: goto label_8015F6A4;
    case 0x8015F6A8u: goto label_8015F6A8;
    case 0x8015F6ACu: goto label_8015F6AC;
    case 0x8015F6B0u: goto label_8015F6B0;
    case 0x8015F6B4u: goto label_8015F6B4;
    case 0x8015F6B8u: goto label_8015F6B8;
    case 0x8015F6BCu: goto label_8015F6BC;
    case 0x8015F6C0u: goto label_8015F6C0;
    case 0x8015F6C4u: goto label_8015F6C4;
    case 0x8015F6C8u: goto label_8015F6C8;
    case 0x8015F6CCu: goto label_8015F6CC;
    case 0x8015F6D0u: goto label_8015F6D0;
    case 0x8015F6D4u: goto label_8015F6D4;
    case 0x8015F6D8u: goto label_8015F6D8;
    case 0x8015F6DCu: goto label_8015F6DC;
    case 0x8015F6E0u: goto label_8015F6E0;
    case 0x8015F6E4u: goto label_8015F6E4;
    case 0x8015F6E8u: goto label_8015F6E8;
    case 0x8015F6ECu: goto label_8015F6EC;
    case 0x8015F6F0u: goto label_8015F6F0;
    case 0x8015F6F4u: goto label_8015F6F4;
    case 0x8015F6F8u: goto label_8015F6F8;
    case 0x8015F6FCu: goto label_8015F6FC;
    case 0x8015F700u: goto label_8015F700;
    case 0x8015F704u: goto label_8015F704;
    case 0x8015F708u: goto label_8015F708;
    case 0x8015F70Cu: goto label_8015F70C;
    case 0x8015F710u: goto label_8015F710;
    case 0x8015F714u: goto label_8015F714;
    case 0x8015F718u: goto label_8015F718;
    case 0x8015F71Cu: goto label_8015F71C;
    case 0x8015F720u: goto label_8015F720;
    case 0x8015F724u: goto label_8015F724;
    case 0x8015F728u: goto label_8015F728;
    case 0x8015F72Cu: goto label_8015F72C;
    case 0x8015F730u: goto label_8015F730;
    case 0x8015F734u: goto label_8015F734;
    case 0x8015F738u: goto label_8015F738;
    case 0x8015F73Cu: goto label_8015F73C;
    case 0x8015F740u: goto label_8015F740;
    case 0x8015F744u: goto label_8015F744;
    case 0x8015F748u: goto label_8015F748;
    case 0x8015F74Cu: goto label_8015F74C;
    case 0x8015F750u: goto label_8015F750;
    case 0x8015F754u: goto label_8015F754;
    case 0x8015F758u: goto label_8015F758;
    case 0x8015F75Cu: goto label_8015F75C;
    case 0x8015F760u: goto label_8015F760;
    case 0x8015F764u: goto label_8015F764;
    case 0x8015F768u: goto label_8015F768;
    case 0x8015F76Cu: goto label_8015F76C;
    case 0x8015F770u: goto label_8015F770;
    case 0x8015F774u: goto label_8015F774;
    case 0x8015F778u: goto label_8015F778;
    case 0x8015F77Cu: goto label_8015F77C;
    case 0x8015F780u: goto label_8015F780;
    case 0x8015F784u: goto label_8015F784;
    case 0x8015F788u: goto label_8015F788;
    case 0x8015F78Cu: goto label_8015F78C;
    case 0x8015F790u: goto label_8015F790;
    case 0x8015F794u: goto label_8015F794;
    case 0x8015F798u: goto label_8015F798;
    case 0x8015F79Cu: goto label_8015F79C;
    case 0x8015F7A0u: goto label_8015F7A0;
    case 0x8015F7A4u: goto label_8015F7A4;
    case 0x8015F7A8u: goto label_8015F7A8;
    case 0x8015F7ACu: goto label_8015F7AC;
    case 0x8015F7B0u: goto label_8015F7B0;
    case 0x8015F7B4u: goto label_8015F7B4;
    case 0x8015F7B8u: goto label_8015F7B8;
    case 0x8015F7BCu: goto label_8015F7BC;
    case 0x8015F7C0u: goto label_8015F7C0;
    case 0x8015F7C4u: goto label_8015F7C4;
    case 0x8015F7C8u: goto label_8015F7C8;
    case 0x8015F7CCu: goto label_8015F7CC;
    case 0x8015F7D0u: goto label_8015F7D0;
    case 0x8015F7D4u: goto label_8015F7D4;
    case 0x8015F7D8u: goto label_8015F7D8;
    case 0x8015F7DCu: goto label_8015F7DC;
    case 0x8015F7E0u: goto label_8015F7E0;
    case 0x8015F7E4u: goto label_8015F7E4;
    case 0x8015F7E8u: goto label_8015F7E8;
    case 0x8015F7ECu: goto label_8015F7EC;
    case 0x8015F7F0u: goto label_8015F7F0;
    case 0x8015F7F4u: goto label_8015F7F4;
    case 0x8015F7F8u: goto label_8015F7F8;
    case 0x8015F7FCu: goto label_8015F7FC;
    case 0x8015F800u: goto label_8015F800;
    case 0x8015F804u: goto label_8015F804;
    case 0x8015F808u: goto label_8015F808;
    case 0x8015F80Cu: goto label_8015F80C;
    case 0x8015F810u: goto label_8015F810;
    case 0x8015F814u: goto label_8015F814;
    case 0x8015F818u: goto label_8015F818;
    case 0x8015F81Cu: goto label_8015F81C;
    case 0x8015F820u: goto label_8015F820;
    case 0x8015F824u: goto label_8015F824;
    case 0x8015F828u: goto label_8015F828;
    case 0x8015F82Cu: goto label_8015F82C;
    case 0x8015F830u: goto label_8015F830;
    case 0x8015F834u: goto label_8015F834;
    case 0x8015F838u: goto label_8015F838;
    case 0x8015F83Cu: goto label_8015F83C;
    case 0x8015F840u: goto label_8015F840;
    case 0x8015F844u: goto label_8015F844;
    case 0x8015F848u: goto label_8015F848;
    case 0x8015F84Cu: goto label_8015F84C;
    case 0x8015F850u: goto label_8015F850;
    case 0x8015F854u: goto label_8015F854;
    case 0x8015F858u: goto label_8015F858;
    case 0x8015F85Cu: goto label_8015F85C;
    case 0x8015F860u: goto label_8015F860;
    case 0x8015F864u: goto label_8015F864;
    case 0x8015F868u: goto label_8015F868;
    case 0x8015F86Cu: goto label_8015F86C;
    case 0x8015F870u: goto label_8015F870;
    case 0x8015F874u: goto label_8015F874;
    case 0x8015F878u: goto label_8015F878;
    case 0x8015F87Cu: goto label_8015F87C;
    case 0x8015F880u: goto label_8015F880;
    case 0x8015F884u: goto label_8015F884;
    case 0x8015F888u: goto label_8015F888;
    case 0x8015F88Cu: goto label_8015F88C;
    case 0x8015F890u: goto label_8015F890;
    case 0x8015F894u: goto label_8015F894;
    case 0x8015F898u: goto label_8015F898;
    case 0x8015F89Cu: goto label_8015F89C;
    case 0x8015F8A0u: goto label_8015F8A0;
    case 0x8015F8A4u: goto label_8015F8A4;
    case 0x8015F8A8u: goto label_8015F8A8;
    case 0x8015F8ACu: goto label_8015F8AC;
    case 0x8015F8B0u: goto label_8015F8B0;
    case 0x8015F8B4u: goto label_8015F8B4;
    case 0x8015F8B8u: goto label_8015F8B8;
    case 0x8015F8BCu: goto label_8015F8BC;
    case 0x8015F8C0u: goto label_8015F8C0;
    case 0x8015F8C4u: goto label_8015F8C4;
    case 0x8015F8C8u: goto label_8015F8C8;
    case 0x8015F8CCu: goto label_8015F8CC;
    case 0x8015F8D0u: goto label_8015F8D0;
    case 0x8015F8D4u: goto label_8015F8D4;
    case 0x8015F8D8u: goto label_8015F8D8;
    case 0x8015F8DCu: goto label_8015F8DC;
    case 0x8015F8E0u: goto label_8015F8E0;
    case 0x8015F8E4u: goto label_8015F8E4;
    case 0x8015F8E8u: goto label_8015F8E8;
    case 0x8015F8ECu: goto label_8015F8EC;
    case 0x8015F8F0u: goto label_8015F8F0;
    case 0x8015F8F4u: goto label_8015F8F4;
    case 0x8015F8F8u: goto label_8015F8F8;
    case 0x8015F8FCu: goto label_8015F8FC;
    case 0x8015F900u: goto label_8015F900;
    case 0x8015F904u: goto label_8015F904;
    case 0x8015F908u: goto label_8015F908;
    case 0x8015F90Cu: goto label_8015F90C;
    case 0x8015F910u: goto label_8015F910;
    case 0x8015F914u: goto label_8015F914;
    case 0x8015F918u: goto label_8015F918;
    case 0x8015F91Cu: goto label_8015F91C;
    case 0x8015F920u: goto label_8015F920;
    case 0x8015F924u: goto label_8015F924;
    case 0x8015F928u: goto label_8015F928;
    case 0x8015F92Cu: goto label_8015F92C;
    case 0x8015F930u: goto label_8015F930;
    case 0x8015F934u: goto label_8015F934;
    case 0x8015F938u: goto label_8015F938;
    case 0x8015F93Cu: goto label_8015F93C;
    case 0x8015F940u: goto label_8015F940;
    case 0x8015F944u: goto label_8015F944;
    case 0x8015F948u: goto label_8015F948;
    case 0x8015F94Cu: goto label_8015F94C;
    case 0x8015F950u: goto label_8015F950;
    case 0x8015F954u: goto label_8015F954;
    case 0x8015F958u: goto label_8015F958;
    case 0x8015F95Cu: goto label_8015F95C;
    case 0x8015F960u: goto label_8015F960;
    case 0x8015F964u: goto label_8015F964;
    case 0x8015F968u: goto label_8015F968;
    case 0x8015F96Cu: goto label_8015F96C;
    case 0x8015F970u: goto label_8015F970;
    case 0x8015F974u: goto label_8015F974;
    case 0x8015F978u: goto label_8015F978;
    case 0x8015F97Cu: goto label_8015F97C;
    case 0x8015F980u: goto label_8015F980;
    case 0x8015F984u: goto label_8015F984;
    case 0x8015F988u: goto label_8015F988;
    case 0x8015F98Cu: goto label_8015F98C;
    case 0x8015F990u: goto label_8015F990;
    case 0x8015F994u: goto label_8015F994;
    case 0x8015F998u: goto label_8015F998;
    case 0x8015F99Cu: goto label_8015F99C;
    case 0x8015F9A0u: goto label_8015F9A0;
    case 0x8015F9A4u: goto label_8015F9A4;
    case 0x8015F9A8u: goto label_8015F9A8;
    case 0x8015F9ACu: goto label_8015F9AC;
    case 0x8015F9B0u: goto label_8015F9B0;
    case 0x8015F9B4u: goto label_8015F9B4;
    case 0x8015F9B8u: goto label_8015F9B8;
    case 0x8015F9BCu: goto label_8015F9BC;
    case 0x8015F9C0u: goto label_8015F9C0;
    case 0x8015F9C4u: goto label_8015F9C4;
    case 0x8015F9C8u: goto label_8015F9C8;
    case 0x8015F9CCu: goto label_8015F9CC;
    case 0x8015F9D0u: goto label_8015F9D0;
    case 0x8015F9D4u: goto label_8015F9D4;
    case 0x8015F9D8u: goto label_8015F9D8;
    case 0x8015F9DCu: goto label_8015F9DC;
    case 0x8015F9E0u: goto label_8015F9E0;
    case 0x8015F9E4u: goto label_8015F9E4;
    case 0x8015F9E8u: goto label_8015F9E8;
    case 0x8015F9ECu: goto label_8015F9EC;
    case 0x8015F9F0u: goto label_8015F9F0;
    case 0x8015F9F4u: goto label_8015F9F4;
    case 0x8015F9F8u: goto label_8015F9F8;
    case 0x8015F9FCu: goto label_8015F9FC;
    case 0x8015FA00u: goto label_8015FA00;
    case 0x8015FA04u: goto label_8015FA04;
    case 0x8015FA08u: goto label_8015FA08;
    case 0x8015FA0Cu: goto label_8015FA0C;
    case 0x8015FA10u: goto label_8015FA10;
    case 0x8015FA14u: goto label_8015FA14;
    case 0x8015FA18u: goto label_8015FA18;
    case 0x8015FA1Cu: goto label_8015FA1C;
    case 0x8015FA20u: goto label_8015FA20;
    case 0x8015FA24u: goto label_8015FA24;
    case 0x8015FA28u: goto label_8015FA28;
    case 0x8015FA2Cu: goto label_8015FA2C;
    case 0x8015FA30u: goto label_8015FA30;
    case 0x8015FA34u: goto label_8015FA34;
    case 0x8015FA38u: goto label_8015FA38;
    case 0x8015FA3Cu: goto label_8015FA3C;
    case 0x8015FA40u: goto label_8015FA40;
    case 0x8015FA44u: goto label_8015FA44;
    case 0x8015FA48u: goto label_8015FA48;
    case 0x8015FA4Cu: goto label_8015FA4C;
    case 0x8015FA50u: goto label_8015FA50;
    case 0x8015FA54u: goto label_8015FA54;
    case 0x8015FA58u: goto label_8015FA58;
    case 0x8015FA5Cu: goto label_8015FA5C;
    case 0x8015FA60u: goto label_8015FA60;
    case 0x8015FA64u: goto label_8015FA64;
    case 0x8015FA68u: goto label_8015FA68;
    case 0x8015FA6Cu: goto label_8015FA6C;
    case 0x8015FA70u: goto label_8015FA70;
    case 0x8015FA74u: goto label_8015FA74;
    case 0x8015FA78u: goto label_8015FA78;
    case 0x8015FA7Cu: goto label_8015FA7C;
    case 0x8015FA80u: goto label_8015FA80;
    case 0x8015FA84u: goto label_8015FA84;
    case 0x8015FA88u: goto label_8015FA88;
    case 0x8015FA8Cu: goto label_8015FA8C;
    case 0x8015FA90u: goto label_8015FA90;
    case 0x8015FA94u: goto label_8015FA94;
    case 0x8015FA98u: goto label_8015FA98;
    case 0x8015FA9Cu: goto label_8015FA9C;
    case 0x8015FAA0u: goto label_8015FAA0;
    case 0x8015FAA4u: goto label_8015FAA4;
    case 0x8015FAA8u: goto label_8015FAA8;
    case 0x8015FAACu: goto label_8015FAAC;
    case 0x8015FAB0u: goto label_8015FAB0;
    case 0x8015FAB4u: goto label_8015FAB4;
    case 0x8015FAB8u: goto label_8015FAB8;
    case 0x8015FABCu: goto label_8015FABC;
    case 0x8015FAC0u: goto label_8015FAC0;
    case 0x8015FAC4u: goto label_8015FAC4;
    case 0x8015FAC8u: goto label_8015FAC8;
    case 0x8015FACCu: goto label_8015FACC;
    case 0x8015FAD0u: goto label_8015FAD0;
    case 0x8015FAD4u: goto label_8015FAD4;
    case 0x8015FAD8u: goto label_8015FAD8;
    case 0x8015FADCu: goto label_8015FADC;
    case 0x8015FAE0u: goto label_8015FAE0;
    case 0x8015FAE4u: goto label_8015FAE4;
    case 0x8015FAE8u: goto label_8015FAE8;
    case 0x8015FAECu: goto label_8015FAEC;
    case 0x8015FAF0u: goto label_8015FAF0;
    case 0x8015FAF4u: goto label_8015FAF4;
    case 0x8015FAF8u: goto label_8015FAF8;
    case 0x8015FAFCu: goto label_8015FAFC;
    case 0x8015FB00u: goto label_8015FB00;
    case 0x8015FB04u: goto label_8015FB04;
    case 0x8015FB08u: goto label_8015FB08;
    case 0x8015FB0Cu: goto label_8015FB0C;
    case 0x8015FB10u: goto label_8015FB10;
    case 0x8015FB14u: goto label_8015FB14;
    case 0x8015FB18u: goto label_8015FB18;
    case 0x8015FB1Cu: goto label_8015FB1C;
    case 0x8015FB20u: goto label_8015FB20;
    case 0x8015FB24u: goto label_8015FB24;
    case 0x8015FB28u: goto label_8015FB28;
    case 0x8015FB2Cu: goto label_8015FB2C;
    case 0x8015FB30u: goto label_8015FB30;
    case 0x8015FB34u: goto label_8015FB34;
    case 0x8015FB38u: goto label_8015FB38;
    case 0x8015FB3Cu: goto label_8015FB3C;
    case 0x8015FB40u: goto label_8015FB40;
    case 0x8015FB44u: goto label_8015FB44;
    case 0x8015FB48u: goto label_8015FB48;
    case 0x8015FB4Cu: goto label_8015FB4C;
    case 0x8015FB50u: goto label_8015FB50;
    case 0x8015FB54u: goto label_8015FB54;
    case 0x8015FB58u: goto label_8015FB58;
    case 0x8015FB5Cu: goto label_8015FB5C;
    case 0x8015FB60u: goto label_8015FB60;
    case 0x8015FB64u: goto label_8015FB64;
    case 0x8015FB68u: goto label_8015FB68;
    case 0x8015FB6Cu: goto label_8015FB6C;
    case 0x8015FB70u: goto label_8015FB70;
    case 0x8015FB74u: goto label_8015FB74;
    case 0x8015FB78u: goto label_8015FB78;
    case 0x8015FB7Cu: goto label_8015FB7C;
    case 0x8015FB80u: goto label_8015FB80;
    case 0x8015FB84u: goto label_8015FB84;
    case 0x8015FB88u: goto label_8015FB88;
    case 0x8015FB8Cu: goto label_8015FB8C;
    case 0x8015FB90u: goto label_8015FB90;
    case 0x8015FB94u: goto label_8015FB94;
    case 0x8015FB98u: goto label_8015FB98;
    case 0x8015FB9Cu: goto label_8015FB9C;
    case 0x8015FBA0u: goto label_8015FBA0;
    case 0x8015FBA4u: goto label_8015FBA4;
    case 0x8015FBA8u: goto label_8015FBA8;
    case 0x8015FBACu: goto label_8015FBAC;
    case 0x8015FBB0u: goto label_8015FBB0;
    case 0x8015FBB4u: goto label_8015FBB4;
    case 0x8015FBB8u: goto label_8015FBB8;
    case 0x8015FBBCu: goto label_8015FBBC;
    case 0x8015FBC0u: goto label_8015FBC0;
    case 0x8015FBC4u: goto label_8015FBC4;
    case 0x8015FBC8u: goto label_8015FBC8;
    case 0x8015FBCCu: goto label_8015FBCC;
    case 0x8015FBD0u: goto label_8015FBD0;
    case 0x8015FBD4u: goto label_8015FBD4;
    case 0x8015FBD8u: goto label_8015FBD8;
    case 0x8015FBDCu: goto label_8015FBDC;
    case 0x8015FBE0u: goto label_8015FBE0;
    case 0x8015FBE4u: goto label_8015FBE4;
    case 0x8015FBE8u: goto label_8015FBE8;
    case 0x8015FBECu: goto label_8015FBEC;
    case 0x8015FBF0u: goto label_8015FBF0;
    case 0x8015FBF4u: goto label_8015FBF4;
    case 0x8015FBF8u: goto label_8015FBF8;
    case 0x8015FBFCu: goto label_8015FBFC;
    case 0x8015FC00u: goto label_8015FC00;
    case 0x8015FC04u: goto label_8015FC04;
    case 0x8015FC08u: goto label_8015FC08;
    case 0x8015FC0Cu: goto label_8015FC0C;
    case 0x8015FC10u: goto label_8015FC10;
    case 0x8015FC14u: goto label_8015FC14;
    case 0x8015FC18u: goto label_8015FC18;
    case 0x8015FC1Cu: goto label_8015FC1C;
    case 0x8015FC20u: goto label_8015FC20;
    case 0x8015FC24u: goto label_8015FC24;
    case 0x8015FC28u: goto label_8015FC28;
    case 0x8015FC2Cu: goto label_8015FC2C;
    case 0x8015FC30u: goto label_8015FC30;
    case 0x8015FC34u: goto label_8015FC34;
    case 0x8015FC38u: goto label_8015FC38;
    case 0x8015FC3Cu: goto label_8015FC3C;
    case 0x8015FC40u: goto label_8015FC40;
    case 0x8015FC44u: goto label_8015FC44;
    case 0x8015FC48u: goto label_8015FC48;
    case 0x8015FC4Cu: goto label_8015FC4C;
    case 0x8015FC50u: goto label_8015FC50;
    case 0x8015FC54u: goto label_8015FC54;
    case 0x8015FC58u: goto label_8015FC58;
    case 0x8015FC5Cu: goto label_8015FC5C;
    case 0x8015FC60u: goto label_8015FC60;
    case 0x8015FC64u: goto label_8015FC64;
    case 0x8015FC68u: goto label_8015FC68;
    case 0x8015FC6Cu: goto label_8015FC6C;
    case 0x8015FC70u: goto label_8015FC70;
    case 0x8015FC74u: goto label_8015FC74;
    case 0x8015FC78u: goto label_8015FC78;
    case 0x8015FC7Cu: goto label_8015FC7C;
    case 0x8015FC80u: goto label_8015FC80;
    case 0x8015FC84u: goto label_8015FC84;
    case 0x8015FC88u: goto label_8015FC88;
    case 0x8015FC8Cu: goto label_8015FC8C;
    case 0x8015FC90u: goto label_8015FC90;
    case 0x8015FC94u: goto label_8015FC94;
    case 0x8015FC98u: goto label_8015FC98;
    case 0x8015FC9Cu: goto label_8015FC9C;
    case 0x8015FCA0u: goto label_8015FCA0;
    case 0x8015FCA4u: goto label_8015FCA4;
    case 0x8015FCA8u: goto label_8015FCA8;
    case 0x8015FCACu: goto label_8015FCAC;
    case 0x8015FCB0u: goto label_8015FCB0;
    case 0x8015FCB4u: goto label_8015FCB4;
    case 0x8015FCB8u: goto label_8015FCB8;
    case 0x8015FCBCu: goto label_8015FCBC;
    case 0x8015FCC0u: goto label_8015FCC0;
    case 0x8015FCC4u: goto label_8015FCC4;
    case 0x8015FCC8u: goto label_8015FCC8;
    case 0x8015FCCCu: goto label_8015FCCC;
    case 0x8015FCD0u: goto label_8015FCD0;
    case 0x8015FCD4u: goto label_8015FCD4;
    case 0x8015FCD8u: goto label_8015FCD8;
    case 0x8015FCDCu: goto label_8015FCDC;
    case 0x8015FCE0u: goto label_8015FCE0;
    case 0x8015FCE4u: goto label_8015FCE4;
    case 0x8015FCE8u: goto label_8015FCE8;
    case 0x8015FCECu: goto label_8015FCEC;
    case 0x8015FCF0u: goto label_8015FCF0;
    case 0x8015FCF4u: goto label_8015FCF4;
    case 0x8015FCF8u: goto label_8015FCF8;
    case 0x8015FCFCu: goto label_8015FCFC;
    case 0x8015FD00u: goto label_8015FD00;
    case 0x8015FD04u: goto label_8015FD04;
    case 0x8015FD08u: goto label_8015FD08;
    case 0x8015FD0Cu: goto label_8015FD0C;
    case 0x8015FD10u: goto label_8015FD10;
    case 0x8015FD14u: goto label_8015FD14;
    case 0x8015FD18u: goto label_8015FD18;
    case 0x8015FD1Cu: goto label_8015FD1C;
    case 0x8015FD20u: goto label_8015FD20;
    case 0x8015FD24u: goto label_8015FD24;
    case 0x8015FD28u: goto label_8015FD28;
    case 0x8015FD2Cu: goto label_8015FD2C;
    case 0x8015FD30u: goto label_8015FD30;
    case 0x8015FD34u: goto label_8015FD34;
    case 0x8015FD38u: goto label_8015FD38;
    case 0x8015FD3Cu: goto label_8015FD3C;
    case 0x8015FD40u: goto label_8015FD40;
    case 0x8015FD44u: goto label_8015FD44;
    case 0x8015FD48u: goto label_8015FD48;
    case 0x8015FD4Cu: goto label_8015FD4C;
    case 0x8015FD50u: goto label_8015FD50;
    case 0x8015FD54u: goto label_8015FD54;
    case 0x8015FD58u: goto label_8015FD58;
    case 0x8015FD5Cu: goto label_8015FD5C;
    case 0x8015FD60u: goto label_8015FD60;
    case 0x8015FD64u: goto label_8015FD64;
    case 0x8015FD68u: goto label_8015FD68;
    case 0x8015FD6Cu: goto label_8015FD6C;
    case 0x8015FD70u: goto label_8015FD70;
    case 0x8015FD74u: goto label_8015FD74;
    case 0x8015FD78u: goto label_8015FD78;
    case 0x8015FD7Cu: goto label_8015FD7C;
    case 0x8015FD80u: goto label_8015FD80;
    case 0x8015FD84u: goto label_8015FD84;
    case 0x8015FD88u: goto label_8015FD88;
    case 0x8015FD8Cu: goto label_8015FD8C;
    case 0x8015FD90u: goto label_8015FD90;
    case 0x8015FD94u: goto label_8015FD94;
    case 0x8015FD98u: goto label_8015FD98;
    case 0x8015FD9Cu: goto label_8015FD9C;
    case 0x8015FDA0u: goto label_8015FDA0;
    case 0x8015FDA4u: goto label_8015FDA4;
    case 0x8015FDA8u: goto label_8015FDA8;
    case 0x8015FDACu: goto label_8015FDAC;
    case 0x8015FDB0u: goto label_8015FDB0;
    case 0x8015FDB4u: goto label_8015FDB4;
    case 0x8015FDB8u: goto label_8015FDB8;
    case 0x8015FDBCu: goto label_8015FDBC;
    case 0x8015FDC0u: goto label_8015FDC0;
    case 0x8015FDC4u: goto label_8015FDC4;
    case 0x8015FDC8u: goto label_8015FDC8;
    case 0x8015FDCCu: goto label_8015FDCC;
    case 0x8015FDD0u: goto label_8015FDD0;
    case 0x8015FDD4u: goto label_8015FDD4;
    case 0x8015FDD8u: goto label_8015FDD8;
    case 0x8015FDDCu: goto label_8015FDDC;
    case 0x8015FDE0u: goto label_8015FDE0;
    case 0x8015FDE4u: goto label_8015FDE4;
    case 0x8015FDE8u: goto label_8015FDE8;
    case 0x8015FDECu: goto label_8015FDEC;
    case 0x8015FDF0u: goto label_8015FDF0;
    case 0x8015FDF4u: goto label_8015FDF4;
    case 0x8015FDF8u: goto label_8015FDF8;
    case 0x8015FDFCu: goto label_8015FDFC;
    case 0x8015FE00u: goto label_8015FE00;
    case 0x8015FE04u: goto label_8015FE04;
    case 0x8015FE08u: goto label_8015FE08;
    case 0x8015FE0Cu: goto label_8015FE0C;
    case 0x8015FE10u: goto label_8015FE10;
    case 0x8015FE14u: goto label_8015FE14;
    case 0x8015FE18u: goto label_8015FE18;
    case 0x8015FE1Cu: goto label_8015FE1C;
    case 0x8015FE20u: goto label_8015FE20;
    case 0x8015FE24u: goto label_8015FE24;
    case 0x8015FE28u: goto label_8015FE28;
    case 0x8015FE2Cu: goto label_8015FE2C;
    case 0x8015FE30u: goto label_8015FE30;
    case 0x8015FE34u: goto label_8015FE34;
    case 0x8015FE38u: goto label_8015FE38;
    case 0x8015FE3Cu: goto label_8015FE3C;
    case 0x8015FE40u: goto label_8015FE40;
    case 0x8015FE44u: goto label_8015FE44;
    case 0x8015FE48u: goto label_8015FE48;
    case 0x8015FE4Cu: goto label_8015FE4C;
    case 0x8015FE50u: goto label_8015FE50;
    case 0x8015FE54u: goto label_8015FE54;
    case 0x8015FE58u: goto label_8015FE58;
    case 0x8015FE5Cu: goto label_8015FE5C;
    case 0x8015FE60u: goto label_8015FE60;
    case 0x8015FE64u: goto label_8015FE64;
    case 0x8015FE68u: goto label_8015FE68;
    case 0x8015FE6Cu: goto label_8015FE6C;
    case 0x8015FE70u: goto label_8015FE70;
    case 0x8015FE74u: goto label_8015FE74;
    case 0x8015FE78u: goto label_8015FE78;
    case 0x8015FE7Cu: goto label_8015FE7C;
    case 0x8015FE80u: goto label_8015FE80;
    case 0x8015FE84u: goto label_8015FE84;
    case 0x8015FE88u: goto label_8015FE88;
    case 0x8015FE8Cu: goto label_8015FE8C;
    case 0x8015FE90u: goto label_8015FE90;
    case 0x8015FE94u: goto label_8015FE94;
    case 0x8015FE98u: goto label_8015FE98;
    case 0x8015FE9Cu: goto label_8015FE9C;
    case 0x8015FEA0u: goto label_8015FEA0;
    case 0x8015FEA4u: goto label_8015FEA4;
    case 0x8015FEA8u: goto label_8015FEA8;
    case 0x8015FEACu: goto label_8015FEAC;
    case 0x8015FEB0u: goto label_8015FEB0;
    case 0x8015FEB4u: goto label_8015FEB4;
    case 0x8015FEB8u: goto label_8015FEB8;
    case 0x8015FEBCu: goto label_8015FEBC;
    case 0x8015FEC0u: goto label_8015FEC0;
    case 0x8015FEC4u: goto label_8015FEC4;
    case 0x8015FEC8u: goto label_8015FEC8;
    case 0x8015FECCu: goto label_8015FECC;
    case 0x8015FED0u: goto label_8015FED0;
    case 0x8015FED4u: goto label_8015FED4;
    case 0x8015FED8u: goto label_8015FED8;
    case 0x8015FEDCu: goto label_8015FEDC;
    case 0x8015FEE0u: goto label_8015FEE0;
    case 0x8015FEE4u: goto label_8015FEE4;
    case 0x8015FEE8u: goto label_8015FEE8;
    case 0x8015FEECu: goto label_8015FEEC;
    case 0x8015FEF0u: goto label_8015FEF0;
    case 0x8015FEF4u: goto label_8015FEF4;
    case 0x8015FEF8u: goto label_8015FEF8;
    case 0x8015FEFCu: goto label_8015FEFC;
    case 0x8015FF00u: goto label_8015FF00;
    case 0x8015FF04u: goto label_8015FF04;
    case 0x8015FF08u: goto label_8015FF08;
    case 0x8015FF0Cu: goto label_8015FF0C;
    case 0x8015FF10u: goto label_8015FF10;
    case 0x8015FF14u: goto label_8015FF14;
    case 0x8015FF18u: goto label_8015FF18;
    case 0x8015FF1Cu: goto label_8015FF1C;
    case 0x8015FF20u: goto label_8015FF20;
    case 0x8015FF24u: goto label_8015FF24;
    case 0x8015FF28u: goto label_8015FF28;
    case 0x8015FF2Cu: goto label_8015FF2C;
    case 0x8015FF30u: goto label_8015FF30;
    case 0x8015FF34u: goto label_8015FF34;
    case 0x8015FF38u: goto label_8015FF38;
    case 0x8015FF3Cu: goto label_8015FF3C;
    case 0x8015FF40u: goto label_8015FF40;
    case 0x8015FF44u: goto label_8015FF44;
    case 0x8015FF48u: goto label_8015FF48;
    case 0x8015FF4Cu: goto label_8015FF4C;
    case 0x8015FF50u: goto label_8015FF50;
    case 0x8015FF54u: goto label_8015FF54;
    case 0x8015FF58u: goto label_8015FF58;
    case 0x8015FF5Cu: goto label_8015FF5C;
    case 0x8015FF60u: goto label_8015FF60;
    case 0x8015FF64u: goto label_8015FF64;
    case 0x8015FF68u: goto label_8015FF68;
    case 0x8015FF6Cu: goto label_8015FF6C;
    case 0x8015FF70u: goto label_8015FF70;
    case 0x8015FF74u: goto label_8015FF74;
    case 0x8015FF78u: goto label_8015FF78;
    case 0x8015FF7Cu: goto label_8015FF7C;
    case 0x8015FF80u: goto label_8015FF80;
    case 0x8015FF84u: goto label_8015FF84;
    case 0x8015FF88u: goto label_8015FF88;
    case 0x8015FF8Cu: goto label_8015FF8C;
    case 0x8015FF90u: goto label_8015FF90;
    case 0x8015FF94u: goto label_8015FF94;
    case 0x8015FF98u: goto label_8015FF98;
    case 0x8015FF9Cu: goto label_8015FF9C;
    case 0x8015FFA0u: goto label_8015FFA0;
    case 0x8015FFA4u: goto label_8015FFA4;
    case 0x8015FFA8u: goto label_8015FFA8;
    case 0x8015FFACu: goto label_8015FFAC;
    case 0x8015FFB0u: goto label_8015FFB0;
    case 0x8015FFB4u: goto label_8015FFB4;
    case 0x8015FFB8u: goto label_8015FFB8;
    case 0x8015FFBCu: goto label_8015FFBC;
    case 0x8015FFC0u: goto label_8015FFC0;
    case 0x8015FFC4u: goto label_8015FFC4;
    case 0x8015FFC8u: goto label_8015FFC8;
    case 0x8015FFCCu: goto label_8015FFCC;
    case 0x8015FFD0u: goto label_8015FFD0;
    case 0x8015FFD4u: goto label_8015FFD4;
    case 0x8015FFD8u: goto label_8015FFD8;
    case 0x8015FFDCu: goto label_8015FFDC;
    case 0x8015FFE0u: goto label_8015FFE0;
    case 0x8015FFE4u: goto label_8015FFE4;
    case 0x8015FFE8u: goto label_8015FFE8;
    case 0x8015FFECu: goto label_8015FFEC;
    case 0x8015FFF0u: goto label_8015FFF0;
    case 0x8015FFF4u: goto label_8015FFF4;
    case 0x8015FFF8u: goto label_8015FFF8;
    case 0x8015FFFCu: goto label_8015FFFC;
    case 0x80160000u: goto label_80160000;
    case 0x80160004u: goto label_80160004;
    case 0x80160008u: goto label_80160008;
    case 0x8016000Cu: goto label_8016000C;
    case 0x80160010u: goto label_80160010;
    case 0x80160014u: goto label_80160014;
    case 0x80160018u: goto label_80160018;
    case 0x8016001Cu: goto label_8016001C;
    case 0x80160020u: goto label_80160020;
    case 0x80160024u: goto label_80160024;
    case 0x80160028u: goto label_80160028;
    case 0x8016002Cu: goto label_8016002C;
    case 0x80160030u: goto label_80160030;
    case 0x80160034u: goto label_80160034;
    case 0x80160038u: goto label_80160038;
    case 0x8016003Cu: goto label_8016003C;
    case 0x80160040u: goto label_80160040;
    case 0x80160044u: goto label_80160044;
    case 0x80160048u: goto label_80160048;
    case 0x8016004Cu: goto label_8016004C;
    case 0x80160050u: goto label_80160050;
    case 0x80160054u: goto label_80160054;
    case 0x80160058u: goto label_80160058;
    case 0x8016005Cu: goto label_8016005C;
    case 0x80160060u: goto label_80160060;
    case 0x80160064u: goto label_80160064;
    case 0x80160068u: goto label_80160068;
    case 0x8016006Cu: goto label_8016006C;
    case 0x80160070u: goto label_80160070;
    case 0x80160074u: goto label_80160074;
    case 0x80160078u: goto label_80160078;
    case 0x8016007Cu: goto label_8016007C;
    case 0x80160080u: goto label_80160080;
    case 0x80160084u: goto label_80160084;
    case 0x80160088u: goto label_80160088;
    case 0x8016008Cu: goto label_8016008C;
    case 0x80160090u: goto label_80160090;
    case 0x80160094u: goto label_80160094;
    case 0x80160098u: goto label_80160098;
    case 0x8016009Cu: goto label_8016009C;
    case 0x801600A0u: goto label_801600A0;
    case 0x801600A4u: goto label_801600A4;
    case 0x801600A8u: goto label_801600A8;
    case 0x801600ACu: goto label_801600AC;
    case 0x801600B0u: goto label_801600B0;
    case 0x801600B4u: goto label_801600B4;
    case 0x801600B8u: goto label_801600B8;
    case 0x801600BCu: goto label_801600BC;
    case 0x801600C0u: goto label_801600C0;
    case 0x801600C4u: goto label_801600C4;
    case 0x801600C8u: goto label_801600C8;
    case 0x801600CCu: goto label_801600CC;
    case 0x801600D0u: goto label_801600D0;
    case 0x801600D4u: goto label_801600D4;
    case 0x801600D8u: goto label_801600D8;
    case 0x801600DCu: goto label_801600DC;
    case 0x801600E0u: goto label_801600E0;
    case 0x801600E4u: goto label_801600E4;
    case 0x801600E8u: goto label_801600E8;
    case 0x801600ECu: goto label_801600EC;
    case 0x801600F0u: goto label_801600F0;
    case 0x801600F4u: goto label_801600F4;
    case 0x801600F8u: goto label_801600F8;
    case 0x801600FCu: goto label_801600FC;
    case 0x80160100u: goto label_80160100;
    case 0x80160104u: goto label_80160104;
    case 0x80160108u: goto label_80160108;
    case 0x8016010Cu: goto label_8016010C;
    case 0x80160110u: goto label_80160110;
    case 0x80160114u: goto label_80160114;
    case 0x80160118u: goto label_80160118;
    case 0x8016011Cu: goto label_8016011C;
    case 0x80160120u: goto label_80160120;
    case 0x80160124u: goto label_80160124;
    case 0x80160128u: goto label_80160128;
    case 0x8016012Cu: goto label_8016012C;
    case 0x80160130u: goto label_80160130;
    case 0x80160134u: goto label_80160134;
    case 0x80160138u: goto label_80160138;
    case 0x8016013Cu: goto label_8016013C;
    case 0x80160140u: goto label_80160140;
    case 0x80160144u: goto label_80160144;
    case 0x80160148u: goto label_80160148;
    case 0x8016014Cu: goto label_8016014C;
    case 0x80160150u: goto label_80160150;
    case 0x80160154u: goto label_80160154;
    case 0x80160158u: goto label_80160158;
    case 0x8016015Cu: goto label_8016015C;
    case 0x80160160u: goto label_80160160;
    case 0x80160164u: goto label_80160164;
    case 0x80160168u: goto label_80160168;
    case 0x8016016Cu: goto label_8016016C;
    case 0x80160170u: goto label_80160170;
    case 0x80160174u: goto label_80160174;
    case 0x80160178u: goto label_80160178;
    case 0x8016017Cu: goto label_8016017C;
    case 0x80160180u: goto label_80160180;
    case 0x80160184u: goto label_80160184;
    case 0x80160188u: goto label_80160188;
    case 0x8016018Cu: goto label_8016018C;
    case 0x80160190u: goto label_80160190;
    case 0x80160194u: goto label_80160194;
    case 0x80160198u: goto label_80160198;
    case 0x8016019Cu: goto label_8016019C;
    case 0x801601A0u: goto label_801601A0;
    case 0x801601A4u: goto label_801601A4;
    case 0x801601A8u: goto label_801601A8;
    case 0x801601ACu: goto label_801601AC;
    case 0x801601B0u: goto label_801601B0;
    case 0x801601B4u: goto label_801601B4;
    case 0x801601B8u: goto label_801601B8;
    case 0x801601BCu: goto label_801601BC;
    case 0x801601C0u: goto label_801601C0;
    case 0x801601C4u: goto label_801601C4;
    case 0x801601C8u: goto label_801601C8;
    case 0x801601CCu: goto label_801601CC;
    case 0x801601D0u: goto label_801601D0;
    case 0x801601D4u: goto label_801601D4;
    case 0x801601D8u: goto label_801601D8;
    case 0x801601DCu: goto label_801601DC;
    case 0x801601E0u: goto label_801601E0;
    case 0x801601E4u: goto label_801601E4;
    case 0x801601E8u: goto label_801601E8;
    case 0x801601ECu: goto label_801601EC;
    case 0x801601F0u: goto label_801601F0;
    case 0x801601F4u: goto label_801601F4;
    case 0x801601F8u: goto label_801601F8;
    case 0x801601FCu: goto label_801601FC;
    case 0x80160200u: goto label_80160200;
    case 0x80160204u: goto label_80160204;
    case 0x80160208u: goto label_80160208;
    case 0x8016020Cu: goto label_8016020C;
    case 0x80160210u: goto label_80160210;
    case 0x80160214u: goto label_80160214;
    case 0x80160218u: goto label_80160218;
    case 0x8016021Cu: goto label_8016021C;
    case 0x80160220u: goto label_80160220;
    case 0x80160224u: goto label_80160224;
    case 0x80160228u: goto label_80160228;
    case 0x8016022Cu: goto label_8016022C;
    case 0x80160230u: goto label_80160230;
    case 0x80160234u: goto label_80160234;
    case 0x80160238u: goto label_80160238;
    case 0x8016023Cu: goto label_8016023C;
    case 0x80160240u: goto label_80160240;
    case 0x80160244u: goto label_80160244;
    case 0x80160248u: goto label_80160248;
    case 0x8016024Cu: goto label_8016024C;
    case 0x80160250u: goto label_80160250;
    case 0x80160254u: goto label_80160254;
    case 0x80160258u: goto label_80160258;
    case 0x8016025Cu: goto label_8016025C;
    case 0x80160260u: goto label_80160260;
    case 0x80160264u: goto label_80160264;
    case 0x80160268u: goto label_80160268;
    case 0x8016026Cu: goto label_8016026C;
    case 0x80160270u: goto label_80160270;
    case 0x80160274u: goto label_80160274;
    case 0x80160278u: goto label_80160278;
    case 0x8016027Cu: goto label_8016027C;
    case 0x80160280u: goto label_80160280;
    case 0x80160284u: goto label_80160284;
    case 0x80160288u: goto label_80160288;
    case 0x8016028Cu: goto label_8016028C;
    case 0x80160290u: goto label_80160290;
    case 0x80160294u: goto label_80160294;
    case 0x80160298u: goto label_80160298;
    case 0x8016029Cu: goto label_8016029C;
    case 0x801602A0u: goto label_801602A0;
    case 0x801602A4u: goto label_801602A4;
    case 0x801602A8u: goto label_801602A8;
    case 0x801602ACu: goto label_801602AC;
    case 0x801602B0u: goto label_801602B0;
    case 0x801602B4u: goto label_801602B4;
    case 0x801602B8u: goto label_801602B8;
    case 0x801602BCu: goto label_801602BC;
    case 0x801602C0u: goto label_801602C0;
    case 0x801602C4u: goto label_801602C4;
    case 0x801602C8u: goto label_801602C8;
    case 0x801602CCu: goto label_801602CC;
    case 0x801602D0u: goto label_801602D0;
    case 0x801602D4u: goto label_801602D4;
    case 0x801602D8u: goto label_801602D8;
    case 0x801602DCu: goto label_801602DC;
    case 0x801602E0u: goto label_801602E0;
    case 0x801602E4u: goto label_801602E4;
    case 0x801602E8u: goto label_801602E8;
    case 0x801602ECu: goto label_801602EC;
    case 0x801602F0u: goto label_801602F0;
    case 0x801602F4u: goto label_801602F4;
    case 0x801602F8u: goto label_801602F8;
    case 0x801602FCu: goto label_801602FC;
    case 0x80160300u: goto label_80160300;
    case 0x80160304u: goto label_80160304;
    case 0x80160308u: goto label_80160308;
    case 0x8016030Cu: goto label_8016030C;
    case 0x80160310u: goto label_80160310;
    case 0x80160314u: goto label_80160314;
    case 0x80160318u: goto label_80160318;
    case 0x8016031Cu: goto label_8016031C;
    case 0x80160320u: goto label_80160320;
    case 0x80160324u: goto label_80160324;
    case 0x80160328u: goto label_80160328;
    case 0x8016032Cu: goto label_8016032C;
    case 0x80160330u: goto label_80160330;
    case 0x80160334u: goto label_80160334;
    case 0x80160338u: goto label_80160338;
    case 0x8016033Cu: goto label_8016033C;
    case 0x80160340u: goto label_80160340;
    case 0x80160344u: goto label_80160344;
    case 0x80160348u: goto label_80160348;
    case 0x8016034Cu: goto label_8016034C;
    case 0x80160350u: goto label_80160350;
    case 0x80160354u: goto label_80160354;
    case 0x80160358u: goto label_80160358;
    case 0x8016035Cu: goto label_8016035C;
    case 0x80160360u: goto label_80160360;
    case 0x80160364u: goto label_80160364;
    case 0x80160368u: goto label_80160368;
    case 0x8016036Cu: goto label_8016036C;
    case 0x80160370u: goto label_80160370;
    case 0x80160374u: goto label_80160374;
    case 0x80160378u: goto label_80160378;
    case 0x8016037Cu: goto label_8016037C;
    case 0x80160380u: goto label_80160380;
    case 0x80160384u: goto label_80160384;
    case 0x80160388u: goto label_80160388;
    case 0x8016038Cu: goto label_8016038C;
    case 0x80160390u: goto label_80160390;
    case 0x80160394u: goto label_80160394;
    case 0x80160398u: goto label_80160398;
    case 0x8016039Cu: goto label_8016039C;
    case 0x801603A0u: goto label_801603A0;
    case 0x801603A4u: goto label_801603A4;
    case 0x801603A8u: goto label_801603A8;
    case 0x801603ACu: goto label_801603AC;
    case 0x801603B0u: goto label_801603B0;
    case 0x801603B4u: goto label_801603B4;
    case 0x801603B8u: goto label_801603B8;
    case 0x801603BCu: goto label_801603BC;
    case 0x801603C0u: goto label_801603C0;
    case 0x801603C4u: goto label_801603C4;
    case 0x801603C8u: goto label_801603C8;
    case 0x801603CCu: goto label_801603CC;
    case 0x801603D0u: goto label_801603D0;
    case 0x801603D4u: goto label_801603D4;
    case 0x801603D8u: goto label_801603D8;
    case 0x801603DCu: goto label_801603DC;
    case 0x801603E0u: goto label_801603E0;
    case 0x801603E4u: goto label_801603E4;
    case 0x801603E8u: goto label_801603E8;
    case 0x801603ECu: goto label_801603EC;
    case 0x801603F0u: goto label_801603F0;
    case 0x801603F4u: goto label_801603F4;
    case 0x801603F8u: goto label_801603F8;
    case 0x801603FCu: goto label_801603FC;
    case 0x80160400u: goto label_80160400;
    case 0x80160404u: goto label_80160404;
    case 0x80160408u: goto label_80160408;
    case 0x8016040Cu: goto label_8016040C;
    case 0x80160410u: goto label_80160410;
    case 0x80160414u: goto label_80160414;
    case 0x80160418u: goto label_80160418;
    case 0x8016041Cu: goto label_8016041C;
    case 0x80160420u: goto label_80160420;
    case 0x80160424u: goto label_80160424;
    case 0x80160428u: goto label_80160428;
    case 0x8016042Cu: goto label_8016042C;
    case 0x80160430u: goto label_80160430;
    case 0x80160434u: goto label_80160434;
    case 0x80160438u: goto label_80160438;
    case 0x8016043Cu: goto label_8016043C;
    case 0x80160440u: goto label_80160440;
    case 0x80160444u: goto label_80160444;
    case 0x80160448u: goto label_80160448;
    case 0x8016044Cu: goto label_8016044C;
    case 0x80160450u: goto label_80160450;
    case 0x80160454u: goto label_80160454;
    case 0x80160458u: goto label_80160458;
    case 0x8016045Cu: goto label_8016045C;
    case 0x80160460u: goto label_80160460;
    case 0x80160464u: goto label_80160464;
    case 0x80160468u: goto label_80160468;
    case 0x8016046Cu: goto label_8016046C;
    case 0x80160470u: goto label_80160470;
    case 0x80160474u: goto label_80160474;
    case 0x80160478u: goto label_80160478;
    case 0x8016047Cu: goto label_8016047C;
    case 0x80160480u: goto label_80160480;
    case 0x80160484u: goto label_80160484;
    case 0x80160488u: goto label_80160488;
    case 0x8016048Cu: goto label_8016048C;
    case 0x80160490u: goto label_80160490;
    case 0x80160494u: goto label_80160494;
    case 0x80160498u: goto label_80160498;
    case 0x8016049Cu: goto label_8016049C;
    case 0x801604A0u: goto label_801604A0;
    case 0x801604A4u: goto label_801604A4;
    case 0x801604A8u: goto label_801604A8;
    case 0x801604ACu: goto label_801604AC;
    case 0x801604B0u: goto label_801604B0;
    case 0x801604B4u: goto label_801604B4;
    case 0x801604B8u: goto label_801604B8;
    case 0x801604BCu: goto label_801604BC;
    case 0x801604C0u: goto label_801604C0;
    case 0x801604C4u: goto label_801604C4;
    case 0x801604C8u: goto label_801604C8;
    case 0x801604CCu: goto label_801604CC;
    case 0x801604D0u: goto label_801604D0;
    case 0x801604D4u: goto label_801604D4;
    case 0x801604D8u: goto label_801604D8;
    case 0x801604DCu: goto label_801604DC;
    case 0x801604E0u: goto label_801604E0;
    case 0x801604E4u: goto label_801604E4;
    case 0x801604E8u: goto label_801604E8;
    case 0x801604ECu: goto label_801604EC;
    case 0x801604F0u: goto label_801604F0;
    case 0x801604F4u: goto label_801604F4;
    case 0x801604F8u: goto label_801604F8;
    case 0x801604FCu: goto label_801604FC;
    case 0x80160500u: goto label_80160500;
    case 0x80160504u: goto label_80160504;
    case 0x80160508u: goto label_80160508;
    case 0x8016050Cu: goto label_8016050C;
    case 0x80160510u: goto label_80160510;
    case 0x80160514u: goto label_80160514;
    case 0x80160518u: goto label_80160518;
    case 0x8016051Cu: goto label_8016051C;
    case 0x80160520u: goto label_80160520;
    case 0x80160524u: goto label_80160524;
    case 0x80160528u: goto label_80160528;
    case 0x8016052Cu: goto label_8016052C;
    case 0x80160530u: goto label_80160530;
    case 0x80160534u: goto label_80160534;
    case 0x80160538u: goto label_80160538;
    case 0x8016053Cu: goto label_8016053C;
    case 0x80160540u: goto label_80160540;
    case 0x80160544u: goto label_80160544;
    case 0x80160548u: goto label_80160548;
    case 0x8016054Cu: goto label_8016054C;
    case 0x80160550u: goto label_80160550;
    case 0x80160554u: goto label_80160554;
    case 0x80160558u: goto label_80160558;
    case 0x8016055Cu: goto label_8016055C;
    case 0x80160560u: goto label_80160560;
    case 0x80160564u: goto label_80160564;
    case 0x80160568u: goto label_80160568;
    case 0x8016056Cu: goto label_8016056C;
    case 0x80160570u: goto label_80160570;
    case 0x80160574u: goto label_80160574;
    case 0x80160578u: goto label_80160578;
    case 0x8016057Cu: goto label_8016057C;
    case 0x80160580u: goto label_80160580;
    case 0x80160584u: goto label_80160584;
    case 0x80160588u: goto label_80160588;
    case 0x8016058Cu: goto label_8016058C;
    case 0x80160590u: goto label_80160590;
    case 0x80160594u: goto label_80160594;
    case 0x80160598u: goto label_80160598;
    case 0x8016059Cu: goto label_8016059C;
    case 0x801605A0u: goto label_801605A0;
    case 0x801605A4u: goto label_801605A4;
    case 0x801605A8u: goto label_801605A8;
    case 0x801605ACu: goto label_801605AC;
    case 0x801605B0u: goto label_801605B0;
    case 0x801605B4u: goto label_801605B4;
    case 0x801605B8u: goto label_801605B8;
    case 0x801605BCu: goto label_801605BC;
    case 0x801605C0u: goto label_801605C0;
    case 0x801605C4u: goto label_801605C4;
    case 0x801605C8u: goto label_801605C8;
    case 0x801605CCu: goto label_801605CC;
    case 0x801605D0u: goto label_801605D0;
    case 0x801605D4u: goto label_801605D4;
    case 0x801605D8u: goto label_801605D8;
    case 0x801605DCu: goto label_801605DC;
    case 0x801605E0u: goto label_801605E0;
    case 0x801605E4u: goto label_801605E4;
    case 0x801605E8u: goto label_801605E8;
    case 0x801605ECu: goto label_801605EC;
    case 0x801605F0u: goto label_801605F0;
    case 0x801605F4u: goto label_801605F4;
    case 0x801605F8u: goto label_801605F8;
    case 0x801605FCu: goto label_801605FC;
    case 0x80160600u: goto label_80160600;
    case 0x80160604u: goto label_80160604;
    case 0x80160608u: goto label_80160608;
    case 0x8016060Cu: goto label_8016060C;
    case 0x80160610u: goto label_80160610;
    case 0x80160614u: goto label_80160614;
    case 0x80160618u: goto label_80160618;
    case 0x8016061Cu: goto label_8016061C;
    case 0x80160620u: goto label_80160620;
    case 0x80160624u: goto label_80160624;
    case 0x80160628u: goto label_80160628;
    case 0x8016062Cu: goto label_8016062C;
    case 0x80160630u: goto label_80160630;
    case 0x80160634u: goto label_80160634;
    case 0x80160638u: goto label_80160638;
    case 0x8016063Cu: goto label_8016063C;
    case 0x80160640u: goto label_80160640;
    case 0x80160644u: goto label_80160644;
    case 0x80160648u: goto label_80160648;
    case 0x8016064Cu: goto label_8016064C;
    case 0x80160650u: goto label_80160650;
    case 0x80160654u: goto label_80160654;
    case 0x80160658u: goto label_80160658;
    case 0x8016065Cu: goto label_8016065C;
    case 0x80160660u: goto label_80160660;
    case 0x80160664u: goto label_80160664;
    case 0x80160668u: goto label_80160668;
    case 0x8016066Cu: goto label_8016066C;
    case 0x80160670u: goto label_80160670;
    case 0x80160674u: goto label_80160674;
    case 0x80160678u: goto label_80160678;
    case 0x8016067Cu: goto label_8016067C;
    case 0x80160680u: goto label_80160680;
    case 0x80160684u: goto label_80160684;
    case 0x80160688u: goto label_80160688;
    case 0x8016068Cu: goto label_8016068C;
    case 0x80160690u: goto label_80160690;
    case 0x80160694u: goto label_80160694;
    case 0x80160698u: goto label_80160698;
    case 0x8016069Cu: goto label_8016069C;
    case 0x801606A0u: goto label_801606A0;
    case 0x801606A4u: goto label_801606A4;
    case 0x801606A8u: goto label_801606A8;
    case 0x801606ACu: goto label_801606AC;
    case 0x801606B0u: goto label_801606B0;
    case 0x801606B4u: goto label_801606B4;
    case 0x801606B8u: goto label_801606B8;
    case 0x801606BCu: goto label_801606BC;
    case 0x801606C0u: goto label_801606C0;
    case 0x801606C4u: goto label_801606C4;
    case 0x801606C8u: goto label_801606C8;
    case 0x801606CCu: goto label_801606CC;
    case 0x801606D0u: goto label_801606D0;
    case 0x801606D4u: goto label_801606D4;
    case 0x801606D8u: goto label_801606D8;
    case 0x801606DCu: goto label_801606DC;
    case 0x801606E0u: goto label_801606E0;
    case 0x801606E4u: goto label_801606E4;
    case 0x801606E8u: goto label_801606E8;
    case 0x801606ECu: goto label_801606EC;
    case 0x801606F0u: goto label_801606F0;
    case 0x801606F4u: goto label_801606F4;
    case 0x801606F8u: goto label_801606F8;
    case 0x801606FCu: goto label_801606FC;
    case 0x80160700u: goto label_80160700;
    case 0x80160704u: goto label_80160704;
    case 0x80160708u: goto label_80160708;
    case 0x8016070Cu: goto label_8016070C;
    case 0x80160710u: goto label_80160710;
    case 0x80160714u: goto label_80160714;
    case 0x80160718u: goto label_80160718;
    case 0x8016071Cu: goto label_8016071C;
    case 0x80160720u: goto label_80160720;
    case 0x80160724u: goto label_80160724;
    case 0x80160728u: goto label_80160728;
    case 0x8016072Cu: goto label_8016072C;
    case 0x80160730u: goto label_80160730;
    case 0x80160734u: goto label_80160734;
    case 0x80160738u: goto label_80160738;
    case 0x8016073Cu: goto label_8016073C;
    case 0x80160740u: goto label_80160740;
    case 0x80160744u: goto label_80160744;
    case 0x80160748u: goto label_80160748;
    case 0x8016074Cu: goto label_8016074C;
    case 0x80160750u: goto label_80160750;
    case 0x80160754u: goto label_80160754;
    case 0x80160758u: goto label_80160758;
    case 0x8016075Cu: goto label_8016075C;
    case 0x80160760u: goto label_80160760;
    case 0x80160764u: goto label_80160764;
    case 0x80160768u: goto label_80160768;
    case 0x8016076Cu: goto label_8016076C;
    case 0x80160770u: goto label_80160770;
    case 0x80160774u: goto label_80160774;
    case 0x80160778u: goto label_80160778;
    case 0x8016077Cu: goto label_8016077C;
    case 0x80160780u: goto label_80160780;
    case 0x80160784u: goto label_80160784;
    case 0x80160788u: goto label_80160788;
    case 0x8016078Cu: goto label_8016078C;
    case 0x80160790u: goto label_80160790;
    case 0x80160794u: goto label_80160794;
    case 0x80160798u: goto label_80160798;
    case 0x8016079Cu: goto label_8016079C;
    case 0x801607A0u: goto label_801607A0;
    case 0x801607A4u: goto label_801607A4;
    case 0x801607A8u: goto label_801607A8;
    case 0x801607ACu: goto label_801607AC;
    case 0x801607B0u: goto label_801607B0;
    case 0x801607B4u: goto label_801607B4;
    case 0x801607B8u: goto label_801607B8;
    case 0x801607BCu: goto label_801607BC;
    case 0x801607C0u: goto label_801607C0;
    case 0x801607C4u: goto label_801607C4;
    case 0x801607C8u: goto label_801607C8;
    case 0x801607CCu: goto label_801607CC;
    case 0x801607D0u: goto label_801607D0;
    case 0x801607D4u: goto label_801607D4;
    case 0x801607D8u: goto label_801607D8;
    case 0x801607DCu: goto label_801607DC;
    case 0x801607E0u: goto label_801607E0;
    case 0x801607E4u: goto label_801607E4;
    case 0x801607E8u: goto label_801607E8;
    case 0x801607ECu: goto label_801607EC;
    case 0x801607F0u: goto label_801607F0;
    case 0x801607F4u: goto label_801607F4;
    case 0x801607F8u: goto label_801607F8;
    case 0x801607FCu: goto label_801607FC;
    case 0x80160800u: goto label_80160800;
    case 0x80160804u: goto label_80160804;
    case 0x80160808u: goto label_80160808;
    case 0x8016080Cu: goto label_8016080C;
    case 0x80160810u: goto label_80160810;
    case 0x80160814u: goto label_80160814;
    case 0x80160818u: goto label_80160818;
    case 0x8016081Cu: goto label_8016081C;
    case 0x80160820u: goto label_80160820;
    case 0x80160824u: goto label_80160824;
    case 0x80160828u: goto label_80160828;
    case 0x8016082Cu: goto label_8016082C;
    case 0x80160830u: goto label_80160830;
    case 0x80160834u: goto label_80160834;
    case 0x80160838u: goto label_80160838;
    case 0x8016083Cu: goto label_8016083C;
    case 0x80160840u: goto label_80160840;
    case 0x80160844u: goto label_80160844;
    case 0x80160848u: goto label_80160848;
    case 0x8016084Cu: goto label_8016084C;
    case 0x80160850u: goto label_80160850;
    case 0x80160854u: goto label_80160854;
    case 0x80160858u: goto label_80160858;
    case 0x8016085Cu: goto label_8016085C;
    case 0x80160860u: goto label_80160860;
    case 0x80160864u: goto label_80160864;
    case 0x80160868u: goto label_80160868;
    case 0x8016086Cu: goto label_8016086C;
    case 0x80160870u: goto label_80160870;
    case 0x80160874u: goto label_80160874;
    case 0x80160878u: goto label_80160878;
    case 0x8016087Cu: goto label_8016087C;
    case 0x80160880u: goto label_80160880;
    case 0x80160884u: goto label_80160884;
    case 0x80160888u: goto label_80160888;
    case 0x8016088Cu: goto label_8016088C;
    case 0x80160890u: goto label_80160890;
    case 0x80160894u: goto label_80160894;
    case 0x80160898u: goto label_80160898;
    case 0x8016089Cu: goto label_8016089C;
    case 0x801608A0u: goto label_801608A0;
    case 0x801608A4u: goto label_801608A4;
    case 0x801608A8u: goto label_801608A8;
    case 0x801608ACu: goto label_801608AC;
    case 0x801608B0u: goto label_801608B0;
    case 0x801608B4u: goto label_801608B4;
    case 0x801608B8u: goto label_801608B8;
    case 0x801608BCu: goto label_801608BC;
    case 0x801608C0u: goto label_801608C0;
    case 0x801608C4u: goto label_801608C4;
    case 0x801608C8u: goto label_801608C8;
    case 0x801608CCu: goto label_801608CC;
    case 0x801608D0u: goto label_801608D0;
    case 0x801608D4u: goto label_801608D4;
    case 0x801608D8u: goto label_801608D8;
    case 0x801608DCu: goto label_801608DC;
    case 0x801608E0u: goto label_801608E0;
    case 0x801608E4u: goto label_801608E4;
    case 0x801608E8u: goto label_801608E8;
    case 0x801608ECu: goto label_801608EC;
    case 0x801608F0u: goto label_801608F0;
    case 0x801608F4u: goto label_801608F4;
    case 0x801608F8u: goto label_801608F8;
    case 0x801608FCu: goto label_801608FC;
    case 0x80160900u: goto label_80160900;
    case 0x80160904u: goto label_80160904;
    case 0x80160908u: goto label_80160908;
    case 0x8016090Cu: goto label_8016090C;
    case 0x80160910u: goto label_80160910;
    case 0x80160914u: goto label_80160914;
    case 0x80160918u: goto label_80160918;
    case 0x8016091Cu: goto label_8016091C;
    case 0x80160920u: goto label_80160920;
    case 0x80160924u: goto label_80160924;
    case 0x80160928u: goto label_80160928;
    case 0x8016092Cu: goto label_8016092C;
    case 0x80160930u: goto label_80160930;
    case 0x80160934u: goto label_80160934;
    case 0x80160938u: goto label_80160938;
    case 0x8016093Cu: goto label_8016093C;
    case 0x80160940u: goto label_80160940;
    case 0x80160944u: goto label_80160944;
    case 0x80160948u: goto label_80160948;
    case 0x8016094Cu: goto label_8016094C;
    case 0x80160950u: goto label_80160950;
    case 0x80160954u: goto label_80160954;
    case 0x80160958u: goto label_80160958;
    case 0x8016095Cu: goto label_8016095C;
    case 0x80160960u: goto label_80160960;
    case 0x80160964u: goto label_80160964;
    case 0x80160968u: goto label_80160968;
    case 0x8016096Cu: goto label_8016096C;
    case 0x80160970u: goto label_80160970;
    case 0x80160974u: goto label_80160974;
    case 0x80160978u: goto label_80160978;
    case 0x8016097Cu: goto label_8016097C;
    case 0x80160980u: goto label_80160980;
    case 0x80160984u: goto label_80160984;
    case 0x80160988u: goto label_80160988;
    case 0x8016098Cu: goto label_8016098C;
    case 0x80160990u: goto label_80160990;
    case 0x80160994u: goto label_80160994;
    case 0x80160998u: goto label_80160998;
    case 0x8016099Cu: goto label_8016099C;
    case 0x801609A0u: goto label_801609A0;
    case 0x801609A4u: goto label_801609A4;
    case 0x801609A8u: goto label_801609A8;
    case 0x801609ACu: goto label_801609AC;
    case 0x801609B0u: goto label_801609B0;
    case 0x801609B4u: goto label_801609B4;
    case 0x801609B8u: goto label_801609B8;
    case 0x801609BCu: goto label_801609BC;
    case 0x801609C0u: goto label_801609C0;
    case 0x801609C4u: goto label_801609C4;
    case 0x801609C8u: goto label_801609C8;
    case 0x801609CCu: goto label_801609CC;
    case 0x801609D0u: goto label_801609D0;
    case 0x801609D4u: goto label_801609D4;
    case 0x801609D8u: goto label_801609D8;
    case 0x801609DCu: goto label_801609DC;
    case 0x801609E0u: goto label_801609E0;
    case 0x801609E4u: goto label_801609E4;
    case 0x801609E8u: goto label_801609E8;
    case 0x801609ECu: goto label_801609EC;
    case 0x801609F0u: goto label_801609F0;
    case 0x801609F4u: goto label_801609F4;
    case 0x801609F8u: goto label_801609F8;
    case 0x801609FCu: goto label_801609FC;
    case 0x80160A00u: goto label_80160A00;
    case 0x80160A04u: goto label_80160A04;
    case 0x80160A08u: goto label_80160A08;
    case 0x80160A0Cu: goto label_80160A0C;
    case 0x80160A10u: goto label_80160A10;
    case 0x80160A14u: goto label_80160A14;
    case 0x80160A18u: goto label_80160A18;
    case 0x80160A1Cu: goto label_80160A1C;
    case 0x80160A20u: goto label_80160A20;
    case 0x80160A24u: goto label_80160A24;
    case 0x80160A28u: goto label_80160A28;
    case 0x80160A2Cu: goto label_80160A2C;
    case 0x80160A30u: goto label_80160A30;
    case 0x80160A34u: goto label_80160A34;
    case 0x80160A38u: goto label_80160A38;
    case 0x80160A3Cu: goto label_80160A3C;
    case 0x80160A40u: goto label_80160A40;
    case 0x80160A44u: goto label_80160A44;
    case 0x80160A48u: goto label_80160A48;
    case 0x80160A4Cu: goto label_80160A4C;
    case 0x80160A50u: goto label_80160A50;
    case 0x80160A54u: goto label_80160A54;
    case 0x80160A58u: goto label_80160A58;
    case 0x80160A5Cu: goto label_80160A5C;
    case 0x80160A60u: goto label_80160A60;
    case 0x80160A64u: goto label_80160A64;
    case 0x80160A68u: goto label_80160A68;
    case 0x80160A6Cu: goto label_80160A6C;
    case 0x80160A70u: goto label_80160A70;
    case 0x80160A74u: goto label_80160A74;
    case 0x80160A78u: goto label_80160A78;
    case 0x80160A7Cu: goto label_80160A7C;
    case 0x80160A80u: goto label_80160A80;
    case 0x80160A84u: goto label_80160A84;
    case 0x80160A88u: goto label_80160A88;
    case 0x80160A8Cu: goto label_80160A8C;
    case 0x80160A90u: goto label_80160A90;
    case 0x80160A94u: goto label_80160A94;
    case 0x80160A98u: goto label_80160A98;
    case 0x80160A9Cu: goto label_80160A9C;
    case 0x80160AA0u: goto label_80160AA0;
    case 0x80160AA4u: goto label_80160AA4;
    case 0x80160AA8u: goto label_80160AA8;
    case 0x80160AACu: goto label_80160AAC;
    case 0x80160AB0u: goto label_80160AB0;
    case 0x80160AB4u: goto label_80160AB4;
    case 0x80160AB8u: goto label_80160AB8;
    case 0x80160ABCu: goto label_80160ABC;
    case 0x80160AC0u: goto label_80160AC0;
    case 0x80160AC4u: goto label_80160AC4;
    case 0x80160AC8u: goto label_80160AC8;
    case 0x80160ACCu: goto label_80160ACC;
    case 0x80160AD0u: goto label_80160AD0;
    case 0x80160AD4u: goto label_80160AD4;
    case 0x80160AD8u: goto label_80160AD8;
    case 0x80160ADCu: goto label_80160ADC;
    case 0x80160AE0u: goto label_80160AE0;
    case 0x80160AE4u: goto label_80160AE4;
    case 0x80160AE8u: goto label_80160AE8;
    case 0x80160AECu: goto label_80160AEC;
    case 0x80160AF0u: goto label_80160AF0;
    case 0x80160AF4u: goto label_80160AF4;
    case 0x80160AF8u: goto label_80160AF8;
    case 0x80160AFCu: goto label_80160AFC;
    case 0x80160B00u: goto label_80160B00;
    case 0x80160B04u: goto label_80160B04;
    case 0x80160B08u: goto label_80160B08;
    case 0x80160B0Cu: goto label_80160B0C;
    case 0x80160B10u: goto label_80160B10;
    case 0x80160B14u: goto label_80160B14;
    case 0x80160B18u: goto label_80160B18;
    case 0x80160B1Cu: goto label_80160B1C;
    case 0x80160B20u: goto label_80160B20;
    case 0x80160B24u: goto label_80160B24;
    case 0x80160B28u: goto label_80160B28;
    case 0x80160B2Cu: goto label_80160B2C;
    case 0x80160B30u: goto label_80160B30;
    case 0x80160B34u: goto label_80160B34;
    case 0x80160B38u: goto label_80160B38;
    case 0x80160B3Cu: goto label_80160B3C;
    case 0x80160B40u: goto label_80160B40;
    case 0x80160B44u: goto label_80160B44;
    case 0x80160B48u: goto label_80160B48;
    case 0x80160B4Cu: goto label_80160B4C;
    case 0x80160B50u: goto label_80160B50;
    case 0x80160B54u: goto label_80160B54;
    case 0x80160B58u: goto label_80160B58;
    case 0x80160B5Cu: goto label_80160B5C;
    case 0x80160B60u: goto label_80160B60;
    case 0x80160B64u: goto label_80160B64;
    case 0x80160B68u: goto label_80160B68;
    case 0x80160B6Cu: goto label_80160B6C;
    case 0x80160B70u: goto label_80160B70;
    case 0x80160B74u: goto label_80160B74;
    case 0x80160B78u: goto label_80160B78;
    case 0x80160B7Cu: goto label_80160B7C;
    case 0x80160B80u: goto label_80160B80;
    case 0x80160B84u: goto label_80160B84;
    case 0x80160B88u: goto label_80160B88;
    case 0x80160B8Cu: goto label_80160B8C;
    case 0x80160B90u: goto label_80160B90;
    case 0x80160B94u: goto label_80160B94;
    case 0x80160B98u: goto label_80160B98;
    case 0x80160B9Cu: goto label_80160B9C;
    case 0x80160BA0u: goto label_80160BA0;
    case 0x80160BA4u: goto label_80160BA4;
    case 0x80160BA8u: goto label_80160BA8;
    case 0x80160BACu: goto label_80160BAC;
    case 0x80160BB0u: goto label_80160BB0;
    case 0x80160BB4u: goto label_80160BB4;
    case 0x80160BB8u: goto label_80160BB8;
    case 0x80160BBCu: goto label_80160BBC;
    case 0x80160BC0u: goto label_80160BC0;
    case 0x80160BC4u: goto label_80160BC4;
    case 0x80160BC8u: goto label_80160BC8;
    case 0x80160BCCu: goto label_80160BCC;
    case 0x80160BD0u: goto label_80160BD0;
    case 0x80160BD4u: goto label_80160BD4;
    case 0x80160BD8u: goto label_80160BD8;
    case 0x80160BDCu: goto label_80160BDC;
    case 0x80160BE0u: goto label_80160BE0;
    case 0x80160BE4u: goto label_80160BE4;
    case 0x80160BE8u: goto label_80160BE8;
    case 0x80160BECu: goto label_80160BEC;
    case 0x80160BF0u: goto label_80160BF0;
    case 0x80160BF4u: goto label_80160BF4;
    case 0x80160BF8u: goto label_80160BF8;
    case 0x80160BFCu: goto label_80160BFC;
    case 0x80160C00u: goto label_80160C00;
    case 0x80160C04u: goto label_80160C04;
    case 0x80160C08u: goto label_80160C08;
    case 0x80160C0Cu: goto label_80160C0C;
    case 0x80160C10u: goto label_80160C10;
    case 0x80160C14u: goto label_80160C14;
    case 0x80160C18u: goto label_80160C18;
    case 0x80160C1Cu: goto label_80160C1C;
    case 0x80160C20u: goto label_80160C20;
    case 0x80160C24u: goto label_80160C24;
    case 0x80160C28u: goto label_80160C28;
    case 0x80160C2Cu: goto label_80160C2C;
    case 0x80160C30u: goto label_80160C30;
    case 0x80160C34u: goto label_80160C34;
    case 0x80160C38u: goto label_80160C38;
    case 0x80160C3Cu: goto label_80160C3C;
    case 0x80160C40u: goto label_80160C40;
    case 0x80160C44u: goto label_80160C44;
    case 0x80160C48u: goto label_80160C48;
    case 0x80160C4Cu: goto label_80160C4C;
    case 0x80160C50u: goto label_80160C50;
    case 0x80160C54u: goto label_80160C54;
    case 0x80160C58u: goto label_80160C58;
    case 0x80160C5Cu: goto label_80160C5C;
    case 0x80160C60u: goto label_80160C60;
    case 0x80160C64u: goto label_80160C64;
    case 0x80160C68u: goto label_80160C68;
    case 0x80160C6Cu: goto label_80160C6C;
    case 0x80160C70u: goto label_80160C70;
    case 0x80160C74u: goto label_80160C74;
    case 0x80160C78u: goto label_80160C78;
    case 0x80160C7Cu: goto label_80160C7C;
    case 0x80160C80u: goto label_80160C80;
    case 0x80160C84u: goto label_80160C84;
    case 0x80160C88u: goto label_80160C88;
    case 0x80160C8Cu: goto label_80160C8C;
    case 0x80160C90u: goto label_80160C90;
    case 0x80160C94u: goto label_80160C94;
    case 0x80160C98u: goto label_80160C98;
    case 0x80160C9Cu: goto label_80160C9C;
    case 0x80160CA0u: goto label_80160CA0;
    case 0x80160CA4u: goto label_80160CA4;
    case 0x80160CA8u: goto label_80160CA8;
    case 0x80160CACu: goto label_80160CAC;
    case 0x80160CB0u: goto label_80160CB0;
    case 0x80160CB4u: goto label_80160CB4;
    case 0x80160CB8u: goto label_80160CB8;
    case 0x80160CBCu: goto label_80160CBC;
    case 0x80160CC0u: goto label_80160CC0;
    case 0x80160CC4u: goto label_80160CC4;
    case 0x80160CC8u: goto label_80160CC8;
    case 0x80160CCCu: goto label_80160CCC;
    case 0x80160CD0u: goto label_80160CD0;
    case 0x80160CD4u: goto label_80160CD4;
    case 0x80160CD8u: goto label_80160CD8;
    case 0x80160CDCu: goto label_80160CDC;
    case 0x80160CE0u: goto label_80160CE0;
    case 0x80160CE4u: goto label_80160CE4;
    case 0x80160CE8u: goto label_80160CE8;
    case 0x80160CECu: goto label_80160CEC;
    case 0x80160CF0u: goto label_80160CF0;
    case 0x80160CF4u: goto label_80160CF4;
    case 0x80160CF8u: goto label_80160CF8;
    case 0x80160CFCu: goto label_80160CFC;
    case 0x80160D00u: goto label_80160D00;
    case 0x80160D04u: goto label_80160D04;
    case 0x80160D08u: goto label_80160D08;
    case 0x80160D0Cu: goto label_80160D0C;
    case 0x80160D10u: goto label_80160D10;
    case 0x80160D14u: goto label_80160D14;
    case 0x80160D18u: goto label_80160D18;
    case 0x80160D1Cu: goto label_80160D1C;
    case 0x80160D20u: goto label_80160D20;
    case 0x80160D24u: goto label_80160D24;
    case 0x80160D28u: goto label_80160D28;
    case 0x80160D2Cu: goto label_80160D2C;
    case 0x80160D30u: goto label_80160D30;
    case 0x80160D34u: goto label_80160D34;
    case 0x80160D38u: goto label_80160D38;
    case 0x80160D3Cu: goto label_80160D3C;
    case 0x80160D40u: goto label_80160D40;
    case 0x80160D44u: goto label_80160D44;
    case 0x80160D48u: goto label_80160D48;
    case 0x80160D4Cu: goto label_80160D4C;
    case 0x80160D50u: goto label_80160D50;
    case 0x80160D54u: goto label_80160D54;
    case 0x80160D58u: goto label_80160D58;
    case 0x80160D5Cu: goto label_80160D5C;
    case 0x80160D60u: goto label_80160D60;
    case 0x80160D64u: goto label_80160D64;
    case 0x80160D68u: goto label_80160D68;
    case 0x80160D6Cu: goto label_80160D6C;
    case 0x80160D70u: goto label_80160D70;
    case 0x80160D74u: goto label_80160D74;
    case 0x80160D78u: goto label_80160D78;
    case 0x80160D7Cu: goto label_80160D7C;
    case 0x80160D80u: goto label_80160D80;
    case 0x80160D84u: goto label_80160D84;
    case 0x80160D88u: goto label_80160D88;
    case 0x80160D8Cu: goto label_80160D8C;
    case 0x80160D90u: goto label_80160D90;
    case 0x80160D94u: goto label_80160D94;
    case 0x80160D98u: goto label_80160D98;
    case 0x80160D9Cu: goto label_80160D9C;
    case 0x80160DA0u: goto label_80160DA0;
    case 0x80160DA4u: goto label_80160DA4;
    case 0x80160DA8u: goto label_80160DA8;
    case 0x80160DACu: goto label_80160DAC;
    case 0x80160DB0u: goto label_80160DB0;
    case 0x80160DB4u: goto label_80160DB4;
    case 0x80160DB8u: goto label_80160DB8;
    case 0x80160DBCu: goto label_80160DBC;
    case 0x80160DC0u: goto label_80160DC0;
    case 0x80160DC4u: goto label_80160DC4;
    case 0x80160DC8u: goto label_80160DC8;
    case 0x80160DCCu: goto label_80160DCC;
    case 0x80160DD0u: goto label_80160DD0;
    case 0x80160DD4u: goto label_80160DD4;
    case 0x80160DD8u: goto label_80160DD8;
    case 0x80160DDCu: goto label_80160DDC;
    case 0x80160DE0u: goto label_80160DE0;
    case 0x80160DE4u: goto label_80160DE4;
    case 0x80160DE8u: goto label_80160DE8;
    case 0x80160DECu: goto label_80160DEC;
    case 0x80160DF0u: goto label_80160DF0;
    case 0x80160DF4u: goto label_80160DF4;
    case 0x80160DF8u: goto label_80160DF8;
    case 0x80160DFCu: goto label_80160DFC;
    case 0x80160E00u: goto label_80160E00;
    case 0x80160E04u: goto label_80160E04;
    case 0x80160E08u: goto label_80160E08;
    case 0x80160E0Cu: goto label_80160E0C;
    case 0x80160E10u: goto label_80160E10;
    case 0x80160E14u: goto label_80160E14;
    case 0x80160E18u: goto label_80160E18;
    case 0x80160E1Cu: goto label_80160E1C;
    case 0x80160E20u: goto label_80160E20;
    case 0x80160E24u: goto label_80160E24;
    case 0x80160E28u: goto label_80160E28;
    case 0x80160E2Cu: goto label_80160E2C;
    case 0x80160E30u: goto label_80160E30;
    case 0x80160E34u: goto label_80160E34;
    case 0x80160E38u: goto label_80160E38;
    case 0x80160E3Cu: goto label_80160E3C;
    case 0x80160E40u: goto label_80160E40;
    case 0x80160E44u: goto label_80160E44;
    case 0x80160E48u: goto label_80160E48;
    case 0x80160E4Cu: goto label_80160E4C;
    case 0x80160E50u: goto label_80160E50;
    case 0x80160E54u: goto label_80160E54;
    case 0x80160E58u: goto label_80160E58;
    case 0x80160E5Cu: goto label_80160E5C;
    case 0x80160E60u: goto label_80160E60;
    case 0x80160E64u: goto label_80160E64;
    case 0x80160E68u: goto label_80160E68;
    case 0x80160E6Cu: goto label_80160E6C;
    case 0x80160E70u: goto label_80160E70;
    case 0x80160E74u: goto label_80160E74;
    case 0x80160E78u: goto label_80160E78;
    case 0x80160E7Cu: goto label_80160E7C;
    case 0x80160E80u: goto label_80160E80;
    case 0x80160E84u: goto label_80160E84;
    case 0x80160E88u: goto label_80160E88;
    case 0x80160E8Cu: goto label_80160E8C;
    case 0x80160E90u: goto label_80160E90;
    case 0x80160E94u: goto label_80160E94;
    case 0x80160E98u: goto label_80160E98;
    case 0x80160E9Cu: goto label_80160E9C;
    case 0x80160EA0u: goto label_80160EA0;
    case 0x80160EA4u: goto label_80160EA4;
    case 0x80160EA8u: goto label_80160EA8;
    case 0x80160EACu: goto label_80160EAC;
    case 0x80160EB0u: goto label_80160EB0;
    case 0x80160EB4u: goto label_80160EB4;
    case 0x80160EB8u: goto label_80160EB8;
    case 0x80160EBCu: goto label_80160EBC;
    case 0x80160EC0u: goto label_80160EC0;
    case 0x80160EC4u: goto label_80160EC4;
    case 0x80160EC8u: goto label_80160EC8;
    case 0x80160ECCu: goto label_80160ECC;
    case 0x80160ED0u: goto label_80160ED0;
    case 0x80160ED4u: goto label_80160ED4;
    case 0x80160ED8u: goto label_80160ED8;
    case 0x80160EDCu: goto label_80160EDC;
    case 0x80160EE0u: goto label_80160EE0;
    case 0x80160EE4u: goto label_80160EE4;
    case 0x80160EE8u: goto label_80160EE8;
    case 0x80160EECu: goto label_80160EEC;
    case 0x80160EF0u: goto label_80160EF0;
    case 0x80160EF4u: goto label_80160EF4;
    case 0x80160EF8u: goto label_80160EF8;
    case 0x80160EFCu: goto label_80160EFC;
    case 0x80160F00u: goto label_80160F00;
    case 0x80160F04u: goto label_80160F04;
    case 0x80160F08u: goto label_80160F08;
    case 0x80160F0Cu: goto label_80160F0C;
    case 0x80160F10u: goto label_80160F10;
    case 0x80160F14u: goto label_80160F14;
    case 0x80160F18u: goto label_80160F18;
    case 0x80160F1Cu: goto label_80160F1C;
    case 0x80160F20u: goto label_80160F20;
    case 0x80160F24u: goto label_80160F24;
    case 0x80160F28u: goto label_80160F28;
    case 0x80160F2Cu: goto label_80160F2C;
    case 0x80160F30u: goto label_80160F30;
    case 0x80160F34u: goto label_80160F34;
    case 0x80160F38u: goto label_80160F38;
    case 0x80160F3Cu: goto label_80160F3C;
    case 0x80160F40u: goto label_80160F40;
    case 0x80160F44u: goto label_80160F44;
    case 0x80160F48u: goto label_80160F48;
    case 0x80160F4Cu: goto label_80160F4C;
    case 0x80160F50u: goto label_80160F50;
    case 0x80160F54u: goto label_80160F54;
    case 0x80160F58u: goto label_80160F58;
    case 0x80160F5Cu: goto label_80160F5C;
    case 0x80160F60u: goto label_80160F60;
    case 0x80160F64u: goto label_80160F64;
    case 0x80160F68u: goto label_80160F68;
    case 0x80160F6Cu: goto label_80160F6C;
    case 0x80160F70u: goto label_80160F70;
    case 0x80160F74u: goto label_80160F74;
    case 0x80160F78u: goto label_80160F78;
    case 0x80160F7Cu: goto label_80160F7C;
    case 0x80160F80u: goto label_80160F80;
    case 0x80160F84u: goto label_80160F84;
    case 0x80160F88u: goto label_80160F88;
    case 0x80160F8Cu: goto label_80160F8C;
    case 0x80160F90u: goto label_80160F90;
    case 0x80160F94u: goto label_80160F94;
    case 0x80160F98u: goto label_80160F98;
    case 0x80160F9Cu: goto label_80160F9C;
    case 0x80160FA0u: goto label_80160FA0;
    case 0x80160FA4u: goto label_80160FA4;
    case 0x80160FA8u: goto label_80160FA8;
    case 0x80160FACu: goto label_80160FAC;
    case 0x80160FB0u: goto label_80160FB0;
    case 0x80160FB4u: goto label_80160FB4;
    case 0x80160FB8u: goto label_80160FB8;
    case 0x80160FBCu: goto label_80160FBC;
    case 0x80160FC0u: goto label_80160FC0;
    case 0x80160FC4u: goto label_80160FC4;
    case 0x80160FC8u: goto label_80160FC8;
    case 0x80160FCCu: goto label_80160FCC;
    case 0x80160FD0u: goto label_80160FD0;
    case 0x80160FD4u: goto label_80160FD4;
    case 0x80160FD8u: goto label_80160FD8;
    case 0x80160FDCu: goto label_80160FDC;
    case 0x80160FE0u: goto label_80160FE0;
    case 0x80160FE4u: goto label_80160FE4;
    case 0x80160FE8u: goto label_80160FE8;
    case 0x80160FECu: goto label_80160FEC;
    case 0x80160FF0u: goto label_80160FF0;
    case 0x80160FF4u: goto label_80160FF4;
    case 0x80160FF8u: goto label_80160FF8;
    case 0x80160FFCu: goto label_80160FFC;
    case 0x80161000u: goto label_80161000;
    case 0x80161004u: goto label_80161004;
    case 0x80161008u: goto label_80161008;
    case 0x8016100Cu: goto label_8016100C;
    case 0x80161010u: goto label_80161010;
    case 0x80161014u: goto label_80161014;
    case 0x80161018u: goto label_80161018;
    case 0x8016101Cu: goto label_8016101C;
    case 0x80161020u: goto label_80161020;
    case 0x80161024u: goto label_80161024;
    case 0x80161028u: goto label_80161028;
    case 0x8016102Cu: goto label_8016102C;
    case 0x80161030u: goto label_80161030;
    case 0x80161034u: goto label_80161034;
    case 0x80161038u: goto label_80161038;
    case 0x8016103Cu: goto label_8016103C;
    case 0x80161040u: goto label_80161040;
    case 0x80161044u: goto label_80161044;
    case 0x80161048u: goto label_80161048;
    case 0x8016104Cu: goto label_8016104C;
    case 0x80161050u: goto label_80161050;
    case 0x80161054u: goto label_80161054;
    case 0x80161058u: goto label_80161058;
    case 0x8016105Cu: goto label_8016105C;
    case 0x80161060u: goto label_80161060;
    case 0x80161064u: goto label_80161064;
    case 0x80161068u: goto label_80161068;
    case 0x8016106Cu: goto label_8016106C;
    case 0x80161070u: goto label_80161070;
    case 0x80161074u: goto label_80161074;
    case 0x80161078u: goto label_80161078;
    case 0x8016107Cu: goto label_8016107C;
    case 0x80161080u: goto label_80161080;
    case 0x80161084u: goto label_80161084;
    case 0x80161088u: goto label_80161088;
    case 0x8016108Cu: goto label_8016108C;
    case 0x80161090u: goto label_80161090;
    case 0x80161094u: goto label_80161094;
    case 0x80161098u: goto label_80161098;
    case 0x8016109Cu: goto label_8016109C;
    case 0x801610A0u: goto label_801610A0;
    case 0x801610A4u: goto label_801610A4;
    case 0x801610A8u: goto label_801610A8;
    case 0x801610ACu: goto label_801610AC;
    case 0x801610B0u: goto label_801610B0;
    case 0x801610B4u: goto label_801610B4;
    case 0x801610B8u: goto label_801610B8;
    case 0x801610BCu: goto label_801610BC;
    case 0x801610C0u: goto label_801610C0;
    case 0x801610C4u: goto label_801610C4;
    case 0x801610C8u: goto label_801610C8;
    case 0x801610CCu: goto label_801610CC;
    case 0x801610D0u: goto label_801610D0;
    case 0x801610D4u: goto label_801610D4;
    case 0x801610D8u: goto label_801610D8;
    case 0x801610DCu: goto label_801610DC;
    case 0x801610E0u: goto label_801610E0;
    case 0x801610E4u: goto label_801610E4;
    case 0x801610E8u: goto label_801610E8;
    case 0x801610ECu: goto label_801610EC;
    case 0x801610F0u: goto label_801610F0;
    case 0x801610F4u: goto label_801610F4;
    case 0x801610F8u: goto label_801610F8;
    case 0x801610FCu: goto label_801610FC;
    case 0x80161100u: goto label_80161100;
    case 0x80161104u: goto label_80161104;
    case 0x80161108u: goto label_80161108;
    case 0x8016110Cu: goto label_8016110C;
    case 0x80161110u: goto label_80161110;
    case 0x80161114u: goto label_80161114;
    case 0x80161118u: goto label_80161118;
    case 0x8016111Cu: goto label_8016111C;
    case 0x80161120u: goto label_80161120;
    case 0x80161124u: goto label_80161124;
    case 0x80161128u: goto label_80161128;
    case 0x8016112Cu: goto label_8016112C;
    case 0x80161130u: goto label_80161130;
    case 0x80161134u: goto label_80161134;
    case 0x80161138u: goto label_80161138;
    case 0x8016113Cu: goto label_8016113C;
    case 0x80161140u: goto label_80161140;
    case 0x80161144u: goto label_80161144;
    case 0x80161148u: goto label_80161148;
    case 0x8016114Cu: goto label_8016114C;
    case 0x80161150u: goto label_80161150;
    case 0x80161154u: goto label_80161154;
    case 0x80161158u: goto label_80161158;
    case 0x8016115Cu: goto label_8016115C;
    case 0x80161160u: goto label_80161160;
    case 0x80161164u: goto label_80161164;
    case 0x80161168u: goto label_80161168;
    case 0x8016116Cu: goto label_8016116C;
    case 0x80161170u: goto label_80161170;
    case 0x80161174u: goto label_80161174;
    case 0x80161178u: goto label_80161178;
    case 0x8016117Cu: goto label_8016117C;
    case 0x80161180u: goto label_80161180;
    case 0x80161184u: goto label_80161184;
    case 0x80161188u: goto label_80161188;
    case 0x8016118Cu: goto label_8016118C;
    case 0x80161190u: goto label_80161190;
    case 0x80161194u: goto label_80161194;
    case 0x80161198u: goto label_80161198;
    case 0x8016119Cu: goto label_8016119C;
    case 0x801611A0u: goto label_801611A0;
    case 0x801611A4u: goto label_801611A4;
    case 0x801611A8u: goto label_801611A8;
    case 0x801611ACu: goto label_801611AC;
    case 0x801611B0u: goto label_801611B0;
    case 0x801611B4u: goto label_801611B4;
    case 0x801611B8u: goto label_801611B8;
    case 0x801611BCu: goto label_801611BC;
    case 0x801611C0u: goto label_801611C0;
    case 0x801611C4u: goto label_801611C4;
    case 0x801611C8u: goto label_801611C8;
    case 0x801611CCu: goto label_801611CC;
    case 0x801611D0u: goto label_801611D0;
    case 0x801611D4u: goto label_801611D4;
    case 0x801611D8u: goto label_801611D8;
    case 0x801611DCu: goto label_801611DC;
    case 0x801611E0u: goto label_801611E0;
    case 0x801611E4u: goto label_801611E4;
    case 0x801611E8u: goto label_801611E8;
    case 0x801611ECu: goto label_801611EC;
    case 0x801611F0u: goto label_801611F0;
    case 0x801611F4u: goto label_801611F4;
    case 0x801611F8u: goto label_801611F8;
    case 0x801611FCu: goto label_801611FC;
    case 0x80161200u: goto label_80161200;
    case 0x80161204u: goto label_80161204;
    case 0x80161208u: goto label_80161208;
    case 0x8016120Cu: goto label_8016120C;
    case 0x80161210u: goto label_80161210;
    case 0x80161214u: goto label_80161214;
    case 0x80161218u: goto label_80161218;
    case 0x8016121Cu: goto label_8016121C;
    case 0x80161220u: goto label_80161220;
    case 0x80161224u: goto label_80161224;
    case 0x80161228u: goto label_80161228;
    case 0x8016122Cu: goto label_8016122C;
    case 0x80161230u: goto label_80161230;
    case 0x80161234u: goto label_80161234;
    case 0x80161238u: goto label_80161238;
    case 0x8016123Cu: goto label_8016123C;
    case 0x80161240u: goto label_80161240;
    case 0x80161244u: goto label_80161244;
    case 0x80161248u: goto label_80161248;
    case 0x8016124Cu: goto label_8016124C;
    case 0x80161250u: goto label_80161250;
    case 0x80161254u: goto label_80161254;
    case 0x80161258u: goto label_80161258;
    case 0x8016125Cu: goto label_8016125C;
    case 0x80161260u: goto label_80161260;
    case 0x80161264u: goto label_80161264;
    case 0x80161268u: goto label_80161268;
    case 0x8016126Cu: goto label_8016126C;
    case 0x80161270u: goto label_80161270;
    case 0x80161274u: goto label_80161274;
    case 0x80161278u: goto label_80161278;
    case 0x8016127Cu: goto label_8016127C;
    case 0x80161280u: goto label_80161280;
    case 0x80161284u: goto label_80161284;
    case 0x80161288u: goto label_80161288;
    case 0x8016128Cu: goto label_8016128C;
    case 0x80161290u: goto label_80161290;
    case 0x80161294u: goto label_80161294;
    case 0x80161298u: goto label_80161298;
    case 0x8016129Cu: goto label_8016129C;
    case 0x801612A0u: goto label_801612A0;
    case 0x801612A4u: goto label_801612A4;
    case 0x801612A8u: goto label_801612A8;
    case 0x801612ACu: goto label_801612AC;
    case 0x801612B0u: goto label_801612B0;
    case 0x801612B4u: goto label_801612B4;
    case 0x801612B8u: goto label_801612B8;
    case 0x801612BCu: goto label_801612BC;
    case 0x801612C0u: goto label_801612C0;
    case 0x801612C4u: goto label_801612C4;
    case 0x801612C8u: goto label_801612C8;
    case 0x801612CCu: goto label_801612CC;
    case 0x801612D0u: goto label_801612D0;
    case 0x801612D4u: goto label_801612D4;
    case 0x801612D8u: goto label_801612D8;
    case 0x801612DCu: goto label_801612DC;
    case 0x801612E0u: goto label_801612E0;
    case 0x801612E4u: goto label_801612E4;
    case 0x801612E8u: goto label_801612E8;
    case 0x801612ECu: goto label_801612EC;
    case 0x801612F0u: goto label_801612F0;
    case 0x801612F4u: goto label_801612F4;
    case 0x801612F8u: goto label_801612F8;
    case 0x801612FCu: goto label_801612FC;
    case 0x80161300u: goto label_80161300;
    case 0x80161304u: goto label_80161304;
    case 0x80161308u: goto label_80161308;
    case 0x8016130Cu: goto label_8016130C;
    case 0x80161310u: goto label_80161310;
    case 0x80161314u: goto label_80161314;
    case 0x80161318u: goto label_80161318;
    case 0x8016131Cu: goto label_8016131C;
    case 0x80161320u: goto label_80161320;
    case 0x80161324u: goto label_80161324;
    case 0x80161328u: goto label_80161328;
    case 0x8016132Cu: goto label_8016132C;
    case 0x80161330u: goto label_80161330;
    case 0x80161334u: goto label_80161334;
    case 0x80161338u: goto label_80161338;
    case 0x8016133Cu: goto label_8016133C;
    case 0x80161340u: goto label_80161340;
    case 0x80161344u: goto label_80161344;
    case 0x80161348u: goto label_80161348;
    case 0x8016134Cu: goto label_8016134C;
    case 0x80161350u: goto label_80161350;
    case 0x80161354u: goto label_80161354;
    case 0x80161358u: goto label_80161358;
    case 0x8016135Cu: goto label_8016135C;
    case 0x80161360u: goto label_80161360;
    case 0x80161364u: goto label_80161364;
    case 0x80161368u: goto label_80161368;
    case 0x8016136Cu: goto label_8016136C;
    case 0x80161370u: goto label_80161370;
    case 0x80161374u: goto label_80161374;
    case 0x80161378u: goto label_80161378;
    case 0x8016137Cu: goto label_8016137C;
    case 0x80161380u: goto label_80161380;
    case 0x80161384u: goto label_80161384;
    case 0x80161388u: goto label_80161388;
    case 0x8016138Cu: goto label_8016138C;
    case 0x80161390u: goto label_80161390;
    case 0x80161394u: goto label_80161394;
    case 0x80161398u: goto label_80161398;
    case 0x8016139Cu: goto label_8016139C;
    case 0x801613A0u: goto label_801613A0;
    case 0x801613A4u: goto label_801613A4;
    case 0x801613A8u: goto label_801613A8;
    case 0x801613ACu: goto label_801613AC;
    case 0x801613B0u: goto label_801613B0;
    case 0x801613B4u: goto label_801613B4;
    case 0x801613B8u: goto label_801613B8;
    case 0x801613BCu: goto label_801613BC;
    case 0x801613C0u: goto label_801613C0;
    case 0x801613C4u: goto label_801613C4;
    case 0x801613C8u: goto label_801613C8;
    case 0x801613CCu: goto label_801613CC;
    case 0x801613D0u: goto label_801613D0;
    case 0x801613D4u: goto label_801613D4;
    case 0x801613D8u: goto label_801613D8;
    case 0x801613DCu: goto label_801613DC;
    case 0x801613E0u: goto label_801613E0;
    case 0x801613E4u: goto label_801613E4;
    case 0x801613E8u: goto label_801613E8;
    case 0x801613ECu: goto label_801613EC;
    case 0x801613F0u: goto label_801613F0;
    case 0x801613F4u: goto label_801613F4;
    case 0x801613F8u: goto label_801613F8;
    case 0x801613FCu: goto label_801613FC;
    case 0x80161400u: goto label_80161400;
    case 0x80161404u: goto label_80161404;
    case 0x80161408u: goto label_80161408;
    case 0x8016140Cu: goto label_8016140C;
    case 0x80161410u: goto label_80161410;
    case 0x80161414u: goto label_80161414;
    case 0x80161418u: goto label_80161418;
    case 0x8016141Cu: goto label_8016141C;
    case 0x80161420u: goto label_80161420;
    case 0x80161424u: goto label_80161424;
    case 0x80161428u: goto label_80161428;
    case 0x8016142Cu: goto label_8016142C;
    case 0x80161430u: goto label_80161430;
    case 0x80161434u: goto label_80161434;
    case 0x80161438u: goto label_80161438;
    case 0x8016143Cu: goto label_8016143C;
    case 0x80161440u: goto label_80161440;
    case 0x80161444u: goto label_80161444;
    case 0x80161448u: goto label_80161448;
    case 0x8016144Cu: goto label_8016144C;
    case 0x80161450u: goto label_80161450;
    case 0x80161454u: goto label_80161454;
    case 0x80161458u: goto label_80161458;
    case 0x8016145Cu: goto label_8016145C;
    case 0x80161460u: goto label_80161460;
    case 0x80161464u: goto label_80161464;
    case 0x80161468u: goto label_80161468;
    case 0x8016146Cu: goto label_8016146C;
    case 0x80161470u: goto label_80161470;
    case 0x80161474u: goto label_80161474;
    case 0x80161478u: goto label_80161478;
    case 0x8016147Cu: goto label_8016147C;
    case 0x80161480u: goto label_80161480;
    case 0x80161484u: goto label_80161484;
    case 0x80161488u: goto label_80161488;
    case 0x8016148Cu: goto label_8016148C;
    case 0x80161490u: goto label_80161490;
    case 0x80161494u: goto label_80161494;
    case 0x80161498u: goto label_80161498;
    case 0x8016149Cu: goto label_8016149C;
    case 0x801614A0u: goto label_801614A0;
    case 0x801614A4u: goto label_801614A4;
    case 0x801614A8u: goto label_801614A8;
    case 0x801614ACu: goto label_801614AC;
    case 0x801614B0u: goto label_801614B0;
    case 0x801614B4u: goto label_801614B4;
    case 0x801614B8u: goto label_801614B8;
    case 0x801614BCu: goto label_801614BC;
    case 0x801614C0u: goto label_801614C0;
    case 0x801614C4u: goto label_801614C4;
    case 0x801614C8u: goto label_801614C8;
    case 0x801614CCu: goto label_801614CC;
    case 0x801614D0u: goto label_801614D0;
    case 0x801614D4u: goto label_801614D4;
    case 0x801614D8u: goto label_801614D8;
    case 0x801614DCu: goto label_801614DC;
    case 0x801614E0u: goto label_801614E0;
    case 0x801614E4u: goto label_801614E4;
    case 0x801614E8u: goto label_801614E8;
    case 0x801614ECu: goto label_801614EC;
    case 0x801614F0u: goto label_801614F0;
    case 0x801614F4u: goto label_801614F4;
    case 0x801614F8u: goto label_801614F8;
    case 0x801614FCu: goto label_801614FC;
    case 0x80161500u: goto label_80161500;
    case 0x80161504u: goto label_80161504;
    case 0x80161508u: goto label_80161508;
    case 0x8016150Cu: goto label_8016150C;
    case 0x80161510u: goto label_80161510;
    case 0x80161514u: goto label_80161514;
    case 0x80161518u: goto label_80161518;
    case 0x8016151Cu: goto label_8016151C;
    case 0x80161520u: goto label_80161520;
    case 0x80161524u: goto label_80161524;
    case 0x80161528u: goto label_80161528;
    case 0x8016152Cu: goto label_8016152C;
    case 0x80161530u: goto label_80161530;
    case 0x80161534u: goto label_80161534;
    case 0x80161538u: goto label_80161538;
    case 0x8016153Cu: goto label_8016153C;
    case 0x80161540u: goto label_80161540;
    case 0x80161544u: goto label_80161544;
    case 0x80161548u: goto label_80161548;
    case 0x8016154Cu: goto label_8016154C;
    case 0x80161550u: goto label_80161550;
    case 0x80161554u: goto label_80161554;
    case 0x80161558u: goto label_80161558;
    case 0x8016155Cu: goto label_8016155C;
    case 0x80161560u: goto label_80161560;
    case 0x80161564u: goto label_80161564;
    case 0x80161568u: goto label_80161568;
    case 0x8016156Cu: goto label_8016156C;
    case 0x80161570u: goto label_80161570;
    case 0x80161574u: goto label_80161574;
    case 0x80161578u: goto label_80161578;
    case 0x8016157Cu: goto label_8016157C;
    case 0x80161580u: goto label_80161580;
    case 0x80161584u: goto label_80161584;
    case 0x80161588u: goto label_80161588;
    case 0x8016158Cu: goto label_8016158C;
    case 0x80161590u: goto label_80161590;
    case 0x80161594u: goto label_80161594;
    case 0x80161598u: goto label_80161598;
    case 0x8016159Cu: goto label_8016159C;
    case 0x801615A0u: goto label_801615A0;
    case 0x801615A4u: goto label_801615A4;
    case 0x801615A8u: goto label_801615A8;
    case 0x801615ACu: goto label_801615AC;
    case 0x801615B0u: goto label_801615B0;
    case 0x801615B4u: goto label_801615B4;
    case 0x801615B8u: goto label_801615B8;
    case 0x801615BCu: goto label_801615BC;
    case 0x801615C0u: goto label_801615C0;
    case 0x801615C4u: goto label_801615C4;
    case 0x801615C8u: goto label_801615C8;
    case 0x801615CCu: goto label_801615CC;
    case 0x801615D0u: goto label_801615D0;
    case 0x801615D4u: goto label_801615D4;
    case 0x801615D8u: goto label_801615D8;
    case 0x801615DCu: goto label_801615DC;
    case 0x801615E0u: goto label_801615E0;
    case 0x801615E4u: goto label_801615E4;
    case 0x801615E8u: goto label_801615E8;
    case 0x801615ECu: goto label_801615EC;
    case 0x801615F0u: goto label_801615F0;
    case 0x801615F4u: goto label_801615F4;
    case 0x801615F8u: goto label_801615F8;
    case 0x801615FCu: goto label_801615FC;
    case 0x80161600u: goto label_80161600;
    case 0x80161604u: goto label_80161604;
    case 0x80161608u: goto label_80161608;
    case 0x8016160Cu: goto label_8016160C;
    case 0x80161610u: goto label_80161610;
    case 0x80161614u: goto label_80161614;
    case 0x80161618u: goto label_80161618;
    case 0x8016161Cu: goto label_8016161C;
    case 0x80161620u: goto label_80161620;
    case 0x80161624u: goto label_80161624;
    case 0x80161628u: goto label_80161628;
    case 0x8016162Cu: goto label_8016162C;
    case 0x80161630u: goto label_80161630;
    case 0x80161634u: goto label_80161634;
    case 0x80161638u: goto label_80161638;
    case 0x8016163Cu: goto label_8016163C;
    case 0x80161640u: goto label_80161640;
    case 0x80161644u: goto label_80161644;
    case 0x80161648u: goto label_80161648;
    case 0x8016164Cu: goto label_8016164C;
    case 0x80161650u: goto label_80161650;
    case 0x80161654u: goto label_80161654;
    case 0x80161658u: goto label_80161658;
    case 0x8016165Cu: goto label_8016165C;
    case 0x80161660u: goto label_80161660;
    case 0x80161664u: goto label_80161664;
    case 0x80161668u: goto label_80161668;
    case 0x8016166Cu: goto label_8016166C;
    case 0x80161670u: goto label_80161670;
    case 0x80161674u: goto label_80161674;
    case 0x80161678u: goto label_80161678;
    case 0x8016167Cu: goto label_8016167C;
    case 0x80161680u: goto label_80161680;
    case 0x80161684u: goto label_80161684;
    case 0x80161688u: goto label_80161688;
    case 0x8016168Cu: goto label_8016168C;
    case 0x80161690u: goto label_80161690;
    case 0x80161694u: goto label_80161694;
    case 0x80161698u: goto label_80161698;
    case 0x8016169Cu: goto label_8016169C;
    case 0x801616A0u: goto label_801616A0;
    case 0x801616A4u: goto label_801616A4;
    case 0x801616A8u: goto label_801616A8;
    case 0x801616ACu: goto label_801616AC;
    case 0x801616B0u: goto label_801616B0;
    case 0x801616B4u: goto label_801616B4;
    case 0x801616B8u: goto label_801616B8;
    case 0x801616BCu: goto label_801616BC;
    case 0x801616C0u: goto label_801616C0;
    case 0x801616C4u: goto label_801616C4;
    case 0x801616C8u: goto label_801616C8;
    case 0x801616CCu: goto label_801616CC;
    case 0x801616D0u: goto label_801616D0;
    case 0x801616D4u: goto label_801616D4;
    case 0x801616D8u: goto label_801616D8;
    case 0x801616DCu: goto label_801616DC;
    case 0x801616E0u: goto label_801616E0;
    case 0x801616E4u: goto label_801616E4;
    case 0x801616E8u: goto label_801616E8;
    case 0x801616ECu: goto label_801616EC;
    case 0x801616F0u: goto label_801616F0;
    case 0x801616F4u: goto label_801616F4;
    case 0x801616F8u: goto label_801616F8;
    case 0x801616FCu: goto label_801616FC;
    case 0x80161700u: goto label_80161700;
    case 0x80161704u: goto label_80161704;
    case 0x80161708u: goto label_80161708;
    case 0x8016170Cu: goto label_8016170C;
    case 0x80161710u: goto label_80161710;
    case 0x80161714u: goto label_80161714;
    case 0x80161718u: goto label_80161718;
    case 0x8016171Cu: goto label_8016171C;
    case 0x80161720u: goto label_80161720;
    case 0x80161724u: goto label_80161724;
    case 0x80161728u: goto label_80161728;
    case 0x8016172Cu: goto label_8016172C;
    case 0x80161730u: goto label_80161730;
    case 0x80161734u: goto label_80161734;
    case 0x80161738u: goto label_80161738;
    case 0x8016173Cu: goto label_8016173C;
    case 0x80161740u: goto label_80161740;
    case 0x80161744u: goto label_80161744;
    case 0x80161748u: goto label_80161748;
    case 0x8016174Cu: goto label_8016174C;
    case 0x80161750u: goto label_80161750;
    case 0x80161754u: goto label_80161754;
    case 0x80161758u: goto label_80161758;
    case 0x8016175Cu: goto label_8016175C;
    case 0x80161760u: goto label_80161760;
    case 0x80161764u: goto label_80161764;
    case 0x80161768u: goto label_80161768;
    case 0x8016176Cu: goto label_8016176C;
    case 0x80161770u: goto label_80161770;
    case 0x80161774u: goto label_80161774;
    case 0x80161778u: goto label_80161778;
    case 0x8016177Cu: goto label_8016177C;
    case 0x80161780u: goto label_80161780;
    case 0x80161784u: goto label_80161784;
    case 0x80161788u: goto label_80161788;
    case 0x8016178Cu: goto label_8016178C;
    case 0x80161790u: goto label_80161790;
    case 0x80161794u: goto label_80161794;
    case 0x80161798u: goto label_80161798;
    case 0x8016179Cu: goto label_8016179C;
    case 0x801617A0u: goto label_801617A0;
    case 0x801617A4u: goto label_801617A4;
    case 0x801617A8u: goto label_801617A8;
    case 0x801617ACu: goto label_801617AC;
    case 0x801617B0u: goto label_801617B0;
    case 0x801617B4u: goto label_801617B4;
    case 0x801617B8u: goto label_801617B8;
    case 0x801617BCu: goto label_801617BC;
    case 0x801617C0u: goto label_801617C0;
    case 0x801617C4u: goto label_801617C4;
    case 0x801617C8u: goto label_801617C8;
    case 0x801617CCu: goto label_801617CC;
    case 0x801617D0u: goto label_801617D0;
    case 0x801617D4u: goto label_801617D4;
    case 0x801617D8u: goto label_801617D8;
    case 0x801617DCu: goto label_801617DC;
    case 0x801617E0u: goto label_801617E0;
    case 0x801617E4u: goto label_801617E4;
    case 0x801617E8u: goto label_801617E8;
    case 0x801617ECu: goto label_801617EC;
    case 0x801617F0u: goto label_801617F0;
    case 0x801617F4u: goto label_801617F4;
    case 0x801617F8u: goto label_801617F8;
    case 0x801617FCu: goto label_801617FC;
    case 0x80161800u: goto label_80161800;
    case 0x80161804u: goto label_80161804;
    case 0x80161808u: goto label_80161808;
    case 0x8016180Cu: goto label_8016180C;
    case 0x80161810u: goto label_80161810;
    case 0x80161814u: goto label_80161814;
    case 0x80161818u: goto label_80161818;
    case 0x8016181Cu: goto label_8016181C;
    case 0x80161820u: goto label_80161820;
    case 0x80161824u: goto label_80161824;
    case 0x80161828u: goto label_80161828;
    case 0x8016182Cu: goto label_8016182C;
    case 0x80161830u: goto label_80161830;
    case 0x80161834u: goto label_80161834;
    case 0x80161838u: goto label_80161838;
    case 0x8016183Cu: goto label_8016183C;
    case 0x80161840u: goto label_80161840;
    case 0x80161844u: goto label_80161844;
    case 0x80161848u: goto label_80161848;
    case 0x8016184Cu: goto label_8016184C;
    case 0x80161850u: goto label_80161850;
    case 0x80161854u: goto label_80161854;
    case 0x80161858u: goto label_80161858;
    case 0x8016185Cu: goto label_8016185C;
    case 0x80161860u: goto label_80161860;
    case 0x80161864u: goto label_80161864;
    case 0x80161868u: goto label_80161868;
    case 0x8016186Cu: goto label_8016186C;
    case 0x80161870u: goto label_80161870;
    case 0x80161874u: goto label_80161874;
    case 0x80161878u: goto label_80161878;
    case 0x8016187Cu: goto label_8016187C;
    case 0x80161880u: goto label_80161880;
    case 0x80161884u: goto label_80161884;
    case 0x80161888u: goto label_80161888;
    case 0x8016188Cu: goto label_8016188C;
    case 0x80161890u: goto label_80161890;
    case 0x80161894u: goto label_80161894;
    case 0x80161898u: goto label_80161898;
    case 0x8016189Cu: goto label_8016189C;
    case 0x801618A0u: goto label_801618A0;
    case 0x801618A4u: goto label_801618A4;
    case 0x801618A8u: goto label_801618A8;
    case 0x801618ACu: goto label_801618AC;
    case 0x801618B0u: goto label_801618B0;
    case 0x801618B4u: goto label_801618B4;
    case 0x801618B8u: goto label_801618B8;
    case 0x801618BCu: goto label_801618BC;
    case 0x801618C0u: goto label_801618C0;
    case 0x801618C4u: goto label_801618C4;
    case 0x801618C8u: goto label_801618C8;
    case 0x801618CCu: goto label_801618CC;
    case 0x801618D0u: goto label_801618D0;
    case 0x801618D4u: goto label_801618D4;
    case 0x801618D8u: goto label_801618D8;
    case 0x801618DCu: goto label_801618DC;
    case 0x801618E0u: goto label_801618E0;
    case 0x801618E4u: goto label_801618E4;
    case 0x801618E8u: goto label_801618E8;
    case 0x801618ECu: goto label_801618EC;
    case 0x801618F0u: goto label_801618F0;
    case 0x801618F4u: goto label_801618F4;
    case 0x801618F8u: goto label_801618F8;
    case 0x801618FCu: goto label_801618FC;
    case 0x80161900u: goto label_80161900;
    case 0x80161904u: goto label_80161904;
    case 0x80161908u: goto label_80161908;
    case 0x8016190Cu: goto label_8016190C;
    case 0x80161910u: goto label_80161910;
    case 0x80161914u: goto label_80161914;
    case 0x80161918u: goto label_80161918;
    case 0x8016191Cu: goto label_8016191C;
    case 0x80161920u: goto label_80161920;
    case 0x80161924u: goto label_80161924;
    case 0x80161928u: goto label_80161928;
    case 0x8016192Cu: goto label_8016192C;
    case 0x80161930u: goto label_80161930;
    case 0x80161934u: goto label_80161934;
    case 0x80161938u: goto label_80161938;
    case 0x8016193Cu: goto label_8016193C;
    case 0x80161940u: goto label_80161940;
    case 0x80161944u: goto label_80161944;
    case 0x80161948u: goto label_80161948;
    case 0x8016194Cu: goto label_8016194C;
    case 0x80161950u: goto label_80161950;
    case 0x80161954u: goto label_80161954;
    case 0x80161958u: goto label_80161958;
    case 0x8016195Cu: goto label_8016195C;
    case 0x80161960u: goto label_80161960;
    case 0x80161964u: goto label_80161964;
    case 0x80161968u: goto label_80161968;
    case 0x8016196Cu: goto label_8016196C;
    case 0x80161970u: goto label_80161970;
    case 0x80161974u: goto label_80161974;
    case 0x80161978u: goto label_80161978;
    case 0x8016197Cu: goto label_8016197C;
    case 0x80161980u: goto label_80161980;
    case 0x80161984u: goto label_80161984;
    case 0x80161988u: goto label_80161988;
    case 0x8016198Cu: goto label_8016198C;
    case 0x80161990u: goto label_80161990;
    case 0x80161994u: goto label_80161994;
    case 0x80161998u: goto label_80161998;
    case 0x8016199Cu: goto label_8016199C;
    case 0x801619A0u: goto label_801619A0;
    case 0x801619A4u: goto label_801619A4;
    case 0x801619A8u: goto label_801619A8;
    case 0x801619ACu: goto label_801619AC;
    case 0x801619B0u: goto label_801619B0;
    case 0x801619B4u: goto label_801619B4;
    case 0x801619B8u: goto label_801619B8;
    case 0x801619BCu: goto label_801619BC;
    case 0x801619C0u: goto label_801619C0;
    case 0x801619C4u: goto label_801619C4;
    case 0x801619C8u: goto label_801619C8;
    case 0x801619CCu: goto label_801619CC;
    case 0x801619D0u: goto label_801619D0;
    case 0x801619D4u: goto label_801619D4;
    case 0x801619D8u: goto label_801619D8;
    case 0x801619DCu: goto label_801619DC;
    case 0x801619E0u: goto label_801619E0;
    case 0x801619E4u: goto label_801619E4;
    case 0x801619E8u: goto label_801619E8;
    case 0x801619ECu: goto label_801619EC;
    case 0x801619F0u: goto label_801619F0;
    case 0x801619F4u: goto label_801619F4;
    case 0x801619F8u: goto label_801619F8;
    case 0x801619FCu: goto label_801619FC;
    case 0x80161A00u: goto label_80161A00;
    case 0x80161A04u: goto label_80161A04;
    case 0x80161A08u: goto label_80161A08;
    case 0x80161A0Cu: goto label_80161A0C;
    case 0x80161A10u: goto label_80161A10;
    case 0x80161A14u: goto label_80161A14;
    case 0x80161A18u: goto label_80161A18;
    case 0x80161A1Cu: goto label_80161A1C;
    case 0x80161A20u: goto label_80161A20;
    case 0x80161A24u: goto label_80161A24;
    case 0x80161A28u: goto label_80161A28;
    case 0x80161A2Cu: goto label_80161A2C;
    case 0x80161A30u: goto label_80161A30;
    case 0x80161A34u: goto label_80161A34;
    case 0x80161A38u: goto label_80161A38;
    case 0x80161A3Cu: goto label_80161A3C;
    case 0x80161A40u: goto label_80161A40;
    case 0x80161A44u: goto label_80161A44;
    case 0x80161A48u: goto label_80161A48;
    case 0x80161A4Cu: goto label_80161A4C;
    case 0x80161A50u: goto label_80161A50;
    case 0x80161A54u: goto label_80161A54;
    case 0x80161A58u: goto label_80161A58;
    case 0x80161A5Cu: goto label_80161A5C;
    case 0x80161A60u: goto label_80161A60;
    case 0x80161A64u: goto label_80161A64;
    case 0x80161A68u: goto label_80161A68;
    case 0x80161A6Cu: goto label_80161A6C;
    case 0x80161A70u: goto label_80161A70;
    case 0x80161A74u: goto label_80161A74;
    case 0x80161A78u: goto label_80161A78;
    case 0x80161A7Cu: goto label_80161A7C;
    case 0x80161A80u: goto label_80161A80;
    case 0x80161A84u: goto label_80161A84;
    case 0x80161A88u: goto label_80161A88;
    case 0x80161A8Cu: goto label_80161A8C;
    case 0x80161A90u: goto label_80161A90;
    case 0x80161A94u: goto label_80161A94;
    case 0x80161A98u: goto label_80161A98;
    case 0x80161A9Cu: goto label_80161A9C;
    case 0x80161AA0u: goto label_80161AA0;
    case 0x80161AA4u: goto label_80161AA4;
    case 0x80161AA8u: goto label_80161AA8;
    case 0x80161AACu: goto label_80161AAC;
    case 0x80161AB0u: goto label_80161AB0;
    case 0x80161AB4u: goto label_80161AB4;
    case 0x80161AB8u: goto label_80161AB8;
    case 0x80161ABCu: goto label_80161ABC;
    case 0x80161AC0u: goto label_80161AC0;
    case 0x80161AC4u: goto label_80161AC4;
    case 0x80161AC8u: goto label_80161AC8;
    case 0x80161ACCu: goto label_80161ACC;
    case 0x80161AD0u: goto label_80161AD0;
    case 0x80161AD4u: goto label_80161AD4;
    case 0x80161AD8u: goto label_80161AD8;
    case 0x80161ADCu: goto label_80161ADC;
    case 0x80161AE0u: goto label_80161AE0;
    case 0x80161AE4u: goto label_80161AE4;
    case 0x80161AE8u: goto label_80161AE8;
    case 0x80161AECu: goto label_80161AEC;
    case 0x80161AF0u: goto label_80161AF0;
    case 0x80161AF4u: goto label_80161AF4;
    case 0x80161AF8u: goto label_80161AF8;
    case 0x80161AFCu: goto label_80161AFC;
    case 0x80161B00u: goto label_80161B00;
    case 0x80161B04u: goto label_80161B04;
    case 0x80161B08u: goto label_80161B08;
    case 0x80161B0Cu: goto label_80161B0C;
    case 0x80161B10u: goto label_80161B10;
    case 0x80161B14u: goto label_80161B14;
    case 0x80161B18u: goto label_80161B18;
    case 0x80161B1Cu: goto label_80161B1C;
    case 0x80161B20u: goto label_80161B20;
    case 0x80161B24u: goto label_80161B24;
    case 0x80161B28u: goto label_80161B28;
    case 0x80161B2Cu: goto label_80161B2C;
    case 0x80161B30u: goto label_80161B30;
    case 0x80161B34u: goto label_80161B34;
    case 0x80161B38u: goto label_80161B38;
    case 0x80161B3Cu: goto label_80161B3C;
    case 0x80161B40u: goto label_80161B40;
    case 0x80161B44u: goto label_80161B44;
    case 0x80161B48u: goto label_80161B48;
    case 0x80161B4Cu: goto label_80161B4C;
    case 0x80161B50u: goto label_80161B50;
    case 0x80161B54u: goto label_80161B54;
    case 0x80161B58u: goto label_80161B58;
    case 0x80161B5Cu: goto label_80161B5C;
    case 0x80161B60u: goto label_80161B60;
    case 0x80161B64u: goto label_80161B64;
    case 0x80161B68u: goto label_80161B68;
    case 0x80161B6Cu: goto label_80161B6C;
    case 0x80161B70u: goto label_80161B70;
    case 0x80161B74u: goto label_80161B74;
    case 0x80161B78u: goto label_80161B78;
    case 0x80161B7Cu: goto label_80161B7C;
    case 0x80161B80u: goto label_80161B80;
    case 0x80161B84u: goto label_80161B84;
    case 0x80161B88u: goto label_80161B88;
    case 0x80161B8Cu: goto label_80161B8C;
    case 0x80161B90u: goto label_80161B90;
    case 0x80161B94u: goto label_80161B94;
    case 0x80161B98u: goto label_80161B98;
    case 0x80161B9Cu: goto label_80161B9C;
    case 0x80161BA0u: goto label_80161BA0;
    case 0x80161BA4u: goto label_80161BA4;
    case 0x80161BA8u: goto label_80161BA8;
    case 0x80161BACu: goto label_80161BAC;
    case 0x80161BB0u: goto label_80161BB0;
    case 0x80161BB4u: goto label_80161BB4;
    case 0x80161BB8u: goto label_80161BB8;
    case 0x80161BBCu: goto label_80161BBC;
    case 0x80161BC0u: goto label_80161BC0;
    case 0x80161BC4u: goto label_80161BC4;
    case 0x80161BC8u: goto label_80161BC8;
    case 0x80161BCCu: goto label_80161BCC;
    case 0x80161BD0u: goto label_80161BD0;
    case 0x80161BD4u: goto label_80161BD4;
    case 0x80161BD8u: goto label_80161BD8;
    case 0x80161BDCu: goto label_80161BDC;
    case 0x80161BE0u: goto label_80161BE0;
    case 0x80161BE4u: goto label_80161BE4;
    case 0x80161BE8u: goto label_80161BE8;
    case 0x80161BECu: goto label_80161BEC;
    case 0x80161BF0u: goto label_80161BF0;
    case 0x80161BF4u: goto label_80161BF4;
    case 0x80161BF8u: goto label_80161BF8;
    case 0x80161BFCu: goto label_80161BFC;
    case 0x80161C00u: goto label_80161C00;
    case 0x80161C04u: goto label_80161C04;
    case 0x80161C08u: goto label_80161C08;
    case 0x80161C0Cu: goto label_80161C0C;
    case 0x80161C10u: goto label_80161C10;
    case 0x80161C14u: goto label_80161C14;
    case 0x80161C18u: goto label_80161C18;
    case 0x80161C1Cu: goto label_80161C1C;
    case 0x80161C20u: goto label_80161C20;
    case 0x80161C24u: goto label_80161C24;
    case 0x80161C28u: goto label_80161C28;
    case 0x80161C2Cu: goto label_80161C2C;
    case 0x80161C30u: goto label_80161C30;
    case 0x80161C34u: goto label_80161C34;
    case 0x80161C38u: goto label_80161C38;
    case 0x80161C3Cu: goto label_80161C3C;
    case 0x80161C40u: goto label_80161C40;
    case 0x80161C44u: goto label_80161C44;
    case 0x80161C48u: goto label_80161C48;
    case 0x80161C4Cu: goto label_80161C4C;
    case 0x80161C50u: goto label_80161C50;
    case 0x80161C54u: goto label_80161C54;
    case 0x80161C58u: goto label_80161C58;
    case 0x80161C5Cu: goto label_80161C5C;
    case 0x80161C60u: goto label_80161C60;
    case 0x80161C64u: goto label_80161C64;
    case 0x80161C68u: goto label_80161C68;
    case 0x80161C6Cu: goto label_80161C6C;
    case 0x80161C70u: goto label_80161C70;
    case 0x80161C74u: goto label_80161C74;
    case 0x80161C78u: goto label_80161C78;
    case 0x80161C7Cu: goto label_80161C7C;
    case 0x80161C80u: goto label_80161C80;
    case 0x80161C84u: goto label_80161C84;
    case 0x80161C88u: goto label_80161C88;
    case 0x80161C8Cu: goto label_80161C8C;
    case 0x80161C90u: goto label_80161C90;
    case 0x80161C94u: goto label_80161C94;
    case 0x80161C98u: goto label_80161C98;
    case 0x80161C9Cu: goto label_80161C9C;
    case 0x80161CA0u: goto label_80161CA0;
    case 0x80161CA4u: goto label_80161CA4;
    case 0x80161CA8u: goto label_80161CA8;
    case 0x80161CACu: goto label_80161CAC;
    case 0x80161CB0u: goto label_80161CB0;
    case 0x80161CB4u: goto label_80161CB4;
    case 0x80161CB8u: goto label_80161CB8;
    case 0x80161CBCu: goto label_80161CBC;
    case 0x80161CC0u: goto label_80161CC0;
    case 0x80161CC4u: goto label_80161CC4;
    case 0x80161CC8u: goto label_80161CC8;
    case 0x80161CCCu: goto label_80161CCC;
    case 0x80161CD0u: goto label_80161CD0;
    case 0x80161CD4u: goto label_80161CD4;
    case 0x80161CD8u: goto label_80161CD8;
    case 0x80161CDCu: goto label_80161CDC;
    case 0x80161CE0u: goto label_80161CE0;
    case 0x80161CE4u: goto label_80161CE4;
    case 0x80161CE8u: goto label_80161CE8;
    case 0x80161CECu: goto label_80161CEC;
    case 0x80161CF0u: goto label_80161CF0;
    case 0x80161CF4u: goto label_80161CF4;
    case 0x80161CF8u: goto label_80161CF8;
    case 0x80161CFCu: goto label_80161CFC;
    case 0x80161D00u: goto label_80161D00;
    case 0x80161D04u: goto label_80161D04;
    case 0x80161D08u: goto label_80161D08;
    case 0x80161D0Cu: goto label_80161D0C;
    case 0x80161D10u: goto label_80161D10;
    case 0x80161D14u: goto label_80161D14;
    case 0x80161D18u: goto label_80161D18;
    case 0x80161D1Cu: goto label_80161D1C;
    case 0x80161D20u: goto label_80161D20;
    case 0x80161D24u: goto label_80161D24;
    case 0x80161D28u: goto label_80161D28;
    case 0x80161D2Cu: goto label_80161D2C;
    case 0x80161D30u: goto label_80161D30;
    case 0x80161D34u: goto label_80161D34;
    case 0x80161D38u: goto label_80161D38;
    case 0x80161D3Cu: goto label_80161D3C;
    case 0x80161D40u: goto label_80161D40;
    case 0x80161D44u: goto label_80161D44;
    case 0x80161D48u: goto label_80161D48;
    case 0x80161D4Cu: goto label_80161D4C;
    case 0x80161D50u: goto label_80161D50;
    case 0x80161D54u: goto label_80161D54;
    case 0x80161D58u: goto label_80161D58;
    case 0x80161D5Cu: goto label_80161D5C;
    case 0x80161D60u: goto label_80161D60;
    case 0x80161D64u: goto label_80161D64;
    case 0x80161D68u: goto label_80161D68;
    case 0x80161D6Cu: goto label_80161D6C;
    case 0x80161D70u: goto label_80161D70;
    case 0x80161D74u: goto label_80161D74;
    case 0x80161D78u: goto label_80161D78;
    case 0x80161D7Cu: goto label_80161D7C;
    case 0x80161D80u: goto label_80161D80;
    case 0x80161D84u: goto label_80161D84;
    case 0x80161D88u: goto label_80161D88;
    case 0x80161D8Cu: goto label_80161D8C;
    case 0x80161D90u: goto label_80161D90;
    case 0x80161D94u: goto label_80161D94;
    case 0x80161D98u: goto label_80161D98;
    case 0x80161D9Cu: goto label_80161D9C;
    case 0x80161DA0u: goto label_80161DA0;
    case 0x80161DA4u: goto label_80161DA4;
    case 0x80161DA8u: goto label_80161DA8;
    case 0x80161DACu: goto label_80161DAC;
    case 0x80161DB0u: goto label_80161DB0;
    case 0x80161DB4u: goto label_80161DB4;
    case 0x80161DB8u: goto label_80161DB8;
    case 0x80161DBCu: goto label_80161DBC;
    case 0x80161DC0u: goto label_80161DC0;
    case 0x80161DC4u: goto label_80161DC4;
    case 0x80161DC8u: goto label_80161DC8;
    case 0x80161DCCu: goto label_80161DCC;
    case 0x80161DD0u: goto label_80161DD0;
    case 0x80161DD4u: goto label_80161DD4;
    case 0x80161DD8u: goto label_80161DD8;
    case 0x80161DDCu: goto label_80161DDC;
    case 0x80161DE0u: goto label_80161DE0;
    case 0x80161DE4u: goto label_80161DE4;
    case 0x80161DE8u: goto label_80161DE8;
    case 0x80161DECu: goto label_80161DEC;
    case 0x80161DF0u: goto label_80161DF0;
    case 0x80161DF4u: goto label_80161DF4;
    case 0x80161DF8u: goto label_80161DF8;
    case 0x80161DFCu: goto label_80161DFC;
    case 0x80161E00u: goto label_80161E00;
    case 0x80161E04u: goto label_80161E04;
    case 0x80161E08u: goto label_80161E08;
    case 0x80161E0Cu: goto label_80161E0C;
    case 0x80161E10u: goto label_80161E10;
    case 0x80161E14u: goto label_80161E14;
    case 0x80161E18u: goto label_80161E18;
    case 0x80161E1Cu: goto label_80161E1C;
    case 0x80161E20u: goto label_80161E20;
    case 0x80161E24u: goto label_80161E24;
    case 0x80161E28u: goto label_80161E28;
    case 0x80161E2Cu: goto label_80161E2C;
    case 0x80161E30u: goto label_80161E30;
    case 0x80161E34u: goto label_80161E34;
    case 0x80161E38u: goto label_80161E38;
    case 0x80161E3Cu: goto label_80161E3C;
    case 0x80161E40u: goto label_80161E40;
    case 0x80161E44u: goto label_80161E44;
    case 0x80161E48u: goto label_80161E48;
    case 0x80161E4Cu: goto label_80161E4C;
    case 0x80161E50u: goto label_80161E50;
    case 0x80161E54u: goto label_80161E54;
    case 0x80161E58u: goto label_80161E58;
    case 0x80161E5Cu: goto label_80161E5C;
    case 0x80161E60u: goto label_80161E60;
    case 0x80161E64u: goto label_80161E64;
    case 0x80161E68u: goto label_80161E68;
    case 0x80161E6Cu: goto label_80161E6C;
    case 0x80161E70u: goto label_80161E70;
    case 0x80161E74u: goto label_80161E74;
    case 0x80161E78u: goto label_80161E78;
    case 0x80161E7Cu: goto label_80161E7C;
    case 0x80161E80u: goto label_80161E80;
    case 0x80161E84u: goto label_80161E84;
    case 0x80161E88u: goto label_80161E88;
    case 0x80161E8Cu: goto label_80161E8C;
    case 0x80161E90u: goto label_80161E90;
    case 0x80161E94u: goto label_80161E94;
    case 0x80161E98u: goto label_80161E98;
    case 0x80161E9Cu: goto label_80161E9C;
    case 0x80161EA0u: goto label_80161EA0;
    case 0x80161EA4u: goto label_80161EA4;
    case 0x80161EA8u: goto label_80161EA8;
    case 0x80161EACu: goto label_80161EAC;
    case 0x80161EB0u: goto label_80161EB0;
    case 0x80161EB4u: goto label_80161EB4;
    case 0x80161EB8u: goto label_80161EB8;
    case 0x80161EBCu: goto label_80161EBC;
    case 0x80161EC0u: goto label_80161EC0;
    case 0x80161EC4u: goto label_80161EC4;
    case 0x80161EC8u: goto label_80161EC8;
    case 0x80161ECCu: goto label_80161ECC;
    case 0x80161ED0u: goto label_80161ED0;
    case 0x80161ED4u: goto label_80161ED4;
    case 0x80161ED8u: goto label_80161ED8;
    case 0x80161EDCu: goto label_80161EDC;
    case 0x80161EE0u: goto label_80161EE0;
    case 0x80161EE4u: goto label_80161EE4;
    case 0x80161EE8u: goto label_80161EE8;
    case 0x80161EECu: goto label_80161EEC;
    case 0x80161EF0u: goto label_80161EF0;
    case 0x80161EF4u: goto label_80161EF4;
    case 0x80161EF8u: goto label_80161EF8;
    case 0x80161EFCu: goto label_80161EFC;
    case 0x80161F00u: goto label_80161F00;
    case 0x80161F04u: goto label_80161F04;
    case 0x80161F08u: goto label_80161F08;
    case 0x80161F0Cu: goto label_80161F0C;
    case 0x80161F10u: goto label_80161F10;
    case 0x80161F14u: goto label_80161F14;
    case 0x80161F18u: goto label_80161F18;
    case 0x80161F1Cu: goto label_80161F1C;
    case 0x80161F20u: goto label_80161F20;
    case 0x80161F24u: goto label_80161F24;
    case 0x80161F28u: goto label_80161F28;
    case 0x80161F2Cu: goto label_80161F2C;
    case 0x80161F30u: goto label_80161F30;
    case 0x80161F34u: goto label_80161F34;
    case 0x80161F38u: goto label_80161F38;
    case 0x80161F3Cu: goto label_80161F3C;
    case 0x80161F40u: goto label_80161F40;
    case 0x80161F44u: goto label_80161F44;
    case 0x80161F48u: goto label_80161F48;
    case 0x80161F4Cu: goto label_80161F4C;
    case 0x80161F50u: goto label_80161F50;
    case 0x80161F54u: goto label_80161F54;
    case 0x80161F58u: goto label_80161F58;
    case 0x80161F5Cu: goto label_80161F5C;
    case 0x80161F60u: goto label_80161F60;
    case 0x80161F64u: goto label_80161F64;
    case 0x80161F68u: goto label_80161F68;
    case 0x80161F6Cu: goto label_80161F6C;
    case 0x80161F70u: goto label_80161F70;
    case 0x80161F74u: goto label_80161F74;
    case 0x80161F78u: goto label_80161F78;
    case 0x80161F7Cu: goto label_80161F7C;
    case 0x80161F80u: goto label_80161F80;
    case 0x80161F84u: goto label_80161F84;
    case 0x80161F88u: goto label_80161F88;
    case 0x80161F8Cu: goto label_80161F8C;
    case 0x80161F90u: goto label_80161F90;
    case 0x80161F94u: goto label_80161F94;
    case 0x80161F98u: goto label_80161F98;
    case 0x80161F9Cu: goto label_80161F9C;
    case 0x80161FA0u: goto label_80161FA0;
    case 0x80161FA4u: goto label_80161FA4;
    case 0x80161FA8u: goto label_80161FA8;
    case 0x80161FACu: goto label_80161FAC;
    case 0x80161FB0u: goto label_80161FB0;
    case 0x80161FB4u: goto label_80161FB4;
    case 0x80161FB8u: goto label_80161FB8;
    case 0x80161FBCu: goto label_80161FBC;
    case 0x80161FC0u: goto label_80161FC0;
    case 0x80161FC4u: goto label_80161FC4;
    case 0x80161FC8u: goto label_80161FC8;
    case 0x80161FCCu: goto label_80161FCC;
    case 0x80161FD0u: goto label_80161FD0;
    case 0x80161FD4u: goto label_80161FD4;
    case 0x80161FD8u: goto label_80161FD8;
    case 0x80161FDCu: goto label_80161FDC;
    case 0x80161FE0u: goto label_80161FE0;
    case 0x80161FE4u: goto label_80161FE4;
    case 0x80161FE8u: goto label_80161FE8;
    case 0x80161FECu: goto label_80161FEC;
    case 0x80161FF0u: goto label_80161FF0;
    case 0x80161FF4u: goto label_80161FF4;
    case 0x80161FF8u: goto label_80161FF8;
    case 0x80161FFCu: goto label_80161FFC;
    case 0x80162000u: goto label_80162000;
    case 0x80162004u: goto label_80162004;
    case 0x80162008u: goto label_80162008;
    case 0x8016200Cu: goto label_8016200C;
    case 0x80162010u: goto label_80162010;
    case 0x80162014u: goto label_80162014;
    case 0x80162018u: goto label_80162018;
    case 0x8016201Cu: goto label_8016201C;
    case 0x80162020u: goto label_80162020;
    case 0x80162024u: goto label_80162024;
    case 0x80162028u: goto label_80162028;
    case 0x8016202Cu: goto label_8016202C;
    case 0x80162030u: goto label_80162030;
    case 0x80162034u: goto label_80162034;
    case 0x80162038u: goto label_80162038;
    case 0x8016203Cu: goto label_8016203C;
    case 0x80162040u: goto label_80162040;
    case 0x80162044u: goto label_80162044;
    case 0x80162048u: goto label_80162048;
    case 0x8016204Cu: goto label_8016204C;
    case 0x80162050u: goto label_80162050;
    case 0x80162054u: goto label_80162054;
    case 0x80162058u: goto label_80162058;
    case 0x8016205Cu: goto label_8016205C;
    case 0x80162060u: goto label_80162060;
    case 0x80162064u: goto label_80162064;
    case 0x80162068u: goto label_80162068;
    case 0x8016206Cu: goto label_8016206C;
    case 0x80162070u: goto label_80162070;
    case 0x80162074u: goto label_80162074;
    case 0x80162078u: goto label_80162078;
    case 0x8016207Cu: goto label_8016207C;
    case 0x80162080u: goto label_80162080;
    case 0x80162084u: goto label_80162084;
    case 0x80162088u: goto label_80162088;
    case 0x8016208Cu: goto label_8016208C;
    case 0x80162090u: goto label_80162090;
    case 0x80162094u: goto label_80162094;
    case 0x80162098u: goto label_80162098;
    case 0x8016209Cu: goto label_8016209C;
    case 0x801620A0u: goto label_801620A0;
    case 0x801620A4u: goto label_801620A4;
    case 0x801620A8u: goto label_801620A8;
    case 0x801620ACu: goto label_801620AC;
    case 0x801620B0u: goto label_801620B0;
    case 0x801620B4u: goto label_801620B4;
    case 0x801620B8u: goto label_801620B8;
    case 0x801620BCu: goto label_801620BC;
    case 0x801620C0u: goto label_801620C0;
    case 0x801620C4u: goto label_801620C4;
    case 0x801620C8u: goto label_801620C8;
    case 0x801620CCu: goto label_801620CC;
    case 0x801620D0u: goto label_801620D0;
    case 0x801620D4u: goto label_801620D4;
    case 0x801620D8u: goto label_801620D8;
    case 0x801620DCu: goto label_801620DC;
    case 0x801620E0u: goto label_801620E0;
    case 0x801620E4u: goto label_801620E4;
    case 0x801620E8u: goto label_801620E8;
    case 0x801620ECu: goto label_801620EC;
    case 0x801620F0u: goto label_801620F0;
    case 0x801620F4u: goto label_801620F4;
    case 0x801620F8u: goto label_801620F8;
    case 0x801620FCu: goto label_801620FC;
    case 0x80162100u: goto label_80162100;
    case 0x80162104u: goto label_80162104;
    case 0x80162108u: goto label_80162108;
    case 0x8016210Cu: goto label_8016210C;
    case 0x80162110u: goto label_80162110;
    case 0x80162114u: goto label_80162114;
    case 0x80162118u: goto label_80162118;
    case 0x8016211Cu: goto label_8016211C;
    case 0x80162120u: goto label_80162120;
    case 0x80162124u: goto label_80162124;
    case 0x80162128u: goto label_80162128;
    case 0x8016212Cu: goto label_8016212C;
    case 0x80162130u: goto label_80162130;
    case 0x80162134u: goto label_80162134;
    case 0x80162138u: goto label_80162138;
    case 0x8016213Cu: goto label_8016213C;
    case 0x80162140u: goto label_80162140;
    case 0x80162144u: goto label_80162144;
    case 0x80162148u: goto label_80162148;
    case 0x8016214Cu: goto label_8016214C;
    case 0x80162150u: goto label_80162150;
    case 0x80162154u: goto label_80162154;
    case 0x80162158u: goto label_80162158;
    case 0x8016215Cu: goto label_8016215C;
    case 0x80162160u: goto label_80162160;
    case 0x80162164u: goto label_80162164;
    case 0x80162168u: goto label_80162168;
    case 0x8016216Cu: goto label_8016216C;
    case 0x80162170u: goto label_80162170;
    case 0x80162174u: goto label_80162174;
    case 0x80162178u: goto label_80162178;
    case 0x8016217Cu: goto label_8016217C;
    case 0x80162180u: goto label_80162180;
    case 0x80162184u: goto label_80162184;
    case 0x80162188u: goto label_80162188;
    case 0x8016218Cu: goto label_8016218C;
    case 0x80162190u: goto label_80162190;
    case 0x80162194u: goto label_80162194;
    case 0x80162198u: goto label_80162198;
    case 0x8016219Cu: goto label_8016219C;
    case 0x801621A0u: goto label_801621A0;
    case 0x801621A4u: goto label_801621A4;
    case 0x801621A8u: goto label_801621A8;
    case 0x801621ACu: goto label_801621AC;
    case 0x801621B0u: goto label_801621B0;
    case 0x801621B4u: goto label_801621B4;
    case 0x801621B8u: goto label_801621B8;
    case 0x801621BCu: goto label_801621BC;
    case 0x801621C0u: goto label_801621C0;
    case 0x801621C4u: goto label_801621C4;
    case 0x801621C8u: goto label_801621C8;
    case 0x801621CCu: goto label_801621CC;
    case 0x801621D0u: goto label_801621D0;
    case 0x801621D4u: goto label_801621D4;
    case 0x801621D8u: goto label_801621D8;
    case 0x801621DCu: goto label_801621DC;
    case 0x801621E0u: goto label_801621E0;
    case 0x801621E4u: goto label_801621E4;
    case 0x801621E8u: goto label_801621E8;
    case 0x801621ECu: goto label_801621EC;
    case 0x801621F0u: goto label_801621F0;
    case 0x801621F4u: goto label_801621F4;
    case 0x801621F8u: goto label_801621F8;
    case 0x801621FCu: goto label_801621FC;
    case 0x80162200u: goto label_80162200;
    case 0x80162204u: goto label_80162204;
    case 0x80162208u: goto label_80162208;
    case 0x8016220Cu: goto label_8016220C;
    case 0x80162210u: goto label_80162210;
    case 0x80162214u: goto label_80162214;
    case 0x80162218u: goto label_80162218;
    case 0x8016221Cu: goto label_8016221C;
    case 0x80162220u: goto label_80162220;
    case 0x80162224u: goto label_80162224;
    case 0x80162228u: goto label_80162228;
    case 0x8016222Cu: goto label_8016222C;
    case 0x80162230u: goto label_80162230;
    case 0x80162234u: goto label_80162234;
    case 0x80162238u: goto label_80162238;
    case 0x8016223Cu: goto label_8016223C;
    case 0x80162240u: goto label_80162240;
    case 0x80162244u: goto label_80162244;
    case 0x80162248u: goto label_80162248;
    case 0x8016224Cu: goto label_8016224C;
    case 0x80162250u: goto label_80162250;
    case 0x80162254u: goto label_80162254;
    case 0x80162258u: goto label_80162258;
    case 0x8016225Cu: goto label_8016225C;
    case 0x80162260u: goto label_80162260;
    case 0x80162264u: goto label_80162264;
    case 0x80162268u: goto label_80162268;
    case 0x8016226Cu: goto label_8016226C;
    case 0x80162270u: goto label_80162270;
    case 0x80162274u: goto label_80162274;
    case 0x80162278u: goto label_80162278;
    case 0x8016227Cu: goto label_8016227C;
    case 0x80162280u: goto label_80162280;
    case 0x80162284u: goto label_80162284;
    case 0x80162288u: goto label_80162288;
    case 0x8016228Cu: goto label_8016228C;
    case 0x80162290u: goto label_80162290;
    case 0x80162294u: goto label_80162294;
    case 0x80162298u: goto label_80162298;
    case 0x8016229Cu: goto label_8016229C;
    case 0x801622A0u: goto label_801622A0;
    case 0x801622A4u: goto label_801622A4;
    case 0x801622A8u: goto label_801622A8;
    case 0x801622ACu: goto label_801622AC;
    case 0x801622B0u: goto label_801622B0;
    case 0x801622B4u: goto label_801622B4;
    case 0x801622B8u: goto label_801622B8;
    case 0x801622BCu: goto label_801622BC;
    case 0x801622C0u: goto label_801622C0;
    case 0x801622C4u: goto label_801622C4;
    case 0x801622C8u: goto label_801622C8;
    case 0x801622CCu: goto label_801622CC;
    case 0x801622D0u: goto label_801622D0;
    case 0x801622D4u: goto label_801622D4;
    case 0x801622D8u: goto label_801622D8;
    case 0x801622DCu: goto label_801622DC;
    case 0x801622E0u: goto label_801622E0;
    case 0x801622E4u: goto label_801622E4;
    case 0x801622E8u: goto label_801622E8;
    case 0x801622ECu: goto label_801622EC;
    case 0x801622F0u: goto label_801622F0;
    case 0x801622F4u: goto label_801622F4;
    case 0x801622F8u: goto label_801622F8;
    case 0x801622FCu: goto label_801622FC;
    case 0x80162300u: goto label_80162300;
    case 0x80162304u: goto label_80162304;
    case 0x80162308u: goto label_80162308;
    case 0x8016230Cu: goto label_8016230C;
    case 0x80162310u: goto label_80162310;
    case 0x80162314u: goto label_80162314;
    case 0x80162318u: goto label_80162318;
    case 0x8016231Cu: goto label_8016231C;
    case 0x80162320u: goto label_80162320;
    case 0x80162324u: goto label_80162324;
    case 0x80162328u: goto label_80162328;
    case 0x8016232Cu: goto label_8016232C;
    case 0x80162330u: goto label_80162330;
    case 0x80162334u: goto label_80162334;
    case 0x80162338u: goto label_80162338;
    case 0x8016233Cu: goto label_8016233C;
    case 0x80162340u: goto label_80162340;
    case 0x80162344u: goto label_80162344;
    case 0x80162348u: goto label_80162348;
    case 0x8016234Cu: goto label_8016234C;
    case 0x80162350u: goto label_80162350;
    case 0x80162354u: goto label_80162354;
    case 0x80162358u: goto label_80162358;
    case 0x8016235Cu: goto label_8016235C;
    case 0x80162360u: goto label_80162360;
    case 0x80162364u: goto label_80162364;
    case 0x80162368u: goto label_80162368;
    case 0x8016236Cu: goto label_8016236C;
    case 0x80162370u: goto label_80162370;
    case 0x80162374u: goto label_80162374;
    case 0x80162378u: goto label_80162378;
    case 0x8016237Cu: goto label_8016237C;
    case 0x80162380u: goto label_80162380;
    case 0x80162384u: goto label_80162384;
    case 0x80162388u: goto label_80162388;
    case 0x8016238Cu: goto label_8016238C;
    case 0x80162390u: goto label_80162390;
    case 0x80162394u: goto label_80162394;
    case 0x80162398u: goto label_80162398;
    case 0x8016239Cu: goto label_8016239C;
    case 0x801623A0u: goto label_801623A0;
    case 0x801623A4u: goto label_801623A4;
    case 0x801623A8u: goto label_801623A8;
    case 0x801623ACu: goto label_801623AC;
    case 0x801623B0u: goto label_801623B0;
    case 0x801623B4u: goto label_801623B4;
    case 0x801623B8u: goto label_801623B8;
    case 0x801623BCu: goto label_801623BC;
    case 0x801623C0u: goto label_801623C0;
    case 0x801623C4u: goto label_801623C4;
    case 0x801623C8u: goto label_801623C8;
    case 0x801623CCu: goto label_801623CC;
    case 0x801623D0u: goto label_801623D0;
    case 0x801623D4u: goto label_801623D4;
    case 0x801623D8u: goto label_801623D8;
    case 0x801623DCu: goto label_801623DC;
    case 0x801623E0u: goto label_801623E0;
    case 0x801623E4u: goto label_801623E4;
    case 0x801623E8u: goto label_801623E8;
    case 0x801623ECu: goto label_801623EC;
    case 0x801623F0u: goto label_801623F0;
    case 0x801623F4u: goto label_801623F4;
    case 0x801623F8u: goto label_801623F8;
    case 0x801623FCu: goto label_801623FC;
    case 0x80162400u: goto label_80162400;
    case 0x80162404u: goto label_80162404;
    case 0x80162408u: goto label_80162408;
    case 0x8016240Cu: goto label_8016240C;
    case 0x80162410u: goto label_80162410;
    case 0x80162414u: goto label_80162414;
    case 0x80162418u: goto label_80162418;
    case 0x8016241Cu: goto label_8016241C;
    case 0x80162420u: goto label_80162420;
    case 0x80162424u: goto label_80162424;
    case 0x80162428u: goto label_80162428;
    case 0x8016242Cu: goto label_8016242C;
    case 0x80162430u: goto label_80162430;
    case 0x80162434u: goto label_80162434;
    case 0x80162438u: goto label_80162438;
    case 0x8016243Cu: goto label_8016243C;
    case 0x80162440u: goto label_80162440;
    case 0x80162444u: goto label_80162444;
    case 0x80162448u: goto label_80162448;
    case 0x8016244Cu: goto label_8016244C;
    case 0x80162450u: goto label_80162450;
    case 0x80162454u: goto label_80162454;
    case 0x80162458u: goto label_80162458;
    case 0x8016245Cu: goto label_8016245C;
    case 0x80162460u: goto label_80162460;
    case 0x80162464u: goto label_80162464;
    case 0x80162468u: goto label_80162468;
    case 0x8016246Cu: goto label_8016246C;
    case 0x80162470u: goto label_80162470;
    case 0x80162474u: goto label_80162474;
    case 0x80162478u: goto label_80162478;
    case 0x8016247Cu: goto label_8016247C;
    case 0x80162480u: goto label_80162480;
    case 0x80162484u: goto label_80162484;
    case 0x80162488u: goto label_80162488;
    case 0x8016248Cu: goto label_8016248C;
    case 0x80162490u: goto label_80162490;
    case 0x80162494u: goto label_80162494;
    case 0x80162498u: goto label_80162498;
    case 0x8016249Cu: goto label_8016249C;
    case 0x801624A0u: goto label_801624A0;
    case 0x801624A4u: goto label_801624A4;
    case 0x801624A8u: goto label_801624A8;
    case 0x801624ACu: goto label_801624AC;
    case 0x801624B0u: goto label_801624B0;
    case 0x801624B4u: goto label_801624B4;
    case 0x801624B8u: goto label_801624B8;
    case 0x801624BCu: goto label_801624BC;
    case 0x801624C0u: goto label_801624C0;
    case 0x801624C4u: goto label_801624C4;
    case 0x801624C8u: goto label_801624C8;
    case 0x801624CCu: goto label_801624CC;
    case 0x801624D0u: goto label_801624D0;
    case 0x801624D4u: goto label_801624D4;
    case 0x801624D8u: goto label_801624D8;
    case 0x801624DCu: goto label_801624DC;
    case 0x801624E0u: goto label_801624E0;
    case 0x801624E4u: goto label_801624E4;
    case 0x801624E8u: goto label_801624E8;
    case 0x801624ECu: goto label_801624EC;
    case 0x801624F0u: goto label_801624F0;
    case 0x801624F4u: goto label_801624F4;
    case 0x801624F8u: goto label_801624F8;
    case 0x801624FCu: goto label_801624FC;
    case 0x80162500u: goto label_80162500;
    case 0x80162504u: goto label_80162504;
    case 0x80162508u: goto label_80162508;
    case 0x8016250Cu: goto label_8016250C;
    case 0x80162510u: goto label_80162510;
    case 0x80162514u: goto label_80162514;
    case 0x80162518u: goto label_80162518;
    case 0x8016251Cu: goto label_8016251C;
    case 0x80162520u: goto label_80162520;
    case 0x80162524u: goto label_80162524;
    case 0x80162528u: goto label_80162528;
    case 0x8016252Cu: goto label_8016252C;
    case 0x80162530u: goto label_80162530;
    case 0x80162534u: goto label_80162534;
    case 0x80162538u: goto label_80162538;
    case 0x8016253Cu: goto label_8016253C;
    case 0x80162540u: goto label_80162540;
    case 0x80162544u: goto label_80162544;
    case 0x80162548u: goto label_80162548;
    case 0x8016254Cu: goto label_8016254C;
    case 0x80162550u: goto label_80162550;
    case 0x80162554u: goto label_80162554;
    case 0x80162558u: goto label_80162558;
    case 0x8016255Cu: goto label_8016255C;
    case 0x80162560u: goto label_80162560;
    case 0x80162564u: goto label_80162564;
    case 0x80162568u: goto label_80162568;
    case 0x8016256Cu: goto label_8016256C;
    case 0x80162570u: goto label_80162570;
    case 0x80162574u: goto label_80162574;
    case 0x80162578u: goto label_80162578;
    case 0x8016257Cu: goto label_8016257C;
    case 0x80162580u: goto label_80162580;
    case 0x80162584u: goto label_80162584;
    case 0x80162588u: goto label_80162588;
    case 0x8016258Cu: goto label_8016258C;
    case 0x80162590u: goto label_80162590;
    case 0x80162594u: goto label_80162594;
    case 0x80162598u: goto label_80162598;
    case 0x8016259Cu: goto label_8016259C;
    case 0x801625A0u: goto label_801625A0;
    case 0x801625A4u: goto label_801625A4;
    case 0x801625A8u: goto label_801625A8;
    case 0x801625ACu: goto label_801625AC;
    case 0x801625B0u: goto label_801625B0;
    case 0x801625B4u: goto label_801625B4;
    case 0x801625B8u: goto label_801625B8;
    case 0x801625BCu: goto label_801625BC;
    case 0x801625C0u: goto label_801625C0;
    case 0x801625C4u: goto label_801625C4;
    case 0x801625C8u: goto label_801625C8;
    case 0x801625CCu: goto label_801625CC;
    case 0x801625D0u: goto label_801625D0;
    case 0x801625D4u: goto label_801625D4;
    case 0x801625D8u: goto label_801625D8;
    case 0x801625DCu: goto label_801625DC;
    case 0x801625E0u: goto label_801625E0;
    case 0x801625E4u: goto label_801625E4;
    case 0x801625E8u: goto label_801625E8;
    case 0x801625ECu: goto label_801625EC;
    case 0x801625F0u: goto label_801625F0;
    case 0x801625F4u: goto label_801625F4;
    case 0x801625F8u: goto label_801625F8;
    case 0x801625FCu: goto label_801625FC;
    case 0x80162600u: goto label_80162600;
    case 0x80162604u: goto label_80162604;
    case 0x80162608u: goto label_80162608;
    case 0x8016260Cu: goto label_8016260C;
    case 0x80162610u: goto label_80162610;
    case 0x80162614u: goto label_80162614;
    case 0x80162618u: goto label_80162618;
    case 0x8016261Cu: goto label_8016261C;
    case 0x80162620u: goto label_80162620;
    case 0x80162624u: goto label_80162624;
    case 0x80162628u: goto label_80162628;
    case 0x8016262Cu: goto label_8016262C;
    case 0x80162630u: goto label_80162630;
    case 0x80162634u: goto label_80162634;
    case 0x80162638u: goto label_80162638;
    case 0x8016263Cu: goto label_8016263C;
    case 0x80162640u: goto label_80162640;
    case 0x80162644u: goto label_80162644;
    case 0x80162648u: goto label_80162648;
    case 0x8016264Cu: goto label_8016264C;
    case 0x80162650u: goto label_80162650;
    case 0x80162654u: goto label_80162654;
    case 0x80162658u: goto label_80162658;
    case 0x8016265Cu: goto label_8016265C;
    case 0x80162660u: goto label_80162660;
    case 0x80162664u: goto label_80162664;
    case 0x80162668u: goto label_80162668;
    case 0x8016266Cu: goto label_8016266C;
    case 0x80162670u: goto label_80162670;
    case 0x80162674u: goto label_80162674;
    case 0x80162678u: goto label_80162678;
    case 0x8016267Cu: goto label_8016267C;
    case 0x80162680u: goto label_80162680;
    case 0x80162684u: goto label_80162684;
    case 0x80162688u: goto label_80162688;
    case 0x8016268Cu: goto label_8016268C;
    case 0x80162690u: goto label_80162690;
    case 0x80162694u: goto label_80162694;
    case 0x80162698u: goto label_80162698;
    case 0x8016269Cu: goto label_8016269C;
    case 0x801626A0u: goto label_801626A0;
    case 0x801626A4u: goto label_801626A4;
    case 0x801626A8u: goto label_801626A8;
    case 0x801626ACu: goto label_801626AC;
    case 0x801626B0u: goto label_801626B0;
    case 0x801626B4u: goto label_801626B4;
    case 0x801626B8u: goto label_801626B8;
    case 0x801626BCu: goto label_801626BC;
    case 0x801626C0u: goto label_801626C0;
    case 0x801626C4u: goto label_801626C4;
    case 0x801626C8u: goto label_801626C8;
    case 0x801626CCu: goto label_801626CC;
    case 0x801626D0u: goto label_801626D0;
    case 0x801626D4u: goto label_801626D4;
    case 0x801626D8u: goto label_801626D8;
    case 0x801626DCu: goto label_801626DC;
    case 0x801626E0u: goto label_801626E0;
    case 0x801626E4u: goto label_801626E4;
    case 0x801626E8u: goto label_801626E8;
    case 0x801626ECu: goto label_801626EC;
    case 0x801626F0u: goto label_801626F0;
    case 0x801626F4u: goto label_801626F4;
    case 0x801626F8u: goto label_801626F8;
    case 0x801626FCu: goto label_801626FC;
    case 0x80162700u: goto label_80162700;
    case 0x80162704u: goto label_80162704;
    case 0x80162708u: goto label_80162708;
    case 0x8016270Cu: goto label_8016270C;
    case 0x80162710u: goto label_80162710;
    case 0x80162714u: goto label_80162714;
    case 0x80162718u: goto label_80162718;
    case 0x8016271Cu: goto label_8016271C;
    case 0x80162720u: goto label_80162720;
    case 0x80162724u: goto label_80162724;
    case 0x80162728u: goto label_80162728;
    case 0x8016272Cu: goto label_8016272C;
    case 0x80162730u: goto label_80162730;
    case 0x80162734u: goto label_80162734;
    case 0x80162738u: goto label_80162738;
    case 0x8016273Cu: goto label_8016273C;
    case 0x80162740u: goto label_80162740;
    case 0x80162744u: goto label_80162744;
    case 0x80162748u: goto label_80162748;
    case 0x8016274Cu: goto label_8016274C;
    case 0x80162750u: goto label_80162750;
    case 0x80162754u: goto label_80162754;
    case 0x80162758u: goto label_80162758;
    case 0x8016275Cu: goto label_8016275C;
    case 0x80162760u: goto label_80162760;
    case 0x80162764u: goto label_80162764;
    case 0x80162768u: goto label_80162768;
    case 0x8016276Cu: goto label_8016276C;
    case 0x80162770u: goto label_80162770;
    case 0x80162774u: goto label_80162774;
    case 0x80162778u: goto label_80162778;
    case 0x8016277Cu: goto label_8016277C;
    case 0x80162780u: goto label_80162780;
    case 0x80162784u: goto label_80162784;
    case 0x80162788u: goto label_80162788;
    case 0x8016278Cu: goto label_8016278C;
    case 0x80162790u: goto label_80162790;
    case 0x80162794u: goto label_80162794;
    case 0x80162798u: goto label_80162798;
    case 0x8016279Cu: goto label_8016279C;
    case 0x801627A0u: goto label_801627A0;
    case 0x801627A4u: goto label_801627A4;
    case 0x801627A8u: goto label_801627A8;
    case 0x801627ACu: goto label_801627AC;
    case 0x801627B0u: goto label_801627B0;
    case 0x801627B4u: goto label_801627B4;
    case 0x801627B8u: goto label_801627B8;
    case 0x801627BCu: goto label_801627BC;
    case 0x801627C0u: goto label_801627C0;
    case 0x801627C4u: goto label_801627C4;
    case 0x801627C8u: goto label_801627C8;
    case 0x801627CCu: goto label_801627CC;
    case 0x801627D0u: goto label_801627D0;
    case 0x801627D4u: goto label_801627D4;
    case 0x801627D8u: goto label_801627D8;
    case 0x801627DCu: goto label_801627DC;
    case 0x801627E0u: goto label_801627E0;
    case 0x801627E4u: goto label_801627E4;
    case 0x801627E8u: goto label_801627E8;
    case 0x801627ECu: goto label_801627EC;
    case 0x801627F0u: goto label_801627F0;
    case 0x801627F4u: goto label_801627F4;
    case 0x801627F8u: goto label_801627F8;
    case 0x801627FCu: goto label_801627FC;
    case 0x80162800u: goto label_80162800;
    case 0x80162804u: goto label_80162804;
    case 0x80162808u: goto label_80162808;
    case 0x8016280Cu: goto label_8016280C;
    case 0x80162810u: goto label_80162810;
    case 0x80162814u: goto label_80162814;
    case 0x80162818u: goto label_80162818;
    case 0x8016281Cu: goto label_8016281C;
    case 0x80162820u: goto label_80162820;
    case 0x80162824u: goto label_80162824;
    case 0x80162828u: goto label_80162828;
    case 0x8016282Cu: goto label_8016282C;
    case 0x80162830u: goto label_80162830;
    case 0x80162834u: goto label_80162834;
    case 0x80162838u: goto label_80162838;
    case 0x8016283Cu: goto label_8016283C;
    case 0x80162840u: goto label_80162840;
    case 0x80162844u: goto label_80162844;
    case 0x80162848u: goto label_80162848;
    case 0x8016284Cu: goto label_8016284C;
    case 0x80162850u: goto label_80162850;
    case 0x80162854u: goto label_80162854;
    case 0x80162858u: goto label_80162858;
    case 0x8016285Cu: goto label_8016285C;
    case 0x80162860u: goto label_80162860;
    case 0x80162864u: goto label_80162864;
    case 0x80162868u: goto label_80162868;
    case 0x8016286Cu: goto label_8016286C;
    case 0x80162870u: goto label_80162870;
    case 0x80162874u: goto label_80162874;
    case 0x80162878u: goto label_80162878;
    case 0x8016287Cu: goto label_8016287C;
    case 0x80162880u: goto label_80162880;
    case 0x80162884u: goto label_80162884;
    case 0x80162888u: goto label_80162888;
    case 0x8016288Cu: goto label_8016288C;
    case 0x80162890u: goto label_80162890;
    case 0x80162894u: goto label_80162894;
    case 0x80162898u: goto label_80162898;
    case 0x8016289Cu: goto label_8016289C;
    case 0x801628A0u: goto label_801628A0;
    case 0x801628A4u: goto label_801628A4;
    case 0x801628A8u: goto label_801628A8;
    case 0x801628ACu: goto label_801628AC;
    case 0x801628B0u: goto label_801628B0;
    case 0x801628B4u: goto label_801628B4;
    case 0x801628B8u: goto label_801628B8;
    case 0x801628BCu: goto label_801628BC;
    case 0x801628C0u: goto label_801628C0;
    case 0x801628C4u: goto label_801628C4;
    case 0x801628C8u: goto label_801628C8;
    case 0x801628CCu: goto label_801628CC;
    case 0x801628D0u: goto label_801628D0;
    case 0x801628D4u: goto label_801628D4;
    case 0x801628D8u: goto label_801628D8;
    case 0x801628DCu: goto label_801628DC;
    case 0x801628E0u: goto label_801628E0;
    case 0x801628E4u: goto label_801628E4;
    case 0x801628E8u: goto label_801628E8;
    case 0x801628ECu: goto label_801628EC;
    case 0x801628F0u: goto label_801628F0;
    case 0x801628F4u: goto label_801628F4;
    case 0x801628F8u: goto label_801628F8;
    case 0x801628FCu: goto label_801628FC;
    case 0x80162900u: goto label_80162900;
    case 0x80162904u: goto label_80162904;
    case 0x80162908u: goto label_80162908;
    case 0x8016290Cu: goto label_8016290C;
    case 0x80162910u: goto label_80162910;
    case 0x80162914u: goto label_80162914;
    case 0x80162918u: goto label_80162918;
    case 0x8016291Cu: goto label_8016291C;
    case 0x80162920u: goto label_80162920;
    case 0x80162924u: goto label_80162924;
    case 0x80162928u: goto label_80162928;
    case 0x8016292Cu: goto label_8016292C;
    case 0x80162930u: goto label_80162930;
    case 0x80162934u: goto label_80162934;
    case 0x80162938u: goto label_80162938;
    case 0x8016293Cu: goto label_8016293C;
    case 0x80162940u: goto label_80162940;
    case 0x80162944u: goto label_80162944;
    case 0x80162948u: goto label_80162948;
    case 0x8016294Cu: goto label_8016294C;
    case 0x80162950u: goto label_80162950;
    case 0x80162954u: goto label_80162954;
    case 0x80162958u: goto label_80162958;
    case 0x8016295Cu: goto label_8016295C;
    case 0x80162960u: goto label_80162960;
    case 0x80162964u: goto label_80162964;
    case 0x80162968u: goto label_80162968;
    case 0x8016296Cu: goto label_8016296C;
    case 0x80162970u: goto label_80162970;
    case 0x80162974u: goto label_80162974;
    case 0x80162978u: goto label_80162978;
    case 0x8016297Cu: goto label_8016297C;
    case 0x80162980u: goto label_80162980;
    case 0x80162984u: goto label_80162984;
    case 0x80162988u: goto label_80162988;
    case 0x8016298Cu: goto label_8016298C;
    case 0x80162990u: goto label_80162990;
    case 0x80162994u: goto label_80162994;
    case 0x80162998u: goto label_80162998;
    case 0x8016299Cu: goto label_8016299C;
    case 0x801629A0u: goto label_801629A0;
    case 0x801629A4u: goto label_801629A4;
    case 0x801629A8u: goto label_801629A8;
    case 0x801629ACu: goto label_801629AC;
    case 0x801629B0u: goto label_801629B0;
    case 0x801629B4u: goto label_801629B4;
    case 0x801629B8u: goto label_801629B8;
    case 0x801629BCu: goto label_801629BC;
    case 0x801629C0u: goto label_801629C0;
    case 0x801629C4u: goto label_801629C4;
    case 0x801629C8u: goto label_801629C8;
    case 0x801629CCu: goto label_801629CC;
    case 0x801629D0u: goto label_801629D0;
    case 0x801629D4u: goto label_801629D4;
    case 0x801629D8u: goto label_801629D8;
    case 0x801629DCu: goto label_801629DC;
    case 0x801629E0u: goto label_801629E0;
    case 0x801629E4u: goto label_801629E4;
    case 0x801629E8u: goto label_801629E8;
    case 0x801629ECu: goto label_801629EC;
    case 0x801629F0u: goto label_801629F0;
    case 0x801629F4u: goto label_801629F4;
    case 0x801629F8u: goto label_801629F8;
    case 0x801629FCu: goto label_801629FC;
    case 0x80162A00u: goto label_80162A00;
    case 0x80162A04u: goto label_80162A04;
    case 0x80162A08u: goto label_80162A08;
    case 0x80162A0Cu: goto label_80162A0C;
    case 0x80162A10u: goto label_80162A10;
    case 0x80162A14u: goto label_80162A14;
    case 0x80162A18u: goto label_80162A18;
    case 0x80162A1Cu: goto label_80162A1C;
    case 0x80162A20u: goto label_80162A20;
    case 0x80162A24u: goto label_80162A24;
    case 0x80162A28u: goto label_80162A28;
    case 0x80162A2Cu: goto label_80162A2C;
    case 0x80162A30u: goto label_80162A30;
    case 0x80162A34u: goto label_80162A34;
    case 0x80162A38u: goto label_80162A38;
    case 0x80162A3Cu: goto label_80162A3C;
    case 0x80162A40u: goto label_80162A40;
    case 0x80162A44u: goto label_80162A44;
    case 0x80162A48u: goto label_80162A48;
    case 0x80162A4Cu: goto label_80162A4C;
    case 0x80162A50u: goto label_80162A50;
    case 0x80162A54u: goto label_80162A54;
    case 0x80162A58u: goto label_80162A58;
    case 0x80162A5Cu: goto label_80162A5C;
    case 0x80162A60u: goto label_80162A60;
    case 0x80162A64u: goto label_80162A64;
    case 0x80162A68u: goto label_80162A68;
    case 0x80162A6Cu: goto label_80162A6C;
    case 0x80162A70u: goto label_80162A70;
    case 0x80162A74u: goto label_80162A74;
    case 0x80162A78u: goto label_80162A78;
    case 0x80162A7Cu: goto label_80162A7C;
    case 0x80162A80u: goto label_80162A80;
    case 0x80162A84u: goto label_80162A84;
    case 0x80162A88u: goto label_80162A88;
    case 0x80162A8Cu: goto label_80162A8C;
    case 0x80162A90u: goto label_80162A90;
    case 0x80162A94u: goto label_80162A94;
    case 0x80162A98u: goto label_80162A98;
    case 0x80162A9Cu: goto label_80162A9C;
    case 0x80162AA0u: goto label_80162AA0;
    case 0x80162AA4u: goto label_80162AA4;
    case 0x80162AA8u: goto label_80162AA8;
    case 0x80162AACu: goto label_80162AAC;
    case 0x80162AB0u: goto label_80162AB0;
    case 0x80162AB4u: goto label_80162AB4;
    case 0x80162AB8u: goto label_80162AB8;
    case 0x80162ABCu: goto label_80162ABC;
    case 0x80162AC0u: goto label_80162AC0;
    case 0x80162AC4u: goto label_80162AC4;
    case 0x80162AC8u: goto label_80162AC8;
    case 0x80162ACCu: goto label_80162ACC;
    case 0x80162AD0u: goto label_80162AD0;
    case 0x80162AD4u: goto label_80162AD4;
    case 0x80162AD8u: goto label_80162AD8;
    case 0x80162ADCu: goto label_80162ADC;
    case 0x80162AE0u: goto label_80162AE0;
    case 0x80162AE4u: goto label_80162AE4;
    case 0x80162AE8u: goto label_80162AE8;
    case 0x80162AECu: goto label_80162AEC;
    case 0x80162AF0u: goto label_80162AF0;
    case 0x80162AF4u: goto label_80162AF4;
    case 0x80162AF8u: goto label_80162AF8;
    case 0x80162AFCu: goto label_80162AFC;
    case 0x80162B00u: goto label_80162B00;
    case 0x80162B04u: goto label_80162B04;
    case 0x80162B08u: goto label_80162B08;
    case 0x80162B0Cu: goto label_80162B0C;
    case 0x80162B10u: goto label_80162B10;
    case 0x80162B14u: goto label_80162B14;
    case 0x80162B18u: goto label_80162B18;
    case 0x80162B1Cu: goto label_80162B1C;
    case 0x80162B20u: goto label_80162B20;
    case 0x80162B24u: goto label_80162B24;
    case 0x80162B28u: goto label_80162B28;
    case 0x80162B2Cu: goto label_80162B2C;
    case 0x80162B30u: goto label_80162B30;
    case 0x80162B34u: goto label_80162B34;
    case 0x80162B38u: goto label_80162B38;
    case 0x80162B3Cu: goto label_80162B3C;
    case 0x80162B40u: goto label_80162B40;
    case 0x80162B44u: goto label_80162B44;
    case 0x80162B48u: goto label_80162B48;
    case 0x80162B4Cu: goto label_80162B4C;
    case 0x80162B50u: goto label_80162B50;
    case 0x80162B54u: goto label_80162B54;
    case 0x80162B58u: goto label_80162B58;
    case 0x80162B5Cu: goto label_80162B5C;
    case 0x80162B60u: goto label_80162B60;
    case 0x80162B64u: goto label_80162B64;
    case 0x80162B68u: goto label_80162B68;
    case 0x80162B6Cu: goto label_80162B6C;
    case 0x80162B70u: goto label_80162B70;
    case 0x80162B74u: goto label_80162B74;
    case 0x80162B78u: goto label_80162B78;
    case 0x80162B7Cu: goto label_80162B7C;
    case 0x80162B80u: goto label_80162B80;
    case 0x80162B84u: goto label_80162B84;
    case 0x80162B88u: goto label_80162B88;
    case 0x80162B8Cu: goto label_80162B8C;
    case 0x80162B90u: goto label_80162B90;
    case 0x80162B94u: goto label_80162B94;
    case 0x80162B98u: goto label_80162B98;
    case 0x80162B9Cu: goto label_80162B9C;
    case 0x80162BA0u: goto label_80162BA0;
    case 0x80162BA4u: goto label_80162BA4;
    case 0x80162BA8u: goto label_80162BA8;
    case 0x80162BACu: goto label_80162BAC;
    case 0x80162BB0u: goto label_80162BB0;
    case 0x80162BB4u: goto label_80162BB4;
    case 0x80162BB8u: goto label_80162BB8;
    case 0x80162BBCu: goto label_80162BBC;
    case 0x80162BC0u: goto label_80162BC0;
    case 0x80162BC4u: goto label_80162BC4;
    case 0x80162BC8u: goto label_80162BC8;
    case 0x80162BCCu: goto label_80162BCC;
    case 0x80162BD0u: goto label_80162BD0;
    case 0x80162BD4u: goto label_80162BD4;
    case 0x80162BD8u: goto label_80162BD8;
    case 0x80162BDCu: goto label_80162BDC;
    case 0x80162BE0u: goto label_80162BE0;
    case 0x80162BE4u: goto label_80162BE4;
    case 0x80162BE8u: goto label_80162BE8;
    case 0x80162BECu: goto label_80162BEC;
    case 0x80162BF0u: goto label_80162BF0;
    case 0x80162BF4u: goto label_80162BF4;
    case 0x80162BF8u: goto label_80162BF8;
    case 0x80162BFCu: goto label_80162BFC;
    case 0x80162C00u: goto label_80162C00;
    case 0x80162C04u: goto label_80162C04;
    case 0x80162C08u: goto label_80162C08;
    case 0x80162C0Cu: goto label_80162C0C;
    case 0x80162C10u: goto label_80162C10;
    case 0x80162C14u: goto label_80162C14;
    case 0x80162C18u: goto label_80162C18;
    case 0x80162C1Cu: goto label_80162C1C;
    case 0x80162C20u: goto label_80162C20;
    case 0x80162C24u: goto label_80162C24;
    case 0x80162C28u: goto label_80162C28;
    case 0x80162C2Cu: goto label_80162C2C;
    case 0x80162C30u: goto label_80162C30;
    case 0x80162C34u: goto label_80162C34;
    case 0x80162C38u: goto label_80162C38;
    case 0x80162C3Cu: goto label_80162C3C;
    case 0x80162C40u: goto label_80162C40;
    case 0x80162C44u: goto label_80162C44;
    case 0x80162C48u: goto label_80162C48;
    case 0x80162C4Cu: goto label_80162C4C;
    case 0x80162C50u: goto label_80162C50;
    case 0x80162C54u: goto label_80162C54;
    case 0x80162C58u: goto label_80162C58;
    case 0x80162C5Cu: goto label_80162C5C;
    case 0x80162C60u: goto label_80162C60;
    case 0x80162C64u: goto label_80162C64;
    case 0x80162C68u: goto label_80162C68;
    case 0x80162C6Cu: goto label_80162C6C;
    case 0x80162C70u: goto label_80162C70;
    case 0x80162C74u: goto label_80162C74;
    case 0x80162C78u: goto label_80162C78;
    case 0x80162C7Cu: goto label_80162C7C;
    case 0x80162C80u: goto label_80162C80;
    case 0x80162C84u: goto label_80162C84;
    case 0x80162C88u: goto label_80162C88;
    case 0x80162C8Cu: goto label_80162C8C;
    case 0x80162C90u: goto label_80162C90;
    case 0x80162C94u: goto label_80162C94;
    case 0x80162C98u: goto label_80162C98;
    case 0x80162C9Cu: goto label_80162C9C;
    case 0x80162CA0u: goto label_80162CA0;
    case 0x80162CA4u: goto label_80162CA4;
    case 0x80162CA8u: goto label_80162CA8;
    case 0x80162CACu: goto label_80162CAC;
    case 0x80162CB0u: goto label_80162CB0;
    case 0x80162CB4u: goto label_80162CB4;
    case 0x80162CB8u: goto label_80162CB8;
    case 0x80162CBCu: goto label_80162CBC;
    case 0x80162CC0u: goto label_80162CC0;
    case 0x80162CC4u: goto label_80162CC4;
    case 0x80162CC8u: goto label_80162CC8;
    case 0x80162CCCu: goto label_80162CCC;
    case 0x80162CD0u: goto label_80162CD0;
    case 0x80162CD4u: goto label_80162CD4;
    case 0x80162CD8u: goto label_80162CD8;
    case 0x80162CDCu: goto label_80162CDC;
    case 0x80162CE0u: goto label_80162CE0;
    case 0x80162CE4u: goto label_80162CE4;
    case 0x80162CE8u: goto label_80162CE8;
    case 0x80162CECu: goto label_80162CEC;
    case 0x80162CF0u: goto label_80162CF0;
    case 0x80162CF4u: goto label_80162CF4;
    case 0x80162CF8u: goto label_80162CF8;
    case 0x80162CFCu: goto label_80162CFC;
    case 0x80162D00u: goto label_80162D00;
    case 0x80162D04u: goto label_80162D04;
    case 0x80162D08u: goto label_80162D08;
    case 0x80162D0Cu: goto label_80162D0C;
    case 0x80162D10u: goto label_80162D10;
    case 0x80162D14u: goto label_80162D14;
    case 0x80162D18u: goto label_80162D18;
    case 0x80162D1Cu: goto label_80162D1C;
    case 0x80162D20u: goto label_80162D20;
    case 0x80162D24u: goto label_80162D24;
    case 0x80162D28u: goto label_80162D28;
    case 0x80162D2Cu: goto label_80162D2C;
    case 0x80162D30u: goto label_80162D30;
    case 0x80162D34u: goto label_80162D34;
    case 0x80162D38u: goto label_80162D38;
    case 0x80162D3Cu: goto label_80162D3C;
    case 0x80162D40u: goto label_80162D40;
    case 0x80162D44u: goto label_80162D44;
    case 0x80162D48u: goto label_80162D48;
    case 0x80162D4Cu: goto label_80162D4C;
    case 0x80162D50u: goto label_80162D50;
    case 0x80162D54u: goto label_80162D54;
    case 0x80162D58u: goto label_80162D58;
    case 0x80162D5Cu: goto label_80162D5C;
    case 0x80162D60u: goto label_80162D60;
    case 0x80162D64u: goto label_80162D64;
    case 0x80162D68u: goto label_80162D68;
    case 0x80162D6Cu: goto label_80162D6C;
    case 0x80162D70u: goto label_80162D70;
    case 0x80162D74u: goto label_80162D74;
    case 0x80162D78u: goto label_80162D78;
    case 0x80162D7Cu: goto label_80162D7C;
    case 0x80162D80u: goto label_80162D80;
    case 0x80162D84u: goto label_80162D84;
    case 0x80162D88u: goto label_80162D88;
    case 0x80162D8Cu: goto label_80162D8C;
    case 0x80162D90u: goto label_80162D90;
    case 0x80162D94u: goto label_80162D94;
    case 0x80162D98u: goto label_80162D98;
    case 0x80162D9Cu: goto label_80162D9C;
    case 0x80162DA0u: goto label_80162DA0;
    case 0x80162DA4u: goto label_80162DA4;
    case 0x80162DA8u: goto label_80162DA8;
    case 0x80162DACu: goto label_80162DAC;
    case 0x80162DB0u: goto label_80162DB0;
    case 0x80162DB4u: goto label_80162DB4;
    case 0x80162DB8u: goto label_80162DB8;
    case 0x80162DBCu: goto label_80162DBC;
    case 0x80162DC0u: goto label_80162DC0;
    case 0x80162DC4u: goto label_80162DC4;
    case 0x80162DC8u: goto label_80162DC8;
    case 0x80162DCCu: goto label_80162DCC;
    case 0x80162DD0u: goto label_80162DD0;
    case 0x80162DD4u: goto label_80162DD4;
    case 0x80162DD8u: goto label_80162DD8;
    case 0x80162DDCu: goto label_80162DDC;
    case 0x80162DE0u: goto label_80162DE0;
    case 0x80162DE4u: goto label_80162DE4;
    case 0x80162DE8u: goto label_80162DE8;
    case 0x80162DECu: goto label_80162DEC;
    case 0x80162DF0u: goto label_80162DF0;
    case 0x80162DF4u: goto label_80162DF4;
    case 0x80162DF8u: goto label_80162DF8;
    case 0x80162DFCu: goto label_80162DFC;
    case 0x80162E00u: goto label_80162E00;
    case 0x80162E04u: goto label_80162E04;
    case 0x80162E08u: goto label_80162E08;
    case 0x80162E0Cu: goto label_80162E0C;
    case 0x80162E10u: goto label_80162E10;
    case 0x80162E14u: goto label_80162E14;
    case 0x80162E18u: goto label_80162E18;
    case 0x80162E1Cu: goto label_80162E1C;
    case 0x80162E20u: goto label_80162E20;
    case 0x80162E24u: goto label_80162E24;
    case 0x80162E28u: goto label_80162E28;
    case 0x80162E2Cu: goto label_80162E2C;
    case 0x80162E30u: goto label_80162E30;
    case 0x80162E34u: goto label_80162E34;
    case 0x80162E38u: goto label_80162E38;
    case 0x80162E3Cu: goto label_80162E3C;
    case 0x80162E40u: goto label_80162E40;
    case 0x80162E44u: goto label_80162E44;
    case 0x80162E48u: goto label_80162E48;
    case 0x80162E4Cu: goto label_80162E4C;
    case 0x80162E50u: goto label_80162E50;
    case 0x80162E54u: goto label_80162E54;
    case 0x80162E58u: goto label_80162E58;
    case 0x80162E5Cu: goto label_80162E5C;
    case 0x80162E60u: goto label_80162E60;
    case 0x80162E64u: goto label_80162E64;
    case 0x80162E68u: goto label_80162E68;
    case 0x80162E6Cu: goto label_80162E6C;
    case 0x80162E70u: goto label_80162E70;
    case 0x80162E74u: goto label_80162E74;
    case 0x80162E78u: goto label_80162E78;
    case 0x80162E7Cu: goto label_80162E7C;
    case 0x80162E80u: goto label_80162E80;
    case 0x80162E84u: goto label_80162E84;
    case 0x80162E88u: goto label_80162E88;
    case 0x80162E8Cu: goto label_80162E8C;
    case 0x80162E90u: goto label_80162E90;
    case 0x80162E94u: goto label_80162E94;
    case 0x80162E98u: goto label_80162E98;
    case 0x80162E9Cu: goto label_80162E9C;
    case 0x80162EA0u: goto label_80162EA0;
    case 0x80162EA4u: goto label_80162EA4;
    case 0x80162EA8u: goto label_80162EA8;
    case 0x80162EACu: goto label_80162EAC;
    case 0x80162EB0u: goto label_80162EB0;
    case 0x80162EB4u: goto label_80162EB4;
    case 0x80162EB8u: goto label_80162EB8;
    case 0x80162EBCu: goto label_80162EBC;
    case 0x80162EC0u: goto label_80162EC0;
    case 0x80162EC4u: goto label_80162EC4;
    case 0x80162EC8u: goto label_80162EC8;
    case 0x80162ECCu: goto label_80162ECC;
    case 0x80162ED0u: goto label_80162ED0;
    case 0x80162ED4u: goto label_80162ED4;
    case 0x80162ED8u: goto label_80162ED8;
    case 0x80162EDCu: goto label_80162EDC;
    case 0x80162EE0u: goto label_80162EE0;
    case 0x80162EE4u: goto label_80162EE4;
    case 0x80162EE8u: goto label_80162EE8;
    case 0x80162EECu: goto label_80162EEC;
    case 0x80162EF0u: goto label_80162EF0;
    case 0x80162EF4u: goto label_80162EF4;
    case 0x80162EF8u: goto label_80162EF8;
    case 0x80162EFCu: goto label_80162EFC;
    case 0x80162F00u: goto label_80162F00;
    case 0x80162F04u: goto label_80162F04;
    case 0x80162F08u: goto label_80162F08;
    case 0x80162F0Cu: goto label_80162F0C;
    case 0x80162F10u: goto label_80162F10;
    case 0x80162F14u: goto label_80162F14;
    case 0x80162F18u: goto label_80162F18;
    case 0x80162F1Cu: goto label_80162F1C;
    case 0x80162F20u: goto label_80162F20;
    case 0x80162F24u: goto label_80162F24;
    case 0x80162F28u: goto label_80162F28;
    case 0x80162F2Cu: goto label_80162F2C;
    case 0x80162F30u: goto label_80162F30;
    case 0x80162F34u: goto label_80162F34;
    case 0x80162F38u: goto label_80162F38;
    case 0x80162F3Cu: goto label_80162F3C;
    case 0x80162F40u: goto label_80162F40;
    case 0x80162F44u: goto label_80162F44;
    case 0x80162F48u: goto label_80162F48;
    case 0x80162F4Cu: goto label_80162F4C;
    case 0x80162F50u: goto label_80162F50;
    case 0x80162F54u: goto label_80162F54;
    case 0x80162F58u: goto label_80162F58;
    case 0x80162F5Cu: goto label_80162F5C;
    case 0x80162F60u: goto label_80162F60;
    case 0x80162F64u: goto label_80162F64;
    case 0x80162F68u: goto label_80162F68;
    case 0x80162F6Cu: goto label_80162F6C;
    case 0x80162F70u: goto label_80162F70;
    case 0x80162F74u: goto label_80162F74;
    case 0x80162F78u: goto label_80162F78;
    case 0x80162F7Cu: goto label_80162F7C;
    case 0x80162F80u: goto label_80162F80;
    case 0x80162F84u: goto label_80162F84;
    case 0x80162F88u: goto label_80162F88;
    case 0x80162F8Cu: goto label_80162F8C;
    case 0x80162F90u: goto label_80162F90;
    case 0x80162F94u: goto label_80162F94;
    case 0x80162F98u: goto label_80162F98;
    case 0x80162F9Cu: goto label_80162F9C;
    case 0x80162FA0u: goto label_80162FA0;
    case 0x80162FA4u: goto label_80162FA4;
    case 0x80162FA8u: goto label_80162FA8;
    case 0x80162FACu: goto label_80162FAC;
    case 0x80162FB0u: goto label_80162FB0;
    case 0x80162FB4u: goto label_80162FB4;
    case 0x80162FB8u: goto label_80162FB8;
    case 0x80162FBCu: goto label_80162FBC;
    case 0x80162FC0u: goto label_80162FC0;
    case 0x80162FC4u: goto label_80162FC4;
    case 0x80162FC8u: goto label_80162FC8;
    case 0x80162FCCu: goto label_80162FCC;
    case 0x80162FD0u: goto label_80162FD0;
    case 0x80162FD4u: goto label_80162FD4;
    case 0x80162FD8u: goto label_80162FD8;
    case 0x80162FDCu: goto label_80162FDC;
    case 0x80162FE0u: goto label_80162FE0;
    case 0x80162FE4u: goto label_80162FE4;
    case 0x80162FE8u: goto label_80162FE8;
    case 0x80162FECu: goto label_80162FEC;
    case 0x80162FF0u: goto label_80162FF0;
    case 0x80162FF4u: goto label_80162FF4;
    case 0x80162FF8u: goto label_80162FF8;
    case 0x80162FFCu: goto label_80162FFC;
    case 0x80163000u: goto label_80163000;
    case 0x80163004u: goto label_80163004;
    case 0x80163008u: goto label_80163008;
    case 0x8016300Cu: goto label_8016300C;
    case 0x80163010u: goto label_80163010;
    case 0x80163014u: goto label_80163014;
    case 0x80163018u: goto label_80163018;
    case 0x8016301Cu: goto label_8016301C;
    case 0x80163020u: goto label_80163020;
    case 0x80163024u: goto label_80163024;
    case 0x80163028u: goto label_80163028;
    case 0x8016302Cu: goto label_8016302C;
    case 0x80163030u: goto label_80163030;
    case 0x80163034u: goto label_80163034;
    case 0x80163038u: goto label_80163038;
    case 0x8016303Cu: goto label_8016303C;
    case 0x80163040u: goto label_80163040;
    case 0x80163044u: goto label_80163044;
    case 0x80163048u: goto label_80163048;
    case 0x8016304Cu: goto label_8016304C;
    case 0x80163050u: goto label_80163050;
    case 0x80163054u: goto label_80163054;
    case 0x80163058u: goto label_80163058;
    case 0x8016305Cu: goto label_8016305C;
    case 0x80163060u: goto label_80163060;
    case 0x80163064u: goto label_80163064;
    case 0x80163068u: goto label_80163068;
    case 0x8016306Cu: goto label_8016306C;
    case 0x80163070u: goto label_80163070;
    case 0x80163074u: goto label_80163074;
    case 0x80163078u: goto label_80163078;
    case 0x8016307Cu: goto label_8016307C;
    case 0x80163080u: goto label_80163080;
    case 0x80163084u: goto label_80163084;
    case 0x80163088u: goto label_80163088;
    case 0x8016308Cu: goto label_8016308C;
    case 0x80163090u: goto label_80163090;
    case 0x80163094u: goto label_80163094;
    case 0x80163098u: goto label_80163098;
    case 0x8016309Cu: goto label_8016309C;
    case 0x801630A0u: goto label_801630A0;
    case 0x801630A4u: goto label_801630A4;
    case 0x801630A8u: goto label_801630A8;
    case 0x801630ACu: goto label_801630AC;
    case 0x801630B0u: goto label_801630B0;
    case 0x801630B4u: goto label_801630B4;
    case 0x801630B8u: goto label_801630B8;
    case 0x801630BCu: goto label_801630BC;
    case 0x801630C0u: goto label_801630C0;
    case 0x801630C4u: goto label_801630C4;
    case 0x801630C8u: goto label_801630C8;
    case 0x801630CCu: goto label_801630CC;
    case 0x801630D0u: goto label_801630D0;
    case 0x801630D4u: goto label_801630D4;
    case 0x801630D8u: goto label_801630D8;
    case 0x801630DCu: goto label_801630DC;
    case 0x801630E0u: goto label_801630E0;
    case 0x801630E4u: goto label_801630E4;
    case 0x801630E8u: goto label_801630E8;
    case 0x801630ECu: goto label_801630EC;
    case 0x801630F0u: goto label_801630F0;
    case 0x801630F4u: goto label_801630F4;
    case 0x801630F8u: goto label_801630F8;
    case 0x801630FCu: goto label_801630FC;
    case 0x80163100u: goto label_80163100;
    case 0x80163104u: goto label_80163104;
    case 0x80163108u: goto label_80163108;
    case 0x8016310Cu: goto label_8016310C;
    case 0x80163110u: goto label_80163110;
    case 0x80163114u: goto label_80163114;
    case 0x80163118u: goto label_80163118;
    case 0x8016311Cu: goto label_8016311C;
    case 0x80163120u: goto label_80163120;
    case 0x80163124u: goto label_80163124;
    case 0x80163128u: goto label_80163128;
    case 0x8016312Cu: goto label_8016312C;
    case 0x80163130u: goto label_80163130;
    case 0x80163134u: goto label_80163134;
    case 0x80163138u: goto label_80163138;
    case 0x8016313Cu: goto label_8016313C;
    case 0x80163140u: goto label_80163140;
    case 0x80163144u: goto label_80163144;
    case 0x80163148u: goto label_80163148;
    case 0x8016314Cu: goto label_8016314C;
    case 0x80163150u: goto label_80163150;
    case 0x80163154u: goto label_80163154;
    case 0x80163158u: goto label_80163158;
    case 0x8016315Cu: goto label_8016315C;
    case 0x80163160u: goto label_80163160;
    case 0x80163164u: goto label_80163164;
    case 0x80163168u: goto label_80163168;
    case 0x8016316Cu: goto label_8016316C;
    case 0x80163170u: goto label_80163170;
    case 0x80163174u: goto label_80163174;
    case 0x80163178u: goto label_80163178;
    case 0x8016317Cu: goto label_8016317C;
    case 0x80163180u: goto label_80163180;
    case 0x80163184u: goto label_80163184;
    case 0x80163188u: goto label_80163188;
    case 0x8016318Cu: goto label_8016318C;
    case 0x80163190u: goto label_80163190;
    case 0x80163194u: goto label_80163194;
    case 0x80163198u: goto label_80163198;
    case 0x8016319Cu: goto label_8016319C;
    case 0x801631A0u: goto label_801631A0;
    case 0x801631A4u: goto label_801631A4;
    case 0x801631A8u: goto label_801631A8;
    case 0x801631ACu: goto label_801631AC;
    case 0x801631B0u: goto label_801631B0;
    case 0x801631B4u: goto label_801631B4;
    case 0x801631B8u: goto label_801631B8;
    case 0x801631BCu: goto label_801631BC;
    case 0x801631C0u: goto label_801631C0;
    case 0x801631C4u: goto label_801631C4;
    case 0x801631C8u: goto label_801631C8;
    case 0x801631CCu: goto label_801631CC;
    case 0x801631D0u: goto label_801631D0;
    case 0x801631D4u: goto label_801631D4;
    case 0x801631D8u: goto label_801631D8;
    case 0x801631DCu: goto label_801631DC;
    case 0x801631E0u: goto label_801631E0;
    case 0x801631E4u: goto label_801631E4;
    case 0x801631E8u: goto label_801631E8;
    case 0x801631ECu: goto label_801631EC;
    case 0x801631F0u: goto label_801631F0;
    case 0x801631F4u: goto label_801631F4;
    case 0x801631F8u: goto label_801631F8;
    case 0x801631FCu: goto label_801631FC;
    case 0x80163200u: goto label_80163200;
    case 0x80163204u: goto label_80163204;
    case 0x80163208u: goto label_80163208;
    case 0x8016320Cu: goto label_8016320C;
    case 0x80163210u: goto label_80163210;
    case 0x80163214u: goto label_80163214;
    case 0x80163218u: goto label_80163218;
    case 0x8016321Cu: goto label_8016321C;
    case 0x80163220u: goto label_80163220;
    case 0x80163224u: goto label_80163224;
    case 0x80163228u: goto label_80163228;
    case 0x8016322Cu: goto label_8016322C;
    case 0x80163230u: goto label_80163230;
    case 0x80163234u: goto label_80163234;
    case 0x80163238u: goto label_80163238;
    case 0x8016323Cu: goto label_8016323C;
    case 0x80163240u: goto label_80163240;
    case 0x80163244u: goto label_80163244;
    case 0x80163248u: goto label_80163248;
    case 0x8016324Cu: goto label_8016324C;
    case 0x80163250u: goto label_80163250;
    case 0x80163254u: goto label_80163254;
    case 0x80163258u: goto label_80163258;
    case 0x8016325Cu: goto label_8016325C;
    case 0x80163260u: goto label_80163260;
    case 0x80163264u: goto label_80163264;
    case 0x80163268u: goto label_80163268;
    case 0x8016326Cu: goto label_8016326C;
    case 0x80163270u: goto label_80163270;
    case 0x80163274u: goto label_80163274;
    case 0x80163278u: goto label_80163278;
    case 0x8016327Cu: goto label_8016327C;
    case 0x80163280u: goto label_80163280;
    case 0x80163284u: goto label_80163284;
    case 0x80163288u: goto label_80163288;
    case 0x8016328Cu: goto label_8016328C;
    case 0x80163290u: goto label_80163290;
    case 0x80163294u: goto label_80163294;
    case 0x80163298u: goto label_80163298;
    case 0x8016329Cu: goto label_8016329C;
    case 0x801632A0u: goto label_801632A0;
    case 0x801632A4u: goto label_801632A4;
    case 0x801632A8u: goto label_801632A8;
    case 0x801632ACu: goto label_801632AC;
    case 0x801632B0u: goto label_801632B0;
    case 0x801632B4u: goto label_801632B4;
    case 0x801632B8u: goto label_801632B8;
    case 0x801632BCu: goto label_801632BC;
    case 0x801632C0u: goto label_801632C0;
    case 0x801632C4u: goto label_801632C4;
    case 0x801632C8u: goto label_801632C8;
    case 0x801632CCu: goto label_801632CC;
    case 0x801632D0u: goto label_801632D0;
    case 0x801632D4u: goto label_801632D4;
    case 0x801632D8u: goto label_801632D8;
    case 0x801632DCu: goto label_801632DC;
    case 0x801632E0u: goto label_801632E0;
    case 0x801632E4u: goto label_801632E4;
    case 0x801632E8u: goto label_801632E8;
    case 0x801632ECu: goto label_801632EC;
    case 0x801632F0u: goto label_801632F0;
    case 0x801632F4u: goto label_801632F4;
    case 0x801632F8u: goto label_801632F8;
    case 0x801632FCu: goto label_801632FC;
    case 0x80163300u: goto label_80163300;
    case 0x80163304u: goto label_80163304;
    case 0x80163308u: goto label_80163308;
    case 0x8016330Cu: goto label_8016330C;
    case 0x80163310u: goto label_80163310;
    case 0x80163314u: goto label_80163314;
    case 0x80163318u: goto label_80163318;
    case 0x8016331Cu: goto label_8016331C;
    case 0x80163320u: goto label_80163320;
    case 0x80163324u: goto label_80163324;
    case 0x80163328u: goto label_80163328;
    case 0x8016332Cu: goto label_8016332C;
    case 0x80163330u: goto label_80163330;
    case 0x80163334u: goto label_80163334;
    case 0x80163338u: goto label_80163338;
    case 0x8016333Cu: goto label_8016333C;
    case 0x80163340u: goto label_80163340;
    case 0x80163344u: goto label_80163344;
    case 0x80163348u: goto label_80163348;
    case 0x8016334Cu: goto label_8016334C;
    case 0x80163350u: goto label_80163350;
    case 0x80163354u: goto label_80163354;
    case 0x80163358u: goto label_80163358;
    case 0x8016335Cu: goto label_8016335C;
    case 0x80163360u: goto label_80163360;
    case 0x80163364u: goto label_80163364;
    case 0x80163368u: goto label_80163368;
    case 0x8016336Cu: goto label_8016336C;
    case 0x80163370u: goto label_80163370;
    case 0x80163374u: goto label_80163374;
    case 0x80163378u: goto label_80163378;
    case 0x8016337Cu: goto label_8016337C;
    case 0x80163380u: goto label_80163380;
    case 0x80163384u: goto label_80163384;
    case 0x80163388u: goto label_80163388;
    case 0x8016338Cu: goto label_8016338C;
    case 0x80163390u: goto label_80163390;
    case 0x80163394u: goto label_80163394;
    case 0x80163398u: goto label_80163398;
    case 0x8016339Cu: goto label_8016339C;
    case 0x801633A0u: goto label_801633A0;
    case 0x801633A4u: goto label_801633A4;
    case 0x801633A8u: goto label_801633A8;
    case 0x801633ACu: goto label_801633AC;
    case 0x801633B0u: goto label_801633B0;
    case 0x801633B4u: goto label_801633B4;
    case 0x801633B8u: goto label_801633B8;
    case 0x801633BCu: goto label_801633BC;
    case 0x801633C0u: goto label_801633C0;
    case 0x801633C4u: goto label_801633C4;
    case 0x801633C8u: goto label_801633C8;
    case 0x801633CCu: goto label_801633CC;
    case 0x801633D0u: goto label_801633D0;
    case 0x801633D4u: goto label_801633D4;
    case 0x801633D8u: goto label_801633D8;
    case 0x801633DCu: goto label_801633DC;
    case 0x801633E0u: goto label_801633E0;
    case 0x801633E4u: goto label_801633E4;
    case 0x801633E8u: goto label_801633E8;
    case 0x801633ECu: goto label_801633EC;
    case 0x801633F0u: goto label_801633F0;
    case 0x801633F4u: goto label_801633F4;
    case 0x801633F8u: goto label_801633F8;
    case 0x801633FCu: goto label_801633FC;
    case 0x80163400u: goto label_80163400;
    case 0x80163404u: goto label_80163404;
    case 0x80163408u: goto label_80163408;
    case 0x8016340Cu: goto label_8016340C;
    case 0x80163410u: goto label_80163410;
    case 0x80163414u: goto label_80163414;
    case 0x80163418u: goto label_80163418;
    case 0x8016341Cu: goto label_8016341C;
    case 0x80163420u: goto label_80163420;
    case 0x80163424u: goto label_80163424;
    case 0x80163428u: goto label_80163428;
    case 0x8016342Cu: goto label_8016342C;
    case 0x80163430u: goto label_80163430;
    case 0x80163434u: goto label_80163434;
    case 0x80163438u: goto label_80163438;
    case 0x8016343Cu: goto label_8016343C;
    case 0x80163440u: goto label_80163440;
    case 0x80163444u: goto label_80163444;
    case 0x80163448u: goto label_80163448;
    case 0x8016344Cu: goto label_8016344C;
    case 0x80163450u: goto label_80163450;
    case 0x80163454u: goto label_80163454;
    case 0x80163458u: goto label_80163458;
    case 0x8016345Cu: goto label_8016345C;
    case 0x80163460u: goto label_80163460;
    case 0x80163464u: goto label_80163464;
    case 0x80163468u: goto label_80163468;
    case 0x8016346Cu: goto label_8016346C;
    case 0x80163470u: goto label_80163470;
    case 0x80163474u: goto label_80163474;
    case 0x80163478u: goto label_80163478;
    case 0x8016347Cu: goto label_8016347C;
    case 0x80163480u: goto label_80163480;
    case 0x80163484u: goto label_80163484;
    case 0x80163488u: goto label_80163488;
    case 0x8016348Cu: goto label_8016348C;
    case 0x80163490u: goto label_80163490;
    case 0x80163494u: goto label_80163494;
    case 0x80163498u: goto label_80163498;
    case 0x8016349Cu: goto label_8016349C;
    case 0x801634A0u: goto label_801634A0;
    case 0x801634A4u: goto label_801634A4;
    case 0x801634A8u: goto label_801634A8;
    case 0x801634ACu: goto label_801634AC;
    case 0x801634B0u: goto label_801634B0;
    case 0x801634B4u: goto label_801634B4;
    case 0x801634B8u: goto label_801634B8;
    case 0x801634BCu: goto label_801634BC;
    default: return;
    }
label_8015F4C0:
    ctx->pc = 0x8015F4C0u;
    ctx->downcount -= 9;
    // 8015F4C0: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_8015F4C4:
    ctx->pc = 0x8015F4C4u;
    // 8015F4C4: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8015F4C8:
    ctx->pc = 0x8015F4C8u;
    // 8015F4C8: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8015F4CC:
    ctx->pc = 0x8015F4CCu;
    // 8015F4CC: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F4D0:
    ctx->pc = 0x8015F4D0u;
    // 8015F4D0: b       0x8015F588
    {
            goto label_8015F588;
    }

label_8015F4D4:
    ctx->pc = 0x8015F4D4u;
    ctx->downcount -= 8;
    // 8015F4D4: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015F4D8:
    ctx->pc = 0x8015F4D8u;
    // 8015F4D8: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8015F4DC:
    ctx->pc = 0x8015F4DCu;
    // 8015F4DC: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F4E0:
    ctx->pc = 0x8015F4E0u;
    // 8015F4E0: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_8015F4E4:
    ctx->pc = 0x8015F4E4u;
    // 8015F4E4: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_8015F4E8:
    ctx->pc = 0x8015F4E8u;
    // 8015F4E8: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_8015F4EC:
    ctx->pc = 0x8015F4ECu;
    // 8015F4EC: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_8015F4F0:
    ctx->pc = 0x8015F4F0u;
    // 8015F4F0: bc    12, 2, 0x8015F510
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015F510;
        }
    }

label_8015F4F4:
    ctx->pc = 0x8015F4F4u;
    ctx->downcount -= 7;
    // 8015F4F4: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_8015F4F8:
    ctx->pc = 0x8015F4F8u;
    // 8015F4F8: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_8015F4FC:
    ctx->pc = 0x8015F4FCu;
    // 8015F4FC: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_8015F500:
    ctx->pc = 0x8015F500u;
    // 8015F500: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_8015F504:
    ctx->pc = 0x8015F504u;
    // 8015F504: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015F508:
    ctx->pc = 0x8015F508u;
    // 8015F508: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8015F50C:
    ctx->pc = 0x8015F50Cu;
    // 8015F50C: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8015F510:
    ctx->pc = 0x8015F510u;
    ctx->downcount -= 2;
    // 8015F510: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8015F514:
    ctx->pc = 0x8015F514u;
    // 8015F514: bl      0x80281C60
    {
            ctx->lr = 0x8015F518u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8015F518:
    ctx->pc = 0x8015F518u;
    ctx->downcount -= 3;
    // 8015F518: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F51C:
    ctx->pc = 0x8015F51Cu;
    // 8015F51C: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8015F520:
    ctx->pc = 0x8015F520u;
    // 8015F520: bc    4, 2, 0x8015F56C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8015F56C;
        }
    }

label_8015F524:
    ctx->pc = 0x8015F524u;
    ctx->downcount -= 3;
    // 8015F524: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8015F528:
    ctx->pc = 0x8015F528u;
    // 8015F528: cmplwi  r11, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F52C:
    ctx->pc = 0x8015F52Cu;
    // 8015F52C: bc    12, 1, 0x8015F558
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015F558;
        }
    }

label_8015F530:
    ctx->pc = 0x8015F530u;
    ctx->downcount -= 2;
    // 8015F530: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_8015F534:
    ctx->pc = 0x8015F534u;
    // 8015F534: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_8015F538:
    ctx->downcount -= 5;
    // 8015F538: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_8015F53C:
    // 8015F53C: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_8015F540:
    ctx->pc = 0x8015F540u;
    // 8015F540: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8015F544:
    // 8015F544: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F548:
    // 8015F548: bc    4, 2, 0x8015F498
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x8015F498u;
            return;
        }
    }

label_8015F54C:
    ctx->downcount -= 3;
    // 8015F54C: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_8015F550:
    // 8015F550: cmplwi  r11, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F554:
    // 8015F554: bc    4, 1, 0x8015F538
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8015F538u;
                return;
            }
            goto label_8015F538;
        }
    }

label_8015F558:
    ctx->pc = 0x8015F558u;
    ctx->downcount -= 4;
    // 8015F558: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8015F55C:
    ctx->pc = 0x8015F55Cu;
    // 8015F55C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8015F560:
    ctx->pc = 0x8015F560u;
    // 8015F560: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F564:
    ctx->pc = 0x8015F564u;
    // 8015F564: bl      0x80281C60
    {
            ctx->lr = 0x8015F568u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8015F568:
    ctx->pc = 0x8015F568u;
    ctx->downcount -= 1;
    // 8015F568: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8015F56C:
    ctx->pc = 0x8015F56Cu;
    ctx->downcount -= 7;
    // 8015F56C: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015F570:
    ctx->pc = 0x8015F570u;
    // 8015F570: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015F574:
    ctx->pc = 0x8015F574u;
    // 8015F574: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8015F578:
    ctx->pc = 0x8015F578u;
    // 8015F578: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8015F57C:
    ctx->pc = 0x8015F57Cu;
    // 8015F57C: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F580:
    ctx->pc = 0x8015F580u;
    // 8015F580: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8015F584:
    ctx->pc = 0x8015F584u;
    // 8015F584: b       0x8015F470
    {
            ctx->pc = 0x8015F470u;
            return;
    }

label_8015F588:
    ctx->pc = 0x8015F588u;
    ctx->downcount -= 16;
    // 8015F588: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015F58C:
    ctx->pc = 0x8015F58Cu;
    // 8015F58C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015F590:
    ctx->pc = 0x8015F590u;
    // 8015F590: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8015F594:
    ctx->pc = 0x8015F594u;
    // 8015F594: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8015F598:
    ctx->pc = 0x8015F598u;
    // 8015F598: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015F59C:
    ctx->pc = 0x8015F59Cu;
    ctx->downcount -= 21;
    // 8015F59C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015F5A0:
    ctx->pc = 0x8015F5A0u;
    // 8015F5A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015F5A4:
    ctx->pc = 0x8015F5A4u;
    // 8015F5A4: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8015F5A8:
    ctx->pc = 0x8015F5A8u;
    // 8015F5A8: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F5AC:
    ctx->pc = 0x8015F5ACu;
    // 8015F5AC: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_8015F5B0:
    ctx->pc = 0x8015F5B0u;
    // 8015F5B0: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_8015F5B4:
    ctx->pc = 0x8015F5B4u;
    // 8015F5B4: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_8015F5B8:
    ctx->pc = 0x8015F5B8u;
    // 8015F5B8: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_8015F5BC:
    ctx->pc = 0x8015F5BCu;
    // 8015F5BC: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8015F5C0:
    ctx->pc = 0x8015F5C0u;
    // 8015F5C0: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F5C4:
    ctx->pc = 0x8015F5C4u;
    // 8015F5C4: bc    12, 2, 0x8015F5D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015F5D4;
        }
    }

label_8015F5C8:
    ctx->pc = 0x8015F5C8u;
    ctx->downcount -= 3;
    // 8015F5C8: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015F5CC:
    ctx->pc = 0x8015F5CCu;
    // 8015F5CC: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F5D0:
    ctx->pc = 0x8015F5D0u;
    // 8015F5D0: b       0x8015F654
    {
            goto label_8015F654;
    }

label_8015F5D4:
    ctx->pc = 0x8015F5D4u;
    ctx->downcount -= 7;
    // 8015F5D4: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_8015F5D8:
    ctx->pc = 0x8015F5D8u;
    // 8015F5D8: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_8015F5DC:
    ctx->pc = 0x8015F5DCu;
    // 8015F5DC: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_8015F5E0:
    ctx->pc = 0x8015F5E0u;
    // 8015F5E0: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8015F5E4:
    ctx->pc = 0x8015F5E4u;
    // 8015F5E4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8015F5E8:
    ctx->pc = 0x8015F5E8u;
    // 8015F5E8: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_8015F5EC:
    ctx->pc = 0x8015F5ECu;
    // 8015F5EC: bl      0x80003EE0
    {
            ctx->lr = 0x8015F5F0u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_8015F5F0:
    ctx->pc = 0x8015F5F0u;
    ctx->downcount -= 3;
    // 8015F5F0: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015F5F4:
    ctx->pc = 0x8015F5F4u;
    // 8015F5F4: cmpwi   r9, 1
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F5F8:
    ctx->pc = 0x8015F5F8u;
    // 8015F5F8: bc    12, 2, 0x8015F650
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015F650;
        }
    }

label_8015F5FC:
    ctx->pc = 0x8015F5FCu;
    ctx->downcount -= 9;
    // 8015F5FC: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_8015F600:
    ctx->pc = 0x8015F600u;
    // 8015F600: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_8015F604:
    ctx->pc = 0x8015F604u;
    // 8015F604: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_8015F608:
    ctx->pc = 0x8015F608u;
    // 8015F608: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8015F60C:
    ctx->pc = 0x8015F60Cu;
    // 8015F60C: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8015F610:
    ctx->pc = 0x8015F610u;
    // 8015F610: cmpwi   r9, 2
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F614:
    ctx->pc = 0x8015F614u;
    // 8015F614: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8015F618:
    ctx->pc = 0x8015F618u;
    // 8015F618: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_8015F61C:
    ctx->pc = 0x8015F61Cu;
    // 8015F61C: bc    4, 2, 0x8015F628
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8015F628;
        }
    }

label_8015F620:
    ctx->pc = 0x8015F620u;
    ctx->downcount -= 2;
    // 8015F620: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8015F624:
    ctx->pc = 0x8015F624u;
    // 8015F624: b       0x8015F650
    {
            goto label_8015F650;
    }

label_8015F628:
    loop_8015F628(ctx);
    if (ctx->pc == 0x8015F648u) goto label_8015F648;
    return;
label_8015F62C:
    // 8015F62C: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_8015F630:
    // 8015F630: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8015F634:
    ctx->pc = 0x8015F634u;
    // 8015F634: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015F638:
    // 8015F638: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_8015F63C:
    // 8015F63C: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_8015F640:
    // 8015F640: cmpw    r9, r8
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F644:
    // 8015F644: bc    4, 2, 0x8015F628
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8015F628u;
                return;
            }
            goto label_8015F628;
        }
    }

label_8015F648:
    ctx->pc = 0x8015F648u;
    ctx->downcount -= 2;
    // 8015F648: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8015F64C:
    ctx->pc = 0x8015F64Cu;
    // 8015F64C: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F650:
    ctx->pc = 0x8015F650u;
    ctx->downcount -= 1;
    // 8015F650: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015F654:
    ctx->pc = 0x8015F654u;
    ctx->downcount -= 17;
    // 8015F654: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8015F658:
    ctx->pc = 0x8015F658u;
    // 8015F658: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015F65C:
    ctx->pc = 0x8015F65Cu;
    // 8015F65C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015F660:
    ctx->pc = 0x8015F660u;
    // 8015F660: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8015F664:
    ctx->pc = 0x8015F664u;
    // 8015F664: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8015F668:
    ctx->pc = 0x8015F668u;
    // 8015F668: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015F66C:
    ctx->pc = 0x8015F66Cu;
    ctx->downcount -= 7;
    // 8015F66C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015F670:
    ctx->pc = 0x8015F670u;
    // 8015F670: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015F674:
    ctx->pc = 0x8015F674u;
    // 8015F674: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F678:
    ctx->pc = 0x8015F678u;
    // 8015F678: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8015F67C:
    ctx->pc = 0x8015F67Cu;
    // 8015F67C: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_8015F680:
    ctx->pc = 0x8015F680u;
    // 8015F680: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F684:
    ctx->pc = 0x8015F684u;
    // 8015F684: bc    4, 2, 0x8015F780
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8015F780;
        }
    }

label_8015F688:
    ctx->pc = 0x8015F688u;
    ctx->downcount -= 2;
    // 8015F688: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F68C:
    ctx->pc = 0x8015F68Cu;
    // 8015F68C: bc    12, 2, 0x8015F780
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015F780;
        }
    }

label_8015F690:
    ctx->pc = 0x8015F690u;
    ctx->downcount -= 5;
    // 8015F690: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_8015F694:
    ctx->pc = 0x8015F694u;
    // 8015F694: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_8015F698:
    ctx->pc = 0x8015F698u;
    // 8015F698: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_8015F69C:
    ctx->pc = 0x8015F69Cu;
    // 8015F69C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8015F6A0:
    ctx->pc = 0x8015F6A0u;
    // 8015F6A0: bl      0x80252AF0
    {
            ctx->lr = 0x8015F6A4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F6A4:
    ctx->pc = 0x8015F6A4u;
    ctx->downcount -= 5;
    // 8015F6A4: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_8015F6A8:
    ctx->pc = 0x8015F6A8u;
    // 8015F6A8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8015F6AC:
    ctx->pc = 0x8015F6ACu;
    // 8015F6AC: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_8015F6B0:
    ctx->pc = 0x8015F6B0u;
    // 8015F6B0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8015F6B4:
    ctx->pc = 0x8015F6B4u;
    // 8015F6B4: bl      0x80252AF0
    {
            ctx->lr = 0x8015F6B8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F6B8:
    ctx->pc = 0x8015F6B8u;
    ctx->downcount -= 5;
    // 8015F6B8: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_8015F6BC:
    ctx->pc = 0x8015F6BCu;
    // 8015F6BC: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_8015F6C0:
    ctx->pc = 0x8015F6C0u;
    // 8015F6C0: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_8015F6C4:
    ctx->pc = 0x8015F6C4u;
    // 8015F6C4: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_8015F6C8:
    ctx->pc = 0x8015F6C8u;
    // 8015F6C8: bl      0x80252AF0
    {
            ctx->lr = 0x8015F6CCu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F6CC:
    ctx->pc = 0x8015F6CCu;
    ctx->downcount -= 5;
    // 8015F6CC: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_8015F6D0:
    ctx->pc = 0x8015F6D0u;
    // 8015F6D0: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_8015F6D4:
    ctx->pc = 0x8015F6D4u;
    // 8015F6D4: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_8015F6D8:
    ctx->pc = 0x8015F6D8u;
    // 8015F6D8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8015F6DC:
    ctx->pc = 0x8015F6DCu;
    // 8015F6DC: bl      0x80252AF0
    {
            ctx->lr = 0x8015F6E0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F6E0:
    ctx->pc = 0x8015F6E0u;
    ctx->downcount -= 5;
    // 8015F6E0: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_8015F6E4:
    ctx->pc = 0x8015F6E4u;
    // 8015F6E4: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_8015F6E8:
    ctx->pc = 0x8015F6E8u;
    // 8015F6E8: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_8015F6EC:
    ctx->pc = 0x8015F6ECu;
    // 8015F6EC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8015F6F0:
    ctx->pc = 0x8015F6F0u;
    // 8015F6F0: bl      0x80252AF0
    {
            ctx->lr = 0x8015F6F4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F6F4:
    ctx->pc = 0x8015F6F4u;
    ctx->downcount -= 5;
    // 8015F6F4: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_8015F6F8:
    ctx->pc = 0x8015F6F8u;
    // 8015F6F8: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8015F6FC:
    ctx->pc = 0x8015F6FCu;
    // 8015F6FC: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_8015F700:
    ctx->pc = 0x8015F700u;
    // 8015F700: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8015F704:
    ctx->pc = 0x8015F704u;
    // 8015F704: bl      0x80252AF0
    {
            ctx->lr = 0x8015F708u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F708:
    ctx->pc = 0x8015F708u;
    ctx->downcount -= 5;
    // 8015F708: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_8015F70C:
    ctx->pc = 0x8015F70Cu;
    // 8015F70C: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8015F710:
    ctx->pc = 0x8015F710u;
    // 8015F710: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_8015F714:
    ctx->pc = 0x8015F714u;
    // 8015F714: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8015F718:
    ctx->pc = 0x8015F718u;
    // 8015F718: bl      0x80252AF0
    {
            ctx->lr = 0x8015F71Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F71C:
    ctx->pc = 0x8015F71Cu;
    ctx->downcount -= 5;
    // 8015F71C: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_8015F720:
    ctx->pc = 0x8015F720u;
    // 8015F720: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_8015F724:
    ctx->pc = 0x8015F724u;
    // 8015F724: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_8015F728:
    ctx->pc = 0x8015F728u;
    // 8015F728: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8015F72C:
    ctx->pc = 0x8015F72Cu;
    // 8015F72C: bl      0x80252AF0
    {
            ctx->lr = 0x8015F730u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F730:
    ctx->pc = 0x8015F730u;
    ctx->downcount -= 5;
    // 8015F730: lis     r3, 25197
    ctx->gpr[3] = ((u32)(s32)(25197) << 16);

label_8015F734:
    ctx->pc = 0x8015F734u;
    // 8015F734: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_8015F738:
    ctx->pc = 0x8015F738u;
    // 8015F738: ori     r3, r3, 0x7368
    ctx->gpr[3] = ctx->gpr[3] | 0x7368u;

label_8015F73C:
    ctx->pc = 0x8015F73Cu;
    // 8015F73C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8015F740:
    ctx->pc = 0x8015F740u;
    // 8015F740: bl      0x80252AF0
    {
            ctx->lr = 0x8015F744u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F744:
    ctx->pc = 0x8015F744u;
    ctx->downcount -= 5;
    // 8015F744: lis     r3, 25199
    ctx->gpr[3] = ((u32)(s32)(25199) << 16);

label_8015F748:
    ctx->pc = 0x8015F748u;
    // 8015F748: li      r4, 63
    ctx->gpr[4] = (u32)(s32)(63);

label_8015F74C:
    ctx->pc = 0x8015F74Cu;
    // 8015F74C: ori     r3, r3, 0x6479
    ctx->gpr[3] = ctx->gpr[3] | 0x6479u;

label_8015F750:
    ctx->pc = 0x8015F750u;
    // 8015F750: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8015F754:
    ctx->pc = 0x8015F754u;
    // 8015F754: bl      0x80252AF0
    {
            ctx->lr = 0x8015F758u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F758:
    ctx->pc = 0x8015F758u;
    ctx->downcount -= 5;
    // 8015F758: lis     r3, 25185
    ctx->gpr[3] = ((u32)(s32)(25185) << 16);

label_8015F75C:
    ctx->pc = 0x8015F75Cu;
    // 8015F75C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8015F760:
    ctx->pc = 0x8015F760u;
    // 8015F760: ori     r3, r3, 0x6E6D
    ctx->gpr[3] = ctx->gpr[3] | 0x6E6Du;

label_8015F764:
    ctx->pc = 0x8015F764u;
    // 8015F764: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8015F768:
    ctx->pc = 0x8015F768u;
    // 8015F768: bl      0x80252AF0
    {
            ctx->lr = 0x8015F76Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F76C:
    ctx->pc = 0x8015F76Cu;
    ctx->downcount -= 5;
    // 8015F76C: lis     r3, 27749
    ctx->gpr[3] = ((u32)(s32)(27749) << 16);

label_8015F770:
    ctx->pc = 0x8015F770u;
    // 8015F770: li      r4, 86
    ctx->gpr[4] = (u32)(s32)(86);

label_8015F774:
    ctx->pc = 0x8015F774u;
    // 8015F774: ori     r3, r3, 0x766C
    ctx->gpr[3] = ctx->gpr[3] | 0x766Cu;

label_8015F778:
    ctx->pc = 0x8015F778u;
    // 8015F778: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8015F77C:
    ctx->pc = 0x8015F77Cu;
    // 8015F77C: bl      0x80252AF0
    {
            ctx->lr = 0x8015F780u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8015F780:
    ctx->pc = 0x8015F780u;
    ctx->downcount -= 5;
    // 8015F780: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015F784:
    ctx->pc = 0x8015F784u;
    // 8015F784: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015F788:
    ctx->pc = 0x8015F788u;
    // 8015F788: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8015F78C:
    ctx->pc = 0x8015F78Cu;
    // 8015F78C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015F790:
    ctx->pc = 0x8015F790u;
    ctx->downcount -= 2;
    // 8015F790: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8015F794:
    ctx->pc = 0x8015F794u;
    // 8015F794: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015F798:
    ctx->pc = 0x8015F798u;
    ctx->downcount -= 2;
    // 8015F798: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8015F79C:
    ctx->pc = 0x8015F79Cu;
    // 8015F79C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015F7A0:
    ctx->pc = 0x8015F7A0u;
    ctx->downcount -= 10;
    // 8015F7A0: stwu     r1, -280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-280);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015F7A4:
    ctx->pc = 0x8015F7A4u;
    // 8015F7A4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015F7A8:
    ctx->pc = 0x8015F7A8u;
    // 8015F7A8: stw     r31, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8015F7AC:
    ctx->pc = 0x8015F7ACu;
    // 8015F7AC: stw     r0, 284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(284);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F7B0:
    ctx->pc = 0x8015F7B0u;
    // 8015F7B0: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8015F7B4:
    ctx->pc = 0x8015F7B4u;
    // 8015F7B4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015F7B8:
    ctx->pc = 0x8015F7B8u;
    // 8015F7B8: addi    r4, r9, -28192
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(-28192);

label_8015F7BC:
    ctx->pc = 0x8015F7BCu;
    // 8015F7BC: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8015F7C0:
    ctx->pc = 0x8015F7C0u;
    // 8015F7C0: cmpwi   r4, 0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015F7C4:
    ctx->pc = 0x8015F7C4u;
    // 8015F7C4: bc    12, 2, 0x8015F7D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015F7D4;
        }
    }

label_8015F7C8:
    ctx->pc = 0x8015F7C8u;
    ctx->downcount -= 2;
    // 8015F7C8: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_8015F7CC:
    ctx->pc = 0x8015F7CCu;
    // 8015F7CC: bl      0x80287F10
    {
            ctx->lr = 0x8015F7D0u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_8015F7D0:
    ctx->pc = 0x8015F7D0u;
    ctx->downcount -= 1;
    // 8015F7D0: b       0x8015F7D8
    {
            goto label_8015F7D8;
    }

label_8015F7D4:
    ctx->pc = 0x8015F7D4u;
    ctx->downcount -= 1;
    // 8015F7D4: stb     r4, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8015F7D8:
    ctx->pc = 0x8015F7D8u;
    ctx->downcount -= 6;
    // 8015F7D8: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8015F7DC:
    ctx->pc = 0x8015F7DCu;
    // 8015F7DC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8015F7E0:
    ctx->pc = 0x8015F7E0u;
    // 8015F7E0: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8015F7E4:
    ctx->pc = 0x8015F7E4u;
    // 8015F7E4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8015F7E8:
    ctx->pc = 0x8015F7E8u;
    // 8015F7E8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8015F7EC:
    ctx->pc = 0x8015F7ECu;
    // 8015F7EC: bl      0x8015A93C
    {
            ctx->lr = 0x8015F7F0u;
            ctx->pc = 0x8015A93Cu;
            return;
    }

label_8015F7F0:
    ctx->pc = 0x8015F7F0u;
    ctx->downcount -= 14;
    // 8015F7F0: lis     r11, -32720
    ctx->gpr[11] = ((u32)(s32)(-32720) << 16);

label_8015F7F4:
    ctx->pc = 0x8015F7F4u;
    // 8015F7F4: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8015F7F8:
    ctx->pc = 0x8015F7F8u;
    // 8015F7F8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8015F7FC:
    ctx->pc = 0x8015F7FCu;
    // 8015F7FC: addi    r9, r9, -27920
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27920);

label_8015F800:
    ctx->pc = 0x8015F800u;
    // 8015F800: lfs     f1, -27648(r11)
    if (!ppc_fp_available_inline(ctx, 0x8015F800u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-27648);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8015F804:
    ctx->pc = 0x8015F804u;
    // 8015F804: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8015F808:
    ctx->pc = 0x8015F808u;
    // 8015F808: stw     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8015F80C:
    ctx->pc = 0x8015F80Cu;
    // 8015F80C: stw     r0, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F810:
    ctx->pc = 0x8015F810u;
    // 8015F810: stw     r0, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F814:
    ctx->pc = 0x8015F814u;
    // 8015F814: stw     r0, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F818:
    ctx->pc = 0x8015F818u;
    // 8015F818: stw     r0, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F81C:
    ctx->pc = 0x8015F81Cu;
    // 8015F81C: stw     r0, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F820:
    ctx->pc = 0x8015F820u;
    // 8015F820: stw     r0, 700(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F824:
    ctx->pc = 0x8015F824u;
    // 8015F824: bl      0x8015C028
    {
            ctx->lr = 0x8015F828u;
            ctx->pc = 0x8015C028u;
            return;
    }

label_8015F828:
    ctx->pc = 0x8015F828u;
    ctx->downcount -= 7;
    // 8015F828: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8015F82C:
    ctx->pc = 0x8015F82Cu;
    // 8015F82C: lwz     r0, 284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(284);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015F830:
    ctx->pc = 0x8015F830u;
    // 8015F830: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015F834:
    ctx->pc = 0x8015F834u;
    // 8015F834: lwz     r31, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8015F838:
    ctx->pc = 0x8015F838u;
    // 8015F838: addi    r1, r1, 280
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(280);

label_8015F83C:
    ctx->pc = 0x8015F83Cu;
    // 8015F83C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015F840:
    ctx->pc = 0x8015F840u;
    ctx->downcount -= 20;
    // 8015F840: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015F844:
    ctx->pc = 0x8015F844u;
    // 8015F844: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015F848:
    ctx->pc = 0x8015F848u;
    // 8015F848: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8015F84C:
    ctx->pc = 0x8015F84Cu;
    // 8015F84C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F850:
    ctx->pc = 0x8015F850u;
    // 8015F850: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8015F854:
    ctx->pc = 0x8015F854u;
    // 8015F854: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015F858:
    ctx->pc = 0x8015F858u;
    // 8015F858: addi    r9, r9, -27920
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27920);

label_8015F85C:
    ctx->pc = 0x8015F85Cu;
    // 8015F85C: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8015F860:
    ctx->pc = 0x8015F860u;
    // 8015F860: stw     r9, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8015F864:
    ctx->pc = 0x8015F864u;
    // 8015F864: bl      0x8015FA30
    {
            ctx->lr = 0x8015F868u;
            goto label_8015FA30;
    }

label_8015F868:
    ctx->pc = 0x8015F868u;
    ctx->downcount -= 2;
    // 8015F868: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8015F86C:
    ctx->pc = 0x8015F86Cu;
    // 8015F86C: bl      0x800FBC64
    {
            ctx->lr = 0x8015F870u;
            ctx->pc = 0x800FBC64u;
            return;
    }

label_8015F870:
    ctx->pc = 0x8015F870u;
    ctx->downcount -= 1;
    // 8015F870: bl      0x8019D2B0
    {
            ctx->lr = 0x8015F874u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_8015F874:
    ctx->pc = 0x8015F874u;
    ctx->downcount -= 3;
    // 8015F874: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015F878:
    ctx->pc = 0x8015F878u;
    // 8015F878: lwz     r4, 696(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8015F87C:
    ctx->pc = 0x8015F87Cu;
    // 8015F87C: bl      0x8019AC1C
    {
            ctx->lr = 0x8015F880u;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_8015F880:
    ctx->pc = 0x8015F880u;
    ctx->downcount -= 3;
    // 8015F880: lwz     r4, 700(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(700);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8015F884:
    ctx->pc = 0x8015F884u;
    // 8015F884: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8015F888:
    ctx->pc = 0x8015F888u;
    // 8015F888: bl      0x8019AC1C
    {
            ctx->lr = 0x8015F88Cu;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_8015F88C:
    ctx->pc = 0x8015F88Cu;
    ctx->downcount -= 5;
    // 8015F88C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8015F890:
    ctx->pc = 0x8015F890u;
    // 8015F890: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8015F894:
    ctx->pc = 0x8015F894u;
    // 8015F894: stw     r0, 700(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F898:
    ctx->pc = 0x8015F898u;
    // 8015F898: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8015F89C:
    ctx->pc = 0x8015F89Cu;
    // 8015F89C: bl      0x8015AE74
    {
            ctx->lr = 0x8015F8A0u;
            ctx->pc = 0x8015AE74u;
            return;
    }

label_8015F8A0:
    ctx->pc = 0x8015F8A0u;
    ctx->downcount -= 16;
    // 8015F8A0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015F8A4:
    ctx->pc = 0x8015F8A4u;
    // 8015F8A4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015F8A8:
    ctx->pc = 0x8015F8A8u;
    // 8015F8A8: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8015F8AC:
    ctx->pc = 0x8015F8ACu;
    // 8015F8AC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8015F8B0:
    ctx->pc = 0x8015F8B0u;
    // 8015F8B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015F8B4:
    ctx->pc = 0x8015F8B4u;
    ctx->downcount -= 18;
    // 8015F8B4: stwu     r1, -152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-152);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015F8B8:
    ctx->pc = 0x8015F8B8u;
    // 8015F8B8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015F8BC:
    ctx->pc = 0x8015F8BCu;
    // 8015F8BC: stw     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8015F8C0:
    ctx->pc = 0x8015F8C0u;
    // 8015F8C0: stw     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F8C4:
    ctx->pc = 0x8015F8C4u;
    // 8015F8C4: lis     r12, 512
    ctx->gpr[12] = ((u32)(s32)(512) << 16);

label_8015F8C8:
    ctx->pc = 0x8015F8C8u;
    // 8015F8C8: addi    r0, r1, 160
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(160);

label_8015F8CC:
    ctx->pc = 0x8015F8CCu;
    // 8015F8CC: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_8015F8D0:
    ctx->pc = 0x8015F8D0u;
    // 8015F8D0: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F8D4:
    ctx->pc = 0x8015F8D4u;
    // 8015F8D4: stw     r11, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8015F8D8:
    ctx->pc = 0x8015F8D8u;
    // 8015F8D8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015F8DC:
    ctx->pc = 0x8015F8DCu;
    // 8015F8DC: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8015F8E0:
    ctx->pc = 0x8015F8E0u;
    // 8015F8E0: stw     r6, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8015F8E4:
    ctx->pc = 0x8015F8E4u;
    // 8015F8E4: stw     r7, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8015F8E8:
    ctx->pc = 0x8015F8E8u;
    // 8015F8E8: stw     r8, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8015F8EC:
    ctx->pc = 0x8015F8ECu;
    // 8015F8EC: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8015F8F0:
    ctx->pc = 0x8015F8F0u;
    // 8015F8F0: stw     r10, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8015F8F4:
    ctx->pc = 0x8015F8F4u;
    // 8015F8F4: stw     r12, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8015F8F8:
    ctx->pc = 0x8015F8F8u;
    // 8015F8F8: bc    4, 6, 0x8015F91C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x02000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8015F91C;
        }
    }

label_8015F8FC:
    ctx->pc = 0x8015F8FCu;
    ctx->downcount -= 8;
    // 8015F8FC: stfd     f1, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015F8FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_8015F900:
    ctx->pc = 0x8015F900u;
    // 8015F900: stfd     f2, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015F900u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_8015F904:
    ctx->pc = 0x8015F904u;
    // 8015F904: stfd     f3, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015F904u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_8015F908:
    ctx->pc = 0x8015F908u;
    // 8015F908: stfd     f4, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015F908u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_8015F90C:
    ctx->pc = 0x8015F90Cu;
    // 8015F90C: stfd     f5, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015F90Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_8015F910:
    ctx->pc = 0x8015F910u;
    // 8015F910: stfd     f6, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015F910u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_8015F914:
    ctx->pc = 0x8015F914u;
    // 8015F914: stfd     f7, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015F914u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_8015F918:
    ctx->pc = 0x8015F918u;
    // 8015F918: stfd     f8, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015F918u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
    }

label_8015F91C:
    ctx->pc = 0x8015F91Cu;
    ctx->downcount -= 12;
    // 8015F91C: addi    r11, r1, 128
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(128);

label_8015F920:
    ctx->pc = 0x8015F920u;
    // 8015F920: addi    r9, r1, 112
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(112);

label_8015F924:
    ctx->pc = 0x8015F924u;
    // 8015F924: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015F928:
    ctx->pc = 0x8015F928u;
    // 8015F928: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8015F92C:
    ctx->pc = 0x8015F92Cu;
    // 8015F92C: lwz     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8015F930:
    ctx->pc = 0x8015F930u;
    // 8015F930: or   r6, r9, r9
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8015F934:
    ctx->pc = 0x8015F934u;
    // 8015F934: stw     r12, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8015F938:
    ctx->pc = 0x8015F938u;
    // 8015F938: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8015F93C:
    ctx->pc = 0x8015F93Cu;
    // 8015F93C: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F940:
    ctx->pc = 0x8015F940u;
    // 8015F940: li      r4, 260
    ctx->gpr[4] = (u32)(s32)(260);

label_8015F944:
    ctx->pc = 0x8015F944u;
    // 8015F944: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8015F948:
    ctx->pc = 0x8015F948u;
    // 8015F948: bl      0x80296720
    {
            ctx->lr = 0x8015F94Cu;
            ctx->pc = 0x80296720u;
            return;
    }

label_8015F94C:
    ctx->pc = 0x8015F94Cu;
    ctx->downcount -= 8;
    // 8015F94C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8015F950:
    ctx->pc = 0x8015F950u;
    // 8015F950: stb     r0, 259(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(259);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8015F954:
    ctx->pc = 0x8015F954u;
    // 8015F954: lwz     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015F958:
    ctx->pc = 0x8015F958u;
    // 8015F958: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015F95C:
    ctx->pc = 0x8015F95Cu;
    // 8015F95C: lwz     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8015F960:
    ctx->pc = 0x8015F960u;
    // 8015F960: addi    r1, r1, 152
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(152);

label_8015F964:
    ctx->pc = 0x8015F964u;
    // 8015F964: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015F968:
    ctx->pc = 0x8015F968u;
    ctx->downcount -= 17;
    // 8015F968: stwu     r1, -296(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-296);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015F96C:
    ctx->pc = 0x8015F96Cu;
    // 8015F96C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015F970:
    ctx->pc = 0x8015F970u;
    // 8015F970: stmw     r27, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8015F974:
    ctx->pc = 0x8015F974u;
    // 8015F974: stw     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015F978:
    ctx->pc = 0x8015F978u;
    // 8015F978: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015F97C:
    ctx->pc = 0x8015F97Cu;
    // 8015F97C: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_8015F980:
    ctx->pc = 0x8015F980u;
    // 8015F980: bl      0x8019D2B0
    {
            ctx->lr = 0x8015F984u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_8015F984:
    ctx->pc = 0x8015F984u;
    ctx->downcount -= 4;
    // 8015F984: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015F988:
    ctx->pc = 0x8015F988u;
    // 8015F988: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_8015F98C:
    ctx->pc = 0x8015F98Cu;
    // 8015F98C: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_8015F990:
    ctx->pc = 0x8015F990u;
    // 8015F990: bl      0x80100A40
    {
            ctx->lr = 0x8015F994u;
            ctx->pc = 0x80100A40u;
            return;
    }

label_8015F994:
    ctx->pc = 0x8015F994u;
    ctx->downcount -= 3;
    // 8015F994: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015F998:
    ctx->pc = 0x8015F998u;
    // 8015F998: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_8015F99C:
    ctx->pc = 0x8015F99Cu;
    // 8015F99C: bl      0x80100368
    {
            ctx->lr = 0x8015F9A0u;
            ctx->pc = 0x80100368u;
            return;
    }

label_8015F9A0:
    ctx->pc = 0x8015F9A0u;
    ctx->downcount -= 9;
    // 8015F9A0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8015F9A4:
    ctx->pc = 0x8015F9A4u;
    // 8015F9A4: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015F9A8:
    ctx->pc = 0x8015F9A8u;
    // 8015F9A8: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8015F9AC:
    ctx->pc = 0x8015F9ACu;
    // 8015F9AC: stb     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8015F9B0:
    ctx->pc = 0x8015F9B0u;
    // 8015F9B0: addi    r4, r4, -28060
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-28060);

label_8015F9B4:
    ctx->pc = 0x8015F9B4u;
    // 8015F9B4: addi    r5, r28, 392
    ctx->gpr[5] = ctx->gpr[28] + (u32)(s32)(392);

label_8015F9B8:
    ctx->pc = 0x8015F9B8u;
    // 8015F9B8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8015F9BC:
    ctx->pc = 0x8015F9BCu;
    // 8015F9BC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8015F9C0:
    ctx->pc = 0x8015F9C0u;
    // 8015F9C0: bl      0x8009258C
    {
            ctx->lr = 0x8015F9C4u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_8015F9C4:
    ctx->pc = 0x8015F9C4u;
    ctx->downcount -= 4;
    // 8015F9C4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8015F9C8:
    ctx->pc = 0x8015F9C8u;
    // 8015F9C8: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8015F9CC:
    ctx->pc = 0x8015F9CCu;
    // 8015F9CC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8015F9D0:
    ctx->pc = 0x8015F9D0u;
    // 8015F9D0: bl      0x8019A70C
    {
            ctx->lr = 0x8015F9D4u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_8015F9D4:
    ctx->pc = 0x8015F9D4u;
    ctx->downcount -= 5;
    // 8015F9D4: stw     r3, 696(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8015F9D8:
    ctx->pc = 0x8015F9D8u;
    // 8015F9D8: li      r4, 47
    ctx->gpr[4] = (u32)(s32)(47);

label_8015F9DC:
    ctx->pc = 0x8015F9DCu;
    // 8015F9DC: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_8015F9E0:
    ctx->pc = 0x8015F9E0u;
    // 8015F9E0: addi    r3, r3, -21808
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-21808);

label_8015F9E4:
    ctx->pc = 0x8015F9E4u;
    // 8015F9E4: bl      0x802980E0
    {
            ctx->lr = 0x8015F9E8u;
            ctx->pc = 0x802980E0u;
            return;
    }

label_8015F9E8:
    ctx->pc = 0x8015F9E8u;
    ctx->downcount -= 6;
    // 8015F9E8: addi    r5, r3, 1
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(1);

label_8015F9EC:
    ctx->pc = 0x8015F9ECu;
    // 8015F9EC: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8015F9F0:
    ctx->pc = 0x8015F9F0u;
    // 8015F9F0: addi    r4, r4, -28036
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-28036);

label_8015F9F4:
    ctx->pc = 0x8015F9F4u;
    // 8015F9F4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8015F9F8:
    ctx->pc = 0x8015F9F8u;
    // 8015F9F8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8015F9FC:
    ctx->pc = 0x8015F9FCu;
    // 8015F9FC: bl      0x8009258C
    {
            ctx->lr = 0x8015FA00u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_8015FA00:
    ctx->pc = 0x8015FA00u;
    ctx->downcount -= 4;
    // 8015FA00: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8015FA04:
    ctx->pc = 0x8015FA04u;
    // 8015FA04: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8015FA08:
    ctx->pc = 0x8015FA08u;
    // 8015FA08: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8015FA0C:
    ctx->pc = 0x8015FA0Cu;
    // 8015FA0C: bl      0x8019A70C
    {
            ctx->lr = 0x8015FA10u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_8015FA10:
    ctx->pc = 0x8015FA10u;
    ctx->downcount -= 19;
    // 8015FA10: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8015FA14:
    ctx->pc = 0x8015FA14u;
    // 8015FA14: stw     r3, 700(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8015FA18:
    ctx->pc = 0x8015FA18u;
    // 8015FA18: stw     r0, 312(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(312);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FA1C:
    ctx->pc = 0x8015FA1Cu;
    // 8015FA1C: lwz     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FA20:
    ctx->pc = 0x8015FA20u;
    // 8015FA20: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FA24:
    ctx->pc = 0x8015FA24u;
    // 8015FA24: lmw     r27, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8015FA28:
    ctx->pc = 0x8015FA28u;
    // 8015FA28: addi    r1, r1, 296
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(296);

label_8015FA2C:
    ctx->pc = 0x8015FA2Cu;
    // 8015FA2C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FA30:
    ctx->pc = 0x8015FA30u;
    ctx->downcount -= 18;
    // 8015FA30: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015FA34:
    ctx->pc = 0x8015FA34u;
    // 8015FA34: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015FA38:
    ctx->pc = 0x8015FA38u;
    // 8015FA38: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8015FA3C:
    ctx->pc = 0x8015FA3Cu;
    // 8015FA3C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FA40:
    ctx->pc = 0x8015FA40u;
    // 8015FA40: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015FA44:
    ctx->pc = 0x8015FA44u;
    // 8015FA44: lwz     r11, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015FA48:
    ctx->pc = 0x8015FA48u;
    // 8015FA48: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015FA4C:
    ctx->pc = 0x8015FA4Cu;
    // 8015FA4C: bc    12, 2, 0x8015FA6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015FA6C;
        }
    }

label_8015FA50:
    ctx->pc = 0x8015FA50u;
    ctx->downcount -= 8;
    // 8015FA50: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FA54:
    ctx->pc = 0x8015FA54u;
    // 8015FA54: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8015FA58:
    ctx->pc = 0x8015FA58u;
    // 8015FA58: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FA5C:
    ctx->pc = 0x8015FA5Cu;
    // 8015FA5C: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FA60:
    ctx->pc = 0x8015FA60u;
    // 8015FA60: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FA64:
    ctx->pc = 0x8015FA64u;
    // 8015FA64: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FA68:
    ctx->pc = 0x8015FA68u;
    // 8015FA68: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FA6Cu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FA6C:
    ctx->pc = 0x8015FA6Cu;
    ctx->downcount -= 5;
    // 8015FA6C: lwz     r11, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015FA70:
    ctx->pc = 0x8015FA70u;
    // 8015FA70: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8015FA74:
    ctx->pc = 0x8015FA74u;
    // 8015FA74: stw     r30, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8015FA78:
    ctx->pc = 0x8015FA78u;
    // 8015FA78: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015FA7C:
    ctx->pc = 0x8015FA7Cu;
    // 8015FA7C: bc    12, 2, 0x8015FA9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015FA9C;
        }
    }

label_8015FA80:
    ctx->pc = 0x8015FA80u;
    ctx->downcount -= 8;
    // 8015FA80: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FA84:
    ctx->pc = 0x8015FA84u;
    // 8015FA84: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8015FA88:
    ctx->pc = 0x8015FA88u;
    // 8015FA88: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FA8C:
    ctx->pc = 0x8015FA8Cu;
    // 8015FA8C: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FA90:
    ctx->pc = 0x8015FA90u;
    // 8015FA90: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FA94:
    ctx->pc = 0x8015FA94u;
    // 8015FA94: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FA98:
    ctx->pc = 0x8015FA98u;
    // 8015FA98: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FA9Cu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FA9C:
    ctx->pc = 0x8015FA9Cu;
    ctx->downcount -= 4;
    // 8015FA9C: lwz     r11, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015FAA0:
    ctx->pc = 0x8015FAA0u;
    // 8015FAA0: stw     r30, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8015FAA4:
    ctx->pc = 0x8015FAA4u;
    // 8015FAA4: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015FAA8:
    ctx->pc = 0x8015FAA8u;
    // 8015FAA8: bc    12, 2, 0x8015FAC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015FAC8;
        }
    }

label_8015FAAC:
    ctx->pc = 0x8015FAACu;
    ctx->downcount -= 8;
    // 8015FAAC: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FAB0:
    ctx->pc = 0x8015FAB0u;
    // 8015FAB0: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8015FAB4:
    ctx->pc = 0x8015FAB4u;
    // 8015FAB4: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FAB8:
    ctx->pc = 0x8015FAB8u;
    // 8015FAB8: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FABC:
    ctx->pc = 0x8015FABCu;
    // 8015FABC: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FAC0:
    ctx->pc = 0x8015FAC0u;
    // 8015FAC0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FAC4:
    ctx->pc = 0x8015FAC4u;
    // 8015FAC4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FAC8u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FAC8:
    ctx->pc = 0x8015FAC8u;
    ctx->downcount -= 17;
    // 8015FAC8: stw     r30, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8015FACC:
    ctx->pc = 0x8015FACCu;
    // 8015FACC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FAD0:
    ctx->pc = 0x8015FAD0u;
    // 8015FAD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FAD4:
    ctx->pc = 0x8015FAD4u;
    // 8015FAD4: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8015FAD8:
    ctx->pc = 0x8015FAD8u;
    // 8015FAD8: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8015FADC:
    ctx->pc = 0x8015FADCu;
    // 8015FADC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FAE0:
    ctx->pc = 0x8015FAE0u;
    ctx->downcount -= 20;
    // 8015FAE0: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015FAE4:
    ctx->pc = 0x8015FAE4u;
    // 8015FAE4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015FAE8:
    ctx->pc = 0x8015FAE8u;
    // 8015FAE8: stmw     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8015FAEC:
    ctx->pc = 0x8015FAECu;
    // 8015FAEC: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FAF0:
    ctx->pc = 0x8015FAF0u;
    // 8015FAF0: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8015FAF4:
    ctx->pc = 0x8015FAF4u;
    // 8015FAF4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015FAF8:
    ctx->pc = 0x8015FAF8u;
    // 8015FAF8: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8015FAFC:
    ctx->pc = 0x8015FAFCu;
    // 8015FAFC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8015FB00:
    ctx->pc = 0x8015FB00u;
    // 8015FB00: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8015FB04:
    ctx->pc = 0x8015FB04u;
    // 8015FB04: bl      0x8015E4F4
    {
            ctx->lr = 0x8015FB08u;
            ctx->pc = 0x8015E4F4u;
            return;
    }

label_8015FB08:
    ctx->pc = 0x8015FB08u;
    ctx->downcount -= 5;
    // 8015FB08: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_8015FB0C:
    ctx->pc = 0x8015FB0Cu;
    // 8015FB0C: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015FB10:
    ctx->pc = 0x8015FB10u;
    // 8015FB10: lwz     r0, -21460(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21460);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FB14:
    ctx->pc = 0x8015FB14u;
    // 8015FB14: cmpw    r30, r0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015FB18:
    ctx->pc = 0x8015FB18u;
    // 8015FB18: bc    4, 2, 0x8015FB88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8015FB88;
        }
    }

label_8015FB1C:
    ctx->pc = 0x8015FB1Cu;
    ctx->downcount -= 2;
    // 8015FB1C: cmpwi   r29, 1
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015FB20:
    ctx->pc = 0x8015FB20u;
    // 8015FB20: bc    4, 2, 0x8015FB88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8015FB88;
        }
    }

label_8015FB24:
    ctx->pc = 0x8015FB24u;
    ctx->downcount -= 2;
    // 8015FB24: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8015FB28:
    ctx->pc = 0x8015FB28u;
    // 8015FB28: bl      0x8015FC44
    {
            ctx->lr = 0x8015FB2Cu;
            goto label_8015FC44;
    }

label_8015FB2C:
    ctx->pc = 0x8015FB2Cu;
    ctx->downcount -= 6;
    // 8015FB2C: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FB30:
    ctx->pc = 0x8015FB30u;
    // 8015FB30: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8015FB34:
    ctx->pc = 0x8015FB34u;
    // 8015FB34: stw     r3, 388(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(388);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8015FB38:
    ctx->pc = 0x8015FB38u;
    // 8015FB38: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8015FB3C:
    ctx->pc = 0x8015FB3Cu;
    // 8015FB3C: lwz     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8015FB40:
    ctx->pc = 0x8015FB40u;
    // 8015FB40: bl      0x801C0BFC
    {
            ctx->lr = 0x8015FB44u;
            ctx->pc = 0x801C0BFCu;
            return;
    }

label_8015FB44:
    ctx->pc = 0x8015FB44u;
    ctx->downcount -= 5;
    // 8015FB44: stw     r29, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8015FB48:
    ctx->pc = 0x8015FB48u;
    // 8015FB48: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_8015FB4C:
    ctx->pc = 0x8015FB4Cu;
    // 8015FB4C: addi    r3, r3, -27996
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27996);

label_8015FB50:
    ctx->pc = 0x8015FB50u;
    // 8015FB50: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8015FB54:
    ctx->pc = 0x8015FB54u;
    // 8015FB54: bl      0x800994E4
    {
            ctx->lr = 0x8015FB58u;
            ctx->pc = 0x800994E4u;
            return;
    }

label_8015FB58:
    ctx->pc = 0x8015FB58u;
    ctx->downcount -= 2;
    // 8015FB58: or.   r3, r3, r3
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8015FB5C:
    ctx->pc = 0x8015FB5Cu;
    // 8015FB5C: bc    12, 2, 0x8015FB88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015FB88;
        }
    }

label_8015FB60:
    ctx->pc = 0x8015FB60u;
    ctx->downcount -= 10;
    // 8015FB60: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8015FB64:
    ctx->pc = 0x8015FB64u;
    // 8015FB64: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_8015FB68:
    ctx->pc = 0x8015FB68u;
    // 8015FB68: lfs     f0, -27644(r9)
    if (!ppc_fp_available_inline(ctx, 0x8015FB68u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-27644);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8015FB6C:
    ctx->pc = 0x8015FB6Cu;
    // 8015FB6C: or   r6, r11, r11
    {
        ctx->gpr[6] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8015FB70:
    ctx->pc = 0x8015FB70u;
    // 8015FB70: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8015FB74:
    ctx->pc = 0x8015FB74u;
    // 8015FB74: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8015FB78:
    ctx->pc = 0x8015FB78u;
    // 8015FB78: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015FB78u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8015FB7C:
    ctx->pc = 0x8015FB7Cu;
    // 8015FB7C: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x8015FB7Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8015FB80:
    ctx->pc = 0x8015FB80u;
    // 8015FB80: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x8015FB80u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8015FB84:
    ctx->pc = 0x8015FB84u;
    // 8015FB84: bl      0x8021B838
    {
            ctx->lr = 0x8015FB88u;
            ctx->pc = 0x8021B838u;
            return;
    }

label_8015FB88:
    ctx->pc = 0x8015FB88u;
    ctx->downcount -= 17;
    // 8015FB88: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8015FB8C:
    ctx->pc = 0x8015FB8Cu;
    // 8015FB8C: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FB90:
    ctx->pc = 0x8015FB90u;
    // 8015FB90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FB94:
    ctx->pc = 0x8015FB94u;
    // 8015FB94: lmw     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8015FB98:
    ctx->pc = 0x8015FB98u;
    // 8015FB98: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8015FB9C:
    ctx->pc = 0x8015FB9Cu;
    // 8015FB9C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FBA0:
    ctx->pc = 0x8015FBA0u;
    ctx->downcount -= 17;
    // 8015FBA0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015FBA4:
    ctx->pc = 0x8015FBA4u;
    // 8015FBA4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015FBA8:
    ctx->pc = 0x8015FBA8u;
    // 8015FBA8: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8015FBAC:
    ctx->pc = 0x8015FBACu;
    // 8015FBAC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FBB0:
    ctx->pc = 0x8015FBB0u;
    // 8015FBB0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015FBB4:
    ctx->pc = 0x8015FBB4u;
    // 8015FBB4: lwz     r3, 684(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(684);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8015FBB8:
    ctx->pc = 0x8015FBB8u;
    // 8015FBB8: bl      0x80143B78
    {
            ctx->lr = 0x8015FBBCu;
            ctx->pc = 0x80143B78u;
            return;
    }

label_8015FBBC:
    ctx->pc = 0x8015FBBCu;
    ctx->downcount -= 17;
    // 8015FBBC: stw     r3, 660(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(660);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8015FBC0:
    ctx->pc = 0x8015FBC0u;
    // 8015FBC0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FBC4:
    ctx->pc = 0x8015FBC4u;
    // 8015FBC4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FBC8:
    ctx->pc = 0x8015FBC8u;
    // 8015FBC8: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8015FBCC:
    ctx->pc = 0x8015FBCCu;
    // 8015FBCC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8015FBD0:
    ctx->pc = 0x8015FBD0u;
    // 8015FBD0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FBD4:
    ctx->pc = 0x8015FBD4u;
    ctx->downcount -= 17;
    // 8015FBD4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015FBD8:
    ctx->pc = 0x8015FBD8u;
    // 8015FBD8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015FBDC:
    ctx->pc = 0x8015FBDCu;
    // 8015FBDC: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8015FBE0:
    ctx->pc = 0x8015FBE0u;
    // 8015FBE0: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FBE4:
    ctx->pc = 0x8015FBE4u;
    // 8015FBE4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015FBE8:
    ctx->pc = 0x8015FBE8u;
    // 8015FBE8: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8015FBEC:
    ctx->pc = 0x8015FBECu;
    // 8015FBEC: bl      0x8015E544
    {
            ctx->lr = 0x8015FBF0u;
            ctx->pc = 0x8015E544u;
            return;
    }

label_8015FBF0:
    ctx->pc = 0x8015FBF0u;
    ctx->downcount -= 9;
    // 8015FBF0: lwz     r11, 684(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(684);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015FBF4:
    ctx->pc = 0x8015FBF4u;
    // 8015FBF4: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8015FBF8:
    ctx->pc = 0x8015FBF8u;
    // 8015FBF8: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FBFC:
    ctx->pc = 0x8015FBFCu;
    // 8015FBFC: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FC00:
    ctx->pc = 0x8015FC00u;
    // 8015FC00: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FC04:
    ctx->pc = 0x8015FC04u;
    // 8015FC04: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FC08:
    ctx->pc = 0x8015FC08u;
    // 8015FC08: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FC0C:
    ctx->pc = 0x8015FC0Cu;
    // 8015FC0C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FC10u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FC10:
    ctx->pc = 0x8015FC10u;
    ctx->downcount -= 9;
    // 8015FC10: lwz     r11, 688(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(688);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015FC14:
    ctx->pc = 0x8015FC14u;
    // 8015FC14: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8015FC18:
    ctx->pc = 0x8015FC18u;
    // 8015FC18: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FC1C:
    ctx->pc = 0x8015FC1Cu;
    // 8015FC1C: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FC20:
    ctx->pc = 0x8015FC20u;
    // 8015FC20: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FC24:
    ctx->pc = 0x8015FC24u;
    // 8015FC24: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FC28:
    ctx->pc = 0x8015FC28u;
    // 8015FC28: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FC2C:
    ctx->pc = 0x8015FC2Cu;
    // 8015FC2C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FC30u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FC30:
    ctx->pc = 0x8015FC30u;
    ctx->downcount -= 16;
    // 8015FC30: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FC34:
    ctx->pc = 0x8015FC34u;
    // 8015FC34: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FC38:
    ctx->pc = 0x8015FC38u;
    // 8015FC38: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8015FC3C:
    ctx->pc = 0x8015FC3Cu;
    // 8015FC3C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8015FC40:
    ctx->pc = 0x8015FC40u;
    // 8015FC40: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FC44:
    ctx->pc = 0x8015FC44u;
    ctx->downcount -= 6;
    // 8015FC44: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015FC48:
    ctx->pc = 0x8015FC48u;
    // 8015FC48: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015FC4C:
    ctx->pc = 0x8015FC4Cu;
    // 8015FC4C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FC50:
    ctx->pc = 0x8015FC50u;
    // 8015FC50: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_8015FC54:
    ctx->pc = 0x8015FC54u;
    // 8015FC54: addi    r3, r3, -25052
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-25052);

label_8015FC58:
    ctx->pc = 0x8015FC58u;
    // 8015FC58: bl      0x801004BC
    {
            ctx->lr = 0x8015FC5Cu;
            ctx->pc = 0x801004BCu;
            return;
    }

label_8015FC5C:
    ctx->pc = 0x8015FC5Cu;
    ctx->downcount -= 2;
    // 8015FC5C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015FC60:
    ctx->pc = 0x8015FC60u;
    // 8015FC60: bc    12, 2, 0x8015FC70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015FC70;
        }
    }

label_8015FC64:
    ctx->pc = 0x8015FC64u;
    ctx->downcount -= 1;
    // 8015FC64: bl      0x800DA004
    {
            ctx->lr = 0x8015FC68u;
            ctx->pc = 0x800DA004u;
            return;
    }

label_8015FC68:
    ctx->pc = 0x8015FC68u;
    ctx->downcount -= 2;
    // 8015FC68: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8015FC6C:
    ctx->pc = 0x8015FC6Cu;
    // 8015FC6C: b       0x8015FC74
    {
            goto label_8015FC74;
    }

label_8015FC70:
    ctx->pc = 0x8015FC70u;
    ctx->downcount -= 1;
    // 8015FC70: li      r3, 11
    ctx->gpr[3] = (u32)(s32)(11);

label_8015FC74:
    ctx->pc = 0x8015FC74u;
    ctx->downcount -= 5;
    // 8015FC74: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FC78:
    ctx->pc = 0x8015FC78u;
    // 8015FC78: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FC7C:
    ctx->pc = 0x8015FC7Cu;
    // 8015FC7C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8015FC80:
    ctx->pc = 0x8015FC80u;
    // 8015FC80: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FC84:
    ctx->pc = 0x8015FC84u;
    ctx->downcount -= 7;
    // 8015FC84: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015FC88:
    ctx->pc = 0x8015FC88u;
    // 8015FC88: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015FC8C:
    ctx->pc = 0x8015FC8Cu;
    // 8015FC8C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FC90:
    ctx->pc = 0x8015FC90u;
    // 8015FC90: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8015FC94:
    ctx->pc = 0x8015FC94u;
    // 8015FC94: lis     r4, 30561
    ctx->gpr[4] = ((u32)(s32)(30561) << 16);

label_8015FC98:
    ctx->pc = 0x8015FC98u;
    // 8015FC98: ori     r4, r4, 0x7665
    ctx->gpr[4] = ctx->gpr[4] | 0x7665u;

label_8015FC9C:
    ctx->pc = 0x8015FC9Cu;
    // 8015FC9C: bl      0x80213200
    {
            ctx->lr = 0x8015FCA0u;
            ctx->pc = 0x80213200u;
            return;
    }

label_8015FCA0:
    ctx->pc = 0x8015FCA0u;
    ctx->downcount -= 5;
    // 8015FCA0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FCA4:
    ctx->pc = 0x8015FCA4u;
    // 8015FCA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FCA8:
    ctx->pc = 0x8015FCA8u;
    // 8015FCA8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8015FCAC:
    ctx->pc = 0x8015FCACu;
    // 8015FCAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FCB0:
    ctx->pc = 0x8015FCB0u;
    ctx->downcount -= 7;
    // 8015FCB0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015FCB4:
    ctx->pc = 0x8015FCB4u;
    // 8015FCB4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015FCB8:
    ctx->pc = 0x8015FCB8u;
    // 8015FCB8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FCBC:
    ctx->pc = 0x8015FCBCu;
    // 8015FCBC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8015FCC0:
    ctx->pc = 0x8015FCC0u;
    // 8015FCC0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8015FCC4:
    ctx->pc = 0x8015FCC4u;
    // 8015FCC4: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_8015FCC8:
    ctx->pc = 0x8015FCC8u;
    // 8015FCC8: bl      0x8015F66C
    {
            ctx->lr = 0x8015FCCCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8015F66Cu;
                return;
            }
            goto label_8015F66C;
    }

label_8015FCCC:
    ctx->pc = 0x8015FCCCu;
    ctx->downcount -= 5;
    // 8015FCCC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FCD0:
    ctx->pc = 0x8015FCD0u;
    // 8015FCD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FCD4:
    ctx->pc = 0x8015FCD4u;
    // 8015FCD4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8015FCD8:
    ctx->pc = 0x8015FCD8u;
    // 8015FCD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FCDC:
    ctx->pc = 0x8015FCDCu;
    ctx->downcount -= 17;
    // 8015FCDC: stwu     r1, -368(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-368);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015FCE0:
    ctx->pc = 0x8015FCE0u;
    // 8015FCE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015FCE4:
    ctx->pc = 0x8015FCE4u;
    // 8015FCE4: stfd     f31, 360(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015FCE4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(360);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8015FCE8:
    ctx->pc = 0x8015FCE8u;
    // 8015FCE8: stmw     r27, 340(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(340);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8015FCEC:
    ctx->pc = 0x8015FCECu;
    // 8015FCEC: stw     r0, 372(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(372);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FCF0:
    ctx->pc = 0x8015FCF0u;
    // 8015FCF0: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015FCF4:
    ctx->pc = 0x8015FCF4u;
    // 8015FCF4: bl      0x8015E4A4
    {
            ctx->lr = 0x8015FCF8u;
            ctx->pc = 0x8015E4A4u;
            return;
    }

label_8015FCF8:
    ctx->pc = 0x8015FCF8u;
    ctx->downcount -= 10;
    // 8015FCF8: addi    r28, r1, 8
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(8);

label_8015FCFC:
    ctx->pc = 0x8015FCFCu;
    // 8015FCFC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8015FD00:
    ctx->pc = 0x8015FD00u;
    // 8015FD00: addi    r5, r29, 392
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(392);

label_8015FD04:
    ctx->pc = 0x8015FD04u;
    // 8015FD04: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8015FD08:
    ctx->pc = 0x8015FD08u;
    // 8015FD08: stb     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8015FD0C:
    ctx->pc = 0x8015FD0Cu;
    // 8015FD0C: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8015FD10:
    ctx->pc = 0x8015FD10u;
    // 8015FD10: addi    r4, r4, -27532
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27532);

label_8015FD14:
    ctx->pc = 0x8015FD14u;
    // 8015FD14: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8015FD18:
    ctx->pc = 0x8015FD18u;
    // 8015FD18: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8015FD1C:
    ctx->pc = 0x8015FD1Cu;
    // 8015FD1C: bl      0x8009258C
    {
            ctx->lr = 0x8015FD20u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_8015FD20:
    ctx->pc = 0x8015FD20u;
    ctx->downcount -= 9;
    // 8015FD20: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015FD24:
    ctx->pc = 0x8015FD24u;
    // 8015FD24: addi    r27, r1, 272
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(272);

label_8015FD28:
    ctx->pc = 0x8015FD28u;
    // 8015FD28: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8015FD2C:
    ctx->pc = 0x8015FD2Cu;
    // 8015FD2C: addi    r30, r1, 280
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(280);

label_8015FD30:
    ctx->pc = 0x8015FD30u;
    // 8015FD30: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FD34:
    ctx->pc = 0x8015FD34u;
    // 8015FD34: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8015FD38:
    ctx->pc = 0x8015FD38u;
    // 8015FD38: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8015FD3C:
    ctx->pc = 0x8015FD3Cu;
    // 8015FD3C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8015FD40:
    ctx->pc = 0x8015FD40u;
    // 8015FD40: bl      0x801CF88C
    {
            ctx->lr = 0x8015FD44u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_8015FD44:
    ctx->pc = 0x8015FD44u;
    ctx->downcount -= 2;
    // 8015FD44: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_8015FD48:
    ctx->pc = 0x8015FD48u;
    // 8015FD48: bl      0x80281C60
    {
            ctx->lr = 0x8015FD4Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8015FD4C:
    ctx->pc = 0x8015FD4Cu;
    ctx->downcount -= 5;
    // 8015FD4C: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8015FD50:
    ctx->pc = 0x8015FD50u;
    // 8015FD50: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8015FD54:
    ctx->pc = 0x8015FD54u;
    // 8015FD54: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8015FD58:
    ctx->pc = 0x8015FD58u;
    // 8015FD58: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8015FD5C:
    ctx->pc = 0x8015FD5Cu;
    // 8015FD5C: bl      0x801427A0
    {
            ctx->lr = 0x8015FD60u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_8015FD60:
    ctx->pc = 0x8015FD60u;
    ctx->downcount -= 15;
    // 8015FD60: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8015FD64:
    ctx->pc = 0x8015FD64u;
    // 8015FD64: stw     r3, 692(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8015FD68:
    ctx->pc = 0x8015FD68u;
    // 8015FD68: lfs     f31, -27408(r9)
    if (!ppc_fp_available_inline(ctx, 0x8015FD68u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-27408);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8015FD6C:
    ctx->pc = 0x8015FD6Cu;
    // 8015FD6C: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_8015FD70:
    ctx->pc = 0x8015FD70u;
    // 8015FD70: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8015FD74:
    ctx->pc = 0x8015FD74u;
    // 8015FD74: stfs     f31, 280(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015FD74u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8015FD78:
    ctx->pc = 0x8015FD78u;
    // 8015FD78: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x8015FD78u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8015FD7C:
    ctx->pc = 0x8015FD7Cu;
    // 8015FD7C: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x8015FD7Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8015FD80:
    ctx->pc = 0x8015FD80u;
    // 8015FD80: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FD84:
    ctx->pc = 0x8015FD84u;
    // 8015FD84: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FD88:
    ctx->pc = 0x8015FD88u;
    // 8015FD88: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FD8C:
    ctx->pc = 0x8015FD8Cu;
    // 8015FD8C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FD90:
    ctx->pc = 0x8015FD90u;
    // 8015FD90: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_8015FD94:
    ctx->pc = 0x8015FD94u;
    // 8015FD94: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FD98u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FD98:
    ctx->pc = 0x8015FD98u;
    ctx->downcount -= 7;
    // 8015FD98: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015FD9C:
    ctx->pc = 0x8015FD9Cu;
    // 8015FD9C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8015FDA0:
    ctx->pc = 0x8015FDA0u;
    // 8015FDA0: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8015FDA4:
    ctx->pc = 0x8015FDA4u;
    // 8015FDA4: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FDA8:
    ctx->pc = 0x8015FDA8u;
    // 8015FDA8: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8015FDAC:
    ctx->pc = 0x8015FDACu;
    // 8015FDAC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8015FDB0:
    ctx->pc = 0x8015FDB0u;
    // 8015FDB0: bl      0x801CF88C
    {
            ctx->lr = 0x8015FDB4u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_8015FDB4:
    ctx->pc = 0x8015FDB4u;
    ctx->downcount -= 2;
    // 8015FDB4: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_8015FDB8:
    ctx->pc = 0x8015FDB8u;
    // 8015FDB8: bl      0x80281C60
    {
            ctx->lr = 0x8015FDBCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8015FDBC:
    ctx->pc = 0x8015FDBCu;
    ctx->downcount -= 6;
    // 8015FDBC: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8015FDC0:
    ctx->pc = 0x8015FDC0u;
    // 8015FDC0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8015FDC4:
    ctx->pc = 0x8015FDC4u;
    // 8015FDC4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8015FDC8:
    ctx->pc = 0x8015FDC8u;
    // 8015FDC8: addi    r4, r4, -27508
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27508);

label_8015FDCC:
    ctx->pc = 0x8015FDCCu;
    // 8015FDCC: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8015FDD0:
    ctx->pc = 0x8015FDD0u;
    // 8015FDD0: bl      0x801427A0
    {
            ctx->lr = 0x8015FDD4u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_8015FDD4:
    ctx->pc = 0x8015FDD4u;
    ctx->downcount -= 13;
    // 8015FDD4: stfs     f31, 280(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015FDD4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8015FDD8:
    ctx->pc = 0x8015FDD8u;
    // 8015FDD8: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8015FDDC:
    ctx->pc = 0x8015FDDCu;
    // 8015FDDC: stw     r3, 684(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8015FDE0:
    ctx->pc = 0x8015FDE0u;
    // 8015FDE0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8015FDE4:
    ctx->pc = 0x8015FDE4u;
    // 8015FDE4: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x8015FDE4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8015FDE8:
    ctx->pc = 0x8015FDE8u;
    // 8015FDE8: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x8015FDE8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8015FDEC:
    ctx->pc = 0x8015FDECu;
    // 8015FDEC: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FDF0:
    ctx->pc = 0x8015FDF0u;
    // 8015FDF0: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FDF4:
    ctx->pc = 0x8015FDF4u;
    // 8015FDF4: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FDF8:
    ctx->pc = 0x8015FDF8u;
    // 8015FDF8: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FDFC:
    ctx->pc = 0x8015FDFCu;
    // 8015FDFC: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_8015FE00:
    ctx->pc = 0x8015FE00u;
    // 8015FE00: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FE04u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FE04:
    ctx->pc = 0x8015FE04u;
    ctx->downcount -= 4;
    // 8015FE04: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8015FE08:
    ctx->pc = 0x8015FE08u;
    // 8015FE08: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8015FE0C:
    ctx->pc = 0x8015FE0Cu;
    // 8015FE0C: addi    r4, r4, -27460
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27460);

label_8015FE10:
    ctx->pc = 0x8015FE10u;
    // 8015FE10: bl      0x801CFE08
    {
            ctx->lr = 0x8015FE14u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_8015FE14:
    ctx->pc = 0x8015FE14u;
    ctx->downcount -= 12;
    // 8015FE14: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_8015FE18:
    ctx->pc = 0x8015FE18u;
    // 8015FE18: lwz     r28, 684(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(684);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8015FE1C:
    ctx->pc = 0x8015FE1Cu;
    // 8015FE1C: addi    r9, r9, -25052
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-25052);

label_8015FE20:
    ctx->pc = 0x8015FE20u;
    // 8015FE20: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8015FE24:
    ctx->pc = 0x8015FE24u;
    // 8015FE24: lwz     r0, 3596(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3596);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FE28:
    ctx->pc = 0x8015FE28u;
    // 8015FE28: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x8015FE28u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8015FE2C:
    ctx->pc = 0x8015FE2Cu;
    // 8015FE2C: addi    r9, r9, 3020
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(3020);

label_8015FE30:
    ctx->pc = 0x8015FE30u;
    // 8015FE30: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_8015FE34:
    ctx->pc = 0x8015FE34u;
    // 8015FE34: lwzx    r4, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8015FE38:
    ctx->pc = 0x8015FE38u;
    // 8015FE38: bl      0x801D009C
    {
            ctx->lr = 0x8015FE3Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8015FE3C:
    ctx->pc = 0x8015FE3Cu;
    ctx->downcount -= 5;
    // 8015FE3C: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8015FE3Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8015FE40:
    ctx->pc = 0x8015FE40u;
    // 8015FE40: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8015FE44:
    ctx->pc = 0x8015FE44u;
    // 8015FE44: stfd     f0, 328(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015FE44u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(328);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8015FE48:
    ctx->pc = 0x8015FE48u;
    // 8015FE48: lwz     r4, 332(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(332);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8015FE4C:
    ctx->pc = 0x8015FE4Cu;
    // 8015FE4C: bl      0x80143B20
    {
            ctx->lr = 0x8015FE50u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_8015FE50:
    ctx->pc = 0x8015FE50u;
    ctx->downcount -= 7;
    // 8015FE50: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015FE54:
    ctx->pc = 0x8015FE54u;
    // 8015FE54: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8015FE58:
    ctx->pc = 0x8015FE58u;
    // 8015FE58: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8015FE5C:
    ctx->pc = 0x8015FE5Cu;
    // 8015FE5C: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FE60:
    ctx->pc = 0x8015FE60u;
    // 8015FE60: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8015FE64:
    ctx->pc = 0x8015FE64u;
    // 8015FE64: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8015FE68:
    ctx->pc = 0x8015FE68u;
    // 8015FE68: bl      0x801CF88C
    {
            ctx->lr = 0x8015FE6Cu;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_8015FE6C:
    ctx->pc = 0x8015FE6Cu;
    ctx->downcount -= 2;
    // 8015FE6C: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_8015FE70:
    ctx->pc = 0x8015FE70u;
    // 8015FE70: bl      0x80281C60
    {
            ctx->lr = 0x8015FE74u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8015FE74:
    ctx->pc = 0x8015FE74u;
    ctx->downcount -= 6;
    // 8015FE74: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8015FE78:
    ctx->pc = 0x8015FE78u;
    // 8015FE78: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8015FE7C:
    ctx->pc = 0x8015FE7Cu;
    // 8015FE7C: addi    r4, r4, -27448
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27448);

label_8015FE80:
    ctx->pc = 0x8015FE80u;
    // 8015FE80: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8015FE84:
    ctx->pc = 0x8015FE84u;
    // 8015FE84: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8015FE88:
    ctx->pc = 0x8015FE88u;
    // 8015FE88: bl      0x801427A0
    {
            ctx->lr = 0x8015FE8Cu;
            ctx->pc = 0x801427A0u;
            return;
    }

label_8015FE8C:
    ctx->pc = 0x8015FE8Cu;
    ctx->downcount -= 14;
    // 8015FE8C: stfs     f31, 296(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015FE8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(296);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8015FE90:
    ctx->pc = 0x8015FE90u;
    // 8015FE90: addi    r9, r1, 296
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(296);

label_8015FE94:
    ctx->pc = 0x8015FE94u;
    // 8015FE94: stw     r3, 688(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8015FE98:
    ctx->pc = 0x8015FE98u;
    // 8015FE98: or   r5, r9, r9
    {
        ctx->gpr[5] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8015FE9C:
    ctx->pc = 0x8015FE9Cu;
    // 8015FE9C: stfs     f31, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x8015FE9Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8015FEA0:
    ctx->pc = 0x8015FEA0u;
    // 8015FEA0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8015FEA4:
    ctx->pc = 0x8015FEA4u;
    // 8015FEA4: stfs     f31, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x8015FEA4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8015FEA8:
    ctx->pc = 0x8015FEA8u;
    // 8015FEA8: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FEAC:
    ctx->pc = 0x8015FEACu;
    // 8015FEAC: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FEB0:
    ctx->pc = 0x8015FEB0u;
    // 8015FEB0: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FEB4:
    ctx->pc = 0x8015FEB4u;
    // 8015FEB4: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FEB8:
    ctx->pc = 0x8015FEB8u;
    // 8015FEB8: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_8015FEBC:
    ctx->pc = 0x8015FEBCu;
    // 8015FEBC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FEC0u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FEC0:
    ctx->pc = 0x8015FEC0u;
    ctx->downcount -= 3;
    // 8015FEC0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8015FEC4:
    ctx->pc = 0x8015FEC4u;
    // 8015FEC4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8015FEC8:
    ctx->pc = 0x8015FEC8u;
    // 8015FEC8: bl      0x801CFEAC
    {
            ctx->lr = 0x8015FECCu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_8015FECC:
    ctx->pc = 0x8015FECCu;
    ctx->downcount -= 17;
    // 8015FECC: lwz     r0, 372(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(372);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FED0:
    ctx->pc = 0x8015FED0u;
    // 8015FED0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FED4:
    ctx->pc = 0x8015FED4u;
    // 8015FED4: lmw     r27, 340(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(340);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8015FED8:
    ctx->pc = 0x8015FED8u;
    // 8015FED8: lfd     f31, 360(r1)
    if (!ppc_fp_available_inline(ctx, 0x8015FED8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(360);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8015FEDC:
    ctx->pc = 0x8015FEDCu;
    // 8015FEDC: addi    r1, r1, 368
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(368);

label_8015FEE0:
    ctx->pc = 0x8015FEE0u;
    // 8015FEE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FEE4:
    ctx->pc = 0x8015FEE4u;
    ctx->downcount -= 18;
    // 8015FEE4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015FEE8:
    ctx->pc = 0x8015FEE8u;
    // 8015FEE8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015FEEC:
    ctx->pc = 0x8015FEECu;
    // 8015FEEC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8015FEF0:
    ctx->pc = 0x8015FEF0u;
    // 8015FEF0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FEF4:
    ctx->pc = 0x8015FEF4u;
    // 8015FEF4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8015FEF8:
    ctx->pc = 0x8015FEF8u;
    // 8015FEF8: lwz     r0, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FEFC:
    ctx->pc = 0x8015FEFCu;
    // 8015FEFC: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015FF00:
    ctx->pc = 0x8015FF00u;
    // 8015FF00: bc    4, 2, 0x8015FF10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8015FF10;
        }
    }

label_8015FF04:
    ctx->pc = 0x8015FF04u;
    ctx->downcount -= 2;
    // 8015FF04: lwz     r3, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8015FF08:
    ctx->pc = 0x8015FF08u;
    // 8015FF08: bl      0x80143B78
    {
            ctx->lr = 0x8015FF0Cu;
            ctx->pc = 0x80143B78u;
            return;
    }

label_8015FF0C:
    ctx->pc = 0x8015FF0Cu;
    ctx->downcount -= 1;
    // 8015FF0C: b       0x8015FFBC
    {
            goto label_8015FFBC;
    }

label_8015FF10:
    ctx->pc = 0x8015FF10u;
    ctx->downcount -= 3;
    // 8015FF10: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FF14:
    ctx->pc = 0x8015FF14u;
    // 8015FF14: lwz     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8015FF18:
    ctx->pc = 0x8015FF18u;
    // 8015FF18: bl      0x801BDA98
    {
            ctx->lr = 0x8015FF1Cu;
            ctx->pc = 0x801BDA98u;
            return;
    }

label_8015FF1C:
    ctx->pc = 0x8015FF1Cu;
    ctx->downcount -= 2;
    // 8015FF1C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015FF20:
    ctx->pc = 0x8015FF20u;
    // 8015FF20: bc    12, 2, 0x8015FFB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8015FFB8;
        }
    }

label_8015FF24:
    ctx->pc = 0x8015FF24u;
    ctx->downcount -= 11;
    // 8015FF24: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8015FF28:
    ctx->pc = 0x8015FF28u;
    // 8015FF28: lwz     r11, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015FF2C:
    ctx->pc = 0x8015FF2Cu;
    // 8015FF2C: stw     r0, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FF30:
    ctx->pc = 0x8015FF30u;
    // 8015FF30: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8015FF34:
    ctx->pc = 0x8015FF34u;
    // 8015FF34: lfs     f1, -27384(r9)
    if (!ppc_fp_available_inline(ctx, 0x8015FF34u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-27384);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8015FF38:
    ctx->pc = 0x8015FF38u;
    // 8015FF38: lwz     r0, 212(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(212);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FF3C:
    ctx->pc = 0x8015FF3Cu;
    // 8015FF3C: lha     r3, 208(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(208);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FF40:
    ctx->pc = 0x8015FF40u;
    // 8015FF40: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FF44:
    ctx->pc = 0x8015FF44u;
    // 8015FF44: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FF48:
    ctx->pc = 0x8015FF48u;
    // 8015FF48: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FF4Cu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FF4C:
    ctx->pc = 0x8015FF4Cu;
    ctx->downcount -= 13;
    // 8015FF4C: lwz     r11, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015FF50:
    ctx->pc = 0x8015FF50u;
    // 8015FF50: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_8015FF54:
    ctx->pc = 0x8015FF54u;
    // 8015FF54: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_8015FF58:
    ctx->pc = 0x8015FF58u;
    // 8015FF58: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8015FF5C:
    ctx->pc = 0x8015FF5Cu;
    // 8015FF5C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FF60:
    ctx->pc = 0x8015FF60u;
    // 8015FF60: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8015FF64:
    ctx->pc = 0x8015FF64u;
    // 8015FF64: lwz     r4, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8015FF68:
    ctx->pc = 0x8015FF68u;
    // 8015FF68: lwz     r0, 148(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(148);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FF6C:
    ctx->pc = 0x8015FF6Cu;
    // 8015FF6C: lha     r3, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FF70:
    ctx->pc = 0x8015FF70u;
    // 8015FF70: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FF74:
    ctx->pc = 0x8015FF74u;
    // 8015FF74: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FF78:
    ctx->pc = 0x8015FF78u;
    // 8015FF78: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FF7Cu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FF7C:
    ctx->pc = 0x8015FF7Cu;
    ctx->downcount -= 9;
    // 8015FF7C: lwz     r11, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8015FF80:
    ctx->pc = 0x8015FF80u;
    // 8015FF80: lwz     r4, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8015FF84:
    ctx->pc = 0x8015FF84u;
    // 8015FF84: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FF88:
    ctx->pc = 0x8015FF88u;
    // 8015FF88: lwz     r0, 132(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FF8C:
    ctx->pc = 0x8015FF8Cu;
    // 8015FF8C: lha     r3, 128(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(128);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FF90:
    ctx->pc = 0x8015FF90u;
    // 8015FF90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FF94:
    ctx->pc = 0x8015FF94u;
    // 8015FF94: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FF98:
    ctx->pc = 0x8015FF98u;
    // 8015FF98: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FF9Cu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FF9C:
    ctx->pc = 0x8015FF9Cu;
    ctx->downcount -= 8;
    // 8015FF9C: lwz     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8015FFA0:
    ctx->pc = 0x8015FFA0u;
    // 8015FFA0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8015FFA4:
    ctx->pc = 0x8015FFA4u;
    // 8015FFA4: lha     r3, 192(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(192);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8015FFA8:
    ctx->pc = 0x8015FFA8u;
    // 8015FFA8: lwz     r0, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FFAC:
    ctx->pc = 0x8015FFACu;
    // 8015FFAC: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8015FFB0:
    ctx->pc = 0x8015FFB0u;
    // 8015FFB0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FFB4:
    ctx->pc = 0x8015FFB4u;
    // 8015FFB4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8015FFB8u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FFB8:
    ctx->pc = 0x8015FFB8u;
    ctx->downcount -= 1;
    // 8015FFB8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8015FFBC:
    ctx->pc = 0x8015FFBCu;
    ctx->downcount -= 16;
    // 8015FFBC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FFC0:
    ctx->pc = 0x8015FFC0u;
    // 8015FFC0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8015FFC4:
    ctx->pc = 0x8015FFC4u;
    // 8015FFC4: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8015FFC8:
    ctx->pc = 0x8015FFC8u;
    // 8015FFC8: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8015FFCC:
    ctx->pc = 0x8015FFCCu;
    // 8015FFCC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8015FFD0:
    ctx->pc = 0x8015FFD0u;
    ctx->downcount -= 19;
    // 8015FFD0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8015FFD4:
    ctx->pc = 0x8015FFD4u;
    // 8015FFD4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8015FFD8:
    ctx->pc = 0x8015FFD8u;
    // 8015FFD8: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8015FFDC:
    ctx->pc = 0x8015FFDCu;
    // 8015FFDC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8015FFE0:
    ctx->pc = 0x8015FFE0u;
    // 8015FFE0: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_8015FFE4:
    ctx->pc = 0x8015FFE4u;
    // 8015FFE4: addi    r31, r9, -25052
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-25052);

label_8015FFE8:
    ctx->pc = 0x8015FFE8u;
    // 8015FFE8: lwz     r0, 3580(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3580);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FFEC:
    ctx->pc = 0x8015FFECu;
    // 8015FFEC: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8015FFF0:
    ctx->pc = 0x8015FFF0u;
    // 8015FFF0: bc    12, 2, 0x80160060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160060;
        }
    }

label_8015FFF4:
    ctx->pc = 0x8015FFF4u;
    ctx->downcount -= 9;
    // 8015FFF4: lwz     r0, 3596(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3596);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8015FFF8:
    ctx->pc = 0x8015FFF8u;
    // 8015FFF8: addi    r30, r31, 3020
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(3020);

label_8015FFFC:
    ctx->pc = 0x8015FFFCu;
    // 8015FFFC: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80160000:
    ctx->pc = 0x80160000u;
    // 80160000: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80160004:
    ctx->pc = 0x80160004u;
    // 80160004: addi    r4, r4, -27380
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27380);

label_80160008:
    ctx->pc = 0x80160008u;
    // 80160008: lwzx    r3, r30, r0
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8016000C:
    ctx->pc = 0x8016000Cu;
    // 8016000C: bl      0x80297FBC
    {
            ctx->lr = 0x80160010u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80160010:
    ctx->pc = 0x80160010u;
    ctx->downcount -= 2;
    // 80160010: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160014:
    ctx->pc = 0x80160014u;
    // 80160014: bc    12, 2, 0x80160058
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160058;
        }
    }

label_80160018:
    ctx->pc = 0x80160018u;
    ctx->downcount -= 8;
    // 80160018: lwz     r0, 3596(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3596);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016001C:
    ctx->pc = 0x8016001Cu;
    // 8016001C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80160020:
    ctx->pc = 0x80160020u;
    // 80160020: addi    r4, r4, -27364
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27364);

label_80160024:
    ctx->pc = 0x80160024u;
    // 80160024: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80160028:
    ctx->pc = 0x80160028u;
    // 80160028: lwzx    r3, r30, r0
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8016002C:
    ctx->pc = 0x8016002Cu;
    // 8016002C: bl      0x80297FBC
    {
            ctx->lr = 0x80160030u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80160030:
    ctx->pc = 0x80160030u;
    ctx->downcount -= 2;
    // 80160030: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160034:
    ctx->pc = 0x80160034u;
    // 80160034: bc    12, 2, 0x80160058
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160058;
        }
    }

label_80160038:
    ctx->pc = 0x80160038u;
    ctx->downcount -= 8;
    // 80160038: lwz     r0, 3596(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3596);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016003C:
    ctx->pc = 0x8016003Cu;
    // 8016003C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80160040:
    ctx->pc = 0x80160040u;
    // 80160040: addi    r4, r4, -27348
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27348);

label_80160044:
    ctx->pc = 0x80160044u;
    // 80160044: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80160048:
    ctx->pc = 0x80160048u;
    // 80160048: lwzx    r3, r30, r0
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8016004C:
    ctx->pc = 0x8016004Cu;
    // 8016004C: bl      0x80297FBC
    {
            ctx->lr = 0x80160050u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80160050:
    ctx->pc = 0x80160050u;
    ctx->downcount -= 2;
    // 80160050: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160054:
    ctx->pc = 0x80160054u;
    // 80160054: bc    4, 2, 0x80160060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80160060;
        }
    }

label_80160058:
    ctx->pc = 0x80160058u;
    ctx->downcount -= 2;
    // 80160058: li      r3, 19
    ctx->gpr[3] = (u32)(s32)(19);

label_8016005C:
    ctx->pc = 0x8016005Cu;
    // 8016005C: b       0x80160098
    {
            goto label_80160098;
    }

label_80160060:
    ctx->pc = 0x80160060u;
    ctx->downcount -= 5;
    // 80160060: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80160064:
    ctx->pc = 0x80160064u;
    // 80160064: addi    r3, r9, -25052
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(-25052);

label_80160068:
    ctx->pc = 0x80160068u;
    // 80160068: lwz     r0, 3584(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3584);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016006C:
    ctx->pc = 0x8016006Cu;
    // 8016006C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160070:
    ctx->pc = 0x80160070u;
    // 80160070: bc    12, 2, 0x8016007C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016007C;
        }
    }

label_80160074:
    ctx->pc = 0x80160074u;
    ctx->downcount -= 2;
    // 80160074: li      r3, 30
    ctx->gpr[3] = (u32)(s32)(30);

label_80160078:
    ctx->pc = 0x80160078u;
    // 80160078: b       0x80160098
    {
            goto label_80160098;
    }

label_8016007C:
    ctx->pc = 0x8016007Cu;
    ctx->downcount -= 1;
    // 8016007C: bl      0x801004BC
    {
            ctx->lr = 0x80160080u;
            ctx->pc = 0x801004BCu;
            return;
    }

label_80160080:
    ctx->pc = 0x80160080u;
    ctx->downcount -= 2;
    // 80160080: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160084:
    ctx->pc = 0x80160084u;
    // 80160084: bc    12, 2, 0x80160094
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160094;
        }
    }

label_80160088:
    ctx->pc = 0x80160088u;
    ctx->downcount -= 1;
    // 80160088: bl      0x800DA004
    {
            ctx->lr = 0x8016008Cu;
            ctx->pc = 0x800DA004u;
            return;
    }

label_8016008C:
    ctx->pc = 0x8016008Cu;
    ctx->downcount -= 2;
    // 8016008C: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80160090:
    ctx->pc = 0x80160090u;
    // 80160090: b       0x80160098
    {
            goto label_80160098;
    }

label_80160094:
    ctx->pc = 0x80160094u;
    ctx->downcount -= 1;
    // 80160094: li      r3, 11
    ctx->gpr[3] = (u32)(s32)(11);

label_80160098:
    ctx->pc = 0x80160098u;
    ctx->downcount -= 16;
    // 80160098: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016009C:
    ctx->pc = 0x8016009Cu;
    // 8016009C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801600A0:
    ctx->pc = 0x801600A0u;
    // 801600A0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801600A4:
    ctx->pc = 0x801600A4u;
    // 801600A4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801600A8:
    ctx->pc = 0x801600A8u;
    // 801600A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801600AC:
    ctx->pc = 0x801600ACu;
    ctx->downcount -= 16;
    // 801600AC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801600B0:
    ctx->pc = 0x801600B0u;
    // 801600B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801600B4:
    ctx->pc = 0x801600B4u;
    // 801600B4: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801600B8:
    ctx->pc = 0x801600B8u;
    // 801600B8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801600BC:
    ctx->pc = 0x801600BCu;
    // 801600BC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801600C0:
    ctx->pc = 0x801600C0u;
    // 801600C0: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801600C4:
    ctx->pc = 0x801600C4u;
    ctx->downcount -= 11;
    // 801600C4: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801600C8:
    ctx->pc = 0x801600C8u;
    // 801600C8: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801600CC:
    // 801600CC: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_801600D0:
    ctx->pc = 0x801600D0u;
    // 801600D0: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801600D4:
    // 801600D4: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_801600D8:
    // 801600D8: cmplw   r10, r11
    {
        u32 val_a = (u32)(ctx->gpr[10]);
        u32 val_b = (u32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801600DC:
    // 801600DC: bc    12, 0, 0x80160104
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160104;
        }
    }

label_801600E0:
    ctx->downcount -= 3;
    // 801600E0: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801600E4:
    ctx->pc = 0x801600E4u;
    // 801600E4: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801600E8:
    // 801600E8: b       0x801601DC
    {
            goto label_801601DC;
    }

label_801600EC:
    ctx->pc = 0x801600ECu;
    ctx->downcount -= 6;
    // 801600EC: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801600F0:
    // 801600F0: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801600F4:
    ctx->pc = 0x801600F4u;
    // 801600F4: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801600F8:
    ctx->pc = 0x801600F8u;
    // 801600F8: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801600FC:
    ctx->pc = 0x801600FCu;
    // 801600FC: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80160100:
    // 80160100: b       0x801600C4
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801600C4u;
                return;
            }
            goto label_801600C4;
    }

label_80160104:
    ctx->downcount -= 2;
    // 80160104: cmplw   r10, r30
    {
        u32 val_a = (u32)(ctx->gpr[10]);
        u32 val_b = (u32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160108:
    // 80160108: bc    12, 0, 0x80160128
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160128;
        }
    }

label_8016010C:
    ctx->downcount -= 50;
    // 8016010C: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_80160110:
    ctx->pc = 0x80160110u;
    // 80160110: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160114:
    // 80160114: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80160118:
    ctx->pc = 0x80160118u;
    // 80160118: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8016011C:
    // 8016011C: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80160120:
    ctx->pc = 0x80160120u;
    // 80160120: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160124:
    // 80160124: b       0x801601DC
    {
            goto label_801601DC;
    }

label_80160128:
    ctx->pc = 0x80160128u;
    ctx->downcount -= 8;
    // 80160128: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8016012C:
    // 8016012C: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80160130:
    // 80160130: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160134:
    // 80160134: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_80160138:
    // 80160138: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_8016013C:
    // 8016013C: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_80160140:
    // 80160140: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_80160144:
    // 80160144: bc    12, 2, 0x80160164
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160164;
        }
    }

label_80160148:
    ctx->downcount -= 7;
    // 80160148: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_8016014C:
    // 8016014C: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80160150:
    // 80160150: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80160154:
    // 80160154: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80160158:
    ctx->pc = 0x80160158u;
    // 80160158: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8016015C:
    ctx->pc = 0x8016015Cu;
    // 8016015C: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80160160:
    ctx->pc = 0x80160160u;
    // 80160160: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80160164:
    ctx->downcount -= 2;
    // 80160164: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80160168:
    // 80160168: bl      0x80281C60
    {
            ctx->lr = 0x8016016Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8016016C:
    ctx->downcount -= 3;
    // 8016016C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160170:
    ctx->pc = 0x80160170u;
    // 80160170: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80160174:
    // 80160174: bc    4, 2, 0x801601C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801601C0;
        }
    }

label_80160178:
    ctx->downcount -= 3;
    // 80160178: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8016017C:
    // 8016017C: cmplwi  r11, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160180:
    // 80160180: bc    12, 1, 0x801601AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801601AC;
        }
    }

label_80160184:
    ctx->downcount -= 2;
    // 80160184: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80160188:
    // 80160188: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_8016018C:
    ctx->downcount -= 5;
    // 8016018C: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_80160190:
    // 80160190: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80160194:
    ctx->pc = 0x80160194u;
    // 80160194: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80160198:
    // 80160198: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016019C:
    // 8016019C: bc    4, 2, 0x801600EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801600ECu;
                return;
            }
            goto label_801600EC;
        }
    }

label_801601A0:
    ctx->downcount -= 3;
    // 801601A0: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_801601A4:
    // 801601A4: cmplwi  r11, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801601A8:
    // 801601A8: bc    4, 1, 0x8016018C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8016018Cu;
                return;
            }
            goto label_8016018C;
        }
    }

label_801601AC:
    ctx->downcount -= 4;
    // 801601AC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801601B0:
    // 801601B0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801601B4:
    ctx->pc = 0x801601B4u;
    // 801601B4: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801601B8:
    // 801601B8: bl      0x80281C60
    {
            ctx->lr = 0x801601BCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801601BC:
    ctx->pc = 0x801601BCu;
    ctx->downcount -= 1;
    // 801601BC: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801601C0:
    ctx->pc = 0x801601C0u;
    ctx->downcount -= 7;
    // 801601C0: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801601C4:
    ctx->pc = 0x801601C4u;
    // 801601C4: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801601C8:
    // 801601C8: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801601CC:
    // 801601CC: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_801601D0:
    ctx->pc = 0x801601D0u;
    // 801601D0: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801601D4:
    ctx->pc = 0x801601D4u;
    // 801601D4: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801601D8:
    // 801601D8: b       0x801600C4
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801600C4u;
                return;
            }
            goto label_801600C4;
    }

label_801601DC:
    ctx->pc = 0x801601DCu;
    ctx->downcount -= 16;
    // 801601DC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801601E0:
    ctx->pc = 0x801601E0u;
    // 801601E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801601E4:
    ctx->pc = 0x801601E4u;
    // 801601E4: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801601E8:
    ctx->pc = 0x801601E8u;
    // 801601E8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801601EC:
    ctx->pc = 0x801601ECu;
    // 801601EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801601F0:
    ctx->pc = 0x801601F0u;
    ctx->downcount -= 21;
    // 801601F0: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801601F4:
    ctx->pc = 0x801601F4u;
    // 801601F4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801601F8:
    ctx->pc = 0x801601F8u;
    // 801601F8: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801601FC:
    ctx->pc = 0x801601FCu;
    // 801601FC: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160200:
    ctx->pc = 0x80160200u;
    // 80160200: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80160204:
    ctx->pc = 0x80160204u;
    // 80160204: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_80160208:
    ctx->pc = 0x80160208u;
    // 80160208: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_8016020C:
    ctx->pc = 0x8016020Cu;
    // 8016020C: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80160210:
    ctx->pc = 0x80160210u;
    // 80160210: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80160214:
    ctx->pc = 0x80160214u;
    // 80160214: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160218:
    ctx->pc = 0x80160218u;
    // 80160218: bc    12, 2, 0x80160228
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160228;
        }
    }

label_8016021C:
    ctx->pc = 0x8016021Cu;
    ctx->downcount -= 3;
    // 8016021C: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160220:
    ctx->pc = 0x80160220u;
    // 80160220: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160224:
    ctx->pc = 0x80160224u;
    // 80160224: b       0x801602A8
    {
            goto label_801602A8;
    }

label_80160228:
    ctx->pc = 0x80160228u;
    ctx->downcount -= 7;
    // 80160228: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_8016022C:
    ctx->pc = 0x8016022Cu;
    // 8016022C: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_80160230:
    ctx->pc = 0x80160230u;
    // 80160230: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_80160234:
    ctx->pc = 0x80160234u;
    // 80160234: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80160238:
    ctx->pc = 0x80160238u;
    // 80160238: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8016023C:
    ctx->pc = 0x8016023Cu;
    // 8016023C: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_80160240:
    ctx->pc = 0x80160240u;
    // 80160240: bl      0x80003EE0
    {
            ctx->lr = 0x80160244u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_80160244:
    ctx->pc = 0x80160244u;
    ctx->downcount -= 3;
    // 80160244: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160248:
    ctx->pc = 0x80160248u;
    // 80160248: cmpwi   r9, 1
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016024C:
    ctx->pc = 0x8016024Cu;
    // 8016024C: bc    12, 2, 0x801602A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801602A4;
        }
    }

label_80160250:
    ctx->pc = 0x80160250u;
    ctx->downcount -= 9;
    // 80160250: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_80160254:
    ctx->pc = 0x80160254u;
    // 80160254: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80160258:
    ctx->pc = 0x80160258u;
    // 80160258: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_8016025C:
    ctx->pc = 0x8016025Cu;
    // 8016025C: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80160260:
    ctx->pc = 0x80160260u;
    // 80160260: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80160264:
    ctx->pc = 0x80160264u;
    // 80160264: cmpwi   r9, 2
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160268:
    ctx->pc = 0x80160268u;
    // 80160268: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8016026C:
    ctx->pc = 0x8016026Cu;
    // 8016026C: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80160270:
    ctx->pc = 0x80160270u;
    // 80160270: bc    4, 2, 0x8016027C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8016027C;
        }
    }

label_80160274:
    ctx->pc = 0x80160274u;
    ctx->downcount -= 2;
    // 80160274: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80160278:
    ctx->pc = 0x80160278u;
    // 80160278: b       0x801602A4
    {
            goto label_801602A4;
    }

label_8016027C:
    loop_8016027C(ctx);
    if (ctx->pc == 0x8016029Cu) goto label_8016029C;
    return;
label_80160280:
    // 80160280: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_80160284:
    // 80160284: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80160288:
    ctx->pc = 0x80160288u;
    // 80160288: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8016028C:
    // 8016028C: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80160290:
    // 80160290: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80160294:
    // 80160294: cmpw    r9, r8
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160298:
    // 80160298: bc    4, 2, 0x8016027C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8016027Cu;
                return;
            }
            goto label_8016027C;
        }
    }

label_8016029C:
    ctx->pc = 0x8016029Cu;
    ctx->downcount -= 2;
    // 8016029C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801602A0:
    ctx->pc = 0x801602A0u;
    // 801602A0: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801602A4:
    ctx->pc = 0x801602A4u;
    ctx->downcount -= 1;
    // 801602A4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801602A8:
    ctx->pc = 0x801602A8u;
    ctx->downcount -= 17;
    // 801602A8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801602AC:
    ctx->pc = 0x801602ACu;
    // 801602AC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801602B0:
    ctx->pc = 0x801602B0u;
    // 801602B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801602B4:
    ctx->pc = 0x801602B4u;
    // 801602B4: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801602B8:
    ctx->pc = 0x801602B8u;
    // 801602B8: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801602BC:
    ctx->pc = 0x801602BCu;
    // 801602BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801602C0:
    ctx->pc = 0x801602C0u;
    ctx->downcount -= 7;
    // 801602C0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801602C4:
    ctx->pc = 0x801602C4u;
    // 801602C4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801602C8:
    ctx->pc = 0x801602C8u;
    // 801602C8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801602CC:
    ctx->pc = 0x801602CCu;
    // 801602CC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801602D0:
    ctx->pc = 0x801602D0u;
    // 801602D0: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_801602D4:
    ctx->pc = 0x801602D4u;
    // 801602D4: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801602D8:
    ctx->pc = 0x801602D8u;
    // 801602D8: bc    4, 2, 0x801603D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801603D4;
        }
    }

label_801602DC:
    ctx->pc = 0x801602DCu;
    ctx->downcount -= 2;
    // 801602DC: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801602E0:
    ctx->pc = 0x801602E0u;
    // 801602E0: bc    12, 2, 0x801603D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801603D4;
        }
    }

label_801602E4:
    ctx->pc = 0x801602E4u;
    ctx->downcount -= 5;
    // 801602E4: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_801602E8:
    ctx->pc = 0x801602E8u;
    // 801602E8: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_801602EC:
    ctx->pc = 0x801602ECu;
    // 801602EC: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_801602F0:
    ctx->pc = 0x801602F0u;
    // 801602F0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801602F4:
    ctx->pc = 0x801602F4u;
    // 801602F4: bl      0x80252AF0
    {
            ctx->lr = 0x801602F8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801602F8:
    ctx->pc = 0x801602F8u;
    ctx->downcount -= 5;
    // 801602F8: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_801602FC:
    ctx->pc = 0x801602FCu;
    // 801602FC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80160300:
    ctx->pc = 0x80160300u;
    // 80160300: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_80160304:
    ctx->pc = 0x80160304u;
    // 80160304: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160308:
    ctx->pc = 0x80160308u;
    // 80160308: bl      0x80252AF0
    {
            ctx->lr = 0x8016030Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8016030C:
    ctx->pc = 0x8016030Cu;
    ctx->downcount -= 5;
    // 8016030C: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_80160310:
    ctx->pc = 0x80160310u;
    // 80160310: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_80160314:
    ctx->pc = 0x80160314u;
    // 80160314: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_80160318:
    ctx->pc = 0x80160318u;
    // 80160318: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_8016031C:
    ctx->pc = 0x8016031Cu;
    // 8016031C: bl      0x80252AF0
    {
            ctx->lr = 0x80160320u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160320:
    ctx->pc = 0x80160320u;
    ctx->downcount -= 5;
    // 80160320: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_80160324:
    ctx->pc = 0x80160324u;
    // 80160324: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80160328:
    ctx->pc = 0x80160328u;
    // 80160328: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_8016032C:
    ctx->pc = 0x8016032Cu;
    // 8016032C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160330:
    ctx->pc = 0x80160330u;
    // 80160330: bl      0x80252AF0
    {
            ctx->lr = 0x80160334u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160334:
    ctx->pc = 0x80160334u;
    ctx->downcount -= 5;
    // 80160334: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_80160338:
    ctx->pc = 0x80160338u;
    // 80160338: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_8016033C:
    ctx->pc = 0x8016033Cu;
    // 8016033C: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_80160340:
    ctx->pc = 0x80160340u;
    // 80160340: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160344:
    ctx->pc = 0x80160344u;
    // 80160344: bl      0x80252AF0
    {
            ctx->lr = 0x80160348u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160348:
    ctx->pc = 0x80160348u;
    ctx->downcount -= 5;
    // 80160348: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_8016034C:
    ctx->pc = 0x8016034Cu;
    // 8016034C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80160350:
    ctx->pc = 0x80160350u;
    // 80160350: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_80160354:
    ctx->pc = 0x80160354u;
    // 80160354: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160358:
    ctx->pc = 0x80160358u;
    // 80160358: bl      0x80252AF0
    {
            ctx->lr = 0x8016035Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8016035C:
    ctx->pc = 0x8016035Cu;
    ctx->downcount -= 5;
    // 8016035C: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_80160360:
    ctx->pc = 0x80160360u;
    // 80160360: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80160364:
    ctx->pc = 0x80160364u;
    // 80160364: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_80160368:
    ctx->pc = 0x80160368u;
    // 80160368: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8016036C:
    ctx->pc = 0x8016036Cu;
    // 8016036C: bl      0x80252AF0
    {
            ctx->lr = 0x80160370u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160370:
    ctx->pc = 0x80160370u;
    ctx->downcount -= 5;
    // 80160370: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_80160374:
    ctx->pc = 0x80160374u;
    // 80160374: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_80160378:
    ctx->pc = 0x80160378u;
    // 80160378: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_8016037C:
    ctx->pc = 0x8016037Cu;
    // 8016037C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160380:
    ctx->pc = 0x80160380u;
    // 80160380: bl      0x80252AF0
    {
            ctx->lr = 0x80160384u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160384:
    ctx->pc = 0x80160384u;
    ctx->downcount -= 5;
    // 80160384: lis     r3, 25197
    ctx->gpr[3] = ((u32)(s32)(25197) << 16);

label_80160388:
    ctx->pc = 0x80160388u;
    // 80160388: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_8016038C:
    ctx->pc = 0x8016038Cu;
    // 8016038C: ori     r3, r3, 0x7368
    ctx->gpr[3] = ctx->gpr[3] | 0x7368u;

label_80160390:
    ctx->pc = 0x80160390u;
    // 80160390: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160394:
    ctx->pc = 0x80160394u;
    // 80160394: bl      0x80252AF0
    {
            ctx->lr = 0x80160398u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160398:
    ctx->pc = 0x80160398u;
    ctx->downcount -= 5;
    // 80160398: lis     r3, 25199
    ctx->gpr[3] = ((u32)(s32)(25199) << 16);

label_8016039C:
    ctx->pc = 0x8016039Cu;
    // 8016039C: li      r4, 63
    ctx->gpr[4] = (u32)(s32)(63);

label_801603A0:
    ctx->pc = 0x801603A0u;
    // 801603A0: ori     r3, r3, 0x6479
    ctx->gpr[3] = ctx->gpr[3] | 0x6479u;

label_801603A4:
    ctx->pc = 0x801603A4u;
    // 801603A4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801603A8:
    ctx->pc = 0x801603A8u;
    // 801603A8: bl      0x80252AF0
    {
            ctx->lr = 0x801603ACu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801603AC:
    ctx->pc = 0x801603ACu;
    ctx->downcount -= 5;
    // 801603AC: lis     r3, 25185
    ctx->gpr[3] = ((u32)(s32)(25185) << 16);

label_801603B0:
    ctx->pc = 0x801603B0u;
    // 801603B0: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_801603B4:
    ctx->pc = 0x801603B4u;
    // 801603B4: ori     r3, r3, 0x6E6D
    ctx->gpr[3] = ctx->gpr[3] | 0x6E6Du;

label_801603B8:
    ctx->pc = 0x801603B8u;
    // 801603B8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801603BC:
    ctx->pc = 0x801603BCu;
    // 801603BC: bl      0x80252AF0
    {
            ctx->lr = 0x801603C0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801603C0:
    ctx->pc = 0x801603C0u;
    ctx->downcount -= 5;
    // 801603C0: lis     r3, 27749
    ctx->gpr[3] = ((u32)(s32)(27749) << 16);

label_801603C4:
    ctx->pc = 0x801603C4u;
    // 801603C4: li      r4, 86
    ctx->gpr[4] = (u32)(s32)(86);

label_801603C8:
    ctx->pc = 0x801603C8u;
    // 801603C8: ori     r3, r3, 0x766C
    ctx->gpr[3] = ctx->gpr[3] | 0x766Cu;

label_801603CC:
    ctx->pc = 0x801603CCu;
    // 801603CC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801603D0:
    ctx->pc = 0x801603D0u;
    // 801603D0: bl      0x80252AF0
    {
            ctx->lr = 0x801603D4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801603D4:
    ctx->pc = 0x801603D4u;
    ctx->downcount -= 5;
    // 801603D4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801603D8:
    ctx->pc = 0x801603D8u;
    // 801603D8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801603DC:
    ctx->pc = 0x801603DCu;
    // 801603DC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801603E0:
    ctx->pc = 0x801603E0u;
    // 801603E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801603E4:
    ctx->pc = 0x801603E4u;
    ctx->downcount -= 2;
    // 801603E4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801603E8:
    ctx->pc = 0x801603E8u;
    // 801603E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801603EC:
    ctx->pc = 0x801603ECu;
    ctx->downcount -= 2;
    // 801603EC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801603F0:
    ctx->pc = 0x801603F0u;
    // 801603F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801603F4:
    ctx->pc = 0x801603F4u;
    ctx->downcount -= 10;
    // 801603F4: stwu     r1, -280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-280);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801603F8:
    ctx->pc = 0x801603F8u;
    // 801603F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801603FC:
    ctx->pc = 0x801603FCu;
    // 801603FC: stw     r31, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80160400:
    ctx->pc = 0x80160400u;
    // 80160400: stw     r0, 284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(284);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160404:
    ctx->pc = 0x80160404u;
    // 80160404: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80160408:
    ctx->pc = 0x80160408u;
    // 80160408: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8016040C:
    ctx->pc = 0x8016040Cu;
    // 8016040C: addi    r4, r9, -27616
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(-27616);

label_80160410:
    ctx->pc = 0x80160410u;
    // 80160410: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80160414:
    ctx->pc = 0x80160414u;
    // 80160414: cmpwi   r4, 0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160418:
    ctx->pc = 0x80160418u;
    // 80160418: bc    12, 2, 0x80160428
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160428;
        }
    }

label_8016041C:
    ctx->pc = 0x8016041Cu;
    ctx->downcount -= 2;
    // 8016041C: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_80160420:
    ctx->pc = 0x80160420u;
    // 80160420: bl      0x80287F10
    {
            ctx->lr = 0x80160424u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_80160424:
    ctx->pc = 0x80160424u;
    ctx->downcount -= 1;
    // 80160424: b       0x8016042C
    {
            goto label_8016042C;
    }

label_80160428:
    ctx->pc = 0x80160428u;
    ctx->downcount -= 1;
    // 80160428: stb     r4, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8016042C:
    ctx->pc = 0x8016042Cu;
    ctx->downcount -= 6;
    // 8016042C: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_80160430:
    ctx->pc = 0x80160430u;
    // 80160430: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80160434:
    ctx->pc = 0x80160434u;
    // 80160434: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80160438:
    ctx->pc = 0x80160438u;
    // 80160438: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8016043C:
    ctx->pc = 0x8016043Cu;
    // 8016043C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80160440:
    ctx->pc = 0x80160440u;
    // 80160440: bl      0x8015A93C
    {
            ctx->lr = 0x80160444u;
            ctx->pc = 0x8015A93Cu;
            return;
    }

label_80160444:
    ctx->pc = 0x80160444u;
    ctx->downcount -= 14;
    // 80160444: lis     r11, -32720
    ctx->gpr[11] = ((u32)(s32)(-32720) << 16);

label_80160448:
    ctx->pc = 0x80160448u;
    // 80160448: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8016044C:
    ctx->pc = 0x8016044Cu;
    // 8016044C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80160450:
    ctx->pc = 0x80160450u;
    // 80160450: addi    r9, r9, -27280
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27280);

label_80160454:
    ctx->pc = 0x80160454u;
    // 80160454: lfs     f1, -27008(r11)
    if (!ppc_fp_available_inline(ctx, 0x80160454u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-27008);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80160458:
    ctx->pc = 0x80160458u;
    // 80160458: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8016045C:
    ctx->pc = 0x8016045Cu;
    // 8016045C: stw     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80160460:
    ctx->pc = 0x80160460u;
    // 80160460: stw     r0, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160464:
    ctx->pc = 0x80160464u;
    // 80160464: stw     r0, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160468:
    ctx->pc = 0x80160468u;
    // 80160468: stw     r0, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016046C:
    ctx->pc = 0x8016046Cu;
    // 8016046C: stw     r0, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160470:
    ctx->pc = 0x80160470u;
    // 80160470: stw     r0, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160474:
    ctx->pc = 0x80160474u;
    // 80160474: stw     r0, 700(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160478:
    ctx->pc = 0x80160478u;
    // 80160478: bl      0x8015C028
    {
            ctx->lr = 0x8016047Cu;
            ctx->pc = 0x8015C028u;
            return;
    }

label_8016047C:
    ctx->pc = 0x8016047Cu;
    ctx->downcount -= 7;
    // 8016047C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80160480:
    ctx->pc = 0x80160480u;
    // 80160480: lwz     r0, 284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(284);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160484:
    ctx->pc = 0x80160484u;
    // 80160484: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160488:
    ctx->pc = 0x80160488u;
    // 80160488: lwz     r31, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8016048C:
    ctx->pc = 0x8016048Cu;
    // 8016048C: addi    r1, r1, 280
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(280);

label_80160490:
    ctx->pc = 0x80160490u;
    // 80160490: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160494:
    ctx->pc = 0x80160494u;
    ctx->downcount -= 20;
    // 80160494: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80160498:
    ctx->pc = 0x80160498u;
    // 80160498: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8016049C:
    ctx->pc = 0x8016049Cu;
    // 8016049C: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801604A0:
    ctx->pc = 0x801604A0u;
    // 801604A0: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801604A4:
    ctx->pc = 0x801604A4u;
    // 801604A4: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801604A8:
    ctx->pc = 0x801604A8u;
    // 801604A8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801604AC:
    ctx->pc = 0x801604ACu;
    // 801604AC: addi    r9, r9, -27280
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27280);

label_801604B0:
    ctx->pc = 0x801604B0u;
    // 801604B0: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801604B4:
    ctx->pc = 0x801604B4u;
    // 801604B4: stw     r9, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801604B8:
    ctx->pc = 0x801604B8u;
    // 801604B8: bl      0x80160684
    {
            ctx->lr = 0x801604BCu;
            goto label_80160684;
    }

label_801604BC:
    ctx->pc = 0x801604BCu;
    ctx->downcount -= 2;
    // 801604BC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801604C0:
    ctx->pc = 0x801604C0u;
    // 801604C0: bl      0x800FBC64
    {
            ctx->lr = 0x801604C4u;
            ctx->pc = 0x800FBC64u;
            return;
    }

label_801604C4:
    ctx->pc = 0x801604C4u;
    ctx->downcount -= 1;
    // 801604C4: bl      0x8019D2B0
    {
            ctx->lr = 0x801604C8u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_801604C8:
    ctx->pc = 0x801604C8u;
    ctx->downcount -= 3;
    // 801604C8: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801604CC:
    ctx->pc = 0x801604CCu;
    // 801604CC: lwz     r4, 696(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801604D0:
    ctx->pc = 0x801604D0u;
    // 801604D0: bl      0x8019AC1C
    {
            ctx->lr = 0x801604D4u;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_801604D4:
    ctx->pc = 0x801604D4u;
    ctx->downcount -= 3;
    // 801604D4: lwz     r4, 700(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(700);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801604D8:
    ctx->pc = 0x801604D8u;
    // 801604D8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801604DC:
    ctx->pc = 0x801604DCu;
    // 801604DC: bl      0x8019AC1C
    {
            ctx->lr = 0x801604E0u;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_801604E0:
    ctx->pc = 0x801604E0u;
    ctx->downcount -= 5;
    // 801604E0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801604E4:
    ctx->pc = 0x801604E4u;
    // 801604E4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801604E8:
    ctx->pc = 0x801604E8u;
    // 801604E8: stw     r0, 700(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801604EC:
    ctx->pc = 0x801604ECu;
    // 801604EC: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801604F0:
    ctx->pc = 0x801604F0u;
    // 801604F0: bl      0x8015AE74
    {
            ctx->lr = 0x801604F4u;
            ctx->pc = 0x8015AE74u;
            return;
    }

label_801604F4:
    ctx->pc = 0x801604F4u;
    ctx->downcount -= 16;
    // 801604F4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801604F8:
    ctx->pc = 0x801604F8u;
    // 801604F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801604FC:
    ctx->pc = 0x801604FCu;
    // 801604FC: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80160500:
    ctx->pc = 0x80160500u;
    // 80160500: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80160504:
    ctx->pc = 0x80160504u;
    // 80160504: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160508:
    ctx->pc = 0x80160508u;
    ctx->downcount -= 18;
    // 80160508: stwu     r1, -152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-152);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8016050C:
    ctx->pc = 0x8016050Cu;
    // 8016050C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80160510:
    ctx->pc = 0x80160510u;
    // 80160510: stw     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80160514:
    ctx->pc = 0x80160514u;
    // 80160514: stw     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160518:
    ctx->pc = 0x80160518u;
    // 80160518: lis     r12, 512
    ctx->gpr[12] = ((u32)(s32)(512) << 16);

label_8016051C:
    ctx->pc = 0x8016051Cu;
    // 8016051C: addi    r0, r1, 160
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(160);

label_80160520:
    ctx->pc = 0x80160520u;
    // 80160520: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_80160524:
    ctx->pc = 0x80160524u;
    // 80160524: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160528:
    ctx->pc = 0x80160528u;
    // 80160528: stw     r11, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8016052C:
    ctx->pc = 0x8016052Cu;
    // 8016052C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80160530:
    ctx->pc = 0x80160530u;
    // 80160530: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80160534:
    ctx->pc = 0x80160534u;
    // 80160534: stw     r6, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80160538:
    ctx->pc = 0x80160538u;
    // 80160538: stw     r7, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8016053C:
    ctx->pc = 0x8016053Cu;
    // 8016053C: stw     r8, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80160540:
    ctx->pc = 0x80160540u;
    // 80160540: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80160544:
    ctx->pc = 0x80160544u;
    // 80160544: stw     r10, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80160548:
    ctx->pc = 0x80160548u;
    // 80160548: stw     r12, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8016054C:
    ctx->pc = 0x8016054Cu;
    // 8016054C: bc    4, 6, 0x80160570
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x02000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80160570;
        }
    }

label_80160550:
    ctx->pc = 0x80160550u;
    ctx->downcount -= 8;
    // 80160550: stfd     f1, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x80160550u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_80160554:
    ctx->pc = 0x80160554u;
    // 80160554: stfd     f2, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x80160554u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_80160558:
    ctx->pc = 0x80160558u;
    // 80160558: stfd     f3, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80160558u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_8016055C:
    ctx->pc = 0x8016055Cu;
    // 8016055C: stfd     f4, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8016055Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_80160560:
    ctx->pc = 0x80160560u;
    // 80160560: stfd     f5, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x80160560u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_80160564:
    ctx->pc = 0x80160564u;
    // 80160564: stfd     f6, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x80160564u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_80160568:
    ctx->pc = 0x80160568u;
    // 80160568: stfd     f7, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x80160568u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_8016056C:
    ctx->pc = 0x8016056Cu;
    // 8016056C: stfd     f8, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8016056Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
    }

label_80160570:
    ctx->pc = 0x80160570u;
    ctx->downcount -= 12;
    // 80160570: addi    r11, r1, 128
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(128);

label_80160574:
    ctx->pc = 0x80160574u;
    // 80160574: addi    r9, r1, 112
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(112);

label_80160578:
    ctx->pc = 0x80160578u;
    // 80160578: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016057C:
    ctx->pc = 0x8016057Cu;
    // 8016057C: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80160580:
    ctx->pc = 0x80160580u;
    // 80160580: lwz     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80160584:
    ctx->pc = 0x80160584u;
    // 80160584: or   r6, r9, r9
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80160588:
    ctx->pc = 0x80160588u;
    // 80160588: stw     r12, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8016058C:
    ctx->pc = 0x8016058Cu;
    // 8016058C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80160590:
    ctx->pc = 0x80160590u;
    // 80160590: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160594:
    ctx->pc = 0x80160594u;
    // 80160594: li      r4, 260
    ctx->gpr[4] = (u32)(s32)(260);

label_80160598:
    ctx->pc = 0x80160598u;
    // 80160598: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8016059C:
    ctx->pc = 0x8016059Cu;
    // 8016059C: bl      0x80296720
    {
            ctx->lr = 0x801605A0u;
            ctx->pc = 0x80296720u;
            return;
    }

label_801605A0:
    ctx->pc = 0x801605A0u;
    ctx->downcount -= 8;
    // 801605A0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801605A4:
    ctx->pc = 0x801605A4u;
    // 801605A4: stb     r0, 259(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(259);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801605A8:
    ctx->pc = 0x801605A8u;
    // 801605A8: lwz     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801605AC:
    ctx->pc = 0x801605ACu;
    // 801605AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801605B0:
    ctx->pc = 0x801605B0u;
    // 801605B0: lwz     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801605B4:
    ctx->pc = 0x801605B4u;
    // 801605B4: addi    r1, r1, 152
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(152);

label_801605B8:
    ctx->pc = 0x801605B8u;
    // 801605B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801605BC:
    ctx->pc = 0x801605BCu;
    ctx->downcount -= 17;
    // 801605BC: stwu     r1, -296(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-296);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801605C0:
    ctx->pc = 0x801605C0u;
    // 801605C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801605C4:
    ctx->pc = 0x801605C4u;
    // 801605C4: stmw     r27, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801605C8:
    ctx->pc = 0x801605C8u;
    // 801605C8: stw     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801605CC:
    ctx->pc = 0x801605CCu;
    // 801605CC: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801605D0:
    ctx->pc = 0x801605D0u;
    // 801605D0: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_801605D4:
    ctx->pc = 0x801605D4u;
    // 801605D4: bl      0x8019D2B0
    {
            ctx->lr = 0x801605D8u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_801605D8:
    ctx->pc = 0x801605D8u;
    ctx->downcount -= 4;
    // 801605D8: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801605DC:
    ctx->pc = 0x801605DCu;
    // 801605DC: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_801605E0:
    ctx->pc = 0x801605E0u;
    // 801605E0: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_801605E4:
    ctx->pc = 0x801605E4u;
    // 801605E4: bl      0x80100A40
    {
            ctx->lr = 0x801605E8u;
            ctx->pc = 0x80100A40u;
            return;
    }

label_801605E8:
    ctx->pc = 0x801605E8u;
    ctx->downcount -= 3;
    // 801605E8: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801605EC:
    ctx->pc = 0x801605ECu;
    // 801605EC: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_801605F0:
    ctx->pc = 0x801605F0u;
    // 801605F0: bl      0x80100368
    {
            ctx->lr = 0x801605F4u;
            ctx->pc = 0x80100368u;
            return;
    }

label_801605F4:
    ctx->pc = 0x801605F4u;
    ctx->downcount -= 9;
    // 801605F4: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801605F8:
    ctx->pc = 0x801605F8u;
    // 801605F8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801605FC:
    ctx->pc = 0x801605FCu;
    // 801605FC: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80160600:
    ctx->pc = 0x80160600u;
    // 80160600: stb     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80160604:
    ctx->pc = 0x80160604u;
    // 80160604: addi    r4, r4, -27600
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27600);

label_80160608:
    ctx->pc = 0x80160608u;
    // 80160608: addi    r5, r28, 392
    ctx->gpr[5] = ctx->gpr[28] + (u32)(s32)(392);

label_8016060C:
    ctx->pc = 0x8016060Cu;
    // 8016060C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80160610:
    ctx->pc = 0x80160610u;
    // 80160610: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80160614:
    ctx->pc = 0x80160614u;
    // 80160614: bl      0x8009258C
    {
            ctx->lr = 0x80160618u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80160618:
    ctx->pc = 0x80160618u;
    ctx->downcount -= 4;
    // 80160618: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8016061C:
    ctx->pc = 0x8016061Cu;
    // 8016061C: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_80160620:
    ctx->pc = 0x80160620u;
    // 80160620: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80160624:
    ctx->pc = 0x80160624u;
    // 80160624: bl      0x8019A70C
    {
            ctx->lr = 0x80160628u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80160628:
    ctx->pc = 0x80160628u;
    ctx->downcount -= 13;
    // 80160628: stw     r3, 696(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8016062C:
    ctx->pc = 0x8016062Cu;
    // 8016062C: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80160630:
    ctx->pc = 0x80160630u;
    // 80160630: addi    r9, r30, 3020
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(3020);

label_80160634:
    ctx->pc = 0x80160634u;
    // 80160634: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80160638:
    ctx->pc = 0x80160638u;
    // 80160638: lwz     r0, 3596(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3596);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016063C:
    ctx->pc = 0x8016063Cu;
    // 8016063C: addi    r4, r4, -27576
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27576);

label_80160640:
    ctx->pc = 0x80160640u;
    // 80160640: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80160644:
    ctx->pc = 0x80160644u;
    // 80160644: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80160648:
    ctx->pc = 0x80160648u;
    // 80160648: lwzx    r5, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8016064C:
    ctx->pc = 0x8016064Cu;
    // 8016064C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80160650:
    ctx->pc = 0x80160650u;
    // 80160650: bl      0x8009258C
    {
            ctx->lr = 0x80160654u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80160654:
    ctx->pc = 0x80160654u;
    ctx->downcount -= 4;
    // 80160654: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80160658:
    ctx->pc = 0x80160658u;
    // 80160658: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8016065C:
    ctx->pc = 0x8016065Cu;
    // 8016065C: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80160660:
    ctx->pc = 0x80160660u;
    // 80160660: bl      0x8019A70C
    {
            ctx->lr = 0x80160664u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80160664:
    ctx->pc = 0x80160664u;
    ctx->downcount -= 19;
    // 80160664: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80160668:
    ctx->pc = 0x80160668u;
    // 80160668: stw     r3, 700(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8016066C:
    ctx->pc = 0x8016066Cu;
    // 8016066C: stw     r0, 312(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(312);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160670:
    ctx->pc = 0x80160670u;
    // 80160670: lwz     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160674:
    ctx->pc = 0x80160674u;
    // 80160674: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160678:
    ctx->pc = 0x80160678u;
    // 80160678: lmw     r27, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8016067C:
    ctx->pc = 0x8016067Cu;
    // 8016067C: addi    r1, r1, 296
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(296);

label_80160680:
    ctx->pc = 0x80160680u;
    // 80160680: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160684:
    ctx->pc = 0x80160684u;
    ctx->downcount -= 18;
    // 80160684: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80160688:
    ctx->pc = 0x80160688u;
    // 80160688: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8016068C:
    ctx->pc = 0x8016068Cu;
    // 8016068C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80160690:
    ctx->pc = 0x80160690u;
    // 80160690: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160694:
    ctx->pc = 0x80160694u;
    // 80160694: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80160698:
    ctx->pc = 0x80160698u;
    // 80160698: lwz     r11, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8016069C:
    ctx->pc = 0x8016069Cu;
    // 8016069C: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801606A0:
    ctx->pc = 0x801606A0u;
    // 801606A0: bc    12, 2, 0x801606C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801606C0;
        }
    }

label_801606A4:
    ctx->pc = 0x801606A4u;
    ctx->downcount -= 8;
    // 801606A4: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801606A8:
    ctx->pc = 0x801606A8u;
    // 801606A8: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_801606AC:
    ctx->pc = 0x801606ACu;
    // 801606AC: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801606B0:
    ctx->pc = 0x801606B0u;
    // 801606B0: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801606B4:
    ctx->pc = 0x801606B4u;
    // 801606B4: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801606B8:
    ctx->pc = 0x801606B8u;
    // 801606B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801606BC:
    ctx->pc = 0x801606BCu;
    // 801606BC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801606C0u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801606C0:
    ctx->pc = 0x801606C0u;
    ctx->downcount -= 5;
    // 801606C0: lwz     r11, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801606C4:
    ctx->pc = 0x801606C4u;
    // 801606C4: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801606C8:
    ctx->pc = 0x801606C8u;
    // 801606C8: stw     r30, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801606CC:
    ctx->pc = 0x801606CCu;
    // 801606CC: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801606D0:
    ctx->pc = 0x801606D0u;
    // 801606D0: bc    12, 2, 0x801606F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801606F0;
        }
    }

label_801606D4:
    ctx->pc = 0x801606D4u;
    ctx->downcount -= 8;
    // 801606D4: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801606D8:
    ctx->pc = 0x801606D8u;
    // 801606D8: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_801606DC:
    ctx->pc = 0x801606DCu;
    // 801606DC: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801606E0:
    ctx->pc = 0x801606E0u;
    // 801606E0: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801606E4:
    ctx->pc = 0x801606E4u;
    // 801606E4: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801606E8:
    ctx->pc = 0x801606E8u;
    // 801606E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801606EC:
    ctx->pc = 0x801606ECu;
    // 801606EC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801606F0u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801606F0:
    ctx->pc = 0x801606F0u;
    ctx->downcount -= 4;
    // 801606F0: lwz     r11, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801606F4:
    ctx->pc = 0x801606F4u;
    // 801606F4: stw     r30, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801606F8:
    ctx->pc = 0x801606F8u;
    // 801606F8: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801606FC:
    ctx->pc = 0x801606FCu;
    // 801606FC: bc    12, 2, 0x8016071C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016071C;
        }
    }

label_80160700:
    ctx->pc = 0x80160700u;
    ctx->downcount -= 8;
    // 80160700: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160704:
    ctx->pc = 0x80160704u;
    // 80160704: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80160708:
    ctx->pc = 0x80160708u;
    // 80160708: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8016070C:
    ctx->pc = 0x8016070Cu;
    // 8016070C: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160710:
    ctx->pc = 0x80160710u;
    // 80160710: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80160714:
    ctx->pc = 0x80160714u;
    // 80160714: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160718:
    ctx->pc = 0x80160718u;
    // 80160718: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8016071Cu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8016071C:
    ctx->pc = 0x8016071Cu;
    ctx->downcount -= 17;
    // 8016071C: stw     r30, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80160720:
    ctx->pc = 0x80160720u;
    // 80160720: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160724:
    ctx->pc = 0x80160724u;
    // 80160724: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160728:
    ctx->pc = 0x80160728u;
    // 80160728: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8016072C:
    ctx->pc = 0x8016072Cu;
    // 8016072C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80160730:
    ctx->pc = 0x80160730u;
    // 80160730: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160734:
    ctx->pc = 0x80160734u;
    ctx->downcount -= 20;
    // 80160734: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80160738:
    ctx->pc = 0x80160738u;
    // 80160738: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8016073C:
    ctx->pc = 0x8016073Cu;
    // 8016073C: stmw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80160740:
    ctx->pc = 0x80160740u;
    // 80160740: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160744:
    ctx->pc = 0x80160744u;
    // 80160744: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80160748:
    ctx->pc = 0x80160748u;
    // 80160748: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8016074C:
    ctx->pc = 0x8016074Cu;
    // 8016074C: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80160750:
    ctx->pc = 0x80160750u;
    // 80160750: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80160754:
    ctx->pc = 0x80160754u;
    // 80160754: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80160758:
    ctx->pc = 0x80160758u;
    // 80160758: bl      0x8015E4F4
    {
            ctx->lr = 0x8016075Cu;
            ctx->pc = 0x8015E4F4u;
            return;
    }

label_8016075C:
    ctx->pc = 0x8016075Cu;
    ctx->downcount -= 6;
    // 8016075C: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80160760:
    ctx->pc = 0x80160760u;
    // 80160760: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80160764:
    ctx->pc = 0x80160764u;
    // 80160764: addi    r29, r9, -25052
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-25052);

label_80160768:
    ctx->pc = 0x80160768u;
    // 80160768: lwz     r0, 3592(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016076C:
    ctx->pc = 0x8016076Cu;
    // 8016076C: cmpw    r30, r0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160770:
    ctx->pc = 0x80160770u;
    // 80160770: bc    4, 2, 0x8016080C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8016080C;
        }
    }

label_80160774:
    ctx->pc = 0x80160774u;
    ctx->downcount -= 2;
    // 80160774: cmpwi   r28, 1
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160778:
    ctx->pc = 0x80160778u;
    // 80160778: bc    4, 2, 0x8016080C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8016080C;
        }
    }

label_8016077C:
    ctx->pc = 0x8016077Cu;
    ctx->downcount -= 2;
    // 8016077C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80160780:
    ctx->pc = 0x80160780u;
    // 80160780: bl      0x8015FFD0
    {
            ctx->lr = 0x80160784u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8015FFD0u;
                return;
            }
            goto label_8015FFD0;
    }

label_80160784:
    ctx->pc = 0x80160784u;
    ctx->downcount -= 4;
    // 80160784: stw     r3, 388(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(388);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80160788:
    ctx->pc = 0x80160788u;
    // 80160788: lwz     r0, 3584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3584);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016078C:
    ctx->pc = 0x8016078Cu;
    // 8016078C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160790:
    ctx->pc = 0x80160790u;
    // 80160790: bc    4, 2, 0x801607B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801607B0;
        }
    }

label_80160794:
    ctx->pc = 0x80160794u;
    ctx->downcount -= 5;
    // 80160794: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160798:
    ctx->pc = 0x80160798u;
    // 80160798: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8016079C:
    ctx->pc = 0x8016079Cu;
    // 8016079C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801607A0:
    ctx->pc = 0x801607A0u;
    // 801607A0: lwz     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801607A4:
    ctx->pc = 0x801607A4u;
    // 801607A4: bl      0x801C0BFC
    {
            ctx->lr = 0x801607A8u;
            ctx->pc = 0x801C0BFCu;
            return;
    }

label_801607A8:
    ctx->pc = 0x801607A8u;
    ctx->downcount -= 2;
    // 801607A8: stw     r28, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_801607AC:
    ctx->pc = 0x801607ACu;
    // 801607AC: b       0x801607CC
    {
            goto label_801607CC;
    }

label_801607B0:
    ctx->pc = 0x801607B0u;
    ctx->downcount -= 8;
    // 801607B0: lwz     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801607B4:
    ctx->pc = 0x801607B4u;
    // 801607B4: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_801607B8:
    ctx->pc = 0x801607B8u;
    // 801607B8: lha     r3, 192(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(192);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801607BC:
    ctx->pc = 0x801607BCu;
    // 801607BC: lwz     r0, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801607C0:
    ctx->pc = 0x801607C0u;
    // 801607C0: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801607C4:
    ctx->pc = 0x801607C4u;
    // 801607C4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801607C8:
    ctx->pc = 0x801607C8u;
    // 801607C8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801607CCu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801607CC:
    ctx->pc = 0x801607CCu;
    ctx->downcount -= 4;
    // 801607CC: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801607D0:
    ctx->pc = 0x801607D0u;
    // 801607D0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801607D4:
    ctx->pc = 0x801607D4u;
    // 801607D4: addi    r3, r3, -27404
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27404);

label_801607D8:
    ctx->pc = 0x801607D8u;
    // 801607D8: bl      0x800994E4
    {
            ctx->lr = 0x801607DCu;
            ctx->pc = 0x800994E4u;
            return;
    }

label_801607DC:
    ctx->pc = 0x801607DCu;
    ctx->downcount -= 2;
    // 801607DC: or.   r3, r3, r3
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801607E0:
    ctx->pc = 0x801607E0u;
    // 801607E0: bc    12, 2, 0x8016080C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016080C;
        }
    }

label_801607E4:
    ctx->pc = 0x801607E4u;
    ctx->downcount -= 10;
    // 801607E4: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801607E8:
    ctx->pc = 0x801607E8u;
    // 801607E8: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_801607EC:
    ctx->pc = 0x801607ECu;
    // 801607EC: lfs     f0, -27004(r9)
    if (!ppc_fp_available_inline(ctx, 0x801607ECu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-27004);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801607F0:
    ctx->pc = 0x801607F0u;
    // 801607F0: or   r6, r11, r11
    {
        ctx->gpr[6] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801607F4:
    ctx->pc = 0x801607F4u;
    // 801607F4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801607F8:
    ctx->pc = 0x801607F8u;
    // 801607F8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801607FC:
    ctx->pc = 0x801607FCu;
    // 801607FC: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801607FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80160800:
    ctx->pc = 0x80160800u;
    // 80160800: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x80160800u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80160804:
    ctx->pc = 0x80160804u;
    // 80160804: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x80160804u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80160808:
    ctx->pc = 0x80160808u;
    // 80160808: bl      0x8021B838
    {
            ctx->lr = 0x8016080Cu;
            ctx->pc = 0x8021B838u;
            return;
    }

label_8016080C:
    ctx->pc = 0x8016080Cu;
    ctx->downcount -= 17;
    // 8016080C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80160810:
    ctx->pc = 0x80160810u;
    // 80160810: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160814:
    ctx->pc = 0x80160814u;
    // 80160814: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160818:
    ctx->pc = 0x80160818u;
    // 80160818: lmw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8016081C:
    ctx->pc = 0x8016081Cu;
    // 8016081C: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_80160820:
    ctx->pc = 0x80160820u;
    // 80160820: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160824:
    ctx->pc = 0x80160824u;
    ctx->downcount -= 17;
    // 80160824: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80160828:
    ctx->pc = 0x80160828u;
    // 80160828: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8016082C:
    ctx->pc = 0x8016082Cu;
    // 8016082C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80160830:
    ctx->pc = 0x80160830u;
    // 80160830: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160834:
    ctx->pc = 0x80160834u;
    // 80160834: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80160838:
    ctx->pc = 0x80160838u;
    // 80160838: lwz     r3, 684(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(684);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8016083C:
    ctx->pc = 0x8016083Cu;
    // 8016083C: bl      0x80143B78
    {
            ctx->lr = 0x80160840u;
            ctx->pc = 0x80143B78u;
            return;
    }

label_80160840:
    ctx->pc = 0x80160840u;
    ctx->downcount -= 17;
    // 80160840: stw     r3, 660(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(660);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80160844:
    ctx->pc = 0x80160844u;
    // 80160844: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160848:
    ctx->pc = 0x80160848u;
    // 80160848: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8016084C:
    ctx->pc = 0x8016084Cu;
    // 8016084C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80160850:
    ctx->pc = 0x80160850u;
    // 80160850: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80160854:
    ctx->pc = 0x80160854u;
    // 80160854: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160858:
    ctx->pc = 0x80160858u;
    ctx->downcount -= 17;
    // 80160858: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8016085C:
    ctx->pc = 0x8016085Cu;
    // 8016085C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80160860:
    ctx->pc = 0x80160860u;
    // 80160860: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80160864:
    ctx->pc = 0x80160864u;
    // 80160864: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160868:
    ctx->pc = 0x80160868u;
    // 80160868: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8016086C:
    ctx->pc = 0x8016086Cu;
    // 8016086C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80160870:
    ctx->pc = 0x80160870u;
    // 80160870: bl      0x8015E544
    {
            ctx->lr = 0x80160874u;
            ctx->pc = 0x8015E544u;
            return;
    }

label_80160874:
    ctx->pc = 0x80160874u;
    ctx->downcount -= 9;
    // 80160874: lwz     r11, 684(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(684);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80160878:
    ctx->pc = 0x80160878u;
    // 80160878: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8016087C:
    ctx->pc = 0x8016087Cu;
    // 8016087C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160880:
    ctx->pc = 0x80160880u;
    // 80160880: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160884:
    ctx->pc = 0x80160884u;
    // 80160884: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80160888:
    ctx->pc = 0x80160888u;
    // 80160888: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8016088C:
    ctx->pc = 0x8016088Cu;
    // 8016088C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80160890:
    ctx->pc = 0x80160890u;
    // 80160890: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80160894u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160894:
    ctx->pc = 0x80160894u;
    ctx->downcount -= 9;
    // 80160894: lwz     r11, 688(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(688);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80160898:
    ctx->pc = 0x80160898u;
    // 80160898: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8016089C:
    ctx->pc = 0x8016089Cu;
    // 8016089C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801608A0:
    ctx->pc = 0x801608A0u;
    // 801608A0: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801608A4:
    ctx->pc = 0x801608A4u;
    // 801608A4: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801608A8:
    ctx->pc = 0x801608A8u;
    // 801608A8: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801608AC:
    ctx->pc = 0x801608ACu;
    // 801608AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801608B0:
    ctx->pc = 0x801608B0u;
    // 801608B0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801608B4u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801608B4:
    ctx->pc = 0x801608B4u;
    ctx->downcount -= 16;
    // 801608B4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801608B8:
    ctx->pc = 0x801608B8u;
    // 801608B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801608BC:
    ctx->pc = 0x801608BCu;
    // 801608BC: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801608C0:
    ctx->pc = 0x801608C0u;
    // 801608C0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801608C4:
    ctx->pc = 0x801608C4u;
    // 801608C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801608C8:
    ctx->pc = 0x801608C8u;
    ctx->downcount -= 7;
    // 801608C8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801608CC:
    ctx->pc = 0x801608CCu;
    // 801608CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801608D0:
    ctx->pc = 0x801608D0u;
    // 801608D0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801608D4:
    ctx->pc = 0x801608D4u;
    // 801608D4: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801608D8:
    ctx->pc = 0x801608D8u;
    // 801608D8: lis     r4, 30561
    ctx->gpr[4] = ((u32)(s32)(30561) << 16);

label_801608DC:
    ctx->pc = 0x801608DCu;
    // 801608DC: ori     r4, r4, 0x7665
    ctx->gpr[4] = ctx->gpr[4] | 0x7665u;

label_801608E0:
    ctx->pc = 0x801608E0u;
    // 801608E0: bl      0x80213200
    {
            ctx->lr = 0x801608E4u;
            ctx->pc = 0x80213200u;
            return;
    }

label_801608E4:
    ctx->pc = 0x801608E4u;
    ctx->downcount -= 5;
    // 801608E4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801608E8:
    ctx->pc = 0x801608E8u;
    // 801608E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801608EC:
    ctx->pc = 0x801608ECu;
    // 801608EC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801608F0:
    ctx->pc = 0x801608F0u;
    // 801608F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801608F4:
    ctx->pc = 0x801608F4u;
    ctx->downcount -= 7;
    // 801608F4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801608F8:
    ctx->pc = 0x801608F8u;
    // 801608F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801608FC:
    ctx->pc = 0x801608FCu;
    // 801608FC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160900:
    ctx->pc = 0x80160900u;
    // 80160900: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80160904:
    ctx->pc = 0x80160904u;
    // 80160904: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80160908:
    ctx->pc = 0x80160908u;
    // 80160908: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_8016090C:
    ctx->pc = 0x8016090Cu;
    // 8016090C: bl      0x801602C0
    {
            ctx->lr = 0x80160910u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801602C0u;
                return;
            }
            goto label_801602C0;
    }

label_80160910:
    ctx->pc = 0x80160910u;
    ctx->downcount -= 5;
    // 80160910: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160914:
    ctx->pc = 0x80160914u;
    // 80160914: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160918:
    ctx->pc = 0x80160918u;
    // 80160918: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8016091C:
    ctx->pc = 0x8016091Cu;
    // 8016091C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160920:
    ctx->pc = 0x80160920u;
    ctx->downcount -= 17;
    // 80160920: stwu     r1, -336(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-336);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80160924:
    ctx->pc = 0x80160924u;
    // 80160924: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80160928:
    ctx->pc = 0x80160928u;
    // 80160928: stfd     f31, 328(r1)
    if (!ppc_fp_available_inline(ctx, 0x80160928u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(328);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8016092C:
    ctx->pc = 0x8016092Cu;
    // 8016092C: stmw     r27, 308(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(308);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80160930:
    ctx->pc = 0x80160930u;
    // 80160930: stw     r0, 340(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(340);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160934:
    ctx->pc = 0x80160934u;
    // 80160934: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80160938:
    ctx->pc = 0x80160938u;
    // 80160938: bl      0x8015E4A4
    {
            ctx->lr = 0x8016093Cu;
            ctx->pc = 0x8015E4A4u;
            return;
    }

label_8016093C:
    ctx->pc = 0x8016093Cu;
    ctx->downcount -= 10;
    // 8016093C: addi    r27, r1, 8
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(8);

label_80160940:
    ctx->pc = 0x80160940u;
    // 80160940: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80160944:
    ctx->pc = 0x80160944u;
    // 80160944: addi    r5, r29, 392
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(392);

label_80160948:
    ctx->pc = 0x80160948u;
    // 80160948: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8016094C:
    ctx->pc = 0x8016094Cu;
    // 8016094C: stb     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80160950:
    ctx->pc = 0x80160950u;
    // 80160950: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80160954:
    ctx->pc = 0x80160954u;
    // 80160954: addi    r4, r4, -26900
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-26900);

label_80160958:
    ctx->pc = 0x80160958u;
    // 80160958: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8016095C:
    ctx->pc = 0x8016095Cu;
    // 8016095C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80160960:
    ctx->pc = 0x80160960u;
    // 80160960: bl      0x8009258C
    {
            ctx->lr = 0x80160964u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80160964:
    ctx->pc = 0x80160964u;
    ctx->downcount -= 9;
    // 80160964: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80160968:
    ctx->pc = 0x80160968u;
    // 80160968: addi    r28, r1, 272
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(272);

label_8016096C:
    ctx->pc = 0x8016096Cu;
    // 8016096C: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80160970:
    ctx->pc = 0x80160970u;
    // 80160970: addi    r30, r1, 280
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(280);

label_80160974:
    ctx->pc = 0x80160974u;
    // 80160974: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160978:
    ctx->pc = 0x80160978u;
    // 80160978: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8016097C:
    ctx->pc = 0x8016097Cu;
    // 8016097C: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80160980:
    ctx->pc = 0x80160980u;
    // 80160980: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80160984:
    ctx->pc = 0x80160984u;
    // 80160984: bl      0x801CF88C
    {
            ctx->lr = 0x80160988u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80160988:
    ctx->pc = 0x80160988u;
    ctx->downcount -= 2;
    // 80160988: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_8016098C:
    ctx->pc = 0x8016098Cu;
    // 8016098C: bl      0x80281C60
    {
            ctx->lr = 0x80160990u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80160990:
    ctx->pc = 0x80160990u;
    ctx->downcount -= 5;
    // 80160990: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80160994:
    ctx->pc = 0x80160994u;
    // 80160994: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80160998:
    ctx->pc = 0x80160998u;
    // 80160998: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8016099C:
    ctx->pc = 0x8016099Cu;
    // 8016099C: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801609A0:
    ctx->pc = 0x801609A0u;
    // 801609A0: bl      0x801427A0
    {
            ctx->lr = 0x801609A4u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_801609A4:
    ctx->pc = 0x801609A4u;
    ctx->downcount -= 15;
    // 801609A4: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801609A8:
    ctx->pc = 0x801609A8u;
    // 801609A8: stw     r3, 692(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801609AC:
    ctx->pc = 0x801609ACu;
    // 801609AC: lfs     f31, -26796(r9)
    if (!ppc_fp_available_inline(ctx, 0x801609ACu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-26796);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_801609B0:
    ctx->pc = 0x801609B0u;
    // 801609B0: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_801609B4:
    ctx->pc = 0x801609B4u;
    // 801609B4: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801609B8:
    ctx->pc = 0x801609B8u;
    // 801609B8: stfs     f31, 280(r1)
    if (!ppc_fp_available_inline(ctx, 0x801609B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801609BC:
    ctx->pc = 0x801609BCu;
    // 801609BC: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x801609BCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801609C0:
    ctx->pc = 0x801609C0u;
    // 801609C0: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x801609C0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801609C4:
    ctx->pc = 0x801609C4u;
    // 801609C4: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801609C8:
    ctx->pc = 0x801609C8u;
    // 801609C8: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801609CC:
    ctx->pc = 0x801609CCu;
    // 801609CC: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801609D0:
    ctx->pc = 0x801609D0u;
    // 801609D0: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801609D4:
    ctx->pc = 0x801609D4u;
    // 801609D4: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801609D8:
    ctx->pc = 0x801609D8u;
    // 801609D8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801609DCu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801609DC:
    ctx->pc = 0x801609DCu;
    ctx->downcount -= 7;
    // 801609DC: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801609E0:
    ctx->pc = 0x801609E0u;
    // 801609E0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801609E4:
    ctx->pc = 0x801609E4u;
    // 801609E4: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801609E8:
    ctx->pc = 0x801609E8u;
    // 801609E8: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801609EC:
    ctx->pc = 0x801609ECu;
    // 801609EC: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801609F0:
    ctx->pc = 0x801609F0u;
    // 801609F0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801609F4:
    ctx->pc = 0x801609F4u;
    // 801609F4: bl      0x801CF88C
    {
            ctx->lr = 0x801609F8u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_801609F8:
    ctx->pc = 0x801609F8u;
    ctx->downcount -= 2;
    // 801609F8: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_801609FC:
    ctx->pc = 0x801609FCu;
    // 801609FC: bl      0x80281C60
    {
            ctx->lr = 0x80160A00u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80160A00:
    ctx->pc = 0x80160A00u;
    ctx->downcount -= 6;
    // 80160A00: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80160A04:
    ctx->pc = 0x80160A04u;
    // 80160A04: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80160A08:
    ctx->pc = 0x80160A08u;
    // 80160A08: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80160A0C:
    ctx->pc = 0x80160A0Cu;
    // 80160A0C: addi    r4, r4, -26876
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-26876);

label_80160A10:
    ctx->pc = 0x80160A10u;
    // 80160A10: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80160A14:
    ctx->pc = 0x80160A14u;
    // 80160A14: bl      0x801427A0
    {
            ctx->lr = 0x80160A18u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80160A18:
    ctx->pc = 0x80160A18u;
    ctx->downcount -= 13;
    // 80160A18: stfs     f31, 280(r1)
    if (!ppc_fp_available_inline(ctx, 0x80160A18u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80160A1C:
    ctx->pc = 0x80160A1Cu;
    // 80160A1C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80160A20:
    ctx->pc = 0x80160A20u;
    // 80160A20: stw     r3, 684(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80160A24:
    ctx->pc = 0x80160A24u;
    // 80160A24: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80160A28:
    ctx->pc = 0x80160A28u;
    // 80160A28: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80160A28u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80160A2C:
    ctx->pc = 0x80160A2Cu;
    // 80160A2C: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80160A2Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80160A30:
    ctx->pc = 0x80160A30u;
    // 80160A30: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160A34:
    ctx->pc = 0x80160A34u;
    // 80160A34: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80160A38:
    ctx->pc = 0x80160A38u;
    // 80160A38: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160A3C:
    ctx->pc = 0x80160A3Cu;
    // 80160A3C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80160A40:
    ctx->pc = 0x80160A40u;
    // 80160A40: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80160A44:
    ctx->pc = 0x80160A44u;
    // 80160A44: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80160A48u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160A48:
    ctx->pc = 0x80160A48u;
    ctx->downcount -= 5;
    // 80160A48: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80160A4C:
    ctx->pc = 0x80160A4Cu;
    // 80160A4C: lwz     r3, 684(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(684);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80160A50:
    ctx->pc = 0x80160A50u;
    // 80160A50: lwz     r4, -21452(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21452);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80160A54:
    ctx->pc = 0x80160A54u;
    // 80160A54: addi    r4, r4, -2
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-2);

label_80160A58:
    ctx->pc = 0x80160A58u;
    // 80160A58: bl      0x80143B20
    {
            ctx->lr = 0x80160A5Cu;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80160A5C:
    ctx->pc = 0x80160A5Cu;
    ctx->downcount -= 7;
    // 80160A5C: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80160A60:
    ctx->pc = 0x80160A60u;
    // 80160A60: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80160A64:
    ctx->pc = 0x80160A64u;
    // 80160A64: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80160A68:
    ctx->pc = 0x80160A68u;
    // 80160A68: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160A6C:
    ctx->pc = 0x80160A6Cu;
    // 80160A6C: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80160A70:
    ctx->pc = 0x80160A70u;
    // 80160A70: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80160A74:
    ctx->pc = 0x80160A74u;
    // 80160A74: bl      0x801CF88C
    {
            ctx->lr = 0x80160A78u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80160A78:
    ctx->pc = 0x80160A78u;
    ctx->downcount -= 2;
    // 80160A78: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80160A7C:
    ctx->pc = 0x80160A7Cu;
    // 80160A7C: bl      0x80281C60
    {
            ctx->lr = 0x80160A80u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80160A80:
    ctx->pc = 0x80160A80u;
    ctx->downcount -= 6;
    // 80160A80: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80160A84:
    ctx->pc = 0x80160A84u;
    // 80160A84: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80160A88:
    ctx->pc = 0x80160A88u;
    // 80160A88: addi    r4, r4, -26832
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-26832);

label_80160A8C:
    ctx->pc = 0x80160A8Cu;
    // 80160A8C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80160A90:
    ctx->pc = 0x80160A90u;
    // 80160A90: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80160A94:
    ctx->pc = 0x80160A94u;
    // 80160A94: bl      0x801427A0
    {
            ctx->lr = 0x80160A98u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80160A98:
    ctx->pc = 0x80160A98u;
    ctx->downcount -= 13;
    // 80160A98: stfs     f31, 280(r1)
    if (!ppc_fp_available_inline(ctx, 0x80160A98u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80160A9C:
    ctx->pc = 0x80160A9Cu;
    // 80160A9C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80160AA0:
    ctx->pc = 0x80160AA0u;
    // 80160AA0: stw     r3, 688(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80160AA4:
    ctx->pc = 0x80160AA4u;
    // 80160AA4: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80160AA8:
    ctx->pc = 0x80160AA8u;
    // 80160AA8: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80160AA8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80160AAC:
    ctx->pc = 0x80160AACu;
    // 80160AAC: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80160AACu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80160AB0:
    ctx->pc = 0x80160AB0u;
    // 80160AB0: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160AB4:
    ctx->pc = 0x80160AB4u;
    // 80160AB4: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80160AB8:
    ctx->pc = 0x80160AB8u;
    // 80160AB8: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160ABC:
    ctx->pc = 0x80160ABCu;
    // 80160ABC: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80160AC0:
    ctx->pc = 0x80160AC0u;
    // 80160AC0: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80160AC4:
    ctx->pc = 0x80160AC4u;
    // 80160AC4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80160AC8u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160AC8:
    ctx->pc = 0x80160AC8u;
    ctx->downcount -= 17;
    // 80160AC8: lwz     r0, 340(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(340);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160ACC:
    ctx->pc = 0x80160ACCu;
    // 80160ACC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160AD0:
    ctx->pc = 0x80160AD0u;
    // 80160AD0: lmw     r27, 308(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(308);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80160AD4:
    ctx->pc = 0x80160AD4u;
    // 80160AD4: lfd     f31, 328(r1)
    if (!ppc_fp_available_inline(ctx, 0x80160AD4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(328);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80160AD8:
    ctx->pc = 0x80160AD8u;
    // 80160AD8: addi    r1, r1, 336
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(336);

label_80160ADC:
    ctx->pc = 0x80160ADCu;
    // 80160ADC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160AE0:
    ctx->pc = 0x80160AE0u;
    ctx->downcount -= 18;
    // 80160AE0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80160AE4:
    ctx->pc = 0x80160AE4u;
    // 80160AE4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80160AE8:
    ctx->pc = 0x80160AE8u;
    // 80160AE8: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80160AEC:
    ctx->pc = 0x80160AECu;
    // 80160AEC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160AF0:
    ctx->pc = 0x80160AF0u;
    // 80160AF0: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80160AF4:
    ctx->pc = 0x80160AF4u;
    // 80160AF4: lwz     r0, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160AF8:
    ctx->pc = 0x80160AF8u;
    // 80160AF8: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160AFC:
    ctx->pc = 0x80160AFCu;
    // 80160AFC: bc    4, 2, 0x80160B0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80160B0C;
        }
    }

label_80160B00:
    ctx->pc = 0x80160B00u;
    ctx->downcount -= 2;
    // 80160B00: lwz     r3, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80160B04:
    ctx->pc = 0x80160B04u;
    // 80160B04: bl      0x80143B78
    {
            ctx->lr = 0x80160B08u;
            ctx->pc = 0x80143B78u;
            return;
    }

label_80160B08:
    ctx->pc = 0x80160B08u;
    ctx->downcount -= 1;
    // 80160B08: b       0x80160BB8
    {
            goto label_80160BB8;
    }

label_80160B0C:
    ctx->pc = 0x80160B0Cu;
    ctx->downcount -= 3;
    // 80160B0C: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160B10:
    ctx->pc = 0x80160B10u;
    // 80160B10: lwz     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80160B14:
    ctx->pc = 0x80160B14u;
    // 80160B14: bl      0x801BDA98
    {
            ctx->lr = 0x80160B18u;
            ctx->pc = 0x801BDA98u;
            return;
    }

label_80160B18:
    ctx->pc = 0x80160B18u;
    ctx->downcount -= 2;
    // 80160B18: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160B1C:
    ctx->pc = 0x80160B1Cu;
    // 80160B1C: bc    12, 2, 0x80160BB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160BB4;
        }
    }

label_80160B20:
    ctx->pc = 0x80160B20u;
    ctx->downcount -= 11;
    // 80160B20: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80160B24:
    ctx->pc = 0x80160B24u;
    // 80160B24: lwz     r11, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80160B28:
    ctx->pc = 0x80160B28u;
    // 80160B28: stw     r0, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160B2C:
    ctx->pc = 0x80160B2Cu;
    // 80160B2C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80160B30:
    ctx->pc = 0x80160B30u;
    // 80160B30: lfs     f1, -26772(r9)
    if (!ppc_fp_available_inline(ctx, 0x80160B30u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-26772);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80160B34:
    ctx->pc = 0x80160B34u;
    // 80160B34: lwz     r0, 212(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(212);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160B38:
    ctx->pc = 0x80160B38u;
    // 80160B38: lha     r3, 208(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(208);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80160B3C:
    ctx->pc = 0x80160B3Cu;
    // 80160B3C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160B40:
    ctx->pc = 0x80160B40u;
    // 80160B40: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80160B44:
    ctx->pc = 0x80160B44u;
    // 80160B44: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80160B48u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160B48:
    ctx->pc = 0x80160B48u;
    ctx->downcount -= 13;
    // 80160B48: lwz     r11, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80160B4C:
    ctx->pc = 0x80160B4Cu;
    // 80160B4C: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80160B50:
    ctx->pc = 0x80160B50u;
    // 80160B50: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80160B54:
    ctx->pc = 0x80160B54u;
    // 80160B54: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80160B58:
    ctx->pc = 0x80160B58u;
    // 80160B58: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160B5C:
    ctx->pc = 0x80160B5Cu;
    // 80160B5C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80160B60:
    ctx->pc = 0x80160B60u;
    // 80160B60: lwz     r4, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80160B64:
    ctx->pc = 0x80160B64u;
    // 80160B64: lwz     r0, 148(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(148);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160B68:
    ctx->pc = 0x80160B68u;
    // 80160B68: lha     r3, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80160B6C:
    ctx->pc = 0x80160B6Cu;
    // 80160B6C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160B70:
    ctx->pc = 0x80160B70u;
    // 80160B70: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80160B74:
    ctx->pc = 0x80160B74u;
    // 80160B74: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80160B78u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160B78:
    ctx->pc = 0x80160B78u;
    ctx->downcount -= 9;
    // 80160B78: lwz     r11, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80160B7C:
    ctx->pc = 0x80160B7Cu;
    // 80160B7C: lwz     r4, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80160B80:
    ctx->pc = 0x80160B80u;
    // 80160B80: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160B84:
    ctx->pc = 0x80160B84u;
    // 80160B84: lwz     r0, 132(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160B88:
    ctx->pc = 0x80160B88u;
    // 80160B88: lha     r3, 128(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(128);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80160B8C:
    ctx->pc = 0x80160B8Cu;
    // 80160B8C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160B90:
    ctx->pc = 0x80160B90u;
    // 80160B90: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80160B94:
    ctx->pc = 0x80160B94u;
    // 80160B94: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80160B98u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160B98:
    ctx->pc = 0x80160B98u;
    ctx->downcount -= 8;
    // 80160B98: lwz     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160B9C:
    ctx->pc = 0x80160B9Cu;
    // 80160B9C: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80160BA0:
    ctx->pc = 0x80160BA0u;
    // 80160BA0: lha     r3, 192(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(192);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80160BA4:
    ctx->pc = 0x80160BA4u;
    // 80160BA4: lwz     r0, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160BA8:
    ctx->pc = 0x80160BA8u;
    // 80160BA8: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80160BAC:
    ctx->pc = 0x80160BACu;
    // 80160BAC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160BB0:
    ctx->pc = 0x80160BB0u;
    // 80160BB0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80160BB4u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160BB4:
    ctx->pc = 0x80160BB4u;
    ctx->downcount -= 1;
    // 80160BB4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80160BB8:
    ctx->pc = 0x80160BB8u;
    ctx->downcount -= 16;
    // 80160BB8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160BBC:
    ctx->pc = 0x80160BBCu;
    // 80160BBC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160BC0:
    ctx->pc = 0x80160BC0u;
    // 80160BC0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80160BC4:
    ctx->pc = 0x80160BC4u;
    // 80160BC4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80160BC8:
    ctx->pc = 0x80160BC8u;
    // 80160BC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160BCC:
    ctx->pc = 0x80160BCCu;
    ctx->downcount -= 16;
    // 80160BCC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80160BD0:
    ctx->pc = 0x80160BD0u;
    // 80160BD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80160BD4:
    ctx->pc = 0x80160BD4u;
    // 80160BD4: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80160BD8:
    ctx->pc = 0x80160BD8u;
    // 80160BD8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160BDC:
    ctx->pc = 0x80160BDCu;
    // 80160BDC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80160BE0:
    ctx->pc = 0x80160BE0u;
    // 80160BE0: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80160BE4:
    ctx->pc = 0x80160BE4u;
    ctx->downcount -= 11;
    // 80160BE4: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160BE8:
    ctx->pc = 0x80160BE8u;
    // 80160BE8: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160BEC:
    // 80160BEC: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80160BF0:
    ctx->pc = 0x80160BF0u;
    // 80160BF0: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80160BF4:
    // 80160BF4: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_80160BF8:
    // 80160BF8: cmplw   r10, r11
    {
        u32 val_a = (u32)(ctx->gpr[10]);
        u32 val_b = (u32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160BFC:
    // 80160BFC: bc    12, 0, 0x80160C24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160C24;
        }
    }

label_80160C00:
    ctx->downcount -= 3;
    // 80160C00: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80160C04:
    ctx->pc = 0x80160C04u;
    // 80160C04: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160C08:
    // 80160C08: b       0x80160CFC
    {
            goto label_80160CFC;
    }

label_80160C0C:
    ctx->pc = 0x80160C0Cu;
    ctx->downcount -= 6;
    // 80160C0C: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160C10:
    // 80160C10: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80160C14:
    ctx->pc = 0x80160C14u;
    // 80160C14: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160C18:
    ctx->pc = 0x80160C18u;
    // 80160C18: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80160C1C:
    ctx->pc = 0x80160C1Cu;
    // 80160C1C: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80160C20:
    // 80160C20: b       0x80160BE4
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80160BE4u;
                return;
            }
            goto label_80160BE4;
    }

label_80160C24:
    ctx->downcount -= 2;
    // 80160C24: cmplw   r10, r30
    {
        u32 val_a = (u32)(ctx->gpr[10]);
        u32 val_b = (u32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160C28:
    // 80160C28: bc    12, 0, 0x80160C48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160C48;
        }
    }

label_80160C2C:
    ctx->downcount -= 50;
    // 80160C2C: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_80160C30:
    ctx->pc = 0x80160C30u;
    // 80160C30: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160C34:
    // 80160C34: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80160C38:
    ctx->pc = 0x80160C38u;
    // 80160C38: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80160C3C:
    // 80160C3C: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80160C40:
    ctx->pc = 0x80160C40u;
    // 80160C40: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160C44:
    // 80160C44: b       0x80160CFC
    {
            goto label_80160CFC;
    }

label_80160C48:
    ctx->pc = 0x80160C48u;
    ctx->downcount -= 8;
    // 80160C48: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160C4C:
    // 80160C4C: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80160C50:
    // 80160C50: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160C54:
    // 80160C54: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_80160C58:
    // 80160C58: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_80160C5C:
    // 80160C5C: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_80160C60:
    // 80160C60: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_80160C64:
    // 80160C64: bc    12, 2, 0x80160C84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160C84;
        }
    }

label_80160C68:
    ctx->downcount -= 7;
    // 80160C68: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_80160C6C:
    // 80160C6C: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80160C70:
    // 80160C70: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80160C74:
    // 80160C74: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80160C78:
    ctx->pc = 0x80160C78u;
    // 80160C78: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80160C7C:
    ctx->pc = 0x80160C7Cu;
    // 80160C7C: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80160C80:
    ctx->pc = 0x80160C80u;
    // 80160C80: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80160C84:
    ctx->downcount -= 2;
    // 80160C84: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80160C88:
    // 80160C88: bl      0x80281C60
    {
            ctx->lr = 0x80160C8Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80160C8C:
    ctx->downcount -= 3;
    // 80160C8C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160C90:
    ctx->pc = 0x80160C90u;
    // 80160C90: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80160C94:
    // 80160C94: bc    4, 2, 0x80160CE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80160CE0;
        }
    }

label_80160C98:
    ctx->downcount -= 3;
    // 80160C98: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80160C9C:
    // 80160C9C: cmplwi  r11, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160CA0:
    // 80160CA0: bc    12, 1, 0x80160CCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160CCC;
        }
    }

label_80160CA4:
    ctx->downcount -= 2;
    // 80160CA4: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80160CA8:
    // 80160CA8: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80160CAC:
    ctx->downcount -= 5;
    // 80160CAC: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_80160CB0:
    // 80160CB0: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80160CB4:
    ctx->pc = 0x80160CB4u;
    // 80160CB4: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80160CB8:
    // 80160CB8: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160CBC:
    // 80160CBC: bc    4, 2, 0x80160C0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80160C0Cu;
                return;
            }
            goto label_80160C0C;
        }
    }

label_80160CC0:
    ctx->downcount -= 3;
    // 80160CC0: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_80160CC4:
    // 80160CC4: cmplwi  r11, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160CC8:
    // 80160CC8: bc    4, 1, 0x80160CAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80160CACu;
                return;
            }
            goto label_80160CAC;
        }
    }

label_80160CCC:
    ctx->downcount -= 4;
    // 80160CCC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80160CD0:
    // 80160CD0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80160CD4:
    ctx->pc = 0x80160CD4u;
    // 80160CD4: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160CD8:
    // 80160CD8: bl      0x80281C60
    {
            ctx->lr = 0x80160CDCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80160CDC:
    ctx->pc = 0x80160CDCu;
    ctx->downcount -= 1;
    // 80160CDC: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80160CE0:
    ctx->pc = 0x80160CE0u;
    ctx->downcount -= 7;
    // 80160CE0: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160CE4:
    ctx->pc = 0x80160CE4u;
    // 80160CE4: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160CE8:
    // 80160CE8: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80160CEC:
    // 80160CEC: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80160CF0:
    ctx->pc = 0x80160CF0u;
    // 80160CF0: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160CF4:
    ctx->pc = 0x80160CF4u;
    // 80160CF4: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80160CF8:
    // 80160CF8: b       0x80160BE4
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80160BE4u;
                return;
            }
            goto label_80160BE4;
    }

label_80160CFC:
    ctx->pc = 0x80160CFCu;
    ctx->downcount -= 16;
    // 80160CFC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160D00:
    ctx->pc = 0x80160D00u;
    // 80160D00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160D04:
    ctx->pc = 0x80160D04u;
    // 80160D04: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80160D08:
    ctx->pc = 0x80160D08u;
    // 80160D08: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80160D0C:
    ctx->pc = 0x80160D0Cu;
    // 80160D0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160D10:
    ctx->pc = 0x80160D10u;
    ctx->downcount -= 21;
    // 80160D10: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80160D14:
    ctx->pc = 0x80160D14u;
    // 80160D14: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80160D18:
    ctx->pc = 0x80160D18u;
    // 80160D18: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80160D1C:
    ctx->pc = 0x80160D1Cu;
    // 80160D1C: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160D20:
    ctx->pc = 0x80160D20u;
    // 80160D20: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80160D24:
    ctx->pc = 0x80160D24u;
    // 80160D24: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_80160D28:
    ctx->pc = 0x80160D28u;
    // 80160D28: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80160D2C:
    ctx->pc = 0x80160D2Cu;
    // 80160D2C: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80160D30:
    ctx->pc = 0x80160D30u;
    // 80160D30: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80160D34:
    ctx->pc = 0x80160D34u;
    // 80160D34: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160D38:
    ctx->pc = 0x80160D38u;
    // 80160D38: bc    12, 2, 0x80160D48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160D48;
        }
    }

label_80160D3C:
    ctx->pc = 0x80160D3Cu;
    ctx->downcount -= 3;
    // 80160D3C: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160D40:
    ctx->pc = 0x80160D40u;
    // 80160D40: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160D44:
    ctx->pc = 0x80160D44u;
    // 80160D44: b       0x80160DC8
    {
            goto label_80160DC8;
    }

label_80160D48:
    ctx->pc = 0x80160D48u;
    ctx->downcount -= 7;
    // 80160D48: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_80160D4C:
    ctx->pc = 0x80160D4Cu;
    // 80160D4C: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_80160D50:
    ctx->pc = 0x80160D50u;
    // 80160D50: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_80160D54:
    ctx->pc = 0x80160D54u;
    // 80160D54: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80160D58:
    ctx->pc = 0x80160D58u;
    // 80160D58: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80160D5C:
    ctx->pc = 0x80160D5Cu;
    // 80160D5C: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_80160D60:
    ctx->pc = 0x80160D60u;
    // 80160D60: bl      0x80003EE0
    {
            ctx->lr = 0x80160D64u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_80160D64:
    ctx->pc = 0x80160D64u;
    ctx->downcount -= 3;
    // 80160D64: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160D68:
    ctx->pc = 0x80160D68u;
    // 80160D68: cmpwi   r9, 1
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160D6C:
    ctx->pc = 0x80160D6Cu;
    // 80160D6C: bc    12, 2, 0x80160DC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160DC4;
        }
    }

label_80160D70:
    ctx->pc = 0x80160D70u;
    ctx->downcount -= 9;
    // 80160D70: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_80160D74:
    ctx->pc = 0x80160D74u;
    // 80160D74: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80160D78:
    ctx->pc = 0x80160D78u;
    // 80160D78: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80160D7C:
    ctx->pc = 0x80160D7Cu;
    // 80160D7C: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80160D80:
    ctx->pc = 0x80160D80u;
    // 80160D80: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80160D84:
    ctx->pc = 0x80160D84u;
    // 80160D84: cmpwi   r9, 2
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160D88:
    ctx->pc = 0x80160D88u;
    // 80160D88: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_80160D8C:
    ctx->pc = 0x80160D8Cu;
    // 80160D8C: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80160D90:
    ctx->pc = 0x80160D90u;
    // 80160D90: bc    4, 2, 0x80160D9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80160D9C;
        }
    }

label_80160D94:
    ctx->pc = 0x80160D94u;
    ctx->downcount -= 2;
    // 80160D94: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80160D98:
    ctx->pc = 0x80160D98u;
    // 80160D98: b       0x80160DC4
    {
            goto label_80160DC4;
    }

label_80160D9C:
    loop_80160D9C(ctx);
    if (ctx->pc == 0x80160DBCu) goto label_80160DBC;
    return;
label_80160DA0:
    // 80160DA0: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_80160DA4:
    // 80160DA4: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80160DA8:
    ctx->pc = 0x80160DA8u;
    // 80160DA8: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80160DAC:
    // 80160DAC: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80160DB0:
    // 80160DB0: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80160DB4:
    // 80160DB4: cmpw    r9, r8
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160DB8:
    // 80160DB8: bc    4, 2, 0x80160D9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80160D9Cu;
                return;
            }
            goto label_80160D9C;
        }
    }

label_80160DBC:
    ctx->pc = 0x80160DBCu;
    ctx->downcount -= 2;
    // 80160DBC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80160DC0:
    ctx->pc = 0x80160DC0u;
    // 80160DC0: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160DC4:
    ctx->pc = 0x80160DC4u;
    ctx->downcount -= 1;
    // 80160DC4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80160DC8:
    ctx->pc = 0x80160DC8u;
    ctx->downcount -= 17;
    // 80160DC8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80160DCC:
    ctx->pc = 0x80160DCCu;
    // 80160DCC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160DD0:
    ctx->pc = 0x80160DD0u;
    // 80160DD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160DD4:
    ctx->pc = 0x80160DD4u;
    // 80160DD4: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80160DD8:
    ctx->pc = 0x80160DD8u;
    // 80160DD8: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80160DDC:
    ctx->pc = 0x80160DDCu;
    // 80160DDC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160DE0:
    ctx->pc = 0x80160DE0u;
    ctx->downcount -= 7;
    // 80160DE0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80160DE4:
    ctx->pc = 0x80160DE4u;
    // 80160DE4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80160DE8:
    ctx->pc = 0x80160DE8u;
    // 80160DE8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160DEC:
    ctx->pc = 0x80160DECu;
    // 80160DEC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80160DF0:
    ctx->pc = 0x80160DF0u;
    // 80160DF0: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_80160DF4:
    ctx->pc = 0x80160DF4u;
    // 80160DF4: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160DF8:
    ctx->pc = 0x80160DF8u;
    // 80160DF8: bc    4, 2, 0x80160EF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80160EF4;
        }
    }

label_80160DFC:
    ctx->pc = 0x80160DFCu;
    ctx->downcount -= 2;
    // 80160DFC: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160E00:
    ctx->pc = 0x80160E00u;
    // 80160E00: bc    12, 2, 0x80160EF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160EF4;
        }
    }

label_80160E04:
    ctx->pc = 0x80160E04u;
    ctx->downcount -= 5;
    // 80160E04: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_80160E08:
    ctx->pc = 0x80160E08u;
    // 80160E08: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_80160E0C:
    ctx->pc = 0x80160E0Cu;
    // 80160E0C: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_80160E10:
    ctx->pc = 0x80160E10u;
    // 80160E10: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160E14:
    ctx->pc = 0x80160E14u;
    // 80160E14: bl      0x80252AF0
    {
            ctx->lr = 0x80160E18u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160E18:
    ctx->pc = 0x80160E18u;
    ctx->downcount -= 5;
    // 80160E18: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_80160E1C:
    ctx->pc = 0x80160E1Cu;
    // 80160E1C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80160E20:
    ctx->pc = 0x80160E20u;
    // 80160E20: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_80160E24:
    ctx->pc = 0x80160E24u;
    // 80160E24: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160E28:
    ctx->pc = 0x80160E28u;
    // 80160E28: bl      0x80252AF0
    {
            ctx->lr = 0x80160E2Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160E2C:
    ctx->pc = 0x80160E2Cu;
    ctx->downcount -= 5;
    // 80160E2C: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_80160E30:
    ctx->pc = 0x80160E30u;
    // 80160E30: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_80160E34:
    ctx->pc = 0x80160E34u;
    // 80160E34: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_80160E38:
    ctx->pc = 0x80160E38u;
    // 80160E38: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_80160E3C:
    ctx->pc = 0x80160E3Cu;
    // 80160E3C: bl      0x80252AF0
    {
            ctx->lr = 0x80160E40u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160E40:
    ctx->pc = 0x80160E40u;
    ctx->downcount -= 5;
    // 80160E40: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_80160E44:
    ctx->pc = 0x80160E44u;
    // 80160E44: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80160E48:
    ctx->pc = 0x80160E48u;
    // 80160E48: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_80160E4C:
    ctx->pc = 0x80160E4Cu;
    // 80160E4C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160E50:
    ctx->pc = 0x80160E50u;
    // 80160E50: bl      0x80252AF0
    {
            ctx->lr = 0x80160E54u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160E54:
    ctx->pc = 0x80160E54u;
    ctx->downcount -= 5;
    // 80160E54: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_80160E58:
    ctx->pc = 0x80160E58u;
    // 80160E58: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_80160E5C:
    ctx->pc = 0x80160E5Cu;
    // 80160E5C: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_80160E60:
    ctx->pc = 0x80160E60u;
    // 80160E60: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160E64:
    ctx->pc = 0x80160E64u;
    // 80160E64: bl      0x80252AF0
    {
            ctx->lr = 0x80160E68u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160E68:
    ctx->pc = 0x80160E68u;
    ctx->downcount -= 5;
    // 80160E68: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_80160E6C:
    ctx->pc = 0x80160E6Cu;
    // 80160E6C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80160E70:
    ctx->pc = 0x80160E70u;
    // 80160E70: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_80160E74:
    ctx->pc = 0x80160E74u;
    // 80160E74: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160E78:
    ctx->pc = 0x80160E78u;
    // 80160E78: bl      0x80252AF0
    {
            ctx->lr = 0x80160E7Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160E7C:
    ctx->pc = 0x80160E7Cu;
    ctx->downcount -= 5;
    // 80160E7C: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_80160E80:
    ctx->pc = 0x80160E80u;
    // 80160E80: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80160E84:
    ctx->pc = 0x80160E84u;
    // 80160E84: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_80160E88:
    ctx->pc = 0x80160E88u;
    // 80160E88: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160E8C:
    ctx->pc = 0x80160E8Cu;
    // 80160E8C: bl      0x80252AF0
    {
            ctx->lr = 0x80160E90u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160E90:
    ctx->pc = 0x80160E90u;
    ctx->downcount -= 5;
    // 80160E90: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_80160E94:
    ctx->pc = 0x80160E94u;
    // 80160E94: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_80160E98:
    ctx->pc = 0x80160E98u;
    // 80160E98: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_80160E9C:
    ctx->pc = 0x80160E9Cu;
    // 80160E9C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160EA0:
    ctx->pc = 0x80160EA0u;
    // 80160EA0: bl      0x80252AF0
    {
            ctx->lr = 0x80160EA4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160EA4:
    ctx->pc = 0x80160EA4u;
    ctx->downcount -= 5;
    // 80160EA4: lis     r3, 25197
    ctx->gpr[3] = ((u32)(s32)(25197) << 16);

label_80160EA8:
    ctx->pc = 0x80160EA8u;
    // 80160EA8: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_80160EAC:
    ctx->pc = 0x80160EACu;
    // 80160EAC: ori     r3, r3, 0x7368
    ctx->gpr[3] = ctx->gpr[3] | 0x7368u;

label_80160EB0:
    ctx->pc = 0x80160EB0u;
    // 80160EB0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160EB4:
    ctx->pc = 0x80160EB4u;
    // 80160EB4: bl      0x80252AF0
    {
            ctx->lr = 0x80160EB8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160EB8:
    ctx->pc = 0x80160EB8u;
    ctx->downcount -= 5;
    // 80160EB8: lis     r3, 25199
    ctx->gpr[3] = ((u32)(s32)(25199) << 16);

label_80160EBC:
    ctx->pc = 0x80160EBCu;
    // 80160EBC: li      r4, 63
    ctx->gpr[4] = (u32)(s32)(63);

label_80160EC0:
    ctx->pc = 0x80160EC0u;
    // 80160EC0: ori     r3, r3, 0x6479
    ctx->gpr[3] = ctx->gpr[3] | 0x6479u;

label_80160EC4:
    ctx->pc = 0x80160EC4u;
    // 80160EC4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160EC8:
    ctx->pc = 0x80160EC8u;
    // 80160EC8: bl      0x80252AF0
    {
            ctx->lr = 0x80160ECCu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160ECC:
    ctx->pc = 0x80160ECCu;
    ctx->downcount -= 5;
    // 80160ECC: lis     r3, 25185
    ctx->gpr[3] = ((u32)(s32)(25185) << 16);

label_80160ED0:
    ctx->pc = 0x80160ED0u;
    // 80160ED0: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_80160ED4:
    ctx->pc = 0x80160ED4u;
    // 80160ED4: ori     r3, r3, 0x6E6D
    ctx->gpr[3] = ctx->gpr[3] | 0x6E6Du;

label_80160ED8:
    ctx->pc = 0x80160ED8u;
    // 80160ED8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160EDC:
    ctx->pc = 0x80160EDCu;
    // 80160EDC: bl      0x80252AF0
    {
            ctx->lr = 0x80160EE0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160EE0:
    ctx->pc = 0x80160EE0u;
    ctx->downcount -= 5;
    // 80160EE0: lis     r3, 27749
    ctx->gpr[3] = ((u32)(s32)(27749) << 16);

label_80160EE4:
    ctx->pc = 0x80160EE4u;
    // 80160EE4: li      r4, 86
    ctx->gpr[4] = (u32)(s32)(86);

label_80160EE8:
    ctx->pc = 0x80160EE8u;
    // 80160EE8: ori     r3, r3, 0x766C
    ctx->gpr[3] = ctx->gpr[3] | 0x766Cu;

label_80160EEC:
    ctx->pc = 0x80160EECu;
    // 80160EEC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80160EF0:
    ctx->pc = 0x80160EF0u;
    // 80160EF0: bl      0x80252AF0
    {
            ctx->lr = 0x80160EF4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80160EF4:
    ctx->pc = 0x80160EF4u;
    ctx->downcount -= 5;
    // 80160EF4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160EF8:
    ctx->pc = 0x80160EF8u;
    // 80160EF8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160EFC:
    ctx->pc = 0x80160EFCu;
    // 80160EFC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80160F00:
    ctx->pc = 0x80160F00u;
    // 80160F00: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160F04:
    ctx->pc = 0x80160F04u;
    ctx->downcount -= 2;
    // 80160F04: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80160F08:
    ctx->pc = 0x80160F08u;
    // 80160F08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160F0C:
    ctx->pc = 0x80160F0Cu;
    ctx->downcount -= 2;
    // 80160F0C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80160F10:
    ctx->pc = 0x80160F10u;
    // 80160F10: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160F14:
    ctx->pc = 0x80160F14u;
    ctx->downcount -= 10;
    // 80160F14: stwu     r1, -280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-280);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80160F18:
    ctx->pc = 0x80160F18u;
    // 80160F18: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80160F1C:
    ctx->pc = 0x80160F1Cu;
    // 80160F1C: stw     r31, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80160F20:
    ctx->pc = 0x80160F20u;
    // 80160F20: stw     r0, 284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(284);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160F24:
    ctx->pc = 0x80160F24u;
    // 80160F24: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80160F28:
    ctx->pc = 0x80160F28u;
    // 80160F28: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80160F2C:
    ctx->pc = 0x80160F2Cu;
    // 80160F2C: addi    r4, r9, -26976
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(-26976);

label_80160F30:
    ctx->pc = 0x80160F30u;
    // 80160F30: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80160F34:
    ctx->pc = 0x80160F34u;
    // 80160F34: cmpwi   r4, 0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80160F38:
    ctx->pc = 0x80160F38u;
    // 80160F38: bc    12, 2, 0x80160F48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80160F48;
        }
    }

label_80160F3C:
    ctx->pc = 0x80160F3Cu;
    ctx->downcount -= 2;
    // 80160F3C: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_80160F40:
    ctx->pc = 0x80160F40u;
    // 80160F40: bl      0x80287F10
    {
            ctx->lr = 0x80160F44u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_80160F44:
    ctx->pc = 0x80160F44u;
    ctx->downcount -= 1;
    // 80160F44: b       0x80160F4C
    {
            goto label_80160F4C;
    }

label_80160F48:
    ctx->pc = 0x80160F48u;
    ctx->downcount -= 1;
    // 80160F48: stb     r4, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80160F4C:
    ctx->pc = 0x80160F4Cu;
    ctx->downcount -= 6;
    // 80160F4C: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_80160F50:
    ctx->pc = 0x80160F50u;
    // 80160F50: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80160F54:
    ctx->pc = 0x80160F54u;
    // 80160F54: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80160F58:
    ctx->pc = 0x80160F58u;
    // 80160F58: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80160F5C:
    ctx->pc = 0x80160F5Cu;
    // 80160F5C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80160F60:
    ctx->pc = 0x80160F60u;
    // 80160F60: bl      0x8015A93C
    {
            ctx->lr = 0x80160F64u;
            ctx->pc = 0x8015A93Cu;
            return;
    }

label_80160F64:
    ctx->pc = 0x80160F64u;
    ctx->downcount -= 14;
    // 80160F64: lis     r11, -32720
    ctx->gpr[11] = ((u32)(s32)(-32720) << 16);

label_80160F68:
    ctx->pc = 0x80160F68u;
    // 80160F68: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80160F6C:
    ctx->pc = 0x80160F6Cu;
    // 80160F6C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80160F70:
    ctx->pc = 0x80160F70u;
    // 80160F70: addi    r9, r9, -26720
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-26720);

label_80160F74:
    ctx->pc = 0x80160F74u;
    // 80160F74: lfs     f1, -26448(r11)
    if (!ppc_fp_available_inline(ctx, 0x80160F74u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-26448);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80160F78:
    ctx->pc = 0x80160F78u;
    // 80160F78: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80160F7C:
    ctx->pc = 0x80160F7Cu;
    // 80160F7C: stw     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80160F80:
    ctx->pc = 0x80160F80u;
    // 80160F80: stw     r0, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160F84:
    ctx->pc = 0x80160F84u;
    // 80160F84: stw     r0, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160F88:
    ctx->pc = 0x80160F88u;
    // 80160F88: stw     r0, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160F8C:
    ctx->pc = 0x80160F8Cu;
    // 80160F8C: stw     r0, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160F90:
    ctx->pc = 0x80160F90u;
    // 80160F90: stw     r0, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160F94:
    ctx->pc = 0x80160F94u;
    // 80160F94: stw     r0, 700(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160F98:
    ctx->pc = 0x80160F98u;
    // 80160F98: bl      0x8015C028
    {
            ctx->lr = 0x80160F9Cu;
            ctx->pc = 0x8015C028u;
            return;
    }

label_80160F9C:
    ctx->pc = 0x80160F9Cu;
    ctx->downcount -= 7;
    // 80160F9C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80160FA0:
    ctx->pc = 0x80160FA0u;
    // 80160FA0: lwz     r0, 284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(284);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80160FA4:
    ctx->pc = 0x80160FA4u;
    // 80160FA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80160FA8:
    ctx->pc = 0x80160FA8u;
    // 80160FA8: lwz     r31, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80160FAC:
    ctx->pc = 0x80160FACu;
    // 80160FAC: addi    r1, r1, 280
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(280);

label_80160FB0:
    ctx->pc = 0x80160FB0u;
    // 80160FB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80160FB4:
    ctx->pc = 0x80160FB4u;
    ctx->downcount -= 20;
    // 80160FB4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80160FB8:
    ctx->pc = 0x80160FB8u;
    // 80160FB8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80160FBC:
    ctx->pc = 0x80160FBCu;
    // 80160FBC: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80160FC0:
    ctx->pc = 0x80160FC0u;
    // 80160FC0: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80160FC4:
    ctx->pc = 0x80160FC4u;
    // 80160FC4: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80160FC8:
    ctx->pc = 0x80160FC8u;
    // 80160FC8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80160FCC:
    ctx->pc = 0x80160FCCu;
    // 80160FCC: addi    r9, r9, -26720
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-26720);

label_80160FD0:
    ctx->pc = 0x80160FD0u;
    // 80160FD0: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80160FD4:
    ctx->pc = 0x80160FD4u;
    // 80160FD4: stw     r9, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80160FD8:
    ctx->pc = 0x80160FD8u;
    // 80160FD8: bl      0x801611A8
    {
            ctx->lr = 0x80160FDCu;
            goto label_801611A8;
    }

label_80160FDC:
    ctx->pc = 0x80160FDCu;
    ctx->downcount -= 2;
    // 80160FDC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80160FE0:
    ctx->pc = 0x80160FE0u;
    // 80160FE0: bl      0x800FBC64
    {
            ctx->lr = 0x80160FE4u;
            ctx->pc = 0x800FBC64u;
            return;
    }

label_80160FE4:
    ctx->pc = 0x80160FE4u;
    ctx->downcount -= 1;
    // 80160FE4: bl      0x8019D2B0
    {
            ctx->lr = 0x80160FE8u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_80160FE8:
    ctx->pc = 0x80160FE8u;
    ctx->downcount -= 3;
    // 80160FE8: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80160FEC:
    ctx->pc = 0x80160FECu;
    // 80160FEC: lwz     r4, 696(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80160FF0:
    ctx->pc = 0x80160FF0u;
    // 80160FF0: bl      0x8019AC1C
    {
            ctx->lr = 0x80160FF4u;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_80160FF4:
    ctx->pc = 0x80160FF4u;
    ctx->downcount -= 3;
    // 80160FF4: lwz     r4, 700(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(700);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80160FF8:
    ctx->pc = 0x80160FF8u;
    // 80160FF8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80160FFC:
    ctx->pc = 0x80160FFCu;
    // 80160FFC: bl      0x8019AC1C
    {
            ctx->lr = 0x80161000u;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_80161000:
    ctx->pc = 0x80161000u;
    ctx->downcount -= 5;
    // 80161000: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80161004:
    ctx->pc = 0x80161004u;
    // 80161004: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80161008:
    ctx->pc = 0x80161008u;
    // 80161008: stw     r0, 700(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016100C:
    ctx->pc = 0x8016100Cu;
    // 8016100C: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80161010:
    ctx->pc = 0x80161010u;
    // 80161010: bl      0x8015AE74
    {
            ctx->lr = 0x80161014u;
            ctx->pc = 0x8015AE74u;
            return;
    }

label_80161014:
    ctx->pc = 0x80161014u;
    ctx->downcount -= 16;
    // 80161014: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161018:
    ctx->pc = 0x80161018u;
    // 80161018: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8016101C:
    ctx->pc = 0x8016101Cu;
    // 8016101C: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80161020:
    ctx->pc = 0x80161020u;
    // 80161020: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80161024:
    ctx->pc = 0x80161024u;
    // 80161024: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161028:
    ctx->pc = 0x80161028u;
    ctx->downcount -= 18;
    // 80161028: stwu     r1, -152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-152);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8016102C:
    ctx->pc = 0x8016102Cu;
    // 8016102C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161030:
    ctx->pc = 0x80161030u;
    // 80161030: stw     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80161034:
    ctx->pc = 0x80161034u;
    // 80161034: stw     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161038:
    ctx->pc = 0x80161038u;
    // 80161038: lis     r12, 512
    ctx->gpr[12] = ((u32)(s32)(512) << 16);

label_8016103C:
    ctx->pc = 0x8016103Cu;
    // 8016103C: addi    r0, r1, 160
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(160);

label_80161040:
    ctx->pc = 0x80161040u;
    // 80161040: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_80161044:
    ctx->pc = 0x80161044u;
    // 80161044: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161048:
    ctx->pc = 0x80161048u;
    // 80161048: stw     r11, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8016104C:
    ctx->pc = 0x8016104Cu;
    // 8016104C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161050:
    ctx->pc = 0x80161050u;
    // 80161050: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80161054:
    ctx->pc = 0x80161054u;
    // 80161054: stw     r6, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80161058:
    ctx->pc = 0x80161058u;
    // 80161058: stw     r7, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8016105C:
    ctx->pc = 0x8016105Cu;
    // 8016105C: stw     r8, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80161060:
    ctx->pc = 0x80161060u;
    // 80161060: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80161064:
    ctx->pc = 0x80161064u;
    // 80161064: stw     r10, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80161068:
    ctx->pc = 0x80161068u;
    // 80161068: stw     r12, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8016106C:
    ctx->pc = 0x8016106Cu;
    // 8016106C: bc    4, 6, 0x80161090
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x02000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80161090;
        }
    }

label_80161070:
    ctx->pc = 0x80161070u;
    ctx->downcount -= 8;
    // 80161070: stfd     f1, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161070u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_80161074:
    ctx->pc = 0x80161074u;
    // 80161074: stfd     f2, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161074u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_80161078:
    ctx->pc = 0x80161078u;
    // 80161078: stfd     f3, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161078u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_8016107C:
    ctx->pc = 0x8016107Cu;
    // 8016107C: stfd     f4, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8016107Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_80161080:
    ctx->pc = 0x80161080u;
    // 80161080: stfd     f5, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161080u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_80161084:
    ctx->pc = 0x80161084u;
    // 80161084: stfd     f6, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161084u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_80161088:
    ctx->pc = 0x80161088u;
    // 80161088: stfd     f7, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161088u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_8016108C:
    ctx->pc = 0x8016108Cu;
    // 8016108C: stfd     f8, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8016108Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
    }

label_80161090:
    ctx->pc = 0x80161090u;
    ctx->downcount -= 12;
    // 80161090: addi    r11, r1, 128
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(128);

label_80161094:
    ctx->pc = 0x80161094u;
    // 80161094: addi    r9, r1, 112
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(112);

label_80161098:
    ctx->pc = 0x80161098u;
    // 80161098: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016109C:
    ctx->pc = 0x8016109Cu;
    // 8016109C: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801610A0:
    ctx->pc = 0x801610A0u;
    // 801610A0: lwz     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801610A4:
    ctx->pc = 0x801610A4u;
    // 801610A4: or   r6, r9, r9
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[9];
    }

label_801610A8:
    ctx->pc = 0x801610A8u;
    // 801610A8: stw     r12, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801610AC:
    ctx->pc = 0x801610ACu;
    // 801610AC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801610B0:
    ctx->pc = 0x801610B0u;
    // 801610B0: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801610B4:
    ctx->pc = 0x801610B4u;
    // 801610B4: li      r4, 260
    ctx->gpr[4] = (u32)(s32)(260);

label_801610B8:
    ctx->pc = 0x801610B8u;
    // 801610B8: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801610BC:
    ctx->pc = 0x801610BCu;
    // 801610BC: bl      0x80296720
    {
            ctx->lr = 0x801610C0u;
            ctx->pc = 0x80296720u;
            return;
    }

label_801610C0:
    ctx->pc = 0x801610C0u;
    ctx->downcount -= 8;
    // 801610C0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801610C4:
    ctx->pc = 0x801610C4u;
    // 801610C4: stb     r0, 259(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(259);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801610C8:
    ctx->pc = 0x801610C8u;
    // 801610C8: lwz     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801610CC:
    ctx->pc = 0x801610CCu;
    // 801610CC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801610D0:
    ctx->pc = 0x801610D0u;
    // 801610D0: lwz     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801610D4:
    ctx->pc = 0x801610D4u;
    // 801610D4: addi    r1, r1, 152
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(152);

label_801610D8:
    ctx->pc = 0x801610D8u;
    // 801610D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801610DC:
    ctx->pc = 0x801610DCu;
    ctx->downcount -= 17;
    // 801610DC: stwu     r1, -296(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-296);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801610E0:
    ctx->pc = 0x801610E0u;
    // 801610E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801610E4:
    ctx->pc = 0x801610E4u;
    // 801610E4: stmw     r27, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801610E8:
    ctx->pc = 0x801610E8u;
    // 801610E8: stw     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801610EC:
    ctx->pc = 0x801610ECu;
    // 801610EC: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801610F0:
    ctx->pc = 0x801610F0u;
    // 801610F0: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_801610F4:
    ctx->pc = 0x801610F4u;
    // 801610F4: bl      0x8019D2B0
    {
            ctx->lr = 0x801610F8u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_801610F8:
    ctx->pc = 0x801610F8u;
    ctx->downcount -= 4;
    // 801610F8: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801610FC:
    ctx->pc = 0x801610FCu;
    // 801610FC: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_80161100:
    ctx->pc = 0x80161100u;
    // 80161100: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80161104:
    ctx->pc = 0x80161104u;
    // 80161104: bl      0x80100A40
    {
            ctx->lr = 0x80161108u;
            ctx->pc = 0x80100A40u;
            return;
    }

label_80161108:
    ctx->pc = 0x80161108u;
    ctx->downcount -= 3;
    // 80161108: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8016110C:
    ctx->pc = 0x8016110Cu;
    // 8016110C: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80161110:
    ctx->pc = 0x80161110u;
    // 80161110: bl      0x80100368
    {
            ctx->lr = 0x80161114u;
            ctx->pc = 0x80100368u;
            return;
    }

label_80161114:
    ctx->pc = 0x80161114u;
    ctx->downcount -= 9;
    // 80161114: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161118:
    ctx->pc = 0x80161118u;
    // 80161118: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8016111C:
    ctx->pc = 0x8016111Cu;
    // 8016111C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161120:
    ctx->pc = 0x80161120u;
    // 80161120: stb     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80161124:
    ctx->pc = 0x80161124u;
    // 80161124: addi    r4, r4, -26964
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-26964);

label_80161128:
    ctx->pc = 0x80161128u;
    // 80161128: addi    r5, r28, 392
    ctx->gpr[5] = ctx->gpr[28] + (u32)(s32)(392);

label_8016112C:
    ctx->pc = 0x8016112Cu;
    // 8016112C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80161130:
    ctx->pc = 0x80161130u;
    // 80161130: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161134:
    ctx->pc = 0x80161134u;
    // 80161134: bl      0x8009258C
    {
            ctx->lr = 0x80161138u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80161138:
    ctx->pc = 0x80161138u;
    ctx->downcount -= 4;
    // 80161138: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8016113C:
    ctx->pc = 0x8016113Cu;
    // 8016113C: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80161140:
    ctx->pc = 0x80161140u;
    // 80161140: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80161144:
    ctx->pc = 0x80161144u;
    // 80161144: bl      0x8019A70C
    {
            ctx->lr = 0x80161148u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80161148:
    ctx->pc = 0x80161148u;
    ctx->downcount -= 12;
    // 80161148: stw     r3, 696(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8016114C:
    ctx->pc = 0x8016114Cu;
    // 8016114C: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80161150:
    ctx->pc = 0x80161150u;
    // 80161150: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80161154:
    ctx->pc = 0x80161154u;
    // 80161154: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161158:
    ctx->pc = 0x80161158u;
    // 80161158: lwz     r0, 3600(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3600);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016115C:
    ctx->pc = 0x8016115Cu;
    // 8016115C: addi    r9, r9, -9132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9132);

label_80161160:
    ctx->pc = 0x80161160u;
    // 80161160: addi    r4, r4, -26940
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-26940);

label_80161164:
    ctx->pc = 0x80161164u;
    // 80161164: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80161168:
    ctx->pc = 0x80161168u;
    // 80161168: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8016116C:
    ctx->pc = 0x8016116Cu;
    // 8016116C: lwzx    r5, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80161170:
    ctx->pc = 0x80161170u;
    // 80161170: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161174:
    ctx->pc = 0x80161174u;
    // 80161174: bl      0x8009258C
    {
            ctx->lr = 0x80161178u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80161178:
    ctx->pc = 0x80161178u;
    ctx->downcount -= 4;
    // 80161178: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8016117C:
    ctx->pc = 0x8016117Cu;
    // 8016117C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80161180:
    ctx->pc = 0x80161180u;
    // 80161180: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80161184:
    ctx->pc = 0x80161184u;
    // 80161184: bl      0x8019A70C
    {
            ctx->lr = 0x80161188u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80161188:
    ctx->pc = 0x80161188u;
    ctx->downcount -= 19;
    // 80161188: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8016118C:
    ctx->pc = 0x8016118Cu;
    // 8016118C: stw     r3, 700(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80161190:
    ctx->pc = 0x80161190u;
    // 80161190: stw     r0, 312(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(312);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161194:
    ctx->pc = 0x80161194u;
    // 80161194: lwz     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161198:
    ctx->pc = 0x80161198u;
    // 80161198: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8016119C:
    ctx->pc = 0x8016119Cu;
    // 8016119C: lmw     r27, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801611A0:
    ctx->pc = 0x801611A0u;
    // 801611A0: addi    r1, r1, 296
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(296);

label_801611A4:
    ctx->pc = 0x801611A4u;
    // 801611A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801611A8:
    ctx->pc = 0x801611A8u;
    ctx->downcount -= 18;
    // 801611A8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801611AC:
    ctx->pc = 0x801611ACu;
    // 801611AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801611B0:
    ctx->pc = 0x801611B0u;
    // 801611B0: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801611B4:
    ctx->pc = 0x801611B4u;
    // 801611B4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801611B8:
    ctx->pc = 0x801611B8u;
    // 801611B8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801611BC:
    ctx->pc = 0x801611BCu;
    // 801611BC: lwz     r11, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801611C0:
    ctx->pc = 0x801611C0u;
    // 801611C0: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801611C4:
    ctx->pc = 0x801611C4u;
    // 801611C4: bc    12, 2, 0x801611E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801611E4;
        }
    }

label_801611C8:
    ctx->pc = 0x801611C8u;
    ctx->downcount -= 8;
    // 801611C8: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801611CC:
    ctx->pc = 0x801611CCu;
    // 801611CC: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_801611D0:
    ctx->pc = 0x801611D0u;
    // 801611D0: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801611D4:
    ctx->pc = 0x801611D4u;
    // 801611D4: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801611D8:
    ctx->pc = 0x801611D8u;
    // 801611D8: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801611DC:
    ctx->pc = 0x801611DCu;
    // 801611DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801611E0:
    ctx->pc = 0x801611E0u;
    // 801611E0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801611E4u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801611E4:
    ctx->pc = 0x801611E4u;
    ctx->downcount -= 5;
    // 801611E4: lwz     r11, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801611E8:
    ctx->pc = 0x801611E8u;
    // 801611E8: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801611EC:
    ctx->pc = 0x801611ECu;
    // 801611EC: stw     r30, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801611F0:
    ctx->pc = 0x801611F0u;
    // 801611F0: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801611F4:
    ctx->pc = 0x801611F4u;
    // 801611F4: bc    12, 2, 0x80161214
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161214;
        }
    }

label_801611F8:
    ctx->pc = 0x801611F8u;
    ctx->downcount -= 8;
    // 801611F8: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801611FC:
    ctx->pc = 0x801611FCu;
    // 801611FC: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80161200:
    ctx->pc = 0x80161200u;
    // 80161200: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80161204:
    ctx->pc = 0x80161204u;
    // 80161204: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161208:
    ctx->pc = 0x80161208u;
    // 80161208: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8016120C:
    ctx->pc = 0x8016120Cu;
    // 8016120C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161210:
    ctx->pc = 0x80161210u;
    // 80161210: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80161214u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161214:
    ctx->pc = 0x80161214u;
    ctx->downcount -= 4;
    // 80161214: lwz     r11, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80161218:
    ctx->pc = 0x80161218u;
    // 80161218: stw     r30, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8016121C:
    ctx->pc = 0x8016121Cu;
    // 8016121C: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161220:
    ctx->pc = 0x80161220u;
    // 80161220: bc    12, 2, 0x80161240
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161240;
        }
    }

label_80161224:
    ctx->pc = 0x80161224u;
    ctx->downcount -= 8;
    // 80161224: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161228:
    ctx->pc = 0x80161228u;
    // 80161228: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8016122C:
    ctx->pc = 0x8016122Cu;
    // 8016122C: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80161230:
    ctx->pc = 0x80161230u;
    // 80161230: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161234:
    ctx->pc = 0x80161234u;
    // 80161234: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80161238:
    ctx->pc = 0x80161238u;
    // 80161238: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8016123C:
    ctx->pc = 0x8016123Cu;
    // 8016123C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80161240u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161240:
    ctx->pc = 0x80161240u;
    ctx->downcount -= 17;
    // 80161240: stw     r30, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80161244:
    ctx->pc = 0x80161244u;
    // 80161244: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161248:
    ctx->pc = 0x80161248u;
    // 80161248: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8016124C:
    ctx->pc = 0x8016124Cu;
    // 8016124C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80161250:
    ctx->pc = 0x80161250u;
    // 80161250: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80161254:
    ctx->pc = 0x80161254u;
    // 80161254: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161258:
    ctx->pc = 0x80161258u;
    ctx->downcount -= 20;
    // 80161258: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8016125C:
    ctx->pc = 0x8016125Cu;
    // 8016125C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161260:
    ctx->pc = 0x80161260u;
    // 80161260: stmw     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80161264:
    ctx->pc = 0x80161264u;
    // 80161264: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161268:
    ctx->pc = 0x80161268u;
    // 80161268: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8016126C:
    ctx->pc = 0x8016126Cu;
    // 8016126C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161270:
    ctx->pc = 0x80161270u;
    // 80161270: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80161274:
    ctx->pc = 0x80161274u;
    // 80161274: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80161278:
    ctx->pc = 0x80161278u;
    // 80161278: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8016127C:
    ctx->pc = 0x8016127Cu;
    // 8016127C: bl      0x8015E4F4
    {
            ctx->lr = 0x80161280u;
            ctx->pc = 0x8015E4F4u;
            return;
    }

label_80161280:
    ctx->pc = 0x80161280u;
    ctx->downcount -= 5;
    // 80161280: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80161284:
    ctx->pc = 0x80161284u;
    // 80161284: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161288:
    ctx->pc = 0x80161288u;
    // 80161288: lwz     r0, -21460(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21460);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016128C:
    ctx->pc = 0x8016128Cu;
    // 8016128C: cmpw    r30, r0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161290:
    ctx->pc = 0x80161290u;
    // 80161290: bc    4, 2, 0x80161300
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80161300;
        }
    }

label_80161294:
    ctx->pc = 0x80161294u;
    ctx->downcount -= 2;
    // 80161294: cmpwi   r29, 1
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161298:
    ctx->pc = 0x80161298u;
    // 80161298: bc    4, 2, 0x80161300
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80161300;
        }
    }

label_8016129C:
    ctx->pc = 0x8016129Cu;
    ctx->downcount -= 2;
    // 8016129C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801612A0:
    ctx->pc = 0x801612A0u;
    // 801612A0: bl      0x801613BC
    {
            ctx->lr = 0x801612A4u;
            goto label_801613BC;
    }

label_801612A4:
    ctx->pc = 0x801612A4u;
    ctx->downcount -= 6;
    // 801612A4: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801612A8:
    ctx->pc = 0x801612A8u;
    // 801612A8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801612AC:
    ctx->pc = 0x801612ACu;
    // 801612AC: stw     r3, 388(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(388);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801612B0:
    ctx->pc = 0x801612B0u;
    // 801612B0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801612B4:
    ctx->pc = 0x801612B4u;
    // 801612B4: lwz     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801612B8:
    ctx->pc = 0x801612B8u;
    // 801612B8: bl      0x801C0BFC
    {
            ctx->lr = 0x801612BCu;
            ctx->pc = 0x801C0BFCu;
            return;
    }

label_801612BC:
    ctx->pc = 0x801612BCu;
    ctx->downcount -= 5;
    // 801612BC: stw     r29, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801612C0:
    ctx->pc = 0x801612C0u;
    // 801612C0: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801612C4:
    ctx->pc = 0x801612C4u;
    // 801612C4: addi    r3, r3, -26792
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-26792);

label_801612C8:
    ctx->pc = 0x801612C8u;
    // 801612C8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801612CC:
    ctx->pc = 0x801612CCu;
    // 801612CC: bl      0x800994E4
    {
            ctx->lr = 0x801612D0u;
            ctx->pc = 0x800994E4u;
            return;
    }

label_801612D0:
    ctx->pc = 0x801612D0u;
    ctx->downcount -= 2;
    // 801612D0: or.   r3, r3, r3
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801612D4:
    ctx->pc = 0x801612D4u;
    // 801612D4: bc    12, 2, 0x80161300
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161300;
        }
    }

label_801612D8:
    ctx->pc = 0x801612D8u;
    ctx->downcount -= 10;
    // 801612D8: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801612DC:
    ctx->pc = 0x801612DCu;
    // 801612DC: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_801612E0:
    ctx->pc = 0x801612E0u;
    // 801612E0: lfs     f0, -26444(r9)
    if (!ppc_fp_available_inline(ctx, 0x801612E0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-26444);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801612E4:
    ctx->pc = 0x801612E4u;
    // 801612E4: or   r6, r11, r11
    {
        ctx->gpr[6] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801612E8:
    ctx->pc = 0x801612E8u;
    // 801612E8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801612EC:
    ctx->pc = 0x801612ECu;
    // 801612EC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801612F0:
    ctx->pc = 0x801612F0u;
    // 801612F0: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801612F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801612F4:
    ctx->pc = 0x801612F4u;
    // 801612F4: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x801612F4u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801612F8:
    ctx->pc = 0x801612F8u;
    // 801612F8: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x801612F8u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801612FC:
    ctx->pc = 0x801612FCu;
    // 801612FC: bl      0x8021B838
    {
            ctx->lr = 0x80161300u;
            ctx->pc = 0x8021B838u;
            return;
    }

label_80161300:
    ctx->pc = 0x80161300u;
    ctx->downcount -= 17;
    // 80161300: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80161304:
    ctx->pc = 0x80161304u;
    // 80161304: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161308:
    ctx->pc = 0x80161308u;
    // 80161308: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8016130C:
    ctx->pc = 0x8016130Cu;
    // 8016130C: lmw     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80161310:
    ctx->pc = 0x80161310u;
    // 80161310: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_80161314:
    ctx->pc = 0x80161314u;
    // 80161314: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161318:
    ctx->pc = 0x80161318u;
    ctx->downcount -= 17;
    // 80161318: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8016131C:
    ctx->pc = 0x8016131Cu;
    // 8016131C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161320:
    ctx->pc = 0x80161320u;
    // 80161320: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80161324:
    ctx->pc = 0x80161324u;
    // 80161324: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161328:
    ctx->pc = 0x80161328u;
    // 80161328: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8016132C:
    ctx->pc = 0x8016132Cu;
    // 8016132C: lwz     r3, 684(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(684);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80161330:
    ctx->pc = 0x80161330u;
    // 80161330: bl      0x80143B78
    {
            ctx->lr = 0x80161334u;
            ctx->pc = 0x80143B78u;
            return;
    }

label_80161334:
    ctx->pc = 0x80161334u;
    ctx->downcount -= 17;
    // 80161334: stw     r3, 660(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(660);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80161338:
    ctx->pc = 0x80161338u;
    // 80161338: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016133C:
    ctx->pc = 0x8016133Cu;
    // 8016133C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161340:
    ctx->pc = 0x80161340u;
    // 80161340: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80161344:
    ctx->pc = 0x80161344u;
    // 80161344: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80161348:
    ctx->pc = 0x80161348u;
    // 80161348: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8016134C:
    ctx->pc = 0x8016134Cu;
    ctx->downcount -= 17;
    // 8016134C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80161350:
    ctx->pc = 0x80161350u;
    // 80161350: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161354:
    ctx->pc = 0x80161354u;
    // 80161354: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80161358:
    ctx->pc = 0x80161358u;
    // 80161358: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016135C:
    ctx->pc = 0x8016135Cu;
    // 8016135C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161360:
    ctx->pc = 0x80161360u;
    // 80161360: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80161364:
    ctx->pc = 0x80161364u;
    // 80161364: bl      0x8015E544
    {
            ctx->lr = 0x80161368u;
            ctx->pc = 0x8015E544u;
            return;
    }

label_80161368:
    ctx->pc = 0x80161368u;
    ctx->downcount -= 9;
    // 80161368: lwz     r11, 684(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(684);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8016136C:
    ctx->pc = 0x8016136Cu;
    // 8016136C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80161370:
    ctx->pc = 0x80161370u;
    // 80161370: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161374:
    ctx->pc = 0x80161374u;
    // 80161374: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161378:
    ctx->pc = 0x80161378u;
    // 80161378: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8016137C:
    ctx->pc = 0x8016137Cu;
    // 8016137C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161380:
    ctx->pc = 0x80161380u;
    // 80161380: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80161384:
    ctx->pc = 0x80161384u;
    // 80161384: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80161388u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161388:
    ctx->pc = 0x80161388u;
    ctx->downcount -= 9;
    // 80161388: lwz     r11, 688(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(688);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8016138C:
    ctx->pc = 0x8016138Cu;
    // 8016138C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80161390:
    ctx->pc = 0x80161390u;
    // 80161390: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161394:
    ctx->pc = 0x80161394u;
    // 80161394: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80161398:
    ctx->pc = 0x80161398u;
    // 80161398: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016139C:
    ctx->pc = 0x8016139Cu;
    // 8016139C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801613A0:
    ctx->pc = 0x801613A0u;
    // 801613A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801613A4:
    ctx->pc = 0x801613A4u;
    // 801613A4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801613A8u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801613A8:
    ctx->pc = 0x801613A8u;
    ctx->downcount -= 16;
    // 801613A8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801613AC:
    ctx->pc = 0x801613ACu;
    // 801613AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801613B0:
    ctx->pc = 0x801613B0u;
    // 801613B0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801613B4:
    ctx->pc = 0x801613B4u;
    // 801613B4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801613B8:
    ctx->pc = 0x801613B8u;
    // 801613B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801613BC:
    ctx->pc = 0x801613BCu;
    ctx->downcount -= 2;
    // 801613BC: li      r3, 19
    ctx->gpr[3] = (u32)(s32)(19);

label_801613C0:
    ctx->pc = 0x801613C0u;
    // 801613C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801613C4:
    ctx->pc = 0x801613C4u;
    ctx->downcount -= 7;
    // 801613C4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801613C8:
    ctx->pc = 0x801613C8u;
    // 801613C8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801613CC:
    ctx->pc = 0x801613CCu;
    // 801613CC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801613D0:
    ctx->pc = 0x801613D0u;
    // 801613D0: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801613D4:
    ctx->pc = 0x801613D4u;
    // 801613D4: lis     r4, 30561
    ctx->gpr[4] = ((u32)(s32)(30561) << 16);

label_801613D8:
    ctx->pc = 0x801613D8u;
    // 801613D8: ori     r4, r4, 0x7665
    ctx->gpr[4] = ctx->gpr[4] | 0x7665u;

label_801613DC:
    ctx->pc = 0x801613DCu;
    // 801613DC: bl      0x80213200
    {
            ctx->lr = 0x801613E0u;
            ctx->pc = 0x80213200u;
            return;
    }

label_801613E0:
    ctx->pc = 0x801613E0u;
    ctx->downcount -= 5;
    // 801613E0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801613E4:
    ctx->pc = 0x801613E4u;
    // 801613E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801613E8:
    ctx->pc = 0x801613E8u;
    // 801613E8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801613EC:
    ctx->pc = 0x801613ECu;
    // 801613EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801613F0:
    ctx->pc = 0x801613F0u;
    ctx->downcount -= 7;
    // 801613F0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801613F4:
    ctx->pc = 0x801613F4u;
    // 801613F4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801613F8:
    ctx->pc = 0x801613F8u;
    // 801613F8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801613FC:
    ctx->pc = 0x801613FCu;
    // 801613FC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80161400:
    ctx->pc = 0x80161400u;
    // 80161400: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80161404:
    ctx->pc = 0x80161404u;
    // 80161404: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_80161408:
    ctx->pc = 0x80161408u;
    // 80161408: bl      0x80160DE0
    {
            ctx->lr = 0x8016140Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80160DE0u;
                return;
            }
            goto label_80160DE0;
    }

label_8016140C:
    ctx->pc = 0x8016140Cu;
    ctx->downcount -= 5;
    // 8016140C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161410:
    ctx->pc = 0x80161410u;
    // 80161410: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161414:
    ctx->pc = 0x80161414u;
    // 80161414: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80161418:
    ctx->pc = 0x80161418u;
    // 80161418: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8016141C:
    ctx->pc = 0x8016141Cu;
    ctx->downcount -= 16;
    // 8016141C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80161420:
    ctx->pc = 0x80161420u;
    // 80161420: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161424:
    ctx->pc = 0x80161424u;
    // 80161424: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80161428:
    ctx->pc = 0x80161428u;
    // 80161428: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016142C:
    ctx->pc = 0x8016142Cu;
    // 8016142C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161430:
    ctx->pc = 0x80161430u;
    // 80161430: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80161434:
    ctx->pc = 0x80161434u;
    ctx->downcount -= 11;
    // 80161434: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161438:
    ctx->pc = 0x80161438u;
    // 80161438: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8016143C:
    // 8016143C: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80161440:
    ctx->pc = 0x80161440u;
    // 80161440: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80161444:
    // 80161444: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_80161448:
    // 80161448: cmplw   r10, r11
    {
        u32 val_a = (u32)(ctx->gpr[10]);
        u32 val_b = (u32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016144C:
    // 8016144C: bc    12, 0, 0x80161474
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161474;
        }
    }

label_80161450:
    ctx->downcount -= 3;
    // 80161450: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80161454:
    ctx->pc = 0x80161454u;
    // 80161454: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161458:
    // 80161458: b       0x8016154C
    {
            goto label_8016154C;
    }

label_8016145C:
    ctx->pc = 0x8016145Cu;
    ctx->downcount -= 6;
    // 8016145C: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161460:
    // 80161460: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80161464:
    ctx->pc = 0x80161464u;
    // 80161464: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161468:
    ctx->pc = 0x80161468u;
    // 80161468: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8016146C:
    ctx->pc = 0x8016146Cu;
    // 8016146C: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80161470:
    // 80161470: b       0x80161434
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80161434u;
                return;
            }
            goto label_80161434;
    }

label_80161474:
    ctx->downcount -= 2;
    // 80161474: cmplw   r10, r30
    {
        u32 val_a = (u32)(ctx->gpr[10]);
        u32 val_b = (u32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161478:
    // 80161478: bc    12, 0, 0x80161498
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161498;
        }
    }

label_8016147C:
    ctx->downcount -= 50;
    // 8016147C: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_80161480:
    ctx->pc = 0x80161480u;
    // 80161480: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161484:
    // 80161484: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80161488:
    ctx->pc = 0x80161488u;
    // 80161488: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8016148C:
    // 8016148C: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80161490:
    ctx->pc = 0x80161490u;
    // 80161490: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161494:
    // 80161494: b       0x8016154C
    {
            goto label_8016154C;
    }

label_80161498:
    ctx->pc = 0x80161498u;
    ctx->downcount -= 8;
    // 80161498: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8016149C:
    // 8016149C: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801614A0:
    // 801614A0: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801614A4:
    // 801614A4: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_801614A8:
    // 801614A8: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_801614AC:
    // 801614AC: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_801614B0:
    // 801614B0: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_801614B4:
    // 801614B4: bc    12, 2, 0x801614D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801614D4;
        }
    }

label_801614B8:
    ctx->downcount -= 7;
    // 801614B8: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_801614BC:
    // 801614BC: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801614C0:
    // 801614C0: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801614C4:
    // 801614C4: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801614C8:
    ctx->pc = 0x801614C8u;
    // 801614C8: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801614CC:
    ctx->pc = 0x801614CCu;
    // 801614CC: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801614D0:
    ctx->pc = 0x801614D0u;
    // 801614D0: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801614D4:
    ctx->downcount -= 2;
    // 801614D4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801614D8:
    // 801614D8: bl      0x80281C60
    {
            ctx->lr = 0x801614DCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801614DC:
    ctx->downcount -= 3;
    // 801614DC: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801614E0:
    ctx->pc = 0x801614E0u;
    // 801614E0: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801614E4:
    // 801614E4: bc    4, 2, 0x80161530
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80161530;
        }
    }

label_801614E8:
    ctx->downcount -= 3;
    // 801614E8: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801614EC:
    // 801614EC: cmplwi  r11, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801614F0:
    // 801614F0: bc    12, 1, 0x8016151C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016151C;
        }
    }

label_801614F4:
    ctx->downcount -= 2;
    // 801614F4: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801614F8:
    // 801614F8: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801614FC:
    ctx->downcount -= 5;
    // 801614FC: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_80161500:
    // 80161500: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80161504:
    ctx->pc = 0x80161504u;
    // 80161504: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80161508:
    // 80161508: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016150C:
    // 8016150C: bc    4, 2, 0x8016145C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8016145Cu;
                return;
            }
            goto label_8016145C;
        }
    }

label_80161510:
    ctx->downcount -= 3;
    // 80161510: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_80161514:
    // 80161514: cmplwi  r11, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161518:
    // 80161518: bc    4, 1, 0x801614FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801614FCu;
                return;
            }
            goto label_801614FC;
        }
    }

label_8016151C:
    ctx->downcount -= 4;
    // 8016151C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80161520:
    // 80161520: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80161524:
    ctx->pc = 0x80161524u;
    // 80161524: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161528:
    // 80161528: bl      0x80281C60
    {
            ctx->lr = 0x8016152Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8016152C:
    ctx->pc = 0x8016152Cu;
    ctx->downcount -= 1;
    // 8016152C: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80161530:
    ctx->pc = 0x80161530u;
    ctx->downcount -= 7;
    // 80161530: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161534:
    ctx->pc = 0x80161534u;
    // 80161534: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161538:
    // 80161538: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8016153C:
    // 8016153C: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80161540:
    ctx->pc = 0x80161540u;
    // 80161540: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161544:
    ctx->pc = 0x80161544u;
    // 80161544: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80161548:
    // 80161548: b       0x80161434
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80161434u;
                return;
            }
            goto label_80161434;
    }

label_8016154C:
    ctx->pc = 0x8016154Cu;
    ctx->downcount -= 16;
    // 8016154C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161550:
    ctx->pc = 0x80161550u;
    // 80161550: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161554:
    ctx->pc = 0x80161554u;
    // 80161554: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80161558:
    ctx->pc = 0x80161558u;
    // 80161558: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8016155C:
    ctx->pc = 0x8016155Cu;
    // 8016155C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161560:
    ctx->pc = 0x80161560u;
    ctx->downcount -= 21;
    // 80161560: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80161564:
    ctx->pc = 0x80161564u;
    // 80161564: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161568:
    ctx->pc = 0x80161568u;
    // 80161568: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8016156C:
    ctx->pc = 0x8016156Cu;
    // 8016156C: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161570:
    ctx->pc = 0x80161570u;
    // 80161570: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80161574:
    ctx->pc = 0x80161574u;
    // 80161574: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_80161578:
    ctx->pc = 0x80161578u;
    // 80161578: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_8016157C:
    ctx->pc = 0x8016157Cu;
    // 8016157C: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80161580:
    ctx->pc = 0x80161580u;
    // 80161580: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80161584:
    ctx->pc = 0x80161584u;
    // 80161584: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161588:
    ctx->pc = 0x80161588u;
    // 80161588: bc    12, 2, 0x80161598
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161598;
        }
    }

label_8016158C:
    ctx->pc = 0x8016158Cu;
    ctx->downcount -= 3;
    // 8016158C: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161590:
    ctx->pc = 0x80161590u;
    // 80161590: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161594:
    ctx->pc = 0x80161594u;
    // 80161594: b       0x80161618
    {
            goto label_80161618;
    }

label_80161598:
    ctx->pc = 0x80161598u;
    ctx->downcount -= 7;
    // 80161598: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_8016159C:
    ctx->pc = 0x8016159Cu;
    // 8016159C: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_801615A0:
    ctx->pc = 0x801615A0u;
    // 801615A0: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_801615A4:
    ctx->pc = 0x801615A4u;
    // 801615A4: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801615A8:
    ctx->pc = 0x801615A8u;
    // 801615A8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801615AC:
    ctx->pc = 0x801615ACu;
    // 801615AC: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_801615B0:
    ctx->pc = 0x801615B0u;
    // 801615B0: bl      0x80003EE0
    {
            ctx->lr = 0x801615B4u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_801615B4:
    ctx->pc = 0x801615B4u;
    ctx->downcount -= 3;
    // 801615B4: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801615B8:
    ctx->pc = 0x801615B8u;
    // 801615B8: cmpwi   r9, 1
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801615BC:
    ctx->pc = 0x801615BCu;
    // 801615BC: bc    12, 2, 0x80161614
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161614;
        }
    }

label_801615C0:
    ctx->pc = 0x801615C0u;
    ctx->downcount -= 9;
    // 801615C0: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_801615C4:
    ctx->pc = 0x801615C4u;
    // 801615C4: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801615C8:
    ctx->pc = 0x801615C8u;
    // 801615C8: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801615CC:
    ctx->pc = 0x801615CCu;
    // 801615CC: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801615D0:
    ctx->pc = 0x801615D0u;
    // 801615D0: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801615D4:
    ctx->pc = 0x801615D4u;
    // 801615D4: cmpwi   r9, 2
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801615D8:
    ctx->pc = 0x801615D8u;
    // 801615D8: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_801615DC:
    ctx->pc = 0x801615DCu;
    // 801615DC: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801615E0:
    ctx->pc = 0x801615E0u;
    // 801615E0: bc    4, 2, 0x801615EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801615EC;
        }
    }

label_801615E4:
    ctx->pc = 0x801615E4u;
    ctx->downcount -= 2;
    // 801615E4: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801615E8:
    ctx->pc = 0x801615E8u;
    // 801615E8: b       0x80161614
    {
            goto label_80161614;
    }

label_801615EC:
    loop_801615EC(ctx);
    if (ctx->pc == 0x8016160Cu) goto label_8016160C;
    return;
label_801615F0:
    // 801615F0: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_801615F4:
    // 801615F4: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801615F8:
    ctx->pc = 0x801615F8u;
    // 801615F8: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801615FC:
    // 801615FC: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80161600:
    // 80161600: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80161604:
    // 80161604: cmpw    r9, r8
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161608:
    // 80161608: bc    4, 2, 0x801615EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801615ECu;
                return;
            }
            goto label_801615EC;
        }
    }

label_8016160C:
    ctx->pc = 0x8016160Cu;
    ctx->downcount -= 2;
    // 8016160C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80161610:
    ctx->pc = 0x80161610u;
    // 80161610: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161614:
    ctx->pc = 0x80161614u;
    ctx->downcount -= 1;
    // 80161614: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161618:
    ctx->pc = 0x80161618u;
    ctx->downcount -= 17;
    // 80161618: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8016161C:
    ctx->pc = 0x8016161Cu;
    // 8016161C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161620:
    ctx->pc = 0x80161620u;
    // 80161620: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161624:
    ctx->pc = 0x80161624u;
    // 80161624: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80161628:
    ctx->pc = 0x80161628u;
    // 80161628: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8016162C:
    ctx->pc = 0x8016162Cu;
    // 8016162C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161630:
    ctx->pc = 0x80161630u;
    ctx->downcount -= 7;
    // 80161630: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80161634:
    ctx->pc = 0x80161634u;
    // 80161634: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161638:
    ctx->pc = 0x80161638u;
    // 80161638: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016163C:
    ctx->pc = 0x8016163Cu;
    // 8016163C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80161640:
    ctx->pc = 0x80161640u;
    // 80161640: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_80161644:
    ctx->pc = 0x80161644u;
    // 80161644: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161648:
    ctx->pc = 0x80161648u;
    // 80161648: bc    4, 2, 0x80161708
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80161708;
        }
    }

label_8016164C:
    ctx->pc = 0x8016164Cu;
    ctx->downcount -= 2;
    // 8016164C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161650:
    ctx->pc = 0x80161650u;
    // 80161650: bc    12, 2, 0x80161708
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161708;
        }
    }

label_80161654:
    ctx->pc = 0x80161654u;
    ctx->downcount -= 5;
    // 80161654: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_80161658:
    ctx->pc = 0x80161658u;
    // 80161658: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_8016165C:
    ctx->pc = 0x8016165Cu;
    // 8016165C: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_80161660:
    ctx->pc = 0x80161660u;
    // 80161660: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80161664:
    ctx->pc = 0x80161664u;
    // 80161664: bl      0x80252AF0
    {
            ctx->lr = 0x80161668u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80161668:
    ctx->pc = 0x80161668u;
    ctx->downcount -= 5;
    // 80161668: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_8016166C:
    ctx->pc = 0x8016166Cu;
    // 8016166C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80161670:
    ctx->pc = 0x80161670u;
    // 80161670: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_80161674:
    ctx->pc = 0x80161674u;
    // 80161674: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80161678:
    ctx->pc = 0x80161678u;
    // 80161678: bl      0x80252AF0
    {
            ctx->lr = 0x8016167Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8016167C:
    ctx->pc = 0x8016167Cu;
    ctx->downcount -= 5;
    // 8016167C: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_80161680:
    ctx->pc = 0x80161680u;
    // 80161680: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_80161684:
    ctx->pc = 0x80161684u;
    // 80161684: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_80161688:
    ctx->pc = 0x80161688u;
    // 80161688: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_8016168C:
    ctx->pc = 0x8016168Cu;
    // 8016168C: bl      0x80252AF0
    {
            ctx->lr = 0x80161690u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80161690:
    ctx->pc = 0x80161690u;
    ctx->downcount -= 5;
    // 80161690: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_80161694:
    ctx->pc = 0x80161694u;
    // 80161694: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80161698:
    ctx->pc = 0x80161698u;
    // 80161698: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_8016169C:
    ctx->pc = 0x8016169Cu;
    // 8016169C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801616A0:
    ctx->pc = 0x801616A0u;
    // 801616A0: bl      0x80252AF0
    {
            ctx->lr = 0x801616A4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801616A4:
    ctx->pc = 0x801616A4u;
    ctx->downcount -= 5;
    // 801616A4: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_801616A8:
    ctx->pc = 0x801616A8u;
    // 801616A8: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_801616AC:
    ctx->pc = 0x801616ACu;
    // 801616AC: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_801616B0:
    ctx->pc = 0x801616B0u;
    // 801616B0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801616B4:
    ctx->pc = 0x801616B4u;
    // 801616B4: bl      0x80252AF0
    {
            ctx->lr = 0x801616B8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801616B8:
    ctx->pc = 0x801616B8u;
    ctx->downcount -= 5;
    // 801616B8: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_801616BC:
    ctx->pc = 0x801616BCu;
    // 801616BC: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_801616C0:
    ctx->pc = 0x801616C0u;
    // 801616C0: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_801616C4:
    ctx->pc = 0x801616C4u;
    // 801616C4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801616C8:
    ctx->pc = 0x801616C8u;
    // 801616C8: bl      0x80252AF0
    {
            ctx->lr = 0x801616CCu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801616CC:
    ctx->pc = 0x801616CCu;
    ctx->downcount -= 5;
    // 801616CC: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_801616D0:
    ctx->pc = 0x801616D0u;
    // 801616D0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_801616D4:
    ctx->pc = 0x801616D4u;
    // 801616D4: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_801616D8:
    ctx->pc = 0x801616D8u;
    // 801616D8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801616DC:
    ctx->pc = 0x801616DCu;
    // 801616DC: bl      0x80252AF0
    {
            ctx->lr = 0x801616E0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801616E0:
    ctx->pc = 0x801616E0u;
    ctx->downcount -= 5;
    // 801616E0: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_801616E4:
    ctx->pc = 0x801616E4u;
    // 801616E4: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_801616E8:
    ctx->pc = 0x801616E8u;
    // 801616E8: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_801616EC:
    ctx->pc = 0x801616ECu;
    // 801616EC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801616F0:
    ctx->pc = 0x801616F0u;
    // 801616F0: bl      0x80252AF0
    {
            ctx->lr = 0x801616F4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801616F4:
    ctx->pc = 0x801616F4u;
    ctx->downcount -= 5;
    // 801616F4: lis     r3, 27749
    ctx->gpr[3] = ((u32)(s32)(27749) << 16);

label_801616F8:
    ctx->pc = 0x801616F8u;
    // 801616F8: li      r4, 86
    ctx->gpr[4] = (u32)(s32)(86);

label_801616FC:
    ctx->pc = 0x801616FCu;
    // 801616FC: ori     r3, r3, 0x766C
    ctx->gpr[3] = ctx->gpr[3] | 0x766Cu;

label_80161700:
    ctx->pc = 0x80161700u;
    // 80161700: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80161704:
    ctx->pc = 0x80161704u;
    // 80161704: bl      0x80252AF0
    {
            ctx->lr = 0x80161708u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80161708:
    ctx->pc = 0x80161708u;
    ctx->downcount -= 5;
    // 80161708: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016170C:
    ctx->pc = 0x8016170Cu;
    // 8016170C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161710:
    ctx->pc = 0x80161710u;
    // 80161710: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80161714:
    ctx->pc = 0x80161714u;
    // 80161714: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161718:
    ctx->pc = 0x80161718u;
    ctx->downcount -= 10;
    // 80161718: stwu     r1, -280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-280);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8016171C:
    ctx->pc = 0x8016171Cu;
    // 8016171C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161720:
    ctx->pc = 0x80161720u;
    // 80161720: stw     r31, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80161724:
    ctx->pc = 0x80161724u;
    // 80161724: stw     r0, 284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(284);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161728:
    ctx->pc = 0x80161728u;
    // 80161728: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8016172C:
    ctx->pc = 0x8016172Cu;
    // 8016172C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161730:
    ctx->pc = 0x80161730u;
    // 80161730: addi    r4, r9, -26416
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(-26416);

label_80161734:
    ctx->pc = 0x80161734u;
    // 80161734: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80161738:
    ctx->pc = 0x80161738u;
    // 80161738: cmpwi   r4, 0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016173C:
    ctx->pc = 0x8016173Cu;
    // 8016173C: bc    12, 2, 0x8016174C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016174C;
        }
    }

label_80161740:
    ctx->pc = 0x80161740u;
    ctx->downcount -= 2;
    // 80161740: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_80161744:
    ctx->pc = 0x80161744u;
    // 80161744: bl      0x80287F10
    {
            ctx->lr = 0x80161748u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_80161748:
    ctx->pc = 0x80161748u;
    ctx->downcount -= 1;
    // 80161748: b       0x80161750
    {
            goto label_80161750;
    }

label_8016174C:
    ctx->pc = 0x8016174Cu;
    ctx->downcount -= 1;
    // 8016174C: stb     r4, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80161750:
    ctx->pc = 0x80161750u;
    ctx->downcount -= 6;
    // 80161750: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80161754:
    ctx->pc = 0x80161754u;
    // 80161754: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_80161758:
    ctx->pc = 0x80161758u;
    // 80161758: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8016175C:
    ctx->pc = 0x8016175Cu;
    // 8016175C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80161760:
    ctx->pc = 0x80161760u;
    // 80161760: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80161764:
    ctx->pc = 0x80161764u;
    // 80161764: bl      0x8015A93C
    {
            ctx->lr = 0x80161768u;
            ctx->pc = 0x8015A93Cu;
            return;
    }

label_80161768:
    ctx->pc = 0x80161768u;
    ctx->downcount -= 15;
    // 80161768: lis     r11, -32720
    ctx->gpr[11] = ((u32)(s32)(-32720) << 16);

label_8016176C:
    ctx->pc = 0x8016176Cu;
    // 8016176C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80161770:
    ctx->pc = 0x80161770u;
    // 80161770: lfs     f0, -26056(r11)
    if (!ppc_fp_available_inline(ctx, 0x80161770u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-26056);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80161774:
    ctx->pc = 0x80161774u;
    // 80161774: addi    r9, r9, -26328
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-26328);

label_80161778:
    ctx->pc = 0x80161778u;
    // 80161778: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8016177C:
    ctx->pc = 0x8016177Cu;
    // 8016177C: stw     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80161780:
    ctx->pc = 0x80161780u;
    // 80161780: stw     r0, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161784:
    ctx->pc = 0x80161784u;
    // 80161784: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80161788:
    ctx->pc = 0x80161788u;
    // 80161788: stfs     f0, 688(r31)
    if (!ppc_fp_available_inline(ctx, 0x80161788u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8016178C:
    ctx->pc = 0x8016178Cu;
    // 8016178C: lwz     r0, 284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(284);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161790:
    ctx->pc = 0x80161790u;
    // 80161790: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161794:
    ctx->pc = 0x80161794u;
    // 80161794: lwz     r31, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80161798:
    ctx->pc = 0x80161798u;
    // 80161798: addi    r1, r1, 280
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(280);

label_8016179C:
    ctx->pc = 0x8016179Cu;
    // 8016179C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801617A0:
    ctx->pc = 0x801617A0u;
    ctx->downcount -= 20;
    // 801617A0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801617A4:
    ctx->pc = 0x801617A4u;
    // 801617A4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801617A8:
    ctx->pc = 0x801617A8u;
    // 801617A8: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801617AC:
    ctx->pc = 0x801617ACu;
    // 801617AC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801617B0:
    ctx->pc = 0x801617B0u;
    // 801617B0: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801617B4:
    ctx->pc = 0x801617B4u;
    // 801617B4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801617B8:
    ctx->pc = 0x801617B8u;
    // 801617B8: addi    r9, r9, -26328
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-26328);

label_801617BC:
    ctx->pc = 0x801617BCu;
    // 801617BC: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801617C0:
    ctx->pc = 0x801617C0u;
    // 801617C0: stw     r9, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801617C4:
    ctx->pc = 0x801617C4u;
    // 801617C4: bl      0x801618B0
    {
            ctx->lr = 0x801617C8u;
            goto label_801618B0;
    }

label_801617C8:
    ctx->pc = 0x801617C8u;
    ctx->downcount -= 3;
    // 801617C8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801617CC:
    ctx->pc = 0x801617CCu;
    // 801617CC: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801617D0:
    ctx->pc = 0x801617D0u;
    // 801617D0: bl      0x8015AE74
    {
            ctx->lr = 0x801617D4u;
            ctx->pc = 0x8015AE74u;
            return;
    }

label_801617D4:
    ctx->pc = 0x801617D4u;
    ctx->downcount -= 16;
    // 801617D4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801617D8:
    ctx->pc = 0x801617D8u;
    // 801617D8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801617DC:
    ctx->pc = 0x801617DCu;
    // 801617DC: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801617E0:
    ctx->pc = 0x801617E0u;
    // 801617E0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801617E4:
    ctx->pc = 0x801617E4u;
    // 801617E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801617E8:
    ctx->pc = 0x801617E8u;
    ctx->downcount -= 4;
    // 801617E8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801617EC:
    ctx->pc = 0x801617ECu;
    // 801617EC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801617F0:
    ctx->pc = 0x801617F0u;
    // 801617F0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801617F4:
    ctx->pc = 0x801617F4u;
    // 801617F4: bl      0x8015B390
    {
            ctx->lr = 0x801617F8u;
            ctx->pc = 0x8015B390u;
            return;
    }

label_801617F8:
    ctx->pc = 0x801617F8u;
    ctx->downcount -= 5;
    // 801617F8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801617FC:
    ctx->pc = 0x801617FCu;
    // 801617FC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161800:
    ctx->pc = 0x80161800u;
    // 80161800: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80161804:
    ctx->pc = 0x80161804u;
    // 80161804: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161808:
    ctx->pc = 0x80161808u;
    ctx->downcount -= 16;
    // 80161808: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8016180C:
    ctx->pc = 0x8016180Cu;
    // 8016180C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161810:
    ctx->pc = 0x80161810u;
    // 80161810: stmw     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80161814:
    ctx->pc = 0x80161814u;
    // 80161814: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161818:
    ctx->pc = 0x80161818u;
    // 80161818: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8016181C:
    ctx->pc = 0x8016181Cu;
    // 8016181C: bl      0x8015E4A4
    {
            ctx->lr = 0x80161820u;
            ctx->pc = 0x8015E4A4u;
            return;
    }

label_80161820:
    ctx->pc = 0x80161820u;
    ctx->downcount -= 9;
    // 80161820: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80161824:
    ctx->pc = 0x80161824u;
    // 80161824: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80161828:
    ctx->pc = 0x80161828u;
    // 80161828: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8016182C:
    ctx->pc = 0x8016182Cu;
    // 8016182C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80161830:
    ctx->pc = 0x80161830u;
    // 80161830: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161834:
    ctx->pc = 0x80161834u;
    // 80161834: addi    r30, r30, -26408
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-26408);

label_80161838:
    ctx->pc = 0x80161838u;
    // 80161838: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8016183C:
    ctx->pc = 0x8016183Cu;
    // 8016183C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161840:
    ctx->pc = 0x80161840u;
    // 80161840: bl      0x801CF88C
    {
            ctx->lr = 0x80161844u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80161844:
    ctx->pc = 0x80161844u;
    ctx->downcount -= 2;
    // 80161844: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80161848:
    ctx->pc = 0x80161848u;
    // 80161848: bl      0x80281C60
    {
            ctx->lr = 0x8016184Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8016184C:
    ctx->pc = 0x8016184Cu;
    ctx->downcount -= 5;
    // 8016184C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80161850:
    ctx->pc = 0x80161850u;
    // 80161850: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80161854:
    ctx->pc = 0x80161854u;
    // 80161854: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80161858:
    ctx->pc = 0x80161858u;
    // 80161858: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8016185C:
    ctx->pc = 0x8016185Cu;
    // 8016185C: bl      0x801427A0
    {
            ctx->lr = 0x80161860u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80161860:
    ctx->pc = 0x80161860u;
    ctx->downcount -= 16;
    // 80161860: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80161864:
    ctx->pc = 0x80161864u;
    // 80161864: stw     r3, 684(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80161868:
    ctx->pc = 0x80161868u;
    // 80161868: lfs     f0, -26052(r9)
    if (!ppc_fp_available_inline(ctx, 0x80161868u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-26052);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8016186C:
    ctx->pc = 0x8016186Cu;
    // 8016186C: addi    r11, r1, 16
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(16);

label_80161870:
    ctx->pc = 0x80161870u;
    // 80161870: or   r5, r11, r11
    {
        ctx->gpr[5] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80161874:
    ctx->pc = 0x80161874u;
    // 80161874: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_80161878:
    ctx->pc = 0x80161878u;
    // 80161878: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161878u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8016187C:
    ctx->pc = 0x8016187Cu;
    // 8016187C: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x8016187Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80161880:
    ctx->pc = 0x80161880u;
    // 80161880: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x80161880u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80161884:
    ctx->pc = 0x80161884u;
    // 80161884: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161888:
    ctx->pc = 0x80161888u;
    // 80161888: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8016188C:
    ctx->pc = 0x8016188Cu;
    // 8016188C: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161890:
    ctx->pc = 0x80161890u;
    // 80161890: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80161894:
    ctx->pc = 0x80161894u;
    // 80161894: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80161898:
    ctx->pc = 0x80161898u;
    // 80161898: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8016189Cu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8016189C:
    ctx->pc = 0x8016189Cu;
    ctx->downcount -= 16;
    // 8016189C: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801618A0:
    ctx->pc = 0x801618A0u;
    // 801618A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801618A4:
    ctx->pc = 0x801618A4u;
    // 801618A4: lmw     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801618A8:
    ctx->pc = 0x801618A8u;
    // 801618A8: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_801618AC:
    ctx->pc = 0x801618ACu;
    // 801618AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801618B0:
    ctx->pc = 0x801618B0u;
    ctx->downcount -= 8;
    // 801618B0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801618B4:
    ctx->pc = 0x801618B4u;
    // 801618B4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801618B8:
    ctx->pc = 0x801618B8u;
    // 801618B8: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801618BC:
    ctx->pc = 0x801618BCu;
    // 801618BC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801618C0:
    ctx->pc = 0x801618C0u;
    // 801618C0: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801618C4:
    ctx->pc = 0x801618C4u;
    // 801618C4: lwz     r11, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801618C8:
    ctx->pc = 0x801618C8u;
    // 801618C8: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801618CC:
    ctx->pc = 0x801618CCu;
    // 801618CC: bc    12, 2, 0x801618EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801618EC;
        }
    }

label_801618D0:
    ctx->pc = 0x801618D0u;
    ctx->downcount -= 8;
    // 801618D0: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801618D4:
    ctx->pc = 0x801618D4u;
    // 801618D4: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_801618D8:
    ctx->pc = 0x801618D8u;
    // 801618D8: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801618DC:
    ctx->pc = 0x801618DCu;
    // 801618DC: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801618E0:
    ctx->pc = 0x801618E0u;
    // 801618E0: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801618E4:
    ctx->pc = 0x801618E4u;
    // 801618E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801618E8:
    ctx->pc = 0x801618E8u;
    // 801618E8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801618ECu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801618EC:
    ctx->pc = 0x801618ECu;
    ctx->downcount -= 8;
    // 801618EC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801618F0:
    ctx->pc = 0x801618F0u;
    // 801618F0: stw     r0, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801618F4:
    ctx->pc = 0x801618F4u;
    // 801618F4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801618F8:
    ctx->pc = 0x801618F8u;
    // 801618F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801618FC:
    ctx->pc = 0x801618FCu;
    // 801618FC: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80161900:
    ctx->pc = 0x80161900u;
    // 80161900: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80161904:
    ctx->pc = 0x80161904u;
    // 80161904: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161908:
    ctx->pc = 0x80161908u;
    ctx->downcount -= 8;
    // 80161908: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8016190C:
    ctx->pc = 0x8016190Cu;
    // 8016190C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161910:
    ctx->pc = 0x80161910u;
    // 80161910: stfd     f31, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161910u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80161914:
    ctx->pc = 0x80161914u;
    // 80161914: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80161918:
    ctx->pc = 0x80161918u;
    // 80161918: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016191C:
    ctx->pc = 0x8016191Cu;
    // 8016191C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161920:
    ctx->pc = 0x80161920u;
    // 80161920: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x80161920u)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_80161924:
    ctx->pc = 0x80161924u;
    // 80161924: bl      0x8015BA2C
    {
            ctx->lr = 0x80161928u;
            ctx->pc = 0x8015BA2Cu;
            return;
    }

label_80161928:
    ctx->pc = 0x80161928u;
    ctx->downcount -= 4;
    // 80161928: lwz     r0, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016192C:
    ctx->pc = 0x8016192Cu;
    // 8016192C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80161930:
    ctx->pc = 0x80161930u;
    // 80161930: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161934:
    ctx->pc = 0x80161934u;
    // 80161934: bc    12, 2, 0x80161948
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161948;
        }
    }

label_80161938:
    ctx->pc = 0x80161938u;
    ctx->downcount -= 3;
    // 80161938: lwz     r0, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016193C:
    ctx->pc = 0x8016193Cu;
    // 8016193C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161940:
    ctx->pc = 0x80161940u;
    // 80161940: bc    12, 2, 0x80161948
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161948;
        }
    }

label_80161944:
    ctx->pc = 0x80161944u;
    ctx->downcount -= 1;
    // 80161944: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_80161948:
    ctx->pc = 0x80161948u;
    ctx->downcount -= 2;
    // 80161948: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016194C:
    ctx->pc = 0x8016194Cu;
    // 8016194C: bc    12, 2, 0x80161970
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161970;
        }
    }

label_80161950:
    ctx->pc = 0x80161950u;
    ctx->downcount -= 5;
    // 80161950: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80161954:
    ctx->pc = 0x80161954u;
    // 80161954: lfs     f13, 688(r31)
    if (!ppc_fp_available_inline(ctx, 0x80161954u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80161958:
    ctx->pc = 0x80161958u;
    // 80161958: lfs     f0, -26048(r9)
    if (!ppc_fp_available_inline(ctx, 0x80161958u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-26048);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8016195C:
    ctx->pc = 0x8016195Cu;
    // 8016195C: fcmpu   cr0, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x8016195Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[13], ctx->fpr[0], false);

label_80161960:
    ctx->pc = 0x80161960u;
    // 80161960: bc    4, 1, 0x80161968
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80161968;
        }
    }

label_80161964:
    ctx->pc = 0x80161964u;
    ctx->downcount -= 1;
    // 80161964: li      r3, 8
    ctx->gpr[3] = (u32)(s32)(8);

label_80161968:
    ctx->pc = 0x80161968u;
    ctx->downcount -= 2;
    // 80161968: fadds   f0, f13, f31
    if (!ppc_fp_available_inline(ctx, 0x80161968u)) return;
    ppc_fadds(ctx, 0, 13, 31);

label_8016196C:
    ctx->pc = 0x8016196Cu;
    // 8016196C: stfs     f0, 688(r31)
    if (!ppc_fp_available_inline(ctx, 0x8016196Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80161970:
    ctx->pc = 0x80161970u;
    ctx->downcount -= 7;
    // 80161970: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161974:
    ctx->pc = 0x80161974u;
    // 80161974: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161978:
    ctx->pc = 0x80161978u;
    // 80161978: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8016197C:
    ctx->pc = 0x8016197Cu;
    // 8016197C: lfd     f31, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8016197Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80161980:
    ctx->pc = 0x80161980u;
    // 80161980: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80161984:
    ctx->pc = 0x80161984u;
    // 80161984: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161988:
    ctx->pc = 0x80161988u;
    ctx->downcount -= 7;
    // 80161988: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8016198C:
    ctx->pc = 0x8016198Cu;
    // 8016198C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161990:
    ctx->pc = 0x80161990u;
    // 80161990: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161994:
    ctx->pc = 0x80161994u;
    // 80161994: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80161998:
    ctx->pc = 0x80161998u;
    // 80161998: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8016199C:
    ctx->pc = 0x8016199Cu;
    // 8016199C: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_801619A0:
    ctx->pc = 0x801619A0u;
    // 801619A0: bl      0x80161630
    {
            ctx->lr = 0x801619A4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80161630u;
                return;
            }
            goto label_80161630;
    }

label_801619A4:
    ctx->pc = 0x801619A4u;
    ctx->downcount -= 5;
    // 801619A4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801619A8:
    ctx->pc = 0x801619A8u;
    // 801619A8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801619AC:
    ctx->pc = 0x801619ACu;
    // 801619AC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801619B0:
    ctx->pc = 0x801619B0u;
    // 801619B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801619B4:
    ctx->pc = 0x801619B4u;
    ctx->downcount -= 20;
    // 801619B4: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801619B8:
    ctx->pc = 0x801619B8u;
    // 801619B8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801619BC:
    ctx->pc = 0x801619BCu;
    // 801619BC: stmw     r25, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801619C0:
    ctx->pc = 0x801619C0u;
    // 801619C0: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801619C4:
    ctx->pc = 0x801619C4u;
    // 801619C4: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801619C8:
    ctx->pc = 0x801619C8u;
    // 801619C8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801619CC:
    ctx->pc = 0x801619CCu;
    // 801619CC: addi    r9, r9, -25672
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-25672);

label_801619D0:
    ctx->pc = 0x801619D0u;
    // 801619D0: or   r25, r4, r4
    {
        ctx->gpr[25] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801619D4:
    ctx->pc = 0x801619D4u;
    // 801619D4: stw     r9, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801619D8:
    ctx->pc = 0x801619D8u;
    // 801619D8: bl      0x801629A8
    {
            ctx->lr = 0x801619DCu;
            goto label_801629A8;
    }

label_801619DC:
    ctx->pc = 0x801619DCu;
    ctx->downcount -= 2;
    // 801619DC: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801619E0:
    ctx->pc = 0x801619E0u;
    // 801619E0: bl      0x8019D2B0
    {
            ctx->lr = 0x801619E4u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_801619E4:
    ctx->pc = 0x801619E4u;
    ctx->downcount -= 7;
    // 801619E4: addi    r11, r30, 704
    ctx->gpr[11] = ctx->gpr[30] + (u32)(s32)(704);

label_801619E8:
    ctx->pc = 0x801619E8u;
    // 801619E8: lwz     r9, 704(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(704);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801619EC:
    ctx->pc = 0x801619ECu;
    // 801619EC: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801619F0:
    ctx->pc = 0x801619F0u;
    // 801619F0: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801619F4:
    ctx->pc = 0x801619F4u;
    // 801619F4: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801619F8:
    ctx->pc = 0x801619F8u;
    // 801619F8: rlwinm. r9, r0, 30, 2, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801619FC:
    ctx->pc = 0x801619FCu;
    // 801619FC: bc    12, 2, 0x80161A44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161A44;
        }
    }

label_80161A00:
    ctx->pc = 0x80161A00u;
    ctx->downcount -= 3;
    // 80161A00: or   r28, r11, r11
    {
        ctx->gpr[28] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80161A04:
    ctx->pc = 0x80161A04u;
    // 80161A04: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80161A08:
    ctx->pc = 0x80161A08u;
    // 80161A08: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80161A0C:
    ctx->pc = 0x80161A0Cu;
    ctx->downcount -= 5;
    // 80161A0C: lwz     r9, 704(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(704);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161A10:
    // 80161A10: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80161A14:
    // 80161A14: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_80161A18:
    ctx->pc = 0x80161A18u;
    // 80161A18: lwzx    r4, r9, r31
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[31];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80161A1C:
    // 80161A1C: bl      0x8019AC1C
    {
            ctx->lr = 0x80161A20u;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_80161A20:
    ctx->pc = 0x80161A20u;
    ctx->downcount -= 9;
    // 80161A20: lwz     r9, 704(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(704);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161A24:
    ctx->pc = 0x80161A24u;
    // 80161A24: stwx    r26, r9, r31
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80161A28:
    // 80161A28: addi    r31, r31, 4
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(4);

label_80161A2C:
    ctx->pc = 0x80161A2Cu;
    // 80161A2C: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161A30:
    ctx->pc = 0x80161A30u;
    // 80161A30: lwz     r9, 704(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(704);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161A34:
    // 80161A34: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80161A38:
    // 80161A38: srawi r0, r0, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[0] = value;
        } else if (sh > 31) {
            ctx->gpr[0] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[0] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80161A3C:
    // 80161A3C: cmplw   r29, r0
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161A40:
    // 80161A40: bc    12, 0, 0x80161A0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80161A0Cu;
                return;
            }
            goto label_80161A0C;
        }
    }

label_80161A44:
    ctx->pc = 0x80161A44u;
    ctx->downcount -= 4;
    // 80161A44: lwz     r3, 704(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(704);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80161A48:
    ctx->pc = 0x80161A48u;
    // 80161A48: addi    r9, r30, 704
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(704);

label_80161A4C:
    ctx->pc = 0x80161A4Cu;
    // 80161A4C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161A50:
    ctx->pc = 0x80161A50u;
    // 80161A50: bc    12, 2, 0x80161A74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161A74;
        }
    }

label_80161A54:
    ctx->pc = 0x80161A54u;
    ctx->downcount -= 5;
    // 80161A54: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161A58:
    ctx->pc = 0x80161A58u;
    // 80161A58: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80161A5C:
    ctx->pc = 0x80161A5Cu;
    // 80161A5C: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80161A60:
    ctx->pc = 0x80161A60u;
    // 80161A60: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161A64:
    ctx->pc = 0x80161A64u;
    // 80161A64: bc    4, 1, 0x80161A70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80161A70;
        }
    }

label_80161A68:
    ctx->pc = 0x80161A68u;
    ctx->downcount -= 1;
    // 80161A68: bl      0x80281D80
    {
            ctx->lr = 0x80161A6Cu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80161A6C:
    ctx->pc = 0x80161A6Cu;
    ctx->downcount -= 1;
    // 80161A6C: b       0x80161A74
    {
            goto label_80161A74;
    }

label_80161A70:
    ctx->pc = 0x80161A70u;
    ctx->downcount -= 1;
    // 80161A70: bl      0x8001D934
    {
            ctx->lr = 0x80161A74u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80161A74:
    ctx->pc = 0x80161A74u;
    ctx->downcount -= 3;
    // 80161A74: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80161A78:
    ctx->pc = 0x80161A78u;
    // 80161A78: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80161A7C:
    ctx->pc = 0x80161A7Cu;
    // 80161A7C: bl      0x8015AE74
    {
            ctx->lr = 0x80161A80u;
            ctx->pc = 0x8015AE74u;
            return;
    }

label_80161A80:
    ctx->pc = 0x80161A80u;
    ctx->downcount -= 16;
    // 80161A80: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161A84:
    ctx->pc = 0x80161A84u;
    // 80161A84: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161A88:
    ctx->pc = 0x80161A88u;
    // 80161A88: lmw     r25, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80161A8C:
    ctx->pc = 0x80161A8Cu;
    // 80161A8C: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_80161A90:
    ctx->pc = 0x80161A90u;
    // 80161A90: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161A94:
    ctx->pc = 0x80161A94u;
    ctx->downcount -= 25;
    // 80161A94: stwu     r1, -304(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-304);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80161A98:
    ctx->pc = 0x80161A98u;
    // 80161A98: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161A9C:
    ctx->pc = 0x80161A9Cu;
    // 80161A9C: stmw     r26, 280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80161AA0:
    ctx->pc = 0x80161AA0u;
    // 80161AA0: stw     r0, 308(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(308);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161AA4:
    ctx->pc = 0x80161AA4u;
    // 80161AA4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161AA8:
    ctx->pc = 0x80161AA8u;
    // 80161AA8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80161AAC:
    ctx->pc = 0x80161AACu;
    // 80161AAC: addi    r3, r31, 704
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(704);

label_80161AB0:
    ctx->pc = 0x80161AB0u;
    // 80161AB0: lwz     r11, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80161AB4:
    ctx->pc = 0x80161AB4u;
    // 80161AB4: lwz     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80161AB8:
    ctx->pc = 0x80161AB8u;
    // 80161AB8: addi    r6, r1, 272
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(272);

label_80161ABC:
    ctx->pc = 0x80161ABCu;
    // 80161ABC: stw     r9, 272(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(272);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80161AC0:
    ctx->pc = 0x80161AC0u;
    // 80161AC0: subf   r0, r11, r4
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80161AC4:
    ctx->pc = 0x80161AC4u;
    // 80161AC4: srawi r0, r0, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[0] = value;
        } else if (sh > 31) {
            ctx->gpr[0] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[0] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80161AC8:
    ctx->pc = 0x80161AC8u;
    // 80161AC8: cmplwi  r0, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161ACC:
    ctx->pc = 0x80161ACCu;
    // 80161ACC: bc    4, 1, 0x80161ADC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80161ADC;
        }
    }

label_80161AD0:
    ctx->pc = 0x80161AD0u;
    ctx->downcount -= 3;
    // 80161AD0: addi    r0, r11, 12
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(12);

label_80161AD4:
    ctx->pc = 0x80161AD4u;
    // 80161AD4: stw     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161AD8:
    ctx->pc = 0x80161AD8u;
    // 80161AD8: b       0x80161AE4
    {
            goto label_80161AE4;
    }

label_80161ADC:
    ctx->pc = 0x80161ADCu;
    ctx->downcount -= 2;
    // 80161ADC: subfic  r5, r0, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80161AE0:
    ctx->pc = 0x80161AE0u;
    // 80161AE0: bl      0x8012952C
    {
            ctx->lr = 0x80161AE4u;
            ctx->pc = 0x8012952Cu;
            return;
    }

label_80161AE4:
    ctx->pc = 0x80161AE4u;
    ctx->downcount -= 1;
    // 80161AE4: bl      0x8019D2B0
    {
            ctx->lr = 0x80161AE8u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_80161AE8:
    ctx->pc = 0x80161AE8u;
    ctx->downcount -= 17;
    // 80161AE8: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80161AEC:
    ctx->pc = 0x80161AECu;
    // 80161AEC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80161AF0:
    ctx->pc = 0x80161AF0u;
    // 80161AF0: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80161AF4:
    ctx->pc = 0x80161AF4u;
    // 80161AF4: addi    r28, r1, 8
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(8);

label_80161AF8:
    ctx->pc = 0x80161AF8u;
    // 80161AF8: lwz     r0, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161AFC:
    ctx->pc = 0x80161AFCu;
    // 80161AFC: addi    r27, r30, 3020
    ctx->gpr[27] = ctx->gpr[30] + (u32)(s32)(3020);

label_80161B00:
    ctx->pc = 0x80161B00u;
    // 80161B00: stb     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80161B04:
    ctx->pc = 0x80161B04u;
    // 80161B04: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161B08:
    ctx->pc = 0x80161B08u;
    // 80161B08: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80161B0C:
    ctx->pc = 0x80161B0Cu;
    // 80161B0C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161B10:
    ctx->pc = 0x80161B10u;
    // 80161B10: addi    r4, r4, -26012
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-26012);

label_80161B14:
    ctx->pc = 0x80161B14u;
    // 80161B14: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80161B18:
    ctx->pc = 0x80161B18u;
    // 80161B18: lwzx    r5, r27, r0
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80161B1C:
    ctx->pc = 0x80161B1Cu;
    // 80161B1C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161B20:
    ctx->pc = 0x80161B20u;
    // 80161B20: bl      0x8009258C
    {
            ctx->lr = 0x80161B24u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80161B24:
    ctx->pc = 0x80161B24u;
    ctx->downcount -= 5;
    // 80161B24: lwz     r29, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80161B28:
    ctx->pc = 0x80161B28u;
    // 80161B28: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80161B2C:
    ctx->pc = 0x80161B2Cu;
    // 80161B2C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80161B30:
    ctx->pc = 0x80161B30u;
    // 80161B30: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80161B34:
    ctx->pc = 0x80161B34u;
    // 80161B34: bl      0x8019A70C
    {
            ctx->lr = 0x80161B38u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80161B38:
    ctx->pc = 0x80161B38u;
    ctx->downcount -= 11;
    // 80161B38: stw     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80161B3C:
    ctx->pc = 0x80161B3Cu;
    // 80161B3C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161B40:
    ctx->pc = 0x80161B40u;
    // 80161B40: addi    r4, r4, -25980
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25980);

label_80161B44:
    ctx->pc = 0x80161B44u;
    // 80161B44: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80161B48:
    ctx->pc = 0x80161B48u;
    // 80161B48: lwz     r0, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161B4C:
    ctx->pc = 0x80161B4Cu;
    // 80161B4C: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80161B50:
    ctx->pc = 0x80161B50u;
    // 80161B50: lwzx    r5, r27, r0
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80161B54:
    ctx->pc = 0x80161B54u;
    // 80161B54: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161B58:
    ctx->pc = 0x80161B58u;
    // 80161B58: bl      0x8009258C
    {
            ctx->lr = 0x80161B5Cu;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80161B5C:
    ctx->pc = 0x80161B5Cu;
    ctx->downcount -= 5;
    // 80161B5C: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80161B60:
    ctx->pc = 0x80161B60u;
    // 80161B60: lwz     r29, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80161B64:
    ctx->pc = 0x80161B64u;
    // 80161B64: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80161B68:
    ctx->pc = 0x80161B68u;
    // 80161B68: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80161B6C:
    ctx->pc = 0x80161B6Cu;
    // 80161B6C: bl      0x8019A70C
    {
            ctx->lr = 0x80161B70u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80161B70:
    ctx->pc = 0x80161B70u;
    ctx->downcount -= 11;
    // 80161B70: stw     r3, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80161B74:
    ctx->pc = 0x80161B74u;
    // 80161B74: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161B78:
    ctx->pc = 0x80161B78u;
    // 80161B78: addi    r4, r4, -25952
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25952);

label_80161B7C:
    ctx->pc = 0x80161B7Cu;
    // 80161B7C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80161B80:
    ctx->pc = 0x80161B80u;
    // 80161B80: lwz     r0, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161B84:
    ctx->pc = 0x80161B84u;
    // 80161B84: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80161B88:
    ctx->pc = 0x80161B88u;
    // 80161B88: lwzx    r5, r27, r0
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80161B8C:
    ctx->pc = 0x80161B8Cu;
    // 80161B8C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161B90:
    ctx->pc = 0x80161B90u;
    // 80161B90: bl      0x8009258C
    {
            ctx->lr = 0x80161B94u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80161B94:
    ctx->pc = 0x80161B94u;
    ctx->downcount -= 5;
    // 80161B94: lwz     r30, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80161B98:
    ctx->pc = 0x80161B98u;
    // 80161B98: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80161B9C:
    ctx->pc = 0x80161B9Cu;
    // 80161B9C: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80161BA0:
    ctx->pc = 0x80161BA0u;
    // 80161BA0: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80161BA4:
    ctx->pc = 0x80161BA4u;
    // 80161BA4: bl      0x8019A70C
    {
            ctx->lr = 0x80161BA8u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80161BA8:
    ctx->pc = 0x80161BA8u;
    ctx->downcount -= 19;
    // 80161BA8: stw     r3, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80161BAC:
    ctx->pc = 0x80161BACu;
    // 80161BAC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80161BB0:
    ctx->pc = 0x80161BB0u;
    // 80161BB0: stw     r0, 312(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(312);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161BB4:
    ctx->pc = 0x80161BB4u;
    // 80161BB4: lwz     r0, 308(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(308);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161BB8:
    ctx->pc = 0x80161BB8u;
    // 80161BB8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161BBC:
    ctx->pc = 0x80161BBCu;
    // 80161BBC: lmw     r26, 280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80161BC0:
    ctx->pc = 0x80161BC0u;
    // 80161BC0: addi    r1, r1, 304
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(304);

label_80161BC4:
    ctx->pc = 0x80161BC4u;
    // 80161BC4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161BC8:
    ctx->pc = 0x80161BC8u;
    ctx->downcount -= 17;
    // 80161BC8: stwu     r1, -608(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-608);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80161BCC:
    ctx->pc = 0x80161BCCu;
    // 80161BCC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161BD0:
    ctx->pc = 0x80161BD0u;
    // 80161BD0: stfd     f31, 600(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161BD0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(600);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80161BD4:
    ctx->pc = 0x80161BD4u;
    // 80161BD4: stmw     r24, 568(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(568);
        for (u32 r = 24; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80161BD8:
    ctx->pc = 0x80161BD8u;
    // 80161BD8: stw     r0, 612(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(612);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161BDC:
    ctx->pc = 0x80161BDCu;
    // 80161BDC: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161BE0:
    ctx->pc = 0x80161BE0u;
    // 80161BE0: bl      0x8015E4A4
    {
            ctx->lr = 0x80161BE4u;
            ctx->pc = 0x8015E4A4u;
            return;
    }

label_80161BE4:
    ctx->pc = 0x80161BE4u;
    ctx->downcount -= 11;
    // 80161BE4: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_80161BE8:
    ctx->pc = 0x80161BE8u;
    // 80161BE8: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80161BEC:
    ctx->pc = 0x80161BECu;
    // 80161BEC: addi    r27, r1, 16
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(16);

label_80161BF0:
    ctx->pc = 0x80161BF0u;
    // 80161BF0: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80161BF4:
    ctx->pc = 0x80161BF4u;
    // 80161BF4: addi    r26, r1, 32
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(32);

label_80161BF8:
    ctx->pc = 0x80161BF8u;
    // 80161BF8: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161BFC:
    ctx->pc = 0x80161BFCu;
    // 80161BFC: addi    r24, r1, 296
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(296);

label_80161C00:
    ctx->pc = 0x80161C00u;
    // 80161C00: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80161C04:
    ctx->pc = 0x80161C04u;
    // 80161C04: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80161C08:
    ctx->pc = 0x80161C08u;
    // 80161C08: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161C0C:
    ctx->pc = 0x80161C0Cu;
    // 80161C0C: bl      0x801CF88C
    {
            ctx->lr = 0x80161C10u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80161C10:
    ctx->pc = 0x80161C10u;
    ctx->downcount -= 2;
    // 80161C10: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80161C14:
    ctx->pc = 0x80161C14u;
    // 80161C14: bl      0x80281C60
    {
            ctx->lr = 0x80161C18u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80161C18:
    ctx->pc = 0x80161C18u;
    ctx->downcount -= 6;
    // 80161C18: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161C1C:
    ctx->pc = 0x80161C1Cu;
    // 80161C1C: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80161C20:
    ctx->pc = 0x80161C20u;
    // 80161C20: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80161C24:
    ctx->pc = 0x80161C24u;
    // 80161C24: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80161C28:
    ctx->pc = 0x80161C28u;
    // 80161C28: addi    r4, r4, -25920
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25920);

label_80161C2C:
    ctx->pc = 0x80161C2Cu;
    // 80161C2C: bl      0x801427A0
    {
            ctx->lr = 0x80161C30u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80161C30:
    ctx->pc = 0x80161C30u;
    ctx->downcount -= 8;
    // 80161C30: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80161C34:
    ctx->pc = 0x80161C34u;
    // 80161C34: stw     r3, 684(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80161C38:
    ctx->pc = 0x80161C38u;
    // 80161C38: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80161C3C:
    ctx->pc = 0x80161C3Cu;
    // 80161C3C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80161C40:
    ctx->pc = 0x80161C40u;
    // 80161C40: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161C44:
    ctx->pc = 0x80161C44u;
    // 80161C44: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80161C48:
    ctx->pc = 0x80161C48u;
    // 80161C48: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161C4C:
    ctx->pc = 0x80161C4Cu;
    // 80161C4C: bl      0x801CF88C
    {
            ctx->lr = 0x80161C50u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80161C50:
    ctx->pc = 0x80161C50u;
    ctx->downcount -= 2;
    // 80161C50: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80161C54:
    ctx->pc = 0x80161C54u;
    // 80161C54: bl      0x80281C60
    {
            ctx->lr = 0x80161C58u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80161C58:
    ctx->pc = 0x80161C58u;
    ctx->downcount -= 6;
    // 80161C58: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161C5C:
    ctx->pc = 0x80161C5Cu;
    // 80161C5C: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80161C60:
    ctx->pc = 0x80161C60u;
    // 80161C60: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80161C64:
    ctx->pc = 0x80161C64u;
    // 80161C64: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80161C68:
    ctx->pc = 0x80161C68u;
    // 80161C68: addi    r4, r4, -25892
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25892);

label_80161C6C:
    ctx->pc = 0x80161C6Cu;
    // 80161C6C: bl      0x801427A0
    {
            ctx->lr = 0x80161C70u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80161C70:
    ctx->pc = 0x80161C70u;
    ctx->downcount -= 8;
    // 80161C70: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80161C74:
    ctx->pc = 0x80161C74u;
    // 80161C74: stw     r3, 688(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80161C78:
    ctx->pc = 0x80161C78u;
    // 80161C78: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80161C7C:
    ctx->pc = 0x80161C7Cu;
    // 80161C7C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80161C80:
    ctx->pc = 0x80161C80u;
    // 80161C80: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161C84:
    ctx->pc = 0x80161C84u;
    // 80161C84: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80161C88:
    ctx->pc = 0x80161C88u;
    // 80161C88: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161C8C:
    ctx->pc = 0x80161C8Cu;
    // 80161C8C: bl      0x801CF88C
    {
            ctx->lr = 0x80161C90u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80161C90:
    ctx->pc = 0x80161C90u;
    ctx->downcount -= 2;
    // 80161C90: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80161C94:
    ctx->pc = 0x80161C94u;
    // 80161C94: bl      0x80281C60
    {
            ctx->lr = 0x80161C98u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80161C98:
    ctx->pc = 0x80161C98u;
    ctx->downcount -= 6;
    // 80161C98: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161C9C:
    ctx->pc = 0x80161C9Cu;
    // 80161C9C: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80161CA0:
    ctx->pc = 0x80161CA0u;
    // 80161CA0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80161CA4:
    ctx->pc = 0x80161CA4u;
    // 80161CA4: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80161CA8:
    ctx->pc = 0x80161CA8u;
    // 80161CA8: addi    r4, r4, -25864
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25864);

label_80161CAC:
    ctx->pc = 0x80161CACu;
    // 80161CAC: bl      0x801427A0
    {
            ctx->lr = 0x80161CB0u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80161CB0:
    ctx->pc = 0x80161CB0u;
    ctx->downcount -= 15;
    // 80161CB0: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80161CB4:
    ctx->pc = 0x80161CB4u;
    // 80161CB4: stw     r3, 692(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80161CB8:
    ctx->pc = 0x80161CB8u;
    // 80161CB8: lfs     f31, -25776(r9)
    if (!ppc_fp_available_inline(ctx, 0x80161CB8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-25776);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80161CBC:
    ctx->pc = 0x80161CBCu;
    // 80161CBC: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80161CC0:
    ctx->pc = 0x80161CC0u;
    // 80161CC0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80161CC4:
    ctx->pc = 0x80161CC4u;
    // 80161CC4: stfs     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161CC4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80161CC8:
    ctx->pc = 0x80161CC8u;
    // 80161CC8: stfs     f31, 4(r27)
    if (!ppc_fp_available_inline(ctx, 0x80161CC8u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80161CCC:
    ctx->pc = 0x80161CCCu;
    // 80161CCC: stfs     f31, 8(r27)
    if (!ppc_fp_available_inline(ctx, 0x80161CCCu)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80161CD0:
    ctx->pc = 0x80161CD0u;
    // 80161CD0: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161CD4:
    ctx->pc = 0x80161CD4u;
    // 80161CD4: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80161CD8:
    ctx->pc = 0x80161CD8u;
    // 80161CD8: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161CDC:
    ctx->pc = 0x80161CDCu;
    // 80161CDC: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80161CE0:
    ctx->pc = 0x80161CE0u;
    // 80161CE0: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80161CE4:
    ctx->pc = 0x80161CE4u;
    // 80161CE4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80161CE8u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161CE8:
    ctx->pc = 0x80161CE8u;
    ctx->downcount -= 4;
    // 80161CE8: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161CEC:
    ctx->pc = 0x80161CECu;
    // 80161CEC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80161CF0:
    ctx->pc = 0x80161CF0u;
    // 80161CF0: addi    r4, r4, -25832
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25832);

label_80161CF4:
    ctx->pc = 0x80161CF4u;
    // 80161CF4: bl      0x801CFE08
    {
            ctx->lr = 0x80161CF8u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80161CF8:
    ctx->pc = 0x80161CF8u;
    ctx->downcount -= 10;
    // 80161CF8: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80161CFC:
    ctx->pc = 0x80161CFCu;
    // 80161CFC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80161D00:
    ctx->pc = 0x80161D00u;
    // 80161D00: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80161D04:
    ctx->pc = 0x80161D04u;
    // 80161D04: lwz     r0, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161D08:
    ctx->pc = 0x80161D08u;
    // 80161D08: addi    r28, r30, 3020
    ctx->gpr[28] = ctx->gpr[30] + (u32)(s32)(3020);

label_80161D0C:
    ctx->pc = 0x80161D0Cu;
    // 80161D0C: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80161D10:
    ctx->pc = 0x80161D10u;
    // 80161D10: lwzx    r4, r28, r0
    {
        u32 ea = ctx->gpr[28] + ctx->gpr[0];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80161D14:
    ctx->pc = 0x80161D14u;
    // 80161D14: bl      0x801CFC48
    {
            ctx->lr = 0x80161D18u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80161D18:
    ctx->pc = 0x80161D18u;
    ctx->downcount -= 5;
    // 80161D18: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161D1C:
    ctx->pc = 0x80161D1Cu;
    // 80161D1C: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80161D1Cu)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80161D20:
    ctx->pc = 0x80161D20u;
    // 80161D20: addi    r4, r4, -25820
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25820);

label_80161D24:
    ctx->pc = 0x80161D24u;
    // 80161D24: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80161D28:
    ctx->pc = 0x80161D28u;
    // 80161D28: bl      0x801D009C
    {
            ctx->lr = 0x80161D2Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80161D2C:
    ctx->pc = 0x80161D2Cu;
    ctx->downcount -= 3;
    // 80161D2C: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x80161D2Cu)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_80161D30:
    ctx->pc = 0x80161D30u;
    // 80161D30: li      r3, 384
    ctx->gpr[3] = (u32)(s32)(384);

label_80161D34:
    ctx->pc = 0x80161D34u;
    // 80161D34: bl      0x80281C60
    {
            ctx->lr = 0x80161D38u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80161D38:
    ctx->pc = 0x80161D38u;
    ctx->downcount -= 3;
    // 80161D38: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80161D38u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80161D3C:
    ctx->pc = 0x80161D3Cu;
    // 80161D3C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80161D40:
    ctx->pc = 0x80161D40u;
    // 80161D40: bl      0x80153CB4
    {
            ctx->lr = 0x80161D44u;
            ctx->pc = 0x80153CB4u;
            return;
    }

label_80161D44:
    ctx->pc = 0x80161D44u;
    ctx->downcount -= 12;
    // 80161D44: stw     r3, 696(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80161D48:
    ctx->pc = 0x80161D48u;
    // 80161D48: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161D4C:
    ctx->pc = 0x80161D4Cu;
    // 80161D4C: stb     r25, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write8(ctx, ea, (u8)ctx->gpr[25]);
    }

label_80161D50:
    ctx->pc = 0x80161D50u;
    // 80161D50: addi    r4, r4, -25812
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25812);

label_80161D54:
    ctx->pc = 0x80161D54u;
    // 80161D54: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80161D58:
    ctx->pc = 0x80161D58u;
    // 80161D58: lwz     r0, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161D5C:
    ctx->pc = 0x80161D5Cu;
    // 80161D5C: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80161D60:
    ctx->pc = 0x80161D60u;
    // 80161D60: lwzx    r5, r28, r0
    {
        u32 ea = ctx->gpr[28] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80161D64:
    ctx->pc = 0x80161D64u;
    // 80161D64: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161D68:
    ctx->pc = 0x80161D68u;
    // 80161D68: bl      0x8009258C
    {
            ctx->lr = 0x80161D6Cu;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80161D6C:
    ctx->pc = 0x80161D6Cu;
    ctx->downcount -= 11;
    // 80161D6C: lwz     r11, 696(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(696);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80161D70:
    ctx->pc = 0x80161D70u;
    // 80161D70: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80161D74:
    ctx->pc = 0x80161D74u;
    // 80161D74: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80161D78:
    ctx->pc = 0x80161D78u;
    // 80161D78: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_80161D7C:
    ctx->pc = 0x80161D7Cu;
    // 80161D7C: lwz     r9, 108(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161D80:
    ctx->pc = 0x80161D80u;
    // 80161D80: lwz     r0, 180(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(180);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161D84:
    ctx->pc = 0x80161D84u;
    // 80161D84: lha     r3, 176(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(176);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80161D88:
    ctx->pc = 0x80161D88u;
    // 80161D88: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161D8C:
    ctx->pc = 0x80161D8Cu;
    // 80161D8C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80161D90:
    ctx->pc = 0x80161D90u;
    // 80161D90: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80161D94u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161D94:
    ctx->pc = 0x80161D94u;
    ctx->downcount -= 11;
    // 80161D94: lwz     r0, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161D98:
    ctx->pc = 0x80161D98u;
    // 80161D98: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161D9C:
    ctx->pc = 0x80161D9Cu;
    // 80161D9C: stb     r25, 296(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(296);
        mem_write8(ctx, ea, (u8)ctx->gpr[25]);
    }

label_80161DA0:
    ctx->pc = 0x80161DA0u;
    // 80161DA0: addi    r4, r4, -25796
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25796);

label_80161DA4:
    ctx->pc = 0x80161DA4u;
    // 80161DA4: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80161DA8:
    ctx->pc = 0x80161DA8u;
    // 80161DA8: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80161DAC:
    ctx->pc = 0x80161DACu;
    // 80161DAC: lwzx    r5, r28, r0
    {
        u32 ea = ctx->gpr[28] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80161DB0:
    ctx->pc = 0x80161DB0u;
    // 80161DB0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161DB4:
    ctx->pc = 0x80161DB4u;
    // 80161DB4: bl      0x8009258C
    {
            ctx->lr = 0x80161DB8u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80161DB8:
    ctx->pc = 0x80161DB8u;
    ctx->downcount -= 5;
    // 80161DB8: lwz     r3, 696(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80161DBC:
    ctx->pc = 0x80161DBCu;
    // 80161DBC: or   r4, r24, r24
    {
        ctx->gpr[4] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80161DC0:
    ctx->pc = 0x80161DC0u;
    // 80161DC0: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_80161DC4:
    ctx->pc = 0x80161DC4u;
    // 80161DC4: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80161DC8:
    ctx->pc = 0x80161DC8u;
    // 80161DC8: bl      0x802055E4
    {
            ctx->lr = 0x80161DCCu;
            ctx->pc = 0x802055E4u;
            return;
    }

label_80161DCC:
    ctx->pc = 0x80161DCCu;
    ctx->downcount -= 5;
    // 80161DCC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80161DD0:
    ctx->pc = 0x80161DD0u;
    // 80161DD0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80161DD4:
    ctx->pc = 0x80161DD4u;
    // 80161DD4: stw     r0, 700(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161DD8:
    ctx->pc = 0x80161DD8u;
    // 80161DD8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80161DDC:
    ctx->pc = 0x80161DDCu;
    // 80161DDC: bl      0x801CFEAC
    {
            ctx->lr = 0x80161DE0u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80161DE0:
    ctx->pc = 0x80161DE0u;
    ctx->downcount -= 17;
    // 80161DE0: lwz     r0, 612(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(612);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161DE4:
    ctx->pc = 0x80161DE4u;
    // 80161DE4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161DE8:
    ctx->pc = 0x80161DE8u;
    // 80161DE8: lmw     r24, 568(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(568);
        for (u32 r = 24; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80161DEC:
    ctx->pc = 0x80161DECu;
    // 80161DEC: lfd     f31, 600(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161DECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(600);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80161DF0:
    ctx->pc = 0x80161DF0u;
    // 80161DF0: addi    r1, r1, 608
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(608);

label_80161DF4:
    ctx->pc = 0x80161DF4u;
    // 80161DF4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161DF8:
    ctx->pc = 0x80161DF8u;
    ctx->downcount -= 19;
    // 80161DF8: stwu     r1, -368(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-368);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80161DFC:
    ctx->pc = 0x80161DFCu;
    // 80161DFC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80161E00:
    ctx->pc = 0x80161E00u;
    // 80161E00: stfd     f31, 360(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161E00u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(360);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80161E04:
    ctx->pc = 0x80161E04u;
    // 80161E04: stmw     r25, 332(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(332);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80161E08:
    ctx->pc = 0x80161E08u;
    // 80161E08: stw     r0, 372(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(372);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161E0C:
    ctx->pc = 0x80161E0Cu;
    // 80161E0C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80161E10:
    ctx->pc = 0x80161E10u;
    // 80161E10: lwz     r25, 700(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(700);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80161E14:
    ctx->pc = 0x80161E14u;
    // 80161E14: cmpwi   r25, 1
    {
        s32 val_a = (s32)(ctx->gpr[25]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161E18:
    ctx->pc = 0x80161E18u;
    // 80161E18: bc    12, 2, 0x80161F34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161F34;
        }
    }

label_80161E1C:
    ctx->pc = 0x80161E1Cu;
    ctx->downcount -= 1;
    // 80161E1C: bc    12, 1, 0x80161E2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161E2C;
        }
    }

label_80161E20:
    ctx->pc = 0x80161E20u;
    ctx->downcount -= 2;
    // 80161E20: cmpwi   r25, 0
    {
        s32 val_a = (s32)(ctx->gpr[25]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161E24:
    ctx->pc = 0x80161E24u;
    // 80161E24: bc    12, 2, 0x80161E40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161E40;
        }
    }

label_80161E28:
    ctx->pc = 0x80161E28u;
    ctx->downcount -= 1;
    // 80161E28: b       0x8016205C
    {
            goto label_8016205C;
    }

label_80161E2C:
    ctx->pc = 0x80161E2Cu;
    ctx->downcount -= 2;
    // 80161E2C: cmpwi   r25, 2
    {
        s32 val_a = (s32)(ctx->gpr[25]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161E30:
    ctx->pc = 0x80161E30u;
    // 80161E30: bc    12, 2, 0x80161F7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80161F7C;
        }
    }

label_80161E34:
    ctx->pc = 0x80161E34u;
    ctx->downcount -= 2;
    // 80161E34: cmpwi   r25, 3
    {
        s32 val_a = (s32)(ctx->gpr[25]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161E38:
    ctx->pc = 0x80161E38u;
    // 80161E38: bc    12, 2, 0x80162044
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162044;
        }
    }

label_80161E3C:
    ctx->pc = 0x80161E3Cu;
    ctx->downcount -= 1;
    // 80161E3C: b       0x8016205C
    {
            goto label_8016205C;
    }

label_80161E40:
    ctx->pc = 0x80161E40u;
    ctx->downcount -= 3;
    // 80161E40: lwz     r0, 720(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(720);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161E44:
    ctx->pc = 0x80161E44u;
    // 80161E44: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161E48:
    ctx->pc = 0x80161E48u;
    // 80161E48: bc    12, 2, 0x8016205C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016205C;
        }
    }

label_80161E4C:
    ctx->pc = 0x80161E4Cu;
    ctx->downcount -= 17;
    // 80161E4C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80161E50:
    ctx->pc = 0x80161E50u;
    // 80161E50: lwz     r11, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80161E54:
    ctx->pc = 0x80161E54u;
    // 80161E54: lfs     f31, -25740(r9)
    if (!ppc_fp_available_inline(ctx, 0x80161E54u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-25740);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80161E58:
    ctx->pc = 0x80161E58u;
    // 80161E58: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_80161E5C:
    ctx->pc = 0x80161E5Cu;
    // 80161E5C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80161E60:
    ctx->pc = 0x80161E60u;
    // 80161E60: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80161E64:
    ctx->pc = 0x80161E64u;
    // 80161E64: stfs     f31, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161E64u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80161E68:
    ctx->pc = 0x80161E68u;
    // 80161E68: addi    r26, r1, 24
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(24);

label_80161E6C:
    ctx->pc = 0x80161E6Cu;
    // 80161E6C: stfs     f31, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x80161E6Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80161E70:
    ctx->pc = 0x80161E70u;
    // 80161E70: stfs     f31, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x80161E70u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80161E74:
    ctx->pc = 0x80161E74u;
    // 80161E74: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161E78:
    ctx->pc = 0x80161E78u;
    // 80161E78: lwz     r0, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161E7C:
    ctx->pc = 0x80161E7Cu;
    // 80161E7C: lha     r3, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80161E80:
    ctx->pc = 0x80161E80u;
    // 80161E80: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161E84:
    ctx->pc = 0x80161E84u;
    // 80161E84: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80161E88:
    ctx->pc = 0x80161E88u;
    // 80161E88: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80161E8Cu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161E8C:
    ctx->pc = 0x80161E8Cu;
    ctx->downcount -= 4;
    // 80161E8C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161E90:
    ctx->pc = 0x80161E90u;
    // 80161E90: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80161E94:
    ctx->pc = 0x80161E94u;
    // 80161E94: addi    r4, r4, -25772
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25772);

label_80161E98:
    ctx->pc = 0x80161E98u;
    // 80161E98: bl      0x801CFE08
    {
            ctx->lr = 0x80161E9Cu;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80161E9C:
    ctx->pc = 0x80161E9Cu;
    ctx->downcount -= 12;
    // 80161E9C: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80161EA0:
    ctx->pc = 0x80161EA0u;
    // 80161EA0: lwz     r28, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80161EA4:
    ctx->pc = 0x80161EA4u;
    // 80161EA4: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80161EA8:
    ctx->pc = 0x80161EA8u;
    // 80161EA8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80161EAC:
    ctx->pc = 0x80161EACu;
    // 80161EAC: lwz     r0, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161EB0:
    ctx->pc = 0x80161EB0u;
    // 80161EB0: addi    r27, r30, 3020
    ctx->gpr[27] = ctx->gpr[30] + (u32)(s32)(3020);

label_80161EB4:
    ctx->pc = 0x80161EB4u;
    // 80161EB4: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80161EB4u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80161EB8:
    ctx->pc = 0x80161EB8u;
    // 80161EB8: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80161EBC:
    ctx->pc = 0x80161EBCu;
    // 80161EBC: lwzx    r4, r27, r0
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[0];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80161EC0:
    ctx->pc = 0x80161EC0u;
    // 80161EC0: bl      0x801D009C
    {
            ctx->lr = 0x80161EC4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80161EC4:
    ctx->pc = 0x80161EC4u;
    ctx->downcount -= 5;
    // 80161EC4: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x80161EC4u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80161EC8:
    ctx->pc = 0x80161EC8u;
    // 80161EC8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80161ECC:
    ctx->pc = 0x80161ECCu;
    // 80161ECC: stfd     f0, 320(r1)
    if (!ppc_fp_available_inline(ctx, 0x80161ECCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(320);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80161ED0:
    ctx->pc = 0x80161ED0u;
    // 80161ED0: lwz     r4, 324(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(324);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80161ED4:
    ctx->pc = 0x80161ED4u;
    // 80161ED4: bl      0x80143B20
    {
            ctx->lr = 0x80161ED8u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80161ED8:
    ctx->pc = 0x80161ED8u;
    ctx->downcount -= 5;
    // 80161ED8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80161EDC:
    ctx->pc = 0x80161EDCu;
    // 80161EDC: lwz     r3, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80161EE0:
    ctx->pc = 0x80161EE0u;
    // 80161EE0: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80161EE4:
    ctx->pc = 0x80161EE4u;
    // 80161EE4: stw     r0, 700(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161EE8:
    ctx->pc = 0x80161EE8u;
    // 80161EE8: bl      0x802069DC
    {
            ctx->lr = 0x80161EECu;
            ctx->pc = 0x802069DCu;
            return;
    }

label_80161EEC:
    ctx->pc = 0x80161EECu;
    ctx->downcount -= 11;
    // 80161EEC: lwz     r0, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161EF0:
    ctx->pc = 0x80161EF0u;
    // 80161EF0: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161EF4:
    ctx->pc = 0x80161EF4u;
    // 80161EF4: stb     r25, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write8(ctx, ea, (u8)ctx->gpr[25]);
    }

label_80161EF8:
    ctx->pc = 0x80161EF8u;
    // 80161EF8: addi    r4, r4, -25760
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25760);

label_80161EFC:
    ctx->pc = 0x80161EFCu;
    // 80161EFC: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80161F00:
    ctx->pc = 0x80161F00u;
    // 80161F00: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80161F04:
    ctx->pc = 0x80161F04u;
    // 80161F04: lwzx    r5, r27, r0
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80161F08:
    ctx->pc = 0x80161F08u;
    // 80161F08: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161F0C:
    ctx->pc = 0x80161F0Cu;
    // 80161F0C: bl      0x8009258C
    {
            ctx->lr = 0x80161F10u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80161F10:
    ctx->pc = 0x80161F10u;
    ctx->downcount -= 5;
    // 80161F10: lwz     r3, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80161F14:
    ctx->pc = 0x80161F14u;
    // 80161F14: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80161F18:
    ctx->pc = 0x80161F18u;
    // 80161F18: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_80161F1C:
    ctx->pc = 0x80161F1Cu;
    // 80161F1C: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80161F20:
    ctx->pc = 0x80161F20u;
    // 80161F20: bl      0x802055E4
    {
            ctx->lr = 0x80161F24u;
            ctx->pc = 0x802055E4u;
            return;
    }

label_80161F24:
    ctx->pc = 0x80161F24u;
    ctx->downcount -= 3;
    // 80161F24: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80161F28:
    ctx->pc = 0x80161F28u;
    // 80161F28: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80161F2C:
    ctx->pc = 0x80161F2Cu;
    // 80161F2C: bl      0x801CFEAC
    {
            ctx->lr = 0x80161F30u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80161F30:
    ctx->pc = 0x80161F30u;
    ctx->downcount -= 1;
    // 80161F30: b       0x8016205C
    {
            goto label_8016205C;
    }

label_80161F34:
    ctx->pc = 0x80161F34u;
    ctx->downcount -= 2;
    // 80161F34: lwz     r3, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80161F38:
    ctx->pc = 0x80161F38u;
    // 80161F38: bl      0x80143B78
    {
            ctx->lr = 0x80161F3Cu;
            ctx->pc = 0x80143B78u;
            return;
    }

label_80161F3C:
    ctx->pc = 0x80161F3Cu;
    ctx->downcount -= 2;
    // 80161F3C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80161F40:
    ctx->pc = 0x80161F40u;
    // 80161F40: bc    12, 2, 0x8016205C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016205C;
        }
    }

label_80161F44:
    ctx->pc = 0x80161F44u;
    ctx->downcount -= 9;
    // 80161F44: lwz     r11, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80161F48:
    ctx->pc = 0x80161F48u;
    // 80161F48: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80161F4C:
    ctx->pc = 0x80161F4Cu;
    // 80161F4C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161F50:
    ctx->pc = 0x80161F50u;
    // 80161F50: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161F54:
    ctx->pc = 0x80161F54u;
    // 80161F54: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80161F58:
    ctx->pc = 0x80161F58u;
    // 80161F58: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80161F5C:
    ctx->pc = 0x80161F5Cu;
    // 80161F5C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80161F60:
    ctx->pc = 0x80161F60u;
    // 80161F60: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80161F64u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80161F64:
    ctx->pc = 0x80161F64u;
    ctx->downcount -= 6;
    // 80161F64: lwz     r11, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80161F68:
    ctx->pc = 0x80161F68u;
    // 80161F68: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80161F6C:
    ctx->pc = 0x80161F6Cu;
    // 80161F6C: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_80161F70:
    ctx->pc = 0x80161F70u;
    // 80161F70: stw     r0, 364(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(364);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80161F74:
    ctx->pc = 0x80161F74u;
    // 80161F74: stw     r9, 700(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80161F78:
    ctx->pc = 0x80161F78u;
    // 80161F78: b       0x8016205C
    {
            goto label_8016205C;
    }

label_80161F7C:
    ctx->pc = 0x80161F7Cu;
    ctx->downcount -= 5;
    // 80161F7C: lwz     r3, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80161F80:
    ctx->pc = 0x80161F80u;
    // 80161F80: lwz     r9, 304(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(304);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80161F84:
    ctx->pc = 0x80161F84u;
    // 80161F84: addi    r3, r3, 288
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(288);

label_80161F88:
    ctx->pc = 0x80161F88u;
    // 80161F88: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80161F8C:
    ctx->pc = 0x80161F8Cu;
    // 80161F8C: bl      0x801D6988
    {
            ctx->lr = 0x80161F90u;
            ctx->pc = 0x801D6988u;
            return;
    }

label_80161F90:
    ctx->pc = 0x80161F90u;
    ctx->downcount -= 2;
    // 80161F90: andi.   r0, r3, 0x0010
    {
        ctx->gpr[0] = ctx->gpr[3] & 0x0010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80161F94:
    ctx->pc = 0x80161F94u;
    // 80161F94: bc    12, 2, 0x8016205C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016205C;
        }
    }

label_80161F98:
    ctx->pc = 0x80161F98u;
    ctx->downcount -= 4;
    // 80161F98: lwz     r3, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80161F9C:
    ctx->pc = 0x80161F9Cu;
    // 80161F9C: addi    r30, r1, 8
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(8);

label_80161FA0:
    ctx->pc = 0x80161FA0u;
    // 80161FA0: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80161FA4:
    ctx->pc = 0x80161FA4u;
    // 80161FA4: bl      0x802069DC
    {
            ctx->lr = 0x80161FA8u;
            ctx->pc = 0x802069DCu;
            return;
    }

label_80161FA8:
    ctx->pc = 0x80161FA8u;
    ctx->downcount -= 15;
    // 80161FA8: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80161FAC:
    ctx->pc = 0x80161FACu;
    // 80161FAC: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80161FB0:
    ctx->pc = 0x80161FB0u;
    // 80161FB0: addi    r9, r9, -25052
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-25052);

label_80161FB4:
    ctx->pc = 0x80161FB4u;
    // 80161FB4: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80161FB8:
    ctx->pc = 0x80161FB8u;
    // 80161FB8: lwz     r0, 3592(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80161FBC:
    ctx->pc = 0x80161FBCu;
    // 80161FBC: addi    r4, r4, -25796
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25796);

label_80161FC0:
    ctx->pc = 0x80161FC0u;
    // 80161FC0: stb     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[11]);
    }

label_80161FC4:
    ctx->pc = 0x80161FC4u;
    // 80161FC4: addi    r9, r9, 3020
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(3020);

label_80161FC8:
    ctx->pc = 0x80161FC8u;
    // 80161FC8: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80161FCC:
    ctx->pc = 0x80161FCCu;
    // 80161FCC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80161FD0:
    ctx->pc = 0x80161FD0u;
    // 80161FD0: lwzx    r5, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80161FD4:
    ctx->pc = 0x80161FD4u;
    // 80161FD4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80161FD8:
    ctx->pc = 0x80161FD8u;
    // 80161FD8: bl      0x8009258C
    {
            ctx->lr = 0x80161FDCu;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80161FDC:
    ctx->pc = 0x80161FDCu;
    ctx->downcount -= 5;
    // 80161FDC: lwz     r3, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80161FE0:
    ctx->pc = 0x80161FE0u;
    // 80161FE0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80161FE4:
    ctx->pc = 0x80161FE4u;
    // 80161FE4: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_80161FE8:
    ctx->pc = 0x80161FE8u;
    // 80161FE8: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80161FEC:
    ctx->pc = 0x80161FECu;
    // 80161FEC: bl      0x802055E4
    {
            ctx->lr = 0x80161FF0u;
            ctx->pc = 0x802055E4u;
            return;
    }

label_80161FF0:
    ctx->pc = 0x80161FF0u;
    ctx->downcount -= 19;
    // 80161FF0: lwz     r11, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80161FF4:
    ctx->pc = 0x80161FF4u;
    // 80161FF4: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80161FF8:
    ctx->pc = 0x80161FF8u;
    // 80161FF8: lfs     f0, -25740(r9)
    if (!ppc_fp_available_inline(ctx, 0x80161FF8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-25740);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80161FFC:
    ctx->pc = 0x80161FFCu;
    // 80161FFC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80162000:
    ctx->pc = 0x80162000u;
    // 80162000: stw     r0, 364(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(364);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162004:
    ctx->pc = 0x80162004u;
    // 80162004: addi    r9, r1, 288
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(288);

label_80162008:
    ctx->pc = 0x80162008u;
    // 80162008: stfs     f0, 288(r1)
    if (!ppc_fp_available_inline(ctx, 0x80162008u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(288);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8016200C:
    ctx->pc = 0x8016200Cu;
    // 8016200C: or   r5, r9, r9
    {
        ctx->gpr[5] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80162010:
    ctx->pc = 0x80162010u;
    // 80162010: stfs     f0, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x80162010u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80162014:
    ctx->pc = 0x80162014u;
    // 80162014: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80162018:
    ctx->pc = 0x80162018u;
    // 80162018: stfs     f0, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x80162018u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8016201C:
    ctx->pc = 0x8016201Cu;
    // 8016201C: lwz     r11, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80162020:
    ctx->pc = 0x80162020u;
    // 80162020: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162024:
    ctx->pc = 0x80162024u;
    // 80162024: lwz     r0, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162028:
    ctx->pc = 0x80162028u;
    // 80162028: lha     r3, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8016202C:
    ctx->pc = 0x8016202Cu;
    // 8016202C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162030:
    ctx->pc = 0x80162030u;
    // 80162030: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162034:
    ctx->pc = 0x80162034u;
    // 80162034: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80162038u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162038:
    ctx->pc = 0x80162038u;
    ctx->downcount -= 3;
    // 80162038: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_8016203C:
    ctx->pc = 0x8016203Cu;
    // 8016203C: stw     r0, 700(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162040:
    ctx->pc = 0x80162040u;
    // 80162040: b       0x8016205C
    {
            goto label_8016205C;
    }

label_80162044:
    ctx->pc = 0x80162044u;
    ctx->downcount -= 2;
    // 80162044: lwz     r3, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80162048:
    ctx->pc = 0x80162048u;
    // 80162048: bl      0x80143B78
    {
            ctx->lr = 0x8016204Cu;
            ctx->pc = 0x80143B78u;
            return;
    }

label_8016204C:
    ctx->pc = 0x8016204Cu;
    ctx->downcount -= 2;
    // 8016204C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162050:
    ctx->pc = 0x80162050u;
    // 80162050: bc    12, 2, 0x8016205C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016205C;
        }
    }

label_80162054:
    ctx->pc = 0x80162054u;
    ctx->downcount -= 2;
    // 80162054: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80162058:
    ctx->pc = 0x80162058u;
    // 80162058: stw     r0, 660(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(660);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016205C:
    ctx->pc = 0x8016205Cu;
    ctx->downcount -= 17;
    // 8016205C: lwz     r0, 372(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(372);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162060:
    ctx->pc = 0x80162060u;
    // 80162060: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162064:
    ctx->pc = 0x80162064u;
    // 80162064: lmw     r25, 332(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(332);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80162068:
    ctx->pc = 0x80162068u;
    // 80162068: lfd     f31, 360(r1)
    if (!ppc_fp_available_inline(ctx, 0x80162068u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(360);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8016206C:
    ctx->pc = 0x8016206Cu;
    // 8016206C: addi    r1, r1, 368
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(368);

label_80162070:
    ctx->pc = 0x80162070u;
    // 80162070: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162074:
    ctx->pc = 0x80162074u;
    ctx->downcount -= 16;
    // 80162074: stwu     r1, -168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-168);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162078:
    ctx->pc = 0x80162078u;
    // 80162078: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8016207C:
    ctx->pc = 0x8016207Cu;
    // 8016207C: stmw     r25, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80162080:
    ctx->pc = 0x80162080u;
    // 80162080: stw     r0, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162084:
    ctx->pc = 0x80162084u;
    // 80162084: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162088:
    ctx->pc = 0x80162088u;
    // 80162088: bl      0x8015BA2C
    {
            ctx->lr = 0x8016208Cu;
            ctx->pc = 0x8015BA2Cu;
            return;
    }

label_8016208C:
    ctx->pc = 0x8016208Cu;
    ctx->downcount -= 5;
    // 8016208C: lwz     r0, 36(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162090:
    ctx->pc = 0x80162090u;
    // 80162090: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162094:
    ctx->pc = 0x80162094u;
    // 80162094: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80162098:
    ctx->pc = 0x80162098u;
    // 80162098: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016209C:
    ctx->pc = 0x8016209Cu;
    // 8016209C: bc    12, 2, 0x801620B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801620B0;
        }
    }

label_801620A0:
    ctx->pc = 0x801620A0u;
    ctx->downcount -= 3;
    // 801620A0: lwz     r0, 40(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801620A4:
    ctx->pc = 0x801620A4u;
    // 801620A4: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801620A8:
    ctx->pc = 0x801620A8u;
    // 801620A8: bc    12, 2, 0x801620B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801620B0;
        }
    }

label_801620AC:
    ctx->pc = 0x801620ACu;
    ctx->downcount -= 1;
    // 801620AC: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_801620B0:
    ctx->pc = 0x801620B0u;
    ctx->downcount -= 2;
    // 801620B0: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801620B4:
    ctx->pc = 0x801620B4u;
    // 801620B4: bc    12, 2, 0x8016221C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016221C;
        }
    }

label_801620B8:
    ctx->pc = 0x801620B8u;
    ctx->downcount -= 5;
    // 801620B8: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_801620BC:
    ctx->pc = 0x801620BCu;
    // 801620BC: addi    r3, r9, -21296
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(-21296);

label_801620C0:
    ctx->pc = 0x801620C0u;
    // 801620C0: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801620C4:
    ctx->pc = 0x801620C4u;
    // 801620C4: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801620C8:
    ctx->pc = 0x801620C8u;
    // 801620C8: bc    12, 2, 0x801620DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801620DC;
        }
    }

label_801620CC:
    ctx->pc = 0x801620CCu;
    ctx->downcount -= 3;
    // 801620CC: lwz     r0, 724(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(724);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801620D0:
    ctx->pc = 0x801620D0u;
    // 801620D0: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801620D4:
    ctx->pc = 0x801620D4u;
    // 801620D4: bc    4, 2, 0x801620DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801620DC;
        }
    }

label_801620D8:
    ctx->pc = 0x801620D8u;
    ctx->downcount -= 1;
    // 801620D8: bl      0x8011065C
    {
            ctx->lr = 0x801620DCu;
            ctx->pc = 0x8011065Cu;
            return;
    }

label_801620DC:
    ctx->pc = 0x801620DCu;
    ctx->downcount -= 4;
    // 801620DC: lwz     r3, 692(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(692);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801620E0:
    ctx->pc = 0x801620E0u;
    // 801620E0: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801620E4:
    ctx->pc = 0x801620E4u;
    // 801620E4: addi    r3, r3, 32
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(32);

label_801620E8:
    ctx->pc = 0x801620E8u;
    // 801620E8: bl      0x801D3620
    {
            ctx->lr = 0x801620ECu;
            ctx->pc = 0x801D3620u;
            return;
    }

label_801620EC:
    ctx->pc = 0x801620ECu;
    ctx->downcount -= 2;
    // 801620EC: or.   r3, r3, r3
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801620F0:
    ctx->pc = 0x801620F0u;
    // 801620F0: bc    12, 2, 0x80162104
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162104;
        }
    }

label_801620F4:
    ctx->pc = 0x801620F4u;
    ctx->downcount -= 3;
    // 801620F4: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801620F8:
    ctx->pc = 0x801620F8u;
    // 801620F8: addi    r4, r4, -25736
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-25736);

label_801620FC:
    ctx->pc = 0x801620FCu;
    // 801620FC: bl      0x801E7DAC
    {
            ctx->lr = 0x80162100u;
            ctx->pc = 0x801E7DACu;
            return;
    }

label_80162100:
    ctx->pc = 0x80162100u;
    ctx->downcount -= 1;
    // 80162100: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162104:
    ctx->pc = 0x80162104u;
    ctx->downcount -= 2;
    // 80162104: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162108:
    ctx->pc = 0x80162108u;
    // 80162108: bc    12, 2, 0x8016221C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016221C;
        }
    }

label_8016210C:
    ctx->pc = 0x8016210Cu;
    ctx->downcount -= 4;
    // 8016210C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80162110:
    ctx->pc = 0x80162110u;
    // 80162110: addi    r29, r1, 72
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(72);

label_80162114:
    ctx->pc = 0x80162114u;
    // 80162114: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162118:
    ctx->pc = 0x80162118u;
    // 80162118: bl      0x802B47B4
    {
            ctx->lr = 0x8016211Cu;
            ctx->pc = 0x802B47B4u;
            return;
    }

label_8016211C:
    ctx->pc = 0x8016211Cu;
    ctx->downcount -= 9;
    // 8016211C: lwz     r9, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162120:
    ctx->pc = 0x80162120u;
    // 80162120: addi    r31, r1, 104
    ctx->gpr[31] = ctx->gpr[1] + (u32)(s32)(104);

label_80162124:
    ctx->pc = 0x80162124u;
    // 80162124: addi    r27, r1, 88
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(88);

label_80162128:
    ctx->pc = 0x80162128u;
    // 80162128: lha     r3, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8016212C:
    ctx->pc = 0x8016212Cu;
    // 8016212C: lwz     r0, 92(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(92);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162130:
    ctx->pc = 0x80162130u;
    // 80162130: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162134:
    ctx->pc = 0x80162134u;
    // 80162134: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162138:
    ctx->pc = 0x80162138u;
    // 80162138: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8016213Cu;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_8016213C:
    ctx->pc = 0x8016213Cu;
    ctx->downcount -= 2;
    // 8016213C: or.   r3, r3, r3
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80162140:
    ctx->pc = 0x80162140u;
    // 80162140: bc    12, 2, 0x801621B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801621B0;
        }
    }

label_80162144:
    ctx->pc = 0x80162144u;
    ctx->downcount -= 3;
    // 80162144: addi    r3, r3, 36
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(36);

label_80162148:
    ctx->pc = 0x80162148u;
    // 80162148: or   r9, r25, r25
    {
        ctx->gpr[9] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8016214C:
    ctx->pc = 0x8016214Cu;
    // 8016214C: li      r11, 48
    ctx->gpr[11] = (u32)(s32)(48);

label_80162150:
    loop_80162150(ctx);
    if (ctx->pc == 0x80162190u) goto label_80162190;
    return;
label_80162154:
    // 80162154: addic.  r11, r11, -24
    {
        u64 a = ctx->gpr[11];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[11] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80162158:
    ctx->pc = 0x80162158u;
    // 80162158: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016215C:
    ctx->pc = 0x8016215Cu;
    // 8016215C: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162160:
    ctx->pc = 0x80162160u;
    // 80162160: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162164:
    ctx->pc = 0x80162164u;
    // 80162164: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162168:
    ctx->pc = 0x80162168u;
    // 80162168: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016216C:
    ctx->pc = 0x8016216Cu;
    // 8016216C: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162170:
    ctx->pc = 0x80162170u;
    // 80162170: stw     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162174:
    ctx->pc = 0x80162174u;
    // 80162174: lwz     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162178:
    ctx->pc = 0x80162178u;
    // 80162178: stw     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016217C:
    ctx->pc = 0x8016217Cu;
    // 8016217C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162180:
    // 80162180: addi    r3, r3, 24
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(24);

label_80162184:
    ctx->pc = 0x80162184u;
    // 80162184: stw     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162188:
    // 80162188: addi    r9, r9, 24
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(24);

label_8016218C:
    // 8016218C: bc    4, 2, 0x80162150
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80162150u;
                return;
            }
            goto label_80162150;
        }
    }

label_80162190:
    ctx->pc = 0x80162190u;
    ctx->downcount -= 8;
    // 80162190: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162194:
    ctx->pc = 0x80162194u;
    // 80162194: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162198:
    ctx->pc = 0x80162198u;
    // 80162198: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016219C:
    ctx->pc = 0x8016219Cu;
    // 8016219C: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801621A0:
    ctx->pc = 0x801621A0u;
    // 801621A0: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801621A4:
    ctx->pc = 0x801621A4u;
    // 801621A4: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801621A8:
    ctx->pc = 0x801621A8u;
    // 801621A8: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801621AC:
    ctx->pc = 0x801621ACu;
    // 801621AC: stw     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801621B0:
    ctx->pc = 0x801621B0u;
    ctx->downcount -= 3;
    // 801621B0: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_801621B4:
    ctx->pc = 0x801621B4u;
    // 801621B4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801621B8:
    ctx->pc = 0x801621B8u;
    // 801621B8: bl      0x80283AF4
    {
            ctx->lr = 0x801621BCu;
            ctx->pc = 0x80283AF4u;
            return;
    }

label_801621BC:
    ctx->pc = 0x801621BCu;
    ctx->downcount -= 9;
    // 801621BC: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801621C0:
    ctx->pc = 0x801621C0u;
    // 801621C0: addi    r5, r1, 120
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(120);

label_801621C4:
    ctx->pc = 0x801621C4u;
    // 801621C4: lfs     f0, -25724(r9)
    if (!ppc_fp_available_inline(ctx, 0x801621C4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-25724);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801621C8:
    ctx->pc = 0x801621C8u;
    // 801621C8: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801621CC:
    ctx->pc = 0x801621CCu;
    // 801621CC: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801621D0:
    ctx->pc = 0x801621D0u;
    // 801621D0: stfs     f0, 104(r1)
    if (!ppc_fp_available_inline(ctx, 0x801621D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801621D4:
    ctx->pc = 0x801621D4u;
    // 801621D4: stfs     f0, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x801621D4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801621D8:
    ctx->pc = 0x801621D8u;
    // 801621D8: stfs     f0, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x801621D8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801621DC:
    ctx->pc = 0x801621DCu;
    // 801621DC: bl      0x8028BEDC
    {
            ctx->lr = 0x801621E0u;
            ctx->pc = 0x8028BEDCu;
            return;
    }

label_801621E0:
    ctx->pc = 0x801621E0u;
    ctx->downcount -= 10;
    // 801621E0: lfs     f12, 120(r1)
    if (!ppc_fp_available_inline(ctx, 0x801621E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801621E4:
    ctx->pc = 0x801621E4u;
    // 801621E4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801621E8:
    ctx->pc = 0x801621E8u;
    // 801621E8: lfs     f0, 124(r1)
    if (!ppc_fp_available_inline(ctx, 0x801621E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801621EC:
    ctx->pc = 0x801621ECu;
    // 801621EC: lfs     f13, 128(r1)
    if (!ppc_fp_available_inline(ctx, 0x801621ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801621F0:
    ctx->pc = 0x801621F0u;
    // 801621F0: lwz     r30, 696(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(696);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801621F4:
    ctx->pc = 0x801621F4u;
    // 801621F4: lwz     r3, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801621F8:
    ctx->pc = 0x801621F8u;
    // 801621F8: stfs     f12, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x801621F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_801621FC:
    ctx->pc = 0x801621FCu;
    // 801621FC: stfs     f0, 92(r1)
    if (!ppc_fp_available_inline(ctx, 0x801621FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80162200:
    ctx->pc = 0x80162200u;
    // 80162200: stfs     f13, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x80162200u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80162204:
    ctx->pc = 0x80162204u;
    // 80162204: bl      0x802198F4
    {
            ctx->lr = 0x80162208u;
            ctx->pc = 0x802198F4u;
            return;
    }

label_80162208:
    ctx->pc = 0x80162208u;
    ctx->downcount -= 5;
    // 80162208: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8016220C:
    ctx->pc = 0x8016220Cu;
    // 8016220C: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80162210:
    ctx->pc = 0x80162210u;
    // 80162210: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80162214:
    ctx->pc = 0x80162214u;
    // 80162214: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80162218:
    ctx->pc = 0x80162218u;
    // 80162218: bl      0x802066E0
    {
            ctx->lr = 0x8016221Cu;
            ctx->pc = 0x802066E0u;
            return;
    }

label_8016221C:
    ctx->pc = 0x8016221Cu;
    ctx->downcount -= 17;
    // 8016221C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80162220:
    ctx->pc = 0x80162220u;
    // 80162220: lwz     r0, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162224:
    ctx->pc = 0x80162224u;
    // 80162224: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162228:
    ctx->pc = 0x80162228u;
    // 80162228: lmw     r25, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8016222C:
    ctx->pc = 0x8016222Cu;
    // 8016222C: addi    r1, r1, 168
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(168);

label_80162230:
    ctx->pc = 0x80162230u;
    // 80162230: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162234:
    ctx->pc = 0x80162234u;
    ctx->downcount -= 16;
    // 80162234: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162238:
    ctx->pc = 0x80162238u;
    // 80162238: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8016223C:
    ctx->pc = 0x8016223Cu;
    // 8016223C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80162240:
    ctx->pc = 0x80162240u;
    // 80162240: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162244:
    ctx->pc = 0x80162244u;
    // 80162244: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162248:
    ctx->pc = 0x80162248u;
    // 80162248: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8016224C:
    ctx->pc = 0x8016224Cu;
    ctx->downcount -= 11;
    // 8016224C: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162250:
    ctx->pc = 0x80162250u;
    // 80162250: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162254:
    // 80162254: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80162258:
    ctx->pc = 0x80162258u;
    // 80162258: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8016225C:
    // 8016225C: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_80162260:
    // 80162260: cmplw   r10, r11
    {
        u32 val_a = (u32)(ctx->gpr[10]);
        u32 val_b = (u32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162264:
    // 80162264: bc    12, 0, 0x8016228C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016228C;
        }
    }

label_80162268:
    ctx->downcount -= 3;
    // 80162268: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8016226C:
    ctx->pc = 0x8016226Cu;
    // 8016226C: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162270:
    // 80162270: b       0x80162364
    {
            goto label_80162364;
    }

label_80162274:
    ctx->pc = 0x80162274u;
    ctx->downcount -= 6;
    // 80162274: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162278:
    // 80162278: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8016227C:
    ctx->pc = 0x8016227Cu;
    // 8016227C: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162280:
    ctx->pc = 0x80162280u;
    // 80162280: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80162284:
    ctx->pc = 0x80162284u;
    // 80162284: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80162288:
    // 80162288: b       0x8016224C
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8016224Cu;
                return;
            }
            goto label_8016224C;
    }

label_8016228C:
    ctx->downcount -= 2;
    // 8016228C: cmplw   r10, r30
    {
        u32 val_a = (u32)(ctx->gpr[10]);
        u32 val_b = (u32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162290:
    // 80162290: bc    12, 0, 0x801622B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801622B0;
        }
    }

label_80162294:
    ctx->downcount -= 50;
    // 80162294: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_80162298:
    ctx->pc = 0x80162298u;
    // 80162298: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016229C:
    // 8016229C: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_801622A0:
    ctx->pc = 0x801622A0u;
    // 801622A0: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801622A4:
    // 801622A4: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801622A8:
    ctx->pc = 0x801622A8u;
    // 801622A8: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801622AC:
    // 801622AC: b       0x80162364
    {
            goto label_80162364;
    }

label_801622B0:
    ctx->pc = 0x801622B0u;
    ctx->downcount -= 8;
    // 801622B0: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801622B4:
    // 801622B4: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801622B8:
    // 801622B8: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801622BC:
    // 801622BC: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_801622C0:
    // 801622C0: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_801622C4:
    // 801622C4: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_801622C8:
    // 801622C8: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_801622CC:
    // 801622CC: bc    12, 2, 0x801622EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801622EC;
        }
    }

label_801622D0:
    ctx->downcount -= 7;
    // 801622D0: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_801622D4:
    // 801622D4: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801622D8:
    // 801622D8: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801622DC:
    // 801622DC: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801622E0:
    ctx->pc = 0x801622E0u;
    // 801622E0: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801622E4:
    ctx->pc = 0x801622E4u;
    // 801622E4: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801622E8:
    ctx->pc = 0x801622E8u;
    // 801622E8: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801622EC:
    ctx->downcount -= 2;
    // 801622EC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801622F0:
    // 801622F0: bl      0x80281C60
    {
            ctx->lr = 0x801622F4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801622F4:
    ctx->downcount -= 3;
    // 801622F4: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801622F8:
    ctx->pc = 0x801622F8u;
    // 801622F8: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801622FC:
    // 801622FC: bc    4, 2, 0x80162348
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80162348;
        }
    }

label_80162300:
    ctx->downcount -= 3;
    // 80162300: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80162304:
    // 80162304: cmplwi  r11, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162308:
    // 80162308: bc    12, 1, 0x80162334
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162334;
        }
    }

label_8016230C:
    ctx->downcount -= 2;
    // 8016230C: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80162310:
    // 80162310: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80162314:
    ctx->downcount -= 5;
    // 80162314: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_80162318:
    // 80162318: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_8016231C:
    ctx->pc = 0x8016231Cu;
    // 8016231C: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80162320:
    // 80162320: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162324:
    // 80162324: bc    4, 2, 0x80162274
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80162274u;
                return;
            }
            goto label_80162274;
        }
    }

label_80162328:
    ctx->downcount -= 3;
    // 80162328: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_8016232C:
    // 8016232C: cmplwi  r11, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162330:
    // 80162330: bc    4, 1, 0x80162314
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80162314u;
                return;
            }
            goto label_80162314;
        }
    }

label_80162334:
    ctx->downcount -= 4;
    // 80162334: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80162338:
    // 80162338: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8016233C:
    ctx->pc = 0x8016233Cu;
    // 8016233C: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162340:
    // 80162340: bl      0x80281C60
    {
            ctx->lr = 0x80162344u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80162344:
    ctx->pc = 0x80162344u;
    ctx->downcount -= 1;
    // 80162344: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80162348:
    ctx->pc = 0x80162348u;
    ctx->downcount -= 7;
    // 80162348: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016234C:
    ctx->pc = 0x8016234Cu;
    // 8016234C: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162350:
    // 80162350: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80162354:
    // 80162354: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80162358:
    ctx->pc = 0x80162358u;
    // 80162358: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016235C:
    ctx->pc = 0x8016235Cu;
    // 8016235C: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80162360:
    // 80162360: b       0x8016224C
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8016224Cu;
                return;
            }
            goto label_8016224C;
    }

label_80162364:
    ctx->pc = 0x80162364u;
    ctx->downcount -= 16;
    // 80162364: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162368:
    ctx->pc = 0x80162368u;
    // 80162368: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8016236C:
    ctx->pc = 0x8016236Cu;
    // 8016236C: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80162370:
    ctx->pc = 0x80162370u;
    // 80162370: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80162374:
    ctx->pc = 0x80162374u;
    // 80162374: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162378:
    ctx->pc = 0x80162378u;
    ctx->downcount -= 21;
    // 80162378: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8016237C:
    ctx->pc = 0x8016237Cu;
    // 8016237C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162380:
    ctx->pc = 0x80162380u;
    // 80162380: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80162384:
    ctx->pc = 0x80162384u;
    // 80162384: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162388:
    ctx->pc = 0x80162388u;
    // 80162388: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_8016238C:
    ctx->pc = 0x8016238Cu;
    // 8016238C: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_80162390:
    ctx->pc = 0x80162390u;
    // 80162390: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80162394:
    ctx->pc = 0x80162394u;
    // 80162394: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80162398:
    ctx->pc = 0x80162398u;
    // 80162398: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8016239C:
    ctx->pc = 0x8016239Cu;
    // 8016239C: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801623A0:
    ctx->pc = 0x801623A0u;
    // 801623A0: bc    12, 2, 0x801623B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801623B0;
        }
    }

label_801623A4:
    ctx->pc = 0x801623A4u;
    ctx->downcount -= 3;
    // 801623A4: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801623A8:
    ctx->pc = 0x801623A8u;
    // 801623A8: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801623AC:
    ctx->pc = 0x801623ACu;
    // 801623AC: b       0x80162430
    {
            goto label_80162430;
    }

label_801623B0:
    ctx->pc = 0x801623B0u;
    ctx->downcount -= 7;
    // 801623B0: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_801623B4:
    ctx->pc = 0x801623B4u;
    // 801623B4: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_801623B8:
    ctx->pc = 0x801623B8u;
    // 801623B8: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_801623BC:
    ctx->pc = 0x801623BCu;
    // 801623BC: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801623C0:
    ctx->pc = 0x801623C0u;
    // 801623C0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801623C4:
    ctx->pc = 0x801623C4u;
    // 801623C4: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_801623C8:
    ctx->pc = 0x801623C8u;
    // 801623C8: bl      0x80003EE0
    {
            ctx->lr = 0x801623CCu;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_801623CC:
    ctx->pc = 0x801623CCu;
    ctx->downcount -= 3;
    // 801623CC: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801623D0:
    ctx->pc = 0x801623D0u;
    // 801623D0: cmpwi   r9, 1
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801623D4:
    ctx->pc = 0x801623D4u;
    // 801623D4: bc    12, 2, 0x8016242C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016242C;
        }
    }

label_801623D8:
    ctx->pc = 0x801623D8u;
    ctx->downcount -= 9;
    // 801623D8: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_801623DC:
    ctx->pc = 0x801623DCu;
    // 801623DC: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801623E0:
    ctx->pc = 0x801623E0u;
    // 801623E0: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801623E4:
    ctx->pc = 0x801623E4u;
    // 801623E4: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801623E8:
    ctx->pc = 0x801623E8u;
    // 801623E8: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801623EC:
    ctx->pc = 0x801623ECu;
    // 801623EC: cmpwi   r9, 2
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801623F0:
    ctx->pc = 0x801623F0u;
    // 801623F0: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_801623F4:
    ctx->pc = 0x801623F4u;
    // 801623F4: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801623F8:
    ctx->pc = 0x801623F8u;
    // 801623F8: bc    4, 2, 0x80162404
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80162404;
        }
    }

label_801623FC:
    ctx->pc = 0x801623FCu;
    ctx->downcount -= 2;
    // 801623FC: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80162400:
    ctx->pc = 0x80162400u;
    // 80162400: b       0x8016242C
    {
            goto label_8016242C;
    }

label_80162404:
    loop_80162404(ctx);
    if (ctx->pc == 0x80162424u) goto label_80162424;
    return;
label_80162408:
    // 80162408: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_8016240C:
    // 8016240C: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80162410:
    ctx->pc = 0x80162410u;
    // 80162410: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162414:
    // 80162414: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80162418:
    // 80162418: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_8016241C:
    // 8016241C: cmpw    r9, r8
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162420:
    // 80162420: bc    4, 2, 0x80162404
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80162404u;
                return;
            }
            goto label_80162404;
        }
    }

label_80162424:
    ctx->pc = 0x80162424u;
    ctx->downcount -= 2;
    // 80162424: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80162428:
    ctx->pc = 0x80162428u;
    // 80162428: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016242C:
    ctx->pc = 0x8016242Cu;
    ctx->downcount -= 1;
    // 8016242C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162430:
    ctx->pc = 0x80162430u;
    ctx->downcount -= 17;
    // 80162430: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80162434:
    ctx->pc = 0x80162434u;
    // 80162434: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162438:
    ctx->pc = 0x80162438u;
    // 80162438: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8016243C:
    ctx->pc = 0x8016243Cu;
    // 8016243C: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80162440:
    ctx->pc = 0x80162440u;
    // 80162440: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80162444:
    ctx->pc = 0x80162444u;
    // 80162444: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162448:
    ctx->pc = 0x80162448u;
    ctx->downcount -= 19;
    // 80162448: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8016244C:
    ctx->pc = 0x8016244Cu;
    // 8016244C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162450:
    ctx->pc = 0x80162450u;
    // 80162450: stmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80162454:
    ctx->pc = 0x80162454u;
    // 80162454: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162458:
    ctx->pc = 0x80162458u;
    // 80162458: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8016245C:
    ctx->pc = 0x8016245Cu;
    // 8016245C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80162460:
    ctx->pc = 0x80162460u;
    // 80162460: or   r26, r6, r6
    {
        ctx->gpr[26] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80162464:
    ctx->pc = 0x80162464u;
    // 80162464: or.   r5, r5, r5
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[5];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80162468:
    ctx->pc = 0x80162468u;
    // 80162468: bc    12, 2, 0x801626B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801626B4;
        }
    }

label_8016246C:
    ctx->pc = 0x8016246Cu;
    ctx->downcount -= 6;
    // 8016246C: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162470:
    ctx->pc = 0x80162470u;
    // 80162470: lwz     r3, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80162474:
    ctx->pc = 0x80162474u;
    // 80162474: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80162478:
    ctx->pc = 0x80162478u;
    // 80162478: srawi r0, r0, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[0] = value;
        } else if (sh > 31) {
            ctx->gpr[0] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[0] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8016247C:
    ctx->pc = 0x8016247Cu;
    // 8016247C: cmplw   r0, r5
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162480:
    ctx->pc = 0x80162480u;
    // 80162480: bc    12, 0, 0x80162598
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162598;
        }
    }

label_80162484:
    ctx->pc = 0x80162484u;
    ctx->downcount -= 7;
    // 80162484: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162488:
    ctx->pc = 0x80162488u;
    // 80162488: lwz     r9, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8016248C:
    ctx->pc = 0x8016248Cu;
    // 8016248C: subf   r0, r29, r31
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80162490:
    ctx->pc = 0x80162490u;
    // 80162490: srawi r0, r0, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[0] = value;
        } else if (sh > 31) {
            ctx->gpr[0] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[0] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80162494:
    ctx->pc = 0x80162494u;
    // 80162494: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80162498:
    ctx->pc = 0x80162498u;
    // 80162498: cmplw   r0, r5
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016249C:
    ctx->pc = 0x8016249Cu;
    // 8016249C: bc    4, 1, 0x80162508
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80162508;
        }
    }

label_801624A0:
    ctx->pc = 0x801624A0u;
    ctx->downcount -= 5;
    // 801624A0: rlwinm r0, r5, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 2u) & 0xFFFFFFFCu;
    }

label_801624A4:
    ctx->pc = 0x801624A4u;
    // 801624A4: subf   r30, r0, r31
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_801624A8:
    ctx->pc = 0x801624A8u;
    // 801624A8: or   r27, r0, r0
    {
        ctx->gpr[27] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801624AC:
    ctx->pc = 0x801624ACu;
    // 801624AC: cmpw    r31, r30
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801624B0:
    ctx->pc = 0x801624B0u;
    // 801624B0: bc    12, 2, 0x801624C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801624C0;
        }
    }

label_801624B4:
    ctx->pc = 0x801624B4u;
    ctx->downcount -= 3;
    // 801624B4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801624B8:
    ctx->pc = 0x801624B8u;
    // 801624B8: subf   r5, r30, r31
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_801624BC:
    ctx->pc = 0x801624BCu;
    // 801624BC: bl      0x80297E3C
    {
            ctx->lr = 0x801624C0u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_801624C0:
    ctx->pc = 0x801624C0u;
    ctx->downcount -= 5;
    // 801624C0: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801624C4:
    ctx->pc = 0x801624C4u;
    // 801624C4: subf.   r5, r29, r30
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801624C8:
    ctx->pc = 0x801624C8u;
    // 801624C8: add   r0, r0, r27
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801624CC:
    ctx->pc = 0x801624CCu;
    // 801624CC: stw     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801624D0:
    ctx->pc = 0x801624D0u;
    // 801624D0: bc    4, 1, 0x801624E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801624E0;
        }
    }

label_801624D4:
    ctx->pc = 0x801624D4u;
    ctx->downcount -= 3;
    // 801624D4: subf   r3, r5, r31
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_801624D8:
    ctx->pc = 0x801624D8u;
    // 801624D8: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801624DC:
    ctx->pc = 0x801624DCu;
    // 801624DC: bl      0x80297E3C
    {
            ctx->lr = 0x801624E0u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_801624E0:
    ctx->pc = 0x801624E0u;
    ctx->downcount -= 4;
    // 801624E0: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801624E4:
    ctx->pc = 0x801624E4u;
    // 801624E4: add   r0, r27, r4
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801624E8:
    ctx->pc = 0x801624E8u;
    // 801624E8: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801624EC:
    ctx->pc = 0x801624ECu;
    // 801624EC: bc    12, 2, 0x801626B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801626B4;
        }
    }

label_801624F0:
    ctx->pc = 0x801624F0u;
    ctx->downcount -= 1;
    // 801624F0: lwz     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801624F4:
    loop_801624F4(ctx);
    if (ctx->pc == 0x80162504u) goto label_80162504;
    return;
label_801624F8:
    // 801624F8: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_801624FC:
    // 801624FC: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162500:
    // 80162500: bc    4, 2, 0x801624F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801624F4u;
                return;
            }
            goto label_801624F4;
        }
    }

label_80162504:
    ctx->pc = 0x80162504u;
    ctx->downcount -= 1;
    // 80162504: b       0x801626B4
    {
            goto label_801626B4;
    }

label_80162508:
    ctx->pc = 0x80162508u;
    ctx->downcount -= 13;
    // 80162508: subf.   r9, r0, r5
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8016250C:
    ctx->pc = 0x8016250Cu;
    // 8016250C: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_80162510:
    ctx->pc = 0x80162510u;
    // 80162510: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_80162514:
    ctx->pc = 0x80162514u;
    // 80162514: cmpw    cr6, r29, r31
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 4)) | (cr_bits << 4);
    }

label_80162518:
    ctx->pc = 0x80162518u;
    // 80162518: or   r26, r11, r11
    {
        ctx->gpr[26] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8016251C:
    ctx->pc = 0x8016251Cu;
    // 8016251C: rlwinm r27, r0, 2, 0, 29
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80162520:
    ctx->pc = 0x80162520u;
    // 80162520: or   r9, r31, r31
    {
        ctx->gpr[9] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80162524:
    ctx->pc = 0x80162524u;
    // 80162524: cmpw    cr7, r31, r29
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 0)) | (cr_bits << 0);
    }

label_80162528:
    ctx->pc = 0x80162528u;
    // 80162528: mfctr    r10
    ctx->gpr[10] = ctx->ctr;

label_8016252C:
    ctx->pc = 0x8016252Cu;
    // 8016252C: mfcr    r30
    ctx->gpr[30] = ctx->cr;

label_80162530:
    ctx->pc = 0x80162530u;
    // 80162530: rlwinm r30, r30, 24, 0, 3
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 24u) & 0xF0000000u;
    }

label_80162534:
    ctx->pc = 0x80162534u;
    // 80162534: bc    12, 2, 0x80162548
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162548;
        }
    }

label_80162538:
    loop_80162538(ctx);
    if (ctx->pc == 0x80162548u) goto label_80162548;
    return;
label_8016253C:
    ctx->pc = 0x8016253Cu;
    // 8016253C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162540:
    // 80162540: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80162544:
    // 80162544: bc    16, 0, 0x80162538
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80162538u;
                return;
            }
            goto label_80162538;
        }
    }

label_80162548:
    ctx->pc = 0x80162548u;
    ctx->downcount -= 5;
    // 80162548: lwz     r9, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8016254C:
    ctx->pc = 0x8016254Cu;
    // 8016254C: rlwinm r0, r10, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 2u) & 0xFFFFFFFCu;
    }

label_80162550:
    ctx->pc = 0x80162550u;
    // 80162550: add   r3, r9, r0
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162554:
    ctx->pc = 0x80162554u;
    // 80162554: stw     r3, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80162558:
    ctx->pc = 0x80162558u;
    // 80162558: bc    12, 30, 0x80162568
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162568;
        }
    }

label_8016255C:
    ctx->pc = 0x8016255Cu;
    ctx->downcount -= 3;
    // 8016255C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80162560:
    ctx->pc = 0x80162560u;
    // 80162560: subf   r5, r29, r31
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_80162564:
    ctx->pc = 0x80162564u;
    // 80162564: bl      0x80297E3C
    {
            ctx->lr = 0x80162568u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80162568:
    ctx->pc = 0x80162568u;
    ctx->downcount -= 6;
    // 80162568: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016256C:
    ctx->pc = 0x8016256Cu;
    // 8016256C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80162570:
    ctx->pc = 0x80162570u;
    // 80162570: mtcrf   0x80, r30
    ctx->cr = (ctx->cr & ~0xF0000000u) | (ctx->gpr[30] & 0xF0000000u);

label_80162574:
    ctx->pc = 0x80162574u;
    // 80162574: add   r0, r0, r27
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80162578:
    ctx->pc = 0x80162578u;
    // 80162578: stw     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016257C:
    ctx->pc = 0x8016257Cu;
    // 8016257C: bc    12, 2, 0x801626B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801626B4;
        }
    }

label_80162580:
    ctx->pc = 0x80162580u;
    ctx->downcount -= 1;
    // 80162580: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162584:
    loop_80162584(ctx);
    if (ctx->pc == 0x80162594u) goto label_80162594;
    return;
label_80162588:
    // 80162588: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_8016258C:
    // 8016258C: cmpw    r4, r31
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162590:
    // 80162590: bc    4, 2, 0x80162584
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80162584u;
                return;
            }
            goto label_80162584;
        }
    }

label_80162594:
    ctx->pc = 0x80162594u;
    ctx->downcount -= 1;
    // 80162594: b       0x801626B4
    {
            goto label_801626B4;
    }

label_80162598:
    ctx->pc = 0x80162598u;
    ctx->downcount -= 9;
    // 80162598: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016259C:
    ctx->pc = 0x8016259Cu;
    // 8016259C: addi    r11, r1, 16
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(16);

label_801625A0:
    ctx->pc = 0x801625A0u;
    // 801625A0: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_801625A4:
    ctx->pc = 0x801625A4u;
    // 801625A4: addi    r9, r1, 12
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(12);

label_801625A8:
    ctx->pc = 0x801625A8u;
    // 801625A8: subf   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801625AC:
    ctx->pc = 0x801625ACu;
    // 801625AC: srawi r3, r0, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[3] = value;
        } else if (sh > 31) {
            ctx->gpr[3] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[3] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_801625B0:
    ctx->pc = 0x801625B0u;
    // 801625B0: cmplw   r3, r5
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801625B4:
    ctx->pc = 0x801625B4u;
    // 801625B4: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801625B8:
    ctx->pc = 0x801625B8u;
    // 801625B8: bc    4, 0, 0x801625C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801625C0;
        }
    }

label_801625BC:
    ctx->pc = 0x801625BCu;
    ctx->downcount -= 1;
    // 801625BC: or   r9, r11, r11
    {
        ctx->gpr[9] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801625C0:
    ctx->pc = 0x801625C0u;
    ctx->downcount -= 3;
    // 801625C0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801625C4:
    ctx->pc = 0x801625C4u;
    // 801625C4: add.   r0, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801625C8:
    ctx->pc = 0x801625C8u;
    // 801625C8: bc    12, 2, 0x801625FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801625FC;
        }
    }

label_801625CC:
    ctx->pc = 0x801625CCu;
    ctx->downcount -= 4;
    // 801625CC: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_801625D0:
    ctx->pc = 0x801625D0u;
    // 801625D0: or   r27, r0, r0
    {
        ctx->gpr[27] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801625D4:
    ctx->pc = 0x801625D4u;
    // 801625D4: cmplwi  r0, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801625D8:
    ctx->pc = 0x801625D8u;
    // 801625D8: bc    4, 1, 0x801625EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801625EC;
        }
    }

label_801625DC:
    ctx->pc = 0x801625DCu;
    ctx->downcount -= 2;
    // 801625DC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801625E0:
    ctx->pc = 0x801625E0u;
    // 801625E0: bl      0x80281C60
    {
            ctx->lr = 0x801625E4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801625E4:
    ctx->pc = 0x801625E4u;
    ctx->downcount -= 2;
    // 801625E4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801625E8:
    ctx->pc = 0x801625E8u;
    // 801625E8: b       0x80162604
    {
            goto label_80162604;
    }

label_801625EC:
    ctx->pc = 0x801625ECu;
    ctx->downcount -= 2;
    // 801625EC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801625F0:
    ctx->pc = 0x801625F0u;
    // 801625F0: bl      0x80004024
    {
            ctx->lr = 0x801625F4u;
            ctx->pc = 0x80004024u;
            return;
    }

label_801625F4:
    ctx->pc = 0x801625F4u;
    ctx->downcount -= 2;
    // 801625F4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801625F8:
    ctx->pc = 0x801625F8u;
    // 801625F8: b       0x80162604
    {
            goto label_80162604;
    }

label_801625FC:
    ctx->pc = 0x801625FCu;
    ctx->downcount -= 2;
    // 801625FC: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80162600:
    ctx->pc = 0x80162600u;
    // 80162600: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_80162604:
    ctx->pc = 0x80162604u;
    ctx->downcount -= 3;
    // 80162604: lwz     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80162608:
    ctx->pc = 0x80162608u;
    // 80162608: cmpw    r29, r4
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016260C:
    ctx->pc = 0x8016260Cu;
    // 8016260C: bc    12, 2, 0x80162628
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162628;
        }
    }

label_80162610:
    ctx->pc = 0x80162610u;
    ctx->downcount -= 4;
    // 80162610: subf   r30, r4, r29
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[29];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_80162614:
    ctx->pc = 0x80162614u;
    // 80162614: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80162618:
    ctx->pc = 0x80162618u;
    // 80162618: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8016261C:
    ctx->pc = 0x8016261Cu;
    // 8016261C: bl      0x80297E3C
    {
            ctx->lr = 0x80162620u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80162620:
    ctx->pc = 0x80162620u;
    ctx->downcount -= 2;
    // 80162620: add   r3, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162624:
    ctx->pc = 0x80162624u;
    // 80162624: b       0x8016262C
    {
            goto label_8016262C;
    }

label_80162628:
    ctx->pc = 0x80162628u;
    ctx->downcount -= 1;
    // 80162628: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8016262C:
    ctx->pc = 0x8016262Cu;
    ctx->downcount -= 5;
    // 8016262C: lwz     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162630:
    ctx->pc = 0x80162630u;
    // 80162630: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80162634:
    ctx->pc = 0x80162634u;
    // 80162634: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162638:
    ctx->pc = 0x80162638u;
    // 80162638: bc    12, 2, 0x8016264C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016264C;
        }
    }

label_8016263C:
    loop_8016263C(ctx);
    if (ctx->pc == 0x8016264Cu) goto label_8016264C;
    return;
label_80162640:
    ctx->pc = 0x80162640u;
    // 80162640: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162644:
    // 80162644: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_80162648:
    // 80162648: bc    16, 0, 0x8016263C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8016263Cu;
                return;
            }
            goto label_8016263C;
        }
    }

label_8016264C:
    ctx->pc = 0x8016264Cu;
    ctx->downcount -= 3;
    // 8016264C: lwz     r30, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80162650:
    ctx->pc = 0x80162650u;
    // 80162650: cmpw    r30, r29
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162654:
    ctx->pc = 0x80162654u;
    // 80162654: bc    12, 2, 0x80162670
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162670;
        }
    }

label_80162658:
    ctx->pc = 0x80162658u;
    ctx->downcount -= 4;
    // 80162658: subf   r30, r29, r30
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_8016265C:
    ctx->pc = 0x8016265Cu;
    // 8016265C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80162660:
    ctx->pc = 0x80162660u;
    // 80162660: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80162664:
    ctx->pc = 0x80162664u;
    // 80162664: bl      0x80297E3C
    {
            ctx->lr = 0x80162668u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80162668:
    ctx->pc = 0x80162668u;
    ctx->downcount -= 2;
    // 80162668: add   r30, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_8016266C:
    ctx->pc = 0x8016266Cu;
    // 8016266C: b       0x80162674
    {
            goto label_80162674;
    }

label_80162670:
    ctx->pc = 0x80162670u;
    ctx->downcount -= 1;
    // 80162670: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162674:
    ctx->pc = 0x80162674u;
    ctx->downcount -= 6;
    // 80162674: lwz     r3, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80162678:
    ctx->pc = 0x80162678u;
    // 80162678: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016267C:
    ctx->pc = 0x8016267Cu;
    // 8016267C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162680:
    ctx->pc = 0x80162680u;
    // 80162680: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80162684:
    ctx->pc = 0x80162684u;
    // 80162684: srawi r0, r0, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[0] = value;
        } else if (sh > 31) {
            ctx->gpr[0] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[0] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80162688:
    ctx->pc = 0x80162688u;
    // 80162688: bc    12, 2, 0x801626A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801626A4;
        }
    }

label_8016268C:
    ctx->pc = 0x8016268Cu;
    ctx->downcount -= 3;
    // 8016268C: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80162690:
    ctx->pc = 0x80162690u;
    // 80162690: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162694:
    ctx->pc = 0x80162694u;
    // 80162694: bc    4, 1, 0x801626A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801626A0;
        }
    }

label_80162698:
    ctx->pc = 0x80162698u;
    ctx->downcount -= 1;
    // 80162698: bl      0x80281D80
    {
            ctx->lr = 0x8016269Cu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_8016269C:
    ctx->pc = 0x8016269Cu;
    ctx->downcount -= 1;
    // 8016269C: b       0x801626A4
    {
            goto label_801626A4;
    }

label_801626A0:
    ctx->pc = 0x801626A0u;
    ctx->downcount -= 1;
    // 801626A0: bl      0x8001D934
    {
            ctx->lr = 0x801626A4u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_801626A4:
    ctx->pc = 0x801626A4u;
    ctx->downcount -= 4;
    // 801626A4: add   r0, r27, r31
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801626A8:
    ctx->pc = 0x801626A8u;
    // 801626A8: stw     r31, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801626AC:
    ctx->pc = 0x801626ACu;
    // 801626AC: stw     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801626B0:
    ctx->pc = 0x801626B0u;
    // 801626B0: stw     r30, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801626B4:
    ctx->pc = 0x801626B4u;
    ctx->downcount -= 16;
    // 801626B4: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801626B8:
    ctx->pc = 0x801626B8u;
    // 801626B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801626BC:
    ctx->pc = 0x801626BCu;
    // 801626BC: lmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801626C0:
    ctx->pc = 0x801626C0u;
    // 801626C0: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_801626C4:
    ctx->pc = 0x801626C4u;
    // 801626C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801626C8:
    ctx->pc = 0x801626C8u;
    ctx->downcount -= 7;
    // 801626C8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801626CC:
    ctx->pc = 0x801626CCu;
    // 801626CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801626D0:
    ctx->pc = 0x801626D0u;
    // 801626D0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801626D4:
    ctx->pc = 0x801626D4u;
    // 801626D4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801626D8:
    ctx->pc = 0x801626D8u;
    // 801626D8: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_801626DC:
    ctx->pc = 0x801626DCu;
    // 801626DC: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801626E0:
    ctx->pc = 0x801626E0u;
    // 801626E0: bc    4, 2, 0x801627DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801627DC;
        }
    }

label_801626E4:
    ctx->pc = 0x801626E4u;
    ctx->downcount -= 2;
    // 801626E4: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801626E8:
    ctx->pc = 0x801626E8u;
    // 801626E8: bc    12, 2, 0x801627DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801627DC;
        }
    }

label_801626EC:
    ctx->pc = 0x801626ECu;
    ctx->downcount -= 5;
    // 801626EC: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_801626F0:
    ctx->pc = 0x801626F0u;
    // 801626F0: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_801626F4:
    ctx->pc = 0x801626F4u;
    // 801626F4: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_801626F8:
    ctx->pc = 0x801626F8u;
    // 801626F8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801626FC:
    ctx->pc = 0x801626FCu;
    // 801626FC: bl      0x80252AF0
    {
            ctx->lr = 0x80162700u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162700:
    ctx->pc = 0x80162700u;
    ctx->downcount -= 5;
    // 80162700: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_80162704:
    ctx->pc = 0x80162704u;
    // 80162704: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80162708:
    ctx->pc = 0x80162708u;
    // 80162708: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_8016270C:
    ctx->pc = 0x8016270Cu;
    // 8016270C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162710:
    ctx->pc = 0x80162710u;
    // 80162710: bl      0x80252AF0
    {
            ctx->lr = 0x80162714u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162714:
    ctx->pc = 0x80162714u;
    ctx->downcount -= 5;
    // 80162714: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_80162718:
    ctx->pc = 0x80162718u;
    // 80162718: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_8016271C:
    ctx->pc = 0x8016271Cu;
    // 8016271C: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_80162720:
    ctx->pc = 0x80162720u;
    // 80162720: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_80162724:
    ctx->pc = 0x80162724u;
    // 80162724: bl      0x80252AF0
    {
            ctx->lr = 0x80162728u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162728:
    ctx->pc = 0x80162728u;
    ctx->downcount -= 5;
    // 80162728: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_8016272C:
    ctx->pc = 0x8016272Cu;
    // 8016272C: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80162730:
    ctx->pc = 0x80162730u;
    // 80162730: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_80162734:
    ctx->pc = 0x80162734u;
    // 80162734: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162738:
    ctx->pc = 0x80162738u;
    // 80162738: bl      0x80252AF0
    {
            ctx->lr = 0x8016273Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8016273C:
    ctx->pc = 0x8016273Cu;
    ctx->downcount -= 5;
    // 8016273C: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_80162740:
    ctx->pc = 0x80162740u;
    // 80162740: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_80162744:
    ctx->pc = 0x80162744u;
    // 80162744: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_80162748:
    ctx->pc = 0x80162748u;
    // 80162748: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8016274C:
    ctx->pc = 0x8016274Cu;
    // 8016274C: bl      0x80252AF0
    {
            ctx->lr = 0x80162750u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162750:
    ctx->pc = 0x80162750u;
    ctx->downcount -= 5;
    // 80162750: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_80162754:
    ctx->pc = 0x80162754u;
    // 80162754: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80162758:
    ctx->pc = 0x80162758u;
    // 80162758: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_8016275C:
    ctx->pc = 0x8016275Cu;
    // 8016275C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162760:
    ctx->pc = 0x80162760u;
    // 80162760: bl      0x80252AF0
    {
            ctx->lr = 0x80162764u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162764:
    ctx->pc = 0x80162764u;
    ctx->downcount -= 5;
    // 80162764: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_80162768:
    ctx->pc = 0x80162768u;
    // 80162768: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8016276C:
    ctx->pc = 0x8016276Cu;
    // 8016276C: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_80162770:
    ctx->pc = 0x80162770u;
    // 80162770: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162774:
    ctx->pc = 0x80162774u;
    // 80162774: bl      0x80252AF0
    {
            ctx->lr = 0x80162778u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162778:
    ctx->pc = 0x80162778u;
    ctx->downcount -= 5;
    // 80162778: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_8016277C:
    ctx->pc = 0x8016277Cu;
    // 8016277C: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_80162780:
    ctx->pc = 0x80162780u;
    // 80162780: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_80162784:
    ctx->pc = 0x80162784u;
    // 80162784: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162788:
    ctx->pc = 0x80162788u;
    // 80162788: bl      0x80252AF0
    {
            ctx->lr = 0x8016278Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8016278C:
    ctx->pc = 0x8016278Cu;
    ctx->downcount -= 5;
    // 8016278C: lis     r3, 25197
    ctx->gpr[3] = ((u32)(s32)(25197) << 16);

label_80162790:
    ctx->pc = 0x80162790u;
    // 80162790: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_80162794:
    ctx->pc = 0x80162794u;
    // 80162794: ori     r3, r3, 0x7368
    ctx->gpr[3] = ctx->gpr[3] | 0x7368u;

label_80162798:
    ctx->pc = 0x80162798u;
    // 80162798: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8016279C:
    ctx->pc = 0x8016279Cu;
    // 8016279C: bl      0x80252AF0
    {
            ctx->lr = 0x801627A0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801627A0:
    ctx->pc = 0x801627A0u;
    ctx->downcount -= 5;
    // 801627A0: lis     r3, 25199
    ctx->gpr[3] = ((u32)(s32)(25199) << 16);

label_801627A4:
    ctx->pc = 0x801627A4u;
    // 801627A4: li      r4, 63
    ctx->gpr[4] = (u32)(s32)(63);

label_801627A8:
    ctx->pc = 0x801627A8u;
    // 801627A8: ori     r3, r3, 0x6479
    ctx->gpr[3] = ctx->gpr[3] | 0x6479u;

label_801627AC:
    ctx->pc = 0x801627ACu;
    // 801627AC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801627B0:
    ctx->pc = 0x801627B0u;
    // 801627B0: bl      0x80252AF0
    {
            ctx->lr = 0x801627B4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801627B4:
    ctx->pc = 0x801627B4u;
    ctx->downcount -= 5;
    // 801627B4: lis     r3, 25185
    ctx->gpr[3] = ((u32)(s32)(25185) << 16);

label_801627B8:
    ctx->pc = 0x801627B8u;
    // 801627B8: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_801627BC:
    ctx->pc = 0x801627BCu;
    // 801627BC: ori     r3, r3, 0x6E6D
    ctx->gpr[3] = ctx->gpr[3] | 0x6E6Du;

label_801627C0:
    ctx->pc = 0x801627C0u;
    // 801627C0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801627C4:
    ctx->pc = 0x801627C4u;
    // 801627C4: bl      0x80252AF0
    {
            ctx->lr = 0x801627C8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801627C8:
    ctx->pc = 0x801627C8u;
    ctx->downcount -= 5;
    // 801627C8: lis     r3, 27749
    ctx->gpr[3] = ((u32)(s32)(27749) << 16);

label_801627CC:
    ctx->pc = 0x801627CCu;
    // 801627CC: li      r4, 86
    ctx->gpr[4] = (u32)(s32)(86);

label_801627D0:
    ctx->pc = 0x801627D0u;
    // 801627D0: ori     r3, r3, 0x766C
    ctx->gpr[3] = ctx->gpr[3] | 0x766Cu;

label_801627D4:
    ctx->pc = 0x801627D4u;
    // 801627D4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801627D8:
    ctx->pc = 0x801627D8u;
    // 801627D8: bl      0x80252AF0
    {
            ctx->lr = 0x801627DCu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801627DC:
    ctx->pc = 0x801627DCu;
    ctx->downcount -= 5;
    // 801627DC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801627E0:
    ctx->pc = 0x801627E0u;
    // 801627E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801627E4:
    ctx->pc = 0x801627E4u;
    // 801627E4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801627E8:
    ctx->pc = 0x801627E8u;
    // 801627E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801627EC:
    ctx->pc = 0x801627ECu;
    ctx->downcount -= 2;
    // 801627EC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801627F0:
    ctx->pc = 0x801627F0u;
    // 801627F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801627F4:
    ctx->pc = 0x801627F4u;
    ctx->downcount -= 2;
    // 801627F4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801627F8:
    ctx->pc = 0x801627F8u;
    // 801627F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801627FC:
    ctx->pc = 0x801627FCu;
    ctx->downcount -= 10;
    // 801627FC: stwu     r1, -280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-280);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162800:
    ctx->pc = 0x80162800u;
    // 80162800: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162804:
    ctx->pc = 0x80162804u;
    // 80162804: stw     r31, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80162808:
    ctx->pc = 0x80162808u;
    // 80162808: stw     r0, 284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(284);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016280C:
    ctx->pc = 0x8016280Cu;
    // 8016280C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80162810:
    ctx->pc = 0x80162810u;
    // 80162810: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162814:
    ctx->pc = 0x80162814u;
    // 80162814: addi    r4, r9, -26016
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(-26016);

label_80162818:
    ctx->pc = 0x80162818u;
    // 80162818: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8016281C:
    ctx->pc = 0x8016281Cu;
    // 8016281C: cmpwi   r4, 0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162820:
    ctx->pc = 0x80162820u;
    // 80162820: bc    12, 2, 0x80162830
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162830;
        }
    }

label_80162824:
    ctx->pc = 0x80162824u;
    ctx->downcount -= 2;
    // 80162824: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_80162828:
    ctx->pc = 0x80162828u;
    // 80162828: bl      0x80287F10
    {
            ctx->lr = 0x8016282Cu;
            ctx->pc = 0x80287F10u;
            return;
    }

label_8016282C:
    ctx->pc = 0x8016282Cu;
    ctx->downcount -= 1;
    // 8016282C: b       0x80162834
    {
            goto label_80162834;
    }

label_80162830:
    ctx->pc = 0x80162830u;
    ctx->downcount -= 1;
    // 80162830: stb     r4, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80162834:
    ctx->pc = 0x80162834u;
    ctx->downcount -= 6;
    // 80162834: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_80162838:
    ctx->pc = 0x80162838u;
    // 80162838: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8016283C:
    ctx->pc = 0x8016283Cu;
    // 8016283C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80162840:
    ctx->pc = 0x80162840u;
    // 80162840: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80162844:
    ctx->pc = 0x80162844u;
    // 80162844: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80162848:
    ctx->pc = 0x80162848u;
    // 80162848: bl      0x8015A93C
    {
            ctx->lr = 0x8016284Cu;
            ctx->pc = 0x8015A93Cu;
            return;
    }

label_8016284C:
    ctx->pc = 0x8016284Cu;
    ctx->downcount -= 16;
    // 8016284C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80162850:
    ctx->pc = 0x80162850u;
    // 80162850: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80162854:
    ctx->pc = 0x80162854u;
    // 80162854: addi    r9, r9, -25672
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-25672);

label_80162858:
    ctx->pc = 0x80162858u;
    // 80162858: stw     r0, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016285C:
    ctx->pc = 0x8016285Cu;
    // 8016285C: stw     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80162860:
    ctx->pc = 0x80162860u;
    // 80162860: addi    r11, r31, 704
    ctx->gpr[11] = ctx->gpr[31] + (u32)(s32)(704);

label_80162864:
    ctx->pc = 0x80162864u;
    // 80162864: stw     r0, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162868:
    ctx->pc = 0x80162868u;
    // 80162868: addi    r9, r31, 712
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(712);

label_8016286C:
    ctx->pc = 0x8016286Cu;
    // 8016286C: stw     r0, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162870:
    ctx->pc = 0x80162870u;
    // 80162870: stw     r0, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162874:
    ctx->pc = 0x80162874u;
    // 80162874: stw     r0, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162878:
    ctx->pc = 0x80162878u;
    // 80162878: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016287C:
    ctx->pc = 0x8016287Cu;
    // 8016287C: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162880:
    ctx->pc = 0x80162880u;
    // 80162880: stw     r0, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162884:
    ctx->pc = 0x80162884u;
    // 80162884: stw     r0, 720(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(720);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162888:
    ctx->pc = 0x80162888u;
    // 80162888: bl      0x800D9B98
    {
            ctx->lr = 0x8016288Cu;
            ctx->pc = 0x800D9B98u;
            return;
    }

label_8016288C:
    ctx->pc = 0x8016288Cu;
    ctx->downcount -= 7;
    // 8016288C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80162890:
    ctx->pc = 0x80162890u;
    // 80162890: lwz     r0, 284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(284);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162894:
    ctx->pc = 0x80162894u;
    // 80162894: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162898:
    ctx->pc = 0x80162898u;
    // 80162898: lwz     r31, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8016289C:
    ctx->pc = 0x8016289Cu;
    // 8016289C: addi    r1, r1, 280
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(280);

label_801628A0:
    ctx->pc = 0x801628A0u;
    // 801628A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801628A4:
    ctx->pc = 0x801628A4u;
    ctx->downcount -= 6;
    // 801628A4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801628A8:
    ctx->pc = 0x801628A8u;
    // 801628A8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801628AC:
    ctx->pc = 0x801628ACu;
    // 801628AC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801628B0:
    ctx->pc = 0x801628B0u;
    // 801628B0: lwz     r0, 668(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(668);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801628B4:
    ctx->pc = 0x801628B4u;
    // 801628B4: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801628B8:
    ctx->pc = 0x801628B8u;
    // 801628B8: bc    4, 2, 0x801628C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801628C8;
        }
    }

label_801628BC:
    ctx->pc = 0x801628BCu;
    ctx->downcount -= 1;
    // 801628BC: bl      0x8015E29C
    {
            ctx->lr = 0x801628C0u;
            ctx->pc = 0x8015E29Cu;
            return;
    }

label_801628C0:
    ctx->pc = 0x801628C0u;
    ctx->downcount -= 2;
    // 801628C0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801628C4:
    ctx->pc = 0x801628C4u;
    // 801628C4: b       0x801628E4
    {
            goto label_801628E4;
    }

label_801628C8:
    ctx->pc = 0x801628C8u;
    ctx->downcount -= 2;
    // 801628C8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801628CC:
    ctx->pc = 0x801628CCu;
    // 801628CC: bl      0x80213970
    {
            ctx->lr = 0x801628D0u;
            ctx->pc = 0x80213970u;
            return;
    }

label_801628D0:
    ctx->pc = 0x801628D0u;
    ctx->downcount -= 2;
    // 801628D0: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801628D4:
    ctx->pc = 0x801628D4u;
    // 801628D4: bc    12, 2, 0x801628DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801628DC;
        }
    }

label_801628D8:
    ctx->pc = 0x801628D8u;
    ctx->downcount -= 1;
    // 801628D8: bl      0x800F0618
    {
            ctx->lr = 0x801628DCu;
            ctx->pc = 0x800F0618u;
            return;
    }

label_801628DC:
    ctx->pc = 0x801628DCu;
    ctx->downcount -= 2;
    // 801628DC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801628E0:
    ctx->pc = 0x801628E0u;
    // 801628E0: bl      0x80213970
    {
            ctx->lr = 0x801628E4u;
            ctx->pc = 0x80213970u;
            return;
    }

label_801628E4:
    ctx->pc = 0x801628E4u;
    ctx->downcount -= 5;
    // 801628E4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801628E8:
    ctx->pc = 0x801628E8u;
    // 801628E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801628EC:
    ctx->pc = 0x801628ECu;
    // 801628EC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801628F0:
    ctx->pc = 0x801628F0u;
    // 801628F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801628F4:
    ctx->pc = 0x801628F4u;
    ctx->downcount -= 18;
    // 801628F4: stwu     r1, -152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-152);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801628F8:
    ctx->pc = 0x801628F8u;
    // 801628F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801628FC:
    ctx->pc = 0x801628FCu;
    // 801628FC: stw     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80162900:
    ctx->pc = 0x80162900u;
    // 80162900: stw     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162904:
    ctx->pc = 0x80162904u;
    // 80162904: lis     r12, 512
    ctx->gpr[12] = ((u32)(s32)(512) << 16);

label_80162908:
    ctx->pc = 0x80162908u;
    // 80162908: addi    r0, r1, 160
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(160);

label_8016290C:
    ctx->pc = 0x8016290Cu;
    // 8016290C: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_80162910:
    ctx->pc = 0x80162910u;
    // 80162910: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162914:
    ctx->pc = 0x80162914u;
    // 80162914: stw     r11, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80162918:
    ctx->pc = 0x80162918u;
    // 80162918: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8016291C:
    ctx->pc = 0x8016291Cu;
    // 8016291C: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80162920:
    ctx->pc = 0x80162920u;
    // 80162920: stw     r6, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80162924:
    ctx->pc = 0x80162924u;
    // 80162924: stw     r7, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80162928:
    ctx->pc = 0x80162928u;
    // 80162928: stw     r8, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8016292C:
    ctx->pc = 0x8016292Cu;
    // 8016292C: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80162930:
    ctx->pc = 0x80162930u;
    // 80162930: stw     r10, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80162934:
    ctx->pc = 0x80162934u;
    // 80162934: stw     r12, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80162938:
    ctx->pc = 0x80162938u;
    // 80162938: bc    4, 6, 0x8016295C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x02000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8016295C;
        }
    }

label_8016293C:
    ctx->pc = 0x8016293Cu;
    ctx->downcount -= 8;
    // 8016293C: stfd     f1, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8016293Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_80162940:
    ctx->pc = 0x80162940u;
    // 80162940: stfd     f2, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x80162940u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_80162944:
    ctx->pc = 0x80162944u;
    // 80162944: stfd     f3, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80162944u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_80162948:
    ctx->pc = 0x80162948u;
    // 80162948: stfd     f4, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80162948u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_8016294C:
    ctx->pc = 0x8016294Cu;
    // 8016294C: stfd     f5, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8016294Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_80162950:
    ctx->pc = 0x80162950u;
    // 80162950: stfd     f6, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x80162950u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_80162954:
    ctx->pc = 0x80162954u;
    // 80162954: stfd     f7, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x80162954u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_80162958:
    ctx->pc = 0x80162958u;
    // 80162958: stfd     f8, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x80162958u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
    }

label_8016295C:
    ctx->pc = 0x8016295Cu;
    ctx->downcount -= 12;
    // 8016295C: addi    r11, r1, 128
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(128);

label_80162960:
    ctx->pc = 0x80162960u;
    // 80162960: addi    r9, r1, 112
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(112);

label_80162964:
    ctx->pc = 0x80162964u;
    // 80162964: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162968:
    ctx->pc = 0x80162968u;
    // 80162968: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8016296C:
    ctx->pc = 0x8016296Cu;
    // 8016296C: lwz     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80162970:
    ctx->pc = 0x80162970u;
    // 80162970: or   r6, r9, r9
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80162974:
    ctx->pc = 0x80162974u;
    // 80162974: stw     r12, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80162978:
    ctx->pc = 0x80162978u;
    // 80162978: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8016297C:
    ctx->pc = 0x8016297Cu;
    // 8016297C: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162980:
    ctx->pc = 0x80162980u;
    // 80162980: li      r4, 260
    ctx->gpr[4] = (u32)(s32)(260);

label_80162984:
    ctx->pc = 0x80162984u;
    // 80162984: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80162988:
    ctx->pc = 0x80162988u;
    // 80162988: bl      0x80296720
    {
            ctx->lr = 0x8016298Cu;
            ctx->pc = 0x80296720u;
            return;
    }

label_8016298C:
    ctx->pc = 0x8016298Cu;
    ctx->downcount -= 8;
    // 8016298C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80162990:
    ctx->pc = 0x80162990u;
    // 80162990: stb     r0, 259(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(259);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80162994:
    ctx->pc = 0x80162994u;
    // 80162994: lwz     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162998:
    ctx->pc = 0x80162998u;
    // 80162998: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8016299C:
    ctx->pc = 0x8016299Cu;
    // 8016299C: lwz     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801629A0:
    ctx->pc = 0x801629A0u;
    // 801629A0: addi    r1, r1, 152
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(152);

label_801629A4:
    ctx->pc = 0x801629A4u;
    // 801629A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801629A8:
    ctx->pc = 0x801629A8u;
    ctx->downcount -= 18;
    // 801629A8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801629AC:
    ctx->pc = 0x801629ACu;
    // 801629AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801629B0:
    ctx->pc = 0x801629B0u;
    // 801629B0: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801629B4:
    ctx->pc = 0x801629B4u;
    // 801629B4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801629B8:
    ctx->pc = 0x801629B8u;
    // 801629B8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801629BC:
    ctx->pc = 0x801629BCu;
    // 801629BC: lwz     r11, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801629C0:
    ctx->pc = 0x801629C0u;
    // 801629C0: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801629C4:
    ctx->pc = 0x801629C4u;
    // 801629C4: bc    12, 2, 0x801629E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801629E4;
        }
    }

label_801629C8:
    ctx->pc = 0x801629C8u;
    ctx->downcount -= 8;
    // 801629C8: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801629CC:
    ctx->pc = 0x801629CCu;
    // 801629CC: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_801629D0:
    ctx->pc = 0x801629D0u;
    // 801629D0: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801629D4:
    ctx->pc = 0x801629D4u;
    // 801629D4: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801629D8:
    ctx->pc = 0x801629D8u;
    // 801629D8: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801629DC:
    ctx->pc = 0x801629DCu;
    // 801629DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801629E0:
    ctx->pc = 0x801629E0u;
    // 801629E0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801629E4u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801629E4:
    ctx->pc = 0x801629E4u;
    ctx->downcount -= 5;
    // 801629E4: lwz     r11, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801629E8:
    ctx->pc = 0x801629E8u;
    // 801629E8: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801629EC:
    ctx->pc = 0x801629ECu;
    // 801629EC: stw     r30, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801629F0:
    ctx->pc = 0x801629F0u;
    // 801629F0: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801629F4:
    ctx->pc = 0x801629F4u;
    // 801629F4: bc    12, 2, 0x80162A14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162A14;
        }
    }

label_801629F8:
    ctx->pc = 0x801629F8u;
    ctx->downcount -= 8;
    // 801629F8: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801629FC:
    ctx->pc = 0x801629FCu;
    // 801629FC: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80162A00:
    ctx->pc = 0x80162A00u;
    // 80162A00: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80162A04:
    ctx->pc = 0x80162A04u;
    // 80162A04: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162A08:
    ctx->pc = 0x80162A08u;
    // 80162A08: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162A0C:
    ctx->pc = 0x80162A0Cu;
    // 80162A0C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162A10:
    ctx->pc = 0x80162A10u;
    // 80162A10: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80162A14u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162A14:
    ctx->pc = 0x80162A14u;
    ctx->downcount -= 4;
    // 80162A14: lwz     r11, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80162A18:
    ctx->pc = 0x80162A18u;
    // 80162A18: stw     r30, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80162A1C:
    ctx->pc = 0x80162A1Cu;
    // 80162A1C: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162A20:
    ctx->pc = 0x80162A20u;
    // 80162A20: bc    12, 2, 0x80162A40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162A40;
        }
    }

label_80162A24:
    ctx->pc = 0x80162A24u;
    ctx->downcount -= 8;
    // 80162A24: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162A28:
    ctx->pc = 0x80162A28u;
    // 80162A28: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80162A2C:
    ctx->pc = 0x80162A2Cu;
    // 80162A2C: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80162A30:
    ctx->pc = 0x80162A30u;
    // 80162A30: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162A34:
    ctx->pc = 0x80162A34u;
    // 80162A34: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162A38:
    ctx->pc = 0x80162A38u;
    // 80162A38: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162A3C:
    ctx->pc = 0x80162A3Cu;
    // 80162A3C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80162A40u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162A40:
    ctx->pc = 0x80162A40u;
    ctx->downcount -= 4;
    // 80162A40: lwz     r11, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80162A44:
    ctx->pc = 0x80162A44u;
    // 80162A44: stw     r30, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80162A48:
    ctx->pc = 0x80162A48u;
    // 80162A48: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162A4C:
    ctx->pc = 0x80162A4Cu;
    // 80162A4C: bc    12, 2, 0x80162A70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162A70;
        }
    }

label_80162A50:
    ctx->pc = 0x80162A50u;
    ctx->downcount -= 9;
    // 80162A50: lwz     r9, 108(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162A54:
    ctx->pc = 0x80162A54u;
    // 80162A54: addi    r0, r11, 88
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(88);

label_80162A58:
    ctx->pc = 0x80162A58u;
    // 80162A58: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80162A5C:
    ctx->pc = 0x80162A5Cu;
    // 80162A5C: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80162A60:
    ctx->pc = 0x80162A60u;
    // 80162A60: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162A64:
    ctx->pc = 0x80162A64u;
    // 80162A64: add   r3, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162A68:
    ctx->pc = 0x80162A68u;
    // 80162A68: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80162A6C:
    ctx->pc = 0x80162A6Cu;
    // 80162A6C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80162A70u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162A70:
    ctx->pc = 0x80162A70u;
    ctx->downcount -= 17;
    // 80162A70: stw     r30, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80162A74:
    ctx->pc = 0x80162A74u;
    // 80162A74: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162A78:
    ctx->pc = 0x80162A78u;
    // 80162A78: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162A7C:
    ctx->pc = 0x80162A7Cu;
    // 80162A7C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80162A80:
    ctx->pc = 0x80162A80u;
    // 80162A80: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80162A84:
    ctx->pc = 0x80162A84u;
    // 80162A84: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162A88:
    ctx->pc = 0x80162A88u;
    ctx->downcount -= 17;
    // 80162A88: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162A8C:
    ctx->pc = 0x80162A8Cu;
    // 80162A8C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162A90:
    ctx->pc = 0x80162A90u;
    // 80162A90: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80162A94:
    ctx->pc = 0x80162A94u;
    // 80162A94: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162A98:
    ctx->pc = 0x80162A98u;
    // 80162A98: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80162A9C:
    ctx->pc = 0x80162A9Cu;
    // 80162A9C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162AA0:
    ctx->pc = 0x80162AA0u;
    // 80162AA0: bl      0x8015B510
    {
            ctx->lr = 0x80162AA4u;
            ctx->pc = 0x8015B510u;
            return;
    }

label_80162AA4:
    ctx->pc = 0x80162AA4u;
    ctx->downcount -= 3;
    // 80162AA4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162AA8:
    ctx->pc = 0x80162AA8u;
    // 80162AA8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80162AAC:
    ctx->pc = 0x80162AACu;
    // 80162AAC: bl      0x80106ED0
    {
            ctx->lr = 0x80162AB0u;
            ctx->pc = 0x80106ED0u;
            return;
    }

label_80162AB0:
    ctx->pc = 0x80162AB0u;
    ctx->downcount -= 4;
    // 80162AB0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162AB4:
    ctx->pc = 0x80162AB4u;
    // 80162AB4: lwz     r0, 140(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(140);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162AB8:
    ctx->pc = 0x80162AB8u;
    // 80162AB8: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162ABC:
    ctx->pc = 0x80162ABCu;
    // 80162ABC: bc    12, 2, 0x80162AF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162AF8;
        }
    }

label_80162AC0:
    ctx->pc = 0x80162AC0u;
    ctx->downcount -= 3;
    // 80162AC0: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80162AC4:
    ctx->pc = 0x80162AC4u;
    // 80162AC4: addi    r3, r3, -25052
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-25052);

label_80162AC8:
    ctx->pc = 0x80162AC8u;
    // 80162AC8: bl      0x800FF4C8
    {
            ctx->lr = 0x80162ACCu;
            ctx->pc = 0x800FF4C8u;
            return;
    }

label_80162ACC:
    ctx->pc = 0x80162ACCu;
    ctx->downcount -= 2;
    // 80162ACC: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162AD0:
    ctx->pc = 0x80162AD0u;
    // 80162AD0: bc    12, 2, 0x80162AF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162AF8;
        }
    }

label_80162AD4:
    ctx->pc = 0x80162AD4u;
    ctx->downcount -= 9;
    // 80162AD4: lwz     r9, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162AD8:
    ctx->pc = 0x80162AD8u;
    // 80162AD8: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80162ADC:
    ctx->pc = 0x80162ADCu;
    // 80162ADC: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_80162AE0:
    ctx->pc = 0x80162AE0u;
    // 80162AE0: lha     r3, 168(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(168);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80162AE4:
    ctx->pc = 0x80162AE4u;
    // 80162AE4: lwz     r0, 172(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(172);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162AE8:
    ctx->pc = 0x80162AE8u;
    // 80162AE8: add   r3, r29, r3
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162AEC:
    ctx->pc = 0x80162AECu;
    // 80162AEC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162AF0:
    ctx->pc = 0x80162AF0u;
    // 80162AF0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80162AF4u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162AF4:
    ctx->pc = 0x80162AF4u;
    ctx->downcount -= 1;
    // 80162AF4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162AF8:
    ctx->pc = 0x80162AF8u;
    ctx->downcount -= 17;
    // 80162AF8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80162AFC:
    ctx->pc = 0x80162AFCu;
    // 80162AFC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162B00:
    ctx->pc = 0x80162B00u;
    // 80162B00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162B04:
    ctx->pc = 0x80162B04u;
    // 80162B04: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80162B08:
    ctx->pc = 0x80162B08u;
    // 80162B08: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80162B0C:
    ctx->pc = 0x80162B0Cu;
    // 80162B0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162B10:
    ctx->pc = 0x80162B10u;
    ctx->downcount -= 20;
    // 80162B10: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162B14:
    ctx->pc = 0x80162B14u;
    // 80162B14: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162B18:
    ctx->pc = 0x80162B18u;
    // 80162B18: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80162B1C:
    ctx->pc = 0x80162B1Cu;
    // 80162B1C: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162B20:
    ctx->pc = 0x80162B20u;
    // 80162B20: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80162B24:
    ctx->pc = 0x80162B24u;
    // 80162B24: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162B28:
    ctx->pc = 0x80162B28u;
    // 80162B28: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80162B2C:
    ctx->pc = 0x80162B2Cu;
    // 80162B2C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80162B30:
    ctx->pc = 0x80162B30u;
    // 80162B30: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80162B34:
    ctx->pc = 0x80162B34u;
    // 80162B34: bl      0x8015E4F4
    {
            ctx->lr = 0x80162B38u;
            ctx->pc = 0x8015E4F4u;
            return;
    }

label_80162B38:
    ctx->pc = 0x80162B38u;
    ctx->downcount -= 6;
    // 80162B38: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80162B3C:
    ctx->pc = 0x80162B3Cu;
    // 80162B3C: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162B40:
    ctx->pc = 0x80162B40u;
    // 80162B40: addi    r29, r9, -25052
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-25052);

label_80162B44:
    ctx->pc = 0x80162B44u;
    // 80162B44: lwz     r0, 3592(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162B48:
    ctx->pc = 0x80162B48u;
    // 80162B48: cmpw    r30, r0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162B4C:
    ctx->pc = 0x80162B4Cu;
    // 80162B4C: bc    4, 2, 0x80162BCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80162BCC;
        }
    }

label_80162B50:
    ctx->pc = 0x80162B50u;
    ctx->downcount -= 2;
    // 80162B50: cmpwi   r28, 6
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162B54:
    ctx->pc = 0x80162B54u;
    // 80162B54: bc    4, 2, 0x80162BCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80162BCC;
        }
    }

label_80162B58:
    ctx->pc = 0x80162B58u;
    ctx->downcount -= 8;
    // 80162B58: lwz     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162B5C:
    ctx->pc = 0x80162B5Cu;
    // 80162B5C: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80162B60:
    ctx->pc = 0x80162B60u;
    // 80162B60: lwz     r0, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162B64:
    ctx->pc = 0x80162B64u;
    // 80162B64: lha     r3, 192(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(192);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80162B68:
    ctx->pc = 0x80162B68u;
    // 80162B68: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162B6C:
    ctx->pc = 0x80162B6Cu;
    // 80162B6C: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162B70:
    ctx->pc = 0x80162B70u;
    // 80162B70: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80162B74u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162B74:
    ctx->pc = 0x80162B74u;
    ctx->downcount -= 6;
    // 80162B74: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80162B78:
    ctx->pc = 0x80162B78u;
    // 80162B78: stw     r0, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162B7C:
    ctx->pc = 0x80162B7Cu;
    // 80162B7C: lwz     r9, 3580(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3580);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162B80:
    ctx->pc = 0x80162B80u;
    // 80162B80: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162B84:
    ctx->pc = 0x80162B84u;
    // 80162B84: li      r0, 29
    ctx->gpr[0] = (u32)(s32)(29);

label_80162B88:
    ctx->pc = 0x80162B88u;
    // 80162B88: bc    4, 2, 0x80162BB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80162BB8;
        }
    }

label_80162B8C:
    ctx->pc = 0x80162B8Cu;
    ctx->downcount -= 3;
    // 80162B8C: lwz     r0, 3584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3584);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162B90:
    ctx->pc = 0x80162B90u;
    // 80162B90: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162B94:
    ctx->pc = 0x80162B94u;
    // 80162B94: bc    12, 2, 0x80162BA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162BA0;
        }
    }

label_80162B98:
    ctx->pc = 0x80162B98u;
    ctx->downcount -= 2;
    // 80162B98: li      r0, 30
    ctx->gpr[0] = (u32)(s32)(30);

label_80162B9C:
    ctx->pc = 0x80162B9Cu;
    // 80162B9C: b       0x80162BB8
    {
            goto label_80162BB8;
    }

label_80162BA0:
    ctx->pc = 0x80162BA0u;
    ctx->downcount -= 2;
    // 80162BA0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80162BA4:
    ctx->pc = 0x80162BA4u;
    // 80162BA4: bl      0x801004BC
    {
            ctx->lr = 0x80162BA8u;
            ctx->pc = 0x801004BCu;
            return;
    }

label_80162BA8:
    ctx->pc = 0x80162BA8u;
    ctx->downcount -= 3;
    // 80162BA8: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162BAC:
    ctx->pc = 0x80162BACu;
    // 80162BAC: li      r0, 11
    ctx->gpr[0] = (u32)(s32)(11);

label_80162BB0:
    ctx->pc = 0x80162BB0u;
    // 80162BB0: bc    12, 2, 0x80162BB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162BB8;
        }
    }

label_80162BB4:
    ctx->pc = 0x80162BB4u;
    ctx->downcount -= 1;
    // 80162BB4: li      r0, 35
    ctx->gpr[0] = (u32)(s32)(35);

label_80162BB8:
    ctx->pc = 0x80162BB8u;
    ctx->downcount -= 5;
    // 80162BB8: stw     r0, 388(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(388);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162BBC:
    ctx->pc = 0x80162BBCu;
    // 80162BBC: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80162BC0:
    ctx->pc = 0x80162BC0u;
    // 80162BC0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80162BC4:
    ctx->pc = 0x80162BC4u;
    // 80162BC4: addi    r3, r3, -21296
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-21296);

label_80162BC8:
    ctx->pc = 0x80162BC8u;
    // 80162BC8: bl      0x80110634
    {
            ctx->lr = 0x80162BCCu;
            ctx->pc = 0x80110634u;
            return;
    }

label_80162BCC:
    ctx->pc = 0x80162BCCu;
    ctx->downcount -= 17;
    // 80162BCC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80162BD0:
    ctx->pc = 0x80162BD0u;
    // 80162BD0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162BD4:
    ctx->pc = 0x80162BD4u;
    // 80162BD4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162BD8:
    ctx->pc = 0x80162BD8u;
    // 80162BD8: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80162BDC:
    ctx->pc = 0x80162BDCu;
    // 80162BDC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80162BE0:
    ctx->pc = 0x80162BE0u;
    // 80162BE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162BE4:
    ctx->pc = 0x80162BE4u;
    ctx->downcount -= 7;
    // 80162BE4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162BE8:
    ctx->pc = 0x80162BE8u;
    // 80162BE8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162BEC:
    ctx->pc = 0x80162BECu;
    // 80162BEC: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80162BF0:
    ctx->pc = 0x80162BF0u;
    // 80162BF0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162BF4:
    ctx->pc = 0x80162BF4u;
    // 80162BF4: lwz     r3, 692(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(692);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80162BF8:
    ctx->pc = 0x80162BF8u;
    // 80162BF8: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_80162BFC:
    ctx->pc = 0x80162BFCu;
    // 80162BFC: bl      0x80143B78
    {
            ctx->lr = 0x80162C00u;
            ctx->pc = 0x80143B78u;
            return;
    }

label_80162C00:
    ctx->pc = 0x80162C00u;
    ctx->downcount -= 2;
    // 80162C00: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162C04:
    ctx->pc = 0x80162C04u;
    // 80162C04: bc    4, 2, 0x80162C0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80162C0C;
        }
    }

label_80162C08:
    ctx->pc = 0x80162C08u;
    ctx->downcount -= 1;
    // 80162C08: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80162C0C:
    ctx->pc = 0x80162C0Cu;
    ctx->downcount -= 7;
    // 80162C0C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80162C10:
    ctx->pc = 0x80162C10u;
    // 80162C10: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162C14:
    ctx->pc = 0x80162C14u;
    // 80162C14: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162C18:
    ctx->pc = 0x80162C18u;
    // 80162C18: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80162C1C:
    ctx->pc = 0x80162C1Cu;
    // 80162C1C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80162C20:
    ctx->pc = 0x80162C20u;
    // 80162C20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162C24:
    ctx->pc = 0x80162C24u;
    ctx->downcount -= 17;
    // 80162C24: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162C28:
    ctx->pc = 0x80162C28u;
    // 80162C28: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162C2C:
    ctx->pc = 0x80162C2Cu;
    // 80162C2C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80162C30:
    ctx->pc = 0x80162C30u;
    // 80162C30: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162C34:
    ctx->pc = 0x80162C34u;
    // 80162C34: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162C38:
    ctx->pc = 0x80162C38u;
    // 80162C38: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80162C3C:
    ctx->pc = 0x80162C3Cu;
    // 80162C3C: bl      0x8015E544
    {
            ctx->lr = 0x80162C40u;
            ctx->pc = 0x8015E544u;
            return;
    }

label_80162C40:
    ctx->pc = 0x80162C40u;
    ctx->downcount -= 9;
    // 80162C40: lwz     r11, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80162C44:
    ctx->pc = 0x80162C44u;
    // 80162C44: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80162C48:
    ctx->pc = 0x80162C48u;
    // 80162C48: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162C4C:
    ctx->pc = 0x80162C4Cu;
    // 80162C4C: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80162C50:
    ctx->pc = 0x80162C50u;
    // 80162C50: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162C54:
    ctx->pc = 0x80162C54u;
    // 80162C54: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162C58:
    ctx->pc = 0x80162C58u;
    // 80162C58: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162C5C:
    ctx->pc = 0x80162C5Cu;
    // 80162C5C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80162C60u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162C60:
    ctx->pc = 0x80162C60u;
    ctx->downcount -= 3;
    // 80162C60: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80162C64:
    ctx->pc = 0x80162C64u;
    // 80162C64: addi    r3, r3, -25052
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-25052);

label_80162C68:
    ctx->pc = 0x80162C68u;
    // 80162C68: bl      0x801004BC
    {
            ctx->lr = 0x80162C6Cu;
            ctx->pc = 0x801004BCu;
            return;
    }

label_80162C6C:
    ctx->pc = 0x80162C6Cu;
    ctx->downcount -= 2;
    // 80162C6C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162C70:
    ctx->pc = 0x80162C70u;
    // 80162C70: bc    4, 2, 0x80162C84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80162C84;
        }
    }

label_80162C74:
    ctx->pc = 0x80162C74u;
    ctx->downcount -= 4;
    // 80162C74: lwz     r9, -27220(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27220);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162C78:
    ctx->pc = 0x80162C78u;
    // 80162C78: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162C7C:
    ctx->pc = 0x80162C7Cu;
    // 80162C7C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162C80:
    ctx->pc = 0x80162C80u;
    // 80162C80: bc    12, 2, 0x80162CA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162CA8;
        }
    }

label_80162C84:
    ctx->pc = 0x80162C84u;
    ctx->downcount -= 9;
    // 80162C84: lwz     r3, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80162C88:
    ctx->pc = 0x80162C88u;
    // 80162C88: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_80162C8C:
    ctx->pc = 0x80162C8Cu;
    // 80162C8C: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162C90:
    ctx->pc = 0x80162C90u;
    // 80162C90: lha     r0, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80162C94:
    ctx->pc = 0x80162C94u;
    // 80162C94: lwz     r9, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162C98:
    ctx->pc = 0x80162C98u;
    // 80162C98: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162C9C:
    ctx->pc = 0x80162C9Cu;
    // 80162C9C: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80162CA0:
    ctx->pc = 0x80162CA0u;
    // 80162CA0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80162CA4u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162CA4:
    ctx->pc = 0x80162CA4u;
    ctx->downcount -= 1;
    // 80162CA4: b       0x80162CC8
    {
            goto label_80162CC8;
    }

label_80162CA8:
    ctx->pc = 0x80162CA8u;
    ctx->downcount -= 9;
    // 80162CA8: lwz     r3, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80162CAC:
    ctx->pc = 0x80162CACu;
    // 80162CAC: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80162CB0:
    ctx->pc = 0x80162CB0u;
    // 80162CB0: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162CB4:
    ctx->pc = 0x80162CB4u;
    // 80162CB4: lha     r0, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80162CB8:
    ctx->pc = 0x80162CB8u;
    // 80162CB8: lwz     r9, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162CBC:
    ctx->pc = 0x80162CBCu;
    // 80162CBC: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80162CC0:
    ctx->pc = 0x80162CC0u;
    // 80162CC0: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80162CC4:
    ctx->pc = 0x80162CC4u;
    // 80162CC4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80162CC8u;
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162CC8:
    ctx->pc = 0x80162CC8u;
    ctx->downcount -= 16;
    // 80162CC8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162CCC:
    ctx->pc = 0x80162CCCu;
    // 80162CCC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162CD0:
    ctx->pc = 0x80162CD0u;
    // 80162CD0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80162CD4:
    ctx->pc = 0x80162CD4u;
    // 80162CD4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80162CD8:
    ctx->pc = 0x80162CD8u;
    // 80162CD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162CDC:
    ctx->pc = 0x80162CDCu;
    ctx->downcount -= 10;
    // 80162CDC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162CE0:
    ctx->pc = 0x80162CE0u;
    // 80162CE0: addi    r4, r4, -1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-1);

label_80162CE4:
    ctx->pc = 0x80162CE4u;
    // 80162CE4: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80162CE8:
    ctx->pc = 0x80162CE8u;
    // 80162CE8: rlwinm r4, r4, 31, 1, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFCu;
    }

label_80162CEC:
    ctx->pc = 0x80162CECu;
    // 80162CEC: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80162CF0:
    ctx->pc = 0x80162CF0u;
    // 80162CF0: lwzx    r0, r4, r9
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162CF4:
    ctx->pc = 0x80162CF4u;
    // 80162CF4: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162CF8:
    ctx->pc = 0x80162CF8u;
    // 80162CF8: stwx    r3, r4, r9
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[9];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80162CFC:
    ctx->pc = 0x80162CFCu;
    // 80162CFC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80162D00:
    ctx->pc = 0x80162D00u;
    // 80162D00: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162D04:
    ctx->pc = 0x80162D04u;
    ctx->downcount -= 7;
    // 80162D04: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162D08:
    ctx->pc = 0x80162D08u;
    // 80162D08: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162D0C:
    ctx->pc = 0x80162D0Cu;
    // 80162D0C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162D10:
    ctx->pc = 0x80162D10u;
    // 80162D10: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80162D14:
    ctx->pc = 0x80162D14u;
    // 80162D14: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80162D18:
    ctx->pc = 0x80162D18u;
    // 80162D18: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_80162D1C:
    ctx->pc = 0x80162D1Cu;
    // 80162D1C: bl      0x801626C8
    {
            ctx->lr = 0x80162D20u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801626C8u;
                return;
            }
            goto label_801626C8;
    }

label_80162D20:
    ctx->pc = 0x80162D20u;
    ctx->downcount -= 5;
    // 80162D20: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162D24:
    ctx->pc = 0x80162D24u;
    // 80162D24: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162D28:
    ctx->pc = 0x80162D28u;
    // 80162D28: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80162D2C:
    ctx->pc = 0x80162D2Cu;
    // 80162D2C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162D30:
    ctx->pc = 0x80162D30u;
    ctx->downcount -= 7;
    // 80162D30: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162D34:
    ctx->pc = 0x80162D34u;
    // 80162D34: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162D38:
    ctx->pc = 0x80162D38u;
    // 80162D38: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162D3C:
    ctx->pc = 0x80162D3Cu;
    // 80162D3C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80162D40:
    ctx->pc = 0x80162D40u;
    // 80162D40: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_80162D44:
    ctx->pc = 0x80162D44u;
    // 80162D44: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162D48:
    ctx->pc = 0x80162D48u;
    // 80162D48: bc    4, 2, 0x80162E08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80162E08;
        }
    }

label_80162D4C:
    ctx->pc = 0x80162D4Cu;
    ctx->downcount -= 2;
    // 80162D4C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162D50:
    ctx->pc = 0x80162D50u;
    // 80162D50: bc    12, 2, 0x80162E08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162E08;
        }
    }

label_80162D54:
    ctx->pc = 0x80162D54u;
    ctx->downcount -= 5;
    // 80162D54: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_80162D58:
    ctx->pc = 0x80162D58u;
    // 80162D58: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_80162D5C:
    ctx->pc = 0x80162D5Cu;
    // 80162D5C: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_80162D60:
    ctx->pc = 0x80162D60u;
    // 80162D60: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_80162D64:
    ctx->pc = 0x80162D64u;
    // 80162D64: bl      0x80252AF0
    {
            ctx->lr = 0x80162D68u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162D68:
    ctx->pc = 0x80162D68u;
    ctx->downcount -= 5;
    // 80162D68: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_80162D6C:
    ctx->pc = 0x80162D6Cu;
    // 80162D6C: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80162D70:
    ctx->pc = 0x80162D70u;
    // 80162D70: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_80162D74:
    ctx->pc = 0x80162D74u;
    // 80162D74: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162D78:
    ctx->pc = 0x80162D78u;
    // 80162D78: bl      0x80252AF0
    {
            ctx->lr = 0x80162D7Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162D7C:
    ctx->pc = 0x80162D7Cu;
    ctx->downcount -= 5;
    // 80162D7C: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_80162D80:
    ctx->pc = 0x80162D80u;
    // 80162D80: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80162D84:
    ctx->pc = 0x80162D84u;
    // 80162D84: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_80162D88:
    ctx->pc = 0x80162D88u;
    // 80162D88: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162D8C:
    ctx->pc = 0x80162D8Cu;
    // 80162D8C: bl      0x80252AF0
    {
            ctx->lr = 0x80162D90u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162D90:
    ctx->pc = 0x80162D90u;
    ctx->downcount -= 5;
    // 80162D90: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_80162D94:
    ctx->pc = 0x80162D94u;
    // 80162D94: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_80162D98:
    ctx->pc = 0x80162D98u;
    // 80162D98: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_80162D9C:
    ctx->pc = 0x80162D9Cu;
    // 80162D9C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162DA0:
    ctx->pc = 0x80162DA0u;
    // 80162DA0: bl      0x80252AF0
    {
            ctx->lr = 0x80162DA4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162DA4:
    ctx->pc = 0x80162DA4u;
    ctx->downcount -= 5;
    // 80162DA4: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_80162DA8:
    ctx->pc = 0x80162DA8u;
    // 80162DA8: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_80162DAC:
    ctx->pc = 0x80162DACu;
    // 80162DAC: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_80162DB0:
    ctx->pc = 0x80162DB0u;
    // 80162DB0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162DB4:
    ctx->pc = 0x80162DB4u;
    // 80162DB4: bl      0x80252AF0
    {
            ctx->lr = 0x80162DB8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162DB8:
    ctx->pc = 0x80162DB8u;
    ctx->downcount -= 5;
    // 80162DB8: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_80162DBC:
    ctx->pc = 0x80162DBCu;
    // 80162DBC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80162DC0:
    ctx->pc = 0x80162DC0u;
    // 80162DC0: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_80162DC4:
    ctx->pc = 0x80162DC4u;
    // 80162DC4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162DC8:
    ctx->pc = 0x80162DC8u;
    // 80162DC8: bl      0x80252AF0
    {
            ctx->lr = 0x80162DCCu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162DCC:
    ctx->pc = 0x80162DCCu;
    ctx->downcount -= 5;
    // 80162DCC: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_80162DD0:
    ctx->pc = 0x80162DD0u;
    // 80162DD0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80162DD4:
    ctx->pc = 0x80162DD4u;
    // 80162DD4: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_80162DD8:
    ctx->pc = 0x80162DD8u;
    // 80162DD8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162DDC:
    ctx->pc = 0x80162DDCu;
    // 80162DDC: bl      0x80252AF0
    {
            ctx->lr = 0x80162DE0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162DE0:
    ctx->pc = 0x80162DE0u;
    ctx->downcount -= 5;
    // 80162DE0: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_80162DE4:
    ctx->pc = 0x80162DE4u;
    // 80162DE4: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_80162DE8:
    ctx->pc = 0x80162DE8u;
    // 80162DE8: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_80162DEC:
    ctx->pc = 0x80162DECu;
    // 80162DEC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80162DF0:
    ctx->pc = 0x80162DF0u;
    // 80162DF0: bl      0x80252AF0
    {
            ctx->lr = 0x80162DF4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80162DF4:
    ctx->pc = 0x80162DF4u;
    ctx->downcount -= 5;
    // 80162DF4: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_80162DF8:
    ctx->pc = 0x80162DF8u;
    // 80162DF8: lis     r4, -32746
    ctx->gpr[4] = ((u32)(s32)(-32746) << 16);

label_80162DFC:
    ctx->pc = 0x80162DFCu;
    // 80162DFC: addi    r3, r3, -25088
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-25088);

label_80162E00:
    ctx->pc = 0x80162E00u;
    // 80162E00: addi    r4, r4, 11808
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(11808);

label_80162E04:
    ctx->pc = 0x80162E04u;
    // 80162E04: bl      0x801FC784
    {
            ctx->lr = 0x80162E08u;
            ctx->pc = 0x801FC784u;
            return;
    }

label_80162E08:
    ctx->pc = 0x80162E08u;
    ctx->downcount -= 5;
    // 80162E08: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162E0C:
    ctx->pc = 0x80162E0Cu;
    // 80162E0C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162E10:
    ctx->pc = 0x80162E10u;
    // 80162E10: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80162E14:
    ctx->pc = 0x80162E14u;
    // 80162E14: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162E18:
    ctx->pc = 0x80162E18u;
    ctx->downcount -= 2;
    // 80162E18: li      r3, 14
    ctx->gpr[3] = (u32)(s32)(14);

label_80162E1C:
    ctx->pc = 0x80162E1Cu;
    // 80162E1C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162E20:
    ctx->pc = 0x80162E20u;
    ctx->downcount -= 17;
    // 80162E20: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162E24:
    ctx->pc = 0x80162E24u;
    // 80162E24: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162E28:
    ctx->pc = 0x80162E28u;
    // 80162E28: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80162E2C:
    ctx->pc = 0x80162E2Cu;
    // 80162E2C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162E30:
    ctx->pc = 0x80162E30u;
    // 80162E30: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162E34:
    ctx->pc = 0x80162E34u;
    // 80162E34: li      r3, 496
    ctx->gpr[3] = (u32)(s32)(496);

label_80162E38:
    ctx->pc = 0x80162E38u;
    // 80162E38: bl      0x80281C60
    {
            ctx->lr = 0x80162E3Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80162E3C:
    ctx->pc = 0x80162E3Cu;
    ctx->downcount -= 2;
    // 80162E3C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80162E40:
    ctx->pc = 0x80162E40u;
    // 80162E40: bl      0x80162E58
    {
            ctx->lr = 0x80162E44u;
            goto label_80162E58;
    }

label_80162E44:
    ctx->pc = 0x80162E44u;
    ctx->downcount -= 16;
    // 80162E44: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162E48:
    ctx->pc = 0x80162E48u;
    // 80162E48: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162E4C:
    ctx->pc = 0x80162E4Cu;
    // 80162E4C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80162E50:
    ctx->pc = 0x80162E50u;
    // 80162E50: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80162E54:
    ctx->pc = 0x80162E54u;
    // 80162E54: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162E58:
    ctx->pc = 0x80162E58u;
    ctx->downcount -= 16;
    // 80162E58: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162E5C:
    ctx->pc = 0x80162E5Cu;
    // 80162E5C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162E60:
    ctx->pc = 0x80162E60u;
    // 80162E60: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80162E64:
    ctx->pc = 0x80162E64u;
    // 80162E64: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162E68:
    ctx->pc = 0x80162E68u;
    // 80162E68: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162E6C:
    ctx->pc = 0x80162E6Cu;
    // 80162E6C: bl      0x800EE0E8
    {
            ctx->lr = 0x80162E70u;
            ctx->pc = 0x800EE0E8u;
            return;
    }

label_80162E70:
    ctx->pc = 0x80162E70u;
    ctx->downcount -= 22;
    // 80162E70: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80162E74:
    ctx->pc = 0x80162E74u;
    // 80162E74: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80162E78:
    ctx->pc = 0x80162E78u;
    // 80162E78: addi    r9, r9, -25328
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-25328);

label_80162E7C:
    ctx->pc = 0x80162E7Cu;
    // 80162E7C: stw     r0, 488(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(488);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162E80:
    ctx->pc = 0x80162E80u;
    // 80162E80: stw     r9, 108(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80162E84:
    ctx->pc = 0x80162E84u;
    // 80162E84: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80162E88:
    ctx->pc = 0x80162E88u;
    // 80162E88: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162E8C:
    ctx->pc = 0x80162E8Cu;
    // 80162E8C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162E90:
    ctx->pc = 0x80162E90u;
    // 80162E90: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80162E94:
    ctx->pc = 0x80162E94u;
    // 80162E94: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80162E98:
    ctx->pc = 0x80162E98u;
    // 80162E98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162E9C:
    ctx->pc = 0x80162E9Cu;
    ctx->downcount -= 8;
    // 80162E9C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162EA0:
    ctx->pc = 0x80162EA0u;
    // 80162EA0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162EA4:
    ctx->pc = 0x80162EA4u;
    // 80162EA4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162EA8:
    ctx->pc = 0x80162EA8u;
    // 80162EA8: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80162EAC:
    ctx->pc = 0x80162EACu;
    // 80162EAC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162EB0:
    ctx->pc = 0x80162EB0u;
    // 80162EB0: addi    r9, r9, -25328
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-25328);

label_80162EB4:
    ctx->pc = 0x80162EB4u;
    // 80162EB4: stw     r9, 108(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80162EB8:
    ctx->pc = 0x80162EB8u;
    // 80162EB8: bl      0x800EE1BC
    {
            ctx->lr = 0x80162EBCu;
            ctx->pc = 0x800EE1BCu;
            return;
    }

label_80162EBC:
    ctx->pc = 0x80162EBCu;
    ctx->downcount -= 5;
    // 80162EBC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162EC0:
    ctx->pc = 0x80162EC0u;
    // 80162EC0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162EC4:
    ctx->pc = 0x80162EC4u;
    // 80162EC4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80162EC8:
    ctx->pc = 0x80162EC8u;
    // 80162EC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162ECC:
    ctx->pc = 0x80162ECCu;
    ctx->downcount -= 4;
    // 80162ECC: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80162ED0:
    ctx->pc = 0x80162ED0u;
    // 80162ED0: lfs     f0, -25080(r9)
    if (!ppc_fp_available_inline(ctx, 0x80162ED0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-25080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80162ED4:
    ctx->pc = 0x80162ED4u;
    // 80162ED4: fcmpu   cr0, f4, f0
    if (!ppc_fp_available_inline(ctx, 0x80162ED4u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[4], ctx->fpr[0], false);

label_80162ED8:
    ctx->pc = 0x80162ED8u;
    // 80162ED8: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162EDC:
    ctx->pc = 0x80162EDCu;
    ctx->downcount -= 3;
    // 80162EDC: lwz     r0, 488(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(488);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162EE0:
    ctx->pc = 0x80162EE0u;
    // 80162EE0: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162EE4:
    ctx->pc = 0x80162EE4u;
    // 80162EE4: bclr  4, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162EE8:
    ctx->pc = 0x80162EE8u;
    ctx->downcount -= 6;
    // 80162EE8: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162EEC:
    ctx->pc = 0x80162EECu;
    // 80162EEC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80162EF0:
    ctx->pc = 0x80162EF0u;
    // 80162EF0: stw     r0, 488(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(488);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162EF4:
    ctx->pc = 0x80162EF4u;
    // 80162EF4: lwz     r9, 56(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(56);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80162EF8:
    ctx->pc = 0x80162EF8u;
    // 80162EF8: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162EFC:
    ctx->pc = 0x80162EFCu;
    // 80162EFC: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162F00:
    ctx->pc = 0x80162F00u;
    ctx->downcount -= 2;
    // 80162F00: stw     r0, 720(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(720);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162F04:
    ctx->pc = 0x80162F04u;
    // 80162F04: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162F08:
    ctx->pc = 0x80162F08u;
    ctx->downcount -= 7;
    // 80162F08: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162F0C:
    ctx->pc = 0x80162F0Cu;
    // 80162F0C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162F10:
    ctx->pc = 0x80162F10u;
    // 80162F10: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162F14:
    ctx->pc = 0x80162F14u;
    // 80162F14: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80162F18:
    ctx->pc = 0x80162F18u;
    // 80162F18: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80162F1C:
    ctx->pc = 0x80162F1Cu;
    // 80162F1C: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_80162F20:
    ctx->pc = 0x80162F20u;
    // 80162F20: bl      0x80162D30
    {
            ctx->lr = 0x80162F24u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80162D30u;
                return;
            }
            goto label_80162D30;
    }

label_80162F24:
    ctx->pc = 0x80162F24u;
    ctx->downcount -= 5;
    // 80162F24: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162F28:
    ctx->pc = 0x80162F28u;
    // 80162F28: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80162F2C:
    ctx->pc = 0x80162F2Cu;
    // 80162F2C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80162F30:
    ctx->pc = 0x80162F30u;
    // 80162F30: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_80162F34:
    ctx->pc = 0x80162F34u;
    ctx->downcount -= 26;
    // 80162F34: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80162F38:
    ctx->pc = 0x80162F38u;
    // 80162F38: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80162F3C:
    ctx->pc = 0x80162F3Cu;
    // 80162F3C: stmw     r25, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80162F40:
    ctx->pc = 0x80162F40u;
    // 80162F40: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80162F44:
    ctx->pc = 0x80162F44u;
    // 80162F44: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80162F48:
    ctx->pc = 0x80162F48u;
    // 80162F48: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80162F4C:
    ctx->pc = 0x80162F4Cu;
    // 80162F4C: addi    r9, r9, -24960
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-24960);

label_80162F50:
    ctx->pc = 0x80162F50u;
    // 80162F50: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80162F54:
    ctx->pc = 0x80162F54u;
    // 80162F54: stw     r9, 56(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80162F58:
    ctx->pc = 0x80162F58u;
    // 80162F58: addi    r29, r26, 20
    ctx->gpr[29] = ctx->gpr[26] + (u32)(s32)(20);

label_80162F5C:
    ctx->pc = 0x80162F5Cu;
    // 80162F5C: addi    r9, r26, 12
    ctx->gpr[9] = ctx->gpr[26] + (u32)(s32)(12);

label_80162F60:
    ctx->pc = 0x80162F60u;
    // 80162F60: stw     r30, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80162F64:
    ctx->pc = 0x80162F64u;
    // 80162F64: stw     r30, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80162F68:
    ctx->pc = 0x80162F68u;
    // 80162F68: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80162F6C:
    ctx->pc = 0x80162F6Cu;
    // 80162F6C: stw     r30, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80162F70:
    ctx->pc = 0x80162F70u;
    // 80162F70: bl      0x80077708
    {
            ctx->lr = 0x80162F74u;
            ctx->pc = 0x80077708u;
            return;
    }

label_80162F74:
    ctx->pc = 0x80162F74u;
    ctx->downcount -= 2;
    // 80162F74: addi    r3, r26, 36
    ctx->gpr[3] = ctx->gpr[26] + (u32)(s32)(36);

label_80162F78:
    ctx->pc = 0x80162F78u;
    // 80162F78: bl      0x80077708
    {
            ctx->lr = 0x80162F7Cu;
            ctx->pc = 0x80077708u;
            return;
    }

label_80162F7C:
    ctx->pc = 0x80162F7Cu;
    ctx->downcount -= 2;
    // 80162F7C: stw     r30, 52(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80162F80:
    ctx->pc = 0x80162F80u;
    // 80162F80: bl      0x8021C94C
    {
            ctx->lr = 0x80162F84u;
            ctx->pc = 0x8021C94Cu;
            return;
    }

label_80162F84:
    ctx->pc = 0x80162F84u;
    ctx->downcount -= 4;
    // 80162F84: stw     r30, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80162F88:
    ctx->pc = 0x80162F88u;
    // 80162F88: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80162F8C:
    ctx->pc = 0x80162F8Cu;
    // 80162F8C: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_80162F90:
    ctx->pc = 0x80162F90u;
    // 80162F90: bl      0x80163CB8
    {
            ctx->lr = 0x80162F94u;
            ctx->pc = 0x80163CB8u;
            return;
    }

label_80162F94:
    ctx->pc = 0x80162F94u;
    ctx->downcount -= 4;
    // 80162F94: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80162F98:
    ctx->pc = 0x80162F98u;
    // 80162F98: addi    r31, r9, -25060
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-25060);

label_80162F9C:
    ctx->pc = 0x80162F9Cu;
    // 80162F9C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80162FA0:
    ctx->pc = 0x80162FA0u;
    // 80162FA0: bl      0x80298908
    {
            ctx->lr = 0x80162FA4u;
            ctx->pc = 0x80298908u;
            return;
    }

label_80162FA4:
    ctx->pc = 0x80162FA4u;
    ctx->downcount -= 7;
    // 80162FA4: add   r27, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[27] = res;
    }

label_80162FA8:
    ctx->pc = 0x80162FA8u;
    // 80162FA8: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162FAC:
    ctx->pc = 0x80162FACu;
    // 80162FAC: lwz     r3, 20(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80162FB0:
    ctx->pc = 0x80162FB0u;
    // 80162FB0: subf   r30, r31, r27
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_80162FB4:
    ctx->pc = 0x80162FB4u;
    // 80162FB4: subf   r5, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_80162FB8:
    ctx->pc = 0x80162FB8u;
    // 80162FB8: cmplw   r30, r5
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162FBC:
    ctx->pc = 0x80162FBCu;
    // 80162FBC: bc    12, 1, 0x8016300C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016300C;
        }
    }

label_80162FC0:
    ctx->pc = 0x80162FC0u;
    ctx->downcount -= 2;
    // 80162FC0: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162FC4:
    ctx->pc = 0x80162FC4u;
    // 80162FC4: bc    12, 2, 0x80162FD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80162FD8;
        }
    }

label_80162FC8:
    ctx->pc = 0x80162FC8u;
    ctx->downcount -= 4;
    // 80162FC8: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80162FCC:
    ctx->pc = 0x80162FCCu;
    // 80162FCC: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80162FD0:
    ctx->pc = 0x80162FD0u;
    // 80162FD0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80162FD4:
    ctx->pc = 0x80162FD4u;
    // 80162FD4: bl      0x80297D98
    {
            ctx->lr = 0x80162FD8u;
            ctx->pc = 0x80297D98u;
            return;
    }

label_80162FD8:
    ctx->pc = 0x80162FD8u;
    ctx->downcount -= 5;
    // 80162FD8: lwz     r0, 20(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80162FDC:
    ctx->pc = 0x80162FDCu;
    // 80162FDC: lwz     r31, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80162FE0:
    ctx->pc = 0x80162FE0u;
    // 80162FE0: add   r30, r0, r30
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_80162FE4:
    ctx->pc = 0x80162FE4u;
    // 80162FE4: cmpw    r30, r31
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80162FE8:
    ctx->pc = 0x80162FE8u;
    // 80162FE8: bc    12, 2, 0x801631A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801631A4;
        }
    }

label_80162FEC:
    ctx->pc = 0x80162FECu;
    ctx->downcount -= 4;
    // 80162FEC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80162FF0:
    ctx->pc = 0x80162FF0u;
    // 80162FF0: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80162FF4:
    ctx->pc = 0x80162FF4u;
    // 80162FF4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80162FF8:
    ctx->pc = 0x80162FF8u;
    // 80162FF8: bl      0x80297E3C
    {
            ctx->lr = 0x80162FFCu;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80162FFC:
    ctx->pc = 0x80162FFCu;
    ctx->downcount -= 4;
    // 80162FFC: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80163000:
    ctx->pc = 0x80163000u;
    // 80163000: subf   r9, r30, r31
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_80163004:
    ctx->pc = 0x80163004u;
    // 80163004: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80163008:
    ctx->pc = 0x80163008u;
    // 80163008: b       0x801631A0
    {
            goto label_801631A0;
    }

label_8016300C:
    ctx->pc = 0x8016300Cu;
    ctx->downcount -= 2;
    // 8016300C: cmpwi   r5, 0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163010:
    ctx->pc = 0x80163010u;
    // 80163010: bc    12, 2, 0x80163020
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163020;
        }
    }

label_80163014:
    ctx->pc = 0x80163014u;
    ctx->downcount -= 3;
    // 80163014: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80163018:
    ctx->pc = 0x80163018u;
    // 80163018: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8016301C:
    ctx->pc = 0x8016301Cu;
    // 8016301C: bl      0x80297D98
    {
            ctx->lr = 0x80163020u;
            ctx->pc = 0x80297D98u;
            return;
    }

label_80163020:
    ctx->pc = 0x80163020u;
    ctx->downcount -= 6;
    // 80163020: lwz     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80163024:
    ctx->pc = 0x80163024u;
    // 80163024: lwz     r0, 20(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80163028:
    ctx->pc = 0x80163028u;
    // 80163028: subf   r9, r0, r9
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_8016302C:
    ctx->pc = 0x8016302Cu;
    // 8016302C: add   r28, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[28] = res;
    }

label_80163030:
    ctx->pc = 0x80163030u;
    // 80163030: cmpw    r28, r27
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163034:
    ctx->pc = 0x80163034u;
    // 80163034: bc    12, 2, 0x801631A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801631A4;
        }
    }

label_80163038:
    ctx->pc = 0x80163038u;
    ctx->downcount -= 5;
    // 80163038: subf   r31, r28, r27
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[31] = res;
    }

label_8016303C:
    ctx->pc = 0x8016303Cu;
    // 8016303C: li      r0, -2
    ctx->gpr[0] = (u32)(s32)(-2);

label_80163040:
    ctx->pc = 0x80163040u;
    // 80163040: cmplw   r31, r0
    {
        u32 val_a = (u32)(ctx->gpr[31]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163044:
    ctx->pc = 0x80163044u;
    // 80163044: stw     r9, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80163048:
    ctx->pc = 0x80163048u;
    // 80163048: bc    12, 1, 0x80163058
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163058;
        }
    }

label_8016304C:
    ctx->pc = 0x8016304Cu;
    ctx->downcount -= 3;
    // 8016304C: subfic  r0, r31, -2
    {
        u64 res = (u64)(u32)(s32)(-2) + (u64)(~ctx->gpr[31]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80163050:
    ctx->pc = 0x80163050u;
    // 80163050: cmplw   r9, r0
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163054:
    ctx->pc = 0x80163054u;
    // 80163054: bc    4, 1, 0x80163060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80163060;
        }
    }

label_80163058:
    ctx->pc = 0x80163058u;
    ctx->downcount -= 2;
    // 80163058: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8016305C:
    ctx->pc = 0x8016305Cu;
    // 8016305C: bl      0x80077768
    {
            ctx->lr = 0x80163060u;
            ctx->pc = 0x80077768u;
            return;
    }

label_80163060:
    ctx->pc = 0x80163060u;
    ctx->downcount -= 8;
    // 80163060: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80163064:
    ctx->pc = 0x80163064u;
    // 80163064: lwz     r9, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80163068:
    ctx->pc = 0x80163068u;
    // 80163068: lwz     r11, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8016306C:
    ctx->pc = 0x8016306Cu;
    // 8016306C: subf   r9, r0, r9
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_80163070:
    ctx->pc = 0x80163070u;
    // 80163070: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80163074:
    ctx->pc = 0x80163074u;
    // 80163074: add   r0, r11, r31
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80163078:
    ctx->pc = 0x80163078u;
    // 80163078: cmplw   r0, r9
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016307C:
    ctx->pc = 0x8016307Cu;
    // 8016307C: bc    4, 1, 0x80163164
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80163164;
        }
    }

label_80163080:
    ctx->pc = 0x80163080u;
    ctx->downcount -= 4;
    // 80163080: cmplw   r11, r31
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163084:
    ctx->pc = 0x80163084u;
    // 80163084: stw     r31, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80163088:
    ctx->pc = 0x80163088u;
    // 80163088: addi    r9, r1, 24
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(24);

label_8016308C:
    ctx->pc = 0x8016308Cu;
    // 8016308C: bc    4, 0, 0x80163094
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80163094;
        }
    }

label_80163090:
    ctx->pc = 0x80163090u;
    ctx->downcount -= 1;
    // 80163090: addi    r9, r1, 16
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(16);

label_80163094:
    ctx->pc = 0x80163094u;
    ctx->downcount -= 4;
    // 80163094: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80163098:
    ctx->pc = 0x80163098u;
    // 80163098: add   r0, r11, r0
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8016309C:
    ctx->pc = 0x8016309Cu;
    // 8016309C: addic.  r25, r0, 1
    {
        u64 a = ctx->gpr[0];
        u64 b = (u32)(s32)(1);
        u64 res = a + b;
        ctx->gpr[25] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[25];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801630A0:
    ctx->pc = 0x801630A0u;
    // 801630A0: bc    12, 2, 0x801630CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801630CC;
        }
    }

label_801630A4:
    ctx->pc = 0x801630A4u;
    ctx->downcount -= 2;
    // 801630A4: cmplwi  r25, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[25]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801630A8:
    ctx->pc = 0x801630A8u;
    // 801630A8: bc    4, 1, 0x801630BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801630BC;
        }
    }

label_801630AC:
    ctx->pc = 0x801630ACu;
    ctx->downcount -= 2;
    // 801630AC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801630B0:
    ctx->pc = 0x801630B0u;
    // 801630B0: bl      0x80281C60
    {
            ctx->lr = 0x801630B4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801630B4:
    ctx->pc = 0x801630B4u;
    ctx->downcount -= 2;
    // 801630B4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801630B8:
    ctx->pc = 0x801630B8u;
    // 801630B8: b       0x801630D0
    {
            goto label_801630D0;
    }

label_801630BC:
    ctx->pc = 0x801630BCu;
    ctx->downcount -= 2;
    // 801630BC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801630C0:
    ctx->pc = 0x801630C0u;
    // 801630C0: bl      0x80004024
    {
            ctx->lr = 0x801630C4u;
            ctx->pc = 0x80004024u;
            return;
    }

label_801630C4:
    ctx->pc = 0x801630C4u;
    ctx->downcount -= 2;
    // 801630C4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801630C8:
    ctx->pc = 0x801630C8u;
    // 801630C8: b       0x801630D0
    {
            goto label_801630D0;
    }

label_801630CC:
    ctx->pc = 0x801630CCu;
    ctx->downcount -= 1;
    // 801630CC: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_801630D0:
    ctx->pc = 0x801630D0u;
    ctx->downcount -= 4;
    // 801630D0: lwz     r4, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801630D4:
    ctx->pc = 0x801630D4u;
    // 801630D4: lwz     r30, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801630D8:
    ctx->pc = 0x801630D8u;
    // 801630D8: cmpw    r30, r4
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801630DC:
    ctx->pc = 0x801630DCu;
    // 801630DC: bc    12, 2, 0x801630F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801630F8;
        }
    }

label_801630E0:
    ctx->pc = 0x801630E0u;
    ctx->downcount -= 4;
    // 801630E0: subf   r30, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_801630E4:
    ctx->pc = 0x801630E4u;
    // 801630E4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801630E8:
    ctx->pc = 0x801630E8u;
    // 801630E8: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801630EC:
    ctx->pc = 0x801630ECu;
    // 801630EC: bl      0x80297E3C
    {
            ctx->lr = 0x801630F0u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_801630F0:
    ctx->pc = 0x801630F0u;
    ctx->downcount -= 2;
    // 801630F0: add   r3, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801630F4:
    ctx->pc = 0x801630F4u;
    // 801630F4: b       0x801630FC
    {
            goto label_801630FC;
    }

label_801630F8:
    ctx->pc = 0x801630F8u;
    ctx->downcount -= 1;
    // 801630F8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801630FC:
    ctx->pc = 0x801630FCu;
    ctx->downcount -= 2;
    // 801630FC: cmpw    r27, r28
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(ctx->gpr[28]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163100:
    ctx->pc = 0x80163100u;
    // 80163100: bc    12, 2, 0x8016311C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016311C;
        }
    }

label_80163104:
    ctx->pc = 0x80163104u;
    ctx->downcount -= 4;
    // 80163104: subf   r30, r28, r27
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_80163108:
    ctx->pc = 0x80163108u;
    // 80163108: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8016310C:
    ctx->pc = 0x8016310Cu;
    // 8016310C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80163110:
    ctx->pc = 0x80163110u;
    // 80163110: bl      0x80297E3C
    {
            ctx->lr = 0x80163114u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80163114:
    ctx->pc = 0x80163114u;
    ctx->downcount -= 2;
    // 80163114: add   r30, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_80163118:
    ctx->pc = 0x80163118u;
    // 80163118: b       0x80163120
    {
            goto label_80163120;
    }

label_8016311C:
    ctx->pc = 0x8016311Cu;
    ctx->downcount -= 1;
    // 8016311C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80163120:
    ctx->pc = 0x80163120u;
    ctx->downcount -= 7;
    // 80163120: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80163124:
    ctx->pc = 0x80163124u;
    // 80163124: stb     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80163128:
    ctx->pc = 0x80163128u;
    // 80163128: lwz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8016312C:
    ctx->pc = 0x8016312Cu;
    // 8016312C: lwz     r0, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80163130:
    ctx->pc = 0x80163130u;
    // 80163130: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163134:
    ctx->pc = 0x80163134u;
    // 80163134: subf   r4, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_80163138:
    ctx->pc = 0x80163138u;
    // 80163138: bc    12, 2, 0x80163150
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163150;
        }
    }

label_8016313C:
    ctx->pc = 0x8016313Cu;
    ctx->downcount -= 2;
    // 8016313C: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163140:
    ctx->pc = 0x80163140u;
    // 80163140: bc    4, 1, 0x8016314C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8016314C;
        }
    }

label_80163144:
    ctx->pc = 0x80163144u;
    ctx->downcount -= 1;
    // 80163144: bl      0x80281D80
    {
            ctx->lr = 0x80163148u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80163148:
    ctx->pc = 0x80163148u;
    ctx->downcount -= 1;
    // 80163148: b       0x80163150
    {
            goto label_80163150;
    }

label_8016314C:
    ctx->pc = 0x8016314Cu;
    ctx->downcount -= 1;
    // 8016314C: bl      0x8001D934
    {
            ctx->lr = 0x80163150u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80163150:
    ctx->pc = 0x80163150u;
    ctx->downcount -= 5;
    // 80163150: add   r0, r31, r25
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[25];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80163154:
    ctx->pc = 0x80163154u;
    // 80163154: stw     r30, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80163158:
    ctx->pc = 0x80163158u;
    // 80163158: stw     r0, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016315C:
    ctx->pc = 0x8016315Cu;
    // 8016315C: stw     r31, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80163160:
    ctx->pc = 0x80163160u;
    // 80163160: b       0x801631A4
    {
            goto label_801631A4;
    }

label_80163164:
    ctx->pc = 0x80163164u;
    ctx->downcount -= 5;
    // 80163164: lwz     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80163168:
    ctx->pc = 0x80163168u;
    // 80163168: addi    r4, r28, 1
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(1);

label_8016316C:
    ctx->pc = 0x8016316Cu;
    // 8016316C: cmpw    r27, r4
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163170:
    ctx->pc = 0x80163170u;
    // 80163170: addi    r3, r9, 1
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(1);

label_80163174:
    ctx->pc = 0x80163174u;
    // 80163174: bc    12, 2, 0x80163180
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163180;
        }
    }

label_80163178:
    ctx->pc = 0x80163178u;
    ctx->downcount -= 2;
    // 80163178: subf   r5, r4, r27
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8016317C:
    ctx->pc = 0x8016317Cu;
    // 8016317C: bl      0x80297E3C
    {
            ctx->lr = 0x80163180u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80163180:
    ctx->pc = 0x80163180u;
    ctx->downcount -= 8;
    // 80163180: lwz     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80163184:
    ctx->pc = 0x80163184u;
    // 80163184: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80163188:
    ctx->pc = 0x80163188u;
    // 80163188: stbx    r0, r9, r31
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[31];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8016318C:
    ctx->pc = 0x8016318Cu;
    // 8016318C: lbz     r11, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_80163190:
    ctx->pc = 0x80163190u;
    // 80163190: lwz     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80163194:
    ctx->pc = 0x80163194u;
    // 80163194: stb     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[11]);
    }

label_80163198:
    ctx->pc = 0x80163198u;
    // 80163198: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016319C:
    ctx->pc = 0x8016319Cu;
    // 8016319C: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801631A0:
    ctx->pc = 0x801631A0u;
    ctx->downcount -= 1;
    // 801631A0: stw     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801631A4:
    ctx->pc = 0x801631A4u;
    ctx->downcount -= 4;
    // 801631A4: addi    r29, r26, 36
    ctx->gpr[29] = ctx->gpr[26] + (u32)(s32)(36);

label_801631A8:
    ctx->pc = 0x801631A8u;
    // 801631A8: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_801631AC:
    ctx->pc = 0x801631ACu;
    // 801631AC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801631B0:
    ctx->pc = 0x801631B0u;
    // 801631B0: bl      0x80163CB8
    {
            ctx->lr = 0x801631B4u;
            ctx->pc = 0x80163CB8u;
            return;
    }

label_801631B4:
    ctx->pc = 0x801631B4u;
    ctx->downcount -= 4;
    // 801631B4: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801631B8:
    ctx->pc = 0x801631B8u;
    // 801631B8: addi    r31, r9, -25060
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-25060);

label_801631BC:
    ctx->pc = 0x801631BCu;
    // 801631BC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801631C0:
    ctx->pc = 0x801631C0u;
    // 801631C0: bl      0x80298908
    {
            ctx->lr = 0x801631C4u;
            ctx->pc = 0x80298908u;
            return;
    }

label_801631C4:
    ctx->pc = 0x801631C4u;
    ctx->downcount -= 7;
    // 801631C4: add   r27, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[27] = res;
    }

label_801631C8:
    ctx->pc = 0x801631C8u;
    // 801631C8: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801631CC:
    ctx->pc = 0x801631CCu;
    // 801631CC: lwz     r3, 36(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(36);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801631D0:
    ctx->pc = 0x801631D0u;
    // 801631D0: subf   r30, r31, r27
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_801631D4:
    ctx->pc = 0x801631D4u;
    // 801631D4: subf   r5, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_801631D8:
    ctx->pc = 0x801631D8u;
    // 801631D8: cmplw   r30, r5
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801631DC:
    ctx->pc = 0x801631DCu;
    // 801631DC: bc    12, 1, 0x8016322C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016322C;
        }
    }

label_801631E0:
    ctx->pc = 0x801631E0u;
    ctx->downcount -= 2;
    // 801631E0: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801631E4:
    ctx->pc = 0x801631E4u;
    // 801631E4: bc    12, 2, 0x801631F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801631F8;
        }
    }

label_801631E8:
    ctx->pc = 0x801631E8u;
    ctx->downcount -= 4;
    // 801631E8: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801631EC:
    ctx->pc = 0x801631ECu;
    // 801631EC: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801631F0:
    ctx->pc = 0x801631F0u;
    // 801631F0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801631F4:
    ctx->pc = 0x801631F4u;
    // 801631F4: bl      0x80297D98
    {
            ctx->lr = 0x801631F8u;
            ctx->pc = 0x80297D98u;
            return;
    }

label_801631F8:
    ctx->pc = 0x801631F8u;
    ctx->downcount -= 5;
    // 801631F8: lwz     r0, 36(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801631FC:
    ctx->pc = 0x801631FCu;
    // 801631FC: lwz     r31, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80163200:
    ctx->pc = 0x80163200u;
    // 80163200: add   r30, r0, r30
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_80163204:
    ctx->pc = 0x80163204u;
    // 80163204: cmpw    r30, r31
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163208:
    ctx->pc = 0x80163208u;
    // 80163208: bc    12, 2, 0x801633C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801633C4;
        }
    }

label_8016320C:
    ctx->pc = 0x8016320Cu;
    ctx->downcount -= 4;
    // 8016320C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80163210:
    ctx->pc = 0x80163210u;
    // 80163210: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80163214:
    ctx->pc = 0x80163214u;
    // 80163214: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80163218:
    ctx->pc = 0x80163218u;
    // 80163218: bl      0x80297E3C
    {
            ctx->lr = 0x8016321Cu;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8016321C:
    ctx->pc = 0x8016321Cu;
    ctx->downcount -= 4;
    // 8016321C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80163220:
    ctx->pc = 0x80163220u;
    // 80163220: subf   r9, r30, r31
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_80163224:
    ctx->pc = 0x80163224u;
    // 80163224: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80163228:
    ctx->pc = 0x80163228u;
    // 80163228: b       0x801633C0
    {
            goto label_801633C0;
    }

label_8016322C:
    ctx->pc = 0x8016322Cu;
    ctx->downcount -= 2;
    // 8016322C: cmpwi   r5, 0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163230:
    ctx->pc = 0x80163230u;
    // 80163230: bc    12, 2, 0x80163240
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163240;
        }
    }

label_80163234:
    ctx->pc = 0x80163234u;
    ctx->downcount -= 3;
    // 80163234: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80163238:
    ctx->pc = 0x80163238u;
    // 80163238: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8016323C:
    ctx->pc = 0x8016323Cu;
    // 8016323C: bl      0x80297D98
    {
            ctx->lr = 0x80163240u;
            ctx->pc = 0x80297D98u;
            return;
    }

label_80163240:
    ctx->pc = 0x80163240u;
    ctx->downcount -= 6;
    // 80163240: lwz     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80163244:
    ctx->pc = 0x80163244u;
    // 80163244: lwz     r0, 36(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80163248:
    ctx->pc = 0x80163248u;
    // 80163248: subf   r9, r0, r9
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_8016324C:
    ctx->pc = 0x8016324Cu;
    // 8016324C: add   r28, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[28] = res;
    }

label_80163250:
    ctx->pc = 0x80163250u;
    // 80163250: cmpw    r28, r27
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163254:
    ctx->pc = 0x80163254u;
    // 80163254: bc    12, 2, 0x801633C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801633C4;
        }
    }

label_80163258:
    ctx->pc = 0x80163258u;
    ctx->downcount -= 5;
    // 80163258: subf   r31, r28, r27
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[31] = res;
    }

label_8016325C:
    ctx->pc = 0x8016325Cu;
    // 8016325C: li      r0, -2
    ctx->gpr[0] = (u32)(s32)(-2);

label_80163260:
    ctx->pc = 0x80163260u;
    // 80163260: cmplw   r31, r0
    {
        u32 val_a = (u32)(ctx->gpr[31]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163264:
    ctx->pc = 0x80163264u;
    // 80163264: stw     r9, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80163268:
    ctx->pc = 0x80163268u;
    // 80163268: bc    12, 1, 0x80163278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163278;
        }
    }

label_8016326C:
    ctx->pc = 0x8016326Cu;
    ctx->downcount -= 3;
    // 8016326C: subfic  r0, r31, -2
    {
        u64 res = (u64)(u32)(s32)(-2) + (u64)(~ctx->gpr[31]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80163270:
    ctx->pc = 0x80163270u;
    // 80163270: cmplw   r9, r0
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163274:
    ctx->pc = 0x80163274u;
    // 80163274: bc    4, 1, 0x80163280
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80163280;
        }
    }

label_80163278:
    ctx->pc = 0x80163278u;
    ctx->downcount -= 2;
    // 80163278: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8016327C:
    ctx->pc = 0x8016327Cu;
    // 8016327C: bl      0x80077768
    {
            ctx->lr = 0x80163280u;
            ctx->pc = 0x80077768u;
            return;
    }

label_80163280:
    ctx->pc = 0x80163280u;
    ctx->downcount -= 8;
    // 80163280: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80163284:
    ctx->pc = 0x80163284u;
    // 80163284: lwz     r9, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80163288:
    ctx->pc = 0x80163288u;
    // 80163288: lwz     r11, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8016328C:
    ctx->pc = 0x8016328Cu;
    // 8016328C: subf   r9, r0, r9
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_80163290:
    ctx->pc = 0x80163290u;
    // 80163290: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80163294:
    ctx->pc = 0x80163294u;
    // 80163294: add   r0, r11, r31
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80163298:
    ctx->pc = 0x80163298u;
    // 80163298: cmplw   r0, r9
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016329C:
    ctx->pc = 0x8016329Cu;
    // 8016329C: bc    4, 1, 0x80163384
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80163384;
        }
    }

label_801632A0:
    ctx->pc = 0x801632A0u;
    ctx->downcount -= 4;
    // 801632A0: cmplw   r11, r31
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801632A4:
    ctx->pc = 0x801632A4u;
    // 801632A4: stw     r31, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801632A8:
    ctx->pc = 0x801632A8u;
    // 801632A8: addi    r9, r1, 28
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(28);

label_801632AC:
    ctx->pc = 0x801632ACu;
    // 801632AC: bc    4, 0, 0x801632B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801632B4;
        }
    }

label_801632B0:
    ctx->pc = 0x801632B0u;
    ctx->downcount -= 1;
    // 801632B0: addi    r9, r1, 16
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(16);

label_801632B4:
    ctx->pc = 0x801632B4u;
    ctx->downcount -= 4;
    // 801632B4: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801632B8:
    ctx->pc = 0x801632B8u;
    // 801632B8: add   r0, r11, r0
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801632BC:
    ctx->pc = 0x801632BCu;
    // 801632BC: addic.  r25, r0, 1
    {
        u64 a = ctx->gpr[0];
        u64 b = (u32)(s32)(1);
        u64 res = a + b;
        ctx->gpr[25] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[25];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801632C0:
    ctx->pc = 0x801632C0u;
    // 801632C0: bc    12, 2, 0x801632EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801632EC;
        }
    }

label_801632C4:
    ctx->pc = 0x801632C4u;
    ctx->downcount -= 2;
    // 801632C4: cmplwi  r25, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[25]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801632C8:
    ctx->pc = 0x801632C8u;
    // 801632C8: bc    4, 1, 0x801632DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801632DC;
        }
    }

label_801632CC:
    ctx->pc = 0x801632CCu;
    ctx->downcount -= 2;
    // 801632CC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801632D0:
    ctx->pc = 0x801632D0u;
    // 801632D0: bl      0x80281C60
    {
            ctx->lr = 0x801632D4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801632D4:
    ctx->pc = 0x801632D4u;
    ctx->downcount -= 2;
    // 801632D4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801632D8:
    ctx->pc = 0x801632D8u;
    // 801632D8: b       0x801632F0
    {
            goto label_801632F0;
    }

label_801632DC:
    ctx->pc = 0x801632DCu;
    ctx->downcount -= 2;
    // 801632DC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801632E0:
    ctx->pc = 0x801632E0u;
    // 801632E0: bl      0x80004024
    {
            ctx->lr = 0x801632E4u;
            ctx->pc = 0x80004024u;
            return;
    }

label_801632E4:
    ctx->pc = 0x801632E4u;
    ctx->downcount -= 2;
    // 801632E4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801632E8:
    ctx->pc = 0x801632E8u;
    // 801632E8: b       0x801632F0
    {
            goto label_801632F0;
    }

label_801632EC:
    ctx->pc = 0x801632ECu;
    ctx->downcount -= 1;
    // 801632EC: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_801632F0:
    ctx->pc = 0x801632F0u;
    ctx->downcount -= 4;
    // 801632F0: lwz     r4, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801632F4:
    ctx->pc = 0x801632F4u;
    // 801632F4: lwz     r30, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801632F8:
    ctx->pc = 0x801632F8u;
    // 801632F8: cmpw    r30, r4
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801632FC:
    ctx->pc = 0x801632FCu;
    // 801632FC: bc    12, 2, 0x80163318
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163318;
        }
    }

label_80163300:
    ctx->pc = 0x80163300u;
    ctx->downcount -= 4;
    // 80163300: subf   r30, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_80163304:
    ctx->pc = 0x80163304u;
    // 80163304: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80163308:
    ctx->pc = 0x80163308u;
    // 80163308: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8016330C:
    ctx->pc = 0x8016330Cu;
    // 8016330C: bl      0x80297E3C
    {
            ctx->lr = 0x80163310u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80163310:
    ctx->pc = 0x80163310u;
    ctx->downcount -= 2;
    // 80163310: add   r3, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80163314:
    ctx->pc = 0x80163314u;
    // 80163314: b       0x8016331C
    {
            goto label_8016331C;
    }

label_80163318:
    ctx->pc = 0x80163318u;
    ctx->downcount -= 1;
    // 80163318: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8016331C:
    ctx->pc = 0x8016331Cu;
    ctx->downcount -= 2;
    // 8016331C: cmpw    r27, r28
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(ctx->gpr[28]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163320:
    ctx->pc = 0x80163320u;
    // 80163320: bc    12, 2, 0x8016333C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8016333C;
        }
    }

label_80163324:
    ctx->pc = 0x80163324u;
    ctx->downcount -= 4;
    // 80163324: subf   r30, r28, r27
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_80163328:
    ctx->pc = 0x80163328u;
    // 80163328: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8016332C:
    ctx->pc = 0x8016332Cu;
    // 8016332C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80163330:
    ctx->pc = 0x80163330u;
    // 80163330: bl      0x80297E3C
    {
            ctx->lr = 0x80163334u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80163334:
    ctx->pc = 0x80163334u;
    ctx->downcount -= 2;
    // 80163334: add   r30, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_80163338:
    ctx->pc = 0x80163338u;
    // 80163338: b       0x80163340
    {
            goto label_80163340;
    }

label_8016333C:
    ctx->pc = 0x8016333Cu;
    ctx->downcount -= 1;
    // 8016333C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80163340:
    ctx->pc = 0x80163340u;
    ctx->downcount -= 7;
    // 80163340: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80163344:
    ctx->pc = 0x80163344u;
    // 80163344: stb     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80163348:
    ctx->pc = 0x80163348u;
    // 80163348: lwz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8016334C:
    ctx->pc = 0x8016334Cu;
    // 8016334C: lwz     r0, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80163350:
    ctx->pc = 0x80163350u;
    // 80163350: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163354:
    ctx->pc = 0x80163354u;
    // 80163354: subf   r4, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_80163358:
    ctx->pc = 0x80163358u;
    // 80163358: bc    12, 2, 0x80163370
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163370;
        }
    }

label_8016335C:
    ctx->pc = 0x8016335Cu;
    ctx->downcount -= 2;
    // 8016335C: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163360:
    ctx->pc = 0x80163360u;
    // 80163360: bc    4, 1, 0x8016336C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8016336C;
        }
    }

label_80163364:
    ctx->pc = 0x80163364u;
    ctx->downcount -= 1;
    // 80163364: bl      0x80281D80
    {
            ctx->lr = 0x80163368u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80163368:
    ctx->pc = 0x80163368u;
    ctx->downcount -= 1;
    // 80163368: b       0x80163370
    {
            goto label_80163370;
    }

label_8016336C:
    ctx->pc = 0x8016336Cu;
    ctx->downcount -= 1;
    // 8016336C: bl      0x8001D934
    {
            ctx->lr = 0x80163370u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80163370:
    ctx->pc = 0x80163370u;
    ctx->downcount -= 5;
    // 80163370: add   r0, r31, r25
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[25];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80163374:
    ctx->pc = 0x80163374u;
    // 80163374: stw     r30, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80163378:
    ctx->pc = 0x80163378u;
    // 80163378: stw     r0, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8016337C:
    ctx->pc = 0x8016337Cu;
    // 8016337C: stw     r31, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80163380:
    ctx->pc = 0x80163380u;
    // 80163380: b       0x801633C4
    {
            goto label_801633C4;
    }

label_80163384:
    ctx->pc = 0x80163384u;
    ctx->downcount -= 5;
    // 80163384: lwz     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80163388:
    ctx->pc = 0x80163388u;
    // 80163388: addi    r4, r28, 1
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(1);

label_8016338C:
    ctx->pc = 0x8016338Cu;
    // 8016338C: cmpw    r27, r4
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163390:
    ctx->pc = 0x80163390u;
    // 80163390: addi    r3, r9, 1
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(1);

label_80163394:
    ctx->pc = 0x80163394u;
    // 80163394: bc    12, 2, 0x801633A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801633A0;
        }
    }

label_80163398:
    ctx->pc = 0x80163398u;
    ctx->downcount -= 2;
    // 80163398: subf   r5, r4, r27
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8016339C:
    ctx->pc = 0x8016339Cu;
    // 8016339C: bl      0x80297E3C
    {
            ctx->lr = 0x801633A0u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_801633A0:
    ctx->pc = 0x801633A0u;
    ctx->downcount -= 8;
    // 801633A0: lwz     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801633A4:
    ctx->pc = 0x801633A4u;
    // 801633A4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801633A8:
    ctx->pc = 0x801633A8u;
    // 801633A8: stbx    r0, r9, r31
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[31];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801633AC:
    ctx->pc = 0x801633ACu;
    // 801633AC: lbz     r11, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_801633B0:
    ctx->pc = 0x801633B0u;
    // 801633B0: lwz     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801633B4:
    ctx->pc = 0x801633B4u;
    // 801633B4: stb     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[11]);
    }

label_801633B8:
    ctx->pc = 0x801633B8u;
    // 801633B8: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801633BC:
    ctx->pc = 0x801633BCu;
    // 801633BC: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801633C0:
    ctx->pc = 0x801633C0u;
    ctx->downcount -= 1;
    // 801633C0: stw     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801633C4:
    ctx->pc = 0x801633C4u;
    ctx->downcount -= 17;
    // 801633C4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801633C8:
    ctx->pc = 0x801633C8u;
    // 801633C8: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801633CC:
    ctx->pc = 0x801633CCu;
    // 801633CC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801633D0:
    ctx->pc = 0x801633D0u;
    // 801633D0: lmw     r25, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801633D4:
    ctx->pc = 0x801633D4u;
    // 801633D4: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_801633D8:
    ctx->pc = 0x801633D8u;
    // 801633D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801633DC:
    ctx->pc = 0x801633DCu;
    ctx->downcount -= 26;
    // 801633DC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801633E0:
    ctx->pc = 0x801633E0u;
    // 801633E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801633E4:
    ctx->pc = 0x801633E4u;
    // 801633E4: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801633E8:
    ctx->pc = 0x801633E8u;
    // 801633E8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801633EC:
    ctx->pc = 0x801633ECu;
    // 801633EC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801633F0:
    ctx->pc = 0x801633F0u;
    // 801633F0: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801633F4:
    ctx->pc = 0x801633F4u;
    // 801633F4: lwz     r3, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801633F8:
    ctx->pc = 0x801633F8u;
    // 801633F8: addi    r9, r9, -24960
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-24960);

label_801633FC:
    ctx->pc = 0x801633FCu;
    // 801633FC: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80163400:
    ctx->pc = 0x80163400u;
    // 80163400: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80163404:
    ctx->pc = 0x80163404u;
    // 80163404: lwz     r0, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80163408:
    ctx->pc = 0x80163408u;
    // 80163408: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016340C:
    ctx->pc = 0x8016340Cu;
    // 8016340C: stw     r9, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80163410:
    ctx->pc = 0x80163410u;
    // 80163410: subf   r4, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_80163414:
    ctx->pc = 0x80163414u;
    // 80163414: stw     r11, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80163418:
    ctx->pc = 0x80163418u;
    // 80163418: bc    12, 2, 0x80163430
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163430;
        }
    }

label_8016341C:
    ctx->pc = 0x8016341Cu;
    ctx->downcount -= 2;
    // 8016341C: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163420:
    ctx->pc = 0x80163420u;
    // 80163420: bc    4, 1, 0x8016342C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8016342C;
        }
    }

label_80163424:
    ctx->pc = 0x80163424u;
    ctx->downcount -= 1;
    // 80163424: bl      0x80281D80
    {
            ctx->lr = 0x80163428u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80163428:
    ctx->pc = 0x80163428u;
    ctx->downcount -= 1;
    // 80163428: b       0x80163430
    {
            goto label_80163430;
    }

label_8016342C:
    ctx->pc = 0x8016342Cu;
    ctx->downcount -= 1;
    // 8016342C: bl      0x8001D934
    {
            ctx->lr = 0x80163430u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80163430:
    ctx->pc = 0x80163430u;
    ctx->downcount -= 5;
    // 80163430: lwz     r3, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80163434:
    ctx->pc = 0x80163434u;
    // 80163434: lwz     r0, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80163438:
    ctx->pc = 0x80163438u;
    // 80163438: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8016343C:
    ctx->pc = 0x8016343Cu;
    // 8016343C: subf   r4, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_80163440:
    ctx->pc = 0x80163440u;
    // 80163440: bc    12, 2, 0x80163458
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163458;
        }
    }

label_80163444:
    ctx->pc = 0x80163444u;
    ctx->downcount -= 2;
    // 80163444: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163448:
    ctx->pc = 0x80163448u;
    // 80163448: bc    4, 1, 0x80163454
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80163454;
        }
    }

label_8016344C:
    ctx->pc = 0x8016344Cu;
    ctx->downcount -= 1;
    // 8016344C: bl      0x80281D80
    {
            ctx->lr = 0x80163450u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80163450:
    ctx->pc = 0x80163450u;
    ctx->downcount -= 1;
    // 80163450: b       0x80163458
    {
            goto label_80163458;
    }

label_80163454:
    ctx->pc = 0x80163454u;
    ctx->downcount -= 1;
    // 80163454: bl      0x8001D934
    {
            ctx->lr = 0x80163458u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80163458:
    ctx->pc = 0x80163458u;
    ctx->downcount -= 4;
    // 80163458: or   r9, r31, r31
    {
        ctx->gpr[9] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8016345C:
    ctx->pc = 0x8016345Cu;
    // 8016345C: lwzu     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_80163460:
    ctx->pc = 0x80163460u;
    // 80163460: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163464:
    ctx->pc = 0x80163464u;
    // 80163464: bc    12, 2, 0x80163488
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163488;
        }
    }

label_80163468:
    ctx->pc = 0x80163468u;
    ctx->downcount -= 5;
    // 80163468: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016346C:
    ctx->pc = 0x8016346Cu;
    // 8016346C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80163470:
    ctx->pc = 0x80163470u;
    // 80163470: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80163474:
    ctx->pc = 0x80163474u;
    // 80163474: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80163478:
    ctx->pc = 0x80163478u;
    // 80163478: bc    4, 1, 0x80163484
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80163484;
        }
    }

label_8016347C:
    ctx->pc = 0x8016347Cu;
    ctx->downcount -= 1;
    // 8016347C: bl      0x80281D80
    {
            ctx->lr = 0x80163480u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80163480:
    ctx->pc = 0x80163480u;
    ctx->downcount -= 1;
    // 80163480: b       0x80163488
    {
            goto label_80163488;
    }

label_80163484:
    ctx->pc = 0x80163484u;
    ctx->downcount -= 1;
    // 80163484: bl      0x8001D934
    {
            ctx->lr = 0x80163488u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80163488:
    ctx->pc = 0x80163488u;
    ctx->downcount -= 2;
    // 80163488: andi.   r0, r30, 0x0001
    {
        ctx->gpr[0] = ctx->gpr[30] & 0x0001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8016348C:
    ctx->pc = 0x8016348Cu;
    // 8016348C: bc    12, 2, 0x80163498
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80163498;
        }
    }

label_80163490:
    ctx->pc = 0x80163490u;
    ctx->downcount -= 2;
    // 80163490: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80163494:
    ctx->pc = 0x80163494u;
    // 80163494: bl      0x80281D80
    {
            ctx->lr = 0x80163498u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80163498:
    ctx->pc = 0x80163498u;
    ctx->downcount -= 16;
    // 80163498: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8016349C:
    ctx->pc = 0x8016349Cu;
    // 8016349C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801634A0:
    ctx->pc = 0x801634A0u;
    // 801634A0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801634A4:
    ctx->pc = 0x801634A4u;
    // 801634A4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801634A8:
    ctx->pc = 0x801634A8u;
    // 801634A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8015F4C0;
        }
    }

label_801634AC:
    ctx->pc = 0x801634ACu;
    ctx->downcount -= 15;
    // 801634AC: stwu     r1, -88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-88);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801634B0:
    ctx->pc = 0x801634B0u;
    // 801634B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801634B4:
    ctx->pc = 0x801634B4u;
    // 801634B4: stmw     r21, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 21; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801634B8:
    ctx->pc = 0x801634B8u;
    // 801634B8: stw     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801634BC:
    ctx->pc = 0x801634BCu;
    // 801634BC: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

    ctx->pc = 0x801634C0u;
    return;
return_dispatch_8015F4C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x8015F518u: goto label_8015F518;
    case 0x8015F568u: goto label_8015F568;
    case 0x8015F5F0u: goto label_8015F5F0;
    case 0x8015F6A4u: goto label_8015F6A4;
    case 0x8015F6B8u: goto label_8015F6B8;
    case 0x8015F6CCu: goto label_8015F6CC;
    case 0x8015F6E0u: goto label_8015F6E0;
    case 0x8015F6F4u: goto label_8015F6F4;
    case 0x8015F708u: goto label_8015F708;
    case 0x8015F71Cu: goto label_8015F71C;
    case 0x8015F730u: goto label_8015F730;
    case 0x8015F744u: goto label_8015F744;
    case 0x8015F758u: goto label_8015F758;
    case 0x8015F76Cu: goto label_8015F76C;
    case 0x8015F780u: goto label_8015F780;
    case 0x8015F7D0u: goto label_8015F7D0;
    case 0x8015F7F0u: goto label_8015F7F0;
    case 0x8015F828u: goto label_8015F828;
    case 0x8015F868u: goto label_8015F868;
    case 0x8015F870u: goto label_8015F870;
    case 0x8015F874u: goto label_8015F874;
    case 0x8015F880u: goto label_8015F880;
    case 0x8015F88Cu: goto label_8015F88C;
    case 0x8015F8A0u: goto label_8015F8A0;
    case 0x8015F94Cu: goto label_8015F94C;
    case 0x8015F984u: goto label_8015F984;
    case 0x8015F994u: goto label_8015F994;
    case 0x8015F9A0u: goto label_8015F9A0;
    case 0x8015F9C4u: goto label_8015F9C4;
    case 0x8015F9D4u: goto label_8015F9D4;
    case 0x8015F9E8u: goto label_8015F9E8;
    case 0x8015FA00u: goto label_8015FA00;
    case 0x8015FA10u: goto label_8015FA10;
    case 0x8015FA6Cu: goto label_8015FA6C;
    case 0x8015FA9Cu: goto label_8015FA9C;
    case 0x8015FAC8u: goto label_8015FAC8;
    case 0x8015FB08u: goto label_8015FB08;
    case 0x8015FB2Cu: goto label_8015FB2C;
    case 0x8015FB44u: goto label_8015FB44;
    case 0x8015FB58u: goto label_8015FB58;
    case 0x8015FB88u: goto label_8015FB88;
    case 0x8015FBBCu: goto label_8015FBBC;
    case 0x8015FBF0u: goto label_8015FBF0;
    case 0x8015FC10u: goto label_8015FC10;
    case 0x8015FC30u: goto label_8015FC30;
    case 0x8015FC5Cu: goto label_8015FC5C;
    case 0x8015FC68u: goto label_8015FC68;
    case 0x8015FCA0u: goto label_8015FCA0;
    case 0x8015FCCCu: goto label_8015FCCC;
    case 0x8015FCF8u: goto label_8015FCF8;
    case 0x8015FD20u: goto label_8015FD20;
    case 0x8015FD44u: goto label_8015FD44;
    case 0x8015FD4Cu: goto label_8015FD4C;
    case 0x8015FD60u: goto label_8015FD60;
    case 0x8015FD98u: goto label_8015FD98;
    case 0x8015FDB4u: goto label_8015FDB4;
    case 0x8015FDBCu: goto label_8015FDBC;
    case 0x8015FDD4u: goto label_8015FDD4;
    case 0x8015FE04u: goto label_8015FE04;
    case 0x8015FE14u: goto label_8015FE14;
    case 0x8015FE3Cu: goto label_8015FE3C;
    case 0x8015FE50u: goto label_8015FE50;
    case 0x8015FE6Cu: goto label_8015FE6C;
    case 0x8015FE74u: goto label_8015FE74;
    case 0x8015FE8Cu: goto label_8015FE8C;
    case 0x8015FEC0u: goto label_8015FEC0;
    case 0x8015FECCu: goto label_8015FECC;
    case 0x8015FF0Cu: goto label_8015FF0C;
    case 0x8015FF1Cu: goto label_8015FF1C;
    case 0x8015FF4Cu: goto label_8015FF4C;
    case 0x8015FF7Cu: goto label_8015FF7C;
    case 0x8015FF9Cu: goto label_8015FF9C;
    case 0x8015FFB8u: goto label_8015FFB8;
    case 0x80160010u: goto label_80160010;
    case 0x80160030u: goto label_80160030;
    case 0x80160050u: goto label_80160050;
    case 0x80160080u: goto label_80160080;
    case 0x8016008Cu: goto label_8016008C;
    case 0x8016016Cu: goto label_8016016C;
    case 0x801601BCu: goto label_801601BC;
    case 0x80160244u: goto label_80160244;
    case 0x801602F8u: goto label_801602F8;
    case 0x8016030Cu: goto label_8016030C;
    case 0x80160320u: goto label_80160320;
    case 0x80160334u: goto label_80160334;
    case 0x80160348u: goto label_80160348;
    case 0x8016035Cu: goto label_8016035C;
    case 0x80160370u: goto label_80160370;
    case 0x80160384u: goto label_80160384;
    case 0x80160398u: goto label_80160398;
    case 0x801603ACu: goto label_801603AC;
    case 0x801603C0u: goto label_801603C0;
    case 0x801603D4u: goto label_801603D4;
    case 0x80160424u: goto label_80160424;
    case 0x80160444u: goto label_80160444;
    case 0x8016047Cu: goto label_8016047C;
    case 0x801604BCu: goto label_801604BC;
    case 0x801604C4u: goto label_801604C4;
    case 0x801604C8u: goto label_801604C8;
    case 0x801604D4u: goto label_801604D4;
    case 0x801604E0u: goto label_801604E0;
    case 0x801604F4u: goto label_801604F4;
    case 0x801605A0u: goto label_801605A0;
    case 0x801605D8u: goto label_801605D8;
    case 0x801605E8u: goto label_801605E8;
    case 0x801605F4u: goto label_801605F4;
    case 0x80160618u: goto label_80160618;
    case 0x80160628u: goto label_80160628;
    case 0x80160654u: goto label_80160654;
    case 0x80160664u: goto label_80160664;
    case 0x801606C0u: goto label_801606C0;
    case 0x801606F0u: goto label_801606F0;
    case 0x8016071Cu: goto label_8016071C;
    case 0x8016075Cu: goto label_8016075C;
    case 0x80160784u: goto label_80160784;
    case 0x801607A8u: goto label_801607A8;
    case 0x801607CCu: goto label_801607CC;
    case 0x801607DCu: goto label_801607DC;
    case 0x8016080Cu: goto label_8016080C;
    case 0x80160840u: goto label_80160840;
    case 0x80160874u: goto label_80160874;
    case 0x80160894u: goto label_80160894;
    case 0x801608B4u: goto label_801608B4;
    case 0x801608E4u: goto label_801608E4;
    case 0x80160910u: goto label_80160910;
    case 0x8016093Cu: goto label_8016093C;
    case 0x80160964u: goto label_80160964;
    case 0x80160988u: goto label_80160988;
    case 0x80160990u: goto label_80160990;
    case 0x801609A4u: goto label_801609A4;
    case 0x801609DCu: goto label_801609DC;
    case 0x801609F8u: goto label_801609F8;
    case 0x80160A00u: goto label_80160A00;
    case 0x80160A18u: goto label_80160A18;
    case 0x80160A48u: goto label_80160A48;
    case 0x80160A5Cu: goto label_80160A5C;
    case 0x80160A78u: goto label_80160A78;
    case 0x80160A80u: goto label_80160A80;
    case 0x80160A98u: goto label_80160A98;
    case 0x80160AC8u: goto label_80160AC8;
    case 0x80160B08u: goto label_80160B08;
    case 0x80160B18u: goto label_80160B18;
    case 0x80160B48u: goto label_80160B48;
    case 0x80160B78u: goto label_80160B78;
    case 0x80160B98u: goto label_80160B98;
    case 0x80160BB4u: goto label_80160BB4;
    case 0x80160C8Cu: goto label_80160C8C;
    case 0x80160CDCu: goto label_80160CDC;
    case 0x80160D64u: goto label_80160D64;
    case 0x80160E18u: goto label_80160E18;
    case 0x80160E2Cu: goto label_80160E2C;
    case 0x80160E40u: goto label_80160E40;
    case 0x80160E54u: goto label_80160E54;
    case 0x80160E68u: goto label_80160E68;
    case 0x80160E7Cu: goto label_80160E7C;
    case 0x80160E90u: goto label_80160E90;
    case 0x80160EA4u: goto label_80160EA4;
    case 0x80160EB8u: goto label_80160EB8;
    case 0x80160ECCu: goto label_80160ECC;
    case 0x80160EE0u: goto label_80160EE0;
    case 0x80160EF4u: goto label_80160EF4;
    case 0x80160F44u: goto label_80160F44;
    case 0x80160F64u: goto label_80160F64;
    case 0x80160F9Cu: goto label_80160F9C;
    case 0x80160FDCu: goto label_80160FDC;
    case 0x80160FE4u: goto label_80160FE4;
    case 0x80160FE8u: goto label_80160FE8;
    case 0x80160FF4u: goto label_80160FF4;
    case 0x80161000u: goto label_80161000;
    case 0x80161014u: goto label_80161014;
    case 0x801610C0u: goto label_801610C0;
    case 0x801610F8u: goto label_801610F8;
    case 0x80161108u: goto label_80161108;
    case 0x80161114u: goto label_80161114;
    case 0x80161138u: goto label_80161138;
    case 0x80161148u: goto label_80161148;
    case 0x80161178u: goto label_80161178;
    case 0x80161188u: goto label_80161188;
    case 0x801611E4u: goto label_801611E4;
    case 0x80161214u: goto label_80161214;
    case 0x80161240u: goto label_80161240;
    case 0x80161280u: goto label_80161280;
    case 0x801612A4u: goto label_801612A4;
    case 0x801612BCu: goto label_801612BC;
    case 0x801612D0u: goto label_801612D0;
    case 0x80161300u: goto label_80161300;
    case 0x80161334u: goto label_80161334;
    case 0x80161368u: goto label_80161368;
    case 0x80161388u: goto label_80161388;
    case 0x801613A8u: goto label_801613A8;
    case 0x801613E0u: goto label_801613E0;
    case 0x8016140Cu: goto label_8016140C;
    case 0x801614DCu: goto label_801614DC;
    case 0x8016152Cu: goto label_8016152C;
    case 0x801615B4u: goto label_801615B4;
    case 0x80161668u: goto label_80161668;
    case 0x8016167Cu: goto label_8016167C;
    case 0x80161690u: goto label_80161690;
    case 0x801616A4u: goto label_801616A4;
    case 0x801616B8u: goto label_801616B8;
    case 0x801616CCu: goto label_801616CC;
    case 0x801616E0u: goto label_801616E0;
    case 0x801616F4u: goto label_801616F4;
    case 0x80161708u: goto label_80161708;
    case 0x80161748u: goto label_80161748;
    case 0x80161768u: goto label_80161768;
    case 0x801617C8u: goto label_801617C8;
    case 0x801617D4u: goto label_801617D4;
    case 0x801617F8u: goto label_801617F8;
    case 0x80161820u: goto label_80161820;
    case 0x80161844u: goto label_80161844;
    case 0x8016184Cu: goto label_8016184C;
    case 0x80161860u: goto label_80161860;
    case 0x8016189Cu: goto label_8016189C;
    case 0x801618ECu: goto label_801618EC;
    case 0x80161928u: goto label_80161928;
    case 0x801619A4u: goto label_801619A4;
    case 0x801619DCu: goto label_801619DC;
    case 0x801619E4u: goto label_801619E4;
    case 0x80161A20u: goto label_80161A20;
    case 0x80161A6Cu: goto label_80161A6C;
    case 0x80161A74u: goto label_80161A74;
    case 0x80161A80u: goto label_80161A80;
    case 0x80161AE4u: goto label_80161AE4;
    case 0x80161AE8u: goto label_80161AE8;
    case 0x80161B24u: goto label_80161B24;
    case 0x80161B38u: goto label_80161B38;
    case 0x80161B5Cu: goto label_80161B5C;
    case 0x80161B70u: goto label_80161B70;
    case 0x80161B94u: goto label_80161B94;
    case 0x80161BA8u: goto label_80161BA8;
    case 0x80161BE4u: goto label_80161BE4;
    case 0x80161C10u: goto label_80161C10;
    case 0x80161C18u: goto label_80161C18;
    case 0x80161C30u: goto label_80161C30;
    case 0x80161C50u: goto label_80161C50;
    case 0x80161C58u: goto label_80161C58;
    case 0x80161C70u: goto label_80161C70;
    case 0x80161C90u: goto label_80161C90;
    case 0x80161C98u: goto label_80161C98;
    case 0x80161CB0u: goto label_80161CB0;
    case 0x80161CE8u: goto label_80161CE8;
    case 0x80161CF8u: goto label_80161CF8;
    case 0x80161D18u: goto label_80161D18;
    case 0x80161D2Cu: goto label_80161D2C;
    case 0x80161D38u: goto label_80161D38;
    case 0x80161D44u: goto label_80161D44;
    case 0x80161D6Cu: goto label_80161D6C;
    case 0x80161D94u: goto label_80161D94;
    case 0x80161DB8u: goto label_80161DB8;
    case 0x80161DCCu: goto label_80161DCC;
    case 0x80161DE0u: goto label_80161DE0;
    case 0x80161E8Cu: goto label_80161E8C;
    case 0x80161E9Cu: goto label_80161E9C;
    case 0x80161EC4u: goto label_80161EC4;
    case 0x80161ED8u: goto label_80161ED8;
    case 0x80161EECu: goto label_80161EEC;
    case 0x80161F10u: goto label_80161F10;
    case 0x80161F24u: goto label_80161F24;
    case 0x80161F30u: goto label_80161F30;
    case 0x80161F3Cu: goto label_80161F3C;
    case 0x80161F64u: goto label_80161F64;
    case 0x80161F90u: goto label_80161F90;
    case 0x80161FA8u: goto label_80161FA8;
    case 0x80161FDCu: goto label_80161FDC;
    case 0x80161FF0u: goto label_80161FF0;
    case 0x80162038u: goto label_80162038;
    case 0x8016204Cu: goto label_8016204C;
    case 0x8016208Cu: goto label_8016208C;
    case 0x801620DCu: goto label_801620DC;
    case 0x801620ECu: goto label_801620EC;
    case 0x80162100u: goto label_80162100;
    case 0x8016211Cu: goto label_8016211C;
    case 0x8016213Cu: goto label_8016213C;
    case 0x801621BCu: goto label_801621BC;
    case 0x801621E0u: goto label_801621E0;
    case 0x80162208u: goto label_80162208;
    case 0x8016221Cu: goto label_8016221C;
    case 0x801622F4u: goto label_801622F4;
    case 0x80162344u: goto label_80162344;
    case 0x801623CCu: goto label_801623CC;
    case 0x801624C0u: goto label_801624C0;
    case 0x801624E0u: goto label_801624E0;
    case 0x80162568u: goto label_80162568;
    case 0x801625E4u: goto label_801625E4;
    case 0x801625F4u: goto label_801625F4;
    case 0x80162620u: goto label_80162620;
    case 0x80162668u: goto label_80162668;
    case 0x8016269Cu: goto label_8016269C;
    case 0x801626A4u: goto label_801626A4;
    case 0x80162700u: goto label_80162700;
    case 0x80162714u: goto label_80162714;
    case 0x80162728u: goto label_80162728;
    case 0x8016273Cu: goto label_8016273C;
    case 0x80162750u: goto label_80162750;
    case 0x80162764u: goto label_80162764;
    case 0x80162778u: goto label_80162778;
    case 0x8016278Cu: goto label_8016278C;
    case 0x801627A0u: goto label_801627A0;
    case 0x801627B4u: goto label_801627B4;
    case 0x801627C8u: goto label_801627C8;
    case 0x801627DCu: goto label_801627DC;
    case 0x8016282Cu: goto label_8016282C;
    case 0x8016284Cu: goto label_8016284C;
    case 0x8016288Cu: goto label_8016288C;
    case 0x801628C0u: goto label_801628C0;
    case 0x801628D0u: goto label_801628D0;
    case 0x801628DCu: goto label_801628DC;
    case 0x801628E4u: goto label_801628E4;
    case 0x8016298Cu: goto label_8016298C;
    case 0x801629E4u: goto label_801629E4;
    case 0x80162A14u: goto label_80162A14;
    case 0x80162A40u: goto label_80162A40;
    case 0x80162A70u: goto label_80162A70;
    case 0x80162AA4u: goto label_80162AA4;
    case 0x80162AB0u: goto label_80162AB0;
    case 0x80162ACCu: goto label_80162ACC;
    case 0x80162AF4u: goto label_80162AF4;
    case 0x80162B38u: goto label_80162B38;
    case 0x80162B74u: goto label_80162B74;
    case 0x80162BA8u: goto label_80162BA8;
    case 0x80162BCCu: goto label_80162BCC;
    case 0x80162C00u: goto label_80162C00;
    case 0x80162C40u: goto label_80162C40;
    case 0x80162C60u: goto label_80162C60;
    case 0x80162C6Cu: goto label_80162C6C;
    case 0x80162CA4u: goto label_80162CA4;
    case 0x80162CC8u: goto label_80162CC8;
    case 0x80162D20u: goto label_80162D20;
    case 0x80162D68u: goto label_80162D68;
    case 0x80162D7Cu: goto label_80162D7C;
    case 0x80162D90u: goto label_80162D90;
    case 0x80162DA4u: goto label_80162DA4;
    case 0x80162DB8u: goto label_80162DB8;
    case 0x80162DCCu: goto label_80162DCC;
    case 0x80162DE0u: goto label_80162DE0;
    case 0x80162DF4u: goto label_80162DF4;
    case 0x80162E08u: goto label_80162E08;
    case 0x80162E3Cu: goto label_80162E3C;
    case 0x80162E44u: goto label_80162E44;
    case 0x80162E70u: goto label_80162E70;
    case 0x80162EBCu: goto label_80162EBC;
    case 0x80162F24u: goto label_80162F24;
    case 0x80162F74u: goto label_80162F74;
    case 0x80162F7Cu: goto label_80162F7C;
    case 0x80162F84u: goto label_80162F84;
    case 0x80162F94u: goto label_80162F94;
    case 0x80162FA4u: goto label_80162FA4;
    case 0x80162FD8u: goto label_80162FD8;
    case 0x80162FFCu: goto label_80162FFC;
    case 0x80163020u: goto label_80163020;
    case 0x80163060u: goto label_80163060;
    case 0x801630B4u: goto label_801630B4;
    case 0x801630C4u: goto label_801630C4;
    case 0x801630F0u: goto label_801630F0;
    case 0x80163114u: goto label_80163114;
    case 0x80163148u: goto label_80163148;
    case 0x80163150u: goto label_80163150;
    case 0x80163180u: goto label_80163180;
    case 0x801631B4u: goto label_801631B4;
    case 0x801631C4u: goto label_801631C4;
    case 0x801631F8u: goto label_801631F8;
    case 0x8016321Cu: goto label_8016321C;
    case 0x80163240u: goto label_80163240;
    case 0x80163280u: goto label_80163280;
    case 0x801632D4u: goto label_801632D4;
    case 0x801632E4u: goto label_801632E4;
    case 0x80163310u: goto label_80163310;
    case 0x80163334u: goto label_80163334;
    case 0x80163368u: goto label_80163368;
    case 0x80163370u: goto label_80163370;
    case 0x801633A0u: goto label_801633A0;
    case 0x80163428u: goto label_80163428;
    case 0x80163430u: goto label_80163430;
    case 0x80163450u: goto label_80163450;
    case 0x80163458u: goto label_80163458;
    case 0x80163480u: goto label_80163480;
    case 0x80163488u: goto label_80163488;
    case 0x80163498u: goto label_80163498;
    default: return;
    }
}

