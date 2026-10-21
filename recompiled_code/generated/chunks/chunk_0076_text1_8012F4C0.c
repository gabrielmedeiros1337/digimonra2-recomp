// DolRecomp output
#include "../generated.h"

static void loop_8012F4C4(CPUState* ctx) {
label_8012F4C4:
    ctx->downcount -= 4;
    ctx->pc = 0x8012F4C4u;
    // 8012F4C4: stw     r9, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    // 8012F4C8: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

    // 8012F4CC: cmpw    r4, r0
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

    // 8012F4D0: bc    4, 2, 0x8012F4C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8012F4C4u;
                return;
            }
            goto label_8012F4C4;
        }
    }

    ctx->pc = 0x8012F4D4u;
}

static void loop_8012F508(CPUState* ctx) {
label_8012F508:
    ctx->downcount -= 4;
    ctx->pc = 0x8012F508u;
    // 8012F508: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8012F50Cu;
    // 8012F50C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8012F510: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

    // 8012F514: bc    16, 0, 0x8012F508
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8012F508u;
                return;
            }
            goto label_8012F508;
        }
    }

    ctx->pc = 0x8012F518u;
}

static void loop_8012F554(CPUState* ctx) {
label_8012F554:
    ctx->downcount -= 4;
    ctx->pc = 0x8012F554u;
    // 8012F554: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8012F558: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

    // 8012F55C: cmpw    r4, r31
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

    // 8012F560: bc    4, 2, 0x8012F554
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8012F554u;
                return;
            }
            goto label_8012F554;
        }
    }

    ctx->pc = 0x8012F564u;
}

static void loop_8012F60C(CPUState* ctx) {
label_8012F60C:
    ctx->downcount -= 4;
    ctx->pc = 0x8012F60Cu;
    // 8012F60C: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8012F610u;
    // 8012F610: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8012F614: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

    // 8012F618: bc    16, 0, 0x8012F60C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8012F60Cu;
                return;
            }
            goto label_8012F60C;
        }
    }

    ctx->pc = 0x8012F61Cu;
}

static void loop_80130F20(CPUState* ctx) {
label_80130F20:
    ctx->downcount -= 8;
    ctx->pc = 0x80130F20u;
    // 80130F20: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 80130F24: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 80130F28: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x80130F2Cu;
    // 80130F2C: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 80130F30: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 80130F34: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 80130F38: cmpw    r9, r8
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

    // 80130F3C: bc    4, 2, 0x80130F20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80130F20u;
                return;
            }
            goto label_80130F20;
        }
    }

    ctx->pc = 0x80130F40u;
}

static void loop_8013250C(CPUState* ctx) {
label_8013250C:
    ctx->downcount -= 3;
    // 8013250C: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

    // 80132510: cmpw    r9, r11
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80132514: bc    4, 2, 0x8013250C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8013250Cu;
                return;
            }
            goto label_8013250C;
        }
    }

    ctx->pc = 0x80132518u;
}

static void loop_80132534(CPUState* ctx) {
label_80132534:
    ctx->downcount -= 6;
    ctx->pc = 0x80132534u;
    // 80132534: lhz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 80132538: addic.  r11, r11, -1
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

    // 8013253C: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

    ctx->pc = 0x80132540u;
    // 80132540: sth     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    // 80132544: addi    r6, r6, 2
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(2);

    // 80132548: bc    12, 1, 0x80132534
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80132534u;
                return;
            }
            goto label_80132534;
        }
    }

    ctx->pc = 0x8013254Cu;
}

static void loop_801326CC(CPUState* ctx) {
label_801326CC:
    ctx->downcount -= 3;
    // 801326CC: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

    // 801326D0: cmpw    r9, r11
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 801326D4: bc    4, 2, 0x801326CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801326CCu;
                return;
            }
            goto label_801326CC;
        }
    }

    ctx->pc = 0x801326D8u;
}

static void loop_801326F4(CPUState* ctx) {
label_801326F4:
    ctx->downcount -= 6;
    ctx->pc = 0x801326F4u;
    // 801326F4: lhz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 801326F8: addic.  r11, r11, -1
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

    // 801326FC: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

    ctx->pc = 0x80132700u;
    // 80132700: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    // 80132704: addi    r4, r4, 2
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(2);

    // 80132708: bc    12, 1, 0x801326F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801326F4u;
                return;
            }
            goto label_801326F4;
        }
    }

    ctx->pc = 0x8013270Cu;
}

void func_8012F4C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x8012F4C0u: goto label_8012F4C0;
    case 0x8012F4C4u: goto label_8012F4C4;
    case 0x8012F4C8u: goto label_8012F4C8;
    case 0x8012F4CCu: goto label_8012F4CC;
    case 0x8012F4D0u: goto label_8012F4D0;
    case 0x8012F4D4u: goto label_8012F4D4;
    case 0x8012F4D8u: goto label_8012F4D8;
    case 0x8012F4DCu: goto label_8012F4DC;
    case 0x8012F4E0u: goto label_8012F4E0;
    case 0x8012F4E4u: goto label_8012F4E4;
    case 0x8012F4E8u: goto label_8012F4E8;
    case 0x8012F4ECu: goto label_8012F4EC;
    case 0x8012F4F0u: goto label_8012F4F0;
    case 0x8012F4F4u: goto label_8012F4F4;
    case 0x8012F4F8u: goto label_8012F4F8;
    case 0x8012F4FCu: goto label_8012F4FC;
    case 0x8012F500u: goto label_8012F500;
    case 0x8012F504u: goto label_8012F504;
    case 0x8012F508u: goto label_8012F508;
    case 0x8012F50Cu: goto label_8012F50C;
    case 0x8012F510u: goto label_8012F510;
    case 0x8012F514u: goto label_8012F514;
    case 0x8012F518u: goto label_8012F518;
    case 0x8012F51Cu: goto label_8012F51C;
    case 0x8012F520u: goto label_8012F520;
    case 0x8012F524u: goto label_8012F524;
    case 0x8012F528u: goto label_8012F528;
    case 0x8012F52Cu: goto label_8012F52C;
    case 0x8012F530u: goto label_8012F530;
    case 0x8012F534u: goto label_8012F534;
    case 0x8012F538u: goto label_8012F538;
    case 0x8012F53Cu: goto label_8012F53C;
    case 0x8012F540u: goto label_8012F540;
    case 0x8012F544u: goto label_8012F544;
    case 0x8012F548u: goto label_8012F548;
    case 0x8012F54Cu: goto label_8012F54C;
    case 0x8012F550u: goto label_8012F550;
    case 0x8012F554u: goto label_8012F554;
    case 0x8012F558u: goto label_8012F558;
    case 0x8012F55Cu: goto label_8012F55C;
    case 0x8012F560u: goto label_8012F560;
    case 0x8012F564u: goto label_8012F564;
    case 0x8012F568u: goto label_8012F568;
    case 0x8012F56Cu: goto label_8012F56C;
    case 0x8012F570u: goto label_8012F570;
    case 0x8012F574u: goto label_8012F574;
    case 0x8012F578u: goto label_8012F578;
    case 0x8012F57Cu: goto label_8012F57C;
    case 0x8012F580u: goto label_8012F580;
    case 0x8012F584u: goto label_8012F584;
    case 0x8012F588u: goto label_8012F588;
    case 0x8012F58Cu: goto label_8012F58C;
    case 0x8012F590u: goto label_8012F590;
    case 0x8012F594u: goto label_8012F594;
    case 0x8012F598u: goto label_8012F598;
    case 0x8012F59Cu: goto label_8012F59C;
    case 0x8012F5A0u: goto label_8012F5A0;
    case 0x8012F5A4u: goto label_8012F5A4;
    case 0x8012F5A8u: goto label_8012F5A8;
    case 0x8012F5ACu: goto label_8012F5AC;
    case 0x8012F5B0u: goto label_8012F5B0;
    case 0x8012F5B4u: goto label_8012F5B4;
    case 0x8012F5B8u: goto label_8012F5B8;
    case 0x8012F5BCu: goto label_8012F5BC;
    case 0x8012F5C0u: goto label_8012F5C0;
    case 0x8012F5C4u: goto label_8012F5C4;
    case 0x8012F5C8u: goto label_8012F5C8;
    case 0x8012F5CCu: goto label_8012F5CC;
    case 0x8012F5D0u: goto label_8012F5D0;
    case 0x8012F5D4u: goto label_8012F5D4;
    case 0x8012F5D8u: goto label_8012F5D8;
    case 0x8012F5DCu: goto label_8012F5DC;
    case 0x8012F5E0u: goto label_8012F5E0;
    case 0x8012F5E4u: goto label_8012F5E4;
    case 0x8012F5E8u: goto label_8012F5E8;
    case 0x8012F5ECu: goto label_8012F5EC;
    case 0x8012F5F0u: goto label_8012F5F0;
    case 0x8012F5F4u: goto label_8012F5F4;
    case 0x8012F5F8u: goto label_8012F5F8;
    case 0x8012F5FCu: goto label_8012F5FC;
    case 0x8012F600u: goto label_8012F600;
    case 0x8012F604u: goto label_8012F604;
    case 0x8012F608u: goto label_8012F608;
    case 0x8012F60Cu: goto label_8012F60C;
    case 0x8012F610u: goto label_8012F610;
    case 0x8012F614u: goto label_8012F614;
    case 0x8012F618u: goto label_8012F618;
    case 0x8012F61Cu: goto label_8012F61C;
    case 0x8012F620u: goto label_8012F620;
    case 0x8012F624u: goto label_8012F624;
    case 0x8012F628u: goto label_8012F628;
    case 0x8012F62Cu: goto label_8012F62C;
    case 0x8012F630u: goto label_8012F630;
    case 0x8012F634u: goto label_8012F634;
    case 0x8012F638u: goto label_8012F638;
    case 0x8012F63Cu: goto label_8012F63C;
    case 0x8012F640u: goto label_8012F640;
    case 0x8012F644u: goto label_8012F644;
    case 0x8012F648u: goto label_8012F648;
    case 0x8012F64Cu: goto label_8012F64C;
    case 0x8012F650u: goto label_8012F650;
    case 0x8012F654u: goto label_8012F654;
    case 0x8012F658u: goto label_8012F658;
    case 0x8012F65Cu: goto label_8012F65C;
    case 0x8012F660u: goto label_8012F660;
    case 0x8012F664u: goto label_8012F664;
    case 0x8012F668u: goto label_8012F668;
    case 0x8012F66Cu: goto label_8012F66C;
    case 0x8012F670u: goto label_8012F670;
    case 0x8012F674u: goto label_8012F674;
    case 0x8012F678u: goto label_8012F678;
    case 0x8012F67Cu: goto label_8012F67C;
    case 0x8012F680u: goto label_8012F680;
    case 0x8012F684u: goto label_8012F684;
    case 0x8012F688u: goto label_8012F688;
    case 0x8012F68Cu: goto label_8012F68C;
    case 0x8012F690u: goto label_8012F690;
    case 0x8012F694u: goto label_8012F694;
    case 0x8012F698u: goto label_8012F698;
    case 0x8012F69Cu: goto label_8012F69C;
    case 0x8012F6A0u: goto label_8012F6A0;
    case 0x8012F6A4u: goto label_8012F6A4;
    case 0x8012F6A8u: goto label_8012F6A8;
    case 0x8012F6ACu: goto label_8012F6AC;
    case 0x8012F6B0u: goto label_8012F6B0;
    case 0x8012F6B4u: goto label_8012F6B4;
    case 0x8012F6B8u: goto label_8012F6B8;
    case 0x8012F6BCu: goto label_8012F6BC;
    case 0x8012F6C0u: goto label_8012F6C0;
    case 0x8012F6C4u: goto label_8012F6C4;
    case 0x8012F6C8u: goto label_8012F6C8;
    case 0x8012F6CCu: goto label_8012F6CC;
    case 0x8012F6D0u: goto label_8012F6D0;
    case 0x8012F6D4u: goto label_8012F6D4;
    case 0x8012F6D8u: goto label_8012F6D8;
    case 0x8012F6DCu: goto label_8012F6DC;
    case 0x8012F6E0u: goto label_8012F6E0;
    case 0x8012F6E4u: goto label_8012F6E4;
    case 0x8012F6E8u: goto label_8012F6E8;
    case 0x8012F6ECu: goto label_8012F6EC;
    case 0x8012F6F0u: goto label_8012F6F0;
    case 0x8012F6F4u: goto label_8012F6F4;
    case 0x8012F6F8u: goto label_8012F6F8;
    case 0x8012F6FCu: goto label_8012F6FC;
    case 0x8012F700u: goto label_8012F700;
    case 0x8012F704u: goto label_8012F704;
    case 0x8012F708u: goto label_8012F708;
    case 0x8012F70Cu: goto label_8012F70C;
    case 0x8012F710u: goto label_8012F710;
    case 0x8012F714u: goto label_8012F714;
    case 0x8012F718u: goto label_8012F718;
    case 0x8012F71Cu: goto label_8012F71C;
    case 0x8012F720u: goto label_8012F720;
    case 0x8012F724u: goto label_8012F724;
    case 0x8012F728u: goto label_8012F728;
    case 0x8012F72Cu: goto label_8012F72C;
    case 0x8012F730u: goto label_8012F730;
    case 0x8012F734u: goto label_8012F734;
    case 0x8012F738u: goto label_8012F738;
    case 0x8012F73Cu: goto label_8012F73C;
    case 0x8012F740u: goto label_8012F740;
    case 0x8012F744u: goto label_8012F744;
    case 0x8012F748u: goto label_8012F748;
    case 0x8012F74Cu: goto label_8012F74C;
    case 0x8012F750u: goto label_8012F750;
    case 0x8012F754u: goto label_8012F754;
    case 0x8012F758u: goto label_8012F758;
    case 0x8012F75Cu: goto label_8012F75C;
    case 0x8012F760u: goto label_8012F760;
    case 0x8012F764u: goto label_8012F764;
    case 0x8012F768u: goto label_8012F768;
    case 0x8012F76Cu: goto label_8012F76C;
    case 0x8012F770u: goto label_8012F770;
    case 0x8012F774u: goto label_8012F774;
    case 0x8012F778u: goto label_8012F778;
    case 0x8012F77Cu: goto label_8012F77C;
    case 0x8012F780u: goto label_8012F780;
    case 0x8012F784u: goto label_8012F784;
    case 0x8012F788u: goto label_8012F788;
    case 0x8012F78Cu: goto label_8012F78C;
    case 0x8012F790u: goto label_8012F790;
    case 0x8012F794u: goto label_8012F794;
    case 0x8012F798u: goto label_8012F798;
    case 0x8012F79Cu: goto label_8012F79C;
    case 0x8012F7A0u: goto label_8012F7A0;
    case 0x8012F7A4u: goto label_8012F7A4;
    case 0x8012F7A8u: goto label_8012F7A8;
    case 0x8012F7ACu: goto label_8012F7AC;
    case 0x8012F7B0u: goto label_8012F7B0;
    case 0x8012F7B4u: goto label_8012F7B4;
    case 0x8012F7B8u: goto label_8012F7B8;
    case 0x8012F7BCu: goto label_8012F7BC;
    case 0x8012F7C0u: goto label_8012F7C0;
    case 0x8012F7C4u: goto label_8012F7C4;
    case 0x8012F7C8u: goto label_8012F7C8;
    case 0x8012F7CCu: goto label_8012F7CC;
    case 0x8012F7D0u: goto label_8012F7D0;
    case 0x8012F7D4u: goto label_8012F7D4;
    case 0x8012F7D8u: goto label_8012F7D8;
    case 0x8012F7DCu: goto label_8012F7DC;
    case 0x8012F7E0u: goto label_8012F7E0;
    case 0x8012F7E4u: goto label_8012F7E4;
    case 0x8012F7E8u: goto label_8012F7E8;
    case 0x8012F7ECu: goto label_8012F7EC;
    case 0x8012F7F0u: goto label_8012F7F0;
    case 0x8012F7F4u: goto label_8012F7F4;
    case 0x8012F7F8u: goto label_8012F7F8;
    case 0x8012F7FCu: goto label_8012F7FC;
    case 0x8012F800u: goto label_8012F800;
    case 0x8012F804u: goto label_8012F804;
    case 0x8012F808u: goto label_8012F808;
    case 0x8012F80Cu: goto label_8012F80C;
    case 0x8012F810u: goto label_8012F810;
    case 0x8012F814u: goto label_8012F814;
    case 0x8012F818u: goto label_8012F818;
    case 0x8012F81Cu: goto label_8012F81C;
    case 0x8012F820u: goto label_8012F820;
    case 0x8012F824u: goto label_8012F824;
    case 0x8012F828u: goto label_8012F828;
    case 0x8012F82Cu: goto label_8012F82C;
    case 0x8012F830u: goto label_8012F830;
    case 0x8012F834u: goto label_8012F834;
    case 0x8012F838u: goto label_8012F838;
    case 0x8012F83Cu: goto label_8012F83C;
    case 0x8012F840u: goto label_8012F840;
    case 0x8012F844u: goto label_8012F844;
    case 0x8012F848u: goto label_8012F848;
    case 0x8012F84Cu: goto label_8012F84C;
    case 0x8012F850u: goto label_8012F850;
    case 0x8012F854u: goto label_8012F854;
    case 0x8012F858u: goto label_8012F858;
    case 0x8012F85Cu: goto label_8012F85C;
    case 0x8012F860u: goto label_8012F860;
    case 0x8012F864u: goto label_8012F864;
    case 0x8012F868u: goto label_8012F868;
    case 0x8012F86Cu: goto label_8012F86C;
    case 0x8012F870u: goto label_8012F870;
    case 0x8012F874u: goto label_8012F874;
    case 0x8012F878u: goto label_8012F878;
    case 0x8012F87Cu: goto label_8012F87C;
    case 0x8012F880u: goto label_8012F880;
    case 0x8012F884u: goto label_8012F884;
    case 0x8012F888u: goto label_8012F888;
    case 0x8012F88Cu: goto label_8012F88C;
    case 0x8012F890u: goto label_8012F890;
    case 0x8012F894u: goto label_8012F894;
    case 0x8012F898u: goto label_8012F898;
    case 0x8012F89Cu: goto label_8012F89C;
    case 0x8012F8A0u: goto label_8012F8A0;
    case 0x8012F8A4u: goto label_8012F8A4;
    case 0x8012F8A8u: goto label_8012F8A8;
    case 0x8012F8ACu: goto label_8012F8AC;
    case 0x8012F8B0u: goto label_8012F8B0;
    case 0x8012F8B4u: goto label_8012F8B4;
    case 0x8012F8B8u: goto label_8012F8B8;
    case 0x8012F8BCu: goto label_8012F8BC;
    case 0x8012F8C0u: goto label_8012F8C0;
    case 0x8012F8C4u: goto label_8012F8C4;
    case 0x8012F8C8u: goto label_8012F8C8;
    case 0x8012F8CCu: goto label_8012F8CC;
    case 0x8012F8D0u: goto label_8012F8D0;
    case 0x8012F8D4u: goto label_8012F8D4;
    case 0x8012F8D8u: goto label_8012F8D8;
    case 0x8012F8DCu: goto label_8012F8DC;
    case 0x8012F8E0u: goto label_8012F8E0;
    case 0x8012F8E4u: goto label_8012F8E4;
    case 0x8012F8E8u: goto label_8012F8E8;
    case 0x8012F8ECu: goto label_8012F8EC;
    case 0x8012F8F0u: goto label_8012F8F0;
    case 0x8012F8F4u: goto label_8012F8F4;
    case 0x8012F8F8u: goto label_8012F8F8;
    case 0x8012F8FCu: goto label_8012F8FC;
    case 0x8012F900u: goto label_8012F900;
    case 0x8012F904u: goto label_8012F904;
    case 0x8012F908u: goto label_8012F908;
    case 0x8012F90Cu: goto label_8012F90C;
    case 0x8012F910u: goto label_8012F910;
    case 0x8012F914u: goto label_8012F914;
    case 0x8012F918u: goto label_8012F918;
    case 0x8012F91Cu: goto label_8012F91C;
    case 0x8012F920u: goto label_8012F920;
    case 0x8012F924u: goto label_8012F924;
    case 0x8012F928u: goto label_8012F928;
    case 0x8012F92Cu: goto label_8012F92C;
    case 0x8012F930u: goto label_8012F930;
    case 0x8012F934u: goto label_8012F934;
    case 0x8012F938u: goto label_8012F938;
    case 0x8012F93Cu: goto label_8012F93C;
    case 0x8012F940u: goto label_8012F940;
    case 0x8012F944u: goto label_8012F944;
    case 0x8012F948u: goto label_8012F948;
    case 0x8012F94Cu: goto label_8012F94C;
    case 0x8012F950u: goto label_8012F950;
    case 0x8012F954u: goto label_8012F954;
    case 0x8012F958u: goto label_8012F958;
    case 0x8012F95Cu: goto label_8012F95C;
    case 0x8012F960u: goto label_8012F960;
    case 0x8012F964u: goto label_8012F964;
    case 0x8012F968u: goto label_8012F968;
    case 0x8012F96Cu: goto label_8012F96C;
    case 0x8012F970u: goto label_8012F970;
    case 0x8012F974u: goto label_8012F974;
    case 0x8012F978u: goto label_8012F978;
    case 0x8012F97Cu: goto label_8012F97C;
    case 0x8012F980u: goto label_8012F980;
    case 0x8012F984u: goto label_8012F984;
    case 0x8012F988u: goto label_8012F988;
    case 0x8012F98Cu: goto label_8012F98C;
    case 0x8012F990u: goto label_8012F990;
    case 0x8012F994u: goto label_8012F994;
    case 0x8012F998u: goto label_8012F998;
    case 0x8012F99Cu: goto label_8012F99C;
    case 0x8012F9A0u: goto label_8012F9A0;
    case 0x8012F9A4u: goto label_8012F9A4;
    case 0x8012F9A8u: goto label_8012F9A8;
    case 0x8012F9ACu: goto label_8012F9AC;
    case 0x8012F9B0u: goto label_8012F9B0;
    case 0x8012F9B4u: goto label_8012F9B4;
    case 0x8012F9B8u: goto label_8012F9B8;
    case 0x8012F9BCu: goto label_8012F9BC;
    case 0x8012F9C0u: goto label_8012F9C0;
    case 0x8012F9C4u: goto label_8012F9C4;
    case 0x8012F9C8u: goto label_8012F9C8;
    case 0x8012F9CCu: goto label_8012F9CC;
    case 0x8012F9D0u: goto label_8012F9D0;
    case 0x8012F9D4u: goto label_8012F9D4;
    case 0x8012F9D8u: goto label_8012F9D8;
    case 0x8012F9DCu: goto label_8012F9DC;
    case 0x8012F9E0u: goto label_8012F9E0;
    case 0x8012F9E4u: goto label_8012F9E4;
    case 0x8012F9E8u: goto label_8012F9E8;
    case 0x8012F9ECu: goto label_8012F9EC;
    case 0x8012F9F0u: goto label_8012F9F0;
    case 0x8012F9F4u: goto label_8012F9F4;
    case 0x8012F9F8u: goto label_8012F9F8;
    case 0x8012F9FCu: goto label_8012F9FC;
    case 0x8012FA00u: goto label_8012FA00;
    case 0x8012FA04u: goto label_8012FA04;
    case 0x8012FA08u: goto label_8012FA08;
    case 0x8012FA0Cu: goto label_8012FA0C;
    case 0x8012FA10u: goto label_8012FA10;
    case 0x8012FA14u: goto label_8012FA14;
    case 0x8012FA18u: goto label_8012FA18;
    case 0x8012FA1Cu: goto label_8012FA1C;
    case 0x8012FA20u: goto label_8012FA20;
    case 0x8012FA24u: goto label_8012FA24;
    case 0x8012FA28u: goto label_8012FA28;
    case 0x8012FA2Cu: goto label_8012FA2C;
    case 0x8012FA30u: goto label_8012FA30;
    case 0x8012FA34u: goto label_8012FA34;
    case 0x8012FA38u: goto label_8012FA38;
    case 0x8012FA3Cu: goto label_8012FA3C;
    case 0x8012FA40u: goto label_8012FA40;
    case 0x8012FA44u: goto label_8012FA44;
    case 0x8012FA48u: goto label_8012FA48;
    case 0x8012FA4Cu: goto label_8012FA4C;
    case 0x8012FA50u: goto label_8012FA50;
    case 0x8012FA54u: goto label_8012FA54;
    case 0x8012FA58u: goto label_8012FA58;
    case 0x8012FA5Cu: goto label_8012FA5C;
    case 0x8012FA60u: goto label_8012FA60;
    case 0x8012FA64u: goto label_8012FA64;
    case 0x8012FA68u: goto label_8012FA68;
    case 0x8012FA6Cu: goto label_8012FA6C;
    case 0x8012FA70u: goto label_8012FA70;
    case 0x8012FA74u: goto label_8012FA74;
    case 0x8012FA78u: goto label_8012FA78;
    case 0x8012FA7Cu: goto label_8012FA7C;
    case 0x8012FA80u: goto label_8012FA80;
    case 0x8012FA84u: goto label_8012FA84;
    case 0x8012FA88u: goto label_8012FA88;
    case 0x8012FA8Cu: goto label_8012FA8C;
    case 0x8012FA90u: goto label_8012FA90;
    case 0x8012FA94u: goto label_8012FA94;
    case 0x8012FA98u: goto label_8012FA98;
    case 0x8012FA9Cu: goto label_8012FA9C;
    case 0x8012FAA0u: goto label_8012FAA0;
    case 0x8012FAA4u: goto label_8012FAA4;
    case 0x8012FAA8u: goto label_8012FAA8;
    case 0x8012FAACu: goto label_8012FAAC;
    case 0x8012FAB0u: goto label_8012FAB0;
    case 0x8012FAB4u: goto label_8012FAB4;
    case 0x8012FAB8u: goto label_8012FAB8;
    case 0x8012FABCu: goto label_8012FABC;
    case 0x8012FAC0u: goto label_8012FAC0;
    case 0x8012FAC4u: goto label_8012FAC4;
    case 0x8012FAC8u: goto label_8012FAC8;
    case 0x8012FACCu: goto label_8012FACC;
    case 0x8012FAD0u: goto label_8012FAD0;
    case 0x8012FAD4u: goto label_8012FAD4;
    case 0x8012FAD8u: goto label_8012FAD8;
    case 0x8012FADCu: goto label_8012FADC;
    case 0x8012FAE0u: goto label_8012FAE0;
    case 0x8012FAE4u: goto label_8012FAE4;
    case 0x8012FAE8u: goto label_8012FAE8;
    case 0x8012FAECu: goto label_8012FAEC;
    case 0x8012FAF0u: goto label_8012FAF0;
    case 0x8012FAF4u: goto label_8012FAF4;
    case 0x8012FAF8u: goto label_8012FAF8;
    case 0x8012FAFCu: goto label_8012FAFC;
    case 0x8012FB00u: goto label_8012FB00;
    case 0x8012FB04u: goto label_8012FB04;
    case 0x8012FB08u: goto label_8012FB08;
    case 0x8012FB0Cu: goto label_8012FB0C;
    case 0x8012FB10u: goto label_8012FB10;
    case 0x8012FB14u: goto label_8012FB14;
    case 0x8012FB18u: goto label_8012FB18;
    case 0x8012FB1Cu: goto label_8012FB1C;
    case 0x8012FB20u: goto label_8012FB20;
    case 0x8012FB24u: goto label_8012FB24;
    case 0x8012FB28u: goto label_8012FB28;
    case 0x8012FB2Cu: goto label_8012FB2C;
    case 0x8012FB30u: goto label_8012FB30;
    case 0x8012FB34u: goto label_8012FB34;
    case 0x8012FB38u: goto label_8012FB38;
    case 0x8012FB3Cu: goto label_8012FB3C;
    case 0x8012FB40u: goto label_8012FB40;
    case 0x8012FB44u: goto label_8012FB44;
    case 0x8012FB48u: goto label_8012FB48;
    case 0x8012FB4Cu: goto label_8012FB4C;
    case 0x8012FB50u: goto label_8012FB50;
    case 0x8012FB54u: goto label_8012FB54;
    case 0x8012FB58u: goto label_8012FB58;
    case 0x8012FB5Cu: goto label_8012FB5C;
    case 0x8012FB60u: goto label_8012FB60;
    case 0x8012FB64u: goto label_8012FB64;
    case 0x8012FB68u: goto label_8012FB68;
    case 0x8012FB6Cu: goto label_8012FB6C;
    case 0x8012FB70u: goto label_8012FB70;
    case 0x8012FB74u: goto label_8012FB74;
    case 0x8012FB78u: goto label_8012FB78;
    case 0x8012FB7Cu: goto label_8012FB7C;
    case 0x8012FB80u: goto label_8012FB80;
    case 0x8012FB84u: goto label_8012FB84;
    case 0x8012FB88u: goto label_8012FB88;
    case 0x8012FB8Cu: goto label_8012FB8C;
    case 0x8012FB90u: goto label_8012FB90;
    case 0x8012FB94u: goto label_8012FB94;
    case 0x8012FB98u: goto label_8012FB98;
    case 0x8012FB9Cu: goto label_8012FB9C;
    case 0x8012FBA0u: goto label_8012FBA0;
    case 0x8012FBA4u: goto label_8012FBA4;
    case 0x8012FBA8u: goto label_8012FBA8;
    case 0x8012FBACu: goto label_8012FBAC;
    case 0x8012FBB0u: goto label_8012FBB0;
    case 0x8012FBB4u: goto label_8012FBB4;
    case 0x8012FBB8u: goto label_8012FBB8;
    case 0x8012FBBCu: goto label_8012FBBC;
    case 0x8012FBC0u: goto label_8012FBC0;
    case 0x8012FBC4u: goto label_8012FBC4;
    case 0x8012FBC8u: goto label_8012FBC8;
    case 0x8012FBCCu: goto label_8012FBCC;
    case 0x8012FBD0u: goto label_8012FBD0;
    case 0x8012FBD4u: goto label_8012FBD4;
    case 0x8012FBD8u: goto label_8012FBD8;
    case 0x8012FBDCu: goto label_8012FBDC;
    case 0x8012FBE0u: goto label_8012FBE0;
    case 0x8012FBE4u: goto label_8012FBE4;
    case 0x8012FBE8u: goto label_8012FBE8;
    case 0x8012FBECu: goto label_8012FBEC;
    case 0x8012FBF0u: goto label_8012FBF0;
    case 0x8012FBF4u: goto label_8012FBF4;
    case 0x8012FBF8u: goto label_8012FBF8;
    case 0x8012FBFCu: goto label_8012FBFC;
    case 0x8012FC00u: goto label_8012FC00;
    case 0x8012FC04u: goto label_8012FC04;
    case 0x8012FC08u: goto label_8012FC08;
    case 0x8012FC0Cu: goto label_8012FC0C;
    case 0x8012FC10u: goto label_8012FC10;
    case 0x8012FC14u: goto label_8012FC14;
    case 0x8012FC18u: goto label_8012FC18;
    case 0x8012FC1Cu: goto label_8012FC1C;
    case 0x8012FC20u: goto label_8012FC20;
    case 0x8012FC24u: goto label_8012FC24;
    case 0x8012FC28u: goto label_8012FC28;
    case 0x8012FC2Cu: goto label_8012FC2C;
    case 0x8012FC30u: goto label_8012FC30;
    case 0x8012FC34u: goto label_8012FC34;
    case 0x8012FC38u: goto label_8012FC38;
    case 0x8012FC3Cu: goto label_8012FC3C;
    case 0x8012FC40u: goto label_8012FC40;
    case 0x8012FC44u: goto label_8012FC44;
    case 0x8012FC48u: goto label_8012FC48;
    case 0x8012FC4Cu: goto label_8012FC4C;
    case 0x8012FC50u: goto label_8012FC50;
    case 0x8012FC54u: goto label_8012FC54;
    case 0x8012FC58u: goto label_8012FC58;
    case 0x8012FC5Cu: goto label_8012FC5C;
    case 0x8012FC60u: goto label_8012FC60;
    case 0x8012FC64u: goto label_8012FC64;
    case 0x8012FC68u: goto label_8012FC68;
    case 0x8012FC6Cu: goto label_8012FC6C;
    case 0x8012FC70u: goto label_8012FC70;
    case 0x8012FC74u: goto label_8012FC74;
    case 0x8012FC78u: goto label_8012FC78;
    case 0x8012FC7Cu: goto label_8012FC7C;
    case 0x8012FC80u: goto label_8012FC80;
    case 0x8012FC84u: goto label_8012FC84;
    case 0x8012FC88u: goto label_8012FC88;
    case 0x8012FC8Cu: goto label_8012FC8C;
    case 0x8012FC90u: goto label_8012FC90;
    case 0x8012FC94u: goto label_8012FC94;
    case 0x8012FC98u: goto label_8012FC98;
    case 0x8012FC9Cu: goto label_8012FC9C;
    case 0x8012FCA0u: goto label_8012FCA0;
    case 0x8012FCA4u: goto label_8012FCA4;
    case 0x8012FCA8u: goto label_8012FCA8;
    case 0x8012FCACu: goto label_8012FCAC;
    case 0x8012FCB0u: goto label_8012FCB0;
    case 0x8012FCB4u: goto label_8012FCB4;
    case 0x8012FCB8u: goto label_8012FCB8;
    case 0x8012FCBCu: goto label_8012FCBC;
    case 0x8012FCC0u: goto label_8012FCC0;
    case 0x8012FCC4u: goto label_8012FCC4;
    case 0x8012FCC8u: goto label_8012FCC8;
    case 0x8012FCCCu: goto label_8012FCCC;
    case 0x8012FCD0u: goto label_8012FCD0;
    case 0x8012FCD4u: goto label_8012FCD4;
    case 0x8012FCD8u: goto label_8012FCD8;
    case 0x8012FCDCu: goto label_8012FCDC;
    case 0x8012FCE0u: goto label_8012FCE0;
    case 0x8012FCE4u: goto label_8012FCE4;
    case 0x8012FCE8u: goto label_8012FCE8;
    case 0x8012FCECu: goto label_8012FCEC;
    case 0x8012FCF0u: goto label_8012FCF0;
    case 0x8012FCF4u: goto label_8012FCF4;
    case 0x8012FCF8u: goto label_8012FCF8;
    case 0x8012FCFCu: goto label_8012FCFC;
    case 0x8012FD00u: goto label_8012FD00;
    case 0x8012FD04u: goto label_8012FD04;
    case 0x8012FD08u: goto label_8012FD08;
    case 0x8012FD0Cu: goto label_8012FD0C;
    case 0x8012FD10u: goto label_8012FD10;
    case 0x8012FD14u: goto label_8012FD14;
    case 0x8012FD18u: goto label_8012FD18;
    case 0x8012FD1Cu: goto label_8012FD1C;
    case 0x8012FD20u: goto label_8012FD20;
    case 0x8012FD24u: goto label_8012FD24;
    case 0x8012FD28u: goto label_8012FD28;
    case 0x8012FD2Cu: goto label_8012FD2C;
    case 0x8012FD30u: goto label_8012FD30;
    case 0x8012FD34u: goto label_8012FD34;
    case 0x8012FD38u: goto label_8012FD38;
    case 0x8012FD3Cu: goto label_8012FD3C;
    case 0x8012FD40u: goto label_8012FD40;
    case 0x8012FD44u: goto label_8012FD44;
    case 0x8012FD48u: goto label_8012FD48;
    case 0x8012FD4Cu: goto label_8012FD4C;
    case 0x8012FD50u: goto label_8012FD50;
    case 0x8012FD54u: goto label_8012FD54;
    case 0x8012FD58u: goto label_8012FD58;
    case 0x8012FD5Cu: goto label_8012FD5C;
    case 0x8012FD60u: goto label_8012FD60;
    case 0x8012FD64u: goto label_8012FD64;
    case 0x8012FD68u: goto label_8012FD68;
    case 0x8012FD6Cu: goto label_8012FD6C;
    case 0x8012FD70u: goto label_8012FD70;
    case 0x8012FD74u: goto label_8012FD74;
    case 0x8012FD78u: goto label_8012FD78;
    case 0x8012FD7Cu: goto label_8012FD7C;
    case 0x8012FD80u: goto label_8012FD80;
    case 0x8012FD84u: goto label_8012FD84;
    case 0x8012FD88u: goto label_8012FD88;
    case 0x8012FD8Cu: goto label_8012FD8C;
    case 0x8012FD90u: goto label_8012FD90;
    case 0x8012FD94u: goto label_8012FD94;
    case 0x8012FD98u: goto label_8012FD98;
    case 0x8012FD9Cu: goto label_8012FD9C;
    case 0x8012FDA0u: goto label_8012FDA0;
    case 0x8012FDA4u: goto label_8012FDA4;
    case 0x8012FDA8u: goto label_8012FDA8;
    case 0x8012FDACu: goto label_8012FDAC;
    case 0x8012FDB0u: goto label_8012FDB0;
    case 0x8012FDB4u: goto label_8012FDB4;
    case 0x8012FDB8u: goto label_8012FDB8;
    case 0x8012FDBCu: goto label_8012FDBC;
    case 0x8012FDC0u: goto label_8012FDC0;
    case 0x8012FDC4u: goto label_8012FDC4;
    case 0x8012FDC8u: goto label_8012FDC8;
    case 0x8012FDCCu: goto label_8012FDCC;
    case 0x8012FDD0u: goto label_8012FDD0;
    case 0x8012FDD4u: goto label_8012FDD4;
    case 0x8012FDD8u: goto label_8012FDD8;
    case 0x8012FDDCu: goto label_8012FDDC;
    case 0x8012FDE0u: goto label_8012FDE0;
    case 0x8012FDE4u: goto label_8012FDE4;
    case 0x8012FDE8u: goto label_8012FDE8;
    case 0x8012FDECu: goto label_8012FDEC;
    case 0x8012FDF0u: goto label_8012FDF0;
    case 0x8012FDF4u: goto label_8012FDF4;
    case 0x8012FDF8u: goto label_8012FDF8;
    case 0x8012FDFCu: goto label_8012FDFC;
    case 0x8012FE00u: goto label_8012FE00;
    case 0x8012FE04u: goto label_8012FE04;
    case 0x8012FE08u: goto label_8012FE08;
    case 0x8012FE0Cu: goto label_8012FE0C;
    case 0x8012FE10u: goto label_8012FE10;
    case 0x8012FE14u: goto label_8012FE14;
    case 0x8012FE18u: goto label_8012FE18;
    case 0x8012FE1Cu: goto label_8012FE1C;
    case 0x8012FE20u: goto label_8012FE20;
    case 0x8012FE24u: goto label_8012FE24;
    case 0x8012FE28u: goto label_8012FE28;
    case 0x8012FE2Cu: goto label_8012FE2C;
    case 0x8012FE30u: goto label_8012FE30;
    case 0x8012FE34u: goto label_8012FE34;
    case 0x8012FE38u: goto label_8012FE38;
    case 0x8012FE3Cu: goto label_8012FE3C;
    case 0x8012FE40u: goto label_8012FE40;
    case 0x8012FE44u: goto label_8012FE44;
    case 0x8012FE48u: goto label_8012FE48;
    case 0x8012FE4Cu: goto label_8012FE4C;
    case 0x8012FE50u: goto label_8012FE50;
    case 0x8012FE54u: goto label_8012FE54;
    case 0x8012FE58u: goto label_8012FE58;
    case 0x8012FE5Cu: goto label_8012FE5C;
    case 0x8012FE60u: goto label_8012FE60;
    case 0x8012FE64u: goto label_8012FE64;
    case 0x8012FE68u: goto label_8012FE68;
    case 0x8012FE6Cu: goto label_8012FE6C;
    case 0x8012FE70u: goto label_8012FE70;
    case 0x8012FE74u: goto label_8012FE74;
    case 0x8012FE78u: goto label_8012FE78;
    case 0x8012FE7Cu: goto label_8012FE7C;
    case 0x8012FE80u: goto label_8012FE80;
    case 0x8012FE84u: goto label_8012FE84;
    case 0x8012FE88u: goto label_8012FE88;
    case 0x8012FE8Cu: goto label_8012FE8C;
    case 0x8012FE90u: goto label_8012FE90;
    case 0x8012FE94u: goto label_8012FE94;
    case 0x8012FE98u: goto label_8012FE98;
    case 0x8012FE9Cu: goto label_8012FE9C;
    case 0x8012FEA0u: goto label_8012FEA0;
    case 0x8012FEA4u: goto label_8012FEA4;
    case 0x8012FEA8u: goto label_8012FEA8;
    case 0x8012FEACu: goto label_8012FEAC;
    case 0x8012FEB0u: goto label_8012FEB0;
    case 0x8012FEB4u: goto label_8012FEB4;
    case 0x8012FEB8u: goto label_8012FEB8;
    case 0x8012FEBCu: goto label_8012FEBC;
    case 0x8012FEC0u: goto label_8012FEC0;
    case 0x8012FEC4u: goto label_8012FEC4;
    case 0x8012FEC8u: goto label_8012FEC8;
    case 0x8012FECCu: goto label_8012FECC;
    case 0x8012FED0u: goto label_8012FED0;
    case 0x8012FED4u: goto label_8012FED4;
    case 0x8012FED8u: goto label_8012FED8;
    case 0x8012FEDCu: goto label_8012FEDC;
    case 0x8012FEE0u: goto label_8012FEE0;
    case 0x8012FEE4u: goto label_8012FEE4;
    case 0x8012FEE8u: goto label_8012FEE8;
    case 0x8012FEECu: goto label_8012FEEC;
    case 0x8012FEF0u: goto label_8012FEF0;
    case 0x8012FEF4u: goto label_8012FEF4;
    case 0x8012FEF8u: goto label_8012FEF8;
    case 0x8012FEFCu: goto label_8012FEFC;
    case 0x8012FF00u: goto label_8012FF00;
    case 0x8012FF04u: goto label_8012FF04;
    case 0x8012FF08u: goto label_8012FF08;
    case 0x8012FF0Cu: goto label_8012FF0C;
    case 0x8012FF10u: goto label_8012FF10;
    case 0x8012FF14u: goto label_8012FF14;
    case 0x8012FF18u: goto label_8012FF18;
    case 0x8012FF1Cu: goto label_8012FF1C;
    case 0x8012FF20u: goto label_8012FF20;
    case 0x8012FF24u: goto label_8012FF24;
    case 0x8012FF28u: goto label_8012FF28;
    case 0x8012FF2Cu: goto label_8012FF2C;
    case 0x8012FF30u: goto label_8012FF30;
    case 0x8012FF34u: goto label_8012FF34;
    case 0x8012FF38u: goto label_8012FF38;
    case 0x8012FF3Cu: goto label_8012FF3C;
    case 0x8012FF40u: goto label_8012FF40;
    case 0x8012FF44u: goto label_8012FF44;
    case 0x8012FF48u: goto label_8012FF48;
    case 0x8012FF4Cu: goto label_8012FF4C;
    case 0x8012FF50u: goto label_8012FF50;
    case 0x8012FF54u: goto label_8012FF54;
    case 0x8012FF58u: goto label_8012FF58;
    case 0x8012FF5Cu: goto label_8012FF5C;
    case 0x8012FF60u: goto label_8012FF60;
    case 0x8012FF64u: goto label_8012FF64;
    case 0x8012FF68u: goto label_8012FF68;
    case 0x8012FF6Cu: goto label_8012FF6C;
    case 0x8012FF70u: goto label_8012FF70;
    case 0x8012FF74u: goto label_8012FF74;
    case 0x8012FF78u: goto label_8012FF78;
    case 0x8012FF7Cu: goto label_8012FF7C;
    case 0x8012FF80u: goto label_8012FF80;
    case 0x8012FF84u: goto label_8012FF84;
    case 0x8012FF88u: goto label_8012FF88;
    case 0x8012FF8Cu: goto label_8012FF8C;
    case 0x8012FF90u: goto label_8012FF90;
    case 0x8012FF94u: goto label_8012FF94;
    case 0x8012FF98u: goto label_8012FF98;
    case 0x8012FF9Cu: goto label_8012FF9C;
    case 0x8012FFA0u: goto label_8012FFA0;
    case 0x8012FFA4u: goto label_8012FFA4;
    case 0x8012FFA8u: goto label_8012FFA8;
    case 0x8012FFACu: goto label_8012FFAC;
    case 0x8012FFB0u: goto label_8012FFB0;
    case 0x8012FFB4u: goto label_8012FFB4;
    case 0x8012FFB8u: goto label_8012FFB8;
    case 0x8012FFBCu: goto label_8012FFBC;
    case 0x8012FFC0u: goto label_8012FFC0;
    case 0x8012FFC4u: goto label_8012FFC4;
    case 0x8012FFC8u: goto label_8012FFC8;
    case 0x8012FFCCu: goto label_8012FFCC;
    case 0x8012FFD0u: goto label_8012FFD0;
    case 0x8012FFD4u: goto label_8012FFD4;
    case 0x8012FFD8u: goto label_8012FFD8;
    case 0x8012FFDCu: goto label_8012FFDC;
    case 0x8012FFE0u: goto label_8012FFE0;
    case 0x8012FFE4u: goto label_8012FFE4;
    case 0x8012FFE8u: goto label_8012FFE8;
    case 0x8012FFECu: goto label_8012FFEC;
    case 0x8012FFF0u: goto label_8012FFF0;
    case 0x8012FFF4u: goto label_8012FFF4;
    case 0x8012FFF8u: goto label_8012FFF8;
    case 0x8012FFFCu: goto label_8012FFFC;
    case 0x80130000u: goto label_80130000;
    case 0x80130004u: goto label_80130004;
    case 0x80130008u: goto label_80130008;
    case 0x8013000Cu: goto label_8013000C;
    case 0x80130010u: goto label_80130010;
    case 0x80130014u: goto label_80130014;
    case 0x80130018u: goto label_80130018;
    case 0x8013001Cu: goto label_8013001C;
    case 0x80130020u: goto label_80130020;
    case 0x80130024u: goto label_80130024;
    case 0x80130028u: goto label_80130028;
    case 0x8013002Cu: goto label_8013002C;
    case 0x80130030u: goto label_80130030;
    case 0x80130034u: goto label_80130034;
    case 0x80130038u: goto label_80130038;
    case 0x8013003Cu: goto label_8013003C;
    case 0x80130040u: goto label_80130040;
    case 0x80130044u: goto label_80130044;
    case 0x80130048u: goto label_80130048;
    case 0x8013004Cu: goto label_8013004C;
    case 0x80130050u: goto label_80130050;
    case 0x80130054u: goto label_80130054;
    case 0x80130058u: goto label_80130058;
    case 0x8013005Cu: goto label_8013005C;
    case 0x80130060u: goto label_80130060;
    case 0x80130064u: goto label_80130064;
    case 0x80130068u: goto label_80130068;
    case 0x8013006Cu: goto label_8013006C;
    case 0x80130070u: goto label_80130070;
    case 0x80130074u: goto label_80130074;
    case 0x80130078u: goto label_80130078;
    case 0x8013007Cu: goto label_8013007C;
    case 0x80130080u: goto label_80130080;
    case 0x80130084u: goto label_80130084;
    case 0x80130088u: goto label_80130088;
    case 0x8013008Cu: goto label_8013008C;
    case 0x80130090u: goto label_80130090;
    case 0x80130094u: goto label_80130094;
    case 0x80130098u: goto label_80130098;
    case 0x8013009Cu: goto label_8013009C;
    case 0x801300A0u: goto label_801300A0;
    case 0x801300A4u: goto label_801300A4;
    case 0x801300A8u: goto label_801300A8;
    case 0x801300ACu: goto label_801300AC;
    case 0x801300B0u: goto label_801300B0;
    case 0x801300B4u: goto label_801300B4;
    case 0x801300B8u: goto label_801300B8;
    case 0x801300BCu: goto label_801300BC;
    case 0x801300C0u: goto label_801300C0;
    case 0x801300C4u: goto label_801300C4;
    case 0x801300C8u: goto label_801300C8;
    case 0x801300CCu: goto label_801300CC;
    case 0x801300D0u: goto label_801300D0;
    case 0x801300D4u: goto label_801300D4;
    case 0x801300D8u: goto label_801300D8;
    case 0x801300DCu: goto label_801300DC;
    case 0x801300E0u: goto label_801300E0;
    case 0x801300E4u: goto label_801300E4;
    case 0x801300E8u: goto label_801300E8;
    case 0x801300ECu: goto label_801300EC;
    case 0x801300F0u: goto label_801300F0;
    case 0x801300F4u: goto label_801300F4;
    case 0x801300F8u: goto label_801300F8;
    case 0x801300FCu: goto label_801300FC;
    case 0x80130100u: goto label_80130100;
    case 0x80130104u: goto label_80130104;
    case 0x80130108u: goto label_80130108;
    case 0x8013010Cu: goto label_8013010C;
    case 0x80130110u: goto label_80130110;
    case 0x80130114u: goto label_80130114;
    case 0x80130118u: goto label_80130118;
    case 0x8013011Cu: goto label_8013011C;
    case 0x80130120u: goto label_80130120;
    case 0x80130124u: goto label_80130124;
    case 0x80130128u: goto label_80130128;
    case 0x8013012Cu: goto label_8013012C;
    case 0x80130130u: goto label_80130130;
    case 0x80130134u: goto label_80130134;
    case 0x80130138u: goto label_80130138;
    case 0x8013013Cu: goto label_8013013C;
    case 0x80130140u: goto label_80130140;
    case 0x80130144u: goto label_80130144;
    case 0x80130148u: goto label_80130148;
    case 0x8013014Cu: goto label_8013014C;
    case 0x80130150u: goto label_80130150;
    case 0x80130154u: goto label_80130154;
    case 0x80130158u: goto label_80130158;
    case 0x8013015Cu: goto label_8013015C;
    case 0x80130160u: goto label_80130160;
    case 0x80130164u: goto label_80130164;
    case 0x80130168u: goto label_80130168;
    case 0x8013016Cu: goto label_8013016C;
    case 0x80130170u: goto label_80130170;
    case 0x80130174u: goto label_80130174;
    case 0x80130178u: goto label_80130178;
    case 0x8013017Cu: goto label_8013017C;
    case 0x80130180u: goto label_80130180;
    case 0x80130184u: goto label_80130184;
    case 0x80130188u: goto label_80130188;
    case 0x8013018Cu: goto label_8013018C;
    case 0x80130190u: goto label_80130190;
    case 0x80130194u: goto label_80130194;
    case 0x80130198u: goto label_80130198;
    case 0x8013019Cu: goto label_8013019C;
    case 0x801301A0u: goto label_801301A0;
    case 0x801301A4u: goto label_801301A4;
    case 0x801301A8u: goto label_801301A8;
    case 0x801301ACu: goto label_801301AC;
    case 0x801301B0u: goto label_801301B0;
    case 0x801301B4u: goto label_801301B4;
    case 0x801301B8u: goto label_801301B8;
    case 0x801301BCu: goto label_801301BC;
    case 0x801301C0u: goto label_801301C0;
    case 0x801301C4u: goto label_801301C4;
    case 0x801301C8u: goto label_801301C8;
    case 0x801301CCu: goto label_801301CC;
    case 0x801301D0u: goto label_801301D0;
    case 0x801301D4u: goto label_801301D4;
    case 0x801301D8u: goto label_801301D8;
    case 0x801301DCu: goto label_801301DC;
    case 0x801301E0u: goto label_801301E0;
    case 0x801301E4u: goto label_801301E4;
    case 0x801301E8u: goto label_801301E8;
    case 0x801301ECu: goto label_801301EC;
    case 0x801301F0u: goto label_801301F0;
    case 0x801301F4u: goto label_801301F4;
    case 0x801301F8u: goto label_801301F8;
    case 0x801301FCu: goto label_801301FC;
    case 0x80130200u: goto label_80130200;
    case 0x80130204u: goto label_80130204;
    case 0x80130208u: goto label_80130208;
    case 0x8013020Cu: goto label_8013020C;
    case 0x80130210u: goto label_80130210;
    case 0x80130214u: goto label_80130214;
    case 0x80130218u: goto label_80130218;
    case 0x8013021Cu: goto label_8013021C;
    case 0x80130220u: goto label_80130220;
    case 0x80130224u: goto label_80130224;
    case 0x80130228u: goto label_80130228;
    case 0x8013022Cu: goto label_8013022C;
    case 0x80130230u: goto label_80130230;
    case 0x80130234u: goto label_80130234;
    case 0x80130238u: goto label_80130238;
    case 0x8013023Cu: goto label_8013023C;
    case 0x80130240u: goto label_80130240;
    case 0x80130244u: goto label_80130244;
    case 0x80130248u: goto label_80130248;
    case 0x8013024Cu: goto label_8013024C;
    case 0x80130250u: goto label_80130250;
    case 0x80130254u: goto label_80130254;
    case 0x80130258u: goto label_80130258;
    case 0x8013025Cu: goto label_8013025C;
    case 0x80130260u: goto label_80130260;
    case 0x80130264u: goto label_80130264;
    case 0x80130268u: goto label_80130268;
    case 0x8013026Cu: goto label_8013026C;
    case 0x80130270u: goto label_80130270;
    case 0x80130274u: goto label_80130274;
    case 0x80130278u: goto label_80130278;
    case 0x8013027Cu: goto label_8013027C;
    case 0x80130280u: goto label_80130280;
    case 0x80130284u: goto label_80130284;
    case 0x80130288u: goto label_80130288;
    case 0x8013028Cu: goto label_8013028C;
    case 0x80130290u: goto label_80130290;
    case 0x80130294u: goto label_80130294;
    case 0x80130298u: goto label_80130298;
    case 0x8013029Cu: goto label_8013029C;
    case 0x801302A0u: goto label_801302A0;
    case 0x801302A4u: goto label_801302A4;
    case 0x801302A8u: goto label_801302A8;
    case 0x801302ACu: goto label_801302AC;
    case 0x801302B0u: goto label_801302B0;
    case 0x801302B4u: goto label_801302B4;
    case 0x801302B8u: goto label_801302B8;
    case 0x801302BCu: goto label_801302BC;
    case 0x801302C0u: goto label_801302C0;
    case 0x801302C4u: goto label_801302C4;
    case 0x801302C8u: goto label_801302C8;
    case 0x801302CCu: goto label_801302CC;
    case 0x801302D0u: goto label_801302D0;
    case 0x801302D4u: goto label_801302D4;
    case 0x801302D8u: goto label_801302D8;
    case 0x801302DCu: goto label_801302DC;
    case 0x801302E0u: goto label_801302E0;
    case 0x801302E4u: goto label_801302E4;
    case 0x801302E8u: goto label_801302E8;
    case 0x801302ECu: goto label_801302EC;
    case 0x801302F0u: goto label_801302F0;
    case 0x801302F4u: goto label_801302F4;
    case 0x801302F8u: goto label_801302F8;
    case 0x801302FCu: goto label_801302FC;
    case 0x80130300u: goto label_80130300;
    case 0x80130304u: goto label_80130304;
    case 0x80130308u: goto label_80130308;
    case 0x8013030Cu: goto label_8013030C;
    case 0x80130310u: goto label_80130310;
    case 0x80130314u: goto label_80130314;
    case 0x80130318u: goto label_80130318;
    case 0x8013031Cu: goto label_8013031C;
    case 0x80130320u: goto label_80130320;
    case 0x80130324u: goto label_80130324;
    case 0x80130328u: goto label_80130328;
    case 0x8013032Cu: goto label_8013032C;
    case 0x80130330u: goto label_80130330;
    case 0x80130334u: goto label_80130334;
    case 0x80130338u: goto label_80130338;
    case 0x8013033Cu: goto label_8013033C;
    case 0x80130340u: goto label_80130340;
    case 0x80130344u: goto label_80130344;
    case 0x80130348u: goto label_80130348;
    case 0x8013034Cu: goto label_8013034C;
    case 0x80130350u: goto label_80130350;
    case 0x80130354u: goto label_80130354;
    case 0x80130358u: goto label_80130358;
    case 0x8013035Cu: goto label_8013035C;
    case 0x80130360u: goto label_80130360;
    case 0x80130364u: goto label_80130364;
    case 0x80130368u: goto label_80130368;
    case 0x8013036Cu: goto label_8013036C;
    case 0x80130370u: goto label_80130370;
    case 0x80130374u: goto label_80130374;
    case 0x80130378u: goto label_80130378;
    case 0x8013037Cu: goto label_8013037C;
    case 0x80130380u: goto label_80130380;
    case 0x80130384u: goto label_80130384;
    case 0x80130388u: goto label_80130388;
    case 0x8013038Cu: goto label_8013038C;
    case 0x80130390u: goto label_80130390;
    case 0x80130394u: goto label_80130394;
    case 0x80130398u: goto label_80130398;
    case 0x8013039Cu: goto label_8013039C;
    case 0x801303A0u: goto label_801303A0;
    case 0x801303A4u: goto label_801303A4;
    case 0x801303A8u: goto label_801303A8;
    case 0x801303ACu: goto label_801303AC;
    case 0x801303B0u: goto label_801303B0;
    case 0x801303B4u: goto label_801303B4;
    case 0x801303B8u: goto label_801303B8;
    case 0x801303BCu: goto label_801303BC;
    case 0x801303C0u: goto label_801303C0;
    case 0x801303C4u: goto label_801303C4;
    case 0x801303C8u: goto label_801303C8;
    case 0x801303CCu: goto label_801303CC;
    case 0x801303D0u: goto label_801303D0;
    case 0x801303D4u: goto label_801303D4;
    case 0x801303D8u: goto label_801303D8;
    case 0x801303DCu: goto label_801303DC;
    case 0x801303E0u: goto label_801303E0;
    case 0x801303E4u: goto label_801303E4;
    case 0x801303E8u: goto label_801303E8;
    case 0x801303ECu: goto label_801303EC;
    case 0x801303F0u: goto label_801303F0;
    case 0x801303F4u: goto label_801303F4;
    case 0x801303F8u: goto label_801303F8;
    case 0x801303FCu: goto label_801303FC;
    case 0x80130400u: goto label_80130400;
    case 0x80130404u: goto label_80130404;
    case 0x80130408u: goto label_80130408;
    case 0x8013040Cu: goto label_8013040C;
    case 0x80130410u: goto label_80130410;
    case 0x80130414u: goto label_80130414;
    case 0x80130418u: goto label_80130418;
    case 0x8013041Cu: goto label_8013041C;
    case 0x80130420u: goto label_80130420;
    case 0x80130424u: goto label_80130424;
    case 0x80130428u: goto label_80130428;
    case 0x8013042Cu: goto label_8013042C;
    case 0x80130430u: goto label_80130430;
    case 0x80130434u: goto label_80130434;
    case 0x80130438u: goto label_80130438;
    case 0x8013043Cu: goto label_8013043C;
    case 0x80130440u: goto label_80130440;
    case 0x80130444u: goto label_80130444;
    case 0x80130448u: goto label_80130448;
    case 0x8013044Cu: goto label_8013044C;
    case 0x80130450u: goto label_80130450;
    case 0x80130454u: goto label_80130454;
    case 0x80130458u: goto label_80130458;
    case 0x8013045Cu: goto label_8013045C;
    case 0x80130460u: goto label_80130460;
    case 0x80130464u: goto label_80130464;
    case 0x80130468u: goto label_80130468;
    case 0x8013046Cu: goto label_8013046C;
    case 0x80130470u: goto label_80130470;
    case 0x80130474u: goto label_80130474;
    case 0x80130478u: goto label_80130478;
    case 0x8013047Cu: goto label_8013047C;
    case 0x80130480u: goto label_80130480;
    case 0x80130484u: goto label_80130484;
    case 0x80130488u: goto label_80130488;
    case 0x8013048Cu: goto label_8013048C;
    case 0x80130490u: goto label_80130490;
    case 0x80130494u: goto label_80130494;
    case 0x80130498u: goto label_80130498;
    case 0x8013049Cu: goto label_8013049C;
    case 0x801304A0u: goto label_801304A0;
    case 0x801304A4u: goto label_801304A4;
    case 0x801304A8u: goto label_801304A8;
    case 0x801304ACu: goto label_801304AC;
    case 0x801304B0u: goto label_801304B0;
    case 0x801304B4u: goto label_801304B4;
    case 0x801304B8u: goto label_801304B8;
    case 0x801304BCu: goto label_801304BC;
    case 0x801304C0u: goto label_801304C0;
    case 0x801304C4u: goto label_801304C4;
    case 0x801304C8u: goto label_801304C8;
    case 0x801304CCu: goto label_801304CC;
    case 0x801304D0u: goto label_801304D0;
    case 0x801304D4u: goto label_801304D4;
    case 0x801304D8u: goto label_801304D8;
    case 0x801304DCu: goto label_801304DC;
    case 0x801304E0u: goto label_801304E0;
    case 0x801304E4u: goto label_801304E4;
    case 0x801304E8u: goto label_801304E8;
    case 0x801304ECu: goto label_801304EC;
    case 0x801304F0u: goto label_801304F0;
    case 0x801304F4u: goto label_801304F4;
    case 0x801304F8u: goto label_801304F8;
    case 0x801304FCu: goto label_801304FC;
    case 0x80130500u: goto label_80130500;
    case 0x80130504u: goto label_80130504;
    case 0x80130508u: goto label_80130508;
    case 0x8013050Cu: goto label_8013050C;
    case 0x80130510u: goto label_80130510;
    case 0x80130514u: goto label_80130514;
    case 0x80130518u: goto label_80130518;
    case 0x8013051Cu: goto label_8013051C;
    case 0x80130520u: goto label_80130520;
    case 0x80130524u: goto label_80130524;
    case 0x80130528u: goto label_80130528;
    case 0x8013052Cu: goto label_8013052C;
    case 0x80130530u: goto label_80130530;
    case 0x80130534u: goto label_80130534;
    case 0x80130538u: goto label_80130538;
    case 0x8013053Cu: goto label_8013053C;
    case 0x80130540u: goto label_80130540;
    case 0x80130544u: goto label_80130544;
    case 0x80130548u: goto label_80130548;
    case 0x8013054Cu: goto label_8013054C;
    case 0x80130550u: goto label_80130550;
    case 0x80130554u: goto label_80130554;
    case 0x80130558u: goto label_80130558;
    case 0x8013055Cu: goto label_8013055C;
    case 0x80130560u: goto label_80130560;
    case 0x80130564u: goto label_80130564;
    case 0x80130568u: goto label_80130568;
    case 0x8013056Cu: goto label_8013056C;
    case 0x80130570u: goto label_80130570;
    case 0x80130574u: goto label_80130574;
    case 0x80130578u: goto label_80130578;
    case 0x8013057Cu: goto label_8013057C;
    case 0x80130580u: goto label_80130580;
    case 0x80130584u: goto label_80130584;
    case 0x80130588u: goto label_80130588;
    case 0x8013058Cu: goto label_8013058C;
    case 0x80130590u: goto label_80130590;
    case 0x80130594u: goto label_80130594;
    case 0x80130598u: goto label_80130598;
    case 0x8013059Cu: goto label_8013059C;
    case 0x801305A0u: goto label_801305A0;
    case 0x801305A4u: goto label_801305A4;
    case 0x801305A8u: goto label_801305A8;
    case 0x801305ACu: goto label_801305AC;
    case 0x801305B0u: goto label_801305B0;
    case 0x801305B4u: goto label_801305B4;
    case 0x801305B8u: goto label_801305B8;
    case 0x801305BCu: goto label_801305BC;
    case 0x801305C0u: goto label_801305C0;
    case 0x801305C4u: goto label_801305C4;
    case 0x801305C8u: goto label_801305C8;
    case 0x801305CCu: goto label_801305CC;
    case 0x801305D0u: goto label_801305D0;
    case 0x801305D4u: goto label_801305D4;
    case 0x801305D8u: goto label_801305D8;
    case 0x801305DCu: goto label_801305DC;
    case 0x801305E0u: goto label_801305E0;
    case 0x801305E4u: goto label_801305E4;
    case 0x801305E8u: goto label_801305E8;
    case 0x801305ECu: goto label_801305EC;
    case 0x801305F0u: goto label_801305F0;
    case 0x801305F4u: goto label_801305F4;
    case 0x801305F8u: goto label_801305F8;
    case 0x801305FCu: goto label_801305FC;
    case 0x80130600u: goto label_80130600;
    case 0x80130604u: goto label_80130604;
    case 0x80130608u: goto label_80130608;
    case 0x8013060Cu: goto label_8013060C;
    case 0x80130610u: goto label_80130610;
    case 0x80130614u: goto label_80130614;
    case 0x80130618u: goto label_80130618;
    case 0x8013061Cu: goto label_8013061C;
    case 0x80130620u: goto label_80130620;
    case 0x80130624u: goto label_80130624;
    case 0x80130628u: goto label_80130628;
    case 0x8013062Cu: goto label_8013062C;
    case 0x80130630u: goto label_80130630;
    case 0x80130634u: goto label_80130634;
    case 0x80130638u: goto label_80130638;
    case 0x8013063Cu: goto label_8013063C;
    case 0x80130640u: goto label_80130640;
    case 0x80130644u: goto label_80130644;
    case 0x80130648u: goto label_80130648;
    case 0x8013064Cu: goto label_8013064C;
    case 0x80130650u: goto label_80130650;
    case 0x80130654u: goto label_80130654;
    case 0x80130658u: goto label_80130658;
    case 0x8013065Cu: goto label_8013065C;
    case 0x80130660u: goto label_80130660;
    case 0x80130664u: goto label_80130664;
    case 0x80130668u: goto label_80130668;
    case 0x8013066Cu: goto label_8013066C;
    case 0x80130670u: goto label_80130670;
    case 0x80130674u: goto label_80130674;
    case 0x80130678u: goto label_80130678;
    case 0x8013067Cu: goto label_8013067C;
    case 0x80130680u: goto label_80130680;
    case 0x80130684u: goto label_80130684;
    case 0x80130688u: goto label_80130688;
    case 0x8013068Cu: goto label_8013068C;
    case 0x80130690u: goto label_80130690;
    case 0x80130694u: goto label_80130694;
    case 0x80130698u: goto label_80130698;
    case 0x8013069Cu: goto label_8013069C;
    case 0x801306A0u: goto label_801306A0;
    case 0x801306A4u: goto label_801306A4;
    case 0x801306A8u: goto label_801306A8;
    case 0x801306ACu: goto label_801306AC;
    case 0x801306B0u: goto label_801306B0;
    case 0x801306B4u: goto label_801306B4;
    case 0x801306B8u: goto label_801306B8;
    case 0x801306BCu: goto label_801306BC;
    case 0x801306C0u: goto label_801306C0;
    case 0x801306C4u: goto label_801306C4;
    case 0x801306C8u: goto label_801306C8;
    case 0x801306CCu: goto label_801306CC;
    case 0x801306D0u: goto label_801306D0;
    case 0x801306D4u: goto label_801306D4;
    case 0x801306D8u: goto label_801306D8;
    case 0x801306DCu: goto label_801306DC;
    case 0x801306E0u: goto label_801306E0;
    case 0x801306E4u: goto label_801306E4;
    case 0x801306E8u: goto label_801306E8;
    case 0x801306ECu: goto label_801306EC;
    case 0x801306F0u: goto label_801306F0;
    case 0x801306F4u: goto label_801306F4;
    case 0x801306F8u: goto label_801306F8;
    case 0x801306FCu: goto label_801306FC;
    case 0x80130700u: goto label_80130700;
    case 0x80130704u: goto label_80130704;
    case 0x80130708u: goto label_80130708;
    case 0x8013070Cu: goto label_8013070C;
    case 0x80130710u: goto label_80130710;
    case 0x80130714u: goto label_80130714;
    case 0x80130718u: goto label_80130718;
    case 0x8013071Cu: goto label_8013071C;
    case 0x80130720u: goto label_80130720;
    case 0x80130724u: goto label_80130724;
    case 0x80130728u: goto label_80130728;
    case 0x8013072Cu: goto label_8013072C;
    case 0x80130730u: goto label_80130730;
    case 0x80130734u: goto label_80130734;
    case 0x80130738u: goto label_80130738;
    case 0x8013073Cu: goto label_8013073C;
    case 0x80130740u: goto label_80130740;
    case 0x80130744u: goto label_80130744;
    case 0x80130748u: goto label_80130748;
    case 0x8013074Cu: goto label_8013074C;
    case 0x80130750u: goto label_80130750;
    case 0x80130754u: goto label_80130754;
    case 0x80130758u: goto label_80130758;
    case 0x8013075Cu: goto label_8013075C;
    case 0x80130760u: goto label_80130760;
    case 0x80130764u: goto label_80130764;
    case 0x80130768u: goto label_80130768;
    case 0x8013076Cu: goto label_8013076C;
    case 0x80130770u: goto label_80130770;
    case 0x80130774u: goto label_80130774;
    case 0x80130778u: goto label_80130778;
    case 0x8013077Cu: goto label_8013077C;
    case 0x80130780u: goto label_80130780;
    case 0x80130784u: goto label_80130784;
    case 0x80130788u: goto label_80130788;
    case 0x8013078Cu: goto label_8013078C;
    case 0x80130790u: goto label_80130790;
    case 0x80130794u: goto label_80130794;
    case 0x80130798u: goto label_80130798;
    case 0x8013079Cu: goto label_8013079C;
    case 0x801307A0u: goto label_801307A0;
    case 0x801307A4u: goto label_801307A4;
    case 0x801307A8u: goto label_801307A8;
    case 0x801307ACu: goto label_801307AC;
    case 0x801307B0u: goto label_801307B0;
    case 0x801307B4u: goto label_801307B4;
    case 0x801307B8u: goto label_801307B8;
    case 0x801307BCu: goto label_801307BC;
    case 0x801307C0u: goto label_801307C0;
    case 0x801307C4u: goto label_801307C4;
    case 0x801307C8u: goto label_801307C8;
    case 0x801307CCu: goto label_801307CC;
    case 0x801307D0u: goto label_801307D0;
    case 0x801307D4u: goto label_801307D4;
    case 0x801307D8u: goto label_801307D8;
    case 0x801307DCu: goto label_801307DC;
    case 0x801307E0u: goto label_801307E0;
    case 0x801307E4u: goto label_801307E4;
    case 0x801307E8u: goto label_801307E8;
    case 0x801307ECu: goto label_801307EC;
    case 0x801307F0u: goto label_801307F0;
    case 0x801307F4u: goto label_801307F4;
    case 0x801307F8u: goto label_801307F8;
    case 0x801307FCu: goto label_801307FC;
    case 0x80130800u: goto label_80130800;
    case 0x80130804u: goto label_80130804;
    case 0x80130808u: goto label_80130808;
    case 0x8013080Cu: goto label_8013080C;
    case 0x80130810u: goto label_80130810;
    case 0x80130814u: goto label_80130814;
    case 0x80130818u: goto label_80130818;
    case 0x8013081Cu: goto label_8013081C;
    case 0x80130820u: goto label_80130820;
    case 0x80130824u: goto label_80130824;
    case 0x80130828u: goto label_80130828;
    case 0x8013082Cu: goto label_8013082C;
    case 0x80130830u: goto label_80130830;
    case 0x80130834u: goto label_80130834;
    case 0x80130838u: goto label_80130838;
    case 0x8013083Cu: goto label_8013083C;
    case 0x80130840u: goto label_80130840;
    case 0x80130844u: goto label_80130844;
    case 0x80130848u: goto label_80130848;
    case 0x8013084Cu: goto label_8013084C;
    case 0x80130850u: goto label_80130850;
    case 0x80130854u: goto label_80130854;
    case 0x80130858u: goto label_80130858;
    case 0x8013085Cu: goto label_8013085C;
    case 0x80130860u: goto label_80130860;
    case 0x80130864u: goto label_80130864;
    case 0x80130868u: goto label_80130868;
    case 0x8013086Cu: goto label_8013086C;
    case 0x80130870u: goto label_80130870;
    case 0x80130874u: goto label_80130874;
    case 0x80130878u: goto label_80130878;
    case 0x8013087Cu: goto label_8013087C;
    case 0x80130880u: goto label_80130880;
    case 0x80130884u: goto label_80130884;
    case 0x80130888u: goto label_80130888;
    case 0x8013088Cu: goto label_8013088C;
    case 0x80130890u: goto label_80130890;
    case 0x80130894u: goto label_80130894;
    case 0x80130898u: goto label_80130898;
    case 0x8013089Cu: goto label_8013089C;
    case 0x801308A0u: goto label_801308A0;
    case 0x801308A4u: goto label_801308A4;
    case 0x801308A8u: goto label_801308A8;
    case 0x801308ACu: goto label_801308AC;
    case 0x801308B0u: goto label_801308B0;
    case 0x801308B4u: goto label_801308B4;
    case 0x801308B8u: goto label_801308B8;
    case 0x801308BCu: goto label_801308BC;
    case 0x801308C0u: goto label_801308C0;
    case 0x801308C4u: goto label_801308C4;
    case 0x801308C8u: goto label_801308C8;
    case 0x801308CCu: goto label_801308CC;
    case 0x801308D0u: goto label_801308D0;
    case 0x801308D4u: goto label_801308D4;
    case 0x801308D8u: goto label_801308D8;
    case 0x801308DCu: goto label_801308DC;
    case 0x801308E0u: goto label_801308E0;
    case 0x801308E4u: goto label_801308E4;
    case 0x801308E8u: goto label_801308E8;
    case 0x801308ECu: goto label_801308EC;
    case 0x801308F0u: goto label_801308F0;
    case 0x801308F4u: goto label_801308F4;
    case 0x801308F8u: goto label_801308F8;
    case 0x801308FCu: goto label_801308FC;
    case 0x80130900u: goto label_80130900;
    case 0x80130904u: goto label_80130904;
    case 0x80130908u: goto label_80130908;
    case 0x8013090Cu: goto label_8013090C;
    case 0x80130910u: goto label_80130910;
    case 0x80130914u: goto label_80130914;
    case 0x80130918u: goto label_80130918;
    case 0x8013091Cu: goto label_8013091C;
    case 0x80130920u: goto label_80130920;
    case 0x80130924u: goto label_80130924;
    case 0x80130928u: goto label_80130928;
    case 0x8013092Cu: goto label_8013092C;
    case 0x80130930u: goto label_80130930;
    case 0x80130934u: goto label_80130934;
    case 0x80130938u: goto label_80130938;
    case 0x8013093Cu: goto label_8013093C;
    case 0x80130940u: goto label_80130940;
    case 0x80130944u: goto label_80130944;
    case 0x80130948u: goto label_80130948;
    case 0x8013094Cu: goto label_8013094C;
    case 0x80130950u: goto label_80130950;
    case 0x80130954u: goto label_80130954;
    case 0x80130958u: goto label_80130958;
    case 0x8013095Cu: goto label_8013095C;
    case 0x80130960u: goto label_80130960;
    case 0x80130964u: goto label_80130964;
    case 0x80130968u: goto label_80130968;
    case 0x8013096Cu: goto label_8013096C;
    case 0x80130970u: goto label_80130970;
    case 0x80130974u: goto label_80130974;
    case 0x80130978u: goto label_80130978;
    case 0x8013097Cu: goto label_8013097C;
    case 0x80130980u: goto label_80130980;
    case 0x80130984u: goto label_80130984;
    case 0x80130988u: goto label_80130988;
    case 0x8013098Cu: goto label_8013098C;
    case 0x80130990u: goto label_80130990;
    case 0x80130994u: goto label_80130994;
    case 0x80130998u: goto label_80130998;
    case 0x8013099Cu: goto label_8013099C;
    case 0x801309A0u: goto label_801309A0;
    case 0x801309A4u: goto label_801309A4;
    case 0x801309A8u: goto label_801309A8;
    case 0x801309ACu: goto label_801309AC;
    case 0x801309B0u: goto label_801309B0;
    case 0x801309B4u: goto label_801309B4;
    case 0x801309B8u: goto label_801309B8;
    case 0x801309BCu: goto label_801309BC;
    case 0x801309C0u: goto label_801309C0;
    case 0x801309C4u: goto label_801309C4;
    case 0x801309C8u: goto label_801309C8;
    case 0x801309CCu: goto label_801309CC;
    case 0x801309D0u: goto label_801309D0;
    case 0x801309D4u: goto label_801309D4;
    case 0x801309D8u: goto label_801309D8;
    case 0x801309DCu: goto label_801309DC;
    case 0x801309E0u: goto label_801309E0;
    case 0x801309E4u: goto label_801309E4;
    case 0x801309E8u: goto label_801309E8;
    case 0x801309ECu: goto label_801309EC;
    case 0x801309F0u: goto label_801309F0;
    case 0x801309F4u: goto label_801309F4;
    case 0x801309F8u: goto label_801309F8;
    case 0x801309FCu: goto label_801309FC;
    case 0x80130A00u: goto label_80130A00;
    case 0x80130A04u: goto label_80130A04;
    case 0x80130A08u: goto label_80130A08;
    case 0x80130A0Cu: goto label_80130A0C;
    case 0x80130A10u: goto label_80130A10;
    case 0x80130A14u: goto label_80130A14;
    case 0x80130A18u: goto label_80130A18;
    case 0x80130A1Cu: goto label_80130A1C;
    case 0x80130A20u: goto label_80130A20;
    case 0x80130A24u: goto label_80130A24;
    case 0x80130A28u: goto label_80130A28;
    case 0x80130A2Cu: goto label_80130A2C;
    case 0x80130A30u: goto label_80130A30;
    case 0x80130A34u: goto label_80130A34;
    case 0x80130A38u: goto label_80130A38;
    case 0x80130A3Cu: goto label_80130A3C;
    case 0x80130A40u: goto label_80130A40;
    case 0x80130A44u: goto label_80130A44;
    case 0x80130A48u: goto label_80130A48;
    case 0x80130A4Cu: goto label_80130A4C;
    case 0x80130A50u: goto label_80130A50;
    case 0x80130A54u: goto label_80130A54;
    case 0x80130A58u: goto label_80130A58;
    case 0x80130A5Cu: goto label_80130A5C;
    case 0x80130A60u: goto label_80130A60;
    case 0x80130A64u: goto label_80130A64;
    case 0x80130A68u: goto label_80130A68;
    case 0x80130A6Cu: goto label_80130A6C;
    case 0x80130A70u: goto label_80130A70;
    case 0x80130A74u: goto label_80130A74;
    case 0x80130A78u: goto label_80130A78;
    case 0x80130A7Cu: goto label_80130A7C;
    case 0x80130A80u: goto label_80130A80;
    case 0x80130A84u: goto label_80130A84;
    case 0x80130A88u: goto label_80130A88;
    case 0x80130A8Cu: goto label_80130A8C;
    case 0x80130A90u: goto label_80130A90;
    case 0x80130A94u: goto label_80130A94;
    case 0x80130A98u: goto label_80130A98;
    case 0x80130A9Cu: goto label_80130A9C;
    case 0x80130AA0u: goto label_80130AA0;
    case 0x80130AA4u: goto label_80130AA4;
    case 0x80130AA8u: goto label_80130AA8;
    case 0x80130AACu: goto label_80130AAC;
    case 0x80130AB0u: goto label_80130AB0;
    case 0x80130AB4u: goto label_80130AB4;
    case 0x80130AB8u: goto label_80130AB8;
    case 0x80130ABCu: goto label_80130ABC;
    case 0x80130AC0u: goto label_80130AC0;
    case 0x80130AC4u: goto label_80130AC4;
    case 0x80130AC8u: goto label_80130AC8;
    case 0x80130ACCu: goto label_80130ACC;
    case 0x80130AD0u: goto label_80130AD0;
    case 0x80130AD4u: goto label_80130AD4;
    case 0x80130AD8u: goto label_80130AD8;
    case 0x80130ADCu: goto label_80130ADC;
    case 0x80130AE0u: goto label_80130AE0;
    case 0x80130AE4u: goto label_80130AE4;
    case 0x80130AE8u: goto label_80130AE8;
    case 0x80130AECu: goto label_80130AEC;
    case 0x80130AF0u: goto label_80130AF0;
    case 0x80130AF4u: goto label_80130AF4;
    case 0x80130AF8u: goto label_80130AF8;
    case 0x80130AFCu: goto label_80130AFC;
    case 0x80130B00u: goto label_80130B00;
    case 0x80130B04u: goto label_80130B04;
    case 0x80130B08u: goto label_80130B08;
    case 0x80130B0Cu: goto label_80130B0C;
    case 0x80130B10u: goto label_80130B10;
    case 0x80130B14u: goto label_80130B14;
    case 0x80130B18u: goto label_80130B18;
    case 0x80130B1Cu: goto label_80130B1C;
    case 0x80130B20u: goto label_80130B20;
    case 0x80130B24u: goto label_80130B24;
    case 0x80130B28u: goto label_80130B28;
    case 0x80130B2Cu: goto label_80130B2C;
    case 0x80130B30u: goto label_80130B30;
    case 0x80130B34u: goto label_80130B34;
    case 0x80130B38u: goto label_80130B38;
    case 0x80130B3Cu: goto label_80130B3C;
    case 0x80130B40u: goto label_80130B40;
    case 0x80130B44u: goto label_80130B44;
    case 0x80130B48u: goto label_80130B48;
    case 0x80130B4Cu: goto label_80130B4C;
    case 0x80130B50u: goto label_80130B50;
    case 0x80130B54u: goto label_80130B54;
    case 0x80130B58u: goto label_80130B58;
    case 0x80130B5Cu: goto label_80130B5C;
    case 0x80130B60u: goto label_80130B60;
    case 0x80130B64u: goto label_80130B64;
    case 0x80130B68u: goto label_80130B68;
    case 0x80130B6Cu: goto label_80130B6C;
    case 0x80130B70u: goto label_80130B70;
    case 0x80130B74u: goto label_80130B74;
    case 0x80130B78u: goto label_80130B78;
    case 0x80130B7Cu: goto label_80130B7C;
    case 0x80130B80u: goto label_80130B80;
    case 0x80130B84u: goto label_80130B84;
    case 0x80130B88u: goto label_80130B88;
    case 0x80130B8Cu: goto label_80130B8C;
    case 0x80130B90u: goto label_80130B90;
    case 0x80130B94u: goto label_80130B94;
    case 0x80130B98u: goto label_80130B98;
    case 0x80130B9Cu: goto label_80130B9C;
    case 0x80130BA0u: goto label_80130BA0;
    case 0x80130BA4u: goto label_80130BA4;
    case 0x80130BA8u: goto label_80130BA8;
    case 0x80130BACu: goto label_80130BAC;
    case 0x80130BB0u: goto label_80130BB0;
    case 0x80130BB4u: goto label_80130BB4;
    case 0x80130BB8u: goto label_80130BB8;
    case 0x80130BBCu: goto label_80130BBC;
    case 0x80130BC0u: goto label_80130BC0;
    case 0x80130BC4u: goto label_80130BC4;
    case 0x80130BC8u: goto label_80130BC8;
    case 0x80130BCCu: goto label_80130BCC;
    case 0x80130BD0u: goto label_80130BD0;
    case 0x80130BD4u: goto label_80130BD4;
    case 0x80130BD8u: goto label_80130BD8;
    case 0x80130BDCu: goto label_80130BDC;
    case 0x80130BE0u: goto label_80130BE0;
    case 0x80130BE4u: goto label_80130BE4;
    case 0x80130BE8u: goto label_80130BE8;
    case 0x80130BECu: goto label_80130BEC;
    case 0x80130BF0u: goto label_80130BF0;
    case 0x80130BF4u: goto label_80130BF4;
    case 0x80130BF8u: goto label_80130BF8;
    case 0x80130BFCu: goto label_80130BFC;
    case 0x80130C00u: goto label_80130C00;
    case 0x80130C04u: goto label_80130C04;
    case 0x80130C08u: goto label_80130C08;
    case 0x80130C0Cu: goto label_80130C0C;
    case 0x80130C10u: goto label_80130C10;
    case 0x80130C14u: goto label_80130C14;
    case 0x80130C18u: goto label_80130C18;
    case 0x80130C1Cu: goto label_80130C1C;
    case 0x80130C20u: goto label_80130C20;
    case 0x80130C24u: goto label_80130C24;
    case 0x80130C28u: goto label_80130C28;
    case 0x80130C2Cu: goto label_80130C2C;
    case 0x80130C30u: goto label_80130C30;
    case 0x80130C34u: goto label_80130C34;
    case 0x80130C38u: goto label_80130C38;
    case 0x80130C3Cu: goto label_80130C3C;
    case 0x80130C40u: goto label_80130C40;
    case 0x80130C44u: goto label_80130C44;
    case 0x80130C48u: goto label_80130C48;
    case 0x80130C4Cu: goto label_80130C4C;
    case 0x80130C50u: goto label_80130C50;
    case 0x80130C54u: goto label_80130C54;
    case 0x80130C58u: goto label_80130C58;
    case 0x80130C5Cu: goto label_80130C5C;
    case 0x80130C60u: goto label_80130C60;
    case 0x80130C64u: goto label_80130C64;
    case 0x80130C68u: goto label_80130C68;
    case 0x80130C6Cu: goto label_80130C6C;
    case 0x80130C70u: goto label_80130C70;
    case 0x80130C74u: goto label_80130C74;
    case 0x80130C78u: goto label_80130C78;
    case 0x80130C7Cu: goto label_80130C7C;
    case 0x80130C80u: goto label_80130C80;
    case 0x80130C84u: goto label_80130C84;
    case 0x80130C88u: goto label_80130C88;
    case 0x80130C8Cu: goto label_80130C8C;
    case 0x80130C90u: goto label_80130C90;
    case 0x80130C94u: goto label_80130C94;
    case 0x80130C98u: goto label_80130C98;
    case 0x80130C9Cu: goto label_80130C9C;
    case 0x80130CA0u: goto label_80130CA0;
    case 0x80130CA4u: goto label_80130CA4;
    case 0x80130CA8u: goto label_80130CA8;
    case 0x80130CACu: goto label_80130CAC;
    case 0x80130CB0u: goto label_80130CB0;
    case 0x80130CB4u: goto label_80130CB4;
    case 0x80130CB8u: goto label_80130CB8;
    case 0x80130CBCu: goto label_80130CBC;
    case 0x80130CC0u: goto label_80130CC0;
    case 0x80130CC4u: goto label_80130CC4;
    case 0x80130CC8u: goto label_80130CC8;
    case 0x80130CCCu: goto label_80130CCC;
    case 0x80130CD0u: goto label_80130CD0;
    case 0x80130CD4u: goto label_80130CD4;
    case 0x80130CD8u: goto label_80130CD8;
    case 0x80130CDCu: goto label_80130CDC;
    case 0x80130CE0u: goto label_80130CE0;
    case 0x80130CE4u: goto label_80130CE4;
    case 0x80130CE8u: goto label_80130CE8;
    case 0x80130CECu: goto label_80130CEC;
    case 0x80130CF0u: goto label_80130CF0;
    case 0x80130CF4u: goto label_80130CF4;
    case 0x80130CF8u: goto label_80130CF8;
    case 0x80130CFCu: goto label_80130CFC;
    case 0x80130D00u: goto label_80130D00;
    case 0x80130D04u: goto label_80130D04;
    case 0x80130D08u: goto label_80130D08;
    case 0x80130D0Cu: goto label_80130D0C;
    case 0x80130D10u: goto label_80130D10;
    case 0x80130D14u: goto label_80130D14;
    case 0x80130D18u: goto label_80130D18;
    case 0x80130D1Cu: goto label_80130D1C;
    case 0x80130D20u: goto label_80130D20;
    case 0x80130D24u: goto label_80130D24;
    case 0x80130D28u: goto label_80130D28;
    case 0x80130D2Cu: goto label_80130D2C;
    case 0x80130D30u: goto label_80130D30;
    case 0x80130D34u: goto label_80130D34;
    case 0x80130D38u: goto label_80130D38;
    case 0x80130D3Cu: goto label_80130D3C;
    case 0x80130D40u: goto label_80130D40;
    case 0x80130D44u: goto label_80130D44;
    case 0x80130D48u: goto label_80130D48;
    case 0x80130D4Cu: goto label_80130D4C;
    case 0x80130D50u: goto label_80130D50;
    case 0x80130D54u: goto label_80130D54;
    case 0x80130D58u: goto label_80130D58;
    case 0x80130D5Cu: goto label_80130D5C;
    case 0x80130D60u: goto label_80130D60;
    case 0x80130D64u: goto label_80130D64;
    case 0x80130D68u: goto label_80130D68;
    case 0x80130D6Cu: goto label_80130D6C;
    case 0x80130D70u: goto label_80130D70;
    case 0x80130D74u: goto label_80130D74;
    case 0x80130D78u: goto label_80130D78;
    case 0x80130D7Cu: goto label_80130D7C;
    case 0x80130D80u: goto label_80130D80;
    case 0x80130D84u: goto label_80130D84;
    case 0x80130D88u: goto label_80130D88;
    case 0x80130D8Cu: goto label_80130D8C;
    case 0x80130D90u: goto label_80130D90;
    case 0x80130D94u: goto label_80130D94;
    case 0x80130D98u: goto label_80130D98;
    case 0x80130D9Cu: goto label_80130D9C;
    case 0x80130DA0u: goto label_80130DA0;
    case 0x80130DA4u: goto label_80130DA4;
    case 0x80130DA8u: goto label_80130DA8;
    case 0x80130DACu: goto label_80130DAC;
    case 0x80130DB0u: goto label_80130DB0;
    case 0x80130DB4u: goto label_80130DB4;
    case 0x80130DB8u: goto label_80130DB8;
    case 0x80130DBCu: goto label_80130DBC;
    case 0x80130DC0u: goto label_80130DC0;
    case 0x80130DC4u: goto label_80130DC4;
    case 0x80130DC8u: goto label_80130DC8;
    case 0x80130DCCu: goto label_80130DCC;
    case 0x80130DD0u: goto label_80130DD0;
    case 0x80130DD4u: goto label_80130DD4;
    case 0x80130DD8u: goto label_80130DD8;
    case 0x80130DDCu: goto label_80130DDC;
    case 0x80130DE0u: goto label_80130DE0;
    case 0x80130DE4u: goto label_80130DE4;
    case 0x80130DE8u: goto label_80130DE8;
    case 0x80130DECu: goto label_80130DEC;
    case 0x80130DF0u: goto label_80130DF0;
    case 0x80130DF4u: goto label_80130DF4;
    case 0x80130DF8u: goto label_80130DF8;
    case 0x80130DFCu: goto label_80130DFC;
    case 0x80130E00u: goto label_80130E00;
    case 0x80130E04u: goto label_80130E04;
    case 0x80130E08u: goto label_80130E08;
    case 0x80130E0Cu: goto label_80130E0C;
    case 0x80130E10u: goto label_80130E10;
    case 0x80130E14u: goto label_80130E14;
    case 0x80130E18u: goto label_80130E18;
    case 0x80130E1Cu: goto label_80130E1C;
    case 0x80130E20u: goto label_80130E20;
    case 0x80130E24u: goto label_80130E24;
    case 0x80130E28u: goto label_80130E28;
    case 0x80130E2Cu: goto label_80130E2C;
    case 0x80130E30u: goto label_80130E30;
    case 0x80130E34u: goto label_80130E34;
    case 0x80130E38u: goto label_80130E38;
    case 0x80130E3Cu: goto label_80130E3C;
    case 0x80130E40u: goto label_80130E40;
    case 0x80130E44u: goto label_80130E44;
    case 0x80130E48u: goto label_80130E48;
    case 0x80130E4Cu: goto label_80130E4C;
    case 0x80130E50u: goto label_80130E50;
    case 0x80130E54u: goto label_80130E54;
    case 0x80130E58u: goto label_80130E58;
    case 0x80130E5Cu: goto label_80130E5C;
    case 0x80130E60u: goto label_80130E60;
    case 0x80130E64u: goto label_80130E64;
    case 0x80130E68u: goto label_80130E68;
    case 0x80130E6Cu: goto label_80130E6C;
    case 0x80130E70u: goto label_80130E70;
    case 0x80130E74u: goto label_80130E74;
    case 0x80130E78u: goto label_80130E78;
    case 0x80130E7Cu: goto label_80130E7C;
    case 0x80130E80u: goto label_80130E80;
    case 0x80130E84u: goto label_80130E84;
    case 0x80130E88u: goto label_80130E88;
    case 0x80130E8Cu: goto label_80130E8C;
    case 0x80130E90u: goto label_80130E90;
    case 0x80130E94u: goto label_80130E94;
    case 0x80130E98u: goto label_80130E98;
    case 0x80130E9Cu: goto label_80130E9C;
    case 0x80130EA0u: goto label_80130EA0;
    case 0x80130EA4u: goto label_80130EA4;
    case 0x80130EA8u: goto label_80130EA8;
    case 0x80130EACu: goto label_80130EAC;
    case 0x80130EB0u: goto label_80130EB0;
    case 0x80130EB4u: goto label_80130EB4;
    case 0x80130EB8u: goto label_80130EB8;
    case 0x80130EBCu: goto label_80130EBC;
    case 0x80130EC0u: goto label_80130EC0;
    case 0x80130EC4u: goto label_80130EC4;
    case 0x80130EC8u: goto label_80130EC8;
    case 0x80130ECCu: goto label_80130ECC;
    case 0x80130ED0u: goto label_80130ED0;
    case 0x80130ED4u: goto label_80130ED4;
    case 0x80130ED8u: goto label_80130ED8;
    case 0x80130EDCu: goto label_80130EDC;
    case 0x80130EE0u: goto label_80130EE0;
    case 0x80130EE4u: goto label_80130EE4;
    case 0x80130EE8u: goto label_80130EE8;
    case 0x80130EECu: goto label_80130EEC;
    case 0x80130EF0u: goto label_80130EF0;
    case 0x80130EF4u: goto label_80130EF4;
    case 0x80130EF8u: goto label_80130EF8;
    case 0x80130EFCu: goto label_80130EFC;
    case 0x80130F00u: goto label_80130F00;
    case 0x80130F04u: goto label_80130F04;
    case 0x80130F08u: goto label_80130F08;
    case 0x80130F0Cu: goto label_80130F0C;
    case 0x80130F10u: goto label_80130F10;
    case 0x80130F14u: goto label_80130F14;
    case 0x80130F18u: goto label_80130F18;
    case 0x80130F1Cu: goto label_80130F1C;
    case 0x80130F20u: goto label_80130F20;
    case 0x80130F24u: goto label_80130F24;
    case 0x80130F28u: goto label_80130F28;
    case 0x80130F2Cu: goto label_80130F2C;
    case 0x80130F30u: goto label_80130F30;
    case 0x80130F34u: goto label_80130F34;
    case 0x80130F38u: goto label_80130F38;
    case 0x80130F3Cu: goto label_80130F3C;
    case 0x80130F40u: goto label_80130F40;
    case 0x80130F44u: goto label_80130F44;
    case 0x80130F48u: goto label_80130F48;
    case 0x80130F4Cu: goto label_80130F4C;
    case 0x80130F50u: goto label_80130F50;
    case 0x80130F54u: goto label_80130F54;
    case 0x80130F58u: goto label_80130F58;
    case 0x80130F5Cu: goto label_80130F5C;
    case 0x80130F60u: goto label_80130F60;
    case 0x80130F64u: goto label_80130F64;
    case 0x80130F68u: goto label_80130F68;
    case 0x80130F6Cu: goto label_80130F6C;
    case 0x80130F70u: goto label_80130F70;
    case 0x80130F74u: goto label_80130F74;
    case 0x80130F78u: goto label_80130F78;
    case 0x80130F7Cu: goto label_80130F7C;
    case 0x80130F80u: goto label_80130F80;
    case 0x80130F84u: goto label_80130F84;
    case 0x80130F88u: goto label_80130F88;
    case 0x80130F8Cu: goto label_80130F8C;
    case 0x80130F90u: goto label_80130F90;
    case 0x80130F94u: goto label_80130F94;
    case 0x80130F98u: goto label_80130F98;
    case 0x80130F9Cu: goto label_80130F9C;
    case 0x80130FA0u: goto label_80130FA0;
    case 0x80130FA4u: goto label_80130FA4;
    case 0x80130FA8u: goto label_80130FA8;
    case 0x80130FACu: goto label_80130FAC;
    case 0x80130FB0u: goto label_80130FB0;
    case 0x80130FB4u: goto label_80130FB4;
    case 0x80130FB8u: goto label_80130FB8;
    case 0x80130FBCu: goto label_80130FBC;
    case 0x80130FC0u: goto label_80130FC0;
    case 0x80130FC4u: goto label_80130FC4;
    case 0x80130FC8u: goto label_80130FC8;
    case 0x80130FCCu: goto label_80130FCC;
    case 0x80130FD0u: goto label_80130FD0;
    case 0x80130FD4u: goto label_80130FD4;
    case 0x80130FD8u: goto label_80130FD8;
    case 0x80130FDCu: goto label_80130FDC;
    case 0x80130FE0u: goto label_80130FE0;
    case 0x80130FE4u: goto label_80130FE4;
    case 0x80130FE8u: goto label_80130FE8;
    case 0x80130FECu: goto label_80130FEC;
    case 0x80130FF0u: goto label_80130FF0;
    case 0x80130FF4u: goto label_80130FF4;
    case 0x80130FF8u: goto label_80130FF8;
    case 0x80130FFCu: goto label_80130FFC;
    case 0x80131000u: goto label_80131000;
    case 0x80131004u: goto label_80131004;
    case 0x80131008u: goto label_80131008;
    case 0x8013100Cu: goto label_8013100C;
    case 0x80131010u: goto label_80131010;
    case 0x80131014u: goto label_80131014;
    case 0x80131018u: goto label_80131018;
    case 0x8013101Cu: goto label_8013101C;
    case 0x80131020u: goto label_80131020;
    case 0x80131024u: goto label_80131024;
    case 0x80131028u: goto label_80131028;
    case 0x8013102Cu: goto label_8013102C;
    case 0x80131030u: goto label_80131030;
    case 0x80131034u: goto label_80131034;
    case 0x80131038u: goto label_80131038;
    case 0x8013103Cu: goto label_8013103C;
    case 0x80131040u: goto label_80131040;
    case 0x80131044u: goto label_80131044;
    case 0x80131048u: goto label_80131048;
    case 0x8013104Cu: goto label_8013104C;
    case 0x80131050u: goto label_80131050;
    case 0x80131054u: goto label_80131054;
    case 0x80131058u: goto label_80131058;
    case 0x8013105Cu: goto label_8013105C;
    case 0x80131060u: goto label_80131060;
    case 0x80131064u: goto label_80131064;
    case 0x80131068u: goto label_80131068;
    case 0x8013106Cu: goto label_8013106C;
    case 0x80131070u: goto label_80131070;
    case 0x80131074u: goto label_80131074;
    case 0x80131078u: goto label_80131078;
    case 0x8013107Cu: goto label_8013107C;
    case 0x80131080u: goto label_80131080;
    case 0x80131084u: goto label_80131084;
    case 0x80131088u: goto label_80131088;
    case 0x8013108Cu: goto label_8013108C;
    case 0x80131090u: goto label_80131090;
    case 0x80131094u: goto label_80131094;
    case 0x80131098u: goto label_80131098;
    case 0x8013109Cu: goto label_8013109C;
    case 0x801310A0u: goto label_801310A0;
    case 0x801310A4u: goto label_801310A4;
    case 0x801310A8u: goto label_801310A8;
    case 0x801310ACu: goto label_801310AC;
    case 0x801310B0u: goto label_801310B0;
    case 0x801310B4u: goto label_801310B4;
    case 0x801310B8u: goto label_801310B8;
    case 0x801310BCu: goto label_801310BC;
    case 0x801310C0u: goto label_801310C0;
    case 0x801310C4u: goto label_801310C4;
    case 0x801310C8u: goto label_801310C8;
    case 0x801310CCu: goto label_801310CC;
    case 0x801310D0u: goto label_801310D0;
    case 0x801310D4u: goto label_801310D4;
    case 0x801310D8u: goto label_801310D8;
    case 0x801310DCu: goto label_801310DC;
    case 0x801310E0u: goto label_801310E0;
    case 0x801310E4u: goto label_801310E4;
    case 0x801310E8u: goto label_801310E8;
    case 0x801310ECu: goto label_801310EC;
    case 0x801310F0u: goto label_801310F0;
    case 0x801310F4u: goto label_801310F4;
    case 0x801310F8u: goto label_801310F8;
    case 0x801310FCu: goto label_801310FC;
    case 0x80131100u: goto label_80131100;
    case 0x80131104u: goto label_80131104;
    case 0x80131108u: goto label_80131108;
    case 0x8013110Cu: goto label_8013110C;
    case 0x80131110u: goto label_80131110;
    case 0x80131114u: goto label_80131114;
    case 0x80131118u: goto label_80131118;
    case 0x8013111Cu: goto label_8013111C;
    case 0x80131120u: goto label_80131120;
    case 0x80131124u: goto label_80131124;
    case 0x80131128u: goto label_80131128;
    case 0x8013112Cu: goto label_8013112C;
    case 0x80131130u: goto label_80131130;
    case 0x80131134u: goto label_80131134;
    case 0x80131138u: goto label_80131138;
    case 0x8013113Cu: goto label_8013113C;
    case 0x80131140u: goto label_80131140;
    case 0x80131144u: goto label_80131144;
    case 0x80131148u: goto label_80131148;
    case 0x8013114Cu: goto label_8013114C;
    case 0x80131150u: goto label_80131150;
    case 0x80131154u: goto label_80131154;
    case 0x80131158u: goto label_80131158;
    case 0x8013115Cu: goto label_8013115C;
    case 0x80131160u: goto label_80131160;
    case 0x80131164u: goto label_80131164;
    case 0x80131168u: goto label_80131168;
    case 0x8013116Cu: goto label_8013116C;
    case 0x80131170u: goto label_80131170;
    case 0x80131174u: goto label_80131174;
    case 0x80131178u: goto label_80131178;
    case 0x8013117Cu: goto label_8013117C;
    case 0x80131180u: goto label_80131180;
    case 0x80131184u: goto label_80131184;
    case 0x80131188u: goto label_80131188;
    case 0x8013118Cu: goto label_8013118C;
    case 0x80131190u: goto label_80131190;
    case 0x80131194u: goto label_80131194;
    case 0x80131198u: goto label_80131198;
    case 0x8013119Cu: goto label_8013119C;
    case 0x801311A0u: goto label_801311A0;
    case 0x801311A4u: goto label_801311A4;
    case 0x801311A8u: goto label_801311A8;
    case 0x801311ACu: goto label_801311AC;
    case 0x801311B0u: goto label_801311B0;
    case 0x801311B4u: goto label_801311B4;
    case 0x801311B8u: goto label_801311B8;
    case 0x801311BCu: goto label_801311BC;
    case 0x801311C0u: goto label_801311C0;
    case 0x801311C4u: goto label_801311C4;
    case 0x801311C8u: goto label_801311C8;
    case 0x801311CCu: goto label_801311CC;
    case 0x801311D0u: goto label_801311D0;
    case 0x801311D4u: goto label_801311D4;
    case 0x801311D8u: goto label_801311D8;
    case 0x801311DCu: goto label_801311DC;
    case 0x801311E0u: goto label_801311E0;
    case 0x801311E4u: goto label_801311E4;
    case 0x801311E8u: goto label_801311E8;
    case 0x801311ECu: goto label_801311EC;
    case 0x801311F0u: goto label_801311F0;
    case 0x801311F4u: goto label_801311F4;
    case 0x801311F8u: goto label_801311F8;
    case 0x801311FCu: goto label_801311FC;
    case 0x80131200u: goto label_80131200;
    case 0x80131204u: goto label_80131204;
    case 0x80131208u: goto label_80131208;
    case 0x8013120Cu: goto label_8013120C;
    case 0x80131210u: goto label_80131210;
    case 0x80131214u: goto label_80131214;
    case 0x80131218u: goto label_80131218;
    case 0x8013121Cu: goto label_8013121C;
    case 0x80131220u: goto label_80131220;
    case 0x80131224u: goto label_80131224;
    case 0x80131228u: goto label_80131228;
    case 0x8013122Cu: goto label_8013122C;
    case 0x80131230u: goto label_80131230;
    case 0x80131234u: goto label_80131234;
    case 0x80131238u: goto label_80131238;
    case 0x8013123Cu: goto label_8013123C;
    case 0x80131240u: goto label_80131240;
    case 0x80131244u: goto label_80131244;
    case 0x80131248u: goto label_80131248;
    case 0x8013124Cu: goto label_8013124C;
    case 0x80131250u: goto label_80131250;
    case 0x80131254u: goto label_80131254;
    case 0x80131258u: goto label_80131258;
    case 0x8013125Cu: goto label_8013125C;
    case 0x80131260u: goto label_80131260;
    case 0x80131264u: goto label_80131264;
    case 0x80131268u: goto label_80131268;
    case 0x8013126Cu: goto label_8013126C;
    case 0x80131270u: goto label_80131270;
    case 0x80131274u: goto label_80131274;
    case 0x80131278u: goto label_80131278;
    case 0x8013127Cu: goto label_8013127C;
    case 0x80131280u: goto label_80131280;
    case 0x80131284u: goto label_80131284;
    case 0x80131288u: goto label_80131288;
    case 0x8013128Cu: goto label_8013128C;
    case 0x80131290u: goto label_80131290;
    case 0x80131294u: goto label_80131294;
    case 0x80131298u: goto label_80131298;
    case 0x8013129Cu: goto label_8013129C;
    case 0x801312A0u: goto label_801312A0;
    case 0x801312A4u: goto label_801312A4;
    case 0x801312A8u: goto label_801312A8;
    case 0x801312ACu: goto label_801312AC;
    case 0x801312B0u: goto label_801312B0;
    case 0x801312B4u: goto label_801312B4;
    case 0x801312B8u: goto label_801312B8;
    case 0x801312BCu: goto label_801312BC;
    case 0x801312C0u: goto label_801312C0;
    case 0x801312C4u: goto label_801312C4;
    case 0x801312C8u: goto label_801312C8;
    case 0x801312CCu: goto label_801312CC;
    case 0x801312D0u: goto label_801312D0;
    case 0x801312D4u: goto label_801312D4;
    case 0x801312D8u: goto label_801312D8;
    case 0x801312DCu: goto label_801312DC;
    case 0x801312E0u: goto label_801312E0;
    case 0x801312E4u: goto label_801312E4;
    case 0x801312E8u: goto label_801312E8;
    case 0x801312ECu: goto label_801312EC;
    case 0x801312F0u: goto label_801312F0;
    case 0x801312F4u: goto label_801312F4;
    case 0x801312F8u: goto label_801312F8;
    case 0x801312FCu: goto label_801312FC;
    case 0x80131300u: goto label_80131300;
    case 0x80131304u: goto label_80131304;
    case 0x80131308u: goto label_80131308;
    case 0x8013130Cu: goto label_8013130C;
    case 0x80131310u: goto label_80131310;
    case 0x80131314u: goto label_80131314;
    case 0x80131318u: goto label_80131318;
    case 0x8013131Cu: goto label_8013131C;
    case 0x80131320u: goto label_80131320;
    case 0x80131324u: goto label_80131324;
    case 0x80131328u: goto label_80131328;
    case 0x8013132Cu: goto label_8013132C;
    case 0x80131330u: goto label_80131330;
    case 0x80131334u: goto label_80131334;
    case 0x80131338u: goto label_80131338;
    case 0x8013133Cu: goto label_8013133C;
    case 0x80131340u: goto label_80131340;
    case 0x80131344u: goto label_80131344;
    case 0x80131348u: goto label_80131348;
    case 0x8013134Cu: goto label_8013134C;
    case 0x80131350u: goto label_80131350;
    case 0x80131354u: goto label_80131354;
    case 0x80131358u: goto label_80131358;
    case 0x8013135Cu: goto label_8013135C;
    case 0x80131360u: goto label_80131360;
    case 0x80131364u: goto label_80131364;
    case 0x80131368u: goto label_80131368;
    case 0x8013136Cu: goto label_8013136C;
    case 0x80131370u: goto label_80131370;
    case 0x80131374u: goto label_80131374;
    case 0x80131378u: goto label_80131378;
    case 0x8013137Cu: goto label_8013137C;
    case 0x80131380u: goto label_80131380;
    case 0x80131384u: goto label_80131384;
    case 0x80131388u: goto label_80131388;
    case 0x8013138Cu: goto label_8013138C;
    case 0x80131390u: goto label_80131390;
    case 0x80131394u: goto label_80131394;
    case 0x80131398u: goto label_80131398;
    case 0x8013139Cu: goto label_8013139C;
    case 0x801313A0u: goto label_801313A0;
    case 0x801313A4u: goto label_801313A4;
    case 0x801313A8u: goto label_801313A8;
    case 0x801313ACu: goto label_801313AC;
    case 0x801313B0u: goto label_801313B0;
    case 0x801313B4u: goto label_801313B4;
    case 0x801313B8u: goto label_801313B8;
    case 0x801313BCu: goto label_801313BC;
    case 0x801313C0u: goto label_801313C0;
    case 0x801313C4u: goto label_801313C4;
    case 0x801313C8u: goto label_801313C8;
    case 0x801313CCu: goto label_801313CC;
    case 0x801313D0u: goto label_801313D0;
    case 0x801313D4u: goto label_801313D4;
    case 0x801313D8u: goto label_801313D8;
    case 0x801313DCu: goto label_801313DC;
    case 0x801313E0u: goto label_801313E0;
    case 0x801313E4u: goto label_801313E4;
    case 0x801313E8u: goto label_801313E8;
    case 0x801313ECu: goto label_801313EC;
    case 0x801313F0u: goto label_801313F0;
    case 0x801313F4u: goto label_801313F4;
    case 0x801313F8u: goto label_801313F8;
    case 0x801313FCu: goto label_801313FC;
    case 0x80131400u: goto label_80131400;
    case 0x80131404u: goto label_80131404;
    case 0x80131408u: goto label_80131408;
    case 0x8013140Cu: goto label_8013140C;
    case 0x80131410u: goto label_80131410;
    case 0x80131414u: goto label_80131414;
    case 0x80131418u: goto label_80131418;
    case 0x8013141Cu: goto label_8013141C;
    case 0x80131420u: goto label_80131420;
    case 0x80131424u: goto label_80131424;
    case 0x80131428u: goto label_80131428;
    case 0x8013142Cu: goto label_8013142C;
    case 0x80131430u: goto label_80131430;
    case 0x80131434u: goto label_80131434;
    case 0x80131438u: goto label_80131438;
    case 0x8013143Cu: goto label_8013143C;
    case 0x80131440u: goto label_80131440;
    case 0x80131444u: goto label_80131444;
    case 0x80131448u: goto label_80131448;
    case 0x8013144Cu: goto label_8013144C;
    case 0x80131450u: goto label_80131450;
    case 0x80131454u: goto label_80131454;
    case 0x80131458u: goto label_80131458;
    case 0x8013145Cu: goto label_8013145C;
    case 0x80131460u: goto label_80131460;
    case 0x80131464u: goto label_80131464;
    case 0x80131468u: goto label_80131468;
    case 0x8013146Cu: goto label_8013146C;
    case 0x80131470u: goto label_80131470;
    case 0x80131474u: goto label_80131474;
    case 0x80131478u: goto label_80131478;
    case 0x8013147Cu: goto label_8013147C;
    case 0x80131480u: goto label_80131480;
    case 0x80131484u: goto label_80131484;
    case 0x80131488u: goto label_80131488;
    case 0x8013148Cu: goto label_8013148C;
    case 0x80131490u: goto label_80131490;
    case 0x80131494u: goto label_80131494;
    case 0x80131498u: goto label_80131498;
    case 0x8013149Cu: goto label_8013149C;
    case 0x801314A0u: goto label_801314A0;
    case 0x801314A4u: goto label_801314A4;
    case 0x801314A8u: goto label_801314A8;
    case 0x801314ACu: goto label_801314AC;
    case 0x801314B0u: goto label_801314B0;
    case 0x801314B4u: goto label_801314B4;
    case 0x801314B8u: goto label_801314B8;
    case 0x801314BCu: goto label_801314BC;
    case 0x801314C0u: goto label_801314C0;
    case 0x801314C4u: goto label_801314C4;
    case 0x801314C8u: goto label_801314C8;
    case 0x801314CCu: goto label_801314CC;
    case 0x801314D0u: goto label_801314D0;
    case 0x801314D4u: goto label_801314D4;
    case 0x801314D8u: goto label_801314D8;
    case 0x801314DCu: goto label_801314DC;
    case 0x801314E0u: goto label_801314E0;
    case 0x801314E4u: goto label_801314E4;
    case 0x801314E8u: goto label_801314E8;
    case 0x801314ECu: goto label_801314EC;
    case 0x801314F0u: goto label_801314F0;
    case 0x801314F4u: goto label_801314F4;
    case 0x801314F8u: goto label_801314F8;
    case 0x801314FCu: goto label_801314FC;
    case 0x80131500u: goto label_80131500;
    case 0x80131504u: goto label_80131504;
    case 0x80131508u: goto label_80131508;
    case 0x8013150Cu: goto label_8013150C;
    case 0x80131510u: goto label_80131510;
    case 0x80131514u: goto label_80131514;
    case 0x80131518u: goto label_80131518;
    case 0x8013151Cu: goto label_8013151C;
    case 0x80131520u: goto label_80131520;
    case 0x80131524u: goto label_80131524;
    case 0x80131528u: goto label_80131528;
    case 0x8013152Cu: goto label_8013152C;
    case 0x80131530u: goto label_80131530;
    case 0x80131534u: goto label_80131534;
    case 0x80131538u: goto label_80131538;
    case 0x8013153Cu: goto label_8013153C;
    case 0x80131540u: goto label_80131540;
    case 0x80131544u: goto label_80131544;
    case 0x80131548u: goto label_80131548;
    case 0x8013154Cu: goto label_8013154C;
    case 0x80131550u: goto label_80131550;
    case 0x80131554u: goto label_80131554;
    case 0x80131558u: goto label_80131558;
    case 0x8013155Cu: goto label_8013155C;
    case 0x80131560u: goto label_80131560;
    case 0x80131564u: goto label_80131564;
    case 0x80131568u: goto label_80131568;
    case 0x8013156Cu: goto label_8013156C;
    case 0x80131570u: goto label_80131570;
    case 0x80131574u: goto label_80131574;
    case 0x80131578u: goto label_80131578;
    case 0x8013157Cu: goto label_8013157C;
    case 0x80131580u: goto label_80131580;
    case 0x80131584u: goto label_80131584;
    case 0x80131588u: goto label_80131588;
    case 0x8013158Cu: goto label_8013158C;
    case 0x80131590u: goto label_80131590;
    case 0x80131594u: goto label_80131594;
    case 0x80131598u: goto label_80131598;
    case 0x8013159Cu: goto label_8013159C;
    case 0x801315A0u: goto label_801315A0;
    case 0x801315A4u: goto label_801315A4;
    case 0x801315A8u: goto label_801315A8;
    case 0x801315ACu: goto label_801315AC;
    case 0x801315B0u: goto label_801315B0;
    case 0x801315B4u: goto label_801315B4;
    case 0x801315B8u: goto label_801315B8;
    case 0x801315BCu: goto label_801315BC;
    case 0x801315C0u: goto label_801315C0;
    case 0x801315C4u: goto label_801315C4;
    case 0x801315C8u: goto label_801315C8;
    case 0x801315CCu: goto label_801315CC;
    case 0x801315D0u: goto label_801315D0;
    case 0x801315D4u: goto label_801315D4;
    case 0x801315D8u: goto label_801315D8;
    case 0x801315DCu: goto label_801315DC;
    case 0x801315E0u: goto label_801315E0;
    case 0x801315E4u: goto label_801315E4;
    case 0x801315E8u: goto label_801315E8;
    case 0x801315ECu: goto label_801315EC;
    case 0x801315F0u: goto label_801315F0;
    case 0x801315F4u: goto label_801315F4;
    case 0x801315F8u: goto label_801315F8;
    case 0x801315FCu: goto label_801315FC;
    case 0x80131600u: goto label_80131600;
    case 0x80131604u: goto label_80131604;
    case 0x80131608u: goto label_80131608;
    case 0x8013160Cu: goto label_8013160C;
    case 0x80131610u: goto label_80131610;
    case 0x80131614u: goto label_80131614;
    case 0x80131618u: goto label_80131618;
    case 0x8013161Cu: goto label_8013161C;
    case 0x80131620u: goto label_80131620;
    case 0x80131624u: goto label_80131624;
    case 0x80131628u: goto label_80131628;
    case 0x8013162Cu: goto label_8013162C;
    case 0x80131630u: goto label_80131630;
    case 0x80131634u: goto label_80131634;
    case 0x80131638u: goto label_80131638;
    case 0x8013163Cu: goto label_8013163C;
    case 0x80131640u: goto label_80131640;
    case 0x80131644u: goto label_80131644;
    case 0x80131648u: goto label_80131648;
    case 0x8013164Cu: goto label_8013164C;
    case 0x80131650u: goto label_80131650;
    case 0x80131654u: goto label_80131654;
    case 0x80131658u: goto label_80131658;
    case 0x8013165Cu: goto label_8013165C;
    case 0x80131660u: goto label_80131660;
    case 0x80131664u: goto label_80131664;
    case 0x80131668u: goto label_80131668;
    case 0x8013166Cu: goto label_8013166C;
    case 0x80131670u: goto label_80131670;
    case 0x80131674u: goto label_80131674;
    case 0x80131678u: goto label_80131678;
    case 0x8013167Cu: goto label_8013167C;
    case 0x80131680u: goto label_80131680;
    case 0x80131684u: goto label_80131684;
    case 0x80131688u: goto label_80131688;
    case 0x8013168Cu: goto label_8013168C;
    case 0x80131690u: goto label_80131690;
    case 0x80131694u: goto label_80131694;
    case 0x80131698u: goto label_80131698;
    case 0x8013169Cu: goto label_8013169C;
    case 0x801316A0u: goto label_801316A0;
    case 0x801316A4u: goto label_801316A4;
    case 0x801316A8u: goto label_801316A8;
    case 0x801316ACu: goto label_801316AC;
    case 0x801316B0u: goto label_801316B0;
    case 0x801316B4u: goto label_801316B4;
    case 0x801316B8u: goto label_801316B8;
    case 0x801316BCu: goto label_801316BC;
    case 0x801316C0u: goto label_801316C0;
    case 0x801316C4u: goto label_801316C4;
    case 0x801316C8u: goto label_801316C8;
    case 0x801316CCu: goto label_801316CC;
    case 0x801316D0u: goto label_801316D0;
    case 0x801316D4u: goto label_801316D4;
    case 0x801316D8u: goto label_801316D8;
    case 0x801316DCu: goto label_801316DC;
    case 0x801316E0u: goto label_801316E0;
    case 0x801316E4u: goto label_801316E4;
    case 0x801316E8u: goto label_801316E8;
    case 0x801316ECu: goto label_801316EC;
    case 0x801316F0u: goto label_801316F0;
    case 0x801316F4u: goto label_801316F4;
    case 0x801316F8u: goto label_801316F8;
    case 0x801316FCu: goto label_801316FC;
    case 0x80131700u: goto label_80131700;
    case 0x80131704u: goto label_80131704;
    case 0x80131708u: goto label_80131708;
    case 0x8013170Cu: goto label_8013170C;
    case 0x80131710u: goto label_80131710;
    case 0x80131714u: goto label_80131714;
    case 0x80131718u: goto label_80131718;
    case 0x8013171Cu: goto label_8013171C;
    case 0x80131720u: goto label_80131720;
    case 0x80131724u: goto label_80131724;
    case 0x80131728u: goto label_80131728;
    case 0x8013172Cu: goto label_8013172C;
    case 0x80131730u: goto label_80131730;
    case 0x80131734u: goto label_80131734;
    case 0x80131738u: goto label_80131738;
    case 0x8013173Cu: goto label_8013173C;
    case 0x80131740u: goto label_80131740;
    case 0x80131744u: goto label_80131744;
    case 0x80131748u: goto label_80131748;
    case 0x8013174Cu: goto label_8013174C;
    case 0x80131750u: goto label_80131750;
    case 0x80131754u: goto label_80131754;
    case 0x80131758u: goto label_80131758;
    case 0x8013175Cu: goto label_8013175C;
    case 0x80131760u: goto label_80131760;
    case 0x80131764u: goto label_80131764;
    case 0x80131768u: goto label_80131768;
    case 0x8013176Cu: goto label_8013176C;
    case 0x80131770u: goto label_80131770;
    case 0x80131774u: goto label_80131774;
    case 0x80131778u: goto label_80131778;
    case 0x8013177Cu: goto label_8013177C;
    case 0x80131780u: goto label_80131780;
    case 0x80131784u: goto label_80131784;
    case 0x80131788u: goto label_80131788;
    case 0x8013178Cu: goto label_8013178C;
    case 0x80131790u: goto label_80131790;
    case 0x80131794u: goto label_80131794;
    case 0x80131798u: goto label_80131798;
    case 0x8013179Cu: goto label_8013179C;
    case 0x801317A0u: goto label_801317A0;
    case 0x801317A4u: goto label_801317A4;
    case 0x801317A8u: goto label_801317A8;
    case 0x801317ACu: goto label_801317AC;
    case 0x801317B0u: goto label_801317B0;
    case 0x801317B4u: goto label_801317B4;
    case 0x801317B8u: goto label_801317B8;
    case 0x801317BCu: goto label_801317BC;
    case 0x801317C0u: goto label_801317C0;
    case 0x801317C4u: goto label_801317C4;
    case 0x801317C8u: goto label_801317C8;
    case 0x801317CCu: goto label_801317CC;
    case 0x801317D0u: goto label_801317D0;
    case 0x801317D4u: goto label_801317D4;
    case 0x801317D8u: goto label_801317D8;
    case 0x801317DCu: goto label_801317DC;
    case 0x801317E0u: goto label_801317E0;
    case 0x801317E4u: goto label_801317E4;
    case 0x801317E8u: goto label_801317E8;
    case 0x801317ECu: goto label_801317EC;
    case 0x801317F0u: goto label_801317F0;
    case 0x801317F4u: goto label_801317F4;
    case 0x801317F8u: goto label_801317F8;
    case 0x801317FCu: goto label_801317FC;
    case 0x80131800u: goto label_80131800;
    case 0x80131804u: goto label_80131804;
    case 0x80131808u: goto label_80131808;
    case 0x8013180Cu: goto label_8013180C;
    case 0x80131810u: goto label_80131810;
    case 0x80131814u: goto label_80131814;
    case 0x80131818u: goto label_80131818;
    case 0x8013181Cu: goto label_8013181C;
    case 0x80131820u: goto label_80131820;
    case 0x80131824u: goto label_80131824;
    case 0x80131828u: goto label_80131828;
    case 0x8013182Cu: goto label_8013182C;
    case 0x80131830u: goto label_80131830;
    case 0x80131834u: goto label_80131834;
    case 0x80131838u: goto label_80131838;
    case 0x8013183Cu: goto label_8013183C;
    case 0x80131840u: goto label_80131840;
    case 0x80131844u: goto label_80131844;
    case 0x80131848u: goto label_80131848;
    case 0x8013184Cu: goto label_8013184C;
    case 0x80131850u: goto label_80131850;
    case 0x80131854u: goto label_80131854;
    case 0x80131858u: goto label_80131858;
    case 0x8013185Cu: goto label_8013185C;
    case 0x80131860u: goto label_80131860;
    case 0x80131864u: goto label_80131864;
    case 0x80131868u: goto label_80131868;
    case 0x8013186Cu: goto label_8013186C;
    case 0x80131870u: goto label_80131870;
    case 0x80131874u: goto label_80131874;
    case 0x80131878u: goto label_80131878;
    case 0x8013187Cu: goto label_8013187C;
    case 0x80131880u: goto label_80131880;
    case 0x80131884u: goto label_80131884;
    case 0x80131888u: goto label_80131888;
    case 0x8013188Cu: goto label_8013188C;
    case 0x80131890u: goto label_80131890;
    case 0x80131894u: goto label_80131894;
    case 0x80131898u: goto label_80131898;
    case 0x8013189Cu: goto label_8013189C;
    case 0x801318A0u: goto label_801318A0;
    case 0x801318A4u: goto label_801318A4;
    case 0x801318A8u: goto label_801318A8;
    case 0x801318ACu: goto label_801318AC;
    case 0x801318B0u: goto label_801318B0;
    case 0x801318B4u: goto label_801318B4;
    case 0x801318B8u: goto label_801318B8;
    case 0x801318BCu: goto label_801318BC;
    case 0x801318C0u: goto label_801318C0;
    case 0x801318C4u: goto label_801318C4;
    case 0x801318C8u: goto label_801318C8;
    case 0x801318CCu: goto label_801318CC;
    case 0x801318D0u: goto label_801318D0;
    case 0x801318D4u: goto label_801318D4;
    case 0x801318D8u: goto label_801318D8;
    case 0x801318DCu: goto label_801318DC;
    case 0x801318E0u: goto label_801318E0;
    case 0x801318E4u: goto label_801318E4;
    case 0x801318E8u: goto label_801318E8;
    case 0x801318ECu: goto label_801318EC;
    case 0x801318F0u: goto label_801318F0;
    case 0x801318F4u: goto label_801318F4;
    case 0x801318F8u: goto label_801318F8;
    case 0x801318FCu: goto label_801318FC;
    case 0x80131900u: goto label_80131900;
    case 0x80131904u: goto label_80131904;
    case 0x80131908u: goto label_80131908;
    case 0x8013190Cu: goto label_8013190C;
    case 0x80131910u: goto label_80131910;
    case 0x80131914u: goto label_80131914;
    case 0x80131918u: goto label_80131918;
    case 0x8013191Cu: goto label_8013191C;
    case 0x80131920u: goto label_80131920;
    case 0x80131924u: goto label_80131924;
    case 0x80131928u: goto label_80131928;
    case 0x8013192Cu: goto label_8013192C;
    case 0x80131930u: goto label_80131930;
    case 0x80131934u: goto label_80131934;
    case 0x80131938u: goto label_80131938;
    case 0x8013193Cu: goto label_8013193C;
    case 0x80131940u: goto label_80131940;
    case 0x80131944u: goto label_80131944;
    case 0x80131948u: goto label_80131948;
    case 0x8013194Cu: goto label_8013194C;
    case 0x80131950u: goto label_80131950;
    case 0x80131954u: goto label_80131954;
    case 0x80131958u: goto label_80131958;
    case 0x8013195Cu: goto label_8013195C;
    case 0x80131960u: goto label_80131960;
    case 0x80131964u: goto label_80131964;
    case 0x80131968u: goto label_80131968;
    case 0x8013196Cu: goto label_8013196C;
    case 0x80131970u: goto label_80131970;
    case 0x80131974u: goto label_80131974;
    case 0x80131978u: goto label_80131978;
    case 0x8013197Cu: goto label_8013197C;
    case 0x80131980u: goto label_80131980;
    case 0x80131984u: goto label_80131984;
    case 0x80131988u: goto label_80131988;
    case 0x8013198Cu: goto label_8013198C;
    case 0x80131990u: goto label_80131990;
    case 0x80131994u: goto label_80131994;
    case 0x80131998u: goto label_80131998;
    case 0x8013199Cu: goto label_8013199C;
    case 0x801319A0u: goto label_801319A0;
    case 0x801319A4u: goto label_801319A4;
    case 0x801319A8u: goto label_801319A8;
    case 0x801319ACu: goto label_801319AC;
    case 0x801319B0u: goto label_801319B0;
    case 0x801319B4u: goto label_801319B4;
    case 0x801319B8u: goto label_801319B8;
    case 0x801319BCu: goto label_801319BC;
    case 0x801319C0u: goto label_801319C0;
    case 0x801319C4u: goto label_801319C4;
    case 0x801319C8u: goto label_801319C8;
    case 0x801319CCu: goto label_801319CC;
    case 0x801319D0u: goto label_801319D0;
    case 0x801319D4u: goto label_801319D4;
    case 0x801319D8u: goto label_801319D8;
    case 0x801319DCu: goto label_801319DC;
    case 0x801319E0u: goto label_801319E0;
    case 0x801319E4u: goto label_801319E4;
    case 0x801319E8u: goto label_801319E8;
    case 0x801319ECu: goto label_801319EC;
    case 0x801319F0u: goto label_801319F0;
    case 0x801319F4u: goto label_801319F4;
    case 0x801319F8u: goto label_801319F8;
    case 0x801319FCu: goto label_801319FC;
    case 0x80131A00u: goto label_80131A00;
    case 0x80131A04u: goto label_80131A04;
    case 0x80131A08u: goto label_80131A08;
    case 0x80131A0Cu: goto label_80131A0C;
    case 0x80131A10u: goto label_80131A10;
    case 0x80131A14u: goto label_80131A14;
    case 0x80131A18u: goto label_80131A18;
    case 0x80131A1Cu: goto label_80131A1C;
    case 0x80131A20u: goto label_80131A20;
    case 0x80131A24u: goto label_80131A24;
    case 0x80131A28u: goto label_80131A28;
    case 0x80131A2Cu: goto label_80131A2C;
    case 0x80131A30u: goto label_80131A30;
    case 0x80131A34u: goto label_80131A34;
    case 0x80131A38u: goto label_80131A38;
    case 0x80131A3Cu: goto label_80131A3C;
    case 0x80131A40u: goto label_80131A40;
    case 0x80131A44u: goto label_80131A44;
    case 0x80131A48u: goto label_80131A48;
    case 0x80131A4Cu: goto label_80131A4C;
    case 0x80131A50u: goto label_80131A50;
    case 0x80131A54u: goto label_80131A54;
    case 0x80131A58u: goto label_80131A58;
    case 0x80131A5Cu: goto label_80131A5C;
    case 0x80131A60u: goto label_80131A60;
    case 0x80131A64u: goto label_80131A64;
    case 0x80131A68u: goto label_80131A68;
    case 0x80131A6Cu: goto label_80131A6C;
    case 0x80131A70u: goto label_80131A70;
    case 0x80131A74u: goto label_80131A74;
    case 0x80131A78u: goto label_80131A78;
    case 0x80131A7Cu: goto label_80131A7C;
    case 0x80131A80u: goto label_80131A80;
    case 0x80131A84u: goto label_80131A84;
    case 0x80131A88u: goto label_80131A88;
    case 0x80131A8Cu: goto label_80131A8C;
    case 0x80131A90u: goto label_80131A90;
    case 0x80131A94u: goto label_80131A94;
    case 0x80131A98u: goto label_80131A98;
    case 0x80131A9Cu: goto label_80131A9C;
    case 0x80131AA0u: goto label_80131AA0;
    case 0x80131AA4u: goto label_80131AA4;
    case 0x80131AA8u: goto label_80131AA8;
    case 0x80131AACu: goto label_80131AAC;
    case 0x80131AB0u: goto label_80131AB0;
    case 0x80131AB4u: goto label_80131AB4;
    case 0x80131AB8u: goto label_80131AB8;
    case 0x80131ABCu: goto label_80131ABC;
    case 0x80131AC0u: goto label_80131AC0;
    case 0x80131AC4u: goto label_80131AC4;
    case 0x80131AC8u: goto label_80131AC8;
    case 0x80131ACCu: goto label_80131ACC;
    case 0x80131AD0u: goto label_80131AD0;
    case 0x80131AD4u: goto label_80131AD4;
    case 0x80131AD8u: goto label_80131AD8;
    case 0x80131ADCu: goto label_80131ADC;
    case 0x80131AE0u: goto label_80131AE0;
    case 0x80131AE4u: goto label_80131AE4;
    case 0x80131AE8u: goto label_80131AE8;
    case 0x80131AECu: goto label_80131AEC;
    case 0x80131AF0u: goto label_80131AF0;
    case 0x80131AF4u: goto label_80131AF4;
    case 0x80131AF8u: goto label_80131AF8;
    case 0x80131AFCu: goto label_80131AFC;
    case 0x80131B00u: goto label_80131B00;
    case 0x80131B04u: goto label_80131B04;
    case 0x80131B08u: goto label_80131B08;
    case 0x80131B0Cu: goto label_80131B0C;
    case 0x80131B10u: goto label_80131B10;
    case 0x80131B14u: goto label_80131B14;
    case 0x80131B18u: goto label_80131B18;
    case 0x80131B1Cu: goto label_80131B1C;
    case 0x80131B20u: goto label_80131B20;
    case 0x80131B24u: goto label_80131B24;
    case 0x80131B28u: goto label_80131B28;
    case 0x80131B2Cu: goto label_80131B2C;
    case 0x80131B30u: goto label_80131B30;
    case 0x80131B34u: goto label_80131B34;
    case 0x80131B38u: goto label_80131B38;
    case 0x80131B3Cu: goto label_80131B3C;
    case 0x80131B40u: goto label_80131B40;
    case 0x80131B44u: goto label_80131B44;
    case 0x80131B48u: goto label_80131B48;
    case 0x80131B4Cu: goto label_80131B4C;
    case 0x80131B50u: goto label_80131B50;
    case 0x80131B54u: goto label_80131B54;
    case 0x80131B58u: goto label_80131B58;
    case 0x80131B5Cu: goto label_80131B5C;
    case 0x80131B60u: goto label_80131B60;
    case 0x80131B64u: goto label_80131B64;
    case 0x80131B68u: goto label_80131B68;
    case 0x80131B6Cu: goto label_80131B6C;
    case 0x80131B70u: goto label_80131B70;
    case 0x80131B74u: goto label_80131B74;
    case 0x80131B78u: goto label_80131B78;
    case 0x80131B7Cu: goto label_80131B7C;
    case 0x80131B80u: goto label_80131B80;
    case 0x80131B84u: goto label_80131B84;
    case 0x80131B88u: goto label_80131B88;
    case 0x80131B8Cu: goto label_80131B8C;
    case 0x80131B90u: goto label_80131B90;
    case 0x80131B94u: goto label_80131B94;
    case 0x80131B98u: goto label_80131B98;
    case 0x80131B9Cu: goto label_80131B9C;
    case 0x80131BA0u: goto label_80131BA0;
    case 0x80131BA4u: goto label_80131BA4;
    case 0x80131BA8u: goto label_80131BA8;
    case 0x80131BACu: goto label_80131BAC;
    case 0x80131BB0u: goto label_80131BB0;
    case 0x80131BB4u: goto label_80131BB4;
    case 0x80131BB8u: goto label_80131BB8;
    case 0x80131BBCu: goto label_80131BBC;
    case 0x80131BC0u: goto label_80131BC0;
    case 0x80131BC4u: goto label_80131BC4;
    case 0x80131BC8u: goto label_80131BC8;
    case 0x80131BCCu: goto label_80131BCC;
    case 0x80131BD0u: goto label_80131BD0;
    case 0x80131BD4u: goto label_80131BD4;
    case 0x80131BD8u: goto label_80131BD8;
    case 0x80131BDCu: goto label_80131BDC;
    case 0x80131BE0u: goto label_80131BE0;
    case 0x80131BE4u: goto label_80131BE4;
    case 0x80131BE8u: goto label_80131BE8;
    case 0x80131BECu: goto label_80131BEC;
    case 0x80131BF0u: goto label_80131BF0;
    case 0x80131BF4u: goto label_80131BF4;
    case 0x80131BF8u: goto label_80131BF8;
    case 0x80131BFCu: goto label_80131BFC;
    case 0x80131C00u: goto label_80131C00;
    case 0x80131C04u: goto label_80131C04;
    case 0x80131C08u: goto label_80131C08;
    case 0x80131C0Cu: goto label_80131C0C;
    case 0x80131C10u: goto label_80131C10;
    case 0x80131C14u: goto label_80131C14;
    case 0x80131C18u: goto label_80131C18;
    case 0x80131C1Cu: goto label_80131C1C;
    case 0x80131C20u: goto label_80131C20;
    case 0x80131C24u: goto label_80131C24;
    case 0x80131C28u: goto label_80131C28;
    case 0x80131C2Cu: goto label_80131C2C;
    case 0x80131C30u: goto label_80131C30;
    case 0x80131C34u: goto label_80131C34;
    case 0x80131C38u: goto label_80131C38;
    case 0x80131C3Cu: goto label_80131C3C;
    case 0x80131C40u: goto label_80131C40;
    case 0x80131C44u: goto label_80131C44;
    case 0x80131C48u: goto label_80131C48;
    case 0x80131C4Cu: goto label_80131C4C;
    case 0x80131C50u: goto label_80131C50;
    case 0x80131C54u: goto label_80131C54;
    case 0x80131C58u: goto label_80131C58;
    case 0x80131C5Cu: goto label_80131C5C;
    case 0x80131C60u: goto label_80131C60;
    case 0x80131C64u: goto label_80131C64;
    case 0x80131C68u: goto label_80131C68;
    case 0x80131C6Cu: goto label_80131C6C;
    case 0x80131C70u: goto label_80131C70;
    case 0x80131C74u: goto label_80131C74;
    case 0x80131C78u: goto label_80131C78;
    case 0x80131C7Cu: goto label_80131C7C;
    case 0x80131C80u: goto label_80131C80;
    case 0x80131C84u: goto label_80131C84;
    case 0x80131C88u: goto label_80131C88;
    case 0x80131C8Cu: goto label_80131C8C;
    case 0x80131C90u: goto label_80131C90;
    case 0x80131C94u: goto label_80131C94;
    case 0x80131C98u: goto label_80131C98;
    case 0x80131C9Cu: goto label_80131C9C;
    case 0x80131CA0u: goto label_80131CA0;
    case 0x80131CA4u: goto label_80131CA4;
    case 0x80131CA8u: goto label_80131CA8;
    case 0x80131CACu: goto label_80131CAC;
    case 0x80131CB0u: goto label_80131CB0;
    case 0x80131CB4u: goto label_80131CB4;
    case 0x80131CB8u: goto label_80131CB8;
    case 0x80131CBCu: goto label_80131CBC;
    case 0x80131CC0u: goto label_80131CC0;
    case 0x80131CC4u: goto label_80131CC4;
    case 0x80131CC8u: goto label_80131CC8;
    case 0x80131CCCu: goto label_80131CCC;
    case 0x80131CD0u: goto label_80131CD0;
    case 0x80131CD4u: goto label_80131CD4;
    case 0x80131CD8u: goto label_80131CD8;
    case 0x80131CDCu: goto label_80131CDC;
    case 0x80131CE0u: goto label_80131CE0;
    case 0x80131CE4u: goto label_80131CE4;
    case 0x80131CE8u: goto label_80131CE8;
    case 0x80131CECu: goto label_80131CEC;
    case 0x80131CF0u: goto label_80131CF0;
    case 0x80131CF4u: goto label_80131CF4;
    case 0x80131CF8u: goto label_80131CF8;
    case 0x80131CFCu: goto label_80131CFC;
    case 0x80131D00u: goto label_80131D00;
    case 0x80131D04u: goto label_80131D04;
    case 0x80131D08u: goto label_80131D08;
    case 0x80131D0Cu: goto label_80131D0C;
    case 0x80131D10u: goto label_80131D10;
    case 0x80131D14u: goto label_80131D14;
    case 0x80131D18u: goto label_80131D18;
    case 0x80131D1Cu: goto label_80131D1C;
    case 0x80131D20u: goto label_80131D20;
    case 0x80131D24u: goto label_80131D24;
    case 0x80131D28u: goto label_80131D28;
    case 0x80131D2Cu: goto label_80131D2C;
    case 0x80131D30u: goto label_80131D30;
    case 0x80131D34u: goto label_80131D34;
    case 0x80131D38u: goto label_80131D38;
    case 0x80131D3Cu: goto label_80131D3C;
    case 0x80131D40u: goto label_80131D40;
    case 0x80131D44u: goto label_80131D44;
    case 0x80131D48u: goto label_80131D48;
    case 0x80131D4Cu: goto label_80131D4C;
    case 0x80131D50u: goto label_80131D50;
    case 0x80131D54u: goto label_80131D54;
    case 0x80131D58u: goto label_80131D58;
    case 0x80131D5Cu: goto label_80131D5C;
    case 0x80131D60u: goto label_80131D60;
    case 0x80131D64u: goto label_80131D64;
    case 0x80131D68u: goto label_80131D68;
    case 0x80131D6Cu: goto label_80131D6C;
    case 0x80131D70u: goto label_80131D70;
    case 0x80131D74u: goto label_80131D74;
    case 0x80131D78u: goto label_80131D78;
    case 0x80131D7Cu: goto label_80131D7C;
    case 0x80131D80u: goto label_80131D80;
    case 0x80131D84u: goto label_80131D84;
    case 0x80131D88u: goto label_80131D88;
    case 0x80131D8Cu: goto label_80131D8C;
    case 0x80131D90u: goto label_80131D90;
    case 0x80131D94u: goto label_80131D94;
    case 0x80131D98u: goto label_80131D98;
    case 0x80131D9Cu: goto label_80131D9C;
    case 0x80131DA0u: goto label_80131DA0;
    case 0x80131DA4u: goto label_80131DA4;
    case 0x80131DA8u: goto label_80131DA8;
    case 0x80131DACu: goto label_80131DAC;
    case 0x80131DB0u: goto label_80131DB0;
    case 0x80131DB4u: goto label_80131DB4;
    case 0x80131DB8u: goto label_80131DB8;
    case 0x80131DBCu: goto label_80131DBC;
    case 0x80131DC0u: goto label_80131DC0;
    case 0x80131DC4u: goto label_80131DC4;
    case 0x80131DC8u: goto label_80131DC8;
    case 0x80131DCCu: goto label_80131DCC;
    case 0x80131DD0u: goto label_80131DD0;
    case 0x80131DD4u: goto label_80131DD4;
    case 0x80131DD8u: goto label_80131DD8;
    case 0x80131DDCu: goto label_80131DDC;
    case 0x80131DE0u: goto label_80131DE0;
    case 0x80131DE4u: goto label_80131DE4;
    case 0x80131DE8u: goto label_80131DE8;
    case 0x80131DECu: goto label_80131DEC;
    case 0x80131DF0u: goto label_80131DF0;
    case 0x80131DF4u: goto label_80131DF4;
    case 0x80131DF8u: goto label_80131DF8;
    case 0x80131DFCu: goto label_80131DFC;
    case 0x80131E00u: goto label_80131E00;
    case 0x80131E04u: goto label_80131E04;
    case 0x80131E08u: goto label_80131E08;
    case 0x80131E0Cu: goto label_80131E0C;
    case 0x80131E10u: goto label_80131E10;
    case 0x80131E14u: goto label_80131E14;
    case 0x80131E18u: goto label_80131E18;
    case 0x80131E1Cu: goto label_80131E1C;
    case 0x80131E20u: goto label_80131E20;
    case 0x80131E24u: goto label_80131E24;
    case 0x80131E28u: goto label_80131E28;
    case 0x80131E2Cu: goto label_80131E2C;
    case 0x80131E30u: goto label_80131E30;
    case 0x80131E34u: goto label_80131E34;
    case 0x80131E38u: goto label_80131E38;
    case 0x80131E3Cu: goto label_80131E3C;
    case 0x80131E40u: goto label_80131E40;
    case 0x80131E44u: goto label_80131E44;
    case 0x80131E48u: goto label_80131E48;
    case 0x80131E4Cu: goto label_80131E4C;
    case 0x80131E50u: goto label_80131E50;
    case 0x80131E54u: goto label_80131E54;
    case 0x80131E58u: goto label_80131E58;
    case 0x80131E5Cu: goto label_80131E5C;
    case 0x80131E60u: goto label_80131E60;
    case 0x80131E64u: goto label_80131E64;
    case 0x80131E68u: goto label_80131E68;
    case 0x80131E6Cu: goto label_80131E6C;
    case 0x80131E70u: goto label_80131E70;
    case 0x80131E74u: goto label_80131E74;
    case 0x80131E78u: goto label_80131E78;
    case 0x80131E7Cu: goto label_80131E7C;
    case 0x80131E80u: goto label_80131E80;
    case 0x80131E84u: goto label_80131E84;
    case 0x80131E88u: goto label_80131E88;
    case 0x80131E8Cu: goto label_80131E8C;
    case 0x80131E90u: goto label_80131E90;
    case 0x80131E94u: goto label_80131E94;
    case 0x80131E98u: goto label_80131E98;
    case 0x80131E9Cu: goto label_80131E9C;
    case 0x80131EA0u: goto label_80131EA0;
    case 0x80131EA4u: goto label_80131EA4;
    case 0x80131EA8u: goto label_80131EA8;
    case 0x80131EACu: goto label_80131EAC;
    case 0x80131EB0u: goto label_80131EB0;
    case 0x80131EB4u: goto label_80131EB4;
    case 0x80131EB8u: goto label_80131EB8;
    case 0x80131EBCu: goto label_80131EBC;
    case 0x80131EC0u: goto label_80131EC0;
    case 0x80131EC4u: goto label_80131EC4;
    case 0x80131EC8u: goto label_80131EC8;
    case 0x80131ECCu: goto label_80131ECC;
    case 0x80131ED0u: goto label_80131ED0;
    case 0x80131ED4u: goto label_80131ED4;
    case 0x80131ED8u: goto label_80131ED8;
    case 0x80131EDCu: goto label_80131EDC;
    case 0x80131EE0u: goto label_80131EE0;
    case 0x80131EE4u: goto label_80131EE4;
    case 0x80131EE8u: goto label_80131EE8;
    case 0x80131EECu: goto label_80131EEC;
    case 0x80131EF0u: goto label_80131EF0;
    case 0x80131EF4u: goto label_80131EF4;
    case 0x80131EF8u: goto label_80131EF8;
    case 0x80131EFCu: goto label_80131EFC;
    case 0x80131F00u: goto label_80131F00;
    case 0x80131F04u: goto label_80131F04;
    case 0x80131F08u: goto label_80131F08;
    case 0x80131F0Cu: goto label_80131F0C;
    case 0x80131F10u: goto label_80131F10;
    case 0x80131F14u: goto label_80131F14;
    case 0x80131F18u: goto label_80131F18;
    case 0x80131F1Cu: goto label_80131F1C;
    case 0x80131F20u: goto label_80131F20;
    case 0x80131F24u: goto label_80131F24;
    case 0x80131F28u: goto label_80131F28;
    case 0x80131F2Cu: goto label_80131F2C;
    case 0x80131F30u: goto label_80131F30;
    case 0x80131F34u: goto label_80131F34;
    case 0x80131F38u: goto label_80131F38;
    case 0x80131F3Cu: goto label_80131F3C;
    case 0x80131F40u: goto label_80131F40;
    case 0x80131F44u: goto label_80131F44;
    case 0x80131F48u: goto label_80131F48;
    case 0x80131F4Cu: goto label_80131F4C;
    case 0x80131F50u: goto label_80131F50;
    case 0x80131F54u: goto label_80131F54;
    case 0x80131F58u: goto label_80131F58;
    case 0x80131F5Cu: goto label_80131F5C;
    case 0x80131F60u: goto label_80131F60;
    case 0x80131F64u: goto label_80131F64;
    case 0x80131F68u: goto label_80131F68;
    case 0x80131F6Cu: goto label_80131F6C;
    case 0x80131F70u: goto label_80131F70;
    case 0x80131F74u: goto label_80131F74;
    case 0x80131F78u: goto label_80131F78;
    case 0x80131F7Cu: goto label_80131F7C;
    case 0x80131F80u: goto label_80131F80;
    case 0x80131F84u: goto label_80131F84;
    case 0x80131F88u: goto label_80131F88;
    case 0x80131F8Cu: goto label_80131F8C;
    case 0x80131F90u: goto label_80131F90;
    case 0x80131F94u: goto label_80131F94;
    case 0x80131F98u: goto label_80131F98;
    case 0x80131F9Cu: goto label_80131F9C;
    case 0x80131FA0u: goto label_80131FA0;
    case 0x80131FA4u: goto label_80131FA4;
    case 0x80131FA8u: goto label_80131FA8;
    case 0x80131FACu: goto label_80131FAC;
    case 0x80131FB0u: goto label_80131FB0;
    case 0x80131FB4u: goto label_80131FB4;
    case 0x80131FB8u: goto label_80131FB8;
    case 0x80131FBCu: goto label_80131FBC;
    case 0x80131FC0u: goto label_80131FC0;
    case 0x80131FC4u: goto label_80131FC4;
    case 0x80131FC8u: goto label_80131FC8;
    case 0x80131FCCu: goto label_80131FCC;
    case 0x80131FD0u: goto label_80131FD0;
    case 0x80131FD4u: goto label_80131FD4;
    case 0x80131FD8u: goto label_80131FD8;
    case 0x80131FDCu: goto label_80131FDC;
    case 0x80131FE0u: goto label_80131FE0;
    case 0x80131FE4u: goto label_80131FE4;
    case 0x80131FE8u: goto label_80131FE8;
    case 0x80131FECu: goto label_80131FEC;
    case 0x80131FF0u: goto label_80131FF0;
    case 0x80131FF4u: goto label_80131FF4;
    case 0x80131FF8u: goto label_80131FF8;
    case 0x80131FFCu: goto label_80131FFC;
    case 0x80132000u: goto label_80132000;
    case 0x80132004u: goto label_80132004;
    case 0x80132008u: goto label_80132008;
    case 0x8013200Cu: goto label_8013200C;
    case 0x80132010u: goto label_80132010;
    case 0x80132014u: goto label_80132014;
    case 0x80132018u: goto label_80132018;
    case 0x8013201Cu: goto label_8013201C;
    case 0x80132020u: goto label_80132020;
    case 0x80132024u: goto label_80132024;
    case 0x80132028u: goto label_80132028;
    case 0x8013202Cu: goto label_8013202C;
    case 0x80132030u: goto label_80132030;
    case 0x80132034u: goto label_80132034;
    case 0x80132038u: goto label_80132038;
    case 0x8013203Cu: goto label_8013203C;
    case 0x80132040u: goto label_80132040;
    case 0x80132044u: goto label_80132044;
    case 0x80132048u: goto label_80132048;
    case 0x8013204Cu: goto label_8013204C;
    case 0x80132050u: goto label_80132050;
    case 0x80132054u: goto label_80132054;
    case 0x80132058u: goto label_80132058;
    case 0x8013205Cu: goto label_8013205C;
    case 0x80132060u: goto label_80132060;
    case 0x80132064u: goto label_80132064;
    case 0x80132068u: goto label_80132068;
    case 0x8013206Cu: goto label_8013206C;
    case 0x80132070u: goto label_80132070;
    case 0x80132074u: goto label_80132074;
    case 0x80132078u: goto label_80132078;
    case 0x8013207Cu: goto label_8013207C;
    case 0x80132080u: goto label_80132080;
    case 0x80132084u: goto label_80132084;
    case 0x80132088u: goto label_80132088;
    case 0x8013208Cu: goto label_8013208C;
    case 0x80132090u: goto label_80132090;
    case 0x80132094u: goto label_80132094;
    case 0x80132098u: goto label_80132098;
    case 0x8013209Cu: goto label_8013209C;
    case 0x801320A0u: goto label_801320A0;
    case 0x801320A4u: goto label_801320A4;
    case 0x801320A8u: goto label_801320A8;
    case 0x801320ACu: goto label_801320AC;
    case 0x801320B0u: goto label_801320B0;
    case 0x801320B4u: goto label_801320B4;
    case 0x801320B8u: goto label_801320B8;
    case 0x801320BCu: goto label_801320BC;
    case 0x801320C0u: goto label_801320C0;
    case 0x801320C4u: goto label_801320C4;
    case 0x801320C8u: goto label_801320C8;
    case 0x801320CCu: goto label_801320CC;
    case 0x801320D0u: goto label_801320D0;
    case 0x801320D4u: goto label_801320D4;
    case 0x801320D8u: goto label_801320D8;
    case 0x801320DCu: goto label_801320DC;
    case 0x801320E0u: goto label_801320E0;
    case 0x801320E4u: goto label_801320E4;
    case 0x801320E8u: goto label_801320E8;
    case 0x801320ECu: goto label_801320EC;
    case 0x801320F0u: goto label_801320F0;
    case 0x801320F4u: goto label_801320F4;
    case 0x801320F8u: goto label_801320F8;
    case 0x801320FCu: goto label_801320FC;
    case 0x80132100u: goto label_80132100;
    case 0x80132104u: goto label_80132104;
    case 0x80132108u: goto label_80132108;
    case 0x8013210Cu: goto label_8013210C;
    case 0x80132110u: goto label_80132110;
    case 0x80132114u: goto label_80132114;
    case 0x80132118u: goto label_80132118;
    case 0x8013211Cu: goto label_8013211C;
    case 0x80132120u: goto label_80132120;
    case 0x80132124u: goto label_80132124;
    case 0x80132128u: goto label_80132128;
    case 0x8013212Cu: goto label_8013212C;
    case 0x80132130u: goto label_80132130;
    case 0x80132134u: goto label_80132134;
    case 0x80132138u: goto label_80132138;
    case 0x8013213Cu: goto label_8013213C;
    case 0x80132140u: goto label_80132140;
    case 0x80132144u: goto label_80132144;
    case 0x80132148u: goto label_80132148;
    case 0x8013214Cu: goto label_8013214C;
    case 0x80132150u: goto label_80132150;
    case 0x80132154u: goto label_80132154;
    case 0x80132158u: goto label_80132158;
    case 0x8013215Cu: goto label_8013215C;
    case 0x80132160u: goto label_80132160;
    case 0x80132164u: goto label_80132164;
    case 0x80132168u: goto label_80132168;
    case 0x8013216Cu: goto label_8013216C;
    case 0x80132170u: goto label_80132170;
    case 0x80132174u: goto label_80132174;
    case 0x80132178u: goto label_80132178;
    case 0x8013217Cu: goto label_8013217C;
    case 0x80132180u: goto label_80132180;
    case 0x80132184u: goto label_80132184;
    case 0x80132188u: goto label_80132188;
    case 0x8013218Cu: goto label_8013218C;
    case 0x80132190u: goto label_80132190;
    case 0x80132194u: goto label_80132194;
    case 0x80132198u: goto label_80132198;
    case 0x8013219Cu: goto label_8013219C;
    case 0x801321A0u: goto label_801321A0;
    case 0x801321A4u: goto label_801321A4;
    case 0x801321A8u: goto label_801321A8;
    case 0x801321ACu: goto label_801321AC;
    case 0x801321B0u: goto label_801321B0;
    case 0x801321B4u: goto label_801321B4;
    case 0x801321B8u: goto label_801321B8;
    case 0x801321BCu: goto label_801321BC;
    case 0x801321C0u: goto label_801321C0;
    case 0x801321C4u: goto label_801321C4;
    case 0x801321C8u: goto label_801321C8;
    case 0x801321CCu: goto label_801321CC;
    case 0x801321D0u: goto label_801321D0;
    case 0x801321D4u: goto label_801321D4;
    case 0x801321D8u: goto label_801321D8;
    case 0x801321DCu: goto label_801321DC;
    case 0x801321E0u: goto label_801321E0;
    case 0x801321E4u: goto label_801321E4;
    case 0x801321E8u: goto label_801321E8;
    case 0x801321ECu: goto label_801321EC;
    case 0x801321F0u: goto label_801321F0;
    case 0x801321F4u: goto label_801321F4;
    case 0x801321F8u: goto label_801321F8;
    case 0x801321FCu: goto label_801321FC;
    case 0x80132200u: goto label_80132200;
    case 0x80132204u: goto label_80132204;
    case 0x80132208u: goto label_80132208;
    case 0x8013220Cu: goto label_8013220C;
    case 0x80132210u: goto label_80132210;
    case 0x80132214u: goto label_80132214;
    case 0x80132218u: goto label_80132218;
    case 0x8013221Cu: goto label_8013221C;
    case 0x80132220u: goto label_80132220;
    case 0x80132224u: goto label_80132224;
    case 0x80132228u: goto label_80132228;
    case 0x8013222Cu: goto label_8013222C;
    case 0x80132230u: goto label_80132230;
    case 0x80132234u: goto label_80132234;
    case 0x80132238u: goto label_80132238;
    case 0x8013223Cu: goto label_8013223C;
    case 0x80132240u: goto label_80132240;
    case 0x80132244u: goto label_80132244;
    case 0x80132248u: goto label_80132248;
    case 0x8013224Cu: goto label_8013224C;
    case 0x80132250u: goto label_80132250;
    case 0x80132254u: goto label_80132254;
    case 0x80132258u: goto label_80132258;
    case 0x8013225Cu: goto label_8013225C;
    case 0x80132260u: goto label_80132260;
    case 0x80132264u: goto label_80132264;
    case 0x80132268u: goto label_80132268;
    case 0x8013226Cu: goto label_8013226C;
    case 0x80132270u: goto label_80132270;
    case 0x80132274u: goto label_80132274;
    case 0x80132278u: goto label_80132278;
    case 0x8013227Cu: goto label_8013227C;
    case 0x80132280u: goto label_80132280;
    case 0x80132284u: goto label_80132284;
    case 0x80132288u: goto label_80132288;
    case 0x8013228Cu: goto label_8013228C;
    case 0x80132290u: goto label_80132290;
    case 0x80132294u: goto label_80132294;
    case 0x80132298u: goto label_80132298;
    case 0x8013229Cu: goto label_8013229C;
    case 0x801322A0u: goto label_801322A0;
    case 0x801322A4u: goto label_801322A4;
    case 0x801322A8u: goto label_801322A8;
    case 0x801322ACu: goto label_801322AC;
    case 0x801322B0u: goto label_801322B0;
    case 0x801322B4u: goto label_801322B4;
    case 0x801322B8u: goto label_801322B8;
    case 0x801322BCu: goto label_801322BC;
    case 0x801322C0u: goto label_801322C0;
    case 0x801322C4u: goto label_801322C4;
    case 0x801322C8u: goto label_801322C8;
    case 0x801322CCu: goto label_801322CC;
    case 0x801322D0u: goto label_801322D0;
    case 0x801322D4u: goto label_801322D4;
    case 0x801322D8u: goto label_801322D8;
    case 0x801322DCu: goto label_801322DC;
    case 0x801322E0u: goto label_801322E0;
    case 0x801322E4u: goto label_801322E4;
    case 0x801322E8u: goto label_801322E8;
    case 0x801322ECu: goto label_801322EC;
    case 0x801322F0u: goto label_801322F0;
    case 0x801322F4u: goto label_801322F4;
    case 0x801322F8u: goto label_801322F8;
    case 0x801322FCu: goto label_801322FC;
    case 0x80132300u: goto label_80132300;
    case 0x80132304u: goto label_80132304;
    case 0x80132308u: goto label_80132308;
    case 0x8013230Cu: goto label_8013230C;
    case 0x80132310u: goto label_80132310;
    case 0x80132314u: goto label_80132314;
    case 0x80132318u: goto label_80132318;
    case 0x8013231Cu: goto label_8013231C;
    case 0x80132320u: goto label_80132320;
    case 0x80132324u: goto label_80132324;
    case 0x80132328u: goto label_80132328;
    case 0x8013232Cu: goto label_8013232C;
    case 0x80132330u: goto label_80132330;
    case 0x80132334u: goto label_80132334;
    case 0x80132338u: goto label_80132338;
    case 0x8013233Cu: goto label_8013233C;
    case 0x80132340u: goto label_80132340;
    case 0x80132344u: goto label_80132344;
    case 0x80132348u: goto label_80132348;
    case 0x8013234Cu: goto label_8013234C;
    case 0x80132350u: goto label_80132350;
    case 0x80132354u: goto label_80132354;
    case 0x80132358u: goto label_80132358;
    case 0x8013235Cu: goto label_8013235C;
    case 0x80132360u: goto label_80132360;
    case 0x80132364u: goto label_80132364;
    case 0x80132368u: goto label_80132368;
    case 0x8013236Cu: goto label_8013236C;
    case 0x80132370u: goto label_80132370;
    case 0x80132374u: goto label_80132374;
    case 0x80132378u: goto label_80132378;
    case 0x8013237Cu: goto label_8013237C;
    case 0x80132380u: goto label_80132380;
    case 0x80132384u: goto label_80132384;
    case 0x80132388u: goto label_80132388;
    case 0x8013238Cu: goto label_8013238C;
    case 0x80132390u: goto label_80132390;
    case 0x80132394u: goto label_80132394;
    case 0x80132398u: goto label_80132398;
    case 0x8013239Cu: goto label_8013239C;
    case 0x801323A0u: goto label_801323A0;
    case 0x801323A4u: goto label_801323A4;
    case 0x801323A8u: goto label_801323A8;
    case 0x801323ACu: goto label_801323AC;
    case 0x801323B0u: goto label_801323B0;
    case 0x801323B4u: goto label_801323B4;
    case 0x801323B8u: goto label_801323B8;
    case 0x801323BCu: goto label_801323BC;
    case 0x801323C0u: goto label_801323C0;
    case 0x801323C4u: goto label_801323C4;
    case 0x801323C8u: goto label_801323C8;
    case 0x801323CCu: goto label_801323CC;
    case 0x801323D0u: goto label_801323D0;
    case 0x801323D4u: goto label_801323D4;
    case 0x801323D8u: goto label_801323D8;
    case 0x801323DCu: goto label_801323DC;
    case 0x801323E0u: goto label_801323E0;
    case 0x801323E4u: goto label_801323E4;
    case 0x801323E8u: goto label_801323E8;
    case 0x801323ECu: goto label_801323EC;
    case 0x801323F0u: goto label_801323F0;
    case 0x801323F4u: goto label_801323F4;
    case 0x801323F8u: goto label_801323F8;
    case 0x801323FCu: goto label_801323FC;
    case 0x80132400u: goto label_80132400;
    case 0x80132404u: goto label_80132404;
    case 0x80132408u: goto label_80132408;
    case 0x8013240Cu: goto label_8013240C;
    case 0x80132410u: goto label_80132410;
    case 0x80132414u: goto label_80132414;
    case 0x80132418u: goto label_80132418;
    case 0x8013241Cu: goto label_8013241C;
    case 0x80132420u: goto label_80132420;
    case 0x80132424u: goto label_80132424;
    case 0x80132428u: goto label_80132428;
    case 0x8013242Cu: goto label_8013242C;
    case 0x80132430u: goto label_80132430;
    case 0x80132434u: goto label_80132434;
    case 0x80132438u: goto label_80132438;
    case 0x8013243Cu: goto label_8013243C;
    case 0x80132440u: goto label_80132440;
    case 0x80132444u: goto label_80132444;
    case 0x80132448u: goto label_80132448;
    case 0x8013244Cu: goto label_8013244C;
    case 0x80132450u: goto label_80132450;
    case 0x80132454u: goto label_80132454;
    case 0x80132458u: goto label_80132458;
    case 0x8013245Cu: goto label_8013245C;
    case 0x80132460u: goto label_80132460;
    case 0x80132464u: goto label_80132464;
    case 0x80132468u: goto label_80132468;
    case 0x8013246Cu: goto label_8013246C;
    case 0x80132470u: goto label_80132470;
    case 0x80132474u: goto label_80132474;
    case 0x80132478u: goto label_80132478;
    case 0x8013247Cu: goto label_8013247C;
    case 0x80132480u: goto label_80132480;
    case 0x80132484u: goto label_80132484;
    case 0x80132488u: goto label_80132488;
    case 0x8013248Cu: goto label_8013248C;
    case 0x80132490u: goto label_80132490;
    case 0x80132494u: goto label_80132494;
    case 0x80132498u: goto label_80132498;
    case 0x8013249Cu: goto label_8013249C;
    case 0x801324A0u: goto label_801324A0;
    case 0x801324A4u: goto label_801324A4;
    case 0x801324A8u: goto label_801324A8;
    case 0x801324ACu: goto label_801324AC;
    case 0x801324B0u: goto label_801324B0;
    case 0x801324B4u: goto label_801324B4;
    case 0x801324B8u: goto label_801324B8;
    case 0x801324BCu: goto label_801324BC;
    case 0x801324C0u: goto label_801324C0;
    case 0x801324C4u: goto label_801324C4;
    case 0x801324C8u: goto label_801324C8;
    case 0x801324CCu: goto label_801324CC;
    case 0x801324D0u: goto label_801324D0;
    case 0x801324D4u: goto label_801324D4;
    case 0x801324D8u: goto label_801324D8;
    case 0x801324DCu: goto label_801324DC;
    case 0x801324E0u: goto label_801324E0;
    case 0x801324E4u: goto label_801324E4;
    case 0x801324E8u: goto label_801324E8;
    case 0x801324ECu: goto label_801324EC;
    case 0x801324F0u: goto label_801324F0;
    case 0x801324F4u: goto label_801324F4;
    case 0x801324F8u: goto label_801324F8;
    case 0x801324FCu: goto label_801324FC;
    case 0x80132500u: goto label_80132500;
    case 0x80132504u: goto label_80132504;
    case 0x80132508u: goto label_80132508;
    case 0x8013250Cu: goto label_8013250C;
    case 0x80132510u: goto label_80132510;
    case 0x80132514u: goto label_80132514;
    case 0x80132518u: goto label_80132518;
    case 0x8013251Cu: goto label_8013251C;
    case 0x80132520u: goto label_80132520;
    case 0x80132524u: goto label_80132524;
    case 0x80132528u: goto label_80132528;
    case 0x8013252Cu: goto label_8013252C;
    case 0x80132530u: goto label_80132530;
    case 0x80132534u: goto label_80132534;
    case 0x80132538u: goto label_80132538;
    case 0x8013253Cu: goto label_8013253C;
    case 0x80132540u: goto label_80132540;
    case 0x80132544u: goto label_80132544;
    case 0x80132548u: goto label_80132548;
    case 0x8013254Cu: goto label_8013254C;
    case 0x80132550u: goto label_80132550;
    case 0x80132554u: goto label_80132554;
    case 0x80132558u: goto label_80132558;
    case 0x8013255Cu: goto label_8013255C;
    case 0x80132560u: goto label_80132560;
    case 0x80132564u: goto label_80132564;
    case 0x80132568u: goto label_80132568;
    case 0x8013256Cu: goto label_8013256C;
    case 0x80132570u: goto label_80132570;
    case 0x80132574u: goto label_80132574;
    case 0x80132578u: goto label_80132578;
    case 0x8013257Cu: goto label_8013257C;
    case 0x80132580u: goto label_80132580;
    case 0x80132584u: goto label_80132584;
    case 0x80132588u: goto label_80132588;
    case 0x8013258Cu: goto label_8013258C;
    case 0x80132590u: goto label_80132590;
    case 0x80132594u: goto label_80132594;
    case 0x80132598u: goto label_80132598;
    case 0x8013259Cu: goto label_8013259C;
    case 0x801325A0u: goto label_801325A0;
    case 0x801325A4u: goto label_801325A4;
    case 0x801325A8u: goto label_801325A8;
    case 0x801325ACu: goto label_801325AC;
    case 0x801325B0u: goto label_801325B0;
    case 0x801325B4u: goto label_801325B4;
    case 0x801325B8u: goto label_801325B8;
    case 0x801325BCu: goto label_801325BC;
    case 0x801325C0u: goto label_801325C0;
    case 0x801325C4u: goto label_801325C4;
    case 0x801325C8u: goto label_801325C8;
    case 0x801325CCu: goto label_801325CC;
    case 0x801325D0u: goto label_801325D0;
    case 0x801325D4u: goto label_801325D4;
    case 0x801325D8u: goto label_801325D8;
    case 0x801325DCu: goto label_801325DC;
    case 0x801325E0u: goto label_801325E0;
    case 0x801325E4u: goto label_801325E4;
    case 0x801325E8u: goto label_801325E8;
    case 0x801325ECu: goto label_801325EC;
    case 0x801325F0u: goto label_801325F0;
    case 0x801325F4u: goto label_801325F4;
    case 0x801325F8u: goto label_801325F8;
    case 0x801325FCu: goto label_801325FC;
    case 0x80132600u: goto label_80132600;
    case 0x80132604u: goto label_80132604;
    case 0x80132608u: goto label_80132608;
    case 0x8013260Cu: goto label_8013260C;
    case 0x80132610u: goto label_80132610;
    case 0x80132614u: goto label_80132614;
    case 0x80132618u: goto label_80132618;
    case 0x8013261Cu: goto label_8013261C;
    case 0x80132620u: goto label_80132620;
    case 0x80132624u: goto label_80132624;
    case 0x80132628u: goto label_80132628;
    case 0x8013262Cu: goto label_8013262C;
    case 0x80132630u: goto label_80132630;
    case 0x80132634u: goto label_80132634;
    case 0x80132638u: goto label_80132638;
    case 0x8013263Cu: goto label_8013263C;
    case 0x80132640u: goto label_80132640;
    case 0x80132644u: goto label_80132644;
    case 0x80132648u: goto label_80132648;
    case 0x8013264Cu: goto label_8013264C;
    case 0x80132650u: goto label_80132650;
    case 0x80132654u: goto label_80132654;
    case 0x80132658u: goto label_80132658;
    case 0x8013265Cu: goto label_8013265C;
    case 0x80132660u: goto label_80132660;
    case 0x80132664u: goto label_80132664;
    case 0x80132668u: goto label_80132668;
    case 0x8013266Cu: goto label_8013266C;
    case 0x80132670u: goto label_80132670;
    case 0x80132674u: goto label_80132674;
    case 0x80132678u: goto label_80132678;
    case 0x8013267Cu: goto label_8013267C;
    case 0x80132680u: goto label_80132680;
    case 0x80132684u: goto label_80132684;
    case 0x80132688u: goto label_80132688;
    case 0x8013268Cu: goto label_8013268C;
    case 0x80132690u: goto label_80132690;
    case 0x80132694u: goto label_80132694;
    case 0x80132698u: goto label_80132698;
    case 0x8013269Cu: goto label_8013269C;
    case 0x801326A0u: goto label_801326A0;
    case 0x801326A4u: goto label_801326A4;
    case 0x801326A8u: goto label_801326A8;
    case 0x801326ACu: goto label_801326AC;
    case 0x801326B0u: goto label_801326B0;
    case 0x801326B4u: goto label_801326B4;
    case 0x801326B8u: goto label_801326B8;
    case 0x801326BCu: goto label_801326BC;
    case 0x801326C0u: goto label_801326C0;
    case 0x801326C4u: goto label_801326C4;
    case 0x801326C8u: goto label_801326C8;
    case 0x801326CCu: goto label_801326CC;
    case 0x801326D0u: goto label_801326D0;
    case 0x801326D4u: goto label_801326D4;
    case 0x801326D8u: goto label_801326D8;
    case 0x801326DCu: goto label_801326DC;
    case 0x801326E0u: goto label_801326E0;
    case 0x801326E4u: goto label_801326E4;
    case 0x801326E8u: goto label_801326E8;
    case 0x801326ECu: goto label_801326EC;
    case 0x801326F0u: goto label_801326F0;
    case 0x801326F4u: goto label_801326F4;
    case 0x801326F8u: goto label_801326F8;
    case 0x801326FCu: goto label_801326FC;
    case 0x80132700u: goto label_80132700;
    case 0x80132704u: goto label_80132704;
    case 0x80132708u: goto label_80132708;
    case 0x8013270Cu: goto label_8013270C;
    case 0x80132710u: goto label_80132710;
    case 0x80132714u: goto label_80132714;
    case 0x80132718u: goto label_80132718;
    case 0x8013271Cu: goto label_8013271C;
    case 0x80132720u: goto label_80132720;
    case 0x80132724u: goto label_80132724;
    case 0x80132728u: goto label_80132728;
    case 0x8013272Cu: goto label_8013272C;
    case 0x80132730u: goto label_80132730;
    case 0x80132734u: goto label_80132734;
    case 0x80132738u: goto label_80132738;
    case 0x8013273Cu: goto label_8013273C;
    case 0x80132740u: goto label_80132740;
    case 0x80132744u: goto label_80132744;
    case 0x80132748u: goto label_80132748;
    case 0x8013274Cu: goto label_8013274C;
    case 0x80132750u: goto label_80132750;
    case 0x80132754u: goto label_80132754;
    case 0x80132758u: goto label_80132758;
    case 0x8013275Cu: goto label_8013275C;
    case 0x80132760u: goto label_80132760;
    case 0x80132764u: goto label_80132764;
    case 0x80132768u: goto label_80132768;
    case 0x8013276Cu: goto label_8013276C;
    case 0x80132770u: goto label_80132770;
    case 0x80132774u: goto label_80132774;
    case 0x80132778u: goto label_80132778;
    case 0x8013277Cu: goto label_8013277C;
    case 0x80132780u: goto label_80132780;
    case 0x80132784u: goto label_80132784;
    case 0x80132788u: goto label_80132788;
    case 0x8013278Cu: goto label_8013278C;
    case 0x80132790u: goto label_80132790;
    case 0x80132794u: goto label_80132794;
    case 0x80132798u: goto label_80132798;
    case 0x8013279Cu: goto label_8013279C;
    case 0x801327A0u: goto label_801327A0;
    case 0x801327A4u: goto label_801327A4;
    case 0x801327A8u: goto label_801327A8;
    case 0x801327ACu: goto label_801327AC;
    case 0x801327B0u: goto label_801327B0;
    case 0x801327B4u: goto label_801327B4;
    case 0x801327B8u: goto label_801327B8;
    case 0x801327BCu: goto label_801327BC;
    case 0x801327C0u: goto label_801327C0;
    case 0x801327C4u: goto label_801327C4;
    case 0x801327C8u: goto label_801327C8;
    case 0x801327CCu: goto label_801327CC;
    case 0x801327D0u: goto label_801327D0;
    case 0x801327D4u: goto label_801327D4;
    case 0x801327D8u: goto label_801327D8;
    case 0x801327DCu: goto label_801327DC;
    case 0x801327E0u: goto label_801327E0;
    case 0x801327E4u: goto label_801327E4;
    case 0x801327E8u: goto label_801327E8;
    case 0x801327ECu: goto label_801327EC;
    case 0x801327F0u: goto label_801327F0;
    case 0x801327F4u: goto label_801327F4;
    case 0x801327F8u: goto label_801327F8;
    case 0x801327FCu: goto label_801327FC;
    case 0x80132800u: goto label_80132800;
    case 0x80132804u: goto label_80132804;
    case 0x80132808u: goto label_80132808;
    case 0x8013280Cu: goto label_8013280C;
    case 0x80132810u: goto label_80132810;
    case 0x80132814u: goto label_80132814;
    case 0x80132818u: goto label_80132818;
    case 0x8013281Cu: goto label_8013281C;
    case 0x80132820u: goto label_80132820;
    case 0x80132824u: goto label_80132824;
    case 0x80132828u: goto label_80132828;
    case 0x8013282Cu: goto label_8013282C;
    case 0x80132830u: goto label_80132830;
    case 0x80132834u: goto label_80132834;
    case 0x80132838u: goto label_80132838;
    case 0x8013283Cu: goto label_8013283C;
    case 0x80132840u: goto label_80132840;
    case 0x80132844u: goto label_80132844;
    case 0x80132848u: goto label_80132848;
    case 0x8013284Cu: goto label_8013284C;
    case 0x80132850u: goto label_80132850;
    case 0x80132854u: goto label_80132854;
    case 0x80132858u: goto label_80132858;
    case 0x8013285Cu: goto label_8013285C;
    case 0x80132860u: goto label_80132860;
    case 0x80132864u: goto label_80132864;
    case 0x80132868u: goto label_80132868;
    case 0x8013286Cu: goto label_8013286C;
    case 0x80132870u: goto label_80132870;
    case 0x80132874u: goto label_80132874;
    case 0x80132878u: goto label_80132878;
    case 0x8013287Cu: goto label_8013287C;
    case 0x80132880u: goto label_80132880;
    case 0x80132884u: goto label_80132884;
    case 0x80132888u: goto label_80132888;
    case 0x8013288Cu: goto label_8013288C;
    case 0x80132890u: goto label_80132890;
    case 0x80132894u: goto label_80132894;
    case 0x80132898u: goto label_80132898;
    case 0x8013289Cu: goto label_8013289C;
    case 0x801328A0u: goto label_801328A0;
    case 0x801328A4u: goto label_801328A4;
    case 0x801328A8u: goto label_801328A8;
    case 0x801328ACu: goto label_801328AC;
    case 0x801328B0u: goto label_801328B0;
    case 0x801328B4u: goto label_801328B4;
    case 0x801328B8u: goto label_801328B8;
    case 0x801328BCu: goto label_801328BC;
    case 0x801328C0u: goto label_801328C0;
    case 0x801328C4u: goto label_801328C4;
    case 0x801328C8u: goto label_801328C8;
    case 0x801328CCu: goto label_801328CC;
    case 0x801328D0u: goto label_801328D0;
    case 0x801328D4u: goto label_801328D4;
    case 0x801328D8u: goto label_801328D8;
    case 0x801328DCu: goto label_801328DC;
    case 0x801328E0u: goto label_801328E0;
    case 0x801328E4u: goto label_801328E4;
    case 0x801328E8u: goto label_801328E8;
    case 0x801328ECu: goto label_801328EC;
    case 0x801328F0u: goto label_801328F0;
    case 0x801328F4u: goto label_801328F4;
    case 0x801328F8u: goto label_801328F8;
    case 0x801328FCu: goto label_801328FC;
    case 0x80132900u: goto label_80132900;
    case 0x80132904u: goto label_80132904;
    case 0x80132908u: goto label_80132908;
    case 0x8013290Cu: goto label_8013290C;
    case 0x80132910u: goto label_80132910;
    case 0x80132914u: goto label_80132914;
    case 0x80132918u: goto label_80132918;
    case 0x8013291Cu: goto label_8013291C;
    case 0x80132920u: goto label_80132920;
    case 0x80132924u: goto label_80132924;
    case 0x80132928u: goto label_80132928;
    case 0x8013292Cu: goto label_8013292C;
    case 0x80132930u: goto label_80132930;
    case 0x80132934u: goto label_80132934;
    case 0x80132938u: goto label_80132938;
    case 0x8013293Cu: goto label_8013293C;
    case 0x80132940u: goto label_80132940;
    case 0x80132944u: goto label_80132944;
    case 0x80132948u: goto label_80132948;
    case 0x8013294Cu: goto label_8013294C;
    case 0x80132950u: goto label_80132950;
    case 0x80132954u: goto label_80132954;
    case 0x80132958u: goto label_80132958;
    case 0x8013295Cu: goto label_8013295C;
    case 0x80132960u: goto label_80132960;
    case 0x80132964u: goto label_80132964;
    case 0x80132968u: goto label_80132968;
    case 0x8013296Cu: goto label_8013296C;
    case 0x80132970u: goto label_80132970;
    case 0x80132974u: goto label_80132974;
    case 0x80132978u: goto label_80132978;
    case 0x8013297Cu: goto label_8013297C;
    case 0x80132980u: goto label_80132980;
    case 0x80132984u: goto label_80132984;
    case 0x80132988u: goto label_80132988;
    case 0x8013298Cu: goto label_8013298C;
    case 0x80132990u: goto label_80132990;
    case 0x80132994u: goto label_80132994;
    case 0x80132998u: goto label_80132998;
    case 0x8013299Cu: goto label_8013299C;
    case 0x801329A0u: goto label_801329A0;
    case 0x801329A4u: goto label_801329A4;
    case 0x801329A8u: goto label_801329A8;
    case 0x801329ACu: goto label_801329AC;
    case 0x801329B0u: goto label_801329B0;
    case 0x801329B4u: goto label_801329B4;
    case 0x801329B8u: goto label_801329B8;
    case 0x801329BCu: goto label_801329BC;
    case 0x801329C0u: goto label_801329C0;
    case 0x801329C4u: goto label_801329C4;
    case 0x801329C8u: goto label_801329C8;
    case 0x801329CCu: goto label_801329CC;
    case 0x801329D0u: goto label_801329D0;
    case 0x801329D4u: goto label_801329D4;
    case 0x801329D8u: goto label_801329D8;
    case 0x801329DCu: goto label_801329DC;
    case 0x801329E0u: goto label_801329E0;
    case 0x801329E4u: goto label_801329E4;
    case 0x801329E8u: goto label_801329E8;
    case 0x801329ECu: goto label_801329EC;
    case 0x801329F0u: goto label_801329F0;
    case 0x801329F4u: goto label_801329F4;
    case 0x801329F8u: goto label_801329F8;
    case 0x801329FCu: goto label_801329FC;
    case 0x80132A00u: goto label_80132A00;
    case 0x80132A04u: goto label_80132A04;
    case 0x80132A08u: goto label_80132A08;
    case 0x80132A0Cu: goto label_80132A0C;
    case 0x80132A10u: goto label_80132A10;
    case 0x80132A14u: goto label_80132A14;
    case 0x80132A18u: goto label_80132A18;
    case 0x80132A1Cu: goto label_80132A1C;
    case 0x80132A20u: goto label_80132A20;
    case 0x80132A24u: goto label_80132A24;
    case 0x80132A28u: goto label_80132A28;
    case 0x80132A2Cu: goto label_80132A2C;
    case 0x80132A30u: goto label_80132A30;
    case 0x80132A34u: goto label_80132A34;
    case 0x80132A38u: goto label_80132A38;
    case 0x80132A3Cu: goto label_80132A3C;
    case 0x80132A40u: goto label_80132A40;
    case 0x80132A44u: goto label_80132A44;
    case 0x80132A48u: goto label_80132A48;
    case 0x80132A4Cu: goto label_80132A4C;
    case 0x80132A50u: goto label_80132A50;
    case 0x80132A54u: goto label_80132A54;
    case 0x80132A58u: goto label_80132A58;
    case 0x80132A5Cu: goto label_80132A5C;
    case 0x80132A60u: goto label_80132A60;
    case 0x80132A64u: goto label_80132A64;
    case 0x80132A68u: goto label_80132A68;
    case 0x80132A6Cu: goto label_80132A6C;
    case 0x80132A70u: goto label_80132A70;
    case 0x80132A74u: goto label_80132A74;
    case 0x80132A78u: goto label_80132A78;
    case 0x80132A7Cu: goto label_80132A7C;
    case 0x80132A80u: goto label_80132A80;
    case 0x80132A84u: goto label_80132A84;
    case 0x80132A88u: goto label_80132A88;
    case 0x80132A8Cu: goto label_80132A8C;
    case 0x80132A90u: goto label_80132A90;
    case 0x80132A94u: goto label_80132A94;
    case 0x80132A98u: goto label_80132A98;
    case 0x80132A9Cu: goto label_80132A9C;
    case 0x80132AA0u: goto label_80132AA0;
    case 0x80132AA4u: goto label_80132AA4;
    case 0x80132AA8u: goto label_80132AA8;
    case 0x80132AACu: goto label_80132AAC;
    case 0x80132AB0u: goto label_80132AB0;
    case 0x80132AB4u: goto label_80132AB4;
    case 0x80132AB8u: goto label_80132AB8;
    case 0x80132ABCu: goto label_80132ABC;
    case 0x80132AC0u: goto label_80132AC0;
    case 0x80132AC4u: goto label_80132AC4;
    case 0x80132AC8u: goto label_80132AC8;
    case 0x80132ACCu: goto label_80132ACC;
    case 0x80132AD0u: goto label_80132AD0;
    case 0x80132AD4u: goto label_80132AD4;
    case 0x80132AD8u: goto label_80132AD8;
    case 0x80132ADCu: goto label_80132ADC;
    case 0x80132AE0u: goto label_80132AE0;
    case 0x80132AE4u: goto label_80132AE4;
    case 0x80132AE8u: goto label_80132AE8;
    case 0x80132AECu: goto label_80132AEC;
    case 0x80132AF0u: goto label_80132AF0;
    case 0x80132AF4u: goto label_80132AF4;
    case 0x80132AF8u: goto label_80132AF8;
    case 0x80132AFCu: goto label_80132AFC;
    case 0x80132B00u: goto label_80132B00;
    case 0x80132B04u: goto label_80132B04;
    case 0x80132B08u: goto label_80132B08;
    case 0x80132B0Cu: goto label_80132B0C;
    case 0x80132B10u: goto label_80132B10;
    case 0x80132B14u: goto label_80132B14;
    case 0x80132B18u: goto label_80132B18;
    case 0x80132B1Cu: goto label_80132B1C;
    case 0x80132B20u: goto label_80132B20;
    case 0x80132B24u: goto label_80132B24;
    case 0x80132B28u: goto label_80132B28;
    case 0x80132B2Cu: goto label_80132B2C;
    case 0x80132B30u: goto label_80132B30;
    case 0x80132B34u: goto label_80132B34;
    case 0x80132B38u: goto label_80132B38;
    case 0x80132B3Cu: goto label_80132B3C;
    case 0x80132B40u: goto label_80132B40;
    case 0x80132B44u: goto label_80132B44;
    case 0x80132B48u: goto label_80132B48;
    case 0x80132B4Cu: goto label_80132B4C;
    case 0x80132B50u: goto label_80132B50;
    case 0x80132B54u: goto label_80132B54;
    case 0x80132B58u: goto label_80132B58;
    case 0x80132B5Cu: goto label_80132B5C;
    case 0x80132B60u: goto label_80132B60;
    case 0x80132B64u: goto label_80132B64;
    case 0x80132B68u: goto label_80132B68;
    case 0x80132B6Cu: goto label_80132B6C;
    case 0x80132B70u: goto label_80132B70;
    case 0x80132B74u: goto label_80132B74;
    case 0x80132B78u: goto label_80132B78;
    case 0x80132B7Cu: goto label_80132B7C;
    case 0x80132B80u: goto label_80132B80;
    case 0x80132B84u: goto label_80132B84;
    case 0x80132B88u: goto label_80132B88;
    case 0x80132B8Cu: goto label_80132B8C;
    case 0x80132B90u: goto label_80132B90;
    case 0x80132B94u: goto label_80132B94;
    case 0x80132B98u: goto label_80132B98;
    case 0x80132B9Cu: goto label_80132B9C;
    case 0x80132BA0u: goto label_80132BA0;
    case 0x80132BA4u: goto label_80132BA4;
    case 0x80132BA8u: goto label_80132BA8;
    case 0x80132BACu: goto label_80132BAC;
    case 0x80132BB0u: goto label_80132BB0;
    case 0x80132BB4u: goto label_80132BB4;
    case 0x80132BB8u: goto label_80132BB8;
    case 0x80132BBCu: goto label_80132BBC;
    case 0x80132BC0u: goto label_80132BC0;
    case 0x80132BC4u: goto label_80132BC4;
    case 0x80132BC8u: goto label_80132BC8;
    case 0x80132BCCu: goto label_80132BCC;
    case 0x80132BD0u: goto label_80132BD0;
    case 0x80132BD4u: goto label_80132BD4;
    case 0x80132BD8u: goto label_80132BD8;
    case 0x80132BDCu: goto label_80132BDC;
    case 0x80132BE0u: goto label_80132BE0;
    case 0x80132BE4u: goto label_80132BE4;
    case 0x80132BE8u: goto label_80132BE8;
    case 0x80132BECu: goto label_80132BEC;
    case 0x80132BF0u: goto label_80132BF0;
    case 0x80132BF4u: goto label_80132BF4;
    case 0x80132BF8u: goto label_80132BF8;
    case 0x80132BFCu: goto label_80132BFC;
    case 0x80132C00u: goto label_80132C00;
    case 0x80132C04u: goto label_80132C04;
    case 0x80132C08u: goto label_80132C08;
    case 0x80132C0Cu: goto label_80132C0C;
    case 0x80132C10u: goto label_80132C10;
    case 0x80132C14u: goto label_80132C14;
    case 0x80132C18u: goto label_80132C18;
    case 0x80132C1Cu: goto label_80132C1C;
    case 0x80132C20u: goto label_80132C20;
    case 0x80132C24u: goto label_80132C24;
    case 0x80132C28u: goto label_80132C28;
    case 0x80132C2Cu: goto label_80132C2C;
    case 0x80132C30u: goto label_80132C30;
    case 0x80132C34u: goto label_80132C34;
    case 0x80132C38u: goto label_80132C38;
    case 0x80132C3Cu: goto label_80132C3C;
    case 0x80132C40u: goto label_80132C40;
    case 0x80132C44u: goto label_80132C44;
    case 0x80132C48u: goto label_80132C48;
    case 0x80132C4Cu: goto label_80132C4C;
    case 0x80132C50u: goto label_80132C50;
    case 0x80132C54u: goto label_80132C54;
    case 0x80132C58u: goto label_80132C58;
    case 0x80132C5Cu: goto label_80132C5C;
    case 0x80132C60u: goto label_80132C60;
    case 0x80132C64u: goto label_80132C64;
    case 0x80132C68u: goto label_80132C68;
    case 0x80132C6Cu: goto label_80132C6C;
    case 0x80132C70u: goto label_80132C70;
    case 0x80132C74u: goto label_80132C74;
    case 0x80132C78u: goto label_80132C78;
    case 0x80132C7Cu: goto label_80132C7C;
    case 0x80132C80u: goto label_80132C80;
    case 0x80132C84u: goto label_80132C84;
    case 0x80132C88u: goto label_80132C88;
    case 0x80132C8Cu: goto label_80132C8C;
    case 0x80132C90u: goto label_80132C90;
    case 0x80132C94u: goto label_80132C94;
    case 0x80132C98u: goto label_80132C98;
    case 0x80132C9Cu: goto label_80132C9C;
    case 0x80132CA0u: goto label_80132CA0;
    case 0x80132CA4u: goto label_80132CA4;
    case 0x80132CA8u: goto label_80132CA8;
    case 0x80132CACu: goto label_80132CAC;
    case 0x80132CB0u: goto label_80132CB0;
    case 0x80132CB4u: goto label_80132CB4;
    case 0x80132CB8u: goto label_80132CB8;
    case 0x80132CBCu: goto label_80132CBC;
    case 0x80132CC0u: goto label_80132CC0;
    case 0x80132CC4u: goto label_80132CC4;
    case 0x80132CC8u: goto label_80132CC8;
    case 0x80132CCCu: goto label_80132CCC;
    case 0x80132CD0u: goto label_80132CD0;
    case 0x80132CD4u: goto label_80132CD4;
    case 0x80132CD8u: goto label_80132CD8;
    case 0x80132CDCu: goto label_80132CDC;
    case 0x80132CE0u: goto label_80132CE0;
    case 0x80132CE4u: goto label_80132CE4;
    case 0x80132CE8u: goto label_80132CE8;
    case 0x80132CECu: goto label_80132CEC;
    case 0x80132CF0u: goto label_80132CF0;
    case 0x80132CF4u: goto label_80132CF4;
    case 0x80132CF8u: goto label_80132CF8;
    case 0x80132CFCu: goto label_80132CFC;
    case 0x80132D00u: goto label_80132D00;
    case 0x80132D04u: goto label_80132D04;
    case 0x80132D08u: goto label_80132D08;
    case 0x80132D0Cu: goto label_80132D0C;
    case 0x80132D10u: goto label_80132D10;
    case 0x80132D14u: goto label_80132D14;
    case 0x80132D18u: goto label_80132D18;
    case 0x80132D1Cu: goto label_80132D1C;
    case 0x80132D20u: goto label_80132D20;
    case 0x80132D24u: goto label_80132D24;
    case 0x80132D28u: goto label_80132D28;
    case 0x80132D2Cu: goto label_80132D2C;
    case 0x80132D30u: goto label_80132D30;
    case 0x80132D34u: goto label_80132D34;
    case 0x80132D38u: goto label_80132D38;
    case 0x80132D3Cu: goto label_80132D3C;
    case 0x80132D40u: goto label_80132D40;
    case 0x80132D44u: goto label_80132D44;
    case 0x80132D48u: goto label_80132D48;
    case 0x80132D4Cu: goto label_80132D4C;
    case 0x80132D50u: goto label_80132D50;
    case 0x80132D54u: goto label_80132D54;
    case 0x80132D58u: goto label_80132D58;
    case 0x80132D5Cu: goto label_80132D5C;
    case 0x80132D60u: goto label_80132D60;
    case 0x80132D64u: goto label_80132D64;
    case 0x80132D68u: goto label_80132D68;
    case 0x80132D6Cu: goto label_80132D6C;
    case 0x80132D70u: goto label_80132D70;
    case 0x80132D74u: goto label_80132D74;
    case 0x80132D78u: goto label_80132D78;
    case 0x80132D7Cu: goto label_80132D7C;
    case 0x80132D80u: goto label_80132D80;
    case 0x80132D84u: goto label_80132D84;
    case 0x80132D88u: goto label_80132D88;
    case 0x80132D8Cu: goto label_80132D8C;
    case 0x80132D90u: goto label_80132D90;
    case 0x80132D94u: goto label_80132D94;
    case 0x80132D98u: goto label_80132D98;
    case 0x80132D9Cu: goto label_80132D9C;
    case 0x80132DA0u: goto label_80132DA0;
    case 0x80132DA4u: goto label_80132DA4;
    case 0x80132DA8u: goto label_80132DA8;
    case 0x80132DACu: goto label_80132DAC;
    case 0x80132DB0u: goto label_80132DB0;
    case 0x80132DB4u: goto label_80132DB4;
    case 0x80132DB8u: goto label_80132DB8;
    case 0x80132DBCu: goto label_80132DBC;
    case 0x80132DC0u: goto label_80132DC0;
    case 0x80132DC4u: goto label_80132DC4;
    case 0x80132DC8u: goto label_80132DC8;
    case 0x80132DCCu: goto label_80132DCC;
    case 0x80132DD0u: goto label_80132DD0;
    case 0x80132DD4u: goto label_80132DD4;
    case 0x80132DD8u: goto label_80132DD8;
    case 0x80132DDCu: goto label_80132DDC;
    case 0x80132DE0u: goto label_80132DE0;
    case 0x80132DE4u: goto label_80132DE4;
    case 0x80132DE8u: goto label_80132DE8;
    case 0x80132DECu: goto label_80132DEC;
    case 0x80132DF0u: goto label_80132DF0;
    case 0x80132DF4u: goto label_80132DF4;
    case 0x80132DF8u: goto label_80132DF8;
    case 0x80132DFCu: goto label_80132DFC;
    case 0x80132E00u: goto label_80132E00;
    case 0x80132E04u: goto label_80132E04;
    case 0x80132E08u: goto label_80132E08;
    case 0x80132E0Cu: goto label_80132E0C;
    case 0x80132E10u: goto label_80132E10;
    case 0x80132E14u: goto label_80132E14;
    case 0x80132E18u: goto label_80132E18;
    case 0x80132E1Cu: goto label_80132E1C;
    case 0x80132E20u: goto label_80132E20;
    case 0x80132E24u: goto label_80132E24;
    case 0x80132E28u: goto label_80132E28;
    case 0x80132E2Cu: goto label_80132E2C;
    case 0x80132E30u: goto label_80132E30;
    case 0x80132E34u: goto label_80132E34;
    case 0x80132E38u: goto label_80132E38;
    case 0x80132E3Cu: goto label_80132E3C;
    case 0x80132E40u: goto label_80132E40;
    case 0x80132E44u: goto label_80132E44;
    case 0x80132E48u: goto label_80132E48;
    case 0x80132E4Cu: goto label_80132E4C;
    case 0x80132E50u: goto label_80132E50;
    case 0x80132E54u: goto label_80132E54;
    case 0x80132E58u: goto label_80132E58;
    case 0x80132E5Cu: goto label_80132E5C;
    case 0x80132E60u: goto label_80132E60;
    case 0x80132E64u: goto label_80132E64;
    case 0x80132E68u: goto label_80132E68;
    case 0x80132E6Cu: goto label_80132E6C;
    case 0x80132E70u: goto label_80132E70;
    case 0x80132E74u: goto label_80132E74;
    case 0x80132E78u: goto label_80132E78;
    case 0x80132E7Cu: goto label_80132E7C;
    case 0x80132E80u: goto label_80132E80;
    case 0x80132E84u: goto label_80132E84;
    case 0x80132E88u: goto label_80132E88;
    case 0x80132E8Cu: goto label_80132E8C;
    case 0x80132E90u: goto label_80132E90;
    case 0x80132E94u: goto label_80132E94;
    case 0x80132E98u: goto label_80132E98;
    case 0x80132E9Cu: goto label_80132E9C;
    case 0x80132EA0u: goto label_80132EA0;
    case 0x80132EA4u: goto label_80132EA4;
    case 0x80132EA8u: goto label_80132EA8;
    case 0x80132EACu: goto label_80132EAC;
    case 0x80132EB0u: goto label_80132EB0;
    case 0x80132EB4u: goto label_80132EB4;
    case 0x80132EB8u: goto label_80132EB8;
    case 0x80132EBCu: goto label_80132EBC;
    case 0x80132EC0u: goto label_80132EC0;
    case 0x80132EC4u: goto label_80132EC4;
    case 0x80132EC8u: goto label_80132EC8;
    case 0x80132ECCu: goto label_80132ECC;
    case 0x80132ED0u: goto label_80132ED0;
    case 0x80132ED4u: goto label_80132ED4;
    case 0x80132ED8u: goto label_80132ED8;
    case 0x80132EDCu: goto label_80132EDC;
    case 0x80132EE0u: goto label_80132EE0;
    case 0x80132EE4u: goto label_80132EE4;
    case 0x80132EE8u: goto label_80132EE8;
    case 0x80132EECu: goto label_80132EEC;
    case 0x80132EF0u: goto label_80132EF0;
    case 0x80132EF4u: goto label_80132EF4;
    case 0x80132EF8u: goto label_80132EF8;
    case 0x80132EFCu: goto label_80132EFC;
    case 0x80132F00u: goto label_80132F00;
    case 0x80132F04u: goto label_80132F04;
    case 0x80132F08u: goto label_80132F08;
    case 0x80132F0Cu: goto label_80132F0C;
    case 0x80132F10u: goto label_80132F10;
    case 0x80132F14u: goto label_80132F14;
    case 0x80132F18u: goto label_80132F18;
    case 0x80132F1Cu: goto label_80132F1C;
    case 0x80132F20u: goto label_80132F20;
    case 0x80132F24u: goto label_80132F24;
    case 0x80132F28u: goto label_80132F28;
    case 0x80132F2Cu: goto label_80132F2C;
    case 0x80132F30u: goto label_80132F30;
    case 0x80132F34u: goto label_80132F34;
    case 0x80132F38u: goto label_80132F38;
    case 0x80132F3Cu: goto label_80132F3C;
    case 0x80132F40u: goto label_80132F40;
    case 0x80132F44u: goto label_80132F44;
    case 0x80132F48u: goto label_80132F48;
    case 0x80132F4Cu: goto label_80132F4C;
    case 0x80132F50u: goto label_80132F50;
    case 0x80132F54u: goto label_80132F54;
    case 0x80132F58u: goto label_80132F58;
    case 0x80132F5Cu: goto label_80132F5C;
    case 0x80132F60u: goto label_80132F60;
    case 0x80132F64u: goto label_80132F64;
    case 0x80132F68u: goto label_80132F68;
    case 0x80132F6Cu: goto label_80132F6C;
    case 0x80132F70u: goto label_80132F70;
    case 0x80132F74u: goto label_80132F74;
    case 0x80132F78u: goto label_80132F78;
    case 0x80132F7Cu: goto label_80132F7C;
    case 0x80132F80u: goto label_80132F80;
    case 0x80132F84u: goto label_80132F84;
    case 0x80132F88u: goto label_80132F88;
    case 0x80132F8Cu: goto label_80132F8C;
    case 0x80132F90u: goto label_80132F90;
    case 0x80132F94u: goto label_80132F94;
    case 0x80132F98u: goto label_80132F98;
    case 0x80132F9Cu: goto label_80132F9C;
    case 0x80132FA0u: goto label_80132FA0;
    case 0x80132FA4u: goto label_80132FA4;
    case 0x80132FA8u: goto label_80132FA8;
    case 0x80132FACu: goto label_80132FAC;
    case 0x80132FB0u: goto label_80132FB0;
    case 0x80132FB4u: goto label_80132FB4;
    case 0x80132FB8u: goto label_80132FB8;
    case 0x80132FBCu: goto label_80132FBC;
    case 0x80132FC0u: goto label_80132FC0;
    case 0x80132FC4u: goto label_80132FC4;
    case 0x80132FC8u: goto label_80132FC8;
    case 0x80132FCCu: goto label_80132FCC;
    case 0x80132FD0u: goto label_80132FD0;
    case 0x80132FD4u: goto label_80132FD4;
    case 0x80132FD8u: goto label_80132FD8;
    case 0x80132FDCu: goto label_80132FDC;
    case 0x80132FE0u: goto label_80132FE0;
    case 0x80132FE4u: goto label_80132FE4;
    case 0x80132FE8u: goto label_80132FE8;
    case 0x80132FECu: goto label_80132FEC;
    case 0x80132FF0u: goto label_80132FF0;
    case 0x80132FF4u: goto label_80132FF4;
    case 0x80132FF8u: goto label_80132FF8;
    case 0x80132FFCu: goto label_80132FFC;
    case 0x80133000u: goto label_80133000;
    case 0x80133004u: goto label_80133004;
    case 0x80133008u: goto label_80133008;
    case 0x8013300Cu: goto label_8013300C;
    case 0x80133010u: goto label_80133010;
    case 0x80133014u: goto label_80133014;
    case 0x80133018u: goto label_80133018;
    case 0x8013301Cu: goto label_8013301C;
    case 0x80133020u: goto label_80133020;
    case 0x80133024u: goto label_80133024;
    case 0x80133028u: goto label_80133028;
    case 0x8013302Cu: goto label_8013302C;
    case 0x80133030u: goto label_80133030;
    case 0x80133034u: goto label_80133034;
    case 0x80133038u: goto label_80133038;
    case 0x8013303Cu: goto label_8013303C;
    case 0x80133040u: goto label_80133040;
    case 0x80133044u: goto label_80133044;
    case 0x80133048u: goto label_80133048;
    case 0x8013304Cu: goto label_8013304C;
    case 0x80133050u: goto label_80133050;
    case 0x80133054u: goto label_80133054;
    case 0x80133058u: goto label_80133058;
    case 0x8013305Cu: goto label_8013305C;
    case 0x80133060u: goto label_80133060;
    case 0x80133064u: goto label_80133064;
    case 0x80133068u: goto label_80133068;
    case 0x8013306Cu: goto label_8013306C;
    case 0x80133070u: goto label_80133070;
    case 0x80133074u: goto label_80133074;
    case 0x80133078u: goto label_80133078;
    case 0x8013307Cu: goto label_8013307C;
    case 0x80133080u: goto label_80133080;
    case 0x80133084u: goto label_80133084;
    case 0x80133088u: goto label_80133088;
    case 0x8013308Cu: goto label_8013308C;
    case 0x80133090u: goto label_80133090;
    case 0x80133094u: goto label_80133094;
    case 0x80133098u: goto label_80133098;
    case 0x8013309Cu: goto label_8013309C;
    case 0x801330A0u: goto label_801330A0;
    case 0x801330A4u: goto label_801330A4;
    case 0x801330A8u: goto label_801330A8;
    case 0x801330ACu: goto label_801330AC;
    case 0x801330B0u: goto label_801330B0;
    case 0x801330B4u: goto label_801330B4;
    case 0x801330B8u: goto label_801330B8;
    case 0x801330BCu: goto label_801330BC;
    case 0x801330C0u: goto label_801330C0;
    case 0x801330C4u: goto label_801330C4;
    case 0x801330C8u: goto label_801330C8;
    case 0x801330CCu: goto label_801330CC;
    case 0x801330D0u: goto label_801330D0;
    case 0x801330D4u: goto label_801330D4;
    case 0x801330D8u: goto label_801330D8;
    case 0x801330DCu: goto label_801330DC;
    case 0x801330E0u: goto label_801330E0;
    case 0x801330E4u: goto label_801330E4;
    case 0x801330E8u: goto label_801330E8;
    case 0x801330ECu: goto label_801330EC;
    case 0x801330F0u: goto label_801330F0;
    case 0x801330F4u: goto label_801330F4;
    case 0x801330F8u: goto label_801330F8;
    case 0x801330FCu: goto label_801330FC;
    case 0x80133100u: goto label_80133100;
    case 0x80133104u: goto label_80133104;
    case 0x80133108u: goto label_80133108;
    case 0x8013310Cu: goto label_8013310C;
    case 0x80133110u: goto label_80133110;
    case 0x80133114u: goto label_80133114;
    case 0x80133118u: goto label_80133118;
    case 0x8013311Cu: goto label_8013311C;
    case 0x80133120u: goto label_80133120;
    case 0x80133124u: goto label_80133124;
    case 0x80133128u: goto label_80133128;
    case 0x8013312Cu: goto label_8013312C;
    case 0x80133130u: goto label_80133130;
    case 0x80133134u: goto label_80133134;
    case 0x80133138u: goto label_80133138;
    case 0x8013313Cu: goto label_8013313C;
    case 0x80133140u: goto label_80133140;
    case 0x80133144u: goto label_80133144;
    case 0x80133148u: goto label_80133148;
    case 0x8013314Cu: goto label_8013314C;
    case 0x80133150u: goto label_80133150;
    case 0x80133154u: goto label_80133154;
    case 0x80133158u: goto label_80133158;
    case 0x8013315Cu: goto label_8013315C;
    case 0x80133160u: goto label_80133160;
    case 0x80133164u: goto label_80133164;
    case 0x80133168u: goto label_80133168;
    case 0x8013316Cu: goto label_8013316C;
    case 0x80133170u: goto label_80133170;
    case 0x80133174u: goto label_80133174;
    case 0x80133178u: goto label_80133178;
    case 0x8013317Cu: goto label_8013317C;
    case 0x80133180u: goto label_80133180;
    case 0x80133184u: goto label_80133184;
    case 0x80133188u: goto label_80133188;
    case 0x8013318Cu: goto label_8013318C;
    case 0x80133190u: goto label_80133190;
    case 0x80133194u: goto label_80133194;
    case 0x80133198u: goto label_80133198;
    case 0x8013319Cu: goto label_8013319C;
    case 0x801331A0u: goto label_801331A0;
    case 0x801331A4u: goto label_801331A4;
    case 0x801331A8u: goto label_801331A8;
    case 0x801331ACu: goto label_801331AC;
    case 0x801331B0u: goto label_801331B0;
    case 0x801331B4u: goto label_801331B4;
    case 0x801331B8u: goto label_801331B8;
    case 0x801331BCu: goto label_801331BC;
    case 0x801331C0u: goto label_801331C0;
    case 0x801331C4u: goto label_801331C4;
    case 0x801331C8u: goto label_801331C8;
    case 0x801331CCu: goto label_801331CC;
    case 0x801331D0u: goto label_801331D0;
    case 0x801331D4u: goto label_801331D4;
    case 0x801331D8u: goto label_801331D8;
    case 0x801331DCu: goto label_801331DC;
    case 0x801331E0u: goto label_801331E0;
    case 0x801331E4u: goto label_801331E4;
    case 0x801331E8u: goto label_801331E8;
    case 0x801331ECu: goto label_801331EC;
    case 0x801331F0u: goto label_801331F0;
    case 0x801331F4u: goto label_801331F4;
    case 0x801331F8u: goto label_801331F8;
    case 0x801331FCu: goto label_801331FC;
    case 0x80133200u: goto label_80133200;
    case 0x80133204u: goto label_80133204;
    case 0x80133208u: goto label_80133208;
    case 0x8013320Cu: goto label_8013320C;
    case 0x80133210u: goto label_80133210;
    case 0x80133214u: goto label_80133214;
    case 0x80133218u: goto label_80133218;
    case 0x8013321Cu: goto label_8013321C;
    case 0x80133220u: goto label_80133220;
    case 0x80133224u: goto label_80133224;
    case 0x80133228u: goto label_80133228;
    case 0x8013322Cu: goto label_8013322C;
    case 0x80133230u: goto label_80133230;
    case 0x80133234u: goto label_80133234;
    case 0x80133238u: goto label_80133238;
    case 0x8013323Cu: goto label_8013323C;
    case 0x80133240u: goto label_80133240;
    case 0x80133244u: goto label_80133244;
    case 0x80133248u: goto label_80133248;
    case 0x8013324Cu: goto label_8013324C;
    case 0x80133250u: goto label_80133250;
    case 0x80133254u: goto label_80133254;
    case 0x80133258u: goto label_80133258;
    case 0x8013325Cu: goto label_8013325C;
    case 0x80133260u: goto label_80133260;
    case 0x80133264u: goto label_80133264;
    case 0x80133268u: goto label_80133268;
    case 0x8013326Cu: goto label_8013326C;
    case 0x80133270u: goto label_80133270;
    case 0x80133274u: goto label_80133274;
    case 0x80133278u: goto label_80133278;
    case 0x8013327Cu: goto label_8013327C;
    case 0x80133280u: goto label_80133280;
    case 0x80133284u: goto label_80133284;
    case 0x80133288u: goto label_80133288;
    case 0x8013328Cu: goto label_8013328C;
    case 0x80133290u: goto label_80133290;
    case 0x80133294u: goto label_80133294;
    case 0x80133298u: goto label_80133298;
    case 0x8013329Cu: goto label_8013329C;
    case 0x801332A0u: goto label_801332A0;
    case 0x801332A4u: goto label_801332A4;
    case 0x801332A8u: goto label_801332A8;
    case 0x801332ACu: goto label_801332AC;
    case 0x801332B0u: goto label_801332B0;
    case 0x801332B4u: goto label_801332B4;
    case 0x801332B8u: goto label_801332B8;
    case 0x801332BCu: goto label_801332BC;
    case 0x801332C0u: goto label_801332C0;
    case 0x801332C4u: goto label_801332C4;
    case 0x801332C8u: goto label_801332C8;
    case 0x801332CCu: goto label_801332CC;
    case 0x801332D0u: goto label_801332D0;
    case 0x801332D4u: goto label_801332D4;
    case 0x801332D8u: goto label_801332D8;
    case 0x801332DCu: goto label_801332DC;
    case 0x801332E0u: goto label_801332E0;
    case 0x801332E4u: goto label_801332E4;
    case 0x801332E8u: goto label_801332E8;
    case 0x801332ECu: goto label_801332EC;
    case 0x801332F0u: goto label_801332F0;
    case 0x801332F4u: goto label_801332F4;
    case 0x801332F8u: goto label_801332F8;
    case 0x801332FCu: goto label_801332FC;
    case 0x80133300u: goto label_80133300;
    case 0x80133304u: goto label_80133304;
    case 0x80133308u: goto label_80133308;
    case 0x8013330Cu: goto label_8013330C;
    case 0x80133310u: goto label_80133310;
    case 0x80133314u: goto label_80133314;
    case 0x80133318u: goto label_80133318;
    case 0x8013331Cu: goto label_8013331C;
    case 0x80133320u: goto label_80133320;
    case 0x80133324u: goto label_80133324;
    case 0x80133328u: goto label_80133328;
    case 0x8013332Cu: goto label_8013332C;
    case 0x80133330u: goto label_80133330;
    case 0x80133334u: goto label_80133334;
    case 0x80133338u: goto label_80133338;
    case 0x8013333Cu: goto label_8013333C;
    case 0x80133340u: goto label_80133340;
    case 0x80133344u: goto label_80133344;
    case 0x80133348u: goto label_80133348;
    case 0x8013334Cu: goto label_8013334C;
    case 0x80133350u: goto label_80133350;
    case 0x80133354u: goto label_80133354;
    case 0x80133358u: goto label_80133358;
    case 0x8013335Cu: goto label_8013335C;
    case 0x80133360u: goto label_80133360;
    case 0x80133364u: goto label_80133364;
    case 0x80133368u: goto label_80133368;
    case 0x8013336Cu: goto label_8013336C;
    case 0x80133370u: goto label_80133370;
    case 0x80133374u: goto label_80133374;
    case 0x80133378u: goto label_80133378;
    case 0x8013337Cu: goto label_8013337C;
    case 0x80133380u: goto label_80133380;
    case 0x80133384u: goto label_80133384;
    case 0x80133388u: goto label_80133388;
    case 0x8013338Cu: goto label_8013338C;
    case 0x80133390u: goto label_80133390;
    case 0x80133394u: goto label_80133394;
    case 0x80133398u: goto label_80133398;
    case 0x8013339Cu: goto label_8013339C;
    case 0x801333A0u: goto label_801333A0;
    case 0x801333A4u: goto label_801333A4;
    case 0x801333A8u: goto label_801333A8;
    case 0x801333ACu: goto label_801333AC;
    case 0x801333B0u: goto label_801333B0;
    case 0x801333B4u: goto label_801333B4;
    case 0x801333B8u: goto label_801333B8;
    case 0x801333BCu: goto label_801333BC;
    case 0x801333C0u: goto label_801333C0;
    case 0x801333C4u: goto label_801333C4;
    case 0x801333C8u: goto label_801333C8;
    case 0x801333CCu: goto label_801333CC;
    case 0x801333D0u: goto label_801333D0;
    case 0x801333D4u: goto label_801333D4;
    case 0x801333D8u: goto label_801333D8;
    case 0x801333DCu: goto label_801333DC;
    case 0x801333E0u: goto label_801333E0;
    case 0x801333E4u: goto label_801333E4;
    case 0x801333E8u: goto label_801333E8;
    case 0x801333ECu: goto label_801333EC;
    case 0x801333F0u: goto label_801333F0;
    case 0x801333F4u: goto label_801333F4;
    case 0x801333F8u: goto label_801333F8;
    case 0x801333FCu: goto label_801333FC;
    case 0x80133400u: goto label_80133400;
    case 0x80133404u: goto label_80133404;
    case 0x80133408u: goto label_80133408;
    case 0x8013340Cu: goto label_8013340C;
    case 0x80133410u: goto label_80133410;
    case 0x80133414u: goto label_80133414;
    case 0x80133418u: goto label_80133418;
    case 0x8013341Cu: goto label_8013341C;
    case 0x80133420u: goto label_80133420;
    case 0x80133424u: goto label_80133424;
    case 0x80133428u: goto label_80133428;
    case 0x8013342Cu: goto label_8013342C;
    case 0x80133430u: goto label_80133430;
    case 0x80133434u: goto label_80133434;
    case 0x80133438u: goto label_80133438;
    case 0x8013343Cu: goto label_8013343C;
    case 0x80133440u: goto label_80133440;
    case 0x80133444u: goto label_80133444;
    case 0x80133448u: goto label_80133448;
    case 0x8013344Cu: goto label_8013344C;
    case 0x80133450u: goto label_80133450;
    case 0x80133454u: goto label_80133454;
    case 0x80133458u: goto label_80133458;
    case 0x8013345Cu: goto label_8013345C;
    case 0x80133460u: goto label_80133460;
    case 0x80133464u: goto label_80133464;
    case 0x80133468u: goto label_80133468;
    case 0x8013346Cu: goto label_8013346C;
    case 0x80133470u: goto label_80133470;
    case 0x80133474u: goto label_80133474;
    case 0x80133478u: goto label_80133478;
    case 0x8013347Cu: goto label_8013347C;
    case 0x80133480u: goto label_80133480;
    case 0x80133484u: goto label_80133484;
    case 0x80133488u: goto label_80133488;
    case 0x8013348Cu: goto label_8013348C;
    case 0x80133490u: goto label_80133490;
    case 0x80133494u: goto label_80133494;
    case 0x80133498u: goto label_80133498;
    case 0x8013349Cu: goto label_8013349C;
    case 0x801334A0u: goto label_801334A0;
    case 0x801334A4u: goto label_801334A4;
    case 0x801334A8u: goto label_801334A8;
    case 0x801334ACu: goto label_801334AC;
    case 0x801334B0u: goto label_801334B0;
    case 0x801334B4u: goto label_801334B4;
    case 0x801334B8u: goto label_801334B8;
    case 0x801334BCu: goto label_801334BC;
    default: return;
    }
label_8012F4C0:
    ctx->pc = 0x8012F4C0u;
    ctx->downcount -= 1;
    // 8012F4C0: lwz     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012F4C4:
    loop_8012F4C4(ctx);
    if (ctx->pc == 0x8012F4D4u) goto label_8012F4D4;
    return;
label_8012F4C8:
    // 8012F4C8: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_8012F4CC:
    // 8012F4CC: cmpw    r4, r0
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

label_8012F4D0:
    // 8012F4D0: bc    4, 2, 0x8012F4C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8012F4C4u;
                return;
            }
            goto label_8012F4C4;
        }
    }

label_8012F4D4:
    ctx->pc = 0x8012F4D4u;
    ctx->downcount -= 1;
    // 8012F4D4: b       0x8012F684
    {
            goto label_8012F684;
    }

label_8012F4D8:
    ctx->pc = 0x8012F4D8u;
    ctx->downcount -= 13;
    // 8012F4D8: subf.   r9, r0, r5
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

label_8012F4DC:
    ctx->pc = 0x8012F4DCu;
    // 8012F4DC: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_8012F4E0:
    ctx->pc = 0x8012F4E0u;
    // 8012F4E0: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_8012F4E4:
    ctx->pc = 0x8012F4E4u;
    // 8012F4E4: cmpw    cr6, r29, r31
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

label_8012F4E8:
    ctx->pc = 0x8012F4E8u;
    // 8012F4E8: or   r26, r11, r11
    {
        ctx->gpr[26] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8012F4EC:
    ctx->pc = 0x8012F4ECu;
    // 8012F4EC: rlwinm r27, r0, 2, 0, 29
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8012F4F0:
    ctx->pc = 0x8012F4F0u;
    // 8012F4F0: or   r9, r31, r31
    {
        ctx->gpr[9] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012F4F4:
    ctx->pc = 0x8012F4F4u;
    // 8012F4F4: cmpw    cr7, r31, r29
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

label_8012F4F8:
    ctx->pc = 0x8012F4F8u;
    // 8012F4F8: mfctr    r10
    ctx->gpr[10] = ctx->ctr;

label_8012F4FC:
    ctx->pc = 0x8012F4FCu;
    // 8012F4FC: mfcr    r30
    ctx->gpr[30] = ctx->cr;

label_8012F500:
    ctx->pc = 0x8012F500u;
    // 8012F500: rlwinm r30, r30, 24, 0, 3
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 24u) & 0xF0000000u;
    }

label_8012F504:
    ctx->pc = 0x8012F504u;
    // 8012F504: bc    12, 2, 0x8012F518
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F518;
        }
    }

label_8012F508:
    loop_8012F508(ctx);
    if (ctx->pc == 0x8012F518u) goto label_8012F518;
    return;
label_8012F50C:
    ctx->pc = 0x8012F50Cu;
    // 8012F50C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F510:
    // 8012F510: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_8012F514:
    // 8012F514: bc    16, 0, 0x8012F508
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8012F508u;
                return;
            }
            goto label_8012F508;
        }
    }

label_8012F518:
    ctx->pc = 0x8012F518u;
    ctx->downcount -= 5;
    // 8012F518: lwz     r9, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012F51C:
    ctx->pc = 0x8012F51Cu;
    // 8012F51C: rlwinm r0, r10, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 2u) & 0xFFFFFFFCu;
    }

label_8012F520:
    ctx->pc = 0x8012F520u;
    // 8012F520: add   r3, r9, r0
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8012F524:
    ctx->pc = 0x8012F524u;
    // 8012F524: stw     r3, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8012F528:
    ctx->pc = 0x8012F528u;
    // 8012F528: bc    12, 30, 0x8012F538
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F538;
        }
    }

label_8012F52C:
    ctx->pc = 0x8012F52Cu;
    ctx->downcount -= 3;
    // 8012F52C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8012F530:
    ctx->pc = 0x8012F530u;
    // 8012F530: subf   r5, r29, r31
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8012F534:
    ctx->pc = 0x8012F534u;
    // 8012F534: bl      0x80297E3C
    {
            ctx->lr = 0x8012F538u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8012F538:
    ctx->pc = 0x8012F538u;
    ctx->downcount -= 6;
    // 8012F538: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F53C:
    ctx->pc = 0x8012F53Cu;
    // 8012F53C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8012F540:
    ctx->pc = 0x8012F540u;
    // 8012F540: mtcrf   0x80, r30
    ctx->cr = (ctx->cr & ~0xF0000000u) | (ctx->gpr[30] & 0xF0000000u);

label_8012F544:
    ctx->pc = 0x8012F544u;
    // 8012F544: add   r0, r0, r27
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8012F548:
    ctx->pc = 0x8012F548u;
    // 8012F548: stw     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F54C:
    ctx->pc = 0x8012F54Cu;
    // 8012F54C: bc    12, 2, 0x8012F684
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F684;
        }
    }

label_8012F550:
    ctx->pc = 0x8012F550u;
    ctx->downcount -= 1;
    // 8012F550: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F554:
    loop_8012F554(ctx);
    if (ctx->pc == 0x8012F564u) goto label_8012F564;
    return;
label_8012F558:
    // 8012F558: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_8012F55C:
    // 8012F55C: cmpw    r4, r31
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

label_8012F560:
    // 8012F560: bc    4, 2, 0x8012F554
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8012F554u;
                return;
            }
            goto label_8012F554;
        }
    }

label_8012F564:
    ctx->pc = 0x8012F564u;
    ctx->downcount -= 1;
    // 8012F564: b       0x8012F684
    {
            goto label_8012F684;
    }

label_8012F568:
    ctx->pc = 0x8012F568u;
    ctx->downcount -= 9;
    // 8012F568: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F56C:
    ctx->pc = 0x8012F56Cu;
    // 8012F56C: addi    r11, r1, 16
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(16);

label_8012F570:
    ctx->pc = 0x8012F570u;
    // 8012F570: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8012F574:
    ctx->pc = 0x8012F574u;
    // 8012F574: addi    r9, r1, 12
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(12);

label_8012F578:
    ctx->pc = 0x8012F578u;
    // 8012F578: subf   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8012F57C:
    ctx->pc = 0x8012F57Cu;
    // 8012F57C: srawi r3, r0, 2
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

label_8012F580:
    ctx->pc = 0x8012F580u;
    // 8012F580: cmplw   r3, r5
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

label_8012F584:
    ctx->pc = 0x8012F584u;
    // 8012F584: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8012F588:
    ctx->pc = 0x8012F588u;
    // 8012F588: bc    4, 0, 0x8012F590
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8012F590;
        }
    }

label_8012F58C:
    ctx->pc = 0x8012F58Cu;
    ctx->downcount -= 1;
    // 8012F58C: or   r9, r11, r11
    {
        ctx->gpr[9] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8012F590:
    ctx->pc = 0x8012F590u;
    ctx->downcount -= 3;
    // 8012F590: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F594:
    ctx->pc = 0x8012F594u;
    // 8012F594: add.   r0, r3, r0
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

label_8012F598:
    ctx->pc = 0x8012F598u;
    // 8012F598: bc    12, 2, 0x8012F5CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F5CC;
        }
    }

label_8012F59C:
    ctx->pc = 0x8012F59Cu;
    ctx->downcount -= 4;
    // 8012F59C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8012F5A0:
    ctx->pc = 0x8012F5A0u;
    // 8012F5A0: or   r27, r0, r0
    {
        ctx->gpr[27] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8012F5A4:
    ctx->pc = 0x8012F5A4u;
    // 8012F5A4: cmplwi  r0, 0x0080
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

label_8012F5A8:
    ctx->pc = 0x8012F5A8u;
    // 8012F5A8: bc    4, 1, 0x8012F5BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8012F5BC;
        }
    }

label_8012F5AC:
    ctx->pc = 0x8012F5ACu;
    ctx->downcount -= 2;
    // 8012F5AC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8012F5B0:
    ctx->pc = 0x8012F5B0u;
    // 8012F5B0: bl      0x80281C60
    {
            ctx->lr = 0x8012F5B4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8012F5B4:
    ctx->pc = 0x8012F5B4u;
    ctx->downcount -= 2;
    // 8012F5B4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012F5B8:
    ctx->pc = 0x8012F5B8u;
    // 8012F5B8: b       0x8012F5D4
    {
            goto label_8012F5D4;
    }

label_8012F5BC:
    ctx->pc = 0x8012F5BCu;
    ctx->downcount -= 2;
    // 8012F5BC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8012F5C0:
    ctx->pc = 0x8012F5C0u;
    // 8012F5C0: bl      0x80004024
    {
            ctx->lr = 0x8012F5C4u;
            ctx->pc = 0x80004024u;
            return;
    }

label_8012F5C4:
    ctx->pc = 0x8012F5C4u;
    ctx->downcount -= 2;
    // 8012F5C4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012F5C8:
    ctx->pc = 0x8012F5C8u;
    // 8012F5C8: b       0x8012F5D4
    {
            goto label_8012F5D4;
    }

label_8012F5CC:
    ctx->pc = 0x8012F5CCu;
    ctx->downcount -= 2;
    // 8012F5CC: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8012F5D0:
    ctx->pc = 0x8012F5D0u;
    // 8012F5D0: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_8012F5D4:
    ctx->pc = 0x8012F5D4u;
    ctx->downcount -= 3;
    // 8012F5D4: lwz     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8012F5D8:
    ctx->pc = 0x8012F5D8u;
    // 8012F5D8: cmpw    r29, r4
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

label_8012F5DC:
    ctx->pc = 0x8012F5DCu;
    // 8012F5DC: bc    12, 2, 0x8012F5F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F5F8;
        }
    }

label_8012F5E0:
    ctx->pc = 0x8012F5E0u;
    ctx->downcount -= 4;
    // 8012F5E0: subf   r30, r4, r29
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[29];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_8012F5E4:
    ctx->pc = 0x8012F5E4u;
    // 8012F5E4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012F5E8:
    ctx->pc = 0x8012F5E8u;
    // 8012F5E8: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012F5EC:
    ctx->pc = 0x8012F5ECu;
    // 8012F5EC: bl      0x80297E3C
    {
            ctx->lr = 0x8012F5F0u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8012F5F0:
    ctx->pc = 0x8012F5F0u;
    ctx->downcount -= 2;
    // 8012F5F0: add   r3, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8012F5F4:
    ctx->pc = 0x8012F5F4u;
    // 8012F5F4: b       0x8012F5FC
    {
            goto label_8012F5FC;
    }

label_8012F5F8:
    ctx->pc = 0x8012F5F8u;
    ctx->downcount -= 1;
    // 8012F5F8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012F5FC:
    ctx->pc = 0x8012F5FCu;
    ctx->downcount -= 5;
    // 8012F5FC: lwz     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F600:
    ctx->pc = 0x8012F600u;
    // 8012F600: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8012F604:
    ctx->pc = 0x8012F604u;
    // 8012F604: cmpwi   r0, 0
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

label_8012F608:
    ctx->pc = 0x8012F608u;
    // 8012F608: bc    12, 2, 0x8012F61C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F61C;
        }
    }

label_8012F60C:
    loop_8012F60C(ctx);
    if (ctx->pc == 0x8012F61Cu) goto label_8012F61C;
    return;
label_8012F610:
    ctx->pc = 0x8012F610u;
    // 8012F610: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F614:
    // 8012F614: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_8012F618:
    // 8012F618: bc    16, 0, 0x8012F60C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8012F60Cu;
                return;
            }
            goto label_8012F60C;
        }
    }

label_8012F61C:
    ctx->pc = 0x8012F61Cu;
    ctx->downcount -= 3;
    // 8012F61C: lwz     r30, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8012F620:
    ctx->pc = 0x8012F620u;
    // 8012F620: cmpw    r30, r29
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

label_8012F624:
    ctx->pc = 0x8012F624u;
    // 8012F624: bc    12, 2, 0x8012F640
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F640;
        }
    }

label_8012F628:
    ctx->pc = 0x8012F628u;
    ctx->downcount -= 4;
    // 8012F628: subf   r30, r29, r30
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_8012F62C:
    ctx->pc = 0x8012F62Cu;
    // 8012F62C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8012F630:
    ctx->pc = 0x8012F630u;
    // 8012F630: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012F634:
    ctx->pc = 0x8012F634u;
    // 8012F634: bl      0x80297E3C
    {
            ctx->lr = 0x8012F638u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8012F638:
    ctx->pc = 0x8012F638u;
    ctx->downcount -= 2;
    // 8012F638: add   r30, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_8012F63C:
    ctx->pc = 0x8012F63Cu;
    // 8012F63C: b       0x8012F644
    {
            goto label_8012F644;
    }

label_8012F640:
    ctx->pc = 0x8012F640u;
    ctx->downcount -= 1;
    // 8012F640: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012F644:
    ctx->pc = 0x8012F644u;
    ctx->downcount -= 6;
    // 8012F644: lwz     r3, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012F648:
    ctx->pc = 0x8012F648u;
    // 8012F648: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F64C:
    ctx->pc = 0x8012F64Cu;
    // 8012F64C: cmpwi   r3, 0
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

label_8012F650:
    ctx->pc = 0x8012F650u;
    // 8012F650: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8012F654:
    ctx->pc = 0x8012F654u;
    // 8012F654: srawi r0, r0, 2
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

label_8012F658:
    ctx->pc = 0x8012F658u;
    // 8012F658: bc    12, 2, 0x8012F674
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F674;
        }
    }

label_8012F65C:
    ctx->pc = 0x8012F65Cu;
    ctx->downcount -= 3;
    // 8012F65C: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8012F660:
    ctx->pc = 0x8012F660u;
    // 8012F660: cmplwi  r4, 0x0080
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

label_8012F664:
    ctx->pc = 0x8012F664u;
    // 8012F664: bc    4, 1, 0x8012F670
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8012F670;
        }
    }

label_8012F668:
    ctx->pc = 0x8012F668u;
    ctx->downcount -= 1;
    // 8012F668: bl      0x80281D80
    {
            ctx->lr = 0x8012F66Cu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_8012F66C:
    ctx->pc = 0x8012F66Cu;
    ctx->downcount -= 1;
    // 8012F66C: b       0x8012F674
    {
            goto label_8012F674;
    }

label_8012F670:
    ctx->pc = 0x8012F670u;
    ctx->downcount -= 1;
    // 8012F670: bl      0x8001D934
    {
            ctx->lr = 0x8012F674u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_8012F674:
    ctx->pc = 0x8012F674u;
    ctx->downcount -= 4;
    // 8012F674: add   r0, r27, r31
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8012F678:
    ctx->pc = 0x8012F678u;
    // 8012F678: stw     r31, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8012F67C:
    ctx->pc = 0x8012F67Cu;
    // 8012F67C: stw     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F680:
    ctx->pc = 0x8012F680u;
    // 8012F680: stw     r30, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8012F684:
    ctx->pc = 0x8012F684u;
    ctx->downcount -= 16;
    // 8012F684: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F688:
    ctx->pc = 0x8012F688u;
    // 8012F688: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012F68C:
    ctx->pc = 0x8012F68Cu;
    // 8012F68C: lmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8012F690:
    ctx->pc = 0x8012F690u;
    // 8012F690: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_8012F694:
    ctx->pc = 0x8012F694u;
    // 8012F694: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012F698:
    ctx->pc = 0x8012F698u;
    ctx->downcount -= 18;
    // 8012F698: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012F69C:
    ctx->pc = 0x8012F69Cu;
    // 8012F69C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012F6A0:
    ctx->pc = 0x8012F6A0u;
    // 8012F6A0: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8012F6A4:
    ctx->pc = 0x8012F6A4u;
    // 8012F6A4: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F6A8:
    ctx->pc = 0x8012F6A8u;
    // 8012F6A8: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012F6AC:
    ctx->pc = 0x8012F6ACu;
    // 8012F6AC: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8012F6B0:
    ctx->pc = 0x8012F6B0u;
    // 8012F6B0: cmpw    r28, r29
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8012F6B4:
    ctx->pc = 0x8012F6B4u;
    // 8012F6B4: bc    12, 2, 0x8012F7FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F7FC;
        }
    }

label_8012F6B8:
    ctx->pc = 0x8012F6B8u;
    ctx->downcount -= 10;
    // 8012F6B8: lwz     r27, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[27] = mem_read32(ctx, ea);
    }

label_8012F6BC:
    ctx->pc = 0x8012F6BCu;
    // 8012F6BC: lwz     r31, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8012F6C0:
    ctx->pc = 0x8012F6C0u;
    // 8012F6C0: lwz     r0, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F6C4:
    ctx->pc = 0x8012F6C4u;
    // 8012F6C4: lwz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012F6C8:
    ctx->pc = 0x8012F6C8u;
    // 8012F6C8: subf   r5, r31, r27
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8012F6CC:
    ctx->pc = 0x8012F6CCu;
    // 8012F6CC: srawi r30, r5, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[5];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[30] = value;
        } else if (sh > 31) {
            ctx->gpr[30] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[30] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8012F6D0:
    ctx->pc = 0x8012F6D0u;
    // 8012F6D0: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8012F6D4:
    ctx->pc = 0x8012F6D4u;
    // 8012F6D4: srawi r0, r0, 2
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

label_8012F6D8:
    ctx->pc = 0x8012F6D8u;
    // 8012F6D8: cmplw   r30, r0
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8012F6DC:
    ctx->pc = 0x8012F6DCu;
    // 8012F6DC: bc    4, 1, 0x8012F778
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8012F778;
        }
    }

label_8012F6E0:
    ctx->pc = 0x8012F6E0u;
    ctx->downcount -= 2;
    // 8012F6E0: cmpwi   r30, 0
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

label_8012F6E4:
    ctx->pc = 0x8012F6E4u;
    // 8012F6E4: bc    12, 2, 0x8012F718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F718;
        }
    }

label_8012F6E8:
    ctx->pc = 0x8012F6E8u;
    ctx->downcount -= 4;
    // 8012F6E8: rlwinm r0, r30, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 2u) & 0xFFFFFFFCu;
    }

label_8012F6EC:
    ctx->pc = 0x8012F6ECu;
    // 8012F6EC: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8012F6F0:
    ctx->pc = 0x8012F6F0u;
    // 8012F6F0: cmplwi  r0, 0x0080
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

label_8012F6F4:
    ctx->pc = 0x8012F6F4u;
    // 8012F6F4: bc    4, 1, 0x8012F708
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8012F708;
        }
    }

label_8012F6F8:
    ctx->pc = 0x8012F6F8u;
    ctx->downcount -= 2;
    // 8012F6F8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012F6FC:
    ctx->pc = 0x8012F6FCu;
    // 8012F6FC: bl      0x80281C60
    {
            ctx->lr = 0x8012F700u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8012F700:
    ctx->pc = 0x8012F700u;
    ctx->downcount -= 2;
    // 8012F700: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012F704:
    ctx->pc = 0x8012F704u;
    // 8012F704: b       0x8012F720
    {
            goto label_8012F720;
    }

label_8012F708:
    ctx->pc = 0x8012F708u;
    ctx->downcount -= 2;
    // 8012F708: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012F70C:
    ctx->pc = 0x8012F70Cu;
    // 8012F70C: bl      0x80004024
    {
            ctx->lr = 0x8012F710u;
            ctx->pc = 0x80004024u;
            return;
    }

label_8012F710:
    ctx->pc = 0x8012F710u;
    ctx->downcount -= 2;
    // 8012F710: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012F714:
    ctx->pc = 0x8012F714u;
    // 8012F714: b       0x8012F720
    {
            goto label_8012F720;
    }

label_8012F718:
    ctx->pc = 0x8012F718u;
    ctx->downcount -= 2;
    // 8012F718: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_8012F71C:
    ctx->pc = 0x8012F71Cu;
    // 8012F71C: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8012F720:
    ctx->pc = 0x8012F720u;
    ctx->downcount -= 2;
    // 8012F720: cmpw    r27, r31
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8012F724:
    ctx->pc = 0x8012F724u;
    // 8012F724: bc    12, 2, 0x8012F738
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F738;
        }
    }

label_8012F728:
    ctx->pc = 0x8012F728u;
    ctx->downcount -= 4;
    // 8012F728: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012F72C:
    ctx->pc = 0x8012F72Cu;
    // 8012F72C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8012F730:
    ctx->pc = 0x8012F730u;
    // 8012F730: subf   r5, r4, r27
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8012F734:
    ctx->pc = 0x8012F734u;
    // 8012F734: bl      0x80297E3C
    {
            ctx->lr = 0x8012F738u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8012F738:
    ctx->pc = 0x8012F738u;
    ctx->downcount -= 6;
    // 8012F738: lwz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012F73C:
    ctx->pc = 0x8012F73Cu;
    // 8012F73C: lwz     r0, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F740:
    ctx->pc = 0x8012F740u;
    // 8012F740: cmpwi   r3, 0
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

label_8012F744:
    ctx->pc = 0x8012F744u;
    // 8012F744: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8012F748:
    ctx->pc = 0x8012F748u;
    // 8012F748: srawi r0, r0, 2
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

label_8012F74C:
    ctx->pc = 0x8012F74Cu;
    // 8012F74C: bc    12, 2, 0x8012F768
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F768;
        }
    }

label_8012F750:
    ctx->pc = 0x8012F750u;
    ctx->downcount -= 3;
    // 8012F750: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8012F754:
    ctx->pc = 0x8012F754u;
    // 8012F754: cmplwi  r4, 0x0080
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

label_8012F758:
    ctx->pc = 0x8012F758u;
    // 8012F758: bc    4, 1, 0x8012F764
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8012F764;
        }
    }

label_8012F75C:
    ctx->pc = 0x8012F75Cu;
    ctx->downcount -= 1;
    // 8012F75C: bl      0x80281D80
    {
            ctx->lr = 0x8012F760u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_8012F760:
    ctx->pc = 0x8012F760u;
    ctx->downcount -= 1;
    // 8012F760: b       0x8012F768
    {
            goto label_8012F768;
    }

label_8012F764:
    ctx->pc = 0x8012F764u;
    ctx->downcount -= 1;
    // 8012F764: bl      0x8001D934
    {
            ctx->lr = 0x8012F768u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_8012F768:
    ctx->pc = 0x8012F768u;
    ctx->downcount -= 4;
    // 8012F768: add   r0, r28, r30
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8012F76C:
    ctx->pc = 0x8012F76Cu;
    // 8012F76C: stw     r28, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8012F770:
    ctx->pc = 0x8012F770u;
    // 8012F770: stw     r0, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F774:
    ctx->pc = 0x8012F774u;
    // 8012F774: b       0x8012F7F0
    {
            goto label_8012F7F0;
    }

label_8012F778:
    ctx->pc = 0x8012F778u;
    ctx->downcount -= 5;
    // 8012F778: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F77C:
    ctx->pc = 0x8012F77Cu;
    // 8012F77C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8012F780:
    ctx->pc = 0x8012F780u;
    // 8012F780: srawi r0, r0, 2
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

label_8012F784:
    ctx->pc = 0x8012F784u;
    // 8012F784: cmplw   r0, r30
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8012F788:
    ctx->pc = 0x8012F788u;
    // 8012F788: bc    12, 0, 0x8012F7A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F7A4;
        }
    }

label_8012F78C:
    ctx->pc = 0x8012F78Cu;
    ctx->downcount -= 2;
    // 8012F78C: cmpw    r27, r31
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8012F790:
    ctx->pc = 0x8012F790u;
    // 8012F790: bc    12, 2, 0x8012F79C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F79C;
        }
    }

label_8012F794:
    ctx->pc = 0x8012F794u;
    ctx->downcount -= 2;
    // 8012F794: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012F798:
    ctx->pc = 0x8012F798u;
    // 8012F798: bl      0x80297E3C
    {
            ctx->lr = 0x8012F79Cu;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8012F79C:
    ctx->pc = 0x8012F79Cu;
    ctx->downcount -= 2;
    // 8012F79C: rlwinm r30, r30, 2, 0, 29
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 2u) & 0xFFFFFFFCu;
    }

label_8012F7A0:
    ctx->pc = 0x8012F7A0u;
    // 8012F7A0: b       0x8012F7F0
    {
            goto label_8012F7F0;
    }

label_8012F7A4:
    ctx->pc = 0x8012F7A4u;
    ctx->downcount -= 4;
    // 8012F7A4: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8012F7A8:
    ctx->pc = 0x8012F7A8u;
    // 8012F7A8: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8012F7AC:
    ctx->pc = 0x8012F7ACu;
    // 8012F7AC: cmpw    r0, r31
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8012F7B0:
    ctx->pc = 0x8012F7B0u;
    // 8012F7B0: bc    12, 2, 0x8012F7C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F7C0;
        }
    }

label_8012F7B4:
    ctx->pc = 0x8012F7B4u;
    ctx->downcount -= 3;
    // 8012F7B4: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012F7B8:
    ctx->pc = 0x8012F7B8u;
    // 8012F7B8: subf   r5, r4, r0
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8012F7BC:
    ctx->pc = 0x8012F7BCu;
    // 8012F7BC: bl      0x80297E3C
    {
            ctx->lr = 0x8012F7C0u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8012F7C0:
    ctx->pc = 0x8012F7C0u;
    ctx->downcount -= 10;
    // 8012F7C0: lwz     r3, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012F7C4:
    ctx->pc = 0x8012F7C4u;
    // 8012F7C4: rlwinm r30, r30, 2, 0, 29
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 2u) & 0xFFFFFFFCu;
    }

label_8012F7C8:
    ctx->pc = 0x8012F7C8u;
    // 8012F7C8: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F7CC:
    ctx->pc = 0x8012F7CCu;
    // 8012F7CC: lwz     r9, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012F7D0:
    ctx->pc = 0x8012F7D0u;
    // 8012F7D0: subf   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8012F7D4:
    ctx->pc = 0x8012F7D4u;
    // 8012F7D4: lwz     r5, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8012F7D8:
    ctx->pc = 0x8012F7D8u;
    // 8012F7D8: rlwinm r0, r0, 0, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_8012F7DC:
    ctx->pc = 0x8012F7DCu;
    // 8012F7DC: add   r4, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8012F7E0:
    ctx->pc = 0x8012F7E0u;
    // 8012F7E0: cmpw    r5, r4
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8012F7E4:
    ctx->pc = 0x8012F7E4u;
    // 8012F7E4: bc    12, 2, 0x8012F7F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F7F0;
        }
    }

label_8012F7E8:
    ctx->pc = 0x8012F7E8u;
    ctx->downcount -= 2;
    // 8012F7E8: subf   r5, r4, r5
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8012F7EC:
    ctx->pc = 0x8012F7ECu;
    // 8012F7EC: bl      0x80297E3C
    {
            ctx->lr = 0x8012F7F0u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8012F7F0:
    ctx->pc = 0x8012F7F0u;
    ctx->downcount -= 3;
    // 8012F7F0: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F7F4:
    ctx->pc = 0x8012F7F4u;
    // 8012F7F4: add   r0, r0, r30
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8012F7F8:
    ctx->pc = 0x8012F7F8u;
    // 8012F7F8: stw     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F7FC:
    ctx->pc = 0x8012F7FCu;
    ctx->downcount -= 17;
    // 8012F7FC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8012F800:
    ctx->pc = 0x8012F800u;
    // 8012F800: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F804:
    ctx->pc = 0x8012F804u;
    // 8012F804: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012F808:
    ctx->pc = 0x8012F808u;
    // 8012F808: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8012F80C:
    ctx->pc = 0x8012F80Cu;
    // 8012F80C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8012F810:
    ctx->pc = 0x8012F810u;
    // 8012F810: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012F814:
    ctx->pc = 0x8012F814u;
    ctx->downcount -= 7;
    // 8012F814: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012F818:
    ctx->pc = 0x8012F818u;
    // 8012F818: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012F81C:
    ctx->pc = 0x8012F81Cu;
    // 8012F81C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F820:
    ctx->pc = 0x8012F820u;
    // 8012F820: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8012F824:
    ctx->pc = 0x8012F824u;
    // 8012F824: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_8012F828:
    ctx->pc = 0x8012F828u;
    // 8012F828: cmpw    r4, r0
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

label_8012F82C:
    ctx->pc = 0x8012F82Cu;
    // 8012F82C: bc    4, 2, 0x8012F928
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8012F928;
        }
    }

label_8012F830:
    ctx->pc = 0x8012F830u;
    ctx->downcount -= 2;
    // 8012F830: cmpwi   r3, 0
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

label_8012F834:
    ctx->pc = 0x8012F834u;
    // 8012F834: bc    12, 2, 0x8012F928
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F928;
        }
    }

label_8012F838:
    ctx->pc = 0x8012F838u;
    ctx->downcount -= 5;
    // 8012F838: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_8012F83C:
    ctx->pc = 0x8012F83Cu;
    // 8012F83C: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_8012F840:
    ctx->pc = 0x8012F840u;
    // 8012F840: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_8012F844:
    ctx->pc = 0x8012F844u;
    // 8012F844: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8012F848:
    ctx->pc = 0x8012F848u;
    // 8012F848: bl      0x80252AF0
    {
            ctx->lr = 0x8012F84Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F84C:
    ctx->pc = 0x8012F84Cu;
    ctx->downcount -= 5;
    // 8012F84C: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_8012F850:
    ctx->pc = 0x8012F850u;
    // 8012F850: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8012F854:
    ctx->pc = 0x8012F854u;
    // 8012F854: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_8012F858:
    ctx->pc = 0x8012F858u;
    // 8012F858: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8012F85C:
    ctx->pc = 0x8012F85Cu;
    // 8012F85C: bl      0x80252AF0
    {
            ctx->lr = 0x8012F860u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F860:
    ctx->pc = 0x8012F860u;
    ctx->downcount -= 5;
    // 8012F860: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_8012F864:
    ctx->pc = 0x8012F864u;
    // 8012F864: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_8012F868:
    ctx->pc = 0x8012F868u;
    // 8012F868: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_8012F86C:
    ctx->pc = 0x8012F86Cu;
    // 8012F86C: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_8012F870:
    ctx->pc = 0x8012F870u;
    // 8012F870: bl      0x80252AF0
    {
            ctx->lr = 0x8012F874u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F874:
    ctx->pc = 0x8012F874u;
    ctx->downcount -= 5;
    // 8012F874: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_8012F878:
    ctx->pc = 0x8012F878u;
    // 8012F878: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_8012F87C:
    ctx->pc = 0x8012F87Cu;
    // 8012F87C: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_8012F880:
    ctx->pc = 0x8012F880u;
    // 8012F880: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8012F884:
    ctx->pc = 0x8012F884u;
    // 8012F884: bl      0x80252AF0
    {
            ctx->lr = 0x8012F888u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F888:
    ctx->pc = 0x8012F888u;
    ctx->downcount -= 5;
    // 8012F888: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_8012F88C:
    ctx->pc = 0x8012F88Cu;
    // 8012F88C: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_8012F890:
    ctx->pc = 0x8012F890u;
    // 8012F890: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_8012F894:
    ctx->pc = 0x8012F894u;
    // 8012F894: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8012F898:
    ctx->pc = 0x8012F898u;
    // 8012F898: bl      0x80252AF0
    {
            ctx->lr = 0x8012F89Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F89C:
    ctx->pc = 0x8012F89Cu;
    ctx->downcount -= 5;
    // 8012F89C: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_8012F8A0:
    ctx->pc = 0x8012F8A0u;
    // 8012F8A0: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8012F8A4:
    ctx->pc = 0x8012F8A4u;
    // 8012F8A4: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_8012F8A8:
    ctx->pc = 0x8012F8A8u;
    // 8012F8A8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8012F8AC:
    ctx->pc = 0x8012F8ACu;
    // 8012F8AC: bl      0x80252AF0
    {
            ctx->lr = 0x8012F8B0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F8B0:
    ctx->pc = 0x8012F8B0u;
    ctx->downcount -= 5;
    // 8012F8B0: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_8012F8B4:
    ctx->pc = 0x8012F8B4u;
    // 8012F8B4: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8012F8B8:
    ctx->pc = 0x8012F8B8u;
    // 8012F8B8: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_8012F8BC:
    ctx->pc = 0x8012F8BCu;
    // 8012F8BC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8012F8C0:
    ctx->pc = 0x8012F8C0u;
    // 8012F8C0: bl      0x80252AF0
    {
            ctx->lr = 0x8012F8C4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F8C4:
    ctx->pc = 0x8012F8C4u;
    ctx->downcount -= 5;
    // 8012F8C4: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_8012F8C8:
    ctx->pc = 0x8012F8C8u;
    // 8012F8C8: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_8012F8CC:
    ctx->pc = 0x8012F8CCu;
    // 8012F8CC: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_8012F8D0:
    ctx->pc = 0x8012F8D0u;
    // 8012F8D0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8012F8D4:
    ctx->pc = 0x8012F8D4u;
    // 8012F8D4: bl      0x80252AF0
    {
            ctx->lr = 0x8012F8D8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F8D8:
    ctx->pc = 0x8012F8D8u;
    ctx->downcount -= 5;
    // 8012F8D8: lis     r3, 25197
    ctx->gpr[3] = ((u32)(s32)(25197) << 16);

label_8012F8DC:
    ctx->pc = 0x8012F8DCu;
    // 8012F8DC: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_8012F8E0:
    ctx->pc = 0x8012F8E0u;
    // 8012F8E0: ori     r3, r3, 0x7368
    ctx->gpr[3] = ctx->gpr[3] | 0x7368u;

label_8012F8E4:
    ctx->pc = 0x8012F8E4u;
    // 8012F8E4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8012F8E8:
    ctx->pc = 0x8012F8E8u;
    // 8012F8E8: bl      0x80252AF0
    {
            ctx->lr = 0x8012F8ECu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F8EC:
    ctx->pc = 0x8012F8ECu;
    ctx->downcount -= 5;
    // 8012F8EC: lis     r3, 25199
    ctx->gpr[3] = ((u32)(s32)(25199) << 16);

label_8012F8F0:
    ctx->pc = 0x8012F8F0u;
    // 8012F8F0: li      r4, 63
    ctx->gpr[4] = (u32)(s32)(63);

label_8012F8F4:
    ctx->pc = 0x8012F8F4u;
    // 8012F8F4: ori     r3, r3, 0x6479
    ctx->gpr[3] = ctx->gpr[3] | 0x6479u;

label_8012F8F8:
    ctx->pc = 0x8012F8F8u;
    // 8012F8F8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8012F8FC:
    ctx->pc = 0x8012F8FCu;
    // 8012F8FC: bl      0x80252AF0
    {
            ctx->lr = 0x8012F900u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F900:
    ctx->pc = 0x8012F900u;
    ctx->downcount -= 5;
    // 8012F900: lis     r3, 25185
    ctx->gpr[3] = ((u32)(s32)(25185) << 16);

label_8012F904:
    ctx->pc = 0x8012F904u;
    // 8012F904: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8012F908:
    ctx->pc = 0x8012F908u;
    // 8012F908: ori     r3, r3, 0x6E6D
    ctx->gpr[3] = ctx->gpr[3] | 0x6E6Du;

label_8012F90C:
    ctx->pc = 0x8012F90Cu;
    // 8012F90C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8012F910:
    ctx->pc = 0x8012F910u;
    // 8012F910: bl      0x80252AF0
    {
            ctx->lr = 0x8012F914u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F914:
    ctx->pc = 0x8012F914u;
    ctx->downcount -= 5;
    // 8012F914: lis     r3, 27749
    ctx->gpr[3] = ((u32)(s32)(27749) << 16);

label_8012F918:
    ctx->pc = 0x8012F918u;
    // 8012F918: li      r4, 86
    ctx->gpr[4] = (u32)(s32)(86);

label_8012F91C:
    ctx->pc = 0x8012F91Cu;
    // 8012F91C: ori     r3, r3, 0x766C
    ctx->gpr[3] = ctx->gpr[3] | 0x766Cu;

label_8012F920:
    ctx->pc = 0x8012F920u;
    // 8012F920: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8012F924:
    ctx->pc = 0x8012F924u;
    // 8012F924: bl      0x80252AF0
    {
            ctx->lr = 0x8012F928u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8012F928:
    ctx->pc = 0x8012F928u;
    ctx->downcount -= 5;
    // 8012F928: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F92C:
    ctx->pc = 0x8012F92Cu;
    // 8012F92C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012F930:
    ctx->pc = 0x8012F930u;
    // 8012F930: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8012F934:
    ctx->pc = 0x8012F934u;
    // 8012F934: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012F938:
    ctx->pc = 0x8012F938u;
    ctx->downcount -= 31;
    // 8012F938: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012F93C:
    ctx->pc = 0x8012F93Cu;
    // 8012F93C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012F940:
    ctx->pc = 0x8012F940u;
    // 8012F940: stmw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8012F944:
    ctx->pc = 0x8012F944u;
    // 8012F944: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F948:
    ctx->pc = 0x8012F948u;
    // 8012F948: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F94C:
    ctx->pc = 0x8012F94Cu;
    // 8012F94C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012F950:
    ctx->pc = 0x8012F950u;
    // 8012F950: addi    r28, r4, 8
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(8);

label_8012F954:
    ctx->pc = 0x8012F954u;
    // 8012F954: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8012F958:
    ctx->pc = 0x8012F958u;
    // 8012F958: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F95C:
    ctx->pc = 0x8012F95Cu;
    // 8012F95C: addi    r31, r29, 8
    ctx->gpr[31] = ctx->gpr[29] + (u32)(s32)(8);

label_8012F960:
    ctx->pc = 0x8012F960u;
    // 8012F960: addi    r10, r31, 8
    ctx->gpr[10] = ctx->gpr[31] + (u32)(s32)(8);

label_8012F964:
    ctx->pc = 0x8012F964u;
    // 8012F964: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F968:
    ctx->pc = 0x8012F968u;
    // 8012F968: stw     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F96C:
    ctx->pc = 0x8012F96Cu;
    // 8012F96C: lwz     r11, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8012F970:
    ctx->pc = 0x8012F970u;
    // 8012F970: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F974:
    ctx->pc = 0x8012F974u;
    // 8012F974: stw     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8012F978:
    ctx->pc = 0x8012F978u;
    // 8012F978: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8012F97C:
    ctx->pc = 0x8012F97Cu;
    // 8012F97C: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8012F980:
    ctx->pc = 0x8012F980u;
    // 8012F980: srawi. r0, r0, 2
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
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8012F984:
    ctx->pc = 0x8012F984u;
    // 8012F984: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8012F988:
    ctx->pc = 0x8012F988u;
    // 8012F988: bc    12, 2, 0x8012F9B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F9B4;
        }
    }

label_8012F98C:
    ctx->pc = 0x8012F98Cu;
    ctx->downcount -= 4;
    // 8012F98C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8012F990:
    ctx->pc = 0x8012F990u;
    // 8012F990: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8012F994:
    ctx->pc = 0x8012F994u;
    // 8012F994: cmplwi  r0, 0x0080
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

label_8012F998:
    ctx->pc = 0x8012F998u;
    // 8012F998: bc    4, 1, 0x8012F9A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8012F9A8;
        }
    }

label_8012F99C:
    ctx->pc = 0x8012F99Cu;
    ctx->downcount -= 2;
    // 8012F99C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012F9A0:
    ctx->pc = 0x8012F9A0u;
    // 8012F9A0: bl      0x80281C60
    {
            ctx->lr = 0x8012F9A4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8012F9A4:
    ctx->pc = 0x8012F9A4u;
    ctx->downcount -= 1;
    // 8012F9A4: b       0x8012F9BC
    {
            goto label_8012F9BC;
    }

label_8012F9A8:
    ctx->pc = 0x8012F9A8u;
    ctx->downcount -= 2;
    // 8012F9A8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012F9AC:
    ctx->pc = 0x8012F9ACu;
    // 8012F9AC: bl      0x80004024
    {
            ctx->lr = 0x8012F9B0u;
            ctx->pc = 0x80004024u;
            return;
    }

label_8012F9B0:
    ctx->pc = 0x8012F9B0u;
    ctx->downcount -= 1;
    // 8012F9B0: b       0x8012F9BC
    {
            goto label_8012F9BC;
    }

label_8012F9B4:
    ctx->pc = 0x8012F9B4u;
    ctx->downcount -= 2;
    // 8012F9B4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8012F9B8:
    ctx->pc = 0x8012F9B8u;
    // 8012F9B8: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8012F9BC:
    ctx->pc = 0x8012F9BCu;
    ctx->downcount -= 8;
    // 8012F9BC: add   r0, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8012F9C0:
    ctx->pc = 0x8012F9C0u;
    // 8012F9C0: stw     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8012F9C4:
    ctx->pc = 0x8012F9C4u;
    // 8012F9C4: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012F9C8:
    ctx->pc = 0x8012F9C8u;
    // 8012F9C8: stw     r3, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8012F9CC:
    ctx->pc = 0x8012F9CCu;
    // 8012F9CC: lwz     r30, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8012F9D0:
    ctx->pc = 0x8012F9D0u;
    // 8012F9D0: lwz     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8012F9D4:
    ctx->pc = 0x8012F9D4u;
    // 8012F9D4: cmpw    r30, r4
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

label_8012F9D8:
    ctx->pc = 0x8012F9D8u;
    // 8012F9D8: bc    12, 2, 0x8012F9EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012F9EC;
        }
    }

label_8012F9DC:
    ctx->pc = 0x8012F9DCu;
    ctx->downcount -= 3;
    // 8012F9DC: subf   r30, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_8012F9E0:
    ctx->pc = 0x8012F9E0u;
    // 8012F9E0: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012F9E4:
    ctx->pc = 0x8012F9E4u;
    // 8012F9E4: bl      0x80297E3C
    {
            ctx->lr = 0x8012F9E8u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8012F9E8:
    ctx->pc = 0x8012F9E8u;
    ctx->downcount -= 1;
    // 8012F9E8: add   r3, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8012F9EC:
    ctx->pc = 0x8012F9ECu;
    ctx->downcount -= 18;
    // 8012F9EC: stw     r3, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8012F9F0:
    ctx->pc = 0x8012F9F0u;
    // 8012F9F0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8012F9F4:
    ctx->pc = 0x8012F9F4u;
    // 8012F9F4: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012F9F8:
    ctx->pc = 0x8012F9F8u;
    // 8012F9F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012F9FC:
    ctx->pc = 0x8012F9FCu;
    // 8012F9FC: lmw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8012FA00:
    ctx->pc = 0x8012FA00u;
    // 8012FA00: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8012FA04:
    ctx->pc = 0x8012FA04u;
    // 8012FA04: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FA08:
    ctx->pc = 0x8012FA08u;
    ctx->downcount -= 2;
    // 8012FA08: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8012FA0C:
    ctx->pc = 0x8012FA0Cu;
    // 8012FA0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FA10:
    ctx->pc = 0x8012FA10u;
    ctx->downcount -= 18;
    // 8012FA10: stwu     r1, -152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-152);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012FA14:
    ctx->pc = 0x8012FA14u;
    // 8012FA14: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012FA18:
    ctx->pc = 0x8012FA18u;
    // 8012FA18: stw     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8012FA1C:
    ctx->pc = 0x8012FA1Cu;
    // 8012FA1C: stw     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FA20:
    ctx->pc = 0x8012FA20u;
    // 8012FA20: lis     r12, 512
    ctx->gpr[12] = ((u32)(s32)(512) << 16);

label_8012FA24:
    ctx->pc = 0x8012FA24u;
    // 8012FA24: addi    r0, r1, 160
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(160);

label_8012FA28:
    ctx->pc = 0x8012FA28u;
    // 8012FA28: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_8012FA2C:
    ctx->pc = 0x8012FA2Cu;
    // 8012FA2C: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FA30:
    ctx->pc = 0x8012FA30u;
    // 8012FA30: stw     r11, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8012FA34:
    ctx->pc = 0x8012FA34u;
    // 8012FA34: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FA38:
    ctx->pc = 0x8012FA38u;
    // 8012FA38: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8012FA3C:
    ctx->pc = 0x8012FA3Cu;
    // 8012FA3C: stw     r6, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8012FA40:
    ctx->pc = 0x8012FA40u;
    // 8012FA40: stw     r7, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8012FA44:
    ctx->pc = 0x8012FA44u;
    // 8012FA44: stw     r8, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8012FA48:
    ctx->pc = 0x8012FA48u;
    // 8012FA48: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8012FA4C:
    ctx->pc = 0x8012FA4Cu;
    // 8012FA4C: stw     r10, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8012FA50:
    ctx->pc = 0x8012FA50u;
    // 8012FA50: stw     r12, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8012FA54:
    ctx->pc = 0x8012FA54u;
    // 8012FA54: bc    4, 6, 0x8012FA78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x02000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8012FA78;
        }
    }

label_8012FA58:
    ctx->pc = 0x8012FA58u;
    ctx->downcount -= 8;
    // 8012FA58: stfd     f1, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8012FA58u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_8012FA5C:
    ctx->pc = 0x8012FA5Cu;
    // 8012FA5C: stfd     f2, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x8012FA5Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_8012FA60:
    ctx->pc = 0x8012FA60u;
    // 8012FA60: stfd     f3, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x8012FA60u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_8012FA64:
    ctx->pc = 0x8012FA64u;
    // 8012FA64: stfd     f4, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8012FA64u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_8012FA68:
    ctx->pc = 0x8012FA68u;
    // 8012FA68: stfd     f5, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8012FA68u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_8012FA6C:
    ctx->pc = 0x8012FA6Cu;
    // 8012FA6C: stfd     f6, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8012FA6Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_8012FA70:
    ctx->pc = 0x8012FA70u;
    // 8012FA70: stfd     f7, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8012FA70u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_8012FA74:
    ctx->pc = 0x8012FA74u;
    // 8012FA74: stfd     f8, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8012FA74u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
    }

label_8012FA78:
    ctx->pc = 0x8012FA78u;
    ctx->downcount -= 12;
    // 8012FA78: addi    r11, r1, 128
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(128);

label_8012FA7C:
    ctx->pc = 0x8012FA7Cu;
    // 8012FA7C: addi    r9, r1, 112
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(112);

label_8012FA80:
    ctx->pc = 0x8012FA80u;
    // 8012FA80: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FA84:
    ctx->pc = 0x8012FA84u;
    // 8012FA84: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8012FA88:
    ctx->pc = 0x8012FA88u;
    // 8012FA88: lwz     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8012FA8C:
    ctx->pc = 0x8012FA8Cu;
    // 8012FA8C: or   r6, r9, r9
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8012FA90:
    ctx->pc = 0x8012FA90u;
    // 8012FA90: stw     r12, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8012FA94:
    ctx->pc = 0x8012FA94u;
    // 8012FA94: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012FA98:
    ctx->pc = 0x8012FA98u;
    // 8012FA98: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FA9C:
    ctx->pc = 0x8012FA9Cu;
    // 8012FA9C: li      r4, 260
    ctx->gpr[4] = (u32)(s32)(260);

label_8012FAA0:
    ctx->pc = 0x8012FAA0u;
    // 8012FAA0: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8012FAA4:
    ctx->pc = 0x8012FAA4u;
    // 8012FAA4: bl      0x80296720
    {
            ctx->lr = 0x8012FAA8u;
            ctx->pc = 0x80296720u;
            return;
    }

label_8012FAA8:
    ctx->pc = 0x8012FAA8u;
    ctx->downcount -= 8;
    // 8012FAA8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8012FAAC:
    ctx->pc = 0x8012FAACu;
    // 8012FAAC: stb     r0, 259(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(259);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8012FAB0:
    ctx->pc = 0x8012FAB0u;
    // 8012FAB0: lwz     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FAB4:
    ctx->pc = 0x8012FAB4u;
    // 8012FAB4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FAB8:
    ctx->pc = 0x8012FAB8u;
    // 8012FAB8: lwz     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8012FABC:
    ctx->pc = 0x8012FABCu;
    // 8012FABC: addi    r1, r1, 152
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(152);

label_8012FAC0:
    ctx->pc = 0x8012FAC0u;
    // 8012FAC0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FAC4:
    ctx->pc = 0x8012FAC4u;
    ctx->downcount -= 20;
    // 8012FAC4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012FAC8:
    ctx->pc = 0x8012FAC8u;
    // 8012FAC8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012FACC:
    ctx->pc = 0x8012FACCu;
    // 8012FACC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8012FAD0:
    ctx->pc = 0x8012FAD0u;
    // 8012FAD0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FAD4:
    ctx->pc = 0x8012FAD4u;
    // 8012FAD4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8012FAD8:
    ctx->pc = 0x8012FAD8u;
    // 8012FAD8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FADC:
    ctx->pc = 0x8012FADCu;
    // 8012FADC: addi    r9, r9, 17512
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17512);

label_8012FAE0:
    ctx->pc = 0x8012FAE0u;
    // 8012FAE0: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8012FAE4:
    ctx->pc = 0x8012FAE4u;
    // 8012FAE4: stw     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8012FAE8:
    ctx->pc = 0x8012FAE8u;
    // 8012FAE8: bl      0x8012E2DC
    {
            ctx->lr = 0x8012FAECu;
            ctx->pc = 0x8012E2DCu;
            return;
    }

label_8012FAEC:
    ctx->pc = 0x8012FAECu;
    ctx->downcount -= 2;
    // 8012FAEC: lwz     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FAF0:
    ctx->pc = 0x8012FAF0u;
    // 8012FAF0: bl      0x801B1564
    {
            ctx->lr = 0x8012FAF4u;
            ctx->pc = 0x801B1564u;
            return;
    }

label_8012FAF4:
    ctx->pc = 0x8012FAF4u;
    ctx->downcount -= 2;
    // 8012FAF4: cmpwi   r3, 0
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

label_8012FAF8:
    ctx->pc = 0x8012FAF8u;
    // 8012FAF8: bc    12, 2, 0x8012FB30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FB30;
        }
    }

label_8012FAFC:
    ctx->pc = 0x8012FAFCu;
    ctx->downcount -= 2;
    // 8012FAFC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012FB00:
    ctx->pc = 0x8012FB00u;
    // 8012FB00: bl      0x800FBC64
    {
            ctx->lr = 0x8012FB04u;
            ctx->pc = 0x800FBC64u;
            return;
    }

label_8012FB04:
    ctx->pc = 0x8012FB04u;
    ctx->downcount -= 2;
    // 8012FB04: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012FB08:
    ctx->pc = 0x8012FB08u;
    // 8012FB08: bl      0x800FBD00
    {
            ctx->lr = 0x8012FB0Cu;
            ctx->pc = 0x800FBD00u;
            return;
    }

label_8012FB0C:
    ctx->pc = 0x8012FB0Cu;
    ctx->downcount -= 1;
    // 8012FB0C: bl      0x8019D2B0
    {
            ctx->lr = 0x8012FB10u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_8012FB10:
    ctx->pc = 0x8012FB10u;
    ctx->downcount -= 2;
    // 8012FB10: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8012FB14:
    ctx->pc = 0x8012FB14u;
    // 8012FB14: bl      0x8019ADA4
    {
            ctx->lr = 0x8012FB18u;
            ctx->pc = 0x8019ADA4u;
            return;
    }

label_8012FB18:
    ctx->pc = 0x8012FB18u;
    ctx->downcount -= 3;
    // 8012FB18: lwz     r0, 388(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(388);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FB1C:
    ctx->pc = 0x8012FB1Cu;
    // 8012FB1C: cmpwi   r0, 4
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8012FB20:
    ctx->pc = 0x8012FB20u;
    // 8012FB20: bc    4, 2, 0x8012FB3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8012FB3C;
        }
    }

label_8012FB24:
    ctx->pc = 0x8012FB24u;
    ctx->downcount -= 1;
    // 8012FB24: bl      0x80219CE4
    {
            ctx->lr = 0x8012FB28u;
            ctx->pc = 0x80219CE4u;
            return;
    }

label_8012FB28:
    ctx->pc = 0x8012FB28u;
    ctx->downcount -= 1;
    // 8012FB28: bl      0x8021D830
    {
            ctx->lr = 0x8012FB2Cu;
            ctx->pc = 0x8021D830u;
            return;
    }

label_8012FB2C:
    ctx->pc = 0x8012FB2Cu;
    ctx->downcount -= 1;
    // 8012FB2C: b       0x8012FB3C
    {
            goto label_8012FB3C;
    }

label_8012FB30:
    ctx->pc = 0x8012FB30u;
    ctx->downcount -= 1;
    // 8012FB30: bl      0x8019D2B0
    {
            ctx->lr = 0x8012FB34u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_8012FB34:
    ctx->pc = 0x8012FB34u;
    ctx->downcount -= 2;
    // 8012FB34: lwz     r4, 728(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(728);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8012FB38:
    ctx->pc = 0x8012FB38u;
    // 8012FB38: bl      0x8019AC1C
    {
            ctx->lr = 0x8012FB3Cu;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_8012FB3C:
    ctx->pc = 0x8012FB3Cu;
    ctx->downcount -= 3;
    // 8012FB3C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012FB40:
    ctx->pc = 0x8012FB40u;
    // 8012FB40: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012FB44:
    ctx->pc = 0x8012FB44u;
    // 8012FB44: bl      0x8015AE74
    {
            ctx->lr = 0x8012FB48u;
            ctx->pc = 0x8015AE74u;
            return;
    }

label_8012FB48:
    ctx->pc = 0x8012FB48u;
    ctx->downcount -= 16;
    // 8012FB48: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FB4C:
    ctx->pc = 0x8012FB4Cu;
    // 8012FB4C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FB50:
    ctx->pc = 0x8012FB50u;
    // 8012FB50: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8012FB54:
    ctx->pc = 0x8012FB54u;
    // 8012FB54: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8012FB58:
    ctx->pc = 0x8012FB58u;
    // 8012FB58: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FB5C:
    ctx->pc = 0x8012FB5Cu;
    ctx->downcount -= 6;
    // 8012FB5C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012FB60:
    ctx->pc = 0x8012FB60u;
    // 8012FB60: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012FB64:
    ctx->pc = 0x8012FB64u;
    // 8012FB64: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8012FB68:
    ctx->pc = 0x8012FB68u;
    // 8012FB68: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FB6C:
    ctx->pc = 0x8012FB6Cu;
    // 8012FB6C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FB70:
    ctx->pc = 0x8012FB70u;
    // 8012FB70: bl      0x8015E34C
    {
            ctx->lr = 0x8012FB74u;
            ctx->pc = 0x8015E34Cu;
            return;
    }

label_8012FB74:
    ctx->pc = 0x8012FB74u;
    ctx->downcount -= 2;
    // 8012FB74: lwz     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FB78:
    ctx->pc = 0x8012FB78u;
    // 8012FB78: bl      0x801B1564
    {
            ctx->lr = 0x8012FB7Cu;
            ctx->pc = 0x801B1564u;
            return;
    }

label_8012FB7C:
    ctx->pc = 0x8012FB7Cu;
    ctx->downcount -= 2;
    // 8012FB7C: cmpwi   r3, 0
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

label_8012FB80:
    ctx->pc = 0x8012FB80u;
    // 8012FB80: bc    12, 2, 0x8012FB9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FB9C;
        }
    }

label_8012FB84:
    ctx->pc = 0x8012FB84u;
    ctx->downcount -= 7;
    // 8012FB84: lwz     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012FB88:
    ctx->pc = 0x8012FB88u;
    // 8012FB88: lha     r3, 136(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(136);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8012FB8C:
    ctx->pc = 0x8012FB8Cu;
    // 8012FB8C: lwz     r0, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FB90:
    ctx->pc = 0x8012FB90u;
    // 8012FB90: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8012FB94:
    ctx->pc = 0x8012FB94u;
    // 8012FB94: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FB98:
    ctx->pc = 0x8012FB98u;
    // 8012FB98: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8012FB9Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FB9C:
    ctx->pc = 0x8012FB9Cu;
    ctx->downcount -= 6;
    // 8012FB9C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FBA0:
    ctx->pc = 0x8012FBA0u;
    // 8012FBA0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FBA4:
    ctx->pc = 0x8012FBA4u;
    // 8012FBA4: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8012FBA8:
    ctx->pc = 0x8012FBA8u;
    // 8012FBA8: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8012FBAC:
    ctx->pc = 0x8012FBACu;
    // 8012FBAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FBB0:
    ctx->pc = 0x8012FBB0u;
    ctx->downcount -= 21;
    // 8012FBB0: stwu     r1, -288(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-288);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012FBB4:
    ctx->pc = 0x8012FBB4u;
    // 8012FBB4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012FBB8:
    ctx->pc = 0x8012FBB8u;
    // 8012FBB8: stmw     r29, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8012FBBC:
    ctx->pc = 0x8012FBBCu;
    // 8012FBBC: stw     r0, 292(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(292);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FBC0:
    ctx->pc = 0x8012FBC0u;
    // 8012FBC0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8012FBC4:
    ctx->pc = 0x8012FBC4u;
    // 8012FBC4: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_8012FBC8:
    ctx->pc = 0x8012FBC8u;
    // 8012FBC8: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FBCC:
    ctx->pc = 0x8012FBCCu;
    // 8012FBCC: addi    r31, r1, 8
    ctx->gpr[31] = ctx->gpr[1] + (u32)(s32)(8);

label_8012FBD0:
    ctx->pc = 0x8012FBD0u;
    // 8012FBD0: stb     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8012FBD4:
    ctx->pc = 0x8012FBD4u;
    // 8012FBD4: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_8012FBD8:
    ctx->pc = 0x8012FBD8u;
    // 8012FBD8: bl      0x80100A40
    {
            ctx->lr = 0x8012FBDCu;
            ctx->pc = 0x80100A40u;
            return;
    }

label_8012FBDC:
    ctx->pc = 0x8012FBDCu;
    ctx->downcount -= 3;
    // 8012FBDC: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FBE0:
    ctx->pc = 0x8012FBE0u;
    // 8012FBE0: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_8012FBE4:
    ctx->pc = 0x8012FBE4u;
    // 8012FBE4: bl      0x80100368
    {
            ctx->lr = 0x8012FBE8u;
            ctx->pc = 0x80100368u;
            return;
    }

label_8012FBE8:
    ctx->pc = 0x8012FBE8u;
    ctx->downcount -= 6;
    // 8012FBE8: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FBEC:
    ctx->pc = 0x8012FBECu;
    // 8012FBEC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8012FBF0:
    ctx->pc = 0x8012FBF0u;
    // 8012FBF0: addi    r4, r4, 16824
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(16824);

label_8012FBF4:
    ctx->pc = 0x8012FBF4u;
    // 8012FBF4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012FBF8:
    ctx->pc = 0x8012FBF8u;
    // 8012FBF8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8012FBFC:
    ctx->pc = 0x8012FBFCu;
    // 8012FBFC: bl      0x8009258C
    {
            ctx->lr = 0x8012FC00u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_8012FC00:
    ctx->pc = 0x8012FC00u;
    ctx->downcount -= 2;
    // 8012FC00: lwz     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FC04:
    ctx->pc = 0x8012FC04u;
    // 8012FC04: bl      0x801B1564
    {
            ctx->lr = 0x8012FC08u;
            ctx->pc = 0x801B1564u;
            return;
    }

label_8012FC08:
    ctx->pc = 0x8012FC08u;
    ctx->downcount -= 2;
    // 8012FC08: cmpwi   r3, 0
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

label_8012FC0C:
    ctx->pc = 0x8012FC0Cu;
    // 8012FC0C: bc    12, 2, 0x8012FC20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FC20;
        }
    }

label_8012FC10:
    ctx->pc = 0x8012FC10u;
    ctx->downcount -= 1;
    // 8012FC10: bl      0x8019D2B0
    {
            ctx->lr = 0x8012FC14u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_8012FC14:
    ctx->pc = 0x8012FC14u;
    ctx->downcount -= 2;
    // 8012FC14: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012FC18:
    ctx->pc = 0x8012FC18u;
    // 8012FC18: bl      0x8019A92C
    {
            ctx->lr = 0x8012FC1Cu;
            ctx->pc = 0x8019A92Cu;
            return;
    }

label_8012FC1C:
    ctx->pc = 0x8012FC1Cu;
    ctx->downcount -= 1;
    // 8012FC1C: b       0x8012FC34
    {
            goto label_8012FC34;
    }

label_8012FC20:
    ctx->pc = 0x8012FC20u;
    ctx->downcount -= 1;
    // 8012FC20: bl      0x8019D2B0
    {
            ctx->lr = 0x8012FC24u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_8012FC24:
    ctx->pc = 0x8012FC24u;
    ctx->downcount -= 3;
    // 8012FC24: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012FC28:
    ctx->pc = 0x8012FC28u;
    // 8012FC28: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8012FC2C:
    ctx->pc = 0x8012FC2Cu;
    // 8012FC2C: bl      0x8019A70C
    {
            ctx->lr = 0x8012FC30u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_8012FC30:
    ctx->pc = 0x8012FC30u;
    ctx->downcount -= 1;
    // 8012FC30: stw     r3, 728(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(728);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8012FC34:
    ctx->pc = 0x8012FC34u;
    ctx->downcount -= 16;
    // 8012FC34: lwz     r0, 292(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(292);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FC38:
    ctx->pc = 0x8012FC38u;
    // 8012FC38: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FC3C:
    ctx->pc = 0x8012FC3Cu;
    // 8012FC3C: lmw     r29, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8012FC40:
    ctx->pc = 0x8012FC40u;
    // 8012FC40: addi    r1, r1, 288
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(288);

label_8012FC44:
    ctx->pc = 0x8012FC44u;
    // 8012FC44: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FC48:
    ctx->pc = 0x8012FC48u;
    ctx->downcount -= 16;
    // 8012FC48: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012FC4C:
    ctx->pc = 0x8012FC4Cu;
    // 8012FC4C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012FC50:
    ctx->pc = 0x8012FC50u;
    // 8012FC50: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8012FC54:
    ctx->pc = 0x8012FC54u;
    // 8012FC54: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FC58:
    ctx->pc = 0x8012FC58u;
    // 8012FC58: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FC5C:
    ctx->pc = 0x8012FC5Cu;
    // 8012FC5C: bl      0x8015BA2C
    {
            ctx->lr = 0x8012FC60u;
            ctx->pc = 0x8015BA2Cu;
            return;
    }

label_8012FC60:
    ctx->pc = 0x8012FC60u;
    ctx->downcount -= 4;
    // 8012FC60: lwz     r0, -31304(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31304);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FC64:
    ctx->pc = 0x8012FC64u;
    // 8012FC64: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FC68:
    ctx->pc = 0x8012FC68u;
    // 8012FC68: cmpwi   r0, 0
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

label_8012FC6C:
    ctx->pc = 0x8012FC6Cu;
    // 8012FC6C: bc    12, 2, 0x8012FCA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FCA8;
        }
    }

label_8012FC70:
    ctx->pc = 0x8012FC70u;
    ctx->downcount -= 2;
    // 8012FC70: lwz     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FC74:
    ctx->pc = 0x8012FC74u;
    // 8012FC74: bl      0x801B1564
    {
            ctx->lr = 0x8012FC78u;
            ctx->pc = 0x801B1564u;
            return;
    }

label_8012FC78:
    ctx->pc = 0x8012FC78u;
    ctx->downcount -= 2;
    // 8012FC78: cmpwi   r3, 0
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

label_8012FC7C:
    ctx->pc = 0x8012FC7Cu;
    // 8012FC7C: bc    12, 2, 0x8012FCA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FCA8;
        }
    }

label_8012FC80:
    ctx->pc = 0x8012FC80u;
    ctx->downcount -= 3;
    // 8012FC80: lwz     r0, 860(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(860);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FC84:
    ctx->pc = 0x8012FC84u;
    // 8012FC84: cmpwi   r0, 0
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

label_8012FC88:
    ctx->pc = 0x8012FC88u;
    // 8012FC88: bc    12, 2, 0x8012FCA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FCA8;
        }
    }

label_8012FC8C:
    ctx->pc = 0x8012FC8Cu;
    ctx->downcount -= 7;
    // 8012FC8C: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012FC90:
    ctx->pc = 0x8012FC90u;
    // 8012FC90: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_8012FC94:
    ctx->pc = 0x8012FC94u;
    // 8012FC94: stw     r0, 388(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(388);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FC98:
    ctx->pc = 0x8012FC98u;
    // 8012FC98: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8012FC9C:
    ctx->pc = 0x8012FC9Cu;
    // 8012FC9C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8012FCA0:
    ctx->pc = 0x8012FCA0u;
    // 8012FCA0: lwz     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FCA4:
    ctx->pc = 0x8012FCA4u;
    // 8012FCA4: bl      0x801C0BFC
    {
            ctx->lr = 0x8012FCA8u;
            ctx->pc = 0x801C0BFCu;
            return;
    }

label_8012FCA8:
    ctx->pc = 0x8012FCA8u;
    ctx->downcount -= 17;
    // 8012FCA8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012FCAC:
    ctx->pc = 0x8012FCACu;
    // 8012FCAC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FCB0:
    ctx->pc = 0x8012FCB0u;
    // 8012FCB0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FCB4:
    ctx->pc = 0x8012FCB4u;
    // 8012FCB4: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8012FCB8:
    ctx->pc = 0x8012FCB8u;
    // 8012FCB8: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8012FCBC:
    ctx->pc = 0x8012FCBCu;
    // 8012FCBC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FCC0:
    ctx->pc = 0x8012FCC0u;
    ctx->downcount -= 8;
    // 8012FCC0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012FCC4:
    ctx->pc = 0x8012FCC4u;
    // 8012FCC4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012FCC8:
    ctx->pc = 0x8012FCC8u;
    // 8012FCC8: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8012FCCC:
    ctx->pc = 0x8012FCCCu;
    // 8012FCCC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FCD0:
    ctx->pc = 0x8012FCD0u;
    // 8012FCD0: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FCD4:
    ctx->pc = 0x8012FCD4u;
    // 8012FCD4: lwz     r0, 860(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(860);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FCD8:
    ctx->pc = 0x8012FCD8u;
    // 8012FCD8: cmpwi   r0, 0
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

label_8012FCDC:
    ctx->pc = 0x8012FCDCu;
    // 8012FCDC: bc    4, 2, 0x8012FCEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8012FCEC;
        }
    }

label_8012FCE0:
    ctx->pc = 0x8012FCE0u;
    ctx->downcount -= 2;
    // 8012FCE0: lwz     r3, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FCE4:
    ctx->pc = 0x8012FCE4u;
    // 8012FCE4: bl      0x80143B78
    {
            ctx->lr = 0x8012FCE8u;
            ctx->pc = 0x80143B78u;
            return;
    }

label_8012FCE8:
    ctx->pc = 0x8012FCE8u;
    ctx->downcount -= 1;
    // 8012FCE8: b       0x8012FD88
    {
            goto label_8012FD88;
    }

label_8012FCEC:
    ctx->pc = 0x8012FCECu;
    ctx->downcount -= 3;
    // 8012FCEC: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012FCF0:
    ctx->pc = 0x8012FCF0u;
    // 8012FCF0: lwz     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FCF4:
    ctx->pc = 0x8012FCF4u;
    // 8012FCF4: bl      0x801BDA98
    {
            ctx->lr = 0x8012FCF8u;
            ctx->pc = 0x801BDA98u;
            return;
    }

label_8012FCF8:
    ctx->pc = 0x8012FCF8u;
    ctx->downcount -= 2;
    // 8012FCF8: cmpwi   r3, 0
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

label_8012FCFC:
    ctx->pc = 0x8012FCFCu;
    // 8012FCFC: bc    12, 2, 0x8012FD84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FD84;
        }
    }

label_8012FD00:
    ctx->pc = 0x8012FD00u;
    ctx->downcount -= 4;
    // 8012FD00: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8012FD04:
    ctx->pc = 0x8012FD04u;
    // 8012FD04: lwz     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FD08:
    ctx->pc = 0x8012FD08u;
    // 8012FD08: stw     r0, 860(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(860);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FD0C:
    ctx->pc = 0x8012FD0Cu;
    // 8012FD0C: bl      0x801B1564
    {
            ctx->lr = 0x8012FD10u;
            ctx->pc = 0x801B1564u;
            return;
    }

label_8012FD10:
    ctx->pc = 0x8012FD10u;
    ctx->downcount -= 2;
    // 8012FD10: cmpwi   r3, 0
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

label_8012FD14:
    ctx->pc = 0x8012FD14u;
    // 8012FD14: bc    12, 2, 0x8012FD48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FD48;
        }
    }

label_8012FD18:
    ctx->pc = 0x8012FD18u;
    ctx->downcount -= 5;
    // 8012FD18: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012FD1C:
    ctx->pc = 0x8012FD1Cu;
    // 8012FD1C: lwz     r0, 864(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(864);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FD20:
    ctx->pc = 0x8012FD20u;
    // 8012FD20: lwz     r3, 52(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(52);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FD24:
    ctx->pc = 0x8012FD24u;
    // 8012FD24: cmpwi   r0, 0
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

label_8012FD28:
    ctx->pc = 0x8012FD28u;
    // 8012FD28: bc    12, 2, 0x8012FD38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FD38;
        }
    }

label_8012FD2C:
    ctx->pc = 0x8012FD2Cu;
    ctx->downcount -= 3;
    // 8012FD2C: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_8012FD30:
    ctx->pc = 0x8012FD30u;
    // 8012FD30: lwz     r5, -21704(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21704);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8012FD34:
    ctx->pc = 0x8012FD34u;
    // 8012FD34: b       0x8012FD3C
    {
            goto label_8012FD3C;
    }

label_8012FD38:
    ctx->pc = 0x8012FD38u;
    ctx->downcount -= 1;
    // 8012FD38: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_8012FD3C:
    ctx->pc = 0x8012FD3Cu;
    ctx->downcount -= 2;
    // 8012FD3C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8012FD40:
    ctx->pc = 0x8012FD40u;
    // 8012FD40: bl      0x800F9EEC
    {
            ctx->lr = 0x8012FD44u;
            ctx->pc = 0x800F9EECu;
            return;
    }

label_8012FD44:
    ctx->pc = 0x8012FD44u;
    ctx->downcount -= 1;
    // 8012FD44: b       0x8012FD68
    {
            goto label_8012FD68;
    }

label_8012FD48:
    ctx->pc = 0x8012FD48u;
    ctx->downcount -= 9;
    // 8012FD48: lwz     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012FD4C:
    ctx->pc = 0x8012FD4Cu;
    // 8012FD4C: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_8012FD50:
    ctx->pc = 0x8012FD50u;
    // 8012FD50: lfs     f1, 17784(r11)
    if (!ppc_fp_available_inline(ctx, 0x8012FD50u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(17784);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8012FD54:
    ctx->pc = 0x8012FD54u;
    // 8012FD54: lha     r3, 208(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(208);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8012FD58:
    ctx->pc = 0x8012FD58u;
    // 8012FD58: lwz     r0, 212(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(212);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FD5C:
    ctx->pc = 0x8012FD5Cu;
    // 8012FD5C: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8012FD60:
    ctx->pc = 0x8012FD60u;
    // 8012FD60: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FD64:
    ctx->pc = 0x8012FD64u;
    // 8012FD64: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8012FD68u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FD68:
    ctx->pc = 0x8012FD68u;
    ctx->downcount -= 8;
    // 8012FD68: lwz     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012FD6C:
    ctx->pc = 0x8012FD6Cu;
    // 8012FD6C: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_8012FD70:
    ctx->pc = 0x8012FD70u;
    // 8012FD70: lha     r3, 192(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(192);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8012FD74:
    ctx->pc = 0x8012FD74u;
    // 8012FD74: lwz     r0, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FD78:
    ctx->pc = 0x8012FD78u;
    // 8012FD78: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8012FD7C:
    ctx->pc = 0x8012FD7Cu;
    // 8012FD7C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FD80:
    ctx->pc = 0x8012FD80u;
    // 8012FD80: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8012FD84u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FD84:
    ctx->pc = 0x8012FD84u;
    ctx->downcount -= 1;
    // 8012FD84: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8012FD88:
    ctx->pc = 0x8012FD88u;
    ctx->downcount -= 6;
    // 8012FD88: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FD8C:
    ctx->pc = 0x8012FD8Cu;
    // 8012FD8C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FD90:
    ctx->pc = 0x8012FD90u;
    // 8012FD90: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8012FD94:
    ctx->pc = 0x8012FD94u;
    // 8012FD94: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8012FD98:
    ctx->pc = 0x8012FD98u;
    // 8012FD98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FD9C:
    ctx->pc = 0x8012FD9Cu;
    ctx->downcount -= 7;
    // 8012FD9C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012FDA0:
    ctx->pc = 0x8012FDA0u;
    // 8012FDA0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012FDA4:
    ctx->pc = 0x8012FDA4u;
    // 8012FDA4: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8012FDA8:
    ctx->pc = 0x8012FDA8u;
    // 8012FDA8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FDAC:
    ctx->pc = 0x8012FDACu;
    // 8012FDAC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FDB0:
    ctx->pc = 0x8012FDB0u;
    // 8012FDB0: lwz     r3, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FDB4:
    ctx->pc = 0x8012FDB4u;
    // 8012FDB4: bl      0x80143B78
    {
            ctx->lr = 0x8012FDB8u;
            ctx->pc = 0x80143B78u;
            return;
    }

label_8012FDB8:
    ctx->pc = 0x8012FDB8u;
    ctx->downcount -= 2;
    // 8012FDB8: cmpwi   r3, 0
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

label_8012FDBC:
    ctx->pc = 0x8012FDBCu;
    // 8012FDBC: bc    12, 2, 0x8012FDC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FDC8;
        }
    }

label_8012FDC0:
    ctx->pc = 0x8012FDC0u;
    ctx->downcount -= 2;
    // 8012FDC0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8012FDC4:
    ctx->pc = 0x8012FDC4u;
    // 8012FDC4: stw     r0, 660(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(660);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FDC8:
    ctx->pc = 0x8012FDC8u;
    ctx->downcount -= 6;
    // 8012FDC8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FDCC:
    ctx->pc = 0x8012FDCCu;
    // 8012FDCC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FDD0:
    ctx->pc = 0x8012FDD0u;
    // 8012FDD0: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8012FDD4:
    ctx->pc = 0x8012FDD4u;
    // 8012FDD4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8012FDD8:
    ctx->pc = 0x8012FDD8u;
    // 8012FDD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FDDC:
    ctx->pc = 0x8012FDDCu;
    ctx->downcount -= 20;
    // 8012FDDC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012FDE0:
    ctx->pc = 0x8012FDE0u;
    // 8012FDE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012FDE4:
    ctx->pc = 0x8012FDE4u;
    // 8012FDE4: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8012FDE8:
    ctx->pc = 0x8012FDE8u;
    // 8012FDE8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FDEC:
    ctx->pc = 0x8012FDECu;
    // 8012FDEC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FDF0:
    ctx->pc = 0x8012FDF0u;
    // 8012FDF0: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8012FDF4:
    ctx->pc = 0x8012FDF4u;
    // 8012FDF4: lwz     r3, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FDF8:
    ctx->pc = 0x8012FDF8u;
    // 8012FDF8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8012FDFC:
    ctx->pc = 0x8012FDFCu;
    // 8012FDFC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8012FE00:
    ctx->pc = 0x8012FE00u;
    // 8012FE00: bl      0x80148240
    {
            ctx->lr = 0x8012FE04u;
            ctx->pc = 0x80148240u;
            return;
    }

label_8012FE04:
    ctx->pc = 0x8012FE04u;
    ctx->downcount -= 13;
    // 8012FE04: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012FE08:
    ctx->pc = 0x8012FE08u;
    // 8012FE08: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012FE0C:
    ctx->pc = 0x8012FE0Cu;
    // 8012FE0C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8012FE10:
    ctx->pc = 0x8012FE10u;
    // 8012FE10: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8012FE14:
    ctx->pc = 0x8012FE14u;
    // 8012FE14: lha     r0, 168(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(168);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8012FE18:
    ctx->pc = 0x8012FE18u;
    // 8012FE18: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8012FE1C:
    ctx->pc = 0x8012FE1Cu;
    // 8012FE1C: lwz     r11, 172(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8012FE20:
    ctx->pc = 0x8012FE20u;
    // 8012FE20: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8012FE24:
    ctx->pc = 0x8012FE24u;
    // 8012FE24: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8012FE28:
    ctx->pc = 0x8012FE28u;
    // 8012FE28: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8012FE2C:
    ctx->pc = 0x8012FE2Cu;
    // 8012FE2C: mtlr    r11
    ctx->lr = ctx->gpr[11];

label_8012FE30:
    ctx->pc = 0x8012FE30u;
    // 8012FE30: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8012FE34u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FE34:
    ctx->pc = 0x8012FE34u;
    ctx->downcount -= 2;
    // 8012FE34: cmpwi   r3, 0
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

label_8012FE38:
    ctx->pc = 0x8012FE38u;
    // 8012FE38: bc    12, 2, 0x8012FE78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FE78;
        }
    }

label_8012FE3C:
    ctx->pc = 0x8012FE3Cu;
    ctx->downcount -= 4;
    // 8012FE3C: lwz     r3, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FE40:
    ctx->pc = 0x8012FE40u;
    // 8012FE40: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8012FE44:
    ctx->pc = 0x8012FE44u;
    // 8012FE44: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8012FE48:
    ctx->pc = 0x8012FE48u;
    // 8012FE48: bl      0x80148240
    {
            ctx->lr = 0x8012FE4Cu;
            ctx->pc = 0x80148240u;
            return;
    }

label_8012FE4C:
    ctx->pc = 0x8012FE4Cu;
    ctx->downcount -= 1;
    // 8012FE4C: bl      0x80143B58
    {
            ctx->lr = 0x8012FE50u;
            ctx->pc = 0x80143B58u;
            return;
    }

label_8012FE50:
    ctx->pc = 0x8012FE50u;
    ctx->downcount -= 5;
    // 8012FE50: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FE54:
    ctx->pc = 0x8012FE54u;
    // 8012FE54: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8012FE58:
    ctx->pc = 0x8012FE58u;
    // 8012FE58: lwz     r3, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FE5C:
    ctx->pc = 0x8012FE5Cu;
    // 8012FE5C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8012FE60:
    ctx->pc = 0x8012FE60u;
    // 8012FE60: bl      0x80148240
    {
            ctx->lr = 0x8012FE64u;
            ctx->pc = 0x80148240u;
            return;
    }

label_8012FE64:
    ctx->pc = 0x8012FE64u;
    ctx->downcount -= 1;
    // 8012FE64: bl      0x80143B58
    {
            ctx->lr = 0x8012FE68u;
            ctx->pc = 0x80143B58u;
            return;
    }

label_8012FE68:
    ctx->pc = 0x8012FE68u;
    ctx->downcount -= 4;
    // 8012FE68: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FE6C:
    ctx->pc = 0x8012FE6Cu;
    // 8012FE6C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012FE70:
    ctx->pc = 0x8012FE70u;
    // 8012FE70: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012FE74:
    ctx->pc = 0x8012FE74u;
    // 8012FE74: bl      0x80130108
    {
            ctx->lr = 0x8012FE78u;
            goto label_80130108;
    }

label_8012FE78:
    ctx->pc = 0x8012FE78u;
    ctx->downcount -= 16;
    // 8012FE78: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FE7C:
    ctx->pc = 0x8012FE7Cu;
    // 8012FE7C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FE80:
    ctx->pc = 0x8012FE80u;
    // 8012FE80: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8012FE84:
    ctx->pc = 0x8012FE84u;
    // 8012FE84: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8012FE88:
    ctx->pc = 0x8012FE88u;
    // 8012FE88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FE8C:
    ctx->pc = 0x8012FE8Cu;
    ctx->downcount -= 20;
    // 8012FE8C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012FE90:
    ctx->pc = 0x8012FE90u;
    // 8012FE90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012FE94:
    ctx->pc = 0x8012FE94u;
    // 8012FE94: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8012FE98:
    ctx->pc = 0x8012FE98u;
    // 8012FE98: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FE9C:
    ctx->pc = 0x8012FE9Cu;
    // 8012FE9C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FEA0:
    ctx->pc = 0x8012FEA0u;
    // 8012FEA0: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8012FEA4:
    ctx->pc = 0x8012FEA4u;
    // 8012FEA4: lwz     r3, 724(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FEA8:
    ctx->pc = 0x8012FEA8u;
    // 8012FEA8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8012FEAC:
    ctx->pc = 0x8012FEACu;
    // 8012FEAC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8012FEB0:
    ctx->pc = 0x8012FEB0u;
    // 8012FEB0: bl      0x80148240
    {
            ctx->lr = 0x8012FEB4u;
            ctx->pc = 0x80148240u;
            return;
    }

label_8012FEB4:
    ctx->pc = 0x8012FEB4u;
    ctx->downcount -= 14;
    // 8012FEB4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FEB8:
    ctx->pc = 0x8012FEB8u;
    // 8012FEB8: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012FEBC:
    ctx->pc = 0x8012FEBCu;
    // 8012FEBC: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012FEC0:
    ctx->pc = 0x8012FEC0u;
    // 8012FEC0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8012FEC4:
    ctx->pc = 0x8012FEC4u;
    // 8012FEC4: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8012FEC8:
    ctx->pc = 0x8012FEC8u;
    // 8012FEC8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8012FECC:
    ctx->pc = 0x8012FECCu;
    // 8012FECC: lha     r3, 168(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(168);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8012FED0:
    ctx->pc = 0x8012FED0u;
    // 8012FED0: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8012FED4:
    ctx->pc = 0x8012FED4u;
    // 8012FED4: lwz     r0, 172(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(172);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FED8:
    ctx->pc = 0x8012FED8u;
    // 8012FED8: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8012FEDC:
    ctx->pc = 0x8012FEDCu;
    // 8012FEDC: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8012FEE0:
    ctx->pc = 0x8012FEE0u;
    // 8012FEE0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FEE4:
    ctx->pc = 0x8012FEE4u;
    // 8012FEE4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8012FEE8u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FEE8:
    ctx->pc = 0x8012FEE8u;
    ctx->downcount -= 2;
    // 8012FEE8: cmpwi   r3, 0
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

label_8012FEEC:
    ctx->pc = 0x8012FEECu;
    // 8012FEEC: bc    12, 2, 0x8012FF04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FF04;
        }
    }

label_8012FEF0:
    ctx->pc = 0x8012FEF0u;
    ctx->downcount -= 2;
    // 8012FEF0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012FEF4:
    ctx->pc = 0x8012FEF4u;
    // 8012FEF4: bl      0x80143B58
    {
            ctx->lr = 0x8012FEF8u;
            ctx->pc = 0x80143B58u;
            return;
    }

label_8012FEF8:
    ctx->pc = 0x8012FEF8u;
    ctx->downcount -= 3;
    // 8012FEF8: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FEFC:
    ctx->pc = 0x8012FEFCu;
    // 8012FEFC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8012FF00:
    ctx->pc = 0x8012FF00u;
    // 8012FF00: bl      0x8012FFC0
    {
            ctx->lr = 0x8012FF04u;
            goto label_8012FFC0;
    }

label_8012FF04:
    ctx->pc = 0x8012FF04u;
    ctx->downcount -= 16;
    // 8012FF04: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FF08:
    ctx->pc = 0x8012FF08u;
    // 8012FF08: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FF0C:
    ctx->pc = 0x8012FF0Cu;
    // 8012FF0C: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8012FF10:
    ctx->pc = 0x8012FF10u;
    // 8012FF10: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8012FF14:
    ctx->pc = 0x8012FF14u;
    // 8012FF14: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FF18:
    ctx->pc = 0x8012FF18u;
    ctx->downcount -= 20;
    // 8012FF18: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012FF1C:
    ctx->pc = 0x8012FF1Cu;
    // 8012FF1C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012FF20:
    ctx->pc = 0x8012FF20u;
    // 8012FF20: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8012FF24:
    ctx->pc = 0x8012FF24u;
    // 8012FF24: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FF28:
    ctx->pc = 0x8012FF28u;
    // 8012FF28: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FF2C:
    ctx->pc = 0x8012FF2Cu;
    // 8012FF2C: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8012FF30:
    ctx->pc = 0x8012FF30u;
    // 8012FF30: lwz     r3, 724(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FF34:
    ctx->pc = 0x8012FF34u;
    // 8012FF34: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8012FF38:
    ctx->pc = 0x8012FF38u;
    // 8012FF38: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8012FF3C:
    ctx->pc = 0x8012FF3Cu;
    // 8012FF3C: bl      0x80148240
    {
            ctx->lr = 0x8012FF40u;
            ctx->pc = 0x80148240u;
            return;
    }

label_8012FF40:
    ctx->pc = 0x8012FF40u;
    ctx->downcount -= 14;
    // 8012FF40: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FF44:
    ctx->pc = 0x8012FF44u;
    // 8012FF44: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012FF48:
    ctx->pc = 0x8012FF48u;
    // 8012FF48: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8012FF4C:
    ctx->pc = 0x8012FF4Cu;
    // 8012FF4C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8012FF50:
    ctx->pc = 0x8012FF50u;
    // 8012FF50: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8012FF54:
    ctx->pc = 0x8012FF54u;
    // 8012FF54: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8012FF58:
    ctx->pc = 0x8012FF58u;
    // 8012FF58: lha     r3, 168(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(168);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8012FF5C:
    ctx->pc = 0x8012FF5Cu;
    // 8012FF5C: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8012FF60:
    ctx->pc = 0x8012FF60u;
    // 8012FF60: lwz     r0, 172(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(172);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FF64:
    ctx->pc = 0x8012FF64u;
    // 8012FF64: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8012FF68:
    ctx->pc = 0x8012FF68u;
    // 8012FF68: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8012FF6C:
    ctx->pc = 0x8012FF6Cu;
    // 8012FF6C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FF70:
    ctx->pc = 0x8012FF70u;
    // 8012FF70: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8012FF74u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FF74:
    ctx->pc = 0x8012FF74u;
    ctx->downcount -= 2;
    // 8012FF74: cmpwi   r3, 0
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

label_8012FF78:
    ctx->pc = 0x8012FF78u;
    // 8012FF78: bc    12, 2, 0x8012FFAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8012FFAC;
        }
    }

label_8012FF7C:
    ctx->pc = 0x8012FF7Cu;
    ctx->downcount -= 4;
    // 8012FF7C: lwz     r3, 724(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FF80:
    ctx->pc = 0x8012FF80u;
    // 8012FF80: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8012FF84:
    ctx->pc = 0x8012FF84u;
    // 8012FF84: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8012FF88:
    ctx->pc = 0x8012FF88u;
    // 8012FF88: bl      0x80148240
    {
            ctx->lr = 0x8012FF8Cu;
            ctx->pc = 0x80148240u;
            return;
    }

label_8012FF8C:
    ctx->pc = 0x8012FF8Cu;
    ctx->downcount -= 1;
    // 8012FF8C: bl      0x80143B58
    {
            ctx->lr = 0x8012FF90u;
            ctx->pc = 0x80143B58u;
            return;
    }

label_8012FF90:
    ctx->pc = 0x8012FF90u;
    ctx->downcount -= 3;
    // 8012FF90: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FF94:
    ctx->pc = 0x8012FF94u;
    // 8012FF94: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8012FF98:
    ctx->pc = 0x8012FF98u;
    // 8012FF98: bl      0x80143B58
    {
            ctx->lr = 0x8012FF9Cu;
            ctx->pc = 0x80143B58u;
            return;
    }

label_8012FF9C:
    ctx->pc = 0x8012FF9Cu;
    ctx->downcount -= 4;
    // 8012FF9C: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FFA0:
    ctx->pc = 0x8012FFA0u;
    // 8012FFA0: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8012FFA4:
    ctx->pc = 0x8012FFA4u;
    // 8012FFA4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8012FFA8:
    ctx->pc = 0x8012FFA8u;
    // 8012FFA8: bl      0x80130038
    {
            ctx->lr = 0x8012FFACu;
            goto label_80130038;
    }

label_8012FFAC:
    ctx->pc = 0x8012FFACu;
    ctx->downcount -= 16;
    // 8012FFAC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8012FFB0:
    ctx->pc = 0x8012FFB0u;
    // 8012FFB0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8012FFB4:
    ctx->pc = 0x8012FFB4u;
    // 8012FFB4: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8012FFB8:
    ctx->pc = 0x8012FFB8u;
    // 8012FFB8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8012FFBC:
    ctx->pc = 0x8012FFBCu;
    // 8012FFBC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8012FFC0:
    ctx->pc = 0x8012FFC0u;
    ctx->downcount -= 21;
    // 8012FFC0: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8012FFC4:
    ctx->pc = 0x8012FFC4u;
    // 8012FFC4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8012FFC8:
    ctx->pc = 0x8012FFC8u;
    // 8012FFC8: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8012FFCC:
    ctx->pc = 0x8012FFCCu;
    // 8012FFCC: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8012FFD0:
    ctx->pc = 0x8012FFD0u;
    // 8012FFD0: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8012FFD4:
    ctx->pc = 0x8012FFD4u;
    // 8012FFD4: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8012FFD8:
    ctx->pc = 0x8012FFD8u;
    // 8012FFD8: lwz     r3, 724(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8012FFDC:
    ctx->pc = 0x8012FFDCu;
    // 8012FFDC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8012FFE0:
    ctx->pc = 0x8012FFE0u;
    // 8012FFE0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8012FFE4:
    ctx->pc = 0x8012FFE4u;
    // 8012FFE4: rlwinm r27, r29, 2, 0, 29
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[29], 2u) & 0xFFFFFFFCu;
    }

label_8012FFE8:
    ctx->pc = 0x8012FFE8u;
    // 8012FFE8: bl      0x80148240
    {
            ctx->lr = 0x8012FFECu;
            ctx->pc = 0x80148240u;
            return;
    }

label_8012FFEC:
    ctx->pc = 0x8012FFECu;
    ctx->downcount -= 2;
    // 8012FFEC: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8012FFF0:
    ctx->pc = 0x8012FFF0u;
    // 8012FFF0: bl      0x80143B20
    {
            ctx->lr = 0x8012FFF4u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_8012FFF4:
    ctx->pc = 0x8012FFF4u;
    ctx->downcount -= 7;
    // 8012FFF4: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_8012FFF8:
    ctx->pc = 0x8012FFF8u;
    // 8012FFF8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8012FFFC:
    ctx->pc = 0x8012FFFCu;
    // 8012FFFC: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80130000:
    ctx->pc = 0x80130000u;
    // 80130000: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130004:
    ctx->pc = 0x80130004u;
    // 80130004: addi    r9, r30, 2884
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(2884);

label_80130008:
    ctx->pc = 0x80130008u;
    // 80130008: lwzx    r4, r9, r27
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8013000C:
    ctx->pc = 0x8013000Cu;
    // 8013000C: bl      0x8012EFB4
    {
            ctx->lr = 0x80130010u;
            ctx->pc = 0x8012EFB4u;
            return;
    }

label_80130010:
    ctx->pc = 0x80130010u;
    ctx->downcount -= 5;
    // 80130010: addi    r30, r30, 2900
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(2900);

label_80130014:
    ctx->pc = 0x80130014u;
    // 80130014: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130018:
    ctx->pc = 0x80130018u;
    // 80130018: lwzx    r4, r30, r27
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8013001C:
    ctx->pc = 0x8013001Cu;
    // 8013001C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130020:
    ctx->pc = 0x80130020u;
    // 80130020: bl      0x80130154
    {
            ctx->lr = 0x80130024u;
            goto label_80130154;
    }

label_80130024:
    ctx->pc = 0x80130024u;
    ctx->downcount -= 16;
    // 80130024: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130028:
    ctx->pc = 0x80130028u;
    // 80130028: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013002C:
    ctx->pc = 0x8013002Cu;
    // 8013002C: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80130030:
    ctx->pc = 0x80130030u;
    // 80130030: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80130034:
    ctx->pc = 0x80130034u;
    // 80130034: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130038:
    ctx->pc = 0x80130038u;
    ctx->downcount -= 20;
    // 80130038: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013003C:
    ctx->pc = 0x8013003Cu;
    // 8013003C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80130040:
    ctx->pc = 0x80130040u;
    // 80130040: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130044:
    ctx->pc = 0x80130044u;
    // 80130044: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130048:
    ctx->pc = 0x80130048u;
    // 80130048: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013004C:
    ctx->pc = 0x8013004Cu;
    // 8013004C: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80130050:
    ctx->pc = 0x80130050u;
    // 80130050: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80130054:
    ctx->pc = 0x80130054u;
    // 80130054: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80130058:
    ctx->pc = 0x80130058u;
    // 80130058: addi    r3, r3, -22168
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-22168);

label_8013005C:
    ctx->pc = 0x8013005Cu;
    // 8013005C: bl      0x800FF414
    {
            ctx->lr = 0x80130060u;
            ctx->pc = 0x800FF414u;
            return;
    }

label_80130060:
    ctx->pc = 0x80130060u;
    ctx->downcount -= 2;
    // 80130060: cmpwi   r28, 2
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80130064:
    ctx->pc = 0x80130064u;
    // 80130064: bc    4, 2, 0x801300E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801300E4;
        }
    }

label_80130068:
    ctx->pc = 0x80130068u;
    ctx->downcount -= 6;
    // 80130068: rlwinm r30, r29, 2, 0, 29
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[29], 2u) & 0xFFFFFFFCu;
    }

label_8013006C:
    ctx->pc = 0x8013006Cu;
    // 8013006C: addi    r9, r31, 764
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(764);

label_80130070:
    ctx->pc = 0x80130070u;
    // 80130070: lwzx    r4, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80130074:
    ctx->pc = 0x80130074u;
    // 80130074: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80130078:
    ctx->pc = 0x80130078u;
    // 80130078: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013007C:
    ctx->pc = 0x8013007Cu;
    // 8013007C: bl      0x80130274
    {
            ctx->lr = 0x80130080u;
            goto label_80130274;
    }

label_80130080:
    ctx->pc = 0x80130080u;
    ctx->downcount -= 5;
    // 80130080: addi    r9, r31, 780
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(780);

label_80130084:
    ctx->pc = 0x80130084u;
    // 80130084: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80130088:
    ctx->pc = 0x80130088u;
    // 80130088: lwzx    r4, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8013008C:
    ctx->pc = 0x8013008Cu;
    // 8013008C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130090:
    ctx->pc = 0x80130090u;
    // 80130090: bl      0x80130328
    {
            ctx->lr = 0x80130094u;
            goto label_80130328;
    }

label_80130094:
    ctx->pc = 0x80130094u;
    ctx->downcount -= 5;
    // 80130094: addi    r9, r31, 796
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(796);

label_80130098:
    ctx->pc = 0x80130098u;
    // 80130098: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8013009C:
    ctx->pc = 0x8013009Cu;
    // 8013009C: lwzx    r4, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801300A0:
    ctx->pc = 0x801300A0u;
    // 801300A0: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801300A4:
    ctx->pc = 0x801300A4u;
    // 801300A4: bl      0x80130428
    {
            ctx->lr = 0x801300A8u;
            goto label_80130428;
    }

label_801300A8:
    ctx->pc = 0x801300A8u;
    ctx->downcount -= 5;
    // 801300A8: addi    r9, r31, 828
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(828);

label_801300AC:
    ctx->pc = 0x801300ACu;
    // 801300AC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801300B0:
    ctx->pc = 0x801300B0u;
    // 801300B0: lwzx    r4, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801300B4:
    ctx->pc = 0x801300B4u;
    // 801300B4: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801300B8:
    ctx->pc = 0x801300B8u;
    // 801300B8: bl      0x80130528
    {
            ctx->lr = 0x801300BCu;
            goto label_80130528;
    }

label_801300BC:
    ctx->pc = 0x801300BCu;
    ctx->downcount -= 5;
    // 801300BC: addi    r9, r31, 812
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(812);

label_801300C0:
    ctx->pc = 0x801300C0u;
    // 801300C0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801300C4:
    ctx->pc = 0x801300C4u;
    // 801300C4: lwzx    r4, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801300C8:
    ctx->pc = 0x801300C8u;
    // 801300C8: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801300CC:
    ctx->pc = 0x801300CCu;
    // 801300CC: bl      0x801305DC
    {
            ctx->lr = 0x801300D0u;
            goto label_801305DC;
    }

label_801300D0:
    ctx->pc = 0x801300D0u;
    ctx->downcount -= 5;
    // 801300D0: addi    r9, r31, 844
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(844);

label_801300D4:
    ctx->pc = 0x801300D4u;
    // 801300D4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801300D8:
    ctx->pc = 0x801300D8u;
    // 801300D8: lwzx    r4, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801300DC:
    ctx->pc = 0x801300DCu;
    // 801300DC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801300E0:
    ctx->pc = 0x801300E0u;
    // 801300E0: bl      0x80130718
    {
            ctx->lr = 0x801300E4u;
            goto label_80130718;
    }

label_801300E4:
    ctx->pc = 0x801300E4u;
    ctx->downcount -= 4;
    // 801300E4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801300E8:
    ctx->pc = 0x801300E8u;
    // 801300E8: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801300EC:
    ctx->pc = 0x801300ECu;
    // 801300EC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801300F0:
    ctx->pc = 0x801300F0u;
    // 801300F0: bl      0x8012EFB4
    {
            ctx->lr = 0x801300F4u;
            ctx->pc = 0x8012EFB4u;
            return;
    }

label_801300F4:
    ctx->pc = 0x801300F4u;
    ctx->downcount -= 16;
    // 801300F4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801300F8:
    ctx->pc = 0x801300F8u;
    // 801300F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801300FC:
    ctx->pc = 0x801300FCu;
    // 801300FC: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80130100:
    ctx->pc = 0x80130100u;
    // 80130100: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80130104:
    ctx->pc = 0x80130104u;
    // 80130104: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130108:
    ctx->pc = 0x80130108u;
    ctx->downcount -= 20;
    // 80130108: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013010C:
    ctx->pc = 0x8013010Cu;
    // 8013010C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80130110:
    ctx->pc = 0x80130110u;
    // 80130110: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130114:
    ctx->pc = 0x80130114u;
    // 80130114: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130118:
    ctx->pc = 0x80130118u;
    // 80130118: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013011C:
    ctx->pc = 0x8013011Cu;
    // 8013011C: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80130120:
    ctx->pc = 0x80130120u;
    // 80130120: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80130124:
    ctx->pc = 0x80130124u;
    // 80130124: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80130128:
    ctx->pc = 0x80130128u;
    // 80130128: addi    r3, r3, -22168
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-22168);

label_8013012C:
    ctx->pc = 0x8013012Cu;
    // 8013012C: bl      0x80100980
    {
            ctx->lr = 0x80130130u;
            ctx->pc = 0x80100980u;
            return;
    }

label_80130130:
    ctx->pc = 0x80130130u;
    ctx->downcount -= 4;
    // 80130130: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130134:
    ctx->pc = 0x80130134u;
    // 80130134: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130138:
    ctx->pc = 0x80130138u;
    // 80130138: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013013C:
    ctx->pc = 0x8013013Cu;
    // 8013013C: bl      0x80130154
    {
            ctx->lr = 0x80130140u;
            goto label_80130154;
    }

label_80130140:
    ctx->pc = 0x80130140u;
    ctx->downcount -= 16;
    // 80130140: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130144:
    ctx->pc = 0x80130144u;
    // 80130144: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80130148:
    ctx->pc = 0x80130148u;
    // 80130148: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8013014C:
    ctx->pc = 0x8013014Cu;
    // 8013014C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80130150:
    ctx->pc = 0x80130150u;
    // 80130150: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130154:
    ctx->pc = 0x80130154u;
    ctx->downcount -= 19;
    // 80130154: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130158:
    ctx->pc = 0x80130158u;
    // 80130158: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8013015C:
    ctx->pc = 0x8013015Cu;
    // 8013015C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130160:
    ctx->pc = 0x80130160u;
    // 80130160: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130164:
    ctx->pc = 0x80130164u;
    // 80130164: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80130168:
    ctx->pc = 0x80130168u;
    // 80130168: lwz     r3, 724(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8013016C:
    ctx->pc = 0x8013016Cu;
    // 8013016C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80130170:
    ctx->pc = 0x80130170u;
    // 80130170: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80130174:
    ctx->pc = 0x80130174u;
    // 80130174: bl      0x80148240
    {
            ctx->lr = 0x80130178u;
            ctx->pc = 0x80148240u;
            return;
    }

label_80130178:
    ctx->pc = 0x80130178u;
    ctx->downcount -= 2;
    // 80130178: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8013017C:
    ctx->pc = 0x8013017Cu;
    // 8013017C: bl      0x80143B20
    {
            ctx->lr = 0x80130180u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80130180:
    ctx->pc = 0x80130180u;
    ctx->downcount -= 16;
    // 80130180: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130184:
    ctx->pc = 0x80130184u;
    // 80130184: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80130188:
    ctx->pc = 0x80130188u;
    // 80130188: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8013018C:
    ctx->pc = 0x8013018Cu;
    // 8013018C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80130190:
    ctx->pc = 0x80130190u;
    // 80130190: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130194:
    ctx->pc = 0x80130194u;
    ctx->downcount -= 22;
    // 80130194: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130198:
    ctx->pc = 0x80130198u;
    // 80130198: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8013019C:
    ctx->pc = 0x8013019Cu;
    // 8013019C: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801301A0:
    ctx->pc = 0x801301A0u;
    // 801301A0: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801301A4:
    ctx->pc = 0x801301A4u;
    // 801301A4: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_801301A8:
    ctx->pc = 0x801301A8u;
    // 801301A8: rlwinm r27, r4, 2, 0, 29
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_801301AC:
    ctx->pc = 0x801301ACu;
    // 801301AC: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_801301B0:
    ctx->pc = 0x801301B0u;
    // 801301B0: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801301B4:
    ctx->pc = 0x801301B4u;
    // 801301B4: addi    r9, r30, 2932
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(2932);

label_801301B8:
    ctx->pc = 0x801301B8u;
    // 801301B8: lwz     r28, 696(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(696);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_801301BC:
    ctx->pc = 0x801301BCu;
    // 801301BC: lwzx    r4, r9, r27
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801301C0:
    ctx->pc = 0x801301C0u;
    // 801301C0: bl      0x801307CC
    {
            ctx->lr = 0x801301C4u;
            goto label_801307CC;
    }

label_801301C4:
    ctx->pc = 0x801301C4u;
    ctx->downcount -= 3;
    // 801301C4: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801301C8:
    ctx->pc = 0x801301C8u;
    // 801301C8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801301CC:
    ctx->pc = 0x801301CCu;
    // 801301CC: bl      0x80143B20
    {
            ctx->lr = 0x801301D0u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_801301D0:
    ctx->pc = 0x801301D0u;
    ctx->downcount -= 5;
    // 801301D0: addi    r30, r30, 2964
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(2964);

label_801301D4:
    ctx->pc = 0x801301D4u;
    // 801301D4: lwz     r28, 700(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(700);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_801301D8:
    ctx->pc = 0x801301D8u;
    // 801301D8: lwzx    r4, r30, r27
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801301DC:
    ctx->pc = 0x801301DCu;
    // 801301DC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801301E0:
    ctx->pc = 0x801301E0u;
    // 801301E0: bl      0x801307CC
    {
            ctx->lr = 0x801301E4u;
            goto label_801307CC;
    }

label_801301E4:
    ctx->pc = 0x801301E4u;
    ctx->downcount -= 3;
    // 801301E4: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801301E8:
    ctx->pc = 0x801301E8u;
    // 801301E8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801301EC:
    ctx->pc = 0x801301ECu;
    // 801301EC: bl      0x80143B20
    {
            ctx->lr = 0x801301F0u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_801301F0:
    ctx->pc = 0x801301F0u;
    ctx->downcount -= 16;
    // 801301F0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801301F4:
    ctx->pc = 0x801301F4u;
    // 801301F4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801301F8:
    ctx->pc = 0x801301F8u;
    // 801301F8: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801301FC:
    ctx->pc = 0x801301FCu;
    // 801301FC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80130200:
    ctx->pc = 0x80130200u;
    // 80130200: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130204:
    ctx->pc = 0x80130204u;
    ctx->downcount -= 22;
    // 80130204: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130208:
    ctx->pc = 0x80130208u;
    // 80130208: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8013020C:
    ctx->pc = 0x8013020Cu;
    // 8013020C: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130210:
    ctx->pc = 0x80130210u;
    // 80130210: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130214:
    ctx->pc = 0x80130214u;
    // 80130214: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80130218:
    ctx->pc = 0x80130218u;
    // 80130218: rlwinm r27, r4, 2, 0, 29
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_8013021C:
    ctx->pc = 0x8013021Cu;
    // 8013021C: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80130220:
    ctx->pc = 0x80130220u;
    // 80130220: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130224:
    ctx->pc = 0x80130224u;
    // 80130224: addi    r9, r30, 2948
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(2948);

label_80130228:
    ctx->pc = 0x80130228u;
    // 80130228: lwz     r28, 708(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(708);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8013022C:
    ctx->pc = 0x8013022Cu;
    // 8013022C: lwzx    r4, r9, r27
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80130230:
    ctx->pc = 0x80130230u;
    // 80130230: bl      0x801307CC
    {
            ctx->lr = 0x80130234u;
            goto label_801307CC;
    }

label_80130234:
    ctx->pc = 0x80130234u;
    ctx->downcount -= 3;
    // 80130234: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130238:
    ctx->pc = 0x80130238u;
    // 80130238: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8013023C:
    ctx->pc = 0x8013023Cu;
    // 8013023C: bl      0x80143B20
    {
            ctx->lr = 0x80130240u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80130240:
    ctx->pc = 0x80130240u;
    ctx->downcount -= 5;
    // 80130240: addi    r30, r30, 2964
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(2964);

label_80130244:
    ctx->pc = 0x80130244u;
    // 80130244: lwz     r28, 712(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(712);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80130248:
    ctx->pc = 0x80130248u;
    // 80130248: lwzx    r4, r30, r27
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8013024C:
    ctx->pc = 0x8013024Cu;
    // 8013024C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130250:
    ctx->pc = 0x80130250u;
    // 80130250: bl      0x801307CC
    {
            ctx->lr = 0x80130254u;
            goto label_801307CC;
    }

label_80130254:
    ctx->pc = 0x80130254u;
    ctx->downcount -= 3;
    // 80130254: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130258:
    ctx->pc = 0x80130258u;
    // 80130258: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8013025C:
    ctx->pc = 0x8013025Cu;
    // 8013025C: bl      0x80143B20
    {
            ctx->lr = 0x80130260u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80130260:
    ctx->pc = 0x80130260u;
    ctx->downcount -= 16;
    // 80130260: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130264:
    ctx->pc = 0x80130264u;
    // 80130264: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80130268:
    ctx->pc = 0x80130268u;
    // 80130268: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8013026C:
    ctx->pc = 0x8013026Cu;
    // 8013026C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80130270:
    ctx->pc = 0x80130270u;
    // 80130270: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130274:
    ctx->pc = 0x80130274u;
    ctx->downcount -= 20;
    // 80130274: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130278:
    ctx->pc = 0x80130278u;
    // 80130278: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8013027C:
    ctx->pc = 0x8013027Cu;
    // 8013027C: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130280:
    ctx->pc = 0x80130280u;
    // 80130280: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130284:
    ctx->pc = 0x80130284u;
    // 80130284: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130288:
    ctx->pc = 0x80130288u;
    // 80130288: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8013028C:
    ctx->pc = 0x8013028Cu;
    // 8013028C: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80130290:
    ctx->pc = 0x80130290u;
    // 80130290: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80130294:
    ctx->pc = 0x80130294u;
    // 80130294: addi    r3, r3, -22168
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-22168);

label_80130298:
    ctx->pc = 0x80130298u;
    // 80130298: bl      0x80100990
    {
            ctx->lr = 0x8013029Cu;
            ctx->pc = 0x80100990u;
            return;
    }

label_8013029C:
    ctx->pc = 0x8013029Cu;
    ctx->downcount -= 4;
    // 8013029C: addi    r3, r28, 732
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(732);

label_801302A0:
    ctx->pc = 0x801302A0u;
    // 801302A0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801302A4:
    ctx->pc = 0x801302A4u;
    // 801302A4: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801302A8:
    ctx->pc = 0x801302A8u;
    // 801302A8: bl      0x80100990
    {
            ctx->lr = 0x801302ACu;
            ctx->pc = 0x80100990u;
            return;
    }

label_801302AC:
    ctx->pc = 0x801302ACu;
    ctx->downcount -= 4;
    // 801302AC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801302B0:
    ctx->pc = 0x801302B0u;
    // 801302B0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801302B4:
    ctx->pc = 0x801302B4u;
    // 801302B4: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801302B8:
    ctx->pc = 0x801302B8u;
    // 801302B8: bl      0x801302D0
    {
            ctx->lr = 0x801302BCu;
            goto label_801302D0;
    }

label_801302BC:
    ctx->pc = 0x801302BCu;
    ctx->downcount -= 16;
    // 801302BC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801302C0:
    ctx->pc = 0x801302C0u;
    // 801302C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801302C4:
    ctx->pc = 0x801302C4u;
    // 801302C4: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801302C8:
    ctx->pc = 0x801302C8u;
    // 801302C8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801302CC:
    ctx->pc = 0x801302CCu;
    // 801302CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801302D0:
    ctx->pc = 0x801302D0u;
    ctx->downcount -= 20;
    // 801302D0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801302D4:
    ctx->pc = 0x801302D4u;
    // 801302D4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801302D8:
    ctx->pc = 0x801302D8u;
    // 801302D8: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801302DC:
    ctx->pc = 0x801302DCu;
    // 801302DC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801302E0:
    ctx->pc = 0x801302E0u;
    // 801302E0: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801302E4:
    ctx->pc = 0x801302E4u;
    // 801302E4: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801302E8:
    ctx->pc = 0x801302E8u;
    // 801302E8: lwz     r3, 724(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801302EC:
    ctx->pc = 0x801302ECu;
    // 801302EC: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_801302F0:
    ctx->pc = 0x801302F0u;
    // 801302F0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801302F4:
    ctx->pc = 0x801302F4u;
    // 801302F4: bl      0x80148240
    {
            ctx->lr = 0x801302F8u;
            ctx->pc = 0x80148240u;
            return;
    }

label_801302F8:
    ctx->pc = 0x801302F8u;
    ctx->downcount -= 4;
    // 801302F8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801302FC:
    ctx->pc = 0x801302FCu;
    // 801302FC: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130300:
    ctx->pc = 0x80130300u;
    // 80130300: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130304:
    ctx->pc = 0x80130304u;
    // 80130304: bl      0x801307CC
    {
            ctx->lr = 0x80130308u;
            goto label_801307CC;
    }

label_80130308:
    ctx->pc = 0x80130308u;
    ctx->downcount -= 3;
    // 80130308: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013030C:
    ctx->pc = 0x8013030Cu;
    // 8013030C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130310:
    ctx->pc = 0x80130310u;
    // 80130310: bl      0x80143B20
    {
            ctx->lr = 0x80130314u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80130314:
    ctx->pc = 0x80130314u;
    ctx->downcount -= 16;
    // 80130314: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130318:
    ctx->pc = 0x80130318u;
    // 80130318: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013031C:
    ctx->pc = 0x8013031Cu;
    // 8013031C: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80130320:
    ctx->pc = 0x80130320u;
    // 80130320: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80130324:
    ctx->pc = 0x80130324u;
    // 80130324: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130328:
    ctx->pc = 0x80130328u;
    ctx->downcount -= 21;
    // 80130328: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013032C:
    ctx->pc = 0x8013032Cu;
    // 8013032C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80130330:
    ctx->pc = 0x80130330u;
    // 80130330: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130334:
    ctx->pc = 0x80130334u;
    // 80130334: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130338:
    ctx->pc = 0x80130338u;
    // 80130338: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013033C:
    ctx->pc = 0x8013033Cu;
    // 8013033C: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80130340:
    ctx->pc = 0x80130340u;
    // 80130340: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80130344:
    ctx->pc = 0x80130344u;
    // 80130344: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80130348:
    ctx->pc = 0x80130348u;
    // 80130348: addi    r3, r3, -22168
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-22168);

label_8013034C:
    ctx->pc = 0x8013034Cu;
    // 8013034C: rlwinm r27, r30, 2, 0, 29
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[30], 2u) & 0xFFFFFFFCu;
    }

label_80130350:
    ctx->pc = 0x80130350u;
    // 80130350: bl      0x801009A0
    {
            ctx->lr = 0x80130354u;
            ctx->pc = 0x801009A0u;
            return;
    }

label_80130354:
    ctx->pc = 0x80130354u;
    ctx->downcount -= 4;
    // 80130354: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130358:
    ctx->pc = 0x80130358u;
    // 80130358: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8013035C:
    ctx->pc = 0x8013035Cu;
    // 8013035C: addi    r3, r28, 732
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(732);

label_80130360:
    ctx->pc = 0x80130360u;
    // 80130360: bl      0x801009A0
    {
            ctx->lr = 0x80130364u;
            ctx->pc = 0x801009A0u;
            return;
    }

label_80130364:
    ctx->pc = 0x80130364u;
    ctx->downcount -= 4;
    // 80130364: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130368:
    ctx->pc = 0x80130368u;
    // 80130368: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013036C:
    ctx->pc = 0x8013036Cu;
    // 8013036C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130370:
    ctx->pc = 0x80130370u;
    // 80130370: bl      0x801303D0
    {
            ctx->lr = 0x80130374u;
            goto label_801303D0;
    }

label_80130374:
    ctx->pc = 0x80130374u;
    ctx->downcount -= 7;
    // 80130374: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80130378:
    ctx->pc = 0x80130378u;
    // 80130378: lwz     r29, 696(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(696);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8013037C:
    ctx->pc = 0x8013037Cu;
    // 8013037C: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80130380:
    ctx->pc = 0x80130380u;
    // 80130380: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130384:
    ctx->pc = 0x80130384u;
    // 80130384: addi    r9, r30, 2932
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(2932);

label_80130388:
    ctx->pc = 0x80130388u;
    // 80130388: lwzx    r4, r9, r27
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8013038C:
    ctx->pc = 0x8013038Cu;
    // 8013038C: bl      0x801307CC
    {
            ctx->lr = 0x80130390u;
            goto label_801307CC;
    }

label_80130390:
    ctx->pc = 0x80130390u;
    ctx->downcount -= 3;
    // 80130390: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130394:
    ctx->pc = 0x80130394u;
    // 80130394: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130398:
    ctx->pc = 0x80130398u;
    // 80130398: bl      0x80143B20
    {
            ctx->lr = 0x8013039Cu;
            ctx->pc = 0x80143B20u;
            return;
    }

label_8013039C:
    ctx->pc = 0x8013039Cu;
    ctx->downcount -= 5;
    // 8013039C: addi    r30, r30, 2964
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(2964);

label_801303A0:
    ctx->pc = 0x801303A0u;
    // 801303A0: lwz     r29, 700(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(700);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_801303A4:
    ctx->pc = 0x801303A4u;
    // 801303A4: lwzx    r4, r30, r27
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801303A8:
    ctx->pc = 0x801303A8u;
    // 801303A8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801303AC:
    ctx->pc = 0x801303ACu;
    // 801303AC: bl      0x801307CC
    {
            ctx->lr = 0x801303B0u;
            goto label_801307CC;
    }

label_801303B0:
    ctx->pc = 0x801303B0u;
    ctx->downcount -= 3;
    // 801303B0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801303B4:
    ctx->pc = 0x801303B4u;
    // 801303B4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801303B8:
    ctx->pc = 0x801303B8u;
    // 801303B8: bl      0x80143B20
    {
            ctx->lr = 0x801303BCu;
            ctx->pc = 0x80143B20u;
            return;
    }

label_801303BC:
    ctx->pc = 0x801303BCu;
    ctx->downcount -= 16;
    // 801303BC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801303C0:
    ctx->pc = 0x801303C0u;
    // 801303C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801303C4:
    ctx->pc = 0x801303C4u;
    // 801303C4: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801303C8:
    ctx->pc = 0x801303C8u;
    // 801303C8: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801303CC:
    ctx->pc = 0x801303CCu;
    // 801303CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801303D0:
    ctx->pc = 0x801303D0u;
    ctx->downcount -= 20;
    // 801303D0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801303D4:
    ctx->pc = 0x801303D4u;
    // 801303D4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801303D8:
    ctx->pc = 0x801303D8u;
    // 801303D8: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801303DC:
    ctx->pc = 0x801303DCu;
    // 801303DC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801303E0:
    ctx->pc = 0x801303E0u;
    // 801303E0: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801303E4:
    ctx->pc = 0x801303E4u;
    // 801303E4: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801303E8:
    ctx->pc = 0x801303E8u;
    // 801303E8: lwz     r3, 724(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801303EC:
    ctx->pc = 0x801303ECu;
    // 801303EC: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_801303F0:
    ctx->pc = 0x801303F0u;
    // 801303F0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801303F4:
    ctx->pc = 0x801303F4u;
    // 801303F4: bl      0x80148240
    {
            ctx->lr = 0x801303F8u;
            ctx->pc = 0x80148240u;
            return;
    }

label_801303F8:
    ctx->pc = 0x801303F8u;
    ctx->downcount -= 4;
    // 801303F8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801303FC:
    ctx->pc = 0x801303FCu;
    // 801303FC: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130400:
    ctx->pc = 0x80130400u;
    // 80130400: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130404:
    ctx->pc = 0x80130404u;
    // 80130404: bl      0x801307CC
    {
            ctx->lr = 0x80130408u;
            goto label_801307CC;
    }

label_80130408:
    ctx->pc = 0x80130408u;
    ctx->downcount -= 3;
    // 80130408: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013040C:
    ctx->pc = 0x8013040Cu;
    // 8013040C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130410:
    ctx->pc = 0x80130410u;
    // 80130410: bl      0x80143B20
    {
            ctx->lr = 0x80130414u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80130414:
    ctx->pc = 0x80130414u;
    ctx->downcount -= 16;
    // 80130414: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130418:
    ctx->pc = 0x80130418u;
    // 80130418: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013041C:
    ctx->pc = 0x8013041Cu;
    // 8013041C: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80130420:
    ctx->pc = 0x80130420u;
    // 80130420: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80130424:
    ctx->pc = 0x80130424u;
    // 80130424: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130428:
    ctx->pc = 0x80130428u;
    ctx->downcount -= 21;
    // 80130428: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013042C:
    ctx->pc = 0x8013042Cu;
    // 8013042C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80130430:
    ctx->pc = 0x80130430u;
    // 80130430: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130434:
    ctx->pc = 0x80130434u;
    // 80130434: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130438:
    ctx->pc = 0x80130438u;
    // 80130438: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013043C:
    ctx->pc = 0x8013043Cu;
    // 8013043C: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80130440:
    ctx->pc = 0x80130440u;
    // 80130440: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80130444:
    ctx->pc = 0x80130444u;
    // 80130444: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80130448:
    ctx->pc = 0x80130448u;
    // 80130448: addi    r3, r3, -22168
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-22168);

label_8013044C:
    ctx->pc = 0x8013044Cu;
    // 8013044C: rlwinm r27, r30, 2, 0, 29
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[30], 2u) & 0xFFFFFFFCu;
    }

label_80130450:
    ctx->pc = 0x80130450u;
    // 80130450: bl      0x801009B0
    {
            ctx->lr = 0x80130454u;
            ctx->pc = 0x801009B0u;
            return;
    }

label_80130454:
    ctx->pc = 0x80130454u;
    ctx->downcount -= 4;
    // 80130454: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130458:
    ctx->pc = 0x80130458u;
    // 80130458: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8013045C:
    ctx->pc = 0x8013045Cu;
    // 8013045C: addi    r3, r28, 732
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(732);

label_80130460:
    ctx->pc = 0x80130460u;
    // 80130460: bl      0x801009B0
    {
            ctx->lr = 0x80130464u;
            ctx->pc = 0x801009B0u;
            return;
    }

label_80130464:
    ctx->pc = 0x80130464u;
    ctx->downcount -= 4;
    // 80130464: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130468:
    ctx->pc = 0x80130468u;
    // 80130468: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013046C:
    ctx->pc = 0x8013046Cu;
    // 8013046C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130470:
    ctx->pc = 0x80130470u;
    // 80130470: bl      0x801304D0
    {
            ctx->lr = 0x80130474u;
            goto label_801304D0;
    }

label_80130474:
    ctx->pc = 0x80130474u;
    ctx->downcount -= 7;
    // 80130474: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80130478:
    ctx->pc = 0x80130478u;
    // 80130478: lwz     r29, 708(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(708);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8013047C:
    ctx->pc = 0x8013047Cu;
    // 8013047C: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80130480:
    ctx->pc = 0x80130480u;
    // 80130480: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130484:
    ctx->pc = 0x80130484u;
    // 80130484: addi    r9, r30, 2948
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(2948);

label_80130488:
    ctx->pc = 0x80130488u;
    // 80130488: lwzx    r4, r9, r27
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8013048C:
    ctx->pc = 0x8013048Cu;
    // 8013048C: bl      0x801307CC
    {
            ctx->lr = 0x80130490u;
            goto label_801307CC;
    }

label_80130490:
    ctx->pc = 0x80130490u;
    ctx->downcount -= 3;
    // 80130490: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130494:
    ctx->pc = 0x80130494u;
    // 80130494: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130498:
    ctx->pc = 0x80130498u;
    // 80130498: bl      0x80143B20
    {
            ctx->lr = 0x8013049Cu;
            ctx->pc = 0x80143B20u;
            return;
    }

label_8013049C:
    ctx->pc = 0x8013049Cu;
    ctx->downcount -= 5;
    // 8013049C: addi    r30, r30, 2964
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(2964);

label_801304A0:
    ctx->pc = 0x801304A0u;
    // 801304A0: lwz     r29, 712(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(712);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_801304A4:
    ctx->pc = 0x801304A4u;
    // 801304A4: lwzx    r4, r30, r27
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801304A8:
    ctx->pc = 0x801304A8u;
    // 801304A8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801304AC:
    ctx->pc = 0x801304ACu;
    // 801304AC: bl      0x801307CC
    {
            ctx->lr = 0x801304B0u;
            goto label_801307CC;
    }

label_801304B0:
    ctx->pc = 0x801304B0u;
    ctx->downcount -= 3;
    // 801304B0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801304B4:
    ctx->pc = 0x801304B4u;
    // 801304B4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801304B8:
    ctx->pc = 0x801304B8u;
    // 801304B8: bl      0x80143B20
    {
            ctx->lr = 0x801304BCu;
            ctx->pc = 0x80143B20u;
            return;
    }

label_801304BC:
    ctx->pc = 0x801304BCu;
    ctx->downcount -= 16;
    // 801304BC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801304C0:
    ctx->pc = 0x801304C0u;
    // 801304C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801304C4:
    ctx->pc = 0x801304C4u;
    // 801304C4: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801304C8:
    ctx->pc = 0x801304C8u;
    // 801304C8: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801304CC:
    ctx->pc = 0x801304CCu;
    // 801304CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801304D0:
    ctx->pc = 0x801304D0u;
    ctx->downcount -= 20;
    // 801304D0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801304D4:
    ctx->pc = 0x801304D4u;
    // 801304D4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801304D8:
    ctx->pc = 0x801304D8u;
    // 801304D8: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801304DC:
    ctx->pc = 0x801304DCu;
    // 801304DC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801304E0:
    ctx->pc = 0x801304E0u;
    // 801304E0: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801304E4:
    ctx->pc = 0x801304E4u;
    // 801304E4: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801304E8:
    ctx->pc = 0x801304E8u;
    // 801304E8: lwz     r3, 724(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801304EC:
    ctx->pc = 0x801304ECu;
    // 801304EC: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_801304F0:
    ctx->pc = 0x801304F0u;
    // 801304F0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801304F4:
    ctx->pc = 0x801304F4u;
    // 801304F4: bl      0x80148240
    {
            ctx->lr = 0x801304F8u;
            ctx->pc = 0x80148240u;
            return;
    }

label_801304F8:
    ctx->pc = 0x801304F8u;
    ctx->downcount -= 4;
    // 801304F8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801304FC:
    ctx->pc = 0x801304FCu;
    // 801304FC: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130500:
    ctx->pc = 0x80130500u;
    // 80130500: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130504:
    ctx->pc = 0x80130504u;
    // 80130504: bl      0x801307CC
    {
            ctx->lr = 0x80130508u;
            goto label_801307CC;
    }

label_80130508:
    ctx->pc = 0x80130508u;
    ctx->downcount -= 3;
    // 80130508: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013050C:
    ctx->pc = 0x8013050Cu;
    // 8013050C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130510:
    ctx->pc = 0x80130510u;
    // 80130510: bl      0x80143B20
    {
            ctx->lr = 0x80130514u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80130514:
    ctx->pc = 0x80130514u;
    ctx->downcount -= 16;
    // 80130514: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130518:
    ctx->pc = 0x80130518u;
    // 80130518: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013051C:
    ctx->pc = 0x8013051Cu;
    // 8013051C: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80130520:
    ctx->pc = 0x80130520u;
    // 80130520: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80130524:
    ctx->pc = 0x80130524u;
    // 80130524: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130528:
    ctx->pc = 0x80130528u;
    ctx->downcount -= 20;
    // 80130528: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013052C:
    ctx->pc = 0x8013052Cu;
    // 8013052C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80130530:
    ctx->pc = 0x80130530u;
    // 80130530: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130534:
    ctx->pc = 0x80130534u;
    // 80130534: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130538:
    ctx->pc = 0x80130538u;
    // 80130538: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013053C:
    ctx->pc = 0x8013053Cu;
    // 8013053C: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80130540:
    ctx->pc = 0x80130540u;
    // 80130540: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80130544:
    ctx->pc = 0x80130544u;
    // 80130544: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80130548:
    ctx->pc = 0x80130548u;
    // 80130548: addi    r3, r3, -22168
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-22168);

label_8013054C:
    ctx->pc = 0x8013054Cu;
    // 8013054C: bl      0x801009D0
    {
            ctx->lr = 0x80130550u;
            ctx->pc = 0x801009D0u;
            return;
    }

label_80130550:
    ctx->pc = 0x80130550u;
    ctx->downcount -= 4;
    // 80130550: addi    r3, r28, 732
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(732);

label_80130554:
    ctx->pc = 0x80130554u;
    // 80130554: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130558:
    ctx->pc = 0x80130558u;
    // 80130558: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013055C:
    ctx->pc = 0x8013055Cu;
    // 8013055C: bl      0x801009D0
    {
            ctx->lr = 0x80130560u;
            ctx->pc = 0x801009D0u;
            return;
    }

label_80130560:
    ctx->pc = 0x80130560u;
    ctx->downcount -= 4;
    // 80130560: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130564:
    ctx->pc = 0x80130564u;
    // 80130564: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130568:
    ctx->pc = 0x80130568u;
    // 80130568: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013056C:
    ctx->pc = 0x8013056Cu;
    // 8013056C: bl      0x80130584
    {
            ctx->lr = 0x80130570u;
            goto label_80130584;
    }

label_80130570:
    ctx->pc = 0x80130570u;
    ctx->downcount -= 16;
    // 80130570: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130574:
    ctx->pc = 0x80130574u;
    // 80130574: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80130578:
    ctx->pc = 0x80130578u;
    // 80130578: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8013057C:
    ctx->pc = 0x8013057Cu;
    // 8013057C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80130580:
    ctx->pc = 0x80130580u;
    // 80130580: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130584:
    ctx->pc = 0x80130584u;
    ctx->downcount -= 20;
    // 80130584: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130588:
    ctx->pc = 0x80130588u;
    // 80130588: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8013058C:
    ctx->pc = 0x8013058Cu;
    // 8013058C: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130590:
    ctx->pc = 0x80130590u;
    // 80130590: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130594:
    ctx->pc = 0x80130594u;
    // 80130594: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130598:
    ctx->pc = 0x80130598u;
    // 80130598: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8013059C:
    ctx->pc = 0x8013059Cu;
    // 8013059C: lwz     r3, 724(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801305A0:
    ctx->pc = 0x801305A0u;
    // 801305A0: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_801305A4:
    ctx->pc = 0x801305A4u;
    // 801305A4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801305A8:
    ctx->pc = 0x801305A8u;
    // 801305A8: bl      0x80148240
    {
            ctx->lr = 0x801305ACu;
            ctx->pc = 0x80148240u;
            return;
    }

label_801305AC:
    ctx->pc = 0x801305ACu;
    ctx->downcount -= 4;
    // 801305AC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801305B0:
    ctx->pc = 0x801305B0u;
    // 801305B0: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801305B4:
    ctx->pc = 0x801305B4u;
    // 801305B4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801305B8:
    ctx->pc = 0x801305B8u;
    // 801305B8: bl      0x801307CC
    {
            ctx->lr = 0x801305BCu;
            goto label_801307CC;
    }

label_801305BC:
    ctx->pc = 0x801305BCu;
    ctx->downcount -= 3;
    // 801305BC: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801305C0:
    ctx->pc = 0x801305C0u;
    // 801305C0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801305C4:
    ctx->pc = 0x801305C4u;
    // 801305C4: bl      0x80143B20
    {
            ctx->lr = 0x801305C8u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_801305C8:
    ctx->pc = 0x801305C8u;
    ctx->downcount -= 16;
    // 801305C8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801305CC:
    ctx->pc = 0x801305CCu;
    // 801305CC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801305D0:
    ctx->pc = 0x801305D0u;
    // 801305D0: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801305D4:
    ctx->pc = 0x801305D4u;
    // 801305D4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801305D8:
    ctx->pc = 0x801305D8u;
    // 801305D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801305DC:
    ctx->pc = 0x801305DCu;
    ctx->downcount -= 21;
    // 801305DC: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801305E0:
    ctx->pc = 0x801305E0u;
    // 801305E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801305E4:
    ctx->pc = 0x801305E4u;
    // 801305E4: stmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801305E8:
    ctx->pc = 0x801305E8u;
    // 801305E8: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801305EC:
    ctx->pc = 0x801305ECu;
    // 801305EC: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801305F0:
    ctx->pc = 0x801305F0u;
    // 801305F0: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801305F4:
    ctx->pc = 0x801305F4u;
    // 801305F4: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801305F8:
    ctx->pc = 0x801305F8u;
    // 801305F8: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_801305FC:
    ctx->pc = 0x801305FCu;
    // 801305FC: addi    r3, r3, -22168
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-22168);

label_80130600:
    ctx->pc = 0x80130600u;
    // 80130600: rlwinm r27, r30, 2, 0, 29
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[30], 2u) & 0xFFFFFFFCu;
    }

label_80130604:
    ctx->pc = 0x80130604u;
    // 80130604: bl      0x801009C0
    {
            ctx->lr = 0x80130608u;
            ctx->pc = 0x801009C0u;
            return;
    }

label_80130608:
    ctx->pc = 0x80130608u;
    ctx->downcount -= 4;
    // 80130608: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013060C:
    ctx->pc = 0x8013060Cu;
    // 8013060C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130610:
    ctx->pc = 0x80130610u;
    // 80130610: addi    r3, r28, 732
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(732);

label_80130614:
    ctx->pc = 0x80130614u;
    // 80130614: bl      0x801009C0
    {
            ctx->lr = 0x80130618u;
            ctx->pc = 0x801009C0u;
            return;
    }

label_80130618:
    ctx->pc = 0x80130618u;
    ctx->downcount -= 4;
    // 80130618: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8013061C:
    ctx->pc = 0x8013061Cu;
    // 8013061C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130620:
    ctx->pc = 0x80130620u;
    // 80130620: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130624:
    ctx->pc = 0x80130624u;
    // 80130624: bl      0x801306C0
    {
            ctx->lr = 0x80130628u;
            goto label_801306C0;
    }

label_80130628:
    ctx->pc = 0x80130628u;
    ctx->downcount -= 8;
    // 80130628: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_8013062C:
    ctx->pc = 0x8013062Cu;
    // 8013062C: lwz     r29, 696(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(696);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80130630:
    ctx->pc = 0x80130630u;
    // 80130630: addi    r30, r30, -25052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80130634:
    ctx->pc = 0x80130634u;
    // 80130634: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130638:
    ctx->pc = 0x80130638u;
    // 80130638: addi    r9, r30, 2932
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(2932);

label_8013063C:
    ctx->pc = 0x8013063Cu;
    // 8013063C: addi    r26, r30, 2964
    ctx->gpr[26] = ctx->gpr[30] + (u32)(s32)(2964);

label_80130640:
    ctx->pc = 0x80130640u;
    // 80130640: lwzx    r4, r9, r27
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80130644:
    ctx->pc = 0x80130644u;
    // 80130644: bl      0x801307CC
    {
            ctx->lr = 0x80130648u;
            goto label_801307CC;
    }

label_80130648:
    ctx->pc = 0x80130648u;
    ctx->downcount -= 3;
    // 80130648: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013064C:
    ctx->pc = 0x8013064Cu;
    // 8013064C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130650:
    ctx->pc = 0x80130650u;
    // 80130650: bl      0x80143B20
    {
            ctx->lr = 0x80130654u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80130654:
    ctx->pc = 0x80130654u;
    ctx->downcount -= 4;
    // 80130654: lwzx    r4, r26, r27
    {
        u32 ea = ctx->gpr[26] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80130658:
    ctx->pc = 0x80130658u;
    // 80130658: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8013065C:
    ctx->pc = 0x8013065Cu;
    // 8013065C: lwz     r29, 700(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(700);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80130660:
    ctx->pc = 0x80130660u;
    // 80130660: bl      0x801307CC
    {
            ctx->lr = 0x80130664u;
            goto label_801307CC;
    }

label_80130664:
    ctx->pc = 0x80130664u;
    ctx->downcount -= 3;
    // 80130664: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130668:
    ctx->pc = 0x80130668u;
    // 80130668: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013066C:
    ctx->pc = 0x8013066Cu;
    // 8013066C: bl      0x80143B20
    {
            ctx->lr = 0x80130670u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80130670:
    ctx->pc = 0x80130670u;
    ctx->downcount -= 5;
    // 80130670: addi    r30, r30, 2948
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(2948);

label_80130674:
    ctx->pc = 0x80130674u;
    // 80130674: lwz     r29, 708(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(708);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80130678:
    ctx->pc = 0x80130678u;
    // 80130678: lwzx    r4, r30, r27
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8013067C:
    ctx->pc = 0x8013067Cu;
    // 8013067C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130680:
    ctx->pc = 0x80130680u;
    // 80130680: bl      0x801307CC
    {
            ctx->lr = 0x80130684u;
            goto label_801307CC;
    }

label_80130684:
    ctx->pc = 0x80130684u;
    ctx->downcount -= 3;
    // 80130684: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130688:
    ctx->pc = 0x80130688u;
    // 80130688: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013068C:
    ctx->pc = 0x8013068Cu;
    // 8013068C: bl      0x80143B20
    {
            ctx->lr = 0x80130690u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80130690:
    ctx->pc = 0x80130690u;
    ctx->downcount -= 4;
    // 80130690: lwzx    r4, r26, r27
    {
        u32 ea = ctx->gpr[26] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80130694:
    ctx->pc = 0x80130694u;
    // 80130694: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130698:
    ctx->pc = 0x80130698u;
    // 80130698: lwz     r30, 712(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(712);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8013069C:
    ctx->pc = 0x8013069Cu;
    // 8013069C: bl      0x801307CC
    {
            ctx->lr = 0x801306A0u;
            goto label_801307CC;
    }

label_801306A0:
    ctx->pc = 0x801306A0u;
    ctx->downcount -= 3;
    // 801306A0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801306A4:
    ctx->pc = 0x801306A4u;
    // 801306A4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801306A8:
    ctx->pc = 0x801306A8u;
    // 801306A8: bl      0x80143B20
    {
            ctx->lr = 0x801306ACu;
            ctx->pc = 0x80143B20u;
            return;
    }

label_801306AC:
    ctx->pc = 0x801306ACu;
    ctx->downcount -= 16;
    // 801306AC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801306B0:
    ctx->pc = 0x801306B0u;
    // 801306B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801306B4:
    ctx->pc = 0x801306B4u;
    // 801306B4: lmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801306B8:
    ctx->pc = 0x801306B8u;
    // 801306B8: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801306BC:
    ctx->pc = 0x801306BCu;
    // 801306BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801306C0:
    ctx->pc = 0x801306C0u;
    ctx->downcount -= 20;
    // 801306C0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801306C4:
    ctx->pc = 0x801306C4u;
    // 801306C4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801306C8:
    ctx->pc = 0x801306C8u;
    // 801306C8: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801306CC:
    ctx->pc = 0x801306CCu;
    // 801306CC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801306D0:
    ctx->pc = 0x801306D0u;
    // 801306D0: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801306D4:
    ctx->pc = 0x801306D4u;
    // 801306D4: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801306D8:
    ctx->pc = 0x801306D8u;
    // 801306D8: lwz     r3, 724(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801306DC:
    ctx->pc = 0x801306DCu;
    // 801306DC: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_801306E0:
    ctx->pc = 0x801306E0u;
    // 801306E0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801306E4:
    ctx->pc = 0x801306E4u;
    // 801306E4: bl      0x80148240
    {
            ctx->lr = 0x801306E8u;
            ctx->pc = 0x80148240u;
            return;
    }

label_801306E8:
    ctx->pc = 0x801306E8u;
    ctx->downcount -= 4;
    // 801306E8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801306EC:
    ctx->pc = 0x801306ECu;
    // 801306EC: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801306F0:
    ctx->pc = 0x801306F0u;
    // 801306F0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801306F4:
    ctx->pc = 0x801306F4u;
    // 801306F4: bl      0x801307CC
    {
            ctx->lr = 0x801306F8u;
            goto label_801307CC;
    }

label_801306F8:
    ctx->pc = 0x801306F8u;
    ctx->downcount -= 3;
    // 801306F8: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801306FC:
    ctx->pc = 0x801306FCu;
    // 801306FC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130700:
    ctx->pc = 0x80130700u;
    // 80130700: bl      0x80143B20
    {
            ctx->lr = 0x80130704u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_80130704:
    ctx->pc = 0x80130704u;
    ctx->downcount -= 16;
    // 80130704: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130708:
    ctx->pc = 0x80130708u;
    // 80130708: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013070C:
    ctx->pc = 0x8013070Cu;
    // 8013070C: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80130710:
    ctx->pc = 0x80130710u;
    // 80130710: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80130714:
    ctx->pc = 0x80130714u;
    // 80130714: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130718:
    ctx->pc = 0x80130718u;
    ctx->downcount -= 20;
    // 80130718: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013071C:
    ctx->pc = 0x8013071Cu;
    // 8013071C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80130720:
    ctx->pc = 0x80130720u;
    // 80130720: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130724:
    ctx->pc = 0x80130724u;
    // 80130724: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130728:
    ctx->pc = 0x80130728u;
    // 80130728: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013072C:
    ctx->pc = 0x8013072Cu;
    // 8013072C: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80130730:
    ctx->pc = 0x80130730u;
    // 80130730: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80130734:
    ctx->pc = 0x80130734u;
    // 80130734: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80130738:
    ctx->pc = 0x80130738u;
    // 80130738: addi    r3, r3, -22168
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-22168);

label_8013073C:
    ctx->pc = 0x8013073Cu;
    // 8013073C: bl      0x801009E0
    {
            ctx->lr = 0x80130740u;
            ctx->pc = 0x801009E0u;
            return;
    }

label_80130740:
    ctx->pc = 0x80130740u;
    ctx->downcount -= 4;
    // 80130740: addi    r3, r28, 732
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(732);

label_80130744:
    ctx->pc = 0x80130744u;
    // 80130744: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130748:
    ctx->pc = 0x80130748u;
    // 80130748: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013074C:
    ctx->pc = 0x8013074Cu;
    // 8013074C: bl      0x801009E0
    {
            ctx->lr = 0x80130750u;
            ctx->pc = 0x801009E0u;
            return;
    }

label_80130750:
    ctx->pc = 0x80130750u;
    ctx->downcount -= 4;
    // 80130750: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130754:
    ctx->pc = 0x80130754u;
    // 80130754: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130758:
    ctx->pc = 0x80130758u;
    // 80130758: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013075C:
    ctx->pc = 0x8013075Cu;
    // 8013075C: bl      0x80130774
    {
            ctx->lr = 0x80130760u;
            goto label_80130774;
    }

label_80130760:
    ctx->pc = 0x80130760u;
    ctx->downcount -= 16;
    // 80130760: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130764:
    ctx->pc = 0x80130764u;
    // 80130764: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80130768:
    ctx->pc = 0x80130768u;
    // 80130768: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8013076C:
    ctx->pc = 0x8013076Cu;
    // 8013076C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80130770:
    ctx->pc = 0x80130770u;
    // 80130770: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130774:
    ctx->pc = 0x80130774u;
    ctx->downcount -= 20;
    // 80130774: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130778:
    ctx->pc = 0x80130778u;
    // 80130778: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8013077C:
    ctx->pc = 0x8013077Cu;
    // 8013077C: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130780:
    ctx->pc = 0x80130780u;
    // 80130780: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130784:
    ctx->pc = 0x80130784u;
    // 80130784: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130788:
    ctx->pc = 0x80130788u;
    // 80130788: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8013078C:
    ctx->pc = 0x8013078Cu;
    // 8013078C: lwz     r3, 724(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(724);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80130790:
    ctx->pc = 0x80130790u;
    // 80130790: li      r4, 8
    ctx->gpr[4] = (u32)(s32)(8);

label_80130794:
    ctx->pc = 0x80130794u;
    // 80130794: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80130798:
    ctx->pc = 0x80130798u;
    // 80130798: bl      0x80148240
    {
            ctx->lr = 0x8013079Cu;
            ctx->pc = 0x80148240u;
            return;
    }

label_8013079C:
    ctx->pc = 0x8013079Cu;
    ctx->downcount -= 4;
    // 8013079C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801307A0:
    ctx->pc = 0x801307A0u;
    // 801307A0: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801307A4:
    ctx->pc = 0x801307A4u;
    // 801307A4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801307A8:
    ctx->pc = 0x801307A8u;
    // 801307A8: bl      0x801307CC
    {
            ctx->lr = 0x801307ACu;
            goto label_801307CC;
    }

label_801307AC:
    ctx->pc = 0x801307ACu;
    ctx->downcount -= 3;
    // 801307AC: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801307B0:
    ctx->pc = 0x801307B0u;
    // 801307B0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801307B4:
    ctx->pc = 0x801307B4u;
    // 801307B4: bl      0x80143B20
    {
            ctx->lr = 0x801307B8u;
            ctx->pc = 0x80143B20u;
            return;
    }

label_801307B8:
    ctx->pc = 0x801307B8u;
    ctx->downcount -= 16;
    // 801307B8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801307BC:
    ctx->pc = 0x801307BCu;
    // 801307BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801307C0:
    ctx->pc = 0x801307C0u;
    // 801307C0: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801307C4:
    ctx->pc = 0x801307C4u;
    // 801307C4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801307C8:
    ctx->pc = 0x801307C8u;
    // 801307C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801307CC:
    ctx->pc = 0x801307CCu;
    ctx->downcount -= 3;
    // 801307CC: li      r3, 31
    ctx->gpr[3] = (u32)(s32)(31);

label_801307D0:
    ctx->pc = 0x801307D0u;
    // 801307D0: cmpwi   r4, 3
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

label_801307D4:
    ctx->pc = 0x801307D4u;
    // 801307D4: bc    12, 2, 0x80130824
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130824;
        }
    }

label_801307D8:
    ctx->pc = 0x801307D8u;
    ctx->downcount -= 1;
    // 801307D8: bc    12, 1, 0x801307F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801307F4;
        }
    }

label_801307DC:
    ctx->pc = 0x801307DCu;
    ctx->downcount -= 2;
    // 801307DC: cmpwi   r4, 1
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801307E0:
    ctx->pc = 0x801307E0u;
    // 801307E0: bc    12, 2, 0x80130814
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130814;
        }
    }

label_801307E4:
    ctx->pc = 0x801307E4u;
    ctx->downcount -= 1;
    // 801307E4: bc    12, 1, 0x8013081C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013081C;
        }
    }

label_801307E8:
    ctx->pc = 0x801307E8u;
    ctx->downcount -= 2;
    // 801307E8: cmpwi   r4, 0
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

label_801307EC:
    ctx->pc = 0x801307ECu;
    // 801307EC: bc    12, 2, 0x8013080C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013080C;
        }
    }

label_801307F0:
    ctx->pc = 0x801307F0u;
    ctx->downcount -= 1;
    // 801307F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801307F4:
    ctx->pc = 0x801307F4u;
    ctx->downcount -= 2;
    // 801307F4: cmpwi   r4, 5
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801307F8:
    ctx->pc = 0x801307F8u;
    // 801307F8: bc    12, 2, 0x80130834
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130834;
        }
    }

label_801307FC:
    ctx->pc = 0x801307FCu;
    ctx->downcount -= 1;
    // 801307FC: bc    12, 0, 0x8013082C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013082C;
        }
    }

label_80130800:
    ctx->pc = 0x80130800u;
    ctx->downcount -= 2;
    // 80130800: cmpwi   r4, 6
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80130804:
    ctx->pc = 0x80130804u;
    // 80130804: bc    12, 2, 0x8013083C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013083C;
        }
    }

label_80130808:
    ctx->pc = 0x80130808u;
    ctx->downcount -= 1;
    // 80130808: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013080C:
    ctx->pc = 0x8013080Cu;
    ctx->downcount -= 2;
    // 8013080C: li      r3, 8
    ctx->gpr[3] = (u32)(s32)(8);

label_80130810:
    ctx->pc = 0x80130810u;
    // 80130810: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130814:
    ctx->pc = 0x80130814u;
    ctx->downcount -= 2;
    // 80130814: li      r3, 9
    ctx->gpr[3] = (u32)(s32)(9);

label_80130818:
    ctx->pc = 0x80130818u;
    // 80130818: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013081C:
    ctx->pc = 0x8013081Cu;
    ctx->downcount -= 2;
    // 8013081C: li      r3, 10
    ctx->gpr[3] = (u32)(s32)(10);

label_80130820:
    ctx->pc = 0x80130820u;
    // 80130820: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130824:
    ctx->pc = 0x80130824u;
    ctx->downcount -= 2;
    // 80130824: li      r3, 11
    ctx->gpr[3] = (u32)(s32)(11);

label_80130828:
    ctx->pc = 0x80130828u;
    // 80130828: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013082C:
    ctx->pc = 0x8013082Cu;
    ctx->downcount -= 2;
    // 8013082C: li      r3, 12
    ctx->gpr[3] = (u32)(s32)(12);

label_80130830:
    ctx->pc = 0x80130830u;
    // 80130830: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130834:
    ctx->pc = 0x80130834u;
    ctx->downcount -= 2;
    // 80130834: li      r3, 13
    ctx->gpr[3] = (u32)(s32)(13);

label_80130838:
    ctx->pc = 0x80130838u;
    // 80130838: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013083C:
    ctx->pc = 0x8013083Cu;
    ctx->downcount -= 2;
    // 8013083C: li      r3, 14
    ctx->gpr[3] = (u32)(s32)(14);

label_80130840:
    ctx->pc = 0x80130840u;
    // 80130840: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130844:
    ctx->pc = 0x80130844u;
    ctx->downcount -= 2;
    // 80130844: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80130848:
    ctx->pc = 0x80130848u;
    // 80130848: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013084C:
    ctx->pc = 0x8013084Cu;
    ctx->downcount -= 5;
    // 8013084C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130850:
    ctx->pc = 0x80130850u;
    // 80130850: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80130854:
    ctx->pc = 0x80130854u;
    // 80130854: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130858:
    ctx->pc = 0x80130858u;
    // 80130858: lwz     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8013085C:
    ctx->pc = 0x8013085Cu;
    // 8013085C: bl      0x801B1564
    {
            ctx->lr = 0x80130860u;
            ctx->pc = 0x801B1564u;
            return;
    }

label_80130860:
    ctx->pc = 0x80130860u;
    ctx->downcount -= 6;
    // 80130860: xori    r3, r3, 0x0001
    ctx->gpr[3] = ctx->gpr[3] ^ 0x0001u;

label_80130864:
    ctx->pc = 0x80130864u;
    // 80130864: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130868:
    ctx->pc = 0x80130868u;
    // 80130868: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013086C:
    ctx->pc = 0x8013086Cu;
    // 8013086C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80130870:
    ctx->pc = 0x80130870u;
    // 80130870: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130874:
    ctx->pc = 0x80130874u;
    ctx->downcount -= 18;
    // 80130874: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130878:
    ctx->pc = 0x80130878u;
    // 80130878: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8013087C:
    ctx->pc = 0x8013087Cu;
    // 8013087C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130880:
    ctx->pc = 0x80130880u;
    // 80130880: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130884:
    ctx->pc = 0x80130884u;
    // 80130884: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130888:
    ctx->pc = 0x80130888u;
    // 80130888: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8013088C:
    ctx->pc = 0x8013088Cu;
    // 8013088C: lwz     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80130890:
    ctx->pc = 0x80130890u;
    // 80130890: bl      0x801B1564
    {
            ctx->lr = 0x80130894u;
            ctx->pc = 0x801B1564u;
            return;
    }

label_80130894:
    ctx->pc = 0x80130894u;
    ctx->downcount -= 2;
    // 80130894: cmpwi   r3, 0
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

label_80130898:
    ctx->pc = 0x80130898u;
    // 80130898: bc    12, 2, 0x801308E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801308E0;
        }
    }

label_8013089C:
    ctx->pc = 0x8013089Cu;
    ctx->downcount -= 2;
    // 8013089C: cmpwi   r30, -1
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801308A0:
    ctx->pc = 0x801308A0u;
    // 801308A0: bc    12, 2, 0x801308E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801308E0;
        }
    }

label_801308A4:
    ctx->pc = 0x801308A4u;
    ctx->downcount -= 16;
    // 801308A4: mulli   r11, r30, 48
    ctx->gpr[11] = (u32)((s64)(s32)ctx->gpr[30] * (s64)(s32)48);

label_801308A8:
    ctx->pc = 0x801308A8u;
    // 801308A8: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_801308AC:
    ctx->pc = 0x801308ACu;
    // 801308AC: addi    r9, r9, -25052
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-25052);

label_801308B0:
    ctx->pc = 0x801308B0u;
    // 801308B0: lwz     r10, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801308B4:
    ctx->pc = 0x801308B4u;
    // 801308B4: li      r30, 1
    ctx->gpr[30] = (u32)(s32)(1);

label_801308B8:
    ctx->pc = 0x801308B8u;
    // 801308B8: addi    r9, r9, 3060
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(3060);

label_801308BC:
    ctx->pc = 0x801308BCu;
    // 801308BC: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_801308C0:
    ctx->pc = 0x801308C0u;
    // 801308C0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801308C4:
    ctx->pc = 0x801308C4u;
    // 801308C4: stwx    r30, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801308C8:
    ctx->pc = 0x801308C8u;
    // 801308C8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801308CC:
    ctx->pc = 0x801308CCu;
    // 801308CC: stw     r0, 388(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(388);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801308D0:
    ctx->pc = 0x801308D0u;
    // 801308D0: stw     r30, 860(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(860);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801308D4:
    ctx->pc = 0x801308D4u;
    // 801308D4: lwz     r3, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801308D8:
    ctx->pc = 0x801308D8u;
    // 801308D8: bl      0x801C0BFC
    {
            ctx->lr = 0x801308DCu;
            ctx->pc = 0x801C0BFCu;
            return;
    }

label_801308DC:
    ctx->pc = 0x801308DCu;
    ctx->downcount -= 1;
    // 801308DC: stw     r30, 864(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(864);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801308E0:
    ctx->pc = 0x801308E0u;
    ctx->downcount -= 16;
    // 801308E0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801308E4:
    ctx->pc = 0x801308E4u;
    // 801308E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801308E8:
    ctx->pc = 0x801308E8u;
    // 801308E8: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801308EC:
    ctx->pc = 0x801308ECu;
    // 801308EC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801308F0:
    ctx->pc = 0x801308F0u;
    // 801308F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801308F4:
    ctx->pc = 0x801308F4u;
    ctx->downcount -= 5;
    // 801308F4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801308F8:
    ctx->pc = 0x801308F8u;
    // 801308F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801308FC:
    ctx->pc = 0x801308FCu;
    // 801308FC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130900:
    ctx->pc = 0x80130900u;
    // 80130900: lwz     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80130904:
    ctx->pc = 0x80130904u;
    // 80130904: bl      0x801B1564
    {
            ctx->lr = 0x80130908u;
            ctx->pc = 0x801B1564u;
            return;
    }

label_80130908:
    ctx->pc = 0x80130908u;
    ctx->downcount -= 2;
    // 80130908: cmpwi   r3, 0
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

label_8013090C:
    ctx->pc = 0x8013090Cu;
    // 8013090C: bc    12, 2, 0x80130930
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130930;
        }
    }

label_80130910:
    ctx->pc = 0x80130910u;
    ctx->downcount -= 4;
    // 80130910: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130914:
    ctx->pc = 0x80130914u;
    // 80130914: lwz     r11, 52(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(52);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80130918:
    ctx->pc = 0x80130918u;
    // 80130918: lwz     r3, 324(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(324);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8013091C:
    ctx->pc = 0x8013091Cu;
    // 8013091C: bl      0x8011ABFC
    {
            ctx->lr = 0x80130920u;
            ctx->pc = 0x8011ABFCu;
            return;
    }

label_80130920:
    ctx->pc = 0x80130920u;
    ctx->downcount -= 4;
    // 80130920: xori    r3, r3, 0x0001
    ctx->gpr[3] = ctx->gpr[3] ^ 0x0001u;

label_80130924:
    ctx->pc = 0x80130924u;
    // 80130924: subfic  r0, r3, 0
    {
        u64 res = (u64)(u32)(s32)(0) + (u64)(~ctx->gpr[3]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80130928:
    ctx->pc = 0x80130928u;
    // 80130928: adde   r3, r0, r3
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8013092C:
    ctx->pc = 0x8013092Cu;
    // 8013092C: b       0x80130934
    {
            goto label_80130934;
    }

label_80130930:
    ctx->pc = 0x80130930u;
    ctx->downcount -= 1;
    // 80130930: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80130934:
    ctx->pc = 0x80130934u;
    ctx->downcount -= 5;
    // 80130934: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130938:
    ctx->pc = 0x80130938u;
    // 80130938: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013093C:
    ctx->pc = 0x8013093Cu;
    // 8013093C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80130940:
    ctx->pc = 0x80130940u;
    // 80130940: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130944:
    ctx->pc = 0x80130944u;
    ctx->downcount -= 10;
    // 80130944: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130948:
    ctx->pc = 0x80130948u;
    // 80130948: addi    r4, r4, -1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-1);

label_8013094C:
    ctx->pc = 0x8013094Cu;
    // 8013094C: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80130950:
    ctx->pc = 0x80130950u;
    // 80130950: rlwinm r4, r4, 31, 1, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFCu;
    }

label_80130954:
    ctx->pc = 0x80130954u;
    // 80130954: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80130958:
    ctx->pc = 0x80130958u;
    // 80130958: lwzx    r0, r4, r9
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013095C:
    ctx->pc = 0x8013095Cu;
    // 8013095C: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130960:
    ctx->pc = 0x80130960u;
    // 80130960: stwx    r3, r4, r9
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[9];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80130964:
    ctx->pc = 0x80130964u;
    // 80130964: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80130968:
    ctx->pc = 0x80130968u;
    // 80130968: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013096C:
    ctx->pc = 0x8013096Cu;
    ctx->downcount -= 7;
    // 8013096C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130970:
    ctx->pc = 0x80130970u;
    // 80130970: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80130974:
    ctx->pc = 0x80130974u;
    // 80130974: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130978:
    ctx->pc = 0x80130978u;
    // 80130978: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8013097C:
    ctx->pc = 0x8013097Cu;
    // 8013097C: lis     r4, 30561
    ctx->gpr[4] = ((u32)(s32)(30561) << 16);

label_80130980:
    ctx->pc = 0x80130980u;
    // 80130980: ori     r4, r4, 0x7665
    ctx->gpr[4] = ctx->gpr[4] | 0x7665u;

label_80130984:
    ctx->pc = 0x80130984u;
    // 80130984: bl      0x80213200
    {
            ctx->lr = 0x80130988u;
            ctx->pc = 0x80213200u;
            return;
    }

label_80130988:
    ctx->pc = 0x80130988u;
    ctx->downcount -= 5;
    // 80130988: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013098C:
    ctx->pc = 0x8013098Cu;
    // 8013098C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80130990:
    ctx->pc = 0x80130990u;
    // 80130990: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80130994:
    ctx->pc = 0x80130994u;
    // 80130994: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130998:
    ctx->pc = 0x80130998u;
    ctx->downcount -= 7;
    // 80130998: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013099C:
    ctx->pc = 0x8013099Cu;
    // 8013099C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801309A0:
    ctx->pc = 0x801309A0u;
    // 801309A0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801309A4:
    ctx->pc = 0x801309A4u;
    // 801309A4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801309A8:
    ctx->pc = 0x801309A8u;
    // 801309A8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801309AC:
    ctx->pc = 0x801309ACu;
    // 801309AC: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_801309B0:
    ctx->pc = 0x801309B0u;
    // 801309B0: bl      0x8012F814
    {
            ctx->lr = 0x801309B4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8012F814u;
                return;
            }
            goto label_8012F814;
    }

label_801309B4:
    ctx->pc = 0x801309B4u;
    ctx->downcount -= 5;
    // 801309B4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801309B8:
    ctx->pc = 0x801309B8u;
    // 801309B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801309BC:
    ctx->pc = 0x801309BCu;
    // 801309BC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801309C0:
    ctx->pc = 0x801309C0u;
    // 801309C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801309C4:
    ctx->pc = 0x801309C4u;
    ctx->downcount -= 18;
    // 801309C4: stwu     r1, -400(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-400);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801309C8:
    ctx->pc = 0x801309C8u;
    // 801309C8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801309CC:
    ctx->pc = 0x801309CCu;
    // 801309CC: stfd     f31, 392(r1)
    if (!ppc_fp_available_inline(ctx, 0x801309CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(392);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_801309D0:
    ctx->pc = 0x801309D0u;
    // 801309D0: stmw     r14, 320(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(320);
        for (u32 r = 14; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801309D4:
    ctx->pc = 0x801309D4u;
    // 801309D4: stw     r0, 404(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(404);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801309D8:
    ctx->pc = 0x801309D8u;
    // 801309D8: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801309DC:
    ctx->pc = 0x801309DCu;
    // 801309DC: or   r21, r4, r4
    {
        ctx->gpr[21] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801309E0:
    ctx->pc = 0x801309E0u;
    // 801309E0: bl      0x800EE0E8
    {
            ctx->lr = 0x801309E4u;
            ctx->pc = 0x800EE0E8u;
            return;
    }

label_801309E4:
    ctx->pc = 0x801309E4u;
    ctx->downcount -= 7;
    // 801309E4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801309E8:
    ctx->pc = 0x801309E8u;
    // 801309E8: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_801309EC:
    ctx->pc = 0x801309ECu;
    // 801309EC: addi    r9, r9, 17920
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17920);

label_801309F0:
    ctx->pc = 0x801309F0u;
    // 801309F0: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_801309F4:
    ctx->pc = 0x801309F4u;
    // 801309F4: stw     r9, 108(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801309F8:
    ctx->pc = 0x801309F8u;
    // 801309F8: addi    r14, r1, 8
    ctx->gpr[14] = ctx->gpr[1] + (u32)(s32)(8);

label_801309FC:
    ctx->downcount -= 1;
    // 801309FC: bc    16, 0, 0x801309FC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801309FCu;
                return;
            }
            goto label_801309FC;
        }
    }

label_80130A00:
    ctx->pc = 0x80130A00u;
    ctx->downcount -= 5;
    // 80130A00: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80130A04:
    ctx->pc = 0x80130A04u;
    // 80130A04: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80130A08:
    ctx->pc = 0x80130A08u;
    // 80130A08: stb     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80130A0C:
    ctx->pc = 0x80130A0Cu;
    // 80130A0C: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80130A10:
    ctx->pc = 0x80130A10u;
    // 80130A10: bl      0x80100A40
    {
            ctx->lr = 0x80130A14u;
            ctx->pc = 0x80100A40u;
            return;
    }

label_80130A14:
    ctx->pc = 0x80130A14u;
    ctx->downcount -= 3;
    // 80130A14: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130A18:
    ctx->pc = 0x80130A18u;
    // 80130A18: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80130A1C:
    ctx->pc = 0x80130A1Cu;
    // 80130A1C: bl      0x80100368
    {
            ctx->lr = 0x80130A20u;
            ctx->pc = 0x80100368u;
            return;
    }

label_80130A20:
    ctx->pc = 0x80130A20u;
    ctx->downcount -= 6;
    // 80130A20: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130A24:
    ctx->pc = 0x80130A24u;
    // 80130A24: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80130A28:
    ctx->pc = 0x80130A28u;
    // 80130A28: addi    r4, r4, 17816
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(17816);

label_80130A2C:
    ctx->pc = 0x80130A2Cu;
    // 80130A2C: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_80130A30:
    ctx->pc = 0x80130A30u;
    // 80130A30: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80130A34:
    ctx->pc = 0x80130A34u;
    // 80130A34: bl      0x8009258C
    {
            ctx->lr = 0x80130A38u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80130A38:
    ctx->pc = 0x80130A38u;
    ctx->downcount -= 4;
    // 80130A38: lwz     r0, 8(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130A3C:
    ctx->pc = 0x80130A3Cu;
    // 80130A3C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80130A40:
    ctx->pc = 0x80130A40u;
    // 80130A40: cmpw    r10, r0
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

label_80130A44:
    ctx->pc = 0x80130A44u;
    // 80130A44: bc    4, 0, 0x80130D34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80130D34;
        }
    }

label_80130A48:
    ctx->pc = 0x80130A48u;
    ctx->downcount -= 2;
    // 80130A48: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80130A4C:
    ctx->pc = 0x80130A4Cu;
    // 80130A4C: lfs     f31, 17868(r9)
    if (!ppc_fp_available_inline(ctx, 0x80130A4Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(17868);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80130A50:
    ctx->downcount -= 12;
    // 80130A50: mulli   r9, r10, 68
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[10] * (s64)(s32)68);

label_80130A54:
    ctx->pc = 0x80130A54u;
    // 80130A54: lwz     r11, 12(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80130A58:
    // 80130A58: addi    r10, r10, 1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(1);

label_80130A5C:
    ctx->pc = 0x80130A5Cu;
    // 80130A5C: stw     r10, 304(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(304);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80130A60:
    // 80130A60: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80130A64:
    // 80130A64: or   r20, r9, r9
    {
        ctx->gpr[20] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80130A68:
    // 80130A68: add   r9, r9, r11
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80130A6C:
    ctx->pc = 0x80130A6Cu;
    // 80130A6C: lwz     r0, 60(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130A70:
    // 80130A70: cmpw    r30, r0
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

label_80130A74:
    // 80130A74: bc    4, 0, 0x80130D24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80130D24;
        }
    }

label_80130A78:
    ctx->downcount -= 9;
    // 80130A78: lis     r9, -32711
    ctx->gpr[9] = ((u32)(s32)(-32711) << 16);

label_80130A7C:
    // 80130A7C: addi    r22, r1, 272
    ctx->gpr[22] = ctx->gpr[1] + (u32)(s32)(272);

label_80130A80:
    // 80130A80: addi    r15, r9, -23792
    ctx->gpr[15] = ctx->gpr[9] + (u32)(s32)(-23792);

label_80130A84:
    // 80130A84: addi    r27, r28, 496
    ctx->gpr[27] = ctx->gpr[28] + (u32)(s32)(496);

label_80130A88:
    // 80130A88: lis     r9, -32711
    ctx->gpr[9] = ((u32)(s32)(-32711) << 16);

label_80130A8C:
    // 80130A8C: addi    r23, r28, 532
    ctx->gpr[23] = ctx->gpr[28] + (u32)(s32)(532);

label_80130A90:
    // 80130A90: addi    r16, r9, -23776
    ctx->gpr[16] = ctx->gpr[9] + (u32)(s32)(-23776);

label_80130A94:
    // 80130A94: addi    r24, r28, 508
    ctx->gpr[24] = ctx->gpr[28] + (u32)(s32)(508);

label_80130A98:
    // 80130A98: addi    r25, r28, 520
    ctx->gpr[25] = ctx->gpr[28] + (u32)(s32)(520);

label_80130A9C:
    ctx->downcount -= 2;
    // 80130A9C: addi    r3, r1, 272
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(272);

label_80130AA0:
    // 80130AA0: bl      0x80122804
    {
            ctx->lr = 0x80130AA4u;
            ctx->pc = 0x80122804u;
            return;
    }

label_80130AA4:
    ctx->pc = 0x80130AA4u;
    ctx->downcount -= 15;
    // 80130AA4: lwz     r9, 12(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130AA8:
    // 80130AA8: rlwinm r10, r30, 3, 0, 28
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[30], 3u) & 0xFFFFFFF8u;
    }

label_80130AAC:
    // 80130AAC: add   r9, r20, r9
    {
        u32 a = ctx->gpr[20];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80130AB0:
    // 80130AB0: addi    r9, r9, 60
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(60);

label_80130AB4:
    ctx->pc = 0x80130AB4u;
    // 80130AB4: lwz     r11, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80130AB8:
    // 80130AB8: addi    r11, r11, 4
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4);

label_80130ABC:
    // 80130ABC: add   r9, r9, r11
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80130AC0:
    ctx->pc = 0x80130AC0u;
    // 80130AC0: lwzx    r0, r9, r10
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[10];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130AC4:
    // 80130AC4: add   r9, r9, r10
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80130AC8:
    // 80130AC8: add   r9, r9, r0
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80130ACC:
    ctx->pc = 0x80130ACCu;
    // 80130ACC: lwzu     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_80130AD0:
    // 80130AD0: or   r4, r9, r9
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80130AD4:
    // 80130AD4: cmpwi   r0, 1
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

label_80130AD8:
    // 80130AD8: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80130ADC:
    // 80130ADC: bc    12, 2, 0x80130AE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130AE4;
        }
    }

label_80130AE0:
    ctx->downcount -= 1;
    // 80130AE0: add   r29, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_80130AE4:
    ctx->pc = 0x80130AE4u;
    ctx->downcount -= 90;
    // 80130AE4: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130AE8:
    // 80130AE8: lis     r9, -32711
    ctx->gpr[9] = ((u32)(s32)(-32711) << 16);

label_80130AEC:
    // 80130AEC: addi    r10, r29, 8
    ctx->gpr[10] = ctx->gpr[29] + (u32)(s32)(8);

label_80130AF0:
    // 80130AF0: addi    r8, r29, 20
    ctx->gpr[8] = ctx->gpr[29] + (u32)(s32)(20);

label_80130AF4:
    ctx->pc = 0x80130AF4u;
    // 80130AF4: stw     r0, 488(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(488);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130AF8:
    // 80130AF8: addi    r7, r29, 32
    ctx->gpr[7] = ctx->gpr[29] + (u32)(s32)(32);

label_80130AFC:
    // 80130AFC: addi    r6, r29, 44
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(44);

label_80130B00:
    // 80130B00: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80130B04:
    ctx->pc = 0x80130B04u;
    // 80130B04: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130B08:
    // 80130B08: addi    r17, r30, 1
    ctx->gpr[17] = ctx->gpr[30] + (u32)(s32)(1);

label_80130B0C:
    // 80130B0C: addi    r19, r28, 584
    ctx->gpr[19] = ctx->gpr[28] + (u32)(s32)(584);

label_80130B10:
    // 80130B10: addi    r18, r28, 488
    ctx->gpr[18] = ctx->gpr[28] + (u32)(s32)(488);

label_80130B14:
    ctx->pc = 0x80130B14u;
    // 80130B14: stw     r0, 492(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(492);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130B18:
    ctx->pc = 0x80130B18u;
    // 80130B18: lfs     f0, -23792(r9)
    if (!ppc_fp_available_inline(ctx, 0x80130B18u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-23792);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80130B1C:
    ctx->pc = 0x80130B1Cu;
    // 80130B1C: lfs     f13, 4(r15)
    if (!ppc_fp_available_inline(ctx, 0x80130B1Cu)) return;
    {
        u32 ea = ctx->gpr[15] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80130B20:
    ctx->pc = 0x80130B20u;
    // 80130B20: lfs     f12, 8(r15)
    if (!ppc_fp_available_inline(ctx, 0x80130B20u)) return;
    {
        u32 ea = ctx->gpr[15] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_80130B24:
    ctx->pc = 0x80130B24u;
    // 80130B24: stfs     f0, 288(r1)
    if (!ppc_fp_available_inline(ctx, 0x80130B24u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(288);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80130B28:
    ctx->pc = 0x80130B28u;
    // 80130B28: stfs     f13, 292(r1)
    if (!ppc_fp_available_inline(ctx, 0x80130B28u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(292);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80130B2C:
    ctx->pc = 0x80130B2Cu;
    // 80130B2C: stfs     f12, 296(r1)
    if (!ppc_fp_available_inline(ctx, 0x80130B2Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(296);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_80130B30:
    ctx->pc = 0x80130B30u;
    // 80130B30: lwz     r0, 288(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(288);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130B34:
    ctx->pc = 0x80130B34u;
    // 80130B34: lwz     r9, 292(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(292);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130B38:
    ctx->pc = 0x80130B38u;
    // 80130B38: lwz     r11, 296(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(296);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80130B3C:
    ctx->pc = 0x80130B3Cu;
    // 80130B3C: stw     r0, 496(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(496);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130B40:
    ctx->pc = 0x80130B40u;
    // 80130B40: stw     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130B44:
    ctx->pc = 0x80130B44u;
    // 80130B44: stw     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80130B48:
    // 80130B48: lis     r9, -32711
    ctx->gpr[9] = ((u32)(s32)(-32711) << 16);

label_80130B4C:
    ctx->pc = 0x80130B4Cu;
    // 80130B4C: lfs     f0, -23776(r9)
    if (!ppc_fp_available_inline(ctx, 0x80130B4Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-23776);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80130B50:
    ctx->pc = 0x80130B50u;
    // 80130B50: lfs     f13, 4(r16)
    if (!ppc_fp_available_inline(ctx, 0x80130B50u)) return;
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80130B54:
    ctx->pc = 0x80130B54u;
    // 80130B54: lfs     f12, 8(r16)
    if (!ppc_fp_available_inline(ctx, 0x80130B54u)) return;
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_80130B58:
    ctx->pc = 0x80130B58u;
    // 80130B58: stfs     f0, 288(r1)
    if (!ppc_fp_available_inline(ctx, 0x80130B58u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(288);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80130B5C:
    ctx->pc = 0x80130B5Cu;
    // 80130B5C: stfs     f13, 292(r1)
    if (!ppc_fp_available_inline(ctx, 0x80130B5Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(292);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80130B60:
    ctx->pc = 0x80130B60u;
    // 80130B60: stfs     f12, 296(r1)
    if (!ppc_fp_available_inline(ctx, 0x80130B60u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(296);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_80130B64:
    ctx->pc = 0x80130B64u;
    // 80130B64: lwz     r0, 288(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(288);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130B68:
    ctx->pc = 0x80130B68u;
    // 80130B68: lwz     r9, 292(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(292);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130B6C:
    ctx->pc = 0x80130B6Cu;
    // 80130B6C: lwz     r11, 296(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(296);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80130B70:
    ctx->pc = 0x80130B70u;
    // 80130B70: stw     r0, 532(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(532);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130B74:
    ctx->pc = 0x80130B74u;
    // 80130B74: stw     r9, 4(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130B78:
    ctx->pc = 0x80130B78u;
    // 80130B78: stw     r11, 8(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80130B7C:
    ctx->pc = 0x80130B7Cu;
    // 80130B7C: lwz     r0, 532(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(532);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130B80:
    ctx->pc = 0x80130B80u;
    // 80130B80: stw     r0, 508(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130B84:
    ctx->pc = 0x80130B84u;
    // 80130B84: stw     r9, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130B88:
    ctx->pc = 0x80130B88u;
    // 80130B88: stw     r11, 8(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80130B8C:
    ctx->pc = 0x80130B8Cu;
    // 80130B8C: lwz     r0, 508(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130B90:
    ctx->pc = 0x80130B90u;
    // 80130B90: stw     r0, 520(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(520);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130B94:
    ctx->pc = 0x80130B94u;
    // 80130B94: stw     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130B98:
    ctx->pc = 0x80130B98u;
    // 80130B98: stw     r11, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80130B9C:
    ctx->pc = 0x80130B9Cu;
    // 80130B9C: stfs     f31, 48(r27)
    if (!ppc_fp_available_inline(ctx, 0x80130B9Cu)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80130BA0:
    ctx->pc = 0x80130BA0u;
    // 80130BA0: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130BA4:
    ctx->pc = 0x80130BA4u;
    // 80130BA4: lwz     r11, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80130BA8:
    ctx->pc = 0x80130BA8u;
    // 80130BA8: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130BAC:
    ctx->pc = 0x80130BACu;
    // 80130BAC: stw     r9, 496(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(496);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130BB0:
    ctx->pc = 0x80130BB0u;
    // 80130BB0: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130BB4:
    ctx->pc = 0x80130BB4u;
    // 80130BB4: stw     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80130BB8:
    ctx->pc = 0x80130BB8u;
    // 80130BB8: lwz     r9, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130BBC:
    ctx->pc = 0x80130BBCu;
    // 80130BBC: lwz     r11, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80130BC0:
    ctx->pc = 0x80130BC0u;
    // 80130BC0: lwz     r0, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130BC4:
    ctx->pc = 0x80130BC4u;
    // 80130BC4: stw     r9, 508(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130BC8:
    ctx->pc = 0x80130BC8u;
    // 80130BC8: stw     r0, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130BCC:
    ctx->pc = 0x80130BCCu;
    // 80130BCC: stw     r11, 8(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80130BD0:
    ctx->pc = 0x80130BD0u;
    // 80130BD0: lwz     r9, 32(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130BD4:
    ctx->pc = 0x80130BD4u;
    // 80130BD4: lwz     r11, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80130BD8:
    ctx->pc = 0x80130BD8u;
    // 80130BD8: lwz     r0, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130BDC:
    ctx->pc = 0x80130BDCu;
    // 80130BDC: stw     r9, 520(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(520);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130BE0:
    ctx->pc = 0x80130BE0u;
    // 80130BE0: stw     r0, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130BE4:
    ctx->pc = 0x80130BE4u;
    // 80130BE4: stw     r11, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80130BE8:
    ctx->pc = 0x80130BE8u;
    // 80130BE8: lwz     r9, 44(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(44);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130BEC:
    ctx->pc = 0x80130BECu;
    // 80130BEC: lwz     r0, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130BF0:
    ctx->pc = 0x80130BF0u;
    // 80130BF0: lwz     r11, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80130BF4:
    ctx->pc = 0x80130BF4u;
    // 80130BF4: stw     r9, 532(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(532);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130BF8:
    ctx->pc = 0x80130BF8u;
    // 80130BF8: stw     r0, 4(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130BFC:
    ctx->pc = 0x80130BFCu;
    // 80130BFC: stw     r11, 8(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80130C00:
    ctx->pc = 0x80130C00u;
    // 80130C00: lfs     f0, 56(r29)
    if (!ppc_fp_available_inline(ctx, 0x80130C00u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80130C04:
    ctx->pc = 0x80130C04u;
    // 80130C04: stfs     f0, 544(r28)
    if (!ppc_fp_available_inline(ctx, 0x80130C04u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(544);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80130C08:
    ctx->pc = 0x80130C08u;
    // 80130C08: lwz     r0, 60(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130C0C:
    ctx->pc = 0x80130C0Cu;
    // 80130C0C: stw     r0, 548(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(548);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130C10:
    ctx->pc = 0x80130C10u;
    // 80130C10: lfs     f0, 64(r29)
    if (!ppc_fp_available_inline(ctx, 0x80130C10u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(64);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80130C14:
    ctx->pc = 0x80130C14u;
    // 80130C14: stfs     f0, 552(r28)
    if (!ppc_fp_available_inline(ctx, 0x80130C14u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(552);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80130C18:
    ctx->pc = 0x80130C18u;
    // 80130C18: lwz     r0, 68(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130C1C:
    ctx->pc = 0x80130C1Cu;
    // 80130C1C: stw     r0, 556(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(556);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130C20:
    ctx->pc = 0x80130C20u;
    // 80130C20: lfs     f0, 72(r29)
    if (!ppc_fp_available_inline(ctx, 0x80130C20u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(72);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80130C24:
    ctx->pc = 0x80130C24u;
    // 80130C24: stfs     f0, 560(r28)
    if (!ppc_fp_available_inline(ctx, 0x80130C24u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(560);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80130C28:
    ctx->pc = 0x80130C28u;
    // 80130C28: lwz     r0, 76(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130C2C:
    ctx->pc = 0x80130C2Cu;
    // 80130C2C: stw     r0, 564(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(564);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130C30:
    ctx->pc = 0x80130C30u;
    // 80130C30: lwz     r9, 80(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(80);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130C34:
    ctx->pc = 0x80130C34u;
    // 80130C34: stw     r9, 568(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(568);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130C38:
    ctx->pc = 0x80130C38u;
    // 80130C38: lwz     r0, 88(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130C3C:
    ctx->pc = 0x80130C3Cu;
    // 80130C3C: stw     r0, 576(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130C40:
    ctx->pc = 0x80130C40u;
    // 80130C40: lwz     r9, 88(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(88);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130C44:
    // 80130C44: cmpw    r26, r9
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80130C48:
    // 80130C48: bc    4, 0, 0x80130C78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80130C78;
        }
    }

label_80130C4C:
    ctx->downcount -= 2;
    // 80130C4C: addi    r31, r29, 92
    ctx->gpr[31] = ctx->gpr[29] + (u32)(s32)(92);

label_80130C50:
    // 80130C50: addi    r30, r28, 580
    ctx->gpr[30] = ctx->gpr[28] + (u32)(s32)(580);

label_80130C54:
    ctx->downcount -= 3;
    // 80130C54: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130C58:
    // 80130C58: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80130C5C:
    // 80130C5C: bl      0x8012270C
    {
            ctx->lr = 0x80130C60u;
            ctx->pc = 0x8012270Cu;
            return;
    }

label_80130C60:
    ctx->downcount -= 6;
    // 80130C60: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_80130C64:
    ctx->pc = 0x80130C64u;
    // 80130C64: lwz     r0, 88(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130C68:
    // 80130C68: addi    r31, r31, 120
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(120);

label_80130C6C:
    // 80130C6C: addi    r30, r30, 120
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(120);

label_80130C70:
    // 80130C70: cmpw    r26, r0
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80130C74:
    // 80130C74: bc    12, 0, 0x80130C54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80130C54u;
                return;
            }
            goto label_80130C54;
        }
    }

label_80130C78:
    ctx->downcount -= 3;
    // 80130C78: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_80130C7C:
    // 80130C7C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80130C80:
    // 80130C80: bl      0x801037A4
    {
            ctx->lr = 0x80130C84u;
            ctx->pc = 0x801037A4u;
            return;
    }

label_80130C84:
    ctx->downcount -= 3;
    // 80130C84: or.   r3, r3, r3
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

label_80130C88:
    // 80130C88: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80130C8C:
    // 80130C8C: bc    12, 2, 0x80130C94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130C94;
        }
    }

label_80130C90:
    ctx->downcount -= 1;
    // 80130C90: subf   r0, r19, r3
    {
        u32 a = ~ctx->gpr[19];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80130C94:
    ctx->pc = 0x80130C94u;
    ctx->downcount -= 7;
    // 80130C94: stw     r0, 584(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(584);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130C98:
    // 80130C98: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80130C9C:
    // 80130C9C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80130CA0:
    ctx->pc = 0x80130CA0u;
    // 80130CA0: stw     r30, 580(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(580);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80130CA4:
    // 80130CA4: or   r5, r18, r18
    {
        ctx->gpr[5] = ctx->gpr[18] | ctx->gpr[18];
    }

label_80130CA8:
    // 80130CA8: or   r3, r22, r22
    {
        ctx->gpr[3] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80130CAC:
    // 80130CAC: bl      0x80216A5C
    {
            ctx->lr = 0x80130CB0u;
            ctx->pc = 0x80216A5Cu;
            return;
    }

label_80130CB0:
    ctx->downcount -= 4;
    // 80130CB0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130CB4:
    // 80130CB4: or   r4, r22, r22
    {
        ctx->gpr[4] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80130CB8:
    // 80130CB8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80130CBC:
    // 80130CBC: bl      0x801FEFBC
    {
            ctx->lr = 0x80130CC0u;
            ctx->pc = 0x801FEFBCu;
            return;
    }

label_80130CC0:
    ctx->pc = 0x80130CC0u;
    ctx->downcount -= 3;
    // 80130CC0: lwz     r0, 280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130CC4:
    // 80130CC4: cmpwi   r0, 0
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

label_80130CC8:
    // 80130CC8: bc    12, 2, 0x80130CF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130CF8;
        }
    }

label_80130CCC:
    ctx->pc = 0x80130CCCu;
    ctx->downcount -= 4;
    // 80130CCC: lwz     r9, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130CD0:
    // 80130CD0: or   r3, r22, r22
    {
        ctx->gpr[3] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80130CD4:
    ctx->pc = 0x80130CD4u;
    // 80130CD4: lwz     r4, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80130CD8:
    // 80130CD8: bl      0x801229B0
    {
            ctx->lr = 0x80130CDCu;
            ctx->pc = 0x801229B0u;
            return;
    }

label_80130CDC:
    ctx->pc = 0x80130CDCu;
    ctx->downcount -= 7;
    // 80130CDC: lwz     r9, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130CE0:
    ctx->pc = 0x80130CE0u;
    // 80130CE0: stw     r9, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130CE4:
    ctx->pc = 0x80130CE4u;
    // 80130CE4: lwz     r11, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80130CE8:
    ctx->pc = 0x80130CE8u;
    // 80130CE8: stw     r30, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80130CEC:
    ctx->pc = 0x80130CECu;
    // 80130CEC: lwz     r9, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130CF0:
    ctx->pc = 0x80130CF0u;
    // 80130CF0: stw     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130CF4:
    ctx->pc = 0x80130CF4u;
    // 80130CF4: stw     r30, 8(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80130CF8:
    ctx->pc = 0x80130CF8u;
    ctx->downcount -= 3;
    // 80130CF8: lwz     r3, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80130CFC:
    // 80130CFC: cmpwi   r3, 0
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

label_80130D00:
    // 80130D00: bc    12, 2, 0x80130D0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130D0C;
        }
    }

label_80130D04:
    ctx->downcount -= 2;
    // 80130D04: li      r4, 24
    ctx->gpr[4] = (u32)(s32)(24);

label_80130D08:
    // 80130D08: bl      0x8001D934
    {
            ctx->lr = 0x80130D0Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80130D0C:
    ctx->pc = 0x80130D0Cu;
    ctx->downcount -= 6;
    // 80130D0C: lwz     r9, 12(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130D10:
    // 80130D10: or   r30, r17, r17
    {
        ctx->gpr[30] = ctx->gpr[17] | ctx->gpr[17];
    }

label_80130D14:
    // 80130D14: add   r9, r20, r9
    {
        u32 a = ctx->gpr[20];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80130D18:
    ctx->pc = 0x80130D18u;
    // 80130D18: lwz     r0, 60(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130D1C:
    // 80130D1C: cmpw    r30, r0
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

label_80130D20:
    // 80130D20: bc    12, 0, 0x80130A9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80130A9Cu;
                return;
            }
            goto label_80130A9C;
        }
    }

label_80130D24:
    ctx->pc = 0x80130D24u;
    ctx->downcount -= 4;
    // 80130D24: lwz     r0, 8(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130D28:
    ctx->pc = 0x80130D28u;
    // 80130D28: lwz     r10, 304(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(304);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80130D2C:
    // 80130D2C: cmpw    r10, r0
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

label_80130D30:
    // 80130D30: bc    12, 0, 0x80130A50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80130A50u;
                return;
            }
            goto label_80130A50;
        }
    }

label_80130D34:
    ctx->pc = 0x80130D34u;
    ctx->downcount -= 18;
    // 80130D34: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80130D38:
    ctx->pc = 0x80130D38u;
    // 80130D38: lwz     r0, 404(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(404);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130D3C:
    ctx->pc = 0x80130D3Cu;
    // 80130D3C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80130D40:
    ctx->pc = 0x80130D40u;
    // 80130D40: lmw     r14, 320(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(320);
        for (u32 r = 14; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80130D44:
    ctx->pc = 0x80130D44u;
    // 80130D44: lfd     f31, 392(r1)
    if (!ppc_fp_available_inline(ctx, 0x80130D44u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(392);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80130D48:
    ctx->pc = 0x80130D48u;
    // 80130D48: addi    r1, r1, 400
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(400);

label_80130D4C:
    ctx->pc = 0x80130D4Cu;
    // 80130D4C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130D50:
    ctx->pc = 0x80130D50u;
    ctx->downcount -= 16;
    // 80130D50: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130D54:
    ctx->pc = 0x80130D54u;
    // 80130D54: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80130D58:
    ctx->pc = 0x80130D58u;
    // 80130D58: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130D5C:
    ctx->pc = 0x80130D5Cu;
    // 80130D5C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130D60:
    ctx->pc = 0x80130D60u;
    // 80130D60: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130D64:
    ctx->pc = 0x80130D64u;
    // 80130D64: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80130D68:
    ctx->pc = 0x80130D68u;
    ctx->downcount -= 11;
    // 80130D68: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130D6C:
    ctx->pc = 0x80130D6Cu;
    // 80130D6C: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130D70:
    // 80130D70: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80130D74:
    ctx->pc = 0x80130D74u;
    // 80130D74: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80130D78:
    // 80130D78: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_80130D7C:
    // 80130D7C: cmplw   r10, r11
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

label_80130D80:
    // 80130D80: bc    12, 0, 0x80130DA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130DA8;
        }
    }

label_80130D84:
    ctx->downcount -= 3;
    // 80130D84: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80130D88:
    ctx->pc = 0x80130D88u;
    // 80130D88: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130D8C:
    // 80130D8C: b       0x80130E80
    {
            goto label_80130E80;
    }

label_80130D90:
    ctx->pc = 0x80130D90u;
    ctx->downcount -= 6;
    // 80130D90: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130D94:
    // 80130D94: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80130D98:
    ctx->pc = 0x80130D98u;
    // 80130D98: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130D9C:
    ctx->pc = 0x80130D9Cu;
    // 80130D9C: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130DA0:
    ctx->pc = 0x80130DA0u;
    // 80130DA0: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80130DA4:
    // 80130DA4: b       0x80130D68
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80130D68u;
                return;
            }
            goto label_80130D68;
    }

label_80130DA8:
    ctx->downcount -= 2;
    // 80130DA8: cmplw   r10, r30
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

label_80130DAC:
    // 80130DAC: bc    12, 0, 0x80130DCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130DCC;
        }
    }

label_80130DB0:
    ctx->downcount -= 50;
    // 80130DB0: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_80130DB4:
    ctx->pc = 0x80130DB4u;
    // 80130DB4: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130DB8:
    // 80130DB8: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80130DBC:
    ctx->pc = 0x80130DBCu;
    // 80130DBC: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80130DC0:
    // 80130DC0: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80130DC4:
    ctx->pc = 0x80130DC4u;
    // 80130DC4: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130DC8:
    // 80130DC8: b       0x80130E80
    {
            goto label_80130E80;
    }

label_80130DCC:
    ctx->pc = 0x80130DCCu;
    ctx->downcount -= 8;
    // 80130DCC: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130DD0:
    // 80130DD0: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80130DD4:
    // 80130DD4: cmpwi   r10, 0
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

label_80130DD8:
    // 80130DD8: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_80130DDC:
    // 80130DDC: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_80130DE0:
    // 80130DE0: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_80130DE4:
    // 80130DE4: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_80130DE8:
    // 80130DE8: bc    12, 2, 0x80130E08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130E08;
        }
    }

label_80130DEC:
    ctx->downcount -= 7;
    // 80130DEC: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_80130DF0:
    // 80130DF0: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80130DF4:
    // 80130DF4: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80130DF8:
    // 80130DF8: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80130DFC:
    ctx->pc = 0x80130DFCu;
    // 80130DFC: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80130E00:
    ctx->pc = 0x80130E00u;
    // 80130E00: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80130E04:
    ctx->pc = 0x80130E04u;
    // 80130E04: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80130E08:
    ctx->downcount -= 2;
    // 80130E08: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80130E0C:
    // 80130E0C: bl      0x80281C60
    {
            ctx->lr = 0x80130E10u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80130E10:
    ctx->downcount -= 3;
    // 80130E10: cmpwi   r3, 0
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

label_80130E14:
    ctx->pc = 0x80130E14u;
    // 80130E14: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80130E18:
    // 80130E18: bc    4, 2, 0x80130E64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80130E64;
        }
    }

label_80130E1C:
    ctx->downcount -= 3;
    // 80130E1C: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130E20:
    // 80130E20: cmplwi  r11, 0x0080
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

label_80130E24:
    // 80130E24: bc    12, 1, 0x80130E50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130E50;
        }
    }

label_80130E28:
    ctx->downcount -= 2;
    // 80130E28: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80130E2C:
    // 80130E2C: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80130E30:
    ctx->downcount -= 5;
    // 80130E30: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_80130E34:
    // 80130E34: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80130E38:
    ctx->pc = 0x80130E38u;
    // 80130E38: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80130E3C:
    // 80130E3C: cmpwi   r10, 0
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

label_80130E40:
    // 80130E40: bc    4, 2, 0x80130D90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80130D90u;
                return;
            }
            goto label_80130D90;
        }
    }

label_80130E44:
    ctx->downcount -= 3;
    // 80130E44: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_80130E48:
    // 80130E48: cmplwi  r11, 0x0080
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

label_80130E4C:
    // 80130E4C: bc    4, 1, 0x80130E30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80130E30u;
                return;
            }
            goto label_80130E30;
        }
    }

label_80130E50:
    ctx->downcount -= 4;
    // 80130E50: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80130E54:
    // 80130E54: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80130E58:
    ctx->pc = 0x80130E58u;
    // 80130E58: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130E5C:
    // 80130E5C: bl      0x80281C60
    {
            ctx->lr = 0x80130E60u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80130E60:
    ctx->pc = 0x80130E60u;
    ctx->downcount -= 1;
    // 80130E60: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80130E64:
    ctx->pc = 0x80130E64u;
    ctx->downcount -= 7;
    // 80130E64: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130E68:
    ctx->pc = 0x80130E68u;
    // 80130E68: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130E6C:
    // 80130E6C: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80130E70:
    // 80130E70: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80130E74:
    ctx->pc = 0x80130E74u;
    // 80130E74: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130E78:
    ctx->pc = 0x80130E78u;
    // 80130E78: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130E7C:
    // 80130E7C: b       0x80130D68
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80130D68u;
                return;
            }
            goto label_80130D68;
    }

label_80130E80:
    ctx->pc = 0x80130E80u;
    ctx->downcount -= 16;
    // 80130E80: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130E84:
    ctx->pc = 0x80130E84u;
    // 80130E84: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80130E88:
    ctx->pc = 0x80130E88u;
    // 80130E88: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80130E8C:
    ctx->pc = 0x80130E8Cu;
    // 80130E8C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80130E90:
    ctx->pc = 0x80130E90u;
    // 80130E90: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130E94:
    ctx->pc = 0x80130E94u;
    ctx->downcount -= 21;
    // 80130E94: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130E98:
    ctx->pc = 0x80130E98u;
    // 80130E98: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80130E9C:
    ctx->pc = 0x80130E9Cu;
    // 80130E9C: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80130EA0:
    ctx->pc = 0x80130EA0u;
    // 80130EA0: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130EA4:
    ctx->pc = 0x80130EA4u;
    // 80130EA4: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80130EA8:
    ctx->pc = 0x80130EA8u;
    // 80130EA8: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_80130EAC:
    ctx->pc = 0x80130EACu;
    // 80130EAC: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80130EB0:
    ctx->pc = 0x80130EB0u;
    // 80130EB0: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80130EB4:
    ctx->pc = 0x80130EB4u;
    // 80130EB4: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80130EB8:
    ctx->pc = 0x80130EB8u;
    // 80130EB8: cmpwi   r30, 0
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

label_80130EBC:
    ctx->pc = 0x80130EBCu;
    // 80130EBC: bc    12, 2, 0x80130ECC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130ECC;
        }
    }

label_80130EC0:
    ctx->pc = 0x80130EC0u;
    ctx->downcount -= 3;
    // 80130EC0: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130EC4:
    ctx->pc = 0x80130EC4u;
    // 80130EC4: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130EC8:
    ctx->pc = 0x80130EC8u;
    // 80130EC8: b       0x80130F4C
    {
            goto label_80130F4C;
    }

label_80130ECC:
    ctx->pc = 0x80130ECCu;
    ctx->downcount -= 7;
    // 80130ECC: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_80130ED0:
    ctx->pc = 0x80130ED0u;
    // 80130ED0: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_80130ED4:
    ctx->pc = 0x80130ED4u;
    // 80130ED4: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_80130ED8:
    ctx->pc = 0x80130ED8u;
    // 80130ED8: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80130EDC:
    ctx->pc = 0x80130EDCu;
    // 80130EDC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80130EE0:
    ctx->pc = 0x80130EE0u;
    // 80130EE0: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_80130EE4:
    ctx->pc = 0x80130EE4u;
    // 80130EE4: bl      0x80003EE0
    {
            ctx->lr = 0x80130EE8u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_80130EE8:
    ctx->pc = 0x80130EE8u;
    ctx->downcount -= 3;
    // 80130EE8: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130EEC:
    ctx->pc = 0x80130EECu;
    // 80130EEC: cmpwi   r9, 1
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

label_80130EF0:
    ctx->pc = 0x80130EF0u;
    // 80130EF0: bc    12, 2, 0x80130F48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80130F48;
        }
    }

label_80130EF4:
    ctx->pc = 0x80130EF4u;
    ctx->downcount -= 9;
    // 80130EF4: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_80130EF8:
    ctx->pc = 0x80130EF8u;
    // 80130EF8: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80130EFC:
    ctx->pc = 0x80130EFCu;
    // 80130EFC: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80130F00:
    ctx->pc = 0x80130F00u;
    // 80130F00: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80130F04:
    ctx->pc = 0x80130F04u;
    // 80130F04: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80130F08:
    ctx->pc = 0x80130F08u;
    // 80130F08: cmpwi   r9, 2
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

label_80130F0C:
    ctx->pc = 0x80130F0Cu;
    // 80130F0C: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_80130F10:
    ctx->pc = 0x80130F10u;
    // 80130F10: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80130F14:
    ctx->pc = 0x80130F14u;
    // 80130F14: bc    4, 2, 0x80130F20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80130F20;
        }
    }

label_80130F18:
    ctx->pc = 0x80130F18u;
    ctx->downcount -= 2;
    // 80130F18: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80130F1C:
    ctx->pc = 0x80130F1Cu;
    // 80130F1C: b       0x80130F48
    {
            goto label_80130F48;
    }

label_80130F20:
    loop_80130F20(ctx);
    if (ctx->pc == 0x80130F40u) goto label_80130F40;
    return;
label_80130F24:
    // 80130F24: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_80130F28:
    // 80130F28: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80130F2C:
    ctx->pc = 0x80130F2Cu;
    // 80130F2C: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80130F30:
    // 80130F30: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80130F34:
    // 80130F34: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80130F38:
    // 80130F38: cmpw    r9, r8
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

label_80130F3C:
    // 80130F3C: bc    4, 2, 0x80130F20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80130F20u;
                return;
            }
            goto label_80130F20;
        }
    }

label_80130F40:
    ctx->pc = 0x80130F40u;
    ctx->downcount -= 2;
    // 80130F40: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80130F44:
    ctx->pc = 0x80130F44u;
    // 80130F44: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130F48:
    ctx->pc = 0x80130F48u;
    ctx->downcount -= 1;
    // 80130F48: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80130F4C:
    ctx->pc = 0x80130F4Cu;
    ctx->downcount -= 17;
    // 80130F4C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80130F50:
    ctx->pc = 0x80130F50u;
    // 80130F50: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80130F54:
    ctx->pc = 0x80130F54u;
    // 80130F54: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80130F58:
    ctx->pc = 0x80130F58u;
    // 80130F58: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80130F5C:
    ctx->pc = 0x80130F5Cu;
    // 80130F5C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80130F60:
    ctx->pc = 0x80130F60u;
    // 80130F60: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80130F64:
    ctx->pc = 0x80130F64u;
    ctx->downcount -= 7;
    // 80130F64: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80130F68:
    ctx->pc = 0x80130F68u;
    // 80130F68: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80130F6C:
    ctx->pc = 0x80130F6Cu;
    // 80130F6C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80130F70:
    ctx->pc = 0x80130F70u;
    // 80130F70: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80130F74:
    ctx->pc = 0x80130F74u;
    // 80130F74: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_80130F78:
    ctx->pc = 0x80130F78u;
    // 80130F78: cmpw    r4, r0
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

label_80130F7C:
    ctx->pc = 0x80130F7Cu;
    // 80130F7C: bc    4, 2, 0x8013103C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013103C;
        }
    }

label_80130F80:
    ctx->pc = 0x80130F80u;
    ctx->downcount -= 2;
    // 80130F80: cmpwi   r3, 0
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

label_80130F84:
    ctx->pc = 0x80130F84u;
    // 80130F84: bc    12, 2, 0x8013103C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013103C;
        }
    }

label_80130F88:
    ctx->pc = 0x80130F88u;
    ctx->downcount -= 5;
    // 80130F88: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_80130F8C:
    ctx->pc = 0x80130F8Cu;
    // 80130F8C: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_80130F90:
    ctx->pc = 0x80130F90u;
    // 80130F90: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_80130F94:
    ctx->pc = 0x80130F94u;
    // 80130F94: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_80130F98:
    ctx->pc = 0x80130F98u;
    // 80130F98: bl      0x80252AF0
    {
            ctx->lr = 0x80130F9Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80130F9C:
    ctx->pc = 0x80130F9Cu;
    ctx->downcount -= 5;
    // 80130F9C: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_80130FA0:
    ctx->pc = 0x80130FA0u;
    // 80130FA0: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80130FA4:
    ctx->pc = 0x80130FA4u;
    // 80130FA4: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_80130FA8:
    ctx->pc = 0x80130FA8u;
    // 80130FA8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80130FAC:
    ctx->pc = 0x80130FACu;
    // 80130FAC: bl      0x80252AF0
    {
            ctx->lr = 0x80130FB0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80130FB0:
    ctx->pc = 0x80130FB0u;
    ctx->downcount -= 5;
    // 80130FB0: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_80130FB4:
    ctx->pc = 0x80130FB4u;
    // 80130FB4: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80130FB8:
    ctx->pc = 0x80130FB8u;
    // 80130FB8: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_80130FBC:
    ctx->pc = 0x80130FBCu;
    // 80130FBC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80130FC0:
    ctx->pc = 0x80130FC0u;
    // 80130FC0: bl      0x80252AF0
    {
            ctx->lr = 0x80130FC4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80130FC4:
    ctx->pc = 0x80130FC4u;
    ctx->downcount -= 5;
    // 80130FC4: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_80130FC8:
    ctx->pc = 0x80130FC8u;
    // 80130FC8: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_80130FCC:
    ctx->pc = 0x80130FCCu;
    // 80130FCC: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_80130FD0:
    ctx->pc = 0x80130FD0u;
    // 80130FD0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80130FD4:
    ctx->pc = 0x80130FD4u;
    // 80130FD4: bl      0x80252AF0
    {
            ctx->lr = 0x80130FD8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80130FD8:
    ctx->pc = 0x80130FD8u;
    ctx->downcount -= 5;
    // 80130FD8: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_80130FDC:
    ctx->pc = 0x80130FDCu;
    // 80130FDC: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_80130FE0:
    ctx->pc = 0x80130FE0u;
    // 80130FE0: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_80130FE4:
    ctx->pc = 0x80130FE4u;
    // 80130FE4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80130FE8:
    ctx->pc = 0x80130FE8u;
    // 80130FE8: bl      0x80252AF0
    {
            ctx->lr = 0x80130FECu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80130FEC:
    ctx->pc = 0x80130FECu;
    ctx->downcount -= 5;
    // 80130FEC: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_80130FF0:
    ctx->pc = 0x80130FF0u;
    // 80130FF0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80130FF4:
    ctx->pc = 0x80130FF4u;
    // 80130FF4: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_80130FF8:
    ctx->pc = 0x80130FF8u;
    // 80130FF8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80130FFC:
    ctx->pc = 0x80130FFCu;
    // 80130FFC: bl      0x80252AF0
    {
            ctx->lr = 0x80131000u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80131000:
    ctx->pc = 0x80131000u;
    ctx->downcount -= 5;
    // 80131000: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_80131004:
    ctx->pc = 0x80131004u;
    // 80131004: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80131008:
    ctx->pc = 0x80131008u;
    // 80131008: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_8013100C:
    ctx->pc = 0x8013100Cu;
    // 8013100C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80131010:
    ctx->pc = 0x80131010u;
    // 80131010: bl      0x80252AF0
    {
            ctx->lr = 0x80131014u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80131014:
    ctx->pc = 0x80131014u;
    ctx->downcount -= 5;
    // 80131014: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_80131018:
    ctx->pc = 0x80131018u;
    // 80131018: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_8013101C:
    ctx->pc = 0x8013101Cu;
    // 8013101C: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_80131020:
    ctx->pc = 0x80131020u;
    // 80131020: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80131024:
    ctx->pc = 0x80131024u;
    // 80131024: bl      0x80252AF0
    {
            ctx->lr = 0x80131028u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80131028:
    ctx->pc = 0x80131028u;
    ctx->downcount -= 5;
    // 80131028: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_8013102C:
    ctx->pc = 0x8013102Cu;
    // 8013102C: lis     r4, -32749
    ctx->gpr[4] = ((u32)(s32)(-32749) << 16);

label_80131030:
    ctx->pc = 0x80131030u;
    // 80131030: addi    r3, r3, 18160
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(18160);

label_80131034:
    ctx->pc = 0x80131034u;
    // 80131034: addi    r4, r4, 4524
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4524);

label_80131038:
    ctx->pc = 0x80131038u;
    // 80131038: bl      0x801FC784
    {
            ctx->lr = 0x8013103Cu;
            ctx->pc = 0x801FC784u;
            return;
    }

label_8013103C:
    ctx->pc = 0x8013103Cu;
    ctx->downcount -= 5;
    // 8013103C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131040:
    ctx->pc = 0x80131040u;
    // 80131040: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131044:
    ctx->pc = 0x80131044u;
    // 80131044: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80131048:
    ctx->pc = 0x80131048u;
    // 80131048: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013104C:
    ctx->pc = 0x8013104Cu;
    ctx->downcount -= 7;
    // 8013104C: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131050:
    ctx->pc = 0x80131050u;
    // 80131050: addi    r11, r4, 4
    ctx->gpr[11] = ctx->gpr[4] + (u32)(s32)(4);

label_80131054:
    ctx->pc = 0x80131054u;
    // 80131054: addi    r9, r3, 4
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(4);

label_80131058:
    ctx->pc = 0x80131058u;
    // 80131058: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013105C:
    ctx->pc = 0x8013105Cu;
    // 8013105C: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131060:
    ctx->pc = 0x80131060u;
    // 80131060: cmpwi   r0, 1
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

label_80131064:
    ctx->pc = 0x80131064u;
    // 80131064: bc    12, 2, 0x80131070
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131070;
        }
    }

label_80131068:
    ctx->pc = 0x80131068u;
    ctx->downcount -= 2;
    // 80131068: add   r0, r11, r0
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8013106C:
    ctx->pc = 0x8013106Cu;
    // 8013106C: b       0x80131074
    {
            goto label_80131074;
    }

label_80131070:
    ctx->pc = 0x80131070u;
    ctx->downcount -= 1;
    // 80131070: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80131074:
    ctx->pc = 0x80131074u;
    ctx->downcount -= 2;
    // 80131074: cmpwi   r0, 0
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

label_80131078:
    ctx->pc = 0x80131078u;
    // 80131078: bc    12, 2, 0x80131084
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131084;
        }
    }

label_8013107C:
    ctx->pc = 0x8013107Cu;
    ctx->downcount -= 2;
    // 8013107C: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80131080:
    ctx->pc = 0x80131080u;
    // 80131080: b       0x80131088
    {
            goto label_80131088;
    }

label_80131084:
    ctx->pc = 0x80131084u;
    ctx->downcount -= 1;
    // 80131084: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80131088:
    ctx->pc = 0x80131088u;
    ctx->downcount -= 28;
    // 80131088: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013108C:
    ctx->pc = 0x8013108Cu;
    // 8013108C: lfs     f13, 8(r4)
    if (!ppc_fp_available_inline(ctx, 0x8013108Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80131090:
    ctx->pc = 0x80131090u;
    // 80131090: addi    r10, r4, 56
    ctx->gpr[10] = ctx->gpr[4] + (u32)(s32)(56);

label_80131094:
    ctx->pc = 0x80131094u;
    // 80131094: addi    r11, r3, 56
    ctx->gpr[11] = ctx->gpr[3] + (u32)(s32)(56);

label_80131098:
    ctx->pc = 0x80131098u;
    // 80131098: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_8013109C:
    ctx->pc = 0x8013109Cu;
    // 8013109C: stfs     f13, 8(r3)
    if (!ppc_fp_available_inline(ctx, 0x8013109Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801310A0:
    ctx->pc = 0x801310A0u;
    // 801310A0: lfs     f0, 12(r4)
    if (!ppc_fp_available_inline(ctx, 0x801310A0u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801310A4:
    ctx->pc = 0x801310A4u;
    // 801310A4: stfs     f0, 12(r3)
    if (!ppc_fp_available_inline(ctx, 0x801310A4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801310A8:
    ctx->pc = 0x801310A8u;
    // 801310A8: lwz     r0, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801310AC:
    ctx->pc = 0x801310ACu;
    // 801310AC: stw     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801310B0:
    ctx->pc = 0x801310B0u;
    // 801310B0: lwz     r9, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801310B4:
    ctx->pc = 0x801310B4u;
    // 801310B4: stw     r9, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801310B8:
    ctx->pc = 0x801310B8u;
    // 801310B8: lfs     f0, 24(r4)
    if (!ppc_fp_available_inline(ctx, 0x801310B8u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801310BC:
    ctx->pc = 0x801310BCu;
    // 801310BC: stfs     f0, 24(r3)
    if (!ppc_fp_available_inline(ctx, 0x801310BCu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801310C0:
    ctx->pc = 0x801310C0u;
    // 801310C0: lfs     f13, 28(r4)
    if (!ppc_fp_available_inline(ctx, 0x801310C0u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801310C4:
    ctx->pc = 0x801310C4u;
    // 801310C4: stfs     f13, 28(r3)
    if (!ppc_fp_available_inline(ctx, 0x801310C4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801310C8:
    ctx->pc = 0x801310C8u;
    // 801310C8: lwz     r0, 32(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801310CC:
    ctx->pc = 0x801310CCu;
    // 801310CC: lwz     r9, 36(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(36);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801310D0:
    ctx->pc = 0x801310D0u;
    // 801310D0: stw     r0, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801310D4:
    ctx->pc = 0x801310D4u;
    // 801310D4: stw     r9, 36(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801310D8:
    ctx->pc = 0x801310D8u;
    // 801310D8: lwz     r0, 40(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801310DC:
    ctx->pc = 0x801310DCu;
    // 801310DC: lwz     r9, 44(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(44);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801310E0:
    ctx->pc = 0x801310E0u;
    // 801310E0: stw     r0, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801310E4:
    ctx->pc = 0x801310E4u;
    // 801310E4: stw     r9, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801310E8:
    ctx->pc = 0x801310E8u;
    // 801310E8: lfs     f0, 48(r4)
    if (!ppc_fp_available_inline(ctx, 0x801310E8u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801310EC:
    ctx->pc = 0x801310ECu;
    // 801310EC: stfs     f0, 48(r3)
    if (!ppc_fp_available_inline(ctx, 0x801310ECu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801310F0:
    ctx->pc = 0x801310F0u;
    // 801310F0: lwz     r0, 52(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801310F4:
    ctx->pc = 0x801310F4u;
    // 801310F4: stw     r0, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801310F8:
    ctx->downcount -= 7;
    // 801310F8: addi    r0, r7, -1
    ctx->gpr[0] = ctx->gpr[7] + (u32)(s32)(-1);

label_801310FC:
    // 801310FC: or   r9, r10, r10
    {
        ctx->gpr[9] = ctx->gpr[10] | ctx->gpr[10];
    }

label_80131100:
    // 80131100: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_80131104:
    // 80131104: addi    r10, r11, 16
    ctx->gpr[10] = ctx->gpr[11] + (u32)(s32)(16);

label_80131108:
    ctx->pc = 0x80131108u;
    // 80131108: mtctr    r7
    ctx->ctr = ctx->gpr[7];

label_8013110C:
    // 8013110C: addi    r8, r9, 16
    ctx->gpr[8] = ctx->gpr[9] + (u32)(s32)(16);

label_80131110:
    ctx->pc = 0x80131110u;
    ctx->downcount -= 5;
    // 80131110: lfs     f0, 0(r9)
    if (!ppc_fp_available_inline(ctx, 0x80131110u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80131114:
    // 80131114: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80131118:
    ctx->pc = 0x80131118u;
    // 80131118: stfs     f0, 0(r11)
    if (!ppc_fp_available_inline(ctx, 0x80131118u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8013111C:
    // 8013111C: addi    r11, r11, 4
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4);

label_80131120:
    // 80131120: bc    16, 0, 0x80131110
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80131110u;
                return;
            }
            goto label_80131110;
        }
    }

label_80131124:
    ctx->downcount -= 5;
    // 80131124: or   r7, r0, r0
    {
        ctx->gpr[7] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80131128:
    // 80131128: or   r11, r10, r10
    {
        ctx->gpr[11] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8013112C:
    // 8013112C: or   r10, r8, r8
    {
        ctx->gpr[10] = ctx->gpr[8] | ctx->gpr[8];
    }

label_80131130:
    // 80131130: cmpwi   r7, -1
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80131134:
    // 80131134: bc    4, 2, 0x801310F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801310F8u;
                return;
            }
            goto label_801310F8;
        }
    }

label_80131138:
    ctx->pc = 0x80131138u;
    ctx->downcount -= 1;
    // 80131138: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013113C:
    ctx->pc = 0x8013113Cu;
    ctx->downcount -= 2;
    // 8013113C: li      r3, 21
    ctx->gpr[3] = (u32)(s32)(21);

label_80131140:
    ctx->pc = 0x80131140u;
    // 80131140: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131144:
    ctx->pc = 0x80131144u;
    ctx->downcount -= 19;
    // 80131144: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80131148:
    ctx->pc = 0x80131148u;
    // 80131148: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8013114C:
    ctx->pc = 0x8013114Cu;
    // 8013114C: stmw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80131150:
    ctx->pc = 0x80131150u;
    // 80131150: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131154:
    ctx->pc = 0x80131154u;
    // 80131154: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80131158:
    ctx->pc = 0x80131158u;
    // 80131158: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8013115C:
    ctx->pc = 0x8013115Cu;
    // 8013115C: stw     r29, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80131160:
    ctx->pc = 0x80131160u;
    // 80131160: li      r3, 24
    ctx->gpr[3] = (u32)(s32)(24);

label_80131164:
    ctx->pc = 0x80131164u;
    // 80131164: bl      0x80004024
    {
            ctx->lr = 0x80131168u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80131168:
    ctx->pc = 0x80131168u;
    ctx->downcount -= 28;
    // 80131168: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013116C:
    ctx->pc = 0x8013116Cu;
    // 8013116C: stw     r29, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80131170:
    ctx->pc = 0x80131170u;
    // 80131170: stw     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80131174:
    ctx->pc = 0x80131174u;
    // 80131174: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80131178:
    ctx->pc = 0x80131178u;
    // 80131178: stb     r29, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write8(ctx, ea, (u8)ctx->gpr[29]);
    }

label_8013117C:
    ctx->pc = 0x8013117Cu;
    // 8013117C: stw     r29, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80131180:
    ctx->pc = 0x80131180u;
    // 80131180: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131184:
    ctx->pc = 0x80131184u;
    // 80131184: stw     r29, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80131188:
    ctx->pc = 0x80131188u;
    // 80131188: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013118C:
    ctx->pc = 0x8013118Cu;
    // 8013118C: stw     r9, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80131190:
    ctx->pc = 0x80131190u;
    // 80131190: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131194:
    ctx->pc = 0x80131194u;
    // 80131194: stw     r11, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80131198:
    ctx->pc = 0x80131198u;
    // 80131198: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013119C:
    ctx->pc = 0x8013119Cu;
    // 8013119C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801311A0:
    ctx->pc = 0x801311A0u;
    // 801311A0: lmw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801311A4:
    ctx->pc = 0x801311A4u;
    // 801311A4: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_801311A8:
    ctx->pc = 0x801311A8u;
    // 801311A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801311AC:
    ctx->pc = 0x801311ACu;
    ctx->downcount -= 17;
    // 801311AC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801311B0:
    ctx->pc = 0x801311B0u;
    // 801311B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801311B4:
    ctx->pc = 0x801311B4u;
    // 801311B4: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801311B8:
    ctx->pc = 0x801311B8u;
    // 801311B8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801311BC:
    ctx->pc = 0x801311BCu;
    // 801311BC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801311C0:
    ctx->pc = 0x801311C0u;
    // 801311C0: li      r3, 1064
    ctx->gpr[3] = (u32)(s32)(1064);

label_801311C4:
    ctx->pc = 0x801311C4u;
    // 801311C4: bl      0x80281C60
    {
            ctx->lr = 0x801311C8u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801311C8:
    ctx->pc = 0x801311C8u;
    ctx->downcount -= 2;
    // 801311C8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801311CC:
    ctx->pc = 0x801311CCu;
    // 801311CC: bl      0x801309C4
    {
            ctx->lr = 0x801311D0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801309C4u;
                return;
            }
            goto label_801309C4;
    }

label_801311D0:
    ctx->pc = 0x801311D0u;
    ctx->downcount -= 16;
    // 801311D0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801311D4:
    ctx->pc = 0x801311D4u;
    // 801311D4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801311D8:
    ctx->pc = 0x801311D8u;
    // 801311D8: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801311DC:
    ctx->pc = 0x801311DCu;
    // 801311DC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801311E0:
    ctx->pc = 0x801311E0u;
    // 801311E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801311E4:
    ctx->pc = 0x801311E4u;
    ctx->downcount -= 18;
    // 801311E4: stwu     r1, -152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-152);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801311E8:
    ctx->pc = 0x801311E8u;
    // 801311E8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801311EC:
    ctx->pc = 0x801311ECu;
    // 801311EC: stw     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801311F0:
    ctx->pc = 0x801311F0u;
    // 801311F0: stw     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801311F4:
    ctx->pc = 0x801311F4u;
    // 801311F4: lis     r12, 512
    ctx->gpr[12] = ((u32)(s32)(512) << 16);

label_801311F8:
    ctx->pc = 0x801311F8u;
    // 801311F8: addi    r0, r1, 160
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(160);

label_801311FC:
    ctx->pc = 0x801311FCu;
    // 801311FC: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_80131200:
    ctx->pc = 0x80131200u;
    // 80131200: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131204:
    ctx->pc = 0x80131204u;
    // 80131204: stw     r11, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80131208:
    ctx->pc = 0x80131208u;
    // 80131208: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013120C:
    ctx->pc = 0x8013120Cu;
    // 8013120C: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80131210:
    ctx->pc = 0x80131210u;
    // 80131210: stw     r6, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80131214:
    ctx->pc = 0x80131214u;
    // 80131214: stw     r7, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80131218:
    ctx->pc = 0x80131218u;
    // 80131218: stw     r8, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8013121C:
    ctx->pc = 0x8013121Cu;
    // 8013121C: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80131220:
    ctx->pc = 0x80131220u;
    // 80131220: stw     r10, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80131224:
    ctx->pc = 0x80131224u;
    // 80131224: stw     r12, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80131228:
    ctx->pc = 0x80131228u;
    // 80131228: bc    4, 6, 0x8013124C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x02000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013124C;
        }
    }

label_8013122C:
    ctx->pc = 0x8013122Cu;
    ctx->downcount -= 8;
    // 8013122C: stfd     f1, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8013122Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_80131230:
    ctx->pc = 0x80131230u;
    // 80131230: stfd     f2, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131230u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_80131234:
    ctx->pc = 0x80131234u;
    // 80131234: stfd     f3, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131234u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_80131238:
    ctx->pc = 0x80131238u;
    // 80131238: stfd     f4, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131238u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_8013123C:
    ctx->pc = 0x8013123Cu;
    // 8013123C: stfd     f5, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8013123Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_80131240:
    ctx->pc = 0x80131240u;
    // 80131240: stfd     f6, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131240u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_80131244:
    ctx->pc = 0x80131244u;
    // 80131244: stfd     f7, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131244u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_80131248:
    ctx->pc = 0x80131248u;
    // 80131248: stfd     f8, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131248u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
    }

label_8013124C:
    ctx->pc = 0x8013124Cu;
    ctx->downcount -= 12;
    // 8013124C: addi    r11, r1, 128
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(128);

label_80131250:
    ctx->pc = 0x80131250u;
    // 80131250: addi    r9, r1, 112
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(112);

label_80131254:
    ctx->pc = 0x80131254u;
    // 80131254: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131258:
    ctx->pc = 0x80131258u;
    // 80131258: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8013125C:
    ctx->pc = 0x8013125Cu;
    // 8013125C: lwz     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80131260:
    ctx->pc = 0x80131260u;
    // 80131260: or   r6, r9, r9
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80131264:
    ctx->pc = 0x80131264u;
    // 80131264: stw     r12, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80131268:
    ctx->pc = 0x80131268u;
    // 80131268: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8013126C:
    ctx->pc = 0x8013126Cu;
    // 8013126C: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131270:
    ctx->pc = 0x80131270u;
    // 80131270: li      r4, 260
    ctx->gpr[4] = (u32)(s32)(260);

label_80131274:
    ctx->pc = 0x80131274u;
    // 80131274: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80131278:
    ctx->pc = 0x80131278u;
    // 80131278: bl      0x80296720
    {
            ctx->lr = 0x8013127Cu;
            ctx->pc = 0x80296720u;
            return;
    }

label_8013127C:
    ctx->pc = 0x8013127Cu;
    ctx->downcount -= 8;
    // 8013127C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80131280:
    ctx->pc = 0x80131280u;
    // 80131280: stb     r0, 259(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(259);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80131284:
    ctx->pc = 0x80131284u;
    // 80131284: lwz     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131288:
    ctx->pc = 0x80131288u;
    // 80131288: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013128C:
    ctx->pc = 0x8013128Cu;
    // 8013128C: lwz     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80131290:
    ctx->pc = 0x80131290u;
    // 80131290: addi    r1, r1, 152
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(152);

label_80131294:
    ctx->pc = 0x80131294u;
    // 80131294: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131298:
    ctx->pc = 0x80131298u;
    ctx->downcount -= 8;
    // 80131298: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013129C:
    ctx->pc = 0x8013129Cu;
    // 8013129C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801312A0:
    ctx->pc = 0x801312A0u;
    // 801312A0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801312A4:
    ctx->pc = 0x801312A4u;
    // 801312A4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801312A8:
    ctx->pc = 0x801312A8u;
    // 801312A8: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801312AC:
    ctx->pc = 0x801312ACu;
    // 801312AC: addi    r9, r9, 17920
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17920);

label_801312B0:
    ctx->pc = 0x801312B0u;
    // 801312B0: stw     r9, 108(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801312B4:
    ctx->pc = 0x801312B4u;
    // 801312B4: bl      0x800EE1BC
    {
            ctx->lr = 0x801312B8u;
            ctx->pc = 0x800EE1BCu;
            return;
    }

label_801312B8:
    ctx->pc = 0x801312B8u;
    ctx->downcount -= 5;
    // 801312B8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801312BC:
    ctx->pc = 0x801312BCu;
    // 801312BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801312C0:
    ctx->pc = 0x801312C0u;
    // 801312C0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801312C4:
    ctx->pc = 0x801312C4u;
    // 801312C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801312C8:
    ctx->pc = 0x801312C8u;
    ctx->downcount -= 10;
    // 801312C8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801312CC:
    ctx->pc = 0x801312CCu;
    // 801312CC: addi    r4, r4, -1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-1);

label_801312D0:
    ctx->pc = 0x801312D0u;
    // 801312D0: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801312D4:
    ctx->pc = 0x801312D4u;
    // 801312D4: rlwinm r4, r4, 31, 1, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFCu;
    }

label_801312D8:
    ctx->pc = 0x801312D8u;
    // 801312D8: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801312DC:
    ctx->pc = 0x801312DCu;
    // 801312DC: lwzx    r0, r4, r9
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801312E0:
    ctx->pc = 0x801312E0u;
    // 801312E0: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801312E4:
    ctx->pc = 0x801312E4u;
    // 801312E4: stwx    r3, r4, r9
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[9];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801312E8:
    ctx->pc = 0x801312E8u;
    // 801312E8: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801312EC:
    ctx->pc = 0x801312ECu;
    // 801312EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801312F0:
    ctx->pc = 0x801312F0u;
    ctx->downcount -= 17;
    // 801312F0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801312F4:
    ctx->pc = 0x801312F4u;
    // 801312F4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801312F8:
    ctx->pc = 0x801312F8u;
    // 801312F8: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801312FC:
    ctx->pc = 0x801312FCu;
    // 801312FC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131300:
    ctx->pc = 0x80131300u;
    // 80131300: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80131304:
    ctx->pc = 0x80131304u;
    // 80131304: or.   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80131308:
    ctx->pc = 0x80131308u;
    // 80131308: bc    12, 2, 0x80131338
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131338;
        }
    }

label_8013130C:
    ctx->pc = 0x8013130Cu;
    ctx->downcount -= 3;
    // 8013130C: lwz     r4, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131310:
    // 80131310: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80131314:
    // 80131314: bl      0x801229B0
    {
            ctx->lr = 0x80131318u;
            ctx->pc = 0x801229B0u;
            return;
    }

label_80131318:
    ctx->pc = 0x80131318u;
    ctx->downcount -= 3;
    // 80131318: lwz     r30, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8013131C:
    // 8013131C: cmpwi   r31, 0
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

label_80131320:
    // 80131320: bc    12, 2, 0x80131330
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131330;
        }
    }

label_80131324:
    ctx->downcount -= 3;
    // 80131324: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80131328:
    // 80131328: li      r4, 24
    ctx->gpr[4] = (u32)(s32)(24);

label_8013132C:
    // 8013132C: bl      0x8001D934
    {
            ctx->lr = 0x80131330u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80131330:
    ctx->downcount -= 2;
    // 80131330: or.   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80131334:
    // 80131334: bc    4, 2, 0x8013130C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8013130Cu;
                return;
            }
            goto label_8013130C;
        }
    }

label_80131338:
    ctx->pc = 0x80131338u;
    ctx->downcount -= 16;
    // 80131338: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013133C:
    ctx->pc = 0x8013133Cu;
    // 8013133C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131340:
    ctx->pc = 0x80131340u;
    // 80131340: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80131344:
    ctx->pc = 0x80131344u;
    // 80131344: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80131348:
    ctx->pc = 0x80131348u;
    // 80131348: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013134C:
    ctx->pc = 0x8013134Cu;
    ctx->downcount -= 7;
    // 8013134C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80131350:
    ctx->pc = 0x80131350u;
    // 80131350: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80131354:
    ctx->pc = 0x80131354u;
    // 80131354: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131358:
    ctx->pc = 0x80131358u;
    // 80131358: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8013135C:
    ctx->pc = 0x8013135Cu;
    // 8013135C: lis     r4, 29557
    ctx->gpr[4] = ((u32)(s32)(29557) << 16);

label_80131360:
    ctx->pc = 0x80131360u;
    // 80131360: ori     r4, r4, 0x7266
    ctx->gpr[4] = ctx->gpr[4] | 0x7266u;

label_80131364:
    ctx->pc = 0x80131364u;
    // 80131364: bl      0x80213200
    {
            ctx->lr = 0x80131368u;
            ctx->pc = 0x80213200u;
            return;
    }

label_80131368:
    ctx->pc = 0x80131368u;
    ctx->downcount -= 5;
    // 80131368: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013136C:
    ctx->pc = 0x8013136Cu;
    // 8013136C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131370:
    ctx->pc = 0x80131370u;
    // 80131370: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80131374:
    ctx->pc = 0x80131374u;
    // 80131374: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131378:
    ctx->pc = 0x80131378u;
    ctx->downcount -= 7;
    // 80131378: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013137C:
    ctx->pc = 0x8013137Cu;
    // 8013137C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80131380:
    ctx->pc = 0x80131380u;
    // 80131380: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131384:
    ctx->pc = 0x80131384u;
    // 80131384: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80131388:
    ctx->pc = 0x80131388u;
    // 80131388: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8013138C:
    ctx->pc = 0x8013138Cu;
    // 8013138C: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_80131390:
    ctx->pc = 0x80131390u;
    // 80131390: bl      0x80130F64
    {
            ctx->lr = 0x80131394u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80130F64u;
                return;
            }
            goto label_80130F64;
    }

label_80131394:
    ctx->pc = 0x80131394u;
    ctx->downcount -= 5;
    // 80131394: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131398:
    ctx->pc = 0x80131398u;
    // 80131398: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013139C:
    ctx->pc = 0x8013139Cu;
    // 8013139C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801313A0:
    ctx->pc = 0x801313A0u;
    // 801313A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801313A4:
    ctx->pc = 0x801313A4u;
    ctx->downcount -= 20;
    // 801313A4: stwu     r1, -296(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-296);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801313A8:
    ctx->pc = 0x801313A8u;
    // 801313A8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801313AC:
    ctx->pc = 0x801313ACu;
    // 801313AC: stmw     r28, 280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801313B0:
    ctx->pc = 0x801313B0u;
    // 801313B0: stw     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801313B4:
    ctx->pc = 0x801313B4u;
    // 801313B4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801313B8:
    ctx->pc = 0x801313B8u;
    // 801313B8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801313BC:
    ctx->pc = 0x801313BCu;
    // 801313BC: addi    r4, r9, 18208
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(18208);

label_801313C0:
    ctx->pc = 0x801313C0u;
    // 801313C0: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_801313C4:
    ctx->pc = 0x801313C4u;
    // 801313C4: cmpwi   r4, 0
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

label_801313C8:
    ctx->pc = 0x801313C8u;
    // 801313C8: bc    12, 2, 0x801313D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801313D8;
        }
    }

label_801313CC:
    ctx->pc = 0x801313CCu;
    ctx->downcount -= 2;
    // 801313CC: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_801313D0:
    ctx->pc = 0x801313D0u;
    // 801313D0: bl      0x80287F10
    {
            ctx->lr = 0x801313D4u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_801313D4:
    ctx->pc = 0x801313D4u;
    ctx->downcount -= 1;
    // 801313D4: b       0x801313DC
    {
            goto label_801313DC;
    }

label_801313D8:
    ctx->pc = 0x801313D8u;
    ctx->downcount -= 1;
    // 801313D8: stb     r4, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801313DC:
    ctx->pc = 0x801313DCu;
    ctx->downcount -= 7;
    // 801313DC: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_801313E0:
    ctx->pc = 0x801313E0u;
    // 801313E0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801313E4:
    ctx->pc = 0x801313E4u;
    // 801313E4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801313E8:
    ctx->pc = 0x801313E8u;
    // 801313E8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_801313EC:
    ctx->pc = 0x801313ECu;
    // 801313EC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801313F0:
    ctx->pc = 0x801313F0u;
    // 801313F0: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801313F4:
    ctx->pc = 0x801313F4u;
    // 801313F4: bl      0x8015A93C
    {
            ctx->lr = 0x801313F8u;
            ctx->pc = 0x8015A93Cu;
            return;
    }

label_801313F8:
    ctx->pc = 0x801313F8u;
    ctx->downcount -= 50;
    // 801313F8: addi    r29, r31, 740
    ctx->gpr[29] = ctx->gpr[31] + (u32)(s32)(740);

label_801313FC:
    ctx->pc = 0x801313FCu;
    // 801313FC: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80131400:
    ctx->pc = 0x80131400u;
    // 80131400: li      r8, -1
    ctx->gpr[8] = (u32)(s32)(-1);

label_80131404:
    ctx->pc = 0x80131404u;
    // 80131404: addi    r9, r9, 19408
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19408);

label_80131408:
    ctx->pc = 0x80131408u;
    // 80131408: li      r0, 6
    ctx->gpr[0] = (u32)(s32)(6);

label_8013140C:
    ctx->pc = 0x8013140Cu;
    // 8013140C: li      r11, 3
    ctx->gpr[11] = (u32)(s32)(3);

label_80131410:
    ctx->pc = 0x80131410u;
    // 80131410: stw     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80131414:
    ctx->pc = 0x80131414u;
    // 80131414: stw     r0, 684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(684);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131418:
    ctx->pc = 0x80131418u;
    // 80131418: addi    r10, r31, 748
    ctx->gpr[10] = ctx->gpr[31] + (u32)(s32)(748);

label_8013141C:
    ctx->pc = 0x8013141Cu;
    // 8013141C: stw     r11, 728(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(728);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80131420:
    ctx->pc = 0x80131420u;
    // 80131420: addi    r9, r31, 756
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(756);

label_80131424:
    ctx->pc = 0x80131424u;
    // 80131424: stw     r8, 720(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(720);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80131428:
    ctx->pc = 0x80131428u;
    // 80131428: addi    r11, r31, 764
    ctx->gpr[11] = ctx->gpr[31] + (u32)(s32)(764);

label_8013142C:
    ctx->pc = 0x8013142Cu;
    // 8013142C: stw     r30, 712(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(712);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131430:
    ctx->pc = 0x80131430u;
    // 80131430: addi    r5, r31, 808
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(808);

label_80131434:
    ctx->pc = 0x80131434u;
    // 80131434: stw     r30, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131438:
    ctx->pc = 0x80131438u;
    // 80131438: addi    r7, r31, 816
    ctx->gpr[7] = ctx->gpr[31] + (u32)(s32)(816);

label_8013143C:
    ctx->pc = 0x8013143Cu;
    // 8013143C: stw     r30, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131440:
    ctx->pc = 0x80131440u;
    // 80131440: addi    r4, r31, 828
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(828);

label_80131444:
    ctx->pc = 0x80131444u;
    // 80131444: stw     r30, 732(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131448:
    ctx->pc = 0x80131448u;
    // 80131448: addi    r6, r31, 836
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(836);

label_8013144C:
    ctx->pc = 0x8013144Cu;
    // 8013144C: stw     r30, 736(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(736);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131450:
    ctx->pc = 0x80131450u;
    // 80131450: or   r28, r9, r9
    {
        ctx->gpr[28] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80131454:
    ctx->pc = 0x80131454u;
    // 80131454: stw     r30, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131458:
    ctx->pc = 0x80131458u;
    // 80131458: addi    r3, r31, 856
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(856);

label_8013145C:
    ctx->pc = 0x8013145Cu;
    // 8013145C: stw     r30, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131460:
    ctx->pc = 0x80131460u;
    // 80131460: stw     r30, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131464:
    ctx->pc = 0x80131464u;
    // 80131464: stw     r30, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131468:
    ctx->pc = 0x80131468u;
    // 80131468: stw     r30, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8013146C:
    ctx->pc = 0x8013146Cu;
    // 8013146C: stw     r30, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131470:
    ctx->pc = 0x80131470u;
    // 80131470: stw     r8, 772(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(772);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80131474:
    ctx->pc = 0x80131474u;
    // 80131474: stw     r30, 776(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(776);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131478:
    ctx->pc = 0x80131478u;
    // 80131478: stw     r30, 780(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(780);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8013147C:
    ctx->pc = 0x8013147Cu;
    // 8013147C: stw     r30, 784(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(784);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131480:
    ctx->pc = 0x80131480u;
    // 80131480: stw     r30, 788(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(788);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131484:
    ctx->pc = 0x80131484u;
    // 80131484: stw     r30, 792(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(792);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131488:
    ctx->pc = 0x80131488u;
    // 80131488: stw     r30, 796(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(796);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8013148C:
    ctx->pc = 0x8013148Cu;
    // 8013148C: stw     r30, 800(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(800);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131490:
    ctx->pc = 0x80131490u;
    // 80131490: stw     r30, 804(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(804);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131494:
    ctx->pc = 0x80131494u;
    // 80131494: stw     r30, 808(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(808);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131498:
    ctx->pc = 0x80131498u;
    // 80131498: stw     r30, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8013149C:
    ctx->pc = 0x8013149Cu;
    // 8013149C: stw     r30, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801314A0:
    ctx->pc = 0x801314A0u;
    // 801314A0: stw     r30, 824(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(824);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801314A4:
    ctx->pc = 0x801314A4u;
    // 801314A4: stw     r30, 828(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(828);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801314A8:
    ctx->pc = 0x801314A8u;
    // 801314A8: stw     r30, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801314AC:
    ctx->pc = 0x801314ACu;
    // 801314AC: stw     r30, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801314B0:
    ctx->pc = 0x801314B0u;
    // 801314B0: stw     r30, 844(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(844);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801314B4:
    ctx->pc = 0x801314B4u;
    // 801314B4: stw     r30, 848(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(848);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801314B8:
    ctx->pc = 0x801314B8u;
    // 801314B8: stw     r30, 852(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(852);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801314BC:
    ctx->pc = 0x801314BCu;
    // 801314BC: bl      0x801D334C
    {
            ctx->lr = 0x801314C0u;
            ctx->pc = 0x801D334Cu;
            return;
    }

label_801314C0:
    ctx->pc = 0x801314C0u;
    ctx->downcount -= 9;
    // 801314C0: lwz     r9, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801314C4:
    ctx->pc = 0x801314C4u;
    // 801314C4: addi    r6, r1, 272
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(272);

label_801314C8:
    ctx->pc = 0x801314C8u;
    // 801314C8: stw     r30, 868(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(868);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801314CC:
    ctx->pc = 0x801314CCu;
    // 801314CC: stw     r30, 272(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(272);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801314D0:
    ctx->pc = 0x801314D0u;
    // 801314D0: lwz     r4, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801314D4:
    ctx->pc = 0x801314D4u;
    // 801314D4: subf   r0, r9, r4
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801314D8:
    ctx->pc = 0x801314D8u;
    // 801314D8: srawi r0, r0, 2
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

label_801314DC:
    ctx->pc = 0x801314DCu;
    // 801314DC: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801314E0:
    ctx->pc = 0x801314E0u;
    // 801314E0: bc    4, 1, 0x801314F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801314F0;
        }
    }

label_801314E4:
    ctx->pc = 0x801314E4u;
    ctx->downcount -= 3;
    // 801314E4: addi    r0, r9, 4
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(4);

label_801314E8:
    ctx->pc = 0x801314E8u;
    // 801314E8: stw     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801314EC:
    ctx->pc = 0x801314ECu;
    // 801314EC: b       0x801314FC
    {
            goto label_801314FC;
    }

label_801314F0:
    ctx->pc = 0x801314F0u;
    ctx->downcount -= 3;
    // 801314F0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801314F4:
    ctx->pc = 0x801314F4u;
    // 801314F4: subfic  r5, r0, 1
    {
        u64 res = (u64)(u32)(s32)(1) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_801314F8:
    ctx->pc = 0x801314F8u;
    // 801314F8: bl      0x8012952C
    {
            ctx->lr = 0x801314FCu;
            ctx->pc = 0x8012952Cu;
            return;
    }

label_801314FC:
    ctx->pc = 0x801314FCu;
    ctx->downcount -= 9;
    // 801314FC: lwz     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131500:
    ctx->pc = 0x80131500u;
    // 80131500: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80131504:
    ctx->pc = 0x80131504u;
    // 80131504: lwz     r11, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131508:
    ctx->pc = 0x80131508u;
    // 80131508: addi    r6, r1, 276
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(276);

label_8013150C:
    ctx->pc = 0x8013150Cu;
    // 8013150C: stw     r9, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80131510:
    ctx->pc = 0x80131510u;
    // 80131510: subf   r0, r11, r4
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80131514:
    ctx->pc = 0x80131514u;
    // 80131514: srawi r0, r0, 2
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

label_80131518:
    ctx->pc = 0x80131518u;
    // 80131518: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8013151C:
    ctx->pc = 0x8013151Cu;
    // 8013151C: bc    4, 1, 0x8013152C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013152C;
        }
    }

label_80131520:
    ctx->pc = 0x80131520u;
    ctx->downcount -= 3;
    // 80131520: addi    r0, r11, 4
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(4);

label_80131524:
    ctx->pc = 0x80131524u;
    // 80131524: stw     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131528:
    ctx->pc = 0x80131528u;
    // 80131528: b       0x80131538
    {
            goto label_80131538;
    }

label_8013152C:
    ctx->pc = 0x8013152Cu;
    ctx->downcount -= 3;
    // 8013152C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80131530:
    ctx->pc = 0x80131530u;
    // 80131530: subfic  r5, r0, 1
    {
        u64 res = (u64)(u32)(s32)(1) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80131534:
    ctx->pc = 0x80131534u;
    // 80131534: bl      0x8012952C
    {
            ctx->lr = 0x80131538u;
            ctx->pc = 0x8012952Cu;
            return;
    }

label_80131538:
    ctx->pc = 0x80131538u;
    ctx->downcount -= 24;
    // 80131538: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8013153C:
    ctx->pc = 0x8013153Cu;
    // 8013153C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80131540:
    ctx->pc = 0x80131540u;
    // 80131540: stw     r0, 688(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131544:
    ctx->pc = 0x80131544u;
    // 80131544: stw     r0, 708(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(708);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131548:
    ctx->pc = 0x80131548u;
    // 80131548: stw     r0, 704(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013154C:
    ctx->pc = 0x8013154Cu;
    // 8013154C: stw     r0, 700(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131550:
    ctx->pc = 0x80131550u;
    // 80131550: stw     r0, 696(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131554:
    ctx->pc = 0x80131554u;
    // 80131554: stw     r0, 692(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131558:
    ctx->pc = 0x80131558u;
    // 80131558: lwz     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013155C:
    ctx->pc = 0x8013155Cu;
    // 8013155C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131560:
    ctx->pc = 0x80131560u;
    // 80131560: lmw     r28, 280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80131564:
    ctx->pc = 0x80131564u;
    // 80131564: addi    r1, r1, 296
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(296);

label_80131568:
    ctx->pc = 0x80131568u;
    // 80131568: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013156C:
    ctx->pc = 0x8013156Cu;
    ctx->downcount -= 20;
    // 8013156C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80131570:
    ctx->pc = 0x80131570u;
    // 80131570: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80131574:
    ctx->pc = 0x80131574u;
    // 80131574: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80131578:
    ctx->pc = 0x80131578u;
    // 80131578: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013157C:
    ctx->pc = 0x8013157Cu;
    // 8013157C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80131580:
    ctx->pc = 0x80131580u;
    // 80131580: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80131584:
    ctx->pc = 0x80131584u;
    // 80131584: addi    r9, r9, 19408
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19408);

label_80131588:
    ctx->pc = 0x80131588u;
    // 80131588: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8013158C:
    ctx->pc = 0x8013158Cu;
    // 8013158C: stw     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80131590:
    ctx->pc = 0x80131590u;
    // 80131590: bl      0x80131E8C
    {
            ctx->lr = 0x80131594u;
            goto label_80131E8C;
    }

label_80131594:
    ctx->pc = 0x80131594u;
    ctx->downcount -= 3;
    // 80131594: lwz     r4, 772(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(772);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131598:
    ctx->pc = 0x80131598u;
    // 80131598: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8013159C:
    ctx->pc = 0x8013159Cu;
    // 8013159C: bl      0x80133010
    {
            ctx->lr = 0x801315A0u;
            goto label_80133010;
    }

label_801315A0:
    ctx->pc = 0x801315A0u;
    ctx->downcount -= 3;
    // 801315A0: addi    r3, r31, 856
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(856);

label_801315A4:
    ctx->pc = 0x801315A4u;
    // 801315A4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801315A8:
    ctx->pc = 0x801315A8u;
    // 801315A8: bl      0x801D3364
    {
            ctx->lr = 0x801315ACu;
            ctx->pc = 0x801D3364u;
            return;
    }

label_801315AC:
    ctx->pc = 0x801315ACu;
    ctx->downcount -= 4;
    // 801315AC: lwz     r3, 828(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(828);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801315B0:
    ctx->pc = 0x801315B0u;
    // 801315B0: addi    r9, r31, 828
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(828);

label_801315B4:
    ctx->pc = 0x801315B4u;
    // 801315B4: cmpwi   r3, 0
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

label_801315B8:
    ctx->pc = 0x801315B8u;
    // 801315B8: bc    12, 2, 0x801315DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801315DC;
        }
    }

label_801315BC:
    ctx->pc = 0x801315BCu;
    ctx->downcount -= 5;
    // 801315BC: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801315C0:
    ctx->pc = 0x801315C0u;
    // 801315C0: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801315C4:
    ctx->pc = 0x801315C4u;
    // 801315C4: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_801315C8:
    ctx->pc = 0x801315C8u;
    // 801315C8: cmplwi  r4, 0x0080
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

label_801315CC:
    ctx->pc = 0x801315CCu;
    // 801315CC: bc    4, 1, 0x801315D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801315D8;
        }
    }

label_801315D0:
    ctx->pc = 0x801315D0u;
    ctx->downcount -= 1;
    // 801315D0: bl      0x80281D80
    {
            ctx->lr = 0x801315D4u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_801315D4:
    ctx->pc = 0x801315D4u;
    ctx->downcount -= 1;
    // 801315D4: b       0x801315DC
    {
            goto label_801315DC;
    }

label_801315D8:
    ctx->pc = 0x801315D8u;
    ctx->downcount -= 1;
    // 801315D8: bl      0x8001D934
    {
            ctx->lr = 0x801315DCu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_801315DC:
    ctx->pc = 0x801315DCu;
    ctx->downcount -= 4;
    // 801315DC: lwz     r3, 808(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(808);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801315E0:
    ctx->pc = 0x801315E0u;
    // 801315E0: addi    r9, r31, 808
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(808);

label_801315E4:
    ctx->pc = 0x801315E4u;
    // 801315E4: cmpwi   r3, 0
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

label_801315E8:
    ctx->pc = 0x801315E8u;
    // 801315E8: bc    12, 2, 0x8013160C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013160C;
        }
    }

label_801315EC:
    ctx->pc = 0x801315ECu;
    ctx->downcount -= 5;
    // 801315EC: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801315F0:
    ctx->pc = 0x801315F0u;
    // 801315F0: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801315F4:
    ctx->pc = 0x801315F4u;
    // 801315F4: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_801315F8:
    ctx->pc = 0x801315F8u;
    // 801315F8: cmplwi  r4, 0x0080
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

label_801315FC:
    ctx->pc = 0x801315FCu;
    // 801315FC: bc    4, 1, 0x80131608
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80131608;
        }
    }

label_80131600:
    ctx->pc = 0x80131600u;
    ctx->downcount -= 1;
    // 80131600: bl      0x80281D80
    {
            ctx->lr = 0x80131604u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80131604:
    ctx->pc = 0x80131604u;
    ctx->downcount -= 1;
    // 80131604: b       0x8013160C
    {
            goto label_8013160C;
    }

label_80131608:
    ctx->pc = 0x80131608u;
    ctx->downcount -= 1;
    // 80131608: bl      0x8001D934
    {
            ctx->lr = 0x8013160Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_8013160C:
    ctx->pc = 0x8013160Cu;
    ctx->downcount -= 4;
    // 8013160C: lwz     r3, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80131610:
    ctx->pc = 0x80131610u;
    // 80131610: addi    r9, r31, 756
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(756);

label_80131614:
    ctx->pc = 0x80131614u;
    // 80131614: cmpwi   r3, 0
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

label_80131618:
    ctx->pc = 0x80131618u;
    // 80131618: bc    12, 2, 0x8013163C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013163C;
        }
    }

label_8013161C:
    ctx->pc = 0x8013161Cu;
    ctx->downcount -= 5;
    // 8013161C: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131620:
    ctx->pc = 0x80131620u;
    // 80131620: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80131624:
    ctx->pc = 0x80131624u;
    // 80131624: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80131628:
    ctx->pc = 0x80131628u;
    // 80131628: cmplwi  r4, 0x0080
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

label_8013162C:
    ctx->pc = 0x8013162Cu;
    // 8013162C: bc    4, 1, 0x80131638
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80131638;
        }
    }

label_80131630:
    ctx->pc = 0x80131630u;
    ctx->downcount -= 1;
    // 80131630: bl      0x80281D80
    {
            ctx->lr = 0x80131634u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80131634:
    ctx->pc = 0x80131634u;
    ctx->downcount -= 1;
    // 80131634: b       0x8013163C
    {
            goto label_8013163C;
    }

label_80131638:
    ctx->pc = 0x80131638u;
    ctx->downcount -= 1;
    // 80131638: bl      0x8001D934
    {
            ctx->lr = 0x8013163Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_8013163C:
    ctx->pc = 0x8013163Cu;
    ctx->downcount -= 4;
    // 8013163C: lwz     r3, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80131640:
    ctx->pc = 0x80131640u;
    // 80131640: addi    r9, r31, 740
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(740);

label_80131644:
    ctx->pc = 0x80131644u;
    // 80131644: cmpwi   r3, 0
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

label_80131648:
    ctx->pc = 0x80131648u;
    // 80131648: bc    12, 2, 0x8013166C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013166C;
        }
    }

label_8013164C:
    ctx->pc = 0x8013164Cu;
    ctx->downcount -= 5;
    // 8013164C: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131650:
    ctx->pc = 0x80131650u;
    // 80131650: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80131654:
    ctx->pc = 0x80131654u;
    // 80131654: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80131658:
    ctx->pc = 0x80131658u;
    // 80131658: cmplwi  r4, 0x0080
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

label_8013165C:
    ctx->pc = 0x8013165Cu;
    // 8013165C: bc    4, 1, 0x80131668
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80131668;
        }
    }

label_80131660:
    ctx->pc = 0x80131660u;
    ctx->downcount -= 1;
    // 80131660: bl      0x80281D80
    {
            ctx->lr = 0x80131664u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80131664:
    ctx->pc = 0x80131664u;
    ctx->downcount -= 1;
    // 80131664: b       0x8013166C
    {
            goto label_8013166C;
    }

label_80131668:
    ctx->pc = 0x80131668u;
    ctx->downcount -= 1;
    // 80131668: bl      0x8001D934
    {
            ctx->lr = 0x8013166Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_8013166C:
    ctx->pc = 0x8013166Cu;
    ctx->downcount -= 3;
    // 8013166C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80131670:
    ctx->pc = 0x80131670u;
    // 80131670: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80131674:
    ctx->pc = 0x80131674u;
    // 80131674: bl      0x8015AE74
    {
            ctx->lr = 0x80131678u;
            ctx->pc = 0x8015AE74u;
            return;
    }

label_80131678:
    ctx->pc = 0x80131678u;
    ctx->downcount -= 16;
    // 80131678: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013167C:
    ctx->pc = 0x8013167Cu;
    // 8013167C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131680:
    ctx->pc = 0x80131680u;
    // 80131680: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80131684:
    ctx->pc = 0x80131684u;
    // 80131684: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80131688:
    ctx->pc = 0x80131688u;
    // 80131688: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013168C:
    ctx->pc = 0x8013168Cu;
    ctx->downcount -= 19;
    // 8013168C: stwu     r1, -152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-152);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80131690:
    ctx->pc = 0x80131690u;
    // 80131690: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80131694:
    ctx->pc = 0x80131694u;
    // 80131694: stfd     f29, 128(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131694u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_80131698:
    ctx->pc = 0x80131698u;
    // 80131698: stfd     f30, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131698u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8013169C:
    ctx->pc = 0x8013169Cu;
    // 8013169C: stfd     f31, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x8013169Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_801316A0:
    ctx->pc = 0x801316A0u;
    // 801316A0: stmw     r26, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801316A4:
    ctx->pc = 0x801316A4u;
    // 801316A4: stw     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801316A8:
    ctx->pc = 0x801316A8u;
    // 801316A8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801316AC:
    ctx->pc = 0x801316ACu;
    // 801316AC: bl      0x8015BA2C
    {
            ctx->lr = 0x801316B0u;
            ctx->pc = 0x8015BA2Cu;
            return;
    }

label_801316B0:
    ctx->pc = 0x801316B0u;
    ctx->downcount -= 5;
    // 801316B0: lwz     r0, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801316B4:
    ctx->pc = 0x801316B4u;
    // 801316B4: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801316B8:
    ctx->pc = 0x801316B8u;
    // 801316B8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801316BC:
    ctx->pc = 0x801316BCu;
    // 801316BC: cmpwi   r0, 0
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

label_801316C0:
    ctx->pc = 0x801316C0u;
    // 801316C0: bc    12, 2, 0x801316D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801316D4;
        }
    }

label_801316C4:
    ctx->pc = 0x801316C4u;
    ctx->downcount -= 3;
    // 801316C4: lwz     r0, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801316C8:
    ctx->pc = 0x801316C8u;
    // 801316C8: cmpwi   r0, 0
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

label_801316CC:
    ctx->pc = 0x801316CCu;
    // 801316CC: bc    12, 2, 0x801316D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801316D4;
        }
    }

label_801316D0:
    ctx->pc = 0x801316D0u;
    ctx->downcount -= 1;
    // 801316D0: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_801316D4:
    ctx->pc = 0x801316D4u;
    ctx->downcount -= 2;
    // 801316D4: cmpwi   r9, 0
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

label_801316D8:
    ctx->pc = 0x801316D8u;
    // 801316D8: bc    12, 2, 0x801319B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801319B4;
        }
    }

label_801316DC:
    ctx->pc = 0x801316DCu;
    ctx->downcount -= 3;
    // 801316DC: lwz     r0, 736(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(736);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801316E0:
    ctx->pc = 0x801316E0u;
    // 801316E0: cmpwi   r0, 0
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

label_801316E4:
    ctx->pc = 0x801316E4u;
    // 801316E4: bc    12, 2, 0x80131760
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131760;
        }
    }

label_801316E8:
    ctx->pc = 0x801316E8u;
    ctx->downcount -= 2;
    // 801316E8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801316EC:
    ctx->pc = 0x801316ECu;
    // 801316EC: bl      0x80133D04
    {
            ctx->lr = 0x801316F0u;
            ctx->pc = 0x80133D04u;
            return;
    }

label_801316F0:
    ctx->pc = 0x801316F0u;
    ctx->downcount -= 2;
    // 801316F0: or.   r30, r3, r3
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

label_801316F4:
    ctx->pc = 0x801316F4u;
    // 801316F4: bc    4, 2, 0x80131760
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80131760;
        }
    }

label_801316F8:
    ctx->pc = 0x801316F8u;
    ctx->downcount -= 4;
    // 801316F8: lwz     r0, 720(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(720);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801316FC:
    ctx->pc = 0x801316FCu;
    // 801316FC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80131700:
    ctx->pc = 0x80131700u;
    // 80131700: cmpwi   r0, -1
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80131704:
    ctx->pc = 0x80131704u;
    // 80131704: bc    12, 2, 0x80131720
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131720;
        }
    }

label_80131708:
    ctx->pc = 0x80131708u;
    ctx->downcount -= 2;
    // 80131708: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8013170C:
    ctx->pc = 0x8013170Cu;
    // 8013170C: bl      0x80133BD8
    {
            ctx->lr = 0x80131710u;
            ctx->pc = 0x80133BD8u;
            return;
    }

label_80131710:
    ctx->pc = 0x80131710u;
    ctx->downcount -= 3;
    // 80131710: lwz     r4, 772(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(772);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131714:
    ctx->pc = 0x80131714u;
    // 80131714: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80131718:
    ctx->pc = 0x80131718u;
    // 80131718: bl      0x80133010
    {
            ctx->lr = 0x8013171Cu;
            goto label_80133010;
    }

label_8013171C:
    ctx->pc = 0x8013171Cu;
    ctx->downcount -= 1;
    // 8013171C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80131720:
    ctx->pc = 0x80131720u;
    ctx->downcount -= 2;
    // 80131720: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80131724:
    ctx->pc = 0x80131724u;
    // 80131724: bl      0x8013367C
    {
            ctx->lr = 0x80131728u;
            ctx->pc = 0x8013367Cu;
            return;
    }

label_80131728:
    ctx->pc = 0x80131728u;
    ctx->downcount -= 4;
    // 80131728: lwz     r0, 776(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(776);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013172C:
    ctx->pc = 0x8013172Cu;
    // 8013172C: cmpwi   r0, 0
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

label_80131730:
    ctx->pc = 0x80131730u;
    // 80131730: stw     r0, 772(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(772);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131734:
    ctx->pc = 0x80131734u;
    // 80131734: bc    4, 2, 0x80131744
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80131744;
        }
    }

label_80131738:
    ctx->pc = 0x80131738u;
    ctx->downcount -= 3;
    // 80131738: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8013173C:
    ctx->pc = 0x8013173Cu;
    // 8013173C: stw     r0, 776(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(776);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131740:
    ctx->pc = 0x80131740u;
    // 80131740: b       0x80131748
    {
            goto label_80131748;
    }

label_80131744:
    ctx->pc = 0x80131744u;
    ctx->downcount -= 1;
    // 80131744: stw     r30, 776(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(776);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131748:
    ctx->pc = 0x80131748u;
    ctx->downcount -= 2;
    // 80131748: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8013174C:
    ctx->pc = 0x8013174Cu;
    // 8013174C: bl      0x80134858
    {
            ctx->lr = 0x80131750u;
            ctx->pc = 0x80134858u;
            return;
    }

label_80131750:
    ctx->pc = 0x80131750u;
    ctx->downcount -= 4;
    // 80131750: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80131754:
    ctx->pc = 0x80131754u;
    // 80131754: addi    r3, r31, 856
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(856);

label_80131758:
    ctx->pc = 0x80131758u;
    // 80131758: stw     r0, 736(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(736);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013175C:
    ctx->pc = 0x8013175Cu;
    // 8013175C: bl      0x801D2F74
    {
            ctx->lr = 0x80131760u;
            ctx->pc = 0x801D2F74u;
            return;
    }

label_80131760:
    ctx->pc = 0x80131760u;
    ctx->downcount -= 3;
    // 80131760: lwz     r0, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131764:
    ctx->pc = 0x80131764u;
    // 80131764: cmpwi   r0, 0
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

label_80131768:
    ctx->pc = 0x80131768u;
    // 80131768: bc    12, 2, 0x80131780
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131780;
        }
    }

label_8013176C:
    ctx->pc = 0x8013176Cu;
    ctx->downcount -= 3;
    // 8013176C: cmpwi   r0, 1
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

label_80131770:
    ctx->pc = 0x80131770u;
    // 80131770: li      r11, 4
    ctx->gpr[11] = (u32)(s32)(4);

label_80131774:
    ctx->pc = 0x80131774u;
    // 80131774: bc    4, 2, 0x80131784
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80131784;
        }
    }

label_80131778:
    ctx->pc = 0x80131778u;
    ctx->downcount -= 2;
    // 80131778: li      r11, 2
    ctx->gpr[11] = (u32)(s32)(2);

label_8013177C:
    ctx->pc = 0x8013177Cu;
    // 8013177C: b       0x80131784
    {
            goto label_80131784;
    }

label_80131780:
    ctx->pc = 0x80131780u;
    ctx->downcount -= 1;
    // 80131780: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80131784:
    ctx->pc = 0x80131784u;
    ctx->downcount -= 5;
    // 80131784: rlwinm r0, r11, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_80131788:
    ctx->pc = 0x80131788u;
    // 80131788: addi    r10, r31, 688
    ctx->gpr[10] = ctx->gpr[31] + (u32)(s32)(688);

label_8013178C:
    ctx->pc = 0x8013178Cu;
    // 8013178C: lwzx    r9, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131790:
    ctx->pc = 0x80131790u;
    // 80131790: cmpwi   r9, 0
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

label_80131794:
    ctx->pc = 0x80131794u;
    // 80131794: bc    12, 2, 0x801319B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801319B4;
        }
    }

label_80131798:
    ctx->pc = 0x80131798u;
    ctx->downcount -= 3;
    // 80131798: lwz     r0, 268(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013179C:
    ctx->pc = 0x8013179Cu;
    // 8013179C: cmpwi   r0, 0
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

label_801317A0:
    ctx->pc = 0x801317A0u;
    // 801317A0: bc    12, 2, 0x801319B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801319B4;
        }
    }

label_801317A4:
    ctx->pc = 0x801317A4u;
    ctx->downcount -= 6;
    // 801317A4: addi    r0, r11, 1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(1);

label_801317A8:
    ctx->pc = 0x801317A8u;
    // 801317A8: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_801317AC:
    ctx->pc = 0x801317ACu;
    // 801317AC: lwzx    r9, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801317B0:
    ctx->pc = 0x801317B0u;
    // 801317B0: lwz     r11, 268(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(268);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801317B4:
    ctx->pc = 0x801317B4u;
    // 801317B4: cmpwi   r11, 0
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

label_801317B8:
    ctx->pc = 0x801317B8u;
    // 801317B8: bc    12, 2, 0x801319B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801319B4;
        }
    }

label_801317BC:
    ctx->pc = 0x801317BCu;
    ctx->downcount -= 3;
    // 801317BC: lwz     r9, 868(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(868);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801317C0:
    ctx->pc = 0x801317C0u;
    // 801317C0: cmpwi   r9, 0
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

label_801317C4:
    ctx->pc = 0x801317C4u;
    // 801317C4: bc    12, 2, 0x8013188C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013188C;
        }
    }

label_801317C8:
    ctx->pc = 0x801317C8u;
    ctx->downcount -= 14;
    // 801317C8: lwz     r0, 124(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801317CC:
    ctx->pc = 0x801317CCu;
    // 801317CC: addi    r29, r1, 40
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(40);

label_801317D0:
    ctx->pc = 0x801317D0u;
    // 801317D0: addi    r9, r9, 124
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(124);

label_801317D4:
    ctx->pc = 0x801317D4u;
    // 801317D4: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_801317D8:
    ctx->pc = 0x801317D8u;
    // 801317D8: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801317DC:
    ctx->pc = 0x801317DCu;
    // 801317DC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801317E0:
    ctx->pc = 0x801317E0u;
    // 801317E0: lwz     r8, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801317E4:
    ctx->pc = 0x801317E4u;
    // 801317E4: addi    r4, r4, 18216
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18216);

label_801317E8:
    ctx->pc = 0x801317E8u;
    // 801317E8: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801317EC:
    ctx->pc = 0x801317ECu;
    // 801317EC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801317F0:
    ctx->pc = 0x801317F0u;
    // 801317F0: stw     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801317F4:
    ctx->pc = 0x801317F4u;
    // 801317F4: lis     r28, -32721
    ctx->gpr[28] = ((u32)(s32)(-32721) << 16);

label_801317F8:
    ctx->pc = 0x801317F8u;
    // 801317F8: stw     r8, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_801317FC:
    ctx->pc = 0x801317FCu;
    // 801317FC: bl      0x801CFE08
    {
            ctx->lr = 0x80131800u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80131800:
    ctx->pc = 0x80131800u;
    ctx->downcount -= 11;
    // 80131800: lwz     r11, 868(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(868);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131804:
    ctx->pc = 0x80131804u;
    // 80131804: addi    r30, r1, 64
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(64);

label_80131808:
    ctx->pc = 0x80131808u;
    // 80131808: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8013180C:
    ctx->pc = 0x8013180Cu;
    // 8013180C: addi    r27, r1, 48
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(48);

label_80131810:
    ctx->pc = 0x80131810u;
    // 80131810: lwz     r9, 108(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131814:
    ctx->pc = 0x80131814u;
    // 80131814: lha     r4, 72(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(72);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131818:
    ctx->pc = 0x80131818u;
    // 80131818: lwz     r0, 76(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013181C:
    ctx->pc = 0x8013181Cu;
    // 8013181C: add   r4, r11, r4
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80131820:
    ctx->pc = 0x80131820u;
    // 80131820: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131824:
    ctx->pc = 0x80131824u;
    // 80131824: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131828u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131828:
    ctx->pc = 0x80131828u;
    ctx->downcount -= 2;
    // 80131828: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8013182C:
    ctx->pc = 0x8013182Cu;
    // 8013182C: bl      0x801D0C78
    {
            ctx->lr = 0x80131830u;
            ctx->pc = 0x801D0C78u;
            return;
    }

label_80131830:
    ctx->pc = 0x80131830u;
    ctx->downcount -= 6;
    // 80131830: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x80131830u)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_80131834:
    ctx->pc = 0x80131834u;
    // 80131834: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80131838:
    ctx->pc = 0x80131838u;
    // 80131838: lfs     f1, 18300(r28)
    if (!ppc_fp_available_inline(ctx, 0x80131838u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(18300);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8013183C:
    ctx->pc = 0x8013183Cu;
    // 8013183C: addi    r4, r4, 18232
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18232);

label_80131840:
    ctx->pc = 0x80131840u;
    // 80131840: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80131844:
    ctx->pc = 0x80131844u;
    // 80131844: bl      0x801D009C
    {
            ctx->lr = 0x80131848u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80131848:
    ctx->pc = 0x80131848u;
    ctx->downcount -= 5;
    // 80131848: lfs     f2, 18300(r28)
    if (!ppc_fp_available_inline(ctx, 0x80131848u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(18300);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8013184C:
    ctx->pc = 0x8013184Cu;
    // 8013184C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80131850:
    ctx->pc = 0x80131850u;
    // 80131850: fadds   f1, f31, f1
    if (!ppc_fp_available_inline(ctx, 0x80131850u)) return;
    ppc_fadds(ctx, 1, 31, 1);

label_80131854:
    ctx->pc = 0x80131854u;
    // 80131854: fmr    f3, f2
    if (!ppc_fp_available_inline(ctx, 0x80131854u)) return;
    ctx->fpr[3] = ctx->fpr[2];

label_80131858:
    ctx->pc = 0x80131858u;
    // 80131858: bl      0x801D04B8
    {
            ctx->lr = 0x8013185Cu;
            ctx->pc = 0x801D04B8u;
            return;
    }

label_8013185C:
    ctx->pc = 0x8013185Cu;
    ctx->downcount -= 11;
    // 8013185C: lfs     f11, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x8013185Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_80131860:
    ctx->pc = 0x80131860u;
    // 80131860: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80131864:
    ctx->pc = 0x80131864u;
    // 80131864: lfs     f12, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131864u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_80131868:
    ctx->pc = 0x80131868u;
    // 80131868: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8013186C:
    ctx->pc = 0x8013186Cu;
    // 8013186C: lfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x8013186Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80131870:
    ctx->pc = 0x80131870u;
    // 80131870: lfs     f13, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131870u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80131874:
    ctx->pc = 0x80131874u;
    // 80131874: stfs     f11, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131874u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_80131878:
    ctx->pc = 0x80131878u;
    // 80131878: stfs     f12, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131878u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_8013187C:
    ctx->pc = 0x8013187Cu;
    // 8013187C: stfs     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8013187Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80131880:
    ctx->pc = 0x80131880u;
    // 80131880: stfs     f13, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131880u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80131884:
    ctx->pc = 0x80131884u;
    // 80131884: bl      0x801CFEAC
    {
            ctx->lr = 0x80131888u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80131888:
    ctx->pc = 0x80131888u;
    ctx->downcount -= 1;
    // 80131888: b       0x80131984
    {
            goto label_80131984;
    }

label_8013188C:
    ctx->pc = 0x8013188Cu;
    ctx->downcount -= 3;
    // 8013188C: li      r3, 384
    ctx->gpr[3] = (u32)(s32)(384);

label_80131890:
    ctx->pc = 0x80131890u;
    // 80131890: lis     r30, -32721
    ctx->gpr[30] = ((u32)(s32)(-32721) << 16);

label_80131894:
    ctx->pc = 0x80131894u;
    // 80131894: bl      0x80281C60
    {
            ctx->lr = 0x80131898u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80131898:
    ctx->pc = 0x80131898u;
    ctx->downcount -= 4;
    // 80131898: lfs     f1, 18300(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131898u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(18300);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8013189C:
    ctx->pc = 0x8013189Cu;
    // 8013189C: addi    r29, r1, 40
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(40);

label_801318A0:
    ctx->pc = 0x801318A0u;
    // 801318A0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801318A4:
    ctx->pc = 0x801318A4u;
    // 801318A4: bl      0x80153CB4
    {
            ctx->lr = 0x801318A8u;
            ctx->pc = 0x80153CB4u;
            return;
    }

label_801318A8:
    ctx->pc = 0x801318A8u;
    ctx->downcount -= 12;
    // 801318A8: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_801318AC:
    ctx->pc = 0x801318ACu;
    // 801318AC: lfs     f31, 18300(r30)
    if (!ppc_fp_available_inline(ctx, 0x801318ACu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(18300);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_801318B0:
    ctx->pc = 0x801318B0u;
    // 801318B0: lfs     f0, 18304(r11)
    if (!ppc_fp_available_inline(ctx, 0x801318B0u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(18304);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801318B4:
    ctx->pc = 0x801318B4u;
    // 801318B4: addi    r9, r1, 56
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(56);

label_801318B8:
    ctx->pc = 0x801318B8u;
    // 801318B8: stw     r3, 868(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(868);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801318BC:
    ctx->pc = 0x801318BCu;
    // 801318BC: or   r4, r9, r9
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[9];
    }

label_801318C0:
    ctx->pc = 0x801318C0u;
    // 801318C0: stfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x801318C0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801318C4:
    ctx->pc = 0x801318C4u;
    // 801318C4: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x801318C4u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_801318C8:
    ctx->pc = 0x801318C8u;
    // 801318C8: stfs     f31, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x801318C8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801318CC:
    ctx->pc = 0x801318CCu;
    // 801318CC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801318D0:
    ctx->pc = 0x801318D0u;
    // 801318D0: stfs     f31, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x801318D0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801318D4:
    ctx->pc = 0x801318D4u;
    // 801318D4: bl      0x801D0BB4
    {
            ctx->lr = 0x801318D8u;
            ctx->pc = 0x801D0BB4u;
            return;
    }

label_801318D8:
    ctx->pc = 0x801318D8u;
    ctx->downcount -= 12;
    // 801318D8: lfs     f11, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x801318D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_801318DC:
    ctx->pc = 0x801318DCu;
    // 801318DC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801318E0:
    ctx->pc = 0x801318E0u;
    // 801318E0: lfs     f12, 44(r1)
    if (!ppc_fp_available_inline(ctx, 0x801318E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801318E4:
    ctx->pc = 0x801318E4u;
    // 801318E4: addi    r4, r4, 18256
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18256);

label_801318E8:
    ctx->pc = 0x801318E8u;
    // 801318E8: lfs     f13, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x801318E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801318EC:
    ctx->pc = 0x801318ECu;
    // 801318EC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801318F0:
    ctx->pc = 0x801318F0u;
    // 801318F0: lfs     f0, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x801318F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801318F4:
    ctx->pc = 0x801318F4u;
    // 801318F4: stfs     f11, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x801318F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_801318F8:
    ctx->pc = 0x801318F8u;
    // 801318F8: stfs     f12, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x801318F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_801318FC:
    ctx->pc = 0x801318FCu;
    // 801318FC: stfs     f13, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x801318FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80131900:
    ctx->pc = 0x80131900u;
    // 80131900: stfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131900u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80131904:
    ctx->pc = 0x80131904u;
    // 80131904: bl      0x801CFE08
    {
            ctx->lr = 0x80131908u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80131908:
    ctx->pc = 0x80131908u;
    ctx->downcount -= 5;
    // 80131908: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8013190C:
    ctx->pc = 0x8013190Cu;
    // 8013190C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80131910:
    ctx->pc = 0x80131910u;
    // 80131910: addi    r4, r4, 18288
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18288);

label_80131914:
    ctx->pc = 0x80131914u;
    // 80131914: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80131914u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80131918:
    ctx->pc = 0x80131918u;
    // 80131918: bl      0x801D009C
    {
            ctx->lr = 0x8013191Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8013191C:
    ctx->pc = 0x8013191Cu;
    ctx->downcount -= 6;
    // 8013191C: fmr    f29, f1
    if (!ppc_fp_available_inline(ctx, 0x8013191Cu)) return;
    ctx->fpr[29] = ctx->fpr[1];

label_80131920:
    ctx->pc = 0x80131920u;
    // 80131920: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80131924:
    ctx->pc = 0x80131924u;
    // 80131924: addi    r4, r4, 18292
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18292);

label_80131928:
    ctx->pc = 0x80131928u;
    // 80131928: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013192C:
    ctx->pc = 0x8013192Cu;
    // 8013192C: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x8013192Cu)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80131930:
    ctx->pc = 0x80131930u;
    // 80131930: bl      0x801D009C
    {
            ctx->lr = 0x80131934u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80131934:
    ctx->pc = 0x80131934u;
    ctx->downcount -= 6;
    // 80131934: fmr    f30, f1
    if (!ppc_fp_available_inline(ctx, 0x80131934u)) return;
    ctx->fpr[30] = ctx->fpr[1];

label_80131938:
    ctx->pc = 0x80131938u;
    // 80131938: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8013193C:
    ctx->pc = 0x8013193Cu;
    // 8013193C: addi    r4, r4, 18296
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18296);

label_80131940:
    ctx->pc = 0x80131940u;
    // 80131940: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80131944:
    ctx->pc = 0x80131944u;
    // 80131944: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80131944u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80131948:
    ctx->pc = 0x80131948u;
    // 80131948: bl      0x801D009C
    {
            ctx->lr = 0x8013194Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8013194C:
    ctx->pc = 0x8013194Cu;
    ctx->downcount -= 14;
    // 8013194C: stfs     f29, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x8013194Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_80131950:
    ctx->pc = 0x80131950u;
    // 80131950: addi    r10, r1, 48
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(48);

label_80131954:
    ctx->pc = 0x80131954u;
    // 80131954: stfs     f30, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131954u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80131958:
    ctx->pc = 0x80131958u;
    // 80131958: addi    r8, r1, 8
    ctx->gpr[8] = ctx->gpr[1] + (u32)(s32)(8);

label_8013195C:
    ctx->pc = 0x8013195Cu;
    // 8013195C: stfs     f1, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x8013195Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80131960:
    ctx->pc = 0x80131960u;
    // 80131960: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80131964:
    ctx->pc = 0x80131964u;
    // 80131964: lwz     r11, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131968:
    ctx->pc = 0x80131968u;
    // 80131968: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8013196C:
    ctx->pc = 0x8013196Cu;
    // 8013196C: lwz     r0, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131970:
    ctx->pc = 0x80131970u;
    // 80131970: lwz     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131974:
    ctx->pc = 0x80131974u;
    // 80131974: stw     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80131978:
    ctx->pc = 0x80131978u;
    // 80131978: stw     r0, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013197C:
    ctx->pc = 0x8013197Cu;
    // 8013197C: stw     r9, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80131980:
    ctx->pc = 0x80131980u;
    // 80131980: bl      0x801CFEAC
    {
            ctx->lr = 0x80131984u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80131984:
    ctx->pc = 0x80131984u;
    ctx->downcount -= 3;
    // 80131984: addi    r29, r1, 24
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(24);

label_80131988:
    ctx->pc = 0x80131988u;
    // 80131988: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8013198C:
    ctx->pc = 0x8013198Cu;
    // 8013198C: bl      0x80133504
    {
            ctx->lr = 0x80131990u;
            ctx->pc = 0x80133504u;
            return;
    }

label_80131990:
    ctx->pc = 0x80131990u;
    ctx->downcount -= 4;
    // 80131990: lwz     r3, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80131994:
    ctx->pc = 0x80131994u;
    // 80131994: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80131998:
    ctx->pc = 0x80131998u;
    // 80131998: lwz     r30, 868(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(868);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8013199C:
    ctx->pc = 0x8013199Cu;
    // 8013199C: bl      0x802198F4
    {
            ctx->lr = 0x801319A0u;
            ctx->pc = 0x802198F4u;
            return;
    }

label_801319A0:
    ctx->pc = 0x801319A0u;
    ctx->downcount -= 5;
    // 801319A0: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801319A4:
    ctx->pc = 0x801319A4u;
    // 801319A4: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801319A8:
    ctx->pc = 0x801319A8u;
    // 801319A8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801319AC:
    ctx->pc = 0x801319ACu;
    // 801319AC: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_801319B0:
    ctx->pc = 0x801319B0u;
    // 801319B0: bl      0x802066E0
    {
            ctx->lr = 0x801319B4u;
            ctx->pc = 0x802066E0u;
            return;
    }

label_801319B4:
    ctx->pc = 0x801319B4u;
    ctx->downcount -= 20;
    // 801319B4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801319B8:
    ctx->pc = 0x801319B8u;
    // 801319B8: lwz     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801319BC:
    ctx->pc = 0x801319BCu;
    // 801319BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801319C0:
    ctx->pc = 0x801319C0u;
    // 801319C0: lmw     r26, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801319C4:
    ctx->pc = 0x801319C4u;
    // 801319C4: lfd     f29, 128(r1)
    if (!ppc_fp_available_inline(ctx, 0x801319C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801319C8:
    ctx->pc = 0x801319C8u;
    // 801319C8: lfd     f30, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x801319C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801319CC:
    ctx->pc = 0x801319CCu;
    // 801319CC: lfd     f31, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x801319CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801319D0:
    ctx->pc = 0x801319D0u;
    // 801319D0: addi    r1, r1, 152
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(152);

label_801319D4:
    ctx->pc = 0x801319D4u;
    // 801319D4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801319D8:
    ctx->pc = 0x801319D8u;
    ctx->downcount -= 17;
    // 801319D8: stwu     r1, -624(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-624);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801319DC:
    ctx->pc = 0x801319DCu;
    // 801319DC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801319E0:
    ctx->pc = 0x801319E0u;
    // 801319E0: stfd     f31, 616(r1)
    if (!ppc_fp_available_inline(ctx, 0x801319E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(616);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_801319E4:
    ctx->pc = 0x801319E4u;
    // 801319E4: stmw     r23, 580(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(580);
        for (u32 r = 23; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801319E8:
    ctx->pc = 0x801319E8u;
    // 801319E8: stw     r0, 628(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(628);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801319EC:
    ctx->pc = 0x801319ECu;
    // 801319EC: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801319F0:
    ctx->pc = 0x801319F0u;
    // 801319F0: bl      0x8015E4A4
    {
            ctx->lr = 0x801319F4u;
            ctx->pc = 0x8015E4A4u;
            return;
    }

label_801319F4:
    ctx->pc = 0x801319F4u;
    ctx->downcount -= 9;
    // 801319F4: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801319F8:
    ctx->pc = 0x801319F8u;
    // 801319F8: addi    r30, r1, 16
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(16);

label_801319FC:
    ctx->pc = 0x801319FCu;
    // 801319FC: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80131A00:
    ctx->pc = 0x80131A00u;
    // 80131A00: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80131A04:
    ctx->pc = 0x80131A04u;
    // 80131A04: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131A08:
    ctx->pc = 0x80131A08u;
    // 80131A08: or   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80131A0C:
    ctx->pc = 0x80131A0Cu;
    // 80131A0C: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131A10:
    ctx->pc = 0x80131A10u;
    // 80131A10: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80131A14:
    ctx->pc = 0x80131A14u;
    // 80131A14: bl      0x801CF88C
    {
            ctx->lr = 0x80131A18u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80131A18:
    ctx->pc = 0x80131A18u;
    ctx->downcount -= 2;
    // 80131A18: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80131A1C:
    ctx->pc = 0x80131A1Cu;
    // 80131A1C: bl      0x80281C60
    {
            ctx->lr = 0x80131A20u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80131A20:
    ctx->pc = 0x80131A20u;
    ctx->downcount -= 6;
    // 80131A20: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80131A24:
    ctx->pc = 0x80131A24u;
    // 80131A24: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80131A28:
    ctx->pc = 0x80131A28u;
    // 80131A28: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80131A2C:
    ctx->pc = 0x80131A2Cu;
    // 80131A2C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80131A30:
    ctx->pc = 0x80131A30u;
    // 80131A30: addi    r4, r4, 18308
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18308);

label_80131A34:
    ctx->pc = 0x80131A34u;
    // 80131A34: bl      0x801427A0
    {
            ctx->lr = 0x80131A38u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80131A38:
    ctx->pc = 0x80131A38u;
    ctx->downcount -= 15;
    // 80131A38: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80131A3C:
    ctx->pc = 0x80131A3Cu;
    // 80131A3C: stw     r3, 780(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(780);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80131A40:
    ctx->pc = 0x80131A40u;
    // 80131A40: lfs     f31, 18768(r9)
    if (!ppc_fp_available_inline(ctx, 0x80131A40u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18768);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80131A44:
    ctx->pc = 0x80131A44u;
    // 80131A44: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80131A48:
    ctx->pc = 0x80131A48u;
    // 80131A48: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80131A4C:
    ctx->pc = 0x80131A4Cu;
    // 80131A4C: stfs     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131A4Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131A50:
    ctx->pc = 0x80131A50u;
    // 80131A50: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131A50u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131A54:
    ctx->pc = 0x80131A54u;
    // 80131A54: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131A54u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131A58:
    ctx->pc = 0x80131A58u;
    // 80131A58: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131A5C:
    ctx->pc = 0x80131A5Cu;
    // 80131A5C: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131A60:
    ctx->pc = 0x80131A60u;
    // 80131A60: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131A64:
    ctx->pc = 0x80131A64u;
    // 80131A64: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131A68:
    ctx->pc = 0x80131A68u;
    // 80131A68: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80131A6C:
    ctx->pc = 0x80131A6Cu;
    // 80131A6C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131A70u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131A70:
    ctx->pc = 0x80131A70u;
    ctx->downcount -= 7;
    // 80131A70: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131A74:
    ctx->pc = 0x80131A74u;
    // 80131A74: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80131A78:
    ctx->pc = 0x80131A78u;
    // 80131A78: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80131A7C:
    ctx->pc = 0x80131A7Cu;
    // 80131A7C: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131A80:
    ctx->pc = 0x80131A80u;
    // 80131A80: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131A84:
    ctx->pc = 0x80131A84u;
    // 80131A84: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80131A88:
    ctx->pc = 0x80131A88u;
    // 80131A88: bl      0x801CF88C
    {
            ctx->lr = 0x80131A8Cu;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80131A8C:
    ctx->pc = 0x80131A8Cu;
    ctx->downcount -= 2;
    // 80131A8C: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80131A90:
    ctx->pc = 0x80131A90u;
    // 80131A90: bl      0x80281C60
    {
            ctx->lr = 0x80131A94u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80131A94:
    ctx->pc = 0x80131A94u;
    ctx->downcount -= 6;
    // 80131A94: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80131A98:
    ctx->pc = 0x80131A98u;
    // 80131A98: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80131A9C:
    ctx->pc = 0x80131A9Cu;
    // 80131A9C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80131AA0:
    ctx->pc = 0x80131AA0u;
    // 80131AA0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80131AA4:
    ctx->pc = 0x80131AA4u;
    // 80131AA4: addi    r4, r4, 18356
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18356);

label_80131AA8:
    ctx->pc = 0x80131AA8u;
    // 80131AA8: bl      0x801427A0
    {
            ctx->lr = 0x80131AACu;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80131AAC:
    ctx->pc = 0x80131AACu;
    ctx->downcount -= 13;
    // 80131AAC: stfs     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131AACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131AB0:
    ctx->pc = 0x80131AB0u;
    // 80131AB0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80131AB4:
    ctx->pc = 0x80131AB4u;
    // 80131AB4: stw     r3, 784(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(784);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80131AB8:
    ctx->pc = 0x80131AB8u;
    // 80131AB8: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80131ABC:
    ctx->pc = 0x80131ABCu;
    // 80131ABC: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131ABCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131AC0:
    ctx->pc = 0x80131AC0u;
    // 80131AC0: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131AC0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131AC4:
    ctx->pc = 0x80131AC4u;
    // 80131AC4: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131AC8:
    ctx->pc = 0x80131AC8u;
    // 80131AC8: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131ACC:
    ctx->pc = 0x80131ACCu;
    // 80131ACC: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131AD0:
    ctx->pc = 0x80131AD0u;
    // 80131AD0: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131AD4:
    ctx->pc = 0x80131AD4u;
    // 80131AD4: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80131AD8:
    ctx->pc = 0x80131AD8u;
    // 80131AD8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131ADCu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131ADC:
    ctx->pc = 0x80131ADCu;
    ctx->downcount -= 7;
    // 80131ADC: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131AE0:
    ctx->pc = 0x80131AE0u;
    // 80131AE0: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80131AE4:
    ctx->pc = 0x80131AE4u;
    // 80131AE4: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80131AE8:
    ctx->pc = 0x80131AE8u;
    // 80131AE8: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131AEC:
    ctx->pc = 0x80131AECu;
    // 80131AEC: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131AF0:
    ctx->pc = 0x80131AF0u;
    // 80131AF0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80131AF4:
    ctx->pc = 0x80131AF4u;
    // 80131AF4: bl      0x801CF88C
    {
            ctx->lr = 0x80131AF8u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80131AF8:
    ctx->pc = 0x80131AF8u;
    ctx->downcount -= 2;
    // 80131AF8: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80131AFC:
    ctx->pc = 0x80131AFCu;
    // 80131AFC: bl      0x80281C60
    {
            ctx->lr = 0x80131B00u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80131B00:
    ctx->pc = 0x80131B00u;
    ctx->downcount -= 6;
    // 80131B00: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80131B04:
    ctx->pc = 0x80131B04u;
    // 80131B04: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80131B08:
    ctx->pc = 0x80131B08u;
    // 80131B08: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80131B0C:
    ctx->pc = 0x80131B0Cu;
    // 80131B0C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80131B10:
    ctx->pc = 0x80131B10u;
    // 80131B10: addi    r4, r4, 18404
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18404);

label_80131B14:
    ctx->pc = 0x80131B14u;
    // 80131B14: bl      0x801427A0
    {
            ctx->lr = 0x80131B18u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80131B18:
    ctx->pc = 0x80131B18u;
    ctx->downcount -= 13;
    // 80131B18: stfs     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131B18u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131B1C:
    ctx->pc = 0x80131B1Cu;
    // 80131B1C: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80131B20:
    ctx->pc = 0x80131B20u;
    // 80131B20: stw     r3, 788(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(788);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80131B24:
    ctx->pc = 0x80131B24u;
    // 80131B24: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80131B28:
    ctx->pc = 0x80131B28u;
    // 80131B28: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131B28u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131B2C:
    ctx->pc = 0x80131B2Cu;
    // 80131B2C: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131B2Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131B30:
    ctx->pc = 0x80131B30u;
    // 80131B30: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131B34:
    ctx->pc = 0x80131B34u;
    // 80131B34: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131B38:
    ctx->pc = 0x80131B38u;
    // 80131B38: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131B3C:
    ctx->pc = 0x80131B3Cu;
    // 80131B3C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131B40:
    ctx->pc = 0x80131B40u;
    // 80131B40: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80131B44:
    ctx->pc = 0x80131B44u;
    // 80131B44: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131B48u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131B48:
    ctx->pc = 0x80131B48u;
    ctx->downcount -= 7;
    // 80131B48: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131B4C:
    ctx->pc = 0x80131B4Cu;
    // 80131B4C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80131B50:
    ctx->pc = 0x80131B50u;
    // 80131B50: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80131B54:
    ctx->pc = 0x80131B54u;
    // 80131B54: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131B58:
    ctx->pc = 0x80131B58u;
    // 80131B58: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131B5C:
    ctx->pc = 0x80131B5Cu;
    // 80131B5C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80131B60:
    ctx->pc = 0x80131B60u;
    // 80131B60: bl      0x801CF88C
    {
            ctx->lr = 0x80131B64u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80131B64:
    ctx->pc = 0x80131B64u;
    ctx->downcount -= 2;
    // 80131B64: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80131B68:
    ctx->pc = 0x80131B68u;
    // 80131B68: bl      0x80281C60
    {
            ctx->lr = 0x80131B6Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80131B6C:
    ctx->pc = 0x80131B6Cu;
    ctx->downcount -= 6;
    // 80131B6C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80131B70:
    ctx->pc = 0x80131B70u;
    // 80131B70: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80131B74:
    ctx->pc = 0x80131B74u;
    // 80131B74: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80131B78:
    ctx->pc = 0x80131B78u;
    // 80131B78: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80131B7C:
    ctx->pc = 0x80131B7Cu;
    // 80131B7C: addi    r4, r4, 18456
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18456);

label_80131B80:
    ctx->pc = 0x80131B80u;
    // 80131B80: bl      0x801427A0
    {
            ctx->lr = 0x80131B84u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80131B84:
    ctx->pc = 0x80131B84u;
    ctx->downcount -= 13;
    // 80131B84: stfs     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131B84u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131B88:
    ctx->pc = 0x80131B88u;
    // 80131B88: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80131B8C:
    ctx->pc = 0x80131B8Cu;
    // 80131B8C: stw     r3, 792(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(792);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80131B90:
    ctx->pc = 0x80131B90u;
    // 80131B90: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80131B94:
    ctx->pc = 0x80131B94u;
    // 80131B94: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131B94u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131B98:
    ctx->pc = 0x80131B98u;
    // 80131B98: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131B98u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131B9C:
    ctx->pc = 0x80131B9Cu;
    // 80131B9C: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131BA0:
    ctx->pc = 0x80131BA0u;
    // 80131BA0: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131BA4:
    ctx->pc = 0x80131BA4u;
    // 80131BA4: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131BA8:
    ctx->pc = 0x80131BA8u;
    // 80131BA8: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131BAC:
    ctx->pc = 0x80131BACu;
    // 80131BAC: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80131BB0:
    ctx->pc = 0x80131BB0u;
    // 80131BB0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131BB4u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131BB4:
    ctx->pc = 0x80131BB4u;
    ctx->downcount -= 7;
    // 80131BB4: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131BB8:
    ctx->pc = 0x80131BB8u;
    // 80131BB8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80131BBC:
    ctx->pc = 0x80131BBCu;
    // 80131BBC: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80131BC0:
    ctx->pc = 0x80131BC0u;
    // 80131BC0: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131BC4:
    ctx->pc = 0x80131BC4u;
    // 80131BC4: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131BC8:
    ctx->pc = 0x80131BC8u;
    // 80131BC8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80131BCC:
    ctx->pc = 0x80131BCCu;
    // 80131BCC: bl      0x801CF88C
    {
            ctx->lr = 0x80131BD0u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80131BD0:
    ctx->pc = 0x80131BD0u;
    ctx->downcount -= 2;
    // 80131BD0: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80131BD4:
    ctx->pc = 0x80131BD4u;
    // 80131BD4: bl      0x80281C60
    {
            ctx->lr = 0x80131BD8u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80131BD8:
    ctx->pc = 0x80131BD8u;
    ctx->downcount -= 6;
    // 80131BD8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80131BDC:
    ctx->pc = 0x80131BDCu;
    // 80131BDC: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80131BE0:
    ctx->pc = 0x80131BE0u;
    // 80131BE0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80131BE4:
    ctx->pc = 0x80131BE4u;
    // 80131BE4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80131BE8:
    ctx->pc = 0x80131BE8u;
    // 80131BE8: addi    r4, r4, 18508
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18508);

label_80131BEC:
    ctx->pc = 0x80131BECu;
    // 80131BEC: bl      0x801427A0
    {
            ctx->lr = 0x80131BF0u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80131BF0:
    ctx->pc = 0x80131BF0u;
    ctx->downcount -= 13;
    // 80131BF0: stfs     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131BF0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131BF4:
    ctx->pc = 0x80131BF4u;
    // 80131BF4: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80131BF8:
    ctx->pc = 0x80131BF8u;
    // 80131BF8: stw     r3, 796(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(796);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80131BFC:
    ctx->pc = 0x80131BFCu;
    // 80131BFC: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80131C00:
    ctx->pc = 0x80131C00u;
    // 80131C00: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131C00u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131C04:
    ctx->pc = 0x80131C04u;
    // 80131C04: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131C04u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131C08:
    ctx->pc = 0x80131C08u;
    // 80131C08: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131C0C:
    ctx->pc = 0x80131C0Cu;
    // 80131C0C: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131C10:
    ctx->pc = 0x80131C10u;
    // 80131C10: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131C14:
    ctx->pc = 0x80131C14u;
    // 80131C14: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131C18:
    ctx->pc = 0x80131C18u;
    // 80131C18: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80131C1C:
    ctx->pc = 0x80131C1Cu;
    // 80131C1C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131C20u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131C20:
    ctx->pc = 0x80131C20u;
    ctx->downcount -= 7;
    // 80131C20: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131C24:
    ctx->pc = 0x80131C24u;
    // 80131C24: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80131C28:
    ctx->pc = 0x80131C28u;
    // 80131C28: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80131C2C:
    ctx->pc = 0x80131C2Cu;
    // 80131C2C: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131C30:
    ctx->pc = 0x80131C30u;
    // 80131C30: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131C34:
    ctx->pc = 0x80131C34u;
    // 80131C34: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80131C38:
    ctx->pc = 0x80131C38u;
    // 80131C38: bl      0x801CF88C
    {
            ctx->lr = 0x80131C3Cu;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80131C3C:
    ctx->pc = 0x80131C3Cu;
    ctx->downcount -= 2;
    // 80131C3C: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80131C40:
    ctx->pc = 0x80131C40u;
    // 80131C40: bl      0x80281C60
    {
            ctx->lr = 0x80131C44u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80131C44:
    ctx->pc = 0x80131C44u;
    ctx->downcount -= 6;
    // 80131C44: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80131C48:
    ctx->pc = 0x80131C48u;
    // 80131C48: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80131C4C:
    ctx->pc = 0x80131C4Cu;
    // 80131C4C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80131C50:
    ctx->pc = 0x80131C50u;
    // 80131C50: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80131C54:
    ctx->pc = 0x80131C54u;
    // 80131C54: addi    r4, r4, 18560
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18560);

label_80131C58:
    ctx->pc = 0x80131C58u;
    // 80131C58: bl      0x801427A0
    {
            ctx->lr = 0x80131C5Cu;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80131C5C:
    ctx->pc = 0x80131C5Cu;
    ctx->downcount -= 13;
    // 80131C5C: stfs     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131C5Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131C60:
    ctx->pc = 0x80131C60u;
    // 80131C60: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80131C64:
    ctx->pc = 0x80131C64u;
    // 80131C64: stw     r3, 800(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(800);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80131C68:
    ctx->pc = 0x80131C68u;
    // 80131C68: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80131C6C:
    ctx->pc = 0x80131C6Cu;
    // 80131C6C: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131C6Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131C70:
    ctx->pc = 0x80131C70u;
    // 80131C70: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131C70u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131C74:
    ctx->pc = 0x80131C74u;
    // 80131C74: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131C78:
    ctx->pc = 0x80131C78u;
    // 80131C78: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131C7C:
    ctx->pc = 0x80131C7Cu;
    // 80131C7C: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131C80:
    ctx->pc = 0x80131C80u;
    // 80131C80: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131C84:
    ctx->pc = 0x80131C84u;
    // 80131C84: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80131C88:
    ctx->pc = 0x80131C88u;
    // 80131C88: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131C8Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131C8C:
    ctx->pc = 0x80131C8Cu;
    ctx->downcount -= 7;
    // 80131C8C: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131C90:
    ctx->pc = 0x80131C90u;
    // 80131C90: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80131C94:
    ctx->pc = 0x80131C94u;
    // 80131C94: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80131C98:
    ctx->pc = 0x80131C98u;
    // 80131C98: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131C9C:
    ctx->pc = 0x80131C9Cu;
    // 80131C9C: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131CA0:
    ctx->pc = 0x80131CA0u;
    // 80131CA0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80131CA4:
    ctx->pc = 0x80131CA4u;
    // 80131CA4: bl      0x801CF88C
    {
            ctx->lr = 0x80131CA8u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80131CA8:
    ctx->pc = 0x80131CA8u;
    ctx->downcount -= 2;
    // 80131CA8: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80131CAC:
    ctx->pc = 0x80131CACu;
    // 80131CAC: bl      0x80281C60
    {
            ctx->lr = 0x80131CB0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80131CB0:
    ctx->pc = 0x80131CB0u;
    ctx->downcount -= 6;
    // 80131CB0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80131CB4:
    ctx->pc = 0x80131CB4u;
    // 80131CB4: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80131CB8:
    ctx->pc = 0x80131CB8u;
    // 80131CB8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80131CBC:
    ctx->pc = 0x80131CBCu;
    // 80131CBC: addi    r4, r4, 18612
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18612);

label_80131CC0:
    ctx->pc = 0x80131CC0u;
    // 80131CC0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80131CC4:
    ctx->pc = 0x80131CC4u;
    // 80131CC4: bl      0x801427A0
    {
            ctx->lr = 0x80131CC8u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80131CC8:
    ctx->pc = 0x80131CC8u;
    ctx->downcount -= 13;
    // 80131CC8: stfs     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131CC8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131CCC:
    ctx->pc = 0x80131CCCu;
    // 80131CCC: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80131CD0:
    ctx->pc = 0x80131CD0u;
    // 80131CD0: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131CD0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131CD4:
    ctx->pc = 0x80131CD4u;
    // 80131CD4: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80131CD8:
    ctx->pc = 0x80131CD8u;
    // 80131CD8: stw     r3, 804(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(804);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80131CDC:
    ctx->pc = 0x80131CDCu;
    // 80131CDC: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80131CDCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131CE0:
    ctx->pc = 0x80131CE0u;
    // 80131CE0: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131CE4:
    ctx->pc = 0x80131CE4u;
    // 80131CE4: lha     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131CE8:
    ctx->pc = 0x80131CE8u;
    // 80131CE8: lwz     r9, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131CEC:
    ctx->pc = 0x80131CECu;
    // 80131CEC: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131CF0:
    ctx->pc = 0x80131CF0u;
    // 80131CF0: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80131CF4:
    ctx->pc = 0x80131CF4u;
    // 80131CF4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131CF8u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131CF8:
    ctx->pc = 0x80131CF8u;
    ctx->downcount -= 10;
    // 80131CF8: addi    r3, r29, 808
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(808);

label_80131CFC:
    ctx->pc = 0x80131CFCu;
    // 80131CFC: lwz     r11, 808(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(808);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131D00:
    ctx->pc = 0x80131D00u;
    // 80131D00: lwz     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131D04:
    ctx->pc = 0x80131D04u;
    // 80131D04: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80131D08:
    ctx->pc = 0x80131D08u;
    // 80131D08: addi    r6, r1, 560
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(560);

label_80131D0C:
    ctx->pc = 0x80131D0Cu;
    // 80131D0C: stw     r0, 560(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(560);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131D10:
    ctx->pc = 0x80131D10u;
    // 80131D10: subf   r9, r11, r4
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_80131D14:
    ctx->pc = 0x80131D14u;
    // 80131D14: srawi r9, r9, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[9];
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
    }

label_80131D18:
    ctx->pc = 0x80131D18u;
    // 80131D18: cmplwi  r9, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80131D1C:
    ctx->pc = 0x80131D1Cu;
    // 80131D1C: bc    4, 1, 0x80131D2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80131D2C;
        }
    }

label_80131D20:
    ctx->pc = 0x80131D20u;
    ctx->downcount -= 3;
    // 80131D20: addi    r0, r11, 12
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(12);

label_80131D24:
    ctx->pc = 0x80131D24u;
    // 80131D24: stw     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131D28:
    ctx->pc = 0x80131D28u;
    // 80131D28: b       0x80131D34
    {
            goto label_80131D34;
    }

label_80131D2C:
    ctx->pc = 0x80131D2Cu;
    ctx->downcount -= 2;
    // 80131D2C: subfic  r5, r9, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[9]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80131D30:
    ctx->pc = 0x80131D30u;
    // 80131D30: bl      0x801297AC
    {
            ctx->lr = 0x80131D34u;
            ctx->pc = 0x801297ACu;
            return;
    }

label_80131D34:
    ctx->pc = 0x80131D34u;
    ctx->downcount -= 11;
    // 80131D34: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80131D38:
    ctx->pc = 0x80131D38u;
    // 80131D38: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80131D3C:
    ctx->pc = 0x80131D3Cu;
    // 80131D3C: addi    r26, r1, 32
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(32);

label_80131D40:
    ctx->pc = 0x80131D40u;
    // 80131D40: or   r28, r31, r31
    {
        ctx->gpr[28] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80131D44:
    ctx->pc = 0x80131D44u;
    // 80131D44: lfs     f31, 18768(r9)
    if (!ppc_fp_available_inline(ctx, 0x80131D44u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18768);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80131D48:
    ctx->pc = 0x80131D48u;
    // 80131D48: or   r25, r26, r26
    {
        ctx->gpr[25] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80131D4C:
    ctx->pc = 0x80131D4Cu;
    // 80131D4C: stb     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80131D50:
    ctx->pc = 0x80131D50u;
    // 80131D50: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_80131D54:
    ctx->pc = 0x80131D54u;
    // 80131D54: lis     r23, -32721
    ctx->gpr[23] = ((u32)(s32)(-32721) << 16);

label_80131D58:
    ctx->pc = 0x80131D58u;
    // 80131D58: addi    r24, r1, 296
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(296);

label_80131D5C:
    ctx->pc = 0x80131D5Cu;
    // 80131D5C: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80131D60:
    ctx->downcount -= 6;
    // 80131D60: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80131D64:
    // 80131D64: addi    r4, r23, 18672
    ctx->gpr[4] = ctx->gpr[23] + (u32)(s32)(18672);

label_80131D68:
    // 80131D68: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80131D6C:
    // 80131D6C: addi    r27, r27, 1
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(1);

label_80131D70:
    // 80131D70: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80131D74:
    // 80131D74: bl      0x8009258C
    {
            ctx->lr = 0x80131D78u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80131D78:
    ctx->pc = 0x80131D78u;
    ctx->downcount -= 8;
    // 80131D78: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131D7C:
    // 80131D7C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80131D80:
    ctx->pc = 0x80131D80u;
    // 80131D80: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80131D84:
    ctx->pc = 0x80131D84u;
    // 80131D84: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131D88:
    ctx->pc = 0x80131D88u;
    // 80131D88: lwz     r30, 808(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(808);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80131D8C:
    ctx->pc = 0x80131D8Cu;
    // 80131D8C: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131D90:
    // 80131D90: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80131D94:
    // 80131D94: bl      0x801CF88C
    {
            ctx->lr = 0x80131D98u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80131D98:
    ctx->downcount -= 2;
    // 80131D98: li      r3, 364
    ctx->gpr[3] = (u32)(s32)(364);

label_80131D9C:
    // 80131D9C: bl      0x80281C60
    {
            ctx->lr = 0x80131DA0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80131DA0:
    ctx->downcount -= 5;
    // 80131DA0: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80131DA4:
    // 80131DA4: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80131DA8:
    // 80131DA8: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80131DAC:
    // 80131DAC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80131DB0:
    // 80131DB0: bl      0x801427A0
    {
            ctx->lr = 0x80131DB4u;
            ctx->pc = 0x801427A0u;
            return;
    }

label_80131DB4:
    ctx->pc = 0x80131DB4u;
    ctx->downcount -= 16;
    // 80131DB4: stwx    r3, r30, r31
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80131DB8:
    // 80131DB8: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80131DBC:
    ctx->pc = 0x80131DBCu;
    // 80131DBC: stfs     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131DBCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131DC0:
    // 80131DC0: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80131DC4:
    ctx->pc = 0x80131DC4u;
    // 80131DC4: stfs     f31, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x80131DC4u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131DC8:
    ctx->pc = 0x80131DC8u;
    // 80131DC8: stfs     f31, 8(r28)
    if (!ppc_fp_available_inline(ctx, 0x80131DC8u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80131DCC:
    ctx->pc = 0x80131DCCu;
    // 80131DCC: lwz     r9, 808(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131DD0:
    ctx->pc = 0x80131DD0u;
    // 80131DD0: lwzx    r11, r9, r31
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[31];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131DD4:
    // 80131DD4: addi    r31, r31, 4
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(4);

label_80131DD8:
    ctx->pc = 0x80131DD8u;
    // 80131DD8: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131DDC:
    ctx->pc = 0x80131DDCu;
    // 80131DDC: lha     r3, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131DE0:
    ctx->pc = 0x80131DE0u;
    // 80131DE0: lwz     r0, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131DE4:
    // 80131DE4: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131DE8:
    ctx->pc = 0x80131DE8u;
    // 80131DE8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131DEC:
    ctx->pc = 0x80131DECu;
    // 80131DEC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131DF0u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131DF0:
    ctx->downcount -= 2;
    // 80131DF0: cmpwi   r27, 2
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80131DF4:
    // 80131DF4: bc    4, 1, 0x80131D60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80131D60u;
                return;
            }
            goto label_80131D60;
        }
    }

label_80131DF8:
    ctx->pc = 0x80131DF8u;
    ctx->downcount -= 5;
    // 80131DF8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80131DFC:
    ctx->pc = 0x80131DFCu;
    // 80131DFC: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80131E00:
    ctx->pc = 0x80131E00u;
    // 80131E00: addi    r4, r4, 18720
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18720);

label_80131E04:
    ctx->pc = 0x80131E04u;
    // 80131E04: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80131E08:
    ctx->pc = 0x80131E08u;
    // 80131E08: bl      0x8009258C
    {
            ctx->lr = 0x80131E0Cu;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80131E0C:
    ctx->pc = 0x80131E0Cu;
    ctx->downcount -= 4;
    // 80131E0C: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80131E10:
    ctx->pc = 0x80131E10u;
    // 80131E10: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_80131E14:
    ctx->pc = 0x80131E14u;
    // 80131E14: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80131E18:
    ctx->pc = 0x80131E18u;
    // 80131E18: bl      0x80287F10
    {
            ctx->lr = 0x80131E1Cu;
            ctx->pc = 0x80287F10u;
            return;
    }

label_80131E1C:
    ctx->pc = 0x80131E1Cu;
    ctx->downcount -= 7;
    // 80131E1C: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131E20:
    ctx->pc = 0x80131E20u;
    // 80131E20: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80131E24:
    ctx->pc = 0x80131E24u;
    // 80131E24: lwz     r5, 320(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80131E28:
    ctx->pc = 0x80131E28u;
    // 80131E28: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131E2C:
    ctx->pc = 0x80131E2Cu;
    // 80131E2C: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80131E30:
    ctx->pc = 0x80131E30u;
    // 80131E30: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80131E34:
    ctx->pc = 0x80131E34u;
    // 80131E34: bl      0x801CF88C
    {
            ctx->lr = 0x80131E38u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80131E38:
    ctx->pc = 0x80131E38u;
    ctx->downcount -= 2;
    // 80131E38: li      r3, 32
    ctx->gpr[3] = (u32)(s32)(32);

label_80131E3C:
    ctx->pc = 0x80131E3Cu;
    // 80131E3C: bl      0x80281C60
    {
            ctx->lr = 0x80131E40u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80131E40:
    ctx->pc = 0x80131E40u;
    ctx->downcount -= 5;
    // 80131E40: or   r4, r24, r24
    {
        ctx->gpr[4] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80131E44:
    ctx->pc = 0x80131E44u;
    // 80131E44: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80131E48:
    ctx->pc = 0x80131E48u;
    // 80131E48: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80131E4C:
    ctx->pc = 0x80131E4Cu;
    // 80131E4C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80131E50:
    ctx->pc = 0x80131E50u;
    // 80131E50: bl      0x80134CC0
    {
            ctx->lr = 0x80131E54u;
            ctx->pc = 0x80134CC0u;
            return;
    }

label_80131E54:
    ctx->pc = 0x80131E54u;
    ctx->downcount -= 9;
    // 80131E54: stw     r3, 824(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(824);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80131E58:
    ctx->pc = 0x80131E58u;
    // 80131E58: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80131E5C:
    ctx->pc = 0x80131E5Cu;
    // 80131E5C: lwz     r9, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131E60:
    ctx->pc = 0x80131E60u;
    // 80131E60: lha     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131E64:
    ctx->pc = 0x80131E64u;
    // 80131E64: lwz     r9, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131E68:
    ctx->pc = 0x80131E68u;
    // 80131E68: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131E6C:
    ctx->pc = 0x80131E6Cu;
    // 80131E6C: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80131E70:
    ctx->pc = 0x80131E70u;
    // 80131E70: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131E74u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131E74:
    ctx->pc = 0x80131E74u;
    ctx->downcount -= 17;
    // 80131E74: lwz     r0, 628(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(628);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131E78:
    ctx->pc = 0x80131E78u;
    // 80131E78: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131E7C:
    ctx->pc = 0x80131E7Cu;
    // 80131E7C: lmw     r23, 580(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(580);
        for (u32 r = 23; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80131E80:
    ctx->pc = 0x80131E80u;
    // 80131E80: lfd     f31, 616(r1)
    if (!ppc_fp_available_inline(ctx, 0x80131E80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(616);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80131E84:
    ctx->pc = 0x80131E84u;
    // 80131E84: addi    r1, r1, 624
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(624);

label_80131E88:
    ctx->pc = 0x80131E88u;
    // 80131E88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131E8C:
    ctx->pc = 0x80131E8Cu;
    ctx->downcount -= 18;
    // 80131E8C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80131E90:
    ctx->pc = 0x80131E90u;
    // 80131E90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80131E94:
    ctx->pc = 0x80131E94u;
    // 80131E94: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80131E98:
    ctx->pc = 0x80131E98u;
    // 80131E98: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80131E9C:
    ctx->pc = 0x80131E9Cu;
    // 80131E9C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80131EA0:
    ctx->pc = 0x80131EA0u;
    // 80131EA0: lwz     r11, 780(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(780);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131EA4:
    ctx->pc = 0x80131EA4u;
    // 80131EA4: cmpwi   r11, 0
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

label_80131EA8:
    ctx->pc = 0x80131EA8u;
    // 80131EA8: bc    12, 2, 0x80131EC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131EC8;
        }
    }

label_80131EAC:
    ctx->pc = 0x80131EACu;
    ctx->downcount -= 8;
    // 80131EAC: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131EB0:
    ctx->pc = 0x80131EB0u;
    // 80131EB0: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80131EB4:
    ctx->pc = 0x80131EB4u;
    // 80131EB4: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131EB8:
    ctx->pc = 0x80131EB8u;
    // 80131EB8: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131EBC:
    ctx->pc = 0x80131EBCu;
    // 80131EBC: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131EC0:
    ctx->pc = 0x80131EC0u;
    // 80131EC0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131EC4:
    ctx->pc = 0x80131EC4u;
    // 80131EC4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131EC8u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131EC8:
    ctx->pc = 0x80131EC8u;
    ctx->downcount -= 5;
    // 80131EC8: lwz     r11, 784(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(784);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131ECC:
    ctx->pc = 0x80131ECCu;
    // 80131ECC: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80131ED0:
    ctx->pc = 0x80131ED0u;
    // 80131ED0: stw     r30, 780(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(780);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131ED4:
    ctx->pc = 0x80131ED4u;
    // 80131ED4: cmpwi   r11, 0
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

label_80131ED8:
    ctx->pc = 0x80131ED8u;
    // 80131ED8: bc    12, 2, 0x80131EF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131EF8;
        }
    }

label_80131EDC:
    ctx->pc = 0x80131EDCu;
    ctx->downcount -= 8;
    // 80131EDC: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131EE0:
    ctx->pc = 0x80131EE0u;
    // 80131EE0: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80131EE4:
    ctx->pc = 0x80131EE4u;
    // 80131EE4: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131EE8:
    ctx->pc = 0x80131EE8u;
    // 80131EE8: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131EEC:
    ctx->pc = 0x80131EECu;
    // 80131EEC: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131EF0:
    ctx->pc = 0x80131EF0u;
    // 80131EF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131EF4:
    ctx->pc = 0x80131EF4u;
    // 80131EF4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131EF8u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131EF8:
    ctx->pc = 0x80131EF8u;
    ctx->downcount -= 4;
    // 80131EF8: lwz     r11, 788(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(788);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131EFC:
    ctx->pc = 0x80131EFCu;
    // 80131EFC: stw     r30, 784(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(784);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131F00:
    ctx->pc = 0x80131F00u;
    // 80131F00: cmpwi   r11, 0
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

label_80131F04:
    ctx->pc = 0x80131F04u;
    // 80131F04: bc    12, 2, 0x80131F24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131F24;
        }
    }

label_80131F08:
    ctx->pc = 0x80131F08u;
    ctx->downcount -= 8;
    // 80131F08: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131F0C:
    ctx->pc = 0x80131F0Cu;
    // 80131F0C: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80131F10:
    ctx->pc = 0x80131F10u;
    // 80131F10: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131F14:
    ctx->pc = 0x80131F14u;
    // 80131F14: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131F18:
    ctx->pc = 0x80131F18u;
    // 80131F18: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131F1C:
    ctx->pc = 0x80131F1Cu;
    // 80131F1C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131F20:
    ctx->pc = 0x80131F20u;
    // 80131F20: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131F24u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131F24:
    ctx->pc = 0x80131F24u;
    ctx->downcount -= 4;
    // 80131F24: lwz     r11, 792(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131F28:
    ctx->pc = 0x80131F28u;
    // 80131F28: stw     r30, 788(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(788);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131F2C:
    ctx->pc = 0x80131F2Cu;
    // 80131F2C: cmpwi   r11, 0
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

label_80131F30:
    ctx->pc = 0x80131F30u;
    // 80131F30: bc    12, 2, 0x80131F50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131F50;
        }
    }

label_80131F34:
    ctx->pc = 0x80131F34u;
    ctx->downcount -= 8;
    // 80131F34: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131F38:
    ctx->pc = 0x80131F38u;
    // 80131F38: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80131F3C:
    ctx->pc = 0x80131F3Cu;
    // 80131F3C: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131F40:
    ctx->pc = 0x80131F40u;
    // 80131F40: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131F44:
    ctx->pc = 0x80131F44u;
    // 80131F44: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131F48:
    ctx->pc = 0x80131F48u;
    // 80131F48: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131F4C:
    ctx->pc = 0x80131F4Cu;
    // 80131F4C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131F50u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131F50:
    ctx->pc = 0x80131F50u;
    ctx->downcount -= 4;
    // 80131F50: lwz     r11, 796(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(796);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131F54:
    ctx->pc = 0x80131F54u;
    // 80131F54: stw     r30, 792(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(792);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131F58:
    ctx->pc = 0x80131F58u;
    // 80131F58: cmpwi   r11, 0
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

label_80131F5C:
    ctx->pc = 0x80131F5Cu;
    // 80131F5C: bc    12, 2, 0x80131F7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131F7C;
        }
    }

label_80131F60:
    ctx->pc = 0x80131F60u;
    ctx->downcount -= 8;
    // 80131F60: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131F64:
    ctx->pc = 0x80131F64u;
    // 80131F64: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80131F68:
    ctx->pc = 0x80131F68u;
    // 80131F68: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131F6C:
    ctx->pc = 0x80131F6Cu;
    // 80131F6C: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131F70:
    ctx->pc = 0x80131F70u;
    // 80131F70: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131F74:
    ctx->pc = 0x80131F74u;
    // 80131F74: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131F78:
    ctx->pc = 0x80131F78u;
    // 80131F78: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131F7Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131F7C:
    ctx->pc = 0x80131F7Cu;
    ctx->downcount -= 4;
    // 80131F7C: lwz     r11, 800(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(800);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131F80:
    ctx->pc = 0x80131F80u;
    // 80131F80: stw     r30, 796(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(796);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131F84:
    ctx->pc = 0x80131F84u;
    // 80131F84: cmpwi   r11, 0
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

label_80131F88:
    ctx->pc = 0x80131F88u;
    // 80131F88: bc    12, 2, 0x80131FA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131FA8;
        }
    }

label_80131F8C:
    ctx->pc = 0x80131F8Cu;
    ctx->downcount -= 8;
    // 80131F8C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131F90:
    ctx->pc = 0x80131F90u;
    // 80131F90: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80131F94:
    ctx->pc = 0x80131F94u;
    // 80131F94: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131F98:
    ctx->pc = 0x80131F98u;
    // 80131F98: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131F9C:
    ctx->pc = 0x80131F9Cu;
    // 80131F9C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131FA0:
    ctx->pc = 0x80131FA0u;
    // 80131FA0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131FA4:
    ctx->pc = 0x80131FA4u;
    // 80131FA4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131FA8u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131FA8:
    ctx->pc = 0x80131FA8u;
    ctx->downcount -= 4;
    // 80131FA8: lwz     r11, 804(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(804);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131FAC:
    ctx->pc = 0x80131FACu;
    // 80131FAC: stw     r30, 800(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(800);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131FB0:
    ctx->pc = 0x80131FB0u;
    // 80131FB0: cmpwi   r11, 0
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

label_80131FB4:
    ctx->pc = 0x80131FB4u;
    // 80131FB4: bc    12, 2, 0x80131FD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80131FD4;
        }
    }

label_80131FB8:
    ctx->pc = 0x80131FB8u;
    ctx->downcount -= 8;
    // 80131FB8: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80131FBC:
    ctx->pc = 0x80131FBCu;
    // 80131FBC: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80131FC0:
    ctx->pc = 0x80131FC0u;
    // 80131FC0: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80131FC4:
    ctx->pc = 0x80131FC4u;
    // 80131FC4: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131FC8:
    ctx->pc = 0x80131FC8u;
    // 80131FC8: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80131FCC:
    ctx->pc = 0x80131FCCu;
    // 80131FCC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80131FD0:
    ctx->pc = 0x80131FD0u;
    // 80131FD0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80131FD4u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80131FD4:
    ctx->pc = 0x80131FD4u;
    ctx->downcount -= 9;
    // 80131FD4: stw     r30, 804(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(804);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80131FD8:
    ctx->pc = 0x80131FD8u;
    // 80131FD8: addi    r9, r31, 808
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(808);

label_80131FDC:
    ctx->pc = 0x80131FDCu;
    // 80131FDC: lwz     r11, 808(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(808);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80131FE0:
    ctx->pc = 0x80131FE0u;
    // 80131FE0: or   r28, r9, r9
    {
        ctx->gpr[28] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80131FE4:
    ctx->pc = 0x80131FE4u;
    // 80131FE4: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80131FE8:
    ctx->pc = 0x80131FE8u;
    // 80131FE8: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80131FEC:
    ctx->pc = 0x80131FECu;
    // 80131FEC: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80131FF0:
    ctx->pc = 0x80131FF0u;
    // 80131FF0: rlwinm. r9, r0, 30, 2, 31
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

label_80131FF4:
    ctx->pc = 0x80131FF4u;
    // 80131FF4: bc    12, 2, 0x80132054
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132054;
        }
    }

label_80131FF8:
    ctx->pc = 0x80131FF8u;
    ctx->downcount -= 2;
    // 80131FF8: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_80131FFC:
    ctx->pc = 0x80131FFCu;
    // 80131FFC: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80132000:
    ctx->pc = 0x80132000u;
    ctx->downcount -= 4;
    // 80132000: lwz     r9, 808(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132004:
    ctx->pc = 0x80132004u;
    // 80132004: lwzx    r11, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132008:
    // 80132008: cmpwi   r11, 0
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

label_8013200C:
    // 8013200C: bc    12, 2, 0x8013202C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013202C;
        }
    }

label_80132010:
    ctx->pc = 0x80132010u;
    ctx->downcount -= 8;
    // 80132010: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132014:
    // 80132014: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80132018:
    ctx->pc = 0x80132018u;
    // 80132018: lha     r3, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8013201C:
    ctx->pc = 0x8013201Cu;
    // 8013201C: lwz     r0, 100(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132020:
    // 80132020: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132024:
    ctx->pc = 0x80132024u;
    // 80132024: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132028:
    ctx->pc = 0x80132028u;
    // 80132028: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013202Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013202C:
    ctx->pc = 0x8013202Cu;
    ctx->downcount -= 10;
    // 8013202C: lwz     r9, 808(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132030:
    // 80132030: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_80132034:
    ctx->pc = 0x80132034u;
    // 80132034: stwx    r27, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_80132038:
    // 80132038: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_8013203C:
    ctx->pc = 0x8013203Cu;
    // 8013203C: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132040:
    ctx->pc = 0x80132040u;
    // 80132040: lwz     r9, 808(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132044:
    // 80132044: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80132048:
    // 80132048: srawi r0, r0, 2
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

label_8013204C:
    // 8013204C: cmplw   r29, r0
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

label_80132050:
    // 80132050: bc    12, 0, 0x80132000
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80132000u;
                return;
            }
            goto label_80132000;
        }
    }

label_80132054:
    ctx->pc = 0x80132054u;
    ctx->downcount -= 3;
    // 80132054: lwz     r11, 824(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(824);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132058:
    ctx->pc = 0x80132058u;
    // 80132058: cmpwi   r11, 0
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

label_8013205C:
    ctx->pc = 0x8013205Cu;
    // 8013205C: bc    12, 2, 0x8013207C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013207C;
        }
    }

label_80132060:
    ctx->pc = 0x80132060u;
    ctx->downcount -= 8;
    // 80132060: lwz     r9, 28(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132064:
    ctx->pc = 0x80132064u;
    // 80132064: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80132068:
    ctx->pc = 0x80132068u;
    // 80132068: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8013206C:
    ctx->pc = 0x8013206Cu;
    // 8013206C: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132070:
    ctx->pc = 0x80132070u;
    // 80132070: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132074:
    ctx->pc = 0x80132074u;
    // 80132074: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132078:
    ctx->pc = 0x80132078u;
    // 80132078: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013207Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013207C:
    ctx->pc = 0x8013207Cu;
    ctx->downcount -= 11;
    // 8013207C: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80132080:
    ctx->pc = 0x80132080u;
    // 80132080: lwz     r3, 868(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(868);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80132084:
    ctx->pc = 0x80132084u;
    // 80132084: stw     r30, 824(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(824);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80132088:
    ctx->pc = 0x80132088u;
    // 80132088: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8013208C:
    ctx->pc = 0x8013208Cu;
    // 8013208C: lwz     r9, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132090:
    ctx->pc = 0x80132090u;
    // 80132090: lha     r0, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80132094:
    ctx->pc = 0x80132094u;
    // 80132094: lwz     r9, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132098:
    ctx->pc = 0x80132098u;
    // 80132098: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8013209C:
    ctx->pc = 0x8013209Cu;
    // 8013209C: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801320A0:
    ctx->pc = 0x801320A0u;
    // 801320A0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801320A4u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801320A4:
    ctx->pc = 0x801320A4u;
    ctx->downcount -= 3;
    // 801320A4: lwz     r3, 868(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(868);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801320A8:
    ctx->pc = 0x801320A8u;
    // 801320A8: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_801320AC:
    ctx->pc = 0x801320ACu;
    // 801320AC: bl      0x802069DC
    {
            ctx->lr = 0x801320B0u;
            ctx->pc = 0x802069DCu;
            return;
    }

label_801320B0:
    ctx->pc = 0x801320B0u;
    ctx->downcount -= 3;
    // 801320B0: lwz     r11, 868(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(868);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801320B4:
    ctx->pc = 0x801320B4u;
    // 801320B4: cmpwi   r11, 0
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

label_801320B8:
    ctx->pc = 0x801320B8u;
    // 801320B8: bc    12, 2, 0x801320DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801320DC;
        }
    }

label_801320BC:
    ctx->pc = 0x801320BCu;
    ctx->downcount -= 9;
    // 801320BC: lwz     r9, 108(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801320C0:
    ctx->pc = 0x801320C0u;
    // 801320C0: addi    r0, r11, 88
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(88);

label_801320C4:
    ctx->pc = 0x801320C4u;
    // 801320C4: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_801320C8:
    ctx->pc = 0x801320C8u;
    // 801320C8: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801320CC:
    ctx->pc = 0x801320CCu;
    // 801320CC: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801320D0:
    ctx->pc = 0x801320D0u;
    // 801320D0: add   r3, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801320D4:
    ctx->pc = 0x801320D4u;
    // 801320D4: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_801320D8:
    ctx->pc = 0x801320D8u;
    // 801320D8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801320DCu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801320DC:
    ctx->pc = 0x801320DCu;
    ctx->downcount -= 3;
    // 801320DC: stw     r30, 868(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(868);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801320E0:
    ctx->pc = 0x801320E0u;
    // 801320E0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801320E4:
    ctx->pc = 0x801320E4u;
    // 801320E4: bl      0x80133BD8
    {
            ctx->lr = 0x801320E8u;
            ctx->pc = 0x80133BD8u;
            return;
    }

label_801320E8:
    ctx->pc = 0x801320E8u;
    ctx->downcount -= 2;
    // 801320E8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801320EC:
    ctx->pc = 0x801320ECu;
    // 801320EC: bl      0x80134770
    {
            ctx->lr = 0x801320F0u;
            ctx->pc = 0x80134770u;
            return;
    }

label_801320F0:
    ctx->pc = 0x801320F0u;
    ctx->downcount -= 16;
    // 801320F0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801320F4:
    ctx->pc = 0x801320F4u;
    // 801320F4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801320F8:
    ctx->pc = 0x801320F8u;
    // 801320F8: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801320FC:
    ctx->pc = 0x801320FCu;
    // 801320FC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80132100:
    ctx->pc = 0x80132100u;
    // 80132100: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80132104:
    ctx->pc = 0x80132104u;
    ctx->downcount -= 19;
    // 80132104: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80132108:
    ctx->pc = 0x80132108u;
    // 80132108: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8013210C:
    ctx->pc = 0x8013210Cu;
    // 8013210C: stmw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80132110:
    ctx->pc = 0x80132110u;
    // 80132110: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132114:
    ctx->pc = 0x80132114u;
    // 80132114: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132118:
    ctx->pc = 0x80132118u;
    // 80132118: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8013211C:
    ctx->pc = 0x8013211Cu;
    // 8013211C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80132120:
    ctx->pc = 0x80132120u;
    // 80132120: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132124:
    ctx->pc = 0x80132124u;
    // 80132124: bl      0x8015E4F4
    {
            ctx->lr = 0x80132128u;
            ctx->pc = 0x8015E4F4u;
            return;
    }

label_80132128:
    ctx->pc = 0x80132128u;
    ctx->downcount -= 3;
    // 80132128: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013212C:
    ctx->pc = 0x8013212Cu;
    // 8013212C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132130:
    ctx->pc = 0x80132130u;
    // 80132130: bl      0x80133D04
    {
            ctx->lr = 0x80132134u;
            ctx->pc = 0x80133D04u;
            return;
    }

label_80132134:
    ctx->pc = 0x80132134u;
    ctx->downcount -= 2;
    // 80132134: or.   r3, r3, r3
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

label_80132138:
    ctx->pc = 0x80132138u;
    // 80132138: bc    4, 2, 0x80132218
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132218;
        }
    }

label_8013213C:
    ctx->pc = 0x8013213Cu;
    ctx->downcount -= 2;
    // 8013213C: cmpwi   r30, 1
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132140:
    ctx->pc = 0x80132140u;
    // 80132140: bc    12, 2, 0x80132150
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132150;
        }
    }

label_80132144:
    ctx->pc = 0x80132144u;
    ctx->downcount -= 2;
    // 80132144: cmpwi   r30, 2
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132148:
    ctx->pc = 0x80132148u;
    // 80132148: bc    12, 2, 0x801321B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801321B4;
        }
    }

label_8013214C:
    ctx->pc = 0x8013214Cu;
    ctx->downcount -= 1;
    // 8013214C: b       0x80132218
    {
            goto label_80132218;
    }

label_80132150:
    ctx->pc = 0x80132150u;
    ctx->downcount -= 3;
    // 80132150: lwz     r0, 732(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(732);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132154:
    ctx->pc = 0x80132154u;
    // 80132154: cmpwi   r0, 0
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

label_80132158:
    ctx->pc = 0x80132158u;
    // 80132158: bc    4, 2, 0x80132164
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132164;
        }
    }

label_8013215C:
    ctx->pc = 0x8013215Cu;
    ctx->downcount -= 2;
    // 8013215C: stw     r30, 732(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80132160:
    ctx->pc = 0x80132160u;
    // 80132160: b       0x80132168
    {
            goto label_80132168;
    }

label_80132164:
    ctx->pc = 0x80132164u;
    ctx->downcount -= 1;
    // 80132164: stw     r3, 732(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80132168:
    ctx->pc = 0x80132168u;
    ctx->downcount -= 2;
    // 80132168: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8013216C:
    ctx->pc = 0x8013216Cu;
    // 8013216C: bl      0x80134858
    {
            ctx->lr = 0x80132170u;
            ctx->pc = 0x80134858u;
            return;
    }

label_80132170:
    ctx->pc = 0x80132170u;
    ctx->downcount -= 4;
    // 80132170: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80132174:
    ctx->pc = 0x80132174u;
    // 80132174: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80132178:
    ctx->pc = 0x80132178u;
    // 80132178: addi    r3, r3, 18772
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(18772);

label_8013217C:
    ctx->pc = 0x8013217Cu;
    // 8013217C: bl      0x800994E4
    {
            ctx->lr = 0x80132180u;
            ctx->pc = 0x800994E4u;
            return;
    }

label_80132180:
    ctx->pc = 0x80132180u;
    ctx->downcount -= 2;
    // 80132180: or.   r3, r3, r3
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

label_80132184:
    ctx->pc = 0x80132184u;
    // 80132184: bc    12, 2, 0x80132218
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132218;
        }
    }

label_80132188:
    ctx->pc = 0x80132188u;
    ctx->downcount -= 10;
    // 80132188: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8013218C:
    ctx->pc = 0x8013218Cu;
    // 8013218C: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_80132190:
    ctx->pc = 0x80132190u;
    // 80132190: lfs     f0, 18792(r9)
    if (!ppc_fp_available_inline(ctx, 0x80132190u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18792);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80132194:
    ctx->pc = 0x80132194u;
    // 80132194: or   r6, r11, r11
    {
        ctx->gpr[6] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80132198:
    ctx->pc = 0x80132198u;
    // 80132198: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8013219C:
    ctx->pc = 0x8013219Cu;
    // 8013219C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801321A0:
    ctx->pc = 0x801321A0u;
    // 801321A0: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801321A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801321A4:
    ctx->pc = 0x801321A4u;
    // 801321A4: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x801321A4u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801321A8:
    ctx->pc = 0x801321A8u;
    // 801321A8: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x801321A8u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801321AC:
    ctx->pc = 0x801321ACu;
    // 801321AC: bl      0x8021B838
    {
            ctx->lr = 0x801321B0u;
            ctx->pc = 0x8021B838u;
            return;
    }

label_801321B0:
    ctx->pc = 0x801321B0u;
    ctx->downcount -= 1;
    // 801321B0: b       0x80132218
    {
            goto label_80132218;
    }

label_801321B4:
    ctx->pc = 0x801321B4u;
    ctx->downcount -= 10;
    // 801321B4: li      r0, 24
    ctx->gpr[0] = (u32)(s32)(24);

label_801321B8:
    ctx->pc = 0x801321B8u;
    // 801321B8: lwz     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801321BC:
    ctx->pc = 0x801321BCu;
    // 801321BC: stw     r0, 388(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(388);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801321C0:
    ctx->pc = 0x801321C0u;
    // 801321C0: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_801321C4:
    ctx->pc = 0x801321C4u;
    // 801321C4: lha     r3, 192(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(192);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801321C8:
    ctx->pc = 0x801321C8u;
    // 801321C8: lwz     r0, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801321CC:
    ctx->pc = 0x801321CCu;
    // 801321CC: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801321D0:
    ctx->pc = 0x801321D0u;
    // 801321D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801321D4:
    ctx->pc = 0x801321D4u;
    // 801321D4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801321D8u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801321D8:
    ctx->pc = 0x801321D8u;
    ctx->downcount -= 4;
    // 801321D8: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801321DC:
    ctx->pc = 0x801321DCu;
    // 801321DC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801321E0:
    ctx->pc = 0x801321E0u;
    // 801321E0: addi    r3, r3, 18772
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(18772);

label_801321E4:
    ctx->pc = 0x801321E4u;
    // 801321E4: bl      0x800994E4
    {
            ctx->lr = 0x801321E8u;
            ctx->pc = 0x800994E4u;
            return;
    }

label_801321E8:
    ctx->pc = 0x801321E8u;
    ctx->downcount -= 2;
    // 801321E8: or.   r3, r3, r3
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

label_801321EC:
    ctx->pc = 0x801321ECu;
    // 801321EC: bc    12, 2, 0x80132218
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132218;
        }
    }

label_801321F0:
    ctx->pc = 0x801321F0u;
    ctx->downcount -= 10;
    // 801321F0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801321F4:
    ctx->pc = 0x801321F4u;
    // 801321F4: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_801321F8:
    ctx->pc = 0x801321F8u;
    // 801321F8: lfs     f0, 18792(r9)
    if (!ppc_fp_available_inline(ctx, 0x801321F8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18792);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801321FC:
    ctx->pc = 0x801321FCu;
    // 801321FC: or   r6, r11, r11
    {
        ctx->gpr[6] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80132200:
    ctx->pc = 0x80132200u;
    // 80132200: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80132204:
    ctx->pc = 0x80132204u;
    // 80132204: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132208:
    ctx->pc = 0x80132208u;
    // 80132208: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x80132208u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8013220C:
    ctx->pc = 0x8013220Cu;
    // 8013220C: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x8013220Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80132210:
    ctx->pc = 0x80132210u;
    // 80132210: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x80132210u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80132214:
    ctx->pc = 0x80132214u;
    // 80132214: bl      0x8021B838
    {
            ctx->lr = 0x80132218u;
            ctx->pc = 0x8021B838u;
            return;
    }

label_80132218:
    ctx->pc = 0x80132218u;
    ctx->downcount -= 17;
    // 80132218: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013221C:
    ctx->pc = 0x8013221Cu;
    // 8013221C: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132220:
    ctx->pc = 0x80132220u;
    // 80132220: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132224:
    ctx->pc = 0x80132224u;
    // 80132224: lmw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80132228:
    ctx->pc = 0x80132228u;
    // 80132228: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8013222C:
    ctx->pc = 0x8013222Cu;
    // 8013222C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80132230:
    ctx->pc = 0x80132230u;
    ctx->downcount -= 17;
    // 80132230: stwu     r1, -408(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-408);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80132234:
    ctx->pc = 0x80132234u;
    // 80132234: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80132238:
    ctx->pc = 0x80132238u;
    // 80132238: stmw     r26, 384(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(384);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8013223C:
    ctx->pc = 0x8013223Cu;
    // 8013223C: stw     r0, 412(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(412);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132240:
    ctx->pc = 0x80132240u;
    // 80132240: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132244:
    ctx->pc = 0x80132244u;
    // 80132244: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80132248:
    ctx->pc = 0x80132248u;
    // 80132248: bl      0x8015E500
    {
            ctx->lr = 0x8013224Cu;
            ctx->pc = 0x8015E500u;
            return;
    }

label_8013224C:
    ctx->pc = 0x8013224Cu;
    ctx->downcount -= 3;
    // 8013224C: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132250:
    ctx->pc = 0x80132250u;
    // 80132250: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132254:
    ctx->pc = 0x80132254u;
    // 80132254: bl      0x80133D04
    {
            ctx->lr = 0x80132258u;
            ctx->pc = 0x80133D04u;
            return;
    }

label_80132258:
    ctx->pc = 0x80132258u;
    ctx->downcount -= 2;
    // 80132258: cmpwi   r3, 0
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

label_8013225C:
    ctx->pc = 0x8013225Cu;
    // 8013225C: bc    4, 2, 0x80132718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132718;
        }
    }

label_80132260:
    ctx->pc = 0x80132260u;
    ctx->downcount -= 2;
    // 80132260: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132264:
    ctx->pc = 0x80132264u;
    // 80132264: bl      0x80134B70
    {
            ctx->lr = 0x80132268u;
            ctx->pc = 0x80134B70u;
            return;
    }

label_80132268:
    ctx->pc = 0x80132268u;
    ctx->downcount -= 2;
    // 80132268: or.   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8013226C:
    ctx->pc = 0x8013226Cu;
    // 8013226C: bc    4, 2, 0x80132718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132718;
        }
    }

label_80132270:
    ctx->pc = 0x80132270u;
    ctx->downcount -= 2;
    // 80132270: cmpwi   r30, 2
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132274:
    ctx->pc = 0x80132274u;
    // 80132274: bc    12, 2, 0x8013255C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013255C;
        }
    }

label_80132278:
    ctx->pc = 0x80132278u;
    ctx->downcount -= 1;
    // 80132278: bc    12, 1, 0x80132288
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132288;
        }
    }

label_8013227C:
    ctx->pc = 0x8013227Cu;
    ctx->downcount -= 2;
    // 8013227C: cmpwi   r30, 1
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132280:
    ctx->pc = 0x80132280u;
    // 80132280: bc    12, 2, 0x80132398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132398;
        }
    }

label_80132284:
    ctx->pc = 0x80132284u;
    ctx->downcount -= 1;
    // 80132284: b       0x80132718
    {
            goto label_80132718;
    }

label_80132288:
    ctx->pc = 0x80132288u;
    ctx->downcount -= 2;
    // 80132288: cmpwi   r30, 3
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8013228C:
    ctx->pc = 0x8013228Cu;
    // 8013228C: bc    12, 2, 0x8013229C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013229C;
        }
    }

label_80132290:
    ctx->pc = 0x80132290u;
    ctx->downcount -= 2;
    // 80132290: cmpwi   r30, 4
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132294:
    ctx->pc = 0x80132294u;
    // 80132294: bc    12, 2, 0x801322C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801322C4;
        }
    }

label_80132298:
    ctx->pc = 0x80132298u;
    ctx->downcount -= 1;
    // 80132298: b       0x80132718
    {
            goto label_80132718;
    }

label_8013229C:
    ctx->pc = 0x8013229Cu;
    ctx->downcount -= 2;
    // 8013229C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801322A0:
    ctx->pc = 0x801322A0u;
    // 801322A0: bl      0x80134A34
    {
            ctx->lr = 0x801322A4u;
            ctx->pc = 0x80134A34u;
            return;
    }

label_801322A4:
    ctx->pc = 0x801322A4u;
    ctx->downcount -= 2;
    // 801322A4: cmpwi   r3, 0
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

label_801322A8:
    ctx->pc = 0x801322A8u;
    // 801322A8: bc    4, 2, 0x80132718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132718;
        }
    }

label_801322AC:
    ctx->pc = 0x801322ACu;
    ctx->downcount -= 3;
    // 801322AC: lwz     r9, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801322B0:
    ctx->pc = 0x801322B0u;
    // 801322B0: cmpwi   r9, 0
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

label_801322B4:
    ctx->pc = 0x801322B4u;
    // 801322B4: bc    4, 1, 0x80132354
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132354;
        }
    }

label_801322B8:
    ctx->pc = 0x801322B8u;
    ctx->downcount -= 3;
    // 801322B8: addi    r0, r9, -1
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(-1);

label_801322BC:
    ctx->pc = 0x801322BCu;
    // 801322BC: lwz     r11, 792(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801322C0:
    ctx->pc = 0x801322C0u;
    // 801322C0: b       0x801322E8
    {
            goto label_801322E8;
    }

label_801322C4:
    ctx->pc = 0x801322C4u;
    ctx->downcount -= 2;
    // 801322C4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801322C8:
    ctx->pc = 0x801322C8u;
    // 801322C8: bl      0x80134A34
    {
            ctx->lr = 0x801322CCu;
            ctx->pc = 0x80134A34u;
            return;
    }

label_801322CC:
    ctx->pc = 0x801322CCu;
    ctx->downcount -= 2;
    // 801322CC: cmpwi   r3, 0
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

label_801322D0:
    ctx->pc = 0x801322D0u;
    // 801322D0: bc    4, 2, 0x80132718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132718;
        }
    }

label_801322D4:
    ctx->pc = 0x801322D4u;
    ctx->downcount -= 3;
    // 801322D4: lwz     r9, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801322D8:
    ctx->pc = 0x801322D8u;
    // 801322D8: cmpwi   r9, 1
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

label_801322DC:
    ctx->pc = 0x801322DCu;
    // 801322DC: bc    12, 1, 0x80132354
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132354;
        }
    }

label_801322E0:
    ctx->pc = 0x801322E0u;
    ctx->downcount -= 2;
    // 801322E0: addi    r0, r9, 1
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(1);

label_801322E4:
    ctx->pc = 0x801322E4u;
    // 801322E4: lwz     r11, 796(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(796);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801322E8:
    ctx->pc = 0x801322E8u;
    ctx->downcount -= 9;
    // 801322E8: stw     r0, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801322EC:
    ctx->pc = 0x801322ECu;
    // 801322EC: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_801322F0:
    ctx->pc = 0x801322F0u;
    // 801322F0: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801322F4:
    ctx->pc = 0x801322F4u;
    // 801322F4: lha     r3, 176(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(176);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801322F8:
    ctx->pc = 0x801322F8u;
    // 801322F8: lwz     r0, 180(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(180);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801322FC:
    ctx->pc = 0x801322FCu;
    // 801322FC: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132300:
    ctx->pc = 0x80132300u;
    // 80132300: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132304:
    ctx->pc = 0x80132304u;
    // 80132304: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80132308u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80132308:
    ctx->pc = 0x80132308u;
    ctx->downcount -= 4;
    // 80132308: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_8013230C:
    ctx->pc = 0x8013230Cu;
    // 8013230C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80132310:
    ctx->pc = 0x80132310u;
    // 80132310: addi    r3, r3, 18796
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(18796);

label_80132314:
    ctx->pc = 0x80132314u;
    // 80132314: bl      0x800994E4
    {
            ctx->lr = 0x80132318u;
            ctx->pc = 0x800994E4u;
            return;
    }

label_80132318:
    ctx->pc = 0x80132318u;
    ctx->downcount -= 2;
    // 80132318: or.   r3, r3, r3
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

label_8013231C:
    ctx->pc = 0x8013231Cu;
    // 8013231C: bc    12, 2, 0x80132348
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132348;
        }
    }

label_80132320:
    ctx->pc = 0x80132320u;
    ctx->downcount -= 10;
    // 80132320: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80132324:
    ctx->pc = 0x80132324u;
    // 80132324: addi    r11, r1, 16
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(16);

label_80132328:
    ctx->pc = 0x80132328u;
    // 80132328: lfs     f0, 18868(r9)
    if (!ppc_fp_available_inline(ctx, 0x80132328u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18868);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8013232C:
    ctx->pc = 0x8013232Cu;
    // 8013232C: or   r6, r11, r11
    {
        ctx->gpr[6] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80132330:
    ctx->pc = 0x80132330u;
    // 80132330: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80132334:
    ctx->pc = 0x80132334u;
    // 80132334: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132338:
    ctx->pc = 0x80132338u;
    // 80132338: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80132338u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8013233C:
    ctx->pc = 0x8013233Cu;
    // 8013233C: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x8013233Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80132340:
    ctx->pc = 0x80132340u;
    // 80132340: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x80132340u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80132344:
    ctx->pc = 0x80132344u;
    // 80132344: bl      0x8021B838
    {
            ctx->lr = 0x80132348u;
            ctx->pc = 0x8021B838u;
            return;
    }

label_80132348:
    ctx->pc = 0x80132348u;
    ctx->downcount -= 2;
    // 80132348: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8013234C:
    ctx->pc = 0x8013234Cu;
    // 8013234C: bl      0x80134858
    {
            ctx->lr = 0x80132350u;
            ctx->pc = 0x80134858u;
            return;
    }

label_80132350:
    ctx->pc = 0x80132350u;
    ctx->downcount -= 1;
    // 80132350: b       0x80132718
    {
            goto label_80132718;
    }

label_80132354:
    ctx->pc = 0x80132354u;
    ctx->downcount -= 4;
    // 80132354: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80132358:
    ctx->pc = 0x80132358u;
    // 80132358: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8013235C:
    ctx->pc = 0x8013235Cu;
    // 8013235C: addi    r3, r3, 18816
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(18816);

label_80132360:
    ctx->pc = 0x80132360u;
    // 80132360: bl      0x800994E4
    {
            ctx->lr = 0x80132364u;
            ctx->pc = 0x800994E4u;
            return;
    }

label_80132364:
    ctx->pc = 0x80132364u;
    ctx->downcount -= 2;
    // 80132364: or.   r3, r3, r3
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

label_80132368:
    ctx->pc = 0x80132368u;
    // 80132368: bc    12, 2, 0x80132718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132718;
        }
    }

label_8013236C:
    ctx->pc = 0x8013236Cu;
    ctx->downcount -= 10;
    // 8013236C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80132370:
    ctx->pc = 0x80132370u;
    // 80132370: addi    r11, r1, 16
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(16);

label_80132374:
    ctx->pc = 0x80132374u;
    // 80132374: lfs     f0, 18868(r9)
    if (!ppc_fp_available_inline(ctx, 0x80132374u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18868);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80132378:
    ctx->pc = 0x80132378u;
    // 80132378: or   r6, r11, r11
    {
        ctx->gpr[6] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8013237C:
    ctx->pc = 0x8013237Cu;
    // 8013237C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80132380:
    ctx->pc = 0x80132380u;
    // 80132380: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132384:
    ctx->pc = 0x80132384u;
    // 80132384: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80132384u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80132388:
    ctx->pc = 0x80132388u;
    // 80132388: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x80132388u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8013238C:
    ctx->pc = 0x8013238Cu;
    // 8013238C: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x8013238Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80132390:
    ctx->pc = 0x80132390u;
    // 80132390: bl      0x8021B838
    {
            ctx->lr = 0x80132394u;
            ctx->pc = 0x8021B838u;
            return;
    }

label_80132394:
    ctx->pc = 0x80132394u;
    ctx->downcount -= 1;
    // 80132394: b       0x80132718
    {
            goto label_80132718;
    }

label_80132398:
    ctx->pc = 0x80132398u;
    ctx->downcount -= 10;
    // 80132398: lwz     r11, 784(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(784);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8013239C:
    ctx->pc = 0x8013239Cu;
    // 8013239C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801323A0:
    ctx->pc = 0x801323A0u;
    // 801323A0: addi    r30, r1, 16
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(16);

label_801323A4:
    ctx->pc = 0x801323A4u;
    // 801323A4: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801323A8:
    ctx->pc = 0x801323A8u;
    // 801323A8: lha     r3, 176(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(176);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801323AC:
    ctx->pc = 0x801323ACu;
    // 801323AC: lwz     r0, 180(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(180);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801323B0:
    ctx->pc = 0x801323B0u;
    // 801323B0: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801323B4:
    ctx->pc = 0x801323B4u;
    // 801323B4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801323B8:
    ctx->pc = 0x801323B8u;
    // 801323B8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801323BCu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801323BC:
    ctx->pc = 0x801323BCu;
    ctx->downcount -= 4;
    // 801323BC: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801323C0:
    ctx->pc = 0x801323C0u;
    // 801323C0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801323C4:
    ctx->pc = 0x801323C4u;
    // 801323C4: addi    r3, r3, 18796
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(18796);

label_801323C8:
    ctx->pc = 0x801323C8u;
    // 801323C8: bl      0x800994E4
    {
            ctx->lr = 0x801323CCu;
            ctx->pc = 0x800994E4u;
            return;
    }

label_801323CC:
    ctx->pc = 0x801323CCu;
    ctx->downcount -= 3;
    // 801323CC: or.   r3, r3, r3
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

label_801323D0:
    ctx->pc = 0x801323D0u;
    // 801323D0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801323D4:
    ctx->pc = 0x801323D4u;
    // 801323D4: bc    12, 2, 0x801323F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801323F8;
        }
    }

label_801323D8:
    ctx->pc = 0x801323D8u;
    ctx->downcount -= 8;
    // 801323D8: lfs     f0, 18868(r9)
    if (!ppc_fp_available_inline(ctx, 0x801323D8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18868);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801323DC:
    ctx->pc = 0x801323DCu;
    // 801323DC: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801323E0:
    ctx->pc = 0x801323E0u;
    // 801323E0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801323E4:
    ctx->pc = 0x801323E4u;
    // 801323E4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801323E8:
    ctx->pc = 0x801323E8u;
    // 801323E8: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x801323E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801323EC:
    ctx->pc = 0x801323ECu;
    // 801323EC: stfs     f0, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x801323ECu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801323F0:
    ctx->pc = 0x801323F0u;
    // 801323F0: stfs     f0, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x801323F0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801323F4:
    ctx->pc = 0x801323F4u;
    // 801323F4: bl      0x8021B838
    {
            ctx->lr = 0x801323F8u;
            ctx->pc = 0x8021B838u;
            return;
    }

label_801323F8:
    ctx->pc = 0x801323F8u;
    ctx->downcount -= 3;
    // 801323F8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801323FC:
    ctx->pc = 0x801323FCu;
    // 801323FC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132400:
    ctx->pc = 0x80132400u;
    // 80132400: bl      0x80132940
    {
            ctx->lr = 0x80132404u;
            goto label_80132940;
    }

label_80132404:
    ctx->pc = 0x80132404u;
    ctx->downcount -= 4;
    // 80132404: addi    r27, r1, 32
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(32);

label_80132408:
    ctx->pc = 0x80132408u;
    // 80132408: addi    r28, r1, 96
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(96);

label_8013240C:
    ctx->pc = 0x8013240Cu;
    // 8013240C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132410:
    ctx->pc = 0x80132410u;
    // 80132410: bl      0x80132BA8
    {
            ctx->lr = 0x80132414u;
            goto label_80132BA8;
    }

label_80132414:
    ctx->pc = 0x80132414u;
    ctx->downcount -= 10;
    // 80132414: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80132418:
    ctx->pc = 0x80132418u;
    // 80132418: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_8013241C:
    ctx->pc = 0x8013241Cu;
    // 8013241C: lfs     f13, 18872(r9)
    if (!ppc_fp_available_inline(ctx, 0x8013241Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18872);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80132420:
    ctx->pc = 0x80132420u;
    // 80132420: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132424:
    ctx->pc = 0x80132424u;
    // 80132424: lfs     f0, 18868(r11)
    if (!ppc_fp_available_inline(ctx, 0x80132424u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(18868);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80132428:
    ctx->pc = 0x80132428u;
    // 80132428: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8013242C:
    ctx->pc = 0x8013242Cu;
    // 8013242C: stfs     f13, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8013242Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80132430:
    ctx->pc = 0x80132430u;
    // 80132430: stfs     f0, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80132430u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80132434:
    ctx->pc = 0x80132434u;
    // 80132434: stfs     f0, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80132434u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80132438:
    ctx->pc = 0x80132438u;
    // 80132438: bl      0x8028B494
    {
            ctx->lr = 0x8013243Cu;
            ctx->pc = 0x8028B494u;
            return;
    }

label_8013243C:
    ctx->pc = 0x8013243Cu;
    ctx->downcount -= 7;
    // 8013243C: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132440:
    ctx->pc = 0x80132440u;
    // 80132440: addi    r3, r1, 376
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(376);

label_80132444:
    ctx->pc = 0x80132444u;
    // 80132444: lwz     r5, 320(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80132448:
    ctx->pc = 0x80132448u;
    // 80132448: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013244C:
    ctx->pc = 0x8013244Cu;
    // 8013244C: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80132450:
    ctx->pc = 0x80132450u;
    // 80132450: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132454:
    ctx->pc = 0x80132454u;
    // 80132454: bl      0x801CF88C
    {
            ctx->lr = 0x80132458u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80132458:
    ctx->pc = 0x80132458u;
    ctx->downcount -= 7;
    // 80132458: lhz     r9, 376(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(376);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_8013245C:
    ctx->pc = 0x8013245Cu;
    // 8013245C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80132460:
    ctx->pc = 0x80132460u;
    // 80132460: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_80132464:
    ctx->pc = 0x80132464u;
    // 80132464: stw     r28, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80132468:
    ctx->pc = 0x80132468u;
    // 80132468: cmpw    r9, r0
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

label_8013246C:
    ctx->pc = 0x8013246Cu;
    // 8013246C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80132470:
    ctx->pc = 0x80132470u;
    // 80132470: bc    4, 2, 0x80132478
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132478;
        }
    }

label_80132474:
    ctx->pc = 0x80132474u;
    ctx->downcount -= 1;
    // 80132474: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80132478:
    ctx->pc = 0x80132478u;
    ctx->downcount -= 2;
    // 80132478: cmpwi   r0, 0
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

label_8013247C:
    ctx->pc = 0x8013247Cu;
    // 8013247C: bc    12, 2, 0x8013248C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013248C;
        }
    }

label_80132480:
    ctx->pc = 0x80132480u;
    ctx->downcount -= 3;
    // 80132480: addi    r0, r1, 98
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(98);

label_80132484:
    ctx->pc = 0x80132484u;
    // 80132484: sth     r9, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80132488:
    ctx->pc = 0x80132488u;
    // 80132488: stw     r0, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013248C:
    ctx->pc = 0x8013248Cu;
    ctx->downcount -= 5;
    // 8013248C: stb     r29, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write8(ctx, ea, (u8)ctx->gpr[29]);
    }

label_80132490:
    ctx->pc = 0x80132490u;
    // 80132490: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80132494:
    ctx->pc = 0x80132494u;
    // 80132494: addi    r29, r1, 112
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(112);

label_80132498:
    ctx->pc = 0x80132498u;
    // 80132498: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_8013249C:
    ctx->pc = 0x8013249Cu;
    // 8013249C: bl      0x80100A40
    {
            ctx->lr = 0x801324A0u;
            ctx->pc = 0x80100A40u;
            return;
    }

label_801324A0:
    ctx->pc = 0x801324A0u;
    ctx->downcount -= 3;
    // 801324A0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801324A4:
    ctx->pc = 0x801324A4u;
    // 801324A4: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_801324A8:
    ctx->pc = 0x801324A8u;
    // 801324A8: bl      0x80100368
    {
            ctx->lr = 0x801324ACu;
            ctx->pc = 0x80100368u;
            return;
    }

label_801324AC:
    ctx->pc = 0x801324ACu;
    ctx->downcount -= 6;
    // 801324AC: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801324B0:
    ctx->pc = 0x801324B0u;
    // 801324B0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801324B4:
    ctx->pc = 0x801324B4u;
    // 801324B4: addi    r4, r4, 18836
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18836);

label_801324B8:
    ctx->pc = 0x801324B8u;
    // 801324B8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801324BC:
    ctx->pc = 0x801324BCu;
    // 801324BC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801324C0:
    ctx->pc = 0x801324C0u;
    // 801324C0: bl      0x8009258C
    {
            ctx->lr = 0x801324C4u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_801324C4:
    ctx->pc = 0x801324C4u;
    ctx->downcount -= 3;
    // 801324C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801324C8:
    ctx->pc = 0x801324C8u;
    // 801324C8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801324CC:
    ctx->pc = 0x801324CCu;
    // 801324CC: bl      0x80098CD0
    {
            ctx->lr = 0x801324D0u;
            ctx->pc = 0x80098CD0u;
            return;
    }

label_801324D0:
    ctx->pc = 0x801324D0u;
    ctx->downcount -= 11;
    // 801324D0: lwz     r10, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801324D4:
    ctx->pc = 0x801324D4u;
    // 801324D4: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801324D8:
    ctx->pc = 0x801324D8u;
    // 801324D8: li      r0, 9
    ctx->gpr[0] = (u32)(s32)(9);

label_801324DC:
    ctx->pc = 0x801324DCu;
    // 801324DC: or   r9, r27, r27
    {
        ctx->gpr[9] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801324E0:
    ctx->pc = 0x801324E0u;
    // 801324E0: addi    r3, r31, 856
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(856);

label_801324E4:
    ctx->pc = 0x801324E4u;
    // 801324E4: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801324E8:
    ctx->pc = 0x801324E8u;
    // 801324E8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801324EC:
    ctx->pc = 0x801324ECu;
    // 801324EC: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801324F0:
    ctx->pc = 0x801324F0u;
    // 801324F0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_801324F4:
    ctx->pc = 0x801324F4u;
    // 801324F4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801324F8:
    ctx->pc = 0x801324F8u;
    // 801324F8: bl      0x801D2C4C
    {
            ctx->lr = 0x801324FCu;
            ctx->pc = 0x801D2C4Cu;
            return;
    }

label_801324FC:
    ctx->pc = 0x801324FCu;
    ctx->downcount -= 4;
    // 801324FC: lwz     r11, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132500:
    ctx->pc = 0x80132500u;
    // 80132500: or   r9, r28, r28
    {
        ctx->gpr[9] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132504:
    ctx->pc = 0x80132504u;
    // 80132504: cmpw    r28, r11
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132508:
    ctx->pc = 0x80132508u;
    // 80132508: bc    12, 2, 0x80132518
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132518;
        }
    }

label_8013250C:
    loop_8013250C(ctx);
    if (ctx->pc == 0x80132518u) goto label_80132518;
    return;
label_80132510:
    // 80132510: cmpw    r9, r11
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132514:
    // 80132514: bc    4, 2, 0x8013250C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8013250Cu;
                return;
            }
            goto label_8013250C;
        }
    }

label_80132518:
    ctx->pc = 0x80132518u;
    ctx->downcount -= 7;
    // 80132518: lwz     r0, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013251C:
    ctx->pc = 0x8013251Cu;
    // 8013251C: or   r9, r11, r11
    {
        ctx->gpr[9] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80132520:
    ctx->pc = 0x80132520u;
    // 80132520: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132524:
    ctx->pc = 0x80132524u;
    // 80132524: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80132528:
    ctx->pc = 0x80132528u;
    // 80132528: subf   r10, r6, r9
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_8013252C:
    ctx->pc = 0x8013252Cu;
    // 8013252C: srawi. r11, r0, 1
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

label_80132530:
    ctx->pc = 0x80132530u;
    // 80132530: bc    4, 1, 0x8013254C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013254C;
        }
    }

label_80132534:
    loop_80132534(ctx);
    if (ctx->pc == 0x8013254Cu) goto label_8013254C;
    return;
label_80132538:
    // 80132538: addic.  r11, r11, -1
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

label_8013253C:
    // 8013253C: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

label_80132540:
    ctx->pc = 0x80132540u;
    // 80132540: sth     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80132544:
    // 80132544: addi    r6, r6, 2
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(2);

label_80132548:
    // 80132548: bc    12, 1, 0x80132534
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80132534u;
                return;
            }
            goto label_80132534;
        }
    }

label_8013254C:
    ctx->pc = 0x8013254Cu;
    ctx->downcount -= 4;
    // 8013254C: lwz     r0, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132550:
    ctx->pc = 0x80132550u;
    // 80132550: subf   r0, r10, r0
    {
        u32 a = ~ctx->gpr[10];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80132554:
    ctx->pc = 0x80132554u;
    // 80132554: stw     r0, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132558:
    ctx->pc = 0x80132558u;
    // 80132558: b       0x80132718
    {
            goto label_80132718;
    }

label_8013255C:
    ctx->pc = 0x8013255Cu;
    ctx->downcount -= 9;
    // 8013255C: lwz     r11, 788(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(788);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132560:
    ctx->pc = 0x80132560u;
    // 80132560: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80132564:
    ctx->pc = 0x80132564u;
    // 80132564: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132568:
    ctx->pc = 0x80132568u;
    // 80132568: lha     r3, 176(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(176);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8013256C:
    ctx->pc = 0x8013256Cu;
    // 8013256C: lwz     r0, 180(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(180);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132570:
    ctx->pc = 0x80132570u;
    // 80132570: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132574:
    ctx->pc = 0x80132574u;
    // 80132574: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132578:
    ctx->pc = 0x80132578u;
    // 80132578: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013257Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013257C:
    ctx->pc = 0x8013257Cu;
    ctx->downcount -= 4;
    // 8013257C: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80132580:
    ctx->pc = 0x80132580u;
    // 80132580: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80132584:
    ctx->pc = 0x80132584u;
    // 80132584: addi    r3, r3, 18796
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(18796);

label_80132588:
    ctx->pc = 0x80132588u;
    // 80132588: bl      0x800994E4
    {
            ctx->lr = 0x8013258Cu;
            ctx->pc = 0x800994E4u;
            return;
    }

label_8013258C:
    ctx->pc = 0x8013258Cu;
    ctx->downcount -= 3;
    // 8013258C: or.   r3, r3, r3
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

label_80132590:
    ctx->pc = 0x80132590u;
    // 80132590: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80132594:
    ctx->pc = 0x80132594u;
    // 80132594: bc    12, 2, 0x801325BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801325BC;
        }
    }

label_80132598:
    ctx->pc = 0x80132598u;
    ctx->downcount -= 9;
    // 80132598: lfs     f0, 18868(r9)
    if (!ppc_fp_available_inline(ctx, 0x80132598u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18868);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8013259C:
    ctx->pc = 0x8013259Cu;
    // 8013259C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801325A0:
    ctx->pc = 0x801325A0u;
    // 801325A0: addi    r9, r1, 16
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(16);

label_801325A4:
    ctx->pc = 0x801325A4u;
    // 801325A4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801325A8:
    ctx->pc = 0x801325A8u;
    // 801325A8: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x801325A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801325AC:
    ctx->pc = 0x801325ACu;
    // 801325AC: or   r6, r9, r9
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[9];
    }

label_801325B0:
    ctx->pc = 0x801325B0u;
    // 801325B0: stfs     f0, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x801325B0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801325B4:
    ctx->pc = 0x801325B4u;
    // 801325B4: stfs     f0, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x801325B4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801325B8:
    ctx->pc = 0x801325B8u;
    // 801325B8: bl      0x8021B838
    {
            ctx->lr = 0x801325BCu;
            ctx->pc = 0x8021B838u;
            return;
    }

label_801325BC:
    ctx->pc = 0x801325BCu;
    ctx->downcount -= 3;
    // 801325BC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801325C0:
    ctx->pc = 0x801325C0u;
    // 801325C0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801325C4:
    ctx->pc = 0x801325C4u;
    // 801325C4: bl      0x80132940
    {
            ctx->lr = 0x801325C8u;
            goto label_80132940;
    }

label_801325C8:
    ctx->pc = 0x801325C8u;
    ctx->downcount -= 3;
    // 801325C8: addi    r28, r1, 80
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(80);

label_801325CC:
    ctx->pc = 0x801325CCu;
    // 801325CC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801325D0:
    ctx->pc = 0x801325D0u;
    // 801325D0: bl      0x80132BA8
    {
            ctx->lr = 0x801325D4u;
            goto label_80132BA8;
    }

label_801325D4:
    ctx->pc = 0x801325D4u;
    ctx->downcount -= 10;
    // 801325D4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801325D8:
    ctx->pc = 0x801325D8u;
    // 801325D8: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_801325DC:
    ctx->pc = 0x801325DCu;
    // 801325DC: lfs     f13, 18872(r9)
    if (!ppc_fp_available_inline(ctx, 0x801325DCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18872);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801325E0:
    ctx->pc = 0x801325E0u;
    // 801325E0: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_801325E4:
    ctx->pc = 0x801325E4u;
    // 801325E4: lfs     f0, 18868(r11)
    if (!ppc_fp_available_inline(ctx, 0x801325E4u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(18868);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801325E8:
    ctx->pc = 0x801325E8u;
    // 801325E8: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801325EC:
    ctx->pc = 0x801325ECu;
    // 801325EC: stfs     f13, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x801325ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801325F0:
    ctx->pc = 0x801325F0u;
    // 801325F0: stfs     f0, 8(r28)
    if (!ppc_fp_available_inline(ctx, 0x801325F0u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801325F4:
    ctx->pc = 0x801325F4u;
    // 801325F4: stfs     f0, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x801325F4u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801325F8:
    ctx->pc = 0x801325F8u;
    // 801325F8: bl      0x8028B494
    {
            ctx->lr = 0x801325FCu;
            ctx->pc = 0x8028B494u;
            return;
    }

label_801325FC:
    ctx->pc = 0x801325FCu;
    ctx->downcount -= 7;
    // 801325FC: lwz     r11, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132600:
    ctx->pc = 0x80132600u;
    // 80132600: addi    r3, r1, 378
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(378);

label_80132604:
    ctx->pc = 0x80132604u;
    // 80132604: lwz     r5, 320(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(320);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80132608:
    ctx->pc = 0x80132608u;
    // 80132608: lwz     r9, 216(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(216);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013260C:
    ctx->pc = 0x8013260Cu;
    // 8013260C: lwz     r4, 96(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(96);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80132610:
    ctx->pc = 0x80132610u;
    // 80132610: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132614:
    ctx->pc = 0x80132614u;
    // 80132614: bl      0x801CF88C
    {
            ctx->lr = 0x80132618u;
            ctx->pc = 0x801CF88Cu;
            return;
    }

label_80132618:
    ctx->pc = 0x80132618u;
    ctx->downcount -= 7;
    // 80132618: lhz     r9, 378(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(378);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_8013261C:
    ctx->pc = 0x8013261Cu;
    // 8013261C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80132620:
    ctx->pc = 0x80132620u;
    // 80132620: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_80132624:
    ctx->pc = 0x80132624u;
    // 80132624: stw     r28, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80132628:
    ctx->pc = 0x80132628u;
    // 80132628: cmpw    r9, r0
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

label_8013262C:
    ctx->pc = 0x8013262Cu;
    // 8013262C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80132630:
    ctx->pc = 0x80132630u;
    // 80132630: bc    4, 2, 0x80132638
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132638;
        }
    }

label_80132634:
    ctx->pc = 0x80132634u;
    ctx->downcount -= 1;
    // 80132634: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80132638:
    ctx->pc = 0x80132638u;
    ctx->downcount -= 2;
    // 80132638: cmpwi   r0, 0
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

label_8013263C:
    ctx->pc = 0x8013263Cu;
    // 8013263C: bc    12, 2, 0x8013264C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013264C;
        }
    }

label_80132640:
    ctx->pc = 0x80132640u;
    ctx->downcount -= 3;
    // 80132640: addi    r0, r1, 82
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(82);

label_80132644:
    ctx->pc = 0x80132644u;
    // 80132644: sth     r9, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80132648:
    ctx->pc = 0x80132648u;
    // 80132648: stw     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013264C:
    ctx->pc = 0x8013264Cu;
    ctx->downcount -= 5;
    // 8013264C: stb     r29, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write8(ctx, ea, (u8)ctx->gpr[29]);
    }

label_80132650:
    ctx->pc = 0x80132650u;
    // 80132650: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80132654:
    ctx->pc = 0x80132654u;
    // 80132654: addi    r29, r1, 96
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(96);

label_80132658:
    ctx->pc = 0x80132658u;
    // 80132658: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_8013265C:
    ctx->pc = 0x8013265Cu;
    // 8013265C: bl      0x80100A40
    {
            ctx->lr = 0x80132660u;
            ctx->pc = 0x80100A40u;
            return;
    }

label_80132660:
    ctx->pc = 0x80132660u;
    ctx->downcount -= 3;
    // 80132660: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132664:
    ctx->pc = 0x80132664u;
    // 80132664: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80132668:
    ctx->pc = 0x80132668u;
    // 80132668: bl      0x80100368
    {
            ctx->lr = 0x8013266Cu;
            ctx->pc = 0x80100368u;
            return;
    }

label_8013266C:
    ctx->pc = 0x8013266Cu;
    ctx->downcount -= 6;
    // 8013266C: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132670:
    ctx->pc = 0x80132670u;
    // 80132670: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132674:
    ctx->pc = 0x80132674u;
    // 80132674: addi    r4, r4, 18836
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18836);

label_80132678:
    ctx->pc = 0x80132678u;
    // 80132678: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013267C:
    ctx->pc = 0x8013267Cu;
    // 8013267C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132680:
    ctx->pc = 0x80132680u;
    // 80132680: bl      0x8009258C
    {
            ctx->lr = 0x80132684u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132684:
    ctx->pc = 0x80132684u;
    ctx->downcount -= 3;
    // 80132684: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80132688:
    ctx->pc = 0x80132688u;
    // 80132688: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013268C:
    ctx->pc = 0x8013268Cu;
    // 8013268C: bl      0x80098CD0
    {
            ctx->lr = 0x80132690u;
            ctx->pc = 0x80098CD0u;
            return;
    }

label_80132690:
    ctx->pc = 0x80132690u;
    ctx->downcount -= 11;
    // 80132690: lwz     r10, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80132694:
    ctx->pc = 0x80132694u;
    // 80132694: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132698:
    ctx->pc = 0x80132698u;
    // 80132698: li      r0, 9
    ctx->gpr[0] = (u32)(s32)(9);

label_8013269C:
    ctx->pc = 0x8013269Cu;
    // 8013269C: addi    r9, r1, 16
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(16);

label_801326A0:
    ctx->pc = 0x801326A0u;
    // 801326A0: addi    r3, r31, 856
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(856);

label_801326A4:
    ctx->pc = 0x801326A4u;
    // 801326A4: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801326A8:
    ctx->pc = 0x801326A8u;
    // 801326A8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801326AC:
    ctx->pc = 0x801326ACu;
    // 801326AC: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801326B0:
    ctx->pc = 0x801326B0u;
    // 801326B0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_801326B4:
    ctx->pc = 0x801326B4u;
    // 801326B4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801326B8:
    ctx->pc = 0x801326B8u;
    // 801326B8: bl      0x801D2C4C
    {
            ctx->lr = 0x801326BCu;
            ctx->pc = 0x801D2C4Cu;
            return;
    }

label_801326BC:
    ctx->pc = 0x801326BCu;
    ctx->downcount -= 4;
    // 801326BC: lwz     r11, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801326C0:
    ctx->pc = 0x801326C0u;
    // 801326C0: or   r9, r28, r28
    {
        ctx->gpr[9] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801326C4:
    ctx->pc = 0x801326C4u;
    // 801326C4: cmpw    r28, r11
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801326C8:
    ctx->pc = 0x801326C8u;
    // 801326C8: bc    12, 2, 0x801326D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801326D8;
        }
    }

label_801326CC:
    loop_801326CC(ctx);
    if (ctx->pc == 0x801326D8u) goto label_801326D8;
    return;
label_801326D0:
    // 801326D0: cmpw    r9, r11
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801326D4:
    // 801326D4: bc    4, 2, 0x801326CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801326CCu;
                return;
            }
            goto label_801326CC;
        }
    }

label_801326D8:
    ctx->pc = 0x801326D8u;
    ctx->downcount -= 7;
    // 801326D8: lwz     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801326DC:
    ctx->pc = 0x801326DCu;
    // 801326DC: or   r9, r11, r11
    {
        ctx->gpr[9] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801326E0:
    ctx->pc = 0x801326E0u;
    // 801326E0: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801326E4:
    ctx->pc = 0x801326E4u;
    // 801326E4: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801326E8:
    ctx->pc = 0x801326E8u;
    // 801326E8: subf   r10, r4, r9
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_801326EC:
    ctx->pc = 0x801326ECu;
    // 801326EC: srawi. r11, r0, 1
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

label_801326F0:
    ctx->pc = 0x801326F0u;
    // 801326F0: bc    4, 1, 0x8013270C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013270C;
        }
    }

label_801326F4:
    loop_801326F4(ctx);
    if (ctx->pc == 0x8013270Cu) goto label_8013270C;
    return;
label_801326F8:
    // 801326F8: addic.  r11, r11, -1
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

label_801326FC:
    // 801326FC: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

label_80132700:
    ctx->pc = 0x80132700u;
    // 80132700: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80132704:
    // 80132704: addi    r4, r4, 2
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(2);

label_80132708:
    // 80132708: bc    12, 1, 0x801326F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801326F4u;
                return;
            }
            goto label_801326F4;
        }
    }

label_8013270C:
    ctx->pc = 0x8013270Cu;
    ctx->downcount -= 3;
    // 8013270C: lwz     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132710:
    ctx->pc = 0x80132710u;
    // 80132710: subf   r0, r10, r0
    {
        u32 a = ~ctx->gpr[10];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80132714:
    ctx->pc = 0x80132714u;
    // 80132714: stw     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132718:
    ctx->pc = 0x80132718u;
    ctx->downcount -= 17;
    // 80132718: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8013271C:
    ctx->pc = 0x8013271Cu;
    // 8013271C: lwz     r0, 412(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(412);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132720:
    ctx->pc = 0x80132720u;
    // 80132720: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132724:
    ctx->pc = 0x80132724u;
    // 80132724: lmw     r26, 384(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(384);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80132728:
    ctx->pc = 0x80132728u;
    // 80132728: addi    r1, r1, 408
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(408);

label_8013272C:
    ctx->pc = 0x8013272Cu;
    // 8013272C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80132730:
    ctx->pc = 0x80132730u;
    ctx->downcount -= 17;
    // 80132730: stwu     r1, -288(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-288);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80132734:
    ctx->pc = 0x80132734u;
    // 80132734: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80132738:
    ctx->pc = 0x80132738u;
    // 80132738: stmw     r28, 272(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(272);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8013273C:
    ctx->pc = 0x8013273Cu;
    // 8013273C: stw     r0, 292(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(292);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132740:
    ctx->pc = 0x80132740u;
    // 80132740: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132744:
    ctx->pc = 0x80132744u;
    // 80132744: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80132748:
    ctx->pc = 0x80132748u;
    // 80132748: bl      0x8015E544
    {
            ctx->lr = 0x8013274Cu;
            ctx->pc = 0x8015E544u;
            return;
    }

label_8013274C:
    ctx->pc = 0x8013274Cu;
    ctx->downcount -= 4;
    // 8013274C: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80132750:
    ctx->pc = 0x80132750u;
    // 80132750: addi    r3, r31, 856
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(856);

label_80132754:
    ctx->pc = 0x80132754u;
    // 80132754: li      r29, 3
    ctx->gpr[29] = (u32)(s32)(3);

label_80132758:
    ctx->pc = 0x80132758u;
    // 80132758: bl      0x801D2F74
    {
            ctx->lr = 0x8013275Cu;
            ctx->pc = 0x801D2F74u;
            return;
    }

label_8013275C:
    ctx->pc = 0x8013275Cu;
    ctx->downcount -= 9;
    // 8013275C: lwz     r11, 780(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(780);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132760:
    ctx->pc = 0x80132760u;
    // 80132760: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132764:
    ctx->pc = 0x80132764u;
    // 80132764: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132768:
    ctx->pc = 0x80132768u;
    // 80132768: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013276C:
    ctx->pc = 0x8013276Cu;
    // 8013276C: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80132770:
    ctx->pc = 0x80132770u;
    // 80132770: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132774:
    ctx->pc = 0x80132774u;
    // 80132774: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132778:
    ctx->pc = 0x80132778u;
    // 80132778: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013277Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013277C:
    ctx->pc = 0x8013277Cu;
    ctx->downcount -= 9;
    // 8013277C: lwz     r11, 784(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(784);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132780:
    ctx->pc = 0x80132780u;
    // 80132780: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132784:
    ctx->pc = 0x80132784u;
    // 80132784: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132788:
    ctx->pc = 0x80132788u;
    // 80132788: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013278C:
    ctx->pc = 0x8013278Cu;
    // 8013278C: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80132790:
    ctx->pc = 0x80132790u;
    // 80132790: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132794:
    ctx->pc = 0x80132794u;
    // 80132794: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132798:
    ctx->pc = 0x80132798u;
    // 80132798: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013279Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013279C:
    ctx->pc = 0x8013279Cu;
    ctx->downcount -= 9;
    // 8013279C: lwz     r11, 788(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(788);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801327A0:
    ctx->pc = 0x801327A0u;
    // 801327A0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801327A4:
    ctx->pc = 0x801327A4u;
    // 801327A4: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801327A8:
    ctx->pc = 0x801327A8u;
    // 801327A8: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801327AC:
    ctx->pc = 0x801327ACu;
    // 801327AC: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801327B0:
    ctx->pc = 0x801327B0u;
    // 801327B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801327B4:
    ctx->pc = 0x801327B4u;
    // 801327B4: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801327B8:
    ctx->pc = 0x801327B8u;
    // 801327B8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801327BCu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801327BC:
    ctx->pc = 0x801327BCu;
    ctx->downcount -= 9;
    // 801327BC: lwz     r11, 792(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801327C0:
    ctx->pc = 0x801327C0u;
    // 801327C0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801327C4:
    ctx->pc = 0x801327C4u;
    // 801327C4: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801327C8:
    ctx->pc = 0x801327C8u;
    // 801327C8: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801327CC:
    ctx->pc = 0x801327CCu;
    // 801327CC: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801327D0:
    ctx->pc = 0x801327D0u;
    // 801327D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801327D4:
    ctx->pc = 0x801327D4u;
    // 801327D4: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801327D8:
    ctx->pc = 0x801327D8u;
    // 801327D8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801327DCu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801327DC:
    ctx->pc = 0x801327DCu;
    ctx->downcount -= 9;
    // 801327DC: lwz     r11, 796(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(796);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801327E0:
    ctx->pc = 0x801327E0u;
    // 801327E0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801327E4:
    ctx->pc = 0x801327E4u;
    // 801327E4: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801327E8:
    ctx->pc = 0x801327E8u;
    // 801327E8: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801327EC:
    ctx->pc = 0x801327ECu;
    // 801327EC: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801327F0:
    ctx->pc = 0x801327F0u;
    // 801327F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801327F4:
    ctx->pc = 0x801327F4u;
    // 801327F4: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801327F8:
    ctx->pc = 0x801327F8u;
    // 801327F8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801327FCu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801327FC:
    ctx->pc = 0x801327FCu;
    ctx->downcount -= 9;
    // 801327FC: lwz     r11, 800(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(800);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132800:
    ctx->pc = 0x80132800u;
    // 80132800: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132804:
    ctx->pc = 0x80132804u;
    // 80132804: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132808:
    ctx->pc = 0x80132808u;
    // 80132808: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013280C:
    ctx->pc = 0x8013280Cu;
    // 8013280C: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80132810:
    ctx->pc = 0x80132810u;
    // 80132810: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132814:
    ctx->pc = 0x80132814u;
    // 80132814: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132818:
    ctx->pc = 0x80132818u;
    // 80132818: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013281Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013281C:
    ctx->pc = 0x8013281Cu;
    ctx->downcount -= 9;
    // 8013281C: lwz     r11, 804(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(804);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132820:
    ctx->pc = 0x80132820u;
    // 80132820: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132824:
    ctx->pc = 0x80132824u;
    // 80132824: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132828:
    ctx->pc = 0x80132828u;
    // 80132828: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013282C:
    ctx->pc = 0x8013282Cu;
    // 8013282C: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80132830:
    ctx->pc = 0x80132830u;
    // 80132830: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132834:
    ctx->pc = 0x80132834u;
    // 80132834: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132838:
    ctx->pc = 0x80132838u;
    // 80132838: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013283Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013283C:
    ctx->pc = 0x8013283Cu;
    ctx->downcount -= 2;
    // 8013283C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80132840:
    ctx->pc = 0x80132840u;
    // 80132840: stb     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80132844:
    ctx->pc = 0x80132844u;
    ctx->downcount -= 11;
    // 80132844: lwz     r9, 808(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132848:
    // 80132848: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8013284C:
    ctx->pc = 0x8013284Cu;
    // 8013284C: lwzx    r11, r9, r28
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[28];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132850:
    // 80132850: addi    r28, r28, 4
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(4);

label_80132854:
    ctx->pc = 0x80132854u;
    // 80132854: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132858:
    ctx->pc = 0x80132858u;
    // 80132858: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8013285C:
    ctx->pc = 0x8013285Cu;
    // 8013285C: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132860:
    // 80132860: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132864:
    ctx->pc = 0x80132864u;
    // 80132864: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132868:
    ctx->pc = 0x80132868u;
    // 80132868: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013286Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013286C:
    ctx->downcount -= 2;
    // 8013286C: addic.  r29, r29, -1
    {
        u64 a = ctx->gpr[29];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[29] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80132870:
    // 80132870: bc    4, 2, 0x80132844
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80132844u;
                return;
            }
            goto label_80132844;
        }
    }

label_80132874:
    ctx->pc = 0x80132874u;
    ctx->downcount -= 11;
    // 80132874: lwz     r3, 824(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(824);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80132878:
    ctx->pc = 0x80132878u;
    // 80132878: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8013287C:
    ctx->pc = 0x8013287Cu;
    // 8013287C: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80132880:
    ctx->pc = 0x80132880u;
    // 80132880: li      r29, 3
    ctx->gpr[29] = (u32)(s32)(3);

label_80132884:
    ctx->pc = 0x80132884u;
    // 80132884: lwz     r9, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132888:
    ctx->pc = 0x80132888u;
    // 80132888: lha     r0, 40(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(40);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8013288C:
    ctx->pc = 0x8013288Cu;
    // 8013288C: lwz     r9, 44(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(44);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132890:
    ctx->pc = 0x80132890u;
    // 80132890: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132894:
    ctx->pc = 0x80132894u;
    // 80132894: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80132898:
    ctx->pc = 0x80132898u;
    // 80132898: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013289Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013289C:
    ctx->pc = 0x8013289Cu;
    ctx->downcount -= 11;
    // 8013289C: lwz     r9, 828(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(828);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801328A0:
    // 801328A0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801328A4:
    ctx->pc = 0x801328A4u;
    // 801328A4: lwzx    r11, r9, r28
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[28];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801328A8:
    // 801328A8: addi    r28, r28, 4
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(4);

label_801328AC:
    ctx->pc = 0x801328ACu;
    // 801328AC: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801328B0:
    ctx->pc = 0x801328B0u;
    // 801328B0: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801328B4:
    ctx->pc = 0x801328B4u;
    // 801328B4: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801328B8:
    // 801328B8: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801328BC:
    ctx->pc = 0x801328BCu;
    // 801328BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801328C0:
    ctx->pc = 0x801328C0u;
    // 801328C0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801328C4u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801328C4:
    ctx->downcount -= 2;
    // 801328C4: addic.  r29, r29, -1
    {
        u64 a = ctx->gpr[29];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[29] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801328C8:
    // 801328C8: bc    4, 2, 0x8013289C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8013289Cu;
                return;
            }
            goto label_8013289C;
        }
    }

label_801328CC:
    ctx->pc = 0x801328CCu;
    ctx->downcount -= 9;
    // 801328CC: lwz     r11, 844(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(844);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801328D0:
    ctx->pc = 0x801328D0u;
    // 801328D0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801328D4:
    ctx->pc = 0x801328D4u;
    // 801328D4: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801328D8:
    ctx->pc = 0x801328D8u;
    // 801328D8: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801328DC:
    ctx->pc = 0x801328DCu;
    // 801328DC: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801328E0:
    ctx->pc = 0x801328E0u;
    // 801328E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801328E4:
    ctx->pc = 0x801328E4u;
    // 801328E4: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801328E8:
    ctx->pc = 0x801328E8u;
    // 801328E8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801328ECu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801328EC:
    ctx->pc = 0x801328ECu;
    ctx->downcount -= 9;
    // 801328EC: lwz     r11, 848(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(848);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801328F0:
    ctx->pc = 0x801328F0u;
    // 801328F0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801328F4:
    ctx->pc = 0x801328F4u;
    // 801328F4: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801328F8:
    ctx->pc = 0x801328F8u;
    // 801328F8: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801328FC:
    ctx->pc = 0x801328FCu;
    // 801328FC: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80132900:
    ctx->pc = 0x80132900u;
    // 80132900: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132904:
    ctx->pc = 0x80132904u;
    // 80132904: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132908:
    ctx->pc = 0x80132908u;
    // 80132908: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013290Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013290C:
    ctx->pc = 0x8013290Cu;
    ctx->downcount -= 9;
    // 8013290C: lwz     r11, 852(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(852);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132910:
    ctx->pc = 0x80132910u;
    // 80132910: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132914:
    ctx->pc = 0x80132914u;
    // 80132914: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132918:
    ctx->pc = 0x80132918u;
    // 80132918: lha     r3, 184(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(184);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8013291C:
    ctx->pc = 0x8013291Cu;
    // 8013291C: lwz     r0, 188(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132920:
    ctx->pc = 0x80132920u;
    // 80132920: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80132924:
    ctx->pc = 0x80132924u;
    // 80132924: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132928:
    ctx->pc = 0x80132928u;
    // 80132928: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013292Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013292C:
    ctx->pc = 0x8013292Cu;
    ctx->downcount -= 16;
    // 8013292C: lwz     r0, 292(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(292);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132930:
    ctx->pc = 0x80132930u;
    // 80132930: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132934:
    ctx->pc = 0x80132934u;
    // 80132934: lmw     r28, 272(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(272);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80132938:
    ctx->pc = 0x80132938u;
    // 80132938: addi    r1, r1, 288
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(288);

label_8013293C:
    ctx->pc = 0x8013293Cu;
    // 8013293C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80132940:
    ctx->pc = 0x80132940u;
    ctx->downcount -= 23;
    // 80132940: stwu     r1, -624(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-624);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80132944:
    ctx->pc = 0x80132944u;
    // 80132944: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80132948:
    ctx->pc = 0x80132948u;
    // 80132948: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_8013294C:
    ctx->pc = 0x8013294Cu;
    // 8013294C: stmw     r20, 576(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(576);
        for (u32 r = 20; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80132950:
    ctx->pc = 0x80132950u;
    // 80132950: stw     r0, 628(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(628);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132954:
    ctx->pc = 0x80132954u;
    // 80132954: stw     r12, 572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(572);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80132958:
    ctx->pc = 0x80132958u;
    // 80132958: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013295C:
    ctx->pc = 0x8013295Cu;
    // 8013295C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80132960:
    ctx->pc = 0x80132960u;
    // 80132960: lwz     r9, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132964:
    ctx->pc = 0x80132964u;
    // 80132964: lwz     r0, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132968:
    ctx->pc = 0x80132968u;
    // 80132968: cmpwi   r9, 2
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

label_8013296C:
    ctx->pc = 0x8013296Cu;
    // 8013296C: stw     r0, 720(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(720);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132970:
    ctx->pc = 0x80132970u;
    // 80132970: bc    12, 2, 0x80132978
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132978;
        }
    }

label_80132974:
    ctx->pc = 0x80132974u;
    ctx->downcount -= 1;
    // 80132974: stw     r9, 728(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(728);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80132978:
    ctx->pc = 0x80132978u;
    ctx->downcount -= 5;
    // 80132978: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8013297C:
    ctx->pc = 0x8013297Cu;
    // 8013297C: addi    r30, r1, 16
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(16);

label_80132980:
    ctx->pc = 0x80132980u;
    // 80132980: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80132984:
    ctx->pc = 0x80132984u;
    // 80132984: addi    r4, r4, 18876
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18876);

label_80132988:
    ctx->pc = 0x80132988u;
    // 80132988: bl      0x801CFE08
    {
            ctx->lr = 0x8013298Cu;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_8013298C:
    ctx->pc = 0x8013298Cu;
    ctx->downcount -= 6;
    // 8013298C: or   r20, r30, r30
    {
        ctx->gpr[20] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132990:
    ctx->pc = 0x80132990u;
    // 80132990: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132994:
    ctx->pc = 0x80132994u;
    // 80132994: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132998:
    ctx->pc = 0x80132998u;
    // 80132998: addi    r4, r4, 18900
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18900);

label_8013299C:
    ctx->pc = 0x8013299Cu;
    // 8013299C: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_801329A0:
    ctx->pc = 0x801329A0u;
    // 801329A0: bl      0x801CFE08
    {
            ctx->lr = 0x801329A4u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_801329A4:
    ctx->pc = 0x801329A4u;
    ctx->downcount -= 21;
    // 801329A4: cmpwi   cr3, r29, 1
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 16)) | (cr_bits << 16);
    }

label_801329A8:
    ctx->pc = 0x801329A8u;
    // 801329A8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801329AC:
    ctx->pc = 0x801329ACu;
    // 801329AC: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_801329B0:
    ctx->pc = 0x801329B0u;
    // 801329B0: lis     r10, 17200
    ctx->gpr[10] = ((u32)(s32)(17200) << 16);

label_801329B4:
    ctx->pc = 0x801329B4u;
    // 801329B4: stw     r0, 564(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(564);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801329B8:
    ctx->pc = 0x801329B8u;
    // 801329B8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801329BC:
    ctx->pc = 0x801329BCu;
    // 801329BC: lfd     f0, 18992(r9)
    if (!ppc_fp_available_inline(ctx, 0x801329BCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18992);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801329C0:
    ctx->pc = 0x801329C0u;
    // 801329C0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801329C4:
    ctx->pc = 0x801329C4u;
    // 801329C4: stw     r10, 560(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(560);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801329C8:
    ctx->pc = 0x801329C8u;
    // 801329C8: addi    r28, r1, 24
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(24);

label_801329CC:
    ctx->pc = 0x801329CCu;
    // 801329CC: addi    r30, r1, 288
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(288);

label_801329D0:
    ctx->pc = 0x801329D0u;
    // 801329D0: addi    r4, r4, 18912
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18912);

label_801329D4:
    ctx->pc = 0x801329D4u;
    // 801329D4: lfd     f1, 560(r1)
    if (!ppc_fp_available_inline(ctx, 0x801329D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(560);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801329D8:
    ctx->pc = 0x801329D8u;
    // 801329D8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_801329DC:
    ctx->pc = 0x801329DCu;
    // 801329DC: cmpwi   cr4, r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801329E0:
    ctx->pc = 0x801329E0u;
    // 801329E0: or   r23, r28, r28
    {
        ctx->gpr[23] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801329E4:
    ctx->pc = 0x801329E4u;
    // 801329E4: fsub   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x801329E4u)) return;
    ppc_fsub(ctx, 1, 1, 0);

label_801329E8:
    ctx->pc = 0x801329E8u;
    // 801329E8: or   r24, r30, r30
    {
        ctx->gpr[24] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801329EC:
    ctx->pc = 0x801329ECu;
    // 801329EC: frsp    f1, f1
    if (!ppc_fp_available_inline(ctx, 0x801329ECu)) return;
    ppc_frsp(ctx, 1, 1);

label_801329F0:
    ctx->pc = 0x801329F0u;
    // 801329F0: lis     r25, -32721
    ctx->gpr[25] = ((u32)(s32)(-32721) << 16);

label_801329F4:
    ctx->pc = 0x801329F4u;
    // 801329F4: bl      0x801D009C
    {
            ctx->lr = 0x801329F8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801329F8:
    ctx->pc = 0x801329F8u;
    ctx->downcount -= 8;
    // 801329F8: lis     r26, -32721
    ctx->gpr[26] = ((u32)(s32)(-32721) << 16);

label_801329FC:
    ctx->pc = 0x801329FCu;
    // 801329FC: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x801329FCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80132A00:
    ctx->pc = 0x80132A00u;
    // 80132A00: stb     r27, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write8(ctx, ea, (u8)ctx->gpr[27]);
    }

label_80132A04:
    ctx->pc = 0x80132A04u;
    // 80132A04: stfd     f0, 560(r1)
    if (!ppc_fp_available_inline(ctx, 0x80132A04u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(560);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80132A08:
    ctx->pc = 0x80132A08u;
    // 80132A08: lis     r21, -32721
    ctx->gpr[21] = ((u32)(s32)(-32721) << 16);

label_80132A0C:
    ctx->pc = 0x80132A0Cu;
    // 80132A0C: stb     r27, 288(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(288);
        mem_write8(ctx, ea, (u8)ctx->gpr[27]);
    }

label_80132A10:
    ctx->pc = 0x80132A10u;
    // 80132A10: lis     r22, -32714
    ctx->gpr[22] = ((u32)(s32)(-32714) << 16);

label_80132A14:
    ctx->pc = 0x80132A14u;
    // 80132A14: lwz     r29, 564(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(564);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80132A18:
    ctx->downcount -= 1;
    // 80132A18: bc    4, 18, 0x80132A38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132A38;
        }
    }

label_80132A1C:
    ctx->pc = 0x80132A1Cu;
    ctx->downcount -= 5;
    // 80132A1C: lwz     r9, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132A20:
    // 80132A20: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80132A24:
    // 80132A24: cmpwi   r9, 0
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

label_80132A28:
    ctx->pc = 0x80132A28u;
    // 80132A28: stw     r9, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80132A2C:
    // 80132A2C: bc    4, 0, 0x80132A38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132A38;
        }
    }

label_80132A30:
    ctx->downcount -= 2;
    // 80132A30: addi    r0, r29, -1
    ctx->gpr[0] = ctx->gpr[29] + (u32)(s32)(-1);

label_80132A34:
    ctx->pc = 0x80132A34u;
    // 80132A34: stw     r0, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132A38:
    ctx->downcount -= 1;
    // 80132A38: bc    4, 14, 0x80132A58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00020000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132A58;
        }
    }

label_80132A3C:
    ctx->pc = 0x80132A3Cu;
    ctx->downcount -= 5;
    // 80132A3C: lwz     r9, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132A40:
    // 80132A40: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80132A44:
    // 80132A44: cmpw    r9, r29
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132A48:
    ctx->pc = 0x80132A48u;
    // 80132A48: stw     r9, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80132A4C:
    // 80132A4C: bc    4, 2, 0x80132A58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132A58;
        }
    }

label_80132A50:
    ctx->downcount -= 2;
    // 80132A50: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80132A54:
    ctx->pc = 0x80132A54u;
    // 80132A54: stw     r0, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132A58:
    ctx->pc = 0x80132A58u;
    ctx->downcount -= 6;
    // 80132A58: lwz     r6, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80132A5C:
    // 80132A5C: addi    r4, r25, 18920
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(18920);

label_80132A60:
    // 80132A60: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132A64:
    // 80132A64: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80132A68:
    // 80132A68: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132A6C:
    // 80132A6C: bl      0x8009258C
    {
            ctx->lr = 0x80132A70u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132A70:
    ctx->downcount -= 4;
    // 80132A70: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80132A74:
    // 80132A74: or   r4, r23, r23
    {
        ctx->gpr[4] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80132A78:
    // 80132A78: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132A7C:
    // 80132A7C: bl      0x801D012C
    {
            ctx->lr = 0x80132A80u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80132A80:
    ctx->downcount -= 5;
    // 80132A80: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132A84:
    // 80132A84: addi    r4, r26, 18940
    ctx->gpr[4] = ctx->gpr[26] + (u32)(s32)(18940);

label_80132A88:
    // 80132A88: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80132A8C:
    // 80132A8C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132A90:
    // 80132A90: bl      0x8009258C
    {
            ctx->lr = 0x80132A94u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132A94:
    ctx->downcount -= 3;
    // 80132A94: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80132A98:
    // 80132A98: addi    r4, r21, 18196
    ctx->gpr[4] = ctx->gpr[21] + (u32)(s32)(18196);

label_80132A9C:
    // 80132A9C: bl      0x80297FBC
    {
            ctx->lr = 0x80132AA0u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80132AA0:
    ctx->downcount -= 2;
    // 80132AA0: cmpwi   r3, 0
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

label_80132AA4:
    // 80132AA4: bc    4, 2, 0x80132AF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132AF0;
        }
    }

label_80132AA8:
    ctx->pc = 0x80132AA8u;
    ctx->downcount -= 6;
    // 80132AA8: lwz     r6, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80132AAC:
    // 80132AAC: addi    r4, r25, 18920
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(18920);

label_80132AB0:
    // 80132AB0: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80132AB4:
    // 80132AB4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132AB8:
    // 80132AB8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132ABC:
    // 80132ABC: bl      0x8009258C
    {
            ctx->lr = 0x80132AC0u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132AC0:
    ctx->downcount -= 4;
    // 80132AC0: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132AC4:
    // 80132AC4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132AC8:
    // 80132AC8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80132ACC:
    // 80132ACC: bl      0x801D012C
    {
            ctx->lr = 0x80132AD0u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80132AD0:
    ctx->downcount -= 5;
    // 80132AD0: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132AD4:
    // 80132AD4: addi    r4, r26, 18940
    ctx->gpr[4] = ctx->gpr[26] + (u32)(s32)(18940);

label_80132AD8:
    // 80132AD8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132ADC:
    // 80132ADC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132AE0:
    // 80132AE0: bl      0x8009258C
    {
            ctx->lr = 0x80132AE4u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132AE4:
    ctx->downcount -= 3;
    // 80132AE4: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80132AE8:
    ctx->pc = 0x80132AE8u;
    // 80132AE8: stw     r0, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132AEC:
    // 80132AEC: b       0x80132B50
    {
            goto label_80132B50;
    }

label_80132AF0:
    ctx->pc = 0x80132AF0u;
    ctx->downcount -= 3;
    // 80132AF0: lwz     r0, 728(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(728);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132AF4:
    // 80132AF4: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132AF8:
    // 80132AF8: bc    12, 2, 0x80132B50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132B50;
        }
    }

label_80132AFC:
    ctx->downcount -= 5;
    // 80132AFC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132B00:
    ctx->pc = 0x80132B00u;
    // 80132B00: stw     r0, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132B04:
    // 80132B04: addi    r4, r4, 18944
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18944);

label_80132B08:
    // 80132B08: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132B0C:
    // 80132B0C: bl      0x80297FBC
    {
            ctx->lr = 0x80132B10u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80132B10:
    ctx->downcount -= 2;
    // 80132B10: cmpwi   r3, 0
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

label_80132B14:
    // 80132B14: bc    12, 2, 0x80132B50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132B50;
        }
    }

label_80132B18:
    ctx->downcount -= 4;
    // 80132B18: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132B1C:
    // 80132B1C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132B20:
    // 80132B20: addi    r4, r4, 18960
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18960);

label_80132B24:
    // 80132B24: bl      0x80297FBC
    {
            ctx->lr = 0x80132B28u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80132B28:
    ctx->downcount -= 2;
    // 80132B28: cmpwi   r3, 0
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

label_80132B2C:
    // 80132B2C: bc    12, 2, 0x80132B50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132B50;
        }
    }

label_80132B30:
    ctx->downcount -= 4;
    // 80132B30: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132B34:
    // 80132B34: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132B38:
    // 80132B38: addi    r4, r4, 18976
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18976);

label_80132B3C:
    // 80132B3C: bl      0x80297FBC
    {
            ctx->lr = 0x80132B40u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80132B40:
    ctx->downcount -= 2;
    // 80132B40: cmpwi   r3, 0
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

label_80132B44:
    // 80132B44: bc    12, 2, 0x80132B50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132B50;
        }
    }

label_80132B48:
    ctx->downcount -= 2;
    // 80132B48: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80132B4C:
    ctx->pc = 0x80132B4Cu;
    // 80132B4C: stw     r0, 728(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(728);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132B50:
    ctx->downcount -= 4;
    // 80132B50: addi    r3, r22, -25052
    ctx->gpr[3] = ctx->gpr[22] + (u32)(s32)(-25052);

label_80132B54:
    // 80132B54: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132B58:
    // 80132B58: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132B5C:
    // 80132B5C: bl      0x800FDC84
    {
            ctx->lr = 0x80132B60u;
            ctx->pc = 0x800FDC84u;
            return;
    }

label_80132B60:
    ctx->downcount -= 2;
    // 80132B60: cmpwi   r3, 0
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

label_80132B64:
    // 80132B64: bc    12, 2, 0x80132B6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132B6C;
        }
    }

label_80132B68:
    ctx->downcount -= 1;
    // 80132B68: li      r27, 1
    ctx->gpr[27] = (u32)(s32)(1);

label_80132B6C:
    ctx->downcount -= 2;
    // 80132B6C: cmpwi   r27, 0
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132B70:
    // 80132B70: bc    12, 2, 0x80132A18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80132A18u;
                return;
            }
            goto label_80132A18;
        }
    }

label_80132B74:
    ctx->pc = 0x80132B74u;
    ctx->downcount -= 3;
    // 80132B74: or   r3, r20, r20
    {
        ctx->gpr[3] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80132B78:
    ctx->pc = 0x80132B78u;
    // 80132B78: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80132B7C:
    ctx->pc = 0x80132B7Cu;
    // 80132B7C: bl      0x801CFEAC
    {
            ctx->lr = 0x80132B80u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80132B80:
    ctx->pc = 0x80132B80u;
    ctx->downcount -= 3;
    // 80132B80: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80132B84:
    ctx->pc = 0x80132B84u;
    // 80132B84: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80132B88:
    ctx->pc = 0x80132B88u;
    // 80132B88: bl      0x801CFEAC
    {
            ctx->lr = 0x80132B8Cu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80132B8C:
    ctx->pc = 0x80132B8Cu;
    ctx->downcount -= 18;
    // 80132B8C: lwz     r0, 628(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(628);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132B90:
    ctx->pc = 0x80132B90u;
    // 80132B90: lwz     r12, 572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(572);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80132B94:
    ctx->pc = 0x80132B94u;
    // 80132B94: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132B98:
    ctx->pc = 0x80132B98u;
    // 80132B98: lmw     r20, 576(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(576);
        for (u32 r = 20; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80132B9C:
    ctx->pc = 0x80132B9Cu;
    // 80132B9C: mtcrf   0x18, r12
    ctx->cr = (ctx->cr & ~0x000FF000u) | (ctx->gpr[12] & 0x000FF000u);

label_80132BA0:
    ctx->pc = 0x80132BA0u;
    // 80132BA0: addi    r1, r1, 624
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(624);

label_80132BA4:
    ctx->pc = 0x80132BA4u;
    // 80132BA4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80132BA8:
    ctx->pc = 0x80132BA8u;
    ctx->downcount -= 23;
    // 80132BA8: stwu     r1, -592(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-592);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80132BAC:
    ctx->pc = 0x80132BACu;
    // 80132BAC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80132BB0:
    ctx->pc = 0x80132BB0u;
    // 80132BB0: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_80132BB4:
    ctx->pc = 0x80132BB4u;
    // 80132BB4: stmw     r22, 552(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(552);
        for (u32 r = 22; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80132BB8:
    ctx->pc = 0x80132BB8u;
    // 80132BB8: stw     r0, 596(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132BBC:
    ctx->pc = 0x80132BBCu;
    // 80132BBC: stw     r12, 548(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(548);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80132BC0:
    ctx->pc = 0x80132BC0u;
    // 80132BC0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80132BC4:
    ctx->pc = 0x80132BC4u;
    // 80132BC4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132BC8:
    ctx->pc = 0x80132BC8u;
    // 80132BC8: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80132BCC:
    ctx->pc = 0x80132BCCu;
    // 80132BCC: stw     r0, 312(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(312);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132BD0:
    ctx->pc = 0x80132BD0u;
    // 80132BD0: stw     r0, 736(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(736);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132BD4:
    ctx->pc = 0x80132BD4u;
    // 80132BD4: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80132BD8:
    ctx->pc = 0x80132BD8u;
    // 80132BD8: bl      0x80100A40
    {
            ctx->lr = 0x80132BDCu;
            ctx->pc = 0x80100A40u;
            return;
    }

label_80132BDC:
    ctx->pc = 0x80132BDCu;
    ctx->downcount -= 6;
    // 80132BDC: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80132BE0:
    ctx->pc = 0x80132BE0u;
    // 80132BE0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132BE4:
    ctx->pc = 0x80132BE4u;
    // 80132BE4: addi    r29, r1, 16
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(16);

label_80132BE8:
    ctx->pc = 0x80132BE8u;
    // 80132BE8: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80132BEC:
    ctx->pc = 0x80132BECu;
    // 80132BEC: li      r23, 0
    ctx->gpr[23] = (u32)(s32)(0);

label_80132BF0:
    ctx->pc = 0x80132BF0u;
    // 80132BF0: bl      0x80100368
    {
            ctx->lr = 0x80132BF4u;
            ctx->pc = 0x80100368u;
            return;
    }

label_80132BF4:
    ctx->pc = 0x80132BF4u;
    ctx->downcount -= 6;
    // 80132BF4: li      r22, 0
    ctx->gpr[22] = (u32)(s32)(0);

label_80132BF8:
    ctx->pc = 0x80132BF8u;
    // 80132BF8: or   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132BFC:
    ctx->pc = 0x80132BFCu;
    // 80132BFC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132C00:
    ctx->pc = 0x80132C00u;
    // 80132C00: addi    r4, r4, 18876
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18876);

label_80132C04:
    ctx->pc = 0x80132C04u;
    // 80132C04: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80132C08:
    ctx->pc = 0x80132C08u;
    // 80132C08: bl      0x801CFE08
    {
            ctx->lr = 0x80132C0Cu;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80132C0C:
    ctx->pc = 0x80132C0Cu;
    ctx->downcount -= 4;
    // 80132C0C: lis     r30, -32721
    ctx->gpr[30] = ((u32)(s32)(-32721) << 16);

label_80132C10:
    ctx->pc = 0x80132C10u;
    // 80132C10: stb     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write8(ctx, ea, (u8)ctx->gpr[28]);
    }

label_80132C14:
    ctx->pc = 0x80132C14u;
    // 80132C14: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132C18:
    ctx->pc = 0x80132C18u;
    // 80132C18: bl      0x80134A34
    {
            ctx->lr = 0x80132C1Cu;
            ctx->pc = 0x80134A34u;
            return;
    }

label_80132C1C:
    ctx->pc = 0x80132C1Cu;
    ctx->downcount -= 2;
    // 80132C1C: cmpwi   r3, 0
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

label_80132C20:
    ctx->pc = 0x80132C20u;
    // 80132C20: bc    4, 2, 0x80132C7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132C7C;
        }
    }

label_80132C24:
    ctx->pc = 0x80132C24u;
    ctx->downcount -= 6;
    // 80132C24: lwz     r6, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80132C28:
    ctx->pc = 0x80132C28u;
    // 80132C28: addi    r4, r30, 18920
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(18920);

label_80132C2C:
    ctx->pc = 0x80132C2Cu;
    // 80132C2C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132C30:
    ctx->pc = 0x80132C30u;
    // 80132C30: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80132C34:
    ctx->pc = 0x80132C34u;
    // 80132C34: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132C38:
    ctx->pc = 0x80132C38u;
    // 80132C38: bl      0x8009258C
    {
            ctx->lr = 0x80132C3Cu;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132C3C:
    ctx->pc = 0x80132C3Cu;
    ctx->downcount -= 4;
    // 80132C3C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80132C40:
    ctx->pc = 0x80132C40u;
    // 80132C40: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80132C44:
    ctx->pc = 0x80132C44u;
    // 80132C44: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132C48:
    ctx->pc = 0x80132C48u;
    // 80132C48: bl      0x801D012C
    {
            ctx->lr = 0x80132C4Cu;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80132C4C:
    ctx->pc = 0x80132C4Cu;
    ctx->downcount -= 7;
    // 80132C4C: lwz     r6, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80132C50:
    ctx->pc = 0x80132C50u;
    // 80132C50: or   r23, r3, r3
    {
        ctx->gpr[23] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132C54:
    ctx->pc = 0x80132C54u;
    // 80132C54: addi    r4, r30, 18920
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(18920);

label_80132C58:
    ctx->pc = 0x80132C58u;
    // 80132C58: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80132C5C:
    ctx->pc = 0x80132C5Cu;
    // 80132C5C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80132C60:
    ctx->pc = 0x80132C60u;
    // 80132C60: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132C64:
    ctx->pc = 0x80132C64u;
    // 80132C64: bl      0x8009258C
    {
            ctx->lr = 0x80132C68u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132C68:
    ctx->pc = 0x80132C68u;
    ctx->downcount -= 4;
    // 80132C68: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80132C6C:
    ctx->pc = 0x80132C6Cu;
    // 80132C6C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80132C70:
    ctx->pc = 0x80132C70u;
    // 80132C70: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132C74:
    ctx->pc = 0x80132C74u;
    // 80132C74: bl      0x801D012C
    {
            ctx->lr = 0x80132C78u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80132C78:
    ctx->pc = 0x80132C78u;
    ctx->downcount -= 1;
    // 80132C78: or   r22, r3, r3
    {
        ctx->gpr[22] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132C7C:
    ctx->pc = 0x80132C7Cu;
    ctx->downcount -= 7;
    // 80132C7C: lwz     r6, 716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(716);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80132C80:
    ctx->pc = 0x80132C80u;
    // 80132C80: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132C84:
    ctx->pc = 0x80132C84u;
    // 80132C84: addi    r4, r4, 18920
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(18920);

label_80132C88:
    ctx->pc = 0x80132C88u;
    // 80132C88: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80132C8C:
    ctx->pc = 0x80132C8Cu;
    // 80132C8C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80132C90:
    ctx->pc = 0x80132C90u;
    // 80132C90: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132C94:
    ctx->pc = 0x80132C94u;
    // 80132C94: bl      0x8009258C
    {
            ctx->lr = 0x80132C98u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132C98:
    ctx->pc = 0x80132C98u;
    ctx->downcount -= 4;
    // 80132C98: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80132C9C:
    ctx->pc = 0x80132C9Cu;
    // 80132C9C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80132CA0:
    ctx->pc = 0x80132CA0u;
    // 80132CA0: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80132CA4:
    ctx->pc = 0x80132CA4u;
    // 80132CA4: bl      0x801D012C
    {
            ctx->lr = 0x80132CA8u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80132CA8:
    ctx->pc = 0x80132CA8u;
    ctx->downcount -= 3;
    // 80132CA8: stb     r28, 280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        mem_write8(ctx, ea, (u8)ctx->gpr[28]);
    }

label_80132CAC:
    ctx->pc = 0x80132CACu;
    // 80132CAC: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132CB0:
    ctx->pc = 0x80132CB0u;
    // 80132CB0: bl      0x8019D2B0
    {
            ctx->lr = 0x80132CB4u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_80132CB4:
    ctx->pc = 0x80132CB4u;
    ctx->downcount -= 4;
    // 80132CB4: lwz     r0, 776(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(776);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132CB8:
    ctx->pc = 0x80132CB8u;
    // 80132CB8: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132CBC:
    ctx->pc = 0x80132CBCu;
    // 80132CBC: cmpwi   r0, 0
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

label_80132CC0:
    ctx->pc = 0x80132CC0u;
    // 80132CC0: bc    4, 2, 0x80132DA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80132DA4;
        }
    }

label_80132CC4:
    ctx->pc = 0x80132CC4u;
    ctx->downcount -= 9;
    // 80132CC4: addi    r9, r31, 740
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(740);

label_80132CC8:
    ctx->pc = 0x80132CC8u;
    // 80132CC8: lwz     r11, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132CCC:
    ctx->pc = 0x80132CCCu;
    // 80132CCC: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132CD0:
    ctx->pc = 0x80132CD0u;
    // 80132CD0: or   r27, r9, r9
    {
        ctx->gpr[27] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80132CD4:
    ctx->pc = 0x80132CD4u;
    // 80132CD4: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80132CD8:
    ctx->pc = 0x80132CD8u;
    // 80132CD8: cmpwi   cr4, r23, 0
    {
        s32 val_a = (s32)(ctx->gpr[23]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_80132CDC:
    ctx->pc = 0x80132CDCu;
    // 80132CDC: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80132CE0:
    ctx->pc = 0x80132CE0u;
    // 80132CE0: rlwinm. r9, r0, 30, 2, 31
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

label_80132CE4:
    ctx->pc = 0x80132CE4u;
    // 80132CE4: bc    12, 2, 0x80132D30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132D30;
        }
    }

label_80132CE8:
    ctx->pc = 0x80132CE8u;
    ctx->downcount -= 2;
    // 80132CE8: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_80132CEC:
    ctx->pc = 0x80132CECu;
    // 80132CEC: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80132CF0:
    ctx->pc = 0x80132CF0u;
    ctx->downcount -= 4;
    // 80132CF0: lwz     r9, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132CF4:
    ctx->pc = 0x80132CF4u;
    // 80132CF4: lwzx    r4, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80132CF8:
    // 80132CF8: cmpwi   r4, 0
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

label_80132CFC:
    // 80132CFC: bc    12, 2, 0x80132D10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132D10;
        }
    }

label_80132D00:
    ctx->downcount -= 2;
    // 80132D00: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132D04:
    // 80132D04: bl      0x8019AC1C
    {
            ctx->lr = 0x80132D08u;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_80132D08:
    ctx->pc = 0x80132D08u;
    ctx->downcount -= 2;
    // 80132D08: lwz     r9, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132D0C:
    ctx->pc = 0x80132D0Cu;
    // 80132D0C: stwx    r25, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80132D10:
    ctx->pc = 0x80132D10u;
    ctx->downcount -= 8;
    // 80132D10: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132D14:
    // 80132D14: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_80132D18:
    ctx->pc = 0x80132D18u;
    // 80132D18: lwz     r9, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132D1C:
    // 80132D1C: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_80132D20:
    // 80132D20: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80132D24:
    // 80132D24: srawi r0, r0, 2
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

label_80132D28:
    // 80132D28: cmplw   r29, r0
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

label_80132D2C:
    // 80132D2C: bc    12, 0, 0x80132CF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80132CF0u;
                return;
            }
            goto label_80132CF0;
        }
    }

label_80132D30:
    ctx->pc = 0x80132D30u;
    ctx->downcount -= 1;
    // 80132D30: bc    12, 18, 0x80132D68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132D68;
        }
    }

label_80132D34:
    ctx->pc = 0x80132D34u;
    ctx->downcount -= 8;
    // 80132D34: addi    r30, r1, 280
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(280);

label_80132D38:
    ctx->pc = 0x80132D38u;
    // 80132D38: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132D3C:
    ctx->pc = 0x80132D3Cu;
    // 80132D3C: addi    r4, r4, 19000
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(19000);

label_80132D40:
    ctx->pc = 0x80132D40u;
    // 80132D40: or   r6, r24, r24
    {
        ctx->gpr[6] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80132D44:
    ctx->pc = 0x80132D44u;
    // 80132D44: or   r5, r23, r23
    {
        ctx->gpr[5] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80132D48:
    ctx->pc = 0x80132D48u;
    // 80132D48: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132D4C:
    ctx->pc = 0x80132D4Cu;
    // 80132D4C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132D50:
    ctx->pc = 0x80132D50u;
    // 80132D50: bl      0x8009258C
    {
            ctx->lr = 0x80132D54u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132D54:
    ctx->pc = 0x80132D54u;
    ctx->downcount -= 5;
    // 80132D54: lwz     r29, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80132D58:
    ctx->pc = 0x80132D58u;
    // 80132D58: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132D5C:
    ctx->pc = 0x80132D5Cu;
    // 80132D5C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132D60:
    ctx->pc = 0x80132D60u;
    // 80132D60: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80132D64:
    ctx->pc = 0x80132D64u;
    // 80132D64: b       0x80132E64
    {
            goto label_80132E64;
    }

label_80132D68:
    ctx->pc = 0x80132D68u;
    ctx->downcount -= 2;
    // 80132D68: cmpwi   r26, 0
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132D6C:
    ctx->pc = 0x80132D6Cu;
    // 80132D6C: bc    12, 2, 0x80132E6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132E6C;
        }
    }

label_80132D70:
    ctx->pc = 0x80132D70u;
    ctx->downcount -= 8;
    // 80132D70: addi    r30, r1, 280
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(280);

label_80132D74:
    ctx->pc = 0x80132D74u;
    // 80132D74: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132D78:
    ctx->pc = 0x80132D78u;
    // 80132D78: addi    r4, r4, 19000
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(19000);

label_80132D7C:
    ctx->pc = 0x80132D7Cu;
    // 80132D7C: or   r6, r24, r24
    {
        ctx->gpr[6] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80132D80:
    ctx->pc = 0x80132D80u;
    // 80132D80: or   r5, r26, r26
    {
        ctx->gpr[5] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80132D84:
    ctx->pc = 0x80132D84u;
    // 80132D84: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132D88:
    ctx->pc = 0x80132D88u;
    // 80132D88: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132D8C:
    ctx->pc = 0x80132D8Cu;
    // 80132D8C: bl      0x8009258C
    {
            ctx->lr = 0x80132D90u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132D90:
    ctx->pc = 0x80132D90u;
    ctx->downcount -= 5;
    // 80132D90: lwz     r29, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80132D94:
    ctx->pc = 0x80132D94u;
    // 80132D94: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132D98:
    ctx->pc = 0x80132D98u;
    // 80132D98: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132D9C:
    ctx->pc = 0x80132D9Cu;
    // 80132D9C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80132DA0:
    ctx->pc = 0x80132DA0u;
    // 80132DA0: b       0x80132E64
    {
            goto label_80132E64;
    }

label_80132DA4:
    ctx->pc = 0x80132DA4u;
    ctx->downcount -= 9;
    // 80132DA4: addi    r9, r31, 756
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(756);

label_80132DA8:
    ctx->pc = 0x80132DA8u;
    // 80132DA8: lwz     r11, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80132DAC:
    ctx->pc = 0x80132DACu;
    // 80132DAC: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132DB0:
    ctx->pc = 0x80132DB0u;
    // 80132DB0: or   r27, r9, r9
    {
        ctx->gpr[27] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80132DB4:
    ctx->pc = 0x80132DB4u;
    // 80132DB4: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80132DB8:
    ctx->pc = 0x80132DB8u;
    // 80132DB8: cmpwi   cr4, r23, 0
    {
        s32 val_a = (s32)(ctx->gpr[23]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_80132DBC:
    ctx->pc = 0x80132DBCu;
    // 80132DBC: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80132DC0:
    ctx->pc = 0x80132DC0u;
    // 80132DC0: rlwinm. r9, r0, 30, 2, 31
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

label_80132DC4:
    ctx->pc = 0x80132DC4u;
    // 80132DC4: bc    12, 2, 0x80132E10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132E10;
        }
    }

label_80132DC8:
    ctx->pc = 0x80132DC8u;
    ctx->downcount -= 2;
    // 80132DC8: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_80132DCC:
    ctx->pc = 0x80132DCCu;
    // 80132DCC: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80132DD0:
    ctx->pc = 0x80132DD0u;
    ctx->downcount -= 4;
    // 80132DD0: lwz     r9, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132DD4:
    ctx->pc = 0x80132DD4u;
    // 80132DD4: lwzx    r4, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80132DD8:
    // 80132DD8: cmpwi   r4, 0
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

label_80132DDC:
    // 80132DDC: bc    12, 2, 0x80132DF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132DF0;
        }
    }

label_80132DE0:
    ctx->downcount -= 2;
    // 80132DE0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132DE4:
    // 80132DE4: bl      0x8019AC1C
    {
            ctx->lr = 0x80132DE8u;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_80132DE8:
    ctx->pc = 0x80132DE8u;
    ctx->downcount -= 2;
    // 80132DE8: lwz     r9, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132DEC:
    ctx->pc = 0x80132DECu;
    // 80132DEC: stwx    r25, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80132DF0:
    ctx->pc = 0x80132DF0u;
    ctx->downcount -= 8;
    // 80132DF0: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132DF4:
    // 80132DF4: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_80132DF8:
    ctx->pc = 0x80132DF8u;
    // 80132DF8: lwz     r9, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80132DFC:
    // 80132DFC: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_80132E00:
    // 80132E00: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80132E04:
    // 80132E04: srawi r0, r0, 2
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

label_80132E08:
    // 80132E08: cmplw   r29, r0
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

label_80132E0C:
    // 80132E0C: bc    12, 0, 0x80132DD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80132DD0u;
                return;
            }
            goto label_80132DD0;
        }
    }

label_80132E10:
    ctx->pc = 0x80132E10u;
    ctx->downcount -= 1;
    // 80132E10: bc    12, 18, 0x80132E2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132E2C;
        }
    }

label_80132E14:
    ctx->pc = 0x80132E14u;
    ctx->downcount -= 6;
    // 80132E14: addi    r30, r1, 280
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(280);

label_80132E18:
    ctx->pc = 0x80132E18u;
    // 80132E18: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132E1C:
    ctx->pc = 0x80132E1Cu;
    // 80132E1C: addi    r4, r4, 19000
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(19000);

label_80132E20:
    ctx->pc = 0x80132E20u;
    // 80132E20: or   r6, r24, r24
    {
        ctx->gpr[6] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80132E24:
    ctx->pc = 0x80132E24u;
    // 80132E24: or   r5, r23, r23
    {
        ctx->gpr[5] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80132E28:
    ctx->pc = 0x80132E28u;
    // 80132E28: b       0x80132E48
    {
            goto label_80132E48;
    }

label_80132E2C:
    ctx->pc = 0x80132E2Cu;
    ctx->downcount -= 2;
    // 80132E2C: cmpwi   r26, 0
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132E30:
    ctx->pc = 0x80132E30u;
    // 80132E30: bc    12, 2, 0x80132E6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132E6C;
        }
    }

label_80132E34:
    ctx->pc = 0x80132E34u;
    ctx->downcount -= 5;
    // 80132E34: addi    r30, r1, 280
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(280);

label_80132E38:
    ctx->pc = 0x80132E38u;
    // 80132E38: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132E3C:
    ctx->pc = 0x80132E3Cu;
    // 80132E3C: addi    r4, r4, 19000
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(19000);

label_80132E40:
    ctx->pc = 0x80132E40u;
    // 80132E40: or   r6, r24, r24
    {
        ctx->gpr[6] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80132E44:
    ctx->pc = 0x80132E44u;
    // 80132E44: or   r5, r26, r26
    {
        ctx->gpr[5] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80132E48:
    ctx->pc = 0x80132E48u;
    ctx->downcount -= 3;
    // 80132E48: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132E4C:
    ctx->pc = 0x80132E4Cu;
    // 80132E4C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132E50:
    ctx->pc = 0x80132E50u;
    // 80132E50: bl      0x8009258C
    {
            ctx->lr = 0x80132E54u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132E54:
    ctx->pc = 0x80132E54u;
    ctx->downcount -= 4;
    // 80132E54: lwz     r29, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80132E58:
    ctx->pc = 0x80132E58u;
    // 80132E58: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132E5C:
    ctx->pc = 0x80132E5Cu;
    // 80132E5C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132E60:
    ctx->pc = 0x80132E60u;
    // 80132E60: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80132E64:
    ctx->pc = 0x80132E64u;
    ctx->downcount -= 1;
    // 80132E64: bl      0x8019A70C
    {
            ctx->lr = 0x80132E68u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80132E68:
    ctx->pc = 0x80132E68u;
    ctx->downcount -= 1;
    // 80132E68: stw     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80132E6C:
    ctx->pc = 0x80132E6Cu;
    ctx->downcount -= 5;
    // 80132E6C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132E70:
    ctx->pc = 0x80132E70u;
    // 80132E70: or   r4, r23, r23
    {
        ctx->gpr[4] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80132E74:
    ctx->pc = 0x80132E74u;
    // 80132E74: or   r5, r22, r22
    {
        ctx->gpr[5] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80132E78:
    ctx->pc = 0x80132E78u;
    // 80132E78: or   r6, r26, r26
    {
        ctx->gpr[6] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80132E7C:
    ctx->pc = 0x80132E7Cu;
    // 80132E7C: bl      0x80132EA8
    {
            ctx->lr = 0x80132E80u;
            goto label_80132EA8;
    }

label_80132E80:
    ctx->pc = 0x80132E80u;
    ctx->downcount -= 3;
    // 80132E80: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80132E84:
    ctx->pc = 0x80132E84u;
    // 80132E84: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80132E88:
    ctx->pc = 0x80132E88u;
    // 80132E88: bl      0x801CFEAC
    {
            ctx->lr = 0x80132E8Cu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80132E8C:
    ctx->pc = 0x80132E8Cu;
    ctx->downcount -= 18;
    // 80132E8C: lwz     r0, 596(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(596);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80132E90:
    ctx->pc = 0x80132E90u;
    // 80132E90: lwz     r12, 548(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(548);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80132E94:
    ctx->pc = 0x80132E94u;
    // 80132E94: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80132E98:
    ctx->pc = 0x80132E98u;
    // 80132E98: lmw     r22, 552(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(552);
        for (u32 r = 22; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80132E9C:
    ctx->pc = 0x80132E9Cu;
    // 80132E9C: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_80132EA0:
    ctx->pc = 0x80132EA0u;
    // 80132EA0: addi    r1, r1, 592
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(592);

label_80132EA4:
    ctx->pc = 0x80132EA4u;
    // 80132EA4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80132EA8:
    ctx->pc = 0x80132EA8u;
    ctx->downcount -= 19;
    // 80132EA8: stwu     r1, -296(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-296);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80132EAC:
    ctx->pc = 0x80132EACu;
    // 80132EAC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80132EB0:
    ctx->pc = 0x80132EB0u;
    // 80132EB0: stmw     r26, 272(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(272);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80132EB4:
    ctx->pc = 0x80132EB4u;
    // 80132EB4: stw     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80132EB8:
    ctx->pc = 0x80132EB8u;
    // 80132EB8: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80132EBC:
    ctx->pc = 0x80132EBCu;
    // 80132EBC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132EC0:
    ctx->pc = 0x80132EC0u;
    // 80132EC0: or   r27, r5, r5
    {
        ctx->gpr[27] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80132EC4:
    ctx->pc = 0x80132EC4u;
    // 80132EC4: or   r26, r6, r6
    {
        ctx->gpr[26] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80132EC8:
    ctx->pc = 0x80132EC8u;
    // 80132EC8: bl      0x8019D2B0
    {
            ctx->lr = 0x80132ECCu;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_80132ECC:
    ctx->pc = 0x80132ECCu;
    ctx->downcount -= 4;
    // 80132ECC: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80132ED0:
    ctx->pc = 0x80132ED0u;
    // 80132ED0: addi    r31, r1, 8
    ctx->gpr[31] = ctx->gpr[1] + (u32)(s32)(8);

label_80132ED4:
    ctx->pc = 0x80132ED4u;
    // 80132ED4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80132ED8:
    ctx->pc = 0x80132ED8u;
    // 80132ED8: bl      0x80134770
    {
            ctx->lr = 0x80132EDCu;
            ctx->pc = 0x80134770u;
            return;
    }

label_80132EDC:
    ctx->pc = 0x80132EDCu;
    ctx->downcount -= 4;
    // 80132EDC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80132EE0:
    ctx->pc = 0x80132EE0u;
    // 80132EE0: cmpwi   r29, 0
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

label_80132EE4:
    ctx->pc = 0x80132EE4u;
    // 80132EE4: stb     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80132EE8:
    ctx->pc = 0x80132EE8u;
    // 80132EE8: bc    12, 2, 0x80132F44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132F44;
        }
    }

label_80132EEC:
    ctx->pc = 0x80132EECu;
    ctx->downcount -= 6;
    // 80132EEC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132EF0:
    ctx->pc = 0x80132EF0u;
    // 80132EF0: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80132EF4:
    ctx->pc = 0x80132EF4u;
    // 80132EF4: addi    r4, r4, 19036
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(19036);

label_80132EF8:
    ctx->pc = 0x80132EF8u;
    // 80132EF8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132EFC:
    ctx->pc = 0x80132EFCu;
    // 80132EFC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132F00:
    ctx->pc = 0x80132F00u;
    // 80132F00: bl      0x8009258C
    {
            ctx->lr = 0x80132F04u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132F04:
    ctx->pc = 0x80132F04u;
    ctx->downcount -= 4;
    // 80132F04: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132F08:
    ctx->pc = 0x80132F08u;
    // 80132F08: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_80132F0C:
    ctx->pc = 0x80132F0Cu;
    // 80132F0C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132F10:
    ctx->pc = 0x80132F10u;
    // 80132F10: bl      0x8019A70C
    {
            ctx->lr = 0x80132F14u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80132F14:
    ctx->pc = 0x80132F14u;
    ctx->downcount -= 7;
    // 80132F14: stw     r3, 688(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80132F18:
    ctx->pc = 0x80132F18u;
    // 80132F18: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132F1C:
    ctx->pc = 0x80132F1Cu;
    // 80132F1C: addi    r4, r4, 19068
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(19068);

label_80132F20:
    ctx->pc = 0x80132F20u;
    // 80132F20: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80132F24:
    ctx->pc = 0x80132F24u;
    // 80132F24: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132F28:
    ctx->pc = 0x80132F28u;
    // 80132F28: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132F2C:
    ctx->pc = 0x80132F2Cu;
    // 80132F2C: bl      0x8009258C
    {
            ctx->lr = 0x80132F30u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132F30:
    ctx->pc = 0x80132F30u;
    ctx->downcount -= 4;
    // 80132F30: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132F34:
    ctx->pc = 0x80132F34u;
    // 80132F34: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132F38:
    ctx->pc = 0x80132F38u;
    // 80132F38: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_80132F3C:
    ctx->pc = 0x80132F3Cu;
    // 80132F3C: bl      0x8019A70C
    {
            ctx->lr = 0x80132F40u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80132F40:
    ctx->pc = 0x80132F40u;
    ctx->downcount -= 1;
    // 80132F40: stw     r3, 692(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80132F44:
    ctx->pc = 0x80132F44u;
    ctx->downcount -= 2;
    // 80132F44: cmpwi   r27, 0
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80132F48:
    ctx->pc = 0x80132F48u;
    // 80132F48: bc    12, 2, 0x80132FA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80132FA4;
        }
    }

label_80132F4C:
    ctx->pc = 0x80132F4Cu;
    ctx->downcount -= 6;
    // 80132F4C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132F50:
    ctx->pc = 0x80132F50u;
    // 80132F50: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80132F54:
    ctx->pc = 0x80132F54u;
    // 80132F54: addi    r4, r4, 19036
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(19036);

label_80132F58:
    ctx->pc = 0x80132F58u;
    // 80132F58: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132F5C:
    ctx->pc = 0x80132F5Cu;
    // 80132F5C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132F60:
    ctx->pc = 0x80132F60u;
    // 80132F60: bl      0x8009258C
    {
            ctx->lr = 0x80132F64u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132F64:
    ctx->pc = 0x80132F64u;
    ctx->downcount -= 4;
    // 80132F64: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132F68:
    ctx->pc = 0x80132F68u;
    // 80132F68: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_80132F6C:
    ctx->pc = 0x80132F6Cu;
    // 80132F6C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132F70:
    ctx->pc = 0x80132F70u;
    // 80132F70: bl      0x8019A70C
    {
            ctx->lr = 0x80132F74u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80132F74:
    ctx->pc = 0x80132F74u;
    ctx->downcount -= 7;
    // 80132F74: stw     r3, 696(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80132F78:
    ctx->pc = 0x80132F78u;
    // 80132F78: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132F7C:
    ctx->pc = 0x80132F7Cu;
    // 80132F7C: addi    r4, r4, 19068
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(19068);

label_80132F80:
    ctx->pc = 0x80132F80u;
    // 80132F80: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80132F84:
    ctx->pc = 0x80132F84u;
    // 80132F84: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132F88:
    ctx->pc = 0x80132F88u;
    // 80132F88: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132F8C:
    ctx->pc = 0x80132F8Cu;
    // 80132F8C: bl      0x8009258C
    {
            ctx->lr = 0x80132F90u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132F90:
    ctx->pc = 0x80132F90u;
    ctx->downcount -= 4;
    // 80132F90: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132F94:
    ctx->pc = 0x80132F94u;
    // 80132F94: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132F98:
    ctx->pc = 0x80132F98u;
    // 80132F98: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_80132F9C:
    ctx->pc = 0x80132F9Cu;
    // 80132F9C: bl      0x8019A70C
    {
            ctx->lr = 0x80132FA0u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80132FA0:
    ctx->pc = 0x80132FA0u;
    ctx->downcount -= 1;
    // 80132FA0: stw     r3, 700(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80132FA4:
    ctx->pc = 0x80132FA4u;
    ctx->downcount -= 6;
    // 80132FA4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132FA8:
    ctx->pc = 0x80132FA8u;
    // 80132FA8: or   r5, r26, r26
    {
        ctx->gpr[5] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80132FAC:
    ctx->pc = 0x80132FACu;
    // 80132FAC: addi    r4, r4, 19036
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(19036);

label_80132FB0:
    ctx->pc = 0x80132FB0u;
    // 80132FB0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132FB4:
    ctx->pc = 0x80132FB4u;
    // 80132FB4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132FB8:
    ctx->pc = 0x80132FB8u;
    // 80132FB8: bl      0x8009258C
    {
            ctx->lr = 0x80132FBCu;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132FBC:
    ctx->pc = 0x80132FBCu;
    ctx->downcount -= 4;
    // 80132FBC: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132FC0:
    ctx->pc = 0x80132FC0u;
    // 80132FC0: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80132FC4:
    ctx->pc = 0x80132FC4u;
    // 80132FC4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132FC8:
    ctx->pc = 0x80132FC8u;
    // 80132FC8: bl      0x8019A70C
    {
            ctx->lr = 0x80132FCCu;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80132FCC:
    ctx->pc = 0x80132FCCu;
    ctx->downcount -= 7;
    // 80132FCC: stw     r3, 704(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80132FD0:
    ctx->pc = 0x80132FD0u;
    // 80132FD0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80132FD4:
    ctx->pc = 0x80132FD4u;
    // 80132FD4: addi    r4, r4, 19068
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(19068);

label_80132FD8:
    ctx->pc = 0x80132FD8u;
    // 80132FD8: or   r5, r26, r26
    {
        ctx->gpr[5] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80132FDC:
    ctx->pc = 0x80132FDCu;
    // 80132FDC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132FE0:
    ctx->pc = 0x80132FE0u;
    // 80132FE0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80132FE4:
    ctx->pc = 0x80132FE4u;
    // 80132FE4: bl      0x8009258C
    {
            ctx->lr = 0x80132FE8u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80132FE8:
    ctx->pc = 0x80132FE8u;
    ctx->downcount -= 4;
    // 80132FE8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80132FEC:
    ctx->pc = 0x80132FECu;
    // 80132FEC: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80132FF0:
    ctx->pc = 0x80132FF0u;
    // 80132FF0: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80132FF4:
    ctx->pc = 0x80132FF4u;
    // 80132FF4: bl      0x8019A70C
    {
            ctx->lr = 0x80132FF8u;
            ctx->pc = 0x8019A70Cu;
            return;
    }

label_80132FF8:
    ctx->pc = 0x80132FF8u;
    ctx->downcount -= 17;
    // 80132FF8: stw     r3, 708(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(708);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80132FFC:
    ctx->pc = 0x80132FFCu;
    // 80132FFC: lwz     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133000:
    ctx->pc = 0x80133000u;
    // 80133000: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133004:
    ctx->pc = 0x80133004u;
    // 80133004: lmw     r26, 272(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(272);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80133008:
    ctx->pc = 0x80133008u;
    // 80133008: addi    r1, r1, 296
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(296);

label_8013300C:
    ctx->pc = 0x8013300Cu;
    // 8013300C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80133010:
    ctx->pc = 0x80133010u;
    ctx->downcount -= 17;
    // 80133010: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80133014:
    ctx->pc = 0x80133014u;
    // 80133014: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133018:
    ctx->pc = 0x80133018u;
    // 80133018: stmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8013301C:
    ctx->pc = 0x8013301Cu;
    // 8013301C: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133020:
    ctx->pc = 0x80133020u;
    // 80133020: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80133024:
    ctx->pc = 0x80133024u;
    // 80133024: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80133028:
    ctx->pc = 0x80133028u;
    // 80133028: bl      0x8019D2B0
    {
            ctx->lr = 0x8013302Cu;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_8013302C:
    ctx->pc = 0x8013302Cu;
    ctx->downcount -= 3;
    // 8013302C: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80133030:
    ctx->pc = 0x80133030u;
    // 80133030: cmpwi   r30, 0
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

label_80133034:
    ctx->pc = 0x80133034u;
    // 80133034: bc    4, 2, 0x801330A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801330A4;
        }
    }

label_80133038:
    ctx->pc = 0x80133038u;
    ctx->downcount -= 8;
    // 80133038: addi    r9, r31, 740
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(740);

label_8013303C:
    ctx->pc = 0x8013303Cu;
    // 8013303C: lwz     r11, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80133040:
    ctx->pc = 0x80133040u;
    // 80133040: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133044:
    ctx->pc = 0x80133044u;
    // 80133044: or   r27, r9, r9
    {
        ctx->gpr[27] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80133048:
    ctx->pc = 0x80133048u;
    // 80133048: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8013304C:
    ctx->pc = 0x8013304Cu;
    // 8013304C: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80133050:
    ctx->pc = 0x80133050u;
    // 80133050: rlwinm. r9, r0, 30, 2, 31
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

label_80133054:
    ctx->pc = 0x80133054u;
    // 80133054: bc    12, 2, 0x8013310C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013310C;
        }
    }

label_80133058:
    ctx->pc = 0x80133058u;
    ctx->downcount -= 2;
    // 80133058: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_8013305C:
    ctx->pc = 0x8013305Cu;
    // 8013305C: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80133060:
    ctx->pc = 0x80133060u;
    ctx->downcount -= 4;
    // 80133060: lwz     r9, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133064:
    ctx->pc = 0x80133064u;
    // 80133064: lwzx    r4, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80133068:
    // 80133068: cmpwi   r4, 0
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

label_8013306C:
    // 8013306C: bc    12, 2, 0x80133080
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133080;
        }
    }

label_80133070:
    ctx->downcount -= 2;
    // 80133070: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80133074:
    // 80133074: bl      0x8019AC1C
    {
            ctx->lr = 0x80133078u;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_80133078:
    ctx->pc = 0x80133078u;
    ctx->downcount -= 2;
    // 80133078: lwz     r9, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013307C:
    ctx->pc = 0x8013307Cu;
    // 8013307C: stwx    r26, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80133080:
    ctx->pc = 0x80133080u;
    ctx->downcount -= 8;
    // 80133080: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133084:
    // 80133084: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_80133088:
    ctx->pc = 0x80133088u;
    // 80133088: lwz     r9, 740(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(740);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013308C:
    // 8013308C: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_80133090:
    // 80133090: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80133094:
    // 80133094: srawi r0, r0, 2
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

label_80133098:
    // 80133098: cmplw   r29, r0
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

label_8013309C:
    // 8013309C: bc    12, 0, 0x80133060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133060u;
                return;
            }
            goto label_80133060;
        }
    }

label_801330A0:
    ctx->pc = 0x801330A0u;
    ctx->downcount -= 1;
    // 801330A0: b       0x8013310C
    {
            goto label_8013310C;
    }

label_801330A4:
    ctx->pc = 0x801330A4u;
    ctx->downcount -= 8;
    // 801330A4: addi    r9, r31, 756
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(756);

label_801330A8:
    ctx->pc = 0x801330A8u;
    // 801330A8: lwz     r11, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801330AC:
    ctx->pc = 0x801330ACu;
    // 801330AC: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801330B0:
    ctx->pc = 0x801330B0u;
    // 801330B0: or   r27, r9, r9
    {
        ctx->gpr[27] = ctx->gpr[9] | ctx->gpr[9];
    }

label_801330B4:
    ctx->pc = 0x801330B4u;
    // 801330B4: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801330B8:
    ctx->pc = 0x801330B8u;
    // 801330B8: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801330BC:
    ctx->pc = 0x801330BCu;
    // 801330BC: rlwinm. r9, r0, 30, 2, 31
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

label_801330C0:
    ctx->pc = 0x801330C0u;
    // 801330C0: bc    12, 2, 0x8013310C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013310C;
        }
    }

label_801330C4:
    ctx->pc = 0x801330C4u;
    ctx->downcount -= 2;
    // 801330C4: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_801330C8:
    ctx->pc = 0x801330C8u;
    // 801330C8: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801330CC:
    ctx->pc = 0x801330CCu;
    ctx->downcount -= 4;
    // 801330CC: lwz     r9, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801330D0:
    ctx->pc = 0x801330D0u;
    // 801330D0: lwzx    r4, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801330D4:
    // 801330D4: cmpwi   r4, 0
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

label_801330D8:
    // 801330D8: bc    12, 2, 0x801330EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801330EC;
        }
    }

label_801330DC:
    ctx->downcount -= 2;
    // 801330DC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801330E0:
    // 801330E0: bl      0x8019AC1C
    {
            ctx->lr = 0x801330E4u;
            ctx->pc = 0x8019AC1Cu;
            return;
    }

label_801330E4:
    ctx->pc = 0x801330E4u;
    ctx->downcount -= 2;
    // 801330E4: lwz     r9, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801330E8:
    ctx->pc = 0x801330E8u;
    // 801330E8: stwx    r26, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_801330EC:
    ctx->pc = 0x801330ECu;
    ctx->downcount -= 8;
    // 801330EC: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801330F0:
    // 801330F0: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_801330F4:
    ctx->pc = 0x801330F4u;
    // 801330F4: lwz     r9, 756(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801330F8:
    // 801330F8: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_801330FC:
    // 801330FC: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80133100:
    // 80133100: srawi r0, r0, 2
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

label_80133104:
    // 80133104: cmplw   r29, r0
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

label_80133108:
    // 80133108: bc    12, 0, 0x801330CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801330CCu;
                return;
            }
            goto label_801330CC;
        }
    }

label_8013310C:
    ctx->pc = 0x8013310Cu;
    ctx->downcount -= 16;
    // 8013310C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133110:
    ctx->pc = 0x80133110u;
    // 80133110: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133114:
    ctx->pc = 0x80133114u;
    // 80133114: lmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80133118:
    ctx->pc = 0x80133118u;
    // 80133118: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8013311C:
    ctx->pc = 0x8013311Cu;
    // 8013311C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80133120:
    ctx->pc = 0x80133120u;
    ctx->downcount -= 16;
    // 80133120: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80133124:
    ctx->pc = 0x80133124u;
    // 80133124: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133128:
    ctx->pc = 0x80133128u;
    // 80133128: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8013312C:
    ctx->pc = 0x8013312Cu;
    // 8013312C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133130:
    ctx->pc = 0x80133130u;
    // 80133130: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80133134:
    ctx->pc = 0x80133134u;
    // 80133134: bl      0x80134A34
    {
            ctx->lr = 0x80133138u;
            ctx->pc = 0x80134A34u;
            return;
    }

label_80133138:
    ctx->pc = 0x80133138u;
    ctx->downcount -= 2;
    // 80133138: cmpwi   r3, 0
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

label_8013313C:
    ctx->pc = 0x8013313Cu;
    // 8013313C: bc    12, 2, 0x8013321C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013321C;
        }
    }

label_80133140:
    ctx->pc = 0x80133140u;
    ctx->downcount -= 4;
    // 80133140: lwz     r11, 792(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80133144:
    ctx->pc = 0x80133144u;
    // 80133144: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133148:
    ctx->pc = 0x80133148u;
    // 80133148: cmpwi   r0, 0
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

label_8013314C:
    ctx->pc = 0x8013314Cu;
    // 8013314C: bc    12, 2, 0x8013316C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013316C;
        }
    }

label_80133150:
    ctx->pc = 0x80133150u;
    ctx->downcount -= 8;
    // 80133150: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133154:
    ctx->pc = 0x80133154u;
    // 80133154: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80133158:
    ctx->pc = 0x80133158u;
    // 80133158: lha     r3, 160(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(160);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8013315C:
    ctx->pc = 0x8013315Cu;
    // 8013315C: lwz     r0, 164(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(164);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133160:
    ctx->pc = 0x80133160u;
    // 80133160: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80133164:
    ctx->pc = 0x80133164u;
    // 80133164: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133168:
    ctx->pc = 0x80133168u;
    // 80133168: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013316Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013316C:
    ctx->pc = 0x8013316Cu;
    ctx->downcount -= 4;
    // 8013316C: lwz     r11, 796(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(796);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80133170:
    ctx->pc = 0x80133170u;
    // 80133170: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133174:
    ctx->pc = 0x80133174u;
    // 80133174: cmpwi   r0, 0
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

label_80133178:
    ctx->pc = 0x80133178u;
    // 80133178: bc    12, 2, 0x80133198
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133198;
        }
    }

label_8013317C:
    ctx->pc = 0x8013317Cu;
    ctx->downcount -= 8;
    // 8013317C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133180:
    ctx->pc = 0x80133180u;
    // 80133180: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80133184:
    ctx->pc = 0x80133184u;
    // 80133184: lha     r3, 160(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(160);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133188:
    ctx->pc = 0x80133188u;
    // 80133188: lwz     r0, 164(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(164);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013318C:
    ctx->pc = 0x8013318Cu;
    // 8013318C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80133190:
    ctx->pc = 0x80133190u;
    // 80133190: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133194:
    ctx->pc = 0x80133194u;
    // 80133194: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80133198u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80133198:
    ctx->pc = 0x80133198u;
    ctx->downcount -= 3;
    // 80133198: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8013319C:
    ctx->pc = 0x8013319Cu;
    // 8013319C: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801331A0:
    ctx->pc = 0x801331A0u;
    // 801331A0: cmpwi   r29, 2
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801331A4:
    ctx->downcount -= 1;
    // 801331A4: bc    12, 2, 0x80133208
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133208;
        }
    }

label_801331A8:
    ctx->pc = 0x801331A8u;
    ctx->downcount -= 5;
    // 801331A8: lwz     r9, 808(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801331AC:
    ctx->pc = 0x801331ACu;
    // 801331AC: lwzx    r11, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801331B0:
    ctx->pc = 0x801331B0u;
    // 801331B0: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801331B4:
    // 801331B4: cmpwi   r0, 0
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

label_801331B8:
    // 801331B8: bc    12, 2, 0x801331D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801331D8;
        }
    }

label_801331BC:
    ctx->pc = 0x801331BCu;
    ctx->downcount -= 8;
    // 801331BC: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801331C0:
    // 801331C0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801331C4:
    ctx->pc = 0x801331C4u;
    // 801331C4: lha     r3, 160(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(160);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801331C8:
    ctx->pc = 0x801331C8u;
    // 801331C8: lwz     r0, 164(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(164);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801331CC:
    // 801331CC: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801331D0:
    ctx->pc = 0x801331D0u;
    // 801331D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801331D4:
    ctx->pc = 0x801331D4u;
    // 801331D4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801331D8u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801331D8:
    ctx->pc = 0x801331D8u;
    ctx->downcount -= 5;
    // 801331D8: lwz     r9, 828(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(828);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801331DC:
    ctx->pc = 0x801331DCu;
    // 801331DC: lwzx    r11, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801331E0:
    ctx->pc = 0x801331E0u;
    // 801331E0: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801331E4:
    // 801331E4: cmpwi   r0, 0
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

label_801331E8:
    // 801331E8: bc    12, 2, 0x80133208
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133208;
        }
    }

label_801331EC:
    ctx->pc = 0x801331ECu;
    ctx->downcount -= 8;
    // 801331EC: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801331F0:
    // 801331F0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801331F4:
    ctx->pc = 0x801331F4u;
    // 801331F4: lha     r3, 160(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(160);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801331F8:
    ctx->pc = 0x801331F8u;
    // 801331F8: lwz     r0, 164(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(164);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801331FC:
    // 801331FC: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80133200:
    ctx->pc = 0x80133200u;
    // 80133200: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133204:
    ctx->pc = 0x80133204u;
    // 80133204: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80133208u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80133208:
    ctx->downcount -= 4;
    // 80133208: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_8013320C:
    // 8013320C: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_80133210:
    // 80133210: cmpwi   r29, 2
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80133214:
    // 80133214: bc    4, 1, 0x801331A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801331A4u;
                return;
            }
            goto label_801331A4;
        }
    }

label_80133218:
    ctx->pc = 0x80133218u;
    ctx->downcount -= 1;
    // 80133218: b       0x801332F4
    {
            goto label_801332F4;
    }

label_8013321C:
    ctx->pc = 0x8013321Cu;
    ctx->downcount -= 4;
    // 8013321C: lwz     r11, 792(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(792);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80133220:
    ctx->pc = 0x80133220u;
    // 80133220: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133224:
    ctx->pc = 0x80133224u;
    // 80133224: cmpwi   r0, 0
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

label_80133228:
    ctx->pc = 0x80133228u;
    // 80133228: bc    4, 2, 0x80133248
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80133248;
        }
    }

label_8013322C:
    ctx->pc = 0x8013322Cu;
    ctx->downcount -= 8;
    // 8013322C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133230:
    ctx->pc = 0x80133230u;
    // 80133230: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80133234:
    ctx->pc = 0x80133234u;
    // 80133234: lha     r3, 152(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(152);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133238:
    ctx->pc = 0x80133238u;
    // 80133238: lwz     r0, 156(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013323C:
    ctx->pc = 0x8013323Cu;
    // 8013323C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80133240:
    ctx->pc = 0x80133240u;
    // 80133240: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133244:
    ctx->pc = 0x80133244u;
    // 80133244: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80133248u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80133248:
    ctx->pc = 0x80133248u;
    ctx->downcount -= 4;
    // 80133248: lwz     r11, 796(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(796);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8013324C:
    ctx->pc = 0x8013324Cu;
    // 8013324C: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133250:
    ctx->pc = 0x80133250u;
    // 80133250: cmpwi   r0, 0
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

label_80133254:
    ctx->pc = 0x80133254u;
    // 80133254: bc    4, 2, 0x80133274
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80133274;
        }
    }

label_80133258:
    ctx->pc = 0x80133258u;
    ctx->downcount -= 8;
    // 80133258: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013325C:
    ctx->pc = 0x8013325Cu;
    // 8013325C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80133260:
    ctx->pc = 0x80133260u;
    // 80133260: lha     r3, 152(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(152);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133264:
    ctx->pc = 0x80133264u;
    // 80133264: lwz     r0, 156(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133268:
    ctx->pc = 0x80133268u;
    // 80133268: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8013326C:
    ctx->pc = 0x8013326Cu;
    // 8013326C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133270:
    ctx->pc = 0x80133270u;
    // 80133270: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80133274u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80133274:
    ctx->pc = 0x80133274u;
    ctx->downcount -= 3;
    // 80133274: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80133278:
    ctx->pc = 0x80133278u;
    // 80133278: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8013327C:
    ctx->pc = 0x8013327Cu;
    // 8013327C: cmpwi   r29, 2
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80133280:
    ctx->downcount -= 1;
    // 80133280: bc    12, 2, 0x801332E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801332E4;
        }
    }

label_80133284:
    ctx->pc = 0x80133284u;
    ctx->downcount -= 5;
    // 80133284: lwz     r9, 808(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133288:
    ctx->pc = 0x80133288u;
    // 80133288: lwzx    r11, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8013328C:
    ctx->pc = 0x8013328Cu;
    // 8013328C: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133290:
    // 80133290: cmpwi   r0, 0
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

label_80133294:
    // 80133294: bc    4, 2, 0x801332B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801332B4;
        }
    }

label_80133298:
    ctx->pc = 0x80133298u;
    ctx->downcount -= 8;
    // 80133298: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013329C:
    // 8013329C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801332A0:
    ctx->pc = 0x801332A0u;
    // 801332A0: lha     r3, 152(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(152);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801332A4:
    ctx->pc = 0x801332A4u;
    // 801332A4: lwz     r0, 156(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801332A8:
    // 801332A8: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801332AC:
    ctx->pc = 0x801332ACu;
    // 801332AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801332B0:
    ctx->pc = 0x801332B0u;
    // 801332B0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801332B4u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801332B4:
    ctx->pc = 0x801332B4u;
    ctx->downcount -= 5;
    // 801332B4: lwz     r9, 828(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(828);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801332B8:
    ctx->pc = 0x801332B8u;
    // 801332B8: lwzx    r11, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801332BC:
    ctx->pc = 0x801332BCu;
    // 801332BC: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801332C0:
    // 801332C0: cmpwi   r0, 0
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

label_801332C4:
    // 801332C4: bc    4, 2, 0x801332E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801332E4;
        }
    }

label_801332C8:
    ctx->pc = 0x801332C8u;
    ctx->downcount -= 8;
    // 801332C8: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801332CC:
    // 801332CC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801332D0:
    ctx->pc = 0x801332D0u;
    // 801332D0: lha     r3, 152(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(152);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801332D4:
    ctx->pc = 0x801332D4u;
    // 801332D4: lwz     r0, 156(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801332D8:
    // 801332D8: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801332DC:
    ctx->pc = 0x801332DCu;
    // 801332DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801332E0:
    ctx->pc = 0x801332E0u;
    // 801332E0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801332E4u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801332E4:
    ctx->downcount -= 4;
    // 801332E4: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_801332E8:
    // 801332E8: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_801332EC:
    // 801332EC: cmpwi   r29, 2
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801332F0:
    // 801332F0: bc    4, 1, 0x80133280
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133280u;
                return;
            }
            goto label_80133280;
        }
    }

label_801332F4:
    ctx->pc = 0x801332F4u;
    ctx->downcount -= 2;
    // 801332F4: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801332F8:
    ctx->pc = 0x801332F8u;
    // 801332F8: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801332FC:
    ctx->pc = 0x801332FCu;
    ctx->downcount -= 3;
    // 801332FC: lwz     r0, 724(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(724);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133300:
    // 80133300: cmpw    r0, r29
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80133304:
    // 80133304: bc    4, 2, 0x8013337C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013337C;
        }
    }

label_80133308:
    ctx->pc = 0x80133308u;
    ctx->downcount -= 5;
    // 80133308: lwz     r9, 808(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013330C:
    ctx->pc = 0x8013330Cu;
    // 8013330C: lwzx    r11, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80133310:
    ctx->pc = 0x80133310u;
    // 80133310: lwz     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133314:
    // 80133314: cmpwi   r0, 0
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

label_80133318:
    // 80133318: bc    4, 2, 0x80133340
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80133340;
        }
    }

label_8013331C:
    ctx->pc = 0x8013331Cu;
    ctx->downcount -= 10;
    // 8013331C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133320:
    // 80133320: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80133324:
    // 80133324: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80133328:
    // 80133328: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8013332C:
    ctx->pc = 0x8013332Cu;
    // 8013332C: lha     r3, 120(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(120);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133330:
    ctx->pc = 0x80133330u;
    // 80133330: lwz     r0, 124(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133334:
    // 80133334: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80133338:
    ctx->pc = 0x80133338u;
    // 80133338: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013333C:
    ctx->pc = 0x8013333Cu;
    // 8013333C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80133340u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80133340:
    ctx->pc = 0x80133340u;
    ctx->downcount -= 5;
    // 80133340: lwz     r9, 828(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(828);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133344:
    ctx->pc = 0x80133344u;
    // 80133344: lwzx    r11, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80133348:
    ctx->pc = 0x80133348u;
    // 80133348: lwz     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013334C:
    // 8013334C: cmpwi   r0, 0
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

label_80133350:
    // 80133350: bc    4, 2, 0x801333DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801333DC;
        }
    }

label_80133354:
    ctx->pc = 0x80133354u;
    ctx->downcount -= 10;
    // 80133354: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133358:
    // 80133358: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8013335C:
    // 8013335C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80133360:
    // 80133360: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80133364:
    ctx->pc = 0x80133364u;
    // 80133364: lha     r3, 120(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(120);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133368:
    ctx->pc = 0x80133368u;
    // 80133368: lwz     r0, 124(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013336C:
    // 8013336C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80133370:
    ctx->pc = 0x80133370u;
    // 80133370: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133374:
    ctx->pc = 0x80133374u;
    // 80133374: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80133378u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80133378:
    ctx->downcount -= 1;
    // 80133378: b       0x801333DC
    {
            goto label_801333DC;
    }

label_8013337C:
    ctx->pc = 0x8013337Cu;
    ctx->downcount -= 5;
    // 8013337C: lwz     r9, 808(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133380:
    ctx->pc = 0x80133380u;
    // 80133380: lwzx    r11, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80133384:
    ctx->pc = 0x80133384u;
    // 80133384: lwz     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133388:
    // 80133388: cmpwi   r0, 0
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

label_8013338C:
    // 8013338C: bc    12, 2, 0x801333AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801333AC;
        }
    }

label_80133390:
    ctx->pc = 0x80133390u;
    ctx->downcount -= 8;
    // 80133390: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133394:
    // 80133394: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80133398:
    ctx->pc = 0x80133398u;
    // 80133398: lha     r3, 128(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(128);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8013339C:
    ctx->pc = 0x8013339Cu;
    // 8013339C: lwz     r0, 132(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801333A0:
    // 801333A0: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801333A4:
    ctx->pc = 0x801333A4u;
    // 801333A4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801333A8:
    ctx->pc = 0x801333A8u;
    // 801333A8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801333ACu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801333AC:
    ctx->pc = 0x801333ACu;
    ctx->downcount -= 5;
    // 801333AC: lwz     r9, 828(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(828);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801333B0:
    ctx->pc = 0x801333B0u;
    // 801333B0: lwzx    r11, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801333B4:
    ctx->pc = 0x801333B4u;
    // 801333B4: lwz     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801333B8:
    // 801333B8: cmpwi   r0, 0
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

label_801333BC:
    // 801333BC: bc    12, 2, 0x801333DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801333DC;
        }
    }

label_801333C0:
    ctx->pc = 0x801333C0u;
    ctx->downcount -= 8;
    // 801333C0: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801333C4:
    // 801333C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801333C8:
    ctx->pc = 0x801333C8u;
    // 801333C8: lha     r3, 128(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(128);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801333CC:
    ctx->pc = 0x801333CCu;
    // 801333CC: lwz     r0, 132(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801333D0:
    // 801333D0: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801333D4:
    ctx->pc = 0x801333D4u;
    // 801333D4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801333D8:
    ctx->pc = 0x801333D8u;
    // 801333D8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801333DCu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801333DC:
    ctx->downcount -= 4;
    // 801333DC: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_801333E0:
    // 801333E0: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_801333E4:
    // 801333E4: cmpwi   r29, 2
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801333E8:
    // 801333E8: bc    4, 1, 0x801332FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801332FCu;
                return;
            }
            goto label_801332FC;
        }
    }

label_801333EC:
    ctx->pc = 0x801333ECu;
    ctx->downcount -= 16;
    // 801333EC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801333F0:
    ctx->pc = 0x801333F0u;
    // 801333F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801333F4:
    ctx->pc = 0x801333F4u;
    // 801333F4: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801333F8:
    ctx->pc = 0x801333F8u;
    // 801333F8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801333FC:
    ctx->pc = 0x801333FCu;
    // 801333FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80133400:
    ctx->pc = 0x80133400u;
    ctx->downcount -= 8;
    // 80133400: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80133404:
    ctx->pc = 0x80133404u;
    // 80133404: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133408:
    ctx->pc = 0x80133408u;
    // 80133408: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8013340C:
    ctx->pc = 0x8013340Cu;
    // 8013340C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133410:
    ctx->pc = 0x80133410u;
    // 80133410: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80133414:
    ctx->pc = 0x80133414u;
    // 80133414: lwz     r0, 732(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(732);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133418:
    ctx->pc = 0x80133418u;
    // 80133418: cmpwi   r0, 1
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

label_8013341C:
    ctx->pc = 0x8013341Cu;
    // 8013341C: bc    4, 2, 0x8013347C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013347C;
        }
    }

label_80133420:
    ctx->pc = 0x80133420u;
    ctx->downcount -= 4;
    // 80133420: lwz     r11, 848(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(848);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80133424:
    ctx->pc = 0x80133424u;
    // 80133424: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133428:
    ctx->pc = 0x80133428u;
    // 80133428: cmpwi   r0, 0
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

label_8013342C:
    ctx->pc = 0x8013342Cu;
    // 8013342C: bc    4, 2, 0x8013344C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013344C;
        }
    }

label_80133430:
    ctx->pc = 0x80133430u;
    ctx->downcount -= 8;
    // 80133430: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133434:
    ctx->pc = 0x80133434u;
    // 80133434: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80133438:
    ctx->pc = 0x80133438u;
    // 80133438: lha     r3, 152(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(152);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8013343C:
    ctx->pc = 0x8013343Cu;
    // 8013343C: lwz     r0, 156(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133440:
    ctx->pc = 0x80133440u;
    // 80133440: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80133444:
    ctx->pc = 0x80133444u;
    // 80133444: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133448:
    ctx->pc = 0x80133448u;
    // 80133448: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8013344Cu;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_8013344C:
    ctx->pc = 0x8013344Cu;
    ctx->downcount -= 4;
    // 8013344C: lwz     r11, 852(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(852);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80133450:
    ctx->pc = 0x80133450u;
    // 80133450: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133454:
    ctx->pc = 0x80133454u;
    // 80133454: cmpwi   r0, 0
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

label_80133458:
    ctx->pc = 0x80133458u;
    // 80133458: bc    4, 2, 0x801334D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x801334D4u;
            return;
        }
    }

label_8013345C:
    ctx->pc = 0x8013345Cu;
    ctx->downcount -= 8;
    // 8013345C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133460:
    ctx->pc = 0x80133460u;
    // 80133460: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80133464:
    ctx->pc = 0x80133464u;
    // 80133464: lha     r3, 152(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(152);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133468:
    ctx->pc = 0x80133468u;
    // 80133468: lwz     r0, 156(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013346C:
    ctx->pc = 0x8013346Cu;
    // 8013346C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80133470:
    ctx->pc = 0x80133470u;
    // 80133470: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133474:
    ctx->pc = 0x80133474u;
    // 80133474: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80133478u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_80133478:
    ctx->pc = 0x80133478u;
    ctx->downcount -= 1;
    // 80133478: b       0x801334D4
    {
            ctx->pc = 0x801334D4u;
            return;
    }

label_8013347C:
    ctx->pc = 0x8013347Cu;
    ctx->downcount -= 4;
    // 8013347C: lwz     r11, 848(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(848);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80133480:
    ctx->pc = 0x80133480u;
    // 80133480: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133484:
    ctx->pc = 0x80133484u;
    // 80133484: cmpwi   r0, 0
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

label_80133488:
    ctx->pc = 0x80133488u;
    // 80133488: bc    12, 2, 0x801334A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801334A8;
        }
    }

label_8013348C:
    ctx->pc = 0x8013348Cu;
    ctx->downcount -= 8;
    // 8013348C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133490:
    ctx->pc = 0x80133490u;
    // 80133490: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80133494:
    ctx->pc = 0x80133494u;
    // 80133494: lha     r3, 160(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(160);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133498:
    ctx->pc = 0x80133498u;
    // 80133498: lwz     r0, 164(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(164);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013349C:
    ctx->pc = 0x8013349Cu;
    // 8013349C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801334A0:
    ctx->pc = 0x801334A0u;
    // 801334A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801334A4:
    ctx->pc = 0x801334A4u;
    // 801334A4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801334A8u;
            ctx->pc = target;
            goto return_dispatch_8012F4C0;
        }
    }

label_801334A8:
    ctx->pc = 0x801334A8u;
    ctx->downcount -= 4;
    // 801334A8: lwz     r11, 852(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(852);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801334AC:
    ctx->pc = 0x801334ACu;
    // 801334AC: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801334B0:
    ctx->pc = 0x801334B0u;
    // 801334B0: cmpwi   r0, 0
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

label_801334B4:
    ctx->pc = 0x801334B4u;
    // 801334B4: bc    12, 2, 0x801334D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x801334D4u;
            return;
        }
    }

label_801334B8:
    ctx->pc = 0x801334B8u;
    ctx->downcount -= 2;
    // 801334B8: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801334BC:
    ctx->pc = 0x801334BCu;
    // 801334BC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

    ctx->pc = 0x801334C0u;
    return;
return_dispatch_8012F4C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x8012F538u: goto label_8012F538;
    case 0x8012F5B4u: goto label_8012F5B4;
    case 0x8012F5C4u: goto label_8012F5C4;
    case 0x8012F5F0u: goto label_8012F5F0;
    case 0x8012F638u: goto label_8012F638;
    case 0x8012F66Cu: goto label_8012F66C;
    case 0x8012F674u: goto label_8012F674;
    case 0x8012F700u: goto label_8012F700;
    case 0x8012F710u: goto label_8012F710;
    case 0x8012F738u: goto label_8012F738;
    case 0x8012F760u: goto label_8012F760;
    case 0x8012F768u: goto label_8012F768;
    case 0x8012F79Cu: goto label_8012F79C;
    case 0x8012F7C0u: goto label_8012F7C0;
    case 0x8012F7F0u: goto label_8012F7F0;
    case 0x8012F84Cu: goto label_8012F84C;
    case 0x8012F860u: goto label_8012F860;
    case 0x8012F874u: goto label_8012F874;
    case 0x8012F888u: goto label_8012F888;
    case 0x8012F89Cu: goto label_8012F89C;
    case 0x8012F8B0u: goto label_8012F8B0;
    case 0x8012F8C4u: goto label_8012F8C4;
    case 0x8012F8D8u: goto label_8012F8D8;
    case 0x8012F8ECu: goto label_8012F8EC;
    case 0x8012F900u: goto label_8012F900;
    case 0x8012F914u: goto label_8012F914;
    case 0x8012F928u: goto label_8012F928;
    case 0x8012F9A4u: goto label_8012F9A4;
    case 0x8012F9B0u: goto label_8012F9B0;
    case 0x8012F9E8u: goto label_8012F9E8;
    case 0x8012FAA8u: goto label_8012FAA8;
    case 0x8012FAECu: goto label_8012FAEC;
    case 0x8012FAF4u: goto label_8012FAF4;
    case 0x8012FB04u: goto label_8012FB04;
    case 0x8012FB0Cu: goto label_8012FB0C;
    case 0x8012FB10u: goto label_8012FB10;
    case 0x8012FB18u: goto label_8012FB18;
    case 0x8012FB28u: goto label_8012FB28;
    case 0x8012FB2Cu: goto label_8012FB2C;
    case 0x8012FB34u: goto label_8012FB34;
    case 0x8012FB3Cu: goto label_8012FB3C;
    case 0x8012FB48u: goto label_8012FB48;
    case 0x8012FB74u: goto label_8012FB74;
    case 0x8012FB7Cu: goto label_8012FB7C;
    case 0x8012FB9Cu: goto label_8012FB9C;
    case 0x8012FBDCu: goto label_8012FBDC;
    case 0x8012FBE8u: goto label_8012FBE8;
    case 0x8012FC00u: goto label_8012FC00;
    case 0x8012FC08u: goto label_8012FC08;
    case 0x8012FC14u: goto label_8012FC14;
    case 0x8012FC1Cu: goto label_8012FC1C;
    case 0x8012FC24u: goto label_8012FC24;
    case 0x8012FC30u: goto label_8012FC30;
    case 0x8012FC60u: goto label_8012FC60;
    case 0x8012FC78u: goto label_8012FC78;
    case 0x8012FCA8u: goto label_8012FCA8;
    case 0x8012FCE8u: goto label_8012FCE8;
    case 0x8012FCF8u: goto label_8012FCF8;
    case 0x8012FD10u: goto label_8012FD10;
    case 0x8012FD44u: goto label_8012FD44;
    case 0x8012FD68u: goto label_8012FD68;
    case 0x8012FD84u: goto label_8012FD84;
    case 0x8012FDB8u: goto label_8012FDB8;
    case 0x8012FE04u: goto label_8012FE04;
    case 0x8012FE34u: goto label_8012FE34;
    case 0x8012FE4Cu: goto label_8012FE4C;
    case 0x8012FE50u: goto label_8012FE50;
    case 0x8012FE64u: goto label_8012FE64;
    case 0x8012FE68u: goto label_8012FE68;
    case 0x8012FE78u: goto label_8012FE78;
    case 0x8012FEB4u: goto label_8012FEB4;
    case 0x8012FEE8u: goto label_8012FEE8;
    case 0x8012FEF8u: goto label_8012FEF8;
    case 0x8012FF04u: goto label_8012FF04;
    case 0x8012FF40u: goto label_8012FF40;
    case 0x8012FF74u: goto label_8012FF74;
    case 0x8012FF8Cu: goto label_8012FF8C;
    case 0x8012FF90u: goto label_8012FF90;
    case 0x8012FF9Cu: goto label_8012FF9C;
    case 0x8012FFACu: goto label_8012FFAC;
    case 0x8012FFECu: goto label_8012FFEC;
    case 0x8012FFF4u: goto label_8012FFF4;
    case 0x80130010u: goto label_80130010;
    case 0x80130024u: goto label_80130024;
    case 0x80130060u: goto label_80130060;
    case 0x80130080u: goto label_80130080;
    case 0x80130094u: goto label_80130094;
    case 0x801300A8u: goto label_801300A8;
    case 0x801300BCu: goto label_801300BC;
    case 0x801300D0u: goto label_801300D0;
    case 0x801300E4u: goto label_801300E4;
    case 0x801300F4u: goto label_801300F4;
    case 0x80130130u: goto label_80130130;
    case 0x80130140u: goto label_80130140;
    case 0x80130178u: goto label_80130178;
    case 0x80130180u: goto label_80130180;
    case 0x801301C4u: goto label_801301C4;
    case 0x801301D0u: goto label_801301D0;
    case 0x801301E4u: goto label_801301E4;
    case 0x801301F0u: goto label_801301F0;
    case 0x80130234u: goto label_80130234;
    case 0x80130240u: goto label_80130240;
    case 0x80130254u: goto label_80130254;
    case 0x80130260u: goto label_80130260;
    case 0x8013029Cu: goto label_8013029C;
    case 0x801302ACu: goto label_801302AC;
    case 0x801302BCu: goto label_801302BC;
    case 0x801302F8u: goto label_801302F8;
    case 0x80130308u: goto label_80130308;
    case 0x80130314u: goto label_80130314;
    case 0x80130354u: goto label_80130354;
    case 0x80130364u: goto label_80130364;
    case 0x80130374u: goto label_80130374;
    case 0x80130390u: goto label_80130390;
    case 0x8013039Cu: goto label_8013039C;
    case 0x801303B0u: goto label_801303B0;
    case 0x801303BCu: goto label_801303BC;
    case 0x801303F8u: goto label_801303F8;
    case 0x80130408u: goto label_80130408;
    case 0x80130414u: goto label_80130414;
    case 0x80130454u: goto label_80130454;
    case 0x80130464u: goto label_80130464;
    case 0x80130474u: goto label_80130474;
    case 0x80130490u: goto label_80130490;
    case 0x8013049Cu: goto label_8013049C;
    case 0x801304B0u: goto label_801304B0;
    case 0x801304BCu: goto label_801304BC;
    case 0x801304F8u: goto label_801304F8;
    case 0x80130508u: goto label_80130508;
    case 0x80130514u: goto label_80130514;
    case 0x80130550u: goto label_80130550;
    case 0x80130560u: goto label_80130560;
    case 0x80130570u: goto label_80130570;
    case 0x801305ACu: goto label_801305AC;
    case 0x801305BCu: goto label_801305BC;
    case 0x801305C8u: goto label_801305C8;
    case 0x80130608u: goto label_80130608;
    case 0x80130618u: goto label_80130618;
    case 0x80130628u: goto label_80130628;
    case 0x80130648u: goto label_80130648;
    case 0x80130654u: goto label_80130654;
    case 0x80130664u: goto label_80130664;
    case 0x80130670u: goto label_80130670;
    case 0x80130684u: goto label_80130684;
    case 0x80130690u: goto label_80130690;
    case 0x801306A0u: goto label_801306A0;
    case 0x801306ACu: goto label_801306AC;
    case 0x801306E8u: goto label_801306E8;
    case 0x801306F8u: goto label_801306F8;
    case 0x80130704u: goto label_80130704;
    case 0x80130740u: goto label_80130740;
    case 0x80130750u: goto label_80130750;
    case 0x80130760u: goto label_80130760;
    case 0x8013079Cu: goto label_8013079C;
    case 0x801307ACu: goto label_801307AC;
    case 0x801307B8u: goto label_801307B8;
    case 0x80130860u: goto label_80130860;
    case 0x80130894u: goto label_80130894;
    case 0x801308DCu: goto label_801308DC;
    case 0x80130908u: goto label_80130908;
    case 0x80130920u: goto label_80130920;
    case 0x80130988u: goto label_80130988;
    case 0x801309B4u: goto label_801309B4;
    case 0x801309E4u: goto label_801309E4;
    case 0x80130A14u: goto label_80130A14;
    case 0x80130A20u: goto label_80130A20;
    case 0x80130A38u: goto label_80130A38;
    case 0x80130AA4u: goto label_80130AA4;
    case 0x80130C60u: goto label_80130C60;
    case 0x80130C84u: goto label_80130C84;
    case 0x80130CB0u: goto label_80130CB0;
    case 0x80130CC0u: goto label_80130CC0;
    case 0x80130CDCu: goto label_80130CDC;
    case 0x80130D0Cu: goto label_80130D0C;
    case 0x80130E10u: goto label_80130E10;
    case 0x80130E60u: goto label_80130E60;
    case 0x80130EE8u: goto label_80130EE8;
    case 0x80130F9Cu: goto label_80130F9C;
    case 0x80130FB0u: goto label_80130FB0;
    case 0x80130FC4u: goto label_80130FC4;
    case 0x80130FD8u: goto label_80130FD8;
    case 0x80130FECu: goto label_80130FEC;
    case 0x80131000u: goto label_80131000;
    case 0x80131014u: goto label_80131014;
    case 0x80131028u: goto label_80131028;
    case 0x8013103Cu: goto label_8013103C;
    case 0x80131168u: goto label_80131168;
    case 0x801311C8u: goto label_801311C8;
    case 0x801311D0u: goto label_801311D0;
    case 0x8013127Cu: goto label_8013127C;
    case 0x801312B8u: goto label_801312B8;
    case 0x80131318u: goto label_80131318;
    case 0x80131330u: goto label_80131330;
    case 0x80131368u: goto label_80131368;
    case 0x80131394u: goto label_80131394;
    case 0x801313D4u: goto label_801313D4;
    case 0x801313F8u: goto label_801313F8;
    case 0x801314C0u: goto label_801314C0;
    case 0x801314FCu: goto label_801314FC;
    case 0x80131538u: goto label_80131538;
    case 0x80131594u: goto label_80131594;
    case 0x801315A0u: goto label_801315A0;
    case 0x801315ACu: goto label_801315AC;
    case 0x801315D4u: goto label_801315D4;
    case 0x801315DCu: goto label_801315DC;
    case 0x80131604u: goto label_80131604;
    case 0x8013160Cu: goto label_8013160C;
    case 0x80131634u: goto label_80131634;
    case 0x8013163Cu: goto label_8013163C;
    case 0x80131664u: goto label_80131664;
    case 0x8013166Cu: goto label_8013166C;
    case 0x80131678u: goto label_80131678;
    case 0x801316B0u: goto label_801316B0;
    case 0x801316F0u: goto label_801316F0;
    case 0x80131710u: goto label_80131710;
    case 0x8013171Cu: goto label_8013171C;
    case 0x80131728u: goto label_80131728;
    case 0x80131750u: goto label_80131750;
    case 0x80131760u: goto label_80131760;
    case 0x80131800u: goto label_80131800;
    case 0x80131828u: goto label_80131828;
    case 0x80131830u: goto label_80131830;
    case 0x80131848u: goto label_80131848;
    case 0x8013185Cu: goto label_8013185C;
    case 0x80131888u: goto label_80131888;
    case 0x80131898u: goto label_80131898;
    case 0x801318A8u: goto label_801318A8;
    case 0x801318D8u: goto label_801318D8;
    case 0x80131908u: goto label_80131908;
    case 0x8013191Cu: goto label_8013191C;
    case 0x80131934u: goto label_80131934;
    case 0x8013194Cu: goto label_8013194C;
    case 0x80131984u: goto label_80131984;
    case 0x80131990u: goto label_80131990;
    case 0x801319A0u: goto label_801319A0;
    case 0x801319B4u: goto label_801319B4;
    case 0x801319F4u: goto label_801319F4;
    case 0x80131A18u: goto label_80131A18;
    case 0x80131A20u: goto label_80131A20;
    case 0x80131A38u: goto label_80131A38;
    case 0x80131A70u: goto label_80131A70;
    case 0x80131A8Cu: goto label_80131A8C;
    case 0x80131A94u: goto label_80131A94;
    case 0x80131AACu: goto label_80131AAC;
    case 0x80131ADCu: goto label_80131ADC;
    case 0x80131AF8u: goto label_80131AF8;
    case 0x80131B00u: goto label_80131B00;
    case 0x80131B18u: goto label_80131B18;
    case 0x80131B48u: goto label_80131B48;
    case 0x80131B64u: goto label_80131B64;
    case 0x80131B6Cu: goto label_80131B6C;
    case 0x80131B84u: goto label_80131B84;
    case 0x80131BB4u: goto label_80131BB4;
    case 0x80131BD0u: goto label_80131BD0;
    case 0x80131BD8u: goto label_80131BD8;
    case 0x80131BF0u: goto label_80131BF0;
    case 0x80131C20u: goto label_80131C20;
    case 0x80131C3Cu: goto label_80131C3C;
    case 0x80131C44u: goto label_80131C44;
    case 0x80131C5Cu: goto label_80131C5C;
    case 0x80131C8Cu: goto label_80131C8C;
    case 0x80131CA8u: goto label_80131CA8;
    case 0x80131CB0u: goto label_80131CB0;
    case 0x80131CC8u: goto label_80131CC8;
    case 0x80131CF8u: goto label_80131CF8;
    case 0x80131D34u: goto label_80131D34;
    case 0x80131D78u: goto label_80131D78;
    case 0x80131D98u: goto label_80131D98;
    case 0x80131DA0u: goto label_80131DA0;
    case 0x80131DB4u: goto label_80131DB4;
    case 0x80131DF0u: goto label_80131DF0;
    case 0x80131E0Cu: goto label_80131E0C;
    case 0x80131E1Cu: goto label_80131E1C;
    case 0x80131E38u: goto label_80131E38;
    case 0x80131E40u: goto label_80131E40;
    case 0x80131E54u: goto label_80131E54;
    case 0x80131E74u: goto label_80131E74;
    case 0x80131EC8u: goto label_80131EC8;
    case 0x80131EF8u: goto label_80131EF8;
    case 0x80131F24u: goto label_80131F24;
    case 0x80131F50u: goto label_80131F50;
    case 0x80131F7Cu: goto label_80131F7C;
    case 0x80131FA8u: goto label_80131FA8;
    case 0x80131FD4u: goto label_80131FD4;
    case 0x8013202Cu: goto label_8013202C;
    case 0x8013207Cu: goto label_8013207C;
    case 0x801320A4u: goto label_801320A4;
    case 0x801320B0u: goto label_801320B0;
    case 0x801320DCu: goto label_801320DC;
    case 0x801320E8u: goto label_801320E8;
    case 0x801320F0u: goto label_801320F0;
    case 0x80132128u: goto label_80132128;
    case 0x80132134u: goto label_80132134;
    case 0x80132170u: goto label_80132170;
    case 0x80132180u: goto label_80132180;
    case 0x801321B0u: goto label_801321B0;
    case 0x801321D8u: goto label_801321D8;
    case 0x801321E8u: goto label_801321E8;
    case 0x80132218u: goto label_80132218;
    case 0x8013224Cu: goto label_8013224C;
    case 0x80132258u: goto label_80132258;
    case 0x80132268u: goto label_80132268;
    case 0x801322A4u: goto label_801322A4;
    case 0x801322CCu: goto label_801322CC;
    case 0x80132308u: goto label_80132308;
    case 0x80132318u: goto label_80132318;
    case 0x80132348u: goto label_80132348;
    case 0x80132350u: goto label_80132350;
    case 0x80132364u: goto label_80132364;
    case 0x80132394u: goto label_80132394;
    case 0x801323BCu: goto label_801323BC;
    case 0x801323CCu: goto label_801323CC;
    case 0x801323F8u: goto label_801323F8;
    case 0x80132404u: goto label_80132404;
    case 0x80132414u: goto label_80132414;
    case 0x8013243Cu: goto label_8013243C;
    case 0x80132458u: goto label_80132458;
    case 0x801324A0u: goto label_801324A0;
    case 0x801324ACu: goto label_801324AC;
    case 0x801324C4u: goto label_801324C4;
    case 0x801324D0u: goto label_801324D0;
    case 0x801324FCu: goto label_801324FC;
    case 0x8013257Cu: goto label_8013257C;
    case 0x8013258Cu: goto label_8013258C;
    case 0x801325BCu: goto label_801325BC;
    case 0x801325C8u: goto label_801325C8;
    case 0x801325D4u: goto label_801325D4;
    case 0x801325FCu: goto label_801325FC;
    case 0x80132618u: goto label_80132618;
    case 0x80132660u: goto label_80132660;
    case 0x8013266Cu: goto label_8013266C;
    case 0x80132684u: goto label_80132684;
    case 0x80132690u: goto label_80132690;
    case 0x801326BCu: goto label_801326BC;
    case 0x8013274Cu: goto label_8013274C;
    case 0x8013275Cu: goto label_8013275C;
    case 0x8013277Cu: goto label_8013277C;
    case 0x8013279Cu: goto label_8013279C;
    case 0x801327BCu: goto label_801327BC;
    case 0x801327DCu: goto label_801327DC;
    case 0x801327FCu: goto label_801327FC;
    case 0x8013281Cu: goto label_8013281C;
    case 0x8013283Cu: goto label_8013283C;
    case 0x8013286Cu: goto label_8013286C;
    case 0x8013289Cu: goto label_8013289C;
    case 0x801328C4u: goto label_801328C4;
    case 0x801328ECu: goto label_801328EC;
    case 0x8013290Cu: goto label_8013290C;
    case 0x8013292Cu: goto label_8013292C;
    case 0x8013298Cu: goto label_8013298C;
    case 0x801329A4u: goto label_801329A4;
    case 0x801329F8u: goto label_801329F8;
    case 0x80132A70u: goto label_80132A70;
    case 0x80132A80u: goto label_80132A80;
    case 0x80132A94u: goto label_80132A94;
    case 0x80132AA0u: goto label_80132AA0;
    case 0x80132AC0u: goto label_80132AC0;
    case 0x80132AD0u: goto label_80132AD0;
    case 0x80132AE4u: goto label_80132AE4;
    case 0x80132B10u: goto label_80132B10;
    case 0x80132B28u: goto label_80132B28;
    case 0x80132B40u: goto label_80132B40;
    case 0x80132B60u: goto label_80132B60;
    case 0x80132B80u: goto label_80132B80;
    case 0x80132B8Cu: goto label_80132B8C;
    case 0x80132BDCu: goto label_80132BDC;
    case 0x80132BF4u: goto label_80132BF4;
    case 0x80132C0Cu: goto label_80132C0C;
    case 0x80132C1Cu: goto label_80132C1C;
    case 0x80132C3Cu: goto label_80132C3C;
    case 0x80132C4Cu: goto label_80132C4C;
    case 0x80132C68u: goto label_80132C68;
    case 0x80132C78u: goto label_80132C78;
    case 0x80132C98u: goto label_80132C98;
    case 0x80132CA8u: goto label_80132CA8;
    case 0x80132CB4u: goto label_80132CB4;
    case 0x80132D08u: goto label_80132D08;
    case 0x80132D54u: goto label_80132D54;
    case 0x80132D90u: goto label_80132D90;
    case 0x80132DE8u: goto label_80132DE8;
    case 0x80132E54u: goto label_80132E54;
    case 0x80132E68u: goto label_80132E68;
    case 0x80132E80u: goto label_80132E80;
    case 0x80132E8Cu: goto label_80132E8C;
    case 0x80132ECCu: goto label_80132ECC;
    case 0x80132EDCu: goto label_80132EDC;
    case 0x80132F04u: goto label_80132F04;
    case 0x80132F14u: goto label_80132F14;
    case 0x80132F30u: goto label_80132F30;
    case 0x80132F40u: goto label_80132F40;
    case 0x80132F64u: goto label_80132F64;
    case 0x80132F74u: goto label_80132F74;
    case 0x80132F90u: goto label_80132F90;
    case 0x80132FA0u: goto label_80132FA0;
    case 0x80132FBCu: goto label_80132FBC;
    case 0x80132FCCu: goto label_80132FCC;
    case 0x80132FE8u: goto label_80132FE8;
    case 0x80132FF8u: goto label_80132FF8;
    case 0x8013302Cu: goto label_8013302C;
    case 0x80133078u: goto label_80133078;
    case 0x801330E4u: goto label_801330E4;
    case 0x80133138u: goto label_80133138;
    case 0x8013316Cu: goto label_8013316C;
    case 0x80133198u: goto label_80133198;
    case 0x801331D8u: goto label_801331D8;
    case 0x80133208u: goto label_80133208;
    case 0x80133248u: goto label_80133248;
    case 0x80133274u: goto label_80133274;
    case 0x801332B4u: goto label_801332B4;
    case 0x801332E4u: goto label_801332E4;
    case 0x80133340u: goto label_80133340;
    case 0x80133378u: goto label_80133378;
    case 0x801333ACu: goto label_801333AC;
    case 0x801333DCu: goto label_801333DC;
    case 0x8013344Cu: goto label_8013344C;
    case 0x80133478u: goto label_80133478;
    case 0x801334A8u: goto label_801334A8;
    default: return;
    }
}

