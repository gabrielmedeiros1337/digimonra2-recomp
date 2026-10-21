// DolRecomp output
#include "../generated.h"

static void loop_802CCBD0(CPUState* ctx) {
label_802CCBD0:
    ctx->downcount -= 5;
    ctx->pc = 0x802CCBD0u;
    // 802CCBD0: lwzu     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

    ctx->pc = 0x802CCBD4u;
    // 802CCBD4: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x802CCBD8u;
    // 802CCBD8: stwu     r3, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
        ctx->gpr[5] = ea;
    }

    ctx->pc = 0x802CCBDCu;
    // 802CCBDC: stw     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 802CCBE0: bc    16, 0, 0x802CCBD0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CCBD0u;
                return;
            }
            goto label_802CCBD0;
        }
    }

    ctx->pc = 0x802CCBE4u;
}

static void loop_802CCE94(CPUState* ctx) {
label_802CCE94:
    ctx->downcount -= 2;
    ctx->pc = 0x802CCE94u;
    // 802CCE94: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    // 802CCE98: bc    16, 0, 0x802CCE94
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CCE94u;
                return;
            }
            goto label_802CCE94;
        }
    }

    ctx->pc = 0x802CCE9Cu;
}

static void loop_802CEB74(CPUState* ctx) {
label_802CEB74:
    ctx->downcount -= 5;
    // 802CEB74: or   r0, r4, r4
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[4];
    }

    ctx->pc = 0x802CEB78u;
    // 802CEB78: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

    ctx->pc = 0x802CEB7Cu;
    // 802CEB7C: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 802CEB80: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 802CEB84: bc    4, 2, 0x802CEB74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEB74u;
                return;
            }
            goto label_802CEB74;
        }
    }

    ctx->pc = 0x802CEB88u;
}

static void loop_802CEBE0(CPUState* ctx) {
label_802CEBE0:
    ctx->downcount -= 5;
    // 802CEBE0: or   r0, r4, r4
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[4];
    }

    ctx->pc = 0x802CEBE4u;
    // 802CEBE4: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

    ctx->pc = 0x802CEBE8u;
    // 802CEBE8: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 802CEBEC: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 802CEBF0: bc    4, 2, 0x802CEBE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEBE0u;
                return;
            }
            goto label_802CEBE0;
        }
    }

    ctx->pc = 0x802CEBF4u;
}

static void loop_802CEC54(CPUState* ctx) {
label_802CEC54:
    ctx->downcount -= 5;
    // 802CEC54: or   r0, r4, r4
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[4];
    }

    ctx->pc = 0x802CEC58u;
    // 802CEC58: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

    ctx->pc = 0x802CEC5Cu;
    // 802CEC5C: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 802CEC60: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 802CEC64: bc    4, 2, 0x802CEC54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEC54u;
                return;
            }
            goto label_802CEC54;
        }
    }

    ctx->pc = 0x802CEC68u;
}

static void loop_802CECBC(CPUState* ctx) {
label_802CECBC:
    ctx->downcount -= 5;
    // 802CECBC: or   r0, r4, r4
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[4];
    }

    ctx->pc = 0x802CECC0u;
    // 802CECC0: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

    ctx->pc = 0x802CECC4u;
    // 802CECC4: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 802CECC8: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 802CECCC: bc    4, 2, 0x802CECBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CECBCu;
                return;
            }
            goto label_802CECBC;
        }
    }

    ctx->pc = 0x802CECD0u;
}

static void loop_802CEDC0(CPUState* ctx) {
label_802CEDC0:
    ctx->downcount -= 5;
    // 802CEDC0: or   r0, r4, r4
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[4];
    }

    ctx->pc = 0x802CEDC4u;
    // 802CEDC4: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

    ctx->pc = 0x802CEDC8u;
    // 802CEDC8: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 802CEDCC: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 802CEDD0: bc    4, 2, 0x802CEDC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEDC0u;
                return;
            }
            goto label_802CEDC0;
        }
    }

    ctx->pc = 0x802CEDD4u;
}

static void loop_802CEE28(CPUState* ctx) {
label_802CEE28:
    ctx->downcount -= 5;
    // 802CEE28: or   r0, r4, r4
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[4];
    }

    ctx->pc = 0x802CEE2Cu;
    // 802CEE2C: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

    ctx->pc = 0x802CEE30u;
    // 802CEE30: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 802CEE34: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 802CEE38: bc    4, 2, 0x802CEE28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEE28u;
                return;
            }
            goto label_802CEE28;
        }
    }

    ctx->pc = 0x802CEE3Cu;
}

void func_802CB4C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x802CB4C0u: goto label_802CB4C0;
    case 0x802CB4C4u: goto label_802CB4C4;
    case 0x802CB4C8u: goto label_802CB4C8;
    case 0x802CB4CCu: goto label_802CB4CC;
    case 0x802CB4D0u: goto label_802CB4D0;
    case 0x802CB4D4u: goto label_802CB4D4;
    case 0x802CB4D8u: goto label_802CB4D8;
    case 0x802CB4DCu: goto label_802CB4DC;
    case 0x802CB4E0u: goto label_802CB4E0;
    case 0x802CB4E4u: goto label_802CB4E4;
    case 0x802CB4E8u: goto label_802CB4E8;
    case 0x802CB4ECu: goto label_802CB4EC;
    case 0x802CB4F0u: goto label_802CB4F0;
    case 0x802CB4F4u: goto label_802CB4F4;
    case 0x802CB4F8u: goto label_802CB4F8;
    case 0x802CB4FCu: goto label_802CB4FC;
    case 0x802CB500u: goto label_802CB500;
    case 0x802CB504u: goto label_802CB504;
    case 0x802CB508u: goto label_802CB508;
    case 0x802CB50Cu: goto label_802CB50C;
    case 0x802CB510u: goto label_802CB510;
    case 0x802CB514u: goto label_802CB514;
    case 0x802CB518u: goto label_802CB518;
    case 0x802CB51Cu: goto label_802CB51C;
    case 0x802CB520u: goto label_802CB520;
    case 0x802CB524u: goto label_802CB524;
    case 0x802CB528u: goto label_802CB528;
    case 0x802CB52Cu: goto label_802CB52C;
    case 0x802CB530u: goto label_802CB530;
    case 0x802CB534u: goto label_802CB534;
    case 0x802CB538u: goto label_802CB538;
    case 0x802CB53Cu: goto label_802CB53C;
    case 0x802CB540u: goto label_802CB540;
    case 0x802CB544u: goto label_802CB544;
    case 0x802CB548u: goto label_802CB548;
    case 0x802CB54Cu: goto label_802CB54C;
    case 0x802CB550u: goto label_802CB550;
    case 0x802CB554u: goto label_802CB554;
    case 0x802CB558u: goto label_802CB558;
    case 0x802CB55Cu: goto label_802CB55C;
    case 0x802CB560u: goto label_802CB560;
    case 0x802CB564u: goto label_802CB564;
    case 0x802CB568u: goto label_802CB568;
    case 0x802CB56Cu: goto label_802CB56C;
    case 0x802CB570u: goto label_802CB570;
    case 0x802CB574u: goto label_802CB574;
    case 0x802CB578u: goto label_802CB578;
    case 0x802CB57Cu: goto label_802CB57C;
    case 0x802CB580u: goto label_802CB580;
    case 0x802CB584u: goto label_802CB584;
    case 0x802CB588u: goto label_802CB588;
    case 0x802CB58Cu: goto label_802CB58C;
    case 0x802CB590u: goto label_802CB590;
    case 0x802CB594u: goto label_802CB594;
    case 0x802CB598u: goto label_802CB598;
    case 0x802CB59Cu: goto label_802CB59C;
    case 0x802CB5A0u: goto label_802CB5A0;
    case 0x802CB5A4u: goto label_802CB5A4;
    case 0x802CB5A8u: goto label_802CB5A8;
    case 0x802CB5ACu: goto label_802CB5AC;
    case 0x802CB5B0u: goto label_802CB5B0;
    case 0x802CB5B4u: goto label_802CB5B4;
    case 0x802CB5B8u: goto label_802CB5B8;
    case 0x802CB5BCu: goto label_802CB5BC;
    case 0x802CB5C0u: goto label_802CB5C0;
    case 0x802CB5C4u: goto label_802CB5C4;
    case 0x802CB5C8u: goto label_802CB5C8;
    case 0x802CB5CCu: goto label_802CB5CC;
    case 0x802CB5D0u: goto label_802CB5D0;
    case 0x802CB5D4u: goto label_802CB5D4;
    case 0x802CB5D8u: goto label_802CB5D8;
    case 0x802CB5DCu: goto label_802CB5DC;
    case 0x802CB5E0u: goto label_802CB5E0;
    case 0x802CB5E4u: goto label_802CB5E4;
    case 0x802CB5E8u: goto label_802CB5E8;
    case 0x802CB5ECu: goto label_802CB5EC;
    case 0x802CB5F0u: goto label_802CB5F0;
    case 0x802CB5F4u: goto label_802CB5F4;
    case 0x802CB5F8u: goto label_802CB5F8;
    case 0x802CB5FCu: goto label_802CB5FC;
    case 0x802CB600u: goto label_802CB600;
    case 0x802CB604u: goto label_802CB604;
    case 0x802CB608u: goto label_802CB608;
    case 0x802CB60Cu: goto label_802CB60C;
    case 0x802CB610u: goto label_802CB610;
    case 0x802CB614u: goto label_802CB614;
    case 0x802CB618u: goto label_802CB618;
    case 0x802CB61Cu: goto label_802CB61C;
    case 0x802CB620u: goto label_802CB620;
    case 0x802CB624u: goto label_802CB624;
    case 0x802CB628u: goto label_802CB628;
    case 0x802CB62Cu: goto label_802CB62C;
    case 0x802CB630u: goto label_802CB630;
    case 0x802CB634u: goto label_802CB634;
    case 0x802CB638u: goto label_802CB638;
    case 0x802CB63Cu: goto label_802CB63C;
    case 0x802CB640u: goto label_802CB640;
    case 0x802CB644u: goto label_802CB644;
    case 0x802CB648u: goto label_802CB648;
    case 0x802CB64Cu: goto label_802CB64C;
    case 0x802CB650u: goto label_802CB650;
    case 0x802CB654u: goto label_802CB654;
    case 0x802CB658u: goto label_802CB658;
    case 0x802CB65Cu: goto label_802CB65C;
    case 0x802CB660u: goto label_802CB660;
    case 0x802CB664u: goto label_802CB664;
    case 0x802CB668u: goto label_802CB668;
    case 0x802CB66Cu: goto label_802CB66C;
    case 0x802CB670u: goto label_802CB670;
    case 0x802CB674u: goto label_802CB674;
    case 0x802CB678u: goto label_802CB678;
    case 0x802CB67Cu: goto label_802CB67C;
    case 0x802CB680u: goto label_802CB680;
    case 0x802CB684u: goto label_802CB684;
    case 0x802CB688u: goto label_802CB688;
    case 0x802CB68Cu: goto label_802CB68C;
    case 0x802CB690u: goto label_802CB690;
    case 0x802CB694u: goto label_802CB694;
    case 0x802CB698u: goto label_802CB698;
    case 0x802CB69Cu: goto label_802CB69C;
    case 0x802CB6A0u: goto label_802CB6A0;
    case 0x802CB6A4u: goto label_802CB6A4;
    case 0x802CB6A8u: goto label_802CB6A8;
    case 0x802CB6ACu: goto label_802CB6AC;
    case 0x802CB6B0u: goto label_802CB6B0;
    case 0x802CB6B4u: goto label_802CB6B4;
    case 0x802CB6B8u: goto label_802CB6B8;
    case 0x802CB6BCu: goto label_802CB6BC;
    case 0x802CB6C0u: goto label_802CB6C0;
    case 0x802CB6C4u: goto label_802CB6C4;
    case 0x802CB6C8u: goto label_802CB6C8;
    case 0x802CB6CCu: goto label_802CB6CC;
    case 0x802CB6D0u: goto label_802CB6D0;
    case 0x802CB6D4u: goto label_802CB6D4;
    case 0x802CB6D8u: goto label_802CB6D8;
    case 0x802CB6DCu: goto label_802CB6DC;
    case 0x802CB6E0u: goto label_802CB6E0;
    case 0x802CB6E4u: goto label_802CB6E4;
    case 0x802CB6E8u: goto label_802CB6E8;
    case 0x802CB6ECu: goto label_802CB6EC;
    case 0x802CB6F0u: goto label_802CB6F0;
    case 0x802CB6F4u: goto label_802CB6F4;
    case 0x802CB6F8u: goto label_802CB6F8;
    case 0x802CB6FCu: goto label_802CB6FC;
    case 0x802CB700u: goto label_802CB700;
    case 0x802CB704u: goto label_802CB704;
    case 0x802CB708u: goto label_802CB708;
    case 0x802CB70Cu: goto label_802CB70C;
    case 0x802CB710u: goto label_802CB710;
    case 0x802CB714u: goto label_802CB714;
    case 0x802CB718u: goto label_802CB718;
    case 0x802CB71Cu: goto label_802CB71C;
    case 0x802CB720u: goto label_802CB720;
    case 0x802CB724u: goto label_802CB724;
    case 0x802CB728u: goto label_802CB728;
    case 0x802CB72Cu: goto label_802CB72C;
    case 0x802CB730u: goto label_802CB730;
    case 0x802CB734u: goto label_802CB734;
    case 0x802CB738u: goto label_802CB738;
    case 0x802CB73Cu: goto label_802CB73C;
    case 0x802CB740u: goto label_802CB740;
    case 0x802CB744u: goto label_802CB744;
    case 0x802CB748u: goto label_802CB748;
    case 0x802CB74Cu: goto label_802CB74C;
    case 0x802CB750u: goto label_802CB750;
    case 0x802CB754u: goto label_802CB754;
    case 0x802CB758u: goto label_802CB758;
    case 0x802CB75Cu: goto label_802CB75C;
    case 0x802CB760u: goto label_802CB760;
    case 0x802CB764u: goto label_802CB764;
    case 0x802CB768u: goto label_802CB768;
    case 0x802CB76Cu: goto label_802CB76C;
    case 0x802CB770u: goto label_802CB770;
    case 0x802CB774u: goto label_802CB774;
    case 0x802CB778u: goto label_802CB778;
    case 0x802CB77Cu: goto label_802CB77C;
    case 0x802CB780u: goto label_802CB780;
    case 0x802CB784u: goto label_802CB784;
    case 0x802CB788u: goto label_802CB788;
    case 0x802CB78Cu: goto label_802CB78C;
    case 0x802CB790u: goto label_802CB790;
    case 0x802CB794u: goto label_802CB794;
    case 0x802CB798u: goto label_802CB798;
    case 0x802CB79Cu: goto label_802CB79C;
    case 0x802CB7A0u: goto label_802CB7A0;
    case 0x802CB7A4u: goto label_802CB7A4;
    case 0x802CB7A8u: goto label_802CB7A8;
    case 0x802CB7ACu: goto label_802CB7AC;
    case 0x802CB7B0u: goto label_802CB7B0;
    case 0x802CB7B4u: goto label_802CB7B4;
    case 0x802CB7B8u: goto label_802CB7B8;
    case 0x802CB7BCu: goto label_802CB7BC;
    case 0x802CB7C0u: goto label_802CB7C0;
    case 0x802CB7C4u: goto label_802CB7C4;
    case 0x802CB7C8u: goto label_802CB7C8;
    case 0x802CB7CCu: goto label_802CB7CC;
    case 0x802CB7D0u: goto label_802CB7D0;
    case 0x802CB7D4u: goto label_802CB7D4;
    case 0x802CB7D8u: goto label_802CB7D8;
    case 0x802CB7DCu: goto label_802CB7DC;
    case 0x802CB7E0u: goto label_802CB7E0;
    case 0x802CB7E4u: goto label_802CB7E4;
    case 0x802CB7E8u: goto label_802CB7E8;
    case 0x802CB7ECu: goto label_802CB7EC;
    case 0x802CB7F0u: goto label_802CB7F0;
    case 0x802CB7F4u: goto label_802CB7F4;
    case 0x802CB7F8u: goto label_802CB7F8;
    case 0x802CB7FCu: goto label_802CB7FC;
    case 0x802CB800u: goto label_802CB800;
    case 0x802CB804u: goto label_802CB804;
    case 0x802CB808u: goto label_802CB808;
    case 0x802CB80Cu: goto label_802CB80C;
    case 0x802CB810u: goto label_802CB810;
    case 0x802CB814u: goto label_802CB814;
    case 0x802CB818u: goto label_802CB818;
    case 0x802CB81Cu: goto label_802CB81C;
    case 0x802CB820u: goto label_802CB820;
    case 0x802CB824u: goto label_802CB824;
    case 0x802CB828u: goto label_802CB828;
    case 0x802CB82Cu: goto label_802CB82C;
    case 0x802CB830u: goto label_802CB830;
    case 0x802CB834u: goto label_802CB834;
    case 0x802CB838u: goto label_802CB838;
    case 0x802CB83Cu: goto label_802CB83C;
    case 0x802CB840u: goto label_802CB840;
    case 0x802CB844u: goto label_802CB844;
    case 0x802CB848u: goto label_802CB848;
    case 0x802CB84Cu: goto label_802CB84C;
    case 0x802CB850u: goto label_802CB850;
    case 0x802CB854u: goto label_802CB854;
    case 0x802CB858u: goto label_802CB858;
    case 0x802CB85Cu: goto label_802CB85C;
    case 0x802CB860u: goto label_802CB860;
    case 0x802CB864u: goto label_802CB864;
    case 0x802CB868u: goto label_802CB868;
    case 0x802CB86Cu: goto label_802CB86C;
    case 0x802CB870u: goto label_802CB870;
    case 0x802CB874u: goto label_802CB874;
    case 0x802CB878u: goto label_802CB878;
    case 0x802CB87Cu: goto label_802CB87C;
    case 0x802CB880u: goto label_802CB880;
    case 0x802CB884u: goto label_802CB884;
    case 0x802CB888u: goto label_802CB888;
    case 0x802CB88Cu: goto label_802CB88C;
    case 0x802CB890u: goto label_802CB890;
    case 0x802CB894u: goto label_802CB894;
    case 0x802CB898u: goto label_802CB898;
    case 0x802CB89Cu: goto label_802CB89C;
    case 0x802CB8A0u: goto label_802CB8A0;
    case 0x802CB8A4u: goto label_802CB8A4;
    case 0x802CB8A8u: goto label_802CB8A8;
    case 0x802CB8ACu: goto label_802CB8AC;
    case 0x802CB8B0u: goto label_802CB8B0;
    case 0x802CB8B4u: goto label_802CB8B4;
    case 0x802CB8B8u: goto label_802CB8B8;
    case 0x802CB8BCu: goto label_802CB8BC;
    case 0x802CB8C0u: goto label_802CB8C0;
    case 0x802CB8C4u: goto label_802CB8C4;
    case 0x802CB8C8u: goto label_802CB8C8;
    case 0x802CB8CCu: goto label_802CB8CC;
    case 0x802CB8D0u: goto label_802CB8D0;
    case 0x802CB8D4u: goto label_802CB8D4;
    case 0x802CB8D8u: goto label_802CB8D8;
    case 0x802CB8DCu: goto label_802CB8DC;
    case 0x802CB8E0u: goto label_802CB8E0;
    case 0x802CB8E4u: goto label_802CB8E4;
    case 0x802CB8E8u: goto label_802CB8E8;
    case 0x802CB8ECu: goto label_802CB8EC;
    case 0x802CB8F0u: goto label_802CB8F0;
    case 0x802CB8F4u: goto label_802CB8F4;
    case 0x802CB8F8u: goto label_802CB8F8;
    case 0x802CB8FCu: goto label_802CB8FC;
    case 0x802CB900u: goto label_802CB900;
    case 0x802CB904u: goto label_802CB904;
    case 0x802CB908u: goto label_802CB908;
    case 0x802CB90Cu: goto label_802CB90C;
    case 0x802CB910u: goto label_802CB910;
    case 0x802CB914u: goto label_802CB914;
    case 0x802CB918u: goto label_802CB918;
    case 0x802CB91Cu: goto label_802CB91C;
    case 0x802CB920u: goto label_802CB920;
    case 0x802CB924u: goto label_802CB924;
    case 0x802CB928u: goto label_802CB928;
    case 0x802CB92Cu: goto label_802CB92C;
    case 0x802CB930u: goto label_802CB930;
    case 0x802CB934u: goto label_802CB934;
    case 0x802CB938u: goto label_802CB938;
    case 0x802CB93Cu: goto label_802CB93C;
    case 0x802CB940u: goto label_802CB940;
    case 0x802CB944u: goto label_802CB944;
    case 0x802CB948u: goto label_802CB948;
    case 0x802CB94Cu: goto label_802CB94C;
    case 0x802CB950u: goto label_802CB950;
    case 0x802CB954u: goto label_802CB954;
    case 0x802CB958u: goto label_802CB958;
    case 0x802CB95Cu: goto label_802CB95C;
    case 0x802CB960u: goto label_802CB960;
    case 0x802CB964u: goto label_802CB964;
    case 0x802CB968u: goto label_802CB968;
    case 0x802CB96Cu: goto label_802CB96C;
    case 0x802CB970u: goto label_802CB970;
    case 0x802CB974u: goto label_802CB974;
    case 0x802CB978u: goto label_802CB978;
    case 0x802CB97Cu: goto label_802CB97C;
    case 0x802CB980u: goto label_802CB980;
    case 0x802CB984u: goto label_802CB984;
    case 0x802CB988u: goto label_802CB988;
    case 0x802CB98Cu: goto label_802CB98C;
    case 0x802CB990u: goto label_802CB990;
    case 0x802CB994u: goto label_802CB994;
    case 0x802CB998u: goto label_802CB998;
    case 0x802CB99Cu: goto label_802CB99C;
    case 0x802CB9A0u: goto label_802CB9A0;
    case 0x802CB9A4u: goto label_802CB9A4;
    case 0x802CB9A8u: goto label_802CB9A8;
    case 0x802CB9ACu: goto label_802CB9AC;
    case 0x802CB9B0u: goto label_802CB9B0;
    case 0x802CB9B4u: goto label_802CB9B4;
    case 0x802CB9B8u: goto label_802CB9B8;
    case 0x802CB9BCu: goto label_802CB9BC;
    case 0x802CB9C0u: goto label_802CB9C0;
    case 0x802CB9C4u: goto label_802CB9C4;
    case 0x802CB9C8u: goto label_802CB9C8;
    case 0x802CB9CCu: goto label_802CB9CC;
    case 0x802CB9D0u: goto label_802CB9D0;
    case 0x802CB9D4u: goto label_802CB9D4;
    case 0x802CB9D8u: goto label_802CB9D8;
    case 0x802CB9DCu: goto label_802CB9DC;
    case 0x802CB9E0u: goto label_802CB9E0;
    case 0x802CB9E4u: goto label_802CB9E4;
    case 0x802CB9E8u: goto label_802CB9E8;
    case 0x802CB9ECu: goto label_802CB9EC;
    case 0x802CB9F0u: goto label_802CB9F0;
    case 0x802CB9F4u: goto label_802CB9F4;
    case 0x802CB9F8u: goto label_802CB9F8;
    case 0x802CB9FCu: goto label_802CB9FC;
    case 0x802CBA00u: goto label_802CBA00;
    case 0x802CBA04u: goto label_802CBA04;
    case 0x802CBA08u: goto label_802CBA08;
    case 0x802CBA0Cu: goto label_802CBA0C;
    case 0x802CBA10u: goto label_802CBA10;
    case 0x802CBA14u: goto label_802CBA14;
    case 0x802CBA18u: goto label_802CBA18;
    case 0x802CBA1Cu: goto label_802CBA1C;
    case 0x802CBA20u: goto label_802CBA20;
    case 0x802CBA24u: goto label_802CBA24;
    case 0x802CBA28u: goto label_802CBA28;
    case 0x802CBA2Cu: goto label_802CBA2C;
    case 0x802CBA30u: goto label_802CBA30;
    case 0x802CBA34u: goto label_802CBA34;
    case 0x802CBA38u: goto label_802CBA38;
    case 0x802CBA3Cu: goto label_802CBA3C;
    case 0x802CBA40u: goto label_802CBA40;
    case 0x802CBA44u: goto label_802CBA44;
    case 0x802CBA48u: goto label_802CBA48;
    case 0x802CBA4Cu: goto label_802CBA4C;
    case 0x802CBA50u: goto label_802CBA50;
    case 0x802CBA54u: goto label_802CBA54;
    case 0x802CBA58u: goto label_802CBA58;
    case 0x802CBA5Cu: goto label_802CBA5C;
    case 0x802CBA60u: goto label_802CBA60;
    case 0x802CBA64u: goto label_802CBA64;
    case 0x802CBA68u: goto label_802CBA68;
    case 0x802CBA6Cu: goto label_802CBA6C;
    case 0x802CBA70u: goto label_802CBA70;
    case 0x802CBA74u: goto label_802CBA74;
    case 0x802CBA78u: goto label_802CBA78;
    case 0x802CBA7Cu: goto label_802CBA7C;
    case 0x802CBA80u: goto label_802CBA80;
    case 0x802CBA84u: goto label_802CBA84;
    case 0x802CBA88u: goto label_802CBA88;
    case 0x802CBA8Cu: goto label_802CBA8C;
    case 0x802CBA90u: goto label_802CBA90;
    case 0x802CBA94u: goto label_802CBA94;
    case 0x802CBA98u: goto label_802CBA98;
    case 0x802CBA9Cu: goto label_802CBA9C;
    case 0x802CBAA0u: goto label_802CBAA0;
    case 0x802CBAA4u: goto label_802CBAA4;
    case 0x802CBAA8u: goto label_802CBAA8;
    case 0x802CBAACu: goto label_802CBAAC;
    case 0x802CBAB0u: goto label_802CBAB0;
    case 0x802CBAB4u: goto label_802CBAB4;
    case 0x802CBAB8u: goto label_802CBAB8;
    case 0x802CBABCu: goto label_802CBABC;
    case 0x802CBAC0u: goto label_802CBAC0;
    case 0x802CBAC4u: goto label_802CBAC4;
    case 0x802CBAC8u: goto label_802CBAC8;
    case 0x802CBACCu: goto label_802CBACC;
    case 0x802CBAD0u: goto label_802CBAD0;
    case 0x802CBAD4u: goto label_802CBAD4;
    case 0x802CBAD8u: goto label_802CBAD8;
    case 0x802CBADCu: goto label_802CBADC;
    case 0x802CBAE0u: goto label_802CBAE0;
    case 0x802CBAE4u: goto label_802CBAE4;
    case 0x802CBAE8u: goto label_802CBAE8;
    case 0x802CBAECu: goto label_802CBAEC;
    case 0x802CBAF0u: goto label_802CBAF0;
    case 0x802CBAF4u: goto label_802CBAF4;
    case 0x802CBAF8u: goto label_802CBAF8;
    case 0x802CBAFCu: goto label_802CBAFC;
    case 0x802CBB00u: goto label_802CBB00;
    case 0x802CBB04u: goto label_802CBB04;
    case 0x802CBB08u: goto label_802CBB08;
    case 0x802CBB0Cu: goto label_802CBB0C;
    case 0x802CBB10u: goto label_802CBB10;
    case 0x802CBB14u: goto label_802CBB14;
    case 0x802CBB18u: goto label_802CBB18;
    case 0x802CBB1Cu: goto label_802CBB1C;
    case 0x802CBB20u: goto label_802CBB20;
    case 0x802CBB24u: goto label_802CBB24;
    case 0x802CBB28u: goto label_802CBB28;
    case 0x802CBB2Cu: goto label_802CBB2C;
    case 0x802CBB30u: goto label_802CBB30;
    case 0x802CBB34u: goto label_802CBB34;
    case 0x802CBB38u: goto label_802CBB38;
    case 0x802CBB3Cu: goto label_802CBB3C;
    case 0x802CBB40u: goto label_802CBB40;
    case 0x802CBB44u: goto label_802CBB44;
    case 0x802CBB48u: goto label_802CBB48;
    case 0x802CBB4Cu: goto label_802CBB4C;
    case 0x802CBB50u: goto label_802CBB50;
    case 0x802CBB54u: goto label_802CBB54;
    case 0x802CBB58u: goto label_802CBB58;
    case 0x802CBB5Cu: goto label_802CBB5C;
    case 0x802CBB60u: goto label_802CBB60;
    case 0x802CBB64u: goto label_802CBB64;
    case 0x802CBB68u: goto label_802CBB68;
    case 0x802CBB6Cu: goto label_802CBB6C;
    case 0x802CBB70u: goto label_802CBB70;
    case 0x802CBB74u: goto label_802CBB74;
    case 0x802CBB78u: goto label_802CBB78;
    case 0x802CBB7Cu: goto label_802CBB7C;
    case 0x802CBB80u: goto label_802CBB80;
    case 0x802CBB84u: goto label_802CBB84;
    case 0x802CBB88u: goto label_802CBB88;
    case 0x802CBB8Cu: goto label_802CBB8C;
    case 0x802CBB90u: goto label_802CBB90;
    case 0x802CBB94u: goto label_802CBB94;
    case 0x802CBB98u: goto label_802CBB98;
    case 0x802CBB9Cu: goto label_802CBB9C;
    case 0x802CBBA0u: goto label_802CBBA0;
    case 0x802CBBA4u: goto label_802CBBA4;
    case 0x802CBBA8u: goto label_802CBBA8;
    case 0x802CBBACu: goto label_802CBBAC;
    case 0x802CBBB0u: goto label_802CBBB0;
    case 0x802CBBB4u: goto label_802CBBB4;
    case 0x802CBBB8u: goto label_802CBBB8;
    case 0x802CBBBCu: goto label_802CBBBC;
    case 0x802CBBC0u: goto label_802CBBC0;
    case 0x802CBBC4u: goto label_802CBBC4;
    case 0x802CBBC8u: goto label_802CBBC8;
    case 0x802CBBCCu: goto label_802CBBCC;
    case 0x802CBBD0u: goto label_802CBBD0;
    case 0x802CBBD4u: goto label_802CBBD4;
    case 0x802CBBD8u: goto label_802CBBD8;
    case 0x802CBBDCu: goto label_802CBBDC;
    case 0x802CBBE0u: goto label_802CBBE0;
    case 0x802CBBE4u: goto label_802CBBE4;
    case 0x802CBBE8u: goto label_802CBBE8;
    case 0x802CBBECu: goto label_802CBBEC;
    case 0x802CBBF0u: goto label_802CBBF0;
    case 0x802CBBF4u: goto label_802CBBF4;
    case 0x802CBBF8u: goto label_802CBBF8;
    case 0x802CBBFCu: goto label_802CBBFC;
    case 0x802CBC00u: goto label_802CBC00;
    case 0x802CBC04u: goto label_802CBC04;
    case 0x802CBC08u: goto label_802CBC08;
    case 0x802CBC0Cu: goto label_802CBC0C;
    case 0x802CBC10u: goto label_802CBC10;
    case 0x802CBC14u: goto label_802CBC14;
    case 0x802CBC18u: goto label_802CBC18;
    case 0x802CBC1Cu: goto label_802CBC1C;
    case 0x802CBC20u: goto label_802CBC20;
    case 0x802CBC24u: goto label_802CBC24;
    case 0x802CBC28u: goto label_802CBC28;
    case 0x802CBC2Cu: goto label_802CBC2C;
    case 0x802CBC30u: goto label_802CBC30;
    case 0x802CBC34u: goto label_802CBC34;
    case 0x802CBC38u: goto label_802CBC38;
    case 0x802CBC3Cu: goto label_802CBC3C;
    case 0x802CBC40u: goto label_802CBC40;
    case 0x802CBC44u: goto label_802CBC44;
    case 0x802CBC48u: goto label_802CBC48;
    case 0x802CBC4Cu: goto label_802CBC4C;
    case 0x802CBC50u: goto label_802CBC50;
    case 0x802CBC54u: goto label_802CBC54;
    case 0x802CBC58u: goto label_802CBC58;
    case 0x802CBC5Cu: goto label_802CBC5C;
    case 0x802CBC60u: goto label_802CBC60;
    case 0x802CBC64u: goto label_802CBC64;
    case 0x802CBC68u: goto label_802CBC68;
    case 0x802CBC6Cu: goto label_802CBC6C;
    case 0x802CBC70u: goto label_802CBC70;
    case 0x802CBC74u: goto label_802CBC74;
    case 0x802CBC78u: goto label_802CBC78;
    case 0x802CBC7Cu: goto label_802CBC7C;
    case 0x802CBC80u: goto label_802CBC80;
    case 0x802CBC84u: goto label_802CBC84;
    case 0x802CBC88u: goto label_802CBC88;
    case 0x802CBC8Cu: goto label_802CBC8C;
    case 0x802CBC90u: goto label_802CBC90;
    case 0x802CBC94u: goto label_802CBC94;
    case 0x802CBC98u: goto label_802CBC98;
    case 0x802CBC9Cu: goto label_802CBC9C;
    case 0x802CBCA0u: goto label_802CBCA0;
    case 0x802CBCA4u: goto label_802CBCA4;
    case 0x802CBCA8u: goto label_802CBCA8;
    case 0x802CBCACu: goto label_802CBCAC;
    case 0x802CBCB0u: goto label_802CBCB0;
    case 0x802CBCB4u: goto label_802CBCB4;
    case 0x802CBCB8u: goto label_802CBCB8;
    case 0x802CBCBCu: goto label_802CBCBC;
    case 0x802CBCC0u: goto label_802CBCC0;
    case 0x802CBCC4u: goto label_802CBCC4;
    case 0x802CBCC8u: goto label_802CBCC8;
    case 0x802CBCCCu: goto label_802CBCCC;
    case 0x802CBCD0u: goto label_802CBCD0;
    case 0x802CBCD4u: goto label_802CBCD4;
    case 0x802CBCD8u: goto label_802CBCD8;
    case 0x802CBCDCu: goto label_802CBCDC;
    case 0x802CBCE0u: goto label_802CBCE0;
    case 0x802CBCE4u: goto label_802CBCE4;
    case 0x802CBCE8u: goto label_802CBCE8;
    case 0x802CBCECu: goto label_802CBCEC;
    case 0x802CBCF0u: goto label_802CBCF0;
    case 0x802CBCF4u: goto label_802CBCF4;
    case 0x802CBCF8u: goto label_802CBCF8;
    case 0x802CBCFCu: goto label_802CBCFC;
    case 0x802CBD00u: goto label_802CBD00;
    case 0x802CBD04u: goto label_802CBD04;
    case 0x802CBD08u: goto label_802CBD08;
    case 0x802CBD0Cu: goto label_802CBD0C;
    case 0x802CBD10u: goto label_802CBD10;
    case 0x802CBD14u: goto label_802CBD14;
    case 0x802CBD18u: goto label_802CBD18;
    case 0x802CBD1Cu: goto label_802CBD1C;
    case 0x802CBD20u: goto label_802CBD20;
    case 0x802CBD24u: goto label_802CBD24;
    case 0x802CBD28u: goto label_802CBD28;
    case 0x802CBD2Cu: goto label_802CBD2C;
    case 0x802CBD30u: goto label_802CBD30;
    case 0x802CBD34u: goto label_802CBD34;
    case 0x802CBD38u: goto label_802CBD38;
    case 0x802CBD3Cu: goto label_802CBD3C;
    case 0x802CBD40u: goto label_802CBD40;
    case 0x802CBD44u: goto label_802CBD44;
    case 0x802CBD48u: goto label_802CBD48;
    case 0x802CBD4Cu: goto label_802CBD4C;
    case 0x802CBD50u: goto label_802CBD50;
    case 0x802CBD54u: goto label_802CBD54;
    case 0x802CBD58u: goto label_802CBD58;
    case 0x802CBD5Cu: goto label_802CBD5C;
    case 0x802CBD60u: goto label_802CBD60;
    case 0x802CBD64u: goto label_802CBD64;
    case 0x802CBD68u: goto label_802CBD68;
    case 0x802CBD6Cu: goto label_802CBD6C;
    case 0x802CBD70u: goto label_802CBD70;
    case 0x802CBD74u: goto label_802CBD74;
    case 0x802CBD78u: goto label_802CBD78;
    case 0x802CBD7Cu: goto label_802CBD7C;
    case 0x802CBD80u: goto label_802CBD80;
    case 0x802CBD84u: goto label_802CBD84;
    case 0x802CBD88u: goto label_802CBD88;
    case 0x802CBD8Cu: goto label_802CBD8C;
    case 0x802CBD90u: goto label_802CBD90;
    case 0x802CBD94u: goto label_802CBD94;
    case 0x802CBD98u: goto label_802CBD98;
    case 0x802CBD9Cu: goto label_802CBD9C;
    case 0x802CBDA0u: goto label_802CBDA0;
    case 0x802CBDA4u: goto label_802CBDA4;
    case 0x802CBDA8u: goto label_802CBDA8;
    case 0x802CBDACu: goto label_802CBDAC;
    case 0x802CBDB0u: goto label_802CBDB0;
    case 0x802CBDB4u: goto label_802CBDB4;
    case 0x802CBDB8u: goto label_802CBDB8;
    case 0x802CBDBCu: goto label_802CBDBC;
    case 0x802CBDC0u: goto label_802CBDC0;
    case 0x802CBDC4u: goto label_802CBDC4;
    case 0x802CBDC8u: goto label_802CBDC8;
    case 0x802CBDCCu: goto label_802CBDCC;
    case 0x802CBDD0u: goto label_802CBDD0;
    case 0x802CBDD4u: goto label_802CBDD4;
    case 0x802CBDD8u: goto label_802CBDD8;
    case 0x802CBDDCu: goto label_802CBDDC;
    case 0x802CBDE0u: goto label_802CBDE0;
    case 0x802CBDE4u: goto label_802CBDE4;
    case 0x802CBDE8u: goto label_802CBDE8;
    case 0x802CBDECu: goto label_802CBDEC;
    case 0x802CBDF0u: goto label_802CBDF0;
    case 0x802CBDF4u: goto label_802CBDF4;
    case 0x802CBDF8u: goto label_802CBDF8;
    case 0x802CBDFCu: goto label_802CBDFC;
    case 0x802CBE00u: goto label_802CBE00;
    case 0x802CBE04u: goto label_802CBE04;
    case 0x802CBE08u: goto label_802CBE08;
    case 0x802CBE0Cu: goto label_802CBE0C;
    case 0x802CBE10u: goto label_802CBE10;
    case 0x802CBE14u: goto label_802CBE14;
    case 0x802CBE18u: goto label_802CBE18;
    case 0x802CBE1Cu: goto label_802CBE1C;
    case 0x802CBE20u: goto label_802CBE20;
    case 0x802CBE24u: goto label_802CBE24;
    case 0x802CBE28u: goto label_802CBE28;
    case 0x802CBE2Cu: goto label_802CBE2C;
    case 0x802CBE30u: goto label_802CBE30;
    case 0x802CBE34u: goto label_802CBE34;
    case 0x802CBE38u: goto label_802CBE38;
    case 0x802CBE3Cu: goto label_802CBE3C;
    case 0x802CBE40u: goto label_802CBE40;
    case 0x802CBE44u: goto label_802CBE44;
    case 0x802CBE48u: goto label_802CBE48;
    case 0x802CBE4Cu: goto label_802CBE4C;
    case 0x802CBE50u: goto label_802CBE50;
    case 0x802CBE54u: goto label_802CBE54;
    case 0x802CBE58u: goto label_802CBE58;
    case 0x802CBE5Cu: goto label_802CBE5C;
    case 0x802CBE60u: goto label_802CBE60;
    case 0x802CBE64u: goto label_802CBE64;
    case 0x802CBE68u: goto label_802CBE68;
    case 0x802CBE6Cu: goto label_802CBE6C;
    case 0x802CBE70u: goto label_802CBE70;
    case 0x802CBE74u: goto label_802CBE74;
    case 0x802CBE78u: goto label_802CBE78;
    case 0x802CBE7Cu: goto label_802CBE7C;
    case 0x802CBE80u: goto label_802CBE80;
    case 0x802CBE84u: goto label_802CBE84;
    case 0x802CBE88u: goto label_802CBE88;
    case 0x802CBE8Cu: goto label_802CBE8C;
    case 0x802CBE90u: goto label_802CBE90;
    case 0x802CBE94u: goto label_802CBE94;
    case 0x802CBE98u: goto label_802CBE98;
    case 0x802CBE9Cu: goto label_802CBE9C;
    case 0x802CBEA0u: goto label_802CBEA0;
    case 0x802CBEA4u: goto label_802CBEA4;
    case 0x802CBEA8u: goto label_802CBEA8;
    case 0x802CBEACu: goto label_802CBEAC;
    case 0x802CBEB0u: goto label_802CBEB0;
    case 0x802CBEB4u: goto label_802CBEB4;
    case 0x802CBEB8u: goto label_802CBEB8;
    case 0x802CBEBCu: goto label_802CBEBC;
    case 0x802CBEC0u: goto label_802CBEC0;
    case 0x802CBEC4u: goto label_802CBEC4;
    case 0x802CBEC8u: goto label_802CBEC8;
    case 0x802CBECCu: goto label_802CBECC;
    case 0x802CBED0u: goto label_802CBED0;
    case 0x802CBED4u: goto label_802CBED4;
    case 0x802CBED8u: goto label_802CBED8;
    case 0x802CBEDCu: goto label_802CBEDC;
    case 0x802CBEE0u: goto label_802CBEE0;
    case 0x802CBEE4u: goto label_802CBEE4;
    case 0x802CBEE8u: goto label_802CBEE8;
    case 0x802CBEECu: goto label_802CBEEC;
    case 0x802CBEF0u: goto label_802CBEF0;
    case 0x802CBEF4u: goto label_802CBEF4;
    case 0x802CBEF8u: goto label_802CBEF8;
    case 0x802CBEFCu: goto label_802CBEFC;
    case 0x802CBF00u: goto label_802CBF00;
    case 0x802CBF04u: goto label_802CBF04;
    case 0x802CBF08u: goto label_802CBF08;
    case 0x802CBF0Cu: goto label_802CBF0C;
    case 0x802CBF10u: goto label_802CBF10;
    case 0x802CBF14u: goto label_802CBF14;
    case 0x802CBF18u: goto label_802CBF18;
    case 0x802CBF1Cu: goto label_802CBF1C;
    case 0x802CBF20u: goto label_802CBF20;
    case 0x802CBF24u: goto label_802CBF24;
    case 0x802CBF28u: goto label_802CBF28;
    case 0x802CBF2Cu: goto label_802CBF2C;
    case 0x802CBF30u: goto label_802CBF30;
    case 0x802CBF34u: goto label_802CBF34;
    case 0x802CBF38u: goto label_802CBF38;
    case 0x802CBF3Cu: goto label_802CBF3C;
    case 0x802CBF40u: goto label_802CBF40;
    case 0x802CBF44u: goto label_802CBF44;
    case 0x802CBF48u: goto label_802CBF48;
    case 0x802CBF4Cu: goto label_802CBF4C;
    case 0x802CBF50u: goto label_802CBF50;
    case 0x802CBF54u: goto label_802CBF54;
    case 0x802CBF58u: goto label_802CBF58;
    case 0x802CBF5Cu: goto label_802CBF5C;
    case 0x802CBF60u: goto label_802CBF60;
    case 0x802CBF64u: goto label_802CBF64;
    case 0x802CBF68u: goto label_802CBF68;
    case 0x802CBF6Cu: goto label_802CBF6C;
    case 0x802CBF70u: goto label_802CBF70;
    case 0x802CBF74u: goto label_802CBF74;
    case 0x802CBF78u: goto label_802CBF78;
    case 0x802CBF7Cu: goto label_802CBF7C;
    case 0x802CBF80u: goto label_802CBF80;
    case 0x802CBF84u: goto label_802CBF84;
    case 0x802CBF88u: goto label_802CBF88;
    case 0x802CBF8Cu: goto label_802CBF8C;
    case 0x802CBF90u: goto label_802CBF90;
    case 0x802CBF94u: goto label_802CBF94;
    case 0x802CBF98u: goto label_802CBF98;
    case 0x802CBF9Cu: goto label_802CBF9C;
    case 0x802CBFA0u: goto label_802CBFA0;
    case 0x802CBFA4u: goto label_802CBFA4;
    case 0x802CBFA8u: goto label_802CBFA8;
    case 0x802CBFACu: goto label_802CBFAC;
    case 0x802CBFB0u: goto label_802CBFB0;
    case 0x802CBFB4u: goto label_802CBFB4;
    case 0x802CBFB8u: goto label_802CBFB8;
    case 0x802CBFBCu: goto label_802CBFBC;
    case 0x802CBFC0u: goto label_802CBFC0;
    case 0x802CBFC4u: goto label_802CBFC4;
    case 0x802CBFC8u: goto label_802CBFC8;
    case 0x802CBFCCu: goto label_802CBFCC;
    case 0x802CBFD0u: goto label_802CBFD0;
    case 0x802CBFD4u: goto label_802CBFD4;
    case 0x802CBFD8u: goto label_802CBFD8;
    case 0x802CBFDCu: goto label_802CBFDC;
    case 0x802CBFE0u: goto label_802CBFE0;
    case 0x802CBFE4u: goto label_802CBFE4;
    case 0x802CBFE8u: goto label_802CBFE8;
    case 0x802CBFECu: goto label_802CBFEC;
    case 0x802CBFF0u: goto label_802CBFF0;
    case 0x802CBFF4u: goto label_802CBFF4;
    case 0x802CBFF8u: goto label_802CBFF8;
    case 0x802CBFFCu: goto label_802CBFFC;
    case 0x802CC000u: goto label_802CC000;
    case 0x802CC004u: goto label_802CC004;
    case 0x802CC008u: goto label_802CC008;
    case 0x802CC00Cu: goto label_802CC00C;
    case 0x802CC010u: goto label_802CC010;
    case 0x802CC014u: goto label_802CC014;
    case 0x802CC018u: goto label_802CC018;
    case 0x802CC01Cu: goto label_802CC01C;
    case 0x802CC020u: goto label_802CC020;
    case 0x802CC024u: goto label_802CC024;
    case 0x802CC028u: goto label_802CC028;
    case 0x802CC02Cu: goto label_802CC02C;
    case 0x802CC030u: goto label_802CC030;
    case 0x802CC034u: goto label_802CC034;
    case 0x802CC038u: goto label_802CC038;
    case 0x802CC03Cu: goto label_802CC03C;
    case 0x802CC040u: goto label_802CC040;
    case 0x802CC044u: goto label_802CC044;
    case 0x802CC048u: goto label_802CC048;
    case 0x802CC04Cu: goto label_802CC04C;
    case 0x802CC050u: goto label_802CC050;
    case 0x802CC054u: goto label_802CC054;
    case 0x802CC058u: goto label_802CC058;
    case 0x802CC05Cu: goto label_802CC05C;
    case 0x802CC060u: goto label_802CC060;
    case 0x802CC064u: goto label_802CC064;
    case 0x802CC068u: goto label_802CC068;
    case 0x802CC06Cu: goto label_802CC06C;
    case 0x802CC070u: goto label_802CC070;
    case 0x802CC074u: goto label_802CC074;
    case 0x802CC078u: goto label_802CC078;
    case 0x802CC07Cu: goto label_802CC07C;
    case 0x802CC080u: goto label_802CC080;
    case 0x802CC084u: goto label_802CC084;
    case 0x802CC088u: goto label_802CC088;
    case 0x802CC08Cu: goto label_802CC08C;
    case 0x802CC090u: goto label_802CC090;
    case 0x802CC094u: goto label_802CC094;
    case 0x802CC098u: goto label_802CC098;
    case 0x802CC09Cu: goto label_802CC09C;
    case 0x802CC0A0u: goto label_802CC0A0;
    case 0x802CC0A4u: goto label_802CC0A4;
    case 0x802CC0A8u: goto label_802CC0A8;
    case 0x802CC0ACu: goto label_802CC0AC;
    case 0x802CC0B0u: goto label_802CC0B0;
    case 0x802CC0B4u: goto label_802CC0B4;
    case 0x802CC0B8u: goto label_802CC0B8;
    case 0x802CC0BCu: goto label_802CC0BC;
    case 0x802CC0C0u: goto label_802CC0C0;
    case 0x802CC0C4u: goto label_802CC0C4;
    case 0x802CC0C8u: goto label_802CC0C8;
    case 0x802CC0CCu: goto label_802CC0CC;
    case 0x802CC0D0u: goto label_802CC0D0;
    case 0x802CC0D4u: goto label_802CC0D4;
    case 0x802CC0D8u: goto label_802CC0D8;
    case 0x802CC0DCu: goto label_802CC0DC;
    case 0x802CC0E0u: goto label_802CC0E0;
    case 0x802CC0E4u: goto label_802CC0E4;
    case 0x802CC0E8u: goto label_802CC0E8;
    case 0x802CC0ECu: goto label_802CC0EC;
    case 0x802CC0F0u: goto label_802CC0F0;
    case 0x802CC0F4u: goto label_802CC0F4;
    case 0x802CC0F8u: goto label_802CC0F8;
    case 0x802CC0FCu: goto label_802CC0FC;
    case 0x802CC100u: goto label_802CC100;
    case 0x802CC104u: goto label_802CC104;
    case 0x802CC108u: goto label_802CC108;
    case 0x802CC10Cu: goto label_802CC10C;
    case 0x802CC110u: goto label_802CC110;
    case 0x802CC114u: goto label_802CC114;
    case 0x802CC118u: goto label_802CC118;
    case 0x802CC11Cu: goto label_802CC11C;
    case 0x802CC120u: goto label_802CC120;
    case 0x802CC124u: goto label_802CC124;
    case 0x802CC128u: goto label_802CC128;
    case 0x802CC12Cu: goto label_802CC12C;
    case 0x802CC130u: goto label_802CC130;
    case 0x802CC134u: goto label_802CC134;
    case 0x802CC138u: goto label_802CC138;
    case 0x802CC13Cu: goto label_802CC13C;
    case 0x802CC140u: goto label_802CC140;
    case 0x802CC144u: goto label_802CC144;
    case 0x802CC148u: goto label_802CC148;
    case 0x802CC14Cu: goto label_802CC14C;
    case 0x802CC150u: goto label_802CC150;
    case 0x802CC154u: goto label_802CC154;
    case 0x802CC158u: goto label_802CC158;
    case 0x802CC15Cu: goto label_802CC15C;
    case 0x802CC160u: goto label_802CC160;
    case 0x802CC164u: goto label_802CC164;
    case 0x802CC168u: goto label_802CC168;
    case 0x802CC16Cu: goto label_802CC16C;
    case 0x802CC170u: goto label_802CC170;
    case 0x802CC174u: goto label_802CC174;
    case 0x802CC178u: goto label_802CC178;
    case 0x802CC17Cu: goto label_802CC17C;
    case 0x802CC180u: goto label_802CC180;
    case 0x802CC184u: goto label_802CC184;
    case 0x802CC188u: goto label_802CC188;
    case 0x802CC18Cu: goto label_802CC18C;
    case 0x802CC190u: goto label_802CC190;
    case 0x802CC194u: goto label_802CC194;
    case 0x802CC198u: goto label_802CC198;
    case 0x802CC19Cu: goto label_802CC19C;
    case 0x802CC1A0u: goto label_802CC1A0;
    case 0x802CC1A4u: goto label_802CC1A4;
    case 0x802CC1A8u: goto label_802CC1A8;
    case 0x802CC1ACu: goto label_802CC1AC;
    case 0x802CC1B0u: goto label_802CC1B0;
    case 0x802CC1B4u: goto label_802CC1B4;
    case 0x802CC1B8u: goto label_802CC1B8;
    case 0x802CC1BCu: goto label_802CC1BC;
    case 0x802CC1C0u: goto label_802CC1C0;
    case 0x802CC1C4u: goto label_802CC1C4;
    case 0x802CC1C8u: goto label_802CC1C8;
    case 0x802CC1CCu: goto label_802CC1CC;
    case 0x802CC1D0u: goto label_802CC1D0;
    case 0x802CC1D4u: goto label_802CC1D4;
    case 0x802CC1D8u: goto label_802CC1D8;
    case 0x802CC1DCu: goto label_802CC1DC;
    case 0x802CC1E0u: goto label_802CC1E0;
    case 0x802CC1E4u: goto label_802CC1E4;
    case 0x802CC1E8u: goto label_802CC1E8;
    case 0x802CC1ECu: goto label_802CC1EC;
    case 0x802CC1F0u: goto label_802CC1F0;
    case 0x802CC1F4u: goto label_802CC1F4;
    case 0x802CC1F8u: goto label_802CC1F8;
    case 0x802CC1FCu: goto label_802CC1FC;
    case 0x802CC200u: goto label_802CC200;
    case 0x802CC204u: goto label_802CC204;
    case 0x802CC208u: goto label_802CC208;
    case 0x802CC20Cu: goto label_802CC20C;
    case 0x802CC210u: goto label_802CC210;
    case 0x802CC214u: goto label_802CC214;
    case 0x802CC218u: goto label_802CC218;
    case 0x802CC21Cu: goto label_802CC21C;
    case 0x802CC220u: goto label_802CC220;
    case 0x802CC224u: goto label_802CC224;
    case 0x802CC228u: goto label_802CC228;
    case 0x802CC22Cu: goto label_802CC22C;
    case 0x802CC230u: goto label_802CC230;
    case 0x802CC234u: goto label_802CC234;
    case 0x802CC238u: goto label_802CC238;
    case 0x802CC23Cu: goto label_802CC23C;
    case 0x802CC240u: goto label_802CC240;
    case 0x802CC244u: goto label_802CC244;
    case 0x802CC248u: goto label_802CC248;
    case 0x802CC24Cu: goto label_802CC24C;
    case 0x802CC250u: goto label_802CC250;
    case 0x802CC254u: goto label_802CC254;
    case 0x802CC258u: goto label_802CC258;
    case 0x802CC25Cu: goto label_802CC25C;
    case 0x802CC260u: goto label_802CC260;
    case 0x802CC264u: goto label_802CC264;
    case 0x802CC268u: goto label_802CC268;
    case 0x802CC26Cu: goto label_802CC26C;
    case 0x802CC270u: goto label_802CC270;
    case 0x802CC274u: goto label_802CC274;
    case 0x802CC278u: goto label_802CC278;
    case 0x802CC27Cu: goto label_802CC27C;
    case 0x802CC280u: goto label_802CC280;
    case 0x802CC284u: goto label_802CC284;
    case 0x802CC288u: goto label_802CC288;
    case 0x802CC28Cu: goto label_802CC28C;
    case 0x802CC290u: goto label_802CC290;
    case 0x802CC294u: goto label_802CC294;
    case 0x802CC298u: goto label_802CC298;
    case 0x802CC29Cu: goto label_802CC29C;
    case 0x802CC2A0u: goto label_802CC2A0;
    case 0x802CC2A4u: goto label_802CC2A4;
    case 0x802CC2A8u: goto label_802CC2A8;
    case 0x802CC2ACu: goto label_802CC2AC;
    case 0x802CC2B0u: goto label_802CC2B0;
    case 0x802CC2B4u: goto label_802CC2B4;
    case 0x802CC2B8u: goto label_802CC2B8;
    case 0x802CC2BCu: goto label_802CC2BC;
    case 0x802CC2C0u: goto label_802CC2C0;
    case 0x802CC2C4u: goto label_802CC2C4;
    case 0x802CC2C8u: goto label_802CC2C8;
    case 0x802CC2CCu: goto label_802CC2CC;
    case 0x802CC2D0u: goto label_802CC2D0;
    case 0x802CC2D4u: goto label_802CC2D4;
    case 0x802CC2D8u: goto label_802CC2D8;
    case 0x802CC2DCu: goto label_802CC2DC;
    case 0x802CC2E0u: goto label_802CC2E0;
    case 0x802CC2E4u: goto label_802CC2E4;
    case 0x802CC2E8u: goto label_802CC2E8;
    case 0x802CC2ECu: goto label_802CC2EC;
    case 0x802CC2F0u: goto label_802CC2F0;
    case 0x802CC2F4u: goto label_802CC2F4;
    case 0x802CC2F8u: goto label_802CC2F8;
    case 0x802CC2FCu: goto label_802CC2FC;
    case 0x802CC300u: goto label_802CC300;
    case 0x802CC304u: goto label_802CC304;
    case 0x802CC308u: goto label_802CC308;
    case 0x802CC30Cu: goto label_802CC30C;
    case 0x802CC310u: goto label_802CC310;
    case 0x802CC314u: goto label_802CC314;
    case 0x802CC318u: goto label_802CC318;
    case 0x802CC31Cu: goto label_802CC31C;
    case 0x802CC320u: goto label_802CC320;
    case 0x802CC324u: goto label_802CC324;
    case 0x802CC328u: goto label_802CC328;
    case 0x802CC32Cu: goto label_802CC32C;
    case 0x802CC330u: goto label_802CC330;
    case 0x802CC334u: goto label_802CC334;
    case 0x802CC338u: goto label_802CC338;
    case 0x802CC33Cu: goto label_802CC33C;
    case 0x802CC340u: goto label_802CC340;
    case 0x802CC344u: goto label_802CC344;
    case 0x802CC348u: goto label_802CC348;
    case 0x802CC34Cu: goto label_802CC34C;
    case 0x802CC350u: goto label_802CC350;
    case 0x802CC354u: goto label_802CC354;
    case 0x802CC358u: goto label_802CC358;
    case 0x802CC35Cu: goto label_802CC35C;
    case 0x802CC360u: goto label_802CC360;
    case 0x802CC364u: goto label_802CC364;
    case 0x802CC368u: goto label_802CC368;
    case 0x802CC36Cu: goto label_802CC36C;
    case 0x802CC370u: goto label_802CC370;
    case 0x802CC374u: goto label_802CC374;
    case 0x802CC378u: goto label_802CC378;
    case 0x802CC37Cu: goto label_802CC37C;
    case 0x802CC380u: goto label_802CC380;
    case 0x802CC384u: goto label_802CC384;
    case 0x802CC388u: goto label_802CC388;
    case 0x802CC38Cu: goto label_802CC38C;
    case 0x802CC390u: goto label_802CC390;
    case 0x802CC394u: goto label_802CC394;
    case 0x802CC398u: goto label_802CC398;
    case 0x802CC39Cu: goto label_802CC39C;
    case 0x802CC3A0u: goto label_802CC3A0;
    case 0x802CC3A4u: goto label_802CC3A4;
    case 0x802CC3A8u: goto label_802CC3A8;
    case 0x802CC3ACu: goto label_802CC3AC;
    case 0x802CC3B0u: goto label_802CC3B0;
    case 0x802CC3B4u: goto label_802CC3B4;
    case 0x802CC3B8u: goto label_802CC3B8;
    case 0x802CC3BCu: goto label_802CC3BC;
    case 0x802CC3C0u: goto label_802CC3C0;
    case 0x802CC3C4u: goto label_802CC3C4;
    case 0x802CC3C8u: goto label_802CC3C8;
    case 0x802CC3CCu: goto label_802CC3CC;
    case 0x802CC3D0u: goto label_802CC3D0;
    case 0x802CC3D4u: goto label_802CC3D4;
    case 0x802CC3D8u: goto label_802CC3D8;
    case 0x802CC3DCu: goto label_802CC3DC;
    case 0x802CC3E0u: goto label_802CC3E0;
    case 0x802CC3E4u: goto label_802CC3E4;
    case 0x802CC3E8u: goto label_802CC3E8;
    case 0x802CC3ECu: goto label_802CC3EC;
    case 0x802CC3F0u: goto label_802CC3F0;
    case 0x802CC3F4u: goto label_802CC3F4;
    case 0x802CC3F8u: goto label_802CC3F8;
    case 0x802CC3FCu: goto label_802CC3FC;
    case 0x802CC400u: goto label_802CC400;
    case 0x802CC404u: goto label_802CC404;
    case 0x802CC408u: goto label_802CC408;
    case 0x802CC40Cu: goto label_802CC40C;
    case 0x802CC410u: goto label_802CC410;
    case 0x802CC414u: goto label_802CC414;
    case 0x802CC418u: goto label_802CC418;
    case 0x802CC41Cu: goto label_802CC41C;
    case 0x802CC420u: goto label_802CC420;
    case 0x802CC424u: goto label_802CC424;
    case 0x802CC428u: goto label_802CC428;
    case 0x802CC42Cu: goto label_802CC42C;
    case 0x802CC430u: goto label_802CC430;
    case 0x802CC434u: goto label_802CC434;
    case 0x802CC438u: goto label_802CC438;
    case 0x802CC43Cu: goto label_802CC43C;
    case 0x802CC440u: goto label_802CC440;
    case 0x802CC444u: goto label_802CC444;
    case 0x802CC448u: goto label_802CC448;
    case 0x802CC44Cu: goto label_802CC44C;
    case 0x802CC450u: goto label_802CC450;
    case 0x802CC454u: goto label_802CC454;
    case 0x802CC458u: goto label_802CC458;
    case 0x802CC45Cu: goto label_802CC45C;
    case 0x802CC460u: goto label_802CC460;
    case 0x802CC464u: goto label_802CC464;
    case 0x802CC468u: goto label_802CC468;
    case 0x802CC46Cu: goto label_802CC46C;
    case 0x802CC470u: goto label_802CC470;
    case 0x802CC474u: goto label_802CC474;
    case 0x802CC478u: goto label_802CC478;
    case 0x802CC47Cu: goto label_802CC47C;
    case 0x802CC480u: goto label_802CC480;
    case 0x802CC484u: goto label_802CC484;
    case 0x802CC488u: goto label_802CC488;
    case 0x802CC48Cu: goto label_802CC48C;
    case 0x802CC490u: goto label_802CC490;
    case 0x802CC494u: goto label_802CC494;
    case 0x802CC498u: goto label_802CC498;
    case 0x802CC49Cu: goto label_802CC49C;
    case 0x802CC4A0u: goto label_802CC4A0;
    case 0x802CC4A4u: goto label_802CC4A4;
    case 0x802CC4A8u: goto label_802CC4A8;
    case 0x802CC4ACu: goto label_802CC4AC;
    case 0x802CC4B0u: goto label_802CC4B0;
    case 0x802CC4B4u: goto label_802CC4B4;
    case 0x802CC4B8u: goto label_802CC4B8;
    case 0x802CC4BCu: goto label_802CC4BC;
    case 0x802CC4C0u: goto label_802CC4C0;
    case 0x802CC4C4u: goto label_802CC4C4;
    case 0x802CC4C8u: goto label_802CC4C8;
    case 0x802CC4CCu: goto label_802CC4CC;
    case 0x802CC4D0u: goto label_802CC4D0;
    case 0x802CC4D4u: goto label_802CC4D4;
    case 0x802CC4D8u: goto label_802CC4D8;
    case 0x802CC4DCu: goto label_802CC4DC;
    case 0x802CC4E0u: goto label_802CC4E0;
    case 0x802CC4E4u: goto label_802CC4E4;
    case 0x802CC4E8u: goto label_802CC4E8;
    case 0x802CC4ECu: goto label_802CC4EC;
    case 0x802CC4F0u: goto label_802CC4F0;
    case 0x802CC4F4u: goto label_802CC4F4;
    case 0x802CC4F8u: goto label_802CC4F8;
    case 0x802CC4FCu: goto label_802CC4FC;
    case 0x802CC500u: goto label_802CC500;
    case 0x802CC504u: goto label_802CC504;
    case 0x802CC508u: goto label_802CC508;
    case 0x802CC50Cu: goto label_802CC50C;
    case 0x802CC510u: goto label_802CC510;
    case 0x802CC514u: goto label_802CC514;
    case 0x802CC518u: goto label_802CC518;
    case 0x802CC51Cu: goto label_802CC51C;
    case 0x802CC520u: goto label_802CC520;
    case 0x802CC524u: goto label_802CC524;
    case 0x802CC528u: goto label_802CC528;
    case 0x802CC52Cu: goto label_802CC52C;
    case 0x802CC530u: goto label_802CC530;
    case 0x802CC534u: goto label_802CC534;
    case 0x802CC538u: goto label_802CC538;
    case 0x802CC53Cu: goto label_802CC53C;
    case 0x802CC540u: goto label_802CC540;
    case 0x802CC544u: goto label_802CC544;
    case 0x802CC548u: goto label_802CC548;
    case 0x802CC54Cu: goto label_802CC54C;
    case 0x802CC550u: goto label_802CC550;
    case 0x802CC554u: goto label_802CC554;
    case 0x802CC558u: goto label_802CC558;
    case 0x802CC55Cu: goto label_802CC55C;
    case 0x802CC560u: goto label_802CC560;
    case 0x802CC564u: goto label_802CC564;
    case 0x802CC568u: goto label_802CC568;
    case 0x802CC56Cu: goto label_802CC56C;
    case 0x802CC570u: goto label_802CC570;
    case 0x802CC574u: goto label_802CC574;
    case 0x802CC578u: goto label_802CC578;
    case 0x802CC57Cu: goto label_802CC57C;
    case 0x802CC580u: goto label_802CC580;
    case 0x802CC584u: goto label_802CC584;
    case 0x802CC588u: goto label_802CC588;
    case 0x802CC58Cu: goto label_802CC58C;
    case 0x802CC590u: goto label_802CC590;
    case 0x802CC594u: goto label_802CC594;
    case 0x802CC598u: goto label_802CC598;
    case 0x802CC59Cu: goto label_802CC59C;
    case 0x802CC5A0u: goto label_802CC5A0;
    case 0x802CC5A4u: goto label_802CC5A4;
    case 0x802CC5A8u: goto label_802CC5A8;
    case 0x802CC5ACu: goto label_802CC5AC;
    case 0x802CC5B0u: goto label_802CC5B0;
    case 0x802CC5B4u: goto label_802CC5B4;
    case 0x802CC5B8u: goto label_802CC5B8;
    case 0x802CC5BCu: goto label_802CC5BC;
    case 0x802CC5C0u: goto label_802CC5C0;
    case 0x802CC5C4u: goto label_802CC5C4;
    case 0x802CC5C8u: goto label_802CC5C8;
    case 0x802CC5CCu: goto label_802CC5CC;
    case 0x802CC5D0u: goto label_802CC5D0;
    case 0x802CC5D4u: goto label_802CC5D4;
    case 0x802CC5D8u: goto label_802CC5D8;
    case 0x802CC5DCu: goto label_802CC5DC;
    case 0x802CC5E0u: goto label_802CC5E0;
    case 0x802CC5E4u: goto label_802CC5E4;
    case 0x802CC5E8u: goto label_802CC5E8;
    case 0x802CC5ECu: goto label_802CC5EC;
    case 0x802CC5F0u: goto label_802CC5F0;
    case 0x802CC5F4u: goto label_802CC5F4;
    case 0x802CC5F8u: goto label_802CC5F8;
    case 0x802CC5FCu: goto label_802CC5FC;
    case 0x802CC600u: goto label_802CC600;
    case 0x802CC604u: goto label_802CC604;
    case 0x802CC608u: goto label_802CC608;
    case 0x802CC60Cu: goto label_802CC60C;
    case 0x802CC610u: goto label_802CC610;
    case 0x802CC614u: goto label_802CC614;
    case 0x802CC618u: goto label_802CC618;
    case 0x802CC61Cu: goto label_802CC61C;
    case 0x802CC620u: goto label_802CC620;
    case 0x802CC624u: goto label_802CC624;
    case 0x802CC628u: goto label_802CC628;
    case 0x802CC62Cu: goto label_802CC62C;
    case 0x802CC630u: goto label_802CC630;
    case 0x802CC634u: goto label_802CC634;
    case 0x802CC638u: goto label_802CC638;
    case 0x802CC63Cu: goto label_802CC63C;
    case 0x802CC640u: goto label_802CC640;
    case 0x802CC644u: goto label_802CC644;
    case 0x802CC648u: goto label_802CC648;
    case 0x802CC64Cu: goto label_802CC64C;
    case 0x802CC650u: goto label_802CC650;
    case 0x802CC654u: goto label_802CC654;
    case 0x802CC658u: goto label_802CC658;
    case 0x802CC65Cu: goto label_802CC65C;
    case 0x802CC660u: goto label_802CC660;
    case 0x802CC664u: goto label_802CC664;
    case 0x802CC668u: goto label_802CC668;
    case 0x802CC66Cu: goto label_802CC66C;
    case 0x802CC670u: goto label_802CC670;
    case 0x802CC674u: goto label_802CC674;
    case 0x802CC678u: goto label_802CC678;
    case 0x802CC67Cu: goto label_802CC67C;
    case 0x802CC680u: goto label_802CC680;
    case 0x802CC684u: goto label_802CC684;
    case 0x802CC688u: goto label_802CC688;
    case 0x802CC68Cu: goto label_802CC68C;
    case 0x802CC690u: goto label_802CC690;
    case 0x802CC694u: goto label_802CC694;
    case 0x802CC698u: goto label_802CC698;
    case 0x802CC69Cu: goto label_802CC69C;
    case 0x802CC6A0u: goto label_802CC6A0;
    case 0x802CC6A4u: goto label_802CC6A4;
    case 0x802CC6A8u: goto label_802CC6A8;
    case 0x802CC6ACu: goto label_802CC6AC;
    case 0x802CC6B0u: goto label_802CC6B0;
    case 0x802CC6B4u: goto label_802CC6B4;
    case 0x802CC6B8u: goto label_802CC6B8;
    case 0x802CC6BCu: goto label_802CC6BC;
    case 0x802CC6C0u: goto label_802CC6C0;
    case 0x802CC6C4u: goto label_802CC6C4;
    case 0x802CC6C8u: goto label_802CC6C8;
    case 0x802CC6CCu: goto label_802CC6CC;
    case 0x802CC6D0u: goto label_802CC6D0;
    case 0x802CC6D4u: goto label_802CC6D4;
    case 0x802CC6D8u: goto label_802CC6D8;
    case 0x802CC6DCu: goto label_802CC6DC;
    case 0x802CC6E0u: goto label_802CC6E0;
    case 0x802CC6E4u: goto label_802CC6E4;
    case 0x802CC6E8u: goto label_802CC6E8;
    case 0x802CC6ECu: goto label_802CC6EC;
    case 0x802CC6F0u: goto label_802CC6F0;
    case 0x802CC6F4u: goto label_802CC6F4;
    case 0x802CC6F8u: goto label_802CC6F8;
    case 0x802CC6FCu: goto label_802CC6FC;
    case 0x802CC700u: goto label_802CC700;
    case 0x802CC704u: goto label_802CC704;
    case 0x802CC708u: goto label_802CC708;
    case 0x802CC70Cu: goto label_802CC70C;
    case 0x802CC710u: goto label_802CC710;
    case 0x802CC714u: goto label_802CC714;
    case 0x802CC718u: goto label_802CC718;
    case 0x802CC71Cu: goto label_802CC71C;
    case 0x802CC720u: goto label_802CC720;
    case 0x802CC724u: goto label_802CC724;
    case 0x802CC728u: goto label_802CC728;
    case 0x802CC72Cu: goto label_802CC72C;
    case 0x802CC730u: goto label_802CC730;
    case 0x802CC734u: goto label_802CC734;
    case 0x802CC738u: goto label_802CC738;
    case 0x802CC73Cu: goto label_802CC73C;
    case 0x802CC740u: goto label_802CC740;
    case 0x802CC744u: goto label_802CC744;
    case 0x802CC748u: goto label_802CC748;
    case 0x802CC74Cu: goto label_802CC74C;
    case 0x802CC750u: goto label_802CC750;
    case 0x802CC754u: goto label_802CC754;
    case 0x802CC758u: goto label_802CC758;
    case 0x802CC75Cu: goto label_802CC75C;
    case 0x802CC760u: goto label_802CC760;
    case 0x802CC764u: goto label_802CC764;
    case 0x802CC768u: goto label_802CC768;
    case 0x802CC76Cu: goto label_802CC76C;
    case 0x802CC770u: goto label_802CC770;
    case 0x802CC774u: goto label_802CC774;
    case 0x802CC778u: goto label_802CC778;
    case 0x802CC77Cu: goto label_802CC77C;
    case 0x802CC780u: goto label_802CC780;
    case 0x802CC784u: goto label_802CC784;
    case 0x802CC788u: goto label_802CC788;
    case 0x802CC78Cu: goto label_802CC78C;
    case 0x802CC790u: goto label_802CC790;
    case 0x802CC794u: goto label_802CC794;
    case 0x802CC798u: goto label_802CC798;
    case 0x802CC79Cu: goto label_802CC79C;
    case 0x802CC7A0u: goto label_802CC7A0;
    case 0x802CC7A4u: goto label_802CC7A4;
    case 0x802CC7A8u: goto label_802CC7A8;
    case 0x802CC7ACu: goto label_802CC7AC;
    case 0x802CC7B0u: goto label_802CC7B0;
    case 0x802CC7B4u: goto label_802CC7B4;
    case 0x802CC7B8u: goto label_802CC7B8;
    case 0x802CC7BCu: goto label_802CC7BC;
    case 0x802CC7C0u: goto label_802CC7C0;
    case 0x802CC7C4u: goto label_802CC7C4;
    case 0x802CC7C8u: goto label_802CC7C8;
    case 0x802CC7CCu: goto label_802CC7CC;
    case 0x802CC7D0u: goto label_802CC7D0;
    case 0x802CC7D4u: goto label_802CC7D4;
    case 0x802CC7D8u: goto label_802CC7D8;
    case 0x802CC7DCu: goto label_802CC7DC;
    case 0x802CC7E0u: goto label_802CC7E0;
    case 0x802CC7E4u: goto label_802CC7E4;
    case 0x802CC7E8u: goto label_802CC7E8;
    case 0x802CC7ECu: goto label_802CC7EC;
    case 0x802CC7F0u: goto label_802CC7F0;
    case 0x802CC7F4u: goto label_802CC7F4;
    case 0x802CC7F8u: goto label_802CC7F8;
    case 0x802CC7FCu: goto label_802CC7FC;
    case 0x802CC800u: goto label_802CC800;
    case 0x802CC804u: goto label_802CC804;
    case 0x802CC808u: goto label_802CC808;
    case 0x802CC80Cu: goto label_802CC80C;
    case 0x802CC810u: goto label_802CC810;
    case 0x802CC814u: goto label_802CC814;
    case 0x802CC818u: goto label_802CC818;
    case 0x802CC81Cu: goto label_802CC81C;
    case 0x802CC820u: goto label_802CC820;
    case 0x802CC824u: goto label_802CC824;
    case 0x802CC828u: goto label_802CC828;
    case 0x802CC82Cu: goto label_802CC82C;
    case 0x802CC830u: goto label_802CC830;
    case 0x802CC834u: goto label_802CC834;
    case 0x802CC838u: goto label_802CC838;
    case 0x802CC83Cu: goto label_802CC83C;
    case 0x802CC840u: goto label_802CC840;
    case 0x802CC844u: goto label_802CC844;
    case 0x802CC848u: goto label_802CC848;
    case 0x802CC84Cu: goto label_802CC84C;
    case 0x802CC850u: goto label_802CC850;
    case 0x802CC854u: goto label_802CC854;
    case 0x802CC858u: goto label_802CC858;
    case 0x802CC85Cu: goto label_802CC85C;
    case 0x802CC860u: goto label_802CC860;
    case 0x802CC864u: goto label_802CC864;
    case 0x802CC868u: goto label_802CC868;
    case 0x802CC86Cu: goto label_802CC86C;
    case 0x802CC870u: goto label_802CC870;
    case 0x802CC874u: goto label_802CC874;
    case 0x802CC878u: goto label_802CC878;
    case 0x802CC87Cu: goto label_802CC87C;
    case 0x802CC880u: goto label_802CC880;
    case 0x802CC884u: goto label_802CC884;
    case 0x802CC888u: goto label_802CC888;
    case 0x802CC88Cu: goto label_802CC88C;
    case 0x802CC890u: goto label_802CC890;
    case 0x802CC894u: goto label_802CC894;
    case 0x802CC898u: goto label_802CC898;
    case 0x802CC89Cu: goto label_802CC89C;
    case 0x802CC8A0u: goto label_802CC8A0;
    case 0x802CC8A4u: goto label_802CC8A4;
    case 0x802CC8A8u: goto label_802CC8A8;
    case 0x802CC8ACu: goto label_802CC8AC;
    case 0x802CC8B0u: goto label_802CC8B0;
    case 0x802CC8B4u: goto label_802CC8B4;
    case 0x802CC8B8u: goto label_802CC8B8;
    case 0x802CC8BCu: goto label_802CC8BC;
    case 0x802CC8C0u: goto label_802CC8C0;
    case 0x802CC8C4u: goto label_802CC8C4;
    case 0x802CC8C8u: goto label_802CC8C8;
    case 0x802CC8CCu: goto label_802CC8CC;
    case 0x802CC8D0u: goto label_802CC8D0;
    case 0x802CC8D4u: goto label_802CC8D4;
    case 0x802CC8D8u: goto label_802CC8D8;
    case 0x802CC8DCu: goto label_802CC8DC;
    case 0x802CC8E0u: goto label_802CC8E0;
    case 0x802CC8E4u: goto label_802CC8E4;
    case 0x802CC8E8u: goto label_802CC8E8;
    case 0x802CC8ECu: goto label_802CC8EC;
    case 0x802CC8F0u: goto label_802CC8F0;
    case 0x802CC8F4u: goto label_802CC8F4;
    case 0x802CC8F8u: goto label_802CC8F8;
    case 0x802CC8FCu: goto label_802CC8FC;
    case 0x802CC900u: goto label_802CC900;
    case 0x802CC904u: goto label_802CC904;
    case 0x802CC908u: goto label_802CC908;
    case 0x802CC90Cu: goto label_802CC90C;
    case 0x802CC910u: goto label_802CC910;
    case 0x802CC914u: goto label_802CC914;
    case 0x802CC918u: goto label_802CC918;
    case 0x802CC91Cu: goto label_802CC91C;
    case 0x802CC920u: goto label_802CC920;
    case 0x802CC924u: goto label_802CC924;
    case 0x802CC928u: goto label_802CC928;
    case 0x802CC92Cu: goto label_802CC92C;
    case 0x802CC930u: goto label_802CC930;
    case 0x802CC934u: goto label_802CC934;
    case 0x802CC938u: goto label_802CC938;
    case 0x802CC93Cu: goto label_802CC93C;
    case 0x802CC940u: goto label_802CC940;
    case 0x802CC944u: goto label_802CC944;
    case 0x802CC948u: goto label_802CC948;
    case 0x802CC94Cu: goto label_802CC94C;
    case 0x802CC950u: goto label_802CC950;
    case 0x802CC954u: goto label_802CC954;
    case 0x802CC958u: goto label_802CC958;
    case 0x802CC95Cu: goto label_802CC95C;
    case 0x802CC960u: goto label_802CC960;
    case 0x802CC964u: goto label_802CC964;
    case 0x802CC968u: goto label_802CC968;
    case 0x802CC96Cu: goto label_802CC96C;
    case 0x802CC970u: goto label_802CC970;
    case 0x802CC974u: goto label_802CC974;
    case 0x802CC978u: goto label_802CC978;
    case 0x802CC97Cu: goto label_802CC97C;
    case 0x802CC980u: goto label_802CC980;
    case 0x802CC984u: goto label_802CC984;
    case 0x802CC988u: goto label_802CC988;
    case 0x802CC98Cu: goto label_802CC98C;
    case 0x802CC990u: goto label_802CC990;
    case 0x802CC994u: goto label_802CC994;
    case 0x802CC998u: goto label_802CC998;
    case 0x802CC99Cu: goto label_802CC99C;
    case 0x802CC9A0u: goto label_802CC9A0;
    case 0x802CC9A4u: goto label_802CC9A4;
    case 0x802CC9A8u: goto label_802CC9A8;
    case 0x802CC9ACu: goto label_802CC9AC;
    case 0x802CC9B0u: goto label_802CC9B0;
    case 0x802CC9B4u: goto label_802CC9B4;
    case 0x802CC9B8u: goto label_802CC9B8;
    case 0x802CC9BCu: goto label_802CC9BC;
    case 0x802CC9C0u: goto label_802CC9C0;
    case 0x802CC9C4u: goto label_802CC9C4;
    case 0x802CC9C8u: goto label_802CC9C8;
    case 0x802CC9CCu: goto label_802CC9CC;
    case 0x802CC9D0u: goto label_802CC9D0;
    case 0x802CC9D4u: goto label_802CC9D4;
    case 0x802CC9D8u: goto label_802CC9D8;
    case 0x802CC9DCu: goto label_802CC9DC;
    case 0x802CC9E0u: goto label_802CC9E0;
    case 0x802CC9E4u: goto label_802CC9E4;
    case 0x802CC9E8u: goto label_802CC9E8;
    case 0x802CC9ECu: goto label_802CC9EC;
    case 0x802CC9F0u: goto label_802CC9F0;
    case 0x802CC9F4u: goto label_802CC9F4;
    case 0x802CC9F8u: goto label_802CC9F8;
    case 0x802CC9FCu: goto label_802CC9FC;
    case 0x802CCA00u: goto label_802CCA00;
    case 0x802CCA04u: goto label_802CCA04;
    case 0x802CCA08u: goto label_802CCA08;
    case 0x802CCA0Cu: goto label_802CCA0C;
    case 0x802CCA10u: goto label_802CCA10;
    case 0x802CCA14u: goto label_802CCA14;
    case 0x802CCA18u: goto label_802CCA18;
    case 0x802CCA1Cu: goto label_802CCA1C;
    case 0x802CCA20u: goto label_802CCA20;
    case 0x802CCA24u: goto label_802CCA24;
    case 0x802CCA28u: goto label_802CCA28;
    case 0x802CCA2Cu: goto label_802CCA2C;
    case 0x802CCA30u: goto label_802CCA30;
    case 0x802CCA34u: goto label_802CCA34;
    case 0x802CCA38u: goto label_802CCA38;
    case 0x802CCA3Cu: goto label_802CCA3C;
    case 0x802CCA40u: goto label_802CCA40;
    case 0x802CCA44u: goto label_802CCA44;
    case 0x802CCA48u: goto label_802CCA48;
    case 0x802CCA4Cu: goto label_802CCA4C;
    case 0x802CCA50u: goto label_802CCA50;
    case 0x802CCA54u: goto label_802CCA54;
    case 0x802CCA58u: goto label_802CCA58;
    case 0x802CCA5Cu: goto label_802CCA5C;
    case 0x802CCA60u: goto label_802CCA60;
    case 0x802CCA64u: goto label_802CCA64;
    case 0x802CCA68u: goto label_802CCA68;
    case 0x802CCA6Cu: goto label_802CCA6C;
    case 0x802CCA70u: goto label_802CCA70;
    case 0x802CCA74u: goto label_802CCA74;
    case 0x802CCA78u: goto label_802CCA78;
    case 0x802CCA7Cu: goto label_802CCA7C;
    case 0x802CCA80u: goto label_802CCA80;
    case 0x802CCA84u: goto label_802CCA84;
    case 0x802CCA88u: goto label_802CCA88;
    case 0x802CCA8Cu: goto label_802CCA8C;
    case 0x802CCA90u: goto label_802CCA90;
    case 0x802CCA94u: goto label_802CCA94;
    case 0x802CCA98u: goto label_802CCA98;
    case 0x802CCA9Cu: goto label_802CCA9C;
    case 0x802CCAA0u: goto label_802CCAA0;
    case 0x802CCAA4u: goto label_802CCAA4;
    case 0x802CCAA8u: goto label_802CCAA8;
    case 0x802CCAACu: goto label_802CCAAC;
    case 0x802CCAB0u: goto label_802CCAB0;
    case 0x802CCAB4u: goto label_802CCAB4;
    case 0x802CCAB8u: goto label_802CCAB8;
    case 0x802CCABCu: goto label_802CCABC;
    case 0x802CCAC0u: goto label_802CCAC0;
    case 0x802CCAC4u: goto label_802CCAC4;
    case 0x802CCAC8u: goto label_802CCAC8;
    case 0x802CCACCu: goto label_802CCACC;
    case 0x802CCAD0u: goto label_802CCAD0;
    case 0x802CCAD4u: goto label_802CCAD4;
    case 0x802CCAD8u: goto label_802CCAD8;
    case 0x802CCADCu: goto label_802CCADC;
    case 0x802CCAE0u: goto label_802CCAE0;
    case 0x802CCAE4u: goto label_802CCAE4;
    case 0x802CCAE8u: goto label_802CCAE8;
    case 0x802CCAECu: goto label_802CCAEC;
    case 0x802CCAF0u: goto label_802CCAF0;
    case 0x802CCAF4u: goto label_802CCAF4;
    case 0x802CCAF8u: goto label_802CCAF8;
    case 0x802CCAFCu: goto label_802CCAFC;
    case 0x802CCB00u: goto label_802CCB00;
    case 0x802CCB04u: goto label_802CCB04;
    case 0x802CCB08u: goto label_802CCB08;
    case 0x802CCB0Cu: goto label_802CCB0C;
    case 0x802CCB10u: goto label_802CCB10;
    case 0x802CCB14u: goto label_802CCB14;
    case 0x802CCB18u: goto label_802CCB18;
    case 0x802CCB1Cu: goto label_802CCB1C;
    case 0x802CCB20u: goto label_802CCB20;
    case 0x802CCB24u: goto label_802CCB24;
    case 0x802CCB28u: goto label_802CCB28;
    case 0x802CCB2Cu: goto label_802CCB2C;
    case 0x802CCB30u: goto label_802CCB30;
    case 0x802CCB34u: goto label_802CCB34;
    case 0x802CCB38u: goto label_802CCB38;
    case 0x802CCB3Cu: goto label_802CCB3C;
    case 0x802CCB40u: goto label_802CCB40;
    case 0x802CCB44u: goto label_802CCB44;
    case 0x802CCB48u: goto label_802CCB48;
    case 0x802CCB4Cu: goto label_802CCB4C;
    case 0x802CCB50u: goto label_802CCB50;
    case 0x802CCB54u: goto label_802CCB54;
    case 0x802CCB58u: goto label_802CCB58;
    case 0x802CCB5Cu: goto label_802CCB5C;
    case 0x802CCB60u: goto label_802CCB60;
    case 0x802CCB64u: goto label_802CCB64;
    case 0x802CCB68u: goto label_802CCB68;
    case 0x802CCB6Cu: goto label_802CCB6C;
    case 0x802CCB70u: goto label_802CCB70;
    case 0x802CCB74u: goto label_802CCB74;
    case 0x802CCB78u: goto label_802CCB78;
    case 0x802CCB7Cu: goto label_802CCB7C;
    case 0x802CCB80u: goto label_802CCB80;
    case 0x802CCB84u: goto label_802CCB84;
    case 0x802CCB88u: goto label_802CCB88;
    case 0x802CCB8Cu: goto label_802CCB8C;
    case 0x802CCB90u: goto label_802CCB90;
    case 0x802CCB94u: goto label_802CCB94;
    case 0x802CCB98u: goto label_802CCB98;
    case 0x802CCB9Cu: goto label_802CCB9C;
    case 0x802CCBA0u: goto label_802CCBA0;
    case 0x802CCBA4u: goto label_802CCBA4;
    case 0x802CCBA8u: goto label_802CCBA8;
    case 0x802CCBACu: goto label_802CCBAC;
    case 0x802CCBB0u: goto label_802CCBB0;
    case 0x802CCBB4u: goto label_802CCBB4;
    case 0x802CCBB8u: goto label_802CCBB8;
    case 0x802CCBBCu: goto label_802CCBBC;
    case 0x802CCBC0u: goto label_802CCBC0;
    case 0x802CCBC4u: goto label_802CCBC4;
    case 0x802CCBC8u: goto label_802CCBC8;
    case 0x802CCBCCu: goto label_802CCBCC;
    case 0x802CCBD0u: goto label_802CCBD0;
    case 0x802CCBD4u: goto label_802CCBD4;
    case 0x802CCBD8u: goto label_802CCBD8;
    case 0x802CCBDCu: goto label_802CCBDC;
    case 0x802CCBE0u: goto label_802CCBE0;
    case 0x802CCBE4u: goto label_802CCBE4;
    case 0x802CCBE8u: goto label_802CCBE8;
    case 0x802CCBECu: goto label_802CCBEC;
    case 0x802CCBF0u: goto label_802CCBF0;
    case 0x802CCBF4u: goto label_802CCBF4;
    case 0x802CCBF8u: goto label_802CCBF8;
    case 0x802CCBFCu: goto label_802CCBFC;
    case 0x802CCC00u: goto label_802CCC00;
    case 0x802CCC04u: goto label_802CCC04;
    case 0x802CCC08u: goto label_802CCC08;
    case 0x802CCC0Cu: goto label_802CCC0C;
    case 0x802CCC10u: goto label_802CCC10;
    case 0x802CCC14u: goto label_802CCC14;
    case 0x802CCC18u: goto label_802CCC18;
    case 0x802CCC1Cu: goto label_802CCC1C;
    case 0x802CCC20u: goto label_802CCC20;
    case 0x802CCC24u: goto label_802CCC24;
    case 0x802CCC28u: goto label_802CCC28;
    case 0x802CCC2Cu: goto label_802CCC2C;
    case 0x802CCC30u: goto label_802CCC30;
    case 0x802CCC34u: goto label_802CCC34;
    case 0x802CCC38u: goto label_802CCC38;
    case 0x802CCC3Cu: goto label_802CCC3C;
    case 0x802CCC40u: goto label_802CCC40;
    case 0x802CCC44u: goto label_802CCC44;
    case 0x802CCC48u: goto label_802CCC48;
    case 0x802CCC4Cu: goto label_802CCC4C;
    case 0x802CCC50u: goto label_802CCC50;
    case 0x802CCC54u: goto label_802CCC54;
    case 0x802CCC58u: goto label_802CCC58;
    case 0x802CCC5Cu: goto label_802CCC5C;
    case 0x802CCC60u: goto label_802CCC60;
    case 0x802CCC64u: goto label_802CCC64;
    case 0x802CCC68u: goto label_802CCC68;
    case 0x802CCC6Cu: goto label_802CCC6C;
    case 0x802CCC70u: goto label_802CCC70;
    case 0x802CCC74u: goto label_802CCC74;
    case 0x802CCC78u: goto label_802CCC78;
    case 0x802CCC7Cu: goto label_802CCC7C;
    case 0x802CCC80u: goto label_802CCC80;
    case 0x802CCC84u: goto label_802CCC84;
    case 0x802CCC88u: goto label_802CCC88;
    case 0x802CCC8Cu: goto label_802CCC8C;
    case 0x802CCC90u: goto label_802CCC90;
    case 0x802CCC94u: goto label_802CCC94;
    case 0x802CCC98u: goto label_802CCC98;
    case 0x802CCC9Cu: goto label_802CCC9C;
    case 0x802CCCA0u: goto label_802CCCA0;
    case 0x802CCCA4u: goto label_802CCCA4;
    case 0x802CCCA8u: goto label_802CCCA8;
    case 0x802CCCACu: goto label_802CCCAC;
    case 0x802CCCB0u: goto label_802CCCB0;
    case 0x802CCCB4u: goto label_802CCCB4;
    case 0x802CCCB8u: goto label_802CCCB8;
    case 0x802CCCBCu: goto label_802CCCBC;
    case 0x802CCCC0u: goto label_802CCCC0;
    case 0x802CCCC4u: goto label_802CCCC4;
    case 0x802CCCC8u: goto label_802CCCC8;
    case 0x802CCCCCu: goto label_802CCCCC;
    case 0x802CCCD0u: goto label_802CCCD0;
    case 0x802CCCD4u: goto label_802CCCD4;
    case 0x802CCCD8u: goto label_802CCCD8;
    case 0x802CCCDCu: goto label_802CCCDC;
    case 0x802CCCE0u: goto label_802CCCE0;
    case 0x802CCCE4u: goto label_802CCCE4;
    case 0x802CCCE8u: goto label_802CCCE8;
    case 0x802CCCECu: goto label_802CCCEC;
    case 0x802CCCF0u: goto label_802CCCF0;
    case 0x802CCCF4u: goto label_802CCCF4;
    case 0x802CCCF8u: goto label_802CCCF8;
    case 0x802CCCFCu: goto label_802CCCFC;
    case 0x802CCD00u: goto label_802CCD00;
    case 0x802CCD04u: goto label_802CCD04;
    case 0x802CCD08u: goto label_802CCD08;
    case 0x802CCD0Cu: goto label_802CCD0C;
    case 0x802CCD10u: goto label_802CCD10;
    case 0x802CCD14u: goto label_802CCD14;
    case 0x802CCD18u: goto label_802CCD18;
    case 0x802CCD1Cu: goto label_802CCD1C;
    case 0x802CCD20u: goto label_802CCD20;
    case 0x802CCD24u: goto label_802CCD24;
    case 0x802CCD28u: goto label_802CCD28;
    case 0x802CCD2Cu: goto label_802CCD2C;
    case 0x802CCD30u: goto label_802CCD30;
    case 0x802CCD34u: goto label_802CCD34;
    case 0x802CCD38u: goto label_802CCD38;
    case 0x802CCD3Cu: goto label_802CCD3C;
    case 0x802CCD40u: goto label_802CCD40;
    case 0x802CCD44u: goto label_802CCD44;
    case 0x802CCD48u: goto label_802CCD48;
    case 0x802CCD4Cu: goto label_802CCD4C;
    case 0x802CCD50u: goto label_802CCD50;
    case 0x802CCD54u: goto label_802CCD54;
    case 0x802CCD58u: goto label_802CCD58;
    case 0x802CCD5Cu: goto label_802CCD5C;
    case 0x802CCD60u: goto label_802CCD60;
    case 0x802CCD64u: goto label_802CCD64;
    case 0x802CCD68u: goto label_802CCD68;
    case 0x802CCD6Cu: goto label_802CCD6C;
    case 0x802CCD70u: goto label_802CCD70;
    case 0x802CCD74u: goto label_802CCD74;
    case 0x802CCD78u: goto label_802CCD78;
    case 0x802CCD7Cu: goto label_802CCD7C;
    case 0x802CCD80u: goto label_802CCD80;
    case 0x802CCD84u: goto label_802CCD84;
    case 0x802CCD88u: goto label_802CCD88;
    case 0x802CCD8Cu: goto label_802CCD8C;
    case 0x802CCD90u: goto label_802CCD90;
    case 0x802CCD94u: goto label_802CCD94;
    case 0x802CCD98u: goto label_802CCD98;
    case 0x802CCD9Cu: goto label_802CCD9C;
    case 0x802CCDA0u: goto label_802CCDA0;
    case 0x802CCDA4u: goto label_802CCDA4;
    case 0x802CCDA8u: goto label_802CCDA8;
    case 0x802CCDACu: goto label_802CCDAC;
    case 0x802CCDB0u: goto label_802CCDB0;
    case 0x802CCDB4u: goto label_802CCDB4;
    case 0x802CCDB8u: goto label_802CCDB8;
    case 0x802CCDBCu: goto label_802CCDBC;
    case 0x802CCDC0u: goto label_802CCDC0;
    case 0x802CCDC4u: goto label_802CCDC4;
    case 0x802CCDC8u: goto label_802CCDC8;
    case 0x802CCDCCu: goto label_802CCDCC;
    case 0x802CCDD0u: goto label_802CCDD0;
    case 0x802CCDD4u: goto label_802CCDD4;
    case 0x802CCDD8u: goto label_802CCDD8;
    case 0x802CCDDCu: goto label_802CCDDC;
    case 0x802CCDE0u: goto label_802CCDE0;
    case 0x802CCDE4u: goto label_802CCDE4;
    case 0x802CCDE8u: goto label_802CCDE8;
    case 0x802CCDECu: goto label_802CCDEC;
    case 0x802CCDF0u: goto label_802CCDF0;
    case 0x802CCDF4u: goto label_802CCDF4;
    case 0x802CCDF8u: goto label_802CCDF8;
    case 0x802CCDFCu: goto label_802CCDFC;
    case 0x802CCE00u: goto label_802CCE00;
    case 0x802CCE04u: goto label_802CCE04;
    case 0x802CCE08u: goto label_802CCE08;
    case 0x802CCE0Cu: goto label_802CCE0C;
    case 0x802CCE10u: goto label_802CCE10;
    case 0x802CCE14u: goto label_802CCE14;
    case 0x802CCE18u: goto label_802CCE18;
    case 0x802CCE1Cu: goto label_802CCE1C;
    case 0x802CCE20u: goto label_802CCE20;
    case 0x802CCE24u: goto label_802CCE24;
    case 0x802CCE28u: goto label_802CCE28;
    case 0x802CCE2Cu: goto label_802CCE2C;
    case 0x802CCE30u: goto label_802CCE30;
    case 0x802CCE34u: goto label_802CCE34;
    case 0x802CCE38u: goto label_802CCE38;
    case 0x802CCE3Cu: goto label_802CCE3C;
    case 0x802CCE40u: goto label_802CCE40;
    case 0x802CCE44u: goto label_802CCE44;
    case 0x802CCE48u: goto label_802CCE48;
    case 0x802CCE4Cu: goto label_802CCE4C;
    case 0x802CCE50u: goto label_802CCE50;
    case 0x802CCE54u: goto label_802CCE54;
    case 0x802CCE58u: goto label_802CCE58;
    case 0x802CCE5Cu: goto label_802CCE5C;
    case 0x802CCE60u: goto label_802CCE60;
    case 0x802CCE64u: goto label_802CCE64;
    case 0x802CCE68u: goto label_802CCE68;
    case 0x802CCE6Cu: goto label_802CCE6C;
    case 0x802CCE70u: goto label_802CCE70;
    case 0x802CCE74u: goto label_802CCE74;
    case 0x802CCE78u: goto label_802CCE78;
    case 0x802CCE7Cu: goto label_802CCE7C;
    case 0x802CCE80u: goto label_802CCE80;
    case 0x802CCE84u: goto label_802CCE84;
    case 0x802CCE88u: goto label_802CCE88;
    case 0x802CCE8Cu: goto label_802CCE8C;
    case 0x802CCE90u: goto label_802CCE90;
    case 0x802CCE94u: goto label_802CCE94;
    case 0x802CCE98u: goto label_802CCE98;
    case 0x802CCE9Cu: goto label_802CCE9C;
    case 0x802CCEA0u: goto label_802CCEA0;
    case 0x802CCEA4u: goto label_802CCEA4;
    case 0x802CCEA8u: goto label_802CCEA8;
    case 0x802CCEACu: goto label_802CCEAC;
    case 0x802CCEB0u: goto label_802CCEB0;
    case 0x802CCEB4u: goto label_802CCEB4;
    case 0x802CCEB8u: goto label_802CCEB8;
    case 0x802CCEBCu: goto label_802CCEBC;
    case 0x802CCEC0u: goto label_802CCEC0;
    case 0x802CCEC4u: goto label_802CCEC4;
    case 0x802CCEC8u: goto label_802CCEC8;
    case 0x802CCECCu: goto label_802CCECC;
    case 0x802CCED0u: goto label_802CCED0;
    case 0x802CCED4u: goto label_802CCED4;
    case 0x802CCED8u: goto label_802CCED8;
    case 0x802CCEDCu: goto label_802CCEDC;
    case 0x802CCEE0u: goto label_802CCEE0;
    case 0x802CCEE4u: goto label_802CCEE4;
    case 0x802CCEE8u: goto label_802CCEE8;
    case 0x802CCEECu: goto label_802CCEEC;
    case 0x802CCEF0u: goto label_802CCEF0;
    case 0x802CCEF4u: goto label_802CCEF4;
    case 0x802CCEF8u: goto label_802CCEF8;
    case 0x802CCEFCu: goto label_802CCEFC;
    case 0x802CCF00u: goto label_802CCF00;
    case 0x802CCF04u: goto label_802CCF04;
    case 0x802CCF08u: goto label_802CCF08;
    case 0x802CCF0Cu: goto label_802CCF0C;
    case 0x802CCF10u: goto label_802CCF10;
    case 0x802CCF14u: goto label_802CCF14;
    case 0x802CCF18u: goto label_802CCF18;
    case 0x802CCF1Cu: goto label_802CCF1C;
    case 0x802CCF20u: goto label_802CCF20;
    case 0x802CCF24u: goto label_802CCF24;
    case 0x802CCF28u: goto label_802CCF28;
    case 0x802CCF2Cu: goto label_802CCF2C;
    case 0x802CCF30u: goto label_802CCF30;
    case 0x802CCF34u: goto label_802CCF34;
    case 0x802CCF38u: goto label_802CCF38;
    case 0x802CCF3Cu: goto label_802CCF3C;
    case 0x802CCF40u: goto label_802CCF40;
    case 0x802CCF44u: goto label_802CCF44;
    case 0x802CCF48u: goto label_802CCF48;
    case 0x802CCF4Cu: goto label_802CCF4C;
    case 0x802CCF50u: goto label_802CCF50;
    case 0x802CCF54u: goto label_802CCF54;
    case 0x802CCF58u: goto label_802CCF58;
    case 0x802CCF5Cu: goto label_802CCF5C;
    case 0x802CCF60u: goto label_802CCF60;
    case 0x802CCF64u: goto label_802CCF64;
    case 0x802CCF68u: goto label_802CCF68;
    case 0x802CCF6Cu: goto label_802CCF6C;
    case 0x802CCF70u: goto label_802CCF70;
    case 0x802CCF74u: goto label_802CCF74;
    case 0x802CCF78u: goto label_802CCF78;
    case 0x802CCF7Cu: goto label_802CCF7C;
    case 0x802CCF80u: goto label_802CCF80;
    case 0x802CCF84u: goto label_802CCF84;
    case 0x802CCF88u: goto label_802CCF88;
    case 0x802CCF8Cu: goto label_802CCF8C;
    case 0x802CCF90u: goto label_802CCF90;
    case 0x802CCF94u: goto label_802CCF94;
    case 0x802CCF98u: goto label_802CCF98;
    case 0x802CCF9Cu: goto label_802CCF9C;
    case 0x802CCFA0u: goto label_802CCFA0;
    case 0x802CCFA4u: goto label_802CCFA4;
    case 0x802CCFA8u: goto label_802CCFA8;
    case 0x802CCFACu: goto label_802CCFAC;
    case 0x802CCFB0u: goto label_802CCFB0;
    case 0x802CCFB4u: goto label_802CCFB4;
    case 0x802CCFB8u: goto label_802CCFB8;
    case 0x802CCFBCu: goto label_802CCFBC;
    case 0x802CCFC0u: goto label_802CCFC0;
    case 0x802CCFC4u: goto label_802CCFC4;
    case 0x802CCFC8u: goto label_802CCFC8;
    case 0x802CCFCCu: goto label_802CCFCC;
    case 0x802CCFD0u: goto label_802CCFD0;
    case 0x802CCFD4u: goto label_802CCFD4;
    case 0x802CCFD8u: goto label_802CCFD8;
    case 0x802CCFDCu: goto label_802CCFDC;
    case 0x802CCFE0u: goto label_802CCFE0;
    case 0x802CCFE4u: goto label_802CCFE4;
    case 0x802CCFE8u: goto label_802CCFE8;
    case 0x802CCFECu: goto label_802CCFEC;
    case 0x802CCFF0u: goto label_802CCFF0;
    case 0x802CCFF4u: goto label_802CCFF4;
    case 0x802CCFF8u: goto label_802CCFF8;
    case 0x802CCFFCu: goto label_802CCFFC;
    case 0x802CD000u: goto label_802CD000;
    case 0x802CD004u: goto label_802CD004;
    case 0x802CD008u: goto label_802CD008;
    case 0x802CD00Cu: goto label_802CD00C;
    case 0x802CD010u: goto label_802CD010;
    case 0x802CD014u: goto label_802CD014;
    case 0x802CD018u: goto label_802CD018;
    case 0x802CD01Cu: goto label_802CD01C;
    case 0x802CD020u: goto label_802CD020;
    case 0x802CD024u: goto label_802CD024;
    case 0x802CD028u: goto label_802CD028;
    case 0x802CD02Cu: goto label_802CD02C;
    case 0x802CD030u: goto label_802CD030;
    case 0x802CD034u: goto label_802CD034;
    case 0x802CD038u: goto label_802CD038;
    case 0x802CD03Cu: goto label_802CD03C;
    case 0x802CD040u: goto label_802CD040;
    case 0x802CD044u: goto label_802CD044;
    case 0x802CD048u: goto label_802CD048;
    case 0x802CD04Cu: goto label_802CD04C;
    case 0x802CD050u: goto label_802CD050;
    case 0x802CD054u: goto label_802CD054;
    case 0x802CD058u: goto label_802CD058;
    case 0x802CD05Cu: goto label_802CD05C;
    case 0x802CD060u: goto label_802CD060;
    case 0x802CD064u: goto label_802CD064;
    case 0x802CD068u: goto label_802CD068;
    case 0x802CD06Cu: goto label_802CD06C;
    case 0x802CD070u: goto label_802CD070;
    case 0x802CD074u: goto label_802CD074;
    case 0x802CD078u: goto label_802CD078;
    case 0x802CD07Cu: goto label_802CD07C;
    case 0x802CD080u: goto label_802CD080;
    case 0x802CD084u: goto label_802CD084;
    case 0x802CD088u: goto label_802CD088;
    case 0x802CD08Cu: goto label_802CD08C;
    case 0x802CD090u: goto label_802CD090;
    case 0x802CD094u: goto label_802CD094;
    case 0x802CD098u: goto label_802CD098;
    case 0x802CD09Cu: goto label_802CD09C;
    case 0x802CD0A0u: goto label_802CD0A0;
    case 0x802CD0A4u: goto label_802CD0A4;
    case 0x802CD0A8u: goto label_802CD0A8;
    case 0x802CD0ACu: goto label_802CD0AC;
    case 0x802CD0B0u: goto label_802CD0B0;
    case 0x802CD0B4u: goto label_802CD0B4;
    case 0x802CD0B8u: goto label_802CD0B8;
    case 0x802CD0BCu: goto label_802CD0BC;
    case 0x802CD0C0u: goto label_802CD0C0;
    case 0x802CD0C4u: goto label_802CD0C4;
    case 0x802CD0C8u: goto label_802CD0C8;
    case 0x802CD0CCu: goto label_802CD0CC;
    case 0x802CD0D0u: goto label_802CD0D0;
    case 0x802CD0D4u: goto label_802CD0D4;
    case 0x802CD0D8u: goto label_802CD0D8;
    case 0x802CD0DCu: goto label_802CD0DC;
    case 0x802CD0E0u: goto label_802CD0E0;
    case 0x802CD0E4u: goto label_802CD0E4;
    case 0x802CD0E8u: goto label_802CD0E8;
    case 0x802CD0ECu: goto label_802CD0EC;
    case 0x802CD0F0u: goto label_802CD0F0;
    case 0x802CD0F4u: goto label_802CD0F4;
    case 0x802CD0F8u: goto label_802CD0F8;
    case 0x802CD0FCu: goto label_802CD0FC;
    case 0x802CD100u: goto label_802CD100;
    case 0x802CD104u: goto label_802CD104;
    case 0x802CD108u: goto label_802CD108;
    case 0x802CD10Cu: goto label_802CD10C;
    case 0x802CD110u: goto label_802CD110;
    case 0x802CD114u: goto label_802CD114;
    case 0x802CD118u: goto label_802CD118;
    case 0x802CD11Cu: goto label_802CD11C;
    case 0x802CD120u: goto label_802CD120;
    case 0x802CD124u: goto label_802CD124;
    case 0x802CD128u: goto label_802CD128;
    case 0x802CD12Cu: goto label_802CD12C;
    case 0x802CD130u: goto label_802CD130;
    case 0x802CD134u: goto label_802CD134;
    case 0x802CD138u: goto label_802CD138;
    case 0x802CD13Cu: goto label_802CD13C;
    case 0x802CD140u: goto label_802CD140;
    case 0x802CD144u: goto label_802CD144;
    case 0x802CD148u: goto label_802CD148;
    case 0x802CD14Cu: goto label_802CD14C;
    case 0x802CD150u: goto label_802CD150;
    case 0x802CD154u: goto label_802CD154;
    case 0x802CD158u: goto label_802CD158;
    case 0x802CD15Cu: goto label_802CD15C;
    case 0x802CD160u: goto label_802CD160;
    case 0x802CD164u: goto label_802CD164;
    case 0x802CD168u: goto label_802CD168;
    case 0x802CD16Cu: goto label_802CD16C;
    case 0x802CD170u: goto label_802CD170;
    case 0x802CD174u: goto label_802CD174;
    case 0x802CD178u: goto label_802CD178;
    case 0x802CD17Cu: goto label_802CD17C;
    case 0x802CD180u: goto label_802CD180;
    case 0x802CD184u: goto label_802CD184;
    case 0x802CD188u: goto label_802CD188;
    case 0x802CD18Cu: goto label_802CD18C;
    case 0x802CD190u: goto label_802CD190;
    case 0x802CD194u: goto label_802CD194;
    case 0x802CD198u: goto label_802CD198;
    case 0x802CD19Cu: goto label_802CD19C;
    case 0x802CD1A0u: goto label_802CD1A0;
    case 0x802CD1A4u: goto label_802CD1A4;
    case 0x802CD1A8u: goto label_802CD1A8;
    case 0x802CD1ACu: goto label_802CD1AC;
    case 0x802CD1B0u: goto label_802CD1B0;
    case 0x802CD1B4u: goto label_802CD1B4;
    case 0x802CD1B8u: goto label_802CD1B8;
    case 0x802CD1BCu: goto label_802CD1BC;
    case 0x802CD1C0u: goto label_802CD1C0;
    case 0x802CD1C4u: goto label_802CD1C4;
    case 0x802CD1C8u: goto label_802CD1C8;
    case 0x802CD1CCu: goto label_802CD1CC;
    case 0x802CD1D0u: goto label_802CD1D0;
    case 0x802CD1D4u: goto label_802CD1D4;
    case 0x802CD1D8u: goto label_802CD1D8;
    case 0x802CD1DCu: goto label_802CD1DC;
    case 0x802CD1E0u: goto label_802CD1E0;
    case 0x802CD1E4u: goto label_802CD1E4;
    case 0x802CD1E8u: goto label_802CD1E8;
    case 0x802CD1ECu: goto label_802CD1EC;
    case 0x802CD1F0u: goto label_802CD1F0;
    case 0x802CD1F4u: goto label_802CD1F4;
    case 0x802CD1F8u: goto label_802CD1F8;
    case 0x802CD1FCu: goto label_802CD1FC;
    case 0x802CD200u: goto label_802CD200;
    case 0x802CD204u: goto label_802CD204;
    case 0x802CD208u: goto label_802CD208;
    case 0x802CD20Cu: goto label_802CD20C;
    case 0x802CD210u: goto label_802CD210;
    case 0x802CD214u: goto label_802CD214;
    case 0x802CD218u: goto label_802CD218;
    case 0x802CD21Cu: goto label_802CD21C;
    case 0x802CD220u: goto label_802CD220;
    case 0x802CD224u: goto label_802CD224;
    case 0x802CD228u: goto label_802CD228;
    case 0x802CD22Cu: goto label_802CD22C;
    case 0x802CD230u: goto label_802CD230;
    case 0x802CD234u: goto label_802CD234;
    case 0x802CD238u: goto label_802CD238;
    case 0x802CD23Cu: goto label_802CD23C;
    case 0x802CD240u: goto label_802CD240;
    case 0x802CD244u: goto label_802CD244;
    case 0x802CD248u: goto label_802CD248;
    case 0x802CD24Cu: goto label_802CD24C;
    case 0x802CD250u: goto label_802CD250;
    case 0x802CD254u: goto label_802CD254;
    case 0x802CD258u: goto label_802CD258;
    case 0x802CD25Cu: goto label_802CD25C;
    case 0x802CD260u: goto label_802CD260;
    case 0x802CD264u: goto label_802CD264;
    case 0x802CD268u: goto label_802CD268;
    case 0x802CD26Cu: goto label_802CD26C;
    case 0x802CD270u: goto label_802CD270;
    case 0x802CD274u: goto label_802CD274;
    case 0x802CD278u: goto label_802CD278;
    case 0x802CD27Cu: goto label_802CD27C;
    case 0x802CD280u: goto label_802CD280;
    case 0x802CD284u: goto label_802CD284;
    case 0x802CD288u: goto label_802CD288;
    case 0x802CD28Cu: goto label_802CD28C;
    case 0x802CD290u: goto label_802CD290;
    case 0x802CD294u: goto label_802CD294;
    case 0x802CD298u: goto label_802CD298;
    case 0x802CD29Cu: goto label_802CD29C;
    case 0x802CD2A0u: goto label_802CD2A0;
    case 0x802CD2A4u: goto label_802CD2A4;
    case 0x802CD2A8u: goto label_802CD2A8;
    case 0x802CD2ACu: goto label_802CD2AC;
    case 0x802CD2B0u: goto label_802CD2B0;
    case 0x802CD2B4u: goto label_802CD2B4;
    case 0x802CD2B8u: goto label_802CD2B8;
    case 0x802CD2BCu: goto label_802CD2BC;
    case 0x802CD2C0u: goto label_802CD2C0;
    case 0x802CD2C4u: goto label_802CD2C4;
    case 0x802CD2C8u: goto label_802CD2C8;
    case 0x802CD2CCu: goto label_802CD2CC;
    case 0x802CD2D0u: goto label_802CD2D0;
    case 0x802CD2D4u: goto label_802CD2D4;
    case 0x802CD2D8u: goto label_802CD2D8;
    case 0x802CD2DCu: goto label_802CD2DC;
    case 0x802CD2E0u: goto label_802CD2E0;
    case 0x802CD2E4u: goto label_802CD2E4;
    case 0x802CD2E8u: goto label_802CD2E8;
    case 0x802CD2ECu: goto label_802CD2EC;
    case 0x802CD2F0u: goto label_802CD2F0;
    case 0x802CD2F4u: goto label_802CD2F4;
    case 0x802CD2F8u: goto label_802CD2F8;
    case 0x802CD2FCu: goto label_802CD2FC;
    case 0x802CD300u: goto label_802CD300;
    case 0x802CD304u: goto label_802CD304;
    case 0x802CD308u: goto label_802CD308;
    case 0x802CD30Cu: goto label_802CD30C;
    case 0x802CD310u: goto label_802CD310;
    case 0x802CD314u: goto label_802CD314;
    case 0x802CD318u: goto label_802CD318;
    case 0x802CD31Cu: goto label_802CD31C;
    case 0x802CD320u: goto label_802CD320;
    case 0x802CD324u: goto label_802CD324;
    case 0x802CD328u: goto label_802CD328;
    case 0x802CD32Cu: goto label_802CD32C;
    case 0x802CD330u: goto label_802CD330;
    case 0x802CD334u: goto label_802CD334;
    case 0x802CD338u: goto label_802CD338;
    case 0x802CD33Cu: goto label_802CD33C;
    case 0x802CD340u: goto label_802CD340;
    case 0x802CD344u: goto label_802CD344;
    case 0x802CD348u: goto label_802CD348;
    case 0x802CD34Cu: goto label_802CD34C;
    case 0x802CD350u: goto label_802CD350;
    case 0x802CD354u: goto label_802CD354;
    case 0x802CD358u: goto label_802CD358;
    case 0x802CD35Cu: goto label_802CD35C;
    case 0x802CD360u: goto label_802CD360;
    case 0x802CD364u: goto label_802CD364;
    case 0x802CD368u: goto label_802CD368;
    case 0x802CD36Cu: goto label_802CD36C;
    case 0x802CD370u: goto label_802CD370;
    case 0x802CD374u: goto label_802CD374;
    case 0x802CD378u: goto label_802CD378;
    case 0x802CD37Cu: goto label_802CD37C;
    case 0x802CD380u: goto label_802CD380;
    case 0x802CD384u: goto label_802CD384;
    case 0x802CD388u: goto label_802CD388;
    case 0x802CD38Cu: goto label_802CD38C;
    case 0x802CD390u: goto label_802CD390;
    case 0x802CD394u: goto label_802CD394;
    case 0x802CD398u: goto label_802CD398;
    case 0x802CD39Cu: goto label_802CD39C;
    case 0x802CD3A0u: goto label_802CD3A0;
    case 0x802CD3A4u: goto label_802CD3A4;
    case 0x802CD3A8u: goto label_802CD3A8;
    case 0x802CD3ACu: goto label_802CD3AC;
    case 0x802CD3B0u: goto label_802CD3B0;
    case 0x802CD3B4u: goto label_802CD3B4;
    case 0x802CD3B8u: goto label_802CD3B8;
    case 0x802CD3BCu: goto label_802CD3BC;
    case 0x802CD3C0u: goto label_802CD3C0;
    case 0x802CD3C4u: goto label_802CD3C4;
    case 0x802CD3C8u: goto label_802CD3C8;
    case 0x802CD3CCu: goto label_802CD3CC;
    case 0x802CD3D0u: goto label_802CD3D0;
    case 0x802CD3D4u: goto label_802CD3D4;
    case 0x802CD3D8u: goto label_802CD3D8;
    case 0x802CD3DCu: goto label_802CD3DC;
    case 0x802CD3E0u: goto label_802CD3E0;
    case 0x802CD3E4u: goto label_802CD3E4;
    case 0x802CD3E8u: goto label_802CD3E8;
    case 0x802CD3ECu: goto label_802CD3EC;
    case 0x802CD3F0u: goto label_802CD3F0;
    case 0x802CD3F4u: goto label_802CD3F4;
    case 0x802CD3F8u: goto label_802CD3F8;
    case 0x802CD3FCu: goto label_802CD3FC;
    case 0x802CD400u: goto label_802CD400;
    case 0x802CD404u: goto label_802CD404;
    case 0x802CD408u: goto label_802CD408;
    case 0x802CD40Cu: goto label_802CD40C;
    case 0x802CD410u: goto label_802CD410;
    case 0x802CD414u: goto label_802CD414;
    case 0x802CD418u: goto label_802CD418;
    case 0x802CD41Cu: goto label_802CD41C;
    case 0x802CD420u: goto label_802CD420;
    case 0x802CD424u: goto label_802CD424;
    case 0x802CD428u: goto label_802CD428;
    case 0x802CD42Cu: goto label_802CD42C;
    case 0x802CD430u: goto label_802CD430;
    case 0x802CD434u: goto label_802CD434;
    case 0x802CD438u: goto label_802CD438;
    case 0x802CD43Cu: goto label_802CD43C;
    case 0x802CD440u: goto label_802CD440;
    case 0x802CD444u: goto label_802CD444;
    case 0x802CD448u: goto label_802CD448;
    case 0x802CD44Cu: goto label_802CD44C;
    case 0x802CD450u: goto label_802CD450;
    case 0x802CD454u: goto label_802CD454;
    case 0x802CD458u: goto label_802CD458;
    case 0x802CD45Cu: goto label_802CD45C;
    case 0x802CD460u: goto label_802CD460;
    case 0x802CD464u: goto label_802CD464;
    case 0x802CD468u: goto label_802CD468;
    case 0x802CD46Cu: goto label_802CD46C;
    case 0x802CD470u: goto label_802CD470;
    case 0x802CD474u: goto label_802CD474;
    case 0x802CD478u: goto label_802CD478;
    case 0x802CD47Cu: goto label_802CD47C;
    case 0x802CD480u: goto label_802CD480;
    case 0x802CD484u: goto label_802CD484;
    case 0x802CD488u: goto label_802CD488;
    case 0x802CD48Cu: goto label_802CD48C;
    case 0x802CD490u: goto label_802CD490;
    case 0x802CD494u: goto label_802CD494;
    case 0x802CD498u: goto label_802CD498;
    case 0x802CD49Cu: goto label_802CD49C;
    case 0x802CD4A0u: goto label_802CD4A0;
    case 0x802CD4A4u: goto label_802CD4A4;
    case 0x802CD4A8u: goto label_802CD4A8;
    case 0x802CD4ACu: goto label_802CD4AC;
    case 0x802CD4B0u: goto label_802CD4B0;
    case 0x802CD4B4u: goto label_802CD4B4;
    case 0x802CD4B8u: goto label_802CD4B8;
    case 0x802CD4BCu: goto label_802CD4BC;
    case 0x802CD4C0u: goto label_802CD4C0;
    case 0x802CD4C4u: goto label_802CD4C4;
    case 0x802CD4C8u: goto label_802CD4C8;
    case 0x802CD4CCu: goto label_802CD4CC;
    case 0x802CD4D0u: goto label_802CD4D0;
    case 0x802CD4D4u: goto label_802CD4D4;
    case 0x802CD4D8u: goto label_802CD4D8;
    case 0x802CD4DCu: goto label_802CD4DC;
    case 0x802CD4E0u: goto label_802CD4E0;
    case 0x802CD4E4u: goto label_802CD4E4;
    case 0x802CD4E8u: goto label_802CD4E8;
    case 0x802CD4ECu: goto label_802CD4EC;
    case 0x802CD4F0u: goto label_802CD4F0;
    case 0x802CD4F4u: goto label_802CD4F4;
    case 0x802CD4F8u: goto label_802CD4F8;
    case 0x802CD4FCu: goto label_802CD4FC;
    case 0x802CD500u: goto label_802CD500;
    case 0x802CD504u: goto label_802CD504;
    case 0x802CD508u: goto label_802CD508;
    case 0x802CD50Cu: goto label_802CD50C;
    case 0x802CD510u: goto label_802CD510;
    case 0x802CD514u: goto label_802CD514;
    case 0x802CD518u: goto label_802CD518;
    case 0x802CD51Cu: goto label_802CD51C;
    case 0x802CD520u: goto label_802CD520;
    case 0x802CD524u: goto label_802CD524;
    case 0x802CD528u: goto label_802CD528;
    case 0x802CD52Cu: goto label_802CD52C;
    case 0x802CD530u: goto label_802CD530;
    case 0x802CD534u: goto label_802CD534;
    case 0x802CD538u: goto label_802CD538;
    case 0x802CD53Cu: goto label_802CD53C;
    case 0x802CD540u: goto label_802CD540;
    case 0x802CD544u: goto label_802CD544;
    case 0x802CD548u: goto label_802CD548;
    case 0x802CD54Cu: goto label_802CD54C;
    case 0x802CD550u: goto label_802CD550;
    case 0x802CD554u: goto label_802CD554;
    case 0x802CD558u: goto label_802CD558;
    case 0x802CD55Cu: goto label_802CD55C;
    case 0x802CD560u: goto label_802CD560;
    case 0x802CD564u: goto label_802CD564;
    case 0x802CD568u: goto label_802CD568;
    case 0x802CD56Cu: goto label_802CD56C;
    case 0x802CD570u: goto label_802CD570;
    case 0x802CD574u: goto label_802CD574;
    case 0x802CD578u: goto label_802CD578;
    case 0x802CD57Cu: goto label_802CD57C;
    case 0x802CD580u: goto label_802CD580;
    case 0x802CD584u: goto label_802CD584;
    case 0x802CD588u: goto label_802CD588;
    case 0x802CD58Cu: goto label_802CD58C;
    case 0x802CD590u: goto label_802CD590;
    case 0x802CD594u: goto label_802CD594;
    case 0x802CD598u: goto label_802CD598;
    case 0x802CD59Cu: goto label_802CD59C;
    case 0x802CD5A0u: goto label_802CD5A0;
    case 0x802CD5A4u: goto label_802CD5A4;
    case 0x802CD5A8u: goto label_802CD5A8;
    case 0x802CD5ACu: goto label_802CD5AC;
    case 0x802CD5B0u: goto label_802CD5B0;
    case 0x802CD5B4u: goto label_802CD5B4;
    case 0x802CD5B8u: goto label_802CD5B8;
    case 0x802CD5BCu: goto label_802CD5BC;
    case 0x802CD5C0u: goto label_802CD5C0;
    case 0x802CD5C4u: goto label_802CD5C4;
    case 0x802CD5C8u: goto label_802CD5C8;
    case 0x802CD5CCu: goto label_802CD5CC;
    case 0x802CD5D0u: goto label_802CD5D0;
    case 0x802CD5D4u: goto label_802CD5D4;
    case 0x802CD5D8u: goto label_802CD5D8;
    case 0x802CD5DCu: goto label_802CD5DC;
    case 0x802CD5E0u: goto label_802CD5E0;
    case 0x802CD5E4u: goto label_802CD5E4;
    case 0x802CD5E8u: goto label_802CD5E8;
    case 0x802CD5ECu: goto label_802CD5EC;
    case 0x802CD5F0u: goto label_802CD5F0;
    case 0x802CD5F4u: goto label_802CD5F4;
    case 0x802CD5F8u: goto label_802CD5F8;
    case 0x802CD5FCu: goto label_802CD5FC;
    case 0x802CD600u: goto label_802CD600;
    case 0x802CD604u: goto label_802CD604;
    case 0x802CD608u: goto label_802CD608;
    case 0x802CD60Cu: goto label_802CD60C;
    case 0x802CD610u: goto label_802CD610;
    case 0x802CD614u: goto label_802CD614;
    case 0x802CD618u: goto label_802CD618;
    case 0x802CD61Cu: goto label_802CD61C;
    case 0x802CD620u: goto label_802CD620;
    case 0x802CD624u: goto label_802CD624;
    case 0x802CD628u: goto label_802CD628;
    case 0x802CD62Cu: goto label_802CD62C;
    case 0x802CD630u: goto label_802CD630;
    case 0x802CD634u: goto label_802CD634;
    case 0x802CD638u: goto label_802CD638;
    case 0x802CD63Cu: goto label_802CD63C;
    case 0x802CD640u: goto label_802CD640;
    case 0x802CD644u: goto label_802CD644;
    case 0x802CD648u: goto label_802CD648;
    case 0x802CD64Cu: goto label_802CD64C;
    case 0x802CD650u: goto label_802CD650;
    case 0x802CD654u: goto label_802CD654;
    case 0x802CD658u: goto label_802CD658;
    case 0x802CD65Cu: goto label_802CD65C;
    case 0x802CD660u: goto label_802CD660;
    case 0x802CD664u: goto label_802CD664;
    case 0x802CD668u: goto label_802CD668;
    case 0x802CD66Cu: goto label_802CD66C;
    case 0x802CD670u: goto label_802CD670;
    case 0x802CD674u: goto label_802CD674;
    case 0x802CD678u: goto label_802CD678;
    case 0x802CD67Cu: goto label_802CD67C;
    case 0x802CD680u: goto label_802CD680;
    case 0x802CD684u: goto label_802CD684;
    case 0x802CD688u: goto label_802CD688;
    case 0x802CD68Cu: goto label_802CD68C;
    case 0x802CD690u: goto label_802CD690;
    case 0x802CD694u: goto label_802CD694;
    case 0x802CD698u: goto label_802CD698;
    case 0x802CD69Cu: goto label_802CD69C;
    case 0x802CD6A0u: goto label_802CD6A0;
    case 0x802CD6A4u: goto label_802CD6A4;
    case 0x802CD6A8u: goto label_802CD6A8;
    case 0x802CD6ACu: goto label_802CD6AC;
    case 0x802CD6B0u: goto label_802CD6B0;
    case 0x802CD6B4u: goto label_802CD6B4;
    case 0x802CD6B8u: goto label_802CD6B8;
    case 0x802CD6BCu: goto label_802CD6BC;
    case 0x802CD6C0u: goto label_802CD6C0;
    case 0x802CD6C4u: goto label_802CD6C4;
    case 0x802CD6C8u: goto label_802CD6C8;
    case 0x802CD6CCu: goto label_802CD6CC;
    case 0x802CD6D0u: goto label_802CD6D0;
    case 0x802CD6D4u: goto label_802CD6D4;
    case 0x802CD6D8u: goto label_802CD6D8;
    case 0x802CD6DCu: goto label_802CD6DC;
    case 0x802CD6E0u: goto label_802CD6E0;
    case 0x802CD6E4u: goto label_802CD6E4;
    case 0x802CD6E8u: goto label_802CD6E8;
    case 0x802CD6ECu: goto label_802CD6EC;
    case 0x802CD6F0u: goto label_802CD6F0;
    case 0x802CD6F4u: goto label_802CD6F4;
    case 0x802CD6F8u: goto label_802CD6F8;
    case 0x802CD6FCu: goto label_802CD6FC;
    case 0x802CD700u: goto label_802CD700;
    case 0x802CD704u: goto label_802CD704;
    case 0x802CD708u: goto label_802CD708;
    case 0x802CD70Cu: goto label_802CD70C;
    case 0x802CD710u: goto label_802CD710;
    case 0x802CD714u: goto label_802CD714;
    case 0x802CD718u: goto label_802CD718;
    case 0x802CD71Cu: goto label_802CD71C;
    case 0x802CD720u: goto label_802CD720;
    case 0x802CD724u: goto label_802CD724;
    case 0x802CD728u: goto label_802CD728;
    case 0x802CD72Cu: goto label_802CD72C;
    case 0x802CD730u: goto label_802CD730;
    case 0x802CD734u: goto label_802CD734;
    case 0x802CD738u: goto label_802CD738;
    case 0x802CD73Cu: goto label_802CD73C;
    case 0x802CD740u: goto label_802CD740;
    case 0x802CD744u: goto label_802CD744;
    case 0x802CD748u: goto label_802CD748;
    case 0x802CD74Cu: goto label_802CD74C;
    case 0x802CD750u: goto label_802CD750;
    case 0x802CD754u: goto label_802CD754;
    case 0x802CD758u: goto label_802CD758;
    case 0x802CD75Cu: goto label_802CD75C;
    case 0x802CD760u: goto label_802CD760;
    case 0x802CD764u: goto label_802CD764;
    case 0x802CD768u: goto label_802CD768;
    case 0x802CD76Cu: goto label_802CD76C;
    case 0x802CD770u: goto label_802CD770;
    case 0x802CD774u: goto label_802CD774;
    case 0x802CD778u: goto label_802CD778;
    case 0x802CD77Cu: goto label_802CD77C;
    case 0x802CD780u: goto label_802CD780;
    case 0x802CD784u: goto label_802CD784;
    case 0x802CD788u: goto label_802CD788;
    case 0x802CD78Cu: goto label_802CD78C;
    case 0x802CD790u: goto label_802CD790;
    case 0x802CD794u: goto label_802CD794;
    case 0x802CD798u: goto label_802CD798;
    case 0x802CD79Cu: goto label_802CD79C;
    case 0x802CD7A0u: goto label_802CD7A0;
    case 0x802CD7A4u: goto label_802CD7A4;
    case 0x802CD7A8u: goto label_802CD7A8;
    case 0x802CD7ACu: goto label_802CD7AC;
    case 0x802CD7B0u: goto label_802CD7B0;
    case 0x802CD7B4u: goto label_802CD7B4;
    case 0x802CD7B8u: goto label_802CD7B8;
    case 0x802CD7BCu: goto label_802CD7BC;
    case 0x802CD7C0u: goto label_802CD7C0;
    case 0x802CD7C4u: goto label_802CD7C4;
    case 0x802CD7C8u: goto label_802CD7C8;
    case 0x802CD7CCu: goto label_802CD7CC;
    case 0x802CD7D0u: goto label_802CD7D0;
    case 0x802CD7D4u: goto label_802CD7D4;
    case 0x802CD7D8u: goto label_802CD7D8;
    case 0x802CD7DCu: goto label_802CD7DC;
    case 0x802CD7E0u: goto label_802CD7E0;
    case 0x802CD7E4u: goto label_802CD7E4;
    case 0x802CD7E8u: goto label_802CD7E8;
    case 0x802CD7ECu: goto label_802CD7EC;
    case 0x802CD7F0u: goto label_802CD7F0;
    case 0x802CD7F4u: goto label_802CD7F4;
    case 0x802CD7F8u: goto label_802CD7F8;
    case 0x802CD7FCu: goto label_802CD7FC;
    case 0x802CD800u: goto label_802CD800;
    case 0x802CD804u: goto label_802CD804;
    case 0x802CD808u: goto label_802CD808;
    case 0x802CD80Cu: goto label_802CD80C;
    case 0x802CD810u: goto label_802CD810;
    case 0x802CD814u: goto label_802CD814;
    case 0x802CD818u: goto label_802CD818;
    case 0x802CD81Cu: goto label_802CD81C;
    case 0x802CD820u: goto label_802CD820;
    case 0x802CD824u: goto label_802CD824;
    case 0x802CD828u: goto label_802CD828;
    case 0x802CD82Cu: goto label_802CD82C;
    case 0x802CD830u: goto label_802CD830;
    case 0x802CD834u: goto label_802CD834;
    case 0x802CD838u: goto label_802CD838;
    case 0x802CD83Cu: goto label_802CD83C;
    case 0x802CD840u: goto label_802CD840;
    case 0x802CD844u: goto label_802CD844;
    case 0x802CD848u: goto label_802CD848;
    case 0x802CD84Cu: goto label_802CD84C;
    case 0x802CD850u: goto label_802CD850;
    case 0x802CD854u: goto label_802CD854;
    case 0x802CD858u: goto label_802CD858;
    case 0x802CD85Cu: goto label_802CD85C;
    case 0x802CD860u: goto label_802CD860;
    case 0x802CD864u: goto label_802CD864;
    case 0x802CD868u: goto label_802CD868;
    case 0x802CD86Cu: goto label_802CD86C;
    case 0x802CD870u: goto label_802CD870;
    case 0x802CD874u: goto label_802CD874;
    case 0x802CD878u: goto label_802CD878;
    case 0x802CD87Cu: goto label_802CD87C;
    case 0x802CD880u: goto label_802CD880;
    case 0x802CD884u: goto label_802CD884;
    case 0x802CD888u: goto label_802CD888;
    case 0x802CD88Cu: goto label_802CD88C;
    case 0x802CD890u: goto label_802CD890;
    case 0x802CD894u: goto label_802CD894;
    case 0x802CD898u: goto label_802CD898;
    case 0x802CD89Cu: goto label_802CD89C;
    case 0x802CD8A0u: goto label_802CD8A0;
    case 0x802CD8A4u: goto label_802CD8A4;
    case 0x802CD8A8u: goto label_802CD8A8;
    case 0x802CD8ACu: goto label_802CD8AC;
    case 0x802CD8B0u: goto label_802CD8B0;
    case 0x802CD8B4u: goto label_802CD8B4;
    case 0x802CD8B8u: goto label_802CD8B8;
    case 0x802CD8BCu: goto label_802CD8BC;
    case 0x802CD8C0u: goto label_802CD8C0;
    case 0x802CD8C4u: goto label_802CD8C4;
    case 0x802CD8C8u: goto label_802CD8C8;
    case 0x802CD8CCu: goto label_802CD8CC;
    case 0x802CD8D0u: goto label_802CD8D0;
    case 0x802CD8D4u: goto label_802CD8D4;
    case 0x802CD8D8u: goto label_802CD8D8;
    case 0x802CD8DCu: goto label_802CD8DC;
    case 0x802CD8E0u: goto label_802CD8E0;
    case 0x802CD8E4u: goto label_802CD8E4;
    case 0x802CD8E8u: goto label_802CD8E8;
    case 0x802CD8ECu: goto label_802CD8EC;
    case 0x802CD8F0u: goto label_802CD8F0;
    case 0x802CD8F4u: goto label_802CD8F4;
    case 0x802CD8F8u: goto label_802CD8F8;
    case 0x802CD8FCu: goto label_802CD8FC;
    case 0x802CD900u: goto label_802CD900;
    case 0x802CD904u: goto label_802CD904;
    case 0x802CD908u: goto label_802CD908;
    case 0x802CD90Cu: goto label_802CD90C;
    case 0x802CD910u: goto label_802CD910;
    case 0x802CD914u: goto label_802CD914;
    case 0x802CD918u: goto label_802CD918;
    case 0x802CD91Cu: goto label_802CD91C;
    case 0x802CD920u: goto label_802CD920;
    case 0x802CD924u: goto label_802CD924;
    case 0x802CD928u: goto label_802CD928;
    case 0x802CD92Cu: goto label_802CD92C;
    case 0x802CD930u: goto label_802CD930;
    case 0x802CD934u: goto label_802CD934;
    case 0x802CD938u: goto label_802CD938;
    case 0x802CD93Cu: goto label_802CD93C;
    case 0x802CD940u: goto label_802CD940;
    case 0x802CD944u: goto label_802CD944;
    case 0x802CD948u: goto label_802CD948;
    case 0x802CD94Cu: goto label_802CD94C;
    case 0x802CD950u: goto label_802CD950;
    case 0x802CD954u: goto label_802CD954;
    case 0x802CD958u: goto label_802CD958;
    case 0x802CD95Cu: goto label_802CD95C;
    case 0x802CD960u: goto label_802CD960;
    case 0x802CD964u: goto label_802CD964;
    case 0x802CD968u: goto label_802CD968;
    case 0x802CD96Cu: goto label_802CD96C;
    case 0x802CD970u: goto label_802CD970;
    case 0x802CD974u: goto label_802CD974;
    case 0x802CD978u: goto label_802CD978;
    case 0x802CD97Cu: goto label_802CD97C;
    case 0x802CD980u: goto label_802CD980;
    case 0x802CD984u: goto label_802CD984;
    case 0x802CD988u: goto label_802CD988;
    case 0x802CD98Cu: goto label_802CD98C;
    case 0x802CD990u: goto label_802CD990;
    case 0x802CD994u: goto label_802CD994;
    case 0x802CD998u: goto label_802CD998;
    case 0x802CD99Cu: goto label_802CD99C;
    case 0x802CD9A0u: goto label_802CD9A0;
    case 0x802CD9A4u: goto label_802CD9A4;
    case 0x802CD9A8u: goto label_802CD9A8;
    case 0x802CD9ACu: goto label_802CD9AC;
    case 0x802CD9B0u: goto label_802CD9B0;
    case 0x802CD9B4u: goto label_802CD9B4;
    case 0x802CD9B8u: goto label_802CD9B8;
    case 0x802CD9BCu: goto label_802CD9BC;
    case 0x802CD9C0u: goto label_802CD9C0;
    case 0x802CD9C4u: goto label_802CD9C4;
    case 0x802CD9C8u: goto label_802CD9C8;
    case 0x802CD9CCu: goto label_802CD9CC;
    case 0x802CD9D0u: goto label_802CD9D0;
    case 0x802CD9D4u: goto label_802CD9D4;
    case 0x802CD9D8u: goto label_802CD9D8;
    case 0x802CD9DCu: goto label_802CD9DC;
    case 0x802CD9E0u: goto label_802CD9E0;
    case 0x802CD9E4u: goto label_802CD9E4;
    case 0x802CD9E8u: goto label_802CD9E8;
    case 0x802CD9ECu: goto label_802CD9EC;
    case 0x802CD9F0u: goto label_802CD9F0;
    case 0x802CD9F4u: goto label_802CD9F4;
    case 0x802CD9F8u: goto label_802CD9F8;
    case 0x802CD9FCu: goto label_802CD9FC;
    case 0x802CDA00u: goto label_802CDA00;
    case 0x802CDA04u: goto label_802CDA04;
    case 0x802CDA08u: goto label_802CDA08;
    case 0x802CDA0Cu: goto label_802CDA0C;
    case 0x802CDA10u: goto label_802CDA10;
    case 0x802CDA14u: goto label_802CDA14;
    case 0x802CDA18u: goto label_802CDA18;
    case 0x802CDA1Cu: goto label_802CDA1C;
    case 0x802CDA20u: goto label_802CDA20;
    case 0x802CDA24u: goto label_802CDA24;
    case 0x802CDA28u: goto label_802CDA28;
    case 0x802CDA2Cu: goto label_802CDA2C;
    case 0x802CDA30u: goto label_802CDA30;
    case 0x802CDA34u: goto label_802CDA34;
    case 0x802CDA38u: goto label_802CDA38;
    case 0x802CDA3Cu: goto label_802CDA3C;
    case 0x802CDA40u: goto label_802CDA40;
    case 0x802CDA44u: goto label_802CDA44;
    case 0x802CDA48u: goto label_802CDA48;
    case 0x802CDA4Cu: goto label_802CDA4C;
    case 0x802CDA50u: goto label_802CDA50;
    case 0x802CDA54u: goto label_802CDA54;
    case 0x802CDA58u: goto label_802CDA58;
    case 0x802CDA5Cu: goto label_802CDA5C;
    case 0x802CDA60u: goto label_802CDA60;
    case 0x802CDA64u: goto label_802CDA64;
    case 0x802CDA68u: goto label_802CDA68;
    case 0x802CDA6Cu: goto label_802CDA6C;
    case 0x802CDA70u: goto label_802CDA70;
    case 0x802CDA74u: goto label_802CDA74;
    case 0x802CDA78u: goto label_802CDA78;
    case 0x802CDA7Cu: goto label_802CDA7C;
    case 0x802CDA80u: goto label_802CDA80;
    case 0x802CDA84u: goto label_802CDA84;
    case 0x802CDA88u: goto label_802CDA88;
    case 0x802CDA8Cu: goto label_802CDA8C;
    case 0x802CDA90u: goto label_802CDA90;
    case 0x802CDA94u: goto label_802CDA94;
    case 0x802CDA98u: goto label_802CDA98;
    case 0x802CDA9Cu: goto label_802CDA9C;
    case 0x802CDAA0u: goto label_802CDAA0;
    case 0x802CDAA4u: goto label_802CDAA4;
    case 0x802CDAA8u: goto label_802CDAA8;
    case 0x802CDAACu: goto label_802CDAAC;
    case 0x802CDAB0u: goto label_802CDAB0;
    case 0x802CDAB4u: goto label_802CDAB4;
    case 0x802CDAB8u: goto label_802CDAB8;
    case 0x802CDABCu: goto label_802CDABC;
    case 0x802CDAC0u: goto label_802CDAC0;
    case 0x802CDAC4u: goto label_802CDAC4;
    case 0x802CDAC8u: goto label_802CDAC8;
    case 0x802CDACCu: goto label_802CDACC;
    case 0x802CDAD0u: goto label_802CDAD0;
    case 0x802CDAD4u: goto label_802CDAD4;
    case 0x802CDAD8u: goto label_802CDAD8;
    case 0x802CDADCu: goto label_802CDADC;
    case 0x802CDAE0u: goto label_802CDAE0;
    case 0x802CDAE4u: goto label_802CDAE4;
    case 0x802CDAE8u: goto label_802CDAE8;
    case 0x802CDAECu: goto label_802CDAEC;
    case 0x802CDAF0u: goto label_802CDAF0;
    case 0x802CDAF4u: goto label_802CDAF4;
    case 0x802CDAF8u: goto label_802CDAF8;
    case 0x802CDAFCu: goto label_802CDAFC;
    case 0x802CDB00u: goto label_802CDB00;
    case 0x802CDB04u: goto label_802CDB04;
    case 0x802CDB08u: goto label_802CDB08;
    case 0x802CDB0Cu: goto label_802CDB0C;
    case 0x802CDB10u: goto label_802CDB10;
    case 0x802CDB14u: goto label_802CDB14;
    case 0x802CDB18u: goto label_802CDB18;
    case 0x802CDB1Cu: goto label_802CDB1C;
    case 0x802CDB20u: goto label_802CDB20;
    case 0x802CDB24u: goto label_802CDB24;
    case 0x802CDB28u: goto label_802CDB28;
    case 0x802CDB2Cu: goto label_802CDB2C;
    case 0x802CDB30u: goto label_802CDB30;
    case 0x802CDB34u: goto label_802CDB34;
    case 0x802CDB38u: goto label_802CDB38;
    case 0x802CDB3Cu: goto label_802CDB3C;
    case 0x802CDB40u: goto label_802CDB40;
    case 0x802CDB44u: goto label_802CDB44;
    case 0x802CDB48u: goto label_802CDB48;
    case 0x802CDB4Cu: goto label_802CDB4C;
    case 0x802CDB50u: goto label_802CDB50;
    case 0x802CDB54u: goto label_802CDB54;
    case 0x802CDB58u: goto label_802CDB58;
    case 0x802CDB5Cu: goto label_802CDB5C;
    case 0x802CDB60u: goto label_802CDB60;
    case 0x802CDB64u: goto label_802CDB64;
    case 0x802CDB68u: goto label_802CDB68;
    case 0x802CDB6Cu: goto label_802CDB6C;
    case 0x802CDB70u: goto label_802CDB70;
    case 0x802CDB74u: goto label_802CDB74;
    case 0x802CDB78u: goto label_802CDB78;
    case 0x802CDB7Cu: goto label_802CDB7C;
    case 0x802CDB80u: goto label_802CDB80;
    case 0x802CDB84u: goto label_802CDB84;
    case 0x802CDB88u: goto label_802CDB88;
    case 0x802CDB8Cu: goto label_802CDB8C;
    case 0x802CDB90u: goto label_802CDB90;
    case 0x802CDB94u: goto label_802CDB94;
    case 0x802CDB98u: goto label_802CDB98;
    case 0x802CDB9Cu: goto label_802CDB9C;
    case 0x802CDBA0u: goto label_802CDBA0;
    case 0x802CDBA4u: goto label_802CDBA4;
    case 0x802CDBA8u: goto label_802CDBA8;
    case 0x802CDBACu: goto label_802CDBAC;
    case 0x802CDBB0u: goto label_802CDBB0;
    case 0x802CDBB4u: goto label_802CDBB4;
    case 0x802CDBB8u: goto label_802CDBB8;
    case 0x802CDBBCu: goto label_802CDBBC;
    case 0x802CDBC0u: goto label_802CDBC0;
    case 0x802CDBC4u: goto label_802CDBC4;
    case 0x802CDBC8u: goto label_802CDBC8;
    case 0x802CDBCCu: goto label_802CDBCC;
    case 0x802CDBD0u: goto label_802CDBD0;
    case 0x802CDBD4u: goto label_802CDBD4;
    case 0x802CDBD8u: goto label_802CDBD8;
    case 0x802CDBDCu: goto label_802CDBDC;
    case 0x802CDBE0u: goto label_802CDBE0;
    case 0x802CDBE4u: goto label_802CDBE4;
    case 0x802CDBE8u: goto label_802CDBE8;
    case 0x802CDBECu: goto label_802CDBEC;
    case 0x802CDBF0u: goto label_802CDBF0;
    case 0x802CDBF4u: goto label_802CDBF4;
    case 0x802CDBF8u: goto label_802CDBF8;
    case 0x802CDBFCu: goto label_802CDBFC;
    case 0x802CDC00u: goto label_802CDC00;
    case 0x802CDC04u: goto label_802CDC04;
    case 0x802CDC08u: goto label_802CDC08;
    case 0x802CDC0Cu: goto label_802CDC0C;
    case 0x802CDC10u: goto label_802CDC10;
    case 0x802CDC14u: goto label_802CDC14;
    case 0x802CDC18u: goto label_802CDC18;
    case 0x802CDC1Cu: goto label_802CDC1C;
    case 0x802CDC20u: goto label_802CDC20;
    case 0x802CDC24u: goto label_802CDC24;
    case 0x802CDC28u: goto label_802CDC28;
    case 0x802CDC2Cu: goto label_802CDC2C;
    case 0x802CDC30u: goto label_802CDC30;
    case 0x802CDC34u: goto label_802CDC34;
    case 0x802CDC38u: goto label_802CDC38;
    case 0x802CDC3Cu: goto label_802CDC3C;
    case 0x802CDC40u: goto label_802CDC40;
    case 0x802CDC44u: goto label_802CDC44;
    case 0x802CDC48u: goto label_802CDC48;
    case 0x802CDC4Cu: goto label_802CDC4C;
    case 0x802CDC50u: goto label_802CDC50;
    case 0x802CDC54u: goto label_802CDC54;
    case 0x802CDC58u: goto label_802CDC58;
    case 0x802CDC5Cu: goto label_802CDC5C;
    case 0x802CDC60u: goto label_802CDC60;
    case 0x802CDC64u: goto label_802CDC64;
    case 0x802CDC68u: goto label_802CDC68;
    case 0x802CDC6Cu: goto label_802CDC6C;
    case 0x802CDC70u: goto label_802CDC70;
    case 0x802CDC74u: goto label_802CDC74;
    case 0x802CDC78u: goto label_802CDC78;
    case 0x802CDC7Cu: goto label_802CDC7C;
    case 0x802CDC80u: goto label_802CDC80;
    case 0x802CDC84u: goto label_802CDC84;
    case 0x802CDC88u: goto label_802CDC88;
    case 0x802CDC8Cu: goto label_802CDC8C;
    case 0x802CDC90u: goto label_802CDC90;
    case 0x802CDC94u: goto label_802CDC94;
    case 0x802CDC98u: goto label_802CDC98;
    case 0x802CDC9Cu: goto label_802CDC9C;
    case 0x802CDCA0u: goto label_802CDCA0;
    case 0x802CDCA4u: goto label_802CDCA4;
    case 0x802CDCA8u: goto label_802CDCA8;
    case 0x802CDCACu: goto label_802CDCAC;
    case 0x802CDCB0u: goto label_802CDCB0;
    case 0x802CDCB4u: goto label_802CDCB4;
    case 0x802CDCB8u: goto label_802CDCB8;
    case 0x802CDCBCu: goto label_802CDCBC;
    case 0x802CDCC0u: goto label_802CDCC0;
    case 0x802CDCC4u: goto label_802CDCC4;
    case 0x802CDCC8u: goto label_802CDCC8;
    case 0x802CDCCCu: goto label_802CDCCC;
    case 0x802CDCD0u: goto label_802CDCD0;
    case 0x802CDCD4u: goto label_802CDCD4;
    case 0x802CDCD8u: goto label_802CDCD8;
    case 0x802CDCDCu: goto label_802CDCDC;
    case 0x802CDCE0u: goto label_802CDCE0;
    case 0x802CDCE4u: goto label_802CDCE4;
    case 0x802CDCE8u: goto label_802CDCE8;
    case 0x802CDCECu: goto label_802CDCEC;
    case 0x802CDCF0u: goto label_802CDCF0;
    case 0x802CDCF4u: goto label_802CDCF4;
    case 0x802CDCF8u: goto label_802CDCF8;
    case 0x802CDCFCu: goto label_802CDCFC;
    case 0x802CDD00u: goto label_802CDD00;
    case 0x802CDD04u: goto label_802CDD04;
    case 0x802CDD08u: goto label_802CDD08;
    case 0x802CDD0Cu: goto label_802CDD0C;
    case 0x802CDD10u: goto label_802CDD10;
    case 0x802CDD14u: goto label_802CDD14;
    case 0x802CDD18u: goto label_802CDD18;
    case 0x802CDD1Cu: goto label_802CDD1C;
    case 0x802CDD20u: goto label_802CDD20;
    case 0x802CDD24u: goto label_802CDD24;
    case 0x802CDD28u: goto label_802CDD28;
    case 0x802CDD2Cu: goto label_802CDD2C;
    case 0x802CDD30u: goto label_802CDD30;
    case 0x802CDD34u: goto label_802CDD34;
    case 0x802CDD38u: goto label_802CDD38;
    case 0x802CDD3Cu: goto label_802CDD3C;
    case 0x802CDD40u: goto label_802CDD40;
    case 0x802CDD44u: goto label_802CDD44;
    case 0x802CDD48u: goto label_802CDD48;
    case 0x802CDD4Cu: goto label_802CDD4C;
    case 0x802CDD50u: goto label_802CDD50;
    case 0x802CDD54u: goto label_802CDD54;
    case 0x802CDD58u: goto label_802CDD58;
    case 0x802CDD5Cu: goto label_802CDD5C;
    case 0x802CDD60u: goto label_802CDD60;
    case 0x802CDD64u: goto label_802CDD64;
    case 0x802CDD68u: goto label_802CDD68;
    case 0x802CDD6Cu: goto label_802CDD6C;
    case 0x802CDD70u: goto label_802CDD70;
    case 0x802CDD74u: goto label_802CDD74;
    case 0x802CDD78u: goto label_802CDD78;
    case 0x802CDD7Cu: goto label_802CDD7C;
    case 0x802CDD80u: goto label_802CDD80;
    case 0x802CDD84u: goto label_802CDD84;
    case 0x802CDD88u: goto label_802CDD88;
    case 0x802CDD8Cu: goto label_802CDD8C;
    case 0x802CDD90u: goto label_802CDD90;
    case 0x802CDD94u: goto label_802CDD94;
    case 0x802CDD98u: goto label_802CDD98;
    case 0x802CDD9Cu: goto label_802CDD9C;
    case 0x802CDDA0u: goto label_802CDDA0;
    case 0x802CDDA4u: goto label_802CDDA4;
    case 0x802CDDA8u: goto label_802CDDA8;
    case 0x802CDDACu: goto label_802CDDAC;
    case 0x802CDDB0u: goto label_802CDDB0;
    case 0x802CDDB4u: goto label_802CDDB4;
    case 0x802CDDB8u: goto label_802CDDB8;
    case 0x802CDDBCu: goto label_802CDDBC;
    case 0x802CDDC0u: goto label_802CDDC0;
    case 0x802CDDC4u: goto label_802CDDC4;
    case 0x802CDDC8u: goto label_802CDDC8;
    case 0x802CDDCCu: goto label_802CDDCC;
    case 0x802CDDD0u: goto label_802CDDD0;
    case 0x802CDDD4u: goto label_802CDDD4;
    case 0x802CDDD8u: goto label_802CDDD8;
    case 0x802CDDDCu: goto label_802CDDDC;
    case 0x802CDDE0u: goto label_802CDDE0;
    case 0x802CDDE4u: goto label_802CDDE4;
    case 0x802CDDE8u: goto label_802CDDE8;
    case 0x802CDDECu: goto label_802CDDEC;
    case 0x802CDDF0u: goto label_802CDDF0;
    case 0x802CDDF4u: goto label_802CDDF4;
    case 0x802CDDF8u: goto label_802CDDF8;
    case 0x802CDDFCu: goto label_802CDDFC;
    case 0x802CDE00u: goto label_802CDE00;
    case 0x802CDE04u: goto label_802CDE04;
    case 0x802CDE08u: goto label_802CDE08;
    case 0x802CDE0Cu: goto label_802CDE0C;
    case 0x802CDE10u: goto label_802CDE10;
    case 0x802CDE14u: goto label_802CDE14;
    case 0x802CDE18u: goto label_802CDE18;
    case 0x802CDE1Cu: goto label_802CDE1C;
    case 0x802CDE20u: goto label_802CDE20;
    case 0x802CDE24u: goto label_802CDE24;
    case 0x802CDE28u: goto label_802CDE28;
    case 0x802CDE2Cu: goto label_802CDE2C;
    case 0x802CDE30u: goto label_802CDE30;
    case 0x802CDE34u: goto label_802CDE34;
    case 0x802CDE38u: goto label_802CDE38;
    case 0x802CDE3Cu: goto label_802CDE3C;
    case 0x802CDE40u: goto label_802CDE40;
    case 0x802CDE44u: goto label_802CDE44;
    case 0x802CDE48u: goto label_802CDE48;
    case 0x802CDE4Cu: goto label_802CDE4C;
    case 0x802CDE50u: goto label_802CDE50;
    case 0x802CDE54u: goto label_802CDE54;
    case 0x802CDE58u: goto label_802CDE58;
    case 0x802CDE5Cu: goto label_802CDE5C;
    case 0x802CDE60u: goto label_802CDE60;
    case 0x802CDE64u: goto label_802CDE64;
    case 0x802CDE68u: goto label_802CDE68;
    case 0x802CDE6Cu: goto label_802CDE6C;
    case 0x802CDE70u: goto label_802CDE70;
    case 0x802CDE74u: goto label_802CDE74;
    case 0x802CDE78u: goto label_802CDE78;
    case 0x802CDE7Cu: goto label_802CDE7C;
    case 0x802CDE80u: goto label_802CDE80;
    case 0x802CDE84u: goto label_802CDE84;
    case 0x802CDE88u: goto label_802CDE88;
    case 0x802CDE8Cu: goto label_802CDE8C;
    case 0x802CDE90u: goto label_802CDE90;
    case 0x802CDE94u: goto label_802CDE94;
    case 0x802CDE98u: goto label_802CDE98;
    case 0x802CDE9Cu: goto label_802CDE9C;
    case 0x802CDEA0u: goto label_802CDEA0;
    case 0x802CDEA4u: goto label_802CDEA4;
    case 0x802CDEA8u: goto label_802CDEA8;
    case 0x802CDEACu: goto label_802CDEAC;
    case 0x802CDEB0u: goto label_802CDEB0;
    case 0x802CDEB4u: goto label_802CDEB4;
    case 0x802CDEB8u: goto label_802CDEB8;
    case 0x802CDEBCu: goto label_802CDEBC;
    case 0x802CDEC0u: goto label_802CDEC0;
    case 0x802CDEC4u: goto label_802CDEC4;
    case 0x802CDEC8u: goto label_802CDEC8;
    case 0x802CDECCu: goto label_802CDECC;
    case 0x802CDED0u: goto label_802CDED0;
    case 0x802CDED4u: goto label_802CDED4;
    case 0x802CDED8u: goto label_802CDED8;
    case 0x802CDEDCu: goto label_802CDEDC;
    case 0x802CDEE0u: goto label_802CDEE0;
    case 0x802CDEE4u: goto label_802CDEE4;
    case 0x802CDEE8u: goto label_802CDEE8;
    case 0x802CDEECu: goto label_802CDEEC;
    case 0x802CDEF0u: goto label_802CDEF0;
    case 0x802CDEF4u: goto label_802CDEF4;
    case 0x802CDEF8u: goto label_802CDEF8;
    case 0x802CDEFCu: goto label_802CDEFC;
    case 0x802CDF00u: goto label_802CDF00;
    case 0x802CDF04u: goto label_802CDF04;
    case 0x802CDF08u: goto label_802CDF08;
    case 0x802CDF0Cu: goto label_802CDF0C;
    case 0x802CDF10u: goto label_802CDF10;
    case 0x802CDF14u: goto label_802CDF14;
    case 0x802CDF18u: goto label_802CDF18;
    case 0x802CDF1Cu: goto label_802CDF1C;
    case 0x802CDF20u: goto label_802CDF20;
    case 0x802CDF24u: goto label_802CDF24;
    case 0x802CDF28u: goto label_802CDF28;
    case 0x802CDF2Cu: goto label_802CDF2C;
    case 0x802CDF30u: goto label_802CDF30;
    case 0x802CDF34u: goto label_802CDF34;
    case 0x802CDF38u: goto label_802CDF38;
    case 0x802CDF3Cu: goto label_802CDF3C;
    case 0x802CDF40u: goto label_802CDF40;
    case 0x802CDF44u: goto label_802CDF44;
    case 0x802CDF48u: goto label_802CDF48;
    case 0x802CDF4Cu: goto label_802CDF4C;
    case 0x802CDF50u: goto label_802CDF50;
    case 0x802CDF54u: goto label_802CDF54;
    case 0x802CDF58u: goto label_802CDF58;
    case 0x802CDF5Cu: goto label_802CDF5C;
    case 0x802CDF60u: goto label_802CDF60;
    case 0x802CDF64u: goto label_802CDF64;
    case 0x802CDF68u: goto label_802CDF68;
    case 0x802CDF6Cu: goto label_802CDF6C;
    case 0x802CDF70u: goto label_802CDF70;
    case 0x802CDF74u: goto label_802CDF74;
    case 0x802CDF78u: goto label_802CDF78;
    case 0x802CDF7Cu: goto label_802CDF7C;
    case 0x802CDF80u: goto label_802CDF80;
    case 0x802CDF84u: goto label_802CDF84;
    case 0x802CDF88u: goto label_802CDF88;
    case 0x802CDF8Cu: goto label_802CDF8C;
    case 0x802CDF90u: goto label_802CDF90;
    case 0x802CDF94u: goto label_802CDF94;
    case 0x802CDF98u: goto label_802CDF98;
    case 0x802CDF9Cu: goto label_802CDF9C;
    case 0x802CDFA0u: goto label_802CDFA0;
    case 0x802CDFA4u: goto label_802CDFA4;
    case 0x802CDFA8u: goto label_802CDFA8;
    case 0x802CDFACu: goto label_802CDFAC;
    case 0x802CDFB0u: goto label_802CDFB0;
    case 0x802CDFB4u: goto label_802CDFB4;
    case 0x802CDFB8u: goto label_802CDFB8;
    case 0x802CDFBCu: goto label_802CDFBC;
    case 0x802CDFC0u: goto label_802CDFC0;
    case 0x802CDFC4u: goto label_802CDFC4;
    case 0x802CDFC8u: goto label_802CDFC8;
    case 0x802CDFCCu: goto label_802CDFCC;
    case 0x802CDFD0u: goto label_802CDFD0;
    case 0x802CDFD4u: goto label_802CDFD4;
    case 0x802CDFD8u: goto label_802CDFD8;
    case 0x802CDFDCu: goto label_802CDFDC;
    case 0x802CDFE0u: goto label_802CDFE0;
    case 0x802CDFE4u: goto label_802CDFE4;
    case 0x802CDFE8u: goto label_802CDFE8;
    case 0x802CDFECu: goto label_802CDFEC;
    case 0x802CDFF0u: goto label_802CDFF0;
    case 0x802CDFF4u: goto label_802CDFF4;
    case 0x802CDFF8u: goto label_802CDFF8;
    case 0x802CDFFCu: goto label_802CDFFC;
    case 0x802CE000u: goto label_802CE000;
    case 0x802CE004u: goto label_802CE004;
    case 0x802CE008u: goto label_802CE008;
    case 0x802CE00Cu: goto label_802CE00C;
    case 0x802CE010u: goto label_802CE010;
    case 0x802CE014u: goto label_802CE014;
    case 0x802CE018u: goto label_802CE018;
    case 0x802CE01Cu: goto label_802CE01C;
    case 0x802CE020u: goto label_802CE020;
    case 0x802CE024u: goto label_802CE024;
    case 0x802CE028u: goto label_802CE028;
    case 0x802CE02Cu: goto label_802CE02C;
    case 0x802CE030u: goto label_802CE030;
    case 0x802CE034u: goto label_802CE034;
    case 0x802CE038u: goto label_802CE038;
    case 0x802CE03Cu: goto label_802CE03C;
    case 0x802CE040u: goto label_802CE040;
    case 0x802CE044u: goto label_802CE044;
    case 0x802CE048u: goto label_802CE048;
    case 0x802CE04Cu: goto label_802CE04C;
    case 0x802CE050u: goto label_802CE050;
    case 0x802CE054u: goto label_802CE054;
    case 0x802CE058u: goto label_802CE058;
    case 0x802CE05Cu: goto label_802CE05C;
    case 0x802CE060u: goto label_802CE060;
    case 0x802CE064u: goto label_802CE064;
    case 0x802CE068u: goto label_802CE068;
    case 0x802CE06Cu: goto label_802CE06C;
    case 0x802CE070u: goto label_802CE070;
    case 0x802CE074u: goto label_802CE074;
    case 0x802CE078u: goto label_802CE078;
    case 0x802CE07Cu: goto label_802CE07C;
    case 0x802CE080u: goto label_802CE080;
    case 0x802CE084u: goto label_802CE084;
    case 0x802CE088u: goto label_802CE088;
    case 0x802CE08Cu: goto label_802CE08C;
    case 0x802CE090u: goto label_802CE090;
    case 0x802CE094u: goto label_802CE094;
    case 0x802CE098u: goto label_802CE098;
    case 0x802CE09Cu: goto label_802CE09C;
    case 0x802CE0A0u: goto label_802CE0A0;
    case 0x802CE0A4u: goto label_802CE0A4;
    case 0x802CE0A8u: goto label_802CE0A8;
    case 0x802CE0ACu: goto label_802CE0AC;
    case 0x802CE0B0u: goto label_802CE0B0;
    case 0x802CE0B4u: goto label_802CE0B4;
    case 0x802CE0B8u: goto label_802CE0B8;
    case 0x802CE0BCu: goto label_802CE0BC;
    case 0x802CE0C0u: goto label_802CE0C0;
    case 0x802CE0C4u: goto label_802CE0C4;
    case 0x802CE0C8u: goto label_802CE0C8;
    case 0x802CE0CCu: goto label_802CE0CC;
    case 0x802CE0D0u: goto label_802CE0D0;
    case 0x802CE0D4u: goto label_802CE0D4;
    case 0x802CE0D8u: goto label_802CE0D8;
    case 0x802CE0DCu: goto label_802CE0DC;
    case 0x802CE0E0u: goto label_802CE0E0;
    case 0x802CE0E4u: goto label_802CE0E4;
    case 0x802CE0E8u: goto label_802CE0E8;
    case 0x802CE0ECu: goto label_802CE0EC;
    case 0x802CE0F0u: goto label_802CE0F0;
    case 0x802CE0F4u: goto label_802CE0F4;
    case 0x802CE0F8u: goto label_802CE0F8;
    case 0x802CE0FCu: goto label_802CE0FC;
    case 0x802CE100u: goto label_802CE100;
    case 0x802CE104u: goto label_802CE104;
    case 0x802CE108u: goto label_802CE108;
    case 0x802CE10Cu: goto label_802CE10C;
    case 0x802CE110u: goto label_802CE110;
    case 0x802CE114u: goto label_802CE114;
    case 0x802CE118u: goto label_802CE118;
    case 0x802CE11Cu: goto label_802CE11C;
    case 0x802CE120u: goto label_802CE120;
    case 0x802CE124u: goto label_802CE124;
    case 0x802CE128u: goto label_802CE128;
    case 0x802CE12Cu: goto label_802CE12C;
    case 0x802CE130u: goto label_802CE130;
    case 0x802CE134u: goto label_802CE134;
    case 0x802CE138u: goto label_802CE138;
    case 0x802CE13Cu: goto label_802CE13C;
    case 0x802CE140u: goto label_802CE140;
    case 0x802CE144u: goto label_802CE144;
    case 0x802CE148u: goto label_802CE148;
    case 0x802CE14Cu: goto label_802CE14C;
    case 0x802CE150u: goto label_802CE150;
    case 0x802CE154u: goto label_802CE154;
    case 0x802CE158u: goto label_802CE158;
    case 0x802CE15Cu: goto label_802CE15C;
    case 0x802CE160u: goto label_802CE160;
    case 0x802CE164u: goto label_802CE164;
    case 0x802CE168u: goto label_802CE168;
    case 0x802CE16Cu: goto label_802CE16C;
    case 0x802CE170u: goto label_802CE170;
    case 0x802CE174u: goto label_802CE174;
    case 0x802CE178u: goto label_802CE178;
    case 0x802CE17Cu: goto label_802CE17C;
    case 0x802CE180u: goto label_802CE180;
    case 0x802CE184u: goto label_802CE184;
    case 0x802CE188u: goto label_802CE188;
    case 0x802CE18Cu: goto label_802CE18C;
    case 0x802CE190u: goto label_802CE190;
    case 0x802CE194u: goto label_802CE194;
    case 0x802CE198u: goto label_802CE198;
    case 0x802CE19Cu: goto label_802CE19C;
    case 0x802CE1A0u: goto label_802CE1A0;
    case 0x802CE1A4u: goto label_802CE1A4;
    case 0x802CE1A8u: goto label_802CE1A8;
    case 0x802CE1ACu: goto label_802CE1AC;
    case 0x802CE1B0u: goto label_802CE1B0;
    case 0x802CE1B4u: goto label_802CE1B4;
    case 0x802CE1B8u: goto label_802CE1B8;
    case 0x802CE1BCu: goto label_802CE1BC;
    case 0x802CE1C0u: goto label_802CE1C0;
    case 0x802CE1C4u: goto label_802CE1C4;
    case 0x802CE1C8u: goto label_802CE1C8;
    case 0x802CE1CCu: goto label_802CE1CC;
    case 0x802CE1D0u: goto label_802CE1D0;
    case 0x802CE1D4u: goto label_802CE1D4;
    case 0x802CE1D8u: goto label_802CE1D8;
    case 0x802CE1DCu: goto label_802CE1DC;
    case 0x802CE1E0u: goto label_802CE1E0;
    case 0x802CE1E4u: goto label_802CE1E4;
    case 0x802CE1E8u: goto label_802CE1E8;
    case 0x802CE1ECu: goto label_802CE1EC;
    case 0x802CE1F0u: goto label_802CE1F0;
    case 0x802CE1F4u: goto label_802CE1F4;
    case 0x802CE1F8u: goto label_802CE1F8;
    case 0x802CE1FCu: goto label_802CE1FC;
    case 0x802CE200u: goto label_802CE200;
    case 0x802CE204u: goto label_802CE204;
    case 0x802CE208u: goto label_802CE208;
    case 0x802CE20Cu: goto label_802CE20C;
    case 0x802CE210u: goto label_802CE210;
    case 0x802CE214u: goto label_802CE214;
    case 0x802CE218u: goto label_802CE218;
    case 0x802CE21Cu: goto label_802CE21C;
    case 0x802CE220u: goto label_802CE220;
    case 0x802CE224u: goto label_802CE224;
    case 0x802CE228u: goto label_802CE228;
    case 0x802CE22Cu: goto label_802CE22C;
    case 0x802CE230u: goto label_802CE230;
    case 0x802CE234u: goto label_802CE234;
    case 0x802CE238u: goto label_802CE238;
    case 0x802CE23Cu: goto label_802CE23C;
    case 0x802CE240u: goto label_802CE240;
    case 0x802CE244u: goto label_802CE244;
    case 0x802CE248u: goto label_802CE248;
    case 0x802CE24Cu: goto label_802CE24C;
    case 0x802CE250u: goto label_802CE250;
    case 0x802CE254u: goto label_802CE254;
    case 0x802CE258u: goto label_802CE258;
    case 0x802CE25Cu: goto label_802CE25C;
    case 0x802CE260u: goto label_802CE260;
    case 0x802CE264u: goto label_802CE264;
    case 0x802CE268u: goto label_802CE268;
    case 0x802CE26Cu: goto label_802CE26C;
    case 0x802CE270u: goto label_802CE270;
    case 0x802CE274u: goto label_802CE274;
    case 0x802CE278u: goto label_802CE278;
    case 0x802CE27Cu: goto label_802CE27C;
    case 0x802CE280u: goto label_802CE280;
    case 0x802CE284u: goto label_802CE284;
    case 0x802CE288u: goto label_802CE288;
    case 0x802CE28Cu: goto label_802CE28C;
    case 0x802CE290u: goto label_802CE290;
    case 0x802CE294u: goto label_802CE294;
    case 0x802CE298u: goto label_802CE298;
    case 0x802CE29Cu: goto label_802CE29C;
    case 0x802CE2A0u: goto label_802CE2A0;
    case 0x802CE2A4u: goto label_802CE2A4;
    case 0x802CE2A8u: goto label_802CE2A8;
    case 0x802CE2ACu: goto label_802CE2AC;
    case 0x802CE2B0u: goto label_802CE2B0;
    case 0x802CE2B4u: goto label_802CE2B4;
    case 0x802CE2B8u: goto label_802CE2B8;
    case 0x802CE2BCu: goto label_802CE2BC;
    case 0x802CE2C0u: goto label_802CE2C0;
    case 0x802CE2C4u: goto label_802CE2C4;
    case 0x802CE2C8u: goto label_802CE2C8;
    case 0x802CE2CCu: goto label_802CE2CC;
    case 0x802CE2D0u: goto label_802CE2D0;
    case 0x802CE2D4u: goto label_802CE2D4;
    case 0x802CE2D8u: goto label_802CE2D8;
    case 0x802CE2DCu: goto label_802CE2DC;
    case 0x802CE2E0u: goto label_802CE2E0;
    case 0x802CE2E4u: goto label_802CE2E4;
    case 0x802CE2E8u: goto label_802CE2E8;
    case 0x802CE2ECu: goto label_802CE2EC;
    case 0x802CE2F0u: goto label_802CE2F0;
    case 0x802CE2F4u: goto label_802CE2F4;
    case 0x802CE2F8u: goto label_802CE2F8;
    case 0x802CE2FCu: goto label_802CE2FC;
    case 0x802CE300u: goto label_802CE300;
    case 0x802CE304u: goto label_802CE304;
    case 0x802CE308u: goto label_802CE308;
    case 0x802CE30Cu: goto label_802CE30C;
    case 0x802CE310u: goto label_802CE310;
    case 0x802CE314u: goto label_802CE314;
    case 0x802CE318u: goto label_802CE318;
    case 0x802CE31Cu: goto label_802CE31C;
    case 0x802CE320u: goto label_802CE320;
    case 0x802CE324u: goto label_802CE324;
    case 0x802CE328u: goto label_802CE328;
    case 0x802CE32Cu: goto label_802CE32C;
    case 0x802CE330u: goto label_802CE330;
    case 0x802CE334u: goto label_802CE334;
    case 0x802CE338u: goto label_802CE338;
    case 0x802CE33Cu: goto label_802CE33C;
    case 0x802CE340u: goto label_802CE340;
    case 0x802CE344u: goto label_802CE344;
    case 0x802CE348u: goto label_802CE348;
    case 0x802CE34Cu: goto label_802CE34C;
    case 0x802CE350u: goto label_802CE350;
    case 0x802CE354u: goto label_802CE354;
    case 0x802CE358u: goto label_802CE358;
    case 0x802CE35Cu: goto label_802CE35C;
    case 0x802CE360u: goto label_802CE360;
    case 0x802CE364u: goto label_802CE364;
    case 0x802CE368u: goto label_802CE368;
    case 0x802CE36Cu: goto label_802CE36C;
    case 0x802CE370u: goto label_802CE370;
    case 0x802CE374u: goto label_802CE374;
    case 0x802CE378u: goto label_802CE378;
    case 0x802CE37Cu: goto label_802CE37C;
    case 0x802CE380u: goto label_802CE380;
    case 0x802CE384u: goto label_802CE384;
    case 0x802CE388u: goto label_802CE388;
    case 0x802CE38Cu: goto label_802CE38C;
    case 0x802CE390u: goto label_802CE390;
    case 0x802CE394u: goto label_802CE394;
    case 0x802CE398u: goto label_802CE398;
    case 0x802CE39Cu: goto label_802CE39C;
    case 0x802CE3A0u: goto label_802CE3A0;
    case 0x802CE3A4u: goto label_802CE3A4;
    case 0x802CE3A8u: goto label_802CE3A8;
    case 0x802CE3ACu: goto label_802CE3AC;
    case 0x802CE3B0u: goto label_802CE3B0;
    case 0x802CE3B4u: goto label_802CE3B4;
    case 0x802CE3B8u: goto label_802CE3B8;
    case 0x802CE3BCu: goto label_802CE3BC;
    case 0x802CE3C0u: goto label_802CE3C0;
    case 0x802CE3C4u: goto label_802CE3C4;
    case 0x802CE3C8u: goto label_802CE3C8;
    case 0x802CE3CCu: goto label_802CE3CC;
    case 0x802CE3D0u: goto label_802CE3D0;
    case 0x802CE3D4u: goto label_802CE3D4;
    case 0x802CE3D8u: goto label_802CE3D8;
    case 0x802CE3DCu: goto label_802CE3DC;
    case 0x802CE3E0u: goto label_802CE3E0;
    case 0x802CE3E4u: goto label_802CE3E4;
    case 0x802CE3E8u: goto label_802CE3E8;
    case 0x802CE3ECu: goto label_802CE3EC;
    case 0x802CE3F0u: goto label_802CE3F0;
    case 0x802CE3F4u: goto label_802CE3F4;
    case 0x802CE3F8u: goto label_802CE3F8;
    case 0x802CE3FCu: goto label_802CE3FC;
    case 0x802CE400u: goto label_802CE400;
    case 0x802CE404u: goto label_802CE404;
    case 0x802CE408u: goto label_802CE408;
    case 0x802CE40Cu: goto label_802CE40C;
    case 0x802CE410u: goto label_802CE410;
    case 0x802CE414u: goto label_802CE414;
    case 0x802CE418u: goto label_802CE418;
    case 0x802CE41Cu: goto label_802CE41C;
    case 0x802CE420u: goto label_802CE420;
    case 0x802CE424u: goto label_802CE424;
    case 0x802CE428u: goto label_802CE428;
    case 0x802CE42Cu: goto label_802CE42C;
    case 0x802CE430u: goto label_802CE430;
    case 0x802CE434u: goto label_802CE434;
    case 0x802CE438u: goto label_802CE438;
    case 0x802CE43Cu: goto label_802CE43C;
    case 0x802CE440u: goto label_802CE440;
    case 0x802CE444u: goto label_802CE444;
    case 0x802CE448u: goto label_802CE448;
    case 0x802CE44Cu: goto label_802CE44C;
    case 0x802CE450u: goto label_802CE450;
    case 0x802CE454u: goto label_802CE454;
    case 0x802CE458u: goto label_802CE458;
    case 0x802CE45Cu: goto label_802CE45C;
    case 0x802CE460u: goto label_802CE460;
    case 0x802CE464u: goto label_802CE464;
    case 0x802CE468u: goto label_802CE468;
    case 0x802CE46Cu: goto label_802CE46C;
    case 0x802CE470u: goto label_802CE470;
    case 0x802CE474u: goto label_802CE474;
    case 0x802CE478u: goto label_802CE478;
    case 0x802CE47Cu: goto label_802CE47C;
    case 0x802CE480u: goto label_802CE480;
    case 0x802CE484u: goto label_802CE484;
    case 0x802CE488u: goto label_802CE488;
    case 0x802CE48Cu: goto label_802CE48C;
    case 0x802CE490u: goto label_802CE490;
    case 0x802CE494u: goto label_802CE494;
    case 0x802CE498u: goto label_802CE498;
    case 0x802CE49Cu: goto label_802CE49C;
    case 0x802CE4A0u: goto label_802CE4A0;
    case 0x802CE4A4u: goto label_802CE4A4;
    case 0x802CE4A8u: goto label_802CE4A8;
    case 0x802CE4ACu: goto label_802CE4AC;
    case 0x802CE4B0u: goto label_802CE4B0;
    case 0x802CE4B4u: goto label_802CE4B4;
    case 0x802CE4B8u: goto label_802CE4B8;
    case 0x802CE4BCu: goto label_802CE4BC;
    case 0x802CE4C0u: goto label_802CE4C0;
    case 0x802CE4C4u: goto label_802CE4C4;
    case 0x802CE4C8u: goto label_802CE4C8;
    case 0x802CE4CCu: goto label_802CE4CC;
    case 0x802CE4D0u: goto label_802CE4D0;
    case 0x802CE4D4u: goto label_802CE4D4;
    case 0x802CE4D8u: goto label_802CE4D8;
    case 0x802CE4DCu: goto label_802CE4DC;
    case 0x802CE4E0u: goto label_802CE4E0;
    case 0x802CE4E4u: goto label_802CE4E4;
    case 0x802CE4E8u: goto label_802CE4E8;
    case 0x802CE4ECu: goto label_802CE4EC;
    case 0x802CE4F0u: goto label_802CE4F0;
    case 0x802CE4F4u: goto label_802CE4F4;
    case 0x802CE4F8u: goto label_802CE4F8;
    case 0x802CE4FCu: goto label_802CE4FC;
    case 0x802CE500u: goto label_802CE500;
    case 0x802CE504u: goto label_802CE504;
    case 0x802CE508u: goto label_802CE508;
    case 0x802CE50Cu: goto label_802CE50C;
    case 0x802CE510u: goto label_802CE510;
    case 0x802CE514u: goto label_802CE514;
    case 0x802CE518u: goto label_802CE518;
    case 0x802CE51Cu: goto label_802CE51C;
    case 0x802CE520u: goto label_802CE520;
    case 0x802CE524u: goto label_802CE524;
    case 0x802CE528u: goto label_802CE528;
    case 0x802CE52Cu: goto label_802CE52C;
    case 0x802CE530u: goto label_802CE530;
    case 0x802CE534u: goto label_802CE534;
    case 0x802CE538u: goto label_802CE538;
    case 0x802CE53Cu: goto label_802CE53C;
    case 0x802CE540u: goto label_802CE540;
    case 0x802CE544u: goto label_802CE544;
    case 0x802CE548u: goto label_802CE548;
    case 0x802CE54Cu: goto label_802CE54C;
    case 0x802CE550u: goto label_802CE550;
    case 0x802CE554u: goto label_802CE554;
    case 0x802CE558u: goto label_802CE558;
    case 0x802CE55Cu: goto label_802CE55C;
    case 0x802CE560u: goto label_802CE560;
    case 0x802CE564u: goto label_802CE564;
    case 0x802CE568u: goto label_802CE568;
    case 0x802CE56Cu: goto label_802CE56C;
    case 0x802CE570u: goto label_802CE570;
    case 0x802CE574u: goto label_802CE574;
    case 0x802CE578u: goto label_802CE578;
    case 0x802CE57Cu: goto label_802CE57C;
    case 0x802CE580u: goto label_802CE580;
    case 0x802CE584u: goto label_802CE584;
    case 0x802CE588u: goto label_802CE588;
    case 0x802CE58Cu: goto label_802CE58C;
    case 0x802CE590u: goto label_802CE590;
    case 0x802CE594u: goto label_802CE594;
    case 0x802CE598u: goto label_802CE598;
    case 0x802CE59Cu: goto label_802CE59C;
    case 0x802CE5A0u: goto label_802CE5A0;
    case 0x802CE5A4u: goto label_802CE5A4;
    case 0x802CE5A8u: goto label_802CE5A8;
    case 0x802CE5ACu: goto label_802CE5AC;
    case 0x802CE5B0u: goto label_802CE5B0;
    case 0x802CE5B4u: goto label_802CE5B4;
    case 0x802CE5B8u: goto label_802CE5B8;
    case 0x802CE5BCu: goto label_802CE5BC;
    case 0x802CE5C0u: goto label_802CE5C0;
    case 0x802CE5C4u: goto label_802CE5C4;
    case 0x802CE5C8u: goto label_802CE5C8;
    case 0x802CE5CCu: goto label_802CE5CC;
    case 0x802CE5D0u: goto label_802CE5D0;
    case 0x802CE5D4u: goto label_802CE5D4;
    case 0x802CE5D8u: goto label_802CE5D8;
    case 0x802CE5DCu: goto label_802CE5DC;
    case 0x802CE5E0u: goto label_802CE5E0;
    case 0x802CE5E4u: goto label_802CE5E4;
    case 0x802CE5E8u: goto label_802CE5E8;
    case 0x802CE5ECu: goto label_802CE5EC;
    case 0x802CE5F0u: goto label_802CE5F0;
    case 0x802CE5F4u: goto label_802CE5F4;
    case 0x802CE5F8u: goto label_802CE5F8;
    case 0x802CE5FCu: goto label_802CE5FC;
    case 0x802CE600u: goto label_802CE600;
    case 0x802CE604u: goto label_802CE604;
    case 0x802CE608u: goto label_802CE608;
    case 0x802CE60Cu: goto label_802CE60C;
    case 0x802CE610u: goto label_802CE610;
    case 0x802CE614u: goto label_802CE614;
    case 0x802CE618u: goto label_802CE618;
    case 0x802CE61Cu: goto label_802CE61C;
    case 0x802CE620u: goto label_802CE620;
    case 0x802CE624u: goto label_802CE624;
    case 0x802CE628u: goto label_802CE628;
    case 0x802CE62Cu: goto label_802CE62C;
    case 0x802CE630u: goto label_802CE630;
    case 0x802CE634u: goto label_802CE634;
    case 0x802CE638u: goto label_802CE638;
    case 0x802CE63Cu: goto label_802CE63C;
    case 0x802CE640u: goto label_802CE640;
    case 0x802CE644u: goto label_802CE644;
    case 0x802CE648u: goto label_802CE648;
    case 0x802CE64Cu: goto label_802CE64C;
    case 0x802CE650u: goto label_802CE650;
    case 0x802CE654u: goto label_802CE654;
    case 0x802CE658u: goto label_802CE658;
    case 0x802CE65Cu: goto label_802CE65C;
    case 0x802CE660u: goto label_802CE660;
    case 0x802CE664u: goto label_802CE664;
    case 0x802CE668u: goto label_802CE668;
    case 0x802CE66Cu: goto label_802CE66C;
    case 0x802CE670u: goto label_802CE670;
    case 0x802CE674u: goto label_802CE674;
    case 0x802CE678u: goto label_802CE678;
    case 0x802CE67Cu: goto label_802CE67C;
    case 0x802CE680u: goto label_802CE680;
    case 0x802CE684u: goto label_802CE684;
    case 0x802CE688u: goto label_802CE688;
    case 0x802CE68Cu: goto label_802CE68C;
    case 0x802CE690u: goto label_802CE690;
    case 0x802CE694u: goto label_802CE694;
    case 0x802CE698u: goto label_802CE698;
    case 0x802CE69Cu: goto label_802CE69C;
    case 0x802CE6A0u: goto label_802CE6A0;
    case 0x802CE6A4u: goto label_802CE6A4;
    case 0x802CE6A8u: goto label_802CE6A8;
    case 0x802CE6ACu: goto label_802CE6AC;
    case 0x802CE6B0u: goto label_802CE6B0;
    case 0x802CE6B4u: goto label_802CE6B4;
    case 0x802CE6B8u: goto label_802CE6B8;
    case 0x802CE6BCu: goto label_802CE6BC;
    case 0x802CE6C0u: goto label_802CE6C0;
    case 0x802CE6C4u: goto label_802CE6C4;
    case 0x802CE6C8u: goto label_802CE6C8;
    case 0x802CE6CCu: goto label_802CE6CC;
    case 0x802CE6D0u: goto label_802CE6D0;
    case 0x802CE6D4u: goto label_802CE6D4;
    case 0x802CE6D8u: goto label_802CE6D8;
    case 0x802CE6DCu: goto label_802CE6DC;
    case 0x802CE6E0u: goto label_802CE6E0;
    case 0x802CE6E4u: goto label_802CE6E4;
    case 0x802CE6E8u: goto label_802CE6E8;
    case 0x802CE6ECu: goto label_802CE6EC;
    case 0x802CE6F0u: goto label_802CE6F0;
    case 0x802CE6F4u: goto label_802CE6F4;
    case 0x802CE6F8u: goto label_802CE6F8;
    case 0x802CE6FCu: goto label_802CE6FC;
    case 0x802CE700u: goto label_802CE700;
    case 0x802CE704u: goto label_802CE704;
    case 0x802CE708u: goto label_802CE708;
    case 0x802CE70Cu: goto label_802CE70C;
    case 0x802CE710u: goto label_802CE710;
    case 0x802CE714u: goto label_802CE714;
    case 0x802CE718u: goto label_802CE718;
    case 0x802CE71Cu: goto label_802CE71C;
    case 0x802CE720u: goto label_802CE720;
    case 0x802CE724u: goto label_802CE724;
    case 0x802CE728u: goto label_802CE728;
    case 0x802CE72Cu: goto label_802CE72C;
    case 0x802CE730u: goto label_802CE730;
    case 0x802CE734u: goto label_802CE734;
    case 0x802CE738u: goto label_802CE738;
    case 0x802CE73Cu: goto label_802CE73C;
    case 0x802CE740u: goto label_802CE740;
    case 0x802CE744u: goto label_802CE744;
    case 0x802CE748u: goto label_802CE748;
    case 0x802CE74Cu: goto label_802CE74C;
    case 0x802CE750u: goto label_802CE750;
    case 0x802CE754u: goto label_802CE754;
    case 0x802CE758u: goto label_802CE758;
    case 0x802CE75Cu: goto label_802CE75C;
    case 0x802CE760u: goto label_802CE760;
    case 0x802CE764u: goto label_802CE764;
    case 0x802CE768u: goto label_802CE768;
    case 0x802CE76Cu: goto label_802CE76C;
    case 0x802CE770u: goto label_802CE770;
    case 0x802CE774u: goto label_802CE774;
    case 0x802CE778u: goto label_802CE778;
    case 0x802CE77Cu: goto label_802CE77C;
    case 0x802CE780u: goto label_802CE780;
    case 0x802CE784u: goto label_802CE784;
    case 0x802CE788u: goto label_802CE788;
    case 0x802CE78Cu: goto label_802CE78C;
    case 0x802CE790u: goto label_802CE790;
    case 0x802CE794u: goto label_802CE794;
    case 0x802CE798u: goto label_802CE798;
    case 0x802CE79Cu: goto label_802CE79C;
    case 0x802CE7A0u: goto label_802CE7A0;
    case 0x802CE7A4u: goto label_802CE7A4;
    case 0x802CE7A8u: goto label_802CE7A8;
    case 0x802CE7ACu: goto label_802CE7AC;
    case 0x802CE7B0u: goto label_802CE7B0;
    case 0x802CE7B4u: goto label_802CE7B4;
    case 0x802CE7B8u: goto label_802CE7B8;
    case 0x802CE7BCu: goto label_802CE7BC;
    case 0x802CE7C0u: goto label_802CE7C0;
    case 0x802CE7C4u: goto label_802CE7C4;
    case 0x802CE7C8u: goto label_802CE7C8;
    case 0x802CE7CCu: goto label_802CE7CC;
    case 0x802CE7D0u: goto label_802CE7D0;
    case 0x802CE7D4u: goto label_802CE7D4;
    case 0x802CE7D8u: goto label_802CE7D8;
    case 0x802CE7DCu: goto label_802CE7DC;
    case 0x802CE7E0u: goto label_802CE7E0;
    case 0x802CE7E4u: goto label_802CE7E4;
    case 0x802CE7E8u: goto label_802CE7E8;
    case 0x802CE7ECu: goto label_802CE7EC;
    case 0x802CE7F0u: goto label_802CE7F0;
    case 0x802CE7F4u: goto label_802CE7F4;
    case 0x802CE7F8u: goto label_802CE7F8;
    case 0x802CE7FCu: goto label_802CE7FC;
    case 0x802CE800u: goto label_802CE800;
    case 0x802CE804u: goto label_802CE804;
    case 0x802CE808u: goto label_802CE808;
    case 0x802CE80Cu: goto label_802CE80C;
    case 0x802CE810u: goto label_802CE810;
    case 0x802CE814u: goto label_802CE814;
    case 0x802CE818u: goto label_802CE818;
    case 0x802CE81Cu: goto label_802CE81C;
    case 0x802CE820u: goto label_802CE820;
    case 0x802CE824u: goto label_802CE824;
    case 0x802CE828u: goto label_802CE828;
    case 0x802CE82Cu: goto label_802CE82C;
    case 0x802CE830u: goto label_802CE830;
    case 0x802CE834u: goto label_802CE834;
    case 0x802CE838u: goto label_802CE838;
    case 0x802CE83Cu: goto label_802CE83C;
    case 0x802CE840u: goto label_802CE840;
    case 0x802CE844u: goto label_802CE844;
    case 0x802CE848u: goto label_802CE848;
    case 0x802CE84Cu: goto label_802CE84C;
    case 0x802CE850u: goto label_802CE850;
    case 0x802CE854u: goto label_802CE854;
    case 0x802CE858u: goto label_802CE858;
    case 0x802CE85Cu: goto label_802CE85C;
    case 0x802CE860u: goto label_802CE860;
    case 0x802CE864u: goto label_802CE864;
    case 0x802CE868u: goto label_802CE868;
    case 0x802CE86Cu: goto label_802CE86C;
    case 0x802CE870u: goto label_802CE870;
    case 0x802CE874u: goto label_802CE874;
    case 0x802CE878u: goto label_802CE878;
    case 0x802CE87Cu: goto label_802CE87C;
    case 0x802CE880u: goto label_802CE880;
    case 0x802CE884u: goto label_802CE884;
    case 0x802CE888u: goto label_802CE888;
    case 0x802CE88Cu: goto label_802CE88C;
    case 0x802CE890u: goto label_802CE890;
    case 0x802CE894u: goto label_802CE894;
    case 0x802CE898u: goto label_802CE898;
    case 0x802CE89Cu: goto label_802CE89C;
    case 0x802CE8A0u: goto label_802CE8A0;
    case 0x802CE8A4u: goto label_802CE8A4;
    case 0x802CE8A8u: goto label_802CE8A8;
    case 0x802CE8ACu: goto label_802CE8AC;
    case 0x802CE8B0u: goto label_802CE8B0;
    case 0x802CE8B4u: goto label_802CE8B4;
    case 0x802CE8B8u: goto label_802CE8B8;
    case 0x802CE8BCu: goto label_802CE8BC;
    case 0x802CE8C0u: goto label_802CE8C0;
    case 0x802CE8C4u: goto label_802CE8C4;
    case 0x802CE8C8u: goto label_802CE8C8;
    case 0x802CE8CCu: goto label_802CE8CC;
    case 0x802CE8D0u: goto label_802CE8D0;
    case 0x802CE8D4u: goto label_802CE8D4;
    case 0x802CE8D8u: goto label_802CE8D8;
    case 0x802CE8DCu: goto label_802CE8DC;
    case 0x802CE8E0u: goto label_802CE8E0;
    case 0x802CE8E4u: goto label_802CE8E4;
    case 0x802CE8E8u: goto label_802CE8E8;
    case 0x802CE8ECu: goto label_802CE8EC;
    case 0x802CE8F0u: goto label_802CE8F0;
    case 0x802CE8F4u: goto label_802CE8F4;
    case 0x802CE8F8u: goto label_802CE8F8;
    case 0x802CE8FCu: goto label_802CE8FC;
    case 0x802CE900u: goto label_802CE900;
    case 0x802CE904u: goto label_802CE904;
    case 0x802CE908u: goto label_802CE908;
    case 0x802CE90Cu: goto label_802CE90C;
    case 0x802CE910u: goto label_802CE910;
    case 0x802CE914u: goto label_802CE914;
    case 0x802CE918u: goto label_802CE918;
    case 0x802CE91Cu: goto label_802CE91C;
    case 0x802CE920u: goto label_802CE920;
    case 0x802CE924u: goto label_802CE924;
    case 0x802CE928u: goto label_802CE928;
    case 0x802CE92Cu: goto label_802CE92C;
    case 0x802CE930u: goto label_802CE930;
    case 0x802CE934u: goto label_802CE934;
    case 0x802CE938u: goto label_802CE938;
    case 0x802CE93Cu: goto label_802CE93C;
    case 0x802CE940u: goto label_802CE940;
    case 0x802CE944u: goto label_802CE944;
    case 0x802CE948u: goto label_802CE948;
    case 0x802CE94Cu: goto label_802CE94C;
    case 0x802CE950u: goto label_802CE950;
    case 0x802CE954u: goto label_802CE954;
    case 0x802CE958u: goto label_802CE958;
    case 0x802CE95Cu: goto label_802CE95C;
    case 0x802CE960u: goto label_802CE960;
    case 0x802CE964u: goto label_802CE964;
    case 0x802CE968u: goto label_802CE968;
    case 0x802CE96Cu: goto label_802CE96C;
    case 0x802CE970u: goto label_802CE970;
    case 0x802CE974u: goto label_802CE974;
    case 0x802CE978u: goto label_802CE978;
    case 0x802CE97Cu: goto label_802CE97C;
    case 0x802CE980u: goto label_802CE980;
    case 0x802CE984u: goto label_802CE984;
    case 0x802CE988u: goto label_802CE988;
    case 0x802CE98Cu: goto label_802CE98C;
    case 0x802CE990u: goto label_802CE990;
    case 0x802CE994u: goto label_802CE994;
    case 0x802CE998u: goto label_802CE998;
    case 0x802CE99Cu: goto label_802CE99C;
    case 0x802CE9A0u: goto label_802CE9A0;
    case 0x802CE9A4u: goto label_802CE9A4;
    case 0x802CE9A8u: goto label_802CE9A8;
    case 0x802CE9ACu: goto label_802CE9AC;
    case 0x802CE9B0u: goto label_802CE9B0;
    case 0x802CE9B4u: goto label_802CE9B4;
    case 0x802CE9B8u: goto label_802CE9B8;
    case 0x802CE9BCu: goto label_802CE9BC;
    case 0x802CE9C0u: goto label_802CE9C0;
    case 0x802CE9C4u: goto label_802CE9C4;
    case 0x802CE9C8u: goto label_802CE9C8;
    case 0x802CE9CCu: goto label_802CE9CC;
    case 0x802CE9D0u: goto label_802CE9D0;
    case 0x802CE9D4u: goto label_802CE9D4;
    case 0x802CE9D8u: goto label_802CE9D8;
    case 0x802CE9DCu: goto label_802CE9DC;
    case 0x802CE9E0u: goto label_802CE9E0;
    case 0x802CE9E4u: goto label_802CE9E4;
    case 0x802CE9E8u: goto label_802CE9E8;
    case 0x802CE9ECu: goto label_802CE9EC;
    case 0x802CE9F0u: goto label_802CE9F0;
    case 0x802CE9F4u: goto label_802CE9F4;
    case 0x802CE9F8u: goto label_802CE9F8;
    case 0x802CE9FCu: goto label_802CE9FC;
    case 0x802CEA00u: goto label_802CEA00;
    case 0x802CEA04u: goto label_802CEA04;
    case 0x802CEA08u: goto label_802CEA08;
    case 0x802CEA0Cu: goto label_802CEA0C;
    case 0x802CEA10u: goto label_802CEA10;
    case 0x802CEA14u: goto label_802CEA14;
    case 0x802CEA18u: goto label_802CEA18;
    case 0x802CEA1Cu: goto label_802CEA1C;
    case 0x802CEA20u: goto label_802CEA20;
    case 0x802CEA24u: goto label_802CEA24;
    case 0x802CEA28u: goto label_802CEA28;
    case 0x802CEA2Cu: goto label_802CEA2C;
    case 0x802CEA30u: goto label_802CEA30;
    case 0x802CEA34u: goto label_802CEA34;
    case 0x802CEA38u: goto label_802CEA38;
    case 0x802CEA3Cu: goto label_802CEA3C;
    case 0x802CEA40u: goto label_802CEA40;
    case 0x802CEA44u: goto label_802CEA44;
    case 0x802CEA48u: goto label_802CEA48;
    case 0x802CEA4Cu: goto label_802CEA4C;
    case 0x802CEA50u: goto label_802CEA50;
    case 0x802CEA54u: goto label_802CEA54;
    case 0x802CEA58u: goto label_802CEA58;
    case 0x802CEA5Cu: goto label_802CEA5C;
    case 0x802CEA60u: goto label_802CEA60;
    case 0x802CEA64u: goto label_802CEA64;
    case 0x802CEA68u: goto label_802CEA68;
    case 0x802CEA6Cu: goto label_802CEA6C;
    case 0x802CEA70u: goto label_802CEA70;
    case 0x802CEA74u: goto label_802CEA74;
    case 0x802CEA78u: goto label_802CEA78;
    case 0x802CEA7Cu: goto label_802CEA7C;
    case 0x802CEA80u: goto label_802CEA80;
    case 0x802CEA84u: goto label_802CEA84;
    case 0x802CEA88u: goto label_802CEA88;
    case 0x802CEA8Cu: goto label_802CEA8C;
    case 0x802CEA90u: goto label_802CEA90;
    case 0x802CEA94u: goto label_802CEA94;
    case 0x802CEA98u: goto label_802CEA98;
    case 0x802CEA9Cu: goto label_802CEA9C;
    case 0x802CEAA0u: goto label_802CEAA0;
    case 0x802CEAA4u: goto label_802CEAA4;
    case 0x802CEAA8u: goto label_802CEAA8;
    case 0x802CEAACu: goto label_802CEAAC;
    case 0x802CEAB0u: goto label_802CEAB0;
    case 0x802CEAB4u: goto label_802CEAB4;
    case 0x802CEAB8u: goto label_802CEAB8;
    case 0x802CEABCu: goto label_802CEABC;
    case 0x802CEAC0u: goto label_802CEAC0;
    case 0x802CEAC4u: goto label_802CEAC4;
    case 0x802CEAC8u: goto label_802CEAC8;
    case 0x802CEACCu: goto label_802CEACC;
    case 0x802CEAD0u: goto label_802CEAD0;
    case 0x802CEAD4u: goto label_802CEAD4;
    case 0x802CEAD8u: goto label_802CEAD8;
    case 0x802CEADCu: goto label_802CEADC;
    case 0x802CEAE0u: goto label_802CEAE0;
    case 0x802CEAE4u: goto label_802CEAE4;
    case 0x802CEAE8u: goto label_802CEAE8;
    case 0x802CEAECu: goto label_802CEAEC;
    case 0x802CEAF0u: goto label_802CEAF0;
    case 0x802CEAF4u: goto label_802CEAF4;
    case 0x802CEAF8u: goto label_802CEAF8;
    case 0x802CEAFCu: goto label_802CEAFC;
    case 0x802CEB00u: goto label_802CEB00;
    case 0x802CEB04u: goto label_802CEB04;
    case 0x802CEB08u: goto label_802CEB08;
    case 0x802CEB0Cu: goto label_802CEB0C;
    case 0x802CEB10u: goto label_802CEB10;
    case 0x802CEB14u: goto label_802CEB14;
    case 0x802CEB18u: goto label_802CEB18;
    case 0x802CEB1Cu: goto label_802CEB1C;
    case 0x802CEB20u: goto label_802CEB20;
    case 0x802CEB24u: goto label_802CEB24;
    case 0x802CEB28u: goto label_802CEB28;
    case 0x802CEB2Cu: goto label_802CEB2C;
    case 0x802CEB30u: goto label_802CEB30;
    case 0x802CEB34u: goto label_802CEB34;
    case 0x802CEB38u: goto label_802CEB38;
    case 0x802CEB3Cu: goto label_802CEB3C;
    case 0x802CEB40u: goto label_802CEB40;
    case 0x802CEB44u: goto label_802CEB44;
    case 0x802CEB48u: goto label_802CEB48;
    case 0x802CEB4Cu: goto label_802CEB4C;
    case 0x802CEB50u: goto label_802CEB50;
    case 0x802CEB54u: goto label_802CEB54;
    case 0x802CEB58u: goto label_802CEB58;
    case 0x802CEB5Cu: goto label_802CEB5C;
    case 0x802CEB60u: goto label_802CEB60;
    case 0x802CEB64u: goto label_802CEB64;
    case 0x802CEB68u: goto label_802CEB68;
    case 0x802CEB6Cu: goto label_802CEB6C;
    case 0x802CEB70u: goto label_802CEB70;
    case 0x802CEB74u: goto label_802CEB74;
    case 0x802CEB78u: goto label_802CEB78;
    case 0x802CEB7Cu: goto label_802CEB7C;
    case 0x802CEB80u: goto label_802CEB80;
    case 0x802CEB84u: goto label_802CEB84;
    case 0x802CEB88u: goto label_802CEB88;
    case 0x802CEB8Cu: goto label_802CEB8C;
    case 0x802CEB90u: goto label_802CEB90;
    case 0x802CEB94u: goto label_802CEB94;
    case 0x802CEB98u: goto label_802CEB98;
    case 0x802CEB9Cu: goto label_802CEB9C;
    case 0x802CEBA0u: goto label_802CEBA0;
    case 0x802CEBA4u: goto label_802CEBA4;
    case 0x802CEBA8u: goto label_802CEBA8;
    case 0x802CEBACu: goto label_802CEBAC;
    case 0x802CEBB0u: goto label_802CEBB0;
    case 0x802CEBB4u: goto label_802CEBB4;
    case 0x802CEBB8u: goto label_802CEBB8;
    case 0x802CEBBCu: goto label_802CEBBC;
    case 0x802CEBC0u: goto label_802CEBC0;
    case 0x802CEBC4u: goto label_802CEBC4;
    case 0x802CEBC8u: goto label_802CEBC8;
    case 0x802CEBCCu: goto label_802CEBCC;
    case 0x802CEBD0u: goto label_802CEBD0;
    case 0x802CEBD4u: goto label_802CEBD4;
    case 0x802CEBD8u: goto label_802CEBD8;
    case 0x802CEBDCu: goto label_802CEBDC;
    case 0x802CEBE0u: goto label_802CEBE0;
    case 0x802CEBE4u: goto label_802CEBE4;
    case 0x802CEBE8u: goto label_802CEBE8;
    case 0x802CEBECu: goto label_802CEBEC;
    case 0x802CEBF0u: goto label_802CEBF0;
    case 0x802CEBF4u: goto label_802CEBF4;
    case 0x802CEBF8u: goto label_802CEBF8;
    case 0x802CEBFCu: goto label_802CEBFC;
    case 0x802CEC00u: goto label_802CEC00;
    case 0x802CEC04u: goto label_802CEC04;
    case 0x802CEC08u: goto label_802CEC08;
    case 0x802CEC0Cu: goto label_802CEC0C;
    case 0x802CEC10u: goto label_802CEC10;
    case 0x802CEC14u: goto label_802CEC14;
    case 0x802CEC18u: goto label_802CEC18;
    case 0x802CEC1Cu: goto label_802CEC1C;
    case 0x802CEC20u: goto label_802CEC20;
    case 0x802CEC24u: goto label_802CEC24;
    case 0x802CEC28u: goto label_802CEC28;
    case 0x802CEC2Cu: goto label_802CEC2C;
    case 0x802CEC30u: goto label_802CEC30;
    case 0x802CEC34u: goto label_802CEC34;
    case 0x802CEC38u: goto label_802CEC38;
    case 0x802CEC3Cu: goto label_802CEC3C;
    case 0x802CEC40u: goto label_802CEC40;
    case 0x802CEC44u: goto label_802CEC44;
    case 0x802CEC48u: goto label_802CEC48;
    case 0x802CEC4Cu: goto label_802CEC4C;
    case 0x802CEC50u: goto label_802CEC50;
    case 0x802CEC54u: goto label_802CEC54;
    case 0x802CEC58u: goto label_802CEC58;
    case 0x802CEC5Cu: goto label_802CEC5C;
    case 0x802CEC60u: goto label_802CEC60;
    case 0x802CEC64u: goto label_802CEC64;
    case 0x802CEC68u: goto label_802CEC68;
    case 0x802CEC6Cu: goto label_802CEC6C;
    case 0x802CEC70u: goto label_802CEC70;
    case 0x802CEC74u: goto label_802CEC74;
    case 0x802CEC78u: goto label_802CEC78;
    case 0x802CEC7Cu: goto label_802CEC7C;
    case 0x802CEC80u: goto label_802CEC80;
    case 0x802CEC84u: goto label_802CEC84;
    case 0x802CEC88u: goto label_802CEC88;
    case 0x802CEC8Cu: goto label_802CEC8C;
    case 0x802CEC90u: goto label_802CEC90;
    case 0x802CEC94u: goto label_802CEC94;
    case 0x802CEC98u: goto label_802CEC98;
    case 0x802CEC9Cu: goto label_802CEC9C;
    case 0x802CECA0u: goto label_802CECA0;
    case 0x802CECA4u: goto label_802CECA4;
    case 0x802CECA8u: goto label_802CECA8;
    case 0x802CECACu: goto label_802CECAC;
    case 0x802CECB0u: goto label_802CECB0;
    case 0x802CECB4u: goto label_802CECB4;
    case 0x802CECB8u: goto label_802CECB8;
    case 0x802CECBCu: goto label_802CECBC;
    case 0x802CECC0u: goto label_802CECC0;
    case 0x802CECC4u: goto label_802CECC4;
    case 0x802CECC8u: goto label_802CECC8;
    case 0x802CECCCu: goto label_802CECCC;
    case 0x802CECD0u: goto label_802CECD0;
    case 0x802CECD4u: goto label_802CECD4;
    case 0x802CECD8u: goto label_802CECD8;
    case 0x802CECDCu: goto label_802CECDC;
    case 0x802CECE0u: goto label_802CECE0;
    case 0x802CECE4u: goto label_802CECE4;
    case 0x802CECE8u: goto label_802CECE8;
    case 0x802CECECu: goto label_802CECEC;
    case 0x802CECF0u: goto label_802CECF0;
    case 0x802CECF4u: goto label_802CECF4;
    case 0x802CECF8u: goto label_802CECF8;
    case 0x802CECFCu: goto label_802CECFC;
    case 0x802CED00u: goto label_802CED00;
    case 0x802CED04u: goto label_802CED04;
    case 0x802CED08u: goto label_802CED08;
    case 0x802CED0Cu: goto label_802CED0C;
    case 0x802CED10u: goto label_802CED10;
    case 0x802CED14u: goto label_802CED14;
    case 0x802CED18u: goto label_802CED18;
    case 0x802CED1Cu: goto label_802CED1C;
    case 0x802CED20u: goto label_802CED20;
    case 0x802CED24u: goto label_802CED24;
    case 0x802CED28u: goto label_802CED28;
    case 0x802CED2Cu: goto label_802CED2C;
    case 0x802CED30u: goto label_802CED30;
    case 0x802CED34u: goto label_802CED34;
    case 0x802CED38u: goto label_802CED38;
    case 0x802CED3Cu: goto label_802CED3C;
    case 0x802CED40u: goto label_802CED40;
    case 0x802CED44u: goto label_802CED44;
    case 0x802CED48u: goto label_802CED48;
    case 0x802CED4Cu: goto label_802CED4C;
    case 0x802CED50u: goto label_802CED50;
    case 0x802CED54u: goto label_802CED54;
    case 0x802CED58u: goto label_802CED58;
    case 0x802CED5Cu: goto label_802CED5C;
    case 0x802CED60u: goto label_802CED60;
    case 0x802CED64u: goto label_802CED64;
    case 0x802CED68u: goto label_802CED68;
    case 0x802CED6Cu: goto label_802CED6C;
    case 0x802CED70u: goto label_802CED70;
    case 0x802CED74u: goto label_802CED74;
    case 0x802CED78u: goto label_802CED78;
    case 0x802CED7Cu: goto label_802CED7C;
    case 0x802CED80u: goto label_802CED80;
    case 0x802CED84u: goto label_802CED84;
    case 0x802CED88u: goto label_802CED88;
    case 0x802CED8Cu: goto label_802CED8C;
    case 0x802CED90u: goto label_802CED90;
    case 0x802CED94u: goto label_802CED94;
    case 0x802CED98u: goto label_802CED98;
    case 0x802CED9Cu: goto label_802CED9C;
    case 0x802CEDA0u: goto label_802CEDA0;
    case 0x802CEDA4u: goto label_802CEDA4;
    case 0x802CEDA8u: goto label_802CEDA8;
    case 0x802CEDACu: goto label_802CEDAC;
    case 0x802CEDB0u: goto label_802CEDB0;
    case 0x802CEDB4u: goto label_802CEDB4;
    case 0x802CEDB8u: goto label_802CEDB8;
    case 0x802CEDBCu: goto label_802CEDBC;
    case 0x802CEDC0u: goto label_802CEDC0;
    case 0x802CEDC4u: goto label_802CEDC4;
    case 0x802CEDC8u: goto label_802CEDC8;
    case 0x802CEDCCu: goto label_802CEDCC;
    case 0x802CEDD0u: goto label_802CEDD0;
    case 0x802CEDD4u: goto label_802CEDD4;
    case 0x802CEDD8u: goto label_802CEDD8;
    case 0x802CEDDCu: goto label_802CEDDC;
    case 0x802CEDE0u: goto label_802CEDE0;
    case 0x802CEDE4u: goto label_802CEDE4;
    case 0x802CEDE8u: goto label_802CEDE8;
    case 0x802CEDECu: goto label_802CEDEC;
    case 0x802CEDF0u: goto label_802CEDF0;
    case 0x802CEDF4u: goto label_802CEDF4;
    case 0x802CEDF8u: goto label_802CEDF8;
    case 0x802CEDFCu: goto label_802CEDFC;
    case 0x802CEE00u: goto label_802CEE00;
    case 0x802CEE04u: goto label_802CEE04;
    case 0x802CEE08u: goto label_802CEE08;
    case 0x802CEE0Cu: goto label_802CEE0C;
    case 0x802CEE10u: goto label_802CEE10;
    case 0x802CEE14u: goto label_802CEE14;
    case 0x802CEE18u: goto label_802CEE18;
    case 0x802CEE1Cu: goto label_802CEE1C;
    case 0x802CEE20u: goto label_802CEE20;
    case 0x802CEE24u: goto label_802CEE24;
    case 0x802CEE28u: goto label_802CEE28;
    case 0x802CEE2Cu: goto label_802CEE2C;
    case 0x802CEE30u: goto label_802CEE30;
    case 0x802CEE34u: goto label_802CEE34;
    case 0x802CEE38u: goto label_802CEE38;
    case 0x802CEE3Cu: goto label_802CEE3C;
    case 0x802CEE40u: goto label_802CEE40;
    case 0x802CEE44u: goto label_802CEE44;
    case 0x802CEE48u: goto label_802CEE48;
    case 0x802CEE4Cu: goto label_802CEE4C;
    case 0x802CEE50u: goto label_802CEE50;
    case 0x802CEE54u: goto label_802CEE54;
    case 0x802CEE58u: goto label_802CEE58;
    case 0x802CEE5Cu: goto label_802CEE5C;
    case 0x802CEE60u: goto label_802CEE60;
    case 0x802CEE64u: goto label_802CEE64;
    case 0x802CEE68u: goto label_802CEE68;
    case 0x802CEE6Cu: goto label_802CEE6C;
    case 0x802CEE70u: goto label_802CEE70;
    case 0x802CEE74u: goto label_802CEE74;
    case 0x802CEE78u: goto label_802CEE78;
    case 0x802CEE7Cu: goto label_802CEE7C;
    case 0x802CEE80u: goto label_802CEE80;
    case 0x802CEE84u: goto label_802CEE84;
    case 0x802CEE88u: goto label_802CEE88;
    case 0x802CEE8Cu: goto label_802CEE8C;
    case 0x802CEE90u: goto label_802CEE90;
    case 0x802CEE94u: goto label_802CEE94;
    case 0x802CEE98u: goto label_802CEE98;
    case 0x802CEE9Cu: goto label_802CEE9C;
    case 0x802CEEA0u: goto label_802CEEA0;
    case 0x802CEEA4u: goto label_802CEEA4;
    case 0x802CEEA8u: goto label_802CEEA8;
    case 0x802CEEACu: goto label_802CEEAC;
    case 0x802CEEB0u: goto label_802CEEB0;
    case 0x802CEEB4u: goto label_802CEEB4;
    case 0x802CEEB8u: goto label_802CEEB8;
    case 0x802CEEBCu: goto label_802CEEBC;
    case 0x802CEEC0u: goto label_802CEEC0;
    case 0x802CEEC4u: goto label_802CEEC4;
    case 0x802CEEC8u: goto label_802CEEC8;
    case 0x802CEECCu: goto label_802CEECC;
    case 0x802CEED0u: goto label_802CEED0;
    case 0x802CEED4u: goto label_802CEED4;
    case 0x802CEED8u: goto label_802CEED8;
    case 0x802CEEDCu: goto label_802CEEDC;
    case 0x802CEEE0u: goto label_802CEEE0;
    case 0x802CEEE4u: goto label_802CEEE4;
    case 0x802CEEE8u: goto label_802CEEE8;
    case 0x802CEEECu: goto label_802CEEEC;
    case 0x802CEEF0u: goto label_802CEEF0;
    case 0x802CEEF4u: goto label_802CEEF4;
    case 0x802CEEF8u: goto label_802CEEF8;
    case 0x802CEEFCu: goto label_802CEEFC;
    case 0x802CEF00u: goto label_802CEF00;
    case 0x802CEF04u: goto label_802CEF04;
    case 0x802CEF08u: goto label_802CEF08;
    case 0x802CEF0Cu: goto label_802CEF0C;
    case 0x802CEF10u: goto label_802CEF10;
    case 0x802CEF14u: goto label_802CEF14;
    case 0x802CEF18u: goto label_802CEF18;
    case 0x802CEF1Cu: goto label_802CEF1C;
    case 0x802CEF20u: goto label_802CEF20;
    case 0x802CEF24u: goto label_802CEF24;
    case 0x802CEF28u: goto label_802CEF28;
    case 0x802CEF2Cu: goto label_802CEF2C;
    case 0x802CEF30u: goto label_802CEF30;
    case 0x802CEF34u: goto label_802CEF34;
    case 0x802CEF38u: goto label_802CEF38;
    case 0x802CEF3Cu: goto label_802CEF3C;
    case 0x802CEF40u: goto label_802CEF40;
    case 0x802CEF44u: goto label_802CEF44;
    case 0x802CEF48u: goto label_802CEF48;
    case 0x802CEF4Cu: goto label_802CEF4C;
    case 0x802CEF50u: goto label_802CEF50;
    case 0x802CEF54u: goto label_802CEF54;
    case 0x802CEF58u: goto label_802CEF58;
    case 0x802CEF5Cu: goto label_802CEF5C;
    case 0x802CEF60u: goto label_802CEF60;
    case 0x802CEF64u: goto label_802CEF64;
    case 0x802CEF68u: goto label_802CEF68;
    case 0x802CEF6Cu: goto label_802CEF6C;
    case 0x802CEF70u: goto label_802CEF70;
    case 0x802CEF74u: goto label_802CEF74;
    case 0x802CEF78u: goto label_802CEF78;
    case 0x802CEF7Cu: goto label_802CEF7C;
    case 0x802CEF80u: goto label_802CEF80;
    case 0x802CEF84u: goto label_802CEF84;
    case 0x802CEF88u: goto label_802CEF88;
    case 0x802CEF8Cu: goto label_802CEF8C;
    case 0x802CEF90u: goto label_802CEF90;
    case 0x802CEF94u: goto label_802CEF94;
    case 0x802CEF98u: goto label_802CEF98;
    case 0x802CEF9Cu: goto label_802CEF9C;
    case 0x802CEFA0u: goto label_802CEFA0;
    case 0x802CEFA4u: goto label_802CEFA4;
    case 0x802CEFA8u: goto label_802CEFA8;
    case 0x802CEFACu: goto label_802CEFAC;
    case 0x802CEFB0u: goto label_802CEFB0;
    case 0x802CEFB4u: goto label_802CEFB4;
    case 0x802CEFB8u: goto label_802CEFB8;
    case 0x802CEFBCu: goto label_802CEFBC;
    case 0x802CEFC0u: goto label_802CEFC0;
    case 0x802CEFC4u: goto label_802CEFC4;
    case 0x802CEFC8u: goto label_802CEFC8;
    case 0x802CEFCCu: goto label_802CEFCC;
    case 0x802CEFD0u: goto label_802CEFD0;
    case 0x802CEFD4u: goto label_802CEFD4;
    case 0x802CEFD8u: goto label_802CEFD8;
    case 0x802CEFDCu: goto label_802CEFDC;
    case 0x802CEFE0u: goto label_802CEFE0;
    case 0x802CEFE4u: goto label_802CEFE4;
    case 0x802CEFE8u: goto label_802CEFE8;
    case 0x802CEFECu: goto label_802CEFEC;
    case 0x802CEFF0u: goto label_802CEFF0;
    case 0x802CEFF4u: goto label_802CEFF4;
    case 0x802CEFF8u: goto label_802CEFF8;
    case 0x802CEFFCu: goto label_802CEFFC;
    case 0x802CF000u: goto label_802CF000;
    case 0x802CF004u: goto label_802CF004;
    case 0x802CF008u: goto label_802CF008;
    case 0x802CF00Cu: goto label_802CF00C;
    case 0x802CF010u: goto label_802CF010;
    case 0x802CF014u: goto label_802CF014;
    case 0x802CF018u: goto label_802CF018;
    case 0x802CF01Cu: goto label_802CF01C;
    case 0x802CF020u: goto label_802CF020;
    case 0x802CF024u: goto label_802CF024;
    case 0x802CF028u: goto label_802CF028;
    case 0x802CF02Cu: goto label_802CF02C;
    case 0x802CF030u: goto label_802CF030;
    case 0x802CF034u: goto label_802CF034;
    case 0x802CF038u: goto label_802CF038;
    case 0x802CF03Cu: goto label_802CF03C;
    case 0x802CF040u: goto label_802CF040;
    case 0x802CF044u: goto label_802CF044;
    case 0x802CF048u: goto label_802CF048;
    case 0x802CF04Cu: goto label_802CF04C;
    case 0x802CF050u: goto label_802CF050;
    case 0x802CF054u: goto label_802CF054;
    case 0x802CF058u: goto label_802CF058;
    case 0x802CF05Cu: goto label_802CF05C;
    case 0x802CF060u: goto label_802CF060;
    case 0x802CF064u: goto label_802CF064;
    case 0x802CF068u: goto label_802CF068;
    case 0x802CF06Cu: goto label_802CF06C;
    case 0x802CF070u: goto label_802CF070;
    case 0x802CF074u: goto label_802CF074;
    case 0x802CF078u: goto label_802CF078;
    case 0x802CF07Cu: goto label_802CF07C;
    case 0x802CF080u: goto label_802CF080;
    case 0x802CF084u: goto label_802CF084;
    case 0x802CF088u: goto label_802CF088;
    case 0x802CF08Cu: goto label_802CF08C;
    case 0x802CF090u: goto label_802CF090;
    case 0x802CF094u: goto label_802CF094;
    case 0x802CF098u: goto label_802CF098;
    case 0x802CF09Cu: goto label_802CF09C;
    case 0x802CF0A0u: goto label_802CF0A0;
    case 0x802CF0A4u: goto label_802CF0A4;
    case 0x802CF0A8u: goto label_802CF0A8;
    case 0x802CF0ACu: goto label_802CF0AC;
    case 0x802CF0B0u: goto label_802CF0B0;
    case 0x802CF0B4u: goto label_802CF0B4;
    case 0x802CF0B8u: goto label_802CF0B8;
    case 0x802CF0BCu: goto label_802CF0BC;
    case 0x802CF0C0u: goto label_802CF0C0;
    case 0x802CF0C4u: goto label_802CF0C4;
    case 0x802CF0C8u: goto label_802CF0C8;
    case 0x802CF0CCu: goto label_802CF0CC;
    case 0x802CF0D0u: goto label_802CF0D0;
    case 0x802CF0D4u: goto label_802CF0D4;
    case 0x802CF0D8u: goto label_802CF0D8;
    case 0x802CF0DCu: goto label_802CF0DC;
    case 0x802CF0E0u: goto label_802CF0E0;
    case 0x802CF0E4u: goto label_802CF0E4;
    case 0x802CF0E8u: goto label_802CF0E8;
    case 0x802CF0ECu: goto label_802CF0EC;
    case 0x802CF0F0u: goto label_802CF0F0;
    case 0x802CF0F4u: goto label_802CF0F4;
    case 0x802CF0F8u: goto label_802CF0F8;
    case 0x802CF0FCu: goto label_802CF0FC;
    case 0x802CF100u: goto label_802CF100;
    case 0x802CF104u: goto label_802CF104;
    case 0x802CF108u: goto label_802CF108;
    case 0x802CF10Cu: goto label_802CF10C;
    case 0x802CF110u: goto label_802CF110;
    case 0x802CF114u: goto label_802CF114;
    case 0x802CF118u: goto label_802CF118;
    case 0x802CF11Cu: goto label_802CF11C;
    case 0x802CF120u: goto label_802CF120;
    case 0x802CF124u: goto label_802CF124;
    case 0x802CF128u: goto label_802CF128;
    case 0x802CF12Cu: goto label_802CF12C;
    case 0x802CF130u: goto label_802CF130;
    case 0x802CF134u: goto label_802CF134;
    case 0x802CF138u: goto label_802CF138;
    case 0x802CF13Cu: goto label_802CF13C;
    case 0x802CF140u: goto label_802CF140;
    case 0x802CF144u: goto label_802CF144;
    case 0x802CF148u: goto label_802CF148;
    case 0x802CF14Cu: goto label_802CF14C;
    case 0x802CF150u: goto label_802CF150;
    case 0x802CF154u: goto label_802CF154;
    case 0x802CF158u: goto label_802CF158;
    case 0x802CF15Cu: goto label_802CF15C;
    case 0x802CF160u: goto label_802CF160;
    case 0x802CF164u: goto label_802CF164;
    case 0x802CF168u: goto label_802CF168;
    case 0x802CF16Cu: goto label_802CF16C;
    case 0x802CF170u: goto label_802CF170;
    case 0x802CF174u: goto label_802CF174;
    case 0x802CF178u: goto label_802CF178;
    case 0x802CF17Cu: goto label_802CF17C;
    case 0x802CF180u: goto label_802CF180;
    case 0x802CF184u: goto label_802CF184;
    case 0x802CF188u: goto label_802CF188;
    case 0x802CF18Cu: goto label_802CF18C;
    case 0x802CF190u: goto label_802CF190;
    case 0x802CF194u: goto label_802CF194;
    case 0x802CF198u: goto label_802CF198;
    case 0x802CF19Cu: goto label_802CF19C;
    case 0x802CF1A0u: goto label_802CF1A0;
    case 0x802CF1A4u: goto label_802CF1A4;
    case 0x802CF1A8u: goto label_802CF1A8;
    case 0x802CF1ACu: goto label_802CF1AC;
    case 0x802CF1B0u: goto label_802CF1B0;
    case 0x802CF1B4u: goto label_802CF1B4;
    case 0x802CF1B8u: goto label_802CF1B8;
    case 0x802CF1BCu: goto label_802CF1BC;
    case 0x802CF1C0u: goto label_802CF1C0;
    case 0x802CF1C4u: goto label_802CF1C4;
    case 0x802CF1C8u: goto label_802CF1C8;
    case 0x802CF1CCu: goto label_802CF1CC;
    case 0x802CF1D0u: goto label_802CF1D0;
    case 0x802CF1D4u: goto label_802CF1D4;
    case 0x802CF1D8u: goto label_802CF1D8;
    case 0x802CF1DCu: goto label_802CF1DC;
    case 0x802CF1E0u: goto label_802CF1E0;
    case 0x802CF1E4u: goto label_802CF1E4;
    case 0x802CF1E8u: goto label_802CF1E8;
    case 0x802CF1ECu: goto label_802CF1EC;
    case 0x802CF1F0u: goto label_802CF1F0;
    case 0x802CF1F4u: goto label_802CF1F4;
    case 0x802CF1F8u: goto label_802CF1F8;
    case 0x802CF1FCu: goto label_802CF1FC;
    case 0x802CF200u: goto label_802CF200;
    case 0x802CF204u: goto label_802CF204;
    case 0x802CF208u: goto label_802CF208;
    case 0x802CF20Cu: goto label_802CF20C;
    case 0x802CF210u: goto label_802CF210;
    case 0x802CF214u: goto label_802CF214;
    case 0x802CF218u: goto label_802CF218;
    case 0x802CF21Cu: goto label_802CF21C;
    case 0x802CF220u: goto label_802CF220;
    case 0x802CF224u: goto label_802CF224;
    case 0x802CF228u: goto label_802CF228;
    case 0x802CF22Cu: goto label_802CF22C;
    case 0x802CF230u: goto label_802CF230;
    case 0x802CF234u: goto label_802CF234;
    case 0x802CF238u: goto label_802CF238;
    case 0x802CF23Cu: goto label_802CF23C;
    case 0x802CF240u: goto label_802CF240;
    case 0x802CF244u: goto label_802CF244;
    case 0x802CF248u: goto label_802CF248;
    case 0x802CF24Cu: goto label_802CF24C;
    case 0x802CF250u: goto label_802CF250;
    case 0x802CF254u: goto label_802CF254;
    case 0x802CF258u: goto label_802CF258;
    case 0x802CF25Cu: goto label_802CF25C;
    case 0x802CF260u: goto label_802CF260;
    case 0x802CF264u: goto label_802CF264;
    case 0x802CF268u: goto label_802CF268;
    case 0x802CF26Cu: goto label_802CF26C;
    case 0x802CF270u: goto label_802CF270;
    case 0x802CF274u: goto label_802CF274;
    case 0x802CF278u: goto label_802CF278;
    case 0x802CF27Cu: goto label_802CF27C;
    case 0x802CF280u: goto label_802CF280;
    case 0x802CF284u: goto label_802CF284;
    case 0x802CF288u: goto label_802CF288;
    case 0x802CF28Cu: goto label_802CF28C;
    case 0x802CF290u: goto label_802CF290;
    case 0x802CF294u: goto label_802CF294;
    case 0x802CF298u: goto label_802CF298;
    case 0x802CF29Cu: goto label_802CF29C;
    case 0x802CF2A0u: goto label_802CF2A0;
    case 0x802CF2A4u: goto label_802CF2A4;
    case 0x802CF2A8u: goto label_802CF2A8;
    case 0x802CF2ACu: goto label_802CF2AC;
    case 0x802CF2B0u: goto label_802CF2B0;
    case 0x802CF2B4u: goto label_802CF2B4;
    case 0x802CF2B8u: goto label_802CF2B8;
    case 0x802CF2BCu: goto label_802CF2BC;
    case 0x802CF2C0u: goto label_802CF2C0;
    case 0x802CF2C4u: goto label_802CF2C4;
    case 0x802CF2C8u: goto label_802CF2C8;
    case 0x802CF2CCu: goto label_802CF2CC;
    case 0x802CF2D0u: goto label_802CF2D0;
    case 0x802CF2D4u: goto label_802CF2D4;
    case 0x802CF2D8u: goto label_802CF2D8;
    case 0x802CF2DCu: goto label_802CF2DC;
    case 0x802CF2E0u: goto label_802CF2E0;
    case 0x802CF2E4u: goto label_802CF2E4;
    case 0x802CF2E8u: goto label_802CF2E8;
    case 0x802CF2ECu: goto label_802CF2EC;
    case 0x802CF2F0u: goto label_802CF2F0;
    case 0x802CF2F4u: goto label_802CF2F4;
    case 0x802CF2F8u: goto label_802CF2F8;
    case 0x802CF2FCu: goto label_802CF2FC;
    case 0x802CF300u: goto label_802CF300;
    case 0x802CF304u: goto label_802CF304;
    case 0x802CF308u: goto label_802CF308;
    case 0x802CF30Cu: goto label_802CF30C;
    case 0x802CF310u: goto label_802CF310;
    case 0x802CF314u: goto label_802CF314;
    case 0x802CF318u: goto label_802CF318;
    case 0x802CF31Cu: goto label_802CF31C;
    case 0x802CF320u: goto label_802CF320;
    case 0x802CF324u: goto label_802CF324;
    case 0x802CF328u: goto label_802CF328;
    case 0x802CF32Cu: goto label_802CF32C;
    case 0x802CF330u: goto label_802CF330;
    case 0x802CF334u: goto label_802CF334;
    case 0x802CF338u: goto label_802CF338;
    case 0x802CF33Cu: goto label_802CF33C;
    case 0x802CF340u: goto label_802CF340;
    case 0x802CF344u: goto label_802CF344;
    case 0x802CF348u: goto label_802CF348;
    case 0x802CF34Cu: goto label_802CF34C;
    case 0x802CF350u: goto label_802CF350;
    case 0x802CF354u: goto label_802CF354;
    case 0x802CF358u: goto label_802CF358;
    case 0x802CF35Cu: goto label_802CF35C;
    case 0x802CF360u: goto label_802CF360;
    case 0x802CF364u: goto label_802CF364;
    case 0x802CF368u: goto label_802CF368;
    case 0x802CF36Cu: goto label_802CF36C;
    case 0x802CF370u: goto label_802CF370;
    case 0x802CF374u: goto label_802CF374;
    case 0x802CF378u: goto label_802CF378;
    case 0x802CF37Cu: goto label_802CF37C;
    case 0x802CF380u: goto label_802CF380;
    case 0x802CF384u: goto label_802CF384;
    case 0x802CF388u: goto label_802CF388;
    case 0x802CF38Cu: goto label_802CF38C;
    case 0x802CF390u: goto label_802CF390;
    case 0x802CF394u: goto label_802CF394;
    case 0x802CF398u: goto label_802CF398;
    case 0x802CF39Cu: goto label_802CF39C;
    case 0x802CF3A0u: goto label_802CF3A0;
    case 0x802CF3A4u: goto label_802CF3A4;
    case 0x802CF3A8u: goto label_802CF3A8;
    case 0x802CF3ACu: goto label_802CF3AC;
    case 0x802CF3B0u: goto label_802CF3B0;
    case 0x802CF3B4u: goto label_802CF3B4;
    case 0x802CF3B8u: goto label_802CF3B8;
    case 0x802CF3BCu: goto label_802CF3BC;
    case 0x802CF3C0u: goto label_802CF3C0;
    case 0x802CF3C4u: goto label_802CF3C4;
    case 0x802CF3C8u: goto label_802CF3C8;
    case 0x802CF3CCu: goto label_802CF3CC;
    case 0x802CF3D0u: goto label_802CF3D0;
    case 0x802CF3D4u: goto label_802CF3D4;
    case 0x802CF3D8u: goto label_802CF3D8;
    case 0x802CF3DCu: goto label_802CF3DC;
    case 0x802CF3E0u: goto label_802CF3E0;
    case 0x802CF3E4u: goto label_802CF3E4;
    case 0x802CF3E8u: goto label_802CF3E8;
    case 0x802CF3ECu: goto label_802CF3EC;
    case 0x802CF3F0u: goto label_802CF3F0;
    case 0x802CF3F4u: goto label_802CF3F4;
    case 0x802CF3F8u: goto label_802CF3F8;
    case 0x802CF3FCu: goto label_802CF3FC;
    case 0x802CF400u: goto label_802CF400;
    case 0x802CF404u: goto label_802CF404;
    case 0x802CF408u: goto label_802CF408;
    case 0x802CF40Cu: goto label_802CF40C;
    case 0x802CF410u: goto label_802CF410;
    case 0x802CF414u: goto label_802CF414;
    case 0x802CF418u: goto label_802CF418;
    case 0x802CF41Cu: goto label_802CF41C;
    case 0x802CF420u: goto label_802CF420;
    case 0x802CF424u: goto label_802CF424;
    case 0x802CF428u: goto label_802CF428;
    case 0x802CF42Cu: goto label_802CF42C;
    case 0x802CF430u: goto label_802CF430;
    case 0x802CF434u: goto label_802CF434;
    case 0x802CF438u: goto label_802CF438;
    case 0x802CF43Cu: goto label_802CF43C;
    case 0x802CF440u: goto label_802CF440;
    case 0x802CF444u: goto label_802CF444;
    case 0x802CF448u: goto label_802CF448;
    case 0x802CF44Cu: goto label_802CF44C;
    case 0x802CF450u: goto label_802CF450;
    case 0x802CF454u: goto label_802CF454;
    case 0x802CF458u: goto label_802CF458;
    case 0x802CF45Cu: goto label_802CF45C;
    case 0x802CF460u: goto label_802CF460;
    case 0x802CF464u: goto label_802CF464;
    case 0x802CF468u: goto label_802CF468;
    case 0x802CF46Cu: goto label_802CF46C;
    case 0x802CF470u: goto label_802CF470;
    case 0x802CF474u: goto label_802CF474;
    case 0x802CF478u: goto label_802CF478;
    case 0x802CF47Cu: goto label_802CF47C;
    case 0x802CF480u: goto label_802CF480;
    case 0x802CF484u: goto label_802CF484;
    case 0x802CF488u: goto label_802CF488;
    case 0x802CF48Cu: goto label_802CF48C;
    case 0x802CF490u: goto label_802CF490;
    case 0x802CF494u: goto label_802CF494;
    case 0x802CF498u: goto label_802CF498;
    case 0x802CF49Cu: goto label_802CF49C;
    case 0x802CF4A0u: goto label_802CF4A0;
    case 0x802CF4A4u: goto label_802CF4A4;
    case 0x802CF4A8u: goto label_802CF4A8;
    case 0x802CF4ACu: goto label_802CF4AC;
    case 0x802CF4B0u: goto label_802CF4B0;
    case 0x802CF4B4u: goto label_802CF4B4;
    case 0x802CF4B8u: goto label_802CF4B8;
    case 0x802CF4BCu: goto label_802CF4BC;
    default: return;
    }
label_802CB4C0:
    ctx->pc = 0x802CB4C0u;
    ctx->downcount -= 17;
    // 802CB4C0: lwzx    r0, r6, r3
    {
        u32 ea = ctx->gpr[6] + ctx->gpr[3];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CB4C4:
    ctx->pc = 0x802CB4C4u;
    // 802CB4C4: addi    r3, r7, 60
    ctx->gpr[3] = ctx->gpr[7] + (u32)(s32)(60);

label_802CB4C8:
    ctx->pc = 0x802CB4C8u;
    // 802CB4C8: addi    r7, r7, 4
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(4);

label_802CB4CC:
    ctx->pc = 0x802CB4CCu;
    // 802CB4CC: stw     r0, -32768(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB4D0:
    ctx->pc = 0x802CB4D0u;
    // 802CB4D0: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CB4D4:
    ctx->pc = 0x802CB4D4u;
    // 802CB4D4: rlwinm r0, r0, 0, 2, 0
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xBFFFFFFFu;
    }

label_802CB4D8:
    ctx->pc = 0x802CB4D8u;
    // 802CB4D8: oris    r0, r0, 0x4000
    ctx->gpr[0] = ctx->gpr[0] | (0x4000u << 16);

label_802CB4DC:
    ctx->pc = 0x802CB4DCu;
    // 802CB4DC: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB4E0:
    ctx->pc = 0x802CB4E0u;
    // 802CB4E0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CB4E4:
    ctx->pc = 0x802CB4E4u;
    // 802CB4E4: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_802CB4E8:
    ctx->pc = 0x802CB4E8u;
    // 802CB4E8: oris    r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] | (0x8000u << 16);

label_802CB4EC:
    ctx->pc = 0x802CB4ECu;
    // 802CB4EC: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB4F0:
    ctx->pc = 0x802CB4F0u;
    // 802CB4F0: stb     r5, -32768(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_802CB4F4:
    ctx->pc = 0x802CB4F4u;
    // 802CB4F4: stb     r4, -32768(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CB4F8:
    ctx->pc = 0x802CB4F8u;
    // 802CB4F8: lwzx    r0, r6, r3
    {
        u32 ea = ctx->gpr[6] + ctx->gpr[3];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CB4FC:
    ctx->pc = 0x802CB4FCu;
    // 802CB4FC: stw     r0, -32768(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB500:
    ctx->pc = 0x802CB500u;
    // 802CB500: bc    16, 0, 0x802CB3BC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x802CB3BCu;
            return;
        }
    }

label_802CB504:
    ctx->pc = 0x802CB504u;
    ctx->downcount -= 22;
    // 802CB504: li      r4, 16
    ctx->gpr[4] = (u32)(s32)(16);

label_802CB508:
    ctx->pc = 0x802CB508u;
    // 802CB508: lis     r6, -13311
    ctx->gpr[6] = ((u32)(s32)(-13311) << 16);

label_802CB50C:
    ctx->pc = 0x802CB50Cu;
    // 802CB50C: stb     r4, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CB510:
    ctx->pc = 0x802CB510u;
    // 802CB510: li      r0, 4096
    ctx->gpr[0] = (u32)(s32)(4096);

label_802CB514:
    ctx->pc = 0x802CB514u;
    // 802CB514: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_802CB518:
    ctx->pc = 0x802CB518u;
    // 802CB518: stw     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB51C:
    ctx->pc = 0x802CB51Cu;
    // 802CB51C: li      r0, 63
    ctx->gpr[0] = (u32)(s32)(63);

label_802CB520:
    ctx->pc = 0x802CB520u;
    // 802CB520: rlwinm r25, r28, 15, 0, 16
    {
        ctx->gpr[25] = dolrecomp_rotl32(ctx->gpr[28], 15u) & 0xFFFF8000u;
    }

label_802CB524:
    ctx->pc = 0x802CB524u;
    // 802CB524: stw     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB528:
    ctx->pc = 0x802CB528u;
    // 802CB528: li      r0, 4114
    ctx->gpr[0] = (u32)(s32)(4114);

label_802CB52C:
    ctx->pc = 0x802CB52Cu;
    // 802CB52C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802CB530:
    ctx->pc = 0x802CB530u;
    // 802CB530: stb     r4, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CB534:
    ctx->pc = 0x802CB534u;
    // 802CB534: li      r4, 97
    ctx->gpr[4] = (u32)(s32)(97);

label_802CB538:
    ctx->pc = 0x802CB538u;
    // 802CB538: lis     r3, 22528
    ctx->gpr[3] = ((u32)(s32)(22528) << 16);

label_802CB53C:
    ctx->pc = 0x802CB53Cu;
    // 802CB53C: stw     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB540:
    ctx->pc = 0x802CB540u;
    // 802CB540: addi    r0, r3, 15
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(15);

label_802CB544:
    ctx->pc = 0x802CB544u;
    // 802CB544: addis   r26, r25, 8
    ctx->gpr[26] = ctx->gpr[25] + ((u32)(s32)(8) << 16);

label_802CB548:
    ctx->pc = 0x802CB548u;
    // 802CB548: stw     r5, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CB54C:
    ctx->pc = 0x802CB54Cu;
    // 802CB54C: rlwinm r27, r28, 4, 0, 27
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[28], 4u) & 0xFFFFFFF0u;
    }

label_802CB550:
    ctx->pc = 0x802CB550u;
    // 802CB550: stb     r4, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CB554:
    ctx->pc = 0x802CB554u;
    // 802CB554: stw     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB558:
    ctx->pc = 0x802CB558u;
    // 802CB558: b       0x802CB55C
    {
            goto label_802CB55C;
    }

label_802CB55C:
    ctx->pc = 0x802CB55Cu;
    ctx->downcount -= 1;
    // 802CB55C: b       0x802CB560
    {
            goto label_802CB560;
    }

label_802CB560:
    ctx->pc = 0x802CB560u;
    ctx->downcount -= 1;
    // 802CB560: b       0x802CB564
    {
            goto label_802CB564;
    }

label_802CB564:
    ctx->pc = 0x802CB564u;
    ctx->downcount -= 9;
    // 802CB564: lwz     r0, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CB568:
    // 802CB568: addi    r3, r27, 520
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(520);

label_802CB56C:
    // 802CB56C: or   r5, r25, r25
    {
        ctx->gpr[5] = ctx->gpr[25] | ctx->gpr[25];
    }

label_802CB570:
    // 802CB570: or   r7, r26, r26
    {
        ctx->gpr[7] = ctx->gpr[26] | ctx->gpr[26];
    }

label_802CB574:
    // 802CB574: add   r3, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802CB578:
    // 802CB578: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB57C:
    // 802CB57C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_802CB580:
    // 802CB580: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_802CB584:
    // 802CB584: bl      0x802D20B4
    {
            ctx->lr = 0x802CB588u;
            ctx->pc = 0x802D20B4u;
            return;
    }

label_802CB588:
    ctx->downcount -= 8;
    // 802CB588: addis   r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + ((u32)(s32)(1) << 16);

label_802CB58C:
    // 802CB58C: addis   r25, r25, 1
    ctx->gpr[25] = ctx->gpr[25] + ((u32)(s32)(1) << 16);

label_802CB590:
    // 802CB590: addi    r26, r26, -32768
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(-32768);

label_802CB594:
    // 802CB594: addi    r25, r25, -32768
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(-32768);

label_802CB598:
    // 802CB598: addi    r27, r27, 16
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(16);

label_802CB59C:
    // 802CB59C: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_802CB5A0:
    // 802CB5A0: cmplwi  r28, 0x0008
    {
        u32 val_a = (u32)(ctx->gpr[28]);
        u32 val_b = (u32)(0x0008u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CB5A4:
    // 802CB5A4: bc    12, 0, 0x802CB564
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CB564u;
                return;
            }
            goto label_802CB564;
        }
    }

label_802CB5A8:
    ctx->pc = 0x802CB5A8u;
    ctx->downcount -= 6;
    // 802CB5A8: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_802CB5AC:
    ctx->pc = 0x802CB5ACu;
    // 802CB5AC: rlwinm r3, r25, 1, 0, 30
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[25], 1u) & 0xFFFFFFFEu;
    }

label_802CB5B0:
    ctx->pc = 0x802CB5B0u;
    // 802CB5B0: addi    r26, r3, 9
    ctx->gpr[26] = ctx->gpr[3] + (u32)(s32)(9);

label_802CB5B4:
    ctx->pc = 0x802CB5B4u;
    // 802CB5B4: addi    r27, r3, 8
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(8);

label_802CB5B8:
    ctx->pc = 0x802CB5B8u;
    // 802CB5B8: rlwinm r28, r25, 4, 0, 27
    {
        ctx->gpr[28] = dolrecomp_rotl32(ctx->gpr[25], 4u) & 0xFFFFFFF0u;
    }

label_802CB5BC:
    ctx->pc = 0x802CB5BCu;
    // 802CB5BC: b       0x802CB5C0
    {
            goto label_802CB5C0;
    }

label_802CB5C0:
    ctx->pc = 0x802CB5C0u;
    ctx->downcount -= 1;
    // 802CB5C0: b       0x802CB5C4
    {
            goto label_802CB5C4;
    }

label_802CB5C4:
    ctx->pc = 0x802CB5C4u;
    ctx->downcount -= 1;
    // 802CB5C4: b       0x802CB5C8
    {
            goto label_802CB5C8;
    }

label_802CB5C8:
    ctx->pc = 0x802CB5C8u;
    ctx->downcount -= 9;
    // 802CB5C8: lwz     r0, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CB5CC:
    // 802CB5CC: addi    r3, r28, 648
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(648);

label_802CB5D0:
    // 802CB5D0: rlwinm r5, r27, 15, 0, 16
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[27], 15u) & 0xFFFF8000u;
    }

label_802CB5D4:
    // 802CB5D4: add   r3, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802CB5D8:
    // 802CB5D8: rlwinm r7, r26, 15, 0, 16
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[26], 15u) & 0xFFFF8000u;
    }

label_802CB5DC:
    // 802CB5DC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB5E0:
    // 802CB5E0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_802CB5E4:
    // 802CB5E4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_802CB5E8:
    // 802CB5E8: bl      0x802D20B4
    {
            ctx->lr = 0x802CB5ECu;
            ctx->pc = 0x802D20B4u;
            return;
    }

label_802CB5EC:
    ctx->downcount -= 6;
    // 802CB5EC: addi    r26, r26, 2
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(2);

label_802CB5F0:
    // 802CB5F0: addi    r27, r27, 2
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(2);

label_802CB5F4:
    // 802CB5F4: addi    r28, r28, 16
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(16);

label_802CB5F8:
    // 802CB5F8: addi    r25, r25, 1
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(1);

label_802CB5FC:
    // 802CB5FC: cmplwi  r25, 0x0004
    {
        u32 val_a = (u32)(ctx->gpr[25]);
        u32 val_b = (u32)(0x0004u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CB600:
    // 802CB600: bc    12, 0, 0x802CB5C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CB5C8u;
                return;
            }
            goto label_802CB5C8;
        }
    }

label_802CB604:
    ctx->pc = 0x802CB604u;
    ctx->downcount -= 5;
    // 802CB604: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_802CB608:
    ctx->pc = 0x802CB608u;
    // 802CB608: rlwinm r3, r25, 13, 0, 18
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[25], 13u) & 0xFFFFE000u;
    }

label_802CB60C:
    ctx->pc = 0x802CB60Cu;
    // 802CB60C: addis   r26, r3, 12
    ctx->gpr[26] = ctx->gpr[3] + ((u32)(s32)(12) << 16);

label_802CB610:
    ctx->pc = 0x802CB610u;
    // 802CB610: rlwinm r27, r25, 4, 0, 27
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[25], 4u) & 0xFFFFFFF0u;
    }

label_802CB614:
    ctx->pc = 0x802CB614u;
    // 802CB614: b       0x802CB618
    {
            goto label_802CB618;
    }

label_802CB618:
    ctx->pc = 0x802CB618u;
    ctx->downcount -= 1;
    // 802CB618: b       0x802CB61C
    {
            goto label_802CB61C;
    }

label_802CB61C:
    ctx->pc = 0x802CB61Cu;
    ctx->downcount -= 1;
    // 802CB61C: b       0x802CB620
    {
            goto label_802CB620;
    }

label_802CB620:
    ctx->pc = 0x802CB620u;
    ctx->downcount -= 6;
    // 802CB620: lwz     r0, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CB624:
    // 802CB624: addi    r3, r27, 720
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(720);

label_802CB628:
    // 802CB628: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_802CB62C:
    // 802CB62C: add   r3, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802CB630:
    // 802CB630: li      r5, 16
    ctx->gpr[5] = (u32)(s32)(16);

label_802CB634:
    // 802CB634: bl      0x802D2370
    {
            ctx->lr = 0x802CB638u;
            ctx->pc = 0x802D2370u;
            return;
    }

label_802CB638:
    ctx->downcount -= 5;
    // 802CB638: addi    r26, r26, 8192
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(8192);

label_802CB63C:
    // 802CB63C: addi    r27, r27, 16
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(16);

label_802CB640:
    // 802CB640: addi    r25, r25, 1
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(1);

label_802CB644:
    // 802CB644: cmplwi  r25, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[25]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CB648:
    // 802CB648: bc    12, 0, 0x802CB620
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CB620u;
                return;
            }
            goto label_802CB620;
        }
    }

label_802CB64C:
    ctx->pc = 0x802CB64Cu;
    ctx->downcount -= 4;
    // 802CB64C: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_802CB650:
    ctx->pc = 0x802CB650u;
    // 802CB650: rlwinm r3, r25, 15, 0, 16
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[25], 15u) & 0xFFFF8000u;
    }

label_802CB654:
    ctx->pc = 0x802CB654u;
    // 802CB654: addis   r26, r3, 14
    ctx->gpr[26] = ctx->gpr[3] + ((u32)(s32)(14) << 16);

label_802CB658:
    ctx->pc = 0x802CB658u;
    // 802CB658: b       0x802CB65C
    {
            goto label_802CB65C;
    }

label_802CB65C:
    ctx->pc = 0x802CB65Cu;
    ctx->downcount -= 1;
    // 802CB65C: b       0x802CB660
    {
            goto label_802CB660;
    }

label_802CB660:
    ctx->pc = 0x802CB660u;
    ctx->downcount -= 1;
    // 802CB660: b       0x802CB664
    {
            goto label_802CB664;
    }

label_802CB664:
    ctx->downcount -= 8;
    // 802CB664: addi    r0, r25, 16
    ctx->gpr[0] = ctx->gpr[25] + (u32)(s32)(16);

label_802CB668:
    ctx->pc = 0x802CB668u;
    // 802CB668: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CB66C:
    // 802CB66C: rlwinm r3, r0, 4, 0, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_802CB670:
    // 802CB670: addi    r3, r3, 720
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(720);

label_802CB674:
    // 802CB674: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_802CB678:
    // 802CB678: add   r3, r5, r3
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802CB67C:
    // 802CB67C: li      r5, 64
    ctx->gpr[5] = (u32)(s32)(64);

label_802CB680:
    // 802CB680: bl      0x802D2370
    {
            ctx->lr = 0x802CB684u;
            ctx->pc = 0x802D2370u;
            return;
    }

label_802CB684:
    ctx->downcount -= 5;
    // 802CB684: addis   r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + ((u32)(s32)(1) << 16);

label_802CB688:
    // 802CB688: addi    r26, r26, -32768
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(-32768);

label_802CB68C:
    // 802CB68C: addi    r25, r25, 1
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(1);

label_802CB690:
    // 802CB690: cmplwi  r25, 0x0004
    {
        u32 val_a = (u32)(ctx->gpr[25]);
        u32 val_b = (u32)(0x0004u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CB694:
    // 802CB694: bc    12, 0, 0x802CB664
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CB664u;
                return;
            }
            goto label_802CB664;
        }
    }

label_802CB698:
    ctx->pc = 0x802CB698u;
    ctx->downcount -= 32;
    // 802CB698: lwz     r4, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CB69C:
    ctx->pc = 0x802CB69Cu;
    // 802CB69C: li      r12, 0
    ctx->gpr[12] = (u32)(s32)(0);

label_802CB6A0:
    ctx->pc = 0x802CB6A0u;
    // 802CB6A0: li      r3, 8
    ctx->gpr[3] = (u32)(s32)(8);

label_802CB6A4:
    ctx->pc = 0x802CB6A4u;
    // 802CB6A4: sth     r12, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[12]);
    }

label_802CB6A8:
    ctx->pc = 0x802CB6A8u;
    // 802CB6A8: lis     r10, -13311
    ctx->gpr[10] = ((u32)(s32)(-13311) << 16);

label_802CB6AC:
    ctx->pc = 0x802CB6ACu;
    // 802CB6AC: li      r9, 32
    ctx->gpr[9] = (u32)(s32)(32);

label_802CB6B0:
    ctx->pc = 0x802CB6B0u;
    // 802CB6B0: lwz     r11, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_802CB6B4:
    ctx->pc = 0x802CB6B4u;
    // 802CB6B4: li      r8, 16
    ctx->gpr[8] = (u32)(s32)(16);

label_802CB6B8:
    ctx->pc = 0x802CB6B8u;
    // 802CB6B8: li      r7, 4102
    ctx->gpr[7] = (u32)(s32)(4102);

label_802CB6BC:
    ctx->pc = 0x802CB6BCu;
    // 802CB6BC: addi    r4, r11, 1260
    ctx->gpr[4] = ctx->gpr[11] + (u32)(s32)(1260);

label_802CB6C0:
    ctx->pc = 0x802CB6C0u;
    // 802CB6C0: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CB6C4:
    ctx->pc = 0x802CB6C4u;
    // 802CB6C4: li      r6, 97
    ctx->gpr[6] = (u32)(s32)(97);

label_802CB6C8:
    ctx->pc = 0x802CB6C8u;
    // 802CB6C8: lis     r5, 8960
    ctx->gpr[5] = ((u32)(s32)(8960) << 16);

label_802CB6CC:
    ctx->pc = 0x802CB6CCu;
    // 802CB6CC: rlwinm r0, r0, 0, 28, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF0Fu;
    }

label_802CB6D0:
    ctx->pc = 0x802CB6D0u;
    // 802CB6D0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB6D4:
    ctx->pc = 0x802CB6D4u;
    // 802CB6D4: lis     r4, 9216
    ctx->gpr[4] = ((u32)(s32)(9216) << 16);

label_802CB6D8:
    ctx->pc = 0x802CB6D8u;
    // 802CB6D8: lis     r0, 26368
    ctx->gpr[0] = ((u32)(s32)(26368) << 16);

label_802CB6DC:
    ctx->pc = 0x802CB6DCu;
    // 802CB6DC: stb     r3, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_802CB6E0:
    ctx->pc = 0x802CB6E0u;
    // 802CB6E0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CB6E4:
    ctx->pc = 0x802CB6E4u;
    // 802CB6E4: stb     r9, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_802CB6E8:
    ctx->pc = 0x802CB6E8u;
    // 802CB6E8: lwz     r9, 1260(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(1260);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_802CB6EC:
    ctx->pc = 0x802CB6ECu;
    // 802CB6EC: stw     r9, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_802CB6F0:
    ctx->pc = 0x802CB6F0u;
    // 802CB6F0: stb     r8, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_802CB6F4:
    ctx->pc = 0x802CB6F4u;
    // 802CB6F4: stw     r7, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_802CB6F8:
    ctx->pc = 0x802CB6F8u;
    // 802CB6F8: stw     r12, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_802CB6FC:
    ctx->pc = 0x802CB6FCu;
    // 802CB6FC: stb     r6, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_802CB700:
    ctx->pc = 0x802CB700u;
    // 802CB700: stw     r5, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CB704:
    ctx->pc = 0x802CB704u;
    // 802CB704: stb     r6, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_802CB708:
    ctx->pc = 0x802CB708u;
    // 802CB708: stw     r4, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CB70C:
    ctx->pc = 0x802CB70Cu;
    // 802CB70C: stb     r6, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_802CB710:
    ctx->pc = 0x802CB710u;
    // 802CB710: stw     r0, -32768(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB714:
    ctx->pc = 0x802CB714u;
    // 802CB714: bl      0x802D2B80
    {
            ctx->lr = 0x802CB718u;
            ctx->pc = 0x802D2B80u;
            return;
    }

label_802CB718:
    ctx->pc = 0x802CB718u;
    ctx->downcount -= 1;
    // 802CB718: bl      0x802CB734
    {
            ctx->lr = 0x802CB71Cu;
            goto label_802CB734;
    }

label_802CB71C:
    ctx->pc = 0x802CB71Cu;
    ctx->downcount -= 17;
    // 802CB71C: addi    r3, r30, 1272
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1272);

label_802CB720:
    ctx->pc = 0x802CB720u;
    // 802CB720: lmw     r25, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802CB724:
    ctx->pc = 0x802CB724u;
    // 802CB724: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CB728:
    ctx->pc = 0x802CB728u;
    // 802CB728: addi    r1, r1, 80
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(80);

label_802CB72C:
    ctx->pc = 0x802CB72Cu;
    // 802CB72C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CB730:
    ctx->pc = 0x802CB730u;
    // 802CB730: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CB734:
    ctx->pc = 0x802CB734u;
    ctx->downcount -= 13;
    // 802CB734: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CB738:
    ctx->pc = 0x802CB738u;
    // 802CB738: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB73C:
    ctx->pc = 0x802CB73Cu;
    // 802CB73C: stwu     r1, -128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-128);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CB740:
    ctx->pc = 0x802CB740u;
    // 802CB740: stw     r31, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CB744:
    ctx->pc = 0x802CB744u;
    // 802CB744: stw     r30, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CB748:
    ctx->pc = 0x802CB748u;
    // 802CB748: stw     r29, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802CB74C:
    ctx->pc = 0x802CB74Cu;
    // 802CB74C: lwz     r4, -3364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3364);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CB750:
    ctx->pc = 0x802CB750u;
    // 802CB750: lwz     r3, -3360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3360);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CB754:
    ctx->pc = 0x802CB754u;
    // 802CB754: lwz     r0, -3356(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3356);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CB758:
    ctx->pc = 0x802CB758u;
    // 802CB758: stw     r4, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CB75C:
    ctx->pc = 0x802CB75Cu;
    // 802CB75C: stw     r3, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CB760:
    ctx->pc = 0x802CB760u;
    // 802CB760: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB764:
    ctx->pc = 0x802CB764u;
    // 802CB764: bl      0x802DF4E0
    {
            ctx->lr = 0x802CB768u;
            ctx->pc = 0x802DF4E0u;
            return;
    }

label_802CB768:
    ctx->pc = 0x802CB768u;
    ctx->downcount -= 2;
    // 802CB768: cmpwi   r3, 2
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CB76C:
    ctx->pc = 0x802CB76Cu;
    // 802CB76C: bc    12, 2, 0x802CB7C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CB7C0;
        }
    }

label_802CB770:
    ctx->pc = 0x802CB770u;
    ctx->downcount -= 1;
    // 802CB770: bc    4, 0, 0x802CB784
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CB784;
        }
    }

label_802CB774:
    ctx->pc = 0x802CB774u;
    ctx->downcount -= 2;
    // 802CB774: cmpwi   r3, 0
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

label_802CB778:
    ctx->pc = 0x802CB778u;
    // 802CB778: bc    12, 2, 0x802CB790
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CB790;
        }
    }

label_802CB77C:
    ctx->pc = 0x802CB77Cu;
    ctx->downcount -= 1;
    // 802CB77C: bc    4, 0, 0x802CB7A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CB7A0;
        }
    }

label_802CB780:
    ctx->pc = 0x802CB780u;
    ctx->downcount -= 1;
    // 802CB780: b       0x802CB7D0
    {
            goto label_802CB7D0;
    }

label_802CB784:
    ctx->pc = 0x802CB784u;
    ctx->downcount -= 2;
    // 802CB784: cmpwi   r3, 5
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CB788:
    ctx->pc = 0x802CB788u;
    // 802CB788: bc    12, 2, 0x802CB7B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CB7B0;
        }
    }

label_802CB78C:
    ctx->pc = 0x802CB78Cu;
    ctx->downcount -= 1;
    // 802CB78C: b       0x802CB7D0
    {
            goto label_802CB7D0;
    }

label_802CB790:
    ctx->pc = 0x802CB790u;
    ctx->downcount -= 4;
    // 802CB790: lis     r3, -32715
    ctx->gpr[3] = ((u32)(s32)(-32715) << 16);

label_802CB794:
    ctx->pc = 0x802CB794u;
    // 802CB794: addi    r0, r3, 32640
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(32640);

label_802CB798:
    ctx->pc = 0x802CB798u;
    // 802CB798: or   r31, r0, r0
    {
        ctx->gpr[31] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802CB79C:
    ctx->pc = 0x802CB79Cu;
    // 802CB79C: b       0x802CB7DC
    {
            goto label_802CB7DC;
    }

label_802CB7A0:
    ctx->pc = 0x802CB7A0u;
    ctx->downcount -= 4;
    // 802CB7A0: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_802CB7A4:
    ctx->pc = 0x802CB7A4u;
    // 802CB7A4: addi    r0, r3, -31936
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-31936);

label_802CB7A8:
    ctx->pc = 0x802CB7A8u;
    // 802CB7A8: or   r31, r0, r0
    {
        ctx->gpr[31] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802CB7AC:
    ctx->pc = 0x802CB7ACu;
    // 802CB7AC: b       0x802CB7DC
    {
            goto label_802CB7DC;
    }

label_802CB7B0:
    ctx->pc = 0x802CB7B0u;
    ctx->downcount -= 4;
    // 802CB7B0: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_802CB7B4:
    ctx->pc = 0x802CB7B4u;
    // 802CB7B4: addi    r0, r3, -31516
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-31516);

label_802CB7B8:
    ctx->pc = 0x802CB7B8u;
    // 802CB7B8: or   r31, r0, r0
    {
        ctx->gpr[31] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802CB7BC:
    ctx->pc = 0x802CB7BCu;
    // 802CB7BC: b       0x802CB7DC
    {
            goto label_802CB7DC;
    }

label_802CB7C0:
    ctx->pc = 0x802CB7C0u;
    ctx->downcount -= 4;
    // 802CB7C0: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_802CB7C4:
    ctx->pc = 0x802CB7C4u;
    // 802CB7C4: addi    r0, r3, -32356
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-32356);

label_802CB7C8:
    ctx->pc = 0x802CB7C8u;
    // 802CB7C8: or   r31, r0, r0
    {
        ctx->gpr[31] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802CB7CC:
    ctx->pc = 0x802CB7CCu;
    // 802CB7CC: b       0x802CB7DC
    {
            goto label_802CB7DC;
    }

label_802CB7D0:
    ctx->pc = 0x802CB7D0u;
    ctx->downcount -= 3;
    // 802CB7D0: lis     r3, -32715
    ctx->gpr[3] = ((u32)(s32)(-32715) << 16);

label_802CB7D4:
    ctx->pc = 0x802CB7D4u;
    // 802CB7D4: addi    r0, r3, 32640
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(32640);

label_802CB7D8:
    ctx->pc = 0x802CB7D8u;
    // 802CB7D8: or   r31, r0, r0
    {
        ctx->gpr[31] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802CB7DC:
    ctx->pc = 0x802CB7DCu;
    ctx->downcount -= 6;
    // 802CB7DC: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CB7E0:
    ctx->pc = 0x802CB7E0u;
    // 802CB7E0: lis     r4, 256
    ctx->gpr[4] = ((u32)(s32)(256) << 16);

label_802CB7E4:
    ctx->pc = 0x802CB7E4u;
    // 802CB7E4: addi    r3, r1, 28
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(28);

label_802CB7E8:
    ctx->pc = 0x802CB7E8u;
    // 802CB7E8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CB7EC:
    ctx->pc = 0x802CB7ECu;
    // 802CB7EC: addi    r4, r4, -1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-1);

label_802CB7F0:
    ctx->pc = 0x802CB7F0u;
    // 802CB7F0: bl      0x802D0410
    {
            ctx->lr = 0x802CB7F4u;
            ctx->pc = 0x802D0410u;
            return;
    }

label_802CB7F4:
    ctx->pc = 0x802CB7F4u;
    ctx->downcount -= 7;
    // 802CB7F4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CB7F8:
    ctx->pc = 0x802CB7F8u;
    // 802CB7F8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CB7FC:
    ctx->pc = 0x802CB7FCu;
    // 802CB7FC: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_802CB800:
    ctx->pc = 0x802CB800u;
    // 802CB800: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_802CB804:
    ctx->pc = 0x802CB804u;
    // 802CB804: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_802CB808:
    ctx->pc = 0x802CB808u;
    // 802CB808: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_802CB80C:
    ctx->pc = 0x802CB80Cu;
    // 802CB80C: bl      0x802CE6A4
    {
            ctx->lr = 0x802CB810u;
            goto label_802CE6A4;
    }

label_802CB810:
    ctx->pc = 0x802CB810u;
    ctx->downcount -= 7;
    // 802CB810: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CB814:
    ctx->pc = 0x802CB814u;
    // 802CB814: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CB818:
    ctx->pc = 0x802CB818u;
    // 802CB818: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_802CB81C:
    ctx->pc = 0x802CB81Cu;
    // 802CB81C: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_802CB820:
    ctx->pc = 0x802CB820u;
    // 802CB820: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_802CB824:
    ctx->pc = 0x802CB824u;
    // 802CB824: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_802CB828:
    ctx->pc = 0x802CB828u;
    // 802CB828: bl      0x802CE6A4
    {
            ctx->lr = 0x802CB82Cu;
            goto label_802CE6A4;
    }

label_802CB82C:
    ctx->pc = 0x802CB82Cu;
    ctx->downcount -= 7;
    // 802CB82C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802CB830:
    ctx->pc = 0x802CB830u;
    // 802CB830: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CB834:
    ctx->pc = 0x802CB834u;
    // 802CB834: li      r5, 6
    ctx->gpr[5] = (u32)(s32)(6);

label_802CB838:
    ctx->pc = 0x802CB838u;
    // 802CB838: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_802CB83C:
    ctx->pc = 0x802CB83Cu;
    // 802CB83C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_802CB840:
    ctx->pc = 0x802CB840u;
    // 802CB840: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_802CB844:
    ctx->pc = 0x802CB844u;
    // 802CB844: bl      0x802CE6A4
    {
            ctx->lr = 0x802CB848u;
            goto label_802CE6A4;
    }

label_802CB848:
    ctx->pc = 0x802CB848u;
    ctx->downcount -= 7;
    // 802CB848: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_802CB84C:
    ctx->pc = 0x802CB84Cu;
    // 802CB84C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CB850:
    ctx->pc = 0x802CB850u;
    // 802CB850: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_802CB854:
    ctx->pc = 0x802CB854u;
    // 802CB854: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_802CB858:
    ctx->pc = 0x802CB858u;
    // 802CB858: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_802CB85C:
    ctx->pc = 0x802CB85Cu;
    // 802CB85C: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_802CB860:
    ctx->pc = 0x802CB860u;
    // 802CB860: bl      0x802CE6A4
    {
            ctx->lr = 0x802CB864u;
            goto label_802CE6A4;
    }

label_802CB864:
    ctx->pc = 0x802CB864u;
    ctx->downcount -= 7;
    // 802CB864: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_802CB868:
    ctx->pc = 0x802CB868u;
    // 802CB868: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CB86C:
    ctx->pc = 0x802CB86Cu;
    // 802CB86C: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_802CB870:
    ctx->pc = 0x802CB870u;
    // 802CB870: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_802CB874:
    ctx->pc = 0x802CB874u;
    // 802CB874: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_802CB878:
    ctx->pc = 0x802CB878u;
    // 802CB878: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_802CB87C:
    ctx->pc = 0x802CB87Cu;
    // 802CB87C: bl      0x802CE6A4
    {
            ctx->lr = 0x802CB880u;
            goto label_802CE6A4;
    }

label_802CB880:
    ctx->pc = 0x802CB880u;
    ctx->downcount -= 7;
    // 802CB880: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_802CB884:
    ctx->pc = 0x802CB884u;
    // 802CB884: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CB888:
    ctx->pc = 0x802CB888u;
    // 802CB888: li      r5, 9
    ctx->gpr[5] = (u32)(s32)(9);

label_802CB88C:
    ctx->pc = 0x802CB88Cu;
    // 802CB88C: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_802CB890:
    ctx->pc = 0x802CB890u;
    // 802CB890: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_802CB894:
    ctx->pc = 0x802CB894u;
    // 802CB894: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_802CB898:
    ctx->pc = 0x802CB898u;
    // 802CB898: bl      0x802CE6A4
    {
            ctx->lr = 0x802CB89Cu;
            goto label_802CE6A4;
    }

label_802CB89C:
    ctx->pc = 0x802CB89Cu;
    ctx->downcount -= 7;
    // 802CB89C: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_802CB8A0:
    ctx->pc = 0x802CB8A0u;
    // 802CB8A0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CB8A4:
    ctx->pc = 0x802CB8A4u;
    // 802CB8A4: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_802CB8A8:
    ctx->pc = 0x802CB8A8u;
    // 802CB8A8: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_802CB8AC:
    ctx->pc = 0x802CB8ACu;
    // 802CB8AC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_802CB8B0:
    ctx->pc = 0x802CB8B0u;
    // 802CB8B0: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_802CB8B4:
    ctx->pc = 0x802CB8B4u;
    // 802CB8B4: bl      0x802CE6A4
    {
            ctx->lr = 0x802CB8B8u;
            goto label_802CE6A4;
    }

label_802CB8B8:
    ctx->pc = 0x802CB8B8u;
    ctx->downcount -= 7;
    // 802CB8B8: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_802CB8BC:
    ctx->pc = 0x802CB8BCu;
    // 802CB8BC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CB8C0:
    ctx->pc = 0x802CB8C0u;
    // 802CB8C0: li      r5, 11
    ctx->gpr[5] = (u32)(s32)(11);

label_802CB8C4:
    ctx->pc = 0x802CB8C4u;
    // 802CB8C4: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_802CB8C8:
    ctx->pc = 0x802CB8C8u;
    // 802CB8C8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_802CB8CC:
    ctx->pc = 0x802CB8CCu;
    // 802CB8CC: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_802CB8D0:
    ctx->pc = 0x802CB8D0u;
    // 802CB8D0: bl      0x802CE6A4
    {
            ctx->lr = 0x802CB8D4u;
            goto label_802CE6A4;
    }

label_802CB8D4:
    ctx->pc = 0x802CB8D4u;
    ctx->downcount -= 2;
    // 802CB8D4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CB8D8:
    ctx->pc = 0x802CB8D8u;
    // 802CB8D8: bl      0x802CE974
    {
            ctx->lr = 0x802CB8DCu;
            goto label_802CE974;
    }

label_802CB8DC:
    ctx->pc = 0x802CB8DCu;
    ctx->downcount -= 1;
    // 802CB8DC: bl      0x802CDB70
    {
            ctx->lr = 0x802CB8E0u;
            goto label_802CDB70;
    }

label_802CB8E0:
    ctx->pc = 0x802CB8E0u;
    ctx->downcount -= 1;
    // 802CB8E0: bl      0x802CE694
    {
            ctx->lr = 0x802CB8E4u;
            goto label_802CE694;
    }

label_802CB8E4:
    ctx->pc = 0x802CB8E4u;
    ctx->downcount -= 2;
    // 802CB8E4: li      r29, 9
    ctx->gpr[29] = (u32)(s32)(9);

label_802CB8E8:
    ctx->pc = 0x802CB8E8u;
    // 802CB8E8: b       0x802CB8EC
    {
            goto label_802CB8EC;
    }

label_802CB8EC:
    ctx->pc = 0x802CB8ECu;
    ctx->downcount -= 1;
    // 802CB8EC: b       0x802CB8F0
    {
            goto label_802CB8F0;
    }

label_802CB8F0:
    ctx->pc = 0x802CB8F0u;
    ctx->downcount -= 1;
    // 802CB8F0: b       0x802CB8F4
    {
            goto label_802CB8F4;
    }

label_802CB8F4:
    ctx->pc = 0x802CB8F4u;
    ctx->downcount -= 4;
    // 802CB8F4: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CB8F8:
    // 802CB8F8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_802CB8FC:
    // 802CB8FC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CB900:
    // 802CB900: bl      0x802CE608
    {
            ctx->lr = 0x802CB904u;
            goto label_802CE608;
    }

label_802CB904:
    ctx->downcount -= 3;
    // 802CB904: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_802CB908:
    // 802CB908: cmplwi  r29, 0x0018
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(0x0018u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CB90C:
    // 802CB90C: bc    4, 1, 0x802CB8F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CB8F4u;
                return;
            }
            goto label_802CB8F4;
        }
    }

label_802CB910:
    ctx->pc = 0x802CB910u;
    ctx->downcount -= 2;
    // 802CB910: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_802CB914:
    ctx->pc = 0x802CB914u;
    // 802CB914: b       0x802CB918
    {
            goto label_802CB918;
    }

label_802CB918:
    ctx->pc = 0x802CB918u;
    ctx->downcount -= 3;
    // 802CB918: lis     r3, -32715
    ctx->gpr[3] = ((u32)(s32)(-32715) << 16);

label_802CB91C:
    ctx->pc = 0x802CB91Cu;
    // 802CB91C: addi    r30, r3, 31428
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(31428);

label_802CB920:
    ctx->pc = 0x802CB920u;
    // 802CB920: b       0x802CB924
    {
            goto label_802CB924;
    }

label_802CB924:
    ctx->pc = 0x802CB924u;
    ctx->downcount -= 1;
    // 802CB924: b       0x802CB928
    {
            goto label_802CB928;
    }

label_802CB928:
    ctx->downcount -= 3;
    // 802CB928: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_802CB92C:
    // 802CB92C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802CB930:
    // 802CB930: bl      0x802CDF00
    {
            ctx->lr = 0x802CB934u;
            goto label_802CDF00;
    }

label_802CB934:
    ctx->downcount -= 3;
    // 802CB934: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_802CB938:
    // 802CB938: cmplwi  r29, 0x0008
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(0x0008u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CB93C:
    // 802CB93C: bc    12, 0, 0x802CB928
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CB928u;
                return;
            }
            goto label_802CB928;
        }
    }

label_802CB940:
    ctx->pc = 0x802CB940u;
    ctx->downcount -= 3;
    // 802CB940: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_802CB944:
    ctx->pc = 0x802CB944u;
    // 802CB944: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB948:
    ctx->pc = 0x802CB948u;
    // 802CB948: bl      0x802CF9B0
    {
            ctx->lr = 0x802CB94Cu;
            ctx->pc = 0x802CF9B0u;
            return;
    }

label_802CB94C:
    ctx->pc = 0x802CB94Cu;
    ctx->downcount -= 3;
    // 802CB94C: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_802CB950:
    ctx->pc = 0x802CB950u;
    // 802CB950: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB954:
    ctx->pc = 0x802CB954u;
    // 802CB954: bl      0x802CFA14
    {
            ctx->lr = 0x802CB958u;
            ctx->pc = 0x802CFA14u;
            return;
    }

label_802CB958:
    ctx->pc = 0x802CB958u;
    ctx->downcount -= 4;
    // 802CB958: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CB95C:
    ctx->pc = 0x802CB95Cu;
    // 802CB95C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB960:
    ctx->pc = 0x802CB960u;
    // 802CB960: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CB964:
    ctx->pc = 0x802CB964u;
    // 802CB964: bl      0x802CFA7C
    {
            ctx->lr = 0x802CB968u;
            ctx->pc = 0x802CFA7Cu;
            return;
    }

label_802CB968:
    ctx->pc = 0x802CB968u;
    ctx->downcount -= 4;
    // 802CB968: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CB96C:
    ctx->pc = 0x802CB96Cu;
    // 802CB96C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB970:
    ctx->pc = 0x802CB970u;
    // 802CB970: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CB974:
    ctx->pc = 0x802CB974u;
    // 802CB974: bl      0x802CFA7C
    {
            ctx->lr = 0x802CB978u;
            ctx->pc = 0x802CFA7Cu;
            return;
    }

label_802CB978:
    ctx->pc = 0x802CB978u;
    ctx->downcount -= 4;
    // 802CB978: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802CB97C:
    ctx->pc = 0x802CB97Cu;
    // 802CB97C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB980:
    ctx->pc = 0x802CB980u;
    // 802CB980: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CB984:
    ctx->pc = 0x802CB984u;
    // 802CB984: bl      0x802CFA7C
    {
            ctx->lr = 0x802CB988u;
            ctx->pc = 0x802CFA7Cu;
            return;
    }

label_802CB988:
    ctx->pc = 0x802CB988u;
    ctx->downcount -= 4;
    // 802CB988: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_802CB98C:
    ctx->pc = 0x802CB98Cu;
    // 802CB98C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB990:
    ctx->pc = 0x802CB990u;
    // 802CB990: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CB994:
    ctx->pc = 0x802CB994u;
    // 802CB994: bl      0x802CFA7C
    {
            ctx->lr = 0x802CB998u;
            ctx->pc = 0x802CFA7Cu;
            return;
    }

label_802CB998:
    ctx->pc = 0x802CB998u;
    ctx->downcount -= 4;
    // 802CB998: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_802CB99C:
    ctx->pc = 0x802CB99Cu;
    // 802CB99C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB9A0:
    ctx->pc = 0x802CB9A0u;
    // 802CB9A0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CB9A4:
    ctx->pc = 0x802CB9A4u;
    // 802CB9A4: bl      0x802CFA7C
    {
            ctx->lr = 0x802CB9A8u;
            ctx->pc = 0x802CFA7Cu;
            return;
    }

label_802CB9A8:
    ctx->pc = 0x802CB9A8u;
    ctx->downcount -= 4;
    // 802CB9A8: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_802CB9AC:
    ctx->pc = 0x802CB9ACu;
    // 802CB9AC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB9B0:
    ctx->pc = 0x802CB9B0u;
    // 802CB9B0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CB9B4:
    ctx->pc = 0x802CB9B4u;
    // 802CB9B4: bl      0x802CFA7C
    {
            ctx->lr = 0x802CB9B8u;
            ctx->pc = 0x802CFA7Cu;
            return;
    }

label_802CB9B8:
    ctx->pc = 0x802CB9B8u;
    ctx->downcount -= 4;
    // 802CB9B8: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_802CB9BC:
    ctx->pc = 0x802CB9BCu;
    // 802CB9BC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB9C0:
    ctx->pc = 0x802CB9C0u;
    // 802CB9C0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CB9C4:
    ctx->pc = 0x802CB9C4u;
    // 802CB9C4: bl      0x802CFA7C
    {
            ctx->lr = 0x802CB9C8u;
            ctx->pc = 0x802CFA7Cu;
            return;
    }

label_802CB9C8:
    ctx->pc = 0x802CB9C8u;
    ctx->downcount -= 4;
    // 802CB9C8: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_802CB9CC:
    ctx->pc = 0x802CB9CCu;
    // 802CB9CC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB9D0:
    ctx->pc = 0x802CB9D0u;
    // 802CB9D0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CB9D4:
    ctx->pc = 0x802CB9D4u;
    // 802CB9D4: bl      0x802CFA7C
    {
            ctx->lr = 0x802CB9D8u;
            ctx->pc = 0x802CFA7Cu;
            return;
    }

label_802CB9D8:
    ctx->pc = 0x802CB9D8u;
    ctx->downcount -= 17;
    // 802CB9D8: lfs     f1, -3352(r13)
    if (!ppc_fp_available_inline(ctx, 0x802CB9D8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3352);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_802CB9DC:
    ctx->pc = 0x802CB9DCu;
    // 802CB9DC: addi    r3, r1, 44
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(44);

label_802CB9E0:
    ctx->pc = 0x802CB9E0u;
    // 802CB9E0: lfs     f0, -3348(r13)
    if (!ppc_fp_available_inline(ctx, 0x802CB9E0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3348);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_802CB9E4:
    ctx->pc = 0x802CB9E4u;
    // 802CB9E4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CB9E8:
    ctx->pc = 0x802CB9E8u;
    // 802CB9E8: stfs     f1, 44(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CB9E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_802CB9EC:
    ctx->pc = 0x802CB9ECu;
    // 802CB9EC: stfs     f0, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CB9ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_802CB9F0:
    ctx->pc = 0x802CB9F0u;
    // 802CB9F0: stfs     f0, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CB9F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_802CB9F4:
    ctx->pc = 0x802CB9F4u;
    // 802CB9F4: stfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CB9F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_802CB9F8:
    ctx->pc = 0x802CB9F8u;
    // 802CB9F8: stfs     f0, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CB9F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_802CB9FC:
    ctx->pc = 0x802CB9FCu;
    // 802CB9FC: stfs     f1, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CB9FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_802CBA00:
    ctx->pc = 0x802CBA00u;
    // 802CBA00: stfs     f0, 68(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CBA00u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_802CBA04:
    ctx->pc = 0x802CBA04u;
    // 802CBA04: stfs     f0, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CBA04u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_802CBA08:
    ctx->pc = 0x802CBA08u;
    // 802CBA08: stfs     f0, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CBA08u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_802CBA0C:
    ctx->pc = 0x802CBA0Cu;
    // 802CBA0C: stfs     f0, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CBA0Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_802CBA10:
    ctx->pc = 0x802CBA10u;
    // 802CBA10: stfs     f1, 84(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CBA10u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_802CBA14:
    ctx->pc = 0x802CBA14u;
    // 802CBA14: stfs     f0, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CBA14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_802CBA18:
    ctx->pc = 0x802CBA18u;
    // 802CBA18: bl      0x802D4D48
    {
            ctx->lr = 0x802CBA1Cu;
            ctx->pc = 0x802D4D48u;
            return;
    }

label_802CBA1C:
    ctx->pc = 0x802CBA1Cu;
    ctx->downcount -= 3;
    // 802CBA1C: addi    r3, r1, 44
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(44);

label_802CBA20:
    ctx->pc = 0x802CBA20u;
    // 802CBA20: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBA24:
    ctx->pc = 0x802CBA24u;
    // 802CBA24: bl      0x802D4DC0
    {
            ctx->lr = 0x802CBA28u;
            ctx->pc = 0x802D4DC0u;
            return;
    }

label_802CBA28:
    ctx->pc = 0x802CBA28u;
    ctx->downcount -= 2;
    // 802CBA28: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBA2C:
    ctx->pc = 0x802CBA2Cu;
    // 802CBA2C: bl      0x802D4E84
    {
            ctx->lr = 0x802CBA30u;
            ctx->pc = 0x802D4E84u;
            return;
    }

label_802CBA30:
    ctx->pc = 0x802CBA30u;
    ctx->downcount -= 4;
    // 802CBA30: addi    r3, r1, 44
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(44);

label_802CBA34:
    ctx->pc = 0x802CBA34u;
    // 802CBA34: li      r4, 60
    ctx->gpr[4] = (u32)(s32)(60);

label_802CBA38:
    ctx->pc = 0x802CBA38u;
    // 802CBA38: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBA3C:
    ctx->pc = 0x802CBA3Cu;
    // 802CBA3C: bl      0x802D4EBC
    {
            ctx->lr = 0x802CBA40u;
            ctx->pc = 0x802D4EBCu;
            return;
    }

label_802CBA40:
    ctx->pc = 0x802CBA40u;
    ctx->downcount -= 4;
    // 802CBA40: addi    r3, r1, 44
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(44);

label_802CBA44:
    ctx->pc = 0x802CBA44u;
    // 802CBA44: li      r4, 125
    ctx->gpr[4] = (u32)(s32)(125);

label_802CBA48:
    ctx->pc = 0x802CBA48u;
    // 802CBA48: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBA4C:
    ctx->pc = 0x802CBA4Cu;
    // 802CBA4C: bl      0x802D4EBC
    {
            ctx->lr = 0x802CBA50u;
            ctx->pc = 0x802D4EBCu;
            return;
    }

label_802CBA50:
    ctx->pc = 0x802CBA50u;
    ctx->downcount -= 17;
    // 802CBA50: lhz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CBA54:
    ctx->pc = 0x802CBA54u;
    // 802CBA54: lis     r3, 17200
    ctx->gpr[3] = ((u32)(s32)(17200) << 16);

label_802CBA58:
    ctx->pc = 0x802CBA58u;
    // 802CBA58: lhz     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CBA5C:
    ctx->pc = 0x802CBA5Cu;
    // 802CBA5C: stw     r4, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CBA60:
    ctx->pc = 0x802CBA60u;
    // 802CBA60: lfs     f1, -3348(r13)
    if (!ppc_fp_available_inline(ctx, 0x802CBA60u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3348);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_802CBA64:
    ctx->pc = 0x802CBA64u;
    // 802CBA64: stw     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CBA68:
    ctx->pc = 0x802CBA68u;
    // 802CBA68: lfd     f4, -3336(r13)
    if (!ppc_fp_available_inline(ctx, 0x802CBA68u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3336);
        ctx->fpr[4] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_802CBA6C:
    ctx->pc = 0x802CBA6Cu;
    // 802CBA6C: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x802CBA6Cu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_802CBA70:
    ctx->pc = 0x802CBA70u;
    // 802CBA70: stw     r3, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CBA74:
    ctx->pc = 0x802CBA74u;
    // 802CBA74: fmr    f5, f1
    if (!ppc_fp_available_inline(ctx, 0x802CBA74u)) return;
    ctx->fpr[5] = ctx->fpr[1];

label_802CBA78:
    ctx->pc = 0x802CBA78u;
    // 802CBA78: lfs     f6, -3352(r13)
    if (!ppc_fp_available_inline(ctx, 0x802CBA78u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3352);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_802CBA7C:
    ctx->pc = 0x802CBA7Cu;
    // 802CBA7C: stw     r3, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CBA80:
    ctx->pc = 0x802CBA80u;
    // 802CBA80: lfd     f3, 104(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CBA80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->fpr[3] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_802CBA84:
    ctx->pc = 0x802CBA84u;
    // 802CBA84: lfd     f0, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CBA84u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_802CBA88:
    ctx->pc = 0x802CBA88u;
    // 802CBA88: fsubs   f3, f3, f4
    if (!ppc_fp_available_inline(ctx, 0x802CBA88u)) return;
    ppc_fsubs(ctx, 3, 3, 4);

label_802CBA8C:
    ctx->pc = 0x802CBA8Cu;
    // 802CBA8C: fsubs   f4, f0, f4
    if (!ppc_fp_available_inline(ctx, 0x802CBA8Cu)) return;
    ppc_fsubs(ctx, 4, 0, 4);

label_802CBA90:
    ctx->pc = 0x802CBA90u;
    // 802CBA90: bl      0x802D50D0
    {
            ctx->lr = 0x802CBA94u;
            ctx->pc = 0x802D50D0u;
            return;
    }

label_802CBA94:
    ctx->pc = 0x802CBA94u;
    ctx->downcount -= 3;
    // 802CBA94: lis     r3, -32715
    ctx->gpr[3] = ((u32)(s32)(-32715) << 16);

label_802CBA98:
    ctx->pc = 0x802CBA98u;
    // 802CBA98: addi    r3, r3, 31636
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(31636);

label_802CBA9C:
    ctx->pc = 0x802CBA9Cu;
    // 802CBA9C: bl      0x802D4B70
    {
            ctx->lr = 0x802CBAA0u;
            ctx->pc = 0x802D4B70u;
            return;
    }

label_802CBAA0:
    ctx->pc = 0x802CBAA0u;
    ctx->downcount -= 2;
    // 802CBAA0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBAA4:
    ctx->pc = 0x802CBAA4u;
    // 802CBAA4: bl      0x802CFB68
    {
            ctx->lr = 0x802CBAA8u;
            ctx->pc = 0x802CFB68u;
            return;
    }

label_802CBAA8:
    ctx->pc = 0x802CBAA8u;
    ctx->downcount -= 2;
    // 802CBAA8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802CBAAC:
    ctx->pc = 0x802CBAACu;
    // 802CBAAC: bl      0x802CFAD8
    {
            ctx->lr = 0x802CBAB0u;
            ctx->pc = 0x802CFAD8u;
            return;
    }

label_802CBAB0:
    ctx->pc = 0x802CBAB0u;
    ctx->downcount -= 2;
    // 802CBAB0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBAB4:
    ctx->pc = 0x802CBAB4u;
    // 802CBAB4: bl      0x802D5244
    {
            ctx->lr = 0x802CBAB8u;
            ctx->pc = 0x802D5244u;
            return;
    }

label_802CBAB8:
    ctx->pc = 0x802CBAB8u;
    ctx->downcount -= 5;
    // 802CBAB8: lhz     r5, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_802CBABC:
    ctx->pc = 0x802CBABCu;
    // 802CBABC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBAC0:
    ctx->pc = 0x802CBAC0u;
    // 802CBAC0: lhz     r6, 6(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(6);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_802CBAC4:
    ctx->pc = 0x802CBAC4u;
    // 802CBAC4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBAC8:
    ctx->pc = 0x802CBAC8u;
    // 802CBAC8: bl      0x802D512C
    {
            ctx->lr = 0x802CBACCu;
            ctx->pc = 0x802D512Cu;
            return;
    }

label_802CBACC:
    ctx->pc = 0x802CBACCu;
    ctx->downcount -= 3;
    // 802CBACC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBAD0:
    ctx->pc = 0x802CBAD0u;
    // 802CBAD0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBAD4:
    ctx->pc = 0x802CBAD4u;
    // 802CBAD4: bl      0x802D5204
    {
            ctx->lr = 0x802CBAD8u;
            ctx->pc = 0x802D5204u;
            return;
    }

label_802CBAD8:
    ctx->pc = 0x802CBAD8u;
    ctx->downcount -= 2;
    // 802CBAD8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBADC:
    ctx->pc = 0x802CBADCu;
    // 802CBADC: bl      0x802D1110
    {
            ctx->lr = 0x802CBAE0u;
            ctx->pc = 0x802D1110u;
            return;
    }

label_802CBAE0:
    ctx->pc = 0x802CBAE0u;
    ctx->downcount -= 8;
    // 802CBAE0: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_802CBAE4:
    ctx->pc = 0x802CBAE4u;
    // 802CBAE4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBAE8:
    ctx->pc = 0x802CBAE8u;
    // 802CBAE8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBAEC:
    ctx->pc = 0x802CBAECu;
    // 802CBAEC: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_802CBAF0:
    ctx->pc = 0x802CBAF0u;
    // 802CBAF0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_802CBAF4:
    ctx->pc = 0x802CBAF4u;
    // 802CBAF4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_802CBAF8:
    ctx->pc = 0x802CBAF8u;
    // 802CBAF8: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_802CBAFC:
    ctx->pc = 0x802CBAFCu;
    // 802CBAFC: bl      0x802D1154
    {
            ctx->lr = 0x802CBB00u;
            ctx->pc = 0x802D1154u;
            return;
    }

label_802CBB00:
    ctx->pc = 0x802CBB00u;
    ctx->downcount -= 5;
    // 802CBB00: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CBB04:
    ctx->pc = 0x802CBB04u;
    // 802CBB04: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_802CBB08:
    ctx->pc = 0x802CBB08u;
    // 802CBB08: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_802CBB0C:
    ctx->pc = 0x802CBB0Cu;
    // 802CBB0C: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CBB10:
    ctx->pc = 0x802CBB10u;
    // 802CBB10: bl      0x802D0F28
    {
            ctx->lr = 0x802CBB14u;
            ctx->pc = 0x802D0F28u;
            return;
    }

label_802CBB14:
    ctx->pc = 0x802CBB14u;
    ctx->downcount -= 5;
    // 802CBB14: lwz     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CBB18:
    ctx->pc = 0x802CBB18u;
    // 802CBB18: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_802CBB1C:
    ctx->pc = 0x802CBB1Cu;
    // 802CBB1C: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_802CBB20:
    ctx->pc = 0x802CBB20u;
    // 802CBB20: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CBB24:
    ctx->pc = 0x802CBB24u;
    // 802CBB24: bl      0x802D101C
    {
            ctx->lr = 0x802CBB28u;
            ctx->pc = 0x802D101Cu;
            return;
    }

label_802CBB28:
    ctx->pc = 0x802CBB28u;
    ctx->downcount -= 8;
    // 802CBB28: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_802CBB2C:
    ctx->pc = 0x802CBB2Cu;
    // 802CBB2C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBB30:
    ctx->pc = 0x802CBB30u;
    // 802CBB30: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBB34:
    ctx->pc = 0x802CBB34u;
    // 802CBB34: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_802CBB38:
    ctx->pc = 0x802CBB38u;
    // 802CBB38: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_802CBB3C:
    ctx->pc = 0x802CBB3Cu;
    // 802CBB3C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_802CBB40:
    ctx->pc = 0x802CBB40u;
    // 802CBB40: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_802CBB44:
    ctx->pc = 0x802CBB44u;
    // 802CBB44: bl      0x802D1154
    {
            ctx->lr = 0x802CBB48u;
            ctx->pc = 0x802D1154u;
            return;
    }

label_802CBB48:
    ctx->pc = 0x802CBB48u;
    ctx->downcount -= 5;
    // 802CBB48: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CBB4C:
    ctx->pc = 0x802CBB4Cu;
    // 802CBB4C: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_802CBB50:
    ctx->pc = 0x802CBB50u;
    // 802CBB50: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_802CBB54:
    ctx->pc = 0x802CBB54u;
    // 802CBB54: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CBB58:
    ctx->pc = 0x802CBB58u;
    // 802CBB58: bl      0x802D0F28
    {
            ctx->lr = 0x802CBB5Cu;
            ctx->pc = 0x802D0F28u;
            return;
    }

label_802CBB5C:
    ctx->pc = 0x802CBB5Cu;
    ctx->downcount -= 5;
    // 802CBB5C: lwz     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CBB60:
    ctx->pc = 0x802CBB60u;
    // 802CBB60: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_802CBB64:
    ctx->pc = 0x802CBB64u;
    // 802CBB64: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_802CBB68:
    ctx->pc = 0x802CBB68u;
    // 802CBB68: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CBB6C:
    ctx->pc = 0x802CBB6Cu;
    // 802CBB6C: bl      0x802D101C
    {
            ctx->lr = 0x802CBB70u;
            ctx->pc = 0x802D101Cu;
            return;
    }

label_802CBB70:
    ctx->pc = 0x802CBB70u;
    ctx->downcount -= 1;
    // 802CBB70: bl      0x802D24E4
    {
            ctx->lr = 0x802CBB74u;
            ctx->pc = 0x802D24E4u;
            return;
    }

label_802CBB74:
    ctx->pc = 0x802CBB74u;
    ctx->downcount -= 7;
    // 802CBB74: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CBB78:
    ctx->pc = 0x802CBB78u;
    // 802CBB78: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_802CBB7C:
    ctx->pc = 0x802CBB7Cu;
    // 802CBB7C: lis     r3, -32723
    ctx->gpr[3] = ((u32)(s32)(-32723) << 16);

label_802CBB80:
    ctx->pc = 0x802CBB80u;
    // 802CBB80: stw     r30, 712(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(712);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CBB84:
    ctx->pc = 0x802CBB84u;
    // 802CBB84: addi    r3, r3, -21388
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-21388);

label_802CBB88:
    ctx->pc = 0x802CBB88u;
    // 802CBB88: stw     r30, 716(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(716);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CBB8C:
    ctx->pc = 0x802CBB8Cu;
    // 802CBB8C: bl      0x802D252C
    {
            ctx->lr = 0x802CBB90u;
            ctx->pc = 0x802D252Cu;
            return;
    }

label_802CBB90:
    ctx->pc = 0x802CBB90u;
    ctx->downcount -= 3;
    // 802CBB90: lis     r3, -32723
    ctx->gpr[3] = ((u32)(s32)(-32723) << 16);

label_802CBB94:
    ctx->pc = 0x802CBB94u;
    // 802CBB94: addi    r3, r3, -21264
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-21264);

label_802CBB98:
    ctx->pc = 0x802CBB98u;
    // 802CBB98: bl      0x802D2540
    {
            ctx->lr = 0x802CBB9Cu;
            ctx->pc = 0x802D2540u;
            return;
    }

label_802CBB9C:
    ctx->pc = 0x802CBB9Cu;
    ctx->downcount -= 5;
    // 802CBB9C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBBA0:
    ctx->pc = 0x802CBBA0u;
    // 802CBBA0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBBA4:
    ctx->pc = 0x802CBBA4u;
    // 802CBBA4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBBA8:
    ctx->pc = 0x802CBBA8u;
    // 802CBBA8: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_802CBBAC:
    ctx->pc = 0x802CBBACu;
    // 802CBBAC: bl      0x802D3D34
    {
            ctx->lr = 0x802CBBB0u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBBB0:
    ctx->pc = 0x802CBBB0u;
    ctx->downcount -= 5;
    // 802CBBB0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBBB4:
    ctx->pc = 0x802CBBB4u;
    // 802CBBB4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CBBB8:
    ctx->pc = 0x802CBBB8u;
    // 802CBBB8: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802CBBBC:
    ctx->pc = 0x802CBBBCu;
    // 802CBBBC: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_802CBBC0:
    ctx->pc = 0x802CBBC0u;
    // 802CBBC0: bl      0x802D3D34
    {
            ctx->lr = 0x802CBBC4u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBBC4:
    ctx->pc = 0x802CBBC4u;
    ctx->downcount -= 5;
    // 802CBBC4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802CBBC8:
    ctx->pc = 0x802CBBC8u;
    // 802CBBC8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802CBBCC:
    ctx->pc = 0x802CBBCCu;
    // 802CBBCC: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_802CBBD0:
    ctx->pc = 0x802CBBD0u;
    // 802CBBD0: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_802CBBD4:
    ctx->pc = 0x802CBBD4u;
    // 802CBBD4: bl      0x802D3D34
    {
            ctx->lr = 0x802CBBD8u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBBD8:
    ctx->pc = 0x802CBBD8u;
    ctx->downcount -= 5;
    // 802CBBD8: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_802CBBDC:
    ctx->pc = 0x802CBBDCu;
    // 802CBBDC: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_802CBBE0:
    ctx->pc = 0x802CBBE0u;
    // 802CBBE0: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_802CBBE4:
    ctx->pc = 0x802CBBE4u;
    // 802CBBE4: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_802CBBE8:
    ctx->pc = 0x802CBBE8u;
    // 802CBBE8: bl      0x802D3D34
    {
            ctx->lr = 0x802CBBECu;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBBEC:
    ctx->pc = 0x802CBBECu;
    ctx->downcount -= 5;
    // 802CBBEC: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_802CBBF0:
    ctx->pc = 0x802CBBF0u;
    // 802CBBF0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802CBBF4:
    ctx->pc = 0x802CBBF4u;
    // 802CBBF4: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_802CBBF8:
    ctx->pc = 0x802CBBF8u;
    // 802CBBF8: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_802CBBFC:
    ctx->pc = 0x802CBBFCu;
    // 802CBBFC: bl      0x802D3D34
    {
            ctx->lr = 0x802CBC00u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBC00:
    ctx->pc = 0x802CBC00u;
    ctx->downcount -= 5;
    // 802CBC00: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_802CBC04:
    ctx->pc = 0x802CBC04u;
    // 802CBC04: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_802CBC08:
    ctx->pc = 0x802CBC08u;
    // 802CBC08: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_802CBC0C:
    ctx->pc = 0x802CBC0Cu;
    // 802CBC0C: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_802CBC10:
    ctx->pc = 0x802CBC10u;
    // 802CBC10: bl      0x802D3D34
    {
            ctx->lr = 0x802CBC14u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBC14:
    ctx->pc = 0x802CBC14u;
    ctx->downcount -= 5;
    // 802CBC14: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_802CBC18:
    ctx->pc = 0x802CBC18u;
    // 802CBC18: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_802CBC1C:
    ctx->pc = 0x802CBC1Cu;
    // 802CBC1C: li      r5, 6
    ctx->gpr[5] = (u32)(s32)(6);

label_802CBC20:
    ctx->pc = 0x802CBC20u;
    // 802CBC20: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_802CBC24:
    ctx->pc = 0x802CBC24u;
    // 802CBC24: bl      0x802D3D34
    {
            ctx->lr = 0x802CBC28u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBC28:
    ctx->pc = 0x802CBC28u;
    ctx->downcount -= 5;
    // 802CBC28: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_802CBC2C:
    ctx->pc = 0x802CBC2Cu;
    // 802CBC2C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_802CBC30:
    ctx->pc = 0x802CBC30u;
    // 802CBC30: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_802CBC34:
    ctx->pc = 0x802CBC34u;
    // 802CBC34: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_802CBC38:
    ctx->pc = 0x802CBC38u;
    // 802CBC38: bl      0x802D3D34
    {
            ctx->lr = 0x802CBC3Cu;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBC3C:
    ctx->pc = 0x802CBC3Cu;
    ctx->downcount -= 5;
    // 802CBC3C: li      r3, 8
    ctx->gpr[3] = (u32)(s32)(8);

label_802CBC40:
    ctx->pc = 0x802CBC40u;
    // 802CBC40: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_802CBC44:
    ctx->pc = 0x802CBC44u;
    // 802CBC44: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_802CBC48:
    ctx->pc = 0x802CBC48u;
    // 802CBC48: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_802CBC4C:
    ctx->pc = 0x802CBC4Cu;
    // 802CBC4C: bl      0x802D3D34
    {
            ctx->lr = 0x802CBC50u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBC50:
    ctx->pc = 0x802CBC50u;
    ctx->downcount -= 5;
    // 802CBC50: li      r3, 9
    ctx->gpr[3] = (u32)(s32)(9);

label_802CBC54:
    ctx->pc = 0x802CBC54u;
    // 802CBC54: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_802CBC58:
    ctx->pc = 0x802CBC58u;
    // 802CBC58: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_802CBC5C:
    ctx->pc = 0x802CBC5Cu;
    // 802CBC5C: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_802CBC60:
    ctx->pc = 0x802CBC60u;
    // 802CBC60: bl      0x802D3D34
    {
            ctx->lr = 0x802CBC64u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBC64:
    ctx->pc = 0x802CBC64u;
    ctx->downcount -= 5;
    // 802CBC64: li      r3, 10
    ctx->gpr[3] = (u32)(s32)(10);

label_802CBC68:
    ctx->pc = 0x802CBC68u;
    // 802CBC68: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_802CBC6C:
    ctx->pc = 0x802CBC6Cu;
    // 802CBC6C: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_802CBC70:
    ctx->pc = 0x802CBC70u;
    // 802CBC70: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_802CBC74:
    ctx->pc = 0x802CBC74u;
    // 802CBC74: bl      0x802D3D34
    {
            ctx->lr = 0x802CBC78u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBC78:
    ctx->pc = 0x802CBC78u;
    ctx->downcount -= 5;
    // 802CBC78: li      r3, 11
    ctx->gpr[3] = (u32)(s32)(11);

label_802CBC7C:
    ctx->pc = 0x802CBC7Cu;
    // 802CBC7C: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_802CBC80:
    ctx->pc = 0x802CBC80u;
    // 802CBC80: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_802CBC84:
    ctx->pc = 0x802CBC84u;
    // 802CBC84: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_802CBC88:
    ctx->pc = 0x802CBC88u;
    // 802CBC88: bl      0x802D3D34
    {
            ctx->lr = 0x802CBC8Cu;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBC8C:
    ctx->pc = 0x802CBC8Cu;
    ctx->downcount -= 5;
    // 802CBC8C: li      r3, 12
    ctx->gpr[3] = (u32)(s32)(12);

label_802CBC90:
    ctx->pc = 0x802CBC90u;
    // 802CBC90: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_802CBC94:
    ctx->pc = 0x802CBC94u;
    // 802CBC94: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_802CBC98:
    ctx->pc = 0x802CBC98u;
    // 802CBC98: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_802CBC9C:
    ctx->pc = 0x802CBC9Cu;
    // 802CBC9C: bl      0x802D3D34
    {
            ctx->lr = 0x802CBCA0u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBCA0:
    ctx->pc = 0x802CBCA0u;
    ctx->downcount -= 5;
    // 802CBCA0: li      r3, 13
    ctx->gpr[3] = (u32)(s32)(13);

label_802CBCA4:
    ctx->pc = 0x802CBCA4u;
    // 802CBCA4: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_802CBCA8:
    ctx->pc = 0x802CBCA8u;
    // 802CBCA8: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_802CBCAC:
    ctx->pc = 0x802CBCACu;
    // 802CBCAC: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_802CBCB0:
    ctx->pc = 0x802CBCB0u;
    // 802CBCB0: bl      0x802D3D34
    {
            ctx->lr = 0x802CBCB4u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBCB4:
    ctx->pc = 0x802CBCB4u;
    ctx->downcount -= 5;
    // 802CBCB4: li      r3, 14
    ctx->gpr[3] = (u32)(s32)(14);

label_802CBCB8:
    ctx->pc = 0x802CBCB8u;
    // 802CBCB8: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_802CBCBC:
    ctx->pc = 0x802CBCBCu;
    // 802CBCBC: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_802CBCC0:
    ctx->pc = 0x802CBCC0u;
    // 802CBCC0: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_802CBCC4:
    ctx->pc = 0x802CBCC4u;
    // 802CBCC4: bl      0x802D3D34
    {
            ctx->lr = 0x802CBCC8u;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBCC8:
    ctx->pc = 0x802CBCC8u;
    ctx->downcount -= 5;
    // 802CBCC8: li      r3, 15
    ctx->gpr[3] = (u32)(s32)(15);

label_802CBCCC:
    ctx->pc = 0x802CBCCCu;
    // 802CBCCC: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_802CBCD0:
    ctx->pc = 0x802CBCD0u;
    // 802CBCD0: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_802CBCD4:
    ctx->pc = 0x802CBCD4u;
    // 802CBCD4: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_802CBCD8:
    ctx->pc = 0x802CBCD8u;
    // 802CBCD8: bl      0x802D3D34
    {
            ctx->lr = 0x802CBCDCu;
            ctx->pc = 0x802D3D34u;
            return;
    }

label_802CBCDC:
    ctx->pc = 0x802CBCDCu;
    ctx->downcount -= 2;
    // 802CBCDC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBCE0:
    ctx->pc = 0x802CBCE0u;
    // 802CBCE0: bl      0x802D3F0C
    {
            ctx->lr = 0x802CBCE4u;
            ctx->pc = 0x802D3F0Cu;
            return;
    }

label_802CBCE4:
    ctx->pc = 0x802CBCE4u;
    ctx->downcount -= 3;
    // 802CBCE4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBCE8:
    ctx->pc = 0x802CBCE8u;
    // 802CBCE8: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_802CBCEC:
    ctx->pc = 0x802CBCECu;
    // 802CBCEC: bl      0x802D3754
    {
            ctx->lr = 0x802CBCF0u;
            ctx->pc = 0x802D3754u;
            return;
    }

label_802CBCF0:
    ctx->pc = 0x802CBCF0u;
    ctx->downcount -= 6;
    // 802CBCF0: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_802CBCF4:
    ctx->pc = 0x802CBCF4u;
    // 802CBCF4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBCF8:
    ctx->pc = 0x802CBCF8u;
    // 802CBCF8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBCFC:
    ctx->pc = 0x802CBCFCu;
    // 802CBCFC: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_802CBD00:
    ctx->pc = 0x802CBD00u;
    // 802CBD00: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_802CBD04:
    ctx->pc = 0x802CBD04u;
    // 802CBD04: bl      0x802D3C5C
    {
            ctx->lr = 0x802CBD08u;
            ctx->pc = 0x802D3C5Cu;
            return;
    }

label_802CBD08:
    ctx->pc = 0x802CBD08u;
    ctx->downcount -= 4;
    // 802CBD08: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBD0C:
    ctx->pc = 0x802CBD0Cu;
    // 802CBD0C: li      r4, 17
    ctx->gpr[4] = (u32)(s32)(17);

label_802CBD10:
    ctx->pc = 0x802CBD10u;
    // 802CBD10: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBD14:
    ctx->pc = 0x802CBD14u;
    // 802CBD14: bl      0x802D3CB0
    {
            ctx->lr = 0x802CBD18u;
            ctx->pc = 0x802D3CB0u;
            return;
    }

label_802CBD18:
    ctx->pc = 0x802CBD18u;
    ctx->downcount -= 1;
    // 802CBD18: b       0x802CBD1C
    {
            goto label_802CBD1C;
    }

label_802CBD1C:
    ctx->pc = 0x802CBD1Cu;
    ctx->downcount -= 1;
    // 802CBD1C: b       0x802CBD20
    {
            goto label_802CBD20;
    }

label_802CBD20:
    ctx->pc = 0x802CBD20u;
    ctx->downcount -= 1;
    // 802CBD20: b       0x802CBD24
    {
            goto label_802CBD24;
    }

label_802CBD24:
    ctx->downcount -= 3;
    // 802CBD24: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802CBD28:
    // 802CBD28: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_802CBD2C:
    // 802CBD2C: bl      0x802D3A94
    {
            ctx->lr = 0x802CBD30u;
            ctx->pc = 0x802D3A94u;
            return;
    }

label_802CBD30:
    ctx->downcount -= 3;
    // 802CBD30: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802CBD34:
    // 802CBD34: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBD38:
    // 802CBD38: bl      0x802D3B00
    {
            ctx->lr = 0x802CBD3Cu;
            ctx->pc = 0x802D3B00u;
            return;
    }

label_802CBD3C:
    ctx->downcount -= 4;
    // 802CBD3C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802CBD40:
    // 802CBD40: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBD44:
    // 802CBD44: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBD48:
    // 802CBD48: bl      0x802D3B6C
    {
            ctx->lr = 0x802CBD4Cu;
            ctx->pc = 0x802D3B6Cu;
            return;
    }

label_802CBD4C:
    ctx->downcount -= 3;
    // 802CBD4C: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_802CBD50:
    // 802CBD50: cmplwi  r30, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CBD54:
    // 802CBD54: bc    12, 0, 0x802CBD24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CBD24u;
                return;
            }
            goto label_802CBD24;
        }
    }

label_802CBD58:
    ctx->pc = 0x802CBD58u;
    ctx->downcount -= 6;
    // 802CBD58: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBD5C:
    ctx->pc = 0x802CBD5Cu;
    // 802CBD5C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBD60:
    ctx->pc = 0x802CBD60u;
    // 802CBD60: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802CBD64:
    ctx->pc = 0x802CBD64u;
    // 802CBD64: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_802CBD68:
    ctx->pc = 0x802CBD68u;
    // 802CBD68: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_802CBD6C:
    ctx->pc = 0x802CBD6Cu;
    // 802CBD6C: bl      0x802D3BC0
    {
            ctx->lr = 0x802CBD70u;
            ctx->pc = 0x802D3BC0u;
            return;
    }

label_802CBD70:
    ctx->pc = 0x802CBD70u;
    ctx->downcount -= 6;
    // 802CBD70: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBD74:
    ctx->pc = 0x802CBD74u;
    // 802CBD74: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBD78:
    ctx->pc = 0x802CBD78u;
    // 802CBD78: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBD7C:
    ctx->pc = 0x802CBD7Cu;
    // 802CBD7C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_802CBD80:
    ctx->pc = 0x802CBD80u;
    // 802CBD80: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_802CBD84:
    ctx->pc = 0x802CBD84u;
    // 802CBD84: bl      0x802D3BC0
    {
            ctx->lr = 0x802CBD88u;
            ctx->pc = 0x802D3BC0u;
            return;
    }

label_802CBD88:
    ctx->pc = 0x802CBD88u;
    ctx->downcount -= 6;
    // 802CBD88: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802CBD8C:
    ctx->pc = 0x802CBD8Cu;
    // 802CBD8C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CBD90:
    ctx->pc = 0x802CBD90u;
    // 802CBD90: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802CBD94:
    ctx->pc = 0x802CBD94u;
    // 802CBD94: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_802CBD98:
    ctx->pc = 0x802CBD98u;
    // 802CBD98: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_802CBD9C:
    ctx->pc = 0x802CBD9Cu;
    // 802CBD9C: bl      0x802D3BC0
    {
            ctx->lr = 0x802CBDA0u;
            ctx->pc = 0x802D3BC0u;
            return;
    }

label_802CBDA0:
    ctx->pc = 0x802CBDA0u;
    ctx->downcount -= 6;
    // 802CBDA0: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_802CBDA4:
    ctx->pc = 0x802CBDA4u;
    // 802CBDA4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802CBDA8:
    ctx->pc = 0x802CBDA8u;
    // 802CBDA8: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_802CBDAC:
    ctx->pc = 0x802CBDACu;
    // 802CBDAC: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_802CBDB0:
    ctx->pc = 0x802CBDB0u;
    // 802CBDB0: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_802CBDB4:
    ctx->pc = 0x802CBDB4u;
    // 802CBDB4: bl      0x802D3BC0
    {
            ctx->lr = 0x802CBDB8u;
            ctx->pc = 0x802D3BC0u;
            return;
    }

label_802CBDB8:
    ctx->pc = 0x802CBDB8u;
    ctx->downcount -= 2;
    // 802CBDB8: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_802CBDBC:
    ctx->pc = 0x802CBDBCu;
    // 802CBDBC: b       0x802CBDC0
    {
            goto label_802CBDC0;
    }

label_802CBDC0:
    ctx->pc = 0x802CBDC0u;
    ctx->downcount -= 1;
    // 802CBDC0: b       0x802CBDC4
    {
            goto label_802CBDC4;
    }

label_802CBDC4:
    ctx->pc = 0x802CBDC4u;
    ctx->downcount -= 1;
    // 802CBDC4: b       0x802CBDC8
    {
            goto label_802CBDC8;
    }

label_802CBDC8:
    ctx->downcount -= 2;
    // 802CBDC8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802CBDCC:
    // 802CBDCC: bl      0x802D3274
    {
            ctx->lr = 0x802CBDD0u;
            ctx->pc = 0x802D3274u;
            return;
    }

label_802CBDD0:
    ctx->downcount -= 3;
    // 802CBDD0: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_802CBDD4:
    // 802CBDD4: cmplwi  r30, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CBDD8:
    // 802CBDD8: bc    12, 0, 0x802CBDC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CBDC8u;
                return;
            }
            goto label_802CBDC8;
        }
    }

label_802CBDDC:
    ctx->pc = 0x802CBDDCu;
    ctx->downcount -= 2;
    // 802CBDDC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBDE0:
    ctx->pc = 0x802CBDE0u;
    // 802CBDE0: bl      0x802D324C
    {
            ctx->lr = 0x802CBDE4u;
            ctx->pc = 0x802D324Cu;
            return;
    }

label_802CBDE4:
    ctx->pc = 0x802CBDE4u;
    ctx->downcount -= 4;
    // 802CBDE4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBDE8:
    ctx->pc = 0x802CBDE8u;
    // 802CBDE8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBDEC:
    ctx->pc = 0x802CBDECu;
    // 802CBDEC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBDF0:
    ctx->pc = 0x802CBDF0u;
    // 802CBDF0: bl      0x802D2FBC
    {
            ctx->lr = 0x802CBDF4u;
            ctx->pc = 0x802D2FBCu;
            return;
    }

label_802CBDF4:
    ctx->pc = 0x802CBDF4u;
    ctx->downcount -= 4;
    // 802CBDF4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBDF8:
    ctx->pc = 0x802CBDF8u;
    // 802CBDF8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBDFC:
    ctx->pc = 0x802CBDFCu;
    // 802CBDFC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBE00:
    ctx->pc = 0x802CBE00u;
    // 802CBE00: bl      0x802D2FBC
    {
            ctx->lr = 0x802CBE04u;
            ctx->pc = 0x802D2FBCu;
            return;
    }

label_802CBE04:
    ctx->pc = 0x802CBE04u;
    ctx->downcount -= 4;
    // 802CBE04: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802CBE08:
    ctx->pc = 0x802CBE08u;
    // 802CBE08: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBE0C:
    ctx->pc = 0x802CBE0Cu;
    // 802CBE0C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBE10:
    ctx->pc = 0x802CBE10u;
    // 802CBE10: bl      0x802D2FBC
    {
            ctx->lr = 0x802CBE14u;
            ctx->pc = 0x802D2FBCu;
            return;
    }

label_802CBE14:
    ctx->pc = 0x802CBE14u;
    ctx->downcount -= 4;
    // 802CBE14: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_802CBE18:
    ctx->pc = 0x802CBE18u;
    // 802CBE18: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBE1C:
    ctx->pc = 0x802CBE1Cu;
    // 802CBE1C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBE20:
    ctx->pc = 0x802CBE20u;
    // 802CBE20: bl      0x802D2FBC
    {
            ctx->lr = 0x802CBE24u;
            ctx->pc = 0x802D2FBCu;
            return;
    }

label_802CBE24:
    ctx->pc = 0x802CBE24u;
    ctx->downcount -= 9;
    // 802CBE24: lfs     f2, -3352(r13)
    if (!ppc_fp_available_inline(ctx, 0x802CBE24u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3352);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_802CBE28:
    ctx->pc = 0x802CBE28u;
    // 802CBE28: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_802CBE2C:
    ctx->pc = 0x802CBE2Cu;
    // 802CBE2C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CBE30:
    ctx->pc = 0x802CBE30u;
    // 802CBE30: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBE34:
    ctx->pc = 0x802CBE34u;
    // 802CBE34: fmr    f4, f2
    if (!ppc_fp_available_inline(ctx, 0x802CBE34u)) return;
    ctx->fpr[4] = ctx->fpr[2];

label_802CBE38:
    ctx->pc = 0x802CBE38u;
    // 802CBE38: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CBE3C:
    ctx->pc = 0x802CBE3Cu;
    // 802CBE3C: lfs     f1, -3348(r13)
    if (!ppc_fp_available_inline(ctx, 0x802CBE3Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3348);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_802CBE40:
    ctx->pc = 0x802CBE40u;
    // 802CBE40: lfs     f3, -3344(r13)
    if (!ppc_fp_available_inline(ctx, 0x802CBE40u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3344);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_802CBE44:
    ctx->pc = 0x802CBE44u;
    // 802CBE44: bl      0x802D3F3C
    {
            ctx->lr = 0x802CBE48u;
            ctx->pc = 0x802D3F3Cu;
            return;
    }

label_802CBE48:
    ctx->pc = 0x802CBE48u;
    ctx->downcount -= 4;
    // 802CBE48: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBE4C:
    ctx->pc = 0x802CBE4Cu;
    // 802CBE4C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBE50:
    ctx->pc = 0x802CBE50u;
    // 802CBE50: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CBE54:
    ctx->pc = 0x802CBE54u;
    // 802CBE54: bl      0x802D4320
    {
            ctx->lr = 0x802CBE58u;
            ctx->pc = 0x802D4320u;
            return;
    }

label_802CBE58:
    ctx->pc = 0x802CBE58u;
    ctx->downcount -= 5;
    // 802CBE58: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBE5C:
    ctx->pc = 0x802CBE5Cu;
    // 802CBE5C: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802CBE60:
    ctx->pc = 0x802CBE60u;
    // 802CBE60: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_802CBE64:
    ctx->pc = 0x802CBE64u;
    // 802CBE64: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_802CBE68:
    ctx->pc = 0x802CBE68u;
    // 802CBE68: bl      0x802D4420
    {
            ctx->lr = 0x802CBE6Cu;
            ctx->pc = 0x802D4420u;
            return;
    }

label_802CBE6C:
    ctx->pc = 0x802CBE6Cu;
    ctx->downcount -= 2;
    // 802CBE6C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBE70:
    ctx->pc = 0x802CBE70u;
    // 802CBE70: bl      0x802D4474
    {
            ctx->lr = 0x802CBE74u;
            ctx->pc = 0x802D4474u;
            return;
    }

label_802CBE74:
    ctx->pc = 0x802CBE74u;
    ctx->downcount -= 2;
    // 802CBE74: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBE78:
    ctx->pc = 0x802CBE78u;
    // 802CBE78: bl      0x802D44A0
    {
            ctx->lr = 0x802CBE7Cu;
            ctx->pc = 0x802D44A0u;
            return;
    }

label_802CBE7C:
    ctx->pc = 0x802CBE7Cu;
    ctx->downcount -= 4;
    // 802CBE7C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBE80:
    ctx->pc = 0x802CBE80u;
    // 802CBE80: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_802CBE84:
    ctx->pc = 0x802CBE84u;
    // 802CBE84: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802CBE88:
    ctx->pc = 0x802CBE88u;
    // 802CBE88: bl      0x802D44CC
    {
            ctx->lr = 0x802CBE8Cu;
            ctx->pc = 0x802D44CCu;
            return;
    }

label_802CBE8C:
    ctx->pc = 0x802CBE8Cu;
    ctx->downcount -= 2;
    // 802CBE8C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBE90:
    ctx->pc = 0x802CBE90u;
    // 802CBE90: bl      0x802D4500
    {
            ctx->lr = 0x802CBE94u;
            ctx->pc = 0x802D4500u;
            return;
    }

label_802CBE94:
    ctx->pc = 0x802CBE94u;
    ctx->downcount -= 2;
    // 802CBE94: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBE98:
    ctx->pc = 0x802CBE98u;
    // 802CBE98: bl      0x802D4620
    {
            ctx->lr = 0x802CBE9Cu;
            ctx->pc = 0x802D4620u;
            return;
    }

label_802CBE9C:
    ctx->pc = 0x802CBE9Cu;
    ctx->downcount -= 3;
    // 802CBE9C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBEA0:
    ctx->pc = 0x802CBEA0u;
    // 802CBEA0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBEA4:
    ctx->pc = 0x802CBEA4u;
    // 802CBEA4: bl      0x802D464C
    {
            ctx->lr = 0x802CBEA8u;
            ctx->pc = 0x802D464Cu;
            return;
    }

label_802CBEA8:
    ctx->pc = 0x802CBEA8u;
    ctx->downcount -= 3;
    // 802CBEA8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBEAC:
    ctx->pc = 0x802CBEACu;
    // 802CBEAC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBEB0:
    ctx->pc = 0x802CBEB0u;
    // 802CBEB0: bl      0x802D4538
    {
            ctx->lr = 0x802CBEB4u;
            ctx->pc = 0x802D4538u;
            return;
    }

label_802CBEB4:
    ctx->pc = 0x802CBEB4u;
    ctx->downcount -= 3;
    // 802CBEB4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBEB8:
    ctx->pc = 0x802CBEB8u;
    // 802CBEB8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CBEBC:
    ctx->pc = 0x802CBEBCu;
    // 802CBEBC: bl      0x802D4688
    {
            ctx->lr = 0x802CBEC0u;
            ctx->pc = 0x802D4688u;
            return;
    }

label_802CBEC0:
    ctx->pc = 0x802CBEC0u;
    ctx->downcount -= 5;
    // 802CBEC0: lhz     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CBEC4:
    ctx->pc = 0x802CBEC4u;
    // 802CBEC4: lhz     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CBEC8:
    ctx->pc = 0x802CBEC8u;
    // 802CBEC8: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_802CBECC:
    ctx->pc = 0x802CBECCu;
    // 802CBECC: cmpw    r3, r0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CBED0:
    ctx->pc = 0x802CBED0u;
    // 802CBED0: bc    4, 2, 0x802CBEDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CBEDC;
        }
    }

label_802CBED4:
    ctx->pc = 0x802CBED4u;
    ctx->downcount -= 2;
    // 802CBED4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CBED8:
    ctx->pc = 0x802CBED8u;
    // 802CBED8: b       0x802CBEE0
    {
            goto label_802CBEE0;
    }

label_802CBEDC:
    ctx->pc = 0x802CBEDCu;
    ctx->downcount -= 1;
    // 802CBEDC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBEE0:
    ctx->pc = 0x802CBEE0u;
    ctx->downcount -= 2;
    // 802CBEE0: lbz     r3, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_802CBEE4:
    ctx->pc = 0x802CBEE4u;
    // 802CBEE4: bl      0x802D46C0
    {
            ctx->lr = 0x802CBEE8u;
            ctx->pc = 0x802D46C0u;
            return;
    }

label_802CBEE8:
    ctx->pc = 0x802CBEE8u;
    ctx->downcount -= 5;
    // 802CBEE8: lhz     r5, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_802CBEEC:
    ctx->pc = 0x802CBEECu;
    // 802CBEEC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBEF0:
    ctx->pc = 0x802CBEF0u;
    // 802CBEF0: lhz     r6, 6(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(6);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_802CBEF4:
    ctx->pc = 0x802CBEF4u;
    // 802CBEF4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBEF8:
    ctx->pc = 0x802CBEF8u;
    // 802CBEF8: bl      0x802CFCE8
    {
            ctx->lr = 0x802CBEFCu;
            ctx->pc = 0x802CFCE8u;
            return;
    }

label_802CBEFC:
    ctx->pc = 0x802CBEFCu;
    ctx->downcount -= 3;
    // 802CBEFC: lhz     r3, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CBF00:
    ctx->pc = 0x802CBF00u;
    // 802CBF00: lhz     r4, 6(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(6);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CBF04:
    ctx->pc = 0x802CBF04u;
    // 802CBF04: bl      0x802CFE08
    {
            ctx->lr = 0x802CBF08u;
            ctx->pc = 0x802CFE08u;
            return;
    }

label_802CBF08:
    ctx->pc = 0x802CBF08u;
    ctx->downcount -= 30;
    // 802CBF08: lhz     r4, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CBF0C:
    ctx->pc = 0x802CBF0Cu;
    // 802CBF0C: lis     r3, 17200
    ctx->gpr[3] = ((u32)(s32)(17200) << 16);

label_802CBF10:
    ctx->pc = 0x802CBF10u;
    // 802CBF10: lhz     r0, 6(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(6);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CBF14:
    ctx->pc = 0x802CBF14u;
    // 802CBF14: stw     r4, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CBF18:
    ctx->pc = 0x802CBF18u;
    // 802CBF18: lfd     f2, -3336(r13)
    if (!ppc_fp_available_inline(ctx, 0x802CBF18u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3336);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_802CBF1C:
    ctx->pc = 0x802CBF1Cu;
    // 802CBF1C: stw     r0, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CBF20:
    ctx->pc = 0x802CBF20u;
    // 802CBF20: stw     r3, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CBF24:
    ctx->pc = 0x802CBF24u;
    // 802CBF24: stw     r3, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CBF28:
    ctx->pc = 0x802CBF28u;
    // 802CBF28: lfd     f1, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CBF28u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_802CBF2C:
    ctx->pc = 0x802CBF2Cu;
    // 802CBF2C: lfd     f0, 104(r1)
    if (!ppc_fp_available_inline(ctx, 0x802CBF2Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_802CBF30:
    ctx->pc = 0x802CBF30u;
    // 802CBF30: fsubs   f1, f1, f2
    if (!ppc_fp_available_inline(ctx, 0x802CBF30u)) return;
    ppc_fsubs(ctx, 1, 1, 2);

label_802CBF34:
    ctx->pc = 0x802CBF34u;
    // 802CBF34: fsubs   f0, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x802CBF34u)) return;
    ppc_fsubs(ctx, 0, 0, 2);

label_802CBF38:
    ctx->pc = 0x802CBF38u;
    // 802CBF38: fdivs   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x802CBF38u)) return;
    ppc_fdivs(ctx, 1, 1, 0);

label_802CBF3C:
    ctx->pc = 0x802CBF3Cu;
    // 802CBF3C: bl      0x802D0348
    {
            ctx->lr = 0x802CBF40u;
            ctx->pc = 0x802D0348u;
            return;
    }

label_802CBF40:
    ctx->pc = 0x802CBF40u;
    ctx->downcount -= 2;
    // 802CBF40: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_802CBF44:
    ctx->pc = 0x802CBF44u;
    // 802CBF44: bl      0x802CFFC0
    {
            ctx->lr = 0x802CBF48u;
            ctx->pc = 0x802CFFC0u;
            return;
    }

label_802CBF48:
    ctx->pc = 0x802CBF48u;
    ctx->downcount -= 5;
    // 802CBF48: lbz     r3, 25(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(25);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_802CBF4C:
    ctx->pc = 0x802CBF4Cu;
    // 802CBF4C: addi    r4, r31, 26
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(26);

label_802CBF50:
    ctx->pc = 0x802CBF50u;
    // 802CBF50: addi    r6, r31, 50
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(50);

label_802CBF54:
    ctx->pc = 0x802CBF54u;
    // 802CBF54: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802CBF58:
    ctx->pc = 0x802CBF58u;
    // 802CBF58: bl      0x802D0478
    {
            ctx->lr = 0x802CBF5Cu;
            ctx->pc = 0x802D0478u;
            return;
    }

label_802CBF5C:
    ctx->pc = 0x802CBF5Cu;
    ctx->downcount -= 2;
    // 802CBF5C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBF60:
    ctx->pc = 0x802CBF60u;
    // 802CBF60: bl      0x802D06A0
    {
            ctx->lr = 0x802CBF64u;
            ctx->pc = 0x802D06A0u;
            return;
    }

label_802CBF64:
    ctx->pc = 0x802CBF64u;
    ctx->downcount -= 2;
    // 802CBF64: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBF68:
    ctx->pc = 0x802CBF68u;
    // 802CBF68: bl      0x802CFF98
    {
            ctx->lr = 0x802CBF6Cu;
            ctx->pc = 0x802CFF98u;
            return;
    }

label_802CBF6C:
    ctx->pc = 0x802CBF6Cu;
    ctx->downcount -= 1;
    // 802CBF6C: bl      0x802D0994
    {
            ctx->lr = 0x802CBF70u;
            ctx->pc = 0x802D0994u;
            return;
    }

label_802CBF70:
    ctx->pc = 0x802CBF70u;
    ctx->downcount -= 2;
    // 802CBF70: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBF74:
    ctx->pc = 0x802CBF74u;
    // 802CBF74: bl      0x802CF230
    {
            ctx->lr = 0x802CBF78u;
            goto label_802CF230;
    }

label_802CBF78:
    ctx->pc = 0x802CBF78u;
    ctx->downcount -= 2;
    // 802CBF78: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBF7C:
    ctx->pc = 0x802CBF7Cu;
    // 802CBF7C: bl      0x802CF18C
    {
            ctx->lr = 0x802CBF80u;
            goto label_802CF18C;
    }

label_802CBF80:
    ctx->pc = 0x802CBF80u;
    ctx->downcount -= 2;
    // 802CBF80: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBF84:
    ctx->pc = 0x802CBF84u;
    // 802CBF84: bl      0x802CF260
    {
            ctx->lr = 0x802CBF88u;
            goto label_802CF260;
    }

label_802CBF88:
    ctx->pc = 0x802CBF88u;
    ctx->downcount -= 5;
    // 802CBF88: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBF8C:
    ctx->pc = 0x802CBF8Cu;
    // 802CBF8C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBF90:
    ctx->pc = 0x802CBF90u;
    // 802CBF90: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802CBF94:
    ctx->pc = 0x802CBF94u;
    // 802CBF94: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_802CBF98:
    ctx->pc = 0x802CBF98u;
    // 802CBF98: bl      0x802CF1A8
    {
            ctx->lr = 0x802CBF9Cu;
            goto label_802CF1A8;
    }

label_802CBF9C:
    ctx->pc = 0x802CBF9Cu;
    ctx->downcount -= 3;
    // 802CBF9C: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_802CBFA0:
    ctx->pc = 0x802CBFA0u;
    // 802CBFA0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBFA4:
    ctx->pc = 0x802CBFA4u;
    // 802CBFA4: bl      0x802CF164
    {
            ctx->lr = 0x802CBFA8u;
            goto label_802CF164;
    }

label_802CBFA8:
    ctx->pc = 0x802CBFA8u;
    ctx->downcount -= 2;
    // 802CBFA8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBFAC:
    ctx->pc = 0x802CBFACu;
    // 802CBFAC: bl      0x802CF178
    {
            ctx->lr = 0x802CBFB0u;
            goto label_802CF178;
    }

label_802CBFB0:
    ctx->pc = 0x802CBFB0u;
    ctx->downcount -= 3;
    // 802CBFB0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CBFB4:
    ctx->pc = 0x802CBFB4u;
    // 802CBFB4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CBFB8:
    ctx->pc = 0x802CBFB8u;
    // 802CBFB8: bl      0x802CF24C
    {
            ctx->lr = 0x802CBFBCu;
            goto label_802CF24C;
    }

label_802CBFBC:
    ctx->pc = 0x802CBFBCu;
    ctx->downcount -= 4;
    // 802CBFBC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CBFC0:
    ctx->pc = 0x802CBFC0u;
    // 802CBFC0: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_802CBFC4:
    ctx->pc = 0x802CBFC4u;
    // 802CBFC4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802CBFC8:
    ctx->pc = 0x802CBFC8u;
    // 802CBFC8: bl      0x802CF27C
    {
            ctx->lr = 0x802CBFCCu;
            goto label_802CF27C;
    }

label_802CBFCC:
    ctx->pc = 0x802CBFCCu;
    ctx->downcount -= 3;
    // 802CBFCC: li      r3, 35
    ctx->gpr[3] = (u32)(s32)(35);

label_802CBFD0:
    ctx->pc = 0x802CBFD0u;
    // 802CBFD0: li      r4, 22
    ctx->gpr[4] = (u32)(s32)(22);

label_802CBFD4:
    ctx->pc = 0x802CBFD4u;
    // 802CBFD4: bl      0x802D52F0
    {
            ctx->lr = 0x802CBFD8u;
            ctx->pc = 0x802D52F0u;
            return;
    }

label_802CBFD8:
    ctx->pc = 0x802CBFD8u;
    ctx->downcount -= 1;
    // 802CBFD8: bl      0x802D5CE0
    {
            ctx->lr = 0x802CBFDCu;
            ctx->pc = 0x802D5CE0u;
            return;
    }

label_802CBFDC:
    ctx->pc = 0x802CBFDCu;
    ctx->downcount -= 8;
    // 802CBFDC: lwz     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CBFE0:
    ctx->pc = 0x802CBFE0u;
    // 802CBFE0: lwz     r31, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CBFE4:
    ctx->pc = 0x802CBFE4u;
    // 802CBFE4: lwz     r30, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CBFE8:
    ctx->pc = 0x802CBFE8u;
    // 802CBFE8: lwz     r29, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802CBFEC:
    ctx->pc = 0x802CBFECu;
    // 802CBFEC: addi    r1, r1, 128
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(128);

label_802CBFF0:
    ctx->pc = 0x802CBFF0u;
    // 802CBFF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CBFF4:
    ctx->pc = 0x802CBFF4u;
    // 802CBFF4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CBFF8:
    ctx->pc = 0x802CBFF8u;
    ctx->downcount -= 9;
    // 802CBFF8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CBFFC:
    ctx->pc = 0x802CBFFCu;
    // 802CBFFC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CC000:
    ctx->pc = 0x802CC000u;
    // 802CC000: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC004:
    ctx->pc = 0x802CC004u;
    // 802CC004: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CC008:
    ctx->pc = 0x802CC008u;
    // 802CC008: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC00C:
    ctx->pc = 0x802CC00Cu;
    // 802CC00C: lwz     r5, -25336(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25336);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CC010:
    ctx->pc = 0x802CC010u;
    // 802CC010: addi    r0, r5, 1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(1);

label_802CC014:
    ctx->pc = 0x802CC014u;
    // 802CC014: stw     r0, -25336(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25336);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC018:
    ctx->pc = 0x802CC018u;
    // 802CC018: bl      0x802CCAE8
    {
            ctx->lr = 0x802CC01Cu;
            goto label_802CCAE8;
    }

label_802CC01C:
    ctx->pc = 0x802CC01Cu;
    ctx->downcount -= 3;
    // 802CC01C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC020:
    ctx->pc = 0x802CC020u;
    // 802CC020: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CC024:
    ctx->pc = 0x802CC024u;
    // 802CC024: bl      0x802CCB24
    {
            ctx->lr = 0x802CC028u;
            goto label_802CCB24;
    }

label_802CC028:
    ctx->pc = 0x802CC028u;
    ctx->downcount -= 4;
    // 802CC028: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802CC02C:
    ctx->pc = 0x802CC02Cu;
    // 802CC02C: lwz     r3, -25352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25352);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC030:
    ctx->pc = 0x802CC030u;
    // 802CC030: stw     r0, -25344(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25344);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC034:
    ctx->pc = 0x802CC034u;
    // 802CC034: bl      0x802C847C
    {
            ctx->lr = 0x802CC038u;
            ctx->pc = 0x802C847Cu;
            return;
    }

label_802CC038:
    ctx->pc = 0x802CC038u;
    ctx->downcount -= 5;
    // 802CC038: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC03C:
    ctx->pc = 0x802CC03Cu;
    // 802CC03C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802CC040:
    ctx->pc = 0x802CC040u;
    // 802CC040: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC044:
    ctx->pc = 0x802CC044u;
    // 802CC044: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC048:
    ctx->pc = 0x802CC048u;
    ctx->downcount -= 5;
    // 802CC048: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC04C:
    ctx->pc = 0x802CC04Cu;
    // 802CC04C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC050:
    ctx->pc = 0x802CC050u;
    // 802CC050: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC054:
    ctx->pc = 0x802CC054u;
    // 802CC054: lwz     r3, -25352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25352);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC058:
    ctx->pc = 0x802CC058u;
    // 802CC058: bl      0x802C81F4
    {
            ctx->lr = 0x802CC05Cu;
            ctx->pc = 0x802C81F4u;
            return;
    }

label_802CC05C:
    ctx->pc = 0x802CC05Cu;
    ctx->downcount -= 5;
    // 802CC05C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CC060:
    ctx->pc = 0x802CC060u;
    // 802CC060: stw     r0, -25344(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25344);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC064:
    ctx->pc = 0x802CC064u;
    // 802CC064: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC068:
    ctx->pc = 0x802CC068u;
    // 802CC068: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CC06C:
    ctx->pc = 0x802CC06Cu;
    // 802CC06C: bl      0x802CCB24
    {
            ctx->lr = 0x802CC070u;
            goto label_802CCB24;
    }

label_802CC070:
    ctx->pc = 0x802CC070u;
    ctx->downcount -= 3;
    // 802CC070: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC074:
    ctx->pc = 0x802CC074u;
    // 802CC074: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CC078:
    ctx->pc = 0x802CC078u;
    // 802CC078: bl      0x802CCAE8
    {
            ctx->lr = 0x802CC07Cu;
            goto label_802CCAE8;
    }

label_802CC07C:
    ctx->pc = 0x802CC07Cu;
    ctx->downcount -= 5;
    // 802CC07C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC080:
    ctx->pc = 0x802CC080u;
    // 802CC080: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802CC084:
    ctx->pc = 0x802CC084u;
    // 802CC084: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC088:
    ctx->pc = 0x802CC088u;
    // 802CC088: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC08C:
    ctx->pc = 0x802CC08Cu;
    ctx->downcount -= 15;
    // 802CC08C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC090:
    ctx->pc = 0x802CC090u;
    // 802CC090: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC094:
    ctx->pc = 0x802CC094u;
    // 802CC094: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC098:
    ctx->pc = 0x802CC098u;
    // 802CC098: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CC09C:
    ctx->pc = 0x802CC09Cu;
    // 802CC09C: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_802CC0A0:
    ctx->pc = 0x802CC0A0u;
    // 802CC0A0: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC0A4:
    ctx->pc = 0x802CC0A4u;
    // 802CC0A4: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC0A8:
    ctx->pc = 0x802CC0A8u;
    // 802CC0A8: rlwinm r0, r0, 0, 27, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFDFu;
    }

label_802CC0AC:
    ctx->pc = 0x802CC0ACu;
    // 802CC0AC: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC0B0:
    ctx->pc = 0x802CC0B0u;
    // 802CC0B0: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC0B4:
    ctx->pc = 0x802CC0B4u;
    // 802CC0B4: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC0B8:
    ctx->pc = 0x802CC0B8u;
    // 802CC0B8: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC0BC:
    ctx->pc = 0x802CC0BCu;
    // 802CC0BC: lwz     r0, -25340(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25340);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC0C0:
    ctx->pc = 0x802CC0C0u;
    // 802CC0C0: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CC0C4:
    ctx->pc = 0x802CC0C4u;
    // 802CC0C4: bc    12, 2, 0x802CC0F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CC0F4;
        }
    }

label_802CC0C8:
    ctx->pc = 0x802CC0C8u;
    ctx->downcount -= 2;
    // 802CC0C8: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CC0CC:
    ctx->pc = 0x802CC0CCu;
    // 802CC0CC: bl      0x802C013C
    {
            ctx->lr = 0x802CC0D0u;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802CC0D0:
    ctx->pc = 0x802CC0D0u;
    ctx->downcount -= 2;
    // 802CC0D0: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CC0D4:
    ctx->pc = 0x802CC0D4u;
    // 802CC0D4: bl      0x802BFF34
    {
            ctx->lr = 0x802CC0D8u;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802CC0D8:
    ctx->pc = 0x802CC0D8u;
    ctx->downcount -= 4;
    // 802CC0D8: lwz     r12, -25340(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25340);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802CC0DC:
    ctx->pc = 0x802CC0DCu;
    // 802CC0DC: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_802CC0E0:
    ctx->pc = 0x802CC0E0u;
    // 802CC0E0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x802CC0E4u;
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC0E4:
    ctx->pc = 0x802CC0E4u;
    ctx->downcount -= 2;
    // 802CC0E4: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CC0E8:
    ctx->pc = 0x802CC0E8u;
    // 802CC0E8: bl      0x802C013C
    {
            ctx->lr = 0x802CC0ECu;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802CC0EC:
    ctx->pc = 0x802CC0ECu;
    ctx->downcount -= 2;
    // 802CC0EC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CC0F0:
    ctx->pc = 0x802CC0F0u;
    // 802CC0F0: bl      0x802BFF34
    {
            ctx->lr = 0x802CC0F4u;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802CC0F4:
    ctx->pc = 0x802CC0F4u;
    ctx->downcount -= 6;
    // 802CC0F4: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC0F8:
    ctx->pc = 0x802CC0F8u;
    // 802CC0F8: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CC0FC:
    ctx->pc = 0x802CC0FCu;
    // 802CC0FC: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_802CC100:
    ctx->pc = 0x802CC100u;
    // 802CC100: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC104:
    ctx->pc = 0x802CC104u;
    // 802CC104: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC108:
    ctx->pc = 0x802CC108u;
    ctx->downcount -= 12;
    // 802CC108: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC10C:
    ctx->pc = 0x802CC10Cu;
    // 802CC10C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC110:
    ctx->pc = 0x802CC110u;
    // 802CC110: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC114:
    ctx->pc = 0x802CC114u;
    // 802CC114: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CC118:
    ctx->pc = 0x802CC118u;
    // 802CC118: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_802CC11C:
    ctx->pc = 0x802CC11Cu;
    // 802CC11C: lwz     r5, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CC120:
    ctx->pc = 0x802CC120u;
    // 802CC120: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC124:
    ctx->pc = 0x802CC124u;
    // 802CC124: lhz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CC128:
    ctx->pc = 0x802CC128u;
    // 802CC128: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC12C:
    ctx->pc = 0x802CC12Cu;
    // 802CC12C: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC130:
    ctx->pc = 0x802CC130u;
    // 802CC130: rlwinm. r0, r0, 29, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 29u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CC134:
    ctx->pc = 0x802CC134u;
    // 802CC134: bc    12, 2, 0x802CC16C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CC16C;
        }
    }

label_802CC138:
    ctx->pc = 0x802CC138u;
    ctx->downcount -= 3;
    // 802CC138: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC13C:
    ctx->pc = 0x802CC13Cu;
    // 802CC13C: rlwinm. r0, r0, 31, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CC140:
    ctx->pc = 0x802CC140u;
    // 802CC140: bc    12, 2, 0x802CC16C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CC16C;
        }
    }

label_802CC144:
    ctx->pc = 0x802CC144u;
    ctx->downcount -= 2;
    // 802CC144: lwz     r3, -25352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25352);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC148:
    ctx->pc = 0x802CC148u;
    // 802CC148: bl      0x802C81F4
    {
            ctx->lr = 0x802CC14Cu;
            ctx->pc = 0x802C81F4u;
            return;
    }

label_802CC14C:
    ctx->pc = 0x802CC14Cu;
    ctx->downcount -= 5;
    // 802CC14C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CC150:
    ctx->pc = 0x802CC150u;
    // 802CC150: stw     r0, -25344(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25344);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC154:
    ctx->pc = 0x802CC154u;
    // 802CC154: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC158:
    ctx->pc = 0x802CC158u;
    // 802CC158: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CC15C:
    ctx->pc = 0x802CC15Cu;
    // 802CC15C: bl      0x802CCB24
    {
            ctx->lr = 0x802CC160u;
            goto label_802CCB24;
    }

label_802CC160:
    ctx->pc = 0x802CC160u;
    ctx->downcount -= 3;
    // 802CC160: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC164:
    ctx->pc = 0x802CC164u;
    // 802CC164: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CC168:
    ctx->pc = 0x802CC168u;
    // 802CC168: bl      0x802CCAE8
    {
            ctx->lr = 0x802CC16Cu;
            goto label_802CCAE8;
    }

label_802CC16C:
    ctx->pc = 0x802CC16Cu;
    ctx->downcount -= 4;
    // 802CC16C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC170:
    ctx->pc = 0x802CC170u;
    // 802CC170: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC174:
    ctx->pc = 0x802CC174u;
    // 802CC174: rlwinm. r0, r0, 30, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CC178:
    ctx->pc = 0x802CC178u;
    // 802CC178: bc    12, 2, 0x802CC1BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CC1BC;
        }
    }

label_802CC17C:
    ctx->pc = 0x802CC17Cu;
    ctx->downcount -= 3;
    // 802CC17C: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC180:
    ctx->pc = 0x802CC180u;
    // 802CC180: rlwinm. r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CC184:
    ctx->pc = 0x802CC184u;
    // 802CC184: bc    12, 2, 0x802CC1BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CC1BC;
        }
    }

label_802CC188:
    ctx->pc = 0x802CC188u;
    ctx->downcount -= 6;
    // 802CC188: lwz     r5, -25336(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25336);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CC18C:
    ctx->pc = 0x802CC18Cu;
    // 802CC18C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CC190:
    ctx->pc = 0x802CC190u;
    // 802CC190: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CC194:
    ctx->pc = 0x802CC194u;
    // 802CC194: addi    r0, r5, 1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(1);

label_802CC198:
    ctx->pc = 0x802CC198u;
    // 802CC198: stw     r0, -25336(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25336);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC19C:
    ctx->pc = 0x802CC19Cu;
    // 802CC19C: bl      0x802CCAE8
    {
            ctx->lr = 0x802CC1A0u;
            goto label_802CCAE8;
    }

label_802CC1A0:
    ctx->pc = 0x802CC1A0u;
    ctx->downcount -= 3;
    // 802CC1A0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC1A4:
    ctx->pc = 0x802CC1A4u;
    // 802CC1A4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CC1A8:
    ctx->pc = 0x802CC1A8u;
    // 802CC1A8: bl      0x802CCB24
    {
            ctx->lr = 0x802CC1ACu;
            goto label_802CCB24;
    }

label_802CC1AC:
    ctx->pc = 0x802CC1ACu;
    ctx->downcount -= 4;
    // 802CC1AC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802CC1B0:
    ctx->pc = 0x802CC1B0u;
    // 802CC1B0: lwz     r3, -25352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25352);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC1B4:
    ctx->pc = 0x802CC1B4u;
    // 802CC1B4: stw     r0, -25344(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25344);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC1B8:
    ctx->pc = 0x802CC1B8u;
    // 802CC1B8: bl      0x802C847C
    {
            ctx->lr = 0x802CC1BCu;
            ctx->pc = 0x802C847Cu;
            return;
    }

label_802CC1BC:
    ctx->pc = 0x802CC1BCu;
    ctx->downcount -= 5;
    // 802CC1BC: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC1C0:
    ctx->pc = 0x802CC1C0u;
    // 802CC1C0: lwz     r4, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CC1C4:
    ctx->pc = 0x802CC1C4u;
    // 802CC1C4: addi    r5, r3, 8
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(8);

label_802CC1C8:
    ctx->pc = 0x802CC1C8u;
    // 802CC1C8: rlwinm. r0, r4, 27, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 27u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CC1CC:
    ctx->pc = 0x802CC1CCu;
    // 802CC1CC: bc    12, 2, 0x802CC228
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CC228;
        }
    }

label_802CC1D0:
    ctx->pc = 0x802CC1D0u;
    ctx->downcount -= 3;
    // 802CC1D0: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC1D4:
    ctx->pc = 0x802CC1D4u;
    // 802CC1D4: rlwinm. r0, r0, 28, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CC1D8:
    ctx->pc = 0x802CC1D8u;
    // 802CC1D8: bc    12, 2, 0x802CC228
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CC228;
        }
    }

label_802CC1DC:
    ctx->pc = 0x802CC1DCu;
    ctx->downcount -= 8;
    // 802CC1DC: rlwinm r0, r4, 0, 27, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFDFu;
    }

label_802CC1E0:
    ctx->pc = 0x802CC1E0u;
    // 802CC1E0: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC1E4:
    ctx->pc = 0x802CC1E4u;
    // 802CC1E4: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC1E8:
    ctx->pc = 0x802CC1E8u;
    // 802CC1E8: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC1EC:
    ctx->pc = 0x802CC1ECu;
    // 802CC1EC: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC1F0:
    ctx->pc = 0x802CC1F0u;
    // 802CC1F0: lwz     r0, -25340(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25340);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC1F4:
    ctx->pc = 0x802CC1F4u;
    // 802CC1F4: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CC1F8:
    ctx->pc = 0x802CC1F8u;
    // 802CC1F8: bc    12, 2, 0x802CC228
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CC228;
        }
    }

label_802CC1FC:
    ctx->pc = 0x802CC1FCu;
    ctx->downcount -= 2;
    // 802CC1FC: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CC200:
    ctx->pc = 0x802CC200u;
    // 802CC200: bl      0x802C013C
    {
            ctx->lr = 0x802CC204u;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802CC204:
    ctx->pc = 0x802CC204u;
    ctx->downcount -= 2;
    // 802CC204: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CC208:
    ctx->pc = 0x802CC208u;
    // 802CC208: bl      0x802BFF34
    {
            ctx->lr = 0x802CC20Cu;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802CC20C:
    ctx->pc = 0x802CC20Cu;
    ctx->downcount -= 4;
    // 802CC20C: lwz     r12, -25340(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25340);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802CC210:
    ctx->pc = 0x802CC210u;
    // 802CC210: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_802CC214:
    ctx->pc = 0x802CC214u;
    // 802CC214: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x802CC218u;
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC218:
    ctx->pc = 0x802CC218u;
    ctx->downcount -= 2;
    // 802CC218: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CC21C:
    ctx->pc = 0x802CC21Cu;
    // 802CC21C: bl      0x802C013C
    {
            ctx->lr = 0x802CC220u;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802CC220:
    ctx->pc = 0x802CC220u;
    ctx->downcount -= 2;
    // 802CC220: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CC224:
    ctx->pc = 0x802CC224u;
    // 802CC224: bl      0x802BFF34
    {
            ctx->lr = 0x802CC228u;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802CC228:
    ctx->pc = 0x802CC228u;
    ctx->downcount -= 6;
    // 802CC228: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC22C:
    ctx->pc = 0x802CC22Cu;
    // 802CC22C: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CC230:
    ctx->pc = 0x802CC230u;
    // 802CC230: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_802CC234:
    ctx->pc = 0x802CC234u;
    // 802CC234: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC238:
    ctx->pc = 0x802CC238u;
    // 802CC238: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC23C:
    ctx->pc = 0x802CC23Cu;
    ctx->downcount -= 17;
    // 802CC23C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC240:
    ctx->pc = 0x802CC240u;
    // 802CC240: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC244:
    ctx->pc = 0x802CC244u;
    // 802CC244: addi    r0, r5, -4
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-4);

label_802CC248:
    ctx->pc = 0x802CC248u;
    // 802CC248: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC24C:
    ctx->pc = 0x802CC24Cu;
    // 802CC24C: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CC250:
    ctx->pc = 0x802CC250u;
    // 802CC250: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_802CC254:
    ctx->pc = 0x802CC254u;
    // 802CC254: add   r0, r31, r0
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CC258:
    ctx->pc = 0x802CC258u;
    // 802CC258: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC25C:
    ctx->pc = 0x802CC25Cu;
    // 802CC25C: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_802CC260:
    ctx->pc = 0x802CC260u;
    // 802CC260: addi    r4, r5, -16384
    ctx->gpr[4] = ctx->gpr[5] + (u32)(s32)(-16384);

label_802CC264:
    ctx->pc = 0x802CC264u;
    // 802CC264: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CC268:
    ctx->pc = 0x802CC268u;
    // 802CC268: stw     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC26C:
    ctx->pc = 0x802CC26Cu;
    // 802CC26C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CC270:
    ctx->pc = 0x802CC270u;
    // 802CC270: stw     r5, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CC274:
    ctx->pc = 0x802CC274u;
    // 802CC274: rlwinm r5, r5, 31, 1, 26
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 31u) & 0x7FFFFFE0u;
    }

label_802CC278:
    ctx->pc = 0x802CC278u;
    // 802CC278: stw     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC27C:
    ctx->pc = 0x802CC27Cu;
    // 802CC27C: bl      0x802CC318
    {
            ctx->lr = 0x802CC280u;
            goto label_802CC318;
    }

label_802CC280:
    ctx->pc = 0x802CC280u;
    ctx->downcount -= 4;
    // 802CC280: addi    r3, r30, 0
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(0);

label_802CC284:
    ctx->pc = 0x802CC284u;
    // 802CC284: addi    r4, r31, 0
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(0);

label_802CC288:
    ctx->pc = 0x802CC288u;
    // 802CC288: addi    r5, r31, 0
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(0);

label_802CC28C:
    ctx->pc = 0x802CC28Cu;
    // 802CC28C: bl      0x802CC2A8
    {
            ctx->lr = 0x802CC290u;
            goto label_802CC2A8;
    }

label_802CC290:
    ctx->pc = 0x802CC290u;
    ctx->downcount -= 7;
    // 802CC290: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC294:
    ctx->pc = 0x802CC294u;
    // 802CC294: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CC298:
    ctx->pc = 0x802CC298u;
    // 802CC298: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CC29C:
    ctx->pc = 0x802CC29Cu;
    // 802CC29C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802CC2A0:
    ctx->pc = 0x802CC2A0u;
    // 802CC2A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC2A4:
    ctx->pc = 0x802CC2A4u;
    // 802CC2A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC2A8:
    ctx->pc = 0x802CC2A8u;
    ctx->downcount -= 10;
    // 802CC2A8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC2AC:
    ctx->pc = 0x802CC2ACu;
    // 802CC2AC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC2B0:
    ctx->pc = 0x802CC2B0u;
    // 802CC2B0: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC2B4:
    ctx->pc = 0x802CC2B4u;
    // 802CC2B4: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CC2B8:
    ctx->pc = 0x802CC2B8u;
    // 802CC2B8: addi    r31, r5, 0
    ctx->gpr[31] = ctx->gpr[5] + (u32)(s32)(0);

label_802CC2BC:
    ctx->pc = 0x802CC2BCu;
    // 802CC2BC: stw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC2C0:
    ctx->pc = 0x802CC2C0u;
    // 802CC2C0: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_802CC2C4:
    ctx->pc = 0x802CC2C4u;
    // 802CC2C4: stw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802CC2C8:
    ctx->pc = 0x802CC2C8u;
    // 802CC2C8: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802CC2CC:
    ctx->pc = 0x802CC2CCu;
    // 802CC2CC: bl      0x802C30E8
    {
            ctx->lr = 0x802CC2D0u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CC2D0:
    ctx->pc = 0x802CC2D0u;
    ctx->downcount -= 7;
    // 802CC2D0: stw     r30, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC2D4:
    ctx->pc = 0x802CC2D4u;
    // 802CC2D4: subf   r0, r30, r31
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_802CC2D8:
    ctx->pc = 0x802CC2D8u;
    // 802CC2D8: stw     r31, 24(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CC2DC:
    ctx->pc = 0x802CC2DCu;
    // 802CC2DC: stw     r0, 28(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC2E0:
    ctx->pc = 0x802CC2E0u;
    // 802CC2E0: lwz     r4, 28(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CC2E4:
    ctx->pc = 0x802CC2E4u;
    // 802CC2E4: cmpwi   r4, 0
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

label_802CC2E8:
    ctx->pc = 0x802CC2E8u;
    // 802CC2E8: bc    4, 0, 0x802CC2F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CC2F8;
        }
    }

label_802CC2EC:
    ctx->pc = 0x802CC2ECu;
    ctx->downcount -= 3;
    // 802CC2EC: lwz     r0, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC2F0:
    ctx->pc = 0x802CC2F0u;
    // 802CC2F0: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CC2F4:
    ctx->pc = 0x802CC2F4u;
    // 802CC2F4: stw     r0, 28(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC2F8:
    ctx->pc = 0x802CC2F8u;
    ctx->downcount -= 1;
    // 802CC2F8: bl      0x802C3110
    {
            ctx->lr = 0x802CC2FCu;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CC2FC:
    ctx->pc = 0x802CC2FCu;
    ctx->downcount -= 8;
    // 802CC2FC: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC300:
    ctx->pc = 0x802CC300u;
    // 802CC300: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CC304:
    ctx->pc = 0x802CC304u;
    // 802CC304: lwz     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CC308:
    ctx->pc = 0x802CC308u;
    // 802CC308: lwz     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802CC30C:
    ctx->pc = 0x802CC30Cu;
    // 802CC30C: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_802CC310:
    ctx->pc = 0x802CC310u;
    // 802CC310: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC314:
    ctx->pc = 0x802CC314u;
    // 802CC314: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC318:
    ctx->pc = 0x802CC318u;
    ctx->downcount -= 3;
    // 802CC318: stw     r4, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CC31C:
    ctx->pc = 0x802CC31Cu;
    // 802CC31C: stw     r5, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CC320:
    ctx->pc = 0x802CC320u;
    // 802CC320: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC324:
    ctx->pc = 0x802CC324u;
    ctx->downcount -= 7;
    // 802CC324: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC328:
    ctx->pc = 0x802CC328u;
    // 802CC328: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC32C:
    ctx->pc = 0x802CC32Cu;
    // 802CC32C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC330:
    ctx->pc = 0x802CC330u;
    // 802CC330: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CC334:
    ctx->pc = 0x802CC334u;
    // 802CC334: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC338:
    ctx->pc = 0x802CC338u;
    // 802CC338: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CC33C:
    ctx->pc = 0x802CC33Cu;
    // 802CC33C: bl      0x802C30E8
    {
            ctx->lr = 0x802CC340u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CC340:
    ctx->pc = 0x802CC340u;
    ctx->downcount -= 5;
    // 802CC340: lwz     r0, -25356(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25356);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC344:
    ctx->pc = 0x802CC344u;
    // 802CC344: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_802CC348:
    ctx->pc = 0x802CC348u;
    // 802CC348: stw     r30, -25360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25360);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC34C:
    ctx->pc = 0x802CC34Cu;
    // 802CC34C: cmplw   r30, r0
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

label_802CC350:
    ctx->pc = 0x802CC350u;
    // 802CC350: bc    4, 2, 0x802CC3B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CC3B4;
        }
    }

label_802CC354:
    ctx->pc = 0x802CC354u;
    ctx->downcount -= 18;
    // 802CC354: lwz     r5, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CC358:
    ctx->pc = 0x802CC358u;
    // 802CC358: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802CC35C:
    ctx->pc = 0x802CC35Cu;
    // 802CC35C: lwz     r4, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CC360:
    ctx->pc = 0x802CC360u;
    // 802CC360: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC364:
    ctx->pc = 0x802CC364u;
    // 802CC364: rlwinm r5, r5, 0, 2, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x3FFFFFFFu;
    }

label_802CC368:
    ctx->pc = 0x802CC368u;
    // 802CC368: stw     r5, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CC36C:
    ctx->pc = 0x802CC36Cu;
    // 802CC36C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CC370:
    ctx->pc = 0x802CC370u;
    // 802CC370: lwz     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CC374:
    ctx->pc = 0x802CC374u;
    // 802CC374: lwz     r5, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CC378:
    ctx->pc = 0x802CC378u;
    // 802CC378: rlwinm r6, r6, 0, 2, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x3FFFFFFFu;
    }

label_802CC37C:
    ctx->pc = 0x802CC37Cu;
    // 802CC37C: stw     r6, 16(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CC380:
    ctx->pc = 0x802CC380u;
    // 802CC380: lwz     r6, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CC384:
    ctx->pc = 0x802CC384u;
    // 802CC384: lwz     r5, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CC388:
    ctx->pc = 0x802CC388u;
    // 802CC388: rlwinm r6, r6, 0, 2, 26
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x3FFFFFE0u;
    }

label_802CC38C:
    ctx->pc = 0x802CC38Cu;
    // 802CC38C: rlwinm r6, r6, 0, 6, 4
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFBFFFFFFu;
    }

label_802CC390:
    ctx->pc = 0x802CC390u;
    // 802CC390: stw     r6, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CC394:
    ctx->pc = 0x802CC394u;
    // 802CC394: stb     r0, -25348(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25348);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC398:
    ctx->pc = 0x802CC398u;
    // 802CC398: bl      0x802CCB24
    {
            ctx->lr = 0x802CC39Cu;
            goto label_802CCB24;
    }

label_802CC39C:
    ctx->pc = 0x802CC39Cu;
    ctx->downcount -= 3;
    // 802CC39C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC3A0:
    ctx->pc = 0x802CC3A0u;
    // 802CC3A0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CC3A4:
    ctx->pc = 0x802CC3A4u;
    // 802CC3A4: bl      0x802CCAE8
    {
            ctx->lr = 0x802CC3A8u;
            goto label_802CCAE8;
    }

label_802CC3A8:
    ctx->pc = 0x802CC3A8u;
    ctx->downcount -= 2;
    // 802CC3A8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC3AC:
    ctx->pc = 0x802CC3ACu;
    // 802CC3AC: bl      0x802CCAAC
    {
            ctx->lr = 0x802CC3B0u;
            goto label_802CCAAC;
    }

label_802CC3B0:
    ctx->pc = 0x802CC3B0u;
    ctx->downcount -= 1;
    // 802CC3B0: b       0x802CC410
    {
            goto label_802CC410;
    }

label_802CC3B4:
    ctx->pc = 0x802CC3B4u;
    ctx->downcount -= 3;
    // 802CC3B4: lbz     r0, -25348(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25348);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CC3B8:
    ctx->pc = 0x802CC3B8u;
    // 802CC3B8: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CC3BC:
    ctx->pc = 0x802CC3BCu;
    // 802CC3BC: bc    12, 2, 0x802CC3D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CC3D0;
        }
    }

label_802CC3C0:
    ctx->pc = 0x802CC3C0u;
    ctx->downcount -= 2;
    // 802CC3C0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CC3C4:
    ctx->pc = 0x802CC3C4u;
    // 802CC3C4: bl      0x802CCAAC
    {
            ctx->lr = 0x802CC3C8u;
            goto label_802CCAAC;
    }

label_802CC3C8:
    ctx->pc = 0x802CC3C8u;
    ctx->downcount -= 2;
    // 802CC3C8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CC3CC:
    ctx->pc = 0x802CC3CCu;
    // 802CC3CC: stb     r0, -25348(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25348);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC3D0:
    ctx->pc = 0x802CC3D0u;
    ctx->downcount -= 3;
    // 802CC3D0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CC3D4:
    ctx->pc = 0x802CC3D4u;
    // 802CC3D4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CC3D8:
    ctx->pc = 0x802CC3D8u;
    // 802CC3D8: bl      0x802CCAE8
    {
            ctx->lr = 0x802CC3DCu;
            goto label_802CCAE8;
    }

label_802CC3DC:
    ctx->pc = 0x802CC3DCu;
    ctx->downcount -= 13;
    // 802CC3DC: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC3E0:
    ctx->pc = 0x802CC3E0u;
    // 802CC3E0: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC3E4:
    ctx->pc = 0x802CC3E4u;
    // 802CC3E4: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_802CC3E8:
    ctx->pc = 0x802CC3E8u;
    // 802CC3E8: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC3EC:
    ctx->pc = 0x802CC3ECu;
    // 802CC3EC: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC3F0:
    ctx->pc = 0x802CC3F0u;
    // 802CC3F0: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC3F4:
    ctx->pc = 0x802CC3F4u;
    // 802CC3F4: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_802CC3F8:
    ctx->pc = 0x802CC3F8u;
    // 802CC3F8: stw     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC3FC:
    ctx->pc = 0x802CC3FCu;
    // 802CC3FC: lwz     r0, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC400:
    ctx->pc = 0x802CC400u;
    // 802CC400: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC404:
    ctx->pc = 0x802CC404u;
    // 802CC404: rlwinm r0, r0, 0, 2, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFE0u;
    }

label_802CC408:
    ctx->pc = 0x802CC408u;
    // 802CC408: rlwinm r0, r0, 0, 6, 4
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFBFFFFFFu;
    }

label_802CC40C:
    ctx->pc = 0x802CC40Cu;
    // 802CC40C: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC410:
    ctx->pc = 0x802CC410u;
    ctx->downcount -= 1;
    // 802CC410: bl      0x802D641C
    {
            ctx->lr = 0x802CC414u;
            ctx->pc = 0x802D641Cu;
            return;
    }

label_802CC414:
    ctx->pc = 0x802CC414u;
    ctx->downcount -= 2;
    // 802CC414: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CC418:
    ctx->pc = 0x802CC418u;
    // 802CC418: bl      0x802C3110
    {
            ctx->lr = 0x802CC41Cu;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CC41C:
    ctx->pc = 0x802CC41Cu;
    ctx->downcount -= 7;
    // 802CC41C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC420:
    ctx->pc = 0x802CC420u;
    // 802CC420: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CC424:
    ctx->pc = 0x802CC424u;
    // 802CC424: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CC428:
    ctx->pc = 0x802CC428u;
    // 802CC428: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CC42C:
    ctx->pc = 0x802CC42Cu;
    // 802CC42C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC430:
    ctx->pc = 0x802CC430u;
    // 802CC430: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC434:
    ctx->pc = 0x802CC434u;
    ctx->downcount -= 7;
    // 802CC434: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC438:
    ctx->pc = 0x802CC438u;
    // 802CC438: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC43C:
    ctx->pc = 0x802CC43Cu;
    // 802CC43C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC440:
    ctx->pc = 0x802CC440u;
    // 802CC440: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CC444:
    ctx->pc = 0x802CC444u;
    // 802CC444: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC448:
    ctx->pc = 0x802CC448u;
    // 802CC448: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CC44C:
    ctx->pc = 0x802CC44Cu;
    // 802CC44C: bl      0x802C30E8
    {
            ctx->lr = 0x802CC450u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CC450:
    ctx->pc = 0x802CC450u;
    ctx->downcount -= 2;
    // 802CC450: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CC454:
    ctx->pc = 0x802CC454u;
    // 802CC454: bl      0x802CCA8C
    {
            ctx->lr = 0x802CC458u;
            goto label_802CCA8C;
    }

label_802CC458:
    ctx->pc = 0x802CC458u;
    ctx->downcount -= 3;
    // 802CC458: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CC45C:
    ctx->pc = 0x802CC45Cu;
    // 802CC45C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CC460:
    ctx->pc = 0x802CC460u;
    // 802CC460: bl      0x802CCAE8
    {
            ctx->lr = 0x802CC464u;
            goto label_802CCAE8;
    }

label_802CC464:
    ctx->pc = 0x802CC464u;
    ctx->downcount -= 51;
    // 802CC464: stw     r30, -25356(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25356);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC468:
    ctx->pc = 0x802CC468u;
    // 802CC468: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC46C:
    ctx->pc = 0x802CC46Cu;
    // 802CC46C: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC470:
    ctx->pc = 0x802CC470u;
    // 802CC470: sth     r0, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC474:
    ctx->pc = 0x802CC474u;
    // 802CC474: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC478:
    ctx->pc = 0x802CC478u;
    // 802CC478: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC47C:
    ctx->pc = 0x802CC47Cu;
    // 802CC47C: sth     r0, 36(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC480:
    ctx->pc = 0x802CC480u;
    // 802CC480: lwz     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC484:
    ctx->pc = 0x802CC484u;
    // 802CC484: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC488:
    ctx->pc = 0x802CC488u;
    // 802CC488: sth     r0, 48(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC48C:
    ctx->pc = 0x802CC48Cu;
    // 802CC48C: lwz     r0, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC490:
    ctx->pc = 0x802CC490u;
    // 802CC490: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC494:
    ctx->pc = 0x802CC494u;
    // 802CC494: sth     r0, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC498:
    ctx->pc = 0x802CC498u;
    // 802CC498: lwz     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC49C:
    ctx->pc = 0x802CC49Cu;
    // 802CC49C: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC4A0:
    ctx->pc = 0x802CC4A0u;
    // 802CC4A0: sth     r0, 56(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(56);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC4A4:
    ctx->pc = 0x802CC4A4u;
    // 802CC4A4: lwz     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC4A8:
    ctx->pc = 0x802CC4A8u;
    // 802CC4A8: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC4AC:
    ctx->pc = 0x802CC4ACu;
    // 802CC4AC: sth     r0, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC4B0:
    ctx->pc = 0x802CC4B0u;
    // 802CC4B0: lwz     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC4B4:
    ctx->pc = 0x802CC4B4u;
    // 802CC4B4: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC4B8:
    ctx->pc = 0x802CC4B8u;
    // 802CC4B8: sth     r0, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC4BC:
    ctx->pc = 0x802CC4BCu;
    // 802CC4BC: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC4C0:
    ctx->pc = 0x802CC4C0u;
    // 802CC4C0: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC4C4:
    ctx->pc = 0x802CC4C4u;
    // 802CC4C4: rlwinm r0, r0, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00003FFFu;
    }

label_802CC4C8:
    ctx->pc = 0x802CC4C8u;
    // 802CC4C8: sth     r0, 34(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(34);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC4CC:
    ctx->pc = 0x802CC4CCu;
    // 802CC4CC: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC4D0:
    ctx->pc = 0x802CC4D0u;
    // 802CC4D0: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC4D4:
    ctx->pc = 0x802CC4D4u;
    // 802CC4D4: rlwinm r0, r0, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00003FFFu;
    }

label_802CC4D8:
    ctx->pc = 0x802CC4D8u;
    // 802CC4D8: sth     r0, 38(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(38);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC4DC:
    ctx->pc = 0x802CC4DCu;
    // 802CC4DC: lwz     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC4E0:
    ctx->pc = 0x802CC4E0u;
    // 802CC4E0: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC4E4:
    ctx->pc = 0x802CC4E4u;
    // 802CC4E4: srawi r0, r0, 16
    {
        u32 sh = 16u;
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

label_802CC4E8:
    ctx->pc = 0x802CC4E8u;
    // 802CC4E8: sth     r0, 50(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(50);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC4EC:
    ctx->pc = 0x802CC4ECu;
    // 802CC4EC: lwz     r0, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC4F0:
    ctx->pc = 0x802CC4F0u;
    // 802CC4F0: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC4F4:
    ctx->pc = 0x802CC4F4u;
    // 802CC4F4: rlwinm r0, r0, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00003FFFu;
    }

label_802CC4F8:
    ctx->pc = 0x802CC4F8u;
    // 802CC4F8: sth     r0, 54(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(54);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC4FC:
    ctx->pc = 0x802CC4FCu;
    // 802CC4FC: lwz     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC500:
    ctx->pc = 0x802CC500u;
    // 802CC500: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC504:
    ctx->pc = 0x802CC504u;
    // 802CC504: rlwinm r0, r0, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00003FFFu;
    }

label_802CC508:
    ctx->pc = 0x802CC508u;
    // 802CC508: sth     r0, 58(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(58);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC50C:
    ctx->pc = 0x802CC50Cu;
    // 802CC50C: lwz     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC510:
    ctx->pc = 0x802CC510u;
    // 802CC510: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC514:
    ctx->pc = 0x802CC514u;
    // 802CC514: rlwinm r0, r0, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x0000FFFFu;
    }

label_802CC518:
    ctx->pc = 0x802CC518u;
    // 802CC518: sth     r0, 42(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(42);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC51C:
    ctx->pc = 0x802CC51Cu;
    // 802CC51C: lwz     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC520:
    ctx->pc = 0x802CC520u;
    // 802CC520: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC524:
    ctx->pc = 0x802CC524u;
    // 802CC524: rlwinm r0, r0, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x0000FFFFu;
    }

label_802CC528:
    ctx->pc = 0x802CC528u;
    // 802CC528: sth     r0, 46(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(46);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC52C:
    ctx->pc = 0x802CC52Cu;
    // 802CC52C: bl      0x802D641C
    {
            ctx->lr = 0x802CC530u;
            ctx->pc = 0x802D641Cu;
            return;
    }

label_802CC530:
    ctx->pc = 0x802CC530u;
    ctx->downcount -= 4;
    // 802CC530: lwz     r3, -25360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25360);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC534:
    ctx->pc = 0x802CC534u;
    // 802CC534: lwz     r0, -25356(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25356);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC538:
    ctx->pc = 0x802CC538u;
    // 802CC538: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CC53C:
    ctx->pc = 0x802CC53Cu;
    // 802CC53C: bc    4, 2, 0x802CC560
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CC560;
        }
    }

label_802CC540:
    ctx->pc = 0x802CC540u;
    ctx->downcount -= 5;
    // 802CC540: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802CC544:
    ctx->pc = 0x802CC544u;
    // 802CC544: stb     r0, -25348(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25348);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC548:
    ctx->pc = 0x802CC548u;
    // 802CC548: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC54C:
    ctx->pc = 0x802CC54Cu;
    // 802CC54C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CC550:
    ctx->pc = 0x802CC550u;
    // 802CC550: bl      0x802CCAE8
    {
            ctx->lr = 0x802CC554u;
            goto label_802CCAE8;
    }

label_802CC554:
    ctx->pc = 0x802CC554u;
    ctx->downcount -= 2;
    // 802CC554: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC558:
    ctx->pc = 0x802CC558u;
    // 802CC558: bl      0x802CCAAC
    {
            ctx->lr = 0x802CC55Cu;
            goto label_802CCAAC;
    }

label_802CC55C:
    ctx->pc = 0x802CC55Cu;
    ctx->downcount -= 1;
    // 802CC55C: b       0x802CC57C
    {
            goto label_802CC57C;
    }

label_802CC560:
    ctx->pc = 0x802CC560u;
    ctx->downcount -= 5;
    // 802CC560: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CC564:
    ctx->pc = 0x802CC564u;
    // 802CC564: stb     r0, -25348(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25348);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC568:
    ctx->pc = 0x802CC568u;
    // 802CC568: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CC56C:
    ctx->pc = 0x802CC56Cu;
    // 802CC56C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CC570:
    ctx->pc = 0x802CC570u;
    // 802CC570: bl      0x802CCAE8
    {
            ctx->lr = 0x802CC574u;
            goto label_802CCAE8;
    }

label_802CC574:
    ctx->pc = 0x802CC574u;
    ctx->downcount -= 2;
    // 802CC574: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CC578:
    ctx->pc = 0x802CC578u;
    // 802CC578: bl      0x802CCAAC
    {
            ctx->lr = 0x802CC57Cu;
            goto label_802CCAAC;
    }

label_802CC57C:
    ctx->pc = 0x802CC57Cu;
    ctx->downcount -= 3;
    // 802CC57C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CC580:
    ctx->pc = 0x802CC580u;
    // 802CC580: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CC584:
    ctx->pc = 0x802CC584u;
    // 802CC584: bl      0x802CCB24
    {
            ctx->lr = 0x802CC588u;
            goto label_802CCB24;
    }

label_802CC588:
    ctx->pc = 0x802CC588u;
    ctx->downcount -= 1;
    // 802CC588: bl      0x802CCA68
    {
            ctx->lr = 0x802CC58Cu;
            goto label_802CCA68;
    }

label_802CC58C:
    ctx->pc = 0x802CC58Cu;
    ctx->downcount -= 2;
    // 802CC58C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CC590:
    ctx->pc = 0x802CC590u;
    // 802CC590: bl      0x802C3110
    {
            ctx->lr = 0x802CC594u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CC594:
    ctx->pc = 0x802CC594u;
    ctx->downcount -= 7;
    // 802CC594: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC598:
    ctx->pc = 0x802CC598u;
    // 802CC598: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CC59C:
    ctx->pc = 0x802CC59Cu;
    // 802CC59C: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CC5A0:
    ctx->pc = 0x802CC5A0u;
    // 802CC5A0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CC5A4:
    ctx->pc = 0x802CC5A4u;
    // 802CC5A4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC5A8:
    ctx->pc = 0x802CC5A8u;
    // 802CC5A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC5AC:
    ctx->pc = 0x802CC5ACu;
    ctx->downcount -= 4;
    // 802CC5AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC5B0:
    ctx->pc = 0x802CC5B0u;
    // 802CC5B0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC5B4:
    ctx->pc = 0x802CC5B4u;
    // 802CC5B4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC5B8:
    ctx->pc = 0x802CC5B8u;
    // 802CC5B8: bl      0x802CC5CC
    {
            ctx->lr = 0x802CC5BCu;
            goto label_802CC5CC;
    }

label_802CC5BC:
    ctx->pc = 0x802CC5BCu;
    ctx->downcount -= 5;
    // 802CC5BC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC5C0:
    ctx->pc = 0x802CC5C0u;
    // 802CC5C0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802CC5C4:
    ctx->pc = 0x802CC5C4u;
    // 802CC5C4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC5C8:
    ctx->pc = 0x802CC5C8u;
    // 802CC5C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC5CC:
    ctx->pc = 0x802CC5CCu;
    ctx->downcount -= 7;
    // 802CC5CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC5D0:
    ctx->pc = 0x802CC5D0u;
    // 802CC5D0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC5D4:
    ctx->pc = 0x802CC5D4u;
    // 802CC5D4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC5D8:
    ctx->pc = 0x802CC5D8u;
    // 802CC5D8: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CC5DC:
    ctx->pc = 0x802CC5DCu;
    // 802CC5DC: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC5E0:
    ctx->pc = 0x802CC5E0u;
    // 802CC5E0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CC5E4:
    ctx->pc = 0x802CC5E4u;
    // 802CC5E4: bl      0x802C30E8
    {
            ctx->lr = 0x802CC5E8u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CC5E8:
    ctx->pc = 0x802CC5E8u;
    ctx->downcount -= 2;
    // 802CC5E8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CC5EC:
    ctx->pc = 0x802CC5ECu;
    // 802CC5EC: bl      0x802CEA48
    {
            ctx->lr = 0x802CC5F0u;
            goto label_802CEA48;
    }

label_802CC5F0:
    ctx->pc = 0x802CC5F0u;
    ctx->downcount -= 16;
    // 802CC5F0: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC5F4:
    ctx->pc = 0x802CC5F4u;
    // 802CC5F4: lwz     r3, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC5F8:
    ctx->pc = 0x802CC5F8u;
    // 802CC5F8: addis   r0, r3, -32768
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-32768) << 16);

label_802CC5FC:
    ctx->pc = 0x802CC5FCu;
    // 802CC5FC: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC600:
    ctx->pc = 0x802CC600u;
    // 802CC600: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC604:
    ctx->pc = 0x802CC604u;
    // 802CC604: lwz     r3, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC608:
    ctx->pc = 0x802CC608u;
    // 802CC608: addis   r0, r3, -32768
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-32768) << 16);

label_802CC60C:
    ctx->pc = 0x802CC60Cu;
    // 802CC60C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC610:
    ctx->pc = 0x802CC610u;
    // 802CC610: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC614:
    ctx->pc = 0x802CC614u;
    // 802CC614: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC618:
    ctx->pc = 0x802CC618u;
    // 802CC618: rlwinm r3, r0, 0, 6, 4
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFBFFFFFFu;
    }

label_802CC61C:
    ctx->pc = 0x802CC61Cu;
    // 802CC61C: addis   r0, r3, -32768
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-32768) << 16);

label_802CC620:
    ctx->pc = 0x802CC620u;
    // 802CC620: stw     r0, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC624:
    ctx->pc = 0x802CC624u;
    // 802CC624: lbz     r0, -25348(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25348);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CC628:
    ctx->pc = 0x802CC628u;
    // 802CC628: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CC62C:
    ctx->pc = 0x802CC62Cu;
    // 802CC62C: bc    12, 2, 0x802CC660
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CC660;
        }
    }

label_802CC630:
    ctx->pc = 0x802CC630u;
    ctx->downcount -= 12;
    // 802CC630: lwz     r4, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CC634:
    ctx->pc = 0x802CC634u;
    // 802CC634: lhz     r3, 58(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(58);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CC638:
    ctx->pc = 0x802CC638u;
    // 802CC638: lhz     r4, 56(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(56);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CC63C:
    ctx->pc = 0x802CC63Cu;
    // 802CC63C: rlwimi r4, r3, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 16u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_802CC640:
    ctx->pc = 0x802CC640u;
    // 802CC640: addis   r0, r4, -32768
    ctx->gpr[0] = ctx->gpr[4] + ((u32)(s32)(-32768) << 16);

label_802CC644:
    ctx->pc = 0x802CC644u;
    // 802CC644: stw     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC648:
    ctx->pc = 0x802CC648u;
    // 802CC648: lwz     r4, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CC64C:
    ctx->pc = 0x802CC64Cu;
    // 802CC64C: lhz     r3, 50(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(50);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CC650:
    ctx->pc = 0x802CC650u;
    // 802CC650: lhz     r0, 48(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CC654:
    ctx->pc = 0x802CC654u;
    // 802CC654: rlwimi r0, r3, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 16u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_802CC658:
    ctx->pc = 0x802CC658u;
    // 802CC658: stw     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC65C:
    ctx->pc = 0x802CC65Cu;
    // 802CC65C: b       0x802CC688
    {
            goto label_802CC688;
    }

label_802CC660:
    ctx->pc = 0x802CC660u;
    ctx->downcount -= 7;
    // 802CC660: lwz     r3, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC664:
    ctx->pc = 0x802CC664u;
    // 802CC664: lwz     r0, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC668:
    ctx->pc = 0x802CC668u;
    // 802CC668: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_802CC66C:
    ctx->pc = 0x802CC66Cu;
    // 802CC66C: stw     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC670:
    ctx->pc = 0x802CC670u;
    // 802CC670: lwz     r3, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC674:
    ctx->pc = 0x802CC674u;
    // 802CC674: cmpwi   r3, 0
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

label_802CC678:
    ctx->pc = 0x802CC678u;
    // 802CC678: bc    4, 0, 0x802CC688
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CC688;
        }
    }

label_802CC67C:
    ctx->pc = 0x802CC67Cu;
    ctx->downcount -= 3;
    // 802CC67C: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC680:
    ctx->pc = 0x802CC680u;
    // 802CC680: add   r0, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CC684:
    ctx->pc = 0x802CC684u;
    // 802CC684: stw     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC688:
    ctx->pc = 0x802CC688u;
    ctx->downcount -= 2;
    // 802CC688: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CC68C:
    ctx->pc = 0x802CC68Cu;
    // 802CC68C: bl      0x802C3110
    {
            ctx->lr = 0x802CC690u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CC690:
    ctx->pc = 0x802CC690u;
    ctx->downcount -= 7;
    // 802CC690: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC694:
    ctx->pc = 0x802CC694u;
    // 802CC694: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CC698:
    ctx->pc = 0x802CC698u;
    // 802CC698: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CC69C:
    ctx->pc = 0x802CC69Cu;
    // 802CC69C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CC6A0:
    ctx->pc = 0x802CC6A0u;
    // 802CC6A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC6A4:
    ctx->pc = 0x802CC6A4u;
    // 802CC6A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC6A8:
    ctx->pc = 0x802CC6A8u;
    ctx->downcount -= 12;
    // 802CC6A8: lwz     r5, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CC6AC:
    ctx->pc = 0x802CC6ACu;
    // 802CC6AC: lhz     r4, 58(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(58);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CC6B0:
    ctx->pc = 0x802CC6B0u;
    // 802CC6B0: lhz     r5, 56(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(56);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_802CC6B4:
    ctx->pc = 0x802CC6B4u;
    // 802CC6B4: rlwimi r5, r4, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 16u);
        ctx->gpr[5] = (ctx->gpr[5] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_802CC6B8:
    ctx->pc = 0x802CC6B8u;
    // 802CC6B8: addis   r0, r5, -32768
    ctx->gpr[0] = ctx->gpr[5] + ((u32)(s32)(-32768) << 16);

label_802CC6BC:
    ctx->pc = 0x802CC6BCu;
    // 802CC6BC: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC6C0:
    ctx->pc = 0x802CC6C0u;
    // 802CC6C0: lwz     r5, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CC6C4:
    ctx->pc = 0x802CC6C4u;
    // 802CC6C4: lhz     r4, 50(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(50);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CC6C8:
    ctx->pc = 0x802CC6C8u;
    // 802CC6C8: lhz     r0, 48(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CC6CC:
    ctx->pc = 0x802CC6CCu;
    // 802CC6CC: rlwimi r0, r4, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 16u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_802CC6D0:
    ctx->pc = 0x802CC6D0u;
    // 802CC6D0: stw     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC6D4:
    ctx->pc = 0x802CC6D4u;
    // 802CC6D4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC6D8:
    ctx->pc = 0x802CC6D8u;
    ctx->downcount -= 20;
    // 802CC6D8: lwz     r9, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_802CC6DC:
    ctx->pc = 0x802CC6DCu;
    // 802CC6DC: lwz     r8, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_802CC6E0:
    ctx->pc = 0x802CC6E0u;
    // 802CC6E0: lhz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CC6E4:
    ctx->pc = 0x802CC6E4u;
    // 802CC6E4: stw     r0, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC6E8:
    ctx->pc = 0x802CC6E8u;
    // 802CC6E8: lwz     r0, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC6EC:
    ctx->pc = 0x802CC6ECu;
    // 802CC6EC: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_802CC6F0:
    ctx->pc = 0x802CC6F0u;
    // 802CC6F0: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC6F4:
    ctx->pc = 0x802CC6F4u;
    // 802CC6F4: lwz     r0, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC6F8:
    ctx->pc = 0x802CC6F8u;
    // 802CC6F8: rlwinm r0, r0, 31, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000001u;
    }

label_802CC6FC:
    ctx->pc = 0x802CC6FCu;
    // 802CC6FC: stb     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC700:
    ctx->pc = 0x802CC700u;
    // 802CC700: lwz     r0, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC704:
    ctx->pc = 0x802CC704u;
    // 802CC704: rlwinm r0, r0, 30, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x00000001u;
    }

label_802CC708:
    ctx->pc = 0x802CC708u;
    // 802CC708: stb     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC70C:
    ctx->pc = 0x802CC70Cu;
    // 802CC70C: lwz     r0, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC710:
    ctx->pc = 0x802CC710u;
    // 802CC710: rlwinm r0, r0, 29, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 29u) & 0x00000001u;
    }

label_802CC714:
    ctx->pc = 0x802CC714u;
    // 802CC714: stb     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC718:
    ctx->pc = 0x802CC718u;
    // 802CC718: lwz     r0, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC71C:
    ctx->pc = 0x802CC71Cu;
    // 802CC71C: rlwinm r0, r0, 28, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x00000001u;
    }

label_802CC720:
    ctx->pc = 0x802CC720u;
    // 802CC720: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC724:
    ctx->pc = 0x802CC724u;
    // 802CC724: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC728:
    ctx->pc = 0x802CC728u;
    ctx->downcount -= 29;
    // 802CC728: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC72C:
    ctx->pc = 0x802CC72Cu;
    // 802CC72C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC730:
    ctx->pc = 0x802CC730u;
    // 802CC730: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CC734:
    ctx->pc = 0x802CC734u;
    // 802CC734: stwu     r1, -80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-80);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC738:
    ctx->pc = 0x802CC738u;
    // 802CC738: stmw     r23, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 23; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802CC73C:
    ctx->pc = 0x802CC73Cu;
    // 802CC73C: addi    r26, r5, 0
    ctx->gpr[26] = ctx->gpr[5] + (u32)(s32)(0);

label_802CC740:
    ctx->pc = 0x802CC740u;
    // 802CC740: or   r25, r4, r4
    {
        ctx->gpr[25] = ctx->gpr[4] | ctx->gpr[4];
    }

label_802CC744:
    ctx->pc = 0x802CC744u;
    // 802CC744: addi    r27, r6, 0
    ctx->gpr[27] = ctx->gpr[6] + (u32)(s32)(0);

label_802CC748:
    ctx->pc = 0x802CC748u;
    // 802CC748: addi    r30, r9, 0
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(0);

label_802CC74C:
    ctx->pc = 0x802CC74Cu;
    // 802CC74C: addi    r28, r7, 0
    ctx->gpr[28] = ctx->gpr[7] + (u32)(s32)(0);

label_802CC750:
    ctx->pc = 0x802CC750u;
    // 802CC750: addi    r29, r8, 0
    ctx->gpr[29] = ctx->gpr[8] + (u32)(s32)(0);

label_802CC754:
    ctx->pc = 0x802CC754u;
    // 802CC754: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CC758:
    ctx->pc = 0x802CC758u;
    // 802CC758: stb     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC75C:
    ctx->pc = 0x802CC75Cu;
    // 802CC75C: stb     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC760:
    ctx->pc = 0x802CC760u;
    // 802CC760: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC764:
    ctx->pc = 0x802CC764u;
    // 802CC764: stb     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC768:
    ctx->pc = 0x802CC768u;
    // 802CC768: lwz     r0, -25356(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25356);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC76C:
    ctx->pc = 0x802CC76Cu;
    // 802CC76C: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CC770:
    ctx->pc = 0x802CC770u;
    // 802CC770: bc    4, 2, 0x802CC7A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CC7A0;
        }
    }

label_802CC774:
    ctx->pc = 0x802CC774u;
    ctx->downcount -= 11;
    // 802CC774: lwz     r4, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CC778:
    ctx->pc = 0x802CC778u;
    // 802CC778: lhz     r3, 58(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(58);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CC77C:
    ctx->pc = 0x802CC77Cu;
    // 802CC77C: lhz     r4, 56(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(56);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CC780:
    ctx->pc = 0x802CC780u;
    // 802CC780: rlwimi r4, r3, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 16u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_802CC784:
    ctx->pc = 0x802CC784u;
    // 802CC784: addis   r0, r4, -32768
    ctx->gpr[0] = ctx->gpr[4] + ((u32)(s32)(-32768) << 16);

label_802CC788:
    ctx->pc = 0x802CC788u;
    // 802CC788: stw     r0, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC78C:
    ctx->pc = 0x802CC78Cu;
    // 802CC78C: lwz     r4, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CC790:
    ctx->pc = 0x802CC790u;
    // 802CC790: lhz     r3, 50(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(50);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CC794:
    ctx->pc = 0x802CC794u;
    // 802CC794: lhz     r0, 48(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CC798:
    ctx->pc = 0x802CC798u;
    // 802CC798: rlwimi r0, r3, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 16u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_802CC79C:
    ctx->pc = 0x802CC79Cu;
    // 802CC79C: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC7A0:
    ctx->pc = 0x802CC7A0u;
    ctx->downcount -= 3;
    // 802CC7A0: lwz     r0, -25360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25360);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC7A4:
    ctx->pc = 0x802CC7A4u;
    // 802CC7A4: cmplw   r31, r0
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

label_802CC7A8:
    ctx->pc = 0x802CC7A8u;
    // 802CC7A8: bc    4, 2, 0x802CC7C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CC7C4;
        }
    }

label_802CC7AC:
    ctx->pc = 0x802CC7ACu;
    ctx->downcount -= 2;
    // 802CC7AC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CC7B0:
    ctx->pc = 0x802CC7B0u;
    // 802CC7B0: bl      0x802CC5CC
    {
            ctx->lr = 0x802CC7B4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CC5CCu;
                return;
            }
            goto label_802CC5CC;
    }

label_802CC7B4:
    ctx->pc = 0x802CC7B4u;
    ctx->downcount -= 4;
    // 802CC7B4: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC7B8:
    ctx->pc = 0x802CC7B8u;
    // 802CC7B8: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC7BC:
    ctx->pc = 0x802CC7BCu;
    // 802CC7BC: rlwinm r0, r0, 6, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 6u) & 0x00000001u;
    }

label_802CC7C0:
    ctx->pc = 0x802CC7C0u;
    // 802CC7C0: stb     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC7C4:
    ctx->pc = 0x802CC7C4u;
    ctx->downcount -= 40;
    // 802CC7C4: lwz     r3, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC7C8:
    ctx->pc = 0x802CC7C8u;
    // 802CC7C8: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC7CC:
    ctx->pc = 0x802CC7CCu;
    // 802CC7CC: subfc   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CC7D0:
    ctx->pc = 0x802CC7D0u;
    // 802CC7D0: subfe   r23, r23, r23
    {
        u32 a = ~ctx->gpr[23];
        u32 b = ctx->gpr[23];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[23] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CC7D4:
    ctx->pc = 0x802CC7D4u;
    // 802CC7D4: neg  r0, r23
    {
        u32 a = ctx->gpr[23];
        ctx->gpr[0] = (~a) + 1u;
    }

label_802CC7D8:
    ctx->pc = 0x802CC7D8u;
    // 802CC7D8: stb     r0, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC7DC:
    ctx->pc = 0x802CC7DCu;
    // 802CC7DC: lwz     r3, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC7E0:
    ctx->pc = 0x802CC7E0u;
    // 802CC7E0: lwz     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC7E4:
    ctx->pc = 0x802CC7E4u;
    // 802CC7E4: subfc   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CC7E8:
    ctx->pc = 0x802CC7E8u;
    // 802CC7E8: subfe   r24, r24, r24
    {
        u32 a = ~ctx->gpr[24];
        u32 b = ctx->gpr[24];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[24] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CC7EC:
    ctx->pc = 0x802CC7ECu;
    // 802CC7EC: neg  r0, r24
    {
        u32 a = ctx->gpr[24];
        ctx->gpr[0] = (~a) + 1u;
    }

label_802CC7F0:
    ctx->pc = 0x802CC7F0u;
    // 802CC7F0: stb     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC7F4:
    ctx->pc = 0x802CC7F4u;
    // 802CC7F4: lwz     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC7F8:
    ctx->pc = 0x802CC7F8u;
    // 802CC7F8: stw     r0, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC7FC:
    ctx->pc = 0x802CC7FCu;
    // 802CC7FC: lwz     r0, -25360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25360);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC800:
    ctx->pc = 0x802CC800u;
    // 802CC800: subf   r0, r0, r31
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_802CC804:
    ctx->pc = 0x802CC804u;
    // 802CC804: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802CC808:
    ctx->pc = 0x802CC808u;
    // 802CC808: rlwinm r0, r0, 27, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x000000FFu;
    }

label_802CC80C:
    ctx->pc = 0x802CC80Cu;
    // 802CC80C: stb     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC810:
    ctx->pc = 0x802CC810u;
    // 802CC810: lwz     r0, -25356(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25356);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC814:
    ctx->pc = 0x802CC814u;
    // 802CC814: subf   r0, r0, r31
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_802CC818:
    ctx->pc = 0x802CC818u;
    // 802CC818: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802CC81C:
    ctx->pc = 0x802CC81Cu;
    // 802CC81C: rlwinm r0, r0, 27, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x000000FFu;
    }

label_802CC820:
    ctx->pc = 0x802CC820u;
    // 802CC820: stb     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CC824:
    ctx->pc = 0x802CC824u;
    // 802CC824: lmw     r23, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 23; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802CC828:
    ctx->pc = 0x802CC828u;
    // 802CC828: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC82C:
    ctx->pc = 0x802CC82Cu;
    // 802CC82C: addi    r1, r1, 80
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(80);

label_802CC830:
    ctx->pc = 0x802CC830u;
    // 802CC830: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC834:
    ctx->pc = 0x802CC834u;
    // 802CC834: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC838:
    ctx->pc = 0x802CC838u;
    ctx->downcount -= 3;
    // 802CC838: lwz     r0, -25360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25360);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC83C:
    ctx->pc = 0x802CC83Cu;
    // 802CC83C: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CC840:
    ctx->pc = 0x802CC840u;
    // 802CC840: bc    4, 2, 0x802CC858
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CC858;
        }
    }

label_802CC844:
    ctx->pc = 0x802CC844u;
    ctx->downcount -= 5;
    // 802CC844: lwz     r6, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CC848:
    ctx->pc = 0x802CC848u;
    // 802CC848: lwz     r0, 20(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC84C:
    ctx->pc = 0x802CC84Cu;
    // 802CC84C: rlwinm r6, r0, 0, 6, 4
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFBFFFFFFu;
    }

label_802CC850:
    ctx->pc = 0x802CC850u;
    // 802CC850: addis   r0, r6, -32768
    ctx->gpr[0] = ctx->gpr[6] + ((u32)(s32)(-32768) << 16);

label_802CC854:
    ctx->pc = 0x802CC854u;
    // 802CC854: stw     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC858:
    ctx->pc = 0x802CC858u;
    ctx->downcount -= 3;
    // 802CC858: lwz     r0, -25356(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25356);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC85C:
    ctx->pc = 0x802CC85Cu;
    // 802CC85C: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CC860:
    ctx->pc = 0x802CC860u;
    // 802CC860: bc    4, 2, 0x802CC894
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CC894;
        }
    }

label_802CC864:
    ctx->pc = 0x802CC864u;
    ctx->downcount -= 12;
    // 802CC864: lwz     r7, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CC868:
    ctx->pc = 0x802CC868u;
    // 802CC868: lhz     r6, 58(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(58);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_802CC86C:
    ctx->pc = 0x802CC86Cu;
    // 802CC86C: lhz     r7, 56(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(56);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_802CC870:
    ctx->pc = 0x802CC870u;
    // 802CC870: rlwimi r7, r6, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[6], 16u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_802CC874:
    ctx->pc = 0x802CC874u;
    // 802CC874: addis   r0, r7, -32768
    ctx->gpr[0] = ctx->gpr[7] + ((u32)(s32)(-32768) << 16);

label_802CC878:
    ctx->pc = 0x802CC878u;
    // 802CC878: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC87C:
    ctx->pc = 0x802CC87Cu;
    // 802CC87C: lwz     r7, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CC880:
    ctx->pc = 0x802CC880u;
    // 802CC880: lhz     r6, 50(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(50);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_802CC884:
    ctx->pc = 0x802CC884u;
    // 802CC884: lhz     r0, 48(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CC888:
    ctx->pc = 0x802CC888u;
    // 802CC888: rlwimi r0, r6, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[6], 16u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_802CC88C:
    ctx->pc = 0x802CC88Cu;
    // 802CC88C: stw     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC890:
    ctx->pc = 0x802CC890u;
    // 802CC890: b       0x802CC8BC
    {
            goto label_802CC8BC;
    }

label_802CC894:
    ctx->pc = 0x802CC894u;
    ctx->downcount -= 7;
    // 802CC894: lwz     r6, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CC898:
    ctx->pc = 0x802CC898u;
    // 802CC898: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC89C:
    ctx->pc = 0x802CC89Cu;
    // 802CC89C: subf   r0, r6, r0
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_802CC8A0:
    ctx->pc = 0x802CC8A0u;
    // 802CC8A0: stw     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC8A4:
    ctx->pc = 0x802CC8A4u;
    // 802CC8A4: lwz     r6, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CC8A8:
    ctx->pc = 0x802CC8A8u;
    // 802CC8A8: cmpwi   r6, 0
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CC8AC:
    ctx->pc = 0x802CC8ACu;
    // 802CC8AC: bc    4, 0, 0x802CC8BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CC8BC;
        }
    }

label_802CC8B0:
    ctx->pc = 0x802CC8B0u;
    ctx->downcount -= 3;
    // 802CC8B0: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC8B4:
    ctx->pc = 0x802CC8B4u;
    // 802CC8B4: add   r0, r6, r0
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CC8B8:
    ctx->pc = 0x802CC8B8u;
    // 802CC8B8: stw     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC8BC:
    ctx->pc = 0x802CC8BCu;
    ctx->downcount -= 5;
    // 802CC8BC: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC8C0:
    ctx->pc = 0x802CC8C0u;
    // 802CC8C0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC8C4:
    ctx->pc = 0x802CC8C4u;
    // 802CC8C4: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC8C8:
    ctx->pc = 0x802CC8C8u;
    // 802CC8C8: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC8CC:
    ctx->pc = 0x802CC8CCu;
    // 802CC8CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC8D0:
    ctx->pc = 0x802CC8D0u;
    ctx->downcount -= 2;
    // 802CC8D0: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC8D4:
    ctx->pc = 0x802CC8D4u;
    // 802CC8D4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC8D8:
    ctx->pc = 0x802CC8D8u;
    ctx->downcount -= 2;
    // 802CC8D8: lwz     r3, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC8DC:
    ctx->pc = 0x802CC8DCu;
    // 802CC8DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC8E0:
    ctx->pc = 0x802CC8E0u;
    ctx->downcount -= 5;
    // 802CC8E0: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC8E4:
    ctx->pc = 0x802CC8E4u;
    // 802CC8E4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC8E8:
    ctx->pc = 0x802CC8E8u;
    // 802CC8E8: lwz     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC8EC:
    ctx->pc = 0x802CC8ECu;
    // 802CC8EC: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC8F0:
    ctx->pc = 0x802CC8F0u;
    // 802CC8F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC8F4:
    ctx->pc = 0x802CC8F4u;
    ctx->downcount -= 8;
    // 802CC8F4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC8F8:
    ctx->pc = 0x802CC8F8u;
    // 802CC8F8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC8FC:
    ctx->pc = 0x802CC8FCu;
    // 802CC8FC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC900:
    ctx->pc = 0x802CC900u;
    // 802CC900: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CC904:
    ctx->pc = 0x802CC904u;
    // 802CC904: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC908:
    ctx->pc = 0x802CC908u;
    // 802CC908: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CC90C:
    ctx->pc = 0x802CC90Cu;
    // 802CC90C: lwz     r31, -25340(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25340);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CC910:
    ctx->pc = 0x802CC910u;
    // 802CC910: bl      0x802C30E8
    {
            ctx->lr = 0x802CC914u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CC914:
    ctx->pc = 0x802CC914u;
    ctx->downcount -= 2;
    // 802CC914: stw     r30, -25340(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25340);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC918:
    ctx->pc = 0x802CC918u;
    // 802CC918: bl      0x802C3110
    {
            ctx->lr = 0x802CC91Cu;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CC91C:
    ctx->pc = 0x802CC91Cu;
    ctx->downcount -= 8;
    // 802CC91C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CC920:
    ctx->pc = 0x802CC920u;
    // 802CC920: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC924:
    ctx->pc = 0x802CC924u;
    // 802CC924: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CC928:
    ctx->pc = 0x802CC928u;
    // 802CC928: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CC92C:
    ctx->pc = 0x802CC92Cu;
    // 802CC92C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CC930:
    ctx->pc = 0x802CC930u;
    // 802CC930: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC934:
    ctx->pc = 0x802CC934u;
    // 802CC934: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC938:
    ctx->pc = 0x802CC938u;
    ctx->downcount -= 7;
    // 802CC938: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC93C:
    ctx->pc = 0x802CC93Cu;
    // 802CC93C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC940:
    ctx->pc = 0x802CC940u;
    // 802CC940: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC944:
    ctx->pc = 0x802CC944u;
    // 802CC944: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CC948:
    ctx->pc = 0x802CC948u;
    // 802CC948: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC94C:
    ctx->pc = 0x802CC94Cu;
    // 802CC94C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CC950:
    ctx->pc = 0x802CC950u;
    // 802CC950: bl      0x802C30E8
    {
            ctx->lr = 0x802CC954u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CC954:
    ctx->pc = 0x802CC954u;
    ctx->downcount -= 2;
    // 802CC954: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CC958:
    ctx->pc = 0x802CC958u;
    // 802CC958: bl      0x802CCA8C
    {
            ctx->lr = 0x802CC95Cu;
            goto label_802CCA8C;
    }

label_802CC95C:
    ctx->pc = 0x802CC95Cu;
    ctx->downcount -= 19;
    // 802CC95C: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC960:
    ctx->pc = 0x802CC960u;
    // 802CC960: rlwinm r0, r30, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 16u) & 0x00003FFFu;
    }

label_802CC964:
    ctx->pc = 0x802CC964u;
    // 802CC964: sth     r30, 60(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(60);
        mem_write16(ctx, ea, (u16)ctx->gpr[30]);
    }

label_802CC968:
    ctx->pc = 0x802CC968u;
    // 802CC968: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC96C:
    ctx->pc = 0x802CC96Cu;
    // 802CC96C: sth     r0, 62(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(62);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC970:
    ctx->pc = 0x802CC970u;
    // 802CC970: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC974:
    ctx->pc = 0x802CC974u;
    // 802CC974: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC978:
    ctx->pc = 0x802CC978u;
    // 802CC978: rlwinm r0, r0, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFDu;
    }

label_802CC97C:
    ctx->pc = 0x802CC97Cu;
    // 802CC97C: ori     r0, r0, 0x0002
    ctx->gpr[0] = ctx->gpr[0] | 0x0002u;

label_802CC980:
    ctx->pc = 0x802CC980u;
    // 802CC980: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC984:
    ctx->pc = 0x802CC984u;
    // 802CC984: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC988:
    ctx->pc = 0x802CC988u;
    // 802CC988: rlwinm r0, r0, 0, 27, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFDFu;
    }

label_802CC98C:
    ctx->pc = 0x802CC98Cu;
    // 802CC98C: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_802CC990:
    ctx->pc = 0x802CC990u;
    // 802CC990: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC994:
    ctx->pc = 0x802CC994u;
    // 802CC994: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC998:
    ctx->pc = 0x802CC998u;
    // 802CC998: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CC99C:
    ctx->pc = 0x802CC99Cu;
    // 802CC99C: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CC9A0:
    ctx->pc = 0x802CC9A0u;
    // 802CC9A0: stw     r30, -25332(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25332);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CC9A4:
    ctx->pc = 0x802CC9A4u;
    // 802CC9A4: bl      0x802CCA68
    {
            ctx->lr = 0x802CC9A8u;
            goto label_802CCA68;
    }

label_802CC9A8:
    ctx->pc = 0x802CC9A8u;
    ctx->downcount -= 2;
    // 802CC9A8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CC9AC:
    ctx->pc = 0x802CC9ACu;
    // 802CC9AC: bl      0x802C3110
    {
            ctx->lr = 0x802CC9B0u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CC9B0:
    ctx->pc = 0x802CC9B0u;
    ctx->downcount -= 7;
    // 802CC9B0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CC9B4:
    ctx->pc = 0x802CC9B4u;
    // 802CC9B4: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CC9B8:
    ctx->pc = 0x802CC9B8u;
    // 802CC9B8: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CC9BC:
    ctx->pc = 0x802CC9BCu;
    // 802CC9BC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CC9C0:
    ctx->pc = 0x802CC9C0u;
    // 802CC9C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CC9C4:
    ctx->pc = 0x802CC9C4u;
    // 802CC9C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CC9C8:
    ctx->pc = 0x802CC9C8u;
    ctx->downcount -= 4;
    // 802CC9C8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CC9CC:
    ctx->pc = 0x802CC9CCu;
    // 802CC9CC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CC9D0:
    ctx->pc = 0x802CC9D0u;
    // 802CC9D0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CC9D4:
    ctx->pc = 0x802CC9D4u;
    // 802CC9D4: bl      0x802C30E8
    {
            ctx->lr = 0x802CC9D8u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CC9D8:
    ctx->pc = 0x802CC9D8u;
    ctx->downcount -= 13;
    // 802CC9D8: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CC9DC:
    ctx->pc = 0x802CC9DCu;
    // 802CC9DC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CC9E0:
    ctx->pc = 0x802CC9E0u;
    // 802CC9E0: lwz     r4, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CC9E4:
    ctx->pc = 0x802CC9E4u;
    // 802CC9E4: rlwinm r4, r4, 0, 31, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFFDu;
    }

label_802CC9E8:
    ctx->pc = 0x802CC9E8u;
    // 802CC9E8: stw     r4, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CC9EC:
    ctx->pc = 0x802CC9ECu;
    // 802CC9EC: lwz     r4, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CC9F0:
    ctx->pc = 0x802CC9F0u;
    // 802CC9F0: rlwinm r4, r4, 0, 27, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFDFu;
    }

label_802CC9F4:
    ctx->pc = 0x802CC9F4u;
    // 802CC9F4: stw     r4, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CC9F8:
    ctx->pc = 0x802CC9F8u;
    // 802CC9F8: lwz     r5, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CC9FC:
    ctx->pc = 0x802CC9FCu;
    // 802CC9FC: lwz     r4, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCA00:
    ctx->pc = 0x802CCA00u;
    // 802CCA00: sth     r5, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_802CCA04:
    ctx->pc = 0x802CCA04u;
    // 802CCA04: stw     r0, -25332(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25332);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCA08:
    ctx->pc = 0x802CCA08u;
    // 802CCA08: bl      0x802C3110
    {
            ctx->lr = 0x802CCA0Cu;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CCA0C:
    ctx->pc = 0x802CCA0Cu;
    ctx->downcount -= 5;
    // 802CCA0C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCA10:
    ctx->pc = 0x802CCA10u;
    // 802CCA10: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802CCA14:
    ctx->pc = 0x802CCA14u;
    // 802CCA14: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CCA18:
    ctx->pc = 0x802CCA18u;
    // 802CCA18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCA1C:
    ctx->pc = 0x802CCA1Cu;
    ctx->downcount -= 7;
    // 802CCA1C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CCA20:
    ctx->pc = 0x802CCA20u;
    // 802CCA20: lis     r3, -32723
    ctx->gpr[3] = ((u32)(s32)(-32723) << 16);

label_802CCA24:
    ctx->pc = 0x802CCA24u;
    // 802CCA24: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCA28:
    ctx->pc = 0x802CCA28u;
    // 802CCA28: addi    r4, r3, -16120
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(-16120);

label_802CCA2C:
    ctx->pc = 0x802CCA2Cu;
    // 802CCA2C: li      r3, 17
    ctx->gpr[3] = (u32)(s32)(17);

label_802CCA30:
    ctx->pc = 0x802CCA30u;
    // 802CCA30: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CCA34:
    ctx->pc = 0x802CCA34u;
    // 802CCA34: bl      0x802C3134
    {
            ctx->lr = 0x802CCA38u;
            ctx->pc = 0x802C3134u;
            return;
    }

label_802CCA38:
    ctx->pc = 0x802CCA38u;
    ctx->downcount -= 2;
    // 802CCA38: li      r3, 16384
    ctx->gpr[3] = (u32)(s32)(16384);

label_802CCA3C:
    ctx->pc = 0x802CCA3Cu;
    // 802CCA3C: bl      0x802C35D4
    {
            ctx->lr = 0x802CCA40u;
            ctx->pc = 0x802C35D4u;
            return;
    }

label_802CCA40:
    ctx->pc = 0x802CCA40u;
    ctx->downcount -= 1;
    // 802CCA40: bl      0x802C73E4
    {
            ctx->lr = 0x802CCA44u;
            ctx->pc = 0x802C73E4u;
            return;
    }

label_802CCA44:
    ctx->pc = 0x802CCA44u;
    ctx->downcount -= 10;
    // 802CCA44: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CCA48:
    ctx->pc = 0x802CCA48u;
    // 802CCA48: stw     r3, -25352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25352);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CCA4C:
    ctx->pc = 0x802CCA4Cu;
    // 802CCA4C: stw     r0, -25344(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25344);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCA50:
    ctx->pc = 0x802CCA50u;
    // 802CCA50: stw     r0, -25360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25360);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCA54:
    ctx->pc = 0x802CCA54u;
    // 802CCA54: stw     r0, -25356(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCA58:
    ctx->pc = 0x802CCA58u;
    // 802CCA58: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCA5C:
    ctx->pc = 0x802CCA5Cu;
    // 802CCA5C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802CCA60:
    ctx->pc = 0x802CCA60u;
    // 802CCA60: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CCA64:
    ctx->pc = 0x802CCA64u;
    // 802CCA64: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCA68:
    ctx->pc = 0x802CCA68u;
    ctx->downcount -= 9;
    // 802CCA68: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCA6C:
    ctx->pc = 0x802CCA6Cu;
    // 802CCA6C: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCA70:
    ctx->pc = 0x802CCA70u;
    // 802CCA70: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_802CCA74:
    ctx->pc = 0x802CCA74u;
    // 802CCA74: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_802CCA78:
    ctx->pc = 0x802CCA78u;
    // 802CCA78: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCA7C:
    ctx->pc = 0x802CCA7Cu;
    // 802CCA7C: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCA80:
    ctx->pc = 0x802CCA80u;
    // 802CCA80: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCA84:
    ctx->pc = 0x802CCA84u;
    // 802CCA84: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCA88:
    ctx->pc = 0x802CCA88u;
    // 802CCA88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCA8C:
    ctx->pc = 0x802CCA8Cu;
    ctx->downcount -= 8;
    // 802CCA8C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCA90:
    ctx->pc = 0x802CCA90u;
    // 802CCA90: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCA94:
    ctx->pc = 0x802CCA94u;
    // 802CCA94: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_802CCA98:
    ctx->pc = 0x802CCA98u;
    // 802CCA98: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCA9C:
    ctx->pc = 0x802CCA9Cu;
    // 802CCA9C: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCAA0:
    ctx->pc = 0x802CCAA0u;
    // 802CCAA0: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCAA4:
    ctx->pc = 0x802CCAA4u;
    // 802CCAA4: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCAA8:
    ctx->pc = 0x802CCAA8u;
    // 802CCAA8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCAAC:
    ctx->pc = 0x802CCAACu;
    ctx->downcount -= 2;
    // 802CCAAC: rlwinm. r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CCAB0:
    ctx->pc = 0x802CCAB0u;
    // 802CCAB0: bc    12, 2, 0x802CCABC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CCABC;
        }
    }

label_802CCAB4:
    ctx->pc = 0x802CCAB4u;
    ctx->downcount -= 2;
    // 802CCAB4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802CCAB8:
    ctx->pc = 0x802CCAB8u;
    // 802CCAB8: b       0x802CCAC0
    {
            goto label_802CCAC0;
    }

label_802CCABC:
    ctx->pc = 0x802CCABCu;
    ctx->downcount -= 1;
    // 802CCABC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CCAC0:
    ctx->pc = 0x802CCAC0u;
    ctx->downcount -= 10;
    // 802CCAC0: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCAC4:
    ctx->pc = 0x802CCAC4u;
    // 802CCAC4: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_802CCAC8:
    ctx->pc = 0x802CCAC8u;
    // 802CCAC8: lwz     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCACC:
    ctx->pc = 0x802CCACCu;
    // 802CCACC: rlwinm r3, r3, 0, 28, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFEFu;
    }

label_802CCAD0:
    ctx->pc = 0x802CCAD0u;
    // 802CCAD0: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CCAD4:
    ctx->pc = 0x802CCAD4u;
    // 802CCAD4: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCAD8:
    ctx->pc = 0x802CCAD8u;
    // 802CCAD8: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCADC:
    ctx->pc = 0x802CCADCu;
    // 802CCADC: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCAE0:
    ctx->pc = 0x802CCAE0u;
    // 802CCAE0: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCAE4:
    ctx->pc = 0x802CCAE4u;
    // 802CCAE4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCAE8:
    ctx->pc = 0x802CCAE8u;
    ctx->downcount -= 15;
    // 802CCAE8: lwz     r6, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CCAEC:
    ctx->pc = 0x802CCAECu;
    // 802CCAEC: rlwinm r3, r3, 2, 22, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x000003FCu;
    }

label_802CCAF0:
    ctx->pc = 0x802CCAF0u;
    // 802CCAF0: rlwinm r0, r4, 3, 21, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0x000007F8u;
    }

label_802CCAF4:
    ctx->pc = 0x802CCAF4u;
    // 802CCAF4: lwz     r5, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CCAF8:
    ctx->pc = 0x802CCAF8u;
    // 802CCAF8: rlwinm r4, r5, 0, 30, 28
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFBu;
    }

label_802CCAFC:
    ctx->pc = 0x802CCAFCu;
    // 802CCAFC: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_802CCB00:
    ctx->pc = 0x802CCB00u;
    // 802CCB00: stw     r3, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CCB04:
    ctx->pc = 0x802CCB04u;
    // 802CCB04: lwz     r3, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCB08:
    ctx->pc = 0x802CCB08u;
    // 802CCB08: rlwinm r3, r3, 0, 29, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF7u;
    }

label_802CCB0C:
    ctx->pc = 0x802CCB0Cu;
    // 802CCB0C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CCB10:
    ctx->pc = 0x802CCB10u;
    // 802CCB10: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCB14:
    ctx->pc = 0x802CCB14u;
    // 802CCB14: lwz     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCB18:
    ctx->pc = 0x802CCB18u;
    // 802CCB18: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCB1C:
    ctx->pc = 0x802CCB1Cu;
    // 802CCB1C: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCB20:
    ctx->pc = 0x802CCB20u;
    // 802CCB20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCB24:
    ctx->pc = 0x802CCB24u;
    ctx->downcount -= 15;
    // 802CCB24: lwz     r6, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CCB28:
    ctx->pc = 0x802CCB28u;
    // 802CCB28: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_802CCB2C:
    ctx->pc = 0x802CCB2Cu;
    // 802CCB2C: rlwinm r0, r4, 1, 23, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0x000001FEu;
    }

label_802CCB30:
    ctx->pc = 0x802CCB30u;
    // 802CCB30: lwz     r5, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CCB34:
    ctx->pc = 0x802CCB34u;
    // 802CCB34: rlwinm r4, r5, 0, 0, 30
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFEu;
    }

label_802CCB38:
    ctx->pc = 0x802CCB38u;
    // 802CCB38: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_802CCB3C:
    ctx->pc = 0x802CCB3Cu;
    // 802CCB3C: stw     r3, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CCB40:
    ctx->pc = 0x802CCB40u;
    // 802CCB40: lwz     r3, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCB44:
    ctx->pc = 0x802CCB44u;
    // 802CCB44: rlwinm r3, r3, 0, 31, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFDu;
    }

label_802CCB48:
    ctx->pc = 0x802CCB48u;
    // 802CCB48: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CCB4C:
    ctx->pc = 0x802CCB4Cu;
    // 802CCB4C: stw     r0, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCB50:
    ctx->pc = 0x802CCB50u;
    // 802CCB50: lwz     r0, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCB54:
    ctx->pc = 0x802CCB54u;
    // 802CCB54: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCB58:
    ctx->pc = 0x802CCB58u;
    // 802CCB58: sth     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCB5C:
    ctx->pc = 0x802CCB5Cu;
    // 802CCB5C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCB60:
    ctx->pc = 0x802CCB60u;
    ctx->downcount -= 12;
    // 802CCB60: lwz     r4, -25356(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25356);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCB64:
    ctx->pc = 0x802CCB64u;
    // 802CCB64: lwz     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCB68:
    ctx->pc = 0x802CCB68u;
    // 802CCB68: addi    r0, r3, 512
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(512);

label_802CCB6C:
    ctx->pc = 0x802CCB6Cu;
    // 802CCB6C: stw     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCB70:
    ctx->pc = 0x802CCB70u;
    // 802CCB70: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCB74:
    ctx->pc = 0x802CCB74u;
    // 802CCB74: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCB78:
    ctx->pc = 0x802CCB78u;
    // 802CCB78: sth     r0, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCB7C:
    ctx->pc = 0x802CCB7Cu;
    // 802CCB7C: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCB80:
    ctx->pc = 0x802CCB80u;
    // 802CCB80: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCB84:
    ctx->pc = 0x802CCB84u;
    // 802CCB84: rlwinm r0, r0, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00003FFFu;
    }

label_802CCB88:
    ctx->pc = 0x802CCB88u;
    // 802CCB88: sth     r0, 42(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(42);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCB8C:
    ctx->pc = 0x802CCB8Cu;
    // 802CCB8C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCB90:
    ctx->pc = 0x802CCB90u;
    ctx->downcount -= 7;
    // 802CCB90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CCB94:
    ctx->pc = 0x802CCB94u;
    // 802CCB94: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCB98:
    ctx->pc = 0x802CCB98u;
    // 802CCB98: stwu     r1, -168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-168);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CCB9C:
    ctx->pc = 0x802CCB9Cu;
    // 802CCB9C: stw     r31, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CCBA0:
    ctx->pc = 0x802CCBA0u;
    // 802CCBA0: stw     r30, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CCBA4:
    ctx->pc = 0x802CCBA4u;
    // 802CCBA4: stw     r29, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802CCBA8:
    ctx->pc = 0x802CCBA8u;
    // 802CCBA8: bl      0x802CCCEC
    {
            ctx->lr = 0x802CCBACu;
            goto label_802CCCEC;
    }

label_802CCBAC:
    ctx->pc = 0x802CCBACu;
    ctx->downcount -= 2;
    // 802CCBAC: or.   r31, r3, r3
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

label_802CCBB0:
    ctx->pc = 0x802CCBB0u;
    // 802CCBB0: bc    12, 2, 0x802CCC74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CCC74;
        }
    }

label_802CCBB4:
    ctx->pc = 0x802CCBB4u;
    ctx->downcount -= 1;
    // 802CCBB4: bl      0x802CCCE4
    {
            ctx->lr = 0x802CCBB8u;
            goto label_802CCCE4;
    }

label_802CCBB8:
    ctx->pc = 0x802CCBB8u;
    ctx->downcount -= 7;
    // 802CCBB8: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_802CCBBC:
    ctx->pc = 0x802CCBBCu;
    // 802CCBBC: lwz     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802CCBC0:
    ctx->pc = 0x802CCBC0u;
    // 802CCBC0: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802CCBC4:
    ctx->pc = 0x802CCBC4u;
    // 802CCBC4: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_802CCBC8:
    ctx->pc = 0x802CCBC8u;
    // 802CCBC8: addi    r5, r1, 12
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(12);

label_802CCBCC:
    ctx->pc = 0x802CCBCCu;
    // 802CCBCC: addi    r4, r31, -8
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(-8);

label_802CCBD0:
    loop_802CCBD0(ctx);
    if (ctx->pc == 0x802CCBE4u) goto label_802CCBE4;
    return;
label_802CCBD4:
    ctx->pc = 0x802CCBD4u;
    // 802CCBD4: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCBD8:
    ctx->pc = 0x802CCBD8u;
    // 802CCBD8: stwu     r3, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
        ctx->gpr[5] = ea;
    }

label_802CCBDC:
    ctx->pc = 0x802CCBDCu;
    // 802CCBDC: stw     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCBE0:
    // 802CCBE0: bc    16, 0, 0x802CCBD0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CCBD0u;
                return;
            }
            goto label_802CCBD0;
        }
    }

label_802CCBE4:
    ctx->pc = 0x802CCBE4u;
    ctx->downcount -= 1;
    // 802CCBE4: bl      0x802C30E8
    {
            ctx->lr = 0x802CCBE8u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CCBE8:
    ctx->pc = 0x802CCBE8u;
    ctx->downcount -= 7;
    // 802CCBE8: stw     r29, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802CCBEC:
    ctx->pc = 0x802CCBECu;
    // 802CCBEC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CCBF0:
    ctx->pc = 0x802CCBF0u;
    // 802CCBF0: stw     r29, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802CCBF4:
    ctx->pc = 0x802CCBF4u;
    // 802CCBF4: stw     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCBF8:
    ctx->pc = 0x802CCBF8u;
    // 802CCBF8: lwz     r4, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCBFC:
    ctx->pc = 0x802CCBFCu;
    // 802CCBFC: cmpwi   r4, 0
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

label_802CCC00:
    ctx->pc = 0x802CCC00u;
    // 802CCC00: bc    4, 0, 0x802CCC10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CCC10;
        }
    }

label_802CCC04:
    ctx->pc = 0x802CCC04u;
    ctx->downcount -= 3;
    // 802CCC04: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCC08:
    ctx->pc = 0x802CCC08u;
    // 802CCC08: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CCC0C:
    ctx->pc = 0x802CCC0Cu;
    // 802CCC0C: stw     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCC10:
    ctx->pc = 0x802CCC10u;
    ctx->downcount -= 1;
    // 802CCC10: bl      0x802C3110
    {
            ctx->lr = 0x802CCC14u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CCC14:
    ctx->pc = 0x802CCC14u;
    ctx->downcount -= 2;
    // 802CCC14: addi    r3, r1, 20
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(20);

label_802CCC18:
    ctx->pc = 0x802CCC18u;
    // 802CCC18: bl      0x802CC434
    {
            ctx->lr = 0x802CCC1Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CC434u;
                return;
            }
            goto label_802CC434;
    }

label_802CCC1C:
    ctx->pc = 0x802CCC1Cu;
    ctx->downcount -= 2;
    // 802CCC1C: cmplw   r30, r31
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CCC20:
    ctx->pc = 0x802CCC20u;
    // 802CCC20: bc    4, 2, 0x802CCC2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CCC2C;
        }
    }

label_802CCC24:
    ctx->pc = 0x802CCC24u;
    ctx->downcount -= 2;
    // 802CCC24: addi    r3, r1, 20
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(20);

label_802CCC28:
    ctx->pc = 0x802CCC28u;
    // 802CCC28: bl      0x802CC324
    {
            ctx->lr = 0x802CCC2Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CC324u;
                return;
            }
            goto label_802CC324;
    }

label_802CCC2C:
    ctx->pc = 0x802CCC2Cu;
    ctx->downcount -= 1;
    // 802CCC2C: bl      0x802C30E8
    {
            ctx->lr = 0x802CCC30u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CCC30:
    ctx->pc = 0x802CCC30u;
    ctx->downcount -= 7;
    // 802CCC30: stw     r29, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802CCC34:
    ctx->pc = 0x802CCC34u;
    // 802CCC34: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CCC38:
    ctx->pc = 0x802CCC38u;
    // 802CCC38: stw     r29, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802CCC3C:
    ctx->pc = 0x802CCC3Cu;
    // 802CCC3C: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCC40:
    ctx->pc = 0x802CCC40u;
    // 802CCC40: lwz     r4, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCC44:
    ctx->pc = 0x802CCC44u;
    // 802CCC44: cmpwi   r4, 0
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

label_802CCC48:
    ctx->pc = 0x802CCC48u;
    // 802CCC48: bc    4, 0, 0x802CCC58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CCC58;
        }
    }

label_802CCC4C:
    ctx->pc = 0x802CCC4Cu;
    ctx->downcount -= 3;
    // 802CCC4C: lwz     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCC50:
    ctx->pc = 0x802CCC50u;
    // 802CCC50: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CCC54:
    ctx->pc = 0x802CCC54u;
    // 802CCC54: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCC58:
    ctx->pc = 0x802CCC58u;
    ctx->downcount -= 1;
    // 802CCC58: bl      0x802C3110
    {
            ctx->lr = 0x802CCC5Cu;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CCC5C:
    ctx->pc = 0x802CCC5Cu;
    ctx->downcount -= 2;
    // 802CCC5C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CCC60:
    ctx->pc = 0x802CCC60u;
    // 802CCC60: bl      0x802CC434
    {
            ctx->lr = 0x802CCC64u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CC434u;
                return;
            }
            goto label_802CC434;
    }

label_802CCC64:
    ctx->pc = 0x802CCC64u;
    ctx->downcount -= 2;
    // 802CCC64: cmplw   r30, r31
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CCC68:
    ctx->pc = 0x802CCC68u;
    // 802CCC68: bc    4, 2, 0x802CCC74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CCC74;
        }
    }

label_802CCC6C:
    ctx->pc = 0x802CCC6Cu;
    ctx->downcount -= 2;
    // 802CCC6C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802CCC70:
    ctx->pc = 0x802CCC70u;
    // 802CCC70: bl      0x802CC324
    {
            ctx->lr = 0x802CCC74u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CC324u;
                return;
            }
            goto label_802CC324;
    }

label_802CCC74:
    ctx->pc = 0x802CCC74u;
    ctx->downcount -= 8;
    // 802CCC74: lwz     r0, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCC78:
    ctx->pc = 0x802CCC78u;
    // 802CCC78: lwz     r31, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CCC7C:
    ctx->pc = 0x802CCC7Cu;
    // 802CCC7C: lwz     r30, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CCC80:
    ctx->pc = 0x802CCC80u;
    // 802CCC80: lwz     r29, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802CCC84:
    ctx->pc = 0x802CCC84u;
    // 802CCC84: addi    r1, r1, 168
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(168);

label_802CCC88:
    ctx->pc = 0x802CCC88u;
    // 802CCC88: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CCC8C:
    ctx->pc = 0x802CCC8Cu;
    // 802CCC8C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCC90:
    ctx->pc = 0x802CCC90u;
    ctx->downcount -= 6;
    // 802CCC90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CCC94:
    ctx->pc = 0x802CCC94u;
    // 802CCC94: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCC98:
    ctx->pc = 0x802CCC98u;
    // 802CCC98: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CCC9C:
    ctx->pc = 0x802CCC9Cu;
    // 802CCC9C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CCCA0:
    ctx->pc = 0x802CCCA0u;
    // 802CCCA0: stw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CCCA4:
    ctx->pc = 0x802CCCA4u;
    // 802CCCA4: bl      0x802C30E8
    {
            ctx->lr = 0x802CCCA8u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CCCA8:
    ctx->pc = 0x802CCCA8u;
    ctx->downcount -= 3;
    // 802CCCA8: lwz     r30, -25352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25352);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CCCAC:
    ctx->pc = 0x802CCCACu;
    // 802CCCAC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CCCB0:
    ctx->pc = 0x802CCCB0u;
    // 802CCCB0: bl      0x802C73E4
    {
            ctx->lr = 0x802CCCB4u;
            ctx->pc = 0x802C73E4u;
            return;
    }

label_802CCCB4:
    ctx->pc = 0x802CCCB4u;
    ctx->downcount -= 3;
    // 802CCCB4: stw     r3, -25352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25352);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CCCB8:
    ctx->pc = 0x802CCCB8u;
    // 802CCCB8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CCCBC:
    ctx->pc = 0x802CCCBCu;
    // 802CCCBC: bl      0x802C3110
    {
            ctx->lr = 0x802CCCC0u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CCCC0:
    ctx->pc = 0x802CCCC0u;
    ctx->downcount -= 8;
    // 802CCCC0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802CCCC4:
    ctx->pc = 0x802CCCC4u;
    // 802CCCC4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCCC8:
    ctx->pc = 0x802CCCC8u;
    // 802CCCC8: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CCCCC:
    ctx->pc = 0x802CCCCCu;
    // 802CCCCC: lwz     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CCCD0:
    ctx->pc = 0x802CCCD0u;
    // 802CCCD0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_802CCCD4:
    ctx->pc = 0x802CCCD4u;
    // 802CCCD4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CCCD8:
    ctx->pc = 0x802CCCD8u;
    // 802CCCD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCCDC:
    ctx->pc = 0x802CCCDCu;
    ctx->downcount -= 2;
    // 802CCCDC: lwz     r3, -25352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25352);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCCE0:
    ctx->pc = 0x802CCCE0u;
    // 802CCCE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCCE4:
    ctx->pc = 0x802CCCE4u;
    ctx->downcount -= 2;
    // 802CCCE4: lwz     r3, -25360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25360);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCCE8:
    ctx->pc = 0x802CCCE8u;
    // 802CCCE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCCEC:
    ctx->pc = 0x802CCCECu;
    ctx->downcount -= 2;
    // 802CCCEC: lwz     r3, -25356(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25356);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCCF0:
    ctx->pc = 0x802CCCF0u;
    // 802CCCF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCCF4:
    ctx->pc = 0x802CCCF4u;
    ctx->downcount -= 2;
    // 802CCCF4: lwz     r3, -25336(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25336);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCCF8:
    ctx->pc = 0x802CCCF8u;
    // 802CCCF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCCFC:
    ctx->pc = 0x802CCCFCu;
    ctx->downcount -= 4;
    // 802CCCFC: lwz     r3, -25336(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25336);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCD00:
    ctx->pc = 0x802CCD00u;
    // 802CCD00: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CCD04:
    ctx->pc = 0x802CCD04u;
    // 802CCD04: stw     r0, -25336(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25336);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCD08:
    ctx->pc = 0x802CCD08u;
    // 802CCD08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCD0C:
    ctx->pc = 0x802CCD0Cu;
    ctx->downcount -= 7;
    // 802CCD0C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CCD10:
    ctx->pc = 0x802CCD10u;
    // 802CCD10: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCD14:
    ctx->pc = 0x802CCD14u;
    // 802CCD14: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CCD18:
    ctx->pc = 0x802CCD18u;
    // 802CCD18: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CCD1C:
    ctx->pc = 0x802CCD1Cu;
    // 802CCD1C: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CCD20:
    ctx->pc = 0x802CCD20u;
    // 802CCD20: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CCD24:
    ctx->pc = 0x802CCD24u;
    // 802CCD24: bl      0x802C30E8
    {
            ctx->lr = 0x802CCD28u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CCD28:
    ctx->pc = 0x802CCD28u;
    ctx->downcount -= 2;
    // 802CCD28: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CCD2C:
    ctx->pc = 0x802CCD2Cu;
    // 802CCD2C: bl      0x802CEA48
    {
            ctx->lr = 0x802CCD30u;
            goto label_802CEA48;
    }

label_802CCD30:
    ctx->downcount -= 1;
    // 802CCD30: bl      0x802D6534
    {
            ctx->lr = 0x802CCD34u;
            ctx->pc = 0x802D6534u;
            return;
    }

label_802CCD34:
    ctx->downcount -= 2;
    // 802CCD34: rlwinm. r0, r3, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CCD38:
    // 802CCD38: bc    4, 2, 0x802CCD30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CCD30u;
                return;
            }
            goto label_802CCD30;
        }
    }

label_802CCD3C:
    ctx->pc = 0x802CCD3Cu;
    ctx->downcount -= 3;
    // 802CCD3C: lis     r3, 3073
    ctx->gpr[3] = ((u32)(s32)(3073) << 16);

label_802CCD40:
    ctx->pc = 0x802CCD40u;
    // 802CCD40: addi    r3, r3, -32768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32768);

label_802CCD44:
    ctx->pc = 0x802CCD44u;
    // 802CCD44: bl      0x802D6540
    {
            ctx->lr = 0x802CCD48u;
            ctx->pc = 0x802D6540u;
            return;
    }

label_802CCD48:
    ctx->pc = 0x802CCD48u;
    ctx->downcount -= 3;
    // 802CCD48: lbz     r0, -25348(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25348);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CCD4C:
    ctx->pc = 0x802CCD4Cu;
    // 802CCD4C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CCD50:
    ctx->pc = 0x802CCD50u;
    // 802CCD50: bc    12, 2, 0x802CCD94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CCD94;
        }
    }

label_802CCD54:
    ctx->pc = 0x802CCD54u;
    ctx->downcount -= 16;
    // 802CCD54: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCD58:
    ctx->pc = 0x802CCD58u;
    // 802CCD58: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCD5C:
    ctx->pc = 0x802CCD5Cu;
    // 802CCD5C: rlwinm r0, r0, 0, 28, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFEFu;
    }

label_802CCD60:
    ctx->pc = 0x802CCD60u;
    // 802CCD60: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCD64:
    ctx->pc = 0x802CCD64u;
    // 802CCD64: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCD68:
    ctx->pc = 0x802CCD68u;
    // 802CCD68: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCD6C:
    ctx->pc = 0x802CCD6Cu;
    // 802CCD6C: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCD70:
    ctx->pc = 0x802CCD70u;
    // 802CCD70: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCD74:
    ctx->pc = 0x802CCD74u;
    // 802CCD74: rlwinm r0, r0, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFBu;
    }

label_802CCD78:
    ctx->pc = 0x802CCD78u;
    // 802CCD78: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCD7C:
    ctx->pc = 0x802CCD7Cu;
    // 802CCD7C: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCD80:
    ctx->pc = 0x802CCD80u;
    // 802CCD80: rlwinm r0, r0, 0, 29, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF7u;
    }

label_802CCD84:
    ctx->pc = 0x802CCD84u;
    // 802CCD84: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCD88:
    ctx->pc = 0x802CCD88u;
    // 802CCD88: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCD8C:
    ctx->pc = 0x802CCD8Cu;
    // 802CCD8C: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCD90:
    ctx->pc = 0x802CCD90u;
    // 802CCD90: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCD94:
    ctx->pc = 0x802CCD94u;
    ctx->downcount -= 17;
    // 802CCD94: lwz     r4, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCD98:
    ctx->pc = 0x802CCD98u;
    // 802CCD98: rlwinm r5, r30, 0, 2, 26
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x3FFFFFE0u;
    }

label_802CCD9C:
    ctx->pc = 0x802CCD9Cu;
    // 802CCD9C: lwz     r3, -25360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25360);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCDA0:
    ctx->pc = 0x802CCDA0u;
    // 802CCDA0: rlwinm r5, r5, 0, 6, 4
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFBFFFFFFu;
    }

label_802CCDA4:
    ctx->pc = 0x802CCDA4u;
    // 802CCDA4: lwz     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCDA8:
    ctx->pc = 0x802CCDA8u;
    // 802CCDA8: rlwinm r4, r0, 0, 6, 4
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFBFFFFFFu;
    }

label_802CCDAC:
    ctx->pc = 0x802CCDACu;
    // 802CCDAC: addis   r0, r4, -32768
    ctx->gpr[0] = ctx->gpr[4] + ((u32)(s32)(-32768) << 16);

label_802CCDB0:
    ctx->pc = 0x802CCDB0u;
    // 802CCDB0: stw     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCDB4:
    ctx->pc = 0x802CCDB4u;
    // 802CCDB4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CCDB8:
    ctx->pc = 0x802CCDB8u;
    // 802CCDB8: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_802CCDBC:
    ctx->pc = 0x802CCDBCu;
    // 802CCDBC: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCDC0:
    ctx->pc = 0x802CCDC0u;
    // 802CCDC0: stw     r4, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CCDC4:
    ctx->pc = 0x802CCDC4u;
    // 802CCDC4: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCDC8:
    ctx->pc = 0x802CCDC8u;
    // 802CCDC8: stw     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCDCC:
    ctx->pc = 0x802CCDCCu;
    // 802CCDCC: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCDD0:
    ctx->pc = 0x802CCDD0u;
    // 802CCDD0: stw     r5, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CCDD4:
    ctx->pc = 0x802CCDD4u;
    // 802CCDD4: bl      0x802D641C
    {
            ctx->lr = 0x802CCDD8u;
            ctx->pc = 0x802D641Cu;
            return;
    }

label_802CCDD8:
    ctx->pc = 0x802CCDD8u;
    ctx->downcount -= 2;
    // 802CCDD8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CCDDC:
    ctx->pc = 0x802CCDDCu;
    // 802CCDDC: bl      0x802C3110
    {
            ctx->lr = 0x802CCDE0u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CCDE0:
    ctx->pc = 0x802CCDE0u;
    ctx->downcount -= 9;
    // 802CCDE0: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_802CCDE4:
    ctx->pc = 0x802CCDE4u;
    // 802CCDE4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCDE8:
    ctx->pc = 0x802CCDE8u;
    // 802CCDE8: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CCDEC:
    ctx->pc = 0x802CCDECu;
    // 802CCDEC: addi    r3, r3, -32768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32768);

label_802CCDF0:
    ctx->pc = 0x802CCDF0u;
    // 802CCDF0: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CCDF4:
    ctx->pc = 0x802CCDF4u;
    // 802CCDF4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CCDF8:
    ctx->pc = 0x802CCDF8u;
    // 802CCDF8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CCDFC:
    ctx->pc = 0x802CCDFCu;
    // 802CCDFC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCE00:
    ctx->pc = 0x802CCE00u;
    ctx->downcount -= 5;
    // 802CCE00: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CCE04:
    ctx->pc = 0x802CCE04u;
    // 802CCE04: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCE08:
    ctx->pc = 0x802CCE08u;
    // 802CCE08: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CCE0C:
    ctx->pc = 0x802CCE0Cu;
    // 802CCE0C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CCE10:
    ctx->pc = 0x802CCE10u;
    // 802CCE10: bl      0x802C30E8
    {
            ctx->lr = 0x802CCE14u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CCE14:
    ctx->pc = 0x802CCE14u;
    ctx->downcount -= 33;
    // 802CCE14: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_802CCE18:
    ctx->pc = 0x802CCE18u;
    // 802CCE18: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CCE1C:
    ctx->pc = 0x802CCE1Cu;
    // 802CCE1C: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE20:
    ctx->pc = 0x802CCE20u;
    // 802CCE20: li      r6, 24
    ctx->gpr[6] = (u32)(s32)(24);

label_802CCE24:
    ctx->pc = 0x802CCE24u;
    // 802CCE24: subfic  r0, r6, 31
    {
        u64 res = (u64)(u32)(s32)(31) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802CCE28:
    ctx->pc = 0x802CCE28u;
    // 802CCE28: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE2C:
    ctx->pc = 0x802CCE2Cu;
    // 802CCE2C: cmplwi  r6, 0x001F
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(0x001Fu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CCE30:
    ctx->pc = 0x802CCE30u;
    // 802CCE30: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802CCE34:
    ctx->pc = 0x802CCE34u;
    // 802CCE34: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CCE38:
    ctx->pc = 0x802CCE38u;
    // 802CCE38: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE3C:
    ctx->pc = 0x802CCE3Cu;
    // 802CCE3C: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE40:
    ctx->pc = 0x802CCE40u;
    // 802CCE40: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE44:
    ctx->pc = 0x802CCE44u;
    // 802CCE44: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE48:
    ctx->pc = 0x802CCE48u;
    // 802CCE48: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE4C:
    ctx->pc = 0x802CCE4Cu;
    // 802CCE4C: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE50:
    ctx->pc = 0x802CCE50u;
    // 802CCE50: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE54:
    ctx->pc = 0x802CCE54u;
    // 802CCE54: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE58:
    ctx->pc = 0x802CCE58u;
    // 802CCE58: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE5C:
    ctx->pc = 0x802CCE5Cu;
    // 802CCE5C: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE60:
    ctx->pc = 0x802CCE60u;
    // 802CCE60: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE64:
    ctx->pc = 0x802CCE64u;
    // 802CCE64: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE68:
    ctx->pc = 0x802CCE68u;
    // 802CCE68: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE6C:
    ctx->pc = 0x802CCE6Cu;
    // 802CCE6C: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE70:
    ctx->pc = 0x802CCE70u;
    // 802CCE70: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE74:
    ctx->pc = 0x802CCE74u;
    // 802CCE74: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE78:
    ctx->pc = 0x802CCE78u;
    // 802CCE78: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE7C:
    ctx->pc = 0x802CCE7Cu;
    // 802CCE7C: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE80:
    ctx->pc = 0x802CCE80u;
    // 802CCE80: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE84:
    ctx->pc = 0x802CCE84u;
    // 802CCE84: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE88:
    ctx->pc = 0x802CCE88u;
    // 802CCE88: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE8C:
    ctx->pc = 0x802CCE8Cu;
    // 802CCE8C: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CCE90:
    ctx->pc = 0x802CCE90u;
    // 802CCE90: bc    4, 0, 0x802CCE9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CCE9C;
        }
    }

label_802CCE94:
    loop_802CCE94(ctx);
    if (ctx->pc == 0x802CCE9Cu) goto label_802CCE9C;
    return;
label_802CCE98:
    // 802CCE98: bc    16, 0, 0x802CCE94
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CCE94u;
                return;
            }
            goto label_802CCE94;
        }
    }

label_802CCE9C:
    ctx->pc = 0x802CCE9Cu;
    ctx->downcount -= 1;
    // 802CCE9C: bl      0x802D641C
    {
            ctx->lr = 0x802CCEA0u;
            ctx->pc = 0x802D641Cu;
            return;
    }

label_802CCEA0:
    ctx->downcount -= 1;
    // 802CCEA0: bl      0x802D6534
    {
            ctx->lr = 0x802CCEA4u;
            ctx->pc = 0x802D6534u;
            return;
    }

label_802CCEA4:
    ctx->downcount -= 2;
    // 802CCEA4: rlwinm. r0, r3, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CCEA8:
    // 802CCEA8: bc    4, 2, 0x802CCEA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CCEA0u;
                return;
            }
            goto label_802CCEA0;
        }
    }

label_802CCEAC:
    ctx->pc = 0x802CCEACu;
    ctx->downcount -= 3;
    // 802CCEAC: lis     r3, 3073
    ctx->gpr[3] = ((u32)(s32)(3073) << 16);

label_802CCEB0:
    ctx->pc = 0x802CCEB0u;
    // 802CCEB0: addi    r3, r3, -32768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32768);

label_802CCEB4:
    ctx->pc = 0x802CCEB4u;
    // 802CCEB4: bl      0x802D6540
    {
            ctx->lr = 0x802CCEB8u;
            ctx->pc = 0x802D6540u;
            return;
    }

label_802CCEB8:
    ctx->pc = 0x802CCEB8u;
    ctx->downcount -= 19;
    // 802CCEB8: lwz     r4, -25360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25360);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCEBC:
    ctx->pc = 0x802CCEBCu;
    // 802CCEBC: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCEC0:
    ctx->pc = 0x802CCEC0u;
    // 802CCEC0: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCEC4:
    ctx->pc = 0x802CCEC4u;
    // 802CCEC4: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_802CCEC8:
    ctx->pc = 0x802CCEC8u;
    // 802CCEC8: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCECC:
    ctx->pc = 0x802CCECCu;
    // 802CCECC: lwz     r4, -25360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25360);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCED0:
    ctx->pc = 0x802CCED0u;
    // 802CCED0: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCED4:
    ctx->pc = 0x802CCED4u;
    // 802CCED4: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCED8:
    ctx->pc = 0x802CCED8u;
    // 802CCED8: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_802CCEDC:
    ctx->pc = 0x802CCEDCu;
    // 802CCEDC: stw     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCEE0:
    ctx->pc = 0x802CCEE0u;
    // 802CCEE0: lwz     r4, -25360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25360);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCEE4:
    ctx->pc = 0x802CCEE4u;
    // 802CCEE4: lwz     r3, -25400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCEE8:
    ctx->pc = 0x802CCEE8u;
    // 802CCEE8: lwz     r0, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCEEC:
    ctx->pc = 0x802CCEECu;
    // 802CCEEC: rlwinm r0, r0, 0, 2, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFE0u;
    }

label_802CCEF0:
    ctx->pc = 0x802CCEF0u;
    // 802CCEF0: rlwinm r0, r0, 0, 6, 4
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFBFFFFFFu;
    }

label_802CCEF4:
    ctx->pc = 0x802CCEF4u;
    // 802CCEF4: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCEF8:
    ctx->pc = 0x802CCEF8u;
    // 802CCEF8: lbz     r0, -25348(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25348);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CCEFC:
    ctx->pc = 0x802CCEFCu;
    // 802CCEFC: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CCF00:
    ctx->pc = 0x802CCF00u;
    // 802CCF00: bc    12, 2, 0x802CCF78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CCF78;
        }
    }

label_802CCF04:
    ctx->pc = 0x802CCF04u;
    ctx->downcount -= 29;
    // 802CCF04: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCF08:
    ctx->pc = 0x802CCF08u;
    // 802CCF08: lwz     r0, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCF0C:
    ctx->pc = 0x802CCF0Cu;
    // 802CCF0C: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_802CCF10:
    ctx->pc = 0x802CCF10u;
    // 802CCF10: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_802CCF14:
    ctx->pc = 0x802CCF14u;
    // 802CCF14: stw     r0, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCF18:
    ctx->pc = 0x802CCF18u;
    // 802CCF18: lwz     r0, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCF1C:
    ctx->pc = 0x802CCF1Cu;
    // 802CCF1C: rlwinm r0, r0, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFDu;
    }

label_802CCF20:
    ctx->pc = 0x802CCF20u;
    // 802CCF20: ori     r0, r0, 0x0002
    ctx->gpr[0] = ctx->gpr[0] | 0x0002u;

label_802CCF24:
    ctx->pc = 0x802CCF24u;
    // 802CCF24: stw     r0, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCF28:
    ctx->pc = 0x802CCF28u;
    // 802CCF28: lwz     r0, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCF2C:
    ctx->pc = 0x802CCF2Cu;
    // 802CCF2C: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCF30:
    ctx->pc = 0x802CCF30u;
    // 802CCF30: sth     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCF34:
    ctx->pc = 0x802CCF34u;
    // 802CCF34: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCF38:
    ctx->pc = 0x802CCF38u;
    // 802CCF38: rlwinm r0, r0, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFBu;
    }

label_802CCF3C:
    ctx->pc = 0x802CCF3Cu;
    // 802CCF3C: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_802CCF40:
    ctx->pc = 0x802CCF40u;
    // 802CCF40: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCF44:
    ctx->pc = 0x802CCF44u;
    // 802CCF44: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCF48:
    ctx->pc = 0x802CCF48u;
    // 802CCF48: rlwinm r0, r0, 0, 29, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF7u;
    }

label_802CCF4C:
    ctx->pc = 0x802CCF4Cu;
    // 802CCF4C: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCF50:
    ctx->pc = 0x802CCF50u;
    // 802CCF50: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCF54:
    ctx->pc = 0x802CCF54u;
    // 802CCF54: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCF58:
    ctx->pc = 0x802CCF58u;
    // 802CCF58: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCF5C:
    ctx->pc = 0x802CCF5Cu;
    // 802CCF5C: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCF60:
    ctx->pc = 0x802CCF60u;
    // 802CCF60: rlwinm r0, r0, 0, 28, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFEFu;
    }

label_802CCF64:
    ctx->pc = 0x802CCF64u;
    // 802CCF64: ori     r0, r0, 0x0010
    ctx->gpr[0] = ctx->gpr[0] | 0x0010u;

label_802CCF68:
    ctx->pc = 0x802CCF68u;
    // 802CCF68: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CCF6C:
    ctx->pc = 0x802CCF6Cu;
    // 802CCF6C: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCF70:
    ctx->pc = 0x802CCF70u;
    // 802CCF70: lwz     r3, -25396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CCF74:
    ctx->pc = 0x802CCF74u;
    // 802CCF74: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CCF78:
    ctx->pc = 0x802CCF78u;
    ctx->downcount -= 1;
    // 802CCF78: bl      0x802D641C
    {
            ctx->lr = 0x802CCF7Cu;
            ctx->pc = 0x802D641Cu;
            return;
    }

label_802CCF7C:
    ctx->pc = 0x802CCF7Cu;
    ctx->downcount -= 2;
    // 802CCF7C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CCF80:
    ctx->pc = 0x802CCF80u;
    // 802CCF80: bl      0x802C3110
    {
            ctx->lr = 0x802CCF84u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CCF84:
    ctx->pc = 0x802CCF84u;
    ctx->downcount -= 6;
    // 802CCF84: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CCF88:
    ctx->pc = 0x802CCF88u;
    // 802CCF88: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CCF8C:
    ctx->pc = 0x802CCF8Cu;
    // 802CCF8C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CCF90:
    ctx->pc = 0x802CCF90u;
    // 802CCF90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CCF94:
    ctx->pc = 0x802CCF94u;
    // 802CCF94: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CCF98:
    ctx->pc = 0x802CCF98u;
    ctx->downcount -= 4;
    // 802CCF98: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CCF9C:
    ctx->pc = 0x802CCF9Cu;
    // 802CCF9C: lwz     r4, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CCFA0:
    ctx->pc = 0x802CCFA0u;
    // 802CCFA0: rlwinm. r0, r4, 19, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 19u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CCFA4:
    ctx->pc = 0x802CCFA4u;
    // 802CCFA4: bc    12, 2, 0x802CCFB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CCFB0;
        }
    }

label_802CCFA8:
    ctx->pc = 0x802CCFA8u;
    ctx->downcount -= 2;
    // 802CCFA8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CCFAC:
    ctx->pc = 0x802CCFACu;
    // 802CCFAC: b       0x802CCFB4
    {
            goto label_802CCFB4;
    }

label_802CCFB0:
    ctx->pc = 0x802CCFB0u;
    ctx->downcount -= 1;
    // 802CCFB0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CCFB4:
    ctx->pc = 0x802CCFB4u;
    ctx->downcount -= 2;
    // 802CCFB4: rlwinm. r0, r4, 17, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 17u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CCFB8:
    ctx->pc = 0x802CCFB8u;
    // 802CCFB8: bc    12, 2, 0x802CCFC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CCFC4;
        }
    }

label_802CCFBC:
    ctx->pc = 0x802CCFBCu;
    ctx->downcount -= 2;
    // 802CCFBC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CCFC0:
    ctx->pc = 0x802CCFC0u;
    // 802CCFC0: b       0x802CCFC8
    {
            goto label_802CCFC8;
    }

label_802CCFC4:
    ctx->pc = 0x802CCFC4u;
    ctx->downcount -= 1;
    // 802CCFC4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CCFC8:
    ctx->pc = 0x802CCFC8u;
    ctx->downcount -= 4;
    // 802CCFC8: lbz     r0, 1053(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CCFCC:
    ctx->pc = 0x802CCFCCu;
    // 802CCFCC: add   r7, r3, r4
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_802CCFD0:
    ctx->pc = 0x802CCFD0u;
    // 802CCFD0: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CCFD4:
    ctx->pc = 0x802CCFD4u;
    // 802CCFD4: bc    12, 2, 0x802CCFE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CCFE0;
        }
    }

label_802CCFD8:
    ctx->pc = 0x802CCFD8u;
    ctx->downcount -= 2;
    // 802CCFD8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802CCFDC:
    ctx->pc = 0x802CCFDCu;
    // 802CCFDC: b       0x802CCFF8
    {
            goto label_802CCFF8;
    }

label_802CCFE0:
    ctx->pc = 0x802CCFE0u;
    ctx->downcount -= 3;
    // 802CCFE0: lbz     r0, 1052(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CCFE4:
    ctx->pc = 0x802CCFE4u;
    // 802CCFE4: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CCFE8:
    ctx->pc = 0x802CCFE8u;
    // 802CCFE8: bc    12, 2, 0x802CCFF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CCFF4;
        }
    }

label_802CCFEC:
    ctx->pc = 0x802CCFECu;
    ctx->downcount -= 2;
    // 802CCFEC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802CCFF0:
    ctx->pc = 0x802CCFF0u;
    // 802CCFF0: b       0x802CCFF8
    {
            goto label_802CCFF8;
    }

label_802CCFF4:
    ctx->pc = 0x802CCFF4u;
    ctx->downcount -= 1;
    // 802CCFF4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CCFF8:
    ctx->pc = 0x802CCFF8u;
    ctx->downcount -= 3;
    // 802CCFF8: lwz     r6, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CCFFC:
    ctx->pc = 0x802CCFFCu;
    // 802CCFFC: rlwinm. r0, r6, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CD000:
    ctx->pc = 0x802CD000u;
    // 802CD000: bc    12, 2, 0x802CD00C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD00C;
        }
    }

label_802CD004:
    ctx->pc = 0x802CD004u;
    ctx->downcount -= 2;
    // 802CD004: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CD008:
    ctx->pc = 0x802CD008u;
    // 802CD008: b       0x802CD010
    {
            goto label_802CD010;
    }

label_802CD00C:
    ctx->pc = 0x802CD00Cu;
    ctx->downcount -= 1;
    // 802CD00C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CD010:
    ctx->pc = 0x802CD010u;
    ctx->downcount -= 2;
    // 802CD010: rlwinm. r0, r6, 30, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 30u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CD014:
    ctx->pc = 0x802CD014u;
    // 802CD014: bc    12, 2, 0x802CD020
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD020;
        }
    }

label_802CD018:
    ctx->pc = 0x802CD018u;
    ctx->downcount -= 2;
    // 802CD018: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802CD01C:
    ctx->pc = 0x802CD01Cu;
    // 802CD01C: b       0x802CD024
    {
            goto label_802CD024;
    }

label_802CD020:
    ctx->pc = 0x802CD020u;
    ctx->downcount -= 1;
    // 802CD020: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CD024:
    ctx->pc = 0x802CD024u;
    ctx->downcount -= 3;
    // 802CD024: rlwinm. r0, r6, 28, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 28u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CD028:
    ctx->pc = 0x802CD028u;
    // 802CD028: add   r8, r3, r5
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_802CD02C:
    ctx->pc = 0x802CD02Cu;
    // 802CD02C: bc    12, 2, 0x802CD038
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD038;
        }
    }

label_802CD030:
    ctx->pc = 0x802CD030u;
    ctx->downcount -= 2;
    // 802CD030: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CD034:
    ctx->pc = 0x802CD034u;
    // 802CD034: b       0x802CD03C
    {
            goto label_802CD03C;
    }

label_802CD038:
    ctx->pc = 0x802CD038u;
    ctx->downcount -= 1;
    // 802CD038: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CD03C:
    ctx->pc = 0x802CD03Cu;
    ctx->downcount -= 3;
    // 802CD03C: rlwinm. r0, r6, 26, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 26u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CD040:
    ctx->pc = 0x802CD040u;
    // 802CD040: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_802CD044:
    ctx->pc = 0x802CD044u;
    // 802CD044: bc    12, 2, 0x802CD050
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD050;
        }
    }

label_802CD048:
    ctx->pc = 0x802CD048u;
    ctx->downcount -= 2;
    // 802CD048: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CD04C:
    ctx->pc = 0x802CD04Cu;
    // 802CD04C: b       0x802CD054
    {
            goto label_802CD054;
    }

label_802CD050:
    ctx->pc = 0x802CD050u;
    ctx->downcount -= 1;
    // 802CD050: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CD054:
    ctx->pc = 0x802CD054u;
    ctx->downcount -= 3;
    // 802CD054: rlwinm. r0, r6, 24, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CD058:
    ctx->pc = 0x802CD058u;
    // 802CD058: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_802CD05C:
    ctx->pc = 0x802CD05Cu;
    // 802CD05C: bc    12, 2, 0x802CD068
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD068;
        }
    }

label_802CD060:
    ctx->pc = 0x802CD060u;
    ctx->downcount -= 2;
    // 802CD060: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CD064:
    ctx->pc = 0x802CD064u;
    // 802CD064: b       0x802CD06C
    {
            goto label_802CD06C;
    }

label_802CD068:
    ctx->pc = 0x802CD068u;
    ctx->downcount -= 1;
    // 802CD068: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CD06C:
    ctx->pc = 0x802CD06Cu;
    ctx->downcount -= 3;
    // 802CD06C: rlwinm. r0, r6, 22, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 22u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CD070:
    ctx->pc = 0x802CD070u;
    // 802CD070: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_802CD074:
    ctx->pc = 0x802CD074u;
    // 802CD074: bc    12, 2, 0x802CD080
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD080;
        }
    }

label_802CD078:
    ctx->pc = 0x802CD078u;
    ctx->downcount -= 2;
    // 802CD078: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CD07C:
    ctx->pc = 0x802CD07Cu;
    // 802CD07C: b       0x802CD084
    {
            goto label_802CD084;
    }

label_802CD080:
    ctx->pc = 0x802CD080u;
    ctx->downcount -= 1;
    // 802CD080: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CD084:
    ctx->pc = 0x802CD084u;
    ctx->downcount -= 3;
    // 802CD084: rlwinm. r0, r6, 20, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 20u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CD088:
    ctx->pc = 0x802CD088u;
    // 802CD088: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_802CD08C:
    ctx->pc = 0x802CD08Cu;
    // 802CD08C: bc    12, 2, 0x802CD098
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD098;
        }
    }

label_802CD090:
    ctx->pc = 0x802CD090u;
    ctx->downcount -= 2;
    // 802CD090: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CD094:
    ctx->pc = 0x802CD094u;
    // 802CD094: b       0x802CD09C
    {
            goto label_802CD09C;
    }

label_802CD098:
    ctx->pc = 0x802CD098u;
    ctx->downcount -= 1;
    // 802CD098: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802CD09C:
    ctx->pc = 0x802CD09Cu;
    ctx->downcount -= 3;
    // 802CD09C: rlwinm. r0, r6, 18, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CD0A0:
    ctx->pc = 0x802CD0A0u;
    // 802CD0A0: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_802CD0A4:
    ctx->pc = 0x802CD0A4u;
    // 802CD0A4: bc    12, 2, 0x802CD0B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD0B0;
        }
    }

label_802CD0A8:
    ctx->pc = 0x802CD0A8u;
    ctx->downcount -= 2;
    // 802CD0A8: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_802CD0AC:
    ctx->pc = 0x802CD0ACu;
    // 802CD0AC: b       0x802CD0B4
    {
            goto label_802CD0B4;
    }

label_802CD0B0:
    ctx->pc = 0x802CD0B0u;
    ctx->downcount -= 1;
    // 802CD0B0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_802CD0B4:
    ctx->pc = 0x802CD0B4u;
    ctx->downcount -= 15;
    // 802CD0B4: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_802CD0B8:
    ctx->pc = 0x802CD0B8u;
    // 802CD0B8: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD0BC:
    ctx->pc = 0x802CD0BCu;
    // 802CD0BC: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_802CD0C0:
    ctx->pc = 0x802CD0C0u;
    // 802CD0C0: add   r8, r8, r6
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_802CD0C4:
    ctx->pc = 0x802CD0C4u;
    // 802CD0C4: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CD0C8:
    ctx->pc = 0x802CD0C8u;
    // 802CD0C8: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_802CD0CC:
    ctx->pc = 0x802CD0CCu;
    // 802CD0CC: li      r4, 4104
    ctx->gpr[4] = (u32)(s32)(4104);

label_802CD0D0:
    ctx->pc = 0x802CD0D0u;
    // 802CD0D0: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CD0D4:
    ctx->pc = 0x802CD0D4u;
    // 802CD0D4: rlwinm r4, r8, 4, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[8], 4u) & 0xFFFFFFF0u;
    }

label_802CD0D8:
    ctx->pc = 0x802CD0D8u;
    // 802CD0D8: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_802CD0DC:
    ctx->pc = 0x802CD0DCu;
    // 802CD0DC: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CD0E0:
    ctx->pc = 0x802CD0E0u;
    // 802CD0E0: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD0E4:
    ctx->pc = 0x802CD0E4u;
    // 802CD0E4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802CD0E8:
    ctx->pc = 0x802CD0E8u;
    // 802CD0E8: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CD0EC:
    ctx->pc = 0x802CD0ECu;
    // 802CD0EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CD0F0:
    ctx->pc = 0x802CD0F0u;
    ctx->downcount -= 2;
    // 802CD0F0: cmplwi  r3, 0x0019
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0019u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CD0F4:
    ctx->pc = 0x802CD0F4u;
    // 802CD0F4: bc    12, 1, 0x802CD3E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD3E4;
        }
    }

label_802CD0F8:
    ctx->pc = 0x802CD0F8u;
    ctx->downcount -= 7;
    // 802CD0F8: lis     r5, -32715
    ctx->gpr[5] = ((u32)(s32)(-32715) << 16);

label_802CD0FC:
    ctx->pc = 0x802CD0FCu;
    // 802CD0FC: addi    r5, r5, 31680
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(31680);

label_802CD100:
    ctx->pc = 0x802CD100u;
    // 802CD100: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_802CD104:
    ctx->pc = 0x802CD104u;
    // 802CD104: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD108:
    ctx->pc = 0x802CD108u;
    // 802CD108: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802CD10C:
    ctx->pc = 0x802CD10Cu;
    // 802CD10C: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_802CD110:
    ctx->pc = 0x802CD110u;
    ctx->downcount -= 6;
    // 802CD110: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD114:
    ctx->pc = 0x802CD114u;
    // 802CD114: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_802CD118:
    ctx->pc = 0x802CD118u;
    // 802CD118: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_802CD11C:
    ctx->pc = 0x802CD11Cu;
    // 802CD11C: or   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[4];
    }

label_802CD120:
    ctx->pc = 0x802CD120u;
    // 802CD120: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD124:
    ctx->pc = 0x802CD124u;
    // 802CD124: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD128:
    ctx->pc = 0x802CD128u;
    ctx->downcount -= 8;
    // 802CD128: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD12C:
    ctx->pc = 0x802CD12Cu;
    // 802CD12C: rlwinm r0, r4, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0xFFFFFFFEu;
    }

label_802CD130:
    ctx->pc = 0x802CD130u;
    // 802CD130: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD134:
    ctx->pc = 0x802CD134u;
    // 802CD134: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD138:
    ctx->pc = 0x802CD138u;
    // 802CD138: rlwinm r3, r3, 0, 31, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFDu;
    }

label_802CD13C:
    ctx->pc = 0x802CD13Cu;
    // 802CD13C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD140:
    ctx->pc = 0x802CD140u;
    // 802CD140: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD144:
    ctx->pc = 0x802CD144u;
    // 802CD144: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD148:
    ctx->pc = 0x802CD148u;
    ctx->downcount -= 8;
    // 802CD148: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD14C:
    ctx->pc = 0x802CD14Cu;
    // 802CD14C: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_802CD150:
    ctx->pc = 0x802CD150u;
    // 802CD150: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD154:
    ctx->pc = 0x802CD154u;
    // 802CD154: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD158:
    ctx->pc = 0x802CD158u;
    // 802CD158: rlwinm r3, r3, 0, 30, 28
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFBu;
    }

label_802CD15C:
    ctx->pc = 0x802CD15Cu;
    // 802CD15C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD160:
    ctx->pc = 0x802CD160u;
    // 802CD160: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD164:
    ctx->pc = 0x802CD164u;
    // 802CD164: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD168:
    ctx->pc = 0x802CD168u;
    ctx->downcount -= 8;
    // 802CD168: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD16C:
    ctx->pc = 0x802CD16Cu;
    // 802CD16C: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

label_802CD170:
    ctx->pc = 0x802CD170u;
    // 802CD170: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD174:
    ctx->pc = 0x802CD174u;
    // 802CD174: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD178:
    ctx->pc = 0x802CD178u;
    // 802CD178: rlwinm r3, r3, 0, 29, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF7u;
    }

label_802CD17C:
    ctx->pc = 0x802CD17Cu;
    // 802CD17C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD180:
    ctx->pc = 0x802CD180u;
    // 802CD180: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD184:
    ctx->pc = 0x802CD184u;
    // 802CD184: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD188:
    ctx->pc = 0x802CD188u;
    ctx->downcount -= 8;
    // 802CD188: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD18C:
    ctx->pc = 0x802CD18Cu;
    // 802CD18C: rlwinm r0, r4, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 4u) & 0xFFFFFFF0u;
    }

label_802CD190:
    ctx->pc = 0x802CD190u;
    // 802CD190: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD194:
    ctx->pc = 0x802CD194u;
    // 802CD194: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD198:
    ctx->pc = 0x802CD198u;
    // 802CD198: rlwinm r3, r3, 0, 28, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFEFu;
    }

label_802CD19C:
    ctx->pc = 0x802CD19Cu;
    // 802CD19C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD1A0:
    ctx->pc = 0x802CD1A0u;
    // 802CD1A0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD1A4:
    ctx->pc = 0x802CD1A4u;
    // 802CD1A4: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD1A8:
    ctx->pc = 0x802CD1A8u;
    ctx->downcount -= 8;
    // 802CD1A8: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD1AC:
    ctx->pc = 0x802CD1ACu;
    // 802CD1AC: rlwinm r0, r4, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 5u) & 0xFFFFFFE0u;
    }

label_802CD1B0:
    ctx->pc = 0x802CD1B0u;
    // 802CD1B0: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD1B4:
    ctx->pc = 0x802CD1B4u;
    // 802CD1B4: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD1B8:
    ctx->pc = 0x802CD1B8u;
    // 802CD1B8: rlwinm r3, r3, 0, 27, 25
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFDFu;
    }

label_802CD1BC:
    ctx->pc = 0x802CD1BCu;
    // 802CD1BC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD1C0:
    ctx->pc = 0x802CD1C0u;
    // 802CD1C0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD1C4:
    ctx->pc = 0x802CD1C4u;
    // 802CD1C4: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD1C8:
    ctx->pc = 0x802CD1C8u;
    ctx->downcount -= 8;
    // 802CD1C8: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD1CC:
    ctx->pc = 0x802CD1CCu;
    // 802CD1CC: rlwinm r0, r4, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 6u) & 0xFFFFFFC0u;
    }

label_802CD1D0:
    ctx->pc = 0x802CD1D0u;
    // 802CD1D0: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD1D4:
    ctx->pc = 0x802CD1D4u;
    // 802CD1D4: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD1D8:
    ctx->pc = 0x802CD1D8u;
    // 802CD1D8: rlwinm r3, r3, 0, 26, 24
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFBFu;
    }

label_802CD1DC:
    ctx->pc = 0x802CD1DCu;
    // 802CD1DC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD1E0:
    ctx->pc = 0x802CD1E0u;
    // 802CD1E0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD1E4:
    ctx->pc = 0x802CD1E4u;
    // 802CD1E4: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD1E8:
    ctx->pc = 0x802CD1E8u;
    ctx->downcount -= 8;
    // 802CD1E8: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD1EC:
    ctx->pc = 0x802CD1ECu;
    // 802CD1EC: rlwinm r0, r4, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 7u) & 0xFFFFFF80u;
    }

label_802CD1F0:
    ctx->pc = 0x802CD1F0u;
    // 802CD1F0: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD1F4:
    ctx->pc = 0x802CD1F4u;
    // 802CD1F4: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD1F8:
    ctx->pc = 0x802CD1F8u;
    // 802CD1F8: rlwinm r3, r3, 0, 25, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFF7Fu;
    }

label_802CD1FC:
    ctx->pc = 0x802CD1FCu;
    // 802CD1FC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD200:
    ctx->pc = 0x802CD200u;
    // 802CD200: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD204:
    ctx->pc = 0x802CD204u;
    // 802CD204: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD208:
    ctx->pc = 0x802CD208u;
    ctx->downcount -= 8;
    // 802CD208: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD20C:
    ctx->pc = 0x802CD20Cu;
    // 802CD20C: rlwinm r0, r4, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_802CD210:
    ctx->pc = 0x802CD210u;
    // 802CD210: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD214:
    ctx->pc = 0x802CD214u;
    // 802CD214: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD218:
    ctx->pc = 0x802CD218u;
    // 802CD218: rlwinm r3, r3, 0, 24, 22
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFEFFu;
    }

label_802CD21C:
    ctx->pc = 0x802CD21Cu;
    // 802CD21C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD220:
    ctx->pc = 0x802CD220u;
    // 802CD220: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD224:
    ctx->pc = 0x802CD224u;
    // 802CD224: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD228:
    ctx->pc = 0x802CD228u;
    ctx->downcount -= 8;
    // 802CD228: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD22C:
    ctx->pc = 0x802CD22Cu;
    // 802CD22C: rlwinm r0, r4, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 9u) & 0xFFFFFE00u;
    }

label_802CD230:
    ctx->pc = 0x802CD230u;
    // 802CD230: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD234:
    ctx->pc = 0x802CD234u;
    // 802CD234: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD238:
    ctx->pc = 0x802CD238u;
    // 802CD238: rlwinm r3, r3, 0, 23, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFF9FFu;
    }

label_802CD23C:
    ctx->pc = 0x802CD23Cu;
    // 802CD23C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD240:
    ctx->pc = 0x802CD240u;
    // 802CD240: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD244:
    ctx->pc = 0x802CD244u;
    // 802CD244: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD248:
    ctx->pc = 0x802CD248u;
    ctx->downcount -= 2;
    // 802CD248: cmpwi   r4, 0
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

label_802CD24C:
    ctx->pc = 0x802CD24Cu;
    // 802CD24C: bc    12, 2, 0x802CD26C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD26C;
        }
    }

label_802CD250:
    ctx->pc = 0x802CD250u;
    ctx->downcount -= 7;
    // 802CD250: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD254:
    ctx->pc = 0x802CD254u;
    // 802CD254: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802CD258:
    ctx->pc = 0x802CD258u;
    // 802CD258: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CD25C:
    ctx->pc = 0x802CD25Cu;
    // 802CD25C: stb     r5, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_802CD260:
    ctx->pc = 0x802CD260u;
    // 802CD260: stb     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CD264:
    ctx->pc = 0x802CD264u;
    // 802CD264: stw     r4, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CD268:
    ctx->pc = 0x802CD268u;
    // 802CD268: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD26C:
    ctx->pc = 0x802CD26Cu;
    ctx->downcount -= 4;
    // 802CD26C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD270:
    ctx->pc = 0x802CD270u;
    // 802CD270: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CD274:
    ctx->pc = 0x802CD274u;
    // 802CD274: stb     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CD278:
    ctx->pc = 0x802CD278u;
    // 802CD278: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD27C:
    ctx->pc = 0x802CD27Cu;
    ctx->downcount -= 2;
    // 802CD27C: cmpwi   r4, 0
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

label_802CD280:
    ctx->pc = 0x802CD280u;
    // 802CD280: bc    12, 2, 0x802CD2A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD2A0;
        }
    }

label_802CD284:
    ctx->pc = 0x802CD284u;
    ctx->downcount -= 7;
    // 802CD284: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD288:
    ctx->pc = 0x802CD288u;
    // 802CD288: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802CD28C:
    ctx->pc = 0x802CD28Cu;
    // 802CD28C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CD290:
    ctx->pc = 0x802CD290u;
    // 802CD290: stb     r5, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_802CD294:
    ctx->pc = 0x802CD294u;
    // 802CD294: stb     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CD298:
    ctx->pc = 0x802CD298u;
    // 802CD298: stw     r4, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CD29C:
    ctx->pc = 0x802CD29Cu;
    // 802CD29C: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD2A0:
    ctx->pc = 0x802CD2A0u;
    ctx->downcount -= 4;
    // 802CD2A0: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD2A4:
    ctx->pc = 0x802CD2A4u;
    // 802CD2A4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CD2A8:
    ctx->pc = 0x802CD2A8u;
    // 802CD2A8: stb     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CD2AC:
    ctx->pc = 0x802CD2ACu;
    // 802CD2AC: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD2B0:
    ctx->pc = 0x802CD2B0u;
    ctx->downcount -= 8;
    // 802CD2B0: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD2B4:
    ctx->pc = 0x802CD2B4u;
    // 802CD2B4: rlwinm r0, r4, 13, 0, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 13u) & 0xFFFFE000u;
    }

label_802CD2B8:
    ctx->pc = 0x802CD2B8u;
    // 802CD2B8: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD2BC:
    ctx->pc = 0x802CD2BCu;
    // 802CD2BC: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD2C0:
    ctx->pc = 0x802CD2C0u;
    // 802CD2C0: rlwinm r3, r3, 0, 19, 16
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFF9FFFu;
    }

label_802CD2C4:
    ctx->pc = 0x802CD2C4u;
    // 802CD2C4: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD2C8:
    ctx->pc = 0x802CD2C8u;
    // 802CD2C8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD2CC:
    ctx->pc = 0x802CD2CCu;
    // 802CD2CC: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD2D0:
    ctx->pc = 0x802CD2D0u;
    ctx->downcount -= 8;
    // 802CD2D0: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD2D4:
    ctx->pc = 0x802CD2D4u;
    // 802CD2D4: rlwinm r0, r4, 15, 0, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 15u) & 0xFFFF8000u;
    }

label_802CD2D8:
    ctx->pc = 0x802CD2D8u;
    // 802CD2D8: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD2DC:
    ctx->pc = 0x802CD2DCu;
    // 802CD2DC: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD2E0:
    ctx->pc = 0x802CD2E0u;
    // 802CD2E0: rlwinm r3, r3, 0, 17, 14
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFE7FFFu;
    }

label_802CD2E4:
    ctx->pc = 0x802CD2E4u;
    // 802CD2E4: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD2E8:
    ctx->pc = 0x802CD2E8u;
    // 802CD2E8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD2EC:
    ctx->pc = 0x802CD2ECu;
    // 802CD2EC: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD2F0:
    ctx->pc = 0x802CD2F0u;
    ctx->downcount -= 6;
    // 802CD2F0: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD2F4:
    ctx->pc = 0x802CD2F4u;
    // 802CD2F4: lwzu     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_802CD2F8:
    ctx->pc = 0x802CD2F8u;
    // 802CD2F8: rlwinm r0, r0, 0, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_802CD2FC:
    ctx->pc = 0x802CD2FCu;
    // 802CD2FC: or   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[4];
    }

label_802CD300:
    ctx->pc = 0x802CD300u;
    // 802CD300: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD304:
    ctx->pc = 0x802CD304u;
    // 802CD304: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD308:
    ctx->pc = 0x802CD308u;
    ctx->downcount -= 8;
    // 802CD308: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD30C:
    ctx->pc = 0x802CD30Cu;
    // 802CD30C: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_802CD310:
    ctx->pc = 0x802CD310u;
    // 802CD310: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_802CD314:
    ctx->pc = 0x802CD314u;
    // 802CD314: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD318:
    ctx->pc = 0x802CD318u;
    // 802CD318: rlwinm r3, r3, 0, 30, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF3u;
    }

label_802CD31C:
    ctx->pc = 0x802CD31Cu;
    // 802CD31C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD320:
    ctx->pc = 0x802CD320u;
    // 802CD320: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD324:
    ctx->pc = 0x802CD324u;
    // 802CD324: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD328:
    ctx->pc = 0x802CD328u;
    ctx->downcount -= 8;
    // 802CD328: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD32C:
    ctx->pc = 0x802CD32Cu;
    // 802CD32C: rlwinm r0, r4, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 4u) & 0xFFFFFFF0u;
    }

label_802CD330:
    ctx->pc = 0x802CD330u;
    // 802CD330: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_802CD334:
    ctx->pc = 0x802CD334u;
    // 802CD334: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD338:
    ctx->pc = 0x802CD338u;
    // 802CD338: rlwinm r3, r3, 0, 28, 25
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFCFu;
    }

label_802CD33C:
    ctx->pc = 0x802CD33Cu;
    // 802CD33C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD340:
    ctx->pc = 0x802CD340u;
    // 802CD340: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD344:
    ctx->pc = 0x802CD344u;
    // 802CD344: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD348:
    ctx->pc = 0x802CD348u;
    ctx->downcount -= 8;
    // 802CD348: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD34C:
    ctx->pc = 0x802CD34Cu;
    // 802CD34C: rlwinm r0, r4, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 6u) & 0xFFFFFFC0u;
    }

label_802CD350:
    ctx->pc = 0x802CD350u;
    // 802CD350: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_802CD354:
    ctx->pc = 0x802CD354u;
    // 802CD354: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD358:
    ctx->pc = 0x802CD358u;
    // 802CD358: rlwinm r3, r3, 0, 26, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFF3Fu;
    }

label_802CD35C:
    ctx->pc = 0x802CD35Cu;
    // 802CD35C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD360:
    ctx->pc = 0x802CD360u;
    // 802CD360: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD364:
    ctx->pc = 0x802CD364u;
    // 802CD364: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD368:
    ctx->pc = 0x802CD368u;
    ctx->downcount -= 8;
    // 802CD368: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD36C:
    ctx->pc = 0x802CD36Cu;
    // 802CD36C: rlwinm r0, r4, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_802CD370:
    ctx->pc = 0x802CD370u;
    // 802CD370: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_802CD374:
    ctx->pc = 0x802CD374u;
    // 802CD374: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD378:
    ctx->pc = 0x802CD378u;
    // 802CD378: rlwinm r3, r3, 0, 24, 21
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFCFFu;
    }

label_802CD37C:
    ctx->pc = 0x802CD37Cu;
    // 802CD37C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD380:
    ctx->pc = 0x802CD380u;
    // 802CD380: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD384:
    ctx->pc = 0x802CD384u;
    // 802CD384: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD388:
    ctx->pc = 0x802CD388u;
    ctx->downcount -= 8;
    // 802CD388: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD38C:
    ctx->pc = 0x802CD38Cu;
    // 802CD38C: rlwinm r0, r4, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 10u) & 0xFFFFFC00u;
    }

label_802CD390:
    ctx->pc = 0x802CD390u;
    // 802CD390: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_802CD394:
    ctx->pc = 0x802CD394u;
    // 802CD394: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD398:
    ctx->pc = 0x802CD398u;
    // 802CD398: rlwinm r3, r3, 0, 22, 19
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFF3FFu;
    }

label_802CD39C:
    ctx->pc = 0x802CD39Cu;
    // 802CD39C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD3A0:
    ctx->pc = 0x802CD3A0u;
    // 802CD3A0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD3A4:
    ctx->pc = 0x802CD3A4u;
    // 802CD3A4: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD3A8:
    ctx->pc = 0x802CD3A8u;
    ctx->downcount -= 8;
    // 802CD3A8: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD3AC:
    ctx->pc = 0x802CD3ACu;
    // 802CD3AC: rlwinm r0, r4, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0xFFFFF000u;
    }

label_802CD3B0:
    ctx->pc = 0x802CD3B0u;
    // 802CD3B0: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_802CD3B4:
    ctx->pc = 0x802CD3B4u;
    // 802CD3B4: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD3B8:
    ctx->pc = 0x802CD3B8u;
    // 802CD3B8: rlwinm r3, r3, 0, 20, 17
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFCFFFu;
    }

label_802CD3BC:
    ctx->pc = 0x802CD3BCu;
    // 802CD3BC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD3C0:
    ctx->pc = 0x802CD3C0u;
    // 802CD3C0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD3C4:
    ctx->pc = 0x802CD3C4u;
    // 802CD3C4: b       0x802CD3E4
    {
            goto label_802CD3E4;
    }

label_802CD3C8:
    ctx->pc = 0x802CD3C8u;
    ctx->downcount -= 7;
    // 802CD3C8: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD3CC:
    ctx->pc = 0x802CD3CCu;
    // 802CD3CC: rlwinm r0, r4, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 14u) & 0xFFFFC000u;
    }

label_802CD3D0:
    ctx->pc = 0x802CD3D0u;
    // 802CD3D0: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_802CD3D4:
    ctx->pc = 0x802CD3D4u;
    // 802CD3D4: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD3D8:
    ctx->pc = 0x802CD3D8u;
    // 802CD3D8: rlwinm r3, r3, 0, 18, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFF3FFFu;
    }

label_802CD3DC:
    ctx->pc = 0x802CD3DCu;
    // 802CD3DC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD3E0:
    ctx->pc = 0x802CD3E0u;
    // 802CD3E0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD3E4:
    ctx->pc = 0x802CD3E4u;
    ctx->downcount -= 4;
    // 802CD3E4: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD3E8:
    ctx->pc = 0x802CD3E8u;
    // 802CD3E8: lbz     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CD3EC:
    ctx->pc = 0x802CD3ECu;
    // 802CD3EC: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CD3F0:
    ctx->pc = 0x802CD3F0u;
    // 802CD3F0: bc    4, 2, 0x802CD400
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CD400;
        }
    }

label_802CD3F4:
    ctx->pc = 0x802CD3F4u;
    ctx->downcount -= 3;
    // 802CD3F4: lbz     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CD3F8:
    ctx->pc = 0x802CD3F8u;
    // 802CD3F8: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CD3FC:
    ctx->pc = 0x802CD3FCu;
    // 802CD3FC: bc    12, 2, 0x802CD420
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD420;
        }
    }

label_802CD400:
    ctx->pc = 0x802CD400u;
    ctx->downcount -= 8;
    // 802CD400: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD404:
    ctx->pc = 0x802CD404u;
    // 802CD404: lwz     r0, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD408:
    ctx->pc = 0x802CD408u;
    // 802CD408: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD40C:
    ctx->pc = 0x802CD40Cu;
    // 802CD40C: rlwinm r0, r0, 11, 0, 20
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 11u) & 0xFFFFF800u;
    }

label_802CD410:
    ctx->pc = 0x802CD410u;
    // 802CD410: rlwinm r3, r3, 0, 21, 18
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFE7FFu;
    }

label_802CD414:
    ctx->pc = 0x802CD414u;
    // 802CD414: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD418:
    ctx->pc = 0x802CD418u;
    // 802CD418: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD41C:
    ctx->pc = 0x802CD41Cu;
    // 802CD41C: b       0x802CD42C
    {
            goto label_802CD42C;
    }

label_802CD420:
    ctx->pc = 0x802CD420u;
    ctx->downcount -= 3;
    // 802CD420: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_802CD424:
    ctx->pc = 0x802CD424u;
    // 802CD424: rlwinm r0, r0, 0, 21, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFE7FFu;
    }

label_802CD428:
    ctx->pc = 0x802CD428u;
    // 802CD428: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD42C:
    ctx->pc = 0x802CD42Cu;
    ctx->downcount -= 5;
    // 802CD42C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD430:
    ctx->pc = 0x802CD430u;
    // 802CD430: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD434:
    ctx->pc = 0x802CD434u;
    // 802CD434: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_802CD438:
    ctx->pc = 0x802CD438u;
    // 802CD438: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD43C:
    ctx->pc = 0x802CD43Cu;
    // 802CD43C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CD440:
    ctx->pc = 0x802CD440u;
    ctx->downcount -= 3;
    // 802CD440: lis     r4, -32715
    ctx->gpr[4] = ((u32)(s32)(-32715) << 16);

label_802CD444:
    ctx->pc = 0x802CD444u;
    // 802CD444: addi    r4, r4, 31784
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(31784);

label_802CD448:
    ctx->pc = 0x802CD448u;
    // 802CD448: b       0x802CD74C
    {
            goto label_802CD74C;
    }

label_802CD44C:
    ctx->pc = 0x802CD44Cu;
    ctx->downcount -= 4;
    // 802CD44C: lwz     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD450:
    ctx->pc = 0x802CD450u;
    // 802CD450: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD454:
    // 802CD454: cmplwi  r5, 0x0019
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0019u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CD458:
    // 802CD458: bc    12, 1, 0x802CD748
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD748;
        }
    }

label_802CD45C:
    ctx->downcount -= 5;
    // 802CD45C: rlwinm r5, r5, 2, 0, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 2u) & 0xFFFFFFFCu;
    }

label_802CD460:
    ctx->pc = 0x802CD460u;
    // 802CD460: lwzx    r5, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD464:
    ctx->pc = 0x802CD464u;
    // 802CD464: mtctr    r5
    ctx->ctr = ctx->gpr[5];

label_802CD468:
    ctx->pc = 0x802CD468u;
    // 802CD468: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_802CD46C:
    ctx->pc = 0x802CD46Cu;
    ctx->downcount -= 7;
    // 802CD46C: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD470:
    // 802CD470: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD474:
    ctx->pc = 0x802CD474u;
    // 802CD474: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD478:
    // 802CD478: rlwinm r5, r5, 0, 0, 30
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFEu;
    }

label_802CD47C:
    // 802CD47C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD480:
    ctx->pc = 0x802CD480u;
    // 802CD480: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD484:
    // 802CD484: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD488:
    ctx->pc = 0x802CD488u;
    ctx->downcount -= 8;
    // 802CD488: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD48C:
    // 802CD48C: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_802CD490:
    // 802CD490: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD494:
    ctx->pc = 0x802CD494u;
    // 802CD494: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD498:
    // 802CD498: rlwinm r5, r5, 0, 31, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFDu;
    }

label_802CD49C:
    // 802CD49C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD4A0:
    ctx->pc = 0x802CD4A0u;
    // 802CD4A0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD4A4:
    // 802CD4A4: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD4A8:
    ctx->pc = 0x802CD4A8u;
    ctx->downcount -= 8;
    // 802CD4A8: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD4AC:
    // 802CD4AC: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_802CD4B0:
    // 802CD4B0: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD4B4:
    ctx->pc = 0x802CD4B4u;
    // 802CD4B4: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD4B8:
    // 802CD4B8: rlwinm r5, r5, 0, 30, 28
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFBu;
    }

label_802CD4BC:
    // 802CD4BC: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD4C0:
    ctx->pc = 0x802CD4C0u;
    // 802CD4C0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD4C4:
    // 802CD4C4: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD4C8:
    ctx->pc = 0x802CD4C8u;
    ctx->downcount -= 8;
    // 802CD4C8: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD4CC:
    // 802CD4CC: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_802CD4D0:
    // 802CD4D0: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD4D4:
    ctx->pc = 0x802CD4D4u;
    // 802CD4D4: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD4D8:
    // 802CD4D8: rlwinm r5, r5, 0, 29, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF7u;
    }

label_802CD4DC:
    // 802CD4DC: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD4E0:
    ctx->pc = 0x802CD4E0u;
    // 802CD4E0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD4E4:
    // 802CD4E4: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD4E8:
    ctx->pc = 0x802CD4E8u;
    ctx->downcount -= 8;
    // 802CD4E8: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD4EC:
    // 802CD4EC: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_802CD4F0:
    // 802CD4F0: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD4F4:
    ctx->pc = 0x802CD4F4u;
    // 802CD4F4: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD4F8:
    // 802CD4F8: rlwinm r5, r5, 0, 28, 26
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFEFu;
    }

label_802CD4FC:
    // 802CD4FC: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD500:
    ctx->pc = 0x802CD500u;
    // 802CD500: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD504:
    // 802CD504: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD508:
    ctx->pc = 0x802CD508u;
    ctx->downcount -= 8;
    // 802CD508: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD50C:
    // 802CD50C: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_802CD510:
    // 802CD510: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD514:
    ctx->pc = 0x802CD514u;
    // 802CD514: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD518:
    // 802CD518: rlwinm r5, r5, 0, 27, 25
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFDFu;
    }

label_802CD51C:
    // 802CD51C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD520:
    ctx->pc = 0x802CD520u;
    // 802CD520: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD524:
    // 802CD524: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD528:
    ctx->pc = 0x802CD528u;
    ctx->downcount -= 8;
    // 802CD528: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD52C:
    // 802CD52C: rlwinm r0, r0, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 6u) & 0xFFFFFFC0u;
    }

label_802CD530:
    // 802CD530: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD534:
    ctx->pc = 0x802CD534u;
    // 802CD534: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD538:
    // 802CD538: rlwinm r5, r5, 0, 26, 24
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFBFu;
    }

label_802CD53C:
    // 802CD53C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD540:
    ctx->pc = 0x802CD540u;
    // 802CD540: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD544:
    // 802CD544: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD548:
    ctx->pc = 0x802CD548u;
    ctx->downcount -= 8;
    // 802CD548: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD54C:
    // 802CD54C: rlwinm r0, r0, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 7u) & 0xFFFFFF80u;
    }

label_802CD550:
    // 802CD550: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD554:
    ctx->pc = 0x802CD554u;
    // 802CD554: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD558:
    // 802CD558: rlwinm r5, r5, 0, 25, 23
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFF7Fu;
    }

label_802CD55C:
    // 802CD55C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD560:
    ctx->pc = 0x802CD560u;
    // 802CD560: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD564:
    // 802CD564: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD568:
    ctx->pc = 0x802CD568u;
    ctx->downcount -= 8;
    // 802CD568: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD56C:
    // 802CD56C: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_802CD570:
    // 802CD570: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD574:
    ctx->pc = 0x802CD574u;
    // 802CD574: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD578:
    // 802CD578: rlwinm r5, r5, 0, 24, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFEFFu;
    }

label_802CD57C:
    // 802CD57C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD580:
    ctx->pc = 0x802CD580u;
    // 802CD580: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD584:
    // 802CD584: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD588:
    ctx->pc = 0x802CD588u;
    ctx->downcount -= 8;
    // 802CD588: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD58C:
    // 802CD58C: rlwinm r0, r0, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0xFFFFFE00u;
    }

label_802CD590:
    // 802CD590: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD594:
    ctx->pc = 0x802CD594u;
    // 802CD594: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD598:
    // 802CD598: rlwinm r5, r5, 0, 23, 20
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFF9FFu;
    }

label_802CD59C:
    // 802CD59C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD5A0:
    ctx->pc = 0x802CD5A0u;
    // 802CD5A0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD5A4:
    // 802CD5A4: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD5A8:
    ctx->downcount -= 2;
    // 802CD5A8: cmpwi   r0, 0
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

label_802CD5AC:
    // 802CD5AC: bc    12, 2, 0x802CD5CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD5CC;
        }
    }

label_802CD5B0:
    ctx->pc = 0x802CD5B0u;
    ctx->downcount -= 7;
    // 802CD5B0: lwz     r6, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CD5B4:
    // 802CD5B4: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_802CD5B8:
    // 802CD5B8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CD5BC:
    ctx->pc = 0x802CD5BCu;
    // 802CD5BC: stb     r7, 1052(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[7]);
    }

label_802CD5C0:
    ctx->pc = 0x802CD5C0u;
    // 802CD5C0: stb     r5, 1053(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_802CD5C4:
    ctx->pc = 0x802CD5C4u;
    // 802CD5C4: stw     r0, 1048(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD5C8:
    // 802CD5C8: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD5CC:
    ctx->pc = 0x802CD5CCu;
    ctx->downcount -= 4;
    // 802CD5CC: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD5D0:
    // 802CD5D0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CD5D4:
    ctx->pc = 0x802CD5D4u;
    // 802CD5D4: stb     r0, 1052(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CD5D8:
    // 802CD5D8: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD5DC:
    ctx->downcount -= 2;
    // 802CD5DC: cmpwi   r0, 0
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

label_802CD5E0:
    // 802CD5E0: bc    12, 2, 0x802CD600
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD600;
        }
    }

label_802CD5E4:
    ctx->pc = 0x802CD5E4u;
    ctx->downcount -= 7;
    // 802CD5E4: lwz     r6, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CD5E8:
    // 802CD5E8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_802CD5EC:
    // 802CD5EC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802CD5F0:
    ctx->pc = 0x802CD5F0u;
    // 802CD5F0: stb     r7, 1053(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[7]);
    }

label_802CD5F4:
    ctx->pc = 0x802CD5F4u;
    // 802CD5F4: stb     r5, 1052(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_802CD5F8:
    ctx->pc = 0x802CD5F8u;
    // 802CD5F8: stw     r0, 1048(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD5FC:
    // 802CD5FC: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD600:
    ctx->pc = 0x802CD600u;
    ctx->downcount -= 4;
    // 802CD600: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD604:
    // 802CD604: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CD608:
    ctx->pc = 0x802CD608u;
    // 802CD608: stb     r0, 1053(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CD60C:
    // 802CD60C: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD610:
    ctx->pc = 0x802CD610u;
    ctx->downcount -= 8;
    // 802CD610: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD614:
    // 802CD614: rlwinm r0, r0, 13, 0, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 13u) & 0xFFFFE000u;
    }

label_802CD618:
    // 802CD618: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD61C:
    ctx->pc = 0x802CD61Cu;
    // 802CD61C: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD620:
    // 802CD620: rlwinm r5, r5, 0, 19, 16
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFF9FFFu;
    }

label_802CD624:
    // 802CD624: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD628:
    ctx->pc = 0x802CD628u;
    // 802CD628: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD62C:
    // 802CD62C: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD630:
    ctx->pc = 0x802CD630u;
    ctx->downcount -= 8;
    // 802CD630: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD634:
    // 802CD634: rlwinm r0, r0, 15, 0, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 15u) & 0xFFFF8000u;
    }

label_802CD638:
    // 802CD638: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802CD63C:
    ctx->pc = 0x802CD63Cu;
    // 802CD63C: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD640:
    // 802CD640: rlwinm r5, r5, 0, 17, 14
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFE7FFFu;
    }

label_802CD644:
    // 802CD644: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD648:
    ctx->pc = 0x802CD648u;
    // 802CD648: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD64C:
    // 802CD64C: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD650:
    ctx->pc = 0x802CD650u;
    ctx->downcount -= 7;
    // 802CD650: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD654:
    // 802CD654: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_802CD658:
    ctx->pc = 0x802CD658u;
    // 802CD658: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD65C:
    // 802CD65C: rlwinm r5, r5, 0, 0, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFCu;
    }

label_802CD660:
    // 802CD660: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD664:
    ctx->pc = 0x802CD664u;
    // 802CD664: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD668:
    // 802CD668: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD66C:
    ctx->pc = 0x802CD66Cu;
    ctx->downcount -= 8;
    // 802CD66C: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD670:
    // 802CD670: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_802CD674:
    // 802CD674: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_802CD678:
    ctx->pc = 0x802CD678u;
    // 802CD678: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD67C:
    // 802CD67C: rlwinm r5, r5, 0, 30, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF3u;
    }

label_802CD680:
    // 802CD680: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD684:
    ctx->pc = 0x802CD684u;
    // 802CD684: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD688:
    // 802CD688: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD68C:
    ctx->pc = 0x802CD68Cu;
    ctx->downcount -= 8;
    // 802CD68C: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD690:
    // 802CD690: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_802CD694:
    // 802CD694: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_802CD698:
    ctx->pc = 0x802CD698u;
    // 802CD698: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD69C:
    // 802CD69C: rlwinm r5, r5, 0, 28, 25
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFCFu;
    }

label_802CD6A0:
    // 802CD6A0: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD6A4:
    ctx->pc = 0x802CD6A4u;
    // 802CD6A4: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD6A8:
    // 802CD6A8: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD6AC:
    ctx->pc = 0x802CD6ACu;
    ctx->downcount -= 8;
    // 802CD6AC: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD6B0:
    // 802CD6B0: rlwinm r0, r0, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 6u) & 0xFFFFFFC0u;
    }

label_802CD6B4:
    // 802CD6B4: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_802CD6B8:
    ctx->pc = 0x802CD6B8u;
    // 802CD6B8: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD6BC:
    // 802CD6BC: rlwinm r5, r5, 0, 26, 23
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFF3Fu;
    }

label_802CD6C0:
    // 802CD6C0: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD6C4:
    ctx->pc = 0x802CD6C4u;
    // 802CD6C4: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD6C8:
    // 802CD6C8: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD6CC:
    ctx->pc = 0x802CD6CCu;
    ctx->downcount -= 8;
    // 802CD6CC: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD6D0:
    // 802CD6D0: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_802CD6D4:
    // 802CD6D4: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_802CD6D8:
    ctx->pc = 0x802CD6D8u;
    // 802CD6D8: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD6DC:
    // 802CD6DC: rlwinm r5, r5, 0, 24, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFCFFu;
    }

label_802CD6E0:
    // 802CD6E0: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD6E4:
    ctx->pc = 0x802CD6E4u;
    // 802CD6E4: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD6E8:
    // 802CD6E8: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD6EC:
    ctx->pc = 0x802CD6ECu;
    ctx->downcount -= 8;
    // 802CD6EC: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD6F0:
    // 802CD6F0: rlwinm r0, r0, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0xFFFFFC00u;
    }

label_802CD6F4:
    // 802CD6F4: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_802CD6F8:
    ctx->pc = 0x802CD6F8u;
    // 802CD6F8: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD6FC:
    // 802CD6FC: rlwinm r5, r5, 0, 22, 19
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFF3FFu;
    }

label_802CD700:
    // 802CD700: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD704:
    ctx->pc = 0x802CD704u;
    // 802CD704: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD708:
    // 802CD708: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD70C:
    ctx->pc = 0x802CD70Cu;
    ctx->downcount -= 8;
    // 802CD70C: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD710:
    // 802CD710: rlwinm r0, r0, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 12u) & 0xFFFFF000u;
    }

label_802CD714:
    // 802CD714: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_802CD718:
    ctx->pc = 0x802CD718u;
    // 802CD718: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD71C:
    // 802CD71C: rlwinm r5, r5, 0, 20, 17
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFCFFFu;
    }

label_802CD720:
    // 802CD720: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD724:
    ctx->pc = 0x802CD724u;
    // 802CD724: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD728:
    // 802CD728: b       0x802CD748
    {
            goto label_802CD748;
    }

label_802CD72C:
    ctx->pc = 0x802CD72Cu;
    ctx->downcount -= 7;
    // 802CD72C: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD730:
    // 802CD730: rlwinm r0, r0, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0xFFFFC000u;
    }

label_802CD734:
    // 802CD734: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_802CD738:
    ctx->pc = 0x802CD738u;
    // 802CD738: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CD73C:
    // 802CD73C: rlwinm r5, r5, 0, 18, 15
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFF3FFFu;
    }

label_802CD740:
    // 802CD740: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CD744:
    ctx->pc = 0x802CD744u;
    // 802CD744: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD748:
    ctx->downcount -= 1;
    // 802CD748: addi    r3, r3, 8
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8);

label_802CD74C:
    ctx->pc = 0x802CD74Cu;
    ctx->downcount -= 3;
    // 802CD74C: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD750:
    // 802CD750: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CD754:
    // 802CD754: bc    4, 2, 0x802CD44C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CD44Cu;
                return;
            }
            goto label_802CD44C;
        }
    }

label_802CD758:
    ctx->pc = 0x802CD758u;
    ctx->downcount -= 4;
    // 802CD758: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD75C:
    ctx->pc = 0x802CD75Cu;
    // 802CD75C: lbz     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CD760:
    ctx->pc = 0x802CD760u;
    // 802CD760: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CD764:
    ctx->pc = 0x802CD764u;
    // 802CD764: bc    4, 2, 0x802CD774
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CD774;
        }
    }

label_802CD768:
    ctx->pc = 0x802CD768u;
    ctx->downcount -= 3;
    // 802CD768: lbz     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CD76C:
    ctx->pc = 0x802CD76Cu;
    // 802CD76C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CD770:
    ctx->pc = 0x802CD770u;
    // 802CD770: bc    12, 2, 0x802CD794
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CD794;
        }
    }

label_802CD774:
    ctx->pc = 0x802CD774u;
    ctx->downcount -= 8;
    // 802CD774: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802CD778:
    ctx->pc = 0x802CD778u;
    // 802CD778: lwz     r0, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD77C:
    ctx->pc = 0x802CD77Cu;
    // 802CD77C: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD780:
    ctx->pc = 0x802CD780u;
    // 802CD780: rlwinm r0, r0, 11, 0, 20
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 11u) & 0xFFFFF800u;
    }

label_802CD784:
    ctx->pc = 0x802CD784u;
    // 802CD784: rlwinm r3, r3, 0, 21, 18
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFE7FFu;
    }

label_802CD788:
    ctx->pc = 0x802CD788u;
    // 802CD788: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CD78C:
    ctx->pc = 0x802CD78Cu;
    // 802CD78C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD790:
    ctx->pc = 0x802CD790u;
    // 802CD790: b       0x802CD7A0
    {
            goto label_802CD7A0;
    }

label_802CD794:
    ctx->pc = 0x802CD794u;
    ctx->downcount -= 3;
    // 802CD794: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_802CD798:
    ctx->pc = 0x802CD798u;
    // 802CD798: rlwinm r0, r0, 0, 21, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFE7FFu;
    }

label_802CD79C:
    ctx->pc = 0x802CD79Cu;
    // 802CD79C: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD7A0:
    ctx->pc = 0x802CD7A0u;
    ctx->downcount -= 5;
    // 802CD7A0: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD7A4:
    ctx->pc = 0x802CD7A4u;
    // 802CD7A4: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD7A8:
    ctx->pc = 0x802CD7A8u;
    // 802CD7A8: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_802CD7AC:
    ctx->pc = 0x802CD7ACu;
    // 802CD7AC: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD7B0:
    ctx->pc = 0x802CD7B0u;
    // 802CD7B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CD7B4:
    ctx->pc = 0x802CD7B4u;
    ctx->downcount -= 17;
    // 802CD7B4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CD7B8:
    ctx->pc = 0x802CD7B8u;
    // 802CD7B8: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_802CD7BC:
    ctx->pc = 0x802CD7BCu;
    // 802CD7BC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD7C0:
    ctx->pc = 0x802CD7C0u;
    // 802CD7C0: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_802CD7C4:
    ctx->pc = 0x802CD7C4u;
    // 802CD7C4: li      r3, 80
    ctx->gpr[3] = (u32)(s32)(80);

label_802CD7C8:
    ctx->pc = 0x802CD7C8u;
    // 802CD7C8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CD7CC:
    ctx->pc = 0x802CD7CCu;
    // 802CD7CC: li      r0, 96
    ctx->gpr[0] = (u32)(s32)(96);

label_802CD7D0:
    ctx->pc = 0x802CD7D0u;
    // 802CD7D0: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_802CD7D4:
    ctx->pc = 0x802CD7D4u;
    // 802CD7D4: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CD7D8:
    ctx->pc = 0x802CD7D8u;
    // 802CD7D8: stb     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_802CD7DC:
    ctx->pc = 0x802CD7DCu;
    // 802CD7DC: lwz     r3, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD7E0:
    ctx->pc = 0x802CD7E0u;
    // 802CD7E0: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CD7E4:
    ctx->pc = 0x802CD7E4u;
    // 802CD7E4: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_802CD7E8:
    ctx->pc = 0x802CD7E8u;
    // 802CD7E8: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CD7EC:
    ctx->pc = 0x802CD7ECu;
    // 802CD7EC: lwz     r0, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD7F0:
    ctx->pc = 0x802CD7F0u;
    // 802CD7F0: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CD7F4:
    ctx->pc = 0x802CD7F4u;
    // 802CD7F4: bl      0x802CCF98
    {
            ctx->lr = 0x802CD7F8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CCF98u;
                return;
            }
            goto label_802CCF98;
    }

label_802CD7F8:
    ctx->pc = 0x802CD7F8u;
    ctx->downcount -= 5;
    // 802CD7F8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD7FC:
    ctx->pc = 0x802CD7FCu;
    // 802CD7FC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802CD800:
    ctx->pc = 0x802CD800u;
    // 802CD800: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CD804:
    ctx->pc = 0x802CD804u;
    // 802CD804: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CD808:
    ctx->pc = 0x802CD808u;
    ctx->downcount -= 4;
    // 802CD808: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD80C:
    ctx->pc = 0x802CD80Cu;
    // 802CD80C: lhz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CD810:
    ctx->pc = 0x802CD810u;
    // 802CD810: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CD814:
    ctx->pc = 0x802CD814u;
    // 802CD814: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CD818:
    ctx->pc = 0x802CD818u;
    ctx->downcount -= 27;
    // 802CD818: lwz     r9, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_802CD81C:
    ctx->pc = 0x802CD81Cu;
    // 802CD81C: addi    r5, r13, -28080
    ctx->gpr[5] = ctx->gpr[13] + (u32)(s32)(-28080);

label_802CD820:
    ctx->pc = 0x802CD820u;
    // 802CD820: lwz     r8, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_802CD824:
    ctx->pc = 0x802CD824u;
    // 802CD824: rlwinm r0, r9, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0x00000001u;
    }

label_802CD828:
    ctx->pc = 0x802CD828u;
    // 802CD828: lwz     r4, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CD82C:
    ctx->pc = 0x802CD82Cu;
    // 802CD82C: rlwinm r6, r9, 31, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 31u) & 0x00000001u;
    }

label_802CD830:
    ctx->pc = 0x802CD830u;
    // 802CD830: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD834:
    ctx->pc = 0x802CD834u;
    // 802CD834: rlwinm r6, r9, 30, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 30u) & 0x00000001u;
    }

label_802CD838:
    ctx->pc = 0x802CD838u;
    // 802CD838: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD83C:
    ctx->pc = 0x802CD83Cu;
    // 802CD83C: rlwinm r7, r9, 29, 31, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[9], 29u) & 0x00000001u;
    }

label_802CD840:
    ctx->pc = 0x802CD840u;
    // 802CD840: rlwinm r6, r9, 23, 30, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 23u) & 0x00000003u;
    }

label_802CD844:
    ctx->pc = 0x802CD844u;
    // 802CD844: lbzx    r5, r5, r6
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[6];
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_802CD848:
    ctx->pc = 0x802CD848u;
    // 802CD848: rlwinm r8, r8, 23, 31, 31
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 23u) & 0x00000001u;
    }

label_802CD84C:
    ctx->pc = 0x802CD84Cu;
    // 802CD84C: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD850:
    ctx->pc = 0x802CD850u;
    // 802CD850: rlwinm r6, r9, 28, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x00000001u;
    }

label_802CD854:
    ctx->pc = 0x802CD854u;
    // 802CD854: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD858:
    ctx->pc = 0x802CD858u;
    // 802CD858: rlwinm r6, r9, 27, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 27u) & 0x00000001u;
    }

label_802CD85C:
    ctx->pc = 0x802CD85Cu;
    // 802CD85C: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD860:
    ctx->pc = 0x802CD860u;
    // 802CD860: rlwinm r6, r9, 26, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 26u) & 0x00000001u;
    }

label_802CD864:
    ctx->pc = 0x802CD864u;
    // 802CD864: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD868:
    ctx->pc = 0x802CD868u;
    // 802CD868: rlwinm r6, r9, 25, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 25u) & 0x00000001u;
    }

label_802CD86C:
    ctx->pc = 0x802CD86Cu;
    // 802CD86C: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD870:
    ctx->pc = 0x802CD870u;
    // 802CD870: rlwinm r6, r9, 24, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 24u) & 0x00000001u;
    }

label_802CD874:
    ctx->pc = 0x802CD874u;
    // 802CD874: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD878:
    ctx->pc = 0x802CD878u;
    // 802CD878: cmpwi   r8, 1
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CD87C:
    ctx->pc = 0x802CD87Cu;
    // 802CD87C: add   r0, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD880:
    ctx->pc = 0x802CD880u;
    // 802CD880: bc    4, 2, 0x802CD88C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CD88C;
        }
    }

label_802CD884:
    ctx->pc = 0x802CD884u;
    ctx->downcount -= 2;
    // 802CD884: li      r8, 3
    ctx->gpr[8] = (u32)(s32)(3);

label_802CD888:
    ctx->pc = 0x802CD888u;
    // 802CD888: b       0x802CD890
    {
            goto label_802CD890;
    }

label_802CD88C:
    ctx->pc = 0x802CD88Cu;
    ctx->downcount -= 1;
    // 802CD88C: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_802CD890:
    ctx->pc = 0x802CD890u;
    ctx->downcount -= 43;
    // 802CD890: rlwinm r6, r9, 21, 30, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 21u) & 0x00000003u;
    }

label_802CD894:
    ctx->pc = 0x802CD894u;
    // 802CD894: addi    r5, r13, -28080
    ctx->gpr[5] = ctx->gpr[13] + (u32)(s32)(-28080);

label_802CD898:
    ctx->pc = 0x802CD898u;
    // 802CD898: lbzx    r6, r5, r6
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[6];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_802CD89C:
    ctx->pc = 0x802CD89Cu;
    // 802CD89C: rlwinm r5, r9, 19, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[9], 19u) & 0x00000003u;
    }

label_802CD8A0:
    ctx->pc = 0x802CD8A0u;
    // 802CD8A0: addi    r7, r13, -28088
    ctx->gpr[7] = ctx->gpr[13] + (u32)(s32)(-28088);

label_802CD8A4:
    ctx->pc = 0x802CD8A4u;
    // 802CD8A4: mullw   r8, r6, r8
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[8];
        ctx->gpr[8] = (u32)product;
    }

label_802CD8A8:
    ctx->pc = 0x802CD8A8u;
    // 802CD8A8: lbzx    r6, r7, r5
    {
        u32 ea = ctx->gpr[7] + ctx->gpr[5];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_802CD8AC:
    ctx->pc = 0x802CD8ACu;
    // 802CD8AC: add   r0, r0, r8
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD8B0:
    ctx->pc = 0x802CD8B0u;
    // 802CD8B0: rlwinm r5, r9, 17, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[9], 17u) & 0x00000003u;
    }

label_802CD8B4:
    ctx->pc = 0x802CD8B4u;
    // 802CD8B4: lbzx    r9, r7, r5
    {
        u32 ea = ctx->gpr[7] + ctx->gpr[5];
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_802CD8B8:
    ctx->pc = 0x802CD8B8u;
    // 802CD8B8: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD8BC:
    ctx->pc = 0x802CD8BCu;
    // 802CD8BC: rlwinm r6, r4, 0, 30, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000003u;
    }

label_802CD8C0:
    ctx->pc = 0x802CD8C0u;
    // 802CD8C0: addi    r8, r13, -28084
    ctx->gpr[8] = ctx->gpr[13] + (u32)(s32)(-28084);

label_802CD8C4:
    ctx->pc = 0x802CD8C4u;
    // 802CD8C4: rlwinm r5, r4, 30, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 30u) & 0x00000003u;
    }

label_802CD8C8:
    ctx->pc = 0x802CD8C8u;
    // 802CD8C8: lbzx    r7, r8, r6
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[6];
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_802CD8CC:
    ctx->pc = 0x802CD8CCu;
    // 802CD8CC: add   r0, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD8D0:
    ctx->pc = 0x802CD8D0u;
    // 802CD8D0: lbzx    r6, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_802CD8D4:
    ctx->pc = 0x802CD8D4u;
    // 802CD8D4: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD8D8:
    ctx->pc = 0x802CD8D8u;
    // 802CD8D8: rlwinm r5, r4, 28, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 28u) & 0x00000003u;
    }

label_802CD8DC:
    ctx->pc = 0x802CD8DCu;
    // 802CD8DC: lbzx    r7, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_802CD8E0:
    ctx->pc = 0x802CD8E0u;
    // 802CD8E0: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD8E4:
    ctx->pc = 0x802CD8E4u;
    // 802CD8E4: rlwinm r5, r4, 26, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 26u) & 0x00000003u;
    }

label_802CD8E8:
    ctx->pc = 0x802CD8E8u;
    // 802CD8E8: lbzx    r6, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_802CD8EC:
    ctx->pc = 0x802CD8ECu;
    // 802CD8EC: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD8F0:
    ctx->pc = 0x802CD8F0u;
    // 802CD8F0: rlwinm r5, r4, 24, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 24u) & 0x00000003u;
    }

label_802CD8F4:
    ctx->pc = 0x802CD8F4u;
    // 802CD8F4: lbzx    r7, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_802CD8F8:
    ctx->pc = 0x802CD8F8u;
    // 802CD8F8: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD8FC:
    ctx->pc = 0x802CD8FCu;
    // 802CD8FC: rlwinm r5, r4, 22, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 22u) & 0x00000003u;
    }

label_802CD900:
    ctx->pc = 0x802CD900u;
    // 802CD900: lbzx    r6, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_802CD904:
    ctx->pc = 0x802CD904u;
    // 802CD904: rlwinm r5, r4, 20, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 20u) & 0x00000003u;
    }

label_802CD908:
    ctx->pc = 0x802CD908u;
    // 802CD908: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD90C:
    ctx->pc = 0x802CD90Cu;
    // 802CD90C: lbzx    r5, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_802CD910:
    ctx->pc = 0x802CD910u;
    // 802CD910: rlwinm r4, r4, 18, 30, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 18u) & 0x00000003u;
    }

label_802CD914:
    ctx->pc = 0x802CD914u;
    // 802CD914: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD918:
    ctx->pc = 0x802CD918u;
    // 802CD918: lbzx    r4, r8, r4
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[4];
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_802CD91C:
    ctx->pc = 0x802CD91Cu;
    // 802CD91C: add   r0, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD920:
    ctx->pc = 0x802CD920u;
    // 802CD920: add   r0, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802CD924:
    ctx->pc = 0x802CD924u;
    // 802CD924: sth     r0, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CD928:
    ctx->pc = 0x802CD928u;
    // 802CD928: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CD92C:
    ctx->pc = 0x802CD92Cu;
    ctx->downcount -= 2;
    // 802CD92C: cmplwi  r3, 0x0019
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0019u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CD930:
    ctx->pc = 0x802CD930u;
    // 802CD930: bc    12, 1, 0x802CDAD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CDAD4;
        }
    }

label_802CD934:
    ctx->pc = 0x802CD934u;
    ctx->downcount -= 7;
    // 802CD934: lis     r5, -32715
    ctx->gpr[5] = ((u32)(s32)(-32715) << 16);

label_802CD938:
    ctx->pc = 0x802CD938u;
    // 802CD938: addi    r5, r5, 31888
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(31888);

label_802CD93C:
    ctx->pc = 0x802CD93Cu;
    // 802CD93C: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_802CD940:
    ctx->pc = 0x802CD940u;
    // 802CD940: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD944:
    ctx->pc = 0x802CD944u;
    // 802CD944: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802CD948:
    ctx->pc = 0x802CD948u;
    // 802CD948: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_802CD94C:
    ctx->pc = 0x802CD94Cu;
    ctx->downcount -= 4;
    // 802CD94C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD950:
    ctx->pc = 0x802CD950u;
    // 802CD950: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD954:
    ctx->pc = 0x802CD954u;
    // 802CD954: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_802CD958:
    ctx->pc = 0x802CD958u;
    // 802CD958: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CD95C:
    ctx->pc = 0x802CD95Cu;
    ctx->downcount -= 4;
    // 802CD95C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD960:
    ctx->pc = 0x802CD960u;
    // 802CD960: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD964:
    ctx->pc = 0x802CD964u;
    // 802CD964: rlwinm r0, r0, 31, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000001u;
    }

label_802CD968:
    ctx->pc = 0x802CD968u;
    // 802CD968: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CD96C:
    ctx->pc = 0x802CD96Cu;
    ctx->downcount -= 4;
    // 802CD96C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD970:
    ctx->pc = 0x802CD970u;
    // 802CD970: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD974:
    ctx->pc = 0x802CD974u;
    // 802CD974: rlwinm r0, r0, 30, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x00000001u;
    }

label_802CD978:
    ctx->pc = 0x802CD978u;
    // 802CD978: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CD97C:
    ctx->pc = 0x802CD97Cu;
    ctx->downcount -= 4;
    // 802CD97C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD980:
    ctx->pc = 0x802CD980u;
    // 802CD980: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD984:
    ctx->pc = 0x802CD984u;
    // 802CD984: rlwinm r0, r0, 29, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 29u) & 0x00000001u;
    }

label_802CD988:
    ctx->pc = 0x802CD988u;
    // 802CD988: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CD98C:
    ctx->pc = 0x802CD98Cu;
    ctx->downcount -= 4;
    // 802CD98C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD990:
    ctx->pc = 0x802CD990u;
    // 802CD990: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD994:
    ctx->pc = 0x802CD994u;
    // 802CD994: rlwinm r0, r0, 28, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x00000001u;
    }

label_802CD998:
    ctx->pc = 0x802CD998u;
    // 802CD998: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CD99C:
    ctx->pc = 0x802CD99Cu;
    ctx->downcount -= 4;
    // 802CD99C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD9A0:
    ctx->pc = 0x802CD9A0u;
    // 802CD9A0: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD9A4:
    ctx->pc = 0x802CD9A4u;
    // 802CD9A4: rlwinm r0, r0, 27, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x00000001u;
    }

label_802CD9A8:
    ctx->pc = 0x802CD9A8u;
    // 802CD9A8: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CD9AC:
    ctx->pc = 0x802CD9ACu;
    ctx->downcount -= 4;
    // 802CD9AC: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD9B0:
    ctx->pc = 0x802CD9B0u;
    // 802CD9B0: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD9B4:
    ctx->pc = 0x802CD9B4u;
    // 802CD9B4: rlwinm r0, r0, 26, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x00000001u;
    }

label_802CD9B8:
    ctx->pc = 0x802CD9B8u;
    // 802CD9B8: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CD9BC:
    ctx->pc = 0x802CD9BCu;
    ctx->downcount -= 4;
    // 802CD9BC: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD9C0:
    ctx->pc = 0x802CD9C0u;
    // 802CD9C0: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD9C4:
    ctx->pc = 0x802CD9C4u;
    // 802CD9C4: rlwinm r0, r0, 25, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 25u) & 0x00000001u;
    }

label_802CD9C8:
    ctx->pc = 0x802CD9C8u;
    // 802CD9C8: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CD9CC:
    ctx->pc = 0x802CD9CCu;
    ctx->downcount -= 4;
    // 802CD9CC: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD9D0:
    ctx->pc = 0x802CD9D0u;
    // 802CD9D0: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD9D4:
    ctx->pc = 0x802CD9D4u;
    // 802CD9D4: rlwinm r0, r0, 24, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x00000001u;
    }

label_802CD9D8:
    ctx->pc = 0x802CD9D8u;
    // 802CD9D8: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CD9DC:
    ctx->pc = 0x802CD9DCu;
    ctx->downcount -= 4;
    // 802CD9DC: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD9E0:
    ctx->pc = 0x802CD9E0u;
    // 802CD9E0: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CD9E4:
    ctx->pc = 0x802CD9E4u;
    // 802CD9E4: rlwinm r0, r0, 23, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x00000003u;
    }

label_802CD9E8:
    ctx->pc = 0x802CD9E8u;
    // 802CD9E8: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CD9EC:
    ctx->pc = 0x802CD9ECu;
    ctx->downcount -= 4;
    // 802CD9EC: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CD9F0:
    ctx->pc = 0x802CD9F0u;
    // 802CD9F0: lbz     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CD9F4:
    ctx->pc = 0x802CD9F4u;
    // 802CD9F4: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CD9F8:
    ctx->pc = 0x802CD9F8u;
    // 802CD9F8: bc    12, 2, 0x802CDA08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CDA08;
        }
    }

label_802CD9FC:
    ctx->pc = 0x802CD9FCu;
    ctx->downcount -= 3;
    // 802CD9FC: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDA00:
    ctx->pc = 0x802CDA00u;
    // 802CDA00: rlwinm r0, r0, 21, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 21u) & 0x00000003u;
    }

label_802CDA04:
    ctx->pc = 0x802CDA04u;
    // 802CDA04: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDA08:
    ctx->pc = 0x802CDA08u;
    ctx->downcount -= 2;
    // 802CDA08: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CDA0C:
    ctx->pc = 0x802CDA0Cu;
    // 802CDA0C: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDA10:
    ctx->pc = 0x802CDA10u;
    ctx->downcount -= 4;
    // 802CDA10: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDA14:
    ctx->pc = 0x802CDA14u;
    // 802CDA14: lbz     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CDA18:
    ctx->pc = 0x802CDA18u;
    // 802CDA18: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CDA1C:
    ctx->pc = 0x802CDA1Cu;
    // 802CDA1C: bc    12, 2, 0x802CDA2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CDA2C;
        }
    }

label_802CDA20:
    ctx->pc = 0x802CDA20u;
    ctx->downcount -= 3;
    // 802CDA20: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDA24:
    ctx->pc = 0x802CDA24u;
    // 802CDA24: rlwinm r0, r0, 21, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 21u) & 0x00000003u;
    }

label_802CDA28:
    ctx->pc = 0x802CDA28u;
    // 802CDA28: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDA2C:
    ctx->pc = 0x802CDA2Cu;
    ctx->downcount -= 2;
    // 802CDA2C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CDA30:
    ctx->pc = 0x802CDA30u;
    // 802CDA30: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDA34:
    ctx->pc = 0x802CDA34u;
    ctx->downcount -= 4;
    // 802CDA34: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDA38:
    ctx->pc = 0x802CDA38u;
    // 802CDA38: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDA3C:
    ctx->pc = 0x802CDA3Cu;
    // 802CDA3C: rlwinm r0, r0, 19, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 19u) & 0x00000003u;
    }

label_802CDA40:
    ctx->pc = 0x802CDA40u;
    // 802CDA40: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDA44:
    ctx->pc = 0x802CDA44u;
    ctx->downcount -= 4;
    // 802CDA44: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDA48:
    ctx->pc = 0x802CDA48u;
    // 802CDA48: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDA4C:
    ctx->pc = 0x802CDA4Cu;
    // 802CDA4C: rlwinm r0, r0, 17, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x00000003u;
    }

label_802CDA50:
    ctx->pc = 0x802CDA50u;
    // 802CDA50: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDA54:
    ctx->pc = 0x802CDA54u;
    ctx->downcount -= 4;
    // 802CDA54: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDA58:
    ctx->pc = 0x802CDA58u;
    // 802CDA58: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDA5C:
    ctx->pc = 0x802CDA5Cu;
    // 802CDA5C: rlwinm r0, r0, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000003u;
    }

label_802CDA60:
    ctx->pc = 0x802CDA60u;
    // 802CDA60: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDA64:
    ctx->pc = 0x802CDA64u;
    ctx->downcount -= 4;
    // 802CDA64: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDA68:
    ctx->pc = 0x802CDA68u;
    // 802CDA68: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDA6C:
    ctx->pc = 0x802CDA6Cu;
    // 802CDA6C: rlwinm r0, r0, 30, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x00000003u;
    }

label_802CDA70:
    ctx->pc = 0x802CDA70u;
    // 802CDA70: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDA74:
    ctx->pc = 0x802CDA74u;
    ctx->downcount -= 4;
    // 802CDA74: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDA78:
    ctx->pc = 0x802CDA78u;
    // 802CDA78: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDA7C:
    ctx->pc = 0x802CDA7Cu;
    // 802CDA7C: rlwinm r0, r0, 28, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x00000003u;
    }

label_802CDA80:
    ctx->pc = 0x802CDA80u;
    // 802CDA80: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDA84:
    ctx->pc = 0x802CDA84u;
    ctx->downcount -= 4;
    // 802CDA84: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDA88:
    ctx->pc = 0x802CDA88u;
    // 802CDA88: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDA8C:
    ctx->pc = 0x802CDA8Cu;
    // 802CDA8C: rlwinm r0, r0, 26, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x00000003u;
    }

label_802CDA90:
    ctx->pc = 0x802CDA90u;
    // 802CDA90: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDA94:
    ctx->pc = 0x802CDA94u;
    ctx->downcount -= 4;
    // 802CDA94: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDA98:
    ctx->pc = 0x802CDA98u;
    // 802CDA98: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDA9C:
    ctx->pc = 0x802CDA9Cu;
    // 802CDA9C: rlwinm r0, r0, 24, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x00000003u;
    }

label_802CDAA0:
    ctx->pc = 0x802CDAA0u;
    // 802CDAA0: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDAA4:
    ctx->pc = 0x802CDAA4u;
    ctx->downcount -= 4;
    // 802CDAA4: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDAA8:
    ctx->pc = 0x802CDAA8u;
    // 802CDAA8: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDAAC:
    ctx->pc = 0x802CDAACu;
    // 802CDAAC: rlwinm r0, r0, 22, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 22u) & 0x00000003u;
    }

label_802CDAB0:
    ctx->pc = 0x802CDAB0u;
    // 802CDAB0: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDAB4:
    ctx->pc = 0x802CDAB4u;
    ctx->downcount -= 4;
    // 802CDAB4: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDAB8:
    ctx->pc = 0x802CDAB8u;
    // 802CDAB8: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDABC:
    ctx->pc = 0x802CDABCu;
    // 802CDABC: rlwinm r0, r0, 20, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 20u) & 0x00000003u;
    }

label_802CDAC0:
    ctx->pc = 0x802CDAC0u;
    // 802CDAC0: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDAC4:
    ctx->pc = 0x802CDAC4u;
    ctx->downcount -= 4;
    // 802CDAC4: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDAC8:
    ctx->pc = 0x802CDAC8u;
    // 802CDAC8: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDACC:
    ctx->pc = 0x802CDACCu;
    // 802CDACC: rlwinm r0, r0, 18, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 18u) & 0x00000003u;
    }

label_802CDAD0:
    ctx->pc = 0x802CDAD0u;
    // 802CDAD0: b       0x802CDAD8
    {
            goto label_802CDAD8;
    }

label_802CDAD4:
    ctx->pc = 0x802CDAD4u;
    ctx->downcount -= 1;
    // 802CDAD4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CDAD8:
    ctx->pc = 0x802CDAD8u;
    ctx->downcount -= 2;
    // 802CDAD8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDADC:
    ctx->pc = 0x802CDADCu;
    // 802CDADC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CDAE0:
    ctx->pc = 0x802CDAE0u;
    ctx->downcount -= 9;
    // 802CDAE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CDAE4:
    ctx->pc = 0x802CDAE4u;
    // 802CDAE4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDAE8:
    ctx->pc = 0x802CDAE8u;
    // 802CDAE8: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CDAEC:
    ctx->pc = 0x802CDAECu;
    // 802CDAEC: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CDAF0:
    ctx->pc = 0x802CDAF0u;
    // 802CDAF0: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_802CDAF4:
    ctx->pc = 0x802CDAF4u;
    // 802CDAF4: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CDAF8:
    ctx->pc = 0x802CDAF8u;
    // 802CDAF8: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_802CDAFC:
    ctx->pc = 0x802CDAFCu;
    // 802CDAFC: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802CDB00:
    ctx->pc = 0x802CDB00u;
    // 802CDB00: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802CDB04:
    ctx->downcount -= 5;
    // 802CDB04: add   r4, r29, r31
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_802CDB08:
    ctx->pc = 0x802CDB08u;
    // 802CDB08: stw     r30, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CDB0C:
    // 802CDB0C: addi    r3, r30, 0
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(0);

label_802CDB10:
    // 802CDB10: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_802CDB14:
    // 802CDB14: bl      0x802CD92C
    {
            ctx->lr = 0x802CDB18u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CD92Cu;
                return;
            }
            goto label_802CD92C;
    }

label_802CDB18:
    ctx->downcount -= 4;
    // 802CDB18: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_802CDB1C:
    // 802CDB1C: cmpwi   r30, 20
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(20);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CDB20:
    // 802CDB20: addi    r31, r31, 8
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(8);

label_802CDB24:
    // 802CDB24: bc    4, 1, 0x802CDB04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CDB04u;
                return;
            }
            goto label_802CDB04;
        }
    }

label_802CDB28:
    ctx->pc = 0x802CDB28u;
    ctx->downcount -= 7;
    // 802CDB28: rlwinm r0, r30, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 3u) & 0xFFFFFFF8u;
    }

label_802CDB2C:
    ctx->pc = 0x802CDB2Cu;
    // 802CDB2C: add   r3, r29, r0
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802CDB30:
    ctx->pc = 0x802CDB30u;
    // 802CDB30: li      r0, 25
    ctx->gpr[0] = (u32)(s32)(25);

label_802CDB34:
    ctx->pc = 0x802CDB34u;
    // 802CDB34: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDB38:
    ctx->pc = 0x802CDB38u;
    // 802CDB38: addi    r4, r3, 4
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(4);

label_802CDB3C:
    ctx->pc = 0x802CDB3Cu;
    // 802CDB3C: li      r3, 25
    ctx->gpr[3] = (u32)(s32)(25);

label_802CDB40:
    ctx->pc = 0x802CDB40u;
    // 802CDB40: bl      0x802CD92C
    {
            ctx->lr = 0x802CDB44u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CD92Cu;
                return;
            }
            goto label_802CD92C;
    }

label_802CDB44:
    ctx->pc = 0x802CDB44u;
    ctx->downcount -= 12;
    // 802CDB44: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_802CDB48:
    ctx->pc = 0x802CDB48u;
    // 802CDB48: rlwinm r0, r30, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 3u) & 0xFFFFFFF8u;
    }

label_802CDB4C:
    ctx->pc = 0x802CDB4Cu;
    // 802CDB4C: li      r3, 255
    ctx->gpr[3] = (u32)(s32)(255);

label_802CDB50:
    ctx->pc = 0x802CDB50u;
    // 802CDB50: stwx    r3, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CDB54:
    ctx->pc = 0x802CDB54u;
    // 802CDB54: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDB58:
    ctx->pc = 0x802CDB58u;
    // 802CDB58: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CDB5C:
    ctx->pc = 0x802CDB5Cu;
    // 802CDB5C: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CDB60:
    ctx->pc = 0x802CDB60u;
    // 802CDB60: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802CDB64:
    ctx->pc = 0x802CDB64u;
    // 802CDB64: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802CDB68:
    ctx->pc = 0x802CDB68u;
    // 802CDB68: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CDB6C:
    ctx->pc = 0x802CDB6Cu;
    // 802CDB6C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CDB70:
    ctx->pc = 0x802CDB70u;
    ctx->downcount -= 14;
    // 802CDB70: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CDB74:
    ctx->pc = 0x802CDB74u;
    // 802CDB74: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802CDB78:
    ctx->pc = 0x802CDB78u;
    // 802CDB78: stw     r4, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CDB7C:
    ctx->pc = 0x802CDB7Cu;
    // 802CDB7C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDB80:
    ctx->pc = 0x802CDB80u;
    // 802CDB80: rlwinm r0, r0, 0, 23, 20
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF9FFu;
    }

label_802CDB84:
    ctx->pc = 0x802CDB84u;
    // 802CDB84: ori     r0, r0, 0x0200
    ctx->gpr[0] = ctx->gpr[0] | 0x0200u;

label_802CDB88:
    ctx->pc = 0x802CDB88u;
    // 802CDB88: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDB8C:
    ctx->pc = 0x802CDB8Cu;
    // 802CDB8C: stw     r4, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CDB90:
    ctx->pc = 0x802CDB90u;
    // 802CDB90: stb     r4, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CDB94:
    ctx->pc = 0x802CDB94u;
    // 802CDB94: stb     r4, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CDB98:
    ctx->pc = 0x802CDB98u;
    // 802CDB98: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDB9C:
    ctx->pc = 0x802CDB9Cu;
    // 802CDB9C: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_802CDBA0:
    ctx->pc = 0x802CDBA0u;
    // 802CDBA0: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDBA4:
    ctx->pc = 0x802CDBA4u;
    // 802CDBA4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CDBA8:
    ctx->pc = 0x802CDBA8u;
    ctx->downcount -= 9;
    // 802CDBA8: addi    r0, r4, -9
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-9);

label_802CDBAC:
    ctx->pc = 0x802CDBACu;
    // 802CDBAC: lwz     r8, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_802CDBB0:
    ctx->pc = 0x802CDBB0u;
    // 802CDBB0: rlwinm r4, r3, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_802CDBB4:
    ctx->pc = 0x802CDBB4u;
    // 802CDBB4: add   r9, r8, r4
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_802CDBB8:
    ctx->pc = 0x802CDBB8u;
    // 802CDBB8: cmplwi  r0, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CDBBC:
    ctx->pc = 0x802CDBBCu;
    // 802CDBBC: addi    r4, r9, 28
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(28);

label_802CDBC0:
    ctx->pc = 0x802CDBC0u;
    // 802CDBC0: addi    r8, r9, 60
    ctx->gpr[8] = ctx->gpr[9] + (u32)(s32)(60);

label_802CDBC4:
    ctx->pc = 0x802CDBC4u;
    // 802CDBC4: addi    r9, r9, 92
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(92);

label_802CDBC8:
    ctx->pc = 0x802CDBC8u;
    // 802CDBC8: bc    12, 1, 0x802CDED0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CDED0;
        }
    }

label_802CDBCC:
    ctx->pc = 0x802CDBCCu;
    ctx->downcount -= 7;
    // 802CDBCC: lis     r10, -32715
    ctx->gpr[10] = ((u32)(s32)(-32715) << 16);

label_802CDBD0:
    ctx->pc = 0x802CDBD0u;
    // 802CDBD0: addi    r10, r10, 31992
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(31992);

label_802CDBD4:
    ctx->pc = 0x802CDBD4u;
    // 802CDBD4: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_802CDBD8:
    ctx->pc = 0x802CDBD8u;
    // 802CDBD8: lwzx    r0, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDBDC:
    ctx->pc = 0x802CDBDCu;
    // 802CDBDC: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802CDBE0:
    ctx->pc = 0x802CDBE0u;
    // 802CDBE0: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_802CDBE4:
    ctx->pc = 0x802CDBE4u;
    ctx->downcount -= 15;
    // 802CDBE4: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDBE8:
    ctx->pc = 0x802CDBE8u;
    // 802CDBE8: rlwinm r6, r6, 1, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_802CDBEC:
    ctx->pc = 0x802CDBECu;
    // 802CDBEC: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_802CDBF0:
    ctx->pc = 0x802CDBF0u;
    // 802CDBF0: or   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[5];
    }

label_802CDBF4:
    ctx->pc = 0x802CDBF4u;
    // 802CDBF4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDBF8:
    ctx->pc = 0x802CDBF8u;
    // 802CDBF8: rlwinm r0, r7, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0x00000FF0u;
    }

label_802CDBFC:
    ctx->pc = 0x802CDBFCu;
    // 802CDBFC: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDC00:
    ctx->pc = 0x802CDC00u;
    // 802CDC00: rlwinm r5, r5, 0, 31, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF1u;
    }

label_802CDC04:
    ctx->pc = 0x802CDC04u;
    // 802CDC04: or   r5, r5, r6
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[6];
    }

label_802CDC08:
    ctx->pc = 0x802CDC08u;
    // 802CDC08: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CDC0C:
    ctx->pc = 0x802CDC0Cu;
    // 802CDC0C: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDC10:
    ctx->pc = 0x802CDC10u;
    // 802CDC10: rlwinm r5, r5, 0, 28, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFE0Fu;
    }

label_802CDC14:
    ctx->pc = 0x802CDC14u;
    // 802CDC14: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CDC18:
    ctx->pc = 0x802CDC18u;
    // 802CDC18: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDC1C:
    ctx->pc = 0x802CDC1Cu;
    // 802CDC1C: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDC20:
    ctx->pc = 0x802CDC20u;
    ctx->downcount -= 7;
    // 802CDC20: lwz     r7, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CDC24:
    ctx->pc = 0x802CDC24u;
    // 802CDC24: rlwinm r0, r6, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_802CDC28:
    ctx->pc = 0x802CDC28u;
    // 802CDC28: cmpwi   r5, 2
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CDC2C:
    ctx->pc = 0x802CDC2Cu;
    // 802CDC2C: rlwinm r6, r7, 0, 22, 18
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFE3FFu;
    }

label_802CDC30:
    ctx->pc = 0x802CDC30u;
    // 802CDC30: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CDC34:
    ctx->pc = 0x802CDC34u;
    // 802CDC34: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDC38:
    ctx->pc = 0x802CDC38u;
    // 802CDC38: bc    4, 2, 0x802CDC60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CDC60;
        }
    }

label_802CDC3C:
    ctx->pc = 0x802CDC3Cu;
    ctx->downcount -= 9;
    // 802CDC3C: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDC40:
    ctx->pc = 0x802CDC40u;
    // 802CDC40: rlwinm r0, r0, 0, 23, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFDFFu;
    }

label_802CDC44:
    ctx->pc = 0x802CDC44u;
    // 802CDC44: ori     r0, r0, 0x0200
    ctx->gpr[0] = ctx->gpr[0] | 0x0200u;

label_802CDC48:
    ctx->pc = 0x802CDC48u;
    // 802CDC48: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDC4C:
    ctx->pc = 0x802CDC4Cu;
    // 802CDC4C: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDC50:
    ctx->pc = 0x802CDC50u;
    // 802CDC50: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_802CDC54:
    ctx->pc = 0x802CDC54u;
    // 802CDC54: oris    r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] | (0x8000u << 16);

label_802CDC58:
    ctx->pc = 0x802CDC58u;
    // 802CDC58: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDC5C:
    ctx->pc = 0x802CDC5Cu;
    // 802CDC5C: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDC60:
    ctx->pc = 0x802CDC60u;
    ctx->downcount -= 9;
    // 802CDC60: lwz     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CDC64:
    ctx->pc = 0x802CDC64u;
    // 802CDC64: rlwinm r0, r5, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 9u) & 0xFFFFFE00u;
    }

label_802CDC68:
    ctx->pc = 0x802CDC68u;
    // 802CDC68: rlwinm r5, r6, 0, 23, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFDFFu;
    }

label_802CDC6C:
    ctx->pc = 0x802CDC6Cu;
    // 802CDC6C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CDC70:
    ctx->pc = 0x802CDC70u;
    // 802CDC70: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDC74:
    ctx->pc = 0x802CDC74u;
    // 802CDC74: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDC78:
    ctx->pc = 0x802CDC78u;
    // 802CDC78: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_802CDC7C:
    ctx->pc = 0x802CDC7Cu;
    // 802CDC7C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDC80:
    ctx->pc = 0x802CDC80u;
    // 802CDC80: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDC84:
    ctx->pc = 0x802CDC84u;
    ctx->downcount -= 11;
    // 802CDC84: lwz     r7, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CDC88:
    ctx->pc = 0x802CDC88u;
    // 802CDC88: rlwinm r5, r5, 13, 0, 18
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 13u) & 0xFFFFE000u;
    }

label_802CDC8C:
    ctx->pc = 0x802CDC8Cu;
    // 802CDC8C: rlwinm r0, r6, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 14u) & 0xFFFFC000u;
    }

label_802CDC90:
    ctx->pc = 0x802CDC90u;
    // 802CDC90: rlwinm r6, r7, 0, 19, 17
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFDFFFu;
    }

label_802CDC94:
    ctx->pc = 0x802CDC94u;
    // 802CDC94: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_802CDC98:
    ctx->pc = 0x802CDC98u;
    // 802CDC98: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CDC9C:
    ctx->pc = 0x802CDC9Cu;
    // 802CDC9C: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDCA0:
    ctx->pc = 0x802CDCA0u;
    // 802CDCA0: rlwinm r5, r5, 0, 18, 14
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFE3FFFu;
    }

label_802CDCA4:
    ctx->pc = 0x802CDCA4u;
    // 802CDCA4: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CDCA8:
    ctx->pc = 0x802CDCA8u;
    // 802CDCA8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDCAC:
    ctx->pc = 0x802CDCACu;
    // 802CDCAC: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDCB0:
    ctx->pc = 0x802CDCB0u;
    ctx->downcount -= 11;
    // 802CDCB0: lwz     r7, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CDCB4:
    ctx->pc = 0x802CDCB4u;
    // 802CDCB4: rlwinm r5, r5, 17, 0, 14
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 17u) & 0xFFFE0000u;
    }

label_802CDCB8:
    ctx->pc = 0x802CDCB8u;
    // 802CDCB8: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_802CDCBC:
    ctx->pc = 0x802CDCBCu;
    // 802CDCBC: rlwinm r6, r7, 0, 15, 13
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFDFFFFu;
    }

label_802CDCC0:
    ctx->pc = 0x802CDCC0u;
    // 802CDCC0: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_802CDCC4:
    ctx->pc = 0x802CDCC4u;
    // 802CDCC4: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CDCC8:
    ctx->pc = 0x802CDCC8u;
    // 802CDCC8: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDCCC:
    ctx->pc = 0x802CDCCCu;
    // 802CDCCC: rlwinm r5, r5, 0, 14, 10
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFE3FFFFu;
    }

label_802CDCD0:
    ctx->pc = 0x802CDCD0u;
    // 802CDCD0: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CDCD4:
    ctx->pc = 0x802CDCD4u;
    // 802CDCD4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDCD8:
    ctx->pc = 0x802CDCD8u;
    // 802CDCD8: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDCDC:
    ctx->pc = 0x802CDCDCu;
    ctx->downcount -= 16;
    // 802CDCDC: lwz     r8, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_802CDCE0:
    ctx->pc = 0x802CDCE0u;
    // 802CDCE0: rlwinm r0, r5, 21, 0, 10
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 21u) & 0xFFE00000u;
    }

label_802CDCE4:
    ctx->pc = 0x802CDCE4u;
    // 802CDCE4: rlwinm r5, r8, 0, 11, 9
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0xFFDFFFFFu;
    }

label_802CDCE8:
    ctx->pc = 0x802CDCE8u;
    // 802CDCE8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CDCEC:
    ctx->pc = 0x802CDCECu;
    // 802CDCEC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDCF0:
    ctx->pc = 0x802CDCF0u;
    // 802CDCF0: rlwinm r5, r6, 22, 0, 9
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[6], 22u) & 0xFFC00000u;
    }

label_802CDCF4:
    ctx->pc = 0x802CDCF4u;
    // 802CDCF4: rlwinm r0, r7, 25, 0, 6
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 25u) & 0xFE000000u;
    }

label_802CDCF8:
    ctx->pc = 0x802CDCF8u;
    // 802CDCF8: lwz     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CDCFC:
    ctx->pc = 0x802CDCFCu;
    // 802CDCFC: rlwinm r6, r6, 0, 10, 6
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFE3FFFFFu;
    }

label_802CDD00:
    ctx->pc = 0x802CDD00u;
    // 802CDD00: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_802CDD04:
    ctx->pc = 0x802CDD04u;
    // 802CDD04: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CDD08:
    ctx->pc = 0x802CDD08u;
    // 802CDD08: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDD0C:
    ctx->pc = 0x802CDD0Cu;
    // 802CDD0C: rlwinm r5, r5, 0, 7, 1
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xC1FFFFFFu;
    }

label_802CDD10:
    ctx->pc = 0x802CDD10u;
    // 802CDD10: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CDD14:
    ctx->pc = 0x802CDD14u;
    // 802CDD14: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDD18:
    ctx->pc = 0x802CDD18u;
    // 802CDD18: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDD1C:
    ctx->pc = 0x802CDD1Cu;
    ctx->downcount -= 15;
    // 802CDD1C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDD20:
    ctx->pc = 0x802CDD20u;
    // 802CDD20: rlwinm r4, r6, 1, 0, 30
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_802CDD24:
    ctx->pc = 0x802CDD24u;
    // 802CDD24: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_802CDD28:
    ctx->pc = 0x802CDD28u;
    // 802CDD28: or   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[5];
    }

label_802CDD2C:
    ctx->pc = 0x802CDD2Cu;
    // 802CDD2C: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDD30:
    ctx->pc = 0x802CDD30u;
    // 802CDD30: rlwinm r0, r7, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0x00000FF0u;
    }

label_802CDD34:
    ctx->pc = 0x802CDD34u;
    // 802CDD34: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDD38:
    ctx->pc = 0x802CDD38u;
    // 802CDD38: rlwinm r5, r5, 0, 31, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF1u;
    }

label_802CDD3C:
    ctx->pc = 0x802CDD3Cu;
    // 802CDD3C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_802CDD40:
    ctx->pc = 0x802CDD40u;
    // 802CDD40: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CDD44:
    ctx->pc = 0x802CDD44u;
    // 802CDD44: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDD48:
    ctx->pc = 0x802CDD48u;
    // 802CDD48: rlwinm r4, r4, 0, 28, 22
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFE0Fu;
    }

label_802CDD4C:
    ctx->pc = 0x802CDD4Cu;
    // 802CDD4C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDD50:
    ctx->pc = 0x802CDD50u;
    // 802CDD50: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDD54:
    ctx->pc = 0x802CDD54u;
    // 802CDD54: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDD58:
    ctx->pc = 0x802CDD58u;
    ctx->downcount -= 16;
    // 802CDD58: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDD5C:
    ctx->pc = 0x802CDD5Cu;
    // 802CDD5C: rlwinm r0, r5, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 9u) & 0xFFFFFE00u;
    }

label_802CDD60:
    ctx->pc = 0x802CDD60u;
    // 802CDD60: rlwinm r4, r4, 0, 23, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFDFFu;
    }

label_802CDD64:
    ctx->pc = 0x802CDD64u;
    // 802CDD64: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDD68:
    ctx->pc = 0x802CDD68u;
    // 802CDD68: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDD6C:
    ctx->pc = 0x802CDD6Cu;
    // 802CDD6C: rlwinm r4, r6, 10, 0, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_802CDD70:
    ctx->pc = 0x802CDD70u;
    // 802CDD70: rlwinm r0, r7, 13, 11, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 13u) & 0x001FE000u;
    }

label_802CDD74:
    ctx->pc = 0x802CDD74u;
    // 802CDD74: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDD78:
    ctx->pc = 0x802CDD78u;
    // 802CDD78: rlwinm r5, r5, 0, 22, 18
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFE3FFu;
    }

label_802CDD7C:
    ctx->pc = 0x802CDD7Cu;
    // 802CDD7C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_802CDD80:
    ctx->pc = 0x802CDD80u;
    // 802CDD80: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CDD84:
    ctx->pc = 0x802CDD84u;
    // 802CDD84: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDD88:
    ctx->pc = 0x802CDD88u;
    // 802CDD88: rlwinm r4, r4, 0, 19, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC1FFFu;
    }

label_802CDD8C:
    ctx->pc = 0x802CDD8Cu;
    // 802CDD8C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDD90:
    ctx->pc = 0x802CDD90u;
    // 802CDD90: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDD94:
    ctx->pc = 0x802CDD94u;
    // 802CDD94: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDD98:
    ctx->pc = 0x802CDD98u;
    ctx->downcount -= 16;
    // 802CDD98: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDD9C:
    ctx->pc = 0x802CDD9Cu;
    // 802CDD9C: rlwinm r0, r5, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 18u) & 0xFFFC0000u;
    }

label_802CDDA0:
    ctx->pc = 0x802CDDA0u;
    // 802CDDA0: rlwinm r4, r4, 0, 14, 12
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFBFFFFu;
    }

label_802CDDA4:
    ctx->pc = 0x802CDDA4u;
    // 802CDDA4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDDA8:
    ctx->pc = 0x802CDDA8u;
    // 802CDDA8: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDDAC:
    ctx->pc = 0x802CDDACu;
    // 802CDDAC: rlwinm r4, r6, 19, 0, 12
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 19u) & 0xFFF80000u;
    }

label_802CDDB0:
    ctx->pc = 0x802CDDB0u;
    // 802CDDB0: rlwinm r0, r7, 22, 2, 9
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 22u) & 0x3FC00000u;
    }

label_802CDDB4:
    ctx->pc = 0x802CDDB4u;
    // 802CDDB4: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDDB8:
    ctx->pc = 0x802CDDB8u;
    // 802CDDB8: rlwinm r5, r5, 0, 13, 9
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFC7FFFFu;
    }

label_802CDDBC:
    ctx->pc = 0x802CDDBCu;
    // 802CDDBC: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_802CDDC0:
    ctx->pc = 0x802CDDC0u;
    // 802CDDC0: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CDDC4:
    ctx->pc = 0x802CDDC4u;
    // 802CDDC4: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDDC8:
    ctx->pc = 0x802CDDC8u;
    // 802CDDC8: rlwinm r4, r4, 0, 10, 4
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xF83FFFFFu;
    }

label_802CDDCC:
    ctx->pc = 0x802CDDCCu;
    // 802CDDCC: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDDD0:
    ctx->pc = 0x802CDDD0u;
    // 802CDDD0: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDDD4:
    ctx->pc = 0x802CDDD4u;
    // 802CDDD4: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDDD8:
    ctx->pc = 0x802CDDD8u;
    ctx->downcount -= 16;
    // 802CDDD8: lwz     r10, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_802CDDDC:
    ctx->pc = 0x802CDDDCu;
    // 802CDDDC: rlwinm r0, r5, 27, 0, 4
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 27u) & 0xF8000000u;
    }

label_802CDDE0:
    ctx->pc = 0x802CDDE0u;
    // 802CDDE0: rlwinm r4, r6, 28, 0, 3
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 28u) & 0xF0000000u;
    }

label_802CDDE4:
    ctx->pc = 0x802CDDE4u;
    // 802CDDE4: rlwinm r5, r10, 0, 5, 3
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0xF7FFFFFFu;
    }

label_802CDDE8:
    ctx->pc = 0x802CDDE8u;
    // 802CDDE8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802CDDEC:
    ctx->pc = 0x802CDDECu;
    // 802CDDEC: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDDF0:
    ctx->pc = 0x802CDDF0u;
    // 802CDDF0: rlwinm r0, r7, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x000000FFu;
    }

label_802CDDF4:
    ctx->pc = 0x802CDDF4u;
    // 802CDDF4: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDDF8:
    ctx->pc = 0x802CDDF8u;
    // 802CDDF8: rlwinm r5, r5, 0, 4, 0
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x8FFFFFFFu;
    }

label_802CDDFC:
    ctx->pc = 0x802CDDFCu;
    // 802CDDFC: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_802CDE00:
    ctx->pc = 0x802CDE00u;
    // 802CDE00: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CDE04:
    ctx->pc = 0x802CDE04u;
    // 802CDE04: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDE08:
    ctx->pc = 0x802CDE08u;
    // 802CDE08: rlwinm r4, r4, 0, 0, 26
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFE0u;
    }

label_802CDE0C:
    ctx->pc = 0x802CDE0Cu;
    // 802CDE0C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDE10:
    ctx->pc = 0x802CDE10u;
    // 802CDE10: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDE14:
    ctx->pc = 0x802CDE14u;
    // 802CDE14: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDE18:
    ctx->pc = 0x802CDE18u;
    ctx->downcount -= 16;
    // 802CDE18: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDE1C:
    ctx->pc = 0x802CDE1Cu;
    // 802CDE1C: rlwinm r0, r5, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 5u) & 0xFFFFFFE0u;
    }

label_802CDE20:
    ctx->pc = 0x802CDE20u;
    // 802CDE20: rlwinm r4, r4, 0, 27, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFDFu;
    }

label_802CDE24:
    ctx->pc = 0x802CDE24u;
    // 802CDE24: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDE28:
    ctx->pc = 0x802CDE28u;
    // 802CDE28: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDE2C:
    ctx->pc = 0x802CDE2Cu;
    // 802CDE2C: rlwinm r4, r6, 6, 0, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_802CDE30:
    ctx->pc = 0x802CDE30u;
    // 802CDE30: rlwinm r0, r7, 9, 15, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 9u) & 0x0001FE00u;
    }

label_802CDE34:
    ctx->pc = 0x802CDE34u;
    // 802CDE34: lwz     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDE38:
    ctx->pc = 0x802CDE38u;
    // 802CDE38: rlwinm r5, r5, 0, 26, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFE3Fu;
    }

label_802CDE3C:
    ctx->pc = 0x802CDE3Cu;
    // 802CDE3C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_802CDE40:
    ctx->pc = 0x802CDE40u;
    // 802CDE40: stw     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CDE44:
    ctx->pc = 0x802CDE44u;
    // 802CDE44: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDE48:
    ctx->pc = 0x802CDE48u;
    // 802CDE48: rlwinm r4, r4, 0, 23, 17
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFC1FFu;
    }

label_802CDE4C:
    ctx->pc = 0x802CDE4Cu;
    // 802CDE4C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDE50:
    ctx->pc = 0x802CDE50u;
    // 802CDE50: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDE54:
    ctx->pc = 0x802CDE54u;
    // 802CDE54: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDE58:
    ctx->pc = 0x802CDE58u;
    ctx->downcount -= 16;
    // 802CDE58: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDE5C:
    ctx->pc = 0x802CDE5Cu;
    // 802CDE5C: rlwinm r0, r5, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 14u) & 0xFFFFC000u;
    }

label_802CDE60:
    ctx->pc = 0x802CDE60u;
    // 802CDE60: rlwinm r4, r4, 0, 18, 16
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFBFFFu;
    }

label_802CDE64:
    ctx->pc = 0x802CDE64u;
    // 802CDE64: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDE68:
    ctx->pc = 0x802CDE68u;
    // 802CDE68: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDE6C:
    ctx->pc = 0x802CDE6Cu;
    // 802CDE6C: rlwinm r4, r6, 15, 0, 16
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 15u) & 0xFFFF8000u;
    }

label_802CDE70:
    ctx->pc = 0x802CDE70u;
    // 802CDE70: rlwinm r0, r7, 18, 6, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 18u) & 0x03FC0000u;
    }

label_802CDE74:
    ctx->pc = 0x802CDE74u;
    // 802CDE74: lwz     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDE78:
    ctx->pc = 0x802CDE78u;
    // 802CDE78: rlwinm r5, r5, 0, 17, 13
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFC7FFFu;
    }

label_802CDE7C:
    ctx->pc = 0x802CDE7Cu;
    // 802CDE7C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_802CDE80:
    ctx->pc = 0x802CDE80u;
    // 802CDE80: stw     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CDE84:
    ctx->pc = 0x802CDE84u;
    // 802CDE84: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDE88:
    ctx->pc = 0x802CDE88u;
    // 802CDE88: rlwinm r4, r4, 0, 14, 8
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF83FFFFu;
    }

label_802CDE8C:
    ctx->pc = 0x802CDE8Cu;
    // 802CDE8C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDE90:
    ctx->pc = 0x802CDE90u;
    // 802CDE90: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDE94:
    ctx->pc = 0x802CDE94u;
    // 802CDE94: b       0x802CDED0
    {
            goto label_802CDED0;
    }

label_802CDE98:
    ctx->pc = 0x802CDE98u;
    ctx->downcount -= 14;
    // 802CDE98: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDE9C:
    ctx->pc = 0x802CDE9Cu;
    // 802CDE9C: rlwinm r0, r5, 23, 0, 8
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 23u) & 0xFF800000u;
    }

label_802CDEA0:
    ctx->pc = 0x802CDEA0u;
    // 802CDEA0: rlwinm r4, r4, 0, 9, 7
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF7FFFFFu;
    }

label_802CDEA4:
    ctx->pc = 0x802CDEA4u;
    // 802CDEA4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDEA8:
    ctx->pc = 0x802CDEA8u;
    // 802CDEA8: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDEAC:
    ctx->pc = 0x802CDEACu;
    // 802CDEAC: rlwinm r0, r6, 24, 0, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0xFF000000u;
    }

label_802CDEB0:
    ctx->pc = 0x802CDEB0u;
    // 802CDEB0: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDEB4:
    ctx->pc = 0x802CDEB4u;
    // 802CDEB4: rlwinm r4, r4, 0, 8, 4
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xF8FFFFFFu;
    }

label_802CDEB8:
    ctx->pc = 0x802CDEB8u;
    // 802CDEB8: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CDEBC:
    ctx->pc = 0x802CDEBCu;
    // 802CDEBC: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDEC0:
    ctx->pc = 0x802CDEC0u;
    // 802CDEC0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDEC4:
    ctx->pc = 0x802CDEC4u;
    // 802CDEC4: rlwinm r0, r0, 0, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x07FFFFFFu;
    }

label_802CDEC8:
    ctx->pc = 0x802CDEC8u;
    // 802CDEC8: rlwimi r0, r7, 27, 0, 4
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 27u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xF8000000u) | (rot & 0xF8000000u);
    }

label_802CDECC:
    ctx->pc = 0x802CDECCu;
    // 802CDECC: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDED0:
    ctx->pc = 0x802CDED0u;
    ctx->downcount -= 12;
    // 802CDED0: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CDED4:
    ctx->pc = 0x802CDED4u;
    // 802CDED4: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_802CDED8:
    ctx->pc = 0x802CDED8u;
    // 802CDED8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CDEDC:
    ctx->pc = 0x802CDEDCu;
    // 802CDEDC: lwz     r4, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CDEE0:
    ctx->pc = 0x802CDEE0u;
    // 802CDEE0: slw   r0, r3, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[3] << sh);
    }

label_802CDEE4:
    ctx->pc = 0x802CDEE4u;
    // 802CDEE4: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_802CDEE8:
    ctx->pc = 0x802CDEE8u;
    // 802CDEE8: ori     r3, r4, 0x0010
    ctx->gpr[3] = ctx->gpr[4] | 0x0010u;

label_802CDEEC:
    ctx->pc = 0x802CDEECu;
    // 802CDEEC: stw     r3, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CDEF0:
    ctx->pc = 0x802CDEF0u;
    // 802CDEF0: lbz     r3, 1267(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1267);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_802CDEF4:
    ctx->pc = 0x802CDEF4u;
    // 802CDEF4: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CDEF8:
    ctx->pc = 0x802CDEF8u;
    // 802CDEF8: stb     r0, 1267(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1267);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CDEFC:
    ctx->pc = 0x802CDEFCu;
    // 802CDEFC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CDF00:
    ctx->pc = 0x802CDF00u;
    ctx->downcount -= 9;
    // 802CDF00: lwz     r6, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CDF04:
    ctx->pc = 0x802CDF04u;
    // 802CDF04: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_802CDF08:
    ctx->pc = 0x802CDF08u;
    // 802CDF08: lis     r5, -32715
    ctx->gpr[5] = ((u32)(s32)(-32715) << 16);

label_802CDF0C:
    ctx->pc = 0x802CDF0Cu;
    // 802CDF0C: add   r6, r6, r0
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_802CDF10:
    ctx->pc = 0x802CDF10u;
    // 802CDF10: addi    r8, r6, 28
    ctx->gpr[8] = ctx->gpr[6] + (u32)(s32)(28);

label_802CDF14:
    ctx->pc = 0x802CDF14u;
    // 802CDF14: addi    r9, r6, 60
    ctx->gpr[9] = ctx->gpr[6] + (u32)(s32)(60);

label_802CDF18:
    ctx->pc = 0x802CDF18u;
    // 802CDF18: addi    r10, r6, 92
    ctx->gpr[10] = ctx->gpr[6] + (u32)(s32)(92);

label_802CDF1C:
    ctx->pc = 0x802CDF1Cu;
    // 802CDF1C: addi    r5, r5, 32060
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(32060);

label_802CDF20:
    ctx->pc = 0x802CDF20u;
    // 802CDF20: b       0x802CE23C
    {
            goto label_802CE23C;
    }

label_802CDF24:
    ctx->pc = 0x802CDF24u;
    ctx->downcount -= 7;
    // 802CDF24: lwz     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CDF28:
    ctx->pc = 0x802CDF28u;
    // 802CDF28: lbz     r7, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_802CDF2C:
    // 802CDF2C: addi    r11, r6, -9
    ctx->gpr[11] = ctx->gpr[6] + (u32)(s32)(-9);

label_802CDF30:
    ctx->pc = 0x802CDF30u;
    // 802CDF30: lwz     r6, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CDF34:
    // 802CDF34: cmplwi  r11, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CDF38:
    ctx->pc = 0x802CDF38u;
    // 802CDF38: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDF3C:
    // 802CDF3C: bc    12, 1, 0x802CE238
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CE238;
        }
    }

label_802CDF40:
    ctx->downcount -= 5;
    // 802CDF40: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_802CDF44:
    ctx->pc = 0x802CDF44u;
    // 802CDF44: lwzx    r11, r5, r11
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[11];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_802CDF48:
    ctx->pc = 0x802CDF48u;
    // 802CDF48: mtctr    r11
    ctx->ctr = ctx->gpr[11];

label_802CDF4C:
    ctx->pc = 0x802CDF4Cu;
    // 802CDF4C: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_802CDF50:
    ctx->pc = 0x802CDF50u;
    ctx->downcount -= 15;
    // 802CDF50: lwz     r12, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802CDF54:
    // 802CDF54: rlwinm r11, r6, 1, 0, 30
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_802CDF58:
    // 802CDF58: rlwinm r6, r7, 4, 0, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0xFFFFFFF0u;
    }

label_802CDF5C:
    // 802CDF5C: rlwinm r7, r12, 0, 0, 30
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xFFFFFFFEu;
    }

label_802CDF60:
    // 802CDF60: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_802CDF64:
    ctx->pc = 0x802CDF64u;
    // 802CDF64: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDF68:
    ctx->pc = 0x802CDF68u;
    // 802CDF68: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDF6C:
    // 802CDF6C: rlwinm r0, r0, 0, 31, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF1u;
    }

label_802CDF70:
    // 802CDF70: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_802CDF74:
    ctx->pc = 0x802CDF74u;
    // 802CDF74: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDF78:
    ctx->pc = 0x802CDF78u;
    // 802CDF78: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDF7C:
    // 802CDF7C: rlwinm r0, r0, 0, 28, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFE0Fu;
    }

label_802CDF80:
    // 802CDF80: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_802CDF84:
    ctx->pc = 0x802CDF84u;
    // 802CDF84: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDF88:
    // 802CDF88: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CDF8C:
    ctx->pc = 0x802CDF8Cu;
    ctx->downcount -= 7;
    // 802CDF8C: lwz     r7, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CDF90:
    // 802CDF90: rlwinm r6, r6, 10, 0, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_802CDF94:
    // 802CDF94: cmpwi   r0, 2
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CDF98:
    // 802CDF98: rlwinm r7, r7, 0, 22, 18
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFE3FFu;
    }

label_802CDF9C:
    // 802CDF9C: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_802CDFA0:
    ctx->pc = 0x802CDFA0u;
    // 802CDFA0: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CDFA4:
    // 802CDFA4: bc    4, 2, 0x802CDFCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CDFCC;
        }
    }

label_802CDFA8:
    ctx->pc = 0x802CDFA8u;
    ctx->downcount -= 9;
    // 802CDFA8: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDFAC:
    // 802CDFAC: rlwinm r0, r0, 0, 23, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFDFFu;
    }

label_802CDFB0:
    // 802CDFB0: ori     r0, r0, 0x0200
    ctx->gpr[0] = ctx->gpr[0] | 0x0200u;

label_802CDFB4:
    ctx->pc = 0x802CDFB4u;
    // 802CDFB4: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDFB8:
    ctx->pc = 0x802CDFB8u;
    // 802CDFB8: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDFBC:
    // 802CDFBC: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_802CDFC0:
    // 802CDFC0: oris    r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] | (0x8000u << 16);

label_802CDFC4:
    ctx->pc = 0x802CDFC4u;
    // 802CDFC4: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDFC8:
    // 802CDFC8: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CDFCC:
    ctx->pc = 0x802CDFCCu;
    ctx->downcount -= 9;
    // 802CDFCC: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CDFD0:
    // 802CDFD0: rlwinm r0, r0, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0xFFFFFE00u;
    }

label_802CDFD4:
    // 802CDFD4: rlwinm r6, r6, 0, 23, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFDFFu;
    }

label_802CDFD8:
    // 802CDFD8: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CDFDC:
    ctx->pc = 0x802CDFDCu;
    // 802CDFDC: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDFE0:
    ctx->pc = 0x802CDFE0u;
    // 802CDFE0: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CDFE4:
    // 802CDFE4: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_802CDFE8:
    ctx->pc = 0x802CDFE8u;
    // 802CDFE8: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CDFEC:
    // 802CDFEC: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CDFF0:
    ctx->pc = 0x802CDFF0u;
    ctx->downcount -= 11;
    // 802CDFF0: lwz     r11, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_802CDFF4:
    // 802CDFF4: rlwinm r7, r0, 13, 0, 18
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 13u) & 0xFFFFE000u;
    }

label_802CDFF8:
    // 802CDFF8: rlwinm r0, r6, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 14u) & 0xFFFFC000u;
    }

label_802CDFFC:
    // 802CDFFC: rlwinm r6, r11, 0, 19, 17
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFDFFFu;
    }

label_802CE000:
    // 802CE000: or   r6, r6, r7
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[7];
    }

label_802CE004:
    ctx->pc = 0x802CE004u;
    // 802CE004: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CE008:
    ctx->pc = 0x802CE008u;
    // 802CE008: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CE00C:
    // 802CE00C: rlwinm r6, r6, 0, 18, 14
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFE3FFFu;
    }

label_802CE010:
    // 802CE010: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CE014:
    ctx->pc = 0x802CE014u;
    // 802CE014: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE018:
    // 802CE018: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CE01C:
    ctx->pc = 0x802CE01Cu;
    ctx->downcount -= 11;
    // 802CE01C: lwz     r11, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_802CE020:
    // 802CE020: rlwinm r7, r0, 17, 0, 14
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0xFFFE0000u;
    }

label_802CE024:
    // 802CE024: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_802CE028:
    // 802CE028: rlwinm r6, r11, 0, 15, 13
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFDFFFFu;
    }

label_802CE02C:
    // 802CE02C: or   r6, r6, r7
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[7];
    }

label_802CE030:
    ctx->pc = 0x802CE030u;
    // 802CE030: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CE034:
    ctx->pc = 0x802CE034u;
    // 802CE034: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CE038:
    // 802CE038: rlwinm r6, r6, 0, 14, 10
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFE3FFFFu;
    }

label_802CE03C:
    // 802CE03C: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CE040:
    ctx->pc = 0x802CE040u;
    // 802CE040: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE044:
    // 802CE044: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CE048:
    ctx->pc = 0x802CE048u;
    ctx->downcount -= 16;
    // 802CE048: lwz     r11, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_802CE04C:
    // 802CE04C: rlwinm r0, r0, 21, 0, 10
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 21u) & 0xFFE00000u;
    }

label_802CE050:
    // 802CE050: rlwinm r6, r6, 22, 0, 9
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 22u) & 0xFFC00000u;
    }

label_802CE054:
    // 802CE054: rlwinm r11, r11, 0, 11, 9
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFDFFFFFu;
    }

label_802CE058:
    // 802CE058: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_802CE05C:
    ctx->pc = 0x802CE05Cu;
    // 802CE05C: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE060:
    // 802CE060: rlwinm r0, r7, 25, 0, 6
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 25u) & 0xFE000000u;
    }

label_802CE064:
    ctx->pc = 0x802CE064u;
    // 802CE064: lwz     r7, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CE068:
    // 802CE068: rlwinm r7, r7, 0, 10, 6
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFE3FFFFFu;
    }

label_802CE06C:
    // 802CE06C: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_802CE070:
    ctx->pc = 0x802CE070u;
    // 802CE070: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CE074:
    ctx->pc = 0x802CE074u;
    // 802CE074: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CE078:
    // 802CE078: rlwinm r6, r6, 0, 7, 1
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xC1FFFFFFu;
    }

label_802CE07C:
    // 802CE07C: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CE080:
    ctx->pc = 0x802CE080u;
    // 802CE080: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE084:
    // 802CE084: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CE088:
    ctx->pc = 0x802CE088u;
    ctx->downcount -= 15;
    // 802CE088: lwz     r12, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802CE08C:
    // 802CE08C: rlwinm r11, r6, 1, 0, 30
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_802CE090:
    // 802CE090: rlwinm r6, r7, 4, 0, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0xFFFFFFF0u;
    }

label_802CE094:
    // 802CE094: rlwinm r7, r12, 0, 0, 30
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xFFFFFFFEu;
    }

label_802CE098:
    // 802CE098: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_802CE09C:
    ctx->pc = 0x802CE09Cu;
    // 802CE09C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE0A0:
    ctx->pc = 0x802CE0A0u;
    // 802CE0A0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE0A4:
    // 802CE0A4: rlwinm r0, r0, 0, 31, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF1u;
    }

label_802CE0A8:
    // 802CE0A8: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_802CE0AC:
    ctx->pc = 0x802CE0ACu;
    // 802CE0AC: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE0B0:
    ctx->pc = 0x802CE0B0u;
    // 802CE0B0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE0B4:
    // 802CE0B4: rlwinm r0, r0, 0, 28, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFE0Fu;
    }

label_802CE0B8:
    // 802CE0B8: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_802CE0BC:
    ctx->pc = 0x802CE0BCu;
    // 802CE0BC: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE0C0:
    // 802CE0C0: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CE0C4:
    ctx->pc = 0x802CE0C4u;
    ctx->downcount -= 16;
    // 802CE0C4: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_802CE0C8:
    // 802CE0C8: rlwinm r0, r0, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0xFFFFFE00u;
    }

label_802CE0CC:
    // 802CE0CC: rlwinm r6, r6, 10, 0, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_802CE0D0:
    // 802CE0D0: rlwinm r11, r11, 0, 23, 21
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFFDFFu;
    }

label_802CE0D4:
    // 802CE0D4: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_802CE0D8:
    ctx->pc = 0x802CE0D8u;
    // 802CE0D8: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE0DC:
    // 802CE0DC: rlwinm r0, r7, 13, 0, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 13u) & 0xFFFFE000u;
    }

label_802CE0E0:
    ctx->pc = 0x802CE0E0u;
    // 802CE0E0: lwz     r7, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CE0E4:
    // 802CE0E4: rlwinm r7, r7, 0, 22, 18
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFE3FFu;
    }

label_802CE0E8:
    // 802CE0E8: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_802CE0EC:
    ctx->pc = 0x802CE0ECu;
    // 802CE0EC: stw     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CE0F0:
    ctx->pc = 0x802CE0F0u;
    // 802CE0F0: lwz     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CE0F4:
    // 802CE0F4: rlwinm r6, r6, 0, 19, 13
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFC1FFFu;
    }

label_802CE0F8:
    // 802CE0F8: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CE0FC:
    ctx->pc = 0x802CE0FCu;
    // 802CE0FC: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE100:
    // 802CE100: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CE104:
    ctx->pc = 0x802CE104u;
    ctx->downcount -= 16;
    // 802CE104: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_802CE108:
    // 802CE108: rlwinm r0, r0, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 18u) & 0xFFFC0000u;
    }

label_802CE10C:
    // 802CE10C: rlwinm r6, r6, 19, 0, 12
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 19u) & 0xFFF80000u;
    }

label_802CE110:
    // 802CE110: rlwinm r11, r11, 0, 14, 12
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFBFFFFu;
    }

label_802CE114:
    // 802CE114: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_802CE118:
    ctx->pc = 0x802CE118u;
    // 802CE118: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE11C:
    // 802CE11C: rlwinm r0, r7, 22, 0, 9
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 22u) & 0xFFC00000u;
    }

label_802CE120:
    ctx->pc = 0x802CE120u;
    // 802CE120: lwz     r7, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CE124:
    // 802CE124: rlwinm r7, r7, 0, 13, 9
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFC7FFFFu;
    }

label_802CE128:
    // 802CE128: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_802CE12C:
    ctx->pc = 0x802CE12Cu;
    // 802CE12C: stw     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CE130:
    ctx->pc = 0x802CE130u;
    // 802CE130: lwz     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CE134:
    // 802CE134: rlwinm r6, r6, 0, 10, 4
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xF83FFFFFu;
    }

label_802CE138:
    // 802CE138: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CE13C:
    ctx->pc = 0x802CE13Cu;
    // 802CE13C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE140:
    // 802CE140: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CE144:
    ctx->pc = 0x802CE144u;
    ctx->downcount -= 15;
    // 802CE144: lwz     r12, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802CE148:
    // 802CE148: rlwinm r11, r0, 27, 0, 4
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0xF8000000u;
    }

label_802CE14C:
    // 802CE14C: rlwinm r0, r6, 28, 0, 3
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 28u) & 0xF0000000u;
    }

label_802CE150:
    // 802CE150: rlwinm r6, r12, 0, 5, 3
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xF7FFFFFFu;
    }

label_802CE154:
    // 802CE154: or   r6, r6, r11
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[11];
    }

label_802CE158:
    ctx->pc = 0x802CE158u;
    // 802CE158: stw     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CE15C:
    ctx->pc = 0x802CE15Cu;
    // 802CE15C: lwz     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CE160:
    // 802CE160: rlwinm r6, r6, 0, 4, 0
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x8FFFFFFFu;
    }

label_802CE164:
    // 802CE164: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CE168:
    ctx->pc = 0x802CE168u;
    // 802CE168: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE16C:
    ctx->pc = 0x802CE16Cu;
    // 802CE16C: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE170:
    // 802CE170: rlwinm r0, r0, 0, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFE0u;
    }

label_802CE174:
    // 802CE174: or   r0, r0, r7
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[7];
    }

label_802CE178:
    ctx->pc = 0x802CE178u;
    // 802CE178: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE17C:
    // 802CE17C: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CE180:
    ctx->pc = 0x802CE180u;
    ctx->downcount -= 16;
    // 802CE180: lwz     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_802CE184:
    // 802CE184: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_802CE188:
    // 802CE188: rlwinm r6, r6, 6, 0, 25
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_802CE18C:
    // 802CE18C: rlwinm r11, r11, 0, 27, 25
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFFFDFu;
    }

label_802CE190:
    // 802CE190: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_802CE194:
    ctx->pc = 0x802CE194u;
    // 802CE194: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE198:
    // 802CE198: rlwinm r0, r7, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 9u) & 0xFFFFFE00u;
    }

label_802CE19C:
    ctx->pc = 0x802CE19Cu;
    // 802CE19C: lwz     r7, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CE1A0:
    // 802CE1A0: rlwinm r7, r7, 0, 26, 22
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFE3Fu;
    }

label_802CE1A4:
    // 802CE1A4: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_802CE1A8:
    ctx->pc = 0x802CE1A8u;
    // 802CE1A8: stw     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CE1AC:
    ctx->pc = 0x802CE1ACu;
    // 802CE1AC: lwz     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CE1B0:
    // 802CE1B0: rlwinm r6, r6, 0, 23, 17
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFC1FFu;
    }

label_802CE1B4:
    // 802CE1B4: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CE1B8:
    ctx->pc = 0x802CE1B8u;
    // 802CE1B8: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE1BC:
    // 802CE1BC: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CE1C0:
    ctx->pc = 0x802CE1C0u;
    ctx->downcount -= 16;
    // 802CE1C0: lwz     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_802CE1C4:
    // 802CE1C4: rlwinm r0, r0, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0xFFFFC000u;
    }

label_802CE1C8:
    // 802CE1C8: rlwinm r6, r6, 15, 0, 16
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 15u) & 0xFFFF8000u;
    }

label_802CE1CC:
    // 802CE1CC: rlwinm r11, r11, 0, 18, 16
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFBFFFu;
    }

label_802CE1D0:
    // 802CE1D0: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_802CE1D4:
    ctx->pc = 0x802CE1D4u;
    // 802CE1D4: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE1D8:
    // 802CE1D8: rlwinm r0, r7, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 18u) & 0xFFFC0000u;
    }

label_802CE1DC:
    ctx->pc = 0x802CE1DCu;
    // 802CE1DC: lwz     r7, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CE1E0:
    // 802CE1E0: rlwinm r7, r7, 0, 17, 13
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFC7FFFu;
    }

label_802CE1E4:
    // 802CE1E4: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_802CE1E8:
    ctx->pc = 0x802CE1E8u;
    // 802CE1E8: stw     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CE1EC:
    ctx->pc = 0x802CE1ECu;
    // 802CE1EC: lwz     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CE1F0:
    // 802CE1F0: rlwinm r6, r6, 0, 14, 8
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFF83FFFFu;
    }

label_802CE1F4:
    // 802CE1F4: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CE1F8:
    ctx->pc = 0x802CE1F8u;
    // 802CE1F8: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE1FC:
    // 802CE1FC: b       0x802CE238
    {
            goto label_802CE238;
    }

label_802CE200:
    ctx->pc = 0x802CE200u;
    ctx->downcount -= 14;
    // 802CE200: lwz     r12, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802CE204:
    // 802CE204: rlwinm r11, r0, 23, 0, 8
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0xFF800000u;
    }

label_802CE208:
    // 802CE208: rlwinm r0, r6, 24, 0, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0xFF000000u;
    }

label_802CE20C:
    // 802CE20C: rlwinm r6, r12, 0, 9, 7
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xFF7FFFFFu;
    }

label_802CE210:
    // 802CE210: or   r6, r6, r11
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[11];
    }

label_802CE214:
    ctx->pc = 0x802CE214u;
    // 802CE214: stw     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CE218:
    ctx->pc = 0x802CE218u;
    // 802CE218: lwz     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CE21C:
    // 802CE21C: rlwinm r6, r6, 0, 8, 4
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xF8FFFFFFu;
    }

label_802CE220:
    // 802CE220: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CE224:
    ctx->pc = 0x802CE224u;
    // 802CE224: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE228:
    ctx->pc = 0x802CE228u;
    // 802CE228: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE22C:
    // 802CE22C: rlwinm r0, r0, 0, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x07FFFFFFu;
    }

label_802CE230:
    // 802CE230: rlwimi r0, r7, 27, 0, 4
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 27u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xF8000000u) | (rot & 0xF8000000u);
    }

label_802CE234:
    ctx->pc = 0x802CE234u;
    // 802CE234: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE238:
    ctx->downcount -= 1;
    // 802CE238: addi    r4, r4, 16
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(16);

label_802CE23C:
    ctx->pc = 0x802CE23Cu;
    ctx->downcount -= 3;
    // 802CE23C: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE240:
    // 802CE240: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE244:
    // 802CE244: bc    4, 2, 0x802CDF24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CDF24u;
                return;
            }
            goto label_802CDF24;
        }
    }

label_802CE248:
    ctx->pc = 0x802CE248u;
    ctx->downcount -= 12;
    // 802CE248: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CE24C:
    ctx->pc = 0x802CE24Cu;
    // 802CE24C: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_802CE250:
    ctx->pc = 0x802CE250u;
    // 802CE250: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CE254:
    ctx->pc = 0x802CE254u;
    // 802CE254: lwz     r4, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE258:
    ctx->pc = 0x802CE258u;
    // 802CE258: slw   r0, r3, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[3] << sh);
    }

label_802CE25C:
    ctx->pc = 0x802CE25Cu;
    // 802CE25C: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_802CE260:
    ctx->pc = 0x802CE260u;
    // 802CE260: ori     r3, r4, 0x0010
    ctx->gpr[3] = ctx->gpr[4] | 0x0010u;

label_802CE264:
    ctx->pc = 0x802CE264u;
    // 802CE264: stw     r3, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CE268:
    ctx->pc = 0x802CE268u;
    // 802CE268: lbz     r3, 1267(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1267);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_802CE26C:
    ctx->pc = 0x802CE26Cu;
    // 802CE26C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CE270:
    ctx->pc = 0x802CE270u;
    // 802CE270: stb     r0, 1267(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1267);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE274:
    ctx->pc = 0x802CE274u;
    // 802CE274: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE278:
    ctx->pc = 0x802CE278u;
    ctx->downcount -= 5;
    // 802CE278: lwz     r10, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_802CE27C:
    ctx->pc = 0x802CE27Cu;
    // 802CE27C: li      r12, 0
    ctx->gpr[12] = (u32)(s32)(0);

label_802CE280:
    ctx->pc = 0x802CE280u;
    // 802CE280: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_802CE284:
    ctx->pc = 0x802CE284u;
    // 802CE284: lis     r7, -13311
    ctx->gpr[7] = ((u32)(s32)(-13311) << 16);

label_802CE288:
    ctx->pc = 0x802CE288u;
    // 802CE288: b       0x802CE2F8
    {
            goto label_802CE2F8;
    }

label_802CE28C:
    ctx->downcount -= 6;
    // 802CE28C: rlwinm r9, r12, 0, 24, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0x000000FFu;
    }

label_802CE290:
    ctx->pc = 0x802CE290u;
    // 802CE290: lbz     r3, 1267(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(1267);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_802CE294:
    // 802CE294: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802CE298:
    // 802CE298: slw   r0, r0, r9
    {
        u32 sh = ctx->gpr[9] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] << sh);
    }

label_802CE29C:
    // 802CE29C: and.   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CE2A0:
    // 802CE2A0: bc    12, 2, 0x802CE2F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CE2F0;
        }
    }

label_802CE2A4:
    ctx->downcount -= 19;
    // 802CE2A4: li      r8, 8
    ctx->gpr[8] = (u32)(s32)(8);

label_802CE2A8:
    ctx->pc = 0x802CE2A8u;
    // 802CE2A8: stb     r8, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_802CE2AC:
    // 802CE2AC: ori     r3, r9, 0x0070
    ctx->gpr[3] = ctx->gpr[9] | 0x0070u;

label_802CE2B0:
    // 802CE2B0: addi    r0, r11, 28
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(28);

label_802CE2B4:
    ctx->pc = 0x802CE2B4u;
    // 802CE2B4: stb     r3, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_802CE2B8:
    // 802CE2B8: ori     r5, r9, 0x0080
    ctx->gpr[5] = ctx->gpr[9] | 0x0080u;

label_802CE2BC:
    // 802CE2BC: addi    r4, r11, 60
    ctx->gpr[4] = ctx->gpr[11] + (u32)(s32)(60);

label_802CE2C0:
    ctx->pc = 0x802CE2C0u;
    // 802CE2C0: lwzx    r6, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CE2C4:
    // 802CE2C4: ori     r3, r9, 0x0090
    ctx->gpr[3] = ctx->gpr[9] | 0x0090u;

label_802CE2C8:
    // 802CE2C8: addi    r0, r11, 92
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(92);

label_802CE2CC:
    ctx->pc = 0x802CE2CCu;
    // 802CE2CC: stw     r6, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802CE2D0:
    ctx->pc = 0x802CE2D0u;
    // 802CE2D0: stb     r8, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_802CE2D4:
    ctx->pc = 0x802CE2D4u;
    // 802CE2D4: stb     r5, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_802CE2D8:
    ctx->pc = 0x802CE2D8u;
    // 802CE2D8: lwzx    r4, r10, r4
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[4];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE2DC:
    ctx->pc = 0x802CE2DCu;
    // 802CE2DC: stw     r4, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CE2E0:
    ctx->pc = 0x802CE2E0u;
    // 802CE2E0: stb     r8, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_802CE2E4:
    ctx->pc = 0x802CE2E4u;
    // 802CE2E4: stb     r3, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_802CE2E8:
    ctx->pc = 0x802CE2E8u;
    // 802CE2E8: lwzx    r0, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE2EC:
    ctx->pc = 0x802CE2ECu;
    // 802CE2EC: stw     r0, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE2F0:
    ctx->downcount -= 2;
    // 802CE2F0: addi    r11, r11, 4
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4);

label_802CE2F4:
    // 802CE2F4: addi    r12, r12, 1
    ctx->gpr[12] = ctx->gpr[12] + (u32)(s32)(1);

label_802CE2F8:
    ctx->downcount -= 3;
    // 802CE2F8: rlwinm r0, r12, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0x000000FFu;
    }

label_802CE2FC:
    // 802CE2FC: cmplwi  r0, 0x0008
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0008u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE300:
    // 802CE300: bc    12, 0, 0x802CE28C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CE28Cu;
                return;
            }
            goto label_802CE28C;
        }
    }

label_802CE304:
    ctx->pc = 0x802CE304u;
    ctx->downcount -= 4;
    // 802CE304: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CE308:
    ctx->pc = 0x802CE308u;
    // 802CE308: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CE30C:
    ctx->pc = 0x802CE30Cu;
    // 802CE30C: stb     r0, 1267(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1267);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE310:
    ctx->pc = 0x802CE310u;
    // 802CE310: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE314:
    ctx->pc = 0x802CE314u;
    ctx->downcount -= 9;
    // 802CE314: addi    r0, r4, -9
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-9);

label_802CE318:
    ctx->pc = 0x802CE318u;
    // 802CE318: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE31C:
    ctx->pc = 0x802CE31Cu;
    // 802CE31C: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_802CE320:
    ctx->pc = 0x802CE320u;
    // 802CE320: add   r4, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_802CE324:
    ctx->pc = 0x802CE324u;
    // 802CE324: cmplwi  r0, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE328:
    ctx->pc = 0x802CE328u;
    // 802CE328: addi    r3, r4, 28
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(28);

label_802CE32C:
    ctx->pc = 0x802CE32Cu;
    // 802CE32C: addi    r8, r4, 60
    ctx->gpr[8] = ctx->gpr[4] + (u32)(s32)(60);

label_802CE330:
    ctx->pc = 0x802CE330u;
    // 802CE330: addi    r9, r4, 92
    ctx->gpr[9] = ctx->gpr[4] + (u32)(s32)(92);

label_802CE334:
    ctx->pc = 0x802CE334u;
    // 802CE334: bc    12, 1, 0x802CE57C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CE57C;
        }
    }

label_802CE338:
    ctx->pc = 0x802CE338u;
    ctx->downcount -= 7;
    // 802CE338: lis     r4, -32715
    ctx->gpr[4] = ((u32)(s32)(-32715) << 16);

label_802CE33C:
    ctx->pc = 0x802CE33Cu;
    // 802CE33C: addi    r4, r4, 32128
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(32128);

label_802CE340:
    ctx->pc = 0x802CE340u;
    // 802CE340: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_802CE344:
    ctx->pc = 0x802CE344u;
    // 802CE344: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE348:
    ctx->pc = 0x802CE348u;
    // 802CE348: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802CE34C:
    ctx->pc = 0x802CE34Cu;
    // 802CE34C: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_802CE350:
    ctx->pc = 0x802CE350u;
    ctx->downcount -= 10;
    // 802CE350: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE354:
    ctx->pc = 0x802CE354u;
    // 802CE354: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_802CE358:
    ctx->pc = 0x802CE358u;
    // 802CE358: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE35C:
    ctx->pc = 0x802CE35Cu;
    // 802CE35C: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE360:
    ctx->pc = 0x802CE360u;
    // 802CE360: rlwinm r0, r0, 31, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000007u;
    }

label_802CE364:
    ctx->pc = 0x802CE364u;
    // 802CE364: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE368:
    ctx->pc = 0x802CE368u;
    // 802CE368: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE36C:
    ctx->pc = 0x802CE36Cu;
    // 802CE36C: rlwinm r0, r0, 28, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x0000001Fu;
    }

label_802CE370:
    ctx->pc = 0x802CE370u;
    // 802CE370: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE374:
    ctx->pc = 0x802CE374u;
    // 802CE374: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE378:
    ctx->pc = 0x802CE378u;
    ctx->downcount -= 6;
    // 802CE378: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE37C:
    ctx->pc = 0x802CE37Cu;
    // 802CE37C: rlwinm r0, r0, 23, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x00000001u;
    }

label_802CE380:
    ctx->pc = 0x802CE380u;
    // 802CE380: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE384:
    ctx->pc = 0x802CE384u;
    // 802CE384: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE388:
    ctx->pc = 0x802CE388u;
    // 802CE388: cmpwi   r0, 1
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

label_802CE38C:
    ctx->pc = 0x802CE38Cu;
    // 802CE38C: bc    4, 2, 0x802CE3A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE3A4;
        }
    }

label_802CE390:
    ctx->pc = 0x802CE390u;
    ctx->downcount -= 3;
    // 802CE390: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE394:
    ctx->pc = 0x802CE394u;
    // 802CE394: rlwinm. r0, r0, 1, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CE398:
    ctx->pc = 0x802CE398u;
    // 802CE398: bc    12, 2, 0x802CE3A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CE3A4;
        }
    }

label_802CE39C:
    ctx->pc = 0x802CE39Cu;
    ctx->downcount -= 2;
    // 802CE39C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_802CE3A0:
    ctx->pc = 0x802CE3A0u;
    // 802CE3A0: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE3A4:
    ctx->pc = 0x802CE3A4u;
    ctx->downcount -= 6;
    // 802CE3A4: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE3A8:
    ctx->pc = 0x802CE3A8u;
    // 802CE3A8: rlwinm r0, r0, 22, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 22u) & 0x00000007u;
    }

label_802CE3AC:
    ctx->pc = 0x802CE3ACu;
    // 802CE3AC: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE3B0:
    ctx->pc = 0x802CE3B0u;
    // 802CE3B0: lwz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE3B4:
    ctx->pc = 0x802CE3B4u;
    // 802CE3B4: cmpwi   r0, 2
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE3B8:
    ctx->pc = 0x802CE3B8u;
    // 802CE3B8: bc    12, 2, 0x802CE3E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CE3E8;
        }
    }

label_802CE3BC:
    ctx->pc = 0x802CE3BCu;
    ctx->downcount -= 1;
    // 802CE3BC: bc    4, 0, 0x802CE3CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE3CC;
        }
    }

label_802CE3C0:
    ctx->pc = 0x802CE3C0u;
    ctx->downcount -= 2;
    // 802CE3C0: cmpwi   r0, 1
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

label_802CE3C4:
    ctx->pc = 0x802CE3C4u;
    // 802CE3C4: bc    4, 0, 0x802CE3D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE3D8;
        }
    }

label_802CE3C8:
    ctx->pc = 0x802CE3C8u;
    ctx->downcount -= 1;
    // 802CE3C8: b       0x802CE3E8
    {
            goto label_802CE3E8;
    }

label_802CE3CC:
    ctx->pc = 0x802CE3CCu;
    ctx->downcount -= 2;
    // 802CE3CC: cmpwi   r0, 4
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

label_802CE3D0:
    ctx->pc = 0x802CE3D0u;
    // 802CE3D0: bc    4, 0, 0x802CE3E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE3E8;
        }
    }

label_802CE3D4:
    ctx->pc = 0x802CE3D4u;
    ctx->downcount -= 1;
    // 802CE3D4: b       0x802CE3E0
    {
            goto label_802CE3E0;
    }

label_802CE3D8:
    ctx->pc = 0x802CE3D8u;
    ctx->downcount -= 2;
    // 802CE3D8: li      r0, 6
    ctx->gpr[0] = (u32)(s32)(6);

label_802CE3DC:
    ctx->pc = 0x802CE3DCu;
    // 802CE3DC: b       0x802CE3EC
    {
            goto label_802CE3EC;
    }

label_802CE3E0:
    ctx->pc = 0x802CE3E0u;
    ctx->downcount -= 2;
    // 802CE3E0: li      r0, 14
    ctx->gpr[0] = (u32)(s32)(14);

label_802CE3E4:
    ctx->pc = 0x802CE3E4u;
    // 802CE3E4: b       0x802CE3EC
    {
            goto label_802CE3EC;
    }

label_802CE3E8:
    ctx->pc = 0x802CE3E8u;
    ctx->downcount -= 1;
    // 802CE3E8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CE3EC:
    ctx->pc = 0x802CE3ECu;
    ctx->downcount -= 2;
    // 802CE3EC: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE3F0:
    ctx->pc = 0x802CE3F0u;
    // 802CE3F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE3F4:
    ctx->pc = 0x802CE3F4u;
    ctx->downcount -= 9;
    // 802CE3F4: lwz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE3F8:
    ctx->pc = 0x802CE3F8u;
    // 802CE3F8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CE3FC:
    ctx->pc = 0x802CE3FCu;
    // 802CE3FC: rlwinm r4, r4, 19, 31, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 19u) & 0x00000001u;
    }

label_802CE400:
    ctx->pc = 0x802CE400u;
    // 802CE400: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CE404:
    ctx->pc = 0x802CE404u;
    // 802CE404: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CE408:
    ctx->pc = 0x802CE408u;
    // 802CE408: rlwinm r3, r3, 18, 29, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 18u) & 0x00000007u;
    }

label_802CE40C:
    ctx->pc = 0x802CE40Cu;
    // 802CE40C: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CE410:
    ctx->pc = 0x802CE410u;
    // 802CE410: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE414:
    ctx->pc = 0x802CE414u;
    // 802CE414: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE418:
    ctx->pc = 0x802CE418u;
    ctx->downcount -= 9;
    // 802CE418: lwz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE41C:
    ctx->pc = 0x802CE41Cu;
    // 802CE41C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CE420:
    ctx->pc = 0x802CE420u;
    // 802CE420: rlwinm r4, r4, 15, 31, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 15u) & 0x00000001u;
    }

label_802CE424:
    ctx->pc = 0x802CE424u;
    // 802CE424: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CE428:
    ctx->pc = 0x802CE428u;
    // 802CE428: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CE42C:
    ctx->pc = 0x802CE42Cu;
    // 802CE42C: rlwinm r3, r3, 14, 29, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 14u) & 0x00000007u;
    }

label_802CE430:
    ctx->pc = 0x802CE430u;
    // 802CE430: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CE434:
    ctx->pc = 0x802CE434u;
    // 802CE434: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE438:
    ctx->pc = 0x802CE438u;
    // 802CE438: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE43C:
    ctx->pc = 0x802CE43Cu;
    ctx->downcount -= 10;
    // 802CE43C: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE440:
    ctx->pc = 0x802CE440u;
    // 802CE440: rlwinm r0, r0, 11, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 11u) & 0x00000001u;
    }

label_802CE444:
    ctx->pc = 0x802CE444u;
    // 802CE444: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE448:
    ctx->pc = 0x802CE448u;
    // 802CE448: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE44C:
    ctx->pc = 0x802CE44Cu;
    // 802CE44C: rlwinm r0, r0, 10, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0x00000007u;
    }

label_802CE450:
    ctx->pc = 0x802CE450u;
    // 802CE450: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE454:
    ctx->pc = 0x802CE454u;
    // 802CE454: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE458:
    ctx->pc = 0x802CE458u;
    // 802CE458: rlwinm r0, r0, 7, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 7u) & 0x0000001Fu;
    }

label_802CE45C:
    ctx->pc = 0x802CE45Cu;
    // 802CE45C: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE460:
    ctx->pc = 0x802CE460u;
    // 802CE460: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE464:
    ctx->pc = 0x802CE464u;
    ctx->downcount -= 10;
    // 802CE464: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE468:
    ctx->pc = 0x802CE468u;
    // 802CE468: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_802CE46C:
    ctx->pc = 0x802CE46Cu;
    // 802CE46C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE470:
    ctx->pc = 0x802CE470u;
    // 802CE470: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE474:
    ctx->pc = 0x802CE474u;
    // 802CE474: rlwinm r0, r0, 31, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000007u;
    }

label_802CE478:
    ctx->pc = 0x802CE478u;
    // 802CE478: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE47C:
    ctx->pc = 0x802CE47Cu;
    // 802CE47C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE480:
    ctx->pc = 0x802CE480u;
    // 802CE480: rlwinm r0, r0, 28, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x0000001Fu;
    }

label_802CE484:
    ctx->pc = 0x802CE484u;
    // 802CE484: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE488:
    ctx->pc = 0x802CE488u;
    // 802CE488: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE48C:
    ctx->pc = 0x802CE48Cu;
    ctx->downcount -= 10;
    // 802CE48C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE490:
    ctx->pc = 0x802CE490u;
    // 802CE490: rlwinm r0, r0, 23, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x00000001u;
    }

label_802CE494:
    ctx->pc = 0x802CE494u;
    // 802CE494: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE498:
    ctx->pc = 0x802CE498u;
    // 802CE498: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE49C:
    ctx->pc = 0x802CE49Cu;
    // 802CE49C: rlwinm r0, r0, 22, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 22u) & 0x00000007u;
    }

label_802CE4A0:
    ctx->pc = 0x802CE4A0u;
    // 802CE4A0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE4A4:
    ctx->pc = 0x802CE4A4u;
    // 802CE4A4: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE4A8:
    ctx->pc = 0x802CE4A8u;
    // 802CE4A8: rlwinm r0, r0, 19, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 19u) & 0x0000001Fu;
    }

label_802CE4AC:
    ctx->pc = 0x802CE4ACu;
    // 802CE4AC: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE4B0:
    ctx->pc = 0x802CE4B0u;
    // 802CE4B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE4B4:
    ctx->pc = 0x802CE4B4u;
    ctx->downcount -= 10;
    // 802CE4B4: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE4B8:
    ctx->pc = 0x802CE4B8u;
    // 802CE4B8: rlwinm r0, r0, 14, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0x00000001u;
    }

label_802CE4BC:
    ctx->pc = 0x802CE4BCu;
    // 802CE4BC: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE4C0:
    ctx->pc = 0x802CE4C0u;
    // 802CE4C0: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE4C4:
    ctx->pc = 0x802CE4C4u;
    // 802CE4C4: rlwinm r0, r0, 13, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 13u) & 0x00000007u;
    }

label_802CE4C8:
    ctx->pc = 0x802CE4C8u;
    // 802CE4C8: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE4CC:
    ctx->pc = 0x802CE4CCu;
    // 802CE4CC: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE4D0:
    ctx->pc = 0x802CE4D0u;
    // 802CE4D0: rlwinm r0, r0, 10, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0x0000001Fu;
    }

label_802CE4D4:
    ctx->pc = 0x802CE4D4u;
    // 802CE4D4: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE4D8:
    ctx->pc = 0x802CE4D8u;
    // 802CE4D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE4DC:
    ctx->pc = 0x802CE4DCu;
    ctx->downcount -= 10;
    // 802CE4DC: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE4E0:
    ctx->pc = 0x802CE4E0u;
    // 802CE4E0: rlwinm r0, r0, 5, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0x00000001u;
    }

label_802CE4E4:
    ctx->pc = 0x802CE4E4u;
    // 802CE4E4: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE4E8:
    ctx->pc = 0x802CE4E8u;
    // 802CE4E8: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE4EC:
    ctx->pc = 0x802CE4ECu;
    // 802CE4EC: rlwinm r0, r0, 4, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0x00000007u;
    }

label_802CE4F0:
    ctx->pc = 0x802CE4F0u;
    // 802CE4F0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE4F4:
    ctx->pc = 0x802CE4F4u;
    // 802CE4F4: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE4F8:
    ctx->pc = 0x802CE4F8u;
    // 802CE4F8: rlwinm r0, r0, 0, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000001Fu;
    }

label_802CE4FC:
    ctx->pc = 0x802CE4FCu;
    // 802CE4FC: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE500:
    ctx->pc = 0x802CE500u;
    // 802CE500: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE504:
    ctx->pc = 0x802CE504u;
    ctx->downcount -= 10;
    // 802CE504: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE508:
    ctx->pc = 0x802CE508u;
    // 802CE508: rlwinm r0, r0, 27, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x00000001u;
    }

label_802CE50C:
    ctx->pc = 0x802CE50Cu;
    // 802CE50C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE510:
    ctx->pc = 0x802CE510u;
    // 802CE510: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE514:
    ctx->pc = 0x802CE514u;
    // 802CE514: rlwinm r0, r0, 26, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x00000007u;
    }

label_802CE518:
    ctx->pc = 0x802CE518u;
    // 802CE518: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE51C:
    ctx->pc = 0x802CE51Cu;
    // 802CE51C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE520:
    ctx->pc = 0x802CE520u;
    // 802CE520: rlwinm r0, r0, 23, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x0000001Fu;
    }

label_802CE524:
    ctx->pc = 0x802CE524u;
    // 802CE524: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE528:
    ctx->pc = 0x802CE528u;
    // 802CE528: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE52C:
    ctx->pc = 0x802CE52Cu;
    ctx->downcount -= 10;
    // 802CE52C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE530:
    ctx->pc = 0x802CE530u;
    // 802CE530: rlwinm r0, r0, 18, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 18u) & 0x00000001u;
    }

label_802CE534:
    ctx->pc = 0x802CE534u;
    // 802CE534: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE538:
    ctx->pc = 0x802CE538u;
    // 802CE538: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE53C:
    ctx->pc = 0x802CE53Cu;
    // 802CE53C: rlwinm r0, r0, 17, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x00000007u;
    }

label_802CE540:
    ctx->pc = 0x802CE540u;
    // 802CE540: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE544:
    ctx->pc = 0x802CE544u;
    // 802CE544: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE548:
    ctx->pc = 0x802CE548u;
    // 802CE548: rlwinm r0, r0, 14, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0x0000001Fu;
    }

label_802CE54C:
    ctx->pc = 0x802CE54Cu;
    // 802CE54C: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE550:
    ctx->pc = 0x802CE550u;
    // 802CE550: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE554:
    ctx->pc = 0x802CE554u;
    ctx->downcount -= 10;
    // 802CE554: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE558:
    ctx->pc = 0x802CE558u;
    // 802CE558: rlwinm r0, r0, 9, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0x00000001u;
    }

label_802CE55C:
    ctx->pc = 0x802CE55Cu;
    // 802CE55C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE560:
    ctx->pc = 0x802CE560u;
    // 802CE560: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE564:
    ctx->pc = 0x802CE564u;
    // 802CE564: rlwinm r0, r0, 8, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0x00000007u;
    }

label_802CE568:
    ctx->pc = 0x802CE568u;
    // 802CE568: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE56C:
    ctx->pc = 0x802CE56Cu;
    // 802CE56C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE570:
    ctx->pc = 0x802CE570u;
    // 802CE570: rlwinm r0, r0, 5, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0x0000001Fu;
    }

label_802CE574:
    ctx->pc = 0x802CE574u;
    // 802CE574: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE578:
    ctx->pc = 0x802CE578u;
    // 802CE578: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE57C:
    ctx->pc = 0x802CE57Cu;
    ctx->downcount -= 6;
    // 802CE57C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802CE580:
    ctx->pc = 0x802CE580u;
    // 802CE580: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE584:
    ctx->pc = 0x802CE584u;
    // 802CE584: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CE588:
    ctx->pc = 0x802CE588u;
    // 802CE588: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE58C:
    ctx->pc = 0x802CE58Cu;
    // 802CE58C: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE590:
    ctx->pc = 0x802CE590u;
    // 802CE590: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE594:
    ctx->pc = 0x802CE594u;
    ctx->downcount -= 9;
    // 802CE594: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CE598:
    ctx->pc = 0x802CE598u;
    // 802CE598: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE59C:
    ctx->pc = 0x802CE59Cu;
    // 802CE59C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CE5A0:
    ctx->pc = 0x802CE5A0u;
    // 802CE5A0: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CE5A4:
    ctx->pc = 0x802CE5A4u;
    // 802CE5A4: li      r31, 9
    ctx->gpr[31] = (u32)(s32)(9);

label_802CE5A8:
    ctx->pc = 0x802CE5A8u;
    // 802CE5A8: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CE5AC:
    ctx->pc = 0x802CE5ACu;
    // 802CE5AC: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_802CE5B0:
    ctx->pc = 0x802CE5B0u;
    // 802CE5B0: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802CE5B4:
    ctx->pc = 0x802CE5B4u;
    // 802CE5B4: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802CE5B8:
    ctx->pc = 0x802CE5B8u;
    ctx->downcount -= 7;
    // 802CE5B8: stw     r31, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CE5BC:
    // 802CE5BC: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_802CE5C0:
    // 802CE5C0: addi    r4, r31, 0
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(0);

label_802CE5C4:
    // 802CE5C4: addi    r5, r30, 4
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(4);

label_802CE5C8:
    // 802CE5C8: addi    r6, r30, 8
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(8);

label_802CE5CC:
    // 802CE5CC: addi    r7, r30, 12
    ctx->gpr[7] = ctx->gpr[30] + (u32)(s32)(12);

label_802CE5D0:
    // 802CE5D0: bl      0x802CE314
    {
            ctx->lr = 0x802CE5D4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CE314u;
                return;
            }
            goto label_802CE314;
    }

label_802CE5D4:
    ctx->downcount -= 4;
    // 802CE5D4: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_802CE5D8:
    // 802CE5D8: cmpwi   r31, 20
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(20);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE5DC:
    // 802CE5DC: addi    r30, r30, 16
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(16);

label_802CE5E0:
    // 802CE5E0: bc    4, 1, 0x802CE5B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CE5B8u;
                return;
            }
            goto label_802CE5B8;
        }
    }

label_802CE5E4:
    ctx->pc = 0x802CE5E4u;
    ctx->downcount -= 10;
    // 802CE5E4: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_802CE5E8:
    ctx->pc = 0x802CE5E8u;
    // 802CE5E8: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE5EC:
    ctx->pc = 0x802CE5ECu;
    // 802CE5EC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE5F0:
    ctx->pc = 0x802CE5F0u;
    // 802CE5F0: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CE5F4:
    ctx->pc = 0x802CE5F4u;
    // 802CE5F4: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CE5F8:
    ctx->pc = 0x802CE5F8u;
    // 802CE5F8: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802CE5FC:
    ctx->pc = 0x802CE5FCu;
    // 802CE5FC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802CE600:
    ctx->pc = 0x802CE600u;
    // 802CE600: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CE604:
    ctx->pc = 0x802CE604u;
    // 802CE604: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE608:
    ctx->pc = 0x802CE608u;
    ctx->downcount -= 2;
    // 802CE608: cmpwi   r3, 25
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(25);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE60C:
    ctx->pc = 0x802CE60Cu;
    // 802CE60C: bc    4, 2, 0x802CE614
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE614;
        }
    }

label_802CE610:
    ctx->pc = 0x802CE610u;
    ctx->downcount -= 1;
    // 802CE610: li      r3, 10
    ctx->gpr[3] = (u32)(s32)(10);

label_802CE614:
    ctx->pc = 0x802CE614u;
    ctx->downcount -= 10;
    // 802CE614: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_802CE618:
    ctx->pc = 0x802CE618u;
    // 802CE618: addi    r6, r3, -9
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(-9);

label_802CE61C:
    ctx->pc = 0x802CE61Cu;
    // 802CE61C: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_802CE620:
    ctx->pc = 0x802CE620u;
    // 802CE620: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE624:
    ctx->pc = 0x802CE624u;
    // 802CE624: ori     r0, r6, 0x00A0
    ctx->gpr[0] = ctx->gpr[6] | 0x00A0u;

label_802CE628:
    ctx->pc = 0x802CE628u;
    // 802CE628: rlwinm r4, r4, 0, 2, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x3FFFFFFFu;
    }

label_802CE62C:
    ctx->pc = 0x802CE62Cu;
    // 802CE62C: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE630:
    ctx->pc = 0x802CE630u;
    // 802CE630: addic.  r0, r6, -12
    {
        u64 a = ctx->gpr[6];
        u64 b = (u32)(s32)(-12);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CE634:
    ctx->pc = 0x802CE634u;
    // 802CE634: stw     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CE638:
    ctx->pc = 0x802CE638u;
    // 802CE638: bc    12, 0, 0x802CE654
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CE654;
        }
    }

label_802CE63C:
    ctx->pc = 0x802CE63Cu;
    ctx->downcount -= 2;
    // 802CE63C: cmpwi   r0, 4
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

label_802CE640:
    ctx->pc = 0x802CE640u;
    // 802CE640: bc    4, 0, 0x802CE654
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE654;
        }
    }

label_802CE644:
    ctx->pc = 0x802CE644u;
    ctx->downcount -= 4;
    // 802CE644: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CE648:
    ctx->pc = 0x802CE648u;
    // 802CE648: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_802CE64C:
    ctx->pc = 0x802CE64Cu;
    // 802CE64C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802CE650:
    ctx->pc = 0x802CE650u;
    // 802CE650: stw     r4, 136(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CE654:
    ctx->pc = 0x802CE654u;
    ctx->downcount -= 9;
    // 802CE654: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_802CE658:
    ctx->pc = 0x802CE658u;
    // 802CE658: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_802CE65C:
    ctx->pc = 0x802CE65Cu;
    // 802CE65C: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE660:
    ctx->pc = 0x802CE660u;
    // 802CE660: ori     r0, r6, 0x00B0
    ctx->gpr[0] = ctx->gpr[6] | 0x00B0u;

label_802CE664:
    ctx->pc = 0x802CE664u;
    // 802CE664: rlwinm r4, r5, 0, 24, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_802CE668:
    ctx->pc = 0x802CE668u;
    // 802CE668: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE66C:
    ctx->pc = 0x802CE66Cu;
    // 802CE66C: addic.  r0, r6, -12
    {
        u64 a = ctx->gpr[6];
        u64 b = (u32)(s32)(-12);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CE670:
    ctx->pc = 0x802CE670u;
    // 802CE670: stw     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CE674:
    ctx->pc = 0x802CE674u;
    // 802CE674: bclr  12, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE678:
    ctx->pc = 0x802CE678u;
    ctx->downcount -= 2;
    // 802CE678: cmpwi   r0, 4
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

label_802CE67C:
    ctx->pc = 0x802CE67Cu;
    // 802CE67C: bclr  4, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE680:
    ctx->pc = 0x802CE680u;
    ctx->downcount -= 5;
    // 802CE680: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CE684:
    ctx->pc = 0x802CE684u;
    // 802CE684: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_802CE688:
    ctx->pc = 0x802CE688u;
    // 802CE688: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802CE68C:
    ctx->pc = 0x802CE68Cu;
    // 802CE68C: stw     r4, 152(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CE690:
    ctx->pc = 0x802CE690u;
    // 802CE690: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE694:
    ctx->pc = 0x802CE694u;
    ctx->downcount -= 4;
    // 802CE694: li      r0, 72
    ctx->gpr[0] = (u32)(s32)(72);

label_802CE698:
    ctx->pc = 0x802CE698u;
    // 802CE698: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_802CE69C:
    ctx->pc = 0x802CE69Cu;
    // 802CE69C: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CE6A0:
    ctx->pc = 0x802CE6A0u;
    // 802CE6A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE6A4:
    ctx->pc = 0x802CE6A4u;
    ctx->downcount -= 8;
    // 802CE6A4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CE6A8:
    ctx->pc = 0x802CE6A8u;
    // 802CE6A8: cmplwi  r5, 0x0014
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0014u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE6AC:
    ctx->pc = 0x802CE6ACu;
    // 802CE6AC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE6B0:
    ctx->pc = 0x802CE6B0u;
    // 802CE6B0: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_802CE6B4:
    ctx->pc = 0x802CE6B4u;
    // 802CE6B4: li      r12, 0
    ctx->gpr[12] = (u32)(s32)(0);

label_802CE6B8:
    ctx->pc = 0x802CE6B8u;
    // 802CE6B8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CE6BC:
    ctx->pc = 0x802CE6BCu;
    // 802CE6BC: li      r10, 5
    ctx->gpr[10] = (u32)(s32)(5);

label_802CE6C0:
    ctx->pc = 0x802CE6C0u;
    // 802CE6C0: bc    12, 1, 0x802CE758
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CE758;
        }
    }

label_802CE6C4:
    ctx->pc = 0x802CE6C4u;
    ctx->downcount -= 7;
    // 802CE6C4: lis     r9, -32715
    ctx->gpr[9] = ((u32)(s32)(-32715) << 16);

label_802CE6C8:
    ctx->pc = 0x802CE6C8u;
    // 802CE6C8: addi    r9, r9, 32224
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(32224);

label_802CE6CC:
    ctx->pc = 0x802CE6CCu;
    // 802CE6CC: rlwinm r0, r5, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 2u) & 0xFFFFFFFCu;
    }

label_802CE6D0:
    ctx->pc = 0x802CE6D0u;
    // 802CE6D0: lwzx    r0, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE6D4:
    ctx->pc = 0x802CE6D4u;
    // 802CE6D4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802CE6D8:
    ctx->pc = 0x802CE6D8u;
    // 802CE6D8: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_802CE6DC:
    ctx->pc = 0x802CE6DCu;
    ctx->downcount -= 3;
    // 802CE6DC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_802CE6E0:
    ctx->pc = 0x802CE6E0u;
    // 802CE6E0: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_802CE6E4:
    ctx->pc = 0x802CE6E4u;
    // 802CE6E4: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE6E8:
    ctx->pc = 0x802CE6E8u;
    ctx->downcount -= 3;
    // 802CE6E8: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_802CE6EC:
    ctx->pc = 0x802CE6ECu;
    // 802CE6EC: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_802CE6F0:
    ctx->pc = 0x802CE6F0u;
    // 802CE6F0: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE6F4:
    ctx->pc = 0x802CE6F4u;
    ctx->downcount -= 3;
    // 802CE6F4: li      r10, 3
    ctx->gpr[10] = (u32)(s32)(3);

label_802CE6F8:
    ctx->pc = 0x802CE6F8u;
    // 802CE6F8: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_802CE6FC:
    ctx->pc = 0x802CE6FCu;
    // 802CE6FC: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE700:
    ctx->pc = 0x802CE700u;
    ctx->downcount -= 3;
    // 802CE700: li      r10, 4
    ctx->gpr[10] = (u32)(s32)(4);

label_802CE704:
    ctx->pc = 0x802CE704u;
    // 802CE704: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_802CE708:
    ctx->pc = 0x802CE708u;
    // 802CE708: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE70C:
    ctx->pc = 0x802CE70Cu;
    ctx->downcount -= 2;
    // 802CE70C: li      r10, 2
    ctx->gpr[10] = (u32)(s32)(2);

label_802CE710:
    ctx->pc = 0x802CE710u;
    // 802CE710: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE714:
    ctx->pc = 0x802CE714u;
    ctx->downcount -= 2;
    // 802CE714: li      r10, 2
    ctx->gpr[10] = (u32)(s32)(2);

label_802CE718:
    ctx->pc = 0x802CE718u;
    // 802CE718: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE71C:
    ctx->pc = 0x802CE71Cu;
    ctx->downcount -= 2;
    // 802CE71C: li      r10, 5
    ctx->gpr[10] = (u32)(s32)(5);

label_802CE720:
    ctx->pc = 0x802CE720u;
    // 802CE720: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE724:
    ctx->pc = 0x802CE724u;
    ctx->downcount -= 2;
    // 802CE724: li      r10, 6
    ctx->gpr[10] = (u32)(s32)(6);

label_802CE728:
    ctx->pc = 0x802CE728u;
    // 802CE728: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE72C:
    ctx->pc = 0x802CE72Cu;
    ctx->downcount -= 2;
    // 802CE72C: li      r10, 7
    ctx->gpr[10] = (u32)(s32)(7);

label_802CE730:
    ctx->pc = 0x802CE730u;
    // 802CE730: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE734:
    ctx->pc = 0x802CE734u;
    ctx->downcount -= 2;
    // 802CE734: li      r10, 8
    ctx->gpr[10] = (u32)(s32)(8);

label_802CE738:
    ctx->pc = 0x802CE738u;
    // 802CE738: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE73C:
    ctx->pc = 0x802CE73Cu;
    ctx->downcount -= 2;
    // 802CE73C: li      r10, 9
    ctx->gpr[10] = (u32)(s32)(9);

label_802CE740:
    ctx->pc = 0x802CE740u;
    // 802CE740: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE744:
    ctx->pc = 0x802CE744u;
    ctx->downcount -= 2;
    // 802CE744: li      r10, 10
    ctx->gpr[10] = (u32)(s32)(10);

label_802CE748:
    ctx->pc = 0x802CE748u;
    // 802CE748: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE74C:
    ctx->pc = 0x802CE74Cu;
    ctx->downcount -= 2;
    // 802CE74C: li      r10, 11
    ctx->gpr[10] = (u32)(s32)(11);

label_802CE750:
    ctx->pc = 0x802CE750u;
    // 802CE750: b       0x802CE758
    {
            goto label_802CE758;
    }

label_802CE754:
    ctx->pc = 0x802CE754u;
    ctx->downcount -= 1;
    // 802CE754: li      r10, 12
    ctx->gpr[10] = (u32)(s32)(12);

label_802CE758:
    ctx->pc = 0x802CE758u;
    ctx->downcount -= 2;
    // 802CE758: cmpwi   r4, 1
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

label_802CE75C:
    ctx->pc = 0x802CE75Cu;
    // 802CE75C: bc    12, 2, 0x802CE780
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CE780;
        }
    }

label_802CE760:
    ctx->pc = 0x802CE760u;
    ctx->downcount -= 1;
    // 802CE760: bc    4, 0, 0x802CE770
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE770;
        }
    }

label_802CE764:
    ctx->pc = 0x802CE764u;
    ctx->downcount -= 2;
    // 802CE764: cmpwi   r4, 0
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

label_802CE768:
    ctx->pc = 0x802CE768u;
    // 802CE768: bc    4, 0, 0x802CE794
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE794;
        }
    }

label_802CE76C:
    ctx->pc = 0x802CE76Cu;
    ctx->downcount -= 1;
    // 802CE76C: b       0x802CE810
    {
            goto label_802CE810;
    }

label_802CE770:
    ctx->pc = 0x802CE770u;
    ctx->downcount -= 2;
    // 802CE770: cmpwi   r4, 10
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE774:
    ctx->pc = 0x802CE774u;
    // 802CE774: bc    12, 2, 0x802CE7E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CE7E8;
        }
    }

label_802CE778:
    ctx->pc = 0x802CE778u;
    ctx->downcount -= 1;
    // 802CE778: bc    4, 0, 0x802CE810
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE810;
        }
    }

label_802CE77C:
    ctx->pc = 0x802CE77Cu;
    ctx->downcount -= 1;
    // 802CE77C: b       0x802CE7AC
    {
            goto label_802CE7AC;
    }

label_802CE780:
    ctx->pc = 0x802CE780u;
    ctx->downcount -= 5;
    // 802CE780: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_802CE784:
    ctx->pc = 0x802CE784u;
    // 802CE784: rlwinm r4, r0, 0, 28, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF00Fu;
    }

label_802CE788:
    ctx->pc = 0x802CE788u;
    // 802CE788: rlwinm r0, r10, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 7u) & 0xFFFFFF80u;
    }

label_802CE78C:
    ctx->pc = 0x802CE78Cu;
    // 802CE78C: or   r11, r4, r0
    {
        ctx->gpr[11] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CE790:
    ctx->pc = 0x802CE790u;
    // 802CE790: b       0x802CE810
    {
            goto label_802CE810;
    }

label_802CE794:
    ctx->pc = 0x802CE794u;
    ctx->downcount -= 6;
    // 802CE794: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_802CE798:
    ctx->pc = 0x802CE798u;
    // 802CE798: ori     r0, r0, 0x0002
    ctx->gpr[0] = ctx->gpr[0] | 0x0002u;

label_802CE79C:
    ctx->pc = 0x802CE79Cu;
    // 802CE79C: rlwinm r4, r0, 0, 28, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF00Fu;
    }

label_802CE7A0:
    ctx->pc = 0x802CE7A0u;
    // 802CE7A0: rlwinm r0, r10, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 7u) & 0xFFFFFF80u;
    }

label_802CE7A4:
    ctx->pc = 0x802CE7A4u;
    // 802CE7A4: or   r11, r4, r0
    {
        ctx->gpr[11] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CE7A8:
    ctx->pc = 0x802CE7A8u;
    // 802CE7A8: b       0x802CE810
    {
            goto label_802CE810;
    }

label_802CE7AC:
    ctx->pc = 0x802CE7ACu;
    ctx->downcount -= 15;
    // 802CE7AC: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_802CE7B0:
    ctx->pc = 0x802CE7B0u;
    // 802CE7B0: rlwinm r0, r0, 0, 28, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF8Fu;
    }

label_802CE7B4:
    ctx->pc = 0x802CE7B4u;
    // 802CE7B4: ori     r0, r0, 0x0010
    ctx->gpr[0] = ctx->gpr[0] | 0x0010u;

label_802CE7B8:
    ctx->pc = 0x802CE7B8u;
    // 802CE7B8: rlwinm r9, r0, 0, 25, 19
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF07Fu;
    }

label_802CE7BC:
    ctx->pc = 0x802CE7BCu;
    // 802CE7BC: rlwinm r0, r10, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 7u) & 0xFFFFFF80u;
    }

label_802CE7C0:
    ctx->pc = 0x802CE7C0u;
    // 802CE7C0: or   r9, r9, r0
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[0];
    }

label_802CE7C4:
    ctx->pc = 0x802CE7C4u;
    // 802CE7C4: addi    r5, r5, -12
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-12);

label_802CE7C8:
    ctx->pc = 0x802CE7C8u;
    // 802CE7C8: addi    r0, r4, -2
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-2);

label_802CE7CC:
    ctx->pc = 0x802CE7CCu;
    // 802CE7CC: rlwinm r9, r9, 0, 20, 16
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFF8FFFu;
    }

label_802CE7D0:
    ctx->pc = 0x802CE7D0u;
    // 802CE7D0: rlwinm r4, r5, 12, 0, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 12u) & 0xFFFFF000u;
    }

label_802CE7D4:
    ctx->pc = 0x802CE7D4u;
    // 802CE7D4: or   r4, r9, r4
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[4];
    }

label_802CE7D8:
    ctx->pc = 0x802CE7D8u;
    // 802CE7D8: rlwinm r4, r4, 0, 17, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC7FFFu;
    }

label_802CE7DC:
    ctx->pc = 0x802CE7DCu;
    // 802CE7DC: rlwinm r0, r0, 15, 0, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 15u) & 0xFFFF8000u;
    }

label_802CE7E0:
    ctx->pc = 0x802CE7E0u;
    // 802CE7E0: or   r11, r4, r0
    {
        ctx->gpr[11] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CE7E4:
    ctx->pc = 0x802CE7E4u;
    // 802CE7E4: b       0x802CE810
    {
            goto label_802CE810;
    }

label_802CE7E8:
    ctx->pc = 0x802CE7E8u;
    ctx->downcount -= 3;
    // 802CE7E8: cmpwi   r5, 19
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE7EC:
    ctx->pc = 0x802CE7ECu;
    // 802CE7EC: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_802CE7F0:
    ctx->pc = 0x802CE7F0u;
    // 802CE7F0: bc    4, 2, 0x802CE800
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE800;
        }
    }

label_802CE7F4:
    ctx->pc = 0x802CE7F4u;
    ctx->downcount -= 3;
    // 802CE7F4: rlwinm r0, r0, 0, 28, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF8Fu;
    }

label_802CE7F8:
    ctx->pc = 0x802CE7F8u;
    // 802CE7F8: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_802CE7FC:
    ctx->pc = 0x802CE7FCu;
    // 802CE7FC: b       0x802CE808
    {
            goto label_802CE808;
    }

label_802CE800:
    ctx->pc = 0x802CE800u;
    ctx->downcount -= 2;
    // 802CE800: rlwinm r0, r0, 0, 28, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF8Fu;
    }

label_802CE804:
    ctx->pc = 0x802CE804u;
    // 802CE804: ori     r0, r0, 0x0030
    ctx->gpr[0] = ctx->gpr[0] | 0x0030u;

label_802CE808:
    ctx->pc = 0x802CE808u;
    ctx->downcount -= 2;
    // 802CE808: rlwinm r0, r0, 0, 25, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF07Fu;
    }

label_802CE80C:
    ctx->pc = 0x802CE80Cu;
    // 802CE80C: ori     r11, r0, 0x0100
    ctx->gpr[11] = ctx->gpr[0] | 0x0100u;

label_802CE810:
    ctx->pc = 0x802CE810u;
    ctx->downcount -= 16;
    // 802CE810: li      r10, 16
    ctx->gpr[10] = (u32)(s32)(16);

label_802CE814:
    ctx->pc = 0x802CE814u;
    // 802CE814: lis     r9, -13311
    ctx->gpr[9] = ((u32)(s32)(-13311) << 16);

label_802CE818:
    ctx->pc = 0x802CE818u;
    // 802CE818: stb     r10, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[10]);
    }

label_802CE81C:
    ctx->pc = 0x802CE81Cu;
    // 802CE81C: addi    r0, r3, 4160
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(4160);

label_802CE820:
    ctx->pc = 0x802CE820u;
    // 802CE820: addi    r4, r8, -64
    ctx->gpr[4] = ctx->gpr[8] + (u32)(s32)(-64);

label_802CE824:
    ctx->pc = 0x802CE824u;
    // 802CE824: stw     r0, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE828:
    ctx->pc = 0x802CE828u;
    // 802CE828: rlwinm r5, r4, 0, 24, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFEFFu;
    }

label_802CE82C:
    ctx->pc = 0x802CE82Cu;
    // 802CE82C: rlwinm r4, r7, 8, 16, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[7], 8u) & 0x0000FF00u;
    }

label_802CE830:
    ctx->pc = 0x802CE830u;
    // 802CE830: stw     r11, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_802CE834:
    ctx->pc = 0x802CE834u;
    // 802CE834: addi    r0, r3, 4176
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(4176);

label_802CE838:
    ctx->pc = 0x802CE838u;
    // 802CE838: cmplwi  r3, 0x0006
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0006u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE83C:
    ctx->pc = 0x802CE83Cu;
    // 802CE83C: stb     r10, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[10]);
    }

label_802CE840:
    ctx->pc = 0x802CE840u;
    // 802CE840: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_802CE844:
    ctx->pc = 0x802CE844u;
    // 802CE844: stw     r0, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE848:
    ctx->pc = 0x802CE848u;
    // 802CE848: stw     r4, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CE84C:
    ctx->pc = 0x802CE84Cu;
    // 802CE84C: bc    12, 1, 0x802CE940
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CE940;
        }
    }

label_802CE850:
    ctx->pc = 0x802CE850u;
    ctx->downcount -= 7;
    // 802CE850: lis     r4, -32715
    ctx->gpr[4] = ((u32)(s32)(-32715) << 16);

label_802CE854:
    ctx->pc = 0x802CE854u;
    // 802CE854: addi    r4, r4, 32196
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(32196);

label_802CE858:
    ctx->pc = 0x802CE858u;
    // 802CE858: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_802CE85C:
    ctx->pc = 0x802CE85Cu;
    // 802CE85C: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE860:
    ctx->pc = 0x802CE860u;
    // 802CE860: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802CE864:
    ctx->pc = 0x802CE864u;
    // 802CE864: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_802CE868:
    ctx->pc = 0x802CE868u;
    ctx->downcount -= 8;
    // 802CE868: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE86C:
    ctx->pc = 0x802CE86Cu;
    // 802CE86C: rlwinm r0, r6, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_802CE870:
    ctx->pc = 0x802CE870u;
    // 802CE870: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_802CE874:
    ctx->pc = 0x802CE874u;
    // 802CE874: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE878:
    ctx->pc = 0x802CE878u;
    // 802CE878: rlwinm r4, r4, 0, 26, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFF03Fu;
    }

label_802CE87C:
    ctx->pc = 0x802CE87Cu;
    // 802CE87C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CE880:
    ctx->pc = 0x802CE880u;
    // 802CE880: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE884:
    ctx->pc = 0x802CE884u;
    // 802CE884: b       0x802CE95C
    {
            goto label_802CE95C;
    }

label_802CE888:
    ctx->pc = 0x802CE888u;
    ctx->downcount -= 8;
    // 802CE888: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE88C:
    ctx->pc = 0x802CE88Cu;
    // 802CE88C: rlwinm r0, r6, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 12u) & 0xFFFFF000u;
    }

label_802CE890:
    ctx->pc = 0x802CE890u;
    // 802CE890: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_802CE894:
    ctx->pc = 0x802CE894u;
    // 802CE894: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE898:
    ctx->pc = 0x802CE898u;
    // 802CE898: rlwinm r4, r4, 0, 20, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC0FFFu;
    }

label_802CE89C:
    ctx->pc = 0x802CE89Cu;
    // 802CE89C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CE8A0:
    ctx->pc = 0x802CE8A0u;
    // 802CE8A0: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE8A4:
    ctx->pc = 0x802CE8A4u;
    // 802CE8A4: b       0x802CE95C
    {
            goto label_802CE95C;
    }

label_802CE8A8:
    ctx->pc = 0x802CE8A8u;
    ctx->downcount -= 8;
    // 802CE8A8: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE8AC:
    ctx->pc = 0x802CE8ACu;
    // 802CE8AC: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_802CE8B0:
    ctx->pc = 0x802CE8B0u;
    // 802CE8B0: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_802CE8B4:
    ctx->pc = 0x802CE8B4u;
    // 802CE8B4: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE8B8:
    ctx->pc = 0x802CE8B8u;
    // 802CE8B8: rlwinm r4, r4, 0, 14, 7
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF03FFFFu;
    }

label_802CE8BC:
    ctx->pc = 0x802CE8BCu;
    // 802CE8BC: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CE8C0:
    ctx->pc = 0x802CE8C0u;
    // 802CE8C0: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE8C4:
    ctx->pc = 0x802CE8C4u;
    // 802CE8C4: b       0x802CE95C
    {
            goto label_802CE95C;
    }

label_802CE8C8:
    ctx->pc = 0x802CE8C8u;
    ctx->downcount -= 8;
    // 802CE8C8: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE8CC:
    ctx->pc = 0x802CE8CCu;
    // 802CE8CC: rlwinm r0, r6, 24, 0, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0xFF000000u;
    }

label_802CE8D0:
    ctx->pc = 0x802CE8D0u;
    // 802CE8D0: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_802CE8D4:
    ctx->pc = 0x802CE8D4u;
    // 802CE8D4: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE8D8:
    ctx->pc = 0x802CE8D8u;
    // 802CE8D8: rlwinm r4, r4, 0, 8, 1
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xC0FFFFFFu;
    }

label_802CE8DC:
    ctx->pc = 0x802CE8DCu;
    // 802CE8DC: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CE8E0:
    ctx->pc = 0x802CE8E0u;
    // 802CE8E0: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE8E4:
    ctx->pc = 0x802CE8E4u;
    // 802CE8E4: b       0x802CE95C
    {
            goto label_802CE95C;
    }

label_802CE8E8:
    ctx->pc = 0x802CE8E8u;
    ctx->downcount -= 6;
    // 802CE8E8: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE8EC:
    ctx->pc = 0x802CE8ECu;
    // 802CE8EC: lwzu     r0, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_802CE8F0:
    ctx->pc = 0x802CE8F0u;
    // 802CE8F0: rlwinm r0, r0, 0, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFC0u;
    }

label_802CE8F4:
    ctx->pc = 0x802CE8F4u;
    // 802CE8F4: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_802CE8F8:
    ctx->pc = 0x802CE8F8u;
    // 802CE8F8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE8FC:
    ctx->pc = 0x802CE8FCu;
    // 802CE8FC: b       0x802CE95C
    {
            goto label_802CE95C;
    }

label_802CE900:
    ctx->pc = 0x802CE900u;
    ctx->downcount -= 8;
    // 802CE900: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE904:
    ctx->pc = 0x802CE904u;
    // 802CE904: rlwinm r0, r6, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_802CE908:
    ctx->pc = 0x802CE908u;
    // 802CE908: addi    r5, r4, 132
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(132);

label_802CE90C:
    ctx->pc = 0x802CE90Cu;
    // 802CE90C: lwz     r4, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE910:
    ctx->pc = 0x802CE910u;
    // 802CE910: rlwinm r4, r4, 0, 26, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFF03Fu;
    }

label_802CE914:
    ctx->pc = 0x802CE914u;
    // 802CE914: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CE918:
    ctx->pc = 0x802CE918u;
    // 802CE918: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE91C:
    ctx->pc = 0x802CE91Cu;
    // 802CE91C: b       0x802CE95C
    {
            goto label_802CE95C;
    }

label_802CE920:
    ctx->pc = 0x802CE920u;
    ctx->downcount -= 8;
    // 802CE920: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE924:
    ctx->pc = 0x802CE924u;
    // 802CE924: rlwinm r0, r6, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 12u) & 0xFFFFF000u;
    }

label_802CE928:
    ctx->pc = 0x802CE928u;
    // 802CE928: addi    r5, r4, 132
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(132);

label_802CE92C:
    ctx->pc = 0x802CE92Cu;
    // 802CE92C: lwz     r4, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE930:
    ctx->pc = 0x802CE930u;
    // 802CE930: rlwinm r4, r4, 0, 20, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC0FFFu;
    }

label_802CE934:
    ctx->pc = 0x802CE934u;
    // 802CE934: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CE938:
    ctx->pc = 0x802CE938u;
    // 802CE938: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE93C:
    ctx->pc = 0x802CE93Cu;
    // 802CE93C: b       0x802CE95C
    {
            goto label_802CE95C;
    }

label_802CE940:
    ctx->pc = 0x802CE940u;
    ctx->downcount -= 7;
    // 802CE940: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE944:
    ctx->pc = 0x802CE944u;
    // 802CE944: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_802CE948:
    ctx->pc = 0x802CE948u;
    // 802CE948: addi    r5, r4, 132
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(132);

label_802CE94C:
    ctx->pc = 0x802CE94Cu;
    // 802CE94C: lwz     r4, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CE950:
    ctx->pc = 0x802CE950u;
    // 802CE950: rlwinm r4, r4, 0, 14, 7
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF03FFFFu;
    }

label_802CE954:
    ctx->pc = 0x802CE954u;
    // 802CE954: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CE958:
    ctx->pc = 0x802CE958u;
    // 802CE958: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE95C:
    ctx->pc = 0x802CE95Cu;
    ctx->downcount -= 2;
    // 802CE95C: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_802CE960:
    ctx->pc = 0x802CE960u;
    // 802CE960: bl      0x802D526C
    {
            ctx->lr = 0x802CE964u;
            ctx->pc = 0x802D526Cu;
            return;
    }

label_802CE964:
    ctx->pc = 0x802CE964u;
    ctx->downcount -= 5;
    // 802CE964: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE968:
    ctx->pc = 0x802CE968u;
    // 802CE968: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802CE96C:
    ctx->pc = 0x802CE96Cu;
    // 802CE96C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CE970:
    ctx->pc = 0x802CE970u;
    // 802CE970: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE974:
    ctx->pc = 0x802CE974u;
    ctx->downcount -= 16;
    // 802CE974: lwz     r6, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802CE978:
    ctx->pc = 0x802CE978u;
    // 802CE978: rlwinm r8, r3, 0, 24, 31
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_802CE97C:
    ctx->pc = 0x802CE97Cu;
    // 802CE97C: li      r4, 16
    ctx->gpr[4] = (u32)(s32)(16);

label_802CE980:
    ctx->pc = 0x802CE980u;
    // 802CE980: lwz     r5, 516(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(516);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CE984:
    ctx->pc = 0x802CE984u;
    // 802CE984: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_802CE988:
    ctx->pc = 0x802CE988u;
    // 802CE988: li      r0, 4159
    ctx->gpr[0] = (u32)(s32)(4159);

label_802CE98C:
    ctx->pc = 0x802CE98Cu;
    // 802CE98C: rlwinm r5, r5, 0, 0, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF0u;
    }

label_802CE990:
    ctx->pc = 0x802CE990u;
    // 802CE990: or   r5, r5, r8
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[8];
    }

label_802CE994:
    ctx->pc = 0x802CE994u;
    // 802CE994: stw     r5, 516(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(516);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CE998:
    ctx->pc = 0x802CE998u;
    // 802CE998: stb     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802CE99C:
    ctx->pc = 0x802CE99Cu;
    // 802CE99C: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE9A0:
    ctx->pc = 0x802CE9A0u;
    // 802CE9A0: stw     r8, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_802CE9A4:
    ctx->pc = 0x802CE9A4u;
    // 802CE9A4: lwz     r0, 1268(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CE9A8:
    ctx->pc = 0x802CE9A8u;
    // 802CE9A8: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_802CE9AC:
    ctx->pc = 0x802CE9ACu;
    // 802CE9AC: stw     r0, 1268(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CE9B0:
    ctx->pc = 0x802CE9B0u;
    // 802CE9B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE9B4:
    ctx->pc = 0x802CE9B4u;
    ctx->downcount -= 2;
    // 802CE9B4: cmpwi   r3, 2
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE9B8:
    ctx->pc = 0x802CE9B8u;
    // 802CE9B8: bc    12, 2, 0x802CEA18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CEA18;
        }
    }

label_802CE9BC:
    ctx->pc = 0x802CE9BCu;
    ctx->downcount -= 1;
    // 802CE9BC: bc    4, 0, 0x802CE9D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE9D0;
        }
    }

label_802CE9C0:
    ctx->pc = 0x802CE9C0u;
    ctx->downcount -= 2;
    // 802CE9C0: cmpwi   r3, 0
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

label_802CE9C4:
    ctx->pc = 0x802CE9C4u;
    // 802CE9C4: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE9C8:
    ctx->pc = 0x802CE9C8u;
    ctx->downcount -= 1;
    // 802CE9C8: bc    4, 0, 0x802CE9DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802CE9DC;
        }
    }

label_802CE9CC:
    ctx->pc = 0x802CE9CCu;
    ctx->downcount -= 1;
    // 802CE9CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE9D0:
    ctx->pc = 0x802CE9D0u;
    ctx->downcount -= 2;
    // 802CE9D0: cmpwi   r3, 4
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CE9D4:
    ctx->pc = 0x802CE9D4u;
    // 802CE9D4: bclr  4, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CE9D8:
    ctx->pc = 0x802CE9D8u;
    ctx->downcount -= 1;
    // 802CE9D8: b       0x802CEA30
    {
            goto label_802CEA30;
    }

label_802CE9DC:
    ctx->pc = 0x802CE9DCu;
    ctx->downcount -= 11;
    // 802CE9DC: lwz     r5, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CE9E0:
    ctx->pc = 0x802CE9E0u;
    // 802CE9E0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802CE9E4:
    ctx->pc = 0x802CE9E4u;
    // 802CE9E4: sth     r4, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_802CE9E8:
    ctx->pc = 0x802CE9E8u;
    // 802CE9E8: lhz     r3, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CE9EC:
    ctx->pc = 0x802CE9ECu;
    // 802CE9EC: cntlzw r3, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[3] = n;
    }

label_802CE9F0:
    ctx->pc = 0x802CE9F0u;
    // 802CE9F0: rlwinm r3, r3, 27, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 27u) & 0x0000FFFFu;
    }

label_802CE9F4:
    ctx->pc = 0x802CE9F4u;
    // 802CE9F4: sth     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_802CE9F8:
    ctx->pc = 0x802CE9F8u;
    // 802CE9F8: sth     r0, 2(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CE9FC:
    ctx->pc = 0x802CE9FCu;
    // 802CE9FC: lhz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CEA00:
    ctx->pc = 0x802CEA00u;
    // 802CEA00: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEA04:
    ctx->pc = 0x802CEA04u;
    // 802CEA04: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CEA08:
    ctx->pc = 0x802CEA08u;
    ctx->downcount -= 4;
    // 802CEA08: lwz     r0, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CEA0C:
    ctx->pc = 0x802CEA0Cu;
    // 802CEA0C: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_802CEA10:
    ctx->pc = 0x802CEA10u;
    // 802CEA10: stw     r0, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEA14:
    ctx->pc = 0x802CEA14u;
    // 802CEA14: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CEA18:
    ctx->pc = 0x802CEA18u;
    ctx->downcount -= 6;
    // 802CEA18: neg  r4, r4
    {
        u32 a = ctx->gpr[4];
        ctx->gpr[4] = (~a) + 1u;
    }

label_802CEA1C:
    ctx->pc = 0x802CEA1Cu;
    // 802CEA1C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CEA20:
    ctx->pc = 0x802CEA20u;
    // 802CEA20: addic   r0, r4, -1
    {
        u64 a = ctx->gpr[4];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802CEA24:
    ctx->pc = 0x802CEA24u;
    // 802CEA24: subfe   r0, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEA28:
    ctx->pc = 0x802CEA28u;
    // 802CEA28: stb     r0, 1265(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1265);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CEA2C:
    ctx->pc = 0x802CEA2Cu;
    // 802CEA2C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CEA30:
    ctx->pc = 0x802CEA30u;
    ctx->downcount -= 6;
    // 802CEA30: neg  r4, r4
    {
        u32 a = ctx->gpr[4];
        ctx->gpr[4] = (~a) + 1u;
    }

label_802CEA34:
    ctx->pc = 0x802CEA34u;
    // 802CEA34: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CEA38:
    ctx->pc = 0x802CEA38u;
    // 802CEA38: addic   r0, r4, -1
    {
        u64 a = ctx->gpr[4];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802CEA3C:
    ctx->pc = 0x802CEA3Cu;
    // 802CEA3C: subfe   r0, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEA40:
    ctx->pc = 0x802CEA40u;
    // 802CEA40: stb     r0, 1266(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1266);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CEA44:
    ctx->pc = 0x802CEA44u;
    // 802CEA44: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CEA48:
    ctx->pc = 0x802CEA48u;
    ctx->downcount -= 7;
    // 802CEA48: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CEA4C:
    ctx->pc = 0x802CEA4Cu;
    // 802CEA4C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEA50:
    ctx->pc = 0x802CEA50u;
    // 802CEA50: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CEA54:
    ctx->pc = 0x802CEA54u;
    // 802CEA54: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CEA58:
    ctx->pc = 0x802CEA58u;
    // 802CEA58: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CEA5C:
    ctx->pc = 0x802CEA5Cu;
    // 802CEA5C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEA60:
    ctx->pc = 0x802CEA60u;
    // 802CEA60: bc    12, 2, 0x802CEA68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CEA68;
        }
    }

label_802CEA64:
    ctx->pc = 0x802CEA64u;
    ctx->downcount -= 1;
    // 802CEA64: bl      0x802CF798
    {
            ctx->lr = 0x802CEA68u;
            ctx->pc = 0x802CF798u;
            return;
    }

label_802CEA68:
    ctx->pc = 0x802CEA68u;
    ctx->downcount -= 11;
    // 802CEA68: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CEA6C:
    ctx->pc = 0x802CEA6Cu;
    // 802CEA6C: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_802CEA70:
    ctx->pc = 0x802CEA70u;
    // 802CEA70: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEA74:
    ctx->pc = 0x802CEA74u;
    // 802CEA74: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEA78:
    ctx->pc = 0x802CEA78u;
    // 802CEA78: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEA7C:
    ctx->pc = 0x802CEA7Cu;
    // 802CEA7C: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEA80:
    ctx->pc = 0x802CEA80u;
    // 802CEA80: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEA84:
    ctx->pc = 0x802CEA84u;
    // 802CEA84: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEA88:
    ctx->pc = 0x802CEA88u;
    // 802CEA88: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEA8C:
    ctx->pc = 0x802CEA8Cu;
    // 802CEA8C: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEA90:
    ctx->pc = 0x802CEA90u;
    // 802CEA90: bl      0x802D641C
    {
            ctx->lr = 0x802CEA94u;
            ctx->pc = 0x802D641Cu;
            return;
    }

label_802CEA94:
    ctx->pc = 0x802CEA94u;
    ctx->downcount -= 5;
    // 802CEA94: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CEA98:
    ctx->pc = 0x802CEA98u;
    // 802CEA98: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802CEA9C:
    ctx->pc = 0x802CEA9Cu;
    // 802CEA9C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CEAA0:
    ctx->pc = 0x802CEAA0u;
    // 802CEAA0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CEAA4:
    ctx->pc = 0x802CEAA4u;
    ctx->downcount -= 3;
    // 802CEAA4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CEAA8:
    ctx->pc = 0x802CEAA8u;
    // 802CEAA8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEAAC:
    ctx->pc = 0x802CEAACu;
    // 802CEAAC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CEAB0:
    ctx->downcount -= 1;
    // 802CEAB0: bl      0x802D6534
    {
            ctx->lr = 0x802CEAB4u;
            ctx->pc = 0x802D6534u;
            return;
    }

label_802CEAB4:
    ctx->downcount -= 2;
    // 802CEAB4: rlwinm. r0, r3, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CEAB8:
    // 802CEAB8: bc    4, 2, 0x802CEAB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEAB0u;
                return;
            }
            goto label_802CEAB0;
        }
    }

label_802CEABC:
    ctx->pc = 0x802CEABCu;
    ctx->downcount -= 3;
    // 802CEABC: lis     r3, 3073
    ctx->gpr[3] = ((u32)(s32)(3073) << 16);

label_802CEAC0:
    ctx->pc = 0x802CEAC0u;
    // 802CEAC0: addi    r3, r3, -32768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32768);

label_802CEAC4:
    ctx->pc = 0x802CEAC4u;
    // 802CEAC4: bl      0x802D6540
    {
            ctx->lr = 0x802CEAC8u;
            ctx->pc = 0x802D6540u;
            return;
    }

label_802CEAC8:
    ctx->pc = 0x802CEAC8u;
    ctx->downcount -= 5;
    // 802CEAC8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CEACC:
    ctx->pc = 0x802CEACCu;
    // 802CEACC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802CEAD0:
    ctx->pc = 0x802CEAD0u;
    // 802CEAD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CEAD4:
    ctx->pc = 0x802CEAD4u;
    // 802CEAD4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CEAD8:
    ctx->pc = 0x802CEAD8u;
    ctx->downcount -= 9;
    // 802CEAD8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CEADC:
    ctx->pc = 0x802CEADCu;
    // 802CEADC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEAE0:
    ctx->pc = 0x802CEAE0u;
    // 802CEAE0: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CEAE4:
    ctx->pc = 0x802CEAE4u;
    // 802CEAE4: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CEAE8:
    ctx->pc = 0x802CEAE8u;
    // 802CEAE8: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CEAEC:
    ctx->pc = 0x802CEAECu;
    // 802CEAEC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CEAF0:
    ctx->pc = 0x802CEAF0u;
    // 802CEAF0: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802CEAF4:
    ctx->pc = 0x802CEAF4u;
    // 802CEAF4: stw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_802CEAF8:
    ctx->pc = 0x802CEAF8u;
    // 802CEAF8: bl      0x802C927C
    {
            ctx->lr = 0x802CEAFCu;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEAFC:
    ctx->pc = 0x802CEAFCu;
    ctx->downcount -= 5;
    // 802CEAFC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CEB00:
    ctx->pc = 0x802CEB00u;
    // 802CEB00: addi    r28, r4, 0
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(0);

label_802CEB04:
    ctx->pc = 0x802CEB04u;
    // 802CEB04: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802CEB08:
    ctx->pc = 0x802CEB08u;
    // 802CEB08: rlwinm r30, r30, 30, 2, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 30u) & 0x3FFFFFFFu;
    }

label_802CEB0C:
    ctx->pc = 0x802CEB0Cu;
    // 802CEB0C: xoris   r31, r0, 0x8000
    ctx->gpr[31] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CEB10:
    ctx->downcount -= 1;
    // 802CEB10: bl      0x802C927C
    {
            ctx->lr = 0x802CEB14u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEB14:
    ctx->downcount -= 8;
    // 802CEB14: subfc   r4, r28, r4
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEB18:
    // 802CEB18: subfe   r0, r29, r3
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEB1C:
    // 802CEB1C: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CEB20:
    // 802CEB20: subfc   r0, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEB24:
    // 802CEB24: subfe   r3, r3, r31
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEB28:
    // 802CEB28: subfe   r3, r31, r31
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEB2C:
    // 802CEB2C: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CEB30:
    // 802CEB30: bc    12, 2, 0x802CEB10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEB10u;
                return;
            }
            goto label_802CEB10;
        }
    }

label_802CEB34:
    ctx->pc = 0x802CEB34u;
    ctx->downcount -= 9;
    // 802CEB34: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CEB38:
    ctx->pc = 0x802CEB38u;
    // 802CEB38: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CEB3C:
    ctx->pc = 0x802CEB3Cu;
    // 802CEB3C: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CEB40:
    ctx->pc = 0x802CEB40u;
    // 802CEB40: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802CEB44:
    ctx->pc = 0x802CEB44u;
    // 802CEB44: lwz     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_802CEB48:
    ctx->pc = 0x802CEB48u;
    // 802CEB48: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802CEB4C:
    ctx->pc = 0x802CEB4Cu;
    // 802CEB4C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CEB50:
    ctx->pc = 0x802CEB50u;
    // 802CEB50: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CEB54:
    ctx->pc = 0x802CEB54u;
    ctx->downcount -= 18;
    // 802CEB54: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CEB58:
    ctx->pc = 0x802CEB58u;
    // 802CEB58: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEB5C:
    ctx->pc = 0x802CEB5Cu;
    // 802CEB5C: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CEB60:
    ctx->pc = 0x802CEB60u;
    // 802CEB60: stmw     r27, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802CEB64:
    ctx->pc = 0x802CEB64u;
    // 802CEB64: lwz     r3, -25388(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25388);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CEB68:
    ctx->pc = 0x802CEB68u;
    // 802CEB68: lhz     r4, 78(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(78);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CEB6C:
    ctx->pc = 0x802CEB6Cu;
    // 802CEB6C: addi    r6, r3, 78
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(78);

label_802CEB70:
    ctx->pc = 0x802CEB70u;
    // 802CEB70: addi    r5, r3, 80
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(80);

label_802CEB74:
    loop_802CEB74(ctx);
    if (ctx->pc == 0x802CEB88u) goto label_802CEB88;
    return;
label_802CEB78:
    ctx->pc = 0x802CEB78u;
    // 802CEB78: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CEB7C:
    ctx->pc = 0x802CEB7Cu;
    // 802CEB7C: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CEB80:
    // 802CEB80: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEB84:
    // 802CEB84: bc    4, 2, 0x802CEB74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEB74u;
                return;
            }
            goto label_802CEB74;
        }
    }

label_802CEB88:
    ctx->pc = 0x802CEB88u;
    ctx->downcount -= 2;
    // 802CEB88: rlwinm r0, r4, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 16u) & 0xFFFF0000u;
    }

label_802CEB8C:
    ctx->pc = 0x802CEB8Cu;
    // 802CEB8C: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_802CEB90:
    ctx->downcount -= 2;
    // 802CEB90: or   r27, r0, r0
    {
        ctx->gpr[27] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802CEB94:
    // 802CEB94: bl      0x802C927C
    {
            ctx->lr = 0x802CEB98u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEB98:
    ctx->downcount -= 5;
    // 802CEB98: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CEB9C:
    // 802CEB9C: addi    r28, r4, 0
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(0);

label_802CEBA0:
    // 802CEBA0: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802CEBA4:
    // 802CEBA4: xoris   r31, r0, 0x8000
    ctx->gpr[31] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CEBA8:
    // 802CEBA8: li      r30, 8
    ctx->gpr[30] = (u32)(s32)(8);

label_802CEBAC:
    ctx->downcount -= 1;
    // 802CEBAC: bl      0x802C927C
    {
            ctx->lr = 0x802CEBB0u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEBB0:
    ctx->downcount -= 8;
    // 802CEBB0: subfc   r4, r28, r4
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEBB4:
    // 802CEBB4: subfe   r0, r29, r3
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEBB8:
    // 802CEBB8: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CEBBC:
    // 802CEBBC: subfc   r0, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEBC0:
    // 802CEBC0: subfe   r3, r3, r31
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEBC4:
    // 802CEBC4: subfe   r3, r31, r31
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEBC8:
    // 802CEBC8: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CEBCC:
    // 802CEBCC: bc    12, 2, 0x802CEBAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEBACu;
                return;
            }
            goto label_802CEBAC;
        }
    }

label_802CEBD0:
    ctx->pc = 0x802CEBD0u;
    ctx->downcount -= 4;
    // 802CEBD0: lwz     r3, -25388(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25388);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CEBD4:
    // 802CEBD4: addi    r6, r3, 78
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(78);

label_802CEBD8:
    ctx->pc = 0x802CEBD8u;
    // 802CEBD8: lhz     r4, 78(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(78);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CEBDC:
    // 802CEBDC: addi    r5, r3, 80
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(80);

label_802CEBE0:
    loop_802CEBE0(ctx);
    if (ctx->pc == 0x802CEBF4u) goto label_802CEBF4;
    return;
label_802CEBE4:
    ctx->pc = 0x802CEBE4u;
    // 802CEBE4: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CEBE8:
    ctx->pc = 0x802CEBE8u;
    // 802CEBE8: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CEBEC:
    // 802CEBEC: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEBF0:
    // 802CEBF0: bc    4, 2, 0x802CEBE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEBE0u;
                return;
            }
            goto label_802CEBE0;
        }
    }

label_802CEBF4:
    ctx->downcount -= 4;
    // 802CEBF4: rlwinm r0, r4, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 16u) & 0xFFFF0000u;
    }

label_802CEBF8:
    // 802CEBF8: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_802CEBFC:
    // 802CEBFC: cmplw   r0, r27
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEC00:
    // 802CEC00: bc    4, 2, 0x802CEB90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEB90u;
                return;
            }
            goto label_802CEB90;
        }
    }

label_802CEC04:
    ctx->pc = 0x802CEC04u;
    ctx->downcount -= 16;
    // 802CEC04: lmw     r27, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802CEC08:
    ctx->pc = 0x802CEC08u;
    // 802CEC08: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CEC0C:
    ctx->pc = 0x802CEC0Cu;
    // 802CEC0C: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_802CEC10:
    ctx->pc = 0x802CEC10u;
    // 802CEC10: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CEC14:
    ctx->pc = 0x802CEC14u;
    // 802CEC14: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CEC18:
    ctx->pc = 0x802CEC18u;
    ctx->downcount -= 18;
    // 802CEC18: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CEC1C:
    ctx->pc = 0x802CEC1Cu;
    // 802CEC1C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEC20:
    ctx->pc = 0x802CEC20u;
    // 802CEC20: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CEC24:
    ctx->pc = 0x802CEC24u;
    // 802CEC24: stmw     r27, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802CEC28:
    ctx->pc = 0x802CEC28u;
    // 802CEC28: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CEC2C:
    ctx->pc = 0x802CEC2Cu;
    // 802CEC2C: lbz     r0, 1266(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1266);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CEC30:
    ctx->pc = 0x802CEC30u;
    // 802CEC30: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEC34:
    ctx->pc = 0x802CEC34u;
    // 802CEC34: bc    12, 2, 0x802CECE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CECE4;
        }
    }

label_802CEC38:
    ctx->pc = 0x802CEC38u;
    ctx->downcount -= 1;
    // 802CEC38: bl      0x802CCCEC
    {
            ctx->lr = 0x802CEC3Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CCCECu;
                return;
            }
            goto label_802CCCEC;
    }

label_802CEC3C:
    ctx->pc = 0x802CEC3Cu;
    ctx->downcount -= 2;
    // 802CEC3C: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEC40:
    ctx->pc = 0x802CEC40u;
    // 802CEC40: bc    12, 2, 0x802CECE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CECE4;
        }
    }

label_802CEC44:
    ctx->pc = 0x802CEC44u;
    ctx->downcount -= 4;
    // 802CEC44: lwz     r3, -25388(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25388);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CEC48:
    ctx->pc = 0x802CEC48u;
    // 802CEC48: addi    r6, r3, 78
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(78);

label_802CEC4C:
    ctx->pc = 0x802CEC4Cu;
    // 802CEC4C: lhz     r4, 78(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(78);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CEC50:
    ctx->pc = 0x802CEC50u;
    // 802CEC50: addi    r5, r3, 80
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(80);

label_802CEC54:
    loop_802CEC54(ctx);
    if (ctx->pc == 0x802CEC68u) goto label_802CEC68;
    return;
label_802CEC58:
    ctx->pc = 0x802CEC58u;
    // 802CEC58: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CEC5C:
    ctx->pc = 0x802CEC5Cu;
    // 802CEC5C: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CEC60:
    // 802CEC60: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEC64:
    // 802CEC64: bc    4, 2, 0x802CEC54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEC54u;
                return;
            }
            goto label_802CEC54;
        }
    }

label_802CEC68:
    ctx->pc = 0x802CEC68u;
    ctx->downcount -= 2;
    // 802CEC68: rlwinm r0, r4, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 16u) & 0xFFFF0000u;
    }

label_802CEC6C:
    ctx->pc = 0x802CEC6Cu;
    // 802CEC6C: or   r27, r0, r3
    {
        ctx->gpr[27] = ctx->gpr[0] | ctx->gpr[3];
    }

label_802CEC70:
    ctx->downcount -= 1;
    // 802CEC70: bl      0x802C927C
    {
            ctx->lr = 0x802CEC74u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEC74:
    ctx->downcount -= 5;
    // 802CEC74: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CEC78:
    // 802CEC78: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_802CEC7C:
    // 802CEC7C: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_802CEC80:
    // 802CEC80: xoris   r28, r0, 0x8000
    ctx->gpr[28] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CEC84:
    // 802CEC84: li      r29, 8
    ctx->gpr[29] = (u32)(s32)(8);

label_802CEC88:
    ctx->downcount -= 1;
    // 802CEC88: bl      0x802C927C
    {
            ctx->lr = 0x802CEC8Cu;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEC8C:
    ctx->downcount -= 8;
    // 802CEC8C: subfc   r4, r31, r4
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEC90:
    // 802CEC90: subfe   r0, r30, r3
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEC94:
    // 802CEC94: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CEC98:
    // 802CEC98: subfc   r0, r4, r29
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[29];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEC9C:
    // 802CEC9C: subfe   r3, r3, r28
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CECA0:
    // 802CECA0: subfe   r3, r28, r28
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CECA4:
    // 802CECA4: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CECA8:
    // 802CECA8: bc    12, 2, 0x802CEC88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEC88u;
                return;
            }
            goto label_802CEC88;
        }
    }

label_802CECAC:
    ctx->pc = 0x802CECACu;
    ctx->downcount -= 4;
    // 802CECAC: lwz     r3, -25388(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25388);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CECB0:
    // 802CECB0: addi    r6, r3, 78
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(78);

label_802CECB4:
    ctx->pc = 0x802CECB4u;
    // 802CECB4: lhz     r4, 78(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(78);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CECB8:
    // 802CECB8: addi    r5, r3, 80
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(80);

label_802CECBC:
    loop_802CECBC(ctx);
    if (ctx->pc == 0x802CECD0u) goto label_802CECD0;
    return;
label_802CECC0:
    ctx->pc = 0x802CECC0u;
    // 802CECC0: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CECC4:
    ctx->pc = 0x802CECC4u;
    // 802CECC4: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CECC8:
    // 802CECC8: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CECCC:
    // 802CECCC: bc    4, 2, 0x802CECBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CECBCu;
                return;
            }
            goto label_802CECBC;
        }
    }

label_802CECD0:
    ctx->downcount -= 5;
    // 802CECD0: rlwinm r0, r4, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 16u) & 0xFFFF0000u;
    }

label_802CECD4:
    // 802CECD4: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_802CECD8:
    // 802CECD8: cmplw   r0, r27
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CECDC:
    // 802CECDC: or   r27, r0, r0
    {
        ctx->gpr[27] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802CECE0:
    // 802CECE0: bc    4, 2, 0x802CEC70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEC70u;
                return;
            }
            goto label_802CEC70;
        }
    }

label_802CECE4:
    ctx->pc = 0x802CECE4u;
    ctx->downcount -= 5;
    // 802CECE4: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_802CECE8:
    ctx->pc = 0x802CECE8u;
    // 802CECE8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802CECEC:
    ctx->pc = 0x802CECECu;
    // 802CECEC: addi    r27, r3, 12288
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(12288);

label_802CECF0:
    ctx->pc = 0x802CECF0u;
    // 802CECF0: stwu     r0, 24(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
        ctx->gpr[27] = ea;
    }

label_802CECF4:
    ctx->pc = 0x802CECF4u;
    // 802CECF4: bl      0x802C927C
    {
            ctx->lr = 0x802CECF8u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CECF8:
    ctx->pc = 0x802CECF8u;
    ctx->downcount -= 5;
    // 802CECF8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CECFC:
    ctx->pc = 0x802CECFCu;
    // 802CECFC: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_802CED00:
    ctx->pc = 0x802CED00u;
    // 802CED00: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_802CED04:
    ctx->pc = 0x802CED04u;
    // 802CED04: xoris   r28, r0, 0x8000
    ctx->gpr[28] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CED08:
    ctx->pc = 0x802CED08u;
    // 802CED08: li      r29, 50
    ctx->gpr[29] = (u32)(s32)(50);

label_802CED0C:
    ctx->downcount -= 1;
    // 802CED0C: bl      0x802C927C
    {
            ctx->lr = 0x802CED10u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CED10:
    ctx->downcount -= 8;
    // 802CED10: subfc   r4, r31, r4
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CED14:
    // 802CED14: subfe   r0, r30, r3
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CED18:
    // 802CED18: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CED1C:
    // 802CED1C: subfc   r0, r4, r29
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[29];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CED20:
    // 802CED20: subfe   r3, r3, r28
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CED24:
    // 802CED24: subfe   r3, r28, r28
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CED28:
    // 802CED28: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CED2C:
    // 802CED2C: bc    12, 2, 0x802CED0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CED0Cu;
                return;
            }
            goto label_802CED0C;
        }
    }

label_802CED30:
    ctx->pc = 0x802CED30u;
    ctx->downcount -= 3;
    // 802CED30: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_802CED34:
    ctx->pc = 0x802CED34u;
    // 802CED34: stw     r30, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CED38:
    ctx->pc = 0x802CED38u;
    // 802CED38: bl      0x802C927C
    {
            ctx->lr = 0x802CED3Cu;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CED3C:
    ctx->pc = 0x802CED3Cu;
    ctx->downcount -= 4;
    // 802CED3C: addi    r28, r4, 0
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(0);

label_802CED40:
    ctx->pc = 0x802CED40u;
    // 802CED40: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802CED44:
    ctx->pc = 0x802CED44u;
    // 802CED44: xoris   r31, r30, 0x8000
    ctx->gpr[31] = ctx->gpr[30] ^ (0x8000u << 16);

label_802CED48:
    ctx->pc = 0x802CED48u;
    // 802CED48: li      r30, 5
    ctx->gpr[30] = (u32)(s32)(5);

label_802CED4C:
    ctx->downcount -= 1;
    // 802CED4C: bl      0x802C927C
    {
            ctx->lr = 0x802CED50u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CED50:
    ctx->downcount -= 8;
    // 802CED50: subfc   r4, r28, r4
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CED54:
    // 802CED54: subfe   r0, r29, r3
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CED58:
    // 802CED58: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CED5C:
    // 802CED5C: subfc   r0, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CED60:
    // 802CED60: subfe   r3, r3, r31
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CED64:
    // 802CED64: subfe   r3, r31, r31
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CED68:
    // 802CED68: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CED6C:
    // 802CED6C: bc    12, 2, 0x802CED4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CED4Cu;
                return;
            }
            goto label_802CED4C;
        }
    }

label_802CED70:
    ctx->pc = 0x802CED70u;
    ctx->downcount -= 16;
    // 802CED70: lmw     r27, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802CED74:
    ctx->pc = 0x802CED74u;
    // 802CED74: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CED78:
    ctx->pc = 0x802CED78u;
    // 802CED78: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_802CED7C:
    ctx->pc = 0x802CED7Cu;
    // 802CED7C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CED80:
    ctx->pc = 0x802CED80u;
    // 802CED80: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CED84:
    ctx->pc = 0x802CED84u;
    ctx->downcount -= 18;
    // 802CED84: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CED88:
    ctx->pc = 0x802CED88u;
    // 802CED88: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CED8C:
    ctx->pc = 0x802CED8Cu;
    // 802CED8C: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CED90:
    ctx->pc = 0x802CED90u;
    // 802CED90: stmw     r27, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802CED94:
    ctx->pc = 0x802CED94u;
    // 802CED94: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CED98:
    ctx->pc = 0x802CED98u;
    // 802CED98: lbz     r0, 1266(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1266);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CED9C:
    ctx->pc = 0x802CED9Cu;
    // 802CED9C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEDA0:
    ctx->pc = 0x802CEDA0u;
    // 802CEDA0: bc    12, 2, 0x802CEE50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CEE50;
        }
    }

label_802CEDA4:
    ctx->pc = 0x802CEDA4u;
    ctx->downcount -= 1;
    // 802CEDA4: bl      0x802CCCEC
    {
            ctx->lr = 0x802CEDA8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CCCECu;
                return;
            }
            goto label_802CCCEC;
    }

label_802CEDA8:
    ctx->pc = 0x802CEDA8u;
    ctx->downcount -= 2;
    // 802CEDA8: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEDAC:
    ctx->pc = 0x802CEDACu;
    // 802CEDAC: bc    12, 2, 0x802CEE50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CEE50;
        }
    }

label_802CEDB0:
    ctx->pc = 0x802CEDB0u;
    ctx->downcount -= 4;
    // 802CEDB0: lwz     r3, -25388(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25388);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CEDB4:
    ctx->pc = 0x802CEDB4u;
    // 802CEDB4: addi    r6, r3, 78
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(78);

label_802CEDB8:
    ctx->pc = 0x802CEDB8u;
    // 802CEDB8: lhz     r4, 78(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(78);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CEDBC:
    ctx->pc = 0x802CEDBCu;
    // 802CEDBC: addi    r5, r3, 80
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(80);

label_802CEDC0:
    loop_802CEDC0(ctx);
    if (ctx->pc == 0x802CEDD4u) goto label_802CEDD4;
    return;
label_802CEDC4:
    ctx->pc = 0x802CEDC4u;
    // 802CEDC4: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CEDC8:
    ctx->pc = 0x802CEDC8u;
    // 802CEDC8: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CEDCC:
    // 802CEDCC: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEDD0:
    // 802CEDD0: bc    4, 2, 0x802CEDC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEDC0u;
                return;
            }
            goto label_802CEDC0;
        }
    }

label_802CEDD4:
    ctx->pc = 0x802CEDD4u;
    ctx->downcount -= 2;
    // 802CEDD4: rlwinm r0, r4, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 16u) & 0xFFFF0000u;
    }

label_802CEDD8:
    ctx->pc = 0x802CEDD8u;
    // 802CEDD8: or   r27, r0, r3
    {
        ctx->gpr[27] = ctx->gpr[0] | ctx->gpr[3];
    }

label_802CEDDC:
    ctx->downcount -= 1;
    // 802CEDDC: bl      0x802C927C
    {
            ctx->lr = 0x802CEDE0u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEDE0:
    ctx->downcount -= 5;
    // 802CEDE0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CEDE4:
    // 802CEDE4: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_802CEDE8:
    // 802CEDE8: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_802CEDEC:
    // 802CEDEC: xoris   r28, r0, 0x8000
    ctx->gpr[28] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CEDF0:
    // 802CEDF0: li      r29, 8
    ctx->gpr[29] = (u32)(s32)(8);

label_802CEDF4:
    ctx->downcount -= 1;
    // 802CEDF4: bl      0x802C927C
    {
            ctx->lr = 0x802CEDF8u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEDF8:
    ctx->downcount -= 8;
    // 802CEDF8: subfc   r4, r31, r4
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEDFC:
    // 802CEDFC: subfe   r0, r30, r3
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEE00:
    // 802CEE00: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CEE04:
    // 802CEE04: subfc   r0, r4, r29
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[29];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEE08:
    // 802CEE08: subfe   r3, r3, r28
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEE0C:
    // 802CEE0C: subfe   r3, r28, r28
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEE10:
    // 802CEE10: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CEE14:
    // 802CEE14: bc    12, 2, 0x802CEDF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEDF4u;
                return;
            }
            goto label_802CEDF4;
        }
    }

label_802CEE18:
    ctx->pc = 0x802CEE18u;
    ctx->downcount -= 4;
    // 802CEE18: lwz     r3, -25388(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25388);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CEE1C:
    // 802CEE1C: addi    r6, r3, 78
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(78);

label_802CEE20:
    ctx->pc = 0x802CEE20u;
    // 802CEE20: lhz     r4, 78(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(78);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CEE24:
    // 802CEE24: addi    r5, r3, 80
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(80);

label_802CEE28:
    loop_802CEE28(ctx);
    if (ctx->pc == 0x802CEE3Cu) goto label_802CEE3C;
    return;
label_802CEE2C:
    ctx->pc = 0x802CEE2Cu;
    // 802CEE2C: lhz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802CEE30:
    ctx->pc = 0x802CEE30u;
    // 802CEE30: lhz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CEE34:
    // 802CEE34: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEE38:
    // 802CEE38: bc    4, 2, 0x802CEE28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEE28u;
                return;
            }
            goto label_802CEE28;
        }
    }

label_802CEE3C:
    ctx->downcount -= 5;
    // 802CEE3C: rlwinm r0, r4, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 16u) & 0xFFFF0000u;
    }

label_802CEE40:
    // 802CEE40: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_802CEE44:
    // 802CEE44: cmplw   r0, r27
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEE48:
    // 802CEE48: or   r27, r0, r0
    {
        ctx->gpr[27] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802CEE4C:
    // 802CEE4C: bc    4, 2, 0x802CEDDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEDDCu;
                return;
            }
            goto label_802CEDDC;
        }
    }

label_802CEE50:
    ctx->pc = 0x802CEE50u;
    ctx->downcount -= 5;
    // 802CEE50: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_802CEE54:
    ctx->pc = 0x802CEE54u;
    // 802CEE54: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802CEE58:
    ctx->pc = 0x802CEE58u;
    // 802CEE58: addi    r27, r3, 12288
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(12288);

label_802CEE5C:
    ctx->pc = 0x802CEE5Cu;
    // 802CEE5C: stwu     r0, 24(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
        ctx->gpr[27] = ea;
    }

label_802CEE60:
    ctx->pc = 0x802CEE60u;
    // 802CEE60: bl      0x802C927C
    {
            ctx->lr = 0x802CEE64u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEE64:
    ctx->pc = 0x802CEE64u;
    ctx->downcount -= 5;
    // 802CEE64: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CEE68:
    ctx->pc = 0x802CEE68u;
    // 802CEE68: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_802CEE6C:
    ctx->pc = 0x802CEE6Cu;
    // 802CEE6C: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_802CEE70:
    ctx->pc = 0x802CEE70u;
    // 802CEE70: xoris   r28, r0, 0x8000
    ctx->gpr[28] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CEE74:
    ctx->pc = 0x802CEE74u;
    // 802CEE74: li      r29, 50
    ctx->gpr[29] = (u32)(s32)(50);

label_802CEE78:
    ctx->downcount -= 1;
    // 802CEE78: bl      0x802C927C
    {
            ctx->lr = 0x802CEE7Cu;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEE7C:
    ctx->downcount -= 8;
    // 802CEE7C: subfc   r4, r31, r4
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEE80:
    // 802CEE80: subfe   r0, r30, r3
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEE84:
    // 802CEE84: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CEE88:
    // 802CEE88: subfc   r0, r4, r29
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[29];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEE8C:
    // 802CEE8C: subfe   r3, r3, r28
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEE90:
    // 802CEE90: subfe   r3, r28, r28
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEE94:
    // 802CEE94: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CEE98:
    // 802CEE98: bc    12, 2, 0x802CEE78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEE78u;
                return;
            }
            goto label_802CEE78;
        }
    }

label_802CEE9C:
    ctx->pc = 0x802CEE9Cu;
    ctx->downcount -= 3;
    // 802CEE9C: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_802CEEA0:
    ctx->pc = 0x802CEEA0u;
    // 802CEEA0: stw     r30, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CEEA4:
    ctx->pc = 0x802CEEA4u;
    // 802CEEA4: bl      0x802C927C
    {
            ctx->lr = 0x802CEEA8u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEEA8:
    ctx->pc = 0x802CEEA8u;
    ctx->downcount -= 4;
    // 802CEEA8: addi    r28, r4, 0
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(0);

label_802CEEAC:
    ctx->pc = 0x802CEEACu;
    // 802CEEAC: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802CEEB0:
    ctx->pc = 0x802CEEB0u;
    // 802CEEB0: xoris   r31, r30, 0x8000
    ctx->gpr[31] = ctx->gpr[30] ^ (0x8000u << 16);

label_802CEEB4:
    ctx->pc = 0x802CEEB4u;
    // 802CEEB4: li      r30, 5
    ctx->gpr[30] = (u32)(s32)(5);

label_802CEEB8:
    ctx->downcount -= 1;
    // 802CEEB8: bl      0x802C927C
    {
            ctx->lr = 0x802CEEBCu;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802CEEBC:
    ctx->downcount -= 8;
    // 802CEEBC: subfc   r4, r28, r4
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEEC0:
    // 802CEEC0: subfe   r0, r29, r3
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEEC4:
    // 802CEEC4: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_802CEEC8:
    // 802CEEC8: subfc   r0, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEECC:
    // 802CEECC: subfe   r3, r3, r31
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEED0:
    // 802CEED0: subfe   r3, r31, r31
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802CEED4:
    // 802CEED4: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802CEED8:
    // 802CEED8: bc    12, 2, 0x802CEEB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEEB8u;
                return;
            }
            goto label_802CEEB8;
        }
    }

label_802CEEDC:
    ctx->pc = 0x802CEEDCu;
    ctx->downcount -= 1;
    // 802CEEDC: bl      0x802CCB90
    {
            ctx->lr = 0x802CEEE0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CCB90u;
                return;
            }
            goto label_802CCB90;
    }

label_802CEEE0:
    ctx->pc = 0x802CEEE0u;
    ctx->downcount -= 16;
    // 802CEEE0: lmw     r27, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802CEEE4:
    ctx->pc = 0x802CEEE4u;
    // 802CEEE4: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CEEE8:
    ctx->pc = 0x802CEEE8u;
    // 802CEEE8: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_802CEEEC:
    ctx->pc = 0x802CEEECu;
    // 802CEEEC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CEEF0:
    ctx->pc = 0x802CEEF0u;
    // 802CEEF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CEEF4:
    ctx->pc = 0x802CEEF4u;
    ctx->downcount -= 7;
    // 802CEEF4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CEEF8:
    ctx->pc = 0x802CEEF8u;
    // 802CEEF8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEEFC:
    ctx->pc = 0x802CEEFCu;
    // 802CEEFC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CEF00:
    ctx->pc = 0x802CEF00u;
    // 802CEF00: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CEF04:
    ctx->pc = 0x802CEF04u;
    // 802CEF04: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CEF08:
    ctx->pc = 0x802CEF08u;
    // 802CEF08: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CEF0C:
    ctx->pc = 0x802CEF0Cu;
    // 802CEF0C: bl      0x802C30E8
    {
            ctx->lr = 0x802CEF10u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CEF10:
    ctx->pc = 0x802CEF10u;
    ctx->downcount -= 17;
    // 802CEF10: li      r6, 97
    ctx->gpr[6] = (u32)(s32)(97);

label_802CEF14:
    ctx->pc = 0x802CEF14u;
    // 802CEF14: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CEF18:
    ctx->pc = 0x802CEF18u;
    // 802CEF18: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_802CEF1C:
    ctx->pc = 0x802CEF1Cu;
    // 802CEF1C: rlwinm r0, r30, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x0000FFFFu;
    }

label_802CEF20:
    ctx->pc = 0x802CEF20u;
    // 802CEF20: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_802CEF24:
    ctx->pc = 0x802CEF24u;
    // 802CEF24: oris    r0, r0, 0x4800
    ctx->gpr[0] = ctx->gpr[0] | (0x4800u << 16);

label_802CEF28:
    ctx->pc = 0x802CEF28u;
    // 802CEF28: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEF2C:
    ctx->pc = 0x802CEF2Cu;
    // 802CEF2C: rlwinm r0, r0, 0, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF0000u;
    }

label_802CEF30:
    ctx->pc = 0x802CEF30u;
    // 802CEF30: rlwimi r0, r30, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[30], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_802CEF34:
    ctx->pc = 0x802CEF34u;
    // 802CEF34: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_802CEF38:
    ctx->pc = 0x802CEF38u;
    // 802CEF38: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_802CEF3C:
    ctx->pc = 0x802CEF3Cu;
    // 802CEF3C: oris    r0, r0, 0x4700
    ctx->gpr[0] = ctx->gpr[0] | (0x4700u << 16);

label_802CEF40:
    ctx->pc = 0x802CEF40u;
    // 802CEF40: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEF44:
    ctx->pc = 0x802CEF44u;
    // 802CEF44: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CEF48:
    ctx->pc = 0x802CEF48u;
    // 802CEF48: lwz     r0, 1268(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CEF4C:
    ctx->pc = 0x802CEF4Cu;
    // 802CEF4C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEF50:
    ctx->pc = 0x802CEF50u;
    // 802CEF50: bc    12, 2, 0x802CEF58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CEF58;
        }
    }

label_802CEF54:
    ctx->pc = 0x802CEF54u;
    ctx->downcount -= 1;
    // 802CEF54: bl      0x802CF798
    {
            ctx->lr = 0x802CEF58u;
            ctx->pc = 0x802CF798u;
            return;
    }

label_802CEF58:
    ctx->pc = 0x802CEF58u;
    ctx->downcount -= 11;
    // 802CEF58: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_802CEF5C:
    ctx->pc = 0x802CEF5Cu;
    // 802CEF5C: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_802CEF60:
    ctx->pc = 0x802CEF60u;
    // 802CEF60: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CEF64:
    ctx->pc = 0x802CEF64u;
    // 802CEF64: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CEF68:
    ctx->pc = 0x802CEF68u;
    // 802CEF68: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CEF6C:
    ctx->pc = 0x802CEF6Cu;
    // 802CEF6C: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CEF70:
    ctx->pc = 0x802CEF70u;
    // 802CEF70: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CEF74:
    ctx->pc = 0x802CEF74u;
    // 802CEF74: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CEF78:
    ctx->pc = 0x802CEF78u;
    // 802CEF78: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CEF7C:
    ctx->pc = 0x802CEF7Cu;
    // 802CEF7C: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CEF80:
    ctx->pc = 0x802CEF80u;
    // 802CEF80: bl      0x802D641C
    {
            ctx->lr = 0x802CEF84u;
            ctx->pc = 0x802D641Cu;
            return;
    }

label_802CEF84:
    ctx->pc = 0x802CEF84u;
    ctx->downcount -= 2;
    // 802CEF84: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802CEF88:
    ctx->pc = 0x802CEF88u;
    // 802CEF88: bl      0x802C3110
    {
            ctx->lr = 0x802CEF8Cu;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CEF8C:
    ctx->pc = 0x802CEF8Cu;
    ctx->downcount -= 9;
    // 802CEF8C: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CEF90:
    ctx->pc = 0x802CEF90u;
    // 802CEF90: sth     r31, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[31]);
    }

label_802CEF94:
    ctx->pc = 0x802CEF94u;
    // 802CEF94: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CEF98:
    ctx->pc = 0x802CEF98u;
    // 802CEF98: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CEF9C:
    ctx->pc = 0x802CEF9Cu;
    // 802CEF9C: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CEFA0:
    ctx->pc = 0x802CEFA0u;
    // 802CEFA0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CEFA4:
    ctx->pc = 0x802CEFA4u;
    // 802CEFA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CEFA8:
    ctx->pc = 0x802CEFA8u;
    // 802CEFA8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CEFAC:
    ctx->pc = 0x802CEFACu;
    ctx->downcount -= 3;
    // 802CEFAC: lwz     r3, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CEFB0:
    ctx->pc = 0x802CEFB0u;
    // 802CEFB0: lhz     r3, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802CEFB4:
    ctx->pc = 0x802CEFB4u;
    // 802CEFB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CEFB8:
    ctx->pc = 0x802CEFB8u;
    ctx->downcount -= 6;
    // 802CEFB8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CEFBC:
    ctx->pc = 0x802CEFBCu;
    // 802CEFBC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEFC0:
    ctx->pc = 0x802CEFC0u;
    // 802CEFC0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CEFC4:
    ctx->pc = 0x802CEFC4u;
    // 802CEFC4: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CEFC8:
    ctx->pc = 0x802CEFC8u;
    // 802CEFC8: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CEFCC:
    ctx->pc = 0x802CEFCCu;
    // 802CEFCC: bl      0x802C30E8
    {
            ctx->lr = 0x802CEFD0u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CEFD0:
    ctx->pc = 0x802CEFD0u;
    ctx->downcount -= 11;
    // 802CEFD0: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_802CEFD4:
    ctx->pc = 0x802CEFD4u;
    // 802CEFD4: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CEFD8:
    ctx->pc = 0x802CEFD8u;
    // 802CEFD8: lis     r6, -13311
    ctx->gpr[6] = ((u32)(s32)(-13311) << 16);

label_802CEFDC:
    ctx->pc = 0x802CEFDCu;
    // 802CEFDC: lis     r5, 17664
    ctx->gpr[5] = ((u32)(s32)(17664) << 16);

label_802CEFE0:
    ctx->pc = 0x802CEFE0u;
    // 802CEFE0: stb     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CEFE4:
    ctx->pc = 0x802CEFE4u;
    // 802CEFE4: addi    r0, r5, 2
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(2);

label_802CEFE8:
    ctx->pc = 0x802CEFE8u;
    // 802CEFE8: stw     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CEFEC:
    ctx->pc = 0x802CEFECu;
    // 802CEFEC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CEFF0:
    ctx->pc = 0x802CEFF0u;
    // 802CEFF0: lwz     r0, 1268(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CEFF4:
    ctx->pc = 0x802CEFF4u;
    // 802CEFF4: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CEFF8:
    ctx->pc = 0x802CEFF8u;
    // 802CEFF8: bc    12, 2, 0x802CF000
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CF000;
        }
    }

label_802CEFFC:
    ctx->pc = 0x802CEFFCu;
    ctx->downcount -= 1;
    // 802CEFFC: bl      0x802CF798
    {
            ctx->lr = 0x802CF000u;
            ctx->pc = 0x802CF798u;
            return;
    }

label_802CF000:
    ctx->pc = 0x802CF000u;
    ctx->downcount -= 11;
    // 802CF000: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_802CF004:
    ctx->pc = 0x802CF004u;
    // 802CF004: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_802CF008:
    ctx->pc = 0x802CF008u;
    // 802CF008: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF00C:
    ctx->pc = 0x802CF00Cu;
    // 802CF00C: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF010:
    ctx->pc = 0x802CF010u;
    // 802CF010: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF014:
    ctx->pc = 0x802CF014u;
    // 802CF014: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF018:
    ctx->pc = 0x802CF018u;
    // 802CF018: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF01C:
    ctx->pc = 0x802CF01Cu;
    // 802CF01C: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF020:
    ctx->pc = 0x802CF020u;
    // 802CF020: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF024:
    ctx->pc = 0x802CF024u;
    // 802CF024: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF028:
    ctx->pc = 0x802CF028u;
    // 802CF028: bl      0x802D641C
    {
            ctx->lr = 0x802CF02Cu;
            ctx->pc = 0x802D641Cu;
            return;
    }

label_802CF02C:
    ctx->pc = 0x802CF02Cu;
    ctx->downcount -= 3;
    // 802CF02C: stb     r31, -25320(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25320);
        mem_write8(ctx, ea, (u8)ctx->gpr[31]);
    }

label_802CF030:
    ctx->pc = 0x802CF030u;
    // 802CF030: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802CF034:
    ctx->pc = 0x802CF034u;
    // 802CF034: bl      0x802C3110
    {
            ctx->lr = 0x802CF038u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CF038:
    ctx->pc = 0x802CF038u;
    ctx->downcount -= 7;
    // 802CF038: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CF03C:
    ctx->pc = 0x802CF03Cu;
    // 802CF03C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CF040:
    ctx->pc = 0x802CF040u;
    // 802CF040: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CF044:
    ctx->pc = 0x802CF044u;
    // 802CF044: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CF048:
    ctx->pc = 0x802CF048u;
    // 802CF048: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CF04C:
    ctx->pc = 0x802CF04Cu;
    // 802CF04C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF050:
    ctx->pc = 0x802CF050u;
    ctx->downcount -= 5;
    // 802CF050: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CF054:
    ctx->pc = 0x802CF054u;
    // 802CF054: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CF058:
    ctx->pc = 0x802CF058u;
    // 802CF058: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CF05C:
    ctx->pc = 0x802CF05Cu;
    // 802CF05C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF060:
    ctx->pc = 0x802CF060u;
    // 802CF060: bl      0x802C30E8
    {
            ctx->lr = 0x802CF064u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CF064:
    ctx->pc = 0x802CF064u;
    ctx->downcount -= 2;
    // 802CF064: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CF068:
    ctx->pc = 0x802CF068u;
    // 802CF068: b       0x802CF074
    {
            goto label_802CF074;
    }

label_802CF06C:
    ctx->downcount -= 2;
    // 802CF06C: addi    r3, r13, -25316
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-25316);

label_802CF070:
    // 802CF070: bl      0x802C85EC
    {
            ctx->lr = 0x802CF074u;
            ctx->pc = 0x802C85ECu;
            return;
    }

label_802CF074:
    ctx->pc = 0x802CF074u;
    ctx->downcount -= 3;
    // 802CF074: lbz     r0, -25320(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25320);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CF078:
    // 802CF078: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CF07C:
    // 802CF07C: bc    12, 2, 0x802CF06C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CF06Cu;
                return;
            }
            goto label_802CF06C;
        }
    }

label_802CF080:
    ctx->pc = 0x802CF080u;
    ctx->downcount -= 2;
    // 802CF080: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CF084:
    ctx->pc = 0x802CF084u;
    // 802CF084: bl      0x802C3110
    {
            ctx->lr = 0x802CF088u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CF088:
    ctx->pc = 0x802CF088u;
    ctx->downcount -= 6;
    // 802CF088: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CF08C:
    ctx->pc = 0x802CF08Cu;
    // 802CF08C: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CF090:
    ctx->pc = 0x802CF090u;
    // 802CF090: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_802CF094:
    ctx->pc = 0x802CF094u;
    // 802CF094: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CF098:
    ctx->pc = 0x802CF098u;
    // 802CF098: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF09C:
    ctx->pc = 0x802CF09Cu;
    ctx->downcount -= 5;
    // 802CF09C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CF0A0:
    ctx->pc = 0x802CF0A0u;
    // 802CF0A0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CF0A4:
    ctx->pc = 0x802CF0A4u;
    // 802CF0A4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CF0A8:
    ctx->pc = 0x802CF0A8u;
    // 802CF0A8: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF0AC:
    ctx->pc = 0x802CF0ACu;
    // 802CF0AC: bl      0x802C30E8
    {
            ctx->lr = 0x802CF0B0u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CF0B0:
    ctx->pc = 0x802CF0B0u;
    ctx->downcount -= 8;
    // 802CF0B0: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_802CF0B4:
    ctx->pc = 0x802CF0B4u;
    // 802CF0B4: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_802CF0B8:
    ctx->pc = 0x802CF0B8u;
    // 802CF0B8: lis     r4, 17664
    ctx->gpr[4] = ((u32)(s32)(17664) << 16);

label_802CF0BC:
    ctx->pc = 0x802CF0BCu;
    // 802CF0BC: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CF0C0:
    ctx->pc = 0x802CF0C0u;
    // 802CF0C0: addi    r0, r4, 2
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(2);

label_802CF0C4:
    ctx->pc = 0x802CF0C4u;
    // 802CF0C4: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CF0C8:
    ctx->pc = 0x802CF0C8u;
    // 802CF0C8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CF0CC:
    ctx->pc = 0x802CF0CCu;
    // 802CF0CC: bl      0x802CEA48
    {
            ctx->lr = 0x802CF0D0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CEA48u;
                return;
            }
            goto label_802CEA48;
    }

label_802CF0D0:
    ctx->pc = 0x802CF0D0u;
    ctx->downcount -= 4;
    // 802CF0D0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CF0D4:
    ctx->pc = 0x802CF0D4u;
    // 802CF0D4: stb     r0, -25320(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25320);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CF0D8:
    ctx->pc = 0x802CF0D8u;
    // 802CF0D8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CF0DC:
    ctx->pc = 0x802CF0DCu;
    // 802CF0DC: bl      0x802C3110
    {
            ctx->lr = 0x802CF0E0u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CF0E0:
    ctx->pc = 0x802CF0E0u;
    ctx->downcount -= 1;
    // 802CF0E0: bl      0x802C30E8
    {
            ctx->lr = 0x802CF0E4u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CF0E4:
    ctx->pc = 0x802CF0E4u;
    ctx->downcount -= 2;
    // 802CF0E4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CF0E8:
    ctx->pc = 0x802CF0E8u;
    // 802CF0E8: b       0x802CF0F4
    {
            goto label_802CF0F4;
    }

label_802CF0EC:
    ctx->downcount -= 2;
    // 802CF0EC: addi    r3, r13, -25316
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-25316);

label_802CF0F0:
    // 802CF0F0: bl      0x802C85EC
    {
            ctx->lr = 0x802CF0F4u;
            ctx->pc = 0x802C85ECu;
            return;
    }

label_802CF0F4:
    ctx->pc = 0x802CF0F4u;
    ctx->downcount -= 3;
    // 802CF0F4: lbz     r0, -25320(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25320);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802CF0F8:
    // 802CF0F8: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CF0FC:
    // 802CF0FC: bc    12, 2, 0x802CF0EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802CF0ECu;
                return;
            }
            goto label_802CF0EC;
        }
    }

label_802CF100:
    ctx->pc = 0x802CF100u;
    ctx->downcount -= 2;
    // 802CF100: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CF104:
    ctx->pc = 0x802CF104u;
    // 802CF104: bl      0x802C3110
    {
            ctx->lr = 0x802CF108u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CF108:
    ctx->pc = 0x802CF108u;
    ctx->downcount -= 6;
    // 802CF108: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CF10C:
    ctx->pc = 0x802CF10Cu;
    // 802CF10C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CF110:
    ctx->pc = 0x802CF110u;
    // 802CF110: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CF114:
    ctx->pc = 0x802CF114u;
    // 802CF114: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CF118:
    ctx->pc = 0x802CF118u;
    // 802CF118: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF11C:
    ctx->pc = 0x802CF11Cu;
    ctx->downcount -= 9;
    // 802CF11C: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_802CF120:
    ctx->pc = 0x802CF120u;
    // 802CF120: lwz     r4, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CF124:
    ctx->pc = 0x802CF124u;
    // 802CF124: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_802CF128:
    ctx->pc = 0x802CF128u;
    // 802CF128: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CF12C:
    ctx->pc = 0x802CF12Cu;
    // 802CF12C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CF130:
    ctx->pc = 0x802CF130u;
    // 802CF130: lwz     r3, 476(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(476);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CF134:
    ctx->pc = 0x802CF134u;
    // 802CF134: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802CF138:
    ctx->pc = 0x802CF138u;
    // 802CF138: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF13C:
    ctx->pc = 0x802CF13Cu;
    // 802CF13C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF140:
    ctx->pc = 0x802CF140u;
    ctx->downcount -= 9;
    // 802CF140: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_802CF144:
    ctx->pc = 0x802CF144u;
    // 802CF144: lwz     r3, -3368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-3368);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CF148:
    ctx->pc = 0x802CF148u;
    // 802CF148: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_802CF14C:
    ctx->pc = 0x802CF14Cu;
    // 802CF14C: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802CF150:
    ctx->pc = 0x802CF150u;
    // 802CF150: lis     r4, 25344
    ctx->gpr[4] = ((u32)(s32)(25344) << 16);

label_802CF154:
    ctx->pc = 0x802CF154u;
    // 802CF154: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802CF158:
    ctx->pc = 0x802CF158u;
    // 802CF158: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802CF15C:
    ctx->pc = 0x802CF15Cu;
    // 802CF15C: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF160:
    ctx->pc = 0x802CF160u;
    // 802CF160: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF164:
    ctx->pc = 0x802CF164u;
    ctx->downcount -= 5;
    // 802CF164: lwz     r5, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CF168:
    ctx->pc = 0x802CF168u;
    // 802CF168: rlwinm r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
    }

label_802CF16C:
    ctx->pc = 0x802CF16Cu;
    // 802CF16C: rlwimi r0, r3, 8, 0, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 8u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xFFFFFF00u) | (rot & 0xFFFFFF00u);
    }

label_802CF170:
    ctx->pc = 0x802CF170u;
    // 802CF170: sth     r0, 6(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF174:
    ctx->pc = 0x802CF174u;
    // 802CF174: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF178:
    ctx->pc = 0x802CF178u;
    ctx->downcount -= 5;
    // 802CF178: rlwinm r0, r3, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFBu;
    }

label_802CF17C:
    ctx->pc = 0x802CF17Cu;
    // 802CF17C: lwz     r3, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CF180:
    ctx->pc = 0x802CF180u;
    // 802CF180: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_802CF184:
    ctx->pc = 0x802CF184u;
    // 802CF184: sth     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF188:
    ctx->pc = 0x802CF188u;
    // 802CF188: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF18C:
    ctx->pc = 0x802CF18Cu;
    ctx->downcount -= 7;
    // 802CF18C: lwz     r4, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CF190:
    ctx->pc = 0x802CF190u;
    // 802CF190: rlwinm r0, r3, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 4u) & 0x00000FF0u;
    }

label_802CF194:
    ctx->pc = 0x802CF194u;
    // 802CF194: lhzu     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_802CF198:
    ctx->pc = 0x802CF198u;
    // 802CF198: rlwinm r3, r3, 0, 28, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFEFu;
    }

label_802CF19C:
    ctx->pc = 0x802CF19Cu;
    // 802CF19C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CF1A0:
    ctx->pc = 0x802CF1A0u;
    // 802CF1A0: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF1A4:
    ctx->pc = 0x802CF1A4u;
    // 802CF1A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF1A8:
    ctx->pc = 0x802CF1A8u;
    ctx->downcount -= 6;
    // 802CF1A8: lwz     r7, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802CF1AC:
    ctx->pc = 0x802CF1ACu;
    // 802CF1AC: cmpwi   r3, 1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CF1B0:
    ctx->pc = 0x802CF1B0u;
    // 802CF1B0: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_802CF1B4:
    ctx->pc = 0x802CF1B4u;
    // 802CF1B4: addi    r10, r7, 2
    ctx->gpr[10] = ctx->gpr[7] + (u32)(s32)(2);

label_802CF1B8:
    ctx->pc = 0x802CF1B8u;
    // 802CF1B8: lhz     r7, 2(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(2);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_802CF1BC:
    ctx->pc = 0x802CF1BCu;
    // 802CF1BC: bc    12, 2, 0x802CF1CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CF1CC;
        }
    }

label_802CF1C0:
    ctx->pc = 0x802CF1C0u;
    ctx->downcount -= 2;
    // 802CF1C0: cmpwi   r3, 3
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CF1C4:
    ctx->pc = 0x802CF1C4u;
    // 802CF1C4: bc    12, 2, 0x802CF1CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CF1CC;
        }
    }

label_802CF1C8:
    ctx->pc = 0x802CF1C8u;
    ctx->downcount -= 1;
    // 802CF1C8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_802CF1CC:
    ctx->pc = 0x802CF1CCu;
    ctx->downcount -= 25;
    // 802CF1CC: rlwinm r8, r7, 0, 0, 30
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFFFEu;
    }

label_802CF1D0:
    ctx->pc = 0x802CF1D0u;
    // 802CF1D0: subfic  r0, r3, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[3]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802CF1D4:
    ctx->pc = 0x802CF1D4u;
    // 802CF1D4: cntlzw r7, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[7] = n;
    }

label_802CF1D8:
    ctx->pc = 0x802CF1D8u;
    // 802CF1D8: subfic  r0, r3, 2
    {
        u64 res = (u64)(u32)(s32)(2) + (u64)(~ctx->gpr[3]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802CF1DC:
    ctx->pc = 0x802CF1DCu;
    // 802CF1DC: or   r8, r8, r9
    {
        ctx->gpr[8] = ctx->gpr[8] | ctx->gpr[9];
    }

label_802CF1E0:
    ctx->pc = 0x802CF1E0u;
    // 802CF1E0: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802CF1E4:
    ctx->pc = 0x802CF1E4u;
    // 802CF1E4: rlwinm r8, r8, 0, 21, 19
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0xFFFFF7FFu;
    }

label_802CF1E8:
    ctx->pc = 0x802CF1E8u;
    // 802CF1E8: rlwinm r3, r7, 6, 0, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[7], 6u) & 0xFFFFF800u;
    }

label_802CF1EC:
    ctx->pc = 0x802CF1ECu;
    // 802CF1EC: or   r3, r8, r3
    {
        ctx->gpr[3] = ctx->gpr[8] | ctx->gpr[3];
    }

label_802CF1F0:
    ctx->pc = 0x802CF1F0u;
    // 802CF1F0: rlwinm r3, r3, 0, 31, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFDu;
    }

label_802CF1F4:
    ctx->pc = 0x802CF1F4u;
    // 802CF1F4: rlwinm r0, r0, 28, 4, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x0FFFFFFEu;
    }

label_802CF1F8:
    ctx->pc = 0x802CF1F8u;
    // 802CF1F8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CF1FC:
    ctx->pc = 0x802CF1FCu;
    // 802CF1FC: rlwinm r3, r0, 0, 20, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF0FFFu;
    }

label_802CF200:
    ctx->pc = 0x802CF200u;
    // 802CF200: rlwinm r0, r6, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 12u) & 0xFFFFF000u;
    }

label_802CF204:
    ctx->pc = 0x802CF204u;
    // 802CF204: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CF208:
    ctx->pc = 0x802CF208u;
    // 802CF208: rlwinm r3, r0, 0, 24, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF8FFu;
    }

label_802CF20C:
    ctx->pc = 0x802CF20Cu;
    // 802CF20C: rlwinm r0, r4, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_802CF210:
    ctx->pc = 0x802CF210u;
    // 802CF210: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CF214:
    ctx->pc = 0x802CF214u;
    // 802CF214: rlwinm r3, r0, 0, 27, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF1Fu;
    }

label_802CF218:
    ctx->pc = 0x802CF218u;
    // 802CF218: rlwinm r0, r5, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 5u) & 0xFFFFFFE0u;
    }

label_802CF21C:
    ctx->pc = 0x802CF21Cu;
    // 802CF21C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CF220:
    ctx->pc = 0x802CF220u;
    // 802CF220: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_802CF224:
    ctx->pc = 0x802CF224u;
    // 802CF224: oris    r0, r0, 0x4100
    ctx->gpr[0] = ctx->gpr[0] | (0x4100u << 16);

label_802CF228:
    ctx->pc = 0x802CF228u;
    // 802CF228: sth     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF22C:
    ctx->pc = 0x802CF22Cu;
    // 802CF22C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF230:
    ctx->pc = 0x802CF230u;
    ctx->downcount -= 7;
    // 802CF230: lwz     r4, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CF234:
    ctx->pc = 0x802CF234u;
    // 802CF234: rlwinm r0, r3, 3, 21, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 3u) & 0x000007F8u;
    }

label_802CF238:
    ctx->pc = 0x802CF238u;
    // 802CF238: lhzu     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_802CF23C:
    ctx->pc = 0x802CF23Cu;
    // 802CF23C: rlwinm r3, r3, 0, 29, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF7u;
    }

label_802CF240:
    ctx->pc = 0x802CF240u;
    // 802CF240: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CF244:
    ctx->pc = 0x802CF244u;
    // 802CF244: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF248:
    ctx->pc = 0x802CF248u;
    // 802CF248: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF24C:
    ctx->pc = 0x802CF24Cu;
    ctx->downcount -= 5;
    // 802CF24C: lwz     r5, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CF250:
    ctx->pc = 0x802CF250u;
    // 802CF250: rlwinm r0, r3, 8, 16, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0x0000FF00u;
    }

label_802CF254:
    ctx->pc = 0x802CF254u;
    // 802CF254: rlwimi r0, r4, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_802CF258:
    ctx->pc = 0x802CF258u;
    // 802CF258: sth     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF25C:
    ctx->pc = 0x802CF25Cu;
    // 802CF25C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF260:
    ctx->pc = 0x802CF260u;
    ctx->downcount -= 7;
    // 802CF260: lwz     r4, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802CF264:
    ctx->pc = 0x802CF264u;
    // 802CF264: rlwinm r0, r3, 2, 22, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x000003FCu;
    }

label_802CF268:
    ctx->pc = 0x802CF268u;
    // 802CF268: lhzu     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_802CF26C:
    ctx->pc = 0x802CF26Cu;
    // 802CF26C: rlwinm r3, r3, 0, 30, 28
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFBu;
    }

label_802CF270:
    ctx->pc = 0x802CF270u;
    // 802CF270: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CF274:
    ctx->pc = 0x802CF274u;
    // 802CF274: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF278:
    ctx->pc = 0x802CF278u;
    // 802CF278: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF27C:
    ctx->pc = 0x802CF27Cu;
    ctx->downcount -= 10;
    // 802CF27C: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_802CF280:
    ctx->pc = 0x802CF280u;
    // 802CF280: lwz     r3, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CF284:
    ctx->pc = 0x802CF284u;
    // 802CF284: rlwinm r6, r0, 0, 31, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF1u;
    }

label_802CF288:
    ctx->pc = 0x802CF288u;
    // 802CF288: rlwinm r0, r4, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0xFFFFFFFEu;
    }

label_802CF28C:
    ctx->pc = 0x802CF28Cu;
    // 802CF28C: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802CF290:
    ctx->pc = 0x802CF290u;
    // 802CF290: rlwinm r4, r0, 0, 28, 26
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFEFu;
    }

label_802CF294:
    ctx->pc = 0x802CF294u;
    // 802CF294: rlwinm r0, r5, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 4u) & 0x00000FF0u;
    }

label_802CF298:
    ctx->pc = 0x802CF298u;
    // 802CF298: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802CF29C:
    ctx->pc = 0x802CF29Cu;
    // 802CF29C: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF2A0:
    ctx->pc = 0x802CF2A0u;
    // 802CF2A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF2A4:
    ctx->pc = 0x802CF2A4u;
    ctx->downcount -= 9;
    // 802CF2A4: rlwinm r0, r3, 2, 14, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x0003FFFCu;
    }

label_802CF2A8:
    ctx->pc = 0x802CF2A8u;
    // 802CF2A8: oris    r0, r0, 0xC800
    ctx->gpr[0] = ctx->gpr[0] | (0xC800u << 16);

label_802CF2AC:
    ctx->pc = 0x802CF2ACu;
    // 802CF2AC: rlwinm r3, r0, 0, 20, 9
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFC00FFFu;
    }

label_802CF2B0:
    ctx->pc = 0x802CF2B0u;
    // 802CF2B0: rlwinm r0, r4, 12, 4, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0x0FFFF000u;
    }

label_802CF2B4:
    ctx->pc = 0x802CF2B4u;
    // 802CF2B4: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CF2B8:
    ctx->pc = 0x802CF2B8u;
    // 802CF2B8: rlwinm r3, r0, 0, 10, 7
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFF3FFFFFu;
    }

label_802CF2BC:
    ctx->pc = 0x802CF2BCu;
    // 802CF2BC: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CF2C0:
    ctx->pc = 0x802CF2C0u;
    // 802CF2C0: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CF2C4:
    ctx->pc = 0x802CF2C4u;
    // 802CF2C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF2C8:
    ctx->pc = 0x802CF2C8u;
    ctx->downcount -= 8;
    // 802CF2C8: rlwinm r0, r3, 2, 14, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x0003FFFCu;
    }

label_802CF2CC:
    ctx->pc = 0x802CF2CCu;
    // 802CF2CC: oris    r0, r0, 0xC800
    ctx->gpr[0] = ctx->gpr[0] | (0xC800u << 16);

label_802CF2D0:
    ctx->pc = 0x802CF2D0u;
    // 802CF2D0: rlwinm r3, r0, 0, 20, 9
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFC00FFFu;
    }

label_802CF2D4:
    ctx->pc = 0x802CF2D4u;
    // 802CF2D4: rlwinm r0, r4, 12, 4, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0x0FFFF000u;
    }

label_802CF2D8:
    ctx->pc = 0x802CF2D8u;
    // 802CF2D8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CF2DC:
    ctx->pc = 0x802CF2DCu;
    // 802CF2DC: rlwinm r3, r0, 0, 10, 7
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFF3FFFFFu;
    }

label_802CF2E0:
    ctx->pc = 0x802CF2E0u;
    // 802CF2E0: stw     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CF2E4:
    ctx->pc = 0x802CF2E4u;
    // 802CF2E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF2E8:
    ctx->pc = 0x802CF2E8u;
    ctx->downcount -= 10;
    // 802CF2E8: rlwinm r0, r3, 2, 14, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x0003FFFCu;
    }

label_802CF2EC:
    ctx->pc = 0x802CF2ECu;
    // 802CF2EC: oris    r0, r0, 0xC800
    ctx->gpr[0] = ctx->gpr[0] | (0xC800u << 16);

label_802CF2F0:
    ctx->pc = 0x802CF2F0u;
    // 802CF2F0: rlwinm r3, r0, 0, 20, 9
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFC00FFFu;
    }

label_802CF2F4:
    ctx->pc = 0x802CF2F4u;
    // 802CF2F4: rlwinm r0, r4, 12, 4, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0x0FFFF000u;
    }

label_802CF2F8:
    ctx->pc = 0x802CF2F8u;
    // 802CF2F8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CF2FC:
    ctx->pc = 0x802CF2FCu;
    // 802CF2FC: rlwinm r0, r0, 0, 10, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFF3FFFFFu;
    }

label_802CF300:
    ctx->pc = 0x802CF300u;
    // 802CF300: oris    r3, r0, 0x0040
    ctx->gpr[3] = ctx->gpr[0] | (0x0040u << 16);

label_802CF304:
    ctx->pc = 0x802CF304u;
    // 802CF304: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CF308:
    ctx->pc = 0x802CF308u;
    // 802CF308: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CF30C:
    ctx->pc = 0x802CF30Cu;
    // 802CF30C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF310:
    ctx->pc = 0x802CF310u;
    ctx->downcount -= 9;
    // 802CF310: rlwinm r0, r3, 2, 14, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x0003FFFCu;
    }

label_802CF314:
    ctx->pc = 0x802CF314u;
    // 802CF314: oris    r0, r0, 0xC800
    ctx->gpr[0] = ctx->gpr[0] | (0xC800u << 16);

label_802CF318:
    ctx->pc = 0x802CF318u;
    // 802CF318: rlwinm r3, r0, 0, 20, 9
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFC00FFFu;
    }

label_802CF31C:
    ctx->pc = 0x802CF31Cu;
    // 802CF31C: rlwinm r0, r4, 12, 4, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0x0FFFF000u;
    }

label_802CF320:
    ctx->pc = 0x802CF320u;
    // 802CF320: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802CF324:
    ctx->pc = 0x802CF324u;
    // 802CF324: rlwinm r0, r0, 0, 10, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFF3FFFFFu;
    }

label_802CF328:
    ctx->pc = 0x802CF328u;
    // 802CF328: oris    r3, r0, 0x0040
    ctx->gpr[3] = ctx->gpr[0] | (0x0040u << 16);

label_802CF32C:
    ctx->pc = 0x802CF32Cu;
    // 802CF32C: stw     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802CF330:
    ctx->pc = 0x802CF330u;
    // 802CF330: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF334:
    ctx->pc = 0x802CF334u;
    ctx->downcount -= 8;
    // 802CF334: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CF338:
    ctx->pc = 0x802CF338u;
    // 802CF338: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CF33C:
    ctx->pc = 0x802CF33Cu;
    // 802CF33C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CF340:
    ctx->pc = 0x802CF340u;
    // 802CF340: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF344:
    ctx->pc = 0x802CF344u;
    // 802CF344: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CF348:
    ctx->pc = 0x802CF348u;
    // 802CF348: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CF34C:
    ctx->pc = 0x802CF34Cu;
    // 802CF34C: lwz     r31, -25328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25328);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CF350:
    ctx->pc = 0x802CF350u;
    // 802CF350: bl      0x802C30E8
    {
            ctx->lr = 0x802CF354u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CF354:
    ctx->pc = 0x802CF354u;
    ctx->downcount -= 2;
    // 802CF354: stw     r30, -25328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25328);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CF358:
    ctx->pc = 0x802CF358u;
    // 802CF358: bl      0x802C3110
    {
            ctx->lr = 0x802CF35Cu;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CF35C:
    ctx->pc = 0x802CF35Cu;
    ctx->downcount -= 8;
    // 802CF35C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CF360:
    ctx->pc = 0x802CF360u;
    // 802CF360: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CF364:
    ctx->pc = 0x802CF364u;
    // 802CF364: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CF368:
    ctx->pc = 0x802CF368u;
    // 802CF368: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CF36C:
    ctx->pc = 0x802CF36Cu;
    // 802CF36C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CF370:
    ctx->pc = 0x802CF370u;
    // 802CF370: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CF374:
    ctx->pc = 0x802CF374u;
    // 802CF374: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF378:
    ctx->pc = 0x802CF378u;
    ctx->downcount -= 11;
    // 802CF378: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CF37C:
    ctx->pc = 0x802CF37Cu;
    // 802CF37C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CF380:
    ctx->pc = 0x802CF380u;
    // 802CF380: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CF384:
    ctx->pc = 0x802CF384u;
    // 802CF384: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF388:
    ctx->pc = 0x802CF388u;
    // 802CF388: stw     r30, 728(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(728);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CF38C:
    ctx->pc = 0x802CF38Cu;
    // 802CF38C: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_802CF390:
    ctx->pc = 0x802CF390u;
    // 802CF390: lwz     r0, -25328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25328);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CF394:
    ctx->pc = 0x802CF394u;
    // 802CF394: lwz     r3, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CF398:
    ctx->pc = 0x802CF398u;
    // 802CF398: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CF39C:
    ctx->pc = 0x802CF39Cu;
    // 802CF39C: lhz     r31, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[31] = mem_read16(ctx, ea);
    }

label_802CF3A0:
    ctx->pc = 0x802CF3A0u;
    // 802CF3A0: bc    12, 2, 0x802CF3D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CF3D4;
        }
    }

label_802CF3A4:
    ctx->pc = 0x802CF3A4u;
    ctx->downcount -= 2;
    // 802CF3A4: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CF3A8:
    ctx->pc = 0x802CF3A8u;
    // 802CF3A8: bl      0x802C013C
    {
            ctx->lr = 0x802CF3ACu;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802CF3AC:
    ctx->pc = 0x802CF3ACu;
    ctx->downcount -= 2;
    // 802CF3AC: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CF3B0:
    ctx->pc = 0x802CF3B0u;
    // 802CF3B0: bl      0x802BFF34
    {
            ctx->lr = 0x802CF3B4u;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802CF3B4:
    ctx->pc = 0x802CF3B4u;
    ctx->downcount -= 5;
    // 802CF3B4: lwz     r12, -25328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25328);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802CF3B8:
    ctx->pc = 0x802CF3B8u;
    // 802CF3B8: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_802CF3BC:
    ctx->pc = 0x802CF3BCu;
    // 802CF3BC: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_802CF3C0:
    ctx->pc = 0x802CF3C0u;
    // 802CF3C0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x802CF3C4u;
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF3C4:
    ctx->pc = 0x802CF3C4u;
    ctx->downcount -= 2;
    // 802CF3C4: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CF3C8:
    ctx->pc = 0x802CF3C8u;
    // 802CF3C8: bl      0x802C013C
    {
            ctx->lr = 0x802CF3CCu;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802CF3CC:
    ctx->pc = 0x802CF3CCu;
    ctx->downcount -= 2;
    // 802CF3CC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802CF3D0:
    ctx->pc = 0x802CF3D0u;
    // 802CF3D0: bl      0x802BFF34
    {
            ctx->lr = 0x802CF3D4u;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802CF3D4:
    ctx->pc = 0x802CF3D4u;
    ctx->downcount -= 12;
    // 802CF3D4: lwz     r3, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802CF3D8:
    ctx->pc = 0x802CF3D8u;
    // 802CF3D8: lhzu     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_802CF3DC:
    ctx->pc = 0x802CF3DCu;
    // 802CF3DC: rlwinm r0, r0, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFBu;
    }

label_802CF3E0:
    ctx->pc = 0x802CF3E0u;
    // 802CF3E0: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_802CF3E4:
    ctx->pc = 0x802CF3E4u;
    // 802CF3E4: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF3E8:
    ctx->pc = 0x802CF3E8u;
    // 802CF3E8: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CF3EC:
    ctx->pc = 0x802CF3ECu;
    // 802CF3EC: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CF3F0:
    ctx->pc = 0x802CF3F0u;
    // 802CF3F0: lwz     r30, 728(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(728);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CF3F4:
    ctx->pc = 0x802CF3F4u;
    // 802CF3F4: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_802CF3F8:
    ctx->pc = 0x802CF3F8u;
    // 802CF3F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CF3FC:
    ctx->pc = 0x802CF3FCu;
    // 802CF3FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF400:
    ctx->pc = 0x802CF400u;
    ctx->downcount -= 8;
    // 802CF400: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CF404:
    ctx->pc = 0x802CF404u;
    // 802CF404: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CF408:
    ctx->pc = 0x802CF408u;
    // 802CF408: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CF40C:
    ctx->pc = 0x802CF40Cu;
    // 802CF40C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF410:
    ctx->pc = 0x802CF410u;
    // 802CF410: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CF414:
    ctx->pc = 0x802CF414u;
    // 802CF414: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802CF418:
    ctx->pc = 0x802CF418u;
    // 802CF418: lwz     r31, -25324(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25324);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CF41C:
    ctx->pc = 0x802CF41Cu;
    // 802CF41C: bl      0x802C30E8
    {
            ctx->lr = 0x802CF420u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802CF420:
    ctx->pc = 0x802CF420u;
    ctx->downcount -= 2;
    // 802CF420: stw     r30, -25324(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25324);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802CF424:
    ctx->pc = 0x802CF424u;
    // 802CF424: bl      0x802C3110
    {
            ctx->lr = 0x802CF428u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802CF428:
    ctx->pc = 0x802CF428u;
    ctx->downcount -= 8;
    // 802CF428: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CF42C:
    ctx->pc = 0x802CF42Cu;
    // 802CF42C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CF430:
    ctx->pc = 0x802CF430u;
    // 802CF430: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CF434:
    ctx->pc = 0x802CF434u;
    // 802CF434: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802CF438:
    ctx->pc = 0x802CF438u;
    // 802CF438: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802CF43C:
    ctx->pc = 0x802CF43Cu;
    // 802CF43C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802CF440:
    ctx->pc = 0x802CF440u;
    // 802CF440: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF444:
    ctx->pc = 0x802CF444u;
    ctx->downcount -= 15;
    // 802CF444: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802CF448:
    ctx->pc = 0x802CF448u;
    // 802CF448: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802CF44C:
    ctx->pc = 0x802CF44Cu;
    // 802CF44C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802CF450:
    ctx->pc = 0x802CF450u;
    // 802CF450: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802CF454:
    ctx->pc = 0x802CF454u;
    // 802CF454: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802CF458:
    ctx->pc = 0x802CF458u;
    // 802CF458: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_802CF45C:
    ctx->pc = 0x802CF45Cu;
    // 802CF45C: lwz     r5, -25392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25392);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802CF460:
    ctx->pc = 0x802CF460u;
    // 802CF460: lhz     r0, 10(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802CF464:
    ctx->pc = 0x802CF464u;
    // 802CF464: rlwinm r0, r0, 0, 29, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF7u;
    }

label_802CF468:
    ctx->pc = 0x802CF468u;
    // 802CF468: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_802CF46C:
    ctx->pc = 0x802CF46Cu;
    // 802CF46C: sth     r0, 10(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802CF470:
    ctx->pc = 0x802CF470u;
    // 802CF470: lwz     r0, -25324(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25324);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CF474:
    ctx->pc = 0x802CF474u;
    // 802CF474: stb     r3, -25320(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25320);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_802CF478:
    ctx->pc = 0x802CF478u;
    // 802CF478: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802CF47C:
    ctx->pc = 0x802CF47Cu;
    // 802CF47C: bc    12, 2, 0x802CF4AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802CF4AC;
        }
    }

label_802CF480:
    ctx->pc = 0x802CF480u;
    ctx->downcount -= 2;
    // 802CF480: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CF484:
    ctx->pc = 0x802CF484u;
    // 802CF484: bl      0x802C013C
    {
            ctx->lr = 0x802CF488u;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802CF488:
    ctx->pc = 0x802CF488u;
    ctx->downcount -= 2;
    // 802CF488: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CF48C:
    ctx->pc = 0x802CF48Cu;
    // 802CF48C: bl      0x802BFF34
    {
            ctx->lr = 0x802CF490u;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802CF490:
    ctx->pc = 0x802CF490u;
    ctx->downcount -= 4;
    // 802CF490: lwz     r12, -25324(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25324);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802CF494:
    ctx->pc = 0x802CF494u;
    // 802CF494: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_802CF498:
    ctx->pc = 0x802CF498u;
    // 802CF498: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x802CF49Cu;
            ctx->pc = target;
            goto return_dispatch_802CB4C0;
        }
    }

label_802CF49C:
    ctx->pc = 0x802CF49Cu;
    ctx->downcount -= 2;
    // 802CF49C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802CF4A0:
    ctx->pc = 0x802CF4A0u;
    // 802CF4A0: bl      0x802C013C
    {
            ctx->lr = 0x802CF4A4u;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802CF4A4:
    ctx->pc = 0x802CF4A4u;
    ctx->downcount -= 2;
    // 802CF4A4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802CF4A8:
    ctx->pc = 0x802CF4A8u;
    // 802CF4A8: bl      0x802BFF34
    {
            ctx->lr = 0x802CF4ACu;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802CF4AC:
    ctx->pc = 0x802CF4ACu;
    ctx->downcount -= 2;
    // 802CF4AC: addi    r3, r13, -25316
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-25316);

label_802CF4B0:
    ctx->pc = 0x802CF4B0u;
    // 802CF4B0: bl      0x802C86D8
    {
            ctx->lr = 0x802CF4B4u;
            ctx->pc = 0x802C86D8u;
            return;
    }

label_802CF4B4:
    ctx->pc = 0x802CF4B4u;
    ctx->downcount -= 3;
    // 802CF4B4: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802CF4B8:
    ctx->pc = 0x802CF4B8u;
    // 802CF4B8: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802CF4BC:
    ctx->pc = 0x802CF4BCu;
    // 802CF4BC: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

    ctx->pc = 0x802CF4C0u;
    return;
return_dispatch_802CB4C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x802CB588u: goto label_802CB588;
    case 0x802CB5ECu: goto label_802CB5EC;
    case 0x802CB638u: goto label_802CB638;
    case 0x802CB684u: goto label_802CB684;
    case 0x802CB718u: goto label_802CB718;
    case 0x802CB71Cu: goto label_802CB71C;
    case 0x802CB768u: goto label_802CB768;
    case 0x802CB7F4u: goto label_802CB7F4;
    case 0x802CB810u: goto label_802CB810;
    case 0x802CB82Cu: goto label_802CB82C;
    case 0x802CB848u: goto label_802CB848;
    case 0x802CB864u: goto label_802CB864;
    case 0x802CB880u: goto label_802CB880;
    case 0x802CB89Cu: goto label_802CB89C;
    case 0x802CB8B8u: goto label_802CB8B8;
    case 0x802CB8D4u: goto label_802CB8D4;
    case 0x802CB8DCu: goto label_802CB8DC;
    case 0x802CB8E0u: goto label_802CB8E0;
    case 0x802CB8E4u: goto label_802CB8E4;
    case 0x802CB904u: goto label_802CB904;
    case 0x802CB934u: goto label_802CB934;
    case 0x802CB94Cu: goto label_802CB94C;
    case 0x802CB958u: goto label_802CB958;
    case 0x802CB968u: goto label_802CB968;
    case 0x802CB978u: goto label_802CB978;
    case 0x802CB988u: goto label_802CB988;
    case 0x802CB998u: goto label_802CB998;
    case 0x802CB9A8u: goto label_802CB9A8;
    case 0x802CB9B8u: goto label_802CB9B8;
    case 0x802CB9C8u: goto label_802CB9C8;
    case 0x802CB9D8u: goto label_802CB9D8;
    case 0x802CBA1Cu: goto label_802CBA1C;
    case 0x802CBA28u: goto label_802CBA28;
    case 0x802CBA30u: goto label_802CBA30;
    case 0x802CBA40u: goto label_802CBA40;
    case 0x802CBA50u: goto label_802CBA50;
    case 0x802CBA94u: goto label_802CBA94;
    case 0x802CBAA0u: goto label_802CBAA0;
    case 0x802CBAA8u: goto label_802CBAA8;
    case 0x802CBAB0u: goto label_802CBAB0;
    case 0x802CBAB8u: goto label_802CBAB8;
    case 0x802CBACCu: goto label_802CBACC;
    case 0x802CBAD8u: goto label_802CBAD8;
    case 0x802CBAE0u: goto label_802CBAE0;
    case 0x802CBB00u: goto label_802CBB00;
    case 0x802CBB14u: goto label_802CBB14;
    case 0x802CBB28u: goto label_802CBB28;
    case 0x802CBB48u: goto label_802CBB48;
    case 0x802CBB5Cu: goto label_802CBB5C;
    case 0x802CBB70u: goto label_802CBB70;
    case 0x802CBB74u: goto label_802CBB74;
    case 0x802CBB90u: goto label_802CBB90;
    case 0x802CBB9Cu: goto label_802CBB9C;
    case 0x802CBBB0u: goto label_802CBBB0;
    case 0x802CBBC4u: goto label_802CBBC4;
    case 0x802CBBD8u: goto label_802CBBD8;
    case 0x802CBBECu: goto label_802CBBEC;
    case 0x802CBC00u: goto label_802CBC00;
    case 0x802CBC14u: goto label_802CBC14;
    case 0x802CBC28u: goto label_802CBC28;
    case 0x802CBC3Cu: goto label_802CBC3C;
    case 0x802CBC50u: goto label_802CBC50;
    case 0x802CBC64u: goto label_802CBC64;
    case 0x802CBC78u: goto label_802CBC78;
    case 0x802CBC8Cu: goto label_802CBC8C;
    case 0x802CBCA0u: goto label_802CBCA0;
    case 0x802CBCB4u: goto label_802CBCB4;
    case 0x802CBCC8u: goto label_802CBCC8;
    case 0x802CBCDCu: goto label_802CBCDC;
    case 0x802CBCE4u: goto label_802CBCE4;
    case 0x802CBCF0u: goto label_802CBCF0;
    case 0x802CBD08u: goto label_802CBD08;
    case 0x802CBD18u: goto label_802CBD18;
    case 0x802CBD30u: goto label_802CBD30;
    case 0x802CBD3Cu: goto label_802CBD3C;
    case 0x802CBD4Cu: goto label_802CBD4C;
    case 0x802CBD70u: goto label_802CBD70;
    case 0x802CBD88u: goto label_802CBD88;
    case 0x802CBDA0u: goto label_802CBDA0;
    case 0x802CBDB8u: goto label_802CBDB8;
    case 0x802CBDD0u: goto label_802CBDD0;
    case 0x802CBDE4u: goto label_802CBDE4;
    case 0x802CBDF4u: goto label_802CBDF4;
    case 0x802CBE04u: goto label_802CBE04;
    case 0x802CBE14u: goto label_802CBE14;
    case 0x802CBE24u: goto label_802CBE24;
    case 0x802CBE48u: goto label_802CBE48;
    case 0x802CBE58u: goto label_802CBE58;
    case 0x802CBE6Cu: goto label_802CBE6C;
    case 0x802CBE74u: goto label_802CBE74;
    case 0x802CBE7Cu: goto label_802CBE7C;
    case 0x802CBE8Cu: goto label_802CBE8C;
    case 0x802CBE94u: goto label_802CBE94;
    case 0x802CBE9Cu: goto label_802CBE9C;
    case 0x802CBEA8u: goto label_802CBEA8;
    case 0x802CBEB4u: goto label_802CBEB4;
    case 0x802CBEC0u: goto label_802CBEC0;
    case 0x802CBEE8u: goto label_802CBEE8;
    case 0x802CBEFCu: goto label_802CBEFC;
    case 0x802CBF08u: goto label_802CBF08;
    case 0x802CBF40u: goto label_802CBF40;
    case 0x802CBF48u: goto label_802CBF48;
    case 0x802CBF5Cu: goto label_802CBF5C;
    case 0x802CBF64u: goto label_802CBF64;
    case 0x802CBF6Cu: goto label_802CBF6C;
    case 0x802CBF70u: goto label_802CBF70;
    case 0x802CBF78u: goto label_802CBF78;
    case 0x802CBF80u: goto label_802CBF80;
    case 0x802CBF88u: goto label_802CBF88;
    case 0x802CBF9Cu: goto label_802CBF9C;
    case 0x802CBFA8u: goto label_802CBFA8;
    case 0x802CBFB0u: goto label_802CBFB0;
    case 0x802CBFBCu: goto label_802CBFBC;
    case 0x802CBFCCu: goto label_802CBFCC;
    case 0x802CBFD8u: goto label_802CBFD8;
    case 0x802CBFDCu: goto label_802CBFDC;
    case 0x802CC01Cu: goto label_802CC01C;
    case 0x802CC028u: goto label_802CC028;
    case 0x802CC038u: goto label_802CC038;
    case 0x802CC05Cu: goto label_802CC05C;
    case 0x802CC070u: goto label_802CC070;
    case 0x802CC07Cu: goto label_802CC07C;
    case 0x802CC0D0u: goto label_802CC0D0;
    case 0x802CC0D8u: goto label_802CC0D8;
    case 0x802CC0E4u: goto label_802CC0E4;
    case 0x802CC0ECu: goto label_802CC0EC;
    case 0x802CC0F4u: goto label_802CC0F4;
    case 0x802CC14Cu: goto label_802CC14C;
    case 0x802CC160u: goto label_802CC160;
    case 0x802CC16Cu: goto label_802CC16C;
    case 0x802CC1A0u: goto label_802CC1A0;
    case 0x802CC1ACu: goto label_802CC1AC;
    case 0x802CC1BCu: goto label_802CC1BC;
    case 0x802CC204u: goto label_802CC204;
    case 0x802CC20Cu: goto label_802CC20C;
    case 0x802CC218u: goto label_802CC218;
    case 0x802CC220u: goto label_802CC220;
    case 0x802CC228u: goto label_802CC228;
    case 0x802CC280u: goto label_802CC280;
    case 0x802CC290u: goto label_802CC290;
    case 0x802CC2D0u: goto label_802CC2D0;
    case 0x802CC2FCu: goto label_802CC2FC;
    case 0x802CC340u: goto label_802CC340;
    case 0x802CC39Cu: goto label_802CC39C;
    case 0x802CC3A8u: goto label_802CC3A8;
    case 0x802CC3B0u: goto label_802CC3B0;
    case 0x802CC3C8u: goto label_802CC3C8;
    case 0x802CC3DCu: goto label_802CC3DC;
    case 0x802CC414u: goto label_802CC414;
    case 0x802CC41Cu: goto label_802CC41C;
    case 0x802CC450u: goto label_802CC450;
    case 0x802CC458u: goto label_802CC458;
    case 0x802CC464u: goto label_802CC464;
    case 0x802CC530u: goto label_802CC530;
    case 0x802CC554u: goto label_802CC554;
    case 0x802CC55Cu: goto label_802CC55C;
    case 0x802CC574u: goto label_802CC574;
    case 0x802CC57Cu: goto label_802CC57C;
    case 0x802CC588u: goto label_802CC588;
    case 0x802CC58Cu: goto label_802CC58C;
    case 0x802CC594u: goto label_802CC594;
    case 0x802CC5BCu: goto label_802CC5BC;
    case 0x802CC5E8u: goto label_802CC5E8;
    case 0x802CC5F0u: goto label_802CC5F0;
    case 0x802CC690u: goto label_802CC690;
    case 0x802CC7B4u: goto label_802CC7B4;
    case 0x802CC914u: goto label_802CC914;
    case 0x802CC91Cu: goto label_802CC91C;
    case 0x802CC954u: goto label_802CC954;
    case 0x802CC95Cu: goto label_802CC95C;
    case 0x802CC9A8u: goto label_802CC9A8;
    case 0x802CC9B0u: goto label_802CC9B0;
    case 0x802CC9D8u: goto label_802CC9D8;
    case 0x802CCA0Cu: goto label_802CCA0C;
    case 0x802CCA38u: goto label_802CCA38;
    case 0x802CCA40u: goto label_802CCA40;
    case 0x802CCA44u: goto label_802CCA44;
    case 0x802CCBACu: goto label_802CCBAC;
    case 0x802CCBB8u: goto label_802CCBB8;
    case 0x802CCBE8u: goto label_802CCBE8;
    case 0x802CCC14u: goto label_802CCC14;
    case 0x802CCC1Cu: goto label_802CCC1C;
    case 0x802CCC2Cu: goto label_802CCC2C;
    case 0x802CCC30u: goto label_802CCC30;
    case 0x802CCC5Cu: goto label_802CCC5C;
    case 0x802CCC64u: goto label_802CCC64;
    case 0x802CCC74u: goto label_802CCC74;
    case 0x802CCCA8u: goto label_802CCCA8;
    case 0x802CCCB4u: goto label_802CCCB4;
    case 0x802CCCC0u: goto label_802CCCC0;
    case 0x802CCD28u: goto label_802CCD28;
    case 0x802CCD30u: goto label_802CCD30;
    case 0x802CCD34u: goto label_802CCD34;
    case 0x802CCD48u: goto label_802CCD48;
    case 0x802CCDD8u: goto label_802CCDD8;
    case 0x802CCDE0u: goto label_802CCDE0;
    case 0x802CCE14u: goto label_802CCE14;
    case 0x802CCEA0u: goto label_802CCEA0;
    case 0x802CCEA4u: goto label_802CCEA4;
    case 0x802CCEB8u: goto label_802CCEB8;
    case 0x802CCF7Cu: goto label_802CCF7C;
    case 0x802CCF84u: goto label_802CCF84;
    case 0x802CD7F8u: goto label_802CD7F8;
    case 0x802CDB18u: goto label_802CDB18;
    case 0x802CDB44u: goto label_802CDB44;
    case 0x802CE5D4u: goto label_802CE5D4;
    case 0x802CE964u: goto label_802CE964;
    case 0x802CEA68u: goto label_802CEA68;
    case 0x802CEA94u: goto label_802CEA94;
    case 0x802CEAB4u: goto label_802CEAB4;
    case 0x802CEAC8u: goto label_802CEAC8;
    case 0x802CEAFCu: goto label_802CEAFC;
    case 0x802CEB14u: goto label_802CEB14;
    case 0x802CEB98u: goto label_802CEB98;
    case 0x802CEBB0u: goto label_802CEBB0;
    case 0x802CEC3Cu: goto label_802CEC3C;
    case 0x802CEC74u: goto label_802CEC74;
    case 0x802CEC8Cu: goto label_802CEC8C;
    case 0x802CECF8u: goto label_802CECF8;
    case 0x802CED10u: goto label_802CED10;
    case 0x802CED3Cu: goto label_802CED3C;
    case 0x802CED50u: goto label_802CED50;
    case 0x802CEDA8u: goto label_802CEDA8;
    case 0x802CEDE0u: goto label_802CEDE0;
    case 0x802CEDF8u: goto label_802CEDF8;
    case 0x802CEE64u: goto label_802CEE64;
    case 0x802CEE7Cu: goto label_802CEE7C;
    case 0x802CEEA8u: goto label_802CEEA8;
    case 0x802CEEBCu: goto label_802CEEBC;
    case 0x802CEEE0u: goto label_802CEEE0;
    case 0x802CEF10u: goto label_802CEF10;
    case 0x802CEF58u: goto label_802CEF58;
    case 0x802CEF84u: goto label_802CEF84;
    case 0x802CEF8Cu: goto label_802CEF8C;
    case 0x802CEFD0u: goto label_802CEFD0;
    case 0x802CF000u: goto label_802CF000;
    case 0x802CF02Cu: goto label_802CF02C;
    case 0x802CF038u: goto label_802CF038;
    case 0x802CF064u: goto label_802CF064;
    case 0x802CF074u: goto label_802CF074;
    case 0x802CF088u: goto label_802CF088;
    case 0x802CF0B0u: goto label_802CF0B0;
    case 0x802CF0D0u: goto label_802CF0D0;
    case 0x802CF0E0u: goto label_802CF0E0;
    case 0x802CF0E4u: goto label_802CF0E4;
    case 0x802CF0F4u: goto label_802CF0F4;
    case 0x802CF108u: goto label_802CF108;
    case 0x802CF354u: goto label_802CF354;
    case 0x802CF35Cu: goto label_802CF35C;
    case 0x802CF3ACu: goto label_802CF3AC;
    case 0x802CF3B4u: goto label_802CF3B4;
    case 0x802CF3C4u: goto label_802CF3C4;
    case 0x802CF3CCu: goto label_802CF3CC;
    case 0x802CF3D4u: goto label_802CF3D4;
    case 0x802CF420u: goto label_802CF420;
    case 0x802CF428u: goto label_802CF428;
    case 0x802CF488u: goto label_802CF488;
    case 0x802CF490u: goto label_802CF490;
    case 0x802CF49Cu: goto label_802CF49C;
    case 0x802CF4A4u: goto label_802CF4A4;
    case 0x802CF4ACu: goto label_802CF4AC;
    case 0x802CF4B4u: goto label_802CF4B4;
    default: return;
    }
}

