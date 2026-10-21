// DolRecomp output
#include "../generated.h"

static void loop_801DBDBC(CPUState* ctx) {
label_801DBDBC:
    ctx->downcount -= 8;
    ctx->pc = 0x801DBDBCu;
    // 801DBDBC: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 801DBDC0: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 801DBDC4: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x801DBDC8u;
    // 801DBDC8: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 801DBDCC: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 801DBDD0: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 801DBDD4: cmpw    r9, r8
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

    // 801DBDD8: bc    4, 2, 0x801DBDBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DBDBCu;
                return;
            }
            goto label_801DBDBC;
        }
    }

    ctx->pc = 0x801DBDDCu;
}

static void loop_801DC5B0(CPUState* ctx) {
label_801DC5B0:
    ctx->downcount -= 8;
    ctx->pc = 0x801DC5B0u;
    // 801DC5B0: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 801DC5B4: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 801DC5B8: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x801DC5BCu;
    // 801DC5BC: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 801DC5C0: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 801DC5C4: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 801DC5C8: cmpw    r9, r8
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

    // 801DC5CC: bc    4, 2, 0x801DC5B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DC5B0u;
                return;
            }
            goto label_801DC5B0;
        }
    }

    ctx->pc = 0x801DC5D0u;
}

static void loop_801DE278(CPUState* ctx) {
label_801DE278:
    ctx->downcount -= 8;
    ctx->pc = 0x801DE278u;
    // 801DE278: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 801DE27C: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 801DE280: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x801DE284u;
    // 801DE284: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 801DE288: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 801DE28C: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 801DE290: cmpw    r9, r8
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

    // 801DE294: bc    4, 2, 0x801DE278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE278u;
                return;
            }
            goto label_801DE278;
        }
    }

    ctx->pc = 0x801DE298u;
}

static void loop_801DE794(CPUState* ctx) {
label_801DE794:
    ctx->downcount -= 3;
    // 801DE794: addi    r11, r11, 2
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2);

    // 801DE798: cmpw    r11, r9
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 801DE79C: bc    4, 2, 0x801DE794
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE794u;
                return;
            }
            goto label_801DE794;
        }
    }

    ctx->pc = 0x801DE7A0u;
}

static void loop_801DE7B8(CPUState* ctx) {
label_801DE7B8:
    ctx->downcount -= 6;
    ctx->pc = 0x801DE7B8u;
    // 801DE7B8: lhz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 801DE7BC: addic.  r10, r10, -1
    {
        u64 a = ctx->gpr[10];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[10] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 801DE7C0: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

    ctx->pc = 0x801DE7C4u;
    // 801DE7C4: sth     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    // 801DE7C8: addi    r11, r11, 2
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2);

    // 801DE7CC: bc    12, 1, 0x801DE7B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE7B8u;
                return;
            }
            goto label_801DE7B8;
        }
    }

    ctx->pc = 0x801DE7D0u;
}

static void loop_801DE82C(CPUState* ctx) {
label_801DE82C:
    ctx->downcount -= 3;
    // 801DE82C: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

    // 801DE830: cmpw    r9, r0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 801DE834: bc    4, 2, 0x801DE82C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE82Cu;
                return;
            }
            goto label_801DE82C;
        }
    }

    ctx->pc = 0x801DE838u;
}

static void loop_801DE850(CPUState* ctx) {
label_801DE850:
    ctx->downcount -= 6;
    ctx->pc = 0x801DE850u;
    // 801DE850: lhz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 801DE854: addic.  r9, r9, -1
    {
        u64 a = ctx->gpr[9];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[9] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 801DE858: addi    r11, r11, 2
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2);

    ctx->pc = 0x801DE85Cu;
    // 801DE85C: sth     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    // 801DE860: addi    r10, r10, 2
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(2);

    // 801DE864: bc    12, 1, 0x801DE850
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE850u;
                return;
            }
            goto label_801DE850;
        }
    }

    ctx->pc = 0x801DE868u;
}

static void loop_801DE910(CPUState* ctx) {
label_801DE910:
    ctx->downcount -= 3;
    // 801DE910: addi    r10, r10, 2
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(2);

    // 801DE914: cmpw    r10, r9
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 801DE918: bc    4, 2, 0x801DE910
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE910u;
                return;
            }
            goto label_801DE910;
        }
    }

    ctx->pc = 0x801DE91Cu;
}

static void loop_801DE934(CPUState* ctx) {
label_801DE934:
    ctx->downcount -= 6;
    ctx->pc = 0x801DE934u;
    // 801DE934: lhz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 801DE938: addic.  r11, r11, -1
    {
        u64 a = ctx->gpr[11];
        u64 b = (u32)(s32)(-1);
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

    // 801DE93C: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

    ctx->pc = 0x801DE940u;
    // 801DE940: sth     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    // 801DE944: addi    r10, r10, 2
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(2);

    // 801DE948: bc    12, 1, 0x801DE934
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE934u;
                return;
            }
            goto label_801DE934;
        }
    }

    ctx->pc = 0x801DE94Cu;
}

static void loop_801DF038(CPUState* ctx) {
label_801DF038:
    ctx->downcount -= 4;
    ctx->pc = 0x801DF038u;
    // 801DF038: lwz     r9, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x801DF03Cu;
    // 801DF03C: lwzu     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

    // 801DF040: cmpw    r0, r11
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 801DF044: bc    4, 2, 0x801DF038
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DF038u;
                return;
            }
            goto label_801DF038;
        }
    }

    ctx->pc = 0x801DF048u;
}

void func_801DB4C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x801DB4C0u: goto label_801DB4C0;
    case 0x801DB4C4u: goto label_801DB4C4;
    case 0x801DB4C8u: goto label_801DB4C8;
    case 0x801DB4CCu: goto label_801DB4CC;
    case 0x801DB4D0u: goto label_801DB4D0;
    case 0x801DB4D4u: goto label_801DB4D4;
    case 0x801DB4D8u: goto label_801DB4D8;
    case 0x801DB4DCu: goto label_801DB4DC;
    case 0x801DB4E0u: goto label_801DB4E0;
    case 0x801DB4E4u: goto label_801DB4E4;
    case 0x801DB4E8u: goto label_801DB4E8;
    case 0x801DB4ECu: goto label_801DB4EC;
    case 0x801DB4F0u: goto label_801DB4F0;
    case 0x801DB4F4u: goto label_801DB4F4;
    case 0x801DB4F8u: goto label_801DB4F8;
    case 0x801DB4FCu: goto label_801DB4FC;
    case 0x801DB500u: goto label_801DB500;
    case 0x801DB504u: goto label_801DB504;
    case 0x801DB508u: goto label_801DB508;
    case 0x801DB50Cu: goto label_801DB50C;
    case 0x801DB510u: goto label_801DB510;
    case 0x801DB514u: goto label_801DB514;
    case 0x801DB518u: goto label_801DB518;
    case 0x801DB51Cu: goto label_801DB51C;
    case 0x801DB520u: goto label_801DB520;
    case 0x801DB524u: goto label_801DB524;
    case 0x801DB528u: goto label_801DB528;
    case 0x801DB52Cu: goto label_801DB52C;
    case 0x801DB530u: goto label_801DB530;
    case 0x801DB534u: goto label_801DB534;
    case 0x801DB538u: goto label_801DB538;
    case 0x801DB53Cu: goto label_801DB53C;
    case 0x801DB540u: goto label_801DB540;
    case 0x801DB544u: goto label_801DB544;
    case 0x801DB548u: goto label_801DB548;
    case 0x801DB54Cu: goto label_801DB54C;
    case 0x801DB550u: goto label_801DB550;
    case 0x801DB554u: goto label_801DB554;
    case 0x801DB558u: goto label_801DB558;
    case 0x801DB55Cu: goto label_801DB55C;
    case 0x801DB560u: goto label_801DB560;
    case 0x801DB564u: goto label_801DB564;
    case 0x801DB568u: goto label_801DB568;
    case 0x801DB56Cu: goto label_801DB56C;
    case 0x801DB570u: goto label_801DB570;
    case 0x801DB574u: goto label_801DB574;
    case 0x801DB578u: goto label_801DB578;
    case 0x801DB57Cu: goto label_801DB57C;
    case 0x801DB580u: goto label_801DB580;
    case 0x801DB584u: goto label_801DB584;
    case 0x801DB588u: goto label_801DB588;
    case 0x801DB58Cu: goto label_801DB58C;
    case 0x801DB590u: goto label_801DB590;
    case 0x801DB594u: goto label_801DB594;
    case 0x801DB598u: goto label_801DB598;
    case 0x801DB59Cu: goto label_801DB59C;
    case 0x801DB5A0u: goto label_801DB5A0;
    case 0x801DB5A4u: goto label_801DB5A4;
    case 0x801DB5A8u: goto label_801DB5A8;
    case 0x801DB5ACu: goto label_801DB5AC;
    case 0x801DB5B0u: goto label_801DB5B0;
    case 0x801DB5B4u: goto label_801DB5B4;
    case 0x801DB5B8u: goto label_801DB5B8;
    case 0x801DB5BCu: goto label_801DB5BC;
    case 0x801DB5C0u: goto label_801DB5C0;
    case 0x801DB5C4u: goto label_801DB5C4;
    case 0x801DB5C8u: goto label_801DB5C8;
    case 0x801DB5CCu: goto label_801DB5CC;
    case 0x801DB5D0u: goto label_801DB5D0;
    case 0x801DB5D4u: goto label_801DB5D4;
    case 0x801DB5D8u: goto label_801DB5D8;
    case 0x801DB5DCu: goto label_801DB5DC;
    case 0x801DB5E0u: goto label_801DB5E0;
    case 0x801DB5E4u: goto label_801DB5E4;
    case 0x801DB5E8u: goto label_801DB5E8;
    case 0x801DB5ECu: goto label_801DB5EC;
    case 0x801DB5F0u: goto label_801DB5F0;
    case 0x801DB5F4u: goto label_801DB5F4;
    case 0x801DB5F8u: goto label_801DB5F8;
    case 0x801DB5FCu: goto label_801DB5FC;
    case 0x801DB600u: goto label_801DB600;
    case 0x801DB604u: goto label_801DB604;
    case 0x801DB608u: goto label_801DB608;
    case 0x801DB60Cu: goto label_801DB60C;
    case 0x801DB610u: goto label_801DB610;
    case 0x801DB614u: goto label_801DB614;
    case 0x801DB618u: goto label_801DB618;
    case 0x801DB61Cu: goto label_801DB61C;
    case 0x801DB620u: goto label_801DB620;
    case 0x801DB624u: goto label_801DB624;
    case 0x801DB628u: goto label_801DB628;
    case 0x801DB62Cu: goto label_801DB62C;
    case 0x801DB630u: goto label_801DB630;
    case 0x801DB634u: goto label_801DB634;
    case 0x801DB638u: goto label_801DB638;
    case 0x801DB63Cu: goto label_801DB63C;
    case 0x801DB640u: goto label_801DB640;
    case 0x801DB644u: goto label_801DB644;
    case 0x801DB648u: goto label_801DB648;
    case 0x801DB64Cu: goto label_801DB64C;
    case 0x801DB650u: goto label_801DB650;
    case 0x801DB654u: goto label_801DB654;
    case 0x801DB658u: goto label_801DB658;
    case 0x801DB65Cu: goto label_801DB65C;
    case 0x801DB660u: goto label_801DB660;
    case 0x801DB664u: goto label_801DB664;
    case 0x801DB668u: goto label_801DB668;
    case 0x801DB66Cu: goto label_801DB66C;
    case 0x801DB670u: goto label_801DB670;
    case 0x801DB674u: goto label_801DB674;
    case 0x801DB678u: goto label_801DB678;
    case 0x801DB67Cu: goto label_801DB67C;
    case 0x801DB680u: goto label_801DB680;
    case 0x801DB684u: goto label_801DB684;
    case 0x801DB688u: goto label_801DB688;
    case 0x801DB68Cu: goto label_801DB68C;
    case 0x801DB690u: goto label_801DB690;
    case 0x801DB694u: goto label_801DB694;
    case 0x801DB698u: goto label_801DB698;
    case 0x801DB69Cu: goto label_801DB69C;
    case 0x801DB6A0u: goto label_801DB6A0;
    case 0x801DB6A4u: goto label_801DB6A4;
    case 0x801DB6A8u: goto label_801DB6A8;
    case 0x801DB6ACu: goto label_801DB6AC;
    case 0x801DB6B0u: goto label_801DB6B0;
    case 0x801DB6B4u: goto label_801DB6B4;
    case 0x801DB6B8u: goto label_801DB6B8;
    case 0x801DB6BCu: goto label_801DB6BC;
    case 0x801DB6C0u: goto label_801DB6C0;
    case 0x801DB6C4u: goto label_801DB6C4;
    case 0x801DB6C8u: goto label_801DB6C8;
    case 0x801DB6CCu: goto label_801DB6CC;
    case 0x801DB6D0u: goto label_801DB6D0;
    case 0x801DB6D4u: goto label_801DB6D4;
    case 0x801DB6D8u: goto label_801DB6D8;
    case 0x801DB6DCu: goto label_801DB6DC;
    case 0x801DB6E0u: goto label_801DB6E0;
    case 0x801DB6E4u: goto label_801DB6E4;
    case 0x801DB6E8u: goto label_801DB6E8;
    case 0x801DB6ECu: goto label_801DB6EC;
    case 0x801DB6F0u: goto label_801DB6F0;
    case 0x801DB6F4u: goto label_801DB6F4;
    case 0x801DB6F8u: goto label_801DB6F8;
    case 0x801DB6FCu: goto label_801DB6FC;
    case 0x801DB700u: goto label_801DB700;
    case 0x801DB704u: goto label_801DB704;
    case 0x801DB708u: goto label_801DB708;
    case 0x801DB70Cu: goto label_801DB70C;
    case 0x801DB710u: goto label_801DB710;
    case 0x801DB714u: goto label_801DB714;
    case 0x801DB718u: goto label_801DB718;
    case 0x801DB71Cu: goto label_801DB71C;
    case 0x801DB720u: goto label_801DB720;
    case 0x801DB724u: goto label_801DB724;
    case 0x801DB728u: goto label_801DB728;
    case 0x801DB72Cu: goto label_801DB72C;
    case 0x801DB730u: goto label_801DB730;
    case 0x801DB734u: goto label_801DB734;
    case 0x801DB738u: goto label_801DB738;
    case 0x801DB73Cu: goto label_801DB73C;
    case 0x801DB740u: goto label_801DB740;
    case 0x801DB744u: goto label_801DB744;
    case 0x801DB748u: goto label_801DB748;
    case 0x801DB74Cu: goto label_801DB74C;
    case 0x801DB750u: goto label_801DB750;
    case 0x801DB754u: goto label_801DB754;
    case 0x801DB758u: goto label_801DB758;
    case 0x801DB75Cu: goto label_801DB75C;
    case 0x801DB760u: goto label_801DB760;
    case 0x801DB764u: goto label_801DB764;
    case 0x801DB768u: goto label_801DB768;
    case 0x801DB76Cu: goto label_801DB76C;
    case 0x801DB770u: goto label_801DB770;
    case 0x801DB774u: goto label_801DB774;
    case 0x801DB778u: goto label_801DB778;
    case 0x801DB77Cu: goto label_801DB77C;
    case 0x801DB780u: goto label_801DB780;
    case 0x801DB784u: goto label_801DB784;
    case 0x801DB788u: goto label_801DB788;
    case 0x801DB78Cu: goto label_801DB78C;
    case 0x801DB790u: goto label_801DB790;
    case 0x801DB794u: goto label_801DB794;
    case 0x801DB798u: goto label_801DB798;
    case 0x801DB79Cu: goto label_801DB79C;
    case 0x801DB7A0u: goto label_801DB7A0;
    case 0x801DB7A4u: goto label_801DB7A4;
    case 0x801DB7A8u: goto label_801DB7A8;
    case 0x801DB7ACu: goto label_801DB7AC;
    case 0x801DB7B0u: goto label_801DB7B0;
    case 0x801DB7B4u: goto label_801DB7B4;
    case 0x801DB7B8u: goto label_801DB7B8;
    case 0x801DB7BCu: goto label_801DB7BC;
    case 0x801DB7C0u: goto label_801DB7C0;
    case 0x801DB7C4u: goto label_801DB7C4;
    case 0x801DB7C8u: goto label_801DB7C8;
    case 0x801DB7CCu: goto label_801DB7CC;
    case 0x801DB7D0u: goto label_801DB7D0;
    case 0x801DB7D4u: goto label_801DB7D4;
    case 0x801DB7D8u: goto label_801DB7D8;
    case 0x801DB7DCu: goto label_801DB7DC;
    case 0x801DB7E0u: goto label_801DB7E0;
    case 0x801DB7E4u: goto label_801DB7E4;
    case 0x801DB7E8u: goto label_801DB7E8;
    case 0x801DB7ECu: goto label_801DB7EC;
    case 0x801DB7F0u: goto label_801DB7F0;
    case 0x801DB7F4u: goto label_801DB7F4;
    case 0x801DB7F8u: goto label_801DB7F8;
    case 0x801DB7FCu: goto label_801DB7FC;
    case 0x801DB800u: goto label_801DB800;
    case 0x801DB804u: goto label_801DB804;
    case 0x801DB808u: goto label_801DB808;
    case 0x801DB80Cu: goto label_801DB80C;
    case 0x801DB810u: goto label_801DB810;
    case 0x801DB814u: goto label_801DB814;
    case 0x801DB818u: goto label_801DB818;
    case 0x801DB81Cu: goto label_801DB81C;
    case 0x801DB820u: goto label_801DB820;
    case 0x801DB824u: goto label_801DB824;
    case 0x801DB828u: goto label_801DB828;
    case 0x801DB82Cu: goto label_801DB82C;
    case 0x801DB830u: goto label_801DB830;
    case 0x801DB834u: goto label_801DB834;
    case 0x801DB838u: goto label_801DB838;
    case 0x801DB83Cu: goto label_801DB83C;
    case 0x801DB840u: goto label_801DB840;
    case 0x801DB844u: goto label_801DB844;
    case 0x801DB848u: goto label_801DB848;
    case 0x801DB84Cu: goto label_801DB84C;
    case 0x801DB850u: goto label_801DB850;
    case 0x801DB854u: goto label_801DB854;
    case 0x801DB858u: goto label_801DB858;
    case 0x801DB85Cu: goto label_801DB85C;
    case 0x801DB860u: goto label_801DB860;
    case 0x801DB864u: goto label_801DB864;
    case 0x801DB868u: goto label_801DB868;
    case 0x801DB86Cu: goto label_801DB86C;
    case 0x801DB870u: goto label_801DB870;
    case 0x801DB874u: goto label_801DB874;
    case 0x801DB878u: goto label_801DB878;
    case 0x801DB87Cu: goto label_801DB87C;
    case 0x801DB880u: goto label_801DB880;
    case 0x801DB884u: goto label_801DB884;
    case 0x801DB888u: goto label_801DB888;
    case 0x801DB88Cu: goto label_801DB88C;
    case 0x801DB890u: goto label_801DB890;
    case 0x801DB894u: goto label_801DB894;
    case 0x801DB898u: goto label_801DB898;
    case 0x801DB89Cu: goto label_801DB89C;
    case 0x801DB8A0u: goto label_801DB8A0;
    case 0x801DB8A4u: goto label_801DB8A4;
    case 0x801DB8A8u: goto label_801DB8A8;
    case 0x801DB8ACu: goto label_801DB8AC;
    case 0x801DB8B0u: goto label_801DB8B0;
    case 0x801DB8B4u: goto label_801DB8B4;
    case 0x801DB8B8u: goto label_801DB8B8;
    case 0x801DB8BCu: goto label_801DB8BC;
    case 0x801DB8C0u: goto label_801DB8C0;
    case 0x801DB8C4u: goto label_801DB8C4;
    case 0x801DB8C8u: goto label_801DB8C8;
    case 0x801DB8CCu: goto label_801DB8CC;
    case 0x801DB8D0u: goto label_801DB8D0;
    case 0x801DB8D4u: goto label_801DB8D4;
    case 0x801DB8D8u: goto label_801DB8D8;
    case 0x801DB8DCu: goto label_801DB8DC;
    case 0x801DB8E0u: goto label_801DB8E0;
    case 0x801DB8E4u: goto label_801DB8E4;
    case 0x801DB8E8u: goto label_801DB8E8;
    case 0x801DB8ECu: goto label_801DB8EC;
    case 0x801DB8F0u: goto label_801DB8F0;
    case 0x801DB8F4u: goto label_801DB8F4;
    case 0x801DB8F8u: goto label_801DB8F8;
    case 0x801DB8FCu: goto label_801DB8FC;
    case 0x801DB900u: goto label_801DB900;
    case 0x801DB904u: goto label_801DB904;
    case 0x801DB908u: goto label_801DB908;
    case 0x801DB90Cu: goto label_801DB90C;
    case 0x801DB910u: goto label_801DB910;
    case 0x801DB914u: goto label_801DB914;
    case 0x801DB918u: goto label_801DB918;
    case 0x801DB91Cu: goto label_801DB91C;
    case 0x801DB920u: goto label_801DB920;
    case 0x801DB924u: goto label_801DB924;
    case 0x801DB928u: goto label_801DB928;
    case 0x801DB92Cu: goto label_801DB92C;
    case 0x801DB930u: goto label_801DB930;
    case 0x801DB934u: goto label_801DB934;
    case 0x801DB938u: goto label_801DB938;
    case 0x801DB93Cu: goto label_801DB93C;
    case 0x801DB940u: goto label_801DB940;
    case 0x801DB944u: goto label_801DB944;
    case 0x801DB948u: goto label_801DB948;
    case 0x801DB94Cu: goto label_801DB94C;
    case 0x801DB950u: goto label_801DB950;
    case 0x801DB954u: goto label_801DB954;
    case 0x801DB958u: goto label_801DB958;
    case 0x801DB95Cu: goto label_801DB95C;
    case 0x801DB960u: goto label_801DB960;
    case 0x801DB964u: goto label_801DB964;
    case 0x801DB968u: goto label_801DB968;
    case 0x801DB96Cu: goto label_801DB96C;
    case 0x801DB970u: goto label_801DB970;
    case 0x801DB974u: goto label_801DB974;
    case 0x801DB978u: goto label_801DB978;
    case 0x801DB97Cu: goto label_801DB97C;
    case 0x801DB980u: goto label_801DB980;
    case 0x801DB984u: goto label_801DB984;
    case 0x801DB988u: goto label_801DB988;
    case 0x801DB98Cu: goto label_801DB98C;
    case 0x801DB990u: goto label_801DB990;
    case 0x801DB994u: goto label_801DB994;
    case 0x801DB998u: goto label_801DB998;
    case 0x801DB99Cu: goto label_801DB99C;
    case 0x801DB9A0u: goto label_801DB9A0;
    case 0x801DB9A4u: goto label_801DB9A4;
    case 0x801DB9A8u: goto label_801DB9A8;
    case 0x801DB9ACu: goto label_801DB9AC;
    case 0x801DB9B0u: goto label_801DB9B0;
    case 0x801DB9B4u: goto label_801DB9B4;
    case 0x801DB9B8u: goto label_801DB9B8;
    case 0x801DB9BCu: goto label_801DB9BC;
    case 0x801DB9C0u: goto label_801DB9C0;
    case 0x801DB9C4u: goto label_801DB9C4;
    case 0x801DB9C8u: goto label_801DB9C8;
    case 0x801DB9CCu: goto label_801DB9CC;
    case 0x801DB9D0u: goto label_801DB9D0;
    case 0x801DB9D4u: goto label_801DB9D4;
    case 0x801DB9D8u: goto label_801DB9D8;
    case 0x801DB9DCu: goto label_801DB9DC;
    case 0x801DB9E0u: goto label_801DB9E0;
    case 0x801DB9E4u: goto label_801DB9E4;
    case 0x801DB9E8u: goto label_801DB9E8;
    case 0x801DB9ECu: goto label_801DB9EC;
    case 0x801DB9F0u: goto label_801DB9F0;
    case 0x801DB9F4u: goto label_801DB9F4;
    case 0x801DB9F8u: goto label_801DB9F8;
    case 0x801DB9FCu: goto label_801DB9FC;
    case 0x801DBA00u: goto label_801DBA00;
    case 0x801DBA04u: goto label_801DBA04;
    case 0x801DBA08u: goto label_801DBA08;
    case 0x801DBA0Cu: goto label_801DBA0C;
    case 0x801DBA10u: goto label_801DBA10;
    case 0x801DBA14u: goto label_801DBA14;
    case 0x801DBA18u: goto label_801DBA18;
    case 0x801DBA1Cu: goto label_801DBA1C;
    case 0x801DBA20u: goto label_801DBA20;
    case 0x801DBA24u: goto label_801DBA24;
    case 0x801DBA28u: goto label_801DBA28;
    case 0x801DBA2Cu: goto label_801DBA2C;
    case 0x801DBA30u: goto label_801DBA30;
    case 0x801DBA34u: goto label_801DBA34;
    case 0x801DBA38u: goto label_801DBA38;
    case 0x801DBA3Cu: goto label_801DBA3C;
    case 0x801DBA40u: goto label_801DBA40;
    case 0x801DBA44u: goto label_801DBA44;
    case 0x801DBA48u: goto label_801DBA48;
    case 0x801DBA4Cu: goto label_801DBA4C;
    case 0x801DBA50u: goto label_801DBA50;
    case 0x801DBA54u: goto label_801DBA54;
    case 0x801DBA58u: goto label_801DBA58;
    case 0x801DBA5Cu: goto label_801DBA5C;
    case 0x801DBA60u: goto label_801DBA60;
    case 0x801DBA64u: goto label_801DBA64;
    case 0x801DBA68u: goto label_801DBA68;
    case 0x801DBA6Cu: goto label_801DBA6C;
    case 0x801DBA70u: goto label_801DBA70;
    case 0x801DBA74u: goto label_801DBA74;
    case 0x801DBA78u: goto label_801DBA78;
    case 0x801DBA7Cu: goto label_801DBA7C;
    case 0x801DBA80u: goto label_801DBA80;
    case 0x801DBA84u: goto label_801DBA84;
    case 0x801DBA88u: goto label_801DBA88;
    case 0x801DBA8Cu: goto label_801DBA8C;
    case 0x801DBA90u: goto label_801DBA90;
    case 0x801DBA94u: goto label_801DBA94;
    case 0x801DBA98u: goto label_801DBA98;
    case 0x801DBA9Cu: goto label_801DBA9C;
    case 0x801DBAA0u: goto label_801DBAA0;
    case 0x801DBAA4u: goto label_801DBAA4;
    case 0x801DBAA8u: goto label_801DBAA8;
    case 0x801DBAACu: goto label_801DBAAC;
    case 0x801DBAB0u: goto label_801DBAB0;
    case 0x801DBAB4u: goto label_801DBAB4;
    case 0x801DBAB8u: goto label_801DBAB8;
    case 0x801DBABCu: goto label_801DBABC;
    case 0x801DBAC0u: goto label_801DBAC0;
    case 0x801DBAC4u: goto label_801DBAC4;
    case 0x801DBAC8u: goto label_801DBAC8;
    case 0x801DBACCu: goto label_801DBACC;
    case 0x801DBAD0u: goto label_801DBAD0;
    case 0x801DBAD4u: goto label_801DBAD4;
    case 0x801DBAD8u: goto label_801DBAD8;
    case 0x801DBADCu: goto label_801DBADC;
    case 0x801DBAE0u: goto label_801DBAE0;
    case 0x801DBAE4u: goto label_801DBAE4;
    case 0x801DBAE8u: goto label_801DBAE8;
    case 0x801DBAECu: goto label_801DBAEC;
    case 0x801DBAF0u: goto label_801DBAF0;
    case 0x801DBAF4u: goto label_801DBAF4;
    case 0x801DBAF8u: goto label_801DBAF8;
    case 0x801DBAFCu: goto label_801DBAFC;
    case 0x801DBB00u: goto label_801DBB00;
    case 0x801DBB04u: goto label_801DBB04;
    case 0x801DBB08u: goto label_801DBB08;
    case 0x801DBB0Cu: goto label_801DBB0C;
    case 0x801DBB10u: goto label_801DBB10;
    case 0x801DBB14u: goto label_801DBB14;
    case 0x801DBB18u: goto label_801DBB18;
    case 0x801DBB1Cu: goto label_801DBB1C;
    case 0x801DBB20u: goto label_801DBB20;
    case 0x801DBB24u: goto label_801DBB24;
    case 0x801DBB28u: goto label_801DBB28;
    case 0x801DBB2Cu: goto label_801DBB2C;
    case 0x801DBB30u: goto label_801DBB30;
    case 0x801DBB34u: goto label_801DBB34;
    case 0x801DBB38u: goto label_801DBB38;
    case 0x801DBB3Cu: goto label_801DBB3C;
    case 0x801DBB40u: goto label_801DBB40;
    case 0x801DBB44u: goto label_801DBB44;
    case 0x801DBB48u: goto label_801DBB48;
    case 0x801DBB4Cu: goto label_801DBB4C;
    case 0x801DBB50u: goto label_801DBB50;
    case 0x801DBB54u: goto label_801DBB54;
    case 0x801DBB58u: goto label_801DBB58;
    case 0x801DBB5Cu: goto label_801DBB5C;
    case 0x801DBB60u: goto label_801DBB60;
    case 0x801DBB64u: goto label_801DBB64;
    case 0x801DBB68u: goto label_801DBB68;
    case 0x801DBB6Cu: goto label_801DBB6C;
    case 0x801DBB70u: goto label_801DBB70;
    case 0x801DBB74u: goto label_801DBB74;
    case 0x801DBB78u: goto label_801DBB78;
    case 0x801DBB7Cu: goto label_801DBB7C;
    case 0x801DBB80u: goto label_801DBB80;
    case 0x801DBB84u: goto label_801DBB84;
    case 0x801DBB88u: goto label_801DBB88;
    case 0x801DBB8Cu: goto label_801DBB8C;
    case 0x801DBB90u: goto label_801DBB90;
    case 0x801DBB94u: goto label_801DBB94;
    case 0x801DBB98u: goto label_801DBB98;
    case 0x801DBB9Cu: goto label_801DBB9C;
    case 0x801DBBA0u: goto label_801DBBA0;
    case 0x801DBBA4u: goto label_801DBBA4;
    case 0x801DBBA8u: goto label_801DBBA8;
    case 0x801DBBACu: goto label_801DBBAC;
    case 0x801DBBB0u: goto label_801DBBB0;
    case 0x801DBBB4u: goto label_801DBBB4;
    case 0x801DBBB8u: goto label_801DBBB8;
    case 0x801DBBBCu: goto label_801DBBBC;
    case 0x801DBBC0u: goto label_801DBBC0;
    case 0x801DBBC4u: goto label_801DBBC4;
    case 0x801DBBC8u: goto label_801DBBC8;
    case 0x801DBBCCu: goto label_801DBBCC;
    case 0x801DBBD0u: goto label_801DBBD0;
    case 0x801DBBD4u: goto label_801DBBD4;
    case 0x801DBBD8u: goto label_801DBBD8;
    case 0x801DBBDCu: goto label_801DBBDC;
    case 0x801DBBE0u: goto label_801DBBE0;
    case 0x801DBBE4u: goto label_801DBBE4;
    case 0x801DBBE8u: goto label_801DBBE8;
    case 0x801DBBECu: goto label_801DBBEC;
    case 0x801DBBF0u: goto label_801DBBF0;
    case 0x801DBBF4u: goto label_801DBBF4;
    case 0x801DBBF8u: goto label_801DBBF8;
    case 0x801DBBFCu: goto label_801DBBFC;
    case 0x801DBC00u: goto label_801DBC00;
    case 0x801DBC04u: goto label_801DBC04;
    case 0x801DBC08u: goto label_801DBC08;
    case 0x801DBC0Cu: goto label_801DBC0C;
    case 0x801DBC10u: goto label_801DBC10;
    case 0x801DBC14u: goto label_801DBC14;
    case 0x801DBC18u: goto label_801DBC18;
    case 0x801DBC1Cu: goto label_801DBC1C;
    case 0x801DBC20u: goto label_801DBC20;
    case 0x801DBC24u: goto label_801DBC24;
    case 0x801DBC28u: goto label_801DBC28;
    case 0x801DBC2Cu: goto label_801DBC2C;
    case 0x801DBC30u: goto label_801DBC30;
    case 0x801DBC34u: goto label_801DBC34;
    case 0x801DBC38u: goto label_801DBC38;
    case 0x801DBC3Cu: goto label_801DBC3C;
    case 0x801DBC40u: goto label_801DBC40;
    case 0x801DBC44u: goto label_801DBC44;
    case 0x801DBC48u: goto label_801DBC48;
    case 0x801DBC4Cu: goto label_801DBC4C;
    case 0x801DBC50u: goto label_801DBC50;
    case 0x801DBC54u: goto label_801DBC54;
    case 0x801DBC58u: goto label_801DBC58;
    case 0x801DBC5Cu: goto label_801DBC5C;
    case 0x801DBC60u: goto label_801DBC60;
    case 0x801DBC64u: goto label_801DBC64;
    case 0x801DBC68u: goto label_801DBC68;
    case 0x801DBC6Cu: goto label_801DBC6C;
    case 0x801DBC70u: goto label_801DBC70;
    case 0x801DBC74u: goto label_801DBC74;
    case 0x801DBC78u: goto label_801DBC78;
    case 0x801DBC7Cu: goto label_801DBC7C;
    case 0x801DBC80u: goto label_801DBC80;
    case 0x801DBC84u: goto label_801DBC84;
    case 0x801DBC88u: goto label_801DBC88;
    case 0x801DBC8Cu: goto label_801DBC8C;
    case 0x801DBC90u: goto label_801DBC90;
    case 0x801DBC94u: goto label_801DBC94;
    case 0x801DBC98u: goto label_801DBC98;
    case 0x801DBC9Cu: goto label_801DBC9C;
    case 0x801DBCA0u: goto label_801DBCA0;
    case 0x801DBCA4u: goto label_801DBCA4;
    case 0x801DBCA8u: goto label_801DBCA8;
    case 0x801DBCACu: goto label_801DBCAC;
    case 0x801DBCB0u: goto label_801DBCB0;
    case 0x801DBCB4u: goto label_801DBCB4;
    case 0x801DBCB8u: goto label_801DBCB8;
    case 0x801DBCBCu: goto label_801DBCBC;
    case 0x801DBCC0u: goto label_801DBCC0;
    case 0x801DBCC4u: goto label_801DBCC4;
    case 0x801DBCC8u: goto label_801DBCC8;
    case 0x801DBCCCu: goto label_801DBCCC;
    case 0x801DBCD0u: goto label_801DBCD0;
    case 0x801DBCD4u: goto label_801DBCD4;
    case 0x801DBCD8u: goto label_801DBCD8;
    case 0x801DBCDCu: goto label_801DBCDC;
    case 0x801DBCE0u: goto label_801DBCE0;
    case 0x801DBCE4u: goto label_801DBCE4;
    case 0x801DBCE8u: goto label_801DBCE8;
    case 0x801DBCECu: goto label_801DBCEC;
    case 0x801DBCF0u: goto label_801DBCF0;
    case 0x801DBCF4u: goto label_801DBCF4;
    case 0x801DBCF8u: goto label_801DBCF8;
    case 0x801DBCFCu: goto label_801DBCFC;
    case 0x801DBD00u: goto label_801DBD00;
    case 0x801DBD04u: goto label_801DBD04;
    case 0x801DBD08u: goto label_801DBD08;
    case 0x801DBD0Cu: goto label_801DBD0C;
    case 0x801DBD10u: goto label_801DBD10;
    case 0x801DBD14u: goto label_801DBD14;
    case 0x801DBD18u: goto label_801DBD18;
    case 0x801DBD1Cu: goto label_801DBD1C;
    case 0x801DBD20u: goto label_801DBD20;
    case 0x801DBD24u: goto label_801DBD24;
    case 0x801DBD28u: goto label_801DBD28;
    case 0x801DBD2Cu: goto label_801DBD2C;
    case 0x801DBD30u: goto label_801DBD30;
    case 0x801DBD34u: goto label_801DBD34;
    case 0x801DBD38u: goto label_801DBD38;
    case 0x801DBD3Cu: goto label_801DBD3C;
    case 0x801DBD40u: goto label_801DBD40;
    case 0x801DBD44u: goto label_801DBD44;
    case 0x801DBD48u: goto label_801DBD48;
    case 0x801DBD4Cu: goto label_801DBD4C;
    case 0x801DBD50u: goto label_801DBD50;
    case 0x801DBD54u: goto label_801DBD54;
    case 0x801DBD58u: goto label_801DBD58;
    case 0x801DBD5Cu: goto label_801DBD5C;
    case 0x801DBD60u: goto label_801DBD60;
    case 0x801DBD64u: goto label_801DBD64;
    case 0x801DBD68u: goto label_801DBD68;
    case 0x801DBD6Cu: goto label_801DBD6C;
    case 0x801DBD70u: goto label_801DBD70;
    case 0x801DBD74u: goto label_801DBD74;
    case 0x801DBD78u: goto label_801DBD78;
    case 0x801DBD7Cu: goto label_801DBD7C;
    case 0x801DBD80u: goto label_801DBD80;
    case 0x801DBD84u: goto label_801DBD84;
    case 0x801DBD88u: goto label_801DBD88;
    case 0x801DBD8Cu: goto label_801DBD8C;
    case 0x801DBD90u: goto label_801DBD90;
    case 0x801DBD94u: goto label_801DBD94;
    case 0x801DBD98u: goto label_801DBD98;
    case 0x801DBD9Cu: goto label_801DBD9C;
    case 0x801DBDA0u: goto label_801DBDA0;
    case 0x801DBDA4u: goto label_801DBDA4;
    case 0x801DBDA8u: goto label_801DBDA8;
    case 0x801DBDACu: goto label_801DBDAC;
    case 0x801DBDB0u: goto label_801DBDB0;
    case 0x801DBDB4u: goto label_801DBDB4;
    case 0x801DBDB8u: goto label_801DBDB8;
    case 0x801DBDBCu: goto label_801DBDBC;
    case 0x801DBDC0u: goto label_801DBDC0;
    case 0x801DBDC4u: goto label_801DBDC4;
    case 0x801DBDC8u: goto label_801DBDC8;
    case 0x801DBDCCu: goto label_801DBDCC;
    case 0x801DBDD0u: goto label_801DBDD0;
    case 0x801DBDD4u: goto label_801DBDD4;
    case 0x801DBDD8u: goto label_801DBDD8;
    case 0x801DBDDCu: goto label_801DBDDC;
    case 0x801DBDE0u: goto label_801DBDE0;
    case 0x801DBDE4u: goto label_801DBDE4;
    case 0x801DBDE8u: goto label_801DBDE8;
    case 0x801DBDECu: goto label_801DBDEC;
    case 0x801DBDF0u: goto label_801DBDF0;
    case 0x801DBDF4u: goto label_801DBDF4;
    case 0x801DBDF8u: goto label_801DBDF8;
    case 0x801DBDFCu: goto label_801DBDFC;
    case 0x801DBE00u: goto label_801DBE00;
    case 0x801DBE04u: goto label_801DBE04;
    case 0x801DBE08u: goto label_801DBE08;
    case 0x801DBE0Cu: goto label_801DBE0C;
    case 0x801DBE10u: goto label_801DBE10;
    case 0x801DBE14u: goto label_801DBE14;
    case 0x801DBE18u: goto label_801DBE18;
    case 0x801DBE1Cu: goto label_801DBE1C;
    case 0x801DBE20u: goto label_801DBE20;
    case 0x801DBE24u: goto label_801DBE24;
    case 0x801DBE28u: goto label_801DBE28;
    case 0x801DBE2Cu: goto label_801DBE2C;
    case 0x801DBE30u: goto label_801DBE30;
    case 0x801DBE34u: goto label_801DBE34;
    case 0x801DBE38u: goto label_801DBE38;
    case 0x801DBE3Cu: goto label_801DBE3C;
    case 0x801DBE40u: goto label_801DBE40;
    case 0x801DBE44u: goto label_801DBE44;
    case 0x801DBE48u: goto label_801DBE48;
    case 0x801DBE4Cu: goto label_801DBE4C;
    case 0x801DBE50u: goto label_801DBE50;
    case 0x801DBE54u: goto label_801DBE54;
    case 0x801DBE58u: goto label_801DBE58;
    case 0x801DBE5Cu: goto label_801DBE5C;
    case 0x801DBE60u: goto label_801DBE60;
    case 0x801DBE64u: goto label_801DBE64;
    case 0x801DBE68u: goto label_801DBE68;
    case 0x801DBE6Cu: goto label_801DBE6C;
    case 0x801DBE70u: goto label_801DBE70;
    case 0x801DBE74u: goto label_801DBE74;
    case 0x801DBE78u: goto label_801DBE78;
    case 0x801DBE7Cu: goto label_801DBE7C;
    case 0x801DBE80u: goto label_801DBE80;
    case 0x801DBE84u: goto label_801DBE84;
    case 0x801DBE88u: goto label_801DBE88;
    case 0x801DBE8Cu: goto label_801DBE8C;
    case 0x801DBE90u: goto label_801DBE90;
    case 0x801DBE94u: goto label_801DBE94;
    case 0x801DBE98u: goto label_801DBE98;
    case 0x801DBE9Cu: goto label_801DBE9C;
    case 0x801DBEA0u: goto label_801DBEA0;
    case 0x801DBEA4u: goto label_801DBEA4;
    case 0x801DBEA8u: goto label_801DBEA8;
    case 0x801DBEACu: goto label_801DBEAC;
    case 0x801DBEB0u: goto label_801DBEB0;
    case 0x801DBEB4u: goto label_801DBEB4;
    case 0x801DBEB8u: goto label_801DBEB8;
    case 0x801DBEBCu: goto label_801DBEBC;
    case 0x801DBEC0u: goto label_801DBEC0;
    case 0x801DBEC4u: goto label_801DBEC4;
    case 0x801DBEC8u: goto label_801DBEC8;
    case 0x801DBECCu: goto label_801DBECC;
    case 0x801DBED0u: goto label_801DBED0;
    case 0x801DBED4u: goto label_801DBED4;
    case 0x801DBED8u: goto label_801DBED8;
    case 0x801DBEDCu: goto label_801DBEDC;
    case 0x801DBEE0u: goto label_801DBEE0;
    case 0x801DBEE4u: goto label_801DBEE4;
    case 0x801DBEE8u: goto label_801DBEE8;
    case 0x801DBEECu: goto label_801DBEEC;
    case 0x801DBEF0u: goto label_801DBEF0;
    case 0x801DBEF4u: goto label_801DBEF4;
    case 0x801DBEF8u: goto label_801DBEF8;
    case 0x801DBEFCu: goto label_801DBEFC;
    case 0x801DBF00u: goto label_801DBF00;
    case 0x801DBF04u: goto label_801DBF04;
    case 0x801DBF08u: goto label_801DBF08;
    case 0x801DBF0Cu: goto label_801DBF0C;
    case 0x801DBF10u: goto label_801DBF10;
    case 0x801DBF14u: goto label_801DBF14;
    case 0x801DBF18u: goto label_801DBF18;
    case 0x801DBF1Cu: goto label_801DBF1C;
    case 0x801DBF20u: goto label_801DBF20;
    case 0x801DBF24u: goto label_801DBF24;
    case 0x801DBF28u: goto label_801DBF28;
    case 0x801DBF2Cu: goto label_801DBF2C;
    case 0x801DBF30u: goto label_801DBF30;
    case 0x801DBF34u: goto label_801DBF34;
    case 0x801DBF38u: goto label_801DBF38;
    case 0x801DBF3Cu: goto label_801DBF3C;
    case 0x801DBF40u: goto label_801DBF40;
    case 0x801DBF44u: goto label_801DBF44;
    case 0x801DBF48u: goto label_801DBF48;
    case 0x801DBF4Cu: goto label_801DBF4C;
    case 0x801DBF50u: goto label_801DBF50;
    case 0x801DBF54u: goto label_801DBF54;
    case 0x801DBF58u: goto label_801DBF58;
    case 0x801DBF5Cu: goto label_801DBF5C;
    case 0x801DBF60u: goto label_801DBF60;
    case 0x801DBF64u: goto label_801DBF64;
    case 0x801DBF68u: goto label_801DBF68;
    case 0x801DBF6Cu: goto label_801DBF6C;
    case 0x801DBF70u: goto label_801DBF70;
    case 0x801DBF74u: goto label_801DBF74;
    case 0x801DBF78u: goto label_801DBF78;
    case 0x801DBF7Cu: goto label_801DBF7C;
    case 0x801DBF80u: goto label_801DBF80;
    case 0x801DBF84u: goto label_801DBF84;
    case 0x801DBF88u: goto label_801DBF88;
    case 0x801DBF8Cu: goto label_801DBF8C;
    case 0x801DBF90u: goto label_801DBF90;
    case 0x801DBF94u: goto label_801DBF94;
    case 0x801DBF98u: goto label_801DBF98;
    case 0x801DBF9Cu: goto label_801DBF9C;
    case 0x801DBFA0u: goto label_801DBFA0;
    case 0x801DBFA4u: goto label_801DBFA4;
    case 0x801DBFA8u: goto label_801DBFA8;
    case 0x801DBFACu: goto label_801DBFAC;
    case 0x801DBFB0u: goto label_801DBFB0;
    case 0x801DBFB4u: goto label_801DBFB4;
    case 0x801DBFB8u: goto label_801DBFB8;
    case 0x801DBFBCu: goto label_801DBFBC;
    case 0x801DBFC0u: goto label_801DBFC0;
    case 0x801DBFC4u: goto label_801DBFC4;
    case 0x801DBFC8u: goto label_801DBFC8;
    case 0x801DBFCCu: goto label_801DBFCC;
    case 0x801DBFD0u: goto label_801DBFD0;
    case 0x801DBFD4u: goto label_801DBFD4;
    case 0x801DBFD8u: goto label_801DBFD8;
    case 0x801DBFDCu: goto label_801DBFDC;
    case 0x801DBFE0u: goto label_801DBFE0;
    case 0x801DBFE4u: goto label_801DBFE4;
    case 0x801DBFE8u: goto label_801DBFE8;
    case 0x801DBFECu: goto label_801DBFEC;
    case 0x801DBFF0u: goto label_801DBFF0;
    case 0x801DBFF4u: goto label_801DBFF4;
    case 0x801DBFF8u: goto label_801DBFF8;
    case 0x801DBFFCu: goto label_801DBFFC;
    case 0x801DC000u: goto label_801DC000;
    case 0x801DC004u: goto label_801DC004;
    case 0x801DC008u: goto label_801DC008;
    case 0x801DC00Cu: goto label_801DC00C;
    case 0x801DC010u: goto label_801DC010;
    case 0x801DC014u: goto label_801DC014;
    case 0x801DC018u: goto label_801DC018;
    case 0x801DC01Cu: goto label_801DC01C;
    case 0x801DC020u: goto label_801DC020;
    case 0x801DC024u: goto label_801DC024;
    case 0x801DC028u: goto label_801DC028;
    case 0x801DC02Cu: goto label_801DC02C;
    case 0x801DC030u: goto label_801DC030;
    case 0x801DC034u: goto label_801DC034;
    case 0x801DC038u: goto label_801DC038;
    case 0x801DC03Cu: goto label_801DC03C;
    case 0x801DC040u: goto label_801DC040;
    case 0x801DC044u: goto label_801DC044;
    case 0x801DC048u: goto label_801DC048;
    case 0x801DC04Cu: goto label_801DC04C;
    case 0x801DC050u: goto label_801DC050;
    case 0x801DC054u: goto label_801DC054;
    case 0x801DC058u: goto label_801DC058;
    case 0x801DC05Cu: goto label_801DC05C;
    case 0x801DC060u: goto label_801DC060;
    case 0x801DC064u: goto label_801DC064;
    case 0x801DC068u: goto label_801DC068;
    case 0x801DC06Cu: goto label_801DC06C;
    case 0x801DC070u: goto label_801DC070;
    case 0x801DC074u: goto label_801DC074;
    case 0x801DC078u: goto label_801DC078;
    case 0x801DC07Cu: goto label_801DC07C;
    case 0x801DC080u: goto label_801DC080;
    case 0x801DC084u: goto label_801DC084;
    case 0x801DC088u: goto label_801DC088;
    case 0x801DC08Cu: goto label_801DC08C;
    case 0x801DC090u: goto label_801DC090;
    case 0x801DC094u: goto label_801DC094;
    case 0x801DC098u: goto label_801DC098;
    case 0x801DC09Cu: goto label_801DC09C;
    case 0x801DC0A0u: goto label_801DC0A0;
    case 0x801DC0A4u: goto label_801DC0A4;
    case 0x801DC0A8u: goto label_801DC0A8;
    case 0x801DC0ACu: goto label_801DC0AC;
    case 0x801DC0B0u: goto label_801DC0B0;
    case 0x801DC0B4u: goto label_801DC0B4;
    case 0x801DC0B8u: goto label_801DC0B8;
    case 0x801DC0BCu: goto label_801DC0BC;
    case 0x801DC0C0u: goto label_801DC0C0;
    case 0x801DC0C4u: goto label_801DC0C4;
    case 0x801DC0C8u: goto label_801DC0C8;
    case 0x801DC0CCu: goto label_801DC0CC;
    case 0x801DC0D0u: goto label_801DC0D0;
    case 0x801DC0D4u: goto label_801DC0D4;
    case 0x801DC0D8u: goto label_801DC0D8;
    case 0x801DC0DCu: goto label_801DC0DC;
    case 0x801DC0E0u: goto label_801DC0E0;
    case 0x801DC0E4u: goto label_801DC0E4;
    case 0x801DC0E8u: goto label_801DC0E8;
    case 0x801DC0ECu: goto label_801DC0EC;
    case 0x801DC0F0u: goto label_801DC0F0;
    case 0x801DC0F4u: goto label_801DC0F4;
    case 0x801DC0F8u: goto label_801DC0F8;
    case 0x801DC0FCu: goto label_801DC0FC;
    case 0x801DC100u: goto label_801DC100;
    case 0x801DC104u: goto label_801DC104;
    case 0x801DC108u: goto label_801DC108;
    case 0x801DC10Cu: goto label_801DC10C;
    case 0x801DC110u: goto label_801DC110;
    case 0x801DC114u: goto label_801DC114;
    case 0x801DC118u: goto label_801DC118;
    case 0x801DC11Cu: goto label_801DC11C;
    case 0x801DC120u: goto label_801DC120;
    case 0x801DC124u: goto label_801DC124;
    case 0x801DC128u: goto label_801DC128;
    case 0x801DC12Cu: goto label_801DC12C;
    case 0x801DC130u: goto label_801DC130;
    case 0x801DC134u: goto label_801DC134;
    case 0x801DC138u: goto label_801DC138;
    case 0x801DC13Cu: goto label_801DC13C;
    case 0x801DC140u: goto label_801DC140;
    case 0x801DC144u: goto label_801DC144;
    case 0x801DC148u: goto label_801DC148;
    case 0x801DC14Cu: goto label_801DC14C;
    case 0x801DC150u: goto label_801DC150;
    case 0x801DC154u: goto label_801DC154;
    case 0x801DC158u: goto label_801DC158;
    case 0x801DC15Cu: goto label_801DC15C;
    case 0x801DC160u: goto label_801DC160;
    case 0x801DC164u: goto label_801DC164;
    case 0x801DC168u: goto label_801DC168;
    case 0x801DC16Cu: goto label_801DC16C;
    case 0x801DC170u: goto label_801DC170;
    case 0x801DC174u: goto label_801DC174;
    case 0x801DC178u: goto label_801DC178;
    case 0x801DC17Cu: goto label_801DC17C;
    case 0x801DC180u: goto label_801DC180;
    case 0x801DC184u: goto label_801DC184;
    case 0x801DC188u: goto label_801DC188;
    case 0x801DC18Cu: goto label_801DC18C;
    case 0x801DC190u: goto label_801DC190;
    case 0x801DC194u: goto label_801DC194;
    case 0x801DC198u: goto label_801DC198;
    case 0x801DC19Cu: goto label_801DC19C;
    case 0x801DC1A0u: goto label_801DC1A0;
    case 0x801DC1A4u: goto label_801DC1A4;
    case 0x801DC1A8u: goto label_801DC1A8;
    case 0x801DC1ACu: goto label_801DC1AC;
    case 0x801DC1B0u: goto label_801DC1B0;
    case 0x801DC1B4u: goto label_801DC1B4;
    case 0x801DC1B8u: goto label_801DC1B8;
    case 0x801DC1BCu: goto label_801DC1BC;
    case 0x801DC1C0u: goto label_801DC1C0;
    case 0x801DC1C4u: goto label_801DC1C4;
    case 0x801DC1C8u: goto label_801DC1C8;
    case 0x801DC1CCu: goto label_801DC1CC;
    case 0x801DC1D0u: goto label_801DC1D0;
    case 0x801DC1D4u: goto label_801DC1D4;
    case 0x801DC1D8u: goto label_801DC1D8;
    case 0x801DC1DCu: goto label_801DC1DC;
    case 0x801DC1E0u: goto label_801DC1E0;
    case 0x801DC1E4u: goto label_801DC1E4;
    case 0x801DC1E8u: goto label_801DC1E8;
    case 0x801DC1ECu: goto label_801DC1EC;
    case 0x801DC1F0u: goto label_801DC1F0;
    case 0x801DC1F4u: goto label_801DC1F4;
    case 0x801DC1F8u: goto label_801DC1F8;
    case 0x801DC1FCu: goto label_801DC1FC;
    case 0x801DC200u: goto label_801DC200;
    case 0x801DC204u: goto label_801DC204;
    case 0x801DC208u: goto label_801DC208;
    case 0x801DC20Cu: goto label_801DC20C;
    case 0x801DC210u: goto label_801DC210;
    case 0x801DC214u: goto label_801DC214;
    case 0x801DC218u: goto label_801DC218;
    case 0x801DC21Cu: goto label_801DC21C;
    case 0x801DC220u: goto label_801DC220;
    case 0x801DC224u: goto label_801DC224;
    case 0x801DC228u: goto label_801DC228;
    case 0x801DC22Cu: goto label_801DC22C;
    case 0x801DC230u: goto label_801DC230;
    case 0x801DC234u: goto label_801DC234;
    case 0x801DC238u: goto label_801DC238;
    case 0x801DC23Cu: goto label_801DC23C;
    case 0x801DC240u: goto label_801DC240;
    case 0x801DC244u: goto label_801DC244;
    case 0x801DC248u: goto label_801DC248;
    case 0x801DC24Cu: goto label_801DC24C;
    case 0x801DC250u: goto label_801DC250;
    case 0x801DC254u: goto label_801DC254;
    case 0x801DC258u: goto label_801DC258;
    case 0x801DC25Cu: goto label_801DC25C;
    case 0x801DC260u: goto label_801DC260;
    case 0x801DC264u: goto label_801DC264;
    case 0x801DC268u: goto label_801DC268;
    case 0x801DC26Cu: goto label_801DC26C;
    case 0x801DC270u: goto label_801DC270;
    case 0x801DC274u: goto label_801DC274;
    case 0x801DC278u: goto label_801DC278;
    case 0x801DC27Cu: goto label_801DC27C;
    case 0x801DC280u: goto label_801DC280;
    case 0x801DC284u: goto label_801DC284;
    case 0x801DC288u: goto label_801DC288;
    case 0x801DC28Cu: goto label_801DC28C;
    case 0x801DC290u: goto label_801DC290;
    case 0x801DC294u: goto label_801DC294;
    case 0x801DC298u: goto label_801DC298;
    case 0x801DC29Cu: goto label_801DC29C;
    case 0x801DC2A0u: goto label_801DC2A0;
    case 0x801DC2A4u: goto label_801DC2A4;
    case 0x801DC2A8u: goto label_801DC2A8;
    case 0x801DC2ACu: goto label_801DC2AC;
    case 0x801DC2B0u: goto label_801DC2B0;
    case 0x801DC2B4u: goto label_801DC2B4;
    case 0x801DC2B8u: goto label_801DC2B8;
    case 0x801DC2BCu: goto label_801DC2BC;
    case 0x801DC2C0u: goto label_801DC2C0;
    case 0x801DC2C4u: goto label_801DC2C4;
    case 0x801DC2C8u: goto label_801DC2C8;
    case 0x801DC2CCu: goto label_801DC2CC;
    case 0x801DC2D0u: goto label_801DC2D0;
    case 0x801DC2D4u: goto label_801DC2D4;
    case 0x801DC2D8u: goto label_801DC2D8;
    case 0x801DC2DCu: goto label_801DC2DC;
    case 0x801DC2E0u: goto label_801DC2E0;
    case 0x801DC2E4u: goto label_801DC2E4;
    case 0x801DC2E8u: goto label_801DC2E8;
    case 0x801DC2ECu: goto label_801DC2EC;
    case 0x801DC2F0u: goto label_801DC2F0;
    case 0x801DC2F4u: goto label_801DC2F4;
    case 0x801DC2F8u: goto label_801DC2F8;
    case 0x801DC2FCu: goto label_801DC2FC;
    case 0x801DC300u: goto label_801DC300;
    case 0x801DC304u: goto label_801DC304;
    case 0x801DC308u: goto label_801DC308;
    case 0x801DC30Cu: goto label_801DC30C;
    case 0x801DC310u: goto label_801DC310;
    case 0x801DC314u: goto label_801DC314;
    case 0x801DC318u: goto label_801DC318;
    case 0x801DC31Cu: goto label_801DC31C;
    case 0x801DC320u: goto label_801DC320;
    case 0x801DC324u: goto label_801DC324;
    case 0x801DC328u: goto label_801DC328;
    case 0x801DC32Cu: goto label_801DC32C;
    case 0x801DC330u: goto label_801DC330;
    case 0x801DC334u: goto label_801DC334;
    case 0x801DC338u: goto label_801DC338;
    case 0x801DC33Cu: goto label_801DC33C;
    case 0x801DC340u: goto label_801DC340;
    case 0x801DC344u: goto label_801DC344;
    case 0x801DC348u: goto label_801DC348;
    case 0x801DC34Cu: goto label_801DC34C;
    case 0x801DC350u: goto label_801DC350;
    case 0x801DC354u: goto label_801DC354;
    case 0x801DC358u: goto label_801DC358;
    case 0x801DC35Cu: goto label_801DC35C;
    case 0x801DC360u: goto label_801DC360;
    case 0x801DC364u: goto label_801DC364;
    case 0x801DC368u: goto label_801DC368;
    case 0x801DC36Cu: goto label_801DC36C;
    case 0x801DC370u: goto label_801DC370;
    case 0x801DC374u: goto label_801DC374;
    case 0x801DC378u: goto label_801DC378;
    case 0x801DC37Cu: goto label_801DC37C;
    case 0x801DC380u: goto label_801DC380;
    case 0x801DC384u: goto label_801DC384;
    case 0x801DC388u: goto label_801DC388;
    case 0x801DC38Cu: goto label_801DC38C;
    case 0x801DC390u: goto label_801DC390;
    case 0x801DC394u: goto label_801DC394;
    case 0x801DC398u: goto label_801DC398;
    case 0x801DC39Cu: goto label_801DC39C;
    case 0x801DC3A0u: goto label_801DC3A0;
    case 0x801DC3A4u: goto label_801DC3A4;
    case 0x801DC3A8u: goto label_801DC3A8;
    case 0x801DC3ACu: goto label_801DC3AC;
    case 0x801DC3B0u: goto label_801DC3B0;
    case 0x801DC3B4u: goto label_801DC3B4;
    case 0x801DC3B8u: goto label_801DC3B8;
    case 0x801DC3BCu: goto label_801DC3BC;
    case 0x801DC3C0u: goto label_801DC3C0;
    case 0x801DC3C4u: goto label_801DC3C4;
    case 0x801DC3C8u: goto label_801DC3C8;
    case 0x801DC3CCu: goto label_801DC3CC;
    case 0x801DC3D0u: goto label_801DC3D0;
    case 0x801DC3D4u: goto label_801DC3D4;
    case 0x801DC3D8u: goto label_801DC3D8;
    case 0x801DC3DCu: goto label_801DC3DC;
    case 0x801DC3E0u: goto label_801DC3E0;
    case 0x801DC3E4u: goto label_801DC3E4;
    case 0x801DC3E8u: goto label_801DC3E8;
    case 0x801DC3ECu: goto label_801DC3EC;
    case 0x801DC3F0u: goto label_801DC3F0;
    case 0x801DC3F4u: goto label_801DC3F4;
    case 0x801DC3F8u: goto label_801DC3F8;
    case 0x801DC3FCu: goto label_801DC3FC;
    case 0x801DC400u: goto label_801DC400;
    case 0x801DC404u: goto label_801DC404;
    case 0x801DC408u: goto label_801DC408;
    case 0x801DC40Cu: goto label_801DC40C;
    case 0x801DC410u: goto label_801DC410;
    case 0x801DC414u: goto label_801DC414;
    case 0x801DC418u: goto label_801DC418;
    case 0x801DC41Cu: goto label_801DC41C;
    case 0x801DC420u: goto label_801DC420;
    case 0x801DC424u: goto label_801DC424;
    case 0x801DC428u: goto label_801DC428;
    case 0x801DC42Cu: goto label_801DC42C;
    case 0x801DC430u: goto label_801DC430;
    case 0x801DC434u: goto label_801DC434;
    case 0x801DC438u: goto label_801DC438;
    case 0x801DC43Cu: goto label_801DC43C;
    case 0x801DC440u: goto label_801DC440;
    case 0x801DC444u: goto label_801DC444;
    case 0x801DC448u: goto label_801DC448;
    case 0x801DC44Cu: goto label_801DC44C;
    case 0x801DC450u: goto label_801DC450;
    case 0x801DC454u: goto label_801DC454;
    case 0x801DC458u: goto label_801DC458;
    case 0x801DC45Cu: goto label_801DC45C;
    case 0x801DC460u: goto label_801DC460;
    case 0x801DC464u: goto label_801DC464;
    case 0x801DC468u: goto label_801DC468;
    case 0x801DC46Cu: goto label_801DC46C;
    case 0x801DC470u: goto label_801DC470;
    case 0x801DC474u: goto label_801DC474;
    case 0x801DC478u: goto label_801DC478;
    case 0x801DC47Cu: goto label_801DC47C;
    case 0x801DC480u: goto label_801DC480;
    case 0x801DC484u: goto label_801DC484;
    case 0x801DC488u: goto label_801DC488;
    case 0x801DC48Cu: goto label_801DC48C;
    case 0x801DC490u: goto label_801DC490;
    case 0x801DC494u: goto label_801DC494;
    case 0x801DC498u: goto label_801DC498;
    case 0x801DC49Cu: goto label_801DC49C;
    case 0x801DC4A0u: goto label_801DC4A0;
    case 0x801DC4A4u: goto label_801DC4A4;
    case 0x801DC4A8u: goto label_801DC4A8;
    case 0x801DC4ACu: goto label_801DC4AC;
    case 0x801DC4B0u: goto label_801DC4B0;
    case 0x801DC4B4u: goto label_801DC4B4;
    case 0x801DC4B8u: goto label_801DC4B8;
    case 0x801DC4BCu: goto label_801DC4BC;
    case 0x801DC4C0u: goto label_801DC4C0;
    case 0x801DC4C4u: goto label_801DC4C4;
    case 0x801DC4C8u: goto label_801DC4C8;
    case 0x801DC4CCu: goto label_801DC4CC;
    case 0x801DC4D0u: goto label_801DC4D0;
    case 0x801DC4D4u: goto label_801DC4D4;
    case 0x801DC4D8u: goto label_801DC4D8;
    case 0x801DC4DCu: goto label_801DC4DC;
    case 0x801DC4E0u: goto label_801DC4E0;
    case 0x801DC4E4u: goto label_801DC4E4;
    case 0x801DC4E8u: goto label_801DC4E8;
    case 0x801DC4ECu: goto label_801DC4EC;
    case 0x801DC4F0u: goto label_801DC4F0;
    case 0x801DC4F4u: goto label_801DC4F4;
    case 0x801DC4F8u: goto label_801DC4F8;
    case 0x801DC4FCu: goto label_801DC4FC;
    case 0x801DC500u: goto label_801DC500;
    case 0x801DC504u: goto label_801DC504;
    case 0x801DC508u: goto label_801DC508;
    case 0x801DC50Cu: goto label_801DC50C;
    case 0x801DC510u: goto label_801DC510;
    case 0x801DC514u: goto label_801DC514;
    case 0x801DC518u: goto label_801DC518;
    case 0x801DC51Cu: goto label_801DC51C;
    case 0x801DC520u: goto label_801DC520;
    case 0x801DC524u: goto label_801DC524;
    case 0x801DC528u: goto label_801DC528;
    case 0x801DC52Cu: goto label_801DC52C;
    case 0x801DC530u: goto label_801DC530;
    case 0x801DC534u: goto label_801DC534;
    case 0x801DC538u: goto label_801DC538;
    case 0x801DC53Cu: goto label_801DC53C;
    case 0x801DC540u: goto label_801DC540;
    case 0x801DC544u: goto label_801DC544;
    case 0x801DC548u: goto label_801DC548;
    case 0x801DC54Cu: goto label_801DC54C;
    case 0x801DC550u: goto label_801DC550;
    case 0x801DC554u: goto label_801DC554;
    case 0x801DC558u: goto label_801DC558;
    case 0x801DC55Cu: goto label_801DC55C;
    case 0x801DC560u: goto label_801DC560;
    case 0x801DC564u: goto label_801DC564;
    case 0x801DC568u: goto label_801DC568;
    case 0x801DC56Cu: goto label_801DC56C;
    case 0x801DC570u: goto label_801DC570;
    case 0x801DC574u: goto label_801DC574;
    case 0x801DC578u: goto label_801DC578;
    case 0x801DC57Cu: goto label_801DC57C;
    case 0x801DC580u: goto label_801DC580;
    case 0x801DC584u: goto label_801DC584;
    case 0x801DC588u: goto label_801DC588;
    case 0x801DC58Cu: goto label_801DC58C;
    case 0x801DC590u: goto label_801DC590;
    case 0x801DC594u: goto label_801DC594;
    case 0x801DC598u: goto label_801DC598;
    case 0x801DC59Cu: goto label_801DC59C;
    case 0x801DC5A0u: goto label_801DC5A0;
    case 0x801DC5A4u: goto label_801DC5A4;
    case 0x801DC5A8u: goto label_801DC5A8;
    case 0x801DC5ACu: goto label_801DC5AC;
    case 0x801DC5B0u: goto label_801DC5B0;
    case 0x801DC5B4u: goto label_801DC5B4;
    case 0x801DC5B8u: goto label_801DC5B8;
    case 0x801DC5BCu: goto label_801DC5BC;
    case 0x801DC5C0u: goto label_801DC5C0;
    case 0x801DC5C4u: goto label_801DC5C4;
    case 0x801DC5C8u: goto label_801DC5C8;
    case 0x801DC5CCu: goto label_801DC5CC;
    case 0x801DC5D0u: goto label_801DC5D0;
    case 0x801DC5D4u: goto label_801DC5D4;
    case 0x801DC5D8u: goto label_801DC5D8;
    case 0x801DC5DCu: goto label_801DC5DC;
    case 0x801DC5E0u: goto label_801DC5E0;
    case 0x801DC5E4u: goto label_801DC5E4;
    case 0x801DC5E8u: goto label_801DC5E8;
    case 0x801DC5ECu: goto label_801DC5EC;
    case 0x801DC5F0u: goto label_801DC5F0;
    case 0x801DC5F4u: goto label_801DC5F4;
    case 0x801DC5F8u: goto label_801DC5F8;
    case 0x801DC5FCu: goto label_801DC5FC;
    case 0x801DC600u: goto label_801DC600;
    case 0x801DC604u: goto label_801DC604;
    case 0x801DC608u: goto label_801DC608;
    case 0x801DC60Cu: goto label_801DC60C;
    case 0x801DC610u: goto label_801DC610;
    case 0x801DC614u: goto label_801DC614;
    case 0x801DC618u: goto label_801DC618;
    case 0x801DC61Cu: goto label_801DC61C;
    case 0x801DC620u: goto label_801DC620;
    case 0x801DC624u: goto label_801DC624;
    case 0x801DC628u: goto label_801DC628;
    case 0x801DC62Cu: goto label_801DC62C;
    case 0x801DC630u: goto label_801DC630;
    case 0x801DC634u: goto label_801DC634;
    case 0x801DC638u: goto label_801DC638;
    case 0x801DC63Cu: goto label_801DC63C;
    case 0x801DC640u: goto label_801DC640;
    case 0x801DC644u: goto label_801DC644;
    case 0x801DC648u: goto label_801DC648;
    case 0x801DC64Cu: goto label_801DC64C;
    case 0x801DC650u: goto label_801DC650;
    case 0x801DC654u: goto label_801DC654;
    case 0x801DC658u: goto label_801DC658;
    case 0x801DC65Cu: goto label_801DC65C;
    case 0x801DC660u: goto label_801DC660;
    case 0x801DC664u: goto label_801DC664;
    case 0x801DC668u: goto label_801DC668;
    case 0x801DC66Cu: goto label_801DC66C;
    case 0x801DC670u: goto label_801DC670;
    case 0x801DC674u: goto label_801DC674;
    case 0x801DC678u: goto label_801DC678;
    case 0x801DC67Cu: goto label_801DC67C;
    case 0x801DC680u: goto label_801DC680;
    case 0x801DC684u: goto label_801DC684;
    case 0x801DC688u: goto label_801DC688;
    case 0x801DC68Cu: goto label_801DC68C;
    case 0x801DC690u: goto label_801DC690;
    case 0x801DC694u: goto label_801DC694;
    case 0x801DC698u: goto label_801DC698;
    case 0x801DC69Cu: goto label_801DC69C;
    case 0x801DC6A0u: goto label_801DC6A0;
    case 0x801DC6A4u: goto label_801DC6A4;
    case 0x801DC6A8u: goto label_801DC6A8;
    case 0x801DC6ACu: goto label_801DC6AC;
    case 0x801DC6B0u: goto label_801DC6B0;
    case 0x801DC6B4u: goto label_801DC6B4;
    case 0x801DC6B8u: goto label_801DC6B8;
    case 0x801DC6BCu: goto label_801DC6BC;
    case 0x801DC6C0u: goto label_801DC6C0;
    case 0x801DC6C4u: goto label_801DC6C4;
    case 0x801DC6C8u: goto label_801DC6C8;
    case 0x801DC6CCu: goto label_801DC6CC;
    case 0x801DC6D0u: goto label_801DC6D0;
    case 0x801DC6D4u: goto label_801DC6D4;
    case 0x801DC6D8u: goto label_801DC6D8;
    case 0x801DC6DCu: goto label_801DC6DC;
    case 0x801DC6E0u: goto label_801DC6E0;
    case 0x801DC6E4u: goto label_801DC6E4;
    case 0x801DC6E8u: goto label_801DC6E8;
    case 0x801DC6ECu: goto label_801DC6EC;
    case 0x801DC6F0u: goto label_801DC6F0;
    case 0x801DC6F4u: goto label_801DC6F4;
    case 0x801DC6F8u: goto label_801DC6F8;
    case 0x801DC6FCu: goto label_801DC6FC;
    case 0x801DC700u: goto label_801DC700;
    case 0x801DC704u: goto label_801DC704;
    case 0x801DC708u: goto label_801DC708;
    case 0x801DC70Cu: goto label_801DC70C;
    case 0x801DC710u: goto label_801DC710;
    case 0x801DC714u: goto label_801DC714;
    case 0x801DC718u: goto label_801DC718;
    case 0x801DC71Cu: goto label_801DC71C;
    case 0x801DC720u: goto label_801DC720;
    case 0x801DC724u: goto label_801DC724;
    case 0x801DC728u: goto label_801DC728;
    case 0x801DC72Cu: goto label_801DC72C;
    case 0x801DC730u: goto label_801DC730;
    case 0x801DC734u: goto label_801DC734;
    case 0x801DC738u: goto label_801DC738;
    case 0x801DC73Cu: goto label_801DC73C;
    case 0x801DC740u: goto label_801DC740;
    case 0x801DC744u: goto label_801DC744;
    case 0x801DC748u: goto label_801DC748;
    case 0x801DC74Cu: goto label_801DC74C;
    case 0x801DC750u: goto label_801DC750;
    case 0x801DC754u: goto label_801DC754;
    case 0x801DC758u: goto label_801DC758;
    case 0x801DC75Cu: goto label_801DC75C;
    case 0x801DC760u: goto label_801DC760;
    case 0x801DC764u: goto label_801DC764;
    case 0x801DC768u: goto label_801DC768;
    case 0x801DC76Cu: goto label_801DC76C;
    case 0x801DC770u: goto label_801DC770;
    case 0x801DC774u: goto label_801DC774;
    case 0x801DC778u: goto label_801DC778;
    case 0x801DC77Cu: goto label_801DC77C;
    case 0x801DC780u: goto label_801DC780;
    case 0x801DC784u: goto label_801DC784;
    case 0x801DC788u: goto label_801DC788;
    case 0x801DC78Cu: goto label_801DC78C;
    case 0x801DC790u: goto label_801DC790;
    case 0x801DC794u: goto label_801DC794;
    case 0x801DC798u: goto label_801DC798;
    case 0x801DC79Cu: goto label_801DC79C;
    case 0x801DC7A0u: goto label_801DC7A0;
    case 0x801DC7A4u: goto label_801DC7A4;
    case 0x801DC7A8u: goto label_801DC7A8;
    case 0x801DC7ACu: goto label_801DC7AC;
    case 0x801DC7B0u: goto label_801DC7B0;
    case 0x801DC7B4u: goto label_801DC7B4;
    case 0x801DC7B8u: goto label_801DC7B8;
    case 0x801DC7BCu: goto label_801DC7BC;
    case 0x801DC7C0u: goto label_801DC7C0;
    case 0x801DC7C4u: goto label_801DC7C4;
    case 0x801DC7C8u: goto label_801DC7C8;
    case 0x801DC7CCu: goto label_801DC7CC;
    case 0x801DC7D0u: goto label_801DC7D0;
    case 0x801DC7D4u: goto label_801DC7D4;
    case 0x801DC7D8u: goto label_801DC7D8;
    case 0x801DC7DCu: goto label_801DC7DC;
    case 0x801DC7E0u: goto label_801DC7E0;
    case 0x801DC7E4u: goto label_801DC7E4;
    case 0x801DC7E8u: goto label_801DC7E8;
    case 0x801DC7ECu: goto label_801DC7EC;
    case 0x801DC7F0u: goto label_801DC7F0;
    case 0x801DC7F4u: goto label_801DC7F4;
    case 0x801DC7F8u: goto label_801DC7F8;
    case 0x801DC7FCu: goto label_801DC7FC;
    case 0x801DC800u: goto label_801DC800;
    case 0x801DC804u: goto label_801DC804;
    case 0x801DC808u: goto label_801DC808;
    case 0x801DC80Cu: goto label_801DC80C;
    case 0x801DC810u: goto label_801DC810;
    case 0x801DC814u: goto label_801DC814;
    case 0x801DC818u: goto label_801DC818;
    case 0x801DC81Cu: goto label_801DC81C;
    case 0x801DC820u: goto label_801DC820;
    case 0x801DC824u: goto label_801DC824;
    case 0x801DC828u: goto label_801DC828;
    case 0x801DC82Cu: goto label_801DC82C;
    case 0x801DC830u: goto label_801DC830;
    case 0x801DC834u: goto label_801DC834;
    case 0x801DC838u: goto label_801DC838;
    case 0x801DC83Cu: goto label_801DC83C;
    case 0x801DC840u: goto label_801DC840;
    case 0x801DC844u: goto label_801DC844;
    case 0x801DC848u: goto label_801DC848;
    case 0x801DC84Cu: goto label_801DC84C;
    case 0x801DC850u: goto label_801DC850;
    case 0x801DC854u: goto label_801DC854;
    case 0x801DC858u: goto label_801DC858;
    case 0x801DC85Cu: goto label_801DC85C;
    case 0x801DC860u: goto label_801DC860;
    case 0x801DC864u: goto label_801DC864;
    case 0x801DC868u: goto label_801DC868;
    case 0x801DC86Cu: goto label_801DC86C;
    case 0x801DC870u: goto label_801DC870;
    case 0x801DC874u: goto label_801DC874;
    case 0x801DC878u: goto label_801DC878;
    case 0x801DC87Cu: goto label_801DC87C;
    case 0x801DC880u: goto label_801DC880;
    case 0x801DC884u: goto label_801DC884;
    case 0x801DC888u: goto label_801DC888;
    case 0x801DC88Cu: goto label_801DC88C;
    case 0x801DC890u: goto label_801DC890;
    case 0x801DC894u: goto label_801DC894;
    case 0x801DC898u: goto label_801DC898;
    case 0x801DC89Cu: goto label_801DC89C;
    case 0x801DC8A0u: goto label_801DC8A0;
    case 0x801DC8A4u: goto label_801DC8A4;
    case 0x801DC8A8u: goto label_801DC8A8;
    case 0x801DC8ACu: goto label_801DC8AC;
    case 0x801DC8B0u: goto label_801DC8B0;
    case 0x801DC8B4u: goto label_801DC8B4;
    case 0x801DC8B8u: goto label_801DC8B8;
    case 0x801DC8BCu: goto label_801DC8BC;
    case 0x801DC8C0u: goto label_801DC8C0;
    case 0x801DC8C4u: goto label_801DC8C4;
    case 0x801DC8C8u: goto label_801DC8C8;
    case 0x801DC8CCu: goto label_801DC8CC;
    case 0x801DC8D0u: goto label_801DC8D0;
    case 0x801DC8D4u: goto label_801DC8D4;
    case 0x801DC8D8u: goto label_801DC8D8;
    case 0x801DC8DCu: goto label_801DC8DC;
    case 0x801DC8E0u: goto label_801DC8E0;
    case 0x801DC8E4u: goto label_801DC8E4;
    case 0x801DC8E8u: goto label_801DC8E8;
    case 0x801DC8ECu: goto label_801DC8EC;
    case 0x801DC8F0u: goto label_801DC8F0;
    case 0x801DC8F4u: goto label_801DC8F4;
    case 0x801DC8F8u: goto label_801DC8F8;
    case 0x801DC8FCu: goto label_801DC8FC;
    case 0x801DC900u: goto label_801DC900;
    case 0x801DC904u: goto label_801DC904;
    case 0x801DC908u: goto label_801DC908;
    case 0x801DC90Cu: goto label_801DC90C;
    case 0x801DC910u: goto label_801DC910;
    case 0x801DC914u: goto label_801DC914;
    case 0x801DC918u: goto label_801DC918;
    case 0x801DC91Cu: goto label_801DC91C;
    case 0x801DC920u: goto label_801DC920;
    case 0x801DC924u: goto label_801DC924;
    case 0x801DC928u: goto label_801DC928;
    case 0x801DC92Cu: goto label_801DC92C;
    case 0x801DC930u: goto label_801DC930;
    case 0x801DC934u: goto label_801DC934;
    case 0x801DC938u: goto label_801DC938;
    case 0x801DC93Cu: goto label_801DC93C;
    case 0x801DC940u: goto label_801DC940;
    case 0x801DC944u: goto label_801DC944;
    case 0x801DC948u: goto label_801DC948;
    case 0x801DC94Cu: goto label_801DC94C;
    case 0x801DC950u: goto label_801DC950;
    case 0x801DC954u: goto label_801DC954;
    case 0x801DC958u: goto label_801DC958;
    case 0x801DC95Cu: goto label_801DC95C;
    case 0x801DC960u: goto label_801DC960;
    case 0x801DC964u: goto label_801DC964;
    case 0x801DC968u: goto label_801DC968;
    case 0x801DC96Cu: goto label_801DC96C;
    case 0x801DC970u: goto label_801DC970;
    case 0x801DC974u: goto label_801DC974;
    case 0x801DC978u: goto label_801DC978;
    case 0x801DC97Cu: goto label_801DC97C;
    case 0x801DC980u: goto label_801DC980;
    case 0x801DC984u: goto label_801DC984;
    case 0x801DC988u: goto label_801DC988;
    case 0x801DC98Cu: goto label_801DC98C;
    case 0x801DC990u: goto label_801DC990;
    case 0x801DC994u: goto label_801DC994;
    case 0x801DC998u: goto label_801DC998;
    case 0x801DC99Cu: goto label_801DC99C;
    case 0x801DC9A0u: goto label_801DC9A0;
    case 0x801DC9A4u: goto label_801DC9A4;
    case 0x801DC9A8u: goto label_801DC9A8;
    case 0x801DC9ACu: goto label_801DC9AC;
    case 0x801DC9B0u: goto label_801DC9B0;
    case 0x801DC9B4u: goto label_801DC9B4;
    case 0x801DC9B8u: goto label_801DC9B8;
    case 0x801DC9BCu: goto label_801DC9BC;
    case 0x801DC9C0u: goto label_801DC9C0;
    case 0x801DC9C4u: goto label_801DC9C4;
    case 0x801DC9C8u: goto label_801DC9C8;
    case 0x801DC9CCu: goto label_801DC9CC;
    case 0x801DC9D0u: goto label_801DC9D0;
    case 0x801DC9D4u: goto label_801DC9D4;
    case 0x801DC9D8u: goto label_801DC9D8;
    case 0x801DC9DCu: goto label_801DC9DC;
    case 0x801DC9E0u: goto label_801DC9E0;
    case 0x801DC9E4u: goto label_801DC9E4;
    case 0x801DC9E8u: goto label_801DC9E8;
    case 0x801DC9ECu: goto label_801DC9EC;
    case 0x801DC9F0u: goto label_801DC9F0;
    case 0x801DC9F4u: goto label_801DC9F4;
    case 0x801DC9F8u: goto label_801DC9F8;
    case 0x801DC9FCu: goto label_801DC9FC;
    case 0x801DCA00u: goto label_801DCA00;
    case 0x801DCA04u: goto label_801DCA04;
    case 0x801DCA08u: goto label_801DCA08;
    case 0x801DCA0Cu: goto label_801DCA0C;
    case 0x801DCA10u: goto label_801DCA10;
    case 0x801DCA14u: goto label_801DCA14;
    case 0x801DCA18u: goto label_801DCA18;
    case 0x801DCA1Cu: goto label_801DCA1C;
    case 0x801DCA20u: goto label_801DCA20;
    case 0x801DCA24u: goto label_801DCA24;
    case 0x801DCA28u: goto label_801DCA28;
    case 0x801DCA2Cu: goto label_801DCA2C;
    case 0x801DCA30u: goto label_801DCA30;
    case 0x801DCA34u: goto label_801DCA34;
    case 0x801DCA38u: goto label_801DCA38;
    case 0x801DCA3Cu: goto label_801DCA3C;
    case 0x801DCA40u: goto label_801DCA40;
    case 0x801DCA44u: goto label_801DCA44;
    case 0x801DCA48u: goto label_801DCA48;
    case 0x801DCA4Cu: goto label_801DCA4C;
    case 0x801DCA50u: goto label_801DCA50;
    case 0x801DCA54u: goto label_801DCA54;
    case 0x801DCA58u: goto label_801DCA58;
    case 0x801DCA5Cu: goto label_801DCA5C;
    case 0x801DCA60u: goto label_801DCA60;
    case 0x801DCA64u: goto label_801DCA64;
    case 0x801DCA68u: goto label_801DCA68;
    case 0x801DCA6Cu: goto label_801DCA6C;
    case 0x801DCA70u: goto label_801DCA70;
    case 0x801DCA74u: goto label_801DCA74;
    case 0x801DCA78u: goto label_801DCA78;
    case 0x801DCA7Cu: goto label_801DCA7C;
    case 0x801DCA80u: goto label_801DCA80;
    case 0x801DCA84u: goto label_801DCA84;
    case 0x801DCA88u: goto label_801DCA88;
    case 0x801DCA8Cu: goto label_801DCA8C;
    case 0x801DCA90u: goto label_801DCA90;
    case 0x801DCA94u: goto label_801DCA94;
    case 0x801DCA98u: goto label_801DCA98;
    case 0x801DCA9Cu: goto label_801DCA9C;
    case 0x801DCAA0u: goto label_801DCAA0;
    case 0x801DCAA4u: goto label_801DCAA4;
    case 0x801DCAA8u: goto label_801DCAA8;
    case 0x801DCAACu: goto label_801DCAAC;
    case 0x801DCAB0u: goto label_801DCAB0;
    case 0x801DCAB4u: goto label_801DCAB4;
    case 0x801DCAB8u: goto label_801DCAB8;
    case 0x801DCABCu: goto label_801DCABC;
    case 0x801DCAC0u: goto label_801DCAC0;
    case 0x801DCAC4u: goto label_801DCAC4;
    case 0x801DCAC8u: goto label_801DCAC8;
    case 0x801DCACCu: goto label_801DCACC;
    case 0x801DCAD0u: goto label_801DCAD0;
    case 0x801DCAD4u: goto label_801DCAD4;
    case 0x801DCAD8u: goto label_801DCAD8;
    case 0x801DCADCu: goto label_801DCADC;
    case 0x801DCAE0u: goto label_801DCAE0;
    case 0x801DCAE4u: goto label_801DCAE4;
    case 0x801DCAE8u: goto label_801DCAE8;
    case 0x801DCAECu: goto label_801DCAEC;
    case 0x801DCAF0u: goto label_801DCAF0;
    case 0x801DCAF4u: goto label_801DCAF4;
    case 0x801DCAF8u: goto label_801DCAF8;
    case 0x801DCAFCu: goto label_801DCAFC;
    case 0x801DCB00u: goto label_801DCB00;
    case 0x801DCB04u: goto label_801DCB04;
    case 0x801DCB08u: goto label_801DCB08;
    case 0x801DCB0Cu: goto label_801DCB0C;
    case 0x801DCB10u: goto label_801DCB10;
    case 0x801DCB14u: goto label_801DCB14;
    case 0x801DCB18u: goto label_801DCB18;
    case 0x801DCB1Cu: goto label_801DCB1C;
    case 0x801DCB20u: goto label_801DCB20;
    case 0x801DCB24u: goto label_801DCB24;
    case 0x801DCB28u: goto label_801DCB28;
    case 0x801DCB2Cu: goto label_801DCB2C;
    case 0x801DCB30u: goto label_801DCB30;
    case 0x801DCB34u: goto label_801DCB34;
    case 0x801DCB38u: goto label_801DCB38;
    case 0x801DCB3Cu: goto label_801DCB3C;
    case 0x801DCB40u: goto label_801DCB40;
    case 0x801DCB44u: goto label_801DCB44;
    case 0x801DCB48u: goto label_801DCB48;
    case 0x801DCB4Cu: goto label_801DCB4C;
    case 0x801DCB50u: goto label_801DCB50;
    case 0x801DCB54u: goto label_801DCB54;
    case 0x801DCB58u: goto label_801DCB58;
    case 0x801DCB5Cu: goto label_801DCB5C;
    case 0x801DCB60u: goto label_801DCB60;
    case 0x801DCB64u: goto label_801DCB64;
    case 0x801DCB68u: goto label_801DCB68;
    case 0x801DCB6Cu: goto label_801DCB6C;
    case 0x801DCB70u: goto label_801DCB70;
    case 0x801DCB74u: goto label_801DCB74;
    case 0x801DCB78u: goto label_801DCB78;
    case 0x801DCB7Cu: goto label_801DCB7C;
    case 0x801DCB80u: goto label_801DCB80;
    case 0x801DCB84u: goto label_801DCB84;
    case 0x801DCB88u: goto label_801DCB88;
    case 0x801DCB8Cu: goto label_801DCB8C;
    case 0x801DCB90u: goto label_801DCB90;
    case 0x801DCB94u: goto label_801DCB94;
    case 0x801DCB98u: goto label_801DCB98;
    case 0x801DCB9Cu: goto label_801DCB9C;
    case 0x801DCBA0u: goto label_801DCBA0;
    case 0x801DCBA4u: goto label_801DCBA4;
    case 0x801DCBA8u: goto label_801DCBA8;
    case 0x801DCBACu: goto label_801DCBAC;
    case 0x801DCBB0u: goto label_801DCBB0;
    case 0x801DCBB4u: goto label_801DCBB4;
    case 0x801DCBB8u: goto label_801DCBB8;
    case 0x801DCBBCu: goto label_801DCBBC;
    case 0x801DCBC0u: goto label_801DCBC0;
    case 0x801DCBC4u: goto label_801DCBC4;
    case 0x801DCBC8u: goto label_801DCBC8;
    case 0x801DCBCCu: goto label_801DCBCC;
    case 0x801DCBD0u: goto label_801DCBD0;
    case 0x801DCBD4u: goto label_801DCBD4;
    case 0x801DCBD8u: goto label_801DCBD8;
    case 0x801DCBDCu: goto label_801DCBDC;
    case 0x801DCBE0u: goto label_801DCBE0;
    case 0x801DCBE4u: goto label_801DCBE4;
    case 0x801DCBE8u: goto label_801DCBE8;
    case 0x801DCBECu: goto label_801DCBEC;
    case 0x801DCBF0u: goto label_801DCBF0;
    case 0x801DCBF4u: goto label_801DCBF4;
    case 0x801DCBF8u: goto label_801DCBF8;
    case 0x801DCBFCu: goto label_801DCBFC;
    case 0x801DCC00u: goto label_801DCC00;
    case 0x801DCC04u: goto label_801DCC04;
    case 0x801DCC08u: goto label_801DCC08;
    case 0x801DCC0Cu: goto label_801DCC0C;
    case 0x801DCC10u: goto label_801DCC10;
    case 0x801DCC14u: goto label_801DCC14;
    case 0x801DCC18u: goto label_801DCC18;
    case 0x801DCC1Cu: goto label_801DCC1C;
    case 0x801DCC20u: goto label_801DCC20;
    case 0x801DCC24u: goto label_801DCC24;
    case 0x801DCC28u: goto label_801DCC28;
    case 0x801DCC2Cu: goto label_801DCC2C;
    case 0x801DCC30u: goto label_801DCC30;
    case 0x801DCC34u: goto label_801DCC34;
    case 0x801DCC38u: goto label_801DCC38;
    case 0x801DCC3Cu: goto label_801DCC3C;
    case 0x801DCC40u: goto label_801DCC40;
    case 0x801DCC44u: goto label_801DCC44;
    case 0x801DCC48u: goto label_801DCC48;
    case 0x801DCC4Cu: goto label_801DCC4C;
    case 0x801DCC50u: goto label_801DCC50;
    case 0x801DCC54u: goto label_801DCC54;
    case 0x801DCC58u: goto label_801DCC58;
    case 0x801DCC5Cu: goto label_801DCC5C;
    case 0x801DCC60u: goto label_801DCC60;
    case 0x801DCC64u: goto label_801DCC64;
    case 0x801DCC68u: goto label_801DCC68;
    case 0x801DCC6Cu: goto label_801DCC6C;
    case 0x801DCC70u: goto label_801DCC70;
    case 0x801DCC74u: goto label_801DCC74;
    case 0x801DCC78u: goto label_801DCC78;
    case 0x801DCC7Cu: goto label_801DCC7C;
    case 0x801DCC80u: goto label_801DCC80;
    case 0x801DCC84u: goto label_801DCC84;
    case 0x801DCC88u: goto label_801DCC88;
    case 0x801DCC8Cu: goto label_801DCC8C;
    case 0x801DCC90u: goto label_801DCC90;
    case 0x801DCC94u: goto label_801DCC94;
    case 0x801DCC98u: goto label_801DCC98;
    case 0x801DCC9Cu: goto label_801DCC9C;
    case 0x801DCCA0u: goto label_801DCCA0;
    case 0x801DCCA4u: goto label_801DCCA4;
    case 0x801DCCA8u: goto label_801DCCA8;
    case 0x801DCCACu: goto label_801DCCAC;
    case 0x801DCCB0u: goto label_801DCCB0;
    case 0x801DCCB4u: goto label_801DCCB4;
    case 0x801DCCB8u: goto label_801DCCB8;
    case 0x801DCCBCu: goto label_801DCCBC;
    case 0x801DCCC0u: goto label_801DCCC0;
    case 0x801DCCC4u: goto label_801DCCC4;
    case 0x801DCCC8u: goto label_801DCCC8;
    case 0x801DCCCCu: goto label_801DCCCC;
    case 0x801DCCD0u: goto label_801DCCD0;
    case 0x801DCCD4u: goto label_801DCCD4;
    case 0x801DCCD8u: goto label_801DCCD8;
    case 0x801DCCDCu: goto label_801DCCDC;
    case 0x801DCCE0u: goto label_801DCCE0;
    case 0x801DCCE4u: goto label_801DCCE4;
    case 0x801DCCE8u: goto label_801DCCE8;
    case 0x801DCCECu: goto label_801DCCEC;
    case 0x801DCCF0u: goto label_801DCCF0;
    case 0x801DCCF4u: goto label_801DCCF4;
    case 0x801DCCF8u: goto label_801DCCF8;
    case 0x801DCCFCu: goto label_801DCCFC;
    case 0x801DCD00u: goto label_801DCD00;
    case 0x801DCD04u: goto label_801DCD04;
    case 0x801DCD08u: goto label_801DCD08;
    case 0x801DCD0Cu: goto label_801DCD0C;
    case 0x801DCD10u: goto label_801DCD10;
    case 0x801DCD14u: goto label_801DCD14;
    case 0x801DCD18u: goto label_801DCD18;
    case 0x801DCD1Cu: goto label_801DCD1C;
    case 0x801DCD20u: goto label_801DCD20;
    case 0x801DCD24u: goto label_801DCD24;
    case 0x801DCD28u: goto label_801DCD28;
    case 0x801DCD2Cu: goto label_801DCD2C;
    case 0x801DCD30u: goto label_801DCD30;
    case 0x801DCD34u: goto label_801DCD34;
    case 0x801DCD38u: goto label_801DCD38;
    case 0x801DCD3Cu: goto label_801DCD3C;
    case 0x801DCD40u: goto label_801DCD40;
    case 0x801DCD44u: goto label_801DCD44;
    case 0x801DCD48u: goto label_801DCD48;
    case 0x801DCD4Cu: goto label_801DCD4C;
    case 0x801DCD50u: goto label_801DCD50;
    case 0x801DCD54u: goto label_801DCD54;
    case 0x801DCD58u: goto label_801DCD58;
    case 0x801DCD5Cu: goto label_801DCD5C;
    case 0x801DCD60u: goto label_801DCD60;
    case 0x801DCD64u: goto label_801DCD64;
    case 0x801DCD68u: goto label_801DCD68;
    case 0x801DCD6Cu: goto label_801DCD6C;
    case 0x801DCD70u: goto label_801DCD70;
    case 0x801DCD74u: goto label_801DCD74;
    case 0x801DCD78u: goto label_801DCD78;
    case 0x801DCD7Cu: goto label_801DCD7C;
    case 0x801DCD80u: goto label_801DCD80;
    case 0x801DCD84u: goto label_801DCD84;
    case 0x801DCD88u: goto label_801DCD88;
    case 0x801DCD8Cu: goto label_801DCD8C;
    case 0x801DCD90u: goto label_801DCD90;
    case 0x801DCD94u: goto label_801DCD94;
    case 0x801DCD98u: goto label_801DCD98;
    case 0x801DCD9Cu: goto label_801DCD9C;
    case 0x801DCDA0u: goto label_801DCDA0;
    case 0x801DCDA4u: goto label_801DCDA4;
    case 0x801DCDA8u: goto label_801DCDA8;
    case 0x801DCDACu: goto label_801DCDAC;
    case 0x801DCDB0u: goto label_801DCDB0;
    case 0x801DCDB4u: goto label_801DCDB4;
    case 0x801DCDB8u: goto label_801DCDB8;
    case 0x801DCDBCu: goto label_801DCDBC;
    case 0x801DCDC0u: goto label_801DCDC0;
    case 0x801DCDC4u: goto label_801DCDC4;
    case 0x801DCDC8u: goto label_801DCDC8;
    case 0x801DCDCCu: goto label_801DCDCC;
    case 0x801DCDD0u: goto label_801DCDD0;
    case 0x801DCDD4u: goto label_801DCDD4;
    case 0x801DCDD8u: goto label_801DCDD8;
    case 0x801DCDDCu: goto label_801DCDDC;
    case 0x801DCDE0u: goto label_801DCDE0;
    case 0x801DCDE4u: goto label_801DCDE4;
    case 0x801DCDE8u: goto label_801DCDE8;
    case 0x801DCDECu: goto label_801DCDEC;
    case 0x801DCDF0u: goto label_801DCDF0;
    case 0x801DCDF4u: goto label_801DCDF4;
    case 0x801DCDF8u: goto label_801DCDF8;
    case 0x801DCDFCu: goto label_801DCDFC;
    case 0x801DCE00u: goto label_801DCE00;
    case 0x801DCE04u: goto label_801DCE04;
    case 0x801DCE08u: goto label_801DCE08;
    case 0x801DCE0Cu: goto label_801DCE0C;
    case 0x801DCE10u: goto label_801DCE10;
    case 0x801DCE14u: goto label_801DCE14;
    case 0x801DCE18u: goto label_801DCE18;
    case 0x801DCE1Cu: goto label_801DCE1C;
    case 0x801DCE20u: goto label_801DCE20;
    case 0x801DCE24u: goto label_801DCE24;
    case 0x801DCE28u: goto label_801DCE28;
    case 0x801DCE2Cu: goto label_801DCE2C;
    case 0x801DCE30u: goto label_801DCE30;
    case 0x801DCE34u: goto label_801DCE34;
    case 0x801DCE38u: goto label_801DCE38;
    case 0x801DCE3Cu: goto label_801DCE3C;
    case 0x801DCE40u: goto label_801DCE40;
    case 0x801DCE44u: goto label_801DCE44;
    case 0x801DCE48u: goto label_801DCE48;
    case 0x801DCE4Cu: goto label_801DCE4C;
    case 0x801DCE50u: goto label_801DCE50;
    case 0x801DCE54u: goto label_801DCE54;
    case 0x801DCE58u: goto label_801DCE58;
    case 0x801DCE5Cu: goto label_801DCE5C;
    case 0x801DCE60u: goto label_801DCE60;
    case 0x801DCE64u: goto label_801DCE64;
    case 0x801DCE68u: goto label_801DCE68;
    case 0x801DCE6Cu: goto label_801DCE6C;
    case 0x801DCE70u: goto label_801DCE70;
    case 0x801DCE74u: goto label_801DCE74;
    case 0x801DCE78u: goto label_801DCE78;
    case 0x801DCE7Cu: goto label_801DCE7C;
    case 0x801DCE80u: goto label_801DCE80;
    case 0x801DCE84u: goto label_801DCE84;
    case 0x801DCE88u: goto label_801DCE88;
    case 0x801DCE8Cu: goto label_801DCE8C;
    case 0x801DCE90u: goto label_801DCE90;
    case 0x801DCE94u: goto label_801DCE94;
    case 0x801DCE98u: goto label_801DCE98;
    case 0x801DCE9Cu: goto label_801DCE9C;
    case 0x801DCEA0u: goto label_801DCEA0;
    case 0x801DCEA4u: goto label_801DCEA4;
    case 0x801DCEA8u: goto label_801DCEA8;
    case 0x801DCEACu: goto label_801DCEAC;
    case 0x801DCEB0u: goto label_801DCEB0;
    case 0x801DCEB4u: goto label_801DCEB4;
    case 0x801DCEB8u: goto label_801DCEB8;
    case 0x801DCEBCu: goto label_801DCEBC;
    case 0x801DCEC0u: goto label_801DCEC0;
    case 0x801DCEC4u: goto label_801DCEC4;
    case 0x801DCEC8u: goto label_801DCEC8;
    case 0x801DCECCu: goto label_801DCECC;
    case 0x801DCED0u: goto label_801DCED0;
    case 0x801DCED4u: goto label_801DCED4;
    case 0x801DCED8u: goto label_801DCED8;
    case 0x801DCEDCu: goto label_801DCEDC;
    case 0x801DCEE0u: goto label_801DCEE0;
    case 0x801DCEE4u: goto label_801DCEE4;
    case 0x801DCEE8u: goto label_801DCEE8;
    case 0x801DCEECu: goto label_801DCEEC;
    case 0x801DCEF0u: goto label_801DCEF0;
    case 0x801DCEF4u: goto label_801DCEF4;
    case 0x801DCEF8u: goto label_801DCEF8;
    case 0x801DCEFCu: goto label_801DCEFC;
    case 0x801DCF00u: goto label_801DCF00;
    case 0x801DCF04u: goto label_801DCF04;
    case 0x801DCF08u: goto label_801DCF08;
    case 0x801DCF0Cu: goto label_801DCF0C;
    case 0x801DCF10u: goto label_801DCF10;
    case 0x801DCF14u: goto label_801DCF14;
    case 0x801DCF18u: goto label_801DCF18;
    case 0x801DCF1Cu: goto label_801DCF1C;
    case 0x801DCF20u: goto label_801DCF20;
    case 0x801DCF24u: goto label_801DCF24;
    case 0x801DCF28u: goto label_801DCF28;
    case 0x801DCF2Cu: goto label_801DCF2C;
    case 0x801DCF30u: goto label_801DCF30;
    case 0x801DCF34u: goto label_801DCF34;
    case 0x801DCF38u: goto label_801DCF38;
    case 0x801DCF3Cu: goto label_801DCF3C;
    case 0x801DCF40u: goto label_801DCF40;
    case 0x801DCF44u: goto label_801DCF44;
    case 0x801DCF48u: goto label_801DCF48;
    case 0x801DCF4Cu: goto label_801DCF4C;
    case 0x801DCF50u: goto label_801DCF50;
    case 0x801DCF54u: goto label_801DCF54;
    case 0x801DCF58u: goto label_801DCF58;
    case 0x801DCF5Cu: goto label_801DCF5C;
    case 0x801DCF60u: goto label_801DCF60;
    case 0x801DCF64u: goto label_801DCF64;
    case 0x801DCF68u: goto label_801DCF68;
    case 0x801DCF6Cu: goto label_801DCF6C;
    case 0x801DCF70u: goto label_801DCF70;
    case 0x801DCF74u: goto label_801DCF74;
    case 0x801DCF78u: goto label_801DCF78;
    case 0x801DCF7Cu: goto label_801DCF7C;
    case 0x801DCF80u: goto label_801DCF80;
    case 0x801DCF84u: goto label_801DCF84;
    case 0x801DCF88u: goto label_801DCF88;
    case 0x801DCF8Cu: goto label_801DCF8C;
    case 0x801DCF90u: goto label_801DCF90;
    case 0x801DCF94u: goto label_801DCF94;
    case 0x801DCF98u: goto label_801DCF98;
    case 0x801DCF9Cu: goto label_801DCF9C;
    case 0x801DCFA0u: goto label_801DCFA0;
    case 0x801DCFA4u: goto label_801DCFA4;
    case 0x801DCFA8u: goto label_801DCFA8;
    case 0x801DCFACu: goto label_801DCFAC;
    case 0x801DCFB0u: goto label_801DCFB0;
    case 0x801DCFB4u: goto label_801DCFB4;
    case 0x801DCFB8u: goto label_801DCFB8;
    case 0x801DCFBCu: goto label_801DCFBC;
    case 0x801DCFC0u: goto label_801DCFC0;
    case 0x801DCFC4u: goto label_801DCFC4;
    case 0x801DCFC8u: goto label_801DCFC8;
    case 0x801DCFCCu: goto label_801DCFCC;
    case 0x801DCFD0u: goto label_801DCFD0;
    case 0x801DCFD4u: goto label_801DCFD4;
    case 0x801DCFD8u: goto label_801DCFD8;
    case 0x801DCFDCu: goto label_801DCFDC;
    case 0x801DCFE0u: goto label_801DCFE0;
    case 0x801DCFE4u: goto label_801DCFE4;
    case 0x801DCFE8u: goto label_801DCFE8;
    case 0x801DCFECu: goto label_801DCFEC;
    case 0x801DCFF0u: goto label_801DCFF0;
    case 0x801DCFF4u: goto label_801DCFF4;
    case 0x801DCFF8u: goto label_801DCFF8;
    case 0x801DCFFCu: goto label_801DCFFC;
    case 0x801DD000u: goto label_801DD000;
    case 0x801DD004u: goto label_801DD004;
    case 0x801DD008u: goto label_801DD008;
    case 0x801DD00Cu: goto label_801DD00C;
    case 0x801DD010u: goto label_801DD010;
    case 0x801DD014u: goto label_801DD014;
    case 0x801DD018u: goto label_801DD018;
    case 0x801DD01Cu: goto label_801DD01C;
    case 0x801DD020u: goto label_801DD020;
    case 0x801DD024u: goto label_801DD024;
    case 0x801DD028u: goto label_801DD028;
    case 0x801DD02Cu: goto label_801DD02C;
    case 0x801DD030u: goto label_801DD030;
    case 0x801DD034u: goto label_801DD034;
    case 0x801DD038u: goto label_801DD038;
    case 0x801DD03Cu: goto label_801DD03C;
    case 0x801DD040u: goto label_801DD040;
    case 0x801DD044u: goto label_801DD044;
    case 0x801DD048u: goto label_801DD048;
    case 0x801DD04Cu: goto label_801DD04C;
    case 0x801DD050u: goto label_801DD050;
    case 0x801DD054u: goto label_801DD054;
    case 0x801DD058u: goto label_801DD058;
    case 0x801DD05Cu: goto label_801DD05C;
    case 0x801DD060u: goto label_801DD060;
    case 0x801DD064u: goto label_801DD064;
    case 0x801DD068u: goto label_801DD068;
    case 0x801DD06Cu: goto label_801DD06C;
    case 0x801DD070u: goto label_801DD070;
    case 0x801DD074u: goto label_801DD074;
    case 0x801DD078u: goto label_801DD078;
    case 0x801DD07Cu: goto label_801DD07C;
    case 0x801DD080u: goto label_801DD080;
    case 0x801DD084u: goto label_801DD084;
    case 0x801DD088u: goto label_801DD088;
    case 0x801DD08Cu: goto label_801DD08C;
    case 0x801DD090u: goto label_801DD090;
    case 0x801DD094u: goto label_801DD094;
    case 0x801DD098u: goto label_801DD098;
    case 0x801DD09Cu: goto label_801DD09C;
    case 0x801DD0A0u: goto label_801DD0A0;
    case 0x801DD0A4u: goto label_801DD0A4;
    case 0x801DD0A8u: goto label_801DD0A8;
    case 0x801DD0ACu: goto label_801DD0AC;
    case 0x801DD0B0u: goto label_801DD0B0;
    case 0x801DD0B4u: goto label_801DD0B4;
    case 0x801DD0B8u: goto label_801DD0B8;
    case 0x801DD0BCu: goto label_801DD0BC;
    case 0x801DD0C0u: goto label_801DD0C0;
    case 0x801DD0C4u: goto label_801DD0C4;
    case 0x801DD0C8u: goto label_801DD0C8;
    case 0x801DD0CCu: goto label_801DD0CC;
    case 0x801DD0D0u: goto label_801DD0D0;
    case 0x801DD0D4u: goto label_801DD0D4;
    case 0x801DD0D8u: goto label_801DD0D8;
    case 0x801DD0DCu: goto label_801DD0DC;
    case 0x801DD0E0u: goto label_801DD0E0;
    case 0x801DD0E4u: goto label_801DD0E4;
    case 0x801DD0E8u: goto label_801DD0E8;
    case 0x801DD0ECu: goto label_801DD0EC;
    case 0x801DD0F0u: goto label_801DD0F0;
    case 0x801DD0F4u: goto label_801DD0F4;
    case 0x801DD0F8u: goto label_801DD0F8;
    case 0x801DD0FCu: goto label_801DD0FC;
    case 0x801DD100u: goto label_801DD100;
    case 0x801DD104u: goto label_801DD104;
    case 0x801DD108u: goto label_801DD108;
    case 0x801DD10Cu: goto label_801DD10C;
    case 0x801DD110u: goto label_801DD110;
    case 0x801DD114u: goto label_801DD114;
    case 0x801DD118u: goto label_801DD118;
    case 0x801DD11Cu: goto label_801DD11C;
    case 0x801DD120u: goto label_801DD120;
    case 0x801DD124u: goto label_801DD124;
    case 0x801DD128u: goto label_801DD128;
    case 0x801DD12Cu: goto label_801DD12C;
    case 0x801DD130u: goto label_801DD130;
    case 0x801DD134u: goto label_801DD134;
    case 0x801DD138u: goto label_801DD138;
    case 0x801DD13Cu: goto label_801DD13C;
    case 0x801DD140u: goto label_801DD140;
    case 0x801DD144u: goto label_801DD144;
    case 0x801DD148u: goto label_801DD148;
    case 0x801DD14Cu: goto label_801DD14C;
    case 0x801DD150u: goto label_801DD150;
    case 0x801DD154u: goto label_801DD154;
    case 0x801DD158u: goto label_801DD158;
    case 0x801DD15Cu: goto label_801DD15C;
    case 0x801DD160u: goto label_801DD160;
    case 0x801DD164u: goto label_801DD164;
    case 0x801DD168u: goto label_801DD168;
    case 0x801DD16Cu: goto label_801DD16C;
    case 0x801DD170u: goto label_801DD170;
    case 0x801DD174u: goto label_801DD174;
    case 0x801DD178u: goto label_801DD178;
    case 0x801DD17Cu: goto label_801DD17C;
    case 0x801DD180u: goto label_801DD180;
    case 0x801DD184u: goto label_801DD184;
    case 0x801DD188u: goto label_801DD188;
    case 0x801DD18Cu: goto label_801DD18C;
    case 0x801DD190u: goto label_801DD190;
    case 0x801DD194u: goto label_801DD194;
    case 0x801DD198u: goto label_801DD198;
    case 0x801DD19Cu: goto label_801DD19C;
    case 0x801DD1A0u: goto label_801DD1A0;
    case 0x801DD1A4u: goto label_801DD1A4;
    case 0x801DD1A8u: goto label_801DD1A8;
    case 0x801DD1ACu: goto label_801DD1AC;
    case 0x801DD1B0u: goto label_801DD1B0;
    case 0x801DD1B4u: goto label_801DD1B4;
    case 0x801DD1B8u: goto label_801DD1B8;
    case 0x801DD1BCu: goto label_801DD1BC;
    case 0x801DD1C0u: goto label_801DD1C0;
    case 0x801DD1C4u: goto label_801DD1C4;
    case 0x801DD1C8u: goto label_801DD1C8;
    case 0x801DD1CCu: goto label_801DD1CC;
    case 0x801DD1D0u: goto label_801DD1D0;
    case 0x801DD1D4u: goto label_801DD1D4;
    case 0x801DD1D8u: goto label_801DD1D8;
    case 0x801DD1DCu: goto label_801DD1DC;
    case 0x801DD1E0u: goto label_801DD1E0;
    case 0x801DD1E4u: goto label_801DD1E4;
    case 0x801DD1E8u: goto label_801DD1E8;
    case 0x801DD1ECu: goto label_801DD1EC;
    case 0x801DD1F0u: goto label_801DD1F0;
    case 0x801DD1F4u: goto label_801DD1F4;
    case 0x801DD1F8u: goto label_801DD1F8;
    case 0x801DD1FCu: goto label_801DD1FC;
    case 0x801DD200u: goto label_801DD200;
    case 0x801DD204u: goto label_801DD204;
    case 0x801DD208u: goto label_801DD208;
    case 0x801DD20Cu: goto label_801DD20C;
    case 0x801DD210u: goto label_801DD210;
    case 0x801DD214u: goto label_801DD214;
    case 0x801DD218u: goto label_801DD218;
    case 0x801DD21Cu: goto label_801DD21C;
    case 0x801DD220u: goto label_801DD220;
    case 0x801DD224u: goto label_801DD224;
    case 0x801DD228u: goto label_801DD228;
    case 0x801DD22Cu: goto label_801DD22C;
    case 0x801DD230u: goto label_801DD230;
    case 0x801DD234u: goto label_801DD234;
    case 0x801DD238u: goto label_801DD238;
    case 0x801DD23Cu: goto label_801DD23C;
    case 0x801DD240u: goto label_801DD240;
    case 0x801DD244u: goto label_801DD244;
    case 0x801DD248u: goto label_801DD248;
    case 0x801DD24Cu: goto label_801DD24C;
    case 0x801DD250u: goto label_801DD250;
    case 0x801DD254u: goto label_801DD254;
    case 0x801DD258u: goto label_801DD258;
    case 0x801DD25Cu: goto label_801DD25C;
    case 0x801DD260u: goto label_801DD260;
    case 0x801DD264u: goto label_801DD264;
    case 0x801DD268u: goto label_801DD268;
    case 0x801DD26Cu: goto label_801DD26C;
    case 0x801DD270u: goto label_801DD270;
    case 0x801DD274u: goto label_801DD274;
    case 0x801DD278u: goto label_801DD278;
    case 0x801DD27Cu: goto label_801DD27C;
    case 0x801DD280u: goto label_801DD280;
    case 0x801DD284u: goto label_801DD284;
    case 0x801DD288u: goto label_801DD288;
    case 0x801DD28Cu: goto label_801DD28C;
    case 0x801DD290u: goto label_801DD290;
    case 0x801DD294u: goto label_801DD294;
    case 0x801DD298u: goto label_801DD298;
    case 0x801DD29Cu: goto label_801DD29C;
    case 0x801DD2A0u: goto label_801DD2A0;
    case 0x801DD2A4u: goto label_801DD2A4;
    case 0x801DD2A8u: goto label_801DD2A8;
    case 0x801DD2ACu: goto label_801DD2AC;
    case 0x801DD2B0u: goto label_801DD2B0;
    case 0x801DD2B4u: goto label_801DD2B4;
    case 0x801DD2B8u: goto label_801DD2B8;
    case 0x801DD2BCu: goto label_801DD2BC;
    case 0x801DD2C0u: goto label_801DD2C0;
    case 0x801DD2C4u: goto label_801DD2C4;
    case 0x801DD2C8u: goto label_801DD2C8;
    case 0x801DD2CCu: goto label_801DD2CC;
    case 0x801DD2D0u: goto label_801DD2D0;
    case 0x801DD2D4u: goto label_801DD2D4;
    case 0x801DD2D8u: goto label_801DD2D8;
    case 0x801DD2DCu: goto label_801DD2DC;
    case 0x801DD2E0u: goto label_801DD2E0;
    case 0x801DD2E4u: goto label_801DD2E4;
    case 0x801DD2E8u: goto label_801DD2E8;
    case 0x801DD2ECu: goto label_801DD2EC;
    case 0x801DD2F0u: goto label_801DD2F0;
    case 0x801DD2F4u: goto label_801DD2F4;
    case 0x801DD2F8u: goto label_801DD2F8;
    case 0x801DD2FCu: goto label_801DD2FC;
    case 0x801DD300u: goto label_801DD300;
    case 0x801DD304u: goto label_801DD304;
    case 0x801DD308u: goto label_801DD308;
    case 0x801DD30Cu: goto label_801DD30C;
    case 0x801DD310u: goto label_801DD310;
    case 0x801DD314u: goto label_801DD314;
    case 0x801DD318u: goto label_801DD318;
    case 0x801DD31Cu: goto label_801DD31C;
    case 0x801DD320u: goto label_801DD320;
    case 0x801DD324u: goto label_801DD324;
    case 0x801DD328u: goto label_801DD328;
    case 0x801DD32Cu: goto label_801DD32C;
    case 0x801DD330u: goto label_801DD330;
    case 0x801DD334u: goto label_801DD334;
    case 0x801DD338u: goto label_801DD338;
    case 0x801DD33Cu: goto label_801DD33C;
    case 0x801DD340u: goto label_801DD340;
    case 0x801DD344u: goto label_801DD344;
    case 0x801DD348u: goto label_801DD348;
    case 0x801DD34Cu: goto label_801DD34C;
    case 0x801DD350u: goto label_801DD350;
    case 0x801DD354u: goto label_801DD354;
    case 0x801DD358u: goto label_801DD358;
    case 0x801DD35Cu: goto label_801DD35C;
    case 0x801DD360u: goto label_801DD360;
    case 0x801DD364u: goto label_801DD364;
    case 0x801DD368u: goto label_801DD368;
    case 0x801DD36Cu: goto label_801DD36C;
    case 0x801DD370u: goto label_801DD370;
    case 0x801DD374u: goto label_801DD374;
    case 0x801DD378u: goto label_801DD378;
    case 0x801DD37Cu: goto label_801DD37C;
    case 0x801DD380u: goto label_801DD380;
    case 0x801DD384u: goto label_801DD384;
    case 0x801DD388u: goto label_801DD388;
    case 0x801DD38Cu: goto label_801DD38C;
    case 0x801DD390u: goto label_801DD390;
    case 0x801DD394u: goto label_801DD394;
    case 0x801DD398u: goto label_801DD398;
    case 0x801DD39Cu: goto label_801DD39C;
    case 0x801DD3A0u: goto label_801DD3A0;
    case 0x801DD3A4u: goto label_801DD3A4;
    case 0x801DD3A8u: goto label_801DD3A8;
    case 0x801DD3ACu: goto label_801DD3AC;
    case 0x801DD3B0u: goto label_801DD3B0;
    case 0x801DD3B4u: goto label_801DD3B4;
    case 0x801DD3B8u: goto label_801DD3B8;
    case 0x801DD3BCu: goto label_801DD3BC;
    case 0x801DD3C0u: goto label_801DD3C0;
    case 0x801DD3C4u: goto label_801DD3C4;
    case 0x801DD3C8u: goto label_801DD3C8;
    case 0x801DD3CCu: goto label_801DD3CC;
    case 0x801DD3D0u: goto label_801DD3D0;
    case 0x801DD3D4u: goto label_801DD3D4;
    case 0x801DD3D8u: goto label_801DD3D8;
    case 0x801DD3DCu: goto label_801DD3DC;
    case 0x801DD3E0u: goto label_801DD3E0;
    case 0x801DD3E4u: goto label_801DD3E4;
    case 0x801DD3E8u: goto label_801DD3E8;
    case 0x801DD3ECu: goto label_801DD3EC;
    case 0x801DD3F0u: goto label_801DD3F0;
    case 0x801DD3F4u: goto label_801DD3F4;
    case 0x801DD3F8u: goto label_801DD3F8;
    case 0x801DD3FCu: goto label_801DD3FC;
    case 0x801DD400u: goto label_801DD400;
    case 0x801DD404u: goto label_801DD404;
    case 0x801DD408u: goto label_801DD408;
    case 0x801DD40Cu: goto label_801DD40C;
    case 0x801DD410u: goto label_801DD410;
    case 0x801DD414u: goto label_801DD414;
    case 0x801DD418u: goto label_801DD418;
    case 0x801DD41Cu: goto label_801DD41C;
    case 0x801DD420u: goto label_801DD420;
    case 0x801DD424u: goto label_801DD424;
    case 0x801DD428u: goto label_801DD428;
    case 0x801DD42Cu: goto label_801DD42C;
    case 0x801DD430u: goto label_801DD430;
    case 0x801DD434u: goto label_801DD434;
    case 0x801DD438u: goto label_801DD438;
    case 0x801DD43Cu: goto label_801DD43C;
    case 0x801DD440u: goto label_801DD440;
    case 0x801DD444u: goto label_801DD444;
    case 0x801DD448u: goto label_801DD448;
    case 0x801DD44Cu: goto label_801DD44C;
    case 0x801DD450u: goto label_801DD450;
    case 0x801DD454u: goto label_801DD454;
    case 0x801DD458u: goto label_801DD458;
    case 0x801DD45Cu: goto label_801DD45C;
    case 0x801DD460u: goto label_801DD460;
    case 0x801DD464u: goto label_801DD464;
    case 0x801DD468u: goto label_801DD468;
    case 0x801DD46Cu: goto label_801DD46C;
    case 0x801DD470u: goto label_801DD470;
    case 0x801DD474u: goto label_801DD474;
    case 0x801DD478u: goto label_801DD478;
    case 0x801DD47Cu: goto label_801DD47C;
    case 0x801DD480u: goto label_801DD480;
    case 0x801DD484u: goto label_801DD484;
    case 0x801DD488u: goto label_801DD488;
    case 0x801DD48Cu: goto label_801DD48C;
    case 0x801DD490u: goto label_801DD490;
    case 0x801DD494u: goto label_801DD494;
    case 0x801DD498u: goto label_801DD498;
    case 0x801DD49Cu: goto label_801DD49C;
    case 0x801DD4A0u: goto label_801DD4A0;
    case 0x801DD4A4u: goto label_801DD4A4;
    case 0x801DD4A8u: goto label_801DD4A8;
    case 0x801DD4ACu: goto label_801DD4AC;
    case 0x801DD4B0u: goto label_801DD4B0;
    case 0x801DD4B4u: goto label_801DD4B4;
    case 0x801DD4B8u: goto label_801DD4B8;
    case 0x801DD4BCu: goto label_801DD4BC;
    case 0x801DD4C0u: goto label_801DD4C0;
    case 0x801DD4C4u: goto label_801DD4C4;
    case 0x801DD4C8u: goto label_801DD4C8;
    case 0x801DD4CCu: goto label_801DD4CC;
    case 0x801DD4D0u: goto label_801DD4D0;
    case 0x801DD4D4u: goto label_801DD4D4;
    case 0x801DD4D8u: goto label_801DD4D8;
    case 0x801DD4DCu: goto label_801DD4DC;
    case 0x801DD4E0u: goto label_801DD4E0;
    case 0x801DD4E4u: goto label_801DD4E4;
    case 0x801DD4E8u: goto label_801DD4E8;
    case 0x801DD4ECu: goto label_801DD4EC;
    case 0x801DD4F0u: goto label_801DD4F0;
    case 0x801DD4F4u: goto label_801DD4F4;
    case 0x801DD4F8u: goto label_801DD4F8;
    case 0x801DD4FCu: goto label_801DD4FC;
    case 0x801DD500u: goto label_801DD500;
    case 0x801DD504u: goto label_801DD504;
    case 0x801DD508u: goto label_801DD508;
    case 0x801DD50Cu: goto label_801DD50C;
    case 0x801DD510u: goto label_801DD510;
    case 0x801DD514u: goto label_801DD514;
    case 0x801DD518u: goto label_801DD518;
    case 0x801DD51Cu: goto label_801DD51C;
    case 0x801DD520u: goto label_801DD520;
    case 0x801DD524u: goto label_801DD524;
    case 0x801DD528u: goto label_801DD528;
    case 0x801DD52Cu: goto label_801DD52C;
    case 0x801DD530u: goto label_801DD530;
    case 0x801DD534u: goto label_801DD534;
    case 0x801DD538u: goto label_801DD538;
    case 0x801DD53Cu: goto label_801DD53C;
    case 0x801DD540u: goto label_801DD540;
    case 0x801DD544u: goto label_801DD544;
    case 0x801DD548u: goto label_801DD548;
    case 0x801DD54Cu: goto label_801DD54C;
    case 0x801DD550u: goto label_801DD550;
    case 0x801DD554u: goto label_801DD554;
    case 0x801DD558u: goto label_801DD558;
    case 0x801DD55Cu: goto label_801DD55C;
    case 0x801DD560u: goto label_801DD560;
    case 0x801DD564u: goto label_801DD564;
    case 0x801DD568u: goto label_801DD568;
    case 0x801DD56Cu: goto label_801DD56C;
    case 0x801DD570u: goto label_801DD570;
    case 0x801DD574u: goto label_801DD574;
    case 0x801DD578u: goto label_801DD578;
    case 0x801DD57Cu: goto label_801DD57C;
    case 0x801DD580u: goto label_801DD580;
    case 0x801DD584u: goto label_801DD584;
    case 0x801DD588u: goto label_801DD588;
    case 0x801DD58Cu: goto label_801DD58C;
    case 0x801DD590u: goto label_801DD590;
    case 0x801DD594u: goto label_801DD594;
    case 0x801DD598u: goto label_801DD598;
    case 0x801DD59Cu: goto label_801DD59C;
    case 0x801DD5A0u: goto label_801DD5A0;
    case 0x801DD5A4u: goto label_801DD5A4;
    case 0x801DD5A8u: goto label_801DD5A8;
    case 0x801DD5ACu: goto label_801DD5AC;
    case 0x801DD5B0u: goto label_801DD5B0;
    case 0x801DD5B4u: goto label_801DD5B4;
    case 0x801DD5B8u: goto label_801DD5B8;
    case 0x801DD5BCu: goto label_801DD5BC;
    case 0x801DD5C0u: goto label_801DD5C0;
    case 0x801DD5C4u: goto label_801DD5C4;
    case 0x801DD5C8u: goto label_801DD5C8;
    case 0x801DD5CCu: goto label_801DD5CC;
    case 0x801DD5D0u: goto label_801DD5D0;
    case 0x801DD5D4u: goto label_801DD5D4;
    case 0x801DD5D8u: goto label_801DD5D8;
    case 0x801DD5DCu: goto label_801DD5DC;
    case 0x801DD5E0u: goto label_801DD5E0;
    case 0x801DD5E4u: goto label_801DD5E4;
    case 0x801DD5E8u: goto label_801DD5E8;
    case 0x801DD5ECu: goto label_801DD5EC;
    case 0x801DD5F0u: goto label_801DD5F0;
    case 0x801DD5F4u: goto label_801DD5F4;
    case 0x801DD5F8u: goto label_801DD5F8;
    case 0x801DD5FCu: goto label_801DD5FC;
    case 0x801DD600u: goto label_801DD600;
    case 0x801DD604u: goto label_801DD604;
    case 0x801DD608u: goto label_801DD608;
    case 0x801DD60Cu: goto label_801DD60C;
    case 0x801DD610u: goto label_801DD610;
    case 0x801DD614u: goto label_801DD614;
    case 0x801DD618u: goto label_801DD618;
    case 0x801DD61Cu: goto label_801DD61C;
    case 0x801DD620u: goto label_801DD620;
    case 0x801DD624u: goto label_801DD624;
    case 0x801DD628u: goto label_801DD628;
    case 0x801DD62Cu: goto label_801DD62C;
    case 0x801DD630u: goto label_801DD630;
    case 0x801DD634u: goto label_801DD634;
    case 0x801DD638u: goto label_801DD638;
    case 0x801DD63Cu: goto label_801DD63C;
    case 0x801DD640u: goto label_801DD640;
    case 0x801DD644u: goto label_801DD644;
    case 0x801DD648u: goto label_801DD648;
    case 0x801DD64Cu: goto label_801DD64C;
    case 0x801DD650u: goto label_801DD650;
    case 0x801DD654u: goto label_801DD654;
    case 0x801DD658u: goto label_801DD658;
    case 0x801DD65Cu: goto label_801DD65C;
    case 0x801DD660u: goto label_801DD660;
    case 0x801DD664u: goto label_801DD664;
    case 0x801DD668u: goto label_801DD668;
    case 0x801DD66Cu: goto label_801DD66C;
    case 0x801DD670u: goto label_801DD670;
    case 0x801DD674u: goto label_801DD674;
    case 0x801DD678u: goto label_801DD678;
    case 0x801DD67Cu: goto label_801DD67C;
    case 0x801DD680u: goto label_801DD680;
    case 0x801DD684u: goto label_801DD684;
    case 0x801DD688u: goto label_801DD688;
    case 0x801DD68Cu: goto label_801DD68C;
    case 0x801DD690u: goto label_801DD690;
    case 0x801DD694u: goto label_801DD694;
    case 0x801DD698u: goto label_801DD698;
    case 0x801DD69Cu: goto label_801DD69C;
    case 0x801DD6A0u: goto label_801DD6A0;
    case 0x801DD6A4u: goto label_801DD6A4;
    case 0x801DD6A8u: goto label_801DD6A8;
    case 0x801DD6ACu: goto label_801DD6AC;
    case 0x801DD6B0u: goto label_801DD6B0;
    case 0x801DD6B4u: goto label_801DD6B4;
    case 0x801DD6B8u: goto label_801DD6B8;
    case 0x801DD6BCu: goto label_801DD6BC;
    case 0x801DD6C0u: goto label_801DD6C0;
    case 0x801DD6C4u: goto label_801DD6C4;
    case 0x801DD6C8u: goto label_801DD6C8;
    case 0x801DD6CCu: goto label_801DD6CC;
    case 0x801DD6D0u: goto label_801DD6D0;
    case 0x801DD6D4u: goto label_801DD6D4;
    case 0x801DD6D8u: goto label_801DD6D8;
    case 0x801DD6DCu: goto label_801DD6DC;
    case 0x801DD6E0u: goto label_801DD6E0;
    case 0x801DD6E4u: goto label_801DD6E4;
    case 0x801DD6E8u: goto label_801DD6E8;
    case 0x801DD6ECu: goto label_801DD6EC;
    case 0x801DD6F0u: goto label_801DD6F0;
    case 0x801DD6F4u: goto label_801DD6F4;
    case 0x801DD6F8u: goto label_801DD6F8;
    case 0x801DD6FCu: goto label_801DD6FC;
    case 0x801DD700u: goto label_801DD700;
    case 0x801DD704u: goto label_801DD704;
    case 0x801DD708u: goto label_801DD708;
    case 0x801DD70Cu: goto label_801DD70C;
    case 0x801DD710u: goto label_801DD710;
    case 0x801DD714u: goto label_801DD714;
    case 0x801DD718u: goto label_801DD718;
    case 0x801DD71Cu: goto label_801DD71C;
    case 0x801DD720u: goto label_801DD720;
    case 0x801DD724u: goto label_801DD724;
    case 0x801DD728u: goto label_801DD728;
    case 0x801DD72Cu: goto label_801DD72C;
    case 0x801DD730u: goto label_801DD730;
    case 0x801DD734u: goto label_801DD734;
    case 0x801DD738u: goto label_801DD738;
    case 0x801DD73Cu: goto label_801DD73C;
    case 0x801DD740u: goto label_801DD740;
    case 0x801DD744u: goto label_801DD744;
    case 0x801DD748u: goto label_801DD748;
    case 0x801DD74Cu: goto label_801DD74C;
    case 0x801DD750u: goto label_801DD750;
    case 0x801DD754u: goto label_801DD754;
    case 0x801DD758u: goto label_801DD758;
    case 0x801DD75Cu: goto label_801DD75C;
    case 0x801DD760u: goto label_801DD760;
    case 0x801DD764u: goto label_801DD764;
    case 0x801DD768u: goto label_801DD768;
    case 0x801DD76Cu: goto label_801DD76C;
    case 0x801DD770u: goto label_801DD770;
    case 0x801DD774u: goto label_801DD774;
    case 0x801DD778u: goto label_801DD778;
    case 0x801DD77Cu: goto label_801DD77C;
    case 0x801DD780u: goto label_801DD780;
    case 0x801DD784u: goto label_801DD784;
    case 0x801DD788u: goto label_801DD788;
    case 0x801DD78Cu: goto label_801DD78C;
    case 0x801DD790u: goto label_801DD790;
    case 0x801DD794u: goto label_801DD794;
    case 0x801DD798u: goto label_801DD798;
    case 0x801DD79Cu: goto label_801DD79C;
    case 0x801DD7A0u: goto label_801DD7A0;
    case 0x801DD7A4u: goto label_801DD7A4;
    case 0x801DD7A8u: goto label_801DD7A8;
    case 0x801DD7ACu: goto label_801DD7AC;
    case 0x801DD7B0u: goto label_801DD7B0;
    case 0x801DD7B4u: goto label_801DD7B4;
    case 0x801DD7B8u: goto label_801DD7B8;
    case 0x801DD7BCu: goto label_801DD7BC;
    case 0x801DD7C0u: goto label_801DD7C0;
    case 0x801DD7C4u: goto label_801DD7C4;
    case 0x801DD7C8u: goto label_801DD7C8;
    case 0x801DD7CCu: goto label_801DD7CC;
    case 0x801DD7D0u: goto label_801DD7D0;
    case 0x801DD7D4u: goto label_801DD7D4;
    case 0x801DD7D8u: goto label_801DD7D8;
    case 0x801DD7DCu: goto label_801DD7DC;
    case 0x801DD7E0u: goto label_801DD7E0;
    case 0x801DD7E4u: goto label_801DD7E4;
    case 0x801DD7E8u: goto label_801DD7E8;
    case 0x801DD7ECu: goto label_801DD7EC;
    case 0x801DD7F0u: goto label_801DD7F0;
    case 0x801DD7F4u: goto label_801DD7F4;
    case 0x801DD7F8u: goto label_801DD7F8;
    case 0x801DD7FCu: goto label_801DD7FC;
    case 0x801DD800u: goto label_801DD800;
    case 0x801DD804u: goto label_801DD804;
    case 0x801DD808u: goto label_801DD808;
    case 0x801DD80Cu: goto label_801DD80C;
    case 0x801DD810u: goto label_801DD810;
    case 0x801DD814u: goto label_801DD814;
    case 0x801DD818u: goto label_801DD818;
    case 0x801DD81Cu: goto label_801DD81C;
    case 0x801DD820u: goto label_801DD820;
    case 0x801DD824u: goto label_801DD824;
    case 0x801DD828u: goto label_801DD828;
    case 0x801DD82Cu: goto label_801DD82C;
    case 0x801DD830u: goto label_801DD830;
    case 0x801DD834u: goto label_801DD834;
    case 0x801DD838u: goto label_801DD838;
    case 0x801DD83Cu: goto label_801DD83C;
    case 0x801DD840u: goto label_801DD840;
    case 0x801DD844u: goto label_801DD844;
    case 0x801DD848u: goto label_801DD848;
    case 0x801DD84Cu: goto label_801DD84C;
    case 0x801DD850u: goto label_801DD850;
    case 0x801DD854u: goto label_801DD854;
    case 0x801DD858u: goto label_801DD858;
    case 0x801DD85Cu: goto label_801DD85C;
    case 0x801DD860u: goto label_801DD860;
    case 0x801DD864u: goto label_801DD864;
    case 0x801DD868u: goto label_801DD868;
    case 0x801DD86Cu: goto label_801DD86C;
    case 0x801DD870u: goto label_801DD870;
    case 0x801DD874u: goto label_801DD874;
    case 0x801DD878u: goto label_801DD878;
    case 0x801DD87Cu: goto label_801DD87C;
    case 0x801DD880u: goto label_801DD880;
    case 0x801DD884u: goto label_801DD884;
    case 0x801DD888u: goto label_801DD888;
    case 0x801DD88Cu: goto label_801DD88C;
    case 0x801DD890u: goto label_801DD890;
    case 0x801DD894u: goto label_801DD894;
    case 0x801DD898u: goto label_801DD898;
    case 0x801DD89Cu: goto label_801DD89C;
    case 0x801DD8A0u: goto label_801DD8A0;
    case 0x801DD8A4u: goto label_801DD8A4;
    case 0x801DD8A8u: goto label_801DD8A8;
    case 0x801DD8ACu: goto label_801DD8AC;
    case 0x801DD8B0u: goto label_801DD8B0;
    case 0x801DD8B4u: goto label_801DD8B4;
    case 0x801DD8B8u: goto label_801DD8B8;
    case 0x801DD8BCu: goto label_801DD8BC;
    case 0x801DD8C0u: goto label_801DD8C0;
    case 0x801DD8C4u: goto label_801DD8C4;
    case 0x801DD8C8u: goto label_801DD8C8;
    case 0x801DD8CCu: goto label_801DD8CC;
    case 0x801DD8D0u: goto label_801DD8D0;
    case 0x801DD8D4u: goto label_801DD8D4;
    case 0x801DD8D8u: goto label_801DD8D8;
    case 0x801DD8DCu: goto label_801DD8DC;
    case 0x801DD8E0u: goto label_801DD8E0;
    case 0x801DD8E4u: goto label_801DD8E4;
    case 0x801DD8E8u: goto label_801DD8E8;
    case 0x801DD8ECu: goto label_801DD8EC;
    case 0x801DD8F0u: goto label_801DD8F0;
    case 0x801DD8F4u: goto label_801DD8F4;
    case 0x801DD8F8u: goto label_801DD8F8;
    case 0x801DD8FCu: goto label_801DD8FC;
    case 0x801DD900u: goto label_801DD900;
    case 0x801DD904u: goto label_801DD904;
    case 0x801DD908u: goto label_801DD908;
    case 0x801DD90Cu: goto label_801DD90C;
    case 0x801DD910u: goto label_801DD910;
    case 0x801DD914u: goto label_801DD914;
    case 0x801DD918u: goto label_801DD918;
    case 0x801DD91Cu: goto label_801DD91C;
    case 0x801DD920u: goto label_801DD920;
    case 0x801DD924u: goto label_801DD924;
    case 0x801DD928u: goto label_801DD928;
    case 0x801DD92Cu: goto label_801DD92C;
    case 0x801DD930u: goto label_801DD930;
    case 0x801DD934u: goto label_801DD934;
    case 0x801DD938u: goto label_801DD938;
    case 0x801DD93Cu: goto label_801DD93C;
    case 0x801DD940u: goto label_801DD940;
    case 0x801DD944u: goto label_801DD944;
    case 0x801DD948u: goto label_801DD948;
    case 0x801DD94Cu: goto label_801DD94C;
    case 0x801DD950u: goto label_801DD950;
    case 0x801DD954u: goto label_801DD954;
    case 0x801DD958u: goto label_801DD958;
    case 0x801DD95Cu: goto label_801DD95C;
    case 0x801DD960u: goto label_801DD960;
    case 0x801DD964u: goto label_801DD964;
    case 0x801DD968u: goto label_801DD968;
    case 0x801DD96Cu: goto label_801DD96C;
    case 0x801DD970u: goto label_801DD970;
    case 0x801DD974u: goto label_801DD974;
    case 0x801DD978u: goto label_801DD978;
    case 0x801DD97Cu: goto label_801DD97C;
    case 0x801DD980u: goto label_801DD980;
    case 0x801DD984u: goto label_801DD984;
    case 0x801DD988u: goto label_801DD988;
    case 0x801DD98Cu: goto label_801DD98C;
    case 0x801DD990u: goto label_801DD990;
    case 0x801DD994u: goto label_801DD994;
    case 0x801DD998u: goto label_801DD998;
    case 0x801DD99Cu: goto label_801DD99C;
    case 0x801DD9A0u: goto label_801DD9A0;
    case 0x801DD9A4u: goto label_801DD9A4;
    case 0x801DD9A8u: goto label_801DD9A8;
    case 0x801DD9ACu: goto label_801DD9AC;
    case 0x801DD9B0u: goto label_801DD9B0;
    case 0x801DD9B4u: goto label_801DD9B4;
    case 0x801DD9B8u: goto label_801DD9B8;
    case 0x801DD9BCu: goto label_801DD9BC;
    case 0x801DD9C0u: goto label_801DD9C0;
    case 0x801DD9C4u: goto label_801DD9C4;
    case 0x801DD9C8u: goto label_801DD9C8;
    case 0x801DD9CCu: goto label_801DD9CC;
    case 0x801DD9D0u: goto label_801DD9D0;
    case 0x801DD9D4u: goto label_801DD9D4;
    case 0x801DD9D8u: goto label_801DD9D8;
    case 0x801DD9DCu: goto label_801DD9DC;
    case 0x801DD9E0u: goto label_801DD9E0;
    case 0x801DD9E4u: goto label_801DD9E4;
    case 0x801DD9E8u: goto label_801DD9E8;
    case 0x801DD9ECu: goto label_801DD9EC;
    case 0x801DD9F0u: goto label_801DD9F0;
    case 0x801DD9F4u: goto label_801DD9F4;
    case 0x801DD9F8u: goto label_801DD9F8;
    case 0x801DD9FCu: goto label_801DD9FC;
    case 0x801DDA00u: goto label_801DDA00;
    case 0x801DDA04u: goto label_801DDA04;
    case 0x801DDA08u: goto label_801DDA08;
    case 0x801DDA0Cu: goto label_801DDA0C;
    case 0x801DDA10u: goto label_801DDA10;
    case 0x801DDA14u: goto label_801DDA14;
    case 0x801DDA18u: goto label_801DDA18;
    case 0x801DDA1Cu: goto label_801DDA1C;
    case 0x801DDA20u: goto label_801DDA20;
    case 0x801DDA24u: goto label_801DDA24;
    case 0x801DDA28u: goto label_801DDA28;
    case 0x801DDA2Cu: goto label_801DDA2C;
    case 0x801DDA30u: goto label_801DDA30;
    case 0x801DDA34u: goto label_801DDA34;
    case 0x801DDA38u: goto label_801DDA38;
    case 0x801DDA3Cu: goto label_801DDA3C;
    case 0x801DDA40u: goto label_801DDA40;
    case 0x801DDA44u: goto label_801DDA44;
    case 0x801DDA48u: goto label_801DDA48;
    case 0x801DDA4Cu: goto label_801DDA4C;
    case 0x801DDA50u: goto label_801DDA50;
    case 0x801DDA54u: goto label_801DDA54;
    case 0x801DDA58u: goto label_801DDA58;
    case 0x801DDA5Cu: goto label_801DDA5C;
    case 0x801DDA60u: goto label_801DDA60;
    case 0x801DDA64u: goto label_801DDA64;
    case 0x801DDA68u: goto label_801DDA68;
    case 0x801DDA6Cu: goto label_801DDA6C;
    case 0x801DDA70u: goto label_801DDA70;
    case 0x801DDA74u: goto label_801DDA74;
    case 0x801DDA78u: goto label_801DDA78;
    case 0x801DDA7Cu: goto label_801DDA7C;
    case 0x801DDA80u: goto label_801DDA80;
    case 0x801DDA84u: goto label_801DDA84;
    case 0x801DDA88u: goto label_801DDA88;
    case 0x801DDA8Cu: goto label_801DDA8C;
    case 0x801DDA90u: goto label_801DDA90;
    case 0x801DDA94u: goto label_801DDA94;
    case 0x801DDA98u: goto label_801DDA98;
    case 0x801DDA9Cu: goto label_801DDA9C;
    case 0x801DDAA0u: goto label_801DDAA0;
    case 0x801DDAA4u: goto label_801DDAA4;
    case 0x801DDAA8u: goto label_801DDAA8;
    case 0x801DDAACu: goto label_801DDAAC;
    case 0x801DDAB0u: goto label_801DDAB0;
    case 0x801DDAB4u: goto label_801DDAB4;
    case 0x801DDAB8u: goto label_801DDAB8;
    case 0x801DDABCu: goto label_801DDABC;
    case 0x801DDAC0u: goto label_801DDAC0;
    case 0x801DDAC4u: goto label_801DDAC4;
    case 0x801DDAC8u: goto label_801DDAC8;
    case 0x801DDACCu: goto label_801DDACC;
    case 0x801DDAD0u: goto label_801DDAD0;
    case 0x801DDAD4u: goto label_801DDAD4;
    case 0x801DDAD8u: goto label_801DDAD8;
    case 0x801DDADCu: goto label_801DDADC;
    case 0x801DDAE0u: goto label_801DDAE0;
    case 0x801DDAE4u: goto label_801DDAE4;
    case 0x801DDAE8u: goto label_801DDAE8;
    case 0x801DDAECu: goto label_801DDAEC;
    case 0x801DDAF0u: goto label_801DDAF0;
    case 0x801DDAF4u: goto label_801DDAF4;
    case 0x801DDAF8u: goto label_801DDAF8;
    case 0x801DDAFCu: goto label_801DDAFC;
    case 0x801DDB00u: goto label_801DDB00;
    case 0x801DDB04u: goto label_801DDB04;
    case 0x801DDB08u: goto label_801DDB08;
    case 0x801DDB0Cu: goto label_801DDB0C;
    case 0x801DDB10u: goto label_801DDB10;
    case 0x801DDB14u: goto label_801DDB14;
    case 0x801DDB18u: goto label_801DDB18;
    case 0x801DDB1Cu: goto label_801DDB1C;
    case 0x801DDB20u: goto label_801DDB20;
    case 0x801DDB24u: goto label_801DDB24;
    case 0x801DDB28u: goto label_801DDB28;
    case 0x801DDB2Cu: goto label_801DDB2C;
    case 0x801DDB30u: goto label_801DDB30;
    case 0x801DDB34u: goto label_801DDB34;
    case 0x801DDB38u: goto label_801DDB38;
    case 0x801DDB3Cu: goto label_801DDB3C;
    case 0x801DDB40u: goto label_801DDB40;
    case 0x801DDB44u: goto label_801DDB44;
    case 0x801DDB48u: goto label_801DDB48;
    case 0x801DDB4Cu: goto label_801DDB4C;
    case 0x801DDB50u: goto label_801DDB50;
    case 0x801DDB54u: goto label_801DDB54;
    case 0x801DDB58u: goto label_801DDB58;
    case 0x801DDB5Cu: goto label_801DDB5C;
    case 0x801DDB60u: goto label_801DDB60;
    case 0x801DDB64u: goto label_801DDB64;
    case 0x801DDB68u: goto label_801DDB68;
    case 0x801DDB6Cu: goto label_801DDB6C;
    case 0x801DDB70u: goto label_801DDB70;
    case 0x801DDB74u: goto label_801DDB74;
    case 0x801DDB78u: goto label_801DDB78;
    case 0x801DDB7Cu: goto label_801DDB7C;
    case 0x801DDB80u: goto label_801DDB80;
    case 0x801DDB84u: goto label_801DDB84;
    case 0x801DDB88u: goto label_801DDB88;
    case 0x801DDB8Cu: goto label_801DDB8C;
    case 0x801DDB90u: goto label_801DDB90;
    case 0x801DDB94u: goto label_801DDB94;
    case 0x801DDB98u: goto label_801DDB98;
    case 0x801DDB9Cu: goto label_801DDB9C;
    case 0x801DDBA0u: goto label_801DDBA0;
    case 0x801DDBA4u: goto label_801DDBA4;
    case 0x801DDBA8u: goto label_801DDBA8;
    case 0x801DDBACu: goto label_801DDBAC;
    case 0x801DDBB0u: goto label_801DDBB0;
    case 0x801DDBB4u: goto label_801DDBB4;
    case 0x801DDBB8u: goto label_801DDBB8;
    case 0x801DDBBCu: goto label_801DDBBC;
    case 0x801DDBC0u: goto label_801DDBC0;
    case 0x801DDBC4u: goto label_801DDBC4;
    case 0x801DDBC8u: goto label_801DDBC8;
    case 0x801DDBCCu: goto label_801DDBCC;
    case 0x801DDBD0u: goto label_801DDBD0;
    case 0x801DDBD4u: goto label_801DDBD4;
    case 0x801DDBD8u: goto label_801DDBD8;
    case 0x801DDBDCu: goto label_801DDBDC;
    case 0x801DDBE0u: goto label_801DDBE0;
    case 0x801DDBE4u: goto label_801DDBE4;
    case 0x801DDBE8u: goto label_801DDBE8;
    case 0x801DDBECu: goto label_801DDBEC;
    case 0x801DDBF0u: goto label_801DDBF0;
    case 0x801DDBF4u: goto label_801DDBF4;
    case 0x801DDBF8u: goto label_801DDBF8;
    case 0x801DDBFCu: goto label_801DDBFC;
    case 0x801DDC00u: goto label_801DDC00;
    case 0x801DDC04u: goto label_801DDC04;
    case 0x801DDC08u: goto label_801DDC08;
    case 0x801DDC0Cu: goto label_801DDC0C;
    case 0x801DDC10u: goto label_801DDC10;
    case 0x801DDC14u: goto label_801DDC14;
    case 0x801DDC18u: goto label_801DDC18;
    case 0x801DDC1Cu: goto label_801DDC1C;
    case 0x801DDC20u: goto label_801DDC20;
    case 0x801DDC24u: goto label_801DDC24;
    case 0x801DDC28u: goto label_801DDC28;
    case 0x801DDC2Cu: goto label_801DDC2C;
    case 0x801DDC30u: goto label_801DDC30;
    case 0x801DDC34u: goto label_801DDC34;
    case 0x801DDC38u: goto label_801DDC38;
    case 0x801DDC3Cu: goto label_801DDC3C;
    case 0x801DDC40u: goto label_801DDC40;
    case 0x801DDC44u: goto label_801DDC44;
    case 0x801DDC48u: goto label_801DDC48;
    case 0x801DDC4Cu: goto label_801DDC4C;
    case 0x801DDC50u: goto label_801DDC50;
    case 0x801DDC54u: goto label_801DDC54;
    case 0x801DDC58u: goto label_801DDC58;
    case 0x801DDC5Cu: goto label_801DDC5C;
    case 0x801DDC60u: goto label_801DDC60;
    case 0x801DDC64u: goto label_801DDC64;
    case 0x801DDC68u: goto label_801DDC68;
    case 0x801DDC6Cu: goto label_801DDC6C;
    case 0x801DDC70u: goto label_801DDC70;
    case 0x801DDC74u: goto label_801DDC74;
    case 0x801DDC78u: goto label_801DDC78;
    case 0x801DDC7Cu: goto label_801DDC7C;
    case 0x801DDC80u: goto label_801DDC80;
    case 0x801DDC84u: goto label_801DDC84;
    case 0x801DDC88u: goto label_801DDC88;
    case 0x801DDC8Cu: goto label_801DDC8C;
    case 0x801DDC90u: goto label_801DDC90;
    case 0x801DDC94u: goto label_801DDC94;
    case 0x801DDC98u: goto label_801DDC98;
    case 0x801DDC9Cu: goto label_801DDC9C;
    case 0x801DDCA0u: goto label_801DDCA0;
    case 0x801DDCA4u: goto label_801DDCA4;
    case 0x801DDCA8u: goto label_801DDCA8;
    case 0x801DDCACu: goto label_801DDCAC;
    case 0x801DDCB0u: goto label_801DDCB0;
    case 0x801DDCB4u: goto label_801DDCB4;
    case 0x801DDCB8u: goto label_801DDCB8;
    case 0x801DDCBCu: goto label_801DDCBC;
    case 0x801DDCC0u: goto label_801DDCC0;
    case 0x801DDCC4u: goto label_801DDCC4;
    case 0x801DDCC8u: goto label_801DDCC8;
    case 0x801DDCCCu: goto label_801DDCCC;
    case 0x801DDCD0u: goto label_801DDCD0;
    case 0x801DDCD4u: goto label_801DDCD4;
    case 0x801DDCD8u: goto label_801DDCD8;
    case 0x801DDCDCu: goto label_801DDCDC;
    case 0x801DDCE0u: goto label_801DDCE0;
    case 0x801DDCE4u: goto label_801DDCE4;
    case 0x801DDCE8u: goto label_801DDCE8;
    case 0x801DDCECu: goto label_801DDCEC;
    case 0x801DDCF0u: goto label_801DDCF0;
    case 0x801DDCF4u: goto label_801DDCF4;
    case 0x801DDCF8u: goto label_801DDCF8;
    case 0x801DDCFCu: goto label_801DDCFC;
    case 0x801DDD00u: goto label_801DDD00;
    case 0x801DDD04u: goto label_801DDD04;
    case 0x801DDD08u: goto label_801DDD08;
    case 0x801DDD0Cu: goto label_801DDD0C;
    case 0x801DDD10u: goto label_801DDD10;
    case 0x801DDD14u: goto label_801DDD14;
    case 0x801DDD18u: goto label_801DDD18;
    case 0x801DDD1Cu: goto label_801DDD1C;
    case 0x801DDD20u: goto label_801DDD20;
    case 0x801DDD24u: goto label_801DDD24;
    case 0x801DDD28u: goto label_801DDD28;
    case 0x801DDD2Cu: goto label_801DDD2C;
    case 0x801DDD30u: goto label_801DDD30;
    case 0x801DDD34u: goto label_801DDD34;
    case 0x801DDD38u: goto label_801DDD38;
    case 0x801DDD3Cu: goto label_801DDD3C;
    case 0x801DDD40u: goto label_801DDD40;
    case 0x801DDD44u: goto label_801DDD44;
    case 0x801DDD48u: goto label_801DDD48;
    case 0x801DDD4Cu: goto label_801DDD4C;
    case 0x801DDD50u: goto label_801DDD50;
    case 0x801DDD54u: goto label_801DDD54;
    case 0x801DDD58u: goto label_801DDD58;
    case 0x801DDD5Cu: goto label_801DDD5C;
    case 0x801DDD60u: goto label_801DDD60;
    case 0x801DDD64u: goto label_801DDD64;
    case 0x801DDD68u: goto label_801DDD68;
    case 0x801DDD6Cu: goto label_801DDD6C;
    case 0x801DDD70u: goto label_801DDD70;
    case 0x801DDD74u: goto label_801DDD74;
    case 0x801DDD78u: goto label_801DDD78;
    case 0x801DDD7Cu: goto label_801DDD7C;
    case 0x801DDD80u: goto label_801DDD80;
    case 0x801DDD84u: goto label_801DDD84;
    case 0x801DDD88u: goto label_801DDD88;
    case 0x801DDD8Cu: goto label_801DDD8C;
    case 0x801DDD90u: goto label_801DDD90;
    case 0x801DDD94u: goto label_801DDD94;
    case 0x801DDD98u: goto label_801DDD98;
    case 0x801DDD9Cu: goto label_801DDD9C;
    case 0x801DDDA0u: goto label_801DDDA0;
    case 0x801DDDA4u: goto label_801DDDA4;
    case 0x801DDDA8u: goto label_801DDDA8;
    case 0x801DDDACu: goto label_801DDDAC;
    case 0x801DDDB0u: goto label_801DDDB0;
    case 0x801DDDB4u: goto label_801DDDB4;
    case 0x801DDDB8u: goto label_801DDDB8;
    case 0x801DDDBCu: goto label_801DDDBC;
    case 0x801DDDC0u: goto label_801DDDC0;
    case 0x801DDDC4u: goto label_801DDDC4;
    case 0x801DDDC8u: goto label_801DDDC8;
    case 0x801DDDCCu: goto label_801DDDCC;
    case 0x801DDDD0u: goto label_801DDDD0;
    case 0x801DDDD4u: goto label_801DDDD4;
    case 0x801DDDD8u: goto label_801DDDD8;
    case 0x801DDDDCu: goto label_801DDDDC;
    case 0x801DDDE0u: goto label_801DDDE0;
    case 0x801DDDE4u: goto label_801DDDE4;
    case 0x801DDDE8u: goto label_801DDDE8;
    case 0x801DDDECu: goto label_801DDDEC;
    case 0x801DDDF0u: goto label_801DDDF0;
    case 0x801DDDF4u: goto label_801DDDF4;
    case 0x801DDDF8u: goto label_801DDDF8;
    case 0x801DDDFCu: goto label_801DDDFC;
    case 0x801DDE00u: goto label_801DDE00;
    case 0x801DDE04u: goto label_801DDE04;
    case 0x801DDE08u: goto label_801DDE08;
    case 0x801DDE0Cu: goto label_801DDE0C;
    case 0x801DDE10u: goto label_801DDE10;
    case 0x801DDE14u: goto label_801DDE14;
    case 0x801DDE18u: goto label_801DDE18;
    case 0x801DDE1Cu: goto label_801DDE1C;
    case 0x801DDE20u: goto label_801DDE20;
    case 0x801DDE24u: goto label_801DDE24;
    case 0x801DDE28u: goto label_801DDE28;
    case 0x801DDE2Cu: goto label_801DDE2C;
    case 0x801DDE30u: goto label_801DDE30;
    case 0x801DDE34u: goto label_801DDE34;
    case 0x801DDE38u: goto label_801DDE38;
    case 0x801DDE3Cu: goto label_801DDE3C;
    case 0x801DDE40u: goto label_801DDE40;
    case 0x801DDE44u: goto label_801DDE44;
    case 0x801DDE48u: goto label_801DDE48;
    case 0x801DDE4Cu: goto label_801DDE4C;
    case 0x801DDE50u: goto label_801DDE50;
    case 0x801DDE54u: goto label_801DDE54;
    case 0x801DDE58u: goto label_801DDE58;
    case 0x801DDE5Cu: goto label_801DDE5C;
    case 0x801DDE60u: goto label_801DDE60;
    case 0x801DDE64u: goto label_801DDE64;
    case 0x801DDE68u: goto label_801DDE68;
    case 0x801DDE6Cu: goto label_801DDE6C;
    case 0x801DDE70u: goto label_801DDE70;
    case 0x801DDE74u: goto label_801DDE74;
    case 0x801DDE78u: goto label_801DDE78;
    case 0x801DDE7Cu: goto label_801DDE7C;
    case 0x801DDE80u: goto label_801DDE80;
    case 0x801DDE84u: goto label_801DDE84;
    case 0x801DDE88u: goto label_801DDE88;
    case 0x801DDE8Cu: goto label_801DDE8C;
    case 0x801DDE90u: goto label_801DDE90;
    case 0x801DDE94u: goto label_801DDE94;
    case 0x801DDE98u: goto label_801DDE98;
    case 0x801DDE9Cu: goto label_801DDE9C;
    case 0x801DDEA0u: goto label_801DDEA0;
    case 0x801DDEA4u: goto label_801DDEA4;
    case 0x801DDEA8u: goto label_801DDEA8;
    case 0x801DDEACu: goto label_801DDEAC;
    case 0x801DDEB0u: goto label_801DDEB0;
    case 0x801DDEB4u: goto label_801DDEB4;
    case 0x801DDEB8u: goto label_801DDEB8;
    case 0x801DDEBCu: goto label_801DDEBC;
    case 0x801DDEC0u: goto label_801DDEC0;
    case 0x801DDEC4u: goto label_801DDEC4;
    case 0x801DDEC8u: goto label_801DDEC8;
    case 0x801DDECCu: goto label_801DDECC;
    case 0x801DDED0u: goto label_801DDED0;
    case 0x801DDED4u: goto label_801DDED4;
    case 0x801DDED8u: goto label_801DDED8;
    case 0x801DDEDCu: goto label_801DDEDC;
    case 0x801DDEE0u: goto label_801DDEE0;
    case 0x801DDEE4u: goto label_801DDEE4;
    case 0x801DDEE8u: goto label_801DDEE8;
    case 0x801DDEECu: goto label_801DDEEC;
    case 0x801DDEF0u: goto label_801DDEF0;
    case 0x801DDEF4u: goto label_801DDEF4;
    case 0x801DDEF8u: goto label_801DDEF8;
    case 0x801DDEFCu: goto label_801DDEFC;
    case 0x801DDF00u: goto label_801DDF00;
    case 0x801DDF04u: goto label_801DDF04;
    case 0x801DDF08u: goto label_801DDF08;
    case 0x801DDF0Cu: goto label_801DDF0C;
    case 0x801DDF10u: goto label_801DDF10;
    case 0x801DDF14u: goto label_801DDF14;
    case 0x801DDF18u: goto label_801DDF18;
    case 0x801DDF1Cu: goto label_801DDF1C;
    case 0x801DDF20u: goto label_801DDF20;
    case 0x801DDF24u: goto label_801DDF24;
    case 0x801DDF28u: goto label_801DDF28;
    case 0x801DDF2Cu: goto label_801DDF2C;
    case 0x801DDF30u: goto label_801DDF30;
    case 0x801DDF34u: goto label_801DDF34;
    case 0x801DDF38u: goto label_801DDF38;
    case 0x801DDF3Cu: goto label_801DDF3C;
    case 0x801DDF40u: goto label_801DDF40;
    case 0x801DDF44u: goto label_801DDF44;
    case 0x801DDF48u: goto label_801DDF48;
    case 0x801DDF4Cu: goto label_801DDF4C;
    case 0x801DDF50u: goto label_801DDF50;
    case 0x801DDF54u: goto label_801DDF54;
    case 0x801DDF58u: goto label_801DDF58;
    case 0x801DDF5Cu: goto label_801DDF5C;
    case 0x801DDF60u: goto label_801DDF60;
    case 0x801DDF64u: goto label_801DDF64;
    case 0x801DDF68u: goto label_801DDF68;
    case 0x801DDF6Cu: goto label_801DDF6C;
    case 0x801DDF70u: goto label_801DDF70;
    case 0x801DDF74u: goto label_801DDF74;
    case 0x801DDF78u: goto label_801DDF78;
    case 0x801DDF7Cu: goto label_801DDF7C;
    case 0x801DDF80u: goto label_801DDF80;
    case 0x801DDF84u: goto label_801DDF84;
    case 0x801DDF88u: goto label_801DDF88;
    case 0x801DDF8Cu: goto label_801DDF8C;
    case 0x801DDF90u: goto label_801DDF90;
    case 0x801DDF94u: goto label_801DDF94;
    case 0x801DDF98u: goto label_801DDF98;
    case 0x801DDF9Cu: goto label_801DDF9C;
    case 0x801DDFA0u: goto label_801DDFA0;
    case 0x801DDFA4u: goto label_801DDFA4;
    case 0x801DDFA8u: goto label_801DDFA8;
    case 0x801DDFACu: goto label_801DDFAC;
    case 0x801DDFB0u: goto label_801DDFB0;
    case 0x801DDFB4u: goto label_801DDFB4;
    case 0x801DDFB8u: goto label_801DDFB8;
    case 0x801DDFBCu: goto label_801DDFBC;
    case 0x801DDFC0u: goto label_801DDFC0;
    case 0x801DDFC4u: goto label_801DDFC4;
    case 0x801DDFC8u: goto label_801DDFC8;
    case 0x801DDFCCu: goto label_801DDFCC;
    case 0x801DDFD0u: goto label_801DDFD0;
    case 0x801DDFD4u: goto label_801DDFD4;
    case 0x801DDFD8u: goto label_801DDFD8;
    case 0x801DDFDCu: goto label_801DDFDC;
    case 0x801DDFE0u: goto label_801DDFE0;
    case 0x801DDFE4u: goto label_801DDFE4;
    case 0x801DDFE8u: goto label_801DDFE8;
    case 0x801DDFECu: goto label_801DDFEC;
    case 0x801DDFF0u: goto label_801DDFF0;
    case 0x801DDFF4u: goto label_801DDFF4;
    case 0x801DDFF8u: goto label_801DDFF8;
    case 0x801DDFFCu: goto label_801DDFFC;
    case 0x801DE000u: goto label_801DE000;
    case 0x801DE004u: goto label_801DE004;
    case 0x801DE008u: goto label_801DE008;
    case 0x801DE00Cu: goto label_801DE00C;
    case 0x801DE010u: goto label_801DE010;
    case 0x801DE014u: goto label_801DE014;
    case 0x801DE018u: goto label_801DE018;
    case 0x801DE01Cu: goto label_801DE01C;
    case 0x801DE020u: goto label_801DE020;
    case 0x801DE024u: goto label_801DE024;
    case 0x801DE028u: goto label_801DE028;
    case 0x801DE02Cu: goto label_801DE02C;
    case 0x801DE030u: goto label_801DE030;
    case 0x801DE034u: goto label_801DE034;
    case 0x801DE038u: goto label_801DE038;
    case 0x801DE03Cu: goto label_801DE03C;
    case 0x801DE040u: goto label_801DE040;
    case 0x801DE044u: goto label_801DE044;
    case 0x801DE048u: goto label_801DE048;
    case 0x801DE04Cu: goto label_801DE04C;
    case 0x801DE050u: goto label_801DE050;
    case 0x801DE054u: goto label_801DE054;
    case 0x801DE058u: goto label_801DE058;
    case 0x801DE05Cu: goto label_801DE05C;
    case 0x801DE060u: goto label_801DE060;
    case 0x801DE064u: goto label_801DE064;
    case 0x801DE068u: goto label_801DE068;
    case 0x801DE06Cu: goto label_801DE06C;
    case 0x801DE070u: goto label_801DE070;
    case 0x801DE074u: goto label_801DE074;
    case 0x801DE078u: goto label_801DE078;
    case 0x801DE07Cu: goto label_801DE07C;
    case 0x801DE080u: goto label_801DE080;
    case 0x801DE084u: goto label_801DE084;
    case 0x801DE088u: goto label_801DE088;
    case 0x801DE08Cu: goto label_801DE08C;
    case 0x801DE090u: goto label_801DE090;
    case 0x801DE094u: goto label_801DE094;
    case 0x801DE098u: goto label_801DE098;
    case 0x801DE09Cu: goto label_801DE09C;
    case 0x801DE0A0u: goto label_801DE0A0;
    case 0x801DE0A4u: goto label_801DE0A4;
    case 0x801DE0A8u: goto label_801DE0A8;
    case 0x801DE0ACu: goto label_801DE0AC;
    case 0x801DE0B0u: goto label_801DE0B0;
    case 0x801DE0B4u: goto label_801DE0B4;
    case 0x801DE0B8u: goto label_801DE0B8;
    case 0x801DE0BCu: goto label_801DE0BC;
    case 0x801DE0C0u: goto label_801DE0C0;
    case 0x801DE0C4u: goto label_801DE0C4;
    case 0x801DE0C8u: goto label_801DE0C8;
    case 0x801DE0CCu: goto label_801DE0CC;
    case 0x801DE0D0u: goto label_801DE0D0;
    case 0x801DE0D4u: goto label_801DE0D4;
    case 0x801DE0D8u: goto label_801DE0D8;
    case 0x801DE0DCu: goto label_801DE0DC;
    case 0x801DE0E0u: goto label_801DE0E0;
    case 0x801DE0E4u: goto label_801DE0E4;
    case 0x801DE0E8u: goto label_801DE0E8;
    case 0x801DE0ECu: goto label_801DE0EC;
    case 0x801DE0F0u: goto label_801DE0F0;
    case 0x801DE0F4u: goto label_801DE0F4;
    case 0x801DE0F8u: goto label_801DE0F8;
    case 0x801DE0FCu: goto label_801DE0FC;
    case 0x801DE100u: goto label_801DE100;
    case 0x801DE104u: goto label_801DE104;
    case 0x801DE108u: goto label_801DE108;
    case 0x801DE10Cu: goto label_801DE10C;
    case 0x801DE110u: goto label_801DE110;
    case 0x801DE114u: goto label_801DE114;
    case 0x801DE118u: goto label_801DE118;
    case 0x801DE11Cu: goto label_801DE11C;
    case 0x801DE120u: goto label_801DE120;
    case 0x801DE124u: goto label_801DE124;
    case 0x801DE128u: goto label_801DE128;
    case 0x801DE12Cu: goto label_801DE12C;
    case 0x801DE130u: goto label_801DE130;
    case 0x801DE134u: goto label_801DE134;
    case 0x801DE138u: goto label_801DE138;
    case 0x801DE13Cu: goto label_801DE13C;
    case 0x801DE140u: goto label_801DE140;
    case 0x801DE144u: goto label_801DE144;
    case 0x801DE148u: goto label_801DE148;
    case 0x801DE14Cu: goto label_801DE14C;
    case 0x801DE150u: goto label_801DE150;
    case 0x801DE154u: goto label_801DE154;
    case 0x801DE158u: goto label_801DE158;
    case 0x801DE15Cu: goto label_801DE15C;
    case 0x801DE160u: goto label_801DE160;
    case 0x801DE164u: goto label_801DE164;
    case 0x801DE168u: goto label_801DE168;
    case 0x801DE16Cu: goto label_801DE16C;
    case 0x801DE170u: goto label_801DE170;
    case 0x801DE174u: goto label_801DE174;
    case 0x801DE178u: goto label_801DE178;
    case 0x801DE17Cu: goto label_801DE17C;
    case 0x801DE180u: goto label_801DE180;
    case 0x801DE184u: goto label_801DE184;
    case 0x801DE188u: goto label_801DE188;
    case 0x801DE18Cu: goto label_801DE18C;
    case 0x801DE190u: goto label_801DE190;
    case 0x801DE194u: goto label_801DE194;
    case 0x801DE198u: goto label_801DE198;
    case 0x801DE19Cu: goto label_801DE19C;
    case 0x801DE1A0u: goto label_801DE1A0;
    case 0x801DE1A4u: goto label_801DE1A4;
    case 0x801DE1A8u: goto label_801DE1A8;
    case 0x801DE1ACu: goto label_801DE1AC;
    case 0x801DE1B0u: goto label_801DE1B0;
    case 0x801DE1B4u: goto label_801DE1B4;
    case 0x801DE1B8u: goto label_801DE1B8;
    case 0x801DE1BCu: goto label_801DE1BC;
    case 0x801DE1C0u: goto label_801DE1C0;
    case 0x801DE1C4u: goto label_801DE1C4;
    case 0x801DE1C8u: goto label_801DE1C8;
    case 0x801DE1CCu: goto label_801DE1CC;
    case 0x801DE1D0u: goto label_801DE1D0;
    case 0x801DE1D4u: goto label_801DE1D4;
    case 0x801DE1D8u: goto label_801DE1D8;
    case 0x801DE1DCu: goto label_801DE1DC;
    case 0x801DE1E0u: goto label_801DE1E0;
    case 0x801DE1E4u: goto label_801DE1E4;
    case 0x801DE1E8u: goto label_801DE1E8;
    case 0x801DE1ECu: goto label_801DE1EC;
    case 0x801DE1F0u: goto label_801DE1F0;
    case 0x801DE1F4u: goto label_801DE1F4;
    case 0x801DE1F8u: goto label_801DE1F8;
    case 0x801DE1FCu: goto label_801DE1FC;
    case 0x801DE200u: goto label_801DE200;
    case 0x801DE204u: goto label_801DE204;
    case 0x801DE208u: goto label_801DE208;
    case 0x801DE20Cu: goto label_801DE20C;
    case 0x801DE210u: goto label_801DE210;
    case 0x801DE214u: goto label_801DE214;
    case 0x801DE218u: goto label_801DE218;
    case 0x801DE21Cu: goto label_801DE21C;
    case 0x801DE220u: goto label_801DE220;
    case 0x801DE224u: goto label_801DE224;
    case 0x801DE228u: goto label_801DE228;
    case 0x801DE22Cu: goto label_801DE22C;
    case 0x801DE230u: goto label_801DE230;
    case 0x801DE234u: goto label_801DE234;
    case 0x801DE238u: goto label_801DE238;
    case 0x801DE23Cu: goto label_801DE23C;
    case 0x801DE240u: goto label_801DE240;
    case 0x801DE244u: goto label_801DE244;
    case 0x801DE248u: goto label_801DE248;
    case 0x801DE24Cu: goto label_801DE24C;
    case 0x801DE250u: goto label_801DE250;
    case 0x801DE254u: goto label_801DE254;
    case 0x801DE258u: goto label_801DE258;
    case 0x801DE25Cu: goto label_801DE25C;
    case 0x801DE260u: goto label_801DE260;
    case 0x801DE264u: goto label_801DE264;
    case 0x801DE268u: goto label_801DE268;
    case 0x801DE26Cu: goto label_801DE26C;
    case 0x801DE270u: goto label_801DE270;
    case 0x801DE274u: goto label_801DE274;
    case 0x801DE278u: goto label_801DE278;
    case 0x801DE27Cu: goto label_801DE27C;
    case 0x801DE280u: goto label_801DE280;
    case 0x801DE284u: goto label_801DE284;
    case 0x801DE288u: goto label_801DE288;
    case 0x801DE28Cu: goto label_801DE28C;
    case 0x801DE290u: goto label_801DE290;
    case 0x801DE294u: goto label_801DE294;
    case 0x801DE298u: goto label_801DE298;
    case 0x801DE29Cu: goto label_801DE29C;
    case 0x801DE2A0u: goto label_801DE2A0;
    case 0x801DE2A4u: goto label_801DE2A4;
    case 0x801DE2A8u: goto label_801DE2A8;
    case 0x801DE2ACu: goto label_801DE2AC;
    case 0x801DE2B0u: goto label_801DE2B0;
    case 0x801DE2B4u: goto label_801DE2B4;
    case 0x801DE2B8u: goto label_801DE2B8;
    case 0x801DE2BCu: goto label_801DE2BC;
    case 0x801DE2C0u: goto label_801DE2C0;
    case 0x801DE2C4u: goto label_801DE2C4;
    case 0x801DE2C8u: goto label_801DE2C8;
    case 0x801DE2CCu: goto label_801DE2CC;
    case 0x801DE2D0u: goto label_801DE2D0;
    case 0x801DE2D4u: goto label_801DE2D4;
    case 0x801DE2D8u: goto label_801DE2D8;
    case 0x801DE2DCu: goto label_801DE2DC;
    case 0x801DE2E0u: goto label_801DE2E0;
    case 0x801DE2E4u: goto label_801DE2E4;
    case 0x801DE2E8u: goto label_801DE2E8;
    case 0x801DE2ECu: goto label_801DE2EC;
    case 0x801DE2F0u: goto label_801DE2F0;
    case 0x801DE2F4u: goto label_801DE2F4;
    case 0x801DE2F8u: goto label_801DE2F8;
    case 0x801DE2FCu: goto label_801DE2FC;
    case 0x801DE300u: goto label_801DE300;
    case 0x801DE304u: goto label_801DE304;
    case 0x801DE308u: goto label_801DE308;
    case 0x801DE30Cu: goto label_801DE30C;
    case 0x801DE310u: goto label_801DE310;
    case 0x801DE314u: goto label_801DE314;
    case 0x801DE318u: goto label_801DE318;
    case 0x801DE31Cu: goto label_801DE31C;
    case 0x801DE320u: goto label_801DE320;
    case 0x801DE324u: goto label_801DE324;
    case 0x801DE328u: goto label_801DE328;
    case 0x801DE32Cu: goto label_801DE32C;
    case 0x801DE330u: goto label_801DE330;
    case 0x801DE334u: goto label_801DE334;
    case 0x801DE338u: goto label_801DE338;
    case 0x801DE33Cu: goto label_801DE33C;
    case 0x801DE340u: goto label_801DE340;
    case 0x801DE344u: goto label_801DE344;
    case 0x801DE348u: goto label_801DE348;
    case 0x801DE34Cu: goto label_801DE34C;
    case 0x801DE350u: goto label_801DE350;
    case 0x801DE354u: goto label_801DE354;
    case 0x801DE358u: goto label_801DE358;
    case 0x801DE35Cu: goto label_801DE35C;
    case 0x801DE360u: goto label_801DE360;
    case 0x801DE364u: goto label_801DE364;
    case 0x801DE368u: goto label_801DE368;
    case 0x801DE36Cu: goto label_801DE36C;
    case 0x801DE370u: goto label_801DE370;
    case 0x801DE374u: goto label_801DE374;
    case 0x801DE378u: goto label_801DE378;
    case 0x801DE37Cu: goto label_801DE37C;
    case 0x801DE380u: goto label_801DE380;
    case 0x801DE384u: goto label_801DE384;
    case 0x801DE388u: goto label_801DE388;
    case 0x801DE38Cu: goto label_801DE38C;
    case 0x801DE390u: goto label_801DE390;
    case 0x801DE394u: goto label_801DE394;
    case 0x801DE398u: goto label_801DE398;
    case 0x801DE39Cu: goto label_801DE39C;
    case 0x801DE3A0u: goto label_801DE3A0;
    case 0x801DE3A4u: goto label_801DE3A4;
    case 0x801DE3A8u: goto label_801DE3A8;
    case 0x801DE3ACu: goto label_801DE3AC;
    case 0x801DE3B0u: goto label_801DE3B0;
    case 0x801DE3B4u: goto label_801DE3B4;
    case 0x801DE3B8u: goto label_801DE3B8;
    case 0x801DE3BCu: goto label_801DE3BC;
    case 0x801DE3C0u: goto label_801DE3C0;
    case 0x801DE3C4u: goto label_801DE3C4;
    case 0x801DE3C8u: goto label_801DE3C8;
    case 0x801DE3CCu: goto label_801DE3CC;
    case 0x801DE3D0u: goto label_801DE3D0;
    case 0x801DE3D4u: goto label_801DE3D4;
    case 0x801DE3D8u: goto label_801DE3D8;
    case 0x801DE3DCu: goto label_801DE3DC;
    case 0x801DE3E0u: goto label_801DE3E0;
    case 0x801DE3E4u: goto label_801DE3E4;
    case 0x801DE3E8u: goto label_801DE3E8;
    case 0x801DE3ECu: goto label_801DE3EC;
    case 0x801DE3F0u: goto label_801DE3F0;
    case 0x801DE3F4u: goto label_801DE3F4;
    case 0x801DE3F8u: goto label_801DE3F8;
    case 0x801DE3FCu: goto label_801DE3FC;
    case 0x801DE400u: goto label_801DE400;
    case 0x801DE404u: goto label_801DE404;
    case 0x801DE408u: goto label_801DE408;
    case 0x801DE40Cu: goto label_801DE40C;
    case 0x801DE410u: goto label_801DE410;
    case 0x801DE414u: goto label_801DE414;
    case 0x801DE418u: goto label_801DE418;
    case 0x801DE41Cu: goto label_801DE41C;
    case 0x801DE420u: goto label_801DE420;
    case 0x801DE424u: goto label_801DE424;
    case 0x801DE428u: goto label_801DE428;
    case 0x801DE42Cu: goto label_801DE42C;
    case 0x801DE430u: goto label_801DE430;
    case 0x801DE434u: goto label_801DE434;
    case 0x801DE438u: goto label_801DE438;
    case 0x801DE43Cu: goto label_801DE43C;
    case 0x801DE440u: goto label_801DE440;
    case 0x801DE444u: goto label_801DE444;
    case 0x801DE448u: goto label_801DE448;
    case 0x801DE44Cu: goto label_801DE44C;
    case 0x801DE450u: goto label_801DE450;
    case 0x801DE454u: goto label_801DE454;
    case 0x801DE458u: goto label_801DE458;
    case 0x801DE45Cu: goto label_801DE45C;
    case 0x801DE460u: goto label_801DE460;
    case 0x801DE464u: goto label_801DE464;
    case 0x801DE468u: goto label_801DE468;
    case 0x801DE46Cu: goto label_801DE46C;
    case 0x801DE470u: goto label_801DE470;
    case 0x801DE474u: goto label_801DE474;
    case 0x801DE478u: goto label_801DE478;
    case 0x801DE47Cu: goto label_801DE47C;
    case 0x801DE480u: goto label_801DE480;
    case 0x801DE484u: goto label_801DE484;
    case 0x801DE488u: goto label_801DE488;
    case 0x801DE48Cu: goto label_801DE48C;
    case 0x801DE490u: goto label_801DE490;
    case 0x801DE494u: goto label_801DE494;
    case 0x801DE498u: goto label_801DE498;
    case 0x801DE49Cu: goto label_801DE49C;
    case 0x801DE4A0u: goto label_801DE4A0;
    case 0x801DE4A4u: goto label_801DE4A4;
    case 0x801DE4A8u: goto label_801DE4A8;
    case 0x801DE4ACu: goto label_801DE4AC;
    case 0x801DE4B0u: goto label_801DE4B0;
    case 0x801DE4B4u: goto label_801DE4B4;
    case 0x801DE4B8u: goto label_801DE4B8;
    case 0x801DE4BCu: goto label_801DE4BC;
    case 0x801DE4C0u: goto label_801DE4C0;
    case 0x801DE4C4u: goto label_801DE4C4;
    case 0x801DE4C8u: goto label_801DE4C8;
    case 0x801DE4CCu: goto label_801DE4CC;
    case 0x801DE4D0u: goto label_801DE4D0;
    case 0x801DE4D4u: goto label_801DE4D4;
    case 0x801DE4D8u: goto label_801DE4D8;
    case 0x801DE4DCu: goto label_801DE4DC;
    case 0x801DE4E0u: goto label_801DE4E0;
    case 0x801DE4E4u: goto label_801DE4E4;
    case 0x801DE4E8u: goto label_801DE4E8;
    case 0x801DE4ECu: goto label_801DE4EC;
    case 0x801DE4F0u: goto label_801DE4F0;
    case 0x801DE4F4u: goto label_801DE4F4;
    case 0x801DE4F8u: goto label_801DE4F8;
    case 0x801DE4FCu: goto label_801DE4FC;
    case 0x801DE500u: goto label_801DE500;
    case 0x801DE504u: goto label_801DE504;
    case 0x801DE508u: goto label_801DE508;
    case 0x801DE50Cu: goto label_801DE50C;
    case 0x801DE510u: goto label_801DE510;
    case 0x801DE514u: goto label_801DE514;
    case 0x801DE518u: goto label_801DE518;
    case 0x801DE51Cu: goto label_801DE51C;
    case 0x801DE520u: goto label_801DE520;
    case 0x801DE524u: goto label_801DE524;
    case 0x801DE528u: goto label_801DE528;
    case 0x801DE52Cu: goto label_801DE52C;
    case 0x801DE530u: goto label_801DE530;
    case 0x801DE534u: goto label_801DE534;
    case 0x801DE538u: goto label_801DE538;
    case 0x801DE53Cu: goto label_801DE53C;
    case 0x801DE540u: goto label_801DE540;
    case 0x801DE544u: goto label_801DE544;
    case 0x801DE548u: goto label_801DE548;
    case 0x801DE54Cu: goto label_801DE54C;
    case 0x801DE550u: goto label_801DE550;
    case 0x801DE554u: goto label_801DE554;
    case 0x801DE558u: goto label_801DE558;
    case 0x801DE55Cu: goto label_801DE55C;
    case 0x801DE560u: goto label_801DE560;
    case 0x801DE564u: goto label_801DE564;
    case 0x801DE568u: goto label_801DE568;
    case 0x801DE56Cu: goto label_801DE56C;
    case 0x801DE570u: goto label_801DE570;
    case 0x801DE574u: goto label_801DE574;
    case 0x801DE578u: goto label_801DE578;
    case 0x801DE57Cu: goto label_801DE57C;
    case 0x801DE580u: goto label_801DE580;
    case 0x801DE584u: goto label_801DE584;
    case 0x801DE588u: goto label_801DE588;
    case 0x801DE58Cu: goto label_801DE58C;
    case 0x801DE590u: goto label_801DE590;
    case 0x801DE594u: goto label_801DE594;
    case 0x801DE598u: goto label_801DE598;
    case 0x801DE59Cu: goto label_801DE59C;
    case 0x801DE5A0u: goto label_801DE5A0;
    case 0x801DE5A4u: goto label_801DE5A4;
    case 0x801DE5A8u: goto label_801DE5A8;
    case 0x801DE5ACu: goto label_801DE5AC;
    case 0x801DE5B0u: goto label_801DE5B0;
    case 0x801DE5B4u: goto label_801DE5B4;
    case 0x801DE5B8u: goto label_801DE5B8;
    case 0x801DE5BCu: goto label_801DE5BC;
    case 0x801DE5C0u: goto label_801DE5C0;
    case 0x801DE5C4u: goto label_801DE5C4;
    case 0x801DE5C8u: goto label_801DE5C8;
    case 0x801DE5CCu: goto label_801DE5CC;
    case 0x801DE5D0u: goto label_801DE5D0;
    case 0x801DE5D4u: goto label_801DE5D4;
    case 0x801DE5D8u: goto label_801DE5D8;
    case 0x801DE5DCu: goto label_801DE5DC;
    case 0x801DE5E0u: goto label_801DE5E0;
    case 0x801DE5E4u: goto label_801DE5E4;
    case 0x801DE5E8u: goto label_801DE5E8;
    case 0x801DE5ECu: goto label_801DE5EC;
    case 0x801DE5F0u: goto label_801DE5F0;
    case 0x801DE5F4u: goto label_801DE5F4;
    case 0x801DE5F8u: goto label_801DE5F8;
    case 0x801DE5FCu: goto label_801DE5FC;
    case 0x801DE600u: goto label_801DE600;
    case 0x801DE604u: goto label_801DE604;
    case 0x801DE608u: goto label_801DE608;
    case 0x801DE60Cu: goto label_801DE60C;
    case 0x801DE610u: goto label_801DE610;
    case 0x801DE614u: goto label_801DE614;
    case 0x801DE618u: goto label_801DE618;
    case 0x801DE61Cu: goto label_801DE61C;
    case 0x801DE620u: goto label_801DE620;
    case 0x801DE624u: goto label_801DE624;
    case 0x801DE628u: goto label_801DE628;
    case 0x801DE62Cu: goto label_801DE62C;
    case 0x801DE630u: goto label_801DE630;
    case 0x801DE634u: goto label_801DE634;
    case 0x801DE638u: goto label_801DE638;
    case 0x801DE63Cu: goto label_801DE63C;
    case 0x801DE640u: goto label_801DE640;
    case 0x801DE644u: goto label_801DE644;
    case 0x801DE648u: goto label_801DE648;
    case 0x801DE64Cu: goto label_801DE64C;
    case 0x801DE650u: goto label_801DE650;
    case 0x801DE654u: goto label_801DE654;
    case 0x801DE658u: goto label_801DE658;
    case 0x801DE65Cu: goto label_801DE65C;
    case 0x801DE660u: goto label_801DE660;
    case 0x801DE664u: goto label_801DE664;
    case 0x801DE668u: goto label_801DE668;
    case 0x801DE66Cu: goto label_801DE66C;
    case 0x801DE670u: goto label_801DE670;
    case 0x801DE674u: goto label_801DE674;
    case 0x801DE678u: goto label_801DE678;
    case 0x801DE67Cu: goto label_801DE67C;
    case 0x801DE680u: goto label_801DE680;
    case 0x801DE684u: goto label_801DE684;
    case 0x801DE688u: goto label_801DE688;
    case 0x801DE68Cu: goto label_801DE68C;
    case 0x801DE690u: goto label_801DE690;
    case 0x801DE694u: goto label_801DE694;
    case 0x801DE698u: goto label_801DE698;
    case 0x801DE69Cu: goto label_801DE69C;
    case 0x801DE6A0u: goto label_801DE6A0;
    case 0x801DE6A4u: goto label_801DE6A4;
    case 0x801DE6A8u: goto label_801DE6A8;
    case 0x801DE6ACu: goto label_801DE6AC;
    case 0x801DE6B0u: goto label_801DE6B0;
    case 0x801DE6B4u: goto label_801DE6B4;
    case 0x801DE6B8u: goto label_801DE6B8;
    case 0x801DE6BCu: goto label_801DE6BC;
    case 0x801DE6C0u: goto label_801DE6C0;
    case 0x801DE6C4u: goto label_801DE6C4;
    case 0x801DE6C8u: goto label_801DE6C8;
    case 0x801DE6CCu: goto label_801DE6CC;
    case 0x801DE6D0u: goto label_801DE6D0;
    case 0x801DE6D4u: goto label_801DE6D4;
    case 0x801DE6D8u: goto label_801DE6D8;
    case 0x801DE6DCu: goto label_801DE6DC;
    case 0x801DE6E0u: goto label_801DE6E0;
    case 0x801DE6E4u: goto label_801DE6E4;
    case 0x801DE6E8u: goto label_801DE6E8;
    case 0x801DE6ECu: goto label_801DE6EC;
    case 0x801DE6F0u: goto label_801DE6F0;
    case 0x801DE6F4u: goto label_801DE6F4;
    case 0x801DE6F8u: goto label_801DE6F8;
    case 0x801DE6FCu: goto label_801DE6FC;
    case 0x801DE700u: goto label_801DE700;
    case 0x801DE704u: goto label_801DE704;
    case 0x801DE708u: goto label_801DE708;
    case 0x801DE70Cu: goto label_801DE70C;
    case 0x801DE710u: goto label_801DE710;
    case 0x801DE714u: goto label_801DE714;
    case 0x801DE718u: goto label_801DE718;
    case 0x801DE71Cu: goto label_801DE71C;
    case 0x801DE720u: goto label_801DE720;
    case 0x801DE724u: goto label_801DE724;
    case 0x801DE728u: goto label_801DE728;
    case 0x801DE72Cu: goto label_801DE72C;
    case 0x801DE730u: goto label_801DE730;
    case 0x801DE734u: goto label_801DE734;
    case 0x801DE738u: goto label_801DE738;
    case 0x801DE73Cu: goto label_801DE73C;
    case 0x801DE740u: goto label_801DE740;
    case 0x801DE744u: goto label_801DE744;
    case 0x801DE748u: goto label_801DE748;
    case 0x801DE74Cu: goto label_801DE74C;
    case 0x801DE750u: goto label_801DE750;
    case 0x801DE754u: goto label_801DE754;
    case 0x801DE758u: goto label_801DE758;
    case 0x801DE75Cu: goto label_801DE75C;
    case 0x801DE760u: goto label_801DE760;
    case 0x801DE764u: goto label_801DE764;
    case 0x801DE768u: goto label_801DE768;
    case 0x801DE76Cu: goto label_801DE76C;
    case 0x801DE770u: goto label_801DE770;
    case 0x801DE774u: goto label_801DE774;
    case 0x801DE778u: goto label_801DE778;
    case 0x801DE77Cu: goto label_801DE77C;
    case 0x801DE780u: goto label_801DE780;
    case 0x801DE784u: goto label_801DE784;
    case 0x801DE788u: goto label_801DE788;
    case 0x801DE78Cu: goto label_801DE78C;
    case 0x801DE790u: goto label_801DE790;
    case 0x801DE794u: goto label_801DE794;
    case 0x801DE798u: goto label_801DE798;
    case 0x801DE79Cu: goto label_801DE79C;
    case 0x801DE7A0u: goto label_801DE7A0;
    case 0x801DE7A4u: goto label_801DE7A4;
    case 0x801DE7A8u: goto label_801DE7A8;
    case 0x801DE7ACu: goto label_801DE7AC;
    case 0x801DE7B0u: goto label_801DE7B0;
    case 0x801DE7B4u: goto label_801DE7B4;
    case 0x801DE7B8u: goto label_801DE7B8;
    case 0x801DE7BCu: goto label_801DE7BC;
    case 0x801DE7C0u: goto label_801DE7C0;
    case 0x801DE7C4u: goto label_801DE7C4;
    case 0x801DE7C8u: goto label_801DE7C8;
    case 0x801DE7CCu: goto label_801DE7CC;
    case 0x801DE7D0u: goto label_801DE7D0;
    case 0x801DE7D4u: goto label_801DE7D4;
    case 0x801DE7D8u: goto label_801DE7D8;
    case 0x801DE7DCu: goto label_801DE7DC;
    case 0x801DE7E0u: goto label_801DE7E0;
    case 0x801DE7E4u: goto label_801DE7E4;
    case 0x801DE7E8u: goto label_801DE7E8;
    case 0x801DE7ECu: goto label_801DE7EC;
    case 0x801DE7F0u: goto label_801DE7F0;
    case 0x801DE7F4u: goto label_801DE7F4;
    case 0x801DE7F8u: goto label_801DE7F8;
    case 0x801DE7FCu: goto label_801DE7FC;
    case 0x801DE800u: goto label_801DE800;
    case 0x801DE804u: goto label_801DE804;
    case 0x801DE808u: goto label_801DE808;
    case 0x801DE80Cu: goto label_801DE80C;
    case 0x801DE810u: goto label_801DE810;
    case 0x801DE814u: goto label_801DE814;
    case 0x801DE818u: goto label_801DE818;
    case 0x801DE81Cu: goto label_801DE81C;
    case 0x801DE820u: goto label_801DE820;
    case 0x801DE824u: goto label_801DE824;
    case 0x801DE828u: goto label_801DE828;
    case 0x801DE82Cu: goto label_801DE82C;
    case 0x801DE830u: goto label_801DE830;
    case 0x801DE834u: goto label_801DE834;
    case 0x801DE838u: goto label_801DE838;
    case 0x801DE83Cu: goto label_801DE83C;
    case 0x801DE840u: goto label_801DE840;
    case 0x801DE844u: goto label_801DE844;
    case 0x801DE848u: goto label_801DE848;
    case 0x801DE84Cu: goto label_801DE84C;
    case 0x801DE850u: goto label_801DE850;
    case 0x801DE854u: goto label_801DE854;
    case 0x801DE858u: goto label_801DE858;
    case 0x801DE85Cu: goto label_801DE85C;
    case 0x801DE860u: goto label_801DE860;
    case 0x801DE864u: goto label_801DE864;
    case 0x801DE868u: goto label_801DE868;
    case 0x801DE86Cu: goto label_801DE86C;
    case 0x801DE870u: goto label_801DE870;
    case 0x801DE874u: goto label_801DE874;
    case 0x801DE878u: goto label_801DE878;
    case 0x801DE87Cu: goto label_801DE87C;
    case 0x801DE880u: goto label_801DE880;
    case 0x801DE884u: goto label_801DE884;
    case 0x801DE888u: goto label_801DE888;
    case 0x801DE88Cu: goto label_801DE88C;
    case 0x801DE890u: goto label_801DE890;
    case 0x801DE894u: goto label_801DE894;
    case 0x801DE898u: goto label_801DE898;
    case 0x801DE89Cu: goto label_801DE89C;
    case 0x801DE8A0u: goto label_801DE8A0;
    case 0x801DE8A4u: goto label_801DE8A4;
    case 0x801DE8A8u: goto label_801DE8A8;
    case 0x801DE8ACu: goto label_801DE8AC;
    case 0x801DE8B0u: goto label_801DE8B0;
    case 0x801DE8B4u: goto label_801DE8B4;
    case 0x801DE8B8u: goto label_801DE8B8;
    case 0x801DE8BCu: goto label_801DE8BC;
    case 0x801DE8C0u: goto label_801DE8C0;
    case 0x801DE8C4u: goto label_801DE8C4;
    case 0x801DE8C8u: goto label_801DE8C8;
    case 0x801DE8CCu: goto label_801DE8CC;
    case 0x801DE8D0u: goto label_801DE8D0;
    case 0x801DE8D4u: goto label_801DE8D4;
    case 0x801DE8D8u: goto label_801DE8D8;
    case 0x801DE8DCu: goto label_801DE8DC;
    case 0x801DE8E0u: goto label_801DE8E0;
    case 0x801DE8E4u: goto label_801DE8E4;
    case 0x801DE8E8u: goto label_801DE8E8;
    case 0x801DE8ECu: goto label_801DE8EC;
    case 0x801DE8F0u: goto label_801DE8F0;
    case 0x801DE8F4u: goto label_801DE8F4;
    case 0x801DE8F8u: goto label_801DE8F8;
    case 0x801DE8FCu: goto label_801DE8FC;
    case 0x801DE900u: goto label_801DE900;
    case 0x801DE904u: goto label_801DE904;
    case 0x801DE908u: goto label_801DE908;
    case 0x801DE90Cu: goto label_801DE90C;
    case 0x801DE910u: goto label_801DE910;
    case 0x801DE914u: goto label_801DE914;
    case 0x801DE918u: goto label_801DE918;
    case 0x801DE91Cu: goto label_801DE91C;
    case 0x801DE920u: goto label_801DE920;
    case 0x801DE924u: goto label_801DE924;
    case 0x801DE928u: goto label_801DE928;
    case 0x801DE92Cu: goto label_801DE92C;
    case 0x801DE930u: goto label_801DE930;
    case 0x801DE934u: goto label_801DE934;
    case 0x801DE938u: goto label_801DE938;
    case 0x801DE93Cu: goto label_801DE93C;
    case 0x801DE940u: goto label_801DE940;
    case 0x801DE944u: goto label_801DE944;
    case 0x801DE948u: goto label_801DE948;
    case 0x801DE94Cu: goto label_801DE94C;
    case 0x801DE950u: goto label_801DE950;
    case 0x801DE954u: goto label_801DE954;
    case 0x801DE958u: goto label_801DE958;
    case 0x801DE95Cu: goto label_801DE95C;
    case 0x801DE960u: goto label_801DE960;
    case 0x801DE964u: goto label_801DE964;
    case 0x801DE968u: goto label_801DE968;
    case 0x801DE96Cu: goto label_801DE96C;
    case 0x801DE970u: goto label_801DE970;
    case 0x801DE974u: goto label_801DE974;
    case 0x801DE978u: goto label_801DE978;
    case 0x801DE97Cu: goto label_801DE97C;
    case 0x801DE980u: goto label_801DE980;
    case 0x801DE984u: goto label_801DE984;
    case 0x801DE988u: goto label_801DE988;
    case 0x801DE98Cu: goto label_801DE98C;
    case 0x801DE990u: goto label_801DE990;
    case 0x801DE994u: goto label_801DE994;
    case 0x801DE998u: goto label_801DE998;
    case 0x801DE99Cu: goto label_801DE99C;
    case 0x801DE9A0u: goto label_801DE9A0;
    case 0x801DE9A4u: goto label_801DE9A4;
    case 0x801DE9A8u: goto label_801DE9A8;
    case 0x801DE9ACu: goto label_801DE9AC;
    case 0x801DE9B0u: goto label_801DE9B0;
    case 0x801DE9B4u: goto label_801DE9B4;
    case 0x801DE9B8u: goto label_801DE9B8;
    case 0x801DE9BCu: goto label_801DE9BC;
    case 0x801DE9C0u: goto label_801DE9C0;
    case 0x801DE9C4u: goto label_801DE9C4;
    case 0x801DE9C8u: goto label_801DE9C8;
    case 0x801DE9CCu: goto label_801DE9CC;
    case 0x801DE9D0u: goto label_801DE9D0;
    case 0x801DE9D4u: goto label_801DE9D4;
    case 0x801DE9D8u: goto label_801DE9D8;
    case 0x801DE9DCu: goto label_801DE9DC;
    case 0x801DE9E0u: goto label_801DE9E0;
    case 0x801DE9E4u: goto label_801DE9E4;
    case 0x801DE9E8u: goto label_801DE9E8;
    case 0x801DE9ECu: goto label_801DE9EC;
    case 0x801DE9F0u: goto label_801DE9F0;
    case 0x801DE9F4u: goto label_801DE9F4;
    case 0x801DE9F8u: goto label_801DE9F8;
    case 0x801DE9FCu: goto label_801DE9FC;
    case 0x801DEA00u: goto label_801DEA00;
    case 0x801DEA04u: goto label_801DEA04;
    case 0x801DEA08u: goto label_801DEA08;
    case 0x801DEA0Cu: goto label_801DEA0C;
    case 0x801DEA10u: goto label_801DEA10;
    case 0x801DEA14u: goto label_801DEA14;
    case 0x801DEA18u: goto label_801DEA18;
    case 0x801DEA1Cu: goto label_801DEA1C;
    case 0x801DEA20u: goto label_801DEA20;
    case 0x801DEA24u: goto label_801DEA24;
    case 0x801DEA28u: goto label_801DEA28;
    case 0x801DEA2Cu: goto label_801DEA2C;
    case 0x801DEA30u: goto label_801DEA30;
    case 0x801DEA34u: goto label_801DEA34;
    case 0x801DEA38u: goto label_801DEA38;
    case 0x801DEA3Cu: goto label_801DEA3C;
    case 0x801DEA40u: goto label_801DEA40;
    case 0x801DEA44u: goto label_801DEA44;
    case 0x801DEA48u: goto label_801DEA48;
    case 0x801DEA4Cu: goto label_801DEA4C;
    case 0x801DEA50u: goto label_801DEA50;
    case 0x801DEA54u: goto label_801DEA54;
    case 0x801DEA58u: goto label_801DEA58;
    case 0x801DEA5Cu: goto label_801DEA5C;
    case 0x801DEA60u: goto label_801DEA60;
    case 0x801DEA64u: goto label_801DEA64;
    case 0x801DEA68u: goto label_801DEA68;
    case 0x801DEA6Cu: goto label_801DEA6C;
    case 0x801DEA70u: goto label_801DEA70;
    case 0x801DEA74u: goto label_801DEA74;
    case 0x801DEA78u: goto label_801DEA78;
    case 0x801DEA7Cu: goto label_801DEA7C;
    case 0x801DEA80u: goto label_801DEA80;
    case 0x801DEA84u: goto label_801DEA84;
    case 0x801DEA88u: goto label_801DEA88;
    case 0x801DEA8Cu: goto label_801DEA8C;
    case 0x801DEA90u: goto label_801DEA90;
    case 0x801DEA94u: goto label_801DEA94;
    case 0x801DEA98u: goto label_801DEA98;
    case 0x801DEA9Cu: goto label_801DEA9C;
    case 0x801DEAA0u: goto label_801DEAA0;
    case 0x801DEAA4u: goto label_801DEAA4;
    case 0x801DEAA8u: goto label_801DEAA8;
    case 0x801DEAACu: goto label_801DEAAC;
    case 0x801DEAB0u: goto label_801DEAB0;
    case 0x801DEAB4u: goto label_801DEAB4;
    case 0x801DEAB8u: goto label_801DEAB8;
    case 0x801DEABCu: goto label_801DEABC;
    case 0x801DEAC0u: goto label_801DEAC0;
    case 0x801DEAC4u: goto label_801DEAC4;
    case 0x801DEAC8u: goto label_801DEAC8;
    case 0x801DEACCu: goto label_801DEACC;
    case 0x801DEAD0u: goto label_801DEAD0;
    case 0x801DEAD4u: goto label_801DEAD4;
    case 0x801DEAD8u: goto label_801DEAD8;
    case 0x801DEADCu: goto label_801DEADC;
    case 0x801DEAE0u: goto label_801DEAE0;
    case 0x801DEAE4u: goto label_801DEAE4;
    case 0x801DEAE8u: goto label_801DEAE8;
    case 0x801DEAECu: goto label_801DEAEC;
    case 0x801DEAF0u: goto label_801DEAF0;
    case 0x801DEAF4u: goto label_801DEAF4;
    case 0x801DEAF8u: goto label_801DEAF8;
    case 0x801DEAFCu: goto label_801DEAFC;
    case 0x801DEB00u: goto label_801DEB00;
    case 0x801DEB04u: goto label_801DEB04;
    case 0x801DEB08u: goto label_801DEB08;
    case 0x801DEB0Cu: goto label_801DEB0C;
    case 0x801DEB10u: goto label_801DEB10;
    case 0x801DEB14u: goto label_801DEB14;
    case 0x801DEB18u: goto label_801DEB18;
    case 0x801DEB1Cu: goto label_801DEB1C;
    case 0x801DEB20u: goto label_801DEB20;
    case 0x801DEB24u: goto label_801DEB24;
    case 0x801DEB28u: goto label_801DEB28;
    case 0x801DEB2Cu: goto label_801DEB2C;
    case 0x801DEB30u: goto label_801DEB30;
    case 0x801DEB34u: goto label_801DEB34;
    case 0x801DEB38u: goto label_801DEB38;
    case 0x801DEB3Cu: goto label_801DEB3C;
    case 0x801DEB40u: goto label_801DEB40;
    case 0x801DEB44u: goto label_801DEB44;
    case 0x801DEB48u: goto label_801DEB48;
    case 0x801DEB4Cu: goto label_801DEB4C;
    case 0x801DEB50u: goto label_801DEB50;
    case 0x801DEB54u: goto label_801DEB54;
    case 0x801DEB58u: goto label_801DEB58;
    case 0x801DEB5Cu: goto label_801DEB5C;
    case 0x801DEB60u: goto label_801DEB60;
    case 0x801DEB64u: goto label_801DEB64;
    case 0x801DEB68u: goto label_801DEB68;
    case 0x801DEB6Cu: goto label_801DEB6C;
    case 0x801DEB70u: goto label_801DEB70;
    case 0x801DEB74u: goto label_801DEB74;
    case 0x801DEB78u: goto label_801DEB78;
    case 0x801DEB7Cu: goto label_801DEB7C;
    case 0x801DEB80u: goto label_801DEB80;
    case 0x801DEB84u: goto label_801DEB84;
    case 0x801DEB88u: goto label_801DEB88;
    case 0x801DEB8Cu: goto label_801DEB8C;
    case 0x801DEB90u: goto label_801DEB90;
    case 0x801DEB94u: goto label_801DEB94;
    case 0x801DEB98u: goto label_801DEB98;
    case 0x801DEB9Cu: goto label_801DEB9C;
    case 0x801DEBA0u: goto label_801DEBA0;
    case 0x801DEBA4u: goto label_801DEBA4;
    case 0x801DEBA8u: goto label_801DEBA8;
    case 0x801DEBACu: goto label_801DEBAC;
    case 0x801DEBB0u: goto label_801DEBB0;
    case 0x801DEBB4u: goto label_801DEBB4;
    case 0x801DEBB8u: goto label_801DEBB8;
    case 0x801DEBBCu: goto label_801DEBBC;
    case 0x801DEBC0u: goto label_801DEBC0;
    case 0x801DEBC4u: goto label_801DEBC4;
    case 0x801DEBC8u: goto label_801DEBC8;
    case 0x801DEBCCu: goto label_801DEBCC;
    case 0x801DEBD0u: goto label_801DEBD0;
    case 0x801DEBD4u: goto label_801DEBD4;
    case 0x801DEBD8u: goto label_801DEBD8;
    case 0x801DEBDCu: goto label_801DEBDC;
    case 0x801DEBE0u: goto label_801DEBE0;
    case 0x801DEBE4u: goto label_801DEBE4;
    case 0x801DEBE8u: goto label_801DEBE8;
    case 0x801DEBECu: goto label_801DEBEC;
    case 0x801DEBF0u: goto label_801DEBF0;
    case 0x801DEBF4u: goto label_801DEBF4;
    case 0x801DEBF8u: goto label_801DEBF8;
    case 0x801DEBFCu: goto label_801DEBFC;
    case 0x801DEC00u: goto label_801DEC00;
    case 0x801DEC04u: goto label_801DEC04;
    case 0x801DEC08u: goto label_801DEC08;
    case 0x801DEC0Cu: goto label_801DEC0C;
    case 0x801DEC10u: goto label_801DEC10;
    case 0x801DEC14u: goto label_801DEC14;
    case 0x801DEC18u: goto label_801DEC18;
    case 0x801DEC1Cu: goto label_801DEC1C;
    case 0x801DEC20u: goto label_801DEC20;
    case 0x801DEC24u: goto label_801DEC24;
    case 0x801DEC28u: goto label_801DEC28;
    case 0x801DEC2Cu: goto label_801DEC2C;
    case 0x801DEC30u: goto label_801DEC30;
    case 0x801DEC34u: goto label_801DEC34;
    case 0x801DEC38u: goto label_801DEC38;
    case 0x801DEC3Cu: goto label_801DEC3C;
    case 0x801DEC40u: goto label_801DEC40;
    case 0x801DEC44u: goto label_801DEC44;
    case 0x801DEC48u: goto label_801DEC48;
    case 0x801DEC4Cu: goto label_801DEC4C;
    case 0x801DEC50u: goto label_801DEC50;
    case 0x801DEC54u: goto label_801DEC54;
    case 0x801DEC58u: goto label_801DEC58;
    case 0x801DEC5Cu: goto label_801DEC5C;
    case 0x801DEC60u: goto label_801DEC60;
    case 0x801DEC64u: goto label_801DEC64;
    case 0x801DEC68u: goto label_801DEC68;
    case 0x801DEC6Cu: goto label_801DEC6C;
    case 0x801DEC70u: goto label_801DEC70;
    case 0x801DEC74u: goto label_801DEC74;
    case 0x801DEC78u: goto label_801DEC78;
    case 0x801DEC7Cu: goto label_801DEC7C;
    case 0x801DEC80u: goto label_801DEC80;
    case 0x801DEC84u: goto label_801DEC84;
    case 0x801DEC88u: goto label_801DEC88;
    case 0x801DEC8Cu: goto label_801DEC8C;
    case 0x801DEC90u: goto label_801DEC90;
    case 0x801DEC94u: goto label_801DEC94;
    case 0x801DEC98u: goto label_801DEC98;
    case 0x801DEC9Cu: goto label_801DEC9C;
    case 0x801DECA0u: goto label_801DECA0;
    case 0x801DECA4u: goto label_801DECA4;
    case 0x801DECA8u: goto label_801DECA8;
    case 0x801DECACu: goto label_801DECAC;
    case 0x801DECB0u: goto label_801DECB0;
    case 0x801DECB4u: goto label_801DECB4;
    case 0x801DECB8u: goto label_801DECB8;
    case 0x801DECBCu: goto label_801DECBC;
    case 0x801DECC0u: goto label_801DECC0;
    case 0x801DECC4u: goto label_801DECC4;
    case 0x801DECC8u: goto label_801DECC8;
    case 0x801DECCCu: goto label_801DECCC;
    case 0x801DECD0u: goto label_801DECD0;
    case 0x801DECD4u: goto label_801DECD4;
    case 0x801DECD8u: goto label_801DECD8;
    case 0x801DECDCu: goto label_801DECDC;
    case 0x801DECE0u: goto label_801DECE0;
    case 0x801DECE4u: goto label_801DECE4;
    case 0x801DECE8u: goto label_801DECE8;
    case 0x801DECECu: goto label_801DECEC;
    case 0x801DECF0u: goto label_801DECF0;
    case 0x801DECF4u: goto label_801DECF4;
    case 0x801DECF8u: goto label_801DECF8;
    case 0x801DECFCu: goto label_801DECFC;
    case 0x801DED00u: goto label_801DED00;
    case 0x801DED04u: goto label_801DED04;
    case 0x801DED08u: goto label_801DED08;
    case 0x801DED0Cu: goto label_801DED0C;
    case 0x801DED10u: goto label_801DED10;
    case 0x801DED14u: goto label_801DED14;
    case 0x801DED18u: goto label_801DED18;
    case 0x801DED1Cu: goto label_801DED1C;
    case 0x801DED20u: goto label_801DED20;
    case 0x801DED24u: goto label_801DED24;
    case 0x801DED28u: goto label_801DED28;
    case 0x801DED2Cu: goto label_801DED2C;
    case 0x801DED30u: goto label_801DED30;
    case 0x801DED34u: goto label_801DED34;
    case 0x801DED38u: goto label_801DED38;
    case 0x801DED3Cu: goto label_801DED3C;
    case 0x801DED40u: goto label_801DED40;
    case 0x801DED44u: goto label_801DED44;
    case 0x801DED48u: goto label_801DED48;
    case 0x801DED4Cu: goto label_801DED4C;
    case 0x801DED50u: goto label_801DED50;
    case 0x801DED54u: goto label_801DED54;
    case 0x801DED58u: goto label_801DED58;
    case 0x801DED5Cu: goto label_801DED5C;
    case 0x801DED60u: goto label_801DED60;
    case 0x801DED64u: goto label_801DED64;
    case 0x801DED68u: goto label_801DED68;
    case 0x801DED6Cu: goto label_801DED6C;
    case 0x801DED70u: goto label_801DED70;
    case 0x801DED74u: goto label_801DED74;
    case 0x801DED78u: goto label_801DED78;
    case 0x801DED7Cu: goto label_801DED7C;
    case 0x801DED80u: goto label_801DED80;
    case 0x801DED84u: goto label_801DED84;
    case 0x801DED88u: goto label_801DED88;
    case 0x801DED8Cu: goto label_801DED8C;
    case 0x801DED90u: goto label_801DED90;
    case 0x801DED94u: goto label_801DED94;
    case 0x801DED98u: goto label_801DED98;
    case 0x801DED9Cu: goto label_801DED9C;
    case 0x801DEDA0u: goto label_801DEDA0;
    case 0x801DEDA4u: goto label_801DEDA4;
    case 0x801DEDA8u: goto label_801DEDA8;
    case 0x801DEDACu: goto label_801DEDAC;
    case 0x801DEDB0u: goto label_801DEDB0;
    case 0x801DEDB4u: goto label_801DEDB4;
    case 0x801DEDB8u: goto label_801DEDB8;
    case 0x801DEDBCu: goto label_801DEDBC;
    case 0x801DEDC0u: goto label_801DEDC0;
    case 0x801DEDC4u: goto label_801DEDC4;
    case 0x801DEDC8u: goto label_801DEDC8;
    case 0x801DEDCCu: goto label_801DEDCC;
    case 0x801DEDD0u: goto label_801DEDD0;
    case 0x801DEDD4u: goto label_801DEDD4;
    case 0x801DEDD8u: goto label_801DEDD8;
    case 0x801DEDDCu: goto label_801DEDDC;
    case 0x801DEDE0u: goto label_801DEDE0;
    case 0x801DEDE4u: goto label_801DEDE4;
    case 0x801DEDE8u: goto label_801DEDE8;
    case 0x801DEDECu: goto label_801DEDEC;
    case 0x801DEDF0u: goto label_801DEDF0;
    case 0x801DEDF4u: goto label_801DEDF4;
    case 0x801DEDF8u: goto label_801DEDF8;
    case 0x801DEDFCu: goto label_801DEDFC;
    case 0x801DEE00u: goto label_801DEE00;
    case 0x801DEE04u: goto label_801DEE04;
    case 0x801DEE08u: goto label_801DEE08;
    case 0x801DEE0Cu: goto label_801DEE0C;
    case 0x801DEE10u: goto label_801DEE10;
    case 0x801DEE14u: goto label_801DEE14;
    case 0x801DEE18u: goto label_801DEE18;
    case 0x801DEE1Cu: goto label_801DEE1C;
    case 0x801DEE20u: goto label_801DEE20;
    case 0x801DEE24u: goto label_801DEE24;
    case 0x801DEE28u: goto label_801DEE28;
    case 0x801DEE2Cu: goto label_801DEE2C;
    case 0x801DEE30u: goto label_801DEE30;
    case 0x801DEE34u: goto label_801DEE34;
    case 0x801DEE38u: goto label_801DEE38;
    case 0x801DEE3Cu: goto label_801DEE3C;
    case 0x801DEE40u: goto label_801DEE40;
    case 0x801DEE44u: goto label_801DEE44;
    case 0x801DEE48u: goto label_801DEE48;
    case 0x801DEE4Cu: goto label_801DEE4C;
    case 0x801DEE50u: goto label_801DEE50;
    case 0x801DEE54u: goto label_801DEE54;
    case 0x801DEE58u: goto label_801DEE58;
    case 0x801DEE5Cu: goto label_801DEE5C;
    case 0x801DEE60u: goto label_801DEE60;
    case 0x801DEE64u: goto label_801DEE64;
    case 0x801DEE68u: goto label_801DEE68;
    case 0x801DEE6Cu: goto label_801DEE6C;
    case 0x801DEE70u: goto label_801DEE70;
    case 0x801DEE74u: goto label_801DEE74;
    case 0x801DEE78u: goto label_801DEE78;
    case 0x801DEE7Cu: goto label_801DEE7C;
    case 0x801DEE80u: goto label_801DEE80;
    case 0x801DEE84u: goto label_801DEE84;
    case 0x801DEE88u: goto label_801DEE88;
    case 0x801DEE8Cu: goto label_801DEE8C;
    case 0x801DEE90u: goto label_801DEE90;
    case 0x801DEE94u: goto label_801DEE94;
    case 0x801DEE98u: goto label_801DEE98;
    case 0x801DEE9Cu: goto label_801DEE9C;
    case 0x801DEEA0u: goto label_801DEEA0;
    case 0x801DEEA4u: goto label_801DEEA4;
    case 0x801DEEA8u: goto label_801DEEA8;
    case 0x801DEEACu: goto label_801DEEAC;
    case 0x801DEEB0u: goto label_801DEEB0;
    case 0x801DEEB4u: goto label_801DEEB4;
    case 0x801DEEB8u: goto label_801DEEB8;
    case 0x801DEEBCu: goto label_801DEEBC;
    case 0x801DEEC0u: goto label_801DEEC0;
    case 0x801DEEC4u: goto label_801DEEC4;
    case 0x801DEEC8u: goto label_801DEEC8;
    case 0x801DEECCu: goto label_801DEECC;
    case 0x801DEED0u: goto label_801DEED0;
    case 0x801DEED4u: goto label_801DEED4;
    case 0x801DEED8u: goto label_801DEED8;
    case 0x801DEEDCu: goto label_801DEEDC;
    case 0x801DEEE0u: goto label_801DEEE0;
    case 0x801DEEE4u: goto label_801DEEE4;
    case 0x801DEEE8u: goto label_801DEEE8;
    case 0x801DEEECu: goto label_801DEEEC;
    case 0x801DEEF0u: goto label_801DEEF0;
    case 0x801DEEF4u: goto label_801DEEF4;
    case 0x801DEEF8u: goto label_801DEEF8;
    case 0x801DEEFCu: goto label_801DEEFC;
    case 0x801DEF00u: goto label_801DEF00;
    case 0x801DEF04u: goto label_801DEF04;
    case 0x801DEF08u: goto label_801DEF08;
    case 0x801DEF0Cu: goto label_801DEF0C;
    case 0x801DEF10u: goto label_801DEF10;
    case 0x801DEF14u: goto label_801DEF14;
    case 0x801DEF18u: goto label_801DEF18;
    case 0x801DEF1Cu: goto label_801DEF1C;
    case 0x801DEF20u: goto label_801DEF20;
    case 0x801DEF24u: goto label_801DEF24;
    case 0x801DEF28u: goto label_801DEF28;
    case 0x801DEF2Cu: goto label_801DEF2C;
    case 0x801DEF30u: goto label_801DEF30;
    case 0x801DEF34u: goto label_801DEF34;
    case 0x801DEF38u: goto label_801DEF38;
    case 0x801DEF3Cu: goto label_801DEF3C;
    case 0x801DEF40u: goto label_801DEF40;
    case 0x801DEF44u: goto label_801DEF44;
    case 0x801DEF48u: goto label_801DEF48;
    case 0x801DEF4Cu: goto label_801DEF4C;
    case 0x801DEF50u: goto label_801DEF50;
    case 0x801DEF54u: goto label_801DEF54;
    case 0x801DEF58u: goto label_801DEF58;
    case 0x801DEF5Cu: goto label_801DEF5C;
    case 0x801DEF60u: goto label_801DEF60;
    case 0x801DEF64u: goto label_801DEF64;
    case 0x801DEF68u: goto label_801DEF68;
    case 0x801DEF6Cu: goto label_801DEF6C;
    case 0x801DEF70u: goto label_801DEF70;
    case 0x801DEF74u: goto label_801DEF74;
    case 0x801DEF78u: goto label_801DEF78;
    case 0x801DEF7Cu: goto label_801DEF7C;
    case 0x801DEF80u: goto label_801DEF80;
    case 0x801DEF84u: goto label_801DEF84;
    case 0x801DEF88u: goto label_801DEF88;
    case 0x801DEF8Cu: goto label_801DEF8C;
    case 0x801DEF90u: goto label_801DEF90;
    case 0x801DEF94u: goto label_801DEF94;
    case 0x801DEF98u: goto label_801DEF98;
    case 0x801DEF9Cu: goto label_801DEF9C;
    case 0x801DEFA0u: goto label_801DEFA0;
    case 0x801DEFA4u: goto label_801DEFA4;
    case 0x801DEFA8u: goto label_801DEFA8;
    case 0x801DEFACu: goto label_801DEFAC;
    case 0x801DEFB0u: goto label_801DEFB0;
    case 0x801DEFB4u: goto label_801DEFB4;
    case 0x801DEFB8u: goto label_801DEFB8;
    case 0x801DEFBCu: goto label_801DEFBC;
    case 0x801DEFC0u: goto label_801DEFC0;
    case 0x801DEFC4u: goto label_801DEFC4;
    case 0x801DEFC8u: goto label_801DEFC8;
    case 0x801DEFCCu: goto label_801DEFCC;
    case 0x801DEFD0u: goto label_801DEFD0;
    case 0x801DEFD4u: goto label_801DEFD4;
    case 0x801DEFD8u: goto label_801DEFD8;
    case 0x801DEFDCu: goto label_801DEFDC;
    case 0x801DEFE0u: goto label_801DEFE0;
    case 0x801DEFE4u: goto label_801DEFE4;
    case 0x801DEFE8u: goto label_801DEFE8;
    case 0x801DEFECu: goto label_801DEFEC;
    case 0x801DEFF0u: goto label_801DEFF0;
    case 0x801DEFF4u: goto label_801DEFF4;
    case 0x801DEFF8u: goto label_801DEFF8;
    case 0x801DEFFCu: goto label_801DEFFC;
    case 0x801DF000u: goto label_801DF000;
    case 0x801DF004u: goto label_801DF004;
    case 0x801DF008u: goto label_801DF008;
    case 0x801DF00Cu: goto label_801DF00C;
    case 0x801DF010u: goto label_801DF010;
    case 0x801DF014u: goto label_801DF014;
    case 0x801DF018u: goto label_801DF018;
    case 0x801DF01Cu: goto label_801DF01C;
    case 0x801DF020u: goto label_801DF020;
    case 0x801DF024u: goto label_801DF024;
    case 0x801DF028u: goto label_801DF028;
    case 0x801DF02Cu: goto label_801DF02C;
    case 0x801DF030u: goto label_801DF030;
    case 0x801DF034u: goto label_801DF034;
    case 0x801DF038u: goto label_801DF038;
    case 0x801DF03Cu: goto label_801DF03C;
    case 0x801DF040u: goto label_801DF040;
    case 0x801DF044u: goto label_801DF044;
    case 0x801DF048u: goto label_801DF048;
    case 0x801DF04Cu: goto label_801DF04C;
    case 0x801DF050u: goto label_801DF050;
    case 0x801DF054u: goto label_801DF054;
    case 0x801DF058u: goto label_801DF058;
    case 0x801DF05Cu: goto label_801DF05C;
    case 0x801DF060u: goto label_801DF060;
    case 0x801DF064u: goto label_801DF064;
    case 0x801DF068u: goto label_801DF068;
    case 0x801DF06Cu: goto label_801DF06C;
    case 0x801DF070u: goto label_801DF070;
    case 0x801DF074u: goto label_801DF074;
    case 0x801DF078u: goto label_801DF078;
    case 0x801DF07Cu: goto label_801DF07C;
    case 0x801DF080u: goto label_801DF080;
    case 0x801DF084u: goto label_801DF084;
    case 0x801DF088u: goto label_801DF088;
    case 0x801DF08Cu: goto label_801DF08C;
    case 0x801DF090u: goto label_801DF090;
    case 0x801DF094u: goto label_801DF094;
    case 0x801DF098u: goto label_801DF098;
    case 0x801DF09Cu: goto label_801DF09C;
    case 0x801DF0A0u: goto label_801DF0A0;
    case 0x801DF0A4u: goto label_801DF0A4;
    case 0x801DF0A8u: goto label_801DF0A8;
    case 0x801DF0ACu: goto label_801DF0AC;
    case 0x801DF0B0u: goto label_801DF0B0;
    case 0x801DF0B4u: goto label_801DF0B4;
    case 0x801DF0B8u: goto label_801DF0B8;
    case 0x801DF0BCu: goto label_801DF0BC;
    case 0x801DF0C0u: goto label_801DF0C0;
    case 0x801DF0C4u: goto label_801DF0C4;
    case 0x801DF0C8u: goto label_801DF0C8;
    case 0x801DF0CCu: goto label_801DF0CC;
    case 0x801DF0D0u: goto label_801DF0D0;
    case 0x801DF0D4u: goto label_801DF0D4;
    case 0x801DF0D8u: goto label_801DF0D8;
    case 0x801DF0DCu: goto label_801DF0DC;
    case 0x801DF0E0u: goto label_801DF0E0;
    case 0x801DF0E4u: goto label_801DF0E4;
    case 0x801DF0E8u: goto label_801DF0E8;
    case 0x801DF0ECu: goto label_801DF0EC;
    case 0x801DF0F0u: goto label_801DF0F0;
    case 0x801DF0F4u: goto label_801DF0F4;
    case 0x801DF0F8u: goto label_801DF0F8;
    case 0x801DF0FCu: goto label_801DF0FC;
    case 0x801DF100u: goto label_801DF100;
    case 0x801DF104u: goto label_801DF104;
    case 0x801DF108u: goto label_801DF108;
    case 0x801DF10Cu: goto label_801DF10C;
    case 0x801DF110u: goto label_801DF110;
    case 0x801DF114u: goto label_801DF114;
    case 0x801DF118u: goto label_801DF118;
    case 0x801DF11Cu: goto label_801DF11C;
    case 0x801DF120u: goto label_801DF120;
    case 0x801DF124u: goto label_801DF124;
    case 0x801DF128u: goto label_801DF128;
    case 0x801DF12Cu: goto label_801DF12C;
    case 0x801DF130u: goto label_801DF130;
    case 0x801DF134u: goto label_801DF134;
    case 0x801DF138u: goto label_801DF138;
    case 0x801DF13Cu: goto label_801DF13C;
    case 0x801DF140u: goto label_801DF140;
    case 0x801DF144u: goto label_801DF144;
    case 0x801DF148u: goto label_801DF148;
    case 0x801DF14Cu: goto label_801DF14C;
    case 0x801DF150u: goto label_801DF150;
    case 0x801DF154u: goto label_801DF154;
    case 0x801DF158u: goto label_801DF158;
    case 0x801DF15Cu: goto label_801DF15C;
    case 0x801DF160u: goto label_801DF160;
    case 0x801DF164u: goto label_801DF164;
    case 0x801DF168u: goto label_801DF168;
    case 0x801DF16Cu: goto label_801DF16C;
    case 0x801DF170u: goto label_801DF170;
    case 0x801DF174u: goto label_801DF174;
    case 0x801DF178u: goto label_801DF178;
    case 0x801DF17Cu: goto label_801DF17C;
    case 0x801DF180u: goto label_801DF180;
    case 0x801DF184u: goto label_801DF184;
    case 0x801DF188u: goto label_801DF188;
    case 0x801DF18Cu: goto label_801DF18C;
    case 0x801DF190u: goto label_801DF190;
    case 0x801DF194u: goto label_801DF194;
    case 0x801DF198u: goto label_801DF198;
    case 0x801DF19Cu: goto label_801DF19C;
    case 0x801DF1A0u: goto label_801DF1A0;
    case 0x801DF1A4u: goto label_801DF1A4;
    case 0x801DF1A8u: goto label_801DF1A8;
    case 0x801DF1ACu: goto label_801DF1AC;
    case 0x801DF1B0u: goto label_801DF1B0;
    case 0x801DF1B4u: goto label_801DF1B4;
    case 0x801DF1B8u: goto label_801DF1B8;
    case 0x801DF1BCu: goto label_801DF1BC;
    case 0x801DF1C0u: goto label_801DF1C0;
    case 0x801DF1C4u: goto label_801DF1C4;
    case 0x801DF1C8u: goto label_801DF1C8;
    case 0x801DF1CCu: goto label_801DF1CC;
    case 0x801DF1D0u: goto label_801DF1D0;
    case 0x801DF1D4u: goto label_801DF1D4;
    case 0x801DF1D8u: goto label_801DF1D8;
    case 0x801DF1DCu: goto label_801DF1DC;
    case 0x801DF1E0u: goto label_801DF1E0;
    case 0x801DF1E4u: goto label_801DF1E4;
    case 0x801DF1E8u: goto label_801DF1E8;
    case 0x801DF1ECu: goto label_801DF1EC;
    case 0x801DF1F0u: goto label_801DF1F0;
    case 0x801DF1F4u: goto label_801DF1F4;
    case 0x801DF1F8u: goto label_801DF1F8;
    case 0x801DF1FCu: goto label_801DF1FC;
    case 0x801DF200u: goto label_801DF200;
    case 0x801DF204u: goto label_801DF204;
    case 0x801DF208u: goto label_801DF208;
    case 0x801DF20Cu: goto label_801DF20C;
    case 0x801DF210u: goto label_801DF210;
    case 0x801DF214u: goto label_801DF214;
    case 0x801DF218u: goto label_801DF218;
    case 0x801DF21Cu: goto label_801DF21C;
    case 0x801DF220u: goto label_801DF220;
    case 0x801DF224u: goto label_801DF224;
    case 0x801DF228u: goto label_801DF228;
    case 0x801DF22Cu: goto label_801DF22C;
    case 0x801DF230u: goto label_801DF230;
    case 0x801DF234u: goto label_801DF234;
    case 0x801DF238u: goto label_801DF238;
    case 0x801DF23Cu: goto label_801DF23C;
    case 0x801DF240u: goto label_801DF240;
    case 0x801DF244u: goto label_801DF244;
    case 0x801DF248u: goto label_801DF248;
    case 0x801DF24Cu: goto label_801DF24C;
    case 0x801DF250u: goto label_801DF250;
    case 0x801DF254u: goto label_801DF254;
    case 0x801DF258u: goto label_801DF258;
    case 0x801DF25Cu: goto label_801DF25C;
    case 0x801DF260u: goto label_801DF260;
    case 0x801DF264u: goto label_801DF264;
    case 0x801DF268u: goto label_801DF268;
    case 0x801DF26Cu: goto label_801DF26C;
    case 0x801DF270u: goto label_801DF270;
    case 0x801DF274u: goto label_801DF274;
    case 0x801DF278u: goto label_801DF278;
    case 0x801DF27Cu: goto label_801DF27C;
    case 0x801DF280u: goto label_801DF280;
    case 0x801DF284u: goto label_801DF284;
    case 0x801DF288u: goto label_801DF288;
    case 0x801DF28Cu: goto label_801DF28C;
    case 0x801DF290u: goto label_801DF290;
    case 0x801DF294u: goto label_801DF294;
    case 0x801DF298u: goto label_801DF298;
    case 0x801DF29Cu: goto label_801DF29C;
    case 0x801DF2A0u: goto label_801DF2A0;
    case 0x801DF2A4u: goto label_801DF2A4;
    case 0x801DF2A8u: goto label_801DF2A8;
    case 0x801DF2ACu: goto label_801DF2AC;
    case 0x801DF2B0u: goto label_801DF2B0;
    case 0x801DF2B4u: goto label_801DF2B4;
    case 0x801DF2B8u: goto label_801DF2B8;
    case 0x801DF2BCu: goto label_801DF2BC;
    case 0x801DF2C0u: goto label_801DF2C0;
    case 0x801DF2C4u: goto label_801DF2C4;
    case 0x801DF2C8u: goto label_801DF2C8;
    case 0x801DF2CCu: goto label_801DF2CC;
    case 0x801DF2D0u: goto label_801DF2D0;
    case 0x801DF2D4u: goto label_801DF2D4;
    case 0x801DF2D8u: goto label_801DF2D8;
    case 0x801DF2DCu: goto label_801DF2DC;
    case 0x801DF2E0u: goto label_801DF2E0;
    case 0x801DF2E4u: goto label_801DF2E4;
    case 0x801DF2E8u: goto label_801DF2E8;
    case 0x801DF2ECu: goto label_801DF2EC;
    case 0x801DF2F0u: goto label_801DF2F0;
    case 0x801DF2F4u: goto label_801DF2F4;
    case 0x801DF2F8u: goto label_801DF2F8;
    case 0x801DF2FCu: goto label_801DF2FC;
    case 0x801DF300u: goto label_801DF300;
    case 0x801DF304u: goto label_801DF304;
    case 0x801DF308u: goto label_801DF308;
    case 0x801DF30Cu: goto label_801DF30C;
    case 0x801DF310u: goto label_801DF310;
    case 0x801DF314u: goto label_801DF314;
    case 0x801DF318u: goto label_801DF318;
    case 0x801DF31Cu: goto label_801DF31C;
    case 0x801DF320u: goto label_801DF320;
    case 0x801DF324u: goto label_801DF324;
    case 0x801DF328u: goto label_801DF328;
    case 0x801DF32Cu: goto label_801DF32C;
    case 0x801DF330u: goto label_801DF330;
    case 0x801DF334u: goto label_801DF334;
    case 0x801DF338u: goto label_801DF338;
    case 0x801DF33Cu: goto label_801DF33C;
    case 0x801DF340u: goto label_801DF340;
    case 0x801DF344u: goto label_801DF344;
    case 0x801DF348u: goto label_801DF348;
    case 0x801DF34Cu: goto label_801DF34C;
    case 0x801DF350u: goto label_801DF350;
    case 0x801DF354u: goto label_801DF354;
    case 0x801DF358u: goto label_801DF358;
    case 0x801DF35Cu: goto label_801DF35C;
    case 0x801DF360u: goto label_801DF360;
    case 0x801DF364u: goto label_801DF364;
    case 0x801DF368u: goto label_801DF368;
    case 0x801DF36Cu: goto label_801DF36C;
    case 0x801DF370u: goto label_801DF370;
    case 0x801DF374u: goto label_801DF374;
    case 0x801DF378u: goto label_801DF378;
    case 0x801DF37Cu: goto label_801DF37C;
    case 0x801DF380u: goto label_801DF380;
    case 0x801DF384u: goto label_801DF384;
    case 0x801DF388u: goto label_801DF388;
    case 0x801DF38Cu: goto label_801DF38C;
    case 0x801DF390u: goto label_801DF390;
    case 0x801DF394u: goto label_801DF394;
    case 0x801DF398u: goto label_801DF398;
    case 0x801DF39Cu: goto label_801DF39C;
    case 0x801DF3A0u: goto label_801DF3A0;
    case 0x801DF3A4u: goto label_801DF3A4;
    case 0x801DF3A8u: goto label_801DF3A8;
    case 0x801DF3ACu: goto label_801DF3AC;
    case 0x801DF3B0u: goto label_801DF3B0;
    case 0x801DF3B4u: goto label_801DF3B4;
    case 0x801DF3B8u: goto label_801DF3B8;
    case 0x801DF3BCu: goto label_801DF3BC;
    case 0x801DF3C0u: goto label_801DF3C0;
    case 0x801DF3C4u: goto label_801DF3C4;
    case 0x801DF3C8u: goto label_801DF3C8;
    case 0x801DF3CCu: goto label_801DF3CC;
    case 0x801DF3D0u: goto label_801DF3D0;
    case 0x801DF3D4u: goto label_801DF3D4;
    case 0x801DF3D8u: goto label_801DF3D8;
    case 0x801DF3DCu: goto label_801DF3DC;
    case 0x801DF3E0u: goto label_801DF3E0;
    case 0x801DF3E4u: goto label_801DF3E4;
    case 0x801DF3E8u: goto label_801DF3E8;
    case 0x801DF3ECu: goto label_801DF3EC;
    case 0x801DF3F0u: goto label_801DF3F0;
    case 0x801DF3F4u: goto label_801DF3F4;
    case 0x801DF3F8u: goto label_801DF3F8;
    case 0x801DF3FCu: goto label_801DF3FC;
    case 0x801DF400u: goto label_801DF400;
    case 0x801DF404u: goto label_801DF404;
    case 0x801DF408u: goto label_801DF408;
    case 0x801DF40Cu: goto label_801DF40C;
    case 0x801DF410u: goto label_801DF410;
    case 0x801DF414u: goto label_801DF414;
    case 0x801DF418u: goto label_801DF418;
    case 0x801DF41Cu: goto label_801DF41C;
    case 0x801DF420u: goto label_801DF420;
    case 0x801DF424u: goto label_801DF424;
    case 0x801DF428u: goto label_801DF428;
    case 0x801DF42Cu: goto label_801DF42C;
    case 0x801DF430u: goto label_801DF430;
    case 0x801DF434u: goto label_801DF434;
    case 0x801DF438u: goto label_801DF438;
    case 0x801DF43Cu: goto label_801DF43C;
    case 0x801DF440u: goto label_801DF440;
    case 0x801DF444u: goto label_801DF444;
    case 0x801DF448u: goto label_801DF448;
    case 0x801DF44Cu: goto label_801DF44C;
    case 0x801DF450u: goto label_801DF450;
    case 0x801DF454u: goto label_801DF454;
    case 0x801DF458u: goto label_801DF458;
    case 0x801DF45Cu: goto label_801DF45C;
    case 0x801DF460u: goto label_801DF460;
    case 0x801DF464u: goto label_801DF464;
    case 0x801DF468u: goto label_801DF468;
    case 0x801DF46Cu: goto label_801DF46C;
    case 0x801DF470u: goto label_801DF470;
    case 0x801DF474u: goto label_801DF474;
    case 0x801DF478u: goto label_801DF478;
    case 0x801DF47Cu: goto label_801DF47C;
    case 0x801DF480u: goto label_801DF480;
    case 0x801DF484u: goto label_801DF484;
    case 0x801DF488u: goto label_801DF488;
    case 0x801DF48Cu: goto label_801DF48C;
    case 0x801DF490u: goto label_801DF490;
    case 0x801DF494u: goto label_801DF494;
    case 0x801DF498u: goto label_801DF498;
    case 0x801DF49Cu: goto label_801DF49C;
    case 0x801DF4A0u: goto label_801DF4A0;
    case 0x801DF4A4u: goto label_801DF4A4;
    case 0x801DF4A8u: goto label_801DF4A8;
    case 0x801DF4ACu: goto label_801DF4AC;
    case 0x801DF4B0u: goto label_801DF4B0;
    case 0x801DF4B4u: goto label_801DF4B4;
    case 0x801DF4B8u: goto label_801DF4B8;
    case 0x801DF4BCu: goto label_801DF4BC;
    default: return;
    }
label_801DB4C0:
    ctx->pc = 0x801DB4C0u;
    ctx->downcount -= 3;
    // 801DB4C0: stfs     f0, -30568(r13)
    if (!ppc_fp_available_inline(ctx, 0x801DB4C0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30568);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801DB4C4:
    ctx->pc = 0x801DB4C4u;
    // 801DB4C4: fmr    f2, f31
    if (!ppc_fp_available_inline(ctx, 0x801DB4C4u)) return;
    ctx->fpr[2] = ctx->fpr[31];

label_801DB4C8:
    ctx->pc = 0x801DB4C8u;
    // 801DB4C8: bl      0x8029E2D4
    {
            ctx->lr = 0x801DB4CCu;
            ctx->pc = 0x8029E2D4u;
            return;
    }

label_801DB4CC:
    ctx->pc = 0x801DB4CCu;
    ctx->downcount -= 4;
    // 801DB4CC: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DB4D0:
    ctx->pc = 0x801DB4D0u;
    // 801DB4D0: lfs     f0, 4632(r9)
    if (!ppc_fp_available_inline(ctx, 0x801DB4D0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4632);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB4D4:
    ctx->pc = 0x801DB4D4u;
    // 801DB4D4: fcmpu   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x801DB4D4u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], false);

label_801DB4D8:
    ctx->pc = 0x801DB4D8u;
    // 801DB4D8: bc    4, 0, 0x801DB4E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DB4E0;
        }
    }

label_801DB4DC:
    ctx->pc = 0x801DB4DCu;
    ctx->downcount -= 1;
    // 801DB4DC: fadds   f1, f1, f31
    if (!ppc_fp_available_inline(ctx, 0x801DB4DCu)) return;
    ppc_fadds(ctx, 1, 1, 31);

label_801DB4E0:
    ctx->pc = 0x801DB4E0u;
    ctx->downcount -= 7;
    // 801DB4E0: stfs     f1, -30572(r13)
    if (!ppc_fp_available_inline(ctx, 0x801DB4E0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30572);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801DB4E4:
    ctx->pc = 0x801DB4E4u;
    // 801DB4E4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB4E8:
    ctx->pc = 0x801DB4E8u;
    // 801DB4E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DB4EC:
    ctx->pc = 0x801DB4ECu;
    // 801DB4EC: lfd     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB4ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801DB4F0:
    ctx->pc = 0x801DB4F0u;
    // 801DB4F0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DB4F4:
    ctx->pc = 0x801DB4F4u;
    // 801DB4F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB4F8:
    ctx->pc = 0x801DB4F8u;
    ctx->downcount -= 2;
    // 801DB4F8: lfs     f1, -30572(r13)
    if (!ppc_fp_available_inline(ctx, 0x801DB4F8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30572);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801DB4FC:
    ctx->pc = 0x801DB4FCu;
    // 801DB4FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB500:
    ctx->pc = 0x801DB500u;
    ctx->downcount -= 3;
    // 801DB500: lfs     f0, 276(r3)
    if (!ppc_fp_available_inline(ctx, 0x801DB500u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB504:
    ctx->pc = 0x801DB504u;
    // 801DB504: fcmpu   cr0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x801DB504u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[1], false);

label_801DB508:
    ctx->pc = 0x801DB508u;
    // 801DB508: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB50C:
    ctx->pc = 0x801DB50Cu;
    ctx->downcount -= 4;
    // 801DB50C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DB510:
    ctx->pc = 0x801DB510u;
    // 801DB510: stfs     f1, 276(r3)
    if (!ppc_fp_available_inline(ctx, 0x801DB510u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(276);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801DB514:
    ctx->pc = 0x801DB514u;
    // 801DB514: stw     r0, 284(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(284);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB518:
    ctx->pc = 0x801DB518u;
    // 801DB518: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB51C:
    ctx->pc = 0x801DB51Cu;
    ctx->downcount -= 3;
    // 801DB51C: lfs     f0, 280(r3)
    if (!ppc_fp_available_inline(ctx, 0x801DB51Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB520:
    ctx->pc = 0x801DB520u;
    // 801DB520: fcmpu   cr0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x801DB520u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[1], false);

label_801DB524:
    ctx->pc = 0x801DB524u;
    // 801DB524: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB528:
    ctx->pc = 0x801DB528u;
    ctx->downcount -= 4;
    // 801DB528: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DB52C:
    ctx->pc = 0x801DB52Cu;
    // 801DB52C: stfs     f1, 280(r3)
    if (!ppc_fp_available_inline(ctx, 0x801DB52Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(280);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801DB530:
    ctx->pc = 0x801DB530u;
    // 801DB530: stw     r0, 284(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(284);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB534:
    ctx->pc = 0x801DB534u;
    // 801DB534: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB538:
    ctx->pc = 0x801DB538u;
    ctx->downcount -= 13;
    // 801DB538: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DB53C:
    ctx->pc = 0x801DB53Cu;
    // 801DB53C: lfs     f0, 280(r3)
    if (!ppc_fp_available_inline(ctx, 0x801DB53Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB540:
    ctx->pc = 0x801DB540u;
    // 801DB540: lfs     f12, 4636(r9)
    if (!ppc_fp_available_inline(ctx, 0x801DB540u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4636);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801DB544:
    ctx->pc = 0x801DB544u;
    // 801DB544: lwz     r8, 272(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(272);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801DB548:
    ctx->pc = 0x801DB548u;
    // 801DB548: fcmpu   cr7, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x801DB548u)) return;
    ppc_fcmp(ctx, 7, ctx->fpr[0], ctx->fpr[12], false);

label_801DB54C:
    ctx->pc = 0x801DB54Cu;
    // 801DB54C: lfs     f13, 276(r3)
    if (!ppc_fp_available_inline(ctx, 0x801DB54Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801DB550:
    ctx->pc = 0x801DB550u;
    // 801DB550: mfcr    r0
    ctx->gpr[0] = ctx->cr;

label_801DB554:
    ctx->pc = 0x801DB554u;
    // 801DB554: rlwinm r0, r0, 29, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 29u) & 0x00000001u;
    }

label_801DB558:
    ctx->pc = 0x801DB558u;
    // 801DB558: stw     r0, 1072(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1072);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB55C:
    ctx->pc = 0x801DB55Cu;
    // 801DB55C: lfs     f0, 64(r8)
    if (!ppc_fp_available_inline(ctx, 0x801DB55Cu)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(64);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB560:
    ctx->pc = 0x801DB560u;
    // 801DB560: fmuls   f13, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x801DB560u)) return;
    ppc_fmuls(ctx, 13, 13, 0);

label_801DB564:
    ctx->pc = 0x801DB564u;
    // 801DB564: fcmpu   cr0, f13, f12
    if (!ppc_fp_available_inline(ctx, 0x801DB564u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[13], ctx->fpr[12], false);

label_801DB568:
    ctx->pc = 0x801DB568u;
    // 801DB568: bc    4, 0, 0x801DB580
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DB580;
        }
    }

label_801DB56C:
    ctx->pc = 0x801DB56Cu;
    ctx->downcount -= 3;
    // 801DB56C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801DB570:
    ctx->pc = 0x801DB570u;
    // 801DB570: addi    r10, r3, 360
    ctx->gpr[10] = ctx->gpr[3] + (u32)(s32)(360);

label_801DB574:
    ctx->pc = 0x801DB574u;
    // 801DB574: b       0x801DB5B4
    {
            goto label_801DB5B4;
    }

label_801DB578:
    ctx->downcount -= 2;
    // 801DB578: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801DB57C:
    // 801DB57C: b       0x801DB5B4
    {
            goto label_801DB5B4;
    }

label_801DB580:
    ctx->downcount -= 4;
    // 801DB580: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_801DB584:
    // 801DB584: addi    r10, r3, 360
    ctx->gpr[10] = ctx->gpr[3] + (u32)(s32)(360);

label_801DB588:
    // 801DB588: cmpw    r11, r4
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DB58C:
    // 801DB58C: bc    4, 0, 0x801DB5B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DB5B0;
        }
    }

label_801DB590:
    ctx->downcount -= 1;
    // 801DB590: addi    r9, r8, 112
    ctx->gpr[9] = ctx->gpr[8] + (u32)(s32)(112);

label_801DB594:
    ctx->pc = 0x801DB594u;
    ctx->downcount -= 4;
    // 801DB594: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB598:
    // 801DB598: addi    r9, r9, 120
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(120);

label_801DB59C:
    // 801DB59C: andis.  r7, r0, 0x2000
    {
        ctx->gpr[7] = ctx->gpr[0] & (0x2000u << 16);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DB5A0:
    // 801DB5A0: bc    4, 2, 0x801DB578
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DB578u;
                return;
            }
            goto label_801DB578;
        }
    }

label_801DB5A4:
    ctx->downcount -= 3;
    // 801DB5A4: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_801DB5A8:
    // 801DB5A8: cmpw    r11, r4
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DB5AC:
    // 801DB5AC: bc    12, 0, 0x801DB594
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DB594u;
                return;
            }
            goto label_801DB594;
        }
    }

label_801DB5B0:
    ctx->pc = 0x801DB5B0u;
    ctx->downcount -= 1;
    // 801DB5B0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DB5B4:
    ctx->pc = 0x801DB5B4u;
    ctx->downcount -= 4;
    // 801DB5B4: stw     r0, 1068(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1068);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB5B8:
    ctx->pc = 0x801DB5B8u;
    // 801DB5B8: lwz     r0, 76(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB5BC:
    ctx->pc = 0x801DB5BCu;
    // 801DB5BC: cmpwi   r0, 0
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

label_801DB5C0:
    ctx->pc = 0x801DB5C0u;
    // 801DB5C0: bc    12, 2, 0x801DB5DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DB5DC;
        }
    }

label_801DB5C4:
    ctx->pc = 0x801DB5C4u;
    ctx->downcount -= 2;
    // 801DB5C4: cmpwi   r0, 1
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DB5C8:
    ctx->pc = 0x801DB5C8u;
    // 801DB5C8: bc    12, 2, 0x801DB5E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DB5E8;
        }
    }

label_801DB5CC:
    ctx->pc = 0x801DB5CCu;
    ctx->downcount -= 4;
    // 801DB5CC: lwz     r0, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB5D0:
    // 801DB5D0: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_801DB5D4:
    ctx->pc = 0x801DB5D4u;
    // 801DB5D4: stw     r0, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB5D8:
    ctx->pc = 0x801DB5D8u;
    // 801DB5D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB5DC:
    ctx->pc = 0x801DB5DCu;
    ctx->downcount -= 3;
    // 801DB5DC: lwz     r0, 1068(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1068);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB5E0:
    // 801DB5E0: cmpwi   r0, 0
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

label_801DB5E4:
    // 801DB5E4: bc    4, 2, 0x801DB5CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DB5CCu;
                return;
            }
            goto label_801DB5CC;
        }
    }

label_801DB5E8:
    ctx->pc = 0x801DB5E8u;
    ctx->downcount -= 4;
    // 801DB5E8: lwz     r0, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB5EC:
    ctx->pc = 0x801DB5ECu;
    // 801DB5EC: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_801DB5F0:
    ctx->pc = 0x801DB5F0u;
    // 801DB5F0: stw     r0, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB5F4:
    ctx->pc = 0x801DB5F4u;
    // 801DB5F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB5F8:
    ctx->pc = 0x801DB5F8u;
    ctx->downcount -= 2;
    // 801DB5F8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DB5FC:
    ctx->pc = 0x801DB5FCu;
    // 801DB5FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB600:
    ctx->pc = 0x801DB600u;
    ctx->downcount -= 2;
    // 801DB600: cmpwi   r4, 500
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(500);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DB604:
    ctx->pc = 0x801DB604u;
    // 801DB604: bc    4, 2, 0x801DB630
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DB630;
        }
    }

label_801DB608:
    ctx->pc = 0x801DB608u;
    ctx->downcount -= 3;
    // 801DB608: lwz     r0, 1068(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1068);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB60C:
    ctx->pc = 0x801DB60Cu;
    // 801DB60C: cmpwi   r0, 0
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

label_801DB610:
    ctx->pc = 0x801DB610u;
    // 801DB610: bc    4, 2, 0x801DB620
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DB620;
        }
    }

label_801DB614:
    ctx->pc = 0x801DB614u;
    ctx->downcount -= 3;
    // 801DB614: lwz     r0, 1072(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1072);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB618:
    ctx->pc = 0x801DB618u;
    // 801DB618: cmpwi   r0, 0
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

label_801DB61C:
    ctx->pc = 0x801DB61Cu;
    // 801DB61C: bc    12, 2, 0x801DB628
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DB628;
        }
    }

label_801DB620:
    ctx->pc = 0x801DB620u;
    ctx->downcount -= 2;
    // 801DB620: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_801DB624:
    ctx->pc = 0x801DB624u;
    // 801DB624: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB628:
    ctx->pc = 0x801DB628u;
    ctx->downcount -= 2;
    // 801DB628: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DB62C:
    ctx->pc = 0x801DB62Cu;
    // 801DB62C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB630:
    ctx->pc = 0x801DB630u;
    ctx->downcount -= 2;
    // 801DB630: cmpwi   r4, 0
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

label_801DB634:
    ctx->pc = 0x801DB634u;
    // 801DB634: bc    12, 2, 0x801DB640
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DB640;
        }
    }

label_801DB638:
    ctx->pc = 0x801DB638u;
    ctx->downcount -= 2;
    // 801DB638: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801DB63C:
    ctx->pc = 0x801DB63Cu;
    // 801DB63C: stw     r0, 1068(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1068);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB640:
    ctx->pc = 0x801DB640u;
    ctx->downcount -= 2;
    // 801DB640: cmpwi   r4, 3
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DB644:
    ctx->pc = 0x801DB644u;
    // 801DB644: bc    4, 2, 0x801DB64C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DB64C;
        }
    }

label_801DB648:
    ctx->pc = 0x801DB648u;
    ctx->downcount -= 1;
    // 801DB648: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_801DB64C:
    ctx->pc = 0x801DB64Cu;
    ctx->downcount -= 2;
    // 801DB64C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DB650:
    ctx->pc = 0x801DB650u;
    // 801DB650: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB654:
    ctx->pc = 0x801DB654u;
    ctx->downcount -= 10;
    // 801DB654: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DB658:
    ctx->pc = 0x801DB658u;
    // 801DB658: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DB65C:
    ctx->pc = 0x801DB65Cu;
    // 801DB65C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB660:
    ctx->pc = 0x801DB660u;
    // 801DB660: mulli   r5, r5, 120
    ctx->gpr[5] = (u32)((s64)(s32)ctx->gpr[5] * (s64)(s32)120);

label_801DB664:
    ctx->pc = 0x801DB664u;
    // 801DB664: lwz     r0, 272(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(272);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB668:
    ctx->pc = 0x801DB668u;
    // 801DB668: addi    r5, r5, 92
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(92);

label_801DB66C:
    ctx->pc = 0x801DB66Cu;
    // 801DB66C: add   r5, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_801DB670:
    ctx->pc = 0x801DB670u;
    // 801DB670: bl      0x801D74E0
    {
            ctx->lr = 0x801DB674u;
            ctx->pc = 0x801D74E0u;
            return;
    }

label_801DB674:
    ctx->pc = 0x801DB674u;
    ctx->downcount -= 5;
    // 801DB674: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB678:
    ctx->pc = 0x801DB678u;
    // 801DB678: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DB67C:
    ctx->pc = 0x801DB67Cu;
    // 801DB67C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DB680:
    ctx->pc = 0x801DB680u;
    // 801DB680: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB684:
    ctx->pc = 0x801DB684u;
    ctx->downcount -= 8;
    // 801DB684: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DB688:
    ctx->pc = 0x801DB688u;
    // 801DB688: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DB68C:
    ctx->pc = 0x801DB68Cu;
    // 801DB68C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB690:
    ctx->pc = 0x801DB690u;
    // 801DB690: addi    r3, r3, 360
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(360);

label_801DB694:
    ctx->pc = 0x801DB694u;
    // 801DB694: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801DB698:
    ctx->pc = 0x801DB698u;
    // 801DB698: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801DB69C:
    ctx->pc = 0x801DB69Cu;
    // 801DB69C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_801DB6A0:
    ctx->pc = 0x801DB6A0u;
    // 801DB6A0: bl      0x802414DC
    {
            ctx->lr = 0x801DB6A4u;
            ctx->pc = 0x802414DCu;
            return;
    }

label_801DB6A4:
    ctx->pc = 0x801DB6A4u;
    ctx->downcount -= 5;
    // 801DB6A4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB6A8:
    ctx->pc = 0x801DB6A8u;
    // 801DB6A8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DB6AC:
    ctx->pc = 0x801DB6ACu;
    // 801DB6AC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DB6B0:
    ctx->pc = 0x801DB6B0u;
    // 801DB6B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB6B4:
    ctx->pc = 0x801DB6B4u;
    ctx->downcount -= 42;
    // 801DB6B4: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DB6B8:
    ctx->pc = 0x801DB6B8u;
    // 801DB6B8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DB6BC:
    ctx->pc = 0x801DB6BCu;
    // 801DB6BC: stmw     r29, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DB6C0:
    ctx->pc = 0x801DB6C0u;
    // 801DB6C0: stw     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB6C4:
    ctx->pc = 0x801DB6C4u;
    // 801DB6C4: lwz     r8, 272(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(272);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801DB6C8:
    ctx->pc = 0x801DB6C8u;
    // 801DB6C8: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_801DB6CC:
    ctx->pc = 0x801DB6CCu;
    // 801DB6CC: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DB6D0:
    ctx->pc = 0x801DB6D0u;
    // 801DB6D0: lfs     f10, 0(r5)
    if (!ppc_fp_available_inline(ctx, 0x801DB6D0u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_801DB6D4:
    ctx->pc = 0x801DB6D4u;
    // 801DB6D4: lfs     f0, 20(r8)
    if (!ppc_fp_available_inline(ctx, 0x801DB6D4u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB6D8:
    ctx->pc = 0x801DB6D8u;
    // 801DB6D8: addi    r10, r8, 20
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(20);

label_801DB6DC:
    ctx->pc = 0x801DB6DCu;
    // 801DB6DC: lfs     f9, 4640(r9)
    if (!ppc_fp_available_inline(ctx, 0x801DB6DCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4640);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_801DB6E0:
    ctx->pc = 0x801DB6E0u;
    // 801DB6E0: addi    r7, r1, 24
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(24);

label_801DB6E4:
    ctx->pc = 0x801DB6E4u;
    // 801DB6E4: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB6E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801DB6E8:
    ctx->pc = 0x801DB6E8u;
    // 801DB6E8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DB6EC:
    ctx->pc = 0x801DB6ECu;
    // 801DB6EC: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DB6F0:
    ctx->pc = 0x801DB6F0u;
    // 801DB6F0: lfs     f0, 4(r10)
    if (!ppc_fp_available_inline(ctx, 0x801DB6F0u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB6F4:
    ctx->pc = 0x801DB6F4u;
    // 801DB6F4: lfs     f11, 8(r5)
    if (!ppc_fp_available_inline(ctx, 0x801DB6F4u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_801DB6F8:
    ctx->pc = 0x801DB6F8u;
    // 801DB6F8: lfs     f12, 4(r5)
    if (!ppc_fp_available_inline(ctx, 0x801DB6F8u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801DB6FC:
    ctx->pc = 0x801DB6FCu;
    // 801DB6FC: stfs     f0, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB6FCu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801DB700:
    ctx->pc = 0x801DB700u;
    // 801DB700: lfs     f13, 8(r10)
    if (!ppc_fp_available_inline(ctx, 0x801DB700u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801DB704:
    ctx->pc = 0x801DB704u;
    // 801DB704: stfs     f9, 12(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB704u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[9]));
    }

label_801DB708:
    ctx->pc = 0x801DB708u;
    // 801DB708: stfs     f13, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB708u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801DB70C:
    ctx->pc = 0x801DB70Cu;
    // 801DB70C: stfs     f10, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB70Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_801DB710:
    ctx->pc = 0x801DB710u;
    // 801DB710: stfs     f12, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB710u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_801DB714:
    ctx->pc = 0x801DB714u;
    // 801DB714: stfs     f11, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB714u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_801DB718:
    ctx->pc = 0x801DB718u;
    // 801DB718: lwz     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB71C:
    ctx->pc = 0x801DB71Cu;
    // 801DB71C: lwz     r9, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DB720:
    ctx->pc = 0x801DB720u;
    // 801DB720: lwz     r11, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801DB724:
    ctx->pc = 0x801DB724u;
    // 801DB724: stw     r0, 20(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB728:
    ctx->pc = 0x801DB728u;
    // 801DB728: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DB72C:
    ctx->pc = 0x801DB72Cu;
    // 801DB72C: stw     r11, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DB730:
    ctx->pc = 0x801DB730u;
    // 801DB730: bl      0x801D73F8
    {
            ctx->lr = 0x801DB734u;
            ctx->pc = 0x801D73F8u;
            return;
    }

label_801DB734:
    ctx->pc = 0x801DB734u;
    ctx->downcount -= 25;
    // 801DB734: lfs     f11, 12(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB734u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_801DB738:
    ctx->pc = 0x801DB738u;
    // 801DB738: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DB73C:
    ctx->pc = 0x801DB73Cu;
    // 801DB73C: lfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB73Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB740:
    ctx->pc = 0x801DB740u;
    // 801DB740: lfs     f13, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB740u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801DB744:
    ctx->pc = 0x801DB744u;
    // 801DB744: lfs     f12, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB744u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801DB748:
    ctx->pc = 0x801DB748u;
    // 801DB748: stfs     f0, 0(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB748u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801DB74C:
    ctx->pc = 0x801DB74Cu;
    // 801DB74C: stfs     f13, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB74Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801DB750:
    ctx->pc = 0x801DB750u;
    // 801DB750: stfs     f12, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB750u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_801DB754:
    ctx->pc = 0x801DB754u;
    // 801DB754: stfs     f11, 12(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB754u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_801DB758:
    ctx->pc = 0x801DB758u;
    // 801DB758: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB75C:
    ctx->pc = 0x801DB75Cu;
    // 801DB75C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DB760:
    ctx->pc = 0x801DB760u;
    // 801DB760: lmw     r29, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DB764:
    ctx->pc = 0x801DB764u;
    // 801DB764: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_801DB768:
    ctx->pc = 0x801DB768u;
    // 801DB768: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB76C:
    ctx->pc = 0x801DB76Cu;
    ctx->downcount -= 42;
    // 801DB76C: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DB770:
    ctx->pc = 0x801DB770u;
    // 801DB770: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DB774:
    ctx->pc = 0x801DB774u;
    // 801DB774: stmw     r29, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DB778:
    ctx->pc = 0x801DB778u;
    // 801DB778: stw     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB77C:
    ctx->pc = 0x801DB77Cu;
    // 801DB77C: lwz     r8, 272(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(272);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801DB780:
    ctx->pc = 0x801DB780u;
    // 801DB780: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_801DB784:
    ctx->pc = 0x801DB784u;
    // 801DB784: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DB788:
    ctx->pc = 0x801DB788u;
    // 801DB788: lfs     f10, 0(r5)
    if (!ppc_fp_available_inline(ctx, 0x801DB788u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_801DB78C:
    ctx->pc = 0x801DB78Cu;
    // 801DB78C: lfs     f0, 44(r8)
    if (!ppc_fp_available_inline(ctx, 0x801DB78Cu)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB790:
    ctx->pc = 0x801DB790u;
    // 801DB790: addi    r10, r8, 44
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(44);

label_801DB794:
    ctx->pc = 0x801DB794u;
    // 801DB794: lfs     f9, 4644(r9)
    if (!ppc_fp_available_inline(ctx, 0x801DB794u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4644);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_801DB798:
    ctx->pc = 0x801DB798u;
    // 801DB798: addi    r7, r1, 24
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(24);

label_801DB79C:
    ctx->pc = 0x801DB79Cu;
    // 801DB79C: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB79Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801DB7A0:
    ctx->pc = 0x801DB7A0u;
    // 801DB7A0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DB7A4:
    ctx->pc = 0x801DB7A4u;
    // 801DB7A4: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DB7A8:
    ctx->pc = 0x801DB7A8u;
    // 801DB7A8: lfs     f0, 4(r10)
    if (!ppc_fp_available_inline(ctx, 0x801DB7A8u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB7AC:
    ctx->pc = 0x801DB7ACu;
    // 801DB7AC: lfs     f11, 8(r5)
    if (!ppc_fp_available_inline(ctx, 0x801DB7ACu)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_801DB7B0:
    ctx->pc = 0x801DB7B0u;
    // 801DB7B0: lfs     f12, 4(r5)
    if (!ppc_fp_available_inline(ctx, 0x801DB7B0u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801DB7B4:
    ctx->pc = 0x801DB7B4u;
    // 801DB7B4: stfs     f0, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB7B4u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801DB7B8:
    ctx->pc = 0x801DB7B8u;
    // 801DB7B8: lfs     f13, 8(r10)
    if (!ppc_fp_available_inline(ctx, 0x801DB7B8u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801DB7BC:
    ctx->pc = 0x801DB7BCu;
    // 801DB7BC: stfs     f9, 12(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB7BCu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[9]));
    }

label_801DB7C0:
    ctx->pc = 0x801DB7C0u;
    // 801DB7C0: stfs     f13, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB7C0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801DB7C4:
    ctx->pc = 0x801DB7C4u;
    // 801DB7C4: stfs     f10, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB7C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_801DB7C8:
    ctx->pc = 0x801DB7C8u;
    // 801DB7C8: stfs     f12, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB7C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_801DB7CC:
    ctx->pc = 0x801DB7CCu;
    // 801DB7CC: stfs     f11, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB7CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_801DB7D0:
    ctx->pc = 0x801DB7D0u;
    // 801DB7D0: lwz     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB7D4:
    ctx->pc = 0x801DB7D4u;
    // 801DB7D4: lwz     r9, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DB7D8:
    ctx->pc = 0x801DB7D8u;
    // 801DB7D8: lwz     r11, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801DB7DC:
    ctx->pc = 0x801DB7DCu;
    // 801DB7DC: stw     r0, 44(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB7E0:
    ctx->pc = 0x801DB7E0u;
    // 801DB7E0: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DB7E4:
    ctx->pc = 0x801DB7E4u;
    // 801DB7E4: stw     r11, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DB7E8:
    ctx->pc = 0x801DB7E8u;
    // 801DB7E8: bl      0x801D73F8
    {
            ctx->lr = 0x801DB7ECu;
            ctx->pc = 0x801D73F8u;
            return;
    }

label_801DB7EC:
    ctx->pc = 0x801DB7ECu;
    ctx->downcount -= 25;
    // 801DB7EC: lfs     f11, 12(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB7ECu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_801DB7F0:
    ctx->pc = 0x801DB7F0u;
    // 801DB7F0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DB7F4:
    ctx->pc = 0x801DB7F4u;
    // 801DB7F4: lfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB7F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB7F8:
    ctx->pc = 0x801DB7F8u;
    // 801DB7F8: lfs     f13, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB7F8u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801DB7FC:
    ctx->pc = 0x801DB7FCu;
    // 801DB7FC: lfs     f12, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB7FCu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801DB800:
    ctx->pc = 0x801DB800u;
    // 801DB800: stfs     f0, 0(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB800u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801DB804:
    ctx->pc = 0x801DB804u;
    // 801DB804: stfs     f13, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB804u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801DB808:
    ctx->pc = 0x801DB808u;
    // 801DB808: stfs     f12, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB808u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_801DB80C:
    ctx->pc = 0x801DB80Cu;
    // 801DB80C: stfs     f11, 12(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB80Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_801DB810:
    ctx->pc = 0x801DB810u;
    // 801DB810: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB814:
    ctx->pc = 0x801DB814u;
    // 801DB814: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DB818:
    ctx->pc = 0x801DB818u;
    // 801DB818: lmw     r29, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DB81C:
    ctx->pc = 0x801DB81Cu;
    // 801DB81C: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_801DB820:
    ctx->pc = 0x801DB820u;
    // 801DB820: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB824:
    ctx->pc = 0x801DB824u;
    ctx->downcount -= 42;
    // 801DB824: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DB828:
    ctx->pc = 0x801DB828u;
    // 801DB828: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DB82C:
    ctx->pc = 0x801DB82Cu;
    // 801DB82C: stmw     r29, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DB830:
    ctx->pc = 0x801DB830u;
    // 801DB830: stw     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB834:
    ctx->pc = 0x801DB834u;
    // 801DB834: lwz     r8, 272(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(272);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801DB838:
    ctx->pc = 0x801DB838u;
    // 801DB838: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_801DB83C:
    ctx->pc = 0x801DB83Cu;
    // 801DB83C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DB840:
    ctx->pc = 0x801DB840u;
    // 801DB840: lfs     f10, 0(r5)
    if (!ppc_fp_available_inline(ctx, 0x801DB840u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_801DB844:
    ctx->pc = 0x801DB844u;
    // 801DB844: lfs     f0, 8(r8)
    if (!ppc_fp_available_inline(ctx, 0x801DB844u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB848:
    ctx->pc = 0x801DB848u;
    // 801DB848: addi    r10, r8, 8
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(8);

label_801DB84C:
    ctx->pc = 0x801DB84Cu;
    // 801DB84C: lfs     f9, 4648(r9)
    if (!ppc_fp_available_inline(ctx, 0x801DB84Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4648);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_801DB850:
    ctx->pc = 0x801DB850u;
    // 801DB850: addi    r7, r1, 24
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(24);

label_801DB854:
    ctx->pc = 0x801DB854u;
    // 801DB854: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB854u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801DB858:
    ctx->pc = 0x801DB858u;
    // 801DB858: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DB85C:
    ctx->pc = 0x801DB85Cu;
    // 801DB85C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DB860:
    ctx->pc = 0x801DB860u;
    // 801DB860: lfs     f0, 4(r10)
    if (!ppc_fp_available_inline(ctx, 0x801DB860u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB864:
    ctx->pc = 0x801DB864u;
    // 801DB864: lfs     f11, 8(r5)
    if (!ppc_fp_available_inline(ctx, 0x801DB864u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_801DB868:
    ctx->pc = 0x801DB868u;
    // 801DB868: lfs     f12, 4(r5)
    if (!ppc_fp_available_inline(ctx, 0x801DB868u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801DB86C:
    ctx->pc = 0x801DB86Cu;
    // 801DB86C: stfs     f0, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB86Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801DB870:
    ctx->pc = 0x801DB870u;
    // 801DB870: lfs     f13, 8(r10)
    if (!ppc_fp_available_inline(ctx, 0x801DB870u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801DB874:
    ctx->pc = 0x801DB874u;
    // 801DB874: stfs     f9, 12(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB874u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[9]));
    }

label_801DB878:
    ctx->pc = 0x801DB878u;
    // 801DB878: stfs     f13, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB878u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801DB87C:
    ctx->pc = 0x801DB87Cu;
    // 801DB87C: stfs     f10, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB87Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_801DB880:
    ctx->pc = 0x801DB880u;
    // 801DB880: stfs     f12, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB880u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_801DB884:
    ctx->pc = 0x801DB884u;
    // 801DB884: stfs     f11, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB884u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_801DB888:
    ctx->pc = 0x801DB888u;
    // 801DB888: lwz     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB88C:
    ctx->pc = 0x801DB88Cu;
    // 801DB88C: lwz     r9, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DB890:
    ctx->pc = 0x801DB890u;
    // 801DB890: lwz     r11, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801DB894:
    ctx->pc = 0x801DB894u;
    // 801DB894: stw     r0, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB898:
    ctx->pc = 0x801DB898u;
    // 801DB898: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DB89C:
    ctx->pc = 0x801DB89Cu;
    // 801DB89C: stw     r11, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DB8A0:
    ctx->pc = 0x801DB8A0u;
    // 801DB8A0: bl      0x801D73F8
    {
            ctx->lr = 0x801DB8A4u;
            ctx->pc = 0x801D73F8u;
            return;
    }

label_801DB8A4:
    ctx->pc = 0x801DB8A4u;
    ctx->downcount -= 25;
    // 801DB8A4: lfs     f11, 12(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB8A4u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_801DB8A8:
    ctx->pc = 0x801DB8A8u;
    // 801DB8A8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DB8AC:
    ctx->pc = 0x801DB8ACu;
    // 801DB8AC: lfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DB8ACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DB8B0:
    ctx->pc = 0x801DB8B0u;
    // 801DB8B0: lfs     f13, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB8B0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801DB8B4:
    ctx->pc = 0x801DB8B4u;
    // 801DB8B4: lfs     f12, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x801DB8B4u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801DB8B8:
    ctx->pc = 0x801DB8B8u;
    // 801DB8B8: stfs     f0, 0(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB8B8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801DB8BC:
    ctx->pc = 0x801DB8BCu;
    // 801DB8BC: stfs     f13, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB8BCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801DB8C0:
    ctx->pc = 0x801DB8C0u;
    // 801DB8C0: stfs     f12, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB8C0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_801DB8C4:
    ctx->pc = 0x801DB8C4u;
    // 801DB8C4: stfs     f11, 12(r30)
    if (!ppc_fp_available_inline(ctx, 0x801DB8C4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_801DB8C8:
    ctx->pc = 0x801DB8C8u;
    // 801DB8C8: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB8CC:
    ctx->pc = 0x801DB8CCu;
    // 801DB8CC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DB8D0:
    ctx->pc = 0x801DB8D0u;
    // 801DB8D0: lmw     r29, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DB8D4:
    ctx->pc = 0x801DB8D4u;
    // 801DB8D4: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_801DB8D8:
    ctx->pc = 0x801DB8D8u;
    // 801DB8D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB8DC:
    ctx->pc = 0x801DB8DCu;
    ctx->downcount -= 8;
    // 801DB8DC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DB8E0:
    ctx->pc = 0x801DB8E0u;
    // 801DB8E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DB8E4:
    ctx->pc = 0x801DB8E4u;
    // 801DB8E4: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DB8E8:
    ctx->pc = 0x801DB8E8u;
    // 801DB8E8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB8EC:
    ctx->pc = 0x801DB8ECu;
    // 801DB8EC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DB8F0:
    ctx->pc = 0x801DB8F0u;
    // 801DB8F0: lwz     r0, 284(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(284);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB8F4:
    ctx->pc = 0x801DB8F4u;
    // 801DB8F4: cmpwi   r0, 0
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

label_801DB8F8:
    ctx->pc = 0x801DB8F8u;
    // 801DB8F8: bc    4, 2, 0x801DB900
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DB900;
        }
    }

label_801DB8FC:
    ctx->pc = 0x801DB8FCu;
    ctx->downcount -= 1;
    // 801DB8FC: bl      0x801DA1BC
    {
            ctx->lr = 0x801DB900u;
            ctx->pc = 0x801DA1BCu;
            return;
    }

label_801DB900:
    ctx->pc = 0x801DB900u;
    ctx->downcount -= 7;
    // 801DB900: lwz     r3, 1068(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1068);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DB904:
    ctx->pc = 0x801DB904u;
    // 801DB904: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB908:
    ctx->pc = 0x801DB908u;
    // 801DB908: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DB90C:
    ctx->pc = 0x801DB90Cu;
    // 801DB90C: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DB910:
    ctx->pc = 0x801DB910u;
    // 801DB910: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DB914:
    ctx->pc = 0x801DB914u;
    // 801DB914: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB918:
    ctx->pc = 0x801DB918u;
    ctx->downcount -= 3;
    // 801DB918: lwz     r0, -30564(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30564);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB91C:
    ctx->pc = 0x801DB91Cu;
    // 801DB91C: cmpwi   r0, 0
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

label_801DB920:
    ctx->pc = 0x801DB920u;
    // 801DB920: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB924:
    ctx->pc = 0x801DB924u;
    ctx->downcount -= 3;
    // 801DB924: lwz     r0, 436(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(436);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB928:
    ctx->pc = 0x801DB928u;
    // 801DB928: cmpwi   r0, 0
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

label_801DB92C:
    ctx->pc = 0x801DB92Cu;
    // 801DB92C: bc    4, 2, 0x801DB93C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DB93C;
        }
    }

label_801DB930:
    ctx->pc = 0x801DB930u;
    ctx->downcount -= 3;
    // 801DB930: lwz     r0, -30560(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30560);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB934:
    ctx->pc = 0x801DB934u;
    // 801DB934: stw     r0, 432(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(432);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB938:
    ctx->pc = 0x801DB938u;
    // 801DB938: stw     r3, -30560(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30560);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DB93C:
    ctx->pc = 0x801DB93Cu;
    ctx->downcount -= 12;
    // 801DB93C: lwz     r9, -30564(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30564);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DB940:
    ctx->pc = 0x801DB940u;
    // 801DB940: lis     r11, -32709
    ctx->gpr[11] = ((u32)(s32)(-32709) << 16);

label_801DB944:
    ctx->pc = 0x801DB944u;
    // 801DB944: addi    r11, r11, 19112
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(19112);

label_801DB948:
    ctx->pc = 0x801DB948u;
    // 801DB948: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801DB94C:
    ctx->pc = 0x801DB94Cu;
    // 801DB94C: rlwinm r8, r9, 3, 0, 28
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[9], 3u) & 0xFFFFFFF8u;
    }

label_801DB950:
    ctx->pc = 0x801DB950u;
    // 801DB950: stw     r9, -30564(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30564);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DB954:
    ctx->pc = 0x801DB954u;
    // 801DB954: add   r10, r8, r11
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_801DB958:
    ctx->pc = 0x801DB958u;
    // 801DB958: stw     r4, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801DB95C:
    ctx->pc = 0x801DB95Cu;
    // 801DB95C: lwz     r0, 436(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(436);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB960:
    ctx->pc = 0x801DB960u;
    // 801DB960: stwx    r0, r8, r11
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[11];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB964:
    ctx->pc = 0x801DB964u;
    // 801DB964: stw     r10, 436(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(436);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801DB968:
    ctx->pc = 0x801DB968u;
    // 801DB968: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB96C:
    ctx->pc = 0x801DB96Cu;
    ctx->downcount -= 1;
    // 801DB96C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DB970:
    ctx->pc = 0x801DB970u;
    ctx->downcount -= 22;
    // 801DB970: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DB974:
    ctx->pc = 0x801DB974u;
    // 801DB974: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DB978:
    ctx->pc = 0x801DB978u;
    // 801DB978: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DB97C:
    ctx->pc = 0x801DB97Cu;
    // 801DB97C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DB980:
    ctx->pc = 0x801DB980u;
    // 801DB980: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DB984:
    ctx->pc = 0x801DB984u;
    // 801DB984: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DB988:
    ctx->pc = 0x801DB988u;
    // 801DB988: lwz     r9, 272(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(272);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DB98C:
    ctx->pc = 0x801DB98Cu;
    // 801DB98C: or   r31, r5, r5
    {
        ctx->gpr[31] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801DB990:
    ctx->pc = 0x801DB990u;
    // 801DB990: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_801DB994:
    ctx->pc = 0x801DB994u;
    // 801DB994: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB998:
    ctx->pc = 0x801DB998u;
    // 801DB998: cmpwi   r0, 21
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(21);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DB99C:
    ctx->pc = 0x801DB99Cu;
    // 801DB99C: bc    4, 2, 0x801DB9AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DB9AC;
        }
    }

label_801DB9A0:
    ctx->pc = 0x801DB9A0u;
    ctx->downcount -= 3;
    // 801DB9A0: lwz     r0, 288(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(288);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB9A4:
    ctx->pc = 0x801DB9A4u;
    // 801DB9A4: subfic  r9, r0, 0
    {
        u64 res = (u64)(u32)(s32)(0) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[9] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_801DB9A8:
    ctx->pc = 0x801DB9A8u;
    // 801DB9A8: adde   r11, r9, r0
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[11] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801DB9AC:
    ctx->pc = 0x801DB9ACu;
    ctx->downcount -= 2;
    // 801DB9AC: cmpwi   r11, 0
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

label_801DB9B0:
    ctx->pc = 0x801DB9B0u;
    // 801DB9B0: bc    12, 2, 0x801DB9C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DB9C8;
        }
    }

label_801DB9B4:
    ctx->pc = 0x801DB9B4u;
    ctx->downcount -= 4;
    // 801DB9B4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DB9B8:
    ctx->pc = 0x801DB9B8u;
    // 801DB9B8: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DB9BC:
    ctx->pc = 0x801DB9BCu;
    // 801DB9BC: or   r5, r31, r31
    {
        ctx->gpr[5] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DB9C0:
    ctx->pc = 0x801DB9C0u;
    // 801DB9C0: bl      0x801DA82C
    {
            ctx->lr = 0x801DB9C4u;
            ctx->pc = 0x801DA82Cu;
            return;
    }

label_801DB9C4:
    ctx->pc = 0x801DB9C4u;
    ctx->downcount -= 1;
    // 801DB9C4: b       0x801DBA78
    {
            goto label_801DBA78;
    }

label_801DB9C8:
    ctx->pc = 0x801DB9C8u;
    ctx->downcount -= 3;
    // 801DB9C8: lwz     r0, 284(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(284);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB9CC:
    ctx->pc = 0x801DB9CCu;
    // 801DB9CC: cmpwi   r0, 0
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

label_801DB9D0:
    ctx->pc = 0x801DB9D0u;
    // 801DB9D0: bc    4, 2, 0x801DB9E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DB9E8;
        }
    }

label_801DB9D4:
    ctx->pc = 0x801DB9D4u;
    ctx->downcount -= 2;
    // 801DB9D4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DB9D8:
    ctx->pc = 0x801DB9D8u;
    // 801DB9D8: bl      0x801DA1BC
    {
            ctx->lr = 0x801DB9DCu;
            ctx->pc = 0x801DA1BCu;
            return;
    }

label_801DB9DC:
    ctx->pc = 0x801DB9DCu;
    ctx->downcount -= 3;
    // 801DB9DC: lwz     r0, 284(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(284);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB9E0:
    ctx->pc = 0x801DB9E0u;
    // 801DB9E0: cmpwi   r0, 0
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

label_801DB9E4:
    ctx->pc = 0x801DB9E4u;
    // 801DB9E4: bc    12, 2, 0x801DBA78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBA78;
        }
    }

label_801DB9E8:
    ctx->pc = 0x801DB9E8u;
    ctx->downcount -= 3;
    // 801DB9E8: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DB9EC:
    ctx->pc = 0x801DB9ECu;
    // 801DB9EC: addi    r31, r30, 360
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(360);

label_801DB9F0:
    ctx->pc = 0x801DB9F0u;
    // 801DB9F0: bc    12, 2, 0x801DBA00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBA00;
        }
    }

label_801DB9F4:
    ctx->pc = 0x801DB9F4u;
    ctx->downcount -= 3;
    // 801DB9F4: lwz     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DB9F8:
    ctx->pc = 0x801DB9F8u;
    // 801DB9F8: ori     r0, r0, 0x0100
    ctx->gpr[0] = ctx->gpr[0] | 0x0100u;

label_801DB9FC:
    ctx->pc = 0x801DB9FCu;
    // 801DB9FC: b       0x801DBA08
    {
            goto label_801DBA08;
    }

label_801DBA00:
    ctx->pc = 0x801DBA00u;
    ctx->downcount -= 2;
    // 801DBA00: lwz     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBA04:
    ctx->pc = 0x801DBA04u;
    // 801DBA04: rlwinm r0, r0, 0, 24, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFEFFu;
    }

label_801DBA08:
    ctx->pc = 0x801DBA08u;
    ctx->downcount -= 10;
    // 801DBA08: stw     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBA0C:
    ctx->pc = 0x801DBA0Cu;
    // 801DBA0C: lwz     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBA10:
    ctx->pc = 0x801DBA10u;
    // 801DBA10: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_801DBA14:
    ctx->pc = 0x801DBA14u;
    // 801DBA14: addi    r9, r30, 296
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(296);

label_801DBA18:
    ctx->pc = 0x801DBA18u;
    // 801DBA18: rlwinm r0, r0, 0, 23, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFDFFu;
    }

label_801DBA1C:
    ctx->pc = 0x801DBA1Cu;
    // 801DBA1C: stw     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBA20:
    ctx->pc = 0x801DBA20u;
    // 801DBA20: stw     r28, 344(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(344);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_801DBA24:
    ctx->pc = 0x801DBA24u;
    // 801DBA24: lwz     r0, 40(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBA28:
    ctx->pc = 0x801DBA28u;
    // 801DBA28: cmpw    r9, r0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DBA2C:
    ctx->pc = 0x801DBA2Cu;
    // 801DBA2C: bc    12, 2, 0x801DBA38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBA38;
        }
    }

label_801DBA30:
    ctx->pc = 0x801DBA30u;
    ctx->downcount -= 2;
    // 801DBA30: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DBA34:
    ctx->pc = 0x801DBA34u;
    // 801DBA34: bl      0x801DADEC
    {
            ctx->lr = 0x801DBA38u;
            ctx->pc = 0x801DADECu;
            return;
    }

label_801DBA38:
    ctx->pc = 0x801DBA38u;
    ctx->downcount -= 6;
    // 801DBA38: lbz     r4, 2(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801DBA3C:
    ctx->pc = 0x801DBA3Cu;
    // 801DBA3C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DBA40:
    ctx->pc = 0x801DBA40u;
    // 801DBA40: xori    r4, r4, 0x0001
    ctx->gpr[4] = ctx->gpr[4] ^ 0x0001u;

label_801DBA44:
    ctx->pc = 0x801DBA44u;
    // 801DBA44: subfic  r0, r4, 0
    {
        u64 res = (u64)(u32)(s32)(0) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_801DBA48:
    ctx->pc = 0x801DBA48u;
    // 801DBA48: adde   r4, r0, r4
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801DBA4C:
    ctx->pc = 0x801DBA4Cu;
    // 801DBA4C: bl      0x8023DF34
    {
            ctx->lr = 0x801DBA50u;
            ctx->pc = 0x8023DF34u;
            return;
    }

label_801DBA50:
    ctx->pc = 0x801DBA50u;
    ctx->downcount -= 2;
    // 801DBA50: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DBA54:
    ctx->pc = 0x801DBA54u;
    // 801DBA54: bl      0x80244970
    {
            ctx->lr = 0x801DBA58u;
            ctx->pc = 0x80244970u;
            return;
    }

label_801DBA58:
    ctx->pc = 0x801DBA58u;
    ctx->downcount -= 3;
    // 801DBA58: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DBA5C:
    ctx->pc = 0x801DBA5Cu;
    // 801DBA5C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DBA60:
    ctx->pc = 0x801DBA60u;
    // 801DBA60: bl      0x801DA750
    {
            ctx->lr = 0x801DBA64u;
            ctx->pc = 0x801DA750u;
            return;
    }

label_801DBA64:
    ctx->pc = 0x801DBA64u;
    ctx->downcount -= 4;
    // 801DBA64: lwz     r9, -26628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26628);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBA68:
    ctx->pc = 0x801DBA68u;
    // 801DBA68: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBA6C:
    ctx->pc = 0x801DBA6Cu;
    // 801DBA6C: cmpwi   r0, 0
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

label_801DBA70:
    ctx->pc = 0x801DBA70u;
    // 801DBA70: bc    12, 2, 0x801DBA78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBA78;
        }
    }

label_801DBA74:
    ctx->pc = 0x801DBA74u;
    ctx->downcount -= 1;
    // 801DBA74: stw     r28, 284(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(284);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_801DBA78:
    ctx->pc = 0x801DBA78u;
    ctx->downcount -= 16;
    // 801DBA78: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBA7C:
    ctx->pc = 0x801DBA7Cu;
    // 801DBA7C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBA80:
    ctx->pc = 0x801DBA80u;
    // 801DBA80: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DBA84:
    ctx->pc = 0x801DBA84u;
    // 801DBA84: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DBA88:
    ctx->pc = 0x801DBA88u;
    // 801DBA88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBA8C:
    ctx->pc = 0x801DBA8Cu;
    ctx->downcount -= 3;
    // 801DBA8C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DBA90:
    ctx->pc = 0x801DBA90u;
    // 801DBA90: stw     r0, 284(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(284);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBA94:
    ctx->pc = 0x801DBA94u;
    // 801DBA94: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBA98:
    ctx->pc = 0x801DBA98u;
    ctx->downcount -= 11;
    // 801DBA98: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBA9C:
    ctx->pc = 0x801DBA9Cu;
    // 801DBA9C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBAA0:
    ctx->pc = 0x801DBAA0u;
    // 801DBAA0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBAA4:
    ctx->pc = 0x801DBAA4u;
    // 801DBAA4: lwz     r5, 88(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(88);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801DBAA8:
    ctx->pc = 0x801DBAA8u;
    // 801DBAA8: lwz     r3, 272(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(272);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DBAAC:
    ctx->pc = 0x801DBAACu;
    // 801DBAAC: subfic  r5, r5, 4
    {
        u64 res = (u64)(u32)(s32)(4) + (u64)(~ctx->gpr[5]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_801DBAB0:
    ctx->pc = 0x801DBAB0u;
    // 801DBAB0: mulli   r5, r5, 120
    ctx->gpr[5] = (u32)((s64)(s32)ctx->gpr[5] * (s64)(s32)120);

label_801DBAB4:
    ctx->pc = 0x801DBAB4u;
    // 801DBAB4: subfic  r5, r5, 572
    {
        u64 res = (u64)(u32)(s32)(572) + (u64)(~ctx->gpr[5]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_801DBAB8:
    ctx->pc = 0x801DBAB8u;
    // 801DBAB8: bl      0x80297D08
    {
            ctx->lr = 0x801DBABCu;
            ctx->pc = 0x80297D08u;
            return;
    }

label_801DBABC:
    ctx->pc = 0x801DBABCu;
    ctx->downcount -= 7;
    // 801DBABC: subfic  r0, r3, 0
    {
        u64 res = (u64)(u32)(s32)(0) + (u64)(~ctx->gpr[3]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_801DBAC0:
    ctx->pc = 0x801DBAC0u;
    // 801DBAC0: adde   r3, r0, r3
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801DBAC4:
    ctx->pc = 0x801DBAC4u;
    // 801DBAC4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBAC8:
    ctx->pc = 0x801DBAC8u;
    // 801DBAC8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBACC:
    ctx->pc = 0x801DBACCu;
    // 801DBACC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DBAD0:
    ctx->pc = 0x801DBAD0u;
    // 801DBAD0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBAD4:
    ctx->pc = 0x801DBAD4u;
    ctx->downcount -= 5;
    // 801DBAD4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBAD8:
    ctx->pc = 0x801DBAD8u;
    // 801DBAD8: lwz     r9, 272(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(272);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBADC:
    ctx->pc = 0x801DBADCu;
    // 801DBADC: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBAE0:
    ctx->pc = 0x801DBAE0u;
    // 801DBAE0: cmpwi   r0, 0
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

label_801DBAE4:
    ctx->pc = 0x801DBAE4u;
    // 801DBAE4: bc    4, 2, 0x801DBB8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DBB8C;
        }
    }

label_801DBAE8:
    ctx->pc = 0x801DBAE8u;
    ctx->downcount -= 4;
    // 801DBAE8: lwz     r0, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBAEC:
    ctx->pc = 0x801DBAECu;
    // 801DBAEC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801DBAF0:
    ctx->pc = 0x801DBAF0u;
    // 801DBAF0: cmpw    r10, r0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DBAF4:
    ctx->pc = 0x801DBAF4u;
    // 801DBAF4: bc    4, 0, 0x801DBB8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DBB8C;
        }
    }

label_801DBAF8:
    ctx->pc = 0x801DBAF8u;
    ctx->downcount -= 6;
    // 801DBAF8: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DBAFC:
    ctx->pc = 0x801DBAFCu;
    // 801DBAFC: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_801DBB00:
    ctx->pc = 0x801DBB00u;
    // 801DBB00: lfs     f12, 4652(r9)
    if (!ppc_fp_available_inline(ctx, 0x801DBB00u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4652);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801DBB04:
    ctx->pc = 0x801DBB04u;
    // 801DBB04: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_801DBB08:
    ctx->pc = 0x801DBB08u;
    // 801DBB08: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_801DBB0C:
    ctx->pc = 0x801DBB0Cu;
    // 801DBB0C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801DBB10:
    ctx->pc = 0x801DBB10u;
    ctx->downcount -= 9;
    // 801DBB10: stfs     f12, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DBB10u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_801DBB14:
    // 801DBB14: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_801DBB18:
    ctx->pc = 0x801DBB18u;
    // 801DBB18: lwz     r0, 272(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(272);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBB1C:
    ctx->pc = 0x801DBB1Cu;
    // 801DBB1C: stfs     f12, 4(r5)
    if (!ppc_fp_available_inline(ctx, 0x801DBB1Cu)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_801DBB20:
    // 801DBB20: add   r9, r8, r0
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_801DBB24:
    ctx->pc = 0x801DBB24u;
    // 801DBB24: lfs     f13, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DBB24u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801DBB28:
    ctx->pc = 0x801DBB28u;
    // 801DBB28: lfsu     f0, 132(r9)
    if (!ppc_fp_available_inline(ctx, 0x801DBB28u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(132);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
        ctx->gpr[9] = ea;
    }

label_801DBB2C:
    ctx->pc = 0x801DBB2Cu;
    // 801DBB2C: fcmpu   cr0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x801DBB2Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[13], false);

label_801DBB30:
    // 801DBB30: bc    4, 2, 0x801DBB40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DBB40;
        }
    }

label_801DBB34:
    ctx->pc = 0x801DBB34u;
    ctx->downcount -= 3;
    // 801DBB34: lfs     f0, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x801DBB34u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DBB38:
    ctx->pc = 0x801DBB38u;
    // 801DBB38: fcmpu   cr0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x801DBB38u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[12], false);

label_801DBB3C:
    // 801DBB3C: bc    12, 2, 0x801DBB44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBB44;
        }
    }

label_801DBB40:
    ctx->downcount -= 1;
    // 801DBB40: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_801DBB44:
    ctx->downcount -= 2;
    // 801DBB44: cmpwi   r11, 0
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

label_801DBB48:
    // 801DBB48: bc    12, 2, 0x801DBB58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBB58;
        }
    }

label_801DBB4C:
    ctx->pc = 0x801DBB4Cu;
    ctx->downcount -= 3;
    // 801DBB4C: lwz     r9, 272(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(272);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBB50:
    ctx->pc = 0x801DBB50u;
    // 801DBB50: stw     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801DBB54:
    // 801DBB54: b       0x801DBB8C
    {
            goto label_801DBB8C;
    }

label_801DBB58:
    ctx->pc = 0x801DBB58u;
    ctx->downcount -= 5;
    // 801DBB58: lwz     r11, 272(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(272);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801DBB5C:
    // 801DBB5C: addi    r9, r11, 100
    ctx->gpr[9] = ctx->gpr[11] + (u32)(s32)(100);

label_801DBB60:
    ctx->pc = 0x801DBB60u;
    // 801DBB60: lfsx    f0, r9, r7
    if (!ppc_fp_available_inline(ctx, 0x801DBB60u)) return;
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[7];
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801DBB64:
    ctx->pc = 0x801DBB64u;
    // 801DBB64: fcmpu   cr0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x801DBB64u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[12], false);

label_801DBB68:
    // 801DBB68: bc    12, 2, 0x801DBB74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBB74;
        }
    }

label_801DBB6C:
    ctx->pc = 0x801DBB6Cu;
    ctx->downcount -= 2;
    // 801DBB6C: stw     r6, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801DBB70:
    // 801DBB70: b       0x801DBB8C
    {
            goto label_801DBB8C;
    }

label_801DBB74:
    ctx->pc = 0x801DBB74u;
    ctx->downcount -= 6;
    // 801DBB74: lwz     r0, 88(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBB78:
    // 801DBB78: addi    r10, r10, 1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(1);

label_801DBB7C:
    // 801DBB7C: addi    r7, r7, 120
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(120);

label_801DBB80:
    // 801DBB80: addi    r8, r8, 120
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(120);

label_801DBB84:
    // 801DBB84: cmpw    r10, r0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DBB88:
    // 801DBB88: bc    12, 0, 0x801DBB10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DBB10u;
                return;
            }
            goto label_801DBB10;
        }
    }

label_801DBB8C:
    ctx->pc = 0x801DBB8Cu;
    ctx->downcount -= 2;
    // 801DBB8C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DBB90:
    ctx->pc = 0x801DBB90u;
    // 801DBB90: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBB94:
    ctx->pc = 0x801DBB94u;
    ctx->downcount -= 7;
    // 801DBB94: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBB98:
    ctx->pc = 0x801DBB98u;
    // 801DBB98: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBB9C:
    ctx->pc = 0x801DBB9Cu;
    // 801DBB9C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBBA0:
    ctx->pc = 0x801DBBA0u;
    // 801DBBA0: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DBBA4:
    ctx->pc = 0x801DBBA4u;
    // 801DBBA4: lis     r4, 29557
    ctx->gpr[4] = ((u32)(s32)(29557) << 16);

label_801DBBA8:
    ctx->pc = 0x801DBBA8u;
    // 801DBBA8: ori     r4, r4, 0x7266
    ctx->gpr[4] = ctx->gpr[4] | 0x7266u;

label_801DBBAC:
    ctx->pc = 0x801DBBACu;
    // 801DBBAC: bl      0x80213200
    {
            ctx->lr = 0x801DBBB0u;
            ctx->pc = 0x80213200u;
            return;
    }

label_801DBBB0:
    ctx->pc = 0x801DBBB0u;
    ctx->downcount -= 5;
    // 801DBBB0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBBB4:
    ctx->pc = 0x801DBBB4u;
    // 801DBBB4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBBB8:
    ctx->pc = 0x801DBBB8u;
    // 801DBBB8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DBBBC:
    ctx->pc = 0x801DBBBCu;
    // 801DBBBC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBBC0:
    ctx->pc = 0x801DBBC0u;
    ctx->downcount -= 7;
    // 801DBBC0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBBC4:
    ctx->pc = 0x801DBBC4u;
    // 801DBBC4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBBC8:
    ctx->pc = 0x801DBBC8u;
    // 801DBBC8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBBCC:
    ctx->pc = 0x801DBBCCu;
    // 801DBBCC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DBBD0:
    ctx->pc = 0x801DBBD0u;
    // 801DBBD0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801DBBD4:
    ctx->pc = 0x801DBBD4u;
    // 801DBBD4: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_801DBBD8:
    ctx->pc = 0x801DBBD8u;
    // 801DBBD8: bl      0x801DB2C4
    {
            ctx->lr = 0x801DBBDCu;
            ctx->pc = 0x801DB2C4u;
            return;
    }

label_801DBBDC:
    ctx->pc = 0x801DBBDCu;
    ctx->downcount -= 5;
    // 801DBBDC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBBE0:
    ctx->pc = 0x801DBBE0u;
    // 801DBBE0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBBE4:
    ctx->pc = 0x801DBBE4u;
    // 801DBBE4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DBBE8:
    ctx->pc = 0x801DBBE8u;
    // 801DBBE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBBEC:
    ctx->pc = 0x801DBBECu;
    ctx->downcount -= 16;
    // 801DBBEC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBBF0:
    ctx->pc = 0x801DBBF0u;
    // 801DBBF0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBBF4:
    ctx->pc = 0x801DBBF4u;
    // 801DBBF4: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DBBF8:
    ctx->pc = 0x801DBBF8u;
    // 801DBBF8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBBFC:
    ctx->pc = 0x801DBBFCu;
    // 801DBBFC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DBC00:
    ctx->pc = 0x801DBC00u;
    // 801DBC00: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DBC04:
    ctx->pc = 0x801DBC04u;
    ctx->downcount -= 11;
    // 801DBC04: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBC08:
    ctx->pc = 0x801DBC08u;
    // 801DBC08: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBC0C:
    // 801DBC0C: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_801DBC10:
    ctx->pc = 0x801DBC10u;
    // 801DBC10: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DBC14:
    // 801DBC14: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_801DBC18:
    // 801DBC18: cmplw   r10, r11
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

label_801DBC1C:
    // 801DBC1C: bc    12, 0, 0x801DBC44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBC44;
        }
    }

label_801DBC20:
    ctx->downcount -= 3;
    // 801DBC20: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DBC24:
    ctx->pc = 0x801DBC24u;
    // 801DBC24: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBC28:
    // 801DBC28: b       0x801DBD1C
    {
            goto label_801DBD1C;
    }

label_801DBC2C:
    ctx->pc = 0x801DBC2Cu;
    ctx->downcount -= 6;
    // 801DBC2C: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBC30:
    // 801DBC30: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DBC34:
    ctx->pc = 0x801DBC34u;
    // 801DBC34: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBC38:
    ctx->pc = 0x801DBC38u;
    // 801DBC38: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DBC3C:
    ctx->pc = 0x801DBC3Cu;
    // 801DBC3C: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801DBC40:
    // 801DBC40: b       0x801DBC04
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DBC04u;
                return;
            }
            goto label_801DBC04;
    }

label_801DBC44:
    ctx->downcount -= 2;
    // 801DBC44: cmplw   r10, r30
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

label_801DBC48:
    // 801DBC48: bc    12, 0, 0x801DBC68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBC68;
        }
    }

label_801DBC4C:
    ctx->downcount -= 50;
    // 801DBC4C: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_801DBC50:
    ctx->pc = 0x801DBC50u;
    // 801DBC50: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBC54:
    // 801DBC54: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_801DBC58:
    ctx->pc = 0x801DBC58u;
    // 801DBC58: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DBC5C:
    // 801DBC5C: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DBC60:
    ctx->pc = 0x801DBC60u;
    // 801DBC60: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBC64:
    // 801DBC64: b       0x801DBD1C
    {
            goto label_801DBD1C;
    }

label_801DBC68:
    ctx->pc = 0x801DBC68u;
    ctx->downcount -= 8;
    // 801DBC68: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBC6C:
    // 801DBC6C: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DBC70:
    // 801DBC70: cmpwi   r10, 0
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

label_801DBC74:
    // 801DBC74: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_801DBC78:
    // 801DBC78: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_801DBC7C:
    // 801DBC7C: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_801DBC80:
    // 801DBC80: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_801DBC84:
    // 801DBC84: bc    12, 2, 0x801DBCA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBCA4;
        }
    }

label_801DBC88:
    ctx->downcount -= 7;
    // 801DBC88: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_801DBC8C:
    // 801DBC8C: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801DBC90:
    // 801DBC90: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DBC94:
    // 801DBC94: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801DBC98:
    ctx->pc = 0x801DBC98u;
    // 801DBC98: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801DBC9C:
    ctx->pc = 0x801DBC9Cu;
    // 801DBC9C: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DBCA0:
    ctx->pc = 0x801DBCA0u;
    // 801DBCA0: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DBCA4:
    ctx->downcount -= 2;
    // 801DBCA4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DBCA8:
    // 801DBCA8: bl      0x80281C60
    {
            ctx->lr = 0x801DBCACu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801DBCAC:
    ctx->downcount -= 3;
    // 801DBCAC: cmpwi   r3, 0
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

label_801DBCB0:
    ctx->pc = 0x801DBCB0u;
    // 801DBCB0: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DBCB4:
    // 801DBCB4: bc    4, 2, 0x801DBD00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DBD00;
        }
    }

label_801DBCB8:
    ctx->downcount -= 3;
    // 801DBCB8: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DBCBC:
    // 801DBCBC: cmplwi  r11, 0x0080
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

label_801DBCC0:
    // 801DBCC0: bc    12, 1, 0x801DBCEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBCEC;
        }
    }

label_801DBCC4:
    ctx->downcount -= 2;
    // 801DBCC4: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801DBCC8:
    // 801DBCC8: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801DBCCC:
    ctx->downcount -= 5;
    // 801DBCCC: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_801DBCD0:
    // 801DBCD0: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DBCD4:
    ctx->pc = 0x801DBCD4u;
    // 801DBCD4: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801DBCD8:
    // 801DBCD8: cmpwi   r10, 0
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

label_801DBCDC:
    // 801DBCDC: bc    4, 2, 0x801DBC2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DBC2Cu;
                return;
            }
            goto label_801DBC2C;
        }
    }

label_801DBCE0:
    ctx->downcount -= 3;
    // 801DBCE0: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_801DBCE4:
    // 801DBCE4: cmplwi  r11, 0x0080
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

label_801DBCE8:
    // 801DBCE8: bc    4, 1, 0x801DBCCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DBCCCu;
                return;
            }
            goto label_801DBCCC;
        }
    }

label_801DBCEC:
    ctx->downcount -= 4;
    // 801DBCEC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DBCF0:
    // 801DBCF0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DBCF4:
    ctx->pc = 0x801DBCF4u;
    // 801DBCF4: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBCF8:
    // 801DBCF8: bl      0x80281C60
    {
            ctx->lr = 0x801DBCFCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801DBCFC:
    ctx->pc = 0x801DBCFCu;
    ctx->downcount -= 1;
    // 801DBCFC: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DBD00:
    ctx->pc = 0x801DBD00u;
    ctx->downcount -= 7;
    // 801DBD00: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBD04:
    ctx->pc = 0x801DBD04u;
    // 801DBD04: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBD08:
    // 801DBD08: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DBD0C:
    // 801DBD0C: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_801DBD10:
    ctx->pc = 0x801DBD10u;
    // 801DBD10: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBD14:
    ctx->pc = 0x801DBD14u;
    // 801DBD14: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DBD18:
    // 801DBD18: b       0x801DBC04
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DBC04u;
                return;
            }
            goto label_801DBC04;
    }

label_801DBD1C:
    ctx->pc = 0x801DBD1Cu;
    ctx->downcount -= 16;
    // 801DBD1C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBD20:
    ctx->pc = 0x801DBD20u;
    // 801DBD20: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBD24:
    ctx->pc = 0x801DBD24u;
    // 801DBD24: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DBD28:
    ctx->pc = 0x801DBD28u;
    // 801DBD28: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DBD2C:
    ctx->pc = 0x801DBD2Cu;
    // 801DBD2C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBD30:
    ctx->pc = 0x801DBD30u;
    ctx->downcount -= 21;
    // 801DBD30: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBD34:
    ctx->pc = 0x801DBD34u;
    // 801DBD34: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBD38:
    ctx->pc = 0x801DBD38u;
    // 801DBD38: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DBD3C:
    ctx->pc = 0x801DBD3Cu;
    // 801DBD3C: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBD40:
    ctx->pc = 0x801DBD40u;
    // 801DBD40: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801DBD44:
    ctx->pc = 0x801DBD44u;
    // 801DBD44: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_801DBD48:
    ctx->pc = 0x801DBD48u;
    // 801DBD48: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801DBD4C:
    ctx->pc = 0x801DBD4Cu;
    // 801DBD4C: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DBD50:
    ctx->pc = 0x801DBD50u;
    // 801DBD50: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801DBD54:
    ctx->pc = 0x801DBD54u;
    // 801DBD54: cmpwi   r30, 0
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

label_801DBD58:
    ctx->pc = 0x801DBD58u;
    // 801DBD58: bc    12, 2, 0x801DBD68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBD68;
        }
    }

label_801DBD5C:
    ctx->pc = 0x801DBD5Cu;
    ctx->downcount -= 3;
    // 801DBD5C: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBD60:
    ctx->pc = 0x801DBD60u;
    // 801DBD60: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBD64:
    ctx->pc = 0x801DBD64u;
    // 801DBD64: b       0x801DBDE8
    {
            goto label_801DBDE8;
    }

label_801DBD68:
    ctx->pc = 0x801DBD68u;
    ctx->downcount -= 7;
    // 801DBD68: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_801DBD6C:
    ctx->pc = 0x801DBD6Cu;
    // 801DBD6C: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_801DBD70:
    ctx->pc = 0x801DBD70u;
    // 801DBD70: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_801DBD74:
    ctx->pc = 0x801DBD74u;
    // 801DBD74: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DBD78:
    ctx->pc = 0x801DBD78u;
    // 801DBD78: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DBD7C:
    ctx->pc = 0x801DBD7Cu;
    // 801DBD7C: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_801DBD80:
    ctx->pc = 0x801DBD80u;
    // 801DBD80: bl      0x80003EE0
    {
            ctx->lr = 0x801DBD84u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_801DBD84:
    ctx->pc = 0x801DBD84u;
    ctx->downcount -= 3;
    // 801DBD84: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBD88:
    ctx->pc = 0x801DBD88u;
    // 801DBD88: cmpwi   r9, 1
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

label_801DBD8C:
    ctx->pc = 0x801DBD8Cu;
    // 801DBD8C: bc    12, 2, 0x801DBDE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBDE4;
        }
    }

label_801DBD90:
    ctx->pc = 0x801DBD90u;
    ctx->downcount -= 9;
    // 801DBD90: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_801DBD94:
    ctx->pc = 0x801DBD94u;
    // 801DBD94: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801DBD98:
    ctx->pc = 0x801DBD98u;
    // 801DBD98: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DBD9C:
    ctx->pc = 0x801DBD9Cu;
    // 801DBD9C: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801DBDA0:
    ctx->pc = 0x801DBDA0u;
    // 801DBDA0: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DBDA4:
    ctx->pc = 0x801DBDA4u;
    // 801DBDA4: cmpwi   r9, 2
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

label_801DBDA8:
    ctx->pc = 0x801DBDA8u;
    // 801DBDA8: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_801DBDAC:
    ctx->pc = 0x801DBDACu;
    // 801DBDAC: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801DBDB0:
    ctx->pc = 0x801DBDB0u;
    // 801DBDB0: bc    4, 2, 0x801DBDBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DBDBC;
        }
    }

label_801DBDB4:
    ctx->pc = 0x801DBDB4u;
    ctx->downcount -= 2;
    // 801DBDB4: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801DBDB8:
    ctx->pc = 0x801DBDB8u;
    // 801DBDB8: b       0x801DBDE4
    {
            goto label_801DBDE4;
    }

label_801DBDBC:
    loop_801DBDBC(ctx);
    if (ctx->pc == 0x801DBDDCu) goto label_801DBDDC;
    return;
label_801DBDC0:
    // 801DBDC0: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_801DBDC4:
    // 801DBDC4: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801DBDC8:
    ctx->pc = 0x801DBDC8u;
    // 801DBDC8: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBDCC:
    // 801DBDCC: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801DBDD0:
    // 801DBDD0: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801DBDD4:
    // 801DBDD4: cmpw    r9, r8
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

label_801DBDD8:
    // 801DBDD8: bc    4, 2, 0x801DBDBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DBDBCu;
                return;
            }
            goto label_801DBDBC;
        }
    }

label_801DBDDC:
    ctx->pc = 0x801DBDDCu;
    ctx->downcount -= 2;
    // 801DBDDC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DBDE0:
    ctx->pc = 0x801DBDE0u;
    // 801DBDE0: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBDE4:
    ctx->pc = 0x801DBDE4u;
    ctx->downcount -= 1;
    // 801DBDE4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DBDE8:
    ctx->pc = 0x801DBDE8u;
    ctx->downcount -= 17;
    // 801DBDE8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DBDEC:
    ctx->pc = 0x801DBDECu;
    // 801DBDEC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBDF0:
    ctx->pc = 0x801DBDF0u;
    // 801DBDF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBDF4:
    ctx->pc = 0x801DBDF4u;
    // 801DBDF4: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DBDF8:
    ctx->pc = 0x801DBDF8u;
    // 801DBDF8: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801DBDFC:
    ctx->pc = 0x801DBDFCu;
    // 801DBDFC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBE00:
    ctx->pc = 0x801DBE00u;
    ctx->downcount -= 3;
    // 801DBE00: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DBE04:
    ctx->pc = 0x801DBE04u;
    // 801DBE04: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBE08:
    ctx->pc = 0x801DBE08u;
    // 801DBE08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBE0C:
    ctx->pc = 0x801DBE0Cu;
    ctx->downcount -= 17;
    // 801DBE0C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBE10:
    ctx->pc = 0x801DBE10u;
    // 801DBE10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBE14:
    ctx->pc = 0x801DBE14u;
    // 801DBE14: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DBE18:
    ctx->pc = 0x801DBE18u;
    // 801DBE18: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBE1C:
    ctx->pc = 0x801DBE1Cu;
    // 801DBE1C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DBE20:
    ctx->pc = 0x801DBE20u;
    // 801DBE20: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DBE24:
    ctx->pc = 0x801DBE24u;
    // 801DBE24: bl      0x802179D4
    {
            ctx->lr = 0x801DBE28u;
            ctx->pc = 0x802179D4u;
            return;
    }

label_801DBE28:
    ctx->pc = 0x801DBE28u;
    ctx->downcount -= 18;
    // 801DBE28: stw     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DBE2C:
    ctx->pc = 0x801DBE2Cu;
    // 801DBE2C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DBE30:
    ctx->pc = 0x801DBE30u;
    // 801DBE30: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBE34:
    ctx->pc = 0x801DBE34u;
    // 801DBE34: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBE38:
    ctx->pc = 0x801DBE38u;
    // 801DBE38: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DBE3C:
    ctx->pc = 0x801DBE3Cu;
    // 801DBE3C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DBE40:
    ctx->pc = 0x801DBE40u;
    // 801DBE40: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBE44:
    ctx->pc = 0x801DBE44u;
    ctx->downcount -= 9;
    // 801DBE44: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBE48:
    ctx->pc = 0x801DBE48u;
    // 801DBE48: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBE4C:
    ctx->pc = 0x801DBE4Cu;
    // 801DBE4C: stfd     f31, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DBE4Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_801DBE50:
    ctx->pc = 0x801DBE50u;
    // 801DBE50: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DBE54:
    ctx->pc = 0x801DBE54u;
    // 801DBE54: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBE58:
    ctx->pc = 0x801DBE58u;
    // 801DBE58: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DBE5C:
    ctx->pc = 0x801DBE5Cu;
    // 801DBE5C: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x801DBE5Cu)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_801DBE60:
    ctx->pc = 0x801DBE60u;
    // 801DBE60: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DBE64:
    ctx->pc = 0x801DBE64u;
    // 801DBE64: bl      0x802179D4
    {
            ctx->lr = 0x801DBE68u;
            ctx->pc = 0x802179D4u;
            return;
    }

label_801DBE68:
    ctx->pc = 0x801DBE68u;
    ctx->downcount -= 6;
    // 801DBE68: stw     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DBE6C:
    ctx->pc = 0x801DBE6Cu;
    // 801DBE6C: stfs     f31, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x801DBE6Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801DBE70:
    ctx->pc = 0x801DBE70u;
    // 801DBE70: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBE74:
    ctx->pc = 0x801DBE74u;
    // 801DBE74: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBE78:
    ctx->pc = 0x801DBE78u;
    // 801DBE78: cmpw    r0, r9
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DBE7C:
    ctx->pc = 0x801DBE7Cu;
    // 801DBE7C: bc    12, 2, 0x801DBE84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBE84;
        }
    }

label_801DBE80:
    ctx->pc = 0x801DBE80u;
    ctx->downcount -= 1;
    // 801DBE80: bl      0x802178A4
    {
            ctx->lr = 0x801DBE84u;
            ctx->pc = 0x802178A4u;
            return;
    }

label_801DBE84:
    ctx->pc = 0x801DBE84u;
    ctx->downcount -= 8;
    // 801DBE84: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DBE88:
    ctx->pc = 0x801DBE88u;
    // 801DBE88: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBE8C:
    ctx->pc = 0x801DBE8Cu;
    // 801DBE8C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBE90:
    ctx->pc = 0x801DBE90u;
    // 801DBE90: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DBE94:
    ctx->pc = 0x801DBE94u;
    // 801DBE94: lfd     f31, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DBE94u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801DBE98:
    ctx->pc = 0x801DBE98u;
    // 801DBE98: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801DBE9C:
    ctx->pc = 0x801DBE9Cu;
    // 801DBE9C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBEA0:
    ctx->pc = 0x801DBEA0u;
    ctx->downcount -= 11;
    // 801DBEA0: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBEA4:
    ctx->pc = 0x801DBEA4u;
    // 801DBEA4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBEA8:
    ctx->pc = 0x801DBEA8u;
    // 801DBEA8: stfd     f31, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DBEA8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_801DBEAC:
    ctx->pc = 0x801DBEACu;
    // 801DBEAC: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DBEB0:
    ctx->pc = 0x801DBEB0u;
    // 801DBEB0: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBEB4:
    ctx->pc = 0x801DBEB4u;
    // 801DBEB4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DBEB8:
    ctx->pc = 0x801DBEB8u;
    // 801DBEB8: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x801DBEB8u)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_801DBEBC:
    ctx->pc = 0x801DBEBCu;
    // 801DBEBC: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBEC0:
    ctx->pc = 0x801DBEC0u;
    // 801DBEC0: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DBEC4:
    ctx->pc = 0x801DBEC4u;
    // 801DBEC4: cmpwi   r0, 0
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

label_801DBEC8:
    ctx->pc = 0x801DBEC8u;
    // 801DBEC8: bc    4, 2, 0x801DBEEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DBEEC;
        }
    }

label_801DBECC:
    ctx->pc = 0x801DBECCu;
    ctx->downcount -= 1;
    // 801DBECC: bl      0x802179D4
    {
            ctx->lr = 0x801DBED0u;
            ctx->pc = 0x802179D4u;
            return;
    }

label_801DBED0:
    ctx->pc = 0x801DBED0u;
    ctx->downcount -= 6;
    // 801DBED0: stw     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DBED4:
    ctx->pc = 0x801DBED4u;
    // 801DBED4: stfs     f31, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x801DBED4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801DBED8:
    ctx->pc = 0x801DBED8u;
    // 801DBED8: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBEDC:
    ctx->pc = 0x801DBEDCu;
    // 801DBEDC: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBEE0:
    ctx->pc = 0x801DBEE0u;
    // 801DBEE0: cmpw    r0, r9
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DBEE4:
    ctx->pc = 0x801DBEE4u;
    // 801DBEE4: bc    12, 2, 0x801DBEEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBEEC;
        }
    }

label_801DBEE8:
    ctx->pc = 0x801DBEE8u;
    ctx->downcount -= 1;
    // 801DBEE8: bl      0x802178A4
    {
            ctx->lr = 0x801DBEECu;
            ctx->pc = 0x802178A4u;
            return;
    }

label_801DBEEC:
    ctx->pc = 0x801DBEECu;
    ctx->downcount -= 7;
    // 801DBEEC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBEF0:
    ctx->pc = 0x801DBEF0u;
    // 801DBEF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBEF4:
    ctx->pc = 0x801DBEF4u;
    // 801DBEF4: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DBEF8:
    ctx->pc = 0x801DBEF8u;
    // 801DBEF8: lfd     f31, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DBEF8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801DBEFC:
    ctx->pc = 0x801DBEFCu;
    // 801DBEFC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801DBF00:
    ctx->pc = 0x801DBF00u;
    // 801DBF00: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBF04:
    ctx->pc = 0x801DBF04u;
    ctx->downcount -= 6;
    // 801DBF04: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBF08:
    ctx->pc = 0x801DBF08u;
    // 801DBF08: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBF0C:
    ctx->pc = 0x801DBF0Cu;
    // 801DBF0C: stfd     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DBF0Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_801DBF10:
    ctx->pc = 0x801DBF10u;
    // 801DBF10: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBF14:
    ctx->pc = 0x801DBF14u;
    // 801DBF14: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x801DBF14u)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_801DBF18:
    ctx->pc = 0x801DBF18u;
    // 801DBF18: bl      0x802179D4
    {
            ctx->lr = 0x801DBF1Cu;
            ctx->pc = 0x802179D4u;
            return;
    }

label_801DBF1C:
    ctx->pc = 0x801DBF1Cu;
    ctx->downcount -= 5;
    // 801DBF1C: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBF20:
    ctx->pc = 0x801DBF20u;
    // 801DBF20: stfs     f31, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x801DBF20u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801DBF24:
    ctx->pc = 0x801DBF24u;
    // 801DBF24: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBF28:
    ctx->pc = 0x801DBF28u;
    // 801DBF28: cmpw    r0, r9
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DBF2C:
    ctx->pc = 0x801DBF2Cu;
    // 801DBF2C: bc    12, 2, 0x801DBF34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBF34;
        }
    }

label_801DBF30:
    ctx->pc = 0x801DBF30u;
    ctx->downcount -= 1;
    // 801DBF30: bl      0x802178A4
    {
            ctx->lr = 0x801DBF34u;
            ctx->pc = 0x802178A4u;
            return;
    }

label_801DBF34:
    ctx->pc = 0x801DBF34u;
    ctx->downcount -= 6;
    // 801DBF34: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBF38:
    ctx->pc = 0x801DBF38u;
    // 801DBF38: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBF3C:
    ctx->pc = 0x801DBF3Cu;
    // 801DBF3C: lfd     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DBF3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801DBF40:
    ctx->pc = 0x801DBF40u;
    // 801DBF40: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DBF44:
    ctx->pc = 0x801DBF44u;
    // 801DBF44: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBF48:
    ctx->pc = 0x801DBF48u;
    ctx->downcount -= 3;
    // 801DBF48: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DBF4C:
    ctx->pc = 0x801DBF4Cu;
    // 801DBF4C: cmpwi   r3, 0
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

label_801DBF50:
    ctx->pc = 0x801DBF50u;
    // 801DBF50: bc    4, 2, 0x801DBF60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DBF60;
        }
    }

label_801DBF54:
    ctx->pc = 0x801DBF54u;
    ctx->downcount -= 3;
    // 801DBF54: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DBF58:
    ctx->pc = 0x801DBF58u;
    // 801DBF58: lfs     f1, 4668(r9)
    if (!ppc_fp_available_inline(ctx, 0x801DBF58u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4668);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801DBF5C:
    ctx->pc = 0x801DBF5Cu;
    // 801DBF5C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBF60:
    ctx->pc = 0x801DBF60u;
    ctx->downcount -= 2;
    // 801DBF60: lfs     f1, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x801DBF60u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801DBF64:
    ctx->pc = 0x801DBF64u;
    // 801DBF64: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBF68:
    ctx->pc = 0x801DBF68u;
    ctx->downcount -= 8;
    // 801DBF68: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBF6C:
    ctx->pc = 0x801DBF6Cu;
    // 801DBF6C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBF70:
    ctx->pc = 0x801DBF70u;
    // 801DBF70: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DBF74:
    ctx->pc = 0x801DBF74u;
    // 801DBF74: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBF78:
    ctx->pc = 0x801DBF78u;
    // 801DBF78: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DBF7C:
    ctx->pc = 0x801DBF7Cu;
    // 801DBF7C: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DBF80:
    ctx->pc = 0x801DBF80u;
    // 801DBF80: cmpwi   r3, 0
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

label_801DBF84:
    ctx->pc = 0x801DBF84u;
    // 801DBF84: bc    12, 2, 0x801DBFA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBFA0;
        }
    }

label_801DBF88:
    ctx->pc = 0x801DBF88u;
    ctx->downcount -= 5;
    // 801DBF88: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DBF8C:
    ctx->pc = 0x801DBF8Cu;
    // 801DBF8C: stfs     f1, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x801DBF8Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801DBF90:
    ctx->pc = 0x801DBF90u;
    // 801DBF90: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBF94:
    ctx->pc = 0x801DBF94u;
    // 801DBF94: cmpw    r0, r9
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DBF98:
    ctx->pc = 0x801DBF98u;
    // 801DBF98: bc    12, 2, 0x801DBFA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DBFA0;
        }
    }

label_801DBF9C:
    ctx->pc = 0x801DBF9Cu;
    ctx->downcount -= 1;
    // 801DBF9C: bl      0x802178A4
    {
            ctx->lr = 0x801DBFA0u;
            ctx->pc = 0x802178A4u;
            return;
    }

label_801DBFA0:
    ctx->pc = 0x801DBFA0u;
    ctx->downcount -= 7;
    // 801DBFA0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DBFA4:
    ctx->pc = 0x801DBFA4u;
    // 801DBFA4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBFA8:
    ctx->pc = 0x801DBFA8u;
    // 801DBFA8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBFAC:
    ctx->pc = 0x801DBFACu;
    // 801DBFAC: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DBFB0:
    ctx->pc = 0x801DBFB0u;
    // 801DBFB0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DBFB4:
    ctx->pc = 0x801DBFB4u;
    // 801DBFB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBFB8:
    ctx->pc = 0x801DBFB8u;
    ctx->downcount -= 4;
    // 801DBFB8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBFBC:
    ctx->pc = 0x801DBFBCu;
    // 801DBFBC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBFC0:
    ctx->pc = 0x801DBFC0u;
    // 801DBFC0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBFC4:
    ctx->pc = 0x801DBFC4u;
    // 801DBFC4: bl      0x801D3B90
    {
            ctx->lr = 0x801DBFC8u;
            ctx->pc = 0x801D3B90u;
            return;
    }

label_801DBFC8:
    ctx->pc = 0x801DBFC8u;
    ctx->downcount -= 1;
    // 801DBFC8: bl      0x801C78E4
    {
            ctx->lr = 0x801DBFCCu;
            ctx->pc = 0x801C78E4u;
            return;
    }

label_801DBFCC:
    ctx->pc = 0x801DBFCCu;
    ctx->downcount -= 5;
    // 801DBFCC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DBFD0:
    ctx->pc = 0x801DBFD0u;
    // 801DBFD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DBFD4:
    ctx->pc = 0x801DBFD4u;
    // 801DBFD4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DBFD8:
    ctx->pc = 0x801DBFD8u;
    // 801DBFD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DBFDC:
    ctx->pc = 0x801DBFDCu;
    ctx->downcount -= 8;
    // 801DBFDC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DBFE0:
    ctx->pc = 0x801DBFE0u;
    // 801DBFE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DBFE4:
    ctx->pc = 0x801DBFE4u;
    // 801DBFE4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DBFE8:
    ctx->pc = 0x801DBFE8u;
    // 801DBFE8: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DBFEC:
    ctx->pc = 0x801DBFECu;
    // 801DBFEC: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DBFF0:
    ctx->pc = 0x801DBFF0u;
    // 801DBFF0: addi    r3, r3, 4708
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4708);

label_801DBFF4:
    ctx->pc = 0x801DBFF4u;
    // 801DBFF4: addi    r4, r4, -14648
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14648);

label_801DBFF8:
    ctx->pc = 0x801DBFF8u;
    // 801DBFF8: bl      0x801E530C
    {
            ctx->lr = 0x801DBFFCu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DBFFC:
    ctx->pc = 0x801DBFFCu;
    ctx->downcount -= 5;
    // 801DBFFC: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC000:
    ctx->pc = 0x801DC000u;
    // 801DC000: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC004:
    ctx->pc = 0x801DC004u;
    // 801DC004: addi    r3, r3, 4716
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4716);

label_801DC008:
    ctx->pc = 0x801DC008u;
    // 801DC008: addi    r4, r4, -14612
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14612);

label_801DC00C:
    ctx->pc = 0x801DC00Cu;
    // 801DC00C: bl      0x801E530C
    {
            ctx->lr = 0x801DC010u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC010:
    ctx->pc = 0x801DC010u;
    ctx->downcount -= 5;
    // 801DC010: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC014:
    ctx->pc = 0x801DC014u;
    // 801DC014: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC018:
    ctx->pc = 0x801DC018u;
    // 801DC018: addi    r3, r3, 4732
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4732);

label_801DC01C:
    ctx->pc = 0x801DC01Cu;
    // 801DC01C: addi    r4, r4, -14576
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14576);

label_801DC020:
    ctx->pc = 0x801DC020u;
    // 801DC020: bl      0x801E530C
    {
            ctx->lr = 0x801DC024u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC024:
    ctx->pc = 0x801DC024u;
    ctx->downcount -= 5;
    // 801DC024: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC028:
    ctx->pc = 0x801DC028u;
    // 801DC028: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC02C:
    ctx->pc = 0x801DC02Cu;
    // 801DC02C: addi    r3, r3, 4740
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4740);

label_801DC030:
    ctx->pc = 0x801DC030u;
    // 801DC030: addi    r4, r4, -14540
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14540);

label_801DC034:
    ctx->pc = 0x801DC034u;
    // 801DC034: bl      0x801E530C
    {
            ctx->lr = 0x801DC038u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC038:
    ctx->pc = 0x801DC038u;
    ctx->downcount -= 5;
    // 801DC038: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC03C:
    ctx->pc = 0x801DC03Cu;
    // 801DC03C: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC040:
    ctx->pc = 0x801DC040u;
    // 801DC040: addi    r3, r3, 4752
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4752);

label_801DC044:
    ctx->pc = 0x801DC044u;
    // 801DC044: addi    r4, r4, -14504
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14504);

label_801DC048:
    ctx->pc = 0x801DC048u;
    // 801DC048: bl      0x801E530C
    {
            ctx->lr = 0x801DC04Cu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC04C:
    ctx->pc = 0x801DC04Cu;
    ctx->downcount -= 5;
    // 801DC04C: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC050:
    ctx->pc = 0x801DC050u;
    // 801DC050: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC054:
    ctx->pc = 0x801DC054u;
    // 801DC054: addi    r3, r3, 4760
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4760);

label_801DC058:
    ctx->pc = 0x801DC058u;
    // 801DC058: addi    r4, r4, -14468
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14468);

label_801DC05C:
    ctx->pc = 0x801DC05Cu;
    // 801DC05C: bl      0x801E530C
    {
            ctx->lr = 0x801DC060u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC060:
    ctx->pc = 0x801DC060u;
    ctx->downcount -= 5;
    // 801DC060: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC064:
    ctx->pc = 0x801DC064u;
    // 801DC064: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC068:
    ctx->pc = 0x801DC068u;
    // 801DC068: addi    r3, r3, 4776
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4776);

label_801DC06C:
    ctx->pc = 0x801DC06Cu;
    // 801DC06C: addi    r4, r4, -14432
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14432);

label_801DC070:
    ctx->pc = 0x801DC070u;
    // 801DC070: bl      0x801E530C
    {
            ctx->lr = 0x801DC074u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC074:
    ctx->pc = 0x801DC074u;
    ctx->downcount -= 5;
    // 801DC074: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC078:
    ctx->pc = 0x801DC078u;
    // 801DC078: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC07C:
    ctx->pc = 0x801DC07Cu;
    // 801DC07C: addi    r3, r3, 4784
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4784);

label_801DC080:
    ctx->pc = 0x801DC080u;
    // 801DC080: addi    r4, r4, -14396
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14396);

label_801DC084:
    ctx->pc = 0x801DC084u;
    // 801DC084: bl      0x801E530C
    {
            ctx->lr = 0x801DC088u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC088:
    ctx->pc = 0x801DC088u;
    ctx->downcount -= 5;
    // 801DC088: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC08C:
    ctx->pc = 0x801DC08Cu;
    // 801DC08C: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC090:
    ctx->pc = 0x801DC090u;
    // 801DC090: addi    r3, r3, 4796
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4796);

label_801DC094:
    ctx->pc = 0x801DC094u;
    // 801DC094: addi    r4, r4, -14360
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14360);

label_801DC098:
    ctx->pc = 0x801DC098u;
    // 801DC098: bl      0x801E530C
    {
            ctx->lr = 0x801DC09Cu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC09C:
    ctx->pc = 0x801DC09Cu;
    ctx->downcount -= 5;
    // 801DC09C: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC0A0:
    ctx->pc = 0x801DC0A0u;
    // 801DC0A0: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC0A4:
    ctx->pc = 0x801DC0A4u;
    // 801DC0A4: addi    r3, r3, 4812
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4812);

label_801DC0A8:
    ctx->pc = 0x801DC0A8u;
    // 801DC0A8: addi    r4, r4, -14324
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14324);

label_801DC0AC:
    ctx->pc = 0x801DC0ACu;
    // 801DC0AC: bl      0x801E530C
    {
            ctx->lr = 0x801DC0B0u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC0B0:
    ctx->pc = 0x801DC0B0u;
    ctx->downcount -= 5;
    // 801DC0B0: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC0B4:
    ctx->pc = 0x801DC0B4u;
    // 801DC0B4: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC0B8:
    ctx->pc = 0x801DC0B8u;
    // 801DC0B8: addi    r3, r3, 4824
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4824);

label_801DC0BC:
    ctx->pc = 0x801DC0BCu;
    // 801DC0BC: addi    r4, r4, -14288
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14288);

label_801DC0C0:
    ctx->pc = 0x801DC0C0u;
    // 801DC0C0: bl      0x801E530C
    {
            ctx->lr = 0x801DC0C4u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC0C4:
    ctx->pc = 0x801DC0C4u;
    ctx->downcount -= 5;
    // 801DC0C4: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC0C8:
    ctx->pc = 0x801DC0C8u;
    // 801DC0C8: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC0CC:
    ctx->pc = 0x801DC0CCu;
    // 801DC0CC: addi    r3, r3, 4836
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4836);

label_801DC0D0:
    ctx->pc = 0x801DC0D0u;
    // 801DC0D0: addi    r4, r4, -14252
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14252);

label_801DC0D4:
    ctx->pc = 0x801DC0D4u;
    // 801DC0D4: bl      0x801E530C
    {
            ctx->lr = 0x801DC0D8u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC0D8:
    ctx->pc = 0x801DC0D8u;
    ctx->downcount -= 5;
    // 801DC0D8: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC0DC:
    ctx->pc = 0x801DC0DCu;
    // 801DC0DC: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC0E0:
    ctx->pc = 0x801DC0E0u;
    // 801DC0E0: addi    r3, r3, 4844
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4844);

label_801DC0E4:
    ctx->pc = 0x801DC0E4u;
    // 801DC0E4: addi    r4, r4, -14216
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14216);

label_801DC0E8:
    ctx->pc = 0x801DC0E8u;
    // 801DC0E8: bl      0x801E530C
    {
            ctx->lr = 0x801DC0ECu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC0EC:
    ctx->pc = 0x801DC0ECu;
    ctx->downcount -= 5;
    // 801DC0EC: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC0F0:
    ctx->pc = 0x801DC0F0u;
    // 801DC0F0: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC0F4:
    ctx->pc = 0x801DC0F4u;
    // 801DC0F4: addi    r3, r3, 4848
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4848);

label_801DC0F8:
    ctx->pc = 0x801DC0F8u;
    // 801DC0F8: addi    r4, r4, -14180
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14180);

label_801DC0FC:
    ctx->pc = 0x801DC0FCu;
    // 801DC0FC: bl      0x801E530C
    {
            ctx->lr = 0x801DC100u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC100:
    ctx->pc = 0x801DC100u;
    ctx->downcount -= 5;
    // 801DC100: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC104:
    ctx->pc = 0x801DC104u;
    // 801DC104: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC108:
    ctx->pc = 0x801DC108u;
    // 801DC108: addi    r3, r3, 4856
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4856);

label_801DC10C:
    ctx->pc = 0x801DC10Cu;
    // 801DC10C: addi    r4, r4, -14144
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14144);

label_801DC110:
    ctx->pc = 0x801DC110u;
    // 801DC110: bl      0x801E530C
    {
            ctx->lr = 0x801DC114u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC114:
    ctx->pc = 0x801DC114u;
    ctx->downcount -= 5;
    // 801DC114: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC118:
    ctx->pc = 0x801DC118u;
    // 801DC118: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC11C:
    ctx->pc = 0x801DC11Cu;
    // 801DC11C: addi    r3, r3, 4868
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4868);

label_801DC120:
    ctx->pc = 0x801DC120u;
    // 801DC120: addi    r4, r4, -14108
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14108);

label_801DC124:
    ctx->pc = 0x801DC124u;
    // 801DC124: bl      0x801E530C
    {
            ctx->lr = 0x801DC128u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC128:
    ctx->pc = 0x801DC128u;
    ctx->downcount -= 5;
    // 801DC128: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC12C:
    ctx->pc = 0x801DC12Cu;
    // 801DC12C: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC130:
    ctx->pc = 0x801DC130u;
    // 801DC130: addi    r3, r3, 4876
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4876);

label_801DC134:
    ctx->pc = 0x801DC134u;
    // 801DC134: addi    r4, r4, -14072
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14072);

label_801DC138:
    ctx->pc = 0x801DC138u;
    // 801DC138: bl      0x801E530C
    {
            ctx->lr = 0x801DC13Cu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC13C:
    ctx->pc = 0x801DC13Cu;
    ctx->downcount -= 5;
    // 801DC13C: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC140:
    ctx->pc = 0x801DC140u;
    // 801DC140: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC144:
    ctx->pc = 0x801DC144u;
    // 801DC144: addi    r3, r3, 4884
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4884);

label_801DC148:
    ctx->pc = 0x801DC148u;
    // 801DC148: addi    r4, r4, -14036
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14036);

label_801DC14C:
    ctx->pc = 0x801DC14Cu;
    // 801DC14C: bl      0x801E530C
    {
            ctx->lr = 0x801DC150u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC150:
    ctx->pc = 0x801DC150u;
    ctx->downcount -= 5;
    // 801DC150: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC154:
    ctx->pc = 0x801DC154u;
    // 801DC154: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC158:
    ctx->pc = 0x801DC158u;
    // 801DC158: addi    r3, r3, 4896
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4896);

label_801DC15C:
    ctx->pc = 0x801DC15Cu;
    // 801DC15C: addi    r4, r4, -14000
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14000);

label_801DC160:
    ctx->pc = 0x801DC160u;
    // 801DC160: bl      0x801E530C
    {
            ctx->lr = 0x801DC164u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC164:
    ctx->pc = 0x801DC164u;
    ctx->downcount -= 5;
    // 801DC164: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC168:
    ctx->pc = 0x801DC168u;
    // 801DC168: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC16C:
    ctx->pc = 0x801DC16Cu;
    // 801DC16C: addi    r3, r3, 4908
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4908);

label_801DC170:
    ctx->pc = 0x801DC170u;
    // 801DC170: addi    r4, r4, -13964
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13964);

label_801DC174:
    ctx->pc = 0x801DC174u;
    // 801DC174: bl      0x801E530C
    {
            ctx->lr = 0x801DC178u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC178:
    ctx->pc = 0x801DC178u;
    ctx->downcount -= 5;
    // 801DC178: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC17C:
    ctx->pc = 0x801DC17Cu;
    // 801DC17C: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC180:
    ctx->pc = 0x801DC180u;
    // 801DC180: addi    r3, r3, 4924
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4924);

label_801DC184:
    ctx->pc = 0x801DC184u;
    // 801DC184: addi    r4, r4, -13928
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13928);

label_801DC188:
    ctx->pc = 0x801DC188u;
    // 801DC188: bl      0x801E530C
    {
            ctx->lr = 0x801DC18Cu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC18C:
    ctx->pc = 0x801DC18Cu;
    ctx->downcount -= 5;
    // 801DC18C: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC190:
    ctx->pc = 0x801DC190u;
    // 801DC190: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC194:
    ctx->pc = 0x801DC194u;
    // 801DC194: addi    r3, r3, 4940
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4940);

label_801DC198:
    ctx->pc = 0x801DC198u;
    // 801DC198: addi    r4, r4, -13892
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13892);

label_801DC19C:
    ctx->pc = 0x801DC19Cu;
    // 801DC19C: bl      0x801E530C
    {
            ctx->lr = 0x801DC1A0u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC1A0:
    ctx->pc = 0x801DC1A0u;
    ctx->downcount -= 5;
    // 801DC1A0: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC1A4:
    ctx->pc = 0x801DC1A4u;
    // 801DC1A4: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC1A8:
    ctx->pc = 0x801DC1A8u;
    // 801DC1A8: addi    r3, r3, 4952
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4952);

label_801DC1AC:
    ctx->pc = 0x801DC1ACu;
    // 801DC1AC: addi    r4, r4, -13856
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13856);

label_801DC1B0:
    ctx->pc = 0x801DC1B0u;
    // 801DC1B0: bl      0x801E530C
    {
            ctx->lr = 0x801DC1B4u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC1B4:
    ctx->pc = 0x801DC1B4u;
    ctx->downcount -= 5;
    // 801DC1B4: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC1B8:
    ctx->pc = 0x801DC1B8u;
    // 801DC1B8: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC1BC:
    ctx->pc = 0x801DC1BCu;
    // 801DC1BC: addi    r3, r3, 4968
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4968);

label_801DC1C0:
    ctx->pc = 0x801DC1C0u;
    // 801DC1C0: addi    r4, r4, -13820
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13820);

label_801DC1C4:
    ctx->pc = 0x801DC1C4u;
    // 801DC1C4: bl      0x801E530C
    {
            ctx->lr = 0x801DC1C8u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC1C8:
    ctx->pc = 0x801DC1C8u;
    ctx->downcount -= 5;
    // 801DC1C8: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC1CC:
    ctx->pc = 0x801DC1CCu;
    // 801DC1CC: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC1D0:
    ctx->pc = 0x801DC1D0u;
    // 801DC1D0: addi    r3, r3, 4980
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4980);

label_801DC1D4:
    ctx->pc = 0x801DC1D4u;
    // 801DC1D4: addi    r4, r4, -13784
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13784);

label_801DC1D8:
    ctx->pc = 0x801DC1D8u;
    // 801DC1D8: bl      0x801E530C
    {
            ctx->lr = 0x801DC1DCu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC1DC:
    ctx->pc = 0x801DC1DCu;
    ctx->downcount -= 5;
    // 801DC1DC: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC1E0:
    ctx->pc = 0x801DC1E0u;
    // 801DC1E0: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC1E4:
    ctx->pc = 0x801DC1E4u;
    // 801DC1E4: addi    r3, r3, 4992
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4992);

label_801DC1E8:
    ctx->pc = 0x801DC1E8u;
    // 801DC1E8: addi    r4, r4, -13748
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13748);

label_801DC1EC:
    ctx->pc = 0x801DC1ECu;
    // 801DC1EC: bl      0x801E530C
    {
            ctx->lr = 0x801DC1F0u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC1F0:
    ctx->pc = 0x801DC1F0u;
    ctx->downcount -= 5;
    // 801DC1F0: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC1F4:
    ctx->pc = 0x801DC1F4u;
    // 801DC1F4: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC1F8:
    ctx->pc = 0x801DC1F8u;
    // 801DC1F8: addi    r3, r3, 5000
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5000);

label_801DC1FC:
    ctx->pc = 0x801DC1FCu;
    // 801DC1FC: addi    r4, r4, -13712
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13712);

label_801DC200:
    ctx->pc = 0x801DC200u;
    // 801DC200: bl      0x801E530C
    {
            ctx->lr = 0x801DC204u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC204:
    ctx->pc = 0x801DC204u;
    ctx->downcount -= 5;
    // 801DC204: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC208:
    ctx->pc = 0x801DC208u;
    // 801DC208: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC20C:
    ctx->pc = 0x801DC20Cu;
    // 801DC20C: addi    r3, r3, 5016
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5016);

label_801DC210:
    ctx->pc = 0x801DC210u;
    // 801DC210: addi    r4, r4, -13676
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13676);

label_801DC214:
    ctx->pc = 0x801DC214u;
    // 801DC214: bl      0x801E530C
    {
            ctx->lr = 0x801DC218u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC218:
    ctx->pc = 0x801DC218u;
    ctx->downcount -= 5;
    // 801DC218: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC21C:
    ctx->pc = 0x801DC21Cu;
    // 801DC21C: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC220:
    ctx->pc = 0x801DC220u;
    // 801DC220: addi    r3, r3, 5028
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5028);

label_801DC224:
    ctx->pc = 0x801DC224u;
    // 801DC224: addi    r4, r4, -13640
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13640);

label_801DC228:
    ctx->pc = 0x801DC228u;
    // 801DC228: bl      0x801E530C
    {
            ctx->lr = 0x801DC22Cu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC22C:
    ctx->pc = 0x801DC22Cu;
    ctx->downcount -= 5;
    // 801DC22C: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC230:
    ctx->pc = 0x801DC230u;
    // 801DC230: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC234:
    ctx->pc = 0x801DC234u;
    // 801DC234: addi    r3, r3, 5040
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5040);

label_801DC238:
    ctx->pc = 0x801DC238u;
    // 801DC238: addi    r4, r4, -13604
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13604);

label_801DC23C:
    ctx->pc = 0x801DC23Cu;
    // 801DC23C: bl      0x801E530C
    {
            ctx->lr = 0x801DC240u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC240:
    ctx->pc = 0x801DC240u;
    ctx->downcount -= 5;
    // 801DC240: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC244:
    ctx->pc = 0x801DC244u;
    // 801DC244: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC248:
    ctx->pc = 0x801DC248u;
    // 801DC248: addi    r3, r3, 5048
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5048);

label_801DC24C:
    ctx->pc = 0x801DC24Cu;
    // 801DC24C: addi    r4, r4, -13568
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13568);

label_801DC250:
    ctx->pc = 0x801DC250u;
    // 801DC250: bl      0x801E530C
    {
            ctx->lr = 0x801DC254u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC254:
    ctx->pc = 0x801DC254u;
    ctx->downcount -= 5;
    // 801DC254: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC258:
    ctx->pc = 0x801DC258u;
    // 801DC258: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC25C:
    ctx->pc = 0x801DC25Cu;
    // 801DC25C: addi    r3, r3, 5068
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5068);

label_801DC260:
    ctx->pc = 0x801DC260u;
    // 801DC260: addi    r4, r4, -13532
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13532);

label_801DC264:
    ctx->pc = 0x801DC264u;
    // 801DC264: bl      0x801E530C
    {
            ctx->lr = 0x801DC268u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC268:
    ctx->pc = 0x801DC268u;
    ctx->downcount -= 5;
    // 801DC268: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC26C:
    ctx->pc = 0x801DC26Cu;
    // 801DC26C: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC270:
    ctx->pc = 0x801DC270u;
    // 801DC270: addi    r3, r3, 5076
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5076);

label_801DC274:
    ctx->pc = 0x801DC274u;
    // 801DC274: addi    r4, r4, -13496
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13496);

label_801DC278:
    ctx->pc = 0x801DC278u;
    // 801DC278: bl      0x801E530C
    {
            ctx->lr = 0x801DC27Cu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC27C:
    ctx->pc = 0x801DC27Cu;
    ctx->downcount -= 5;
    // 801DC27C: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC280:
    ctx->pc = 0x801DC280u;
    // 801DC280: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC284:
    ctx->pc = 0x801DC284u;
    // 801DC284: addi    r3, r3, 5084
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5084);

label_801DC288:
    ctx->pc = 0x801DC288u;
    // 801DC288: addi    r4, r4, -13460
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13460);

label_801DC28C:
    ctx->pc = 0x801DC28Cu;
    // 801DC28C: bl      0x801E530C
    {
            ctx->lr = 0x801DC290u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC290:
    ctx->pc = 0x801DC290u;
    ctx->downcount -= 5;
    // 801DC290: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC294:
    ctx->pc = 0x801DC294u;
    // 801DC294: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC298:
    ctx->pc = 0x801DC298u;
    // 801DC298: addi    r3, r3, 5096
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5096);

label_801DC29C:
    ctx->pc = 0x801DC29Cu;
    // 801DC29C: addi    r4, r4, -13424
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13424);

label_801DC2A0:
    ctx->pc = 0x801DC2A0u;
    // 801DC2A0: bl      0x801E530C
    {
            ctx->lr = 0x801DC2A4u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC2A4:
    ctx->pc = 0x801DC2A4u;
    ctx->downcount -= 5;
    // 801DC2A4: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC2A8:
    ctx->pc = 0x801DC2A8u;
    // 801DC2A8: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC2AC:
    ctx->pc = 0x801DC2ACu;
    // 801DC2AC: addi    r3, r3, 5112
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5112);

label_801DC2B0:
    ctx->pc = 0x801DC2B0u;
    // 801DC2B0: addi    r4, r4, -13388
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13388);

label_801DC2B4:
    ctx->pc = 0x801DC2B4u;
    // 801DC2B4: bl      0x801E530C
    {
            ctx->lr = 0x801DC2B8u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC2B8:
    ctx->pc = 0x801DC2B8u;
    ctx->downcount -= 5;
    // 801DC2B8: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC2BC:
    ctx->pc = 0x801DC2BCu;
    // 801DC2BC: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC2C0:
    ctx->pc = 0x801DC2C0u;
    // 801DC2C0: addi    r3, r3, 5124
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5124);

label_801DC2C4:
    ctx->pc = 0x801DC2C4u;
    // 801DC2C4: addi    r4, r4, -13352
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13352);

label_801DC2C8:
    ctx->pc = 0x801DC2C8u;
    // 801DC2C8: bl      0x801E530C
    {
            ctx->lr = 0x801DC2CCu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC2CC:
    ctx->pc = 0x801DC2CCu;
    ctx->downcount -= 5;
    // 801DC2CC: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC2D0:
    ctx->pc = 0x801DC2D0u;
    // 801DC2D0: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC2D4:
    ctx->pc = 0x801DC2D4u;
    // 801DC2D4: addi    r3, r3, 5136
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5136);

label_801DC2D8:
    ctx->pc = 0x801DC2D8u;
    // 801DC2D8: addi    r4, r4, -13316
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13316);

label_801DC2DC:
    ctx->pc = 0x801DC2DCu;
    // 801DC2DC: bl      0x801E530C
    {
            ctx->lr = 0x801DC2E0u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC2E0:
    ctx->pc = 0x801DC2E0u;
    ctx->downcount -= 5;
    // 801DC2E0: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC2E4:
    ctx->pc = 0x801DC2E4u;
    // 801DC2E4: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC2E8:
    ctx->pc = 0x801DC2E8u;
    // 801DC2E8: addi    r3, r3, 5152
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5152);

label_801DC2EC:
    ctx->pc = 0x801DC2ECu;
    // 801DC2EC: addi    r4, r4, -13280
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13280);

label_801DC2F0:
    ctx->pc = 0x801DC2F0u;
    // 801DC2F0: bl      0x801E530C
    {
            ctx->lr = 0x801DC2F4u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC2F4:
    ctx->pc = 0x801DC2F4u;
    ctx->downcount -= 5;
    // 801DC2F4: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC2F8:
    ctx->pc = 0x801DC2F8u;
    // 801DC2F8: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC2FC:
    ctx->pc = 0x801DC2FCu;
    // 801DC2FC: addi    r3, r3, 5168
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5168);

label_801DC300:
    ctx->pc = 0x801DC300u;
    // 801DC300: addi    r4, r4, -13244
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13244);

label_801DC304:
    ctx->pc = 0x801DC304u;
    // 801DC304: bl      0x801E530C
    {
            ctx->lr = 0x801DC308u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC308:
    ctx->pc = 0x801DC308u;
    ctx->downcount -= 5;
    // 801DC308: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC30C:
    ctx->pc = 0x801DC30Cu;
    // 801DC30C: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC310:
    ctx->pc = 0x801DC310u;
    // 801DC310: addi    r3, r3, 5176
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5176);

label_801DC314:
    ctx->pc = 0x801DC314u;
    // 801DC314: addi    r4, r4, -13208
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13208);

label_801DC318:
    ctx->pc = 0x801DC318u;
    // 801DC318: bl      0x801E530C
    {
            ctx->lr = 0x801DC31Cu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC31C:
    ctx->pc = 0x801DC31Cu;
    ctx->downcount -= 5;
    // 801DC31C: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC320:
    ctx->pc = 0x801DC320u;
    // 801DC320: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC324:
    ctx->pc = 0x801DC324u;
    // 801DC324: addi    r3, r3, 5188
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5188);

label_801DC328:
    ctx->pc = 0x801DC328u;
    // 801DC328: addi    r4, r4, -13172
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13172);

label_801DC32C:
    ctx->pc = 0x801DC32Cu;
    // 801DC32C: bl      0x801E530C
    {
            ctx->lr = 0x801DC330u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC330:
    ctx->pc = 0x801DC330u;
    ctx->downcount -= 5;
    // 801DC330: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC334:
    ctx->pc = 0x801DC334u;
    // 801DC334: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC338:
    ctx->pc = 0x801DC338u;
    // 801DC338: addi    r3, r3, 5196
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5196);

label_801DC33C:
    ctx->pc = 0x801DC33Cu;
    // 801DC33C: addi    r4, r4, -13136
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13136);

label_801DC340:
    ctx->pc = 0x801DC340u;
    // 801DC340: bl      0x801E530C
    {
            ctx->lr = 0x801DC344u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC344:
    ctx->pc = 0x801DC344u;
    ctx->downcount -= 5;
    // 801DC344: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC348:
    ctx->pc = 0x801DC348u;
    // 801DC348: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC34C:
    ctx->pc = 0x801DC34Cu;
    // 801DC34C: addi    r3, r3, 5204
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5204);

label_801DC350:
    ctx->pc = 0x801DC350u;
    // 801DC350: addi    r4, r4, -13100
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13100);

label_801DC354:
    ctx->pc = 0x801DC354u;
    // 801DC354: bl      0x801E530C
    {
            ctx->lr = 0x801DC358u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC358:
    ctx->pc = 0x801DC358u;
    ctx->downcount -= 5;
    // 801DC358: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC35C:
    ctx->pc = 0x801DC35Cu;
    // 801DC35C: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC360:
    ctx->pc = 0x801DC360u;
    // 801DC360: addi    r3, r3, 5224
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5224);

label_801DC364:
    ctx->pc = 0x801DC364u;
    // 801DC364: addi    r4, r4, -13064
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13064);

label_801DC368:
    ctx->pc = 0x801DC368u;
    // 801DC368: bl      0x801E530C
    {
            ctx->lr = 0x801DC36Cu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC36C:
    ctx->pc = 0x801DC36Cu;
    ctx->downcount -= 5;
    // 801DC36C: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC370:
    ctx->pc = 0x801DC370u;
    // 801DC370: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC374:
    ctx->pc = 0x801DC374u;
    // 801DC374: addi    r3, r3, 5232
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5232);

label_801DC378:
    ctx->pc = 0x801DC378u;
    // 801DC378: addi    r4, r4, -13028
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13028);

label_801DC37C:
    ctx->pc = 0x801DC37Cu;
    // 801DC37C: bl      0x801E530C
    {
            ctx->lr = 0x801DC380u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC380:
    ctx->pc = 0x801DC380u;
    ctx->downcount -= 5;
    // 801DC380: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC384:
    ctx->pc = 0x801DC384u;
    // 801DC384: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC388:
    ctx->pc = 0x801DC388u;
    // 801DC388: addi    r3, r3, 5240
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5240);

label_801DC38C:
    ctx->pc = 0x801DC38Cu;
    // 801DC38C: addi    r4, r4, -12992
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12992);

label_801DC390:
    ctx->pc = 0x801DC390u;
    // 801DC390: bl      0x801E530C
    {
            ctx->lr = 0x801DC394u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC394:
    ctx->pc = 0x801DC394u;
    ctx->downcount -= 5;
    // 801DC394: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC398:
    ctx->pc = 0x801DC398u;
    // 801DC398: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC39C:
    ctx->pc = 0x801DC39Cu;
    // 801DC39C: addi    r3, r3, 5252
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5252);

label_801DC3A0:
    ctx->pc = 0x801DC3A0u;
    // 801DC3A0: addi    r4, r4, -12956
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12956);

label_801DC3A4:
    ctx->pc = 0x801DC3A4u;
    // 801DC3A4: bl      0x801E530C
    {
            ctx->lr = 0x801DC3A8u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC3A8:
    ctx->pc = 0x801DC3A8u;
    ctx->downcount -= 5;
    // 801DC3A8: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC3AC:
    ctx->pc = 0x801DC3ACu;
    // 801DC3AC: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC3B0:
    ctx->pc = 0x801DC3B0u;
    // 801DC3B0: addi    r3, r3, 5268
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5268);

label_801DC3B4:
    ctx->pc = 0x801DC3B4u;
    // 801DC3B4: addi    r4, r4, -12920
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12920);

label_801DC3B8:
    ctx->pc = 0x801DC3B8u;
    // 801DC3B8: bl      0x801E530C
    {
            ctx->lr = 0x801DC3BCu;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC3BC:
    ctx->pc = 0x801DC3BCu;
    ctx->downcount -= 5;
    // 801DC3BC: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DC3C0:
    ctx->pc = 0x801DC3C0u;
    // 801DC3C0: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DC3C4:
    ctx->pc = 0x801DC3C4u;
    // 801DC3C4: addi    r3, r3, 5280
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5280);

label_801DC3C8:
    ctx->pc = 0x801DC3C8u;
    // 801DC3C8: addi    r4, r4, -12884
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12884);

label_801DC3CC:
    ctx->pc = 0x801DC3CCu;
    // 801DC3CC: bl      0x801E530C
    {
            ctx->lr = 0x801DC3D0u;
            ctx->pc = 0x801E530Cu;
            return;
    }

label_801DC3D0:
    ctx->pc = 0x801DC3D0u;
    ctx->downcount -= 5;
    // 801DC3D0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC3D4:
    ctx->pc = 0x801DC3D4u;
    // 801DC3D4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC3D8:
    ctx->pc = 0x801DC3D8u;
    // 801DC3D8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC3DC:
    ctx->pc = 0x801DC3DCu;
    // 801DC3DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC3E0:
    ctx->pc = 0x801DC3E0u;
    ctx->downcount -= 16;
    // 801DC3E0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC3E4:
    ctx->pc = 0x801DC3E4u;
    // 801DC3E4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC3E8:
    ctx->pc = 0x801DC3E8u;
    // 801DC3E8: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DC3EC:
    ctx->pc = 0x801DC3ECu;
    // 801DC3EC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC3F0:
    ctx->pc = 0x801DC3F0u;
    // 801DC3F0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DC3F4:
    ctx->pc = 0x801DC3F4u;
    // 801DC3F4: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC3F8:
    ctx->pc = 0x801DC3F8u;
    ctx->downcount -= 11;
    // 801DC3F8: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC3FC:
    ctx->pc = 0x801DC3FCu;
    // 801DC3FC: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DC400:
    // 801DC400: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_801DC404:
    ctx->pc = 0x801DC404u;
    // 801DC404: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DC408:
    // 801DC408: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_801DC40C:
    // 801DC40C: cmplw   r10, r11
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

label_801DC410:
    // 801DC410: bc    12, 0, 0x801DC438
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DC438;
        }
    }

label_801DC414:
    ctx->downcount -= 3;
    // 801DC414: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DC418:
    ctx->pc = 0x801DC418u;
    // 801DC418: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC41C:
    // 801DC41C: b       0x801DC510
    {
            goto label_801DC510;
    }

label_801DC420:
    ctx->pc = 0x801DC420u;
    ctx->downcount -= 6;
    // 801DC420: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DC424:
    // 801DC424: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DC428:
    ctx->pc = 0x801DC428u;
    // 801DC428: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC42C:
    ctx->pc = 0x801DC42Cu;
    // 801DC42C: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DC430:
    ctx->pc = 0x801DC430u;
    // 801DC430: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801DC434:
    // 801DC434: b       0x801DC3F8
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DC3F8u;
                return;
            }
            goto label_801DC3F8;
    }

label_801DC438:
    ctx->downcount -= 2;
    // 801DC438: cmplw   r10, r30
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

label_801DC43C:
    // 801DC43C: bc    12, 0, 0x801DC45C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DC45C;
        }
    }

label_801DC440:
    ctx->downcount -= 50;
    // 801DC440: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_801DC444:
    ctx->pc = 0x801DC444u;
    // 801DC444: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC448:
    // 801DC448: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_801DC44C:
    ctx->pc = 0x801DC44Cu;
    // 801DC44C: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DC450:
    // 801DC450: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DC454:
    ctx->pc = 0x801DC454u;
    // 801DC454: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC458:
    // 801DC458: b       0x801DC510
    {
            goto label_801DC510;
    }

label_801DC45C:
    ctx->pc = 0x801DC45Cu;
    ctx->downcount -= 8;
    // 801DC45C: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DC460:
    // 801DC460: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DC464:
    // 801DC464: cmpwi   r10, 0
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

label_801DC468:
    // 801DC468: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_801DC46C:
    // 801DC46C: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_801DC470:
    // 801DC470: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_801DC474:
    // 801DC474: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_801DC478:
    // 801DC478: bc    12, 2, 0x801DC498
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DC498;
        }
    }

label_801DC47C:
    ctx->downcount -= 7;
    // 801DC47C: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_801DC480:
    // 801DC480: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801DC484:
    // 801DC484: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DC488:
    // 801DC488: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801DC48C:
    ctx->pc = 0x801DC48Cu;
    // 801DC48C: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801DC490:
    ctx->pc = 0x801DC490u;
    // 801DC490: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DC494:
    ctx->pc = 0x801DC494u;
    // 801DC494: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DC498:
    ctx->downcount -= 2;
    // 801DC498: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DC49C:
    // 801DC49C: bl      0x80281C60
    {
            ctx->lr = 0x801DC4A0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801DC4A0:
    ctx->downcount -= 3;
    // 801DC4A0: cmpwi   r3, 0
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

label_801DC4A4:
    ctx->pc = 0x801DC4A4u;
    // 801DC4A4: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DC4A8:
    // 801DC4A8: bc    4, 2, 0x801DC4F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DC4F4;
        }
    }

label_801DC4AC:
    ctx->downcount -= 3;
    // 801DC4AC: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DC4B0:
    // 801DC4B0: cmplwi  r11, 0x0080
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

label_801DC4B4:
    // 801DC4B4: bc    12, 1, 0x801DC4E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DC4E0;
        }
    }

label_801DC4B8:
    ctx->downcount -= 2;
    // 801DC4B8: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801DC4BC:
    // 801DC4BC: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801DC4C0:
    ctx->downcount -= 5;
    // 801DC4C0: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_801DC4C4:
    // 801DC4C4: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DC4C8:
    ctx->pc = 0x801DC4C8u;
    // 801DC4C8: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801DC4CC:
    // 801DC4CC: cmpwi   r10, 0
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

label_801DC4D0:
    // 801DC4D0: bc    4, 2, 0x801DC420
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DC420u;
                return;
            }
            goto label_801DC420;
        }
    }

label_801DC4D4:
    ctx->downcount -= 3;
    // 801DC4D4: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_801DC4D8:
    // 801DC4D8: cmplwi  r11, 0x0080
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

label_801DC4DC:
    // 801DC4DC: bc    4, 1, 0x801DC4C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DC4C0u;
                return;
            }
            goto label_801DC4C0;
        }
    }

label_801DC4E0:
    ctx->downcount -= 4;
    // 801DC4E0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DC4E4:
    // 801DC4E4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DC4E8:
    ctx->pc = 0x801DC4E8u;
    // 801DC4E8: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC4EC:
    // 801DC4EC: bl      0x80281C60
    {
            ctx->lr = 0x801DC4F0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801DC4F0:
    ctx->pc = 0x801DC4F0u;
    ctx->downcount -= 1;
    // 801DC4F0: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DC4F4:
    ctx->pc = 0x801DC4F4u;
    ctx->downcount -= 7;
    // 801DC4F4: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC4F8:
    ctx->pc = 0x801DC4F8u;
    // 801DC4F8: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DC4FC:
    // 801DC4FC: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DC500:
    // 801DC500: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_801DC504:
    ctx->pc = 0x801DC504u;
    // 801DC504: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC508:
    ctx->pc = 0x801DC508u;
    // 801DC508: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DC50C:
    // 801DC50C: b       0x801DC3F8
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DC3F8u;
                return;
            }
            goto label_801DC3F8;
    }

label_801DC510:
    ctx->pc = 0x801DC510u;
    ctx->downcount -= 16;
    // 801DC510: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC514:
    ctx->pc = 0x801DC514u;
    // 801DC514: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC518:
    ctx->pc = 0x801DC518u;
    // 801DC518: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DC51C:
    ctx->pc = 0x801DC51Cu;
    // 801DC51C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DC520:
    ctx->pc = 0x801DC520u;
    // 801DC520: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC524:
    ctx->pc = 0x801DC524u;
    ctx->downcount -= 21;
    // 801DC524: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC528:
    ctx->pc = 0x801DC528u;
    // 801DC528: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC52C:
    ctx->pc = 0x801DC52Cu;
    // 801DC52C: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DC530:
    ctx->pc = 0x801DC530u;
    // 801DC530: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC534:
    ctx->pc = 0x801DC534u;
    // 801DC534: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801DC538:
    ctx->pc = 0x801DC538u;
    // 801DC538: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_801DC53C:
    ctx->pc = 0x801DC53Cu;
    // 801DC53C: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801DC540:
    ctx->pc = 0x801DC540u;
    // 801DC540: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DC544:
    ctx->pc = 0x801DC544u;
    // 801DC544: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801DC548:
    ctx->pc = 0x801DC548u;
    // 801DC548: cmpwi   r30, 0
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

label_801DC54C:
    ctx->pc = 0x801DC54Cu;
    // 801DC54C: bc    12, 2, 0x801DC55C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DC55C;
        }
    }

label_801DC550:
    ctx->pc = 0x801DC550u;
    ctx->downcount -= 3;
    // 801DC550: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC554:
    ctx->pc = 0x801DC554u;
    // 801DC554: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC558:
    ctx->pc = 0x801DC558u;
    // 801DC558: b       0x801DC5DC
    {
            goto label_801DC5DC;
    }

label_801DC55C:
    ctx->pc = 0x801DC55Cu;
    ctx->downcount -= 7;
    // 801DC55C: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_801DC560:
    ctx->pc = 0x801DC560u;
    // 801DC560: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_801DC564:
    ctx->pc = 0x801DC564u;
    // 801DC564: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_801DC568:
    ctx->pc = 0x801DC568u;
    // 801DC568: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DC56C:
    ctx->pc = 0x801DC56Cu;
    // 801DC56C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DC570:
    ctx->pc = 0x801DC570u;
    // 801DC570: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_801DC574:
    ctx->pc = 0x801DC574u;
    // 801DC574: bl      0x80003EE0
    {
            ctx->lr = 0x801DC578u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_801DC578:
    ctx->pc = 0x801DC578u;
    ctx->downcount -= 3;
    // 801DC578: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DC57C:
    ctx->pc = 0x801DC57Cu;
    // 801DC57C: cmpwi   r9, 1
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

label_801DC580:
    ctx->pc = 0x801DC580u;
    // 801DC580: bc    12, 2, 0x801DC5D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DC5D8;
        }
    }

label_801DC584:
    ctx->pc = 0x801DC584u;
    ctx->downcount -= 9;
    // 801DC584: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_801DC588:
    ctx->pc = 0x801DC588u;
    // 801DC588: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801DC58C:
    ctx->pc = 0x801DC58Cu;
    // 801DC58C: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DC590:
    ctx->pc = 0x801DC590u;
    // 801DC590: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801DC594:
    ctx->pc = 0x801DC594u;
    // 801DC594: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DC598:
    ctx->pc = 0x801DC598u;
    // 801DC598: cmpwi   r9, 2
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

label_801DC59C:
    ctx->pc = 0x801DC59Cu;
    // 801DC59C: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_801DC5A0:
    ctx->pc = 0x801DC5A0u;
    // 801DC5A0: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801DC5A4:
    ctx->pc = 0x801DC5A4u;
    // 801DC5A4: bc    4, 2, 0x801DC5B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DC5B0;
        }
    }

label_801DC5A8:
    ctx->pc = 0x801DC5A8u;
    ctx->downcount -= 2;
    // 801DC5A8: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801DC5AC:
    ctx->pc = 0x801DC5ACu;
    // 801DC5AC: b       0x801DC5D8
    {
            goto label_801DC5D8;
    }

label_801DC5B0:
    loop_801DC5B0(ctx);
    if (ctx->pc == 0x801DC5D0u) goto label_801DC5D0;
    return;
label_801DC5B4:
    // 801DC5B4: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_801DC5B8:
    // 801DC5B8: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801DC5BC:
    ctx->pc = 0x801DC5BCu;
    // 801DC5BC: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DC5C0:
    // 801DC5C0: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801DC5C4:
    // 801DC5C4: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801DC5C8:
    // 801DC5C8: cmpw    r9, r8
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

label_801DC5CC:
    // 801DC5CC: bc    4, 2, 0x801DC5B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DC5B0u;
                return;
            }
            goto label_801DC5B0;
        }
    }

label_801DC5D0:
    ctx->pc = 0x801DC5D0u;
    ctx->downcount -= 2;
    // 801DC5D0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DC5D4:
    ctx->pc = 0x801DC5D4u;
    // 801DC5D4: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC5D8:
    ctx->pc = 0x801DC5D8u;
    ctx->downcount -= 1;
    // 801DC5D8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DC5DC:
    ctx->pc = 0x801DC5DCu;
    ctx->downcount -= 17;
    // 801DC5DC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DC5E0:
    ctx->pc = 0x801DC5E0u;
    // 801DC5E0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC5E4:
    ctx->pc = 0x801DC5E4u;
    // 801DC5E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC5E8:
    ctx->pc = 0x801DC5E8u;
    // 801DC5E8: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DC5EC:
    ctx->pc = 0x801DC5ECu;
    // 801DC5EC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801DC5F0:
    ctx->pc = 0x801DC5F0u;
    // 801DC5F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC5F4:
    ctx->pc = 0x801DC5F4u;
    ctx->downcount -= 7;
    // 801DC5F4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC5F8:
    ctx->pc = 0x801DC5F8u;
    // 801DC5F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC5FC:
    ctx->pc = 0x801DC5FCu;
    // 801DC5FC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC600:
    ctx->pc = 0x801DC600u;
    // 801DC600: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DC604:
    ctx->pc = 0x801DC604u;
    // 801DC604: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_801DC608:
    ctx->pc = 0x801DC608u;
    // 801DC608: cmpw    r4, r0
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

label_801DC60C:
    ctx->pc = 0x801DC60Cu;
    // 801DC60C: bc    4, 2, 0x801DC6B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DC6B8;
        }
    }

label_801DC610:
    ctx->pc = 0x801DC610u;
    ctx->downcount -= 2;
    // 801DC610: cmpwi   r3, 0
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

label_801DC614:
    ctx->pc = 0x801DC614u;
    // 801DC614: bc    12, 2, 0x801DC6B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DC6B8;
        }
    }

label_801DC618:
    ctx->pc = 0x801DC618u;
    ctx->downcount -= 5;
    // 801DC618: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_801DC61C:
    ctx->pc = 0x801DC61Cu;
    // 801DC61C: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_801DC620:
    ctx->pc = 0x801DC620u;
    // 801DC620: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_801DC624:
    ctx->pc = 0x801DC624u;
    // 801DC624: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DC628:
    ctx->pc = 0x801DC628u;
    // 801DC628: bl      0x80252AF0
    {
            ctx->lr = 0x801DC62Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DC62C:
    ctx->pc = 0x801DC62Cu;
    ctx->downcount -= 5;
    // 801DC62C: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_801DC630:
    ctx->pc = 0x801DC630u;
    // 801DC630: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801DC634:
    ctx->pc = 0x801DC634u;
    // 801DC634: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_801DC638:
    ctx->pc = 0x801DC638u;
    // 801DC638: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DC63C:
    ctx->pc = 0x801DC63Cu;
    // 801DC63C: bl      0x80252AF0
    {
            ctx->lr = 0x801DC640u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DC640:
    ctx->pc = 0x801DC640u;
    ctx->downcount -= 5;
    // 801DC640: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_801DC644:
    ctx->pc = 0x801DC644u;
    // 801DC644: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_801DC648:
    ctx->pc = 0x801DC648u;
    // 801DC648: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_801DC64C:
    ctx->pc = 0x801DC64Cu;
    // 801DC64C: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_801DC650:
    ctx->pc = 0x801DC650u;
    // 801DC650: bl      0x80252AF0
    {
            ctx->lr = 0x801DC654u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DC654:
    ctx->pc = 0x801DC654u;
    ctx->downcount -= 5;
    // 801DC654: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_801DC658:
    ctx->pc = 0x801DC658u;
    // 801DC658: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_801DC65C:
    ctx->pc = 0x801DC65Cu;
    // 801DC65C: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_801DC660:
    ctx->pc = 0x801DC660u;
    // 801DC660: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DC664:
    ctx->pc = 0x801DC664u;
    // 801DC664: bl      0x80252AF0
    {
            ctx->lr = 0x801DC668u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DC668:
    ctx->pc = 0x801DC668u;
    ctx->downcount -= 5;
    // 801DC668: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_801DC66C:
    ctx->pc = 0x801DC66Cu;
    // 801DC66C: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_801DC670:
    ctx->pc = 0x801DC670u;
    // 801DC670: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_801DC674:
    ctx->pc = 0x801DC674u;
    // 801DC674: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DC678:
    ctx->pc = 0x801DC678u;
    // 801DC678: bl      0x80252AF0
    {
            ctx->lr = 0x801DC67Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DC67C:
    ctx->pc = 0x801DC67Cu;
    ctx->downcount -= 5;
    // 801DC67C: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_801DC680:
    ctx->pc = 0x801DC680u;
    // 801DC680: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_801DC684:
    ctx->pc = 0x801DC684u;
    // 801DC684: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_801DC688:
    ctx->pc = 0x801DC688u;
    // 801DC688: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DC68C:
    ctx->pc = 0x801DC68Cu;
    // 801DC68C: bl      0x80252AF0
    {
            ctx->lr = 0x801DC690u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DC690:
    ctx->pc = 0x801DC690u;
    ctx->downcount -= 5;
    // 801DC690: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_801DC694:
    ctx->pc = 0x801DC694u;
    // 801DC694: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_801DC698:
    ctx->pc = 0x801DC698u;
    // 801DC698: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_801DC69C:
    ctx->pc = 0x801DC69Cu;
    // 801DC69C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DC6A0:
    ctx->pc = 0x801DC6A0u;
    // 801DC6A0: bl      0x80252AF0
    {
            ctx->lr = 0x801DC6A4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DC6A4:
    ctx->pc = 0x801DC6A4u;
    ctx->downcount -= 5;
    // 801DC6A4: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_801DC6A8:
    ctx->pc = 0x801DC6A8u;
    // 801DC6A8: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_801DC6AC:
    ctx->pc = 0x801DC6ACu;
    // 801DC6AC: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_801DC6B0:
    ctx->pc = 0x801DC6B0u;
    // 801DC6B0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DC6B4:
    ctx->pc = 0x801DC6B4u;
    // 801DC6B4: bl      0x80252AF0
    {
            ctx->lr = 0x801DC6B8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DC6B8:
    ctx->pc = 0x801DC6B8u;
    ctx->downcount -= 5;
    // 801DC6B8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC6BC:
    ctx->pc = 0x801DC6BCu;
    // 801DC6BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC6C0:
    ctx->pc = 0x801DC6C0u;
    // 801DC6C0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC6C4:
    ctx->pc = 0x801DC6C4u;
    // 801DC6C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC6C8:
    ctx->pc = 0x801DC6C8u;
    ctx->downcount -= 5;
    // 801DC6C8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC6CC:
    ctx->pc = 0x801DC6CCu;
    // 801DC6CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC6D0:
    ctx->pc = 0x801DC6D0u;
    // 801DC6D0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC6D4:
    ctx->pc = 0x801DC6D4u;
    // 801DC6D4: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC6D8:
    ctx->pc = 0x801DC6D8u;
    // 801DC6D8: bl      0x801DCDD0
    {
            ctx->lr = 0x801DC6DCu;
            goto label_801DCDD0;
    }

label_801DC6DC:
    ctx->pc = 0x801DC6DCu;
    ctx->downcount -= 5;
    // 801DC6DC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC6E0:
    ctx->pc = 0x801DC6E0u;
    // 801DC6E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC6E4:
    ctx->pc = 0x801DC6E4u;
    // 801DC6E4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC6E8:
    ctx->pc = 0x801DC6E8u;
    // 801DC6E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC6EC:
    ctx->pc = 0x801DC6ECu;
    ctx->downcount -= 5;
    // 801DC6EC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC6F0:
    ctx->pc = 0x801DC6F0u;
    // 801DC6F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC6F4:
    ctx->pc = 0x801DC6F4u;
    // 801DC6F4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC6F8:
    ctx->pc = 0x801DC6F8u;
    // 801DC6F8: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC6FC:
    ctx->pc = 0x801DC6FCu;
    // 801DC6FC: bl      0x801DCE1C
    {
            ctx->lr = 0x801DC700u;
            goto label_801DCE1C;
    }

label_801DC700:
    ctx->pc = 0x801DC700u;
    ctx->downcount -= 5;
    // 801DC700: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC704:
    ctx->pc = 0x801DC704u;
    // 801DC704: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC708:
    ctx->pc = 0x801DC708u;
    // 801DC708: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC70C:
    ctx->pc = 0x801DC70Cu;
    // 801DC70C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC710:
    ctx->pc = 0x801DC710u;
    ctx->downcount -= 5;
    // 801DC710: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC714:
    ctx->pc = 0x801DC714u;
    // 801DC714: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC718:
    ctx->pc = 0x801DC718u;
    // 801DC718: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC71C:
    ctx->pc = 0x801DC71Cu;
    // 801DC71C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC720:
    ctx->pc = 0x801DC720u;
    // 801DC720: bl      0x801DCE68
    {
            ctx->lr = 0x801DC724u;
            goto label_801DCE68;
    }

label_801DC724:
    ctx->pc = 0x801DC724u;
    ctx->downcount -= 5;
    // 801DC724: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC728:
    ctx->pc = 0x801DC728u;
    // 801DC728: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC72C:
    ctx->pc = 0x801DC72Cu;
    // 801DC72C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC730:
    ctx->pc = 0x801DC730u;
    // 801DC730: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC734:
    ctx->pc = 0x801DC734u;
    ctx->downcount -= 5;
    // 801DC734: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC738:
    ctx->pc = 0x801DC738u;
    // 801DC738: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC73C:
    ctx->pc = 0x801DC73Cu;
    // 801DC73C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC740:
    ctx->pc = 0x801DC740u;
    // 801DC740: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC744:
    ctx->pc = 0x801DC744u;
    // 801DC744: bl      0x801DCEB4
    {
            ctx->lr = 0x801DC748u;
            goto label_801DCEB4;
    }

label_801DC748:
    ctx->pc = 0x801DC748u;
    ctx->downcount -= 5;
    // 801DC748: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC74C:
    ctx->pc = 0x801DC74Cu;
    // 801DC74C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC750:
    ctx->pc = 0x801DC750u;
    // 801DC750: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC754:
    ctx->pc = 0x801DC754u;
    // 801DC754: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC758:
    ctx->pc = 0x801DC758u;
    ctx->downcount -= 5;
    // 801DC758: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC75C:
    ctx->pc = 0x801DC75Cu;
    // 801DC75C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC760:
    ctx->pc = 0x801DC760u;
    // 801DC760: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC764:
    ctx->pc = 0x801DC764u;
    // 801DC764: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC768:
    ctx->pc = 0x801DC768u;
    // 801DC768: bl      0x801DCF1C
    {
            ctx->lr = 0x801DC76Cu;
            goto label_801DCF1C;
    }

label_801DC76C:
    ctx->pc = 0x801DC76Cu;
    ctx->downcount -= 5;
    // 801DC76C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC770:
    ctx->pc = 0x801DC770u;
    // 801DC770: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC774:
    ctx->pc = 0x801DC774u;
    // 801DC774: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC778:
    ctx->pc = 0x801DC778u;
    // 801DC778: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC77C:
    ctx->pc = 0x801DC77Cu;
    ctx->downcount -= 5;
    // 801DC77C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC780:
    ctx->pc = 0x801DC780u;
    // 801DC780: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC784:
    ctx->pc = 0x801DC784u;
    // 801DC784: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC788:
    ctx->pc = 0x801DC788u;
    // 801DC788: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC78C:
    ctx->pc = 0x801DC78Cu;
    // 801DC78C: bl      0x801DCF84
    {
            ctx->lr = 0x801DC790u;
            goto label_801DCF84;
    }

label_801DC790:
    ctx->pc = 0x801DC790u;
    ctx->downcount -= 5;
    // 801DC790: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC794:
    ctx->pc = 0x801DC794u;
    // 801DC794: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC798:
    ctx->pc = 0x801DC798u;
    // 801DC798: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC79C:
    ctx->pc = 0x801DC79Cu;
    // 801DC79C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC7A0:
    ctx->pc = 0x801DC7A0u;
    ctx->downcount -= 5;
    // 801DC7A0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC7A4:
    ctx->pc = 0x801DC7A4u;
    // 801DC7A4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC7A8:
    ctx->pc = 0x801DC7A8u;
    // 801DC7A8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC7AC:
    ctx->pc = 0x801DC7ACu;
    // 801DC7AC: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC7B0:
    ctx->pc = 0x801DC7B0u;
    // 801DC7B0: bl      0x801DCFD0
    {
            ctx->lr = 0x801DC7B4u;
            goto label_801DCFD0;
    }

label_801DC7B4:
    ctx->pc = 0x801DC7B4u;
    ctx->downcount -= 5;
    // 801DC7B4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC7B8:
    ctx->pc = 0x801DC7B8u;
    // 801DC7B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC7BC:
    ctx->pc = 0x801DC7BCu;
    // 801DC7BC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC7C0:
    ctx->pc = 0x801DC7C0u;
    // 801DC7C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC7C4:
    ctx->pc = 0x801DC7C4u;
    ctx->downcount -= 5;
    // 801DC7C4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC7C8:
    ctx->pc = 0x801DC7C8u;
    // 801DC7C8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC7CC:
    ctx->pc = 0x801DC7CCu;
    // 801DC7CC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC7D0:
    ctx->pc = 0x801DC7D0u;
    // 801DC7D0: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC7D4:
    ctx->pc = 0x801DC7D4u;
    // 801DC7D4: bl      0x801DD01C
    {
            ctx->lr = 0x801DC7D8u;
            goto label_801DD01C;
    }

label_801DC7D8:
    ctx->pc = 0x801DC7D8u;
    ctx->downcount -= 5;
    // 801DC7D8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC7DC:
    ctx->pc = 0x801DC7DCu;
    // 801DC7DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC7E0:
    ctx->pc = 0x801DC7E0u;
    // 801DC7E0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC7E4:
    ctx->pc = 0x801DC7E4u;
    // 801DC7E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC7E8:
    ctx->pc = 0x801DC7E8u;
    ctx->downcount -= 5;
    // 801DC7E8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC7EC:
    ctx->pc = 0x801DC7ECu;
    // 801DC7EC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC7F0:
    ctx->pc = 0x801DC7F0u;
    // 801DC7F0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC7F4:
    ctx->pc = 0x801DC7F4u;
    // 801DC7F4: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC7F8:
    ctx->pc = 0x801DC7F8u;
    // 801DC7F8: bl      0x801DD068
    {
            ctx->lr = 0x801DC7FCu;
            goto label_801DD068;
    }

label_801DC7FC:
    ctx->pc = 0x801DC7FCu;
    ctx->downcount -= 5;
    // 801DC7FC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC800:
    ctx->pc = 0x801DC800u;
    // 801DC800: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC804:
    ctx->pc = 0x801DC804u;
    // 801DC804: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC808:
    ctx->pc = 0x801DC808u;
    // 801DC808: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC80C:
    ctx->pc = 0x801DC80Cu;
    ctx->downcount -= 5;
    // 801DC80C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC810:
    ctx->pc = 0x801DC810u;
    // 801DC810: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC814:
    ctx->pc = 0x801DC814u;
    // 801DC814: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC818:
    ctx->pc = 0x801DC818u;
    // 801DC818: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC81C:
    ctx->pc = 0x801DC81Cu;
    // 801DC81C: bl      0x801DD0B4
    {
            ctx->lr = 0x801DC820u;
            goto label_801DD0B4;
    }

label_801DC820:
    ctx->pc = 0x801DC820u;
    ctx->downcount -= 5;
    // 801DC820: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC824:
    ctx->pc = 0x801DC824u;
    // 801DC824: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC828:
    ctx->pc = 0x801DC828u;
    // 801DC828: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC82C:
    ctx->pc = 0x801DC82Cu;
    // 801DC82C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC830:
    ctx->pc = 0x801DC830u;
    ctx->downcount -= 5;
    // 801DC830: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC834:
    ctx->pc = 0x801DC834u;
    // 801DC834: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC838:
    ctx->pc = 0x801DC838u;
    // 801DC838: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC83C:
    ctx->pc = 0x801DC83Cu;
    // 801DC83C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC840:
    ctx->pc = 0x801DC840u;
    // 801DC840: bl      0x801DD100
    {
            ctx->lr = 0x801DC844u;
            goto label_801DD100;
    }

label_801DC844:
    ctx->pc = 0x801DC844u;
    ctx->downcount -= 5;
    // 801DC844: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC848:
    ctx->pc = 0x801DC848u;
    // 801DC848: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC84C:
    ctx->pc = 0x801DC84Cu;
    // 801DC84C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC850:
    ctx->pc = 0x801DC850u;
    // 801DC850: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC854:
    ctx->pc = 0x801DC854u;
    ctx->downcount -= 5;
    // 801DC854: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC858:
    ctx->pc = 0x801DC858u;
    // 801DC858: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC85C:
    ctx->pc = 0x801DC85Cu;
    // 801DC85C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC860:
    ctx->pc = 0x801DC860u;
    // 801DC860: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC864:
    ctx->pc = 0x801DC864u;
    // 801DC864: bl      0x801DD14C
    {
            ctx->lr = 0x801DC868u;
            goto label_801DD14C;
    }

label_801DC868:
    ctx->pc = 0x801DC868u;
    ctx->downcount -= 5;
    // 801DC868: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC86C:
    ctx->pc = 0x801DC86Cu;
    // 801DC86C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC870:
    ctx->pc = 0x801DC870u;
    // 801DC870: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC874:
    ctx->pc = 0x801DC874u;
    // 801DC874: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC878:
    ctx->pc = 0x801DC878u;
    ctx->downcount -= 5;
    // 801DC878: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC87C:
    ctx->pc = 0x801DC87Cu;
    // 801DC87C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC880:
    ctx->pc = 0x801DC880u;
    // 801DC880: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC884:
    ctx->pc = 0x801DC884u;
    // 801DC884: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC888:
    ctx->pc = 0x801DC888u;
    // 801DC888: bl      0x801DD1CC
    {
            ctx->lr = 0x801DC88Cu;
            goto label_801DD1CC;
    }

label_801DC88C:
    ctx->pc = 0x801DC88Cu;
    ctx->downcount -= 5;
    // 801DC88C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC890:
    ctx->pc = 0x801DC890u;
    // 801DC890: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC894:
    ctx->pc = 0x801DC894u;
    // 801DC894: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC898:
    ctx->pc = 0x801DC898u;
    // 801DC898: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC89C:
    ctx->pc = 0x801DC89Cu;
    ctx->downcount -= 5;
    // 801DC89C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC8A0:
    ctx->pc = 0x801DC8A0u;
    // 801DC8A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC8A4:
    ctx->pc = 0x801DC8A4u;
    // 801DC8A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC8A8:
    ctx->pc = 0x801DC8A8u;
    // 801DC8A8: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC8AC:
    ctx->pc = 0x801DC8ACu;
    // 801DC8AC: bl      0x801DD218
    {
            ctx->lr = 0x801DC8B0u;
            goto label_801DD218;
    }

label_801DC8B0:
    ctx->pc = 0x801DC8B0u;
    ctx->downcount -= 5;
    // 801DC8B0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC8B4:
    ctx->pc = 0x801DC8B4u;
    // 801DC8B4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC8B8:
    ctx->pc = 0x801DC8B8u;
    // 801DC8B8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC8BC:
    ctx->pc = 0x801DC8BCu;
    // 801DC8BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC8C0:
    ctx->pc = 0x801DC8C0u;
    ctx->downcount -= 5;
    // 801DC8C0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC8C4:
    ctx->pc = 0x801DC8C4u;
    // 801DC8C4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC8C8:
    ctx->pc = 0x801DC8C8u;
    // 801DC8C8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC8CC:
    ctx->pc = 0x801DC8CCu;
    // 801DC8CC: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC8D0:
    ctx->pc = 0x801DC8D0u;
    // 801DC8D0: bl      0x801DD294
    {
            ctx->lr = 0x801DC8D4u;
            goto label_801DD294;
    }

label_801DC8D4:
    ctx->pc = 0x801DC8D4u;
    ctx->downcount -= 5;
    // 801DC8D4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC8D8:
    ctx->pc = 0x801DC8D8u;
    // 801DC8D8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC8DC:
    ctx->pc = 0x801DC8DCu;
    // 801DC8DC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC8E0:
    ctx->pc = 0x801DC8E0u;
    // 801DC8E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC8E4:
    ctx->pc = 0x801DC8E4u;
    ctx->downcount -= 5;
    // 801DC8E4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC8E8:
    ctx->pc = 0x801DC8E8u;
    // 801DC8E8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC8EC:
    ctx->pc = 0x801DC8ECu;
    // 801DC8EC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC8F0:
    ctx->pc = 0x801DC8F0u;
    // 801DC8F0: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC8F4:
    ctx->pc = 0x801DC8F4u;
    // 801DC8F4: bl      0x801DD304
    {
            ctx->lr = 0x801DC8F8u;
            goto label_801DD304;
    }

label_801DC8F8:
    ctx->pc = 0x801DC8F8u;
    ctx->downcount -= 5;
    // 801DC8F8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC8FC:
    ctx->pc = 0x801DC8FCu;
    // 801DC8FC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC900:
    ctx->pc = 0x801DC900u;
    // 801DC900: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC904:
    ctx->pc = 0x801DC904u;
    // 801DC904: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC908:
    ctx->pc = 0x801DC908u;
    ctx->downcount -= 5;
    // 801DC908: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC90C:
    ctx->pc = 0x801DC90Cu;
    // 801DC90C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC910:
    ctx->pc = 0x801DC910u;
    // 801DC910: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC914:
    ctx->pc = 0x801DC914u;
    // 801DC914: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC918:
    ctx->pc = 0x801DC918u;
    // 801DC918: bl      0x801DD350
    {
            ctx->lr = 0x801DC91Cu;
            goto label_801DD350;
    }

label_801DC91C:
    ctx->pc = 0x801DC91Cu;
    ctx->downcount -= 5;
    // 801DC91C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC920:
    ctx->pc = 0x801DC920u;
    // 801DC920: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC924:
    ctx->pc = 0x801DC924u;
    // 801DC924: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC928:
    ctx->pc = 0x801DC928u;
    // 801DC928: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC92C:
    ctx->pc = 0x801DC92Cu;
    ctx->downcount -= 5;
    // 801DC92C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC930:
    ctx->pc = 0x801DC930u;
    // 801DC930: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC934:
    ctx->pc = 0x801DC934u;
    // 801DC934: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC938:
    ctx->pc = 0x801DC938u;
    // 801DC938: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC93C:
    ctx->pc = 0x801DC93Cu;
    // 801DC93C: bl      0x801DD3B8
    {
            ctx->lr = 0x801DC940u;
            goto label_801DD3B8;
    }

label_801DC940:
    ctx->pc = 0x801DC940u;
    ctx->downcount -= 5;
    // 801DC940: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC944:
    ctx->pc = 0x801DC944u;
    // 801DC944: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC948:
    ctx->pc = 0x801DC948u;
    // 801DC948: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC94C:
    ctx->pc = 0x801DC94Cu;
    // 801DC94C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC950:
    ctx->pc = 0x801DC950u;
    ctx->downcount -= 5;
    // 801DC950: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC954:
    ctx->pc = 0x801DC954u;
    // 801DC954: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC958:
    ctx->pc = 0x801DC958u;
    // 801DC958: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC95C:
    ctx->pc = 0x801DC95Cu;
    // 801DC95C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC960:
    ctx->pc = 0x801DC960u;
    // 801DC960: bl      0x801DD404
    {
            ctx->lr = 0x801DC964u;
            goto label_801DD404;
    }

label_801DC964:
    ctx->pc = 0x801DC964u;
    ctx->downcount -= 5;
    // 801DC964: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC968:
    ctx->pc = 0x801DC968u;
    // 801DC968: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC96C:
    ctx->pc = 0x801DC96Cu;
    // 801DC96C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC970:
    ctx->pc = 0x801DC970u;
    // 801DC970: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC974:
    ctx->pc = 0x801DC974u;
    ctx->downcount -= 5;
    // 801DC974: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC978:
    ctx->pc = 0x801DC978u;
    // 801DC978: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC97C:
    ctx->pc = 0x801DC97Cu;
    // 801DC97C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC980:
    ctx->pc = 0x801DC980u;
    // 801DC980: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC984:
    ctx->pc = 0x801DC984u;
    // 801DC984: bl      0x801DD46C
    {
            ctx->lr = 0x801DC988u;
            goto label_801DD46C;
    }

label_801DC988:
    ctx->pc = 0x801DC988u;
    ctx->downcount -= 5;
    // 801DC988: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC98C:
    ctx->pc = 0x801DC98Cu;
    // 801DC98C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC990:
    ctx->pc = 0x801DC990u;
    // 801DC990: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC994:
    ctx->pc = 0x801DC994u;
    // 801DC994: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC998:
    ctx->pc = 0x801DC998u;
    ctx->downcount -= 5;
    // 801DC998: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC99C:
    ctx->pc = 0x801DC99Cu;
    // 801DC99C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC9A0:
    ctx->pc = 0x801DC9A0u;
    // 801DC9A0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC9A4:
    ctx->pc = 0x801DC9A4u;
    // 801DC9A4: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC9A8:
    ctx->pc = 0x801DC9A8u;
    // 801DC9A8: bl      0x801DD4B8
    {
            ctx->lr = 0x801DC9ACu;
            goto label_801DD4B8;
    }

label_801DC9AC:
    ctx->pc = 0x801DC9ACu;
    ctx->downcount -= 5;
    // 801DC9AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC9B0:
    ctx->pc = 0x801DC9B0u;
    // 801DC9B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC9B4:
    ctx->pc = 0x801DC9B4u;
    // 801DC9B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC9B8:
    ctx->pc = 0x801DC9B8u;
    // 801DC9B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC9BC:
    ctx->pc = 0x801DC9BCu;
    ctx->downcount -= 5;
    // 801DC9BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC9C0:
    ctx->pc = 0x801DC9C0u;
    // 801DC9C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC9C4:
    ctx->pc = 0x801DC9C4u;
    // 801DC9C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC9C8:
    ctx->pc = 0x801DC9C8u;
    // 801DC9C8: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC9CC:
    ctx->pc = 0x801DC9CCu;
    // 801DC9CC: bl      0x801DD504
    {
            ctx->lr = 0x801DC9D0u;
            goto label_801DD504;
    }

label_801DC9D0:
    ctx->pc = 0x801DC9D0u;
    ctx->downcount -= 5;
    // 801DC9D0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC9D4:
    ctx->pc = 0x801DC9D4u;
    // 801DC9D4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC9D8:
    ctx->pc = 0x801DC9D8u;
    // 801DC9D8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DC9DC:
    ctx->pc = 0x801DC9DCu;
    // 801DC9DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DC9E0:
    ctx->pc = 0x801DC9E0u;
    ctx->downcount -= 5;
    // 801DC9E0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DC9E4:
    ctx->pc = 0x801DC9E4u;
    // 801DC9E4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DC9E8:
    ctx->pc = 0x801DC9E8u;
    // 801DC9E8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DC9EC:
    ctx->pc = 0x801DC9ECu;
    // 801DC9EC: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DC9F0:
    ctx->pc = 0x801DC9F0u;
    // 801DC9F0: bl      0x801DD550
    {
            ctx->lr = 0x801DC9F4u;
            goto label_801DD550;
    }

label_801DC9F4:
    ctx->pc = 0x801DC9F4u;
    ctx->downcount -= 5;
    // 801DC9F4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DC9F8:
    ctx->pc = 0x801DC9F8u;
    // 801DC9F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DC9FC:
    ctx->pc = 0x801DC9FCu;
    // 801DC9FC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCA00:
    ctx->pc = 0x801DCA00u;
    // 801DCA00: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCA04:
    ctx->pc = 0x801DCA04u;
    ctx->downcount -= 5;
    // 801DCA04: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCA08:
    ctx->pc = 0x801DCA08u;
    // 801DCA08: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCA0C:
    ctx->pc = 0x801DCA0Cu;
    // 801DCA0C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCA10:
    ctx->pc = 0x801DCA10u;
    // 801DCA10: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCA14:
    ctx->pc = 0x801DCA14u;
    // 801DCA14: bl      0x801DD59C
    {
            ctx->lr = 0x801DCA18u;
            goto label_801DD59C;
    }

label_801DCA18:
    ctx->pc = 0x801DCA18u;
    ctx->downcount -= 5;
    // 801DCA18: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCA1C:
    ctx->pc = 0x801DCA1Cu;
    // 801DCA1C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCA20:
    ctx->pc = 0x801DCA20u;
    // 801DCA20: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCA24:
    ctx->pc = 0x801DCA24u;
    // 801DCA24: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCA28:
    ctx->pc = 0x801DCA28u;
    ctx->downcount -= 5;
    // 801DCA28: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCA2C:
    ctx->pc = 0x801DCA2Cu;
    // 801DCA2C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCA30:
    ctx->pc = 0x801DCA30u;
    // 801DCA30: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCA34:
    ctx->pc = 0x801DCA34u;
    // 801DCA34: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCA38:
    ctx->pc = 0x801DCA38u;
    // 801DCA38: bl      0x801DD5E8
    {
            ctx->lr = 0x801DCA3Cu;
            goto label_801DD5E8;
    }

label_801DCA3C:
    ctx->pc = 0x801DCA3Cu;
    ctx->downcount -= 5;
    // 801DCA3C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCA40:
    ctx->pc = 0x801DCA40u;
    // 801DCA40: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCA44:
    ctx->pc = 0x801DCA44u;
    // 801DCA44: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCA48:
    ctx->pc = 0x801DCA48u;
    // 801DCA48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCA4C:
    ctx->pc = 0x801DCA4Cu;
    ctx->downcount -= 5;
    // 801DCA4C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCA50:
    ctx->pc = 0x801DCA50u;
    // 801DCA50: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCA54:
    ctx->pc = 0x801DCA54u;
    // 801DCA54: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCA58:
    ctx->pc = 0x801DCA58u;
    // 801DCA58: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCA5C:
    ctx->pc = 0x801DCA5Cu;
    // 801DCA5C: bl      0x801DD634
    {
            ctx->lr = 0x801DCA60u;
            goto label_801DD634;
    }

label_801DCA60:
    ctx->pc = 0x801DCA60u;
    ctx->downcount -= 5;
    // 801DCA60: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCA64:
    ctx->pc = 0x801DCA64u;
    // 801DCA64: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCA68:
    ctx->pc = 0x801DCA68u;
    // 801DCA68: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCA6C:
    ctx->pc = 0x801DCA6Cu;
    // 801DCA6C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCA70:
    ctx->pc = 0x801DCA70u;
    ctx->downcount -= 5;
    // 801DCA70: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCA74:
    ctx->pc = 0x801DCA74u;
    // 801DCA74: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCA78:
    ctx->pc = 0x801DCA78u;
    // 801DCA78: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCA7C:
    ctx->pc = 0x801DCA7Cu;
    // 801DCA7C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCA80:
    ctx->pc = 0x801DCA80u;
    // 801DCA80: bl      0x801DD680
    {
            ctx->lr = 0x801DCA84u;
            goto label_801DD680;
    }

label_801DCA84:
    ctx->pc = 0x801DCA84u;
    ctx->downcount -= 5;
    // 801DCA84: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCA88:
    ctx->pc = 0x801DCA88u;
    // 801DCA88: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCA8C:
    ctx->pc = 0x801DCA8Cu;
    // 801DCA8C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCA90:
    ctx->pc = 0x801DCA90u;
    // 801DCA90: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCA94:
    ctx->pc = 0x801DCA94u;
    ctx->downcount -= 5;
    // 801DCA94: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCA98:
    ctx->pc = 0x801DCA98u;
    // 801DCA98: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCA9C:
    ctx->pc = 0x801DCA9Cu;
    // 801DCA9C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCAA0:
    ctx->pc = 0x801DCAA0u;
    // 801DCAA0: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCAA4:
    ctx->pc = 0x801DCAA4u;
    // 801DCAA4: bl      0x801DD6CC
    {
            ctx->lr = 0x801DCAA8u;
            goto label_801DD6CC;
    }

label_801DCAA8:
    ctx->pc = 0x801DCAA8u;
    ctx->downcount -= 5;
    // 801DCAA8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCAAC:
    ctx->pc = 0x801DCAACu;
    // 801DCAAC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCAB0:
    ctx->pc = 0x801DCAB0u;
    // 801DCAB0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCAB4:
    ctx->pc = 0x801DCAB4u;
    // 801DCAB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCAB8:
    ctx->pc = 0x801DCAB8u;
    ctx->downcount -= 5;
    // 801DCAB8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCABC:
    ctx->pc = 0x801DCABCu;
    // 801DCABC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCAC0:
    ctx->pc = 0x801DCAC0u;
    // 801DCAC0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCAC4:
    ctx->pc = 0x801DCAC4u;
    // 801DCAC4: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCAC8:
    ctx->pc = 0x801DCAC8u;
    // 801DCAC8: bl      0x801DD718
    {
            ctx->lr = 0x801DCACCu;
            goto label_801DD718;
    }

label_801DCACC:
    ctx->pc = 0x801DCACCu;
    ctx->downcount -= 5;
    // 801DCACC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCAD0:
    ctx->pc = 0x801DCAD0u;
    // 801DCAD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCAD4:
    ctx->pc = 0x801DCAD4u;
    // 801DCAD4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCAD8:
    ctx->pc = 0x801DCAD8u;
    // 801DCAD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCADC:
    ctx->pc = 0x801DCADCu;
    ctx->downcount -= 5;
    // 801DCADC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCAE0:
    ctx->pc = 0x801DCAE0u;
    // 801DCAE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCAE4:
    ctx->pc = 0x801DCAE4u;
    // 801DCAE4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCAE8:
    ctx->pc = 0x801DCAE8u;
    // 801DCAE8: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCAEC:
    ctx->pc = 0x801DCAECu;
    // 801DCAEC: bl      0x801DD764
    {
            ctx->lr = 0x801DCAF0u;
            goto label_801DD764;
    }

label_801DCAF0:
    ctx->pc = 0x801DCAF0u;
    ctx->downcount -= 5;
    // 801DCAF0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCAF4:
    ctx->pc = 0x801DCAF4u;
    // 801DCAF4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCAF8:
    ctx->pc = 0x801DCAF8u;
    // 801DCAF8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCAFC:
    ctx->pc = 0x801DCAFCu;
    // 801DCAFC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCB00:
    ctx->pc = 0x801DCB00u;
    ctx->downcount -= 5;
    // 801DCB00: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCB04:
    ctx->pc = 0x801DCB04u;
    // 801DCB04: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCB08:
    ctx->pc = 0x801DCB08u;
    // 801DCB08: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCB0C:
    ctx->pc = 0x801DCB0Cu;
    // 801DCB0C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCB10:
    ctx->pc = 0x801DCB10u;
    // 801DCB10: bl      0x801DD7B0
    {
            ctx->lr = 0x801DCB14u;
            goto label_801DD7B0;
    }

label_801DCB14:
    ctx->pc = 0x801DCB14u;
    ctx->downcount -= 5;
    // 801DCB14: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCB18:
    ctx->pc = 0x801DCB18u;
    // 801DCB18: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCB1C:
    ctx->pc = 0x801DCB1Cu;
    // 801DCB1C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCB20:
    ctx->pc = 0x801DCB20u;
    // 801DCB20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCB24:
    ctx->pc = 0x801DCB24u;
    ctx->downcount -= 5;
    // 801DCB24: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCB28:
    ctx->pc = 0x801DCB28u;
    // 801DCB28: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCB2C:
    ctx->pc = 0x801DCB2Cu;
    // 801DCB2C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCB30:
    ctx->pc = 0x801DCB30u;
    // 801DCB30: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCB34:
    ctx->pc = 0x801DCB34u;
    // 801DCB34: bl      0x801DD7FC
    {
            ctx->lr = 0x801DCB38u;
            goto label_801DD7FC;
    }

label_801DCB38:
    ctx->pc = 0x801DCB38u;
    ctx->downcount -= 5;
    // 801DCB38: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCB3C:
    ctx->pc = 0x801DCB3Cu;
    // 801DCB3C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCB40:
    ctx->pc = 0x801DCB40u;
    // 801DCB40: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCB44:
    ctx->pc = 0x801DCB44u;
    // 801DCB44: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCB48:
    ctx->pc = 0x801DCB48u;
    ctx->downcount -= 5;
    // 801DCB48: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCB4C:
    ctx->pc = 0x801DCB4Cu;
    // 801DCB4C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCB50:
    ctx->pc = 0x801DCB50u;
    // 801DCB50: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCB54:
    ctx->pc = 0x801DCB54u;
    // 801DCB54: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCB58:
    ctx->pc = 0x801DCB58u;
    // 801DCB58: bl      0x801DD848
    {
            ctx->lr = 0x801DCB5Cu;
            goto label_801DD848;
    }

label_801DCB5C:
    ctx->pc = 0x801DCB5Cu;
    ctx->downcount -= 5;
    // 801DCB5C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCB60:
    ctx->pc = 0x801DCB60u;
    // 801DCB60: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCB64:
    ctx->pc = 0x801DCB64u;
    // 801DCB64: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCB68:
    ctx->pc = 0x801DCB68u;
    // 801DCB68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCB6C:
    ctx->pc = 0x801DCB6Cu;
    ctx->downcount -= 5;
    // 801DCB6C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCB70:
    ctx->pc = 0x801DCB70u;
    // 801DCB70: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCB74:
    ctx->pc = 0x801DCB74u;
    // 801DCB74: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCB78:
    ctx->pc = 0x801DCB78u;
    // 801DCB78: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCB7C:
    ctx->pc = 0x801DCB7Cu;
    // 801DCB7C: bl      0x801DD894
    {
            ctx->lr = 0x801DCB80u;
            goto label_801DD894;
    }

label_801DCB80:
    ctx->pc = 0x801DCB80u;
    ctx->downcount -= 5;
    // 801DCB80: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCB84:
    ctx->pc = 0x801DCB84u;
    // 801DCB84: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCB88:
    ctx->pc = 0x801DCB88u;
    // 801DCB88: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCB8C:
    ctx->pc = 0x801DCB8Cu;
    // 801DCB8C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCB90:
    ctx->pc = 0x801DCB90u;
    ctx->downcount -= 5;
    // 801DCB90: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCB94:
    ctx->pc = 0x801DCB94u;
    // 801DCB94: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCB98:
    ctx->pc = 0x801DCB98u;
    // 801DCB98: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCB9C:
    ctx->pc = 0x801DCB9Cu;
    // 801DCB9C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCBA0:
    ctx->pc = 0x801DCBA0u;
    // 801DCBA0: bl      0x801DD8E0
    {
            ctx->lr = 0x801DCBA4u;
            goto label_801DD8E0;
    }

label_801DCBA4:
    ctx->pc = 0x801DCBA4u;
    ctx->downcount -= 5;
    // 801DCBA4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCBA8:
    ctx->pc = 0x801DCBA8u;
    // 801DCBA8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCBAC:
    ctx->pc = 0x801DCBACu;
    // 801DCBAC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCBB0:
    ctx->pc = 0x801DCBB0u;
    // 801DCBB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCBB4:
    ctx->pc = 0x801DCBB4u;
    ctx->downcount -= 5;
    // 801DCBB4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCBB8:
    ctx->pc = 0x801DCBB8u;
    // 801DCBB8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCBBC:
    ctx->pc = 0x801DCBBCu;
    // 801DCBBC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCBC0:
    ctx->pc = 0x801DCBC0u;
    // 801DCBC0: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCBC4:
    ctx->pc = 0x801DCBC4u;
    // 801DCBC4: bl      0x801DD950
    {
            ctx->lr = 0x801DCBC8u;
            goto label_801DD950;
    }

label_801DCBC8:
    ctx->pc = 0x801DCBC8u;
    ctx->downcount -= 5;
    // 801DCBC8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCBCC:
    ctx->pc = 0x801DCBCCu;
    // 801DCBCC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCBD0:
    ctx->pc = 0x801DCBD0u;
    // 801DCBD0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCBD4:
    ctx->pc = 0x801DCBD4u;
    // 801DCBD4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCBD8:
    ctx->pc = 0x801DCBD8u;
    ctx->downcount -= 5;
    // 801DCBD8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCBDC:
    ctx->pc = 0x801DCBDCu;
    // 801DCBDC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCBE0:
    ctx->pc = 0x801DCBE0u;
    // 801DCBE0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCBE4:
    ctx->pc = 0x801DCBE4u;
    // 801DCBE4: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCBE8:
    ctx->pc = 0x801DCBE8u;
    // 801DCBE8: bl      0x801DD99C
    {
            ctx->lr = 0x801DCBECu;
            goto label_801DD99C;
    }

label_801DCBEC:
    ctx->pc = 0x801DCBECu;
    ctx->downcount -= 5;
    // 801DCBEC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCBF0:
    ctx->pc = 0x801DCBF0u;
    // 801DCBF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCBF4:
    ctx->pc = 0x801DCBF4u;
    // 801DCBF4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCBF8:
    ctx->pc = 0x801DCBF8u;
    // 801DCBF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCBFC:
    ctx->pc = 0x801DCBFCu;
    ctx->downcount -= 5;
    // 801DCBFC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCC00:
    ctx->pc = 0x801DCC00u;
    // 801DCC00: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCC04:
    ctx->pc = 0x801DCC04u;
    // 801DCC04: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCC08:
    ctx->pc = 0x801DCC08u;
    // 801DCC08: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCC0C:
    ctx->pc = 0x801DCC0Cu;
    // 801DCC0C: bl      0x801DDA18
    {
            ctx->lr = 0x801DCC10u;
            goto label_801DDA18;
    }

label_801DCC10:
    ctx->pc = 0x801DCC10u;
    ctx->downcount -= 5;
    // 801DCC10: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCC14:
    ctx->pc = 0x801DCC14u;
    // 801DCC14: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCC18:
    ctx->pc = 0x801DCC18u;
    // 801DCC18: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCC1C:
    ctx->pc = 0x801DCC1Cu;
    // 801DCC1C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCC20:
    ctx->pc = 0x801DCC20u;
    ctx->downcount -= 5;
    // 801DCC20: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCC24:
    ctx->pc = 0x801DCC24u;
    // 801DCC24: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCC28:
    ctx->pc = 0x801DCC28u;
    // 801DCC28: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCC2C:
    ctx->pc = 0x801DCC2Cu;
    // 801DCC2C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCC30:
    ctx->pc = 0x801DCC30u;
    // 801DCC30: bl      0x801DDA8C
    {
            ctx->lr = 0x801DCC34u;
            goto label_801DDA8C;
    }

label_801DCC34:
    ctx->pc = 0x801DCC34u;
    ctx->downcount -= 5;
    // 801DCC34: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCC38:
    ctx->pc = 0x801DCC38u;
    // 801DCC38: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCC3C:
    ctx->pc = 0x801DCC3Cu;
    // 801DCC3C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCC40:
    ctx->pc = 0x801DCC40u;
    // 801DCC40: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCC44:
    ctx->pc = 0x801DCC44u;
    ctx->downcount -= 5;
    // 801DCC44: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCC48:
    ctx->pc = 0x801DCC48u;
    // 801DCC48: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCC4C:
    ctx->pc = 0x801DCC4Cu;
    // 801DCC4C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCC50:
    ctx->pc = 0x801DCC50u;
    // 801DCC50: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCC54:
    ctx->pc = 0x801DCC54u;
    // 801DCC54: bl      0x801DDAF4
    {
            ctx->lr = 0x801DCC58u;
            goto label_801DDAF4;
    }

label_801DCC58:
    ctx->pc = 0x801DCC58u;
    ctx->downcount -= 5;
    // 801DCC58: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCC5C:
    ctx->pc = 0x801DCC5Cu;
    // 801DCC5C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCC60:
    ctx->pc = 0x801DCC60u;
    // 801DCC60: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCC64:
    ctx->pc = 0x801DCC64u;
    // 801DCC64: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCC68:
    ctx->pc = 0x801DCC68u;
    ctx->downcount -= 5;
    // 801DCC68: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCC6C:
    ctx->pc = 0x801DCC6Cu;
    // 801DCC6C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCC70:
    ctx->pc = 0x801DCC70u;
    // 801DCC70: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCC74:
    ctx->pc = 0x801DCC74u;
    // 801DCC74: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCC78:
    ctx->pc = 0x801DCC78u;
    // 801DCC78: bl      0x801DDB64
    {
            ctx->lr = 0x801DCC7Cu;
            goto label_801DDB64;
    }

label_801DCC7C:
    ctx->pc = 0x801DCC7Cu;
    ctx->downcount -= 5;
    // 801DCC7C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCC80:
    ctx->pc = 0x801DCC80u;
    // 801DCC80: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCC84:
    ctx->pc = 0x801DCC84u;
    // 801DCC84: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCC88:
    ctx->pc = 0x801DCC88u;
    // 801DCC88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCC8C:
    ctx->pc = 0x801DCC8Cu;
    ctx->downcount -= 5;
    // 801DCC8C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCC90:
    ctx->pc = 0x801DCC90u;
    // 801DCC90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCC94:
    ctx->pc = 0x801DCC94u;
    // 801DCC94: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCC98:
    ctx->pc = 0x801DCC98u;
    // 801DCC98: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCC9C:
    ctx->pc = 0x801DCC9Cu;
    // 801DCC9C: bl      0x801DDBCC
    {
            ctx->lr = 0x801DCCA0u;
            goto label_801DDBCC;
    }

label_801DCCA0:
    ctx->pc = 0x801DCCA0u;
    ctx->downcount -= 5;
    // 801DCCA0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCCA4:
    ctx->pc = 0x801DCCA4u;
    // 801DCCA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCCA8:
    ctx->pc = 0x801DCCA8u;
    // 801DCCA8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCCAC:
    ctx->pc = 0x801DCCACu;
    // 801DCCAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCCB0:
    ctx->pc = 0x801DCCB0u;
    ctx->downcount -= 5;
    // 801DCCB0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCCB4:
    ctx->pc = 0x801DCCB4u;
    // 801DCCB4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCCB8:
    ctx->pc = 0x801DCCB8u;
    // 801DCCB8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCCBC:
    ctx->pc = 0x801DCCBCu;
    // 801DCCBC: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCCC0:
    ctx->pc = 0x801DCCC0u;
    // 801DCCC0: bl      0x801DDC18
    {
            ctx->lr = 0x801DCCC4u;
            goto label_801DDC18;
    }

label_801DCCC4:
    ctx->pc = 0x801DCCC4u;
    ctx->downcount -= 5;
    // 801DCCC4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCCC8:
    ctx->pc = 0x801DCCC8u;
    // 801DCCC8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCCCC:
    ctx->pc = 0x801DCCCCu;
    // 801DCCCC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCCD0:
    ctx->pc = 0x801DCCD0u;
    // 801DCCD0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCCD4:
    ctx->pc = 0x801DCCD4u;
    ctx->downcount -= 5;
    // 801DCCD4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCCD8:
    ctx->pc = 0x801DCCD8u;
    // 801DCCD8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCCDC:
    ctx->pc = 0x801DCCDCu;
    // 801DCCDC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCCE0:
    ctx->pc = 0x801DCCE0u;
    // 801DCCE0: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCCE4:
    ctx->pc = 0x801DCCE4u;
    // 801DCCE4: bl      0x801DDC64
    {
            ctx->lr = 0x801DCCE8u;
            goto label_801DDC64;
    }

label_801DCCE8:
    ctx->pc = 0x801DCCE8u;
    ctx->downcount -= 5;
    // 801DCCE8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCCEC:
    ctx->pc = 0x801DCCECu;
    // 801DCCEC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCCF0:
    ctx->pc = 0x801DCCF0u;
    // 801DCCF0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCCF4:
    ctx->pc = 0x801DCCF4u;
    // 801DCCF4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCCF8:
    ctx->pc = 0x801DCCF8u;
    ctx->downcount -= 5;
    // 801DCCF8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCCFC:
    ctx->pc = 0x801DCCFCu;
    // 801DCCFC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCD00:
    ctx->pc = 0x801DCD00u;
    // 801DCD00: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCD04:
    ctx->pc = 0x801DCD04u;
    // 801DCD04: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCD08:
    ctx->pc = 0x801DCD08u;
    // 801DCD08: bl      0x801DDCF4
    {
            ctx->lr = 0x801DCD0Cu;
            goto label_801DDCF4;
    }

label_801DCD0C:
    ctx->pc = 0x801DCD0Cu;
    ctx->downcount -= 5;
    // 801DCD0C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCD10:
    ctx->pc = 0x801DCD10u;
    // 801DCD10: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCD14:
    ctx->pc = 0x801DCD14u;
    // 801DCD14: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCD18:
    ctx->pc = 0x801DCD18u;
    // 801DCD18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCD1C:
    ctx->pc = 0x801DCD1Cu;
    ctx->downcount -= 5;
    // 801DCD1C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCD20:
    ctx->pc = 0x801DCD20u;
    // 801DCD20: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCD24:
    ctx->pc = 0x801DCD24u;
    // 801DCD24: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCD28:
    ctx->pc = 0x801DCD28u;
    // 801DCD28: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCD2C:
    ctx->pc = 0x801DCD2Cu;
    // 801DCD2C: bl      0x801DDD5C
    {
            ctx->lr = 0x801DCD30u;
            goto label_801DDD5C;
    }

label_801DCD30:
    ctx->pc = 0x801DCD30u;
    ctx->downcount -= 5;
    // 801DCD30: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCD34:
    ctx->pc = 0x801DCD34u;
    // 801DCD34: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCD38:
    ctx->pc = 0x801DCD38u;
    // 801DCD38: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCD3C:
    ctx->pc = 0x801DCD3Cu;
    // 801DCD3C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCD40:
    ctx->pc = 0x801DCD40u;
    ctx->downcount -= 5;
    // 801DCD40: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCD44:
    ctx->pc = 0x801DCD44u;
    // 801DCD44: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCD48:
    ctx->pc = 0x801DCD48u;
    // 801DCD48: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCD4C:
    ctx->pc = 0x801DCD4Cu;
    // 801DCD4C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCD50:
    ctx->pc = 0x801DCD50u;
    // 801DCD50: bl      0x801DDDC4
    {
            ctx->lr = 0x801DCD54u;
            goto label_801DDDC4;
    }

label_801DCD54:
    ctx->pc = 0x801DCD54u;
    ctx->downcount -= 5;
    // 801DCD54: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCD58:
    ctx->pc = 0x801DCD58u;
    // 801DCD58: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCD5C:
    ctx->pc = 0x801DCD5Cu;
    // 801DCD5C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCD60:
    ctx->pc = 0x801DCD60u;
    // 801DCD60: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCD64:
    ctx->pc = 0x801DCD64u;
    ctx->downcount -= 5;
    // 801DCD64: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCD68:
    ctx->pc = 0x801DCD68u;
    // 801DCD68: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCD6C:
    ctx->pc = 0x801DCD6Cu;
    // 801DCD6C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCD70:
    ctx->pc = 0x801DCD70u;
    // 801DCD70: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCD74:
    ctx->pc = 0x801DCD74u;
    // 801DCD74: bl      0x801DDE10
    {
            ctx->lr = 0x801DCD78u;
            goto label_801DDE10;
    }

label_801DCD78:
    ctx->pc = 0x801DCD78u;
    ctx->downcount -= 5;
    // 801DCD78: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCD7C:
    ctx->pc = 0x801DCD7Cu;
    // 801DCD7C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCD80:
    ctx->pc = 0x801DCD80u;
    // 801DCD80: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCD84:
    ctx->pc = 0x801DCD84u;
    // 801DCD84: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCD88:
    ctx->pc = 0x801DCD88u;
    ctx->downcount -= 5;
    // 801DCD88: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCD8C:
    ctx->pc = 0x801DCD8Cu;
    // 801DCD8C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCD90:
    ctx->pc = 0x801DCD90u;
    // 801DCD90: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCD94:
    ctx->pc = 0x801DCD94u;
    // 801DCD94: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCD98:
    ctx->pc = 0x801DCD98u;
    // 801DCD98: bl      0x801DDE78
    {
            ctx->lr = 0x801DCD9Cu;
            goto label_801DDE78;
    }

label_801DCD9C:
    ctx->pc = 0x801DCD9Cu;
    ctx->downcount -= 5;
    // 801DCD9C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCDA0:
    ctx->pc = 0x801DCDA0u;
    // 801DCDA0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCDA4:
    ctx->pc = 0x801DCDA4u;
    // 801DCDA4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCDA8:
    ctx->pc = 0x801DCDA8u;
    // 801DCDA8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCDAC:
    ctx->pc = 0x801DCDACu;
    ctx->downcount -= 5;
    // 801DCDAC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCDB0:
    ctx->pc = 0x801DCDB0u;
    // 801DCDB0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCDB4:
    ctx->pc = 0x801DCDB4u;
    // 801DCDB4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCDB8:
    ctx->pc = 0x801DCDB8u;
    // 801DCDB8: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DCDBC:
    ctx->pc = 0x801DCDBCu;
    // 801DCDBC: bl      0x801DDEC4
    {
            ctx->lr = 0x801DCDC0u;
            goto label_801DDEC4;
    }

label_801DCDC0:
    ctx->pc = 0x801DCDC0u;
    ctx->downcount -= 5;
    // 801DCDC0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCDC4:
    ctx->pc = 0x801DCDC4u;
    // 801DCDC4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCDC8:
    ctx->pc = 0x801DCDC8u;
    // 801DCDC8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCDCC:
    ctx->pc = 0x801DCDCCu;
    // 801DCDCC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCDD0:
    ctx->pc = 0x801DCDD0u;
    ctx->downcount -= 11;
    // 801DCDD0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCDD4:
    ctx->pc = 0x801DCDD4u;
    // 801DCDD4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCDD8:
    ctx->pc = 0x801DCDD8u;
    // 801DCDD8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCDDC:
    ctx->pc = 0x801DCDDCu;
    // 801DCDDC: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCDE0:
    ctx->pc = 0x801DCDE0u;
    // 801DCDE0: li      r4, 92
    ctx->gpr[4] = (u32)(s32)(92);

label_801DCDE4:
    ctx->pc = 0x801DCDE4u;
    // 801DCDE4: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DCDE8:
    ctx->pc = 0x801DCDE8u;
    // 801DCDE8: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCDEC:
    ctx->pc = 0x801DCDECu;
    // 801DCDEC: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DCDF0:
    ctx->pc = 0x801DCDF0u;
    // 801DCDF0: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DCDF4:
    ctx->pc = 0x801DCDF4u;
    // 801DCDF4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DCDF8u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCDF8:
    ctx->pc = 0x801DCDF8u;
    ctx->downcount -= 2;
    // 801DCDF8: or.   r3, r3, r3
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

label_801DCDFC:
    ctx->pc = 0x801DCDFCu;
    // 801DCDFC: bc    12, 2, 0x801DCE08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DCE08;
        }
    }

label_801DCE00:
    ctx->pc = 0x801DCE00u;
    ctx->downcount -= 1;
    // 801DCE00: bl      0x8022A728
    {
            ctx->lr = 0x801DCE04u;
            ctx->pc = 0x8022A728u;
            return;
    }

label_801DCE04:
    ctx->pc = 0x801DCE04u;
    ctx->downcount -= 1;
    // 801DCE04: b       0x801DCE0C
    {
            goto label_801DCE0C;
    }

label_801DCE08:
    ctx->pc = 0x801DCE08u;
    ctx->downcount -= 1;
    // 801DCE08: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DCE0C:
    ctx->pc = 0x801DCE0Cu;
    ctx->downcount -= 5;
    // 801DCE0C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCE10:
    ctx->pc = 0x801DCE10u;
    // 801DCE10: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCE14:
    ctx->pc = 0x801DCE14u;
    // 801DCE14: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCE18:
    ctx->pc = 0x801DCE18u;
    // 801DCE18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCE1C:
    ctx->pc = 0x801DCE1Cu;
    ctx->downcount -= 11;
    // 801DCE1C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCE20:
    ctx->pc = 0x801DCE20u;
    // 801DCE20: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCE24:
    ctx->pc = 0x801DCE24u;
    // 801DCE24: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCE28:
    ctx->pc = 0x801DCE28u;
    // 801DCE28: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCE2C:
    ctx->pc = 0x801DCE2Cu;
    // 801DCE2C: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_801DCE30:
    ctx->pc = 0x801DCE30u;
    // 801DCE30: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DCE34:
    ctx->pc = 0x801DCE34u;
    // 801DCE34: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCE38:
    ctx->pc = 0x801DCE38u;
    // 801DCE38: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DCE3C:
    ctx->pc = 0x801DCE3Cu;
    // 801DCE3C: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DCE40:
    ctx->pc = 0x801DCE40u;
    // 801DCE40: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DCE44u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCE44:
    ctx->pc = 0x801DCE44u;
    ctx->downcount -= 2;
    // 801DCE44: or.   r3, r3, r3
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

label_801DCE48:
    ctx->pc = 0x801DCE48u;
    // 801DCE48: bc    12, 2, 0x801DCE54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DCE54;
        }
    }

label_801DCE4C:
    ctx->pc = 0x801DCE4Cu;
    ctx->downcount -= 1;
    // 801DCE4C: bl      0x801F48C8
    {
            ctx->lr = 0x801DCE50u;
            ctx->pc = 0x801F48C8u;
            return;
    }

label_801DCE50:
    ctx->pc = 0x801DCE50u;
    ctx->downcount -= 1;
    // 801DCE50: b       0x801DCE58
    {
            goto label_801DCE58;
    }

label_801DCE54:
    ctx->pc = 0x801DCE54u;
    ctx->downcount -= 1;
    // 801DCE54: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DCE58:
    ctx->pc = 0x801DCE58u;
    ctx->downcount -= 5;
    // 801DCE58: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCE5C:
    ctx->pc = 0x801DCE5Cu;
    // 801DCE5C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCE60:
    ctx->pc = 0x801DCE60u;
    // 801DCE60: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCE64:
    ctx->pc = 0x801DCE64u;
    // 801DCE64: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCE68:
    ctx->pc = 0x801DCE68u;
    ctx->downcount -= 11;
    // 801DCE68: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCE6C:
    ctx->pc = 0x801DCE6Cu;
    // 801DCE6C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCE70:
    ctx->pc = 0x801DCE70u;
    // 801DCE70: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCE74:
    ctx->pc = 0x801DCE74u;
    // 801DCE74: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCE78:
    ctx->pc = 0x801DCE78u;
    // 801DCE78: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DCE7C:
    ctx->pc = 0x801DCE7Cu;
    // 801DCE7C: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DCE80:
    ctx->pc = 0x801DCE80u;
    // 801DCE80: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCE84:
    ctx->pc = 0x801DCE84u;
    // 801DCE84: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DCE88:
    ctx->pc = 0x801DCE88u;
    // 801DCE88: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DCE8C:
    ctx->pc = 0x801DCE8Cu;
    // 801DCE8C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DCE90u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCE90:
    ctx->pc = 0x801DCE90u;
    ctx->downcount -= 2;
    // 801DCE90: or.   r3, r3, r3
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

label_801DCE94:
    ctx->pc = 0x801DCE94u;
    // 801DCE94: bc    12, 2, 0x801DCEA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DCEA0;
        }
    }

label_801DCE98:
    ctx->pc = 0x801DCE98u;
    ctx->downcount -= 1;
    // 801DCE98: bl      0x801F3684
    {
            ctx->lr = 0x801DCE9Cu;
            ctx->pc = 0x801F3684u;
            return;
    }

label_801DCE9C:
    ctx->pc = 0x801DCE9Cu;
    ctx->downcount -= 1;
    // 801DCE9C: b       0x801DCEA4
    {
            goto label_801DCEA4;
    }

label_801DCEA0:
    ctx->pc = 0x801DCEA0u;
    ctx->downcount -= 1;
    // 801DCEA0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DCEA4:
    ctx->pc = 0x801DCEA4u;
    ctx->downcount -= 5;
    // 801DCEA4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCEA8:
    ctx->pc = 0x801DCEA8u;
    // 801DCEA8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCEAC:
    ctx->pc = 0x801DCEACu;
    // 801DCEAC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCEB0:
    ctx->pc = 0x801DCEB0u;
    // 801DCEB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCEB4:
    ctx->pc = 0x801DCEB4u;
    ctx->downcount -= 12;
    // 801DCEB4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCEB8:
    ctx->pc = 0x801DCEB8u;
    // 801DCEB8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCEBC:
    ctx->pc = 0x801DCEBCu;
    // 801DCEBC: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DCEC0:
    ctx->pc = 0x801DCEC0u;
    // 801DCEC0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCEC4:
    ctx->pc = 0x801DCEC4u;
    // 801DCEC4: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCEC8:
    ctx->pc = 0x801DCEC8u;
    // 801DCEC8: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_801DCECC:
    ctx->pc = 0x801DCECCu;
    // 801DCECC: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DCED0:
    ctx->pc = 0x801DCED0u;
    // 801DCED0: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCED4:
    ctx->pc = 0x801DCED4u;
    // 801DCED4: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DCED8:
    ctx->pc = 0x801DCED8u;
    // 801DCED8: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DCEDC:
    ctx->pc = 0x801DCEDCu;
    // 801DCEDC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DCEE0u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCEE0:
    ctx->pc = 0x801DCEE0u;
    ctx->downcount -= 2;
    // 801DCEE0: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DCEE4:
    ctx->pc = 0x801DCEE4u;
    // 801DCEE4: bc    12, 2, 0x801DCF04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DCF04;
        }
    }

label_801DCEE8:
    ctx->pc = 0x801DCEE8u;
    ctx->downcount -= 2;
    // 801DCEE8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DCEEC:
    ctx->pc = 0x801DCEECu;
    // 801DCEEC: bl      0x801E7708
    {
            ctx->lr = 0x801DCEF0u;
            ctx->pc = 0x801E7708u;
            return;
    }

label_801DCEF0:
    ctx->pc = 0x801DCEF0u;
    ctx->downcount -= 5;
    // 801DCEF0: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DCEF4:
    ctx->pc = 0x801DCEF4u;
    // 801DCEF4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DCEF8:
    ctx->pc = 0x801DCEF8u;
    // 801DCEF8: addi    r9, r9, 18040
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18040);

label_801DCEFC:
    ctx->pc = 0x801DCEFCu;
    // 801DCEFC: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DCF00:
    ctx->pc = 0x801DCF00u;
    // 801DCF00: b       0x801DCF08
    {
            goto label_801DCF08;
    }

label_801DCF04:
    ctx->pc = 0x801DCF04u;
    ctx->downcount -= 1;
    // 801DCF04: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DCF08:
    ctx->pc = 0x801DCF08u;
    ctx->downcount -= 6;
    // 801DCF08: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCF0C:
    ctx->pc = 0x801DCF0Cu;
    // 801DCF0C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCF10:
    ctx->pc = 0x801DCF10u;
    // 801DCF10: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DCF14:
    ctx->pc = 0x801DCF14u;
    // 801DCF14: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DCF18:
    ctx->pc = 0x801DCF18u;
    // 801DCF18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCF1C:
    ctx->pc = 0x801DCF1Cu;
    ctx->downcount -= 12;
    // 801DCF1C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCF20:
    ctx->pc = 0x801DCF20u;
    // 801DCF20: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCF24:
    ctx->pc = 0x801DCF24u;
    // 801DCF24: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DCF28:
    ctx->pc = 0x801DCF28u;
    // 801DCF28: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCF2C:
    ctx->pc = 0x801DCF2Cu;
    // 801DCF2C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCF30:
    ctx->pc = 0x801DCF30u;
    // 801DCF30: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_801DCF34:
    ctx->pc = 0x801DCF34u;
    // 801DCF34: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DCF38:
    ctx->pc = 0x801DCF38u;
    // 801DCF38: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCF3C:
    ctx->pc = 0x801DCF3Cu;
    // 801DCF3C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DCF40:
    ctx->pc = 0x801DCF40u;
    // 801DCF40: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DCF44:
    ctx->pc = 0x801DCF44u;
    // 801DCF44: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DCF48u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCF48:
    ctx->pc = 0x801DCF48u;
    ctx->downcount -= 2;
    // 801DCF48: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DCF4C:
    ctx->pc = 0x801DCF4Cu;
    // 801DCF4C: bc    12, 2, 0x801DCF6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DCF6C;
        }
    }

label_801DCF50:
    ctx->pc = 0x801DCF50u;
    ctx->downcount -= 2;
    // 801DCF50: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DCF54:
    ctx->pc = 0x801DCF54u;
    // 801DCF54: bl      0x801E7708
    {
            ctx->lr = 0x801DCF58u;
            ctx->pc = 0x801E7708u;
            return;
    }

label_801DCF58:
    ctx->pc = 0x801DCF58u;
    ctx->downcount -= 5;
    // 801DCF58: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DCF5C:
    ctx->pc = 0x801DCF5Cu;
    // 801DCF5C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DCF60:
    ctx->pc = 0x801DCF60u;
    // 801DCF60: addi    r9, r9, 16280
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16280);

label_801DCF64:
    ctx->pc = 0x801DCF64u;
    // 801DCF64: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DCF68:
    ctx->pc = 0x801DCF68u;
    // 801DCF68: b       0x801DCF70
    {
            goto label_801DCF70;
    }

label_801DCF6C:
    ctx->pc = 0x801DCF6Cu;
    ctx->downcount -= 1;
    // 801DCF6C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DCF70:
    ctx->pc = 0x801DCF70u;
    ctx->downcount -= 6;
    // 801DCF70: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCF74:
    ctx->pc = 0x801DCF74u;
    // 801DCF74: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCF78:
    ctx->pc = 0x801DCF78u;
    // 801DCF78: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DCF7C:
    ctx->pc = 0x801DCF7Cu;
    // 801DCF7C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DCF80:
    ctx->pc = 0x801DCF80u;
    // 801DCF80: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCF84:
    ctx->pc = 0x801DCF84u;
    ctx->downcount -= 11;
    // 801DCF84: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCF88:
    ctx->pc = 0x801DCF88u;
    // 801DCF88: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCF8C:
    ctx->pc = 0x801DCF8Cu;
    // 801DCF8C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCF90:
    ctx->pc = 0x801DCF90u;
    // 801DCF90: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCF94:
    ctx->pc = 0x801DCF94u;
    // 801DCF94: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_801DCF98:
    ctx->pc = 0x801DCF98u;
    // 801DCF98: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DCF9C:
    ctx->pc = 0x801DCF9Cu;
    // 801DCF9C: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCFA0:
    ctx->pc = 0x801DCFA0u;
    // 801DCFA0: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DCFA4:
    ctx->pc = 0x801DCFA4u;
    // 801DCFA4: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DCFA8:
    ctx->pc = 0x801DCFA8u;
    // 801DCFA8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DCFACu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCFAC:
    ctx->pc = 0x801DCFACu;
    ctx->downcount -= 2;
    // 801DCFAC: or.   r3, r3, r3
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

label_801DCFB0:
    ctx->pc = 0x801DCFB0u;
    // 801DCFB0: bc    12, 2, 0x801DCFBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DCFBC;
        }
    }

label_801DCFB4:
    ctx->pc = 0x801DCFB4u;
    ctx->downcount -= 1;
    // 801DCFB4: bl      0x8022D7C8
    {
            ctx->lr = 0x801DCFB8u;
            ctx->pc = 0x8022D7C8u;
            return;
    }

label_801DCFB8:
    ctx->pc = 0x801DCFB8u;
    ctx->downcount -= 1;
    // 801DCFB8: b       0x801DCFC0
    {
            goto label_801DCFC0;
    }

label_801DCFBC:
    ctx->pc = 0x801DCFBCu;
    ctx->downcount -= 1;
    // 801DCFBC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DCFC0:
    ctx->pc = 0x801DCFC0u;
    ctx->downcount -= 5;
    // 801DCFC0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DCFC4:
    ctx->pc = 0x801DCFC4u;
    // 801DCFC4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DCFC8:
    ctx->pc = 0x801DCFC8u;
    // 801DCFC8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DCFCC:
    ctx->pc = 0x801DCFCCu;
    // 801DCFCC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCFD0:
    ctx->pc = 0x801DCFD0u;
    ctx->downcount -= 11;
    // 801DCFD0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DCFD4:
    ctx->pc = 0x801DCFD4u;
    // 801DCFD4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DCFD8:
    ctx->pc = 0x801DCFD8u;
    // 801DCFD8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DCFDC:
    ctx->pc = 0x801DCFDCu;
    // 801DCFDC: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCFE0:
    ctx->pc = 0x801DCFE0u;
    // 801DCFE0: li      r4, 88
    ctx->gpr[4] = (u32)(s32)(88);

label_801DCFE4:
    ctx->pc = 0x801DCFE4u;
    // 801DCFE4: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DCFE8:
    ctx->pc = 0x801DCFE8u;
    // 801DCFE8: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DCFEC:
    ctx->pc = 0x801DCFECu;
    // 801DCFEC: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DCFF0:
    ctx->pc = 0x801DCFF0u;
    // 801DCFF0: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DCFF4:
    ctx->pc = 0x801DCFF4u;
    // 801DCFF4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DCFF8u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DCFF8:
    ctx->pc = 0x801DCFF8u;
    ctx->downcount -= 2;
    // 801DCFF8: or.   r3, r3, r3
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

label_801DCFFC:
    ctx->pc = 0x801DCFFCu;
    // 801DCFFC: bc    12, 2, 0x801DD008
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD008;
        }
    }

label_801DD000:
    ctx->pc = 0x801DD000u;
    ctx->downcount -= 1;
    // 801DD000: bl      0x8022D184
    {
            ctx->lr = 0x801DD004u;
            ctx->pc = 0x8022D184u;
            return;
    }

label_801DD004:
    ctx->pc = 0x801DD004u;
    ctx->downcount -= 1;
    // 801DD004: b       0x801DD00C
    {
            goto label_801DD00C;
    }

label_801DD008:
    ctx->pc = 0x801DD008u;
    ctx->downcount -= 1;
    // 801DD008: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD00C:
    ctx->pc = 0x801DD00Cu;
    ctx->downcount -= 5;
    // 801DD00C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD010:
    ctx->pc = 0x801DD010u;
    // 801DD010: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD014:
    ctx->pc = 0x801DD014u;
    // 801DD014: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD018:
    ctx->pc = 0x801DD018u;
    // 801DD018: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD01C:
    ctx->pc = 0x801DD01Cu;
    ctx->downcount -= 11;
    // 801DD01C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD020:
    ctx->pc = 0x801DD020u;
    // 801DD020: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD024:
    ctx->pc = 0x801DD024u;
    // 801DD024: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD028:
    ctx->pc = 0x801DD028u;
    // 801DD028: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD02C:
    ctx->pc = 0x801DD02Cu;
    // 801DD02C: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_801DD030:
    ctx->pc = 0x801DD030u;
    // 801DD030: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD034:
    ctx->pc = 0x801DD034u;
    // 801DD034: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD038:
    ctx->pc = 0x801DD038u;
    // 801DD038: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD03C:
    ctx->pc = 0x801DD03Cu;
    // 801DD03C: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD040:
    ctx->pc = 0x801DD040u;
    // 801DD040: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD044u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD044:
    ctx->pc = 0x801DD044u;
    ctx->downcount -= 2;
    // 801DD044: or.   r3, r3, r3
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

label_801DD048:
    ctx->pc = 0x801DD048u;
    // 801DD048: bc    12, 2, 0x801DD054
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD054;
        }
    }

label_801DD04C:
    ctx->pc = 0x801DD04Cu;
    ctx->downcount -= 1;
    // 801DD04C: bl      0x8022D98C
    {
            ctx->lr = 0x801DD050u;
            ctx->pc = 0x8022D98Cu;
            return;
    }

label_801DD050:
    ctx->pc = 0x801DD050u;
    ctx->downcount -= 1;
    // 801DD050: b       0x801DD058
    {
            goto label_801DD058;
    }

label_801DD054:
    ctx->pc = 0x801DD054u;
    ctx->downcount -= 1;
    // 801DD054: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD058:
    ctx->pc = 0x801DD058u;
    ctx->downcount -= 5;
    // 801DD058: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD05C:
    ctx->pc = 0x801DD05Cu;
    // 801DD05C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD060:
    ctx->pc = 0x801DD060u;
    // 801DD060: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD064:
    ctx->pc = 0x801DD064u;
    // 801DD064: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD068:
    ctx->pc = 0x801DD068u;
    ctx->downcount -= 11;
    // 801DD068: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD06C:
    ctx->pc = 0x801DD06Cu;
    // 801DD06C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD070:
    ctx->pc = 0x801DD070u;
    // 801DD070: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD074:
    ctx->pc = 0x801DD074u;
    // 801DD074: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD078:
    ctx->pc = 0x801DD078u;
    // 801DD078: li      r4, 124
    ctx->gpr[4] = (u32)(s32)(124);

label_801DD07C:
    ctx->pc = 0x801DD07Cu;
    // 801DD07C: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD080:
    ctx->pc = 0x801DD080u;
    // 801DD080: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD084:
    ctx->pc = 0x801DD084u;
    // 801DD084: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD088:
    ctx->pc = 0x801DD088u;
    // 801DD088: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD08C:
    ctx->pc = 0x801DD08Cu;
    // 801DD08C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD090u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD090:
    ctx->pc = 0x801DD090u;
    ctx->downcount -= 2;
    // 801DD090: or.   r3, r3, r3
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

label_801DD094:
    ctx->pc = 0x801DD094u;
    // 801DD094: bc    12, 2, 0x801DD0A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD0A0;
        }
    }

label_801DD098:
    ctx->pc = 0x801DD098u;
    ctx->downcount -= 1;
    // 801DD098: bl      0x801F4994
    {
            ctx->lr = 0x801DD09Cu;
            ctx->pc = 0x801F4994u;
            return;
    }

label_801DD09C:
    ctx->pc = 0x801DD09Cu;
    ctx->downcount -= 1;
    // 801DD09C: b       0x801DD0A4
    {
            goto label_801DD0A4;
    }

label_801DD0A0:
    ctx->pc = 0x801DD0A0u;
    ctx->downcount -= 1;
    // 801DD0A0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD0A4:
    ctx->pc = 0x801DD0A4u;
    ctx->downcount -= 5;
    // 801DD0A4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD0A8:
    ctx->pc = 0x801DD0A8u;
    // 801DD0A8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD0AC:
    ctx->pc = 0x801DD0ACu;
    // 801DD0AC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD0B0:
    ctx->pc = 0x801DD0B0u;
    // 801DD0B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD0B4:
    ctx->pc = 0x801DD0B4u;
    ctx->downcount -= 11;
    // 801DD0B4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD0B8:
    ctx->pc = 0x801DD0B8u;
    // 801DD0B8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD0BC:
    ctx->pc = 0x801DD0BCu;
    // 801DD0BC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD0C0:
    ctx->pc = 0x801DD0C0u;
    // 801DD0C0: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD0C4:
    ctx->pc = 0x801DD0C4u;
    // 801DD0C4: li      r4, 72
    ctx->gpr[4] = (u32)(s32)(72);

label_801DD0C8:
    ctx->pc = 0x801DD0C8u;
    // 801DD0C8: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD0CC:
    ctx->pc = 0x801DD0CCu;
    // 801DD0CC: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD0D0:
    ctx->pc = 0x801DD0D0u;
    // 801DD0D0: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD0D4:
    ctx->pc = 0x801DD0D4u;
    // 801DD0D4: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD0D8:
    ctx->pc = 0x801DD0D8u;
    // 801DD0D8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD0DCu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD0DC:
    ctx->pc = 0x801DD0DCu;
    ctx->downcount -= 2;
    // 801DD0DC: or.   r3, r3, r3
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

label_801DD0E0:
    ctx->pc = 0x801DD0E0u;
    // 801DD0E0: bc    12, 2, 0x801DD0EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD0EC;
        }
    }

label_801DD0E4:
    ctx->pc = 0x801DD0E4u;
    ctx->downcount -= 1;
    // 801DD0E4: bl      0x801F4A6C
    {
            ctx->lr = 0x801DD0E8u;
            ctx->pc = 0x801F4A6Cu;
            return;
    }

label_801DD0E8:
    ctx->pc = 0x801DD0E8u;
    ctx->downcount -= 1;
    // 801DD0E8: b       0x801DD0F0
    {
            goto label_801DD0F0;
    }

label_801DD0EC:
    ctx->pc = 0x801DD0ECu;
    ctx->downcount -= 1;
    // 801DD0EC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD0F0:
    ctx->pc = 0x801DD0F0u;
    ctx->downcount -= 5;
    // 801DD0F0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD0F4:
    ctx->pc = 0x801DD0F4u;
    // 801DD0F4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD0F8:
    ctx->pc = 0x801DD0F8u;
    // 801DD0F8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD0FC:
    ctx->pc = 0x801DD0FCu;
    // 801DD0FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD100:
    ctx->pc = 0x801DD100u;
    ctx->downcount -= 11;
    // 801DD100: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD104:
    ctx->pc = 0x801DD104u;
    // 801DD104: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD108:
    ctx->pc = 0x801DD108u;
    // 801DD108: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD10C:
    ctx->pc = 0x801DD10Cu;
    // 801DD10C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD110:
    ctx->pc = 0x801DD110u;
    // 801DD110: li      r4, 36
    ctx->gpr[4] = (u32)(s32)(36);

label_801DD114:
    ctx->pc = 0x801DD114u;
    // 801DD114: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD118:
    ctx->pc = 0x801DD118u;
    // 801DD118: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD11C:
    ctx->pc = 0x801DD11Cu;
    // 801DD11C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD120:
    ctx->pc = 0x801DD120u;
    // 801DD120: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD124:
    ctx->pc = 0x801DD124u;
    // 801DD124: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD128u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD128:
    ctx->pc = 0x801DD128u;
    ctx->downcount -= 2;
    // 801DD128: or.   r3, r3, r3
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

label_801DD12C:
    ctx->pc = 0x801DD12Cu;
    // 801DD12C: bc    12, 2, 0x801DD138
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD138;
        }
    }

label_801DD130:
    ctx->pc = 0x801DD130u;
    ctx->downcount -= 1;
    // 801DD130: bl      0x801F4F1C
    {
            ctx->lr = 0x801DD134u;
            ctx->pc = 0x801F4F1Cu;
            return;
    }

label_801DD134:
    ctx->pc = 0x801DD134u;
    ctx->downcount -= 1;
    // 801DD134: b       0x801DD13C
    {
            goto label_801DD13C;
    }

label_801DD138:
    ctx->pc = 0x801DD138u;
    ctx->downcount -= 1;
    // 801DD138: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD13C:
    ctx->pc = 0x801DD13Cu;
    ctx->downcount -= 5;
    // 801DD13C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD140:
    ctx->pc = 0x801DD140u;
    // 801DD140: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD144:
    ctx->pc = 0x801DD144u;
    // 801DD144: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD148:
    ctx->pc = 0x801DD148u;
    // 801DD148: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD14C:
    ctx->pc = 0x801DD14Cu;
    ctx->downcount -= 12;
    // 801DD14C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD150:
    ctx->pc = 0x801DD150u;
    // 801DD150: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD154:
    ctx->pc = 0x801DD154u;
    // 801DD154: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DD158:
    ctx->pc = 0x801DD158u;
    // 801DD158: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD15C:
    ctx->pc = 0x801DD15Cu;
    // 801DD15C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD160:
    ctx->pc = 0x801DD160u;
    // 801DD160: li      r4, 192
    ctx->gpr[4] = (u32)(s32)(192);

label_801DD164:
    ctx->pc = 0x801DD164u;
    // 801DD164: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD168:
    ctx->pc = 0x801DD168u;
    // 801DD168: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD16C:
    ctx->pc = 0x801DD16Cu;
    // 801DD16C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD170:
    ctx->pc = 0x801DD170u;
    // 801DD170: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD174:
    ctx->pc = 0x801DD174u;
    // 801DD174: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD178u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD178:
    ctx->pc = 0x801DD178u;
    ctx->downcount -= 2;
    // 801DD178: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DD17C:
    ctx->pc = 0x801DD17Cu;
    // 801DD17C: bc    12, 2, 0x801DD1B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD1B4;
        }
    }

label_801DD180:
    ctx->pc = 0x801DD180u;
    ctx->downcount -= 2;
    // 801DD180: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD184:
    ctx->pc = 0x801DD184u;
    // 801DD184: bl      0x801F27B0
    {
            ctx->lr = 0x801DD188u;
            ctx->pc = 0x801F27B0u;
            return;
    }

label_801DD188:
    ctx->pc = 0x801DD188u;
    ctx->downcount -= 11;
    // 801DD188: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DD18C:
    ctx->pc = 0x801DD18Cu;
    // 801DD18C: lis     r11, -32720
    ctx->gpr[11] = ((u32)(s32)(-32720) << 16);

label_801DD190:
    ctx->pc = 0x801DD190u;
    // 801DD190: lis     r10, -32720
    ctx->gpr[10] = ((u32)(s32)(-32720) << 16);

label_801DD194:
    ctx->pc = 0x801DD194u;
    // 801DD194: addi    r9, r9, 18976
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18976);

label_801DD198:
    ctx->pc = 0x801DD198u;
    // 801DD198: addi    r11, r11, 18504
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(18504);

label_801DD19C:
    ctx->pc = 0x801DD19Cu;
    // 801DD19C: addi    r10, r10, 18576
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(18576);

label_801DD1A0:
    ctx->pc = 0x801DD1A0u;
    // 801DD1A0: stw     r9, 108(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DD1A4:
    ctx->pc = 0x801DD1A4u;
    // 801DD1A4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD1A8:
    ctx->pc = 0x801DD1A8u;
    // 801DD1A8: stw     r11, 112(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DD1AC:
    ctx->pc = 0x801DD1ACu;
    // 801DD1AC: stw     r10, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801DD1B0:
    ctx->pc = 0x801DD1B0u;
    // 801DD1B0: b       0x801DD1B8
    {
            goto label_801DD1B8;
    }

label_801DD1B4:
    ctx->pc = 0x801DD1B4u;
    ctx->downcount -= 1;
    // 801DD1B4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD1B8:
    ctx->pc = 0x801DD1B8u;
    ctx->downcount -= 6;
    // 801DD1B8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD1BC:
    ctx->pc = 0x801DD1BCu;
    // 801DD1BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD1C0:
    ctx->pc = 0x801DD1C0u;
    // 801DD1C0: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DD1C4:
    ctx->pc = 0x801DD1C4u;
    // 801DD1C4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DD1C8:
    ctx->pc = 0x801DD1C8u;
    // 801DD1C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD1CC:
    ctx->pc = 0x801DD1CCu;
    ctx->downcount -= 11;
    // 801DD1CC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD1D0:
    ctx->pc = 0x801DD1D0u;
    // 801DD1D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD1D4:
    ctx->pc = 0x801DD1D4u;
    // 801DD1D4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD1D8:
    ctx->pc = 0x801DD1D8u;
    // 801DD1D8: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD1DC:
    ctx->pc = 0x801DD1DCu;
    // 801DD1DC: li      r4, 212
    ctx->gpr[4] = (u32)(s32)(212);

label_801DD1E0:
    ctx->pc = 0x801DD1E0u;
    // 801DD1E0: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD1E4:
    ctx->pc = 0x801DD1E4u;
    // 801DD1E4: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD1E8:
    ctx->pc = 0x801DD1E8u;
    // 801DD1E8: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD1EC:
    ctx->pc = 0x801DD1ECu;
    // 801DD1EC: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD1F0:
    ctx->pc = 0x801DD1F0u;
    // 801DD1F0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD1F4u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD1F4:
    ctx->pc = 0x801DD1F4u;
    ctx->downcount -= 2;
    // 801DD1F4: or.   r3, r3, r3
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

label_801DD1F8:
    ctx->pc = 0x801DD1F8u;
    // 801DD1F8: bc    12, 2, 0x801DD204
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD204;
        }
    }

label_801DD1FC:
    ctx->pc = 0x801DD1FCu;
    ctx->downcount -= 1;
    // 801DD1FC: bl      0x801F3024
    {
            ctx->lr = 0x801DD200u;
            ctx->pc = 0x801F3024u;
            return;
    }

label_801DD200:
    ctx->pc = 0x801DD200u;
    ctx->downcount -= 1;
    // 801DD200: b       0x801DD208
    {
            goto label_801DD208;
    }

label_801DD204:
    ctx->pc = 0x801DD204u;
    ctx->downcount -= 1;
    // 801DD204: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD208:
    ctx->pc = 0x801DD208u;
    ctx->downcount -= 5;
    // 801DD208: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD20C:
    ctx->pc = 0x801DD20Cu;
    // 801DD20C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD210:
    ctx->pc = 0x801DD210u;
    // 801DD210: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD214:
    ctx->pc = 0x801DD214u;
    // 801DD214: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD218:
    ctx->pc = 0x801DD218u;
    ctx->downcount -= 12;
    // 801DD218: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD21C:
    ctx->pc = 0x801DD21Cu;
    // 801DD21C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD220:
    ctx->pc = 0x801DD220u;
    // 801DD220: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DD224:
    ctx->pc = 0x801DD224u;
    // 801DD224: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD228:
    ctx->pc = 0x801DD228u;
    // 801DD228: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD22C:
    ctx->pc = 0x801DD22Cu;
    // 801DD22C: li      r4, 36
    ctx->gpr[4] = (u32)(s32)(36);

label_801DD230:
    ctx->pc = 0x801DD230u;
    // 801DD230: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD234:
    ctx->pc = 0x801DD234u;
    // 801DD234: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD238:
    ctx->pc = 0x801DD238u;
    // 801DD238: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD23C:
    ctx->pc = 0x801DD23Cu;
    // 801DD23C: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD240:
    ctx->pc = 0x801DD240u;
    // 801DD240: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD244u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD244:
    ctx->pc = 0x801DD244u;
    ctx->downcount -= 2;
    // 801DD244: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DD248:
    ctx->pc = 0x801DD248u;
    // 801DD248: bc    12, 2, 0x801DD27C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD27C;
        }
    }

label_801DD24C:
    ctx->pc = 0x801DD24Cu;
    ctx->downcount -= 2;
    // 801DD24C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD250:
    ctx->pc = 0x801DD250u;
    // 801DD250: bl      0x801E7708
    {
            ctx->lr = 0x801DD254u;
            ctx->pc = 0x801E7708u;
            return;
    }

label_801DD254:
    ctx->pc = 0x801DD254u;
    ctx->downcount -= 10;
    // 801DD254: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DD258:
    ctx->pc = 0x801DD258u;
    // 801DD258: lis     r11, -32720
    ctx->gpr[11] = ((u32)(s32)(-32720) << 16);

label_801DD25C:
    ctx->pc = 0x801DD25Cu;
    // 801DD25C: addi    r9, r9, 17432
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17432);

label_801DD260:
    ctx->pc = 0x801DD260u;
    // 801DD260: addi    r11, r11, 17464
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(17464);

label_801DD264:
    ctx->pc = 0x801DD264u;
    // 801DD264: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DD268:
    ctx->pc = 0x801DD268u;
    // 801DD268: stw     r9, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DD26C:
    ctx->pc = 0x801DD26Cu;
    // 801DD26C: stw     r11, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DD270:
    ctx->pc = 0x801DD270u;
    // 801DD270: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD274:
    ctx->pc = 0x801DD274u;
    // 801DD274: stw     r0, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD278:
    ctx->pc = 0x801DD278u;
    // 801DD278: b       0x801DD280
    {
            goto label_801DD280;
    }

label_801DD27C:
    ctx->pc = 0x801DD27Cu;
    ctx->downcount -= 1;
    // 801DD27C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD280:
    ctx->pc = 0x801DD280u;
    ctx->downcount -= 6;
    // 801DD280: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD284:
    ctx->pc = 0x801DD284u;
    // 801DD284: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD288:
    ctx->pc = 0x801DD288u;
    // 801DD288: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DD28C:
    ctx->pc = 0x801DD28Cu;
    // 801DD28C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DD290:
    ctx->pc = 0x801DD290u;
    // 801DD290: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD294:
    ctx->pc = 0x801DD294u;
    ctx->downcount -= 12;
    // 801DD294: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD298:
    ctx->pc = 0x801DD298u;
    // 801DD298: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD29C:
    ctx->pc = 0x801DD29Cu;
    // 801DD29C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DD2A0:
    ctx->pc = 0x801DD2A0u;
    // 801DD2A0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD2A4:
    ctx->pc = 0x801DD2A4u;
    // 801DD2A4: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD2A8:
    ctx->pc = 0x801DD2A8u;
    // 801DD2A8: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_801DD2AC:
    ctx->pc = 0x801DD2ACu;
    // 801DD2AC: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD2B0:
    ctx->pc = 0x801DD2B0u;
    // 801DD2B0: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD2B4:
    ctx->pc = 0x801DD2B4u;
    // 801DD2B4: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD2B8:
    ctx->pc = 0x801DD2B8u;
    // 801DD2B8: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD2BC:
    ctx->pc = 0x801DD2BCu;
    // 801DD2BC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD2C0u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD2C0:
    ctx->pc = 0x801DD2C0u;
    ctx->downcount -= 2;
    // 801DD2C0: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DD2C4:
    ctx->pc = 0x801DD2C4u;
    // 801DD2C4: bc    12, 2, 0x801DD2EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD2EC;
        }
    }

label_801DD2C8:
    ctx->pc = 0x801DD2C8u;
    ctx->downcount -= 2;
    // 801DD2C8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD2CC:
    ctx->pc = 0x801DD2CCu;
    // 801DD2CC: bl      0x801E7708
    {
            ctx->lr = 0x801DD2D0u;
            ctx->pc = 0x801E7708u;
            return;
    }

label_801DD2D0:
    ctx->pc = 0x801DD2D0u;
    ctx->downcount -= 7;
    // 801DD2D0: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DD2D4:
    ctx->pc = 0x801DD2D4u;
    // 801DD2D4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DD2D8:
    ctx->pc = 0x801DD2D8u;
    // 801DD2D8: addi    r9, r9, 12896
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(12896);

label_801DD2DC:
    ctx->pc = 0x801DD2DCu;
    // 801DD2DC: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD2E0:
    ctx->pc = 0x801DD2E0u;
    // 801DD2E0: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DD2E4:
    ctx->pc = 0x801DD2E4u;
    // 801DD2E4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD2E8:
    ctx->pc = 0x801DD2E8u;
    // 801DD2E8: b       0x801DD2F0
    {
            goto label_801DD2F0;
    }

label_801DD2EC:
    ctx->pc = 0x801DD2ECu;
    ctx->downcount -= 1;
    // 801DD2EC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD2F0:
    ctx->pc = 0x801DD2F0u;
    ctx->downcount -= 6;
    // 801DD2F0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD2F4:
    ctx->pc = 0x801DD2F4u;
    // 801DD2F4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD2F8:
    ctx->pc = 0x801DD2F8u;
    // 801DD2F8: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DD2FC:
    ctx->pc = 0x801DD2FCu;
    // 801DD2FC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DD300:
    ctx->pc = 0x801DD300u;
    // 801DD300: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD304:
    ctx->pc = 0x801DD304u;
    ctx->downcount -= 11;
    // 801DD304: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD308:
    ctx->pc = 0x801DD308u;
    // 801DD308: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD30C:
    ctx->pc = 0x801DD30Cu;
    // 801DD30C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD310:
    ctx->pc = 0x801DD310u;
    // 801DD310: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD314:
    ctx->pc = 0x801DD314u;
    // 801DD314: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD318:
    ctx->pc = 0x801DD318u;
    // 801DD318: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD31C:
    ctx->pc = 0x801DD31Cu;
    // 801DD31C: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD320:
    ctx->pc = 0x801DD320u;
    // 801DD320: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD324:
    ctx->pc = 0x801DD324u;
    // 801DD324: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD328:
    ctx->pc = 0x801DD328u;
    // 801DD328: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD32Cu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD32C:
    ctx->pc = 0x801DD32Cu;
    ctx->downcount -= 2;
    // 801DD32C: or.   r3, r3, r3
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

label_801DD330:
    ctx->pc = 0x801DD330u;
    // 801DD330: bc    12, 2, 0x801DD33C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD33C;
        }
    }

label_801DD334:
    ctx->pc = 0x801DD334u;
    ctx->downcount -= 1;
    // 801DD334: bl      0x801F3374
    {
            ctx->lr = 0x801DD338u;
            ctx->pc = 0x801F3374u;
            return;
    }

label_801DD338:
    ctx->pc = 0x801DD338u;
    ctx->downcount -= 1;
    // 801DD338: b       0x801DD340
    {
            goto label_801DD340;
    }

label_801DD33C:
    ctx->pc = 0x801DD33Cu;
    ctx->downcount -= 1;
    // 801DD33C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD340:
    ctx->pc = 0x801DD340u;
    ctx->downcount -= 5;
    // 801DD340: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD344:
    ctx->pc = 0x801DD344u;
    // 801DD344: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD348:
    ctx->pc = 0x801DD348u;
    // 801DD348: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD34C:
    ctx->pc = 0x801DD34Cu;
    // 801DD34C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD350:
    ctx->pc = 0x801DD350u;
    ctx->downcount -= 12;
    // 801DD350: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD354:
    ctx->pc = 0x801DD354u;
    // 801DD354: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD358:
    ctx->pc = 0x801DD358u;
    // 801DD358: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DD35C:
    ctx->pc = 0x801DD35Cu;
    // 801DD35C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD360:
    ctx->pc = 0x801DD360u;
    // 801DD360: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD364:
    ctx->pc = 0x801DD364u;
    // 801DD364: li      r4, 36
    ctx->gpr[4] = (u32)(s32)(36);

label_801DD368:
    ctx->pc = 0x801DD368u;
    // 801DD368: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD36C:
    ctx->pc = 0x801DD36Cu;
    // 801DD36C: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD370:
    ctx->pc = 0x801DD370u;
    // 801DD370: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD374:
    ctx->pc = 0x801DD374u;
    // 801DD374: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD378:
    ctx->pc = 0x801DD378u;
    // 801DD378: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD37Cu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD37C:
    ctx->pc = 0x801DD37Cu;
    ctx->downcount -= 2;
    // 801DD37C: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DD380:
    ctx->pc = 0x801DD380u;
    // 801DD380: bc    12, 2, 0x801DD3A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD3A0;
        }
    }

label_801DD384:
    ctx->pc = 0x801DD384u;
    ctx->downcount -= 2;
    // 801DD384: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD388:
    ctx->pc = 0x801DD388u;
    // 801DD388: bl      0x801D1410
    {
            ctx->lr = 0x801DD38Cu;
            ctx->pc = 0x801D1410u;
            return;
    }

label_801DD38C:
    ctx->pc = 0x801DD38Cu;
    ctx->downcount -= 5;
    // 801DD38C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801DD390:
    ctx->pc = 0x801DD390u;
    // 801DD390: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD394:
    ctx->pc = 0x801DD394u;
    // 801DD394: addi    r9, r9, -19432
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-19432);

label_801DD398:
    ctx->pc = 0x801DD398u;
    // 801DD398: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DD39C:
    ctx->pc = 0x801DD39Cu;
    // 801DD39C: b       0x801DD3A4
    {
            goto label_801DD3A4;
    }

label_801DD3A0:
    ctx->pc = 0x801DD3A0u;
    ctx->downcount -= 1;
    // 801DD3A0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD3A4:
    ctx->pc = 0x801DD3A4u;
    ctx->downcount -= 6;
    // 801DD3A4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD3A8:
    ctx->pc = 0x801DD3A8u;
    // 801DD3A8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD3AC:
    ctx->pc = 0x801DD3ACu;
    // 801DD3AC: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DD3B0:
    ctx->pc = 0x801DD3B0u;
    // 801DD3B0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DD3B4:
    ctx->pc = 0x801DD3B4u;
    // 801DD3B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD3B8:
    ctx->pc = 0x801DD3B8u;
    ctx->downcount -= 11;
    // 801DD3B8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD3BC:
    ctx->pc = 0x801DD3BCu;
    // 801DD3BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD3C0:
    ctx->pc = 0x801DD3C0u;
    // 801DD3C0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD3C4:
    ctx->pc = 0x801DD3C4u;
    // 801DD3C4: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD3C8:
    ctx->pc = 0x801DD3C8u;
    // 801DD3C8: li      r4, 36
    ctx->gpr[4] = (u32)(s32)(36);

label_801DD3CC:
    ctx->pc = 0x801DD3CCu;
    // 801DD3CC: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD3D0:
    ctx->pc = 0x801DD3D0u;
    // 801DD3D0: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD3D4:
    ctx->pc = 0x801DD3D4u;
    // 801DD3D4: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD3D8:
    ctx->pc = 0x801DD3D8u;
    // 801DD3D8: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD3DC:
    ctx->pc = 0x801DD3DCu;
    // 801DD3DC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD3E0u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD3E0:
    ctx->pc = 0x801DD3E0u;
    ctx->downcount -= 2;
    // 801DD3E0: or.   r3, r3, r3
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

label_801DD3E4:
    ctx->pc = 0x801DD3E4u;
    // 801DD3E4: bc    12, 2, 0x801DD3F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD3F0;
        }
    }

label_801DD3E8:
    ctx->pc = 0x801DD3E8u;
    ctx->downcount -= 1;
    // 801DD3E8: bl      0x801DF5CC
    {
            ctx->lr = 0x801DD3ECu;
            ctx->pc = 0x801DF5CCu;
            return;
    }

label_801DD3EC:
    ctx->pc = 0x801DD3ECu;
    ctx->downcount -= 1;
    // 801DD3EC: b       0x801DD3F4
    {
            goto label_801DD3F4;
    }

label_801DD3F0:
    ctx->pc = 0x801DD3F0u;
    ctx->downcount -= 1;
    // 801DD3F0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD3F4:
    ctx->pc = 0x801DD3F4u;
    ctx->downcount -= 5;
    // 801DD3F4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD3F8:
    ctx->pc = 0x801DD3F8u;
    // 801DD3F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD3FC:
    ctx->pc = 0x801DD3FCu;
    // 801DD3FC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD400:
    ctx->pc = 0x801DD400u;
    // 801DD400: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD404:
    ctx->pc = 0x801DD404u;
    ctx->downcount -= 12;
    // 801DD404: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD408:
    ctx->pc = 0x801DD408u;
    // 801DD408: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD40C:
    ctx->pc = 0x801DD40Cu;
    // 801DD40C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DD410:
    ctx->pc = 0x801DD410u;
    // 801DD410: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD414:
    ctx->pc = 0x801DD414u;
    // 801DD414: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD418:
    ctx->pc = 0x801DD418u;
    // 801DD418: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_801DD41C:
    ctx->pc = 0x801DD41Cu;
    // 801DD41C: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD420:
    ctx->pc = 0x801DD420u;
    // 801DD420: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD424:
    ctx->pc = 0x801DD424u;
    // 801DD424: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD428:
    ctx->pc = 0x801DD428u;
    // 801DD428: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD42C:
    ctx->pc = 0x801DD42Cu;
    // 801DD42C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD430u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD430:
    ctx->pc = 0x801DD430u;
    ctx->downcount -= 2;
    // 801DD430: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DD434:
    ctx->pc = 0x801DD434u;
    // 801DD434: bc    12, 2, 0x801DD454
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD454;
        }
    }

label_801DD438:
    ctx->pc = 0x801DD438u;
    ctx->downcount -= 2;
    // 801DD438: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD43C:
    ctx->pc = 0x801DD43Cu;
    // 801DD43C: bl      0x801E7708
    {
            ctx->lr = 0x801DD440u;
            ctx->pc = 0x801E7708u;
            return;
    }

label_801DD440:
    ctx->pc = 0x801DD440u;
    ctx->downcount -= 5;
    // 801DD440: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DD444:
    ctx->pc = 0x801DD444u;
    // 801DD444: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD448:
    ctx->pc = 0x801DD448u;
    // 801DD448: addi    r9, r9, 17848
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17848);

label_801DD44C:
    ctx->pc = 0x801DD44Cu;
    // 801DD44C: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DD450:
    ctx->pc = 0x801DD450u;
    // 801DD450: b       0x801DD458
    {
            goto label_801DD458;
    }

label_801DD454:
    ctx->pc = 0x801DD454u;
    ctx->downcount -= 1;
    // 801DD454: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD458:
    ctx->pc = 0x801DD458u;
    ctx->downcount -= 6;
    // 801DD458: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD45C:
    ctx->pc = 0x801DD45Cu;
    // 801DD45C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD460:
    ctx->pc = 0x801DD460u;
    // 801DD460: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DD464:
    ctx->pc = 0x801DD464u;
    // 801DD464: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DD468:
    ctx->pc = 0x801DD468u;
    // 801DD468: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD46C:
    ctx->pc = 0x801DD46Cu;
    ctx->downcount -= 11;
    // 801DD46C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD470:
    ctx->pc = 0x801DD470u;
    // 801DD470: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD474:
    ctx->pc = 0x801DD474u;
    // 801DD474: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD478:
    ctx->pc = 0x801DD478u;
    // 801DD478: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD47C:
    ctx->pc = 0x801DD47Cu;
    // 801DD47C: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD480:
    ctx->pc = 0x801DD480u;
    // 801DD480: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD484:
    ctx->pc = 0x801DD484u;
    // 801DD484: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD488:
    ctx->pc = 0x801DD488u;
    // 801DD488: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD48C:
    ctx->pc = 0x801DD48Cu;
    // 801DD48C: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD490:
    ctx->pc = 0x801DD490u;
    // 801DD490: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD494u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD494:
    ctx->pc = 0x801DD494u;
    ctx->downcount -= 2;
    // 801DD494: or.   r3, r3, r3
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

label_801DD498:
    ctx->pc = 0x801DD498u;
    // 801DD498: bc    12, 2, 0x801DD4A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD4A4;
        }
    }

label_801DD49C:
    ctx->pc = 0x801DD49Cu;
    ctx->downcount -= 1;
    // 801DD49C: bl      0x801F3900
    {
            ctx->lr = 0x801DD4A0u;
            ctx->pc = 0x801F3900u;
            return;
    }

label_801DD4A0:
    ctx->pc = 0x801DD4A0u;
    ctx->downcount -= 1;
    // 801DD4A0: b       0x801DD4A8
    {
            goto label_801DD4A8;
    }

label_801DD4A4:
    ctx->pc = 0x801DD4A4u;
    ctx->downcount -= 1;
    // 801DD4A4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD4A8:
    ctx->pc = 0x801DD4A8u;
    ctx->downcount -= 5;
    // 801DD4A8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD4AC:
    ctx->pc = 0x801DD4ACu;
    // 801DD4AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD4B0:
    ctx->pc = 0x801DD4B0u;
    // 801DD4B0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD4B4:
    ctx->pc = 0x801DD4B4u;
    // 801DD4B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD4B8:
    ctx->pc = 0x801DD4B8u;
    ctx->downcount -= 11;
    // 801DD4B8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD4BC:
    ctx->pc = 0x801DD4BCu;
    // 801DD4BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD4C0:
    ctx->pc = 0x801DD4C0u;
    // 801DD4C0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD4C4:
    ctx->pc = 0x801DD4C4u;
    // 801DD4C4: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD4C8:
    ctx->pc = 0x801DD4C8u;
    // 801DD4C8: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD4CC:
    ctx->pc = 0x801DD4CCu;
    // 801DD4CC: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD4D0:
    ctx->pc = 0x801DD4D0u;
    // 801DD4D0: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD4D4:
    ctx->pc = 0x801DD4D4u;
    // 801DD4D4: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD4D8:
    ctx->pc = 0x801DD4D8u;
    // 801DD4D8: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD4DC:
    ctx->pc = 0x801DD4DCu;
    // 801DD4DC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD4E0u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD4E0:
    ctx->pc = 0x801DD4E0u;
    ctx->downcount -= 2;
    // 801DD4E0: or.   r3, r3, r3
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

label_801DD4E4:
    ctx->pc = 0x801DD4E4u;
    // 801DD4E4: bc    12, 2, 0x801DD4F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD4F0;
        }
    }

label_801DD4E8:
    ctx->pc = 0x801DD4E8u;
    ctx->downcount -= 1;
    // 801DD4E8: bl      0x801F3FAC
    {
            ctx->lr = 0x801DD4ECu;
            ctx->pc = 0x801F3FACu;
            return;
    }

label_801DD4EC:
    ctx->pc = 0x801DD4ECu;
    ctx->downcount -= 1;
    // 801DD4EC: b       0x801DD4F4
    {
            goto label_801DD4F4;
    }

label_801DD4F0:
    ctx->pc = 0x801DD4F0u;
    ctx->downcount -= 1;
    // 801DD4F0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD4F4:
    ctx->pc = 0x801DD4F4u;
    ctx->downcount -= 5;
    // 801DD4F4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD4F8:
    ctx->pc = 0x801DD4F8u;
    // 801DD4F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD4FC:
    ctx->pc = 0x801DD4FCu;
    // 801DD4FC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD500:
    ctx->pc = 0x801DD500u;
    // 801DD500: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD504:
    ctx->pc = 0x801DD504u;
    ctx->downcount -= 11;
    // 801DD504: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD508:
    ctx->pc = 0x801DD508u;
    // 801DD508: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD50C:
    ctx->pc = 0x801DD50Cu;
    // 801DD50C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD510:
    ctx->pc = 0x801DD510u;
    // 801DD510: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD514:
    ctx->pc = 0x801DD514u;
    // 801DD514: li      r4, 44
    ctx->gpr[4] = (u32)(s32)(44);

label_801DD518:
    ctx->pc = 0x801DD518u;
    // 801DD518: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD51C:
    ctx->pc = 0x801DD51Cu;
    // 801DD51C: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD520:
    ctx->pc = 0x801DD520u;
    // 801DD520: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD524:
    ctx->pc = 0x801DD524u;
    // 801DD524: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD528:
    ctx->pc = 0x801DD528u;
    // 801DD528: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD52Cu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD52C:
    ctx->pc = 0x801DD52Cu;
    ctx->downcount -= 2;
    // 801DD52C: or.   r3, r3, r3
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

label_801DD530:
    ctx->pc = 0x801DD530u;
    // 801DD530: bc    12, 2, 0x801DD53C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD53C;
        }
    }

label_801DD534:
    ctx->pc = 0x801DD534u;
    ctx->downcount -= 1;
    // 801DD534: bl      0x801F4314
    {
            ctx->lr = 0x801DD538u;
            ctx->pc = 0x801F4314u;
            return;
    }

label_801DD538:
    ctx->pc = 0x801DD538u;
    ctx->downcount -= 1;
    // 801DD538: b       0x801DD540
    {
            goto label_801DD540;
    }

label_801DD53C:
    ctx->pc = 0x801DD53Cu;
    ctx->downcount -= 1;
    // 801DD53C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD540:
    ctx->pc = 0x801DD540u;
    ctx->downcount -= 5;
    // 801DD540: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD544:
    ctx->pc = 0x801DD544u;
    // 801DD544: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD548:
    ctx->pc = 0x801DD548u;
    // 801DD548: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD54C:
    ctx->pc = 0x801DD54Cu;
    // 801DD54C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD550:
    ctx->pc = 0x801DD550u;
    ctx->downcount -= 11;
    // 801DD550: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD554:
    ctx->pc = 0x801DD554u;
    // 801DD554: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD558:
    ctx->pc = 0x801DD558u;
    // 801DD558: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD55C:
    ctx->pc = 0x801DD55Cu;
    // 801DD55C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD560:
    ctx->pc = 0x801DD560u;
    // 801DD560: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD564:
    ctx->pc = 0x801DD564u;
    // 801DD564: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD568:
    ctx->pc = 0x801DD568u;
    // 801DD568: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD56C:
    ctx->pc = 0x801DD56Cu;
    // 801DD56C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD570:
    ctx->pc = 0x801DD570u;
    // 801DD570: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD574:
    ctx->pc = 0x801DD574u;
    // 801DD574: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD578u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD578:
    ctx->pc = 0x801DD578u;
    ctx->downcount -= 2;
    // 801DD578: or.   r3, r3, r3
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

label_801DD57C:
    ctx->pc = 0x801DD57Cu;
    // 801DD57C: bc    12, 2, 0x801DD588
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD588;
        }
    }

label_801DD580:
    ctx->pc = 0x801DD580u;
    ctx->downcount -= 1;
    // 801DD580: bl      0x801F40AC
    {
            ctx->lr = 0x801DD584u;
            ctx->pc = 0x801F40ACu;
            return;
    }

label_801DD584:
    ctx->pc = 0x801DD584u;
    ctx->downcount -= 1;
    // 801DD584: b       0x801DD58C
    {
            goto label_801DD58C;
    }

label_801DD588:
    ctx->pc = 0x801DD588u;
    ctx->downcount -= 1;
    // 801DD588: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD58C:
    ctx->pc = 0x801DD58Cu;
    ctx->downcount -= 5;
    // 801DD58C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD590:
    ctx->pc = 0x801DD590u;
    // 801DD590: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD594:
    ctx->pc = 0x801DD594u;
    // 801DD594: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD598:
    ctx->pc = 0x801DD598u;
    // 801DD598: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD59C:
    ctx->pc = 0x801DD59Cu;
    ctx->downcount -= 11;
    // 801DD59C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD5A0:
    ctx->pc = 0x801DD5A0u;
    // 801DD5A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD5A4:
    ctx->pc = 0x801DD5A4u;
    // 801DD5A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD5A8:
    ctx->pc = 0x801DD5A8u;
    // 801DD5A8: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD5AC:
    ctx->pc = 0x801DD5ACu;
    // 801DD5AC: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD5B0:
    ctx->pc = 0x801DD5B0u;
    // 801DD5B0: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD5B4:
    ctx->pc = 0x801DD5B4u;
    // 801DD5B4: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD5B8:
    ctx->pc = 0x801DD5B8u;
    // 801DD5B8: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD5BC:
    ctx->pc = 0x801DD5BCu;
    // 801DD5BC: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD5C0:
    ctx->pc = 0x801DD5C0u;
    // 801DD5C0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD5C4u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD5C4:
    ctx->pc = 0x801DD5C4u;
    ctx->downcount -= 2;
    // 801DD5C4: or.   r3, r3, r3
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

label_801DD5C8:
    ctx->pc = 0x801DD5C8u;
    // 801DD5C8: bc    12, 2, 0x801DD5D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD5D4;
        }
    }

label_801DD5CC:
    ctx->pc = 0x801DD5CCu;
    ctx->downcount -= 1;
    // 801DD5CC: bl      0x801F3EB0
    {
            ctx->lr = 0x801DD5D0u;
            ctx->pc = 0x801F3EB0u;
            return;
    }

label_801DD5D0:
    ctx->pc = 0x801DD5D0u;
    ctx->downcount -= 1;
    // 801DD5D0: b       0x801DD5D8
    {
            goto label_801DD5D8;
    }

label_801DD5D4:
    ctx->pc = 0x801DD5D4u;
    ctx->downcount -= 1;
    // 801DD5D4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD5D8:
    ctx->pc = 0x801DD5D8u;
    ctx->downcount -= 5;
    // 801DD5D8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD5DC:
    ctx->pc = 0x801DD5DCu;
    // 801DD5DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD5E0:
    ctx->pc = 0x801DD5E0u;
    // 801DD5E0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD5E4:
    ctx->pc = 0x801DD5E4u;
    // 801DD5E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD5E8:
    ctx->pc = 0x801DD5E8u;
    ctx->downcount -= 11;
    // 801DD5E8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD5EC:
    ctx->pc = 0x801DD5ECu;
    // 801DD5EC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD5F0:
    ctx->pc = 0x801DD5F0u;
    // 801DD5F0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD5F4:
    ctx->pc = 0x801DD5F4u;
    // 801DD5F4: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD5F8:
    ctx->pc = 0x801DD5F8u;
    // 801DD5F8: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD5FC:
    ctx->pc = 0x801DD5FCu;
    // 801DD5FC: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD600:
    ctx->pc = 0x801DD600u;
    // 801DD600: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD604:
    ctx->pc = 0x801DD604u;
    // 801DD604: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD608:
    ctx->pc = 0x801DD608u;
    // 801DD608: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD60C:
    ctx->pc = 0x801DD60Cu;
    // 801DD60C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD610u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD610:
    ctx->pc = 0x801DD610u;
    ctx->downcount -= 2;
    // 801DD610: or.   r3, r3, r3
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

label_801DD614:
    ctx->pc = 0x801DD614u;
    // 801DD614: bc    12, 2, 0x801DD620
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD620;
        }
    }

label_801DD618:
    ctx->pc = 0x801DD618u;
    ctx->downcount -= 1;
    // 801DD618: bl      0x801F39FC
    {
            ctx->lr = 0x801DD61Cu;
            ctx->pc = 0x801F39FCu;
            return;
    }

label_801DD61C:
    ctx->pc = 0x801DD61Cu;
    ctx->downcount -= 1;
    // 801DD61C: b       0x801DD624
    {
            goto label_801DD624;
    }

label_801DD620:
    ctx->pc = 0x801DD620u;
    ctx->downcount -= 1;
    // 801DD620: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD624:
    ctx->pc = 0x801DD624u;
    ctx->downcount -= 5;
    // 801DD624: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD628:
    ctx->pc = 0x801DD628u;
    // 801DD628: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD62C:
    ctx->pc = 0x801DD62Cu;
    // 801DD62C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD630:
    ctx->pc = 0x801DD630u;
    // 801DD630: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD634:
    ctx->pc = 0x801DD634u;
    ctx->downcount -= 11;
    // 801DD634: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD638:
    ctx->pc = 0x801DD638u;
    // 801DD638: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD63C:
    ctx->pc = 0x801DD63Cu;
    // 801DD63C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD640:
    ctx->pc = 0x801DD640u;
    // 801DD640: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD644:
    ctx->pc = 0x801DD644u;
    // 801DD644: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD648:
    ctx->pc = 0x801DD648u;
    // 801DD648: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD64C:
    ctx->pc = 0x801DD64Cu;
    // 801DD64C: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD650:
    ctx->pc = 0x801DD650u;
    // 801DD650: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD654:
    ctx->pc = 0x801DD654u;
    // 801DD654: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD658:
    ctx->pc = 0x801DD658u;
    // 801DD658: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD65Cu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD65C:
    ctx->pc = 0x801DD65Cu;
    ctx->downcount -= 2;
    // 801DD65C: or.   r3, r3, r3
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

label_801DD660:
    ctx->pc = 0x801DD660u;
    // 801DD660: bc    12, 2, 0x801DD66C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD66C;
        }
    }

label_801DD664:
    ctx->pc = 0x801DD664u;
    ctx->downcount -= 1;
    // 801DD664: bl      0x801F4730
    {
            ctx->lr = 0x801DD668u;
            ctx->pc = 0x801F4730u;
            return;
    }

label_801DD668:
    ctx->pc = 0x801DD668u;
    ctx->downcount -= 1;
    // 801DD668: b       0x801DD670
    {
            goto label_801DD670;
    }

label_801DD66C:
    ctx->pc = 0x801DD66Cu;
    ctx->downcount -= 1;
    // 801DD66C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD670:
    ctx->pc = 0x801DD670u;
    ctx->downcount -= 5;
    // 801DD670: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD674:
    ctx->pc = 0x801DD674u;
    // 801DD674: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD678:
    ctx->pc = 0x801DD678u;
    // 801DD678: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD67C:
    ctx->pc = 0x801DD67Cu;
    // 801DD67C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD680:
    ctx->pc = 0x801DD680u;
    ctx->downcount -= 11;
    // 801DD680: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD684:
    ctx->pc = 0x801DD684u;
    // 801DD684: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD688:
    ctx->pc = 0x801DD688u;
    // 801DD688: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD68C:
    ctx->pc = 0x801DD68Cu;
    // 801DD68C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD690:
    ctx->pc = 0x801DD690u;
    // 801DD690: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD694:
    ctx->pc = 0x801DD694u;
    // 801DD694: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD698:
    ctx->pc = 0x801DD698u;
    // 801DD698: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD69C:
    ctx->pc = 0x801DD69Cu;
    // 801DD69C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD6A0:
    ctx->pc = 0x801DD6A0u;
    // 801DD6A0: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD6A4:
    ctx->pc = 0x801DD6A4u;
    // 801DD6A4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD6A8u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD6A8:
    ctx->pc = 0x801DD6A8u;
    ctx->downcount -= 2;
    // 801DD6A8: or.   r3, r3, r3
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

label_801DD6AC:
    ctx->pc = 0x801DD6ACu;
    // 801DD6AC: bc    12, 2, 0x801DD6B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD6B8;
        }
    }

label_801DD6B0:
    ctx->pc = 0x801DD6B0u;
    ctx->downcount -= 1;
    // 801DD6B0: bl      0x801F3CB8
    {
            ctx->lr = 0x801DD6B4u;
            ctx->pc = 0x801F3CB8u;
            return;
    }

label_801DD6B4:
    ctx->pc = 0x801DD6B4u;
    ctx->downcount -= 1;
    // 801DD6B4: b       0x801DD6BC
    {
            goto label_801DD6BC;
    }

label_801DD6B8:
    ctx->pc = 0x801DD6B8u;
    ctx->downcount -= 1;
    // 801DD6B8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD6BC:
    ctx->pc = 0x801DD6BCu;
    ctx->downcount -= 5;
    // 801DD6BC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD6C0:
    ctx->pc = 0x801DD6C0u;
    // 801DD6C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD6C4:
    ctx->pc = 0x801DD6C4u;
    // 801DD6C4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD6C8:
    ctx->pc = 0x801DD6C8u;
    // 801DD6C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD6CC:
    ctx->pc = 0x801DD6CCu;
    ctx->downcount -= 11;
    // 801DD6CC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD6D0:
    ctx->pc = 0x801DD6D0u;
    // 801DD6D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD6D4:
    ctx->pc = 0x801DD6D4u;
    // 801DD6D4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD6D8:
    ctx->pc = 0x801DD6D8u;
    // 801DD6D8: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD6DC:
    ctx->pc = 0x801DD6DCu;
    // 801DD6DC: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_801DD6E0:
    ctx->pc = 0x801DD6E0u;
    // 801DD6E0: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD6E4:
    ctx->pc = 0x801DD6E4u;
    // 801DD6E4: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD6E8:
    ctx->pc = 0x801DD6E8u;
    // 801DD6E8: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD6EC:
    ctx->pc = 0x801DD6ECu;
    // 801DD6EC: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD6F0:
    ctx->pc = 0x801DD6F0u;
    // 801DD6F0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD6F4u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD6F4:
    ctx->pc = 0x801DD6F4u;
    ctx->downcount -= 2;
    // 801DD6F4: or.   r3, r3, r3
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

label_801DD6F8:
    ctx->pc = 0x801DD6F8u;
    // 801DD6F8: bc    12, 2, 0x801DD704
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD704;
        }
    }

label_801DD6FC:
    ctx->pc = 0x801DD6FCu;
    ctx->downcount -= 1;
    // 801DD6FC: bl      0x801F45D8
    {
            ctx->lr = 0x801DD700u;
            ctx->pc = 0x801F45D8u;
            return;
    }

label_801DD700:
    ctx->pc = 0x801DD700u;
    ctx->downcount -= 1;
    // 801DD700: b       0x801DD708
    {
            goto label_801DD708;
    }

label_801DD704:
    ctx->pc = 0x801DD704u;
    ctx->downcount -= 1;
    // 801DD704: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD708:
    ctx->pc = 0x801DD708u;
    ctx->downcount -= 5;
    // 801DD708: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD70C:
    ctx->pc = 0x801DD70Cu;
    // 801DD70C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD710:
    ctx->pc = 0x801DD710u;
    // 801DD710: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD714:
    ctx->pc = 0x801DD714u;
    // 801DD714: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD718:
    ctx->pc = 0x801DD718u;
    ctx->downcount -= 11;
    // 801DD718: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD71C:
    ctx->pc = 0x801DD71Cu;
    // 801DD71C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD720:
    ctx->pc = 0x801DD720u;
    // 801DD720: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD724:
    ctx->pc = 0x801DD724u;
    // 801DD724: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD728:
    ctx->pc = 0x801DD728u;
    // 801DD728: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_801DD72C:
    ctx->pc = 0x801DD72Cu;
    // 801DD72C: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD730:
    ctx->pc = 0x801DD730u;
    // 801DD730: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD734:
    ctx->pc = 0x801DD734u;
    // 801DD734: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD738:
    ctx->pc = 0x801DD738u;
    // 801DD738: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD73C:
    ctx->pc = 0x801DD73Cu;
    // 801DD73C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD740u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD740:
    ctx->pc = 0x801DD740u;
    ctx->downcount -= 2;
    // 801DD740: or.   r3, r3, r3
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

label_801DD744:
    ctx->pc = 0x801DD744u;
    // 801DD744: bc    12, 2, 0x801DD750
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD750;
        }
    }

label_801DD748:
    ctx->pc = 0x801DD748u;
    ctx->downcount -= 1;
    // 801DD748: bl      0x801F4480
    {
            ctx->lr = 0x801DD74Cu;
            ctx->pc = 0x801F4480u;
            return;
    }

label_801DD74C:
    ctx->pc = 0x801DD74Cu;
    ctx->downcount -= 1;
    // 801DD74C: b       0x801DD754
    {
            goto label_801DD754;
    }

label_801DD750:
    ctx->pc = 0x801DD750u;
    ctx->downcount -= 1;
    // 801DD750: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD754:
    ctx->pc = 0x801DD754u;
    ctx->downcount -= 5;
    // 801DD754: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD758:
    ctx->pc = 0x801DD758u;
    // 801DD758: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD75C:
    ctx->pc = 0x801DD75Cu;
    // 801DD75C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD760:
    ctx->pc = 0x801DD760u;
    // 801DD760: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD764:
    ctx->pc = 0x801DD764u;
    ctx->downcount -= 11;
    // 801DD764: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD768:
    ctx->pc = 0x801DD768u;
    // 801DD768: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD76C:
    ctx->pc = 0x801DD76Cu;
    // 801DD76C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD770:
    ctx->pc = 0x801DD770u;
    // 801DD770: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD774:
    ctx->pc = 0x801DD774u;
    // 801DD774: li      r4, 44
    ctx->gpr[4] = (u32)(s32)(44);

label_801DD778:
    ctx->pc = 0x801DD778u;
    // 801DD778: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD77C:
    ctx->pc = 0x801DD77Cu;
    // 801DD77C: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD780:
    ctx->pc = 0x801DD780u;
    // 801DD780: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD784:
    ctx->pc = 0x801DD784u;
    // 801DD784: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD788:
    ctx->pc = 0x801DD788u;
    // 801DD788: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD78Cu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD78C:
    ctx->pc = 0x801DD78Cu;
    ctx->downcount -= 2;
    // 801DD78C: or.   r3, r3, r3
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

label_801DD790:
    ctx->pc = 0x801DD790u;
    // 801DD790: bc    12, 2, 0x801DD79C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD79C;
        }
    }

label_801DD794:
    ctx->pc = 0x801DD794u;
    ctx->downcount -= 1;
    // 801DD794: bl      0x801F41A8
    {
            ctx->lr = 0x801DD798u;
            ctx->pc = 0x801F41A8u;
            return;
    }

label_801DD798:
    ctx->pc = 0x801DD798u;
    ctx->downcount -= 1;
    // 801DD798: b       0x801DD7A0
    {
            goto label_801DD7A0;
    }

label_801DD79C:
    ctx->pc = 0x801DD79Cu;
    ctx->downcount -= 1;
    // 801DD79C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD7A0:
    ctx->pc = 0x801DD7A0u;
    ctx->downcount -= 5;
    // 801DD7A0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD7A4:
    ctx->pc = 0x801DD7A4u;
    // 801DD7A4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD7A8:
    ctx->pc = 0x801DD7A8u;
    // 801DD7A8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD7AC:
    ctx->pc = 0x801DD7ACu;
    // 801DD7AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD7B0:
    ctx->pc = 0x801DD7B0u;
    ctx->downcount -= 11;
    // 801DD7B0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD7B4:
    ctx->pc = 0x801DD7B4u;
    // 801DD7B4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD7B8:
    ctx->pc = 0x801DD7B8u;
    // 801DD7B8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD7BC:
    ctx->pc = 0x801DD7BCu;
    // 801DD7BC: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD7C0:
    ctx->pc = 0x801DD7C0u;
    // 801DD7C0: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD7C4:
    ctx->pc = 0x801DD7C4u;
    // 801DD7C4: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD7C8:
    ctx->pc = 0x801DD7C8u;
    // 801DD7C8: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD7CC:
    ctx->pc = 0x801DD7CCu;
    // 801DD7CC: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD7D0:
    ctx->pc = 0x801DD7D0u;
    // 801DD7D0: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD7D4:
    ctx->pc = 0x801DD7D4u;
    // 801DD7D4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD7D8u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD7D8:
    ctx->pc = 0x801DD7D8u;
    ctx->downcount -= 2;
    // 801DD7D8: or.   r3, r3, r3
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

label_801DD7DC:
    ctx->pc = 0x801DD7DCu;
    // 801DD7DC: bc    12, 2, 0x801DD7E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD7E8;
        }
    }

label_801DD7E0:
    ctx->pc = 0x801DD7E0u;
    ctx->downcount -= 1;
    // 801DD7E0: bl      0x801F3DB4
    {
            ctx->lr = 0x801DD7E4u;
            ctx->pc = 0x801F3DB4u;
            return;
    }

label_801DD7E4:
    ctx->pc = 0x801DD7E4u;
    ctx->downcount -= 1;
    // 801DD7E4: b       0x801DD7EC
    {
            goto label_801DD7EC;
    }

label_801DD7E8:
    ctx->pc = 0x801DD7E8u;
    ctx->downcount -= 1;
    // 801DD7E8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD7EC:
    ctx->pc = 0x801DD7ECu;
    ctx->downcount -= 5;
    // 801DD7EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD7F0:
    ctx->pc = 0x801DD7F0u;
    // 801DD7F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD7F4:
    ctx->pc = 0x801DD7F4u;
    // 801DD7F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD7F8:
    ctx->pc = 0x801DD7F8u;
    // 801DD7F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD7FC:
    ctx->pc = 0x801DD7FCu;
    ctx->downcount -= 11;
    // 801DD7FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD800:
    ctx->pc = 0x801DD800u;
    // 801DD800: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD804:
    ctx->pc = 0x801DD804u;
    // 801DD804: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD808:
    ctx->pc = 0x801DD808u;
    // 801DD808: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD80C:
    ctx->pc = 0x801DD80Cu;
    // 801DD80C: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD810:
    ctx->pc = 0x801DD810u;
    // 801DD810: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD814:
    ctx->pc = 0x801DD814u;
    // 801DD814: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD818:
    ctx->pc = 0x801DD818u;
    // 801DD818: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD81C:
    ctx->pc = 0x801DD81Cu;
    // 801DD81C: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD820:
    ctx->pc = 0x801DD820u;
    // 801DD820: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD824u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD824:
    ctx->pc = 0x801DD824u;
    ctx->downcount -= 2;
    // 801DD824: or.   r3, r3, r3
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

label_801DD828:
    ctx->pc = 0x801DD828u;
    // 801DD828: bc    12, 2, 0x801DD834
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD834;
        }
    }

label_801DD82C:
    ctx->pc = 0x801DD82Cu;
    ctx->downcount -= 1;
    // 801DD82C: bl      0x801F3764
    {
            ctx->lr = 0x801DD830u;
            ctx->pc = 0x801F3764u;
            return;
    }

label_801DD830:
    ctx->pc = 0x801DD830u;
    ctx->downcount -= 1;
    // 801DD830: b       0x801DD838
    {
            goto label_801DD838;
    }

label_801DD834:
    ctx->pc = 0x801DD834u;
    ctx->downcount -= 1;
    // 801DD834: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD838:
    ctx->pc = 0x801DD838u;
    ctx->downcount -= 5;
    // 801DD838: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD83C:
    ctx->pc = 0x801DD83Cu;
    // 801DD83C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD840:
    ctx->pc = 0x801DD840u;
    // 801DD840: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD844:
    ctx->pc = 0x801DD844u;
    // 801DD844: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD848:
    ctx->pc = 0x801DD848u;
    ctx->downcount -= 11;
    // 801DD848: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD84C:
    ctx->pc = 0x801DD84Cu;
    // 801DD84C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD850:
    ctx->pc = 0x801DD850u;
    // 801DD850: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD854:
    ctx->pc = 0x801DD854u;
    // 801DD854: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD858:
    ctx->pc = 0x801DD858u;
    // 801DD858: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD85C:
    ctx->pc = 0x801DD85Cu;
    // 801DD85C: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD860:
    ctx->pc = 0x801DD860u;
    // 801DD860: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD864:
    ctx->pc = 0x801DD864u;
    // 801DD864: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD868:
    ctx->pc = 0x801DD868u;
    // 801DD868: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD86C:
    ctx->pc = 0x801DD86Cu;
    // 801DD86C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD870u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD870:
    ctx->pc = 0x801DD870u;
    ctx->downcount -= 2;
    // 801DD870: or.   r3, r3, r3
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

label_801DD874:
    ctx->pc = 0x801DD874u;
    // 801DD874: bc    12, 2, 0x801DD880
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD880;
        }
    }

label_801DD878:
    ctx->pc = 0x801DD878u;
    ctx->downcount -= 1;
    // 801DD878: bl      0x801F3AF8
    {
            ctx->lr = 0x801DD87Cu;
            ctx->pc = 0x801F3AF8u;
            return;
    }

label_801DD87C:
    ctx->pc = 0x801DD87Cu;
    ctx->downcount -= 1;
    // 801DD87C: b       0x801DD884
    {
            goto label_801DD884;
    }

label_801DD880:
    ctx->pc = 0x801DD880u;
    ctx->downcount -= 1;
    // 801DD880: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD884:
    ctx->pc = 0x801DD884u;
    ctx->downcount -= 5;
    // 801DD884: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD888:
    ctx->pc = 0x801DD888u;
    // 801DD888: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD88C:
    ctx->pc = 0x801DD88Cu;
    // 801DD88C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD890:
    ctx->pc = 0x801DD890u;
    // 801DD890: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD894:
    ctx->pc = 0x801DD894u;
    ctx->downcount -= 11;
    // 801DD894: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD898:
    ctx->pc = 0x801DD898u;
    // 801DD898: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD89C:
    ctx->pc = 0x801DD89Cu;
    // 801DD89C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD8A0:
    ctx->pc = 0x801DD8A0u;
    // 801DD8A0: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD8A4:
    ctx->pc = 0x801DD8A4u;
    // 801DD8A4: li      r4, 96
    ctx->gpr[4] = (u32)(s32)(96);

label_801DD8A8:
    ctx->pc = 0x801DD8A8u;
    // 801DD8A8: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD8AC:
    ctx->pc = 0x801DD8ACu;
    // 801DD8AC: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD8B0:
    ctx->pc = 0x801DD8B0u;
    // 801DD8B0: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD8B4:
    ctx->pc = 0x801DD8B4u;
    // 801DD8B4: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD8B8:
    ctx->pc = 0x801DD8B8u;
    // 801DD8B8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD8BCu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD8BC:
    ctx->pc = 0x801DD8BCu;
    ctx->downcount -= 2;
    // 801DD8BC: or.   r3, r3, r3
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

label_801DD8C0:
    ctx->pc = 0x801DD8C0u;
    // 801DD8C0: bc    12, 2, 0x801DD8CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD8CC;
        }
    }

label_801DD8C4:
    ctx->pc = 0x801DD8C4u;
    ctx->downcount -= 1;
    // 801DD8C4: bl      0x80200594
    {
            ctx->lr = 0x801DD8C8u;
            ctx->pc = 0x80200594u;
            return;
    }

label_801DD8C8:
    ctx->pc = 0x801DD8C8u;
    ctx->downcount -= 1;
    // 801DD8C8: b       0x801DD8D0
    {
            goto label_801DD8D0;
    }

label_801DD8CC:
    ctx->pc = 0x801DD8CCu;
    ctx->downcount -= 1;
    // 801DD8CC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD8D0:
    ctx->pc = 0x801DD8D0u;
    ctx->downcount -= 5;
    // 801DD8D0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD8D4:
    ctx->pc = 0x801DD8D4u;
    // 801DD8D4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD8D8:
    ctx->pc = 0x801DD8D8u;
    // 801DD8D8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD8DC:
    ctx->pc = 0x801DD8DCu;
    // 801DD8DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD8E0:
    ctx->pc = 0x801DD8E0u;
    ctx->downcount -= 12;
    // 801DD8E0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD8E4:
    ctx->pc = 0x801DD8E4u;
    // 801DD8E4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD8E8:
    ctx->pc = 0x801DD8E8u;
    // 801DD8E8: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DD8EC:
    ctx->pc = 0x801DD8ECu;
    // 801DD8EC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD8F0:
    ctx->pc = 0x801DD8F0u;
    // 801DD8F0: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD8F4:
    ctx->pc = 0x801DD8F4u;
    // 801DD8F4: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD8F8:
    ctx->pc = 0x801DD8F8u;
    // 801DD8F8: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD8FC:
    ctx->pc = 0x801DD8FCu;
    // 801DD8FC: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD900:
    ctx->pc = 0x801DD900u;
    // 801DD900: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD904:
    ctx->pc = 0x801DD904u;
    // 801DD904: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD908:
    ctx->pc = 0x801DD908u;
    // 801DD908: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD90Cu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD90C:
    ctx->pc = 0x801DD90Cu;
    ctx->downcount -= 2;
    // 801DD90C: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DD910:
    ctx->pc = 0x801DD910u;
    // 801DD910: bc    12, 2, 0x801DD938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD938;
        }
    }

label_801DD914:
    ctx->pc = 0x801DD914u;
    ctx->downcount -= 2;
    // 801DD914: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD918:
    ctx->pc = 0x801DD918u;
    // 801DD918: bl      0x801D1410
    {
            ctx->lr = 0x801DD91Cu;
            ctx->pc = 0x801D1410u;
            return;
    }

label_801DD91C:
    ctx->pc = 0x801DD91Cu;
    ctx->downcount -= 7;
    // 801DD91C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DD920:
    ctx->pc = 0x801DD920u;
    // 801DD920: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DD924:
    ctx->pc = 0x801DD924u;
    // 801DD924: addi    r9, r9, 13088
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13088);

label_801DD928:
    ctx->pc = 0x801DD928u;
    // 801DD928: stw     r0, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD92C:
    ctx->pc = 0x801DD92Cu;
    // 801DD92C: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DD930:
    ctx->pc = 0x801DD930u;
    // 801DD930: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD934:
    ctx->pc = 0x801DD934u;
    // 801DD934: b       0x801DD93C
    {
            goto label_801DD93C;
    }

label_801DD938:
    ctx->pc = 0x801DD938u;
    ctx->downcount -= 1;
    // 801DD938: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD93C:
    ctx->pc = 0x801DD93Cu;
    ctx->downcount -= 6;
    // 801DD93C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD940:
    ctx->pc = 0x801DD940u;
    // 801DD940: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD944:
    ctx->pc = 0x801DD944u;
    // 801DD944: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DD948:
    ctx->pc = 0x801DD948u;
    // 801DD948: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DD94C:
    ctx->pc = 0x801DD94Cu;
    // 801DD94C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD950:
    ctx->pc = 0x801DD950u;
    ctx->downcount -= 11;
    // 801DD950: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD954:
    ctx->pc = 0x801DD954u;
    // 801DD954: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD958:
    ctx->pc = 0x801DD958u;
    // 801DD958: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD95C:
    ctx->pc = 0x801DD95Cu;
    // 801DD95C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD960:
    ctx->pc = 0x801DD960u;
    // 801DD960: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DD964:
    ctx->pc = 0x801DD964u;
    // 801DD964: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD968:
    ctx->pc = 0x801DD968u;
    // 801DD968: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD96C:
    ctx->pc = 0x801DD96Cu;
    // 801DD96C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD970:
    ctx->pc = 0x801DD970u;
    // 801DD970: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD974:
    ctx->pc = 0x801DD974u;
    // 801DD974: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD978u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD978:
    ctx->pc = 0x801DD978u;
    ctx->downcount -= 2;
    // 801DD978: or.   r3, r3, r3
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

label_801DD97C:
    ctx->pc = 0x801DD97Cu;
    // 801DD97C: bc    12, 2, 0x801DD988
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DD988;
        }
    }

label_801DD980:
    ctx->pc = 0x801DD980u;
    ctx->downcount -= 1;
    // 801DD980: bl      0x801F4D28
    {
            ctx->lr = 0x801DD984u;
            ctx->pc = 0x801F4D28u;
            return;
    }

label_801DD984:
    ctx->pc = 0x801DD984u;
    ctx->downcount -= 1;
    // 801DD984: b       0x801DD98C
    {
            goto label_801DD98C;
    }

label_801DD988:
    ctx->pc = 0x801DD988u;
    ctx->downcount -= 1;
    // 801DD988: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DD98C:
    ctx->pc = 0x801DD98Cu;
    ctx->downcount -= 5;
    // 801DD98C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DD990:
    ctx->pc = 0x801DD990u;
    // 801DD990: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DD994:
    ctx->pc = 0x801DD994u;
    // 801DD994: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DD998:
    ctx->pc = 0x801DD998u;
    // 801DD998: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD99C:
    ctx->pc = 0x801DD99Cu;
    ctx->downcount -= 12;
    // 801DD99C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DD9A0:
    ctx->pc = 0x801DD9A0u;
    // 801DD9A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DD9A4:
    ctx->pc = 0x801DD9A4u;
    // 801DD9A4: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DD9A8:
    ctx->pc = 0x801DD9A8u;
    // 801DD9A8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD9AC:
    ctx->pc = 0x801DD9ACu;
    // 801DD9AC: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD9B0:
    ctx->pc = 0x801DD9B0u;
    // 801DD9B0: li      r4, 64
    ctx->gpr[4] = (u32)(s32)(64);

label_801DD9B4:
    ctx->pc = 0x801DD9B4u;
    // 801DD9B4: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DD9B8:
    ctx->pc = 0x801DD9B8u;
    // 801DD9B8: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DD9BC:
    ctx->pc = 0x801DD9BCu;
    // 801DD9BC: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DD9C0:
    ctx->pc = 0x801DD9C0u;
    // 801DD9C0: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DD9C4:
    ctx->pc = 0x801DD9C4u;
    // 801DD9C4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DD9C8u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DD9C8:
    ctx->pc = 0x801DD9C8u;
    ctx->downcount -= 2;
    // 801DD9C8: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DD9CC:
    ctx->pc = 0x801DD9CCu;
    // 801DD9CC: bc    12, 2, 0x801DDA00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDA00;
        }
    }

label_801DD9D0:
    ctx->pc = 0x801DD9D0u;
    ctx->downcount -= 2;
    // 801DD9D0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD9D4:
    ctx->pc = 0x801DD9D4u;
    // 801DD9D4: bl      0x801D1410
    {
            ctx->lr = 0x801DD9D8u;
            ctx->pc = 0x801D1410u;
            return;
    }

label_801DD9D8:
    ctx->pc = 0x801DD9D8u;
    ctx->downcount -= 10;
    // 801DD9D8: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DD9DC:
    ctx->pc = 0x801DD9DCu;
    // 801DD9DC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DD9E0:
    ctx->pc = 0x801DD9E0u;
    // 801DD9E0: addi    r9, r9, 10944
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(10944);

label_801DD9E4:
    ctx->pc = 0x801DD9E4u;
    // 801DD9E4: stw     r0, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD9E8:
    ctx->pc = 0x801DD9E8u;
    // 801DD9E8: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DD9EC:
    ctx->pc = 0x801DD9ECu;
    // 801DD9EC: addi    r11, r31, 56
    ctx->gpr[11] = ctx->gpr[31] + (u32)(s32)(56);

label_801DD9F0:
    ctx->pc = 0x801DD9F0u;
    // 801DD9F0: stw     r0, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD9F4:
    ctx->pc = 0x801DD9F4u;
    // 801DD9F4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DD9F8:
    ctx->pc = 0x801DD9F8u;
    // 801DD9F8: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DD9FC:
    ctx->pc = 0x801DD9FCu;
    // 801DD9FC: b       0x801DDA04
    {
            goto label_801DDA04;
    }

label_801DDA00:
    ctx->pc = 0x801DDA00u;
    ctx->downcount -= 1;
    // 801DDA00: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDA04:
    ctx->pc = 0x801DDA04u;
    ctx->downcount -= 6;
    // 801DDA04: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDA08:
    ctx->pc = 0x801DDA08u;
    // 801DDA08: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDA0C:
    ctx->pc = 0x801DDA0Cu;
    // 801DDA0C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DDA10:
    ctx->pc = 0x801DDA10u;
    // 801DDA10: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DDA14:
    ctx->pc = 0x801DDA14u;
    // 801DDA14: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDA18:
    ctx->pc = 0x801DDA18u;
    ctx->downcount -= 12;
    // 801DDA18: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDA1C:
    ctx->pc = 0x801DDA1Cu;
    // 801DDA1C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDA20:
    ctx->pc = 0x801DDA20u;
    // 801DDA20: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DDA24:
    ctx->pc = 0x801DDA24u;
    // 801DDA24: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDA28:
    ctx->pc = 0x801DDA28u;
    // 801DDA28: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDA2C:
    ctx->pc = 0x801DDA2Cu;
    // 801DDA2C: li      r4, 56
    ctx->gpr[4] = (u32)(s32)(56);

label_801DDA30:
    ctx->pc = 0x801DDA30u;
    // 801DDA30: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDA34:
    ctx->pc = 0x801DDA34u;
    // 801DDA34: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDA38:
    ctx->pc = 0x801DDA38u;
    // 801DDA38: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDA3C:
    ctx->pc = 0x801DDA3Cu;
    // 801DDA3C: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDA40:
    ctx->pc = 0x801DDA40u;
    // 801DDA40: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDA44u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDA44:
    ctx->pc = 0x801DDA44u;
    ctx->downcount -= 2;
    // 801DDA44: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DDA48:
    ctx->pc = 0x801DDA48u;
    // 801DDA48: bc    12, 2, 0x801DDA74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDA74;
        }
    }

label_801DDA4C:
    ctx->pc = 0x801DDA4Cu;
    ctx->downcount -= 2;
    // 801DDA4C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDA50:
    ctx->pc = 0x801DDA50u;
    // 801DDA50: bl      0x801D1410
    {
            ctx->lr = 0x801DDA54u;
            ctx->pc = 0x801D1410u;
            return;
    }

label_801DDA54:
    ctx->pc = 0x801DDA54u;
    ctx->downcount -= 8;
    // 801DDA54: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DDA58:
    ctx->pc = 0x801DDA58u;
    // 801DDA58: addi    r11, r31, 36
    ctx->gpr[11] = ctx->gpr[31] + (u32)(s32)(36);

label_801DDA5C:
    ctx->pc = 0x801DDA5Cu;
    // 801DDA5C: addi    r9, r9, 11328
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(11328);

label_801DDA60:
    ctx->pc = 0x801DDA60u;
    // 801DDA60: stw     r11, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DDA64:
    ctx->pc = 0x801DDA64u;
    // 801DDA64: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DDA68:
    ctx->pc = 0x801DDA68u;
    // 801DDA68: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDA6C:
    ctx->pc = 0x801DDA6Cu;
    // 801DDA6C: stw     r11, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DDA70:
    ctx->pc = 0x801DDA70u;
    // 801DDA70: b       0x801DDA78
    {
            goto label_801DDA78;
    }

label_801DDA74:
    ctx->pc = 0x801DDA74u;
    ctx->downcount -= 1;
    // 801DDA74: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDA78:
    ctx->pc = 0x801DDA78u;
    ctx->downcount -= 6;
    // 801DDA78: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDA7C:
    ctx->pc = 0x801DDA7Cu;
    // 801DDA7C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDA80:
    ctx->pc = 0x801DDA80u;
    // 801DDA80: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DDA84:
    ctx->pc = 0x801DDA84u;
    // 801DDA84: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DDA88:
    ctx->pc = 0x801DDA88u;
    // 801DDA88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDA8C:
    ctx->pc = 0x801DDA8Cu;
    ctx->downcount -= 12;
    // 801DDA8C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDA90:
    ctx->pc = 0x801DDA90u;
    // 801DDA90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDA94:
    ctx->pc = 0x801DDA94u;
    // 801DDA94: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DDA98:
    ctx->pc = 0x801DDA98u;
    // 801DDA98: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDA9C:
    ctx->pc = 0x801DDA9Cu;
    // 801DDA9C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDAA0:
    ctx->pc = 0x801DDAA0u;
    // 801DDAA0: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DDAA4:
    ctx->pc = 0x801DDAA4u;
    // 801DDAA4: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDAA8:
    ctx->pc = 0x801DDAA8u;
    // 801DDAA8: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDAAC:
    ctx->pc = 0x801DDAACu;
    // 801DDAAC: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDAB0:
    ctx->pc = 0x801DDAB0u;
    // 801DDAB0: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDAB4:
    ctx->pc = 0x801DDAB4u;
    // 801DDAB4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDAB8u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDAB8:
    ctx->pc = 0x801DDAB8u;
    ctx->downcount -= 2;
    // 801DDAB8: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DDABC:
    ctx->pc = 0x801DDABCu;
    // 801DDABC: bc    12, 2, 0x801DDADC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDADC;
        }
    }

label_801DDAC0:
    ctx->pc = 0x801DDAC0u;
    ctx->downcount -= 2;
    // 801DDAC0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDAC4:
    ctx->pc = 0x801DDAC4u;
    // 801DDAC4: bl      0x801E7708
    {
            ctx->lr = 0x801DDAC8u;
            ctx->pc = 0x801E7708u;
            return;
    }

label_801DDAC8:
    ctx->pc = 0x801DDAC8u;
    ctx->downcount -= 5;
    // 801DDAC8: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DDACC:
    ctx->pc = 0x801DDACCu;
    // 801DDACC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDAD0:
    ctx->pc = 0x801DDAD0u;
    // 801DDAD0: addi    r9, r9, 12704
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(12704);

label_801DDAD4:
    ctx->pc = 0x801DDAD4u;
    // 801DDAD4: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DDAD8:
    ctx->pc = 0x801DDAD8u;
    // 801DDAD8: b       0x801DDAE0
    {
            goto label_801DDAE0;
    }

label_801DDADC:
    ctx->pc = 0x801DDADCu;
    ctx->downcount -= 1;
    // 801DDADC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDAE0:
    ctx->pc = 0x801DDAE0u;
    ctx->downcount -= 6;
    // 801DDAE0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDAE4:
    ctx->pc = 0x801DDAE4u;
    // 801DDAE4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDAE8:
    ctx->pc = 0x801DDAE8u;
    // 801DDAE8: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DDAEC:
    ctx->pc = 0x801DDAECu;
    // 801DDAEC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DDAF0:
    ctx->pc = 0x801DDAF0u;
    // 801DDAF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDAF4:
    ctx->pc = 0x801DDAF4u;
    ctx->downcount -= 12;
    // 801DDAF4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDAF8:
    ctx->pc = 0x801DDAF8u;
    // 801DDAF8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDAFC:
    ctx->pc = 0x801DDAFCu;
    // 801DDAFC: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DDB00:
    ctx->pc = 0x801DDB00u;
    // 801DDB00: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDB04:
    ctx->pc = 0x801DDB04u;
    // 801DDB04: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDB08:
    ctx->pc = 0x801DDB08u;
    // 801DDB08: li      r4, 76
    ctx->gpr[4] = (u32)(s32)(76);

label_801DDB0C:
    ctx->pc = 0x801DDB0Cu;
    // 801DDB0C: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDB10:
    ctx->pc = 0x801DDB10u;
    // 801DDB10: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDB14:
    ctx->pc = 0x801DDB14u;
    // 801DDB14: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDB18:
    ctx->pc = 0x801DDB18u;
    // 801DDB18: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDB1C:
    ctx->pc = 0x801DDB1Cu;
    // 801DDB1C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDB20u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDB20:
    ctx->pc = 0x801DDB20u;
    ctx->downcount -= 2;
    // 801DDB20: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DDB24:
    ctx->pc = 0x801DDB24u;
    // 801DDB24: bc    12, 2, 0x801DDB4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDB4C;
        }
    }

label_801DDB28:
    ctx->pc = 0x801DDB28u;
    ctx->downcount -= 2;
    // 801DDB28: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDB2C:
    ctx->pc = 0x801DDB2Cu;
    // 801DDB2C: bl      0x801D1410
    {
            ctx->lr = 0x801DDB30u;
            ctx->pc = 0x801D1410u;
            return;
    }

label_801DDB30:
    ctx->pc = 0x801DDB30u;
    ctx->downcount -= 5;
    // 801DDB30: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DDB34:
    ctx->pc = 0x801DDB34u;
    // 801DDB34: addi    r3, r31, 36
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(36);

label_801DDB38:
    ctx->pc = 0x801DDB38u;
    // 801DDB38: addi    r9, r9, 11520
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(11520);

label_801DDB3C:
    ctx->pc = 0x801DDB3Cu;
    // 801DDB3C: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DDB40:
    ctx->pc = 0x801DDB40u;
    // 801DDB40: bl      0x802871CC
    {
            ctx->lr = 0x801DDB44u;
            ctx->pc = 0x802871CCu;
            return;
    }

label_801DDB44:
    ctx->pc = 0x801DDB44u;
    ctx->downcount -= 2;
    // 801DDB44: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDB48:
    ctx->pc = 0x801DDB48u;
    // 801DDB48: b       0x801DDB50
    {
            goto label_801DDB50;
    }

label_801DDB4C:
    ctx->pc = 0x801DDB4Cu;
    ctx->downcount -= 1;
    // 801DDB4C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDB50:
    ctx->pc = 0x801DDB50u;
    ctx->downcount -= 6;
    // 801DDB50: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDB54:
    ctx->pc = 0x801DDB54u;
    // 801DDB54: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDB58:
    ctx->pc = 0x801DDB58u;
    // 801DDB58: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DDB5C:
    ctx->pc = 0x801DDB5Cu;
    // 801DDB5C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DDB60:
    ctx->pc = 0x801DDB60u;
    // 801DDB60: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDB64:
    ctx->pc = 0x801DDB64u;
    ctx->downcount -= 12;
    // 801DDB64: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDB68:
    ctx->pc = 0x801DDB68u;
    // 801DDB68: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDB6C:
    ctx->pc = 0x801DDB6Cu;
    // 801DDB6C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DDB70:
    ctx->pc = 0x801DDB70u;
    // 801DDB70: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDB74:
    ctx->pc = 0x801DDB74u;
    // 801DDB74: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDB78:
    ctx->pc = 0x801DDB78u;
    // 801DDB78: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_801DDB7C:
    ctx->pc = 0x801DDB7Cu;
    // 801DDB7C: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDB80:
    ctx->pc = 0x801DDB80u;
    // 801DDB80: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDB84:
    ctx->pc = 0x801DDB84u;
    // 801DDB84: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDB88:
    ctx->pc = 0x801DDB88u;
    // 801DDB88: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDB8C:
    ctx->pc = 0x801DDB8Cu;
    // 801DDB8C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDB90u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDB90:
    ctx->pc = 0x801DDB90u;
    ctx->downcount -= 2;
    // 801DDB90: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DDB94:
    ctx->pc = 0x801DDB94u;
    // 801DDB94: bc    12, 2, 0x801DDBB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDBB4;
        }
    }

label_801DDB98:
    ctx->pc = 0x801DDB98u;
    ctx->downcount -= 2;
    // 801DDB98: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDB9C:
    ctx->pc = 0x801DDB9Cu;
    // 801DDB9C: bl      0x801E7708
    {
            ctx->lr = 0x801DDBA0u;
            ctx->pc = 0x801E7708u;
            return;
    }

label_801DDBA0:
    ctx->pc = 0x801DDBA0u;
    ctx->downcount -= 5;
    // 801DDBA0: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DDBA4:
    ctx->pc = 0x801DDBA4u;
    // 801DDBA4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDBA8:
    ctx->pc = 0x801DDBA8u;
    // 801DDBA8: addi    r9, r9, 26856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(26856);

label_801DDBAC:
    ctx->pc = 0x801DDBACu;
    // 801DDBAC: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DDBB0:
    ctx->pc = 0x801DDBB0u;
    // 801DDBB0: b       0x801DDBB8
    {
            goto label_801DDBB8;
    }

label_801DDBB4:
    ctx->pc = 0x801DDBB4u;
    ctx->downcount -= 1;
    // 801DDBB4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDBB8:
    ctx->pc = 0x801DDBB8u;
    ctx->downcount -= 6;
    // 801DDBB8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDBBC:
    ctx->pc = 0x801DDBBCu;
    // 801DDBBC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDBC0:
    ctx->pc = 0x801DDBC0u;
    // 801DDBC0: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DDBC4:
    ctx->pc = 0x801DDBC4u;
    // 801DDBC4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DDBC8:
    ctx->pc = 0x801DDBC8u;
    // 801DDBC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDBCC:
    ctx->pc = 0x801DDBCCu;
    ctx->downcount -= 11;
    // 801DDBCC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDBD0:
    ctx->pc = 0x801DDBD0u;
    // 801DDBD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDBD4:
    ctx->pc = 0x801DDBD4u;
    // 801DDBD4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDBD8:
    ctx->pc = 0x801DDBD8u;
    // 801DDBD8: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDBDC:
    ctx->pc = 0x801DDBDCu;
    // 801DDBDC: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_801DDBE0:
    ctx->pc = 0x801DDBE0u;
    // 801DDBE0: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDBE4:
    ctx->pc = 0x801DDBE4u;
    // 801DDBE4: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDBE8:
    ctx->pc = 0x801DDBE8u;
    // 801DDBE8: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDBEC:
    ctx->pc = 0x801DDBECu;
    // 801DDBEC: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDBF0:
    ctx->pc = 0x801DDBF0u;
    // 801DDBF0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDBF4u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDBF4:
    ctx->pc = 0x801DDBF4u;
    ctx->downcount -= 2;
    // 801DDBF4: or.   r3, r3, r3
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

label_801DDBF8:
    ctx->pc = 0x801DDBF8u;
    // 801DDBF8: bc    12, 2, 0x801DDC04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDC04;
        }
    }

label_801DDBFC:
    ctx->pc = 0x801DDBFCu;
    ctx->downcount -= 1;
    // 801DDBFC: bl      0x80216978
    {
            ctx->lr = 0x801DDC00u;
            ctx->pc = 0x80216978u;
            return;
    }

label_801DDC00:
    ctx->pc = 0x801DDC00u;
    ctx->downcount -= 1;
    // 801DDC00: b       0x801DDC08
    {
            goto label_801DDC08;
    }

label_801DDC04:
    ctx->pc = 0x801DDC04u;
    ctx->downcount -= 1;
    // 801DDC04: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDC08:
    ctx->pc = 0x801DDC08u;
    ctx->downcount -= 5;
    // 801DDC08: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDC0C:
    ctx->pc = 0x801DDC0Cu;
    // 801DDC0C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDC10:
    ctx->pc = 0x801DDC10u;
    // 801DDC10: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DDC14:
    ctx->pc = 0x801DDC14u;
    // 801DDC14: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDC18:
    ctx->pc = 0x801DDC18u;
    ctx->downcount -= 11;
    // 801DDC18: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDC1C:
    ctx->pc = 0x801DDC1Cu;
    // 801DDC1C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDC20:
    ctx->pc = 0x801DDC20u;
    // 801DDC20: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDC24:
    ctx->pc = 0x801DDC24u;
    // 801DDC24: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDC28:
    ctx->pc = 0x801DDC28u;
    // 801DDC28: li      r4, 64
    ctx->gpr[4] = (u32)(s32)(64);

label_801DDC2C:
    ctx->pc = 0x801DDC2Cu;
    // 801DDC2C: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDC30:
    ctx->pc = 0x801DDC30u;
    // 801DDC30: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDC34:
    ctx->pc = 0x801DDC34u;
    // 801DDC34: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDC38:
    ctx->pc = 0x801DDC38u;
    // 801DDC38: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDC3C:
    ctx->pc = 0x801DDC3Cu;
    // 801DDC3C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDC40u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDC40:
    ctx->pc = 0x801DDC40u;
    ctx->downcount -= 2;
    // 801DDC40: or.   r3, r3, r3
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

label_801DDC44:
    ctx->pc = 0x801DDC44u;
    // 801DDC44: bc    12, 2, 0x801DDC50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDC50;
        }
    }

label_801DDC48:
    ctx->pc = 0x801DDC48u;
    ctx->downcount -= 1;
    // 801DDC48: bl      0x801F340C
    {
            ctx->lr = 0x801DDC4Cu;
            ctx->pc = 0x801F340Cu;
            return;
    }

label_801DDC4C:
    ctx->pc = 0x801DDC4Cu;
    ctx->downcount -= 1;
    // 801DDC4C: b       0x801DDC54
    {
            goto label_801DDC54;
    }

label_801DDC50:
    ctx->pc = 0x801DDC50u;
    ctx->downcount -= 1;
    // 801DDC50: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDC54:
    ctx->pc = 0x801DDC54u;
    ctx->downcount -= 5;
    // 801DDC54: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDC58:
    ctx->pc = 0x801DDC58u;
    // 801DDC58: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDC5C:
    ctx->pc = 0x801DDC5Cu;
    // 801DDC5C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DDC60:
    ctx->pc = 0x801DDC60u;
    // 801DDC60: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDC64:
    ctx->pc = 0x801DDC64u;
    ctx->downcount -= 22;
    // 801DDC64: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDC68:
    ctx->pc = 0x801DDC68u;
    // 801DDC68: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDC6C:
    ctx->pc = 0x801DDC6Cu;
    // 801DDC6C: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DDC70:
    ctx->pc = 0x801DDC70u;
    // 801DDC70: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDC74:
    ctx->pc = 0x801DDC74u;
    // 801DDC74: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDC78:
    ctx->pc = 0x801DDC78u;
    // 801DDC78: li      r4, 88
    ctx->gpr[4] = (u32)(s32)(88);

label_801DDC7C:
    ctx->pc = 0x801DDC7Cu;
    // 801DDC7C: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDC80:
    ctx->pc = 0x801DDC80u;
    // 801DDC80: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDC84:
    ctx->pc = 0x801DDC84u;
    // 801DDC84: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDC88:
    ctx->pc = 0x801DDC88u;
    // 801DDC88: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDC8C:
    ctx->pc = 0x801DDC8Cu;
    // 801DDC8C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDC90u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDC90:
    ctx->pc = 0x801DDC90u;
    ctx->downcount -= 2;
    // 801DDC90: or.   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[28];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DDC94:
    ctx->pc = 0x801DDC94u;
    // 801DDC94: bc    12, 2, 0x801DDCDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDCDC;
        }
    }

label_801DDC98:
    ctx->pc = 0x801DDC98u;
    ctx->downcount -= 5;
    // 801DDC98: or   r30, r28, r28
    {
        ctx->gpr[30] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801DDC9C:
    ctx->pc = 0x801DDC9Cu;
    // 801DDC9C: li      r29, 4
    ctx->gpr[29] = (u32)(s32)(4);

label_801DDCA0:
    ctx->pc = 0x801DDCA0u;
    // 801DDCA0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DDCA4:
    ctx->pc = 0x801DDCA4u;
    // 801DDCA4: addi    r31, r30, 28
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(28);

label_801DDCA8:
    ctx->pc = 0x801DDCA8u;
    // 801DDCA8: bl      0x801E7708
    {
            ctx->lr = 0x801DDCACu;
            ctx->pc = 0x801E7708u;
            return;
    }

label_801DDCAC:
    ctx->pc = 0x801DDCACu;
    ctx->downcount -= 3;
    // 801DDCAC: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DDCB0:
    ctx->pc = 0x801DDCB0u;
    // 801DDCB0: addi    r9, r9, 16856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16856);

label_801DDCB4:
    ctx->pc = 0x801DDCB4u;
    // 801DDCB4: stw     r9, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DDCB8:
    ctx->downcount -= 3;
    // 801DDCB8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDCBC:
    // 801DDCBC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DDCC0:
    // 801DDCC0: bl      0x801C4BEC
    {
            ctx->lr = 0x801DDCC4u;
            ctx->pc = 0x801C4BECu;
            return;
    }

label_801DDCC4:
    ctx->downcount -= 4;
    // 801DDCC4: addi    r31, r31, 12
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(12);

label_801DDCC8:
    // 801DDCC8: cmpwi   r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DDCCC:
    // 801DDCCC: addi    r29, r29, -1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(-1);

label_801DDCD0:
    // 801DDCD0: bc    4, 2, 0x801DDCB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DDCB8u;
                return;
            }
            goto label_801DDCB8;
        }
    }

label_801DDCD4:
    ctx->pc = 0x801DDCD4u;
    ctx->downcount -= 2;
    // 801DDCD4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801DDCD8:
    ctx->pc = 0x801DDCD8u;
    // 801DDCD8: b       0x801DDCE0
    {
            goto label_801DDCE0;
    }

label_801DDCDC:
    ctx->pc = 0x801DDCDCu;
    ctx->downcount -= 1;
    // 801DDCDC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDCE0:
    ctx->pc = 0x801DDCE0u;
    ctx->downcount -= 16;
    // 801DDCE0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDCE4:
    ctx->pc = 0x801DDCE4u;
    // 801DDCE4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDCE8:
    ctx->pc = 0x801DDCE8u;
    // 801DDCE8: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DDCEC:
    ctx->pc = 0x801DDCECu;
    // 801DDCEC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DDCF0:
    ctx->pc = 0x801DDCF0u;
    // 801DDCF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDCF4:
    ctx->pc = 0x801DDCF4u;
    ctx->downcount -= 12;
    // 801DDCF4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDCF8:
    ctx->pc = 0x801DDCF8u;
    // 801DDCF8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDCFC:
    ctx->pc = 0x801DDCFCu;
    // 801DDCFC: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DDD00:
    ctx->pc = 0x801DDD00u;
    // 801DDD00: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDD04:
    ctx->pc = 0x801DDD04u;
    // 801DDD04: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDD08:
    ctx->pc = 0x801DDD08u;
    // 801DDD08: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_801DDD0C:
    ctx->pc = 0x801DDD0Cu;
    // 801DDD0C: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDD10:
    ctx->pc = 0x801DDD10u;
    // 801DDD10: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDD14:
    ctx->pc = 0x801DDD14u;
    // 801DDD14: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDD18:
    ctx->pc = 0x801DDD18u;
    // 801DDD18: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDD1C:
    ctx->pc = 0x801DDD1Cu;
    // 801DDD1C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDD20u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDD20:
    ctx->pc = 0x801DDD20u;
    ctx->downcount -= 2;
    // 801DDD20: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DDD24:
    ctx->pc = 0x801DDD24u;
    // 801DDD24: bc    12, 2, 0x801DDD44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDD44;
        }
    }

label_801DDD28:
    ctx->pc = 0x801DDD28u;
    ctx->downcount -= 2;
    // 801DDD28: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDD2C:
    ctx->pc = 0x801DDD2Cu;
    // 801DDD2C: bl      0x801E7708
    {
            ctx->lr = 0x801DDD30u;
            ctx->pc = 0x801E7708u;
            return;
    }

label_801DDD30:
    ctx->pc = 0x801DDD30u;
    ctx->downcount -= 5;
    // 801DDD30: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DDD34:
    ctx->pc = 0x801DDD34u;
    // 801DDD34: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDD38:
    ctx->pc = 0x801DDD38u;
    // 801DDD38: addi    r9, r9, 16472
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16472);

label_801DDD3C:
    ctx->pc = 0x801DDD3Cu;
    // 801DDD3C: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DDD40:
    ctx->pc = 0x801DDD40u;
    // 801DDD40: b       0x801DDD48
    {
            goto label_801DDD48;
    }

label_801DDD44:
    ctx->pc = 0x801DDD44u;
    ctx->downcount -= 1;
    // 801DDD44: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDD48:
    ctx->pc = 0x801DDD48u;
    ctx->downcount -= 6;
    // 801DDD48: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDD4C:
    ctx->pc = 0x801DDD4Cu;
    // 801DDD4C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDD50:
    ctx->pc = 0x801DDD50u;
    // 801DDD50: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DDD54:
    ctx->pc = 0x801DDD54u;
    // 801DDD54: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DDD58:
    ctx->pc = 0x801DDD58u;
    // 801DDD58: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDD5C:
    ctx->pc = 0x801DDD5Cu;
    ctx->downcount -= 12;
    // 801DDD5C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDD60:
    ctx->pc = 0x801DDD60u;
    // 801DDD60: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDD64:
    ctx->pc = 0x801DDD64u;
    // 801DDD64: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DDD68:
    ctx->pc = 0x801DDD68u;
    // 801DDD68: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDD6C:
    ctx->pc = 0x801DDD6Cu;
    // 801DDD6C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDD70:
    ctx->pc = 0x801DDD70u;
    // 801DDD70: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_801DDD74:
    ctx->pc = 0x801DDD74u;
    // 801DDD74: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDD78:
    ctx->pc = 0x801DDD78u;
    // 801DDD78: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDD7C:
    ctx->pc = 0x801DDD7Cu;
    // 801DDD7C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDD80:
    ctx->pc = 0x801DDD80u;
    // 801DDD80: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDD84:
    ctx->pc = 0x801DDD84u;
    // 801DDD84: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDD88u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDD88:
    ctx->pc = 0x801DDD88u;
    ctx->downcount -= 2;
    // 801DDD88: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DDD8C:
    ctx->pc = 0x801DDD8Cu;
    // 801DDD8C: bc    12, 2, 0x801DDDAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDDAC;
        }
    }

label_801DDD90:
    ctx->pc = 0x801DDD90u;
    ctx->downcount -= 2;
    // 801DDD90: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDD94:
    ctx->pc = 0x801DDD94u;
    // 801DDD94: bl      0x801E7708
    {
            ctx->lr = 0x801DDD98u;
            ctx->pc = 0x801E7708u;
            return;
    }

label_801DDD98:
    ctx->pc = 0x801DDD98u;
    ctx->downcount -= 5;
    // 801DDD98: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DDD9C:
    ctx->pc = 0x801DDD9Cu;
    // 801DDD9C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDDA0:
    ctx->pc = 0x801DDDA0u;
    // 801DDDA0: addi    r9, r9, 17656
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17656);

label_801DDDA4:
    ctx->pc = 0x801DDDA4u;
    // 801DDDA4: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DDDA8:
    ctx->pc = 0x801DDDA8u;
    // 801DDDA8: b       0x801DDDB0
    {
            goto label_801DDDB0;
    }

label_801DDDAC:
    ctx->pc = 0x801DDDACu;
    ctx->downcount -= 1;
    // 801DDDAC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDDB0:
    ctx->pc = 0x801DDDB0u;
    ctx->downcount -= 6;
    // 801DDDB0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDDB4:
    ctx->pc = 0x801DDDB4u;
    // 801DDDB4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDDB8:
    ctx->pc = 0x801DDDB8u;
    // 801DDDB8: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DDDBC:
    ctx->pc = 0x801DDDBCu;
    // 801DDDBC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DDDC0:
    ctx->pc = 0x801DDDC0u;
    // 801DDDC0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDDC4:
    ctx->pc = 0x801DDDC4u;
    ctx->downcount -= 11;
    // 801DDDC4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDDC8:
    ctx->pc = 0x801DDDC8u;
    // 801DDDC8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDDCC:
    ctx->pc = 0x801DDDCCu;
    // 801DDDCC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDDD0:
    ctx->pc = 0x801DDDD0u;
    // 801DDDD0: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDDD4:
    ctx->pc = 0x801DDDD4u;
    // 801DDDD4: li      r4, 192
    ctx->gpr[4] = (u32)(s32)(192);

label_801DDDD8:
    ctx->pc = 0x801DDDD8u;
    // 801DDDD8: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDDDC:
    ctx->pc = 0x801DDDDCu;
    // 801DDDDC: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDDE0:
    ctx->pc = 0x801DDDE0u;
    // 801DDDE0: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDDE4:
    ctx->pc = 0x801DDDE4u;
    // 801DDDE4: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDDE8:
    ctx->pc = 0x801DDDE8u;
    // 801DDDE8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDDECu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDDEC:
    ctx->pc = 0x801DDDECu;
    ctx->downcount -= 2;
    // 801DDDEC: or.   r3, r3, r3
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

label_801DDDF0:
    ctx->pc = 0x801DDDF0u;
    // 801DDDF0: bc    12, 2, 0x801DDDFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDDFC;
        }
    }

label_801DDDF4:
    ctx->pc = 0x801DDDF4u;
    ctx->downcount -= 1;
    // 801DDDF4: bl      0x801F27B0
    {
            ctx->lr = 0x801DDDF8u;
            ctx->pc = 0x801F27B0u;
            return;
    }

label_801DDDF8:
    ctx->pc = 0x801DDDF8u;
    ctx->downcount -= 1;
    // 801DDDF8: b       0x801DDE00
    {
            goto label_801DDE00;
    }

label_801DDDFC:
    ctx->pc = 0x801DDDFCu;
    ctx->downcount -= 1;
    // 801DDDFC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDE00:
    ctx->pc = 0x801DDE00u;
    ctx->downcount -= 5;
    // 801DDE00: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDE04:
    ctx->pc = 0x801DDE04u;
    // 801DDE04: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDE08:
    ctx->pc = 0x801DDE08u;
    // 801DDE08: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DDE0C:
    ctx->pc = 0x801DDE0Cu;
    // 801DDE0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDE10:
    ctx->pc = 0x801DDE10u;
    ctx->downcount -= 12;
    // 801DDE10: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDE14:
    ctx->pc = 0x801DDE14u;
    // 801DDE14: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDE18:
    ctx->pc = 0x801DDE18u;
    // 801DDE18: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DDE1C:
    ctx->pc = 0x801DDE1Cu;
    // 801DDE1C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDE20:
    ctx->pc = 0x801DDE20u;
    // 801DDE20: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDE24:
    ctx->pc = 0x801DDE24u;
    // 801DDE24: li      r4, 36
    ctx->gpr[4] = (u32)(s32)(36);

label_801DDE28:
    ctx->pc = 0x801DDE28u;
    // 801DDE28: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDE2C:
    ctx->pc = 0x801DDE2Cu;
    // 801DDE2C: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDE30:
    ctx->pc = 0x801DDE30u;
    // 801DDE30: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDE34:
    ctx->pc = 0x801DDE34u;
    // 801DDE34: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDE38:
    ctx->pc = 0x801DDE38u;
    // 801DDE38: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDE3Cu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDE3C:
    ctx->pc = 0x801DDE3Cu;
    ctx->downcount -= 2;
    // 801DDE3C: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DDE40:
    ctx->pc = 0x801DDE40u;
    // 801DDE40: bc    12, 2, 0x801DDE60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDE60;
        }
    }

label_801DDE44:
    ctx->pc = 0x801DDE44u;
    ctx->downcount -= 2;
    // 801DDE44: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDE48:
    ctx->pc = 0x801DDE48u;
    // 801DDE48: bl      0x801D1410
    {
            ctx->lr = 0x801DDE4Cu;
            ctx->pc = 0x801D1410u;
            return;
    }

label_801DDE4C:
    ctx->pc = 0x801DDE4Cu;
    ctx->downcount -= 5;
    // 801DDE4C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DDE50:
    ctx->pc = 0x801DDE50u;
    // 801DDE50: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDE54:
    ctx->pc = 0x801DDE54u;
    // 801DDE54: addi    r9, r9, 11712
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(11712);

label_801DDE58:
    ctx->pc = 0x801DDE58u;
    // 801DDE58: stw     r9, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DDE5C:
    ctx->pc = 0x801DDE5Cu;
    // 801DDE5C: b       0x801DDE64
    {
            goto label_801DDE64;
    }

label_801DDE60:
    ctx->pc = 0x801DDE60u;
    ctx->downcount -= 1;
    // 801DDE60: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDE64:
    ctx->pc = 0x801DDE64u;
    ctx->downcount -= 6;
    // 801DDE64: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDE68:
    ctx->pc = 0x801DDE68u;
    // 801DDE68: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDE6C:
    ctx->pc = 0x801DDE6Cu;
    // 801DDE6C: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DDE70:
    ctx->pc = 0x801DDE70u;
    // 801DDE70: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DDE74:
    ctx->pc = 0x801DDE74u;
    // 801DDE74: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDE78:
    ctx->pc = 0x801DDE78u;
    ctx->downcount -= 11;
    // 801DDE78: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDE7C:
    ctx->pc = 0x801DDE7Cu;
    // 801DDE7C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDE80:
    ctx->pc = 0x801DDE80u;
    // 801DDE80: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDE84:
    ctx->pc = 0x801DDE84u;
    // 801DDE84: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDE88:
    ctx->pc = 0x801DDE88u;
    // 801DDE88: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DDE8C:
    ctx->pc = 0x801DDE8Cu;
    // 801DDE8C: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDE90:
    ctx->pc = 0x801DDE90u;
    // 801DDE90: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDE94:
    ctx->pc = 0x801DDE94u;
    // 801DDE94: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDE98:
    ctx->pc = 0x801DDE98u;
    // 801DDE98: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDE9C:
    ctx->pc = 0x801DDE9Cu;
    // 801DDE9C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDEA0u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDEA0:
    ctx->pc = 0x801DDEA0u;
    ctx->downcount -= 2;
    // 801DDEA0: or.   r3, r3, r3
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

label_801DDEA4:
    ctx->pc = 0x801DDEA4u;
    // 801DDEA4: bc    12, 2, 0x801DDEB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDEB0;
        }
    }

label_801DDEA8:
    ctx->pc = 0x801DDEA8u;
    ctx->downcount -= 1;
    // 801DDEA8: bl      0x801F5194
    {
            ctx->lr = 0x801DDEACu;
            ctx->pc = 0x801F5194u;
            return;
    }

label_801DDEAC:
    ctx->pc = 0x801DDEACu;
    ctx->downcount -= 1;
    // 801DDEAC: b       0x801DDEB4
    {
            goto label_801DDEB4;
    }

label_801DDEB0:
    ctx->pc = 0x801DDEB0u;
    ctx->downcount -= 1;
    // 801DDEB0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDEB4:
    ctx->pc = 0x801DDEB4u;
    ctx->downcount -= 5;
    // 801DDEB4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDEB8:
    ctx->pc = 0x801DDEB8u;
    // 801DDEB8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDEBC:
    ctx->pc = 0x801DDEBCu;
    // 801DDEBC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DDEC0:
    ctx->pc = 0x801DDEC0u;
    // 801DDEC0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDEC4:
    ctx->pc = 0x801DDEC4u;
    ctx->downcount -= 11;
    // 801DDEC4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDEC8:
    ctx->pc = 0x801DDEC8u;
    // 801DDEC8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDECC:
    ctx->pc = 0x801DDECCu;
    // 801DDECC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDED0:
    ctx->pc = 0x801DDED0u;
    // 801DDED0: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDED4:
    ctx->pc = 0x801DDED4u;
    // 801DDED4: li      r4, 40
    ctx->gpr[4] = (u32)(s32)(40);

label_801DDED8:
    ctx->pc = 0x801DDED8u;
    // 801DDED8: lha     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DDEDC:
    ctx->pc = 0x801DDEDCu;
    // 801DDEDC: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DDEE0:
    ctx->pc = 0x801DDEE0u;
    // 801DDEE0: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DDEE4:
    ctx->pc = 0x801DDEE4u;
    // 801DDEE4: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DDEE8:
    ctx->pc = 0x801DDEE8u;
    // 801DDEE8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DDEECu;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDEEC:
    ctx->pc = 0x801DDEECu;
    ctx->downcount -= 2;
    // 801DDEEC: or.   r3, r3, r3
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

label_801DDEF0:
    ctx->pc = 0x801DDEF0u;
    // 801DDEF0: bc    12, 2, 0x801DDEFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDEFC;
        }
    }

label_801DDEF4:
    ctx->pc = 0x801DDEF4u;
    ctx->downcount -= 1;
    // 801DDEF4: bl      0x801F5250
    {
            ctx->lr = 0x801DDEF8u;
            ctx->pc = 0x801F5250u;
            return;
    }

label_801DDEF8:
    ctx->pc = 0x801DDEF8u;
    ctx->downcount -= 1;
    // 801DDEF8: b       0x801DDF00
    {
            goto label_801DDF00;
    }

label_801DDEFC:
    ctx->pc = 0x801DDEFCu;
    ctx->downcount -= 1;
    // 801DDEFC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DDF00:
    ctx->pc = 0x801DDF00u;
    ctx->downcount -= 5;
    // 801DDF00: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDF04:
    ctx->pc = 0x801DDF04u;
    // 801DDF04: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDF08:
    ctx->pc = 0x801DDF08u;
    // 801DDF08: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DDF0C:
    ctx->pc = 0x801DDF0Cu;
    // 801DDF0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDF10:
    ctx->pc = 0x801DDF10u;
    ctx->downcount -= 4;
    // 801DDF10: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDF14:
    ctx->pc = 0x801DDF14u;
    // 801DDF14: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDF18:
    ctx->pc = 0x801DDF18u;
    // 801DDF18: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDF1C:
    ctx->pc = 0x801DDF1Cu;
    // 801DDF1C: bl      0x801E7738
    {
            ctx->lr = 0x801DDF20u;
            ctx->pc = 0x801E7738u;
            return;
    }

label_801DDF20:
    ctx->pc = 0x801DDF20u;
    ctx->downcount -= 5;
    // 801DDF20: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDF24:
    ctx->pc = 0x801DDF24u;
    // 801DDF24: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDF28:
    ctx->pc = 0x801DDF28u;
    // 801DDF28: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DDF2C:
    ctx->pc = 0x801DDF2Cu;
    // 801DDF2C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDF30:
    ctx->pc = 0x801DDF30u;
    ctx->downcount -= 1;
    // 801DDF30: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDF34:
    ctx->pc = 0x801DDF34u;
    ctx->downcount -= 1;
    // 801DDF34: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDF38:
    ctx->pc = 0x801DDF38u;
    ctx->downcount -= 7;
    // 801DDF38: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDF3C:
    ctx->pc = 0x801DDF3Cu;
    // 801DDF3C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDF40:
    ctx->pc = 0x801DDF40u;
    // 801DDF40: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDF44:
    ctx->pc = 0x801DDF44u;
    // 801DDF44: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DDF48:
    ctx->pc = 0x801DDF48u;
    // 801DDF48: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801DDF4C:
    ctx->pc = 0x801DDF4Cu;
    // 801DDF4C: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_801DDF50:
    ctx->pc = 0x801DDF50u;
    // 801DDF50: bl      0x801DC5F4
    {
            ctx->lr = 0x801DDF54u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DC5F4u;
                return;
            }
            goto label_801DC5F4;
    }

label_801DDF54:
    ctx->pc = 0x801DDF54u;
    ctx->downcount -= 5;
    // 801DDF54: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DDF58:
    ctx->pc = 0x801DDF58u;
    // 801DDF58: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DDF5C:
    ctx->pc = 0x801DDF5Cu;
    // 801DDF5C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DDF60:
    ctx->pc = 0x801DDF60u;
    // 801DDF60: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DDF64:
    ctx->pc = 0x801DDF64u;
    ctx->downcount -= 20;
    // 801DDF64: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DDF68:
    ctx->pc = 0x801DDF68u;
    // 801DDF68: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DDF6C:
    ctx->pc = 0x801DDF6Cu;
    // 801DDF6C: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DDF70:
    ctx->pc = 0x801DDF70u;
    // 801DDF70: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDF74:
    ctx->pc = 0x801DDF74u;
    // 801DDF74: lwz     r11, -26948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26948);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801DDF78:
    ctx->pc = 0x801DDF78u;
    // 801DDF78: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DDF7C:
    ctx->pc = 0x801DDF7Cu;
    // 801DDF7C: addi    r31, r29, 32
    ctx->gpr[31] = ctx->gpr[29] + (u32)(s32)(32);

label_801DDF80:
    ctx->pc = 0x801DDF80u;
    // 801DDF80: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_801DDF84:
    ctx->pc = 0x801DDF84u;
    // 801DDF84: cmpwi   r11, 0
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

label_801DDF88:
    ctx->pc = 0x801DDF88u;
    // 801DDF88: bc    4, 2, 0x801DDFA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DDFA4;
        }
    }

label_801DDF8C:
    ctx->pc = 0x801DDF8Cu;
    ctx->downcount -= 6;
    // 801DDF8C: addi    r9, r30, -15840
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(-15840);

label_801DDF90:
    ctx->pc = 0x801DDF90u;
    // 801DDF90: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801DDF94:
    ctx->pc = 0x801DDF94u;
    // 801DDF94: stb     r11, 520(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(520);
        mem_write8(ctx, ea, (u8)ctx->gpr[11]);
    }

label_801DDF98:
    ctx->pc = 0x801DDF98u;
    // 801DDF98: stw     r0, -26948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26948);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DDF9C:
    ctx->pc = 0x801DDF9Cu;
    // 801DDF9C: stb     r11, -15840(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-15840);
        mem_write8(ctx, ea, (u8)ctx->gpr[11]);
    }

label_801DDFA0:
    ctx->pc = 0x801DDFA0u;
    // 801DDFA0: stb     r11, 260(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(260);
        mem_write8(ctx, ea, (u8)ctx->gpr[11]);
    }

label_801DDFA4:
    ctx->pc = 0x801DDFA4u;
    ctx->downcount -= 5;
    // 801DDFA4: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DDFA8:
    ctx->pc = 0x801DDFA8u;
    // 801DDFA8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDFAC:
    ctx->pc = 0x801DDFACu;
    // 801DDFAC: addi    r4, r4, 5556
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5556);

label_801DDFB0:
    ctx->pc = 0x801DDFB0u;
    // 801DDFB0: li      r5, 14
    ctx->gpr[5] = (u32)(s32)(14);

label_801DDFB4:
    ctx->pc = 0x801DDFB4u;
    // 801DDFB4: bl      0x80298ADC
    {
            ctx->lr = 0x801DDFB8u;
            ctx->pc = 0x80298ADCu;
            return;
    }

label_801DDFB8:
    ctx->pc = 0x801DDFB8u;
    ctx->downcount -= 2;
    // 801DDFB8: cmpwi   r3, 0
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

label_801DDFBC:
    ctx->pc = 0x801DDFBCu;
    // 801DDFBC: bc    4, 2, 0x801DDFFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DDFFC;
        }
    }

label_801DDFC0:
    ctx->pc = 0x801DDFC0u;
    ctx->downcount -= 4;
    // 801DDFC0: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_801DDFC4:
    ctx->pc = 0x801DDFC4u;
    // 801DDFC4: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DDFC8:
    ctx->pc = 0x801DDFC8u;
    // 801DDFC8: addi    r3, r9, -15840
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(-15840);

label_801DDFCC:
    ctx->pc = 0x801DDFCCu;
    // 801DDFCC: bc    12, 2, 0x801DDFE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DDFE0;
        }
    }

label_801DDFD0:
    ctx->pc = 0x801DDFD0u;
    ctx->downcount -= 3;
    // 801DDFD0: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DDFD4:
    ctx->pc = 0x801DDFD4u;
    // 801DDFD4: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_801DDFD8:
    ctx->pc = 0x801DDFD8u;
    // 801DDFD8: bl      0x80287F10
    {
            ctx->lr = 0x801DDFDCu;
            ctx->pc = 0x80287F10u;
            return;
    }

label_801DDFDC:
    ctx->pc = 0x801DDFDCu;
    ctx->downcount -= 1;
    // 801DDFDC: b       0x801DDFE4
    {
            goto label_801DDFE4;
    }

label_801DDFE0:
    ctx->pc = 0x801DDFE0u;
    ctx->downcount -= 1;
    // 801DDFE0: stb     r31, -15840(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-15840);
        mem_write8(ctx, ea, (u8)ctx->gpr[31]);
    }

label_801DDFE4:
    ctx->pc = 0x801DDFE4u;
    ctx->downcount -= 6;
    // 801DDFE4: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_801DDFE8:
    ctx->pc = 0x801DDFE8u;
    // 801DDFE8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DDFEC:
    ctx->pc = 0x801DDFECu;
    // 801DDFEC: addi    r11, r9, -15580
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-15580);

label_801DDFF0:
    ctx->pc = 0x801DDFF0u;
    // 801DDFF0: stb     r0, -15580(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15580);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801DDFF4:
    ctx->pc = 0x801DDFF4u;
    // 801DDFF4: stb     r0, 260(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(260);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801DDFF8:
    ctx->pc = 0x801DDFF8u;
    // 801DDFF8: b       0x801DE054
    {
            goto label_801DE054;
    }

label_801DDFFC:
    ctx->pc = 0x801DDFFCu;
    ctx->downcount -= 7;
    // 801DDFFC: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_801DE000:
    ctx->pc = 0x801DE000u;
    // 801DE000: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DE004:
    ctx->pc = 0x801DE004u;
    // 801DE004: addi    r11, r9, -15840
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-15840);

label_801DE008:
    ctx->pc = 0x801DE008u;
    // 801DE008: stb     r0, -15840(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15840);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801DE00C:
    ctx->pc = 0x801DE00Cu;
    // 801DE00C: addi    r3, r11, 260
    ctx->gpr[3] = ctx->gpr[11] + (u32)(s32)(260);

label_801DE010:
    ctx->pc = 0x801DE010u;
    // 801DE010: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE014:
    ctx->pc = 0x801DE014u;
    // 801DE014: bc    12, 2, 0x801DE028
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE028;
        }
    }

label_801DE018:
    ctx->pc = 0x801DE018u;
    ctx->downcount -= 3;
    // 801DE018: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DE01C:
    ctx->pc = 0x801DE01Cu;
    // 801DE01C: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_801DE020:
    ctx->pc = 0x801DE020u;
    // 801DE020: bl      0x80287F10
    {
            ctx->lr = 0x801DE024u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_801DE024:
    ctx->pc = 0x801DE024u;
    ctx->downcount -= 1;
    // 801DE024: b       0x801DE02C
    {
            goto label_801DE02C;
    }

label_801DE028:
    ctx->pc = 0x801DE028u;
    ctx->downcount -= 1;
    // 801DE028: stb     r31, 260(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(260);
        mem_write8(ctx, ea, (u8)ctx->gpr[31]);
    }

label_801DE02C:
    ctx->pc = 0x801DE02Cu;
    ctx->downcount -= 6;
    // 801DE02C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DE030:
    ctx->pc = 0x801DE030u;
    // 801DE030: lis     r11, -32714
    ctx->gpr[11] = ((u32)(s32)(-32714) << 16);

label_801DE034:
    ctx->pc = 0x801DE034u;
    // 801DE034: addi    r4, r9, 5572
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(5572);

label_801DE038:
    ctx->pc = 0x801DE038u;
    // 801DE038: addi    r3, r11, -15320
    ctx->gpr[3] = ctx->gpr[11] + (u32)(s32)(-15320);

label_801DE03C:
    ctx->pc = 0x801DE03Cu;
    // 801DE03C: cmpwi   r4, 0
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

label_801DE040:
    ctx->pc = 0x801DE040u;
    // 801DE040: bc    12, 2, 0x801DE050
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE050;
        }
    }

label_801DE044:
    ctx->pc = 0x801DE044u;
    ctx->downcount -= 2;
    // 801DE044: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_801DE048:
    ctx->pc = 0x801DE048u;
    // 801DE048: bl      0x80287F10
    {
            ctx->lr = 0x801DE04Cu;
            ctx->pc = 0x80287F10u;
            return;
    }

label_801DE04C:
    ctx->pc = 0x801DE04Cu;
    ctx->downcount -= 1;
    // 801DE04C: b       0x801DE054
    {
            goto label_801DE054;
    }

label_801DE050:
    ctx->pc = 0x801DE050u;
    ctx->downcount -= 1;
    // 801DE050: stb     r4, -15320(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-15320);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801DE054:
    ctx->pc = 0x801DE054u;
    ctx->downcount -= 7;
    // 801DE054: lwz     r9, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE058:
    ctx->pc = 0x801DE058u;
    // 801DE058: lis     r11, -32714
    ctx->gpr[11] = ((u32)(s32)(-32714) << 16);

label_801DE05C:
    ctx->pc = 0x801DE05Cu;
    // 801DE05C: addi    r11, r11, -15840
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-15840);

label_801DE060:
    ctx->pc = 0x801DE060u;
    // 801DE060: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DE064:
    ctx->pc = 0x801DE064u;
    // 801DE064: lwz     r10, 220(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(220);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801DE068:
    ctx->pc = 0x801DE068u;
    // 801DE068: stw     r11, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DE06C:
    ctx->pc = 0x801DE06Cu;
    // 801DE06C: bl      0x801E5148
    {
            ctx->lr = 0x801DE070u;
            ctx->pc = 0x801E5148u;
            return;
    }

label_801DE070:
    ctx->pc = 0x801DE070u;
    ctx->downcount -= 4;
    // 801DE070: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_801DE074:
    ctx->pc = 0x801DE074u;
    // 801DE074: stw     r3, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DE078:
    ctx->pc = 0x801DE078u;
    // 801DE078: cmpwi   r3, 0
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

label_801DE07C:
    ctx->pc = 0x801DE07Cu;
    // 801DE07C: bc    12, 2, 0x801DE08C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE08C;
        }
    }

label_801DE080:
    ctx->pc = 0x801DE080u;
    ctx->downcount -= 3;
    // 801DE080: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE084:
    ctx->pc = 0x801DE084u;
    // 801DE084: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801DE088:
    ctx->pc = 0x801DE088u;
    // 801DE088: stw     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DE08C:
    ctx->pc = 0x801DE08Cu;
    ctx->downcount -= 2;
    // 801DE08C: lwz     r3, 368(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DE090:
    ctx->pc = 0x801DE090u;
    // 801DE090: bl      0x801E31C8
    {
            ctx->lr = 0x801DE094u;
            ctx->pc = 0x801E31C8u;
            return;
    }

label_801DE094:
    ctx->pc = 0x801DE094u;
    ctx->downcount -= 16;
    // 801DE094: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE098:
    ctx->pc = 0x801DE098u;
    // 801DE098: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE09C:
    ctx->pc = 0x801DE09Cu;
    // 801DE09C: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DE0A0:
    ctx->pc = 0x801DE0A0u;
    // 801DE0A0: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801DE0A4:
    ctx->pc = 0x801DE0A4u;
    // 801DE0A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE0A8:
    ctx->pc = 0x801DE0A8u;
    ctx->downcount -= 16;
    // 801DE0A8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE0AC:
    ctx->pc = 0x801DE0ACu;
    // 801DE0AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DE0B0:
    ctx->pc = 0x801DE0B0u;
    // 801DE0B0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DE0B4:
    ctx->pc = 0x801DE0B4u;
    // 801DE0B4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE0B8:
    ctx->pc = 0x801DE0B8u;
    // 801DE0B8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DE0BC:
    ctx->pc = 0x801DE0BCu;
    // 801DE0BC: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DE0C0:
    ctx->pc = 0x801DE0C0u;
    ctx->downcount -= 11;
    // 801DE0C0: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE0C4:
    ctx->pc = 0x801DE0C4u;
    // 801DE0C4: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE0C8:
    // 801DE0C8: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_801DE0CC:
    ctx->pc = 0x801DE0CCu;
    // 801DE0CC: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DE0D0:
    // 801DE0D0: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_801DE0D4:
    // 801DE0D4: cmplw   r10, r11
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

label_801DE0D8:
    // 801DE0D8: bc    12, 0, 0x801DE100
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE100;
        }
    }

label_801DE0DC:
    ctx->downcount -= 3;
    // 801DE0DC: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DE0E0:
    ctx->pc = 0x801DE0E0u;
    // 801DE0E0: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE0E4:
    // 801DE0E4: b       0x801DE1D8
    {
            goto label_801DE1D8;
    }

label_801DE0E8:
    ctx->pc = 0x801DE0E8u;
    ctx->downcount -= 6;
    // 801DE0E8: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE0EC:
    // 801DE0EC: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DE0F0:
    ctx->pc = 0x801DE0F0u;
    // 801DE0F0: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE0F4:
    ctx->pc = 0x801DE0F4u;
    // 801DE0F4: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DE0F8:
    ctx->pc = 0x801DE0F8u;
    // 801DE0F8: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801DE0FC:
    // 801DE0FC: b       0x801DE0C0
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE0C0u;
                return;
            }
            goto label_801DE0C0;
    }

label_801DE100:
    ctx->downcount -= 2;
    // 801DE100: cmplw   r10, r30
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

label_801DE104:
    // 801DE104: bc    12, 0, 0x801DE124
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE124;
        }
    }

label_801DE108:
    ctx->downcount -= 50;
    // 801DE108: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_801DE10C:
    ctx->pc = 0x801DE10Cu;
    // 801DE10C: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE110:
    // 801DE110: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_801DE114:
    ctx->pc = 0x801DE114u;
    // 801DE114: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DE118:
    // 801DE118: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DE11C:
    ctx->pc = 0x801DE11Cu;
    // 801DE11C: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE120:
    // 801DE120: b       0x801DE1D8
    {
            goto label_801DE1D8;
    }

label_801DE124:
    ctx->pc = 0x801DE124u;
    ctx->downcount -= 8;
    // 801DE124: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE128:
    // 801DE128: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DE12C:
    // 801DE12C: cmpwi   r10, 0
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

label_801DE130:
    // 801DE130: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_801DE134:
    // 801DE134: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_801DE138:
    // 801DE138: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_801DE13C:
    // 801DE13C: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_801DE140:
    // 801DE140: bc    12, 2, 0x801DE160
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE160;
        }
    }

label_801DE144:
    ctx->downcount -= 7;
    // 801DE144: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_801DE148:
    // 801DE148: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801DE14C:
    // 801DE14C: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DE150:
    // 801DE150: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801DE154:
    ctx->pc = 0x801DE154u;
    // 801DE154: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801DE158:
    ctx->pc = 0x801DE158u;
    // 801DE158: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DE15C:
    ctx->pc = 0x801DE15Cu;
    // 801DE15C: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DE160:
    ctx->downcount -= 2;
    // 801DE160: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DE164:
    // 801DE164: bl      0x80281C60
    {
            ctx->lr = 0x801DE168u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801DE168:
    ctx->downcount -= 3;
    // 801DE168: cmpwi   r3, 0
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

label_801DE16C:
    ctx->pc = 0x801DE16Cu;
    // 801DE16C: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DE170:
    // 801DE170: bc    4, 2, 0x801DE1BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DE1BC;
        }
    }

label_801DE174:
    ctx->downcount -= 3;
    // 801DE174: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DE178:
    // 801DE178: cmplwi  r11, 0x0080
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

label_801DE17C:
    // 801DE17C: bc    12, 1, 0x801DE1A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE1A8;
        }
    }

label_801DE180:
    ctx->downcount -= 2;
    // 801DE180: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801DE184:
    // 801DE184: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801DE188:
    ctx->downcount -= 5;
    // 801DE188: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_801DE18C:
    // 801DE18C: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DE190:
    ctx->pc = 0x801DE190u;
    // 801DE190: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801DE194:
    // 801DE194: cmpwi   r10, 0
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

label_801DE198:
    // 801DE198: bc    4, 2, 0x801DE0E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE0E8u;
                return;
            }
            goto label_801DE0E8;
        }
    }

label_801DE19C:
    ctx->downcount -= 3;
    // 801DE19C: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_801DE1A0:
    // 801DE1A0: cmplwi  r11, 0x0080
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

label_801DE1A4:
    // 801DE1A4: bc    4, 1, 0x801DE188
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE188u;
                return;
            }
            goto label_801DE188;
        }
    }

label_801DE1A8:
    ctx->downcount -= 4;
    // 801DE1A8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DE1AC:
    // 801DE1AC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DE1B0:
    ctx->pc = 0x801DE1B0u;
    // 801DE1B0: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE1B4:
    // 801DE1B4: bl      0x80281C60
    {
            ctx->lr = 0x801DE1B8u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801DE1B8:
    ctx->pc = 0x801DE1B8u;
    ctx->downcount -= 1;
    // 801DE1B8: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DE1BC:
    ctx->pc = 0x801DE1BCu;
    ctx->downcount -= 7;
    // 801DE1BC: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE1C0:
    ctx->pc = 0x801DE1C0u;
    // 801DE1C0: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE1C4:
    // 801DE1C4: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DE1C8:
    // 801DE1C8: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_801DE1CC:
    ctx->pc = 0x801DE1CCu;
    // 801DE1CC: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE1D0:
    ctx->pc = 0x801DE1D0u;
    // 801DE1D0: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DE1D4:
    // 801DE1D4: b       0x801DE0C0
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE0C0u;
                return;
            }
            goto label_801DE0C0;
    }

label_801DE1D8:
    ctx->pc = 0x801DE1D8u;
    ctx->downcount -= 16;
    // 801DE1D8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE1DC:
    ctx->pc = 0x801DE1DCu;
    // 801DE1DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE1E0:
    ctx->pc = 0x801DE1E0u;
    // 801DE1E0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DE1E4:
    ctx->pc = 0x801DE1E4u;
    // 801DE1E4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DE1E8:
    ctx->pc = 0x801DE1E8u;
    // 801DE1E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE1EC:
    ctx->pc = 0x801DE1ECu;
    ctx->downcount -= 21;
    // 801DE1EC: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE1F0:
    ctx->pc = 0x801DE1F0u;
    // 801DE1F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DE1F4:
    ctx->pc = 0x801DE1F4u;
    // 801DE1F4: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DE1F8:
    ctx->pc = 0x801DE1F8u;
    // 801DE1F8: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE1FC:
    ctx->pc = 0x801DE1FCu;
    // 801DE1FC: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801DE200:
    ctx->pc = 0x801DE200u;
    // 801DE200: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_801DE204:
    ctx->pc = 0x801DE204u;
    // 801DE204: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801DE208:
    ctx->pc = 0x801DE208u;
    // 801DE208: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DE20C:
    ctx->pc = 0x801DE20Cu;
    // 801DE20C: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801DE210:
    ctx->pc = 0x801DE210u;
    // 801DE210: cmpwi   r30, 0
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

label_801DE214:
    ctx->pc = 0x801DE214u;
    // 801DE214: bc    12, 2, 0x801DE224
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE224;
        }
    }

label_801DE218:
    ctx->pc = 0x801DE218u;
    ctx->downcount -= 3;
    // 801DE218: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE21C:
    ctx->pc = 0x801DE21Cu;
    // 801DE21C: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE220:
    ctx->pc = 0x801DE220u;
    // 801DE220: b       0x801DE2A4
    {
            goto label_801DE2A4;
    }

label_801DE224:
    ctx->pc = 0x801DE224u;
    ctx->downcount -= 7;
    // 801DE224: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_801DE228:
    ctx->pc = 0x801DE228u;
    // 801DE228: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_801DE22C:
    ctx->pc = 0x801DE22Cu;
    // 801DE22C: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_801DE230:
    ctx->pc = 0x801DE230u;
    // 801DE230: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DE234:
    ctx->pc = 0x801DE234u;
    // 801DE234: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DE238:
    ctx->pc = 0x801DE238u;
    // 801DE238: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_801DE23C:
    ctx->pc = 0x801DE23Cu;
    // 801DE23C: bl      0x80003EE0
    {
            ctx->lr = 0x801DE240u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_801DE240:
    ctx->pc = 0x801DE240u;
    ctx->downcount -= 3;
    // 801DE240: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE244:
    ctx->pc = 0x801DE244u;
    // 801DE244: cmpwi   r9, 1
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

label_801DE248:
    ctx->pc = 0x801DE248u;
    // 801DE248: bc    12, 2, 0x801DE2A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE2A0;
        }
    }

label_801DE24C:
    ctx->pc = 0x801DE24Cu;
    ctx->downcount -= 9;
    // 801DE24C: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_801DE250:
    ctx->pc = 0x801DE250u;
    // 801DE250: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801DE254:
    ctx->pc = 0x801DE254u;
    // 801DE254: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801DE258:
    ctx->pc = 0x801DE258u;
    // 801DE258: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801DE25C:
    ctx->pc = 0x801DE25Cu;
    // 801DE25C: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DE260:
    ctx->pc = 0x801DE260u;
    // 801DE260: cmpwi   r9, 2
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

label_801DE264:
    ctx->pc = 0x801DE264u;
    // 801DE264: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_801DE268:
    ctx->pc = 0x801DE268u;
    // 801DE268: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801DE26C:
    ctx->pc = 0x801DE26Cu;
    // 801DE26C: bc    4, 2, 0x801DE278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DE278;
        }
    }

label_801DE270:
    ctx->pc = 0x801DE270u;
    ctx->downcount -= 2;
    // 801DE270: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801DE274:
    ctx->pc = 0x801DE274u;
    // 801DE274: b       0x801DE2A0
    {
            goto label_801DE2A0;
    }

label_801DE278:
    loop_801DE278(ctx);
    if (ctx->pc == 0x801DE298u) goto label_801DE298;
    return;
label_801DE27C:
    // 801DE27C: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_801DE280:
    // 801DE280: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801DE284:
    ctx->pc = 0x801DE284u;
    // 801DE284: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE288:
    // 801DE288: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801DE28C:
    // 801DE28C: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801DE290:
    // 801DE290: cmpw    r9, r8
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

label_801DE294:
    // 801DE294: bc    4, 2, 0x801DE278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE278u;
                return;
            }
            goto label_801DE278;
        }
    }

label_801DE298:
    ctx->pc = 0x801DE298u;
    ctx->downcount -= 2;
    // 801DE298: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DE29C:
    ctx->pc = 0x801DE29Cu;
    // 801DE29C: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE2A0:
    ctx->pc = 0x801DE2A0u;
    ctx->downcount -= 1;
    // 801DE2A0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DE2A4:
    ctx->pc = 0x801DE2A4u;
    ctx->downcount -= 17;
    // 801DE2A4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DE2A8:
    ctx->pc = 0x801DE2A8u;
    // 801DE2A8: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE2AC:
    ctx->pc = 0x801DE2ACu;
    // 801DE2AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE2B0:
    ctx->pc = 0x801DE2B0u;
    // 801DE2B0: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DE2B4:
    ctx->pc = 0x801DE2B4u;
    // 801DE2B4: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801DE2B8:
    ctx->pc = 0x801DE2B8u;
    // 801DE2B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE2BC:
    ctx->pc = 0x801DE2BCu;
    ctx->downcount -= 7;
    // 801DE2BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE2C0:
    ctx->pc = 0x801DE2C0u;
    // 801DE2C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DE2C4:
    ctx->pc = 0x801DE2C4u;
    // 801DE2C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE2C8:
    ctx->pc = 0x801DE2C8u;
    // 801DE2C8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DE2CC:
    ctx->pc = 0x801DE2CCu;
    // 801DE2CC: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_801DE2D0:
    ctx->pc = 0x801DE2D0u;
    // 801DE2D0: cmpw    r4, r0
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

label_801DE2D4:
    ctx->pc = 0x801DE2D4u;
    // 801DE2D4: bc    4, 2, 0x801DE3A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DE3A8;
        }
    }

label_801DE2D8:
    ctx->pc = 0x801DE2D8u;
    ctx->downcount -= 2;
    // 801DE2D8: cmpwi   r3, 0
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

label_801DE2DC:
    ctx->pc = 0x801DE2DCu;
    // 801DE2DC: bc    12, 2, 0x801DE3A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE3A8;
        }
    }

label_801DE2E0:
    ctx->pc = 0x801DE2E0u;
    ctx->downcount -= 5;
    // 801DE2E0: lis     r3, 28009
    ctx->gpr[3] = ((u32)(s32)(28009) << 16);

label_801DE2E4:
    ctx->pc = 0x801DE2E4u;
    // 801DE2E4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801DE2E8:
    ctx->pc = 0x801DE2E8u;
    // 801DE2E8: ori     r3, r3, 0x6E66
    ctx->gpr[3] = ctx->gpr[3] | 0x6E66u;

label_801DE2EC:
    ctx->pc = 0x801DE2ECu;
    // 801DE2EC: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_801DE2F0:
    ctx->pc = 0x801DE2F0u;
    // 801DE2F0: bl      0x80252AF0
    {
            ctx->lr = 0x801DE2F4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE2F4:
    ctx->pc = 0x801DE2F4u;
    ctx->downcount -= 5;
    // 801DE2F4: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_801DE2F8:
    ctx->pc = 0x801DE2F8u;
    // 801DE2F8: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_801DE2FC:
    ctx->pc = 0x801DE2FCu;
    // 801DE2FC: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_801DE300:
    ctx->pc = 0x801DE300u;
    // 801DE300: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_801DE304:
    ctx->pc = 0x801DE304u;
    // 801DE304: bl      0x80252AF0
    {
            ctx->lr = 0x801DE308u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE308:
    ctx->pc = 0x801DE308u;
    ctx->downcount -= 5;
    // 801DE308: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_801DE30C:
    ctx->pc = 0x801DE30Cu;
    // 801DE30C: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_801DE310:
    ctx->pc = 0x801DE310u;
    // 801DE310: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_801DE314:
    ctx->pc = 0x801DE314u;
    // 801DE314: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE318:
    ctx->pc = 0x801DE318u;
    // 801DE318: bl      0x80252AF0
    {
            ctx->lr = 0x801DE31Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE31C:
    ctx->pc = 0x801DE31Cu;
    ctx->downcount -= 5;
    // 801DE31C: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_801DE320:
    ctx->pc = 0x801DE320u;
    // 801DE320: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_801DE324:
    ctx->pc = 0x801DE324u;
    // 801DE324: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_801DE328:
    ctx->pc = 0x801DE328u;
    // 801DE328: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE32C:
    ctx->pc = 0x801DE32Cu;
    // 801DE32C: bl      0x80252AF0
    {
            ctx->lr = 0x801DE330u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE330:
    ctx->pc = 0x801DE330u;
    ctx->downcount -= 5;
    // 801DE330: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_801DE334:
    ctx->pc = 0x801DE334u;
    // 801DE334: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_801DE338:
    ctx->pc = 0x801DE338u;
    // 801DE338: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_801DE33C:
    ctx->pc = 0x801DE33Cu;
    // 801DE33C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE340:
    ctx->pc = 0x801DE340u;
    // 801DE340: bl      0x80252AF0
    {
            ctx->lr = 0x801DE344u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE344:
    ctx->pc = 0x801DE344u;
    ctx->downcount -= 5;
    // 801DE344: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_801DE348:
    ctx->pc = 0x801DE348u;
    // 801DE348: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_801DE34C:
    ctx->pc = 0x801DE34Cu;
    // 801DE34C: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_801DE350:
    ctx->pc = 0x801DE350u;
    // 801DE350: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE354:
    ctx->pc = 0x801DE354u;
    // 801DE354: bl      0x80252AF0
    {
            ctx->lr = 0x801DE358u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE358:
    ctx->pc = 0x801DE358u;
    ctx->downcount -= 5;
    // 801DE358: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_801DE35C:
    ctx->pc = 0x801DE35Cu;
    // 801DE35C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801DE360:
    ctx->pc = 0x801DE360u;
    // 801DE360: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_801DE364:
    ctx->pc = 0x801DE364u;
    // 801DE364: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE368:
    ctx->pc = 0x801DE368u;
    // 801DE368: bl      0x80252AF0
    {
            ctx->lr = 0x801DE36Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE36C:
    ctx->pc = 0x801DE36Cu;
    ctx->downcount -= 5;
    // 801DE36C: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_801DE370:
    ctx->pc = 0x801DE370u;
    // 801DE370: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_801DE374:
    ctx->pc = 0x801DE374u;
    // 801DE374: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_801DE378:
    ctx->pc = 0x801DE378u;
    // 801DE378: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE37C:
    ctx->pc = 0x801DE37Cu;
    // 801DE37C: bl      0x80252AF0
    {
            ctx->lr = 0x801DE380u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE380:
    ctx->pc = 0x801DE380u;
    ctx->downcount -= 5;
    // 801DE380: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_801DE384:
    ctx->pc = 0x801DE384u;
    // 801DE384: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_801DE388:
    ctx->pc = 0x801DE388u;
    // 801DE388: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_801DE38C:
    ctx->pc = 0x801DE38Cu;
    // 801DE38C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE390:
    ctx->pc = 0x801DE390u;
    // 801DE390: bl      0x80252AF0
    {
            ctx->lr = 0x801DE394u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE394:
    ctx->pc = 0x801DE394u;
    ctx->downcount -= 5;
    // 801DE394: lis     r3, 27749
    ctx->gpr[3] = ((u32)(s32)(27749) << 16);

label_801DE398:
    ctx->pc = 0x801DE398u;
    // 801DE398: li      r4, 86
    ctx->gpr[4] = (u32)(s32)(86);

label_801DE39C:
    ctx->pc = 0x801DE39Cu;
    // 801DE39C: ori     r3, r3, 0x766C
    ctx->gpr[3] = ctx->gpr[3] | 0x766Cu;

label_801DE3A0:
    ctx->pc = 0x801DE3A0u;
    // 801DE3A0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE3A4:
    ctx->pc = 0x801DE3A4u;
    // 801DE3A4: bl      0x80252AF0
    {
            ctx->lr = 0x801DE3A8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE3A8:
    ctx->pc = 0x801DE3A8u;
    ctx->downcount -= 5;
    // 801DE3A8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE3AC:
    ctx->pc = 0x801DE3ACu;
    // 801DE3AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE3B0:
    ctx->pc = 0x801DE3B0u;
    // 801DE3B0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DE3B4:
    ctx->pc = 0x801DE3B4u;
    // 801DE3B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE3B8:
    ctx->pc = 0x801DE3B8u;
    ctx->downcount -= 24;
    // 801DE3B8: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE3BC:
    ctx->pc = 0x801DE3BCu;
    // 801DE3BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DE3C0:
    ctx->pc = 0x801DE3C0u;
    // 801DE3C0: stmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DE3C4:
    ctx->pc = 0x801DE3C4u;
    // 801DE3C4: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE3C8:
    ctx->pc = 0x801DE3C8u;
    // 801DE3C8: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DE3CC:
    ctx->pc = 0x801DE3CCu;
    // 801DE3CC: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DE3D0:
    ctx->pc = 0x801DE3D0u;
    // 801DE3D0: addi    r9, r9, 7904
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7904);

label_801DE3D4:
    ctx->pc = 0x801DE3D4u;
    // 801DE3D4: addi    r28, r29, 16
    ctx->gpr[28] = ctx->gpr[29] + (u32)(s32)(16);

label_801DE3D8:
    ctx->pc = 0x801DE3D8u;
    // 801DE3D8: stw     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DE3DC:
    ctx->pc = 0x801DE3DCu;
    // 801DE3DC: or   r26, r4, r4
    {
        ctx->gpr[26] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DE3E0:
    ctx->pc = 0x801DE3E0u;
    // 801DE3E0: lwz     r31, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DE3E4:
    ctx->pc = 0x801DE3E4u;
    // 801DE3E4: lwz     r30, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801DE3E8:
    ctx->pc = 0x801DE3E8u;
    // 801DE3E8: cmpw    r31, r30
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

label_801DE3EC:
    ctx->pc = 0x801DE3ECu;
    // 801DE3EC: bc    12, 2, 0x801DE440
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE440;
        }
    }

label_801DE3F0:
    ctx->pc = 0x801DE3F0u;
    ctx->downcount -= 1;
    // 801DE3F0: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_801DE3F4:
    ctx->pc = 0x801DE3F4u;
    ctx->downcount -= 3;
    // 801DE3F4: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801DE3F8:
    // 801DE3F8: cmpwi   r11, 0
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

label_801DE3FC:
    // 801DE3FC: bc    12, 2, 0x801DE430
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE430;
        }
    }

label_801DE400:
    ctx->pc = 0x801DE400u;
    ctx->downcount -= 5;
    // 801DE400: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE404:
    // 801DE404: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801DE408:
    // 801DE408: cmpwi   r9, 0
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

label_801DE40C:
    ctx->pc = 0x801DE40Cu;
    // 801DE40C: stw     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DE410:
    // 801DE410: bc    4, 2, 0x801DE430
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DE430;
        }
    }

label_801DE414:
    ctx->pc = 0x801DE414u;
    ctx->downcount -= 8;
    // 801DE414: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE418:
    // 801DE418: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_801DE41C:
    ctx->pc = 0x801DE41Cu;
    // 801DE41C: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DE420:
    ctx->pc = 0x801DE420u;
    // 801DE420: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE424:
    // 801DE424: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DE428:
    ctx->pc = 0x801DE428u;
    // 801DE428: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE42C:
    ctx->pc = 0x801DE42Cu;
    // 801DE42C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DE430u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE430:
    ctx->pc = 0x801DE430u;
    ctx->downcount -= 4;
    // 801DE430: stw     r27, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_801DE434:
    // 801DE434: addi    r31, r31, 4
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(4);

label_801DE438:
    // 801DE438: cmpw    r31, r30
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

label_801DE43C:
    // 801DE43C: bc    4, 2, 0x801DE3F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE3F4u;
                return;
            }
            goto label_801DE3F4;
        }
    }

label_801DE440:
    ctx->pc = 0x801DE440u;
    ctx->downcount -= 3;
    // 801DE440: lwz     r3, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DE444:
    ctx->pc = 0x801DE444u;
    // 801DE444: cmpwi   r3, 0
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

label_801DE448:
    ctx->pc = 0x801DE448u;
    // 801DE448: bc    12, 2, 0x801DE46C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE46C;
        }
    }

label_801DE44C:
    ctx->pc = 0x801DE44Cu;
    ctx->downcount -= 5;
    // 801DE44C: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE450:
    ctx->pc = 0x801DE450u;
    // 801DE450: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801DE454:
    ctx->pc = 0x801DE454u;
    // 801DE454: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_801DE458:
    ctx->pc = 0x801DE458u;
    // 801DE458: cmplwi  r4, 0x0080
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

label_801DE45C:
    ctx->pc = 0x801DE45Cu;
    // 801DE45C: bc    4, 1, 0x801DE468
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DE468;
        }
    }

label_801DE460:
    ctx->pc = 0x801DE460u;
    ctx->downcount -= 1;
    // 801DE460: bl      0x80281D80
    {
            ctx->lr = 0x801DE464u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_801DE464:
    ctx->pc = 0x801DE464u;
    ctx->downcount -= 1;
    // 801DE464: b       0x801DE46C
    {
            goto label_801DE46C;
    }

label_801DE468:
    ctx->pc = 0x801DE468u;
    ctx->downcount -= 1;
    // 801DE468: bl      0x8001D934
    {
            ctx->lr = 0x801DE46Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_801DE46C:
    ctx->pc = 0x801DE46Cu;
    ctx->downcount -= 2;
    // 801DE46C: addi    r3, r29, 8
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(8);

label_801DE470:
    ctx->pc = 0x801DE470u;
    // 801DE470: bl      0x8028C37C
    {
            ctx->lr = 0x801DE474u;
            ctx->pc = 0x8028C37Cu;
            return;
    }

label_801DE474:
    ctx->pc = 0x801DE474u;
    ctx->downcount -= 5;
    // 801DE474: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801DE478:
    ctx->pc = 0x801DE478u;
    // 801DE478: andi.   r0, r26, 0x0001
    {
        ctx->gpr[0] = ctx->gpr[26] & 0x0001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DE47C:
    ctx->pc = 0x801DE47Cu;
    // 801DE47C: addi    r9, r9, -27760
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27760);

label_801DE480:
    ctx->pc = 0x801DE480u;
    // 801DE480: stw     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DE484:
    ctx->pc = 0x801DE484u;
    // 801DE484: bc    12, 2, 0x801DE490
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE490;
        }
    }

label_801DE488:
    ctx->pc = 0x801DE488u;
    ctx->downcount -= 2;
    // 801DE488: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DE48C:
    ctx->pc = 0x801DE48Cu;
    // 801DE48C: bl      0x80281D80
    {
            ctx->lr = 0x801DE490u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_801DE490:
    ctx->pc = 0x801DE490u;
    ctx->downcount -= 16;
    // 801DE490: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE494:
    ctx->pc = 0x801DE494u;
    // 801DE494: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE498:
    ctx->pc = 0x801DE498u;
    // 801DE498: lmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DE49C:
    ctx->pc = 0x801DE49Cu;
    // 801DE49C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801DE4A0:
    ctx->pc = 0x801DE4A0u;
    // 801DE4A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE4A4:
    ctx->pc = 0x801DE4A4u;
    ctx->downcount -= 16;
    // 801DE4A4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE4A8:
    ctx->pc = 0x801DE4A8u;
    // 801DE4A8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DE4AC:
    ctx->pc = 0x801DE4ACu;
    // 801DE4AC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DE4B0:
    ctx->pc = 0x801DE4B0u;
    // 801DE4B0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE4B4:
    ctx->pc = 0x801DE4B4u;
    // 801DE4B4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DE4B8:
    ctx->pc = 0x801DE4B8u;
    // 801DE4B8: bl      0x801E4B40
    {
            ctx->lr = 0x801DE4BCu;
            ctx->pc = 0x801E4B40u;
            return;
    }

label_801DE4BC:
    ctx->pc = 0x801DE4BCu;
    ctx->downcount -= 8;
    // 801DE4BC: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801DE4C0:
    ctx->pc = 0x801DE4C0u;
    // 801DE4C0: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DE4C4:
    ctx->pc = 0x801DE4C4u;
    // 801DE4C4: addi    r9, r9, 5664
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(5664);

label_801DE4C8:
    ctx->pc = 0x801DE4C8u;
    // 801DE4C8: addi    r4, r4, 5584
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5584);

label_801DE4CC:
    ctx->pc = 0x801DE4CCu;
    // 801DE4CC: stw     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DE4D0:
    ctx->pc = 0x801DE4D0u;
    // 801DE4D0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DE4D4:
    ctx->pc = 0x801DE4D4u;
    // 801DE4D4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801DE4D8:
    ctx->pc = 0x801DE4D8u;
    // 801DE4D8: bl      0x801E1970
    {
            ctx->lr = 0x801DE4DCu;
            ctx->pc = 0x801E1970u;
            return;
    }

label_801DE4DC:
    ctx->pc = 0x801DE4DCu;
    ctx->downcount -= 22;
    // 801DE4DC: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_801DE4E0:
    ctx->pc = 0x801DE4E0u;
    // 801DE4E0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DE4E4:
    ctx->pc = 0x801DE4E4u;
    // 801DE4E4: addi    r9, r9, 20580
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(20580);

label_801DE4E8:
    ctx->pc = 0x801DE4E8u;
    // 801DE4E8: stw     r0, 144(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE4EC:
    ctx->pc = 0x801DE4ECu;
    // 801DE4EC: stw     r9, 140(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DE4F0:
    ctx->pc = 0x801DE4F0u;
    // 801DE4F0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DE4F4:
    ctx->pc = 0x801DE4F4u;
    // 801DE4F4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE4F8:
    ctx->pc = 0x801DE4F8u;
    // 801DE4F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE4FC:
    ctx->pc = 0x801DE4FCu;
    // 801DE4FC: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DE500:
    ctx->pc = 0x801DE500u;
    // 801DE500: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DE504:
    ctx->pc = 0x801DE504u;
    // 801DE504: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE508:
    ctx->pc = 0x801DE508u;
    ctx->downcount -= 17;
    // 801DE508: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE50C:
    ctx->pc = 0x801DE50Cu;
    // 801DE50C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DE510:
    ctx->pc = 0x801DE510u;
    // 801DE510: stmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DE514:
    ctx->pc = 0x801DE514u;
    // 801DE514: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE518:
    ctx->pc = 0x801DE518u;
    // 801DE518: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DE51C:
    ctx->pc = 0x801DE51Cu;
    // 801DE51C: or.   r26, r4, r4
    {
        ctx->gpr[26] = ctx->gpr[4] | ctx->gpr[4];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[26];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DE520:
    ctx->pc = 0x801DE520u;
    // 801DE520: bc    12, 2, 0x801DE5E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE5E0;
        }
    }

label_801DE524:
    ctx->pc = 0x801DE524u;
    ctx->downcount -= 3;
    // 801DE524: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DE528:
    ctx->pc = 0x801DE528u;
    // 801DE528: addi    r3, r3, 5600
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5600);

label_801DE52C:
    ctx->pc = 0x801DE52Cu;
    // 801DE52C: bl      0x80213A94
    {
            ctx->lr = 0x801DE530u;
            ctx->pc = 0x80213A94u;
            return;
    }

label_801DE530:
    ctx->pc = 0x801DE530u;
    ctx->downcount -= 4;
    // 801DE530: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DE534:
    ctx->pc = 0x801DE534u;
    // 801DE534: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DE538:
    ctx->pc = 0x801DE538u;
    // 801DE538: addi    r3, r3, 5616
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5616);

label_801DE53C:
    ctx->pc = 0x801DE53Cu;
    // 801DE53C: bl      0x801C47CC
    {
            ctx->lr = 0x801DE540u;
            ctx->pc = 0x801C47CCu;
            return;
    }

label_801DE540:
    ctx->pc = 0x801DE540u;
    ctx->downcount -= 2;
    // 801DE540: or.   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DE544:
    ctx->pc = 0x801DE544u;
    // 801DE544: bc    12, 2, 0x801DE5BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE5BC;
        }
    }

label_801DE548:
    ctx->pc = 0x801DE548u;
    ctx->downcount -= 5;
    // 801DE548: lis     r4, 27749
    ctx->gpr[4] = ((u32)(s32)(27749) << 16);

label_801DE54C:
    ctx->pc = 0x801DE54Cu;
    // 801DE54C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DE550:
    ctx->pc = 0x801DE550u;
    // 801DE550: ori     r4, r4, 0x766C
    ctx->gpr[4] = ctx->gpr[4] | 0x766Cu;

label_801DE554:
    ctx->pc = 0x801DE554u;
    // 801DE554: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801DE558:
    ctx->pc = 0x801DE558u;
    // 801DE558: bl      0x80250C9C
    {
            ctx->lr = 0x801DE55Cu;
            ctx->pc = 0x80250C9Cu;
            return;
    }

label_801DE55C:
    ctx->pc = 0x801DE55Cu;
    ctx->downcount -= 2;
    // 801DE55C: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DE560:
    ctx->pc = 0x801DE560u;
    // 801DE560: bc    12, 2, 0x801DE5FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE5FC;
        }
    }

label_801DE564:
    ctx->pc = 0x801DE564u;
    ctx->downcount -= 3;
    // 801DE564: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_801DE568:
    ctx->pc = 0x801DE568u;
    // 801DE568: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_801DE56C:
    ctx->pc = 0x801DE56Cu;
    // 801DE56C: addi    r28, r9, -8348
    ctx->gpr[28] = ctx->gpr[9] + (u32)(s32)(-8348);

label_801DE570:
    ctx->downcount -= 2;
    // 801DE570: li      r3, 152
    ctx->gpr[3] = (u32)(s32)(152);

label_801DE574:
    // 801DE574: bl      0x80281C60
    {
            ctx->lr = 0x801DE578u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801DE578:
    ctx->pc = 0x801DE578u;
    ctx->downcount -= 3;
    // 801DE578: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801DE57C:
    // 801DE57C: add   r4, r31, r4
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_801DE580:
    // 801DE580: bl      0x801E4BA0
    {
            ctx->lr = 0x801DE584u;
            ctx->pc = 0x801E4BA0u;
            return;
    }

label_801DE584:
    ctx->downcount -= 6;
    // 801DE584: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DE588:
    // 801DE588: or   r4, r9, r9
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[9];
    }

label_801DE58C:
    // 801DE58C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DE590:
    ctx->pc = 0x801DE590u;
    // 801DE590: stw     r28, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_801DE594:
    ctx->pc = 0x801DE594u;
    // 801DE594: stw     r27, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_801DE598:
    // 801DE598: bl      0x801E1598
    {
            ctx->lr = 0x801DE59Cu;
            ctx->pc = 0x801E1598u;
            return;
    }

label_801DE59C:
    ctx->downcount -= 5;
    // 801DE59C: lis     r4, 27749
    ctx->gpr[4] = ((u32)(s32)(27749) << 16);

label_801DE5A0:
    // 801DE5A0: or   r5, r31, r31
    {
        ctx->gpr[5] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DE5A4:
    // 801DE5A4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DE5A8:
    // 801DE5A8: ori     r4, r4, 0x766C
    ctx->gpr[4] = ctx->gpr[4] | 0x766Cu;

label_801DE5AC:
    // 801DE5AC: bl      0x80250C9C
    {
            ctx->lr = 0x801DE5B0u;
            ctx->pc = 0x80250C9Cu;
            return;
    }

label_801DE5B0:
    ctx->downcount -= 2;
    // 801DE5B0: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DE5B4:
    // 801DE5B4: bc    4, 2, 0x801DE570
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE570u;
                return;
            }
            goto label_801DE570;
        }
    }

label_801DE5B8:
    ctx->pc = 0x801DE5B8u;
    ctx->downcount -= 1;
    // 801DE5B8: b       0x801DE5FC
    {
            goto label_801DE5FC;
    }

label_801DE5BC:
    ctx->pc = 0x801DE5BCu;
    ctx->downcount -= 2;
    // 801DE5BC: li      r3, 152
    ctx->gpr[3] = (u32)(s32)(152);

label_801DE5C0:
    ctx->pc = 0x801DE5C0u;
    // 801DE5C0: bl      0x80281C60
    {
            ctx->lr = 0x801DE5C4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801DE5C4:
    ctx->pc = 0x801DE5C4u;
    ctx->downcount -= 3;
    // 801DE5C4: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DE5C8:
    ctx->pc = 0x801DE5C8u;
    // 801DE5C8: addi    r4, r4, 5628
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5628);

label_801DE5CC:
    ctx->pc = 0x801DE5CCu;
    // 801DE5CC: bl      0x801E4BA0
    {
            ctx->lr = 0x801DE5D0u;
            ctx->pc = 0x801E4BA0u;
            return;
    }

label_801DE5D0:
    ctx->pc = 0x801DE5D0u;
    ctx->downcount -= 3;
    // 801DE5D0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DE5D4:
    ctx->pc = 0x801DE5D4u;
    // 801DE5D4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DE5D8:
    ctx->pc = 0x801DE5D8u;
    // 801DE5D8: bl      0x801E1598
    {
            ctx->lr = 0x801DE5DCu;
            ctx->pc = 0x801E1598u;
            return;
    }

label_801DE5DC:
    ctx->pc = 0x801DE5DCu;
    ctx->downcount -= 1;
    // 801DE5DC: b       0x801DE5FC
    {
            goto label_801DE5FC;
    }

label_801DE5E0:
    ctx->pc = 0x801DE5E0u;
    ctx->downcount -= 2;
    // 801DE5E0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DE5E4:
    ctx->pc = 0x801DE5E4u;
    // 801DE5E4: bl      0x801E1508
    {
            ctx->lr = 0x801DE5E8u;
            ctx->pc = 0x801E1508u;
            return;
    }

label_801DE5E8:
    ctx->pc = 0x801DE5E8u;
    ctx->downcount -= 5;
    // 801DE5E8: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DE5EC:
    ctx->pc = 0x801DE5ECu;
    // 801DE5EC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DE5F0:
    ctx->pc = 0x801DE5F0u;
    // 801DE5F0: addi    r4, r4, 5584
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5584);

label_801DE5F4:
    ctx->pc = 0x801DE5F4u;
    // 801DE5F4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801DE5F8:
    ctx->pc = 0x801DE5F8u;
    // 801DE5F8: bl      0x801E1970
    {
            ctx->lr = 0x801DE5FCu;
            ctx->pc = 0x801E1970u;
            return;
    }

label_801DE5FC:
    ctx->pc = 0x801DE5FCu;
    ctx->downcount -= 17;
    // 801DE5FC: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801DE600:
    ctx->pc = 0x801DE600u;
    // 801DE600: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE604:
    ctx->pc = 0x801DE604u;
    // 801DE604: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE608:
    ctx->pc = 0x801DE608u;
    // 801DE608: lmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DE60C:
    ctx->pc = 0x801DE60Cu;
    // 801DE60C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801DE610:
    ctx->pc = 0x801DE610u;
    // 801DE610: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE614:
    ctx->pc = 0x801DE614u;
    ctx->downcount -= 10;
    // 801DE614: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE618:
    ctx->pc = 0x801DE618u;
    // 801DE618: addi    r4, r4, -1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-1);

label_801DE61C:
    ctx->pc = 0x801DE61Cu;
    // 801DE61C: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801DE620:
    ctx->pc = 0x801DE620u;
    // 801DE620: rlwinm r4, r4, 31, 1, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFCu;
    }

label_801DE624:
    ctx->pc = 0x801DE624u;
    // 801DE624: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801DE628:
    ctx->pc = 0x801DE628u;
    // 801DE628: lwzx    r0, r4, r9
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE62C:
    ctx->pc = 0x801DE62Cu;
    // 801DE62C: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE630:
    ctx->pc = 0x801DE630u;
    // 801DE630: stwx    r3, r4, r9
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[9];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DE634:
    ctx->pc = 0x801DE634u;
    // 801DE634: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DE638:
    ctx->pc = 0x801DE638u;
    // 801DE638: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE63C:
    ctx->pc = 0x801DE63Cu;
    ctx->downcount -= 8;
    // 801DE63C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE640:
    ctx->pc = 0x801DE640u;
    // 801DE640: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DE644:
    ctx->pc = 0x801DE644u;
    // 801DE644: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE648:
    ctx->pc = 0x801DE648u;
    // 801DE648: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801DE64C:
    ctx->pc = 0x801DE64Cu;
    // 801DE64C: andi.   r0, r4, 0x0001
    {
        ctx->gpr[0] = ctx->gpr[4] & 0x0001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DE650:
    ctx->pc = 0x801DE650u;
    // 801DE650: addi    r9, r9, -27760
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27760);

label_801DE654:
    ctx->pc = 0x801DE654u;
    // 801DE654: stw     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DE658:
    ctx->pc = 0x801DE658u;
    // 801DE658: bc    12, 2, 0x801DE660
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE660;
        }
    }

label_801DE65C:
    ctx->pc = 0x801DE65Cu;
    ctx->downcount -= 1;
    // 801DE65C: bl      0x80281D80
    {
            ctx->lr = 0x801DE660u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_801DE660:
    ctx->pc = 0x801DE660u;
    ctx->downcount -= 5;
    // 801DE660: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE664:
    ctx->pc = 0x801DE664u;
    // 801DE664: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE668:
    ctx->pc = 0x801DE668u;
    // 801DE668: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DE66C:
    ctx->pc = 0x801DE66Cu;
    // 801DE66C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE670:
    ctx->pc = 0x801DE670u;
    ctx->downcount -= 7;
    // 801DE670: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE674:
    ctx->pc = 0x801DE674u;
    // 801DE674: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DE678:
    ctx->pc = 0x801DE678u;
    // 801DE678: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE67C:
    ctx->pc = 0x801DE67Cu;
    // 801DE67C: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DE680:
    ctx->pc = 0x801DE680u;
    // 801DE680: lis     r4, 28009
    ctx->gpr[4] = ((u32)(s32)(28009) << 16);

label_801DE684:
    ctx->pc = 0x801DE684u;
    // 801DE684: ori     r4, r4, 0x6E66
    ctx->gpr[4] = ctx->gpr[4] | 0x6E66u;

label_801DE688:
    ctx->pc = 0x801DE688u;
    // 801DE688: bl      0x80213200
    {
            ctx->lr = 0x801DE68Cu;
            ctx->pc = 0x80213200u;
            return;
    }

label_801DE68C:
    ctx->pc = 0x801DE68Cu;
    ctx->downcount -= 5;
    // 801DE68C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE690:
    ctx->pc = 0x801DE690u;
    // 801DE690: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE694:
    ctx->pc = 0x801DE694u;
    // 801DE694: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DE698:
    ctx->pc = 0x801DE698u;
    // 801DE698: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE69C:
    ctx->pc = 0x801DE69Cu;
    ctx->downcount -= 7;
    // 801DE69C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE6A0:
    ctx->pc = 0x801DE6A0u;
    // 801DE6A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DE6A4:
    ctx->pc = 0x801DE6A4u;
    // 801DE6A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE6A8:
    ctx->pc = 0x801DE6A8u;
    // 801DE6A8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DE6AC:
    ctx->pc = 0x801DE6ACu;
    // 801DE6AC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801DE6B0:
    ctx->pc = 0x801DE6B0u;
    // 801DE6B0: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_801DE6B4:
    ctx->pc = 0x801DE6B4u;
    // 801DE6B4: bl      0x801DE2BC
    {
            ctx->lr = 0x801DE6B8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE2BCu;
                return;
            }
            goto label_801DE2BC;
    }

label_801DE6B8:
    ctx->pc = 0x801DE6B8u;
    ctx->downcount -= 5;
    // 801DE6B8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE6BC:
    ctx->pc = 0x801DE6BCu;
    // 801DE6BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE6C0:
    ctx->pc = 0x801DE6C0u;
    // 801DE6C0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DE6C4:
    ctx->pc = 0x801DE6C4u;
    // 801DE6C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE6C8:
    ctx->pc = 0x801DE6C8u;
    ctx->downcount -= 26;
    // 801DE6C8: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE6CC:
    ctx->pc = 0x801DE6CCu;
    // 801DE6CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DE6D0:
    ctx->pc = 0x801DE6D0u;
    // 801DE6D0: stmw     r29, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DE6D4:
    ctx->pc = 0x801DE6D4u;
    // 801DE6D4: stw     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE6D8:
    ctx->pc = 0x801DE6D8u;
    // 801DE6D8: addi    r31, r1, 8
    ctx->gpr[31] = ctx->gpr[1] + (u32)(s32)(8);

label_801DE6DC:
    ctx->pc = 0x801DE6DCu;
    // 801DE6DC: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DE6E0:
    ctx->pc = 0x801DE6E0u;
    // 801DE6E0: stw     r31, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801DE6E4:
    ctx->pc = 0x801DE6E4u;
    // 801DE6E4: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DE6E8:
    ctx->pc = 0x801DE6E8u;
    // 801DE6E8: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DE6EC:
    ctx->pc = 0x801DE6ECu;
    // 801DE6EC: lwz     r9, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE6F0:
    ctx->pc = 0x801DE6F0u;
    // 801DE6F0: lha     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801DE6F4:
    ctx->pc = 0x801DE6F4u;
    // 801DE6F4: lwz     r9, 36(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(36);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE6F8:
    ctx->pc = 0x801DE6F8u;
    // 801DE6F8: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DE6FC:
    ctx->pc = 0x801DE6FCu;
    // 801DE6FC: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801DE700:
    ctx->pc = 0x801DE700u;
    // 801DE700: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801DE704u;
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE704:
    ctx->pc = 0x801DE704u;
    ctx->downcount -= 3;
    // 801DE704: or.   r3, r3, r3
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

label_801DE708:
    ctx->pc = 0x801DE708u;
    // 801DE708: or   r6, r31, r31
    {
        ctx->gpr[6] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DE70C:
    ctx->pc = 0x801DE70Cu;
    // 801DE70C: bc    12, 2, 0x801DE7E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE7E0;
        }
    }

label_801DE710:
    ctx->pc = 0x801DE710u;
    ctx->downcount -= 4;
    // 801DE710: addi    r9, r3, 88
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(88);

label_801DE714:
    ctx->pc = 0x801DE714u;
    // 801DE714: addi    r10, r1, 24
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(24);

label_801DE718:
    ctx->pc = 0x801DE718u;
    // 801DE718: lwz     r8, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801DE71C:
    ctx->pc = 0x801DE71Cu;
    // 801DE71C: or   r7, r10, r10
    {
        ctx->gpr[7] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801DE720:
    ctx->downcount -= 2;
    // 801DE720: cmpw    r9, r8
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

label_801DE724:
    // 801DE724: bc    12, 2, 0x801DE748
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE748;
        }
    }

label_801DE728:
    ctx->downcount -= 4;
    // 801DE728: or   r11, r10, r10
    {
        ctx->gpr[11] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801DE72C:
    // 801DE72C: addi    r10, r10, 2
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(2);

label_801DE730:
    // 801DE730: cmpwi   r11, 0
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

label_801DE734:
    // 801DE734: bc    12, 2, 0x801DE720
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE720u;
                return;
            }
            goto label_801DE720;
        }
    }

label_801DE738:
    ctx->pc = 0x801DE738u;
    ctx->downcount -= 4;
    // 801DE738: lhz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801DE73C:
    // 801DE73C: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

label_801DE740:
    ctx->pc = 0x801DE740u;
    // 801DE740: sth     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801DE744:
    // 801DE744: b       0x801DE720
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE720u;
                return;
            }
            goto label_801DE720;
    }

label_801DE748:
    ctx->pc = 0x801DE748u;
    ctx->downcount -= 5;
    // 801DE748: stw     r10, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801DE74C:
    ctx->pc = 0x801DE74Cu;
    // 801DE74C: or   r11, r7, r7
    {
        ctx->gpr[11] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801DE750:
    ctx->pc = 0x801DE750u;
    // 801DE750: or   r8, r6, r6
    {
        ctx->gpr[8] = ctx->gpr[6] | ctx->gpr[6];
    }

label_801DE754:
    ctx->pc = 0x801DE754u;
    // 801DE754: cmpw    r7, r10
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(ctx->gpr[10]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE758:
    ctx->pc = 0x801DE758u;
    // 801DE758: bc    12, 2, 0x801DE780
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE780;
        }
    }

label_801DE75C:
    ctx->downcount -= 4;
    // 801DE75C: or   r9, r8, r8
    {
        ctx->gpr[9] = ctx->gpr[8] | ctx->gpr[8];
    }

label_801DE760:
    // 801DE760: addi    r8, r8, 2
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(2);

label_801DE764:
    // 801DE764: cmpwi   r9, 0
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

label_801DE768:
    // 801DE768: bc    12, 2, 0x801DE778
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE778;
        }
    }

label_801DE76C:
    ctx->pc = 0x801DE76Cu;
    ctx->downcount -= 3;
    // 801DE76C: lhz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801DE770:
    // 801DE770: addi    r11, r11, 2
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2);

label_801DE774:
    ctx->pc = 0x801DE774u;
    // 801DE774: sth     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801DE778:
    ctx->downcount -= 2;
    // 801DE778: cmpw    r11, r10
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[10]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE77C:
    // 801DE77C: bc    4, 2, 0x801DE75C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE75Cu;
                return;
            }
            goto label_801DE75C;
        }
    }

label_801DE780:
    ctx->pc = 0x801DE780u;
    ctx->downcount -= 5;
    // 801DE780: lwz     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE784:
    ctx->pc = 0x801DE784u;
    // 801DE784: or   r11, r7, r7
    {
        ctx->gpr[11] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801DE788:
    ctx->pc = 0x801DE788u;
    // 801DE788: stw     r8, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_801DE78C:
    ctx->pc = 0x801DE78Cu;
    // 801DE78C: cmpw    r7, r9
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE790:
    ctx->pc = 0x801DE790u;
    // 801DE790: bc    12, 2, 0x801DE7A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE7A0;
        }
    }

label_801DE794:
    loop_801DE794(ctx);
    if (ctx->pc == 0x801DE7A0u) goto label_801DE7A0;
    return;
label_801DE798:
    // 801DE798: cmpw    r11, r9
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE79C:
    // 801DE79C: bc    4, 2, 0x801DE794
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE794u;
                return;
            }
            goto label_801DE794;
        }
    }

label_801DE7A0:
    ctx->pc = 0x801DE7A0u;
    ctx->downcount -= 6;
    // 801DE7A0: lwz     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE7A4:
    ctx->pc = 0x801DE7A4u;
    // 801DE7A4: or   r11, r7, r7
    {
        ctx->gpr[11] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801DE7A8:
    ctx->pc = 0x801DE7A8u;
    // 801DE7A8: subf   r8, r11, r9
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[8] = res;
    }

label_801DE7AC:
    ctx->pc = 0x801DE7ACu;
    // 801DE7AC: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801DE7B0:
    ctx->pc = 0x801DE7B0u;
    // 801DE7B0: srawi. r10, r0, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[10] = value;
        } else if (sh > 31) {
            ctx->gpr[10] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[10] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DE7B4:
    ctx->pc = 0x801DE7B4u;
    // 801DE7B4: bc    4, 1, 0x801DE7D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DE7D0;
        }
    }

label_801DE7B8:
    loop_801DE7B8(ctx);
    if (ctx->pc == 0x801DE7D0u) goto label_801DE7D0;
    return;
label_801DE7BC:
    // 801DE7BC: addic.  r10, r10, -1
    {
        u64 a = ctx->gpr[10];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[10] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DE7C0:
    // 801DE7C0: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

label_801DE7C4:
    ctx->pc = 0x801DE7C4u;
    // 801DE7C4: sth     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801DE7C8:
    // 801DE7C8: addi    r11, r11, 2
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2);

label_801DE7CC:
    // 801DE7CC: bc    12, 1, 0x801DE7B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE7B8u;
                return;
            }
            goto label_801DE7B8;
        }
    }

label_801DE7D0:
    ctx->pc = 0x801DE7D0u;
    ctx->downcount -= 4;
    // 801DE7D0: lwz     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE7D4:
    ctx->pc = 0x801DE7D4u;
    // 801DE7D4: subf   r0, r8, r0
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801DE7D8:
    ctx->pc = 0x801DE7D8u;
    // 801DE7D8: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE7DC:
    ctx->pc = 0x801DE7DCu;
    // 801DE7DC: b       0x801DE8C4
    {
            goto label_801DE8C4;
    }

label_801DE7E0:
    ctx->pc = 0x801DE7E0u;
    ctx->downcount -= 12;
    // 801DE7E0: lwz     r10, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801DE7E4:
    ctx->pc = 0x801DE7E4u;
    // 801DE7E4: or   r7, r6, r6
    {
        ctx->gpr[7] = ctx->gpr[6] | ctx->gpr[6];
    }

label_801DE7E8:
    ctx->pc = 0x801DE7E8u;
    // 801DE7E8: lwz     r8, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801DE7EC:
    ctx->pc = 0x801DE7ECu;
    // 801DE7EC: addi    r11, r10, 32
    ctx->gpr[11] = ctx->gpr[10] + (u32)(s32)(32);

label_801DE7F0:
    ctx->pc = 0x801DE7F0u;
    // 801DE7F0: lwz     r0, 32(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE7F4:
    ctx->pc = 0x801DE7F4u;
    // 801DE7F4: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE7F8:
    ctx->pc = 0x801DE7F8u;
    // 801DE7F8: cmpw    r6, r8
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE7FC:
    ctx->pc = 0x801DE7FCu;
    // 801DE7FC: add   r0, r0, r0
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801DE800:
    ctx->pc = 0x801DE800u;
    // 801DE800: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_801DE804:
    ctx->pc = 0x801DE804u;
    // 801DE804: add   r11, r11, r9
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801DE808:
    ctx->pc = 0x801DE808u;
    // 801DE808: add   r3, r11, r0
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801DE80C:
    ctx->pc = 0x801DE80Cu;
    // 801DE80C: bc    12, 2, 0x801DE894
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE894;
        }
    }

label_801DE810:
    ctx->downcount -= 2;
    // 801DE810: cmpw    r11, r3
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE814:
    // 801DE814: bc    4, 2, 0x801DE878
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DE878;
        }
    }

label_801DE818:
    ctx->pc = 0x801DE818u;
    ctx->downcount -= 5;
    // 801DE818: lwz     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE81C:
    // 801DE81C: or   r9, r7, r7
    {
        ctx->gpr[9] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801DE820:
    // 801DE820: or   r8, r0, r0
    {
        ctx->gpr[8] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801DE824:
    // 801DE824: cmpw    r7, r0
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE828:
    // 801DE828: bc    12, 2, 0x801DE838
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE838;
        }
    }

label_801DE82C:
    loop_801DE82C(ctx);
    if (ctx->pc == 0x801DE838u) goto label_801DE838;
    return;
label_801DE830:
    // 801DE830: cmpw    r9, r0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE834:
    // 801DE834: bc    4, 2, 0x801DE82C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE82Cu;
                return;
            }
            goto label_801DE82C;
        }
    }

label_801DE838:
    ctx->downcount -= 6;
    // 801DE838: or   r11, r0, r0
    {
        ctx->gpr[11] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801DE83C:
    // 801DE83C: or   r10, r7, r7
    {
        ctx->gpr[10] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801DE840:
    // 801DE840: subf   r0, r11, r8
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801DE844:
    // 801DE844: subf   r8, r10, r11
    {
        u32 a = ~ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[8] = res;
    }

label_801DE848:
    // 801DE848: srawi. r9, r0, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[9] = value;
        } else if (sh > 31) {
            ctx->gpr[9] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[9] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DE84C:
    // 801DE84C: bc    4, 1, 0x801DE868
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DE868;
        }
    }

label_801DE850:
    loop_801DE850(ctx);
    if (ctx->pc == 0x801DE868u) goto label_801DE868;
    return;
label_801DE854:
    // 801DE854: addic.  r9, r9, -1
    {
        u64 a = ctx->gpr[9];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[9] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DE858:
    // 801DE858: addi    r11, r11, 2
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2);

label_801DE85C:
    ctx->pc = 0x801DE85Cu;
    // 801DE85C: sth     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801DE860:
    // 801DE860: addi    r10, r10, 2
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(2);

label_801DE864:
    // 801DE864: bc    12, 1, 0x801DE850
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE850u;
                return;
            }
            goto label_801DE850;
        }
    }

label_801DE868:
    ctx->pc = 0x801DE868u;
    ctx->downcount -= 4;
    // 801DE868: lwz     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE86C:
    // 801DE86C: subf   r0, r8, r0
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801DE870:
    ctx->pc = 0x801DE870u;
    // 801DE870: stw     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE874:
    // 801DE874: b       0x801DE8C4
    {
            goto label_801DE8C4;
    }

label_801DE878:
    ctx->pc = 0x801DE878u;
    ctx->downcount -= 7;
    // 801DE878: lhz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801DE87C:
    // 801DE87C: addi    r11, r11, 2
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2);

label_801DE880:
    ctx->pc = 0x801DE880u;
    // 801DE880: sth     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801DE884:
    // 801DE884: addi    r7, r7, 2
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(2);

label_801DE888:
    ctx->pc = 0x801DE888u;
    // 801DE888: lwz     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE88C:
    // 801DE88C: cmpw    r7, r0
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE890:
    // 801DE890: bc    4, 2, 0x801DE810
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE810u;
                return;
            }
            goto label_801DE810;
        }
    }

label_801DE894:
    ctx->pc = 0x801DE894u;
    ctx->downcount -= 1;
    // 801DE894: or   r9, r7, r7
    {
        ctx->gpr[9] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801DE898:
    ctx->downcount -= 2;
    // 801DE898: cmpw    r11, r3
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE89C:
    // 801DE89C: bc    12, 2, 0x801DE8C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE8C0;
        }
    }

label_801DE8A0:
    ctx->downcount -= 4;
    // 801DE8A0: or   r10, r9, r9
    {
        ctx->gpr[10] = ctx->gpr[9] | ctx->gpr[9];
    }

label_801DE8A4:
    // 801DE8A4: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

label_801DE8A8:
    // 801DE8A8: cmpwi   r10, 0
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

label_801DE8AC:
    // 801DE8AC: bc    12, 2, 0x801DE898
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE898u;
                return;
            }
            goto label_801DE898;
        }
    }

label_801DE8B0:
    ctx->pc = 0x801DE8B0u;
    ctx->downcount -= 4;
    // 801DE8B0: lhz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801DE8B4:
    // 801DE8B4: addi    r11, r11, 2
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2);

label_801DE8B8:
    ctx->pc = 0x801DE8B8u;
    // 801DE8B8: sth     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801DE8BC:
    // 801DE8BC: b       0x801DE898
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE898u;
                return;
            }
            goto label_801DE898;
    }

label_801DE8C0:
    ctx->pc = 0x801DE8C0u;
    ctx->downcount -= 1;
    // 801DE8C0: stw     r9, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801DE8C4:
    ctx->pc = 0x801DE8C4u;
    ctx->downcount -= 5;
    // 801DE8C4: lwz     r8, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801DE8C8:
    ctx->pc = 0x801DE8C8u;
    // 801DE8C8: or   r10, r6, r6
    {
        ctx->gpr[10] = ctx->gpr[6] | ctx->gpr[6];
    }

label_801DE8CC:
    ctx->pc = 0x801DE8CCu;
    // 801DE8CC: or   r11, r29, r29
    {
        ctx->gpr[11] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DE8D0:
    ctx->pc = 0x801DE8D0u;
    // 801DE8D0: cmpw    r6, r8
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE8D4:
    ctx->pc = 0x801DE8D4u;
    // 801DE8D4: bc    12, 2, 0x801DE8FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE8FC;
        }
    }

label_801DE8D8:
    ctx->downcount -= 4;
    // 801DE8D8: or   r9, r11, r11
    {
        ctx->gpr[9] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801DE8DC:
    // 801DE8DC: addi    r11, r11, 2
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2);

label_801DE8E0:
    // 801DE8E0: cmpwi   r9, 0
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

label_801DE8E4:
    // 801DE8E4: bc    12, 2, 0x801DE8F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE8F4;
        }
    }

label_801DE8E8:
    ctx->pc = 0x801DE8E8u;
    ctx->downcount -= 3;
    // 801DE8E8: lhz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801DE8EC:
    // 801DE8EC: addi    r10, r10, 2
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(2);

label_801DE8F0:
    ctx->pc = 0x801DE8F0u;
    // 801DE8F0: sth     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801DE8F4:
    ctx->downcount -= 2;
    // 801DE8F4: cmpw    r10, r8
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE8F8:
    // 801DE8F8: bc    4, 2, 0x801DE8D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE8D8u;
                return;
            }
            goto label_801DE8D8;
        }
    }

label_801DE8FC:
    ctx->pc = 0x801DE8FCu;
    ctx->downcount -= 5;
    // 801DE8FC: lwz     r9, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DE900:
    ctx->pc = 0x801DE900u;
    // 801DE900: or   r10, r6, r6
    {
        ctx->gpr[10] = ctx->gpr[6] | ctx->gpr[6];
    }

label_801DE904:
    ctx->pc = 0x801DE904u;
    // 801DE904: stw     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DE908:
    ctx->pc = 0x801DE908u;
    // 801DE908: cmpw    r6, r9
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE90C:
    ctx->pc = 0x801DE90Cu;
    // 801DE90C: bc    12, 2, 0x801DE91C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DE91C;
        }
    }

label_801DE910:
    loop_801DE910(ctx);
    if (ctx->pc == 0x801DE91Cu) goto label_801DE91C;
    return;
label_801DE914:
    // 801DE914: cmpw    r10, r9
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DE918:
    // 801DE918: bc    4, 2, 0x801DE910
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE910u;
                return;
            }
            goto label_801DE910;
        }
    }

label_801DE91C:
    ctx->pc = 0x801DE91Cu;
    ctx->downcount -= 6;
    // 801DE91C: lwz     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE920:
    ctx->pc = 0x801DE920u;
    // 801DE920: subf   r8, r6, r9
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[8] = res;
    }

label_801DE924:
    ctx->pc = 0x801DE924u;
    // 801DE924: or   r10, r6, r6
    {
        ctx->gpr[10] = ctx->gpr[6] | ctx->gpr[6];
    }

label_801DE928:
    ctx->pc = 0x801DE928u;
    // 801DE928: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801DE92C:
    ctx->pc = 0x801DE92Cu;
    // 801DE92C: srawi. r11, r0, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[11] = value;
        } else if (sh > 31) {
            ctx->gpr[11] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[11] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DE930:
    ctx->pc = 0x801DE930u;
    // 801DE930: bc    4, 1, 0x801DE94C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DE94C;
        }
    }

label_801DE934:
    loop_801DE934(ctx);
    if (ctx->pc == 0x801DE94Cu) goto label_801DE94C;
    return;
label_801DE938:
    // 801DE938: addic.  r11, r11, -1
    {
        u64 a = ctx->gpr[11];
        u64 b = (u32)(s32)(-1);
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

label_801DE93C:
    // 801DE93C: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

label_801DE940:
    ctx->pc = 0x801DE940u;
    // 801DE940: sth     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801DE944:
    // 801DE944: addi    r10, r10, 2
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(2);

label_801DE948:
    // 801DE948: bc    12, 1, 0x801DE934
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE934u;
                return;
            }
            goto label_801DE934;
        }
    }

label_801DE94C:
    ctx->pc = 0x801DE94Cu;
    ctx->downcount -= 20;
    // 801DE94C: lwz     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE950:
    ctx->pc = 0x801DE950u;
    // 801DE950: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DE954:
    ctx->pc = 0x801DE954u;
    // 801DE954: subf   r0, r8, r0
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801DE958:
    ctx->pc = 0x801DE958u;
    // 801DE958: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE95C:
    ctx->pc = 0x801DE95Cu;
    // 801DE95C: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DE960:
    ctx->pc = 0x801DE960u;
    // 801DE960: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DE964:
    ctx->pc = 0x801DE964u;
    // 801DE964: lmw     r29, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DE968:
    ctx->pc = 0x801DE968u;
    // 801DE968: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_801DE96C:
    ctx->pc = 0x801DE96Cu;
    // 801DE96C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DE970:
    ctx->pc = 0x801DE970u;
    ctx->downcount -= 7;
    // 801DE970: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DE974:
    ctx->pc = 0x801DE974u;
    // 801DE974: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DE978:
    ctx->pc = 0x801DE978u;
    // 801DE978: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DE97C:
    ctx->pc = 0x801DE97Cu;
    // 801DE97C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DE980:
    ctx->pc = 0x801DE980u;
    // 801DE980: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_801DE984:
    ctx->pc = 0x801DE984u;
    // 801DE984: cmpw    r4, r0
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

label_801DE988:
    ctx->pc = 0x801DE988u;
    // 801DE988: bc    4, 2, 0x801DEA34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DEA34;
        }
    }

label_801DE98C:
    ctx->pc = 0x801DE98Cu;
    ctx->downcount -= 2;
    // 801DE98C: cmpwi   r3, 0
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

label_801DE990:
    ctx->pc = 0x801DE990u;
    // 801DE990: bc    12, 2, 0x801DEA34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DEA34;
        }
    }

label_801DE994:
    ctx->pc = 0x801DE994u;
    ctx->downcount -= 5;
    // 801DE994: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_801DE998:
    ctx->pc = 0x801DE998u;
    // 801DE998: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_801DE99C:
    ctx->pc = 0x801DE99Cu;
    // 801DE99C: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_801DE9A0:
    ctx->pc = 0x801DE9A0u;
    // 801DE9A0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE9A4:
    ctx->pc = 0x801DE9A4u;
    // 801DE9A4: bl      0x80252AF0
    {
            ctx->lr = 0x801DE9A8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE9A8:
    ctx->pc = 0x801DE9A8u;
    ctx->downcount -= 5;
    // 801DE9A8: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_801DE9AC:
    ctx->pc = 0x801DE9ACu;
    // 801DE9AC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801DE9B0:
    ctx->pc = 0x801DE9B0u;
    // 801DE9B0: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_801DE9B4:
    ctx->pc = 0x801DE9B4u;
    // 801DE9B4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE9B8:
    ctx->pc = 0x801DE9B8u;
    // 801DE9B8: bl      0x80252AF0
    {
            ctx->lr = 0x801DE9BCu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE9BC:
    ctx->pc = 0x801DE9BCu;
    ctx->downcount -= 5;
    // 801DE9BC: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_801DE9C0:
    ctx->pc = 0x801DE9C0u;
    // 801DE9C0: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_801DE9C4:
    ctx->pc = 0x801DE9C4u;
    // 801DE9C4: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_801DE9C8:
    ctx->pc = 0x801DE9C8u;
    // 801DE9C8: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_801DE9CC:
    ctx->pc = 0x801DE9CCu;
    // 801DE9CC: bl      0x80252AF0
    {
            ctx->lr = 0x801DE9D0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE9D0:
    ctx->pc = 0x801DE9D0u;
    ctx->downcount -= 5;
    // 801DE9D0: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_801DE9D4:
    ctx->pc = 0x801DE9D4u;
    // 801DE9D4: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_801DE9D8:
    ctx->pc = 0x801DE9D8u;
    // 801DE9D8: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_801DE9DC:
    ctx->pc = 0x801DE9DCu;
    // 801DE9DC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE9E0:
    ctx->pc = 0x801DE9E0u;
    // 801DE9E0: bl      0x80252AF0
    {
            ctx->lr = 0x801DE9E4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE9E4:
    ctx->pc = 0x801DE9E4u;
    ctx->downcount -= 5;
    // 801DE9E4: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_801DE9E8:
    ctx->pc = 0x801DE9E8u;
    // 801DE9E8: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_801DE9EC:
    ctx->pc = 0x801DE9ECu;
    // 801DE9EC: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_801DE9F0:
    ctx->pc = 0x801DE9F0u;
    // 801DE9F0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DE9F4:
    ctx->pc = 0x801DE9F4u;
    // 801DE9F4: bl      0x80252AF0
    {
            ctx->lr = 0x801DE9F8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DE9F8:
    ctx->pc = 0x801DE9F8u;
    ctx->downcount -= 5;
    // 801DE9F8: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_801DE9FC:
    ctx->pc = 0x801DE9FCu;
    // 801DE9FC: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_801DEA00:
    ctx->pc = 0x801DEA00u;
    // 801DEA00: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_801DEA04:
    ctx->pc = 0x801DEA04u;
    // 801DEA04: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DEA08:
    ctx->pc = 0x801DEA08u;
    // 801DEA08: bl      0x80252AF0
    {
            ctx->lr = 0x801DEA0Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DEA0C:
    ctx->pc = 0x801DEA0Cu;
    ctx->downcount -= 5;
    // 801DEA0C: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_801DEA10:
    ctx->pc = 0x801DEA10u;
    // 801DEA10: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_801DEA14:
    ctx->pc = 0x801DEA14u;
    // 801DEA14: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_801DEA18:
    ctx->pc = 0x801DEA18u;
    // 801DEA18: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DEA1C:
    ctx->pc = 0x801DEA1Cu;
    // 801DEA1C: bl      0x80252AF0
    {
            ctx->lr = 0x801DEA20u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DEA20:
    ctx->pc = 0x801DEA20u;
    ctx->downcount -= 5;
    // 801DEA20: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_801DEA24:
    ctx->pc = 0x801DEA24u;
    // 801DEA24: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_801DEA28:
    ctx->pc = 0x801DEA28u;
    // 801DEA28: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_801DEA2C:
    ctx->pc = 0x801DEA2Cu;
    // 801DEA2C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DEA30:
    ctx->pc = 0x801DEA30u;
    // 801DEA30: bl      0x80252AF0
    {
            ctx->lr = 0x801DEA34u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DEA34:
    ctx->pc = 0x801DEA34u;
    ctx->downcount -= 5;
    // 801DEA34: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DEA38:
    ctx->pc = 0x801DEA38u;
    // 801DEA38: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DEA3C:
    ctx->pc = 0x801DEA3Cu;
    // 801DEA3C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DEA40:
    ctx->pc = 0x801DEA40u;
    // 801DEA40: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DEA44:
    ctx->pc = 0x801DEA44u;
    ctx->downcount -= 17;
    // 801DEA44: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DEA48:
    ctx->pc = 0x801DEA48u;
    // 801DEA48: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DEA4C:
    ctx->pc = 0x801DEA4Cu;
    // 801DEA4C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DEA50:
    ctx->pc = 0x801DEA50u;
    // 801DEA50: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DEA54:
    ctx->pc = 0x801DEA54u;
    // 801DEA54: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DEA58:
    ctx->pc = 0x801DEA58u;
    // 801DEA58: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DEA5C:
    ctx->pc = 0x801DEA5Cu;
    // 801DEA5C: bl      0x801D1500
    {
            ctx->lr = 0x801DEA60u;
            ctx->pc = 0x801D1500u;
            return;
    }

label_801DEA60:
    ctx->pc = 0x801DEA60u;
    ctx->downcount -= 3;
    // 801DEA60: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DEA64:
    ctx->pc = 0x801DEA64u;
    // 801DEA64: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEA68:
    ctx->pc = 0x801DEA68u;
    // 801DEA68: bl      0x80283AF4
    {
            ctx->lr = 0x801DEA6Cu;
            ctx->pc = 0x80283AF4u;
            return;
    }

label_801DEA6C:
    ctx->pc = 0x801DEA6Cu;
    ctx->downcount -= 17;
    // 801DEA6C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEA70:
    ctx->pc = 0x801DEA70u;
    // 801DEA70: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DEA74:
    ctx->pc = 0x801DEA74u;
    // 801DEA74: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DEA78:
    ctx->pc = 0x801DEA78u;
    // 801DEA78: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DEA7C:
    ctx->pc = 0x801DEA7Cu;
    // 801DEA7C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DEA80:
    ctx->pc = 0x801DEA80u;
    // 801DEA80: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DEA84:
    ctx->pc = 0x801DEA84u;
    ctx->downcount -= 7;
    // 801DEA84: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DEA88:
    ctx->pc = 0x801DEA88u;
    // 801DEA88: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DEA8C:
    ctx->pc = 0x801DEA8Cu;
    // 801DEA8C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DEA90:
    ctx->pc = 0x801DEA90u;
    // 801DEA90: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DEA94:
    ctx->pc = 0x801DEA94u;
    // 801DEA94: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801DEA98:
    ctx->pc = 0x801DEA98u;
    // 801DEA98: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_801DEA9C:
    ctx->pc = 0x801DEA9Cu;
    // 801DEA9C: bl      0x801DE970
    {
            ctx->lr = 0x801DEAA0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DE970u;
                return;
            }
            goto label_801DE970;
    }

label_801DEAA0:
    ctx->pc = 0x801DEAA0u;
    ctx->downcount -= 5;
    // 801DEAA0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DEAA4:
    ctx->pc = 0x801DEAA4u;
    // 801DEAA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DEAA8:
    ctx->pc = 0x801DEAA8u;
    // 801DEAA8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DEAAC:
    ctx->pc = 0x801DEAACu;
    // 801DEAAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DEAB0:
    ctx->pc = 0x801DEAB0u;
    ctx->downcount -= 7;
    // 801DEAB0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DEAB4:
    ctx->pc = 0x801DEAB4u;
    // 801DEAB4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DEAB8:
    ctx->pc = 0x801DEAB8u;
    // 801DEAB8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DEABC:
    ctx->pc = 0x801DEABCu;
    // 801DEABC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DEAC0:
    ctx->pc = 0x801DEAC0u;
    // 801DEAC0: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_801DEAC4:
    ctx->pc = 0x801DEAC4u;
    // 801DEAC4: cmpw    r4, r0
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

label_801DEAC8:
    ctx->pc = 0x801DEAC8u;
    // 801DEAC8: bc    4, 2, 0x801DEAE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DEAE8;
        }
    }

label_801DEACC:
    ctx->pc = 0x801DEACCu;
    ctx->downcount -= 2;
    // 801DEACC: cmpwi   r3, 0
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

label_801DEAD0:
    ctx->pc = 0x801DEAD0u;
    // 801DEAD0: bc    12, 2, 0x801DEAE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DEAE8;
        }
    }

label_801DEAD4:
    ctx->pc = 0x801DEAD4u;
    ctx->downcount -= 5;
    // 801DEAD4: lis     r3, 27765
    ctx->gpr[3] = ((u32)(s32)(27765) << 16);

label_801DEAD8:
    ctx->pc = 0x801DEAD8u;
    // 801DEAD8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DEADC:
    ctx->pc = 0x801DEADCu;
    // 801DEADC: ori     r3, r3, 0x6121
    ctx->gpr[3] = ctx->gpr[3] | 0x6121u;

label_801DEAE0:
    ctx->pc = 0x801DEAE0u;
    // 801DEAE0: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_801DEAE4:
    ctx->pc = 0x801DEAE4u;
    // 801DEAE4: bl      0x80252AF0
    {
            ctx->lr = 0x801DEAE8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DEAE8:
    ctx->pc = 0x801DEAE8u;
    ctx->downcount -= 5;
    // 801DEAE8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DEAEC:
    ctx->pc = 0x801DEAECu;
    // 801DEAEC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DEAF0:
    ctx->pc = 0x801DEAF0u;
    // 801DEAF0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DEAF4:
    ctx->pc = 0x801DEAF4u;
    // 801DEAF4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DEAF8:
    ctx->pc = 0x801DEAF8u;
    ctx->downcount -= 15;
    // 801DEAF8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DEAFC:
    ctx->pc = 0x801DEAFCu;
    // 801DEAFC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DEB00:
    ctx->pc = 0x801DEB00u;
    // 801DEB00: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DEB04:
    ctx->pc = 0x801DEB04u;
    // 801DEB04: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DEB08:
    ctx->pc = 0x801DEB08u;
    // 801DEB08: bl      0x8026B0D4
    {
            ctx->lr = 0x801DEB0Cu;
            ctx->pc = 0x8026B0D4u;
            return;
    }

label_801DEB0C:
    ctx->pc = 0x801DEB0Cu;
    ctx->downcount -= 3;
    // 801DEB0C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DEB10:
    ctx->pc = 0x801DEB10u;
    // 801DEB10: stw     r30, -26944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26944);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801DEB14:
    ctx->pc = 0x801DEB14u;
    // 801DEB14: bl      0x80257FC4
    {
            ctx->lr = 0x801DEB18u;
            ctx->pc = 0x80257FC4u;
            return;
    }

label_801DEB18:
    ctx->pc = 0x801DEB18u;
    ctx->downcount -= 2;
    // 801DEB18: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB1C:
    ctx->pc = 0x801DEB1Cu;
    // 801DEB1C: bl      0x8025BF58
    {
            ctx->lr = 0x801DEB20u;
            ctx->pc = 0x8025BF58u;
            return;
    }

label_801DEB20:
    ctx->pc = 0x801DEB20u;
    ctx->downcount -= 2;
    // 801DEB20: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB24:
    ctx->pc = 0x801DEB24u;
    // 801DEB24: bl      0x8025CC18
    {
            ctx->lr = 0x801DEB28u;
            ctx->pc = 0x8025CC18u;
            return;
    }

label_801DEB28:
    ctx->pc = 0x801DEB28u;
    ctx->downcount -= 2;
    // 801DEB28: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB2C:
    ctx->pc = 0x801DEB2Cu;
    // 801DEB2C: bl      0x80259D00
    {
            ctx->lr = 0x801DEB30u;
            ctx->pc = 0x80259D00u;
            return;
    }

label_801DEB30:
    ctx->pc = 0x801DEB30u;
    ctx->downcount -= 2;
    // 801DEB30: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB34:
    ctx->pc = 0x801DEB34u;
    // 801DEB34: bl      0x8025955C
    {
            ctx->lr = 0x801DEB38u;
            ctx->pc = 0x8025955Cu;
            return;
    }

label_801DEB38:
    ctx->pc = 0x801DEB38u;
    ctx->downcount -= 2;
    // 801DEB38: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB3C:
    ctx->pc = 0x801DEB3Cu;
    // 801DEB3C: bl      0x801DECC0
    {
            ctx->lr = 0x801DEB40u;
            goto label_801DECC0;
    }

label_801DEB40:
    ctx->pc = 0x801DEB40u;
    ctx->downcount -= 4;
    // 801DEB40: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DEB44:
    ctx->pc = 0x801DEB44u;
    // 801DEB44: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB48:
    ctx->pc = 0x801DEB48u;
    // 801DEB48: addi    r4, r4, 5852
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5852);

label_801DEB4C:
    ctx->pc = 0x801DEB4Cu;
    // 801DEB4C: bl      0x8025EAC8
    {
            ctx->lr = 0x801DEB50u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DEB50:
    ctx->pc = 0x801DEB50u;
    ctx->downcount -= 3;
    // 801DEB50: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB54:
    ctx->pc = 0x801DEB54u;
    // 801DEB54: li      r4, -10000
    ctx->gpr[4] = (u32)(s32)(-10000);

label_801DEB58:
    ctx->pc = 0x801DEB58u;
    // 801DEB58: bl      0x8025E090
    {
            ctx->lr = 0x801DEB5Cu;
            ctx->pc = 0x8025E090u;
            return;
    }

label_801DEB5C:
    ctx->pc = 0x801DEB5Cu;
    ctx->downcount -= 3;
    // 801DEB5C: li      r4, -10001
    ctx->gpr[4] = (u32)(s32)(-10001);

label_801DEB60:
    ctx->pc = 0x801DEB60u;
    // 801DEB60: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB64:
    ctx->pc = 0x801DEB64u;
    // 801DEB64: bl      0x8025F140
    {
            ctx->lr = 0x801DEB68u;
            ctx->pc = 0x8025F140u;
            return;
    }

label_801DEB68:
    ctx->pc = 0x801DEB68u;
    ctx->downcount -= 4;
    // 801DEB68: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DEB6C:
    ctx->pc = 0x801DEB6Cu;
    // 801DEB6C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB70:
    ctx->pc = 0x801DEB70u;
    // 801DEB70: addi    r4, r4, 5864
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5864);

label_801DEB74:
    ctx->pc = 0x801DEB74u;
    // 801DEB74: bl      0x8025EAC8
    {
            ctx->lr = 0x801DEB78u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DEB78:
    ctx->pc = 0x801DEB78u;
    ctx->downcount -= 4;
    // 801DEB78: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DEB7C:
    ctx->pc = 0x801DEB7Cu;
    // 801DEB7C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB80:
    ctx->pc = 0x801DEB80u;
    // 801DEB80: addi    r4, r4, 5876
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5876);

label_801DEB84:
    ctx->pc = 0x801DEB84u;
    // 801DEB84: bl      0x8025EAC8
    {
            ctx->lr = 0x801DEB88u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DEB88:
    ctx->pc = 0x801DEB88u;
    ctx->downcount -= 3;
    // 801DEB88: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB8C:
    ctx->pc = 0x801DEB8Cu;
    // 801DEB8C: li      r4, -10001
    ctx->gpr[4] = (u32)(s32)(-10001);

label_801DEB90:
    ctx->pc = 0x801DEB90u;
    // 801DEB90: bl      0x8025F140
    {
            ctx->lr = 0x801DEB94u;
            ctx->pc = 0x8025F140u;
            return;
    }

label_801DEB94:
    ctx->pc = 0x801DEB94u;
    ctx->downcount -= 3;
    // 801DEB94: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEB98:
    ctx->pc = 0x801DEB98u;
    // 801DEB98: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DEB9C:
    ctx->pc = 0x801DEB9Cu;
    // 801DEB9C: bl      0x8025E020
    {
            ctx->lr = 0x801DEBA0u;
            ctx->pc = 0x8025E020u;
            return;
    }

label_801DEBA0:
    ctx->pc = 0x801DEBA0u;
    ctx->downcount -= 16;
    // 801DEBA0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DEBA4:
    ctx->pc = 0x801DEBA4u;
    // 801DEBA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DEBA8:
    ctx->pc = 0x801DEBA8u;
    // 801DEBA8: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DEBAC:
    ctx->pc = 0x801DEBACu;
    // 801DEBAC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DEBB0:
    ctx->pc = 0x801DEBB0u;
    // 801DEBB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DEBB4:
    ctx->pc = 0x801DEBB4u;
    ctx->downcount -= 19;
    // 801DEBB4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DEBB8:
    ctx->pc = 0x801DEBB8u;
    // 801DEBB8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DEBBC:
    ctx->pc = 0x801DEBBCu;
    // 801DEBBC: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DEBC0:
    ctx->pc = 0x801DEBC0u;
    // 801DEBC0: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DEBC4:
    ctx->pc = 0x801DEBC4u;
    // 801DEBC4: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DEBC8:
    ctx->pc = 0x801DEBC8u;
    // 801DEBC8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DEBCC:
    ctx->pc = 0x801DEBCCu;
    // 801DEBCC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEBD0:
    ctx->pc = 0x801DEBD0u;
    // 801DEBD0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DEBD4:
    ctx->pc = 0x801DEBD4u;
    // 801DEBD4: bl      0x801DEE90
    {
            ctx->lr = 0x801DEBD8u;
            goto label_801DEE90;
    }

label_801DEBD8:
    ctx->pc = 0x801DEBD8u;
    ctx->downcount -= 2;
    // 801DEBD8: or.   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DEBDC:
    ctx->pc = 0x801DEBDCu;
    // 801DEBDC: bc    4, 2, 0x801DEBE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DEBE8;
        }
    }

label_801DEBE0:
    ctx->pc = 0x801DEBE0u;
    ctx->downcount -= 2;
    // 801DEBE0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_801DEBE4:
    ctx->pc = 0x801DEBE4u;
    // 801DEBE4: b       0x801DECAC
    {
            goto label_801DECAC;
    }

label_801DEBE8:
    ctx->pc = 0x801DEBE8u;
    ctx->downcount -= 7;
    // 801DEBE8: lwz     r4, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801DEBEC:
    ctx->pc = 0x801DEBECu;
    // 801DEBEC: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEBF0:
    ctx->pc = 0x801DEBF0u;
    // 801DEBF0: lwz     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801DEBF4:
    ctx->pc = 0x801DEBF4u;
    // 801DEBF4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEBF8:
    ctx->pc = 0x801DEBF8u;
    // 801DEBF8: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_801DEBFC:
    ctx->pc = 0x801DEBFCu;
    // 801DEBFC: add   r4, r9, r4
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_801DEC00:
    ctx->pc = 0x801DEC00u;
    // 801DEC00: bl      0x80256CD0
    {
            ctx->lr = 0x801DEC04u;
            ctx->pc = 0x80256CD0u;
            return;
    }

label_801DEC04:
    ctx->pc = 0x801DEC04u;
    ctx->downcount -= 2;
    // 801DEC04: cmpwi   r3, 0
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

label_801DEC08:
    ctx->pc = 0x801DEC08u;
    // 801DEC08: bc    4, 2, 0x801DEC70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DEC70;
        }
    }

label_801DEC0C:
    ctx->pc = 0x801DEC0Cu;
    ctx->downcount -= 2;
    // 801DEC0C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEC10:
    ctx->pc = 0x801DEC10u;
    // 801DEC10: bl      0x8025E00C
    {
            ctx->lr = 0x801DEC14u;
            ctx->pc = 0x8025E00Cu;
            return;
    }

label_801DEC14:
    ctx->pc = 0x801DEC14u;
    ctx->downcount -= 6;
    // 801DEC14: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DEC18:
    ctx->pc = 0x801DEC18u;
    // 801DEC18: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DEC1C:
    ctx->pc = 0x801DEC1Cu;
    // 801DEC1C: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_801DEC20:
    ctx->pc = 0x801DEC20u;
    // 801DEC20: addi    r4, r4, 5888
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5888);

label_801DEC24:
    ctx->pc = 0x801DEC24u;
    // 801DEC24: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEC28:
    ctx->pc = 0x801DEC28u;
    // 801DEC28: bl      0x8025EA54
    {
            ctx->lr = 0x801DEC2Cu;
            ctx->pc = 0x8025EA54u;
            return;
    }

label_801DEC2C:
    ctx->pc = 0x801DEC2Cu;
    ctx->downcount -= 3;
    // 801DEC2C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEC30:
    ctx->pc = 0x801DEC30u;
    // 801DEC30: li      r4, -10001
    ctx->gpr[4] = (u32)(s32)(-10001);

label_801DEC34:
    ctx->pc = 0x801DEC34u;
    // 801DEC34: bl      0x8025EDB4
    {
            ctx->lr = 0x801DEC38u;
            ctx->pc = 0x8025EDB4u;
            return;
    }

label_801DEC38:
    ctx->pc = 0x801DEC38u;
    ctx->downcount -= 3;
    // 801DEC38: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEC3C:
    ctx->pc = 0x801DEC3Cu;
    // 801DEC3C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEC40:
    ctx->pc = 0x801DEC40u;
    // 801DEC40: bl      0x8025E21C
    {
            ctx->lr = 0x801DEC44u;
            ctx->pc = 0x8025E21Cu;
            return;
    }

label_801DEC44:
    ctx->pc = 0x801DEC44u;
    ctx->downcount -= 5;
    // 801DEC44: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DEC48:
    ctx->pc = 0x801DEC48u;
    // 801DEC48: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_801DEC4C:
    ctx->pc = 0x801DEC4Cu;
    // 801DEC4C: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEC50:
    ctx->pc = 0x801DEC50u;
    // 801DEC50: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEC54:
    ctx->pc = 0x801DEC54u;
    // 801DEC54: bl      0x8025F508
    {
            ctx->lr = 0x801DEC58u;
            ctx->pc = 0x8025F508u;
            return;
    }

label_801DEC58:
    ctx->pc = 0x801DEC58u;
    ctx->downcount -= 4;
    // 801DEC58: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DEC5C:
    ctx->pc = 0x801DEC5Cu;
    // 801DEC5C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEC60:
    ctx->pc = 0x801DEC60u;
    // 801DEC60: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEC64:
    ctx->pc = 0x801DEC64u;
    // 801DEC64: bl      0x8025E148
    {
            ctx->lr = 0x801DEC68u;
            ctx->pc = 0x8025E148u;
            return;
    }

label_801DEC68:
    ctx->pc = 0x801DEC68u;
    ctx->downcount -= 2;
    // 801DEC68: cmpwi   r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DEC6C:
    ctx->pc = 0x801DEC6Cu;
    // 801DEC6C: bc    12, 2, 0x801DEC90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DEC90;
        }
    }

label_801DEC70:
    ctx->pc = 0x801DEC70u;
    ctx->downcount -= 3;
    // 801DEC70: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_801DEC74:
    ctx->pc = 0x801DEC74u;
    // 801DEC74: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEC78:
    ctx->pc = 0x801DEC78u;
    // 801DEC78: bl      0x8025D7A8
    {
            ctx->lr = 0x801DEC7Cu;
            ctx->pc = 0x8025D7A8u;
            return;
    }

label_801DEC7C:
    ctx->pc = 0x801DEC7Cu;
    ctx->downcount -= 5;
    // 801DEC7C: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DEC80:
    ctx->pc = 0x801DEC80u;
    // 801DEC80: lis     r3, -32720
    ctx->gpr[3] = ((u32)(s32)(-32720) << 16);

label_801DEC84:
    ctx->pc = 0x801DEC84u;
    // 801DEC84: addi    r3, r3, 5900
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5900);

label_801DEC88:
    ctx->pc = 0x801DEC88u;
    // 801DEC88: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801DEC8C:
    ctx->pc = 0x801DEC8Cu;
    // 801DEC8C: bl      0x8028CD1C
    {
            ctx->lr = 0x801DEC90u;
            ctx->pc = 0x8028CD1Cu;
            return;
    }

label_801DEC90:
    ctx->pc = 0x801DEC90u;
    ctx->downcount -= 3;
    // 801DEC90: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEC94:
    ctx->pc = 0x801DEC94u;
    // 801DEC94: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DEC98:
    ctx->pc = 0x801DEC98u;
    // 801DEC98: bl      0x8025F72C
    {
            ctx->lr = 0x801DEC9Cu;
            ctx->pc = 0x8025F72Cu;
            return;
    }

label_801DEC9C:
    ctx->pc = 0x801DEC9Cu;
    ctx->downcount -= 3;
    // 801DEC9C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DECA0:
    ctx->pc = 0x801DECA0u;
    // 801DECA0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DECA4:
    ctx->pc = 0x801DECA4u;
    // 801DECA4: bl      0x8025E020
    {
            ctx->lr = 0x801DECA8u;
            ctx->pc = 0x8025E020u;
            return;
    }

label_801DECA8:
    ctx->pc = 0x801DECA8u;
    ctx->downcount -= 1;
    // 801DECA8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DECAC:
    ctx->pc = 0x801DECACu;
    ctx->downcount -= 16;
    // 801DECAC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DECB0:
    ctx->pc = 0x801DECB0u;
    // 801DECB0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DECB4:
    ctx->pc = 0x801DECB4u;
    // 801DECB4: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DECB8:
    ctx->pc = 0x801DECB8u;
    // 801DECB8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DECBC:
    ctx->pc = 0x801DECBCu;
    // 801DECBC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DECC0:
    ctx->pc = 0x801DECC0u;
    ctx->downcount -= 18;
    // 801DECC0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DECC4:
    ctx->pc = 0x801DECC4u;
    // 801DECC4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DECC8:
    ctx->pc = 0x801DECC8u;
    // 801DECC8: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DECCC:
    ctx->pc = 0x801DECCCu;
    // 801DECCC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DECD0:
    ctx->pc = 0x801DECD0u;
    // 801DECD0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DECD4:
    ctx->pc = 0x801DECD4u;
    // 801DECD4: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DECD8:
    ctx->pc = 0x801DECD8u;
    // 801DECD8: addi    r4, r4, 5992
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5992);

label_801DECDC:
    ctx->pc = 0x801DECDCu;
    // 801DECDC: bl      0x8025EAC8
    {
            ctx->lr = 0x801DECE0u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DECE0:
    ctx->pc = 0x801DECE0u;
    ctx->downcount -= 5;
    // 801DECE0: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DECE4:
    ctx->pc = 0x801DECE4u;
    // 801DECE4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801DECE8:
    ctx->pc = 0x801DECE8u;
    // 801DECE8: addi    r4, r4, -4760
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-4760);

label_801DECEC:
    ctx->pc = 0x801DECECu;
    // 801DECEC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DECF0:
    ctx->pc = 0x801DECF0u;
    // 801DECF0: bl      0x8025EBB0
    {
            ctx->lr = 0x801DECF4u;
            ctx->pc = 0x8025EBB0u;
            return;
    }

label_801DECF4:
    ctx->pc = 0x801DECF4u;
    ctx->downcount -= 3;
    // 801DECF4: li      r4, -10001
    ctx->gpr[4] = (u32)(s32)(-10001);

label_801DECF8:
    ctx->pc = 0x801DECF8u;
    // 801DECF8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DECFC:
    ctx->pc = 0x801DECFCu;
    // 801DECFC: bl      0x8025F140
    {
            ctx->lr = 0x801DED00u;
            ctx->pc = 0x8025F140u;
            return;
    }

label_801DED00:
    ctx->pc = 0x801DED00u;
    ctx->downcount -= 4;
    // 801DED00: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DED04:
    ctx->pc = 0x801DED04u;
    // 801DED04: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DED08:
    ctx->pc = 0x801DED08u;
    // 801DED08: addi    r4, r4, 6004
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6004);

label_801DED0C:
    ctx->pc = 0x801DED0Cu;
    // 801DED0C: bl      0x8025EAC8
    {
            ctx->lr = 0x801DED10u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DED10:
    ctx->pc = 0x801DED10u;
    ctx->downcount -= 5;
    // 801DED10: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DED14:
    ctx->pc = 0x801DED14u;
    // 801DED14: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801DED18:
    ctx->pc = 0x801DED18u;
    // 801DED18: addi    r4, r4, -4552
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-4552);

label_801DED1C:
    ctx->pc = 0x801DED1Cu;
    // 801DED1C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DED20:
    ctx->pc = 0x801DED20u;
    // 801DED20: bl      0x8025EBB0
    {
            ctx->lr = 0x801DED24u;
            ctx->pc = 0x8025EBB0u;
            return;
    }

label_801DED24:
    ctx->pc = 0x801DED24u;
    ctx->downcount -= 3;
    // 801DED24: li      r4, -10001
    ctx->gpr[4] = (u32)(s32)(-10001);

label_801DED28:
    ctx->pc = 0x801DED28u;
    // 801DED28: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DED2C:
    ctx->pc = 0x801DED2Cu;
    // 801DED2C: bl      0x8025F140
    {
            ctx->lr = 0x801DED30u;
            ctx->pc = 0x8025F140u;
            return;
    }

label_801DED30:
    ctx->pc = 0x801DED30u;
    ctx->downcount -= 2;
    // 801DED30: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DED34:
    ctx->pc = 0x801DED34u;
    // 801DED34: bl      0x80232964
    {
            ctx->lr = 0x801DED38u;
            ctx->pc = 0x80232964u;
            return;
    }

label_801DED38:
    ctx->pc = 0x801DED38u;
    ctx->downcount -= 2;
    // 801DED38: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DED3C:
    ctx->pc = 0x801DED3Cu;
    // 801DED3C: bl      0x80232CBC
    {
            ctx->lr = 0x801DED40u;
            ctx->pc = 0x80232CBCu;
            return;
    }

label_801DED40:
    ctx->pc = 0x801DED40u;
    ctx->downcount -= 2;
    // 801DED40: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DED44:
    ctx->pc = 0x801DED44u;
    // 801DED44: bl      0x801DF724
    {
            ctx->lr = 0x801DED48u;
            ctx->pc = 0x801DF724u;
            return;
    }

label_801DED48:
    ctx->pc = 0x801DED48u;
    ctx->downcount -= 2;
    // 801DED48: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DED4C:
    ctx->pc = 0x801DED4Cu;
    // 801DED4C: bl      0x80232ACC
    {
            ctx->lr = 0x801DED50u;
            ctx->pc = 0x80232ACCu;
            return;
    }

label_801DED50:
    ctx->pc = 0x801DED50u;
    ctx->downcount -= 17;
    // 801DED50: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DED54:
    ctx->pc = 0x801DED54u;
    // 801DED54: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DED58:
    ctx->pc = 0x801DED58u;
    // 801DED58: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DED5C:
    ctx->pc = 0x801DED5Cu;
    // 801DED5C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DED60:
    ctx->pc = 0x801DED60u;
    // 801DED60: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DED64:
    ctx->pc = 0x801DED64u;
    // 801DED64: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DED68:
    ctx->pc = 0x801DED68u;
    ctx->downcount -= 19;
    // 801DED68: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DED6C:
    ctx->pc = 0x801DED6Cu;
    // 801DED6C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DED70:
    ctx->pc = 0x801DED70u;
    // 801DED70: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DED74:
    ctx->pc = 0x801DED74u;
    // 801DED74: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DED78:
    ctx->pc = 0x801DED78u;
    // 801DED78: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DED7C:
    ctx->pc = 0x801DED7Cu;
    // 801DED7C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801DED80:
    ctx->pc = 0x801DED80u;
    // 801DED80: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801DED84:
    ctx->pc = 0x801DED84u;
    // 801DED84: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801DED88:
    ctx->pc = 0x801DED88u;
    // 801DED88: bl      0x802554F0
    {
            ctx->lr = 0x801DED8Cu;
            ctx->pc = 0x802554F0u;
            return;
    }

label_801DED8C:
    ctx->pc = 0x801DED8Cu;
    ctx->downcount -= 2;
    // 801DED8C: or.   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DED90:
    ctx->pc = 0x801DED90u;
    // 801DED90: bc    4, 2, 0x801DEDAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DEDAC;
        }
    }

label_801DED94:
    ctx->pc = 0x801DED94u;
    ctx->downcount -= 5;
    // 801DED94: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DED98:
    ctx->pc = 0x801DED98u;
    // 801DED98: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DED9C:
    ctx->pc = 0x801DED9Cu;
    // 801DED9C: addi    r4, r4, 5920
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5920);

label_801DEDA0:
    ctx->pc = 0x801DEDA0u;
    // 801DEDA0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801DEDA4:
    ctx->pc = 0x801DEDA4u;
    // 801DEDA4: bl      0x802553C8
    {
            ctx->lr = 0x801DEDA8u;
            ctx->pc = 0x802553C8u;
            return;
    }

label_801DEDA8:
    ctx->pc = 0x801DEDA8u;
    ctx->downcount -= 1;
    // 801DEDA8: b       0x801DEE24
    {
            goto label_801DEE24;
    }

label_801DEDAC:
    ctx->pc = 0x801DEDACu;
    ctx->downcount -= 3;
    // 801DEDAC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEDB0:
    ctx->pc = 0x801DEDB0u;
    // 801DEDB0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DEDB4:
    ctx->pc = 0x801DEDB4u;
    // 801DEDB4: bl      0x801DEE90
    {
            ctx->lr = 0x801DEDB8u;
            goto label_801DEE90;
    }

label_801DEDB8:
    ctx->pc = 0x801DEDB8u;
    ctx->downcount -= 2;
    // 801DEDB8: or.   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DEDBC:
    ctx->pc = 0x801DEDBCu;
    // 801DEDBC: bc    4, 2, 0x801DEDDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DEDDC;
        }
    }

label_801DEDC0:
    ctx->pc = 0x801DEDC0u;
    ctx->downcount -= 6;
    // 801DEDC0: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DEDC4:
    ctx->pc = 0x801DEDC4u;
    // 801DEDC4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEDC8:
    ctx->pc = 0x801DEDC8u;
    // 801DEDC8: addi    r4, r4, 5960
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5960);

label_801DEDCC:
    ctx->pc = 0x801DEDCCu;
    // 801DEDCC: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEDD0:
    ctx->pc = 0x801DEDD0u;
    // 801DEDD0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801DEDD4:
    ctx->pc = 0x801DEDD4u;
    // 801DEDD4: bl      0x802553C8
    {
            ctx->lr = 0x801DEDD8u;
            ctx->pc = 0x802553C8u;
            return;
    }

label_801DEDD8:
    ctx->pc = 0x801DEDD8u;
    ctx->downcount -= 1;
    // 801DEDD8: b       0x801DEE24
    {
            goto label_801DEE24;
    }

label_801DEDDC:
    ctx->pc = 0x801DEDDCu;
    ctx->downcount -= 7;
    // 801DEDDC: lwz     r4, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801DEDE0:
    ctx->pc = 0x801DEDE0u;
    // 801DEDE0: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DEDE4:
    ctx->pc = 0x801DEDE4u;
    // 801DEDE4: lwz     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801DEDE8:
    ctx->pc = 0x801DEDE8u;
    // 801DEDE8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEDEC:
    ctx->pc = 0x801DEDECu;
    // 801DEDEC: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_801DEDF0:
    ctx->pc = 0x801DEDF0u;
    // 801DEDF0: add   r4, r9, r4
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_801DEDF4:
    ctx->pc = 0x801DEDF4u;
    // 801DEDF4: bl      0x80256CD0
    {
            ctx->lr = 0x801DEDF8u;
            ctx->pc = 0x80256CD0u;
            return;
    }

label_801DEDF8:
    ctx->pc = 0x801DEDF8u;
    ctx->downcount -= 2;
    // 801DEDF8: cmpwi   r3, 0
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

label_801DEDFC:
    ctx->pc = 0x801DEDFCu;
    // 801DEDFC: bc    12, 2, 0x801DEE08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DEE08;
        }
    }

label_801DEE00:
    ctx->pc = 0x801DEE00u;
    ctx->downcount -= 2;
    // 801DEE00: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEE04:
    ctx->pc = 0x801DEE04u;
    // 801DEE04: bl      0x8025F794
    {
            ctx->lr = 0x801DEE08u;
            ctx->pc = 0x8025F794u;
            return;
    }

label_801DEE08:
    ctx->pc = 0x801DEE08u;
    ctx->downcount -= 4;
    // 801DEE08: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEE0C:
    ctx->pc = 0x801DEE0Cu;
    // 801DEE0C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DEE10:
    ctx->pc = 0x801DEE10u;
    // 801DEE10: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_801DEE14:
    ctx->pc = 0x801DEE14u;
    // 801DEE14: bl      0x8025F4D8
    {
            ctx->lr = 0x801DEE18u;
            ctx->pc = 0x8025F4D8u;
            return;
    }

label_801DEE18:
    ctx->pc = 0x801DEE18u;
    ctx->downcount -= 2;
    // 801DEE18: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEE1C:
    ctx->pc = 0x801DEE1Cu;
    // 801DEE1C: bl      0x8025E00C
    {
            ctx->lr = 0x801DEE20u;
            ctx->pc = 0x8025E00Cu;
            return;
    }

label_801DEE20:
    ctx->pc = 0x801DEE20u;
    ctx->downcount -= 1;
    // 801DEE20: addi    r3, r3, -1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-1);

label_801DEE24:
    ctx->pc = 0x801DEE24u;
    ctx->downcount -= 16;
    // 801DEE24: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DEE28:
    ctx->pc = 0x801DEE28u;
    // 801DEE28: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DEE2C:
    ctx->pc = 0x801DEE2Cu;
    // 801DEE2C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DEE30:
    ctx->pc = 0x801DEE30u;
    // 801DEE30: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DEE34:
    ctx->pc = 0x801DEE34u;
    // 801DEE34: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DEE38:
    ctx->pc = 0x801DEE38u;
    ctx->downcount -= 17;
    // 801DEE38: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DEE3C:
    ctx->pc = 0x801DEE3Cu;
    // 801DEE3C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DEE40:
    ctx->pc = 0x801DEE40u;
    // 801DEE40: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DEE44:
    ctx->pc = 0x801DEE44u;
    // 801DEE44: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DEE48:
    ctx->pc = 0x801DEE48u;
    // 801DEE48: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DEE4C:
    ctx->pc = 0x801DEE4Cu;
    // 801DEE4C: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_801DEE50:
    ctx->pc = 0x801DEE50u;
    // 801DEE50: bl      0x8025E00C
    {
            ctx->lr = 0x801DEE54u;
            ctx->pc = 0x8025E00Cu;
            return;
    }

label_801DEE54:
    ctx->pc = 0x801DEE54u;
    ctx->downcount -= 3;
    // 801DEE54: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DEE58:
    ctx->pc = 0x801DEE58u;
    // 801DEE58: cmpw    r31, r30
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

label_801DEE5C:
    ctx->pc = 0x801DEE5Cu;
    // 801DEE5C: bc    12, 1, 0x801DEE78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DEE78;
        }
    }

label_801DEE60:
    ctx->downcount -= 3;
    // 801DEE60: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEE64:
    // 801DEE64: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DEE68:
    // 801DEE68: bl      0x8025D7A8
    {
            ctx->lr = 0x801DEE6Cu;
            ctx->pc = 0x8025D7A8u;
            return;
    }

label_801DEE6C:
    ctx->downcount -= 3;
    // 801DEE6C: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_801DEE70:
    // 801DEE70: cmpw    r31, r30
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

label_801DEE74:
    // 801DEE74: bc    4, 1, 0x801DEE60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DEE60u;
                return;
            }
            goto label_801DEE60;
        }
    }

label_801DEE78:
    ctx->pc = 0x801DEE78u;
    ctx->downcount -= 17;
    // 801DEE78: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DEE7C:
    ctx->pc = 0x801DEE7Cu;
    // 801DEE7C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DEE80:
    ctx->pc = 0x801DEE80u;
    // 801DEE80: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DEE84:
    ctx->pc = 0x801DEE84u;
    // 801DEE84: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DEE88:
    ctx->pc = 0x801DEE88u;
    // 801DEE88: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DEE8C:
    ctx->pc = 0x801DEE8Cu;
    // 801DEE8C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DEE90:
    ctx->pc = 0x801DEE90u;
    ctx->downcount -= 7;
    // 801DEE90: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DEE94:
    ctx->pc = 0x801DEE94u;
    // 801DEE94: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DEE98:
    ctx->pc = 0x801DEE98u;
    // 801DEE98: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DEE9C:
    ctx->pc = 0x801DEE9Cu;
    // 801DEE9C: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DEEA0:
    ctx->pc = 0x801DEEA0u;
    // 801DEEA0: lis     r4, 27765
    ctx->gpr[4] = ((u32)(s32)(27765) << 16);

label_801DEEA4:
    ctx->pc = 0x801DEEA4u;
    // 801DEEA4: ori     r4, r4, 0x6121
    ctx->gpr[4] = ctx->gpr[4] | 0x6121u;

label_801DEEA8:
    ctx->pc = 0x801DEEA8u;
    // 801DEEA8: bl      0x80213200
    {
            ctx->lr = 0x801DEEACu;
            ctx->pc = 0x80213200u;
            return;
    }

label_801DEEAC:
    ctx->pc = 0x801DEEACu;
    ctx->downcount -= 5;
    // 801DEEAC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DEEB0:
    ctx->pc = 0x801DEEB0u;
    // 801DEEB0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DEEB4:
    ctx->pc = 0x801DEEB4u;
    // 801DEEB4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DEEB8:
    ctx->pc = 0x801DEEB8u;
    // 801DEEB8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DEEBC:
    ctx->pc = 0x801DEEBCu;
    ctx->downcount -= 7;
    // 801DEEBC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DEEC0:
    ctx->pc = 0x801DEEC0u;
    // 801DEEC0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DEEC4:
    ctx->pc = 0x801DEEC4u;
    // 801DEEC4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DEEC8:
    ctx->pc = 0x801DEEC8u;
    // 801DEEC8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DEECC:
    ctx->pc = 0x801DEECCu;
    // 801DEECC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801DEED0:
    ctx->pc = 0x801DEED0u;
    // 801DEED0: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_801DEED4:
    ctx->pc = 0x801DEED4u;
    // 801DEED4: bl      0x801DEAB0
    {
            ctx->lr = 0x801DEED8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DEAB0u;
                return;
            }
            goto label_801DEAB0;
    }

label_801DEED8:
    ctx->pc = 0x801DEED8u;
    ctx->downcount -= 5;
    // 801DEED8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DEEDC:
    ctx->pc = 0x801DEEDCu;
    // 801DEEDC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DEEE0:
    ctx->pc = 0x801DEEE0u;
    // 801DEEE0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DEEE4:
    ctx->pc = 0x801DEEE4u;
    // 801DEEE4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DEEE8:
    ctx->pc = 0x801DEEE8u;
    ctx->downcount -= 19;
    // 801DEEE8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DEEEC:
    ctx->pc = 0x801DEEECu;
    // 801DEEEC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DEEF0:
    ctx->pc = 0x801DEEF0u;
    // 801DEEF0: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DEEF4:
    ctx->pc = 0x801DEEF4u;
    // 801DEEF4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DEEF8:
    ctx->pc = 0x801DEEF8u;
    // 801DEEF8: lwz     r0, -30504(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30504);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DEEFC:
    ctx->pc = 0x801DEEFCu;
    // 801DEEFC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DEF00:
    ctx->pc = 0x801DEF00u;
    // 801DEF00: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801DEF04:
    ctx->pc = 0x801DEF04u;
    // 801DEF04: cmpwi   r0, -2
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DEF08:
    ctx->pc = 0x801DEF08u;
    // 801DEF08: bc    4, 2, 0x801DEFE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DEFE0;
        }
    }

label_801DEF0C:
    ctx->pc = 0x801DEF0Cu;
    ctx->downcount -= 1;
    // 801DEF0C: bl      0x8025EF70
    {
            ctx->lr = 0x801DEF10u;
            ctx->pc = 0x8025EF70u;
            return;
    }

label_801DEF10:
    ctx->pc = 0x801DEF10u;
    ctx->downcount -= 4;
    // 801DEF10: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DEF14:
    ctx->pc = 0x801DEF14u;
    // 801DEF14: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEF18:
    ctx->pc = 0x801DEF18u;
    // 801DEF18: addi    r4, r4, 6036
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6036);

label_801DEF1C:
    ctx->pc = 0x801DEF1Cu;
    // 801DEF1C: bl      0x8025EAC8
    {
            ctx->lr = 0x801DEF20u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DEF20:
    ctx->pc = 0x801DEF20u;
    ctx->downcount -= 5;
    // 801DEF20: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DEF24:
    ctx->pc = 0x801DEF24u;
    // 801DEF24: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801DEF28:
    ctx->pc = 0x801DEF28u;
    // 801DEF28: addi    r4, r4, -2756
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-2756);

label_801DEF2C:
    ctx->pc = 0x801DEF2Cu;
    // 801DEF2C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEF30:
    ctx->pc = 0x801DEF30u;
    // 801DEF30: bl      0x8025EBB0
    {
            ctx->lr = 0x801DEF34u;
            ctx->pc = 0x8025EBB0u;
            return;
    }

label_801DEF34:
    ctx->pc = 0x801DEF34u;
    ctx->downcount -= 3;
    // 801DEF34: li      r4, -3
    ctx->gpr[4] = (u32)(s32)(-3);

label_801DEF38:
    ctx->pc = 0x801DEF38u;
    // 801DEF38: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEF3C:
    ctx->pc = 0x801DEF3Cu;
    // 801DEF3C: bl      0x8025F140
    {
            ctx->lr = 0x801DEF40u;
            ctx->pc = 0x8025F140u;
            return;
    }

label_801DEF40:
    ctx->pc = 0x801DEF40u;
    ctx->downcount -= 4;
    // 801DEF40: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DEF44:
    ctx->pc = 0x801DEF44u;
    // 801DEF44: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEF48:
    ctx->pc = 0x801DEF48u;
    // 801DEF48: addi    r4, r4, 6048
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6048);

label_801DEF4C:
    ctx->pc = 0x801DEF4Cu;
    // 801DEF4C: bl      0x8025EAC8
    {
            ctx->lr = 0x801DEF50u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DEF50:
    ctx->pc = 0x801DEF50u;
    ctx->downcount -= 5;
    // 801DEF50: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DEF54:
    ctx->pc = 0x801DEF54u;
    // 801DEF54: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801DEF58:
    ctx->pc = 0x801DEF58u;
    // 801DEF58: addi    r4, r4, -3932
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-3932);

label_801DEF5C:
    ctx->pc = 0x801DEF5Cu;
    // 801DEF5C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEF60:
    ctx->pc = 0x801DEF60u;
    // 801DEF60: bl      0x8025EBB0
    {
            ctx->lr = 0x801DEF64u;
            ctx->pc = 0x8025EBB0u;
            return;
    }

label_801DEF64:
    ctx->pc = 0x801DEF64u;
    ctx->downcount -= 3;
    // 801DEF64: li      r4, -3
    ctx->gpr[4] = (u32)(s32)(-3);

label_801DEF68:
    ctx->pc = 0x801DEF68u;
    // 801DEF68: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEF6C:
    ctx->pc = 0x801DEF6Cu;
    // 801DEF6C: bl      0x8025F140
    {
            ctx->lr = 0x801DEF70u;
            ctx->pc = 0x8025F140u;
            return;
    }

label_801DEF70:
    ctx->pc = 0x801DEF70u;
    ctx->downcount -= 4;
    // 801DEF70: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DEF74:
    ctx->pc = 0x801DEF74u;
    // 801DEF74: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEF78:
    ctx->pc = 0x801DEF78u;
    // 801DEF78: addi    r4, r4, 6056
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6056);

label_801DEF7C:
    ctx->pc = 0x801DEF7Cu;
    // 801DEF7C: bl      0x8025EAC8
    {
            ctx->lr = 0x801DEF80u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DEF80:
    ctx->pc = 0x801DEF80u;
    ctx->downcount -= 5;
    // 801DEF80: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DEF84:
    ctx->pc = 0x801DEF84u;
    // 801DEF84: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801DEF88:
    ctx->pc = 0x801DEF88u;
    // 801DEF88: addi    r4, r4, -3680
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-3680);

label_801DEF8C:
    ctx->pc = 0x801DEF8Cu;
    // 801DEF8C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEF90:
    ctx->pc = 0x801DEF90u;
    // 801DEF90: bl      0x8025EBB0
    {
            ctx->lr = 0x801DEF94u;
            ctx->pc = 0x8025EBB0u;
            return;
    }

label_801DEF94:
    ctx->pc = 0x801DEF94u;
    ctx->downcount -= 3;
    // 801DEF94: li      r4, -3
    ctx->gpr[4] = (u32)(s32)(-3);

label_801DEF98:
    ctx->pc = 0x801DEF98u;
    // 801DEF98: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEF9C:
    ctx->pc = 0x801DEF9Cu;
    // 801DEF9C: bl      0x8025F140
    {
            ctx->lr = 0x801DEFA0u;
            ctx->pc = 0x8025F140u;
            return;
    }

label_801DEFA0:
    ctx->pc = 0x801DEFA0u;
    ctx->downcount -= 4;
    // 801DEFA0: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DEFA4:
    ctx->pc = 0x801DEFA4u;
    // 801DEFA4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEFA8:
    ctx->pc = 0x801DEFA8u;
    // 801DEFA8: addi    r4, r4, 6068
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6068);

label_801DEFAC:
    ctx->pc = 0x801DEFACu;
    // 801DEFAC: bl      0x8025EAC8
    {
            ctx->lr = 0x801DEFB0u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DEFB0:
    ctx->pc = 0x801DEFB0u;
    ctx->downcount -= 5;
    // 801DEFB0: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_801DEFB4:
    ctx->pc = 0x801DEFB4u;
    // 801DEFB4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801DEFB8:
    ctx->pc = 0x801DEFB8u;
    // 801DEFB8: addi    r4, r4, -2856
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-2856);

label_801DEFBC:
    ctx->pc = 0x801DEFBCu;
    // 801DEFBC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEFC0:
    ctx->pc = 0x801DEFC0u;
    // 801DEFC0: bl      0x8025EBB0
    {
            ctx->lr = 0x801DEFC4u;
            ctx->pc = 0x8025EBB0u;
            return;
    }

label_801DEFC4:
    ctx->pc = 0x801DEFC4u;
    ctx->downcount -= 3;
    // 801DEFC4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEFC8:
    ctx->pc = 0x801DEFC8u;
    // 801DEFC8: li      r4, -3
    ctx->gpr[4] = (u32)(s32)(-3);

label_801DEFCC:
    ctx->pc = 0x801DEFCCu;
    // 801DEFCC: bl      0x8025F140
    {
            ctx->lr = 0x801DEFD0u;
            ctx->pc = 0x8025F140u;
            return;
    }

label_801DEFD0:
    ctx->pc = 0x801DEFD0u;
    ctx->downcount -= 3;
    // 801DEFD0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEFD4:
    ctx->pc = 0x801DEFD4u;
    // 801DEFD4: li      r4, -10000
    ctx->gpr[4] = (u32)(s32)(-10000);

label_801DEFD8:
    ctx->pc = 0x801DEFD8u;
    // 801DEFD8: bl      0x80256B08
    {
            ctx->lr = 0x801DEFDCu;
            ctx->pc = 0x80256B08u;
            return;
    }

label_801DEFDC:
    ctx->pc = 0x801DEFDCu;
    ctx->downcount -= 1;
    // 801DEFDC: stw     r3, -30504(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30504);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DEFE0:
    ctx->pc = 0x801DEFE0u;
    ctx->downcount -= 3;
    // 801DEFE0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DEFE4:
    ctx->pc = 0x801DEFE4u;
    // 801DEFE4: li      r4, 12
    ctx->gpr[4] = (u32)(s32)(12);

label_801DEFE8:
    ctx->pc = 0x801DEFE8u;
    // 801DEFE8: bl      0x8025EFDC
    {
            ctx->lr = 0x801DEFECu;
            ctx->pc = 0x8025EFDCu;
            return;
    }

label_801DEFEC:
    ctx->pc = 0x801DEFECu;
    ctx->downcount -= 2;
    // 801DEFEC: or.   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DEFF0:
    ctx->pc = 0x801DEFF0u;
    // 801DEFF0: bc    12, 2, 0x801DF000
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF000;
        }
    }

label_801DEFF4:
    ctx->pc = 0x801DEFF4u;
    ctx->downcount -= 3;
    // 801DEFF4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DEFF8:
    ctx->pc = 0x801DEFF8u;
    // 801DEFF8: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DEFFC:
    ctx->pc = 0x801DEFFCu;
    // 801DEFFC: stw     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DF000:
    ctx->pc = 0x801DF000u;
    ctx->downcount -= 4;
    // 801DF000: lwz     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DF004:
    ctx->pc = 0x801DF004u;
    // 801DF004: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801DF008:
    ctx->pc = 0x801DF008u;
    // 801DF008: cmpwi   r9, 0
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

label_801DF00C:
    ctx->pc = 0x801DF00Cu;
    // 801DF00C: bc    12, 2, 0x801DF014
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF014;
        }
    }

label_801DF010:
    ctx->pc = 0x801DF010u;
    ctx->downcount -= 1;
    // 801DF010: addi    r10, r9, 24
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(24);

label_801DF014:
    ctx->pc = 0x801DF014u;
    ctx->downcount -= 4;
    // 801DF014: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DF018:
    ctx->pc = 0x801DF018u;
    // 801DF018: cmpwi   cr7, r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 0)) | (cr_bits << 0);
    }

label_801DF01C:
    ctx->pc = 0x801DF01Cu;
    // 801DF01C: cmpwi   r0, 0
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

label_801DF020:
    ctx->pc = 0x801DF020u;
    // 801DF020: bc    12, 2, 0x801DF04C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF04C;
        }
    }

label_801DF024:
    ctx->pc = 0x801DF024u;
    ctx->downcount -= 5;
    // 801DF024: or   r9, r0, r0
    {
        ctx->gpr[9] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801DF028:
    ctx->pc = 0x801DF028u;
    // 801DF028: lwz     r8, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801DF02C:
    ctx->pc = 0x801DF02Cu;
    // 801DF02C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DF030:
    ctx->pc = 0x801DF030u;
    // 801DF030: cmpw    r0, r11
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DF034:
    ctx->pc = 0x801DF034u;
    // 801DF034: bc    12, 2, 0x801DF048
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF048;
        }
    }

label_801DF038:
    loop_801DF038(ctx);
    if (ctx->pc == 0x801DF048u) goto label_801DF048;
    return;
label_801DF03C:
    ctx->pc = 0x801DF03Cu;
    // 801DF03C: lwzu     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_801DF040:
    // 801DF040: cmpw    r0, r11
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DF044:
    // 801DF044: bc    4, 2, 0x801DF038
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801DF038u;
                return;
            }
            goto label_801DF038;
        }
    }

label_801DF048:
    ctx->pc = 0x801DF048u;
    ctx->downcount -= 1;
    // 801DF048: stw     r8, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_801DF04C:
    ctx->pc = 0x801DF04Cu;
    ctx->downcount -= 1;
    // 801DF04C: bc    12, 30, 0x801DF064
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF064;
        }
    }

label_801DF050:
    ctx->pc = 0x801DF050u;
    ctx->downcount -= 5;
    // 801DF050: stw     r10, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801DF054:
    ctx->pc = 0x801DF054u;
    // 801DF054: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DF058:
    ctx->pc = 0x801DF058u;
    // 801DF058: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DF05C:
    ctx->pc = 0x801DF05Cu;
    // 801DF05C: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801DF060:
    ctx->pc = 0x801DF060u;
    // 801DF060: b       0x801DF06C
    {
            goto label_801DF06C;
    }

label_801DF064:
    ctx->pc = 0x801DF064u;
    ctx->downcount -= 2;
    // 801DF064: stw     r10, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801DF068:
    ctx->pc = 0x801DF068u;
    // 801DF068: stw     r10, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801DF06C:
    ctx->pc = 0x801DF06Cu;
    ctx->downcount -= 6;
    // 801DF06C: lhz     r0, 6(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(6);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801DF070:
    ctx->pc = 0x801DF070u;
    // 801DF070: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF074:
    ctx->pc = 0x801DF074u;
    // 801DF074: lwz     r5, -30504(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30504);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801DF078:
    ctx->pc = 0x801DF078u;
    // 801DF078: li      r4, -10000
    ctx->gpr[4] = (u32)(s32)(-10000);

label_801DF07C:
    ctx->pc = 0x801DF07Cu;
    // 801DF07C: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DF080:
    ctx->pc = 0x801DF080u;
    // 801DF080: bl      0x8025EE94
    {
            ctx->lr = 0x801DF084u;
            ctx->pc = 0x8025EE94u;
            return;
    }

label_801DF084:
    ctx->pc = 0x801DF084u;
    ctx->downcount -= 3;
    // 801DF084: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF088:
    ctx->pc = 0x801DF088u;
    // 801DF088: li      r4, -2
    ctx->gpr[4] = (u32)(s32)(-2);

label_801DF08C:
    ctx->pc = 0x801DF08Cu;
    // 801DF08C: bl      0x8025DD90
    {
            ctx->lr = 0x801DF090u;
            ctx->pc = 0x8025DD90u;
            return;
    }

label_801DF090:
    ctx->pc = 0x801DF090u;
    ctx->downcount -= 16;
    // 801DF090: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DF094:
    ctx->pc = 0x801DF094u;
    // 801DF094: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DF098:
    ctx->pc = 0x801DF098u;
    // 801DF098: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DF09C:
    ctx->pc = 0x801DF09Cu;
    // 801DF09C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801DF0A0:
    ctx->pc = 0x801DF0A0u;
    // 801DF0A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DF0A4:
    ctx->pc = 0x801DF0A4u;
    ctx->downcount -= 17;
    // 801DF0A4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DF0A8:
    ctx->pc = 0x801DF0A8u;
    // 801DF0A8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DF0AC:
    ctx->pc = 0x801DF0ACu;
    // 801DF0AC: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DF0B0:
    ctx->pc = 0x801DF0B0u;
    // 801DF0B0: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DF0B4:
    ctx->pc = 0x801DF0B4u;
    // 801DF0B4: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF0B8:
    ctx->pc = 0x801DF0B8u;
    // 801DF0B8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801DF0BC:
    ctx->pc = 0x801DF0BCu;
    // 801DF0BC: bl      0x8025D7A8
    {
            ctx->lr = 0x801DF0C0u;
            ctx->pc = 0x8025D7A8u;
            return;
    }

label_801DF0C0:
    ctx->pc = 0x801DF0C0u;
    ctx->downcount -= 4;
    // 801DF0C0: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF0C4:
    ctx->pc = 0x801DF0C4u;
    // 801DF0C4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801DF0C8:
    ctx->pc = 0x801DF0C8u;
    // 801DF0C8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801DF0CC:
    ctx->pc = 0x801DF0CCu;
    // 801DF0CC: bl      0x8025D9D4
    {
            ctx->lr = 0x801DF0D0u;
            ctx->pc = 0x8025D9D4u;
            return;
    }

label_801DF0D0:
    ctx->pc = 0x801DF0D0u;
    ctx->downcount -= 2;
    // 801DF0D0: cmpwi   r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DF0D4:
    ctx->pc = 0x801DF0D4u;
    // 801DF0D4: bc    12, 2, 0x801DF0FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF0FC;
        }
    }

label_801DF0D8:
    ctx->pc = 0x801DF0D8u;
    ctx->downcount -= 2;
    // 801DF0D8: cmpwi   r3, 0
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

label_801DF0DC:
    ctx->pc = 0x801DF0DCu;
    // 801DF0DC: bc    12, 2, 0x801DF0FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF0FC;
        }
    }

label_801DF0E0:
    ctx->pc = 0x801DF0E0u;
    ctx->downcount -= 4;
    // 801DF0E0: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DF0E4:
    ctx->pc = 0x801DF0E4u;
    // 801DF0E4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DF0E8:
    ctx->pc = 0x801DF0E8u;
    // 801DF0E8: cmpwi   cr7, r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 0)) | (cr_bits << 0);
    }

label_801DF0EC:
    ctx->pc = 0x801DF0ECu;
    // 801DF0EC: bc    12, 30, 0x801DF0F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF0F4;
        }
    }

label_801DF0F0:
    ctx->pc = 0x801DF0F0u;
    ctx->downcount -= 1;
    // 801DF0F0: addi    r0, r9, -24
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(-24);

label_801DF0F4:
    ctx->pc = 0x801DF0F4u;
    ctx->downcount -= 2;
    // 801DF0F4: cmpwi   r0, 0
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

label_801DF0F8:
    ctx->pc = 0x801DF0F8u;
    // 801DF0F8: bc    4, 2, 0x801DF104
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DF104;
        }
    }

label_801DF0FC:
    ctx->pc = 0x801DF0FCu;
    ctx->downcount -= 2;
    // 801DF0FC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DF100:
    ctx->pc = 0x801DF100u;
    // 801DF100: b       0x801DF18C
    {
            goto label_801DF18C;
    }

label_801DF104:
    ctx->pc = 0x801DF104u;
    ctx->downcount -= 2;
    // 801DF104: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DF108:
    ctx->pc = 0x801DF108u;
    // 801DF108: bc    12, 30, 0x801DF110
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF110;
        }
    }

label_801DF10C:
    ctx->pc = 0x801DF10Cu;
    ctx->downcount -= 1;
    // 801DF10C: addi    r0, r9, -24
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(-24);

label_801DF110:
    ctx->pc = 0x801DF110u;
    ctx->downcount -= 3;
    // 801DF110: lwz     r4, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801DF114:
    ctx->pc = 0x801DF114u;
    // 801DF114: or   r3, r0, r0
    {
        ctx->gpr[3] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801DF118:
    ctx->pc = 0x801DF118u;
    // 801DF118: bl      0x801E7CD4
    {
            ctx->lr = 0x801DF11Cu;
            ctx->pc = 0x801E7CD4u;
            return;
    }

label_801DF11C:
    ctx->pc = 0x801DF11Cu;
    ctx->downcount -= 3;
    // 801DF11C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF120:
    ctx->pc = 0x801DF120u;
    // 801DF120: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DF124:
    ctx->pc = 0x801DF124u;
    // 801DF124: bl      0x801E7A84
    {
            ctx->lr = 0x801DF128u;
            ctx->pc = 0x801E7A84u;
            return;
    }

label_801DF128:
    ctx->pc = 0x801DF128u;
    ctx->downcount -= 2;
    // 801DF128: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DF12C:
    ctx->pc = 0x801DF12Cu;
    // 801DF12C: bc    4, 0, 0x801DF150
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DF150;
        }
    }

label_801DF130:
    ctx->pc = 0x801DF130u;
    ctx->downcount -= 3;
    // 801DF130: lwz     r3, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DF134:
    ctx->pc = 0x801DF134u;
    // 801DF134: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DF138:
    ctx->pc = 0x801DF138u;
    // 801DF138: bl      0x80252254
    {
            ctx->lr = 0x801DF13Cu;
            ctx->pc = 0x80252254u;
            return;
    }

label_801DF13C:
    ctx->pc = 0x801DF13Cu;
    ctx->downcount -= 2;
    // 801DF13C: or.   r3, r3, r3
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

label_801DF140:
    ctx->pc = 0x801DF140u;
    // 801DF140: bc    12, 2, 0x801DF148
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF148;
        }
    }

label_801DF144:
    ctx->pc = 0x801DF144u;
    ctx->downcount -= 1;
    // 801DF144: lwz     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DF148:
    ctx->pc = 0x801DF148u;
    ctx->downcount -= 2;
    // 801DF148: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DF14C:
    ctx->pc = 0x801DF14Cu;
    // 801DF14C: bc    12, 0, 0x801DF168
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF168;
        }
    }

label_801DF150:
    ctx->pc = 0x801DF150u;
    ctx->downcount -= 5;
    // 801DF150: lwz     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801DF154:
    ctx->pc = 0x801DF154u;
    // 801DF154: rlwinm r9, r31, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[31], 2u) & 0xFFFFFFFCu;
    }

label_801DF158:
    ctx->pc = 0x801DF158u;
    // 801DF158: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801DF15C:
    ctx->pc = 0x801DF15Cu;
    // 801DF15C: lfsx    f1, r9, r11
    if (!ppc_fp_available_inline(ctx, 0x801DF15Cu)) return;
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801DF160:
    ctx->pc = 0x801DF160u;
    // 801DF160: bl      0x8025EA34
    {
            ctx->lr = 0x801DF164u;
            ctx->pc = 0x8025EA34u;
            return;
    }

label_801DF164:
    ctx->pc = 0x801DF164u;
    ctx->downcount -= 1;
    // 801DF164: b       0x801DF188
    {
            goto label_801DF188;
    }

label_801DF168:
    ctx->pc = 0x801DF168u;
    ctx->downcount -= 3;
    // 801DF168: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DF16C:
    ctx->pc = 0x801DF16Cu;
    // 801DF16C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DF170:
    ctx->pc = 0x801DF170u;
    // 801DF170: bl      0x801E58DC
    {
            ctx->lr = 0x801DF174u;
            ctx->pc = 0x801E58DCu;
            return;
    }

label_801DF174:
    ctx->pc = 0x801DF174u;
    ctx->downcount -= 3;
    // 801DF174: or.   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DF178:
    ctx->pc = 0x801DF178u;
    // 801DF178: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DF17C:
    ctx->pc = 0x801DF17Cu;
    // 801DF17C: bc    12, 2, 0x801DF18C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF18C;
        }
    }

label_801DF180:
    ctx->pc = 0x801DF180u;
    ctx->downcount -= 2;
    // 801DF180: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801DF184:
    ctx->pc = 0x801DF184u;
    // 801DF184: bl      0x8025EAC8
    {
            ctx->lr = 0x801DF188u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DF188:
    ctx->pc = 0x801DF188u;
    ctx->downcount -= 1;
    // 801DF188: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801DF18C:
    ctx->pc = 0x801DF18Cu;
    ctx->downcount -= 16;
    // 801DF18C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DF190:
    ctx->pc = 0x801DF190u;
    // 801DF190: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DF194:
    ctx->pc = 0x801DF194u;
    // 801DF194: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DF198:
    ctx->pc = 0x801DF198u;
    // 801DF198: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DF19C:
    ctx->pc = 0x801DF19Cu;
    // 801DF19C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DF1A0:
    ctx->pc = 0x801DF1A0u;
    ctx->downcount -= 18;
    // 801DF1A0: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DF1A4:
    ctx->pc = 0x801DF1A4u;
    // 801DF1A4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DF1A8:
    ctx->pc = 0x801DF1A8u;
    // 801DF1A8: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DF1A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_801DF1AC:
    ctx->pc = 0x801DF1ACu;
    // 801DF1AC: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DF1B0:
    ctx->pc = 0x801DF1B0u;
    // 801DF1B0: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DF1B4:
    ctx->pc = 0x801DF1B4u;
    // 801DF1B4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF1B8:
    ctx->pc = 0x801DF1B8u;
    // 801DF1B8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801DF1BC:
    ctx->pc = 0x801DF1BCu;
    // 801DF1BC: bl      0x8025D9D4
    {
            ctx->lr = 0x801DF1C0u;
            ctx->pc = 0x8025D9D4u;
            return;
    }

label_801DF1C0:
    ctx->pc = 0x801DF1C0u;
    ctx->downcount -= 4;
    // 801DF1C0: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF1C4:
    ctx->pc = 0x801DF1C4u;
    // 801DF1C4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801DF1C8:
    ctx->pc = 0x801DF1C8u;
    // 801DF1C8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DF1CC:
    ctx->pc = 0x801DF1CCu;
    // 801DF1CC: bl      0x8025D7A8
    {
            ctx->lr = 0x801DF1D0u;
            ctx->pc = 0x8025D7A8u;
            return;
    }

label_801DF1D0:
    ctx->pc = 0x801DF1D0u;
    ctx->downcount -= 4;
    // 801DF1D0: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF1D4:
    ctx->pc = 0x801DF1D4u;
    // 801DF1D4: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_801DF1D8:
    ctx->pc = 0x801DF1D8u;
    // 801DF1D8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DF1DC:
    ctx->pc = 0x801DF1DCu;
    // 801DF1DC: bl      0x8025D6BC
    {
            ctx->lr = 0x801DF1E0u;
            ctx->pc = 0x8025D6BCu;
            return;
    }

label_801DF1E0:
    ctx->pc = 0x801DF1E0u;
    ctx->downcount -= 3;
    // 801DF1E0: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x801DF1E0u)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_801DF1E4:
    ctx->pc = 0x801DF1E4u;
    // 801DF1E4: cmpwi   r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DF1E8:
    ctx->pc = 0x801DF1E8u;
    // 801DF1E8: bc    12, 2, 0x801DF26C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF26C;
        }
    }

label_801DF1EC:
    ctx->pc = 0x801DF1ECu;
    ctx->downcount -= 2;
    // 801DF1EC: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DF1F0:
    ctx->pc = 0x801DF1F0u;
    // 801DF1F0: bc    12, 2, 0x801DF26C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF26C;
        }
    }

label_801DF1F4:
    ctx->pc = 0x801DF1F4u;
    ctx->downcount -= 4;
    // 801DF1F4: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DF1F8:
    ctx->pc = 0x801DF1F8u;
    // 801DF1F8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DF1FC:
    ctx->pc = 0x801DF1FCu;
    // 801DF1FC: cmpwi   cr7, r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 0)) | (cr_bits << 0);
    }

label_801DF200:
    ctx->pc = 0x801DF200u;
    // 801DF200: bc    12, 30, 0x801DF208
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF208;
        }
    }

label_801DF204:
    ctx->pc = 0x801DF204u;
    ctx->downcount -= 1;
    // 801DF204: addi    r0, r9, -24
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(-24);

label_801DF208:
    ctx->pc = 0x801DF208u;
    ctx->downcount -= 2;
    // 801DF208: cmpwi   r0, 0
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

label_801DF20C:
    ctx->pc = 0x801DF20Cu;
    // 801DF20C: bc    12, 2, 0x801DF26C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF26C;
        }
    }

label_801DF210:
    ctx->pc = 0x801DF210u;
    ctx->downcount -= 2;
    // 801DF210: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DF214:
    ctx->pc = 0x801DF214u;
    // 801DF214: bc    12, 30, 0x801DF21C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF21C;
        }
    }

label_801DF218:
    ctx->pc = 0x801DF218u;
    ctx->downcount -= 1;
    // 801DF218: addi    r3, r9, -24
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(-24);

label_801DF21C:
    ctx->pc = 0x801DF21Cu;
    ctx->downcount -= 2;
    // 801DF21C: lwz     r4, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801DF220:
    ctx->pc = 0x801DF220u;
    // 801DF220: bl      0x801E7CD4
    {
            ctx->lr = 0x801DF224u;
            ctx->pc = 0x801E7CD4u;
            return;
    }

label_801DF224:
    ctx->pc = 0x801DF224u;
    ctx->downcount -= 3;
    // 801DF224: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF228:
    ctx->pc = 0x801DF228u;
    // 801DF228: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DF22C:
    ctx->pc = 0x801DF22Cu;
    // 801DF22C: bl      0x801E7A84
    {
            ctx->lr = 0x801DF230u;
            ctx->pc = 0x801E7A84u;
            return;
    }

label_801DF230:
    ctx->pc = 0x801DF230u;
    ctx->downcount -= 2;
    // 801DF230: or.   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801DF234:
    ctx->pc = 0x801DF234u;
    // 801DF234: bc    4, 0, 0x801DF250
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DF250;
        }
    }

label_801DF238:
    ctx->pc = 0x801DF238u;
    ctx->downcount -= 3;
    // 801DF238: lwz     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DF23C:
    ctx->pc = 0x801DF23Cu;
    // 801DF23C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DF240:
    ctx->pc = 0x801DF240u;
    // 801DF240: bl      0x80252254
    {
            ctx->lr = 0x801DF244u;
            ctx->pc = 0x80252254u;
            return;
    }

label_801DF244:
    ctx->pc = 0x801DF244u;
    ctx->downcount -= 2;
    // 801DF244: or.   r3, r3, r3
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

label_801DF248:
    ctx->pc = 0x801DF248u;
    // 801DF248: bc    12, 2, 0x801DF250
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF250;
        }
    }

label_801DF24C:
    ctx->pc = 0x801DF24Cu;
    ctx->downcount -= 1;
    // 801DF24C: lwz     r30, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801DF250:
    ctx->pc = 0x801DF250u;
    ctx->downcount -= 3;
    // 801DF250: cmpwi   r30, 0
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

label_801DF254:
    ctx->pc = 0x801DF254u;
    // 801DF254: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DF258:
    ctx->pc = 0x801DF258u;
    // 801DF258: bc    12, 0, 0x801DF270
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF270;
        }
    }

label_801DF25C:
    ctx->pc = 0x801DF25Cu;
    ctx->downcount -= 4;
    // 801DF25C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF260:
    ctx->pc = 0x801DF260u;
    // 801DF260: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DF264:
    ctx->pc = 0x801DF264u;
    // 801DF264: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x801DF264u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_801DF268:
    ctx->pc = 0x801DF268u;
    // 801DF268: bl      0x801E78C4
    {
            ctx->lr = 0x801DF26Cu;
            ctx->pc = 0x801E78C4u;
            return;
    }

label_801DF26C:
    ctx->pc = 0x801DF26Cu;
    ctx->downcount -= 1;
    // 801DF26C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801DF270:
    ctx->pc = 0x801DF270u;
    ctx->downcount -= 17;
    // 801DF270: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DF274:
    ctx->pc = 0x801DF274u;
    // 801DF274: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DF278:
    ctx->pc = 0x801DF278u;
    // 801DF278: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DF27C:
    ctx->pc = 0x801DF27Cu;
    // 801DF27C: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x801DF27Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801DF280:
    ctx->pc = 0x801DF280u;
    // 801DF280: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_801DF284:
    ctx->pc = 0x801DF284u;
    // 801DF284: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DF288:
    ctx->pc = 0x801DF288u;
    ctx->downcount -= 21;
    // 801DF288: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DF28C:
    ctx->pc = 0x801DF28Cu;
    // 801DF28C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DF290:
    ctx->pc = 0x801DF290u;
    // 801DF290: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801DF294:
    ctx->pc = 0x801DF294u;
    // 801DF294: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DF298:
    ctx->pc = 0x801DF298u;
    // 801DF298: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF29C:
    ctx->pc = 0x801DF29Cu;
    // 801DF29C: lwz     r31, -26944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26944);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801DF2A0:
    ctx->pc = 0x801DF2A0u;
    // 801DF2A0: lwz     r9, 20(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801DF2A4:
    ctx->pc = 0x801DF2A4u;
    // 801DF2A4: lwz     r29, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_801DF2A8:
    ctx->pc = 0x801DF2A8u;
    // 801DF2A8: addi    r9, r9, 28
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28);

label_801DF2AC:
    ctx->pc = 0x801DF2ACu;
    // 801DF2AC: cmpwi   r29, 1
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

label_801DF2B0:
    ctx->pc = 0x801DF2B0u;
    // 801DF2B0: bc    12, 2, 0x801DF2BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF2BC;
        }
    }

label_801DF2B4:
    ctx->pc = 0x801DF2B4u;
    ctx->downcount -= 2;
    // 801DF2B4: add   r9, r9, r29
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_801DF2B8:
    ctx->pc = 0x801DF2B8u;
    // 801DF2B8: b       0x801DF2C0
    {
            goto label_801DF2C0;
    }

label_801DF2BC:
    ctx->pc = 0x801DF2BCu;
    ctx->downcount -= 1;
    // 801DF2BC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801DF2C0:
    ctx->pc = 0x801DF2C0u;
    ctx->downcount -= 6;
    // 801DF2C0: lwz     r30, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801DF2C4:
    ctx->pc = 0x801DF2C4u;
    // 801DF2C4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801DF2C8:
    ctx->pc = 0x801DF2C8u;
    // 801DF2C8: lwz     r29, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_801DF2CC:
    ctx->pc = 0x801DF2CCu;
    // 801DF2CC: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_801DF2D0:
    ctx->pc = 0x801DF2D0u;
    // 801DF2D0: add   r30, r9, r30
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_801DF2D4:
    ctx->pc = 0x801DF2D4u;
    // 801DF2D4: bl      0x801E776C
    {
            ctx->lr = 0x801DF2D8u;
            ctx->pc = 0x801E776Cu;
            return;
    }

label_801DF2D8:
    ctx->pc = 0x801DF2D8u;
    ctx->downcount -= 5;
    // 801DF2D8: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF2DC:
    ctx->pc = 0x801DF2DCu;
    // 801DF2DC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DF2E0:
    ctx->pc = 0x801DF2E0u;
    // 801DF2E0: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801DF2E4:
    ctx->pc = 0x801DF2E4u;
    // 801DF2E4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF2E8:
    ctx->pc = 0x801DF2E8u;
    // 801DF2E8: bl      0x80256CD0
    {
            ctx->lr = 0x801DF2ECu;
            ctx->pc = 0x80256CD0u;
            return;
    }

label_801DF2EC:
    ctx->pc = 0x801DF2ECu;
    ctx->downcount -= 2;
    // 801DF2EC: cmpwi   r3, 0
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

label_801DF2F0:
    ctx->pc = 0x801DF2F0u;
    // 801DF2F0: bc    4, 2, 0x801DF3B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DF3B8;
        }
    }

label_801DF2F4:
    ctx->pc = 0x801DF2F4u;
    ctx->downcount -= 2;
    // 801DF2F4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF2F8:
    ctx->pc = 0x801DF2F8u;
    // 801DF2F8: bl      0x8025E00C
    {
            ctx->lr = 0x801DF2FCu;
            ctx->pc = 0x8025E00Cu;
            return;
    }

label_801DF2FC:
    ctx->pc = 0x801DF2FCu;
    ctx->downcount -= 6;
    // 801DF2FC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF300:
    ctx->pc = 0x801DF300u;
    // 801DF300: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DF304:
    ctx->pc = 0x801DF304u;
    // 801DF304: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_801DF308:
    ctx->pc = 0x801DF308u;
    // 801DF308: addi    r4, r4, 6092
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6092);

label_801DF30C:
    ctx->pc = 0x801DF30Cu;
    // 801DF30C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF310:
    ctx->pc = 0x801DF310u;
    // 801DF310: bl      0x8025EA54
    {
            ctx->lr = 0x801DF314u;
            ctx->pc = 0x8025EA54u;
            return;
    }

label_801DF314:
    ctx->pc = 0x801DF314u;
    ctx->downcount -= 3;
    // 801DF314: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF318:
    ctx->pc = 0x801DF318u;
    // 801DF318: li      r4, -10001
    ctx->gpr[4] = (u32)(s32)(-10001);

label_801DF31C:
    ctx->pc = 0x801DF31Cu;
    // 801DF31C: bl      0x8025EDB4
    {
            ctx->lr = 0x801DF320u;
            ctx->pc = 0x8025EDB4u;
            return;
    }

label_801DF320:
    ctx->pc = 0x801DF320u;
    ctx->downcount -= 3;
    // 801DF320: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF324:
    ctx->pc = 0x801DF324u;
    // 801DF324: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DF328:
    ctx->pc = 0x801DF328u;
    // 801DF328: bl      0x8025E21C
    {
            ctx->lr = 0x801DF32Cu;
            ctx->pc = 0x8025E21Cu;
            return;
    }

label_801DF32C:
    ctx->pc = 0x801DF32Cu;
    ctx->downcount -= 5;
    // 801DF32C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801DF330:
    ctx->pc = 0x801DF330u;
    // 801DF330: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DF334:
    ctx->pc = 0x801DF334u;
    // 801DF334: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DF338:
    ctx->pc = 0x801DF338u;
    // 801DF338: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF33C:
    ctx->pc = 0x801DF33Cu;
    // 801DF33C: bl      0x8025F508
    {
            ctx->lr = 0x801DF340u;
            ctx->pc = 0x8025F508u;
            return;
    }

label_801DF340:
    ctx->pc = 0x801DF340u;
    ctx->downcount -= 4;
    // 801DF340: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF344:
    ctx->pc = 0x801DF344u;
    // 801DF344: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801DF348:
    ctx->pc = 0x801DF348u;
    // 801DF348: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF34C:
    ctx->pc = 0x801DF34Cu;
    // 801DF34C: bl      0x8025E148
    {
            ctx->lr = 0x801DF350u;
            ctx->pc = 0x8025E148u;
            return;
    }

label_801DF350:
    ctx->pc = 0x801DF350u;
    ctx->downcount -= 4;
    // 801DF350: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801DF354:
    ctx->pc = 0x801DF354u;
    // 801DF354: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF358:
    ctx->pc = 0x801DF358u;
    // 801DF358: addi    r4, r4, 6104
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6104);

label_801DF35C:
    ctx->pc = 0x801DF35Cu;
    // 801DF35C: bl      0x8025EAC8
    {
            ctx->lr = 0x801DF360u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DF360:
    ctx->pc = 0x801DF360u;
    ctx->downcount -= 3;
    // 801DF360: li      r4, -10001
    ctx->gpr[4] = (u32)(s32)(-10001);

label_801DF364:
    ctx->pc = 0x801DF364u;
    // 801DF364: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF368:
    ctx->pc = 0x801DF368u;
    // 801DF368: bl      0x8025ECCC
    {
            ctx->lr = 0x801DF36Cu;
            ctx->pc = 0x8025ECCCu;
            return;
    }

label_801DF36C:
    ctx->pc = 0x801DF36Cu;
    ctx->downcount -= 2;
    // 801DF36C: lwz     r3, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801DF370:
    ctx->pc = 0x801DF370u;
    // 801DF370: bl      0x801E7D70
    {
            ctx->lr = 0x801DF374u;
            ctx->pc = 0x801E7D70u;
            return;
    }

label_801DF374:
    ctx->pc = 0x801DF374u;
    ctx->downcount -= 3;
    // 801DF374: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801DF378:
    ctx->pc = 0x801DF378u;
    // 801DF378: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF37C:
    ctx->pc = 0x801DF37Cu;
    // 801DF37C: bl      0x8025EAC8
    {
            ctx->lr = 0x801DF380u;
            ctx->pc = 0x8025EAC8u;
            return;
    }

label_801DF380:
    ctx->pc = 0x801DF380u;
    ctx->downcount -= 5;
    // 801DF380: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801DF384:
    ctx->pc = 0x801DF384u;
    // 801DF384: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801DF388:
    ctx->pc = 0x801DF388u;
    // 801DF388: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801DF38C:
    ctx->pc = 0x801DF38Cu;
    // 801DF38C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF390:
    ctx->pc = 0x801DF390u;
    // 801DF390: bl      0x8025F508
    {
            ctx->lr = 0x801DF394u;
            ctx->pc = 0x8025F508u;
            return;
    }

label_801DF394:
    ctx->pc = 0x801DF394u;
    ctx->downcount -= 3;
    // 801DF394: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF398:
    ctx->pc = 0x801DF398u;
    // 801DF398: li      r4, -2
    ctx->gpr[4] = (u32)(s32)(-2);

label_801DF39C:
    ctx->pc = 0x801DF39Cu;
    // 801DF39C: bl      0x8025F3FC
    {
            ctx->lr = 0x801DF3A0u;
            ctx->pc = 0x8025F3FCu;
            return;
    }

label_801DF3A0:
    ctx->pc = 0x801DF3A0u;
    ctx->downcount -= 2;
    // 801DF3A0: cmpwi   r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801DF3A4:
    ctx->pc = 0x801DF3A4u;
    // 801DF3A4: bc    4, 2, 0x801DF3B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DF3B8;
        }
    }

label_801DF3A8:
    ctx->pc = 0x801DF3A8u;
    ctx->downcount -= 3;
    // 801DF3A8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801DF3AC:
    ctx->pc = 0x801DF3ACu;
    // 801DF3AC: li      r4, -10000
    ctx->gpr[4] = (u32)(s32)(-10000);

label_801DF3B0:
    ctx->pc = 0x801DF3B0u;
    // 801DF3B0: bl      0x80256B08
    {
            ctx->lr = 0x801DF3B4u;
            ctx->pc = 0x80256B08u;
            return;
    }

label_801DF3B4:
    ctx->pc = 0x801DF3B4u;
    ctx->downcount -= 1;
    // 801DF3B4: stw     r3, 28(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801DF3B8:
    ctx->pc = 0x801DF3B8u;
    ctx->downcount -= 17;
    // 801DF3B8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801DF3BC:
    ctx->pc = 0x801DF3BCu;
    // 801DF3BC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DF3C0:
    ctx->pc = 0x801DF3C0u;
    // 801DF3C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DF3C4:
    ctx->pc = 0x801DF3C4u;
    // 801DF3C4: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801DF3C8:
    ctx->pc = 0x801DF3C8u;
    // 801DF3C8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801DF3CC:
    ctx->pc = 0x801DF3CCu;
    // 801DF3CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DF3D0:
    ctx->pc = 0x801DF3D0u;
    ctx->downcount -= 7;
    // 801DF3D0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DF3D4:
    ctx->pc = 0x801DF3D4u;
    // 801DF3D4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801DF3D8:
    ctx->pc = 0x801DF3D8u;
    // 801DF3D8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801DF3DC:
    ctx->pc = 0x801DF3DCu;
    // 801DF3DC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801DF3E0:
    ctx->pc = 0x801DF3E0u;
    // 801DF3E0: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_801DF3E4:
    ctx->pc = 0x801DF3E4u;
    // 801DF3E4: cmpw    r4, r0
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

label_801DF3E8:
    ctx->pc = 0x801DF3E8u;
    // 801DF3E8: bc    4, 2, 0x801DF4A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801DF4A8;
        }
    }

label_801DF3EC:
    ctx->pc = 0x801DF3ECu;
    ctx->downcount -= 2;
    // 801DF3EC: cmpwi   r3, 0
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

label_801DF3F0:
    ctx->pc = 0x801DF3F0u;
    // 801DF3F0: bc    12, 2, 0x801DF4A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801DF4A8;
        }
    }

label_801DF3F4:
    ctx->pc = 0x801DF3F4u;
    ctx->downcount -= 5;
    // 801DF3F4: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_801DF3F8:
    ctx->pc = 0x801DF3F8u;
    // 801DF3F8: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_801DF3FC:
    ctx->pc = 0x801DF3FCu;
    // 801DF3FC: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_801DF400:
    ctx->pc = 0x801DF400u;
    // 801DF400: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DF404:
    ctx->pc = 0x801DF404u;
    // 801DF404: bl      0x80252AF0
    {
            ctx->lr = 0x801DF408u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DF408:
    ctx->pc = 0x801DF408u;
    ctx->downcount -= 5;
    // 801DF408: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_801DF40C:
    ctx->pc = 0x801DF40Cu;
    // 801DF40C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801DF410:
    ctx->pc = 0x801DF410u;
    // 801DF410: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_801DF414:
    ctx->pc = 0x801DF414u;
    // 801DF414: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DF418:
    ctx->pc = 0x801DF418u;
    // 801DF418: bl      0x80252AF0
    {
            ctx->lr = 0x801DF41Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DF41C:
    ctx->pc = 0x801DF41Cu;
    ctx->downcount -= 5;
    // 801DF41C: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_801DF420:
    ctx->pc = 0x801DF420u;
    // 801DF420: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_801DF424:
    ctx->pc = 0x801DF424u;
    // 801DF424: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_801DF428:
    ctx->pc = 0x801DF428u;
    // 801DF428: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_801DF42C:
    ctx->pc = 0x801DF42Cu;
    // 801DF42C: bl      0x80252AF0
    {
            ctx->lr = 0x801DF430u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DF430:
    ctx->pc = 0x801DF430u;
    ctx->downcount -= 5;
    // 801DF430: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_801DF434:
    ctx->pc = 0x801DF434u;
    // 801DF434: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_801DF438:
    ctx->pc = 0x801DF438u;
    // 801DF438: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_801DF43C:
    ctx->pc = 0x801DF43Cu;
    // 801DF43C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DF440:
    ctx->pc = 0x801DF440u;
    // 801DF440: bl      0x80252AF0
    {
            ctx->lr = 0x801DF444u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DF444:
    ctx->pc = 0x801DF444u;
    ctx->downcount -= 5;
    // 801DF444: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_801DF448:
    ctx->pc = 0x801DF448u;
    // 801DF448: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_801DF44C:
    ctx->pc = 0x801DF44Cu;
    // 801DF44C: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_801DF450:
    ctx->pc = 0x801DF450u;
    // 801DF450: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DF454:
    ctx->pc = 0x801DF454u;
    // 801DF454: bl      0x80252AF0
    {
            ctx->lr = 0x801DF458u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DF458:
    ctx->pc = 0x801DF458u;
    ctx->downcount -= 5;
    // 801DF458: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_801DF45C:
    ctx->pc = 0x801DF45Cu;
    // 801DF45C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_801DF460:
    ctx->pc = 0x801DF460u;
    // 801DF460: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_801DF464:
    ctx->pc = 0x801DF464u;
    // 801DF464: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DF468:
    ctx->pc = 0x801DF468u;
    // 801DF468: bl      0x80252AF0
    {
            ctx->lr = 0x801DF46Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DF46C:
    ctx->pc = 0x801DF46Cu;
    ctx->downcount -= 5;
    // 801DF46C: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_801DF470:
    ctx->pc = 0x801DF470u;
    // 801DF470: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_801DF474:
    ctx->pc = 0x801DF474u;
    // 801DF474: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_801DF478:
    ctx->pc = 0x801DF478u;
    // 801DF478: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DF47C:
    ctx->pc = 0x801DF47Cu;
    // 801DF47C: bl      0x80252AF0
    {
            ctx->lr = 0x801DF480u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DF480:
    ctx->pc = 0x801DF480u;
    ctx->downcount -= 5;
    // 801DF480: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_801DF484:
    ctx->pc = 0x801DF484u;
    // 801DF484: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_801DF488:
    ctx->pc = 0x801DF488u;
    // 801DF488: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_801DF48C:
    ctx->pc = 0x801DF48Cu;
    // 801DF48C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801DF490:
    ctx->pc = 0x801DF490u;
    // 801DF490: bl      0x80252AF0
    {
            ctx->lr = 0x801DF494u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DF494:
    ctx->pc = 0x801DF494u;
    ctx->downcount -= 5;
    // 801DF494: lis     r3, 27765
    ctx->gpr[3] = ((u32)(s32)(27765) << 16);

label_801DF498:
    ctx->pc = 0x801DF498u;
    // 801DF498: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801DF49C:
    ctx->pc = 0x801DF49Cu;
    // 801DF49C: ori     r3, r3, 0x6121
    ctx->gpr[3] = ctx->gpr[3] | 0x6121u;

label_801DF4A0:
    ctx->pc = 0x801DF4A0u;
    // 801DF4A0: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_801DF4A4:
    ctx->pc = 0x801DF4A4u;
    // 801DF4A4: bl      0x80252AF0
    {
            ctx->lr = 0x801DF4A8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801DF4A8:
    ctx->pc = 0x801DF4A8u;
    ctx->downcount -= 5;
    // 801DF4A8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801DF4AC:
    ctx->pc = 0x801DF4ACu;
    // 801DF4AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801DF4B0:
    ctx->pc = 0x801DF4B0u;
    // 801DF4B0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801DF4B4:
    ctx->pc = 0x801DF4B4u;
    // 801DF4B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801DB4C0;
        }
    }

label_801DF4B8:
    ctx->pc = 0x801DF4B8u;
    ctx->downcount -= 2;
    // 801DF4B8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801DF4BC:
    ctx->pc = 0x801DF4BCu;
    // 801DF4BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

    ctx->pc = 0x801DF4C0u;
    return;
return_dispatch_801DB4C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x801DB4CCu: goto label_801DB4CC;
    case 0x801DB674u: goto label_801DB674;
    case 0x801DB6A4u: goto label_801DB6A4;
    case 0x801DB734u: goto label_801DB734;
    case 0x801DB7ECu: goto label_801DB7EC;
    case 0x801DB8A4u: goto label_801DB8A4;
    case 0x801DB900u: goto label_801DB900;
    case 0x801DB9C4u: goto label_801DB9C4;
    case 0x801DB9DCu: goto label_801DB9DC;
    case 0x801DBA38u: goto label_801DBA38;
    case 0x801DBA50u: goto label_801DBA50;
    case 0x801DBA58u: goto label_801DBA58;
    case 0x801DBA64u: goto label_801DBA64;
    case 0x801DBABCu: goto label_801DBABC;
    case 0x801DBBB0u: goto label_801DBBB0;
    case 0x801DBBDCu: goto label_801DBBDC;
    case 0x801DBCACu: goto label_801DBCAC;
    case 0x801DBCFCu: goto label_801DBCFC;
    case 0x801DBD84u: goto label_801DBD84;
    case 0x801DBE28u: goto label_801DBE28;
    case 0x801DBE68u: goto label_801DBE68;
    case 0x801DBE84u: goto label_801DBE84;
    case 0x801DBED0u: goto label_801DBED0;
    case 0x801DBEECu: goto label_801DBEEC;
    case 0x801DBF1Cu: goto label_801DBF1C;
    case 0x801DBF34u: goto label_801DBF34;
    case 0x801DBFA0u: goto label_801DBFA0;
    case 0x801DBFC8u: goto label_801DBFC8;
    case 0x801DBFCCu: goto label_801DBFCC;
    case 0x801DBFFCu: goto label_801DBFFC;
    case 0x801DC010u: goto label_801DC010;
    case 0x801DC024u: goto label_801DC024;
    case 0x801DC038u: goto label_801DC038;
    case 0x801DC04Cu: goto label_801DC04C;
    case 0x801DC060u: goto label_801DC060;
    case 0x801DC074u: goto label_801DC074;
    case 0x801DC088u: goto label_801DC088;
    case 0x801DC09Cu: goto label_801DC09C;
    case 0x801DC0B0u: goto label_801DC0B0;
    case 0x801DC0C4u: goto label_801DC0C4;
    case 0x801DC0D8u: goto label_801DC0D8;
    case 0x801DC0ECu: goto label_801DC0EC;
    case 0x801DC100u: goto label_801DC100;
    case 0x801DC114u: goto label_801DC114;
    case 0x801DC128u: goto label_801DC128;
    case 0x801DC13Cu: goto label_801DC13C;
    case 0x801DC150u: goto label_801DC150;
    case 0x801DC164u: goto label_801DC164;
    case 0x801DC178u: goto label_801DC178;
    case 0x801DC18Cu: goto label_801DC18C;
    case 0x801DC1A0u: goto label_801DC1A0;
    case 0x801DC1B4u: goto label_801DC1B4;
    case 0x801DC1C8u: goto label_801DC1C8;
    case 0x801DC1DCu: goto label_801DC1DC;
    case 0x801DC1F0u: goto label_801DC1F0;
    case 0x801DC204u: goto label_801DC204;
    case 0x801DC218u: goto label_801DC218;
    case 0x801DC22Cu: goto label_801DC22C;
    case 0x801DC240u: goto label_801DC240;
    case 0x801DC254u: goto label_801DC254;
    case 0x801DC268u: goto label_801DC268;
    case 0x801DC27Cu: goto label_801DC27C;
    case 0x801DC290u: goto label_801DC290;
    case 0x801DC2A4u: goto label_801DC2A4;
    case 0x801DC2B8u: goto label_801DC2B8;
    case 0x801DC2CCu: goto label_801DC2CC;
    case 0x801DC2E0u: goto label_801DC2E0;
    case 0x801DC2F4u: goto label_801DC2F4;
    case 0x801DC308u: goto label_801DC308;
    case 0x801DC31Cu: goto label_801DC31C;
    case 0x801DC330u: goto label_801DC330;
    case 0x801DC344u: goto label_801DC344;
    case 0x801DC358u: goto label_801DC358;
    case 0x801DC36Cu: goto label_801DC36C;
    case 0x801DC380u: goto label_801DC380;
    case 0x801DC394u: goto label_801DC394;
    case 0x801DC3A8u: goto label_801DC3A8;
    case 0x801DC3BCu: goto label_801DC3BC;
    case 0x801DC3D0u: goto label_801DC3D0;
    case 0x801DC4A0u: goto label_801DC4A0;
    case 0x801DC4F0u: goto label_801DC4F0;
    case 0x801DC578u: goto label_801DC578;
    case 0x801DC62Cu: goto label_801DC62C;
    case 0x801DC640u: goto label_801DC640;
    case 0x801DC654u: goto label_801DC654;
    case 0x801DC668u: goto label_801DC668;
    case 0x801DC67Cu: goto label_801DC67C;
    case 0x801DC690u: goto label_801DC690;
    case 0x801DC6A4u: goto label_801DC6A4;
    case 0x801DC6B8u: goto label_801DC6B8;
    case 0x801DC6DCu: goto label_801DC6DC;
    case 0x801DC700u: goto label_801DC700;
    case 0x801DC724u: goto label_801DC724;
    case 0x801DC748u: goto label_801DC748;
    case 0x801DC76Cu: goto label_801DC76C;
    case 0x801DC790u: goto label_801DC790;
    case 0x801DC7B4u: goto label_801DC7B4;
    case 0x801DC7D8u: goto label_801DC7D8;
    case 0x801DC7FCu: goto label_801DC7FC;
    case 0x801DC820u: goto label_801DC820;
    case 0x801DC844u: goto label_801DC844;
    case 0x801DC868u: goto label_801DC868;
    case 0x801DC88Cu: goto label_801DC88C;
    case 0x801DC8B0u: goto label_801DC8B0;
    case 0x801DC8D4u: goto label_801DC8D4;
    case 0x801DC8F8u: goto label_801DC8F8;
    case 0x801DC91Cu: goto label_801DC91C;
    case 0x801DC940u: goto label_801DC940;
    case 0x801DC964u: goto label_801DC964;
    case 0x801DC988u: goto label_801DC988;
    case 0x801DC9ACu: goto label_801DC9AC;
    case 0x801DC9D0u: goto label_801DC9D0;
    case 0x801DC9F4u: goto label_801DC9F4;
    case 0x801DCA18u: goto label_801DCA18;
    case 0x801DCA3Cu: goto label_801DCA3C;
    case 0x801DCA60u: goto label_801DCA60;
    case 0x801DCA84u: goto label_801DCA84;
    case 0x801DCAA8u: goto label_801DCAA8;
    case 0x801DCACCu: goto label_801DCACC;
    case 0x801DCAF0u: goto label_801DCAF0;
    case 0x801DCB14u: goto label_801DCB14;
    case 0x801DCB38u: goto label_801DCB38;
    case 0x801DCB5Cu: goto label_801DCB5C;
    case 0x801DCB80u: goto label_801DCB80;
    case 0x801DCBA4u: goto label_801DCBA4;
    case 0x801DCBC8u: goto label_801DCBC8;
    case 0x801DCBECu: goto label_801DCBEC;
    case 0x801DCC10u: goto label_801DCC10;
    case 0x801DCC34u: goto label_801DCC34;
    case 0x801DCC58u: goto label_801DCC58;
    case 0x801DCC7Cu: goto label_801DCC7C;
    case 0x801DCCA0u: goto label_801DCCA0;
    case 0x801DCCC4u: goto label_801DCCC4;
    case 0x801DCCE8u: goto label_801DCCE8;
    case 0x801DCD0Cu: goto label_801DCD0C;
    case 0x801DCD30u: goto label_801DCD30;
    case 0x801DCD54u: goto label_801DCD54;
    case 0x801DCD78u: goto label_801DCD78;
    case 0x801DCD9Cu: goto label_801DCD9C;
    case 0x801DCDC0u: goto label_801DCDC0;
    case 0x801DCDF8u: goto label_801DCDF8;
    case 0x801DCE04u: goto label_801DCE04;
    case 0x801DCE44u: goto label_801DCE44;
    case 0x801DCE50u: goto label_801DCE50;
    case 0x801DCE90u: goto label_801DCE90;
    case 0x801DCE9Cu: goto label_801DCE9C;
    case 0x801DCEE0u: goto label_801DCEE0;
    case 0x801DCEF0u: goto label_801DCEF0;
    case 0x801DCF48u: goto label_801DCF48;
    case 0x801DCF58u: goto label_801DCF58;
    case 0x801DCFACu: goto label_801DCFAC;
    case 0x801DCFB8u: goto label_801DCFB8;
    case 0x801DCFF8u: goto label_801DCFF8;
    case 0x801DD004u: goto label_801DD004;
    case 0x801DD044u: goto label_801DD044;
    case 0x801DD050u: goto label_801DD050;
    case 0x801DD090u: goto label_801DD090;
    case 0x801DD09Cu: goto label_801DD09C;
    case 0x801DD0DCu: goto label_801DD0DC;
    case 0x801DD0E8u: goto label_801DD0E8;
    case 0x801DD128u: goto label_801DD128;
    case 0x801DD134u: goto label_801DD134;
    case 0x801DD178u: goto label_801DD178;
    case 0x801DD188u: goto label_801DD188;
    case 0x801DD1F4u: goto label_801DD1F4;
    case 0x801DD200u: goto label_801DD200;
    case 0x801DD244u: goto label_801DD244;
    case 0x801DD254u: goto label_801DD254;
    case 0x801DD2C0u: goto label_801DD2C0;
    case 0x801DD2D0u: goto label_801DD2D0;
    case 0x801DD32Cu: goto label_801DD32C;
    case 0x801DD338u: goto label_801DD338;
    case 0x801DD37Cu: goto label_801DD37C;
    case 0x801DD38Cu: goto label_801DD38C;
    case 0x801DD3E0u: goto label_801DD3E0;
    case 0x801DD3ECu: goto label_801DD3EC;
    case 0x801DD430u: goto label_801DD430;
    case 0x801DD440u: goto label_801DD440;
    case 0x801DD494u: goto label_801DD494;
    case 0x801DD4A0u: goto label_801DD4A0;
    case 0x801DD4E0u: goto label_801DD4E0;
    case 0x801DD4ECu: goto label_801DD4EC;
    case 0x801DD52Cu: goto label_801DD52C;
    case 0x801DD538u: goto label_801DD538;
    case 0x801DD578u: goto label_801DD578;
    case 0x801DD584u: goto label_801DD584;
    case 0x801DD5C4u: goto label_801DD5C4;
    case 0x801DD5D0u: goto label_801DD5D0;
    case 0x801DD610u: goto label_801DD610;
    case 0x801DD61Cu: goto label_801DD61C;
    case 0x801DD65Cu: goto label_801DD65C;
    case 0x801DD668u: goto label_801DD668;
    case 0x801DD6A8u: goto label_801DD6A8;
    case 0x801DD6B4u: goto label_801DD6B4;
    case 0x801DD6F4u: goto label_801DD6F4;
    case 0x801DD700u: goto label_801DD700;
    case 0x801DD740u: goto label_801DD740;
    case 0x801DD74Cu: goto label_801DD74C;
    case 0x801DD78Cu: goto label_801DD78C;
    case 0x801DD798u: goto label_801DD798;
    case 0x801DD7D8u: goto label_801DD7D8;
    case 0x801DD7E4u: goto label_801DD7E4;
    case 0x801DD824u: goto label_801DD824;
    case 0x801DD830u: goto label_801DD830;
    case 0x801DD870u: goto label_801DD870;
    case 0x801DD87Cu: goto label_801DD87C;
    case 0x801DD8BCu: goto label_801DD8BC;
    case 0x801DD8C8u: goto label_801DD8C8;
    case 0x801DD90Cu: goto label_801DD90C;
    case 0x801DD91Cu: goto label_801DD91C;
    case 0x801DD978u: goto label_801DD978;
    case 0x801DD984u: goto label_801DD984;
    case 0x801DD9C8u: goto label_801DD9C8;
    case 0x801DD9D8u: goto label_801DD9D8;
    case 0x801DDA44u: goto label_801DDA44;
    case 0x801DDA54u: goto label_801DDA54;
    case 0x801DDAB8u: goto label_801DDAB8;
    case 0x801DDAC8u: goto label_801DDAC8;
    case 0x801DDB20u: goto label_801DDB20;
    case 0x801DDB30u: goto label_801DDB30;
    case 0x801DDB44u: goto label_801DDB44;
    case 0x801DDB90u: goto label_801DDB90;
    case 0x801DDBA0u: goto label_801DDBA0;
    case 0x801DDBF4u: goto label_801DDBF4;
    case 0x801DDC00u: goto label_801DDC00;
    case 0x801DDC40u: goto label_801DDC40;
    case 0x801DDC4Cu: goto label_801DDC4C;
    case 0x801DDC90u: goto label_801DDC90;
    case 0x801DDCACu: goto label_801DDCAC;
    case 0x801DDCC4u: goto label_801DDCC4;
    case 0x801DDD20u: goto label_801DDD20;
    case 0x801DDD30u: goto label_801DDD30;
    case 0x801DDD88u: goto label_801DDD88;
    case 0x801DDD98u: goto label_801DDD98;
    case 0x801DDDECu: goto label_801DDDEC;
    case 0x801DDDF8u: goto label_801DDDF8;
    case 0x801DDE3Cu: goto label_801DDE3C;
    case 0x801DDE4Cu: goto label_801DDE4C;
    case 0x801DDEA0u: goto label_801DDEA0;
    case 0x801DDEACu: goto label_801DDEAC;
    case 0x801DDEECu: goto label_801DDEEC;
    case 0x801DDEF8u: goto label_801DDEF8;
    case 0x801DDF20u: goto label_801DDF20;
    case 0x801DDF54u: goto label_801DDF54;
    case 0x801DDFB8u: goto label_801DDFB8;
    case 0x801DDFDCu: goto label_801DDFDC;
    case 0x801DE024u: goto label_801DE024;
    case 0x801DE04Cu: goto label_801DE04C;
    case 0x801DE070u: goto label_801DE070;
    case 0x801DE094u: goto label_801DE094;
    case 0x801DE168u: goto label_801DE168;
    case 0x801DE1B8u: goto label_801DE1B8;
    case 0x801DE240u: goto label_801DE240;
    case 0x801DE2F4u: goto label_801DE2F4;
    case 0x801DE308u: goto label_801DE308;
    case 0x801DE31Cu: goto label_801DE31C;
    case 0x801DE330u: goto label_801DE330;
    case 0x801DE344u: goto label_801DE344;
    case 0x801DE358u: goto label_801DE358;
    case 0x801DE36Cu: goto label_801DE36C;
    case 0x801DE380u: goto label_801DE380;
    case 0x801DE394u: goto label_801DE394;
    case 0x801DE3A8u: goto label_801DE3A8;
    case 0x801DE430u: goto label_801DE430;
    case 0x801DE464u: goto label_801DE464;
    case 0x801DE46Cu: goto label_801DE46C;
    case 0x801DE474u: goto label_801DE474;
    case 0x801DE490u: goto label_801DE490;
    case 0x801DE4BCu: goto label_801DE4BC;
    case 0x801DE4DCu: goto label_801DE4DC;
    case 0x801DE530u: goto label_801DE530;
    case 0x801DE540u: goto label_801DE540;
    case 0x801DE55Cu: goto label_801DE55C;
    case 0x801DE578u: goto label_801DE578;
    case 0x801DE584u: goto label_801DE584;
    case 0x801DE59Cu: goto label_801DE59C;
    case 0x801DE5B0u: goto label_801DE5B0;
    case 0x801DE5C4u: goto label_801DE5C4;
    case 0x801DE5D0u: goto label_801DE5D0;
    case 0x801DE5DCu: goto label_801DE5DC;
    case 0x801DE5E8u: goto label_801DE5E8;
    case 0x801DE5FCu: goto label_801DE5FC;
    case 0x801DE660u: goto label_801DE660;
    case 0x801DE68Cu: goto label_801DE68C;
    case 0x801DE6B8u: goto label_801DE6B8;
    case 0x801DE704u: goto label_801DE704;
    case 0x801DE9A8u: goto label_801DE9A8;
    case 0x801DE9BCu: goto label_801DE9BC;
    case 0x801DE9D0u: goto label_801DE9D0;
    case 0x801DE9E4u: goto label_801DE9E4;
    case 0x801DE9F8u: goto label_801DE9F8;
    case 0x801DEA0Cu: goto label_801DEA0C;
    case 0x801DEA20u: goto label_801DEA20;
    case 0x801DEA34u: goto label_801DEA34;
    case 0x801DEA60u: goto label_801DEA60;
    case 0x801DEA6Cu: goto label_801DEA6C;
    case 0x801DEAA0u: goto label_801DEAA0;
    case 0x801DEAE8u: goto label_801DEAE8;
    case 0x801DEB0Cu: goto label_801DEB0C;
    case 0x801DEB18u: goto label_801DEB18;
    case 0x801DEB20u: goto label_801DEB20;
    case 0x801DEB28u: goto label_801DEB28;
    case 0x801DEB30u: goto label_801DEB30;
    case 0x801DEB38u: goto label_801DEB38;
    case 0x801DEB40u: goto label_801DEB40;
    case 0x801DEB50u: goto label_801DEB50;
    case 0x801DEB5Cu: goto label_801DEB5C;
    case 0x801DEB68u: goto label_801DEB68;
    case 0x801DEB78u: goto label_801DEB78;
    case 0x801DEB88u: goto label_801DEB88;
    case 0x801DEB94u: goto label_801DEB94;
    case 0x801DEBA0u: goto label_801DEBA0;
    case 0x801DEBD8u: goto label_801DEBD8;
    case 0x801DEC04u: goto label_801DEC04;
    case 0x801DEC14u: goto label_801DEC14;
    case 0x801DEC2Cu: goto label_801DEC2C;
    case 0x801DEC38u: goto label_801DEC38;
    case 0x801DEC44u: goto label_801DEC44;
    case 0x801DEC58u: goto label_801DEC58;
    case 0x801DEC68u: goto label_801DEC68;
    case 0x801DEC7Cu: goto label_801DEC7C;
    case 0x801DEC90u: goto label_801DEC90;
    case 0x801DEC9Cu: goto label_801DEC9C;
    case 0x801DECA8u: goto label_801DECA8;
    case 0x801DECE0u: goto label_801DECE0;
    case 0x801DECF4u: goto label_801DECF4;
    case 0x801DED00u: goto label_801DED00;
    case 0x801DED10u: goto label_801DED10;
    case 0x801DED24u: goto label_801DED24;
    case 0x801DED30u: goto label_801DED30;
    case 0x801DED38u: goto label_801DED38;
    case 0x801DED40u: goto label_801DED40;
    case 0x801DED48u: goto label_801DED48;
    case 0x801DED50u: goto label_801DED50;
    case 0x801DED8Cu: goto label_801DED8C;
    case 0x801DEDA8u: goto label_801DEDA8;
    case 0x801DEDB8u: goto label_801DEDB8;
    case 0x801DEDD8u: goto label_801DEDD8;
    case 0x801DEDF8u: goto label_801DEDF8;
    case 0x801DEE08u: goto label_801DEE08;
    case 0x801DEE18u: goto label_801DEE18;
    case 0x801DEE20u: goto label_801DEE20;
    case 0x801DEE54u: goto label_801DEE54;
    case 0x801DEE6Cu: goto label_801DEE6C;
    case 0x801DEEACu: goto label_801DEEAC;
    case 0x801DEED8u: goto label_801DEED8;
    case 0x801DEF10u: goto label_801DEF10;
    case 0x801DEF20u: goto label_801DEF20;
    case 0x801DEF34u: goto label_801DEF34;
    case 0x801DEF40u: goto label_801DEF40;
    case 0x801DEF50u: goto label_801DEF50;
    case 0x801DEF64u: goto label_801DEF64;
    case 0x801DEF70u: goto label_801DEF70;
    case 0x801DEF80u: goto label_801DEF80;
    case 0x801DEF94u: goto label_801DEF94;
    case 0x801DEFA0u: goto label_801DEFA0;
    case 0x801DEFB0u: goto label_801DEFB0;
    case 0x801DEFC4u: goto label_801DEFC4;
    case 0x801DEFD0u: goto label_801DEFD0;
    case 0x801DEFDCu: goto label_801DEFDC;
    case 0x801DEFECu: goto label_801DEFEC;
    case 0x801DF084u: goto label_801DF084;
    case 0x801DF090u: goto label_801DF090;
    case 0x801DF0C0u: goto label_801DF0C0;
    case 0x801DF0D0u: goto label_801DF0D0;
    case 0x801DF11Cu: goto label_801DF11C;
    case 0x801DF128u: goto label_801DF128;
    case 0x801DF13Cu: goto label_801DF13C;
    case 0x801DF164u: goto label_801DF164;
    case 0x801DF174u: goto label_801DF174;
    case 0x801DF188u: goto label_801DF188;
    case 0x801DF1C0u: goto label_801DF1C0;
    case 0x801DF1D0u: goto label_801DF1D0;
    case 0x801DF1E0u: goto label_801DF1E0;
    case 0x801DF224u: goto label_801DF224;
    case 0x801DF230u: goto label_801DF230;
    case 0x801DF244u: goto label_801DF244;
    case 0x801DF26Cu: goto label_801DF26C;
    case 0x801DF2D8u: goto label_801DF2D8;
    case 0x801DF2ECu: goto label_801DF2EC;
    case 0x801DF2FCu: goto label_801DF2FC;
    case 0x801DF314u: goto label_801DF314;
    case 0x801DF320u: goto label_801DF320;
    case 0x801DF32Cu: goto label_801DF32C;
    case 0x801DF340u: goto label_801DF340;
    case 0x801DF350u: goto label_801DF350;
    case 0x801DF360u: goto label_801DF360;
    case 0x801DF36Cu: goto label_801DF36C;
    case 0x801DF374u: goto label_801DF374;
    case 0x801DF380u: goto label_801DF380;
    case 0x801DF394u: goto label_801DF394;
    case 0x801DF3A0u: goto label_801DF3A0;
    case 0x801DF3B4u: goto label_801DF3B4;
    case 0x801DF408u: goto label_801DF408;
    case 0x801DF41Cu: goto label_801DF41C;
    case 0x801DF430u: goto label_801DF430;
    case 0x801DF444u: goto label_801DF444;
    case 0x801DF458u: goto label_801DF458;
    case 0x801DF46Cu: goto label_801DF46C;
    case 0x801DF480u: goto label_801DF480;
    case 0x801DF494u: goto label_801DF494;
    case 0x801DF4A8u: goto label_801DF4A8;
    default: return;
    }
}

