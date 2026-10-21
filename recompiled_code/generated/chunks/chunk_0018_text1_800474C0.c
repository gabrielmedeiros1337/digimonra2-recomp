// DolRecomp output
#include "../generated.h"

static void loop_800475B0(CPUState* ctx) {
label_800475B0:
    ctx->downcount -= 4;
    ctx->pc = 0x800475B0u;
    // 800475B0: lwz     r0, 0(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x800475B4u;
    // 800475B4: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 800475B8: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

    // 800475BC: bc    16, 0, 0x800475B0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800475B0u;
                return;
            }
            goto label_800475B0;
        }
    }

    ctx->pc = 0x800475C0u;
}

static void loop_8004780C(CPUState* ctx) {
label_8004780C:
    ctx->downcount -= 4;
    ctx->pc = 0x8004780Cu;
    // 8004780C: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80047810u;
    // 80047810: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80047814: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

    // 80047818: bc    16, 0, 0x8004780C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004780Cu;
                return;
            }
            goto label_8004780C;
        }
    }

    ctx->pc = 0x8004781Cu;
}

static void loop_80047D34(CPUState* ctx) {
label_80047D34:
    ctx->downcount -= 4;
    ctx->pc = 0x80047D34u;
    // 80047D34: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80047D38u;
    // 80047D38: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80047D3C: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

    // 80047D40: bc    16, 0, 0x80047D34
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80047D34u;
                return;
            }
            goto label_80047D34;
        }
    }

    ctx->pc = 0x80047D44u;
}

static void loop_80047E60(CPUState* ctx) {
label_80047E60:
    ctx->downcount -= 4;
    ctx->pc = 0x80047E60u;
    // 80047E60: lwz     r0, 0(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80047E64u;
    // 80047E64: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80047E68: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

    // 80047E6C: bc    16, 0, 0x80047E60
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80047E60u;
                return;
            }
            goto label_80047E60;
        }
    }

    ctx->pc = 0x80047E70u;
}

static void loop_800480BC(CPUState* ctx) {
label_800480BC:
    ctx->downcount -= 4;
    ctx->pc = 0x800480BCu;
    // 800480BC: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x800480C0u;
    // 800480C0: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 800480C4: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

    // 800480C8: bc    16, 0, 0x800480BC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800480BCu;
                return;
            }
            goto label_800480BC;
        }
    }

    ctx->pc = 0x800480CCu;
}

static void loop_800485E4(CPUState* ctx) {
label_800485E4:
    ctx->downcount -= 4;
    ctx->pc = 0x800485E4u;
    // 800485E4: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x800485E8u;
    // 800485E8: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 800485EC: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

    // 800485F0: bc    16, 0, 0x800485E4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800485E4u;
                return;
            }
            goto label_800485E4;
        }
    }

    ctx->pc = 0x800485F4u;
}

static void loop_80048710(CPUState* ctx) {
label_80048710:
    ctx->downcount -= 4;
    ctx->pc = 0x80048710u;
    // 80048710: lwz     r0, 0(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80048714u;
    // 80048714: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80048718: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

    // 8004871C: bc    16, 0, 0x80048710
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048710u;
                return;
            }
            goto label_80048710;
        }
    }

    ctx->pc = 0x80048720u;
}

static void loop_8004896C(CPUState* ctx) {
label_8004896C:
    ctx->downcount -= 4;
    ctx->pc = 0x8004896Cu;
    // 8004896C: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80048970u;
    // 80048970: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80048974: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

    // 80048978: bc    16, 0, 0x8004896C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004896Cu;
                return;
            }
            goto label_8004896C;
        }
    }

    ctx->pc = 0x8004897Cu;
}

static void loop_80048E34(CPUState* ctx) {
label_80048E34:
    ctx->downcount -= 4;
    ctx->pc = 0x80048E34u;
    // 80048E34: lwz     r9, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80048E38u;
    // 80048E38: lwzu     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

    // 80048E3C: cmpw    r0, r11
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

    // 80048E40: bc    4, 2, 0x80048E34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048E34u;
                return;
            }
            goto label_80048E34;
        }
    }

    ctx->pc = 0x80048E44u;
}

static void loop_80048EB0(CPUState* ctx) {
label_80048EB0:
    ctx->downcount -= 4;
    ctx->pc = 0x80048EB0u;
    // 80048EB0: lwz     r9, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80048EB4u;
    // 80048EB4: lwzu     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

    // 80048EB8: cmpw    r0, r10
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[10]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80048EBC: bc    4, 2, 0x80048EB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048EB0u;
                return;
            }
            goto label_80048EB0;
        }
    }

    ctx->pc = 0x80048EC0u;
}

static void loop_80048F2C(CPUState* ctx) {
label_80048F2C:
    ctx->downcount -= 4;
    ctx->pc = 0x80048F2Cu;
    // 80048F2C: lwz     r9, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80048F30u;
    // 80048F30: lwzu     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

    // 80048F34: cmpw    r0, r7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80048F38: bc    4, 2, 0x80048F2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048F2Cu;
                return;
            }
            goto label_80048F2C;
        }
    }

    ctx->pc = 0x80048F3Cu;
}

static void loop_80048FA8(CPUState* ctx) {
label_80048FA8:
    ctx->downcount -= 4;
    ctx->pc = 0x80048FA8u;
    // 80048FA8: lwz     r9, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80048FACu;
    // 80048FAC: lwzu     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

    // 80048FB0: cmpw    r0, r5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80048FB4: bc    4, 2, 0x80048FA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048FA8u;
                return;
            }
            goto label_80048FA8;
        }
    }

    ctx->pc = 0x80048FB8u;
}

void func_800474C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x800474C0u: goto label_800474C0;
    case 0x800474C4u: goto label_800474C4;
    case 0x800474C8u: goto label_800474C8;
    case 0x800474CCu: goto label_800474CC;
    case 0x800474D0u: goto label_800474D0;
    case 0x800474D4u: goto label_800474D4;
    case 0x800474D8u: goto label_800474D8;
    case 0x800474DCu: goto label_800474DC;
    case 0x800474E0u: goto label_800474E0;
    case 0x800474E4u: goto label_800474E4;
    case 0x800474E8u: goto label_800474E8;
    case 0x800474ECu: goto label_800474EC;
    case 0x800474F0u: goto label_800474F0;
    case 0x800474F4u: goto label_800474F4;
    case 0x800474F8u: goto label_800474F8;
    case 0x800474FCu: goto label_800474FC;
    case 0x80047500u: goto label_80047500;
    case 0x80047504u: goto label_80047504;
    case 0x80047508u: goto label_80047508;
    case 0x8004750Cu: goto label_8004750C;
    case 0x80047510u: goto label_80047510;
    case 0x80047514u: goto label_80047514;
    case 0x80047518u: goto label_80047518;
    case 0x8004751Cu: goto label_8004751C;
    case 0x80047520u: goto label_80047520;
    case 0x80047524u: goto label_80047524;
    case 0x80047528u: goto label_80047528;
    case 0x8004752Cu: goto label_8004752C;
    case 0x80047530u: goto label_80047530;
    case 0x80047534u: goto label_80047534;
    case 0x80047538u: goto label_80047538;
    case 0x8004753Cu: goto label_8004753C;
    case 0x80047540u: goto label_80047540;
    case 0x80047544u: goto label_80047544;
    case 0x80047548u: goto label_80047548;
    case 0x8004754Cu: goto label_8004754C;
    case 0x80047550u: goto label_80047550;
    case 0x80047554u: goto label_80047554;
    case 0x80047558u: goto label_80047558;
    case 0x8004755Cu: goto label_8004755C;
    case 0x80047560u: goto label_80047560;
    case 0x80047564u: goto label_80047564;
    case 0x80047568u: goto label_80047568;
    case 0x8004756Cu: goto label_8004756C;
    case 0x80047570u: goto label_80047570;
    case 0x80047574u: goto label_80047574;
    case 0x80047578u: goto label_80047578;
    case 0x8004757Cu: goto label_8004757C;
    case 0x80047580u: goto label_80047580;
    case 0x80047584u: goto label_80047584;
    case 0x80047588u: goto label_80047588;
    case 0x8004758Cu: goto label_8004758C;
    case 0x80047590u: goto label_80047590;
    case 0x80047594u: goto label_80047594;
    case 0x80047598u: goto label_80047598;
    case 0x8004759Cu: goto label_8004759C;
    case 0x800475A0u: goto label_800475A0;
    case 0x800475A4u: goto label_800475A4;
    case 0x800475A8u: goto label_800475A8;
    case 0x800475ACu: goto label_800475AC;
    case 0x800475B0u: goto label_800475B0;
    case 0x800475B4u: goto label_800475B4;
    case 0x800475B8u: goto label_800475B8;
    case 0x800475BCu: goto label_800475BC;
    case 0x800475C0u: goto label_800475C0;
    case 0x800475C4u: goto label_800475C4;
    case 0x800475C8u: goto label_800475C8;
    case 0x800475CCu: goto label_800475CC;
    case 0x800475D0u: goto label_800475D0;
    case 0x800475D4u: goto label_800475D4;
    case 0x800475D8u: goto label_800475D8;
    case 0x800475DCu: goto label_800475DC;
    case 0x800475E0u: goto label_800475E0;
    case 0x800475E4u: goto label_800475E4;
    case 0x800475E8u: goto label_800475E8;
    case 0x800475ECu: goto label_800475EC;
    case 0x800475F0u: goto label_800475F0;
    case 0x800475F4u: goto label_800475F4;
    case 0x800475F8u: goto label_800475F8;
    case 0x800475FCu: goto label_800475FC;
    case 0x80047600u: goto label_80047600;
    case 0x80047604u: goto label_80047604;
    case 0x80047608u: goto label_80047608;
    case 0x8004760Cu: goto label_8004760C;
    case 0x80047610u: goto label_80047610;
    case 0x80047614u: goto label_80047614;
    case 0x80047618u: goto label_80047618;
    case 0x8004761Cu: goto label_8004761C;
    case 0x80047620u: goto label_80047620;
    case 0x80047624u: goto label_80047624;
    case 0x80047628u: goto label_80047628;
    case 0x8004762Cu: goto label_8004762C;
    case 0x80047630u: goto label_80047630;
    case 0x80047634u: goto label_80047634;
    case 0x80047638u: goto label_80047638;
    case 0x8004763Cu: goto label_8004763C;
    case 0x80047640u: goto label_80047640;
    case 0x80047644u: goto label_80047644;
    case 0x80047648u: goto label_80047648;
    case 0x8004764Cu: goto label_8004764C;
    case 0x80047650u: goto label_80047650;
    case 0x80047654u: goto label_80047654;
    case 0x80047658u: goto label_80047658;
    case 0x8004765Cu: goto label_8004765C;
    case 0x80047660u: goto label_80047660;
    case 0x80047664u: goto label_80047664;
    case 0x80047668u: goto label_80047668;
    case 0x8004766Cu: goto label_8004766C;
    case 0x80047670u: goto label_80047670;
    case 0x80047674u: goto label_80047674;
    case 0x80047678u: goto label_80047678;
    case 0x8004767Cu: goto label_8004767C;
    case 0x80047680u: goto label_80047680;
    case 0x80047684u: goto label_80047684;
    case 0x80047688u: goto label_80047688;
    case 0x8004768Cu: goto label_8004768C;
    case 0x80047690u: goto label_80047690;
    case 0x80047694u: goto label_80047694;
    case 0x80047698u: goto label_80047698;
    case 0x8004769Cu: goto label_8004769C;
    case 0x800476A0u: goto label_800476A0;
    case 0x800476A4u: goto label_800476A4;
    case 0x800476A8u: goto label_800476A8;
    case 0x800476ACu: goto label_800476AC;
    case 0x800476B0u: goto label_800476B0;
    case 0x800476B4u: goto label_800476B4;
    case 0x800476B8u: goto label_800476B8;
    case 0x800476BCu: goto label_800476BC;
    case 0x800476C0u: goto label_800476C0;
    case 0x800476C4u: goto label_800476C4;
    case 0x800476C8u: goto label_800476C8;
    case 0x800476CCu: goto label_800476CC;
    case 0x800476D0u: goto label_800476D0;
    case 0x800476D4u: goto label_800476D4;
    case 0x800476D8u: goto label_800476D8;
    case 0x800476DCu: goto label_800476DC;
    case 0x800476E0u: goto label_800476E0;
    case 0x800476E4u: goto label_800476E4;
    case 0x800476E8u: goto label_800476E8;
    case 0x800476ECu: goto label_800476EC;
    case 0x800476F0u: goto label_800476F0;
    case 0x800476F4u: goto label_800476F4;
    case 0x800476F8u: goto label_800476F8;
    case 0x800476FCu: goto label_800476FC;
    case 0x80047700u: goto label_80047700;
    case 0x80047704u: goto label_80047704;
    case 0x80047708u: goto label_80047708;
    case 0x8004770Cu: goto label_8004770C;
    case 0x80047710u: goto label_80047710;
    case 0x80047714u: goto label_80047714;
    case 0x80047718u: goto label_80047718;
    case 0x8004771Cu: goto label_8004771C;
    case 0x80047720u: goto label_80047720;
    case 0x80047724u: goto label_80047724;
    case 0x80047728u: goto label_80047728;
    case 0x8004772Cu: goto label_8004772C;
    case 0x80047730u: goto label_80047730;
    case 0x80047734u: goto label_80047734;
    case 0x80047738u: goto label_80047738;
    case 0x8004773Cu: goto label_8004773C;
    case 0x80047740u: goto label_80047740;
    case 0x80047744u: goto label_80047744;
    case 0x80047748u: goto label_80047748;
    case 0x8004774Cu: goto label_8004774C;
    case 0x80047750u: goto label_80047750;
    case 0x80047754u: goto label_80047754;
    case 0x80047758u: goto label_80047758;
    case 0x8004775Cu: goto label_8004775C;
    case 0x80047760u: goto label_80047760;
    case 0x80047764u: goto label_80047764;
    case 0x80047768u: goto label_80047768;
    case 0x8004776Cu: goto label_8004776C;
    case 0x80047770u: goto label_80047770;
    case 0x80047774u: goto label_80047774;
    case 0x80047778u: goto label_80047778;
    case 0x8004777Cu: goto label_8004777C;
    case 0x80047780u: goto label_80047780;
    case 0x80047784u: goto label_80047784;
    case 0x80047788u: goto label_80047788;
    case 0x8004778Cu: goto label_8004778C;
    case 0x80047790u: goto label_80047790;
    case 0x80047794u: goto label_80047794;
    case 0x80047798u: goto label_80047798;
    case 0x8004779Cu: goto label_8004779C;
    case 0x800477A0u: goto label_800477A0;
    case 0x800477A4u: goto label_800477A4;
    case 0x800477A8u: goto label_800477A8;
    case 0x800477ACu: goto label_800477AC;
    case 0x800477B0u: goto label_800477B0;
    case 0x800477B4u: goto label_800477B4;
    case 0x800477B8u: goto label_800477B8;
    case 0x800477BCu: goto label_800477BC;
    case 0x800477C0u: goto label_800477C0;
    case 0x800477C4u: goto label_800477C4;
    case 0x800477C8u: goto label_800477C8;
    case 0x800477CCu: goto label_800477CC;
    case 0x800477D0u: goto label_800477D0;
    case 0x800477D4u: goto label_800477D4;
    case 0x800477D8u: goto label_800477D8;
    case 0x800477DCu: goto label_800477DC;
    case 0x800477E0u: goto label_800477E0;
    case 0x800477E4u: goto label_800477E4;
    case 0x800477E8u: goto label_800477E8;
    case 0x800477ECu: goto label_800477EC;
    case 0x800477F0u: goto label_800477F0;
    case 0x800477F4u: goto label_800477F4;
    case 0x800477F8u: goto label_800477F8;
    case 0x800477FCu: goto label_800477FC;
    case 0x80047800u: goto label_80047800;
    case 0x80047804u: goto label_80047804;
    case 0x80047808u: goto label_80047808;
    case 0x8004780Cu: goto label_8004780C;
    case 0x80047810u: goto label_80047810;
    case 0x80047814u: goto label_80047814;
    case 0x80047818u: goto label_80047818;
    case 0x8004781Cu: goto label_8004781C;
    case 0x80047820u: goto label_80047820;
    case 0x80047824u: goto label_80047824;
    case 0x80047828u: goto label_80047828;
    case 0x8004782Cu: goto label_8004782C;
    case 0x80047830u: goto label_80047830;
    case 0x80047834u: goto label_80047834;
    case 0x80047838u: goto label_80047838;
    case 0x8004783Cu: goto label_8004783C;
    case 0x80047840u: goto label_80047840;
    case 0x80047844u: goto label_80047844;
    case 0x80047848u: goto label_80047848;
    case 0x8004784Cu: goto label_8004784C;
    case 0x80047850u: goto label_80047850;
    case 0x80047854u: goto label_80047854;
    case 0x80047858u: goto label_80047858;
    case 0x8004785Cu: goto label_8004785C;
    case 0x80047860u: goto label_80047860;
    case 0x80047864u: goto label_80047864;
    case 0x80047868u: goto label_80047868;
    case 0x8004786Cu: goto label_8004786C;
    case 0x80047870u: goto label_80047870;
    case 0x80047874u: goto label_80047874;
    case 0x80047878u: goto label_80047878;
    case 0x8004787Cu: goto label_8004787C;
    case 0x80047880u: goto label_80047880;
    case 0x80047884u: goto label_80047884;
    case 0x80047888u: goto label_80047888;
    case 0x8004788Cu: goto label_8004788C;
    case 0x80047890u: goto label_80047890;
    case 0x80047894u: goto label_80047894;
    case 0x80047898u: goto label_80047898;
    case 0x8004789Cu: goto label_8004789C;
    case 0x800478A0u: goto label_800478A0;
    case 0x800478A4u: goto label_800478A4;
    case 0x800478A8u: goto label_800478A8;
    case 0x800478ACu: goto label_800478AC;
    case 0x800478B0u: goto label_800478B0;
    case 0x800478B4u: goto label_800478B4;
    case 0x800478B8u: goto label_800478B8;
    case 0x800478BCu: goto label_800478BC;
    case 0x800478C0u: goto label_800478C0;
    case 0x800478C4u: goto label_800478C4;
    case 0x800478C8u: goto label_800478C8;
    case 0x800478CCu: goto label_800478CC;
    case 0x800478D0u: goto label_800478D0;
    case 0x800478D4u: goto label_800478D4;
    case 0x800478D8u: goto label_800478D8;
    case 0x800478DCu: goto label_800478DC;
    case 0x800478E0u: goto label_800478E0;
    case 0x800478E4u: goto label_800478E4;
    case 0x800478E8u: goto label_800478E8;
    case 0x800478ECu: goto label_800478EC;
    case 0x800478F0u: goto label_800478F0;
    case 0x800478F4u: goto label_800478F4;
    case 0x800478F8u: goto label_800478F8;
    case 0x800478FCu: goto label_800478FC;
    case 0x80047900u: goto label_80047900;
    case 0x80047904u: goto label_80047904;
    case 0x80047908u: goto label_80047908;
    case 0x8004790Cu: goto label_8004790C;
    case 0x80047910u: goto label_80047910;
    case 0x80047914u: goto label_80047914;
    case 0x80047918u: goto label_80047918;
    case 0x8004791Cu: goto label_8004791C;
    case 0x80047920u: goto label_80047920;
    case 0x80047924u: goto label_80047924;
    case 0x80047928u: goto label_80047928;
    case 0x8004792Cu: goto label_8004792C;
    case 0x80047930u: goto label_80047930;
    case 0x80047934u: goto label_80047934;
    case 0x80047938u: goto label_80047938;
    case 0x8004793Cu: goto label_8004793C;
    case 0x80047940u: goto label_80047940;
    case 0x80047944u: goto label_80047944;
    case 0x80047948u: goto label_80047948;
    case 0x8004794Cu: goto label_8004794C;
    case 0x80047950u: goto label_80047950;
    case 0x80047954u: goto label_80047954;
    case 0x80047958u: goto label_80047958;
    case 0x8004795Cu: goto label_8004795C;
    case 0x80047960u: goto label_80047960;
    case 0x80047964u: goto label_80047964;
    case 0x80047968u: goto label_80047968;
    case 0x8004796Cu: goto label_8004796C;
    case 0x80047970u: goto label_80047970;
    case 0x80047974u: goto label_80047974;
    case 0x80047978u: goto label_80047978;
    case 0x8004797Cu: goto label_8004797C;
    case 0x80047980u: goto label_80047980;
    case 0x80047984u: goto label_80047984;
    case 0x80047988u: goto label_80047988;
    case 0x8004798Cu: goto label_8004798C;
    case 0x80047990u: goto label_80047990;
    case 0x80047994u: goto label_80047994;
    case 0x80047998u: goto label_80047998;
    case 0x8004799Cu: goto label_8004799C;
    case 0x800479A0u: goto label_800479A0;
    case 0x800479A4u: goto label_800479A4;
    case 0x800479A8u: goto label_800479A8;
    case 0x800479ACu: goto label_800479AC;
    case 0x800479B0u: goto label_800479B0;
    case 0x800479B4u: goto label_800479B4;
    case 0x800479B8u: goto label_800479B8;
    case 0x800479BCu: goto label_800479BC;
    case 0x800479C0u: goto label_800479C0;
    case 0x800479C4u: goto label_800479C4;
    case 0x800479C8u: goto label_800479C8;
    case 0x800479CCu: goto label_800479CC;
    case 0x800479D0u: goto label_800479D0;
    case 0x800479D4u: goto label_800479D4;
    case 0x800479D8u: goto label_800479D8;
    case 0x800479DCu: goto label_800479DC;
    case 0x800479E0u: goto label_800479E0;
    case 0x800479E4u: goto label_800479E4;
    case 0x800479E8u: goto label_800479E8;
    case 0x800479ECu: goto label_800479EC;
    case 0x800479F0u: goto label_800479F0;
    case 0x800479F4u: goto label_800479F4;
    case 0x800479F8u: goto label_800479F8;
    case 0x800479FCu: goto label_800479FC;
    case 0x80047A00u: goto label_80047A00;
    case 0x80047A04u: goto label_80047A04;
    case 0x80047A08u: goto label_80047A08;
    case 0x80047A0Cu: goto label_80047A0C;
    case 0x80047A10u: goto label_80047A10;
    case 0x80047A14u: goto label_80047A14;
    case 0x80047A18u: goto label_80047A18;
    case 0x80047A1Cu: goto label_80047A1C;
    case 0x80047A20u: goto label_80047A20;
    case 0x80047A24u: goto label_80047A24;
    case 0x80047A28u: goto label_80047A28;
    case 0x80047A2Cu: goto label_80047A2C;
    case 0x80047A30u: goto label_80047A30;
    case 0x80047A34u: goto label_80047A34;
    case 0x80047A38u: goto label_80047A38;
    case 0x80047A3Cu: goto label_80047A3C;
    case 0x80047A40u: goto label_80047A40;
    case 0x80047A44u: goto label_80047A44;
    case 0x80047A48u: goto label_80047A48;
    case 0x80047A4Cu: goto label_80047A4C;
    case 0x80047A50u: goto label_80047A50;
    case 0x80047A54u: goto label_80047A54;
    case 0x80047A58u: goto label_80047A58;
    case 0x80047A5Cu: goto label_80047A5C;
    case 0x80047A60u: goto label_80047A60;
    case 0x80047A64u: goto label_80047A64;
    case 0x80047A68u: goto label_80047A68;
    case 0x80047A6Cu: goto label_80047A6C;
    case 0x80047A70u: goto label_80047A70;
    case 0x80047A74u: goto label_80047A74;
    case 0x80047A78u: goto label_80047A78;
    case 0x80047A7Cu: goto label_80047A7C;
    case 0x80047A80u: goto label_80047A80;
    case 0x80047A84u: goto label_80047A84;
    case 0x80047A88u: goto label_80047A88;
    case 0x80047A8Cu: goto label_80047A8C;
    case 0x80047A90u: goto label_80047A90;
    case 0x80047A94u: goto label_80047A94;
    case 0x80047A98u: goto label_80047A98;
    case 0x80047A9Cu: goto label_80047A9C;
    case 0x80047AA0u: goto label_80047AA0;
    case 0x80047AA4u: goto label_80047AA4;
    case 0x80047AA8u: goto label_80047AA8;
    case 0x80047AACu: goto label_80047AAC;
    case 0x80047AB0u: goto label_80047AB0;
    case 0x80047AB4u: goto label_80047AB4;
    case 0x80047AB8u: goto label_80047AB8;
    case 0x80047ABCu: goto label_80047ABC;
    case 0x80047AC0u: goto label_80047AC0;
    case 0x80047AC4u: goto label_80047AC4;
    case 0x80047AC8u: goto label_80047AC8;
    case 0x80047ACCu: goto label_80047ACC;
    case 0x80047AD0u: goto label_80047AD0;
    case 0x80047AD4u: goto label_80047AD4;
    case 0x80047AD8u: goto label_80047AD8;
    case 0x80047ADCu: goto label_80047ADC;
    case 0x80047AE0u: goto label_80047AE0;
    case 0x80047AE4u: goto label_80047AE4;
    case 0x80047AE8u: goto label_80047AE8;
    case 0x80047AECu: goto label_80047AEC;
    case 0x80047AF0u: goto label_80047AF0;
    case 0x80047AF4u: goto label_80047AF4;
    case 0x80047AF8u: goto label_80047AF8;
    case 0x80047AFCu: goto label_80047AFC;
    case 0x80047B00u: goto label_80047B00;
    case 0x80047B04u: goto label_80047B04;
    case 0x80047B08u: goto label_80047B08;
    case 0x80047B0Cu: goto label_80047B0C;
    case 0x80047B10u: goto label_80047B10;
    case 0x80047B14u: goto label_80047B14;
    case 0x80047B18u: goto label_80047B18;
    case 0x80047B1Cu: goto label_80047B1C;
    case 0x80047B20u: goto label_80047B20;
    case 0x80047B24u: goto label_80047B24;
    case 0x80047B28u: goto label_80047B28;
    case 0x80047B2Cu: goto label_80047B2C;
    case 0x80047B30u: goto label_80047B30;
    case 0x80047B34u: goto label_80047B34;
    case 0x80047B38u: goto label_80047B38;
    case 0x80047B3Cu: goto label_80047B3C;
    case 0x80047B40u: goto label_80047B40;
    case 0x80047B44u: goto label_80047B44;
    case 0x80047B48u: goto label_80047B48;
    case 0x80047B4Cu: goto label_80047B4C;
    case 0x80047B50u: goto label_80047B50;
    case 0x80047B54u: goto label_80047B54;
    case 0x80047B58u: goto label_80047B58;
    case 0x80047B5Cu: goto label_80047B5C;
    case 0x80047B60u: goto label_80047B60;
    case 0x80047B64u: goto label_80047B64;
    case 0x80047B68u: goto label_80047B68;
    case 0x80047B6Cu: goto label_80047B6C;
    case 0x80047B70u: goto label_80047B70;
    case 0x80047B74u: goto label_80047B74;
    case 0x80047B78u: goto label_80047B78;
    case 0x80047B7Cu: goto label_80047B7C;
    case 0x80047B80u: goto label_80047B80;
    case 0x80047B84u: goto label_80047B84;
    case 0x80047B88u: goto label_80047B88;
    case 0x80047B8Cu: goto label_80047B8C;
    case 0x80047B90u: goto label_80047B90;
    case 0x80047B94u: goto label_80047B94;
    case 0x80047B98u: goto label_80047B98;
    case 0x80047B9Cu: goto label_80047B9C;
    case 0x80047BA0u: goto label_80047BA0;
    case 0x80047BA4u: goto label_80047BA4;
    case 0x80047BA8u: goto label_80047BA8;
    case 0x80047BACu: goto label_80047BAC;
    case 0x80047BB0u: goto label_80047BB0;
    case 0x80047BB4u: goto label_80047BB4;
    case 0x80047BB8u: goto label_80047BB8;
    case 0x80047BBCu: goto label_80047BBC;
    case 0x80047BC0u: goto label_80047BC0;
    case 0x80047BC4u: goto label_80047BC4;
    case 0x80047BC8u: goto label_80047BC8;
    case 0x80047BCCu: goto label_80047BCC;
    case 0x80047BD0u: goto label_80047BD0;
    case 0x80047BD4u: goto label_80047BD4;
    case 0x80047BD8u: goto label_80047BD8;
    case 0x80047BDCu: goto label_80047BDC;
    case 0x80047BE0u: goto label_80047BE0;
    case 0x80047BE4u: goto label_80047BE4;
    case 0x80047BE8u: goto label_80047BE8;
    case 0x80047BECu: goto label_80047BEC;
    case 0x80047BF0u: goto label_80047BF0;
    case 0x80047BF4u: goto label_80047BF4;
    case 0x80047BF8u: goto label_80047BF8;
    case 0x80047BFCu: goto label_80047BFC;
    case 0x80047C00u: goto label_80047C00;
    case 0x80047C04u: goto label_80047C04;
    case 0x80047C08u: goto label_80047C08;
    case 0x80047C0Cu: goto label_80047C0C;
    case 0x80047C10u: goto label_80047C10;
    case 0x80047C14u: goto label_80047C14;
    case 0x80047C18u: goto label_80047C18;
    case 0x80047C1Cu: goto label_80047C1C;
    case 0x80047C20u: goto label_80047C20;
    case 0x80047C24u: goto label_80047C24;
    case 0x80047C28u: goto label_80047C28;
    case 0x80047C2Cu: goto label_80047C2C;
    case 0x80047C30u: goto label_80047C30;
    case 0x80047C34u: goto label_80047C34;
    case 0x80047C38u: goto label_80047C38;
    case 0x80047C3Cu: goto label_80047C3C;
    case 0x80047C40u: goto label_80047C40;
    case 0x80047C44u: goto label_80047C44;
    case 0x80047C48u: goto label_80047C48;
    case 0x80047C4Cu: goto label_80047C4C;
    case 0x80047C50u: goto label_80047C50;
    case 0x80047C54u: goto label_80047C54;
    case 0x80047C58u: goto label_80047C58;
    case 0x80047C5Cu: goto label_80047C5C;
    case 0x80047C60u: goto label_80047C60;
    case 0x80047C64u: goto label_80047C64;
    case 0x80047C68u: goto label_80047C68;
    case 0x80047C6Cu: goto label_80047C6C;
    case 0x80047C70u: goto label_80047C70;
    case 0x80047C74u: goto label_80047C74;
    case 0x80047C78u: goto label_80047C78;
    case 0x80047C7Cu: goto label_80047C7C;
    case 0x80047C80u: goto label_80047C80;
    case 0x80047C84u: goto label_80047C84;
    case 0x80047C88u: goto label_80047C88;
    case 0x80047C8Cu: goto label_80047C8C;
    case 0x80047C90u: goto label_80047C90;
    case 0x80047C94u: goto label_80047C94;
    case 0x80047C98u: goto label_80047C98;
    case 0x80047C9Cu: goto label_80047C9C;
    case 0x80047CA0u: goto label_80047CA0;
    case 0x80047CA4u: goto label_80047CA4;
    case 0x80047CA8u: goto label_80047CA8;
    case 0x80047CACu: goto label_80047CAC;
    case 0x80047CB0u: goto label_80047CB0;
    case 0x80047CB4u: goto label_80047CB4;
    case 0x80047CB8u: goto label_80047CB8;
    case 0x80047CBCu: goto label_80047CBC;
    case 0x80047CC0u: goto label_80047CC0;
    case 0x80047CC4u: goto label_80047CC4;
    case 0x80047CC8u: goto label_80047CC8;
    case 0x80047CCCu: goto label_80047CCC;
    case 0x80047CD0u: goto label_80047CD0;
    case 0x80047CD4u: goto label_80047CD4;
    case 0x80047CD8u: goto label_80047CD8;
    case 0x80047CDCu: goto label_80047CDC;
    case 0x80047CE0u: goto label_80047CE0;
    case 0x80047CE4u: goto label_80047CE4;
    case 0x80047CE8u: goto label_80047CE8;
    case 0x80047CECu: goto label_80047CEC;
    case 0x80047CF0u: goto label_80047CF0;
    case 0x80047CF4u: goto label_80047CF4;
    case 0x80047CF8u: goto label_80047CF8;
    case 0x80047CFCu: goto label_80047CFC;
    case 0x80047D00u: goto label_80047D00;
    case 0x80047D04u: goto label_80047D04;
    case 0x80047D08u: goto label_80047D08;
    case 0x80047D0Cu: goto label_80047D0C;
    case 0x80047D10u: goto label_80047D10;
    case 0x80047D14u: goto label_80047D14;
    case 0x80047D18u: goto label_80047D18;
    case 0x80047D1Cu: goto label_80047D1C;
    case 0x80047D20u: goto label_80047D20;
    case 0x80047D24u: goto label_80047D24;
    case 0x80047D28u: goto label_80047D28;
    case 0x80047D2Cu: goto label_80047D2C;
    case 0x80047D30u: goto label_80047D30;
    case 0x80047D34u: goto label_80047D34;
    case 0x80047D38u: goto label_80047D38;
    case 0x80047D3Cu: goto label_80047D3C;
    case 0x80047D40u: goto label_80047D40;
    case 0x80047D44u: goto label_80047D44;
    case 0x80047D48u: goto label_80047D48;
    case 0x80047D4Cu: goto label_80047D4C;
    case 0x80047D50u: goto label_80047D50;
    case 0x80047D54u: goto label_80047D54;
    case 0x80047D58u: goto label_80047D58;
    case 0x80047D5Cu: goto label_80047D5C;
    case 0x80047D60u: goto label_80047D60;
    case 0x80047D64u: goto label_80047D64;
    case 0x80047D68u: goto label_80047D68;
    case 0x80047D6Cu: goto label_80047D6C;
    case 0x80047D70u: goto label_80047D70;
    case 0x80047D74u: goto label_80047D74;
    case 0x80047D78u: goto label_80047D78;
    case 0x80047D7Cu: goto label_80047D7C;
    case 0x80047D80u: goto label_80047D80;
    case 0x80047D84u: goto label_80047D84;
    case 0x80047D88u: goto label_80047D88;
    case 0x80047D8Cu: goto label_80047D8C;
    case 0x80047D90u: goto label_80047D90;
    case 0x80047D94u: goto label_80047D94;
    case 0x80047D98u: goto label_80047D98;
    case 0x80047D9Cu: goto label_80047D9C;
    case 0x80047DA0u: goto label_80047DA0;
    case 0x80047DA4u: goto label_80047DA4;
    case 0x80047DA8u: goto label_80047DA8;
    case 0x80047DACu: goto label_80047DAC;
    case 0x80047DB0u: goto label_80047DB0;
    case 0x80047DB4u: goto label_80047DB4;
    case 0x80047DB8u: goto label_80047DB8;
    case 0x80047DBCu: goto label_80047DBC;
    case 0x80047DC0u: goto label_80047DC0;
    case 0x80047DC4u: goto label_80047DC4;
    case 0x80047DC8u: goto label_80047DC8;
    case 0x80047DCCu: goto label_80047DCC;
    case 0x80047DD0u: goto label_80047DD0;
    case 0x80047DD4u: goto label_80047DD4;
    case 0x80047DD8u: goto label_80047DD8;
    case 0x80047DDCu: goto label_80047DDC;
    case 0x80047DE0u: goto label_80047DE0;
    case 0x80047DE4u: goto label_80047DE4;
    case 0x80047DE8u: goto label_80047DE8;
    case 0x80047DECu: goto label_80047DEC;
    case 0x80047DF0u: goto label_80047DF0;
    case 0x80047DF4u: goto label_80047DF4;
    case 0x80047DF8u: goto label_80047DF8;
    case 0x80047DFCu: goto label_80047DFC;
    case 0x80047E00u: goto label_80047E00;
    case 0x80047E04u: goto label_80047E04;
    case 0x80047E08u: goto label_80047E08;
    case 0x80047E0Cu: goto label_80047E0C;
    case 0x80047E10u: goto label_80047E10;
    case 0x80047E14u: goto label_80047E14;
    case 0x80047E18u: goto label_80047E18;
    case 0x80047E1Cu: goto label_80047E1C;
    case 0x80047E20u: goto label_80047E20;
    case 0x80047E24u: goto label_80047E24;
    case 0x80047E28u: goto label_80047E28;
    case 0x80047E2Cu: goto label_80047E2C;
    case 0x80047E30u: goto label_80047E30;
    case 0x80047E34u: goto label_80047E34;
    case 0x80047E38u: goto label_80047E38;
    case 0x80047E3Cu: goto label_80047E3C;
    case 0x80047E40u: goto label_80047E40;
    case 0x80047E44u: goto label_80047E44;
    case 0x80047E48u: goto label_80047E48;
    case 0x80047E4Cu: goto label_80047E4C;
    case 0x80047E50u: goto label_80047E50;
    case 0x80047E54u: goto label_80047E54;
    case 0x80047E58u: goto label_80047E58;
    case 0x80047E5Cu: goto label_80047E5C;
    case 0x80047E60u: goto label_80047E60;
    case 0x80047E64u: goto label_80047E64;
    case 0x80047E68u: goto label_80047E68;
    case 0x80047E6Cu: goto label_80047E6C;
    case 0x80047E70u: goto label_80047E70;
    case 0x80047E74u: goto label_80047E74;
    case 0x80047E78u: goto label_80047E78;
    case 0x80047E7Cu: goto label_80047E7C;
    case 0x80047E80u: goto label_80047E80;
    case 0x80047E84u: goto label_80047E84;
    case 0x80047E88u: goto label_80047E88;
    case 0x80047E8Cu: goto label_80047E8C;
    case 0x80047E90u: goto label_80047E90;
    case 0x80047E94u: goto label_80047E94;
    case 0x80047E98u: goto label_80047E98;
    case 0x80047E9Cu: goto label_80047E9C;
    case 0x80047EA0u: goto label_80047EA0;
    case 0x80047EA4u: goto label_80047EA4;
    case 0x80047EA8u: goto label_80047EA8;
    case 0x80047EACu: goto label_80047EAC;
    case 0x80047EB0u: goto label_80047EB0;
    case 0x80047EB4u: goto label_80047EB4;
    case 0x80047EB8u: goto label_80047EB8;
    case 0x80047EBCu: goto label_80047EBC;
    case 0x80047EC0u: goto label_80047EC0;
    case 0x80047EC4u: goto label_80047EC4;
    case 0x80047EC8u: goto label_80047EC8;
    case 0x80047ECCu: goto label_80047ECC;
    case 0x80047ED0u: goto label_80047ED0;
    case 0x80047ED4u: goto label_80047ED4;
    case 0x80047ED8u: goto label_80047ED8;
    case 0x80047EDCu: goto label_80047EDC;
    case 0x80047EE0u: goto label_80047EE0;
    case 0x80047EE4u: goto label_80047EE4;
    case 0x80047EE8u: goto label_80047EE8;
    case 0x80047EECu: goto label_80047EEC;
    case 0x80047EF0u: goto label_80047EF0;
    case 0x80047EF4u: goto label_80047EF4;
    case 0x80047EF8u: goto label_80047EF8;
    case 0x80047EFCu: goto label_80047EFC;
    case 0x80047F00u: goto label_80047F00;
    case 0x80047F04u: goto label_80047F04;
    case 0x80047F08u: goto label_80047F08;
    case 0x80047F0Cu: goto label_80047F0C;
    case 0x80047F10u: goto label_80047F10;
    case 0x80047F14u: goto label_80047F14;
    case 0x80047F18u: goto label_80047F18;
    case 0x80047F1Cu: goto label_80047F1C;
    case 0x80047F20u: goto label_80047F20;
    case 0x80047F24u: goto label_80047F24;
    case 0x80047F28u: goto label_80047F28;
    case 0x80047F2Cu: goto label_80047F2C;
    case 0x80047F30u: goto label_80047F30;
    case 0x80047F34u: goto label_80047F34;
    case 0x80047F38u: goto label_80047F38;
    case 0x80047F3Cu: goto label_80047F3C;
    case 0x80047F40u: goto label_80047F40;
    case 0x80047F44u: goto label_80047F44;
    case 0x80047F48u: goto label_80047F48;
    case 0x80047F4Cu: goto label_80047F4C;
    case 0x80047F50u: goto label_80047F50;
    case 0x80047F54u: goto label_80047F54;
    case 0x80047F58u: goto label_80047F58;
    case 0x80047F5Cu: goto label_80047F5C;
    case 0x80047F60u: goto label_80047F60;
    case 0x80047F64u: goto label_80047F64;
    case 0x80047F68u: goto label_80047F68;
    case 0x80047F6Cu: goto label_80047F6C;
    case 0x80047F70u: goto label_80047F70;
    case 0x80047F74u: goto label_80047F74;
    case 0x80047F78u: goto label_80047F78;
    case 0x80047F7Cu: goto label_80047F7C;
    case 0x80047F80u: goto label_80047F80;
    case 0x80047F84u: goto label_80047F84;
    case 0x80047F88u: goto label_80047F88;
    case 0x80047F8Cu: goto label_80047F8C;
    case 0x80047F90u: goto label_80047F90;
    case 0x80047F94u: goto label_80047F94;
    case 0x80047F98u: goto label_80047F98;
    case 0x80047F9Cu: goto label_80047F9C;
    case 0x80047FA0u: goto label_80047FA0;
    case 0x80047FA4u: goto label_80047FA4;
    case 0x80047FA8u: goto label_80047FA8;
    case 0x80047FACu: goto label_80047FAC;
    case 0x80047FB0u: goto label_80047FB0;
    case 0x80047FB4u: goto label_80047FB4;
    case 0x80047FB8u: goto label_80047FB8;
    case 0x80047FBCu: goto label_80047FBC;
    case 0x80047FC0u: goto label_80047FC0;
    case 0x80047FC4u: goto label_80047FC4;
    case 0x80047FC8u: goto label_80047FC8;
    case 0x80047FCCu: goto label_80047FCC;
    case 0x80047FD0u: goto label_80047FD0;
    case 0x80047FD4u: goto label_80047FD4;
    case 0x80047FD8u: goto label_80047FD8;
    case 0x80047FDCu: goto label_80047FDC;
    case 0x80047FE0u: goto label_80047FE0;
    case 0x80047FE4u: goto label_80047FE4;
    case 0x80047FE8u: goto label_80047FE8;
    case 0x80047FECu: goto label_80047FEC;
    case 0x80047FF0u: goto label_80047FF0;
    case 0x80047FF4u: goto label_80047FF4;
    case 0x80047FF8u: goto label_80047FF8;
    case 0x80047FFCu: goto label_80047FFC;
    case 0x80048000u: goto label_80048000;
    case 0x80048004u: goto label_80048004;
    case 0x80048008u: goto label_80048008;
    case 0x8004800Cu: goto label_8004800C;
    case 0x80048010u: goto label_80048010;
    case 0x80048014u: goto label_80048014;
    case 0x80048018u: goto label_80048018;
    case 0x8004801Cu: goto label_8004801C;
    case 0x80048020u: goto label_80048020;
    case 0x80048024u: goto label_80048024;
    case 0x80048028u: goto label_80048028;
    case 0x8004802Cu: goto label_8004802C;
    case 0x80048030u: goto label_80048030;
    case 0x80048034u: goto label_80048034;
    case 0x80048038u: goto label_80048038;
    case 0x8004803Cu: goto label_8004803C;
    case 0x80048040u: goto label_80048040;
    case 0x80048044u: goto label_80048044;
    case 0x80048048u: goto label_80048048;
    case 0x8004804Cu: goto label_8004804C;
    case 0x80048050u: goto label_80048050;
    case 0x80048054u: goto label_80048054;
    case 0x80048058u: goto label_80048058;
    case 0x8004805Cu: goto label_8004805C;
    case 0x80048060u: goto label_80048060;
    case 0x80048064u: goto label_80048064;
    case 0x80048068u: goto label_80048068;
    case 0x8004806Cu: goto label_8004806C;
    case 0x80048070u: goto label_80048070;
    case 0x80048074u: goto label_80048074;
    case 0x80048078u: goto label_80048078;
    case 0x8004807Cu: goto label_8004807C;
    case 0x80048080u: goto label_80048080;
    case 0x80048084u: goto label_80048084;
    case 0x80048088u: goto label_80048088;
    case 0x8004808Cu: goto label_8004808C;
    case 0x80048090u: goto label_80048090;
    case 0x80048094u: goto label_80048094;
    case 0x80048098u: goto label_80048098;
    case 0x8004809Cu: goto label_8004809C;
    case 0x800480A0u: goto label_800480A0;
    case 0x800480A4u: goto label_800480A4;
    case 0x800480A8u: goto label_800480A8;
    case 0x800480ACu: goto label_800480AC;
    case 0x800480B0u: goto label_800480B0;
    case 0x800480B4u: goto label_800480B4;
    case 0x800480B8u: goto label_800480B8;
    case 0x800480BCu: goto label_800480BC;
    case 0x800480C0u: goto label_800480C0;
    case 0x800480C4u: goto label_800480C4;
    case 0x800480C8u: goto label_800480C8;
    case 0x800480CCu: goto label_800480CC;
    case 0x800480D0u: goto label_800480D0;
    case 0x800480D4u: goto label_800480D4;
    case 0x800480D8u: goto label_800480D8;
    case 0x800480DCu: goto label_800480DC;
    case 0x800480E0u: goto label_800480E0;
    case 0x800480E4u: goto label_800480E4;
    case 0x800480E8u: goto label_800480E8;
    case 0x800480ECu: goto label_800480EC;
    case 0x800480F0u: goto label_800480F0;
    case 0x800480F4u: goto label_800480F4;
    case 0x800480F8u: goto label_800480F8;
    case 0x800480FCu: goto label_800480FC;
    case 0x80048100u: goto label_80048100;
    case 0x80048104u: goto label_80048104;
    case 0x80048108u: goto label_80048108;
    case 0x8004810Cu: goto label_8004810C;
    case 0x80048110u: goto label_80048110;
    case 0x80048114u: goto label_80048114;
    case 0x80048118u: goto label_80048118;
    case 0x8004811Cu: goto label_8004811C;
    case 0x80048120u: goto label_80048120;
    case 0x80048124u: goto label_80048124;
    case 0x80048128u: goto label_80048128;
    case 0x8004812Cu: goto label_8004812C;
    case 0x80048130u: goto label_80048130;
    case 0x80048134u: goto label_80048134;
    case 0x80048138u: goto label_80048138;
    case 0x8004813Cu: goto label_8004813C;
    case 0x80048140u: goto label_80048140;
    case 0x80048144u: goto label_80048144;
    case 0x80048148u: goto label_80048148;
    case 0x8004814Cu: goto label_8004814C;
    case 0x80048150u: goto label_80048150;
    case 0x80048154u: goto label_80048154;
    case 0x80048158u: goto label_80048158;
    case 0x8004815Cu: goto label_8004815C;
    case 0x80048160u: goto label_80048160;
    case 0x80048164u: goto label_80048164;
    case 0x80048168u: goto label_80048168;
    case 0x8004816Cu: goto label_8004816C;
    case 0x80048170u: goto label_80048170;
    case 0x80048174u: goto label_80048174;
    case 0x80048178u: goto label_80048178;
    case 0x8004817Cu: goto label_8004817C;
    case 0x80048180u: goto label_80048180;
    case 0x80048184u: goto label_80048184;
    case 0x80048188u: goto label_80048188;
    case 0x8004818Cu: goto label_8004818C;
    case 0x80048190u: goto label_80048190;
    case 0x80048194u: goto label_80048194;
    case 0x80048198u: goto label_80048198;
    case 0x8004819Cu: goto label_8004819C;
    case 0x800481A0u: goto label_800481A0;
    case 0x800481A4u: goto label_800481A4;
    case 0x800481A8u: goto label_800481A8;
    case 0x800481ACu: goto label_800481AC;
    case 0x800481B0u: goto label_800481B0;
    case 0x800481B4u: goto label_800481B4;
    case 0x800481B8u: goto label_800481B8;
    case 0x800481BCu: goto label_800481BC;
    case 0x800481C0u: goto label_800481C0;
    case 0x800481C4u: goto label_800481C4;
    case 0x800481C8u: goto label_800481C8;
    case 0x800481CCu: goto label_800481CC;
    case 0x800481D0u: goto label_800481D0;
    case 0x800481D4u: goto label_800481D4;
    case 0x800481D8u: goto label_800481D8;
    case 0x800481DCu: goto label_800481DC;
    case 0x800481E0u: goto label_800481E0;
    case 0x800481E4u: goto label_800481E4;
    case 0x800481E8u: goto label_800481E8;
    case 0x800481ECu: goto label_800481EC;
    case 0x800481F0u: goto label_800481F0;
    case 0x800481F4u: goto label_800481F4;
    case 0x800481F8u: goto label_800481F8;
    case 0x800481FCu: goto label_800481FC;
    case 0x80048200u: goto label_80048200;
    case 0x80048204u: goto label_80048204;
    case 0x80048208u: goto label_80048208;
    case 0x8004820Cu: goto label_8004820C;
    case 0x80048210u: goto label_80048210;
    case 0x80048214u: goto label_80048214;
    case 0x80048218u: goto label_80048218;
    case 0x8004821Cu: goto label_8004821C;
    case 0x80048220u: goto label_80048220;
    case 0x80048224u: goto label_80048224;
    case 0x80048228u: goto label_80048228;
    case 0x8004822Cu: goto label_8004822C;
    case 0x80048230u: goto label_80048230;
    case 0x80048234u: goto label_80048234;
    case 0x80048238u: goto label_80048238;
    case 0x8004823Cu: goto label_8004823C;
    case 0x80048240u: goto label_80048240;
    case 0x80048244u: goto label_80048244;
    case 0x80048248u: goto label_80048248;
    case 0x8004824Cu: goto label_8004824C;
    case 0x80048250u: goto label_80048250;
    case 0x80048254u: goto label_80048254;
    case 0x80048258u: goto label_80048258;
    case 0x8004825Cu: goto label_8004825C;
    case 0x80048260u: goto label_80048260;
    case 0x80048264u: goto label_80048264;
    case 0x80048268u: goto label_80048268;
    case 0x8004826Cu: goto label_8004826C;
    case 0x80048270u: goto label_80048270;
    case 0x80048274u: goto label_80048274;
    case 0x80048278u: goto label_80048278;
    case 0x8004827Cu: goto label_8004827C;
    case 0x80048280u: goto label_80048280;
    case 0x80048284u: goto label_80048284;
    case 0x80048288u: goto label_80048288;
    case 0x8004828Cu: goto label_8004828C;
    case 0x80048290u: goto label_80048290;
    case 0x80048294u: goto label_80048294;
    case 0x80048298u: goto label_80048298;
    case 0x8004829Cu: goto label_8004829C;
    case 0x800482A0u: goto label_800482A0;
    case 0x800482A4u: goto label_800482A4;
    case 0x800482A8u: goto label_800482A8;
    case 0x800482ACu: goto label_800482AC;
    case 0x800482B0u: goto label_800482B0;
    case 0x800482B4u: goto label_800482B4;
    case 0x800482B8u: goto label_800482B8;
    case 0x800482BCu: goto label_800482BC;
    case 0x800482C0u: goto label_800482C0;
    case 0x800482C4u: goto label_800482C4;
    case 0x800482C8u: goto label_800482C8;
    case 0x800482CCu: goto label_800482CC;
    case 0x800482D0u: goto label_800482D0;
    case 0x800482D4u: goto label_800482D4;
    case 0x800482D8u: goto label_800482D8;
    case 0x800482DCu: goto label_800482DC;
    case 0x800482E0u: goto label_800482E0;
    case 0x800482E4u: goto label_800482E4;
    case 0x800482E8u: goto label_800482E8;
    case 0x800482ECu: goto label_800482EC;
    case 0x800482F0u: goto label_800482F0;
    case 0x800482F4u: goto label_800482F4;
    case 0x800482F8u: goto label_800482F8;
    case 0x800482FCu: goto label_800482FC;
    case 0x80048300u: goto label_80048300;
    case 0x80048304u: goto label_80048304;
    case 0x80048308u: goto label_80048308;
    case 0x8004830Cu: goto label_8004830C;
    case 0x80048310u: goto label_80048310;
    case 0x80048314u: goto label_80048314;
    case 0x80048318u: goto label_80048318;
    case 0x8004831Cu: goto label_8004831C;
    case 0x80048320u: goto label_80048320;
    case 0x80048324u: goto label_80048324;
    case 0x80048328u: goto label_80048328;
    case 0x8004832Cu: goto label_8004832C;
    case 0x80048330u: goto label_80048330;
    case 0x80048334u: goto label_80048334;
    case 0x80048338u: goto label_80048338;
    case 0x8004833Cu: goto label_8004833C;
    case 0x80048340u: goto label_80048340;
    case 0x80048344u: goto label_80048344;
    case 0x80048348u: goto label_80048348;
    case 0x8004834Cu: goto label_8004834C;
    case 0x80048350u: goto label_80048350;
    case 0x80048354u: goto label_80048354;
    case 0x80048358u: goto label_80048358;
    case 0x8004835Cu: goto label_8004835C;
    case 0x80048360u: goto label_80048360;
    case 0x80048364u: goto label_80048364;
    case 0x80048368u: goto label_80048368;
    case 0x8004836Cu: goto label_8004836C;
    case 0x80048370u: goto label_80048370;
    case 0x80048374u: goto label_80048374;
    case 0x80048378u: goto label_80048378;
    case 0x8004837Cu: goto label_8004837C;
    case 0x80048380u: goto label_80048380;
    case 0x80048384u: goto label_80048384;
    case 0x80048388u: goto label_80048388;
    case 0x8004838Cu: goto label_8004838C;
    case 0x80048390u: goto label_80048390;
    case 0x80048394u: goto label_80048394;
    case 0x80048398u: goto label_80048398;
    case 0x8004839Cu: goto label_8004839C;
    case 0x800483A0u: goto label_800483A0;
    case 0x800483A4u: goto label_800483A4;
    case 0x800483A8u: goto label_800483A8;
    case 0x800483ACu: goto label_800483AC;
    case 0x800483B0u: goto label_800483B0;
    case 0x800483B4u: goto label_800483B4;
    case 0x800483B8u: goto label_800483B8;
    case 0x800483BCu: goto label_800483BC;
    case 0x800483C0u: goto label_800483C0;
    case 0x800483C4u: goto label_800483C4;
    case 0x800483C8u: goto label_800483C8;
    case 0x800483CCu: goto label_800483CC;
    case 0x800483D0u: goto label_800483D0;
    case 0x800483D4u: goto label_800483D4;
    case 0x800483D8u: goto label_800483D8;
    case 0x800483DCu: goto label_800483DC;
    case 0x800483E0u: goto label_800483E0;
    case 0x800483E4u: goto label_800483E4;
    case 0x800483E8u: goto label_800483E8;
    case 0x800483ECu: goto label_800483EC;
    case 0x800483F0u: goto label_800483F0;
    case 0x800483F4u: goto label_800483F4;
    case 0x800483F8u: goto label_800483F8;
    case 0x800483FCu: goto label_800483FC;
    case 0x80048400u: goto label_80048400;
    case 0x80048404u: goto label_80048404;
    case 0x80048408u: goto label_80048408;
    case 0x8004840Cu: goto label_8004840C;
    case 0x80048410u: goto label_80048410;
    case 0x80048414u: goto label_80048414;
    case 0x80048418u: goto label_80048418;
    case 0x8004841Cu: goto label_8004841C;
    case 0x80048420u: goto label_80048420;
    case 0x80048424u: goto label_80048424;
    case 0x80048428u: goto label_80048428;
    case 0x8004842Cu: goto label_8004842C;
    case 0x80048430u: goto label_80048430;
    case 0x80048434u: goto label_80048434;
    case 0x80048438u: goto label_80048438;
    case 0x8004843Cu: goto label_8004843C;
    case 0x80048440u: goto label_80048440;
    case 0x80048444u: goto label_80048444;
    case 0x80048448u: goto label_80048448;
    case 0x8004844Cu: goto label_8004844C;
    case 0x80048450u: goto label_80048450;
    case 0x80048454u: goto label_80048454;
    case 0x80048458u: goto label_80048458;
    case 0x8004845Cu: goto label_8004845C;
    case 0x80048460u: goto label_80048460;
    case 0x80048464u: goto label_80048464;
    case 0x80048468u: goto label_80048468;
    case 0x8004846Cu: goto label_8004846C;
    case 0x80048470u: goto label_80048470;
    case 0x80048474u: goto label_80048474;
    case 0x80048478u: goto label_80048478;
    case 0x8004847Cu: goto label_8004847C;
    case 0x80048480u: goto label_80048480;
    case 0x80048484u: goto label_80048484;
    case 0x80048488u: goto label_80048488;
    case 0x8004848Cu: goto label_8004848C;
    case 0x80048490u: goto label_80048490;
    case 0x80048494u: goto label_80048494;
    case 0x80048498u: goto label_80048498;
    case 0x8004849Cu: goto label_8004849C;
    case 0x800484A0u: goto label_800484A0;
    case 0x800484A4u: goto label_800484A4;
    case 0x800484A8u: goto label_800484A8;
    case 0x800484ACu: goto label_800484AC;
    case 0x800484B0u: goto label_800484B0;
    case 0x800484B4u: goto label_800484B4;
    case 0x800484B8u: goto label_800484B8;
    case 0x800484BCu: goto label_800484BC;
    case 0x800484C0u: goto label_800484C0;
    case 0x800484C4u: goto label_800484C4;
    case 0x800484C8u: goto label_800484C8;
    case 0x800484CCu: goto label_800484CC;
    case 0x800484D0u: goto label_800484D0;
    case 0x800484D4u: goto label_800484D4;
    case 0x800484D8u: goto label_800484D8;
    case 0x800484DCu: goto label_800484DC;
    case 0x800484E0u: goto label_800484E0;
    case 0x800484E4u: goto label_800484E4;
    case 0x800484E8u: goto label_800484E8;
    case 0x800484ECu: goto label_800484EC;
    case 0x800484F0u: goto label_800484F0;
    case 0x800484F4u: goto label_800484F4;
    case 0x800484F8u: goto label_800484F8;
    case 0x800484FCu: goto label_800484FC;
    case 0x80048500u: goto label_80048500;
    case 0x80048504u: goto label_80048504;
    case 0x80048508u: goto label_80048508;
    case 0x8004850Cu: goto label_8004850C;
    case 0x80048510u: goto label_80048510;
    case 0x80048514u: goto label_80048514;
    case 0x80048518u: goto label_80048518;
    case 0x8004851Cu: goto label_8004851C;
    case 0x80048520u: goto label_80048520;
    case 0x80048524u: goto label_80048524;
    case 0x80048528u: goto label_80048528;
    case 0x8004852Cu: goto label_8004852C;
    case 0x80048530u: goto label_80048530;
    case 0x80048534u: goto label_80048534;
    case 0x80048538u: goto label_80048538;
    case 0x8004853Cu: goto label_8004853C;
    case 0x80048540u: goto label_80048540;
    case 0x80048544u: goto label_80048544;
    case 0x80048548u: goto label_80048548;
    case 0x8004854Cu: goto label_8004854C;
    case 0x80048550u: goto label_80048550;
    case 0x80048554u: goto label_80048554;
    case 0x80048558u: goto label_80048558;
    case 0x8004855Cu: goto label_8004855C;
    case 0x80048560u: goto label_80048560;
    case 0x80048564u: goto label_80048564;
    case 0x80048568u: goto label_80048568;
    case 0x8004856Cu: goto label_8004856C;
    case 0x80048570u: goto label_80048570;
    case 0x80048574u: goto label_80048574;
    case 0x80048578u: goto label_80048578;
    case 0x8004857Cu: goto label_8004857C;
    case 0x80048580u: goto label_80048580;
    case 0x80048584u: goto label_80048584;
    case 0x80048588u: goto label_80048588;
    case 0x8004858Cu: goto label_8004858C;
    case 0x80048590u: goto label_80048590;
    case 0x80048594u: goto label_80048594;
    case 0x80048598u: goto label_80048598;
    case 0x8004859Cu: goto label_8004859C;
    case 0x800485A0u: goto label_800485A0;
    case 0x800485A4u: goto label_800485A4;
    case 0x800485A8u: goto label_800485A8;
    case 0x800485ACu: goto label_800485AC;
    case 0x800485B0u: goto label_800485B0;
    case 0x800485B4u: goto label_800485B4;
    case 0x800485B8u: goto label_800485B8;
    case 0x800485BCu: goto label_800485BC;
    case 0x800485C0u: goto label_800485C0;
    case 0x800485C4u: goto label_800485C4;
    case 0x800485C8u: goto label_800485C8;
    case 0x800485CCu: goto label_800485CC;
    case 0x800485D0u: goto label_800485D0;
    case 0x800485D4u: goto label_800485D4;
    case 0x800485D8u: goto label_800485D8;
    case 0x800485DCu: goto label_800485DC;
    case 0x800485E0u: goto label_800485E0;
    case 0x800485E4u: goto label_800485E4;
    case 0x800485E8u: goto label_800485E8;
    case 0x800485ECu: goto label_800485EC;
    case 0x800485F0u: goto label_800485F0;
    case 0x800485F4u: goto label_800485F4;
    case 0x800485F8u: goto label_800485F8;
    case 0x800485FCu: goto label_800485FC;
    case 0x80048600u: goto label_80048600;
    case 0x80048604u: goto label_80048604;
    case 0x80048608u: goto label_80048608;
    case 0x8004860Cu: goto label_8004860C;
    case 0x80048610u: goto label_80048610;
    case 0x80048614u: goto label_80048614;
    case 0x80048618u: goto label_80048618;
    case 0x8004861Cu: goto label_8004861C;
    case 0x80048620u: goto label_80048620;
    case 0x80048624u: goto label_80048624;
    case 0x80048628u: goto label_80048628;
    case 0x8004862Cu: goto label_8004862C;
    case 0x80048630u: goto label_80048630;
    case 0x80048634u: goto label_80048634;
    case 0x80048638u: goto label_80048638;
    case 0x8004863Cu: goto label_8004863C;
    case 0x80048640u: goto label_80048640;
    case 0x80048644u: goto label_80048644;
    case 0x80048648u: goto label_80048648;
    case 0x8004864Cu: goto label_8004864C;
    case 0x80048650u: goto label_80048650;
    case 0x80048654u: goto label_80048654;
    case 0x80048658u: goto label_80048658;
    case 0x8004865Cu: goto label_8004865C;
    case 0x80048660u: goto label_80048660;
    case 0x80048664u: goto label_80048664;
    case 0x80048668u: goto label_80048668;
    case 0x8004866Cu: goto label_8004866C;
    case 0x80048670u: goto label_80048670;
    case 0x80048674u: goto label_80048674;
    case 0x80048678u: goto label_80048678;
    case 0x8004867Cu: goto label_8004867C;
    case 0x80048680u: goto label_80048680;
    case 0x80048684u: goto label_80048684;
    case 0x80048688u: goto label_80048688;
    case 0x8004868Cu: goto label_8004868C;
    case 0x80048690u: goto label_80048690;
    case 0x80048694u: goto label_80048694;
    case 0x80048698u: goto label_80048698;
    case 0x8004869Cu: goto label_8004869C;
    case 0x800486A0u: goto label_800486A0;
    case 0x800486A4u: goto label_800486A4;
    case 0x800486A8u: goto label_800486A8;
    case 0x800486ACu: goto label_800486AC;
    case 0x800486B0u: goto label_800486B0;
    case 0x800486B4u: goto label_800486B4;
    case 0x800486B8u: goto label_800486B8;
    case 0x800486BCu: goto label_800486BC;
    case 0x800486C0u: goto label_800486C0;
    case 0x800486C4u: goto label_800486C4;
    case 0x800486C8u: goto label_800486C8;
    case 0x800486CCu: goto label_800486CC;
    case 0x800486D0u: goto label_800486D0;
    case 0x800486D4u: goto label_800486D4;
    case 0x800486D8u: goto label_800486D8;
    case 0x800486DCu: goto label_800486DC;
    case 0x800486E0u: goto label_800486E0;
    case 0x800486E4u: goto label_800486E4;
    case 0x800486E8u: goto label_800486E8;
    case 0x800486ECu: goto label_800486EC;
    case 0x800486F0u: goto label_800486F0;
    case 0x800486F4u: goto label_800486F4;
    case 0x800486F8u: goto label_800486F8;
    case 0x800486FCu: goto label_800486FC;
    case 0x80048700u: goto label_80048700;
    case 0x80048704u: goto label_80048704;
    case 0x80048708u: goto label_80048708;
    case 0x8004870Cu: goto label_8004870C;
    case 0x80048710u: goto label_80048710;
    case 0x80048714u: goto label_80048714;
    case 0x80048718u: goto label_80048718;
    case 0x8004871Cu: goto label_8004871C;
    case 0x80048720u: goto label_80048720;
    case 0x80048724u: goto label_80048724;
    case 0x80048728u: goto label_80048728;
    case 0x8004872Cu: goto label_8004872C;
    case 0x80048730u: goto label_80048730;
    case 0x80048734u: goto label_80048734;
    case 0x80048738u: goto label_80048738;
    case 0x8004873Cu: goto label_8004873C;
    case 0x80048740u: goto label_80048740;
    case 0x80048744u: goto label_80048744;
    case 0x80048748u: goto label_80048748;
    case 0x8004874Cu: goto label_8004874C;
    case 0x80048750u: goto label_80048750;
    case 0x80048754u: goto label_80048754;
    case 0x80048758u: goto label_80048758;
    case 0x8004875Cu: goto label_8004875C;
    case 0x80048760u: goto label_80048760;
    case 0x80048764u: goto label_80048764;
    case 0x80048768u: goto label_80048768;
    case 0x8004876Cu: goto label_8004876C;
    case 0x80048770u: goto label_80048770;
    case 0x80048774u: goto label_80048774;
    case 0x80048778u: goto label_80048778;
    case 0x8004877Cu: goto label_8004877C;
    case 0x80048780u: goto label_80048780;
    case 0x80048784u: goto label_80048784;
    case 0x80048788u: goto label_80048788;
    case 0x8004878Cu: goto label_8004878C;
    case 0x80048790u: goto label_80048790;
    case 0x80048794u: goto label_80048794;
    case 0x80048798u: goto label_80048798;
    case 0x8004879Cu: goto label_8004879C;
    case 0x800487A0u: goto label_800487A0;
    case 0x800487A4u: goto label_800487A4;
    case 0x800487A8u: goto label_800487A8;
    case 0x800487ACu: goto label_800487AC;
    case 0x800487B0u: goto label_800487B0;
    case 0x800487B4u: goto label_800487B4;
    case 0x800487B8u: goto label_800487B8;
    case 0x800487BCu: goto label_800487BC;
    case 0x800487C0u: goto label_800487C0;
    case 0x800487C4u: goto label_800487C4;
    case 0x800487C8u: goto label_800487C8;
    case 0x800487CCu: goto label_800487CC;
    case 0x800487D0u: goto label_800487D0;
    case 0x800487D4u: goto label_800487D4;
    case 0x800487D8u: goto label_800487D8;
    case 0x800487DCu: goto label_800487DC;
    case 0x800487E0u: goto label_800487E0;
    case 0x800487E4u: goto label_800487E4;
    case 0x800487E8u: goto label_800487E8;
    case 0x800487ECu: goto label_800487EC;
    case 0x800487F0u: goto label_800487F0;
    case 0x800487F4u: goto label_800487F4;
    case 0x800487F8u: goto label_800487F8;
    case 0x800487FCu: goto label_800487FC;
    case 0x80048800u: goto label_80048800;
    case 0x80048804u: goto label_80048804;
    case 0x80048808u: goto label_80048808;
    case 0x8004880Cu: goto label_8004880C;
    case 0x80048810u: goto label_80048810;
    case 0x80048814u: goto label_80048814;
    case 0x80048818u: goto label_80048818;
    case 0x8004881Cu: goto label_8004881C;
    case 0x80048820u: goto label_80048820;
    case 0x80048824u: goto label_80048824;
    case 0x80048828u: goto label_80048828;
    case 0x8004882Cu: goto label_8004882C;
    case 0x80048830u: goto label_80048830;
    case 0x80048834u: goto label_80048834;
    case 0x80048838u: goto label_80048838;
    case 0x8004883Cu: goto label_8004883C;
    case 0x80048840u: goto label_80048840;
    case 0x80048844u: goto label_80048844;
    case 0x80048848u: goto label_80048848;
    case 0x8004884Cu: goto label_8004884C;
    case 0x80048850u: goto label_80048850;
    case 0x80048854u: goto label_80048854;
    case 0x80048858u: goto label_80048858;
    case 0x8004885Cu: goto label_8004885C;
    case 0x80048860u: goto label_80048860;
    case 0x80048864u: goto label_80048864;
    case 0x80048868u: goto label_80048868;
    case 0x8004886Cu: goto label_8004886C;
    case 0x80048870u: goto label_80048870;
    case 0x80048874u: goto label_80048874;
    case 0x80048878u: goto label_80048878;
    case 0x8004887Cu: goto label_8004887C;
    case 0x80048880u: goto label_80048880;
    case 0x80048884u: goto label_80048884;
    case 0x80048888u: goto label_80048888;
    case 0x8004888Cu: goto label_8004888C;
    case 0x80048890u: goto label_80048890;
    case 0x80048894u: goto label_80048894;
    case 0x80048898u: goto label_80048898;
    case 0x8004889Cu: goto label_8004889C;
    case 0x800488A0u: goto label_800488A0;
    case 0x800488A4u: goto label_800488A4;
    case 0x800488A8u: goto label_800488A8;
    case 0x800488ACu: goto label_800488AC;
    case 0x800488B0u: goto label_800488B0;
    case 0x800488B4u: goto label_800488B4;
    case 0x800488B8u: goto label_800488B8;
    case 0x800488BCu: goto label_800488BC;
    case 0x800488C0u: goto label_800488C0;
    case 0x800488C4u: goto label_800488C4;
    case 0x800488C8u: goto label_800488C8;
    case 0x800488CCu: goto label_800488CC;
    case 0x800488D0u: goto label_800488D0;
    case 0x800488D4u: goto label_800488D4;
    case 0x800488D8u: goto label_800488D8;
    case 0x800488DCu: goto label_800488DC;
    case 0x800488E0u: goto label_800488E0;
    case 0x800488E4u: goto label_800488E4;
    case 0x800488E8u: goto label_800488E8;
    case 0x800488ECu: goto label_800488EC;
    case 0x800488F0u: goto label_800488F0;
    case 0x800488F4u: goto label_800488F4;
    case 0x800488F8u: goto label_800488F8;
    case 0x800488FCu: goto label_800488FC;
    case 0x80048900u: goto label_80048900;
    case 0x80048904u: goto label_80048904;
    case 0x80048908u: goto label_80048908;
    case 0x8004890Cu: goto label_8004890C;
    case 0x80048910u: goto label_80048910;
    case 0x80048914u: goto label_80048914;
    case 0x80048918u: goto label_80048918;
    case 0x8004891Cu: goto label_8004891C;
    case 0x80048920u: goto label_80048920;
    case 0x80048924u: goto label_80048924;
    case 0x80048928u: goto label_80048928;
    case 0x8004892Cu: goto label_8004892C;
    case 0x80048930u: goto label_80048930;
    case 0x80048934u: goto label_80048934;
    case 0x80048938u: goto label_80048938;
    case 0x8004893Cu: goto label_8004893C;
    case 0x80048940u: goto label_80048940;
    case 0x80048944u: goto label_80048944;
    case 0x80048948u: goto label_80048948;
    case 0x8004894Cu: goto label_8004894C;
    case 0x80048950u: goto label_80048950;
    case 0x80048954u: goto label_80048954;
    case 0x80048958u: goto label_80048958;
    case 0x8004895Cu: goto label_8004895C;
    case 0x80048960u: goto label_80048960;
    case 0x80048964u: goto label_80048964;
    case 0x80048968u: goto label_80048968;
    case 0x8004896Cu: goto label_8004896C;
    case 0x80048970u: goto label_80048970;
    case 0x80048974u: goto label_80048974;
    case 0x80048978u: goto label_80048978;
    case 0x8004897Cu: goto label_8004897C;
    case 0x80048980u: goto label_80048980;
    case 0x80048984u: goto label_80048984;
    case 0x80048988u: goto label_80048988;
    case 0x8004898Cu: goto label_8004898C;
    case 0x80048990u: goto label_80048990;
    case 0x80048994u: goto label_80048994;
    case 0x80048998u: goto label_80048998;
    case 0x8004899Cu: goto label_8004899C;
    case 0x800489A0u: goto label_800489A0;
    case 0x800489A4u: goto label_800489A4;
    case 0x800489A8u: goto label_800489A8;
    case 0x800489ACu: goto label_800489AC;
    case 0x800489B0u: goto label_800489B0;
    case 0x800489B4u: goto label_800489B4;
    case 0x800489B8u: goto label_800489B8;
    case 0x800489BCu: goto label_800489BC;
    case 0x800489C0u: goto label_800489C0;
    case 0x800489C4u: goto label_800489C4;
    case 0x800489C8u: goto label_800489C8;
    case 0x800489CCu: goto label_800489CC;
    case 0x800489D0u: goto label_800489D0;
    case 0x800489D4u: goto label_800489D4;
    case 0x800489D8u: goto label_800489D8;
    case 0x800489DCu: goto label_800489DC;
    case 0x800489E0u: goto label_800489E0;
    case 0x800489E4u: goto label_800489E4;
    case 0x800489E8u: goto label_800489E8;
    case 0x800489ECu: goto label_800489EC;
    case 0x800489F0u: goto label_800489F0;
    case 0x800489F4u: goto label_800489F4;
    case 0x800489F8u: goto label_800489F8;
    case 0x800489FCu: goto label_800489FC;
    case 0x80048A00u: goto label_80048A00;
    case 0x80048A04u: goto label_80048A04;
    case 0x80048A08u: goto label_80048A08;
    case 0x80048A0Cu: goto label_80048A0C;
    case 0x80048A10u: goto label_80048A10;
    case 0x80048A14u: goto label_80048A14;
    case 0x80048A18u: goto label_80048A18;
    case 0x80048A1Cu: goto label_80048A1C;
    case 0x80048A20u: goto label_80048A20;
    case 0x80048A24u: goto label_80048A24;
    case 0x80048A28u: goto label_80048A28;
    case 0x80048A2Cu: goto label_80048A2C;
    case 0x80048A30u: goto label_80048A30;
    case 0x80048A34u: goto label_80048A34;
    case 0x80048A38u: goto label_80048A38;
    case 0x80048A3Cu: goto label_80048A3C;
    case 0x80048A40u: goto label_80048A40;
    case 0x80048A44u: goto label_80048A44;
    case 0x80048A48u: goto label_80048A48;
    case 0x80048A4Cu: goto label_80048A4C;
    case 0x80048A50u: goto label_80048A50;
    case 0x80048A54u: goto label_80048A54;
    case 0x80048A58u: goto label_80048A58;
    case 0x80048A5Cu: goto label_80048A5C;
    case 0x80048A60u: goto label_80048A60;
    case 0x80048A64u: goto label_80048A64;
    case 0x80048A68u: goto label_80048A68;
    case 0x80048A6Cu: goto label_80048A6C;
    case 0x80048A70u: goto label_80048A70;
    case 0x80048A74u: goto label_80048A74;
    case 0x80048A78u: goto label_80048A78;
    case 0x80048A7Cu: goto label_80048A7C;
    case 0x80048A80u: goto label_80048A80;
    case 0x80048A84u: goto label_80048A84;
    case 0x80048A88u: goto label_80048A88;
    case 0x80048A8Cu: goto label_80048A8C;
    case 0x80048A90u: goto label_80048A90;
    case 0x80048A94u: goto label_80048A94;
    case 0x80048A98u: goto label_80048A98;
    case 0x80048A9Cu: goto label_80048A9C;
    case 0x80048AA0u: goto label_80048AA0;
    case 0x80048AA4u: goto label_80048AA4;
    case 0x80048AA8u: goto label_80048AA8;
    case 0x80048AACu: goto label_80048AAC;
    case 0x80048AB0u: goto label_80048AB0;
    case 0x80048AB4u: goto label_80048AB4;
    case 0x80048AB8u: goto label_80048AB8;
    case 0x80048ABCu: goto label_80048ABC;
    case 0x80048AC0u: goto label_80048AC0;
    case 0x80048AC4u: goto label_80048AC4;
    case 0x80048AC8u: goto label_80048AC8;
    case 0x80048ACCu: goto label_80048ACC;
    case 0x80048AD0u: goto label_80048AD0;
    case 0x80048AD4u: goto label_80048AD4;
    case 0x80048AD8u: goto label_80048AD8;
    case 0x80048ADCu: goto label_80048ADC;
    case 0x80048AE0u: goto label_80048AE0;
    case 0x80048AE4u: goto label_80048AE4;
    case 0x80048AE8u: goto label_80048AE8;
    case 0x80048AECu: goto label_80048AEC;
    case 0x80048AF0u: goto label_80048AF0;
    case 0x80048AF4u: goto label_80048AF4;
    case 0x80048AF8u: goto label_80048AF8;
    case 0x80048AFCu: goto label_80048AFC;
    case 0x80048B00u: goto label_80048B00;
    case 0x80048B04u: goto label_80048B04;
    case 0x80048B08u: goto label_80048B08;
    case 0x80048B0Cu: goto label_80048B0C;
    case 0x80048B10u: goto label_80048B10;
    case 0x80048B14u: goto label_80048B14;
    case 0x80048B18u: goto label_80048B18;
    case 0x80048B1Cu: goto label_80048B1C;
    case 0x80048B20u: goto label_80048B20;
    case 0x80048B24u: goto label_80048B24;
    case 0x80048B28u: goto label_80048B28;
    case 0x80048B2Cu: goto label_80048B2C;
    case 0x80048B30u: goto label_80048B30;
    case 0x80048B34u: goto label_80048B34;
    case 0x80048B38u: goto label_80048B38;
    case 0x80048B3Cu: goto label_80048B3C;
    case 0x80048B40u: goto label_80048B40;
    case 0x80048B44u: goto label_80048B44;
    case 0x80048B48u: goto label_80048B48;
    case 0x80048B4Cu: goto label_80048B4C;
    case 0x80048B50u: goto label_80048B50;
    case 0x80048B54u: goto label_80048B54;
    case 0x80048B58u: goto label_80048B58;
    case 0x80048B5Cu: goto label_80048B5C;
    case 0x80048B60u: goto label_80048B60;
    case 0x80048B64u: goto label_80048B64;
    case 0x80048B68u: goto label_80048B68;
    case 0x80048B6Cu: goto label_80048B6C;
    case 0x80048B70u: goto label_80048B70;
    case 0x80048B74u: goto label_80048B74;
    case 0x80048B78u: goto label_80048B78;
    case 0x80048B7Cu: goto label_80048B7C;
    case 0x80048B80u: goto label_80048B80;
    case 0x80048B84u: goto label_80048B84;
    case 0x80048B88u: goto label_80048B88;
    case 0x80048B8Cu: goto label_80048B8C;
    case 0x80048B90u: goto label_80048B90;
    case 0x80048B94u: goto label_80048B94;
    case 0x80048B98u: goto label_80048B98;
    case 0x80048B9Cu: goto label_80048B9C;
    case 0x80048BA0u: goto label_80048BA0;
    case 0x80048BA4u: goto label_80048BA4;
    case 0x80048BA8u: goto label_80048BA8;
    case 0x80048BACu: goto label_80048BAC;
    case 0x80048BB0u: goto label_80048BB0;
    case 0x80048BB4u: goto label_80048BB4;
    case 0x80048BB8u: goto label_80048BB8;
    case 0x80048BBCu: goto label_80048BBC;
    case 0x80048BC0u: goto label_80048BC0;
    case 0x80048BC4u: goto label_80048BC4;
    case 0x80048BC8u: goto label_80048BC8;
    case 0x80048BCCu: goto label_80048BCC;
    case 0x80048BD0u: goto label_80048BD0;
    case 0x80048BD4u: goto label_80048BD4;
    case 0x80048BD8u: goto label_80048BD8;
    case 0x80048BDCu: goto label_80048BDC;
    case 0x80048BE0u: goto label_80048BE0;
    case 0x80048BE4u: goto label_80048BE4;
    case 0x80048BE8u: goto label_80048BE8;
    case 0x80048BECu: goto label_80048BEC;
    case 0x80048BF0u: goto label_80048BF0;
    case 0x80048BF4u: goto label_80048BF4;
    case 0x80048BF8u: goto label_80048BF8;
    case 0x80048BFCu: goto label_80048BFC;
    case 0x80048C00u: goto label_80048C00;
    case 0x80048C04u: goto label_80048C04;
    case 0x80048C08u: goto label_80048C08;
    case 0x80048C0Cu: goto label_80048C0C;
    case 0x80048C10u: goto label_80048C10;
    case 0x80048C14u: goto label_80048C14;
    case 0x80048C18u: goto label_80048C18;
    case 0x80048C1Cu: goto label_80048C1C;
    case 0x80048C20u: goto label_80048C20;
    case 0x80048C24u: goto label_80048C24;
    case 0x80048C28u: goto label_80048C28;
    case 0x80048C2Cu: goto label_80048C2C;
    case 0x80048C30u: goto label_80048C30;
    case 0x80048C34u: goto label_80048C34;
    case 0x80048C38u: goto label_80048C38;
    case 0x80048C3Cu: goto label_80048C3C;
    case 0x80048C40u: goto label_80048C40;
    case 0x80048C44u: goto label_80048C44;
    case 0x80048C48u: goto label_80048C48;
    case 0x80048C4Cu: goto label_80048C4C;
    case 0x80048C50u: goto label_80048C50;
    case 0x80048C54u: goto label_80048C54;
    case 0x80048C58u: goto label_80048C58;
    case 0x80048C5Cu: goto label_80048C5C;
    case 0x80048C60u: goto label_80048C60;
    case 0x80048C64u: goto label_80048C64;
    case 0x80048C68u: goto label_80048C68;
    case 0x80048C6Cu: goto label_80048C6C;
    case 0x80048C70u: goto label_80048C70;
    case 0x80048C74u: goto label_80048C74;
    case 0x80048C78u: goto label_80048C78;
    case 0x80048C7Cu: goto label_80048C7C;
    case 0x80048C80u: goto label_80048C80;
    case 0x80048C84u: goto label_80048C84;
    case 0x80048C88u: goto label_80048C88;
    case 0x80048C8Cu: goto label_80048C8C;
    case 0x80048C90u: goto label_80048C90;
    case 0x80048C94u: goto label_80048C94;
    case 0x80048C98u: goto label_80048C98;
    case 0x80048C9Cu: goto label_80048C9C;
    case 0x80048CA0u: goto label_80048CA0;
    case 0x80048CA4u: goto label_80048CA4;
    case 0x80048CA8u: goto label_80048CA8;
    case 0x80048CACu: goto label_80048CAC;
    case 0x80048CB0u: goto label_80048CB0;
    case 0x80048CB4u: goto label_80048CB4;
    case 0x80048CB8u: goto label_80048CB8;
    case 0x80048CBCu: goto label_80048CBC;
    case 0x80048CC0u: goto label_80048CC0;
    case 0x80048CC4u: goto label_80048CC4;
    case 0x80048CC8u: goto label_80048CC8;
    case 0x80048CCCu: goto label_80048CCC;
    case 0x80048CD0u: goto label_80048CD0;
    case 0x80048CD4u: goto label_80048CD4;
    case 0x80048CD8u: goto label_80048CD8;
    case 0x80048CDCu: goto label_80048CDC;
    case 0x80048CE0u: goto label_80048CE0;
    case 0x80048CE4u: goto label_80048CE4;
    case 0x80048CE8u: goto label_80048CE8;
    case 0x80048CECu: goto label_80048CEC;
    case 0x80048CF0u: goto label_80048CF0;
    case 0x80048CF4u: goto label_80048CF4;
    case 0x80048CF8u: goto label_80048CF8;
    case 0x80048CFCu: goto label_80048CFC;
    case 0x80048D00u: goto label_80048D00;
    case 0x80048D04u: goto label_80048D04;
    case 0x80048D08u: goto label_80048D08;
    case 0x80048D0Cu: goto label_80048D0C;
    case 0x80048D10u: goto label_80048D10;
    case 0x80048D14u: goto label_80048D14;
    case 0x80048D18u: goto label_80048D18;
    case 0x80048D1Cu: goto label_80048D1C;
    case 0x80048D20u: goto label_80048D20;
    case 0x80048D24u: goto label_80048D24;
    case 0x80048D28u: goto label_80048D28;
    case 0x80048D2Cu: goto label_80048D2C;
    case 0x80048D30u: goto label_80048D30;
    case 0x80048D34u: goto label_80048D34;
    case 0x80048D38u: goto label_80048D38;
    case 0x80048D3Cu: goto label_80048D3C;
    case 0x80048D40u: goto label_80048D40;
    case 0x80048D44u: goto label_80048D44;
    case 0x80048D48u: goto label_80048D48;
    case 0x80048D4Cu: goto label_80048D4C;
    case 0x80048D50u: goto label_80048D50;
    case 0x80048D54u: goto label_80048D54;
    case 0x80048D58u: goto label_80048D58;
    case 0x80048D5Cu: goto label_80048D5C;
    case 0x80048D60u: goto label_80048D60;
    case 0x80048D64u: goto label_80048D64;
    case 0x80048D68u: goto label_80048D68;
    case 0x80048D6Cu: goto label_80048D6C;
    case 0x80048D70u: goto label_80048D70;
    case 0x80048D74u: goto label_80048D74;
    case 0x80048D78u: goto label_80048D78;
    case 0x80048D7Cu: goto label_80048D7C;
    case 0x80048D80u: goto label_80048D80;
    case 0x80048D84u: goto label_80048D84;
    case 0x80048D88u: goto label_80048D88;
    case 0x80048D8Cu: goto label_80048D8C;
    case 0x80048D90u: goto label_80048D90;
    case 0x80048D94u: goto label_80048D94;
    case 0x80048D98u: goto label_80048D98;
    case 0x80048D9Cu: goto label_80048D9C;
    case 0x80048DA0u: goto label_80048DA0;
    case 0x80048DA4u: goto label_80048DA4;
    case 0x80048DA8u: goto label_80048DA8;
    case 0x80048DACu: goto label_80048DAC;
    case 0x80048DB0u: goto label_80048DB0;
    case 0x80048DB4u: goto label_80048DB4;
    case 0x80048DB8u: goto label_80048DB8;
    case 0x80048DBCu: goto label_80048DBC;
    case 0x80048DC0u: goto label_80048DC0;
    case 0x80048DC4u: goto label_80048DC4;
    case 0x80048DC8u: goto label_80048DC8;
    case 0x80048DCCu: goto label_80048DCC;
    case 0x80048DD0u: goto label_80048DD0;
    case 0x80048DD4u: goto label_80048DD4;
    case 0x80048DD8u: goto label_80048DD8;
    case 0x80048DDCu: goto label_80048DDC;
    case 0x80048DE0u: goto label_80048DE0;
    case 0x80048DE4u: goto label_80048DE4;
    case 0x80048DE8u: goto label_80048DE8;
    case 0x80048DECu: goto label_80048DEC;
    case 0x80048DF0u: goto label_80048DF0;
    case 0x80048DF4u: goto label_80048DF4;
    case 0x80048DF8u: goto label_80048DF8;
    case 0x80048DFCu: goto label_80048DFC;
    case 0x80048E00u: goto label_80048E00;
    case 0x80048E04u: goto label_80048E04;
    case 0x80048E08u: goto label_80048E08;
    case 0x80048E0Cu: goto label_80048E0C;
    case 0x80048E10u: goto label_80048E10;
    case 0x80048E14u: goto label_80048E14;
    case 0x80048E18u: goto label_80048E18;
    case 0x80048E1Cu: goto label_80048E1C;
    case 0x80048E20u: goto label_80048E20;
    case 0x80048E24u: goto label_80048E24;
    case 0x80048E28u: goto label_80048E28;
    case 0x80048E2Cu: goto label_80048E2C;
    case 0x80048E30u: goto label_80048E30;
    case 0x80048E34u: goto label_80048E34;
    case 0x80048E38u: goto label_80048E38;
    case 0x80048E3Cu: goto label_80048E3C;
    case 0x80048E40u: goto label_80048E40;
    case 0x80048E44u: goto label_80048E44;
    case 0x80048E48u: goto label_80048E48;
    case 0x80048E4Cu: goto label_80048E4C;
    case 0x80048E50u: goto label_80048E50;
    case 0x80048E54u: goto label_80048E54;
    case 0x80048E58u: goto label_80048E58;
    case 0x80048E5Cu: goto label_80048E5C;
    case 0x80048E60u: goto label_80048E60;
    case 0x80048E64u: goto label_80048E64;
    case 0x80048E68u: goto label_80048E68;
    case 0x80048E6Cu: goto label_80048E6C;
    case 0x80048E70u: goto label_80048E70;
    case 0x80048E74u: goto label_80048E74;
    case 0x80048E78u: goto label_80048E78;
    case 0x80048E7Cu: goto label_80048E7C;
    case 0x80048E80u: goto label_80048E80;
    case 0x80048E84u: goto label_80048E84;
    case 0x80048E88u: goto label_80048E88;
    case 0x80048E8Cu: goto label_80048E8C;
    case 0x80048E90u: goto label_80048E90;
    case 0x80048E94u: goto label_80048E94;
    case 0x80048E98u: goto label_80048E98;
    case 0x80048E9Cu: goto label_80048E9C;
    case 0x80048EA0u: goto label_80048EA0;
    case 0x80048EA4u: goto label_80048EA4;
    case 0x80048EA8u: goto label_80048EA8;
    case 0x80048EACu: goto label_80048EAC;
    case 0x80048EB0u: goto label_80048EB0;
    case 0x80048EB4u: goto label_80048EB4;
    case 0x80048EB8u: goto label_80048EB8;
    case 0x80048EBCu: goto label_80048EBC;
    case 0x80048EC0u: goto label_80048EC0;
    case 0x80048EC4u: goto label_80048EC4;
    case 0x80048EC8u: goto label_80048EC8;
    case 0x80048ECCu: goto label_80048ECC;
    case 0x80048ED0u: goto label_80048ED0;
    case 0x80048ED4u: goto label_80048ED4;
    case 0x80048ED8u: goto label_80048ED8;
    case 0x80048EDCu: goto label_80048EDC;
    case 0x80048EE0u: goto label_80048EE0;
    case 0x80048EE4u: goto label_80048EE4;
    case 0x80048EE8u: goto label_80048EE8;
    case 0x80048EECu: goto label_80048EEC;
    case 0x80048EF0u: goto label_80048EF0;
    case 0x80048EF4u: goto label_80048EF4;
    case 0x80048EF8u: goto label_80048EF8;
    case 0x80048EFCu: goto label_80048EFC;
    case 0x80048F00u: goto label_80048F00;
    case 0x80048F04u: goto label_80048F04;
    case 0x80048F08u: goto label_80048F08;
    case 0x80048F0Cu: goto label_80048F0C;
    case 0x80048F10u: goto label_80048F10;
    case 0x80048F14u: goto label_80048F14;
    case 0x80048F18u: goto label_80048F18;
    case 0x80048F1Cu: goto label_80048F1C;
    case 0x80048F20u: goto label_80048F20;
    case 0x80048F24u: goto label_80048F24;
    case 0x80048F28u: goto label_80048F28;
    case 0x80048F2Cu: goto label_80048F2C;
    case 0x80048F30u: goto label_80048F30;
    case 0x80048F34u: goto label_80048F34;
    case 0x80048F38u: goto label_80048F38;
    case 0x80048F3Cu: goto label_80048F3C;
    case 0x80048F40u: goto label_80048F40;
    case 0x80048F44u: goto label_80048F44;
    case 0x80048F48u: goto label_80048F48;
    case 0x80048F4Cu: goto label_80048F4C;
    case 0x80048F50u: goto label_80048F50;
    case 0x80048F54u: goto label_80048F54;
    case 0x80048F58u: goto label_80048F58;
    case 0x80048F5Cu: goto label_80048F5C;
    case 0x80048F60u: goto label_80048F60;
    case 0x80048F64u: goto label_80048F64;
    case 0x80048F68u: goto label_80048F68;
    case 0x80048F6Cu: goto label_80048F6C;
    case 0x80048F70u: goto label_80048F70;
    case 0x80048F74u: goto label_80048F74;
    case 0x80048F78u: goto label_80048F78;
    case 0x80048F7Cu: goto label_80048F7C;
    case 0x80048F80u: goto label_80048F80;
    case 0x80048F84u: goto label_80048F84;
    case 0x80048F88u: goto label_80048F88;
    case 0x80048F8Cu: goto label_80048F8C;
    case 0x80048F90u: goto label_80048F90;
    case 0x80048F94u: goto label_80048F94;
    case 0x80048F98u: goto label_80048F98;
    case 0x80048F9Cu: goto label_80048F9C;
    case 0x80048FA0u: goto label_80048FA0;
    case 0x80048FA4u: goto label_80048FA4;
    case 0x80048FA8u: goto label_80048FA8;
    case 0x80048FACu: goto label_80048FAC;
    case 0x80048FB0u: goto label_80048FB0;
    case 0x80048FB4u: goto label_80048FB4;
    case 0x80048FB8u: goto label_80048FB8;
    case 0x80048FBCu: goto label_80048FBC;
    case 0x80048FC0u: goto label_80048FC0;
    case 0x80048FC4u: goto label_80048FC4;
    case 0x80048FC8u: goto label_80048FC8;
    case 0x80048FCCu: goto label_80048FCC;
    case 0x80048FD0u: goto label_80048FD0;
    case 0x80048FD4u: goto label_80048FD4;
    case 0x80048FD8u: goto label_80048FD8;
    case 0x80048FDCu: goto label_80048FDC;
    case 0x80048FE0u: goto label_80048FE0;
    case 0x80048FE4u: goto label_80048FE4;
    case 0x80048FE8u: goto label_80048FE8;
    case 0x80048FECu: goto label_80048FEC;
    case 0x80048FF0u: goto label_80048FF0;
    case 0x80048FF4u: goto label_80048FF4;
    case 0x80048FF8u: goto label_80048FF8;
    case 0x80048FFCu: goto label_80048FFC;
    case 0x80049000u: goto label_80049000;
    case 0x80049004u: goto label_80049004;
    case 0x80049008u: goto label_80049008;
    case 0x8004900Cu: goto label_8004900C;
    case 0x80049010u: goto label_80049010;
    case 0x80049014u: goto label_80049014;
    case 0x80049018u: goto label_80049018;
    case 0x8004901Cu: goto label_8004901C;
    case 0x80049020u: goto label_80049020;
    case 0x80049024u: goto label_80049024;
    case 0x80049028u: goto label_80049028;
    case 0x8004902Cu: goto label_8004902C;
    case 0x80049030u: goto label_80049030;
    case 0x80049034u: goto label_80049034;
    case 0x80049038u: goto label_80049038;
    case 0x8004903Cu: goto label_8004903C;
    case 0x80049040u: goto label_80049040;
    case 0x80049044u: goto label_80049044;
    case 0x80049048u: goto label_80049048;
    case 0x8004904Cu: goto label_8004904C;
    case 0x80049050u: goto label_80049050;
    case 0x80049054u: goto label_80049054;
    case 0x80049058u: goto label_80049058;
    case 0x8004905Cu: goto label_8004905C;
    case 0x80049060u: goto label_80049060;
    case 0x80049064u: goto label_80049064;
    case 0x80049068u: goto label_80049068;
    case 0x8004906Cu: goto label_8004906C;
    case 0x80049070u: goto label_80049070;
    case 0x80049074u: goto label_80049074;
    case 0x80049078u: goto label_80049078;
    case 0x8004907Cu: goto label_8004907C;
    case 0x80049080u: goto label_80049080;
    case 0x80049084u: goto label_80049084;
    case 0x80049088u: goto label_80049088;
    case 0x8004908Cu: goto label_8004908C;
    case 0x80049090u: goto label_80049090;
    case 0x80049094u: goto label_80049094;
    case 0x80049098u: goto label_80049098;
    case 0x8004909Cu: goto label_8004909C;
    case 0x800490A0u: goto label_800490A0;
    case 0x800490A4u: goto label_800490A4;
    case 0x800490A8u: goto label_800490A8;
    case 0x800490ACu: goto label_800490AC;
    case 0x800490B0u: goto label_800490B0;
    case 0x800490B4u: goto label_800490B4;
    case 0x800490B8u: goto label_800490B8;
    case 0x800490BCu: goto label_800490BC;
    case 0x800490C0u: goto label_800490C0;
    case 0x800490C4u: goto label_800490C4;
    case 0x800490C8u: goto label_800490C8;
    case 0x800490CCu: goto label_800490CC;
    case 0x800490D0u: goto label_800490D0;
    case 0x800490D4u: goto label_800490D4;
    case 0x800490D8u: goto label_800490D8;
    case 0x800490DCu: goto label_800490DC;
    case 0x800490E0u: goto label_800490E0;
    case 0x800490E4u: goto label_800490E4;
    case 0x800490E8u: goto label_800490E8;
    case 0x800490ECu: goto label_800490EC;
    case 0x800490F0u: goto label_800490F0;
    case 0x800490F4u: goto label_800490F4;
    case 0x800490F8u: goto label_800490F8;
    case 0x800490FCu: goto label_800490FC;
    case 0x80049100u: goto label_80049100;
    case 0x80049104u: goto label_80049104;
    case 0x80049108u: goto label_80049108;
    case 0x8004910Cu: goto label_8004910C;
    case 0x80049110u: goto label_80049110;
    case 0x80049114u: goto label_80049114;
    case 0x80049118u: goto label_80049118;
    case 0x8004911Cu: goto label_8004911C;
    case 0x80049120u: goto label_80049120;
    case 0x80049124u: goto label_80049124;
    case 0x80049128u: goto label_80049128;
    case 0x8004912Cu: goto label_8004912C;
    case 0x80049130u: goto label_80049130;
    case 0x80049134u: goto label_80049134;
    case 0x80049138u: goto label_80049138;
    case 0x8004913Cu: goto label_8004913C;
    case 0x80049140u: goto label_80049140;
    case 0x80049144u: goto label_80049144;
    case 0x80049148u: goto label_80049148;
    case 0x8004914Cu: goto label_8004914C;
    case 0x80049150u: goto label_80049150;
    case 0x80049154u: goto label_80049154;
    case 0x80049158u: goto label_80049158;
    case 0x8004915Cu: goto label_8004915C;
    case 0x80049160u: goto label_80049160;
    case 0x80049164u: goto label_80049164;
    case 0x80049168u: goto label_80049168;
    case 0x8004916Cu: goto label_8004916C;
    case 0x80049170u: goto label_80049170;
    case 0x80049174u: goto label_80049174;
    case 0x80049178u: goto label_80049178;
    case 0x8004917Cu: goto label_8004917C;
    case 0x80049180u: goto label_80049180;
    case 0x80049184u: goto label_80049184;
    case 0x80049188u: goto label_80049188;
    case 0x8004918Cu: goto label_8004918C;
    case 0x80049190u: goto label_80049190;
    case 0x80049194u: goto label_80049194;
    case 0x80049198u: goto label_80049198;
    case 0x8004919Cu: goto label_8004919C;
    case 0x800491A0u: goto label_800491A0;
    case 0x800491A4u: goto label_800491A4;
    case 0x800491A8u: goto label_800491A8;
    case 0x800491ACu: goto label_800491AC;
    case 0x800491B0u: goto label_800491B0;
    case 0x800491B4u: goto label_800491B4;
    case 0x800491B8u: goto label_800491B8;
    case 0x800491BCu: goto label_800491BC;
    case 0x800491C0u: goto label_800491C0;
    case 0x800491C4u: goto label_800491C4;
    case 0x800491C8u: goto label_800491C8;
    case 0x800491CCu: goto label_800491CC;
    case 0x800491D0u: goto label_800491D0;
    case 0x800491D4u: goto label_800491D4;
    case 0x800491D8u: goto label_800491D8;
    case 0x800491DCu: goto label_800491DC;
    case 0x800491E0u: goto label_800491E0;
    case 0x800491E4u: goto label_800491E4;
    case 0x800491E8u: goto label_800491E8;
    case 0x800491ECu: goto label_800491EC;
    case 0x800491F0u: goto label_800491F0;
    case 0x800491F4u: goto label_800491F4;
    case 0x800491F8u: goto label_800491F8;
    case 0x800491FCu: goto label_800491FC;
    case 0x80049200u: goto label_80049200;
    case 0x80049204u: goto label_80049204;
    case 0x80049208u: goto label_80049208;
    case 0x8004920Cu: goto label_8004920C;
    case 0x80049210u: goto label_80049210;
    case 0x80049214u: goto label_80049214;
    case 0x80049218u: goto label_80049218;
    case 0x8004921Cu: goto label_8004921C;
    case 0x80049220u: goto label_80049220;
    case 0x80049224u: goto label_80049224;
    case 0x80049228u: goto label_80049228;
    case 0x8004922Cu: goto label_8004922C;
    case 0x80049230u: goto label_80049230;
    case 0x80049234u: goto label_80049234;
    case 0x80049238u: goto label_80049238;
    case 0x8004923Cu: goto label_8004923C;
    case 0x80049240u: goto label_80049240;
    case 0x80049244u: goto label_80049244;
    case 0x80049248u: goto label_80049248;
    case 0x8004924Cu: goto label_8004924C;
    case 0x80049250u: goto label_80049250;
    case 0x80049254u: goto label_80049254;
    case 0x80049258u: goto label_80049258;
    case 0x8004925Cu: goto label_8004925C;
    case 0x80049260u: goto label_80049260;
    case 0x80049264u: goto label_80049264;
    case 0x80049268u: goto label_80049268;
    case 0x8004926Cu: goto label_8004926C;
    case 0x80049270u: goto label_80049270;
    case 0x80049274u: goto label_80049274;
    case 0x80049278u: goto label_80049278;
    case 0x8004927Cu: goto label_8004927C;
    case 0x80049280u: goto label_80049280;
    case 0x80049284u: goto label_80049284;
    case 0x80049288u: goto label_80049288;
    case 0x8004928Cu: goto label_8004928C;
    case 0x80049290u: goto label_80049290;
    case 0x80049294u: goto label_80049294;
    case 0x80049298u: goto label_80049298;
    case 0x8004929Cu: goto label_8004929C;
    case 0x800492A0u: goto label_800492A0;
    case 0x800492A4u: goto label_800492A4;
    case 0x800492A8u: goto label_800492A8;
    case 0x800492ACu: goto label_800492AC;
    case 0x800492B0u: goto label_800492B0;
    case 0x800492B4u: goto label_800492B4;
    case 0x800492B8u: goto label_800492B8;
    case 0x800492BCu: goto label_800492BC;
    case 0x800492C0u: goto label_800492C0;
    case 0x800492C4u: goto label_800492C4;
    case 0x800492C8u: goto label_800492C8;
    case 0x800492CCu: goto label_800492CC;
    case 0x800492D0u: goto label_800492D0;
    case 0x800492D4u: goto label_800492D4;
    case 0x800492D8u: goto label_800492D8;
    case 0x800492DCu: goto label_800492DC;
    case 0x800492E0u: goto label_800492E0;
    case 0x800492E4u: goto label_800492E4;
    case 0x800492E8u: goto label_800492E8;
    case 0x800492ECu: goto label_800492EC;
    case 0x800492F0u: goto label_800492F0;
    case 0x800492F4u: goto label_800492F4;
    case 0x800492F8u: goto label_800492F8;
    case 0x800492FCu: goto label_800492FC;
    case 0x80049300u: goto label_80049300;
    case 0x80049304u: goto label_80049304;
    case 0x80049308u: goto label_80049308;
    case 0x8004930Cu: goto label_8004930C;
    case 0x80049310u: goto label_80049310;
    case 0x80049314u: goto label_80049314;
    case 0x80049318u: goto label_80049318;
    case 0x8004931Cu: goto label_8004931C;
    case 0x80049320u: goto label_80049320;
    case 0x80049324u: goto label_80049324;
    case 0x80049328u: goto label_80049328;
    case 0x8004932Cu: goto label_8004932C;
    case 0x80049330u: goto label_80049330;
    case 0x80049334u: goto label_80049334;
    case 0x80049338u: goto label_80049338;
    case 0x8004933Cu: goto label_8004933C;
    case 0x80049340u: goto label_80049340;
    case 0x80049344u: goto label_80049344;
    case 0x80049348u: goto label_80049348;
    case 0x8004934Cu: goto label_8004934C;
    case 0x80049350u: goto label_80049350;
    case 0x80049354u: goto label_80049354;
    case 0x80049358u: goto label_80049358;
    case 0x8004935Cu: goto label_8004935C;
    case 0x80049360u: goto label_80049360;
    case 0x80049364u: goto label_80049364;
    case 0x80049368u: goto label_80049368;
    case 0x8004936Cu: goto label_8004936C;
    case 0x80049370u: goto label_80049370;
    case 0x80049374u: goto label_80049374;
    case 0x80049378u: goto label_80049378;
    case 0x8004937Cu: goto label_8004937C;
    case 0x80049380u: goto label_80049380;
    case 0x80049384u: goto label_80049384;
    case 0x80049388u: goto label_80049388;
    case 0x8004938Cu: goto label_8004938C;
    case 0x80049390u: goto label_80049390;
    case 0x80049394u: goto label_80049394;
    case 0x80049398u: goto label_80049398;
    case 0x8004939Cu: goto label_8004939C;
    case 0x800493A0u: goto label_800493A0;
    case 0x800493A4u: goto label_800493A4;
    case 0x800493A8u: goto label_800493A8;
    case 0x800493ACu: goto label_800493AC;
    case 0x800493B0u: goto label_800493B0;
    case 0x800493B4u: goto label_800493B4;
    case 0x800493B8u: goto label_800493B8;
    case 0x800493BCu: goto label_800493BC;
    case 0x800493C0u: goto label_800493C0;
    case 0x800493C4u: goto label_800493C4;
    case 0x800493C8u: goto label_800493C8;
    case 0x800493CCu: goto label_800493CC;
    case 0x800493D0u: goto label_800493D0;
    case 0x800493D4u: goto label_800493D4;
    case 0x800493D8u: goto label_800493D8;
    case 0x800493DCu: goto label_800493DC;
    case 0x800493E0u: goto label_800493E0;
    case 0x800493E4u: goto label_800493E4;
    case 0x800493E8u: goto label_800493E8;
    case 0x800493ECu: goto label_800493EC;
    case 0x800493F0u: goto label_800493F0;
    case 0x800493F4u: goto label_800493F4;
    case 0x800493F8u: goto label_800493F8;
    case 0x800493FCu: goto label_800493FC;
    case 0x80049400u: goto label_80049400;
    case 0x80049404u: goto label_80049404;
    case 0x80049408u: goto label_80049408;
    case 0x8004940Cu: goto label_8004940C;
    case 0x80049410u: goto label_80049410;
    case 0x80049414u: goto label_80049414;
    case 0x80049418u: goto label_80049418;
    case 0x8004941Cu: goto label_8004941C;
    case 0x80049420u: goto label_80049420;
    case 0x80049424u: goto label_80049424;
    case 0x80049428u: goto label_80049428;
    case 0x8004942Cu: goto label_8004942C;
    case 0x80049430u: goto label_80049430;
    case 0x80049434u: goto label_80049434;
    case 0x80049438u: goto label_80049438;
    case 0x8004943Cu: goto label_8004943C;
    case 0x80049440u: goto label_80049440;
    case 0x80049444u: goto label_80049444;
    case 0x80049448u: goto label_80049448;
    case 0x8004944Cu: goto label_8004944C;
    case 0x80049450u: goto label_80049450;
    case 0x80049454u: goto label_80049454;
    case 0x80049458u: goto label_80049458;
    case 0x8004945Cu: goto label_8004945C;
    case 0x80049460u: goto label_80049460;
    case 0x80049464u: goto label_80049464;
    case 0x80049468u: goto label_80049468;
    case 0x8004946Cu: goto label_8004946C;
    case 0x80049470u: goto label_80049470;
    case 0x80049474u: goto label_80049474;
    case 0x80049478u: goto label_80049478;
    case 0x8004947Cu: goto label_8004947C;
    case 0x80049480u: goto label_80049480;
    case 0x80049484u: goto label_80049484;
    case 0x80049488u: goto label_80049488;
    case 0x8004948Cu: goto label_8004948C;
    case 0x80049490u: goto label_80049490;
    case 0x80049494u: goto label_80049494;
    case 0x80049498u: goto label_80049498;
    case 0x8004949Cu: goto label_8004949C;
    case 0x800494A0u: goto label_800494A0;
    case 0x800494A4u: goto label_800494A4;
    case 0x800494A8u: goto label_800494A8;
    case 0x800494ACu: goto label_800494AC;
    case 0x800494B0u: goto label_800494B0;
    case 0x800494B4u: goto label_800494B4;
    case 0x800494B8u: goto label_800494B8;
    case 0x800494BCu: goto label_800494BC;
    case 0x800494C0u: goto label_800494C0;
    case 0x800494C4u: goto label_800494C4;
    case 0x800494C8u: goto label_800494C8;
    case 0x800494CCu: goto label_800494CC;
    case 0x800494D0u: goto label_800494D0;
    case 0x800494D4u: goto label_800494D4;
    case 0x800494D8u: goto label_800494D8;
    case 0x800494DCu: goto label_800494DC;
    case 0x800494E0u: goto label_800494E0;
    case 0x800494E4u: goto label_800494E4;
    case 0x800494E8u: goto label_800494E8;
    case 0x800494ECu: goto label_800494EC;
    case 0x800494F0u: goto label_800494F0;
    case 0x800494F4u: goto label_800494F4;
    case 0x800494F8u: goto label_800494F8;
    case 0x800494FCu: goto label_800494FC;
    case 0x80049500u: goto label_80049500;
    case 0x80049504u: goto label_80049504;
    case 0x80049508u: goto label_80049508;
    case 0x8004950Cu: goto label_8004950C;
    case 0x80049510u: goto label_80049510;
    case 0x80049514u: goto label_80049514;
    case 0x80049518u: goto label_80049518;
    case 0x8004951Cu: goto label_8004951C;
    case 0x80049520u: goto label_80049520;
    case 0x80049524u: goto label_80049524;
    case 0x80049528u: goto label_80049528;
    case 0x8004952Cu: goto label_8004952C;
    case 0x80049530u: goto label_80049530;
    case 0x80049534u: goto label_80049534;
    case 0x80049538u: goto label_80049538;
    case 0x8004953Cu: goto label_8004953C;
    case 0x80049540u: goto label_80049540;
    case 0x80049544u: goto label_80049544;
    case 0x80049548u: goto label_80049548;
    case 0x8004954Cu: goto label_8004954C;
    case 0x80049550u: goto label_80049550;
    case 0x80049554u: goto label_80049554;
    case 0x80049558u: goto label_80049558;
    case 0x8004955Cu: goto label_8004955C;
    case 0x80049560u: goto label_80049560;
    case 0x80049564u: goto label_80049564;
    case 0x80049568u: goto label_80049568;
    case 0x8004956Cu: goto label_8004956C;
    case 0x80049570u: goto label_80049570;
    case 0x80049574u: goto label_80049574;
    case 0x80049578u: goto label_80049578;
    case 0x8004957Cu: goto label_8004957C;
    case 0x80049580u: goto label_80049580;
    case 0x80049584u: goto label_80049584;
    case 0x80049588u: goto label_80049588;
    case 0x8004958Cu: goto label_8004958C;
    case 0x80049590u: goto label_80049590;
    case 0x80049594u: goto label_80049594;
    case 0x80049598u: goto label_80049598;
    case 0x8004959Cu: goto label_8004959C;
    case 0x800495A0u: goto label_800495A0;
    case 0x800495A4u: goto label_800495A4;
    case 0x800495A8u: goto label_800495A8;
    case 0x800495ACu: goto label_800495AC;
    case 0x800495B0u: goto label_800495B0;
    case 0x800495B4u: goto label_800495B4;
    case 0x800495B8u: goto label_800495B8;
    case 0x800495BCu: goto label_800495BC;
    case 0x800495C0u: goto label_800495C0;
    case 0x800495C4u: goto label_800495C4;
    case 0x800495C8u: goto label_800495C8;
    case 0x800495CCu: goto label_800495CC;
    case 0x800495D0u: goto label_800495D0;
    case 0x800495D4u: goto label_800495D4;
    case 0x800495D8u: goto label_800495D8;
    case 0x800495DCu: goto label_800495DC;
    case 0x800495E0u: goto label_800495E0;
    case 0x800495E4u: goto label_800495E4;
    case 0x800495E8u: goto label_800495E8;
    case 0x800495ECu: goto label_800495EC;
    case 0x800495F0u: goto label_800495F0;
    case 0x800495F4u: goto label_800495F4;
    case 0x800495F8u: goto label_800495F8;
    case 0x800495FCu: goto label_800495FC;
    case 0x80049600u: goto label_80049600;
    case 0x80049604u: goto label_80049604;
    case 0x80049608u: goto label_80049608;
    case 0x8004960Cu: goto label_8004960C;
    case 0x80049610u: goto label_80049610;
    case 0x80049614u: goto label_80049614;
    case 0x80049618u: goto label_80049618;
    case 0x8004961Cu: goto label_8004961C;
    case 0x80049620u: goto label_80049620;
    case 0x80049624u: goto label_80049624;
    case 0x80049628u: goto label_80049628;
    case 0x8004962Cu: goto label_8004962C;
    case 0x80049630u: goto label_80049630;
    case 0x80049634u: goto label_80049634;
    case 0x80049638u: goto label_80049638;
    case 0x8004963Cu: goto label_8004963C;
    case 0x80049640u: goto label_80049640;
    case 0x80049644u: goto label_80049644;
    case 0x80049648u: goto label_80049648;
    case 0x8004964Cu: goto label_8004964C;
    case 0x80049650u: goto label_80049650;
    case 0x80049654u: goto label_80049654;
    case 0x80049658u: goto label_80049658;
    case 0x8004965Cu: goto label_8004965C;
    case 0x80049660u: goto label_80049660;
    case 0x80049664u: goto label_80049664;
    case 0x80049668u: goto label_80049668;
    case 0x8004966Cu: goto label_8004966C;
    case 0x80049670u: goto label_80049670;
    case 0x80049674u: goto label_80049674;
    case 0x80049678u: goto label_80049678;
    case 0x8004967Cu: goto label_8004967C;
    case 0x80049680u: goto label_80049680;
    case 0x80049684u: goto label_80049684;
    case 0x80049688u: goto label_80049688;
    case 0x8004968Cu: goto label_8004968C;
    case 0x80049690u: goto label_80049690;
    case 0x80049694u: goto label_80049694;
    case 0x80049698u: goto label_80049698;
    case 0x8004969Cu: goto label_8004969C;
    case 0x800496A0u: goto label_800496A0;
    case 0x800496A4u: goto label_800496A4;
    case 0x800496A8u: goto label_800496A8;
    case 0x800496ACu: goto label_800496AC;
    case 0x800496B0u: goto label_800496B0;
    case 0x800496B4u: goto label_800496B4;
    case 0x800496B8u: goto label_800496B8;
    case 0x800496BCu: goto label_800496BC;
    case 0x800496C0u: goto label_800496C0;
    case 0x800496C4u: goto label_800496C4;
    case 0x800496C8u: goto label_800496C8;
    case 0x800496CCu: goto label_800496CC;
    case 0x800496D0u: goto label_800496D0;
    case 0x800496D4u: goto label_800496D4;
    case 0x800496D8u: goto label_800496D8;
    case 0x800496DCu: goto label_800496DC;
    case 0x800496E0u: goto label_800496E0;
    case 0x800496E4u: goto label_800496E4;
    case 0x800496E8u: goto label_800496E8;
    case 0x800496ECu: goto label_800496EC;
    case 0x800496F0u: goto label_800496F0;
    case 0x800496F4u: goto label_800496F4;
    case 0x800496F8u: goto label_800496F8;
    case 0x800496FCu: goto label_800496FC;
    case 0x80049700u: goto label_80049700;
    case 0x80049704u: goto label_80049704;
    case 0x80049708u: goto label_80049708;
    case 0x8004970Cu: goto label_8004970C;
    case 0x80049710u: goto label_80049710;
    case 0x80049714u: goto label_80049714;
    case 0x80049718u: goto label_80049718;
    case 0x8004971Cu: goto label_8004971C;
    case 0x80049720u: goto label_80049720;
    case 0x80049724u: goto label_80049724;
    case 0x80049728u: goto label_80049728;
    case 0x8004972Cu: goto label_8004972C;
    case 0x80049730u: goto label_80049730;
    case 0x80049734u: goto label_80049734;
    case 0x80049738u: goto label_80049738;
    case 0x8004973Cu: goto label_8004973C;
    case 0x80049740u: goto label_80049740;
    case 0x80049744u: goto label_80049744;
    case 0x80049748u: goto label_80049748;
    case 0x8004974Cu: goto label_8004974C;
    case 0x80049750u: goto label_80049750;
    case 0x80049754u: goto label_80049754;
    case 0x80049758u: goto label_80049758;
    case 0x8004975Cu: goto label_8004975C;
    case 0x80049760u: goto label_80049760;
    case 0x80049764u: goto label_80049764;
    case 0x80049768u: goto label_80049768;
    case 0x8004976Cu: goto label_8004976C;
    case 0x80049770u: goto label_80049770;
    case 0x80049774u: goto label_80049774;
    case 0x80049778u: goto label_80049778;
    case 0x8004977Cu: goto label_8004977C;
    case 0x80049780u: goto label_80049780;
    case 0x80049784u: goto label_80049784;
    case 0x80049788u: goto label_80049788;
    case 0x8004978Cu: goto label_8004978C;
    case 0x80049790u: goto label_80049790;
    case 0x80049794u: goto label_80049794;
    case 0x80049798u: goto label_80049798;
    case 0x8004979Cu: goto label_8004979C;
    case 0x800497A0u: goto label_800497A0;
    case 0x800497A4u: goto label_800497A4;
    case 0x800497A8u: goto label_800497A8;
    case 0x800497ACu: goto label_800497AC;
    case 0x800497B0u: goto label_800497B0;
    case 0x800497B4u: goto label_800497B4;
    case 0x800497B8u: goto label_800497B8;
    case 0x800497BCu: goto label_800497BC;
    case 0x800497C0u: goto label_800497C0;
    case 0x800497C4u: goto label_800497C4;
    case 0x800497C8u: goto label_800497C8;
    case 0x800497CCu: goto label_800497CC;
    case 0x800497D0u: goto label_800497D0;
    case 0x800497D4u: goto label_800497D4;
    case 0x800497D8u: goto label_800497D8;
    case 0x800497DCu: goto label_800497DC;
    case 0x800497E0u: goto label_800497E0;
    case 0x800497E4u: goto label_800497E4;
    case 0x800497E8u: goto label_800497E8;
    case 0x800497ECu: goto label_800497EC;
    case 0x800497F0u: goto label_800497F0;
    case 0x800497F4u: goto label_800497F4;
    case 0x800497F8u: goto label_800497F8;
    case 0x800497FCu: goto label_800497FC;
    case 0x80049800u: goto label_80049800;
    case 0x80049804u: goto label_80049804;
    case 0x80049808u: goto label_80049808;
    case 0x8004980Cu: goto label_8004980C;
    case 0x80049810u: goto label_80049810;
    case 0x80049814u: goto label_80049814;
    case 0x80049818u: goto label_80049818;
    case 0x8004981Cu: goto label_8004981C;
    case 0x80049820u: goto label_80049820;
    case 0x80049824u: goto label_80049824;
    case 0x80049828u: goto label_80049828;
    case 0x8004982Cu: goto label_8004982C;
    case 0x80049830u: goto label_80049830;
    case 0x80049834u: goto label_80049834;
    case 0x80049838u: goto label_80049838;
    case 0x8004983Cu: goto label_8004983C;
    case 0x80049840u: goto label_80049840;
    case 0x80049844u: goto label_80049844;
    case 0x80049848u: goto label_80049848;
    case 0x8004984Cu: goto label_8004984C;
    case 0x80049850u: goto label_80049850;
    case 0x80049854u: goto label_80049854;
    case 0x80049858u: goto label_80049858;
    case 0x8004985Cu: goto label_8004985C;
    case 0x80049860u: goto label_80049860;
    case 0x80049864u: goto label_80049864;
    case 0x80049868u: goto label_80049868;
    case 0x8004986Cu: goto label_8004986C;
    case 0x80049870u: goto label_80049870;
    case 0x80049874u: goto label_80049874;
    case 0x80049878u: goto label_80049878;
    case 0x8004987Cu: goto label_8004987C;
    case 0x80049880u: goto label_80049880;
    case 0x80049884u: goto label_80049884;
    case 0x80049888u: goto label_80049888;
    case 0x8004988Cu: goto label_8004988C;
    case 0x80049890u: goto label_80049890;
    case 0x80049894u: goto label_80049894;
    case 0x80049898u: goto label_80049898;
    case 0x8004989Cu: goto label_8004989C;
    case 0x800498A0u: goto label_800498A0;
    case 0x800498A4u: goto label_800498A4;
    case 0x800498A8u: goto label_800498A8;
    case 0x800498ACu: goto label_800498AC;
    case 0x800498B0u: goto label_800498B0;
    case 0x800498B4u: goto label_800498B4;
    case 0x800498B8u: goto label_800498B8;
    case 0x800498BCu: goto label_800498BC;
    case 0x800498C0u: goto label_800498C0;
    case 0x800498C4u: goto label_800498C4;
    case 0x800498C8u: goto label_800498C8;
    case 0x800498CCu: goto label_800498CC;
    case 0x800498D0u: goto label_800498D0;
    case 0x800498D4u: goto label_800498D4;
    case 0x800498D8u: goto label_800498D8;
    case 0x800498DCu: goto label_800498DC;
    case 0x800498E0u: goto label_800498E0;
    case 0x800498E4u: goto label_800498E4;
    case 0x800498E8u: goto label_800498E8;
    case 0x800498ECu: goto label_800498EC;
    case 0x800498F0u: goto label_800498F0;
    case 0x800498F4u: goto label_800498F4;
    case 0x800498F8u: goto label_800498F8;
    case 0x800498FCu: goto label_800498FC;
    case 0x80049900u: goto label_80049900;
    case 0x80049904u: goto label_80049904;
    case 0x80049908u: goto label_80049908;
    case 0x8004990Cu: goto label_8004990C;
    case 0x80049910u: goto label_80049910;
    case 0x80049914u: goto label_80049914;
    case 0x80049918u: goto label_80049918;
    case 0x8004991Cu: goto label_8004991C;
    case 0x80049920u: goto label_80049920;
    case 0x80049924u: goto label_80049924;
    case 0x80049928u: goto label_80049928;
    case 0x8004992Cu: goto label_8004992C;
    case 0x80049930u: goto label_80049930;
    case 0x80049934u: goto label_80049934;
    case 0x80049938u: goto label_80049938;
    case 0x8004993Cu: goto label_8004993C;
    case 0x80049940u: goto label_80049940;
    case 0x80049944u: goto label_80049944;
    case 0x80049948u: goto label_80049948;
    case 0x8004994Cu: goto label_8004994C;
    case 0x80049950u: goto label_80049950;
    case 0x80049954u: goto label_80049954;
    case 0x80049958u: goto label_80049958;
    case 0x8004995Cu: goto label_8004995C;
    case 0x80049960u: goto label_80049960;
    case 0x80049964u: goto label_80049964;
    case 0x80049968u: goto label_80049968;
    case 0x8004996Cu: goto label_8004996C;
    case 0x80049970u: goto label_80049970;
    case 0x80049974u: goto label_80049974;
    case 0x80049978u: goto label_80049978;
    case 0x8004997Cu: goto label_8004997C;
    case 0x80049980u: goto label_80049980;
    case 0x80049984u: goto label_80049984;
    case 0x80049988u: goto label_80049988;
    case 0x8004998Cu: goto label_8004998C;
    case 0x80049990u: goto label_80049990;
    case 0x80049994u: goto label_80049994;
    case 0x80049998u: goto label_80049998;
    case 0x8004999Cu: goto label_8004999C;
    case 0x800499A0u: goto label_800499A0;
    case 0x800499A4u: goto label_800499A4;
    case 0x800499A8u: goto label_800499A8;
    case 0x800499ACu: goto label_800499AC;
    case 0x800499B0u: goto label_800499B0;
    case 0x800499B4u: goto label_800499B4;
    case 0x800499B8u: goto label_800499B8;
    case 0x800499BCu: goto label_800499BC;
    case 0x800499C0u: goto label_800499C0;
    case 0x800499C4u: goto label_800499C4;
    case 0x800499C8u: goto label_800499C8;
    case 0x800499CCu: goto label_800499CC;
    case 0x800499D0u: goto label_800499D0;
    case 0x800499D4u: goto label_800499D4;
    case 0x800499D8u: goto label_800499D8;
    case 0x800499DCu: goto label_800499DC;
    case 0x800499E0u: goto label_800499E0;
    case 0x800499E4u: goto label_800499E4;
    case 0x800499E8u: goto label_800499E8;
    case 0x800499ECu: goto label_800499EC;
    case 0x800499F0u: goto label_800499F0;
    case 0x800499F4u: goto label_800499F4;
    case 0x800499F8u: goto label_800499F8;
    case 0x800499FCu: goto label_800499FC;
    case 0x80049A00u: goto label_80049A00;
    case 0x80049A04u: goto label_80049A04;
    case 0x80049A08u: goto label_80049A08;
    case 0x80049A0Cu: goto label_80049A0C;
    case 0x80049A10u: goto label_80049A10;
    case 0x80049A14u: goto label_80049A14;
    case 0x80049A18u: goto label_80049A18;
    case 0x80049A1Cu: goto label_80049A1C;
    case 0x80049A20u: goto label_80049A20;
    case 0x80049A24u: goto label_80049A24;
    case 0x80049A28u: goto label_80049A28;
    case 0x80049A2Cu: goto label_80049A2C;
    case 0x80049A30u: goto label_80049A30;
    case 0x80049A34u: goto label_80049A34;
    case 0x80049A38u: goto label_80049A38;
    case 0x80049A3Cu: goto label_80049A3C;
    case 0x80049A40u: goto label_80049A40;
    case 0x80049A44u: goto label_80049A44;
    case 0x80049A48u: goto label_80049A48;
    case 0x80049A4Cu: goto label_80049A4C;
    case 0x80049A50u: goto label_80049A50;
    case 0x80049A54u: goto label_80049A54;
    case 0x80049A58u: goto label_80049A58;
    case 0x80049A5Cu: goto label_80049A5C;
    case 0x80049A60u: goto label_80049A60;
    case 0x80049A64u: goto label_80049A64;
    case 0x80049A68u: goto label_80049A68;
    case 0x80049A6Cu: goto label_80049A6C;
    case 0x80049A70u: goto label_80049A70;
    case 0x80049A74u: goto label_80049A74;
    case 0x80049A78u: goto label_80049A78;
    case 0x80049A7Cu: goto label_80049A7C;
    case 0x80049A80u: goto label_80049A80;
    case 0x80049A84u: goto label_80049A84;
    case 0x80049A88u: goto label_80049A88;
    case 0x80049A8Cu: goto label_80049A8C;
    case 0x80049A90u: goto label_80049A90;
    case 0x80049A94u: goto label_80049A94;
    case 0x80049A98u: goto label_80049A98;
    case 0x80049A9Cu: goto label_80049A9C;
    case 0x80049AA0u: goto label_80049AA0;
    case 0x80049AA4u: goto label_80049AA4;
    case 0x80049AA8u: goto label_80049AA8;
    case 0x80049AACu: goto label_80049AAC;
    case 0x80049AB0u: goto label_80049AB0;
    case 0x80049AB4u: goto label_80049AB4;
    case 0x80049AB8u: goto label_80049AB8;
    case 0x80049ABCu: goto label_80049ABC;
    case 0x80049AC0u: goto label_80049AC0;
    case 0x80049AC4u: goto label_80049AC4;
    case 0x80049AC8u: goto label_80049AC8;
    case 0x80049ACCu: goto label_80049ACC;
    case 0x80049AD0u: goto label_80049AD0;
    case 0x80049AD4u: goto label_80049AD4;
    case 0x80049AD8u: goto label_80049AD8;
    case 0x80049ADCu: goto label_80049ADC;
    case 0x80049AE0u: goto label_80049AE0;
    case 0x80049AE4u: goto label_80049AE4;
    case 0x80049AE8u: goto label_80049AE8;
    case 0x80049AECu: goto label_80049AEC;
    case 0x80049AF0u: goto label_80049AF0;
    case 0x80049AF4u: goto label_80049AF4;
    case 0x80049AF8u: goto label_80049AF8;
    case 0x80049AFCu: goto label_80049AFC;
    case 0x80049B00u: goto label_80049B00;
    case 0x80049B04u: goto label_80049B04;
    case 0x80049B08u: goto label_80049B08;
    case 0x80049B0Cu: goto label_80049B0C;
    case 0x80049B10u: goto label_80049B10;
    case 0x80049B14u: goto label_80049B14;
    case 0x80049B18u: goto label_80049B18;
    case 0x80049B1Cu: goto label_80049B1C;
    case 0x80049B20u: goto label_80049B20;
    case 0x80049B24u: goto label_80049B24;
    case 0x80049B28u: goto label_80049B28;
    case 0x80049B2Cu: goto label_80049B2C;
    case 0x80049B30u: goto label_80049B30;
    case 0x80049B34u: goto label_80049B34;
    case 0x80049B38u: goto label_80049B38;
    case 0x80049B3Cu: goto label_80049B3C;
    case 0x80049B40u: goto label_80049B40;
    case 0x80049B44u: goto label_80049B44;
    case 0x80049B48u: goto label_80049B48;
    case 0x80049B4Cu: goto label_80049B4C;
    case 0x80049B50u: goto label_80049B50;
    case 0x80049B54u: goto label_80049B54;
    case 0x80049B58u: goto label_80049B58;
    case 0x80049B5Cu: goto label_80049B5C;
    case 0x80049B60u: goto label_80049B60;
    case 0x80049B64u: goto label_80049B64;
    case 0x80049B68u: goto label_80049B68;
    case 0x80049B6Cu: goto label_80049B6C;
    case 0x80049B70u: goto label_80049B70;
    case 0x80049B74u: goto label_80049B74;
    case 0x80049B78u: goto label_80049B78;
    case 0x80049B7Cu: goto label_80049B7C;
    case 0x80049B80u: goto label_80049B80;
    case 0x80049B84u: goto label_80049B84;
    case 0x80049B88u: goto label_80049B88;
    case 0x80049B8Cu: goto label_80049B8C;
    case 0x80049B90u: goto label_80049B90;
    case 0x80049B94u: goto label_80049B94;
    case 0x80049B98u: goto label_80049B98;
    case 0x80049B9Cu: goto label_80049B9C;
    case 0x80049BA0u: goto label_80049BA0;
    case 0x80049BA4u: goto label_80049BA4;
    case 0x80049BA8u: goto label_80049BA8;
    case 0x80049BACu: goto label_80049BAC;
    case 0x80049BB0u: goto label_80049BB0;
    case 0x80049BB4u: goto label_80049BB4;
    case 0x80049BB8u: goto label_80049BB8;
    case 0x80049BBCu: goto label_80049BBC;
    case 0x80049BC0u: goto label_80049BC0;
    case 0x80049BC4u: goto label_80049BC4;
    case 0x80049BC8u: goto label_80049BC8;
    case 0x80049BCCu: goto label_80049BCC;
    case 0x80049BD0u: goto label_80049BD0;
    case 0x80049BD4u: goto label_80049BD4;
    case 0x80049BD8u: goto label_80049BD8;
    case 0x80049BDCu: goto label_80049BDC;
    case 0x80049BE0u: goto label_80049BE0;
    case 0x80049BE4u: goto label_80049BE4;
    case 0x80049BE8u: goto label_80049BE8;
    case 0x80049BECu: goto label_80049BEC;
    case 0x80049BF0u: goto label_80049BF0;
    case 0x80049BF4u: goto label_80049BF4;
    case 0x80049BF8u: goto label_80049BF8;
    case 0x80049BFCu: goto label_80049BFC;
    case 0x80049C00u: goto label_80049C00;
    case 0x80049C04u: goto label_80049C04;
    case 0x80049C08u: goto label_80049C08;
    case 0x80049C0Cu: goto label_80049C0C;
    case 0x80049C10u: goto label_80049C10;
    case 0x80049C14u: goto label_80049C14;
    case 0x80049C18u: goto label_80049C18;
    case 0x80049C1Cu: goto label_80049C1C;
    case 0x80049C20u: goto label_80049C20;
    case 0x80049C24u: goto label_80049C24;
    case 0x80049C28u: goto label_80049C28;
    case 0x80049C2Cu: goto label_80049C2C;
    case 0x80049C30u: goto label_80049C30;
    case 0x80049C34u: goto label_80049C34;
    case 0x80049C38u: goto label_80049C38;
    case 0x80049C3Cu: goto label_80049C3C;
    case 0x80049C40u: goto label_80049C40;
    case 0x80049C44u: goto label_80049C44;
    case 0x80049C48u: goto label_80049C48;
    case 0x80049C4Cu: goto label_80049C4C;
    case 0x80049C50u: goto label_80049C50;
    case 0x80049C54u: goto label_80049C54;
    case 0x80049C58u: goto label_80049C58;
    case 0x80049C5Cu: goto label_80049C5C;
    case 0x80049C60u: goto label_80049C60;
    case 0x80049C64u: goto label_80049C64;
    case 0x80049C68u: goto label_80049C68;
    case 0x80049C6Cu: goto label_80049C6C;
    case 0x80049C70u: goto label_80049C70;
    case 0x80049C74u: goto label_80049C74;
    case 0x80049C78u: goto label_80049C78;
    case 0x80049C7Cu: goto label_80049C7C;
    case 0x80049C80u: goto label_80049C80;
    case 0x80049C84u: goto label_80049C84;
    case 0x80049C88u: goto label_80049C88;
    case 0x80049C8Cu: goto label_80049C8C;
    case 0x80049C90u: goto label_80049C90;
    case 0x80049C94u: goto label_80049C94;
    case 0x80049C98u: goto label_80049C98;
    case 0x80049C9Cu: goto label_80049C9C;
    case 0x80049CA0u: goto label_80049CA0;
    case 0x80049CA4u: goto label_80049CA4;
    case 0x80049CA8u: goto label_80049CA8;
    case 0x80049CACu: goto label_80049CAC;
    case 0x80049CB0u: goto label_80049CB0;
    case 0x80049CB4u: goto label_80049CB4;
    case 0x80049CB8u: goto label_80049CB8;
    case 0x80049CBCu: goto label_80049CBC;
    case 0x80049CC0u: goto label_80049CC0;
    case 0x80049CC4u: goto label_80049CC4;
    case 0x80049CC8u: goto label_80049CC8;
    case 0x80049CCCu: goto label_80049CCC;
    case 0x80049CD0u: goto label_80049CD0;
    case 0x80049CD4u: goto label_80049CD4;
    case 0x80049CD8u: goto label_80049CD8;
    case 0x80049CDCu: goto label_80049CDC;
    case 0x80049CE0u: goto label_80049CE0;
    case 0x80049CE4u: goto label_80049CE4;
    case 0x80049CE8u: goto label_80049CE8;
    case 0x80049CECu: goto label_80049CEC;
    case 0x80049CF0u: goto label_80049CF0;
    case 0x80049CF4u: goto label_80049CF4;
    case 0x80049CF8u: goto label_80049CF8;
    case 0x80049CFCu: goto label_80049CFC;
    case 0x80049D00u: goto label_80049D00;
    case 0x80049D04u: goto label_80049D04;
    case 0x80049D08u: goto label_80049D08;
    case 0x80049D0Cu: goto label_80049D0C;
    case 0x80049D10u: goto label_80049D10;
    case 0x80049D14u: goto label_80049D14;
    case 0x80049D18u: goto label_80049D18;
    case 0x80049D1Cu: goto label_80049D1C;
    case 0x80049D20u: goto label_80049D20;
    case 0x80049D24u: goto label_80049D24;
    case 0x80049D28u: goto label_80049D28;
    case 0x80049D2Cu: goto label_80049D2C;
    case 0x80049D30u: goto label_80049D30;
    case 0x80049D34u: goto label_80049D34;
    case 0x80049D38u: goto label_80049D38;
    case 0x80049D3Cu: goto label_80049D3C;
    case 0x80049D40u: goto label_80049D40;
    case 0x80049D44u: goto label_80049D44;
    case 0x80049D48u: goto label_80049D48;
    case 0x80049D4Cu: goto label_80049D4C;
    case 0x80049D50u: goto label_80049D50;
    case 0x80049D54u: goto label_80049D54;
    case 0x80049D58u: goto label_80049D58;
    case 0x80049D5Cu: goto label_80049D5C;
    case 0x80049D60u: goto label_80049D60;
    case 0x80049D64u: goto label_80049D64;
    case 0x80049D68u: goto label_80049D68;
    case 0x80049D6Cu: goto label_80049D6C;
    case 0x80049D70u: goto label_80049D70;
    case 0x80049D74u: goto label_80049D74;
    case 0x80049D78u: goto label_80049D78;
    case 0x80049D7Cu: goto label_80049D7C;
    case 0x80049D80u: goto label_80049D80;
    case 0x80049D84u: goto label_80049D84;
    case 0x80049D88u: goto label_80049D88;
    case 0x80049D8Cu: goto label_80049D8C;
    case 0x80049D90u: goto label_80049D90;
    case 0x80049D94u: goto label_80049D94;
    case 0x80049D98u: goto label_80049D98;
    case 0x80049D9Cu: goto label_80049D9C;
    case 0x80049DA0u: goto label_80049DA0;
    case 0x80049DA4u: goto label_80049DA4;
    case 0x80049DA8u: goto label_80049DA8;
    case 0x80049DACu: goto label_80049DAC;
    case 0x80049DB0u: goto label_80049DB0;
    case 0x80049DB4u: goto label_80049DB4;
    case 0x80049DB8u: goto label_80049DB8;
    case 0x80049DBCu: goto label_80049DBC;
    case 0x80049DC0u: goto label_80049DC0;
    case 0x80049DC4u: goto label_80049DC4;
    case 0x80049DC8u: goto label_80049DC8;
    case 0x80049DCCu: goto label_80049DCC;
    case 0x80049DD0u: goto label_80049DD0;
    case 0x80049DD4u: goto label_80049DD4;
    case 0x80049DD8u: goto label_80049DD8;
    case 0x80049DDCu: goto label_80049DDC;
    case 0x80049DE0u: goto label_80049DE0;
    case 0x80049DE4u: goto label_80049DE4;
    case 0x80049DE8u: goto label_80049DE8;
    case 0x80049DECu: goto label_80049DEC;
    case 0x80049DF0u: goto label_80049DF0;
    case 0x80049DF4u: goto label_80049DF4;
    case 0x80049DF8u: goto label_80049DF8;
    case 0x80049DFCu: goto label_80049DFC;
    case 0x80049E00u: goto label_80049E00;
    case 0x80049E04u: goto label_80049E04;
    case 0x80049E08u: goto label_80049E08;
    case 0x80049E0Cu: goto label_80049E0C;
    case 0x80049E10u: goto label_80049E10;
    case 0x80049E14u: goto label_80049E14;
    case 0x80049E18u: goto label_80049E18;
    case 0x80049E1Cu: goto label_80049E1C;
    case 0x80049E20u: goto label_80049E20;
    case 0x80049E24u: goto label_80049E24;
    case 0x80049E28u: goto label_80049E28;
    case 0x80049E2Cu: goto label_80049E2C;
    case 0x80049E30u: goto label_80049E30;
    case 0x80049E34u: goto label_80049E34;
    case 0x80049E38u: goto label_80049E38;
    case 0x80049E3Cu: goto label_80049E3C;
    case 0x80049E40u: goto label_80049E40;
    case 0x80049E44u: goto label_80049E44;
    case 0x80049E48u: goto label_80049E48;
    case 0x80049E4Cu: goto label_80049E4C;
    case 0x80049E50u: goto label_80049E50;
    case 0x80049E54u: goto label_80049E54;
    case 0x80049E58u: goto label_80049E58;
    case 0x80049E5Cu: goto label_80049E5C;
    case 0x80049E60u: goto label_80049E60;
    case 0x80049E64u: goto label_80049E64;
    case 0x80049E68u: goto label_80049E68;
    case 0x80049E6Cu: goto label_80049E6C;
    case 0x80049E70u: goto label_80049E70;
    case 0x80049E74u: goto label_80049E74;
    case 0x80049E78u: goto label_80049E78;
    case 0x80049E7Cu: goto label_80049E7C;
    case 0x80049E80u: goto label_80049E80;
    case 0x80049E84u: goto label_80049E84;
    case 0x80049E88u: goto label_80049E88;
    case 0x80049E8Cu: goto label_80049E8C;
    case 0x80049E90u: goto label_80049E90;
    case 0x80049E94u: goto label_80049E94;
    case 0x80049E98u: goto label_80049E98;
    case 0x80049E9Cu: goto label_80049E9C;
    case 0x80049EA0u: goto label_80049EA0;
    case 0x80049EA4u: goto label_80049EA4;
    case 0x80049EA8u: goto label_80049EA8;
    case 0x80049EACu: goto label_80049EAC;
    case 0x80049EB0u: goto label_80049EB0;
    case 0x80049EB4u: goto label_80049EB4;
    case 0x80049EB8u: goto label_80049EB8;
    case 0x80049EBCu: goto label_80049EBC;
    case 0x80049EC0u: goto label_80049EC0;
    case 0x80049EC4u: goto label_80049EC4;
    case 0x80049EC8u: goto label_80049EC8;
    case 0x80049ECCu: goto label_80049ECC;
    case 0x80049ED0u: goto label_80049ED0;
    case 0x80049ED4u: goto label_80049ED4;
    case 0x80049ED8u: goto label_80049ED8;
    case 0x80049EDCu: goto label_80049EDC;
    case 0x80049EE0u: goto label_80049EE0;
    case 0x80049EE4u: goto label_80049EE4;
    case 0x80049EE8u: goto label_80049EE8;
    case 0x80049EECu: goto label_80049EEC;
    case 0x80049EF0u: goto label_80049EF0;
    case 0x80049EF4u: goto label_80049EF4;
    case 0x80049EF8u: goto label_80049EF8;
    case 0x80049EFCu: goto label_80049EFC;
    case 0x80049F00u: goto label_80049F00;
    case 0x80049F04u: goto label_80049F04;
    case 0x80049F08u: goto label_80049F08;
    case 0x80049F0Cu: goto label_80049F0C;
    case 0x80049F10u: goto label_80049F10;
    case 0x80049F14u: goto label_80049F14;
    case 0x80049F18u: goto label_80049F18;
    case 0x80049F1Cu: goto label_80049F1C;
    case 0x80049F20u: goto label_80049F20;
    case 0x80049F24u: goto label_80049F24;
    case 0x80049F28u: goto label_80049F28;
    case 0x80049F2Cu: goto label_80049F2C;
    case 0x80049F30u: goto label_80049F30;
    case 0x80049F34u: goto label_80049F34;
    case 0x80049F38u: goto label_80049F38;
    case 0x80049F3Cu: goto label_80049F3C;
    case 0x80049F40u: goto label_80049F40;
    case 0x80049F44u: goto label_80049F44;
    case 0x80049F48u: goto label_80049F48;
    case 0x80049F4Cu: goto label_80049F4C;
    case 0x80049F50u: goto label_80049F50;
    case 0x80049F54u: goto label_80049F54;
    case 0x80049F58u: goto label_80049F58;
    case 0x80049F5Cu: goto label_80049F5C;
    case 0x80049F60u: goto label_80049F60;
    case 0x80049F64u: goto label_80049F64;
    case 0x80049F68u: goto label_80049F68;
    case 0x80049F6Cu: goto label_80049F6C;
    case 0x80049F70u: goto label_80049F70;
    case 0x80049F74u: goto label_80049F74;
    case 0x80049F78u: goto label_80049F78;
    case 0x80049F7Cu: goto label_80049F7C;
    case 0x80049F80u: goto label_80049F80;
    case 0x80049F84u: goto label_80049F84;
    case 0x80049F88u: goto label_80049F88;
    case 0x80049F8Cu: goto label_80049F8C;
    case 0x80049F90u: goto label_80049F90;
    case 0x80049F94u: goto label_80049F94;
    case 0x80049F98u: goto label_80049F98;
    case 0x80049F9Cu: goto label_80049F9C;
    case 0x80049FA0u: goto label_80049FA0;
    case 0x80049FA4u: goto label_80049FA4;
    case 0x80049FA8u: goto label_80049FA8;
    case 0x80049FACu: goto label_80049FAC;
    case 0x80049FB0u: goto label_80049FB0;
    case 0x80049FB4u: goto label_80049FB4;
    case 0x80049FB8u: goto label_80049FB8;
    case 0x80049FBCu: goto label_80049FBC;
    case 0x80049FC0u: goto label_80049FC0;
    case 0x80049FC4u: goto label_80049FC4;
    case 0x80049FC8u: goto label_80049FC8;
    case 0x80049FCCu: goto label_80049FCC;
    case 0x80049FD0u: goto label_80049FD0;
    case 0x80049FD4u: goto label_80049FD4;
    case 0x80049FD8u: goto label_80049FD8;
    case 0x80049FDCu: goto label_80049FDC;
    case 0x80049FE0u: goto label_80049FE0;
    case 0x80049FE4u: goto label_80049FE4;
    case 0x80049FE8u: goto label_80049FE8;
    case 0x80049FECu: goto label_80049FEC;
    case 0x80049FF0u: goto label_80049FF0;
    case 0x80049FF4u: goto label_80049FF4;
    case 0x80049FF8u: goto label_80049FF8;
    case 0x80049FFCu: goto label_80049FFC;
    case 0x8004A000u: goto label_8004A000;
    case 0x8004A004u: goto label_8004A004;
    case 0x8004A008u: goto label_8004A008;
    case 0x8004A00Cu: goto label_8004A00C;
    case 0x8004A010u: goto label_8004A010;
    case 0x8004A014u: goto label_8004A014;
    case 0x8004A018u: goto label_8004A018;
    case 0x8004A01Cu: goto label_8004A01C;
    case 0x8004A020u: goto label_8004A020;
    case 0x8004A024u: goto label_8004A024;
    case 0x8004A028u: goto label_8004A028;
    case 0x8004A02Cu: goto label_8004A02C;
    case 0x8004A030u: goto label_8004A030;
    case 0x8004A034u: goto label_8004A034;
    case 0x8004A038u: goto label_8004A038;
    case 0x8004A03Cu: goto label_8004A03C;
    case 0x8004A040u: goto label_8004A040;
    case 0x8004A044u: goto label_8004A044;
    case 0x8004A048u: goto label_8004A048;
    case 0x8004A04Cu: goto label_8004A04C;
    case 0x8004A050u: goto label_8004A050;
    case 0x8004A054u: goto label_8004A054;
    case 0x8004A058u: goto label_8004A058;
    case 0x8004A05Cu: goto label_8004A05C;
    case 0x8004A060u: goto label_8004A060;
    case 0x8004A064u: goto label_8004A064;
    case 0x8004A068u: goto label_8004A068;
    case 0x8004A06Cu: goto label_8004A06C;
    case 0x8004A070u: goto label_8004A070;
    case 0x8004A074u: goto label_8004A074;
    case 0x8004A078u: goto label_8004A078;
    case 0x8004A07Cu: goto label_8004A07C;
    case 0x8004A080u: goto label_8004A080;
    case 0x8004A084u: goto label_8004A084;
    case 0x8004A088u: goto label_8004A088;
    case 0x8004A08Cu: goto label_8004A08C;
    case 0x8004A090u: goto label_8004A090;
    case 0x8004A094u: goto label_8004A094;
    case 0x8004A098u: goto label_8004A098;
    case 0x8004A09Cu: goto label_8004A09C;
    case 0x8004A0A0u: goto label_8004A0A0;
    case 0x8004A0A4u: goto label_8004A0A4;
    case 0x8004A0A8u: goto label_8004A0A8;
    case 0x8004A0ACu: goto label_8004A0AC;
    case 0x8004A0B0u: goto label_8004A0B0;
    case 0x8004A0B4u: goto label_8004A0B4;
    case 0x8004A0B8u: goto label_8004A0B8;
    case 0x8004A0BCu: goto label_8004A0BC;
    case 0x8004A0C0u: goto label_8004A0C0;
    case 0x8004A0C4u: goto label_8004A0C4;
    case 0x8004A0C8u: goto label_8004A0C8;
    case 0x8004A0CCu: goto label_8004A0CC;
    case 0x8004A0D0u: goto label_8004A0D0;
    case 0x8004A0D4u: goto label_8004A0D4;
    case 0x8004A0D8u: goto label_8004A0D8;
    case 0x8004A0DCu: goto label_8004A0DC;
    case 0x8004A0E0u: goto label_8004A0E0;
    case 0x8004A0E4u: goto label_8004A0E4;
    case 0x8004A0E8u: goto label_8004A0E8;
    case 0x8004A0ECu: goto label_8004A0EC;
    case 0x8004A0F0u: goto label_8004A0F0;
    case 0x8004A0F4u: goto label_8004A0F4;
    case 0x8004A0F8u: goto label_8004A0F8;
    case 0x8004A0FCu: goto label_8004A0FC;
    case 0x8004A100u: goto label_8004A100;
    case 0x8004A104u: goto label_8004A104;
    case 0x8004A108u: goto label_8004A108;
    case 0x8004A10Cu: goto label_8004A10C;
    case 0x8004A110u: goto label_8004A110;
    case 0x8004A114u: goto label_8004A114;
    case 0x8004A118u: goto label_8004A118;
    case 0x8004A11Cu: goto label_8004A11C;
    case 0x8004A120u: goto label_8004A120;
    case 0x8004A124u: goto label_8004A124;
    case 0x8004A128u: goto label_8004A128;
    case 0x8004A12Cu: goto label_8004A12C;
    case 0x8004A130u: goto label_8004A130;
    case 0x8004A134u: goto label_8004A134;
    case 0x8004A138u: goto label_8004A138;
    case 0x8004A13Cu: goto label_8004A13C;
    case 0x8004A140u: goto label_8004A140;
    case 0x8004A144u: goto label_8004A144;
    case 0x8004A148u: goto label_8004A148;
    case 0x8004A14Cu: goto label_8004A14C;
    case 0x8004A150u: goto label_8004A150;
    case 0x8004A154u: goto label_8004A154;
    case 0x8004A158u: goto label_8004A158;
    case 0x8004A15Cu: goto label_8004A15C;
    case 0x8004A160u: goto label_8004A160;
    case 0x8004A164u: goto label_8004A164;
    case 0x8004A168u: goto label_8004A168;
    case 0x8004A16Cu: goto label_8004A16C;
    case 0x8004A170u: goto label_8004A170;
    case 0x8004A174u: goto label_8004A174;
    case 0x8004A178u: goto label_8004A178;
    case 0x8004A17Cu: goto label_8004A17C;
    case 0x8004A180u: goto label_8004A180;
    case 0x8004A184u: goto label_8004A184;
    case 0x8004A188u: goto label_8004A188;
    case 0x8004A18Cu: goto label_8004A18C;
    case 0x8004A190u: goto label_8004A190;
    case 0x8004A194u: goto label_8004A194;
    case 0x8004A198u: goto label_8004A198;
    case 0x8004A19Cu: goto label_8004A19C;
    case 0x8004A1A0u: goto label_8004A1A0;
    case 0x8004A1A4u: goto label_8004A1A4;
    case 0x8004A1A8u: goto label_8004A1A8;
    case 0x8004A1ACu: goto label_8004A1AC;
    case 0x8004A1B0u: goto label_8004A1B0;
    case 0x8004A1B4u: goto label_8004A1B4;
    case 0x8004A1B8u: goto label_8004A1B8;
    case 0x8004A1BCu: goto label_8004A1BC;
    case 0x8004A1C0u: goto label_8004A1C0;
    case 0x8004A1C4u: goto label_8004A1C4;
    case 0x8004A1C8u: goto label_8004A1C8;
    case 0x8004A1CCu: goto label_8004A1CC;
    case 0x8004A1D0u: goto label_8004A1D0;
    case 0x8004A1D4u: goto label_8004A1D4;
    case 0x8004A1D8u: goto label_8004A1D8;
    case 0x8004A1DCu: goto label_8004A1DC;
    case 0x8004A1E0u: goto label_8004A1E0;
    case 0x8004A1E4u: goto label_8004A1E4;
    case 0x8004A1E8u: goto label_8004A1E8;
    case 0x8004A1ECu: goto label_8004A1EC;
    case 0x8004A1F0u: goto label_8004A1F0;
    case 0x8004A1F4u: goto label_8004A1F4;
    case 0x8004A1F8u: goto label_8004A1F8;
    case 0x8004A1FCu: goto label_8004A1FC;
    case 0x8004A200u: goto label_8004A200;
    case 0x8004A204u: goto label_8004A204;
    case 0x8004A208u: goto label_8004A208;
    case 0x8004A20Cu: goto label_8004A20C;
    case 0x8004A210u: goto label_8004A210;
    case 0x8004A214u: goto label_8004A214;
    case 0x8004A218u: goto label_8004A218;
    case 0x8004A21Cu: goto label_8004A21C;
    case 0x8004A220u: goto label_8004A220;
    case 0x8004A224u: goto label_8004A224;
    case 0x8004A228u: goto label_8004A228;
    case 0x8004A22Cu: goto label_8004A22C;
    case 0x8004A230u: goto label_8004A230;
    case 0x8004A234u: goto label_8004A234;
    case 0x8004A238u: goto label_8004A238;
    case 0x8004A23Cu: goto label_8004A23C;
    case 0x8004A240u: goto label_8004A240;
    case 0x8004A244u: goto label_8004A244;
    case 0x8004A248u: goto label_8004A248;
    case 0x8004A24Cu: goto label_8004A24C;
    case 0x8004A250u: goto label_8004A250;
    case 0x8004A254u: goto label_8004A254;
    case 0x8004A258u: goto label_8004A258;
    case 0x8004A25Cu: goto label_8004A25C;
    case 0x8004A260u: goto label_8004A260;
    case 0x8004A264u: goto label_8004A264;
    case 0x8004A268u: goto label_8004A268;
    case 0x8004A26Cu: goto label_8004A26C;
    case 0x8004A270u: goto label_8004A270;
    case 0x8004A274u: goto label_8004A274;
    case 0x8004A278u: goto label_8004A278;
    case 0x8004A27Cu: goto label_8004A27C;
    case 0x8004A280u: goto label_8004A280;
    case 0x8004A284u: goto label_8004A284;
    case 0x8004A288u: goto label_8004A288;
    case 0x8004A28Cu: goto label_8004A28C;
    case 0x8004A290u: goto label_8004A290;
    case 0x8004A294u: goto label_8004A294;
    case 0x8004A298u: goto label_8004A298;
    case 0x8004A29Cu: goto label_8004A29C;
    case 0x8004A2A0u: goto label_8004A2A0;
    case 0x8004A2A4u: goto label_8004A2A4;
    case 0x8004A2A8u: goto label_8004A2A8;
    case 0x8004A2ACu: goto label_8004A2AC;
    case 0x8004A2B0u: goto label_8004A2B0;
    case 0x8004A2B4u: goto label_8004A2B4;
    case 0x8004A2B8u: goto label_8004A2B8;
    case 0x8004A2BCu: goto label_8004A2BC;
    case 0x8004A2C0u: goto label_8004A2C0;
    case 0x8004A2C4u: goto label_8004A2C4;
    case 0x8004A2C8u: goto label_8004A2C8;
    case 0x8004A2CCu: goto label_8004A2CC;
    case 0x8004A2D0u: goto label_8004A2D0;
    case 0x8004A2D4u: goto label_8004A2D4;
    case 0x8004A2D8u: goto label_8004A2D8;
    case 0x8004A2DCu: goto label_8004A2DC;
    case 0x8004A2E0u: goto label_8004A2E0;
    case 0x8004A2E4u: goto label_8004A2E4;
    case 0x8004A2E8u: goto label_8004A2E8;
    case 0x8004A2ECu: goto label_8004A2EC;
    case 0x8004A2F0u: goto label_8004A2F0;
    case 0x8004A2F4u: goto label_8004A2F4;
    case 0x8004A2F8u: goto label_8004A2F8;
    case 0x8004A2FCu: goto label_8004A2FC;
    case 0x8004A300u: goto label_8004A300;
    case 0x8004A304u: goto label_8004A304;
    case 0x8004A308u: goto label_8004A308;
    case 0x8004A30Cu: goto label_8004A30C;
    case 0x8004A310u: goto label_8004A310;
    case 0x8004A314u: goto label_8004A314;
    case 0x8004A318u: goto label_8004A318;
    case 0x8004A31Cu: goto label_8004A31C;
    case 0x8004A320u: goto label_8004A320;
    case 0x8004A324u: goto label_8004A324;
    case 0x8004A328u: goto label_8004A328;
    case 0x8004A32Cu: goto label_8004A32C;
    case 0x8004A330u: goto label_8004A330;
    case 0x8004A334u: goto label_8004A334;
    case 0x8004A338u: goto label_8004A338;
    case 0x8004A33Cu: goto label_8004A33C;
    case 0x8004A340u: goto label_8004A340;
    case 0x8004A344u: goto label_8004A344;
    case 0x8004A348u: goto label_8004A348;
    case 0x8004A34Cu: goto label_8004A34C;
    case 0x8004A350u: goto label_8004A350;
    case 0x8004A354u: goto label_8004A354;
    case 0x8004A358u: goto label_8004A358;
    case 0x8004A35Cu: goto label_8004A35C;
    case 0x8004A360u: goto label_8004A360;
    case 0x8004A364u: goto label_8004A364;
    case 0x8004A368u: goto label_8004A368;
    case 0x8004A36Cu: goto label_8004A36C;
    case 0x8004A370u: goto label_8004A370;
    case 0x8004A374u: goto label_8004A374;
    case 0x8004A378u: goto label_8004A378;
    case 0x8004A37Cu: goto label_8004A37C;
    case 0x8004A380u: goto label_8004A380;
    case 0x8004A384u: goto label_8004A384;
    case 0x8004A388u: goto label_8004A388;
    case 0x8004A38Cu: goto label_8004A38C;
    case 0x8004A390u: goto label_8004A390;
    case 0x8004A394u: goto label_8004A394;
    case 0x8004A398u: goto label_8004A398;
    case 0x8004A39Cu: goto label_8004A39C;
    case 0x8004A3A0u: goto label_8004A3A0;
    case 0x8004A3A4u: goto label_8004A3A4;
    case 0x8004A3A8u: goto label_8004A3A8;
    case 0x8004A3ACu: goto label_8004A3AC;
    case 0x8004A3B0u: goto label_8004A3B0;
    case 0x8004A3B4u: goto label_8004A3B4;
    case 0x8004A3B8u: goto label_8004A3B8;
    case 0x8004A3BCu: goto label_8004A3BC;
    case 0x8004A3C0u: goto label_8004A3C0;
    case 0x8004A3C4u: goto label_8004A3C4;
    case 0x8004A3C8u: goto label_8004A3C8;
    case 0x8004A3CCu: goto label_8004A3CC;
    case 0x8004A3D0u: goto label_8004A3D0;
    case 0x8004A3D4u: goto label_8004A3D4;
    case 0x8004A3D8u: goto label_8004A3D8;
    case 0x8004A3DCu: goto label_8004A3DC;
    case 0x8004A3E0u: goto label_8004A3E0;
    case 0x8004A3E4u: goto label_8004A3E4;
    case 0x8004A3E8u: goto label_8004A3E8;
    case 0x8004A3ECu: goto label_8004A3EC;
    case 0x8004A3F0u: goto label_8004A3F0;
    case 0x8004A3F4u: goto label_8004A3F4;
    case 0x8004A3F8u: goto label_8004A3F8;
    case 0x8004A3FCu: goto label_8004A3FC;
    case 0x8004A400u: goto label_8004A400;
    case 0x8004A404u: goto label_8004A404;
    case 0x8004A408u: goto label_8004A408;
    case 0x8004A40Cu: goto label_8004A40C;
    case 0x8004A410u: goto label_8004A410;
    case 0x8004A414u: goto label_8004A414;
    case 0x8004A418u: goto label_8004A418;
    case 0x8004A41Cu: goto label_8004A41C;
    case 0x8004A420u: goto label_8004A420;
    case 0x8004A424u: goto label_8004A424;
    case 0x8004A428u: goto label_8004A428;
    case 0x8004A42Cu: goto label_8004A42C;
    case 0x8004A430u: goto label_8004A430;
    case 0x8004A434u: goto label_8004A434;
    case 0x8004A438u: goto label_8004A438;
    case 0x8004A43Cu: goto label_8004A43C;
    case 0x8004A440u: goto label_8004A440;
    case 0x8004A444u: goto label_8004A444;
    case 0x8004A448u: goto label_8004A448;
    case 0x8004A44Cu: goto label_8004A44C;
    case 0x8004A450u: goto label_8004A450;
    case 0x8004A454u: goto label_8004A454;
    case 0x8004A458u: goto label_8004A458;
    case 0x8004A45Cu: goto label_8004A45C;
    case 0x8004A460u: goto label_8004A460;
    case 0x8004A464u: goto label_8004A464;
    case 0x8004A468u: goto label_8004A468;
    case 0x8004A46Cu: goto label_8004A46C;
    case 0x8004A470u: goto label_8004A470;
    case 0x8004A474u: goto label_8004A474;
    case 0x8004A478u: goto label_8004A478;
    case 0x8004A47Cu: goto label_8004A47C;
    case 0x8004A480u: goto label_8004A480;
    case 0x8004A484u: goto label_8004A484;
    case 0x8004A488u: goto label_8004A488;
    case 0x8004A48Cu: goto label_8004A48C;
    case 0x8004A490u: goto label_8004A490;
    case 0x8004A494u: goto label_8004A494;
    case 0x8004A498u: goto label_8004A498;
    case 0x8004A49Cu: goto label_8004A49C;
    case 0x8004A4A0u: goto label_8004A4A0;
    case 0x8004A4A4u: goto label_8004A4A4;
    case 0x8004A4A8u: goto label_8004A4A8;
    case 0x8004A4ACu: goto label_8004A4AC;
    case 0x8004A4B0u: goto label_8004A4B0;
    case 0x8004A4B4u: goto label_8004A4B4;
    case 0x8004A4B8u: goto label_8004A4B8;
    case 0x8004A4BCu: goto label_8004A4BC;
    case 0x8004A4C0u: goto label_8004A4C0;
    case 0x8004A4C4u: goto label_8004A4C4;
    case 0x8004A4C8u: goto label_8004A4C8;
    case 0x8004A4CCu: goto label_8004A4CC;
    case 0x8004A4D0u: goto label_8004A4D0;
    case 0x8004A4D4u: goto label_8004A4D4;
    case 0x8004A4D8u: goto label_8004A4D8;
    case 0x8004A4DCu: goto label_8004A4DC;
    case 0x8004A4E0u: goto label_8004A4E0;
    case 0x8004A4E4u: goto label_8004A4E4;
    case 0x8004A4E8u: goto label_8004A4E8;
    case 0x8004A4ECu: goto label_8004A4EC;
    case 0x8004A4F0u: goto label_8004A4F0;
    case 0x8004A4F4u: goto label_8004A4F4;
    case 0x8004A4F8u: goto label_8004A4F8;
    case 0x8004A4FCu: goto label_8004A4FC;
    case 0x8004A500u: goto label_8004A500;
    case 0x8004A504u: goto label_8004A504;
    case 0x8004A508u: goto label_8004A508;
    case 0x8004A50Cu: goto label_8004A50C;
    case 0x8004A510u: goto label_8004A510;
    case 0x8004A514u: goto label_8004A514;
    case 0x8004A518u: goto label_8004A518;
    case 0x8004A51Cu: goto label_8004A51C;
    case 0x8004A520u: goto label_8004A520;
    case 0x8004A524u: goto label_8004A524;
    case 0x8004A528u: goto label_8004A528;
    case 0x8004A52Cu: goto label_8004A52C;
    case 0x8004A530u: goto label_8004A530;
    case 0x8004A534u: goto label_8004A534;
    case 0x8004A538u: goto label_8004A538;
    case 0x8004A53Cu: goto label_8004A53C;
    case 0x8004A540u: goto label_8004A540;
    case 0x8004A544u: goto label_8004A544;
    case 0x8004A548u: goto label_8004A548;
    case 0x8004A54Cu: goto label_8004A54C;
    case 0x8004A550u: goto label_8004A550;
    case 0x8004A554u: goto label_8004A554;
    case 0x8004A558u: goto label_8004A558;
    case 0x8004A55Cu: goto label_8004A55C;
    case 0x8004A560u: goto label_8004A560;
    case 0x8004A564u: goto label_8004A564;
    case 0x8004A568u: goto label_8004A568;
    case 0x8004A56Cu: goto label_8004A56C;
    case 0x8004A570u: goto label_8004A570;
    case 0x8004A574u: goto label_8004A574;
    case 0x8004A578u: goto label_8004A578;
    case 0x8004A57Cu: goto label_8004A57C;
    case 0x8004A580u: goto label_8004A580;
    case 0x8004A584u: goto label_8004A584;
    case 0x8004A588u: goto label_8004A588;
    case 0x8004A58Cu: goto label_8004A58C;
    case 0x8004A590u: goto label_8004A590;
    case 0x8004A594u: goto label_8004A594;
    case 0x8004A598u: goto label_8004A598;
    case 0x8004A59Cu: goto label_8004A59C;
    case 0x8004A5A0u: goto label_8004A5A0;
    case 0x8004A5A4u: goto label_8004A5A4;
    case 0x8004A5A8u: goto label_8004A5A8;
    case 0x8004A5ACu: goto label_8004A5AC;
    case 0x8004A5B0u: goto label_8004A5B0;
    case 0x8004A5B4u: goto label_8004A5B4;
    case 0x8004A5B8u: goto label_8004A5B8;
    case 0x8004A5BCu: goto label_8004A5BC;
    case 0x8004A5C0u: goto label_8004A5C0;
    case 0x8004A5C4u: goto label_8004A5C4;
    case 0x8004A5C8u: goto label_8004A5C8;
    case 0x8004A5CCu: goto label_8004A5CC;
    case 0x8004A5D0u: goto label_8004A5D0;
    case 0x8004A5D4u: goto label_8004A5D4;
    case 0x8004A5D8u: goto label_8004A5D8;
    case 0x8004A5DCu: goto label_8004A5DC;
    case 0x8004A5E0u: goto label_8004A5E0;
    case 0x8004A5E4u: goto label_8004A5E4;
    case 0x8004A5E8u: goto label_8004A5E8;
    case 0x8004A5ECu: goto label_8004A5EC;
    case 0x8004A5F0u: goto label_8004A5F0;
    case 0x8004A5F4u: goto label_8004A5F4;
    case 0x8004A5F8u: goto label_8004A5F8;
    case 0x8004A5FCu: goto label_8004A5FC;
    case 0x8004A600u: goto label_8004A600;
    case 0x8004A604u: goto label_8004A604;
    case 0x8004A608u: goto label_8004A608;
    case 0x8004A60Cu: goto label_8004A60C;
    case 0x8004A610u: goto label_8004A610;
    case 0x8004A614u: goto label_8004A614;
    case 0x8004A618u: goto label_8004A618;
    case 0x8004A61Cu: goto label_8004A61C;
    case 0x8004A620u: goto label_8004A620;
    case 0x8004A624u: goto label_8004A624;
    case 0x8004A628u: goto label_8004A628;
    case 0x8004A62Cu: goto label_8004A62C;
    case 0x8004A630u: goto label_8004A630;
    case 0x8004A634u: goto label_8004A634;
    case 0x8004A638u: goto label_8004A638;
    case 0x8004A63Cu: goto label_8004A63C;
    case 0x8004A640u: goto label_8004A640;
    case 0x8004A644u: goto label_8004A644;
    case 0x8004A648u: goto label_8004A648;
    case 0x8004A64Cu: goto label_8004A64C;
    case 0x8004A650u: goto label_8004A650;
    case 0x8004A654u: goto label_8004A654;
    case 0x8004A658u: goto label_8004A658;
    case 0x8004A65Cu: goto label_8004A65C;
    case 0x8004A660u: goto label_8004A660;
    case 0x8004A664u: goto label_8004A664;
    case 0x8004A668u: goto label_8004A668;
    case 0x8004A66Cu: goto label_8004A66C;
    case 0x8004A670u: goto label_8004A670;
    case 0x8004A674u: goto label_8004A674;
    case 0x8004A678u: goto label_8004A678;
    case 0x8004A67Cu: goto label_8004A67C;
    case 0x8004A680u: goto label_8004A680;
    case 0x8004A684u: goto label_8004A684;
    case 0x8004A688u: goto label_8004A688;
    case 0x8004A68Cu: goto label_8004A68C;
    case 0x8004A690u: goto label_8004A690;
    case 0x8004A694u: goto label_8004A694;
    case 0x8004A698u: goto label_8004A698;
    case 0x8004A69Cu: goto label_8004A69C;
    case 0x8004A6A0u: goto label_8004A6A0;
    case 0x8004A6A4u: goto label_8004A6A4;
    case 0x8004A6A8u: goto label_8004A6A8;
    case 0x8004A6ACu: goto label_8004A6AC;
    case 0x8004A6B0u: goto label_8004A6B0;
    case 0x8004A6B4u: goto label_8004A6B4;
    case 0x8004A6B8u: goto label_8004A6B8;
    case 0x8004A6BCu: goto label_8004A6BC;
    case 0x8004A6C0u: goto label_8004A6C0;
    case 0x8004A6C4u: goto label_8004A6C4;
    case 0x8004A6C8u: goto label_8004A6C8;
    case 0x8004A6CCu: goto label_8004A6CC;
    case 0x8004A6D0u: goto label_8004A6D0;
    case 0x8004A6D4u: goto label_8004A6D4;
    case 0x8004A6D8u: goto label_8004A6D8;
    case 0x8004A6DCu: goto label_8004A6DC;
    case 0x8004A6E0u: goto label_8004A6E0;
    case 0x8004A6E4u: goto label_8004A6E4;
    case 0x8004A6E8u: goto label_8004A6E8;
    case 0x8004A6ECu: goto label_8004A6EC;
    case 0x8004A6F0u: goto label_8004A6F0;
    case 0x8004A6F4u: goto label_8004A6F4;
    case 0x8004A6F8u: goto label_8004A6F8;
    case 0x8004A6FCu: goto label_8004A6FC;
    case 0x8004A700u: goto label_8004A700;
    case 0x8004A704u: goto label_8004A704;
    case 0x8004A708u: goto label_8004A708;
    case 0x8004A70Cu: goto label_8004A70C;
    case 0x8004A710u: goto label_8004A710;
    case 0x8004A714u: goto label_8004A714;
    case 0x8004A718u: goto label_8004A718;
    case 0x8004A71Cu: goto label_8004A71C;
    case 0x8004A720u: goto label_8004A720;
    case 0x8004A724u: goto label_8004A724;
    case 0x8004A728u: goto label_8004A728;
    case 0x8004A72Cu: goto label_8004A72C;
    case 0x8004A730u: goto label_8004A730;
    case 0x8004A734u: goto label_8004A734;
    case 0x8004A738u: goto label_8004A738;
    case 0x8004A73Cu: goto label_8004A73C;
    case 0x8004A740u: goto label_8004A740;
    case 0x8004A744u: goto label_8004A744;
    case 0x8004A748u: goto label_8004A748;
    case 0x8004A74Cu: goto label_8004A74C;
    case 0x8004A750u: goto label_8004A750;
    case 0x8004A754u: goto label_8004A754;
    case 0x8004A758u: goto label_8004A758;
    case 0x8004A75Cu: goto label_8004A75C;
    case 0x8004A760u: goto label_8004A760;
    case 0x8004A764u: goto label_8004A764;
    case 0x8004A768u: goto label_8004A768;
    case 0x8004A76Cu: goto label_8004A76C;
    case 0x8004A770u: goto label_8004A770;
    case 0x8004A774u: goto label_8004A774;
    case 0x8004A778u: goto label_8004A778;
    case 0x8004A77Cu: goto label_8004A77C;
    case 0x8004A780u: goto label_8004A780;
    case 0x8004A784u: goto label_8004A784;
    case 0x8004A788u: goto label_8004A788;
    case 0x8004A78Cu: goto label_8004A78C;
    case 0x8004A790u: goto label_8004A790;
    case 0x8004A794u: goto label_8004A794;
    case 0x8004A798u: goto label_8004A798;
    case 0x8004A79Cu: goto label_8004A79C;
    case 0x8004A7A0u: goto label_8004A7A0;
    case 0x8004A7A4u: goto label_8004A7A4;
    case 0x8004A7A8u: goto label_8004A7A8;
    case 0x8004A7ACu: goto label_8004A7AC;
    case 0x8004A7B0u: goto label_8004A7B0;
    case 0x8004A7B4u: goto label_8004A7B4;
    case 0x8004A7B8u: goto label_8004A7B8;
    case 0x8004A7BCu: goto label_8004A7BC;
    case 0x8004A7C0u: goto label_8004A7C0;
    case 0x8004A7C4u: goto label_8004A7C4;
    case 0x8004A7C8u: goto label_8004A7C8;
    case 0x8004A7CCu: goto label_8004A7CC;
    case 0x8004A7D0u: goto label_8004A7D0;
    case 0x8004A7D4u: goto label_8004A7D4;
    case 0x8004A7D8u: goto label_8004A7D8;
    case 0x8004A7DCu: goto label_8004A7DC;
    case 0x8004A7E0u: goto label_8004A7E0;
    case 0x8004A7E4u: goto label_8004A7E4;
    case 0x8004A7E8u: goto label_8004A7E8;
    case 0x8004A7ECu: goto label_8004A7EC;
    case 0x8004A7F0u: goto label_8004A7F0;
    case 0x8004A7F4u: goto label_8004A7F4;
    case 0x8004A7F8u: goto label_8004A7F8;
    case 0x8004A7FCu: goto label_8004A7FC;
    case 0x8004A800u: goto label_8004A800;
    case 0x8004A804u: goto label_8004A804;
    case 0x8004A808u: goto label_8004A808;
    case 0x8004A80Cu: goto label_8004A80C;
    case 0x8004A810u: goto label_8004A810;
    case 0x8004A814u: goto label_8004A814;
    case 0x8004A818u: goto label_8004A818;
    case 0x8004A81Cu: goto label_8004A81C;
    case 0x8004A820u: goto label_8004A820;
    case 0x8004A824u: goto label_8004A824;
    case 0x8004A828u: goto label_8004A828;
    case 0x8004A82Cu: goto label_8004A82C;
    case 0x8004A830u: goto label_8004A830;
    case 0x8004A834u: goto label_8004A834;
    case 0x8004A838u: goto label_8004A838;
    case 0x8004A83Cu: goto label_8004A83C;
    case 0x8004A840u: goto label_8004A840;
    case 0x8004A844u: goto label_8004A844;
    case 0x8004A848u: goto label_8004A848;
    case 0x8004A84Cu: goto label_8004A84C;
    case 0x8004A850u: goto label_8004A850;
    case 0x8004A854u: goto label_8004A854;
    case 0x8004A858u: goto label_8004A858;
    case 0x8004A85Cu: goto label_8004A85C;
    case 0x8004A860u: goto label_8004A860;
    case 0x8004A864u: goto label_8004A864;
    case 0x8004A868u: goto label_8004A868;
    case 0x8004A86Cu: goto label_8004A86C;
    case 0x8004A870u: goto label_8004A870;
    case 0x8004A874u: goto label_8004A874;
    case 0x8004A878u: goto label_8004A878;
    case 0x8004A87Cu: goto label_8004A87C;
    case 0x8004A880u: goto label_8004A880;
    case 0x8004A884u: goto label_8004A884;
    case 0x8004A888u: goto label_8004A888;
    case 0x8004A88Cu: goto label_8004A88C;
    case 0x8004A890u: goto label_8004A890;
    case 0x8004A894u: goto label_8004A894;
    case 0x8004A898u: goto label_8004A898;
    case 0x8004A89Cu: goto label_8004A89C;
    case 0x8004A8A0u: goto label_8004A8A0;
    case 0x8004A8A4u: goto label_8004A8A4;
    case 0x8004A8A8u: goto label_8004A8A8;
    case 0x8004A8ACu: goto label_8004A8AC;
    case 0x8004A8B0u: goto label_8004A8B0;
    case 0x8004A8B4u: goto label_8004A8B4;
    case 0x8004A8B8u: goto label_8004A8B8;
    case 0x8004A8BCu: goto label_8004A8BC;
    case 0x8004A8C0u: goto label_8004A8C0;
    case 0x8004A8C4u: goto label_8004A8C4;
    case 0x8004A8C8u: goto label_8004A8C8;
    case 0x8004A8CCu: goto label_8004A8CC;
    case 0x8004A8D0u: goto label_8004A8D0;
    case 0x8004A8D4u: goto label_8004A8D4;
    case 0x8004A8D8u: goto label_8004A8D8;
    case 0x8004A8DCu: goto label_8004A8DC;
    case 0x8004A8E0u: goto label_8004A8E0;
    case 0x8004A8E4u: goto label_8004A8E4;
    case 0x8004A8E8u: goto label_8004A8E8;
    case 0x8004A8ECu: goto label_8004A8EC;
    case 0x8004A8F0u: goto label_8004A8F0;
    case 0x8004A8F4u: goto label_8004A8F4;
    case 0x8004A8F8u: goto label_8004A8F8;
    case 0x8004A8FCu: goto label_8004A8FC;
    case 0x8004A900u: goto label_8004A900;
    case 0x8004A904u: goto label_8004A904;
    case 0x8004A908u: goto label_8004A908;
    case 0x8004A90Cu: goto label_8004A90C;
    case 0x8004A910u: goto label_8004A910;
    case 0x8004A914u: goto label_8004A914;
    case 0x8004A918u: goto label_8004A918;
    case 0x8004A91Cu: goto label_8004A91C;
    case 0x8004A920u: goto label_8004A920;
    case 0x8004A924u: goto label_8004A924;
    case 0x8004A928u: goto label_8004A928;
    case 0x8004A92Cu: goto label_8004A92C;
    case 0x8004A930u: goto label_8004A930;
    case 0x8004A934u: goto label_8004A934;
    case 0x8004A938u: goto label_8004A938;
    case 0x8004A93Cu: goto label_8004A93C;
    case 0x8004A940u: goto label_8004A940;
    case 0x8004A944u: goto label_8004A944;
    case 0x8004A948u: goto label_8004A948;
    case 0x8004A94Cu: goto label_8004A94C;
    case 0x8004A950u: goto label_8004A950;
    case 0x8004A954u: goto label_8004A954;
    case 0x8004A958u: goto label_8004A958;
    case 0x8004A95Cu: goto label_8004A95C;
    case 0x8004A960u: goto label_8004A960;
    case 0x8004A964u: goto label_8004A964;
    case 0x8004A968u: goto label_8004A968;
    case 0x8004A96Cu: goto label_8004A96C;
    case 0x8004A970u: goto label_8004A970;
    case 0x8004A974u: goto label_8004A974;
    case 0x8004A978u: goto label_8004A978;
    case 0x8004A97Cu: goto label_8004A97C;
    case 0x8004A980u: goto label_8004A980;
    case 0x8004A984u: goto label_8004A984;
    case 0x8004A988u: goto label_8004A988;
    case 0x8004A98Cu: goto label_8004A98C;
    case 0x8004A990u: goto label_8004A990;
    case 0x8004A994u: goto label_8004A994;
    case 0x8004A998u: goto label_8004A998;
    case 0x8004A99Cu: goto label_8004A99C;
    case 0x8004A9A0u: goto label_8004A9A0;
    case 0x8004A9A4u: goto label_8004A9A4;
    case 0x8004A9A8u: goto label_8004A9A8;
    case 0x8004A9ACu: goto label_8004A9AC;
    case 0x8004A9B0u: goto label_8004A9B0;
    case 0x8004A9B4u: goto label_8004A9B4;
    case 0x8004A9B8u: goto label_8004A9B8;
    case 0x8004A9BCu: goto label_8004A9BC;
    case 0x8004A9C0u: goto label_8004A9C0;
    case 0x8004A9C4u: goto label_8004A9C4;
    case 0x8004A9C8u: goto label_8004A9C8;
    case 0x8004A9CCu: goto label_8004A9CC;
    case 0x8004A9D0u: goto label_8004A9D0;
    case 0x8004A9D4u: goto label_8004A9D4;
    case 0x8004A9D8u: goto label_8004A9D8;
    case 0x8004A9DCu: goto label_8004A9DC;
    case 0x8004A9E0u: goto label_8004A9E0;
    case 0x8004A9E4u: goto label_8004A9E4;
    case 0x8004A9E8u: goto label_8004A9E8;
    case 0x8004A9ECu: goto label_8004A9EC;
    case 0x8004A9F0u: goto label_8004A9F0;
    case 0x8004A9F4u: goto label_8004A9F4;
    case 0x8004A9F8u: goto label_8004A9F8;
    case 0x8004A9FCu: goto label_8004A9FC;
    case 0x8004AA00u: goto label_8004AA00;
    case 0x8004AA04u: goto label_8004AA04;
    case 0x8004AA08u: goto label_8004AA08;
    case 0x8004AA0Cu: goto label_8004AA0C;
    case 0x8004AA10u: goto label_8004AA10;
    case 0x8004AA14u: goto label_8004AA14;
    case 0x8004AA18u: goto label_8004AA18;
    case 0x8004AA1Cu: goto label_8004AA1C;
    case 0x8004AA20u: goto label_8004AA20;
    case 0x8004AA24u: goto label_8004AA24;
    case 0x8004AA28u: goto label_8004AA28;
    case 0x8004AA2Cu: goto label_8004AA2C;
    case 0x8004AA30u: goto label_8004AA30;
    case 0x8004AA34u: goto label_8004AA34;
    case 0x8004AA38u: goto label_8004AA38;
    case 0x8004AA3Cu: goto label_8004AA3C;
    case 0x8004AA40u: goto label_8004AA40;
    case 0x8004AA44u: goto label_8004AA44;
    case 0x8004AA48u: goto label_8004AA48;
    case 0x8004AA4Cu: goto label_8004AA4C;
    case 0x8004AA50u: goto label_8004AA50;
    case 0x8004AA54u: goto label_8004AA54;
    case 0x8004AA58u: goto label_8004AA58;
    case 0x8004AA5Cu: goto label_8004AA5C;
    case 0x8004AA60u: goto label_8004AA60;
    case 0x8004AA64u: goto label_8004AA64;
    case 0x8004AA68u: goto label_8004AA68;
    case 0x8004AA6Cu: goto label_8004AA6C;
    case 0x8004AA70u: goto label_8004AA70;
    case 0x8004AA74u: goto label_8004AA74;
    case 0x8004AA78u: goto label_8004AA78;
    case 0x8004AA7Cu: goto label_8004AA7C;
    case 0x8004AA80u: goto label_8004AA80;
    case 0x8004AA84u: goto label_8004AA84;
    case 0x8004AA88u: goto label_8004AA88;
    case 0x8004AA8Cu: goto label_8004AA8C;
    case 0x8004AA90u: goto label_8004AA90;
    case 0x8004AA94u: goto label_8004AA94;
    case 0x8004AA98u: goto label_8004AA98;
    case 0x8004AA9Cu: goto label_8004AA9C;
    case 0x8004AAA0u: goto label_8004AAA0;
    case 0x8004AAA4u: goto label_8004AAA4;
    case 0x8004AAA8u: goto label_8004AAA8;
    case 0x8004AAACu: goto label_8004AAAC;
    case 0x8004AAB0u: goto label_8004AAB0;
    case 0x8004AAB4u: goto label_8004AAB4;
    case 0x8004AAB8u: goto label_8004AAB8;
    case 0x8004AABCu: goto label_8004AABC;
    case 0x8004AAC0u: goto label_8004AAC0;
    case 0x8004AAC4u: goto label_8004AAC4;
    case 0x8004AAC8u: goto label_8004AAC8;
    case 0x8004AACCu: goto label_8004AACC;
    case 0x8004AAD0u: goto label_8004AAD0;
    case 0x8004AAD4u: goto label_8004AAD4;
    case 0x8004AAD8u: goto label_8004AAD8;
    case 0x8004AADCu: goto label_8004AADC;
    case 0x8004AAE0u: goto label_8004AAE0;
    case 0x8004AAE4u: goto label_8004AAE4;
    case 0x8004AAE8u: goto label_8004AAE8;
    case 0x8004AAECu: goto label_8004AAEC;
    case 0x8004AAF0u: goto label_8004AAF0;
    case 0x8004AAF4u: goto label_8004AAF4;
    case 0x8004AAF8u: goto label_8004AAF8;
    case 0x8004AAFCu: goto label_8004AAFC;
    case 0x8004AB00u: goto label_8004AB00;
    case 0x8004AB04u: goto label_8004AB04;
    case 0x8004AB08u: goto label_8004AB08;
    case 0x8004AB0Cu: goto label_8004AB0C;
    case 0x8004AB10u: goto label_8004AB10;
    case 0x8004AB14u: goto label_8004AB14;
    case 0x8004AB18u: goto label_8004AB18;
    case 0x8004AB1Cu: goto label_8004AB1C;
    case 0x8004AB20u: goto label_8004AB20;
    case 0x8004AB24u: goto label_8004AB24;
    case 0x8004AB28u: goto label_8004AB28;
    case 0x8004AB2Cu: goto label_8004AB2C;
    case 0x8004AB30u: goto label_8004AB30;
    case 0x8004AB34u: goto label_8004AB34;
    case 0x8004AB38u: goto label_8004AB38;
    case 0x8004AB3Cu: goto label_8004AB3C;
    case 0x8004AB40u: goto label_8004AB40;
    case 0x8004AB44u: goto label_8004AB44;
    case 0x8004AB48u: goto label_8004AB48;
    case 0x8004AB4Cu: goto label_8004AB4C;
    case 0x8004AB50u: goto label_8004AB50;
    case 0x8004AB54u: goto label_8004AB54;
    case 0x8004AB58u: goto label_8004AB58;
    case 0x8004AB5Cu: goto label_8004AB5C;
    case 0x8004AB60u: goto label_8004AB60;
    case 0x8004AB64u: goto label_8004AB64;
    case 0x8004AB68u: goto label_8004AB68;
    case 0x8004AB6Cu: goto label_8004AB6C;
    case 0x8004AB70u: goto label_8004AB70;
    case 0x8004AB74u: goto label_8004AB74;
    case 0x8004AB78u: goto label_8004AB78;
    case 0x8004AB7Cu: goto label_8004AB7C;
    case 0x8004AB80u: goto label_8004AB80;
    case 0x8004AB84u: goto label_8004AB84;
    case 0x8004AB88u: goto label_8004AB88;
    case 0x8004AB8Cu: goto label_8004AB8C;
    case 0x8004AB90u: goto label_8004AB90;
    case 0x8004AB94u: goto label_8004AB94;
    case 0x8004AB98u: goto label_8004AB98;
    case 0x8004AB9Cu: goto label_8004AB9C;
    case 0x8004ABA0u: goto label_8004ABA0;
    case 0x8004ABA4u: goto label_8004ABA4;
    case 0x8004ABA8u: goto label_8004ABA8;
    case 0x8004ABACu: goto label_8004ABAC;
    case 0x8004ABB0u: goto label_8004ABB0;
    case 0x8004ABB4u: goto label_8004ABB4;
    case 0x8004ABB8u: goto label_8004ABB8;
    case 0x8004ABBCu: goto label_8004ABBC;
    case 0x8004ABC0u: goto label_8004ABC0;
    case 0x8004ABC4u: goto label_8004ABC4;
    case 0x8004ABC8u: goto label_8004ABC8;
    case 0x8004ABCCu: goto label_8004ABCC;
    case 0x8004ABD0u: goto label_8004ABD0;
    case 0x8004ABD4u: goto label_8004ABD4;
    case 0x8004ABD8u: goto label_8004ABD8;
    case 0x8004ABDCu: goto label_8004ABDC;
    case 0x8004ABE0u: goto label_8004ABE0;
    case 0x8004ABE4u: goto label_8004ABE4;
    case 0x8004ABE8u: goto label_8004ABE8;
    case 0x8004ABECu: goto label_8004ABEC;
    case 0x8004ABF0u: goto label_8004ABF0;
    case 0x8004ABF4u: goto label_8004ABF4;
    case 0x8004ABF8u: goto label_8004ABF8;
    case 0x8004ABFCu: goto label_8004ABFC;
    case 0x8004AC00u: goto label_8004AC00;
    case 0x8004AC04u: goto label_8004AC04;
    case 0x8004AC08u: goto label_8004AC08;
    case 0x8004AC0Cu: goto label_8004AC0C;
    case 0x8004AC10u: goto label_8004AC10;
    case 0x8004AC14u: goto label_8004AC14;
    case 0x8004AC18u: goto label_8004AC18;
    case 0x8004AC1Cu: goto label_8004AC1C;
    case 0x8004AC20u: goto label_8004AC20;
    case 0x8004AC24u: goto label_8004AC24;
    case 0x8004AC28u: goto label_8004AC28;
    case 0x8004AC2Cu: goto label_8004AC2C;
    case 0x8004AC30u: goto label_8004AC30;
    case 0x8004AC34u: goto label_8004AC34;
    case 0x8004AC38u: goto label_8004AC38;
    case 0x8004AC3Cu: goto label_8004AC3C;
    case 0x8004AC40u: goto label_8004AC40;
    case 0x8004AC44u: goto label_8004AC44;
    case 0x8004AC48u: goto label_8004AC48;
    case 0x8004AC4Cu: goto label_8004AC4C;
    case 0x8004AC50u: goto label_8004AC50;
    case 0x8004AC54u: goto label_8004AC54;
    case 0x8004AC58u: goto label_8004AC58;
    case 0x8004AC5Cu: goto label_8004AC5C;
    case 0x8004AC60u: goto label_8004AC60;
    case 0x8004AC64u: goto label_8004AC64;
    case 0x8004AC68u: goto label_8004AC68;
    case 0x8004AC6Cu: goto label_8004AC6C;
    case 0x8004AC70u: goto label_8004AC70;
    case 0x8004AC74u: goto label_8004AC74;
    case 0x8004AC78u: goto label_8004AC78;
    case 0x8004AC7Cu: goto label_8004AC7C;
    case 0x8004AC80u: goto label_8004AC80;
    case 0x8004AC84u: goto label_8004AC84;
    case 0x8004AC88u: goto label_8004AC88;
    case 0x8004AC8Cu: goto label_8004AC8C;
    case 0x8004AC90u: goto label_8004AC90;
    case 0x8004AC94u: goto label_8004AC94;
    case 0x8004AC98u: goto label_8004AC98;
    case 0x8004AC9Cu: goto label_8004AC9C;
    case 0x8004ACA0u: goto label_8004ACA0;
    case 0x8004ACA4u: goto label_8004ACA4;
    case 0x8004ACA8u: goto label_8004ACA8;
    case 0x8004ACACu: goto label_8004ACAC;
    case 0x8004ACB0u: goto label_8004ACB0;
    case 0x8004ACB4u: goto label_8004ACB4;
    case 0x8004ACB8u: goto label_8004ACB8;
    case 0x8004ACBCu: goto label_8004ACBC;
    case 0x8004ACC0u: goto label_8004ACC0;
    case 0x8004ACC4u: goto label_8004ACC4;
    case 0x8004ACC8u: goto label_8004ACC8;
    case 0x8004ACCCu: goto label_8004ACCC;
    case 0x8004ACD0u: goto label_8004ACD0;
    case 0x8004ACD4u: goto label_8004ACD4;
    case 0x8004ACD8u: goto label_8004ACD8;
    case 0x8004ACDCu: goto label_8004ACDC;
    case 0x8004ACE0u: goto label_8004ACE0;
    case 0x8004ACE4u: goto label_8004ACE4;
    case 0x8004ACE8u: goto label_8004ACE8;
    case 0x8004ACECu: goto label_8004ACEC;
    case 0x8004ACF0u: goto label_8004ACF0;
    case 0x8004ACF4u: goto label_8004ACF4;
    case 0x8004ACF8u: goto label_8004ACF8;
    case 0x8004ACFCu: goto label_8004ACFC;
    case 0x8004AD00u: goto label_8004AD00;
    case 0x8004AD04u: goto label_8004AD04;
    case 0x8004AD08u: goto label_8004AD08;
    case 0x8004AD0Cu: goto label_8004AD0C;
    case 0x8004AD10u: goto label_8004AD10;
    case 0x8004AD14u: goto label_8004AD14;
    case 0x8004AD18u: goto label_8004AD18;
    case 0x8004AD1Cu: goto label_8004AD1C;
    case 0x8004AD20u: goto label_8004AD20;
    case 0x8004AD24u: goto label_8004AD24;
    case 0x8004AD28u: goto label_8004AD28;
    case 0x8004AD2Cu: goto label_8004AD2C;
    case 0x8004AD30u: goto label_8004AD30;
    case 0x8004AD34u: goto label_8004AD34;
    case 0x8004AD38u: goto label_8004AD38;
    case 0x8004AD3Cu: goto label_8004AD3C;
    case 0x8004AD40u: goto label_8004AD40;
    case 0x8004AD44u: goto label_8004AD44;
    case 0x8004AD48u: goto label_8004AD48;
    case 0x8004AD4Cu: goto label_8004AD4C;
    case 0x8004AD50u: goto label_8004AD50;
    case 0x8004AD54u: goto label_8004AD54;
    case 0x8004AD58u: goto label_8004AD58;
    case 0x8004AD5Cu: goto label_8004AD5C;
    case 0x8004AD60u: goto label_8004AD60;
    case 0x8004AD64u: goto label_8004AD64;
    case 0x8004AD68u: goto label_8004AD68;
    case 0x8004AD6Cu: goto label_8004AD6C;
    case 0x8004AD70u: goto label_8004AD70;
    case 0x8004AD74u: goto label_8004AD74;
    case 0x8004AD78u: goto label_8004AD78;
    case 0x8004AD7Cu: goto label_8004AD7C;
    case 0x8004AD80u: goto label_8004AD80;
    case 0x8004AD84u: goto label_8004AD84;
    case 0x8004AD88u: goto label_8004AD88;
    case 0x8004AD8Cu: goto label_8004AD8C;
    case 0x8004AD90u: goto label_8004AD90;
    case 0x8004AD94u: goto label_8004AD94;
    case 0x8004AD98u: goto label_8004AD98;
    case 0x8004AD9Cu: goto label_8004AD9C;
    case 0x8004ADA0u: goto label_8004ADA0;
    case 0x8004ADA4u: goto label_8004ADA4;
    case 0x8004ADA8u: goto label_8004ADA8;
    case 0x8004ADACu: goto label_8004ADAC;
    case 0x8004ADB0u: goto label_8004ADB0;
    case 0x8004ADB4u: goto label_8004ADB4;
    case 0x8004ADB8u: goto label_8004ADB8;
    case 0x8004ADBCu: goto label_8004ADBC;
    case 0x8004ADC0u: goto label_8004ADC0;
    case 0x8004ADC4u: goto label_8004ADC4;
    case 0x8004ADC8u: goto label_8004ADC8;
    case 0x8004ADCCu: goto label_8004ADCC;
    case 0x8004ADD0u: goto label_8004ADD0;
    case 0x8004ADD4u: goto label_8004ADD4;
    case 0x8004ADD8u: goto label_8004ADD8;
    case 0x8004ADDCu: goto label_8004ADDC;
    case 0x8004ADE0u: goto label_8004ADE0;
    case 0x8004ADE4u: goto label_8004ADE4;
    case 0x8004ADE8u: goto label_8004ADE8;
    case 0x8004ADECu: goto label_8004ADEC;
    case 0x8004ADF0u: goto label_8004ADF0;
    case 0x8004ADF4u: goto label_8004ADF4;
    case 0x8004ADF8u: goto label_8004ADF8;
    case 0x8004ADFCu: goto label_8004ADFC;
    case 0x8004AE00u: goto label_8004AE00;
    case 0x8004AE04u: goto label_8004AE04;
    case 0x8004AE08u: goto label_8004AE08;
    case 0x8004AE0Cu: goto label_8004AE0C;
    case 0x8004AE10u: goto label_8004AE10;
    case 0x8004AE14u: goto label_8004AE14;
    case 0x8004AE18u: goto label_8004AE18;
    case 0x8004AE1Cu: goto label_8004AE1C;
    case 0x8004AE20u: goto label_8004AE20;
    case 0x8004AE24u: goto label_8004AE24;
    case 0x8004AE28u: goto label_8004AE28;
    case 0x8004AE2Cu: goto label_8004AE2C;
    case 0x8004AE30u: goto label_8004AE30;
    case 0x8004AE34u: goto label_8004AE34;
    case 0x8004AE38u: goto label_8004AE38;
    case 0x8004AE3Cu: goto label_8004AE3C;
    case 0x8004AE40u: goto label_8004AE40;
    case 0x8004AE44u: goto label_8004AE44;
    case 0x8004AE48u: goto label_8004AE48;
    case 0x8004AE4Cu: goto label_8004AE4C;
    case 0x8004AE50u: goto label_8004AE50;
    case 0x8004AE54u: goto label_8004AE54;
    case 0x8004AE58u: goto label_8004AE58;
    case 0x8004AE5Cu: goto label_8004AE5C;
    case 0x8004AE60u: goto label_8004AE60;
    case 0x8004AE64u: goto label_8004AE64;
    case 0x8004AE68u: goto label_8004AE68;
    case 0x8004AE6Cu: goto label_8004AE6C;
    case 0x8004AE70u: goto label_8004AE70;
    case 0x8004AE74u: goto label_8004AE74;
    case 0x8004AE78u: goto label_8004AE78;
    case 0x8004AE7Cu: goto label_8004AE7C;
    case 0x8004AE80u: goto label_8004AE80;
    case 0x8004AE84u: goto label_8004AE84;
    case 0x8004AE88u: goto label_8004AE88;
    case 0x8004AE8Cu: goto label_8004AE8C;
    case 0x8004AE90u: goto label_8004AE90;
    case 0x8004AE94u: goto label_8004AE94;
    case 0x8004AE98u: goto label_8004AE98;
    case 0x8004AE9Cu: goto label_8004AE9C;
    case 0x8004AEA0u: goto label_8004AEA0;
    case 0x8004AEA4u: goto label_8004AEA4;
    case 0x8004AEA8u: goto label_8004AEA8;
    case 0x8004AEACu: goto label_8004AEAC;
    case 0x8004AEB0u: goto label_8004AEB0;
    case 0x8004AEB4u: goto label_8004AEB4;
    case 0x8004AEB8u: goto label_8004AEB8;
    case 0x8004AEBCu: goto label_8004AEBC;
    case 0x8004AEC0u: goto label_8004AEC0;
    case 0x8004AEC4u: goto label_8004AEC4;
    case 0x8004AEC8u: goto label_8004AEC8;
    case 0x8004AECCu: goto label_8004AECC;
    case 0x8004AED0u: goto label_8004AED0;
    case 0x8004AED4u: goto label_8004AED4;
    case 0x8004AED8u: goto label_8004AED8;
    case 0x8004AEDCu: goto label_8004AEDC;
    case 0x8004AEE0u: goto label_8004AEE0;
    case 0x8004AEE4u: goto label_8004AEE4;
    case 0x8004AEE8u: goto label_8004AEE8;
    case 0x8004AEECu: goto label_8004AEEC;
    case 0x8004AEF0u: goto label_8004AEF0;
    case 0x8004AEF4u: goto label_8004AEF4;
    case 0x8004AEF8u: goto label_8004AEF8;
    case 0x8004AEFCu: goto label_8004AEFC;
    case 0x8004AF00u: goto label_8004AF00;
    case 0x8004AF04u: goto label_8004AF04;
    case 0x8004AF08u: goto label_8004AF08;
    case 0x8004AF0Cu: goto label_8004AF0C;
    case 0x8004AF10u: goto label_8004AF10;
    case 0x8004AF14u: goto label_8004AF14;
    case 0x8004AF18u: goto label_8004AF18;
    case 0x8004AF1Cu: goto label_8004AF1C;
    case 0x8004AF20u: goto label_8004AF20;
    case 0x8004AF24u: goto label_8004AF24;
    case 0x8004AF28u: goto label_8004AF28;
    case 0x8004AF2Cu: goto label_8004AF2C;
    case 0x8004AF30u: goto label_8004AF30;
    case 0x8004AF34u: goto label_8004AF34;
    case 0x8004AF38u: goto label_8004AF38;
    case 0x8004AF3Cu: goto label_8004AF3C;
    case 0x8004AF40u: goto label_8004AF40;
    case 0x8004AF44u: goto label_8004AF44;
    case 0x8004AF48u: goto label_8004AF48;
    case 0x8004AF4Cu: goto label_8004AF4C;
    case 0x8004AF50u: goto label_8004AF50;
    case 0x8004AF54u: goto label_8004AF54;
    case 0x8004AF58u: goto label_8004AF58;
    case 0x8004AF5Cu: goto label_8004AF5C;
    case 0x8004AF60u: goto label_8004AF60;
    case 0x8004AF64u: goto label_8004AF64;
    case 0x8004AF68u: goto label_8004AF68;
    case 0x8004AF6Cu: goto label_8004AF6C;
    case 0x8004AF70u: goto label_8004AF70;
    case 0x8004AF74u: goto label_8004AF74;
    case 0x8004AF78u: goto label_8004AF78;
    case 0x8004AF7Cu: goto label_8004AF7C;
    case 0x8004AF80u: goto label_8004AF80;
    case 0x8004AF84u: goto label_8004AF84;
    case 0x8004AF88u: goto label_8004AF88;
    case 0x8004AF8Cu: goto label_8004AF8C;
    case 0x8004AF90u: goto label_8004AF90;
    case 0x8004AF94u: goto label_8004AF94;
    case 0x8004AF98u: goto label_8004AF98;
    case 0x8004AF9Cu: goto label_8004AF9C;
    case 0x8004AFA0u: goto label_8004AFA0;
    case 0x8004AFA4u: goto label_8004AFA4;
    case 0x8004AFA8u: goto label_8004AFA8;
    case 0x8004AFACu: goto label_8004AFAC;
    case 0x8004AFB0u: goto label_8004AFB0;
    case 0x8004AFB4u: goto label_8004AFB4;
    case 0x8004AFB8u: goto label_8004AFB8;
    case 0x8004AFBCu: goto label_8004AFBC;
    case 0x8004AFC0u: goto label_8004AFC0;
    case 0x8004AFC4u: goto label_8004AFC4;
    case 0x8004AFC8u: goto label_8004AFC8;
    case 0x8004AFCCu: goto label_8004AFCC;
    case 0x8004AFD0u: goto label_8004AFD0;
    case 0x8004AFD4u: goto label_8004AFD4;
    case 0x8004AFD8u: goto label_8004AFD8;
    case 0x8004AFDCu: goto label_8004AFDC;
    case 0x8004AFE0u: goto label_8004AFE0;
    case 0x8004AFE4u: goto label_8004AFE4;
    case 0x8004AFE8u: goto label_8004AFE8;
    case 0x8004AFECu: goto label_8004AFEC;
    case 0x8004AFF0u: goto label_8004AFF0;
    case 0x8004AFF4u: goto label_8004AFF4;
    case 0x8004AFF8u: goto label_8004AFF8;
    case 0x8004AFFCu: goto label_8004AFFC;
    case 0x8004B000u: goto label_8004B000;
    case 0x8004B004u: goto label_8004B004;
    case 0x8004B008u: goto label_8004B008;
    case 0x8004B00Cu: goto label_8004B00C;
    case 0x8004B010u: goto label_8004B010;
    case 0x8004B014u: goto label_8004B014;
    case 0x8004B018u: goto label_8004B018;
    case 0x8004B01Cu: goto label_8004B01C;
    case 0x8004B020u: goto label_8004B020;
    case 0x8004B024u: goto label_8004B024;
    case 0x8004B028u: goto label_8004B028;
    case 0x8004B02Cu: goto label_8004B02C;
    case 0x8004B030u: goto label_8004B030;
    case 0x8004B034u: goto label_8004B034;
    case 0x8004B038u: goto label_8004B038;
    case 0x8004B03Cu: goto label_8004B03C;
    case 0x8004B040u: goto label_8004B040;
    case 0x8004B044u: goto label_8004B044;
    case 0x8004B048u: goto label_8004B048;
    case 0x8004B04Cu: goto label_8004B04C;
    case 0x8004B050u: goto label_8004B050;
    case 0x8004B054u: goto label_8004B054;
    case 0x8004B058u: goto label_8004B058;
    case 0x8004B05Cu: goto label_8004B05C;
    case 0x8004B060u: goto label_8004B060;
    case 0x8004B064u: goto label_8004B064;
    case 0x8004B068u: goto label_8004B068;
    case 0x8004B06Cu: goto label_8004B06C;
    case 0x8004B070u: goto label_8004B070;
    case 0x8004B074u: goto label_8004B074;
    case 0x8004B078u: goto label_8004B078;
    case 0x8004B07Cu: goto label_8004B07C;
    case 0x8004B080u: goto label_8004B080;
    case 0x8004B084u: goto label_8004B084;
    case 0x8004B088u: goto label_8004B088;
    case 0x8004B08Cu: goto label_8004B08C;
    case 0x8004B090u: goto label_8004B090;
    case 0x8004B094u: goto label_8004B094;
    case 0x8004B098u: goto label_8004B098;
    case 0x8004B09Cu: goto label_8004B09C;
    case 0x8004B0A0u: goto label_8004B0A0;
    case 0x8004B0A4u: goto label_8004B0A4;
    case 0x8004B0A8u: goto label_8004B0A8;
    case 0x8004B0ACu: goto label_8004B0AC;
    case 0x8004B0B0u: goto label_8004B0B0;
    case 0x8004B0B4u: goto label_8004B0B4;
    case 0x8004B0B8u: goto label_8004B0B8;
    case 0x8004B0BCu: goto label_8004B0BC;
    case 0x8004B0C0u: goto label_8004B0C0;
    case 0x8004B0C4u: goto label_8004B0C4;
    case 0x8004B0C8u: goto label_8004B0C8;
    case 0x8004B0CCu: goto label_8004B0CC;
    case 0x8004B0D0u: goto label_8004B0D0;
    case 0x8004B0D4u: goto label_8004B0D4;
    case 0x8004B0D8u: goto label_8004B0D8;
    case 0x8004B0DCu: goto label_8004B0DC;
    case 0x8004B0E0u: goto label_8004B0E0;
    case 0x8004B0E4u: goto label_8004B0E4;
    case 0x8004B0E8u: goto label_8004B0E8;
    case 0x8004B0ECu: goto label_8004B0EC;
    case 0x8004B0F0u: goto label_8004B0F0;
    case 0x8004B0F4u: goto label_8004B0F4;
    case 0x8004B0F8u: goto label_8004B0F8;
    case 0x8004B0FCu: goto label_8004B0FC;
    case 0x8004B100u: goto label_8004B100;
    case 0x8004B104u: goto label_8004B104;
    case 0x8004B108u: goto label_8004B108;
    case 0x8004B10Cu: goto label_8004B10C;
    case 0x8004B110u: goto label_8004B110;
    case 0x8004B114u: goto label_8004B114;
    case 0x8004B118u: goto label_8004B118;
    case 0x8004B11Cu: goto label_8004B11C;
    case 0x8004B120u: goto label_8004B120;
    case 0x8004B124u: goto label_8004B124;
    case 0x8004B128u: goto label_8004B128;
    case 0x8004B12Cu: goto label_8004B12C;
    case 0x8004B130u: goto label_8004B130;
    case 0x8004B134u: goto label_8004B134;
    case 0x8004B138u: goto label_8004B138;
    case 0x8004B13Cu: goto label_8004B13C;
    case 0x8004B140u: goto label_8004B140;
    case 0x8004B144u: goto label_8004B144;
    case 0x8004B148u: goto label_8004B148;
    case 0x8004B14Cu: goto label_8004B14C;
    case 0x8004B150u: goto label_8004B150;
    case 0x8004B154u: goto label_8004B154;
    case 0x8004B158u: goto label_8004B158;
    case 0x8004B15Cu: goto label_8004B15C;
    case 0x8004B160u: goto label_8004B160;
    case 0x8004B164u: goto label_8004B164;
    case 0x8004B168u: goto label_8004B168;
    case 0x8004B16Cu: goto label_8004B16C;
    case 0x8004B170u: goto label_8004B170;
    case 0x8004B174u: goto label_8004B174;
    case 0x8004B178u: goto label_8004B178;
    case 0x8004B17Cu: goto label_8004B17C;
    case 0x8004B180u: goto label_8004B180;
    case 0x8004B184u: goto label_8004B184;
    case 0x8004B188u: goto label_8004B188;
    case 0x8004B18Cu: goto label_8004B18C;
    case 0x8004B190u: goto label_8004B190;
    case 0x8004B194u: goto label_8004B194;
    case 0x8004B198u: goto label_8004B198;
    case 0x8004B19Cu: goto label_8004B19C;
    case 0x8004B1A0u: goto label_8004B1A0;
    case 0x8004B1A4u: goto label_8004B1A4;
    case 0x8004B1A8u: goto label_8004B1A8;
    case 0x8004B1ACu: goto label_8004B1AC;
    case 0x8004B1B0u: goto label_8004B1B0;
    case 0x8004B1B4u: goto label_8004B1B4;
    case 0x8004B1B8u: goto label_8004B1B8;
    case 0x8004B1BCu: goto label_8004B1BC;
    case 0x8004B1C0u: goto label_8004B1C0;
    case 0x8004B1C4u: goto label_8004B1C4;
    case 0x8004B1C8u: goto label_8004B1C8;
    case 0x8004B1CCu: goto label_8004B1CC;
    case 0x8004B1D0u: goto label_8004B1D0;
    case 0x8004B1D4u: goto label_8004B1D4;
    case 0x8004B1D8u: goto label_8004B1D8;
    case 0x8004B1DCu: goto label_8004B1DC;
    case 0x8004B1E0u: goto label_8004B1E0;
    case 0x8004B1E4u: goto label_8004B1E4;
    case 0x8004B1E8u: goto label_8004B1E8;
    case 0x8004B1ECu: goto label_8004B1EC;
    case 0x8004B1F0u: goto label_8004B1F0;
    case 0x8004B1F4u: goto label_8004B1F4;
    case 0x8004B1F8u: goto label_8004B1F8;
    case 0x8004B1FCu: goto label_8004B1FC;
    case 0x8004B200u: goto label_8004B200;
    case 0x8004B204u: goto label_8004B204;
    case 0x8004B208u: goto label_8004B208;
    case 0x8004B20Cu: goto label_8004B20C;
    case 0x8004B210u: goto label_8004B210;
    case 0x8004B214u: goto label_8004B214;
    case 0x8004B218u: goto label_8004B218;
    case 0x8004B21Cu: goto label_8004B21C;
    case 0x8004B220u: goto label_8004B220;
    case 0x8004B224u: goto label_8004B224;
    case 0x8004B228u: goto label_8004B228;
    case 0x8004B22Cu: goto label_8004B22C;
    case 0x8004B230u: goto label_8004B230;
    case 0x8004B234u: goto label_8004B234;
    case 0x8004B238u: goto label_8004B238;
    case 0x8004B23Cu: goto label_8004B23C;
    case 0x8004B240u: goto label_8004B240;
    case 0x8004B244u: goto label_8004B244;
    case 0x8004B248u: goto label_8004B248;
    case 0x8004B24Cu: goto label_8004B24C;
    case 0x8004B250u: goto label_8004B250;
    case 0x8004B254u: goto label_8004B254;
    case 0x8004B258u: goto label_8004B258;
    case 0x8004B25Cu: goto label_8004B25C;
    case 0x8004B260u: goto label_8004B260;
    case 0x8004B264u: goto label_8004B264;
    case 0x8004B268u: goto label_8004B268;
    case 0x8004B26Cu: goto label_8004B26C;
    case 0x8004B270u: goto label_8004B270;
    case 0x8004B274u: goto label_8004B274;
    case 0x8004B278u: goto label_8004B278;
    case 0x8004B27Cu: goto label_8004B27C;
    case 0x8004B280u: goto label_8004B280;
    case 0x8004B284u: goto label_8004B284;
    case 0x8004B288u: goto label_8004B288;
    case 0x8004B28Cu: goto label_8004B28C;
    case 0x8004B290u: goto label_8004B290;
    case 0x8004B294u: goto label_8004B294;
    case 0x8004B298u: goto label_8004B298;
    case 0x8004B29Cu: goto label_8004B29C;
    case 0x8004B2A0u: goto label_8004B2A0;
    case 0x8004B2A4u: goto label_8004B2A4;
    case 0x8004B2A8u: goto label_8004B2A8;
    case 0x8004B2ACu: goto label_8004B2AC;
    case 0x8004B2B0u: goto label_8004B2B0;
    case 0x8004B2B4u: goto label_8004B2B4;
    case 0x8004B2B8u: goto label_8004B2B8;
    case 0x8004B2BCu: goto label_8004B2BC;
    case 0x8004B2C0u: goto label_8004B2C0;
    case 0x8004B2C4u: goto label_8004B2C4;
    case 0x8004B2C8u: goto label_8004B2C8;
    case 0x8004B2CCu: goto label_8004B2CC;
    case 0x8004B2D0u: goto label_8004B2D0;
    case 0x8004B2D4u: goto label_8004B2D4;
    case 0x8004B2D8u: goto label_8004B2D8;
    case 0x8004B2DCu: goto label_8004B2DC;
    case 0x8004B2E0u: goto label_8004B2E0;
    case 0x8004B2E4u: goto label_8004B2E4;
    case 0x8004B2E8u: goto label_8004B2E8;
    case 0x8004B2ECu: goto label_8004B2EC;
    case 0x8004B2F0u: goto label_8004B2F0;
    case 0x8004B2F4u: goto label_8004B2F4;
    case 0x8004B2F8u: goto label_8004B2F8;
    case 0x8004B2FCu: goto label_8004B2FC;
    case 0x8004B300u: goto label_8004B300;
    case 0x8004B304u: goto label_8004B304;
    case 0x8004B308u: goto label_8004B308;
    case 0x8004B30Cu: goto label_8004B30C;
    case 0x8004B310u: goto label_8004B310;
    case 0x8004B314u: goto label_8004B314;
    case 0x8004B318u: goto label_8004B318;
    case 0x8004B31Cu: goto label_8004B31C;
    case 0x8004B320u: goto label_8004B320;
    case 0x8004B324u: goto label_8004B324;
    case 0x8004B328u: goto label_8004B328;
    case 0x8004B32Cu: goto label_8004B32C;
    case 0x8004B330u: goto label_8004B330;
    case 0x8004B334u: goto label_8004B334;
    case 0x8004B338u: goto label_8004B338;
    case 0x8004B33Cu: goto label_8004B33C;
    case 0x8004B340u: goto label_8004B340;
    case 0x8004B344u: goto label_8004B344;
    case 0x8004B348u: goto label_8004B348;
    case 0x8004B34Cu: goto label_8004B34C;
    case 0x8004B350u: goto label_8004B350;
    case 0x8004B354u: goto label_8004B354;
    case 0x8004B358u: goto label_8004B358;
    case 0x8004B35Cu: goto label_8004B35C;
    case 0x8004B360u: goto label_8004B360;
    case 0x8004B364u: goto label_8004B364;
    case 0x8004B368u: goto label_8004B368;
    case 0x8004B36Cu: goto label_8004B36C;
    case 0x8004B370u: goto label_8004B370;
    case 0x8004B374u: goto label_8004B374;
    case 0x8004B378u: goto label_8004B378;
    case 0x8004B37Cu: goto label_8004B37C;
    case 0x8004B380u: goto label_8004B380;
    case 0x8004B384u: goto label_8004B384;
    case 0x8004B388u: goto label_8004B388;
    case 0x8004B38Cu: goto label_8004B38C;
    case 0x8004B390u: goto label_8004B390;
    case 0x8004B394u: goto label_8004B394;
    case 0x8004B398u: goto label_8004B398;
    case 0x8004B39Cu: goto label_8004B39C;
    case 0x8004B3A0u: goto label_8004B3A0;
    case 0x8004B3A4u: goto label_8004B3A4;
    case 0x8004B3A8u: goto label_8004B3A8;
    case 0x8004B3ACu: goto label_8004B3AC;
    case 0x8004B3B0u: goto label_8004B3B0;
    case 0x8004B3B4u: goto label_8004B3B4;
    case 0x8004B3B8u: goto label_8004B3B8;
    case 0x8004B3BCu: goto label_8004B3BC;
    case 0x8004B3C0u: goto label_8004B3C0;
    case 0x8004B3C4u: goto label_8004B3C4;
    case 0x8004B3C8u: goto label_8004B3C8;
    case 0x8004B3CCu: goto label_8004B3CC;
    case 0x8004B3D0u: goto label_8004B3D0;
    case 0x8004B3D4u: goto label_8004B3D4;
    case 0x8004B3D8u: goto label_8004B3D8;
    case 0x8004B3DCu: goto label_8004B3DC;
    case 0x8004B3E0u: goto label_8004B3E0;
    case 0x8004B3E4u: goto label_8004B3E4;
    case 0x8004B3E8u: goto label_8004B3E8;
    case 0x8004B3ECu: goto label_8004B3EC;
    case 0x8004B3F0u: goto label_8004B3F0;
    case 0x8004B3F4u: goto label_8004B3F4;
    case 0x8004B3F8u: goto label_8004B3F8;
    case 0x8004B3FCu: goto label_8004B3FC;
    case 0x8004B400u: goto label_8004B400;
    case 0x8004B404u: goto label_8004B404;
    case 0x8004B408u: goto label_8004B408;
    case 0x8004B40Cu: goto label_8004B40C;
    case 0x8004B410u: goto label_8004B410;
    case 0x8004B414u: goto label_8004B414;
    case 0x8004B418u: goto label_8004B418;
    case 0x8004B41Cu: goto label_8004B41C;
    case 0x8004B420u: goto label_8004B420;
    case 0x8004B424u: goto label_8004B424;
    case 0x8004B428u: goto label_8004B428;
    case 0x8004B42Cu: goto label_8004B42C;
    case 0x8004B430u: goto label_8004B430;
    case 0x8004B434u: goto label_8004B434;
    case 0x8004B438u: goto label_8004B438;
    case 0x8004B43Cu: goto label_8004B43C;
    case 0x8004B440u: goto label_8004B440;
    case 0x8004B444u: goto label_8004B444;
    case 0x8004B448u: goto label_8004B448;
    case 0x8004B44Cu: goto label_8004B44C;
    case 0x8004B450u: goto label_8004B450;
    case 0x8004B454u: goto label_8004B454;
    case 0x8004B458u: goto label_8004B458;
    case 0x8004B45Cu: goto label_8004B45C;
    case 0x8004B460u: goto label_8004B460;
    case 0x8004B464u: goto label_8004B464;
    case 0x8004B468u: goto label_8004B468;
    case 0x8004B46Cu: goto label_8004B46C;
    case 0x8004B470u: goto label_8004B470;
    case 0x8004B474u: goto label_8004B474;
    case 0x8004B478u: goto label_8004B478;
    case 0x8004B47Cu: goto label_8004B47C;
    case 0x8004B480u: goto label_8004B480;
    case 0x8004B484u: goto label_8004B484;
    case 0x8004B488u: goto label_8004B488;
    case 0x8004B48Cu: goto label_8004B48C;
    case 0x8004B490u: goto label_8004B490;
    case 0x8004B494u: goto label_8004B494;
    case 0x8004B498u: goto label_8004B498;
    case 0x8004B49Cu: goto label_8004B49C;
    case 0x8004B4A0u: goto label_8004B4A0;
    case 0x8004B4A4u: goto label_8004B4A4;
    case 0x8004B4A8u: goto label_8004B4A8;
    case 0x8004B4ACu: goto label_8004B4AC;
    case 0x8004B4B0u: goto label_8004B4B0;
    case 0x8004B4B4u: goto label_8004B4B4;
    case 0x8004B4B8u: goto label_8004B4B8;
    case 0x8004B4BCu: goto label_8004B4BC;
    default: return;
    }
label_800474C0:
    ctx->pc = 0x800474C0u;
    ctx->downcount -= 1;
    // 800474C0: bl      0x8001D934
    {
            ctx->lr = 0x800474C4u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_800474C4:
    ctx->pc = 0x800474C4u;
    ctx->downcount -= 10;
    // 800474C4: add   r0, r28, r29
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800474C8:
    ctx->pc = 0x800474C8u;
    // 800474C8: stw     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800474CC:
    ctx->pc = 0x800474CCu;
    // 800474CC: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800474D0:
    ctx->pc = 0x800474D0u;
    // 800474D0: stw     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800474D4:
    ctx->pc = 0x800474D4u;
    // 800474D4: lwz     r31, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800474D8:
    ctx->pc = 0x800474D8u;
    // 800474D8: stw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_800474DC:
    ctx->pc = 0x800474DCu;
    // 800474DC: lwz     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800474E0:
    ctx->pc = 0x800474E0u;
    // 800474E0: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800474E4:
    ctx->pc = 0x800474E4u;
    // 800474E4: cmpw    r30, r0
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

label_800474E8:
    ctx->pc = 0x800474E8u;
    // 800474E8: bc    12, 2, 0x80047508
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047508;
        }
    }

label_800474EC:
    ctx->pc = 0x800474ECu;
    ctx->downcount -= 2;
    // 800474EC: cmpwi   r30, 0
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

label_800474F0:
    ctx->pc = 0x800474F0u;
    // 800474F0: bc    12, 2, 0x800474F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800474F8;
        }
    }

label_800474F4:
    ctx->pc = 0x800474F4u;
    ctx->downcount -= 1;
    // 800474F4: stw     r27, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_800474F8:
    ctx->pc = 0x800474F8u;
    ctx->downcount -= 4;
    // 800474F8: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800474FC:
    ctx->pc = 0x800474FCu;
    // 800474FC: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80047500:
    ctx->pc = 0x80047500u;
    // 80047500: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047504:
    ctx->pc = 0x80047504u;
    // 80047504: b       0x80047600
    {
            goto label_80047600;
    }

label_80047508:
    ctx->pc = 0x80047508u;
    ctx->downcount -= 9;
    // 80047508: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004750C:
    ctx->pc = 0x8004750Cu;
    // 8004750C: addi    r11, r1, 36
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(36);

label_80047510:
    ctx->pc = 0x80047510u;
    // 80047510: stw     r22, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[22]);
    }

label_80047514:
    ctx->pc = 0x80047514u;
    // 80047514: addi    r10, r1, 32
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(32);

label_80047518:
    ctx->pc = 0x80047518u;
    // 80047518: subf   r0, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8004751C:
    ctx->pc = 0x8004751Cu;
    // 8004751C: srawi r9, r0, 2
    {
        u32 sh = 2u;
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
    }

label_80047520:
    ctx->pc = 0x80047520u;
    // 80047520: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047524:
    ctx->pc = 0x80047524u;
    // 80047524: cmplw   r9, r22
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(ctx->gpr[22]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80047528:
    ctx->pc = 0x80047528u;
    // 80047528: bc    4, 0, 0x80047530
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047530;
        }
    }

label_8004752C:
    ctx->pc = 0x8004752Cu;
    ctx->downcount -= 1;
    // 8004752C: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80047530:
    ctx->pc = 0x80047530u;
    ctx->downcount -= 3;
    // 80047530: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047534:
    ctx->pc = 0x80047534u;
    // 80047534: add.   r0, r9, r0
    {
        u32 a = ctx->gpr[9];
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

label_80047538:
    ctx->pc = 0x80047538u;
    // 80047538: bc    12, 2, 0x8004756C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004756C;
        }
    }

label_8004753C:
    ctx->pc = 0x8004753Cu;
    ctx->downcount -= 4;
    // 8004753C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80047540:
    ctx->pc = 0x80047540u;
    // 80047540: or   r28, r0, r0
    {
        ctx->gpr[28] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80047544:
    ctx->pc = 0x80047544u;
    // 80047544: cmplwi  r0, 0x0080
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

label_80047548:
    ctx->pc = 0x80047548u;
    // 80047548: bc    4, 1, 0x8004755C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004755C;
        }
    }

label_8004754C:
    ctx->pc = 0x8004754Cu;
    ctx->downcount -= 2;
    // 8004754C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80047550:
    ctx->pc = 0x80047550u;
    // 80047550: bl      0x80281C60
    {
            ctx->lr = 0x80047554u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80047554:
    ctx->pc = 0x80047554u;
    ctx->downcount -= 2;
    // 80047554: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047558:
    ctx->pc = 0x80047558u;
    // 80047558: b       0x80047574
    {
            goto label_80047574;
    }

label_8004755C:
    ctx->pc = 0x8004755Cu;
    ctx->downcount -= 2;
    // 8004755C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80047560:
    ctx->pc = 0x80047560u;
    // 80047560: bl      0x80004024
    {
            ctx->lr = 0x80047564u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80047564:
    ctx->pc = 0x80047564u;
    ctx->downcount -= 2;
    // 80047564: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047568:
    ctx->pc = 0x80047568u;
    // 80047568: b       0x80047574
    {
            goto label_80047574;
    }

label_8004756C:
    ctx->pc = 0x8004756Cu;
    ctx->downcount -= 2;
    // 8004756C: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80047570:
    ctx->pc = 0x80047570u;
    // 80047570: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80047574:
    ctx->pc = 0x80047574u;
    ctx->downcount -= 3;
    // 80047574: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80047578:
    ctx->pc = 0x80047578u;
    // 80047578: cmpw    r30, r4
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

label_8004757C:
    ctx->pc = 0x8004757Cu;
    // 8004757C: bc    12, 2, 0x80047598
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047598;
        }
    }

label_80047580:
    ctx->pc = 0x80047580u;
    ctx->downcount -= 4;
    // 80047580: subf   r30, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_80047584:
    ctx->pc = 0x80047584u;
    // 80047584: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80047588:
    ctx->pc = 0x80047588u;
    // 80047588: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8004758C:
    ctx->pc = 0x8004758Cu;
    // 8004758C: bl      0x80297E3C
    {
            ctx->lr = 0x80047590u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80047590:
    ctx->pc = 0x80047590u;
    ctx->downcount -= 2;
    // 80047590: add   r0, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80047594:
    ctx->pc = 0x80047594u;
    // 80047594: b       0x8004759C
    {
            goto label_8004759C;
    }

label_80047598:
    ctx->pc = 0x80047598u;
    ctx->downcount -= 1;
    // 80047598: or   r0, r29, r29
    {
        ctx->gpr[0] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8004759C:
    ctx->pc = 0x8004759Cu;
    ctx->downcount -= 6;
    // 8004759C: lwz     r9, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800475A0:
    ctx->pc = 0x800475A0u;
    // 800475A0: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_800475A4:
    ctx->pc = 0x800475A4u;
    // 800475A4: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_800475A8:
    ctx->pc = 0x800475A8u;
    // 800475A8: cmpwi   r9, 0
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

label_800475AC:
    ctx->pc = 0x800475ACu;
    // 800475AC: bc    12, 2, 0x800475C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800475C0;
        }
    }

label_800475B0:
    loop_800475B0(ctx);
    if (ctx->pc == 0x800475C0u) goto label_800475C0;
    return;
label_800475B4:
    ctx->pc = 0x800475B4u;
    // 800475B4: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800475B8:
    // 800475B8: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_800475BC:
    // 800475BC: bc    16, 0, 0x800475B0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800475B0u;
                return;
            }
            goto label_800475B0;
        }
    }

label_800475C0:
    ctx->pc = 0x800475C0u;
    ctx->downcount -= 6;
    // 800475C0: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800475C4:
    ctx->pc = 0x800475C4u;
    // 800475C4: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800475C8:
    ctx->pc = 0x800475C8u;
    // 800475C8: cmpwi   r3, 0
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

label_800475CC:
    ctx->pc = 0x800475CCu;
    // 800475CC: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800475D0:
    ctx->pc = 0x800475D0u;
    // 800475D0: srawi r0, r0, 2
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

label_800475D4:
    ctx->pc = 0x800475D4u;
    // 800475D4: bc    12, 2, 0x800475F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800475F0;
        }
    }

label_800475D8:
    ctx->pc = 0x800475D8u;
    ctx->downcount -= 3;
    // 800475D8: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_800475DC:
    ctx->pc = 0x800475DCu;
    // 800475DC: cmplwi  r4, 0x0080
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

label_800475E0:
    ctx->pc = 0x800475E0u;
    // 800475E0: bc    4, 1, 0x800475EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800475EC;
        }
    }

label_800475E4:
    ctx->pc = 0x800475E4u;
    ctx->downcount -= 1;
    // 800475E4: bl      0x80281D80
    {
            ctx->lr = 0x800475E8u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800475E8:
    ctx->pc = 0x800475E8u;
    ctx->downcount -= 1;
    // 800475E8: b       0x800475F0
    {
            goto label_800475F0;
    }

label_800475EC:
    ctx->pc = 0x800475ECu;
    ctx->downcount -= 1;
    // 800475EC: bl      0x8001D934
    {
            ctx->lr = 0x800475F0u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_800475F0:
    ctx->pc = 0x800475F0u;
    ctx->downcount -= 4;
    // 800475F0: add   r0, r28, r29
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800475F4:
    ctx->pc = 0x800475F4u;
    // 800475F4: stw     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800475F8:
    ctx->pc = 0x800475F8u;
    // 800475F8: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800475FC:
    ctx->pc = 0x800475FCu;
    // 800475FC: stw     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80047600:
    ctx->pc = 0x80047600u;
    ctx->downcount -= 3;
    // 80047600: or   r27, r23, r23
    {
        ctx->gpr[27] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80047604:
    ctx->pc = 0x80047604u;
    // 80047604: cmplw   r27, r20
    {
        u32 val_a = (u32)(ctx->gpr[27]);
        u32 val_b = (u32)(ctx->gpr[20]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80047608:
    ctx->pc = 0x80047608u;
    // 80047608: bc    12, 0, 0x80047364
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x80047364u;
            return;
        }
    }

label_8004760C:
    ctx->pc = 0x8004760Cu;
    ctx->downcount -= 17;
    // 8004760C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80047610:
    ctx->pc = 0x80047610u;
    // 80047610: lwz     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047614:
    ctx->pc = 0x80047614u;
    // 80047614: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80047618:
    ctx->pc = 0x80047618u;
    // 80047618: lmw     r19, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 19; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004761C:
    ctx->pc = 0x8004761Cu;
    // 8004761C: addi    r1, r1, 96
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(96);

label_80047620:
    ctx->pc = 0x80047620u;
    // 80047620: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80047624:
    ctx->pc = 0x80047624u;
    ctx->downcount -= 18;
    // 80047624: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80047628:
    ctx->pc = 0x80047628u;
    // 80047628: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004762C:
    ctx->pc = 0x8004762Cu;
    // 8004762C: stmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80047630:
    ctx->pc = 0x80047630u;
    // 80047630: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047634:
    ctx->pc = 0x80047634u;
    // 80047634: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047638:
    ctx->pc = 0x80047638u;
    // 80047638: lwz     r31, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004763C:
    ctx->pc = 0x8004763Cu;
    // 8004763C: cmpwi   r31, 0
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

label_80047640:
    ctx->pc = 0x80047640u;
    // 80047640: bc    4, 2, 0x8004765C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004765C;
        }
    }

label_80047644:
    ctx->pc = 0x80047644u;
    ctx->downcount -= 2;
    // 80047644: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80047648:
    ctx->pc = 0x80047648u;
    // 80047648: bl      0x80281C60
    {
            ctx->lr = 0x8004764Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8004764C:
    ctx->pc = 0x8004764Cu;
    ctx->downcount -= 4;
    // 8004764C: stw     r31, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047650:
    ctx->pc = 0x80047650u;
    // 80047650: stw     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80047654:
    ctx->pc = 0x80047654u;
    // 80047654: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047658:
    ctx->pc = 0x80047658u;
    // 80047658: stw     r31, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004765C:
    ctx->pc = 0x8004765Cu;
    ctx->downcount -= 3;
    // 8004765C: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80047660:
    ctx->pc = 0x80047660u;
    // 80047660: cmpwi   r31, 0
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

label_80047664:
    ctx->pc = 0x80047664u;
    // 80047664: bc    4, 2, 0x80047680
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047680;
        }
    }

label_80047668:
    ctx->pc = 0x80047668u;
    ctx->downcount -= 2;
    // 80047668: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_8004766C:
    ctx->pc = 0x8004766Cu;
    // 8004766C: bl      0x80281C60
    {
            ctx->lr = 0x80047670u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80047670:
    ctx->pc = 0x80047670u;
    ctx->downcount -= 4;
    // 80047670: stw     r31, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047674:
    ctx->pc = 0x80047674u;
    // 80047674: stw     r3, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80047678:
    ctx->pc = 0x80047678u;
    // 80047678: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004767C:
    ctx->pc = 0x8004767Cu;
    // 8004767C: stw     r31, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047680:
    ctx->pc = 0x80047680u;
    ctx->downcount -= 6;
    // 80047680: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047684:
    ctx->pc = 0x80047684u;
    // 80047684: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80047688:
    ctx->pc = 0x80047688u;
    // 80047688: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004768C:
    ctx->pc = 0x8004768Cu;
    // 8004768C: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047690:
    ctx->pc = 0x80047690u;
    // 80047690: rlwinm. r9, r0, 30, 2, 31
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

label_80047694:
    ctx->pc = 0x80047694u;
    // 80047694: bc    4, 2, 0x800476D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800476D8;
        }
    }

label_80047698:
    ctx->pc = 0x80047698u;
    ctx->downcount -= 3;
    // 80047698: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004769C:
    ctx->pc = 0x8004769Cu;
    // 8004769C: cmpwi   r0, 0
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

label_800476A0:
    ctx->pc = 0x800476A0u;
    // 800476A0: bc    4, 2, 0x800476D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800476D0;
        }
    }

label_800476A4:
    ctx->pc = 0x800476A4u;
    ctx->downcount -= 9;
    // 800476A4: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800476A8:
    ctx->pc = 0x800476A8u;
    // 800476A8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800476AC:
    ctx->pc = 0x800476ACu;
    // 800476AC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800476B0:
    ctx->pc = 0x800476B0u;
    // 800476B0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800476B4:
    ctx->pc = 0x800476B4u;
    // 800476B4: lwz     r4, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800476B8:
    ctx->pc = 0x800476B8u;
    // 800476B8: subf   r4, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_800476BC:
    ctx->pc = 0x800476BCu;
    // 800476BC: srawi r4, r4, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[4];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_800476C0:
    ctx->pc = 0x800476C0u;
    // 800476C0: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_800476C4:
    ctx->pc = 0x800476C4u;
    // 800476C4: bl      0x8001BA20
    {
            ctx->lr = 0x800476C8u;
            ctx->pc = 0x8001BA20u;
            return;
    }

label_800476C8:
    ctx->pc = 0x800476C8u;
    ctx->downcount -= 2;
    // 800476C8: cmpwi   r3, 0
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

label_800476CC:
    ctx->pc = 0x800476CCu;
    // 800476CC: bc    4, 2, 0x800476D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800476D8;
        }
    }

label_800476D0:
    ctx->pc = 0x800476D0u;
    ctx->downcount -= 2;
    // 800476D0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800476D4:
    ctx->pc = 0x800476D4u;
    // 800476D4: b       0x800476FC
    {
            goto label_800476FC;
    }

label_800476D8:
    ctx->pc = 0x800476D8u;
    ctx->downcount -= 9;
    // 800476D8: lwz     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800476DC:
    ctx->pc = 0x800476DCu;
    // 800476DC: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800476E0:
    ctx->pc = 0x800476E0u;
    // 800476E0: lwzu     r0, -4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_800476E4:
    ctx->pc = 0x800476E4u;
    // 800476E4: stw     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800476E8:
    ctx->pc = 0x800476E8u;
    // 800476E8: rlwinm r10, r0, 2, 0, 29
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_800476EC:
    ctx->pc = 0x800476ECu;
    // 800476EC: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800476F0:
    ctx->pc = 0x800476F0u;
    // 800476F0: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800476F4:
    ctx->pc = 0x800476F4u;
    // 800476F4: lwzx    r3, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800476F8:
    ctx->pc = 0x800476F8u;
    // 800476F8: stw     r0, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800476FC:
    ctx->pc = 0x800476FCu;
    ctx->downcount -= 16;
    // 800476FC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047700:
    ctx->pc = 0x80047700u;
    // 80047700: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80047704:
    ctx->pc = 0x80047704u;
    // 80047704: lmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80047708:
    ctx->pc = 0x80047708u;
    // 80047708: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8004770C:
    ctx->pc = 0x8004770Cu;
    // 8004770C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80047710:
    ctx->pc = 0x80047710u;
    ctx->downcount -= 23;
    // 80047710: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80047714:
    ctx->pc = 0x80047714u;
    // 80047714: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80047718:
    ctx->pc = 0x80047718u;
    // 80047718: stmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8004771C:
    ctx->pc = 0x8004771Cu;
    // 8004771C: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047720:
    ctx->pc = 0x80047720u;
    // 80047720: lwz     r31, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80047724:
    ctx->pc = 0x80047724u;
    // 80047724: or   r27, r4, r4
    {
        ctx->gpr[27] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80047728:
    ctx->pc = 0x80047728u;
    // 80047728: lwz     r9, 40(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004772C:
    ctx->pc = 0x8004772Cu;
    // 8004772C: addi    r26, r1, 8
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(8);

label_80047730:
    ctx->pc = 0x80047730u;
    // 80047730: lwz     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80047734:
    ctx->pc = 0x80047734u;
    // 80047734: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047738:
    ctx->pc = 0x80047738u;
    // 80047738: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004773C:
    ctx->pc = 0x8004773Cu;
    // 8004773C: cmpw    r30, r0
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

label_80047740:
    ctx->pc = 0x80047740u;
    // 80047740: bc    12, 2, 0x80047760
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047760;
        }
    }

label_80047744:
    ctx->pc = 0x80047744u;
    ctx->downcount -= 2;
    // 80047744: cmpwi   r30, 0
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

label_80047748:
    ctx->pc = 0x80047748u;
    // 80047748: bc    12, 2, 0x80047750
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047750;
        }
    }

label_8004774C:
    ctx->pc = 0x8004774Cu;
    ctx->downcount -= 1;
    // 8004774C: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047750:
    ctx->pc = 0x80047750u;
    ctx->downcount -= 4;
    // 80047750: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047754:
    ctx->pc = 0x80047754u;
    // 80047754: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80047758:
    ctx->pc = 0x80047758u;
    // 80047758: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004775C:
    ctx->pc = 0x8004775Cu;
    // 8004775C: b       0x8004785C
    {
            goto label_8004785C;
    }

label_80047760:
    ctx->pc = 0x80047760u;
    ctx->downcount -= 10;
    // 80047760: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047764:
    ctx->pc = 0x80047764u;
    // 80047764: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_80047768:
    ctx->pc = 0x80047768u;
    // 80047768: stw     r9, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004776C:
    ctx->pc = 0x8004776Cu;
    // 8004776C: addi    r10, r1, 16
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(16);

label_80047770:
    ctx->pc = 0x80047770u;
    // 80047770: subf   r0, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047774:
    ctx->pc = 0x80047774u;
    // 80047774: addi    r11, r1, 12
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(12);

label_80047778:
    ctx->pc = 0x80047778u;
    // 80047778: srawi r9, r0, 2
    {
        u32 sh = 2u;
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
    }

label_8004777C:
    ctx->pc = 0x8004777Cu;
    // 8004777C: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047780:
    ctx->pc = 0x80047780u;
    // 80047780: cmplwi  r9, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80047784:
    ctx->pc = 0x80047784u;
    // 80047784: bc    4, 0, 0x8004778C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004778C;
        }
    }

label_80047788:
    ctx->pc = 0x80047788u;
    ctx->downcount -= 1;
    // 80047788: or   r11, r10, r10
    {
        ctx->gpr[11] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8004778C:
    ctx->pc = 0x8004778Cu;
    ctx->downcount -= 3;
    // 8004778C: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047790:
    ctx->pc = 0x80047790u;
    // 80047790: add.   r0, r9, r0
    {
        u32 a = ctx->gpr[9];
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

label_80047794:
    ctx->pc = 0x80047794u;
    // 80047794: bc    12, 2, 0x800477C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800477C8;
        }
    }

label_80047798:
    ctx->pc = 0x80047798u;
    ctx->downcount -= 4;
    // 80047798: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8004779C:
    ctx->pc = 0x8004779Cu;
    // 8004779C: or   r28, r0, r0
    {
        ctx->gpr[28] = ctx->gpr[0] | ctx->gpr[0];
    }

label_800477A0:
    ctx->pc = 0x800477A0u;
    // 800477A0: cmplwi  r0, 0x0080
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

label_800477A4:
    ctx->pc = 0x800477A4u;
    // 800477A4: bc    4, 1, 0x800477B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800477B8;
        }
    }

label_800477A8:
    ctx->pc = 0x800477A8u;
    ctx->downcount -= 2;
    // 800477A8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800477AC:
    ctx->pc = 0x800477ACu;
    // 800477AC: bl      0x80281C60
    {
            ctx->lr = 0x800477B0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800477B0:
    ctx->pc = 0x800477B0u;
    ctx->downcount -= 2;
    // 800477B0: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800477B4:
    ctx->pc = 0x800477B4u;
    // 800477B4: b       0x800477D0
    {
            goto label_800477D0;
    }

label_800477B8:
    ctx->pc = 0x800477B8u;
    ctx->downcount -= 2;
    // 800477B8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800477BC:
    ctx->pc = 0x800477BCu;
    // 800477BC: bl      0x80004024
    {
            ctx->lr = 0x800477C0u;
            ctx->pc = 0x80004024u;
            return;
    }

label_800477C0:
    ctx->pc = 0x800477C0u;
    ctx->downcount -= 2;
    // 800477C0: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800477C4:
    ctx->pc = 0x800477C4u;
    // 800477C4: b       0x800477D0
    {
            goto label_800477D0;
    }

label_800477C8:
    ctx->pc = 0x800477C8u;
    ctx->downcount -= 2;
    // 800477C8: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_800477CC:
    ctx->pc = 0x800477CCu;
    // 800477CC: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_800477D0:
    ctx->pc = 0x800477D0u;
    ctx->downcount -= 3;
    // 800477D0: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800477D4:
    ctx->pc = 0x800477D4u;
    // 800477D4: cmpw    r30, r4
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

label_800477D8:
    ctx->pc = 0x800477D8u;
    // 800477D8: bc    12, 2, 0x800477F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800477F4;
        }
    }

label_800477DC:
    ctx->pc = 0x800477DCu;
    ctx->downcount -= 4;
    // 800477DC: subf   r30, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_800477E0:
    ctx->pc = 0x800477E0u;
    // 800477E0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800477E4:
    ctx->pc = 0x800477E4u;
    // 800477E4: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800477E8:
    ctx->pc = 0x800477E8u;
    // 800477E8: bl      0x80297E3C
    {
            ctx->lr = 0x800477ECu;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_800477EC:
    ctx->pc = 0x800477ECu;
    ctx->downcount -= 2;
    // 800477EC: add   r0, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800477F0:
    ctx->pc = 0x800477F0u;
    // 800477F0: b       0x800477F8
    {
            goto label_800477F8;
    }

label_800477F4:
    ctx->pc = 0x800477F4u;
    ctx->downcount -= 1;
    // 800477F4: or   r0, r29, r29
    {
        ctx->gpr[0] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800477F8:
    ctx->pc = 0x800477F8u;
    ctx->downcount -= 6;
    // 800477F8: lwz     r9, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800477FC:
    ctx->pc = 0x800477FCu;
    // 800477FC: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80047800:
    ctx->pc = 0x80047800u;
    // 80047800: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_80047804:
    ctx->pc = 0x80047804u;
    // 80047804: cmpwi   r9, 0
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

label_80047808:
    ctx->pc = 0x80047808u;
    // 80047808: bc    12, 2, 0x8004781C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004781C;
        }
    }

label_8004780C:
    loop_8004780C(ctx);
    if (ctx->pc == 0x8004781Cu) goto label_8004781C;
    return;
label_80047810:
    ctx->pc = 0x80047810u;
    // 80047810: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047814:
    // 80047814: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_80047818:
    // 80047818: bc    16, 0, 0x8004780C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004780Cu;
                return;
            }
            goto label_8004780C;
        }
    }

label_8004781C:
    ctx->pc = 0x8004781Cu;
    ctx->downcount -= 6;
    // 8004781C: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80047820:
    ctx->pc = 0x80047820u;
    // 80047820: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047824:
    ctx->pc = 0x80047824u;
    // 80047824: cmpwi   r3, 0
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

label_80047828:
    ctx->pc = 0x80047828u;
    // 80047828: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8004782C:
    ctx->pc = 0x8004782Cu;
    // 8004782C: srawi r0, r0, 2
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

label_80047830:
    ctx->pc = 0x80047830u;
    // 80047830: bc    12, 2, 0x8004784C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004784C;
        }
    }

label_80047834:
    ctx->pc = 0x80047834u;
    ctx->downcount -= 3;
    // 80047834: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80047838:
    ctx->pc = 0x80047838u;
    // 80047838: cmplwi  r4, 0x0080
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

label_8004783C:
    ctx->pc = 0x8004783Cu;
    // 8004783C: bc    4, 1, 0x80047848
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047848;
        }
    }

label_80047840:
    ctx->pc = 0x80047840u;
    ctx->downcount -= 1;
    // 80047840: bl      0x80281D80
    {
            ctx->lr = 0x80047844u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80047844:
    ctx->pc = 0x80047844u;
    ctx->downcount -= 1;
    // 80047844: b       0x8004784C
    {
            goto label_8004784C;
    }

label_80047848:
    ctx->pc = 0x80047848u;
    ctx->downcount -= 1;
    // 80047848: bl      0x8001D934
    {
            ctx->lr = 0x8004784Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_8004784C:
    ctx->pc = 0x8004784Cu;
    ctx->downcount -= 4;
    // 8004784C: add   r0, r28, r29
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80047850:
    ctx->pc = 0x80047850u;
    // 80047850: stw     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80047854:
    ctx->pc = 0x80047854u;
    // 80047854: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047858:
    ctx->pc = 0x80047858u;
    // 80047858: stw     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8004785C:
    ctx->pc = 0x8004785Cu;
    ctx->downcount -= 8;
    // 8004785C: lwz     r9, 32(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047860:
    ctx->pc = 0x80047860u;
    // 80047860: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80047864:
    ctx->pc = 0x80047864u;
    // 80047864: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047868:
    ctx->pc = 0x80047868u;
    // 80047868: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004786C:
    ctx->pc = 0x8004786Cu;
    // 8004786C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80047870:
    ctx->pc = 0x80047870u;
    // 80047870: add   r3, r27, r3
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80047874:
    ctx->pc = 0x80047874u;
    // 80047874: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80047878u;
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80047878:
    ctx->pc = 0x80047878u;
    ctx->downcount -= 18;
    // 80047878: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8004787C:
    ctx->pc = 0x8004787Cu;
    // 8004787C: stw     r0, 40(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047880:
    ctx->pc = 0x80047880u;
    // 80047880: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047884:
    ctx->pc = 0x80047884u;
    // 80047884: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80047888:
    ctx->pc = 0x80047888u;
    // 80047888: lmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004788C:
    ctx->pc = 0x8004788Cu;
    // 8004788C: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_80047890:
    ctx->pc = 0x80047890u;
    // 80047890: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80047894:
    ctx->pc = 0x80047894u;
    ctx->downcount -= 18;
    // 80047894: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80047898:
    ctx->pc = 0x80047898u;
    // 80047898: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004789C:
    ctx->pc = 0x8004789Cu;
    // 8004789C: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800478A0:
    ctx->pc = 0x800478A0u;
    // 800478A0: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800478A4:
    ctx->pc = 0x800478A4u;
    // 800478A4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800478A8:
    ctx->pc = 0x800478A8u;
    // 800478A8: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800478AC:
    ctx->pc = 0x800478ACu;
    // 800478AC: cmpwi   r11, 0
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

label_800478B0:
    ctx->pc = 0x800478B0u;
    // 800478B0: bc    12, 2, 0x80047994
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047994;
        }
    }

label_800478B4:
    ctx->pc = 0x800478B4u;
    ctx->downcount -= 6;
    // 800478B4: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800478B8:
    ctx->pc = 0x800478B8u;
    // 800478B8: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_800478BC:
    ctx->pc = 0x800478BCu;
    // 800478BC: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800478C0:
    ctx->pc = 0x800478C0u;
    // 800478C0: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800478C4:
    ctx->pc = 0x800478C4u;
    // 800478C4: rlwinm. r9, r0, 30, 2, 31
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

label_800478C8:
    ctx->pc = 0x800478C8u;
    // 800478C8: bc    12, 2, 0x80047948
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047948;
        }
    }

label_800478CC:
    ctx->pc = 0x800478CCu;
    ctx->downcount -= 2;
    // 800478CC: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_800478D0:
    ctx->pc = 0x800478D0u;
    // 800478D0: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_800478D4:
    ctx->pc = 0x800478D4u;
    ctx->downcount -= 6;
    // 800478D4: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800478D8:
    ctx->pc = 0x800478D8u;
    // 800478D8: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800478DC:
    ctx->pc = 0x800478DCu;
    // 800478DC: lwzx    r11, r11, r29
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[29];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800478E0:
    ctx->pc = 0x800478E0u;
    // 800478E0: lwz     r0, 40(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800478E4:
    // 800478E4: cmpwi   r0, -1
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

label_800478E8:
    // 800478E8: bc    12, 2, 0x80047910
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047910;
        }
    }

label_800478EC:
    ctx->downcount -= 2;
    // 800478EC: cmpwi   r11, 0
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

label_800478F0:
    // 800478F0: bc    12, 2, 0x80047910
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047910;
        }
    }

label_800478F4:
    ctx->pc = 0x800478F4u;
    ctx->downcount -= 8;
    // 800478F4: lwz     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800478F8:
    // 800478F8: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_800478FC:
    ctx->pc = 0x800478FCu;
    // 800478FC: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80047900:
    ctx->pc = 0x80047900u;
    // 80047900: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047904:
    // 80047904: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80047908:
    ctx->pc = 0x80047908u;
    // 80047908: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004790C:
    ctx->pc = 0x8004790Cu;
    // 8004790C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80047910u;
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80047910:
    ctx->pc = 0x80047910u;
    ctx->downcount -= 7;
    // 80047910: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80047914:
    // 80047914: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_80047918:
    // 80047918: addi    r29, r29, 4
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(4);

label_8004791C:
    ctx->pc = 0x8004791Cu;
    // 8004791C: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047920:
    ctx->pc = 0x80047920u;
    // 80047920: lwzx    r3, r9, r28
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[28];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80047924:
    // 80047924: addi    r28, r28, 4
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(4);

label_80047928:
    // 80047928: bl      0x80281B70
    {
            ctx->lr = 0x8004792Cu;
            ctx->pc = 0x80281B70u;
            return;
    }

label_8004792C:
    ctx->pc = 0x8004792Cu;
    ctx->downcount -= 7;
    // 8004792C: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047930:
    ctx->pc = 0x80047930u;
    // 80047930: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80047934:
    ctx->pc = 0x80047934u;
    // 80047934: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047938:
    // 80047938: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8004793C:
    // 8004793C: srawi r0, r0, 2
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

label_80047940:
    // 80047940: cmplw   r31, r0
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

label_80047944:
    // 80047944: bc    12, 0, 0x800478D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800478D4u;
                return;
            }
            goto label_800478D4;
        }
    }

label_80047948:
    ctx->pc = 0x80047948u;
    ctx->downcount -= 6;
    // 80047948: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004794C:
    ctx->pc = 0x8004794Cu;
    // 8004794C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047950:
    ctx->pc = 0x80047950u;
    // 80047950: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047954:
    ctx->pc = 0x80047954u;
    // 80047954: lwz     r31, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80047958:
    ctx->pc = 0x80047958u;
    // 80047958: cmpwi   r31, 0
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

label_8004795C:
    ctx->pc = 0x8004795Cu;
    // 8004795C: bc    12, 2, 0x80047994
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047994;
        }
    }

label_80047960:
    ctx->pc = 0x80047960u;
    ctx->downcount -= 3;
    // 80047960: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80047964:
    ctx->pc = 0x80047964u;
    // 80047964: cmpwi   r3, 0
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

label_80047968:
    ctx->pc = 0x80047968u;
    // 80047968: bc    12, 2, 0x8004798C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004798C;
        }
    }

label_8004796C:
    ctx->pc = 0x8004796Cu;
    ctx->downcount -= 5;
    // 8004796C: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047970:
    ctx->pc = 0x80047970u;
    // 80047970: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047974:
    ctx->pc = 0x80047974u;
    // 80047974: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80047978:
    ctx->pc = 0x80047978u;
    // 80047978: cmplwi  r4, 0x0080
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

label_8004797C:
    ctx->pc = 0x8004797Cu;
    // 8004797C: bc    4, 1, 0x80047988
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047988;
        }
    }

label_80047980:
    ctx->pc = 0x80047980u;
    ctx->downcount -= 1;
    // 80047980: bl      0x80281D80
    {
            ctx->lr = 0x80047984u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80047984:
    ctx->pc = 0x80047984u;
    ctx->downcount -= 1;
    // 80047984: b       0x8004798C
    {
            goto label_8004798C;
    }

label_80047988:
    ctx->pc = 0x80047988u;
    ctx->downcount -= 1;
    // 80047988: bl      0x8001D934
    {
            ctx->lr = 0x8004798Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_8004798C:
    ctx->pc = 0x8004798Cu;
    ctx->downcount -= 2;
    // 8004798C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80047990:
    ctx->pc = 0x80047990u;
    // 80047990: bl      0x80281D80
    {
            ctx->lr = 0x80047994u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80047994:
    ctx->pc = 0x80047994u;
    ctx->downcount -= 5;
    // 80047994: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047998:
    ctx->pc = 0x80047998u;
    // 80047998: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004799C:
    ctx->pc = 0x8004799Cu;
    // 8004799C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800479A0:
    ctx->pc = 0x800479A0u;
    // 800479A0: cmpwi   r9, 0
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

label_800479A4:
    ctx->pc = 0x800479A4u;
    // 800479A4: bc    12, 2, 0x800479F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800479F0;
        }
    }

label_800479A8:
    ctx->pc = 0x800479A8u;
    ctx->downcount -= 5;
    // 800479A8: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800479AC:
    ctx->pc = 0x800479ACu;
    // 800479AC: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800479B0:
    ctx->pc = 0x800479B0u;
    // 800479B0: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800479B4:
    ctx->pc = 0x800479B4u;
    // 800479B4: cmpwi   r31, 0
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

label_800479B8:
    ctx->pc = 0x800479B8u;
    // 800479B8: bc    12, 2, 0x800479F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800479F0;
        }
    }

label_800479BC:
    ctx->pc = 0x800479BCu;
    ctx->downcount -= 3;
    // 800479BC: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800479C0:
    ctx->pc = 0x800479C0u;
    // 800479C0: cmpwi   r3, 0
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

label_800479C4:
    ctx->pc = 0x800479C4u;
    // 800479C4: bc    12, 2, 0x800479E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800479E8;
        }
    }

label_800479C8:
    ctx->pc = 0x800479C8u;
    ctx->downcount -= 5;
    // 800479C8: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800479CC:
    ctx->pc = 0x800479CCu;
    // 800479CC: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800479D0:
    ctx->pc = 0x800479D0u;
    // 800479D0: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_800479D4:
    ctx->pc = 0x800479D4u;
    // 800479D4: cmplwi  r4, 0x0080
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

label_800479D8:
    ctx->pc = 0x800479D8u;
    // 800479D8: bc    4, 1, 0x800479E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800479E4;
        }
    }

label_800479DC:
    ctx->pc = 0x800479DCu;
    ctx->downcount -= 1;
    // 800479DC: bl      0x80281D80
    {
            ctx->lr = 0x800479E0u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800479E0:
    ctx->pc = 0x800479E0u;
    ctx->downcount -= 1;
    // 800479E0: b       0x800479E8
    {
            goto label_800479E8;
    }

label_800479E4:
    ctx->pc = 0x800479E4u;
    ctx->downcount -= 1;
    // 800479E4: bl      0x8001D934
    {
            ctx->lr = 0x800479E8u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_800479E8:
    ctx->pc = 0x800479E8u;
    ctx->downcount -= 2;
    // 800479E8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800479EC:
    ctx->pc = 0x800479ECu;
    // 800479EC: bl      0x80281D80
    {
            ctx->lr = 0x800479F0u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800479F0:
    ctx->pc = 0x800479F0u;
    ctx->downcount -= 19;
    // 800479F0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800479F4:
    ctx->pc = 0x800479F4u;
    // 800479F4: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800479F8:
    ctx->pc = 0x800479F8u;
    // 800479F8: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800479FC:
    ctx->pc = 0x800479FCu;
    // 800479FC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047A00:
    ctx->pc = 0x80047A00u;
    // 80047A00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80047A04:
    ctx->pc = 0x80047A04u;
    // 80047A04: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80047A08:
    ctx->pc = 0x80047A08u;
    // 80047A08: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80047A0C:
    ctx->pc = 0x80047A0Cu;
    // 80047A0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80047A10:
    ctx->pc = 0x80047A10u;
    ctx->downcount -= 21;
    // 80047A10: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80047A14:
    ctx->pc = 0x80047A14u;
    // 80047A14: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80047A18:
    ctx->pc = 0x80047A18u;
    // 80047A18: stmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80047A1C:
    ctx->pc = 0x80047A1Cu;
    // 80047A1C: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047A20:
    ctx->pc = 0x80047A20u;
    // 80047A20: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047A24:
    ctx->pc = 0x80047A24u;
    // 80047A24: lwz     r29, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80047A28:
    ctx->pc = 0x80047A28u;
    // 80047A28: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047A2C:
    ctx->pc = 0x80047A2Cu;
    // 80047A2C: subf   r0, r29, r0
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047A30:
    ctx->pc = 0x80047A30u;
    // 80047A30: srawi r0, r0, 2
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

label_80047A34:
    ctx->pc = 0x80047A34u;
    // 80047A34: cmplw   r0, r4
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80047A38:
    ctx->pc = 0x80047A38u;
    // 80047A38: bc    4, 0, 0x80047B30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047B30;
        }
    }

label_80047A3C:
    ctx->pc = 0x80047A3Cu;
    ctx->downcount -= 5;
    // 80047A3C: lwz     r27, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[27] = mem_read32(ctx, ea);
    }

label_80047A40:
    ctx->pc = 0x80047A40u;
    // 80047A40: cmpwi   r29, 0
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

label_80047A44:
    ctx->pc = 0x80047A44u;
    // 80047A44: subf   r0, r29, r27
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047A48:
    ctx->pc = 0x80047A48u;
    // 80047A48: srawi r26, r0, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[26] = value;
        } else if (sh > 31) {
            ctx->gpr[26] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[26] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80047A4C:
    ctx->pc = 0x80047A4Cu;
    // 80047A4C: bc    12, 2, 0x80047ADC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047ADC;
        }
    }

label_80047A50:
    ctx->pc = 0x80047A50u;
    ctx->downcount -= 2;
    // 80047A50: cmpwi   r4, 0
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

label_80047A54:
    ctx->pc = 0x80047A54u;
    // 80047A54: bc    12, 2, 0x80047A88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047A88;
        }
    }

label_80047A58:
    ctx->pc = 0x80047A58u;
    ctx->downcount -= 4;
    // 80047A58: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_80047A5C:
    ctx->pc = 0x80047A5Cu;
    // 80047A5C: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80047A60:
    ctx->pc = 0x80047A60u;
    // 80047A60: cmplwi  r0, 0x0080
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

label_80047A64:
    ctx->pc = 0x80047A64u;
    // 80047A64: bc    4, 1, 0x80047A78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047A78;
        }
    }

label_80047A68:
    ctx->pc = 0x80047A68u;
    ctx->downcount -= 2;
    // 80047A68: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80047A6C:
    ctx->pc = 0x80047A6Cu;
    // 80047A6C: bl      0x80281C60
    {
            ctx->lr = 0x80047A70u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80047A70:
    ctx->pc = 0x80047A70u;
    ctx->downcount -= 2;
    // 80047A70: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047A74:
    ctx->pc = 0x80047A74u;
    // 80047A74: b       0x80047A90
    {
            goto label_80047A90;
    }

label_80047A78:
    ctx->pc = 0x80047A78u;
    ctx->downcount -= 2;
    // 80047A78: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80047A7C:
    ctx->pc = 0x80047A7Cu;
    // 80047A7C: bl      0x80004024
    {
            ctx->lr = 0x80047A80u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80047A80:
    ctx->pc = 0x80047A80u;
    ctx->downcount -= 2;
    // 80047A80: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047A84:
    ctx->pc = 0x80047A84u;
    // 80047A84: b       0x80047A90
    {
            goto label_80047A90;
    }

label_80047A88:
    ctx->pc = 0x80047A88u;
    ctx->downcount -= 2;
    // 80047A88: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80047A8C:
    ctx->pc = 0x80047A8Cu;
    // 80047A8C: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80047A90:
    ctx->pc = 0x80047A90u;
    ctx->downcount -= 2;
    // 80047A90: cmpw    r27, r29
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80047A94:
    ctx->pc = 0x80047A94u;
    // 80047A94: bc    12, 2, 0x80047AA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047AA8;
        }
    }

label_80047A98:
    ctx->pc = 0x80047A98u;
    ctx->downcount -= 4;
    // 80047A98: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80047A9C:
    ctx->pc = 0x80047A9Cu;
    // 80047A9C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80047AA0:
    ctx->pc = 0x80047AA0u;
    // 80047AA0: subf   r5, r4, r27
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_80047AA4:
    ctx->pc = 0x80047AA4u;
    // 80047AA4: bl      0x80297E3C
    {
            ctx->lr = 0x80047AA8u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80047AA8:
    ctx->pc = 0x80047AA8u;
    ctx->downcount -= 6;
    // 80047AA8: lwz     r3, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80047AAC:
    ctx->pc = 0x80047AACu;
    // 80047AAC: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047AB0:
    ctx->pc = 0x80047AB0u;
    // 80047AB0: cmpwi   r3, 0
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

label_80047AB4:
    ctx->pc = 0x80047AB4u;
    // 80047AB4: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047AB8:
    ctx->pc = 0x80047AB8u;
    // 80047AB8: srawi r0, r0, 2
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

label_80047ABC:
    ctx->pc = 0x80047ABCu;
    // 80047ABC: bc    12, 2, 0x80047B18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047B18;
        }
    }

label_80047AC0:
    ctx->pc = 0x80047AC0u;
    ctx->downcount -= 3;
    // 80047AC0: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80047AC4:
    ctx->pc = 0x80047AC4u;
    // 80047AC4: cmplwi  r4, 0x0080
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

label_80047AC8:
    ctx->pc = 0x80047AC8u;
    // 80047AC8: bc    4, 1, 0x80047AD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047AD4;
        }
    }

label_80047ACC:
    ctx->pc = 0x80047ACCu;
    ctx->downcount -= 1;
    // 80047ACC: bl      0x80281D80
    {
            ctx->lr = 0x80047AD0u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80047AD0:
    ctx->pc = 0x80047AD0u;
    ctx->downcount -= 1;
    // 80047AD0: b       0x80047B18
    {
            goto label_80047B18;
    }

label_80047AD4:
    ctx->pc = 0x80047AD4u;
    ctx->downcount -= 1;
    // 80047AD4: bl      0x8001D934
    {
            ctx->lr = 0x80047AD8u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80047AD8:
    ctx->pc = 0x80047AD8u;
    ctx->downcount -= 1;
    // 80047AD8: b       0x80047B18
    {
            goto label_80047B18;
    }

label_80047ADC:
    ctx->pc = 0x80047ADCu;
    ctx->downcount -= 2;
    // 80047ADC: cmpwi   r4, 0
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

label_80047AE0:
    ctx->pc = 0x80047AE0u;
    // 80047AE0: bc    12, 2, 0x80047B0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047B0C;
        }
    }

label_80047AE4:
    ctx->pc = 0x80047AE4u;
    ctx->downcount -= 4;
    // 80047AE4: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_80047AE8:
    ctx->pc = 0x80047AE8u;
    // 80047AE8: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80047AEC:
    ctx->pc = 0x80047AECu;
    // 80047AEC: cmplwi  r0, 0x0080
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

label_80047AF0:
    ctx->pc = 0x80047AF0u;
    // 80047AF0: bc    4, 1, 0x80047B00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047B00;
        }
    }

label_80047AF4:
    ctx->pc = 0x80047AF4u;
    ctx->downcount -= 2;
    // 80047AF4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80047AF8:
    ctx->pc = 0x80047AF8u;
    // 80047AF8: bl      0x80281C60
    {
            ctx->lr = 0x80047AFCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80047AFC:
    ctx->pc = 0x80047AFCu;
    ctx->downcount -= 1;
    // 80047AFC: b       0x80047B14
    {
            goto label_80047B14;
    }

label_80047B00:
    ctx->pc = 0x80047B00u;
    ctx->downcount -= 2;
    // 80047B00: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80047B04:
    ctx->pc = 0x80047B04u;
    // 80047B04: bl      0x80004024
    {
            ctx->lr = 0x80047B08u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80047B08:
    ctx->pc = 0x80047B08u;
    ctx->downcount -= 1;
    // 80047B08: b       0x80047B14
    {
            goto label_80047B14;
    }

label_80047B0C:
    ctx->pc = 0x80047B0Cu;
    ctx->downcount -= 2;
    // 80047B0C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80047B10:
    ctx->pc = 0x80047B10u;
    // 80047B10: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80047B14:
    ctx->pc = 0x80047B14u;
    ctx->downcount -= 1;
    // 80047B14: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047B18:
    ctx->pc = 0x80047B18u;
    ctx->downcount -= 6;
    // 80047B18: rlwinm r0, r26, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[26], 2u) & 0xFFFFFFFCu;
    }

label_80047B1C:
    ctx->pc = 0x80047B1Cu;
    // 80047B1C: add   r9, r30, r31
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80047B20:
    ctx->pc = 0x80047B20u;
    // 80047B20: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80047B24:
    ctx->pc = 0x80047B24u;
    // 80047B24: stw     r9, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047B28:
    ctx->pc = 0x80047B28u;
    // 80047B28: stw     r31, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047B2C:
    ctx->pc = 0x80047B2Cu;
    // 80047B2C: stw     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047B30:
    ctx->pc = 0x80047B30u;
    ctx->downcount -= 16;
    // 80047B30: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047B34:
    ctx->pc = 0x80047B34u;
    // 80047B34: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80047B38:
    ctx->pc = 0x80047B38u;
    // 80047B38: lmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80047B3C:
    ctx->pc = 0x80047B3Cu;
    // 80047B3C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80047B40:
    ctx->pc = 0x80047B40u;
    // 80047B40: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80047B44:
    ctx->pc = 0x80047B44u;
    ctx->downcount -= 20;
    // 80047B44: stwu     r1, -96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-96);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80047B48:
    ctx->pc = 0x80047B48u;
    // 80047B48: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80047B4C:
    ctx->pc = 0x80047B4Cu;
    // 80047B4C: stmw     r19, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 19; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80047B50:
    ctx->pc = 0x80047B50u;
    // 80047B50: stw     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047B54:
    ctx->pc = 0x80047B54u;
    // 80047B54: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047B58:
    ctx->pc = 0x80047B58u;
    // 80047B58: or   r20, r4, r4
    {
        ctx->gpr[20] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80047B5C:
    ctx->pc = 0x80047B5Cu;
    // 80047B5C: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80047B60:
    ctx->pc = 0x80047B60u;
    // 80047B60: lwz     r31, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80047B64:
    ctx->pc = 0x80047B64u;
    // 80047B64: cmpwi   r31, 0
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

label_80047B68:
    ctx->pc = 0x80047B68u;
    // 80047B68: bc    4, 2, 0x80047B84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047B84;
        }
    }

label_80047B6C:
    ctx->pc = 0x80047B6Cu;
    ctx->downcount -= 2;
    // 80047B6C: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80047B70:
    ctx->pc = 0x80047B70u;
    // 80047B70: bl      0x80281C60
    {
            ctx->lr = 0x80047B74u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80047B74:
    ctx->pc = 0x80047B74u;
    ctx->downcount -= 4;
    // 80047B74: stw     r31, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047B78:
    ctx->pc = 0x80047B78u;
    // 80047B78: stw     r3, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80047B7C:
    ctx->pc = 0x80047B7Cu;
    // 80047B7C: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047B80:
    ctx->pc = 0x80047B80u;
    // 80047B80: stw     r31, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047B84:
    ctx->pc = 0x80047B84u;
    ctx->downcount -= 3;
    // 80047B84: lwz     r31, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80047B88:
    ctx->pc = 0x80047B88u;
    // 80047B88: cmpwi   r31, 0
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

label_80047B8C:
    ctx->pc = 0x80047B8Cu;
    // 80047B8C: bc    4, 2, 0x80047BA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047BA8;
        }
    }

label_80047B90:
    ctx->pc = 0x80047B90u;
    ctx->downcount -= 2;
    // 80047B90: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80047B94:
    ctx->pc = 0x80047B94u;
    // 80047B94: bl      0x80281C60
    {
            ctx->lr = 0x80047B98u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80047B98:
    ctx->pc = 0x80047B98u;
    ctx->downcount -= 4;
    // 80047B98: stw     r31, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047B9C:
    ctx->pc = 0x80047B9Cu;
    // 80047B9C: stw     r3, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80047BA0:
    ctx->pc = 0x80047BA0u;
    // 80047BA0: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047BA4:
    ctx->pc = 0x80047BA4u;
    // 80047BA4: stw     r31, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047BA8:
    ctx->pc = 0x80047BA8u;
    ctx->downcount -= 10;
    // 80047BA8: lwz     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047BAC:
    ctx->pc = 0x80047BACu;
    // 80047BAC: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_80047BB0:
    ctx->pc = 0x80047BB0u;
    // 80047BB0: stw     r30, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80047BB4:
    ctx->pc = 0x80047BB4u;
    // 80047BB4: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80047BB8:
    ctx->pc = 0x80047BB8u;
    // 80047BB8: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047BBC:
    ctx->pc = 0x80047BBCu;
    // 80047BBC: lwz     r4, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80047BC0:
    ctx->pc = 0x80047BC0u;
    // 80047BC0: subf   r4, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_80047BC4:
    ctx->pc = 0x80047BC4u;
    // 80047BC4: srawi r4, r4, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[4];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80047BC8:
    ctx->pc = 0x80047BC8u;
    // 80047BC8: add   r4, r4, r20
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[20];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80047BCC:
    ctx->pc = 0x80047BCCu;
    // 80047BCC: bl      0x8001C19C
    {
            ctx->lr = 0x80047BD0u;
            ctx->pc = 0x8001C19Cu;
            return;
    }

label_80047BD0:
    ctx->pc = 0x80047BD0u;
    ctx->downcount -= 8;
    // 80047BD0: lwz     r9, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047BD4:
    ctx->pc = 0x80047BD4u;
    // 80047BD4: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047BD8:
    ctx->pc = 0x80047BD8u;
    // 80047BD8: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80047BDC:
    ctx->pc = 0x80047BDCu;
    // 80047BDC: lwz     r4, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80047BE0:
    ctx->pc = 0x80047BE0u;
    // 80047BE0: subf   r4, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_80047BE4:
    ctx->pc = 0x80047BE4u;
    // 80047BE4: srawi r4, r4, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[4];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80047BE8:
    ctx->pc = 0x80047BE8u;
    // 80047BE8: add   r4, r4, r20
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[20];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80047BEC:
    ctx->pc = 0x80047BECu;
    // 80047BEC: bl      0x8000435C
    {
            ctx->lr = 0x80047BF0u;
            ctx->pc = 0x8000435Cu;
            return;
    }

label_80047BF0:
    ctx->pc = 0x80047BF0u;
    ctx->downcount -= 7;
    // 80047BF0: lwz     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047BF4:
    ctx->pc = 0x80047BF4u;
    // 80047BF4: cmplw   r27, r20
    {
        u32 val_a = (u32)(ctx->gpr[27]);
        u32 val_b = (u32)(ctx->gpr[20]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80047BF8:
    ctx->pc = 0x80047BF8u;
    // 80047BF8: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80047BFC:
    ctx->pc = 0x80047BFCu;
    // 80047BFC: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047C00:
    ctx->pc = 0x80047C00u;
    // 80047C00: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047C04:
    ctx->pc = 0x80047C04u;
    // 80047C04: srawi r21, r0, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[21] = value;
        } else if (sh > 31) {
            ctx->gpr[21] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[21] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80047C08:
    ctx->pc = 0x80047C08u;
    // 80047C08: bc    4, 0, 0x80047EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047EBC;
        }
    }

label_80047C0C:
    ctx->pc = 0x80047C0Cu;
    ctx->downcount -= 2;
    // 80047C0C: li      r22, 1
    ctx->gpr[22] = (u32)(s32)(1);

label_80047C10:
    ctx->pc = 0x80047C10u;
    // 80047C10: li      r19, -1
    ctx->gpr[19] = (u32)(s32)(-1);

label_80047C14:
    ctx->downcount -= 5;
    // 80047C14: lis     r4, -32722
    ctx->gpr[4] = ((u32)(s32)(-32722) << 16);

label_80047C18:
    // 80047C18: li      r3, 80
    ctx->gpr[3] = (u32)(s32)(80);

label_80047C1C:
    // 80047C1C: addi    r4, r4, 8336
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(8336);

label_80047C20:
    // 80047C20: li      r5, 68
    ctx->gpr[5] = (u32)(s32)(68);

label_80047C24:
    // 80047C24: bl      0x80281B50
    {
            ctx->lr = 0x80047C28u;
            ctx->pc = 0x80281B50u;
            return;
    }

label_80047C28:
    ctx->downcount -= 3;
    // 80047C28: or.   r9, r3, r3
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

label_80047C2C:
    ctx->pc = 0x80047C2Cu;
    // 80047C2C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80047C30:
    // 80047C30: bc    4, 2, 0x80047C3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047C3C;
        }
    }

label_80047C34:
    ctx->downcount -= 2;
    // 80047C34: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80047C38:
    // 80047C38: b       0x80047EC0
    {
            goto label_80047EC0;
    }

label_80047C3C:
    ctx->pc = 0x80047C3Cu;
    ctx->downcount -= 7;
    // 80047C3C: stw     r19, 76(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[19]);
    }

label_80047C40:
    // 80047C40: addi    r26, r1, 16
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(16);

label_80047C44:
    ctx->pc = 0x80047C44u;
    // 80047C44: lwz     r31, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80047C48:
    ctx->pc = 0x80047C48u;
    // 80047C48: lwz     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80047C4C:
    ctx->pc = 0x80047C4Cu;
    // 80047C4C: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047C50:
    // 80047C50: cmpw    r30, r0
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

label_80047C54:
    // 80047C54: bc    12, 2, 0x80047C80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047C80;
        }
    }

label_80047C58:
    ctx->downcount -= 2;
    // 80047C58: cmpwi   r30, 0
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

label_80047C5C:
    // 80047C5C: bc    12, 2, 0x80047C64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047C64;
        }
    }

label_80047C60:
    ctx->pc = 0x80047C60u;
    ctx->downcount -= 1;
    // 80047C60: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047C64:
    ctx->pc = 0x80047C64u;
    ctx->downcount -= 7;
    // 80047C64: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047C68:
    // 80047C68: addi    r23, r27, 1
    ctx->gpr[23] = ctx->gpr[27] + (u32)(s32)(1);

label_80047C6C:
    // 80047C6C: add   r27, r21, r27
    {
        u32 a = ctx->gpr[21];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[27] = res;
    }

label_80047C70:
    // 80047C70: addi    r24, r1, 28
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(28);

label_80047C74:
    // 80047C74: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80047C78:
    ctx->pc = 0x80047C78u;
    // 80047C78: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047C7C:
    // 80047C7C: b       0x80047D84
    {
            goto label_80047D84;
    }

label_80047C80:
    ctx->pc = 0x80047C80u;
    ctx->downcount -= 9;
    // 80047C80: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047C84:
    // 80047C84: addi    r11, r1, 24
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(24);

label_80047C88:
    ctx->pc = 0x80047C88u;
    // 80047C88: stw     r22, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[22]);
    }

label_80047C8C:
    // 80047C8C: addi    r10, r1, 20
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(20);

label_80047C90:
    // 80047C90: subf   r0, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047C94:
    // 80047C94: srawi r9, r0, 2
    {
        u32 sh = 2u;
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
    }

label_80047C98:
    ctx->pc = 0x80047C98u;
    // 80047C98: stw     r9, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047C9C:
    // 80047C9C: cmplw   r9, r22
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(ctx->gpr[22]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80047CA0:
    // 80047CA0: bc    4, 0, 0x80047CA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047CA8;
        }
    }

label_80047CA4:
    ctx->downcount -= 1;
    // 80047CA4: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80047CA8:
    ctx->pc = 0x80047CA8u;
    ctx->downcount -= 3;
    // 80047CA8: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047CAC:
    // 80047CAC: add.   r0, r9, r0
    {
        u32 a = ctx->gpr[9];
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

label_80047CB0:
    // 80047CB0: bc    12, 2, 0x80047CE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047CE4;
        }
    }

label_80047CB4:
    ctx->downcount -= 4;
    // 80047CB4: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80047CB8:
    // 80047CB8: or   r28, r0, r0
    {
        ctx->gpr[28] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80047CBC:
    // 80047CBC: cmplwi  r0, 0x0080
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

label_80047CC0:
    // 80047CC0: bc    4, 1, 0x80047CD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047CD4;
        }
    }

label_80047CC4:
    ctx->downcount -= 2;
    // 80047CC4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80047CC8:
    // 80047CC8: bl      0x80281C60
    {
            ctx->lr = 0x80047CCCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80047CCC:
    ctx->downcount -= 2;
    // 80047CCC: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047CD0:
    // 80047CD0: b       0x80047CEC
    {
            goto label_80047CEC;
    }

label_80047CD4:
    ctx->downcount -= 2;
    // 80047CD4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80047CD8:
    // 80047CD8: bl      0x80004024
    {
            ctx->lr = 0x80047CDCu;
            ctx->pc = 0x80004024u;
            return;
    }

label_80047CDC:
    ctx->downcount -= 2;
    // 80047CDC: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047CE0:
    // 80047CE0: b       0x80047CEC
    {
            goto label_80047CEC;
    }

label_80047CE4:
    ctx->downcount -= 2;
    // 80047CE4: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80047CE8:
    // 80047CE8: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80047CEC:
    ctx->pc = 0x80047CECu;
    ctx->downcount -= 3;
    // 80047CEC: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80047CF0:
    // 80047CF0: cmpw    r30, r4
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

label_80047CF4:
    // 80047CF4: bc    12, 2, 0x80047D10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047D10;
        }
    }

label_80047CF8:
    ctx->downcount -= 4;
    // 80047CF8: subf   r30, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_80047CFC:
    // 80047CFC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80047D00:
    // 80047D00: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80047D04:
    // 80047D04: bl      0x80297E3C
    {
            ctx->lr = 0x80047D08u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80047D08:
    ctx->downcount -= 2;
    // 80047D08: add   r0, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80047D0C:
    // 80047D0C: b       0x80047D14
    {
            goto label_80047D14;
    }

label_80047D10:
    ctx->downcount -= 1;
    // 80047D10: or   r0, r29, r29
    {
        ctx->gpr[0] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80047D14:
    ctx->pc = 0x80047D14u;
    ctx->downcount -= 9;
    // 80047D14: lwz     r9, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047D18:
    // 80047D18: addi    r23, r27, 1
    ctx->gpr[23] = ctx->gpr[27] + (u32)(s32)(1);

label_80047D1C:
    // 80047D1C: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80047D20:
    // 80047D20: add   r27, r21, r27
    {
        u32 a = ctx->gpr[21];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[27] = res;
    }

label_80047D24:
    ctx->pc = 0x80047D24u;
    // 80047D24: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_80047D28:
    // 80047D28: addi    r24, r1, 28
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(28);

label_80047D2C:
    // 80047D2C: cmpwi   r9, 0
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

label_80047D30:
    // 80047D30: bc    12, 2, 0x80047D44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047D44;
        }
    }

label_80047D34:
    loop_80047D34(ctx);
    if (ctx->pc == 0x80047D44u) goto label_80047D44;
    return;
label_80047D38:
    ctx->pc = 0x80047D38u;
    // 80047D38: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047D3C:
    // 80047D3C: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_80047D40:
    // 80047D40: bc    16, 0, 0x80047D34
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80047D34u;
                return;
            }
            goto label_80047D34;
        }
    }

label_80047D44:
    ctx->pc = 0x80047D44u;
    ctx->downcount -= 6;
    // 80047D44: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80047D48:
    ctx->pc = 0x80047D48u;
    // 80047D48: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047D4C:
    // 80047D4C: cmpwi   r3, 0
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

label_80047D50:
    // 80047D50: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047D54:
    // 80047D54: srawi r0, r0, 2
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

label_80047D58:
    // 80047D58: bc    12, 2, 0x80047D74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047D74;
        }
    }

label_80047D5C:
    ctx->downcount -= 3;
    // 80047D5C: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80047D60:
    // 80047D60: cmplwi  r4, 0x0080
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

label_80047D64:
    // 80047D64: bc    4, 1, 0x80047D70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047D70;
        }
    }

label_80047D68:
    ctx->downcount -= 1;
    // 80047D68: bl      0x80281D80
    {
            ctx->lr = 0x80047D6Cu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80047D6C:
    ctx->downcount -= 1;
    // 80047D6C: b       0x80047D74
    {
            goto label_80047D74;
    }

label_80047D70:
    ctx->downcount -= 1;
    // 80047D70: bl      0x8001D934
    {
            ctx->lr = 0x80047D74u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80047D74:
    ctx->downcount -= 4;
    // 80047D74: add   r0, r28, r29
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80047D78:
    ctx->pc = 0x80047D78u;
    // 80047D78: stw     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80047D7C:
    ctx->pc = 0x80047D7Cu;
    // 80047D7C: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047D80:
    ctx->pc = 0x80047D80u;
    // 80047D80: stw     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80047D84:
    ctx->pc = 0x80047D84u;
    ctx->downcount -= 6;
    // 80047D84: lwz     r31, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80047D88:
    ctx->pc = 0x80047D88u;
    // 80047D88: stw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_80047D8C:
    ctx->pc = 0x80047D8Cu;
    // 80047D8C: lwz     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80047D90:
    ctx->pc = 0x80047D90u;
    // 80047D90: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047D94:
    // 80047D94: cmpw    r30, r0
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

label_80047D98:
    // 80047D98: bc    12, 2, 0x80047DB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047DB8;
        }
    }

label_80047D9C:
    ctx->downcount -= 2;
    // 80047D9C: cmpwi   r30, 0
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

label_80047DA0:
    // 80047DA0: bc    12, 2, 0x80047DA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047DA8;
        }
    }

label_80047DA4:
    ctx->pc = 0x80047DA4u;
    ctx->downcount -= 1;
    // 80047DA4: stw     r27, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_80047DA8:
    ctx->pc = 0x80047DA8u;
    ctx->downcount -= 4;
    // 80047DA8: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047DAC:
    // 80047DAC: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80047DB0:
    ctx->pc = 0x80047DB0u;
    // 80047DB0: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047DB4:
    // 80047DB4: b       0x80047EB0
    {
            goto label_80047EB0;
    }

label_80047DB8:
    ctx->pc = 0x80047DB8u;
    ctx->downcount -= 9;
    // 80047DB8: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047DBC:
    // 80047DBC: addi    r11, r1, 36
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(36);

label_80047DC0:
    ctx->pc = 0x80047DC0u;
    // 80047DC0: stw     r22, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[22]);
    }

label_80047DC4:
    // 80047DC4: addi    r10, r1, 32
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(32);

label_80047DC8:
    // 80047DC8: subf   r0, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047DCC:
    // 80047DCC: srawi r9, r0, 2
    {
        u32 sh = 2u;
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
    }

label_80047DD0:
    ctx->pc = 0x80047DD0u;
    // 80047DD0: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047DD4:
    // 80047DD4: cmplw   r9, r22
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(ctx->gpr[22]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80047DD8:
    // 80047DD8: bc    4, 0, 0x80047DE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047DE0;
        }
    }

label_80047DDC:
    ctx->downcount -= 1;
    // 80047DDC: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80047DE0:
    ctx->pc = 0x80047DE0u;
    ctx->downcount -= 3;
    // 80047DE0: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047DE4:
    // 80047DE4: add.   r0, r9, r0
    {
        u32 a = ctx->gpr[9];
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

label_80047DE8:
    // 80047DE8: bc    12, 2, 0x80047E1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047E1C;
        }
    }

label_80047DEC:
    ctx->downcount -= 4;
    // 80047DEC: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80047DF0:
    // 80047DF0: or   r28, r0, r0
    {
        ctx->gpr[28] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80047DF4:
    // 80047DF4: cmplwi  r0, 0x0080
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

label_80047DF8:
    // 80047DF8: bc    4, 1, 0x80047E0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047E0C;
        }
    }

label_80047DFC:
    ctx->downcount -= 2;
    // 80047DFC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80047E00:
    // 80047E00: bl      0x80281C60
    {
            ctx->lr = 0x80047E04u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80047E04:
    ctx->downcount -= 2;
    // 80047E04: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047E08:
    // 80047E08: b       0x80047E24
    {
            goto label_80047E24;
    }

label_80047E0C:
    ctx->downcount -= 2;
    // 80047E0C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80047E10:
    // 80047E10: bl      0x80004024
    {
            ctx->lr = 0x80047E14u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80047E14:
    ctx->downcount -= 2;
    // 80047E14: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047E18:
    // 80047E18: b       0x80047E24
    {
            goto label_80047E24;
    }

label_80047E1C:
    ctx->downcount -= 2;
    // 80047E1C: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80047E20:
    // 80047E20: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80047E24:
    ctx->pc = 0x80047E24u;
    ctx->downcount -= 3;
    // 80047E24: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80047E28:
    // 80047E28: cmpw    r30, r4
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

label_80047E2C:
    // 80047E2C: bc    12, 2, 0x80047E48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047E48;
        }
    }

label_80047E30:
    ctx->downcount -= 4;
    // 80047E30: subf   r30, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_80047E34:
    // 80047E34: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80047E38:
    // 80047E38: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80047E3C:
    // 80047E3C: bl      0x80297E3C
    {
            ctx->lr = 0x80047E40u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80047E40:
    ctx->downcount -= 2;
    // 80047E40: add   r0, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80047E44:
    // 80047E44: b       0x80047E4C
    {
            goto label_80047E4C;
    }

label_80047E48:
    ctx->downcount -= 1;
    // 80047E48: or   r0, r29, r29
    {
        ctx->gpr[0] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80047E4C:
    ctx->pc = 0x80047E4Cu;
    ctx->downcount -= 6;
    // 80047E4C: lwz     r9, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047E50:
    // 80047E50: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80047E54:
    ctx->pc = 0x80047E54u;
    // 80047E54: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_80047E58:
    // 80047E58: cmpwi   r9, 0
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

label_80047E5C:
    // 80047E5C: bc    12, 2, 0x80047E70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047E70;
        }
    }

label_80047E60:
    loop_80047E60(ctx);
    if (ctx->pc == 0x80047E70u) goto label_80047E70;
    return;
label_80047E64:
    ctx->pc = 0x80047E64u;
    // 80047E64: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047E68:
    // 80047E68: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_80047E6C:
    // 80047E6C: bc    16, 0, 0x80047E60
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80047E60u;
                return;
            }
            goto label_80047E60;
        }
    }

label_80047E70:
    ctx->pc = 0x80047E70u;
    ctx->downcount -= 6;
    // 80047E70: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80047E74:
    ctx->pc = 0x80047E74u;
    // 80047E74: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047E78:
    // 80047E78: cmpwi   r3, 0
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

label_80047E7C:
    // 80047E7C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047E80:
    // 80047E80: srawi r0, r0, 2
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

label_80047E84:
    // 80047E84: bc    12, 2, 0x80047EA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80047EA0;
        }
    }

label_80047E88:
    ctx->downcount -= 3;
    // 80047E88: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80047E8C:
    // 80047E8C: cmplwi  r4, 0x0080
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

label_80047E90:
    // 80047E90: bc    4, 1, 0x80047E9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047E9C;
        }
    }

label_80047E94:
    ctx->downcount -= 1;
    // 80047E94: bl      0x80281D80
    {
            ctx->lr = 0x80047E98u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80047E98:
    ctx->downcount -= 1;
    // 80047E98: b       0x80047EA0
    {
            goto label_80047EA0;
    }

label_80047E9C:
    ctx->downcount -= 1;
    // 80047E9C: bl      0x8001D934
    {
            ctx->lr = 0x80047EA0u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80047EA0:
    ctx->downcount -= 4;
    // 80047EA0: add   r0, r28, r29
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80047EA4:
    ctx->pc = 0x80047EA4u;
    // 80047EA4: stw     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80047EA8:
    ctx->pc = 0x80047EA8u;
    // 80047EA8: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047EAC:
    ctx->pc = 0x80047EACu;
    // 80047EAC: stw     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80047EB0:
    ctx->downcount -= 3;
    // 80047EB0: or   r27, r23, r23
    {
        ctx->gpr[27] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80047EB4:
    // 80047EB4: cmplw   r27, r20
    {
        u32 val_a = (u32)(ctx->gpr[27]);
        u32 val_b = (u32)(ctx->gpr[20]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80047EB8:
    // 80047EB8: bc    12, 0, 0x80047C14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80047C14u;
                return;
            }
            goto label_80047C14;
        }
    }

label_80047EBC:
    ctx->pc = 0x80047EBCu;
    ctx->downcount -= 1;
    // 80047EBC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80047EC0:
    ctx->pc = 0x80047EC0u;
    ctx->downcount -= 16;
    // 80047EC0: lwz     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047EC4:
    ctx->pc = 0x80047EC4u;
    // 80047EC4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80047EC8:
    ctx->pc = 0x80047EC8u;
    // 80047EC8: lmw     r19, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 19; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80047ECC:
    ctx->pc = 0x80047ECCu;
    // 80047ECC: addi    r1, r1, 96
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(96);

label_80047ED0:
    ctx->pc = 0x80047ED0u;
    // 80047ED0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80047ED4:
    ctx->pc = 0x80047ED4u;
    ctx->downcount -= 18;
    // 80047ED4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80047ED8:
    ctx->pc = 0x80047ED8u;
    // 80047ED8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80047EDC:
    ctx->pc = 0x80047EDCu;
    // 80047EDC: stmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80047EE0:
    ctx->pc = 0x80047EE0u;
    // 80047EE0: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047EE4:
    ctx->pc = 0x80047EE4u;
    // 80047EE4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80047EE8:
    ctx->pc = 0x80047EE8u;
    // 80047EE8: lwz     r31, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80047EEC:
    ctx->pc = 0x80047EECu;
    // 80047EEC: cmpwi   r31, 0
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

label_80047EF0:
    ctx->pc = 0x80047EF0u;
    // 80047EF0: bc    4, 2, 0x80047F0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047F0C;
        }
    }

label_80047EF4:
    ctx->pc = 0x80047EF4u;
    ctx->downcount -= 2;
    // 80047EF4: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80047EF8:
    ctx->pc = 0x80047EF8u;
    // 80047EF8: bl      0x80281C60
    {
            ctx->lr = 0x80047EFCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80047EFC:
    ctx->pc = 0x80047EFCu;
    ctx->downcount -= 4;
    // 80047EFC: stw     r31, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047F00:
    ctx->pc = 0x80047F00u;
    // 80047F00: stw     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80047F04:
    ctx->pc = 0x80047F04u;
    // 80047F04: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047F08:
    ctx->pc = 0x80047F08u;
    // 80047F08: stw     r31, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047F0C:
    ctx->pc = 0x80047F0Cu;
    ctx->downcount -= 3;
    // 80047F0C: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80047F10:
    ctx->pc = 0x80047F10u;
    // 80047F10: cmpwi   r31, 0
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

label_80047F14:
    ctx->pc = 0x80047F14u;
    // 80047F14: bc    4, 2, 0x80047F30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047F30;
        }
    }

label_80047F18:
    ctx->pc = 0x80047F18u;
    ctx->downcount -= 2;
    // 80047F18: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80047F1C:
    ctx->pc = 0x80047F1Cu;
    // 80047F1C: bl      0x80281C60
    {
            ctx->lr = 0x80047F20u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80047F20:
    ctx->pc = 0x80047F20u;
    ctx->downcount -= 4;
    // 80047F20: stw     r31, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047F24:
    ctx->pc = 0x80047F24u;
    // 80047F24: stw     r3, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80047F28:
    ctx->pc = 0x80047F28u;
    // 80047F28: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047F2C:
    ctx->pc = 0x80047F2Cu;
    // 80047F2C: stw     r31, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80047F30:
    ctx->pc = 0x80047F30u;
    ctx->downcount -= 6;
    // 80047F30: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047F34:
    ctx->pc = 0x80047F34u;
    // 80047F34: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80047F38:
    ctx->pc = 0x80047F38u;
    // 80047F38: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047F3C:
    ctx->pc = 0x80047F3Cu;
    // 80047F3C: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80047F40:
    ctx->pc = 0x80047F40u;
    // 80047F40: rlwinm. r9, r0, 30, 2, 31
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

label_80047F44:
    ctx->pc = 0x80047F44u;
    // 80047F44: bc    4, 2, 0x80047F88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047F88;
        }
    }

label_80047F48:
    ctx->pc = 0x80047F48u;
    ctx->downcount -= 3;
    // 80047F48: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047F4C:
    ctx->pc = 0x80047F4Cu;
    // 80047F4C: cmpwi   r0, 0
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

label_80047F50:
    ctx->pc = 0x80047F50u;
    // 80047F50: bc    4, 2, 0x80047F80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047F80;
        }
    }

label_80047F54:
    ctx->pc = 0x80047F54u;
    ctx->downcount -= 9;
    // 80047F54: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047F58:
    ctx->pc = 0x80047F58u;
    // 80047F58: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80047F5C:
    ctx->pc = 0x80047F5Cu;
    // 80047F5C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80047F60:
    ctx->pc = 0x80047F60u;
    // 80047F60: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047F64:
    ctx->pc = 0x80047F64u;
    // 80047F64: lwz     r4, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80047F68:
    ctx->pc = 0x80047F68u;
    // 80047F68: subf   r4, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_80047F6C:
    ctx->pc = 0x80047F6Cu;
    // 80047F6C: srawi r4, r4, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[4];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80047F70:
    ctx->pc = 0x80047F70u;
    // 80047F70: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_80047F74:
    ctx->pc = 0x80047F74u;
    // 80047F74: bl      0x8001C2D0
    {
            ctx->lr = 0x80047F78u;
            ctx->pc = 0x8001C2D0u;
            return;
    }

label_80047F78:
    ctx->pc = 0x80047F78u;
    ctx->downcount -= 2;
    // 80047F78: cmpwi   r3, 0
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

label_80047F7C:
    ctx->pc = 0x80047F7Cu;
    // 80047F7C: bc    4, 2, 0x80047F88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80047F88;
        }
    }

label_80047F80:
    ctx->pc = 0x80047F80u;
    ctx->downcount -= 2;
    // 80047F80: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80047F84:
    ctx->pc = 0x80047F84u;
    // 80047F84: b       0x80047FAC
    {
            goto label_80047FAC;
    }

label_80047F88:
    ctx->pc = 0x80047F88u;
    ctx->downcount -= 9;
    // 80047F88: lwz     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80047F8C:
    ctx->pc = 0x80047F8Cu;
    // 80047F8C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047F90:
    ctx->pc = 0x80047F90u;
    // 80047F90: lwzu     r0, -4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_80047F94:
    ctx->pc = 0x80047F94u;
    // 80047F94: stw     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047F98:
    ctx->pc = 0x80047F98u;
    // 80047F98: rlwinm r10, r0, 2, 0, 29
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80047F9C:
    ctx->pc = 0x80047F9Cu;
    // 80047F9C: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047FA0:
    ctx->pc = 0x80047FA0u;
    // 80047FA0: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80047FA4:
    ctx->pc = 0x80047FA4u;
    // 80047FA4: lwzx    r3, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80047FA8:
    ctx->pc = 0x80047FA8u;
    // 80047FA8: stw     r0, 76(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047FAC:
    ctx->pc = 0x80047FACu;
    ctx->downcount -= 16;
    // 80047FAC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047FB0:
    ctx->pc = 0x80047FB0u;
    // 80047FB0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80047FB4:
    ctx->pc = 0x80047FB4u;
    // 80047FB4: lmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80047FB8:
    ctx->pc = 0x80047FB8u;
    // 80047FB8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80047FBC:
    ctx->pc = 0x80047FBCu;
    // 80047FBC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80047FC0:
    ctx->pc = 0x80047FC0u;
    ctx->downcount -= 23;
    // 80047FC0: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80047FC4:
    ctx->pc = 0x80047FC4u;
    // 80047FC4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80047FC8:
    ctx->pc = 0x80047FC8u;
    // 80047FC8: stmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80047FCC:
    ctx->pc = 0x80047FCCu;
    // 80047FCC: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80047FD0:
    ctx->pc = 0x80047FD0u;
    // 80047FD0: lwz     r31, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80047FD4:
    ctx->pc = 0x80047FD4u;
    // 80047FD4: or   r27, r4, r4
    {
        ctx->gpr[27] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80047FD8:
    ctx->pc = 0x80047FD8u;
    // 80047FD8: lwz     r9, 76(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(76);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80047FDC:
    ctx->pc = 0x80047FDCu;
    // 80047FDC: addi    r26, r1, 8
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(8);

label_80047FE0:
    ctx->pc = 0x80047FE0u;
    // 80047FE0: lwz     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80047FE4:
    ctx->pc = 0x80047FE4u;
    // 80047FE4: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80047FE8:
    ctx->pc = 0x80047FE8u;
    // 80047FE8: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80047FEC:
    ctx->pc = 0x80047FECu;
    // 80047FEC: cmpw    r30, r0
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

label_80047FF0:
    ctx->pc = 0x80047FF0u;
    // 80047FF0: bc    12, 2, 0x80048010
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048010;
        }
    }

label_80047FF4:
    ctx->pc = 0x80047FF4u;
    ctx->downcount -= 2;
    // 80047FF4: cmpwi   r30, 0
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

label_80047FF8:
    ctx->pc = 0x80047FF8u;
    // 80047FF8: bc    12, 2, 0x80048000
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048000;
        }
    }

label_80047FFC:
    ctx->pc = 0x80047FFCu;
    ctx->downcount -= 1;
    // 80047FFC: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80048000:
    ctx->pc = 0x80048000u;
    ctx->downcount -= 4;
    // 80048000: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048004:
    ctx->pc = 0x80048004u;
    // 80048004: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80048008:
    ctx->pc = 0x80048008u;
    // 80048008: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004800C:
    ctx->pc = 0x8004800Cu;
    // 8004800C: b       0x8004810C
    {
            goto label_8004810C;
    }

label_80048010:
    ctx->pc = 0x80048010u;
    ctx->downcount -= 10;
    // 80048010: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048014:
    ctx->pc = 0x80048014u;
    // 80048014: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_80048018:
    ctx->pc = 0x80048018u;
    // 80048018: stw     r9, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004801C:
    ctx->pc = 0x8004801Cu;
    // 8004801C: addi    r10, r1, 16
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(16);

label_80048020:
    ctx->pc = 0x80048020u;
    // 80048020: subf   r0, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048024:
    ctx->pc = 0x80048024u;
    // 80048024: addi    r11, r1, 12
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(12);

label_80048028:
    ctx->pc = 0x80048028u;
    // 80048028: srawi r9, r0, 2
    {
        u32 sh = 2u;
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
    }

label_8004802C:
    ctx->pc = 0x8004802Cu;
    // 8004802C: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80048030:
    ctx->pc = 0x80048030u;
    // 80048030: cmplwi  r9, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80048034:
    ctx->pc = 0x80048034u;
    // 80048034: bc    4, 0, 0x8004803C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004803C;
        }
    }

label_80048038:
    ctx->pc = 0x80048038u;
    ctx->downcount -= 1;
    // 80048038: or   r11, r10, r10
    {
        ctx->gpr[11] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8004803C:
    ctx->pc = 0x8004803Cu;
    ctx->downcount -= 3;
    // 8004803C: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048040:
    ctx->pc = 0x80048040u;
    // 80048040: add.   r0, r9, r0
    {
        u32 a = ctx->gpr[9];
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

label_80048044:
    ctx->pc = 0x80048044u;
    // 80048044: bc    12, 2, 0x80048078
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048078;
        }
    }

label_80048048:
    ctx->pc = 0x80048048u;
    ctx->downcount -= 4;
    // 80048048: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8004804C:
    ctx->pc = 0x8004804Cu;
    // 8004804C: or   r28, r0, r0
    {
        ctx->gpr[28] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80048050:
    ctx->pc = 0x80048050u;
    // 80048050: cmplwi  r0, 0x0080
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

label_80048054:
    ctx->pc = 0x80048054u;
    // 80048054: bc    4, 1, 0x80048068
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048068;
        }
    }

label_80048058:
    ctx->pc = 0x80048058u;
    ctx->downcount -= 2;
    // 80048058: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8004805C:
    ctx->pc = 0x8004805Cu;
    // 8004805C: bl      0x80281C60
    {
            ctx->lr = 0x80048060u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80048060:
    ctx->pc = 0x80048060u;
    ctx->downcount -= 2;
    // 80048060: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048064:
    ctx->pc = 0x80048064u;
    // 80048064: b       0x80048080
    {
            goto label_80048080;
    }

label_80048068:
    ctx->pc = 0x80048068u;
    ctx->downcount -= 2;
    // 80048068: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8004806C:
    ctx->pc = 0x8004806Cu;
    // 8004806C: bl      0x80004024
    {
            ctx->lr = 0x80048070u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80048070:
    ctx->pc = 0x80048070u;
    ctx->downcount -= 2;
    // 80048070: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048074:
    ctx->pc = 0x80048074u;
    // 80048074: b       0x80048080
    {
            goto label_80048080;
    }

label_80048078:
    ctx->pc = 0x80048078u;
    ctx->downcount -= 2;
    // 80048078: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8004807C:
    ctx->pc = 0x8004807Cu;
    // 8004807C: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80048080:
    ctx->pc = 0x80048080u;
    ctx->downcount -= 3;
    // 80048080: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80048084:
    ctx->pc = 0x80048084u;
    // 80048084: cmpw    r30, r4
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

label_80048088:
    ctx->pc = 0x80048088u;
    // 80048088: bc    12, 2, 0x800480A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800480A4;
        }
    }

label_8004808C:
    ctx->pc = 0x8004808Cu;
    ctx->downcount -= 4;
    // 8004808C: subf   r30, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_80048090:
    ctx->pc = 0x80048090u;
    // 80048090: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80048094:
    ctx->pc = 0x80048094u;
    // 80048094: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80048098:
    ctx->pc = 0x80048098u;
    // 80048098: bl      0x80297E3C
    {
            ctx->lr = 0x8004809Cu;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8004809C:
    ctx->pc = 0x8004809Cu;
    ctx->downcount -= 2;
    // 8004809C: add   r0, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800480A0:
    ctx->pc = 0x800480A0u;
    // 800480A0: b       0x800480A8
    {
            goto label_800480A8;
    }

label_800480A4:
    ctx->pc = 0x800480A4u;
    ctx->downcount -= 1;
    // 800480A4: or   r0, r29, r29
    {
        ctx->gpr[0] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800480A8:
    ctx->pc = 0x800480A8u;
    ctx->downcount -= 6;
    // 800480A8: lwz     r9, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800480AC:
    ctx->pc = 0x800480ACu;
    // 800480AC: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_800480B0:
    ctx->pc = 0x800480B0u;
    // 800480B0: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_800480B4:
    ctx->pc = 0x800480B4u;
    // 800480B4: cmpwi   r9, 0
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

label_800480B8:
    ctx->pc = 0x800480B8u;
    // 800480B8: bc    12, 2, 0x800480CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800480CC;
        }
    }

label_800480BC:
    loop_800480BC(ctx);
    if (ctx->pc == 0x800480CCu) goto label_800480CC;
    return;
label_800480C0:
    ctx->pc = 0x800480C0u;
    // 800480C0: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800480C4:
    // 800480C4: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_800480C8:
    // 800480C8: bc    16, 0, 0x800480BC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800480BCu;
                return;
            }
            goto label_800480BC;
        }
    }

label_800480CC:
    ctx->pc = 0x800480CCu;
    ctx->downcount -= 6;
    // 800480CC: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800480D0:
    ctx->pc = 0x800480D0u;
    // 800480D0: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800480D4:
    ctx->pc = 0x800480D4u;
    // 800480D4: cmpwi   r3, 0
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

label_800480D8:
    ctx->pc = 0x800480D8u;
    // 800480D8: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800480DC:
    ctx->pc = 0x800480DCu;
    // 800480DC: srawi r0, r0, 2
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

label_800480E0:
    ctx->pc = 0x800480E0u;
    // 800480E0: bc    12, 2, 0x800480FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800480FC;
        }
    }

label_800480E4:
    ctx->pc = 0x800480E4u;
    ctx->downcount -= 3;
    // 800480E4: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_800480E8:
    ctx->pc = 0x800480E8u;
    // 800480E8: cmplwi  r4, 0x0080
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

label_800480EC:
    ctx->pc = 0x800480ECu;
    // 800480EC: bc    4, 1, 0x800480F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800480F8;
        }
    }

label_800480F0:
    ctx->pc = 0x800480F0u;
    ctx->downcount -= 1;
    // 800480F0: bl      0x80281D80
    {
            ctx->lr = 0x800480F4u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800480F4:
    ctx->pc = 0x800480F4u;
    ctx->downcount -= 1;
    // 800480F4: b       0x800480FC
    {
            goto label_800480FC;
    }

label_800480F8:
    ctx->pc = 0x800480F8u;
    ctx->downcount -= 1;
    // 800480F8: bl      0x8001D934
    {
            ctx->lr = 0x800480FCu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_800480FC:
    ctx->pc = 0x800480FCu;
    ctx->downcount -= 4;
    // 800480FC: add   r0, r28, r29
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80048100:
    ctx->pc = 0x80048100u;
    // 80048100: stw     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80048104:
    ctx->pc = 0x80048104u;
    // 80048104: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048108:
    ctx->pc = 0x80048108u;
    // 80048108: stw     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8004810C:
    ctx->pc = 0x8004810Cu;
    ctx->downcount -= 8;
    // 8004810C: lwz     r9, 32(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048110:
    ctx->pc = 0x80048110u;
    // 80048110: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80048114:
    ctx->pc = 0x80048114u;
    // 80048114: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048118:
    ctx->pc = 0x80048118u;
    // 80048118: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004811C:
    ctx->pc = 0x8004811Cu;
    // 8004811C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80048120:
    ctx->pc = 0x80048120u;
    // 80048120: add   r3, r27, r3
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80048124:
    ctx->pc = 0x80048124u;
    // 80048124: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80048128u;
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80048128:
    ctx->pc = 0x80048128u;
    ctx->downcount -= 18;
    // 80048128: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8004812C:
    ctx->pc = 0x8004812Cu;
    // 8004812C: stw     r0, 76(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048130:
    ctx->pc = 0x80048130u;
    // 80048130: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048134:
    ctx->pc = 0x80048134u;
    // 80048134: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80048138:
    ctx->pc = 0x80048138u;
    // 80048138: lmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004813C:
    ctx->pc = 0x8004813Cu;
    // 8004813C: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_80048140:
    ctx->pc = 0x80048140u;
    // 80048140: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80048144:
    ctx->pc = 0x80048144u;
    ctx->downcount -= 18;
    // 80048144: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80048148:
    ctx->pc = 0x80048148u;
    // 80048148: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004814C:
    ctx->pc = 0x8004814Cu;
    // 8004814C: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80048150:
    ctx->pc = 0x80048150u;
    // 80048150: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048154:
    ctx->pc = 0x80048154u;
    // 80048154: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048158:
    ctx->pc = 0x80048158u;
    // 80048158: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004815C:
    ctx->pc = 0x8004815Cu;
    // 8004815C: cmpwi   r11, 0
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

label_80048160:
    ctx->pc = 0x80048160u;
    // 80048160: bc    12, 2, 0x80048244
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048244;
        }
    }

label_80048164:
    ctx->pc = 0x80048164u;
    ctx->downcount -= 6;
    // 80048164: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048168:
    ctx->pc = 0x80048168u;
    // 80048168: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8004816C:
    ctx->pc = 0x8004816Cu;
    // 8004816C: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048170:
    ctx->pc = 0x80048170u;
    // 80048170: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048174:
    ctx->pc = 0x80048174u;
    // 80048174: rlwinm. r9, r0, 30, 2, 31
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

label_80048178:
    ctx->pc = 0x80048178u;
    // 80048178: bc    12, 2, 0x800481F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800481F8;
        }
    }

label_8004817C:
    ctx->pc = 0x8004817Cu;
    ctx->downcount -= 2;
    // 8004817C: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80048180:
    ctx->pc = 0x80048180u;
    // 80048180: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80048184:
    ctx->pc = 0x80048184u;
    ctx->downcount -= 6;
    // 80048184: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048188:
    ctx->pc = 0x80048188u;
    // 80048188: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004818C:
    ctx->pc = 0x8004818Cu;
    // 8004818C: lwzx    r11, r11, r29
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[29];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80048190:
    ctx->pc = 0x80048190u;
    // 80048190: lwz     r0, 76(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048194:
    // 80048194: cmpwi   r0, -1
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

label_80048198:
    // 80048198: bc    12, 2, 0x800481C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800481C0;
        }
    }

label_8004819C:
    ctx->downcount -= 2;
    // 8004819C: cmpwi   r11, 0
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

label_800481A0:
    // 800481A0: bc    12, 2, 0x800481C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800481C0;
        }
    }

label_800481A4:
    ctx->pc = 0x800481A4u;
    ctx->downcount -= 8;
    // 800481A4: lwz     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800481A8:
    // 800481A8: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_800481AC:
    ctx->pc = 0x800481ACu;
    // 800481AC: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800481B0:
    ctx->pc = 0x800481B0u;
    // 800481B0: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800481B4:
    // 800481B4: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800481B8:
    ctx->pc = 0x800481B8u;
    // 800481B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800481BC:
    ctx->pc = 0x800481BCu;
    // 800481BC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800481C0u;
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800481C0:
    ctx->pc = 0x800481C0u;
    ctx->downcount -= 7;
    // 800481C0: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800481C4:
    // 800481C4: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_800481C8:
    // 800481C8: addi    r29, r29, 4
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(4);

label_800481CC:
    ctx->pc = 0x800481CCu;
    // 800481CC: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800481D0:
    ctx->pc = 0x800481D0u;
    // 800481D0: lwzx    r3, r9, r28
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[28];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800481D4:
    // 800481D4: addi    r28, r28, 4
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(4);

label_800481D8:
    // 800481D8: bl      0x80281B70
    {
            ctx->lr = 0x800481DCu;
            ctx->pc = 0x80281B70u;
            return;
    }

label_800481DC:
    ctx->pc = 0x800481DCu;
    ctx->downcount -= 7;
    // 800481DC: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800481E0:
    ctx->pc = 0x800481E0u;
    // 800481E0: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800481E4:
    ctx->pc = 0x800481E4u;
    // 800481E4: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800481E8:
    // 800481E8: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800481EC:
    // 800481EC: srawi r0, r0, 2
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

label_800481F0:
    // 800481F0: cmplw   r31, r0
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

label_800481F4:
    // 800481F4: bc    12, 0, 0x80048184
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048184u;
                return;
            }
            goto label_80048184;
        }
    }

label_800481F8:
    ctx->pc = 0x800481F8u;
    ctx->downcount -= 6;
    // 800481F8: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800481FC:
    ctx->pc = 0x800481FCu;
    // 800481FC: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048200:
    ctx->pc = 0x80048200u;
    // 80048200: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048204:
    ctx->pc = 0x80048204u;
    // 80048204: lwz     r31, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80048208:
    ctx->pc = 0x80048208u;
    // 80048208: cmpwi   r31, 0
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

label_8004820C:
    ctx->pc = 0x8004820Cu;
    // 8004820C: bc    12, 2, 0x80048244
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048244;
        }
    }

label_80048210:
    ctx->pc = 0x80048210u;
    ctx->downcount -= 3;
    // 80048210: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80048214:
    ctx->pc = 0x80048214u;
    // 80048214: cmpwi   r3, 0
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

label_80048218:
    ctx->pc = 0x80048218u;
    // 80048218: bc    12, 2, 0x8004823C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004823C;
        }
    }

label_8004821C:
    ctx->pc = 0x8004821Cu;
    ctx->downcount -= 5;
    // 8004821C: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048220:
    ctx->pc = 0x80048220u;
    // 80048220: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048224:
    ctx->pc = 0x80048224u;
    // 80048224: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80048228:
    ctx->pc = 0x80048228u;
    // 80048228: cmplwi  r4, 0x0080
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

label_8004822C:
    ctx->pc = 0x8004822Cu;
    // 8004822C: bc    4, 1, 0x80048238
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048238;
        }
    }

label_80048230:
    ctx->pc = 0x80048230u;
    ctx->downcount -= 1;
    // 80048230: bl      0x80281D80
    {
            ctx->lr = 0x80048234u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80048234:
    ctx->pc = 0x80048234u;
    ctx->downcount -= 1;
    // 80048234: b       0x8004823C
    {
            goto label_8004823C;
    }

label_80048238:
    ctx->pc = 0x80048238u;
    ctx->downcount -= 1;
    // 80048238: bl      0x8001D934
    {
            ctx->lr = 0x8004823Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_8004823C:
    ctx->pc = 0x8004823Cu;
    ctx->downcount -= 2;
    // 8004823C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80048240:
    ctx->pc = 0x80048240u;
    // 80048240: bl      0x80281D80
    {
            ctx->lr = 0x80048244u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80048244:
    ctx->pc = 0x80048244u;
    ctx->downcount -= 5;
    // 80048244: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048248:
    ctx->pc = 0x80048248u;
    // 80048248: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004824C:
    ctx->pc = 0x8004824Cu;
    // 8004824C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048250:
    ctx->pc = 0x80048250u;
    // 80048250: cmpwi   r9, 0
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

label_80048254:
    ctx->pc = 0x80048254u;
    // 80048254: bc    12, 2, 0x800482A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800482A0;
        }
    }

label_80048258:
    ctx->pc = 0x80048258u;
    ctx->downcount -= 5;
    // 80048258: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004825C:
    ctx->pc = 0x8004825Cu;
    // 8004825C: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048260:
    ctx->pc = 0x80048260u;
    // 80048260: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80048264:
    ctx->pc = 0x80048264u;
    // 80048264: cmpwi   r31, 0
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

label_80048268:
    ctx->pc = 0x80048268u;
    // 80048268: bc    12, 2, 0x800482A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800482A0;
        }
    }

label_8004826C:
    ctx->pc = 0x8004826Cu;
    ctx->downcount -= 3;
    // 8004826C: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80048270:
    ctx->pc = 0x80048270u;
    // 80048270: cmpwi   r3, 0
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

label_80048274:
    ctx->pc = 0x80048274u;
    // 80048274: bc    12, 2, 0x80048298
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048298;
        }
    }

label_80048278:
    ctx->pc = 0x80048278u;
    ctx->downcount -= 5;
    // 80048278: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004827C:
    ctx->pc = 0x8004827Cu;
    // 8004827C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048280:
    ctx->pc = 0x80048280u;
    // 80048280: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80048284:
    ctx->pc = 0x80048284u;
    // 80048284: cmplwi  r4, 0x0080
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

label_80048288:
    ctx->pc = 0x80048288u;
    // 80048288: bc    4, 1, 0x80048294
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048294;
        }
    }

label_8004828C:
    ctx->pc = 0x8004828Cu;
    ctx->downcount -= 1;
    // 8004828C: bl      0x80281D80
    {
            ctx->lr = 0x80048290u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80048290:
    ctx->pc = 0x80048290u;
    ctx->downcount -= 1;
    // 80048290: b       0x80048298
    {
            goto label_80048298;
    }

label_80048294:
    ctx->pc = 0x80048294u;
    ctx->downcount -= 1;
    // 80048294: bl      0x8001D934
    {
            ctx->lr = 0x80048298u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80048298:
    ctx->pc = 0x80048298u;
    ctx->downcount -= 2;
    // 80048298: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8004829C:
    ctx->pc = 0x8004829Cu;
    // 8004829C: bl      0x80281D80
    {
            ctx->lr = 0x800482A0u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800482A0:
    ctx->pc = 0x800482A0u;
    ctx->downcount -= 19;
    // 800482A0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800482A4:
    ctx->pc = 0x800482A4u;
    // 800482A4: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800482A8:
    ctx->pc = 0x800482A8u;
    // 800482A8: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800482AC:
    ctx->pc = 0x800482ACu;
    // 800482AC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800482B0:
    ctx->pc = 0x800482B0u;
    // 800482B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800482B4:
    ctx->pc = 0x800482B4u;
    // 800482B4: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800482B8:
    ctx->pc = 0x800482B8u;
    // 800482B8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800482BC:
    ctx->pc = 0x800482BCu;
    // 800482BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800482C0:
    ctx->pc = 0x800482C0u;
    ctx->downcount -= 21;
    // 800482C0: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800482C4:
    ctx->pc = 0x800482C4u;
    // 800482C4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800482C8:
    ctx->pc = 0x800482C8u;
    // 800482C8: stmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800482CC:
    ctx->pc = 0x800482CCu;
    // 800482CC: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800482D0:
    ctx->pc = 0x800482D0u;
    // 800482D0: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800482D4:
    ctx->pc = 0x800482D4u;
    // 800482D4: lwz     r29, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_800482D8:
    ctx->pc = 0x800482D8u;
    // 800482D8: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800482DC:
    ctx->pc = 0x800482DCu;
    // 800482DC: subf   r0, r29, r0
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800482E0:
    ctx->pc = 0x800482E0u;
    // 800482E0: srawi r0, r0, 2
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

label_800482E4:
    ctx->pc = 0x800482E4u;
    // 800482E4: cmplw   r0, r4
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800482E8:
    ctx->pc = 0x800482E8u;
    // 800482E8: bc    4, 0, 0x800483E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800483E0;
        }
    }

label_800482EC:
    ctx->pc = 0x800482ECu;
    ctx->downcount -= 5;
    // 800482EC: lwz     r27, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[27] = mem_read32(ctx, ea);
    }

label_800482F0:
    ctx->pc = 0x800482F0u;
    // 800482F0: cmpwi   r29, 0
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

label_800482F4:
    ctx->pc = 0x800482F4u;
    // 800482F4: subf   r0, r29, r27
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800482F8:
    ctx->pc = 0x800482F8u;
    // 800482F8: srawi r26, r0, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[26] = value;
        } else if (sh > 31) {
            ctx->gpr[26] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[26] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_800482FC:
    ctx->pc = 0x800482FCu;
    // 800482FC: bc    12, 2, 0x8004838C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004838C;
        }
    }

label_80048300:
    ctx->pc = 0x80048300u;
    ctx->downcount -= 2;
    // 80048300: cmpwi   r4, 0
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

label_80048304:
    ctx->pc = 0x80048304u;
    // 80048304: bc    12, 2, 0x80048338
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048338;
        }
    }

label_80048308:
    ctx->pc = 0x80048308u;
    ctx->downcount -= 4;
    // 80048308: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_8004830C:
    ctx->pc = 0x8004830Cu;
    // 8004830C: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80048310:
    ctx->pc = 0x80048310u;
    // 80048310: cmplwi  r0, 0x0080
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

label_80048314:
    ctx->pc = 0x80048314u;
    // 80048314: bc    4, 1, 0x80048328
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048328;
        }
    }

label_80048318:
    ctx->pc = 0x80048318u;
    ctx->downcount -= 2;
    // 80048318: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8004831C:
    ctx->pc = 0x8004831Cu;
    // 8004831C: bl      0x80281C60
    {
            ctx->lr = 0x80048320u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80048320:
    ctx->pc = 0x80048320u;
    ctx->downcount -= 2;
    // 80048320: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048324:
    ctx->pc = 0x80048324u;
    // 80048324: b       0x80048340
    {
            goto label_80048340;
    }

label_80048328:
    ctx->pc = 0x80048328u;
    ctx->downcount -= 2;
    // 80048328: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8004832C:
    ctx->pc = 0x8004832Cu;
    // 8004832C: bl      0x80004024
    {
            ctx->lr = 0x80048330u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80048330:
    ctx->pc = 0x80048330u;
    ctx->downcount -= 2;
    // 80048330: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048334:
    ctx->pc = 0x80048334u;
    // 80048334: b       0x80048340
    {
            goto label_80048340;
    }

label_80048338:
    ctx->pc = 0x80048338u;
    ctx->downcount -= 2;
    // 80048338: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8004833C:
    ctx->pc = 0x8004833Cu;
    // 8004833C: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80048340:
    ctx->pc = 0x80048340u;
    ctx->downcount -= 2;
    // 80048340: cmpw    r27, r29
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80048344:
    ctx->pc = 0x80048344u;
    // 80048344: bc    12, 2, 0x80048358
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048358;
        }
    }

label_80048348:
    ctx->pc = 0x80048348u;
    ctx->downcount -= 4;
    // 80048348: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8004834C:
    ctx->pc = 0x8004834Cu;
    // 8004834C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80048350:
    ctx->pc = 0x80048350u;
    // 80048350: subf   r5, r4, r27
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_80048354:
    ctx->pc = 0x80048354u;
    // 80048354: bl      0x80297E3C
    {
            ctx->lr = 0x80048358u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80048358:
    ctx->pc = 0x80048358u;
    ctx->downcount -= 6;
    // 80048358: lwz     r3, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004835C:
    ctx->pc = 0x8004835Cu;
    // 8004835C: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048360:
    ctx->pc = 0x80048360u;
    // 80048360: cmpwi   r3, 0
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

label_80048364:
    ctx->pc = 0x80048364u;
    // 80048364: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048368:
    ctx->pc = 0x80048368u;
    // 80048368: srawi r0, r0, 2
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

label_8004836C:
    ctx->pc = 0x8004836Cu;
    // 8004836C: bc    12, 2, 0x800483C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800483C8;
        }
    }

label_80048370:
    ctx->pc = 0x80048370u;
    ctx->downcount -= 3;
    // 80048370: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80048374:
    ctx->pc = 0x80048374u;
    // 80048374: cmplwi  r4, 0x0080
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

label_80048378:
    ctx->pc = 0x80048378u;
    // 80048378: bc    4, 1, 0x80048384
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048384;
        }
    }

label_8004837C:
    ctx->pc = 0x8004837Cu;
    ctx->downcount -= 1;
    // 8004837C: bl      0x80281D80
    {
            ctx->lr = 0x80048380u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80048380:
    ctx->pc = 0x80048380u;
    ctx->downcount -= 1;
    // 80048380: b       0x800483C8
    {
            goto label_800483C8;
    }

label_80048384:
    ctx->pc = 0x80048384u;
    ctx->downcount -= 1;
    // 80048384: bl      0x8001D934
    {
            ctx->lr = 0x80048388u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80048388:
    ctx->pc = 0x80048388u;
    ctx->downcount -= 1;
    // 80048388: b       0x800483C8
    {
            goto label_800483C8;
    }

label_8004838C:
    ctx->pc = 0x8004838Cu;
    ctx->downcount -= 2;
    // 8004838C: cmpwi   r4, 0
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

label_80048390:
    ctx->pc = 0x80048390u;
    // 80048390: bc    12, 2, 0x800483BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800483BC;
        }
    }

label_80048394:
    ctx->pc = 0x80048394u;
    ctx->downcount -= 4;
    // 80048394: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_80048398:
    ctx->pc = 0x80048398u;
    // 80048398: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8004839C:
    ctx->pc = 0x8004839Cu;
    // 8004839C: cmplwi  r0, 0x0080
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

label_800483A0:
    ctx->pc = 0x800483A0u;
    // 800483A0: bc    4, 1, 0x800483B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800483B0;
        }
    }

label_800483A4:
    ctx->pc = 0x800483A4u;
    ctx->downcount -= 2;
    // 800483A4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800483A8:
    ctx->pc = 0x800483A8u;
    // 800483A8: bl      0x80281C60
    {
            ctx->lr = 0x800483ACu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800483AC:
    ctx->pc = 0x800483ACu;
    ctx->downcount -= 1;
    // 800483AC: b       0x800483C4
    {
            goto label_800483C4;
    }

label_800483B0:
    ctx->pc = 0x800483B0u;
    ctx->downcount -= 2;
    // 800483B0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800483B4:
    ctx->pc = 0x800483B4u;
    // 800483B4: bl      0x80004024
    {
            ctx->lr = 0x800483B8u;
            ctx->pc = 0x80004024u;
            return;
    }

label_800483B8:
    ctx->pc = 0x800483B8u;
    ctx->downcount -= 1;
    // 800483B8: b       0x800483C4
    {
            goto label_800483C4;
    }

label_800483BC:
    ctx->pc = 0x800483BCu;
    ctx->downcount -= 2;
    // 800483BC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800483C0:
    ctx->pc = 0x800483C0u;
    // 800483C0: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_800483C4:
    ctx->pc = 0x800483C4u;
    ctx->downcount -= 1;
    // 800483C4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800483C8:
    ctx->pc = 0x800483C8u;
    ctx->downcount -= 6;
    // 800483C8: rlwinm r0, r26, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[26], 2u) & 0xFFFFFFFCu;
    }

label_800483CC:
    ctx->pc = 0x800483CCu;
    // 800483CC: add   r9, r30, r31
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800483D0:
    ctx->pc = 0x800483D0u;
    // 800483D0: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800483D4:
    ctx->pc = 0x800483D4u;
    // 800483D4: stw     r9, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800483D8:
    ctx->pc = 0x800483D8u;
    // 800483D8: stw     r31, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800483DC:
    ctx->pc = 0x800483DCu;
    // 800483DC: stw     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800483E0:
    ctx->pc = 0x800483E0u;
    ctx->downcount -= 16;
    // 800483E0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800483E4:
    ctx->pc = 0x800483E4u;
    // 800483E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800483E8:
    ctx->pc = 0x800483E8u;
    // 800483E8: lmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800483EC:
    ctx->pc = 0x800483ECu;
    // 800483EC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_800483F0:
    ctx->pc = 0x800483F0u;
    // 800483F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800483F4:
    ctx->pc = 0x800483F4u;
    ctx->downcount -= 20;
    // 800483F4: stwu     r1, -96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-96);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800483F8:
    ctx->pc = 0x800483F8u;
    // 800483F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800483FC:
    ctx->pc = 0x800483FCu;
    // 800483FC: stmw     r19, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 19; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80048400:
    ctx->pc = 0x80048400u;
    // 80048400: stw     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048404:
    ctx->pc = 0x80048404u;
    // 80048404: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048408:
    ctx->pc = 0x80048408u;
    // 80048408: or   r20, r4, r4
    {
        ctx->gpr[20] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004840C:
    ctx->pc = 0x8004840Cu;
    // 8004840C: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80048410:
    ctx->pc = 0x80048410u;
    // 80048410: lwz     r31, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80048414:
    ctx->pc = 0x80048414u;
    // 80048414: cmpwi   r31, 0
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

label_80048418:
    ctx->pc = 0x80048418u;
    // 80048418: bc    4, 2, 0x80048434
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048434;
        }
    }

label_8004841C:
    ctx->pc = 0x8004841Cu;
    ctx->downcount -= 2;
    // 8004841C: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80048420:
    ctx->pc = 0x80048420u;
    // 80048420: bl      0x80281C60
    {
            ctx->lr = 0x80048424u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80048424:
    ctx->pc = 0x80048424u;
    ctx->downcount -= 4;
    // 80048424: stw     r31, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80048428:
    ctx->pc = 0x80048428u;
    // 80048428: stw     r3, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004842C:
    ctx->pc = 0x8004842Cu;
    // 8004842C: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80048430:
    ctx->pc = 0x80048430u;
    // 80048430: stw     r31, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80048434:
    ctx->pc = 0x80048434u;
    ctx->downcount -= 3;
    // 80048434: lwz     r31, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80048438:
    ctx->pc = 0x80048438u;
    // 80048438: cmpwi   r31, 0
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

label_8004843C:
    ctx->pc = 0x8004843Cu;
    // 8004843C: bc    4, 2, 0x80048458
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048458;
        }
    }

label_80048440:
    ctx->pc = 0x80048440u;
    ctx->downcount -= 2;
    // 80048440: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80048444:
    ctx->pc = 0x80048444u;
    // 80048444: bl      0x80281C60
    {
            ctx->lr = 0x80048448u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80048448:
    ctx->pc = 0x80048448u;
    ctx->downcount -= 4;
    // 80048448: stw     r31, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004844C:
    ctx->pc = 0x8004844Cu;
    // 8004844C: stw     r3, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80048450:
    ctx->pc = 0x80048450u;
    // 80048450: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80048454:
    ctx->pc = 0x80048454u;
    // 80048454: stw     r31, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80048458:
    ctx->pc = 0x80048458u;
    ctx->downcount -= 10;
    // 80048458: lwz     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004845C:
    ctx->pc = 0x8004845Cu;
    // 8004845C: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_80048460:
    ctx->pc = 0x80048460u;
    // 80048460: stw     r30, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80048464:
    ctx->pc = 0x80048464u;
    // 80048464: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80048468:
    ctx->pc = 0x80048468u;
    // 80048468: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004846C:
    ctx->pc = 0x8004846Cu;
    // 8004846C: lwz     r4, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80048470:
    ctx->pc = 0x80048470u;
    // 80048470: subf   r4, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_80048474:
    ctx->pc = 0x80048474u;
    // 80048474: srawi r4, r4, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[4];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80048478:
    ctx->pc = 0x80048478u;
    // 80048478: add   r4, r4, r20
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[20];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8004847C:
    ctx->pc = 0x8004847Cu;
    // 8004847C: bl      0x8001CA4C
    {
            ctx->lr = 0x80048480u;
            ctx->pc = 0x8001CA4Cu;
            return;
    }

label_80048480:
    ctx->pc = 0x80048480u;
    ctx->downcount -= 8;
    // 80048480: lwz     r9, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048484:
    ctx->pc = 0x80048484u;
    // 80048484: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048488:
    ctx->pc = 0x80048488u;
    // 80048488: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8004848C:
    ctx->pc = 0x8004848Cu;
    // 8004848C: lwz     r4, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80048490:
    ctx->pc = 0x80048490u;
    // 80048490: subf   r4, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_80048494:
    ctx->pc = 0x80048494u;
    // 80048494: srawi r4, r4, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[4];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80048498:
    ctx->pc = 0x80048498u;
    // 80048498: add   r4, r4, r20
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[20];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8004849C:
    ctx->pc = 0x8004849Cu;
    // 8004849C: bl      0x8000435C
    {
            ctx->lr = 0x800484A0u;
            ctx->pc = 0x8000435Cu;
            return;
    }

label_800484A0:
    ctx->pc = 0x800484A0u;
    ctx->downcount -= 7;
    // 800484A0: lwz     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800484A4:
    ctx->pc = 0x800484A4u;
    // 800484A4: cmplw   r27, r20
    {
        u32 val_a = (u32)(ctx->gpr[27]);
        u32 val_b = (u32)(ctx->gpr[20]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800484A8:
    ctx->pc = 0x800484A8u;
    // 800484A8: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800484AC:
    ctx->pc = 0x800484ACu;
    // 800484AC: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800484B0:
    ctx->pc = 0x800484B0u;
    // 800484B0: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800484B4:
    ctx->pc = 0x800484B4u;
    // 800484B4: srawi r21, r0, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[21] = value;
        } else if (sh > 31) {
            ctx->gpr[21] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[21] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_800484B8:
    ctx->pc = 0x800484B8u;
    // 800484B8: bc    4, 0, 0x8004876C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004876C;
        }
    }

label_800484BC:
    ctx->pc = 0x800484BCu;
    ctx->downcount -= 2;
    // 800484BC: li      r22, 1
    ctx->gpr[22] = (u32)(s32)(1);

label_800484C0:
    ctx->pc = 0x800484C0u;
    // 800484C0: li      r19, -1
    ctx->gpr[19] = (u32)(s32)(-1);

label_800484C4:
    ctx->downcount -= 5;
    // 800484C4: lis     r4, -32722
    ctx->gpr[4] = ((u32)(s32)(-32722) << 16);

label_800484C8:
    // 800484C8: li      r3, 80
    ctx->gpr[3] = (u32)(s32)(80);

label_800484CC:
    // 800484CC: addi    r4, r4, 8336
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(8336);

label_800484D0:
    // 800484D0: li      r5, 68
    ctx->gpr[5] = (u32)(s32)(68);

label_800484D4:
    // 800484D4: bl      0x80281B50
    {
            ctx->lr = 0x800484D8u;
            ctx->pc = 0x80281B50u;
            return;
    }

label_800484D8:
    ctx->downcount -= 3;
    // 800484D8: or.   r9, r3, r3
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

label_800484DC:
    ctx->pc = 0x800484DCu;
    // 800484DC: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800484E0:
    // 800484E0: bc    4, 2, 0x800484EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800484EC;
        }
    }

label_800484E4:
    ctx->downcount -= 2;
    // 800484E4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800484E8:
    // 800484E8: b       0x80048770
    {
            goto label_80048770;
    }

label_800484EC:
    ctx->pc = 0x800484ECu;
    ctx->downcount -= 7;
    // 800484EC: stw     r19, 76(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[19]);
    }

label_800484F0:
    // 800484F0: addi    r26, r1, 16
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(16);

label_800484F4:
    ctx->pc = 0x800484F4u;
    // 800484F4: lwz     r31, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800484F8:
    ctx->pc = 0x800484F8u;
    // 800484F8: lwz     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800484FC:
    ctx->pc = 0x800484FCu;
    // 800484FC: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048500:
    // 80048500: cmpw    r30, r0
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

label_80048504:
    // 80048504: bc    12, 2, 0x80048530
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048530;
        }
    }

label_80048508:
    ctx->downcount -= 2;
    // 80048508: cmpwi   r30, 0
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

label_8004850C:
    // 8004850C: bc    12, 2, 0x80048514
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048514;
        }
    }

label_80048510:
    ctx->pc = 0x80048510u;
    ctx->downcount -= 1;
    // 80048510: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80048514:
    ctx->pc = 0x80048514u;
    ctx->downcount -= 7;
    // 80048514: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048518:
    // 80048518: addi    r23, r27, 1
    ctx->gpr[23] = ctx->gpr[27] + (u32)(s32)(1);

label_8004851C:
    // 8004851C: add   r27, r21, r27
    {
        u32 a = ctx->gpr[21];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[27] = res;
    }

label_80048520:
    // 80048520: addi    r24, r1, 28
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(28);

label_80048524:
    // 80048524: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80048528:
    ctx->pc = 0x80048528u;
    // 80048528: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004852C:
    // 8004852C: b       0x80048634
    {
            goto label_80048634;
    }

label_80048530:
    ctx->pc = 0x80048530u;
    ctx->downcount -= 9;
    // 80048530: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048534:
    // 80048534: addi    r11, r1, 24
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(24);

label_80048538:
    ctx->pc = 0x80048538u;
    // 80048538: stw     r22, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[22]);
    }

label_8004853C:
    // 8004853C: addi    r10, r1, 20
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(20);

label_80048540:
    // 80048540: subf   r0, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048544:
    // 80048544: srawi r9, r0, 2
    {
        u32 sh = 2u;
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
    }

label_80048548:
    ctx->pc = 0x80048548u;
    // 80048548: stw     r9, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004854C:
    // 8004854C: cmplw   r9, r22
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(ctx->gpr[22]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80048550:
    // 80048550: bc    4, 0, 0x80048558
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048558;
        }
    }

label_80048554:
    ctx->downcount -= 1;
    // 80048554: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80048558:
    ctx->pc = 0x80048558u;
    ctx->downcount -= 3;
    // 80048558: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004855C:
    // 8004855C: add.   r0, r9, r0
    {
        u32 a = ctx->gpr[9];
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

label_80048560:
    // 80048560: bc    12, 2, 0x80048594
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048594;
        }
    }

label_80048564:
    ctx->downcount -= 4;
    // 80048564: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80048568:
    // 80048568: or   r28, r0, r0
    {
        ctx->gpr[28] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8004856C:
    // 8004856C: cmplwi  r0, 0x0080
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

label_80048570:
    // 80048570: bc    4, 1, 0x80048584
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048584;
        }
    }

label_80048574:
    ctx->downcount -= 2;
    // 80048574: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80048578:
    // 80048578: bl      0x80281C60
    {
            ctx->lr = 0x8004857Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8004857C:
    ctx->downcount -= 2;
    // 8004857C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048580:
    // 80048580: b       0x8004859C
    {
            goto label_8004859C;
    }

label_80048584:
    ctx->downcount -= 2;
    // 80048584: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80048588:
    // 80048588: bl      0x80004024
    {
            ctx->lr = 0x8004858Cu;
            ctx->pc = 0x80004024u;
            return;
    }

label_8004858C:
    ctx->downcount -= 2;
    // 8004858C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048590:
    // 80048590: b       0x8004859C
    {
            goto label_8004859C;
    }

label_80048594:
    ctx->downcount -= 2;
    // 80048594: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80048598:
    // 80048598: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_8004859C:
    ctx->pc = 0x8004859Cu;
    ctx->downcount -= 3;
    // 8004859C: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800485A0:
    // 800485A0: cmpw    r30, r4
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

label_800485A4:
    // 800485A4: bc    12, 2, 0x800485C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800485C0;
        }
    }

label_800485A8:
    ctx->downcount -= 4;
    // 800485A8: subf   r30, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_800485AC:
    // 800485AC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800485B0:
    // 800485B0: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800485B4:
    // 800485B4: bl      0x80297E3C
    {
            ctx->lr = 0x800485B8u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_800485B8:
    ctx->downcount -= 2;
    // 800485B8: add   r0, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800485BC:
    // 800485BC: b       0x800485C4
    {
            goto label_800485C4;
    }

label_800485C0:
    ctx->downcount -= 1;
    // 800485C0: or   r0, r29, r29
    {
        ctx->gpr[0] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800485C4:
    ctx->pc = 0x800485C4u;
    ctx->downcount -= 9;
    // 800485C4: lwz     r9, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800485C8:
    // 800485C8: addi    r23, r27, 1
    ctx->gpr[23] = ctx->gpr[27] + (u32)(s32)(1);

label_800485CC:
    // 800485CC: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_800485D0:
    // 800485D0: add   r27, r21, r27
    {
        u32 a = ctx->gpr[21];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[27] = res;
    }

label_800485D4:
    ctx->pc = 0x800485D4u;
    // 800485D4: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_800485D8:
    // 800485D8: addi    r24, r1, 28
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(28);

label_800485DC:
    // 800485DC: cmpwi   r9, 0
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

label_800485E0:
    // 800485E0: bc    12, 2, 0x800485F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800485F4;
        }
    }

label_800485E4:
    loop_800485E4(ctx);
    if (ctx->pc == 0x800485F4u) goto label_800485F4;
    return;
label_800485E8:
    ctx->pc = 0x800485E8u;
    // 800485E8: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800485EC:
    // 800485EC: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_800485F0:
    // 800485F0: bc    16, 0, 0x800485E4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800485E4u;
                return;
            }
            goto label_800485E4;
        }
    }

label_800485F4:
    ctx->pc = 0x800485F4u;
    ctx->downcount -= 6;
    // 800485F4: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800485F8:
    ctx->pc = 0x800485F8u;
    // 800485F8: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800485FC:
    // 800485FC: cmpwi   r3, 0
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

label_80048600:
    // 80048600: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048604:
    // 80048604: srawi r0, r0, 2
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

label_80048608:
    // 80048608: bc    12, 2, 0x80048624
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048624;
        }
    }

label_8004860C:
    ctx->downcount -= 3;
    // 8004860C: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80048610:
    // 80048610: cmplwi  r4, 0x0080
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

label_80048614:
    // 80048614: bc    4, 1, 0x80048620
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048620;
        }
    }

label_80048618:
    ctx->downcount -= 1;
    // 80048618: bl      0x80281D80
    {
            ctx->lr = 0x8004861Cu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_8004861C:
    ctx->downcount -= 1;
    // 8004861C: b       0x80048624
    {
            goto label_80048624;
    }

label_80048620:
    ctx->downcount -= 1;
    // 80048620: bl      0x8001D934
    {
            ctx->lr = 0x80048624u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80048624:
    ctx->downcount -= 4;
    // 80048624: add   r0, r28, r29
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80048628:
    ctx->pc = 0x80048628u;
    // 80048628: stw     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8004862C:
    ctx->pc = 0x8004862Cu;
    // 8004862C: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048630:
    ctx->pc = 0x80048630u;
    // 80048630: stw     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80048634:
    ctx->pc = 0x80048634u;
    ctx->downcount -= 6;
    // 80048634: lwz     r31, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80048638:
    ctx->pc = 0x80048638u;
    // 80048638: stw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_8004863C:
    ctx->pc = 0x8004863Cu;
    // 8004863C: lwz     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80048640:
    ctx->pc = 0x80048640u;
    // 80048640: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048644:
    // 80048644: cmpw    r30, r0
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

label_80048648:
    // 80048648: bc    12, 2, 0x80048668
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048668;
        }
    }

label_8004864C:
    ctx->downcount -= 2;
    // 8004864C: cmpwi   r30, 0
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

label_80048650:
    // 80048650: bc    12, 2, 0x80048658
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048658;
        }
    }

label_80048654:
    ctx->pc = 0x80048654u;
    ctx->downcount -= 1;
    // 80048654: stw     r27, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_80048658:
    ctx->pc = 0x80048658u;
    ctx->downcount -= 4;
    // 80048658: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004865C:
    // 8004865C: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80048660:
    ctx->pc = 0x80048660u;
    // 80048660: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80048664:
    // 80048664: b       0x80048760
    {
            goto label_80048760;
    }

label_80048668:
    ctx->pc = 0x80048668u;
    ctx->downcount -= 9;
    // 80048668: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004866C:
    // 8004866C: addi    r11, r1, 36
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(36);

label_80048670:
    ctx->pc = 0x80048670u;
    // 80048670: stw     r22, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[22]);
    }

label_80048674:
    // 80048674: addi    r10, r1, 32
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(32);

label_80048678:
    // 80048678: subf   r0, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8004867C:
    // 8004867C: srawi r9, r0, 2
    {
        u32 sh = 2u;
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
    }

label_80048680:
    ctx->pc = 0x80048680u;
    // 80048680: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80048684:
    // 80048684: cmplw   r9, r22
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(ctx->gpr[22]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80048688:
    // 80048688: bc    4, 0, 0x80048690
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048690;
        }
    }

label_8004868C:
    ctx->downcount -= 1;
    // 8004868C: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80048690:
    ctx->pc = 0x80048690u;
    ctx->downcount -= 3;
    // 80048690: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048694:
    // 80048694: add.   r0, r9, r0
    {
        u32 a = ctx->gpr[9];
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

label_80048698:
    // 80048698: bc    12, 2, 0x800486CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800486CC;
        }
    }

label_8004869C:
    ctx->downcount -= 4;
    // 8004869C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_800486A0:
    // 800486A0: or   r28, r0, r0
    {
        ctx->gpr[28] = ctx->gpr[0] | ctx->gpr[0];
    }

label_800486A4:
    // 800486A4: cmplwi  r0, 0x0080
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

label_800486A8:
    // 800486A8: bc    4, 1, 0x800486BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800486BC;
        }
    }

label_800486AC:
    ctx->downcount -= 2;
    // 800486AC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800486B0:
    // 800486B0: bl      0x80281C60
    {
            ctx->lr = 0x800486B4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800486B4:
    ctx->downcount -= 2;
    // 800486B4: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800486B8:
    // 800486B8: b       0x800486D4
    {
            goto label_800486D4;
    }

label_800486BC:
    ctx->downcount -= 2;
    // 800486BC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800486C0:
    // 800486C0: bl      0x80004024
    {
            ctx->lr = 0x800486C4u;
            ctx->pc = 0x80004024u;
            return;
    }

label_800486C4:
    ctx->downcount -= 2;
    // 800486C4: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800486C8:
    // 800486C8: b       0x800486D4
    {
            goto label_800486D4;
    }

label_800486CC:
    ctx->downcount -= 2;
    // 800486CC: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_800486D0:
    // 800486D0: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_800486D4:
    ctx->pc = 0x800486D4u;
    ctx->downcount -= 3;
    // 800486D4: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800486D8:
    // 800486D8: cmpw    r30, r4
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

label_800486DC:
    // 800486DC: bc    12, 2, 0x800486F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800486F8;
        }
    }

label_800486E0:
    ctx->downcount -= 4;
    // 800486E0: subf   r30, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_800486E4:
    // 800486E4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800486E8:
    // 800486E8: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800486EC:
    // 800486EC: bl      0x80297E3C
    {
            ctx->lr = 0x800486F0u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_800486F0:
    ctx->downcount -= 2;
    // 800486F0: add   r0, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800486F4:
    // 800486F4: b       0x800486FC
    {
            goto label_800486FC;
    }

label_800486F8:
    ctx->downcount -= 1;
    // 800486F8: or   r0, r29, r29
    {
        ctx->gpr[0] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800486FC:
    ctx->pc = 0x800486FCu;
    ctx->downcount -= 6;
    // 800486FC: lwz     r9, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048700:
    // 80048700: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80048704:
    ctx->pc = 0x80048704u;
    // 80048704: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_80048708:
    // 80048708: cmpwi   r9, 0
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

label_8004870C:
    // 8004870C: bc    12, 2, 0x80048720
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048720;
        }
    }

label_80048710:
    loop_80048710(ctx);
    if (ctx->pc == 0x80048720u) goto label_80048720;
    return;
label_80048714:
    ctx->pc = 0x80048714u;
    // 80048714: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048718:
    // 80048718: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_8004871C:
    // 8004871C: bc    16, 0, 0x80048710
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048710u;
                return;
            }
            goto label_80048710;
        }
    }

label_80048720:
    ctx->pc = 0x80048720u;
    ctx->downcount -= 6;
    // 80048720: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80048724:
    ctx->pc = 0x80048724u;
    // 80048724: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048728:
    // 80048728: cmpwi   r3, 0
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

label_8004872C:
    // 8004872C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048730:
    // 80048730: srawi r0, r0, 2
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

label_80048734:
    // 80048734: bc    12, 2, 0x80048750
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048750;
        }
    }

label_80048738:
    ctx->downcount -= 3;
    // 80048738: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8004873C:
    // 8004873C: cmplwi  r4, 0x0080
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

label_80048740:
    // 80048740: bc    4, 1, 0x8004874C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004874C;
        }
    }

label_80048744:
    ctx->downcount -= 1;
    // 80048744: bl      0x80281D80
    {
            ctx->lr = 0x80048748u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80048748:
    ctx->downcount -= 1;
    // 80048748: b       0x80048750
    {
            goto label_80048750;
    }

label_8004874C:
    ctx->downcount -= 1;
    // 8004874C: bl      0x8001D934
    {
            ctx->lr = 0x80048750u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80048750:
    ctx->downcount -= 4;
    // 80048750: add   r0, r28, r29
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80048754:
    ctx->pc = 0x80048754u;
    // 80048754: stw     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80048758:
    ctx->pc = 0x80048758u;
    // 80048758: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004875C:
    ctx->pc = 0x8004875Cu;
    // 8004875C: stw     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80048760:
    ctx->downcount -= 3;
    // 80048760: or   r27, r23, r23
    {
        ctx->gpr[27] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80048764:
    // 80048764: cmplw   r27, r20
    {
        u32 val_a = (u32)(ctx->gpr[27]);
        u32 val_b = (u32)(ctx->gpr[20]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80048768:
    // 80048768: bc    12, 0, 0x800484C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800484C4u;
                return;
            }
            goto label_800484C4;
        }
    }

label_8004876C:
    ctx->pc = 0x8004876Cu;
    ctx->downcount -= 1;
    // 8004876C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80048770:
    ctx->pc = 0x80048770u;
    ctx->downcount -= 16;
    // 80048770: lwz     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048774:
    ctx->pc = 0x80048774u;
    // 80048774: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80048778:
    ctx->pc = 0x80048778u;
    // 80048778: lmw     r19, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 19; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004877C:
    ctx->pc = 0x8004877Cu;
    // 8004877C: addi    r1, r1, 96
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(96);

label_80048780:
    ctx->pc = 0x80048780u;
    // 80048780: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80048784:
    ctx->pc = 0x80048784u;
    ctx->downcount -= 18;
    // 80048784: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80048788:
    ctx->pc = 0x80048788u;
    // 80048788: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004878C:
    ctx->pc = 0x8004878Cu;
    // 8004878C: stmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80048790:
    ctx->pc = 0x80048790u;
    // 80048790: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048794:
    ctx->pc = 0x80048794u;
    // 80048794: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048798:
    ctx->pc = 0x80048798u;
    // 80048798: lwz     r31, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004879C:
    ctx->pc = 0x8004879Cu;
    // 8004879C: cmpwi   r31, 0
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

label_800487A0:
    ctx->pc = 0x800487A0u;
    // 800487A0: bc    4, 2, 0x800487BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800487BC;
        }
    }

label_800487A4:
    ctx->pc = 0x800487A4u;
    ctx->downcount -= 2;
    // 800487A4: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_800487A8:
    ctx->pc = 0x800487A8u;
    // 800487A8: bl      0x80281C60
    {
            ctx->lr = 0x800487ACu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800487AC:
    ctx->pc = 0x800487ACu;
    ctx->downcount -= 4;
    // 800487AC: stw     r31, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800487B0:
    ctx->pc = 0x800487B0u;
    // 800487B0: stw     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800487B4:
    ctx->pc = 0x800487B4u;
    // 800487B4: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800487B8:
    ctx->pc = 0x800487B8u;
    // 800487B8: stw     r31, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800487BC:
    ctx->pc = 0x800487BCu;
    ctx->downcount -= 3;
    // 800487BC: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800487C0:
    ctx->pc = 0x800487C0u;
    // 800487C0: cmpwi   r31, 0
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

label_800487C4:
    ctx->pc = 0x800487C4u;
    // 800487C4: bc    4, 2, 0x800487E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800487E0;
        }
    }

label_800487C8:
    ctx->pc = 0x800487C8u;
    ctx->downcount -= 2;
    // 800487C8: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_800487CC:
    ctx->pc = 0x800487CCu;
    // 800487CC: bl      0x80281C60
    {
            ctx->lr = 0x800487D0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800487D0:
    ctx->pc = 0x800487D0u;
    ctx->downcount -= 4;
    // 800487D0: stw     r31, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800487D4:
    ctx->pc = 0x800487D4u;
    // 800487D4: stw     r3, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800487D8:
    ctx->pc = 0x800487D8u;
    // 800487D8: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800487DC:
    ctx->pc = 0x800487DCu;
    // 800487DC: stw     r31, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800487E0:
    ctx->pc = 0x800487E0u;
    ctx->downcount -= 6;
    // 800487E0: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800487E4:
    ctx->pc = 0x800487E4u;
    // 800487E4: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800487E8:
    ctx->pc = 0x800487E8u;
    // 800487E8: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800487EC:
    ctx->pc = 0x800487ECu;
    // 800487EC: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800487F0:
    ctx->pc = 0x800487F0u;
    // 800487F0: rlwinm. r9, r0, 30, 2, 31
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

label_800487F4:
    ctx->pc = 0x800487F4u;
    // 800487F4: bc    4, 2, 0x80048838
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048838;
        }
    }

label_800487F8:
    ctx->pc = 0x800487F8u;
    ctx->downcount -= 3;
    // 800487F8: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800487FC:
    ctx->pc = 0x800487FCu;
    // 800487FC: cmpwi   r0, 0
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

label_80048800:
    ctx->pc = 0x80048800u;
    // 80048800: bc    4, 2, 0x80048830
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048830;
        }
    }

label_80048804:
    ctx->pc = 0x80048804u;
    ctx->downcount -= 9;
    // 80048804: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048808:
    ctx->pc = 0x80048808u;
    // 80048808: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8004880C:
    ctx->pc = 0x8004880Cu;
    // 8004880C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80048810:
    ctx->pc = 0x80048810u;
    // 80048810: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048814:
    ctx->pc = 0x80048814u;
    // 80048814: lwz     r4, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80048818:
    ctx->pc = 0x80048818u;
    // 80048818: subf   r4, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_8004881C:
    ctx->pc = 0x8004881Cu;
    // 8004881C: srawi r4, r4, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[4];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80048820:
    ctx->pc = 0x80048820u;
    // 80048820: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_80048824:
    ctx->pc = 0x80048824u;
    // 80048824: bl      0x8001CB80
    {
            ctx->lr = 0x80048828u;
            ctx->pc = 0x8001CB80u;
            return;
    }

label_80048828:
    ctx->pc = 0x80048828u;
    ctx->downcount -= 2;
    // 80048828: cmpwi   r3, 0
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

label_8004882C:
    ctx->pc = 0x8004882Cu;
    // 8004882C: bc    4, 2, 0x80048838
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048838;
        }
    }

label_80048830:
    ctx->pc = 0x80048830u;
    ctx->downcount -= 2;
    // 80048830: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80048834:
    ctx->pc = 0x80048834u;
    // 80048834: b       0x8004885C
    {
            goto label_8004885C;
    }

label_80048838:
    ctx->pc = 0x80048838u;
    ctx->downcount -= 9;
    // 80048838: lwz     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004883C:
    ctx->pc = 0x8004883Cu;
    // 8004883C: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048840:
    ctx->pc = 0x80048840u;
    // 80048840: lwzu     r0, -4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_80048844:
    ctx->pc = 0x80048844u;
    // 80048844: stw     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80048848:
    ctx->pc = 0x80048848u;
    // 80048848: rlwinm r10, r0, 2, 0, 29
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8004884C:
    ctx->pc = 0x8004884Cu;
    // 8004884C: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048850:
    ctx->pc = 0x80048850u;
    // 80048850: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80048854:
    ctx->pc = 0x80048854u;
    // 80048854: lwzx    r3, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80048858:
    ctx->pc = 0x80048858u;
    // 80048858: stw     r0, 76(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004885C:
    ctx->pc = 0x8004885Cu;
    ctx->downcount -= 16;
    // 8004885C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048860:
    ctx->pc = 0x80048860u;
    // 80048860: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80048864:
    ctx->pc = 0x80048864u;
    // 80048864: lmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80048868:
    ctx->pc = 0x80048868u;
    // 80048868: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8004886C:
    ctx->pc = 0x8004886Cu;
    // 8004886C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80048870:
    ctx->pc = 0x80048870u;
    ctx->downcount -= 23;
    // 80048870: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80048874:
    ctx->pc = 0x80048874u;
    // 80048874: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80048878:
    ctx->pc = 0x80048878u;
    // 80048878: stmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8004887C:
    ctx->pc = 0x8004887Cu;
    // 8004887C: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048880:
    ctx->pc = 0x80048880u;
    // 80048880: lwz     r31, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80048884:
    ctx->pc = 0x80048884u;
    // 80048884: or   r27, r4, r4
    {
        ctx->gpr[27] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80048888:
    ctx->pc = 0x80048888u;
    // 80048888: lwz     r9, 76(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(76);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004888C:
    ctx->pc = 0x8004888Cu;
    // 8004888C: addi    r26, r1, 8
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(8);

label_80048890:
    ctx->pc = 0x80048890u;
    // 80048890: lwz     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80048894:
    ctx->pc = 0x80048894u;
    // 80048894: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048898:
    ctx->pc = 0x80048898u;
    // 80048898: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004889C:
    ctx->pc = 0x8004889Cu;
    // 8004889C: cmpw    r30, r0
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

label_800488A0:
    ctx->pc = 0x800488A0u;
    // 800488A0: bc    12, 2, 0x800488C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800488C0;
        }
    }

label_800488A4:
    ctx->pc = 0x800488A4u;
    ctx->downcount -= 2;
    // 800488A4: cmpwi   r30, 0
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

label_800488A8:
    ctx->pc = 0x800488A8u;
    // 800488A8: bc    12, 2, 0x800488B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800488B0;
        }
    }

label_800488AC:
    ctx->pc = 0x800488ACu;
    ctx->downcount -= 1;
    // 800488AC: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800488B0:
    ctx->pc = 0x800488B0u;
    ctx->downcount -= 4;
    // 800488B0: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800488B4:
    ctx->pc = 0x800488B4u;
    // 800488B4: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_800488B8:
    ctx->pc = 0x800488B8u;
    // 800488B8: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800488BC:
    ctx->pc = 0x800488BCu;
    // 800488BC: b       0x800489BC
    {
            goto label_800489BC;
    }

label_800488C0:
    ctx->pc = 0x800488C0u;
    ctx->downcount -= 10;
    // 800488C0: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800488C4:
    ctx->pc = 0x800488C4u;
    // 800488C4: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_800488C8:
    ctx->pc = 0x800488C8u;
    // 800488C8: stw     r9, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800488CC:
    ctx->pc = 0x800488CCu;
    // 800488CC: addi    r10, r1, 16
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(16);

label_800488D0:
    ctx->pc = 0x800488D0u;
    // 800488D0: subf   r0, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800488D4:
    ctx->pc = 0x800488D4u;
    // 800488D4: addi    r11, r1, 12
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(12);

label_800488D8:
    ctx->pc = 0x800488D8u;
    // 800488D8: srawi r9, r0, 2
    {
        u32 sh = 2u;
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
    }

label_800488DC:
    ctx->pc = 0x800488DCu;
    // 800488DC: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800488E0:
    ctx->pc = 0x800488E0u;
    // 800488E0: cmplwi  r9, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800488E4:
    ctx->pc = 0x800488E4u;
    // 800488E4: bc    4, 0, 0x800488EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800488EC;
        }
    }

label_800488E8:
    ctx->pc = 0x800488E8u;
    ctx->downcount -= 1;
    // 800488E8: or   r11, r10, r10
    {
        ctx->gpr[11] = ctx->gpr[10] | ctx->gpr[10];
    }

label_800488EC:
    ctx->pc = 0x800488ECu;
    ctx->downcount -= 3;
    // 800488EC: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800488F0:
    ctx->pc = 0x800488F0u;
    // 800488F0: add.   r0, r9, r0
    {
        u32 a = ctx->gpr[9];
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

label_800488F4:
    ctx->pc = 0x800488F4u;
    // 800488F4: bc    12, 2, 0x80048928
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048928;
        }
    }

label_800488F8:
    ctx->pc = 0x800488F8u;
    ctx->downcount -= 4;
    // 800488F8: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_800488FC:
    ctx->pc = 0x800488FCu;
    // 800488FC: or   r28, r0, r0
    {
        ctx->gpr[28] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80048900:
    ctx->pc = 0x80048900u;
    // 80048900: cmplwi  r0, 0x0080
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

label_80048904:
    ctx->pc = 0x80048904u;
    // 80048904: bc    4, 1, 0x80048918
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048918;
        }
    }

label_80048908:
    ctx->pc = 0x80048908u;
    ctx->downcount -= 2;
    // 80048908: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8004890C:
    ctx->pc = 0x8004890Cu;
    // 8004890C: bl      0x80281C60
    {
            ctx->lr = 0x80048910u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80048910:
    ctx->pc = 0x80048910u;
    ctx->downcount -= 2;
    // 80048910: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048914:
    ctx->pc = 0x80048914u;
    // 80048914: b       0x80048930
    {
            goto label_80048930;
    }

label_80048918:
    ctx->pc = 0x80048918u;
    ctx->downcount -= 2;
    // 80048918: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8004891C:
    ctx->pc = 0x8004891Cu;
    // 8004891C: bl      0x80004024
    {
            ctx->lr = 0x80048920u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80048920:
    ctx->pc = 0x80048920u;
    ctx->downcount -= 2;
    // 80048920: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048924:
    ctx->pc = 0x80048924u;
    // 80048924: b       0x80048930
    {
            goto label_80048930;
    }

label_80048928:
    ctx->pc = 0x80048928u;
    ctx->downcount -= 2;
    // 80048928: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8004892C:
    ctx->pc = 0x8004892Cu;
    // 8004892C: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80048930:
    ctx->pc = 0x80048930u;
    ctx->downcount -= 3;
    // 80048930: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80048934:
    ctx->pc = 0x80048934u;
    // 80048934: cmpw    r30, r4
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

label_80048938:
    ctx->pc = 0x80048938u;
    // 80048938: bc    12, 2, 0x80048954
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048954;
        }
    }

label_8004893C:
    ctx->pc = 0x8004893Cu;
    ctx->downcount -= 4;
    // 8004893C: subf   r30, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_80048940:
    ctx->pc = 0x80048940u;
    // 80048940: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80048944:
    ctx->pc = 0x80048944u;
    // 80048944: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80048948:
    ctx->pc = 0x80048948u;
    // 80048948: bl      0x80297E3C
    {
            ctx->lr = 0x8004894Cu;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8004894C:
    ctx->pc = 0x8004894Cu;
    ctx->downcount -= 2;
    // 8004894C: add   r0, r3, r30
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80048950:
    ctx->pc = 0x80048950u;
    // 80048950: b       0x80048958
    {
            goto label_80048958;
    }

label_80048954:
    ctx->pc = 0x80048954u;
    ctx->downcount -= 1;
    // 80048954: or   r0, r29, r29
    {
        ctx->gpr[0] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80048958:
    ctx->pc = 0x80048958u;
    ctx->downcount -= 6;
    // 80048958: lwz     r9, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004895C:
    ctx->pc = 0x8004895Cu;
    // 8004895C: or   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80048960:
    ctx->pc = 0x80048960u;
    // 80048960: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_80048964:
    ctx->pc = 0x80048964u;
    // 80048964: cmpwi   r9, 0
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

label_80048968:
    ctx->pc = 0x80048968u;
    // 80048968: bc    12, 2, 0x8004897C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004897C;
        }
    }

label_8004896C:
    loop_8004896C(ctx);
    if (ctx->pc == 0x8004897Cu) goto label_8004897C;
    return;
label_80048970:
    ctx->pc = 0x80048970u;
    // 80048970: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048974:
    // 80048974: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_80048978:
    // 80048978: bc    16, 0, 0x8004896C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004896Cu;
                return;
            }
            goto label_8004896C;
        }
    }

label_8004897C:
    ctx->pc = 0x8004897Cu;
    ctx->downcount -= 6;
    // 8004897C: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80048980:
    ctx->pc = 0x80048980u;
    // 80048980: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048984:
    ctx->pc = 0x80048984u;
    // 80048984: cmpwi   r3, 0
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

label_80048988:
    ctx->pc = 0x80048988u;
    // 80048988: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8004898C:
    ctx->pc = 0x8004898Cu;
    // 8004898C: srawi r0, r0, 2
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

label_80048990:
    ctx->pc = 0x80048990u;
    // 80048990: bc    12, 2, 0x800489AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800489AC;
        }
    }

label_80048994:
    ctx->pc = 0x80048994u;
    ctx->downcount -= 3;
    // 80048994: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80048998:
    ctx->pc = 0x80048998u;
    // 80048998: cmplwi  r4, 0x0080
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

label_8004899C:
    ctx->pc = 0x8004899Cu;
    // 8004899C: bc    4, 1, 0x800489A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800489A8;
        }
    }

label_800489A0:
    ctx->pc = 0x800489A0u;
    ctx->downcount -= 1;
    // 800489A0: bl      0x80281D80
    {
            ctx->lr = 0x800489A4u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800489A4:
    ctx->pc = 0x800489A4u;
    ctx->downcount -= 1;
    // 800489A4: b       0x800489AC
    {
            goto label_800489AC;
    }

label_800489A8:
    ctx->pc = 0x800489A8u;
    ctx->downcount -= 1;
    // 800489A8: bl      0x8001D934
    {
            ctx->lr = 0x800489ACu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_800489AC:
    ctx->pc = 0x800489ACu;
    ctx->downcount -= 4;
    // 800489AC: add   r0, r28, r29
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800489B0:
    ctx->pc = 0x800489B0u;
    // 800489B0: stw     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800489B4:
    ctx->pc = 0x800489B4u;
    // 800489B4: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800489B8:
    ctx->pc = 0x800489B8u;
    // 800489B8: stw     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800489BC:
    ctx->pc = 0x800489BCu;
    ctx->downcount -= 8;
    // 800489BC: lwz     r9, 32(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800489C0:
    ctx->pc = 0x800489C0u;
    // 800489C0: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_800489C4:
    ctx->pc = 0x800489C4u;
    // 800489C4: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800489C8:
    ctx->pc = 0x800489C8u;
    // 800489C8: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800489CC:
    ctx->pc = 0x800489CCu;
    // 800489CC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800489D0:
    ctx->pc = 0x800489D0u;
    // 800489D0: add   r3, r27, r3
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800489D4:
    ctx->pc = 0x800489D4u;
    // 800489D4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800489D8u;
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800489D8:
    ctx->pc = 0x800489D8u;
    ctx->downcount -= 18;
    // 800489D8: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_800489DC:
    ctx->pc = 0x800489DCu;
    // 800489DC: stw     r0, 76(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800489E0:
    ctx->pc = 0x800489E0u;
    // 800489E0: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800489E4:
    ctx->pc = 0x800489E4u;
    // 800489E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800489E8:
    ctx->pc = 0x800489E8u;
    // 800489E8: lmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800489EC:
    ctx->pc = 0x800489ECu;
    // 800489EC: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_800489F0:
    ctx->pc = 0x800489F0u;
    // 800489F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800489F4:
    ctx->pc = 0x800489F4u;
    ctx->downcount -= 18;
    // 800489F4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800489F8:
    ctx->pc = 0x800489F8u;
    // 800489F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800489FC:
    ctx->pc = 0x800489FCu;
    // 800489FC: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80048A00:
    ctx->pc = 0x80048A00u;
    // 80048A00: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048A04:
    ctx->pc = 0x80048A04u;
    // 80048A04: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048A08:
    ctx->pc = 0x80048A08u;
    // 80048A08: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80048A0C:
    ctx->pc = 0x80048A0Cu;
    // 80048A0C: cmpwi   r11, 0
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

label_80048A10:
    ctx->pc = 0x80048A10u;
    // 80048A10: bc    12, 2, 0x80048AF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048AF4;
        }
    }

label_80048A14:
    ctx->pc = 0x80048A14u;
    ctx->downcount -= 6;
    // 80048A14: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048A18:
    ctx->pc = 0x80048A18u;
    // 80048A18: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80048A1C:
    ctx->pc = 0x80048A1Cu;
    // 80048A1C: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048A20:
    ctx->pc = 0x80048A20u;
    // 80048A20: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048A24:
    ctx->pc = 0x80048A24u;
    // 80048A24: rlwinm. r9, r0, 30, 2, 31
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

label_80048A28:
    ctx->pc = 0x80048A28u;
    // 80048A28: bc    12, 2, 0x80048AA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048AA8;
        }
    }

label_80048A2C:
    ctx->pc = 0x80048A2Cu;
    ctx->downcount -= 2;
    // 80048A2C: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80048A30:
    ctx->pc = 0x80048A30u;
    // 80048A30: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80048A34:
    ctx->pc = 0x80048A34u;
    ctx->downcount -= 6;
    // 80048A34: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048A38:
    ctx->pc = 0x80048A38u;
    // 80048A38: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80048A3C:
    ctx->pc = 0x80048A3Cu;
    // 80048A3C: lwzx    r11, r11, r29
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[29];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80048A40:
    ctx->pc = 0x80048A40u;
    // 80048A40: lwz     r0, 76(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048A44:
    // 80048A44: cmpwi   r0, -1
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

label_80048A48:
    // 80048A48: bc    12, 2, 0x80048A70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048A70;
        }
    }

label_80048A4C:
    ctx->downcount -= 2;
    // 80048A4C: cmpwi   r11, 0
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

label_80048A50:
    // 80048A50: bc    12, 2, 0x80048A70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048A70;
        }
    }

label_80048A54:
    ctx->pc = 0x80048A54u;
    ctx->downcount -= 8;
    // 80048A54: lwz     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048A58:
    // 80048A58: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80048A5C:
    ctx->pc = 0x80048A5Cu;
    // 80048A5C: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80048A60:
    ctx->pc = 0x80048A60u;
    // 80048A60: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048A64:
    // 80048A64: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80048A68:
    ctx->pc = 0x80048A68u;
    // 80048A68: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80048A6C:
    ctx->pc = 0x80048A6Cu;
    // 80048A6C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80048A70u;
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80048A70:
    ctx->pc = 0x80048A70u;
    ctx->downcount -= 7;
    // 80048A70: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80048A74:
    // 80048A74: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_80048A78:
    // 80048A78: addi    r29, r29, 4
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(4);

label_80048A7C:
    ctx->pc = 0x80048A7Cu;
    // 80048A7C: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048A80:
    ctx->pc = 0x80048A80u;
    // 80048A80: lwzx    r3, r9, r28
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[28];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80048A84:
    // 80048A84: addi    r28, r28, 4
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(4);

label_80048A88:
    // 80048A88: bl      0x80281B70
    {
            ctx->lr = 0x80048A8Cu;
            ctx->pc = 0x80281B70u;
            return;
    }

label_80048A8C:
    ctx->pc = 0x80048A8Cu;
    ctx->downcount -= 7;
    // 80048A8C: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048A90:
    ctx->pc = 0x80048A90u;
    // 80048A90: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80048A94:
    ctx->pc = 0x80048A94u;
    // 80048A94: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048A98:
    // 80048A98: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048A9C:
    // 80048A9C: srawi r0, r0, 2
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

label_80048AA0:
    // 80048AA0: cmplw   r31, r0
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

label_80048AA4:
    // 80048AA4: bc    12, 0, 0x80048A34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048A34u;
                return;
            }
            goto label_80048A34;
        }
    }

label_80048AA8:
    ctx->pc = 0x80048AA8u;
    ctx->downcount -= 6;
    // 80048AA8: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048AAC:
    ctx->pc = 0x80048AACu;
    // 80048AAC: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048AB0:
    ctx->pc = 0x80048AB0u;
    // 80048AB0: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048AB4:
    ctx->pc = 0x80048AB4u;
    // 80048AB4: lwz     r31, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80048AB8:
    ctx->pc = 0x80048AB8u;
    // 80048AB8: cmpwi   r31, 0
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

label_80048ABC:
    ctx->pc = 0x80048ABCu;
    // 80048ABC: bc    12, 2, 0x80048AF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048AF4;
        }
    }

label_80048AC0:
    ctx->pc = 0x80048AC0u;
    ctx->downcount -= 3;
    // 80048AC0: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80048AC4:
    ctx->pc = 0x80048AC4u;
    // 80048AC4: cmpwi   r3, 0
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

label_80048AC8:
    ctx->pc = 0x80048AC8u;
    // 80048AC8: bc    12, 2, 0x80048AEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048AEC;
        }
    }

label_80048ACC:
    ctx->pc = 0x80048ACCu;
    ctx->downcount -= 5;
    // 80048ACC: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048AD0:
    ctx->pc = 0x80048AD0u;
    // 80048AD0: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048AD4:
    ctx->pc = 0x80048AD4u;
    // 80048AD4: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80048AD8:
    ctx->pc = 0x80048AD8u;
    // 80048AD8: cmplwi  r4, 0x0080
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

label_80048ADC:
    ctx->pc = 0x80048ADCu;
    // 80048ADC: bc    4, 1, 0x80048AE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048AE8;
        }
    }

label_80048AE0:
    ctx->pc = 0x80048AE0u;
    ctx->downcount -= 1;
    // 80048AE0: bl      0x80281D80
    {
            ctx->lr = 0x80048AE4u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80048AE4:
    ctx->pc = 0x80048AE4u;
    ctx->downcount -= 1;
    // 80048AE4: b       0x80048AEC
    {
            goto label_80048AEC;
    }

label_80048AE8:
    ctx->pc = 0x80048AE8u;
    ctx->downcount -= 1;
    // 80048AE8: bl      0x8001D934
    {
            ctx->lr = 0x80048AECu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80048AEC:
    ctx->pc = 0x80048AECu;
    ctx->downcount -= 2;
    // 80048AEC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80048AF0:
    ctx->pc = 0x80048AF0u;
    // 80048AF0: bl      0x80281D80
    {
            ctx->lr = 0x80048AF4u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80048AF4:
    ctx->pc = 0x80048AF4u;
    ctx->downcount -= 5;
    // 80048AF4: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048AF8:
    ctx->pc = 0x80048AF8u;
    // 80048AF8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80048AFC:
    ctx->pc = 0x80048AFCu;
    // 80048AFC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048B00:
    ctx->pc = 0x80048B00u;
    // 80048B00: cmpwi   r9, 0
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

label_80048B04:
    ctx->pc = 0x80048B04u;
    // 80048B04: bc    12, 2, 0x80048B50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048B50;
        }
    }

label_80048B08:
    ctx->pc = 0x80048B08u;
    ctx->downcount -= 5;
    // 80048B08: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048B0C:
    ctx->pc = 0x80048B0Cu;
    // 80048B0C: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048B10:
    ctx->pc = 0x80048B10u;
    // 80048B10: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80048B14:
    ctx->pc = 0x80048B14u;
    // 80048B14: cmpwi   r31, 0
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

label_80048B18:
    ctx->pc = 0x80048B18u;
    // 80048B18: bc    12, 2, 0x80048B50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048B50;
        }
    }

label_80048B1C:
    ctx->pc = 0x80048B1Cu;
    ctx->downcount -= 3;
    // 80048B1C: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80048B20:
    ctx->pc = 0x80048B20u;
    // 80048B20: cmpwi   r3, 0
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

label_80048B24:
    ctx->pc = 0x80048B24u;
    // 80048B24: bc    12, 2, 0x80048B48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048B48;
        }
    }

label_80048B28:
    ctx->pc = 0x80048B28u;
    ctx->downcount -= 5;
    // 80048B28: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048B2C:
    ctx->pc = 0x80048B2Cu;
    // 80048B2C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80048B30:
    ctx->pc = 0x80048B30u;
    // 80048B30: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80048B34:
    ctx->pc = 0x80048B34u;
    // 80048B34: cmplwi  r4, 0x0080
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

label_80048B38:
    ctx->pc = 0x80048B38u;
    // 80048B38: bc    4, 1, 0x80048B44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048B44;
        }
    }

label_80048B3C:
    ctx->pc = 0x80048B3Cu;
    ctx->downcount -= 1;
    // 80048B3C: bl      0x80281D80
    {
            ctx->lr = 0x80048B40u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80048B40:
    ctx->pc = 0x80048B40u;
    ctx->downcount -= 1;
    // 80048B40: b       0x80048B48
    {
            goto label_80048B48;
    }

label_80048B44:
    ctx->pc = 0x80048B44u;
    ctx->downcount -= 1;
    // 80048B44: bl      0x8001D934
    {
            ctx->lr = 0x80048B48u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80048B48:
    ctx->pc = 0x80048B48u;
    ctx->downcount -= 2;
    // 80048B48: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80048B4C:
    ctx->pc = 0x80048B4Cu;
    // 80048B4C: bl      0x80281D80
    {
            ctx->lr = 0x80048B50u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80048B50:
    ctx->pc = 0x80048B50u;
    ctx->downcount -= 19;
    // 80048B50: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80048B54:
    ctx->pc = 0x80048B54u;
    // 80048B54: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048B58:
    ctx->pc = 0x80048B58u;
    // 80048B58: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048B5C:
    ctx->pc = 0x80048B5Cu;
    // 80048B5C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048B60:
    ctx->pc = 0x80048B60u;
    // 80048B60: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80048B64:
    ctx->pc = 0x80048B64u;
    // 80048B64: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80048B68:
    ctx->pc = 0x80048B68u;
    // 80048B68: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80048B6C:
    ctx->pc = 0x80048B6Cu;
    // 80048B6C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80048B70:
    ctx->pc = 0x80048B70u;
    ctx->downcount -= 17;
    // 80048B70: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80048B74:
    ctx->pc = 0x80048B74u;
    // 80048B74: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80048B78:
    ctx->pc = 0x80048B78u;
    // 80048B78: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80048B7C:
    ctx->pc = 0x80048B7Cu;
    // 80048B7C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048B80:
    ctx->pc = 0x80048B80u;
    // 80048B80: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048B84:
    ctx->pc = 0x80048B84u;
    // 80048B84: or.   r31, r4, r4
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

label_80048B88:
    ctx->pc = 0x80048B88u;
    // 80048B88: bc    12, 2, 0x80048BE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048BE0;
        }
    }

label_80048B8C:
    ctx->pc = 0x80048B8Cu;
    ctx->downcount -= 3;
    // 80048B8C: lwz     r4, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80048B90:
    // 80048B90: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80048B94:
    // 80048B94: bl      0x80048B70
    {
            ctx->lr = 0x80048B98u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048B70u;
                return;
            }
            goto label_80048B70;
    }

label_80048B98:
    ctx->pc = 0x80048B98u;
    ctx->downcount -= 6;
    // 80048B98: lwz     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80048B9C:
    ctx->pc = 0x80048B9Cu;
    // 80048B9C: lwz     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048BA0:
    ctx->pc = 0x80048BA0u;
    // 80048BA0: lwz     r30, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80048BA4:
    // 80048BA4: cmpwi   r3, 0
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

label_80048BA8:
    // 80048BA8: subf   r4, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_80048BAC:
    // 80048BAC: bc    12, 2, 0x80048BC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048BC4;
        }
    }

label_80048BB0:
    ctx->downcount -= 2;
    // 80048BB0: cmplwi  r4, 0x0080
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

label_80048BB4:
    // 80048BB4: bc    4, 1, 0x80048BC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048BC0;
        }
    }

label_80048BB8:
    ctx->downcount -= 1;
    // 80048BB8: bl      0x80281D80
    {
            ctx->lr = 0x80048BBCu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80048BBC:
    ctx->downcount -= 1;
    // 80048BBC: b       0x80048BC4
    {
            goto label_80048BC4;
    }

label_80048BC0:
    ctx->downcount -= 1;
    // 80048BC0: bl      0x8001D934
    {
            ctx->lr = 0x80048BC4u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80048BC4:
    ctx->downcount -= 2;
    // 80048BC4: cmpwi   r31, 0
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

label_80048BC8:
    // 80048BC8: bc    12, 2, 0x80048BD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048BD8;
        }
    }

label_80048BCC:
    ctx->downcount -= 3;
    // 80048BCC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80048BD0:
    // 80048BD0: li      r4, 36
    ctx->gpr[4] = (u32)(s32)(36);

label_80048BD4:
    // 80048BD4: bl      0x8001D934
    {
            ctx->lr = 0x80048BD8u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80048BD8:
    ctx->downcount -= 2;
    // 80048BD8: or.   r31, r30, r30
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

label_80048BDC:
    // 80048BDC: bc    4, 2, 0x80048B8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048B8Cu;
                return;
            }
            goto label_80048B8C;
        }
    }

label_80048BE0:
    ctx->pc = 0x80048BE0u;
    ctx->downcount -= 16;
    // 80048BE0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048BE4:
    ctx->pc = 0x80048BE4u;
    // 80048BE4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80048BE8:
    ctx->pc = 0x80048BE8u;
    // 80048BE8: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80048BEC:
    ctx->pc = 0x80048BECu;
    // 80048BEC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80048BF0:
    ctx->pc = 0x80048BF0u;
    // 80048BF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80048BF4:
    ctx->pc = 0x80048BF4u;
    ctx->downcount -= 7;
    // 80048BF4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80048BF8:
    ctx->pc = 0x80048BF8u;
    // 80048BF8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80048BFC:
    ctx->pc = 0x80048BFCu;
    // 80048BFC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048C00:
    ctx->pc = 0x80048C00u;
    // 80048C00: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80048C04:
    ctx->pc = 0x80048C04u;
    // 80048C04: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_80048C08:
    ctx->pc = 0x80048C08u;
    // 80048C08: cmpw    r4, r0
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

label_80048C0C:
    ctx->pc = 0x80048C0Cu;
    // 80048C0C: bc    4, 2, 0x80048CF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048CF4;
        }
    }

label_80048C10:
    ctx->pc = 0x80048C10u;
    ctx->downcount -= 2;
    // 80048C10: cmpwi   r3, 0
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

label_80048C14:
    ctx->pc = 0x80048C14u;
    // 80048C14: bc    12, 2, 0x80048CF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048CF4;
        }
    }

label_80048C18:
    ctx->pc = 0x80048C18u;
    ctx->downcount -= 5;
    // 80048C18: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_80048C1C:
    ctx->pc = 0x80048C1Cu;
    // 80048C1C: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_80048C20:
    ctx->pc = 0x80048C20u;
    // 80048C20: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_80048C24:
    ctx->pc = 0x80048C24u;
    // 80048C24: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80048C28:
    ctx->pc = 0x80048C28u;
    // 80048C28: bl      0x80252AF0
    {
            ctx->lr = 0x80048C2Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80048C2C:
    ctx->pc = 0x80048C2Cu;
    ctx->downcount -= 5;
    // 80048C2C: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_80048C30:
    ctx->pc = 0x80048C30u;
    // 80048C30: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80048C34:
    ctx->pc = 0x80048C34u;
    // 80048C34: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_80048C38:
    ctx->pc = 0x80048C38u;
    // 80048C38: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80048C3C:
    ctx->pc = 0x80048C3Cu;
    // 80048C3C: bl      0x80252AF0
    {
            ctx->lr = 0x80048C40u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80048C40:
    ctx->pc = 0x80048C40u;
    ctx->downcount -= 5;
    // 80048C40: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_80048C44:
    ctx->pc = 0x80048C44u;
    // 80048C44: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_80048C48:
    ctx->pc = 0x80048C48u;
    // 80048C48: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_80048C4C:
    ctx->pc = 0x80048C4Cu;
    // 80048C4C: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_80048C50:
    ctx->pc = 0x80048C50u;
    // 80048C50: bl      0x80252AF0
    {
            ctx->lr = 0x80048C54u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80048C54:
    ctx->pc = 0x80048C54u;
    ctx->downcount -= 5;
    // 80048C54: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_80048C58:
    ctx->pc = 0x80048C58u;
    // 80048C58: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80048C5C:
    ctx->pc = 0x80048C5Cu;
    // 80048C5C: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_80048C60:
    ctx->pc = 0x80048C60u;
    // 80048C60: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80048C64:
    ctx->pc = 0x80048C64u;
    // 80048C64: bl      0x80252AF0
    {
            ctx->lr = 0x80048C68u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80048C68:
    ctx->pc = 0x80048C68u;
    ctx->downcount -= 5;
    // 80048C68: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_80048C6C:
    ctx->pc = 0x80048C6Cu;
    // 80048C6C: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_80048C70:
    ctx->pc = 0x80048C70u;
    // 80048C70: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_80048C74:
    ctx->pc = 0x80048C74u;
    // 80048C74: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80048C78:
    ctx->pc = 0x80048C78u;
    // 80048C78: bl      0x80252AF0
    {
            ctx->lr = 0x80048C7Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80048C7C:
    ctx->pc = 0x80048C7Cu;
    ctx->downcount -= 5;
    // 80048C7C: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_80048C80:
    ctx->pc = 0x80048C80u;
    // 80048C80: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80048C84:
    ctx->pc = 0x80048C84u;
    // 80048C84: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_80048C88:
    ctx->pc = 0x80048C88u;
    // 80048C88: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80048C8C:
    ctx->pc = 0x80048C8Cu;
    // 80048C8C: bl      0x80252AF0
    {
            ctx->lr = 0x80048C90u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80048C90:
    ctx->pc = 0x80048C90u;
    ctx->downcount -= 5;
    // 80048C90: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_80048C94:
    ctx->pc = 0x80048C94u;
    // 80048C94: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80048C98:
    ctx->pc = 0x80048C98u;
    // 80048C98: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_80048C9C:
    ctx->pc = 0x80048C9Cu;
    // 80048C9C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80048CA0:
    ctx->pc = 0x80048CA0u;
    // 80048CA0: bl      0x80252AF0
    {
            ctx->lr = 0x80048CA4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80048CA4:
    ctx->pc = 0x80048CA4u;
    ctx->downcount -= 5;
    // 80048CA4: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_80048CA8:
    ctx->pc = 0x80048CA8u;
    // 80048CA8: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_80048CAC:
    ctx->pc = 0x80048CACu;
    // 80048CAC: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_80048CB0:
    ctx->pc = 0x80048CB0u;
    // 80048CB0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80048CB4:
    ctx->pc = 0x80048CB4u;
    // 80048CB4: bl      0x80252AF0
    {
            ctx->lr = 0x80048CB8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80048CB8:
    ctx->pc = 0x80048CB8u;
    ctx->downcount -= 5;
    // 80048CB8: lis     r3, 25197
    ctx->gpr[3] = ((u32)(s32)(25197) << 16);

label_80048CBC:
    ctx->pc = 0x80048CBCu;
    // 80048CBC: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_80048CC0:
    ctx->pc = 0x80048CC0u;
    // 80048CC0: ori     r3, r3, 0x7368
    ctx->gpr[3] = ctx->gpr[3] | 0x7368u;

label_80048CC4:
    ctx->pc = 0x80048CC4u;
    // 80048CC4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80048CC8:
    ctx->pc = 0x80048CC8u;
    // 80048CC8: bl      0x80252AF0
    {
            ctx->lr = 0x80048CCCu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80048CCC:
    ctx->pc = 0x80048CCCu;
    ctx->downcount -= 5;
    // 80048CCC: lis     r3, 25199
    ctx->gpr[3] = ((u32)(s32)(25199) << 16);

label_80048CD0:
    ctx->pc = 0x80048CD0u;
    // 80048CD0: li      r4, 63
    ctx->gpr[4] = (u32)(s32)(63);

label_80048CD4:
    ctx->pc = 0x80048CD4u;
    // 80048CD4: ori     r3, r3, 0x6479
    ctx->gpr[3] = ctx->gpr[3] | 0x6479u;

label_80048CD8:
    ctx->pc = 0x80048CD8u;
    // 80048CD8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80048CDC:
    ctx->pc = 0x80048CDCu;
    // 80048CDC: bl      0x80252AF0
    {
            ctx->lr = 0x80048CE0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80048CE0:
    ctx->pc = 0x80048CE0u;
    ctx->downcount -= 5;
    // 80048CE0: lis     r3, 25185
    ctx->gpr[3] = ((u32)(s32)(25185) << 16);

label_80048CE4:
    ctx->pc = 0x80048CE4u;
    // 80048CE4: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_80048CE8:
    ctx->pc = 0x80048CE8u;
    // 80048CE8: ori     r3, r3, 0x6E6D
    ctx->gpr[3] = ctx->gpr[3] | 0x6E6Du;

label_80048CEC:
    ctx->pc = 0x80048CECu;
    // 80048CEC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80048CF0:
    ctx->pc = 0x80048CF0u;
    // 80048CF0: bl      0x80252AF0
    {
            ctx->lr = 0x80048CF4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80048CF4:
    ctx->pc = 0x80048CF4u;
    ctx->downcount -= 5;
    // 80048CF4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048CF8:
    ctx->pc = 0x80048CF8u;
    // 80048CF8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80048CFC:
    ctx->pc = 0x80048CFCu;
    // 80048CFC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80048D00:
    ctx->pc = 0x80048D00u;
    // 80048D00: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80048D04:
    ctx->pc = 0x80048D04u;
    ctx->downcount -= 11;
    // 80048D04: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80048D08:
    ctx->pc = 0x80048D08u;
    // 80048D08: lwz     r9, 84(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(84);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048D0C:
    ctx->pc = 0x80048D0Cu;
    // 80048D0C: lwz     r10, 88(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(88);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80048D10:
    ctx->pc = 0x80048D10u;
    // 80048D10: addi    r8, r1, 8
    ctx->gpr[8] = ctx->gpr[1] + (u32)(s32)(8);

label_80048D14:
    ctx->pc = 0x80048D14u;
    // 80048D14: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80048D18:
    ctx->pc = 0x80048D18u;
    // 80048D18: stw     r10, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80048D1C:
    ctx->pc = 0x80048D1Cu;
    // 80048D1C: lwz     r0, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048D20:
    ctx->pc = 0x80048D20u;
    // 80048D20: add   r4, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80048D24:
    ctx->pc = 0x80048D24u;
    // 80048D24: or   r0, r4, r4
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80048D28:
    ctx->pc = 0x80048D28u;
    // 80048D28: cmpwi   r4, 0
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

label_80048D2C:
    ctx->pc = 0x80048D2Cu;
    // 80048D2C: bc    4, 0, 0x80048D34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048D34;
        }
    }

label_80048D30:
    ctx->pc = 0x80048D30u;
    ctx->downcount -= 1;
    // 80048D30: addi    r0, r4, 31
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(31);

label_80048D34:
    ctx->pc = 0x80048D34u;
    ctx->downcount -= 8;
    // 80048D34: srawi r0, r0, 5
    {
        u32 sh = 5u;
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

label_80048D38:
    ctx->pc = 0x80048D38u;
    // 80048D38: lwz     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048D3C:
    ctx->pc = 0x80048D3Cu;
    // 80048D3C: rlwinm r11, r0, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80048D40:
    ctx->pc = 0x80048D40u;
    // 80048D40: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_80048D44:
    ctx->pc = 0x80048D44u;
    // 80048D44: add   r9, r9, r11
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80048D48:
    ctx->pc = 0x80048D48u;
    // 80048D48: subf.   r4, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80048D4C:
    ctx->pc = 0x80048D4Cu;
    // 80048D4C: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80048D50:
    ctx->pc = 0x80048D50u;
    // 80048D50: bc    4, 0, 0x80048D6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048D6C;
        }
    }

label_80048D54:
    ctx->pc = 0x80048D54u;
    ctx->downcount -= 6;
    // 80048D54: addi    r0, r4, 32
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(32);

label_80048D58:
    ctx->pc = 0x80048D58u;
    // 80048D58: stw     r0, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048D5C:
    ctx->pc = 0x80048D5Cu;
    // 80048D5C: lwz     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048D60:
    ctx->pc = 0x80048D60u;
    // 80048D60: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

label_80048D64:
    ctx->pc = 0x80048D64u;
    // 80048D64: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80048D68:
    ctx->pc = 0x80048D68u;
    // 80048D68: b       0x80048D70
    {
            goto label_80048D70;
    }

label_80048D6C:
    ctx->pc = 0x80048D6Cu;
    ctx->downcount -= 1;
    // 80048D6C: stw     r4, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80048D70:
    ctx->pc = 0x80048D70u;
    ctx->downcount -= 15;
    // 80048D70: lwz     r9, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048D74:
    ctx->pc = 0x80048D74u;
    // 80048D74: lwz     r10, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80048D78:
    ctx->pc = 0x80048D78u;
    // 80048D78: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_80048D7C:
    ctx->pc = 0x80048D7Cu;
    // 80048D7C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80048D80:
    ctx->pc = 0x80048D80u;
    // 80048D80: stw     r9, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80048D84:
    ctx->pc = 0x80048D84u;
    // 80048D84: stw     r10, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80048D88:
    ctx->pc = 0x80048D88u;
    // 80048D88: lwz     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048D8C:
    ctx->pc = 0x80048D8Cu;
    // 80048D8C: lwz     r9, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048D90:
    ctx->pc = 0x80048D90u;
    // 80048D90: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048D94:
    ctx->pc = 0x80048D94u;
    // 80048D94: slw   r11, r11, r9
    {
        u32 sh = ctx->gpr[9] & 0x3Fu;
        ctx->gpr[11] = sh > 31 ? 0u : (ctx->gpr[11] << sh);
    }

label_80048D98:
    ctx->pc = 0x80048D98u;
    // 80048D98: stw     r11, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80048D9C:
    ctx->pc = 0x80048D9Cu;
    // 80048D9C: or   r9, r0, r0
    {
        ctx->gpr[9] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80048DA0:
    ctx->pc = 0x80048DA0u;
    // 80048DA0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048DA4:
    ctx->pc = 0x80048DA4u;
    // 80048DA4: and.   r9, r0, r11
    {
        ctx->gpr[9] = ctx->gpr[0] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80048DA8:
    ctx->pc = 0x80048DA8u;
    // 80048DA8: bc    4, 2, 0x80048DB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80048DB0;
        }
    }

label_80048DAC:
    ctx->pc = 0x80048DACu;
    ctx->downcount -= 1;
    // 80048DAC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80048DB0:
    ctx->pc = 0x80048DB0u;
    ctx->downcount -= 2;
    // 80048DB0: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80048DB4:
    ctx->pc = 0x80048DB4u;
    // 80048DB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80048DB8:
    ctx->pc = 0x80048DB8u;
    ctx->downcount -= 2;
    // 80048DB8: lwz     r3, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80048DBC:
    ctx->pc = 0x80048DBCu;
    // 80048DBC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80048DC0:
    ctx->pc = 0x80048DC0u;
    ctx->downcount -= 12;
    // 80048DC0: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048DC4:
    ctx->pc = 0x80048DC4u;
    // 80048DC4: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80048DC8:
    ctx->pc = 0x80048DC8u;
    // 80048DC8: addi    r11, r6, 12
    ctx->gpr[11] = ctx->gpr[6] + (u32)(s32)(12);

label_80048DCC:
    ctx->pc = 0x80048DCCu;
    // 80048DCC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80048DD0:
    ctx->pc = 0x80048DD0u;
    // 80048DD0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048DD4:
    ctx->pc = 0x80048DD4u;
    // 80048DD4: lwz     r9, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048DD8:
    ctx->pc = 0x80048DD8u;
    // 80048DD8: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048DDC:
    ctx->pc = 0x80048DDCu;
    // 80048DDC: stw     r9, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80048DE0:
    ctx->pc = 0x80048DE0u;
    // 80048DE0: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048DE4:
    ctx->pc = 0x80048DE4u;
    // 80048DE4: lwz     r9, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048DE8:
    ctx->pc = 0x80048DE8u;
    // 80048DE8: cmpwi   r9, 0
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

label_80048DEC:
    ctx->pc = 0x80048DECu;
    // 80048DEC: bc    12, 2, 0x80048DF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048DF4;
        }
    }

label_80048DF0:
    ctx->pc = 0x80048DF0u;
    ctx->downcount -= 1;
    // 80048DF0: addi    r10, r9, -112
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(-112);

label_80048DF4:
    ctx->pc = 0x80048DF4u;
    ctx->downcount -= 3;
    // 80048DF4: cmpwi   r10, 0
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

label_80048DF8:
    ctx->pc = 0x80048DF8u;
    // 80048DF8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80048DFC:
    ctx->pc = 0x80048DFCu;
    // 80048DFC: bc    12, 2, 0x80048E04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048E04;
        }
    }

label_80048E00:
    ctx->pc = 0x80048E00u;
    ctx->downcount -= 1;
    // 80048E00: addi    r8, r10, 112
    ctx->gpr[8] = ctx->gpr[10] + (u32)(s32)(112);

label_80048E04:
    ctx->pc = 0x80048E04u;
    ctx->downcount -= 7;
    // 80048E04: lwz     r0, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048E08:
    ctx->pc = 0x80048E08u;
    // 80048E08: cmpwi   cr7, r8, 0
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 0)) | (cr_bits << 0);
    }

label_80048E0C:
    ctx->pc = 0x80048E0Cu;
    // 80048E0C: addi    r10, r6, 20
    ctx->gpr[10] = ctx->gpr[6] + (u32)(s32)(20);

label_80048E10:
    ctx->pc = 0x80048E10u;
    // 80048E10: addi    r7, r6, 28
    ctx->gpr[7] = ctx->gpr[6] + (u32)(s32)(28);

label_80048E14:
    ctx->pc = 0x80048E14u;
    // 80048E14: cmpwi   r0, 0
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

label_80048E18:
    ctx->pc = 0x80048E18u;
    // 80048E18: addi    r5, r6, 36
    ctx->gpr[5] = ctx->gpr[6] + (u32)(s32)(36);

label_80048E1C:
    ctx->pc = 0x80048E1Cu;
    // 80048E1C: bc    12, 2, 0x80048E48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048E48;
        }
    }

label_80048E20:
    ctx->pc = 0x80048E20u;
    ctx->downcount -= 5;
    // 80048E20: or   r9, r0, r0
    {
        ctx->gpr[9] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80048E24:
    ctx->pc = 0x80048E24u;
    // 80048E24: lwz     r3, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80048E28:
    ctx->pc = 0x80048E28u;
    // 80048E28: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048E2C:
    ctx->pc = 0x80048E2Cu;
    // 80048E2C: cmpw    r0, r11
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

label_80048E30:
    ctx->pc = 0x80048E30u;
    // 80048E30: bc    12, 2, 0x80048E44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048E44;
        }
    }

label_80048E34:
    loop_80048E34(ctx);
    if (ctx->pc == 0x80048E44u) goto label_80048E44;
    return;
label_80048E38:
    ctx->pc = 0x80048E38u;
    // 80048E38: lwzu     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_80048E3C:
    // 80048E3C: cmpw    r0, r11
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

label_80048E40:
    // 80048E40: bc    4, 2, 0x80048E34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048E34u;
                return;
            }
            goto label_80048E34;
        }
    }

label_80048E44:
    ctx->pc = 0x80048E44u;
    ctx->downcount -= 1;
    // 80048E44: stw     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80048E48:
    ctx->pc = 0x80048E48u;
    ctx->downcount -= 1;
    // 80048E48: bc    12, 30, 0x80048E60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048E60;
        }
    }

label_80048E4C:
    ctx->pc = 0x80048E4Cu;
    ctx->downcount -= 5;
    // 80048E4C: stw     r8, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80048E50:
    ctx->pc = 0x80048E50u;
    // 80048E50: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048E54:
    ctx->pc = 0x80048E54u;
    // 80048E54: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048E58:
    ctx->pc = 0x80048E58u;
    // 80048E58: stw     r11, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80048E5C:
    ctx->pc = 0x80048E5Cu;
    // 80048E5C: b       0x80048E68
    {
            goto label_80048E68;
    }

label_80048E60:
    ctx->pc = 0x80048E60u;
    ctx->downcount -= 2;
    // 80048E60: stw     r8, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80048E64:
    ctx->pc = 0x80048E64u;
    // 80048E64: stw     r8, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80048E68:
    ctx->pc = 0x80048E68u;
    ctx->downcount -= 4;
    // 80048E68: lwz     r9, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048E6C:
    ctx->pc = 0x80048E6Cu;
    // 80048E6C: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80048E70:
    ctx->pc = 0x80048E70u;
    // 80048E70: cmpwi   r9, 0
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

label_80048E74:
    ctx->pc = 0x80048E74u;
    // 80048E74: bc    12, 2, 0x80048E7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048E7C;
        }
    }

label_80048E78:
    ctx->pc = 0x80048E78u;
    ctx->downcount -= 1;
    // 80048E78: addi    r11, r9, -112
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-112);

label_80048E7C:
    ctx->pc = 0x80048E7Cu;
    ctx->downcount -= 3;
    // 80048E7C: cmpwi   r11, 0
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

label_80048E80:
    ctx->pc = 0x80048E80u;
    // 80048E80: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80048E84:
    ctx->pc = 0x80048E84u;
    // 80048E84: bc    12, 2, 0x80048E8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048E8C;
        }
    }

label_80048E88:
    ctx->pc = 0x80048E88u;
    ctx->downcount -= 1;
    // 80048E88: addi    r8, r11, 112
    ctx->gpr[8] = ctx->gpr[11] + (u32)(s32)(112);

label_80048E8C:
    ctx->pc = 0x80048E8Cu;
    ctx->downcount -= 4;
    // 80048E8C: lwz     r0, 20(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048E90:
    ctx->pc = 0x80048E90u;
    // 80048E90: cmpwi   cr7, r8, 0
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 0)) | (cr_bits << 0);
    }

label_80048E94:
    ctx->pc = 0x80048E94u;
    // 80048E94: cmpwi   r0, 0
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

label_80048E98:
    ctx->pc = 0x80048E98u;
    // 80048E98: bc    12, 2, 0x80048EC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048EC4;
        }
    }

label_80048E9C:
    ctx->pc = 0x80048E9Cu;
    ctx->downcount -= 5;
    // 80048E9C: or   r9, r0, r0
    {
        ctx->gpr[9] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80048EA0:
    ctx->pc = 0x80048EA0u;
    // 80048EA0: lwz     r11, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80048EA4:
    ctx->pc = 0x80048EA4u;
    // 80048EA4: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048EA8:
    ctx->pc = 0x80048EA8u;
    // 80048EA8: cmpw    r0, r10
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[10]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80048EAC:
    ctx->pc = 0x80048EACu;
    // 80048EAC: bc    12, 2, 0x80048EC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048EC0;
        }
    }

label_80048EB0:
    loop_80048EB0(ctx);
    if (ctx->pc == 0x80048EC0u) goto label_80048EC0;
    return;
label_80048EB4:
    ctx->pc = 0x80048EB4u;
    // 80048EB4: lwzu     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_80048EB8:
    // 80048EB8: cmpw    r0, r10
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[10]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80048EBC:
    // 80048EBC: bc    4, 2, 0x80048EB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048EB0u;
                return;
            }
            goto label_80048EB0;
        }
    }

label_80048EC0:
    ctx->pc = 0x80048EC0u;
    ctx->downcount -= 1;
    // 80048EC0: stw     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80048EC4:
    ctx->pc = 0x80048EC4u;
    ctx->downcount -= 1;
    // 80048EC4: bc    12, 30, 0x80048EDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048EDC;
        }
    }

label_80048EC8:
    ctx->pc = 0x80048EC8u;
    ctx->downcount -= 5;
    // 80048EC8: stw     r8, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80048ECC:
    ctx->pc = 0x80048ECCu;
    // 80048ECC: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048ED0:
    ctx->pc = 0x80048ED0u;
    // 80048ED0: stw     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048ED4:
    ctx->pc = 0x80048ED4u;
    // 80048ED4: stw     r10, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80048ED8:
    ctx->pc = 0x80048ED8u;
    // 80048ED8: b       0x80048EE4
    {
            goto label_80048EE4;
    }

label_80048EDC:
    ctx->pc = 0x80048EDCu;
    ctx->downcount -= 2;
    // 80048EDC: stw     r8, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80048EE0:
    ctx->pc = 0x80048EE0u;
    // 80048EE0: stw     r8, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80048EE4:
    ctx->pc = 0x80048EE4u;
    ctx->downcount -= 4;
    // 80048EE4: lwz     r9, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048EE8:
    ctx->pc = 0x80048EE8u;
    // 80048EE8: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80048EEC:
    ctx->pc = 0x80048EECu;
    // 80048EEC: cmpwi   r9, 0
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

label_80048EF0:
    ctx->pc = 0x80048EF0u;
    // 80048EF0: bc    12, 2, 0x80048EF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048EF8;
        }
    }

label_80048EF4:
    ctx->pc = 0x80048EF4u;
    ctx->downcount -= 1;
    // 80048EF4: addi    r11, r9, -112
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-112);

label_80048EF8:
    ctx->pc = 0x80048EF8u;
    ctx->downcount -= 3;
    // 80048EF8: cmpwi   r11, 0
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

label_80048EFC:
    ctx->pc = 0x80048EFCu;
    // 80048EFC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80048F00:
    ctx->pc = 0x80048F00u;
    // 80048F00: bc    12, 2, 0x80048F08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048F08;
        }
    }

label_80048F04:
    ctx->pc = 0x80048F04u;
    ctx->downcount -= 1;
    // 80048F04: addi    r10, r11, 112
    ctx->gpr[10] = ctx->gpr[11] + (u32)(s32)(112);

label_80048F08:
    ctx->pc = 0x80048F08u;
    ctx->downcount -= 4;
    // 80048F08: lwz     r0, 28(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048F0C:
    ctx->pc = 0x80048F0Cu;
    // 80048F0C: cmpwi   cr7, r10, 0
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

label_80048F10:
    ctx->pc = 0x80048F10u;
    // 80048F10: cmpwi   r0, 0
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

label_80048F14:
    ctx->pc = 0x80048F14u;
    // 80048F14: bc    12, 2, 0x80048F40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048F40;
        }
    }

label_80048F18:
    ctx->pc = 0x80048F18u;
    ctx->downcount -= 5;
    // 80048F18: or   r9, r0, r0
    {
        ctx->gpr[9] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80048F1C:
    ctx->pc = 0x80048F1Cu;
    // 80048F1C: lwz     r11, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80048F20:
    ctx->pc = 0x80048F20u;
    // 80048F20: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048F24:
    ctx->pc = 0x80048F24u;
    // 80048F24: cmpw    r0, r7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80048F28:
    ctx->pc = 0x80048F28u;
    // 80048F28: bc    12, 2, 0x80048F3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048F3C;
        }
    }

label_80048F2C:
    loop_80048F2C(ctx);
    if (ctx->pc == 0x80048F3Cu) goto label_80048F3C;
    return;
label_80048F30:
    ctx->pc = 0x80048F30u;
    // 80048F30: lwzu     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_80048F34:
    // 80048F34: cmpw    r0, r7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80048F38:
    // 80048F38: bc    4, 2, 0x80048F2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048F2Cu;
                return;
            }
            goto label_80048F2C;
        }
    }

label_80048F3C:
    ctx->pc = 0x80048F3Cu;
    ctx->downcount -= 1;
    // 80048F3C: stw     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80048F40:
    ctx->pc = 0x80048F40u;
    ctx->downcount -= 1;
    // 80048F40: bc    12, 30, 0x80048F58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048F58;
        }
    }

label_80048F44:
    ctx->pc = 0x80048F44u;
    ctx->downcount -= 5;
    // 80048F44: stw     r10, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80048F48:
    ctx->pc = 0x80048F48u;
    // 80048F48: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048F4C:
    ctx->pc = 0x80048F4Cu;
    // 80048F4C: stw     r0, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048F50:
    ctx->pc = 0x80048F50u;
    // 80048F50: stw     r7, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80048F54:
    ctx->pc = 0x80048F54u;
    // 80048F54: b       0x80048F60
    {
            goto label_80048F60;
    }

label_80048F58:
    ctx->pc = 0x80048F58u;
    ctx->downcount -= 2;
    // 80048F58: stw     r10, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80048F5C:
    ctx->pc = 0x80048F5Cu;
    // 80048F5C: stw     r10, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80048F60:
    ctx->pc = 0x80048F60u;
    ctx->downcount -= 4;
    // 80048F60: lwz     r9, 36(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(36);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80048F64:
    ctx->pc = 0x80048F64u;
    // 80048F64: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80048F68:
    ctx->pc = 0x80048F68u;
    // 80048F68: cmpwi   r9, 0
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

label_80048F6C:
    ctx->pc = 0x80048F6Cu;
    // 80048F6C: bc    12, 2, 0x80048F74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048F74;
        }
    }

label_80048F70:
    ctx->pc = 0x80048F70u;
    ctx->downcount -= 1;
    // 80048F70: addi    r11, r9, -112
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-112);

label_80048F74:
    ctx->pc = 0x80048F74u;
    ctx->downcount -= 3;
    // 80048F74: cmpwi   r11, 0
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

label_80048F78:
    ctx->pc = 0x80048F78u;
    // 80048F78: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80048F7C:
    ctx->pc = 0x80048F7Cu;
    // 80048F7C: bc    12, 2, 0x80048F84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048F84;
        }
    }

label_80048F80:
    ctx->pc = 0x80048F80u;
    ctx->downcount -= 1;
    // 80048F80: addi    r10, r11, 112
    ctx->gpr[10] = ctx->gpr[11] + (u32)(s32)(112);

label_80048F84:
    ctx->pc = 0x80048F84u;
    ctx->downcount -= 4;
    // 80048F84: lwz     r0, 36(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048F88:
    ctx->pc = 0x80048F88u;
    // 80048F88: cmpwi   cr7, r10, 0
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

label_80048F8C:
    ctx->pc = 0x80048F8Cu;
    // 80048F8C: cmpwi   r0, 0
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

label_80048F90:
    ctx->pc = 0x80048F90u;
    // 80048F90: bc    12, 2, 0x80048FBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048FBC;
        }
    }

label_80048F94:
    ctx->pc = 0x80048F94u;
    ctx->downcount -= 5;
    // 80048F94: or   r9, r0, r0
    {
        ctx->gpr[9] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80048F98:
    ctx->pc = 0x80048F98u;
    // 80048F98: lwz     r11, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80048F9C:
    ctx->pc = 0x80048F9Cu;
    // 80048F9C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048FA0:
    ctx->pc = 0x80048FA0u;
    // 80048FA0: cmpw    r0, r5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80048FA4:
    ctx->pc = 0x80048FA4u;
    // 80048FA4: bc    12, 2, 0x80048FB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048FB8;
        }
    }

label_80048FA8:
    loop_80048FA8(ctx);
    if (ctx->pc == 0x80048FB8u) goto label_80048FB8;
    return;
label_80048FAC:
    ctx->pc = 0x80048FACu;
    // 80048FAC: lwzu     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_80048FB0:
    // 80048FB0: cmpw    r0, r5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80048FB4:
    // 80048FB4: bc    4, 2, 0x80048FA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80048FA8u;
                return;
            }
            goto label_80048FA8;
        }
    }

label_80048FB8:
    ctx->pc = 0x80048FB8u;
    ctx->downcount -= 1;
    // 80048FB8: stw     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80048FBC:
    ctx->pc = 0x80048FBCu;
    ctx->downcount -= 1;
    // 80048FBC: bc    12, 30, 0x80048FD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80048FD4;
        }
    }

label_80048FC0:
    ctx->pc = 0x80048FC0u;
    ctx->downcount -= 5;
    // 80048FC0: stw     r10, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80048FC4:
    ctx->pc = 0x80048FC4u;
    // 80048FC4: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048FC8:
    ctx->pc = 0x80048FC8u;
    // 80048FC8: stw     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048FCC:
    ctx->pc = 0x80048FCCu;
    // 80048FCC: stw     r5, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80048FD0:
    ctx->pc = 0x80048FD0u;
    // 80048FD0: b       0x80048FDC
    {
            goto label_80048FDC;
    }

label_80048FD4:
    ctx->pc = 0x80048FD4u;
    ctx->downcount -= 2;
    // 80048FD4: stw     r10, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80048FD8:
    ctx->pc = 0x80048FD8u;
    // 80048FD8: stw     r10, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80048FDC:
    ctx->pc = 0x80048FDCu;
    ctx->downcount -= 4;
    // 80048FDC: lwz     r0, 44(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80048FE0:
    ctx->pc = 0x80048FE0u;
    // 80048FE0: or   r3, r6, r6
    {
        ctx->gpr[3] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80048FE4:
    ctx->pc = 0x80048FE4u;
    // 80048FE4: stw     r0, 44(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048FE8:
    ctx->pc = 0x80048FE8u;
    // 80048FE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80048FEC:
    ctx->pc = 0x80048FECu;
    ctx->downcount -= 8;
    // 80048FEC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80048FF0:
    ctx->pc = 0x80048FF0u;
    // 80048FF0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80048FF4:
    ctx->pc = 0x80048FF4u;
    // 80048FF4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80048FF8:
    ctx->pc = 0x80048FF8u;
    // 80048FF8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80048FFC:
    ctx->pc = 0x80048FFCu;
    // 80048FFC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049000:
    ctx->pc = 0x80049000u;
    // 80049000: addi    r9, r9, 19992
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19992);

label_80049004:
    ctx->pc = 0x80049004u;
    // 80049004: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049008:
    ctx->pc = 0x80049008u;
    // 80049008: bl      0x8004B1A0
    {
            ctx->lr = 0x8004900Cu;
            goto label_8004B1A0;
    }

label_8004900C:
    ctx->pc = 0x8004900Cu;
    ctx->downcount -= 5;
    // 8004900C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049010:
    ctx->pc = 0x80049010u;
    // 80049010: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049014:
    ctx->pc = 0x80049014u;
    // 80049014: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049018:
    ctx->pc = 0x80049018u;
    // 80049018: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004901C:
    ctx->pc = 0x8004901Cu;
    ctx->downcount -= 8;
    // 8004901C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049020:
    ctx->pc = 0x80049020u;
    // 80049020: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049024:
    ctx->pc = 0x80049024u;
    // 80049024: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049028:
    ctx->pc = 0x80049028u;
    // 80049028: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004902C:
    ctx->pc = 0x8004902Cu;
    // 8004902C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049030:
    ctx->pc = 0x80049030u;
    // 80049030: addi    r9, r9, 19936
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19936);

label_80049034:
    ctx->pc = 0x80049034u;
    // 80049034: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049038:
    ctx->pc = 0x80049038u;
    // 80049038: bl      0x8004B1A0
    {
            ctx->lr = 0x8004903Cu;
            goto label_8004B1A0;
    }

label_8004903C:
    ctx->pc = 0x8004903Cu;
    ctx->downcount -= 5;
    // 8004903C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049040:
    ctx->pc = 0x80049040u;
    // 80049040: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049044:
    ctx->pc = 0x80049044u;
    // 80049044: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049048:
    ctx->pc = 0x80049048u;
    // 80049048: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004904C:
    ctx->pc = 0x8004904Cu;
    ctx->downcount -= 8;
    // 8004904C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049050:
    ctx->pc = 0x80049050u;
    // 80049050: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049054:
    ctx->pc = 0x80049054u;
    // 80049054: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049058:
    ctx->pc = 0x80049058u;
    // 80049058: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004905C:
    ctx->pc = 0x8004905Cu;
    // 8004905C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049060:
    ctx->pc = 0x80049060u;
    // 80049060: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_80049064:
    ctx->pc = 0x80049064u;
    // 80049064: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049068:
    ctx->pc = 0x80049068u;
    // 80049068: bl      0x8004B1A0
    {
            ctx->lr = 0x8004906Cu;
            goto label_8004B1A0;
    }

label_8004906C:
    ctx->pc = 0x8004906Cu;
    ctx->downcount -= 5;
    // 8004906C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049070:
    ctx->pc = 0x80049070u;
    // 80049070: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049074:
    ctx->pc = 0x80049074u;
    // 80049074: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049078:
    ctx->pc = 0x80049078u;
    // 80049078: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004907C:
    ctx->pc = 0x8004907Cu;
    ctx->downcount -= 8;
    // 8004907C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049080:
    ctx->pc = 0x80049080u;
    // 80049080: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049084:
    ctx->pc = 0x80049084u;
    // 80049084: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049088:
    ctx->pc = 0x80049088u;
    // 80049088: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004908C:
    ctx->pc = 0x8004908Cu;
    // 8004908C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049090:
    ctx->pc = 0x80049090u;
    // 80049090: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_80049094:
    ctx->pc = 0x80049094u;
    // 80049094: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049098:
    ctx->pc = 0x80049098u;
    // 80049098: bl      0x8004B1A0
    {
            ctx->lr = 0x8004909Cu;
            goto label_8004B1A0;
    }

label_8004909C:
    ctx->pc = 0x8004909Cu;
    ctx->downcount -= 5;
    // 8004909C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800490A0:
    ctx->pc = 0x800490A0u;
    // 800490A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800490A4:
    ctx->pc = 0x800490A4u;
    // 800490A4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800490A8:
    ctx->pc = 0x800490A8u;
    // 800490A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800490AC:
    ctx->pc = 0x800490ACu;
    ctx->downcount -= 8;
    // 800490AC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800490B0:
    ctx->pc = 0x800490B0u;
    // 800490B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800490B4:
    ctx->pc = 0x800490B4u;
    // 800490B4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800490B8:
    ctx->pc = 0x800490B8u;
    // 800490B8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800490BC:
    ctx->pc = 0x800490BCu;
    // 800490BC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800490C0:
    ctx->pc = 0x800490C0u;
    // 800490C0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_800490C4:
    ctx->pc = 0x800490C4u;
    // 800490C4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800490C8:
    ctx->pc = 0x800490C8u;
    // 800490C8: bl      0x8004B1A0
    {
            ctx->lr = 0x800490CCu;
            goto label_8004B1A0;
    }

label_800490CC:
    ctx->pc = 0x800490CCu;
    ctx->downcount -= 5;
    // 800490CC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800490D0:
    ctx->pc = 0x800490D0u;
    // 800490D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800490D4:
    ctx->pc = 0x800490D4u;
    // 800490D4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800490D8:
    ctx->pc = 0x800490D8u;
    // 800490D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800490DC:
    ctx->pc = 0x800490DCu;
    ctx->downcount -= 8;
    // 800490DC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800490E0:
    ctx->pc = 0x800490E0u;
    // 800490E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800490E4:
    ctx->pc = 0x800490E4u;
    // 800490E4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800490E8:
    ctx->pc = 0x800490E8u;
    // 800490E8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800490EC:
    ctx->pc = 0x800490ECu;
    // 800490EC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800490F0:
    ctx->pc = 0x800490F0u;
    // 800490F0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_800490F4:
    ctx->pc = 0x800490F4u;
    // 800490F4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800490F8:
    ctx->pc = 0x800490F8u;
    // 800490F8: bl      0x8004B1A0
    {
            ctx->lr = 0x800490FCu;
            goto label_8004B1A0;
    }

label_800490FC:
    ctx->pc = 0x800490FCu;
    ctx->downcount -= 5;
    // 800490FC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049100:
    ctx->pc = 0x80049100u;
    // 80049100: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049104:
    ctx->pc = 0x80049104u;
    // 80049104: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049108:
    ctx->pc = 0x80049108u;
    // 80049108: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004910C:
    ctx->pc = 0x8004910Cu;
    ctx->downcount -= 8;
    // 8004910C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049110:
    ctx->pc = 0x80049110u;
    // 80049110: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049114:
    ctx->pc = 0x80049114u;
    // 80049114: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049118:
    ctx->pc = 0x80049118u;
    // 80049118: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004911C:
    ctx->pc = 0x8004911Cu;
    // 8004911C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049120:
    ctx->pc = 0x80049120u;
    // 80049120: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_80049124:
    ctx->pc = 0x80049124u;
    // 80049124: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049128:
    ctx->pc = 0x80049128u;
    // 80049128: bl      0x8004B1A0
    {
            ctx->lr = 0x8004912Cu;
            goto label_8004B1A0;
    }

label_8004912C:
    ctx->pc = 0x8004912Cu;
    ctx->downcount -= 5;
    // 8004912C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049130:
    ctx->pc = 0x80049130u;
    // 80049130: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049134:
    ctx->pc = 0x80049134u;
    // 80049134: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049138:
    ctx->pc = 0x80049138u;
    // 80049138: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004913C:
    ctx->pc = 0x8004913Cu;
    ctx->downcount -= 8;
    // 8004913C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049140:
    ctx->pc = 0x80049140u;
    // 80049140: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049144:
    ctx->pc = 0x80049144u;
    // 80049144: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049148:
    ctx->pc = 0x80049148u;
    // 80049148: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004914C:
    ctx->pc = 0x8004914Cu;
    // 8004914C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049150:
    ctx->pc = 0x80049150u;
    // 80049150: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_80049154:
    ctx->pc = 0x80049154u;
    // 80049154: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049158:
    ctx->pc = 0x80049158u;
    // 80049158: bl      0x8004B1A0
    {
            ctx->lr = 0x8004915Cu;
            goto label_8004B1A0;
    }

label_8004915C:
    ctx->pc = 0x8004915Cu;
    ctx->downcount -= 5;
    // 8004915C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049160:
    ctx->pc = 0x80049160u;
    // 80049160: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049164:
    ctx->pc = 0x80049164u;
    // 80049164: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049168:
    ctx->pc = 0x80049168u;
    // 80049168: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004916C:
    ctx->pc = 0x8004916Cu;
    ctx->downcount -= 8;
    // 8004916C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049170:
    ctx->pc = 0x80049170u;
    // 80049170: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049174:
    ctx->pc = 0x80049174u;
    // 80049174: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049178:
    ctx->pc = 0x80049178u;
    // 80049178: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004917C:
    ctx->pc = 0x8004917Cu;
    // 8004917C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049180:
    ctx->pc = 0x80049180u;
    // 80049180: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_80049184:
    ctx->pc = 0x80049184u;
    // 80049184: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049188:
    ctx->pc = 0x80049188u;
    // 80049188: bl      0x8004B1A0
    {
            ctx->lr = 0x8004918Cu;
            goto label_8004B1A0;
    }

label_8004918C:
    ctx->pc = 0x8004918Cu;
    ctx->downcount -= 5;
    // 8004918C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049190:
    ctx->pc = 0x80049190u;
    // 80049190: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049194:
    ctx->pc = 0x80049194u;
    // 80049194: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049198:
    ctx->pc = 0x80049198u;
    // 80049198: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004919C:
    ctx->pc = 0x8004919Cu;
    ctx->downcount -= 8;
    // 8004919C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800491A0:
    ctx->pc = 0x800491A0u;
    // 800491A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800491A4:
    ctx->pc = 0x800491A4u;
    // 800491A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800491A8:
    ctx->pc = 0x800491A8u;
    // 800491A8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800491AC:
    ctx->pc = 0x800491ACu;
    // 800491AC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800491B0:
    ctx->pc = 0x800491B0u;
    // 800491B0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_800491B4:
    ctx->pc = 0x800491B4u;
    // 800491B4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800491B8:
    ctx->pc = 0x800491B8u;
    // 800491B8: bl      0x8004B1A0
    {
            ctx->lr = 0x800491BCu;
            goto label_8004B1A0;
    }

label_800491BC:
    ctx->pc = 0x800491BCu;
    ctx->downcount -= 5;
    // 800491BC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800491C0:
    ctx->pc = 0x800491C0u;
    // 800491C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800491C4:
    ctx->pc = 0x800491C4u;
    // 800491C4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800491C8:
    ctx->pc = 0x800491C8u;
    // 800491C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800491CC:
    ctx->pc = 0x800491CCu;
    ctx->downcount -= 8;
    // 800491CC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800491D0:
    ctx->pc = 0x800491D0u;
    // 800491D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800491D4:
    ctx->pc = 0x800491D4u;
    // 800491D4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800491D8:
    ctx->pc = 0x800491D8u;
    // 800491D8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800491DC:
    ctx->pc = 0x800491DCu;
    // 800491DC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800491E0:
    ctx->pc = 0x800491E0u;
    // 800491E0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_800491E4:
    ctx->pc = 0x800491E4u;
    // 800491E4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800491E8:
    ctx->pc = 0x800491E8u;
    // 800491E8: bl      0x8004B1A0
    {
            ctx->lr = 0x800491ECu;
            goto label_8004B1A0;
    }

label_800491EC:
    ctx->pc = 0x800491ECu;
    ctx->downcount -= 5;
    // 800491EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800491F0:
    ctx->pc = 0x800491F0u;
    // 800491F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800491F4:
    ctx->pc = 0x800491F4u;
    // 800491F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800491F8:
    ctx->pc = 0x800491F8u;
    // 800491F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800491FC:
    ctx->pc = 0x800491FCu;
    ctx->downcount -= 8;
    // 800491FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049200:
    ctx->pc = 0x80049200u;
    // 80049200: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049204:
    ctx->pc = 0x80049204u;
    // 80049204: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049208:
    ctx->pc = 0x80049208u;
    // 80049208: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004920C:
    ctx->pc = 0x8004920Cu;
    // 8004920C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049210:
    ctx->pc = 0x80049210u;
    // 80049210: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_80049214:
    ctx->pc = 0x80049214u;
    // 80049214: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049218:
    ctx->pc = 0x80049218u;
    // 80049218: bl      0x8004B1A0
    {
            ctx->lr = 0x8004921Cu;
            goto label_8004B1A0;
    }

label_8004921C:
    ctx->pc = 0x8004921Cu;
    ctx->downcount -= 5;
    // 8004921C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049220:
    ctx->pc = 0x80049220u;
    // 80049220: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049224:
    ctx->pc = 0x80049224u;
    // 80049224: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049228:
    ctx->pc = 0x80049228u;
    // 80049228: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004922C:
    ctx->pc = 0x8004922Cu;
    ctx->downcount -= 8;
    // 8004922C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049230:
    ctx->pc = 0x80049230u;
    // 80049230: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049234:
    ctx->pc = 0x80049234u;
    // 80049234: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049238:
    ctx->pc = 0x80049238u;
    // 80049238: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004923C:
    ctx->pc = 0x8004923Cu;
    // 8004923C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049240:
    ctx->pc = 0x80049240u;
    // 80049240: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_80049244:
    ctx->pc = 0x80049244u;
    // 80049244: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049248:
    ctx->pc = 0x80049248u;
    // 80049248: bl      0x8004B1A0
    {
            ctx->lr = 0x8004924Cu;
            goto label_8004B1A0;
    }

label_8004924C:
    ctx->pc = 0x8004924Cu;
    ctx->downcount -= 5;
    // 8004924C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049250:
    ctx->pc = 0x80049250u;
    // 80049250: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049254:
    ctx->pc = 0x80049254u;
    // 80049254: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049258:
    ctx->pc = 0x80049258u;
    // 80049258: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004925C:
    ctx->pc = 0x8004925Cu;
    ctx->downcount -= 8;
    // 8004925C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049260:
    ctx->pc = 0x80049260u;
    // 80049260: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049264:
    ctx->pc = 0x80049264u;
    // 80049264: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049268:
    ctx->pc = 0x80049268u;
    // 80049268: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004926C:
    ctx->pc = 0x8004926Cu;
    // 8004926C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049270:
    ctx->pc = 0x80049270u;
    // 80049270: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_80049274:
    ctx->pc = 0x80049274u;
    // 80049274: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049278:
    ctx->pc = 0x80049278u;
    // 80049278: bl      0x8004B1A0
    {
            ctx->lr = 0x8004927Cu;
            goto label_8004B1A0;
    }

label_8004927C:
    ctx->pc = 0x8004927Cu;
    ctx->downcount -= 5;
    // 8004927C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049280:
    ctx->pc = 0x80049280u;
    // 80049280: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049284:
    ctx->pc = 0x80049284u;
    // 80049284: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049288:
    ctx->pc = 0x80049288u;
    // 80049288: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004928C:
    ctx->pc = 0x8004928Cu;
    ctx->downcount -= 8;
    // 8004928C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049290:
    ctx->pc = 0x80049290u;
    // 80049290: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049294:
    ctx->pc = 0x80049294u;
    // 80049294: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049298:
    ctx->pc = 0x80049298u;
    // 80049298: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004929C:
    ctx->pc = 0x8004929Cu;
    // 8004929C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800492A0:
    ctx->pc = 0x800492A0u;
    // 800492A0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_800492A4:
    ctx->pc = 0x800492A4u;
    // 800492A4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800492A8:
    ctx->pc = 0x800492A8u;
    // 800492A8: bl      0x8004B1A0
    {
            ctx->lr = 0x800492ACu;
            goto label_8004B1A0;
    }

label_800492AC:
    ctx->pc = 0x800492ACu;
    ctx->downcount -= 5;
    // 800492AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800492B0:
    ctx->pc = 0x800492B0u;
    // 800492B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800492B4:
    ctx->pc = 0x800492B4u;
    // 800492B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800492B8:
    ctx->pc = 0x800492B8u;
    // 800492B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800492BC:
    ctx->pc = 0x800492BCu;
    ctx->downcount -= 8;
    // 800492BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800492C0:
    ctx->pc = 0x800492C0u;
    // 800492C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800492C4:
    ctx->pc = 0x800492C4u;
    // 800492C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800492C8:
    ctx->pc = 0x800492C8u;
    // 800492C8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800492CC:
    ctx->pc = 0x800492CCu;
    // 800492CC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800492D0:
    ctx->pc = 0x800492D0u;
    // 800492D0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_800492D4:
    ctx->pc = 0x800492D4u;
    // 800492D4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800492D8:
    ctx->pc = 0x800492D8u;
    // 800492D8: bl      0x8004B1A0
    {
            ctx->lr = 0x800492DCu;
            goto label_8004B1A0;
    }

label_800492DC:
    ctx->pc = 0x800492DCu;
    ctx->downcount -= 5;
    // 800492DC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800492E0:
    ctx->pc = 0x800492E0u;
    // 800492E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800492E4:
    ctx->pc = 0x800492E4u;
    // 800492E4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800492E8:
    ctx->pc = 0x800492E8u;
    // 800492E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800492EC:
    ctx->pc = 0x800492ECu;
    ctx->downcount -= 8;
    // 800492EC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800492F0:
    ctx->pc = 0x800492F0u;
    // 800492F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800492F4:
    ctx->pc = 0x800492F4u;
    // 800492F4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800492F8:
    ctx->pc = 0x800492F8u;
    // 800492F8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800492FC:
    ctx->pc = 0x800492FCu;
    // 800492FC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049300:
    ctx->pc = 0x80049300u;
    // 80049300: addi    r9, r9, 18752
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18752);

label_80049304:
    ctx->pc = 0x80049304u;
    // 80049304: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049308:
    ctx->pc = 0x80049308u;
    // 80049308: bl      0x8004BE94
    {
            ctx->lr = 0x8004930Cu;
            ctx->pc = 0x8004BE94u;
            return;
    }

label_8004930C:
    ctx->pc = 0x8004930Cu;
    ctx->downcount -= 5;
    // 8004930C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049310:
    ctx->pc = 0x80049310u;
    // 80049310: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049314:
    ctx->pc = 0x80049314u;
    // 80049314: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049318:
    ctx->pc = 0x80049318u;
    // 80049318: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004931C:
    ctx->pc = 0x8004931Cu;
    ctx->downcount -= 8;
    // 8004931C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049320:
    ctx->pc = 0x80049320u;
    // 80049320: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049324:
    ctx->pc = 0x80049324u;
    // 80049324: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049328:
    ctx->pc = 0x80049328u;
    // 80049328: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004932C:
    ctx->pc = 0x8004932Cu;
    // 8004932C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049330:
    ctx->pc = 0x80049330u;
    // 80049330: addi    r9, r9, 18752
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18752);

label_80049334:
    ctx->pc = 0x80049334u;
    // 80049334: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049338:
    ctx->pc = 0x80049338u;
    // 80049338: bl      0x8004BE94
    {
            ctx->lr = 0x8004933Cu;
            ctx->pc = 0x8004BE94u;
            return;
    }

label_8004933C:
    ctx->pc = 0x8004933Cu;
    ctx->downcount -= 5;
    // 8004933C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049340:
    ctx->pc = 0x80049340u;
    // 80049340: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049344:
    ctx->pc = 0x80049344u;
    // 80049344: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049348:
    ctx->pc = 0x80049348u;
    // 80049348: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004934C:
    ctx->pc = 0x8004934Cu;
    ctx->downcount -= 8;
    // 8004934C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049350:
    ctx->pc = 0x80049350u;
    // 80049350: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049354:
    ctx->pc = 0x80049354u;
    // 80049354: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049358:
    ctx->pc = 0x80049358u;
    // 80049358: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004935C:
    ctx->pc = 0x8004935Cu;
    // 8004935C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049360:
    ctx->pc = 0x80049360u;
    // 80049360: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_80049364:
    ctx->pc = 0x80049364u;
    // 80049364: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049368:
    ctx->pc = 0x80049368u;
    // 80049368: bl      0x8004B1A0
    {
            ctx->lr = 0x8004936Cu;
            goto label_8004B1A0;
    }

label_8004936C:
    ctx->pc = 0x8004936Cu;
    ctx->downcount -= 5;
    // 8004936C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049370:
    ctx->pc = 0x80049370u;
    // 80049370: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049374:
    ctx->pc = 0x80049374u;
    // 80049374: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049378:
    ctx->pc = 0x80049378u;
    // 80049378: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004937C:
    ctx->pc = 0x8004937Cu;
    ctx->downcount -= 8;
    // 8004937C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049380:
    ctx->pc = 0x80049380u;
    // 80049380: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049384:
    ctx->pc = 0x80049384u;
    // 80049384: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049388:
    ctx->pc = 0x80049388u;
    // 80049388: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004938C:
    ctx->pc = 0x8004938Cu;
    // 8004938C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049390:
    ctx->pc = 0x80049390u;
    // 80049390: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_80049394:
    ctx->pc = 0x80049394u;
    // 80049394: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049398:
    ctx->pc = 0x80049398u;
    // 80049398: bl      0x8004B1A0
    {
            ctx->lr = 0x8004939Cu;
            goto label_8004B1A0;
    }

label_8004939C:
    ctx->pc = 0x8004939Cu;
    ctx->downcount -= 5;
    // 8004939C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800493A0:
    ctx->pc = 0x800493A0u;
    // 800493A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800493A4:
    ctx->pc = 0x800493A4u;
    // 800493A4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800493A8:
    ctx->pc = 0x800493A8u;
    // 800493A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800493AC:
    ctx->pc = 0x800493ACu;
    ctx->downcount -= 8;
    // 800493AC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800493B0:
    ctx->pc = 0x800493B0u;
    // 800493B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800493B4:
    ctx->pc = 0x800493B4u;
    // 800493B4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800493B8:
    ctx->pc = 0x800493B8u;
    // 800493B8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800493BC:
    ctx->pc = 0x800493BCu;
    // 800493BC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800493C0:
    ctx->pc = 0x800493C0u;
    // 800493C0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_800493C4:
    ctx->pc = 0x800493C4u;
    // 800493C4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800493C8:
    ctx->pc = 0x800493C8u;
    // 800493C8: bl      0x8004B1A0
    {
            ctx->lr = 0x800493CCu;
            goto label_8004B1A0;
    }

label_800493CC:
    ctx->pc = 0x800493CCu;
    ctx->downcount -= 5;
    // 800493CC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800493D0:
    ctx->pc = 0x800493D0u;
    // 800493D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800493D4:
    ctx->pc = 0x800493D4u;
    // 800493D4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800493D8:
    ctx->pc = 0x800493D8u;
    // 800493D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800493DC:
    ctx->pc = 0x800493DCu;
    ctx->downcount -= 8;
    // 800493DC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800493E0:
    ctx->pc = 0x800493E0u;
    // 800493E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800493E4:
    ctx->pc = 0x800493E4u;
    // 800493E4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800493E8:
    ctx->pc = 0x800493E8u;
    // 800493E8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800493EC:
    ctx->pc = 0x800493ECu;
    // 800493EC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800493F0:
    ctx->pc = 0x800493F0u;
    // 800493F0: addi    r9, r9, 18408
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18408);

label_800493F4:
    ctx->pc = 0x800493F4u;
    // 800493F4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800493F8:
    ctx->pc = 0x800493F8u;
    // 800493F8: bl      0x8004B1A0
    {
            ctx->lr = 0x800493FCu;
            goto label_8004B1A0;
    }

label_800493FC:
    ctx->pc = 0x800493FCu;
    ctx->downcount -= 5;
    // 800493FC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049400:
    ctx->pc = 0x80049400u;
    // 80049400: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049404:
    ctx->pc = 0x80049404u;
    // 80049404: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049408:
    ctx->pc = 0x80049408u;
    // 80049408: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004940C:
    ctx->pc = 0x8004940Cu;
    ctx->downcount -= 8;
    // 8004940C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049410:
    ctx->pc = 0x80049410u;
    // 80049410: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049414:
    ctx->pc = 0x80049414u;
    // 80049414: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049418:
    ctx->pc = 0x80049418u;
    // 80049418: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004941C:
    ctx->pc = 0x8004941Cu;
    // 8004941C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049420:
    ctx->pc = 0x80049420u;
    // 80049420: addi    r9, r9, 18344
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18344);

label_80049424:
    ctx->pc = 0x80049424u;
    // 80049424: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049428:
    ctx->pc = 0x80049428u;
    // 80049428: bl      0x8004B1A0
    {
            ctx->lr = 0x8004942Cu;
            goto label_8004B1A0;
    }

label_8004942C:
    ctx->pc = 0x8004942Cu;
    ctx->downcount -= 5;
    // 8004942C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049430:
    ctx->pc = 0x80049430u;
    // 80049430: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049434:
    ctx->pc = 0x80049434u;
    // 80049434: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049438:
    ctx->pc = 0x80049438u;
    // 80049438: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004943C:
    ctx->pc = 0x8004943Cu;
    ctx->downcount -= 8;
    // 8004943C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049440:
    ctx->pc = 0x80049440u;
    // 80049440: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049444:
    ctx->pc = 0x80049444u;
    // 80049444: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049448:
    ctx->pc = 0x80049448u;
    // 80049448: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004944C:
    ctx->pc = 0x8004944Cu;
    // 8004944C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049450:
    ctx->pc = 0x80049450u;
    // 80049450: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_80049454:
    ctx->pc = 0x80049454u;
    // 80049454: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049458:
    ctx->pc = 0x80049458u;
    // 80049458: bl      0x8004B1A0
    {
            ctx->lr = 0x8004945Cu;
            goto label_8004B1A0;
    }

label_8004945C:
    ctx->pc = 0x8004945Cu;
    ctx->downcount -= 5;
    // 8004945C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049460:
    ctx->pc = 0x80049460u;
    // 80049460: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049464:
    ctx->pc = 0x80049464u;
    // 80049464: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049468:
    ctx->pc = 0x80049468u;
    // 80049468: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004946C:
    ctx->pc = 0x8004946Cu;
    ctx->downcount -= 8;
    // 8004946C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049470:
    ctx->pc = 0x80049470u;
    // 80049470: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049474:
    ctx->pc = 0x80049474u;
    // 80049474: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049478:
    ctx->pc = 0x80049478u;
    // 80049478: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004947C:
    ctx->pc = 0x8004947Cu;
    // 8004947C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049480:
    ctx->pc = 0x80049480u;
    // 80049480: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_80049484:
    ctx->pc = 0x80049484u;
    // 80049484: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049488:
    ctx->pc = 0x80049488u;
    // 80049488: bl      0x8004B1A0
    {
            ctx->lr = 0x8004948Cu;
            goto label_8004B1A0;
    }

label_8004948C:
    ctx->pc = 0x8004948Cu;
    ctx->downcount -= 5;
    // 8004948C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049490:
    ctx->pc = 0x80049490u;
    // 80049490: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049494:
    ctx->pc = 0x80049494u;
    // 80049494: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049498:
    ctx->pc = 0x80049498u;
    // 80049498: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004949C:
    ctx->pc = 0x8004949Cu;
    ctx->downcount -= 8;
    // 8004949C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800494A0:
    ctx->pc = 0x800494A0u;
    // 800494A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800494A4:
    ctx->pc = 0x800494A4u;
    // 800494A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800494A8:
    ctx->pc = 0x800494A8u;
    // 800494A8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800494AC:
    ctx->pc = 0x800494ACu;
    // 800494AC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800494B0:
    ctx->pc = 0x800494B0u;
    // 800494B0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_800494B4:
    ctx->pc = 0x800494B4u;
    // 800494B4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800494B8:
    ctx->pc = 0x800494B8u;
    // 800494B8: bl      0x8004B1A0
    {
            ctx->lr = 0x800494BCu;
            goto label_8004B1A0;
    }

label_800494BC:
    ctx->pc = 0x800494BCu;
    ctx->downcount -= 5;
    // 800494BC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800494C0:
    ctx->pc = 0x800494C0u;
    // 800494C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800494C4:
    ctx->pc = 0x800494C4u;
    // 800494C4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800494C8:
    ctx->pc = 0x800494C8u;
    // 800494C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800494CC:
    ctx->pc = 0x800494CCu;
    ctx->downcount -= 8;
    // 800494CC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800494D0:
    ctx->pc = 0x800494D0u;
    // 800494D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800494D4:
    ctx->pc = 0x800494D4u;
    // 800494D4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800494D8:
    ctx->pc = 0x800494D8u;
    // 800494D8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800494DC:
    ctx->pc = 0x800494DCu;
    // 800494DC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800494E0:
    ctx->pc = 0x800494E0u;
    // 800494E0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_800494E4:
    ctx->pc = 0x800494E4u;
    // 800494E4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800494E8:
    ctx->pc = 0x800494E8u;
    // 800494E8: bl      0x8004B1A0
    {
            ctx->lr = 0x800494ECu;
            goto label_8004B1A0;
    }

label_800494EC:
    ctx->pc = 0x800494ECu;
    ctx->downcount -= 5;
    // 800494EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800494F0:
    ctx->pc = 0x800494F0u;
    // 800494F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800494F4:
    ctx->pc = 0x800494F4u;
    // 800494F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800494F8:
    ctx->pc = 0x800494F8u;
    // 800494F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800494FC:
    ctx->pc = 0x800494FCu;
    ctx->downcount -= 8;
    // 800494FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049500:
    ctx->pc = 0x80049500u;
    // 80049500: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049504:
    ctx->pc = 0x80049504u;
    // 80049504: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049508:
    ctx->pc = 0x80049508u;
    // 80049508: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004950C:
    ctx->pc = 0x8004950Cu;
    // 8004950C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049510:
    ctx->pc = 0x80049510u;
    // 80049510: addi    r9, r9, 18000
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18000);

label_80049514:
    ctx->pc = 0x80049514u;
    // 80049514: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049518:
    ctx->pc = 0x80049518u;
    // 80049518: bl      0x8004B1A0
    {
            ctx->lr = 0x8004951Cu;
            goto label_8004B1A0;
    }

label_8004951C:
    ctx->pc = 0x8004951Cu;
    ctx->downcount -= 5;
    // 8004951C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049520:
    ctx->pc = 0x80049520u;
    // 80049520: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049524:
    ctx->pc = 0x80049524u;
    // 80049524: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049528:
    ctx->pc = 0x80049528u;
    // 80049528: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004952C:
    ctx->pc = 0x8004952Cu;
    ctx->downcount -= 8;
    // 8004952C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049530:
    ctx->pc = 0x80049530u;
    // 80049530: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049534:
    ctx->pc = 0x80049534u;
    // 80049534: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049538:
    ctx->pc = 0x80049538u;
    // 80049538: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004953C:
    ctx->pc = 0x8004953Cu;
    // 8004953C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049540:
    ctx->pc = 0x80049540u;
    // 80049540: addi    r9, r9, 17944
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17944);

label_80049544:
    ctx->pc = 0x80049544u;
    // 80049544: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049548:
    ctx->pc = 0x80049548u;
    // 80049548: bl      0x8004B1A0
    {
            ctx->lr = 0x8004954Cu;
            goto label_8004B1A0;
    }

label_8004954C:
    ctx->pc = 0x8004954Cu;
    ctx->downcount -= 5;
    // 8004954C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049550:
    ctx->pc = 0x80049550u;
    // 80049550: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049554:
    ctx->pc = 0x80049554u;
    // 80049554: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049558:
    ctx->pc = 0x80049558u;
    // 80049558: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004955C:
    ctx->pc = 0x8004955Cu;
    ctx->downcount -= 8;
    // 8004955C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049560:
    ctx->pc = 0x80049560u;
    // 80049560: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049564:
    ctx->pc = 0x80049564u;
    // 80049564: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049568:
    ctx->pc = 0x80049568u;
    // 80049568: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004956C:
    ctx->pc = 0x8004956Cu;
    // 8004956C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049570:
    ctx->pc = 0x80049570u;
    // 80049570: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_80049574:
    ctx->pc = 0x80049574u;
    // 80049574: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049578:
    ctx->pc = 0x80049578u;
    // 80049578: bl      0x8004B1A0
    {
            ctx->lr = 0x8004957Cu;
            goto label_8004B1A0;
    }

label_8004957C:
    ctx->pc = 0x8004957Cu;
    ctx->downcount -= 5;
    // 8004957C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049580:
    ctx->pc = 0x80049580u;
    // 80049580: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049584:
    ctx->pc = 0x80049584u;
    // 80049584: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049588:
    ctx->pc = 0x80049588u;
    // 80049588: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004958C:
    ctx->pc = 0x8004958Cu;
    ctx->downcount -= 8;
    // 8004958C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049590:
    ctx->pc = 0x80049590u;
    // 80049590: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049594:
    ctx->pc = 0x80049594u;
    // 80049594: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049598:
    ctx->pc = 0x80049598u;
    // 80049598: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004959C:
    ctx->pc = 0x8004959Cu;
    // 8004959C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800495A0:
    ctx->pc = 0x800495A0u;
    // 800495A0: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_800495A4:
    ctx->pc = 0x800495A4u;
    // 800495A4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800495A8:
    ctx->pc = 0x800495A8u;
    // 800495A8: bl      0x8004B1A0
    {
            ctx->lr = 0x800495ACu;
            goto label_8004B1A0;
    }

label_800495AC:
    ctx->pc = 0x800495ACu;
    ctx->downcount -= 5;
    // 800495AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800495B0:
    ctx->pc = 0x800495B0u;
    // 800495B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800495B4:
    ctx->pc = 0x800495B4u;
    // 800495B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800495B8:
    ctx->pc = 0x800495B8u;
    // 800495B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800495BC:
    ctx->pc = 0x800495BCu;
    ctx->downcount -= 8;
    // 800495BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800495C0:
    ctx->pc = 0x800495C0u;
    // 800495C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800495C4:
    ctx->pc = 0x800495C4u;
    // 800495C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800495C8:
    ctx->pc = 0x800495C8u;
    // 800495C8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800495CC:
    ctx->pc = 0x800495CCu;
    // 800495CC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800495D0:
    ctx->pc = 0x800495D0u;
    // 800495D0: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_800495D4:
    ctx->pc = 0x800495D4u;
    // 800495D4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800495D8:
    ctx->pc = 0x800495D8u;
    // 800495D8: bl      0x8004B1A0
    {
            ctx->lr = 0x800495DCu;
            goto label_8004B1A0;
    }

label_800495DC:
    ctx->pc = 0x800495DCu;
    ctx->downcount -= 5;
    // 800495DC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800495E0:
    ctx->pc = 0x800495E0u;
    // 800495E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800495E4:
    ctx->pc = 0x800495E4u;
    // 800495E4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800495E8:
    ctx->pc = 0x800495E8u;
    // 800495E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800495EC:
    ctx->pc = 0x800495ECu;
    ctx->downcount -= 8;
    // 800495EC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800495F0:
    ctx->pc = 0x800495F0u;
    // 800495F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800495F4:
    ctx->pc = 0x800495F4u;
    // 800495F4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800495F8:
    ctx->pc = 0x800495F8u;
    // 800495F8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800495FC:
    ctx->pc = 0x800495FCu;
    // 800495FC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049600:
    ctx->pc = 0x80049600u;
    // 80049600: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_80049604:
    ctx->pc = 0x80049604u;
    // 80049604: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049608:
    ctx->pc = 0x80049608u;
    // 80049608: bl      0x8004B1A0
    {
            ctx->lr = 0x8004960Cu;
            goto label_8004B1A0;
    }

label_8004960C:
    ctx->pc = 0x8004960Cu;
    ctx->downcount -= 5;
    // 8004960C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049610:
    ctx->pc = 0x80049610u;
    // 80049610: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049614:
    ctx->pc = 0x80049614u;
    // 80049614: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049618:
    ctx->pc = 0x80049618u;
    // 80049618: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004961C:
    ctx->pc = 0x8004961Cu;
    ctx->downcount -= 8;
    // 8004961C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049620:
    ctx->pc = 0x80049620u;
    // 80049620: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049624:
    ctx->pc = 0x80049624u;
    // 80049624: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049628:
    ctx->pc = 0x80049628u;
    // 80049628: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004962C:
    ctx->pc = 0x8004962Cu;
    // 8004962C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049630:
    ctx->pc = 0x80049630u;
    // 80049630: addi    r9, r9, 17616
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17616);

label_80049634:
    ctx->pc = 0x80049634u;
    // 80049634: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049638:
    ctx->pc = 0x80049638u;
    // 80049638: bl      0x8004B1A0
    {
            ctx->lr = 0x8004963Cu;
            goto label_8004B1A0;
    }

label_8004963C:
    ctx->pc = 0x8004963Cu;
    ctx->downcount -= 5;
    // 8004963C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049640:
    ctx->pc = 0x80049640u;
    // 80049640: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049644:
    ctx->pc = 0x80049644u;
    // 80049644: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049648:
    ctx->pc = 0x80049648u;
    // 80049648: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004964C:
    ctx->pc = 0x8004964Cu;
    ctx->downcount -= 8;
    // 8004964C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049650:
    ctx->pc = 0x80049650u;
    // 80049650: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049654:
    ctx->pc = 0x80049654u;
    // 80049654: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049658:
    ctx->pc = 0x80049658u;
    // 80049658: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004965C:
    ctx->pc = 0x8004965Cu;
    // 8004965C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049660:
    ctx->pc = 0x80049660u;
    // 80049660: addi    r9, r9, 17560
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17560);

label_80049664:
    ctx->pc = 0x80049664u;
    // 80049664: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049668:
    ctx->pc = 0x80049668u;
    // 80049668: bl      0x8004B1A0
    {
            ctx->lr = 0x8004966Cu;
            goto label_8004B1A0;
    }

label_8004966C:
    ctx->pc = 0x8004966Cu;
    ctx->downcount -= 5;
    // 8004966C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049670:
    ctx->pc = 0x80049670u;
    // 80049670: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049674:
    ctx->pc = 0x80049674u;
    // 80049674: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049678:
    ctx->pc = 0x80049678u;
    // 80049678: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004967C:
    ctx->pc = 0x8004967Cu;
    ctx->downcount -= 8;
    // 8004967C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049680:
    ctx->pc = 0x80049680u;
    // 80049680: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049684:
    ctx->pc = 0x80049684u;
    // 80049684: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049688:
    ctx->pc = 0x80049688u;
    // 80049688: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004968C:
    ctx->pc = 0x8004968Cu;
    // 8004968C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049690:
    ctx->pc = 0x80049690u;
    // 80049690: addi    r9, r9, 17504
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17504);

label_80049694:
    ctx->pc = 0x80049694u;
    // 80049694: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049698:
    ctx->pc = 0x80049698u;
    // 80049698: bl      0x8004B1A0
    {
            ctx->lr = 0x8004969Cu;
            goto label_8004B1A0;
    }

label_8004969C:
    ctx->pc = 0x8004969Cu;
    ctx->downcount -= 5;
    // 8004969C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800496A0:
    ctx->pc = 0x800496A0u;
    // 800496A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800496A4:
    ctx->pc = 0x800496A4u;
    // 800496A4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800496A8:
    ctx->pc = 0x800496A8u;
    // 800496A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800496AC:
    ctx->pc = 0x800496ACu;
    ctx->downcount -= 8;
    // 800496AC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800496B0:
    ctx->pc = 0x800496B0u;
    // 800496B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800496B4:
    ctx->pc = 0x800496B4u;
    // 800496B4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800496B8:
    ctx->pc = 0x800496B8u;
    // 800496B8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800496BC:
    ctx->pc = 0x800496BCu;
    // 800496BC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800496C0:
    ctx->pc = 0x800496C0u;
    // 800496C0: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_800496C4:
    ctx->pc = 0x800496C4u;
    // 800496C4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800496C8:
    ctx->pc = 0x800496C8u;
    // 800496C8: bl      0x8004B1A0
    {
            ctx->lr = 0x800496CCu;
            goto label_8004B1A0;
    }

label_800496CC:
    ctx->pc = 0x800496CCu;
    ctx->downcount -= 5;
    // 800496CC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800496D0:
    ctx->pc = 0x800496D0u;
    // 800496D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800496D4:
    ctx->pc = 0x800496D4u;
    // 800496D4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800496D8:
    ctx->pc = 0x800496D8u;
    // 800496D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800496DC:
    ctx->pc = 0x800496DCu;
    ctx->downcount -= 8;
    // 800496DC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800496E0:
    ctx->pc = 0x800496E0u;
    // 800496E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800496E4:
    ctx->pc = 0x800496E4u;
    // 800496E4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800496E8:
    ctx->pc = 0x800496E8u;
    // 800496E8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800496EC:
    ctx->pc = 0x800496ECu;
    // 800496EC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800496F0:
    ctx->pc = 0x800496F0u;
    // 800496F0: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_800496F4:
    ctx->pc = 0x800496F4u;
    // 800496F4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800496F8:
    ctx->pc = 0x800496F8u;
    // 800496F8: bl      0x8004B1A0
    {
            ctx->lr = 0x800496FCu;
            goto label_8004B1A0;
    }

label_800496FC:
    ctx->pc = 0x800496FCu;
    ctx->downcount -= 5;
    // 800496FC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049700:
    ctx->pc = 0x80049700u;
    // 80049700: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049704:
    ctx->pc = 0x80049704u;
    // 80049704: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049708:
    ctx->pc = 0x80049708u;
    // 80049708: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004970C:
    ctx->pc = 0x8004970Cu;
    ctx->downcount -= 8;
    // 8004970C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049710:
    ctx->pc = 0x80049710u;
    // 80049710: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049714:
    ctx->pc = 0x80049714u;
    // 80049714: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049718:
    ctx->pc = 0x80049718u;
    // 80049718: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004971C:
    ctx->pc = 0x8004971Cu;
    // 8004971C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049720:
    ctx->pc = 0x80049720u;
    // 80049720: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_80049724:
    ctx->pc = 0x80049724u;
    // 80049724: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049728:
    ctx->pc = 0x80049728u;
    // 80049728: bl      0x8004B1A0
    {
            ctx->lr = 0x8004972Cu;
            goto label_8004B1A0;
    }

label_8004972C:
    ctx->pc = 0x8004972Cu;
    ctx->downcount -= 5;
    // 8004972C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049730:
    ctx->pc = 0x80049730u;
    // 80049730: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049734:
    ctx->pc = 0x80049734u;
    // 80049734: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049738:
    ctx->pc = 0x80049738u;
    // 80049738: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004973C:
    ctx->pc = 0x8004973Cu;
    ctx->downcount -= 8;
    // 8004973C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049740:
    ctx->pc = 0x80049740u;
    // 80049740: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049744:
    ctx->pc = 0x80049744u;
    // 80049744: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049748:
    ctx->pc = 0x80049748u;
    // 80049748: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004974C:
    ctx->pc = 0x8004974Cu;
    // 8004974C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049750:
    ctx->pc = 0x80049750u;
    // 80049750: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_80049754:
    ctx->pc = 0x80049754u;
    // 80049754: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049758:
    ctx->pc = 0x80049758u;
    // 80049758: bl      0x8004B1A0
    {
            ctx->lr = 0x8004975Cu;
            goto label_8004B1A0;
    }

label_8004975C:
    ctx->pc = 0x8004975Cu;
    ctx->downcount -= 5;
    // 8004975C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049760:
    ctx->pc = 0x80049760u;
    // 80049760: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049764:
    ctx->pc = 0x80049764u;
    // 80049764: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049768:
    ctx->pc = 0x80049768u;
    // 80049768: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004976C:
    ctx->pc = 0x8004976Cu;
    ctx->downcount -= 8;
    // 8004976C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049770:
    ctx->pc = 0x80049770u;
    // 80049770: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049774:
    ctx->pc = 0x80049774u;
    // 80049774: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049778:
    ctx->pc = 0x80049778u;
    // 80049778: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004977C:
    ctx->pc = 0x8004977Cu;
    // 8004977C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049780:
    ctx->pc = 0x80049780u;
    // 80049780: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_80049784:
    ctx->pc = 0x80049784u;
    // 80049784: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049788:
    ctx->pc = 0x80049788u;
    // 80049788: bl      0x8004B1A0
    {
            ctx->lr = 0x8004978Cu;
            goto label_8004B1A0;
    }

label_8004978C:
    ctx->pc = 0x8004978Cu;
    ctx->downcount -= 5;
    // 8004978C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049790:
    ctx->pc = 0x80049790u;
    // 80049790: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049794:
    ctx->pc = 0x80049794u;
    // 80049794: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049798:
    ctx->pc = 0x80049798u;
    // 80049798: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004979C:
    ctx->pc = 0x8004979Cu;
    ctx->downcount -= 8;
    // 8004979C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800497A0:
    ctx->pc = 0x800497A0u;
    // 800497A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800497A4:
    ctx->pc = 0x800497A4u;
    // 800497A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800497A8:
    ctx->pc = 0x800497A8u;
    // 800497A8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800497AC:
    ctx->pc = 0x800497ACu;
    // 800497AC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800497B0:
    ctx->pc = 0x800497B0u;
    // 800497B0: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_800497B4:
    ctx->pc = 0x800497B4u;
    // 800497B4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800497B8:
    ctx->pc = 0x800497B8u;
    // 800497B8: bl      0x8004B1A0
    {
            ctx->lr = 0x800497BCu;
            goto label_8004B1A0;
    }

label_800497BC:
    ctx->pc = 0x800497BCu;
    ctx->downcount -= 5;
    // 800497BC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800497C0:
    ctx->pc = 0x800497C0u;
    // 800497C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800497C4:
    ctx->pc = 0x800497C4u;
    // 800497C4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800497C8:
    ctx->pc = 0x800497C8u;
    // 800497C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800497CC:
    ctx->pc = 0x800497CCu;
    ctx->downcount -= 8;
    // 800497CC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800497D0:
    ctx->pc = 0x800497D0u;
    // 800497D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800497D4:
    ctx->pc = 0x800497D4u;
    // 800497D4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800497D8:
    ctx->pc = 0x800497D8u;
    // 800497D8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800497DC:
    ctx->pc = 0x800497DCu;
    // 800497DC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800497E0:
    ctx->pc = 0x800497E0u;
    // 800497E0: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_800497E4:
    ctx->pc = 0x800497E4u;
    // 800497E4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800497E8:
    ctx->pc = 0x800497E8u;
    // 800497E8: bl      0x8004B1A0
    {
            ctx->lr = 0x800497ECu;
            goto label_8004B1A0;
    }

label_800497EC:
    ctx->pc = 0x800497ECu;
    ctx->downcount -= 5;
    // 800497EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800497F0:
    ctx->pc = 0x800497F0u;
    // 800497F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800497F4:
    ctx->pc = 0x800497F4u;
    // 800497F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800497F8:
    ctx->pc = 0x800497F8u;
    // 800497F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800497FC:
    ctx->pc = 0x800497FCu;
    ctx->downcount -= 8;
    // 800497FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049800:
    ctx->pc = 0x80049800u;
    // 80049800: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049804:
    ctx->pc = 0x80049804u;
    // 80049804: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049808:
    ctx->pc = 0x80049808u;
    // 80049808: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004980C:
    ctx->pc = 0x8004980Cu;
    // 8004980C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049810:
    ctx->pc = 0x80049810u;
    // 80049810: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_80049814:
    ctx->pc = 0x80049814u;
    // 80049814: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049818:
    ctx->pc = 0x80049818u;
    // 80049818: bl      0x8004B1A0
    {
            ctx->lr = 0x8004981Cu;
            goto label_8004B1A0;
    }

label_8004981C:
    ctx->pc = 0x8004981Cu;
    ctx->downcount -= 5;
    // 8004981C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049820:
    ctx->pc = 0x80049820u;
    // 80049820: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049824:
    ctx->pc = 0x80049824u;
    // 80049824: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049828:
    ctx->pc = 0x80049828u;
    // 80049828: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004982C:
    ctx->pc = 0x8004982Cu;
    ctx->downcount -= 8;
    // 8004982C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049830:
    ctx->pc = 0x80049830u;
    // 80049830: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049834:
    ctx->pc = 0x80049834u;
    // 80049834: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049838:
    ctx->pc = 0x80049838u;
    // 80049838: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004983C:
    ctx->pc = 0x8004983Cu;
    // 8004983C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049840:
    ctx->pc = 0x80049840u;
    // 80049840: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_80049844:
    ctx->pc = 0x80049844u;
    // 80049844: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049848:
    ctx->pc = 0x80049848u;
    // 80049848: bl      0x8004B1A0
    {
            ctx->lr = 0x8004984Cu;
            goto label_8004B1A0;
    }

label_8004984C:
    ctx->pc = 0x8004984Cu;
    ctx->downcount -= 5;
    // 8004984C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049850:
    ctx->pc = 0x80049850u;
    // 80049850: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049854:
    ctx->pc = 0x80049854u;
    // 80049854: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049858:
    ctx->pc = 0x80049858u;
    // 80049858: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004985C:
    ctx->pc = 0x8004985Cu;
    ctx->downcount -= 8;
    // 8004985C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049860:
    ctx->pc = 0x80049860u;
    // 80049860: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049864:
    ctx->pc = 0x80049864u;
    // 80049864: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049868:
    ctx->pc = 0x80049868u;
    // 80049868: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004986C:
    ctx->pc = 0x8004986Cu;
    // 8004986C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049870:
    ctx->pc = 0x80049870u;
    // 80049870: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_80049874:
    ctx->pc = 0x80049874u;
    // 80049874: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049878:
    ctx->pc = 0x80049878u;
    // 80049878: bl      0x8004B1A0
    {
            ctx->lr = 0x8004987Cu;
            goto label_8004B1A0;
    }

label_8004987C:
    ctx->pc = 0x8004987Cu;
    ctx->downcount -= 5;
    // 8004987C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049880:
    ctx->pc = 0x80049880u;
    // 80049880: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049884:
    ctx->pc = 0x80049884u;
    // 80049884: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049888:
    ctx->pc = 0x80049888u;
    // 80049888: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004988C:
    ctx->pc = 0x8004988Cu;
    ctx->downcount -= 8;
    // 8004988C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049890:
    ctx->pc = 0x80049890u;
    // 80049890: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049894:
    ctx->pc = 0x80049894u;
    // 80049894: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049898:
    ctx->pc = 0x80049898u;
    // 80049898: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004989C:
    ctx->pc = 0x8004989Cu;
    // 8004989C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800498A0:
    ctx->pc = 0x800498A0u;
    // 800498A0: addi    r9, r9, 16728
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16728);

label_800498A4:
    ctx->pc = 0x800498A4u;
    // 800498A4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800498A8:
    ctx->pc = 0x800498A8u;
    // 800498A8: bl      0x8004B1A0
    {
            ctx->lr = 0x800498ACu;
            goto label_8004B1A0;
    }

label_800498AC:
    ctx->pc = 0x800498ACu;
    ctx->downcount -= 5;
    // 800498AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800498B0:
    ctx->pc = 0x800498B0u;
    // 800498B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800498B4:
    ctx->pc = 0x800498B4u;
    // 800498B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800498B8:
    ctx->pc = 0x800498B8u;
    // 800498B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800498BC:
    ctx->pc = 0x800498BCu;
    ctx->downcount -= 8;
    // 800498BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800498C0:
    ctx->pc = 0x800498C0u;
    // 800498C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800498C4:
    ctx->pc = 0x800498C4u;
    // 800498C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800498C8:
    ctx->pc = 0x800498C8u;
    // 800498C8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800498CC:
    ctx->pc = 0x800498CCu;
    // 800498CC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800498D0:
    ctx->pc = 0x800498D0u;
    // 800498D0: addi    r9, r9, 16672
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16672);

label_800498D4:
    ctx->pc = 0x800498D4u;
    // 800498D4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800498D8:
    ctx->pc = 0x800498D8u;
    // 800498D8: bl      0x8004B1A0
    {
            ctx->lr = 0x800498DCu;
            goto label_8004B1A0;
    }

label_800498DC:
    ctx->pc = 0x800498DCu;
    ctx->downcount -= 5;
    // 800498DC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800498E0:
    ctx->pc = 0x800498E0u;
    // 800498E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800498E4:
    ctx->pc = 0x800498E4u;
    // 800498E4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800498E8:
    ctx->pc = 0x800498E8u;
    // 800498E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800498EC:
    ctx->pc = 0x800498ECu;
    ctx->downcount -= 8;
    // 800498EC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800498F0:
    ctx->pc = 0x800498F0u;
    // 800498F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800498F4:
    ctx->pc = 0x800498F4u;
    // 800498F4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800498F8:
    ctx->pc = 0x800498F8u;
    // 800498F8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800498FC:
    ctx->pc = 0x800498FCu;
    // 800498FC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049900:
    ctx->pc = 0x80049900u;
    // 80049900: addi    r9, r9, 16616
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16616);

label_80049904:
    ctx->pc = 0x80049904u;
    // 80049904: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049908:
    ctx->pc = 0x80049908u;
    // 80049908: bl      0x8004B1A0
    {
            ctx->lr = 0x8004990Cu;
            goto label_8004B1A0;
    }

label_8004990C:
    ctx->pc = 0x8004990Cu;
    ctx->downcount -= 5;
    // 8004990C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049910:
    ctx->pc = 0x80049910u;
    // 80049910: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049914:
    ctx->pc = 0x80049914u;
    // 80049914: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049918:
    ctx->pc = 0x80049918u;
    // 80049918: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004991C:
    ctx->pc = 0x8004991Cu;
    ctx->downcount -= 8;
    // 8004991C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049920:
    ctx->pc = 0x80049920u;
    // 80049920: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049924:
    ctx->pc = 0x80049924u;
    // 80049924: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049928:
    ctx->pc = 0x80049928u;
    // 80049928: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004992C:
    ctx->pc = 0x8004992Cu;
    // 8004992C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049930:
    ctx->pc = 0x80049930u;
    // 80049930: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_80049934:
    ctx->pc = 0x80049934u;
    // 80049934: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049938:
    ctx->pc = 0x80049938u;
    // 80049938: bl      0x8004B1A0
    {
            ctx->lr = 0x8004993Cu;
            goto label_8004B1A0;
    }

label_8004993C:
    ctx->pc = 0x8004993Cu;
    ctx->downcount -= 5;
    // 8004993C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049940:
    ctx->pc = 0x80049940u;
    // 80049940: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049944:
    ctx->pc = 0x80049944u;
    // 80049944: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049948:
    ctx->pc = 0x80049948u;
    // 80049948: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004994C:
    ctx->pc = 0x8004994Cu;
    ctx->downcount -= 8;
    // 8004994C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049950:
    ctx->pc = 0x80049950u;
    // 80049950: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049954:
    ctx->pc = 0x80049954u;
    // 80049954: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049958:
    ctx->pc = 0x80049958u;
    // 80049958: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004995C:
    ctx->pc = 0x8004995Cu;
    // 8004995C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049960:
    ctx->pc = 0x80049960u;
    // 80049960: addi    r9, r9, 16496
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16496);

label_80049964:
    ctx->pc = 0x80049964u;
    // 80049964: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049968:
    ctx->pc = 0x80049968u;
    // 80049968: bl      0x8004B1A0
    {
            ctx->lr = 0x8004996Cu;
            goto label_8004B1A0;
    }

label_8004996C:
    ctx->pc = 0x8004996Cu;
    ctx->downcount -= 5;
    // 8004996C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049970:
    ctx->pc = 0x80049970u;
    // 80049970: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049974:
    ctx->pc = 0x80049974u;
    // 80049974: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049978:
    ctx->pc = 0x80049978u;
    // 80049978: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004997C:
    ctx->pc = 0x8004997Cu;
    ctx->downcount -= 8;
    // 8004997C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049980:
    ctx->pc = 0x80049980u;
    // 80049980: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049984:
    ctx->pc = 0x80049984u;
    // 80049984: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049988:
    ctx->pc = 0x80049988u;
    // 80049988: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004998C:
    ctx->pc = 0x8004998Cu;
    // 8004998C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049990:
    ctx->pc = 0x80049990u;
    // 80049990: addi    r9, r9, 16440
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16440);

label_80049994:
    ctx->pc = 0x80049994u;
    // 80049994: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049998:
    ctx->pc = 0x80049998u;
    // 80049998: bl      0x8004B1A0
    {
            ctx->lr = 0x8004999Cu;
            goto label_8004B1A0;
    }

label_8004999C:
    ctx->pc = 0x8004999Cu;
    ctx->downcount -= 5;
    // 8004999C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800499A0:
    ctx->pc = 0x800499A0u;
    // 800499A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800499A4:
    ctx->pc = 0x800499A4u;
    // 800499A4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800499A8:
    ctx->pc = 0x800499A8u;
    // 800499A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800499AC:
    ctx->pc = 0x800499ACu;
    ctx->downcount -= 8;
    // 800499AC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800499B0:
    ctx->pc = 0x800499B0u;
    // 800499B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800499B4:
    ctx->pc = 0x800499B4u;
    // 800499B4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800499B8:
    ctx->pc = 0x800499B8u;
    // 800499B8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800499BC:
    ctx->pc = 0x800499BCu;
    // 800499BC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800499C0:
    ctx->pc = 0x800499C0u;
    // 800499C0: addi    r9, r9, 16384
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16384);

label_800499C4:
    ctx->pc = 0x800499C4u;
    // 800499C4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800499C8:
    ctx->pc = 0x800499C8u;
    // 800499C8: bl      0x8004B1A0
    {
            ctx->lr = 0x800499CCu;
            goto label_8004B1A0;
    }

label_800499CC:
    ctx->pc = 0x800499CCu;
    ctx->downcount -= 5;
    // 800499CC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800499D0:
    ctx->pc = 0x800499D0u;
    // 800499D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800499D4:
    ctx->pc = 0x800499D4u;
    // 800499D4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800499D8:
    ctx->pc = 0x800499D8u;
    // 800499D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_800499DC:
    ctx->pc = 0x800499DCu;
    ctx->downcount -= 8;
    // 800499DC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800499E0:
    ctx->pc = 0x800499E0u;
    // 800499E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800499E4:
    ctx->pc = 0x800499E4u;
    // 800499E4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800499E8:
    ctx->pc = 0x800499E8u;
    // 800499E8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_800499EC:
    ctx->pc = 0x800499ECu;
    // 800499EC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800499F0:
    ctx->pc = 0x800499F0u;
    // 800499F0: addi    r9, r9, 16328
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16328);

label_800499F4:
    ctx->pc = 0x800499F4u;
    // 800499F4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800499F8:
    ctx->pc = 0x800499F8u;
    // 800499F8: bl      0x8004B1A0
    {
            ctx->lr = 0x800499FCu;
            goto label_8004B1A0;
    }

label_800499FC:
    ctx->pc = 0x800499FCu;
    ctx->downcount -= 5;
    // 800499FC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049A00:
    ctx->pc = 0x80049A00u;
    // 80049A00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049A04:
    ctx->pc = 0x80049A04u;
    // 80049A04: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049A08:
    ctx->pc = 0x80049A08u;
    // 80049A08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049A0C:
    ctx->pc = 0x80049A0Cu;
    ctx->downcount -= 8;
    // 80049A0C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049A10:
    ctx->pc = 0x80049A10u;
    // 80049A10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049A14:
    ctx->pc = 0x80049A14u;
    // 80049A14: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049A18:
    ctx->pc = 0x80049A18u;
    // 80049A18: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049A1C:
    ctx->pc = 0x80049A1Cu;
    // 80049A1C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049A20:
    ctx->pc = 0x80049A20u;
    // 80049A20: addi    r9, r9, 16272
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16272);

label_80049A24:
    ctx->pc = 0x80049A24u;
    // 80049A24: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049A28:
    ctx->pc = 0x80049A28u;
    // 80049A28: bl      0x8004B1A0
    {
            ctx->lr = 0x80049A2Cu;
            goto label_8004B1A0;
    }

label_80049A2C:
    ctx->pc = 0x80049A2Cu;
    ctx->downcount -= 5;
    // 80049A2C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049A30:
    ctx->pc = 0x80049A30u;
    // 80049A30: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049A34:
    ctx->pc = 0x80049A34u;
    // 80049A34: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049A38:
    ctx->pc = 0x80049A38u;
    // 80049A38: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049A3C:
    ctx->pc = 0x80049A3Cu;
    ctx->downcount -= 8;
    // 80049A3C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049A40:
    ctx->pc = 0x80049A40u;
    // 80049A40: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049A44:
    ctx->pc = 0x80049A44u;
    // 80049A44: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049A48:
    ctx->pc = 0x80049A48u;
    // 80049A48: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049A4C:
    ctx->pc = 0x80049A4Cu;
    // 80049A4C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049A50:
    ctx->pc = 0x80049A50u;
    // 80049A50: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_80049A54:
    ctx->pc = 0x80049A54u;
    // 80049A54: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049A58:
    ctx->pc = 0x80049A58u;
    // 80049A58: bl      0x8004B1A0
    {
            ctx->lr = 0x80049A5Cu;
            goto label_8004B1A0;
    }

label_80049A5C:
    ctx->pc = 0x80049A5Cu;
    ctx->downcount -= 5;
    // 80049A5C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049A60:
    ctx->pc = 0x80049A60u;
    // 80049A60: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049A64:
    ctx->pc = 0x80049A64u;
    // 80049A64: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049A68:
    ctx->pc = 0x80049A68u;
    // 80049A68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049A6C:
    ctx->pc = 0x80049A6Cu;
    ctx->downcount -= 8;
    // 80049A6C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049A70:
    ctx->pc = 0x80049A70u;
    // 80049A70: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049A74:
    ctx->pc = 0x80049A74u;
    // 80049A74: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049A78:
    ctx->pc = 0x80049A78u;
    // 80049A78: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049A7C:
    ctx->pc = 0x80049A7Cu;
    // 80049A7C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049A80:
    ctx->pc = 0x80049A80u;
    // 80049A80: addi    r9, r9, 16152
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16152);

label_80049A84:
    ctx->pc = 0x80049A84u;
    // 80049A84: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049A88:
    ctx->pc = 0x80049A88u;
    // 80049A88: bl      0x8004B1A0
    {
            ctx->lr = 0x80049A8Cu;
            goto label_8004B1A0;
    }

label_80049A8C:
    ctx->pc = 0x80049A8Cu;
    ctx->downcount -= 5;
    // 80049A8C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049A90:
    ctx->pc = 0x80049A90u;
    // 80049A90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049A94:
    ctx->pc = 0x80049A94u;
    // 80049A94: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049A98:
    ctx->pc = 0x80049A98u;
    // 80049A98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049A9C:
    ctx->pc = 0x80049A9Cu;
    ctx->downcount -= 8;
    // 80049A9C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049AA0:
    ctx->pc = 0x80049AA0u;
    // 80049AA0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049AA4:
    ctx->pc = 0x80049AA4u;
    // 80049AA4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049AA8:
    ctx->pc = 0x80049AA8u;
    // 80049AA8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049AAC:
    ctx->pc = 0x80049AACu;
    // 80049AAC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049AB0:
    ctx->pc = 0x80049AB0u;
    // 80049AB0: addi    r9, r9, 16096
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16096);

label_80049AB4:
    ctx->pc = 0x80049AB4u;
    // 80049AB4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049AB8:
    ctx->pc = 0x80049AB8u;
    // 80049AB8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049ABCu;
            goto label_8004B1A0;
    }

label_80049ABC:
    ctx->pc = 0x80049ABCu;
    ctx->downcount -= 5;
    // 80049ABC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049AC0:
    ctx->pc = 0x80049AC0u;
    // 80049AC0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049AC4:
    ctx->pc = 0x80049AC4u;
    // 80049AC4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049AC8:
    ctx->pc = 0x80049AC8u;
    // 80049AC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049ACC:
    ctx->pc = 0x80049ACCu;
    ctx->downcount -= 8;
    // 80049ACC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049AD0:
    ctx->pc = 0x80049AD0u;
    // 80049AD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049AD4:
    ctx->pc = 0x80049AD4u;
    // 80049AD4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049AD8:
    ctx->pc = 0x80049AD8u;
    // 80049AD8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049ADC:
    ctx->pc = 0x80049ADCu;
    // 80049ADC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049AE0:
    ctx->pc = 0x80049AE0u;
    // 80049AE0: addi    r9, r9, 16040
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16040);

label_80049AE4:
    ctx->pc = 0x80049AE4u;
    // 80049AE4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049AE8:
    ctx->pc = 0x80049AE8u;
    // 80049AE8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049AECu;
            goto label_8004B1A0;
    }

label_80049AEC:
    ctx->pc = 0x80049AECu;
    ctx->downcount -= 5;
    // 80049AEC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049AF0:
    ctx->pc = 0x80049AF0u;
    // 80049AF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049AF4:
    ctx->pc = 0x80049AF4u;
    // 80049AF4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049AF8:
    ctx->pc = 0x80049AF8u;
    // 80049AF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049AFC:
    ctx->pc = 0x80049AFCu;
    ctx->downcount -= 8;
    // 80049AFC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049B00:
    ctx->pc = 0x80049B00u;
    // 80049B00: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049B04:
    ctx->pc = 0x80049B04u;
    // 80049B04: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049B08:
    ctx->pc = 0x80049B08u;
    // 80049B08: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049B0C:
    ctx->pc = 0x80049B0Cu;
    // 80049B0C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049B10:
    ctx->pc = 0x80049B10u;
    // 80049B10: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049B14:
    ctx->pc = 0x80049B14u;
    // 80049B14: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049B18:
    ctx->pc = 0x80049B18u;
    // 80049B18: bl      0x8004B1A0
    {
            ctx->lr = 0x80049B1Cu;
            goto label_8004B1A0;
    }

label_80049B1C:
    ctx->pc = 0x80049B1Cu;
    ctx->downcount -= 5;
    // 80049B1C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049B20:
    ctx->pc = 0x80049B20u;
    // 80049B20: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049B24:
    ctx->pc = 0x80049B24u;
    // 80049B24: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049B28:
    ctx->pc = 0x80049B28u;
    // 80049B28: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049B2C:
    ctx->pc = 0x80049B2Cu;
    ctx->downcount -= 8;
    // 80049B2C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049B30:
    ctx->pc = 0x80049B30u;
    // 80049B30: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049B34:
    ctx->pc = 0x80049B34u;
    // 80049B34: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049B38:
    ctx->pc = 0x80049B38u;
    // 80049B38: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049B3C:
    ctx->pc = 0x80049B3Cu;
    // 80049B3C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049B40:
    ctx->pc = 0x80049B40u;
    // 80049B40: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049B44:
    ctx->pc = 0x80049B44u;
    // 80049B44: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049B48:
    ctx->pc = 0x80049B48u;
    // 80049B48: bl      0x8004B1A0
    {
            ctx->lr = 0x80049B4Cu;
            goto label_8004B1A0;
    }

label_80049B4C:
    ctx->pc = 0x80049B4Cu;
    ctx->downcount -= 5;
    // 80049B4C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049B50:
    ctx->pc = 0x80049B50u;
    // 80049B50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049B54:
    ctx->pc = 0x80049B54u;
    // 80049B54: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049B58:
    ctx->pc = 0x80049B58u;
    // 80049B58: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049B5C:
    ctx->pc = 0x80049B5Cu;
    ctx->downcount -= 8;
    // 80049B5C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049B60:
    ctx->pc = 0x80049B60u;
    // 80049B60: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049B64:
    ctx->pc = 0x80049B64u;
    // 80049B64: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049B68:
    ctx->pc = 0x80049B68u;
    // 80049B68: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049B6C:
    ctx->pc = 0x80049B6Cu;
    // 80049B6C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049B70:
    ctx->pc = 0x80049B70u;
    // 80049B70: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049B74:
    ctx->pc = 0x80049B74u;
    // 80049B74: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049B78:
    ctx->pc = 0x80049B78u;
    // 80049B78: bl      0x8004B1A0
    {
            ctx->lr = 0x80049B7Cu;
            goto label_8004B1A0;
    }

label_80049B7C:
    ctx->pc = 0x80049B7Cu;
    ctx->downcount -= 5;
    // 80049B7C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049B80:
    ctx->pc = 0x80049B80u;
    // 80049B80: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049B84:
    ctx->pc = 0x80049B84u;
    // 80049B84: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049B88:
    ctx->pc = 0x80049B88u;
    // 80049B88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049B8C:
    ctx->pc = 0x80049B8Cu;
    ctx->downcount -= 8;
    // 80049B8C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049B90:
    ctx->pc = 0x80049B90u;
    // 80049B90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049B94:
    ctx->pc = 0x80049B94u;
    // 80049B94: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049B98:
    ctx->pc = 0x80049B98u;
    // 80049B98: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049B9C:
    ctx->pc = 0x80049B9Cu;
    // 80049B9C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049BA0:
    ctx->pc = 0x80049BA0u;
    // 80049BA0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049BA4:
    ctx->pc = 0x80049BA4u;
    // 80049BA4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049BA8:
    ctx->pc = 0x80049BA8u;
    // 80049BA8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049BACu;
            goto label_8004B1A0;
    }

label_80049BAC:
    ctx->pc = 0x80049BACu;
    ctx->downcount -= 5;
    // 80049BAC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049BB0:
    ctx->pc = 0x80049BB0u;
    // 80049BB0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049BB4:
    ctx->pc = 0x80049BB4u;
    // 80049BB4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049BB8:
    ctx->pc = 0x80049BB8u;
    // 80049BB8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049BBC:
    ctx->pc = 0x80049BBCu;
    ctx->downcount -= 8;
    // 80049BBC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049BC0:
    ctx->pc = 0x80049BC0u;
    // 80049BC0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049BC4:
    ctx->pc = 0x80049BC4u;
    // 80049BC4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049BC8:
    ctx->pc = 0x80049BC8u;
    // 80049BC8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049BCC:
    ctx->pc = 0x80049BCCu;
    // 80049BCC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049BD0:
    ctx->pc = 0x80049BD0u;
    // 80049BD0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049BD4:
    ctx->pc = 0x80049BD4u;
    // 80049BD4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049BD8:
    ctx->pc = 0x80049BD8u;
    // 80049BD8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049BDCu;
            goto label_8004B1A0;
    }

label_80049BDC:
    ctx->pc = 0x80049BDCu;
    ctx->downcount -= 5;
    // 80049BDC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049BE0:
    ctx->pc = 0x80049BE0u;
    // 80049BE0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049BE4:
    ctx->pc = 0x80049BE4u;
    // 80049BE4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049BE8:
    ctx->pc = 0x80049BE8u;
    // 80049BE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049BEC:
    ctx->pc = 0x80049BECu;
    ctx->downcount -= 8;
    // 80049BEC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049BF0:
    ctx->pc = 0x80049BF0u;
    // 80049BF0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049BF4:
    ctx->pc = 0x80049BF4u;
    // 80049BF4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049BF8:
    ctx->pc = 0x80049BF8u;
    // 80049BF8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049BFC:
    ctx->pc = 0x80049BFCu;
    // 80049BFC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049C00:
    ctx->pc = 0x80049C00u;
    // 80049C00: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049C04:
    ctx->pc = 0x80049C04u;
    // 80049C04: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049C08:
    ctx->pc = 0x80049C08u;
    // 80049C08: bl      0x8004B1A0
    {
            ctx->lr = 0x80049C0Cu;
            goto label_8004B1A0;
    }

label_80049C0C:
    ctx->pc = 0x80049C0Cu;
    ctx->downcount -= 5;
    // 80049C0C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049C10:
    ctx->pc = 0x80049C10u;
    // 80049C10: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049C14:
    ctx->pc = 0x80049C14u;
    // 80049C14: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049C18:
    ctx->pc = 0x80049C18u;
    // 80049C18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049C1C:
    ctx->pc = 0x80049C1Cu;
    ctx->downcount -= 8;
    // 80049C1C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049C20:
    ctx->pc = 0x80049C20u;
    // 80049C20: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049C24:
    ctx->pc = 0x80049C24u;
    // 80049C24: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049C28:
    ctx->pc = 0x80049C28u;
    // 80049C28: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049C2C:
    ctx->pc = 0x80049C2Cu;
    // 80049C2C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049C30:
    ctx->pc = 0x80049C30u;
    // 80049C30: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049C34:
    ctx->pc = 0x80049C34u;
    // 80049C34: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049C38:
    ctx->pc = 0x80049C38u;
    // 80049C38: bl      0x8004B1A0
    {
            ctx->lr = 0x80049C3Cu;
            goto label_8004B1A0;
    }

label_80049C3C:
    ctx->pc = 0x80049C3Cu;
    ctx->downcount -= 5;
    // 80049C3C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049C40:
    ctx->pc = 0x80049C40u;
    // 80049C40: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049C44:
    ctx->pc = 0x80049C44u;
    // 80049C44: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049C48:
    ctx->pc = 0x80049C48u;
    // 80049C48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049C4C:
    ctx->pc = 0x80049C4Cu;
    ctx->downcount -= 8;
    // 80049C4C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049C50:
    ctx->pc = 0x80049C50u;
    // 80049C50: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049C54:
    ctx->pc = 0x80049C54u;
    // 80049C54: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049C58:
    ctx->pc = 0x80049C58u;
    // 80049C58: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049C5C:
    ctx->pc = 0x80049C5Cu;
    // 80049C5C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049C60:
    ctx->pc = 0x80049C60u;
    // 80049C60: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049C64:
    ctx->pc = 0x80049C64u;
    // 80049C64: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049C68:
    ctx->pc = 0x80049C68u;
    // 80049C68: bl      0x8004B1A0
    {
            ctx->lr = 0x80049C6Cu;
            goto label_8004B1A0;
    }

label_80049C6C:
    ctx->pc = 0x80049C6Cu;
    ctx->downcount -= 5;
    // 80049C6C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049C70:
    ctx->pc = 0x80049C70u;
    // 80049C70: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049C74:
    ctx->pc = 0x80049C74u;
    // 80049C74: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049C78:
    ctx->pc = 0x80049C78u;
    // 80049C78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049C7C:
    ctx->pc = 0x80049C7Cu;
    ctx->downcount -= 8;
    // 80049C7C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049C80:
    ctx->pc = 0x80049C80u;
    // 80049C80: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049C84:
    ctx->pc = 0x80049C84u;
    // 80049C84: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049C88:
    ctx->pc = 0x80049C88u;
    // 80049C88: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049C8C:
    ctx->pc = 0x80049C8Cu;
    // 80049C8C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049C90:
    ctx->pc = 0x80049C90u;
    // 80049C90: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049C94:
    ctx->pc = 0x80049C94u;
    // 80049C94: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049C98:
    ctx->pc = 0x80049C98u;
    // 80049C98: bl      0x8004B1A0
    {
            ctx->lr = 0x80049C9Cu;
            goto label_8004B1A0;
    }

label_80049C9C:
    ctx->pc = 0x80049C9Cu;
    ctx->downcount -= 5;
    // 80049C9C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049CA0:
    ctx->pc = 0x80049CA0u;
    // 80049CA0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049CA4:
    ctx->pc = 0x80049CA4u;
    // 80049CA4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049CA8:
    ctx->pc = 0x80049CA8u;
    // 80049CA8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049CAC:
    ctx->pc = 0x80049CACu;
    ctx->downcount -= 8;
    // 80049CAC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049CB0:
    ctx->pc = 0x80049CB0u;
    // 80049CB0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049CB4:
    ctx->pc = 0x80049CB4u;
    // 80049CB4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049CB8:
    ctx->pc = 0x80049CB8u;
    // 80049CB8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049CBC:
    ctx->pc = 0x80049CBCu;
    // 80049CBC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049CC0:
    ctx->pc = 0x80049CC0u;
    // 80049CC0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049CC4:
    ctx->pc = 0x80049CC4u;
    // 80049CC4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049CC8:
    ctx->pc = 0x80049CC8u;
    // 80049CC8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049CCCu;
            goto label_8004B1A0;
    }

label_80049CCC:
    ctx->pc = 0x80049CCCu;
    ctx->downcount -= 5;
    // 80049CCC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049CD0:
    ctx->pc = 0x80049CD0u;
    // 80049CD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049CD4:
    ctx->pc = 0x80049CD4u;
    // 80049CD4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049CD8:
    ctx->pc = 0x80049CD8u;
    // 80049CD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049CDC:
    ctx->pc = 0x80049CDCu;
    ctx->downcount -= 8;
    // 80049CDC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049CE0:
    ctx->pc = 0x80049CE0u;
    // 80049CE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049CE4:
    ctx->pc = 0x80049CE4u;
    // 80049CE4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049CE8:
    ctx->pc = 0x80049CE8u;
    // 80049CE8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049CEC:
    ctx->pc = 0x80049CECu;
    // 80049CEC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049CF0:
    ctx->pc = 0x80049CF0u;
    // 80049CF0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049CF4:
    ctx->pc = 0x80049CF4u;
    // 80049CF4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049CF8:
    ctx->pc = 0x80049CF8u;
    // 80049CF8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049CFCu;
            goto label_8004B1A0;
    }

label_80049CFC:
    ctx->pc = 0x80049CFCu;
    ctx->downcount -= 5;
    // 80049CFC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049D00:
    ctx->pc = 0x80049D00u;
    // 80049D00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049D04:
    ctx->pc = 0x80049D04u;
    // 80049D04: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049D08:
    ctx->pc = 0x80049D08u;
    // 80049D08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049D0C:
    ctx->pc = 0x80049D0Cu;
    ctx->downcount -= 8;
    // 80049D0C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049D10:
    ctx->pc = 0x80049D10u;
    // 80049D10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049D14:
    ctx->pc = 0x80049D14u;
    // 80049D14: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049D18:
    ctx->pc = 0x80049D18u;
    // 80049D18: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049D1C:
    ctx->pc = 0x80049D1Cu;
    // 80049D1C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049D20:
    ctx->pc = 0x80049D20u;
    // 80049D20: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049D24:
    ctx->pc = 0x80049D24u;
    // 80049D24: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049D28:
    ctx->pc = 0x80049D28u;
    // 80049D28: bl      0x8004B1A0
    {
            ctx->lr = 0x80049D2Cu;
            goto label_8004B1A0;
    }

label_80049D2C:
    ctx->pc = 0x80049D2Cu;
    ctx->downcount -= 5;
    // 80049D2C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049D30:
    ctx->pc = 0x80049D30u;
    // 80049D30: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049D34:
    ctx->pc = 0x80049D34u;
    // 80049D34: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049D38:
    ctx->pc = 0x80049D38u;
    // 80049D38: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049D3C:
    ctx->pc = 0x80049D3Cu;
    ctx->downcount -= 8;
    // 80049D3C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049D40:
    ctx->pc = 0x80049D40u;
    // 80049D40: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049D44:
    ctx->pc = 0x80049D44u;
    // 80049D44: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049D48:
    ctx->pc = 0x80049D48u;
    // 80049D48: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049D4C:
    ctx->pc = 0x80049D4Cu;
    // 80049D4C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049D50:
    ctx->pc = 0x80049D50u;
    // 80049D50: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049D54:
    ctx->pc = 0x80049D54u;
    // 80049D54: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049D58:
    ctx->pc = 0x80049D58u;
    // 80049D58: bl      0x8004B1A0
    {
            ctx->lr = 0x80049D5Cu;
            goto label_8004B1A0;
    }

label_80049D5C:
    ctx->pc = 0x80049D5Cu;
    ctx->downcount -= 5;
    // 80049D5C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049D60:
    ctx->pc = 0x80049D60u;
    // 80049D60: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049D64:
    ctx->pc = 0x80049D64u;
    // 80049D64: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049D68:
    ctx->pc = 0x80049D68u;
    // 80049D68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049D6C:
    ctx->pc = 0x80049D6Cu;
    ctx->downcount -= 8;
    // 80049D6C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049D70:
    ctx->pc = 0x80049D70u;
    // 80049D70: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049D74:
    ctx->pc = 0x80049D74u;
    // 80049D74: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049D78:
    ctx->pc = 0x80049D78u;
    // 80049D78: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049D7C:
    ctx->pc = 0x80049D7Cu;
    // 80049D7C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049D80:
    ctx->pc = 0x80049D80u;
    // 80049D80: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049D84:
    ctx->pc = 0x80049D84u;
    // 80049D84: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049D88:
    ctx->pc = 0x80049D88u;
    // 80049D88: bl      0x8004B1A0
    {
            ctx->lr = 0x80049D8Cu;
            goto label_8004B1A0;
    }

label_80049D8C:
    ctx->pc = 0x80049D8Cu;
    ctx->downcount -= 5;
    // 80049D8C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049D90:
    ctx->pc = 0x80049D90u;
    // 80049D90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049D94:
    ctx->pc = 0x80049D94u;
    // 80049D94: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049D98:
    ctx->pc = 0x80049D98u;
    // 80049D98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049D9C:
    ctx->pc = 0x80049D9Cu;
    ctx->downcount -= 8;
    // 80049D9C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049DA0:
    ctx->pc = 0x80049DA0u;
    // 80049DA0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049DA4:
    ctx->pc = 0x80049DA4u;
    // 80049DA4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049DA8:
    ctx->pc = 0x80049DA8u;
    // 80049DA8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049DAC:
    ctx->pc = 0x80049DACu;
    // 80049DAC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049DB0:
    ctx->pc = 0x80049DB0u;
    // 80049DB0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049DB4:
    ctx->pc = 0x80049DB4u;
    // 80049DB4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049DB8:
    ctx->pc = 0x80049DB8u;
    // 80049DB8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049DBCu;
            goto label_8004B1A0;
    }

label_80049DBC:
    ctx->pc = 0x80049DBCu;
    ctx->downcount -= 5;
    // 80049DBC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049DC0:
    ctx->pc = 0x80049DC0u;
    // 80049DC0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049DC4:
    ctx->pc = 0x80049DC4u;
    // 80049DC4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049DC8:
    ctx->pc = 0x80049DC8u;
    // 80049DC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049DCC:
    ctx->pc = 0x80049DCCu;
    ctx->downcount -= 8;
    // 80049DCC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049DD0:
    ctx->pc = 0x80049DD0u;
    // 80049DD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049DD4:
    ctx->pc = 0x80049DD4u;
    // 80049DD4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049DD8:
    ctx->pc = 0x80049DD8u;
    // 80049DD8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049DDC:
    ctx->pc = 0x80049DDCu;
    // 80049DDC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049DE0:
    ctx->pc = 0x80049DE0u;
    // 80049DE0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049DE4:
    ctx->pc = 0x80049DE4u;
    // 80049DE4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049DE8:
    ctx->pc = 0x80049DE8u;
    // 80049DE8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049DECu;
            goto label_8004B1A0;
    }

label_80049DEC:
    ctx->pc = 0x80049DECu;
    ctx->downcount -= 5;
    // 80049DEC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049DF0:
    ctx->pc = 0x80049DF0u;
    // 80049DF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049DF4:
    ctx->pc = 0x80049DF4u;
    // 80049DF4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049DF8:
    ctx->pc = 0x80049DF8u;
    // 80049DF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049DFC:
    ctx->pc = 0x80049DFCu;
    ctx->downcount -= 8;
    // 80049DFC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049E00:
    ctx->pc = 0x80049E00u;
    // 80049E00: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049E04:
    ctx->pc = 0x80049E04u;
    // 80049E04: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049E08:
    ctx->pc = 0x80049E08u;
    // 80049E08: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049E0C:
    ctx->pc = 0x80049E0Cu;
    // 80049E0C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049E10:
    ctx->pc = 0x80049E10u;
    // 80049E10: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049E14:
    ctx->pc = 0x80049E14u;
    // 80049E14: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049E18:
    ctx->pc = 0x80049E18u;
    // 80049E18: bl      0x8004B1A0
    {
            ctx->lr = 0x80049E1Cu;
            goto label_8004B1A0;
    }

label_80049E1C:
    ctx->pc = 0x80049E1Cu;
    ctx->downcount -= 5;
    // 80049E1C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049E20:
    ctx->pc = 0x80049E20u;
    // 80049E20: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049E24:
    ctx->pc = 0x80049E24u;
    // 80049E24: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049E28:
    ctx->pc = 0x80049E28u;
    // 80049E28: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049E2C:
    ctx->pc = 0x80049E2Cu;
    ctx->downcount -= 8;
    // 80049E2C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049E30:
    ctx->pc = 0x80049E30u;
    // 80049E30: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049E34:
    ctx->pc = 0x80049E34u;
    // 80049E34: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049E38:
    ctx->pc = 0x80049E38u;
    // 80049E38: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049E3C:
    ctx->pc = 0x80049E3Cu;
    // 80049E3C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049E40:
    ctx->pc = 0x80049E40u;
    // 80049E40: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049E44:
    ctx->pc = 0x80049E44u;
    // 80049E44: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049E48:
    ctx->pc = 0x80049E48u;
    // 80049E48: bl      0x8004B1A0
    {
            ctx->lr = 0x80049E4Cu;
            goto label_8004B1A0;
    }

label_80049E4C:
    ctx->pc = 0x80049E4Cu;
    ctx->downcount -= 5;
    // 80049E4C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049E50:
    ctx->pc = 0x80049E50u;
    // 80049E50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049E54:
    ctx->pc = 0x80049E54u;
    // 80049E54: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049E58:
    ctx->pc = 0x80049E58u;
    // 80049E58: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049E5C:
    ctx->pc = 0x80049E5Cu;
    ctx->downcount -= 8;
    // 80049E5C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049E60:
    ctx->pc = 0x80049E60u;
    // 80049E60: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049E64:
    ctx->pc = 0x80049E64u;
    // 80049E64: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049E68:
    ctx->pc = 0x80049E68u;
    // 80049E68: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049E6C:
    ctx->pc = 0x80049E6Cu;
    // 80049E6C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049E70:
    ctx->pc = 0x80049E70u;
    // 80049E70: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049E74:
    ctx->pc = 0x80049E74u;
    // 80049E74: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049E78:
    ctx->pc = 0x80049E78u;
    // 80049E78: bl      0x8004B1A0
    {
            ctx->lr = 0x80049E7Cu;
            goto label_8004B1A0;
    }

label_80049E7C:
    ctx->pc = 0x80049E7Cu;
    ctx->downcount -= 5;
    // 80049E7C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049E80:
    ctx->pc = 0x80049E80u;
    // 80049E80: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049E84:
    ctx->pc = 0x80049E84u;
    // 80049E84: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049E88:
    ctx->pc = 0x80049E88u;
    // 80049E88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049E8C:
    ctx->pc = 0x80049E8Cu;
    ctx->downcount -= 8;
    // 80049E8C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049E90:
    ctx->pc = 0x80049E90u;
    // 80049E90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049E94:
    ctx->pc = 0x80049E94u;
    // 80049E94: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049E98:
    ctx->pc = 0x80049E98u;
    // 80049E98: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049E9C:
    ctx->pc = 0x80049E9Cu;
    // 80049E9C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049EA0:
    ctx->pc = 0x80049EA0u;
    // 80049EA0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049EA4:
    ctx->pc = 0x80049EA4u;
    // 80049EA4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049EA8:
    ctx->pc = 0x80049EA8u;
    // 80049EA8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049EACu;
            goto label_8004B1A0;
    }

label_80049EAC:
    ctx->pc = 0x80049EACu;
    ctx->downcount -= 5;
    // 80049EAC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049EB0:
    ctx->pc = 0x80049EB0u;
    // 80049EB0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049EB4:
    ctx->pc = 0x80049EB4u;
    // 80049EB4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049EB8:
    ctx->pc = 0x80049EB8u;
    // 80049EB8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049EBC:
    ctx->pc = 0x80049EBCu;
    ctx->downcount -= 8;
    // 80049EBC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049EC0:
    ctx->pc = 0x80049EC0u;
    // 80049EC0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049EC4:
    ctx->pc = 0x80049EC4u;
    // 80049EC4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049EC8:
    ctx->pc = 0x80049EC8u;
    // 80049EC8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049ECC:
    ctx->pc = 0x80049ECCu;
    // 80049ECC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049ED0:
    ctx->pc = 0x80049ED0u;
    // 80049ED0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049ED4:
    ctx->pc = 0x80049ED4u;
    // 80049ED4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049ED8:
    ctx->pc = 0x80049ED8u;
    // 80049ED8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049EDCu;
            goto label_8004B1A0;
    }

label_80049EDC:
    ctx->pc = 0x80049EDCu;
    ctx->downcount -= 5;
    // 80049EDC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049EE0:
    ctx->pc = 0x80049EE0u;
    // 80049EE0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049EE4:
    ctx->pc = 0x80049EE4u;
    // 80049EE4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049EE8:
    ctx->pc = 0x80049EE8u;
    // 80049EE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049EEC:
    ctx->pc = 0x80049EECu;
    ctx->downcount -= 8;
    // 80049EEC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049EF0:
    ctx->pc = 0x80049EF0u;
    // 80049EF0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049EF4:
    ctx->pc = 0x80049EF4u;
    // 80049EF4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049EF8:
    ctx->pc = 0x80049EF8u;
    // 80049EF8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049EFC:
    ctx->pc = 0x80049EFCu;
    // 80049EFC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049F00:
    ctx->pc = 0x80049F00u;
    // 80049F00: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049F04:
    ctx->pc = 0x80049F04u;
    // 80049F04: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049F08:
    ctx->pc = 0x80049F08u;
    // 80049F08: bl      0x8004B1A0
    {
            ctx->lr = 0x80049F0Cu;
            goto label_8004B1A0;
    }

label_80049F0C:
    ctx->pc = 0x80049F0Cu;
    ctx->downcount -= 5;
    // 80049F0C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049F10:
    ctx->pc = 0x80049F10u;
    // 80049F10: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049F14:
    ctx->pc = 0x80049F14u;
    // 80049F14: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049F18:
    ctx->pc = 0x80049F18u;
    // 80049F18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049F1C:
    ctx->pc = 0x80049F1Cu;
    ctx->downcount -= 8;
    // 80049F1C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049F20:
    ctx->pc = 0x80049F20u;
    // 80049F20: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049F24:
    ctx->pc = 0x80049F24u;
    // 80049F24: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049F28:
    ctx->pc = 0x80049F28u;
    // 80049F28: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049F2C:
    ctx->pc = 0x80049F2Cu;
    // 80049F2C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049F30:
    ctx->pc = 0x80049F30u;
    // 80049F30: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049F34:
    ctx->pc = 0x80049F34u;
    // 80049F34: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049F38:
    ctx->pc = 0x80049F38u;
    // 80049F38: bl      0x8004B1A0
    {
            ctx->lr = 0x80049F3Cu;
            goto label_8004B1A0;
    }

label_80049F3C:
    ctx->pc = 0x80049F3Cu;
    ctx->downcount -= 5;
    // 80049F3C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049F40:
    ctx->pc = 0x80049F40u;
    // 80049F40: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049F44:
    ctx->pc = 0x80049F44u;
    // 80049F44: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049F48:
    ctx->pc = 0x80049F48u;
    // 80049F48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049F4C:
    ctx->pc = 0x80049F4Cu;
    ctx->downcount -= 8;
    // 80049F4C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049F50:
    ctx->pc = 0x80049F50u;
    // 80049F50: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049F54:
    ctx->pc = 0x80049F54u;
    // 80049F54: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049F58:
    ctx->pc = 0x80049F58u;
    // 80049F58: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049F5C:
    ctx->pc = 0x80049F5Cu;
    // 80049F5C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049F60:
    ctx->pc = 0x80049F60u;
    // 80049F60: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049F64:
    ctx->pc = 0x80049F64u;
    // 80049F64: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049F68:
    ctx->pc = 0x80049F68u;
    // 80049F68: bl      0x8004B1A0
    {
            ctx->lr = 0x80049F6Cu;
            goto label_8004B1A0;
    }

label_80049F6C:
    ctx->pc = 0x80049F6Cu;
    ctx->downcount -= 5;
    // 80049F6C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049F70:
    ctx->pc = 0x80049F70u;
    // 80049F70: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049F74:
    ctx->pc = 0x80049F74u;
    // 80049F74: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049F78:
    ctx->pc = 0x80049F78u;
    // 80049F78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049F7C:
    ctx->pc = 0x80049F7Cu;
    ctx->downcount -= 8;
    // 80049F7C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049F80:
    ctx->pc = 0x80049F80u;
    // 80049F80: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049F84:
    ctx->pc = 0x80049F84u;
    // 80049F84: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049F88:
    ctx->pc = 0x80049F88u;
    // 80049F88: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049F8C:
    ctx->pc = 0x80049F8Cu;
    // 80049F8C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049F90:
    ctx->pc = 0x80049F90u;
    // 80049F90: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049F94:
    ctx->pc = 0x80049F94u;
    // 80049F94: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049F98:
    ctx->pc = 0x80049F98u;
    // 80049F98: bl      0x8004B1A0
    {
            ctx->lr = 0x80049F9Cu;
            goto label_8004B1A0;
    }

label_80049F9C:
    ctx->pc = 0x80049F9Cu;
    ctx->downcount -= 5;
    // 80049F9C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049FA0:
    ctx->pc = 0x80049FA0u;
    // 80049FA0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049FA4:
    ctx->pc = 0x80049FA4u;
    // 80049FA4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049FA8:
    ctx->pc = 0x80049FA8u;
    // 80049FA8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049FAC:
    ctx->pc = 0x80049FACu;
    ctx->downcount -= 8;
    // 80049FAC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049FB0:
    ctx->pc = 0x80049FB0u;
    // 80049FB0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049FB4:
    ctx->pc = 0x80049FB4u;
    // 80049FB4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049FB8:
    ctx->pc = 0x80049FB8u;
    // 80049FB8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049FBC:
    ctx->pc = 0x80049FBCu;
    // 80049FBC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049FC0:
    ctx->pc = 0x80049FC0u;
    // 80049FC0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049FC4:
    ctx->pc = 0x80049FC4u;
    // 80049FC4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049FC8:
    ctx->pc = 0x80049FC8u;
    // 80049FC8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049FCCu;
            goto label_8004B1A0;
    }

label_80049FCC:
    ctx->pc = 0x80049FCCu;
    ctx->downcount -= 5;
    // 80049FCC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80049FD0:
    ctx->pc = 0x80049FD0u;
    // 80049FD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80049FD4:
    ctx->pc = 0x80049FD4u;
    // 80049FD4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80049FD8:
    ctx->pc = 0x80049FD8u;
    // 80049FD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_80049FDC:
    ctx->pc = 0x80049FDCu;
    ctx->downcount -= 8;
    // 80049FDC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80049FE0:
    ctx->pc = 0x80049FE0u;
    // 80049FE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80049FE4:
    ctx->pc = 0x80049FE4u;
    // 80049FE4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80049FE8:
    ctx->pc = 0x80049FE8u;
    // 80049FE8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_80049FEC:
    ctx->pc = 0x80049FECu;
    // 80049FEC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80049FF0:
    ctx->pc = 0x80049FF0u;
    // 80049FF0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_80049FF4:
    ctx->pc = 0x80049FF4u;
    // 80049FF4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80049FF8:
    ctx->pc = 0x80049FF8u;
    // 80049FF8: bl      0x8004B1A0
    {
            ctx->lr = 0x80049FFCu;
            goto label_8004B1A0;
    }

label_80049FFC:
    ctx->pc = 0x80049FFCu;
    ctx->downcount -= 5;
    // 80049FFC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A000:
    ctx->pc = 0x8004A000u;
    // 8004A000: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A004:
    ctx->pc = 0x8004A004u;
    // 8004A004: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A008:
    ctx->pc = 0x8004A008u;
    // 8004A008: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A00C:
    ctx->pc = 0x8004A00Cu;
    ctx->downcount -= 8;
    // 8004A00C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A010:
    ctx->pc = 0x8004A010u;
    // 8004A010: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A014:
    ctx->pc = 0x8004A014u;
    // 8004A014: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A018:
    ctx->pc = 0x8004A018u;
    // 8004A018: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A01C:
    ctx->pc = 0x8004A01Cu;
    // 8004A01C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A020:
    ctx->pc = 0x8004A020u;
    // 8004A020: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_8004A024:
    ctx->pc = 0x8004A024u;
    // 8004A024: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A028:
    ctx->pc = 0x8004A028u;
    // 8004A028: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A02Cu;
            goto label_8004B1A0;
    }

label_8004A02C:
    ctx->pc = 0x8004A02Cu;
    ctx->downcount -= 5;
    // 8004A02C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A030:
    ctx->pc = 0x8004A030u;
    // 8004A030: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A034:
    ctx->pc = 0x8004A034u;
    // 8004A034: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A038:
    ctx->pc = 0x8004A038u;
    // 8004A038: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A03C:
    ctx->pc = 0x8004A03Cu;
    ctx->downcount -= 8;
    // 8004A03C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A040:
    ctx->pc = 0x8004A040u;
    // 8004A040: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A044:
    ctx->pc = 0x8004A044u;
    // 8004A044: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A048:
    ctx->pc = 0x8004A048u;
    // 8004A048: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A04C:
    ctx->pc = 0x8004A04Cu;
    // 8004A04C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A050:
    ctx->pc = 0x8004A050u;
    // 8004A050: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_8004A054:
    ctx->pc = 0x8004A054u;
    // 8004A054: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A058:
    ctx->pc = 0x8004A058u;
    // 8004A058: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A05Cu;
            goto label_8004B1A0;
    }

label_8004A05C:
    ctx->pc = 0x8004A05Cu;
    ctx->downcount -= 5;
    // 8004A05C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A060:
    ctx->pc = 0x8004A060u;
    // 8004A060: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A064:
    ctx->pc = 0x8004A064u;
    // 8004A064: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A068:
    ctx->pc = 0x8004A068u;
    // 8004A068: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A06C:
    ctx->pc = 0x8004A06Cu;
    ctx->downcount -= 8;
    // 8004A06C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A070:
    ctx->pc = 0x8004A070u;
    // 8004A070: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A074:
    ctx->pc = 0x8004A074u;
    // 8004A074: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A078:
    ctx->pc = 0x8004A078u;
    // 8004A078: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A07C:
    ctx->pc = 0x8004A07Cu;
    // 8004A07C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A080:
    ctx->pc = 0x8004A080u;
    // 8004A080: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_8004A084:
    ctx->pc = 0x8004A084u;
    // 8004A084: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A088:
    ctx->pc = 0x8004A088u;
    // 8004A088: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A08Cu;
            goto label_8004B1A0;
    }

label_8004A08C:
    ctx->pc = 0x8004A08Cu;
    ctx->downcount -= 5;
    // 8004A08C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A090:
    ctx->pc = 0x8004A090u;
    // 8004A090: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A094:
    ctx->pc = 0x8004A094u;
    // 8004A094: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A098:
    ctx->pc = 0x8004A098u;
    // 8004A098: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A09C:
    ctx->pc = 0x8004A09Cu;
    ctx->downcount -= 8;
    // 8004A09C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A0A0:
    ctx->pc = 0x8004A0A0u;
    // 8004A0A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A0A4:
    ctx->pc = 0x8004A0A4u;
    // 8004A0A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A0A8:
    ctx->pc = 0x8004A0A8u;
    // 8004A0A8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A0AC:
    ctx->pc = 0x8004A0ACu;
    // 8004A0AC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A0B0:
    ctx->pc = 0x8004A0B0u;
    // 8004A0B0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_8004A0B4:
    ctx->pc = 0x8004A0B4u;
    // 8004A0B4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A0B8:
    ctx->pc = 0x8004A0B8u;
    // 8004A0B8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A0BCu;
            goto label_8004B1A0;
    }

label_8004A0BC:
    ctx->pc = 0x8004A0BCu;
    ctx->downcount -= 5;
    // 8004A0BC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A0C0:
    ctx->pc = 0x8004A0C0u;
    // 8004A0C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A0C4:
    ctx->pc = 0x8004A0C4u;
    // 8004A0C4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A0C8:
    ctx->pc = 0x8004A0C8u;
    // 8004A0C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A0CC:
    ctx->pc = 0x8004A0CCu;
    ctx->downcount -= 8;
    // 8004A0CC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A0D0:
    ctx->pc = 0x8004A0D0u;
    // 8004A0D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A0D4:
    ctx->pc = 0x8004A0D4u;
    // 8004A0D4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A0D8:
    ctx->pc = 0x8004A0D8u;
    // 8004A0D8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A0DC:
    ctx->pc = 0x8004A0DCu;
    // 8004A0DC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A0E0:
    ctx->pc = 0x8004A0E0u;
    // 8004A0E0: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_8004A0E4:
    ctx->pc = 0x8004A0E4u;
    // 8004A0E4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A0E8:
    ctx->pc = 0x8004A0E8u;
    // 8004A0E8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A0ECu;
            goto label_8004B1A0;
    }

label_8004A0EC:
    ctx->pc = 0x8004A0ECu;
    ctx->downcount -= 5;
    // 8004A0EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A0F0:
    ctx->pc = 0x8004A0F0u;
    // 8004A0F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A0F4:
    ctx->pc = 0x8004A0F4u;
    // 8004A0F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A0F8:
    ctx->pc = 0x8004A0F8u;
    // 8004A0F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A0FC:
    ctx->pc = 0x8004A0FCu;
    ctx->downcount -= 8;
    // 8004A0FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A100:
    ctx->pc = 0x8004A100u;
    // 8004A100: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A104:
    ctx->pc = 0x8004A104u;
    // 8004A104: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A108:
    ctx->pc = 0x8004A108u;
    // 8004A108: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A10C:
    ctx->pc = 0x8004A10Cu;
    // 8004A10C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A110:
    ctx->pc = 0x8004A110u;
    // 8004A110: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_8004A114:
    ctx->pc = 0x8004A114u;
    // 8004A114: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A118:
    ctx->pc = 0x8004A118u;
    // 8004A118: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A11Cu;
            goto label_8004B1A0;
    }

label_8004A11C:
    ctx->pc = 0x8004A11Cu;
    ctx->downcount -= 5;
    // 8004A11C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A120:
    ctx->pc = 0x8004A120u;
    // 8004A120: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A124:
    ctx->pc = 0x8004A124u;
    // 8004A124: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A128:
    ctx->pc = 0x8004A128u;
    // 8004A128: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A12C:
    ctx->pc = 0x8004A12Cu;
    ctx->downcount -= 8;
    // 8004A12C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A130:
    ctx->pc = 0x8004A130u;
    // 8004A130: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A134:
    ctx->pc = 0x8004A134u;
    // 8004A134: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A138:
    ctx->pc = 0x8004A138u;
    // 8004A138: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A13C:
    ctx->pc = 0x8004A13Cu;
    // 8004A13C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A140:
    ctx->pc = 0x8004A140u;
    // 8004A140: addi    r9, r9, 15984
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15984);

label_8004A144:
    ctx->pc = 0x8004A144u;
    // 8004A144: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A148:
    ctx->pc = 0x8004A148u;
    // 8004A148: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A14Cu;
            goto label_8004B1A0;
    }

label_8004A14C:
    ctx->pc = 0x8004A14Cu;
    ctx->downcount -= 5;
    // 8004A14C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A150:
    ctx->pc = 0x8004A150u;
    // 8004A150: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A154:
    ctx->pc = 0x8004A154u;
    // 8004A154: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A158:
    ctx->pc = 0x8004A158u;
    // 8004A158: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A15C:
    ctx->pc = 0x8004A15Cu;
    ctx->downcount -= 8;
    // 8004A15C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A160:
    ctx->pc = 0x8004A160u;
    // 8004A160: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A164:
    ctx->pc = 0x8004A164u;
    // 8004A164: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A168:
    ctx->pc = 0x8004A168u;
    // 8004A168: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A16C:
    ctx->pc = 0x8004A16Cu;
    // 8004A16C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A170:
    ctx->pc = 0x8004A170u;
    // 8004A170: addi    r9, r9, 14080
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(14080);

label_8004A174:
    ctx->pc = 0x8004A174u;
    // 8004A174: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A178:
    ctx->pc = 0x8004A178u;
    // 8004A178: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A17Cu;
            goto label_8004B1A0;
    }

label_8004A17C:
    ctx->pc = 0x8004A17Cu;
    ctx->downcount -= 5;
    // 8004A17C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A180:
    ctx->pc = 0x8004A180u;
    // 8004A180: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A184:
    ctx->pc = 0x8004A184u;
    // 8004A184: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A188:
    ctx->pc = 0x8004A188u;
    // 8004A188: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A18C:
    ctx->pc = 0x8004A18Cu;
    ctx->downcount -= 8;
    // 8004A18C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A190:
    ctx->pc = 0x8004A190u;
    // 8004A190: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A194:
    ctx->pc = 0x8004A194u;
    // 8004A194: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A198:
    ctx->pc = 0x8004A198u;
    // 8004A198: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A19C:
    ctx->pc = 0x8004A19Cu;
    // 8004A19C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A1A0:
    ctx->pc = 0x8004A1A0u;
    // 8004A1A0: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_8004A1A4:
    ctx->pc = 0x8004A1A4u;
    // 8004A1A4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A1A8:
    ctx->pc = 0x8004A1A8u;
    // 8004A1A8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A1ACu;
            goto label_8004B1A0;
    }

label_8004A1AC:
    ctx->pc = 0x8004A1ACu;
    ctx->downcount -= 5;
    // 8004A1AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A1B0:
    ctx->pc = 0x8004A1B0u;
    // 8004A1B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A1B4:
    ctx->pc = 0x8004A1B4u;
    // 8004A1B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A1B8:
    ctx->pc = 0x8004A1B8u;
    // 8004A1B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A1BC:
    ctx->pc = 0x8004A1BCu;
    ctx->downcount -= 8;
    // 8004A1BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A1C0:
    ctx->pc = 0x8004A1C0u;
    // 8004A1C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A1C4:
    ctx->pc = 0x8004A1C4u;
    // 8004A1C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A1C8:
    ctx->pc = 0x8004A1C8u;
    // 8004A1C8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A1CC:
    ctx->pc = 0x8004A1CCu;
    // 8004A1CC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A1D0:
    ctx->pc = 0x8004A1D0u;
    // 8004A1D0: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_8004A1D4:
    ctx->pc = 0x8004A1D4u;
    // 8004A1D4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A1D8:
    ctx->pc = 0x8004A1D8u;
    // 8004A1D8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A1DCu;
            goto label_8004B1A0;
    }

label_8004A1DC:
    ctx->pc = 0x8004A1DCu;
    ctx->downcount -= 5;
    // 8004A1DC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A1E0:
    ctx->pc = 0x8004A1E0u;
    // 8004A1E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A1E4:
    ctx->pc = 0x8004A1E4u;
    // 8004A1E4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A1E8:
    ctx->pc = 0x8004A1E8u;
    // 8004A1E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A1EC:
    ctx->pc = 0x8004A1ECu;
    ctx->downcount -= 8;
    // 8004A1EC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A1F0:
    ctx->pc = 0x8004A1F0u;
    // 8004A1F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A1F4:
    ctx->pc = 0x8004A1F4u;
    // 8004A1F4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A1F8:
    ctx->pc = 0x8004A1F8u;
    // 8004A1F8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A1FC:
    ctx->pc = 0x8004A1FCu;
    // 8004A1FC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A200:
    ctx->pc = 0x8004A200u;
    // 8004A200: addi    r9, r9, 19872
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19872);

label_8004A204:
    ctx->pc = 0x8004A204u;
    // 8004A204: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A208:
    ctx->pc = 0x8004A208u;
    // 8004A208: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A20Cu;
            goto label_8004B1A0;
    }

label_8004A20C:
    ctx->pc = 0x8004A20Cu;
    ctx->downcount -= 5;
    // 8004A20C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A210:
    ctx->pc = 0x8004A210u;
    // 8004A210: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A214:
    ctx->pc = 0x8004A214u;
    // 8004A214: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A218:
    ctx->pc = 0x8004A218u;
    // 8004A218: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A21C:
    ctx->pc = 0x8004A21Cu;
    ctx->downcount -= 8;
    // 8004A21C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A220:
    ctx->pc = 0x8004A220u;
    // 8004A220: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A224:
    ctx->pc = 0x8004A224u;
    // 8004A224: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A228:
    ctx->pc = 0x8004A228u;
    // 8004A228: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A22C:
    ctx->pc = 0x8004A22Cu;
    // 8004A22C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A230:
    ctx->pc = 0x8004A230u;
    // 8004A230: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A234:
    ctx->pc = 0x8004A234u;
    // 8004A234: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A238:
    ctx->pc = 0x8004A238u;
    // 8004A238: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A23Cu;
            goto label_8004B1A0;
    }

label_8004A23C:
    ctx->pc = 0x8004A23Cu;
    ctx->downcount -= 5;
    // 8004A23C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A240:
    ctx->pc = 0x8004A240u;
    // 8004A240: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A244:
    ctx->pc = 0x8004A244u;
    // 8004A244: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A248:
    ctx->pc = 0x8004A248u;
    // 8004A248: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A24C:
    ctx->pc = 0x8004A24Cu;
    ctx->downcount -= 8;
    // 8004A24C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A250:
    ctx->pc = 0x8004A250u;
    // 8004A250: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A254:
    ctx->pc = 0x8004A254u;
    // 8004A254: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A258:
    ctx->pc = 0x8004A258u;
    // 8004A258: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A25C:
    ctx->pc = 0x8004A25Cu;
    // 8004A25C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A260:
    ctx->pc = 0x8004A260u;
    // 8004A260: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A264:
    ctx->pc = 0x8004A264u;
    // 8004A264: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A268:
    ctx->pc = 0x8004A268u;
    // 8004A268: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A26Cu;
            goto label_8004B1A0;
    }

label_8004A26C:
    ctx->pc = 0x8004A26Cu;
    ctx->downcount -= 5;
    // 8004A26C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A270:
    ctx->pc = 0x8004A270u;
    // 8004A270: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A274:
    ctx->pc = 0x8004A274u;
    // 8004A274: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A278:
    ctx->pc = 0x8004A278u;
    // 8004A278: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A27C:
    ctx->pc = 0x8004A27Cu;
    ctx->downcount -= 8;
    // 8004A27C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A280:
    ctx->pc = 0x8004A280u;
    // 8004A280: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A284:
    ctx->pc = 0x8004A284u;
    // 8004A284: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A288:
    ctx->pc = 0x8004A288u;
    // 8004A288: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A28C:
    ctx->pc = 0x8004A28Cu;
    // 8004A28C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A290:
    ctx->pc = 0x8004A290u;
    // 8004A290: addi    r9, r9, 13704
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13704);

label_8004A294:
    ctx->pc = 0x8004A294u;
    // 8004A294: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A298:
    ctx->pc = 0x8004A298u;
    // 8004A298: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A29Cu;
            goto label_8004B1A0;
    }

label_8004A29C:
    ctx->pc = 0x8004A29Cu;
    ctx->downcount -= 5;
    // 8004A29C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A2A0:
    ctx->pc = 0x8004A2A0u;
    // 8004A2A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A2A4:
    ctx->pc = 0x8004A2A4u;
    // 8004A2A4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A2A8:
    ctx->pc = 0x8004A2A8u;
    // 8004A2A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A2AC:
    ctx->pc = 0x8004A2ACu;
    ctx->downcount -= 8;
    // 8004A2AC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A2B0:
    ctx->pc = 0x8004A2B0u;
    // 8004A2B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A2B4:
    ctx->pc = 0x8004A2B4u;
    // 8004A2B4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A2B8:
    ctx->pc = 0x8004A2B8u;
    // 8004A2B8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A2BC:
    ctx->pc = 0x8004A2BCu;
    // 8004A2BC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A2C0:
    ctx->pc = 0x8004A2C0u;
    // 8004A2C0: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A2C4:
    ctx->pc = 0x8004A2C4u;
    // 8004A2C4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A2C8:
    ctx->pc = 0x8004A2C8u;
    // 8004A2C8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A2CCu;
            goto label_8004B1A0;
    }

label_8004A2CC:
    ctx->pc = 0x8004A2CCu;
    ctx->downcount -= 5;
    // 8004A2CC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A2D0:
    ctx->pc = 0x8004A2D0u;
    // 8004A2D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A2D4:
    ctx->pc = 0x8004A2D4u;
    // 8004A2D4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A2D8:
    ctx->pc = 0x8004A2D8u;
    // 8004A2D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A2DC:
    ctx->pc = 0x8004A2DCu;
    ctx->downcount -= 8;
    // 8004A2DC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A2E0:
    ctx->pc = 0x8004A2E0u;
    // 8004A2E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A2E4:
    ctx->pc = 0x8004A2E4u;
    // 8004A2E4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A2E8:
    ctx->pc = 0x8004A2E8u;
    // 8004A2E8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A2EC:
    ctx->pc = 0x8004A2ECu;
    // 8004A2EC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A2F0:
    ctx->pc = 0x8004A2F0u;
    // 8004A2F0: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A2F4:
    ctx->pc = 0x8004A2F4u;
    // 8004A2F4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A2F8:
    ctx->pc = 0x8004A2F8u;
    // 8004A2F8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A2FCu;
            goto label_8004B1A0;
    }

label_8004A2FC:
    ctx->pc = 0x8004A2FCu;
    ctx->downcount -= 5;
    // 8004A2FC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A300:
    ctx->pc = 0x8004A300u;
    // 8004A300: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A304:
    ctx->pc = 0x8004A304u;
    // 8004A304: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A308:
    ctx->pc = 0x8004A308u;
    // 8004A308: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A30C:
    ctx->pc = 0x8004A30Cu;
    ctx->downcount -= 8;
    // 8004A30C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A310:
    ctx->pc = 0x8004A310u;
    // 8004A310: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A314:
    ctx->pc = 0x8004A314u;
    // 8004A314: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A318:
    ctx->pc = 0x8004A318u;
    // 8004A318: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A31C:
    ctx->pc = 0x8004A31Cu;
    // 8004A31C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A320:
    ctx->pc = 0x8004A320u;
    // 8004A320: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A324:
    ctx->pc = 0x8004A324u;
    // 8004A324: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A328:
    ctx->pc = 0x8004A328u;
    // 8004A328: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A32Cu;
            goto label_8004B1A0;
    }

label_8004A32C:
    ctx->pc = 0x8004A32Cu;
    ctx->downcount -= 5;
    // 8004A32C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A330:
    ctx->pc = 0x8004A330u;
    // 8004A330: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A334:
    ctx->pc = 0x8004A334u;
    // 8004A334: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A338:
    ctx->pc = 0x8004A338u;
    // 8004A338: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A33C:
    ctx->pc = 0x8004A33Cu;
    ctx->downcount -= 8;
    // 8004A33C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A340:
    ctx->pc = 0x8004A340u;
    // 8004A340: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A344:
    ctx->pc = 0x8004A344u;
    // 8004A344: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A348:
    ctx->pc = 0x8004A348u;
    // 8004A348: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A34C:
    ctx->pc = 0x8004A34Cu;
    // 8004A34C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A350:
    ctx->pc = 0x8004A350u;
    // 8004A350: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A354:
    ctx->pc = 0x8004A354u;
    // 8004A354: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A358:
    ctx->pc = 0x8004A358u;
    // 8004A358: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A35Cu;
            goto label_8004B1A0;
    }

label_8004A35C:
    ctx->pc = 0x8004A35Cu;
    ctx->downcount -= 5;
    // 8004A35C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A360:
    ctx->pc = 0x8004A360u;
    // 8004A360: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A364:
    ctx->pc = 0x8004A364u;
    // 8004A364: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A368:
    ctx->pc = 0x8004A368u;
    // 8004A368: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A36C:
    ctx->pc = 0x8004A36Cu;
    ctx->downcount -= 8;
    // 8004A36C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A370:
    ctx->pc = 0x8004A370u;
    // 8004A370: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A374:
    ctx->pc = 0x8004A374u;
    // 8004A374: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A378:
    ctx->pc = 0x8004A378u;
    // 8004A378: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A37C:
    ctx->pc = 0x8004A37Cu;
    // 8004A37C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A380:
    ctx->pc = 0x8004A380u;
    // 8004A380: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A384:
    ctx->pc = 0x8004A384u;
    // 8004A384: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A388:
    ctx->pc = 0x8004A388u;
    // 8004A388: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A38Cu;
            goto label_8004B1A0;
    }

label_8004A38C:
    ctx->pc = 0x8004A38Cu;
    ctx->downcount -= 5;
    // 8004A38C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A390:
    ctx->pc = 0x8004A390u;
    // 8004A390: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A394:
    ctx->pc = 0x8004A394u;
    // 8004A394: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A398:
    ctx->pc = 0x8004A398u;
    // 8004A398: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A39C:
    ctx->pc = 0x8004A39Cu;
    ctx->downcount -= 8;
    // 8004A39C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A3A0:
    ctx->pc = 0x8004A3A0u;
    // 8004A3A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A3A4:
    ctx->pc = 0x8004A3A4u;
    // 8004A3A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A3A8:
    ctx->pc = 0x8004A3A8u;
    // 8004A3A8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A3AC:
    ctx->pc = 0x8004A3ACu;
    // 8004A3AC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A3B0:
    ctx->pc = 0x8004A3B0u;
    // 8004A3B0: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A3B4:
    ctx->pc = 0x8004A3B4u;
    // 8004A3B4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A3B8:
    ctx->pc = 0x8004A3B8u;
    // 8004A3B8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A3BCu;
            goto label_8004B1A0;
    }

label_8004A3BC:
    ctx->pc = 0x8004A3BCu;
    ctx->downcount -= 5;
    // 8004A3BC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A3C0:
    ctx->pc = 0x8004A3C0u;
    // 8004A3C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A3C4:
    ctx->pc = 0x8004A3C4u;
    // 8004A3C4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A3C8:
    ctx->pc = 0x8004A3C8u;
    // 8004A3C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A3CC:
    ctx->pc = 0x8004A3CCu;
    ctx->downcount -= 8;
    // 8004A3CC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A3D0:
    ctx->pc = 0x8004A3D0u;
    // 8004A3D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A3D4:
    ctx->pc = 0x8004A3D4u;
    // 8004A3D4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A3D8:
    ctx->pc = 0x8004A3D8u;
    // 8004A3D8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A3DC:
    ctx->pc = 0x8004A3DCu;
    // 8004A3DC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A3E0:
    ctx->pc = 0x8004A3E0u;
    // 8004A3E0: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A3E4:
    ctx->pc = 0x8004A3E4u;
    // 8004A3E4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A3E8:
    ctx->pc = 0x8004A3E8u;
    // 8004A3E8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A3ECu;
            goto label_8004B1A0;
    }

label_8004A3EC:
    ctx->pc = 0x8004A3ECu;
    ctx->downcount -= 5;
    // 8004A3EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A3F0:
    ctx->pc = 0x8004A3F0u;
    // 8004A3F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A3F4:
    ctx->pc = 0x8004A3F4u;
    // 8004A3F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A3F8:
    ctx->pc = 0x8004A3F8u;
    // 8004A3F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A3FC:
    ctx->pc = 0x8004A3FCu;
    ctx->downcount -= 8;
    // 8004A3FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A400:
    ctx->pc = 0x8004A400u;
    // 8004A400: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A404:
    ctx->pc = 0x8004A404u;
    // 8004A404: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A408:
    ctx->pc = 0x8004A408u;
    // 8004A408: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A40C:
    ctx->pc = 0x8004A40Cu;
    // 8004A40C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A410:
    ctx->pc = 0x8004A410u;
    // 8004A410: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A414:
    ctx->pc = 0x8004A414u;
    // 8004A414: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A418:
    ctx->pc = 0x8004A418u;
    // 8004A418: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A41Cu;
            goto label_8004B1A0;
    }

label_8004A41C:
    ctx->pc = 0x8004A41Cu;
    ctx->downcount -= 5;
    // 8004A41C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A420:
    ctx->pc = 0x8004A420u;
    // 8004A420: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A424:
    ctx->pc = 0x8004A424u;
    // 8004A424: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A428:
    ctx->pc = 0x8004A428u;
    // 8004A428: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A42C:
    ctx->pc = 0x8004A42Cu;
    ctx->downcount -= 8;
    // 8004A42C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A430:
    ctx->pc = 0x8004A430u;
    // 8004A430: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A434:
    ctx->pc = 0x8004A434u;
    // 8004A434: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A438:
    ctx->pc = 0x8004A438u;
    // 8004A438: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A43C:
    ctx->pc = 0x8004A43Cu;
    // 8004A43C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A440:
    ctx->pc = 0x8004A440u;
    // 8004A440: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A444:
    ctx->pc = 0x8004A444u;
    // 8004A444: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A448:
    ctx->pc = 0x8004A448u;
    // 8004A448: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A44Cu;
            goto label_8004B1A0;
    }

label_8004A44C:
    ctx->pc = 0x8004A44Cu;
    ctx->downcount -= 5;
    // 8004A44C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A450:
    ctx->pc = 0x8004A450u;
    // 8004A450: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A454:
    ctx->pc = 0x8004A454u;
    // 8004A454: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A458:
    ctx->pc = 0x8004A458u;
    // 8004A458: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A45C:
    ctx->pc = 0x8004A45Cu;
    ctx->downcount -= 8;
    // 8004A45C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A460:
    ctx->pc = 0x8004A460u;
    // 8004A460: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A464:
    ctx->pc = 0x8004A464u;
    // 8004A464: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A468:
    ctx->pc = 0x8004A468u;
    // 8004A468: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A46C:
    ctx->pc = 0x8004A46Cu;
    // 8004A46C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A470:
    ctx->pc = 0x8004A470u;
    // 8004A470: addi    r9, r9, 13816
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(13816);

label_8004A474:
    ctx->pc = 0x8004A474u;
    // 8004A474: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A478:
    ctx->pc = 0x8004A478u;
    // 8004A478: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A47Cu;
            goto label_8004B1A0;
    }

label_8004A47C:
    ctx->pc = 0x8004A47Cu;
    ctx->downcount -= 5;
    // 8004A47C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A480:
    ctx->pc = 0x8004A480u;
    // 8004A480: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A484:
    ctx->pc = 0x8004A484u;
    // 8004A484: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A488:
    ctx->pc = 0x8004A488u;
    // 8004A488: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A48C:
    ctx->pc = 0x8004A48Cu;
    ctx->downcount -= 8;
    // 8004A48C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A490:
    ctx->pc = 0x8004A490u;
    // 8004A490: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A494:
    ctx->pc = 0x8004A494u;
    // 8004A494: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A498:
    ctx->pc = 0x8004A498u;
    // 8004A498: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A49C:
    ctx->pc = 0x8004A49Cu;
    // 8004A49C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A4A0:
    ctx->pc = 0x8004A4A0u;
    // 8004A4A0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A4A4:
    ctx->pc = 0x8004A4A4u;
    // 8004A4A4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A4A8:
    ctx->pc = 0x8004A4A8u;
    // 8004A4A8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A4ACu;
            goto label_8004B1A0;
    }

label_8004A4AC:
    ctx->pc = 0x8004A4ACu;
    ctx->downcount -= 5;
    // 8004A4AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A4B0:
    ctx->pc = 0x8004A4B0u;
    // 8004A4B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A4B4:
    ctx->pc = 0x8004A4B4u;
    // 8004A4B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A4B8:
    ctx->pc = 0x8004A4B8u;
    // 8004A4B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A4BC:
    ctx->pc = 0x8004A4BCu;
    ctx->downcount -= 8;
    // 8004A4BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A4C0:
    ctx->pc = 0x8004A4C0u;
    // 8004A4C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A4C4:
    ctx->pc = 0x8004A4C4u;
    // 8004A4C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A4C8:
    ctx->pc = 0x8004A4C8u;
    // 8004A4C8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A4CC:
    ctx->pc = 0x8004A4CCu;
    // 8004A4CC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A4D0:
    ctx->pc = 0x8004A4D0u;
    // 8004A4D0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A4D4:
    ctx->pc = 0x8004A4D4u;
    // 8004A4D4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A4D8:
    ctx->pc = 0x8004A4D8u;
    // 8004A4D8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A4DCu;
            goto label_8004B1A0;
    }

label_8004A4DC:
    ctx->pc = 0x8004A4DCu;
    ctx->downcount -= 5;
    // 8004A4DC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A4E0:
    ctx->pc = 0x8004A4E0u;
    // 8004A4E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A4E4:
    ctx->pc = 0x8004A4E4u;
    // 8004A4E4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A4E8:
    ctx->pc = 0x8004A4E8u;
    // 8004A4E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A4EC:
    ctx->pc = 0x8004A4ECu;
    ctx->downcount -= 8;
    // 8004A4EC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A4F0:
    ctx->pc = 0x8004A4F0u;
    // 8004A4F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A4F4:
    ctx->pc = 0x8004A4F4u;
    // 8004A4F4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A4F8:
    ctx->pc = 0x8004A4F8u;
    // 8004A4F8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A4FC:
    ctx->pc = 0x8004A4FCu;
    // 8004A4FC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A500:
    ctx->pc = 0x8004A500u;
    // 8004A500: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A504:
    ctx->pc = 0x8004A504u;
    // 8004A504: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A508:
    ctx->pc = 0x8004A508u;
    // 8004A508: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A50Cu;
            goto label_8004B1A0;
    }

label_8004A50C:
    ctx->pc = 0x8004A50Cu;
    ctx->downcount -= 5;
    // 8004A50C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A510:
    ctx->pc = 0x8004A510u;
    // 8004A510: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A514:
    ctx->pc = 0x8004A514u;
    // 8004A514: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A518:
    ctx->pc = 0x8004A518u;
    // 8004A518: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A51C:
    ctx->pc = 0x8004A51Cu;
    ctx->downcount -= 8;
    // 8004A51C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A520:
    ctx->pc = 0x8004A520u;
    // 8004A520: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A524:
    ctx->pc = 0x8004A524u;
    // 8004A524: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A528:
    ctx->pc = 0x8004A528u;
    // 8004A528: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A52C:
    ctx->pc = 0x8004A52Cu;
    // 8004A52C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A530:
    ctx->pc = 0x8004A530u;
    // 8004A530: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A534:
    ctx->pc = 0x8004A534u;
    // 8004A534: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A538:
    ctx->pc = 0x8004A538u;
    // 8004A538: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A53Cu;
            goto label_8004B1A0;
    }

label_8004A53C:
    ctx->pc = 0x8004A53Cu;
    ctx->downcount -= 5;
    // 8004A53C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A540:
    ctx->pc = 0x8004A540u;
    // 8004A540: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A544:
    ctx->pc = 0x8004A544u;
    // 8004A544: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A548:
    ctx->pc = 0x8004A548u;
    // 8004A548: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A54C:
    ctx->pc = 0x8004A54Cu;
    ctx->downcount -= 8;
    // 8004A54C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A550:
    ctx->pc = 0x8004A550u;
    // 8004A550: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A554:
    ctx->pc = 0x8004A554u;
    // 8004A554: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A558:
    ctx->pc = 0x8004A558u;
    // 8004A558: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A55C:
    ctx->pc = 0x8004A55Cu;
    // 8004A55C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A560:
    ctx->pc = 0x8004A560u;
    // 8004A560: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A564:
    ctx->pc = 0x8004A564u;
    // 8004A564: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A568:
    ctx->pc = 0x8004A568u;
    // 8004A568: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A56Cu;
            goto label_8004B1A0;
    }

label_8004A56C:
    ctx->pc = 0x8004A56Cu;
    ctx->downcount -= 5;
    // 8004A56C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A570:
    ctx->pc = 0x8004A570u;
    // 8004A570: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A574:
    ctx->pc = 0x8004A574u;
    // 8004A574: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A578:
    ctx->pc = 0x8004A578u;
    // 8004A578: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A57C:
    ctx->pc = 0x8004A57Cu;
    ctx->downcount -= 8;
    // 8004A57C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A580:
    ctx->pc = 0x8004A580u;
    // 8004A580: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A584:
    ctx->pc = 0x8004A584u;
    // 8004A584: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A588:
    ctx->pc = 0x8004A588u;
    // 8004A588: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A58C:
    ctx->pc = 0x8004A58Cu;
    // 8004A58C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A590:
    ctx->pc = 0x8004A590u;
    // 8004A590: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A594:
    ctx->pc = 0x8004A594u;
    // 8004A594: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A598:
    ctx->pc = 0x8004A598u;
    // 8004A598: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A59Cu;
            goto label_8004B1A0;
    }

label_8004A59C:
    ctx->pc = 0x8004A59Cu;
    ctx->downcount -= 5;
    // 8004A59C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A5A0:
    ctx->pc = 0x8004A5A0u;
    // 8004A5A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A5A4:
    ctx->pc = 0x8004A5A4u;
    // 8004A5A4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A5A8:
    ctx->pc = 0x8004A5A8u;
    // 8004A5A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A5AC:
    ctx->pc = 0x8004A5ACu;
    ctx->downcount -= 8;
    // 8004A5AC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A5B0:
    ctx->pc = 0x8004A5B0u;
    // 8004A5B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A5B4:
    ctx->pc = 0x8004A5B4u;
    // 8004A5B4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A5B8:
    ctx->pc = 0x8004A5B8u;
    // 8004A5B8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A5BC:
    ctx->pc = 0x8004A5BCu;
    // 8004A5BC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A5C0:
    ctx->pc = 0x8004A5C0u;
    // 8004A5C0: addi    r9, r9, 18752
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18752);

label_8004A5C4:
    ctx->pc = 0x8004A5C4u;
    // 8004A5C4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A5C8:
    ctx->pc = 0x8004A5C8u;
    // 8004A5C8: bl      0x8004BE94
    {
            ctx->lr = 0x8004A5CCu;
            ctx->pc = 0x8004BE94u;
            return;
    }

label_8004A5CC:
    ctx->pc = 0x8004A5CCu;
    ctx->downcount -= 5;
    // 8004A5CC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A5D0:
    ctx->pc = 0x8004A5D0u;
    // 8004A5D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A5D4:
    ctx->pc = 0x8004A5D4u;
    // 8004A5D4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A5D8:
    ctx->pc = 0x8004A5D8u;
    // 8004A5D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A5DC:
    ctx->pc = 0x8004A5DCu;
    ctx->downcount -= 8;
    // 8004A5DC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A5E0:
    ctx->pc = 0x8004A5E0u;
    // 8004A5E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A5E4:
    ctx->pc = 0x8004A5E4u;
    // 8004A5E4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A5E8:
    ctx->pc = 0x8004A5E8u;
    // 8004A5E8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A5EC:
    ctx->pc = 0x8004A5ECu;
    // 8004A5EC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A5F0:
    ctx->pc = 0x8004A5F0u;
    // 8004A5F0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A5F4:
    ctx->pc = 0x8004A5F4u;
    // 8004A5F4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A5F8:
    ctx->pc = 0x8004A5F8u;
    // 8004A5F8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A5FCu;
            goto label_8004B1A0;
    }

label_8004A5FC:
    ctx->pc = 0x8004A5FCu;
    ctx->downcount -= 5;
    // 8004A5FC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A600:
    ctx->pc = 0x8004A600u;
    // 8004A600: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A604:
    ctx->pc = 0x8004A604u;
    // 8004A604: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A608:
    ctx->pc = 0x8004A608u;
    // 8004A608: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A60C:
    ctx->pc = 0x8004A60Cu;
    ctx->downcount -= 8;
    // 8004A60C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A610:
    ctx->pc = 0x8004A610u;
    // 8004A610: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A614:
    ctx->pc = 0x8004A614u;
    // 8004A614: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A618:
    ctx->pc = 0x8004A618u;
    // 8004A618: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A61C:
    ctx->pc = 0x8004A61Cu;
    // 8004A61C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A620:
    ctx->pc = 0x8004A620u;
    // 8004A620: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A624:
    ctx->pc = 0x8004A624u;
    // 8004A624: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A628:
    ctx->pc = 0x8004A628u;
    // 8004A628: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A62Cu;
            goto label_8004B1A0;
    }

label_8004A62C:
    ctx->pc = 0x8004A62Cu;
    ctx->downcount -= 5;
    // 8004A62C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A630:
    ctx->pc = 0x8004A630u;
    // 8004A630: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A634:
    ctx->pc = 0x8004A634u;
    // 8004A634: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A638:
    ctx->pc = 0x8004A638u;
    // 8004A638: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A63C:
    ctx->pc = 0x8004A63Cu;
    ctx->downcount -= 8;
    // 8004A63C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A640:
    ctx->pc = 0x8004A640u;
    // 8004A640: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A644:
    ctx->pc = 0x8004A644u;
    // 8004A644: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A648:
    ctx->pc = 0x8004A648u;
    // 8004A648: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A64C:
    ctx->pc = 0x8004A64Cu;
    // 8004A64C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A650:
    ctx->pc = 0x8004A650u;
    // 8004A650: addi    r9, r9, 12440
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(12440);

label_8004A654:
    ctx->pc = 0x8004A654u;
    // 8004A654: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A658:
    ctx->pc = 0x8004A658u;
    // 8004A658: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A65Cu;
            goto label_8004B1A0;
    }

label_8004A65C:
    ctx->pc = 0x8004A65Cu;
    ctx->downcount -= 5;
    // 8004A65C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A660:
    ctx->pc = 0x8004A660u;
    // 8004A660: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A664:
    ctx->pc = 0x8004A664u;
    // 8004A664: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A668:
    ctx->pc = 0x8004A668u;
    // 8004A668: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A66C:
    ctx->pc = 0x8004A66Cu;
    ctx->downcount -= 8;
    // 8004A66C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A670:
    ctx->pc = 0x8004A670u;
    // 8004A670: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A674:
    ctx->pc = 0x8004A674u;
    // 8004A674: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A678:
    ctx->pc = 0x8004A678u;
    // 8004A678: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A67C:
    ctx->pc = 0x8004A67Cu;
    // 8004A67C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A680:
    ctx->pc = 0x8004A680u;
    // 8004A680: addi    r9, r9, 18344
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18344);

label_8004A684:
    ctx->pc = 0x8004A684u;
    // 8004A684: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A688:
    ctx->pc = 0x8004A688u;
    // 8004A688: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A68Cu;
            goto label_8004B1A0;
    }

label_8004A68C:
    ctx->pc = 0x8004A68Cu;
    ctx->downcount -= 5;
    // 8004A68C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A690:
    ctx->pc = 0x8004A690u;
    // 8004A690: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A694:
    ctx->pc = 0x8004A694u;
    // 8004A694: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A698:
    ctx->pc = 0x8004A698u;
    // 8004A698: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A69C:
    ctx->pc = 0x8004A69Cu;
    ctx->downcount -= 8;
    // 8004A69C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A6A0:
    ctx->pc = 0x8004A6A0u;
    // 8004A6A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A6A4:
    ctx->pc = 0x8004A6A4u;
    // 8004A6A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A6A8:
    ctx->pc = 0x8004A6A8u;
    // 8004A6A8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A6AC:
    ctx->pc = 0x8004A6ACu;
    // 8004A6AC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A6B0:
    ctx->pc = 0x8004A6B0u;
    // 8004A6B0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A6B4:
    ctx->pc = 0x8004A6B4u;
    // 8004A6B4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A6B8:
    ctx->pc = 0x8004A6B8u;
    // 8004A6B8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A6BCu;
            goto label_8004B1A0;
    }

label_8004A6BC:
    ctx->pc = 0x8004A6BCu;
    ctx->downcount -= 5;
    // 8004A6BC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A6C0:
    ctx->pc = 0x8004A6C0u;
    // 8004A6C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A6C4:
    ctx->pc = 0x8004A6C4u;
    // 8004A6C4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A6C8:
    ctx->pc = 0x8004A6C8u;
    // 8004A6C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A6CC:
    ctx->pc = 0x8004A6CCu;
    ctx->downcount -= 8;
    // 8004A6CC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A6D0:
    ctx->pc = 0x8004A6D0u;
    // 8004A6D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A6D4:
    ctx->pc = 0x8004A6D4u;
    // 8004A6D4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A6D8:
    ctx->pc = 0x8004A6D8u;
    // 8004A6D8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A6DC:
    ctx->pc = 0x8004A6DCu;
    // 8004A6DC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A6E0:
    ctx->pc = 0x8004A6E0u;
    // 8004A6E0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A6E4:
    ctx->pc = 0x8004A6E4u;
    // 8004A6E4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A6E8:
    ctx->pc = 0x8004A6E8u;
    // 8004A6E8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A6ECu;
            goto label_8004B1A0;
    }

label_8004A6EC:
    ctx->pc = 0x8004A6ECu;
    ctx->downcount -= 5;
    // 8004A6EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A6F0:
    ctx->pc = 0x8004A6F0u;
    // 8004A6F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A6F4:
    ctx->pc = 0x8004A6F4u;
    // 8004A6F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A6F8:
    ctx->pc = 0x8004A6F8u;
    // 8004A6F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A6FC:
    ctx->pc = 0x8004A6FCu;
    ctx->downcount -= 8;
    // 8004A6FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A700:
    ctx->pc = 0x8004A700u;
    // 8004A700: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A704:
    ctx->pc = 0x8004A704u;
    // 8004A704: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A708:
    ctx->pc = 0x8004A708u;
    // 8004A708: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A70C:
    ctx->pc = 0x8004A70Cu;
    // 8004A70C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A710:
    ctx->pc = 0x8004A710u;
    // 8004A710: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A714:
    ctx->pc = 0x8004A714u;
    // 8004A714: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A718:
    ctx->pc = 0x8004A718u;
    // 8004A718: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A71Cu;
            goto label_8004B1A0;
    }

label_8004A71C:
    ctx->pc = 0x8004A71Cu;
    ctx->downcount -= 5;
    // 8004A71C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A720:
    ctx->pc = 0x8004A720u;
    // 8004A720: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A724:
    ctx->pc = 0x8004A724u;
    // 8004A724: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A728:
    ctx->pc = 0x8004A728u;
    // 8004A728: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A72C:
    ctx->pc = 0x8004A72Cu;
    ctx->downcount -= 8;
    // 8004A72C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A730:
    ctx->pc = 0x8004A730u;
    // 8004A730: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A734:
    ctx->pc = 0x8004A734u;
    // 8004A734: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A738:
    ctx->pc = 0x8004A738u;
    // 8004A738: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A73C:
    ctx->pc = 0x8004A73Cu;
    // 8004A73C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A740:
    ctx->pc = 0x8004A740u;
    // 8004A740: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A744:
    ctx->pc = 0x8004A744u;
    // 8004A744: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A748:
    ctx->pc = 0x8004A748u;
    // 8004A748: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A74Cu;
            goto label_8004B1A0;
    }

label_8004A74C:
    ctx->pc = 0x8004A74Cu;
    ctx->downcount -= 5;
    // 8004A74C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A750:
    ctx->pc = 0x8004A750u;
    // 8004A750: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A754:
    ctx->pc = 0x8004A754u;
    // 8004A754: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A758:
    ctx->pc = 0x8004A758u;
    // 8004A758: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A75C:
    ctx->pc = 0x8004A75Cu;
    ctx->downcount -= 8;
    // 8004A75C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A760:
    ctx->pc = 0x8004A760u;
    // 8004A760: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A764:
    ctx->pc = 0x8004A764u;
    // 8004A764: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A768:
    ctx->pc = 0x8004A768u;
    // 8004A768: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A76C:
    ctx->pc = 0x8004A76Cu;
    // 8004A76C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A770:
    ctx->pc = 0x8004A770u;
    // 8004A770: addi    r9, r9, 12016
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(12016);

label_8004A774:
    ctx->pc = 0x8004A774u;
    // 8004A774: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A778:
    ctx->pc = 0x8004A778u;
    // 8004A778: bl      0x8004BE94
    {
            ctx->lr = 0x8004A77Cu;
            ctx->pc = 0x8004BE94u;
            return;
    }

label_8004A77C:
    ctx->pc = 0x8004A77Cu;
    ctx->downcount -= 5;
    // 8004A77C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A780:
    ctx->pc = 0x8004A780u;
    // 8004A780: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A784:
    ctx->pc = 0x8004A784u;
    // 8004A784: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A788:
    ctx->pc = 0x8004A788u;
    // 8004A788: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A78C:
    ctx->pc = 0x8004A78Cu;
    ctx->downcount -= 8;
    // 8004A78C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A790:
    ctx->pc = 0x8004A790u;
    // 8004A790: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A794:
    ctx->pc = 0x8004A794u;
    // 8004A794: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A798:
    ctx->pc = 0x8004A798u;
    // 8004A798: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A79C:
    ctx->pc = 0x8004A79Cu;
    // 8004A79C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A7A0:
    ctx->pc = 0x8004A7A0u;
    // 8004A7A0: addi    r9, r9, 11944
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(11944);

label_8004A7A4:
    ctx->pc = 0x8004A7A4u;
    // 8004A7A4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A7A8:
    ctx->pc = 0x8004A7A8u;
    // 8004A7A8: bl      0x8004BE94
    {
            ctx->lr = 0x8004A7ACu;
            ctx->pc = 0x8004BE94u;
            return;
    }

label_8004A7AC:
    ctx->pc = 0x8004A7ACu;
    ctx->downcount -= 5;
    // 8004A7AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A7B0:
    ctx->pc = 0x8004A7B0u;
    // 8004A7B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A7B4:
    ctx->pc = 0x8004A7B4u;
    // 8004A7B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A7B8:
    ctx->pc = 0x8004A7B8u;
    // 8004A7B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A7BC:
    ctx->pc = 0x8004A7BCu;
    ctx->downcount -= 8;
    // 8004A7BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A7C0:
    ctx->pc = 0x8004A7C0u;
    // 8004A7C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A7C4:
    ctx->pc = 0x8004A7C4u;
    // 8004A7C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A7C8:
    ctx->pc = 0x8004A7C8u;
    // 8004A7C8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A7CC:
    ctx->pc = 0x8004A7CCu;
    // 8004A7CC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A7D0:
    ctx->pc = 0x8004A7D0u;
    // 8004A7D0: addi    r9, r9, 11888
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(11888);

label_8004A7D4:
    ctx->pc = 0x8004A7D4u;
    // 8004A7D4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A7D8:
    ctx->pc = 0x8004A7D8u;
    // 8004A7D8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A7DCu;
            goto label_8004B1A0;
    }

label_8004A7DC:
    ctx->pc = 0x8004A7DCu;
    ctx->downcount -= 5;
    // 8004A7DC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A7E0:
    ctx->pc = 0x8004A7E0u;
    // 8004A7E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A7E4:
    ctx->pc = 0x8004A7E4u;
    // 8004A7E4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A7E8:
    ctx->pc = 0x8004A7E8u;
    // 8004A7E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A7EC:
    ctx->pc = 0x8004A7ECu;
    ctx->downcount -= 8;
    // 8004A7EC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A7F0:
    ctx->pc = 0x8004A7F0u;
    // 8004A7F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A7F4:
    ctx->pc = 0x8004A7F4u;
    // 8004A7F4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A7F8:
    ctx->pc = 0x8004A7F8u;
    // 8004A7F8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A7FC:
    ctx->pc = 0x8004A7FCu;
    // 8004A7FC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A800:
    ctx->pc = 0x8004A800u;
    // 8004A800: addi    r9, r9, 18344
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18344);

label_8004A804:
    ctx->pc = 0x8004A804u;
    // 8004A804: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A808:
    ctx->pc = 0x8004A808u;
    // 8004A808: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A80Cu;
            goto label_8004B1A0;
    }

label_8004A80C:
    ctx->pc = 0x8004A80Cu;
    ctx->downcount -= 5;
    // 8004A80C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A810:
    ctx->pc = 0x8004A810u;
    // 8004A810: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A814:
    ctx->pc = 0x8004A814u;
    // 8004A814: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A818:
    ctx->pc = 0x8004A818u;
    // 8004A818: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A81C:
    ctx->pc = 0x8004A81Cu;
    ctx->downcount -= 8;
    // 8004A81C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A820:
    ctx->pc = 0x8004A820u;
    // 8004A820: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A824:
    ctx->pc = 0x8004A824u;
    // 8004A824: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A828:
    ctx->pc = 0x8004A828u;
    // 8004A828: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A82C:
    ctx->pc = 0x8004A82Cu;
    // 8004A82C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A830:
    ctx->pc = 0x8004A830u;
    // 8004A830: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A834:
    ctx->pc = 0x8004A834u;
    // 8004A834: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A838:
    ctx->pc = 0x8004A838u;
    // 8004A838: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A83Cu;
            goto label_8004B1A0;
    }

label_8004A83C:
    ctx->pc = 0x8004A83Cu;
    ctx->downcount -= 5;
    // 8004A83C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A840:
    ctx->pc = 0x8004A840u;
    // 8004A840: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A844:
    ctx->pc = 0x8004A844u;
    // 8004A844: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A848:
    ctx->pc = 0x8004A848u;
    // 8004A848: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A84C:
    ctx->pc = 0x8004A84Cu;
    ctx->downcount -= 8;
    // 8004A84C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A850:
    ctx->pc = 0x8004A850u;
    // 8004A850: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A854:
    ctx->pc = 0x8004A854u;
    // 8004A854: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A858:
    ctx->pc = 0x8004A858u;
    // 8004A858: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A85C:
    ctx->pc = 0x8004A85Cu;
    // 8004A85C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A860:
    ctx->pc = 0x8004A860u;
    // 8004A860: addi    r9, r9, 11680
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(11680);

label_8004A864:
    ctx->pc = 0x8004A864u;
    // 8004A864: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A868:
    ctx->pc = 0x8004A868u;
    // 8004A868: bl      0x8004BE94
    {
            ctx->lr = 0x8004A86Cu;
            ctx->pc = 0x8004BE94u;
            return;
    }

label_8004A86C:
    ctx->pc = 0x8004A86Cu;
    ctx->downcount -= 5;
    // 8004A86C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A870:
    ctx->pc = 0x8004A870u;
    // 8004A870: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A874:
    ctx->pc = 0x8004A874u;
    // 8004A874: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A878:
    ctx->pc = 0x8004A878u;
    // 8004A878: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A87C:
    ctx->pc = 0x8004A87Cu;
    ctx->downcount -= 8;
    // 8004A87C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A880:
    ctx->pc = 0x8004A880u;
    // 8004A880: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A884:
    ctx->pc = 0x8004A884u;
    // 8004A884: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A888:
    ctx->pc = 0x8004A888u;
    // 8004A888: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A88C:
    ctx->pc = 0x8004A88Cu;
    // 8004A88C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A890:
    ctx->pc = 0x8004A890u;
    // 8004A890: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A894:
    ctx->pc = 0x8004A894u;
    // 8004A894: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A898:
    ctx->pc = 0x8004A898u;
    // 8004A898: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A89Cu;
            goto label_8004B1A0;
    }

label_8004A89C:
    ctx->pc = 0x8004A89Cu;
    ctx->downcount -= 5;
    // 8004A89C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A8A0:
    ctx->pc = 0x8004A8A0u;
    // 8004A8A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A8A4:
    ctx->pc = 0x8004A8A4u;
    // 8004A8A4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A8A8:
    ctx->pc = 0x8004A8A8u;
    // 8004A8A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A8AC:
    ctx->pc = 0x8004A8ACu;
    ctx->downcount -= 8;
    // 8004A8AC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A8B0:
    ctx->pc = 0x8004A8B0u;
    // 8004A8B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A8B4:
    ctx->pc = 0x8004A8B4u;
    // 8004A8B4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A8B8:
    ctx->pc = 0x8004A8B8u;
    // 8004A8B8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A8BC:
    ctx->pc = 0x8004A8BCu;
    // 8004A8BC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A8C0:
    ctx->pc = 0x8004A8C0u;
    // 8004A8C0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A8C4:
    ctx->pc = 0x8004A8C4u;
    // 8004A8C4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A8C8:
    ctx->pc = 0x8004A8C8u;
    // 8004A8C8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A8CCu;
            goto label_8004B1A0;
    }

label_8004A8CC:
    ctx->pc = 0x8004A8CCu;
    ctx->downcount -= 5;
    // 8004A8CC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A8D0:
    ctx->pc = 0x8004A8D0u;
    // 8004A8D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A8D4:
    ctx->pc = 0x8004A8D4u;
    // 8004A8D4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A8D8:
    ctx->pc = 0x8004A8D8u;
    // 8004A8D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A8DC:
    ctx->pc = 0x8004A8DCu;
    ctx->downcount -= 8;
    // 8004A8DC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A8E0:
    ctx->pc = 0x8004A8E0u;
    // 8004A8E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A8E4:
    ctx->pc = 0x8004A8E4u;
    // 8004A8E4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A8E8:
    ctx->pc = 0x8004A8E8u;
    // 8004A8E8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A8EC:
    ctx->pc = 0x8004A8ECu;
    // 8004A8EC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A8F0:
    ctx->pc = 0x8004A8F0u;
    // 8004A8F0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A8F4:
    ctx->pc = 0x8004A8F4u;
    // 8004A8F4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A8F8:
    ctx->pc = 0x8004A8F8u;
    // 8004A8F8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A8FCu;
            goto label_8004B1A0;
    }

label_8004A8FC:
    ctx->pc = 0x8004A8FCu;
    ctx->downcount -= 5;
    // 8004A8FC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A900:
    ctx->pc = 0x8004A900u;
    // 8004A900: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A904:
    ctx->pc = 0x8004A904u;
    // 8004A904: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A908:
    ctx->pc = 0x8004A908u;
    // 8004A908: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A90C:
    ctx->pc = 0x8004A90Cu;
    ctx->downcount -= 8;
    // 8004A90C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A910:
    ctx->pc = 0x8004A910u;
    // 8004A910: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A914:
    ctx->pc = 0x8004A914u;
    // 8004A914: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A918:
    ctx->pc = 0x8004A918u;
    // 8004A918: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A91C:
    ctx->pc = 0x8004A91Cu;
    // 8004A91C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A920:
    ctx->pc = 0x8004A920u;
    // 8004A920: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A924:
    ctx->pc = 0x8004A924u;
    // 8004A924: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A928:
    ctx->pc = 0x8004A928u;
    // 8004A928: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A92Cu;
            goto label_8004B1A0;
    }

label_8004A92C:
    ctx->pc = 0x8004A92Cu;
    ctx->downcount -= 5;
    // 8004A92C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A930:
    ctx->pc = 0x8004A930u;
    // 8004A930: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A934:
    ctx->pc = 0x8004A934u;
    // 8004A934: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A938:
    ctx->pc = 0x8004A938u;
    // 8004A938: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A93C:
    ctx->pc = 0x8004A93Cu;
    ctx->downcount -= 8;
    // 8004A93C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A940:
    ctx->pc = 0x8004A940u;
    // 8004A940: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A944:
    ctx->pc = 0x8004A944u;
    // 8004A944: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A948:
    ctx->pc = 0x8004A948u;
    // 8004A948: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A94C:
    ctx->pc = 0x8004A94Cu;
    // 8004A94C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A950:
    ctx->pc = 0x8004A950u;
    // 8004A950: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A954:
    ctx->pc = 0x8004A954u;
    // 8004A954: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A958:
    ctx->pc = 0x8004A958u;
    // 8004A958: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A95Cu;
            goto label_8004B1A0;
    }

label_8004A95C:
    ctx->pc = 0x8004A95Cu;
    ctx->downcount -= 5;
    // 8004A95C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A960:
    ctx->pc = 0x8004A960u;
    // 8004A960: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A964:
    ctx->pc = 0x8004A964u;
    // 8004A964: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A968:
    ctx->pc = 0x8004A968u;
    // 8004A968: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A96C:
    ctx->pc = 0x8004A96Cu;
    ctx->downcount -= 8;
    // 8004A96C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A970:
    ctx->pc = 0x8004A970u;
    // 8004A970: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A974:
    ctx->pc = 0x8004A974u;
    // 8004A974: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A978:
    ctx->pc = 0x8004A978u;
    // 8004A978: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A97C:
    ctx->pc = 0x8004A97Cu;
    // 8004A97C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A980:
    ctx->pc = 0x8004A980u;
    // 8004A980: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A984:
    ctx->pc = 0x8004A984u;
    // 8004A984: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A988:
    ctx->pc = 0x8004A988u;
    // 8004A988: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A98Cu;
            goto label_8004B1A0;
    }

label_8004A98C:
    ctx->pc = 0x8004A98Cu;
    ctx->downcount -= 5;
    // 8004A98C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A990:
    ctx->pc = 0x8004A990u;
    // 8004A990: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A994:
    ctx->pc = 0x8004A994u;
    // 8004A994: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A998:
    ctx->pc = 0x8004A998u;
    // 8004A998: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A99C:
    ctx->pc = 0x8004A99Cu;
    ctx->downcount -= 8;
    // 8004A99C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A9A0:
    ctx->pc = 0x8004A9A0u;
    // 8004A9A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A9A4:
    ctx->pc = 0x8004A9A4u;
    // 8004A9A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A9A8:
    ctx->pc = 0x8004A9A8u;
    // 8004A9A8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A9AC:
    ctx->pc = 0x8004A9ACu;
    // 8004A9AC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A9B0:
    ctx->pc = 0x8004A9B0u;
    // 8004A9B0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A9B4:
    ctx->pc = 0x8004A9B4u;
    // 8004A9B4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A9B8:
    ctx->pc = 0x8004A9B8u;
    // 8004A9B8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A9BCu;
            goto label_8004B1A0;
    }

label_8004A9BC:
    ctx->pc = 0x8004A9BCu;
    ctx->downcount -= 5;
    // 8004A9BC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A9C0:
    ctx->pc = 0x8004A9C0u;
    // 8004A9C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A9C4:
    ctx->pc = 0x8004A9C4u;
    // 8004A9C4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A9C8:
    ctx->pc = 0x8004A9C8u;
    // 8004A9C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A9CC:
    ctx->pc = 0x8004A9CCu;
    ctx->downcount -= 8;
    // 8004A9CC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A9D0:
    ctx->pc = 0x8004A9D0u;
    // 8004A9D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A9D4:
    ctx->pc = 0x8004A9D4u;
    // 8004A9D4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A9D8:
    ctx->pc = 0x8004A9D8u;
    // 8004A9D8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004A9DC:
    ctx->pc = 0x8004A9DCu;
    // 8004A9DC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A9E0:
    ctx->pc = 0x8004A9E0u;
    // 8004A9E0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004A9E4:
    ctx->pc = 0x8004A9E4u;
    // 8004A9E4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004A9E8:
    ctx->pc = 0x8004A9E8u;
    // 8004A9E8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004A9ECu;
            goto label_8004B1A0;
    }

label_8004A9EC:
    ctx->pc = 0x8004A9ECu;
    ctx->downcount -= 5;
    // 8004A9EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A9F0:
    ctx->pc = 0x8004A9F0u;
    // 8004A9F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A9F4:
    ctx->pc = 0x8004A9F4u;
    // 8004A9F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A9F8:
    ctx->pc = 0x8004A9F8u;
    // 8004A9F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004A9FC:
    ctx->pc = 0x8004A9FCu;
    ctx->downcount -= 8;
    // 8004A9FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AA00:
    ctx->pc = 0x8004AA00u;
    // 8004AA00: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AA04:
    ctx->pc = 0x8004AA04u;
    // 8004AA04: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AA08:
    ctx->pc = 0x8004AA08u;
    // 8004AA08: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AA0C:
    ctx->pc = 0x8004AA0Cu;
    // 8004AA0C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AA10:
    ctx->pc = 0x8004AA10u;
    // 8004AA10: addi    r9, r9, 11008
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(11008);

label_8004AA14:
    ctx->pc = 0x8004AA14u;
    // 8004AA14: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AA18:
    ctx->pc = 0x8004AA18u;
    // 8004AA18: bl      0x8004BE94
    {
            ctx->lr = 0x8004AA1Cu;
            ctx->pc = 0x8004BE94u;
            return;
    }

label_8004AA1C:
    ctx->pc = 0x8004AA1Cu;
    ctx->downcount -= 5;
    // 8004AA1C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AA20:
    ctx->pc = 0x8004AA20u;
    // 8004AA20: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AA24:
    ctx->pc = 0x8004AA24u;
    // 8004AA24: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AA28:
    ctx->pc = 0x8004AA28u;
    // 8004AA28: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AA2C:
    ctx->pc = 0x8004AA2Cu;
    ctx->downcount -= 8;
    // 8004AA2C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AA30:
    ctx->pc = 0x8004AA30u;
    // 8004AA30: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AA34:
    ctx->pc = 0x8004AA34u;
    // 8004AA34: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AA38:
    ctx->pc = 0x8004AA38u;
    // 8004AA38: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AA3C:
    ctx->pc = 0x8004AA3Cu;
    // 8004AA3C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AA40:
    ctx->pc = 0x8004AA40u;
    // 8004AA40: addi    r9, r9, 18344
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18344);

label_8004AA44:
    ctx->pc = 0x8004AA44u;
    // 8004AA44: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AA48:
    ctx->pc = 0x8004AA48u;
    // 8004AA48: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AA4Cu;
            goto label_8004B1A0;
    }

label_8004AA4C:
    ctx->pc = 0x8004AA4Cu;
    ctx->downcount -= 5;
    // 8004AA4C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AA50:
    ctx->pc = 0x8004AA50u;
    // 8004AA50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AA54:
    ctx->pc = 0x8004AA54u;
    // 8004AA54: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AA58:
    ctx->pc = 0x8004AA58u;
    // 8004AA58: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AA5C:
    ctx->pc = 0x8004AA5Cu;
    ctx->downcount -= 8;
    // 8004AA5C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AA60:
    ctx->pc = 0x8004AA60u;
    // 8004AA60: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AA64:
    ctx->pc = 0x8004AA64u;
    // 8004AA64: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AA68:
    ctx->pc = 0x8004AA68u;
    // 8004AA68: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AA6C:
    ctx->pc = 0x8004AA6Cu;
    // 8004AA6C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AA70:
    ctx->pc = 0x8004AA70u;
    // 8004AA70: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AA74:
    ctx->pc = 0x8004AA74u;
    // 8004AA74: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AA78:
    ctx->pc = 0x8004AA78u;
    // 8004AA78: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AA7Cu;
            goto label_8004B1A0;
    }

label_8004AA7C:
    ctx->pc = 0x8004AA7Cu;
    ctx->downcount -= 5;
    // 8004AA7C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AA80:
    ctx->pc = 0x8004AA80u;
    // 8004AA80: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AA84:
    ctx->pc = 0x8004AA84u;
    // 8004AA84: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AA88:
    ctx->pc = 0x8004AA88u;
    // 8004AA88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AA8C:
    ctx->pc = 0x8004AA8Cu;
    ctx->downcount -= 8;
    // 8004AA8C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AA90:
    ctx->pc = 0x8004AA90u;
    // 8004AA90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AA94:
    ctx->pc = 0x8004AA94u;
    // 8004AA94: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AA98:
    ctx->pc = 0x8004AA98u;
    // 8004AA98: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AA9C:
    ctx->pc = 0x8004AA9Cu;
    // 8004AA9C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AAA0:
    ctx->pc = 0x8004AAA0u;
    // 8004AAA0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AAA4:
    ctx->pc = 0x8004AAA4u;
    // 8004AAA4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AAA8:
    ctx->pc = 0x8004AAA8u;
    // 8004AAA8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AAACu;
            goto label_8004B1A0;
    }

label_8004AAAC:
    ctx->pc = 0x8004AAACu;
    ctx->downcount -= 5;
    // 8004AAAC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AAB0:
    ctx->pc = 0x8004AAB0u;
    // 8004AAB0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AAB4:
    ctx->pc = 0x8004AAB4u;
    // 8004AAB4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AAB8:
    ctx->pc = 0x8004AAB8u;
    // 8004AAB8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AABC:
    ctx->pc = 0x8004AABCu;
    ctx->downcount -= 8;
    // 8004AABC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AAC0:
    ctx->pc = 0x8004AAC0u;
    // 8004AAC0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AAC4:
    ctx->pc = 0x8004AAC4u;
    // 8004AAC4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AAC8:
    ctx->pc = 0x8004AAC8u;
    // 8004AAC8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AACC:
    ctx->pc = 0x8004AACCu;
    // 8004AACC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AAD0:
    ctx->pc = 0x8004AAD0u;
    // 8004AAD0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AAD4:
    ctx->pc = 0x8004AAD4u;
    // 8004AAD4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AAD8:
    ctx->pc = 0x8004AAD8u;
    // 8004AAD8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AADCu;
            goto label_8004B1A0;
    }

label_8004AADC:
    ctx->pc = 0x8004AADCu;
    ctx->downcount -= 5;
    // 8004AADC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AAE0:
    ctx->pc = 0x8004AAE0u;
    // 8004AAE0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AAE4:
    ctx->pc = 0x8004AAE4u;
    // 8004AAE4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AAE8:
    ctx->pc = 0x8004AAE8u;
    // 8004AAE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AAEC:
    ctx->pc = 0x8004AAECu;
    ctx->downcount -= 8;
    // 8004AAEC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AAF0:
    ctx->pc = 0x8004AAF0u;
    // 8004AAF0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AAF4:
    ctx->pc = 0x8004AAF4u;
    // 8004AAF4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AAF8:
    ctx->pc = 0x8004AAF8u;
    // 8004AAF8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AAFC:
    ctx->pc = 0x8004AAFCu;
    // 8004AAFC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AB00:
    ctx->pc = 0x8004AB00u;
    // 8004AB00: addi    r9, r9, 18752
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18752);

label_8004AB04:
    ctx->pc = 0x8004AB04u;
    // 8004AB04: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AB08:
    ctx->pc = 0x8004AB08u;
    // 8004AB08: bl      0x8004BE94
    {
            ctx->lr = 0x8004AB0Cu;
            ctx->pc = 0x8004BE94u;
            return;
    }

label_8004AB0C:
    ctx->pc = 0x8004AB0Cu;
    ctx->downcount -= 5;
    // 8004AB0C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AB10:
    ctx->pc = 0x8004AB10u;
    // 8004AB10: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AB14:
    ctx->pc = 0x8004AB14u;
    // 8004AB14: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AB18:
    ctx->pc = 0x8004AB18u;
    // 8004AB18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AB1C:
    ctx->pc = 0x8004AB1Cu;
    ctx->downcount -= 8;
    // 8004AB1C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AB20:
    ctx->pc = 0x8004AB20u;
    // 8004AB20: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AB24:
    ctx->pc = 0x8004AB24u;
    // 8004AB24: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AB28:
    ctx->pc = 0x8004AB28u;
    // 8004AB28: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AB2C:
    ctx->pc = 0x8004AB2Cu;
    // 8004AB2C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AB30:
    ctx->pc = 0x8004AB30u;
    // 8004AB30: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AB34:
    ctx->pc = 0x8004AB34u;
    // 8004AB34: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AB38:
    ctx->pc = 0x8004AB38u;
    // 8004AB38: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AB3Cu;
            goto label_8004B1A0;
    }

label_8004AB3C:
    ctx->pc = 0x8004AB3Cu;
    ctx->downcount -= 5;
    // 8004AB3C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AB40:
    ctx->pc = 0x8004AB40u;
    // 8004AB40: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AB44:
    ctx->pc = 0x8004AB44u;
    // 8004AB44: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AB48:
    ctx->pc = 0x8004AB48u;
    // 8004AB48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AB4C:
    ctx->pc = 0x8004AB4Cu;
    ctx->downcount -= 8;
    // 8004AB4C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AB50:
    ctx->pc = 0x8004AB50u;
    // 8004AB50: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AB54:
    ctx->pc = 0x8004AB54u;
    // 8004AB54: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AB58:
    ctx->pc = 0x8004AB58u;
    // 8004AB58: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AB5C:
    ctx->pc = 0x8004AB5Cu;
    // 8004AB5C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AB60:
    ctx->pc = 0x8004AB60u;
    // 8004AB60: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AB64:
    ctx->pc = 0x8004AB64u;
    // 8004AB64: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AB68:
    ctx->pc = 0x8004AB68u;
    // 8004AB68: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AB6Cu;
            goto label_8004B1A0;
    }

label_8004AB6C:
    ctx->pc = 0x8004AB6Cu;
    ctx->downcount -= 5;
    // 8004AB6C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AB70:
    ctx->pc = 0x8004AB70u;
    // 8004AB70: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AB74:
    ctx->pc = 0x8004AB74u;
    // 8004AB74: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AB78:
    ctx->pc = 0x8004AB78u;
    // 8004AB78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AB7C:
    ctx->pc = 0x8004AB7Cu;
    ctx->downcount -= 8;
    // 8004AB7C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AB80:
    ctx->pc = 0x8004AB80u;
    // 8004AB80: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AB84:
    ctx->pc = 0x8004AB84u;
    // 8004AB84: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AB88:
    ctx->pc = 0x8004AB88u;
    // 8004AB88: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AB8C:
    ctx->pc = 0x8004AB8Cu;
    // 8004AB8C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AB90:
    ctx->pc = 0x8004AB90u;
    // 8004AB90: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AB94:
    ctx->pc = 0x8004AB94u;
    // 8004AB94: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AB98:
    ctx->pc = 0x8004AB98u;
    // 8004AB98: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AB9Cu;
            goto label_8004B1A0;
    }

label_8004AB9C:
    ctx->pc = 0x8004AB9Cu;
    ctx->downcount -= 5;
    // 8004AB9C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004ABA0:
    ctx->pc = 0x8004ABA0u;
    // 8004ABA0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004ABA4:
    ctx->pc = 0x8004ABA4u;
    // 8004ABA4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004ABA8:
    ctx->pc = 0x8004ABA8u;
    // 8004ABA8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004ABAC:
    ctx->pc = 0x8004ABACu;
    ctx->downcount -= 8;
    // 8004ABAC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004ABB0:
    ctx->pc = 0x8004ABB0u;
    // 8004ABB0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004ABB4:
    ctx->pc = 0x8004ABB4u;
    // 8004ABB4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004ABB8:
    ctx->pc = 0x8004ABB8u;
    // 8004ABB8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004ABBC:
    ctx->pc = 0x8004ABBCu;
    // 8004ABBC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004ABC0:
    ctx->pc = 0x8004ABC0u;
    // 8004ABC0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004ABC4:
    ctx->pc = 0x8004ABC4u;
    // 8004ABC4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004ABC8:
    ctx->pc = 0x8004ABC8u;
    // 8004ABC8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004ABCCu;
            goto label_8004B1A0;
    }

label_8004ABCC:
    ctx->pc = 0x8004ABCCu;
    ctx->downcount -= 5;
    // 8004ABCC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004ABD0:
    ctx->pc = 0x8004ABD0u;
    // 8004ABD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004ABD4:
    ctx->pc = 0x8004ABD4u;
    // 8004ABD4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004ABD8:
    ctx->pc = 0x8004ABD8u;
    // 8004ABD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004ABDC:
    ctx->pc = 0x8004ABDCu;
    ctx->downcount -= 8;
    // 8004ABDC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004ABE0:
    ctx->pc = 0x8004ABE0u;
    // 8004ABE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004ABE4:
    ctx->pc = 0x8004ABE4u;
    // 8004ABE4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004ABE8:
    ctx->pc = 0x8004ABE8u;
    // 8004ABE8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004ABEC:
    ctx->pc = 0x8004ABECu;
    // 8004ABEC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004ABF0:
    ctx->pc = 0x8004ABF0u;
    // 8004ABF0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004ABF4:
    ctx->pc = 0x8004ABF4u;
    // 8004ABF4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004ABF8:
    ctx->pc = 0x8004ABF8u;
    // 8004ABF8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004ABFCu;
            goto label_8004B1A0;
    }

label_8004ABFC:
    ctx->pc = 0x8004ABFCu;
    ctx->downcount -= 5;
    // 8004ABFC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AC00:
    ctx->pc = 0x8004AC00u;
    // 8004AC00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AC04:
    ctx->pc = 0x8004AC04u;
    // 8004AC04: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AC08:
    ctx->pc = 0x8004AC08u;
    // 8004AC08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AC0C:
    ctx->pc = 0x8004AC0Cu;
    ctx->downcount -= 8;
    // 8004AC0C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AC10:
    ctx->pc = 0x8004AC10u;
    // 8004AC10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AC14:
    ctx->pc = 0x8004AC14u;
    // 8004AC14: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AC18:
    ctx->pc = 0x8004AC18u;
    // 8004AC18: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AC1C:
    ctx->pc = 0x8004AC1Cu;
    // 8004AC1C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AC20:
    ctx->pc = 0x8004AC20u;
    // 8004AC20: addi    r9, r9, 18344
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18344);

label_8004AC24:
    ctx->pc = 0x8004AC24u;
    // 8004AC24: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AC28:
    ctx->pc = 0x8004AC28u;
    // 8004AC28: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AC2Cu;
            goto label_8004B1A0;
    }

label_8004AC2C:
    ctx->pc = 0x8004AC2Cu;
    ctx->downcount -= 5;
    // 8004AC2C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AC30:
    ctx->pc = 0x8004AC30u;
    // 8004AC30: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AC34:
    ctx->pc = 0x8004AC34u;
    // 8004AC34: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AC38:
    ctx->pc = 0x8004AC38u;
    // 8004AC38: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AC3C:
    ctx->pc = 0x8004AC3Cu;
    ctx->downcount -= 8;
    // 8004AC3C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AC40:
    ctx->pc = 0x8004AC40u;
    // 8004AC40: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AC44:
    ctx->pc = 0x8004AC44u;
    // 8004AC44: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AC48:
    ctx->pc = 0x8004AC48u;
    // 8004AC48: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AC4C:
    ctx->pc = 0x8004AC4Cu;
    // 8004AC4C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AC50:
    ctx->pc = 0x8004AC50u;
    // 8004AC50: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AC54:
    ctx->pc = 0x8004AC54u;
    // 8004AC54: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AC58:
    ctx->pc = 0x8004AC58u;
    // 8004AC58: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AC5Cu;
            goto label_8004B1A0;
    }

label_8004AC5C:
    ctx->pc = 0x8004AC5Cu;
    ctx->downcount -= 5;
    // 8004AC5C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AC60:
    ctx->pc = 0x8004AC60u;
    // 8004AC60: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AC64:
    ctx->pc = 0x8004AC64u;
    // 8004AC64: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AC68:
    ctx->pc = 0x8004AC68u;
    // 8004AC68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AC6C:
    ctx->pc = 0x8004AC6Cu;
    ctx->downcount -= 8;
    // 8004AC6C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AC70:
    ctx->pc = 0x8004AC70u;
    // 8004AC70: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AC74:
    ctx->pc = 0x8004AC74u;
    // 8004AC74: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AC78:
    ctx->pc = 0x8004AC78u;
    // 8004AC78: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AC7C:
    ctx->pc = 0x8004AC7Cu;
    // 8004AC7C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AC80:
    ctx->pc = 0x8004AC80u;
    // 8004AC80: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AC84:
    ctx->pc = 0x8004AC84u;
    // 8004AC84: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AC88:
    ctx->pc = 0x8004AC88u;
    // 8004AC88: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AC8Cu;
            goto label_8004B1A0;
    }

label_8004AC8C:
    ctx->pc = 0x8004AC8Cu;
    ctx->downcount -= 5;
    // 8004AC8C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AC90:
    ctx->pc = 0x8004AC90u;
    // 8004AC90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AC94:
    ctx->pc = 0x8004AC94u;
    // 8004AC94: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AC98:
    ctx->pc = 0x8004AC98u;
    // 8004AC98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AC9C:
    ctx->pc = 0x8004AC9Cu;
    ctx->downcount -= 8;
    // 8004AC9C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004ACA0:
    ctx->pc = 0x8004ACA0u;
    // 8004ACA0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004ACA4:
    ctx->pc = 0x8004ACA4u;
    // 8004ACA4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004ACA8:
    ctx->pc = 0x8004ACA8u;
    // 8004ACA8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004ACAC:
    ctx->pc = 0x8004ACACu;
    // 8004ACAC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004ACB0:
    ctx->pc = 0x8004ACB0u;
    // 8004ACB0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004ACB4:
    ctx->pc = 0x8004ACB4u;
    // 8004ACB4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004ACB8:
    ctx->pc = 0x8004ACB8u;
    // 8004ACB8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004ACBCu;
            goto label_8004B1A0;
    }

label_8004ACBC:
    ctx->pc = 0x8004ACBCu;
    ctx->downcount -= 5;
    // 8004ACBC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004ACC0:
    ctx->pc = 0x8004ACC0u;
    // 8004ACC0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004ACC4:
    ctx->pc = 0x8004ACC4u;
    // 8004ACC4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004ACC8:
    ctx->pc = 0x8004ACC8u;
    // 8004ACC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004ACCC:
    ctx->pc = 0x8004ACCCu;
    ctx->downcount -= 8;
    // 8004ACCC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004ACD0:
    ctx->pc = 0x8004ACD0u;
    // 8004ACD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004ACD4:
    ctx->pc = 0x8004ACD4u;
    // 8004ACD4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004ACD8:
    ctx->pc = 0x8004ACD8u;
    // 8004ACD8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004ACDC:
    ctx->pc = 0x8004ACDCu;
    // 8004ACDC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004ACE0:
    ctx->pc = 0x8004ACE0u;
    // 8004ACE0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004ACE4:
    ctx->pc = 0x8004ACE4u;
    // 8004ACE4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004ACE8:
    ctx->pc = 0x8004ACE8u;
    // 8004ACE8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004ACECu;
            goto label_8004B1A0;
    }

label_8004ACEC:
    ctx->pc = 0x8004ACECu;
    ctx->downcount -= 5;
    // 8004ACEC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004ACF0:
    ctx->pc = 0x8004ACF0u;
    // 8004ACF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004ACF4:
    ctx->pc = 0x8004ACF4u;
    // 8004ACF4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004ACF8:
    ctx->pc = 0x8004ACF8u;
    // 8004ACF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004ACFC:
    ctx->pc = 0x8004ACFCu;
    ctx->downcount -= 8;
    // 8004ACFC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AD00:
    ctx->pc = 0x8004AD00u;
    // 8004AD00: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AD04:
    ctx->pc = 0x8004AD04u;
    // 8004AD04: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AD08:
    ctx->pc = 0x8004AD08u;
    // 8004AD08: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AD0C:
    ctx->pc = 0x8004AD0Cu;
    // 8004AD0C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AD10:
    ctx->pc = 0x8004AD10u;
    // 8004AD10: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AD14:
    ctx->pc = 0x8004AD14u;
    // 8004AD14: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AD18:
    ctx->pc = 0x8004AD18u;
    // 8004AD18: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AD1Cu;
            goto label_8004B1A0;
    }

label_8004AD1C:
    ctx->pc = 0x8004AD1Cu;
    ctx->downcount -= 5;
    // 8004AD1C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AD20:
    ctx->pc = 0x8004AD20u;
    // 8004AD20: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AD24:
    ctx->pc = 0x8004AD24u;
    // 8004AD24: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AD28:
    ctx->pc = 0x8004AD28u;
    // 8004AD28: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AD2C:
    ctx->pc = 0x8004AD2Cu;
    ctx->downcount -= 8;
    // 8004AD2C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AD30:
    ctx->pc = 0x8004AD30u;
    // 8004AD30: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AD34:
    ctx->pc = 0x8004AD34u;
    // 8004AD34: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AD38:
    ctx->pc = 0x8004AD38u;
    // 8004AD38: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AD3C:
    ctx->pc = 0x8004AD3Cu;
    // 8004AD3C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AD40:
    ctx->pc = 0x8004AD40u;
    // 8004AD40: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AD44:
    ctx->pc = 0x8004AD44u;
    // 8004AD44: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AD48:
    ctx->pc = 0x8004AD48u;
    // 8004AD48: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AD4Cu;
            goto label_8004B1A0;
    }

label_8004AD4C:
    ctx->pc = 0x8004AD4Cu;
    ctx->downcount -= 5;
    // 8004AD4C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AD50:
    ctx->pc = 0x8004AD50u;
    // 8004AD50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AD54:
    ctx->pc = 0x8004AD54u;
    // 8004AD54: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AD58:
    ctx->pc = 0x8004AD58u;
    // 8004AD58: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AD5C:
    ctx->pc = 0x8004AD5Cu;
    ctx->downcount -= 8;
    // 8004AD5C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AD60:
    ctx->pc = 0x8004AD60u;
    // 8004AD60: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AD64:
    ctx->pc = 0x8004AD64u;
    // 8004AD64: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AD68:
    ctx->pc = 0x8004AD68u;
    // 8004AD68: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AD6C:
    ctx->pc = 0x8004AD6Cu;
    // 8004AD6C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AD70:
    ctx->pc = 0x8004AD70u;
    // 8004AD70: addi    r9, r9, 9728
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(9728);

label_8004AD74:
    ctx->pc = 0x8004AD74u;
    // 8004AD74: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AD78:
    ctx->pc = 0x8004AD78u;
    // 8004AD78: bl      0x8004BE94
    {
            ctx->lr = 0x8004AD7Cu;
            ctx->pc = 0x8004BE94u;
            return;
    }

label_8004AD7C:
    ctx->pc = 0x8004AD7Cu;
    ctx->downcount -= 5;
    // 8004AD7C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AD80:
    ctx->pc = 0x8004AD80u;
    // 8004AD80: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AD84:
    ctx->pc = 0x8004AD84u;
    // 8004AD84: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AD88:
    ctx->pc = 0x8004AD88u;
    // 8004AD88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AD8C:
    ctx->pc = 0x8004AD8Cu;
    ctx->downcount -= 8;
    // 8004AD8C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AD90:
    ctx->pc = 0x8004AD90u;
    // 8004AD90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AD94:
    ctx->pc = 0x8004AD94u;
    // 8004AD94: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AD98:
    ctx->pc = 0x8004AD98u;
    // 8004AD98: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AD9C:
    ctx->pc = 0x8004AD9Cu;
    // 8004AD9C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004ADA0:
    ctx->pc = 0x8004ADA0u;
    // 8004ADA0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004ADA4:
    ctx->pc = 0x8004ADA4u;
    // 8004ADA4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004ADA8:
    ctx->pc = 0x8004ADA8u;
    // 8004ADA8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004ADACu;
            goto label_8004B1A0;
    }

label_8004ADAC:
    ctx->pc = 0x8004ADACu;
    ctx->downcount -= 5;
    // 8004ADAC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004ADB0:
    ctx->pc = 0x8004ADB0u;
    // 8004ADB0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004ADB4:
    ctx->pc = 0x8004ADB4u;
    // 8004ADB4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004ADB8:
    ctx->pc = 0x8004ADB8u;
    // 8004ADB8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004ADBC:
    ctx->pc = 0x8004ADBCu;
    ctx->downcount -= 8;
    // 8004ADBC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004ADC0:
    ctx->pc = 0x8004ADC0u;
    // 8004ADC0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004ADC4:
    ctx->pc = 0x8004ADC4u;
    // 8004ADC4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004ADC8:
    ctx->pc = 0x8004ADC8u;
    // 8004ADC8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004ADCC:
    ctx->pc = 0x8004ADCCu;
    // 8004ADCC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004ADD0:
    ctx->pc = 0x8004ADD0u;
    // 8004ADD0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004ADD4:
    ctx->pc = 0x8004ADD4u;
    // 8004ADD4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004ADD8:
    ctx->pc = 0x8004ADD8u;
    // 8004ADD8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004ADDCu;
            goto label_8004B1A0;
    }

label_8004ADDC:
    ctx->pc = 0x8004ADDCu;
    ctx->downcount -= 5;
    // 8004ADDC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004ADE0:
    ctx->pc = 0x8004ADE0u;
    // 8004ADE0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004ADE4:
    ctx->pc = 0x8004ADE4u;
    // 8004ADE4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004ADE8:
    ctx->pc = 0x8004ADE8u;
    // 8004ADE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004ADEC:
    ctx->pc = 0x8004ADECu;
    ctx->downcount -= 8;
    // 8004ADEC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004ADF0:
    ctx->pc = 0x8004ADF0u;
    // 8004ADF0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004ADF4:
    ctx->pc = 0x8004ADF4u;
    // 8004ADF4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004ADF8:
    ctx->pc = 0x8004ADF8u;
    // 8004ADF8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004ADFC:
    ctx->pc = 0x8004ADFCu;
    // 8004ADFC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AE00:
    ctx->pc = 0x8004AE00u;
    // 8004AE00: addi    r9, r9, 18344
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18344);

label_8004AE04:
    ctx->pc = 0x8004AE04u;
    // 8004AE04: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AE08:
    ctx->pc = 0x8004AE08u;
    // 8004AE08: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AE0Cu;
            goto label_8004B1A0;
    }

label_8004AE0C:
    ctx->pc = 0x8004AE0Cu;
    ctx->downcount -= 5;
    // 8004AE0C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AE10:
    ctx->pc = 0x8004AE10u;
    // 8004AE10: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AE14:
    ctx->pc = 0x8004AE14u;
    // 8004AE14: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AE18:
    ctx->pc = 0x8004AE18u;
    // 8004AE18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AE1C:
    ctx->pc = 0x8004AE1Cu;
    ctx->downcount -= 8;
    // 8004AE1C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AE20:
    ctx->pc = 0x8004AE20u;
    // 8004AE20: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AE24:
    ctx->pc = 0x8004AE24u;
    // 8004AE24: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AE28:
    ctx->pc = 0x8004AE28u;
    // 8004AE28: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AE2C:
    ctx->pc = 0x8004AE2Cu;
    // 8004AE2C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AE30:
    ctx->pc = 0x8004AE30u;
    // 8004AE30: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AE34:
    ctx->pc = 0x8004AE34u;
    // 8004AE34: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AE38:
    ctx->pc = 0x8004AE38u;
    // 8004AE38: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AE3Cu;
            goto label_8004B1A0;
    }

label_8004AE3C:
    ctx->pc = 0x8004AE3Cu;
    ctx->downcount -= 5;
    // 8004AE3C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AE40:
    ctx->pc = 0x8004AE40u;
    // 8004AE40: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AE44:
    ctx->pc = 0x8004AE44u;
    // 8004AE44: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AE48:
    ctx->pc = 0x8004AE48u;
    // 8004AE48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AE4C:
    ctx->pc = 0x8004AE4Cu;
    ctx->downcount -= 8;
    // 8004AE4C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AE50:
    ctx->pc = 0x8004AE50u;
    // 8004AE50: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AE54:
    ctx->pc = 0x8004AE54u;
    // 8004AE54: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AE58:
    ctx->pc = 0x8004AE58u;
    // 8004AE58: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AE5C:
    ctx->pc = 0x8004AE5Cu;
    // 8004AE5C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AE60:
    ctx->pc = 0x8004AE60u;
    // 8004AE60: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AE64:
    ctx->pc = 0x8004AE64u;
    // 8004AE64: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AE68:
    ctx->pc = 0x8004AE68u;
    // 8004AE68: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AE6Cu;
            goto label_8004B1A0;
    }

label_8004AE6C:
    ctx->pc = 0x8004AE6Cu;
    ctx->downcount -= 5;
    // 8004AE6C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AE70:
    ctx->pc = 0x8004AE70u;
    // 8004AE70: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AE74:
    ctx->pc = 0x8004AE74u;
    // 8004AE74: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AE78:
    ctx->pc = 0x8004AE78u;
    // 8004AE78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AE7C:
    ctx->pc = 0x8004AE7Cu;
    ctx->downcount -= 8;
    // 8004AE7C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AE80:
    ctx->pc = 0x8004AE80u;
    // 8004AE80: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AE84:
    ctx->pc = 0x8004AE84u;
    // 8004AE84: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AE88:
    ctx->pc = 0x8004AE88u;
    // 8004AE88: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AE8C:
    ctx->pc = 0x8004AE8Cu;
    // 8004AE8C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AE90:
    ctx->pc = 0x8004AE90u;
    // 8004AE90: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AE94:
    ctx->pc = 0x8004AE94u;
    // 8004AE94: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AE98:
    ctx->pc = 0x8004AE98u;
    // 8004AE98: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AE9Cu;
            goto label_8004B1A0;
    }

label_8004AE9C:
    ctx->pc = 0x8004AE9Cu;
    ctx->downcount -= 5;
    // 8004AE9C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AEA0:
    ctx->pc = 0x8004AEA0u;
    // 8004AEA0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AEA4:
    ctx->pc = 0x8004AEA4u;
    // 8004AEA4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AEA8:
    ctx->pc = 0x8004AEA8u;
    // 8004AEA8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AEAC:
    ctx->pc = 0x8004AEACu;
    ctx->downcount -= 8;
    // 8004AEAC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AEB0:
    ctx->pc = 0x8004AEB0u;
    // 8004AEB0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AEB4:
    ctx->pc = 0x8004AEB4u;
    // 8004AEB4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AEB8:
    ctx->pc = 0x8004AEB8u;
    // 8004AEB8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AEBC:
    ctx->pc = 0x8004AEBCu;
    // 8004AEBC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AEC0:
    ctx->pc = 0x8004AEC0u;
    // 8004AEC0: addi    r9, r9, 18344
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(18344);

label_8004AEC4:
    ctx->pc = 0x8004AEC4u;
    // 8004AEC4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AEC8:
    ctx->pc = 0x8004AEC8u;
    // 8004AEC8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AECCu;
            goto label_8004B1A0;
    }

label_8004AECC:
    ctx->pc = 0x8004AECCu;
    ctx->downcount -= 5;
    // 8004AECC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AED0:
    ctx->pc = 0x8004AED0u;
    // 8004AED0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AED4:
    ctx->pc = 0x8004AED4u;
    // 8004AED4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AED8:
    ctx->pc = 0x8004AED8u;
    // 8004AED8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AEDC:
    ctx->pc = 0x8004AEDCu;
    ctx->downcount -= 8;
    // 8004AEDC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AEE0:
    ctx->pc = 0x8004AEE0u;
    // 8004AEE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AEE4:
    ctx->pc = 0x8004AEE4u;
    // 8004AEE4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AEE8:
    ctx->pc = 0x8004AEE8u;
    // 8004AEE8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AEEC:
    ctx->pc = 0x8004AEECu;
    // 8004AEEC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AEF0:
    ctx->pc = 0x8004AEF0u;
    // 8004AEF0: addi    r9, r9, 9184
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(9184);

label_8004AEF4:
    ctx->pc = 0x8004AEF4u;
    // 8004AEF4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AEF8:
    ctx->pc = 0x8004AEF8u;
    // 8004AEF8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AEFCu;
            goto label_8004B1A0;
    }

label_8004AEFC:
    ctx->pc = 0x8004AEFCu;
    ctx->downcount -= 5;
    // 8004AEFC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AF00:
    ctx->pc = 0x8004AF00u;
    // 8004AF00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AF04:
    ctx->pc = 0x8004AF04u;
    // 8004AF04: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AF08:
    ctx->pc = 0x8004AF08u;
    // 8004AF08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AF0C:
    ctx->pc = 0x8004AF0Cu;
    ctx->downcount -= 8;
    // 8004AF0C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AF10:
    ctx->pc = 0x8004AF10u;
    // 8004AF10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AF14:
    ctx->pc = 0x8004AF14u;
    // 8004AF14: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AF18:
    ctx->pc = 0x8004AF18u;
    // 8004AF18: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AF1C:
    ctx->pc = 0x8004AF1Cu;
    // 8004AF1C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AF20:
    ctx->pc = 0x8004AF20u;
    // 8004AF20: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AF24:
    ctx->pc = 0x8004AF24u;
    // 8004AF24: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AF28:
    ctx->pc = 0x8004AF28u;
    // 8004AF28: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AF2Cu;
            goto label_8004B1A0;
    }

label_8004AF2C:
    ctx->pc = 0x8004AF2Cu;
    ctx->downcount -= 5;
    // 8004AF2C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AF30:
    ctx->pc = 0x8004AF30u;
    // 8004AF30: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AF34:
    ctx->pc = 0x8004AF34u;
    // 8004AF34: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AF38:
    ctx->pc = 0x8004AF38u;
    // 8004AF38: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AF3C:
    ctx->pc = 0x8004AF3Cu;
    ctx->downcount -= 8;
    // 8004AF3C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AF40:
    ctx->pc = 0x8004AF40u;
    // 8004AF40: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AF44:
    ctx->pc = 0x8004AF44u;
    // 8004AF44: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AF48:
    ctx->pc = 0x8004AF48u;
    // 8004AF48: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AF4C:
    ctx->pc = 0x8004AF4Cu;
    // 8004AF4C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AF50:
    ctx->pc = 0x8004AF50u;
    // 8004AF50: addi    r9, r9, 12440
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(12440);

label_8004AF54:
    ctx->pc = 0x8004AF54u;
    // 8004AF54: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AF58:
    ctx->pc = 0x8004AF58u;
    // 8004AF58: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AF5Cu;
            goto label_8004B1A0;
    }

label_8004AF5C:
    ctx->pc = 0x8004AF5Cu;
    ctx->downcount -= 5;
    // 8004AF5C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AF60:
    ctx->pc = 0x8004AF60u;
    // 8004AF60: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AF64:
    ctx->pc = 0x8004AF64u;
    // 8004AF64: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AF68:
    ctx->pc = 0x8004AF68u;
    // 8004AF68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AF6C:
    ctx->pc = 0x8004AF6Cu;
    ctx->downcount -= 8;
    // 8004AF6C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AF70:
    ctx->pc = 0x8004AF70u;
    // 8004AF70: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AF74:
    ctx->pc = 0x8004AF74u;
    // 8004AF74: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AF78:
    ctx->pc = 0x8004AF78u;
    // 8004AF78: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AF7C:
    ctx->pc = 0x8004AF7Cu;
    // 8004AF7C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AF80:
    ctx->pc = 0x8004AF80u;
    // 8004AF80: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AF84:
    ctx->pc = 0x8004AF84u;
    // 8004AF84: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AF88:
    ctx->pc = 0x8004AF88u;
    // 8004AF88: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AF8Cu;
            goto label_8004B1A0;
    }

label_8004AF8C:
    ctx->pc = 0x8004AF8Cu;
    ctx->downcount -= 5;
    // 8004AF8C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AF90:
    ctx->pc = 0x8004AF90u;
    // 8004AF90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AF94:
    ctx->pc = 0x8004AF94u;
    // 8004AF94: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AF98:
    ctx->pc = 0x8004AF98u;
    // 8004AF98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AF9C:
    ctx->pc = 0x8004AF9Cu;
    ctx->downcount -= 8;
    // 8004AF9C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AFA0:
    ctx->pc = 0x8004AFA0u;
    // 8004AFA0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AFA4:
    ctx->pc = 0x8004AFA4u;
    // 8004AFA4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AFA8:
    ctx->pc = 0x8004AFA8u;
    // 8004AFA8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AFAC:
    ctx->pc = 0x8004AFACu;
    // 8004AFAC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AFB0:
    ctx->pc = 0x8004AFB0u;
    // 8004AFB0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AFB4:
    ctx->pc = 0x8004AFB4u;
    // 8004AFB4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AFB8:
    ctx->pc = 0x8004AFB8u;
    // 8004AFB8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AFBCu;
            goto label_8004B1A0;
    }

label_8004AFBC:
    ctx->pc = 0x8004AFBCu;
    ctx->downcount -= 5;
    // 8004AFBC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AFC0:
    ctx->pc = 0x8004AFC0u;
    // 8004AFC0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AFC4:
    ctx->pc = 0x8004AFC4u;
    // 8004AFC4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AFC8:
    ctx->pc = 0x8004AFC8u;
    // 8004AFC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AFCC:
    ctx->pc = 0x8004AFCCu;
    ctx->downcount -= 8;
    // 8004AFCC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AFD0:
    ctx->pc = 0x8004AFD0u;
    // 8004AFD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AFD4:
    ctx->pc = 0x8004AFD4u;
    // 8004AFD4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AFD8:
    ctx->pc = 0x8004AFD8u;
    // 8004AFD8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004AFDC:
    ctx->pc = 0x8004AFDCu;
    // 8004AFDC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AFE0:
    ctx->pc = 0x8004AFE0u;
    // 8004AFE0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004AFE4:
    ctx->pc = 0x8004AFE4u;
    // 8004AFE4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AFE8:
    ctx->pc = 0x8004AFE8u;
    // 8004AFE8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004AFECu;
            goto label_8004B1A0;
    }

label_8004AFEC:
    ctx->pc = 0x8004AFECu;
    ctx->downcount -= 5;
    // 8004AFEC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AFF0:
    ctx->pc = 0x8004AFF0u;
    // 8004AFF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AFF4:
    ctx->pc = 0x8004AFF4u;
    // 8004AFF4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004AFF8:
    ctx->pc = 0x8004AFF8u;
    // 8004AFF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004AFFC:
    ctx->pc = 0x8004AFFCu;
    ctx->downcount -= 8;
    // 8004AFFC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B000:
    ctx->pc = 0x8004B000u;
    // 8004B000: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B004:
    ctx->pc = 0x8004B004u;
    // 8004B004: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B008:
    ctx->pc = 0x8004B008u;
    // 8004B008: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B00C:
    ctx->pc = 0x8004B00Cu;
    // 8004B00C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B010:
    ctx->pc = 0x8004B010u;
    // 8004B010: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004B014:
    ctx->pc = 0x8004B014u;
    // 8004B014: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004B018:
    ctx->pc = 0x8004B018u;
    // 8004B018: bl      0x8004B1A0
    {
            ctx->lr = 0x8004B01Cu;
            goto label_8004B1A0;
    }

label_8004B01C:
    ctx->pc = 0x8004B01Cu;
    ctx->downcount -= 5;
    // 8004B01C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B020:
    ctx->pc = 0x8004B020u;
    // 8004B020: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B024:
    ctx->pc = 0x8004B024u;
    // 8004B024: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004B028:
    ctx->pc = 0x8004B028u;
    // 8004B028: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B02C:
    ctx->pc = 0x8004B02Cu;
    ctx->downcount -= 8;
    // 8004B02C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B030:
    ctx->pc = 0x8004B030u;
    // 8004B030: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B034:
    ctx->pc = 0x8004B034u;
    // 8004B034: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B038:
    ctx->pc = 0x8004B038u;
    // 8004B038: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B03C:
    ctx->pc = 0x8004B03Cu;
    // 8004B03C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B040:
    ctx->pc = 0x8004B040u;
    // 8004B040: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004B044:
    ctx->pc = 0x8004B044u;
    // 8004B044: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004B048:
    ctx->pc = 0x8004B048u;
    // 8004B048: bl      0x8004B1A0
    {
            ctx->lr = 0x8004B04Cu;
            goto label_8004B1A0;
    }

label_8004B04C:
    ctx->pc = 0x8004B04Cu;
    ctx->downcount -= 5;
    // 8004B04C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B050:
    ctx->pc = 0x8004B050u;
    // 8004B050: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B054:
    ctx->pc = 0x8004B054u;
    // 8004B054: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004B058:
    ctx->pc = 0x8004B058u;
    // 8004B058: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B05C:
    ctx->pc = 0x8004B05Cu;
    ctx->downcount -= 8;
    // 8004B05C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B060:
    ctx->pc = 0x8004B060u;
    // 8004B060: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B064:
    ctx->pc = 0x8004B064u;
    // 8004B064: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B068:
    ctx->pc = 0x8004B068u;
    // 8004B068: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B06C:
    ctx->pc = 0x8004B06Cu;
    // 8004B06C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B070:
    ctx->pc = 0x8004B070u;
    // 8004B070: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004B074:
    ctx->pc = 0x8004B074u;
    // 8004B074: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004B078:
    ctx->pc = 0x8004B078u;
    // 8004B078: bl      0x8004B1A0
    {
            ctx->lr = 0x8004B07Cu;
            goto label_8004B1A0;
    }

label_8004B07C:
    ctx->pc = 0x8004B07Cu;
    ctx->downcount -= 5;
    // 8004B07C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B080:
    ctx->pc = 0x8004B080u;
    // 8004B080: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B084:
    ctx->pc = 0x8004B084u;
    // 8004B084: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004B088:
    ctx->pc = 0x8004B088u;
    // 8004B088: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B08C:
    ctx->pc = 0x8004B08Cu;
    ctx->downcount -= 8;
    // 8004B08C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B090:
    ctx->pc = 0x8004B090u;
    // 8004B090: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B094:
    ctx->pc = 0x8004B094u;
    // 8004B094: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B098:
    ctx->pc = 0x8004B098u;
    // 8004B098: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B09C:
    ctx->pc = 0x8004B09Cu;
    // 8004B09C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B0A0:
    ctx->pc = 0x8004B0A0u;
    // 8004B0A0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004B0A4:
    ctx->pc = 0x8004B0A4u;
    // 8004B0A4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004B0A8:
    ctx->pc = 0x8004B0A8u;
    // 8004B0A8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004B0ACu;
            goto label_8004B1A0;
    }

label_8004B0AC:
    ctx->pc = 0x8004B0ACu;
    ctx->downcount -= 5;
    // 8004B0AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B0B0:
    ctx->pc = 0x8004B0B0u;
    // 8004B0B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B0B4:
    ctx->pc = 0x8004B0B4u;
    // 8004B0B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004B0B8:
    ctx->pc = 0x8004B0B8u;
    // 8004B0B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B0BC:
    ctx->pc = 0x8004B0BCu;
    ctx->downcount -= 8;
    // 8004B0BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B0C0:
    ctx->pc = 0x8004B0C0u;
    // 8004B0C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B0C4:
    ctx->pc = 0x8004B0C4u;
    // 8004B0C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B0C8:
    ctx->pc = 0x8004B0C8u;
    // 8004B0C8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B0CC:
    ctx->pc = 0x8004B0CCu;
    // 8004B0CC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B0D0:
    ctx->pc = 0x8004B0D0u;
    // 8004B0D0: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004B0D4:
    ctx->pc = 0x8004B0D4u;
    // 8004B0D4: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004B0D8:
    ctx->pc = 0x8004B0D8u;
    // 8004B0D8: bl      0x8004B1A0
    {
            ctx->lr = 0x8004B0DCu;
            goto label_8004B1A0;
    }

label_8004B0DC:
    ctx->pc = 0x8004B0DCu;
    ctx->downcount -= 5;
    // 8004B0DC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B0E0:
    ctx->pc = 0x8004B0E0u;
    // 8004B0E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B0E4:
    ctx->pc = 0x8004B0E4u;
    // 8004B0E4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004B0E8:
    ctx->pc = 0x8004B0E8u;
    // 8004B0E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B0EC:
    ctx->pc = 0x8004B0ECu;
    ctx->downcount -= 8;
    // 8004B0EC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B0F0:
    ctx->pc = 0x8004B0F0u;
    // 8004B0F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B0F4:
    ctx->pc = 0x8004B0F4u;
    // 8004B0F4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B0F8:
    ctx->pc = 0x8004B0F8u;
    // 8004B0F8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B0FC:
    ctx->pc = 0x8004B0FCu;
    // 8004B0FC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B100:
    ctx->pc = 0x8004B100u;
    // 8004B100: addi    r9, r9, 19800
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(19800);

label_8004B104:
    ctx->pc = 0x8004B104u;
    // 8004B104: stw     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004B108:
    ctx->pc = 0x8004B108u;
    // 8004B108: bl      0x8004B1A0
    {
            ctx->lr = 0x8004B10Cu;
            goto label_8004B1A0;
    }

label_8004B10C:
    ctx->pc = 0x8004B10Cu;
    ctx->downcount -= 5;
    // 8004B10C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B110:
    ctx->pc = 0x8004B110u;
    // 8004B110: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B114:
    ctx->pc = 0x8004B114u;
    // 8004B114: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004B118:
    ctx->pc = 0x8004B118u;
    // 8004B118: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B11C:
    ctx->pc = 0x8004B11Cu;
    ctx->downcount -= 24;
    // 8004B11C: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B120:
    ctx->pc = 0x8004B120u;
    // 8004B120: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B124:
    ctx->pc = 0x8004B124u;
    // 8004B124: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004B124u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8004B128:
    ctx->pc = 0x8004B128u;
    // 8004B128: stmw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8004B12C:
    ctx->pc = 0x8004B12Cu;
    // 8004B12C: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B130:
    ctx->pc = 0x8004B130u;
    // 8004B130: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B134:
    ctx->pc = 0x8004B134u;
    // 8004B134: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B138:
    ctx->pc = 0x8004B138u;
    // 8004B138: addi    r9, r9, 20104
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(20104);

label_8004B13C:
    ctx->pc = 0x8004B13Cu;
    // 8004B13C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004B140:
    ctx->pc = 0x8004B140u;
    // 8004B140: or   r28, r5, r5
    {
        ctx->gpr[28] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004B144:
    ctx->pc = 0x8004B144u;
    // 8004B144: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x8004B144u)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_8004B148:
    ctx->pc = 0x8004B148u;
    // 8004B148: stw     r9, 84(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004B14C:
    ctx->pc = 0x8004B14Cu;
    // 8004B14C: addi    r3, r30, 8
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(8);

label_8004B150:
    ctx->pc = 0x8004B150u;
    // 8004B150: bl      0x800831D8
    {
            ctx->lr = 0x8004B154u;
            ctx->pc = 0x800831D8u;
            return;
    }

label_8004B154:
    ctx->pc = 0x8004B154u;
    ctx->downcount -= 30;
    // 8004B154: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B158:
    ctx->pc = 0x8004B158u;
    // 8004B158: lis     r11, -32722
    ctx->gpr[11] = ((u32)(s32)(-32722) << 16);

label_8004B15C:
    ctx->pc = 0x8004B15Cu;
    // 8004B15C: lfs     f13, 20160(r9)
    if (!ppc_fp_available_inline(ctx, 0x8004B15Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20160);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8004B160:
    ctx->pc = 0x8004B160u;
    // 8004B160: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004B164:
    ctx->pc = 0x8004B164u;
    // 8004B164: lfs     f0, 20164(r11)
    if (!ppc_fp_available_inline(ctx, 0x8004B164u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004B168:
    ctx->pc = 0x8004B168u;
    // 8004B168: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8004B16C:
    ctx->pc = 0x8004B16Cu;
    // 8004B16C: stw     r29, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8004B170:
    ctx->pc = 0x8004B170u;
    // 8004B170: stw     r28, 68(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8004B174:
    ctx->pc = 0x8004B174u;
    // 8004B174: stfs     f31, 72(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B174u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8004B178:
    ctx->pc = 0x8004B178u;
    // 8004B178: stfs     f13, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B178u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8004B17C:
    ctx->pc = 0x8004B17Cu;
    // 8004B17C: stfs     f0, 64(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B17Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004B180:
    ctx->pc = 0x8004B180u;
    // 8004B180: stw     r0, 60(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B184:
    ctx->pc = 0x8004B184u;
    // 8004B184: stw     r0, 56(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B188:
    ctx->pc = 0x8004B188u;
    // 8004B188: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B18C:
    ctx->pc = 0x8004B18Cu;
    // 8004B18C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B190:
    ctx->pc = 0x8004B190u;
    // 8004B190: lmw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004B194:
    ctx->pc = 0x8004B194u;
    // 8004B194: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004B194u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004B198:
    ctx->pc = 0x8004B198u;
    // 8004B198: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8004B19C:
    ctx->pc = 0x8004B19Cu;
    // 8004B19C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B1A0:
    ctx->pc = 0x8004B1A0u;
    ctx->downcount -= 22;
    // 8004B1A0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B1A4:
    ctx->pc = 0x8004B1A4u;
    // 8004B1A4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B1A8:
    ctx->pc = 0x8004B1A8u;
    // 8004B1A8: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8004B1AC:
    ctx->pc = 0x8004B1ACu;
    // 8004B1AC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B1B0:
    ctx->pc = 0x8004B1B0u;
    // 8004B1B0: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B1B4:
    ctx->pc = 0x8004B1B4u;
    // 8004B1B4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B1B8:
    ctx->pc = 0x8004B1B8u;
    // 8004B1B8: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004B1BC:
    ctx->pc = 0x8004B1BCu;
    // 8004B1BC: addi    r9, r9, 20104
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(20104);

label_8004B1C0:
    ctx->pc = 0x8004B1C0u;
    // 8004B1C0: stw     r9, 84(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004B1C4:
    ctx->pc = 0x8004B1C4u;
    // 8004B1C4: addi    r3, r31, 8
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(8);

label_8004B1C8:
    ctx->pc = 0x8004B1C8u;
    // 8004B1C8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8004B1CC:
    ctx->pc = 0x8004B1CCu;
    // 8004B1CC: bl      0x80083280
    {
            ctx->lr = 0x8004B1D0u;
            ctx->pc = 0x80083280u;
            return;
    }

label_8004B1D0:
    ctx->pc = 0x8004B1D0u;
    ctx->downcount -= 2;
    // 8004B1D0: andi.   r0, r30, 0x0001
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

label_8004B1D4:
    ctx->pc = 0x8004B1D4u;
    // 8004B1D4: bc    12, 2, 0x8004B1E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B1E0;
        }
    }

label_8004B1D8:
    ctx->pc = 0x8004B1D8u;
    ctx->downcount -= 2;
    // 8004B1D8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8004B1DC:
    ctx->pc = 0x8004B1DCu;
    // 8004B1DC: bl      0x80281D80
    {
            ctx->lr = 0x8004B1E0u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_8004B1E0:
    ctx->pc = 0x8004B1E0u;
    ctx->downcount -= 16;
    // 8004B1E0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B1E4:
    ctx->pc = 0x8004B1E4u;
    // 8004B1E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B1E8:
    ctx->pc = 0x8004B1E8u;
    // 8004B1E8: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004B1EC:
    ctx->pc = 0x8004B1ECu;
    // 8004B1EC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004B1F0:
    ctx->pc = 0x8004B1F0u;
    // 8004B1F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B1F4:
    ctx->pc = 0x8004B1F4u;
    ctx->downcount -= 17;
    // 8004B1F4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B1F8:
    ctx->pc = 0x8004B1F8u;
    // 8004B1F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B1FC:
    ctx->pc = 0x8004B1FCu;
    // 8004B1FC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8004B200:
    ctx->pc = 0x8004B200u;
    // 8004B200: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B204:
    ctx->pc = 0x8004B204u;
    // 8004B204: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B208:
    ctx->pc = 0x8004B208u;
    // 8004B208: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B20C:
    ctx->pc = 0x8004B20Cu;
    // 8004B20C: bl      0x8004FCDC
    {
            ctx->lr = 0x8004B210u;
            ctx->pc = 0x8004FCDCu;
            return;
    }

label_8004B210:
    ctx->pc = 0x8004B210u;
    ctx->downcount -= 7;
    // 8004B210: lfs     f0, 104(r3)
    if (!ppc_fp_available_inline(ctx, 0x8004B210u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(104);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004B214:
    ctx->pc = 0x8004B214u;
    // 8004B214: lfs     f12, 76(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B214u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(76);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_8004B218:
    ctx->pc = 0x8004B218u;
    // 8004B218: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004B21C:
    ctx->pc = 0x8004B21Cu;
    // 8004B21C: lfs     f13, 80(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B21Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(80);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8004B220:
    ctx->pc = 0x8004B220u;
    // 8004B220: fsubs   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x8004B220u)) return;
    ppc_fsubs(ctx, 0, 0, 12);

label_8004B224:
    ctx->pc = 0x8004B224u;
    // 8004B224: fcmpu   cr0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x8004B224u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[13], false);

label_8004B228:
    ctx->pc = 0x8004B228u;
    // 8004B228: bc    12, 1, 0x8004B230
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B230;
        }
    }

label_8004B22C:
    ctx->pc = 0x8004B22Cu;
    ctx->downcount -= 1;
    // 8004B22C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004B230:
    ctx->pc = 0x8004B230u;
    ctx->downcount -= 16;
    // 8004B230: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B234:
    ctx->pc = 0x8004B234u;
    // 8004B234: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B238:
    ctx->pc = 0x8004B238u;
    // 8004B238: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004B23C:
    ctx->pc = 0x8004B23Cu;
    // 8004B23C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004B240:
    ctx->pc = 0x8004B240u;
    // 8004B240: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B244:
    ctx->pc = 0x8004B244u;
    ctx->downcount -= 18;
    // 8004B244: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B248:
    ctx->pc = 0x8004B248u;
    // 8004B248: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B24C:
    ctx->pc = 0x8004B24Cu;
    // 8004B24C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8004B250:
    ctx->pc = 0x8004B250u;
    // 8004B250: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B254:
    ctx->pc = 0x8004B254u;
    // 8004B254: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B258:
    ctx->pc = 0x8004B258u;
    // 8004B258: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B25C:
    ctx->pc = 0x8004B25Cu;
    // 8004B25C: stfs     f1, 80(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B25Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004B260:
    ctx->pc = 0x8004B260u;
    // 8004B260: bl      0x8004FCDC
    {
            ctx->lr = 0x8004B264u;
            ctx->pc = 0x8004FCDCu;
            return;
    }

label_8004B264:
    ctx->pc = 0x8004B264u;
    ctx->downcount -= 18;
    // 8004B264: lfs     f0, 104(r3)
    if (!ppc_fp_available_inline(ctx, 0x8004B264u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(104);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004B268:
    ctx->pc = 0x8004B268u;
    // 8004B268: stfs     f0, 76(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B268u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004B26C:
    ctx->pc = 0x8004B26Cu;
    // 8004B26C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B270:
    ctx->pc = 0x8004B270u;
    // 8004B270: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B274:
    ctx->pc = 0x8004B274u;
    // 8004B274: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004B278:
    ctx->pc = 0x8004B278u;
    // 8004B278: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004B27C:
    ctx->pc = 0x8004B27Cu;
    // 8004B27C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B280:
    ctx->pc = 0x8004B280u;
    ctx->downcount -= 21;
    // 8004B280: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B284:
    ctx->pc = 0x8004B284u;
    // 8004B284: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B288:
    ctx->pc = 0x8004B288u;
    // 8004B288: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8004B28C:
    ctx->pc = 0x8004B28Cu;
    // 8004B28C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B290:
    ctx->pc = 0x8004B290u;
    // 8004B290: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B294:
    ctx->pc = 0x8004B294u;
    // 8004B294: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004B298:
    ctx->pc = 0x8004B298u;
    // 8004B298: stw     r0, 60(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B29C:
    ctx->pc = 0x8004B29Cu;
    // 8004B29C: stw     r0, 56(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B2A0:
    ctx->pc = 0x8004B2A0u;
    // 8004B2A0: lwz     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004B2A4:
    ctx->pc = 0x8004B2A4u;
    // 8004B2A4: lwz     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B2A8:
    ctx->pc = 0x8004B2A8u;
    // 8004B2A8: bl      0x8009BCD8
    {
            ctx->lr = 0x8004B2ACu;
            ctx->pc = 0x8009BCD8u;
            return;
    }

label_8004B2AC:
    ctx->pc = 0x8004B2ACu;
    ctx->downcount -= 5;
    // 8004B2AC: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B2B0:
    ctx->pc = 0x8004B2B0u;
    // 8004B2B0: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B2B4:
    ctx->pc = 0x8004B2B4u;
    // 8004B2B4: lfs     f0, 20168(r9)
    if (!ppc_fp_available_inline(ctx, 0x8004B2B4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004B2B8:
    ctx->pc = 0x8004B2B8u;
    // 8004B2B8: stfs     f0, 80(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B2B8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004B2BC:
    ctx->pc = 0x8004B2BCu;
    // 8004B2BC: bl      0x8004FCDC
    {
            ctx->lr = 0x8004B2C0u;
            ctx->pc = 0x8004FCDCu;
            return;
    }

label_8004B2C0:
    ctx->pc = 0x8004B2C0u;
    ctx->downcount -= 19;
    // 8004B2C0: lfs     f0, 104(r3)
    if (!ppc_fp_available_inline(ctx, 0x8004B2C0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(104);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004B2C4:
    ctx->pc = 0x8004B2C4u;
    // 8004B2C4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004B2C8:
    ctx->pc = 0x8004B2C8u;
    // 8004B2C8: stfs     f0, 76(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B2C8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004B2CC:
    ctx->pc = 0x8004B2CCu;
    // 8004B2CC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B2D0:
    ctx->pc = 0x8004B2D0u;
    // 8004B2D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B2D4:
    ctx->pc = 0x8004B2D4u;
    // 8004B2D4: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004B2D8:
    ctx->pc = 0x8004B2D8u;
    // 8004B2D8: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004B2DC:
    ctx->pc = 0x8004B2DCu;
    // 8004B2DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B2E0:
    ctx->pc = 0x8004B2E0u;
    ctx->downcount -= 29;
    // 8004B2E0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B2E4:
    ctx->pc = 0x8004B2E4u;
    // 8004B2E4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B2E8:
    ctx->pc = 0x8004B2E8u;
    // 8004B2E8: stmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8004B2EC:
    ctx->pc = 0x8004B2ECu;
    // 8004B2EC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B2F0:
    ctx->pc = 0x8004B2F0u;
    // 8004B2F0: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_8004B2F4:
    ctx->pc = 0x8004B2F4u;
    // 8004B2F4: lwz     r0, -27624(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-27624);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B2F8:
    ctx->pc = 0x8004B2F8u;
    // 8004B2F8: lis     r10, 17200
    ctx->gpr[10] = ((u32)(s32)(17200) << 16);

label_8004B2FC:
    ctx->pc = 0x8004B2FCu;
    // 8004B2FC: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B300:
    ctx->pc = 0x8004B300u;
    // 8004B300: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B304:
    ctx->pc = 0x8004B304u;
    // 8004B304: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B308:
    ctx->pc = 0x8004B308u;
    // 8004B308: lfd     f13, 20176(r9)
    if (!ppc_fp_available_inline(ctx, 0x8004B308u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20176);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004B30C:
    ctx->pc = 0x8004B30Cu;
    // 8004B30C: stw     r10, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8004B310:
    ctx->pc = 0x8004B310u;
    // 8004B310: lwz     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004B314:
    ctx->pc = 0x8004B314u;
    // 8004B314: lfd     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004B314u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004B318:
    ctx->pc = 0x8004B318u;
    // 8004B318: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x8004B318u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_8004B31C:
    ctx->pc = 0x8004B31Cu;
    // 8004B31C: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8004B31Cu)) return;
    ppc_frsp(ctx, 0, 0);

label_8004B320:
    ctx->pc = 0x8004B320u;
    // 8004B320: stfs     f0, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B320u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004B324:
    ctx->pc = 0x8004B324u;
    // 8004B324: lwz     r3, 228(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(228);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B328:
    ctx->pc = 0x8004B328u;
    // 8004B328: bl      0x80082C00
    {
            ctx->lr = 0x8004B32Cu;
            ctx->pc = 0x80082C00u;
            return;
    }

label_8004B32C:
    ctx->pc = 0x8004B32Cu;
    ctx->downcount -= 3;
    // 8004B32C: lwz     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004B330:
    ctx->pc = 0x8004B330u;
    // 8004B330: lwz     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B334:
    ctx->pc = 0x8004B334u;
    // 8004B334: bl      0x8009BCD8
    {
            ctx->lr = 0x8004B338u;
            ctx->pc = 0x8009BCD8u;
            return;
    }

label_8004B338:
    ctx->pc = 0x8004B338u;
    ctx->downcount -= 16;
    // 8004B338: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B33C:
    ctx->pc = 0x8004B33Cu;
    // 8004B33C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B340:
    ctx->pc = 0x8004B340u;
    // 8004B340: lmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004B344:
    ctx->pc = 0x8004B344u;
    // 8004B344: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8004B348:
    ctx->pc = 0x8004B348u;
    // 8004B348: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B34C:
    ctx->pc = 0x8004B34Cu;
    ctx->downcount -= 10;
    // 8004B34C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B350:
    ctx->pc = 0x8004B350u;
    // 8004B350: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B354:
    ctx->pc = 0x8004B354u;
    // 8004B354: stfd     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004B354u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8004B358:
    ctx->pc = 0x8004B358u;
    // 8004B358: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B35C:
    ctx->pc = 0x8004B35Cu;
    // 8004B35C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B360:
    ctx->pc = 0x8004B360u;
    // 8004B360: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B364:
    ctx->pc = 0x8004B364u;
    // 8004B364: lfs     f1, 20184(r9)
    if (!ppc_fp_available_inline(ctx, 0x8004B364u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20184);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004B368:
    ctx->pc = 0x8004B368u;
    // 8004B368: lfs     f31, 64(r11)
    if (!ppc_fp_available_inline(ctx, 0x8004B368u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(64);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8004B36C:
    ctx->pc = 0x8004B36Cu;
    // 8004B36C: fcmpu   cr0, f31, f1
    if (!ppc_fp_available_inline(ctx, 0x8004B36Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[1], false);

label_8004B370:
    ctx->pc = 0x8004B370u;
    // 8004B370: bc    12, 2, 0x8004B394
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B394;
        }
    }

label_8004B374:
    ctx->pc = 0x8004B374u;
    ctx->downcount -= 7;
    // 8004B374: lwz     r9, 84(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(84);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004B378:
    ctx->pc = 0x8004B378u;
    // 8004B378: lha     r3, 40(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(40);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B37C:
    ctx->pc = 0x8004B37Cu;
    // 8004B37C: lwz     r0, 44(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B380:
    ctx->pc = 0x8004B380u;
    // 8004B380: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B384:
    ctx->pc = 0x8004B384u;
    // 8004B384: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B388:
    ctx->pc = 0x8004B388u;
    // 8004B388: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8004B38Cu;
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B38C:
    ctx->pc = 0x8004B38Cu;
    ctx->downcount -= 2;
    // 8004B38C: fmuls   f1, f31, f1
    if (!ppc_fp_available_inline(ctx, 0x8004B38Cu)) return;
    ppc_fmuls(ctx, 1, 31, 1);

label_8004B390:
    ctx->pc = 0x8004B390u;
    // 8004B390: fmuls   f1, f1, f1
    if (!ppc_fp_available_inline(ctx, 0x8004B390u)) return;
    ppc_fmuls(ctx, 1, 1, 1);

label_8004B394:
    ctx->pc = 0x8004B394u;
    ctx->downcount -= 6;
    // 8004B394: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B398:
    ctx->pc = 0x8004B398u;
    // 8004B398: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B39C:
    ctx->pc = 0x8004B39Cu;
    // 8004B39C: lfd     f31, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004B39Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004B3A0:
    ctx->pc = 0x8004B3A0u;
    // 8004B3A0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8004B3A4:
    ctx->pc = 0x8004B3A4u;
    // 8004B3A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B3A8:
    ctx->pc = 0x8004B3A8u;
    ctx->downcount -= 35;
    // 8004B3A8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B3AC:
    ctx->pc = 0x8004B3ACu;
    // 8004B3AC: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_8004B3B0:
    ctx->pc = 0x8004B3B0u;
    // 8004B3B0: lwz     r0, -27624(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-27624);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B3B4:
    ctx->pc = 0x8004B3B4u;
    // 8004B3B4: lis     r10, 17200
    ctx->gpr[10] = ((u32)(s32)(17200) << 16);

label_8004B3B8:
    ctx->pc = 0x8004B3B8u;
    // 8004B3B8: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B3BC:
    ctx->pc = 0x8004B3BCu;
    // 8004B3BC: lfs     f11, 4(r3)
    if (!ppc_fp_available_inline(ctx, 0x8004B3BCu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8004B3C0:
    ctx->pc = 0x8004B3C0u;
    // 8004B3C0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B3C4:
    ctx->pc = 0x8004B3C4u;
    // 8004B3C4: lis     r8, -32722
    ctx->gpr[8] = ((u32)(s32)(-32722) << 16);

label_8004B3C8:
    ctx->pc = 0x8004B3C8u;
    // 8004B3C8: lfd     f13, 20192(r9)
    if (!ppc_fp_available_inline(ctx, 0x8004B3C8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20192);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004B3CC:
    ctx->pc = 0x8004B3CCu;
    // 8004B3CC: stw     r10, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8004B3D0:
    ctx->pc = 0x8004B3D0u;
    // 8004B3D0: lfs     f12, 72(r3)
    if (!ppc_fp_available_inline(ctx, 0x8004B3D0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(72);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_8004B3D4:
    ctx->pc = 0x8004B3D4u;
    // 8004B3D4: lfd     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004B3D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004B3D8:
    ctx->pc = 0x8004B3D8u;
    // 8004B3D8: lfs     f1, 20200(r8)
    if (!ppc_fp_available_inline(ctx, 0x8004B3D8u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(20200);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004B3DC:
    ctx->pc = 0x8004B3DCu;
    // 8004B3DC: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x8004B3DCu)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_8004B3E0:
    ctx->pc = 0x8004B3E0u;
    // 8004B3E0: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8004B3E0u)) return;
    ppc_frsp(ctx, 0, 0);

label_8004B3E4:
    ctx->pc = 0x8004B3E4u;
    // 8004B3E4: fsubs   f0, f0, f11
    if (!ppc_fp_available_inline(ctx, 0x8004B3E4u)) return;
    ppc_fsubs(ctx, 0, 0, 11);

label_8004B3E8:
    ctx->pc = 0x8004B3E8u;
    // 8004B3E8: fdivs   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x8004B3E8u)) return;
    ppc_fdivs(ctx, 0, 0, 12);

label_8004B3EC:
    ctx->pc = 0x8004B3ECu;
    // 8004B3EC: fcmpu   cr0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8004B3ECu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[1], false);

label_8004B3F0:
    ctx->pc = 0x8004B3F0u;
    // 8004B3F0: bc    12, 1, 0x8004B40C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B40C;
        }
    }

label_8004B3F4:
    ctx->pc = 0x8004B3F4u;
    ctx->downcount -= 5;
    // 8004B3F4: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B3F8:
    ctx->pc = 0x8004B3F8u;
    // 8004B3F8: fmr    f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004B3F8u)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_8004B3FC:
    ctx->pc = 0x8004B3FCu;
    // 8004B3FC: lfs     f13, 20204(r9)
    if (!ppc_fp_available_inline(ctx, 0x8004B3FCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20204);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8004B400:
    ctx->pc = 0x8004B400u;
    // 8004B400: fcmpu   cr0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x8004B400u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[13], false);

label_8004B404:
    ctx->pc = 0x8004B404u;
    // 8004B404: bc    4, 0, 0x8004B40C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B40C;
        }
    }

label_8004B408:
    ctx->pc = 0x8004B408u;
    ctx->downcount -= 1;
    // 8004B408: fmr    f1, f13
    if (!ppc_fp_available_inline(ctx, 0x8004B408u)) return;
    ctx->fpr[1] = ctx->fpr[13];

label_8004B40C:
    ctx->pc = 0x8004B40Cu;
    ctx->downcount -= 2;
    // 8004B40C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004B410:
    ctx->pc = 0x8004B410u;
    // 8004B410: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B414:
    ctx->pc = 0x8004B414u;
    ctx->downcount -= 5;
    // 8004B414: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B418:
    ctx->pc = 0x8004B418u;
    // 8004B418: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B41C:
    ctx->pc = 0x8004B41Cu;
    // 8004B41C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B420:
    ctx->pc = 0x8004B420u;
    // 8004B420: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B424:
    ctx->pc = 0x8004B424u;
    // 8004B424: bl      0x8004FEB8
    {
            ctx->lr = 0x8004B428u;
            ctx->pc = 0x8004FEB8u;
            return;
    }

label_8004B428:
    ctx->pc = 0x8004B428u;
    ctx->downcount -= 6;
    // 8004B428: fadds   f1, f1, f1
    if (!ppc_fp_available_inline(ctx, 0x8004B428u)) return;
    ppc_fadds(ctx, 1, 1, 1);

label_8004B42C:
    ctx->pc = 0x8004B42Cu;
    // 8004B42C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B430:
    ctx->pc = 0x8004B430u;
    // 8004B430: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B434:
    ctx->pc = 0x8004B434u;
    // 8004B434: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8004B438:
    ctx->pc = 0x8004B438u;
    // 8004B438: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B43C:
    ctx->pc = 0x8004B43Cu;
    ctx->downcount -= 4;
    // 8004B43C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004B440:
    ctx->pc = 0x8004B440u;
    // 8004B440: lwz     r3, 232(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(232);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B444:
    ctx->pc = 0x8004B444u;
    // 8004B444: xori    r3, r3, 0x0001
    ctx->gpr[3] = ctx->gpr[3] ^ 0x0001u;

label_8004B448:
    ctx->pc = 0x8004B448u;
    // 8004B448: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B44C:
    ctx->pc = 0x8004B44Cu;
    ctx->downcount -= 21;
    // 8004B44C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B450:
    ctx->pc = 0x8004B450u;
    // 8004B450: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B454:
    ctx->pc = 0x8004B454u;
    // 8004B454: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8004B458:
    ctx->pc = 0x8004B458u;
    // 8004B458: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B45C:
    ctx->pc = 0x8004B45Cu;
    // 8004B45C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B460:
    ctx->pc = 0x8004B460u;
    // 8004B460: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004B464:
    ctx->pc = 0x8004B464u;
    // 8004B464: stw     r0, 60(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B468:
    ctx->pc = 0x8004B468u;
    // 8004B468: stw     r0, 56(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B46C:
    ctx->pc = 0x8004B46Cu;
    // 8004B46C: lwz     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004B470:
    ctx->pc = 0x8004B470u;
    // 8004B470: lwz     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B474:
    ctx->pc = 0x8004B474u;
    // 8004B474: bl      0x8009BCD8
    {
            ctx->lr = 0x8004B478u;
            ctx->pc = 0x8009BCD8u;
            return;
    }

label_8004B478:
    ctx->pc = 0x8004B478u;
    ctx->downcount -= 5;
    // 8004B478: lis     r9, -32722
    ctx->gpr[9] = ((u32)(s32)(-32722) << 16);

label_8004B47C:
    ctx->pc = 0x8004B47Cu;
    // 8004B47C: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B480:
    ctx->pc = 0x8004B480u;
    // 8004B480: lfs     f0, 20208(r9)
    if (!ppc_fp_available_inline(ctx, 0x8004B480u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20208);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004B484:
    ctx->pc = 0x8004B484u;
    // 8004B484: stfs     f0, 80(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B484u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004B488:
    ctx->pc = 0x8004B488u;
    // 8004B488: bl      0x8004FCDC
    {
            ctx->lr = 0x8004B48Cu;
            ctx->pc = 0x8004FCDCu;
            return;
    }

label_8004B48C:
    ctx->pc = 0x8004B48Cu;
    ctx->downcount -= 19;
    // 8004B48C: lfs     f0, 104(r3)
    if (!ppc_fp_available_inline(ctx, 0x8004B48Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(104);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004B490:
    ctx->pc = 0x8004B490u;
    // 8004B490: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004B494:
    ctx->pc = 0x8004B494u;
    // 8004B494: stfs     f0, 76(r30)
    if (!ppc_fp_available_inline(ctx, 0x8004B494u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004B498:
    ctx->pc = 0x8004B498u;
    // 8004B498: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B49C:
    ctx->pc = 0x8004B49Cu;
    // 8004B49C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B4A0:
    ctx->pc = 0x8004B4A0u;
    // 8004B4A0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004B4A4:
    ctx->pc = 0x8004B4A4u;
    // 8004B4A4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004B4A8:
    ctx->pc = 0x8004B4A8u;
    // 8004B4A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800474C0;
        }
    }

label_8004B4AC:
    ctx->pc = 0x8004B4ACu;
    ctx->downcount -= 5;
    // 8004B4AC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B4B0:
    ctx->pc = 0x8004B4B0u;
    // 8004B4B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B4B4:
    ctx->pc = 0x8004B4B4u;
    // 8004B4B4: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004B4B8:
    ctx->pc = 0x8004B4B8u;
    // 8004B4B8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B4BC:
    ctx->pc = 0x8004B4BCu;
    // 8004B4BC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

    ctx->pc = 0x8004B4C0u;
    return;
return_dispatch_800474C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x800474C4u: goto label_800474C4;
    case 0x80047554u: goto label_80047554;
    case 0x80047564u: goto label_80047564;
    case 0x80047590u: goto label_80047590;
    case 0x800475E8u: goto label_800475E8;
    case 0x800475F0u: goto label_800475F0;
    case 0x8004764Cu: goto label_8004764C;
    case 0x80047670u: goto label_80047670;
    case 0x800476C8u: goto label_800476C8;
    case 0x800477B0u: goto label_800477B0;
    case 0x800477C0u: goto label_800477C0;
    case 0x800477ECu: goto label_800477EC;
    case 0x80047844u: goto label_80047844;
    case 0x8004784Cu: goto label_8004784C;
    case 0x80047878u: goto label_80047878;
    case 0x80047910u: goto label_80047910;
    case 0x8004792Cu: goto label_8004792C;
    case 0x80047984u: goto label_80047984;
    case 0x8004798Cu: goto label_8004798C;
    case 0x80047994u: goto label_80047994;
    case 0x800479E0u: goto label_800479E0;
    case 0x800479E8u: goto label_800479E8;
    case 0x800479F0u: goto label_800479F0;
    case 0x80047A70u: goto label_80047A70;
    case 0x80047A80u: goto label_80047A80;
    case 0x80047AA8u: goto label_80047AA8;
    case 0x80047AD0u: goto label_80047AD0;
    case 0x80047AD8u: goto label_80047AD8;
    case 0x80047AFCu: goto label_80047AFC;
    case 0x80047B08u: goto label_80047B08;
    case 0x80047B74u: goto label_80047B74;
    case 0x80047B98u: goto label_80047B98;
    case 0x80047BD0u: goto label_80047BD0;
    case 0x80047BF0u: goto label_80047BF0;
    case 0x80047C28u: goto label_80047C28;
    case 0x80047CCCu: goto label_80047CCC;
    case 0x80047CDCu: goto label_80047CDC;
    case 0x80047D08u: goto label_80047D08;
    case 0x80047D6Cu: goto label_80047D6C;
    case 0x80047D74u: goto label_80047D74;
    case 0x80047E04u: goto label_80047E04;
    case 0x80047E14u: goto label_80047E14;
    case 0x80047E40u: goto label_80047E40;
    case 0x80047E98u: goto label_80047E98;
    case 0x80047EA0u: goto label_80047EA0;
    case 0x80047EFCu: goto label_80047EFC;
    case 0x80047F20u: goto label_80047F20;
    case 0x80047F78u: goto label_80047F78;
    case 0x80048060u: goto label_80048060;
    case 0x80048070u: goto label_80048070;
    case 0x8004809Cu: goto label_8004809C;
    case 0x800480F4u: goto label_800480F4;
    case 0x800480FCu: goto label_800480FC;
    case 0x80048128u: goto label_80048128;
    case 0x800481C0u: goto label_800481C0;
    case 0x800481DCu: goto label_800481DC;
    case 0x80048234u: goto label_80048234;
    case 0x8004823Cu: goto label_8004823C;
    case 0x80048244u: goto label_80048244;
    case 0x80048290u: goto label_80048290;
    case 0x80048298u: goto label_80048298;
    case 0x800482A0u: goto label_800482A0;
    case 0x80048320u: goto label_80048320;
    case 0x80048330u: goto label_80048330;
    case 0x80048358u: goto label_80048358;
    case 0x80048380u: goto label_80048380;
    case 0x80048388u: goto label_80048388;
    case 0x800483ACu: goto label_800483AC;
    case 0x800483B8u: goto label_800483B8;
    case 0x80048424u: goto label_80048424;
    case 0x80048448u: goto label_80048448;
    case 0x80048480u: goto label_80048480;
    case 0x800484A0u: goto label_800484A0;
    case 0x800484D8u: goto label_800484D8;
    case 0x8004857Cu: goto label_8004857C;
    case 0x8004858Cu: goto label_8004858C;
    case 0x800485B8u: goto label_800485B8;
    case 0x8004861Cu: goto label_8004861C;
    case 0x80048624u: goto label_80048624;
    case 0x800486B4u: goto label_800486B4;
    case 0x800486C4u: goto label_800486C4;
    case 0x800486F0u: goto label_800486F0;
    case 0x80048748u: goto label_80048748;
    case 0x80048750u: goto label_80048750;
    case 0x800487ACu: goto label_800487AC;
    case 0x800487D0u: goto label_800487D0;
    case 0x80048828u: goto label_80048828;
    case 0x80048910u: goto label_80048910;
    case 0x80048920u: goto label_80048920;
    case 0x8004894Cu: goto label_8004894C;
    case 0x800489A4u: goto label_800489A4;
    case 0x800489ACu: goto label_800489AC;
    case 0x800489D8u: goto label_800489D8;
    case 0x80048A70u: goto label_80048A70;
    case 0x80048A8Cu: goto label_80048A8C;
    case 0x80048AE4u: goto label_80048AE4;
    case 0x80048AECu: goto label_80048AEC;
    case 0x80048AF4u: goto label_80048AF4;
    case 0x80048B40u: goto label_80048B40;
    case 0x80048B48u: goto label_80048B48;
    case 0x80048B50u: goto label_80048B50;
    case 0x80048B98u: goto label_80048B98;
    case 0x80048BBCu: goto label_80048BBC;
    case 0x80048BC4u: goto label_80048BC4;
    case 0x80048BD8u: goto label_80048BD8;
    case 0x80048C2Cu: goto label_80048C2C;
    case 0x80048C40u: goto label_80048C40;
    case 0x80048C54u: goto label_80048C54;
    case 0x80048C68u: goto label_80048C68;
    case 0x80048C7Cu: goto label_80048C7C;
    case 0x80048C90u: goto label_80048C90;
    case 0x80048CA4u: goto label_80048CA4;
    case 0x80048CB8u: goto label_80048CB8;
    case 0x80048CCCu: goto label_80048CCC;
    case 0x80048CE0u: goto label_80048CE0;
    case 0x80048CF4u: goto label_80048CF4;
    case 0x8004900Cu: goto label_8004900C;
    case 0x8004903Cu: goto label_8004903C;
    case 0x8004906Cu: goto label_8004906C;
    case 0x8004909Cu: goto label_8004909C;
    case 0x800490CCu: goto label_800490CC;
    case 0x800490FCu: goto label_800490FC;
    case 0x8004912Cu: goto label_8004912C;
    case 0x8004915Cu: goto label_8004915C;
    case 0x8004918Cu: goto label_8004918C;
    case 0x800491BCu: goto label_800491BC;
    case 0x800491ECu: goto label_800491EC;
    case 0x8004921Cu: goto label_8004921C;
    case 0x8004924Cu: goto label_8004924C;
    case 0x8004927Cu: goto label_8004927C;
    case 0x800492ACu: goto label_800492AC;
    case 0x800492DCu: goto label_800492DC;
    case 0x8004930Cu: goto label_8004930C;
    case 0x8004933Cu: goto label_8004933C;
    case 0x8004936Cu: goto label_8004936C;
    case 0x8004939Cu: goto label_8004939C;
    case 0x800493CCu: goto label_800493CC;
    case 0x800493FCu: goto label_800493FC;
    case 0x8004942Cu: goto label_8004942C;
    case 0x8004945Cu: goto label_8004945C;
    case 0x8004948Cu: goto label_8004948C;
    case 0x800494BCu: goto label_800494BC;
    case 0x800494ECu: goto label_800494EC;
    case 0x8004951Cu: goto label_8004951C;
    case 0x8004954Cu: goto label_8004954C;
    case 0x8004957Cu: goto label_8004957C;
    case 0x800495ACu: goto label_800495AC;
    case 0x800495DCu: goto label_800495DC;
    case 0x8004960Cu: goto label_8004960C;
    case 0x8004963Cu: goto label_8004963C;
    case 0x8004966Cu: goto label_8004966C;
    case 0x8004969Cu: goto label_8004969C;
    case 0x800496CCu: goto label_800496CC;
    case 0x800496FCu: goto label_800496FC;
    case 0x8004972Cu: goto label_8004972C;
    case 0x8004975Cu: goto label_8004975C;
    case 0x8004978Cu: goto label_8004978C;
    case 0x800497BCu: goto label_800497BC;
    case 0x800497ECu: goto label_800497EC;
    case 0x8004981Cu: goto label_8004981C;
    case 0x8004984Cu: goto label_8004984C;
    case 0x8004987Cu: goto label_8004987C;
    case 0x800498ACu: goto label_800498AC;
    case 0x800498DCu: goto label_800498DC;
    case 0x8004990Cu: goto label_8004990C;
    case 0x8004993Cu: goto label_8004993C;
    case 0x8004996Cu: goto label_8004996C;
    case 0x8004999Cu: goto label_8004999C;
    case 0x800499CCu: goto label_800499CC;
    case 0x800499FCu: goto label_800499FC;
    case 0x80049A2Cu: goto label_80049A2C;
    case 0x80049A5Cu: goto label_80049A5C;
    case 0x80049A8Cu: goto label_80049A8C;
    case 0x80049ABCu: goto label_80049ABC;
    case 0x80049AECu: goto label_80049AEC;
    case 0x80049B1Cu: goto label_80049B1C;
    case 0x80049B4Cu: goto label_80049B4C;
    case 0x80049B7Cu: goto label_80049B7C;
    case 0x80049BACu: goto label_80049BAC;
    case 0x80049BDCu: goto label_80049BDC;
    case 0x80049C0Cu: goto label_80049C0C;
    case 0x80049C3Cu: goto label_80049C3C;
    case 0x80049C6Cu: goto label_80049C6C;
    case 0x80049C9Cu: goto label_80049C9C;
    case 0x80049CCCu: goto label_80049CCC;
    case 0x80049CFCu: goto label_80049CFC;
    case 0x80049D2Cu: goto label_80049D2C;
    case 0x80049D5Cu: goto label_80049D5C;
    case 0x80049D8Cu: goto label_80049D8C;
    case 0x80049DBCu: goto label_80049DBC;
    case 0x80049DECu: goto label_80049DEC;
    case 0x80049E1Cu: goto label_80049E1C;
    case 0x80049E4Cu: goto label_80049E4C;
    case 0x80049E7Cu: goto label_80049E7C;
    case 0x80049EACu: goto label_80049EAC;
    case 0x80049EDCu: goto label_80049EDC;
    case 0x80049F0Cu: goto label_80049F0C;
    case 0x80049F3Cu: goto label_80049F3C;
    case 0x80049F6Cu: goto label_80049F6C;
    case 0x80049F9Cu: goto label_80049F9C;
    case 0x80049FCCu: goto label_80049FCC;
    case 0x80049FFCu: goto label_80049FFC;
    case 0x8004A02Cu: goto label_8004A02C;
    case 0x8004A05Cu: goto label_8004A05C;
    case 0x8004A08Cu: goto label_8004A08C;
    case 0x8004A0BCu: goto label_8004A0BC;
    case 0x8004A0ECu: goto label_8004A0EC;
    case 0x8004A11Cu: goto label_8004A11C;
    case 0x8004A14Cu: goto label_8004A14C;
    case 0x8004A17Cu: goto label_8004A17C;
    case 0x8004A1ACu: goto label_8004A1AC;
    case 0x8004A1DCu: goto label_8004A1DC;
    case 0x8004A20Cu: goto label_8004A20C;
    case 0x8004A23Cu: goto label_8004A23C;
    case 0x8004A26Cu: goto label_8004A26C;
    case 0x8004A29Cu: goto label_8004A29C;
    case 0x8004A2CCu: goto label_8004A2CC;
    case 0x8004A2FCu: goto label_8004A2FC;
    case 0x8004A32Cu: goto label_8004A32C;
    case 0x8004A35Cu: goto label_8004A35C;
    case 0x8004A38Cu: goto label_8004A38C;
    case 0x8004A3BCu: goto label_8004A3BC;
    case 0x8004A3ECu: goto label_8004A3EC;
    case 0x8004A41Cu: goto label_8004A41C;
    case 0x8004A44Cu: goto label_8004A44C;
    case 0x8004A47Cu: goto label_8004A47C;
    case 0x8004A4ACu: goto label_8004A4AC;
    case 0x8004A4DCu: goto label_8004A4DC;
    case 0x8004A50Cu: goto label_8004A50C;
    case 0x8004A53Cu: goto label_8004A53C;
    case 0x8004A56Cu: goto label_8004A56C;
    case 0x8004A59Cu: goto label_8004A59C;
    case 0x8004A5CCu: goto label_8004A5CC;
    case 0x8004A5FCu: goto label_8004A5FC;
    case 0x8004A62Cu: goto label_8004A62C;
    case 0x8004A65Cu: goto label_8004A65C;
    case 0x8004A68Cu: goto label_8004A68C;
    case 0x8004A6BCu: goto label_8004A6BC;
    case 0x8004A6ECu: goto label_8004A6EC;
    case 0x8004A71Cu: goto label_8004A71C;
    case 0x8004A74Cu: goto label_8004A74C;
    case 0x8004A77Cu: goto label_8004A77C;
    case 0x8004A7ACu: goto label_8004A7AC;
    case 0x8004A7DCu: goto label_8004A7DC;
    case 0x8004A80Cu: goto label_8004A80C;
    case 0x8004A83Cu: goto label_8004A83C;
    case 0x8004A86Cu: goto label_8004A86C;
    case 0x8004A89Cu: goto label_8004A89C;
    case 0x8004A8CCu: goto label_8004A8CC;
    case 0x8004A8FCu: goto label_8004A8FC;
    case 0x8004A92Cu: goto label_8004A92C;
    case 0x8004A95Cu: goto label_8004A95C;
    case 0x8004A98Cu: goto label_8004A98C;
    case 0x8004A9BCu: goto label_8004A9BC;
    case 0x8004A9ECu: goto label_8004A9EC;
    case 0x8004AA1Cu: goto label_8004AA1C;
    case 0x8004AA4Cu: goto label_8004AA4C;
    case 0x8004AA7Cu: goto label_8004AA7C;
    case 0x8004AAACu: goto label_8004AAAC;
    case 0x8004AADCu: goto label_8004AADC;
    case 0x8004AB0Cu: goto label_8004AB0C;
    case 0x8004AB3Cu: goto label_8004AB3C;
    case 0x8004AB6Cu: goto label_8004AB6C;
    case 0x8004AB9Cu: goto label_8004AB9C;
    case 0x8004ABCCu: goto label_8004ABCC;
    case 0x8004ABFCu: goto label_8004ABFC;
    case 0x8004AC2Cu: goto label_8004AC2C;
    case 0x8004AC5Cu: goto label_8004AC5C;
    case 0x8004AC8Cu: goto label_8004AC8C;
    case 0x8004ACBCu: goto label_8004ACBC;
    case 0x8004ACECu: goto label_8004ACEC;
    case 0x8004AD1Cu: goto label_8004AD1C;
    case 0x8004AD4Cu: goto label_8004AD4C;
    case 0x8004AD7Cu: goto label_8004AD7C;
    case 0x8004ADACu: goto label_8004ADAC;
    case 0x8004ADDCu: goto label_8004ADDC;
    case 0x8004AE0Cu: goto label_8004AE0C;
    case 0x8004AE3Cu: goto label_8004AE3C;
    case 0x8004AE6Cu: goto label_8004AE6C;
    case 0x8004AE9Cu: goto label_8004AE9C;
    case 0x8004AECCu: goto label_8004AECC;
    case 0x8004AEFCu: goto label_8004AEFC;
    case 0x8004AF2Cu: goto label_8004AF2C;
    case 0x8004AF5Cu: goto label_8004AF5C;
    case 0x8004AF8Cu: goto label_8004AF8C;
    case 0x8004AFBCu: goto label_8004AFBC;
    case 0x8004AFECu: goto label_8004AFEC;
    case 0x8004B01Cu: goto label_8004B01C;
    case 0x8004B04Cu: goto label_8004B04C;
    case 0x8004B07Cu: goto label_8004B07C;
    case 0x8004B0ACu: goto label_8004B0AC;
    case 0x8004B0DCu: goto label_8004B0DC;
    case 0x8004B10Cu: goto label_8004B10C;
    case 0x8004B154u: goto label_8004B154;
    case 0x8004B1D0u: goto label_8004B1D0;
    case 0x8004B1E0u: goto label_8004B1E0;
    case 0x8004B210u: goto label_8004B210;
    case 0x8004B264u: goto label_8004B264;
    case 0x8004B2ACu: goto label_8004B2AC;
    case 0x8004B2C0u: goto label_8004B2C0;
    case 0x8004B32Cu: goto label_8004B32C;
    case 0x8004B338u: goto label_8004B338;
    case 0x8004B38Cu: goto label_8004B38C;
    case 0x8004B428u: goto label_8004B428;
    case 0x8004B478u: goto label_8004B478;
    case 0x8004B48Cu: goto label_8004B48C;
    default: return;
    }
}

