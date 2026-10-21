// DolRecomp output
#include "../generated.h"

static void loop_800F5FB0(CPUState* ctx) {
label_800F5FB0:
    ctx->downcount -= 8;
    ctx->pc = 0x800F5FB0u;
    // 800F5FB0: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 800F5FB4: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 800F5FB8: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x800F5FBCu;
    // 800F5FBC: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 800F5FC0: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 800F5FC4: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 800F5FC8: cmpw    r9, r8
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

    // 800F5FCC: bc    4, 2, 0x800F5FB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F5FB0u;
                return;
            }
            goto label_800F5FB0;
        }
    }

    ctx->pc = 0x800F5FD0u;
}

static void loop_800F63B8(CPUState* ctx) {
label_800F63B8:
    ctx->downcount -= 8;
    ctx->pc = 0x800F63B8u;
    // 800F63B8: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 800F63BC: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 800F63C0: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x800F63C4u;
    // 800F63C4: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 800F63C8: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 800F63CC: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 800F63D0: cmpw    r9, r8
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

    // 800F63D4: bc    4, 2, 0x800F63B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F63B8u;
                return;
            }
            goto label_800F63B8;
        }
    }

    ctx->pc = 0x800F63D8u;
}

static void loop_800F6BC8(CPUState* ctx) {
label_800F6BC8:
    ctx->downcount -= 8;
    ctx->pc = 0x800F6BC8u;
    // 800F6BC8: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 800F6BCC: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 800F6BD0: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x800F6BD4u;
    // 800F6BD4: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 800F6BD8: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 800F6BDC: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 800F6BE0: cmpw    r9, r8
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

    // 800F6BE4: bc    4, 2, 0x800F6BC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F6BC8u;
                return;
            }
            goto label_800F6BC8;
        }
    }

    ctx->pc = 0x800F6BE8u;
}

void func_800F34C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x800F34C0u: goto label_800F34C0;
    case 0x800F34C4u: goto label_800F34C4;
    case 0x800F34C8u: goto label_800F34C8;
    case 0x800F34CCu: goto label_800F34CC;
    case 0x800F34D0u: goto label_800F34D0;
    case 0x800F34D4u: goto label_800F34D4;
    case 0x800F34D8u: goto label_800F34D8;
    case 0x800F34DCu: goto label_800F34DC;
    case 0x800F34E0u: goto label_800F34E0;
    case 0x800F34E4u: goto label_800F34E4;
    case 0x800F34E8u: goto label_800F34E8;
    case 0x800F34ECu: goto label_800F34EC;
    case 0x800F34F0u: goto label_800F34F0;
    case 0x800F34F4u: goto label_800F34F4;
    case 0x800F34F8u: goto label_800F34F8;
    case 0x800F34FCu: goto label_800F34FC;
    case 0x800F3500u: goto label_800F3500;
    case 0x800F3504u: goto label_800F3504;
    case 0x800F3508u: goto label_800F3508;
    case 0x800F350Cu: goto label_800F350C;
    case 0x800F3510u: goto label_800F3510;
    case 0x800F3514u: goto label_800F3514;
    case 0x800F3518u: goto label_800F3518;
    case 0x800F351Cu: goto label_800F351C;
    case 0x800F3520u: goto label_800F3520;
    case 0x800F3524u: goto label_800F3524;
    case 0x800F3528u: goto label_800F3528;
    case 0x800F352Cu: goto label_800F352C;
    case 0x800F3530u: goto label_800F3530;
    case 0x800F3534u: goto label_800F3534;
    case 0x800F3538u: goto label_800F3538;
    case 0x800F353Cu: goto label_800F353C;
    case 0x800F3540u: goto label_800F3540;
    case 0x800F3544u: goto label_800F3544;
    case 0x800F3548u: goto label_800F3548;
    case 0x800F354Cu: goto label_800F354C;
    case 0x800F3550u: goto label_800F3550;
    case 0x800F3554u: goto label_800F3554;
    case 0x800F3558u: goto label_800F3558;
    case 0x800F355Cu: goto label_800F355C;
    case 0x800F3560u: goto label_800F3560;
    case 0x800F3564u: goto label_800F3564;
    case 0x800F3568u: goto label_800F3568;
    case 0x800F356Cu: goto label_800F356C;
    case 0x800F3570u: goto label_800F3570;
    case 0x800F3574u: goto label_800F3574;
    case 0x800F3578u: goto label_800F3578;
    case 0x800F357Cu: goto label_800F357C;
    case 0x800F3580u: goto label_800F3580;
    case 0x800F3584u: goto label_800F3584;
    case 0x800F3588u: goto label_800F3588;
    case 0x800F358Cu: goto label_800F358C;
    case 0x800F3590u: goto label_800F3590;
    case 0x800F3594u: goto label_800F3594;
    case 0x800F3598u: goto label_800F3598;
    case 0x800F359Cu: goto label_800F359C;
    case 0x800F35A0u: goto label_800F35A0;
    case 0x800F35A4u: goto label_800F35A4;
    case 0x800F35A8u: goto label_800F35A8;
    case 0x800F35ACu: goto label_800F35AC;
    case 0x800F35B0u: goto label_800F35B0;
    case 0x800F35B4u: goto label_800F35B4;
    case 0x800F35B8u: goto label_800F35B8;
    case 0x800F35BCu: goto label_800F35BC;
    case 0x800F35C0u: goto label_800F35C0;
    case 0x800F35C4u: goto label_800F35C4;
    case 0x800F35C8u: goto label_800F35C8;
    case 0x800F35CCu: goto label_800F35CC;
    case 0x800F35D0u: goto label_800F35D0;
    case 0x800F35D4u: goto label_800F35D4;
    case 0x800F35D8u: goto label_800F35D8;
    case 0x800F35DCu: goto label_800F35DC;
    case 0x800F35E0u: goto label_800F35E0;
    case 0x800F35E4u: goto label_800F35E4;
    case 0x800F35E8u: goto label_800F35E8;
    case 0x800F35ECu: goto label_800F35EC;
    case 0x800F35F0u: goto label_800F35F0;
    case 0x800F35F4u: goto label_800F35F4;
    case 0x800F35F8u: goto label_800F35F8;
    case 0x800F35FCu: goto label_800F35FC;
    case 0x800F3600u: goto label_800F3600;
    case 0x800F3604u: goto label_800F3604;
    case 0x800F3608u: goto label_800F3608;
    case 0x800F360Cu: goto label_800F360C;
    case 0x800F3610u: goto label_800F3610;
    case 0x800F3614u: goto label_800F3614;
    case 0x800F3618u: goto label_800F3618;
    case 0x800F361Cu: goto label_800F361C;
    case 0x800F3620u: goto label_800F3620;
    case 0x800F3624u: goto label_800F3624;
    case 0x800F3628u: goto label_800F3628;
    case 0x800F362Cu: goto label_800F362C;
    case 0x800F3630u: goto label_800F3630;
    case 0x800F3634u: goto label_800F3634;
    case 0x800F3638u: goto label_800F3638;
    case 0x800F363Cu: goto label_800F363C;
    case 0x800F3640u: goto label_800F3640;
    case 0x800F3644u: goto label_800F3644;
    case 0x800F3648u: goto label_800F3648;
    case 0x800F364Cu: goto label_800F364C;
    case 0x800F3650u: goto label_800F3650;
    case 0x800F3654u: goto label_800F3654;
    case 0x800F3658u: goto label_800F3658;
    case 0x800F365Cu: goto label_800F365C;
    case 0x800F3660u: goto label_800F3660;
    case 0x800F3664u: goto label_800F3664;
    case 0x800F3668u: goto label_800F3668;
    case 0x800F366Cu: goto label_800F366C;
    case 0x800F3670u: goto label_800F3670;
    case 0x800F3674u: goto label_800F3674;
    case 0x800F3678u: goto label_800F3678;
    case 0x800F367Cu: goto label_800F367C;
    case 0x800F3680u: goto label_800F3680;
    case 0x800F3684u: goto label_800F3684;
    case 0x800F3688u: goto label_800F3688;
    case 0x800F368Cu: goto label_800F368C;
    case 0x800F3690u: goto label_800F3690;
    case 0x800F3694u: goto label_800F3694;
    case 0x800F3698u: goto label_800F3698;
    case 0x800F369Cu: goto label_800F369C;
    case 0x800F36A0u: goto label_800F36A0;
    case 0x800F36A4u: goto label_800F36A4;
    case 0x800F36A8u: goto label_800F36A8;
    case 0x800F36ACu: goto label_800F36AC;
    case 0x800F36B0u: goto label_800F36B0;
    case 0x800F36B4u: goto label_800F36B4;
    case 0x800F36B8u: goto label_800F36B8;
    case 0x800F36BCu: goto label_800F36BC;
    case 0x800F36C0u: goto label_800F36C0;
    case 0x800F36C4u: goto label_800F36C4;
    case 0x800F36C8u: goto label_800F36C8;
    case 0x800F36CCu: goto label_800F36CC;
    case 0x800F36D0u: goto label_800F36D0;
    case 0x800F36D4u: goto label_800F36D4;
    case 0x800F36D8u: goto label_800F36D8;
    case 0x800F36DCu: goto label_800F36DC;
    case 0x800F36E0u: goto label_800F36E0;
    case 0x800F36E4u: goto label_800F36E4;
    case 0x800F36E8u: goto label_800F36E8;
    case 0x800F36ECu: goto label_800F36EC;
    case 0x800F36F0u: goto label_800F36F0;
    case 0x800F36F4u: goto label_800F36F4;
    case 0x800F36F8u: goto label_800F36F8;
    case 0x800F36FCu: goto label_800F36FC;
    case 0x800F3700u: goto label_800F3700;
    case 0x800F3704u: goto label_800F3704;
    case 0x800F3708u: goto label_800F3708;
    case 0x800F370Cu: goto label_800F370C;
    case 0x800F3710u: goto label_800F3710;
    case 0x800F3714u: goto label_800F3714;
    case 0x800F3718u: goto label_800F3718;
    case 0x800F371Cu: goto label_800F371C;
    case 0x800F3720u: goto label_800F3720;
    case 0x800F3724u: goto label_800F3724;
    case 0x800F3728u: goto label_800F3728;
    case 0x800F372Cu: goto label_800F372C;
    case 0x800F3730u: goto label_800F3730;
    case 0x800F3734u: goto label_800F3734;
    case 0x800F3738u: goto label_800F3738;
    case 0x800F373Cu: goto label_800F373C;
    case 0x800F3740u: goto label_800F3740;
    case 0x800F3744u: goto label_800F3744;
    case 0x800F3748u: goto label_800F3748;
    case 0x800F374Cu: goto label_800F374C;
    case 0x800F3750u: goto label_800F3750;
    case 0x800F3754u: goto label_800F3754;
    case 0x800F3758u: goto label_800F3758;
    case 0x800F375Cu: goto label_800F375C;
    case 0x800F3760u: goto label_800F3760;
    case 0x800F3764u: goto label_800F3764;
    case 0x800F3768u: goto label_800F3768;
    case 0x800F376Cu: goto label_800F376C;
    case 0x800F3770u: goto label_800F3770;
    case 0x800F3774u: goto label_800F3774;
    case 0x800F3778u: goto label_800F3778;
    case 0x800F377Cu: goto label_800F377C;
    case 0x800F3780u: goto label_800F3780;
    case 0x800F3784u: goto label_800F3784;
    case 0x800F3788u: goto label_800F3788;
    case 0x800F378Cu: goto label_800F378C;
    case 0x800F3790u: goto label_800F3790;
    case 0x800F3794u: goto label_800F3794;
    case 0x800F3798u: goto label_800F3798;
    case 0x800F379Cu: goto label_800F379C;
    case 0x800F37A0u: goto label_800F37A0;
    case 0x800F37A4u: goto label_800F37A4;
    case 0x800F37A8u: goto label_800F37A8;
    case 0x800F37ACu: goto label_800F37AC;
    case 0x800F37B0u: goto label_800F37B0;
    case 0x800F37B4u: goto label_800F37B4;
    case 0x800F37B8u: goto label_800F37B8;
    case 0x800F37BCu: goto label_800F37BC;
    case 0x800F37C0u: goto label_800F37C0;
    case 0x800F37C4u: goto label_800F37C4;
    case 0x800F37C8u: goto label_800F37C8;
    case 0x800F37CCu: goto label_800F37CC;
    case 0x800F37D0u: goto label_800F37D0;
    case 0x800F37D4u: goto label_800F37D4;
    case 0x800F37D8u: goto label_800F37D8;
    case 0x800F37DCu: goto label_800F37DC;
    case 0x800F37E0u: goto label_800F37E0;
    case 0x800F37E4u: goto label_800F37E4;
    case 0x800F37E8u: goto label_800F37E8;
    case 0x800F37ECu: goto label_800F37EC;
    case 0x800F37F0u: goto label_800F37F0;
    case 0x800F37F4u: goto label_800F37F4;
    case 0x800F37F8u: goto label_800F37F8;
    case 0x800F37FCu: goto label_800F37FC;
    case 0x800F3800u: goto label_800F3800;
    case 0x800F3804u: goto label_800F3804;
    case 0x800F3808u: goto label_800F3808;
    case 0x800F380Cu: goto label_800F380C;
    case 0x800F3810u: goto label_800F3810;
    case 0x800F3814u: goto label_800F3814;
    case 0x800F3818u: goto label_800F3818;
    case 0x800F381Cu: goto label_800F381C;
    case 0x800F3820u: goto label_800F3820;
    case 0x800F3824u: goto label_800F3824;
    case 0x800F3828u: goto label_800F3828;
    case 0x800F382Cu: goto label_800F382C;
    case 0x800F3830u: goto label_800F3830;
    case 0x800F3834u: goto label_800F3834;
    case 0x800F3838u: goto label_800F3838;
    case 0x800F383Cu: goto label_800F383C;
    case 0x800F3840u: goto label_800F3840;
    case 0x800F3844u: goto label_800F3844;
    case 0x800F3848u: goto label_800F3848;
    case 0x800F384Cu: goto label_800F384C;
    case 0x800F3850u: goto label_800F3850;
    case 0x800F3854u: goto label_800F3854;
    case 0x800F3858u: goto label_800F3858;
    case 0x800F385Cu: goto label_800F385C;
    case 0x800F3860u: goto label_800F3860;
    case 0x800F3864u: goto label_800F3864;
    case 0x800F3868u: goto label_800F3868;
    case 0x800F386Cu: goto label_800F386C;
    case 0x800F3870u: goto label_800F3870;
    case 0x800F3874u: goto label_800F3874;
    case 0x800F3878u: goto label_800F3878;
    case 0x800F387Cu: goto label_800F387C;
    case 0x800F3880u: goto label_800F3880;
    case 0x800F3884u: goto label_800F3884;
    case 0x800F3888u: goto label_800F3888;
    case 0x800F388Cu: goto label_800F388C;
    case 0x800F3890u: goto label_800F3890;
    case 0x800F3894u: goto label_800F3894;
    case 0x800F3898u: goto label_800F3898;
    case 0x800F389Cu: goto label_800F389C;
    case 0x800F38A0u: goto label_800F38A0;
    case 0x800F38A4u: goto label_800F38A4;
    case 0x800F38A8u: goto label_800F38A8;
    case 0x800F38ACu: goto label_800F38AC;
    case 0x800F38B0u: goto label_800F38B0;
    case 0x800F38B4u: goto label_800F38B4;
    case 0x800F38B8u: goto label_800F38B8;
    case 0x800F38BCu: goto label_800F38BC;
    case 0x800F38C0u: goto label_800F38C0;
    case 0x800F38C4u: goto label_800F38C4;
    case 0x800F38C8u: goto label_800F38C8;
    case 0x800F38CCu: goto label_800F38CC;
    case 0x800F38D0u: goto label_800F38D0;
    case 0x800F38D4u: goto label_800F38D4;
    case 0x800F38D8u: goto label_800F38D8;
    case 0x800F38DCu: goto label_800F38DC;
    case 0x800F38E0u: goto label_800F38E0;
    case 0x800F38E4u: goto label_800F38E4;
    case 0x800F38E8u: goto label_800F38E8;
    case 0x800F38ECu: goto label_800F38EC;
    case 0x800F38F0u: goto label_800F38F0;
    case 0x800F38F4u: goto label_800F38F4;
    case 0x800F38F8u: goto label_800F38F8;
    case 0x800F38FCu: goto label_800F38FC;
    case 0x800F3900u: goto label_800F3900;
    case 0x800F3904u: goto label_800F3904;
    case 0x800F3908u: goto label_800F3908;
    case 0x800F390Cu: goto label_800F390C;
    case 0x800F3910u: goto label_800F3910;
    case 0x800F3914u: goto label_800F3914;
    case 0x800F3918u: goto label_800F3918;
    case 0x800F391Cu: goto label_800F391C;
    case 0x800F3920u: goto label_800F3920;
    case 0x800F3924u: goto label_800F3924;
    case 0x800F3928u: goto label_800F3928;
    case 0x800F392Cu: goto label_800F392C;
    case 0x800F3930u: goto label_800F3930;
    case 0x800F3934u: goto label_800F3934;
    case 0x800F3938u: goto label_800F3938;
    case 0x800F393Cu: goto label_800F393C;
    case 0x800F3940u: goto label_800F3940;
    case 0x800F3944u: goto label_800F3944;
    case 0x800F3948u: goto label_800F3948;
    case 0x800F394Cu: goto label_800F394C;
    case 0x800F3950u: goto label_800F3950;
    case 0x800F3954u: goto label_800F3954;
    case 0x800F3958u: goto label_800F3958;
    case 0x800F395Cu: goto label_800F395C;
    case 0x800F3960u: goto label_800F3960;
    case 0x800F3964u: goto label_800F3964;
    case 0x800F3968u: goto label_800F3968;
    case 0x800F396Cu: goto label_800F396C;
    case 0x800F3970u: goto label_800F3970;
    case 0x800F3974u: goto label_800F3974;
    case 0x800F3978u: goto label_800F3978;
    case 0x800F397Cu: goto label_800F397C;
    case 0x800F3980u: goto label_800F3980;
    case 0x800F3984u: goto label_800F3984;
    case 0x800F3988u: goto label_800F3988;
    case 0x800F398Cu: goto label_800F398C;
    case 0x800F3990u: goto label_800F3990;
    case 0x800F3994u: goto label_800F3994;
    case 0x800F3998u: goto label_800F3998;
    case 0x800F399Cu: goto label_800F399C;
    case 0x800F39A0u: goto label_800F39A0;
    case 0x800F39A4u: goto label_800F39A4;
    case 0x800F39A8u: goto label_800F39A8;
    case 0x800F39ACu: goto label_800F39AC;
    case 0x800F39B0u: goto label_800F39B0;
    case 0x800F39B4u: goto label_800F39B4;
    case 0x800F39B8u: goto label_800F39B8;
    case 0x800F39BCu: goto label_800F39BC;
    case 0x800F39C0u: goto label_800F39C0;
    case 0x800F39C4u: goto label_800F39C4;
    case 0x800F39C8u: goto label_800F39C8;
    case 0x800F39CCu: goto label_800F39CC;
    case 0x800F39D0u: goto label_800F39D0;
    case 0x800F39D4u: goto label_800F39D4;
    case 0x800F39D8u: goto label_800F39D8;
    case 0x800F39DCu: goto label_800F39DC;
    case 0x800F39E0u: goto label_800F39E0;
    case 0x800F39E4u: goto label_800F39E4;
    case 0x800F39E8u: goto label_800F39E8;
    case 0x800F39ECu: goto label_800F39EC;
    case 0x800F39F0u: goto label_800F39F0;
    case 0x800F39F4u: goto label_800F39F4;
    case 0x800F39F8u: goto label_800F39F8;
    case 0x800F39FCu: goto label_800F39FC;
    case 0x800F3A00u: goto label_800F3A00;
    case 0x800F3A04u: goto label_800F3A04;
    case 0x800F3A08u: goto label_800F3A08;
    case 0x800F3A0Cu: goto label_800F3A0C;
    case 0x800F3A10u: goto label_800F3A10;
    case 0x800F3A14u: goto label_800F3A14;
    case 0x800F3A18u: goto label_800F3A18;
    case 0x800F3A1Cu: goto label_800F3A1C;
    case 0x800F3A20u: goto label_800F3A20;
    case 0x800F3A24u: goto label_800F3A24;
    case 0x800F3A28u: goto label_800F3A28;
    case 0x800F3A2Cu: goto label_800F3A2C;
    case 0x800F3A30u: goto label_800F3A30;
    case 0x800F3A34u: goto label_800F3A34;
    case 0x800F3A38u: goto label_800F3A38;
    case 0x800F3A3Cu: goto label_800F3A3C;
    case 0x800F3A40u: goto label_800F3A40;
    case 0x800F3A44u: goto label_800F3A44;
    case 0x800F3A48u: goto label_800F3A48;
    case 0x800F3A4Cu: goto label_800F3A4C;
    case 0x800F3A50u: goto label_800F3A50;
    case 0x800F3A54u: goto label_800F3A54;
    case 0x800F3A58u: goto label_800F3A58;
    case 0x800F3A5Cu: goto label_800F3A5C;
    case 0x800F3A60u: goto label_800F3A60;
    case 0x800F3A64u: goto label_800F3A64;
    case 0x800F3A68u: goto label_800F3A68;
    case 0x800F3A6Cu: goto label_800F3A6C;
    case 0x800F3A70u: goto label_800F3A70;
    case 0x800F3A74u: goto label_800F3A74;
    case 0x800F3A78u: goto label_800F3A78;
    case 0x800F3A7Cu: goto label_800F3A7C;
    case 0x800F3A80u: goto label_800F3A80;
    case 0x800F3A84u: goto label_800F3A84;
    case 0x800F3A88u: goto label_800F3A88;
    case 0x800F3A8Cu: goto label_800F3A8C;
    case 0x800F3A90u: goto label_800F3A90;
    case 0x800F3A94u: goto label_800F3A94;
    case 0x800F3A98u: goto label_800F3A98;
    case 0x800F3A9Cu: goto label_800F3A9C;
    case 0x800F3AA0u: goto label_800F3AA0;
    case 0x800F3AA4u: goto label_800F3AA4;
    case 0x800F3AA8u: goto label_800F3AA8;
    case 0x800F3AACu: goto label_800F3AAC;
    case 0x800F3AB0u: goto label_800F3AB0;
    case 0x800F3AB4u: goto label_800F3AB4;
    case 0x800F3AB8u: goto label_800F3AB8;
    case 0x800F3ABCu: goto label_800F3ABC;
    case 0x800F3AC0u: goto label_800F3AC0;
    case 0x800F3AC4u: goto label_800F3AC4;
    case 0x800F3AC8u: goto label_800F3AC8;
    case 0x800F3ACCu: goto label_800F3ACC;
    case 0x800F3AD0u: goto label_800F3AD0;
    case 0x800F3AD4u: goto label_800F3AD4;
    case 0x800F3AD8u: goto label_800F3AD8;
    case 0x800F3ADCu: goto label_800F3ADC;
    case 0x800F3AE0u: goto label_800F3AE0;
    case 0x800F3AE4u: goto label_800F3AE4;
    case 0x800F3AE8u: goto label_800F3AE8;
    case 0x800F3AECu: goto label_800F3AEC;
    case 0x800F3AF0u: goto label_800F3AF0;
    case 0x800F3AF4u: goto label_800F3AF4;
    case 0x800F3AF8u: goto label_800F3AF8;
    case 0x800F3AFCu: goto label_800F3AFC;
    case 0x800F3B00u: goto label_800F3B00;
    case 0x800F3B04u: goto label_800F3B04;
    case 0x800F3B08u: goto label_800F3B08;
    case 0x800F3B0Cu: goto label_800F3B0C;
    case 0x800F3B10u: goto label_800F3B10;
    case 0x800F3B14u: goto label_800F3B14;
    case 0x800F3B18u: goto label_800F3B18;
    case 0x800F3B1Cu: goto label_800F3B1C;
    case 0x800F3B20u: goto label_800F3B20;
    case 0x800F3B24u: goto label_800F3B24;
    case 0x800F3B28u: goto label_800F3B28;
    case 0x800F3B2Cu: goto label_800F3B2C;
    case 0x800F3B30u: goto label_800F3B30;
    case 0x800F3B34u: goto label_800F3B34;
    case 0x800F3B38u: goto label_800F3B38;
    case 0x800F3B3Cu: goto label_800F3B3C;
    case 0x800F3B40u: goto label_800F3B40;
    case 0x800F3B44u: goto label_800F3B44;
    case 0x800F3B48u: goto label_800F3B48;
    case 0x800F3B4Cu: goto label_800F3B4C;
    case 0x800F3B50u: goto label_800F3B50;
    case 0x800F3B54u: goto label_800F3B54;
    case 0x800F3B58u: goto label_800F3B58;
    case 0x800F3B5Cu: goto label_800F3B5C;
    case 0x800F3B60u: goto label_800F3B60;
    case 0x800F3B64u: goto label_800F3B64;
    case 0x800F3B68u: goto label_800F3B68;
    case 0x800F3B6Cu: goto label_800F3B6C;
    case 0x800F3B70u: goto label_800F3B70;
    case 0x800F3B74u: goto label_800F3B74;
    case 0x800F3B78u: goto label_800F3B78;
    case 0x800F3B7Cu: goto label_800F3B7C;
    case 0x800F3B80u: goto label_800F3B80;
    case 0x800F3B84u: goto label_800F3B84;
    case 0x800F3B88u: goto label_800F3B88;
    case 0x800F3B8Cu: goto label_800F3B8C;
    case 0x800F3B90u: goto label_800F3B90;
    case 0x800F3B94u: goto label_800F3B94;
    case 0x800F3B98u: goto label_800F3B98;
    case 0x800F3B9Cu: goto label_800F3B9C;
    case 0x800F3BA0u: goto label_800F3BA0;
    case 0x800F3BA4u: goto label_800F3BA4;
    case 0x800F3BA8u: goto label_800F3BA8;
    case 0x800F3BACu: goto label_800F3BAC;
    case 0x800F3BB0u: goto label_800F3BB0;
    case 0x800F3BB4u: goto label_800F3BB4;
    case 0x800F3BB8u: goto label_800F3BB8;
    case 0x800F3BBCu: goto label_800F3BBC;
    case 0x800F3BC0u: goto label_800F3BC0;
    case 0x800F3BC4u: goto label_800F3BC4;
    case 0x800F3BC8u: goto label_800F3BC8;
    case 0x800F3BCCu: goto label_800F3BCC;
    case 0x800F3BD0u: goto label_800F3BD0;
    case 0x800F3BD4u: goto label_800F3BD4;
    case 0x800F3BD8u: goto label_800F3BD8;
    case 0x800F3BDCu: goto label_800F3BDC;
    case 0x800F3BE0u: goto label_800F3BE0;
    case 0x800F3BE4u: goto label_800F3BE4;
    case 0x800F3BE8u: goto label_800F3BE8;
    case 0x800F3BECu: goto label_800F3BEC;
    case 0x800F3BF0u: goto label_800F3BF0;
    case 0x800F3BF4u: goto label_800F3BF4;
    case 0x800F3BF8u: goto label_800F3BF8;
    case 0x800F3BFCu: goto label_800F3BFC;
    case 0x800F3C00u: goto label_800F3C00;
    case 0x800F3C04u: goto label_800F3C04;
    case 0x800F3C08u: goto label_800F3C08;
    case 0x800F3C0Cu: goto label_800F3C0C;
    case 0x800F3C10u: goto label_800F3C10;
    case 0x800F3C14u: goto label_800F3C14;
    case 0x800F3C18u: goto label_800F3C18;
    case 0x800F3C1Cu: goto label_800F3C1C;
    case 0x800F3C20u: goto label_800F3C20;
    case 0x800F3C24u: goto label_800F3C24;
    case 0x800F3C28u: goto label_800F3C28;
    case 0x800F3C2Cu: goto label_800F3C2C;
    case 0x800F3C30u: goto label_800F3C30;
    case 0x800F3C34u: goto label_800F3C34;
    case 0x800F3C38u: goto label_800F3C38;
    case 0x800F3C3Cu: goto label_800F3C3C;
    case 0x800F3C40u: goto label_800F3C40;
    case 0x800F3C44u: goto label_800F3C44;
    case 0x800F3C48u: goto label_800F3C48;
    case 0x800F3C4Cu: goto label_800F3C4C;
    case 0x800F3C50u: goto label_800F3C50;
    case 0x800F3C54u: goto label_800F3C54;
    case 0x800F3C58u: goto label_800F3C58;
    case 0x800F3C5Cu: goto label_800F3C5C;
    case 0x800F3C60u: goto label_800F3C60;
    case 0x800F3C64u: goto label_800F3C64;
    case 0x800F3C68u: goto label_800F3C68;
    case 0x800F3C6Cu: goto label_800F3C6C;
    case 0x800F3C70u: goto label_800F3C70;
    case 0x800F3C74u: goto label_800F3C74;
    case 0x800F3C78u: goto label_800F3C78;
    case 0x800F3C7Cu: goto label_800F3C7C;
    case 0x800F3C80u: goto label_800F3C80;
    case 0x800F3C84u: goto label_800F3C84;
    case 0x800F3C88u: goto label_800F3C88;
    case 0x800F3C8Cu: goto label_800F3C8C;
    case 0x800F3C90u: goto label_800F3C90;
    case 0x800F3C94u: goto label_800F3C94;
    case 0x800F3C98u: goto label_800F3C98;
    case 0x800F3C9Cu: goto label_800F3C9C;
    case 0x800F3CA0u: goto label_800F3CA0;
    case 0x800F3CA4u: goto label_800F3CA4;
    case 0x800F3CA8u: goto label_800F3CA8;
    case 0x800F3CACu: goto label_800F3CAC;
    case 0x800F3CB0u: goto label_800F3CB0;
    case 0x800F3CB4u: goto label_800F3CB4;
    case 0x800F3CB8u: goto label_800F3CB8;
    case 0x800F3CBCu: goto label_800F3CBC;
    case 0x800F3CC0u: goto label_800F3CC0;
    case 0x800F3CC4u: goto label_800F3CC4;
    case 0x800F3CC8u: goto label_800F3CC8;
    case 0x800F3CCCu: goto label_800F3CCC;
    case 0x800F3CD0u: goto label_800F3CD0;
    case 0x800F3CD4u: goto label_800F3CD4;
    case 0x800F3CD8u: goto label_800F3CD8;
    case 0x800F3CDCu: goto label_800F3CDC;
    case 0x800F3CE0u: goto label_800F3CE0;
    case 0x800F3CE4u: goto label_800F3CE4;
    case 0x800F3CE8u: goto label_800F3CE8;
    case 0x800F3CECu: goto label_800F3CEC;
    case 0x800F3CF0u: goto label_800F3CF0;
    case 0x800F3CF4u: goto label_800F3CF4;
    case 0x800F3CF8u: goto label_800F3CF8;
    case 0x800F3CFCu: goto label_800F3CFC;
    case 0x800F3D00u: goto label_800F3D00;
    case 0x800F3D04u: goto label_800F3D04;
    case 0x800F3D08u: goto label_800F3D08;
    case 0x800F3D0Cu: goto label_800F3D0C;
    case 0x800F3D10u: goto label_800F3D10;
    case 0x800F3D14u: goto label_800F3D14;
    case 0x800F3D18u: goto label_800F3D18;
    case 0x800F3D1Cu: goto label_800F3D1C;
    case 0x800F3D20u: goto label_800F3D20;
    case 0x800F3D24u: goto label_800F3D24;
    case 0x800F3D28u: goto label_800F3D28;
    case 0x800F3D2Cu: goto label_800F3D2C;
    case 0x800F3D30u: goto label_800F3D30;
    case 0x800F3D34u: goto label_800F3D34;
    case 0x800F3D38u: goto label_800F3D38;
    case 0x800F3D3Cu: goto label_800F3D3C;
    case 0x800F3D40u: goto label_800F3D40;
    case 0x800F3D44u: goto label_800F3D44;
    case 0x800F3D48u: goto label_800F3D48;
    case 0x800F3D4Cu: goto label_800F3D4C;
    case 0x800F3D50u: goto label_800F3D50;
    case 0x800F3D54u: goto label_800F3D54;
    case 0x800F3D58u: goto label_800F3D58;
    case 0x800F3D5Cu: goto label_800F3D5C;
    case 0x800F3D60u: goto label_800F3D60;
    case 0x800F3D64u: goto label_800F3D64;
    case 0x800F3D68u: goto label_800F3D68;
    case 0x800F3D6Cu: goto label_800F3D6C;
    case 0x800F3D70u: goto label_800F3D70;
    case 0x800F3D74u: goto label_800F3D74;
    case 0x800F3D78u: goto label_800F3D78;
    case 0x800F3D7Cu: goto label_800F3D7C;
    case 0x800F3D80u: goto label_800F3D80;
    case 0x800F3D84u: goto label_800F3D84;
    case 0x800F3D88u: goto label_800F3D88;
    case 0x800F3D8Cu: goto label_800F3D8C;
    case 0x800F3D90u: goto label_800F3D90;
    case 0x800F3D94u: goto label_800F3D94;
    case 0x800F3D98u: goto label_800F3D98;
    case 0x800F3D9Cu: goto label_800F3D9C;
    case 0x800F3DA0u: goto label_800F3DA0;
    case 0x800F3DA4u: goto label_800F3DA4;
    case 0x800F3DA8u: goto label_800F3DA8;
    case 0x800F3DACu: goto label_800F3DAC;
    case 0x800F3DB0u: goto label_800F3DB0;
    case 0x800F3DB4u: goto label_800F3DB4;
    case 0x800F3DB8u: goto label_800F3DB8;
    case 0x800F3DBCu: goto label_800F3DBC;
    case 0x800F3DC0u: goto label_800F3DC0;
    case 0x800F3DC4u: goto label_800F3DC4;
    case 0x800F3DC8u: goto label_800F3DC8;
    case 0x800F3DCCu: goto label_800F3DCC;
    case 0x800F3DD0u: goto label_800F3DD0;
    case 0x800F3DD4u: goto label_800F3DD4;
    case 0x800F3DD8u: goto label_800F3DD8;
    case 0x800F3DDCu: goto label_800F3DDC;
    case 0x800F3DE0u: goto label_800F3DE0;
    case 0x800F3DE4u: goto label_800F3DE4;
    case 0x800F3DE8u: goto label_800F3DE8;
    case 0x800F3DECu: goto label_800F3DEC;
    case 0x800F3DF0u: goto label_800F3DF0;
    case 0x800F3DF4u: goto label_800F3DF4;
    case 0x800F3DF8u: goto label_800F3DF8;
    case 0x800F3DFCu: goto label_800F3DFC;
    case 0x800F3E00u: goto label_800F3E00;
    case 0x800F3E04u: goto label_800F3E04;
    case 0x800F3E08u: goto label_800F3E08;
    case 0x800F3E0Cu: goto label_800F3E0C;
    case 0x800F3E10u: goto label_800F3E10;
    case 0x800F3E14u: goto label_800F3E14;
    case 0x800F3E18u: goto label_800F3E18;
    case 0x800F3E1Cu: goto label_800F3E1C;
    case 0x800F3E20u: goto label_800F3E20;
    case 0x800F3E24u: goto label_800F3E24;
    case 0x800F3E28u: goto label_800F3E28;
    case 0x800F3E2Cu: goto label_800F3E2C;
    case 0x800F3E30u: goto label_800F3E30;
    case 0x800F3E34u: goto label_800F3E34;
    case 0x800F3E38u: goto label_800F3E38;
    case 0x800F3E3Cu: goto label_800F3E3C;
    case 0x800F3E40u: goto label_800F3E40;
    case 0x800F3E44u: goto label_800F3E44;
    case 0x800F3E48u: goto label_800F3E48;
    case 0x800F3E4Cu: goto label_800F3E4C;
    case 0x800F3E50u: goto label_800F3E50;
    case 0x800F3E54u: goto label_800F3E54;
    case 0x800F3E58u: goto label_800F3E58;
    case 0x800F3E5Cu: goto label_800F3E5C;
    case 0x800F3E60u: goto label_800F3E60;
    case 0x800F3E64u: goto label_800F3E64;
    case 0x800F3E68u: goto label_800F3E68;
    case 0x800F3E6Cu: goto label_800F3E6C;
    case 0x800F3E70u: goto label_800F3E70;
    case 0x800F3E74u: goto label_800F3E74;
    case 0x800F3E78u: goto label_800F3E78;
    case 0x800F3E7Cu: goto label_800F3E7C;
    case 0x800F3E80u: goto label_800F3E80;
    case 0x800F3E84u: goto label_800F3E84;
    case 0x800F3E88u: goto label_800F3E88;
    case 0x800F3E8Cu: goto label_800F3E8C;
    case 0x800F3E90u: goto label_800F3E90;
    case 0x800F3E94u: goto label_800F3E94;
    case 0x800F3E98u: goto label_800F3E98;
    case 0x800F3E9Cu: goto label_800F3E9C;
    case 0x800F3EA0u: goto label_800F3EA0;
    case 0x800F3EA4u: goto label_800F3EA4;
    case 0x800F3EA8u: goto label_800F3EA8;
    case 0x800F3EACu: goto label_800F3EAC;
    case 0x800F3EB0u: goto label_800F3EB0;
    case 0x800F3EB4u: goto label_800F3EB4;
    case 0x800F3EB8u: goto label_800F3EB8;
    case 0x800F3EBCu: goto label_800F3EBC;
    case 0x800F3EC0u: goto label_800F3EC0;
    case 0x800F3EC4u: goto label_800F3EC4;
    case 0x800F3EC8u: goto label_800F3EC8;
    case 0x800F3ECCu: goto label_800F3ECC;
    case 0x800F3ED0u: goto label_800F3ED0;
    case 0x800F3ED4u: goto label_800F3ED4;
    case 0x800F3ED8u: goto label_800F3ED8;
    case 0x800F3EDCu: goto label_800F3EDC;
    case 0x800F3EE0u: goto label_800F3EE0;
    case 0x800F3EE4u: goto label_800F3EE4;
    case 0x800F3EE8u: goto label_800F3EE8;
    case 0x800F3EECu: goto label_800F3EEC;
    case 0x800F3EF0u: goto label_800F3EF0;
    case 0x800F3EF4u: goto label_800F3EF4;
    case 0x800F3EF8u: goto label_800F3EF8;
    case 0x800F3EFCu: goto label_800F3EFC;
    case 0x800F3F00u: goto label_800F3F00;
    case 0x800F3F04u: goto label_800F3F04;
    case 0x800F3F08u: goto label_800F3F08;
    case 0x800F3F0Cu: goto label_800F3F0C;
    case 0x800F3F10u: goto label_800F3F10;
    case 0x800F3F14u: goto label_800F3F14;
    case 0x800F3F18u: goto label_800F3F18;
    case 0x800F3F1Cu: goto label_800F3F1C;
    case 0x800F3F20u: goto label_800F3F20;
    case 0x800F3F24u: goto label_800F3F24;
    case 0x800F3F28u: goto label_800F3F28;
    case 0x800F3F2Cu: goto label_800F3F2C;
    case 0x800F3F30u: goto label_800F3F30;
    case 0x800F3F34u: goto label_800F3F34;
    case 0x800F3F38u: goto label_800F3F38;
    case 0x800F3F3Cu: goto label_800F3F3C;
    case 0x800F3F40u: goto label_800F3F40;
    case 0x800F3F44u: goto label_800F3F44;
    case 0x800F3F48u: goto label_800F3F48;
    case 0x800F3F4Cu: goto label_800F3F4C;
    case 0x800F3F50u: goto label_800F3F50;
    case 0x800F3F54u: goto label_800F3F54;
    case 0x800F3F58u: goto label_800F3F58;
    case 0x800F3F5Cu: goto label_800F3F5C;
    case 0x800F3F60u: goto label_800F3F60;
    case 0x800F3F64u: goto label_800F3F64;
    case 0x800F3F68u: goto label_800F3F68;
    case 0x800F3F6Cu: goto label_800F3F6C;
    case 0x800F3F70u: goto label_800F3F70;
    case 0x800F3F74u: goto label_800F3F74;
    case 0x800F3F78u: goto label_800F3F78;
    case 0x800F3F7Cu: goto label_800F3F7C;
    case 0x800F3F80u: goto label_800F3F80;
    case 0x800F3F84u: goto label_800F3F84;
    case 0x800F3F88u: goto label_800F3F88;
    case 0x800F3F8Cu: goto label_800F3F8C;
    case 0x800F3F90u: goto label_800F3F90;
    case 0x800F3F94u: goto label_800F3F94;
    case 0x800F3F98u: goto label_800F3F98;
    case 0x800F3F9Cu: goto label_800F3F9C;
    case 0x800F3FA0u: goto label_800F3FA0;
    case 0x800F3FA4u: goto label_800F3FA4;
    case 0x800F3FA8u: goto label_800F3FA8;
    case 0x800F3FACu: goto label_800F3FAC;
    case 0x800F3FB0u: goto label_800F3FB0;
    case 0x800F3FB4u: goto label_800F3FB4;
    case 0x800F3FB8u: goto label_800F3FB8;
    case 0x800F3FBCu: goto label_800F3FBC;
    case 0x800F3FC0u: goto label_800F3FC0;
    case 0x800F3FC4u: goto label_800F3FC4;
    case 0x800F3FC8u: goto label_800F3FC8;
    case 0x800F3FCCu: goto label_800F3FCC;
    case 0x800F3FD0u: goto label_800F3FD0;
    case 0x800F3FD4u: goto label_800F3FD4;
    case 0x800F3FD8u: goto label_800F3FD8;
    case 0x800F3FDCu: goto label_800F3FDC;
    case 0x800F3FE0u: goto label_800F3FE0;
    case 0x800F3FE4u: goto label_800F3FE4;
    case 0x800F3FE8u: goto label_800F3FE8;
    case 0x800F3FECu: goto label_800F3FEC;
    case 0x800F3FF0u: goto label_800F3FF0;
    case 0x800F3FF4u: goto label_800F3FF4;
    case 0x800F3FF8u: goto label_800F3FF8;
    case 0x800F3FFCu: goto label_800F3FFC;
    case 0x800F4000u: goto label_800F4000;
    case 0x800F4004u: goto label_800F4004;
    case 0x800F4008u: goto label_800F4008;
    case 0x800F400Cu: goto label_800F400C;
    case 0x800F4010u: goto label_800F4010;
    case 0x800F4014u: goto label_800F4014;
    case 0x800F4018u: goto label_800F4018;
    case 0x800F401Cu: goto label_800F401C;
    case 0x800F4020u: goto label_800F4020;
    case 0x800F4024u: goto label_800F4024;
    case 0x800F4028u: goto label_800F4028;
    case 0x800F402Cu: goto label_800F402C;
    case 0x800F4030u: goto label_800F4030;
    case 0x800F4034u: goto label_800F4034;
    case 0x800F4038u: goto label_800F4038;
    case 0x800F403Cu: goto label_800F403C;
    case 0x800F4040u: goto label_800F4040;
    case 0x800F4044u: goto label_800F4044;
    case 0x800F4048u: goto label_800F4048;
    case 0x800F404Cu: goto label_800F404C;
    case 0x800F4050u: goto label_800F4050;
    case 0x800F4054u: goto label_800F4054;
    case 0x800F4058u: goto label_800F4058;
    case 0x800F405Cu: goto label_800F405C;
    case 0x800F4060u: goto label_800F4060;
    case 0x800F4064u: goto label_800F4064;
    case 0x800F4068u: goto label_800F4068;
    case 0x800F406Cu: goto label_800F406C;
    case 0x800F4070u: goto label_800F4070;
    case 0x800F4074u: goto label_800F4074;
    case 0x800F4078u: goto label_800F4078;
    case 0x800F407Cu: goto label_800F407C;
    case 0x800F4080u: goto label_800F4080;
    case 0x800F4084u: goto label_800F4084;
    case 0x800F4088u: goto label_800F4088;
    case 0x800F408Cu: goto label_800F408C;
    case 0x800F4090u: goto label_800F4090;
    case 0x800F4094u: goto label_800F4094;
    case 0x800F4098u: goto label_800F4098;
    case 0x800F409Cu: goto label_800F409C;
    case 0x800F40A0u: goto label_800F40A0;
    case 0x800F40A4u: goto label_800F40A4;
    case 0x800F40A8u: goto label_800F40A8;
    case 0x800F40ACu: goto label_800F40AC;
    case 0x800F40B0u: goto label_800F40B0;
    case 0x800F40B4u: goto label_800F40B4;
    case 0x800F40B8u: goto label_800F40B8;
    case 0x800F40BCu: goto label_800F40BC;
    case 0x800F40C0u: goto label_800F40C0;
    case 0x800F40C4u: goto label_800F40C4;
    case 0x800F40C8u: goto label_800F40C8;
    case 0x800F40CCu: goto label_800F40CC;
    case 0x800F40D0u: goto label_800F40D0;
    case 0x800F40D4u: goto label_800F40D4;
    case 0x800F40D8u: goto label_800F40D8;
    case 0x800F40DCu: goto label_800F40DC;
    case 0x800F40E0u: goto label_800F40E0;
    case 0x800F40E4u: goto label_800F40E4;
    case 0x800F40E8u: goto label_800F40E8;
    case 0x800F40ECu: goto label_800F40EC;
    case 0x800F40F0u: goto label_800F40F0;
    case 0x800F40F4u: goto label_800F40F4;
    case 0x800F40F8u: goto label_800F40F8;
    case 0x800F40FCu: goto label_800F40FC;
    case 0x800F4100u: goto label_800F4100;
    case 0x800F4104u: goto label_800F4104;
    case 0x800F4108u: goto label_800F4108;
    case 0x800F410Cu: goto label_800F410C;
    case 0x800F4110u: goto label_800F4110;
    case 0x800F4114u: goto label_800F4114;
    case 0x800F4118u: goto label_800F4118;
    case 0x800F411Cu: goto label_800F411C;
    case 0x800F4120u: goto label_800F4120;
    case 0x800F4124u: goto label_800F4124;
    case 0x800F4128u: goto label_800F4128;
    case 0x800F412Cu: goto label_800F412C;
    case 0x800F4130u: goto label_800F4130;
    case 0x800F4134u: goto label_800F4134;
    case 0x800F4138u: goto label_800F4138;
    case 0x800F413Cu: goto label_800F413C;
    case 0x800F4140u: goto label_800F4140;
    case 0x800F4144u: goto label_800F4144;
    case 0x800F4148u: goto label_800F4148;
    case 0x800F414Cu: goto label_800F414C;
    case 0x800F4150u: goto label_800F4150;
    case 0x800F4154u: goto label_800F4154;
    case 0x800F4158u: goto label_800F4158;
    case 0x800F415Cu: goto label_800F415C;
    case 0x800F4160u: goto label_800F4160;
    case 0x800F4164u: goto label_800F4164;
    case 0x800F4168u: goto label_800F4168;
    case 0x800F416Cu: goto label_800F416C;
    case 0x800F4170u: goto label_800F4170;
    case 0x800F4174u: goto label_800F4174;
    case 0x800F4178u: goto label_800F4178;
    case 0x800F417Cu: goto label_800F417C;
    case 0x800F4180u: goto label_800F4180;
    case 0x800F4184u: goto label_800F4184;
    case 0x800F4188u: goto label_800F4188;
    case 0x800F418Cu: goto label_800F418C;
    case 0x800F4190u: goto label_800F4190;
    case 0x800F4194u: goto label_800F4194;
    case 0x800F4198u: goto label_800F4198;
    case 0x800F419Cu: goto label_800F419C;
    case 0x800F41A0u: goto label_800F41A0;
    case 0x800F41A4u: goto label_800F41A4;
    case 0x800F41A8u: goto label_800F41A8;
    case 0x800F41ACu: goto label_800F41AC;
    case 0x800F41B0u: goto label_800F41B0;
    case 0x800F41B4u: goto label_800F41B4;
    case 0x800F41B8u: goto label_800F41B8;
    case 0x800F41BCu: goto label_800F41BC;
    case 0x800F41C0u: goto label_800F41C0;
    case 0x800F41C4u: goto label_800F41C4;
    case 0x800F41C8u: goto label_800F41C8;
    case 0x800F41CCu: goto label_800F41CC;
    case 0x800F41D0u: goto label_800F41D0;
    case 0x800F41D4u: goto label_800F41D4;
    case 0x800F41D8u: goto label_800F41D8;
    case 0x800F41DCu: goto label_800F41DC;
    case 0x800F41E0u: goto label_800F41E0;
    case 0x800F41E4u: goto label_800F41E4;
    case 0x800F41E8u: goto label_800F41E8;
    case 0x800F41ECu: goto label_800F41EC;
    case 0x800F41F0u: goto label_800F41F0;
    case 0x800F41F4u: goto label_800F41F4;
    case 0x800F41F8u: goto label_800F41F8;
    case 0x800F41FCu: goto label_800F41FC;
    case 0x800F4200u: goto label_800F4200;
    case 0x800F4204u: goto label_800F4204;
    case 0x800F4208u: goto label_800F4208;
    case 0x800F420Cu: goto label_800F420C;
    case 0x800F4210u: goto label_800F4210;
    case 0x800F4214u: goto label_800F4214;
    case 0x800F4218u: goto label_800F4218;
    case 0x800F421Cu: goto label_800F421C;
    case 0x800F4220u: goto label_800F4220;
    case 0x800F4224u: goto label_800F4224;
    case 0x800F4228u: goto label_800F4228;
    case 0x800F422Cu: goto label_800F422C;
    case 0x800F4230u: goto label_800F4230;
    case 0x800F4234u: goto label_800F4234;
    case 0x800F4238u: goto label_800F4238;
    case 0x800F423Cu: goto label_800F423C;
    case 0x800F4240u: goto label_800F4240;
    case 0x800F4244u: goto label_800F4244;
    case 0x800F4248u: goto label_800F4248;
    case 0x800F424Cu: goto label_800F424C;
    case 0x800F4250u: goto label_800F4250;
    case 0x800F4254u: goto label_800F4254;
    case 0x800F4258u: goto label_800F4258;
    case 0x800F425Cu: goto label_800F425C;
    case 0x800F4260u: goto label_800F4260;
    case 0x800F4264u: goto label_800F4264;
    case 0x800F4268u: goto label_800F4268;
    case 0x800F426Cu: goto label_800F426C;
    case 0x800F4270u: goto label_800F4270;
    case 0x800F4274u: goto label_800F4274;
    case 0x800F4278u: goto label_800F4278;
    case 0x800F427Cu: goto label_800F427C;
    case 0x800F4280u: goto label_800F4280;
    case 0x800F4284u: goto label_800F4284;
    case 0x800F4288u: goto label_800F4288;
    case 0x800F428Cu: goto label_800F428C;
    case 0x800F4290u: goto label_800F4290;
    case 0x800F4294u: goto label_800F4294;
    case 0x800F4298u: goto label_800F4298;
    case 0x800F429Cu: goto label_800F429C;
    case 0x800F42A0u: goto label_800F42A0;
    case 0x800F42A4u: goto label_800F42A4;
    case 0x800F42A8u: goto label_800F42A8;
    case 0x800F42ACu: goto label_800F42AC;
    case 0x800F42B0u: goto label_800F42B0;
    case 0x800F42B4u: goto label_800F42B4;
    case 0x800F42B8u: goto label_800F42B8;
    case 0x800F42BCu: goto label_800F42BC;
    case 0x800F42C0u: goto label_800F42C0;
    case 0x800F42C4u: goto label_800F42C4;
    case 0x800F42C8u: goto label_800F42C8;
    case 0x800F42CCu: goto label_800F42CC;
    case 0x800F42D0u: goto label_800F42D0;
    case 0x800F42D4u: goto label_800F42D4;
    case 0x800F42D8u: goto label_800F42D8;
    case 0x800F42DCu: goto label_800F42DC;
    case 0x800F42E0u: goto label_800F42E0;
    case 0x800F42E4u: goto label_800F42E4;
    case 0x800F42E8u: goto label_800F42E8;
    case 0x800F42ECu: goto label_800F42EC;
    case 0x800F42F0u: goto label_800F42F0;
    case 0x800F42F4u: goto label_800F42F4;
    case 0x800F42F8u: goto label_800F42F8;
    case 0x800F42FCu: goto label_800F42FC;
    case 0x800F4300u: goto label_800F4300;
    case 0x800F4304u: goto label_800F4304;
    case 0x800F4308u: goto label_800F4308;
    case 0x800F430Cu: goto label_800F430C;
    case 0x800F4310u: goto label_800F4310;
    case 0x800F4314u: goto label_800F4314;
    case 0x800F4318u: goto label_800F4318;
    case 0x800F431Cu: goto label_800F431C;
    case 0x800F4320u: goto label_800F4320;
    case 0x800F4324u: goto label_800F4324;
    case 0x800F4328u: goto label_800F4328;
    case 0x800F432Cu: goto label_800F432C;
    case 0x800F4330u: goto label_800F4330;
    case 0x800F4334u: goto label_800F4334;
    case 0x800F4338u: goto label_800F4338;
    case 0x800F433Cu: goto label_800F433C;
    case 0x800F4340u: goto label_800F4340;
    case 0x800F4344u: goto label_800F4344;
    case 0x800F4348u: goto label_800F4348;
    case 0x800F434Cu: goto label_800F434C;
    case 0x800F4350u: goto label_800F4350;
    case 0x800F4354u: goto label_800F4354;
    case 0x800F4358u: goto label_800F4358;
    case 0x800F435Cu: goto label_800F435C;
    case 0x800F4360u: goto label_800F4360;
    case 0x800F4364u: goto label_800F4364;
    case 0x800F4368u: goto label_800F4368;
    case 0x800F436Cu: goto label_800F436C;
    case 0x800F4370u: goto label_800F4370;
    case 0x800F4374u: goto label_800F4374;
    case 0x800F4378u: goto label_800F4378;
    case 0x800F437Cu: goto label_800F437C;
    case 0x800F4380u: goto label_800F4380;
    case 0x800F4384u: goto label_800F4384;
    case 0x800F4388u: goto label_800F4388;
    case 0x800F438Cu: goto label_800F438C;
    case 0x800F4390u: goto label_800F4390;
    case 0x800F4394u: goto label_800F4394;
    case 0x800F4398u: goto label_800F4398;
    case 0x800F439Cu: goto label_800F439C;
    case 0x800F43A0u: goto label_800F43A0;
    case 0x800F43A4u: goto label_800F43A4;
    case 0x800F43A8u: goto label_800F43A8;
    case 0x800F43ACu: goto label_800F43AC;
    case 0x800F43B0u: goto label_800F43B0;
    case 0x800F43B4u: goto label_800F43B4;
    case 0x800F43B8u: goto label_800F43B8;
    case 0x800F43BCu: goto label_800F43BC;
    case 0x800F43C0u: goto label_800F43C0;
    case 0x800F43C4u: goto label_800F43C4;
    case 0x800F43C8u: goto label_800F43C8;
    case 0x800F43CCu: goto label_800F43CC;
    case 0x800F43D0u: goto label_800F43D0;
    case 0x800F43D4u: goto label_800F43D4;
    case 0x800F43D8u: goto label_800F43D8;
    case 0x800F43DCu: goto label_800F43DC;
    case 0x800F43E0u: goto label_800F43E0;
    case 0x800F43E4u: goto label_800F43E4;
    case 0x800F43E8u: goto label_800F43E8;
    case 0x800F43ECu: goto label_800F43EC;
    case 0x800F43F0u: goto label_800F43F0;
    case 0x800F43F4u: goto label_800F43F4;
    case 0x800F43F8u: goto label_800F43F8;
    case 0x800F43FCu: goto label_800F43FC;
    case 0x800F4400u: goto label_800F4400;
    case 0x800F4404u: goto label_800F4404;
    case 0x800F4408u: goto label_800F4408;
    case 0x800F440Cu: goto label_800F440C;
    case 0x800F4410u: goto label_800F4410;
    case 0x800F4414u: goto label_800F4414;
    case 0x800F4418u: goto label_800F4418;
    case 0x800F441Cu: goto label_800F441C;
    case 0x800F4420u: goto label_800F4420;
    case 0x800F4424u: goto label_800F4424;
    case 0x800F4428u: goto label_800F4428;
    case 0x800F442Cu: goto label_800F442C;
    case 0x800F4430u: goto label_800F4430;
    case 0x800F4434u: goto label_800F4434;
    case 0x800F4438u: goto label_800F4438;
    case 0x800F443Cu: goto label_800F443C;
    case 0x800F4440u: goto label_800F4440;
    case 0x800F4444u: goto label_800F4444;
    case 0x800F4448u: goto label_800F4448;
    case 0x800F444Cu: goto label_800F444C;
    case 0x800F4450u: goto label_800F4450;
    case 0x800F4454u: goto label_800F4454;
    case 0x800F4458u: goto label_800F4458;
    case 0x800F445Cu: goto label_800F445C;
    case 0x800F4460u: goto label_800F4460;
    case 0x800F4464u: goto label_800F4464;
    case 0x800F4468u: goto label_800F4468;
    case 0x800F446Cu: goto label_800F446C;
    case 0x800F4470u: goto label_800F4470;
    case 0x800F4474u: goto label_800F4474;
    case 0x800F4478u: goto label_800F4478;
    case 0x800F447Cu: goto label_800F447C;
    case 0x800F4480u: goto label_800F4480;
    case 0x800F4484u: goto label_800F4484;
    case 0x800F4488u: goto label_800F4488;
    case 0x800F448Cu: goto label_800F448C;
    case 0x800F4490u: goto label_800F4490;
    case 0x800F4494u: goto label_800F4494;
    case 0x800F4498u: goto label_800F4498;
    case 0x800F449Cu: goto label_800F449C;
    case 0x800F44A0u: goto label_800F44A0;
    case 0x800F44A4u: goto label_800F44A4;
    case 0x800F44A8u: goto label_800F44A8;
    case 0x800F44ACu: goto label_800F44AC;
    case 0x800F44B0u: goto label_800F44B0;
    case 0x800F44B4u: goto label_800F44B4;
    case 0x800F44B8u: goto label_800F44B8;
    case 0x800F44BCu: goto label_800F44BC;
    case 0x800F44C0u: goto label_800F44C0;
    case 0x800F44C4u: goto label_800F44C4;
    case 0x800F44C8u: goto label_800F44C8;
    case 0x800F44CCu: goto label_800F44CC;
    case 0x800F44D0u: goto label_800F44D0;
    case 0x800F44D4u: goto label_800F44D4;
    case 0x800F44D8u: goto label_800F44D8;
    case 0x800F44DCu: goto label_800F44DC;
    case 0x800F44E0u: goto label_800F44E0;
    case 0x800F44E4u: goto label_800F44E4;
    case 0x800F44E8u: goto label_800F44E8;
    case 0x800F44ECu: goto label_800F44EC;
    case 0x800F44F0u: goto label_800F44F0;
    case 0x800F44F4u: goto label_800F44F4;
    case 0x800F44F8u: goto label_800F44F8;
    case 0x800F44FCu: goto label_800F44FC;
    case 0x800F4500u: goto label_800F4500;
    case 0x800F4504u: goto label_800F4504;
    case 0x800F4508u: goto label_800F4508;
    case 0x800F450Cu: goto label_800F450C;
    case 0x800F4510u: goto label_800F4510;
    case 0x800F4514u: goto label_800F4514;
    case 0x800F4518u: goto label_800F4518;
    case 0x800F451Cu: goto label_800F451C;
    case 0x800F4520u: goto label_800F4520;
    case 0x800F4524u: goto label_800F4524;
    case 0x800F4528u: goto label_800F4528;
    case 0x800F452Cu: goto label_800F452C;
    case 0x800F4530u: goto label_800F4530;
    case 0x800F4534u: goto label_800F4534;
    case 0x800F4538u: goto label_800F4538;
    case 0x800F453Cu: goto label_800F453C;
    case 0x800F4540u: goto label_800F4540;
    case 0x800F4544u: goto label_800F4544;
    case 0x800F4548u: goto label_800F4548;
    case 0x800F454Cu: goto label_800F454C;
    case 0x800F4550u: goto label_800F4550;
    case 0x800F4554u: goto label_800F4554;
    case 0x800F4558u: goto label_800F4558;
    case 0x800F455Cu: goto label_800F455C;
    case 0x800F4560u: goto label_800F4560;
    case 0x800F4564u: goto label_800F4564;
    case 0x800F4568u: goto label_800F4568;
    case 0x800F456Cu: goto label_800F456C;
    case 0x800F4570u: goto label_800F4570;
    case 0x800F4574u: goto label_800F4574;
    case 0x800F4578u: goto label_800F4578;
    case 0x800F457Cu: goto label_800F457C;
    case 0x800F4580u: goto label_800F4580;
    case 0x800F4584u: goto label_800F4584;
    case 0x800F4588u: goto label_800F4588;
    case 0x800F458Cu: goto label_800F458C;
    case 0x800F4590u: goto label_800F4590;
    case 0x800F4594u: goto label_800F4594;
    case 0x800F4598u: goto label_800F4598;
    case 0x800F459Cu: goto label_800F459C;
    case 0x800F45A0u: goto label_800F45A0;
    case 0x800F45A4u: goto label_800F45A4;
    case 0x800F45A8u: goto label_800F45A8;
    case 0x800F45ACu: goto label_800F45AC;
    case 0x800F45B0u: goto label_800F45B0;
    case 0x800F45B4u: goto label_800F45B4;
    case 0x800F45B8u: goto label_800F45B8;
    case 0x800F45BCu: goto label_800F45BC;
    case 0x800F45C0u: goto label_800F45C0;
    case 0x800F45C4u: goto label_800F45C4;
    case 0x800F45C8u: goto label_800F45C8;
    case 0x800F45CCu: goto label_800F45CC;
    case 0x800F45D0u: goto label_800F45D0;
    case 0x800F45D4u: goto label_800F45D4;
    case 0x800F45D8u: goto label_800F45D8;
    case 0x800F45DCu: goto label_800F45DC;
    case 0x800F45E0u: goto label_800F45E0;
    case 0x800F45E4u: goto label_800F45E4;
    case 0x800F45E8u: goto label_800F45E8;
    case 0x800F45ECu: goto label_800F45EC;
    case 0x800F45F0u: goto label_800F45F0;
    case 0x800F45F4u: goto label_800F45F4;
    case 0x800F45F8u: goto label_800F45F8;
    case 0x800F45FCu: goto label_800F45FC;
    case 0x800F4600u: goto label_800F4600;
    case 0x800F4604u: goto label_800F4604;
    case 0x800F4608u: goto label_800F4608;
    case 0x800F460Cu: goto label_800F460C;
    case 0x800F4610u: goto label_800F4610;
    case 0x800F4614u: goto label_800F4614;
    case 0x800F4618u: goto label_800F4618;
    case 0x800F461Cu: goto label_800F461C;
    case 0x800F4620u: goto label_800F4620;
    case 0x800F4624u: goto label_800F4624;
    case 0x800F4628u: goto label_800F4628;
    case 0x800F462Cu: goto label_800F462C;
    case 0x800F4630u: goto label_800F4630;
    case 0x800F4634u: goto label_800F4634;
    case 0x800F4638u: goto label_800F4638;
    case 0x800F463Cu: goto label_800F463C;
    case 0x800F4640u: goto label_800F4640;
    case 0x800F4644u: goto label_800F4644;
    case 0x800F4648u: goto label_800F4648;
    case 0x800F464Cu: goto label_800F464C;
    case 0x800F4650u: goto label_800F4650;
    case 0x800F4654u: goto label_800F4654;
    case 0x800F4658u: goto label_800F4658;
    case 0x800F465Cu: goto label_800F465C;
    case 0x800F4660u: goto label_800F4660;
    case 0x800F4664u: goto label_800F4664;
    case 0x800F4668u: goto label_800F4668;
    case 0x800F466Cu: goto label_800F466C;
    case 0x800F4670u: goto label_800F4670;
    case 0x800F4674u: goto label_800F4674;
    case 0x800F4678u: goto label_800F4678;
    case 0x800F467Cu: goto label_800F467C;
    case 0x800F4680u: goto label_800F4680;
    case 0x800F4684u: goto label_800F4684;
    case 0x800F4688u: goto label_800F4688;
    case 0x800F468Cu: goto label_800F468C;
    case 0x800F4690u: goto label_800F4690;
    case 0x800F4694u: goto label_800F4694;
    case 0x800F4698u: goto label_800F4698;
    case 0x800F469Cu: goto label_800F469C;
    case 0x800F46A0u: goto label_800F46A0;
    case 0x800F46A4u: goto label_800F46A4;
    case 0x800F46A8u: goto label_800F46A8;
    case 0x800F46ACu: goto label_800F46AC;
    case 0x800F46B0u: goto label_800F46B0;
    case 0x800F46B4u: goto label_800F46B4;
    case 0x800F46B8u: goto label_800F46B8;
    case 0x800F46BCu: goto label_800F46BC;
    case 0x800F46C0u: goto label_800F46C0;
    case 0x800F46C4u: goto label_800F46C4;
    case 0x800F46C8u: goto label_800F46C8;
    case 0x800F46CCu: goto label_800F46CC;
    case 0x800F46D0u: goto label_800F46D0;
    case 0x800F46D4u: goto label_800F46D4;
    case 0x800F46D8u: goto label_800F46D8;
    case 0x800F46DCu: goto label_800F46DC;
    case 0x800F46E0u: goto label_800F46E0;
    case 0x800F46E4u: goto label_800F46E4;
    case 0x800F46E8u: goto label_800F46E8;
    case 0x800F46ECu: goto label_800F46EC;
    case 0x800F46F0u: goto label_800F46F0;
    case 0x800F46F4u: goto label_800F46F4;
    case 0x800F46F8u: goto label_800F46F8;
    case 0x800F46FCu: goto label_800F46FC;
    case 0x800F4700u: goto label_800F4700;
    case 0x800F4704u: goto label_800F4704;
    case 0x800F4708u: goto label_800F4708;
    case 0x800F470Cu: goto label_800F470C;
    case 0x800F4710u: goto label_800F4710;
    case 0x800F4714u: goto label_800F4714;
    case 0x800F4718u: goto label_800F4718;
    case 0x800F471Cu: goto label_800F471C;
    case 0x800F4720u: goto label_800F4720;
    case 0x800F4724u: goto label_800F4724;
    case 0x800F4728u: goto label_800F4728;
    case 0x800F472Cu: goto label_800F472C;
    case 0x800F4730u: goto label_800F4730;
    case 0x800F4734u: goto label_800F4734;
    case 0x800F4738u: goto label_800F4738;
    case 0x800F473Cu: goto label_800F473C;
    case 0x800F4740u: goto label_800F4740;
    case 0x800F4744u: goto label_800F4744;
    case 0x800F4748u: goto label_800F4748;
    case 0x800F474Cu: goto label_800F474C;
    case 0x800F4750u: goto label_800F4750;
    case 0x800F4754u: goto label_800F4754;
    case 0x800F4758u: goto label_800F4758;
    case 0x800F475Cu: goto label_800F475C;
    case 0x800F4760u: goto label_800F4760;
    case 0x800F4764u: goto label_800F4764;
    case 0x800F4768u: goto label_800F4768;
    case 0x800F476Cu: goto label_800F476C;
    case 0x800F4770u: goto label_800F4770;
    case 0x800F4774u: goto label_800F4774;
    case 0x800F4778u: goto label_800F4778;
    case 0x800F477Cu: goto label_800F477C;
    case 0x800F4780u: goto label_800F4780;
    case 0x800F4784u: goto label_800F4784;
    case 0x800F4788u: goto label_800F4788;
    case 0x800F478Cu: goto label_800F478C;
    case 0x800F4790u: goto label_800F4790;
    case 0x800F4794u: goto label_800F4794;
    case 0x800F4798u: goto label_800F4798;
    case 0x800F479Cu: goto label_800F479C;
    case 0x800F47A0u: goto label_800F47A0;
    case 0x800F47A4u: goto label_800F47A4;
    case 0x800F47A8u: goto label_800F47A8;
    case 0x800F47ACu: goto label_800F47AC;
    case 0x800F47B0u: goto label_800F47B0;
    case 0x800F47B4u: goto label_800F47B4;
    case 0x800F47B8u: goto label_800F47B8;
    case 0x800F47BCu: goto label_800F47BC;
    case 0x800F47C0u: goto label_800F47C0;
    case 0x800F47C4u: goto label_800F47C4;
    case 0x800F47C8u: goto label_800F47C8;
    case 0x800F47CCu: goto label_800F47CC;
    case 0x800F47D0u: goto label_800F47D0;
    case 0x800F47D4u: goto label_800F47D4;
    case 0x800F47D8u: goto label_800F47D8;
    case 0x800F47DCu: goto label_800F47DC;
    case 0x800F47E0u: goto label_800F47E0;
    case 0x800F47E4u: goto label_800F47E4;
    case 0x800F47E8u: goto label_800F47E8;
    case 0x800F47ECu: goto label_800F47EC;
    case 0x800F47F0u: goto label_800F47F0;
    case 0x800F47F4u: goto label_800F47F4;
    case 0x800F47F8u: goto label_800F47F8;
    case 0x800F47FCu: goto label_800F47FC;
    case 0x800F4800u: goto label_800F4800;
    case 0x800F4804u: goto label_800F4804;
    case 0x800F4808u: goto label_800F4808;
    case 0x800F480Cu: goto label_800F480C;
    case 0x800F4810u: goto label_800F4810;
    case 0x800F4814u: goto label_800F4814;
    case 0x800F4818u: goto label_800F4818;
    case 0x800F481Cu: goto label_800F481C;
    case 0x800F4820u: goto label_800F4820;
    case 0x800F4824u: goto label_800F4824;
    case 0x800F4828u: goto label_800F4828;
    case 0x800F482Cu: goto label_800F482C;
    case 0x800F4830u: goto label_800F4830;
    case 0x800F4834u: goto label_800F4834;
    case 0x800F4838u: goto label_800F4838;
    case 0x800F483Cu: goto label_800F483C;
    case 0x800F4840u: goto label_800F4840;
    case 0x800F4844u: goto label_800F4844;
    case 0x800F4848u: goto label_800F4848;
    case 0x800F484Cu: goto label_800F484C;
    case 0x800F4850u: goto label_800F4850;
    case 0x800F4854u: goto label_800F4854;
    case 0x800F4858u: goto label_800F4858;
    case 0x800F485Cu: goto label_800F485C;
    case 0x800F4860u: goto label_800F4860;
    case 0x800F4864u: goto label_800F4864;
    case 0x800F4868u: goto label_800F4868;
    case 0x800F486Cu: goto label_800F486C;
    case 0x800F4870u: goto label_800F4870;
    case 0x800F4874u: goto label_800F4874;
    case 0x800F4878u: goto label_800F4878;
    case 0x800F487Cu: goto label_800F487C;
    case 0x800F4880u: goto label_800F4880;
    case 0x800F4884u: goto label_800F4884;
    case 0x800F4888u: goto label_800F4888;
    case 0x800F488Cu: goto label_800F488C;
    case 0x800F4890u: goto label_800F4890;
    case 0x800F4894u: goto label_800F4894;
    case 0x800F4898u: goto label_800F4898;
    case 0x800F489Cu: goto label_800F489C;
    case 0x800F48A0u: goto label_800F48A0;
    case 0x800F48A4u: goto label_800F48A4;
    case 0x800F48A8u: goto label_800F48A8;
    case 0x800F48ACu: goto label_800F48AC;
    case 0x800F48B0u: goto label_800F48B0;
    case 0x800F48B4u: goto label_800F48B4;
    case 0x800F48B8u: goto label_800F48B8;
    case 0x800F48BCu: goto label_800F48BC;
    case 0x800F48C0u: goto label_800F48C0;
    case 0x800F48C4u: goto label_800F48C4;
    case 0x800F48C8u: goto label_800F48C8;
    case 0x800F48CCu: goto label_800F48CC;
    case 0x800F48D0u: goto label_800F48D0;
    case 0x800F48D4u: goto label_800F48D4;
    case 0x800F48D8u: goto label_800F48D8;
    case 0x800F48DCu: goto label_800F48DC;
    case 0x800F48E0u: goto label_800F48E0;
    case 0x800F48E4u: goto label_800F48E4;
    case 0x800F48E8u: goto label_800F48E8;
    case 0x800F48ECu: goto label_800F48EC;
    case 0x800F48F0u: goto label_800F48F0;
    case 0x800F48F4u: goto label_800F48F4;
    case 0x800F48F8u: goto label_800F48F8;
    case 0x800F48FCu: goto label_800F48FC;
    case 0x800F4900u: goto label_800F4900;
    case 0x800F4904u: goto label_800F4904;
    case 0x800F4908u: goto label_800F4908;
    case 0x800F490Cu: goto label_800F490C;
    case 0x800F4910u: goto label_800F4910;
    case 0x800F4914u: goto label_800F4914;
    case 0x800F4918u: goto label_800F4918;
    case 0x800F491Cu: goto label_800F491C;
    case 0x800F4920u: goto label_800F4920;
    case 0x800F4924u: goto label_800F4924;
    case 0x800F4928u: goto label_800F4928;
    case 0x800F492Cu: goto label_800F492C;
    case 0x800F4930u: goto label_800F4930;
    case 0x800F4934u: goto label_800F4934;
    case 0x800F4938u: goto label_800F4938;
    case 0x800F493Cu: goto label_800F493C;
    case 0x800F4940u: goto label_800F4940;
    case 0x800F4944u: goto label_800F4944;
    case 0x800F4948u: goto label_800F4948;
    case 0x800F494Cu: goto label_800F494C;
    case 0x800F4950u: goto label_800F4950;
    case 0x800F4954u: goto label_800F4954;
    case 0x800F4958u: goto label_800F4958;
    case 0x800F495Cu: goto label_800F495C;
    case 0x800F4960u: goto label_800F4960;
    case 0x800F4964u: goto label_800F4964;
    case 0x800F4968u: goto label_800F4968;
    case 0x800F496Cu: goto label_800F496C;
    case 0x800F4970u: goto label_800F4970;
    case 0x800F4974u: goto label_800F4974;
    case 0x800F4978u: goto label_800F4978;
    case 0x800F497Cu: goto label_800F497C;
    case 0x800F4980u: goto label_800F4980;
    case 0x800F4984u: goto label_800F4984;
    case 0x800F4988u: goto label_800F4988;
    case 0x800F498Cu: goto label_800F498C;
    case 0x800F4990u: goto label_800F4990;
    case 0x800F4994u: goto label_800F4994;
    case 0x800F4998u: goto label_800F4998;
    case 0x800F499Cu: goto label_800F499C;
    case 0x800F49A0u: goto label_800F49A0;
    case 0x800F49A4u: goto label_800F49A4;
    case 0x800F49A8u: goto label_800F49A8;
    case 0x800F49ACu: goto label_800F49AC;
    case 0x800F49B0u: goto label_800F49B0;
    case 0x800F49B4u: goto label_800F49B4;
    case 0x800F49B8u: goto label_800F49B8;
    case 0x800F49BCu: goto label_800F49BC;
    case 0x800F49C0u: goto label_800F49C0;
    case 0x800F49C4u: goto label_800F49C4;
    case 0x800F49C8u: goto label_800F49C8;
    case 0x800F49CCu: goto label_800F49CC;
    case 0x800F49D0u: goto label_800F49D0;
    case 0x800F49D4u: goto label_800F49D4;
    case 0x800F49D8u: goto label_800F49D8;
    case 0x800F49DCu: goto label_800F49DC;
    case 0x800F49E0u: goto label_800F49E0;
    case 0x800F49E4u: goto label_800F49E4;
    case 0x800F49E8u: goto label_800F49E8;
    case 0x800F49ECu: goto label_800F49EC;
    case 0x800F49F0u: goto label_800F49F0;
    case 0x800F49F4u: goto label_800F49F4;
    case 0x800F49F8u: goto label_800F49F8;
    case 0x800F49FCu: goto label_800F49FC;
    case 0x800F4A00u: goto label_800F4A00;
    case 0x800F4A04u: goto label_800F4A04;
    case 0x800F4A08u: goto label_800F4A08;
    case 0x800F4A0Cu: goto label_800F4A0C;
    case 0x800F4A10u: goto label_800F4A10;
    case 0x800F4A14u: goto label_800F4A14;
    case 0x800F4A18u: goto label_800F4A18;
    case 0x800F4A1Cu: goto label_800F4A1C;
    case 0x800F4A20u: goto label_800F4A20;
    case 0x800F4A24u: goto label_800F4A24;
    case 0x800F4A28u: goto label_800F4A28;
    case 0x800F4A2Cu: goto label_800F4A2C;
    case 0x800F4A30u: goto label_800F4A30;
    case 0x800F4A34u: goto label_800F4A34;
    case 0x800F4A38u: goto label_800F4A38;
    case 0x800F4A3Cu: goto label_800F4A3C;
    case 0x800F4A40u: goto label_800F4A40;
    case 0x800F4A44u: goto label_800F4A44;
    case 0x800F4A48u: goto label_800F4A48;
    case 0x800F4A4Cu: goto label_800F4A4C;
    case 0x800F4A50u: goto label_800F4A50;
    case 0x800F4A54u: goto label_800F4A54;
    case 0x800F4A58u: goto label_800F4A58;
    case 0x800F4A5Cu: goto label_800F4A5C;
    case 0x800F4A60u: goto label_800F4A60;
    case 0x800F4A64u: goto label_800F4A64;
    case 0x800F4A68u: goto label_800F4A68;
    case 0x800F4A6Cu: goto label_800F4A6C;
    case 0x800F4A70u: goto label_800F4A70;
    case 0x800F4A74u: goto label_800F4A74;
    case 0x800F4A78u: goto label_800F4A78;
    case 0x800F4A7Cu: goto label_800F4A7C;
    case 0x800F4A80u: goto label_800F4A80;
    case 0x800F4A84u: goto label_800F4A84;
    case 0x800F4A88u: goto label_800F4A88;
    case 0x800F4A8Cu: goto label_800F4A8C;
    case 0x800F4A90u: goto label_800F4A90;
    case 0x800F4A94u: goto label_800F4A94;
    case 0x800F4A98u: goto label_800F4A98;
    case 0x800F4A9Cu: goto label_800F4A9C;
    case 0x800F4AA0u: goto label_800F4AA0;
    case 0x800F4AA4u: goto label_800F4AA4;
    case 0x800F4AA8u: goto label_800F4AA8;
    case 0x800F4AACu: goto label_800F4AAC;
    case 0x800F4AB0u: goto label_800F4AB0;
    case 0x800F4AB4u: goto label_800F4AB4;
    case 0x800F4AB8u: goto label_800F4AB8;
    case 0x800F4ABCu: goto label_800F4ABC;
    case 0x800F4AC0u: goto label_800F4AC0;
    case 0x800F4AC4u: goto label_800F4AC4;
    case 0x800F4AC8u: goto label_800F4AC8;
    case 0x800F4ACCu: goto label_800F4ACC;
    case 0x800F4AD0u: goto label_800F4AD0;
    case 0x800F4AD4u: goto label_800F4AD4;
    case 0x800F4AD8u: goto label_800F4AD8;
    case 0x800F4ADCu: goto label_800F4ADC;
    case 0x800F4AE0u: goto label_800F4AE0;
    case 0x800F4AE4u: goto label_800F4AE4;
    case 0x800F4AE8u: goto label_800F4AE8;
    case 0x800F4AECu: goto label_800F4AEC;
    case 0x800F4AF0u: goto label_800F4AF0;
    case 0x800F4AF4u: goto label_800F4AF4;
    case 0x800F4AF8u: goto label_800F4AF8;
    case 0x800F4AFCu: goto label_800F4AFC;
    case 0x800F4B00u: goto label_800F4B00;
    case 0x800F4B04u: goto label_800F4B04;
    case 0x800F4B08u: goto label_800F4B08;
    case 0x800F4B0Cu: goto label_800F4B0C;
    case 0x800F4B10u: goto label_800F4B10;
    case 0x800F4B14u: goto label_800F4B14;
    case 0x800F4B18u: goto label_800F4B18;
    case 0x800F4B1Cu: goto label_800F4B1C;
    case 0x800F4B20u: goto label_800F4B20;
    case 0x800F4B24u: goto label_800F4B24;
    case 0x800F4B28u: goto label_800F4B28;
    case 0x800F4B2Cu: goto label_800F4B2C;
    case 0x800F4B30u: goto label_800F4B30;
    case 0x800F4B34u: goto label_800F4B34;
    case 0x800F4B38u: goto label_800F4B38;
    case 0x800F4B3Cu: goto label_800F4B3C;
    case 0x800F4B40u: goto label_800F4B40;
    case 0x800F4B44u: goto label_800F4B44;
    case 0x800F4B48u: goto label_800F4B48;
    case 0x800F4B4Cu: goto label_800F4B4C;
    case 0x800F4B50u: goto label_800F4B50;
    case 0x800F4B54u: goto label_800F4B54;
    case 0x800F4B58u: goto label_800F4B58;
    case 0x800F4B5Cu: goto label_800F4B5C;
    case 0x800F4B60u: goto label_800F4B60;
    case 0x800F4B64u: goto label_800F4B64;
    case 0x800F4B68u: goto label_800F4B68;
    case 0x800F4B6Cu: goto label_800F4B6C;
    case 0x800F4B70u: goto label_800F4B70;
    case 0x800F4B74u: goto label_800F4B74;
    case 0x800F4B78u: goto label_800F4B78;
    case 0x800F4B7Cu: goto label_800F4B7C;
    case 0x800F4B80u: goto label_800F4B80;
    case 0x800F4B84u: goto label_800F4B84;
    case 0x800F4B88u: goto label_800F4B88;
    case 0x800F4B8Cu: goto label_800F4B8C;
    case 0x800F4B90u: goto label_800F4B90;
    case 0x800F4B94u: goto label_800F4B94;
    case 0x800F4B98u: goto label_800F4B98;
    case 0x800F4B9Cu: goto label_800F4B9C;
    case 0x800F4BA0u: goto label_800F4BA0;
    case 0x800F4BA4u: goto label_800F4BA4;
    case 0x800F4BA8u: goto label_800F4BA8;
    case 0x800F4BACu: goto label_800F4BAC;
    case 0x800F4BB0u: goto label_800F4BB0;
    case 0x800F4BB4u: goto label_800F4BB4;
    case 0x800F4BB8u: goto label_800F4BB8;
    case 0x800F4BBCu: goto label_800F4BBC;
    case 0x800F4BC0u: goto label_800F4BC0;
    case 0x800F4BC4u: goto label_800F4BC4;
    case 0x800F4BC8u: goto label_800F4BC8;
    case 0x800F4BCCu: goto label_800F4BCC;
    case 0x800F4BD0u: goto label_800F4BD0;
    case 0x800F4BD4u: goto label_800F4BD4;
    case 0x800F4BD8u: goto label_800F4BD8;
    case 0x800F4BDCu: goto label_800F4BDC;
    case 0x800F4BE0u: goto label_800F4BE0;
    case 0x800F4BE4u: goto label_800F4BE4;
    case 0x800F4BE8u: goto label_800F4BE8;
    case 0x800F4BECu: goto label_800F4BEC;
    case 0x800F4BF0u: goto label_800F4BF0;
    case 0x800F4BF4u: goto label_800F4BF4;
    case 0x800F4BF8u: goto label_800F4BF8;
    case 0x800F4BFCu: goto label_800F4BFC;
    case 0x800F4C00u: goto label_800F4C00;
    case 0x800F4C04u: goto label_800F4C04;
    case 0x800F4C08u: goto label_800F4C08;
    case 0x800F4C0Cu: goto label_800F4C0C;
    case 0x800F4C10u: goto label_800F4C10;
    case 0x800F4C14u: goto label_800F4C14;
    case 0x800F4C18u: goto label_800F4C18;
    case 0x800F4C1Cu: goto label_800F4C1C;
    case 0x800F4C20u: goto label_800F4C20;
    case 0x800F4C24u: goto label_800F4C24;
    case 0x800F4C28u: goto label_800F4C28;
    case 0x800F4C2Cu: goto label_800F4C2C;
    case 0x800F4C30u: goto label_800F4C30;
    case 0x800F4C34u: goto label_800F4C34;
    case 0x800F4C38u: goto label_800F4C38;
    case 0x800F4C3Cu: goto label_800F4C3C;
    case 0x800F4C40u: goto label_800F4C40;
    case 0x800F4C44u: goto label_800F4C44;
    case 0x800F4C48u: goto label_800F4C48;
    case 0x800F4C4Cu: goto label_800F4C4C;
    case 0x800F4C50u: goto label_800F4C50;
    case 0x800F4C54u: goto label_800F4C54;
    case 0x800F4C58u: goto label_800F4C58;
    case 0x800F4C5Cu: goto label_800F4C5C;
    case 0x800F4C60u: goto label_800F4C60;
    case 0x800F4C64u: goto label_800F4C64;
    case 0x800F4C68u: goto label_800F4C68;
    case 0x800F4C6Cu: goto label_800F4C6C;
    case 0x800F4C70u: goto label_800F4C70;
    case 0x800F4C74u: goto label_800F4C74;
    case 0x800F4C78u: goto label_800F4C78;
    case 0x800F4C7Cu: goto label_800F4C7C;
    case 0x800F4C80u: goto label_800F4C80;
    case 0x800F4C84u: goto label_800F4C84;
    case 0x800F4C88u: goto label_800F4C88;
    case 0x800F4C8Cu: goto label_800F4C8C;
    case 0x800F4C90u: goto label_800F4C90;
    case 0x800F4C94u: goto label_800F4C94;
    case 0x800F4C98u: goto label_800F4C98;
    case 0x800F4C9Cu: goto label_800F4C9C;
    case 0x800F4CA0u: goto label_800F4CA0;
    case 0x800F4CA4u: goto label_800F4CA4;
    case 0x800F4CA8u: goto label_800F4CA8;
    case 0x800F4CACu: goto label_800F4CAC;
    case 0x800F4CB0u: goto label_800F4CB0;
    case 0x800F4CB4u: goto label_800F4CB4;
    case 0x800F4CB8u: goto label_800F4CB8;
    case 0x800F4CBCu: goto label_800F4CBC;
    case 0x800F4CC0u: goto label_800F4CC0;
    case 0x800F4CC4u: goto label_800F4CC4;
    case 0x800F4CC8u: goto label_800F4CC8;
    case 0x800F4CCCu: goto label_800F4CCC;
    case 0x800F4CD0u: goto label_800F4CD0;
    case 0x800F4CD4u: goto label_800F4CD4;
    case 0x800F4CD8u: goto label_800F4CD8;
    case 0x800F4CDCu: goto label_800F4CDC;
    case 0x800F4CE0u: goto label_800F4CE0;
    case 0x800F4CE4u: goto label_800F4CE4;
    case 0x800F4CE8u: goto label_800F4CE8;
    case 0x800F4CECu: goto label_800F4CEC;
    case 0x800F4CF0u: goto label_800F4CF0;
    case 0x800F4CF4u: goto label_800F4CF4;
    case 0x800F4CF8u: goto label_800F4CF8;
    case 0x800F4CFCu: goto label_800F4CFC;
    case 0x800F4D00u: goto label_800F4D00;
    case 0x800F4D04u: goto label_800F4D04;
    case 0x800F4D08u: goto label_800F4D08;
    case 0x800F4D0Cu: goto label_800F4D0C;
    case 0x800F4D10u: goto label_800F4D10;
    case 0x800F4D14u: goto label_800F4D14;
    case 0x800F4D18u: goto label_800F4D18;
    case 0x800F4D1Cu: goto label_800F4D1C;
    case 0x800F4D20u: goto label_800F4D20;
    case 0x800F4D24u: goto label_800F4D24;
    case 0x800F4D28u: goto label_800F4D28;
    case 0x800F4D2Cu: goto label_800F4D2C;
    case 0x800F4D30u: goto label_800F4D30;
    case 0x800F4D34u: goto label_800F4D34;
    case 0x800F4D38u: goto label_800F4D38;
    case 0x800F4D3Cu: goto label_800F4D3C;
    case 0x800F4D40u: goto label_800F4D40;
    case 0x800F4D44u: goto label_800F4D44;
    case 0x800F4D48u: goto label_800F4D48;
    case 0x800F4D4Cu: goto label_800F4D4C;
    case 0x800F4D50u: goto label_800F4D50;
    case 0x800F4D54u: goto label_800F4D54;
    case 0x800F4D58u: goto label_800F4D58;
    case 0x800F4D5Cu: goto label_800F4D5C;
    case 0x800F4D60u: goto label_800F4D60;
    case 0x800F4D64u: goto label_800F4D64;
    case 0x800F4D68u: goto label_800F4D68;
    case 0x800F4D6Cu: goto label_800F4D6C;
    case 0x800F4D70u: goto label_800F4D70;
    case 0x800F4D74u: goto label_800F4D74;
    case 0x800F4D78u: goto label_800F4D78;
    case 0x800F4D7Cu: goto label_800F4D7C;
    case 0x800F4D80u: goto label_800F4D80;
    case 0x800F4D84u: goto label_800F4D84;
    case 0x800F4D88u: goto label_800F4D88;
    case 0x800F4D8Cu: goto label_800F4D8C;
    case 0x800F4D90u: goto label_800F4D90;
    case 0x800F4D94u: goto label_800F4D94;
    case 0x800F4D98u: goto label_800F4D98;
    case 0x800F4D9Cu: goto label_800F4D9C;
    case 0x800F4DA0u: goto label_800F4DA0;
    case 0x800F4DA4u: goto label_800F4DA4;
    case 0x800F4DA8u: goto label_800F4DA8;
    case 0x800F4DACu: goto label_800F4DAC;
    case 0x800F4DB0u: goto label_800F4DB0;
    case 0x800F4DB4u: goto label_800F4DB4;
    case 0x800F4DB8u: goto label_800F4DB8;
    case 0x800F4DBCu: goto label_800F4DBC;
    case 0x800F4DC0u: goto label_800F4DC0;
    case 0x800F4DC4u: goto label_800F4DC4;
    case 0x800F4DC8u: goto label_800F4DC8;
    case 0x800F4DCCu: goto label_800F4DCC;
    case 0x800F4DD0u: goto label_800F4DD0;
    case 0x800F4DD4u: goto label_800F4DD4;
    case 0x800F4DD8u: goto label_800F4DD8;
    case 0x800F4DDCu: goto label_800F4DDC;
    case 0x800F4DE0u: goto label_800F4DE0;
    case 0x800F4DE4u: goto label_800F4DE4;
    case 0x800F4DE8u: goto label_800F4DE8;
    case 0x800F4DECu: goto label_800F4DEC;
    case 0x800F4DF0u: goto label_800F4DF0;
    case 0x800F4DF4u: goto label_800F4DF4;
    case 0x800F4DF8u: goto label_800F4DF8;
    case 0x800F4DFCu: goto label_800F4DFC;
    case 0x800F4E00u: goto label_800F4E00;
    case 0x800F4E04u: goto label_800F4E04;
    case 0x800F4E08u: goto label_800F4E08;
    case 0x800F4E0Cu: goto label_800F4E0C;
    case 0x800F4E10u: goto label_800F4E10;
    case 0x800F4E14u: goto label_800F4E14;
    case 0x800F4E18u: goto label_800F4E18;
    case 0x800F4E1Cu: goto label_800F4E1C;
    case 0x800F4E20u: goto label_800F4E20;
    case 0x800F4E24u: goto label_800F4E24;
    case 0x800F4E28u: goto label_800F4E28;
    case 0x800F4E2Cu: goto label_800F4E2C;
    case 0x800F4E30u: goto label_800F4E30;
    case 0x800F4E34u: goto label_800F4E34;
    case 0x800F4E38u: goto label_800F4E38;
    case 0x800F4E3Cu: goto label_800F4E3C;
    case 0x800F4E40u: goto label_800F4E40;
    case 0x800F4E44u: goto label_800F4E44;
    case 0x800F4E48u: goto label_800F4E48;
    case 0x800F4E4Cu: goto label_800F4E4C;
    case 0x800F4E50u: goto label_800F4E50;
    case 0x800F4E54u: goto label_800F4E54;
    case 0x800F4E58u: goto label_800F4E58;
    case 0x800F4E5Cu: goto label_800F4E5C;
    case 0x800F4E60u: goto label_800F4E60;
    case 0x800F4E64u: goto label_800F4E64;
    case 0x800F4E68u: goto label_800F4E68;
    case 0x800F4E6Cu: goto label_800F4E6C;
    case 0x800F4E70u: goto label_800F4E70;
    case 0x800F4E74u: goto label_800F4E74;
    case 0x800F4E78u: goto label_800F4E78;
    case 0x800F4E7Cu: goto label_800F4E7C;
    case 0x800F4E80u: goto label_800F4E80;
    case 0x800F4E84u: goto label_800F4E84;
    case 0x800F4E88u: goto label_800F4E88;
    case 0x800F4E8Cu: goto label_800F4E8C;
    case 0x800F4E90u: goto label_800F4E90;
    case 0x800F4E94u: goto label_800F4E94;
    case 0x800F4E98u: goto label_800F4E98;
    case 0x800F4E9Cu: goto label_800F4E9C;
    case 0x800F4EA0u: goto label_800F4EA0;
    case 0x800F4EA4u: goto label_800F4EA4;
    case 0x800F4EA8u: goto label_800F4EA8;
    case 0x800F4EACu: goto label_800F4EAC;
    case 0x800F4EB0u: goto label_800F4EB0;
    case 0x800F4EB4u: goto label_800F4EB4;
    case 0x800F4EB8u: goto label_800F4EB8;
    case 0x800F4EBCu: goto label_800F4EBC;
    case 0x800F4EC0u: goto label_800F4EC0;
    case 0x800F4EC4u: goto label_800F4EC4;
    case 0x800F4EC8u: goto label_800F4EC8;
    case 0x800F4ECCu: goto label_800F4ECC;
    case 0x800F4ED0u: goto label_800F4ED0;
    case 0x800F4ED4u: goto label_800F4ED4;
    case 0x800F4ED8u: goto label_800F4ED8;
    case 0x800F4EDCu: goto label_800F4EDC;
    case 0x800F4EE0u: goto label_800F4EE0;
    case 0x800F4EE4u: goto label_800F4EE4;
    case 0x800F4EE8u: goto label_800F4EE8;
    case 0x800F4EECu: goto label_800F4EEC;
    case 0x800F4EF0u: goto label_800F4EF0;
    case 0x800F4EF4u: goto label_800F4EF4;
    case 0x800F4EF8u: goto label_800F4EF8;
    case 0x800F4EFCu: goto label_800F4EFC;
    case 0x800F4F00u: goto label_800F4F00;
    case 0x800F4F04u: goto label_800F4F04;
    case 0x800F4F08u: goto label_800F4F08;
    case 0x800F4F0Cu: goto label_800F4F0C;
    case 0x800F4F10u: goto label_800F4F10;
    case 0x800F4F14u: goto label_800F4F14;
    case 0x800F4F18u: goto label_800F4F18;
    case 0x800F4F1Cu: goto label_800F4F1C;
    case 0x800F4F20u: goto label_800F4F20;
    case 0x800F4F24u: goto label_800F4F24;
    case 0x800F4F28u: goto label_800F4F28;
    case 0x800F4F2Cu: goto label_800F4F2C;
    case 0x800F4F30u: goto label_800F4F30;
    case 0x800F4F34u: goto label_800F4F34;
    case 0x800F4F38u: goto label_800F4F38;
    case 0x800F4F3Cu: goto label_800F4F3C;
    case 0x800F4F40u: goto label_800F4F40;
    case 0x800F4F44u: goto label_800F4F44;
    case 0x800F4F48u: goto label_800F4F48;
    case 0x800F4F4Cu: goto label_800F4F4C;
    case 0x800F4F50u: goto label_800F4F50;
    case 0x800F4F54u: goto label_800F4F54;
    case 0x800F4F58u: goto label_800F4F58;
    case 0x800F4F5Cu: goto label_800F4F5C;
    case 0x800F4F60u: goto label_800F4F60;
    case 0x800F4F64u: goto label_800F4F64;
    case 0x800F4F68u: goto label_800F4F68;
    case 0x800F4F6Cu: goto label_800F4F6C;
    case 0x800F4F70u: goto label_800F4F70;
    case 0x800F4F74u: goto label_800F4F74;
    case 0x800F4F78u: goto label_800F4F78;
    case 0x800F4F7Cu: goto label_800F4F7C;
    case 0x800F4F80u: goto label_800F4F80;
    case 0x800F4F84u: goto label_800F4F84;
    case 0x800F4F88u: goto label_800F4F88;
    case 0x800F4F8Cu: goto label_800F4F8C;
    case 0x800F4F90u: goto label_800F4F90;
    case 0x800F4F94u: goto label_800F4F94;
    case 0x800F4F98u: goto label_800F4F98;
    case 0x800F4F9Cu: goto label_800F4F9C;
    case 0x800F4FA0u: goto label_800F4FA0;
    case 0x800F4FA4u: goto label_800F4FA4;
    case 0x800F4FA8u: goto label_800F4FA8;
    case 0x800F4FACu: goto label_800F4FAC;
    case 0x800F4FB0u: goto label_800F4FB0;
    case 0x800F4FB4u: goto label_800F4FB4;
    case 0x800F4FB8u: goto label_800F4FB8;
    case 0x800F4FBCu: goto label_800F4FBC;
    case 0x800F4FC0u: goto label_800F4FC0;
    case 0x800F4FC4u: goto label_800F4FC4;
    case 0x800F4FC8u: goto label_800F4FC8;
    case 0x800F4FCCu: goto label_800F4FCC;
    case 0x800F4FD0u: goto label_800F4FD0;
    case 0x800F4FD4u: goto label_800F4FD4;
    case 0x800F4FD8u: goto label_800F4FD8;
    case 0x800F4FDCu: goto label_800F4FDC;
    case 0x800F4FE0u: goto label_800F4FE0;
    case 0x800F4FE4u: goto label_800F4FE4;
    case 0x800F4FE8u: goto label_800F4FE8;
    case 0x800F4FECu: goto label_800F4FEC;
    case 0x800F4FF0u: goto label_800F4FF0;
    case 0x800F4FF4u: goto label_800F4FF4;
    case 0x800F4FF8u: goto label_800F4FF8;
    case 0x800F4FFCu: goto label_800F4FFC;
    case 0x800F5000u: goto label_800F5000;
    case 0x800F5004u: goto label_800F5004;
    case 0x800F5008u: goto label_800F5008;
    case 0x800F500Cu: goto label_800F500C;
    case 0x800F5010u: goto label_800F5010;
    case 0x800F5014u: goto label_800F5014;
    case 0x800F5018u: goto label_800F5018;
    case 0x800F501Cu: goto label_800F501C;
    case 0x800F5020u: goto label_800F5020;
    case 0x800F5024u: goto label_800F5024;
    case 0x800F5028u: goto label_800F5028;
    case 0x800F502Cu: goto label_800F502C;
    case 0x800F5030u: goto label_800F5030;
    case 0x800F5034u: goto label_800F5034;
    case 0x800F5038u: goto label_800F5038;
    case 0x800F503Cu: goto label_800F503C;
    case 0x800F5040u: goto label_800F5040;
    case 0x800F5044u: goto label_800F5044;
    case 0x800F5048u: goto label_800F5048;
    case 0x800F504Cu: goto label_800F504C;
    case 0x800F5050u: goto label_800F5050;
    case 0x800F5054u: goto label_800F5054;
    case 0x800F5058u: goto label_800F5058;
    case 0x800F505Cu: goto label_800F505C;
    case 0x800F5060u: goto label_800F5060;
    case 0x800F5064u: goto label_800F5064;
    case 0x800F5068u: goto label_800F5068;
    case 0x800F506Cu: goto label_800F506C;
    case 0x800F5070u: goto label_800F5070;
    case 0x800F5074u: goto label_800F5074;
    case 0x800F5078u: goto label_800F5078;
    case 0x800F507Cu: goto label_800F507C;
    case 0x800F5080u: goto label_800F5080;
    case 0x800F5084u: goto label_800F5084;
    case 0x800F5088u: goto label_800F5088;
    case 0x800F508Cu: goto label_800F508C;
    case 0x800F5090u: goto label_800F5090;
    case 0x800F5094u: goto label_800F5094;
    case 0x800F5098u: goto label_800F5098;
    case 0x800F509Cu: goto label_800F509C;
    case 0x800F50A0u: goto label_800F50A0;
    case 0x800F50A4u: goto label_800F50A4;
    case 0x800F50A8u: goto label_800F50A8;
    case 0x800F50ACu: goto label_800F50AC;
    case 0x800F50B0u: goto label_800F50B0;
    case 0x800F50B4u: goto label_800F50B4;
    case 0x800F50B8u: goto label_800F50B8;
    case 0x800F50BCu: goto label_800F50BC;
    case 0x800F50C0u: goto label_800F50C0;
    case 0x800F50C4u: goto label_800F50C4;
    case 0x800F50C8u: goto label_800F50C8;
    case 0x800F50CCu: goto label_800F50CC;
    case 0x800F50D0u: goto label_800F50D0;
    case 0x800F50D4u: goto label_800F50D4;
    case 0x800F50D8u: goto label_800F50D8;
    case 0x800F50DCu: goto label_800F50DC;
    case 0x800F50E0u: goto label_800F50E0;
    case 0x800F50E4u: goto label_800F50E4;
    case 0x800F50E8u: goto label_800F50E8;
    case 0x800F50ECu: goto label_800F50EC;
    case 0x800F50F0u: goto label_800F50F0;
    case 0x800F50F4u: goto label_800F50F4;
    case 0x800F50F8u: goto label_800F50F8;
    case 0x800F50FCu: goto label_800F50FC;
    case 0x800F5100u: goto label_800F5100;
    case 0x800F5104u: goto label_800F5104;
    case 0x800F5108u: goto label_800F5108;
    case 0x800F510Cu: goto label_800F510C;
    case 0x800F5110u: goto label_800F5110;
    case 0x800F5114u: goto label_800F5114;
    case 0x800F5118u: goto label_800F5118;
    case 0x800F511Cu: goto label_800F511C;
    case 0x800F5120u: goto label_800F5120;
    case 0x800F5124u: goto label_800F5124;
    case 0x800F5128u: goto label_800F5128;
    case 0x800F512Cu: goto label_800F512C;
    case 0x800F5130u: goto label_800F5130;
    case 0x800F5134u: goto label_800F5134;
    case 0x800F5138u: goto label_800F5138;
    case 0x800F513Cu: goto label_800F513C;
    case 0x800F5140u: goto label_800F5140;
    case 0x800F5144u: goto label_800F5144;
    case 0x800F5148u: goto label_800F5148;
    case 0x800F514Cu: goto label_800F514C;
    case 0x800F5150u: goto label_800F5150;
    case 0x800F5154u: goto label_800F5154;
    case 0x800F5158u: goto label_800F5158;
    case 0x800F515Cu: goto label_800F515C;
    case 0x800F5160u: goto label_800F5160;
    case 0x800F5164u: goto label_800F5164;
    case 0x800F5168u: goto label_800F5168;
    case 0x800F516Cu: goto label_800F516C;
    case 0x800F5170u: goto label_800F5170;
    case 0x800F5174u: goto label_800F5174;
    case 0x800F5178u: goto label_800F5178;
    case 0x800F517Cu: goto label_800F517C;
    case 0x800F5180u: goto label_800F5180;
    case 0x800F5184u: goto label_800F5184;
    case 0x800F5188u: goto label_800F5188;
    case 0x800F518Cu: goto label_800F518C;
    case 0x800F5190u: goto label_800F5190;
    case 0x800F5194u: goto label_800F5194;
    case 0x800F5198u: goto label_800F5198;
    case 0x800F519Cu: goto label_800F519C;
    case 0x800F51A0u: goto label_800F51A0;
    case 0x800F51A4u: goto label_800F51A4;
    case 0x800F51A8u: goto label_800F51A8;
    case 0x800F51ACu: goto label_800F51AC;
    case 0x800F51B0u: goto label_800F51B0;
    case 0x800F51B4u: goto label_800F51B4;
    case 0x800F51B8u: goto label_800F51B8;
    case 0x800F51BCu: goto label_800F51BC;
    case 0x800F51C0u: goto label_800F51C0;
    case 0x800F51C4u: goto label_800F51C4;
    case 0x800F51C8u: goto label_800F51C8;
    case 0x800F51CCu: goto label_800F51CC;
    case 0x800F51D0u: goto label_800F51D0;
    case 0x800F51D4u: goto label_800F51D4;
    case 0x800F51D8u: goto label_800F51D8;
    case 0x800F51DCu: goto label_800F51DC;
    case 0x800F51E0u: goto label_800F51E0;
    case 0x800F51E4u: goto label_800F51E4;
    case 0x800F51E8u: goto label_800F51E8;
    case 0x800F51ECu: goto label_800F51EC;
    case 0x800F51F0u: goto label_800F51F0;
    case 0x800F51F4u: goto label_800F51F4;
    case 0x800F51F8u: goto label_800F51F8;
    case 0x800F51FCu: goto label_800F51FC;
    case 0x800F5200u: goto label_800F5200;
    case 0x800F5204u: goto label_800F5204;
    case 0x800F5208u: goto label_800F5208;
    case 0x800F520Cu: goto label_800F520C;
    case 0x800F5210u: goto label_800F5210;
    case 0x800F5214u: goto label_800F5214;
    case 0x800F5218u: goto label_800F5218;
    case 0x800F521Cu: goto label_800F521C;
    case 0x800F5220u: goto label_800F5220;
    case 0x800F5224u: goto label_800F5224;
    case 0x800F5228u: goto label_800F5228;
    case 0x800F522Cu: goto label_800F522C;
    case 0x800F5230u: goto label_800F5230;
    case 0x800F5234u: goto label_800F5234;
    case 0x800F5238u: goto label_800F5238;
    case 0x800F523Cu: goto label_800F523C;
    case 0x800F5240u: goto label_800F5240;
    case 0x800F5244u: goto label_800F5244;
    case 0x800F5248u: goto label_800F5248;
    case 0x800F524Cu: goto label_800F524C;
    case 0x800F5250u: goto label_800F5250;
    case 0x800F5254u: goto label_800F5254;
    case 0x800F5258u: goto label_800F5258;
    case 0x800F525Cu: goto label_800F525C;
    case 0x800F5260u: goto label_800F5260;
    case 0x800F5264u: goto label_800F5264;
    case 0x800F5268u: goto label_800F5268;
    case 0x800F526Cu: goto label_800F526C;
    case 0x800F5270u: goto label_800F5270;
    case 0x800F5274u: goto label_800F5274;
    case 0x800F5278u: goto label_800F5278;
    case 0x800F527Cu: goto label_800F527C;
    case 0x800F5280u: goto label_800F5280;
    case 0x800F5284u: goto label_800F5284;
    case 0x800F5288u: goto label_800F5288;
    case 0x800F528Cu: goto label_800F528C;
    case 0x800F5290u: goto label_800F5290;
    case 0x800F5294u: goto label_800F5294;
    case 0x800F5298u: goto label_800F5298;
    case 0x800F529Cu: goto label_800F529C;
    case 0x800F52A0u: goto label_800F52A0;
    case 0x800F52A4u: goto label_800F52A4;
    case 0x800F52A8u: goto label_800F52A8;
    case 0x800F52ACu: goto label_800F52AC;
    case 0x800F52B0u: goto label_800F52B0;
    case 0x800F52B4u: goto label_800F52B4;
    case 0x800F52B8u: goto label_800F52B8;
    case 0x800F52BCu: goto label_800F52BC;
    case 0x800F52C0u: goto label_800F52C0;
    case 0x800F52C4u: goto label_800F52C4;
    case 0x800F52C8u: goto label_800F52C8;
    case 0x800F52CCu: goto label_800F52CC;
    case 0x800F52D0u: goto label_800F52D0;
    case 0x800F52D4u: goto label_800F52D4;
    case 0x800F52D8u: goto label_800F52D8;
    case 0x800F52DCu: goto label_800F52DC;
    case 0x800F52E0u: goto label_800F52E0;
    case 0x800F52E4u: goto label_800F52E4;
    case 0x800F52E8u: goto label_800F52E8;
    case 0x800F52ECu: goto label_800F52EC;
    case 0x800F52F0u: goto label_800F52F0;
    case 0x800F52F4u: goto label_800F52F4;
    case 0x800F52F8u: goto label_800F52F8;
    case 0x800F52FCu: goto label_800F52FC;
    case 0x800F5300u: goto label_800F5300;
    case 0x800F5304u: goto label_800F5304;
    case 0x800F5308u: goto label_800F5308;
    case 0x800F530Cu: goto label_800F530C;
    case 0x800F5310u: goto label_800F5310;
    case 0x800F5314u: goto label_800F5314;
    case 0x800F5318u: goto label_800F5318;
    case 0x800F531Cu: goto label_800F531C;
    case 0x800F5320u: goto label_800F5320;
    case 0x800F5324u: goto label_800F5324;
    case 0x800F5328u: goto label_800F5328;
    case 0x800F532Cu: goto label_800F532C;
    case 0x800F5330u: goto label_800F5330;
    case 0x800F5334u: goto label_800F5334;
    case 0x800F5338u: goto label_800F5338;
    case 0x800F533Cu: goto label_800F533C;
    case 0x800F5340u: goto label_800F5340;
    case 0x800F5344u: goto label_800F5344;
    case 0x800F5348u: goto label_800F5348;
    case 0x800F534Cu: goto label_800F534C;
    case 0x800F5350u: goto label_800F5350;
    case 0x800F5354u: goto label_800F5354;
    case 0x800F5358u: goto label_800F5358;
    case 0x800F535Cu: goto label_800F535C;
    case 0x800F5360u: goto label_800F5360;
    case 0x800F5364u: goto label_800F5364;
    case 0x800F5368u: goto label_800F5368;
    case 0x800F536Cu: goto label_800F536C;
    case 0x800F5370u: goto label_800F5370;
    case 0x800F5374u: goto label_800F5374;
    case 0x800F5378u: goto label_800F5378;
    case 0x800F537Cu: goto label_800F537C;
    case 0x800F5380u: goto label_800F5380;
    case 0x800F5384u: goto label_800F5384;
    case 0x800F5388u: goto label_800F5388;
    case 0x800F538Cu: goto label_800F538C;
    case 0x800F5390u: goto label_800F5390;
    case 0x800F5394u: goto label_800F5394;
    case 0x800F5398u: goto label_800F5398;
    case 0x800F539Cu: goto label_800F539C;
    case 0x800F53A0u: goto label_800F53A0;
    case 0x800F53A4u: goto label_800F53A4;
    case 0x800F53A8u: goto label_800F53A8;
    case 0x800F53ACu: goto label_800F53AC;
    case 0x800F53B0u: goto label_800F53B0;
    case 0x800F53B4u: goto label_800F53B4;
    case 0x800F53B8u: goto label_800F53B8;
    case 0x800F53BCu: goto label_800F53BC;
    case 0x800F53C0u: goto label_800F53C0;
    case 0x800F53C4u: goto label_800F53C4;
    case 0x800F53C8u: goto label_800F53C8;
    case 0x800F53CCu: goto label_800F53CC;
    case 0x800F53D0u: goto label_800F53D0;
    case 0x800F53D4u: goto label_800F53D4;
    case 0x800F53D8u: goto label_800F53D8;
    case 0x800F53DCu: goto label_800F53DC;
    case 0x800F53E0u: goto label_800F53E0;
    case 0x800F53E4u: goto label_800F53E4;
    case 0x800F53E8u: goto label_800F53E8;
    case 0x800F53ECu: goto label_800F53EC;
    case 0x800F53F0u: goto label_800F53F0;
    case 0x800F53F4u: goto label_800F53F4;
    case 0x800F53F8u: goto label_800F53F8;
    case 0x800F53FCu: goto label_800F53FC;
    case 0x800F5400u: goto label_800F5400;
    case 0x800F5404u: goto label_800F5404;
    case 0x800F5408u: goto label_800F5408;
    case 0x800F540Cu: goto label_800F540C;
    case 0x800F5410u: goto label_800F5410;
    case 0x800F5414u: goto label_800F5414;
    case 0x800F5418u: goto label_800F5418;
    case 0x800F541Cu: goto label_800F541C;
    case 0x800F5420u: goto label_800F5420;
    case 0x800F5424u: goto label_800F5424;
    case 0x800F5428u: goto label_800F5428;
    case 0x800F542Cu: goto label_800F542C;
    case 0x800F5430u: goto label_800F5430;
    case 0x800F5434u: goto label_800F5434;
    case 0x800F5438u: goto label_800F5438;
    case 0x800F543Cu: goto label_800F543C;
    case 0x800F5440u: goto label_800F5440;
    case 0x800F5444u: goto label_800F5444;
    case 0x800F5448u: goto label_800F5448;
    case 0x800F544Cu: goto label_800F544C;
    case 0x800F5450u: goto label_800F5450;
    case 0x800F5454u: goto label_800F5454;
    case 0x800F5458u: goto label_800F5458;
    case 0x800F545Cu: goto label_800F545C;
    case 0x800F5460u: goto label_800F5460;
    case 0x800F5464u: goto label_800F5464;
    case 0x800F5468u: goto label_800F5468;
    case 0x800F546Cu: goto label_800F546C;
    case 0x800F5470u: goto label_800F5470;
    case 0x800F5474u: goto label_800F5474;
    case 0x800F5478u: goto label_800F5478;
    case 0x800F547Cu: goto label_800F547C;
    case 0x800F5480u: goto label_800F5480;
    case 0x800F5484u: goto label_800F5484;
    case 0x800F5488u: goto label_800F5488;
    case 0x800F548Cu: goto label_800F548C;
    case 0x800F5490u: goto label_800F5490;
    case 0x800F5494u: goto label_800F5494;
    case 0x800F5498u: goto label_800F5498;
    case 0x800F549Cu: goto label_800F549C;
    case 0x800F54A0u: goto label_800F54A0;
    case 0x800F54A4u: goto label_800F54A4;
    case 0x800F54A8u: goto label_800F54A8;
    case 0x800F54ACu: goto label_800F54AC;
    case 0x800F54B0u: goto label_800F54B0;
    case 0x800F54B4u: goto label_800F54B4;
    case 0x800F54B8u: goto label_800F54B8;
    case 0x800F54BCu: goto label_800F54BC;
    case 0x800F54C0u: goto label_800F54C0;
    case 0x800F54C4u: goto label_800F54C4;
    case 0x800F54C8u: goto label_800F54C8;
    case 0x800F54CCu: goto label_800F54CC;
    case 0x800F54D0u: goto label_800F54D0;
    case 0x800F54D4u: goto label_800F54D4;
    case 0x800F54D8u: goto label_800F54D8;
    case 0x800F54DCu: goto label_800F54DC;
    case 0x800F54E0u: goto label_800F54E0;
    case 0x800F54E4u: goto label_800F54E4;
    case 0x800F54E8u: goto label_800F54E8;
    case 0x800F54ECu: goto label_800F54EC;
    case 0x800F54F0u: goto label_800F54F0;
    case 0x800F54F4u: goto label_800F54F4;
    case 0x800F54F8u: goto label_800F54F8;
    case 0x800F54FCu: goto label_800F54FC;
    case 0x800F5500u: goto label_800F5500;
    case 0x800F5504u: goto label_800F5504;
    case 0x800F5508u: goto label_800F5508;
    case 0x800F550Cu: goto label_800F550C;
    case 0x800F5510u: goto label_800F5510;
    case 0x800F5514u: goto label_800F5514;
    case 0x800F5518u: goto label_800F5518;
    case 0x800F551Cu: goto label_800F551C;
    case 0x800F5520u: goto label_800F5520;
    case 0x800F5524u: goto label_800F5524;
    case 0x800F5528u: goto label_800F5528;
    case 0x800F552Cu: goto label_800F552C;
    case 0x800F5530u: goto label_800F5530;
    case 0x800F5534u: goto label_800F5534;
    case 0x800F5538u: goto label_800F5538;
    case 0x800F553Cu: goto label_800F553C;
    case 0x800F5540u: goto label_800F5540;
    case 0x800F5544u: goto label_800F5544;
    case 0x800F5548u: goto label_800F5548;
    case 0x800F554Cu: goto label_800F554C;
    case 0x800F5550u: goto label_800F5550;
    case 0x800F5554u: goto label_800F5554;
    case 0x800F5558u: goto label_800F5558;
    case 0x800F555Cu: goto label_800F555C;
    case 0x800F5560u: goto label_800F5560;
    case 0x800F5564u: goto label_800F5564;
    case 0x800F5568u: goto label_800F5568;
    case 0x800F556Cu: goto label_800F556C;
    case 0x800F5570u: goto label_800F5570;
    case 0x800F5574u: goto label_800F5574;
    case 0x800F5578u: goto label_800F5578;
    case 0x800F557Cu: goto label_800F557C;
    case 0x800F5580u: goto label_800F5580;
    case 0x800F5584u: goto label_800F5584;
    case 0x800F5588u: goto label_800F5588;
    case 0x800F558Cu: goto label_800F558C;
    case 0x800F5590u: goto label_800F5590;
    case 0x800F5594u: goto label_800F5594;
    case 0x800F5598u: goto label_800F5598;
    case 0x800F559Cu: goto label_800F559C;
    case 0x800F55A0u: goto label_800F55A0;
    case 0x800F55A4u: goto label_800F55A4;
    case 0x800F55A8u: goto label_800F55A8;
    case 0x800F55ACu: goto label_800F55AC;
    case 0x800F55B0u: goto label_800F55B0;
    case 0x800F55B4u: goto label_800F55B4;
    case 0x800F55B8u: goto label_800F55B8;
    case 0x800F55BCu: goto label_800F55BC;
    case 0x800F55C0u: goto label_800F55C0;
    case 0x800F55C4u: goto label_800F55C4;
    case 0x800F55C8u: goto label_800F55C8;
    case 0x800F55CCu: goto label_800F55CC;
    case 0x800F55D0u: goto label_800F55D0;
    case 0x800F55D4u: goto label_800F55D4;
    case 0x800F55D8u: goto label_800F55D8;
    case 0x800F55DCu: goto label_800F55DC;
    case 0x800F55E0u: goto label_800F55E0;
    case 0x800F55E4u: goto label_800F55E4;
    case 0x800F55E8u: goto label_800F55E8;
    case 0x800F55ECu: goto label_800F55EC;
    case 0x800F55F0u: goto label_800F55F0;
    case 0x800F55F4u: goto label_800F55F4;
    case 0x800F55F8u: goto label_800F55F8;
    case 0x800F55FCu: goto label_800F55FC;
    case 0x800F5600u: goto label_800F5600;
    case 0x800F5604u: goto label_800F5604;
    case 0x800F5608u: goto label_800F5608;
    case 0x800F560Cu: goto label_800F560C;
    case 0x800F5610u: goto label_800F5610;
    case 0x800F5614u: goto label_800F5614;
    case 0x800F5618u: goto label_800F5618;
    case 0x800F561Cu: goto label_800F561C;
    case 0x800F5620u: goto label_800F5620;
    case 0x800F5624u: goto label_800F5624;
    case 0x800F5628u: goto label_800F5628;
    case 0x800F562Cu: goto label_800F562C;
    case 0x800F5630u: goto label_800F5630;
    case 0x800F5634u: goto label_800F5634;
    case 0x800F5638u: goto label_800F5638;
    case 0x800F563Cu: goto label_800F563C;
    case 0x800F5640u: goto label_800F5640;
    case 0x800F5644u: goto label_800F5644;
    case 0x800F5648u: goto label_800F5648;
    case 0x800F564Cu: goto label_800F564C;
    case 0x800F5650u: goto label_800F5650;
    case 0x800F5654u: goto label_800F5654;
    case 0x800F5658u: goto label_800F5658;
    case 0x800F565Cu: goto label_800F565C;
    case 0x800F5660u: goto label_800F5660;
    case 0x800F5664u: goto label_800F5664;
    case 0x800F5668u: goto label_800F5668;
    case 0x800F566Cu: goto label_800F566C;
    case 0x800F5670u: goto label_800F5670;
    case 0x800F5674u: goto label_800F5674;
    case 0x800F5678u: goto label_800F5678;
    case 0x800F567Cu: goto label_800F567C;
    case 0x800F5680u: goto label_800F5680;
    case 0x800F5684u: goto label_800F5684;
    case 0x800F5688u: goto label_800F5688;
    case 0x800F568Cu: goto label_800F568C;
    case 0x800F5690u: goto label_800F5690;
    case 0x800F5694u: goto label_800F5694;
    case 0x800F5698u: goto label_800F5698;
    case 0x800F569Cu: goto label_800F569C;
    case 0x800F56A0u: goto label_800F56A0;
    case 0x800F56A4u: goto label_800F56A4;
    case 0x800F56A8u: goto label_800F56A8;
    case 0x800F56ACu: goto label_800F56AC;
    case 0x800F56B0u: goto label_800F56B0;
    case 0x800F56B4u: goto label_800F56B4;
    case 0x800F56B8u: goto label_800F56B8;
    case 0x800F56BCu: goto label_800F56BC;
    case 0x800F56C0u: goto label_800F56C0;
    case 0x800F56C4u: goto label_800F56C4;
    case 0x800F56C8u: goto label_800F56C8;
    case 0x800F56CCu: goto label_800F56CC;
    case 0x800F56D0u: goto label_800F56D0;
    case 0x800F56D4u: goto label_800F56D4;
    case 0x800F56D8u: goto label_800F56D8;
    case 0x800F56DCu: goto label_800F56DC;
    case 0x800F56E0u: goto label_800F56E0;
    case 0x800F56E4u: goto label_800F56E4;
    case 0x800F56E8u: goto label_800F56E8;
    case 0x800F56ECu: goto label_800F56EC;
    case 0x800F56F0u: goto label_800F56F0;
    case 0x800F56F4u: goto label_800F56F4;
    case 0x800F56F8u: goto label_800F56F8;
    case 0x800F56FCu: goto label_800F56FC;
    case 0x800F5700u: goto label_800F5700;
    case 0x800F5704u: goto label_800F5704;
    case 0x800F5708u: goto label_800F5708;
    case 0x800F570Cu: goto label_800F570C;
    case 0x800F5710u: goto label_800F5710;
    case 0x800F5714u: goto label_800F5714;
    case 0x800F5718u: goto label_800F5718;
    case 0x800F571Cu: goto label_800F571C;
    case 0x800F5720u: goto label_800F5720;
    case 0x800F5724u: goto label_800F5724;
    case 0x800F5728u: goto label_800F5728;
    case 0x800F572Cu: goto label_800F572C;
    case 0x800F5730u: goto label_800F5730;
    case 0x800F5734u: goto label_800F5734;
    case 0x800F5738u: goto label_800F5738;
    case 0x800F573Cu: goto label_800F573C;
    case 0x800F5740u: goto label_800F5740;
    case 0x800F5744u: goto label_800F5744;
    case 0x800F5748u: goto label_800F5748;
    case 0x800F574Cu: goto label_800F574C;
    case 0x800F5750u: goto label_800F5750;
    case 0x800F5754u: goto label_800F5754;
    case 0x800F5758u: goto label_800F5758;
    case 0x800F575Cu: goto label_800F575C;
    case 0x800F5760u: goto label_800F5760;
    case 0x800F5764u: goto label_800F5764;
    case 0x800F5768u: goto label_800F5768;
    case 0x800F576Cu: goto label_800F576C;
    case 0x800F5770u: goto label_800F5770;
    case 0x800F5774u: goto label_800F5774;
    case 0x800F5778u: goto label_800F5778;
    case 0x800F577Cu: goto label_800F577C;
    case 0x800F5780u: goto label_800F5780;
    case 0x800F5784u: goto label_800F5784;
    case 0x800F5788u: goto label_800F5788;
    case 0x800F578Cu: goto label_800F578C;
    case 0x800F5790u: goto label_800F5790;
    case 0x800F5794u: goto label_800F5794;
    case 0x800F5798u: goto label_800F5798;
    case 0x800F579Cu: goto label_800F579C;
    case 0x800F57A0u: goto label_800F57A0;
    case 0x800F57A4u: goto label_800F57A4;
    case 0x800F57A8u: goto label_800F57A8;
    case 0x800F57ACu: goto label_800F57AC;
    case 0x800F57B0u: goto label_800F57B0;
    case 0x800F57B4u: goto label_800F57B4;
    case 0x800F57B8u: goto label_800F57B8;
    case 0x800F57BCu: goto label_800F57BC;
    case 0x800F57C0u: goto label_800F57C0;
    case 0x800F57C4u: goto label_800F57C4;
    case 0x800F57C8u: goto label_800F57C8;
    case 0x800F57CCu: goto label_800F57CC;
    case 0x800F57D0u: goto label_800F57D0;
    case 0x800F57D4u: goto label_800F57D4;
    case 0x800F57D8u: goto label_800F57D8;
    case 0x800F57DCu: goto label_800F57DC;
    case 0x800F57E0u: goto label_800F57E0;
    case 0x800F57E4u: goto label_800F57E4;
    case 0x800F57E8u: goto label_800F57E8;
    case 0x800F57ECu: goto label_800F57EC;
    case 0x800F57F0u: goto label_800F57F0;
    case 0x800F57F4u: goto label_800F57F4;
    case 0x800F57F8u: goto label_800F57F8;
    case 0x800F57FCu: goto label_800F57FC;
    case 0x800F5800u: goto label_800F5800;
    case 0x800F5804u: goto label_800F5804;
    case 0x800F5808u: goto label_800F5808;
    case 0x800F580Cu: goto label_800F580C;
    case 0x800F5810u: goto label_800F5810;
    case 0x800F5814u: goto label_800F5814;
    case 0x800F5818u: goto label_800F5818;
    case 0x800F581Cu: goto label_800F581C;
    case 0x800F5820u: goto label_800F5820;
    case 0x800F5824u: goto label_800F5824;
    case 0x800F5828u: goto label_800F5828;
    case 0x800F582Cu: goto label_800F582C;
    case 0x800F5830u: goto label_800F5830;
    case 0x800F5834u: goto label_800F5834;
    case 0x800F5838u: goto label_800F5838;
    case 0x800F583Cu: goto label_800F583C;
    case 0x800F5840u: goto label_800F5840;
    case 0x800F5844u: goto label_800F5844;
    case 0x800F5848u: goto label_800F5848;
    case 0x800F584Cu: goto label_800F584C;
    case 0x800F5850u: goto label_800F5850;
    case 0x800F5854u: goto label_800F5854;
    case 0x800F5858u: goto label_800F5858;
    case 0x800F585Cu: goto label_800F585C;
    case 0x800F5860u: goto label_800F5860;
    case 0x800F5864u: goto label_800F5864;
    case 0x800F5868u: goto label_800F5868;
    case 0x800F586Cu: goto label_800F586C;
    case 0x800F5870u: goto label_800F5870;
    case 0x800F5874u: goto label_800F5874;
    case 0x800F5878u: goto label_800F5878;
    case 0x800F587Cu: goto label_800F587C;
    case 0x800F5880u: goto label_800F5880;
    case 0x800F5884u: goto label_800F5884;
    case 0x800F5888u: goto label_800F5888;
    case 0x800F588Cu: goto label_800F588C;
    case 0x800F5890u: goto label_800F5890;
    case 0x800F5894u: goto label_800F5894;
    case 0x800F5898u: goto label_800F5898;
    case 0x800F589Cu: goto label_800F589C;
    case 0x800F58A0u: goto label_800F58A0;
    case 0x800F58A4u: goto label_800F58A4;
    case 0x800F58A8u: goto label_800F58A8;
    case 0x800F58ACu: goto label_800F58AC;
    case 0x800F58B0u: goto label_800F58B0;
    case 0x800F58B4u: goto label_800F58B4;
    case 0x800F58B8u: goto label_800F58B8;
    case 0x800F58BCu: goto label_800F58BC;
    case 0x800F58C0u: goto label_800F58C0;
    case 0x800F58C4u: goto label_800F58C4;
    case 0x800F58C8u: goto label_800F58C8;
    case 0x800F58CCu: goto label_800F58CC;
    case 0x800F58D0u: goto label_800F58D0;
    case 0x800F58D4u: goto label_800F58D4;
    case 0x800F58D8u: goto label_800F58D8;
    case 0x800F58DCu: goto label_800F58DC;
    case 0x800F58E0u: goto label_800F58E0;
    case 0x800F58E4u: goto label_800F58E4;
    case 0x800F58E8u: goto label_800F58E8;
    case 0x800F58ECu: goto label_800F58EC;
    case 0x800F58F0u: goto label_800F58F0;
    case 0x800F58F4u: goto label_800F58F4;
    case 0x800F58F8u: goto label_800F58F8;
    case 0x800F58FCu: goto label_800F58FC;
    case 0x800F5900u: goto label_800F5900;
    case 0x800F5904u: goto label_800F5904;
    case 0x800F5908u: goto label_800F5908;
    case 0x800F590Cu: goto label_800F590C;
    case 0x800F5910u: goto label_800F5910;
    case 0x800F5914u: goto label_800F5914;
    case 0x800F5918u: goto label_800F5918;
    case 0x800F591Cu: goto label_800F591C;
    case 0x800F5920u: goto label_800F5920;
    case 0x800F5924u: goto label_800F5924;
    case 0x800F5928u: goto label_800F5928;
    case 0x800F592Cu: goto label_800F592C;
    case 0x800F5930u: goto label_800F5930;
    case 0x800F5934u: goto label_800F5934;
    case 0x800F5938u: goto label_800F5938;
    case 0x800F593Cu: goto label_800F593C;
    case 0x800F5940u: goto label_800F5940;
    case 0x800F5944u: goto label_800F5944;
    case 0x800F5948u: goto label_800F5948;
    case 0x800F594Cu: goto label_800F594C;
    case 0x800F5950u: goto label_800F5950;
    case 0x800F5954u: goto label_800F5954;
    case 0x800F5958u: goto label_800F5958;
    case 0x800F595Cu: goto label_800F595C;
    case 0x800F5960u: goto label_800F5960;
    case 0x800F5964u: goto label_800F5964;
    case 0x800F5968u: goto label_800F5968;
    case 0x800F596Cu: goto label_800F596C;
    case 0x800F5970u: goto label_800F5970;
    case 0x800F5974u: goto label_800F5974;
    case 0x800F5978u: goto label_800F5978;
    case 0x800F597Cu: goto label_800F597C;
    case 0x800F5980u: goto label_800F5980;
    case 0x800F5984u: goto label_800F5984;
    case 0x800F5988u: goto label_800F5988;
    case 0x800F598Cu: goto label_800F598C;
    case 0x800F5990u: goto label_800F5990;
    case 0x800F5994u: goto label_800F5994;
    case 0x800F5998u: goto label_800F5998;
    case 0x800F599Cu: goto label_800F599C;
    case 0x800F59A0u: goto label_800F59A0;
    case 0x800F59A4u: goto label_800F59A4;
    case 0x800F59A8u: goto label_800F59A8;
    case 0x800F59ACu: goto label_800F59AC;
    case 0x800F59B0u: goto label_800F59B0;
    case 0x800F59B4u: goto label_800F59B4;
    case 0x800F59B8u: goto label_800F59B8;
    case 0x800F59BCu: goto label_800F59BC;
    case 0x800F59C0u: goto label_800F59C0;
    case 0x800F59C4u: goto label_800F59C4;
    case 0x800F59C8u: goto label_800F59C8;
    case 0x800F59CCu: goto label_800F59CC;
    case 0x800F59D0u: goto label_800F59D0;
    case 0x800F59D4u: goto label_800F59D4;
    case 0x800F59D8u: goto label_800F59D8;
    case 0x800F59DCu: goto label_800F59DC;
    case 0x800F59E0u: goto label_800F59E0;
    case 0x800F59E4u: goto label_800F59E4;
    case 0x800F59E8u: goto label_800F59E8;
    case 0x800F59ECu: goto label_800F59EC;
    case 0x800F59F0u: goto label_800F59F0;
    case 0x800F59F4u: goto label_800F59F4;
    case 0x800F59F8u: goto label_800F59F8;
    case 0x800F59FCu: goto label_800F59FC;
    case 0x800F5A00u: goto label_800F5A00;
    case 0x800F5A04u: goto label_800F5A04;
    case 0x800F5A08u: goto label_800F5A08;
    case 0x800F5A0Cu: goto label_800F5A0C;
    case 0x800F5A10u: goto label_800F5A10;
    case 0x800F5A14u: goto label_800F5A14;
    case 0x800F5A18u: goto label_800F5A18;
    case 0x800F5A1Cu: goto label_800F5A1C;
    case 0x800F5A20u: goto label_800F5A20;
    case 0x800F5A24u: goto label_800F5A24;
    case 0x800F5A28u: goto label_800F5A28;
    case 0x800F5A2Cu: goto label_800F5A2C;
    case 0x800F5A30u: goto label_800F5A30;
    case 0x800F5A34u: goto label_800F5A34;
    case 0x800F5A38u: goto label_800F5A38;
    case 0x800F5A3Cu: goto label_800F5A3C;
    case 0x800F5A40u: goto label_800F5A40;
    case 0x800F5A44u: goto label_800F5A44;
    case 0x800F5A48u: goto label_800F5A48;
    case 0x800F5A4Cu: goto label_800F5A4C;
    case 0x800F5A50u: goto label_800F5A50;
    case 0x800F5A54u: goto label_800F5A54;
    case 0x800F5A58u: goto label_800F5A58;
    case 0x800F5A5Cu: goto label_800F5A5C;
    case 0x800F5A60u: goto label_800F5A60;
    case 0x800F5A64u: goto label_800F5A64;
    case 0x800F5A68u: goto label_800F5A68;
    case 0x800F5A6Cu: goto label_800F5A6C;
    case 0x800F5A70u: goto label_800F5A70;
    case 0x800F5A74u: goto label_800F5A74;
    case 0x800F5A78u: goto label_800F5A78;
    case 0x800F5A7Cu: goto label_800F5A7C;
    case 0x800F5A80u: goto label_800F5A80;
    case 0x800F5A84u: goto label_800F5A84;
    case 0x800F5A88u: goto label_800F5A88;
    case 0x800F5A8Cu: goto label_800F5A8C;
    case 0x800F5A90u: goto label_800F5A90;
    case 0x800F5A94u: goto label_800F5A94;
    case 0x800F5A98u: goto label_800F5A98;
    case 0x800F5A9Cu: goto label_800F5A9C;
    case 0x800F5AA0u: goto label_800F5AA0;
    case 0x800F5AA4u: goto label_800F5AA4;
    case 0x800F5AA8u: goto label_800F5AA8;
    case 0x800F5AACu: goto label_800F5AAC;
    case 0x800F5AB0u: goto label_800F5AB0;
    case 0x800F5AB4u: goto label_800F5AB4;
    case 0x800F5AB8u: goto label_800F5AB8;
    case 0x800F5ABCu: goto label_800F5ABC;
    case 0x800F5AC0u: goto label_800F5AC0;
    case 0x800F5AC4u: goto label_800F5AC4;
    case 0x800F5AC8u: goto label_800F5AC8;
    case 0x800F5ACCu: goto label_800F5ACC;
    case 0x800F5AD0u: goto label_800F5AD0;
    case 0x800F5AD4u: goto label_800F5AD4;
    case 0x800F5AD8u: goto label_800F5AD8;
    case 0x800F5ADCu: goto label_800F5ADC;
    case 0x800F5AE0u: goto label_800F5AE0;
    case 0x800F5AE4u: goto label_800F5AE4;
    case 0x800F5AE8u: goto label_800F5AE8;
    case 0x800F5AECu: goto label_800F5AEC;
    case 0x800F5AF0u: goto label_800F5AF0;
    case 0x800F5AF4u: goto label_800F5AF4;
    case 0x800F5AF8u: goto label_800F5AF8;
    case 0x800F5AFCu: goto label_800F5AFC;
    case 0x800F5B00u: goto label_800F5B00;
    case 0x800F5B04u: goto label_800F5B04;
    case 0x800F5B08u: goto label_800F5B08;
    case 0x800F5B0Cu: goto label_800F5B0C;
    case 0x800F5B10u: goto label_800F5B10;
    case 0x800F5B14u: goto label_800F5B14;
    case 0x800F5B18u: goto label_800F5B18;
    case 0x800F5B1Cu: goto label_800F5B1C;
    case 0x800F5B20u: goto label_800F5B20;
    case 0x800F5B24u: goto label_800F5B24;
    case 0x800F5B28u: goto label_800F5B28;
    case 0x800F5B2Cu: goto label_800F5B2C;
    case 0x800F5B30u: goto label_800F5B30;
    case 0x800F5B34u: goto label_800F5B34;
    case 0x800F5B38u: goto label_800F5B38;
    case 0x800F5B3Cu: goto label_800F5B3C;
    case 0x800F5B40u: goto label_800F5B40;
    case 0x800F5B44u: goto label_800F5B44;
    case 0x800F5B48u: goto label_800F5B48;
    case 0x800F5B4Cu: goto label_800F5B4C;
    case 0x800F5B50u: goto label_800F5B50;
    case 0x800F5B54u: goto label_800F5B54;
    case 0x800F5B58u: goto label_800F5B58;
    case 0x800F5B5Cu: goto label_800F5B5C;
    case 0x800F5B60u: goto label_800F5B60;
    case 0x800F5B64u: goto label_800F5B64;
    case 0x800F5B68u: goto label_800F5B68;
    case 0x800F5B6Cu: goto label_800F5B6C;
    case 0x800F5B70u: goto label_800F5B70;
    case 0x800F5B74u: goto label_800F5B74;
    case 0x800F5B78u: goto label_800F5B78;
    case 0x800F5B7Cu: goto label_800F5B7C;
    case 0x800F5B80u: goto label_800F5B80;
    case 0x800F5B84u: goto label_800F5B84;
    case 0x800F5B88u: goto label_800F5B88;
    case 0x800F5B8Cu: goto label_800F5B8C;
    case 0x800F5B90u: goto label_800F5B90;
    case 0x800F5B94u: goto label_800F5B94;
    case 0x800F5B98u: goto label_800F5B98;
    case 0x800F5B9Cu: goto label_800F5B9C;
    case 0x800F5BA0u: goto label_800F5BA0;
    case 0x800F5BA4u: goto label_800F5BA4;
    case 0x800F5BA8u: goto label_800F5BA8;
    case 0x800F5BACu: goto label_800F5BAC;
    case 0x800F5BB0u: goto label_800F5BB0;
    case 0x800F5BB4u: goto label_800F5BB4;
    case 0x800F5BB8u: goto label_800F5BB8;
    case 0x800F5BBCu: goto label_800F5BBC;
    case 0x800F5BC0u: goto label_800F5BC0;
    case 0x800F5BC4u: goto label_800F5BC4;
    case 0x800F5BC8u: goto label_800F5BC8;
    case 0x800F5BCCu: goto label_800F5BCC;
    case 0x800F5BD0u: goto label_800F5BD0;
    case 0x800F5BD4u: goto label_800F5BD4;
    case 0x800F5BD8u: goto label_800F5BD8;
    case 0x800F5BDCu: goto label_800F5BDC;
    case 0x800F5BE0u: goto label_800F5BE0;
    case 0x800F5BE4u: goto label_800F5BE4;
    case 0x800F5BE8u: goto label_800F5BE8;
    case 0x800F5BECu: goto label_800F5BEC;
    case 0x800F5BF0u: goto label_800F5BF0;
    case 0x800F5BF4u: goto label_800F5BF4;
    case 0x800F5BF8u: goto label_800F5BF8;
    case 0x800F5BFCu: goto label_800F5BFC;
    case 0x800F5C00u: goto label_800F5C00;
    case 0x800F5C04u: goto label_800F5C04;
    case 0x800F5C08u: goto label_800F5C08;
    case 0x800F5C0Cu: goto label_800F5C0C;
    case 0x800F5C10u: goto label_800F5C10;
    case 0x800F5C14u: goto label_800F5C14;
    case 0x800F5C18u: goto label_800F5C18;
    case 0x800F5C1Cu: goto label_800F5C1C;
    case 0x800F5C20u: goto label_800F5C20;
    case 0x800F5C24u: goto label_800F5C24;
    case 0x800F5C28u: goto label_800F5C28;
    case 0x800F5C2Cu: goto label_800F5C2C;
    case 0x800F5C30u: goto label_800F5C30;
    case 0x800F5C34u: goto label_800F5C34;
    case 0x800F5C38u: goto label_800F5C38;
    case 0x800F5C3Cu: goto label_800F5C3C;
    case 0x800F5C40u: goto label_800F5C40;
    case 0x800F5C44u: goto label_800F5C44;
    case 0x800F5C48u: goto label_800F5C48;
    case 0x800F5C4Cu: goto label_800F5C4C;
    case 0x800F5C50u: goto label_800F5C50;
    case 0x800F5C54u: goto label_800F5C54;
    case 0x800F5C58u: goto label_800F5C58;
    case 0x800F5C5Cu: goto label_800F5C5C;
    case 0x800F5C60u: goto label_800F5C60;
    case 0x800F5C64u: goto label_800F5C64;
    case 0x800F5C68u: goto label_800F5C68;
    case 0x800F5C6Cu: goto label_800F5C6C;
    case 0x800F5C70u: goto label_800F5C70;
    case 0x800F5C74u: goto label_800F5C74;
    case 0x800F5C78u: goto label_800F5C78;
    case 0x800F5C7Cu: goto label_800F5C7C;
    case 0x800F5C80u: goto label_800F5C80;
    case 0x800F5C84u: goto label_800F5C84;
    case 0x800F5C88u: goto label_800F5C88;
    case 0x800F5C8Cu: goto label_800F5C8C;
    case 0x800F5C90u: goto label_800F5C90;
    case 0x800F5C94u: goto label_800F5C94;
    case 0x800F5C98u: goto label_800F5C98;
    case 0x800F5C9Cu: goto label_800F5C9C;
    case 0x800F5CA0u: goto label_800F5CA0;
    case 0x800F5CA4u: goto label_800F5CA4;
    case 0x800F5CA8u: goto label_800F5CA8;
    case 0x800F5CACu: goto label_800F5CAC;
    case 0x800F5CB0u: goto label_800F5CB0;
    case 0x800F5CB4u: goto label_800F5CB4;
    case 0x800F5CB8u: goto label_800F5CB8;
    case 0x800F5CBCu: goto label_800F5CBC;
    case 0x800F5CC0u: goto label_800F5CC0;
    case 0x800F5CC4u: goto label_800F5CC4;
    case 0x800F5CC8u: goto label_800F5CC8;
    case 0x800F5CCCu: goto label_800F5CCC;
    case 0x800F5CD0u: goto label_800F5CD0;
    case 0x800F5CD4u: goto label_800F5CD4;
    case 0x800F5CD8u: goto label_800F5CD8;
    case 0x800F5CDCu: goto label_800F5CDC;
    case 0x800F5CE0u: goto label_800F5CE0;
    case 0x800F5CE4u: goto label_800F5CE4;
    case 0x800F5CE8u: goto label_800F5CE8;
    case 0x800F5CECu: goto label_800F5CEC;
    case 0x800F5CF0u: goto label_800F5CF0;
    case 0x800F5CF4u: goto label_800F5CF4;
    case 0x800F5CF8u: goto label_800F5CF8;
    case 0x800F5CFCu: goto label_800F5CFC;
    case 0x800F5D00u: goto label_800F5D00;
    case 0x800F5D04u: goto label_800F5D04;
    case 0x800F5D08u: goto label_800F5D08;
    case 0x800F5D0Cu: goto label_800F5D0C;
    case 0x800F5D10u: goto label_800F5D10;
    case 0x800F5D14u: goto label_800F5D14;
    case 0x800F5D18u: goto label_800F5D18;
    case 0x800F5D1Cu: goto label_800F5D1C;
    case 0x800F5D20u: goto label_800F5D20;
    case 0x800F5D24u: goto label_800F5D24;
    case 0x800F5D28u: goto label_800F5D28;
    case 0x800F5D2Cu: goto label_800F5D2C;
    case 0x800F5D30u: goto label_800F5D30;
    case 0x800F5D34u: goto label_800F5D34;
    case 0x800F5D38u: goto label_800F5D38;
    case 0x800F5D3Cu: goto label_800F5D3C;
    case 0x800F5D40u: goto label_800F5D40;
    case 0x800F5D44u: goto label_800F5D44;
    case 0x800F5D48u: goto label_800F5D48;
    case 0x800F5D4Cu: goto label_800F5D4C;
    case 0x800F5D50u: goto label_800F5D50;
    case 0x800F5D54u: goto label_800F5D54;
    case 0x800F5D58u: goto label_800F5D58;
    case 0x800F5D5Cu: goto label_800F5D5C;
    case 0x800F5D60u: goto label_800F5D60;
    case 0x800F5D64u: goto label_800F5D64;
    case 0x800F5D68u: goto label_800F5D68;
    case 0x800F5D6Cu: goto label_800F5D6C;
    case 0x800F5D70u: goto label_800F5D70;
    case 0x800F5D74u: goto label_800F5D74;
    case 0x800F5D78u: goto label_800F5D78;
    case 0x800F5D7Cu: goto label_800F5D7C;
    case 0x800F5D80u: goto label_800F5D80;
    case 0x800F5D84u: goto label_800F5D84;
    case 0x800F5D88u: goto label_800F5D88;
    case 0x800F5D8Cu: goto label_800F5D8C;
    case 0x800F5D90u: goto label_800F5D90;
    case 0x800F5D94u: goto label_800F5D94;
    case 0x800F5D98u: goto label_800F5D98;
    case 0x800F5D9Cu: goto label_800F5D9C;
    case 0x800F5DA0u: goto label_800F5DA0;
    case 0x800F5DA4u: goto label_800F5DA4;
    case 0x800F5DA8u: goto label_800F5DA8;
    case 0x800F5DACu: goto label_800F5DAC;
    case 0x800F5DB0u: goto label_800F5DB0;
    case 0x800F5DB4u: goto label_800F5DB4;
    case 0x800F5DB8u: goto label_800F5DB8;
    case 0x800F5DBCu: goto label_800F5DBC;
    case 0x800F5DC0u: goto label_800F5DC0;
    case 0x800F5DC4u: goto label_800F5DC4;
    case 0x800F5DC8u: goto label_800F5DC8;
    case 0x800F5DCCu: goto label_800F5DCC;
    case 0x800F5DD0u: goto label_800F5DD0;
    case 0x800F5DD4u: goto label_800F5DD4;
    case 0x800F5DD8u: goto label_800F5DD8;
    case 0x800F5DDCu: goto label_800F5DDC;
    case 0x800F5DE0u: goto label_800F5DE0;
    case 0x800F5DE4u: goto label_800F5DE4;
    case 0x800F5DE8u: goto label_800F5DE8;
    case 0x800F5DECu: goto label_800F5DEC;
    case 0x800F5DF0u: goto label_800F5DF0;
    case 0x800F5DF4u: goto label_800F5DF4;
    case 0x800F5DF8u: goto label_800F5DF8;
    case 0x800F5DFCu: goto label_800F5DFC;
    case 0x800F5E00u: goto label_800F5E00;
    case 0x800F5E04u: goto label_800F5E04;
    case 0x800F5E08u: goto label_800F5E08;
    case 0x800F5E0Cu: goto label_800F5E0C;
    case 0x800F5E10u: goto label_800F5E10;
    case 0x800F5E14u: goto label_800F5E14;
    case 0x800F5E18u: goto label_800F5E18;
    case 0x800F5E1Cu: goto label_800F5E1C;
    case 0x800F5E20u: goto label_800F5E20;
    case 0x800F5E24u: goto label_800F5E24;
    case 0x800F5E28u: goto label_800F5E28;
    case 0x800F5E2Cu: goto label_800F5E2C;
    case 0x800F5E30u: goto label_800F5E30;
    case 0x800F5E34u: goto label_800F5E34;
    case 0x800F5E38u: goto label_800F5E38;
    case 0x800F5E3Cu: goto label_800F5E3C;
    case 0x800F5E40u: goto label_800F5E40;
    case 0x800F5E44u: goto label_800F5E44;
    case 0x800F5E48u: goto label_800F5E48;
    case 0x800F5E4Cu: goto label_800F5E4C;
    case 0x800F5E50u: goto label_800F5E50;
    case 0x800F5E54u: goto label_800F5E54;
    case 0x800F5E58u: goto label_800F5E58;
    case 0x800F5E5Cu: goto label_800F5E5C;
    case 0x800F5E60u: goto label_800F5E60;
    case 0x800F5E64u: goto label_800F5E64;
    case 0x800F5E68u: goto label_800F5E68;
    case 0x800F5E6Cu: goto label_800F5E6C;
    case 0x800F5E70u: goto label_800F5E70;
    case 0x800F5E74u: goto label_800F5E74;
    case 0x800F5E78u: goto label_800F5E78;
    case 0x800F5E7Cu: goto label_800F5E7C;
    case 0x800F5E80u: goto label_800F5E80;
    case 0x800F5E84u: goto label_800F5E84;
    case 0x800F5E88u: goto label_800F5E88;
    case 0x800F5E8Cu: goto label_800F5E8C;
    case 0x800F5E90u: goto label_800F5E90;
    case 0x800F5E94u: goto label_800F5E94;
    case 0x800F5E98u: goto label_800F5E98;
    case 0x800F5E9Cu: goto label_800F5E9C;
    case 0x800F5EA0u: goto label_800F5EA0;
    case 0x800F5EA4u: goto label_800F5EA4;
    case 0x800F5EA8u: goto label_800F5EA8;
    case 0x800F5EACu: goto label_800F5EAC;
    case 0x800F5EB0u: goto label_800F5EB0;
    case 0x800F5EB4u: goto label_800F5EB4;
    case 0x800F5EB8u: goto label_800F5EB8;
    case 0x800F5EBCu: goto label_800F5EBC;
    case 0x800F5EC0u: goto label_800F5EC0;
    case 0x800F5EC4u: goto label_800F5EC4;
    case 0x800F5EC8u: goto label_800F5EC8;
    case 0x800F5ECCu: goto label_800F5ECC;
    case 0x800F5ED0u: goto label_800F5ED0;
    case 0x800F5ED4u: goto label_800F5ED4;
    case 0x800F5ED8u: goto label_800F5ED8;
    case 0x800F5EDCu: goto label_800F5EDC;
    case 0x800F5EE0u: goto label_800F5EE0;
    case 0x800F5EE4u: goto label_800F5EE4;
    case 0x800F5EE8u: goto label_800F5EE8;
    case 0x800F5EECu: goto label_800F5EEC;
    case 0x800F5EF0u: goto label_800F5EF0;
    case 0x800F5EF4u: goto label_800F5EF4;
    case 0x800F5EF8u: goto label_800F5EF8;
    case 0x800F5EFCu: goto label_800F5EFC;
    case 0x800F5F00u: goto label_800F5F00;
    case 0x800F5F04u: goto label_800F5F04;
    case 0x800F5F08u: goto label_800F5F08;
    case 0x800F5F0Cu: goto label_800F5F0C;
    case 0x800F5F10u: goto label_800F5F10;
    case 0x800F5F14u: goto label_800F5F14;
    case 0x800F5F18u: goto label_800F5F18;
    case 0x800F5F1Cu: goto label_800F5F1C;
    case 0x800F5F20u: goto label_800F5F20;
    case 0x800F5F24u: goto label_800F5F24;
    case 0x800F5F28u: goto label_800F5F28;
    case 0x800F5F2Cu: goto label_800F5F2C;
    case 0x800F5F30u: goto label_800F5F30;
    case 0x800F5F34u: goto label_800F5F34;
    case 0x800F5F38u: goto label_800F5F38;
    case 0x800F5F3Cu: goto label_800F5F3C;
    case 0x800F5F40u: goto label_800F5F40;
    case 0x800F5F44u: goto label_800F5F44;
    case 0x800F5F48u: goto label_800F5F48;
    case 0x800F5F4Cu: goto label_800F5F4C;
    case 0x800F5F50u: goto label_800F5F50;
    case 0x800F5F54u: goto label_800F5F54;
    case 0x800F5F58u: goto label_800F5F58;
    case 0x800F5F5Cu: goto label_800F5F5C;
    case 0x800F5F60u: goto label_800F5F60;
    case 0x800F5F64u: goto label_800F5F64;
    case 0x800F5F68u: goto label_800F5F68;
    case 0x800F5F6Cu: goto label_800F5F6C;
    case 0x800F5F70u: goto label_800F5F70;
    case 0x800F5F74u: goto label_800F5F74;
    case 0x800F5F78u: goto label_800F5F78;
    case 0x800F5F7Cu: goto label_800F5F7C;
    case 0x800F5F80u: goto label_800F5F80;
    case 0x800F5F84u: goto label_800F5F84;
    case 0x800F5F88u: goto label_800F5F88;
    case 0x800F5F8Cu: goto label_800F5F8C;
    case 0x800F5F90u: goto label_800F5F90;
    case 0x800F5F94u: goto label_800F5F94;
    case 0x800F5F98u: goto label_800F5F98;
    case 0x800F5F9Cu: goto label_800F5F9C;
    case 0x800F5FA0u: goto label_800F5FA0;
    case 0x800F5FA4u: goto label_800F5FA4;
    case 0x800F5FA8u: goto label_800F5FA8;
    case 0x800F5FACu: goto label_800F5FAC;
    case 0x800F5FB0u: goto label_800F5FB0;
    case 0x800F5FB4u: goto label_800F5FB4;
    case 0x800F5FB8u: goto label_800F5FB8;
    case 0x800F5FBCu: goto label_800F5FBC;
    case 0x800F5FC0u: goto label_800F5FC0;
    case 0x800F5FC4u: goto label_800F5FC4;
    case 0x800F5FC8u: goto label_800F5FC8;
    case 0x800F5FCCu: goto label_800F5FCC;
    case 0x800F5FD0u: goto label_800F5FD0;
    case 0x800F5FD4u: goto label_800F5FD4;
    case 0x800F5FD8u: goto label_800F5FD8;
    case 0x800F5FDCu: goto label_800F5FDC;
    case 0x800F5FE0u: goto label_800F5FE0;
    case 0x800F5FE4u: goto label_800F5FE4;
    case 0x800F5FE8u: goto label_800F5FE8;
    case 0x800F5FECu: goto label_800F5FEC;
    case 0x800F5FF0u: goto label_800F5FF0;
    case 0x800F5FF4u: goto label_800F5FF4;
    case 0x800F5FF8u: goto label_800F5FF8;
    case 0x800F5FFCu: goto label_800F5FFC;
    case 0x800F6000u: goto label_800F6000;
    case 0x800F6004u: goto label_800F6004;
    case 0x800F6008u: goto label_800F6008;
    case 0x800F600Cu: goto label_800F600C;
    case 0x800F6010u: goto label_800F6010;
    case 0x800F6014u: goto label_800F6014;
    case 0x800F6018u: goto label_800F6018;
    case 0x800F601Cu: goto label_800F601C;
    case 0x800F6020u: goto label_800F6020;
    case 0x800F6024u: goto label_800F6024;
    case 0x800F6028u: goto label_800F6028;
    case 0x800F602Cu: goto label_800F602C;
    case 0x800F6030u: goto label_800F6030;
    case 0x800F6034u: goto label_800F6034;
    case 0x800F6038u: goto label_800F6038;
    case 0x800F603Cu: goto label_800F603C;
    case 0x800F6040u: goto label_800F6040;
    case 0x800F6044u: goto label_800F6044;
    case 0x800F6048u: goto label_800F6048;
    case 0x800F604Cu: goto label_800F604C;
    case 0x800F6050u: goto label_800F6050;
    case 0x800F6054u: goto label_800F6054;
    case 0x800F6058u: goto label_800F6058;
    case 0x800F605Cu: goto label_800F605C;
    case 0x800F6060u: goto label_800F6060;
    case 0x800F6064u: goto label_800F6064;
    case 0x800F6068u: goto label_800F6068;
    case 0x800F606Cu: goto label_800F606C;
    case 0x800F6070u: goto label_800F6070;
    case 0x800F6074u: goto label_800F6074;
    case 0x800F6078u: goto label_800F6078;
    case 0x800F607Cu: goto label_800F607C;
    case 0x800F6080u: goto label_800F6080;
    case 0x800F6084u: goto label_800F6084;
    case 0x800F6088u: goto label_800F6088;
    case 0x800F608Cu: goto label_800F608C;
    case 0x800F6090u: goto label_800F6090;
    case 0x800F6094u: goto label_800F6094;
    case 0x800F6098u: goto label_800F6098;
    case 0x800F609Cu: goto label_800F609C;
    case 0x800F60A0u: goto label_800F60A0;
    case 0x800F60A4u: goto label_800F60A4;
    case 0x800F60A8u: goto label_800F60A8;
    case 0x800F60ACu: goto label_800F60AC;
    case 0x800F60B0u: goto label_800F60B0;
    case 0x800F60B4u: goto label_800F60B4;
    case 0x800F60B8u: goto label_800F60B8;
    case 0x800F60BCu: goto label_800F60BC;
    case 0x800F60C0u: goto label_800F60C0;
    case 0x800F60C4u: goto label_800F60C4;
    case 0x800F60C8u: goto label_800F60C8;
    case 0x800F60CCu: goto label_800F60CC;
    case 0x800F60D0u: goto label_800F60D0;
    case 0x800F60D4u: goto label_800F60D4;
    case 0x800F60D8u: goto label_800F60D8;
    case 0x800F60DCu: goto label_800F60DC;
    case 0x800F60E0u: goto label_800F60E0;
    case 0x800F60E4u: goto label_800F60E4;
    case 0x800F60E8u: goto label_800F60E8;
    case 0x800F60ECu: goto label_800F60EC;
    case 0x800F60F0u: goto label_800F60F0;
    case 0x800F60F4u: goto label_800F60F4;
    case 0x800F60F8u: goto label_800F60F8;
    case 0x800F60FCu: goto label_800F60FC;
    case 0x800F6100u: goto label_800F6100;
    case 0x800F6104u: goto label_800F6104;
    case 0x800F6108u: goto label_800F6108;
    case 0x800F610Cu: goto label_800F610C;
    case 0x800F6110u: goto label_800F6110;
    case 0x800F6114u: goto label_800F6114;
    case 0x800F6118u: goto label_800F6118;
    case 0x800F611Cu: goto label_800F611C;
    case 0x800F6120u: goto label_800F6120;
    case 0x800F6124u: goto label_800F6124;
    case 0x800F6128u: goto label_800F6128;
    case 0x800F612Cu: goto label_800F612C;
    case 0x800F6130u: goto label_800F6130;
    case 0x800F6134u: goto label_800F6134;
    case 0x800F6138u: goto label_800F6138;
    case 0x800F613Cu: goto label_800F613C;
    case 0x800F6140u: goto label_800F6140;
    case 0x800F6144u: goto label_800F6144;
    case 0x800F6148u: goto label_800F6148;
    case 0x800F614Cu: goto label_800F614C;
    case 0x800F6150u: goto label_800F6150;
    case 0x800F6154u: goto label_800F6154;
    case 0x800F6158u: goto label_800F6158;
    case 0x800F615Cu: goto label_800F615C;
    case 0x800F6160u: goto label_800F6160;
    case 0x800F6164u: goto label_800F6164;
    case 0x800F6168u: goto label_800F6168;
    case 0x800F616Cu: goto label_800F616C;
    case 0x800F6170u: goto label_800F6170;
    case 0x800F6174u: goto label_800F6174;
    case 0x800F6178u: goto label_800F6178;
    case 0x800F617Cu: goto label_800F617C;
    case 0x800F6180u: goto label_800F6180;
    case 0x800F6184u: goto label_800F6184;
    case 0x800F6188u: goto label_800F6188;
    case 0x800F618Cu: goto label_800F618C;
    case 0x800F6190u: goto label_800F6190;
    case 0x800F6194u: goto label_800F6194;
    case 0x800F6198u: goto label_800F6198;
    case 0x800F619Cu: goto label_800F619C;
    case 0x800F61A0u: goto label_800F61A0;
    case 0x800F61A4u: goto label_800F61A4;
    case 0x800F61A8u: goto label_800F61A8;
    case 0x800F61ACu: goto label_800F61AC;
    case 0x800F61B0u: goto label_800F61B0;
    case 0x800F61B4u: goto label_800F61B4;
    case 0x800F61B8u: goto label_800F61B8;
    case 0x800F61BCu: goto label_800F61BC;
    case 0x800F61C0u: goto label_800F61C0;
    case 0x800F61C4u: goto label_800F61C4;
    case 0x800F61C8u: goto label_800F61C8;
    case 0x800F61CCu: goto label_800F61CC;
    case 0x800F61D0u: goto label_800F61D0;
    case 0x800F61D4u: goto label_800F61D4;
    case 0x800F61D8u: goto label_800F61D8;
    case 0x800F61DCu: goto label_800F61DC;
    case 0x800F61E0u: goto label_800F61E0;
    case 0x800F61E4u: goto label_800F61E4;
    case 0x800F61E8u: goto label_800F61E8;
    case 0x800F61ECu: goto label_800F61EC;
    case 0x800F61F0u: goto label_800F61F0;
    case 0x800F61F4u: goto label_800F61F4;
    case 0x800F61F8u: goto label_800F61F8;
    case 0x800F61FCu: goto label_800F61FC;
    case 0x800F6200u: goto label_800F6200;
    case 0x800F6204u: goto label_800F6204;
    case 0x800F6208u: goto label_800F6208;
    case 0x800F620Cu: goto label_800F620C;
    case 0x800F6210u: goto label_800F6210;
    case 0x800F6214u: goto label_800F6214;
    case 0x800F6218u: goto label_800F6218;
    case 0x800F621Cu: goto label_800F621C;
    case 0x800F6220u: goto label_800F6220;
    case 0x800F6224u: goto label_800F6224;
    case 0x800F6228u: goto label_800F6228;
    case 0x800F622Cu: goto label_800F622C;
    case 0x800F6230u: goto label_800F6230;
    case 0x800F6234u: goto label_800F6234;
    case 0x800F6238u: goto label_800F6238;
    case 0x800F623Cu: goto label_800F623C;
    case 0x800F6240u: goto label_800F6240;
    case 0x800F6244u: goto label_800F6244;
    case 0x800F6248u: goto label_800F6248;
    case 0x800F624Cu: goto label_800F624C;
    case 0x800F6250u: goto label_800F6250;
    case 0x800F6254u: goto label_800F6254;
    case 0x800F6258u: goto label_800F6258;
    case 0x800F625Cu: goto label_800F625C;
    case 0x800F6260u: goto label_800F6260;
    case 0x800F6264u: goto label_800F6264;
    case 0x800F6268u: goto label_800F6268;
    case 0x800F626Cu: goto label_800F626C;
    case 0x800F6270u: goto label_800F6270;
    case 0x800F6274u: goto label_800F6274;
    case 0x800F6278u: goto label_800F6278;
    case 0x800F627Cu: goto label_800F627C;
    case 0x800F6280u: goto label_800F6280;
    case 0x800F6284u: goto label_800F6284;
    case 0x800F6288u: goto label_800F6288;
    case 0x800F628Cu: goto label_800F628C;
    case 0x800F6290u: goto label_800F6290;
    case 0x800F6294u: goto label_800F6294;
    case 0x800F6298u: goto label_800F6298;
    case 0x800F629Cu: goto label_800F629C;
    case 0x800F62A0u: goto label_800F62A0;
    case 0x800F62A4u: goto label_800F62A4;
    case 0x800F62A8u: goto label_800F62A8;
    case 0x800F62ACu: goto label_800F62AC;
    case 0x800F62B0u: goto label_800F62B0;
    case 0x800F62B4u: goto label_800F62B4;
    case 0x800F62B8u: goto label_800F62B8;
    case 0x800F62BCu: goto label_800F62BC;
    case 0x800F62C0u: goto label_800F62C0;
    case 0x800F62C4u: goto label_800F62C4;
    case 0x800F62C8u: goto label_800F62C8;
    case 0x800F62CCu: goto label_800F62CC;
    case 0x800F62D0u: goto label_800F62D0;
    case 0x800F62D4u: goto label_800F62D4;
    case 0x800F62D8u: goto label_800F62D8;
    case 0x800F62DCu: goto label_800F62DC;
    case 0x800F62E0u: goto label_800F62E0;
    case 0x800F62E4u: goto label_800F62E4;
    case 0x800F62E8u: goto label_800F62E8;
    case 0x800F62ECu: goto label_800F62EC;
    case 0x800F62F0u: goto label_800F62F0;
    case 0x800F62F4u: goto label_800F62F4;
    case 0x800F62F8u: goto label_800F62F8;
    case 0x800F62FCu: goto label_800F62FC;
    case 0x800F6300u: goto label_800F6300;
    case 0x800F6304u: goto label_800F6304;
    case 0x800F6308u: goto label_800F6308;
    case 0x800F630Cu: goto label_800F630C;
    case 0x800F6310u: goto label_800F6310;
    case 0x800F6314u: goto label_800F6314;
    case 0x800F6318u: goto label_800F6318;
    case 0x800F631Cu: goto label_800F631C;
    case 0x800F6320u: goto label_800F6320;
    case 0x800F6324u: goto label_800F6324;
    case 0x800F6328u: goto label_800F6328;
    case 0x800F632Cu: goto label_800F632C;
    case 0x800F6330u: goto label_800F6330;
    case 0x800F6334u: goto label_800F6334;
    case 0x800F6338u: goto label_800F6338;
    case 0x800F633Cu: goto label_800F633C;
    case 0x800F6340u: goto label_800F6340;
    case 0x800F6344u: goto label_800F6344;
    case 0x800F6348u: goto label_800F6348;
    case 0x800F634Cu: goto label_800F634C;
    case 0x800F6350u: goto label_800F6350;
    case 0x800F6354u: goto label_800F6354;
    case 0x800F6358u: goto label_800F6358;
    case 0x800F635Cu: goto label_800F635C;
    case 0x800F6360u: goto label_800F6360;
    case 0x800F6364u: goto label_800F6364;
    case 0x800F6368u: goto label_800F6368;
    case 0x800F636Cu: goto label_800F636C;
    case 0x800F6370u: goto label_800F6370;
    case 0x800F6374u: goto label_800F6374;
    case 0x800F6378u: goto label_800F6378;
    case 0x800F637Cu: goto label_800F637C;
    case 0x800F6380u: goto label_800F6380;
    case 0x800F6384u: goto label_800F6384;
    case 0x800F6388u: goto label_800F6388;
    case 0x800F638Cu: goto label_800F638C;
    case 0x800F6390u: goto label_800F6390;
    case 0x800F6394u: goto label_800F6394;
    case 0x800F6398u: goto label_800F6398;
    case 0x800F639Cu: goto label_800F639C;
    case 0x800F63A0u: goto label_800F63A0;
    case 0x800F63A4u: goto label_800F63A4;
    case 0x800F63A8u: goto label_800F63A8;
    case 0x800F63ACu: goto label_800F63AC;
    case 0x800F63B0u: goto label_800F63B0;
    case 0x800F63B4u: goto label_800F63B4;
    case 0x800F63B8u: goto label_800F63B8;
    case 0x800F63BCu: goto label_800F63BC;
    case 0x800F63C0u: goto label_800F63C0;
    case 0x800F63C4u: goto label_800F63C4;
    case 0x800F63C8u: goto label_800F63C8;
    case 0x800F63CCu: goto label_800F63CC;
    case 0x800F63D0u: goto label_800F63D0;
    case 0x800F63D4u: goto label_800F63D4;
    case 0x800F63D8u: goto label_800F63D8;
    case 0x800F63DCu: goto label_800F63DC;
    case 0x800F63E0u: goto label_800F63E0;
    case 0x800F63E4u: goto label_800F63E4;
    case 0x800F63E8u: goto label_800F63E8;
    case 0x800F63ECu: goto label_800F63EC;
    case 0x800F63F0u: goto label_800F63F0;
    case 0x800F63F4u: goto label_800F63F4;
    case 0x800F63F8u: goto label_800F63F8;
    case 0x800F63FCu: goto label_800F63FC;
    case 0x800F6400u: goto label_800F6400;
    case 0x800F6404u: goto label_800F6404;
    case 0x800F6408u: goto label_800F6408;
    case 0x800F640Cu: goto label_800F640C;
    case 0x800F6410u: goto label_800F6410;
    case 0x800F6414u: goto label_800F6414;
    case 0x800F6418u: goto label_800F6418;
    case 0x800F641Cu: goto label_800F641C;
    case 0x800F6420u: goto label_800F6420;
    case 0x800F6424u: goto label_800F6424;
    case 0x800F6428u: goto label_800F6428;
    case 0x800F642Cu: goto label_800F642C;
    case 0x800F6430u: goto label_800F6430;
    case 0x800F6434u: goto label_800F6434;
    case 0x800F6438u: goto label_800F6438;
    case 0x800F643Cu: goto label_800F643C;
    case 0x800F6440u: goto label_800F6440;
    case 0x800F6444u: goto label_800F6444;
    case 0x800F6448u: goto label_800F6448;
    case 0x800F644Cu: goto label_800F644C;
    case 0x800F6450u: goto label_800F6450;
    case 0x800F6454u: goto label_800F6454;
    case 0x800F6458u: goto label_800F6458;
    case 0x800F645Cu: goto label_800F645C;
    case 0x800F6460u: goto label_800F6460;
    case 0x800F6464u: goto label_800F6464;
    case 0x800F6468u: goto label_800F6468;
    case 0x800F646Cu: goto label_800F646C;
    case 0x800F6470u: goto label_800F6470;
    case 0x800F6474u: goto label_800F6474;
    case 0x800F6478u: goto label_800F6478;
    case 0x800F647Cu: goto label_800F647C;
    case 0x800F6480u: goto label_800F6480;
    case 0x800F6484u: goto label_800F6484;
    case 0x800F6488u: goto label_800F6488;
    case 0x800F648Cu: goto label_800F648C;
    case 0x800F6490u: goto label_800F6490;
    case 0x800F6494u: goto label_800F6494;
    case 0x800F6498u: goto label_800F6498;
    case 0x800F649Cu: goto label_800F649C;
    case 0x800F64A0u: goto label_800F64A0;
    case 0x800F64A4u: goto label_800F64A4;
    case 0x800F64A8u: goto label_800F64A8;
    case 0x800F64ACu: goto label_800F64AC;
    case 0x800F64B0u: goto label_800F64B0;
    case 0x800F64B4u: goto label_800F64B4;
    case 0x800F64B8u: goto label_800F64B8;
    case 0x800F64BCu: goto label_800F64BC;
    case 0x800F64C0u: goto label_800F64C0;
    case 0x800F64C4u: goto label_800F64C4;
    case 0x800F64C8u: goto label_800F64C8;
    case 0x800F64CCu: goto label_800F64CC;
    case 0x800F64D0u: goto label_800F64D0;
    case 0x800F64D4u: goto label_800F64D4;
    case 0x800F64D8u: goto label_800F64D8;
    case 0x800F64DCu: goto label_800F64DC;
    case 0x800F64E0u: goto label_800F64E0;
    case 0x800F64E4u: goto label_800F64E4;
    case 0x800F64E8u: goto label_800F64E8;
    case 0x800F64ECu: goto label_800F64EC;
    case 0x800F64F0u: goto label_800F64F0;
    case 0x800F64F4u: goto label_800F64F4;
    case 0x800F64F8u: goto label_800F64F8;
    case 0x800F64FCu: goto label_800F64FC;
    case 0x800F6500u: goto label_800F6500;
    case 0x800F6504u: goto label_800F6504;
    case 0x800F6508u: goto label_800F6508;
    case 0x800F650Cu: goto label_800F650C;
    case 0x800F6510u: goto label_800F6510;
    case 0x800F6514u: goto label_800F6514;
    case 0x800F6518u: goto label_800F6518;
    case 0x800F651Cu: goto label_800F651C;
    case 0x800F6520u: goto label_800F6520;
    case 0x800F6524u: goto label_800F6524;
    case 0x800F6528u: goto label_800F6528;
    case 0x800F652Cu: goto label_800F652C;
    case 0x800F6530u: goto label_800F6530;
    case 0x800F6534u: goto label_800F6534;
    case 0x800F6538u: goto label_800F6538;
    case 0x800F653Cu: goto label_800F653C;
    case 0x800F6540u: goto label_800F6540;
    case 0x800F6544u: goto label_800F6544;
    case 0x800F6548u: goto label_800F6548;
    case 0x800F654Cu: goto label_800F654C;
    case 0x800F6550u: goto label_800F6550;
    case 0x800F6554u: goto label_800F6554;
    case 0x800F6558u: goto label_800F6558;
    case 0x800F655Cu: goto label_800F655C;
    case 0x800F6560u: goto label_800F6560;
    case 0x800F6564u: goto label_800F6564;
    case 0x800F6568u: goto label_800F6568;
    case 0x800F656Cu: goto label_800F656C;
    case 0x800F6570u: goto label_800F6570;
    case 0x800F6574u: goto label_800F6574;
    case 0x800F6578u: goto label_800F6578;
    case 0x800F657Cu: goto label_800F657C;
    case 0x800F6580u: goto label_800F6580;
    case 0x800F6584u: goto label_800F6584;
    case 0x800F6588u: goto label_800F6588;
    case 0x800F658Cu: goto label_800F658C;
    case 0x800F6590u: goto label_800F6590;
    case 0x800F6594u: goto label_800F6594;
    case 0x800F6598u: goto label_800F6598;
    case 0x800F659Cu: goto label_800F659C;
    case 0x800F65A0u: goto label_800F65A0;
    case 0x800F65A4u: goto label_800F65A4;
    case 0x800F65A8u: goto label_800F65A8;
    case 0x800F65ACu: goto label_800F65AC;
    case 0x800F65B0u: goto label_800F65B0;
    case 0x800F65B4u: goto label_800F65B4;
    case 0x800F65B8u: goto label_800F65B8;
    case 0x800F65BCu: goto label_800F65BC;
    case 0x800F65C0u: goto label_800F65C0;
    case 0x800F65C4u: goto label_800F65C4;
    case 0x800F65C8u: goto label_800F65C8;
    case 0x800F65CCu: goto label_800F65CC;
    case 0x800F65D0u: goto label_800F65D0;
    case 0x800F65D4u: goto label_800F65D4;
    case 0x800F65D8u: goto label_800F65D8;
    case 0x800F65DCu: goto label_800F65DC;
    case 0x800F65E0u: goto label_800F65E0;
    case 0x800F65E4u: goto label_800F65E4;
    case 0x800F65E8u: goto label_800F65E8;
    case 0x800F65ECu: goto label_800F65EC;
    case 0x800F65F0u: goto label_800F65F0;
    case 0x800F65F4u: goto label_800F65F4;
    case 0x800F65F8u: goto label_800F65F8;
    case 0x800F65FCu: goto label_800F65FC;
    case 0x800F6600u: goto label_800F6600;
    case 0x800F6604u: goto label_800F6604;
    case 0x800F6608u: goto label_800F6608;
    case 0x800F660Cu: goto label_800F660C;
    case 0x800F6610u: goto label_800F6610;
    case 0x800F6614u: goto label_800F6614;
    case 0x800F6618u: goto label_800F6618;
    case 0x800F661Cu: goto label_800F661C;
    case 0x800F6620u: goto label_800F6620;
    case 0x800F6624u: goto label_800F6624;
    case 0x800F6628u: goto label_800F6628;
    case 0x800F662Cu: goto label_800F662C;
    case 0x800F6630u: goto label_800F6630;
    case 0x800F6634u: goto label_800F6634;
    case 0x800F6638u: goto label_800F6638;
    case 0x800F663Cu: goto label_800F663C;
    case 0x800F6640u: goto label_800F6640;
    case 0x800F6644u: goto label_800F6644;
    case 0x800F6648u: goto label_800F6648;
    case 0x800F664Cu: goto label_800F664C;
    case 0x800F6650u: goto label_800F6650;
    case 0x800F6654u: goto label_800F6654;
    case 0x800F6658u: goto label_800F6658;
    case 0x800F665Cu: goto label_800F665C;
    case 0x800F6660u: goto label_800F6660;
    case 0x800F6664u: goto label_800F6664;
    case 0x800F6668u: goto label_800F6668;
    case 0x800F666Cu: goto label_800F666C;
    case 0x800F6670u: goto label_800F6670;
    case 0x800F6674u: goto label_800F6674;
    case 0x800F6678u: goto label_800F6678;
    case 0x800F667Cu: goto label_800F667C;
    case 0x800F6680u: goto label_800F6680;
    case 0x800F6684u: goto label_800F6684;
    case 0x800F6688u: goto label_800F6688;
    case 0x800F668Cu: goto label_800F668C;
    case 0x800F6690u: goto label_800F6690;
    case 0x800F6694u: goto label_800F6694;
    case 0x800F6698u: goto label_800F6698;
    case 0x800F669Cu: goto label_800F669C;
    case 0x800F66A0u: goto label_800F66A0;
    case 0x800F66A4u: goto label_800F66A4;
    case 0x800F66A8u: goto label_800F66A8;
    case 0x800F66ACu: goto label_800F66AC;
    case 0x800F66B0u: goto label_800F66B0;
    case 0x800F66B4u: goto label_800F66B4;
    case 0x800F66B8u: goto label_800F66B8;
    case 0x800F66BCu: goto label_800F66BC;
    case 0x800F66C0u: goto label_800F66C0;
    case 0x800F66C4u: goto label_800F66C4;
    case 0x800F66C8u: goto label_800F66C8;
    case 0x800F66CCu: goto label_800F66CC;
    case 0x800F66D0u: goto label_800F66D0;
    case 0x800F66D4u: goto label_800F66D4;
    case 0x800F66D8u: goto label_800F66D8;
    case 0x800F66DCu: goto label_800F66DC;
    case 0x800F66E0u: goto label_800F66E0;
    case 0x800F66E4u: goto label_800F66E4;
    case 0x800F66E8u: goto label_800F66E8;
    case 0x800F66ECu: goto label_800F66EC;
    case 0x800F66F0u: goto label_800F66F0;
    case 0x800F66F4u: goto label_800F66F4;
    case 0x800F66F8u: goto label_800F66F8;
    case 0x800F66FCu: goto label_800F66FC;
    case 0x800F6700u: goto label_800F6700;
    case 0x800F6704u: goto label_800F6704;
    case 0x800F6708u: goto label_800F6708;
    case 0x800F670Cu: goto label_800F670C;
    case 0x800F6710u: goto label_800F6710;
    case 0x800F6714u: goto label_800F6714;
    case 0x800F6718u: goto label_800F6718;
    case 0x800F671Cu: goto label_800F671C;
    case 0x800F6720u: goto label_800F6720;
    case 0x800F6724u: goto label_800F6724;
    case 0x800F6728u: goto label_800F6728;
    case 0x800F672Cu: goto label_800F672C;
    case 0x800F6730u: goto label_800F6730;
    case 0x800F6734u: goto label_800F6734;
    case 0x800F6738u: goto label_800F6738;
    case 0x800F673Cu: goto label_800F673C;
    case 0x800F6740u: goto label_800F6740;
    case 0x800F6744u: goto label_800F6744;
    case 0x800F6748u: goto label_800F6748;
    case 0x800F674Cu: goto label_800F674C;
    case 0x800F6750u: goto label_800F6750;
    case 0x800F6754u: goto label_800F6754;
    case 0x800F6758u: goto label_800F6758;
    case 0x800F675Cu: goto label_800F675C;
    case 0x800F6760u: goto label_800F6760;
    case 0x800F6764u: goto label_800F6764;
    case 0x800F6768u: goto label_800F6768;
    case 0x800F676Cu: goto label_800F676C;
    case 0x800F6770u: goto label_800F6770;
    case 0x800F6774u: goto label_800F6774;
    case 0x800F6778u: goto label_800F6778;
    case 0x800F677Cu: goto label_800F677C;
    case 0x800F6780u: goto label_800F6780;
    case 0x800F6784u: goto label_800F6784;
    case 0x800F6788u: goto label_800F6788;
    case 0x800F678Cu: goto label_800F678C;
    case 0x800F6790u: goto label_800F6790;
    case 0x800F6794u: goto label_800F6794;
    case 0x800F6798u: goto label_800F6798;
    case 0x800F679Cu: goto label_800F679C;
    case 0x800F67A0u: goto label_800F67A0;
    case 0x800F67A4u: goto label_800F67A4;
    case 0x800F67A8u: goto label_800F67A8;
    case 0x800F67ACu: goto label_800F67AC;
    case 0x800F67B0u: goto label_800F67B0;
    case 0x800F67B4u: goto label_800F67B4;
    case 0x800F67B8u: goto label_800F67B8;
    case 0x800F67BCu: goto label_800F67BC;
    case 0x800F67C0u: goto label_800F67C0;
    case 0x800F67C4u: goto label_800F67C4;
    case 0x800F67C8u: goto label_800F67C8;
    case 0x800F67CCu: goto label_800F67CC;
    case 0x800F67D0u: goto label_800F67D0;
    case 0x800F67D4u: goto label_800F67D4;
    case 0x800F67D8u: goto label_800F67D8;
    case 0x800F67DCu: goto label_800F67DC;
    case 0x800F67E0u: goto label_800F67E0;
    case 0x800F67E4u: goto label_800F67E4;
    case 0x800F67E8u: goto label_800F67E8;
    case 0x800F67ECu: goto label_800F67EC;
    case 0x800F67F0u: goto label_800F67F0;
    case 0x800F67F4u: goto label_800F67F4;
    case 0x800F67F8u: goto label_800F67F8;
    case 0x800F67FCu: goto label_800F67FC;
    case 0x800F6800u: goto label_800F6800;
    case 0x800F6804u: goto label_800F6804;
    case 0x800F6808u: goto label_800F6808;
    case 0x800F680Cu: goto label_800F680C;
    case 0x800F6810u: goto label_800F6810;
    case 0x800F6814u: goto label_800F6814;
    case 0x800F6818u: goto label_800F6818;
    case 0x800F681Cu: goto label_800F681C;
    case 0x800F6820u: goto label_800F6820;
    case 0x800F6824u: goto label_800F6824;
    case 0x800F6828u: goto label_800F6828;
    case 0x800F682Cu: goto label_800F682C;
    case 0x800F6830u: goto label_800F6830;
    case 0x800F6834u: goto label_800F6834;
    case 0x800F6838u: goto label_800F6838;
    case 0x800F683Cu: goto label_800F683C;
    case 0x800F6840u: goto label_800F6840;
    case 0x800F6844u: goto label_800F6844;
    case 0x800F6848u: goto label_800F6848;
    case 0x800F684Cu: goto label_800F684C;
    case 0x800F6850u: goto label_800F6850;
    case 0x800F6854u: goto label_800F6854;
    case 0x800F6858u: goto label_800F6858;
    case 0x800F685Cu: goto label_800F685C;
    case 0x800F6860u: goto label_800F6860;
    case 0x800F6864u: goto label_800F6864;
    case 0x800F6868u: goto label_800F6868;
    case 0x800F686Cu: goto label_800F686C;
    case 0x800F6870u: goto label_800F6870;
    case 0x800F6874u: goto label_800F6874;
    case 0x800F6878u: goto label_800F6878;
    case 0x800F687Cu: goto label_800F687C;
    case 0x800F6880u: goto label_800F6880;
    case 0x800F6884u: goto label_800F6884;
    case 0x800F6888u: goto label_800F6888;
    case 0x800F688Cu: goto label_800F688C;
    case 0x800F6890u: goto label_800F6890;
    case 0x800F6894u: goto label_800F6894;
    case 0x800F6898u: goto label_800F6898;
    case 0x800F689Cu: goto label_800F689C;
    case 0x800F68A0u: goto label_800F68A0;
    case 0x800F68A4u: goto label_800F68A4;
    case 0x800F68A8u: goto label_800F68A8;
    case 0x800F68ACu: goto label_800F68AC;
    case 0x800F68B0u: goto label_800F68B0;
    case 0x800F68B4u: goto label_800F68B4;
    case 0x800F68B8u: goto label_800F68B8;
    case 0x800F68BCu: goto label_800F68BC;
    case 0x800F68C0u: goto label_800F68C0;
    case 0x800F68C4u: goto label_800F68C4;
    case 0x800F68C8u: goto label_800F68C8;
    case 0x800F68CCu: goto label_800F68CC;
    case 0x800F68D0u: goto label_800F68D0;
    case 0x800F68D4u: goto label_800F68D4;
    case 0x800F68D8u: goto label_800F68D8;
    case 0x800F68DCu: goto label_800F68DC;
    case 0x800F68E0u: goto label_800F68E0;
    case 0x800F68E4u: goto label_800F68E4;
    case 0x800F68E8u: goto label_800F68E8;
    case 0x800F68ECu: goto label_800F68EC;
    case 0x800F68F0u: goto label_800F68F0;
    case 0x800F68F4u: goto label_800F68F4;
    case 0x800F68F8u: goto label_800F68F8;
    case 0x800F68FCu: goto label_800F68FC;
    case 0x800F6900u: goto label_800F6900;
    case 0x800F6904u: goto label_800F6904;
    case 0x800F6908u: goto label_800F6908;
    case 0x800F690Cu: goto label_800F690C;
    case 0x800F6910u: goto label_800F6910;
    case 0x800F6914u: goto label_800F6914;
    case 0x800F6918u: goto label_800F6918;
    case 0x800F691Cu: goto label_800F691C;
    case 0x800F6920u: goto label_800F6920;
    case 0x800F6924u: goto label_800F6924;
    case 0x800F6928u: goto label_800F6928;
    case 0x800F692Cu: goto label_800F692C;
    case 0x800F6930u: goto label_800F6930;
    case 0x800F6934u: goto label_800F6934;
    case 0x800F6938u: goto label_800F6938;
    case 0x800F693Cu: goto label_800F693C;
    case 0x800F6940u: goto label_800F6940;
    case 0x800F6944u: goto label_800F6944;
    case 0x800F6948u: goto label_800F6948;
    case 0x800F694Cu: goto label_800F694C;
    case 0x800F6950u: goto label_800F6950;
    case 0x800F6954u: goto label_800F6954;
    case 0x800F6958u: goto label_800F6958;
    case 0x800F695Cu: goto label_800F695C;
    case 0x800F6960u: goto label_800F6960;
    case 0x800F6964u: goto label_800F6964;
    case 0x800F6968u: goto label_800F6968;
    case 0x800F696Cu: goto label_800F696C;
    case 0x800F6970u: goto label_800F6970;
    case 0x800F6974u: goto label_800F6974;
    case 0x800F6978u: goto label_800F6978;
    case 0x800F697Cu: goto label_800F697C;
    case 0x800F6980u: goto label_800F6980;
    case 0x800F6984u: goto label_800F6984;
    case 0x800F6988u: goto label_800F6988;
    case 0x800F698Cu: goto label_800F698C;
    case 0x800F6990u: goto label_800F6990;
    case 0x800F6994u: goto label_800F6994;
    case 0x800F6998u: goto label_800F6998;
    case 0x800F699Cu: goto label_800F699C;
    case 0x800F69A0u: goto label_800F69A0;
    case 0x800F69A4u: goto label_800F69A4;
    case 0x800F69A8u: goto label_800F69A8;
    case 0x800F69ACu: goto label_800F69AC;
    case 0x800F69B0u: goto label_800F69B0;
    case 0x800F69B4u: goto label_800F69B4;
    case 0x800F69B8u: goto label_800F69B8;
    case 0x800F69BCu: goto label_800F69BC;
    case 0x800F69C0u: goto label_800F69C0;
    case 0x800F69C4u: goto label_800F69C4;
    case 0x800F69C8u: goto label_800F69C8;
    case 0x800F69CCu: goto label_800F69CC;
    case 0x800F69D0u: goto label_800F69D0;
    case 0x800F69D4u: goto label_800F69D4;
    case 0x800F69D8u: goto label_800F69D8;
    case 0x800F69DCu: goto label_800F69DC;
    case 0x800F69E0u: goto label_800F69E0;
    case 0x800F69E4u: goto label_800F69E4;
    case 0x800F69E8u: goto label_800F69E8;
    case 0x800F69ECu: goto label_800F69EC;
    case 0x800F69F0u: goto label_800F69F0;
    case 0x800F69F4u: goto label_800F69F4;
    case 0x800F69F8u: goto label_800F69F8;
    case 0x800F69FCu: goto label_800F69FC;
    case 0x800F6A00u: goto label_800F6A00;
    case 0x800F6A04u: goto label_800F6A04;
    case 0x800F6A08u: goto label_800F6A08;
    case 0x800F6A0Cu: goto label_800F6A0C;
    case 0x800F6A10u: goto label_800F6A10;
    case 0x800F6A14u: goto label_800F6A14;
    case 0x800F6A18u: goto label_800F6A18;
    case 0x800F6A1Cu: goto label_800F6A1C;
    case 0x800F6A20u: goto label_800F6A20;
    case 0x800F6A24u: goto label_800F6A24;
    case 0x800F6A28u: goto label_800F6A28;
    case 0x800F6A2Cu: goto label_800F6A2C;
    case 0x800F6A30u: goto label_800F6A30;
    case 0x800F6A34u: goto label_800F6A34;
    case 0x800F6A38u: goto label_800F6A38;
    case 0x800F6A3Cu: goto label_800F6A3C;
    case 0x800F6A40u: goto label_800F6A40;
    case 0x800F6A44u: goto label_800F6A44;
    case 0x800F6A48u: goto label_800F6A48;
    case 0x800F6A4Cu: goto label_800F6A4C;
    case 0x800F6A50u: goto label_800F6A50;
    case 0x800F6A54u: goto label_800F6A54;
    case 0x800F6A58u: goto label_800F6A58;
    case 0x800F6A5Cu: goto label_800F6A5C;
    case 0x800F6A60u: goto label_800F6A60;
    case 0x800F6A64u: goto label_800F6A64;
    case 0x800F6A68u: goto label_800F6A68;
    case 0x800F6A6Cu: goto label_800F6A6C;
    case 0x800F6A70u: goto label_800F6A70;
    case 0x800F6A74u: goto label_800F6A74;
    case 0x800F6A78u: goto label_800F6A78;
    case 0x800F6A7Cu: goto label_800F6A7C;
    case 0x800F6A80u: goto label_800F6A80;
    case 0x800F6A84u: goto label_800F6A84;
    case 0x800F6A88u: goto label_800F6A88;
    case 0x800F6A8Cu: goto label_800F6A8C;
    case 0x800F6A90u: goto label_800F6A90;
    case 0x800F6A94u: goto label_800F6A94;
    case 0x800F6A98u: goto label_800F6A98;
    case 0x800F6A9Cu: goto label_800F6A9C;
    case 0x800F6AA0u: goto label_800F6AA0;
    case 0x800F6AA4u: goto label_800F6AA4;
    case 0x800F6AA8u: goto label_800F6AA8;
    case 0x800F6AACu: goto label_800F6AAC;
    case 0x800F6AB0u: goto label_800F6AB0;
    case 0x800F6AB4u: goto label_800F6AB4;
    case 0x800F6AB8u: goto label_800F6AB8;
    case 0x800F6ABCu: goto label_800F6ABC;
    case 0x800F6AC0u: goto label_800F6AC0;
    case 0x800F6AC4u: goto label_800F6AC4;
    case 0x800F6AC8u: goto label_800F6AC8;
    case 0x800F6ACCu: goto label_800F6ACC;
    case 0x800F6AD0u: goto label_800F6AD0;
    case 0x800F6AD4u: goto label_800F6AD4;
    case 0x800F6AD8u: goto label_800F6AD8;
    case 0x800F6ADCu: goto label_800F6ADC;
    case 0x800F6AE0u: goto label_800F6AE0;
    case 0x800F6AE4u: goto label_800F6AE4;
    case 0x800F6AE8u: goto label_800F6AE8;
    case 0x800F6AECu: goto label_800F6AEC;
    case 0x800F6AF0u: goto label_800F6AF0;
    case 0x800F6AF4u: goto label_800F6AF4;
    case 0x800F6AF8u: goto label_800F6AF8;
    case 0x800F6AFCu: goto label_800F6AFC;
    case 0x800F6B00u: goto label_800F6B00;
    case 0x800F6B04u: goto label_800F6B04;
    case 0x800F6B08u: goto label_800F6B08;
    case 0x800F6B0Cu: goto label_800F6B0C;
    case 0x800F6B10u: goto label_800F6B10;
    case 0x800F6B14u: goto label_800F6B14;
    case 0x800F6B18u: goto label_800F6B18;
    case 0x800F6B1Cu: goto label_800F6B1C;
    case 0x800F6B20u: goto label_800F6B20;
    case 0x800F6B24u: goto label_800F6B24;
    case 0x800F6B28u: goto label_800F6B28;
    case 0x800F6B2Cu: goto label_800F6B2C;
    case 0x800F6B30u: goto label_800F6B30;
    case 0x800F6B34u: goto label_800F6B34;
    case 0x800F6B38u: goto label_800F6B38;
    case 0x800F6B3Cu: goto label_800F6B3C;
    case 0x800F6B40u: goto label_800F6B40;
    case 0x800F6B44u: goto label_800F6B44;
    case 0x800F6B48u: goto label_800F6B48;
    case 0x800F6B4Cu: goto label_800F6B4C;
    case 0x800F6B50u: goto label_800F6B50;
    case 0x800F6B54u: goto label_800F6B54;
    case 0x800F6B58u: goto label_800F6B58;
    case 0x800F6B5Cu: goto label_800F6B5C;
    case 0x800F6B60u: goto label_800F6B60;
    case 0x800F6B64u: goto label_800F6B64;
    case 0x800F6B68u: goto label_800F6B68;
    case 0x800F6B6Cu: goto label_800F6B6C;
    case 0x800F6B70u: goto label_800F6B70;
    case 0x800F6B74u: goto label_800F6B74;
    case 0x800F6B78u: goto label_800F6B78;
    case 0x800F6B7Cu: goto label_800F6B7C;
    case 0x800F6B80u: goto label_800F6B80;
    case 0x800F6B84u: goto label_800F6B84;
    case 0x800F6B88u: goto label_800F6B88;
    case 0x800F6B8Cu: goto label_800F6B8C;
    case 0x800F6B90u: goto label_800F6B90;
    case 0x800F6B94u: goto label_800F6B94;
    case 0x800F6B98u: goto label_800F6B98;
    case 0x800F6B9Cu: goto label_800F6B9C;
    case 0x800F6BA0u: goto label_800F6BA0;
    case 0x800F6BA4u: goto label_800F6BA4;
    case 0x800F6BA8u: goto label_800F6BA8;
    case 0x800F6BACu: goto label_800F6BAC;
    case 0x800F6BB0u: goto label_800F6BB0;
    case 0x800F6BB4u: goto label_800F6BB4;
    case 0x800F6BB8u: goto label_800F6BB8;
    case 0x800F6BBCu: goto label_800F6BBC;
    case 0x800F6BC0u: goto label_800F6BC0;
    case 0x800F6BC4u: goto label_800F6BC4;
    case 0x800F6BC8u: goto label_800F6BC8;
    case 0x800F6BCCu: goto label_800F6BCC;
    case 0x800F6BD0u: goto label_800F6BD0;
    case 0x800F6BD4u: goto label_800F6BD4;
    case 0x800F6BD8u: goto label_800F6BD8;
    case 0x800F6BDCu: goto label_800F6BDC;
    case 0x800F6BE0u: goto label_800F6BE0;
    case 0x800F6BE4u: goto label_800F6BE4;
    case 0x800F6BE8u: goto label_800F6BE8;
    case 0x800F6BECu: goto label_800F6BEC;
    case 0x800F6BF0u: goto label_800F6BF0;
    case 0x800F6BF4u: goto label_800F6BF4;
    case 0x800F6BF8u: goto label_800F6BF8;
    case 0x800F6BFCu: goto label_800F6BFC;
    case 0x800F6C00u: goto label_800F6C00;
    case 0x800F6C04u: goto label_800F6C04;
    case 0x800F6C08u: goto label_800F6C08;
    case 0x800F6C0Cu: goto label_800F6C0C;
    case 0x800F6C10u: goto label_800F6C10;
    case 0x800F6C14u: goto label_800F6C14;
    case 0x800F6C18u: goto label_800F6C18;
    case 0x800F6C1Cu: goto label_800F6C1C;
    case 0x800F6C20u: goto label_800F6C20;
    case 0x800F6C24u: goto label_800F6C24;
    case 0x800F6C28u: goto label_800F6C28;
    case 0x800F6C2Cu: goto label_800F6C2C;
    case 0x800F6C30u: goto label_800F6C30;
    case 0x800F6C34u: goto label_800F6C34;
    case 0x800F6C38u: goto label_800F6C38;
    case 0x800F6C3Cu: goto label_800F6C3C;
    case 0x800F6C40u: goto label_800F6C40;
    case 0x800F6C44u: goto label_800F6C44;
    case 0x800F6C48u: goto label_800F6C48;
    case 0x800F6C4Cu: goto label_800F6C4C;
    case 0x800F6C50u: goto label_800F6C50;
    case 0x800F6C54u: goto label_800F6C54;
    case 0x800F6C58u: goto label_800F6C58;
    case 0x800F6C5Cu: goto label_800F6C5C;
    case 0x800F6C60u: goto label_800F6C60;
    case 0x800F6C64u: goto label_800F6C64;
    case 0x800F6C68u: goto label_800F6C68;
    case 0x800F6C6Cu: goto label_800F6C6C;
    case 0x800F6C70u: goto label_800F6C70;
    case 0x800F6C74u: goto label_800F6C74;
    case 0x800F6C78u: goto label_800F6C78;
    case 0x800F6C7Cu: goto label_800F6C7C;
    case 0x800F6C80u: goto label_800F6C80;
    case 0x800F6C84u: goto label_800F6C84;
    case 0x800F6C88u: goto label_800F6C88;
    case 0x800F6C8Cu: goto label_800F6C8C;
    case 0x800F6C90u: goto label_800F6C90;
    case 0x800F6C94u: goto label_800F6C94;
    case 0x800F6C98u: goto label_800F6C98;
    case 0x800F6C9Cu: goto label_800F6C9C;
    case 0x800F6CA0u: goto label_800F6CA0;
    case 0x800F6CA4u: goto label_800F6CA4;
    case 0x800F6CA8u: goto label_800F6CA8;
    case 0x800F6CACu: goto label_800F6CAC;
    case 0x800F6CB0u: goto label_800F6CB0;
    case 0x800F6CB4u: goto label_800F6CB4;
    case 0x800F6CB8u: goto label_800F6CB8;
    case 0x800F6CBCu: goto label_800F6CBC;
    case 0x800F6CC0u: goto label_800F6CC0;
    case 0x800F6CC4u: goto label_800F6CC4;
    case 0x800F6CC8u: goto label_800F6CC8;
    case 0x800F6CCCu: goto label_800F6CCC;
    case 0x800F6CD0u: goto label_800F6CD0;
    case 0x800F6CD4u: goto label_800F6CD4;
    case 0x800F6CD8u: goto label_800F6CD8;
    case 0x800F6CDCu: goto label_800F6CDC;
    case 0x800F6CE0u: goto label_800F6CE0;
    case 0x800F6CE4u: goto label_800F6CE4;
    case 0x800F6CE8u: goto label_800F6CE8;
    case 0x800F6CECu: goto label_800F6CEC;
    case 0x800F6CF0u: goto label_800F6CF0;
    case 0x800F6CF4u: goto label_800F6CF4;
    case 0x800F6CF8u: goto label_800F6CF8;
    case 0x800F6CFCu: goto label_800F6CFC;
    case 0x800F6D00u: goto label_800F6D00;
    case 0x800F6D04u: goto label_800F6D04;
    case 0x800F6D08u: goto label_800F6D08;
    case 0x800F6D0Cu: goto label_800F6D0C;
    case 0x800F6D10u: goto label_800F6D10;
    case 0x800F6D14u: goto label_800F6D14;
    case 0x800F6D18u: goto label_800F6D18;
    case 0x800F6D1Cu: goto label_800F6D1C;
    case 0x800F6D20u: goto label_800F6D20;
    case 0x800F6D24u: goto label_800F6D24;
    case 0x800F6D28u: goto label_800F6D28;
    case 0x800F6D2Cu: goto label_800F6D2C;
    case 0x800F6D30u: goto label_800F6D30;
    case 0x800F6D34u: goto label_800F6D34;
    case 0x800F6D38u: goto label_800F6D38;
    case 0x800F6D3Cu: goto label_800F6D3C;
    case 0x800F6D40u: goto label_800F6D40;
    case 0x800F6D44u: goto label_800F6D44;
    case 0x800F6D48u: goto label_800F6D48;
    case 0x800F6D4Cu: goto label_800F6D4C;
    case 0x800F6D50u: goto label_800F6D50;
    case 0x800F6D54u: goto label_800F6D54;
    case 0x800F6D58u: goto label_800F6D58;
    case 0x800F6D5Cu: goto label_800F6D5C;
    case 0x800F6D60u: goto label_800F6D60;
    case 0x800F6D64u: goto label_800F6D64;
    case 0x800F6D68u: goto label_800F6D68;
    case 0x800F6D6Cu: goto label_800F6D6C;
    case 0x800F6D70u: goto label_800F6D70;
    case 0x800F6D74u: goto label_800F6D74;
    case 0x800F6D78u: goto label_800F6D78;
    case 0x800F6D7Cu: goto label_800F6D7C;
    case 0x800F6D80u: goto label_800F6D80;
    case 0x800F6D84u: goto label_800F6D84;
    case 0x800F6D88u: goto label_800F6D88;
    case 0x800F6D8Cu: goto label_800F6D8C;
    case 0x800F6D90u: goto label_800F6D90;
    case 0x800F6D94u: goto label_800F6D94;
    case 0x800F6D98u: goto label_800F6D98;
    case 0x800F6D9Cu: goto label_800F6D9C;
    case 0x800F6DA0u: goto label_800F6DA0;
    case 0x800F6DA4u: goto label_800F6DA4;
    case 0x800F6DA8u: goto label_800F6DA8;
    case 0x800F6DACu: goto label_800F6DAC;
    case 0x800F6DB0u: goto label_800F6DB0;
    case 0x800F6DB4u: goto label_800F6DB4;
    case 0x800F6DB8u: goto label_800F6DB8;
    case 0x800F6DBCu: goto label_800F6DBC;
    case 0x800F6DC0u: goto label_800F6DC0;
    case 0x800F6DC4u: goto label_800F6DC4;
    case 0x800F6DC8u: goto label_800F6DC8;
    case 0x800F6DCCu: goto label_800F6DCC;
    case 0x800F6DD0u: goto label_800F6DD0;
    case 0x800F6DD4u: goto label_800F6DD4;
    case 0x800F6DD8u: goto label_800F6DD8;
    case 0x800F6DDCu: goto label_800F6DDC;
    case 0x800F6DE0u: goto label_800F6DE0;
    case 0x800F6DE4u: goto label_800F6DE4;
    case 0x800F6DE8u: goto label_800F6DE8;
    case 0x800F6DECu: goto label_800F6DEC;
    case 0x800F6DF0u: goto label_800F6DF0;
    case 0x800F6DF4u: goto label_800F6DF4;
    case 0x800F6DF8u: goto label_800F6DF8;
    case 0x800F6DFCu: goto label_800F6DFC;
    case 0x800F6E00u: goto label_800F6E00;
    case 0x800F6E04u: goto label_800F6E04;
    case 0x800F6E08u: goto label_800F6E08;
    case 0x800F6E0Cu: goto label_800F6E0C;
    case 0x800F6E10u: goto label_800F6E10;
    case 0x800F6E14u: goto label_800F6E14;
    case 0x800F6E18u: goto label_800F6E18;
    case 0x800F6E1Cu: goto label_800F6E1C;
    case 0x800F6E20u: goto label_800F6E20;
    case 0x800F6E24u: goto label_800F6E24;
    case 0x800F6E28u: goto label_800F6E28;
    case 0x800F6E2Cu: goto label_800F6E2C;
    case 0x800F6E30u: goto label_800F6E30;
    case 0x800F6E34u: goto label_800F6E34;
    case 0x800F6E38u: goto label_800F6E38;
    case 0x800F6E3Cu: goto label_800F6E3C;
    case 0x800F6E40u: goto label_800F6E40;
    case 0x800F6E44u: goto label_800F6E44;
    case 0x800F6E48u: goto label_800F6E48;
    case 0x800F6E4Cu: goto label_800F6E4C;
    case 0x800F6E50u: goto label_800F6E50;
    case 0x800F6E54u: goto label_800F6E54;
    case 0x800F6E58u: goto label_800F6E58;
    case 0x800F6E5Cu: goto label_800F6E5C;
    case 0x800F6E60u: goto label_800F6E60;
    case 0x800F6E64u: goto label_800F6E64;
    case 0x800F6E68u: goto label_800F6E68;
    case 0x800F6E6Cu: goto label_800F6E6C;
    case 0x800F6E70u: goto label_800F6E70;
    case 0x800F6E74u: goto label_800F6E74;
    case 0x800F6E78u: goto label_800F6E78;
    case 0x800F6E7Cu: goto label_800F6E7C;
    case 0x800F6E80u: goto label_800F6E80;
    case 0x800F6E84u: goto label_800F6E84;
    case 0x800F6E88u: goto label_800F6E88;
    case 0x800F6E8Cu: goto label_800F6E8C;
    case 0x800F6E90u: goto label_800F6E90;
    case 0x800F6E94u: goto label_800F6E94;
    case 0x800F6E98u: goto label_800F6E98;
    case 0x800F6E9Cu: goto label_800F6E9C;
    case 0x800F6EA0u: goto label_800F6EA0;
    case 0x800F6EA4u: goto label_800F6EA4;
    case 0x800F6EA8u: goto label_800F6EA8;
    case 0x800F6EACu: goto label_800F6EAC;
    case 0x800F6EB0u: goto label_800F6EB0;
    case 0x800F6EB4u: goto label_800F6EB4;
    case 0x800F6EB8u: goto label_800F6EB8;
    case 0x800F6EBCu: goto label_800F6EBC;
    case 0x800F6EC0u: goto label_800F6EC0;
    case 0x800F6EC4u: goto label_800F6EC4;
    case 0x800F6EC8u: goto label_800F6EC8;
    case 0x800F6ECCu: goto label_800F6ECC;
    case 0x800F6ED0u: goto label_800F6ED0;
    case 0x800F6ED4u: goto label_800F6ED4;
    case 0x800F6ED8u: goto label_800F6ED8;
    case 0x800F6EDCu: goto label_800F6EDC;
    case 0x800F6EE0u: goto label_800F6EE0;
    case 0x800F6EE4u: goto label_800F6EE4;
    case 0x800F6EE8u: goto label_800F6EE8;
    case 0x800F6EECu: goto label_800F6EEC;
    case 0x800F6EF0u: goto label_800F6EF0;
    case 0x800F6EF4u: goto label_800F6EF4;
    case 0x800F6EF8u: goto label_800F6EF8;
    case 0x800F6EFCu: goto label_800F6EFC;
    case 0x800F6F00u: goto label_800F6F00;
    case 0x800F6F04u: goto label_800F6F04;
    case 0x800F6F08u: goto label_800F6F08;
    case 0x800F6F0Cu: goto label_800F6F0C;
    case 0x800F6F10u: goto label_800F6F10;
    case 0x800F6F14u: goto label_800F6F14;
    case 0x800F6F18u: goto label_800F6F18;
    case 0x800F6F1Cu: goto label_800F6F1C;
    case 0x800F6F20u: goto label_800F6F20;
    case 0x800F6F24u: goto label_800F6F24;
    case 0x800F6F28u: goto label_800F6F28;
    case 0x800F6F2Cu: goto label_800F6F2C;
    case 0x800F6F30u: goto label_800F6F30;
    case 0x800F6F34u: goto label_800F6F34;
    case 0x800F6F38u: goto label_800F6F38;
    case 0x800F6F3Cu: goto label_800F6F3C;
    case 0x800F6F40u: goto label_800F6F40;
    case 0x800F6F44u: goto label_800F6F44;
    case 0x800F6F48u: goto label_800F6F48;
    case 0x800F6F4Cu: goto label_800F6F4C;
    case 0x800F6F50u: goto label_800F6F50;
    case 0x800F6F54u: goto label_800F6F54;
    case 0x800F6F58u: goto label_800F6F58;
    case 0x800F6F5Cu: goto label_800F6F5C;
    case 0x800F6F60u: goto label_800F6F60;
    case 0x800F6F64u: goto label_800F6F64;
    case 0x800F6F68u: goto label_800F6F68;
    case 0x800F6F6Cu: goto label_800F6F6C;
    case 0x800F6F70u: goto label_800F6F70;
    case 0x800F6F74u: goto label_800F6F74;
    case 0x800F6F78u: goto label_800F6F78;
    case 0x800F6F7Cu: goto label_800F6F7C;
    case 0x800F6F80u: goto label_800F6F80;
    case 0x800F6F84u: goto label_800F6F84;
    case 0x800F6F88u: goto label_800F6F88;
    case 0x800F6F8Cu: goto label_800F6F8C;
    case 0x800F6F90u: goto label_800F6F90;
    case 0x800F6F94u: goto label_800F6F94;
    case 0x800F6F98u: goto label_800F6F98;
    case 0x800F6F9Cu: goto label_800F6F9C;
    case 0x800F6FA0u: goto label_800F6FA0;
    case 0x800F6FA4u: goto label_800F6FA4;
    case 0x800F6FA8u: goto label_800F6FA8;
    case 0x800F6FACu: goto label_800F6FAC;
    case 0x800F6FB0u: goto label_800F6FB0;
    case 0x800F6FB4u: goto label_800F6FB4;
    case 0x800F6FB8u: goto label_800F6FB8;
    case 0x800F6FBCu: goto label_800F6FBC;
    case 0x800F6FC0u: goto label_800F6FC0;
    case 0x800F6FC4u: goto label_800F6FC4;
    case 0x800F6FC8u: goto label_800F6FC8;
    case 0x800F6FCCu: goto label_800F6FCC;
    case 0x800F6FD0u: goto label_800F6FD0;
    case 0x800F6FD4u: goto label_800F6FD4;
    case 0x800F6FD8u: goto label_800F6FD8;
    case 0x800F6FDCu: goto label_800F6FDC;
    case 0x800F6FE0u: goto label_800F6FE0;
    case 0x800F6FE4u: goto label_800F6FE4;
    case 0x800F6FE8u: goto label_800F6FE8;
    case 0x800F6FECu: goto label_800F6FEC;
    case 0x800F6FF0u: goto label_800F6FF0;
    case 0x800F6FF4u: goto label_800F6FF4;
    case 0x800F6FF8u: goto label_800F6FF8;
    case 0x800F6FFCu: goto label_800F6FFC;
    case 0x800F7000u: goto label_800F7000;
    case 0x800F7004u: goto label_800F7004;
    case 0x800F7008u: goto label_800F7008;
    case 0x800F700Cu: goto label_800F700C;
    case 0x800F7010u: goto label_800F7010;
    case 0x800F7014u: goto label_800F7014;
    case 0x800F7018u: goto label_800F7018;
    case 0x800F701Cu: goto label_800F701C;
    case 0x800F7020u: goto label_800F7020;
    case 0x800F7024u: goto label_800F7024;
    case 0x800F7028u: goto label_800F7028;
    case 0x800F702Cu: goto label_800F702C;
    case 0x800F7030u: goto label_800F7030;
    case 0x800F7034u: goto label_800F7034;
    case 0x800F7038u: goto label_800F7038;
    case 0x800F703Cu: goto label_800F703C;
    case 0x800F7040u: goto label_800F7040;
    case 0x800F7044u: goto label_800F7044;
    case 0x800F7048u: goto label_800F7048;
    case 0x800F704Cu: goto label_800F704C;
    case 0x800F7050u: goto label_800F7050;
    case 0x800F7054u: goto label_800F7054;
    case 0x800F7058u: goto label_800F7058;
    case 0x800F705Cu: goto label_800F705C;
    case 0x800F7060u: goto label_800F7060;
    case 0x800F7064u: goto label_800F7064;
    case 0x800F7068u: goto label_800F7068;
    case 0x800F706Cu: goto label_800F706C;
    case 0x800F7070u: goto label_800F7070;
    case 0x800F7074u: goto label_800F7074;
    case 0x800F7078u: goto label_800F7078;
    case 0x800F707Cu: goto label_800F707C;
    case 0x800F7080u: goto label_800F7080;
    case 0x800F7084u: goto label_800F7084;
    case 0x800F7088u: goto label_800F7088;
    case 0x800F708Cu: goto label_800F708C;
    case 0x800F7090u: goto label_800F7090;
    case 0x800F7094u: goto label_800F7094;
    case 0x800F7098u: goto label_800F7098;
    case 0x800F709Cu: goto label_800F709C;
    case 0x800F70A0u: goto label_800F70A0;
    case 0x800F70A4u: goto label_800F70A4;
    case 0x800F70A8u: goto label_800F70A8;
    case 0x800F70ACu: goto label_800F70AC;
    case 0x800F70B0u: goto label_800F70B0;
    case 0x800F70B4u: goto label_800F70B4;
    case 0x800F70B8u: goto label_800F70B8;
    case 0x800F70BCu: goto label_800F70BC;
    case 0x800F70C0u: goto label_800F70C0;
    case 0x800F70C4u: goto label_800F70C4;
    case 0x800F70C8u: goto label_800F70C8;
    case 0x800F70CCu: goto label_800F70CC;
    case 0x800F70D0u: goto label_800F70D0;
    case 0x800F70D4u: goto label_800F70D4;
    case 0x800F70D8u: goto label_800F70D8;
    case 0x800F70DCu: goto label_800F70DC;
    case 0x800F70E0u: goto label_800F70E0;
    case 0x800F70E4u: goto label_800F70E4;
    case 0x800F70E8u: goto label_800F70E8;
    case 0x800F70ECu: goto label_800F70EC;
    case 0x800F70F0u: goto label_800F70F0;
    case 0x800F70F4u: goto label_800F70F4;
    case 0x800F70F8u: goto label_800F70F8;
    case 0x800F70FCu: goto label_800F70FC;
    case 0x800F7100u: goto label_800F7100;
    case 0x800F7104u: goto label_800F7104;
    case 0x800F7108u: goto label_800F7108;
    case 0x800F710Cu: goto label_800F710C;
    case 0x800F7110u: goto label_800F7110;
    case 0x800F7114u: goto label_800F7114;
    case 0x800F7118u: goto label_800F7118;
    case 0x800F711Cu: goto label_800F711C;
    case 0x800F7120u: goto label_800F7120;
    case 0x800F7124u: goto label_800F7124;
    case 0x800F7128u: goto label_800F7128;
    case 0x800F712Cu: goto label_800F712C;
    case 0x800F7130u: goto label_800F7130;
    case 0x800F7134u: goto label_800F7134;
    case 0x800F7138u: goto label_800F7138;
    case 0x800F713Cu: goto label_800F713C;
    case 0x800F7140u: goto label_800F7140;
    case 0x800F7144u: goto label_800F7144;
    case 0x800F7148u: goto label_800F7148;
    case 0x800F714Cu: goto label_800F714C;
    case 0x800F7150u: goto label_800F7150;
    case 0x800F7154u: goto label_800F7154;
    case 0x800F7158u: goto label_800F7158;
    case 0x800F715Cu: goto label_800F715C;
    case 0x800F7160u: goto label_800F7160;
    case 0x800F7164u: goto label_800F7164;
    case 0x800F7168u: goto label_800F7168;
    case 0x800F716Cu: goto label_800F716C;
    case 0x800F7170u: goto label_800F7170;
    case 0x800F7174u: goto label_800F7174;
    case 0x800F7178u: goto label_800F7178;
    case 0x800F717Cu: goto label_800F717C;
    case 0x800F7180u: goto label_800F7180;
    case 0x800F7184u: goto label_800F7184;
    case 0x800F7188u: goto label_800F7188;
    case 0x800F718Cu: goto label_800F718C;
    case 0x800F7190u: goto label_800F7190;
    case 0x800F7194u: goto label_800F7194;
    case 0x800F7198u: goto label_800F7198;
    case 0x800F719Cu: goto label_800F719C;
    case 0x800F71A0u: goto label_800F71A0;
    case 0x800F71A4u: goto label_800F71A4;
    case 0x800F71A8u: goto label_800F71A8;
    case 0x800F71ACu: goto label_800F71AC;
    case 0x800F71B0u: goto label_800F71B0;
    case 0x800F71B4u: goto label_800F71B4;
    case 0x800F71B8u: goto label_800F71B8;
    case 0x800F71BCu: goto label_800F71BC;
    case 0x800F71C0u: goto label_800F71C0;
    case 0x800F71C4u: goto label_800F71C4;
    case 0x800F71C8u: goto label_800F71C8;
    case 0x800F71CCu: goto label_800F71CC;
    case 0x800F71D0u: goto label_800F71D0;
    case 0x800F71D4u: goto label_800F71D4;
    case 0x800F71D8u: goto label_800F71D8;
    case 0x800F71DCu: goto label_800F71DC;
    case 0x800F71E0u: goto label_800F71E0;
    case 0x800F71E4u: goto label_800F71E4;
    case 0x800F71E8u: goto label_800F71E8;
    case 0x800F71ECu: goto label_800F71EC;
    case 0x800F71F0u: goto label_800F71F0;
    case 0x800F71F4u: goto label_800F71F4;
    case 0x800F71F8u: goto label_800F71F8;
    case 0x800F71FCu: goto label_800F71FC;
    case 0x800F7200u: goto label_800F7200;
    case 0x800F7204u: goto label_800F7204;
    case 0x800F7208u: goto label_800F7208;
    case 0x800F720Cu: goto label_800F720C;
    case 0x800F7210u: goto label_800F7210;
    case 0x800F7214u: goto label_800F7214;
    case 0x800F7218u: goto label_800F7218;
    case 0x800F721Cu: goto label_800F721C;
    case 0x800F7220u: goto label_800F7220;
    case 0x800F7224u: goto label_800F7224;
    case 0x800F7228u: goto label_800F7228;
    case 0x800F722Cu: goto label_800F722C;
    case 0x800F7230u: goto label_800F7230;
    case 0x800F7234u: goto label_800F7234;
    case 0x800F7238u: goto label_800F7238;
    case 0x800F723Cu: goto label_800F723C;
    case 0x800F7240u: goto label_800F7240;
    case 0x800F7244u: goto label_800F7244;
    case 0x800F7248u: goto label_800F7248;
    case 0x800F724Cu: goto label_800F724C;
    case 0x800F7250u: goto label_800F7250;
    case 0x800F7254u: goto label_800F7254;
    case 0x800F7258u: goto label_800F7258;
    case 0x800F725Cu: goto label_800F725C;
    case 0x800F7260u: goto label_800F7260;
    case 0x800F7264u: goto label_800F7264;
    case 0x800F7268u: goto label_800F7268;
    case 0x800F726Cu: goto label_800F726C;
    case 0x800F7270u: goto label_800F7270;
    case 0x800F7274u: goto label_800F7274;
    case 0x800F7278u: goto label_800F7278;
    case 0x800F727Cu: goto label_800F727C;
    case 0x800F7280u: goto label_800F7280;
    case 0x800F7284u: goto label_800F7284;
    case 0x800F7288u: goto label_800F7288;
    case 0x800F728Cu: goto label_800F728C;
    case 0x800F7290u: goto label_800F7290;
    case 0x800F7294u: goto label_800F7294;
    case 0x800F7298u: goto label_800F7298;
    case 0x800F729Cu: goto label_800F729C;
    case 0x800F72A0u: goto label_800F72A0;
    case 0x800F72A4u: goto label_800F72A4;
    case 0x800F72A8u: goto label_800F72A8;
    case 0x800F72ACu: goto label_800F72AC;
    case 0x800F72B0u: goto label_800F72B0;
    case 0x800F72B4u: goto label_800F72B4;
    case 0x800F72B8u: goto label_800F72B8;
    case 0x800F72BCu: goto label_800F72BC;
    case 0x800F72C0u: goto label_800F72C0;
    case 0x800F72C4u: goto label_800F72C4;
    case 0x800F72C8u: goto label_800F72C8;
    case 0x800F72CCu: goto label_800F72CC;
    case 0x800F72D0u: goto label_800F72D0;
    case 0x800F72D4u: goto label_800F72D4;
    case 0x800F72D8u: goto label_800F72D8;
    case 0x800F72DCu: goto label_800F72DC;
    case 0x800F72E0u: goto label_800F72E0;
    case 0x800F72E4u: goto label_800F72E4;
    case 0x800F72E8u: goto label_800F72E8;
    case 0x800F72ECu: goto label_800F72EC;
    case 0x800F72F0u: goto label_800F72F0;
    case 0x800F72F4u: goto label_800F72F4;
    case 0x800F72F8u: goto label_800F72F8;
    case 0x800F72FCu: goto label_800F72FC;
    case 0x800F7300u: goto label_800F7300;
    case 0x800F7304u: goto label_800F7304;
    case 0x800F7308u: goto label_800F7308;
    case 0x800F730Cu: goto label_800F730C;
    case 0x800F7310u: goto label_800F7310;
    case 0x800F7314u: goto label_800F7314;
    case 0x800F7318u: goto label_800F7318;
    case 0x800F731Cu: goto label_800F731C;
    case 0x800F7320u: goto label_800F7320;
    case 0x800F7324u: goto label_800F7324;
    case 0x800F7328u: goto label_800F7328;
    case 0x800F732Cu: goto label_800F732C;
    case 0x800F7330u: goto label_800F7330;
    case 0x800F7334u: goto label_800F7334;
    case 0x800F7338u: goto label_800F7338;
    case 0x800F733Cu: goto label_800F733C;
    case 0x800F7340u: goto label_800F7340;
    case 0x800F7344u: goto label_800F7344;
    case 0x800F7348u: goto label_800F7348;
    case 0x800F734Cu: goto label_800F734C;
    case 0x800F7350u: goto label_800F7350;
    case 0x800F7354u: goto label_800F7354;
    case 0x800F7358u: goto label_800F7358;
    case 0x800F735Cu: goto label_800F735C;
    case 0x800F7360u: goto label_800F7360;
    case 0x800F7364u: goto label_800F7364;
    case 0x800F7368u: goto label_800F7368;
    case 0x800F736Cu: goto label_800F736C;
    case 0x800F7370u: goto label_800F7370;
    case 0x800F7374u: goto label_800F7374;
    case 0x800F7378u: goto label_800F7378;
    case 0x800F737Cu: goto label_800F737C;
    case 0x800F7380u: goto label_800F7380;
    case 0x800F7384u: goto label_800F7384;
    case 0x800F7388u: goto label_800F7388;
    case 0x800F738Cu: goto label_800F738C;
    case 0x800F7390u: goto label_800F7390;
    case 0x800F7394u: goto label_800F7394;
    case 0x800F7398u: goto label_800F7398;
    case 0x800F739Cu: goto label_800F739C;
    case 0x800F73A0u: goto label_800F73A0;
    case 0x800F73A4u: goto label_800F73A4;
    case 0x800F73A8u: goto label_800F73A8;
    case 0x800F73ACu: goto label_800F73AC;
    case 0x800F73B0u: goto label_800F73B0;
    case 0x800F73B4u: goto label_800F73B4;
    case 0x800F73B8u: goto label_800F73B8;
    case 0x800F73BCu: goto label_800F73BC;
    case 0x800F73C0u: goto label_800F73C0;
    case 0x800F73C4u: goto label_800F73C4;
    case 0x800F73C8u: goto label_800F73C8;
    case 0x800F73CCu: goto label_800F73CC;
    case 0x800F73D0u: goto label_800F73D0;
    case 0x800F73D4u: goto label_800F73D4;
    case 0x800F73D8u: goto label_800F73D8;
    case 0x800F73DCu: goto label_800F73DC;
    case 0x800F73E0u: goto label_800F73E0;
    case 0x800F73E4u: goto label_800F73E4;
    case 0x800F73E8u: goto label_800F73E8;
    case 0x800F73ECu: goto label_800F73EC;
    case 0x800F73F0u: goto label_800F73F0;
    case 0x800F73F4u: goto label_800F73F4;
    case 0x800F73F8u: goto label_800F73F8;
    case 0x800F73FCu: goto label_800F73FC;
    case 0x800F7400u: goto label_800F7400;
    case 0x800F7404u: goto label_800F7404;
    case 0x800F7408u: goto label_800F7408;
    case 0x800F740Cu: goto label_800F740C;
    case 0x800F7410u: goto label_800F7410;
    case 0x800F7414u: goto label_800F7414;
    case 0x800F7418u: goto label_800F7418;
    case 0x800F741Cu: goto label_800F741C;
    case 0x800F7420u: goto label_800F7420;
    case 0x800F7424u: goto label_800F7424;
    case 0x800F7428u: goto label_800F7428;
    case 0x800F742Cu: goto label_800F742C;
    case 0x800F7430u: goto label_800F7430;
    case 0x800F7434u: goto label_800F7434;
    case 0x800F7438u: goto label_800F7438;
    case 0x800F743Cu: goto label_800F743C;
    case 0x800F7440u: goto label_800F7440;
    case 0x800F7444u: goto label_800F7444;
    case 0x800F7448u: goto label_800F7448;
    case 0x800F744Cu: goto label_800F744C;
    case 0x800F7450u: goto label_800F7450;
    case 0x800F7454u: goto label_800F7454;
    case 0x800F7458u: goto label_800F7458;
    case 0x800F745Cu: goto label_800F745C;
    case 0x800F7460u: goto label_800F7460;
    case 0x800F7464u: goto label_800F7464;
    case 0x800F7468u: goto label_800F7468;
    case 0x800F746Cu: goto label_800F746C;
    case 0x800F7470u: goto label_800F7470;
    case 0x800F7474u: goto label_800F7474;
    case 0x800F7478u: goto label_800F7478;
    case 0x800F747Cu: goto label_800F747C;
    case 0x800F7480u: goto label_800F7480;
    case 0x800F7484u: goto label_800F7484;
    case 0x800F7488u: goto label_800F7488;
    case 0x800F748Cu: goto label_800F748C;
    case 0x800F7490u: goto label_800F7490;
    case 0x800F7494u: goto label_800F7494;
    case 0x800F7498u: goto label_800F7498;
    case 0x800F749Cu: goto label_800F749C;
    case 0x800F74A0u: goto label_800F74A0;
    case 0x800F74A4u: goto label_800F74A4;
    case 0x800F74A8u: goto label_800F74A8;
    case 0x800F74ACu: goto label_800F74AC;
    case 0x800F74B0u: goto label_800F74B0;
    case 0x800F74B4u: goto label_800F74B4;
    case 0x800F74B8u: goto label_800F74B8;
    case 0x800F74BCu: goto label_800F74BC;
    default: return;
    }
label_800F34C0:
    ctx->pc = 0x800F34C0u;
    ctx->downcount -= 17;
    // 800F34C0: stw     r10, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800F34C4:
    ctx->pc = 0x800F34C4u;
    // 800F34C4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F34C8:
    ctx->pc = 0x800F34C8u;
    // 800F34C8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F34CC:
    ctx->pc = 0x800F34CCu;
    // 800F34CC: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F34D0:
    ctx->pc = 0x800F34D0u;
    // 800F34D0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F34D4:
    ctx->pc = 0x800F34D4u;
    // 800F34D4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F34D8:
    ctx->pc = 0x800F34D8u;
    ctx->downcount -= 18;
    // 800F34D8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F34DC:
    ctx->pc = 0x800F34DCu;
    // 800F34DC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F34E0:
    ctx->pc = 0x800F34E0u;
    // 800F34E0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F34E4:
    ctx->pc = 0x800F34E4u;
    // 800F34E4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F34E8:
    ctx->pc = 0x800F34E8u;
    // 800F34E8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F34EC:
    ctx->pc = 0x800F34ECu;
    // 800F34EC: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_800F34F0:
    ctx->pc = 0x800F34F0u;
    // 800F34F0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F34F4:
    ctx->pc = 0x800F34F4u;
    // 800F34F4: bl      0x800EFF24
    {
            ctx->lr = 0x800F34F8u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F34F8:
    ctx->pc = 0x800F34F8u;
    ctx->downcount -= 25;
    // 800F34F8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F34FC:
    ctx->pc = 0x800F34FCu;
    // 800F34FC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F3500:
    ctx->pc = 0x800F3500u;
    // 800F3500: addi    r9, r9, -11496
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-11496);

label_800F3504:
    ctx->pc = 0x800F3504u;
    // 800F3504: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F3508:
    ctx->pc = 0x800F3508u;
    // 800F3508: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F350C:
    ctx->pc = 0x800F350Cu;
    // 800F350C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3510:
    ctx->pc = 0x800F3510u;
    // 800F3510: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F3514:
    ctx->pc = 0x800F3514u;
    // 800F3514: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3518:
    ctx->pc = 0x800F3518u;
    // 800F3518: stw     r29, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800F351C:
    ctx->pc = 0x800F351Cu;
    // 800F351C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3520:
    ctx->pc = 0x800F3520u;
    // 800F3520: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3524:
    ctx->pc = 0x800F3524u;
    // 800F3524: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3528:
    ctx->pc = 0x800F3528u;
    // 800F3528: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F352C:
    ctx->pc = 0x800F352Cu;
    // 800F352C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3530:
    ctx->pc = 0x800F3530u;
    ctx->downcount -= 19;
    // 800F3530: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3534:
    ctx->pc = 0x800F3534u;
    // 800F3534: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3538:
    ctx->pc = 0x800F3538u;
    // 800F3538: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F353C:
    ctx->pc = 0x800F353Cu;
    // 800F353C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3540:
    ctx->pc = 0x800F3540u;
    // 800F3540: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3544:
    ctx->pc = 0x800F3544u;
    // 800F3544: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3548:
    ctx->pc = 0x800F3548u;
    // 800F3548: addi    r4, r4, -13848
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13848);

label_800F354C:
    ctx->pc = 0x800F354Cu;
    // 800F354C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F3550:
    ctx->pc = 0x800F3550u;
    // 800F3550: bl      0x800EFF24
    {
            ctx->lr = 0x800F3554u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F3554:
    ctx->pc = 0x800F3554u;
    ctx->downcount -= 26;
    // 800F3554: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3558:
    ctx->pc = 0x800F3558u;
    // 800F3558: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_800F355C:
    ctx->pc = 0x800F355Cu;
    // 800F355C: addi    r9, r9, -7648
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-7648);

label_800F3560:
    ctx->pc = 0x800F3560u;
    // 800F3560: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F3564:
    ctx->pc = 0x800F3564u;
    // 800F3564: li      r10, 60
    ctx->gpr[10] = (u32)(s32)(60);

label_800F3568:
    ctx->pc = 0x800F3568u;
    // 800F3568: stw     r11, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F356C:
    ctx->pc = 0x800F356Cu;
    // 800F356C: stw     r0, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3570:
    ctx->pc = 0x800F3570u;
    // 800F3570: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3574:
    ctx->pc = 0x800F3574u;
    // 800F3574: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3578:
    ctx->pc = 0x800F3578u;
    // 800F3578: stw     r10, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800F357C:
    ctx->pc = 0x800F357Cu;
    // 800F357C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3580:
    ctx->pc = 0x800F3580u;
    // 800F3580: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3584:
    ctx->pc = 0x800F3584u;
    // 800F3584: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3588:
    ctx->pc = 0x800F3588u;
    // 800F3588: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F358C:
    ctx->pc = 0x800F358Cu;
    // 800F358C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3590:
    ctx->pc = 0x800F3590u;
    ctx->downcount -= 22;
    // 800F3590: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3594:
    ctx->pc = 0x800F3594u;
    // 800F3594: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3598:
    ctx->pc = 0x800F3598u;
    // 800F3598: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3598u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F359C:
    ctx->pc = 0x800F359Cu;
    // 800F359C: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F35A0:
    ctx->pc = 0x800F35A0u;
    // 800F35A0: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F35A4:
    ctx->pc = 0x800F35A4u;
    // 800F35A4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F35A8:
    ctx->pc = 0x800F35A8u;
    // 800F35A8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F35AC:
    ctx->pc = 0x800F35ACu;
    // 800F35AC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F35B0:
    ctx->pc = 0x800F35B0u;
    // 800F35B0: lfs     f31, -10512(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F35B0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10512);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F35B4:
    ctx->pc = 0x800F35B4u;
    // 800F35B4: addi    r4, r4, -13828
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13828);

label_800F35B8:
    ctx->pc = 0x800F35B8u;
    // 800F35B8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F35BC:
    ctx->pc = 0x800F35BCu;
    // 800F35BC: bl      0x800EFF24
    {
            ctx->lr = 0x800F35C0u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F35C0:
    ctx->pc = 0x800F35C0u;
    ctx->downcount -= 9;
    // 800F35C0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F35C4:
    ctx->pc = 0x800F35C4u;
    // 800F35C4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F35C8:
    ctx->pc = 0x800F35C8u;
    // 800F35C8: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F35CC:
    ctx->pc = 0x800F35CCu;
    // 800F35CC: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F35D0:
    ctx->pc = 0x800F35D0u;
    // 800F35D0: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F35D0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F35D4:
    ctx->pc = 0x800F35D4u;
    // 800F35D4: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F35D8:
    ctx->pc = 0x800F35D8u;
    // 800F35D8: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F35DC:
    ctx->pc = 0x800F35DCu;
    // 800F35DC: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F35E0:
    ctx->pc = 0x800F35E0u;
    // 800F35E0: bl      0x80289138
    {
            ctx->lr = 0x800F35E4u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F35E4:
    ctx->pc = 0x800F35E4u;
    ctx->downcount -= 33;
    // 800F35E4: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F35E8:
    ctx->pc = 0x800F35E8u;
    // 800F35E8: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F35EC:
    ctx->pc = 0x800F35ECu;
    // 800F35EC: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F35F0:
    ctx->pc = 0x800F35F0u;
    // 800F35F0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F35F4:
    ctx->pc = 0x800F35F4u;
    // 800F35F4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F35F8:
    ctx->pc = 0x800F35F8u;
    // 800F35F8: lfd     f13, -10504(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F35F8u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10504);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F35FC:
    ctx->pc = 0x800F35FCu;
    // 800F35FC: addi    r9, r9, -7728
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-7728);

label_800F3600:
    ctx->pc = 0x800F3600u;
    // 800F3600: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F3604:
    ctx->pc = 0x800F3604u;
    // 800F3604: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3608:
    ctx->pc = 0x800F3608u;
    // 800F3608: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F3608u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F360C:
    ctx->pc = 0x800F360Cu;
    // 800F360C: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F360Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3610:
    ctx->pc = 0x800F3610u;
    // 800F3610: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3614:
    ctx->pc = 0x800F3614u;
    // 800F3614: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F3614u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F3618:
    ctx->pc = 0x800F3618u;
    // 800F3618: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F3618u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F361C:
    ctx->pc = 0x800F361Cu;
    // 800F361C: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F361Cu)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F3620:
    ctx->pc = 0x800F3620u;
    // 800F3620: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3620u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F3624:
    ctx->pc = 0x800F3624u;
    // 800F3624: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3628:
    ctx->pc = 0x800F3628u;
    // 800F3628: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F362C:
    ctx->pc = 0x800F362Cu;
    // 800F362C: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3630:
    ctx->pc = 0x800F3630u;
    // 800F3630: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3630u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3634:
    ctx->pc = 0x800F3634u;
    // 800F3634: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F3638:
    ctx->pc = 0x800F3638u;
    // 800F3638: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F363C:
    ctx->pc = 0x800F363Cu;
    ctx->downcount -= 22;
    // 800F363C: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3640:
    ctx->pc = 0x800F3640u;
    // 800F3640: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3644:
    ctx->pc = 0x800F3644u;
    // 800F3644: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3644u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F3648:
    ctx->pc = 0x800F3648u;
    // 800F3648: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F364C:
    ctx->pc = 0x800F364Cu;
    // 800F364C: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3650:
    ctx->pc = 0x800F3650u;
    // 800F3650: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3654:
    ctx->pc = 0x800F3654u;
    // 800F3654: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3658:
    ctx->pc = 0x800F3658u;
    // 800F3658: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F365C:
    ctx->pc = 0x800F365Cu;
    // 800F365C: lfs     f31, -10496(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F365Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10496);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F3660:
    ctx->pc = 0x800F3660u;
    // 800F3660: addi    r4, r4, -13804
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13804);

label_800F3664:
    ctx->pc = 0x800F3664u;
    // 800F3664: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F3668:
    ctx->pc = 0x800F3668u;
    // 800F3668: bl      0x800EFF24
    {
            ctx->lr = 0x800F366Cu;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F366C:
    ctx->pc = 0x800F366Cu;
    ctx->downcount -= 9;
    // 800F366C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3670:
    ctx->pc = 0x800F3670u;
    // 800F3670: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F3674:
    ctx->pc = 0x800F3674u;
    // 800F3674: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F3678:
    ctx->pc = 0x800F3678u;
    // 800F3678: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F367C:
    ctx->pc = 0x800F367Cu;
    // 800F367C: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F367Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F3680:
    ctx->pc = 0x800F3680u;
    // 800F3680: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3684:
    ctx->pc = 0x800F3684u;
    // 800F3684: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F3688:
    ctx->pc = 0x800F3688u;
    // 800F3688: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F368C:
    ctx->pc = 0x800F368Cu;
    // 800F368C: bl      0x80289138
    {
            ctx->lr = 0x800F3690u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F3690:
    ctx->pc = 0x800F3690u;
    ctx->downcount -= 33;
    // 800F3690: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3694:
    ctx->pc = 0x800F3694u;
    // 800F3694: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F3698:
    ctx->pc = 0x800F3698u;
    // 800F3698: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F369C:
    ctx->pc = 0x800F369Cu;
    // 800F369C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F36A0:
    ctx->pc = 0x800F36A0u;
    // 800F36A0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F36A4:
    ctx->pc = 0x800F36A4u;
    // 800F36A4: lfd     f13, -10488(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F36A4u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10488);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F36A8:
    ctx->pc = 0x800F36A8u;
    // 800F36A8: addi    r9, r9, -7808
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-7808);

label_800F36AC:
    ctx->pc = 0x800F36ACu;
    // 800F36AC: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F36B0:
    ctx->pc = 0x800F36B0u;
    // 800F36B0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F36B4:
    ctx->pc = 0x800F36B4u;
    // 800F36B4: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F36B4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F36B8:
    ctx->pc = 0x800F36B8u;
    // 800F36B8: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F36B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F36BC:
    ctx->pc = 0x800F36BCu;
    // 800F36BC: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F36C0:
    ctx->pc = 0x800F36C0u;
    // 800F36C0: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F36C0u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F36C4:
    ctx->pc = 0x800F36C4u;
    // 800F36C4: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F36C4u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F36C8:
    ctx->pc = 0x800F36C8u;
    // 800F36C8: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F36C8u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F36CC:
    ctx->pc = 0x800F36CCu;
    // 800F36CC: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F36CCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F36D0:
    ctx->pc = 0x800F36D0u;
    // 800F36D0: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F36D4:
    ctx->pc = 0x800F36D4u;
    // 800F36D4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F36D8:
    ctx->pc = 0x800F36D8u;
    // 800F36D8: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F36DC:
    ctx->pc = 0x800F36DCu;
    // 800F36DC: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F36DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F36E0:
    ctx->pc = 0x800F36E0u;
    // 800F36E0: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F36E4:
    ctx->pc = 0x800F36E4u;
    // 800F36E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F36E8:
    ctx->pc = 0x800F36E8u;
    ctx->downcount -= 18;
    // 800F36E8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F36EC:
    ctx->pc = 0x800F36ECu;
    // 800F36EC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F36F0:
    ctx->pc = 0x800F36F0u;
    // 800F36F0: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F36F4:
    ctx->pc = 0x800F36F4u;
    // 800F36F4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F36F8:
    ctx->pc = 0x800F36F8u;
    // 800F36F8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F36FC:
    ctx->pc = 0x800F36FCu;
    // 800F36FC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3700:
    ctx->pc = 0x800F3700u;
    // 800F3700: addi    r4, r4, -13736
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13736);

label_800F3704:
    ctx->pc = 0x800F3704u;
    // 800F3704: bl      0x800F0E48
    {
            ctx->lr = 0x800F3708u;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F3708:
    ctx->pc = 0x800F3708u;
    ctx->downcount -= 20;
    // 800F3708: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F370C:
    ctx->pc = 0x800F370Cu;
    // 800F370C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3710:
    ctx->pc = 0x800F3710u;
    // 800F3710: addi    r9, r9, -7888
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-7888);

label_800F3714:
    ctx->pc = 0x800F3714u;
    // 800F3714: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3718:
    ctx->pc = 0x800F3718u;
    // 800F3718: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F371C:
    ctx->pc = 0x800F371Cu;
    // 800F371C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3720:
    ctx->pc = 0x800F3720u;
    // 800F3720: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3724:
    ctx->pc = 0x800F3724u;
    // 800F3724: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F3728:
    ctx->pc = 0x800F3728u;
    // 800F3728: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F372C:
    ctx->pc = 0x800F372Cu;
    ctx->downcount -= 18;
    // 800F372C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3730:
    ctx->pc = 0x800F3730u;
    // 800F3730: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3734:
    ctx->pc = 0x800F3734u;
    // 800F3734: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3738:
    ctx->pc = 0x800F3738u;
    // 800F3738: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F373C:
    ctx->pc = 0x800F373Cu;
    // 800F373C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3740:
    ctx->pc = 0x800F3740u;
    // 800F3740: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3744:
    ctx->pc = 0x800F3744u;
    // 800F3744: addi    r4, r4, -13704
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13704);

label_800F3748:
    ctx->pc = 0x800F3748u;
    // 800F3748: bl      0x800F0E48
    {
            ctx->lr = 0x800F374Cu;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F374C:
    ctx->pc = 0x800F374Cu;
    ctx->downcount -= 20;
    // 800F374C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3750:
    ctx->pc = 0x800F3750u;
    // 800F3750: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3754:
    ctx->pc = 0x800F3754u;
    // 800F3754: addi    r9, r9, -7968
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-7968);

label_800F3758:
    ctx->pc = 0x800F3758u;
    // 800F3758: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F375C:
    ctx->pc = 0x800F375Cu;
    // 800F375C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3760:
    ctx->pc = 0x800F3760u;
    // 800F3760: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3764:
    ctx->pc = 0x800F3764u;
    // 800F3764: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3768:
    ctx->pc = 0x800F3768u;
    // 800F3768: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F376C:
    ctx->pc = 0x800F376Cu;
    // 800F376C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3770:
    ctx->pc = 0x800F3770u;
    ctx->downcount -= 18;
    // 800F3770: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3774:
    ctx->pc = 0x800F3774u;
    // 800F3774: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3778:
    ctx->pc = 0x800F3778u;
    // 800F3778: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F377C:
    ctx->pc = 0x800F377Cu;
    // 800F377C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3780:
    ctx->pc = 0x800F3780u;
    // 800F3780: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3784:
    ctx->pc = 0x800F3784u;
    // 800F3784: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3788:
    ctx->pc = 0x800F3788u;
    // 800F3788: addi    r4, r4, -13676
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13676);

label_800F378C:
    ctx->pc = 0x800F378Cu;
    // 800F378C: bl      0x800F0E48
    {
            ctx->lr = 0x800F3790u;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F3790:
    ctx->pc = 0x800F3790u;
    ctx->downcount -= 20;
    // 800F3790: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3794:
    ctx->pc = 0x800F3794u;
    // 800F3794: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3798:
    ctx->pc = 0x800F3798u;
    // 800F3798: addi    r9, r9, -8048
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8048);

label_800F379C:
    ctx->pc = 0x800F379Cu;
    // 800F379C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F37A0:
    ctx->pc = 0x800F37A0u;
    // 800F37A0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F37A4:
    ctx->pc = 0x800F37A4u;
    // 800F37A4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F37A8:
    ctx->pc = 0x800F37A8u;
    // 800F37A8: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F37AC:
    ctx->pc = 0x800F37ACu;
    // 800F37AC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F37B0:
    ctx->pc = 0x800F37B0u;
    // 800F37B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F37B4:
    ctx->pc = 0x800F37B4u;
    ctx->downcount -= 19;
    // 800F37B4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F37B8:
    ctx->pc = 0x800F37B8u;
    // 800F37B8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F37BC:
    ctx->pc = 0x800F37BCu;
    // 800F37BC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F37C0:
    ctx->pc = 0x800F37C0u;
    // 800F37C0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F37C4:
    ctx->pc = 0x800F37C4u;
    // 800F37C4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F37C8:
    ctx->pc = 0x800F37C8u;
    // 800F37C8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F37CC:
    ctx->pc = 0x800F37CCu;
    // 800F37CC: addi    r4, r4, -13548
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13548);

label_800F37D0:
    ctx->pc = 0x800F37D0u;
    // 800F37D0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F37D4:
    ctx->pc = 0x800F37D4u;
    // 800F37D4: bl      0x800F0D5C
    {
            ctx->lr = 0x800F37D8u;
            ctx->pc = 0x800F0D5Cu;
            return;
    }

label_800F37D8:
    ctx->pc = 0x800F37D8u;
    ctx->downcount -= 20;
    // 800F37D8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F37DC:
    ctx->pc = 0x800F37DCu;
    // 800F37DC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F37E0:
    ctx->pc = 0x800F37E0u;
    // 800F37E0: addi    r9, r9, -8128
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8128);

label_800F37E4:
    ctx->pc = 0x800F37E4u;
    // 800F37E4: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F37E8:
    ctx->pc = 0x800F37E8u;
    // 800F37E8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F37EC:
    ctx->pc = 0x800F37ECu;
    // 800F37EC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F37F0:
    ctx->pc = 0x800F37F0u;
    // 800F37F0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F37F4:
    ctx->pc = 0x800F37F4u;
    // 800F37F4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F37F8:
    ctx->pc = 0x800F37F8u;
    // 800F37F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F37FC:
    ctx->pc = 0x800F37FCu;
    ctx->downcount -= 22;
    // 800F37FC: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3800:
    ctx->pc = 0x800F3800u;
    // 800F3800: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3804:
    ctx->pc = 0x800F3804u;
    // 800F3804: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3804u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F3808:
    ctx->pc = 0x800F3808u;
    // 800F3808: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F380C:
    ctx->pc = 0x800F380Cu;
    // 800F380C: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3810:
    ctx->pc = 0x800F3810u;
    // 800F3810: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3814:
    ctx->pc = 0x800F3814u;
    // 800F3814: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3818:
    ctx->pc = 0x800F3818u;
    // 800F3818: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F381C:
    ctx->pc = 0x800F381Cu;
    // 800F381C: lfs     f31, -10480(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F381Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10480);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F3820:
    ctx->pc = 0x800F3820u;
    // 800F3820: addi    r4, r4, -13524
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13524);

label_800F3824:
    ctx->pc = 0x800F3824u;
    // 800F3824: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F3828:
    ctx->pc = 0x800F3828u;
    // 800F3828: bl      0x800EFF24
    {
            ctx->lr = 0x800F382Cu;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F382C:
    ctx->pc = 0x800F382Cu;
    ctx->downcount -= 9;
    // 800F382C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3830:
    ctx->pc = 0x800F3830u;
    // 800F3830: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F3834:
    ctx->pc = 0x800F3834u;
    // 800F3834: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F3838:
    ctx->pc = 0x800F3838u;
    // 800F3838: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F383C:
    ctx->pc = 0x800F383Cu;
    // 800F383C: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F383Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F3840:
    ctx->pc = 0x800F3840u;
    // 800F3840: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3844:
    ctx->pc = 0x800F3844u;
    // 800F3844: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F3848:
    ctx->pc = 0x800F3848u;
    // 800F3848: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F384C:
    ctx->pc = 0x800F384Cu;
    // 800F384C: bl      0x80289138
    {
            ctx->lr = 0x800F3850u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F3850:
    ctx->pc = 0x800F3850u;
    ctx->downcount -= 33;
    // 800F3850: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3854:
    ctx->pc = 0x800F3854u;
    // 800F3854: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F3858:
    ctx->pc = 0x800F3858u;
    // 800F3858: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F385C:
    ctx->pc = 0x800F385Cu;
    // 800F385C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3860:
    ctx->pc = 0x800F3860u;
    // 800F3860: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3864:
    ctx->pc = 0x800F3864u;
    // 800F3864: lfd     f13, -10472(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F3864u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10472);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3868:
    ctx->pc = 0x800F3868u;
    // 800F3868: addi    r9, r9, -8208
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8208);

label_800F386C:
    ctx->pc = 0x800F386Cu;
    // 800F386C: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F3870:
    ctx->pc = 0x800F3870u;
    // 800F3870: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3874:
    ctx->pc = 0x800F3874u;
    // 800F3874: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F3874u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F3878:
    ctx->pc = 0x800F3878u;
    // 800F3878: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3878u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F387C:
    ctx->pc = 0x800F387Cu;
    // 800F387C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3880:
    ctx->pc = 0x800F3880u;
    // 800F3880: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F3880u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F3884:
    ctx->pc = 0x800F3884u;
    // 800F3884: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F3884u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F3888:
    ctx->pc = 0x800F3888u;
    // 800F3888: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F3888u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F388C:
    ctx->pc = 0x800F388Cu;
    // 800F388C: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F388Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F3890:
    ctx->pc = 0x800F3890u;
    // 800F3890: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3894:
    ctx->pc = 0x800F3894u;
    // 800F3894: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3898:
    ctx->pc = 0x800F3898u;
    // 800F3898: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F389C:
    ctx->pc = 0x800F389Cu;
    // 800F389C: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F389Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F38A0:
    ctx->pc = 0x800F38A0u;
    // 800F38A0: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F38A4:
    ctx->pc = 0x800F38A4u;
    // 800F38A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F38A8:
    ctx->pc = 0x800F38A8u;
    ctx->downcount -= 20;
    // 800F38A8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F38AC:
    ctx->pc = 0x800F38ACu;
    // 800F38AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F38B0:
    ctx->pc = 0x800F38B0u;
    // 800F38B0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F38B4:
    ctx->pc = 0x800F38B4u;
    // 800F38B4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F38B8:
    ctx->pc = 0x800F38B8u;
    // 800F38B8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F38BC:
    ctx->pc = 0x800F38BCu;
    // 800F38BC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F38C0:
    ctx->pc = 0x800F38C0u;
    // 800F38C0: addi    r4, r4, -13496
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13496);

label_800F38C4:
    ctx->pc = 0x800F38C4u;
    // 800F38C4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F38C8:
    ctx->pc = 0x800F38C8u;
    // 800F38C8: li      r29, 4
    ctx->gpr[29] = (u32)(s32)(4);

label_800F38CC:
    ctx->pc = 0x800F38CCu;
    // 800F38CC: bl      0x800EFF24
    {
            ctx->lr = 0x800F38D0u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F38D0:
    ctx->pc = 0x800F38D0u;
    ctx->downcount -= 25;
    // 800F38D0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F38D4:
    ctx->pc = 0x800F38D4u;
    // 800F38D4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F38D8:
    ctx->pc = 0x800F38D8u;
    // 800F38D8: addi    r9, r9, -8288
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8288);

label_800F38DC:
    ctx->pc = 0x800F38DCu;
    // 800F38DC: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F38E0:
    ctx->pc = 0x800F38E0u;
    // 800F38E0: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F38E4:
    ctx->pc = 0x800F38E4u;
    // 800F38E4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F38E8:
    ctx->pc = 0x800F38E8u;
    // 800F38E8: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F38EC:
    ctx->pc = 0x800F38ECu;
    // 800F38EC: stw     r29, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800F38F0:
    ctx->pc = 0x800F38F0u;
    // 800F38F0: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F38F4:
    ctx->pc = 0x800F38F4u;
    // 800F38F4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F38F8:
    ctx->pc = 0x800F38F8u;
    // 800F38F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F38FC:
    ctx->pc = 0x800F38FCu;
    // 800F38FC: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3900:
    ctx->pc = 0x800F3900u;
    // 800F3900: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F3904:
    ctx->pc = 0x800F3904u;
    // 800F3904: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3908:
    ctx->pc = 0x800F3908u;
    ctx->downcount -= 22;
    // 800F3908: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F390C:
    ctx->pc = 0x800F390Cu;
    // 800F390C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3910:
    ctx->pc = 0x800F3910u;
    // 800F3910: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3910u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F3914:
    ctx->pc = 0x800F3914u;
    // 800F3914: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3918:
    ctx->pc = 0x800F3918u;
    // 800F3918: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F391C:
    ctx->pc = 0x800F391Cu;
    // 800F391C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3920:
    ctx->pc = 0x800F3920u;
    // 800F3920: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3924:
    ctx->pc = 0x800F3924u;
    // 800F3924: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3928:
    ctx->pc = 0x800F3928u;
    // 800F3928: lfs     f31, -10464(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F3928u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10464);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F392C:
    ctx->pc = 0x800F392Cu;
    // 800F392C: addi    r4, r4, -13432
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13432);

label_800F3930:
    ctx->pc = 0x800F3930u;
    // 800F3930: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F3934:
    ctx->pc = 0x800F3934u;
    // 800F3934: bl      0x800EFF24
    {
            ctx->lr = 0x800F3938u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F3938:
    ctx->pc = 0x800F3938u;
    ctx->downcount -= 9;
    // 800F3938: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F393C:
    ctx->pc = 0x800F393Cu;
    // 800F393C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F3940:
    ctx->pc = 0x800F3940u;
    // 800F3940: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F3944:
    ctx->pc = 0x800F3944u;
    // 800F3944: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F3948:
    ctx->pc = 0x800F3948u;
    // 800F3948: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3948u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F394C:
    ctx->pc = 0x800F394Cu;
    // 800F394C: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3950:
    ctx->pc = 0x800F3950u;
    // 800F3950: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F3954:
    ctx->pc = 0x800F3954u;
    // 800F3954: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3958:
    ctx->pc = 0x800F3958u;
    // 800F3958: bl      0x80289138
    {
            ctx->lr = 0x800F395Cu;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F395C:
    ctx->pc = 0x800F395Cu;
    ctx->downcount -= 33;
    // 800F395C: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3960:
    ctx->pc = 0x800F3960u;
    // 800F3960: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F3964:
    ctx->pc = 0x800F3964u;
    // 800F3964: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F3968:
    ctx->pc = 0x800F3968u;
    // 800F3968: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F396C:
    ctx->pc = 0x800F396Cu;
    // 800F396C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3970:
    ctx->pc = 0x800F3970u;
    // 800F3970: lfd     f13, -10456(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F3970u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10456);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3974:
    ctx->pc = 0x800F3974u;
    // 800F3974: addi    r9, r9, -8528
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8528);

label_800F3978:
    ctx->pc = 0x800F3978u;
    // 800F3978: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F397C:
    ctx->pc = 0x800F397Cu;
    // 800F397C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3980:
    ctx->pc = 0x800F3980u;
    // 800F3980: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F3980u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F3984:
    ctx->pc = 0x800F3984u;
    // 800F3984: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3984u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3988:
    ctx->pc = 0x800F3988u;
    // 800F3988: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F398C:
    ctx->pc = 0x800F398Cu;
    // 800F398C: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F398Cu)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F3990:
    ctx->pc = 0x800F3990u;
    // 800F3990: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F3990u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F3994:
    ctx->pc = 0x800F3994u;
    // 800F3994: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F3994u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F3998:
    ctx->pc = 0x800F3998u;
    // 800F3998: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3998u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F399C:
    ctx->pc = 0x800F399Cu;
    // 800F399C: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F39A0:
    ctx->pc = 0x800F39A0u;
    // 800F39A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F39A4:
    ctx->pc = 0x800F39A4u;
    // 800F39A4: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F39A8:
    ctx->pc = 0x800F39A8u;
    // 800F39A8: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F39A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F39AC:
    ctx->pc = 0x800F39ACu;
    // 800F39AC: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F39B0:
    ctx->pc = 0x800F39B0u;
    // 800F39B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F39B4:
    ctx->pc = 0x800F39B4u;
    ctx->downcount -= 22;
    // 800F39B4: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F39B8:
    ctx->pc = 0x800F39B8u;
    // 800F39B8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F39BC:
    ctx->pc = 0x800F39BCu;
    // 800F39BC: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F39BCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F39C0:
    ctx->pc = 0x800F39C0u;
    // 800F39C0: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F39C4:
    ctx->pc = 0x800F39C4u;
    // 800F39C4: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F39C8:
    ctx->pc = 0x800F39C8u;
    // 800F39C8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F39CC:
    ctx->pc = 0x800F39CCu;
    // 800F39CC: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F39D0:
    ctx->pc = 0x800F39D0u;
    // 800F39D0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F39D4:
    ctx->pc = 0x800F39D4u;
    // 800F39D4: lfs     f31, -10448(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F39D4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10448);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F39D8:
    ctx->pc = 0x800F39D8u;
    // 800F39D8: addi    r4, r4, -13408
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13408);

label_800F39DC:
    ctx->pc = 0x800F39DCu;
    // 800F39DC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F39E0:
    ctx->pc = 0x800F39E0u;
    // 800F39E0: bl      0x800EFF24
    {
            ctx->lr = 0x800F39E4u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F39E4:
    ctx->pc = 0x800F39E4u;
    ctx->downcount -= 9;
    // 800F39E4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F39E8:
    ctx->pc = 0x800F39E8u;
    // 800F39E8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F39EC:
    ctx->pc = 0x800F39ECu;
    // 800F39EC: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F39F0:
    ctx->pc = 0x800F39F0u;
    // 800F39F0: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F39F4:
    ctx->pc = 0x800F39F4u;
    // 800F39F4: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F39F4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F39F8:
    ctx->pc = 0x800F39F8u;
    // 800F39F8: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F39FC:
    ctx->pc = 0x800F39FCu;
    // 800F39FC: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F3A00:
    ctx->pc = 0x800F3A00u;
    // 800F3A00: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3A04:
    ctx->pc = 0x800F3A04u;
    // 800F3A04: bl      0x80289138
    {
            ctx->lr = 0x800F3A08u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F3A08:
    ctx->pc = 0x800F3A08u;
    ctx->downcount -= 33;
    // 800F3A08: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3A0C:
    ctx->pc = 0x800F3A0Cu;
    // 800F3A0C: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F3A10:
    ctx->pc = 0x800F3A10u;
    // 800F3A10: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F3A14:
    ctx->pc = 0x800F3A14u;
    // 800F3A14: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3A18:
    ctx->pc = 0x800F3A18u;
    // 800F3A18: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3A1C:
    ctx->pc = 0x800F3A1Cu;
    // 800F3A1C: lfd     f13, -10440(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F3A1Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10440);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3A20:
    ctx->pc = 0x800F3A20u;
    // 800F3A20: addi    r9, r9, -8448
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8448);

label_800F3A24:
    ctx->pc = 0x800F3A24u;
    // 800F3A24: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F3A28:
    ctx->pc = 0x800F3A28u;
    // 800F3A28: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3A2C:
    ctx->pc = 0x800F3A2Cu;
    // 800F3A2C: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F3A2Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F3A30:
    ctx->pc = 0x800F3A30u;
    // 800F3A30: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3A30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3A34:
    ctx->pc = 0x800F3A34u;
    // 800F3A34: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3A38:
    ctx->pc = 0x800F3A38u;
    // 800F3A38: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F3A38u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F3A3C:
    ctx->pc = 0x800F3A3Cu;
    // 800F3A3C: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F3A3Cu)) return;
    ppc_frsp(ctx, 0, 0);

label_800F3A40:
    ctx->pc = 0x800F3A40u;
    // 800F3A40: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F3A40u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F3A44:
    ctx->pc = 0x800F3A44u;
    // 800F3A44: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3A44u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F3A48:
    ctx->pc = 0x800F3A48u;
    // 800F3A48: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3A4C:
    ctx->pc = 0x800F3A4Cu;
    // 800F3A4C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3A50:
    ctx->pc = 0x800F3A50u;
    // 800F3A50: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3A54:
    ctx->pc = 0x800F3A54u;
    // 800F3A54: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3A54u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3A58:
    ctx->pc = 0x800F3A58u;
    // 800F3A58: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F3A5C:
    ctx->pc = 0x800F3A5Cu;
    // 800F3A5C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3A60:
    ctx->pc = 0x800F3A60u;
    ctx->downcount -= 22;
    // 800F3A60: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3A64:
    ctx->pc = 0x800F3A64u;
    // 800F3A64: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3A68:
    ctx->pc = 0x800F3A68u;
    // 800F3A68: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3A68u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F3A6C:
    ctx->pc = 0x800F3A6Cu;
    // 800F3A6C: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3A70:
    ctx->pc = 0x800F3A70u;
    // 800F3A70: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3A74:
    ctx->pc = 0x800F3A74u;
    // 800F3A74: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3A78:
    ctx->pc = 0x800F3A78u;
    // 800F3A78: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3A7C:
    ctx->pc = 0x800F3A7Cu;
    // 800F3A7C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3A80:
    ctx->pc = 0x800F3A80u;
    // 800F3A80: lfs     f31, -10432(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F3A80u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10432);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F3A84:
    ctx->pc = 0x800F3A84u;
    // 800F3A84: addi    r4, r4, -13384
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13384);

label_800F3A88:
    ctx->pc = 0x800F3A88u;
    // 800F3A88: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F3A8C:
    ctx->pc = 0x800F3A8Cu;
    // 800F3A8C: bl      0x800EFF24
    {
            ctx->lr = 0x800F3A90u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F3A90:
    ctx->pc = 0x800F3A90u;
    ctx->downcount -= 9;
    // 800F3A90: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3A94:
    ctx->pc = 0x800F3A94u;
    // 800F3A94: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F3A98:
    ctx->pc = 0x800F3A98u;
    // 800F3A98: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F3A9C:
    ctx->pc = 0x800F3A9Cu;
    // 800F3A9C: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F3AA0:
    ctx->pc = 0x800F3AA0u;
    // 800F3AA0: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3AA0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F3AA4:
    ctx->pc = 0x800F3AA4u;
    // 800F3AA4: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3AA8:
    ctx->pc = 0x800F3AA8u;
    // 800F3AA8: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F3AAC:
    ctx->pc = 0x800F3AACu;
    // 800F3AAC: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3AB0:
    ctx->pc = 0x800F3AB0u;
    // 800F3AB0: bl      0x80289138
    {
            ctx->lr = 0x800F3AB4u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F3AB4:
    ctx->pc = 0x800F3AB4u;
    ctx->downcount -= 33;
    // 800F3AB4: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3AB8:
    ctx->pc = 0x800F3AB8u;
    // 800F3AB8: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F3ABC:
    ctx->pc = 0x800F3ABCu;
    // 800F3ABC: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F3AC0:
    ctx->pc = 0x800F3AC0u;
    // 800F3AC0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3AC4:
    ctx->pc = 0x800F3AC4u;
    // 800F3AC4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3AC8:
    ctx->pc = 0x800F3AC8u;
    // 800F3AC8: lfd     f13, -10424(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F3AC8u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10424);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3ACC:
    ctx->pc = 0x800F3ACCu;
    // 800F3ACC: addi    r9, r9, -8608
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8608);

label_800F3AD0:
    ctx->pc = 0x800F3AD0u;
    // 800F3AD0: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F3AD4:
    ctx->pc = 0x800F3AD4u;
    // 800F3AD4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3AD8:
    ctx->pc = 0x800F3AD8u;
    // 800F3AD8: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F3AD8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F3ADC:
    ctx->pc = 0x800F3ADCu;
    // 800F3ADC: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3ADCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3AE0:
    ctx->pc = 0x800F3AE0u;
    // 800F3AE0: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3AE4:
    ctx->pc = 0x800F3AE4u;
    // 800F3AE4: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F3AE4u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F3AE8:
    ctx->pc = 0x800F3AE8u;
    // 800F3AE8: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F3AE8u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F3AEC:
    ctx->pc = 0x800F3AECu;
    // 800F3AEC: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F3AECu)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F3AF0:
    ctx->pc = 0x800F3AF0u;
    // 800F3AF0: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3AF0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F3AF4:
    ctx->pc = 0x800F3AF4u;
    // 800F3AF4: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3AF8:
    ctx->pc = 0x800F3AF8u;
    // 800F3AF8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3AFC:
    ctx->pc = 0x800F3AFCu;
    // 800F3AFC: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3B00:
    ctx->pc = 0x800F3B00u;
    // 800F3B00: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3B00u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3B04:
    ctx->pc = 0x800F3B04u;
    // 800F3B04: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F3B08:
    ctx->pc = 0x800F3B08u;
    // 800F3B08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3B0C:
    ctx->pc = 0x800F3B0Cu;
    ctx->downcount -= 22;
    // 800F3B0C: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3B10:
    ctx->pc = 0x800F3B10u;
    // 800F3B10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3B14:
    ctx->pc = 0x800F3B14u;
    // 800F3B14: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3B14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F3B18:
    ctx->pc = 0x800F3B18u;
    // 800F3B18: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3B1C:
    ctx->pc = 0x800F3B1Cu;
    // 800F3B1C: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3B20:
    ctx->pc = 0x800F3B20u;
    // 800F3B20: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3B24:
    ctx->pc = 0x800F3B24u;
    // 800F3B24: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3B28:
    ctx->pc = 0x800F3B28u;
    // 800F3B28: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3B2C:
    ctx->pc = 0x800F3B2Cu;
    // 800F3B2C: lfs     f31, -10416(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F3B2Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10416);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F3B30:
    ctx->pc = 0x800F3B30u;
    // 800F3B30: addi    r4, r4, -13356
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13356);

label_800F3B34:
    ctx->pc = 0x800F3B34u;
    // 800F3B34: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F3B38:
    ctx->pc = 0x800F3B38u;
    // 800F3B38: bl      0x800EFF24
    {
            ctx->lr = 0x800F3B3Cu;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F3B3C:
    ctx->pc = 0x800F3B3Cu;
    ctx->downcount -= 9;
    // 800F3B3C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3B40:
    ctx->pc = 0x800F3B40u;
    // 800F3B40: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F3B44:
    ctx->pc = 0x800F3B44u;
    // 800F3B44: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F3B48:
    ctx->pc = 0x800F3B48u;
    // 800F3B48: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F3B4C:
    ctx->pc = 0x800F3B4Cu;
    // 800F3B4C: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3B4Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F3B50:
    ctx->pc = 0x800F3B50u;
    // 800F3B50: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3B54:
    ctx->pc = 0x800F3B54u;
    // 800F3B54: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F3B58:
    ctx->pc = 0x800F3B58u;
    // 800F3B58: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3B5C:
    ctx->pc = 0x800F3B5Cu;
    // 800F3B5C: bl      0x80289138
    {
            ctx->lr = 0x800F3B60u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F3B60:
    ctx->pc = 0x800F3B60u;
    ctx->downcount -= 33;
    // 800F3B60: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3B64:
    ctx->pc = 0x800F3B64u;
    // 800F3B64: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F3B68:
    ctx->pc = 0x800F3B68u;
    // 800F3B68: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F3B6C:
    ctx->pc = 0x800F3B6Cu;
    // 800F3B6C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3B70:
    ctx->pc = 0x800F3B70u;
    // 800F3B70: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3B74:
    ctx->pc = 0x800F3B74u;
    // 800F3B74: lfd     f13, -10408(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F3B74u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10408);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3B78:
    ctx->pc = 0x800F3B78u;
    // 800F3B78: addi    r9, r9, -8368
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8368);

label_800F3B7C:
    ctx->pc = 0x800F3B7Cu;
    // 800F3B7C: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F3B80:
    ctx->pc = 0x800F3B80u;
    // 800F3B80: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3B84:
    ctx->pc = 0x800F3B84u;
    // 800F3B84: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F3B84u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F3B88:
    ctx->pc = 0x800F3B88u;
    // 800F3B88: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3B88u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3B8C:
    ctx->pc = 0x800F3B8Cu;
    // 800F3B8C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3B90:
    ctx->pc = 0x800F3B90u;
    // 800F3B90: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F3B90u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F3B94:
    ctx->pc = 0x800F3B94u;
    // 800F3B94: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F3B94u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F3B98:
    ctx->pc = 0x800F3B98u;
    // 800F3B98: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F3B98u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F3B9C:
    ctx->pc = 0x800F3B9Cu;
    // 800F3B9C: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3B9Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F3BA0:
    ctx->pc = 0x800F3BA0u;
    // 800F3BA0: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3BA4:
    ctx->pc = 0x800F3BA4u;
    // 800F3BA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3BA8:
    ctx->pc = 0x800F3BA8u;
    // 800F3BA8: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3BAC:
    ctx->pc = 0x800F3BACu;
    // 800F3BAC: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3BACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3BB0:
    ctx->pc = 0x800F3BB0u;
    // 800F3BB0: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F3BB4:
    ctx->pc = 0x800F3BB4u;
    // 800F3BB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3BB8:
    ctx->pc = 0x800F3BB8u;
    ctx->downcount -= 22;
    // 800F3BB8: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3BBC:
    ctx->pc = 0x800F3BBCu;
    // 800F3BBC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3BC0:
    ctx->pc = 0x800F3BC0u;
    // 800F3BC0: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3BC0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F3BC4:
    ctx->pc = 0x800F3BC4u;
    // 800F3BC4: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3BC8:
    ctx->pc = 0x800F3BC8u;
    // 800F3BC8: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3BCC:
    ctx->pc = 0x800F3BCCu;
    // 800F3BCC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3BD0:
    ctx->pc = 0x800F3BD0u;
    // 800F3BD0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3BD4:
    ctx->pc = 0x800F3BD4u;
    // 800F3BD4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3BD8:
    ctx->pc = 0x800F3BD8u;
    // 800F3BD8: lfs     f31, -10400(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F3BD8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10400);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F3BDC:
    ctx->pc = 0x800F3BDCu;
    // 800F3BDC: addi    r4, r4, -13320
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13320);

label_800F3BE0:
    ctx->pc = 0x800F3BE0u;
    // 800F3BE0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F3BE4:
    ctx->pc = 0x800F3BE4u;
    // 800F3BE4: bl      0x800EFF24
    {
            ctx->lr = 0x800F3BE8u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F3BE8:
    ctx->pc = 0x800F3BE8u;
    ctx->downcount -= 9;
    // 800F3BE8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3BEC:
    ctx->pc = 0x800F3BECu;
    // 800F3BEC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F3BF0:
    ctx->pc = 0x800F3BF0u;
    // 800F3BF0: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F3BF4:
    ctx->pc = 0x800F3BF4u;
    // 800F3BF4: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F3BF8:
    ctx->pc = 0x800F3BF8u;
    // 800F3BF8: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3BF8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F3BFC:
    ctx->pc = 0x800F3BFCu;
    // 800F3BFC: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3C00:
    ctx->pc = 0x800F3C00u;
    // 800F3C00: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F3C04:
    ctx->pc = 0x800F3C04u;
    // 800F3C04: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3C08:
    ctx->pc = 0x800F3C08u;
    // 800F3C08: bl      0x80289138
    {
            ctx->lr = 0x800F3C0Cu;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F3C0C:
    ctx->pc = 0x800F3C0Cu;
    ctx->downcount -= 33;
    // 800F3C0C: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3C10:
    ctx->pc = 0x800F3C10u;
    // 800F3C10: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F3C14:
    ctx->pc = 0x800F3C14u;
    // 800F3C14: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F3C18:
    ctx->pc = 0x800F3C18u;
    // 800F3C18: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3C1C:
    ctx->pc = 0x800F3C1Cu;
    // 800F3C1C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3C20:
    ctx->pc = 0x800F3C20u;
    // 800F3C20: lfd     f13, -10392(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F3C20u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10392);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3C24:
    ctx->pc = 0x800F3C24u;
    // 800F3C24: addi    r9, r9, -8688
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8688);

label_800F3C28:
    ctx->pc = 0x800F3C28u;
    // 800F3C28: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F3C2C:
    ctx->pc = 0x800F3C2Cu;
    // 800F3C2C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3C30:
    ctx->pc = 0x800F3C30u;
    // 800F3C30: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F3C30u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F3C34:
    ctx->pc = 0x800F3C34u;
    // 800F3C34: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3C34u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3C38:
    ctx->pc = 0x800F3C38u;
    // 800F3C38: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3C3C:
    ctx->pc = 0x800F3C3Cu;
    // 800F3C3C: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F3C3Cu)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F3C40:
    ctx->pc = 0x800F3C40u;
    // 800F3C40: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F3C40u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F3C44:
    ctx->pc = 0x800F3C44u;
    // 800F3C44: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F3C44u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F3C48:
    ctx->pc = 0x800F3C48u;
    // 800F3C48: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3C48u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F3C4C:
    ctx->pc = 0x800F3C4Cu;
    // 800F3C4C: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3C50:
    ctx->pc = 0x800F3C50u;
    // 800F3C50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3C54:
    ctx->pc = 0x800F3C54u;
    // 800F3C54: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3C58:
    ctx->pc = 0x800F3C58u;
    // 800F3C58: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3C58u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3C5C:
    ctx->pc = 0x800F3C5Cu;
    // 800F3C5C: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F3C60:
    ctx->pc = 0x800F3C60u;
    // 800F3C60: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3C64:
    ctx->pc = 0x800F3C64u;
    ctx->downcount -= 23;
    // 800F3C64: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3C68:
    ctx->pc = 0x800F3C68u;
    // 800F3C68: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3C6C:
    ctx->pc = 0x800F3C6Cu;
    // 800F3C6C: stfd     f31, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3C6Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F3C70:
    ctx->pc = 0x800F3C70u;
    // 800F3C70: stmw     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3C74:
    ctx->pc = 0x800F3C74u;
    // 800F3C74: stw     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3C78:
    ctx->pc = 0x800F3C78u;
    // 800F3C78: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3C7C:
    ctx->pc = 0x800F3C7Cu;
    // 800F3C7C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3C80:
    ctx->pc = 0x800F3C80u;
    // 800F3C80: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3C84:
    ctx->pc = 0x800F3C84u;
    // 800F3C84: lfs     f31, -10384(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F3C84u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10384);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F3C88:
    ctx->pc = 0x800F3C88u;
    // 800F3C88: addi    r4, r4, -13288
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13288);

label_800F3C8C:
    ctx->pc = 0x800F3C8Cu;
    // 800F3C8C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F3C90:
    ctx->pc = 0x800F3C90u;
    // 800F3C90: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_800F3C94:
    ctx->pc = 0x800F3C94u;
    // 800F3C94: bl      0x800EFF24
    {
            ctx->lr = 0x800F3C98u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F3C98:
    ctx->pc = 0x800F3C98u;
    ctx->downcount -= 8;
    // 800F3C98: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3C9C:
    ctx->pc = 0x800F3C9Cu;
    // 800F3C9C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F3CA0:
    ctx->pc = 0x800F3CA0u;
    // 800F3CA0: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F3CA4:
    ctx->pc = 0x800F3CA4u;
    // 800F3CA4: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3CA4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F3CA8:
    ctx->pc = 0x800F3CA8u;
    // 800F3CA8: stw     r29, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800F3CAC:
    ctx->pc = 0x800F3CACu;
    // 800F3CAC: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3CB0:
    ctx->pc = 0x800F3CB0u;
    // 800F3CB0: stw     r0, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3CB4:
    ctx->pc = 0x800F3CB4u;
    // 800F3CB4: bl      0x80289138
    {
            ctx->lr = 0x800F3CB8u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F3CB8:
    ctx->pc = 0x800F3CB8u;
    ctx->downcount -= 34;
    // 800F3CB8: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3CBC:
    ctx->pc = 0x800F3CBCu;
    // 800F3CBC: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F3CC0:
    ctx->pc = 0x800F3CC0u;
    // 800F3CC0: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F3CC4:
    ctx->pc = 0x800F3CC4u;
    // 800F3CC4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3CC8:
    ctx->pc = 0x800F3CC8u;
    // 800F3CC8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3CCC:
    ctx->pc = 0x800F3CCCu;
    // 800F3CCC: lfd     f13, -10376(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F3CCCu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10376);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3CD0:
    ctx->pc = 0x800F3CD0u;
    // 800F3CD0: addi    r9, r9, -12056
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-12056);

label_800F3CD4:
    ctx->pc = 0x800F3CD4u;
    // 800F3CD4: stw     r8, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F3CD8:
    ctx->pc = 0x800F3CD8u;
    // 800F3CD8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3CDC:
    ctx->pc = 0x800F3CDCu;
    // 800F3CDC: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F3CDCu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F3CE0:
    ctx->pc = 0x800F3CE0u;
    // 800F3CE0: lfd     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3CE0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3CE4:
    ctx->pc = 0x800F3CE4u;
    // 800F3CE4: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3CE8:
    ctx->pc = 0x800F3CE8u;
    // 800F3CE8: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F3CE8u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F3CEC:
    ctx->pc = 0x800F3CECu;
    // 800F3CEC: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F3CECu)) return;
    ppc_frsp(ctx, 0, 0);

label_800F3CF0:
    ctx->pc = 0x800F3CF0u;
    // 800F3CF0: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F3CF0u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F3CF4:
    ctx->pc = 0x800F3CF4u;
    // 800F3CF4: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F3CF4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F3CF8:
    ctx->pc = 0x800F3CF8u;
    // 800F3CF8: stw     r29, -32168(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32168);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800F3CFC:
    ctx->pc = 0x800F3CFCu;
    // 800F3CFC: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3D00:
    ctx->pc = 0x800F3D00u;
    // 800F3D00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3D04:
    ctx->pc = 0x800F3D04u;
    // 800F3D04: lmw     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3D08:
    ctx->pc = 0x800F3D08u;
    // 800F3D08: lfd     f31, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F3D08u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F3D0C:
    ctx->pc = 0x800F3D0Cu;
    // 800F3D0C: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_800F3D10:
    ctx->pc = 0x800F3D10u;
    // 800F3D10: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3D14:
    ctx->pc = 0x800F3D14u;
    ctx->downcount -= 25;
    // 800F3D14: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3D18:
    ctx->pc = 0x800F3D18u;
    // 800F3D18: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3D1C:
    ctx->pc = 0x800F3D1Cu;
    // 800F3D1C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3D20:
    ctx->pc = 0x800F3D20u;
    // 800F3D20: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3D24:
    ctx->pc = 0x800F3D24u;
    // 800F3D24: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3D28:
    ctx->pc = 0x800F3D28u;
    // 800F3D28: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3D2C:
    ctx->pc = 0x800F3D2Cu;
    // 800F3D2C: addi    r9, r9, -12056
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-12056);

label_800F3D30:
    ctx->pc = 0x800F3D30u;
    // 800F3D30: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_800F3D34:
    ctx->pc = 0x800F3D34u;
    // 800F3D34: stw     r9, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3D38:
    ctx->pc = 0x800F3D38u;
    // 800F3D38: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_800F3D3C:
    ctx->pc = 0x800F3D3Cu;
    // 800F3D3C: addi    r11, r11, -10616
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-10616);

label_800F3D40:
    ctx->pc = 0x800F3D40u;
    // 800F3D40: stw     r30, -32168(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32168);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800F3D44:
    ctx->pc = 0x800F3D44u;
    // 800F3D44: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800F3D48:
    ctx->pc = 0x800F3D48u;
    // 800F3D48: stw     r11, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F3D4C:
    ctx->pc = 0x800F3D4Cu;
    // 800F3D4C: bl      0x80106E94
    {
            ctx->lr = 0x800F3D50u;
            ctx->pc = 0x80106E94u;
            return;
    }

label_800F3D50:
    ctx->pc = 0x800F3D50u;
    ctx->downcount -= 4;
    // 800F3D50: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F3D54:
    ctx->pc = 0x800F3D54u;
    // 800F3D54: stw     r30, -25068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25068);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800F3D58:
    ctx->pc = 0x800F3D58u;
    // 800F3D58: cmpwi   r3, 0
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

label_800F3D5C:
    ctx->pc = 0x800F3D5Cu;
    // 800F3D5C: bc    12, 2, 0x800F3D64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F3D64;
        }
    }

label_800F3D60:
    ctx->pc = 0x800F3D60u;
    ctx->downcount -= 1;
    // 800F3D60: bl      0x80281DD0
    {
            ctx->lr = 0x800F3D64u;
            ctx->pc = 0x80281DD0u;
            return;
    }

label_800F3D64:
    ctx->pc = 0x800F3D64u;
    ctx->downcount -= 4;
    // 800F3D64: or   r9, r31, r31
    {
        ctx->gpr[9] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F3D68:
    ctx->pc = 0x800F3D68u;
    // 800F3D68: lwzu     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_800F3D6C:
    ctx->pc = 0x800F3D6Cu;
    // 800F3D6C: cmpwi   r3, 0
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

label_800F3D70:
    ctx->pc = 0x800F3D70u;
    // 800F3D70: bc    12, 2, 0x800F3D94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F3D94;
        }
    }

label_800F3D74:
    ctx->pc = 0x800F3D74u;
    ctx->downcount -= 5;
    // 800F3D74: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3D78:
    ctx->pc = 0x800F3D78u;
    // 800F3D78: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800F3D7C:
    ctx->pc = 0x800F3D7Cu;
    // 800F3D7C: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_800F3D80:
    ctx->pc = 0x800F3D80u;
    // 800F3D80: cmplwi  r4, 0x0080
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

label_800F3D84:
    ctx->pc = 0x800F3D84u;
    // 800F3D84: bc    4, 1, 0x800F3D90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F3D90;
        }
    }

label_800F3D88:
    ctx->pc = 0x800F3D88u;
    ctx->downcount -= 1;
    // 800F3D88: bl      0x80281D80
    {
            ctx->lr = 0x800F3D8Cu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800F3D8C:
    ctx->pc = 0x800F3D8Cu;
    ctx->downcount -= 1;
    // 800F3D8C: b       0x800F3D94
    {
            goto label_800F3D94;
    }

label_800F3D90:
    ctx->pc = 0x800F3D90u;
    ctx->downcount -= 1;
    // 800F3D90: bl      0x8001D934
    {
            ctx->lr = 0x800F3D94u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_800F3D94:
    ctx->pc = 0x800F3D94u;
    ctx->downcount -= 2;
    // 800F3D94: andi.   r0, r29, 0x0001
    {
        ctx->gpr[0] = ctx->gpr[29] & 0x0001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800F3D98:
    ctx->pc = 0x800F3D98u;
    // 800F3D98: bc    12, 2, 0x800F3DA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F3DA4;
        }
    }

label_800F3D9C:
    ctx->pc = 0x800F3D9Cu;
    ctx->downcount -= 2;
    // 800F3D9C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F3DA0:
    ctx->pc = 0x800F3DA0u;
    // 800F3DA0: bl      0x80281D80
    {
            ctx->lr = 0x800F3DA4u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800F3DA4:
    ctx->pc = 0x800F3DA4u;
    ctx->downcount -= 16;
    // 800F3DA4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3DA8:
    ctx->pc = 0x800F3DA8u;
    // 800F3DA8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3DAC:
    ctx->pc = 0x800F3DACu;
    // 800F3DAC: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3DB0:
    ctx->pc = 0x800F3DB0u;
    // 800F3DB0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F3DB4:
    ctx->pc = 0x800F3DB4u;
    // 800F3DB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3DB8:
    ctx->pc = 0x800F3DB8u;
    ctx->downcount -= 18;
    // 800F3DB8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3DBC:
    ctx->pc = 0x800F3DBCu;
    // 800F3DBC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3DC0:
    ctx->pc = 0x800F3DC0u;
    // 800F3DC0: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3DC4:
    ctx->pc = 0x800F3DC4u;
    // 800F3DC4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3DC8:
    ctx->pc = 0x800F3DC8u;
    // 800F3DC8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3DCC:
    ctx->pc = 0x800F3DCCu;
    // 800F3DCC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3DD0:
    ctx->pc = 0x800F3DD0u;
    // 800F3DD0: addi    r4, r4, -13264
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13264);

label_800F3DD4:
    ctx->pc = 0x800F3DD4u;
    // 800F3DD4: bl      0x800F0E48
    {
            ctx->lr = 0x800F3DD8u;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F3DD8:
    ctx->pc = 0x800F3DD8u;
    ctx->downcount -= 20;
    // 800F3DD8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3DDC:
    ctx->pc = 0x800F3DDCu;
    // 800F3DDC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3DE0:
    ctx->pc = 0x800F3DE0u;
    // 800F3DE0: addi    r9, r9, -8768
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8768);

label_800F3DE4:
    ctx->pc = 0x800F3DE4u;
    // 800F3DE4: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3DE8:
    ctx->pc = 0x800F3DE8u;
    // 800F3DE8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3DEC:
    ctx->pc = 0x800F3DECu;
    // 800F3DEC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3DF0:
    ctx->pc = 0x800F3DF0u;
    // 800F3DF0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3DF4:
    ctx->pc = 0x800F3DF4u;
    // 800F3DF4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F3DF8:
    ctx->pc = 0x800F3DF8u;
    // 800F3DF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3DFC:
    ctx->pc = 0x800F3DFCu;
    ctx->downcount -= 18;
    // 800F3DFC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3E00:
    ctx->pc = 0x800F3E00u;
    // 800F3E00: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3E04:
    ctx->pc = 0x800F3E04u;
    // 800F3E04: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3E08:
    ctx->pc = 0x800F3E08u;
    // 800F3E08: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3E0C:
    ctx->pc = 0x800F3E0Cu;
    // 800F3E0C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3E10:
    ctx->pc = 0x800F3E10u;
    // 800F3E10: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3E14:
    ctx->pc = 0x800F3E14u;
    // 800F3E14: addi    r4, r4, -13236
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13236);

label_800F3E18:
    ctx->pc = 0x800F3E18u;
    // 800F3E18: bl      0x800F0E48
    {
            ctx->lr = 0x800F3E1Cu;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F3E1C:
    ctx->pc = 0x800F3E1Cu;
    ctx->downcount -= 20;
    // 800F3E1C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3E20:
    ctx->pc = 0x800F3E20u;
    // 800F3E20: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3E24:
    ctx->pc = 0x800F3E24u;
    // 800F3E24: addi    r9, r9, -8928
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8928);

label_800F3E28:
    ctx->pc = 0x800F3E28u;
    // 800F3E28: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3E2C:
    ctx->pc = 0x800F3E2Cu;
    // 800F3E2C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3E30:
    ctx->pc = 0x800F3E30u;
    // 800F3E30: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3E34:
    ctx->pc = 0x800F3E34u;
    // 800F3E34: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3E38:
    ctx->pc = 0x800F3E38u;
    // 800F3E38: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F3E3C:
    ctx->pc = 0x800F3E3Cu;
    // 800F3E3C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3E40:
    ctx->pc = 0x800F3E40u;
    ctx->downcount -= 19;
    // 800F3E40: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3E44:
    ctx->pc = 0x800F3E44u;
    // 800F3E44: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3E48:
    ctx->pc = 0x800F3E48u;
    // 800F3E48: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3E4C:
    ctx->pc = 0x800F3E4Cu;
    // 800F3E4C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3E50:
    ctx->pc = 0x800F3E50u;
    // 800F3E50: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3E54:
    ctx->pc = 0x800F3E54u;
    // 800F3E54: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3E58:
    ctx->pc = 0x800F3E58u;
    // 800F3E58: addi    r4, r4, -13208
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13208);

label_800F3E5C:
    ctx->pc = 0x800F3E5Cu;
    // 800F3E5C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F3E60:
    ctx->pc = 0x800F3E60u;
    // 800F3E60: bl      0x800F0C70
    {
            ctx->lr = 0x800F3E64u;
            ctx->pc = 0x800F0C70u;
            return;
    }

label_800F3E64:
    ctx->pc = 0x800F3E64u;
    ctx->downcount -= 20;
    // 800F3E64: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3E68:
    ctx->pc = 0x800F3E68u;
    // 800F3E68: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3E6C:
    ctx->pc = 0x800F3E6Cu;
    // 800F3E6C: addi    r9, r9, -8848
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8848);

label_800F3E70:
    ctx->pc = 0x800F3E70u;
    // 800F3E70: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3E74:
    ctx->pc = 0x800F3E74u;
    // 800F3E74: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3E78:
    ctx->pc = 0x800F3E78u;
    // 800F3E78: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3E7C:
    ctx->pc = 0x800F3E7Cu;
    // 800F3E7C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3E80:
    ctx->pc = 0x800F3E80u;
    // 800F3E80: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F3E84:
    ctx->pc = 0x800F3E84u;
    // 800F3E84: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3E88:
    ctx->pc = 0x800F3E88u;
    ctx->downcount -= 6;
    // 800F3E88: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3E8C:
    ctx->pc = 0x800F3E8Cu;
    // 800F3E8C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3E90:
    ctx->pc = 0x800F3E90u;
    // 800F3E90: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3E94:
    ctx->pc = 0x800F3E94u;
    // 800F3E94: lwz     r0, 36(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3E98:
    ctx->pc = 0x800F3E98u;
    // 800F3E98: cmpwi   r0, 0
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

label_800F3E9C:
    ctx->pc = 0x800F3E9Cu;
    // 800F3E9C: bc    12, 2, 0x800F3EC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F3EC4;
        }
    }

label_800F3EA0:
    ctx->pc = 0x800F3EA0u;
    ctx->downcount -= 3;
    // 800F3EA0: lwz     r0, -25064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25064);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3EA4:
    ctx->pc = 0x800F3EA4u;
    // 800F3EA4: cmpwi   r0, 10
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800F3EA8:
    ctx->pc = 0x800F3EA8u;
    // 800F3EA8: bc    4, 2, 0x800F3EC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F3EC4;
        }
    }

label_800F3EAC:
    ctx->pc = 0x800F3EACu;
    ctx->downcount -= 4;
    // 800F3EAC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F3EB0:
    ctx->pc = 0x800F3EB0u;
    // 800F3EB0: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F3EB4:
    ctx->pc = 0x800F3EB4u;
    // 800F3EB4: stw     r0, -25064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25064);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3EB8:
    ctx->pc = 0x800F3EB8u;
    // 800F3EB8: bl      0x80281C60
    {
            ctx->lr = 0x800F3EBCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F3EBC:
    ctx->pc = 0x800F3EBCu;
    ctx->downcount -= 1;
    // 800F3EBC: bl      0x800F3EF8
    {
            ctx->lr = 0x800F3EC0u;
            goto label_800F3EF8;
    }

label_800F3EC0:
    ctx->pc = 0x800F3EC0u;
    ctx->downcount -= 1;
    // 800F3EC0: b       0x800F3EC8
    {
            goto label_800F3EC8;
    }

label_800F3EC4:
    ctx->pc = 0x800F3EC4u;
    ctx->downcount -= 1;
    // 800F3EC4: bl      0x800F09AC
    {
            ctx->lr = 0x800F3EC8u;
            ctx->pc = 0x800F09ACu;
            return;
    }

label_800F3EC8:
    ctx->pc = 0x800F3EC8u;
    ctx->downcount -= 5;
    // 800F3EC8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3ECC:
    ctx->pc = 0x800F3ECCu;
    // 800F3ECC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3ED0:
    ctx->pc = 0x800F3ED0u;
    // 800F3ED0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F3ED4:
    ctx->pc = 0x800F3ED4u;
    // 800F3ED4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3ED8:
    ctx->pc = 0x800F3ED8u;
    ctx->downcount -= 4;
    // 800F3ED8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3EDC:
    ctx->pc = 0x800F3EDCu;
    // 800F3EDC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3EE0:
    ctx->pc = 0x800F3EE0u;
    // 800F3EE0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3EE4:
    ctx->pc = 0x800F3EE4u;
    // 800F3EE4: bl      0x800F09AC
    {
            ctx->lr = 0x800F3EE8u;
            ctx->pc = 0x800F09ACu;
            return;
    }

label_800F3EE8:
    ctx->pc = 0x800F3EE8u;
    ctx->downcount -= 5;
    // 800F3EE8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3EEC:
    ctx->pc = 0x800F3EECu;
    // 800F3EEC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3EF0:
    ctx->pc = 0x800F3EF0u;
    // 800F3EF0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F3EF4:
    ctx->pc = 0x800F3EF4u;
    // 800F3EF4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3EF8:
    ctx->pc = 0x800F3EF8u;
    ctx->downcount -= 19;
    // 800F3EF8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3EFC:
    ctx->pc = 0x800F3EFCu;
    // 800F3EFC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3F00:
    ctx->pc = 0x800F3F00u;
    // 800F3F00: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3F04:
    ctx->pc = 0x800F3F04u;
    // 800F3F04: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3F08:
    ctx->pc = 0x800F3F08u;
    // 800F3F08: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3F0C:
    ctx->pc = 0x800F3F0Cu;
    // 800F3F0C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3F10:
    ctx->pc = 0x800F3F10u;
    // 800F3F10: addi    r4, r4, -13096
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13096);

label_800F3F14:
    ctx->pc = 0x800F3F14u;
    // 800F3F14: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F3F18:
    ctx->pc = 0x800F3F18u;
    // 800F3F18: bl      0x800F0D5C
    {
            ctx->lr = 0x800F3F1Cu;
            ctx->pc = 0x800F0D5Cu;
            return;
    }

label_800F3F1C:
    ctx->pc = 0x800F3F1Cu;
    ctx->downcount -= 20;
    // 800F3F1C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3F20:
    ctx->pc = 0x800F3F20u;
    // 800F3F20: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F3F24:
    ctx->pc = 0x800F3F24u;
    // 800F3F24: addi    r9, r9, -11736
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-11736);

label_800F3F28:
    ctx->pc = 0x800F3F28u;
    // 800F3F28: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3F2C:
    ctx->pc = 0x800F3F2Cu;
    // 800F3F2C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3F30:
    ctx->pc = 0x800F3F30u;
    // 800F3F30: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3F34:
    ctx->pc = 0x800F3F34u;
    // 800F3F34: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F3F38:
    ctx->pc = 0x800F3F38u;
    // 800F3F38: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F3F3C:
    ctx->pc = 0x800F3F3Cu;
    // 800F3F3C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3F40:
    ctx->pc = 0x800F3F40u;
    ctx->downcount -= 8;
    // 800F3F40: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3F44:
    ctx->pc = 0x800F3F44u;
    // 800F3F44: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3F48:
    ctx->pc = 0x800F3F48u;
    // 800F3F48: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800F3F4C:
    ctx->pc = 0x800F3F4Cu;
    // 800F3F4C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3F50:
    ctx->pc = 0x800F3F50u;
    // 800F3F50: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3F54:
    ctx->pc = 0x800F3F54u;
    // 800F3F54: lwz     r0, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3F58:
    ctx->pc = 0x800F3F58u;
    // 800F3F58: cmpwi   r0, 0
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

label_800F3F5C:
    ctx->pc = 0x800F3F5Cu;
    // 800F3F5C: bc    12, 2, 0x800F3F84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F3F84;
        }
    }

label_800F3F60:
    ctx->pc = 0x800F3F60u;
    ctx->downcount -= 3;
    // 800F3F60: lwz     r0, -25064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25064);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3F64:
    ctx->pc = 0x800F3F64u;
    // 800F3F64: cmpwi   r0, 1
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

label_800F3F68:
    ctx->pc = 0x800F3F68u;
    // 800F3F68: bc    4, 2, 0x800F3F74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F3F74;
        }
    }

label_800F3F6C:
    ctx->pc = 0x800F3F6Cu;
    ctx->downcount -= 2;
    // 800F3F6C: li      r0, 10
    ctx->gpr[0] = (u32)(s32)(10);

label_800F3F70:
    ctx->pc = 0x800F3F70u;
    // 800F3F70: b       0x800F3F80
    {
            goto label_800F3F80;
    }

label_800F3F74:
    ctx->pc = 0x800F3F74u;
    ctx->downcount -= 2;
    // 800F3F74: cmpwi   r0, 2
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

label_800F3F78:
    ctx->pc = 0x800F3F78u;
    // 800F3F78: bc    4, 2, 0x800F3F84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F3F84;
        }
    }

label_800F3F7C:
    ctx->pc = 0x800F3F7Cu;
    ctx->downcount -= 1;
    // 800F3F7C: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_800F3F80:
    ctx->pc = 0x800F3F80u;
    ctx->downcount -= 1;
    // 800F3F80: stw     r0, -25064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25064);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3F84:
    ctx->pc = 0x800F3F84u;
    ctx->downcount -= 7;
    // 800F3F84: lwz     r9, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F3F88:
    ctx->pc = 0x800F3F88u;
    // 800F3F88: lha     r3, 40(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(40);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800F3F8C:
    ctx->pc = 0x800F3F8Cu;
    // 800F3F8C: lwz     r0, 44(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3F90:
    ctx->pc = 0x800F3F90u;
    // 800F3F90: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800F3F94:
    ctx->pc = 0x800F3F94u;
    // 800F3F94: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3F98:
    ctx->pc = 0x800F3F98u;
    // 800F3F98: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800F3F9Cu;
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3F9C:
    ctx->pc = 0x800F3F9Cu;
    ctx->downcount -= 2;
    // 800F3F9C: cmpwi   r3, 0
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

label_800F3FA0:
    ctx->pc = 0x800F3FA0u;
    // 800F3FA0: bc    12, 2, 0x800F3FB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F3FB8;
        }
    }

label_800F3FA4:
    ctx->pc = 0x800F3FA4u;
    ctx->downcount -= 5;
    // 800F3FA4: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_800F3FA8:
    ctx->pc = 0x800F3FA8u;
    // 800F3FA8: lwz     r0, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3FAC:
    ctx->pc = 0x800F3FACu;
    // 800F3FAC: stw     r9, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3FB0:
    ctx->pc = 0x800F3FB0u;
    // 800F3FB0: stw     r0, -25064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25064);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3FB4:
    ctx->pc = 0x800F3FB4u;
    // 800F3FB4: stw     r9, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F3FB8:
    ctx->pc = 0x800F3FB8u;
    ctx->downcount -= 2;
    // 800F3FB8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F3FBC:
    ctx->pc = 0x800F3FBCu;
    // 800F3FBC: bl      0x800F09AC
    {
            ctx->lr = 0x800F3FC0u;
            ctx->pc = 0x800F09ACu;
            return;
    }

label_800F3FC0:
    ctx->pc = 0x800F3FC0u;
    ctx->downcount -= 6;
    // 800F3FC0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F3FC4:
    ctx->pc = 0x800F3FC4u;
    // 800F3FC4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F3FC8:
    ctx->pc = 0x800F3FC8u;
    // 800F3FC8: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800F3FCC:
    ctx->pc = 0x800F3FCCu;
    // 800F3FCC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F3FD0:
    ctx->pc = 0x800F3FD0u;
    // 800F3FD0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F3FD4:
    ctx->pc = 0x800F3FD4u;
    ctx->downcount -= 19;
    // 800F3FD4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F3FD8:
    ctx->pc = 0x800F3FD8u;
    // 800F3FD8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F3FDC:
    ctx->pc = 0x800F3FDCu;
    // 800F3FDC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F3FE0:
    ctx->pc = 0x800F3FE0u;
    // 800F3FE0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F3FE4:
    ctx->pc = 0x800F3FE4u;
    // 800F3FE4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F3FE8:
    ctx->pc = 0x800F3FE8u;
    // 800F3FE8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F3FEC:
    ctx->pc = 0x800F3FECu;
    // 800F3FEC: addi    r4, r4, -13064
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13064);

label_800F3FF0:
    ctx->pc = 0x800F3FF0u;
    // 800F3FF0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F3FF4:
    ctx->pc = 0x800F3FF4u;
    // 800F3FF4: bl      0x800EFF24
    {
            ctx->lr = 0x800F3FF8u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F3FF8:
    ctx->pc = 0x800F3FF8u;
    ctx->downcount -= 20;
    // 800F3FF8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F3FFC:
    ctx->pc = 0x800F3FFCu;
    // 800F3FFC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4000:
    ctx->pc = 0x800F4000u;
    // 800F4000: addi    r9, r9, -12216
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-12216);

label_800F4004:
    ctx->pc = 0x800F4004u;
    // 800F4004: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4008:
    ctx->pc = 0x800F4008u;
    // 800F4008: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F400C:
    ctx->pc = 0x800F400Cu;
    // 800F400C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4010:
    ctx->pc = 0x800F4010u;
    // 800F4010: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4014:
    ctx->pc = 0x800F4014u;
    // 800F4014: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4018:
    ctx->pc = 0x800F4018u;
    // 800F4018: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F401C:
    ctx->pc = 0x800F401Cu;
    ctx->downcount -= 6;
    // 800F401C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4020:
    ctx->pc = 0x800F4020u;
    // 800F4020: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4024:
    ctx->pc = 0x800F4024u;
    // 800F4024: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800F4028:
    ctx->pc = 0x800F4028u;
    // 800F4028: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F402C:
    ctx->pc = 0x800F402Cu;
    // 800F402C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4030:
    ctx->pc = 0x800F4030u;
    // 800F4030: bl      0x8028D82C
    {
            ctx->lr = 0x800F4034u;
            ctx->pc = 0x8028D82Cu;
            return;
    }

label_800F4034:
    ctx->pc = 0x800F4034u;
    ctx->downcount -= 2;
    // 800F4034: cmpwi   r3, 1
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

label_800F4038:
    ctx->pc = 0x800F4038u;
    // 800F4038: bc    12, 2, 0x800F4060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F4060;
        }
    }

label_800F403C:
    ctx->pc = 0x800F403Cu;
    ctx->downcount -= 2;
    // 800F403C: cmpwi   r31, 0
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

label_800F4040:
    ctx->pc = 0x800F4040u;
    // 800F4040: bc    12, 2, 0x800F4060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F4060;
        }
    }

label_800F4044:
    ctx->pc = 0x800F4044u;
    ctx->downcount -= 8;
    // 800F4044: lwz     r9, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F4048:
    ctx->pc = 0x800F4048u;
    // 800F4048: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_800F404C:
    ctx->pc = 0x800F404Cu;
    // 800F404C: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800F4050:
    ctx->pc = 0x800F4050u;
    // 800F4050: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4054:
    ctx->pc = 0x800F4054u;
    // 800F4054: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800F4058:
    ctx->pc = 0x800F4058u;
    // 800F4058: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F405C:
    ctx->pc = 0x800F405Cu;
    // 800F405C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800F4060u;
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4060:
    ctx->pc = 0x800F4060u;
    ctx->downcount -= 6;
    // 800F4060: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4064:
    ctx->pc = 0x800F4064u;
    // 800F4064: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4068:
    ctx->pc = 0x800F4068u;
    // 800F4068: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800F406C:
    ctx->pc = 0x800F406Cu;
    // 800F406C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4070:
    ctx->pc = 0x800F4070u;
    // 800F4070: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4074:
    ctx->pc = 0x800F4074u;
    ctx->downcount -= 19;
    // 800F4074: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4078:
    ctx->pc = 0x800F4078u;
    // 800F4078: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F407C:
    ctx->pc = 0x800F407Cu;
    // 800F407C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4080:
    ctx->pc = 0x800F4080u;
    // 800F4080: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4084:
    ctx->pc = 0x800F4084u;
    // 800F4084: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4088:
    ctx->pc = 0x800F4088u;
    // 800F4088: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F408C:
    ctx->pc = 0x800F408Cu;
    // 800F408C: addi    r4, r4, -13036
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13036);

label_800F4090:
    ctx->pc = 0x800F4090u;
    // 800F4090: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4094:
    ctx->pc = 0x800F4094u;
    // 800F4094: bl      0x800EFF24
    {
            ctx->lr = 0x800F4098u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4098:
    ctx->pc = 0x800F4098u;
    ctx->downcount -= 20;
    // 800F4098: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F409C:
    ctx->pc = 0x800F409Cu;
    // 800F409C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F40A0:
    ctx->pc = 0x800F40A0u;
    // 800F40A0: addi    r9, r9, -12296
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-12296);

label_800F40A4:
    ctx->pc = 0x800F40A4u;
    // 800F40A4: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F40A8:
    ctx->pc = 0x800F40A8u;
    // 800F40A8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F40AC:
    ctx->pc = 0x800F40ACu;
    // 800F40AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F40B0:
    ctx->pc = 0x800F40B0u;
    // 800F40B0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F40B4:
    ctx->pc = 0x800F40B4u;
    // 800F40B4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F40B8:
    ctx->pc = 0x800F40B8u;
    // 800F40B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F40BC:
    ctx->pc = 0x800F40BCu;
    ctx->downcount -= 6;
    // 800F40BC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F40C0:
    ctx->pc = 0x800F40C0u;
    // 800F40C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F40C4:
    ctx->pc = 0x800F40C4u;
    // 800F40C4: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800F40C8:
    ctx->pc = 0x800F40C8u;
    // 800F40C8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F40CC:
    ctx->pc = 0x800F40CCu;
    // 800F40CC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F40D0:
    ctx->pc = 0x800F40D0u;
    // 800F40D0: bl      0x8028D82C
    {
            ctx->lr = 0x800F40D4u;
            ctx->pc = 0x8028D82Cu;
            return;
    }

label_800F40D4:
    ctx->pc = 0x800F40D4u;
    ctx->downcount -= 2;
    // 800F40D4: cmpwi   r3, 2
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

label_800F40D8:
    ctx->pc = 0x800F40D8u;
    // 800F40D8: bc    12, 2, 0x800F4100
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F4100;
        }
    }

label_800F40DC:
    ctx->pc = 0x800F40DCu;
    ctx->downcount -= 2;
    // 800F40DC: cmpwi   r31, 0
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

label_800F40E0:
    ctx->pc = 0x800F40E0u;
    // 800F40E0: bc    12, 2, 0x800F4100
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F4100;
        }
    }

label_800F40E4:
    ctx->pc = 0x800F40E4u;
    ctx->downcount -= 8;
    // 800F40E4: lwz     r9, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F40E8:
    ctx->pc = 0x800F40E8u;
    // 800F40E8: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_800F40EC:
    ctx->pc = 0x800F40ECu;
    // 800F40EC: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800F40F0:
    ctx->pc = 0x800F40F0u;
    // 800F40F0: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F40F4:
    ctx->pc = 0x800F40F4u;
    // 800F40F4: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800F40F8:
    ctx->pc = 0x800F40F8u;
    // 800F40F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F40FC:
    ctx->pc = 0x800F40FCu;
    // 800F40FC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800F4100u;
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4100:
    ctx->pc = 0x800F4100u;
    ctx->downcount -= 6;
    // 800F4100: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4104:
    ctx->pc = 0x800F4104u;
    // 800F4104: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4108:
    ctx->pc = 0x800F4108u;
    // 800F4108: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800F410C:
    ctx->pc = 0x800F410Cu;
    // 800F410C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4110:
    ctx->pc = 0x800F4110u;
    // 800F4110: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4114:
    ctx->pc = 0x800F4114u;
    ctx->downcount -= 19;
    // 800F4114: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4118:
    ctx->pc = 0x800F4118u;
    // 800F4118: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F411C:
    ctx->pc = 0x800F411Cu;
    // 800F411C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4120:
    ctx->pc = 0x800F4120u;
    // 800F4120: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4124:
    ctx->pc = 0x800F4124u;
    // 800F4124: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4128:
    ctx->pc = 0x800F4128u;
    // 800F4128: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F412C:
    ctx->pc = 0x800F412Cu;
    // 800F412C: addi    r4, r4, -13008
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13008);

label_800F4130:
    ctx->pc = 0x800F4130u;
    // 800F4130: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4134:
    ctx->pc = 0x800F4134u;
    // 800F4134: bl      0x800EFF24
    {
            ctx->lr = 0x800F4138u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4138:
    ctx->pc = 0x800F4138u;
    ctx->downcount -= 20;
    // 800F4138: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F413C:
    ctx->pc = 0x800F413Cu;
    // 800F413C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4140:
    ctx->pc = 0x800F4140u;
    // 800F4140: addi    r9, r9, -12376
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-12376);

label_800F4144:
    ctx->pc = 0x800F4144u;
    // 800F4144: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4148:
    ctx->pc = 0x800F4148u;
    // 800F4148: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F414C:
    ctx->pc = 0x800F414Cu;
    // 800F414C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4150:
    ctx->pc = 0x800F4150u;
    // 800F4150: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4154:
    ctx->pc = 0x800F4154u;
    // 800F4154: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4158:
    ctx->pc = 0x800F4158u;
    // 800F4158: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F415C:
    ctx->pc = 0x800F415Cu;
    ctx->downcount -= 6;
    // 800F415C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4160:
    ctx->pc = 0x800F4160u;
    // 800F4160: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4164:
    ctx->pc = 0x800F4164u;
    // 800F4164: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800F4168:
    ctx->pc = 0x800F4168u;
    // 800F4168: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F416C:
    ctx->pc = 0x800F416Cu;
    // 800F416C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4170:
    ctx->pc = 0x800F4170u;
    // 800F4170: bl      0x8028D82C
    {
            ctx->lr = 0x800F4174u;
            ctx->pc = 0x8028D82Cu;
            return;
    }

label_800F4174:
    ctx->pc = 0x800F4174u;
    ctx->downcount -= 2;
    // 800F4174: cmpwi   r3, 3
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

label_800F4178:
    ctx->pc = 0x800F4178u;
    // 800F4178: bc    12, 2, 0x800F41A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F41A0;
        }
    }

label_800F417C:
    ctx->pc = 0x800F417Cu;
    ctx->downcount -= 2;
    // 800F417C: cmpwi   r31, 0
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

label_800F4180:
    ctx->pc = 0x800F4180u;
    // 800F4180: bc    12, 2, 0x800F41A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F41A0;
        }
    }

label_800F4184:
    ctx->pc = 0x800F4184u;
    ctx->downcount -= 8;
    // 800F4184: lwz     r9, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F4188:
    ctx->pc = 0x800F4188u;
    // 800F4188: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_800F418C:
    ctx->pc = 0x800F418Cu;
    // 800F418C: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800F4190:
    ctx->pc = 0x800F4190u;
    // 800F4190: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4194:
    ctx->pc = 0x800F4194u;
    // 800F4194: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800F4198:
    ctx->pc = 0x800F4198u;
    // 800F4198: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F419C:
    ctx->pc = 0x800F419Cu;
    // 800F419C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800F41A0u;
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F41A0:
    ctx->pc = 0x800F41A0u;
    ctx->downcount -= 6;
    // 800F41A0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F41A4:
    ctx->pc = 0x800F41A4u;
    // 800F41A4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F41A8:
    ctx->pc = 0x800F41A8u;
    // 800F41A8: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800F41AC:
    ctx->pc = 0x800F41ACu;
    // 800F41AC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F41B0:
    ctx->pc = 0x800F41B0u;
    // 800F41B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F41B4:
    ctx->pc = 0x800F41B4u;
    ctx->downcount -= 19;
    // 800F41B4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F41B8:
    ctx->pc = 0x800F41B8u;
    // 800F41B8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F41BC:
    ctx->pc = 0x800F41BCu;
    // 800F41BC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F41C0:
    ctx->pc = 0x800F41C0u;
    // 800F41C0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F41C4:
    ctx->pc = 0x800F41C4u;
    // 800F41C4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F41C8:
    ctx->pc = 0x800F41C8u;
    // 800F41C8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F41CC:
    ctx->pc = 0x800F41CCu;
    // 800F41CC: addi    r4, r4, -12980
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12980);

label_800F41D0:
    ctx->pc = 0x800F41D0u;
    // 800F41D0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F41D4:
    ctx->pc = 0x800F41D4u;
    // 800F41D4: bl      0x800EFF24
    {
            ctx->lr = 0x800F41D8u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F41D8:
    ctx->pc = 0x800F41D8u;
    ctx->downcount -= 20;
    // 800F41D8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F41DC:
    ctx->pc = 0x800F41DCu;
    // 800F41DC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F41E0:
    ctx->pc = 0x800F41E0u;
    // 800F41E0: addi    r9, r9, -9008
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9008);

label_800F41E4:
    ctx->pc = 0x800F41E4u;
    // 800F41E4: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F41E8:
    ctx->pc = 0x800F41E8u;
    // 800F41E8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F41EC:
    ctx->pc = 0x800F41ECu;
    // 800F41EC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F41F0:
    ctx->pc = 0x800F41F0u;
    // 800F41F0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F41F4:
    ctx->pc = 0x800F41F4u;
    // 800F41F4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F41F8:
    ctx->pc = 0x800F41F8u;
    // 800F41F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F41FC:
    ctx->pc = 0x800F41FCu;
    ctx->downcount -= 19;
    // 800F41FC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4200:
    ctx->pc = 0x800F4200u;
    // 800F4200: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4204:
    ctx->pc = 0x800F4204u;
    // 800F4204: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4208:
    ctx->pc = 0x800F4208u;
    // 800F4208: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F420C:
    ctx->pc = 0x800F420Cu;
    // 800F420C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4210:
    ctx->pc = 0x800F4210u;
    // 800F4210: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4214:
    ctx->pc = 0x800F4214u;
    // 800F4214: addi    r4, r4, -12956
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12956);

label_800F4218:
    ctx->pc = 0x800F4218u;
    // 800F4218: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F421C:
    ctx->pc = 0x800F421Cu;
    // 800F421C: bl      0x800EFF24
    {
            ctx->lr = 0x800F4220u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4220:
    ctx->pc = 0x800F4220u;
    ctx->downcount -= 20;
    // 800F4220: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4224:
    ctx->pc = 0x800F4224u;
    // 800F4224: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4228:
    ctx->pc = 0x800F4228u;
    // 800F4228: addi    r9, r9, -9088
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9088);

label_800F422C:
    ctx->pc = 0x800F422Cu;
    // 800F422C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4230:
    ctx->pc = 0x800F4230u;
    // 800F4230: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4234:
    ctx->pc = 0x800F4234u;
    // 800F4234: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4238:
    ctx->pc = 0x800F4238u;
    // 800F4238: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F423C:
    ctx->pc = 0x800F423Cu;
    // 800F423C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4240:
    ctx->pc = 0x800F4240u;
    // 800F4240: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4244:
    ctx->pc = 0x800F4244u;
    ctx->downcount -= 19;
    // 800F4244: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4248:
    ctx->pc = 0x800F4248u;
    // 800F4248: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F424C:
    ctx->pc = 0x800F424Cu;
    // 800F424C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4250:
    ctx->pc = 0x800F4250u;
    // 800F4250: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4254:
    ctx->pc = 0x800F4254u;
    // 800F4254: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4258:
    ctx->pc = 0x800F4258u;
    // 800F4258: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F425C:
    ctx->pc = 0x800F425Cu;
    // 800F425C: addi    r4, r4, -12932
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12932);

label_800F4260:
    ctx->pc = 0x800F4260u;
    // 800F4260: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4264:
    ctx->pc = 0x800F4264u;
    // 800F4264: bl      0x800F0C70
    {
            ctx->lr = 0x800F4268u;
            ctx->pc = 0x800F0C70u;
            return;
    }

label_800F4268:
    ctx->pc = 0x800F4268u;
    ctx->downcount -= 20;
    // 800F4268: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F426C:
    ctx->pc = 0x800F426Cu;
    // 800F426C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4270:
    ctx->pc = 0x800F4270u;
    // 800F4270: addi    r9, r9, -9168
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9168);

label_800F4274:
    ctx->pc = 0x800F4274u;
    // 800F4274: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4278:
    ctx->pc = 0x800F4278u;
    // 800F4278: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F427C:
    ctx->pc = 0x800F427Cu;
    // 800F427C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4280:
    ctx->pc = 0x800F4280u;
    // 800F4280: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4284:
    ctx->pc = 0x800F4284u;
    // 800F4284: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4288:
    ctx->pc = 0x800F4288u;
    // 800F4288: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F428C:
    ctx->pc = 0x800F428Cu;
    ctx->downcount -= 22;
    // 800F428C: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4290:
    ctx->pc = 0x800F4290u;
    // 800F4290: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4294:
    ctx->pc = 0x800F4294u;
    // 800F4294: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4294u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F4298:
    ctx->pc = 0x800F4298u;
    // 800F4298: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F429C:
    ctx->pc = 0x800F429Cu;
    // 800F429C: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F42A0:
    ctx->pc = 0x800F42A0u;
    // 800F42A0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F42A4:
    ctx->pc = 0x800F42A4u;
    // 800F42A4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F42A8:
    ctx->pc = 0x800F42A8u;
    // 800F42A8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F42AC:
    ctx->pc = 0x800F42ACu;
    // 800F42AC: lfs     f31, -10368(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F42ACu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10368);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F42B0:
    ctx->pc = 0x800F42B0u;
    // 800F42B0: addi    r4, r4, -12904
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12904);

label_800F42B4:
    ctx->pc = 0x800F42B4u;
    // 800F42B4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F42B8:
    ctx->pc = 0x800F42B8u;
    // 800F42B8: bl      0x800EFF24
    {
            ctx->lr = 0x800F42BCu;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F42BC:
    ctx->pc = 0x800F42BCu;
    ctx->downcount -= 9;
    // 800F42BC: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F42C0:
    ctx->pc = 0x800F42C0u;
    // 800F42C0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F42C4:
    ctx->pc = 0x800F42C4u;
    // 800F42C4: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F42C8:
    ctx->pc = 0x800F42C8u;
    // 800F42C8: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F42CC:
    ctx->pc = 0x800F42CCu;
    // 800F42CC: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F42CCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F42D0:
    ctx->pc = 0x800F42D0u;
    // 800F42D0: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F42D4:
    ctx->pc = 0x800F42D4u;
    // 800F42D4: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F42D8:
    ctx->pc = 0x800F42D8u;
    // 800F42D8: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F42DC:
    ctx->pc = 0x800F42DCu;
    // 800F42DC: bl      0x80289138
    {
            ctx->lr = 0x800F42E0u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F42E0:
    ctx->pc = 0x800F42E0u;
    ctx->downcount -= 33;
    // 800F42E0: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F42E4:
    ctx->pc = 0x800F42E4u;
    // 800F42E4: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F42E8:
    ctx->pc = 0x800F42E8u;
    // 800F42E8: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F42EC:
    ctx->pc = 0x800F42ECu;
    // 800F42EC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F42F0:
    ctx->pc = 0x800F42F0u;
    // 800F42F0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F42F4:
    ctx->pc = 0x800F42F4u;
    // 800F42F4: lfd     f13, -10360(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F42F4u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10360);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F42F8:
    ctx->pc = 0x800F42F8u;
    // 800F42F8: addi    r9, r9, -9248
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9248);

label_800F42FC:
    ctx->pc = 0x800F42FCu;
    // 800F42FC: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F4300:
    ctx->pc = 0x800F4300u;
    // 800F4300: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4304:
    ctx->pc = 0x800F4304u;
    // 800F4304: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F4304u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F4308:
    ctx->pc = 0x800F4308u;
    // 800F4308: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4308u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F430C:
    ctx->pc = 0x800F430Cu;
    // 800F430C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4310:
    ctx->pc = 0x800F4310u;
    // 800F4310: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F4310u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F4314:
    ctx->pc = 0x800F4314u;
    // 800F4314: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F4314u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F4318:
    ctx->pc = 0x800F4318u;
    // 800F4318: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F4318u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F431C:
    ctx->pc = 0x800F431Cu;
    // 800F431C: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F431Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F4320:
    ctx->pc = 0x800F4320u;
    // 800F4320: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4324:
    ctx->pc = 0x800F4324u;
    // 800F4324: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4328:
    ctx->pc = 0x800F4328u;
    // 800F4328: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F432C:
    ctx->pc = 0x800F432Cu;
    // 800F432C: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F432Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4330:
    ctx->pc = 0x800F4330u;
    // 800F4330: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F4334:
    ctx->pc = 0x800F4334u;
    // 800F4334: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4338:
    ctx->pc = 0x800F4338u;
    ctx->downcount -= 22;
    // 800F4338: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F433C:
    ctx->pc = 0x800F433Cu;
    // 800F433C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4340:
    ctx->pc = 0x800F4340u;
    // 800F4340: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4340u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F4344:
    ctx->pc = 0x800F4344u;
    // 800F4344: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4348:
    ctx->pc = 0x800F4348u;
    // 800F4348: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F434C:
    ctx->pc = 0x800F434Cu;
    // 800F434C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4350:
    ctx->pc = 0x800F4350u;
    // 800F4350: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4354:
    ctx->pc = 0x800F4354u;
    // 800F4354: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4358:
    ctx->pc = 0x800F4358u;
    // 800F4358: lfs     f31, -10352(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F4358u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10352);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F435C:
    ctx->pc = 0x800F435Cu;
    // 800F435C: addi    r4, r4, -12884
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12884);

label_800F4360:
    ctx->pc = 0x800F4360u;
    // 800F4360: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4364:
    ctx->pc = 0x800F4364u;
    // 800F4364: bl      0x800EFF24
    {
            ctx->lr = 0x800F4368u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4368:
    ctx->pc = 0x800F4368u;
    ctx->downcount -= 9;
    // 800F4368: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F436C:
    ctx->pc = 0x800F436Cu;
    // 800F436C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F4370:
    ctx->pc = 0x800F4370u;
    // 800F4370: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F4374:
    ctx->pc = 0x800F4374u;
    // 800F4374: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F4378:
    ctx->pc = 0x800F4378u;
    // 800F4378: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4378u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F437C:
    ctx->pc = 0x800F437Cu;
    // 800F437C: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4380:
    ctx->pc = 0x800F4380u;
    // 800F4380: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F4384:
    ctx->pc = 0x800F4384u;
    // 800F4384: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4388:
    ctx->pc = 0x800F4388u;
    // 800F4388: bl      0x80289138
    {
            ctx->lr = 0x800F438Cu;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F438C:
    ctx->pc = 0x800F438Cu;
    ctx->downcount -= 33;
    // 800F438C: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4390:
    ctx->pc = 0x800F4390u;
    // 800F4390: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F4394:
    ctx->pc = 0x800F4394u;
    // 800F4394: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F4398:
    ctx->pc = 0x800F4398u;
    // 800F4398: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F439C:
    ctx->pc = 0x800F439Cu;
    // 800F439C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F43A0:
    ctx->pc = 0x800F43A0u;
    // 800F43A0: lfd     f13, -10344(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F43A0u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10344);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F43A4:
    ctx->pc = 0x800F43A4u;
    // 800F43A4: addi    r9, r9, -9328
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9328);

label_800F43A8:
    ctx->pc = 0x800F43A8u;
    // 800F43A8: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F43AC:
    ctx->pc = 0x800F43ACu;
    // 800F43AC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F43B0:
    ctx->pc = 0x800F43B0u;
    // 800F43B0: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F43B0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F43B4:
    ctx->pc = 0x800F43B4u;
    // 800F43B4: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F43B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F43B8:
    ctx->pc = 0x800F43B8u;
    // 800F43B8: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F43BC:
    ctx->pc = 0x800F43BCu;
    // 800F43BC: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F43BCu)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F43C0:
    ctx->pc = 0x800F43C0u;
    // 800F43C0: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F43C0u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F43C4:
    ctx->pc = 0x800F43C4u;
    // 800F43C4: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F43C4u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F43C8:
    ctx->pc = 0x800F43C8u;
    // 800F43C8: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F43C8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F43CC:
    ctx->pc = 0x800F43CCu;
    // 800F43CC: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F43D0:
    ctx->pc = 0x800F43D0u;
    // 800F43D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F43D4:
    ctx->pc = 0x800F43D4u;
    // 800F43D4: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F43D8:
    ctx->pc = 0x800F43D8u;
    // 800F43D8: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F43D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F43DC:
    ctx->pc = 0x800F43DCu;
    // 800F43DC: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F43E0:
    ctx->pc = 0x800F43E0u;
    // 800F43E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F43E4:
    ctx->pc = 0x800F43E4u;
    ctx->downcount -= 19;
    // 800F43E4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F43E8:
    ctx->pc = 0x800F43E8u;
    // 800F43E8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F43EC:
    ctx->pc = 0x800F43ECu;
    // 800F43EC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F43F0:
    ctx->pc = 0x800F43F0u;
    // 800F43F0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F43F4:
    ctx->pc = 0x800F43F4u;
    // 800F43F4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F43F8:
    ctx->pc = 0x800F43F8u;
    // 800F43F8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F43FC:
    ctx->pc = 0x800F43FCu;
    // 800F43FC: addi    r4, r4, -12864
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12864);

label_800F4400:
    ctx->pc = 0x800F4400u;
    // 800F4400: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4404:
    ctx->pc = 0x800F4404u;
    // 800F4404: bl      0x800F0C70
    {
            ctx->lr = 0x800F4408u;
            ctx->pc = 0x800F0C70u;
            return;
    }

label_800F4408:
    ctx->pc = 0x800F4408u;
    ctx->downcount -= 20;
    // 800F4408: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F440C:
    ctx->pc = 0x800F440Cu;
    // 800F440C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4410:
    ctx->pc = 0x800F4410u;
    // 800F4410: addi    r9, r9, -9408
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9408);

label_800F4414:
    ctx->pc = 0x800F4414u;
    // 800F4414: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4418:
    ctx->pc = 0x800F4418u;
    // 800F4418: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F441C:
    ctx->pc = 0x800F441Cu;
    // 800F441C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4420:
    ctx->pc = 0x800F4420u;
    // 800F4420: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4424:
    ctx->pc = 0x800F4424u;
    // 800F4424: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4428:
    ctx->pc = 0x800F4428u;
    // 800F4428: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F442C:
    ctx->pc = 0x800F442Cu;
    ctx->downcount -= 22;
    // 800F442C: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4430:
    ctx->pc = 0x800F4430u;
    // 800F4430: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4434:
    ctx->pc = 0x800F4434u;
    // 800F4434: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4434u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F4438:
    ctx->pc = 0x800F4438u;
    // 800F4438: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F443C:
    ctx->pc = 0x800F443Cu;
    // 800F443C: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4440:
    ctx->pc = 0x800F4440u;
    // 800F4440: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4444:
    ctx->pc = 0x800F4444u;
    // 800F4444: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4448:
    ctx->pc = 0x800F4448u;
    // 800F4448: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F444C:
    ctx->pc = 0x800F444Cu;
    // 800F444C: lfs     f31, -10336(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F444Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10336);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F4450:
    ctx->pc = 0x800F4450u;
    // 800F4450: addi    r4, r4, -12840
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12840);

label_800F4454:
    ctx->pc = 0x800F4454u;
    // 800F4454: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4458:
    ctx->pc = 0x800F4458u;
    // 800F4458: bl      0x800EFF24
    {
            ctx->lr = 0x800F445Cu;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F445C:
    ctx->pc = 0x800F445Cu;
    ctx->downcount -= 9;
    // 800F445C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4460:
    ctx->pc = 0x800F4460u;
    // 800F4460: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F4464:
    ctx->pc = 0x800F4464u;
    // 800F4464: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F4468:
    ctx->pc = 0x800F4468u;
    // 800F4468: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F446C:
    ctx->pc = 0x800F446Cu;
    // 800F446C: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F446Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F4470:
    ctx->pc = 0x800F4470u;
    // 800F4470: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4474:
    ctx->pc = 0x800F4474u;
    // 800F4474: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F4478:
    ctx->pc = 0x800F4478u;
    // 800F4478: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F447C:
    ctx->pc = 0x800F447Cu;
    // 800F447C: bl      0x80289138
    {
            ctx->lr = 0x800F4480u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F4480:
    ctx->pc = 0x800F4480u;
    ctx->downcount -= 33;
    // 800F4480: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4484:
    ctx->pc = 0x800F4484u;
    // 800F4484: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F4488:
    ctx->pc = 0x800F4488u;
    // 800F4488: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F448C:
    ctx->pc = 0x800F448Cu;
    // 800F448C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4490:
    ctx->pc = 0x800F4490u;
    // 800F4490: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4494:
    ctx->pc = 0x800F4494u;
    // 800F4494: lfd     f13, -10328(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F4494u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10328);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4498:
    ctx->pc = 0x800F4498u;
    // 800F4498: addi    r9, r9, -9488
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9488);

label_800F449C:
    ctx->pc = 0x800F449Cu;
    // 800F449C: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F44A0:
    ctx->pc = 0x800F44A0u;
    // 800F44A0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F44A4:
    ctx->pc = 0x800F44A4u;
    // 800F44A4: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F44A4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F44A8:
    ctx->pc = 0x800F44A8u;
    // 800F44A8: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F44A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F44AC:
    ctx->pc = 0x800F44ACu;
    // 800F44AC: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F44B0:
    ctx->pc = 0x800F44B0u;
    // 800F44B0: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F44B0u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F44B4:
    ctx->pc = 0x800F44B4u;
    // 800F44B4: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F44B4u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F44B8:
    ctx->pc = 0x800F44B8u;
    // 800F44B8: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F44B8u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F44BC:
    ctx->pc = 0x800F44BCu;
    // 800F44BC: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F44BCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F44C0:
    ctx->pc = 0x800F44C0u;
    // 800F44C0: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F44C4:
    ctx->pc = 0x800F44C4u;
    // 800F44C4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F44C8:
    ctx->pc = 0x800F44C8u;
    // 800F44C8: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F44CC:
    ctx->pc = 0x800F44CCu;
    // 800F44CC: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F44CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F44D0:
    ctx->pc = 0x800F44D0u;
    // 800F44D0: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F44D4:
    ctx->pc = 0x800F44D4u;
    // 800F44D4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F44D8:
    ctx->pc = 0x800F44D8u;
    ctx->downcount -= 22;
    // 800F44D8: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F44DC:
    ctx->pc = 0x800F44DCu;
    // 800F44DC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F44E0:
    ctx->pc = 0x800F44E0u;
    // 800F44E0: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F44E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F44E4:
    ctx->pc = 0x800F44E4u;
    // 800F44E4: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F44E8:
    ctx->pc = 0x800F44E8u;
    // 800F44E8: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F44EC:
    ctx->pc = 0x800F44ECu;
    // 800F44EC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F44F0:
    ctx->pc = 0x800F44F0u;
    // 800F44F0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F44F4:
    ctx->pc = 0x800F44F4u;
    // 800F44F4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F44F8:
    ctx->pc = 0x800F44F8u;
    // 800F44F8: lfs     f31, -10320(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F44F8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10320);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F44FC:
    ctx->pc = 0x800F44FCu;
    // 800F44FC: addi    r4, r4, -12816
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12816);

label_800F4500:
    ctx->pc = 0x800F4500u;
    // 800F4500: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4504:
    ctx->pc = 0x800F4504u;
    // 800F4504: bl      0x800EFF24
    {
            ctx->lr = 0x800F4508u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4508:
    ctx->pc = 0x800F4508u;
    ctx->downcount -= 9;
    // 800F4508: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F450C:
    ctx->pc = 0x800F450Cu;
    // 800F450C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F4510:
    ctx->pc = 0x800F4510u;
    // 800F4510: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F4514:
    ctx->pc = 0x800F4514u;
    // 800F4514: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F4518:
    ctx->pc = 0x800F4518u;
    // 800F4518: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4518u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F451C:
    ctx->pc = 0x800F451Cu;
    // 800F451C: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4520:
    ctx->pc = 0x800F4520u;
    // 800F4520: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F4524:
    ctx->pc = 0x800F4524u;
    // 800F4524: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4528:
    ctx->pc = 0x800F4528u;
    // 800F4528: bl      0x80289138
    {
            ctx->lr = 0x800F452Cu;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F452C:
    ctx->pc = 0x800F452Cu;
    ctx->downcount -= 33;
    // 800F452C: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4530:
    ctx->pc = 0x800F4530u;
    // 800F4530: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F4534:
    ctx->pc = 0x800F4534u;
    // 800F4534: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F4538:
    ctx->pc = 0x800F4538u;
    // 800F4538: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F453C:
    ctx->pc = 0x800F453Cu;
    // 800F453C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4540:
    ctx->pc = 0x800F4540u;
    // 800F4540: lfd     f13, -10312(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F4540u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10312);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4544:
    ctx->pc = 0x800F4544u;
    // 800F4544: addi    r9, r9, -9568
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9568);

label_800F4548:
    ctx->pc = 0x800F4548u;
    // 800F4548: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F454C:
    ctx->pc = 0x800F454Cu;
    // 800F454C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4550:
    ctx->pc = 0x800F4550u;
    // 800F4550: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F4550u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F4554:
    ctx->pc = 0x800F4554u;
    // 800F4554: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4554u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4558:
    ctx->pc = 0x800F4558u;
    // 800F4558: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F455C:
    ctx->pc = 0x800F455Cu;
    // 800F455C: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F455Cu)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F4560:
    ctx->pc = 0x800F4560u;
    // 800F4560: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F4560u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F4564:
    ctx->pc = 0x800F4564u;
    // 800F4564: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F4564u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F4568:
    ctx->pc = 0x800F4568u;
    // 800F4568: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4568u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F456C:
    ctx->pc = 0x800F456Cu;
    // 800F456C: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4570:
    ctx->pc = 0x800F4570u;
    // 800F4570: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4574:
    ctx->pc = 0x800F4574u;
    // 800F4574: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4578:
    ctx->pc = 0x800F4578u;
    // 800F4578: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4578u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F457C:
    ctx->pc = 0x800F457Cu;
    // 800F457C: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F4580:
    ctx->pc = 0x800F4580u;
    // 800F4580: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4584:
    ctx->pc = 0x800F4584u;
    ctx->downcount -= 7;
    // 800F4584: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4588:
    ctx->pc = 0x800F4588u;
    // 800F4588: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F458C:
    ctx->pc = 0x800F458Cu;
    // 800F458C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800F4590:
    ctx->pc = 0x800F4590u;
    // 800F4590: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4594:
    ctx->pc = 0x800F4594u;
    // 800F4594: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4598:
    ctx->pc = 0x800F4598u;
    // 800F4598: lwz     r3, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F459C:
    ctx->pc = 0x800F459Cu;
    // 800F459C: bl      0x8028CAA4
    {
            ctx->lr = 0x800F45A0u;
            ctx->pc = 0x8028CAA4u;
            return;
    }

label_800F45A0:
    ctx->pc = 0x800F45A0u;
    ctx->downcount -= 3;
    // 800F45A0: lwz     r11, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F45A4:
    ctx->pc = 0x800F45A4u;
    // 800F45A4: cmpwi   r11, 1
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800F45A8:
    ctx->pc = 0x800F45A8u;
    // 800F45A8: bc    4, 2, 0x800F45E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F45E8;
        }
    }

label_800F45AC:
    ctx->pc = 0x800F45ACu;
    ctx->downcount -= 5;
    // 800F45AC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F45B0:
    ctx->pc = 0x800F45B0u;
    // 800F45B0: stw     r0, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F45B4:
    ctx->pc = 0x800F45B4u;
    // 800F45B4: lwz     r9, 140(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(140);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F45B8:
    ctx->pc = 0x800F45B8u;
    // 800F45B8: cmpwi   r9, 0
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

label_800F45BC:
    ctx->pc = 0x800F45BCu;
    // 800F45BC: bc    12, 2, 0x800F45D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F45D4;
        }
    }

label_800F45C0:
    ctx->pc = 0x800F45C0u;
    ctx->downcount -= 3;
    // 800F45C0: lwz     r0, -25064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25064);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F45C4:
    ctx->pc = 0x800F45C4u;
    // 800F45C4: cmpwi   r0, 4
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

label_800F45C8:
    ctx->pc = 0x800F45C8u;
    // 800F45C8: bc    4, 2, 0x800F45D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F45D4;
        }
    }

label_800F45CC:
    ctx->pc = 0x800F45CCu;
    ctx->downcount -= 2;
    // 800F45CC: stw     r11, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F45D0:
    ctx->pc = 0x800F45D0u;
    // 800F45D0: b       0x800F45E8
    {
            goto label_800F45E8;
    }

label_800F45D4:
    ctx->pc = 0x800F45D4u;
    ctx->downcount -= 3;
    // 800F45D4: lwz     r0, -25064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25064);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F45D8:
    ctx->pc = 0x800F45D8u;
    // 800F45D8: cmpwi   r0, 3
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

label_800F45DC:
    ctx->pc = 0x800F45DCu;
    // 800F45DC: bc    4, 2, 0x800F45E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F45E8;
        }
    }

label_800F45E0:
    ctx->pc = 0x800F45E0u;
    ctx->downcount -= 2;
    // 800F45E0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F45E4:
    ctx->pc = 0x800F45E4u;
    // 800F45E4: stw     r0, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F45E8:
    ctx->pc = 0x800F45E8u;
    ctx->downcount -= 2;
    // 800F45E8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F45EC:
    ctx->pc = 0x800F45ECu;
    // 800F45EC: bl      0x800F09AC
    {
            ctx->lr = 0x800F45F0u;
            ctx->pc = 0x800F09ACu;
            return;
    }

label_800F45F0:
    ctx->pc = 0x800F45F0u;
    ctx->downcount -= 6;
    // 800F45F0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F45F4:
    ctx->pc = 0x800F45F4u;
    // 800F45F4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F45F8:
    ctx->pc = 0x800F45F8u;
    // 800F45F8: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800F45FC:
    ctx->pc = 0x800F45FCu;
    // 800F45FC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4600:
    ctx->pc = 0x800F4600u;
    // 800F4600: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4604:
    ctx->pc = 0x800F4604u;
    ctx->downcount -= 20;
    // 800F4604: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4608:
    ctx->pc = 0x800F4608u;
    // 800F4608: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F460C:
    ctx->pc = 0x800F460Cu;
    // 800F460C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4610:
    ctx->pc = 0x800F4610u;
    // 800F4610: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4614:
    ctx->pc = 0x800F4614u;
    // 800F4614: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4618:
    ctx->pc = 0x800F4618u;
    // 800F4618: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F461C:
    ctx->pc = 0x800F461Cu;
    // 800F461C: addi    r4, r4, -12776
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12776);

label_800F4620:
    ctx->pc = 0x800F4620u;
    // 800F4620: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4624:
    ctx->pc = 0x800F4624u;
    // 800F4624: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F4628:
    ctx->pc = 0x800F4628u;
    // 800F4628: bl      0x800F1B90
    {
            ctx->lr = 0x800F462Cu;
            ctx->pc = 0x800F1B90u;
            return;
    }

label_800F462C:
    ctx->pc = 0x800F462Cu;
    ctx->downcount -= 20;
    // 800F462C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4630:
    ctx->pc = 0x800F4630u;
    // 800F4630: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4634:
    ctx->pc = 0x800F4634u;
    // 800F4634: addi    r9, r9, -9648
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9648);

label_800F4638:
    ctx->pc = 0x800F4638u;
    // 800F4638: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F463C:
    ctx->pc = 0x800F463Cu;
    // 800F463C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4640:
    ctx->pc = 0x800F4640u;
    // 800F4640: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4644:
    ctx->pc = 0x800F4644u;
    // 800F4644: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4648:
    ctx->pc = 0x800F4648u;
    // 800F4648: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F464C:
    ctx->pc = 0x800F464Cu;
    // 800F464C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4650:
    ctx->pc = 0x800F4650u;
    ctx->downcount -= 20;
    // 800F4650: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4654:
    ctx->pc = 0x800F4654u;
    // 800F4654: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4658:
    ctx->pc = 0x800F4658u;
    // 800F4658: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F465C:
    ctx->pc = 0x800F465Cu;
    // 800F465C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4660:
    ctx->pc = 0x800F4660u;
    // 800F4660: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4664:
    ctx->pc = 0x800F4664u;
    // 800F4664: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4668:
    ctx->pc = 0x800F4668u;
    // 800F4668: addi    r4, r4, -12744
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12744);

label_800F466C:
    ctx->pc = 0x800F466Cu;
    // 800F466C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_800F4670:
    ctx->pc = 0x800F4670u;
    // 800F4670: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F4674:
    ctx->pc = 0x800F4674u;
    // 800F4674: bl      0x800F1B90
    {
            ctx->lr = 0x800F4678u;
            ctx->pc = 0x800F1B90u;
            return;
    }

label_800F4678:
    ctx->pc = 0x800F4678u;
    ctx->downcount -= 20;
    // 800F4678: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F467C:
    ctx->pc = 0x800F467Cu;
    // 800F467C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4680:
    ctx->pc = 0x800F4680u;
    // 800F4680: addi    r9, r9, -9728
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9728);

label_800F4684:
    ctx->pc = 0x800F4684u;
    // 800F4684: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4688:
    ctx->pc = 0x800F4688u;
    // 800F4688: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F468C:
    ctx->pc = 0x800F468Cu;
    // 800F468C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4690:
    ctx->pc = 0x800F4690u;
    // 800F4690: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4694:
    ctx->pc = 0x800F4694u;
    // 800F4694: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4698:
    ctx->pc = 0x800F4698u;
    // 800F4698: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F469C:
    ctx->pc = 0x800F469Cu;
    ctx->downcount -= 20;
    // 800F469C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F46A0:
    ctx->pc = 0x800F46A0u;
    // 800F46A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F46A4:
    ctx->pc = 0x800F46A4u;
    // 800F46A4: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F46A8:
    ctx->pc = 0x800F46A8u;
    // 800F46A8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F46AC:
    ctx->pc = 0x800F46ACu;
    // 800F46AC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F46B0:
    ctx->pc = 0x800F46B0u;
    // 800F46B0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F46B4:
    ctx->pc = 0x800F46B4u;
    // 800F46B4: addi    r4, r4, -12712
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12712);

label_800F46B8:
    ctx->pc = 0x800F46B8u;
    // 800F46B8: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_800F46BC:
    ctx->pc = 0x800F46BCu;
    // 800F46BC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F46C0:
    ctx->pc = 0x800F46C0u;
    // 800F46C0: bl      0x800F1B90
    {
            ctx->lr = 0x800F46C4u;
            ctx->pc = 0x800F1B90u;
            return;
    }

label_800F46C4:
    ctx->pc = 0x800F46C4u;
    ctx->downcount -= 20;
    // 800F46C4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F46C8:
    ctx->pc = 0x800F46C8u;
    // 800F46C8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F46CC:
    ctx->pc = 0x800F46CCu;
    // 800F46CC: addi    r9, r9, -9808
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9808);

label_800F46D0:
    ctx->pc = 0x800F46D0u;
    // 800F46D0: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F46D4:
    ctx->pc = 0x800F46D4u;
    // 800F46D4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F46D8:
    ctx->pc = 0x800F46D8u;
    // 800F46D8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F46DC:
    ctx->pc = 0x800F46DCu;
    // 800F46DC: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F46E0:
    ctx->pc = 0x800F46E0u;
    // 800F46E0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F46E4:
    ctx->pc = 0x800F46E4u;
    // 800F46E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F46E8:
    ctx->pc = 0x800F46E8u;
    ctx->downcount -= 20;
    // 800F46E8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F46EC:
    ctx->pc = 0x800F46ECu;
    // 800F46EC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F46F0:
    ctx->pc = 0x800F46F0u;
    // 800F46F0: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F46F4:
    ctx->pc = 0x800F46F4u;
    // 800F46F4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F46F8:
    ctx->pc = 0x800F46F8u;
    // 800F46F8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F46FC:
    ctx->pc = 0x800F46FCu;
    // 800F46FC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4700:
    ctx->pc = 0x800F4700u;
    // 800F4700: addi    r4, r4, -12680
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12680);

label_800F4704:
    ctx->pc = 0x800F4704u;
    // 800F4704: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_800F4708:
    ctx->pc = 0x800F4708u;
    // 800F4708: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F470C:
    ctx->pc = 0x800F470Cu;
    // 800F470C: bl      0x800F1B90
    {
            ctx->lr = 0x800F4710u;
            ctx->pc = 0x800F1B90u;
            return;
    }

label_800F4710:
    ctx->pc = 0x800F4710u;
    ctx->downcount -= 20;
    // 800F4710: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4714:
    ctx->pc = 0x800F4714u;
    // 800F4714: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4718:
    ctx->pc = 0x800F4718u;
    // 800F4718: addi    r9, r9, -9888
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9888);

label_800F471C:
    ctx->pc = 0x800F471Cu;
    // 800F471C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4720:
    ctx->pc = 0x800F4720u;
    // 800F4720: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4724:
    ctx->pc = 0x800F4724u;
    // 800F4724: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4728:
    ctx->pc = 0x800F4728u;
    // 800F4728: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F472C:
    ctx->pc = 0x800F472Cu;
    // 800F472C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4730:
    ctx->pc = 0x800F4730u;
    // 800F4730: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4734:
    ctx->pc = 0x800F4734u;
    ctx->downcount -= 20;
    // 800F4734: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4738:
    ctx->pc = 0x800F4738u;
    // 800F4738: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F473C:
    ctx->pc = 0x800F473Cu;
    // 800F473C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4740:
    ctx->pc = 0x800F4740u;
    // 800F4740: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4744:
    ctx->pc = 0x800F4744u;
    // 800F4744: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4748:
    ctx->pc = 0x800F4748u;
    // 800F4748: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F474C:
    ctx->pc = 0x800F474Cu;
    // 800F474C: addi    r4, r4, -12648
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12648);

label_800F4750:
    ctx->pc = 0x800F4750u;
    // 800F4750: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4754:
    ctx->pc = 0x800F4754u;
    // 800F4754: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_800F4758:
    ctx->pc = 0x800F4758u;
    // 800F4758: bl      0x800F1B90
    {
            ctx->lr = 0x800F475Cu;
            ctx->pc = 0x800F1B90u;
            return;
    }

label_800F475C:
    ctx->pc = 0x800F475Cu;
    ctx->downcount -= 20;
    // 800F475C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4760:
    ctx->pc = 0x800F4760u;
    // 800F4760: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4764:
    ctx->pc = 0x800F4764u;
    // 800F4764: addi    r9, r9, -9968
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9968);

label_800F4768:
    ctx->pc = 0x800F4768u;
    // 800F4768: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F476C:
    ctx->pc = 0x800F476Cu;
    // 800F476C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4770:
    ctx->pc = 0x800F4770u;
    // 800F4770: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4774:
    ctx->pc = 0x800F4774u;
    // 800F4774: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4778:
    ctx->pc = 0x800F4778u;
    // 800F4778: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F477C:
    ctx->pc = 0x800F477Cu;
    // 800F477C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4780:
    ctx->pc = 0x800F4780u;
    ctx->downcount -= 20;
    // 800F4780: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4784:
    ctx->pc = 0x800F4784u;
    // 800F4784: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4788:
    ctx->pc = 0x800F4788u;
    // 800F4788: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F478C:
    ctx->pc = 0x800F478Cu;
    // 800F478C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4790:
    ctx->pc = 0x800F4790u;
    // 800F4790: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4794:
    ctx->pc = 0x800F4794u;
    // 800F4794: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4798:
    ctx->pc = 0x800F4798u;
    // 800F4798: addi    r4, r4, -12616
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12616);

label_800F479C:
    ctx->pc = 0x800F479Cu;
    // 800F479C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_800F47A0:
    ctx->pc = 0x800F47A0u;
    // 800F47A0: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_800F47A4:
    ctx->pc = 0x800F47A4u;
    // 800F47A4: bl      0x800F1B90
    {
            ctx->lr = 0x800F47A8u;
            ctx->pc = 0x800F1B90u;
            return;
    }

label_800F47A8:
    ctx->pc = 0x800F47A8u;
    ctx->downcount -= 20;
    // 800F47A8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F47AC:
    ctx->pc = 0x800F47ACu;
    // 800F47AC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F47B0:
    ctx->pc = 0x800F47B0u;
    // 800F47B0: addi    r9, r9, -10048
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10048);

label_800F47B4:
    ctx->pc = 0x800F47B4u;
    // 800F47B4: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F47B8:
    ctx->pc = 0x800F47B8u;
    // 800F47B8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F47BC:
    ctx->pc = 0x800F47BCu;
    // 800F47BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F47C0:
    ctx->pc = 0x800F47C0u;
    // 800F47C0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F47C4:
    ctx->pc = 0x800F47C4u;
    // 800F47C4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F47C8:
    ctx->pc = 0x800F47C8u;
    // 800F47C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F47CC:
    ctx->pc = 0x800F47CCu;
    ctx->downcount -= 20;
    // 800F47CC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F47D0:
    ctx->pc = 0x800F47D0u;
    // 800F47D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F47D4:
    ctx->pc = 0x800F47D4u;
    // 800F47D4: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F47D8:
    ctx->pc = 0x800F47D8u;
    // 800F47D8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F47DC:
    ctx->pc = 0x800F47DCu;
    // 800F47DC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F47E0:
    ctx->pc = 0x800F47E0u;
    // 800F47E0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F47E4:
    ctx->pc = 0x800F47E4u;
    // 800F47E4: addi    r4, r4, -12584
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12584);

label_800F47E8:
    ctx->pc = 0x800F47E8u;
    // 800F47E8: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_800F47EC:
    ctx->pc = 0x800F47ECu;
    // 800F47EC: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_800F47F0:
    ctx->pc = 0x800F47F0u;
    // 800F47F0: bl      0x800F1B90
    {
            ctx->lr = 0x800F47F4u;
            ctx->pc = 0x800F1B90u;
            return;
    }

label_800F47F4:
    ctx->pc = 0x800F47F4u;
    ctx->downcount -= 20;
    // 800F47F4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F47F8:
    ctx->pc = 0x800F47F8u;
    // 800F47F8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F47FC:
    ctx->pc = 0x800F47FCu;
    // 800F47FC: addi    r9, r9, -10128
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10128);

label_800F4800:
    ctx->pc = 0x800F4800u;
    // 800F4800: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4804:
    ctx->pc = 0x800F4804u;
    // 800F4804: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4808:
    ctx->pc = 0x800F4808u;
    // 800F4808: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F480C:
    ctx->pc = 0x800F480Cu;
    // 800F480C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4810:
    ctx->pc = 0x800F4810u;
    // 800F4810: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4814:
    ctx->pc = 0x800F4814u;
    // 800F4814: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4818:
    ctx->pc = 0x800F4818u;
    ctx->downcount -= 20;
    // 800F4818: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F481C:
    ctx->pc = 0x800F481Cu;
    // 800F481C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4820:
    ctx->pc = 0x800F4820u;
    // 800F4820: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4824:
    ctx->pc = 0x800F4824u;
    // 800F4824: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4828:
    ctx->pc = 0x800F4828u;
    // 800F4828: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F482C:
    ctx->pc = 0x800F482Cu;
    // 800F482C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4830:
    ctx->pc = 0x800F4830u;
    // 800F4830: addi    r4, r4, -12552
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12552);

label_800F4834:
    ctx->pc = 0x800F4834u;
    // 800F4834: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_800F4838:
    ctx->pc = 0x800F4838u;
    // 800F4838: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_800F483C:
    ctx->pc = 0x800F483Cu;
    // 800F483C: bl      0x800F1B90
    {
            ctx->lr = 0x800F4840u;
            ctx->pc = 0x800F1B90u;
            return;
    }

label_800F4840:
    ctx->pc = 0x800F4840u;
    ctx->downcount -= 20;
    // 800F4840: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4844:
    ctx->pc = 0x800F4844u;
    // 800F4844: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4848:
    ctx->pc = 0x800F4848u;
    // 800F4848: addi    r9, r9, -10208
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10208);

label_800F484C:
    ctx->pc = 0x800F484Cu;
    // 800F484C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4850:
    ctx->pc = 0x800F4850u;
    // 800F4850: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4854:
    ctx->pc = 0x800F4854u;
    // 800F4854: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4858:
    ctx->pc = 0x800F4858u;
    // 800F4858: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F485C:
    ctx->pc = 0x800F485Cu;
    // 800F485C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4860:
    ctx->pc = 0x800F4860u;
    // 800F4860: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4864:
    ctx->pc = 0x800F4864u;
    ctx->downcount -= 16;
    // 800F4864: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4868:
    ctx->pc = 0x800F4868u;
    // 800F4868: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F486C:
    ctx->pc = 0x800F486Cu;
    // 800F486C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4870:
    ctx->pc = 0x800F4870u;
    // 800F4870: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4874:
    ctx->pc = 0x800F4874u;
    // 800F4874: li      r3, 44
    ctx->gpr[3] = (u32)(s32)(44);

label_800F4878:
    ctx->pc = 0x800F4878u;
    // 800F4878: bl      0x80281C60
    {
            ctx->lr = 0x800F487Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F487C:
    ctx->pc = 0x800F487Cu;
    ctx->downcount -= 5;
    // 800F487C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4880:
    ctx->pc = 0x800F4880u;
    // 800F4880: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4884:
    ctx->pc = 0x800F4884u;
    // 800F4884: addi    r4, r4, -13848
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13848);

label_800F4888:
    ctx->pc = 0x800F4888u;
    // 800F4888: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F488C:
    ctx->pc = 0x800F488Cu;
    // 800F488C: bl      0x800EFF24
    {
            ctx->lr = 0x800F4890u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4890:
    ctx->pc = 0x800F4890u;
    ctx->downcount -= 26;
    // 800F4890: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4894:
    ctx->pc = 0x800F4894u;
    // 800F4894: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_800F4898:
    ctx->pc = 0x800F4898u;
    // 800F4898: addi    r9, r9, -7648
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-7648);

label_800F489C:
    ctx->pc = 0x800F489Cu;
    // 800F489C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F48A0:
    ctx->pc = 0x800F48A0u;
    // 800F48A0: li      r10, 60
    ctx->gpr[10] = (u32)(s32)(60);

label_800F48A4:
    ctx->pc = 0x800F48A4u;
    // 800F48A4: stw     r11, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F48A8:
    ctx->pc = 0x800F48A8u;
    // 800F48A8: stw     r0, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F48AC:
    ctx->pc = 0x800F48ACu;
    // 800F48AC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F48B0:
    ctx->pc = 0x800F48B0u;
    // 800F48B0: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F48B4:
    ctx->pc = 0x800F48B4u;
    // 800F48B4: stw     r10, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800F48B8:
    ctx->pc = 0x800F48B8u;
    // 800F48B8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F48BC:
    ctx->pc = 0x800F48BCu;
    // 800F48BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F48C0:
    ctx->pc = 0x800F48C0u;
    // 800F48C0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F48C4:
    ctx->pc = 0x800F48C4u;
    // 800F48C4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F48C8:
    ctx->pc = 0x800F48C8u;
    // 800F48C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F48CC:
    ctx->pc = 0x800F48CCu;
    ctx->downcount -= 16;
    // 800F48CC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F48D0:
    ctx->pc = 0x800F48D0u;
    // 800F48D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F48D4:
    ctx->pc = 0x800F48D4u;
    // 800F48D4: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F48D8:
    ctx->pc = 0x800F48D8u;
    // 800F48D8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F48DC:
    ctx->pc = 0x800F48DCu;
    // 800F48DC: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F48E0:
    ctx->pc = 0x800F48E0u;
    // 800F48E0: bl      0x80281C60
    {
            ctx->lr = 0x800F48E4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F48E4:
    ctx->pc = 0x800F48E4u;
    ctx->downcount -= 4;
    // 800F48E4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F48E8:
    ctx->pc = 0x800F48E8u;
    // 800F48E8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F48EC:
    ctx->pc = 0x800F48ECu;
    // 800F48EC: addi    r4, r4, -13236
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13236);

label_800F48F0:
    ctx->pc = 0x800F48F0u;
    // 800F48F0: bl      0x800F0E48
    {
            ctx->lr = 0x800F48F4u;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F48F4:
    ctx->pc = 0x800F48F4u;
    ctx->downcount -= 20;
    // 800F48F4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F48F8:
    ctx->pc = 0x800F48F8u;
    // 800F48F8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F48FC:
    ctx->pc = 0x800F48FCu;
    // 800F48FC: addi    r9, r9, -8928
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8928);

label_800F4900:
    ctx->pc = 0x800F4900u;
    // 800F4900: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4904:
    ctx->pc = 0x800F4904u;
    // 800F4904: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4908:
    ctx->pc = 0x800F4908u;
    // 800F4908: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F490C:
    ctx->pc = 0x800F490Cu;
    // 800F490C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4910:
    ctx->pc = 0x800F4910u;
    // 800F4910: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4914:
    ctx->pc = 0x800F4914u;
    // 800F4914: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4918:
    ctx->pc = 0x800F4918u;
    ctx->downcount -= 2;
    // 800F4918: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F491C:
    ctx->pc = 0x800F491Cu;
    // 800F491C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4920:
    ctx->pc = 0x800F4920u;
    ctx->downcount -= 5;
    // 800F4920: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4924:
    ctx->pc = 0x800F4924u;
    // 800F4924: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4928:
    ctx->pc = 0x800F4928u;
    // 800F4928: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F492C:
    ctx->pc = 0x800F492Cu;
    // 800F492C: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F4930:
    ctx->pc = 0x800F4930u;
    // 800F4930: bl      0x80281C60
    {
            ctx->lr = 0x800F4934u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4934:
    ctx->pc = 0x800F4934u;
    ctx->downcount -= 1;
    // 800F4934: bl      0x800F1708
    {
            ctx->lr = 0x800F4938u;
            ctx->pc = 0x800F1708u;
            return;
    }

label_800F4938:
    ctx->pc = 0x800F4938u;
    ctx->downcount -= 5;
    // 800F4938: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F493C:
    ctx->pc = 0x800F493Cu;
    // 800F493C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4940:
    ctx->pc = 0x800F4940u;
    // 800F4940: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F4944:
    ctx->pc = 0x800F4944u;
    // 800F4944: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4948:
    ctx->pc = 0x800F4948u;
    ctx->downcount -= 5;
    // 800F4948: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F494C:
    ctx->pc = 0x800F494Cu;
    // 800F494C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4950:
    ctx->pc = 0x800F4950u;
    // 800F4950: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4954:
    ctx->pc = 0x800F4954u;
    // 800F4954: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F4958:
    ctx->pc = 0x800F4958u;
    // 800F4958: bl      0x80281C60
    {
            ctx->lr = 0x800F495Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F495C:
    ctx->pc = 0x800F495Cu;
    ctx->downcount -= 1;
    // 800F495C: bl      0x800F14C4
    {
            ctx->lr = 0x800F4960u;
            ctx->pc = 0x800F14C4u;
            return;
    }

label_800F4960:
    ctx->pc = 0x800F4960u;
    ctx->downcount -= 5;
    // 800F4960: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4964:
    ctx->pc = 0x800F4964u;
    // 800F4964: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4968:
    ctx->pc = 0x800F4968u;
    // 800F4968: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F496C:
    ctx->pc = 0x800F496Cu;
    // 800F496C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4970:
    ctx->pc = 0x800F4970u;
    ctx->downcount -= 17;
    // 800F4970: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4974:
    ctx->pc = 0x800F4974u;
    // 800F4974: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4978:
    ctx->pc = 0x800F4978u;
    // 800F4978: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4978u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F497C:
    ctx->pc = 0x800F497Cu;
    // 800F497C: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4980:
    ctx->pc = 0x800F4980u;
    // 800F4980: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4984:
    ctx->pc = 0x800F4984u;
    // 800F4984: li      r3, 48
    ctx->gpr[3] = (u32)(s32)(48);

label_800F4988:
    ctx->pc = 0x800F4988u;
    // 800F4988: bl      0x80281C60
    {
            ctx->lr = 0x800F498Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F498C:
    ctx->pc = 0x800F498Cu;
    ctx->downcount -= 7;
    // 800F498C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4990:
    ctx->pc = 0x800F4990u;
    // 800F4990: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4994:
    ctx->pc = 0x800F4994u;
    // 800F4994: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4998:
    ctx->pc = 0x800F4998u;
    // 800F4998: lfs     f31, -10304(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F4998u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10304);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F499C:
    ctx->pc = 0x800F499Cu;
    // 800F499C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F49A0:
    ctx->pc = 0x800F49A0u;
    // 800F49A0: addi    r4, r4, -13524
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13524);

label_800F49A4:
    ctx->pc = 0x800F49A4u;
    // 800F49A4: bl      0x800EFF24
    {
            ctx->lr = 0x800F49A8u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F49A8:
    ctx->pc = 0x800F49A8u;
    ctx->downcount -= 9;
    // 800F49A8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F49AC:
    ctx->pc = 0x800F49ACu;
    // 800F49AC: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_800F49B0:
    ctx->pc = 0x800F49B0u;
    // 800F49B0: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F49B4:
    ctx->pc = 0x800F49B4u;
    // 800F49B4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F49B8:
    ctx->pc = 0x800F49B8u;
    // 800F49B8: stw     r11, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F49BC:
    ctx->pc = 0x800F49BCu;
    // 800F49BC: stw     r0, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F49C0:
    ctx->pc = 0x800F49C0u;
    // 800F49C0: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F49C4:
    ctx->pc = 0x800F49C4u;
    // 800F49C4: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F49C4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F49C8:
    ctx->pc = 0x800F49C8u;
    // 800F49C8: bl      0x80289138
    {
            ctx->lr = 0x800F49CCu;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F49CC:
    ctx->pc = 0x800F49CCu;
    ctx->downcount -= 33;
    // 800F49CC: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F49D0:
    ctx->pc = 0x800F49D0u;
    // 800F49D0: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F49D4:
    ctx->pc = 0x800F49D4u;
    // 800F49D4: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F49D8:
    ctx->pc = 0x800F49D8u;
    // 800F49D8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F49DC:
    ctx->pc = 0x800F49DCu;
    // 800F49DC: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F49E0:
    ctx->pc = 0x800F49E0u;
    // 800F49E0: lfd     f13, -10296(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F49E0u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10296);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F49E4:
    ctx->pc = 0x800F49E4u;
    // 800F49E4: addi    r9, r9, -8208
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8208);

label_800F49E8:
    ctx->pc = 0x800F49E8u;
    // 800F49E8: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F49EC:
    ctx->pc = 0x800F49ECu;
    // 800F49EC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F49F0:
    ctx->pc = 0x800F49F0u;
    // 800F49F0: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F49F0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F49F4:
    ctx->pc = 0x800F49F4u;
    // 800F49F4: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F49F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F49F8:
    ctx->pc = 0x800F49F8u;
    // 800F49F8: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F49FC:
    ctx->pc = 0x800F49FCu;
    // 800F49FC: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F49FCu)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F4A00:
    ctx->pc = 0x800F4A00u;
    // 800F4A00: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F4A00u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F4A04:
    ctx->pc = 0x800F4A04u;
    // 800F4A04: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F4A04u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F4A08:
    ctx->pc = 0x800F4A08u;
    // 800F4A08: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4A08u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F4A0C:
    ctx->pc = 0x800F4A0Cu;
    // 800F4A0C: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4A10:
    ctx->pc = 0x800F4A10u;
    // 800F4A10: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4A14:
    ctx->pc = 0x800F4A14u;
    // 800F4A14: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4A18:
    ctx->pc = 0x800F4A18u;
    // 800F4A18: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4A18u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4A1C:
    ctx->pc = 0x800F4A1Cu;
    // 800F4A1C: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F4A20:
    ctx->pc = 0x800F4A20u;
    // 800F4A20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4A24:
    ctx->pc = 0x800F4A24u;
    ctx->downcount -= 2;
    // 800F4A24: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F4A28:
    ctx->pc = 0x800F4A28u;
    // 800F4A28: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4A2C:
    ctx->pc = 0x800F4A2Cu;
    ctx->downcount -= 17;
    // 800F4A2C: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4A30:
    ctx->pc = 0x800F4A30u;
    // 800F4A30: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4A34:
    ctx->pc = 0x800F4A34u;
    // 800F4A34: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4A34u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F4A38:
    ctx->pc = 0x800F4A38u;
    // 800F4A38: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4A3C:
    ctx->pc = 0x800F4A3Cu;
    // 800F4A3C: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4A40:
    ctx->pc = 0x800F4A40u;
    // 800F4A40: li      r3, 48
    ctx->gpr[3] = (u32)(s32)(48);

label_800F4A44:
    ctx->pc = 0x800F4A44u;
    // 800F4A44: bl      0x80281C60
    {
            ctx->lr = 0x800F4A48u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4A48:
    ctx->pc = 0x800F4A48u;
    ctx->downcount -= 7;
    // 800F4A48: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4A4C:
    ctx->pc = 0x800F4A4Cu;
    // 800F4A4C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4A50:
    ctx->pc = 0x800F4A50u;
    // 800F4A50: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4A54:
    ctx->pc = 0x800F4A54u;
    // 800F4A54: lfs     f31, -10288(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F4A54u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10288);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F4A58:
    ctx->pc = 0x800F4A58u;
    // 800F4A58: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4A5C:
    ctx->pc = 0x800F4A5Cu;
    // 800F4A5C: addi    r4, r4, -13356
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13356);

label_800F4A60:
    ctx->pc = 0x800F4A60u;
    // 800F4A60: bl      0x800EFF24
    {
            ctx->lr = 0x800F4A64u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4A64:
    ctx->pc = 0x800F4A64u;
    ctx->downcount -= 9;
    // 800F4A64: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4A68:
    ctx->pc = 0x800F4A68u;
    // 800F4A68: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_800F4A6C:
    ctx->pc = 0x800F4A6Cu;
    // 800F4A6C: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F4A70:
    ctx->pc = 0x800F4A70u;
    // 800F4A70: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F4A74:
    ctx->pc = 0x800F4A74u;
    // 800F4A74: stw     r11, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F4A78:
    ctx->pc = 0x800F4A78u;
    // 800F4A78: stw     r0, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4A7C:
    ctx->pc = 0x800F4A7Cu;
    // 800F4A7C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4A80:
    ctx->pc = 0x800F4A80u;
    // 800F4A80: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4A80u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F4A84:
    ctx->pc = 0x800F4A84u;
    // 800F4A84: bl      0x80289138
    {
            ctx->lr = 0x800F4A88u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F4A88:
    ctx->pc = 0x800F4A88u;
    ctx->downcount -= 33;
    // 800F4A88: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4A8C:
    ctx->pc = 0x800F4A8Cu;
    // 800F4A8C: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F4A90:
    ctx->pc = 0x800F4A90u;
    // 800F4A90: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F4A94:
    ctx->pc = 0x800F4A94u;
    // 800F4A94: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4A98:
    ctx->pc = 0x800F4A98u;
    // 800F4A98: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4A9C:
    ctx->pc = 0x800F4A9Cu;
    // 800F4A9C: lfd     f13, -10280(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F4A9Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10280);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4AA0:
    ctx->pc = 0x800F4AA0u;
    // 800F4AA0: addi    r9, r9, -8368
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8368);

label_800F4AA4:
    ctx->pc = 0x800F4AA4u;
    // 800F4AA4: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F4AA8:
    ctx->pc = 0x800F4AA8u;
    // 800F4AA8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4AAC:
    ctx->pc = 0x800F4AACu;
    // 800F4AAC: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F4AACu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F4AB0:
    ctx->pc = 0x800F4AB0u;
    // 800F4AB0: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4AB0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4AB4:
    ctx->pc = 0x800F4AB4u;
    // 800F4AB4: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4AB8:
    ctx->pc = 0x800F4AB8u;
    // 800F4AB8: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F4AB8u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F4ABC:
    ctx->pc = 0x800F4ABCu;
    // 800F4ABC: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F4ABCu)) return;
    ppc_frsp(ctx, 0, 0);

label_800F4AC0:
    ctx->pc = 0x800F4AC0u;
    // 800F4AC0: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F4AC0u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F4AC4:
    ctx->pc = 0x800F4AC4u;
    // 800F4AC4: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4AC4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F4AC8:
    ctx->pc = 0x800F4AC8u;
    // 800F4AC8: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4ACC:
    ctx->pc = 0x800F4ACCu;
    // 800F4ACC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4AD0:
    ctx->pc = 0x800F4AD0u;
    // 800F4AD0: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4AD4:
    ctx->pc = 0x800F4AD4u;
    // 800F4AD4: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4AD4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4AD8:
    ctx->pc = 0x800F4AD8u;
    // 800F4AD8: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F4ADC:
    ctx->pc = 0x800F4ADCu;
    // 800F4ADC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4AE0:
    ctx->pc = 0x800F4AE0u;
    ctx->downcount -= 17;
    // 800F4AE0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4AE4:
    ctx->pc = 0x800F4AE4u;
    // 800F4AE4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4AE8:
    ctx->pc = 0x800F4AE8u;
    // 800F4AE8: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4AEC:
    ctx->pc = 0x800F4AECu;
    // 800F4AEC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4AF0:
    ctx->pc = 0x800F4AF0u;
    // 800F4AF0: li      r3, 44
    ctx->gpr[3] = (u32)(s32)(44);

label_800F4AF4:
    ctx->pc = 0x800F4AF4u;
    // 800F4AF4: li      r29, 4
    ctx->gpr[29] = (u32)(s32)(4);

label_800F4AF8:
    ctx->pc = 0x800F4AF8u;
    // 800F4AF8: bl      0x80281C60
    {
            ctx->lr = 0x800F4AFCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4AFC:
    ctx->pc = 0x800F4AFCu;
    ctx->downcount -= 5;
    // 800F4AFC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4B00:
    ctx->pc = 0x800F4B00u;
    // 800F4B00: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4B04:
    ctx->pc = 0x800F4B04u;
    // 800F4B04: addi    r4, r4, -13496
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13496);

label_800F4B08:
    ctx->pc = 0x800F4B08u;
    // 800F4B08: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4B0C:
    ctx->pc = 0x800F4B0Cu;
    // 800F4B0C: bl      0x800EFF24
    {
            ctx->lr = 0x800F4B10u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4B10:
    ctx->pc = 0x800F4B10u;
    ctx->downcount -= 25;
    // 800F4B10: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4B14:
    ctx->pc = 0x800F4B14u;
    // 800F4B14: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F4B18:
    ctx->pc = 0x800F4B18u;
    // 800F4B18: addi    r9, r9, -8288
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8288);

label_800F4B1C:
    ctx->pc = 0x800F4B1Cu;
    // 800F4B1C: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F4B20:
    ctx->pc = 0x800F4B20u;
    // 800F4B20: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4B24:
    ctx->pc = 0x800F4B24u;
    // 800F4B24: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4B28:
    ctx->pc = 0x800F4B28u;
    // 800F4B28: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F4B2C:
    ctx->pc = 0x800F4B2Cu;
    // 800F4B2C: stw     r29, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800F4B30:
    ctx->pc = 0x800F4B30u;
    // 800F4B30: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4B34:
    ctx->pc = 0x800F4B34u;
    // 800F4B34: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4B38:
    ctx->pc = 0x800F4B38u;
    // 800F4B38: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4B3C:
    ctx->pc = 0x800F4B3Cu;
    // 800F4B3C: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4B40:
    ctx->pc = 0x800F4B40u;
    // 800F4B40: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F4B44:
    ctx->pc = 0x800F4B44u;
    // 800F4B44: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4B48:
    ctx->pc = 0x800F4B48u;
    ctx->downcount -= 17;
    // 800F4B48: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4B4C:
    ctx->pc = 0x800F4B4Cu;
    // 800F4B4C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4B50:
    ctx->pc = 0x800F4B50u;
    // 800F4B50: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4B50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F4B54:
    ctx->pc = 0x800F4B54u;
    // 800F4B54: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4B58:
    ctx->pc = 0x800F4B58u;
    // 800F4B58: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4B5C:
    ctx->pc = 0x800F4B5Cu;
    // 800F4B5C: li      r3, 48
    ctx->gpr[3] = (u32)(s32)(48);

label_800F4B60:
    ctx->pc = 0x800F4B60u;
    // 800F4B60: bl      0x80281C60
    {
            ctx->lr = 0x800F4B64u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4B64:
    ctx->pc = 0x800F4B64u;
    ctx->downcount -= 7;
    // 800F4B64: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4B68:
    ctx->pc = 0x800F4B68u;
    // 800F4B68: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4B6C:
    ctx->pc = 0x800F4B6Cu;
    // 800F4B6C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4B70:
    ctx->pc = 0x800F4B70u;
    // 800F4B70: lfs     f31, -10272(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F4B70u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10272);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F4B74:
    ctx->pc = 0x800F4B74u;
    // 800F4B74: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4B78:
    ctx->pc = 0x800F4B78u;
    // 800F4B78: addi    r4, r4, -13432
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13432);

label_800F4B7C:
    ctx->pc = 0x800F4B7Cu;
    // 800F4B7C: bl      0x800EFF24
    {
            ctx->lr = 0x800F4B80u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4B80:
    ctx->pc = 0x800F4B80u;
    ctx->downcount -= 9;
    // 800F4B80: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4B84:
    ctx->pc = 0x800F4B84u;
    // 800F4B84: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_800F4B88:
    ctx->pc = 0x800F4B88u;
    // 800F4B88: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F4B8C:
    ctx->pc = 0x800F4B8Cu;
    // 800F4B8C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F4B90:
    ctx->pc = 0x800F4B90u;
    // 800F4B90: stw     r11, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F4B94:
    ctx->pc = 0x800F4B94u;
    // 800F4B94: stw     r0, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4B98:
    ctx->pc = 0x800F4B98u;
    // 800F4B98: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4B9C:
    ctx->pc = 0x800F4B9Cu;
    // 800F4B9C: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4B9Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F4BA0:
    ctx->pc = 0x800F4BA0u;
    // 800F4BA0: bl      0x80289138
    {
            ctx->lr = 0x800F4BA4u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F4BA4:
    ctx->pc = 0x800F4BA4u;
    ctx->downcount -= 33;
    // 800F4BA4: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4BA8:
    ctx->pc = 0x800F4BA8u;
    // 800F4BA8: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F4BAC:
    ctx->pc = 0x800F4BACu;
    // 800F4BAC: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F4BB0:
    ctx->pc = 0x800F4BB0u;
    // 800F4BB0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4BB4:
    ctx->pc = 0x800F4BB4u;
    // 800F4BB4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4BB8:
    ctx->pc = 0x800F4BB8u;
    // 800F4BB8: lfd     f13, -10264(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F4BB8u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10264);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4BBC:
    ctx->pc = 0x800F4BBCu;
    // 800F4BBC: addi    r9, r9, -8528
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8528);

label_800F4BC0:
    ctx->pc = 0x800F4BC0u;
    // 800F4BC0: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F4BC4:
    ctx->pc = 0x800F4BC4u;
    // 800F4BC4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4BC8:
    ctx->pc = 0x800F4BC8u;
    // 800F4BC8: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F4BC8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F4BCC:
    ctx->pc = 0x800F4BCCu;
    // 800F4BCC: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4BCCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4BD0:
    ctx->pc = 0x800F4BD0u;
    // 800F4BD0: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4BD4:
    ctx->pc = 0x800F4BD4u;
    // 800F4BD4: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F4BD4u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F4BD8:
    ctx->pc = 0x800F4BD8u;
    // 800F4BD8: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F4BD8u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F4BDC:
    ctx->pc = 0x800F4BDCu;
    // 800F4BDC: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F4BDCu)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F4BE0:
    ctx->pc = 0x800F4BE0u;
    // 800F4BE0: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4BE0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F4BE4:
    ctx->pc = 0x800F4BE4u;
    // 800F4BE4: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4BE8:
    ctx->pc = 0x800F4BE8u;
    // 800F4BE8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4BEC:
    ctx->pc = 0x800F4BECu;
    // 800F4BEC: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4BF0:
    ctx->pc = 0x800F4BF0u;
    // 800F4BF0: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4BF0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4BF4:
    ctx->pc = 0x800F4BF4u;
    // 800F4BF4: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F4BF8:
    ctx->pc = 0x800F4BF8u;
    // 800F4BF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4BFC:
    ctx->pc = 0x800F4BFCu;
    ctx->downcount -= 17;
    // 800F4BFC: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4C00:
    ctx->pc = 0x800F4C00u;
    // 800F4C00: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4C04:
    ctx->pc = 0x800F4C04u;
    // 800F4C04: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4C04u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F4C08:
    ctx->pc = 0x800F4C08u;
    // 800F4C08: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4C0C:
    ctx->pc = 0x800F4C0Cu;
    // 800F4C0C: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4C10:
    ctx->pc = 0x800F4C10u;
    // 800F4C10: li      r3, 48
    ctx->gpr[3] = (u32)(s32)(48);

label_800F4C14:
    ctx->pc = 0x800F4C14u;
    // 800F4C14: bl      0x80281C60
    {
            ctx->lr = 0x800F4C18u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4C18:
    ctx->pc = 0x800F4C18u;
    ctx->downcount -= 7;
    // 800F4C18: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4C1C:
    ctx->pc = 0x800F4C1Cu;
    // 800F4C1C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4C20:
    ctx->pc = 0x800F4C20u;
    // 800F4C20: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4C24:
    ctx->pc = 0x800F4C24u;
    // 800F4C24: lfs     f31, -10256(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F4C24u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10256);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F4C28:
    ctx->pc = 0x800F4C28u;
    // 800F4C28: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4C2C:
    ctx->pc = 0x800F4C2Cu;
    // 800F4C2C: addi    r4, r4, -13408
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13408);

label_800F4C30:
    ctx->pc = 0x800F4C30u;
    // 800F4C30: bl      0x800EFF24
    {
            ctx->lr = 0x800F4C34u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4C34:
    ctx->pc = 0x800F4C34u;
    ctx->downcount -= 9;
    // 800F4C34: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4C38:
    ctx->pc = 0x800F4C38u;
    // 800F4C38: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_800F4C3C:
    ctx->pc = 0x800F4C3Cu;
    // 800F4C3C: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F4C40:
    ctx->pc = 0x800F4C40u;
    // 800F4C40: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F4C44:
    ctx->pc = 0x800F4C44u;
    // 800F4C44: stw     r11, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F4C48:
    ctx->pc = 0x800F4C48u;
    // 800F4C48: stw     r0, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4C4C:
    ctx->pc = 0x800F4C4Cu;
    // 800F4C4C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4C50:
    ctx->pc = 0x800F4C50u;
    // 800F4C50: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4C50u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F4C54:
    ctx->pc = 0x800F4C54u;
    // 800F4C54: bl      0x80289138
    {
            ctx->lr = 0x800F4C58u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F4C58:
    ctx->pc = 0x800F4C58u;
    ctx->downcount -= 33;
    // 800F4C58: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4C5C:
    ctx->pc = 0x800F4C5Cu;
    // 800F4C5C: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F4C60:
    ctx->pc = 0x800F4C60u;
    // 800F4C60: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F4C64:
    ctx->pc = 0x800F4C64u;
    // 800F4C64: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4C68:
    ctx->pc = 0x800F4C68u;
    // 800F4C68: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4C6C:
    ctx->pc = 0x800F4C6Cu;
    // 800F4C6C: lfd     f13, -10248(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F4C6Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10248);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4C70:
    ctx->pc = 0x800F4C70u;
    // 800F4C70: addi    r9, r9, -8448
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8448);

label_800F4C74:
    ctx->pc = 0x800F4C74u;
    // 800F4C74: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F4C78:
    ctx->pc = 0x800F4C78u;
    // 800F4C78: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4C7C:
    ctx->pc = 0x800F4C7Cu;
    // 800F4C7C: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F4C7Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F4C80:
    ctx->pc = 0x800F4C80u;
    // 800F4C80: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4C80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4C84:
    ctx->pc = 0x800F4C84u;
    // 800F4C84: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4C88:
    ctx->pc = 0x800F4C88u;
    // 800F4C88: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F4C88u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F4C8C:
    ctx->pc = 0x800F4C8Cu;
    // 800F4C8C: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F4C8Cu)) return;
    ppc_frsp(ctx, 0, 0);

label_800F4C90:
    ctx->pc = 0x800F4C90u;
    // 800F4C90: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F4C90u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F4C94:
    ctx->pc = 0x800F4C94u;
    // 800F4C94: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4C94u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F4C98:
    ctx->pc = 0x800F4C98u;
    // 800F4C98: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4C9C:
    ctx->pc = 0x800F4C9Cu;
    // 800F4C9C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4CA0:
    ctx->pc = 0x800F4CA0u;
    // 800F4CA0: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4CA4:
    ctx->pc = 0x800F4CA4u;
    // 800F4CA4: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4CA4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4CA8:
    ctx->pc = 0x800F4CA8u;
    // 800F4CA8: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F4CAC:
    ctx->pc = 0x800F4CACu;
    // 800F4CAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4CB0:
    ctx->pc = 0x800F4CB0u;
    ctx->downcount -= 16;
    // 800F4CB0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4CB4:
    ctx->pc = 0x800F4CB4u;
    // 800F4CB4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4CB8:
    ctx->pc = 0x800F4CB8u;
    // 800F4CB8: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4CBC:
    ctx->pc = 0x800F4CBCu;
    // 800F4CBC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4CC0:
    ctx->pc = 0x800F4CC0u;
    // 800F4CC0: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F4CC4:
    ctx->pc = 0x800F4CC4u;
    // 800F4CC4: bl      0x80281C60
    {
            ctx->lr = 0x800F4CC8u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4CC8:
    ctx->pc = 0x800F4CC8u;
    ctx->downcount -= 4;
    // 800F4CC8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4CCC:
    ctx->pc = 0x800F4CCCu;
    // 800F4CCC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4CD0:
    ctx->pc = 0x800F4CD0u;
    // 800F4CD0: addi    r4, r4, -13676
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13676);

label_800F4CD4:
    ctx->pc = 0x800F4CD4u;
    // 800F4CD4: bl      0x800F0E48
    {
            ctx->lr = 0x800F4CD8u;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F4CD8:
    ctx->pc = 0x800F4CD8u;
    ctx->downcount -= 20;
    // 800F4CD8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4CDC:
    ctx->pc = 0x800F4CDCu;
    // 800F4CDC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4CE0:
    ctx->pc = 0x800F4CE0u;
    // 800F4CE0: addi    r9, r9, -8048
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8048);

label_800F4CE4:
    ctx->pc = 0x800F4CE4u;
    // 800F4CE4: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4CE8:
    ctx->pc = 0x800F4CE8u;
    // 800F4CE8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4CEC:
    ctx->pc = 0x800F4CECu;
    // 800F4CEC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4CF0:
    ctx->pc = 0x800F4CF0u;
    // 800F4CF0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4CF4:
    ctx->pc = 0x800F4CF4u;
    // 800F4CF4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4CF8:
    ctx->pc = 0x800F4CF8u;
    // 800F4CF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4CFC:
    ctx->pc = 0x800F4CFCu;
    ctx->downcount -= 5;
    // 800F4CFC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4D00:
    ctx->pc = 0x800F4D00u;
    // 800F4D00: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4D04:
    ctx->pc = 0x800F4D04u;
    // 800F4D04: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4D08:
    ctx->pc = 0x800F4D08u;
    // 800F4D08: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F4D0C:
    ctx->pc = 0x800F4D0Cu;
    // 800F4D0C: bl      0x80281C60
    {
            ctx->lr = 0x800F4D10u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4D10:
    ctx->pc = 0x800F4D10u;
    ctx->downcount -= 1;
    // 800F4D10: bl      0x800F184C
    {
            ctx->lr = 0x800F4D14u;
            ctx->pc = 0x800F184Cu;
            return;
    }

label_800F4D14:
    ctx->pc = 0x800F4D14u;
    ctx->downcount -= 5;
    // 800F4D14: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4D18:
    ctx->pc = 0x800F4D18u;
    // 800F4D18: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4D1C:
    ctx->pc = 0x800F4D1Cu;
    // 800F4D1C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F4D20:
    ctx->pc = 0x800F4D20u;
    // 800F4D20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4D24:
    ctx->pc = 0x800F4D24u;
    ctx->downcount -= 5;
    // 800F4D24: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4D28:
    ctx->pc = 0x800F4D28u;
    // 800F4D28: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4D2C:
    ctx->pc = 0x800F4D2Cu;
    // 800F4D2C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4D30:
    ctx->pc = 0x800F4D30u;
    // 800F4D30: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F4D34:
    ctx->pc = 0x800F4D34u;
    // 800F4D34: bl      0x80281C60
    {
            ctx->lr = 0x800F4D38u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4D38:
    ctx->pc = 0x800F4D38u;
    ctx->downcount -= 1;
    // 800F4D38: bl      0x800F1990
    {
            ctx->lr = 0x800F4D3Cu;
            ctx->pc = 0x800F1990u;
            return;
    }

label_800F4D3C:
    ctx->pc = 0x800F4D3Cu;
    ctx->downcount -= 5;
    // 800F4D3C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4D40:
    ctx->pc = 0x800F4D40u;
    // 800F4D40: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4D44:
    ctx->pc = 0x800F4D44u;
    // 800F4D44: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F4D48:
    ctx->pc = 0x800F4D48u;
    // 800F4D48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4D4C:
    ctx->pc = 0x800F4D4Cu;
    ctx->downcount -= 5;
    // 800F4D4C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4D50:
    ctx->pc = 0x800F4D50u;
    // 800F4D50: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4D54:
    ctx->pc = 0x800F4D54u;
    // 800F4D54: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4D58:
    ctx->pc = 0x800F4D58u;
    // 800F4D58: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F4D5C:
    ctx->pc = 0x800F4D5Cu;
    // 800F4D5C: bl      0x80281C60
    {
            ctx->lr = 0x800F4D60u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4D60:
    ctx->pc = 0x800F4D60u;
    ctx->downcount -= 1;
    // 800F4D60: bl      0x800F1990
    {
            ctx->lr = 0x800F4D64u;
            ctx->pc = 0x800F1990u;
            return;
    }

label_800F4D64:
    ctx->pc = 0x800F4D64u;
    ctx->downcount -= 5;
    // 800F4D64: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4D68:
    ctx->pc = 0x800F4D68u;
    // 800F4D68: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4D6C:
    ctx->pc = 0x800F4D6Cu;
    // 800F4D6C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F4D70:
    ctx->pc = 0x800F4D70u;
    // 800F4D70: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4D74:
    ctx->pc = 0x800F4D74u;
    ctx->downcount -= 17;
    // 800F4D74: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4D78:
    ctx->pc = 0x800F4D78u;
    // 800F4D78: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4D7C:
    ctx->pc = 0x800F4D7Cu;
    // 800F4D7C: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4D7Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F4D80:
    ctx->pc = 0x800F4D80u;
    // 800F4D80: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4D84:
    ctx->pc = 0x800F4D84u;
    // 800F4D84: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4D88:
    ctx->pc = 0x800F4D88u;
    // 800F4D88: li      r3, 48
    ctx->gpr[3] = (u32)(s32)(48);

label_800F4D8C:
    ctx->pc = 0x800F4D8Cu;
    // 800F4D8C: bl      0x80281C60
    {
            ctx->lr = 0x800F4D90u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4D90:
    ctx->pc = 0x800F4D90u;
    ctx->downcount -= 7;
    // 800F4D90: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4D94:
    ctx->pc = 0x800F4D94u;
    // 800F4D94: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4D98:
    ctx->pc = 0x800F4D98u;
    // 800F4D98: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4D9C:
    ctx->pc = 0x800F4D9Cu;
    // 800F4D9C: lfs     f31, -10240(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F4D9Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10240);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F4DA0:
    ctx->pc = 0x800F4DA0u;
    // 800F4DA0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4DA4:
    ctx->pc = 0x800F4DA4u;
    // 800F4DA4: addi    r4, r4, -13384
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13384);

label_800F4DA8:
    ctx->pc = 0x800F4DA8u;
    // 800F4DA8: bl      0x800EFF24
    {
            ctx->lr = 0x800F4DACu;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4DAC:
    ctx->pc = 0x800F4DACu;
    ctx->downcount -= 9;
    // 800F4DAC: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4DB0:
    ctx->pc = 0x800F4DB0u;
    // 800F4DB0: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_800F4DB4:
    ctx->pc = 0x800F4DB4u;
    // 800F4DB4: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F4DB8:
    ctx->pc = 0x800F4DB8u;
    // 800F4DB8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F4DBC:
    ctx->pc = 0x800F4DBCu;
    // 800F4DBC: stw     r11, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F4DC0:
    ctx->pc = 0x800F4DC0u;
    // 800F4DC0: stw     r0, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4DC4:
    ctx->pc = 0x800F4DC4u;
    // 800F4DC4: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4DC8:
    ctx->pc = 0x800F4DC8u;
    // 800F4DC8: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4DC8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F4DCC:
    ctx->pc = 0x800F4DCCu;
    // 800F4DCC: bl      0x80289138
    {
            ctx->lr = 0x800F4DD0u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F4DD0:
    ctx->pc = 0x800F4DD0u;
    ctx->downcount -= 33;
    // 800F4DD0: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4DD4:
    ctx->pc = 0x800F4DD4u;
    // 800F4DD4: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F4DD8:
    ctx->pc = 0x800F4DD8u;
    // 800F4DD8: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F4DDC:
    ctx->pc = 0x800F4DDCu;
    // 800F4DDC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4DE0:
    ctx->pc = 0x800F4DE0u;
    // 800F4DE0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4DE4:
    ctx->pc = 0x800F4DE4u;
    // 800F4DE4: lfd     f13, -10232(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F4DE4u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10232);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4DE8:
    ctx->pc = 0x800F4DE8u;
    // 800F4DE8: addi    r9, r9, -8608
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8608);

label_800F4DEC:
    ctx->pc = 0x800F4DECu;
    // 800F4DEC: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F4DF0:
    ctx->pc = 0x800F4DF0u;
    // 800F4DF0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4DF4:
    ctx->pc = 0x800F4DF4u;
    // 800F4DF4: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F4DF4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F4DF8:
    ctx->pc = 0x800F4DF8u;
    // 800F4DF8: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4DF8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4DFC:
    ctx->pc = 0x800F4DFCu;
    // 800F4DFC: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4E00:
    ctx->pc = 0x800F4E00u;
    // 800F4E00: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F4E00u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F4E04:
    ctx->pc = 0x800F4E04u;
    // 800F4E04: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F4E04u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F4E08:
    ctx->pc = 0x800F4E08u;
    // 800F4E08: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F4E08u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F4E0C:
    ctx->pc = 0x800F4E0Cu;
    // 800F4E0C: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4E0Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F4E10:
    ctx->pc = 0x800F4E10u;
    // 800F4E10: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4E14:
    ctx->pc = 0x800F4E14u;
    // 800F4E14: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4E18:
    ctx->pc = 0x800F4E18u;
    // 800F4E18: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4E1C:
    ctx->pc = 0x800F4E1Cu;
    // 800F4E1C: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4E1Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F4E20:
    ctx->pc = 0x800F4E20u;
    // 800F4E20: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F4E24:
    ctx->pc = 0x800F4E24u;
    // 800F4E24: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4E28:
    ctx->pc = 0x800F4E28u;
    ctx->downcount -= 16;
    // 800F4E28: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4E2C:
    ctx->pc = 0x800F4E2Cu;
    // 800F4E2C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4E30:
    ctx->pc = 0x800F4E30u;
    // 800F4E30: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4E34:
    ctx->pc = 0x800F4E34u;
    // 800F4E34: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4E38:
    ctx->pc = 0x800F4E38u;
    // 800F4E38: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F4E3C:
    ctx->pc = 0x800F4E3Cu;
    // 800F4E3C: bl      0x80281C60
    {
            ctx->lr = 0x800F4E40u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4E40:
    ctx->pc = 0x800F4E40u;
    ctx->downcount -= 4;
    // 800F4E40: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4E44:
    ctx->pc = 0x800F4E44u;
    // 800F4E44: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4E48:
    ctx->pc = 0x800F4E48u;
    // 800F4E48: addi    r4, r4, -13236
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13236);

label_800F4E4C:
    ctx->pc = 0x800F4E4Cu;
    // 800F4E4C: bl      0x800F0E48
    {
            ctx->lr = 0x800F4E50u;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F4E50:
    ctx->pc = 0x800F4E50u;
    ctx->downcount -= 20;
    // 800F4E50: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4E54:
    ctx->pc = 0x800F4E54u;
    // 800F4E54: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4E58:
    ctx->pc = 0x800F4E58u;
    // 800F4E58: addi    r9, r9, -8928
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8928);

label_800F4E5C:
    ctx->pc = 0x800F4E5Cu;
    // 800F4E5C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4E60:
    ctx->pc = 0x800F4E60u;
    // 800F4E60: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4E64:
    ctx->pc = 0x800F4E64u;
    // 800F4E64: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4E68:
    ctx->pc = 0x800F4E68u;
    // 800F4E68: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4E6C:
    ctx->pc = 0x800F4E6Cu;
    // 800F4E6C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F4E70:
    ctx->pc = 0x800F4E70u;
    // 800F4E70: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4E74:
    ctx->pc = 0x800F4E74u;
    ctx->downcount -= 17;
    // 800F4E74: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4E78:
    ctx->pc = 0x800F4E78u;
    // 800F4E78: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4E7C:
    ctx->pc = 0x800F4E7Cu;
    // 800F4E7C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4E80:
    ctx->pc = 0x800F4E80u;
    // 800F4E80: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4E84:
    ctx->pc = 0x800F4E84u;
    // 800F4E84: li      r3, 44
    ctx->gpr[3] = (u32)(s32)(44);

label_800F4E88:
    ctx->pc = 0x800F4E88u;
    // 800F4E88: li      r29, 4
    ctx->gpr[29] = (u32)(s32)(4);

label_800F4E8C:
    ctx->pc = 0x800F4E8Cu;
    // 800F4E8C: bl      0x80281C60
    {
            ctx->lr = 0x800F4E90u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4E90:
    ctx->pc = 0x800F4E90u;
    ctx->downcount -= 5;
    // 800F4E90: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4E94:
    ctx->pc = 0x800F4E94u;
    // 800F4E94: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4E98:
    ctx->pc = 0x800F4E98u;
    // 800F4E98: addi    r4, r4, -13496
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13496);

label_800F4E9C:
    ctx->pc = 0x800F4E9Cu;
    // 800F4E9C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4EA0:
    ctx->pc = 0x800F4EA0u;
    // 800F4EA0: bl      0x800EFF24
    {
            ctx->lr = 0x800F4EA4u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4EA4:
    ctx->pc = 0x800F4EA4u;
    ctx->downcount -= 25;
    // 800F4EA4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4EA8:
    ctx->pc = 0x800F4EA8u;
    // 800F4EA8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F4EAC:
    ctx->pc = 0x800F4EACu;
    // 800F4EAC: addi    r9, r9, -8288
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8288);

label_800F4EB0:
    ctx->pc = 0x800F4EB0u;
    // 800F4EB0: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F4EB4:
    ctx->pc = 0x800F4EB4u;
    // 800F4EB4: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4EB8:
    ctx->pc = 0x800F4EB8u;
    // 800F4EB8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4EBC:
    ctx->pc = 0x800F4EBCu;
    // 800F4EBC: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F4EC0:
    ctx->pc = 0x800F4EC0u;
    // 800F4EC0: stw     r29, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800F4EC4:
    ctx->pc = 0x800F4EC4u;
    // 800F4EC4: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4EC8:
    ctx->pc = 0x800F4EC8u;
    // 800F4EC8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4ECC:
    ctx->pc = 0x800F4ECCu;
    // 800F4ECC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4ED0:
    ctx->pc = 0x800F4ED0u;
    // 800F4ED0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4ED4:
    ctx->pc = 0x800F4ED4u;
    // 800F4ED4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F4ED8:
    ctx->pc = 0x800F4ED8u;
    // 800F4ED8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4EDC:
    ctx->pc = 0x800F4EDCu;
    ctx->downcount -= 17;
    // 800F4EDC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4EE0:
    ctx->pc = 0x800F4EE0u;
    // 800F4EE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4EE4:
    ctx->pc = 0x800F4EE4u;
    // 800F4EE4: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4EE8:
    ctx->pc = 0x800F4EE8u;
    // 800F4EE8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4EEC:
    ctx->pc = 0x800F4EECu;
    // 800F4EEC: li      r3, 44
    ctx->gpr[3] = (u32)(s32)(44);

label_800F4EF0:
    ctx->pc = 0x800F4EF0u;
    // 800F4EF0: li      r29, 4
    ctx->gpr[29] = (u32)(s32)(4);

label_800F4EF4:
    ctx->pc = 0x800F4EF4u;
    // 800F4EF4: bl      0x80281C60
    {
            ctx->lr = 0x800F4EF8u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4EF8:
    ctx->pc = 0x800F4EF8u;
    ctx->downcount -= 5;
    // 800F4EF8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4EFC:
    ctx->pc = 0x800F4EFCu;
    // 800F4EFC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4F00:
    ctx->pc = 0x800F4F00u;
    // 800F4F00: addi    r4, r4, -13496
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13496);

label_800F4F04:
    ctx->pc = 0x800F4F04u;
    // 800F4F04: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4F08:
    ctx->pc = 0x800F4F08u;
    // 800F4F08: bl      0x800EFF24
    {
            ctx->lr = 0x800F4F0Cu;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4F0C:
    ctx->pc = 0x800F4F0Cu;
    ctx->downcount -= 25;
    // 800F4F0C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4F10:
    ctx->pc = 0x800F4F10u;
    // 800F4F10: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F4F14:
    ctx->pc = 0x800F4F14u;
    // 800F4F14: addi    r9, r9, -8288
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8288);

label_800F4F18:
    ctx->pc = 0x800F4F18u;
    // 800F4F18: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F4F1C:
    ctx->pc = 0x800F4F1Cu;
    // 800F4F1C: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4F20:
    ctx->pc = 0x800F4F20u;
    // 800F4F20: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4F24:
    ctx->pc = 0x800F4F24u;
    // 800F4F24: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F4F28:
    ctx->pc = 0x800F4F28u;
    // 800F4F28: stw     r29, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800F4F2C:
    ctx->pc = 0x800F4F2Cu;
    // 800F4F2C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4F30:
    ctx->pc = 0x800F4F30u;
    // 800F4F30: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4F34:
    ctx->pc = 0x800F4F34u;
    // 800F4F34: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4F38:
    ctx->pc = 0x800F4F38u;
    // 800F4F38: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4F3C:
    ctx->pc = 0x800F4F3Cu;
    // 800F4F3C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F4F40:
    ctx->pc = 0x800F4F40u;
    // 800F4F40: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4F44:
    ctx->pc = 0x800F4F44u;
    ctx->downcount -= 17;
    // 800F4F44: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4F48:
    ctx->pc = 0x800F4F48u;
    // 800F4F48: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4F4C:
    ctx->pc = 0x800F4F4Cu;
    // 800F4F4C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4F50:
    ctx->pc = 0x800F4F50u;
    // 800F4F50: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4F54:
    ctx->pc = 0x800F4F54u;
    // 800F4F54: li      r3, 44
    ctx->gpr[3] = (u32)(s32)(44);

label_800F4F58:
    ctx->pc = 0x800F4F58u;
    // 800F4F58: li      r29, 4
    ctx->gpr[29] = (u32)(s32)(4);

label_800F4F5C:
    ctx->pc = 0x800F4F5Cu;
    // 800F4F5C: bl      0x80281C60
    {
            ctx->lr = 0x800F4F60u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4F60:
    ctx->pc = 0x800F4F60u;
    ctx->downcount -= 5;
    // 800F4F60: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4F64:
    ctx->pc = 0x800F4F64u;
    // 800F4F64: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4F68:
    ctx->pc = 0x800F4F68u;
    // 800F4F68: addi    r4, r4, -13496
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13496);

label_800F4F6C:
    ctx->pc = 0x800F4F6Cu;
    // 800F4F6C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4F70:
    ctx->pc = 0x800F4F70u;
    // 800F4F70: bl      0x800EFF24
    {
            ctx->lr = 0x800F4F74u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4F74:
    ctx->pc = 0x800F4F74u;
    ctx->downcount -= 25;
    // 800F4F74: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4F78:
    ctx->pc = 0x800F4F78u;
    // 800F4F78: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F4F7C:
    ctx->pc = 0x800F4F7Cu;
    // 800F4F7C: addi    r9, r9, -8288
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8288);

label_800F4F80:
    ctx->pc = 0x800F4F80u;
    // 800F4F80: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800F4F84:
    ctx->pc = 0x800F4F84u;
    // 800F4F84: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4F88:
    ctx->pc = 0x800F4F88u;
    // 800F4F88: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F4F8C:
    ctx->pc = 0x800F4F8Cu;
    // 800F4F8C: stw     r11, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F4F90:
    ctx->pc = 0x800F4F90u;
    // 800F4F90: stw     r29, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800F4F94:
    ctx->pc = 0x800F4F94u;
    // 800F4F94: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4F98:
    ctx->pc = 0x800F4F98u;
    // 800F4F98: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F4F9C:
    ctx->pc = 0x800F4F9Cu;
    // 800F4F9C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F4FA0:
    ctx->pc = 0x800F4FA0u;
    // 800F4FA0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F4FA4:
    ctx->pc = 0x800F4FA4u;
    // 800F4FA4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F4FA8:
    ctx->pc = 0x800F4FA8u;
    // 800F4FA8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F4FAC:
    ctx->pc = 0x800F4FACu;
    ctx->downcount -= 18;
    // 800F4FAC: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F4FB0:
    ctx->pc = 0x800F4FB0u;
    // 800F4FB0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F4FB4:
    ctx->pc = 0x800F4FB4u;
    // 800F4FB4: stfd     f31, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F4FB4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F4FB8:
    ctx->pc = 0x800F4FB8u;
    // 800F4FB8: stmw     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F4FBC:
    ctx->pc = 0x800F4FBCu;
    // 800F4FBC: stw     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4FC0:
    ctx->pc = 0x800F4FC0u;
    // 800F4FC0: li      r3, 48
    ctx->gpr[3] = (u32)(s32)(48);

label_800F4FC4:
    ctx->pc = 0x800F4FC4u;
    // 800F4FC4: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_800F4FC8:
    ctx->pc = 0x800F4FC8u;
    // 800F4FC8: bl      0x80281C60
    {
            ctx->lr = 0x800F4FCCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F4FCC:
    ctx->pc = 0x800F4FCCu;
    ctx->downcount -= 7;
    // 800F4FCC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F4FD0:
    ctx->pc = 0x800F4FD0u;
    // 800F4FD0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4FD4:
    ctx->pc = 0x800F4FD4u;
    // 800F4FD4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F4FD8:
    ctx->pc = 0x800F4FD8u;
    // 800F4FD8: lfs     f31, -10224(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F4FD8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-10224);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F4FDC:
    ctx->pc = 0x800F4FDCu;
    // 800F4FDC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F4FE0:
    ctx->pc = 0x800F4FE0u;
    // 800F4FE0: addi    r4, r4, -13288
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13288);

label_800F4FE4:
    ctx->pc = 0x800F4FE4u;
    // 800F4FE4: bl      0x800EFF24
    {
            ctx->lr = 0x800F4FE8u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F4FE8:
    ctx->pc = 0x800F4FE8u;
    ctx->downcount -= 8;
    // 800F4FE8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F4FEC:
    ctx->pc = 0x800F4FECu;
    // 800F4FEC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F4FF0:
    ctx->pc = 0x800F4FF0u;
    // 800F4FF0: addi    r9, r9, -10856
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10856);

label_800F4FF4:
    ctx->pc = 0x800F4FF4u;
    // 800F4FF4: stw     r0, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F4FF8:
    ctx->pc = 0x800F4FF8u;
    // 800F4FF8: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F4FFC:
    ctx->pc = 0x800F4FFCu;
    // 800F4FFC: stfs     f31, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F4FFCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F5000:
    ctx->pc = 0x800F5000u;
    // 800F5000: stw     r29, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800F5004:
    ctx->pc = 0x800F5004u;
    // 800F5004: bl      0x80289138
    {
            ctx->lr = 0x800F5008u;
            ctx->pc = 0x80289138u;
            return;
    }

label_800F5008:
    ctx->pc = 0x800F5008u;
    ctx->downcount -= 34;
    // 800F5008: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F500C:
    ctx->pc = 0x800F500Cu;
    // 800F500C: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_800F5010:
    ctx->pc = 0x800F5010u;
    // 800F5010: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F5014:
    ctx->pc = 0x800F5014u;
    // 800F5014: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5018:
    ctx->pc = 0x800F5018u;
    // 800F5018: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F501C:
    ctx->pc = 0x800F501Cu;
    // 800F501C: lfd     f13, -10216(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F501Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-10216);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F5020:
    ctx->pc = 0x800F5020u;
    // 800F5020: addi    r9, r9, -12056
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-12056);

label_800F5024:
    ctx->pc = 0x800F5024u;
    // 800F5024: stw     r8, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F5028:
    ctx->pc = 0x800F5028u;
    // 800F5028: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F502C:
    ctx->pc = 0x800F502Cu;
    // 800F502C: lfs     f12, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F502Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F5030:
    ctx->pc = 0x800F5030u;
    // 800F5030: lfd     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F5030u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F5034:
    ctx->pc = 0x800F5034u;
    // 800F5034: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5038:
    ctx->pc = 0x800F5038u;
    // 800F5038: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F5038u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800F503C:
    ctx->pc = 0x800F503Cu;
    // 800F503C: stw     r29, -32168(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32168);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800F5040:
    ctx->pc = 0x800F5040u;
    // 800F5040: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F5040u)) return;
    ppc_frsp(ctx, 0, 0);

label_800F5044:
    ctx->pc = 0x800F5044u;
    // 800F5044: fmuls   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F5044u)) return;
    ppc_fmuls(ctx, 0, 0, 12);

label_800F5048:
    ctx->pc = 0x800F5048u;
    // 800F5048: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F5048u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F504C:
    ctx->pc = 0x800F504Cu;
    // 800F504C: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5050:
    ctx->pc = 0x800F5050u;
    // 800F5050: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5054:
    ctx->pc = 0x800F5054u;
    // 800F5054: lmw     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F5058:
    ctx->pc = 0x800F5058u;
    // 800F5058: lfd     f31, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F5058u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F505C:
    ctx->pc = 0x800F505Cu;
    // 800F505C: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_800F5060:
    ctx->pc = 0x800F5060u;
    // 800F5060: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5064:
    ctx->pc = 0x800F5064u;
    ctx->downcount -= 16;
    // 800F5064: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5068:
    ctx->pc = 0x800F5068u;
    // 800F5068: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F506C:
    ctx->pc = 0x800F506Cu;
    // 800F506C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5070:
    ctx->pc = 0x800F5070u;
    // 800F5070: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5074:
    ctx->pc = 0x800F5074u;
    // 800F5074: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F5078:
    ctx->pc = 0x800F5078u;
    // 800F5078: bl      0x80281C60
    {
            ctx->lr = 0x800F507Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F507C:
    ctx->pc = 0x800F507Cu;
    ctx->downcount -= 4;
    // 800F507C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5080:
    ctx->pc = 0x800F5080u;
    // 800F5080: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5084:
    ctx->pc = 0x800F5084u;
    // 800F5084: addi    r4, r4, -13236
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13236);

label_800F5088:
    ctx->pc = 0x800F5088u;
    // 800F5088: bl      0x800F0E48
    {
            ctx->lr = 0x800F508Cu;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F508C:
    ctx->pc = 0x800F508Cu;
    ctx->downcount -= 20;
    // 800F508C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F5090:
    ctx->pc = 0x800F5090u;
    // 800F5090: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F5094:
    ctx->pc = 0x800F5094u;
    // 800F5094: addi    r9, r9, -8928
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8928);

label_800F5098:
    ctx->pc = 0x800F5098u;
    // 800F5098: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F509C:
    ctx->pc = 0x800F509Cu;
    // 800F509C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F50A0:
    ctx->pc = 0x800F50A0u;
    // 800F50A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F50A4:
    ctx->pc = 0x800F50A4u;
    // 800F50A4: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F50A8:
    ctx->pc = 0x800F50A8u;
    // 800F50A8: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F50AC:
    ctx->pc = 0x800F50ACu;
    // 800F50AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F50B0:
    ctx->pc = 0x800F50B0u;
    ctx->downcount -= 5;
    // 800F50B0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F50B4:
    ctx->pc = 0x800F50B4u;
    // 800F50B4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F50B8:
    ctx->pc = 0x800F50B8u;
    // 800F50B8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F50BC:
    ctx->pc = 0x800F50BCu;
    // 800F50BC: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F50C0:
    ctx->pc = 0x800F50C0u;
    // 800F50C0: bl      0x80281C60
    {
            ctx->lr = 0x800F50C4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F50C4:
    ctx->pc = 0x800F50C4u;
    ctx->downcount -= 1;
    // 800F50C4: bl      0x800F1708
    {
            ctx->lr = 0x800F50C8u;
            ctx->pc = 0x800F1708u;
            return;
    }

label_800F50C8:
    ctx->pc = 0x800F50C8u;
    ctx->downcount -= 5;
    // 800F50C8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F50CC:
    ctx->pc = 0x800F50CCu;
    // 800F50CC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F50D0:
    ctx->pc = 0x800F50D0u;
    // 800F50D0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F50D4:
    ctx->pc = 0x800F50D4u;
    // 800F50D4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F50D8:
    ctx->pc = 0x800F50D8u;
    ctx->downcount -= 16;
    // 800F50D8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F50DC:
    ctx->pc = 0x800F50DCu;
    // 800F50DC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F50E0:
    ctx->pc = 0x800F50E0u;
    // 800F50E0: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F50E4:
    ctx->pc = 0x800F50E4u;
    // 800F50E4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F50E8:
    ctx->pc = 0x800F50E8u;
    // 800F50E8: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F50EC:
    ctx->pc = 0x800F50ECu;
    // 800F50EC: bl      0x80281C60
    {
            ctx->lr = 0x800F50F0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F50F0:
    ctx->pc = 0x800F50F0u;
    ctx->downcount -= 4;
    // 800F50F0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F50F4:
    ctx->pc = 0x800F50F4u;
    // 800F50F4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F50F8:
    ctx->pc = 0x800F50F8u;
    // 800F50F8: addi    r4, r4, -13676
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13676);

label_800F50FC:
    ctx->pc = 0x800F50FCu;
    // 800F50FC: bl      0x800F0E48
    {
            ctx->lr = 0x800F5100u;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F5100:
    ctx->pc = 0x800F5100u;
    ctx->downcount -= 20;
    // 800F5100: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F5104:
    ctx->pc = 0x800F5104u;
    // 800F5104: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F5108:
    ctx->pc = 0x800F5108u;
    // 800F5108: addi    r9, r9, -8048
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8048);

label_800F510C:
    ctx->pc = 0x800F510Cu;
    // 800F510C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5110:
    ctx->pc = 0x800F5110u;
    // 800F5110: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5114:
    ctx->pc = 0x800F5114u;
    // 800F5114: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5118:
    ctx->pc = 0x800F5118u;
    // 800F5118: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F511C:
    ctx->pc = 0x800F511Cu;
    // 800F511C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F5120:
    ctx->pc = 0x800F5120u;
    // 800F5120: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5124:
    ctx->pc = 0x800F5124u;
    ctx->downcount -= 5;
    // 800F5124: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5128:
    ctx->pc = 0x800F5128u;
    // 800F5128: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F512C:
    ctx->pc = 0x800F512Cu;
    // 800F512C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5130:
    ctx->pc = 0x800F5130u;
    // 800F5130: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F5134:
    ctx->pc = 0x800F5134u;
    // 800F5134: bl      0x80281C60
    {
            ctx->lr = 0x800F5138u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F5138:
    ctx->pc = 0x800F5138u;
    ctx->downcount -= 1;
    // 800F5138: bl      0x800F184C
    {
            ctx->lr = 0x800F513Cu;
            ctx->pc = 0x800F184Cu;
            return;
    }

label_800F513C:
    ctx->pc = 0x800F513Cu;
    ctx->downcount -= 5;
    // 800F513C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5140:
    ctx->pc = 0x800F5140u;
    // 800F5140: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5144:
    ctx->pc = 0x800F5144u;
    // 800F5144: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5148:
    ctx->pc = 0x800F5148u;
    // 800F5148: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F514C:
    ctx->pc = 0x800F514Cu;
    ctx->downcount -= 16;
    // 800F514C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5150:
    ctx->pc = 0x800F5150u;
    // 800F5150: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5154:
    ctx->pc = 0x800F5154u;
    // 800F5154: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5158:
    ctx->pc = 0x800F5158u;
    // 800F5158: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F515C:
    ctx->pc = 0x800F515Cu;
    // 800F515C: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F5160:
    ctx->pc = 0x800F5160u;
    // 800F5160: bl      0x80281C60
    {
            ctx->lr = 0x800F5164u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F5164:
    ctx->pc = 0x800F5164u;
    ctx->downcount -= 4;
    // 800F5164: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5168:
    ctx->pc = 0x800F5168u;
    // 800F5168: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F516C:
    ctx->pc = 0x800F516Cu;
    // 800F516C: addi    r4, r4, -13264
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13264);

label_800F5170:
    ctx->pc = 0x800F5170u;
    // 800F5170: bl      0x800F0E48
    {
            ctx->lr = 0x800F5174u;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F5174:
    ctx->pc = 0x800F5174u;
    ctx->downcount -= 20;
    // 800F5174: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F5178:
    ctx->pc = 0x800F5178u;
    // 800F5178: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F517C:
    ctx->pc = 0x800F517Cu;
    // 800F517C: addi    r9, r9, -8768
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8768);

label_800F5180:
    ctx->pc = 0x800F5180u;
    // 800F5180: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5184:
    ctx->pc = 0x800F5184u;
    // 800F5184: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5188:
    ctx->pc = 0x800F5188u;
    // 800F5188: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F518C:
    ctx->pc = 0x800F518Cu;
    // 800F518C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F5190:
    ctx->pc = 0x800F5190u;
    // 800F5190: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F5194:
    ctx->pc = 0x800F5194u;
    // 800F5194: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5198:
    ctx->pc = 0x800F5198u;
    ctx->downcount -= 16;
    // 800F5198: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F519C:
    ctx->pc = 0x800F519Cu;
    // 800F519C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F51A0:
    ctx->pc = 0x800F51A0u;
    // 800F51A0: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F51A4:
    ctx->pc = 0x800F51A4u;
    // 800F51A4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F51A8:
    ctx->pc = 0x800F51A8u;
    // 800F51A8: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F51AC:
    ctx->pc = 0x800F51ACu;
    // 800F51AC: bl      0x80281C60
    {
            ctx->lr = 0x800F51B0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F51B0:
    ctx->pc = 0x800F51B0u;
    ctx->downcount -= 4;
    // 800F51B0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F51B4:
    ctx->pc = 0x800F51B4u;
    // 800F51B4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F51B8:
    ctx->pc = 0x800F51B8u;
    // 800F51B8: addi    r4, r4, -13736
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13736);

label_800F51BC:
    ctx->pc = 0x800F51BCu;
    // 800F51BC: bl      0x800F0E48
    {
            ctx->lr = 0x800F51C0u;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F51C0:
    ctx->pc = 0x800F51C0u;
    ctx->downcount -= 20;
    // 800F51C0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F51C4:
    ctx->pc = 0x800F51C4u;
    // 800F51C4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F51C8:
    ctx->pc = 0x800F51C8u;
    // 800F51C8: addi    r9, r9, -7888
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-7888);

label_800F51CC:
    ctx->pc = 0x800F51CCu;
    // 800F51CC: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F51D0:
    ctx->pc = 0x800F51D0u;
    // 800F51D0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F51D4:
    ctx->pc = 0x800F51D4u;
    // 800F51D4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F51D8:
    ctx->pc = 0x800F51D8u;
    // 800F51D8: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F51DC:
    ctx->pc = 0x800F51DCu;
    // 800F51DC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F51E0:
    ctx->pc = 0x800F51E0u;
    // 800F51E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F51E4:
    ctx->pc = 0x800F51E4u;
    ctx->downcount -= 16;
    // 800F51E4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F51E8:
    ctx->pc = 0x800F51E8u;
    // 800F51E8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F51EC:
    ctx->pc = 0x800F51ECu;
    // 800F51EC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F51F0:
    ctx->pc = 0x800F51F0u;
    // 800F51F0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F51F4:
    ctx->pc = 0x800F51F4u;
    // 800F51F4: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F51F8:
    ctx->pc = 0x800F51F8u;
    // 800F51F8: bl      0x80281C60
    {
            ctx->lr = 0x800F51FCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F51FC:
    ctx->pc = 0x800F51FCu;
    ctx->downcount -= 4;
    // 800F51FC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5200:
    ctx->pc = 0x800F5200u;
    // 800F5200: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5204:
    ctx->pc = 0x800F5204u;
    // 800F5204: addi    r4, r4, -13264
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13264);

label_800F5208:
    ctx->pc = 0x800F5208u;
    // 800F5208: bl      0x800F0E48
    {
            ctx->lr = 0x800F520Cu;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F520C:
    ctx->pc = 0x800F520Cu;
    ctx->downcount -= 20;
    // 800F520C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F5210:
    ctx->pc = 0x800F5210u;
    // 800F5210: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F5214:
    ctx->pc = 0x800F5214u;
    // 800F5214: addi    r9, r9, -8768
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8768);

label_800F5218:
    ctx->pc = 0x800F5218u;
    // 800F5218: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F521C:
    ctx->pc = 0x800F521Cu;
    // 800F521C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5220:
    ctx->pc = 0x800F5220u;
    // 800F5220: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5224:
    ctx->pc = 0x800F5224u;
    // 800F5224: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F5228:
    ctx->pc = 0x800F5228u;
    // 800F5228: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F522C:
    ctx->pc = 0x800F522Cu;
    // 800F522C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5230:
    ctx->pc = 0x800F5230u;
    ctx->downcount -= 2;
    // 800F5230: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F5234:
    ctx->pc = 0x800F5234u;
    // 800F5234: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5238:
    ctx->pc = 0x800F5238u;
    ctx->downcount -= 16;
    // 800F5238: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F523C:
    ctx->pc = 0x800F523Cu;
    // 800F523C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5240:
    ctx->pc = 0x800F5240u;
    // 800F5240: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5244:
    ctx->pc = 0x800F5244u;
    // 800F5244: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5248:
    ctx->pc = 0x800F5248u;
    // 800F5248: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F524C:
    ctx->pc = 0x800F524Cu;
    // 800F524C: bl      0x80281C60
    {
            ctx->lr = 0x800F5250u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F5250:
    ctx->pc = 0x800F5250u;
    ctx->downcount -= 4;
    // 800F5250: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5254:
    ctx->pc = 0x800F5254u;
    // 800F5254: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5258:
    ctx->pc = 0x800F5258u;
    // 800F5258: addi    r4, r4, -13704
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13704);

label_800F525C:
    ctx->pc = 0x800F525Cu;
    // 800F525C: bl      0x800F0E48
    {
            ctx->lr = 0x800F5260u;
            ctx->pc = 0x800F0E48u;
            return;
    }

label_800F5260:
    ctx->pc = 0x800F5260u;
    ctx->downcount -= 20;
    // 800F5260: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F5264:
    ctx->pc = 0x800F5264u;
    // 800F5264: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F5268:
    ctx->pc = 0x800F5268u;
    // 800F5268: addi    r9, r9, -7968
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-7968);

label_800F526C:
    ctx->pc = 0x800F526Cu;
    // 800F526C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5270:
    ctx->pc = 0x800F5270u;
    // 800F5270: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5274:
    ctx->pc = 0x800F5274u;
    // 800F5274: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5278:
    ctx->pc = 0x800F5278u;
    // 800F5278: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F527C:
    ctx->pc = 0x800F527Cu;
    // 800F527C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F5280:
    ctx->pc = 0x800F5280u;
    // 800F5280: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5284:
    ctx->pc = 0x800F5284u;
    ctx->downcount -= 16;
    // 800F5284: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5288:
    ctx->pc = 0x800F5288u;
    // 800F5288: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F528C:
    ctx->pc = 0x800F528Cu;
    // 800F528C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5290:
    ctx->pc = 0x800F5290u;
    // 800F5290: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5294:
    ctx->pc = 0x800F5294u;
    // 800F5294: li      r3, 32
    ctx->gpr[3] = (u32)(s32)(32);

label_800F5298:
    ctx->pc = 0x800F5298u;
    // 800F5298: bl      0x80281C60
    {
            ctx->lr = 0x800F529Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F529C:
    ctx->pc = 0x800F529Cu;
    ctx->downcount -= 5;
    // 800F529C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F52A0:
    ctx->pc = 0x800F52A0u;
    // 800F52A0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F52A4:
    ctx->pc = 0x800F52A4u;
    // 800F52A4: addi    r4, r4, -13064
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13064);

label_800F52A8:
    ctx->pc = 0x800F52A8u;
    // 800F52A8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F52AC:
    ctx->pc = 0x800F52ACu;
    // 800F52AC: bl      0x800EFF24
    {
            ctx->lr = 0x800F52B0u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F52B0:
    ctx->pc = 0x800F52B0u;
    ctx->downcount -= 20;
    // 800F52B0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F52B4:
    ctx->pc = 0x800F52B4u;
    // 800F52B4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F52B8:
    ctx->pc = 0x800F52B8u;
    // 800F52B8: addi    r9, r9, -12216
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-12216);

label_800F52BC:
    ctx->pc = 0x800F52BCu;
    // 800F52BC: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F52C0:
    ctx->pc = 0x800F52C0u;
    // 800F52C0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F52C4:
    ctx->pc = 0x800F52C4u;
    // 800F52C4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F52C8:
    ctx->pc = 0x800F52C8u;
    // 800F52C8: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F52CC:
    ctx->pc = 0x800F52CCu;
    // 800F52CC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F52D0:
    ctx->pc = 0x800F52D0u;
    // 800F52D0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F52D4:
    ctx->pc = 0x800F52D4u;
    ctx->downcount -= 16;
    // 800F52D4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F52D8:
    ctx->pc = 0x800F52D8u;
    // 800F52D8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F52DC:
    ctx->pc = 0x800F52DCu;
    // 800F52DC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F52E0:
    ctx->pc = 0x800F52E0u;
    // 800F52E0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F52E4:
    ctx->pc = 0x800F52E4u;
    // 800F52E4: li      r3, 32
    ctx->gpr[3] = (u32)(s32)(32);

label_800F52E8:
    ctx->pc = 0x800F52E8u;
    // 800F52E8: bl      0x80281C60
    {
            ctx->lr = 0x800F52ECu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F52EC:
    ctx->pc = 0x800F52ECu;
    ctx->downcount -= 5;
    // 800F52EC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F52F0:
    ctx->pc = 0x800F52F0u;
    // 800F52F0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F52F4:
    ctx->pc = 0x800F52F4u;
    // 800F52F4: addi    r4, r4, -13036
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13036);

label_800F52F8:
    ctx->pc = 0x800F52F8u;
    // 800F52F8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F52FC:
    ctx->pc = 0x800F52FCu;
    // 800F52FC: bl      0x800EFF24
    {
            ctx->lr = 0x800F5300u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F5300:
    ctx->pc = 0x800F5300u;
    ctx->downcount -= 20;
    // 800F5300: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F5304:
    ctx->pc = 0x800F5304u;
    // 800F5304: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F5308:
    ctx->pc = 0x800F5308u;
    // 800F5308: addi    r9, r9, -12296
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-12296);

label_800F530C:
    ctx->pc = 0x800F530Cu;
    // 800F530C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5310:
    ctx->pc = 0x800F5310u;
    // 800F5310: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5314:
    ctx->pc = 0x800F5314u;
    // 800F5314: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5318:
    ctx->pc = 0x800F5318u;
    // 800F5318: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F531C:
    ctx->pc = 0x800F531Cu;
    // 800F531C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F5320:
    ctx->pc = 0x800F5320u;
    // 800F5320: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5324:
    ctx->pc = 0x800F5324u;
    ctx->downcount -= 16;
    // 800F5324: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5328:
    ctx->pc = 0x800F5328u;
    // 800F5328: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F532C:
    ctx->pc = 0x800F532Cu;
    // 800F532C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5330:
    ctx->pc = 0x800F5330u;
    // 800F5330: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5334:
    ctx->pc = 0x800F5334u;
    // 800F5334: li      r3, 32
    ctx->gpr[3] = (u32)(s32)(32);

label_800F5338:
    ctx->pc = 0x800F5338u;
    // 800F5338: bl      0x80281C60
    {
            ctx->lr = 0x800F533Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F533C:
    ctx->pc = 0x800F533Cu;
    ctx->downcount -= 5;
    // 800F533C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5340:
    ctx->pc = 0x800F5340u;
    // 800F5340: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5344:
    ctx->pc = 0x800F5344u;
    // 800F5344: addi    r4, r4, -13008
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13008);

label_800F5348:
    ctx->pc = 0x800F5348u;
    // 800F5348: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F534C:
    ctx->pc = 0x800F534Cu;
    // 800F534C: bl      0x800EFF24
    {
            ctx->lr = 0x800F5350u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F5350:
    ctx->pc = 0x800F5350u;
    ctx->downcount -= 20;
    // 800F5350: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F5354:
    ctx->pc = 0x800F5354u;
    // 800F5354: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F5358:
    ctx->pc = 0x800F5358u;
    // 800F5358: addi    r9, r9, -12376
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-12376);

label_800F535C:
    ctx->pc = 0x800F535Cu;
    // 800F535C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5360:
    ctx->pc = 0x800F5360u;
    // 800F5360: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5364:
    ctx->pc = 0x800F5364u;
    // 800F5364: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5368:
    ctx->pc = 0x800F5368u;
    // 800F5368: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F536C:
    ctx->pc = 0x800F536Cu;
    // 800F536C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F5370:
    ctx->pc = 0x800F5370u;
    // 800F5370: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5374:
    ctx->pc = 0x800F5374u;
    ctx->downcount -= 16;
    // 800F5374: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5378:
    ctx->pc = 0x800F5378u;
    // 800F5378: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F537C:
    ctx->pc = 0x800F537Cu;
    // 800F537C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5380:
    ctx->pc = 0x800F5380u;
    // 800F5380: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5384:
    ctx->pc = 0x800F5384u;
    // 800F5384: li      r3, 32
    ctx->gpr[3] = (u32)(s32)(32);

label_800F5388:
    ctx->pc = 0x800F5388u;
    // 800F5388: bl      0x80281C60
    {
            ctx->lr = 0x800F538Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F538C:
    ctx->pc = 0x800F538Cu;
    ctx->downcount -= 5;
    // 800F538C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5390:
    ctx->pc = 0x800F5390u;
    // 800F5390: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5394:
    ctx->pc = 0x800F5394u;
    // 800F5394: addi    r4, r4, -12980
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12980);

label_800F5398:
    ctx->pc = 0x800F5398u;
    // 800F5398: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F539C:
    ctx->pc = 0x800F539Cu;
    // 800F539C: bl      0x800EFF24
    {
            ctx->lr = 0x800F53A0u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F53A0:
    ctx->pc = 0x800F53A0u;
    ctx->downcount -= 20;
    // 800F53A0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F53A4:
    ctx->pc = 0x800F53A4u;
    // 800F53A4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F53A8:
    ctx->pc = 0x800F53A8u;
    // 800F53A8: addi    r9, r9, -9008
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9008);

label_800F53AC:
    ctx->pc = 0x800F53ACu;
    // 800F53AC: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F53B0:
    ctx->pc = 0x800F53B0u;
    // 800F53B0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F53B4:
    ctx->pc = 0x800F53B4u;
    // 800F53B4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F53B8:
    ctx->pc = 0x800F53B8u;
    // 800F53B8: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F53BC:
    ctx->pc = 0x800F53BCu;
    // 800F53BC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F53C0:
    ctx->pc = 0x800F53C0u;
    // 800F53C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F53C4:
    ctx->pc = 0x800F53C4u;
    ctx->downcount -= 18;
    // 800F53C4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F53C8:
    ctx->pc = 0x800F53C8u;
    // 800F53C8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F53CC:
    ctx->pc = 0x800F53CCu;
    // 800F53CC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F53D0:
    ctx->pc = 0x800F53D0u;
    // 800F53D0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F53D4:
    ctx->pc = 0x800F53D4u;
    // 800F53D4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F53D8:
    ctx->pc = 0x800F53D8u;
    // 800F53D8: li      r3, 32
    ctx->gpr[3] = (u32)(s32)(32);

label_800F53DC:
    ctx->pc = 0x800F53DCu;
    // 800F53DC: stw     r0, -32164(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32164);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F53E0:
    ctx->pc = 0x800F53E0u;
    // 800F53E0: bl      0x80281C60
    {
            ctx->lr = 0x800F53E4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F53E4:
    ctx->pc = 0x800F53E4u;
    ctx->downcount -= 5;
    // 800F53E4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F53E8:
    ctx->pc = 0x800F53E8u;
    // 800F53E8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F53EC:
    ctx->pc = 0x800F53ECu;
    // 800F53EC: addi    r4, r4, -12956
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12956);

label_800F53F0:
    ctx->pc = 0x800F53F0u;
    // 800F53F0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F53F4:
    ctx->pc = 0x800F53F4u;
    // 800F53F4: bl      0x800EFF24
    {
            ctx->lr = 0x800F53F8u;
            ctx->pc = 0x800EFF24u;
            return;
    }

label_800F53F8:
    ctx->pc = 0x800F53F8u;
    ctx->downcount -= 20;
    // 800F53F8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F53FC:
    ctx->pc = 0x800F53FCu;
    // 800F53FC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F5400:
    ctx->pc = 0x800F5400u;
    // 800F5400: addi    r9, r9, -9088
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9088);

label_800F5404:
    ctx->pc = 0x800F5404u;
    // 800F5404: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5408:
    ctx->pc = 0x800F5408u;
    // 800F5408: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F540C:
    ctx->pc = 0x800F540Cu;
    // 800F540C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5410:
    ctx->pc = 0x800F5410u;
    // 800F5410: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F5414:
    ctx->pc = 0x800F5414u;
    // 800F5414: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F5418:
    ctx->pc = 0x800F5418u;
    // 800F5418: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F541C:
    ctx->pc = 0x800F541Cu;
    ctx->downcount -= 16;
    // 800F541C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5420:
    ctx->pc = 0x800F5420u;
    // 800F5420: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5424:
    ctx->pc = 0x800F5424u;
    // 800F5424: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5428:
    ctx->pc = 0x800F5428u;
    // 800F5428: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F542C:
    ctx->pc = 0x800F542Cu;
    // 800F542C: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F5430:
    ctx->pc = 0x800F5430u;
    // 800F5430: bl      0x80281C60
    {
            ctx->lr = 0x800F5434u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F5434:
    ctx->pc = 0x800F5434u;
    ctx->downcount -= 5;
    // 800F5434: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5438:
    ctx->pc = 0x800F5438u;
    // 800F5438: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F543C:
    ctx->pc = 0x800F543Cu;
    // 800F543C: addi    r4, r4, -13208
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13208);

label_800F5440:
    ctx->pc = 0x800F5440u;
    // 800F5440: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5444:
    ctx->pc = 0x800F5444u;
    // 800F5444: bl      0x800F0C70
    {
            ctx->lr = 0x800F5448u;
            ctx->pc = 0x800F0C70u;
            return;
    }

label_800F5448:
    ctx->pc = 0x800F5448u;
    ctx->downcount -= 20;
    // 800F5448: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F544C:
    ctx->pc = 0x800F544Cu;
    // 800F544C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F5450:
    ctx->pc = 0x800F5450u;
    // 800F5450: addi    r9, r9, -8848
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8848);

label_800F5454:
    ctx->pc = 0x800F5454u;
    // 800F5454: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5458:
    ctx->pc = 0x800F5458u;
    // 800F5458: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F545C:
    ctx->pc = 0x800F545Cu;
    // 800F545C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5460:
    ctx->pc = 0x800F5460u;
    // 800F5460: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F5464:
    ctx->pc = 0x800F5464u;
    // 800F5464: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F5468:
    ctx->pc = 0x800F5468u;
    // 800F5468: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F546C:
    ctx->pc = 0x800F546Cu;
    ctx->downcount -= 16;
    // 800F546C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5470:
    ctx->pc = 0x800F5470u;
    // 800F5470: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5474:
    ctx->pc = 0x800F5474u;
    // 800F5474: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5478:
    ctx->pc = 0x800F5478u;
    // 800F5478: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F547C:
    ctx->pc = 0x800F547Cu;
    // 800F547C: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F5480:
    ctx->pc = 0x800F5480u;
    // 800F5480: bl      0x80281C60
    {
            ctx->lr = 0x800F5484u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F5484:
    ctx->pc = 0x800F5484u;
    ctx->downcount -= 5;
    // 800F5484: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5488:
    ctx->pc = 0x800F5488u;
    // 800F5488: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F548C:
    ctx->pc = 0x800F548Cu;
    // 800F548C: addi    r4, r4, -12864
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-12864);

label_800F5490:
    ctx->pc = 0x800F5490u;
    // 800F5490: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5494:
    ctx->pc = 0x800F5494u;
    // 800F5494: bl      0x800F0C70
    {
            ctx->lr = 0x800F5498u;
            ctx->pc = 0x800F0C70u;
            return;
    }

label_800F5498:
    ctx->pc = 0x800F5498u;
    ctx->downcount -= 20;
    // 800F5498: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F549C:
    ctx->pc = 0x800F549Cu;
    // 800F549C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F54A0:
    ctx->pc = 0x800F54A0u;
    // 800F54A0: addi    r9, r9, -9408
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-9408);

label_800F54A4:
    ctx->pc = 0x800F54A4u;
    // 800F54A4: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F54A8:
    ctx->pc = 0x800F54A8u;
    // 800F54A8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F54AC:
    ctx->pc = 0x800F54ACu;
    // 800F54AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F54B0:
    ctx->pc = 0x800F54B0u;
    // 800F54B0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F54B4:
    ctx->pc = 0x800F54B4u;
    // 800F54B4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F54B8:
    ctx->pc = 0x800F54B8u;
    // 800F54B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F54BC:
    ctx->pc = 0x800F54BCu;
    ctx->downcount -= 2;
    // 800F54BC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F54C0:
    ctx->pc = 0x800F54C0u;
    // 800F54C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F54C4:
    ctx->pc = 0x800F54C4u;
    ctx->downcount -= 2;
    // 800F54C4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F54C8:
    ctx->pc = 0x800F54C8u;
    // 800F54C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F54CC:
    ctx->pc = 0x800F54CCu;
    ctx->downcount -= 2;
    // 800F54CC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F54D0:
    ctx->pc = 0x800F54D0u;
    // 800F54D0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F54D4:
    ctx->pc = 0x800F54D4u;
    ctx->downcount -= 2;
    // 800F54D4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F54D8:
    ctx->pc = 0x800F54D8u;
    // 800F54D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F54DC:
    ctx->pc = 0x800F54DCu;
    ctx->downcount -= 2;
    // 800F54DC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F54E0:
    ctx->pc = 0x800F54E0u;
    // 800F54E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F54E4:
    ctx->pc = 0x800F54E4u;
    ctx->downcount -= 5;
    // 800F54E4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F54E8:
    ctx->pc = 0x800F54E8u;
    // 800F54E8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F54EC:
    ctx->pc = 0x800F54ECu;
    // 800F54EC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F54F0:
    ctx->pc = 0x800F54F0u;
    // 800F54F0: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F54F4:
    ctx->pc = 0x800F54F4u;
    // 800F54F4: bl      0x80281C60
    {
            ctx->lr = 0x800F54F8u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F54F8:
    ctx->pc = 0x800F54F8u;
    ctx->downcount -= 1;
    // 800F54F8: bl      0x800F1990
    {
            ctx->lr = 0x800F54FCu;
            ctx->pc = 0x800F1990u;
            return;
    }

label_800F54FC:
    ctx->pc = 0x800F54FCu;
    ctx->downcount -= 5;
    // 800F54FC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5500:
    ctx->pc = 0x800F5500u;
    // 800F5500: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5504:
    ctx->pc = 0x800F5504u;
    // 800F5504: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5508:
    ctx->pc = 0x800F5508u;
    // 800F5508: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F550C:
    ctx->pc = 0x800F550Cu;
    ctx->downcount -= 5;
    // 800F550C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5510:
    ctx->pc = 0x800F5510u;
    // 800F5510: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5514:
    ctx->pc = 0x800F5514u;
    // 800F5514: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5518:
    ctx->pc = 0x800F5518u;
    // 800F5518: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F551C:
    ctx->pc = 0x800F551Cu;
    // 800F551C: bl      0x80281C60
    {
            ctx->lr = 0x800F5520u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F5520:
    ctx->pc = 0x800F5520u;
    ctx->downcount -= 1;
    // 800F5520: bl      0x800F1990
    {
            ctx->lr = 0x800F5524u;
            ctx->pc = 0x800F1990u;
            return;
    }

label_800F5524:
    ctx->pc = 0x800F5524u;
    ctx->downcount -= 5;
    // 800F5524: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5528:
    ctx->pc = 0x800F5528u;
    // 800F5528: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F552C:
    ctx->pc = 0x800F552Cu;
    // 800F552C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5530:
    ctx->pc = 0x800F5530u;
    // 800F5530: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5534:
    ctx->pc = 0x800F5534u;
    ctx->downcount -= 16;
    // 800F5534: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5538:
    ctx->pc = 0x800F5538u;
    // 800F5538: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F553C:
    ctx->pc = 0x800F553Cu;
    // 800F553C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5540:
    ctx->pc = 0x800F5540u;
    // 800F5540: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5544:
    ctx->pc = 0x800F5544u;
    // 800F5544: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F5548:
    ctx->pc = 0x800F5548u;
    // 800F5548: bl      0x80281C60
    {
            ctx->lr = 0x800F554Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F554C:
    ctx->pc = 0x800F554Cu;
    ctx->downcount -= 5;
    // 800F554C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5550:
    ctx->pc = 0x800F5550u;
    // 800F5550: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5554:
    ctx->pc = 0x800F5554u;
    // 800F5554: addi    r4, r4, -13548
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13548);

label_800F5558:
    ctx->pc = 0x800F5558u;
    // 800F5558: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F555C:
    ctx->pc = 0x800F555Cu;
    // 800F555C: bl      0x800F0D5C
    {
            ctx->lr = 0x800F5560u;
            ctx->pc = 0x800F0D5Cu;
            return;
    }

label_800F5560:
    ctx->pc = 0x800F5560u;
    ctx->downcount -= 20;
    // 800F5560: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F5564:
    ctx->pc = 0x800F5564u;
    // 800F5564: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F5568:
    ctx->pc = 0x800F5568u;
    // 800F5568: addi    r9, r9, -8128
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8128);

label_800F556C:
    ctx->pc = 0x800F556Cu;
    // 800F556C: stw     r9, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5570:
    ctx->pc = 0x800F5570u;
    // 800F5570: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5574:
    ctx->pc = 0x800F5574u;
    // 800F5574: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5578:
    ctx->pc = 0x800F5578u;
    // 800F5578: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F557C:
    ctx->pc = 0x800F557Cu;
    // 800F557C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F5580:
    ctx->pc = 0x800F5580u;
    // 800F5580: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5584:
    ctx->pc = 0x800F5584u;
    ctx->downcount -= 5;
    // 800F5584: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5588:
    ctx->pc = 0x800F5588u;
    // 800F5588: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F558C:
    ctx->pc = 0x800F558Cu;
    // 800F558C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5590:
    ctx->pc = 0x800F5590u;
    // 800F5590: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F5594:
    ctx->pc = 0x800F5594u;
    // 800F5594: bl      0x80281C60
    {
            ctx->lr = 0x800F5598u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F5598:
    ctx->pc = 0x800F5598u;
    ctx->downcount -= 1;
    // 800F5598: bl      0x800F1A90
    {
            ctx->lr = 0x800F559Cu;
            ctx->pc = 0x800F1A90u;
            return;
    }

label_800F559C:
    ctx->pc = 0x800F559Cu;
    ctx->downcount -= 5;
    // 800F559C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F55A0:
    ctx->pc = 0x800F55A0u;
    // 800F55A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F55A4:
    ctx->pc = 0x800F55A4u;
    // 800F55A4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F55A8:
    ctx->pc = 0x800F55A8u;
    // 800F55A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F55AC:
    ctx->pc = 0x800F55ACu;
    ctx->downcount -= 5;
    // 800F55AC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F55B0:
    ctx->pc = 0x800F55B0u;
    // 800F55B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F55B4:
    ctx->pc = 0x800F55B4u;
    // 800F55B4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F55B8:
    ctx->pc = 0x800F55B8u;
    // 800F55B8: li      r3, 72
    ctx->gpr[3] = (u32)(s32)(72);

label_800F55BC:
    ctx->pc = 0x800F55BCu;
    // 800F55BC: bl      0x80281C60
    {
            ctx->lr = 0x800F55C0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F55C0:
    ctx->pc = 0x800F55C0u;
    ctx->downcount -= 1;
    // 800F55C0: bl      0x800F1608
    {
            ctx->lr = 0x800F55C4u;
            ctx->pc = 0x800F1608u;
            return;
    }

label_800F55C4:
    ctx->pc = 0x800F55C4u;
    ctx->downcount -= 5;
    // 800F55C4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F55C8:
    ctx->pc = 0x800F55C8u;
    // 800F55C8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F55CC:
    ctx->pc = 0x800F55CCu;
    // 800F55CC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F55D0:
    ctx->pc = 0x800F55D0u;
    // 800F55D0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F55D4:
    ctx->pc = 0x800F55D4u;
    ctx->downcount -= 10;
    // 800F55D4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F55D8:
    ctx->pc = 0x800F55D8u;
    // 800F55D8: addi    r4, r4, -1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-1);

label_800F55DC:
    ctx->pc = 0x800F55DCu;
    // 800F55DC: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_800F55E0:
    ctx->pc = 0x800F55E0u;
    // 800F55E0: rlwinm r4, r4, 31, 1, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFCu;
    }

label_800F55E4:
    ctx->pc = 0x800F55E4u;
    // 800F55E4: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_800F55E8:
    ctx->pc = 0x800F55E8u;
    // 800F55E8: lwzx    r0, r4, r9
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F55EC:
    ctx->pc = 0x800F55ECu;
    // 800F55EC: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F55F0:
    ctx->pc = 0x800F55F0u;
    // 800F55F0: stwx    r3, r4, r9
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[9];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800F55F4:
    ctx->pc = 0x800F55F4u;
    // 800F55F4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F55F8:
    ctx->pc = 0x800F55F8u;
    // 800F55F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F55FC:
    ctx->pc = 0x800F55FCu;
    ctx->downcount -= 4;
    // 800F55FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5600:
    ctx->pc = 0x800F5600u;
    // 800F5600: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5604:
    ctx->pc = 0x800F5604u;
    // 800F5604: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5608:
    ctx->pc = 0x800F5608u;
    // 800F5608: bl      0x800F2198
    {
            ctx->lr = 0x800F560Cu;
            ctx->pc = 0x800F2198u;
            return;
    }

label_800F560C:
    ctx->pc = 0x800F560Cu;
    ctx->downcount -= 5;
    // 800F560C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5610:
    ctx->pc = 0x800F5610u;
    // 800F5610: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5614:
    ctx->pc = 0x800F5614u;
    // 800F5614: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5618:
    ctx->pc = 0x800F5618u;
    // 800F5618: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F561C:
    ctx->pc = 0x800F561Cu;
    ctx->downcount -= 4;
    // 800F561C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5620:
    ctx->pc = 0x800F5620u;
    // 800F5620: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5624:
    ctx->pc = 0x800F5624u;
    // 800F5624: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5628:
    ctx->pc = 0x800F5628u;
    // 800F5628: bl      0x800F222C
    {
            ctx->lr = 0x800F562Cu;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F562C:
    ctx->pc = 0x800F562Cu;
    ctx->downcount -= 5;
    // 800F562C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5630:
    ctx->pc = 0x800F5630u;
    // 800F5630: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5634:
    ctx->pc = 0x800F5634u;
    // 800F5634: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5638:
    ctx->pc = 0x800F5638u;
    // 800F5638: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F563C:
    ctx->pc = 0x800F563Cu;
    ctx->downcount -= 4;
    // 800F563C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5640:
    ctx->pc = 0x800F5640u;
    // 800F5640: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5644:
    ctx->pc = 0x800F5644u;
    // 800F5644: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5648:
    ctx->pc = 0x800F5648u;
    // 800F5648: bl      0x800F222C
    {
            ctx->lr = 0x800F564Cu;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F564C:
    ctx->pc = 0x800F564Cu;
    ctx->downcount -= 5;
    // 800F564C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5650:
    ctx->pc = 0x800F5650u;
    // 800F5650: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5654:
    ctx->pc = 0x800F5654u;
    // 800F5654: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5658:
    ctx->pc = 0x800F5658u;
    // 800F5658: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F565C:
    ctx->pc = 0x800F565Cu;
    ctx->downcount -= 4;
    // 800F565C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5660:
    ctx->pc = 0x800F5660u;
    // 800F5660: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5664:
    ctx->pc = 0x800F5664u;
    // 800F5664: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5668:
    ctx->pc = 0x800F5668u;
    // 800F5668: bl      0x800F247C
    {
            ctx->lr = 0x800F566Cu;
            ctx->pc = 0x800F247Cu;
            return;
    }

label_800F566C:
    ctx->pc = 0x800F566Cu;
    ctx->downcount -= 5;
    // 800F566C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5670:
    ctx->pc = 0x800F5670u;
    // 800F5670: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5674:
    ctx->pc = 0x800F5674u;
    // 800F5674: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5678:
    ctx->pc = 0x800F5678u;
    // 800F5678: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F567C:
    ctx->pc = 0x800F567Cu;
    ctx->downcount -= 4;
    // 800F567C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5680:
    ctx->pc = 0x800F5680u;
    // 800F5680: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5684:
    ctx->pc = 0x800F5684u;
    // 800F5684: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5688:
    ctx->pc = 0x800F5688u;
    // 800F5688: bl      0x800F247C
    {
            ctx->lr = 0x800F568Cu;
            ctx->pc = 0x800F247Cu;
            return;
    }

label_800F568C:
    ctx->pc = 0x800F568Cu;
    ctx->downcount -= 5;
    // 800F568C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5690:
    ctx->pc = 0x800F5690u;
    // 800F5690: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5694:
    ctx->pc = 0x800F5694u;
    // 800F5694: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5698:
    ctx->pc = 0x800F5698u;
    // 800F5698: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F569C:
    ctx->pc = 0x800F569Cu;
    ctx->downcount -= 4;
    // 800F569C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F56A0:
    ctx->pc = 0x800F56A0u;
    // 800F56A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F56A4:
    ctx->pc = 0x800F56A4u;
    // 800F56A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F56A8:
    ctx->pc = 0x800F56A8u;
    // 800F56A8: bl      0x800F247C
    {
            ctx->lr = 0x800F56ACu;
            ctx->pc = 0x800F247Cu;
            return;
    }

label_800F56AC:
    ctx->pc = 0x800F56ACu;
    ctx->downcount -= 5;
    // 800F56AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F56B0:
    ctx->pc = 0x800F56B0u;
    // 800F56B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F56B4:
    ctx->pc = 0x800F56B4u;
    // 800F56B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F56B8:
    ctx->pc = 0x800F56B8u;
    // 800F56B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F56BC:
    ctx->pc = 0x800F56BCu;
    ctx->downcount -= 4;
    // 800F56BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F56C0:
    ctx->pc = 0x800F56C0u;
    // 800F56C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F56C4:
    ctx->pc = 0x800F56C4u;
    // 800F56C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F56C8:
    ctx->pc = 0x800F56C8u;
    // 800F56C8: bl      0x800F23E8
    {
            ctx->lr = 0x800F56CCu;
            ctx->pc = 0x800F23E8u;
            return;
    }

label_800F56CC:
    ctx->pc = 0x800F56CCu;
    ctx->downcount -= 5;
    // 800F56CC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F56D0:
    ctx->pc = 0x800F56D0u;
    // 800F56D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F56D4:
    ctx->pc = 0x800F56D4u;
    // 800F56D4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F56D8:
    ctx->pc = 0x800F56D8u;
    // 800F56D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F56DC:
    ctx->pc = 0x800F56DCu;
    ctx->downcount -= 4;
    // 800F56DC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F56E0:
    ctx->pc = 0x800F56E0u;
    // 800F56E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F56E4:
    ctx->pc = 0x800F56E4u;
    // 800F56E4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F56E8:
    ctx->pc = 0x800F56E8u;
    // 800F56E8: bl      0x800F222C
    {
            ctx->lr = 0x800F56ECu;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F56EC:
    ctx->pc = 0x800F56ECu;
    ctx->downcount -= 5;
    // 800F56EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F56F0:
    ctx->pc = 0x800F56F0u;
    // 800F56F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F56F4:
    ctx->pc = 0x800F56F4u;
    // 800F56F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F56F8:
    ctx->pc = 0x800F56F8u;
    // 800F56F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F56FC:
    ctx->pc = 0x800F56FCu;
    ctx->downcount -= 4;
    // 800F56FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5700:
    ctx->pc = 0x800F5700u;
    // 800F5700: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5704:
    ctx->pc = 0x800F5704u;
    // 800F5704: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5708:
    ctx->pc = 0x800F5708u;
    // 800F5708: bl      0x800F25A4
    {
            ctx->lr = 0x800F570Cu;
            ctx->pc = 0x800F25A4u;
            return;
    }

label_800F570C:
    ctx->pc = 0x800F570Cu;
    ctx->downcount -= 5;
    // 800F570C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5710:
    ctx->pc = 0x800F5710u;
    // 800F5710: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5714:
    ctx->pc = 0x800F5714u;
    // 800F5714: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5718:
    ctx->pc = 0x800F5718u;
    // 800F5718: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F571C:
    ctx->pc = 0x800F571Cu;
    ctx->downcount -= 4;
    // 800F571C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5720:
    ctx->pc = 0x800F5720u;
    // 800F5720: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5724:
    ctx->pc = 0x800F5724u;
    // 800F5724: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5728:
    ctx->pc = 0x800F5728u;
    // 800F5728: bl      0x800F222C
    {
            ctx->lr = 0x800F572Cu;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F572C:
    ctx->pc = 0x800F572Cu;
    ctx->downcount -= 5;
    // 800F572C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5730:
    ctx->pc = 0x800F5730u;
    // 800F5730: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5734:
    ctx->pc = 0x800F5734u;
    // 800F5734: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5738:
    ctx->pc = 0x800F5738u;
    // 800F5738: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F573C:
    ctx->pc = 0x800F573Cu;
    ctx->downcount -= 4;
    // 800F573C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5740:
    ctx->pc = 0x800F5740u;
    // 800F5740: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5744:
    ctx->pc = 0x800F5744u;
    // 800F5744: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5748:
    ctx->pc = 0x800F5748u;
    // 800F5748: bl      0x800F222C
    {
            ctx->lr = 0x800F574Cu;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F574C:
    ctx->pc = 0x800F574Cu;
    ctx->downcount -= 5;
    // 800F574C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5750:
    ctx->pc = 0x800F5750u;
    // 800F5750: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5754:
    ctx->pc = 0x800F5754u;
    // 800F5754: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5758:
    ctx->pc = 0x800F5758u;
    // 800F5758: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F575C:
    ctx->pc = 0x800F575Cu;
    ctx->downcount -= 4;
    // 800F575C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5760:
    ctx->pc = 0x800F5760u;
    // 800F5760: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5764:
    ctx->pc = 0x800F5764u;
    // 800F5764: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5768:
    ctx->pc = 0x800F5768u;
    // 800F5768: bl      0x800F222C
    {
            ctx->lr = 0x800F576Cu;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F576C:
    ctx->pc = 0x800F576Cu;
    ctx->downcount -= 5;
    // 800F576C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5770:
    ctx->pc = 0x800F5770u;
    // 800F5770: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5774:
    ctx->pc = 0x800F5774u;
    // 800F5774: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5778:
    ctx->pc = 0x800F5778u;
    // 800F5778: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F577C:
    ctx->pc = 0x800F577Cu;
    ctx->downcount -= 4;
    // 800F577C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5780:
    ctx->pc = 0x800F5780u;
    // 800F5780: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5784:
    ctx->pc = 0x800F5784u;
    // 800F5784: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5788:
    ctx->pc = 0x800F5788u;
    // 800F5788: bl      0x800F222C
    {
            ctx->lr = 0x800F578Cu;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F578C:
    ctx->pc = 0x800F578Cu;
    ctx->downcount -= 5;
    // 800F578C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5790:
    ctx->pc = 0x800F5790u;
    // 800F5790: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5794:
    ctx->pc = 0x800F5794u;
    // 800F5794: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5798:
    ctx->pc = 0x800F5798u;
    // 800F5798: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F579C:
    ctx->pc = 0x800F579Cu;
    ctx->downcount -= 4;
    // 800F579C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F57A0:
    ctx->pc = 0x800F57A0u;
    // 800F57A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F57A4:
    ctx->pc = 0x800F57A4u;
    // 800F57A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F57A8:
    ctx->pc = 0x800F57A8u;
    // 800F57A8: bl      0x800F222C
    {
            ctx->lr = 0x800F57ACu;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F57AC:
    ctx->pc = 0x800F57ACu;
    ctx->downcount -= 5;
    // 800F57AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F57B0:
    ctx->pc = 0x800F57B0u;
    // 800F57B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F57B4:
    ctx->pc = 0x800F57B4u;
    // 800F57B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F57B8:
    ctx->pc = 0x800F57B8u;
    // 800F57B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F57BC:
    ctx->pc = 0x800F57BCu;
    ctx->downcount -= 4;
    // 800F57BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F57C0:
    ctx->pc = 0x800F57C0u;
    // 800F57C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F57C4:
    ctx->pc = 0x800F57C4u;
    // 800F57C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F57C8:
    ctx->pc = 0x800F57C8u;
    // 800F57C8: bl      0x800F247C
    {
            ctx->lr = 0x800F57CCu;
            ctx->pc = 0x800F247Cu;
            return;
    }

label_800F57CC:
    ctx->pc = 0x800F57CCu;
    ctx->downcount -= 5;
    // 800F57CC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F57D0:
    ctx->pc = 0x800F57D0u;
    // 800F57D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F57D4:
    ctx->pc = 0x800F57D4u;
    // 800F57D4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F57D8:
    ctx->pc = 0x800F57D8u;
    // 800F57D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F57DC:
    ctx->pc = 0x800F57DCu;
    ctx->downcount -= 4;
    // 800F57DC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F57E0:
    ctx->pc = 0x800F57E0u;
    // 800F57E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F57E4:
    ctx->pc = 0x800F57E4u;
    // 800F57E4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F57E8:
    ctx->pc = 0x800F57E8u;
    // 800F57E8: bl      0x800F2354
    {
            ctx->lr = 0x800F57ECu;
            ctx->pc = 0x800F2354u;
            return;
    }

label_800F57EC:
    ctx->pc = 0x800F57ECu;
    ctx->downcount -= 5;
    // 800F57EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F57F0:
    ctx->pc = 0x800F57F0u;
    // 800F57F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F57F4:
    ctx->pc = 0x800F57F4u;
    // 800F57F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F57F8:
    ctx->pc = 0x800F57F8u;
    // 800F57F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F57FC:
    ctx->pc = 0x800F57FCu;
    ctx->downcount -= 4;
    // 800F57FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5800:
    ctx->pc = 0x800F5800u;
    // 800F5800: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5804:
    ctx->pc = 0x800F5804u;
    // 800F5804: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5808:
    ctx->pc = 0x800F5808u;
    // 800F5808: bl      0x800F247C
    {
            ctx->lr = 0x800F580Cu;
            ctx->pc = 0x800F247Cu;
            return;
    }

label_800F580C:
    ctx->pc = 0x800F580Cu;
    ctx->downcount -= 5;
    // 800F580C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5810:
    ctx->pc = 0x800F5810u;
    // 800F5810: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5814:
    ctx->pc = 0x800F5814u;
    // 800F5814: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5818:
    ctx->pc = 0x800F5818u;
    // 800F5818: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F581C:
    ctx->pc = 0x800F581Cu;
    ctx->downcount -= 20;
    // 800F581C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5820:
    ctx->pc = 0x800F5820u;
    // 800F5820: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5824:
    ctx->pc = 0x800F5824u;
    // 800F5824: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5828:
    ctx->pc = 0x800F5828u;
    // 800F5828: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F582C:
    ctx->pc = 0x800F582Cu;
    // 800F582C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F5830:
    ctx->pc = 0x800F5830u;
    // 800F5830: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5834:
    ctx->pc = 0x800F5834u;
    // 800F5834: addi    r9, r9, -10616
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10616);

label_800F5838:
    ctx->pc = 0x800F5838u;
    // 800F5838: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800F583C:
    ctx->pc = 0x800F583Cu;
    // 800F583C: stw     r9, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5840:
    ctx->pc = 0x800F5840u;
    // 800F5840: bl      0x80106E94
    {
            ctx->lr = 0x800F5844u;
            ctx->pc = 0x80106E94u;
            return;
    }

label_800F5844:
    ctx->pc = 0x800F5844u;
    ctx->downcount -= 5;
    // 800F5844: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F5848:
    ctx->pc = 0x800F5848u;
    // 800F5848: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F584C:
    ctx->pc = 0x800F584Cu;
    // 800F584C: stw     r0, -25068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25068);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5850:
    ctx->pc = 0x800F5850u;
    // 800F5850: cmpwi   r3, 0
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

label_800F5854:
    ctx->pc = 0x800F5854u;
    // 800F5854: bc    12, 2, 0x800F585C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F585C;
        }
    }

label_800F5858:
    ctx->pc = 0x800F5858u;
    ctx->downcount -= 1;
    // 800F5858: bl      0x80281DD0
    {
            ctx->lr = 0x800F585Cu;
            ctx->pc = 0x80281DD0u;
            return;
    }

label_800F585C:
    ctx->pc = 0x800F585Cu;
    ctx->downcount -= 4;
    // 800F585C: or   r9, r31, r31
    {
        ctx->gpr[9] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F5860:
    ctx->pc = 0x800F5860u;
    // 800F5860: lwzu     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_800F5864:
    ctx->pc = 0x800F5864u;
    // 800F5864: cmpwi   r3, 0
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

label_800F5868:
    ctx->pc = 0x800F5868u;
    // 800F5868: bc    12, 2, 0x800F588C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F588C;
        }
    }

label_800F586C:
    ctx->pc = 0x800F586Cu;
    ctx->downcount -= 5;
    // 800F586C: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5870:
    ctx->pc = 0x800F5870u;
    // 800F5870: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800F5874:
    ctx->pc = 0x800F5874u;
    // 800F5874: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_800F5878:
    ctx->pc = 0x800F5878u;
    // 800F5878: cmplwi  r4, 0x0080
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

label_800F587C:
    ctx->pc = 0x800F587Cu;
    // 800F587C: bc    4, 1, 0x800F5888
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F5888;
        }
    }

label_800F5880:
    ctx->pc = 0x800F5880u;
    ctx->downcount -= 1;
    // 800F5880: bl      0x80281D80
    {
            ctx->lr = 0x800F5884u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800F5884:
    ctx->pc = 0x800F5884u;
    ctx->downcount -= 1;
    // 800F5884: b       0x800F588C
    {
            goto label_800F588C;
    }

label_800F5888:
    ctx->pc = 0x800F5888u;
    ctx->downcount -= 1;
    // 800F5888: bl      0x8001D934
    {
            ctx->lr = 0x800F588Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_800F588C:
    ctx->pc = 0x800F588Cu;
    ctx->downcount -= 2;
    // 800F588C: andi.   r0, r30, 0x0001
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

label_800F5890:
    ctx->pc = 0x800F5890u;
    // 800F5890: bc    12, 2, 0x800F589C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F589C;
        }
    }

label_800F5894:
    ctx->pc = 0x800F5894u;
    ctx->downcount -= 2;
    // 800F5894: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F5898:
    ctx->pc = 0x800F5898u;
    // 800F5898: bl      0x80281D80
    {
            ctx->lr = 0x800F589Cu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800F589C:
    ctx->pc = 0x800F589Cu;
    ctx->downcount -= 16;
    // 800F589C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F58A0:
    ctx->pc = 0x800F58A0u;
    // 800F58A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F58A4:
    ctx->pc = 0x800F58A4u;
    // 800F58A4: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F58A8:
    ctx->pc = 0x800F58A8u;
    // 800F58A8: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F58AC:
    ctx->pc = 0x800F58ACu;
    // 800F58AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F58B0:
    ctx->pc = 0x800F58B0u;
    ctx->downcount -= 2;
    // 800F58B0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800F58B4:
    ctx->pc = 0x800F58B4u;
    // 800F58B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F58B8:
    ctx->pc = 0x800F58B8u;
    ctx->downcount -= 20;
    // 800F58B8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F58BC:
    ctx->pc = 0x800F58BCu;
    // 800F58BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F58C0:
    ctx->pc = 0x800F58C0u;
    // 800F58C0: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F58C4:
    ctx->pc = 0x800F58C4u;
    // 800F58C4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F58C8:
    ctx->pc = 0x800F58C8u;
    // 800F58C8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F58CC:
    ctx->pc = 0x800F58CCu;
    // 800F58CC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F58D0:
    ctx->pc = 0x800F58D0u;
    // 800F58D0: addi    r9, r9, -10616
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-10616);

label_800F58D4:
    ctx->pc = 0x800F58D4u;
    // 800F58D4: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800F58D8:
    ctx->pc = 0x800F58D8u;
    // 800F58D8: stw     r9, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F58DC:
    ctx->pc = 0x800F58DCu;
    // 800F58DC: bl      0x80106E94
    {
            ctx->lr = 0x800F58E0u;
            ctx->pc = 0x80106E94u;
            return;
    }

label_800F58E0:
    ctx->pc = 0x800F58E0u;
    ctx->downcount -= 5;
    // 800F58E0: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F58E4:
    ctx->pc = 0x800F58E4u;
    // 800F58E4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F58E8:
    ctx->pc = 0x800F58E8u;
    // 800F58E8: stw     r0, -25068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25068);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F58EC:
    ctx->pc = 0x800F58ECu;
    // 800F58EC: cmpwi   r3, 0
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

label_800F58F0:
    ctx->pc = 0x800F58F0u;
    // 800F58F0: bc    12, 2, 0x800F58F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F58F8;
        }
    }

label_800F58F4:
    ctx->pc = 0x800F58F4u;
    ctx->downcount -= 1;
    // 800F58F4: bl      0x80281DD0
    {
            ctx->lr = 0x800F58F8u;
            ctx->pc = 0x80281DD0u;
            return;
    }

label_800F58F8:
    ctx->pc = 0x800F58F8u;
    ctx->downcount -= 4;
    // 800F58F8: or   r9, r31, r31
    {
        ctx->gpr[9] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F58FC:
    ctx->pc = 0x800F58FCu;
    // 800F58FC: lwzu     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

label_800F5900:
    ctx->pc = 0x800F5900u;
    // 800F5900: cmpwi   r3, 0
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

label_800F5904:
    ctx->pc = 0x800F5904u;
    // 800F5904: bc    12, 2, 0x800F5928
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F5928;
        }
    }

label_800F5908:
    ctx->pc = 0x800F5908u;
    ctx->downcount -= 5;
    // 800F5908: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F590C:
    ctx->pc = 0x800F590Cu;
    // 800F590C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800F5910:
    ctx->pc = 0x800F5910u;
    // 800F5910: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_800F5914:
    ctx->pc = 0x800F5914u;
    // 800F5914: cmplwi  r4, 0x0080
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

label_800F5918:
    ctx->pc = 0x800F5918u;
    // 800F5918: bc    4, 1, 0x800F5924
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F5924;
        }
    }

label_800F591C:
    ctx->pc = 0x800F591Cu;
    ctx->downcount -= 1;
    // 800F591C: bl      0x80281D80
    {
            ctx->lr = 0x800F5920u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800F5920:
    ctx->pc = 0x800F5920u;
    ctx->downcount -= 1;
    // 800F5920: b       0x800F5928
    {
            goto label_800F5928;
    }

label_800F5924:
    ctx->pc = 0x800F5924u;
    ctx->downcount -= 1;
    // 800F5924: bl      0x8001D934
    {
            ctx->lr = 0x800F5928u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_800F5928:
    ctx->pc = 0x800F5928u;
    ctx->downcount -= 2;
    // 800F5928: andi.   r0, r30, 0x0001
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

label_800F592C:
    ctx->pc = 0x800F592Cu;
    // 800F592C: bc    12, 2, 0x800F5938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F5938;
        }
    }

label_800F5930:
    ctx->pc = 0x800F5930u;
    ctx->downcount -= 2;
    // 800F5930: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F5934:
    ctx->pc = 0x800F5934u;
    // 800F5934: bl      0x80281D80
    {
            ctx->lr = 0x800F5938u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_800F5938:
    ctx->pc = 0x800F5938u;
    ctx->downcount -= 16;
    // 800F5938: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F593C:
    ctx->pc = 0x800F593Cu;
    // 800F593C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5940:
    ctx->pc = 0x800F5940u;
    // 800F5940: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F5944:
    ctx->pc = 0x800F5944u;
    // 800F5944: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F5948:
    ctx->pc = 0x800F5948u;
    // 800F5948: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F594C:
    ctx->pc = 0x800F594Cu;
    ctx->downcount -= 2;
    // 800F594C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800F5950:
    ctx->pc = 0x800F5950u;
    // 800F5950: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5954:
    ctx->pc = 0x800F5954u;
    ctx->downcount -= 4;
    // 800F5954: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5958:
    ctx->pc = 0x800F5958u;
    // 800F5958: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F595C:
    ctx->pc = 0x800F595Cu;
    // 800F595C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5960:
    ctx->pc = 0x800F5960u;
    // 800F5960: bl      0x800F2354
    {
            ctx->lr = 0x800F5964u;
            ctx->pc = 0x800F2354u;
            return;
    }

label_800F5964:
    ctx->pc = 0x800F5964u;
    ctx->downcount -= 5;
    // 800F5964: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5968:
    ctx->pc = 0x800F5968u;
    // 800F5968: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F596C:
    ctx->pc = 0x800F596Cu;
    // 800F596C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5970:
    ctx->pc = 0x800F5970u;
    // 800F5970: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5974:
    ctx->pc = 0x800F5974u;
    ctx->downcount -= 4;
    // 800F5974: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5978:
    ctx->pc = 0x800F5978u;
    // 800F5978: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F597C:
    ctx->pc = 0x800F597Cu;
    // 800F597C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5980:
    ctx->pc = 0x800F5980u;
    // 800F5980: bl      0x800F222C
    {
            ctx->lr = 0x800F5984u;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F5984:
    ctx->pc = 0x800F5984u;
    ctx->downcount -= 5;
    // 800F5984: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5988:
    ctx->pc = 0x800F5988u;
    // 800F5988: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F598C:
    ctx->pc = 0x800F598Cu;
    // 800F598C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5990:
    ctx->pc = 0x800F5990u;
    // 800F5990: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5994:
    ctx->pc = 0x800F5994u;
    ctx->downcount -= 4;
    // 800F5994: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5998:
    ctx->pc = 0x800F5998u;
    // 800F5998: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F599C:
    ctx->pc = 0x800F599Cu;
    // 800F599C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F59A0:
    ctx->pc = 0x800F59A0u;
    // 800F59A0: bl      0x800F222C
    {
            ctx->lr = 0x800F59A4u;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F59A4:
    ctx->pc = 0x800F59A4u;
    ctx->downcount -= 5;
    // 800F59A4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F59A8:
    ctx->pc = 0x800F59A8u;
    // 800F59A8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F59AC:
    ctx->pc = 0x800F59ACu;
    // 800F59AC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F59B0:
    ctx->pc = 0x800F59B0u;
    // 800F59B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F59B4:
    ctx->pc = 0x800F59B4u;
    ctx->downcount -= 4;
    // 800F59B4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F59B8:
    ctx->pc = 0x800F59B8u;
    // 800F59B8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F59BC:
    ctx->pc = 0x800F59BCu;
    // 800F59BC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F59C0:
    ctx->pc = 0x800F59C0u;
    // 800F59C0: bl      0x800F2354
    {
            ctx->lr = 0x800F59C4u;
            ctx->pc = 0x800F2354u;
            return;
    }

label_800F59C4:
    ctx->pc = 0x800F59C4u;
    ctx->downcount -= 5;
    // 800F59C4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F59C8:
    ctx->pc = 0x800F59C8u;
    // 800F59C8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F59CC:
    ctx->pc = 0x800F59CCu;
    // 800F59CC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F59D0:
    ctx->pc = 0x800F59D0u;
    // 800F59D0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F59D4:
    ctx->pc = 0x800F59D4u;
    ctx->downcount -= 4;
    // 800F59D4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F59D8:
    ctx->pc = 0x800F59D8u;
    // 800F59D8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F59DC:
    ctx->pc = 0x800F59DCu;
    // 800F59DC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F59E0:
    ctx->pc = 0x800F59E0u;
    // 800F59E0: bl      0x800F222C
    {
            ctx->lr = 0x800F59E4u;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F59E4:
    ctx->pc = 0x800F59E4u;
    ctx->downcount -= 5;
    // 800F59E4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F59E8:
    ctx->pc = 0x800F59E8u;
    // 800F59E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F59EC:
    ctx->pc = 0x800F59ECu;
    // 800F59EC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F59F0:
    ctx->pc = 0x800F59F0u;
    // 800F59F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F59F4:
    ctx->pc = 0x800F59F4u;
    ctx->downcount -= 4;
    // 800F59F4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F59F8:
    ctx->pc = 0x800F59F8u;
    // 800F59F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F59FC:
    ctx->pc = 0x800F59FCu;
    // 800F59FC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5A00:
    ctx->pc = 0x800F5A00u;
    // 800F5A00: bl      0x800F222C
    {
            ctx->lr = 0x800F5A04u;
            ctx->pc = 0x800F222Cu;
            return;
    }

label_800F5A04:
    ctx->pc = 0x800F5A04u;
    ctx->downcount -= 5;
    // 800F5A04: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5A08:
    ctx->pc = 0x800F5A08u;
    // 800F5A08: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5A0C:
    ctx->pc = 0x800F5A0Cu;
    // 800F5A0C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5A10:
    ctx->pc = 0x800F5A10u;
    // 800F5A10: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5A14:
    ctx->pc = 0x800F5A14u;
    ctx->downcount -= 4;
    // 800F5A14: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5A18:
    ctx->pc = 0x800F5A18u;
    // 800F5A18: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5A1C:
    ctx->pc = 0x800F5A1Cu;
    // 800F5A1C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5A20:
    ctx->pc = 0x800F5A20u;
    // 800F5A20: bl      0x800F2D40
    {
            ctx->lr = 0x800F5A24u;
            ctx->pc = 0x800F2D40u;
            return;
    }

label_800F5A24:
    ctx->pc = 0x800F5A24u;
    ctx->downcount -= 5;
    // 800F5A24: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5A28:
    ctx->pc = 0x800F5A28u;
    // 800F5A28: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5A2C:
    ctx->pc = 0x800F5A2Cu;
    // 800F5A2C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5A30:
    ctx->pc = 0x800F5A30u;
    // 800F5A30: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5A34:
    ctx->pc = 0x800F5A34u;
    ctx->downcount -= 4;
    // 800F5A34: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5A38:
    ctx->pc = 0x800F5A38u;
    // 800F5A38: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5A3C:
    ctx->pc = 0x800F5A3Cu;
    // 800F5A3C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5A40:
    ctx->pc = 0x800F5A40u;
    // 800F5A40: bl      0x800F2D40
    {
            ctx->lr = 0x800F5A44u;
            ctx->pc = 0x800F2D40u;
            return;
    }

label_800F5A44:
    ctx->pc = 0x800F5A44u;
    ctx->downcount -= 5;
    // 800F5A44: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5A48:
    ctx->pc = 0x800F5A48u;
    // 800F5A48: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5A4C:
    ctx->pc = 0x800F5A4Cu;
    // 800F5A4C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5A50:
    ctx->pc = 0x800F5A50u;
    // 800F5A50: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5A54:
    ctx->pc = 0x800F5A54u;
    ctx->downcount -= 4;
    // 800F5A54: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5A58:
    ctx->pc = 0x800F5A58u;
    // 800F5A58: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5A5C:
    ctx->pc = 0x800F5A5Cu;
    // 800F5A5C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5A60:
    ctx->pc = 0x800F5A60u;
    // 800F5A60: bl      0x800F2D40
    {
            ctx->lr = 0x800F5A64u;
            ctx->pc = 0x800F2D40u;
            return;
    }

label_800F5A64:
    ctx->pc = 0x800F5A64u;
    ctx->downcount -= 5;
    // 800F5A64: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5A68:
    ctx->pc = 0x800F5A68u;
    // 800F5A68: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5A6C:
    ctx->pc = 0x800F5A6Cu;
    // 800F5A6C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5A70:
    ctx->pc = 0x800F5A70u;
    // 800F5A70: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5A74:
    ctx->pc = 0x800F5A74u;
    ctx->downcount -= 4;
    // 800F5A74: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5A78:
    ctx->pc = 0x800F5A78u;
    // 800F5A78: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5A7C:
    ctx->pc = 0x800F5A7Cu;
    // 800F5A7C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5A80:
    ctx->pc = 0x800F5A80u;
    // 800F5A80: bl      0x800F2D40
    {
            ctx->lr = 0x800F5A84u;
            ctx->pc = 0x800F2D40u;
            return;
    }

label_800F5A84:
    ctx->pc = 0x800F5A84u;
    ctx->downcount -= 5;
    // 800F5A84: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5A88:
    ctx->pc = 0x800F5A88u;
    // 800F5A88: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5A8C:
    ctx->pc = 0x800F5A8Cu;
    // 800F5A8C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5A90:
    ctx->pc = 0x800F5A90u;
    // 800F5A90: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5A94:
    ctx->pc = 0x800F5A94u;
    ctx->downcount -= 4;
    // 800F5A94: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5A98:
    ctx->pc = 0x800F5A98u;
    // 800F5A98: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5A9C:
    ctx->pc = 0x800F5A9Cu;
    // 800F5A9C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5AA0:
    ctx->pc = 0x800F5AA0u;
    // 800F5AA0: bl      0x800F2D40
    {
            ctx->lr = 0x800F5AA4u;
            ctx->pc = 0x800F2D40u;
            return;
    }

label_800F5AA4:
    ctx->pc = 0x800F5AA4u;
    ctx->downcount -= 5;
    // 800F5AA4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5AA8:
    ctx->pc = 0x800F5AA8u;
    // 800F5AA8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5AAC:
    ctx->pc = 0x800F5AACu;
    // 800F5AAC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5AB0:
    ctx->pc = 0x800F5AB0u;
    // 800F5AB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5AB4:
    ctx->pc = 0x800F5AB4u;
    ctx->downcount -= 4;
    // 800F5AB4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5AB8:
    ctx->pc = 0x800F5AB8u;
    // 800F5AB8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5ABC:
    ctx->pc = 0x800F5ABCu;
    // 800F5ABC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5AC0:
    ctx->pc = 0x800F5AC0u;
    // 800F5AC0: bl      0x800F2D40
    {
            ctx->lr = 0x800F5AC4u;
            ctx->pc = 0x800F2D40u;
            return;
    }

label_800F5AC4:
    ctx->pc = 0x800F5AC4u;
    ctx->downcount -= 5;
    // 800F5AC4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5AC8:
    ctx->pc = 0x800F5AC8u;
    // 800F5AC8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5ACC:
    ctx->pc = 0x800F5ACCu;
    // 800F5ACC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5AD0:
    ctx->pc = 0x800F5AD0u;
    // 800F5AD0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5AD4:
    ctx->pc = 0x800F5AD4u;
    ctx->downcount -= 4;
    // 800F5AD4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5AD8:
    ctx->pc = 0x800F5AD8u;
    // 800F5AD8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5ADC:
    ctx->pc = 0x800F5ADCu;
    // 800F5ADC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5AE0:
    ctx->pc = 0x800F5AE0u;
    // 800F5AE0: bl      0x800F2D40
    {
            ctx->lr = 0x800F5AE4u;
            ctx->pc = 0x800F2D40u;
            return;
    }

label_800F5AE4:
    ctx->pc = 0x800F5AE4u;
    ctx->downcount -= 5;
    // 800F5AE4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5AE8:
    ctx->pc = 0x800F5AE8u;
    // 800F5AE8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5AEC:
    ctx->pc = 0x800F5AECu;
    // 800F5AEC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5AF0:
    ctx->pc = 0x800F5AF0u;
    // 800F5AF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5AF4:
    ctx->pc = 0x800F5AF4u;
    ctx->downcount -= 4;
    // 800F5AF4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5AF8:
    ctx->pc = 0x800F5AF8u;
    // 800F5AF8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5AFC:
    ctx->pc = 0x800F5AFCu;
    // 800F5AFC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5B00:
    ctx->pc = 0x800F5B00u;
    // 800F5B00: bl      0x800F2D40
    {
            ctx->lr = 0x800F5B04u;
            ctx->pc = 0x800F2D40u;
            return;
    }

label_800F5B04:
    ctx->pc = 0x800F5B04u;
    ctx->downcount -= 5;
    // 800F5B04: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5B08:
    ctx->pc = 0x800F5B08u;
    // 800F5B08: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5B0C:
    ctx->pc = 0x800F5B0Cu;
    // 800F5B0C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5B10:
    ctx->pc = 0x800F5B10u;
    // 800F5B10: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5B14:
    ctx->pc = 0x800F5B14u;
    ctx->downcount -= 7;
    // 800F5B14: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5B18:
    ctx->pc = 0x800F5B18u;
    // 800F5B18: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5B1C:
    ctx->pc = 0x800F5B1Cu;
    // 800F5B1C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5B20:
    ctx->pc = 0x800F5B20u;
    // 800F5B20: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800F5B24:
    ctx->pc = 0x800F5B24u;
    // 800F5B24: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800F5B28:
    ctx->pc = 0x800F5B28u;
    // 800F5B28: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_800F5B2C:
    ctx->pc = 0x800F5B2Cu;
    // 800F5B2C: bl      0x800F2024
    {
            ctx->lr = 0x800F5B30u;
            ctx->pc = 0x800F2024u;
            return;
    }

label_800F5B30:
    ctx->pc = 0x800F5B30u;
    ctx->downcount -= 5;
    // 800F5B30: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5B34:
    ctx->pc = 0x800F5B34u;
    // 800F5B34: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5B38:
    ctx->pc = 0x800F5B38u;
    // 800F5B38: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5B3C:
    ctx->pc = 0x800F5B3Cu;
    // 800F5B3C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5B40:
    ctx->pc = 0x800F5B40u;
    ctx->downcount -= 7;
    // 800F5B40: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5B44:
    ctx->pc = 0x800F5B44u;
    // 800F5B44: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5B48:
    ctx->pc = 0x800F5B48u;
    // 800F5B48: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5B4C:
    ctx->pc = 0x800F5B4Cu;
    // 800F5B4C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F5B50:
    ctx->pc = 0x800F5B50u;
    // 800F5B50: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_800F5B54:
    ctx->pc = 0x800F5B54u;
    // 800F5B54: cmpw    r4, r0
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

label_800F5B58:
    ctx->pc = 0x800F5B58u;
    // 800F5B58: bc    4, 2, 0x800F5CA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F5CA4;
        }
    }

label_800F5B5C:
    ctx->pc = 0x800F5B5Cu;
    ctx->downcount -= 2;
    // 800F5B5C: cmpwi   r3, 0
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

label_800F5B60:
    ctx->pc = 0x800F5B60u;
    // 800F5B60: bc    12, 2, 0x800F5CA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F5CA4;
        }
    }

label_800F5B64:
    ctx->pc = 0x800F5B64u;
    ctx->downcount -= 8;
    // 800F5B64: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5B68:
    ctx->pc = 0x800F5B68u;
    // 800F5B68: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5B6C:
    ctx->pc = 0x800F5B6Cu;
    // 800F5B6C: addi    r4, r4, -7556
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-7556);

label_800F5B70:
    ctx->pc = 0x800F5B70u;
    // 800F5B70: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F5B74:
    ctx->pc = 0x800F5B74u;
    // 800F5B74: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_800F5B78:
    ctx->pc = 0x800F5B78u;
    // 800F5B78: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800F5B7C:
    ctx->pc = 0x800F5B7Cu;
    // 800F5B7C: addi    r3, r13, -27504
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27504);

label_800F5B80:
    ctx->pc = 0x800F5B80u;
    // 800F5B80: bl      0x8027A270
    {
            ctx->lr = 0x800F5B84u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_800F5B84:
    ctx->pc = 0x800F5B84u;
    ctx->downcount -= 8;
    // 800F5B84: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5B88:
    ctx->pc = 0x800F5B88u;
    // 800F5B88: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5B8C:
    ctx->pc = 0x800F5B8Cu;
    // 800F5B8C: addi    r4, r4, -7524
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-7524);

label_800F5B90:
    ctx->pc = 0x800F5B90u;
    // 800F5B90: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F5B94:
    ctx->pc = 0x800F5B94u;
    // 800F5B94: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_800F5B98:
    ctx->pc = 0x800F5B98u;
    // 800F5B98: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800F5B9C:
    ctx->pc = 0x800F5B9Cu;
    // 800F5B9C: addi    r3, r13, -27500
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27500);

label_800F5BA0:
    ctx->pc = 0x800F5BA0u;
    // 800F5BA0: bl      0x8027A270
    {
            ctx->lr = 0x800F5BA4u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_800F5BA4:
    ctx->pc = 0x800F5BA4u;
    ctx->downcount -= 8;
    // 800F5BA4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5BA8:
    ctx->pc = 0x800F5BA8u;
    // 800F5BA8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5BAC:
    ctx->pc = 0x800F5BACu;
    // 800F5BAC: addi    r4, r4, -7488
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-7488);

label_800F5BB0:
    ctx->pc = 0x800F5BB0u;
    // 800F5BB0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F5BB4:
    ctx->pc = 0x800F5BB4u;
    // 800F5BB4: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_800F5BB8:
    ctx->pc = 0x800F5BB8u;
    // 800F5BB8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800F5BBC:
    ctx->pc = 0x800F5BBCu;
    // 800F5BBC: addi    r3, r13, -27496
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27496);

label_800F5BC0:
    ctx->pc = 0x800F5BC0u;
    // 800F5BC0: bl      0x8027A270
    {
            ctx->lr = 0x800F5BC4u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_800F5BC4:
    ctx->pc = 0x800F5BC4u;
    ctx->downcount -= 8;
    // 800F5BC4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5BC8:
    ctx->pc = 0x800F5BC8u;
    // 800F5BC8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5BCC:
    ctx->pc = 0x800F5BCCu;
    // 800F5BCC: addi    r4, r4, -7448
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-7448);

label_800F5BD0:
    ctx->pc = 0x800F5BD0u;
    // 800F5BD0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F5BD4:
    ctx->pc = 0x800F5BD4u;
    // 800F5BD4: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_800F5BD8:
    ctx->pc = 0x800F5BD8u;
    // 800F5BD8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800F5BDC:
    ctx->pc = 0x800F5BDCu;
    // 800F5BDC: addi    r3, r13, -27492
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27492);

label_800F5BE0:
    ctx->pc = 0x800F5BE0u;
    // 800F5BE0: bl      0x8027A270
    {
            ctx->lr = 0x800F5BE4u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_800F5BE4:
    ctx->pc = 0x800F5BE4u;
    ctx->downcount -= 8;
    // 800F5BE4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5BE8:
    ctx->pc = 0x800F5BE8u;
    // 800F5BE8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5BEC:
    ctx->pc = 0x800F5BECu;
    // 800F5BEC: addi    r4, r4, -7412
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-7412);

label_800F5BF0:
    ctx->pc = 0x800F5BF0u;
    // 800F5BF0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F5BF4:
    ctx->pc = 0x800F5BF4u;
    // 800F5BF4: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_800F5BF8:
    ctx->pc = 0x800F5BF8u;
    // 800F5BF8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800F5BFC:
    ctx->pc = 0x800F5BFCu;
    // 800F5BFC: addi    r3, r13, -27488
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27488);

label_800F5C00:
    ctx->pc = 0x800F5C00u;
    // 800F5C00: bl      0x8027A270
    {
            ctx->lr = 0x800F5C04u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_800F5C04:
    ctx->pc = 0x800F5C04u;
    ctx->downcount -= 8;
    // 800F5C04: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5C08:
    ctx->pc = 0x800F5C08u;
    // 800F5C08: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5C0C:
    ctx->pc = 0x800F5C0Cu;
    // 800F5C0C: addi    r4, r4, -7376
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-7376);

label_800F5C10:
    ctx->pc = 0x800F5C10u;
    // 800F5C10: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F5C14:
    ctx->pc = 0x800F5C14u;
    // 800F5C14: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_800F5C18:
    ctx->pc = 0x800F5C18u;
    // 800F5C18: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800F5C1C:
    ctx->pc = 0x800F5C1Cu;
    // 800F5C1C: addi    r3, r13, -27484
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27484);

label_800F5C20:
    ctx->pc = 0x800F5C20u;
    // 800F5C20: bl      0x8027A270
    {
            ctx->lr = 0x800F5C24u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_800F5C24:
    ctx->pc = 0x800F5C24u;
    ctx->downcount -= 8;
    // 800F5C24: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5C28:
    ctx->pc = 0x800F5C28u;
    // 800F5C28: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5C2C:
    ctx->pc = 0x800F5C2Cu;
    // 800F5C2C: addi    r4, r4, -7336
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-7336);

label_800F5C30:
    ctx->pc = 0x800F5C30u;
    // 800F5C30: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F5C34:
    ctx->pc = 0x800F5C34u;
    // 800F5C34: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_800F5C38:
    ctx->pc = 0x800F5C38u;
    // 800F5C38: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800F5C3C:
    ctx->pc = 0x800F5C3Cu;
    // 800F5C3C: addi    r3, r13, -27480
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27480);

label_800F5C40:
    ctx->pc = 0x800F5C40u;
    // 800F5C40: bl      0x8027A270
    {
            ctx->lr = 0x800F5C44u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_800F5C44:
    ctx->pc = 0x800F5C44u;
    ctx->downcount -= 8;
    // 800F5C44: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5C48:
    ctx->pc = 0x800F5C48u;
    // 800F5C48: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5C4C:
    ctx->pc = 0x800F5C4Cu;
    // 800F5C4C: addi    r4, r4, -7300
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-7300);

label_800F5C50:
    ctx->pc = 0x800F5C50u;
    // 800F5C50: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F5C54:
    ctx->pc = 0x800F5C54u;
    // 800F5C54: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_800F5C58:
    ctx->pc = 0x800F5C58u;
    // 800F5C58: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800F5C5C:
    ctx->pc = 0x800F5C5Cu;
    // 800F5C5C: addi    r3, r13, -27476
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27476);

label_800F5C60:
    ctx->pc = 0x800F5C60u;
    // 800F5C60: bl      0x8027A270
    {
            ctx->lr = 0x800F5C64u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_800F5C64:
    ctx->pc = 0x800F5C64u;
    ctx->downcount -= 8;
    // 800F5C64: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5C68:
    ctx->pc = 0x800F5C68u;
    // 800F5C68: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5C6C:
    ctx->pc = 0x800F5C6Cu;
    // 800F5C6C: addi    r4, r4, -7256
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-7256);

label_800F5C70:
    ctx->pc = 0x800F5C70u;
    // 800F5C70: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F5C74:
    ctx->pc = 0x800F5C74u;
    // 800F5C74: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_800F5C78:
    ctx->pc = 0x800F5C78u;
    // 800F5C78: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800F5C7C:
    ctx->pc = 0x800F5C7Cu;
    // 800F5C7C: addi    r3, r13, -27472
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27472);

label_800F5C80:
    ctx->pc = 0x800F5C80u;
    // 800F5C80: bl      0x8027A270
    {
            ctx->lr = 0x800F5C84u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_800F5C84:
    ctx->pc = 0x800F5C84u;
    ctx->downcount -= 8;
    // 800F5C84: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F5C88:
    ctx->pc = 0x800F5C88u;
    // 800F5C88: addi    r3, r13, -27468
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27468);

label_800F5C8C:
    ctx->pc = 0x800F5C8Cu;
    // 800F5C8C: addi    r4, r4, -7220
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-7220);

label_800F5C90:
    ctx->pc = 0x800F5C90u;
    // 800F5C90: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800F5C94:
    ctx->pc = 0x800F5C94u;
    // 800F5C94: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800F5C98:
    ctx->pc = 0x800F5C98u;
    // 800F5C98: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_800F5C9C:
    ctx->pc = 0x800F5C9Cu;
    // 800F5C9C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800F5CA0:
    ctx->pc = 0x800F5CA0u;
    // 800F5CA0: bl      0x8027A270
    {
            ctx->lr = 0x800F5CA4u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_800F5CA4:
    ctx->pc = 0x800F5CA4u;
    ctx->downcount -= 5;
    // 800F5CA4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5CA8:
    ctx->pc = 0x800F5CA8u;
    // 800F5CA8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5CAC:
    ctx->pc = 0x800F5CACu;
    // 800F5CAC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5CB0:
    ctx->pc = 0x800F5CB0u;
    // 800F5CB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5CB4:
    ctx->pc = 0x800F5CB4u;
    ctx->downcount -= 1;
    // 800F5CB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5CB8:
    ctx->pc = 0x800F5CB8u;
    ctx->downcount -= 7;
    // 800F5CB8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5CBC:
    ctx->pc = 0x800F5CBCu;
    // 800F5CBC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5CC0:
    ctx->pc = 0x800F5CC0u;
    // 800F5CC0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5CC4:
    ctx->pc = 0x800F5CC4u;
    // 800F5CC4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800F5CC8:
    ctx->pc = 0x800F5CC8u;
    // 800F5CC8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800F5CCC:
    ctx->pc = 0x800F5CCCu;
    // 800F5CCC: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_800F5CD0:
    ctx->pc = 0x800F5CD0u;
    // 800F5CD0: bl      0x800F5B40
    {
            ctx->lr = 0x800F5CD4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F5B40u;
                return;
            }
            goto label_800F5B40;
    }

label_800F5CD4:
    ctx->pc = 0x800F5CD4u;
    ctx->downcount -= 5;
    // 800F5CD4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5CD8:
    ctx->pc = 0x800F5CD8u;
    // 800F5CD8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5CDC:
    ctx->pc = 0x800F5CDCu;
    // 800F5CDC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5CE0:
    ctx->pc = 0x800F5CE0u;
    // 800F5CE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5CE4:
    ctx->pc = 0x800F5CE4u;
    ctx->downcount -= 17;
    // 800F5CE4: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5CE8:
    ctx->pc = 0x800F5CE8u;
    // 800F5CE8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5CEC:
    ctx->pc = 0x800F5CECu;
    // 800F5CEC: stmw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5CF0:
    ctx->pc = 0x800F5CF0u;
    // 800F5CF0: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5CF4:
    ctx->pc = 0x800F5CF4u;
    // 800F5CF4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5CF8:
    ctx->pc = 0x800F5CF8u;
    // 800F5CF8: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800F5CFC:
    ctx->pc = 0x800F5CFCu;
    // 800F5CFC: bl      0x800E65AC
    {
            ctx->lr = 0x800F5D00u;
            ctx->pc = 0x800E65ACu;
            return;
    }

label_800F5D00:
    ctx->pc = 0x800F5D00u;
    ctx->downcount -= 3;
    // 800F5D00: lwz     r0, 488(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(488);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5D04:
    ctx->pc = 0x800F5D04u;
    // 800F5D04: cmpwi   r0, 0
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

label_800F5D08:
    ctx->pc = 0x800F5D08u;
    // 800F5D08: bc    12, 2, 0x800F5DCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F5DCC;
        }
    }

label_800F5D0C:
    ctx->pc = 0x800F5D0Cu;
    ctx->downcount -= 3;
    // 800F5D0C: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5D10:
    ctx->pc = 0x800F5D10u;
    // 800F5D10: cmpwi   r0, 2
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

label_800F5D14:
    ctx->pc = 0x800F5D14u;
    // 800F5D14: bc    4, 2, 0x800F5DCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F5DCC;
        }
    }

label_800F5D18:
    ctx->pc = 0x800F5D18u;
    ctx->downcount -= 8;
    // 800F5D18: lwz     r31, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800F5D1C:
    ctx->pc = 0x800F5D1Cu;
    // 800F5D1C: lwz     r9, 108(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F5D20:
    ctx->pc = 0x800F5D20u;
    // 800F5D20: lha     r3, 40(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(40);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800F5D24:
    ctx->pc = 0x800F5D24u;
    // 800F5D24: lwz     r0, 44(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5D28:
    ctx->pc = 0x800F5D28u;
    // 800F5D28: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800F5D2C:
    ctx->pc = 0x800F5D2Cu;
    // 800F5D2C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5D30:
    ctx->pc = 0x800F5D30u;
    // 800F5D30: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800F5D34u;
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5D34:
    ctx->pc = 0x800F5D34u;
    ctx->downcount -= 2;
    // 800F5D34: cmpwi   r3, 0
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

label_800F5D38:
    ctx->pc = 0x800F5D38u;
    // 800F5D38: bc    12, 2, 0x800F5DCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F5DCC;
        }
    }

label_800F5D3C:
    ctx->pc = 0x800F5D3Cu;
    ctx->downcount -= 7;
    // 800F5D3C: lwz     r9, 108(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F5D40:
    ctx->pc = 0x800F5D40u;
    // 800F5D40: lha     r3, 264(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(264);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800F5D44:
    ctx->pc = 0x800F5D44u;
    // 800F5D44: lwz     r0, 268(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5D48:
    ctx->pc = 0x800F5D48u;
    // 800F5D48: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800F5D4C:
    ctx->pc = 0x800F5D4Cu;
    // 800F5D4C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5D50:
    ctx->pc = 0x800F5D50u;
    // 800F5D50: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800F5D54u;
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5D54:
    ctx->pc = 0x800F5D54u;
    ctx->downcount -= 2;
    // 800F5D54: cmpwi   r3, 5
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

label_800F5D58:
    ctx->pc = 0x800F5D58u;
    // 800F5D58: bc    4, 2, 0x800F5DCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F5DCC;
        }
    }

label_800F5D5C:
    ctx->pc = 0x800F5D5Cu;
    ctx->downcount -= 3;
    // 800F5D5C: lwz     r31, 304(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(304);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800F5D60:
    ctx->pc = 0x800F5D60u;
    // 800F5D60: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F5D64:
    ctx->pc = 0x800F5D64u;
    // 800F5D64: bl      0x801A48A0
    {
            ctx->lr = 0x800F5D68u;
            ctx->pc = 0x801A48A0u;
            return;
    }

label_800F5D68:
    ctx->pc = 0x800F5D68u;
    ctx->downcount -= 2;
    // 800F5D68: cmpwi   r3, 1
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

label_800F5D6C:
    ctx->pc = 0x800F5D6Cu;
    // 800F5D6C: bc    4, 2, 0x800F5DCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F5DCC;
        }
    }

label_800F5D70:
    ctx->pc = 0x800F5D70u;
    ctx->downcount -= 21;
    // 800F5D70: lwz     r10, 108(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(108);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800F5D74:
    ctx->pc = 0x800F5D74u;
    // 800F5D74: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F5D78:
    ctx->pc = 0x800F5D78u;
    // 800F5D78: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_800F5D7C:
    ctx->pc = 0x800F5D7Cu;
    // 800F5D7C: lfs     f0, 524(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F5D7Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(524);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F5D80:
    ctx->pc = 0x800F5D80u;
    // 800F5D80: lha     r3, 160(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(160);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800F5D84:
    ctx->pc = 0x800F5D84u;
    // 800F5D84: li      r0, 12
    ctx->gpr[0] = (u32)(s32)(12);

label_800F5D88:
    ctx->pc = 0x800F5D88u;
    // 800F5D88: lfs     f12, -7160(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F5D88u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-7160);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F5D8C:
    ctx->pc = 0x800F5D8Cu;
    // 800F5D8C: lfs     f13, -7156(r11)
    if (!ppc_fp_available_inline(ctx, 0x800F5D8Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-7156);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F5D90:
    ctx->pc = 0x800F5D90u;
    // 800F5D90: addi    r9, r1, 8
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(8);

label_800F5D94:
    ctx->pc = 0x800F5D94u;
    // 800F5D94: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5D98:
    ctx->pc = 0x800F5D98u;
    // 800F5D98: or   r4, r9, r9
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800F5D9C:
    ctx->pc = 0x800F5D9Cu;
    // 800F5D9C: stfs     f12, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F5D9Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F5DA0:
    ctx->pc = 0x800F5DA0u;
    // 800F5DA0: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800F5DA4:
    ctx->pc = 0x800F5DA4u;
    // 800F5DA4: stfs     f13, 16(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F5DA4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F5DA8:
    ctx->pc = 0x800F5DA8u;
    // 800F5DA8: stfs     f0, 20(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F5DA8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F5DAC:
    ctx->pc = 0x800F5DACu;
    // 800F5DAC: stw     r30, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800F5DB0:
    ctx->pc = 0x800F5DB0u;
    // 800F5DB0: stfs     f13, 12(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F5DB0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F5DB4:
    ctx->pc = 0x800F5DB4u;
    // 800F5DB4: lwz     r0, 164(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(164);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5DB8:
    ctx->pc = 0x800F5DB8u;
    // 800F5DB8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5DBC:
    ctx->pc = 0x800F5DBCu;
    // 800F5DBC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800F5DC0u;
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5DC0:
    ctx->pc = 0x800F5DC0u;
    ctx->downcount -= 3;
    // 800F5DC0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F5DC4:
    ctx->pc = 0x800F5DC4u;
    // 800F5DC4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800F5DC8:
    ctx->pc = 0x800F5DC8u;
    // 800F5DC8: bl      0x801A1ECC
    {
            ctx->lr = 0x800F5DCCu;
            ctx->pc = 0x801A1ECCu;
            return;
    }

label_800F5DCC:
    ctx->pc = 0x800F5DCCu;
    ctx->downcount -= 16;
    // 800F5DCC: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5DD0:
    ctx->pc = 0x800F5DD0u;
    // 800F5DD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5DD4:
    ctx->pc = 0x800F5DD4u;
    // 800F5DD4: lmw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F5DD8:
    ctx->pc = 0x800F5DD8u;
    // 800F5DD8: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800F5DDC:
    ctx->pc = 0x800F5DDCu;
    // 800F5DDC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5DE0:
    ctx->pc = 0x800F5DE0u;
    ctx->downcount -= 16;
    // 800F5DE0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5DE4:
    ctx->pc = 0x800F5DE4u;
    // 800F5DE4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5DE8:
    ctx->pc = 0x800F5DE8u;
    // 800F5DE8: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5DEC:
    ctx->pc = 0x800F5DECu;
    // 800F5DEC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5DF0:
    ctx->pc = 0x800F5DF0u;
    // 800F5DF0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5DF4:
    ctx->pc = 0x800F5DF4u;
    // 800F5DF4: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800F5DF8:
    ctx->pc = 0x800F5DF8u;
    ctx->downcount -= 11;
    // 800F5DF8: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5DFC:
    ctx->pc = 0x800F5DFCu;
    // 800F5DFC: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F5E00:
    // 800F5E00: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_800F5E04:
    ctx->pc = 0x800F5E04u;
    // 800F5E04: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F5E08:
    // 800F5E08: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_800F5E0C:
    // 800F5E0C: cmplw   r10, r11
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

label_800F5E10:
    // 800F5E10: bc    12, 0, 0x800F5E38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F5E38;
        }
    }

label_800F5E14:
    ctx->downcount -= 3;
    // 800F5E14: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F5E18:
    ctx->pc = 0x800F5E18u;
    // 800F5E18: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5E1C:
    // 800F5E1C: b       0x800F5F10
    {
            goto label_800F5F10;
    }

label_800F5E20:
    ctx->pc = 0x800F5E20u;
    ctx->downcount -= 6;
    // 800F5E20: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F5E24:
    // 800F5E24: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F5E28:
    ctx->pc = 0x800F5E28u;
    // 800F5E28: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5E2C:
    ctx->pc = 0x800F5E2Cu;
    // 800F5E2C: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5E30:
    ctx->pc = 0x800F5E30u;
    // 800F5E30: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800F5E34:
    // 800F5E34: b       0x800F5DF8
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F5DF8u;
                return;
            }
            goto label_800F5DF8;
    }

label_800F5E38:
    ctx->downcount -= 2;
    // 800F5E38: cmplw   r10, r30
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

label_800F5E3C:
    // 800F5E3C: bc    12, 0, 0x800F5E5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F5E5C;
        }
    }

label_800F5E40:
    ctx->downcount -= 50;
    // 800F5E40: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_800F5E44:
    ctx->pc = 0x800F5E44u;
    // 800F5E44: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5E48:
    // 800F5E48: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_800F5E4C:
    ctx->pc = 0x800F5E4Cu;
    // 800F5E4C: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F5E50:
    // 800F5E50: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F5E54:
    ctx->pc = 0x800F5E54u;
    // 800F5E54: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5E58:
    // 800F5E58: b       0x800F5F10
    {
            goto label_800F5F10;
    }

label_800F5E5C:
    ctx->pc = 0x800F5E5Cu;
    ctx->downcount -= 8;
    // 800F5E5C: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F5E60:
    // 800F5E60: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F5E64:
    // 800F5E64: cmpwi   r10, 0
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

label_800F5E68:
    // 800F5E68: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_800F5E6C:
    // 800F5E6C: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_800F5E70:
    // 800F5E70: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_800F5E74:
    // 800F5E74: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_800F5E78:
    // 800F5E78: bc    12, 2, 0x800F5E98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F5E98;
        }
    }

label_800F5E7C:
    ctx->downcount -= 7;
    // 800F5E7C: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_800F5E80:
    // 800F5E80: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_800F5E84:
    // 800F5E84: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F5E88:
    // 800F5E88: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_800F5E8C:
    ctx->pc = 0x800F5E8Cu;
    // 800F5E8C: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F5E90:
    ctx->pc = 0x800F5E90u;
    // 800F5E90: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F5E94:
    ctx->pc = 0x800F5E94u;
    // 800F5E94: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800F5E98:
    ctx->downcount -= 2;
    // 800F5E98: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F5E9C:
    // 800F5E9C: bl      0x80281C60
    {
            ctx->lr = 0x800F5EA0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F5EA0:
    ctx->downcount -= 3;
    // 800F5EA0: cmpwi   r3, 0
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

label_800F5EA4:
    ctx->pc = 0x800F5EA4u;
    // 800F5EA4: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800F5EA8:
    // 800F5EA8: bc    4, 2, 0x800F5EF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F5EF4;
        }
    }

label_800F5EAC:
    ctx->downcount -= 3;
    // 800F5EAC: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F5EB0:
    // 800F5EB0: cmplwi  r11, 0x0080
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

label_800F5EB4:
    // 800F5EB4: bc    12, 1, 0x800F5EE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F5EE0;
        }
    }

label_800F5EB8:
    ctx->downcount -= 2;
    // 800F5EB8: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_800F5EBC:
    // 800F5EBC: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_800F5EC0:
    ctx->downcount -= 5;
    // 800F5EC0: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_800F5EC4:
    // 800F5EC4: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F5EC8:
    ctx->pc = 0x800F5EC8u;
    // 800F5EC8: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800F5ECC:
    // 800F5ECC: cmpwi   r10, 0
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

label_800F5ED0:
    // 800F5ED0: bc    4, 2, 0x800F5E20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F5E20u;
                return;
            }
            goto label_800F5E20;
        }
    }

label_800F5ED4:
    ctx->downcount -= 3;
    // 800F5ED4: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_800F5ED8:
    // 800F5ED8: cmplwi  r11, 0x0080
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

label_800F5EDC:
    // 800F5EDC: bc    4, 1, 0x800F5EC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F5EC0u;
                return;
            }
            goto label_800F5EC0;
        }
    }

label_800F5EE0:
    ctx->downcount -= 4;
    // 800F5EE0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F5EE4:
    // 800F5EE4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F5EE8:
    ctx->pc = 0x800F5EE8u;
    // 800F5EE8: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5EEC:
    // 800F5EEC: bl      0x80281C60
    {
            ctx->lr = 0x800F5EF0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F5EF0:
    ctx->pc = 0x800F5EF0u;
    ctx->downcount -= 1;
    // 800F5EF0: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800F5EF4:
    ctx->pc = 0x800F5EF4u;
    ctx->downcount -= 7;
    // 800F5EF4: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5EF8:
    ctx->pc = 0x800F5EF8u;
    // 800F5EF8: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F5EFC:
    // 800F5EFC: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F5F00:
    // 800F5F00: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800F5F04:
    ctx->pc = 0x800F5F04u;
    // 800F5F04: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5F08:
    ctx->pc = 0x800F5F08u;
    // 800F5F08: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5F0C:
    // 800F5F0C: b       0x800F5DF8
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F5DF8u;
                return;
            }
            goto label_800F5DF8;
    }

label_800F5F10:
    ctx->pc = 0x800F5F10u;
    ctx->downcount -= 16;
    // 800F5F10: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5F14:
    ctx->pc = 0x800F5F14u;
    // 800F5F14: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5F18:
    ctx->pc = 0x800F5F18u;
    // 800F5F18: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F5F1C:
    ctx->pc = 0x800F5F1Cu;
    // 800F5F1C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F5F20:
    ctx->pc = 0x800F5F20u;
    // 800F5F20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5F24:
    ctx->pc = 0x800F5F24u;
    ctx->downcount -= 21;
    // 800F5F24: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5F28:
    ctx->pc = 0x800F5F28u;
    // 800F5F28: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5F2C:
    ctx->pc = 0x800F5F2Cu;
    // 800F5F2C: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F5F30:
    ctx->pc = 0x800F5F30u;
    // 800F5F30: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5F34:
    ctx->pc = 0x800F5F34u;
    // 800F5F34: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_800F5F38:
    ctx->pc = 0x800F5F38u;
    // 800F5F38: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_800F5F3C:
    ctx->pc = 0x800F5F3Cu;
    // 800F5F3C: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_800F5F40:
    ctx->pc = 0x800F5F40u;
    // 800F5F40: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F5F44:
    ctx->pc = 0x800F5F44u;
    // 800F5F44: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800F5F48:
    ctx->pc = 0x800F5F48u;
    // 800F5F48: cmpwi   r30, 0
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

label_800F5F4C:
    ctx->pc = 0x800F5F4Cu;
    // 800F5F4C: bc    12, 2, 0x800F5F5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F5F5C;
        }
    }

label_800F5F50:
    ctx->pc = 0x800F5F50u;
    ctx->downcount -= 3;
    // 800F5F50: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5F54:
    ctx->pc = 0x800F5F54u;
    // 800F5F54: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5F58:
    ctx->pc = 0x800F5F58u;
    // 800F5F58: b       0x800F5FDC
    {
            goto label_800F5FDC;
    }

label_800F5F5C:
    ctx->pc = 0x800F5F5Cu;
    ctx->downcount -= 7;
    // 800F5F5C: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_800F5F60:
    ctx->pc = 0x800F5F60u;
    // 800F5F60: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_800F5F64:
    ctx->pc = 0x800F5F64u;
    // 800F5F64: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_800F5F68:
    ctx->pc = 0x800F5F68u;
    // 800F5F68: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F5F6C:
    ctx->pc = 0x800F5F6Cu;
    // 800F5F6C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F5F70:
    ctx->pc = 0x800F5F70u;
    // 800F5F70: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_800F5F74:
    ctx->pc = 0x800F5F74u;
    // 800F5F74: bl      0x80003EE0
    {
            ctx->lr = 0x800F5F78u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_800F5F78:
    ctx->pc = 0x800F5F78u;
    ctx->downcount -= 3;
    // 800F5F78: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F5F7C:
    ctx->pc = 0x800F5F7Cu;
    // 800F5F7C: cmpwi   r9, 1
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

label_800F5F80:
    ctx->pc = 0x800F5F80u;
    // 800F5F80: bc    12, 2, 0x800F5FD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F5FD8;
        }
    }

label_800F5F84:
    ctx->pc = 0x800F5F84u;
    ctx->downcount -= 9;
    // 800F5F84: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_800F5F88:
    ctx->pc = 0x800F5F88u;
    // 800F5F88: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800F5F8C:
    ctx->pc = 0x800F5F8Cu;
    // 800F5F8C: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F5F90:
    ctx->pc = 0x800F5F90u;
    // 800F5F90: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800F5F94:
    ctx->pc = 0x800F5F94u;
    // 800F5F94: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F5F98:
    ctx->pc = 0x800F5F98u;
    // 800F5F98: cmpwi   r9, 2
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

label_800F5F9C:
    ctx->pc = 0x800F5F9Cu;
    // 800F5F9C: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_800F5FA0:
    ctx->pc = 0x800F5FA0u;
    // 800F5FA0: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800F5FA4:
    ctx->pc = 0x800F5FA4u;
    // 800F5FA4: bc    4, 2, 0x800F5FB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F5FB0;
        }
    }

label_800F5FA8:
    ctx->pc = 0x800F5FA8u;
    ctx->downcount -= 2;
    // 800F5FA8: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800F5FAC:
    ctx->pc = 0x800F5FACu;
    // 800F5FAC: b       0x800F5FD8
    {
            goto label_800F5FD8;
    }

label_800F5FB0:
    loop_800F5FB0(ctx);
    if (ctx->pc == 0x800F5FD0u) goto label_800F5FD0;
    return;
label_800F5FB4:
    // 800F5FB4: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_800F5FB8:
    // 800F5FB8: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800F5FBC:
    ctx->pc = 0x800F5FBCu;
    // 800F5FBC: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F5FC0:
    // 800F5FC0: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800F5FC4:
    // 800F5FC4: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_800F5FC8:
    // 800F5FC8: cmpw    r9, r8
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

label_800F5FCC:
    // 800F5FCC: bc    4, 2, 0x800F5FB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F5FB0u;
                return;
            }
            goto label_800F5FB0;
        }
    }

label_800F5FD0:
    ctx->pc = 0x800F5FD0u;
    ctx->downcount -= 2;
    // 800F5FD0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F5FD4:
    ctx->pc = 0x800F5FD4u;
    // 800F5FD4: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F5FD8:
    ctx->pc = 0x800F5FD8u;
    ctx->downcount -= 1;
    // 800F5FD8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F5FDC:
    ctx->pc = 0x800F5FDCu;
    ctx->downcount -= 17;
    // 800F5FDC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F5FE0:
    ctx->pc = 0x800F5FE0u;
    // 800F5FE0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F5FE4:
    ctx->pc = 0x800F5FE4u;
    // 800F5FE4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F5FE8:
    ctx->pc = 0x800F5FE8u;
    // 800F5FE8: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F5FEC:
    ctx->pc = 0x800F5FECu;
    // 800F5FEC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_800F5FF0:
    ctx->pc = 0x800F5FF0u;
    // 800F5FF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F5FF4:
    ctx->pc = 0x800F5FF4u;
    ctx->downcount -= 7;
    // 800F5FF4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F5FF8:
    ctx->pc = 0x800F5FF8u;
    // 800F5FF8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F5FFC:
    ctx->pc = 0x800F5FFCu;
    // 800F5FFC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6000:
    ctx->pc = 0x800F6000u;
    // 800F6000: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F6004:
    ctx->pc = 0x800F6004u;
    // 800F6004: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_800F6008:
    ctx->pc = 0x800F6008u;
    // 800F6008: cmpw    r4, r0
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

label_800F600C:
    ctx->pc = 0x800F600Cu;
    // 800F600C: bc    4, 2, 0x800F6108
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F6108;
        }
    }

label_800F6010:
    ctx->pc = 0x800F6010u;
    ctx->downcount -= 2;
    // 800F6010: cmpwi   r3, 0
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

label_800F6014:
    ctx->pc = 0x800F6014u;
    // 800F6014: bc    12, 2, 0x800F6108
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6108;
        }
    }

label_800F6018:
    ctx->pc = 0x800F6018u;
    ctx->downcount -= 5;
    // 800F6018: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_800F601C:
    ctx->pc = 0x800F601Cu;
    // 800F601C: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_800F6020:
    ctx->pc = 0x800F6020u;
    // 800F6020: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_800F6024:
    ctx->pc = 0x800F6024u;
    // 800F6024: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_800F6028:
    ctx->pc = 0x800F6028u;
    // 800F6028: bl      0x80252AF0
    {
            ctx->lr = 0x800F602Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F602C:
    ctx->pc = 0x800F602Cu;
    ctx->downcount -= 5;
    // 800F602C: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_800F6030:
    ctx->pc = 0x800F6030u;
    // 800F6030: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_800F6034:
    ctx->pc = 0x800F6034u;
    // 800F6034: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_800F6038:
    ctx->pc = 0x800F6038u;
    // 800F6038: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F603C:
    ctx->pc = 0x800F603Cu;
    // 800F603C: bl      0x80252AF0
    {
            ctx->lr = 0x800F6040u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6040:
    ctx->pc = 0x800F6040u;
    ctx->downcount -= 5;
    // 800F6040: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_800F6044:
    ctx->pc = 0x800F6044u;
    // 800F6044: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_800F6048:
    ctx->pc = 0x800F6048u;
    // 800F6048: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_800F604C:
    ctx->pc = 0x800F604Cu;
    // 800F604C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F6050:
    ctx->pc = 0x800F6050u;
    // 800F6050: bl      0x80252AF0
    {
            ctx->lr = 0x800F6054u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6054:
    ctx->pc = 0x800F6054u;
    ctx->downcount -= 5;
    // 800F6054: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_800F6058:
    ctx->pc = 0x800F6058u;
    // 800F6058: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_800F605C:
    ctx->pc = 0x800F605Cu;
    // 800F605C: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_800F6060:
    ctx->pc = 0x800F6060u;
    // 800F6060: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F6064:
    ctx->pc = 0x800F6064u;
    // 800F6064: bl      0x80252AF0
    {
            ctx->lr = 0x800F6068u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6068:
    ctx->pc = 0x800F6068u;
    ctx->downcount -= 5;
    // 800F6068: lis     r3, 25197
    ctx->gpr[3] = ((u32)(s32)(25197) << 16);

label_800F606C:
    ctx->pc = 0x800F606Cu;
    // 800F606C: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_800F6070:
    ctx->pc = 0x800F6070u;
    // 800F6070: ori     r3, r3, 0x7368
    ctx->gpr[3] = ctx->gpr[3] | 0x7368u;

label_800F6074:
    ctx->pc = 0x800F6074u;
    // 800F6074: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F6078:
    ctx->pc = 0x800F6078u;
    // 800F6078: bl      0x80252AF0
    {
            ctx->lr = 0x800F607Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F607C:
    ctx->pc = 0x800F607Cu;
    ctx->downcount -= 5;
    // 800F607C: lis     r3, 25199
    ctx->gpr[3] = ((u32)(s32)(25199) << 16);

label_800F6080:
    ctx->pc = 0x800F6080u;
    // 800F6080: li      r4, 63
    ctx->gpr[4] = (u32)(s32)(63);

label_800F6084:
    ctx->pc = 0x800F6084u;
    // 800F6084: ori     r3, r3, 0x6479
    ctx->gpr[3] = ctx->gpr[3] | 0x6479u;

label_800F6088:
    ctx->pc = 0x800F6088u;
    // 800F6088: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F608C:
    ctx->pc = 0x800F608Cu;
    // 800F608C: bl      0x80252AF0
    {
            ctx->lr = 0x800F6090u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6090:
    ctx->pc = 0x800F6090u;
    ctx->downcount -= 5;
    // 800F6090: lis     r3, 25185
    ctx->gpr[3] = ((u32)(s32)(25185) << 16);

label_800F6094:
    ctx->pc = 0x800F6094u;
    // 800F6094: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_800F6098:
    ctx->pc = 0x800F6098u;
    // 800F6098: ori     r3, r3, 0x6E6D
    ctx->gpr[3] = ctx->gpr[3] | 0x6E6Du;

label_800F609C:
    ctx->pc = 0x800F609Cu;
    // 800F609C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F60A0:
    ctx->pc = 0x800F60A0u;
    // 800F60A0: bl      0x80252AF0
    {
            ctx->lr = 0x800F60A4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F60A4:
    ctx->pc = 0x800F60A4u;
    ctx->downcount -= 5;
    // 800F60A4: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_800F60A8:
    ctx->pc = 0x800F60A8u;
    // 800F60A8: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_800F60AC:
    ctx->pc = 0x800F60ACu;
    // 800F60AC: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_800F60B0:
    ctx->pc = 0x800F60B0u;
    // 800F60B0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F60B4:
    ctx->pc = 0x800F60B4u;
    // 800F60B4: bl      0x80252AF0
    {
            ctx->lr = 0x800F60B8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F60B8:
    ctx->pc = 0x800F60B8u;
    ctx->downcount -= 5;
    // 800F60B8: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_800F60BC:
    ctx->pc = 0x800F60BCu;
    // 800F60BC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800F60C0:
    ctx->pc = 0x800F60C0u;
    // 800F60C0: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_800F60C4:
    ctx->pc = 0x800F60C4u;
    // 800F60C4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F60C8:
    ctx->pc = 0x800F60C8u;
    // 800F60C8: bl      0x80252AF0
    {
            ctx->lr = 0x800F60CCu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F60CC:
    ctx->pc = 0x800F60CCu;
    ctx->downcount -= 5;
    // 800F60CC: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_800F60D0:
    ctx->pc = 0x800F60D0u;
    // 800F60D0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_800F60D4:
    ctx->pc = 0x800F60D4u;
    // 800F60D4: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_800F60D8:
    ctx->pc = 0x800F60D8u;
    // 800F60D8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F60DC:
    ctx->pc = 0x800F60DCu;
    // 800F60DC: bl      0x80252AF0
    {
            ctx->lr = 0x800F60E0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F60E0:
    ctx->pc = 0x800F60E0u;
    ctx->downcount -= 5;
    // 800F60E0: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_800F60E4:
    ctx->pc = 0x800F60E4u;
    // 800F60E4: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_800F60E8:
    ctx->pc = 0x800F60E8u;
    // 800F60E8: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_800F60EC:
    ctx->pc = 0x800F60ECu;
    // 800F60EC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F60F0:
    ctx->pc = 0x800F60F0u;
    // 800F60F0: bl      0x80252AF0
    {
            ctx->lr = 0x800F60F4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F60F4:
    ctx->pc = 0x800F60F4u;
    ctx->downcount -= 5;
    // 800F60F4: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_800F60F8:
    ctx->pc = 0x800F60F8u;
    // 800F60F8: lis     r4, -32753
    ctx->gpr[4] = ((u32)(s32)(-32753) << 16);

label_800F60FC:
    ctx->pc = 0x800F60FCu;
    // 800F60FC: addi    r3, r3, -6808
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-6808);

label_800F6100:
    ctx->pc = 0x800F6100u;
    // 800F6100: addi    r4, r4, 24856
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(24856);

label_800F6104:
    ctx->pc = 0x800F6104u;
    // 800F6104: bl      0x801FC784
    {
            ctx->lr = 0x800F6108u;
            ctx->pc = 0x801FC784u;
            return;
    }

label_800F6108:
    ctx->pc = 0x800F6108u;
    ctx->downcount -= 5;
    // 800F6108: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F610C:
    ctx->pc = 0x800F610Cu;
    // 800F610C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6110:
    ctx->pc = 0x800F6110u;
    // 800F6110: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F6114:
    ctx->pc = 0x800F6114u;
    // 800F6114: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6118:
    ctx->pc = 0x800F6118u;
    ctx->downcount -= 17;
    // 800F6118: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F611C:
    ctx->pc = 0x800F611Cu;
    // 800F611C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6120:
    ctx->pc = 0x800F6120u;
    // 800F6120: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F6124:
    ctx->pc = 0x800F6124u;
    // 800F6124: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6128:
    ctx->pc = 0x800F6128u;
    // 800F6128: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F612C:
    ctx->pc = 0x800F612Cu;
    // 800F612C: li      r3, 1608
    ctx->gpr[3] = (u32)(s32)(1608);

label_800F6130:
    ctx->pc = 0x800F6130u;
    // 800F6130: bl      0x80281C60
    {
            ctx->lr = 0x800F6134u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F6134:
    ctx->pc = 0x800F6134u;
    ctx->downcount -= 2;
    // 800F6134: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6138:
    ctx->pc = 0x800F6138u;
    // 800F6138: bl      0x800F6150
    {
            ctx->lr = 0x800F613Cu;
            goto label_800F6150;
    }

label_800F613C:
    ctx->pc = 0x800F613Cu;
    ctx->downcount -= 16;
    // 800F613C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6140:
    ctx->pc = 0x800F6140u;
    // 800F6140: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6144:
    ctx->pc = 0x800F6144u;
    // 800F6144: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F6148:
    ctx->pc = 0x800F6148u;
    // 800F6148: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F614C:
    ctx->pc = 0x800F614Cu;
    // 800F614C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6150:
    ctx->pc = 0x800F6150u;
    ctx->downcount -= 16;
    // 800F6150: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6154:
    ctx->pc = 0x800F6154u;
    // 800F6154: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6158:
    ctx->pc = 0x800F6158u;
    // 800F6158: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F615C:
    ctx->pc = 0x800F615Cu;
    // 800F615C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6160:
    ctx->pc = 0x800F6160u;
    // 800F6160: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6164:
    ctx->pc = 0x800F6164u;
    // 800F6164: bl      0x8008FD98
    {
            ctx->lr = 0x800F6168u;
            ctx->pc = 0x8008FD98u;
            return;
    }

label_800F6168:
    ctx->pc = 0x800F6168u;
    ctx->downcount -= 20;
    // 800F6168: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F616C:
    ctx->pc = 0x800F616Cu;
    // 800F616C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6170:
    ctx->pc = 0x800F6170u;
    // 800F6170: addi    r9, r9, -7104
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-7104);

label_800F6174:
    ctx->pc = 0x800F6174u;
    // 800F6174: stw     r9, 108(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6178:
    ctx->pc = 0x800F6178u;
    // 800F6178: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F617C:
    ctx->pc = 0x800F617Cu;
    // 800F617C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6180:
    ctx->pc = 0x800F6180u;
    // 800F6180: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F6184:
    ctx->pc = 0x800F6184u;
    // 800F6184: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F6188:
    ctx->pc = 0x800F6188u;
    // 800F6188: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F618C:
    ctx->pc = 0x800F618Cu;
    ctx->downcount -= 8;
    // 800F618C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6190:
    ctx->pc = 0x800F6190u;
    // 800F6190: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6194:
    ctx->pc = 0x800F6194u;
    // 800F6194: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6198:
    ctx->pc = 0x800F6198u;
    // 800F6198: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F619C:
    ctx->pc = 0x800F619Cu;
    // 800F619C: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F61A0:
    ctx->pc = 0x800F61A0u;
    // 800F61A0: addi    r9, r9, -7104
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-7104);

label_800F61A4:
    ctx->pc = 0x800F61A4u;
    // 800F61A4: stw     r9, 108(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F61A8:
    ctx->pc = 0x800F61A8u;
    // 800F61A8: bl      0x8008FEA0
    {
            ctx->lr = 0x800F61ACu;
            ctx->pc = 0x8008FEA0u;
            return;
    }

label_800F61AC:
    ctx->pc = 0x800F61ACu;
    ctx->downcount -= 5;
    // 800F61AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F61B0:
    ctx->pc = 0x800F61B0u;
    // 800F61B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F61B4:
    ctx->pc = 0x800F61B4u;
    // 800F61B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F61B8:
    ctx->pc = 0x800F61B8u;
    // 800F61B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F61BC:
    ctx->pc = 0x800F61BCu;
    ctx->downcount -= 7;
    // 800F61BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F61C0:
    ctx->pc = 0x800F61C0u;
    // 800F61C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F61C4:
    ctx->pc = 0x800F61C4u;
    // 800F61C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F61C8:
    ctx->pc = 0x800F61C8u;
    // 800F61C8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800F61CC:
    ctx->pc = 0x800F61CCu;
    // 800F61CC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800F61D0:
    ctx->pc = 0x800F61D0u;
    // 800F61D0: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_800F61D4:
    ctx->pc = 0x800F61D4u;
    // 800F61D4: bl      0x800F5FF4
    {
            ctx->lr = 0x800F61D8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F5FF4u;
                return;
            }
            goto label_800F5FF4;
    }

label_800F61D8:
    ctx->pc = 0x800F61D8u;
    ctx->downcount -= 5;
    // 800F61D8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F61DC:
    ctx->pc = 0x800F61DCu;
    // 800F61DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F61E0:
    ctx->pc = 0x800F61E0u;
    // 800F61E0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F61E4:
    ctx->pc = 0x800F61E4u;
    // 800F61E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F61E8:
    ctx->pc = 0x800F61E8u;
    ctx->downcount -= 16;
    // 800F61E8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F61EC:
    ctx->pc = 0x800F61ECu;
    // 800F61EC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F61F0:
    ctx->pc = 0x800F61F0u;
    // 800F61F0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F61F4:
    ctx->pc = 0x800F61F4u;
    // 800F61F4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F61F8:
    ctx->pc = 0x800F61F8u;
    // 800F61F8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F61FC:
    ctx->pc = 0x800F61FCu;
    // 800F61FC: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800F6200:
    ctx->pc = 0x800F6200u;
    ctx->downcount -= 11;
    // 800F6200: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6204:
    ctx->pc = 0x800F6204u;
    // 800F6204: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6208:
    // 800F6208: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_800F620C:
    ctx->pc = 0x800F620Cu;
    // 800F620C: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F6210:
    // 800F6210: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_800F6214:
    // 800F6214: cmplw   r10, r11
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

label_800F6218:
    // 800F6218: bc    12, 0, 0x800F6240
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6240;
        }
    }

label_800F621C:
    ctx->downcount -= 3;
    // 800F621C: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F6220:
    ctx->pc = 0x800F6220u;
    // 800F6220: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6224:
    // 800F6224: b       0x800F6318
    {
            goto label_800F6318;
    }

label_800F6228:
    ctx->pc = 0x800F6228u;
    ctx->downcount -= 6;
    // 800F6228: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F622C:
    // 800F622C: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F6230:
    ctx->pc = 0x800F6230u;
    // 800F6230: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6234:
    ctx->pc = 0x800F6234u;
    // 800F6234: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6238:
    ctx->pc = 0x800F6238u;
    // 800F6238: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800F623C:
    // 800F623C: b       0x800F6200
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F6200u;
                return;
            }
            goto label_800F6200;
    }

label_800F6240:
    ctx->downcount -= 2;
    // 800F6240: cmplw   r10, r30
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

label_800F6244:
    // 800F6244: bc    12, 0, 0x800F6264
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6264;
        }
    }

label_800F6248:
    ctx->downcount -= 50;
    // 800F6248: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_800F624C:
    ctx->pc = 0x800F624Cu;
    // 800F624C: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6250:
    // 800F6250: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_800F6254:
    ctx->pc = 0x800F6254u;
    // 800F6254: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F6258:
    // 800F6258: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F625C:
    ctx->pc = 0x800F625Cu;
    // 800F625C: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6260:
    // 800F6260: b       0x800F6318
    {
            goto label_800F6318;
    }

label_800F6264:
    ctx->pc = 0x800F6264u;
    ctx->downcount -= 8;
    // 800F6264: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6268:
    // 800F6268: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F626C:
    // 800F626C: cmpwi   r10, 0
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

label_800F6270:
    // 800F6270: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_800F6274:
    // 800F6274: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_800F6278:
    // 800F6278: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_800F627C:
    // 800F627C: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_800F6280:
    // 800F6280: bc    12, 2, 0x800F62A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F62A0;
        }
    }

label_800F6284:
    ctx->downcount -= 7;
    // 800F6284: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_800F6288:
    // 800F6288: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_800F628C:
    // 800F628C: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F6290:
    // 800F6290: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_800F6294:
    ctx->pc = 0x800F6294u;
    // 800F6294: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F6298:
    ctx->pc = 0x800F6298u;
    // 800F6298: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F629C:
    ctx->pc = 0x800F629Cu;
    // 800F629C: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800F62A0:
    ctx->downcount -= 2;
    // 800F62A0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F62A4:
    // 800F62A4: bl      0x80281C60
    {
            ctx->lr = 0x800F62A8u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F62A8:
    ctx->downcount -= 3;
    // 800F62A8: cmpwi   r3, 0
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

label_800F62AC:
    ctx->pc = 0x800F62ACu;
    // 800F62AC: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800F62B0:
    // 800F62B0: bc    4, 2, 0x800F62FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F62FC;
        }
    }

label_800F62B4:
    ctx->downcount -= 3;
    // 800F62B4: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F62B8:
    // 800F62B8: cmplwi  r11, 0x0080
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

label_800F62BC:
    // 800F62BC: bc    12, 1, 0x800F62E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F62E8;
        }
    }

label_800F62C0:
    ctx->downcount -= 2;
    // 800F62C0: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_800F62C4:
    // 800F62C4: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_800F62C8:
    ctx->downcount -= 5;
    // 800F62C8: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_800F62CC:
    // 800F62CC: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F62D0:
    ctx->pc = 0x800F62D0u;
    // 800F62D0: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800F62D4:
    // 800F62D4: cmpwi   r10, 0
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

label_800F62D8:
    // 800F62D8: bc    4, 2, 0x800F6228
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F6228u;
                return;
            }
            goto label_800F6228;
        }
    }

label_800F62DC:
    ctx->downcount -= 3;
    // 800F62DC: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_800F62E0:
    // 800F62E0: cmplwi  r11, 0x0080
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

label_800F62E4:
    // 800F62E4: bc    4, 1, 0x800F62C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F62C8u;
                return;
            }
            goto label_800F62C8;
        }
    }

label_800F62E8:
    ctx->downcount -= 4;
    // 800F62E8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F62EC:
    // 800F62EC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F62F0:
    ctx->pc = 0x800F62F0u;
    // 800F62F0: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F62F4:
    // 800F62F4: bl      0x80281C60
    {
            ctx->lr = 0x800F62F8u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F62F8:
    ctx->pc = 0x800F62F8u;
    ctx->downcount -= 1;
    // 800F62F8: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800F62FC:
    ctx->pc = 0x800F62FCu;
    ctx->downcount -= 7;
    // 800F62FC: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6300:
    ctx->pc = 0x800F6300u;
    // 800F6300: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6304:
    // 800F6304: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F6308:
    // 800F6308: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800F630C:
    ctx->pc = 0x800F630Cu;
    // 800F630C: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6310:
    ctx->pc = 0x800F6310u;
    // 800F6310: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6314:
    // 800F6314: b       0x800F6200
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F6200u;
                return;
            }
            goto label_800F6200;
    }

label_800F6318:
    ctx->pc = 0x800F6318u;
    ctx->downcount -= 16;
    // 800F6318: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F631C:
    ctx->pc = 0x800F631Cu;
    // 800F631C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6320:
    ctx->pc = 0x800F6320u;
    // 800F6320: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F6324:
    ctx->pc = 0x800F6324u;
    // 800F6324: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F6328:
    ctx->pc = 0x800F6328u;
    // 800F6328: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F632C:
    ctx->pc = 0x800F632Cu;
    ctx->downcount -= 21;
    // 800F632C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6330:
    ctx->pc = 0x800F6330u;
    // 800F6330: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6334:
    ctx->pc = 0x800F6334u;
    // 800F6334: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F6338:
    ctx->pc = 0x800F6338u;
    // 800F6338: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F633C:
    ctx->pc = 0x800F633Cu;
    // 800F633C: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_800F6340:
    ctx->pc = 0x800F6340u;
    // 800F6340: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_800F6344:
    ctx->pc = 0x800F6344u;
    // 800F6344: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_800F6348:
    ctx->pc = 0x800F6348u;
    // 800F6348: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F634C:
    ctx->pc = 0x800F634Cu;
    // 800F634C: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800F6350:
    ctx->pc = 0x800F6350u;
    // 800F6350: cmpwi   r30, 0
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

label_800F6354:
    ctx->pc = 0x800F6354u;
    // 800F6354: bc    12, 2, 0x800F6364
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6364;
        }
    }

label_800F6358:
    ctx->pc = 0x800F6358u;
    ctx->downcount -= 3;
    // 800F6358: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F635C:
    ctx->pc = 0x800F635Cu;
    // 800F635C: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6360:
    ctx->pc = 0x800F6360u;
    // 800F6360: b       0x800F63E4
    {
            goto label_800F63E4;
    }

label_800F6364:
    ctx->pc = 0x800F6364u;
    ctx->downcount -= 7;
    // 800F6364: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_800F6368:
    ctx->pc = 0x800F6368u;
    // 800F6368: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_800F636C:
    ctx->pc = 0x800F636Cu;
    // 800F636C: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_800F6370:
    ctx->pc = 0x800F6370u;
    // 800F6370: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6374:
    ctx->pc = 0x800F6374u;
    // 800F6374: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F6378:
    ctx->pc = 0x800F6378u;
    // 800F6378: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_800F637C:
    ctx->pc = 0x800F637Cu;
    // 800F637C: bl      0x80003EE0
    {
            ctx->lr = 0x800F6380u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_800F6380:
    ctx->pc = 0x800F6380u;
    ctx->downcount -= 3;
    // 800F6380: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6384:
    ctx->pc = 0x800F6384u;
    // 800F6384: cmpwi   r9, 1
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

label_800F6388:
    ctx->pc = 0x800F6388u;
    // 800F6388: bc    12, 2, 0x800F63E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F63E0;
        }
    }

label_800F638C:
    ctx->pc = 0x800F638Cu;
    ctx->downcount -= 9;
    // 800F638C: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_800F6390:
    ctx->pc = 0x800F6390u;
    // 800F6390: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800F6394:
    ctx->pc = 0x800F6394u;
    // 800F6394: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F6398:
    ctx->pc = 0x800F6398u;
    // 800F6398: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800F639C:
    ctx->pc = 0x800F639Cu;
    // 800F639C: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F63A0:
    ctx->pc = 0x800F63A0u;
    // 800F63A0: cmpwi   r9, 2
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

label_800F63A4:
    ctx->pc = 0x800F63A4u;
    // 800F63A4: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_800F63A8:
    ctx->pc = 0x800F63A8u;
    // 800F63A8: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800F63AC:
    ctx->pc = 0x800F63ACu;
    // 800F63AC: bc    4, 2, 0x800F63B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F63B8;
        }
    }

label_800F63B0:
    ctx->pc = 0x800F63B0u;
    ctx->downcount -= 2;
    // 800F63B0: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800F63B4:
    ctx->pc = 0x800F63B4u;
    // 800F63B4: b       0x800F63E0
    {
            goto label_800F63E0;
    }

label_800F63B8:
    loop_800F63B8(ctx);
    if (ctx->pc == 0x800F63D8u) goto label_800F63D8;
    return;
label_800F63BC:
    // 800F63BC: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_800F63C0:
    // 800F63C0: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800F63C4:
    ctx->pc = 0x800F63C4u;
    // 800F63C4: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F63C8:
    // 800F63C8: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800F63CC:
    // 800F63CC: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_800F63D0:
    // 800F63D0: cmpw    r9, r8
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

label_800F63D4:
    // 800F63D4: bc    4, 2, 0x800F63B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F63B8u;
                return;
            }
            goto label_800F63B8;
        }
    }

label_800F63D8:
    ctx->pc = 0x800F63D8u;
    ctx->downcount -= 2;
    // 800F63D8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F63DC:
    ctx->pc = 0x800F63DCu;
    // 800F63DC: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F63E0:
    ctx->pc = 0x800F63E0u;
    ctx->downcount -= 1;
    // 800F63E0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F63E4:
    ctx->pc = 0x800F63E4u;
    ctx->downcount -= 17;
    // 800F63E4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F63E8:
    ctx->pc = 0x800F63E8u;
    // 800F63E8: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F63EC:
    ctx->pc = 0x800F63ECu;
    // 800F63EC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F63F0:
    ctx->pc = 0x800F63F0u;
    // 800F63F0: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F63F4:
    ctx->pc = 0x800F63F4u;
    // 800F63F4: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_800F63F8:
    ctx->pc = 0x800F63F8u;
    // 800F63F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F63FC:
    ctx->pc = 0x800F63FCu;
    ctx->downcount -= 7;
    // 800F63FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6400:
    ctx->pc = 0x800F6400u;
    // 800F6400: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6404:
    ctx->pc = 0x800F6404u;
    // 800F6404: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6408:
    ctx->pc = 0x800F6408u;
    // 800F6408: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F640C:
    ctx->pc = 0x800F640Cu;
    // 800F640C: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_800F6410:
    ctx->pc = 0x800F6410u;
    // 800F6410: cmpw    r4, r0
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

label_800F6414:
    ctx->pc = 0x800F6414u;
    // 800F6414: bc    4, 2, 0x800F6510
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F6510;
        }
    }

label_800F6418:
    ctx->pc = 0x800F6418u;
    ctx->downcount -= 2;
    // 800F6418: cmpwi   r3, 0
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

label_800F641C:
    ctx->pc = 0x800F641Cu;
    // 800F641C: bc    12, 2, 0x800F6510
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6510;
        }
    }

label_800F6420:
    ctx->pc = 0x800F6420u;
    ctx->downcount -= 5;
    // 800F6420: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_800F6424:
    ctx->pc = 0x800F6424u;
    // 800F6424: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_800F6428:
    ctx->pc = 0x800F6428u;
    // 800F6428: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_800F642C:
    ctx->pc = 0x800F642Cu;
    // 800F642C: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_800F6430:
    ctx->pc = 0x800F6430u;
    // 800F6430: bl      0x80252AF0
    {
            ctx->lr = 0x800F6434u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6434:
    ctx->pc = 0x800F6434u;
    ctx->downcount -= 5;
    // 800F6434: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_800F6438:
    ctx->pc = 0x800F6438u;
    // 800F6438: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_800F643C:
    ctx->pc = 0x800F643Cu;
    // 800F643C: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_800F6440:
    ctx->pc = 0x800F6440u;
    // 800F6440: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F6444:
    ctx->pc = 0x800F6444u;
    // 800F6444: bl      0x80252AF0
    {
            ctx->lr = 0x800F6448u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6448:
    ctx->pc = 0x800F6448u;
    ctx->downcount -= 5;
    // 800F6448: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_800F644C:
    ctx->pc = 0x800F644Cu;
    // 800F644C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_800F6450:
    ctx->pc = 0x800F6450u;
    // 800F6450: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_800F6454:
    ctx->pc = 0x800F6454u;
    // 800F6454: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F6458:
    ctx->pc = 0x800F6458u;
    // 800F6458: bl      0x80252AF0
    {
            ctx->lr = 0x800F645Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F645C:
    ctx->pc = 0x800F645Cu;
    ctx->downcount -= 5;
    // 800F645C: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_800F6460:
    ctx->pc = 0x800F6460u;
    // 800F6460: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_800F6464:
    ctx->pc = 0x800F6464u;
    // 800F6464: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_800F6468:
    ctx->pc = 0x800F6468u;
    // 800F6468: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F646C:
    ctx->pc = 0x800F646Cu;
    // 800F646C: bl      0x80252AF0
    {
            ctx->lr = 0x800F6470u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6470:
    ctx->pc = 0x800F6470u;
    ctx->downcount -= 5;
    // 800F6470: lis     r3, 25197
    ctx->gpr[3] = ((u32)(s32)(25197) << 16);

label_800F6474:
    ctx->pc = 0x800F6474u;
    // 800F6474: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_800F6478:
    ctx->pc = 0x800F6478u;
    // 800F6478: ori     r3, r3, 0x7368
    ctx->gpr[3] = ctx->gpr[3] | 0x7368u;

label_800F647C:
    ctx->pc = 0x800F647Cu;
    // 800F647C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F6480:
    ctx->pc = 0x800F6480u;
    // 800F6480: bl      0x80252AF0
    {
            ctx->lr = 0x800F6484u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6484:
    ctx->pc = 0x800F6484u;
    ctx->downcount -= 5;
    // 800F6484: lis     r3, 25199
    ctx->gpr[3] = ((u32)(s32)(25199) << 16);

label_800F6488:
    ctx->pc = 0x800F6488u;
    // 800F6488: li      r4, 63
    ctx->gpr[4] = (u32)(s32)(63);

label_800F648C:
    ctx->pc = 0x800F648Cu;
    // 800F648C: ori     r3, r3, 0x6479
    ctx->gpr[3] = ctx->gpr[3] | 0x6479u;

label_800F6490:
    ctx->pc = 0x800F6490u;
    // 800F6490: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F6494:
    ctx->pc = 0x800F6494u;
    // 800F6494: bl      0x80252AF0
    {
            ctx->lr = 0x800F6498u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6498:
    ctx->pc = 0x800F6498u;
    ctx->downcount -= 5;
    // 800F6498: lis     r3, 25185
    ctx->gpr[3] = ((u32)(s32)(25185) << 16);

label_800F649C:
    ctx->pc = 0x800F649Cu;
    // 800F649C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_800F64A0:
    ctx->pc = 0x800F64A0u;
    // 800F64A0: ori     r3, r3, 0x6E6D
    ctx->gpr[3] = ctx->gpr[3] | 0x6E6Du;

label_800F64A4:
    ctx->pc = 0x800F64A4u;
    // 800F64A4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F64A8:
    ctx->pc = 0x800F64A8u;
    // 800F64A8: bl      0x80252AF0
    {
            ctx->lr = 0x800F64ACu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F64AC:
    ctx->pc = 0x800F64ACu;
    ctx->downcount -= 5;
    // 800F64AC: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_800F64B0:
    ctx->pc = 0x800F64B0u;
    // 800F64B0: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_800F64B4:
    ctx->pc = 0x800F64B4u;
    // 800F64B4: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_800F64B8:
    ctx->pc = 0x800F64B8u;
    // 800F64B8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F64BC:
    ctx->pc = 0x800F64BCu;
    // 800F64BC: bl      0x80252AF0
    {
            ctx->lr = 0x800F64C0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F64C0:
    ctx->pc = 0x800F64C0u;
    ctx->downcount -= 5;
    // 800F64C0: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_800F64C4:
    ctx->pc = 0x800F64C4u;
    // 800F64C4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800F64C8:
    ctx->pc = 0x800F64C8u;
    // 800F64C8: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_800F64CC:
    ctx->pc = 0x800F64CCu;
    // 800F64CC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F64D0:
    ctx->pc = 0x800F64D0u;
    // 800F64D0: bl      0x80252AF0
    {
            ctx->lr = 0x800F64D4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F64D4:
    ctx->pc = 0x800F64D4u;
    ctx->downcount -= 5;
    // 800F64D4: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_800F64D8:
    ctx->pc = 0x800F64D8u;
    // 800F64D8: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_800F64DC:
    ctx->pc = 0x800F64DCu;
    // 800F64DC: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_800F64E0:
    ctx->pc = 0x800F64E0u;
    // 800F64E0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F64E4:
    ctx->pc = 0x800F64E4u;
    // 800F64E4: bl      0x80252AF0
    {
            ctx->lr = 0x800F64E8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F64E8:
    ctx->pc = 0x800F64E8u;
    ctx->downcount -= 5;
    // 800F64E8: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_800F64EC:
    ctx->pc = 0x800F64ECu;
    // 800F64EC: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_800F64F0:
    ctx->pc = 0x800F64F0u;
    // 800F64F0: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_800F64F4:
    ctx->pc = 0x800F64F4u;
    // 800F64F4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F64F8:
    ctx->pc = 0x800F64F8u;
    // 800F64F8: bl      0x80252AF0
    {
            ctx->lr = 0x800F64FCu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F64FC:
    ctx->pc = 0x800F64FCu;
    ctx->downcount -= 5;
    // 800F64FC: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_800F6500:
    ctx->pc = 0x800F6500u;
    // 800F6500: lis     r4, -32753
    ctx->gpr[4] = ((u32)(s32)(-32753) << 16);

label_800F6504:
    ctx->pc = 0x800F6504u;
    // 800F6504: addi    r3, r3, -6432
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-6432);

label_800F6508:
    ctx->pc = 0x800F6508u;
    // 800F6508: addi    r4, r4, 25888
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(25888);

label_800F650C:
    ctx->pc = 0x800F650Cu;
    // 800F650C: bl      0x801FC784
    {
            ctx->lr = 0x800F6510u;
            ctx->pc = 0x801FC784u;
            return;
    }

label_800F6510:
    ctx->pc = 0x800F6510u;
    ctx->downcount -= 5;
    // 800F6510: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6514:
    ctx->pc = 0x800F6514u;
    // 800F6514: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6518:
    ctx->pc = 0x800F6518u;
    // 800F6518: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F651C:
    ctx->pc = 0x800F651Cu;
    // 800F651C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6520:
    ctx->pc = 0x800F6520u;
    ctx->downcount -= 17;
    // 800F6520: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6524:
    ctx->pc = 0x800F6524u;
    // 800F6524: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6528:
    ctx->pc = 0x800F6528u;
    // 800F6528: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F652C:
    ctx->pc = 0x800F652Cu;
    // 800F652C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6530:
    ctx->pc = 0x800F6530u;
    // 800F6530: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6534:
    ctx->pc = 0x800F6534u;
    // 800F6534: li      r3, 1560
    ctx->gpr[3] = (u32)(s32)(1560);

label_800F6538:
    ctx->pc = 0x800F6538u;
    // 800F6538: bl      0x80281C60
    {
            ctx->lr = 0x800F653Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F653C:
    ctx->pc = 0x800F653Cu;
    ctx->downcount -= 2;
    // 800F653C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6540:
    ctx->pc = 0x800F6540u;
    // 800F6540: bl      0x800F6558
    {
            ctx->lr = 0x800F6544u;
            goto label_800F6558;
    }

label_800F6544:
    ctx->pc = 0x800F6544u;
    ctx->downcount -= 16;
    // 800F6544: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6548:
    ctx->pc = 0x800F6548u;
    // 800F6548: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F654C:
    ctx->pc = 0x800F654Cu;
    // 800F654C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F6550:
    ctx->pc = 0x800F6550u;
    // 800F6550: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F6554:
    ctx->pc = 0x800F6554u;
    // 800F6554: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6558:
    ctx->pc = 0x800F6558u;
    ctx->downcount -= 16;
    // 800F6558: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F655C:
    ctx->pc = 0x800F655Cu;
    // 800F655C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6560:
    ctx->pc = 0x800F6560u;
    // 800F6560: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F6564:
    ctx->pc = 0x800F6564u;
    // 800F6564: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6568:
    ctx->pc = 0x800F6568u;
    // 800F6568: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F656C:
    ctx->pc = 0x800F656Cu;
    // 800F656C: bl      0x800E55D0
    {
            ctx->lr = 0x800F6570u;
            ctx->pc = 0x800E55D0u;
            return;
    }

label_800F6570:
    ctx->pc = 0x800F6570u;
    ctx->downcount -= 30;
    // 800F6570: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F6574:
    ctx->pc = 0x800F6574u;
    // 800F6574: lwz     r10, 508(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(508);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800F6578:
    ctx->pc = 0x800F6578u;
    // 800F6578: addi    r9, r9, -6728
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-6728);

label_800F657C:
    ctx->pc = 0x800F657Cu;
    // 800F657C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800F6580:
    ctx->pc = 0x800F6580u;
    // 800F6580: stw     r9, 108(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6584:
    ctx->pc = 0x800F6584u;
    // 800F6584: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_800F6588:
    ctx->pc = 0x800F6588u;
    // 800F6588: stw     r0, 228(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(228);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F658C:
    ctx->pc = 0x800F658Cu;
    // 800F658C: li      r8, 29
    ctx->gpr[8] = (u32)(s32)(29);

label_800F6590:
    ctx->pc = 0x800F6590u;
    // 800F6590: lfs     f0, -6424(r11)
    if (!ppc_fp_available_inline(ctx, 0x800F6590u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-6424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F6594:
    ctx->pc = 0x800F6594u;
    // 800F6594: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6598:
    ctx->pc = 0x800F6598u;
    // 800F6598: lwz     r9, 508(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(508);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F659C:
    ctx->pc = 0x800F659Cu;
    // 800F659C: stfs     f0, 292(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F659Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(292);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F65A0:
    ctx->pc = 0x800F65A0u;
    // 800F65A0: lwz     r11, 508(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(508);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F65A4:
    ctx->pc = 0x800F65A4u;
    // 800F65A4: stw     r8, 288(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(288);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800F65A8:
    ctx->pc = 0x800F65A8u;
    // 800F65A8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F65AC:
    ctx->pc = 0x800F65ACu;
    // 800F65AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F65B0:
    ctx->pc = 0x800F65B0u;
    // 800F65B0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F65B4:
    ctx->pc = 0x800F65B4u;
    // 800F65B4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F65B8:
    ctx->pc = 0x800F65B8u;
    // 800F65B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F65BC:
    ctx->pc = 0x800F65BCu;
    ctx->downcount -= 8;
    // 800F65BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F65C0:
    ctx->pc = 0x800F65C0u;
    // 800F65C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F65C4:
    ctx->pc = 0x800F65C4u;
    // 800F65C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F65C8:
    ctx->pc = 0x800F65C8u;
    // 800F65C8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F65CC:
    ctx->pc = 0x800F65CCu;
    // 800F65CC: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F65D0:
    ctx->pc = 0x800F65D0u;
    // 800F65D0: addi    r9, r9, -6728
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-6728);

label_800F65D4:
    ctx->pc = 0x800F65D4u;
    // 800F65D4: stw     r9, 108(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F65D8:
    ctx->pc = 0x800F65D8u;
    // 800F65D8: bl      0x800E6574
    {
            ctx->lr = 0x800F65DCu;
            ctx->pc = 0x800E6574u;
            return;
    }

label_800F65DC:
    ctx->pc = 0x800F65DCu;
    ctx->downcount -= 5;
    // 800F65DC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F65E0:
    ctx->pc = 0x800F65E0u;
    // 800F65E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F65E4:
    ctx->pc = 0x800F65E4u;
    // 800F65E4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F65E8:
    ctx->pc = 0x800F65E8u;
    // 800F65E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F65EC:
    ctx->pc = 0x800F65ECu;
    ctx->downcount -= 17;
    // 800F65EC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F65F0:
    ctx->pc = 0x800F65F0u;
    // 800F65F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F65F4:
    ctx->pc = 0x800F65F4u;
    // 800F65F4: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F65F8:
    ctx->pc = 0x800F65F8u;
    // 800F65F8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F65FC:
    ctx->pc = 0x800F65FCu;
    // 800F65FC: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800F6600:
    ctx->pc = 0x800F6600u;
    // 800F6600: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6604:
    ctx->pc = 0x800F6604u;
    // 800F6604: bl      0x800EE2A8
    {
            ctx->lr = 0x800F6608u;
            ctx->pc = 0x800EE2A8u;
            return;
    }

label_800F6608:
    ctx->pc = 0x800F6608u;
    ctx->downcount -= 3;
    // 800F6608: cmpwi   r31, 0
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

label_800F660C:
    ctx->pc = 0x800F660Cu;
    // 800F660C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F6610:
    ctx->pc = 0x800F6610u;
    // 800F6610: bc    12, 2, 0x800F6618
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6618;
        }
    }

label_800F6614:
    ctx->pc = 0x800F6614u;
    ctx->downcount -= 1;
    // 800F6614: addi    r0, r31, -288
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-288);

label_800F6618:
    ctx->pc = 0x800F6618u;
    ctx->downcount -= 17;
    // 800F6618: stw     r0, 1552(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1552);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F661C:
    ctx->pc = 0x800F661Cu;
    // 800F661C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6620:
    ctx->pc = 0x800F6620u;
    // 800F6620: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6624:
    ctx->pc = 0x800F6624u;
    // 800F6624: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F6628:
    ctx->pc = 0x800F6628u;
    // 800F6628: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F662C:
    ctx->pc = 0x800F662Cu;
    // 800F662C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6630:
    ctx->pc = 0x800F6630u;
    ctx->downcount -= 18;
    // 800F6630: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6634:
    ctx->pc = 0x800F6634u;
    // 800F6634: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6638:
    ctx->pc = 0x800F6638u;
    // 800F6638: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F663C:
    ctx->pc = 0x800F663Cu;
    // 800F663C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6640:
    ctx->pc = 0x800F6640u;
    // 800F6640: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800F6644:
    ctx->pc = 0x800F6644u;
    // 800F6644: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6648:
    ctx->pc = 0x800F6648u;
    // 800F6648: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F664C:
    ctx->pc = 0x800F664Cu;
    // 800F664C: bl      0x8017C3FC
    {
            ctx->lr = 0x800F6650u;
            ctx->pc = 0x8017C3FCu;
            return;
    }

label_800F6650:
    ctx->pc = 0x800F6650u;
    ctx->downcount -= 2;
    // 800F6650: cmpwi   r3, 0
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

label_800F6654:
    ctx->pc = 0x800F6654u;
    // 800F6654: bc    4, 2, 0x800F6664
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F6664;
        }
    }

label_800F6658:
    ctx->pc = 0x800F6658u;
    ctx->downcount -= 3;
    // 800F6658: lwz     r0, 500(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(500);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F665C:
    ctx->pc = 0x800F665Cu;
    // 800F665C: cmpwi   r0, 0
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

label_800F6660:
    ctx->pc = 0x800F6660u;
    // 800F6660: bc    12, 2, 0x800F6684
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6684;
        }
    }

label_800F6664:
    ctx->pc = 0x800F6664u;
    ctx->downcount -= 3;
    // 800F6664: lwz     r4, 1552(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1552);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800F6668:
    ctx->pc = 0x800F6668u;
    // 800F6668: cmpwi   r4, 0
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

label_800F666C:
    ctx->pc = 0x800F666Cu;
    // 800F666C: bc    12, 2, 0x800F6678
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6678;
        }
    }

label_800F6670:
    ctx->pc = 0x800F6670u;
    ctx->downcount -= 2;
    // 800F6670: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6674:
    ctx->pc = 0x800F6674u;
    // 800F6674: bl      0x80180AEC
    {
            ctx->lr = 0x800F6678u;
            ctx->pc = 0x80180AECu;
            return;
    }

label_800F6678:
    ctx->pc = 0x800F6678u;
    ctx->downcount -= 3;
    // 800F6678: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F667C:
    ctx->pc = 0x800F667Cu;
    // 800F667C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6680:
    ctx->pc = 0x800F6680u;
    // 800F6680: bl      0x800E66F0
    {
            ctx->lr = 0x800F6684u;
            ctx->pc = 0x800E66F0u;
            return;
    }

label_800F6684:
    ctx->pc = 0x800F6684u;
    ctx->downcount -= 16;
    // 800F6684: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6688:
    ctx->pc = 0x800F6688u;
    // 800F6688: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F668C:
    ctx->pc = 0x800F668Cu;
    // 800F668C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F6690:
    ctx->pc = 0x800F6690u;
    // 800F6690: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F6694:
    ctx->pc = 0x800F6694u;
    // 800F6694: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6698:
    ctx->pc = 0x800F6698u;
    ctx->downcount -= 16;
    // 800F6698: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F669C:
    ctx->pc = 0x800F669Cu;
    // 800F669C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F66A0:
    ctx->pc = 0x800F66A0u;
    // 800F66A0: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F66A4:
    ctx->pc = 0x800F66A4u;
    // 800F66A4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F66A8:
    ctx->pc = 0x800F66A8u;
    // 800F66A8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F66AC:
    ctx->pc = 0x800F66ACu;
    // 800F66AC: bl      0x800E67B0
    {
            ctx->lr = 0x800F66B0u;
            ctx->pc = 0x800E67B0u;
            return;
    }

label_800F66B0:
    ctx->pc = 0x800F66B0u;
    ctx->downcount -= 2;
    // 800F66B0: or.   r31, r3, r3
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

label_800F66B4:
    ctx->pc = 0x800F66B4u;
    // 800F66B4: bc    12, 2, 0x800F66E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F66E8;
        }
    }

label_800F66B8:
    ctx->pc = 0x800F66B8u;
    ctx->downcount -= 7;
    // 800F66B8: lwz     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F66BC:
    ctx->pc = 0x800F66BCu;
    // 800F66BC: lwz     r0, 108(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F66C0:
    ctx->pc = 0x800F66C0u;
    // 800F66C0: lha     r3, 104(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(104);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800F66C4:
    ctx->pc = 0x800F66C4u;
    // 800F66C4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F66C8:
    ctx->pc = 0x800F66C8u;
    // 800F66C8: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800F66CC:
    ctx->pc = 0x800F66CCu;
    // 800F66CC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800F66D0u;
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F66D0:
    ctx->pc = 0x800F66D0u;
    ctx->downcount -= 4;
    // 800F66D0: lwz     r0, 1552(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1552);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F66D4:
    ctx->pc = 0x800F66D4u;
    // 800F66D4: cmpw    r3, r0
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

label_800F66D8:
    ctx->pc = 0x800F66D8u;
    // 800F66D8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F66DC:
    ctx->pc = 0x800F66DCu;
    // 800F66DC: bc    12, 2, 0x800F66EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F66EC;
        }
    }

label_800F66E0:
    ctx->pc = 0x800F66E0u;
    ctx->downcount -= 2;
    // 800F66E0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F66E4:
    ctx->pc = 0x800F66E4u;
    // 800F66E4: b       0x800F66EC
    {
            goto label_800F66EC;
    }

label_800F66E8:
    ctx->pc = 0x800F66E8u;
    ctx->downcount -= 1;
    // 800F66E8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F66EC:
    ctx->pc = 0x800F66ECu;
    ctx->downcount -= 16;
    // 800F66EC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F66F0:
    ctx->pc = 0x800F66F0u;
    // 800F66F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F66F4:
    ctx->pc = 0x800F66F4u;
    // 800F66F4: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F66F8:
    ctx->pc = 0x800F66F8u;
    // 800F66F8: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F66FC:
    ctx->pc = 0x800F66FCu;
    // 800F66FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6700:
    ctx->pc = 0x800F6700u;
    ctx->downcount -= 7;
    // 800F6700: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6704:
    ctx->pc = 0x800F6704u;
    // 800F6704: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6708:
    ctx->pc = 0x800F6708u;
    // 800F6708: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F670C:
    ctx->pc = 0x800F670Cu;
    // 800F670C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800F6710:
    ctx->pc = 0x800F6710u;
    // 800F6710: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800F6714:
    ctx->pc = 0x800F6714u;
    // 800F6714: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_800F6718:
    ctx->pc = 0x800F6718u;
    // 800F6718: bl      0x800F63FC
    {
            ctx->lr = 0x800F671Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F63FCu;
                return;
            }
            goto label_800F63FC;
    }

label_800F671C:
    ctx->pc = 0x800F671Cu;
    ctx->downcount -= 5;
    // 800F671C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6720:
    ctx->pc = 0x800F6720u;
    // 800F6720: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6724:
    ctx->pc = 0x800F6724u;
    // 800F6724: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F6728:
    ctx->pc = 0x800F6728u;
    // 800F6728: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F672C:
    ctx->pc = 0x800F672Cu;
    ctx->downcount -= 7;
    // 800F672C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6730:
    ctx->pc = 0x800F6730u;
    // 800F6730: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6734:
    ctx->pc = 0x800F6734u;
    // 800F6734: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6738:
    ctx->pc = 0x800F6738u;
    // 800F6738: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F673C:
    ctx->pc = 0x800F673Cu;
    // 800F673C: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_800F6740:
    ctx->pc = 0x800F6740u;
    // 800F6740: cmpw    r4, r0
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

label_800F6744:
    ctx->pc = 0x800F6744u;
    // 800F6744: bc    4, 2, 0x800F67B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F67B4;
        }
    }

label_800F6748:
    ctx->pc = 0x800F6748u;
    ctx->downcount -= 2;
    // 800F6748: cmpwi   r3, 0
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

label_800F674C:
    ctx->pc = 0x800F674Cu;
    // 800F674C: bc    12, 2, 0x800F67B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F67B4;
        }
    }

label_800F6750:
    ctx->pc = 0x800F6750u;
    ctx->downcount -= 5;
    // 800F6750: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_800F6754:
    ctx->pc = 0x800F6754u;
    // 800F6754: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_800F6758:
    ctx->pc = 0x800F6758u;
    // 800F6758: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_800F675C:
    ctx->pc = 0x800F675Cu;
    // 800F675C: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_800F6760:
    ctx->pc = 0x800F6760u;
    // 800F6760: bl      0x80252AF0
    {
            ctx->lr = 0x800F6764u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6764:
    ctx->pc = 0x800F6764u;
    ctx->downcount -= 5;
    // 800F6764: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_800F6768:
    ctx->pc = 0x800F6768u;
    // 800F6768: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_800F676C:
    ctx->pc = 0x800F676Cu;
    // 800F676C: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_800F6770:
    ctx->pc = 0x800F6770u;
    // 800F6770: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F6774:
    ctx->pc = 0x800F6774u;
    // 800F6774: bl      0x80252AF0
    {
            ctx->lr = 0x800F6778u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6778:
    ctx->pc = 0x800F6778u;
    ctx->downcount -= 5;
    // 800F6778: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_800F677C:
    ctx->pc = 0x800F677Cu;
    // 800F677C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_800F6780:
    ctx->pc = 0x800F6780u;
    // 800F6780: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_800F6784:
    ctx->pc = 0x800F6784u;
    // 800F6784: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F6788:
    ctx->pc = 0x800F6788u;
    // 800F6788: bl      0x80252AF0
    {
            ctx->lr = 0x800F678Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F678C:
    ctx->pc = 0x800F678Cu;
    ctx->downcount -= 5;
    // 800F678C: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_800F6790:
    ctx->pc = 0x800F6790u;
    // 800F6790: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_800F6794:
    ctx->pc = 0x800F6794u;
    // 800F6794: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_800F6798:
    ctx->pc = 0x800F6798u;
    // 800F6798: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F679C:
    ctx->pc = 0x800F679Cu;
    // 800F679C: bl      0x80252AF0
    {
            ctx->lr = 0x800F67A0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F67A0:
    ctx->pc = 0x800F67A0u;
    ctx->downcount -= 5;
    // 800F67A0: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_800F67A4:
    ctx->pc = 0x800F67A4u;
    // 800F67A4: lis     r4, -32753
    ctx->gpr[4] = ((u32)(s32)(-32753) << 16);

label_800F67A8:
    ctx->pc = 0x800F67A8u;
    // 800F67A8: addi    r3, r3, -6088
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-6088);

label_800F67AC:
    ctx->pc = 0x800F67ACu;
    // 800F67AC: addi    r4, r4, 26564
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(26564);

label_800F67B0:
    ctx->pc = 0x800F67B0u;
    // 800F67B0: bl      0x801FC784
    {
            ctx->lr = 0x800F67B4u;
            ctx->pc = 0x801FC784u;
            return;
    }

label_800F67B4:
    ctx->pc = 0x800F67B4u;
    ctx->downcount -= 5;
    // 800F67B4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F67B8:
    ctx->pc = 0x800F67B8u;
    // 800F67B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F67BC:
    ctx->pc = 0x800F67BCu;
    // 800F67BC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F67C0:
    ctx->pc = 0x800F67C0u;
    // 800F67C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F67C4:
    ctx->pc = 0x800F67C4u;
    ctx->downcount -= 17;
    // 800F67C4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F67C8:
    ctx->pc = 0x800F67C8u;
    // 800F67C8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F67CC:
    ctx->pc = 0x800F67CCu;
    // 800F67CC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F67D0:
    ctx->pc = 0x800F67D0u;
    // 800F67D0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F67D4:
    ctx->pc = 0x800F67D4u;
    // 800F67D4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F67D8:
    ctx->pc = 0x800F67D8u;
    // 800F67D8: li      r3, 488
    ctx->gpr[3] = (u32)(s32)(488);

label_800F67DC:
    ctx->pc = 0x800F67DCu;
    // 800F67DC: bl      0x80281C60
    {
            ctx->lr = 0x800F67E0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F67E0:
    ctx->pc = 0x800F67E0u;
    ctx->downcount -= 2;
    // 800F67E0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F67E4:
    ctx->pc = 0x800F67E4u;
    // 800F67E4: bl      0x800F67FC
    {
            ctx->lr = 0x800F67E8u;
            goto label_800F67FC;
    }

label_800F67E8:
    ctx->pc = 0x800F67E8u;
    ctx->downcount -= 16;
    // 800F67E8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F67EC:
    ctx->pc = 0x800F67ECu;
    // 800F67EC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F67F0:
    ctx->pc = 0x800F67F0u;
    // 800F67F0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F67F4:
    ctx->pc = 0x800F67F4u;
    // 800F67F4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F67F8:
    ctx->pc = 0x800F67F8u;
    // 800F67F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F67FC:
    ctx->pc = 0x800F67FCu;
    ctx->downcount -= 16;
    // 800F67FC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6800:
    ctx->pc = 0x800F6800u;
    // 800F6800: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6804:
    ctx->pc = 0x800F6804u;
    // 800F6804: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F6808:
    ctx->pc = 0x800F6808u;
    // 800F6808: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F680C:
    ctx->pc = 0x800F680Cu;
    // 800F680C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6810:
    ctx->pc = 0x800F6810u;
    // 800F6810: bl      0x801FC8B4
    {
            ctx->lr = 0x800F6814u;
            ctx->pc = 0x801FC8B4u;
            return;
    }

label_800F6814:
    ctx->pc = 0x800F6814u;
    ctx->downcount -= 22;
    // 800F6814: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_800F6818:
    ctx->pc = 0x800F6818u;
    // 800F6818: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_800F681C:
    ctx->pc = 0x800F681Cu;
    // 800F681C: lfs     f0, -6084(r11)
    if (!ppc_fp_available_inline(ctx, 0x800F681Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-6084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F6820:
    ctx->pc = 0x800F6820u;
    // 800F6820: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F6824:
    ctx->pc = 0x800F6824u;
    // 800F6824: addi    r9, r9, -6320
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-6320);

label_800F6828:
    ctx->pc = 0x800F6828u;
    // 800F6828: lfs     f13, -6080(r10)
    if (!ppc_fp_available_inline(ctx, 0x800F6828u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-6080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F682C:
    ctx->pc = 0x800F682Cu;
    // 800F682C: stw     r9, 108(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6830:
    ctx->pc = 0x800F6830u;
    // 800F6830: addi    r11, r30, 472
    ctx->gpr[11] = ctx->gpr[30] + (u32)(s32)(472);

label_800F6834:
    ctx->pc = 0x800F6834u;
    // 800F6834: stfs     f0, 472(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F6834u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(472);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F6838:
    ctx->pc = 0x800F6838u;
    // 800F6838: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F683C:
    ctx->pc = 0x800F683Cu;
    // 800F683C: stfs     f13, 12(r11)
    if (!ppc_fp_available_inline(ctx, 0x800F683Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F6840:
    ctx->pc = 0x800F6840u;
    // 800F6840: lis     r9, -1
    ctx->gpr[9] = ((u32)(s32)(-1) << 16);

label_800F6844:
    ctx->pc = 0x800F6844u;
    // 800F6844: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x800F6844u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F6848:
    ctx->pc = 0x800F6848u;
    // 800F6848: ori     r9, r9, 0x5FEF
    ctx->gpr[9] = ctx->gpr[9] | 0x5FEFu;

label_800F684C:
    ctx->pc = 0x800F684Cu;
    // 800F684C: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x800F684Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F6850:
    ctx->pc = 0x800F6850u;
    // 800F6850: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6854:
    ctx->pc = 0x800F6854u;
    // 800F6854: stw     r0, 412(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(412);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6858:
    ctx->pc = 0x800F6858u;
    // 800F6858: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800F685C:
    ctx->pc = 0x800F685Cu;
    // 800F685C: lwz     r0, 416(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(416);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6860:
    ctx->pc = 0x800F6860u;
    // 800F6860: and   r0, r0, r9
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[9];
    }

label_800F6864:
    ctx->pc = 0x800F6864u;
    // 800F6864: stw     r0, 416(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(416);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6868:
    ctx->pc = 0x800F6868u;
    // 800F6868: bl      0x80221174
    {
            ctx->lr = 0x800F686Cu;
            ctx->pc = 0x80221174u;
            return;
    }

label_800F686C:
    ctx->pc = 0x800F686Cu;
    ctx->downcount -= 4;
    // 800F686C: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6870:
    ctx->pc = 0x800F6870u;
    // 800F6870: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6874:
    ctx->pc = 0x800F6874u;
    // 800F6874: lwz     r3, 52(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(52);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F6878:
    ctx->pc = 0x800F6878u;
    // 800F6878: bl      0x800FB398
    {
            ctx->lr = 0x800F687Cu;
            ctx->pc = 0x800FB398u;
            return;
    }

label_800F687C:
    ctx->pc = 0x800F687Cu;
    ctx->downcount -= 17;
    // 800F687C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6880:
    ctx->pc = 0x800F6880u;
    // 800F6880: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6884:
    ctx->pc = 0x800F6884u;
    // 800F6884: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6888:
    ctx->pc = 0x800F6888u;
    // 800F6888: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F688C:
    ctx->pc = 0x800F688Cu;
    // 800F688C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F6890:
    ctx->pc = 0x800F6890u;
    // 800F6890: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6894:
    ctx->pc = 0x800F6894u;
    ctx->downcount -= 5;
    // 800F6894: stfs     f4, 484(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F6894u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(484);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_800F6898:
    ctx->pc = 0x800F6898u;
    // 800F6898: stfs     f1, 472(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F6898u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(472);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_800F689C:
    ctx->pc = 0x800F689Cu;
    // 800F689C: stfs     f2, 476(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F689Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(476);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_800F68A0:
    ctx->pc = 0x800F68A0u;
    // 800F68A0: stfs     f3, 480(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F68A0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(480);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_800F68A4:
    ctx->pc = 0x800F68A4u;
    // 800F68A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F68A8:
    ctx->pc = 0x800F68A8u;
    ctx->downcount -= 9;
    // 800F68A8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F68AC:
    ctx->pc = 0x800F68ACu;
    // 800F68AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F68B0:
    ctx->pc = 0x800F68B0u;
    // 800F68B0: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800F68B4:
    ctx->pc = 0x800F68B4u;
    // 800F68B4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F68B8:
    ctx->pc = 0x800F68B8u;
    // 800F68B8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F68BC:
    ctx->pc = 0x800F68BCu;
    // 800F68BC: lwz     r9, 436(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(436);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F68C0:
    ctx->pc = 0x800F68C0u;
    // 800F68C0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F68C4:
    ctx->pc = 0x800F68C4u;
    // 800F68C4: cmpwi   r9, 0
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

label_800F68C8:
    ctx->pc = 0x800F68C8u;
    // 800F68C8: bc    12, 2, 0x800F68D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F68D0;
        }
    }

label_800F68CC:
    ctx->pc = 0x800F68CCu;
    ctx->downcount -= 1;
    // 800F68CC: addi    r3, r9, -36
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(-36);

label_800F68D0:
    ctx->pc = 0x800F68D0u;
    ctx->downcount -= 3;
    // 800F68D0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F68D4:
    ctx->pc = 0x800F68D4u;
    // 800F68D4: addi    r4, r4, -6392
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-6392);

label_800F68D8:
    ctx->pc = 0x800F68D8u;
    // 800F68D8: bl      0x801E7A84
    {
            ctx->lr = 0x800F68DCu;
            ctx->pc = 0x801E7A84u;
            return;
    }

label_800F68DC:
    ctx->pc = 0x800F68DCu;
    ctx->downcount -= 4;
    // 800F68DC: lwz     r11, 436(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(436);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F68E0:
    ctx->pc = 0x800F68E0u;
    // 800F68E0: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_800F68E4:
    ctx->pc = 0x800F68E4u;
    // 800F68E4: cmpwi   r11, 0
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

label_800F68E8:
    ctx->pc = 0x800F68E8u;
    // 800F68E8: bc    12, 2, 0x800F68F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F68F0;
        }
    }

label_800F68EC:
    ctx->pc = 0x800F68ECu;
    ctx->downcount -= 1;
    // 800F68EC: addi    r10, r11, -36
    ctx->gpr[10] = ctx->gpr[11] + (u32)(s32)(-36);

label_800F68F0:
    ctx->pc = 0x800F68F0u;
    ctx->downcount -= 9;
    // 800F68F0: lwz     r11, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F68F4:
    ctx->pc = 0x800F68F4u;
    // 800F68F4: rlwinm r9, r3, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_800F68F8:
    ctx->pc = 0x800F68F8u;
    // 800F68F8: lfsx    f1, r9, r11
    if (!ppc_fp_available_inline(ctx, 0x800F68F8u)) return;
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800F68FC:
    ctx->pc = 0x800F68FCu;
    // 800F68FC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6900:
    ctx->pc = 0x800F6900u;
    // 800F6900: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6904:
    ctx->pc = 0x800F6904u;
    // 800F6904: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800F6908:
    ctx->pc = 0x800F6908u;
    // 800F6908: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F690C:
    ctx->pc = 0x800F690Cu;
    // 800F690C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6910:
    ctx->pc = 0x800F6910u;
    ctx->downcount -= 9;
    // 800F6910: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6914:
    ctx->pc = 0x800F6914u;
    // 800F6914: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6918:
    ctx->pc = 0x800F6918u;
    // 800F6918: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800F691C:
    ctx->pc = 0x800F691Cu;
    // 800F691C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6920:
    ctx->pc = 0x800F6920u;
    // 800F6920: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6924:
    ctx->pc = 0x800F6924u;
    // 800F6924: lwz     r9, 436(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(436);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6928:
    ctx->pc = 0x800F6928u;
    // 800F6928: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800F692C:
    ctx->pc = 0x800F692Cu;
    // 800F692C: cmpwi   r9, 0
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

label_800F6930:
    ctx->pc = 0x800F6930u;
    // 800F6930: bc    12, 2, 0x800F6938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6938;
        }
    }

label_800F6934:
    ctx->pc = 0x800F6934u;
    ctx->downcount -= 1;
    // 800F6934: addi    r3, r9, -36
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(-36);

label_800F6938:
    ctx->pc = 0x800F6938u;
    ctx->downcount -= 3;
    // 800F6938: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_800F693C:
    ctx->pc = 0x800F693Cu;
    // 800F693C: addi    r4, r4, -6380
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-6380);

label_800F6940:
    ctx->pc = 0x800F6940u;
    // 800F6940: bl      0x801E7A84
    {
            ctx->lr = 0x800F6944u;
            ctx->pc = 0x801E7A84u;
            return;
    }

label_800F6944:
    ctx->pc = 0x800F6944u;
    ctx->downcount -= 4;
    // 800F6944: lwz     r11, 436(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(436);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F6948:
    ctx->pc = 0x800F6948u;
    // 800F6948: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_800F694C:
    ctx->pc = 0x800F694Cu;
    // 800F694C: cmpwi   r11, 0
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

label_800F6950:
    ctx->pc = 0x800F6950u;
    // 800F6950: bc    12, 2, 0x800F6958
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6958;
        }
    }

label_800F6954:
    ctx->pc = 0x800F6954u;
    ctx->downcount -= 1;
    // 800F6954: addi    r10, r11, -36
    ctx->gpr[10] = ctx->gpr[11] + (u32)(s32)(-36);

label_800F6958:
    ctx->pc = 0x800F6958u;
    ctx->downcount -= 9;
    // 800F6958: lwz     r11, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F695C:
    ctx->pc = 0x800F695Cu;
    // 800F695C: rlwinm r9, r3, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_800F6960:
    ctx->pc = 0x800F6960u;
    // 800F6960: lfsx    f1, r9, r11
    if (!ppc_fp_available_inline(ctx, 0x800F6960u)) return;
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800F6964:
    ctx->pc = 0x800F6964u;
    // 800F6964: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6968:
    ctx->pc = 0x800F6968u;
    // 800F6968: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F696C:
    ctx->pc = 0x800F696Cu;
    // 800F696C: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800F6970:
    ctx->pc = 0x800F6970u;
    // 800F6970: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F6974:
    ctx->pc = 0x800F6974u;
    // 800F6974: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6978:
    ctx->pc = 0x800F6978u;
    ctx->downcount -= 23;
    // 800F6978: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F697C:
    ctx->pc = 0x800F697Cu;
    // 800F697C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6980:
    ctx->pc = 0x800F6980u;
    // 800F6980: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F6984:
    ctx->pc = 0x800F6984u;
    // 800F6984: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6988:
    ctx->pc = 0x800F6988u;
    // 800F6988: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F698C:
    ctx->pc = 0x800F698Cu;
    // 800F698C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6990:
    ctx->pc = 0x800F6990u;
    // 800F6990: lwz     r11, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F6994:
    ctx->pc = 0x800F6994u;
    // 800F6994: addi    r9, r9, -6320
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-6320);

label_800F6998:
    ctx->pc = 0x800F6998u;
    // 800F6998: stw     r9, 108(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F699C:
    ctx->pc = 0x800F699Cu;
    // 800F699C: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800F69A0:
    ctx->pc = 0x800F69A0u;
    // 800F69A0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800F69A4:
    ctx->pc = 0x800F69A4u;
    // 800F69A4: lwz     r3, 52(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(52);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F69A8:
    ctx->pc = 0x800F69A8u;
    // 800F69A8: bl      0x800FB398
    {
            ctx->lr = 0x800F69ACu;
            ctx->pc = 0x800FB398u;
            return;
    }

label_800F69AC:
    ctx->pc = 0x800F69ACu;
    ctx->downcount -= 3;
    // 800F69AC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800F69B0:
    ctx->pc = 0x800F69B0u;
    // 800F69B0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F69B4:
    ctx->pc = 0x800F69B4u;
    // 800F69B4: bl      0x801FEF28
    {
            ctx->lr = 0x800F69B8u;
            ctx->pc = 0x801FEF28u;
            return;
    }

label_800F69B8:
    ctx->pc = 0x800F69B8u;
    ctx->downcount -= 16;
    // 800F69B8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F69BC:
    ctx->pc = 0x800F69BCu;
    // 800F69BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F69C0:
    ctx->pc = 0x800F69C0u;
    // 800F69C0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F69C4:
    ctx->pc = 0x800F69C4u;
    // 800F69C4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F69C8:
    ctx->pc = 0x800F69C8u;
    // 800F69C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F69CC:
    ctx->pc = 0x800F69CCu;
    ctx->downcount -= 7;
    // 800F69CC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F69D0:
    ctx->pc = 0x800F69D0u;
    // 800F69D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F69D4:
    ctx->pc = 0x800F69D4u;
    // 800F69D4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F69D8:
    ctx->pc = 0x800F69D8u;
    // 800F69D8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800F69DC:
    ctx->pc = 0x800F69DCu;
    // 800F69DC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800F69E0:
    ctx->pc = 0x800F69E0u;
    // 800F69E0: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_800F69E4:
    ctx->pc = 0x800F69E4u;
    // 800F69E4: bl      0x800F672C
    {
            ctx->lr = 0x800F69E8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F672Cu;
                return;
            }
            goto label_800F672C;
    }

label_800F69E8:
    ctx->pc = 0x800F69E8u;
    ctx->downcount -= 5;
    // 800F69E8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F69EC:
    ctx->pc = 0x800F69ECu;
    // 800F69EC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F69F0:
    ctx->pc = 0x800F69F0u;
    // 800F69F0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F69F4:
    ctx->pc = 0x800F69F4u;
    // 800F69F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F69F8:
    ctx->pc = 0x800F69F8u;
    ctx->downcount -= 16;
    // 800F69F8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F69FC:
    ctx->pc = 0x800F69FCu;
    // 800F69FC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6A00:
    ctx->pc = 0x800F6A00u;
    // 800F6A00: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F6A04:
    ctx->pc = 0x800F6A04u;
    // 800F6A04: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6A08:
    ctx->pc = 0x800F6A08u;
    // 800F6A08: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6A0C:
    ctx->pc = 0x800F6A0Cu;
    // 800F6A0C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800F6A10:
    ctx->pc = 0x800F6A10u;
    ctx->downcount -= 11;
    // 800F6A10: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6A14:
    ctx->pc = 0x800F6A14u;
    // 800F6A14: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6A18:
    // 800F6A18: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_800F6A1C:
    ctx->pc = 0x800F6A1Cu;
    // 800F6A1C: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F6A20:
    // 800F6A20: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_800F6A24:
    // 800F6A24: cmplw   r10, r11
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

label_800F6A28:
    // 800F6A28: bc    12, 0, 0x800F6A50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6A50;
        }
    }

label_800F6A2C:
    ctx->downcount -= 3;
    // 800F6A2C: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F6A30:
    ctx->pc = 0x800F6A30u;
    // 800F6A30: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6A34:
    // 800F6A34: b       0x800F6B28
    {
            goto label_800F6B28;
    }

label_800F6A38:
    ctx->pc = 0x800F6A38u;
    ctx->downcount -= 6;
    // 800F6A38: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6A3C:
    // 800F6A3C: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F6A40:
    ctx->pc = 0x800F6A40u;
    // 800F6A40: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6A44:
    ctx->pc = 0x800F6A44u;
    // 800F6A44: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6A48:
    ctx->pc = 0x800F6A48u;
    // 800F6A48: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800F6A4C:
    // 800F6A4C: b       0x800F6A10
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F6A10u;
                return;
            }
            goto label_800F6A10;
    }

label_800F6A50:
    ctx->downcount -= 2;
    // 800F6A50: cmplw   r10, r30
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

label_800F6A54:
    // 800F6A54: bc    12, 0, 0x800F6A74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6A74;
        }
    }

label_800F6A58:
    ctx->downcount -= 50;
    // 800F6A58: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_800F6A5C:
    ctx->pc = 0x800F6A5Cu;
    // 800F6A5C: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6A60:
    // 800F6A60: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_800F6A64:
    ctx->pc = 0x800F6A64u;
    // 800F6A64: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800F6A68:
    // 800F6A68: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F6A6C:
    ctx->pc = 0x800F6A6Cu;
    // 800F6A6C: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6A70:
    // 800F6A70: b       0x800F6B28
    {
            goto label_800F6B28;
    }

label_800F6A74:
    ctx->pc = 0x800F6A74u;
    ctx->downcount -= 8;
    // 800F6A74: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6A78:
    // 800F6A78: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F6A7C:
    // 800F6A7C: cmpwi   r10, 0
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

label_800F6A80:
    // 800F6A80: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_800F6A84:
    // 800F6A84: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_800F6A88:
    // 800F6A88: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_800F6A8C:
    // 800F6A8C: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_800F6A90:
    // 800F6A90: bc    12, 2, 0x800F6AB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6AB0;
        }
    }

label_800F6A94:
    ctx->downcount -= 7;
    // 800F6A94: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_800F6A98:
    // 800F6A98: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_800F6A9C:
    // 800F6A9C: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F6AA0:
    // 800F6AA0: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_800F6AA4:
    ctx->pc = 0x800F6AA4u;
    // 800F6AA4: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F6AA8:
    ctx->pc = 0x800F6AA8u;
    // 800F6AA8: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F6AAC:
    ctx->pc = 0x800F6AACu;
    // 800F6AAC: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800F6AB0:
    ctx->downcount -= 2;
    // 800F6AB0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F6AB4:
    // 800F6AB4: bl      0x80281C60
    {
            ctx->lr = 0x800F6AB8u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F6AB8:
    ctx->downcount -= 3;
    // 800F6AB8: cmpwi   r3, 0
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

label_800F6ABC:
    ctx->pc = 0x800F6ABCu;
    // 800F6ABC: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800F6AC0:
    // 800F6AC0: bc    4, 2, 0x800F6B0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F6B0C;
        }
    }

label_800F6AC4:
    ctx->downcount -= 3;
    // 800F6AC4: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6AC8:
    // 800F6AC8: cmplwi  r11, 0x0080
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

label_800F6ACC:
    // 800F6ACC: bc    12, 1, 0x800F6AF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6AF8;
        }
    }

label_800F6AD0:
    ctx->downcount -= 2;
    // 800F6AD0: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_800F6AD4:
    // 800F6AD4: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_800F6AD8:
    ctx->downcount -= 5;
    // 800F6AD8: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_800F6ADC:
    // 800F6ADC: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F6AE0:
    ctx->pc = 0x800F6AE0u;
    // 800F6AE0: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800F6AE4:
    // 800F6AE4: cmpwi   r10, 0
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

label_800F6AE8:
    // 800F6AE8: bc    4, 2, 0x800F6A38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F6A38u;
                return;
            }
            goto label_800F6A38;
        }
    }

label_800F6AEC:
    ctx->downcount -= 3;
    // 800F6AEC: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_800F6AF0:
    // 800F6AF0: cmplwi  r11, 0x0080
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

label_800F6AF4:
    // 800F6AF4: bc    4, 1, 0x800F6AD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F6AD8u;
                return;
            }
            goto label_800F6AD8;
        }
    }

label_800F6AF8:
    ctx->downcount -= 4;
    // 800F6AF8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F6AFC:
    // 800F6AFC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F6B00:
    ctx->pc = 0x800F6B00u;
    // 800F6B00: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6B04:
    // 800F6B04: bl      0x80281C60
    {
            ctx->lr = 0x800F6B08u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_800F6B08:
    ctx->pc = 0x800F6B08u;
    ctx->downcount -= 1;
    // 800F6B08: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800F6B0C:
    ctx->pc = 0x800F6B0Cu;
    ctx->downcount -= 7;
    // 800F6B0C: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6B10:
    ctx->pc = 0x800F6B10u;
    // 800F6B10: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6B14:
    // 800F6B14: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800F6B18:
    // 800F6B18: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800F6B1C:
    ctx->pc = 0x800F6B1Cu;
    // 800F6B1C: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6B20:
    ctx->pc = 0x800F6B20u;
    // 800F6B20: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6B24:
    // 800F6B24: b       0x800F6A10
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F6A10u;
                return;
            }
            goto label_800F6A10;
    }

label_800F6B28:
    ctx->pc = 0x800F6B28u;
    ctx->downcount -= 16;
    // 800F6B28: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6B2C:
    ctx->pc = 0x800F6B2Cu;
    // 800F6B2C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6B30:
    ctx->pc = 0x800F6B30u;
    // 800F6B30: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F6B34:
    ctx->pc = 0x800F6B34u;
    // 800F6B34: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F6B38:
    ctx->pc = 0x800F6B38u;
    // 800F6B38: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6B3C:
    ctx->pc = 0x800F6B3Cu;
    ctx->downcount -= 21;
    // 800F6B3C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6B40:
    ctx->pc = 0x800F6B40u;
    // 800F6B40: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6B44:
    ctx->pc = 0x800F6B44u;
    // 800F6B44: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F6B48:
    ctx->pc = 0x800F6B48u;
    // 800F6B48: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6B4C:
    ctx->pc = 0x800F6B4Cu;
    // 800F6B4C: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_800F6B50:
    ctx->pc = 0x800F6B50u;
    // 800F6B50: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_800F6B54:
    ctx->pc = 0x800F6B54u;
    // 800F6B54: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_800F6B58:
    ctx->pc = 0x800F6B58u;
    // 800F6B58: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F6B5C:
    ctx->pc = 0x800F6B5Cu;
    // 800F6B5C: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800F6B60:
    ctx->pc = 0x800F6B60u;
    // 800F6B60: cmpwi   r30, 0
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

label_800F6B64:
    ctx->pc = 0x800F6B64u;
    // 800F6B64: bc    12, 2, 0x800F6B74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6B74;
        }
    }

label_800F6B68:
    ctx->pc = 0x800F6B68u;
    ctx->downcount -= 3;
    // 800F6B68: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6B6C:
    ctx->pc = 0x800F6B6Cu;
    // 800F6B6C: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6B70:
    ctx->pc = 0x800F6B70u;
    // 800F6B70: b       0x800F6BF4
    {
            goto label_800F6BF4;
    }

label_800F6B74:
    ctx->pc = 0x800F6B74u;
    ctx->downcount -= 7;
    // 800F6B74: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_800F6B78:
    ctx->pc = 0x800F6B78u;
    // 800F6B78: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_800F6B7C:
    ctx->pc = 0x800F6B7Cu;
    // 800F6B7C: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_800F6B80:
    ctx->pc = 0x800F6B80u;
    // 800F6B80: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6B84:
    ctx->pc = 0x800F6B84u;
    // 800F6B84: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F6B88:
    ctx->pc = 0x800F6B88u;
    // 800F6B88: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_800F6B8C:
    ctx->pc = 0x800F6B8Cu;
    // 800F6B8C: bl      0x80003EE0
    {
            ctx->lr = 0x800F6B90u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_800F6B90:
    ctx->pc = 0x800F6B90u;
    ctx->downcount -= 3;
    // 800F6B90: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6B94:
    ctx->pc = 0x800F6B94u;
    // 800F6B94: cmpwi   r9, 1
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

label_800F6B98:
    ctx->pc = 0x800F6B98u;
    // 800F6B98: bc    12, 2, 0x800F6BF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6BF0;
        }
    }

label_800F6B9C:
    ctx->pc = 0x800F6B9Cu;
    ctx->downcount -= 9;
    // 800F6B9C: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_800F6BA0:
    ctx->pc = 0x800F6BA0u;
    // 800F6BA0: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800F6BA4:
    ctx->pc = 0x800F6BA4u;
    // 800F6BA4: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_800F6BA8:
    ctx->pc = 0x800F6BA8u;
    // 800F6BA8: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800F6BAC:
    ctx->pc = 0x800F6BACu;
    // 800F6BAC: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F6BB0:
    ctx->pc = 0x800F6BB0u;
    // 800F6BB0: cmpwi   r9, 2
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

label_800F6BB4:
    ctx->pc = 0x800F6BB4u;
    // 800F6BB4: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_800F6BB8:
    ctx->pc = 0x800F6BB8u;
    // 800F6BB8: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800F6BBC:
    ctx->pc = 0x800F6BBCu;
    // 800F6BBC: bc    4, 2, 0x800F6BC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F6BC8;
        }
    }

label_800F6BC0:
    ctx->pc = 0x800F6BC0u;
    ctx->downcount -= 2;
    // 800F6BC0: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800F6BC4:
    ctx->pc = 0x800F6BC4u;
    // 800F6BC4: b       0x800F6BF0
    {
            goto label_800F6BF0;
    }

label_800F6BC8:
    loop_800F6BC8(ctx);
    if (ctx->pc == 0x800F6BE8u) goto label_800F6BE8;
    return;
label_800F6BCC:
    // 800F6BCC: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_800F6BD0:
    // 800F6BD0: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800F6BD4:
    ctx->pc = 0x800F6BD4u;
    // 800F6BD4: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6BD8:
    // 800F6BD8: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800F6BDC:
    // 800F6BDC: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_800F6BE0:
    // 800F6BE0: cmpw    r9, r8
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

label_800F6BE4:
    // 800F6BE4: bc    4, 2, 0x800F6BC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F6BC8u;
                return;
            }
            goto label_800F6BC8;
        }
    }

label_800F6BE8:
    ctx->pc = 0x800F6BE8u;
    ctx->downcount -= 2;
    // 800F6BE8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F6BEC:
    ctx->pc = 0x800F6BECu;
    // 800F6BEC: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6BF0:
    ctx->pc = 0x800F6BF0u;
    ctx->downcount -= 1;
    // 800F6BF0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6BF4:
    ctx->pc = 0x800F6BF4u;
    ctx->downcount -= 17;
    // 800F6BF4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6BF8:
    ctx->pc = 0x800F6BF8u;
    // 800F6BF8: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6BFC:
    ctx->pc = 0x800F6BFCu;
    // 800F6BFC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6C00:
    ctx->pc = 0x800F6C00u;
    // 800F6C00: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F6C04:
    ctx->pc = 0x800F6C04u;
    // 800F6C04: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_800F6C08:
    ctx->pc = 0x800F6C08u;
    // 800F6C08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6C0C:
    ctx->pc = 0x800F6C0Cu;
    ctx->downcount -= 7;
    // 800F6C0C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6C10:
    ctx->pc = 0x800F6C10u;
    // 800F6C10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6C14:
    ctx->pc = 0x800F6C14u;
    // 800F6C14: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6C18:
    ctx->pc = 0x800F6C18u;
    // 800F6C18: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800F6C1C:
    ctx->pc = 0x800F6C1Cu;
    // 800F6C1C: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_800F6C20:
    ctx->pc = 0x800F6C20u;
    // 800F6C20: cmpw    r4, r0
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

label_800F6C24:
    ctx->pc = 0x800F6C24u;
    // 800F6C24: bc    4, 2, 0x800F6C6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F6C6C;
        }
    }

label_800F6C28:
    ctx->pc = 0x800F6C28u;
    ctx->downcount -= 2;
    // 800F6C28: cmpwi   r3, 0
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

label_800F6C2C:
    ctx->pc = 0x800F6C2Cu;
    // 800F6C2C: bc    12, 2, 0x800F6C6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6C6C;
        }
    }

label_800F6C30:
    ctx->pc = 0x800F6C30u;
    ctx->downcount -= 5;
    // 800F6C30: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_800F6C34:
    ctx->pc = 0x800F6C34u;
    // 800F6C34: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_800F6C38:
    ctx->pc = 0x800F6C38u;
    // 800F6C38: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_800F6C3C:
    ctx->pc = 0x800F6C3Cu;
    // 800F6C3C: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_800F6C40:
    ctx->pc = 0x800F6C40u;
    // 800F6C40: bl      0x80252AF0
    {
            ctx->lr = 0x800F6C44u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6C44:
    ctx->pc = 0x800F6C44u;
    ctx->downcount -= 5;
    // 800F6C44: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_800F6C48:
    ctx->pc = 0x800F6C48u;
    // 800F6C48: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_800F6C4C:
    ctx->pc = 0x800F6C4Cu;
    // 800F6C4C: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_800F6C50:
    ctx->pc = 0x800F6C50u;
    // 800F6C50: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F6C54:
    ctx->pc = 0x800F6C54u;
    // 800F6C54: bl      0x80252AF0
    {
            ctx->lr = 0x800F6C58u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6C58:
    ctx->pc = 0x800F6C58u;
    ctx->downcount -= 5;
    // 800F6C58: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_800F6C5C:
    ctx->pc = 0x800F6C5Cu;
    // 800F6C5C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_800F6C60:
    ctx->pc = 0x800F6C60u;
    // 800F6C60: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_800F6C64:
    ctx->pc = 0x800F6C64u;
    // 800F6C64: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800F6C68:
    ctx->pc = 0x800F6C68u;
    // 800F6C68: bl      0x80252AF0
    {
            ctx->lr = 0x800F6C6Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_800F6C6C:
    ctx->pc = 0x800F6C6Cu;
    ctx->downcount -= 5;
    // 800F6C6C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6C70:
    ctx->pc = 0x800F6C70u;
    // 800F6C70: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6C74:
    ctx->pc = 0x800F6C74u;
    // 800F6C74: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F6C78:
    ctx->pc = 0x800F6C78u;
    // 800F6C78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6C7C:
    ctx->pc = 0x800F6C7Cu;
    ctx->downcount -= 16;
    // 800F6C7C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6C80:
    ctx->pc = 0x800F6C80u;
    // 800F6C80: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6C84:
    ctx->pc = 0x800F6C84u;
    // 800F6C84: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F6C88:
    ctx->pc = 0x800F6C88u;
    // 800F6C88: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6C8C:
    ctx->pc = 0x800F6C8Cu;
    // 800F6C8C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6C90:
    ctx->pc = 0x800F6C90u;
    // 800F6C90: bl      0x801D613C
    {
            ctx->lr = 0x800F6C94u;
            ctx->pc = 0x801D613Cu;
            return;
    }

label_800F6C94:
    ctx->pc = 0x800F6C94u;
    ctx->downcount -= 20;
    // 800F6C94: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F6C98:
    ctx->pc = 0x800F6C98u;
    // 800F6C98: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6C9C:
    ctx->pc = 0x800F6C9Cu;
    // 800F6C9C: addi    r9, r9, -6008
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-6008);

label_800F6CA0:
    ctx->pc = 0x800F6CA0u;
    // 800F6CA0: stw     r9, 108(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6CA4:
    ctx->pc = 0x800F6CA4u;
    // 800F6CA4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6CA8:
    ctx->pc = 0x800F6CA8u;
    // 800F6CA8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6CAC:
    ctx->pc = 0x800F6CACu;
    // 800F6CAC: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F6CB0:
    ctx->pc = 0x800F6CB0u;
    // 800F6CB0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800F6CB4:
    ctx->pc = 0x800F6CB4u;
    // 800F6CB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6CB8:
    ctx->pc = 0x800F6CB8u;
    ctx->downcount -= 8;
    // 800F6CB8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6CBC:
    ctx->pc = 0x800F6CBCu;
    // 800F6CBC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6CC0:
    ctx->pc = 0x800F6CC0u;
    // 800F6CC0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6CC4:
    ctx->pc = 0x800F6CC4u;
    // 800F6CC4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F6CC8:
    ctx->pc = 0x800F6CC8u;
    // 800F6CC8: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6CCC:
    ctx->pc = 0x800F6CCCu;
    // 800F6CCC: addi    r9, r9, -6008
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-6008);

label_800F6CD0:
    ctx->pc = 0x800F6CD0u;
    // 800F6CD0: stw     r9, 108(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6CD4:
    ctx->pc = 0x800F6CD4u;
    // 800F6CD4: bl      0x801D61A0
    {
            ctx->lr = 0x800F6CD8u;
            ctx->pc = 0x801D61A0u;
            return;
    }

label_800F6CD8:
    ctx->pc = 0x800F6CD8u;
    ctx->downcount -= 5;
    // 800F6CD8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6CDC:
    ctx->pc = 0x800F6CDCu;
    // 800F6CDC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6CE0:
    ctx->pc = 0x800F6CE0u;
    // 800F6CE0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F6CE4:
    ctx->pc = 0x800F6CE4u;
    // 800F6CE4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6CE8:
    ctx->pc = 0x800F6CE8u;
    ctx->downcount -= 21;
    // 800F6CE8: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6CEC:
    ctx->pc = 0x800F6CECu;
    // 800F6CEC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6CF0:
    ctx->pc = 0x800F6CF0u;
    // 800F6CF0: stfd     f30, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6CF0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_800F6CF4:
    ctx->pc = 0x800F6CF4u;
    // 800F6CF4: stfd     f31, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6CF4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F6CF8:
    ctx->pc = 0x800F6CF8u;
    // 800F6CF8: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F6CFC:
    ctx->pc = 0x800F6CFCu;
    // 800F6CFC: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6D00:
    ctx->pc = 0x800F6D00u;
    // 800F6D00: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F6D04:
    ctx->pc = 0x800F6D04u;
    // 800F6D04: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6D08:
    ctx->pc = 0x800F6D08u;
    // 800F6D08: lfs     f30, -5736(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F6D08u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-5736);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_800F6D0C:
    ctx->pc = 0x800F6D0Cu;
    // 800F6D0C: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x800F6D0Cu)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_800F6D10:
    ctx->pc = 0x800F6D10u;
    // 800F6D10: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_800F6D14:
    ctx->downcount -= 2;
    // 800F6D14: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F6D18:
    // 800F6D18: bl      0x80106ED0
    {
            ctx->lr = 0x800F6D1Cu;
            ctx->pc = 0x80106ED0u;
            return;
    }

label_800F6D1C:
    ctx->pc = 0x800F6D1Cu;
    ctx->downcount -= 3;
    // 800F6D1C: lfs     f0, 60(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F6D1Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F6D20:
    ctx->pc = 0x800F6D20u;
    // 800F6D20: fcmpu   cr0, f0, f30
    if (!ppc_fp_available_inline(ctx, 0x800F6D20u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[30], false);

label_800F6D24:
    // 800F6D24: bc    12, 1, 0x800F6D40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6D40;
        }
    }

label_800F6D28:
    ctx->downcount -= 3;
    // 800F6D28: cmpwi   r31, 3
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800F6D2C:
    // 800F6D2C: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_800F6D30:
    // 800F6D30: bc    4, 2, 0x800F6D14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F6D14u;
                return;
            }
            goto label_800F6D14;
        }
    }

label_800F6D34:
    ctx->pc = 0x800F6D34u;
    ctx->downcount -= 3;
    // 800F6D34: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F6D38:
    ctx->pc = 0x800F6D38u;
    // 800F6D38: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x800F6D38u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_800F6D3C:
    ctx->pc = 0x800F6D3Cu;
    // 800F6D3C: bl      0x801D55B4
    {
            ctx->lr = 0x800F6D40u;
            ctx->pc = 0x801D55B4u;
            return;
    }

label_800F6D40:
    ctx->pc = 0x800F6D40u;
    ctx->downcount -= 18;
    // 800F6D40: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6D44:
    ctx->pc = 0x800F6D44u;
    // 800F6D44: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6D48:
    ctx->pc = 0x800F6D48u;
    // 800F6D48: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F6D4C:
    ctx->pc = 0x800F6D4Cu;
    // 800F6D4C: lfd     f30, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6D4Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F6D50:
    ctx->pc = 0x800F6D50u;
    // 800F6D50: lfd     f31, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6D50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F6D54:
    ctx->pc = 0x800F6D54u;
    // 800F6D54: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_800F6D58:
    ctx->pc = 0x800F6D58u;
    // 800F6D58: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6D5C:
    ctx->pc = 0x800F6D5Cu;
    ctx->downcount -= 7;
    // 800F6D5C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6D60:
    ctx->pc = 0x800F6D60u;
    // 800F6D60: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6D64:
    ctx->pc = 0x800F6D64u;
    // 800F6D64: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6D68:
    ctx->pc = 0x800F6D68u;
    // 800F6D68: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800F6D6C:
    ctx->pc = 0x800F6D6Cu;
    // 800F6D6C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800F6D70:
    ctx->pc = 0x800F6D70u;
    // 800F6D70: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_800F6D74:
    ctx->pc = 0x800F6D74u;
    // 800F6D74: bl      0x800F6C0C
    {
            ctx->lr = 0x800F6D78u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F6C0Cu;
                return;
            }
            goto label_800F6C0C;
    }

label_800F6D78:
    ctx->pc = 0x800F6D78u;
    ctx->downcount -= 5;
    // 800F6D78: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6D7C:
    ctx->pc = 0x800F6D7Cu;
    // 800F6D7C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F6D80:
    ctx->pc = 0x800F6D80u;
    // 800F6D80: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800F6D84:
    ctx->pc = 0x800F6D84u;
    // 800F6D84: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F6D88:
    ctx->pc = 0x800F6D88u;
    ctx->downcount -= 23;
    // 800F6D88: stwu     r1, -144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-144);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F6D8C:
    ctx->pc = 0x800F6D8Cu;
    // 800F6D8C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F6D90:
    ctx->pc = 0x800F6D90u;
    // 800F6D90: stfd     f31, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6D90u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F6D94:
    ctx->pc = 0x800F6D94u;
    // 800F6D94: stmw     r26, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F6D98:
    ctx->pc = 0x800F6D98u;
    // 800F6D98: stw     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6D9C:
    ctx->pc = 0x800F6D9Cu;
    // 800F6D9C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F6DA0:
    ctx->pc = 0x800F6DA0u;
    // 800F6DA0: addi    r27, r1, 56
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(56);

label_800F6DA4:
    ctx->pc = 0x800F6DA4u;
    // 800F6DA4: addi    r31, r29, 124
    ctx->gpr[31] = ctx->gpr[29] + (u32)(s32)(124);

label_800F6DA8:
    ctx->pc = 0x800F6DA8u;
    // 800F6DA8: addi    r3, r29, 24
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(24);

label_800F6DAC:
    ctx->pc = 0x800F6DACu;
    // 800F6DAC: addi    r4, r29, 56
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(56);

label_800F6DB0:
    ctx->pc = 0x800F6DB0u;
    // 800F6DB0: or   r5, r31, r31
    {
        ctx->gpr[5] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F6DB4:
    ctx->pc = 0x800F6DB4u;
    // 800F6DB4: or   r6, r27, r27
    {
        ctx->gpr[6] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800F6DB8:
    ctx->pc = 0x800F6DB8u;
    // 800F6DB8: bl      0x802837C8
    {
            ctx->lr = 0x800F6DBCu;
            ctx->pc = 0x802837C8u;
            return;
    }

label_800F6DBC:
    ctx->pc = 0x800F6DBCu;
    ctx->downcount -= 10;
    // 800F6DBC: lfs     f7, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6DBCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[7] = value;
        ctx->ps1[7] = value;
    }

label_800F6DC0:
    ctx->pc = 0x800F6DC0u;
    // 800F6DC0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F6DC4:
    ctx->pc = 0x800F6DC4u;
    // 800F6DC4: lfs     f8, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6DC4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_800F6DC8:
    ctx->pc = 0x800F6DC8u;
    // 800F6DC8: lfs     f9, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6DC8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F6DCC:
    ctx->pc = 0x800F6DCCu;
    // 800F6DCC: fmuls   f0, f7, f7
    if (!ppc_fp_available_inline(ctx, 0x800F6DCCu)) return;
    ppc_fmuls(ctx, 0, 7, 7);

label_800F6DD0:
    ctx->pc = 0x800F6DD0u;
    // 800F6DD0: lfs     f31, -5716(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F6DD0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-5716);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F6DD4:
    ctx->pc = 0x800F6DD4u;
    // 800F6DD4: fmadds f0, f8, f8, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6DD4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[8], ctx->fpr[8], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F6DD8:
    ctx->pc = 0x800F6DD8u;
    // 800F6DD8: fmadds f10, f9, f9, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6DD8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[9], ctx->fpr[9], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[10] = ctx->ps1[10] = result;
    }

label_800F6DDC:
    ctx->pc = 0x800F6DDCu;
    // 800F6DDC: fcmpu   cr0, f10, f31
    if (!ppc_fp_available_inline(ctx, 0x800F6DDCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[10], ctx->fpr[31], false);

label_800F6DE0:
    ctx->pc = 0x800F6DE0u;
    // 800F6DE0: bc    12, 2, 0x800F6E18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6E18;
        }
    }

label_800F6DE4:
    ctx->pc = 0x800F6DE4u;
    ctx->downcount -= 13;
    // 800F6DE4: frsqrte    f13, f10
    if (!ppc_fp_available_inline(ctx, 0x800F6DE4u)) return;
    { f64 result; if (ppc_frsqrte(ctx, ctx->fpr[10], &result)) ctx->fpr[13] = result; }

label_800F6DE8:
    ctx->pc = 0x800F6DE8u;
    // 800F6DE8: lfs     f12, -29688(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F6DE8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-29688);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F6DEC:
    ctx->pc = 0x800F6DECu;
    // 800F6DEC: lfs     f11, -29676(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F6DECu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-29676);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F6DF0:
    ctx->pc = 0x800F6DF0u;
    // 800F6DF0: fmuls   f0, f13, f13
    if (!ppc_fp_available_inline(ctx, 0x800F6DF0u)) return;
    ppc_fmuls(ctx, 0, 13, 13);

label_800F6DF4:
    ctx->pc = 0x800F6DF4u;
    // 800F6DF4: fmuls   f13, f13, f12
    if (!ppc_fp_available_inline(ctx, 0x800F6DF4u)) return;
    ppc_fmuls(ctx, 13, 13, 12);

label_800F6DF8:
    ctx->pc = 0x800F6DF8u;
    // 800F6DF8: fnmsubs f0, f0, f10, f11
    if (!ppc_fp_available_inline(ctx, 0x800F6DF8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[10], ctx->fpr[11], true, true, true, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F6DFC:
    ctx->pc = 0x800F6DFCu;
    // 800F6DFC: fmuls   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F6DFCu)) return;
    ppc_fmuls(ctx, 0, 0, 13);

label_800F6E00:
    ctx->pc = 0x800F6E00u;
    // 800F6E00: fmuls   f12, f9, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6E00u)) return;
    ppc_fmuls(ctx, 12, 9, 0);

label_800F6E04:
    ctx->pc = 0x800F6E04u;
    // 800F6E04: fmuls   f13, f8, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6E04u)) return;
    ppc_fmuls(ctx, 13, 8, 0);

label_800F6E08:
    ctx->pc = 0x800F6E08u;
    // 800F6E08: stfs     f12, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6E08u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F6E0C:
    ctx->pc = 0x800F6E0Cu;
    // 800F6E0C: fmuls   f0, f7, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6E0Cu)) return;
    ppc_fmuls(ctx, 0, 7, 0);

label_800F6E10:
    ctx->pc = 0x800F6E10u;
    // 800F6E10: stfs     f13, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6E10u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F6E14:
    ctx->pc = 0x800F6E14u;
    // 800F6E14: stfs     f0, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6E14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F6E18:
    ctx->pc = 0x800F6E18u;
    ctx->downcount -= 53;
    // 800F6E18: addi    r30, r29, 88
    ctx->gpr[30] = ctx->gpr[29] + (u32)(s32)(88);

label_800F6E1C:
    ctx->pc = 0x800F6E1Cu;
    // 800F6E1C: lfs     f8, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6E1Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_800F6E20:
    ctx->pc = 0x800F6E20u;
    // 800F6E20: lfs     f12, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F6E20u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F6E24:
    ctx->pc = 0x800F6E24u;
    // 800F6E24: addi    r26, r1, 72
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(72);

label_800F6E28:
    ctx->pc = 0x800F6E28u;
    // 800F6E28: lfs     f13, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F6E28u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F6E2C:
    ctx->pc = 0x800F6E2Cu;
    // 800F6E2C: addi    r28, r1, 8
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(8);

label_800F6E30:
    ctx->pc = 0x800F6E30u;
    // 800F6E30: lfs     f11, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6E30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F6E34:
    ctx->pc = 0x800F6E34u;
    // 800F6E34: addi    r3, r29, 72
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(72);

label_800F6E38:
    ctx->pc = 0x800F6E38u;
    // 800F6E38: lfs     f0, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6E38u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F6E3C:
    ctx->pc = 0x800F6E3Cu;
    // 800F6E3C: fmuls   f7, f13, f8
    if (!ppc_fp_available_inline(ctx, 0x800F6E3Cu)) return;
    ppc_fmuls(ctx, 7, 13, 8);

label_800F6E40:
    ctx->pc = 0x800F6E40u;
    // 800F6E40: fmuls   f10, f12, f11
    if (!ppc_fp_available_inline(ctx, 0x800F6E40u)) return;
    ppc_fmuls(ctx, 10, 12, 11);

label_800F6E44:
    ctx->pc = 0x800F6E44u;
    // 800F6E44: lfs     f9, 88(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F6E44u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(88);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F6E48:
    ctx->pc = 0x800F6E48u;
    // 800F6E48: lfs     f5, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F6E48u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_800F6E4C:
    ctx->pc = 0x800F6E4Cu;
    // 800F6E4C: fmsubs f13, f13, f0, f10
    if (!ppc_fp_available_inline(ctx, 0x800F6E4Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[13], ctx->fpr[0], ctx->fpr[10], true, true, false, &result))
            ctx->fpr[13] = ctx->ps1[13] = result;
    }

label_800F6E50:
    ctx->pc = 0x800F6E50u;
    // 800F6E50: stfs     f13, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6E50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F6E54:
    ctx->pc = 0x800F6E54u;
    // 800F6E54: fmuls   f0, f9, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6E54u)) return;
    ppc_fmuls(ctx, 0, 9, 0);

label_800F6E58:
    ctx->pc = 0x800F6E58u;
    // 800F6E58: fmsubs f12, f12, f8, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6E58u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[12], ctx->fpr[8], ctx->fpr[0], true, true, false, &result))
            ctx->fpr[12] = ctx->ps1[12] = result;
    }

label_800F6E5C:
    ctx->pc = 0x800F6E5Cu;
    // 800F6E5C: addi    r4, r29, 40
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(40);

label_800F6E60:
    ctx->pc = 0x800F6E60u;
    // 800F6E60: lfs     f6, 124(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F6E60u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(124);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_800F6E64:
    ctx->pc = 0x800F6E64u;
    // 800F6E64: fmsubs f11, f9, f11, f7
    if (!ppc_fp_available_inline(ctx, 0x800F6E64u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[9], ctx->fpr[11], ctx->fpr[7], true, true, false, &result))
            ctx->fpr[11] = ctx->ps1[11] = result;
    }

label_800F6E68:
    ctx->pc = 0x800F6E68u;
    // 800F6E68: stfs     f12, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6E68u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F6E6C:
    ctx->pc = 0x800F6E6Cu;
    // 800F6E6C: or   r5, r31, r31
    {
        ctx->gpr[5] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800F6E70:
    ctx->pc = 0x800F6E70u;
    // 800F6E70: stfs     f11, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6E70u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800F6E74:
    ctx->pc = 0x800F6E74u;
    // 800F6E74: or   r6, r27, r27
    {
        ctx->gpr[6] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800F6E78:
    ctx->pc = 0x800F6E78u;
    // 800F6E78: lwz     r11, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F6E7C:
    ctx->pc = 0x800F6E7Cu;
    // 800F6E7C: lwz     r9, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6E80:
    ctx->pc = 0x800F6E80u;
    // 800F6E80: lwz     r0, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6E84:
    ctx->pc = 0x800F6E84u;
    // 800F6E84: stw     r11, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F6E88:
    ctx->pc = 0x800F6E88u;
    // 800F6E88: stw     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6E8C:
    ctx->pc = 0x800F6E8Cu;
    // 800F6E8C: stw     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6E90:
    ctx->pc = 0x800F6E90u;
    // 800F6E90: lfs     f11, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6E90u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F6E94:
    ctx->pc = 0x800F6E94u;
    // 800F6E94: lfs     f13, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6E94u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F6E98:
    ctx->pc = 0x800F6E98u;
    // 800F6E98: lfs     f10, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F6E98u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800F6E9C:
    ctx->pc = 0x800F6E9Cu;
    // 800F6E9C: fmuls   f0, f11, f5
    if (!ppc_fp_available_inline(ctx, 0x800F6E9Cu)) return;
    ppc_fmuls(ctx, 0, 11, 5);

label_800F6EA0:
    ctx->pc = 0x800F6EA0u;
    // 800F6EA0: lfs     f12, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6EA0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F6EA4:
    ctx->pc = 0x800F6EA4u;
    // 800F6EA4: fmadds f0, f13, f6, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6EA4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[13], ctx->fpr[6], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F6EA8:
    ctx->pc = 0x800F6EA8u;
    // 800F6EA8: stfs     f13, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6EA8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F6EAC:
    ctx->pc = 0x800F6EACu;
    // 800F6EAC: fnmadds f0, f12, f10, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6EACu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[12], ctx->fpr[10], ctx->fpr[0], true, false, true, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F6EB0:
    ctx->pc = 0x800F6EB0u;
    // 800F6EB0: stfs     f11, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6EB0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800F6EB4:
    ctx->pc = 0x800F6EB4u;
    // 800F6EB4: stfs     f12, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6EB4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F6EB8:
    ctx->pc = 0x800F6EB8u;
    // 800F6EB8: stfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6EB8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F6EBC:
    ctx->pc = 0x800F6EBCu;
    // 800F6EBC: lfs     f13, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F6EBCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F6EC0:
    ctx->pc = 0x800F6EC0u;
    // 800F6EC0: lfs     f0, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F6EC0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F6EC4:
    ctx->pc = 0x800F6EC4u;
    // 800F6EC4: stfs     f9, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6EC4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[9]));
    }

label_800F6EC8:
    ctx->pc = 0x800F6EC8u;
    // 800F6EC8: fmuls   f13, f13, f5
    if (!ppc_fp_available_inline(ctx, 0x800F6EC8u)) return;
    ppc_fmuls(ctx, 13, 13, 5);

label_800F6ECC:
    ctx->pc = 0x800F6ECCu;
    // 800F6ECC: fmadds f9, f9, f6, f13
    if (!ppc_fp_available_inline(ctx, 0x800F6ECCu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[9], ctx->fpr[6], ctx->fpr[13], true, false, false, &result))
            ctx->fpr[9] = ctx->ps1[9] = result;
    }

label_800F6ED0:
    ctx->pc = 0x800F6ED0u;
    // 800F6ED0: lfs     f12, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F6ED0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F6ED4:
    ctx->pc = 0x800F6ED4u;
    // 800F6ED4: fnmadds f0, f0, f10, f9
    if (!ppc_fp_available_inline(ctx, 0x800F6ED4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[10], ctx->fpr[9], true, false, true, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F6ED8:
    ctx->pc = 0x800F6ED8u;
    // 800F6ED8: stfs     f12, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x800F6ED8u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F6EDC:
    ctx->pc = 0x800F6EDCu;
    // 800F6EDC: lfs     f13, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F6EDCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F6EE0:
    ctx->pc = 0x800F6EE0u;
    // 800F6EE0: stfs     f0, 12(r28)
    if (!ppc_fp_available_inline(ctx, 0x800F6EE0u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F6EE4:
    ctx->pc = 0x800F6EE4u;
    // 800F6EE4: stfs     f13, 8(r28)
    if (!ppc_fp_available_inline(ctx, 0x800F6EE4u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F6EE8:
    ctx->pc = 0x800F6EE8u;
    // 800F6EE8: bl      0x802837C8
    {
            ctx->lr = 0x800F6EECu;
            ctx->pc = 0x802837C8u;
            return;
    }

label_800F6EEC:
    ctx->pc = 0x800F6EECu;
    ctx->downcount -= 8;
    // 800F6EEC: lfs     f7, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6EECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[7] = value;
        ctx->ps1[7] = value;
    }

label_800F6EF0:
    ctx->pc = 0x800F6EF0u;
    // 800F6EF0: lfs     f8, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6EF0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_800F6EF4:
    ctx->pc = 0x800F6EF4u;
    // 800F6EF4: lfs     f9, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6EF4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F6EF8:
    ctx->pc = 0x800F6EF8u;
    // 800F6EF8: fmuls   f0, f7, f7
    if (!ppc_fp_available_inline(ctx, 0x800F6EF8u)) return;
    ppc_fmuls(ctx, 0, 7, 7);

label_800F6EFC:
    ctx->pc = 0x800F6EFCu;
    // 800F6EFC: fmadds f0, f8, f8, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6EFCu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[8], ctx->fpr[8], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F6F00:
    ctx->pc = 0x800F6F00u;
    // 800F6F00: fmadds f10, f9, f9, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6F00u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[9], ctx->fpr[9], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[10] = ctx->ps1[10] = result;
    }

label_800F6F04:
    ctx->pc = 0x800F6F04u;
    // 800F6F04: fcmpu   cr0, f10, f31
    if (!ppc_fp_available_inline(ctx, 0x800F6F04u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[10], ctx->fpr[31], false);

label_800F6F08:
    ctx->pc = 0x800F6F08u;
    // 800F6F08: bc    12, 2, 0x800F6F40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800F6F40;
        }
    }

label_800F6F0C:
    ctx->pc = 0x800F6F0Cu;
    ctx->downcount -= 13;
    // 800F6F0C: frsqrte    f13, f10
    if (!ppc_fp_available_inline(ctx, 0x800F6F0Cu)) return;
    { f64 result; if (ppc_frsqrte(ctx, ctx->fpr[10], &result)) ctx->fpr[13] = result; }

label_800F6F10:
    ctx->pc = 0x800F6F10u;
    // 800F6F10: lfs     f12, -29688(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F6F10u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-29688);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F6F14:
    ctx->pc = 0x800F6F14u;
    // 800F6F14: lfs     f11, -29676(r13)
    if (!ppc_fp_available_inline(ctx, 0x800F6F14u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-29676);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F6F18:
    ctx->pc = 0x800F6F18u;
    // 800F6F18: fmuls   f0, f13, f13
    if (!ppc_fp_available_inline(ctx, 0x800F6F18u)) return;
    ppc_fmuls(ctx, 0, 13, 13);

label_800F6F1C:
    ctx->pc = 0x800F6F1Cu;
    // 800F6F1C: fmuls   f13, f13, f12
    if (!ppc_fp_available_inline(ctx, 0x800F6F1Cu)) return;
    ppc_fmuls(ctx, 13, 13, 12);

label_800F6F20:
    ctx->pc = 0x800F6F20u;
    // 800F6F20: fnmsubs f0, f0, f10, f11
    if (!ppc_fp_available_inline(ctx, 0x800F6F20u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[10], ctx->fpr[11], true, true, true, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F6F24:
    ctx->pc = 0x800F6F24u;
    // 800F6F24: fmuls   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F6F24u)) return;
    ppc_fmuls(ctx, 0, 0, 13);

label_800F6F28:
    ctx->pc = 0x800F6F28u;
    // 800F6F28: fmuls   f12, f9, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6F28u)) return;
    ppc_fmuls(ctx, 12, 9, 0);

label_800F6F2C:
    ctx->pc = 0x800F6F2Cu;
    // 800F6F2C: fmuls   f13, f8, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6F2Cu)) return;
    ppc_fmuls(ctx, 13, 8, 0);

label_800F6F30:
    ctx->pc = 0x800F6F30u;
    // 800F6F30: stfs     f12, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6F30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F6F34:
    ctx->pc = 0x800F6F34u;
    // 800F6F34: fmuls   f0, f7, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6F34u)) return;
    ppc_fmuls(ctx, 0, 7, 0);

label_800F6F38:
    ctx->pc = 0x800F6F38u;
    // 800F6F38: stfs     f13, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6F38u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F6F3C:
    ctx->pc = 0x800F6F3Cu;
    // 800F6F3C: stfs     f0, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6F3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F6F40:
    ctx->pc = 0x800F6F40u;
    ctx->downcount -= 47;
    // 800F6F40: lfs     f11, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F6F40u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F6F44:
    ctx->pc = 0x800F6F44u;
    // 800F6F44: lfs     f0, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F6F44u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F6F48:
    ctx->pc = 0x800F6F48u;
    // 800F6F48: lfs     f6, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6F48u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_800F6F4C:
    ctx->pc = 0x800F6F4Cu;
    // 800F6F4C: lfs     f7, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6F4Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[7] = value;
        ctx->ps1[7] = value;
    }

label_800F6F50:
    ctx->pc = 0x800F6F50u;
    // 800F6F50: lfs     f13, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6F50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F6F54:
    ctx->pc = 0x800F6F54u;
    // 800F6F54: fmuls   f9, f0, f6
    if (!ppc_fp_available_inline(ctx, 0x800F6F54u)) return;
    ppc_fmuls(ctx, 9, 0, 6);

label_800F6F58:
    ctx->pc = 0x800F6F58u;
    // 800F6F58: fmuls   f10, f11, f7
    if (!ppc_fp_available_inline(ctx, 0x800F6F58u)) return;
    ppc_fmuls(ctx, 10, 11, 7);

label_800F6F5C:
    ctx->pc = 0x800F6F5Cu;
    // 800F6F5C: lfs     f12, 88(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F6F5Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(88);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F6F60:
    ctx->pc = 0x800F6F60u;
    // 800F6F60: lfs     f8, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F6F60u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_800F6F64:
    ctx->pc = 0x800F6F64u;
    // 800F6F64: fmsubs f0, f0, f13, f10
    if (!ppc_fp_available_inline(ctx, 0x800F6F64u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[13], ctx->fpr[10], true, true, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F6F68:
    ctx->pc = 0x800F6F68u;
    // 800F6F68: stfs     f0, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6F68u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F6F6C:
    ctx->pc = 0x800F6F6Cu;
    // 800F6F6C: fmuls   f13, f12, f13
    if (!ppc_fp_available_inline(ctx, 0x800F6F6Cu)) return;
    ppc_fmuls(ctx, 13, 12, 13);

label_800F6F70:
    ctx->pc = 0x800F6F70u;
    // 800F6F70: fmsubs f11, f11, f6, f13
    if (!ppc_fp_available_inline(ctx, 0x800F6F70u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[6], ctx->fpr[13], true, true, false, &result))
            ctx->fpr[11] = ctx->ps1[11] = result;
    }

label_800F6F74:
    ctx->pc = 0x800F6F74u;
    // 800F6F74: lfs     f10, 124(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F6F74u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(124);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800F6F78:
    ctx->pc = 0x800F6F78u;
    // 800F6F78: fmsubs f12, f12, f7, f9
    if (!ppc_fp_available_inline(ctx, 0x800F6F78u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[12], ctx->fpr[7], ctx->fpr[9], true, true, false, &result))
            ctx->fpr[12] = ctx->ps1[12] = result;
    }

label_800F6F7C:
    ctx->pc = 0x800F6F7Cu;
    // 800F6F7C: stfs     f11, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6F7Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800F6F80:
    ctx->pc = 0x800F6F80u;
    // 800F6F80: stfs     f12, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6F80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F6F84:
    ctx->pc = 0x800F6F84u;
    // 800F6F84: lwz     r9, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F6F88:
    ctx->pc = 0x800F6F88u;
    // 800F6F88: lwz     r11, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F6F8C:
    ctx->pc = 0x800F6F8Cu;
    // 800F6F8C: lwz     r0, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F6F90:
    ctx->pc = 0x800F6F90u;
    // 800F6F90: stw     r9, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F6F94:
    ctx->pc = 0x800F6F94u;
    // 800F6F94: stw     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F6F98:
    ctx->pc = 0x800F6F98u;
    // 800F6F98: stw     r11, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F6F9C:
    ctx->pc = 0x800F6F9Cu;
    // 800F6F9C: lfs     f5, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6F9Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_800F6FA0:
    ctx->pc = 0x800F6FA0u;
    // 800F6FA0: lfs     f7, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6FA0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[7] = value;
        ctx->ps1[7] = value;
    }

label_800F6FA4:
    ctx->pc = 0x800F6FA4u;
    // 800F6FA4: lfs     f12, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F6FA4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F6FA8:
    ctx->pc = 0x800F6FA8u;
    // 800F6FA8: fmuls   f0, f5, f8
    if (!ppc_fp_available_inline(ctx, 0x800F6FA8u)) return;
    ppc_fmuls(ctx, 0, 5, 8);

label_800F6FAC:
    ctx->pc = 0x800F6FACu;
    // 800F6FAC: lfs     f6, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6FACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_800F6FB0:
    ctx->pc = 0x800F6FB0u;
    // 800F6FB0: fmadds f0, f7, f10, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6FB0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[7], ctx->fpr[10], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F6FB4:
    ctx->pc = 0x800F6FB4u;
    // 800F6FB4: stfs     f7, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6FB4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[7]));
    }

label_800F6FB8:
    ctx->pc = 0x800F6FB8u;
    // 800F6FB8: fnmadds f4, f6, f12, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6FB8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[6], ctx->fpr[12], ctx->fpr[0], true, false, true, &result))
            ctx->fpr[4] = ctx->ps1[4] = result;
    }

label_800F6FBC:
    ctx->pc = 0x800F6FBCu;
    // 800F6FBC: stfs     f5, 44(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6FBCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_800F6FC0:
    ctx->pc = 0x800F6FC0u;
    // 800F6FC0: stfs     f6, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6FC0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[6]));
    }

label_800F6FC4:
    ctx->pc = 0x800F6FC4u;
    // 800F6FC4: stfs     f4, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6FC4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_800F6FC8:
    ctx->pc = 0x800F6FC8u;
    // 800F6FC8: lfs     f11, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6FC8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F6FCC:
    ctx->pc = 0x800F6FCCu;
    // 800F6FCC: lfs     f0, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x800F6FCCu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F6FD0:
    ctx->pc = 0x800F6FD0u;
    // 800F6FD0: lfs     f13, 8(r28)
    if (!ppc_fp_available_inline(ctx, 0x800F6FD0u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F6FD4:
    ctx->pc = 0x800F6FD4u;
    // 800F6FD4: stfs     f11, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6FD4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800F6FD8:
    ctx->pc = 0x800F6FD8u;
    // 800F6FD8: fmuls   f8, f0, f8
    if (!ppc_fp_available_inline(ctx, 0x800F6FD8u)) return;
    ppc_fmuls(ctx, 8, 0, 8);

label_800F6FDC:
    ctx->pc = 0x800F6FDCu;
    // 800F6FDC: stfs     f13, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6FDCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F6FE0:
    ctx->pc = 0x800F6FE0u;
    // 800F6FE0: fmadds f10, f11, f10, f8
    if (!ppc_fp_available_inline(ctx, 0x800F6FE0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[10], ctx->fpr[8], true, false, false, &result))
            ctx->fpr[10] = ctx->ps1[10] = result;
    }

label_800F6FE4:
    ctx->pc = 0x800F6FE4u;
    // 800F6FE4: stfs     f0, 92(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6FE4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F6FE8:
    ctx->pc = 0x800F6FE8u;
    // 800F6FE8: fmadds f13, f13, f12, f10
    if (!ppc_fp_available_inline(ctx, 0x800F6FE8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[13], ctx->fpr[12], ctx->fpr[10], true, false, false, &result))
            ctx->fpr[13] = ctx->ps1[13] = result;
    }

label_800F6FEC:
    ctx->pc = 0x800F6FECu;
    // 800F6FEC: lfs     f0, 12(r28)
    if (!ppc_fp_available_inline(ctx, 0x800F6FECu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F6FF0:
    ctx->pc = 0x800F6FF0u;
    // 800F6FF0: fadds   f13, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x800F6FF0u)) return;
    ppc_fadds(ctx, 13, 13, 0);

label_800F6FF4:
    ctx->pc = 0x800F6FF4u;
    // 800F6FF4: fcmpu   cr0, f13, f31
    if (!ppc_fp_available_inline(ctx, 0x800F6FF4u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[13], ctx->fpr[31], false);

label_800F6FF8:
    ctx->pc = 0x800F6FF8u;
    // 800F6FF8: bc    4, 0, 0x800F7008
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F7008;
        }
    }

label_800F6FFC:
    ctx->pc = 0x800F6FFCu;
    ctx->downcount -= 3;
    // 800F6FFC: lfs     f0, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F6FFCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7000:
    ctx->pc = 0x800F7000u;
    // 800F7000: fsubs   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F7000u)) return;
    ppc_fsubs(ctx, 0, 0, 13);

label_800F7004:
    ctx->pc = 0x800F7004u;
    // 800F7004: stfs     f0, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7004u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F7008:
    ctx->pc = 0x800F7008u;
    ctx->downcount -= 77;
    // 800F7008: lfs     f0, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7008u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F700C:
    ctx->pc = 0x800F700Cu;
    // 800F700C: lfs     f12, 8(r28)
    if (!ppc_fp_available_inline(ctx, 0x800F700Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F7010:
    ctx->pc = 0x800F7010u;
    // 800F7010: lfs     f13, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x800F7010u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F7014:
    ctx->pc = 0x800F7014u;
    // 800F7014: fneg    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800F7014u)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_800F7018:
    ctx->pc = 0x800F7018u;
    // 800F7018: fmuls   f11, f11, f0
    if (!ppc_fp_available_inline(ctx, 0x800F7018u)) return;
    ppc_fmuls(ctx, 11, 11, 0);

label_800F701C:
    ctx->pc = 0x800F701Cu;
    // 800F701C: lfs     f8, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F701Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_800F7020:
    ctx->pc = 0x800F7020u;
    // 800F7020: stfs     f11, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7020u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800F7024:
    ctx->pc = 0x800F7024u;
    // 800F7024: fmuls   f12, f12, f0
    if (!ppc_fp_available_inline(ctx, 0x800F7024u)) return;
    ppc_fmuls(ctx, 12, 12, 0);

label_800F7028:
    ctx->pc = 0x800F7028u;
    // 800F7028: fmuls   f13, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x800F7028u)) return;
    ppc_fmuls(ctx, 13, 13, 0);

label_800F702C:
    ctx->pc = 0x800F702Cu;
    // 800F702C: stfs     f12, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F702Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F7030:
    ctx->pc = 0x800F7030u;
    // 800F7030: stfs     f13, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7030u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F7034:
    ctx->pc = 0x800F7034u;
    // 800F7034: lwz     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F7038:
    ctx->pc = 0x800F7038u;
    // 800F7038: lwz     r11, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800F703C:
    ctx->pc = 0x800F703Cu;
    // 800F703C: stw     r0, 124(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F7040:
    ctx->pc = 0x800F7040u;
    // 800F7040: lwz     r9, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800F7044:
    ctx->pc = 0x800F7044u;
    // 800F7044: stw     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800F7048:
    ctx->pc = 0x800F7048u;
    // 800F7048: stw     r9, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800F704C:
    ctx->pc = 0x800F704Cu;
    // 800F704C: lfs     f0, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F704Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7050:
    ctx->pc = 0x800F7050u;
    // 800F7050: lfs     f11, 124(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F7050u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(124);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F7054:
    ctx->pc = 0x800F7054u;
    // 800F7054: lfs     f12, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7054u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F7058:
    ctx->pc = 0x800F7058u;
    // 800F7058: fmuls   f0, f8, f0
    if (!ppc_fp_available_inline(ctx, 0x800F7058u)) return;
    ppc_fmuls(ctx, 0, 8, 0);

label_800F705C:
    ctx->pc = 0x800F705Cu;
    // 800F705C: lfs     f13, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F705Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F7060:
    ctx->pc = 0x800F7060u;
    // 800F7060: lfs     f9, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7060u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F7064:
    ctx->pc = 0x800F7064u;
    // 800F7064: fmadds f0, f12, f11, f0
    if (!ppc_fp_available_inline(ctx, 0x800F7064u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[12], ctx->fpr[11], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F7068:
    ctx->pc = 0x800F7068u;
    // 800F7068: lfs     f10, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7068u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800F706C:
    ctx->pc = 0x800F706Cu;
    // 800F706C: fmadds f13, f9, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x800F706Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[9], ctx->fpr[13], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[13] = ctx->ps1[13] = result;
    }

label_800F7070:
    ctx->pc = 0x800F7070u;
    // 800F7070: stfs     f7, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7070u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[7]));
    }

label_800F7074:
    ctx->pc = 0x800F7074u;
    // 800F7074: fadds   f13, f13, f10
    if (!ppc_fp_available_inline(ctx, 0x800F7074u)) return;
    ppc_fadds(ctx, 13, 13, 10);

label_800F7078:
    ctx->pc = 0x800F7078u;
    // 800F7078: stfs     f5, 92(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7078u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_800F707C:
    ctx->pc = 0x800F707Cu;
    // 800F707C: fmuls   f12, f12, f13
    if (!ppc_fp_available_inline(ctx, 0x800F707Cu)) return;
    ppc_fmuls(ctx, 12, 12, 13);

label_800F7080:
    ctx->pc = 0x800F7080u;
    // 800F7080: stfs     f6, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7080u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[6]));
    }

label_800F7084:
    ctx->pc = 0x800F7084u;
    // 800F7084: fsubs   f11, f11, f12
    if (!ppc_fp_available_inline(ctx, 0x800F7084u)) return;
    ppc_fsubs(ctx, 11, 11, 12);

label_800F7088:
    ctx->pc = 0x800F7088u;
    // 800F7088: stfs     f11, 124(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F7088u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(124);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800F708C:
    ctx->pc = 0x800F708Cu;
    // 800F708C: fmuls   f9, f9, f13
    if (!ppc_fp_available_inline(ctx, 0x800F708Cu)) return;
    ppc_fmuls(ctx, 9, 9, 13);

label_800F7090:
    ctx->pc = 0x800F7090u;
    // 800F7090: fmuls   f8, f8, f13
    if (!ppc_fp_available_inline(ctx, 0x800F7090u)) return;
    ppc_fmuls(ctx, 8, 8, 13);

label_800F7094:
    ctx->pc = 0x800F7094u;
    // 800F7094: lfs     f0, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F7094u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7098:
    ctx->pc = 0x800F7098u;
    // 800F7098: lfs     f13, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F7098u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F709C:
    ctx->pc = 0x800F709Cu;
    // 800F709C: fsubs   f0, f0, f8
    if (!ppc_fp_available_inline(ctx, 0x800F709Cu)) return;
    ppc_fsubs(ctx, 0, 0, 8);

label_800F70A0:
    ctx->pc = 0x800F70A0u;
    // 800F70A0: fsubs   f13, f13, f9
    if (!ppc_fp_available_inline(ctx, 0x800F70A0u)) return;
    ppc_fsubs(ctx, 13, 13, 9);

label_800F70A4:
    ctx->pc = 0x800F70A4u;
    // 800F70A4: stfs     f0, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F70A4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F70A8:
    ctx->pc = 0x800F70A8u;
    // 800F70A8: stfs     f13, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F70A8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F70AC:
    ctx->pc = 0x800F70ACu;
    // 800F70AC: fmuls   f0, f5, f0
    if (!ppc_fp_available_inline(ctx, 0x800F70ACu)) return;
    ppc_fmuls(ctx, 0, 5, 0);

label_800F70B0:
    ctx->pc = 0x800F70B0u;
    // 800F70B0: lfs     f12, 124(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F70B0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(124);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F70B4:
    ctx->pc = 0x800F70B4u;
    // 800F70B4: fmadds f0, f7, f12, f0
    if (!ppc_fp_available_inline(ctx, 0x800F70B4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[7], ctx->fpr[12], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F70B8:
    ctx->pc = 0x800F70B8u;
    // 800F70B8: fmadds f13, f6, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x800F70B8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[6], ctx->fpr[13], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[13] = ctx->ps1[13] = result;
    }

label_800F70BC:
    ctx->pc = 0x800F70BCu;
    // 800F70BC: fadds   f13, f13, f4
    if (!ppc_fp_available_inline(ctx, 0x800F70BCu)) return;
    ppc_fadds(ctx, 13, 13, 4);

label_800F70C0:
    ctx->pc = 0x800F70C0u;
    // 800F70C0: fmuls   f0, f7, f13
    if (!ppc_fp_available_inline(ctx, 0x800F70C0u)) return;
    ppc_fmuls(ctx, 0, 7, 13);

label_800F70C4:
    ctx->pc = 0x800F70C4u;
    // 800F70C4: stfs     f0, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F70C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F70C8:
    ctx->pc = 0x800F70C8u;
    // 800F70C8: fsubs   f12, f12, f0
    if (!ppc_fp_available_inline(ctx, 0x800F70C8u)) return;
    ppc_fsubs(ctx, 12, 12, 0);

label_800F70CC:
    ctx->pc = 0x800F70CCu;
    // 800F70CC: stfs     f12, 124(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F70CCu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(124);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F70D0:
    ctx->pc = 0x800F70D0u;
    // 800F70D0: fmuls   f11, f6, f13
    if (!ppc_fp_available_inline(ctx, 0x800F70D0u)) return;
    ppc_fmuls(ctx, 11, 6, 13);

label_800F70D4:
    ctx->pc = 0x800F70D4u;
    // 800F70D4: stfs     f11, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F70D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800F70D8:
    ctx->pc = 0x800F70D8u;
    // 800F70D8: fmuls   f0, f5, f13
    if (!ppc_fp_available_inline(ctx, 0x800F70D8u)) return;
    ppc_fmuls(ctx, 0, 5, 13);

label_800F70DC:
    ctx->pc = 0x800F70DCu;
    // 800F70DC: lfs     f13, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F70DCu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F70E0:
    ctx->pc = 0x800F70E0u;
    // 800F70E0: stfs     f0, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F70E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F70E4:
    ctx->pc = 0x800F70E4u;
    // 800F70E4: fsubs   f13, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x800F70E4u)) return;
    ppc_fsubs(ctx, 13, 13, 0);

label_800F70E8:
    ctx->pc = 0x800F70E8u;
    // 800F70E8: stfs     f13, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F70E8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F70EC:
    ctx->pc = 0x800F70ECu;
    // 800F70EC: lfs     f0, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F70ECu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F70F0:
    ctx->pc = 0x800F70F0u;
    // 800F70F0: fsubs   f0, f0, f11
    if (!ppc_fp_available_inline(ctx, 0x800F70F0u)) return;
    ppc_fsubs(ctx, 0, 0, 11);

label_800F70F4:
    ctx->pc = 0x800F70F4u;
    // 800F70F4: stfs     f0, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x800F70F4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F70F8:
    ctx->pc = 0x800F70F8u;
    // 800F70F8: lwz     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F70FC:
    ctx->pc = 0x800F70FCu;
    // 800F70FC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F7100:
    ctx->pc = 0x800F7100u;
    // 800F7100: lmw     r26, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F7104:
    ctx->pc = 0x800F7104u;
    // 800F7104: lfd     f31, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7104u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F7108:
    ctx->pc = 0x800F7108u;
    // 800F7108: addi    r1, r1, 144
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(144);

label_800F710C:
    ctx->pc = 0x800F710Cu;
    // 800F710C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F7110:
    ctx->pc = 0x800F7110u;
    ctx->downcount -= 21;
    // 800F7110: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F7114:
    ctx->pc = 0x800F7114u;
    // 800F7114: addi    r9, r3, 8
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(8);

label_800F7118:
    ctx->pc = 0x800F7118u;
    // 800F7118: lfs     f13, 4(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F7118u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F711C:
    ctx->pc = 0x800F711Cu;
    // 800F711C: lfs     f12, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F711Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F7120:
    ctx->pc = 0x800F7120u;
    // 800F7120: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_800F7124:
    ctx->pc = 0x800F7124u;
    // 800F7124: lfs     f11, 8(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7124u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F7128:
    ctx->pc = 0x800F7128u;
    // 800F7128: lfs     f0, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F7128u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F712C:
    ctx->pc = 0x800F712Cu;
    // 800F712C: stfs     f12, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F712Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F7130:
    ctx->pc = 0x800F7130u;
    // 800F7130: stfs     f11, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7130u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800F7134:
    ctx->pc = 0x800F7134u;
    // 800F7134: fmuls   f12, f12, f13
    if (!ppc_fp_available_inline(ctx, 0x800F7134u)) return;
    ppc_fmuls(ctx, 12, 12, 13);

label_800F7138:
    ctx->pc = 0x800F7138u;
    // 800F7138: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7138u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F713C:
    ctx->pc = 0x800F713Cu;
    // 800F713C: lfs     f13, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F713Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F7140:
    ctx->pc = 0x800F7140u;
    // 800F7140: lfs     f10, 8(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F7140u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800F7144:
    ctx->pc = 0x800F7144u;
    // 800F7144: fmadds f11, f11, f13, f12
    if (!ppc_fp_available_inline(ctx, 0x800F7144u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[13], ctx->fpr[12], true, false, false, &result))
            ctx->fpr[11] = ctx->ps1[11] = result;
    }

label_800F7148:
    ctx->pc = 0x800F7148u;
    // 800F7148: lfs     f9, 12(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F7148u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F714C:
    ctx->pc = 0x800F714Cu;
    // 800F714C: fmadds f0, f0, f10, f11
    if (!ppc_fp_available_inline(ctx, 0x800F714Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[10], ctx->fpr[11], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F7150:
    ctx->pc = 0x800F7150u;
    // 800F7150: lfs     f8, -5712(r11)
    if (!ppc_fp_available_inline(ctx, 0x800F7150u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-5712);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_800F7154:
    ctx->pc = 0x800F7154u;
    // 800F7154: fadds   f0, f0, f9
    if (!ppc_fp_available_inline(ctx, 0x800F7154u)) return;
    ppc_fadds(ctx, 0, 0, 9);

label_800F7158:
    ctx->pc = 0x800F7158u;
    // 800F7158: fsubs   f12, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800F7158u)) return;
    ppc_fsubs(ctx, 12, 0, 1);

label_800F715C:
    ctx->pc = 0x800F715Cu;
    // 800F715C: fcmpu   cr0, f12, f8
    if (!ppc_fp_available_inline(ctx, 0x800F715Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[12], ctx->fpr[8], false);

label_800F7160:
    ctx->pc = 0x800F7160u;
    // 800F7160: bc    4, 0, 0x800F7170
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F7170;
        }
    }

label_800F7164:
    ctx->pc = 0x800F7164u;
    ctx->downcount -= 3;
    // 800F7164: lfs     f0, 20(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7164u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7168:
    ctx->pc = 0x800F7168u;
    // 800F7168: fsubs   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F7168u)) return;
    ppc_fsubs(ctx, 0, 0, 12);

label_800F716C:
    ctx->pc = 0x800F716Cu;
    // 800F716C: stfs     f0, 20(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F716Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F7170:
    ctx->pc = 0x800F7170u;
    ctx->downcount -= 18;
    // 800F7170: addi    r9, r3, 24
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(24);

label_800F7174:
    ctx->pc = 0x800F7174u;
    // 800F7174: lfs     f12, 4(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F7174u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F7178:
    ctx->pc = 0x800F7178u;
    // 800F7178: lfs     f13, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F7178u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F717C:
    ctx->pc = 0x800F717Cu;
    // 800F717C: lfs     f10, 24(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F717Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800F7180:
    ctx->pc = 0x800F7180u;
    // 800F7180: lfs     f0, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F7180u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7184:
    ctx->pc = 0x800F7184u;
    // 800F7184: stfs     f13, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7184u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F7188:
    ctx->pc = 0x800F7188u;
    // 800F7188: stfs     f10, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7188u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_800F718C:
    ctx->pc = 0x800F718Cu;
    // 800F718C: fmuls   f13, f13, f12
    if (!ppc_fp_available_inline(ctx, 0x800F718Cu)) return;
    ppc_fmuls(ctx, 13, 13, 12);

label_800F7190:
    ctx->pc = 0x800F7190u;
    // 800F7190: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7190u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F7194:
    ctx->pc = 0x800F7194u;
    // 800F7194: lfs     f12, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F7194u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F7198:
    ctx->pc = 0x800F7198u;
    // 800F7198: lfs     f9, 8(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F7198u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F719C:
    ctx->pc = 0x800F719Cu;
    // 800F719C: fmadds f10, f10, f12, f13
    if (!ppc_fp_available_inline(ctx, 0x800F719Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[12], ctx->fpr[13], true, false, false, &result))
            ctx->fpr[10] = ctx->ps1[10] = result;
    }

label_800F71A0:
    ctx->pc = 0x800F71A0u;
    // 800F71A0: lfs     f11, 12(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F71A0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F71A4:
    ctx->pc = 0x800F71A4u;
    // 800F71A4: fmadds f0, f0, f9, f10
    if (!ppc_fp_available_inline(ctx, 0x800F71A4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[9], ctx->fpr[10], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F71A8:
    ctx->pc = 0x800F71A8u;
    // 800F71A8: fadds   f0, f0, f11
    if (!ppc_fp_available_inline(ctx, 0x800F71A8u)) return;
    ppc_fadds(ctx, 0, 0, 11);

label_800F71AC:
    ctx->pc = 0x800F71ACu;
    // 800F71AC: fsubs   f12, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800F71ACu)) return;
    ppc_fsubs(ctx, 12, 0, 1);

label_800F71B0:
    ctx->pc = 0x800F71B0u;
    // 800F71B0: fcmpu   cr0, f12, f8
    if (!ppc_fp_available_inline(ctx, 0x800F71B0u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[12], ctx->fpr[8], false);

label_800F71B4:
    ctx->pc = 0x800F71B4u;
    // 800F71B4: bc    4, 0, 0x800F71C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F71C4;
        }
    }

label_800F71B8:
    ctx->pc = 0x800F71B8u;
    ctx->downcount -= 3;
    // 800F71B8: lfs     f0, 36(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F71B8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F71BC:
    ctx->pc = 0x800F71BCu;
    // 800F71BC: fsubs   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F71BCu)) return;
    ppc_fsubs(ctx, 0, 0, 12);

label_800F71C0:
    ctx->pc = 0x800F71C0u;
    // 800F71C0: stfs     f0, 36(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F71C0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F71C4:
    ctx->pc = 0x800F71C4u;
    ctx->downcount -= 18;
    // 800F71C4: addi    r9, r3, 56
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(56);

label_800F71C8:
    ctx->pc = 0x800F71C8u;
    // 800F71C8: lfs     f12, 4(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F71C8u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F71CC:
    ctx->pc = 0x800F71CCu;
    // 800F71CC: lfs     f13, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F71CCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F71D0:
    ctx->pc = 0x800F71D0u;
    // 800F71D0: lfs     f10, 56(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F71D0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800F71D4:
    ctx->pc = 0x800F71D4u;
    // 800F71D4: lfs     f0, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F71D4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F71D8:
    ctx->pc = 0x800F71D8u;
    // 800F71D8: stfs     f13, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F71D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F71DC:
    ctx->pc = 0x800F71DCu;
    // 800F71DC: stfs     f10, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F71DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_800F71E0:
    ctx->pc = 0x800F71E0u;
    // 800F71E0: fmuls   f13, f13, f12
    if (!ppc_fp_available_inline(ctx, 0x800F71E0u)) return;
    ppc_fmuls(ctx, 13, 13, 12);

label_800F71E4:
    ctx->pc = 0x800F71E4u;
    // 800F71E4: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F71E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F71E8:
    ctx->pc = 0x800F71E8u;
    // 800F71E8: lfs     f12, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F71E8u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F71EC:
    ctx->pc = 0x800F71ECu;
    // 800F71EC: lfs     f9, 8(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F71ECu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F71F0:
    ctx->pc = 0x800F71F0u;
    // 800F71F0: fmadds f10, f10, f12, f13
    if (!ppc_fp_available_inline(ctx, 0x800F71F0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[12], ctx->fpr[13], true, false, false, &result))
            ctx->fpr[10] = ctx->ps1[10] = result;
    }

label_800F71F4:
    ctx->pc = 0x800F71F4u;
    // 800F71F4: lfs     f11, 12(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F71F4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F71F8:
    ctx->pc = 0x800F71F8u;
    // 800F71F8: fmadds f0, f0, f9, f10
    if (!ppc_fp_available_inline(ctx, 0x800F71F8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[9], ctx->fpr[10], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F71FC:
    ctx->pc = 0x800F71FCu;
    // 800F71FC: fadds   f0, f0, f11
    if (!ppc_fp_available_inline(ctx, 0x800F71FCu)) return;
    ppc_fadds(ctx, 0, 0, 11);

label_800F7200:
    ctx->pc = 0x800F7200u;
    // 800F7200: fsubs   f12, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800F7200u)) return;
    ppc_fsubs(ctx, 12, 0, 1);

label_800F7204:
    ctx->pc = 0x800F7204u;
    // 800F7204: fcmpu   cr0, f12, f8
    if (!ppc_fp_available_inline(ctx, 0x800F7204u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[12], ctx->fpr[8], false);

label_800F7208:
    ctx->pc = 0x800F7208u;
    // 800F7208: bc    4, 0, 0x800F7218
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F7218;
        }
    }

label_800F720C:
    ctx->pc = 0x800F720Cu;
    ctx->downcount -= 3;
    // 800F720C: lfs     f0, 68(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F720Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(68);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7210:
    ctx->pc = 0x800F7210u;
    // 800F7210: fsubs   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F7210u)) return;
    ppc_fsubs(ctx, 0, 0, 12);

label_800F7214:
    ctx->pc = 0x800F7214u;
    // 800F7214: stfs     f0, 68(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7214u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(68);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F7218:
    ctx->pc = 0x800F7218u;
    ctx->downcount -= 2;
    // 800F7218: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F721C:
    ctx->pc = 0x800F721Cu;
    // 800F721C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F7220:
    ctx->pc = 0x800F7220u;
    ctx->downcount -= 21;
    // 800F7220: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F7224:
    ctx->pc = 0x800F7224u;
    // 800F7224: addi    r9, r3, 8
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(8);

label_800F7228:
    ctx->pc = 0x800F7228u;
    // 800F7228: lfs     f13, 4(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F7228u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F722C:
    ctx->pc = 0x800F722Cu;
    // 800F722C: lfs     f12, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F722Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F7230:
    ctx->pc = 0x800F7230u;
    // 800F7230: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_800F7234:
    ctx->pc = 0x800F7234u;
    // 800F7234: lfs     f11, 8(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7234u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F7238:
    ctx->pc = 0x800F7238u;
    // 800F7238: lfs     f0, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F7238u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F723C:
    ctx->pc = 0x800F723Cu;
    // 800F723C: stfs     f12, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F723Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F7240:
    ctx->pc = 0x800F7240u;
    // 800F7240: stfs     f11, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7240u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800F7244:
    ctx->pc = 0x800F7244u;
    // 800F7244: fmuls   f12, f12, f13
    if (!ppc_fp_available_inline(ctx, 0x800F7244u)) return;
    ppc_fmuls(ctx, 12, 12, 13);

label_800F7248:
    ctx->pc = 0x800F7248u;
    // 800F7248: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7248u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F724C:
    ctx->pc = 0x800F724Cu;
    // 800F724C: lfs     f13, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F724Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F7250:
    ctx->pc = 0x800F7250u;
    // 800F7250: lfs     f10, 8(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F7250u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800F7254:
    ctx->pc = 0x800F7254u;
    // 800F7254: fmadds f11, f11, f13, f12
    if (!ppc_fp_available_inline(ctx, 0x800F7254u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[13], ctx->fpr[12], true, false, false, &result))
            ctx->fpr[11] = ctx->ps1[11] = result;
    }

label_800F7258:
    ctx->pc = 0x800F7258u;
    // 800F7258: lfs     f9, 12(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F7258u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F725C:
    ctx->pc = 0x800F725Cu;
    // 800F725C: fmadds f0, f0, f10, f11
    if (!ppc_fp_available_inline(ctx, 0x800F725Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[10], ctx->fpr[11], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F7260:
    ctx->pc = 0x800F7260u;
    // 800F7260: lfs     f12, -5708(r11)
    if (!ppc_fp_available_inline(ctx, 0x800F7260u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-5708);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F7264:
    ctx->pc = 0x800F7264u;
    // 800F7264: fadds   f0, f0, f9
    if (!ppc_fp_available_inline(ctx, 0x800F7264u)) return;
    ppc_fadds(ctx, 0, 0, 9);

label_800F7268:
    ctx->pc = 0x800F7268u;
    // 800F7268: fsubs   f13, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800F7268u)) return;
    ppc_fsubs(ctx, 13, 0, 1);

label_800F726C:
    ctx->pc = 0x800F726Cu;
    // 800F726C: fcmpu   cr0, f13, f12
    if (!ppc_fp_available_inline(ctx, 0x800F726Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[13], ctx->fpr[12], false);

label_800F7270:
    ctx->pc = 0x800F7270u;
    // 800F7270: bc    4, 0, 0x800F7280
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F7280;
        }
    }

label_800F7274:
    ctx->pc = 0x800F7274u;
    ctx->downcount -= 3;
    // 800F7274: lfs     f0, 20(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7274u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7278:
    ctx->pc = 0x800F7278u;
    // 800F7278: fsubs   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F7278u)) return;
    ppc_fsubs(ctx, 0, 0, 13);

label_800F727C:
    ctx->pc = 0x800F727Cu;
    // 800F727C: stfs     f0, 20(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F727Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F7280:
    ctx->pc = 0x800F7280u;
    ctx->downcount -= 5;
    // 800F7280: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_800F7284:
    ctx->pc = 0x800F7284u;
    // 800F7284: fmr    f7, f12
    if (!ppc_fp_available_inline(ctx, 0x800F7284u)) return;
    ctx->fpr[7] = ctx->fpr[12];

label_800F7288:
    ctx->pc = 0x800F7288u;
    // 800F7288: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_800F728C:
    ctx->pc = 0x800F728Cu;
    // 800F728C: addi    r3, r3, 24
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(24);

label_800F7290:
    ctx->pc = 0x800F7290u;
    ctx->downcount -= 17;
    // 800F7290: lfs     f9, 4(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7290u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F7294:
    ctx->pc = 0x800F7294u;
    // 800F7294: lfs     f13, 4(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F7294u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F7298:
    ctx->pc = 0x800F7298u;
    // 800F7298: lfs     f11, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7298u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F729C:
    ctx->pc = 0x800F729Cu;
    // 800F729C: lfs     f12, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F729Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F72A0:
    ctx->pc = 0x800F72A0u;
    // 800F72A0: fmuls   f13, f9, f13
    if (!ppc_fp_available_inline(ctx, 0x800F72A0u)) return;
    ppc_fmuls(ctx, 13, 9, 13);

label_800F72A4:
    ctx->pc = 0x800F72A4u;
    // 800F72A4: lfs     f10, 8(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F72A4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800F72A8:
    ctx->pc = 0x800F72A8u;
    // 800F72A8: lfs     f0, 8(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F72A8u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F72AC:
    ctx->pc = 0x800F72ACu;
    // 800F72AC: fmadds f12, f11, f12, f13
    if (!ppc_fp_available_inline(ctx, 0x800F72ACu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[12], ctx->fpr[13], true, false, false, &result))
            ctx->fpr[12] = ctx->ps1[12] = result;
    }

label_800F72B0:
    ctx->pc = 0x800F72B0u;
    // 800F72B0: lfs     f8, 12(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F72B0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_800F72B4:
    ctx->pc = 0x800F72B4u;
    // 800F72B4: fmadds f0, f10, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F72B4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[0], ctx->fpr[12], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F72B8:
    ctx->pc = 0x800F72B8u;
    // 800F72B8: stfs     f11, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F72B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800F72BC:
    ctx->pc = 0x800F72BCu;
    // 800F72BC: fadds   f0, f0, f8
    if (!ppc_fp_available_inline(ctx, 0x800F72BCu)) return;
    ppc_fadds(ctx, 0, 0, 8);

label_800F72C0:
    ctx->pc = 0x800F72C0u;
    // 800F72C0: stfs     f9, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F72C0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[9]));
    }

label_800F72C4:
    ctx->pc = 0x800F72C4u;
    // 800F72C4: fsubs   f13, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800F72C4u)) return;
    ppc_fsubs(ctx, 13, 0, 1);

label_800F72C8:
    ctx->pc = 0x800F72C8u;
    // 800F72C8: stfs     f10, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F72C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_800F72CC:
    ctx->pc = 0x800F72CCu;
    // 800F72CC: fcmpu   cr0, f13, f7
    if (!ppc_fp_available_inline(ctx, 0x800F72CCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[13], ctx->fpr[7], false);

label_800F72D0:
    // 800F72D0: bc    4, 0, 0x800F72DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F72DC;
        }
    }

label_800F72D4:
    ctx->pc = 0x800F72D4u;
    ctx->downcount -= 2;
    // 800F72D4: fsubs   f0, f8, f13
    if (!ppc_fp_available_inline(ctx, 0x800F72D4u)) return;
    ppc_fsubs(ctx, 0, 8, 13);

label_800F72D8:
    ctx->pc = 0x800F72D8u;
    // 800F72D8: stfs     f0, 12(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F72D8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F72DC:
    ctx->downcount -= 2;
    // 800F72DC: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_800F72E0:
    // 800F72E0: bc    16, 0, 0x800F7290
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F7290u;
                return;
            }
            goto label_800F7290;
        }
    }

label_800F72E4:
    ctx->pc = 0x800F72E4u;
    ctx->downcount -= 2;
    // 800F72E4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800F72E8:
    ctx->pc = 0x800F72E8u;
    // 800F72E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F72EC:
    ctx->pc = 0x800F72ECu;
    ctx->downcount -= 34;
    // 800F72EC: stwu     r1, -72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-72);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F72F0:
    ctx->pc = 0x800F72F0u;
    // 800F72F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800F72F4:
    ctx->pc = 0x800F72F4u;
    // 800F72F4: stfd     f30, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F72F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_800F72F8:
    ctx->pc = 0x800F72F8u;
    // 800F72F8: stfd     f31, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F72F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800F72FC:
    ctx->pc = 0x800F72FCu;
    // 800F72FC: stmw     r28, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800F7300:
    ctx->pc = 0x800F7300u;
    // 800F7300: stw     r0, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800F7304:
    ctx->pc = 0x800F7304u;
    // 800F7304: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800F7308:
    ctx->pc = 0x800F7308u;
    // 800F7308: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_800F730C:
    ctx->pc = 0x800F730Cu;
    // 800F730C: lfs     f12, 0(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F730Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F7310:
    ctx->pc = 0x800F7310u;
    // 800F7310: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_800F7314:
    ctx->pc = 0x800F7314u;
    // 800F7314: lfs     f0, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F7314u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7318:
    ctx->pc = 0x800F7318u;
    // 800F7318: addi    r30, r1, 8
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(8);

label_800F731C:
    ctx->pc = 0x800F731Cu;
    // 800F731C: lfs     f30, -5700(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F731Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-5700);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_800F7320:
    ctx->pc = 0x800F7320u;
    // 800F7320: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800F7324:
    ctx->pc = 0x800F7324u;
    // 800F7324: lfs     f31, -5704(r11)
    if (!ppc_fp_available_inline(ctx, 0x800F7324u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-5704);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800F7328:
    ctx->pc = 0x800F7328u;
    // 800F7328: fsubs   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F7328u)) return;
    ppc_fsubs(ctx, 0, 0, 12);

label_800F732C:
    ctx->pc = 0x800F732Cu;
    // 800F732C: lfs     f13, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F732Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F7330:
    ctx->pc = 0x800F7330u;
    // 800F7330: fmadds f0, f0, f30, f12
    if (!ppc_fp_available_inline(ctx, 0x800F7330u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[30], ctx->fpr[12], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F7334:
    ctx->pc = 0x800F7334u;
    // 800F7334: stfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7334u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F7338:
    ctx->pc = 0x800F7338u;
    // 800F7338: stfs     f31, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7338u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800F733C:
    ctx->pc = 0x800F733Cu;
    // 800F733C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F7340:
    ctx->pc = 0x800F7340u;
    // 800F7340: stfs     f13, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F7340u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F7344:
    ctx->pc = 0x800F7344u;
    // 800F7344: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x800F7344u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_800F7348:
    ctx->pc = 0x800F7348u;
    // 800F7348: bl      0x800F7220
    {
            ctx->lr = 0x800F734Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F7220u;
                return;
            }
            goto label_800F7220;
    }

label_800F734C:
    ctx->pc = 0x800F734Cu;
    ctx->downcount -= 6;
    // 800F734C: lfs     f0, 12(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F734Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7350:
    ctx->pc = 0x800F7350u;
    // 800F7350: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800F7354:
    ctx->pc = 0x800F7354u;
    // 800F7354: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F7358:
    ctx->pc = 0x800F7358u;
    // 800F7358: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x800F7358u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_800F735C:
    ctx->pc = 0x800F735Cu;
    // 800F735C: stfs     f0, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F735Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F7360:
    ctx->pc = 0x800F7360u;
    // 800F7360: bl      0x800F7220
    {
            ctx->lr = 0x800F7364u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F7220u;
                return;
            }
            goto label_800F7220;
    }

label_800F7364:
    ctx->pc = 0x800F7364u;
    ctx->downcount -= 11;
    // 800F7364: lfs     f13, 12(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F7364u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F7368:
    ctx->pc = 0x800F7368u;
    // 800F7368: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800F736C:
    ctx->pc = 0x800F736Cu;
    // 800F736C: lfs     f0, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F736Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7370:
    ctx->pc = 0x800F7370u;
    // 800F7370: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F7374:
    ctx->pc = 0x800F7374u;
    // 800F7374: lfs     f12, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F7374u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F7378:
    ctx->pc = 0x800F7378u;
    // 800F7378: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x800F7378u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_800F737C:
    ctx->pc = 0x800F737Cu;
    // 800F737C: fsubs   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x800F737Cu)) return;
    ppc_fsubs(ctx, 0, 0, 13);

label_800F7380:
    ctx->pc = 0x800F7380u;
    // 800F7380: fmadds f0, f0, f30, f13
    if (!ppc_fp_available_inline(ctx, 0x800F7380u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[30], ctx->fpr[13], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F7384:
    ctx->pc = 0x800F7384u;
    // 800F7384: stfs     f0, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x800F7384u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F7388:
    ctx->pc = 0x800F7388u;
    // 800F7388: stfs     f12, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7388u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F738C:
    ctx->pc = 0x800F738Cu;
    // 800F738C: bl      0x800F7220
    {
            ctx->lr = 0x800F7390u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F7220u;
                return;
            }
            goto label_800F7220;
    }

label_800F7390:
    ctx->pc = 0x800F7390u;
    ctx->downcount -= 6;
    // 800F7390: lfs     f0, 0(r29)
    if (!ppc_fp_available_inline(ctx, 0x800F7390u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7394:
    ctx->pc = 0x800F7394u;
    // 800F7394: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800F7398:
    ctx->pc = 0x800F7398u;
    // 800F7398: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800F739C:
    ctx->pc = 0x800F739Cu;
    // 800F739C: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x800F739Cu)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_800F73A0:
    ctx->pc = 0x800F73A0u;
    // 800F73A0: stfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F73A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F73A4:
    ctx->pc = 0x800F73A4u;
    // 800F73A4: bl      0x800F7220
    {
            ctx->lr = 0x800F73A8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800F7220u;
                return;
            }
            goto label_800F7220;
    }

label_800F73A8:
    ctx->pc = 0x800F73A8u;
    ctx->downcount -= 18;
    // 800F73A8: lwz     r0, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800F73AC:
    ctx->pc = 0x800F73ACu;
    // 800F73AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800F73B0:
    ctx->pc = 0x800F73B0u;
    // 800F73B0: lmw     r28, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800F73B4:
    ctx->pc = 0x800F73B4u;
    // 800F73B4: lfd     f30, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F73B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F73B8:
    ctx->pc = 0x800F73B8u;
    // 800F73B8: lfd     f31, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F73B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800F73BC:
    ctx->pc = 0x800F73BCu;
    // 800F73BC: addi    r1, r1, 72
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(72);

label_800F73C0:
    ctx->pc = 0x800F73C0u;
    // 800F73C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800F34C0;
        }
    }

label_800F73C4:
    ctx->pc = 0x800F73C4u;
    ctx->downcount -= 21;
    // 800F73C4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800F73C8:
    ctx->pc = 0x800F73C8u;
    // 800F73C8: addi    r9, r3, 8
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(8);

label_800F73CC:
    ctx->pc = 0x800F73CCu;
    // 800F73CC: lfs     f13, 4(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F73CCu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F73D0:
    ctx->pc = 0x800F73D0u;
    // 800F73D0: lfs     f12, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F73D0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F73D4:
    ctx->pc = 0x800F73D4u;
    // 800F73D4: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_800F73D8:
    ctx->pc = 0x800F73D8u;
    // 800F73D8: lfs     f11, 8(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F73D8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F73DC:
    ctx->pc = 0x800F73DCu;
    // 800F73DC: lfs     f0, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F73DCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F73E0:
    ctx->pc = 0x800F73E0u;
    // 800F73E0: stfs     f12, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F73E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800F73E4:
    ctx->pc = 0x800F73E4u;
    // 800F73E4: stfs     f11, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F73E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800F73E8:
    ctx->pc = 0x800F73E8u;
    // 800F73E8: fmuls   f12, f12, f13
    if (!ppc_fp_available_inline(ctx, 0x800F73E8u)) return;
    ppc_fmuls(ctx, 12, 12, 13);

label_800F73EC:
    ctx->pc = 0x800F73ECu;
    // 800F73EC: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F73ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F73F0:
    ctx->pc = 0x800F73F0u;
    // 800F73F0: lfs     f13, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F73F0u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F73F4:
    ctx->pc = 0x800F73F4u;
    // 800F73F4: lfs     f10, 8(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F73F4u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800F73F8:
    ctx->pc = 0x800F73F8u;
    // 800F73F8: fmadds f11, f11, f13, f12
    if (!ppc_fp_available_inline(ctx, 0x800F73F8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[13], ctx->fpr[12], true, false, false, &result))
            ctx->fpr[11] = ctx->ps1[11] = result;
    }

label_800F73FC:
    ctx->pc = 0x800F73FCu;
    // 800F73FC: lfs     f9, 12(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F73FCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F7400:
    ctx->pc = 0x800F7400u;
    // 800F7400: fmadds f0, f0, f10, f11
    if (!ppc_fp_available_inline(ctx, 0x800F7400u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[10], ctx->fpr[11], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F7404:
    ctx->pc = 0x800F7404u;
    // 800F7404: lfs     f8, -5696(r11)
    if (!ppc_fp_available_inline(ctx, 0x800F7404u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-5696);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_800F7408:
    ctx->pc = 0x800F7408u;
    // 800F7408: fadds   f0, f0, f9
    if (!ppc_fp_available_inline(ctx, 0x800F7408u)) return;
    ppc_fadds(ctx, 0, 0, 9);

label_800F740C:
    ctx->pc = 0x800F740Cu;
    // 800F740C: fsubs   f12, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800F740Cu)) return;
    ppc_fsubs(ctx, 12, 0, 1);

label_800F7410:
    ctx->pc = 0x800F7410u;
    // 800F7410: fcmpu   cr0, f12, f8
    if (!ppc_fp_available_inline(ctx, 0x800F7410u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[12], ctx->fpr[8], false);

label_800F7414:
    ctx->pc = 0x800F7414u;
    // 800F7414: bc    4, 0, 0x800F7424
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F7424;
        }
    }

label_800F7418:
    ctx->pc = 0x800F7418u;
    ctx->downcount -= 3;
    // 800F7418: lfs     f0, 20(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7418u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F741C:
    ctx->pc = 0x800F741Cu;
    // 800F741C: fsubs   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F741Cu)) return;
    ppc_fsubs(ctx, 0, 0, 12);

label_800F7420:
    ctx->pc = 0x800F7420u;
    // 800F7420: stfs     f0, 20(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7420u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F7424:
    ctx->pc = 0x800F7424u;
    ctx->downcount -= 18;
    // 800F7424: addi    r9, r3, 72
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(72);

label_800F7428:
    ctx->pc = 0x800F7428u;
    // 800F7428: lfs     f12, 4(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F7428u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F742C:
    ctx->pc = 0x800F742Cu;
    // 800F742C: lfs     f13, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F742Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F7430:
    ctx->pc = 0x800F7430u;
    // 800F7430: lfs     f10, 72(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7430u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(72);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800F7434:
    ctx->pc = 0x800F7434u;
    // 800F7434: lfs     f0, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F7434u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7438:
    ctx->pc = 0x800F7438u;
    // 800F7438: stfs     f13, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7438u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F743C:
    ctx->pc = 0x800F743Cu;
    // 800F743C: stfs     f10, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F743Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_800F7440:
    ctx->pc = 0x800F7440u;
    // 800F7440: fmuls   f13, f13, f12
    if (!ppc_fp_available_inline(ctx, 0x800F7440u)) return;
    ppc_fmuls(ctx, 13, 13, 12);

label_800F7444:
    ctx->pc = 0x800F7444u;
    // 800F7444: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7444u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F7448:
    ctx->pc = 0x800F7448u;
    // 800F7448: lfs     f12, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F7448u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F744C:
    ctx->pc = 0x800F744Cu;
    // 800F744C: lfs     f9, 8(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F744Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F7450:
    ctx->pc = 0x800F7450u;
    // 800F7450: fmadds f10, f10, f12, f13
    if (!ppc_fp_available_inline(ctx, 0x800F7450u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[12], ctx->fpr[13], true, false, false, &result))
            ctx->fpr[10] = ctx->ps1[10] = result;
    }

label_800F7454:
    ctx->pc = 0x800F7454u;
    // 800F7454: lfs     f11, 12(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F7454u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F7458:
    ctx->pc = 0x800F7458u;
    // 800F7458: fmadds f0, f0, f9, f10
    if (!ppc_fp_available_inline(ctx, 0x800F7458u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[9], ctx->fpr[10], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F745C:
    ctx->pc = 0x800F745Cu;
    // 800F745C: fadds   f0, f0, f11
    if (!ppc_fp_available_inline(ctx, 0x800F745Cu)) return;
    ppc_fadds(ctx, 0, 0, 11);

label_800F7460:
    ctx->pc = 0x800F7460u;
    // 800F7460: fsubs   f12, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800F7460u)) return;
    ppc_fsubs(ctx, 12, 0, 1);

label_800F7464:
    ctx->pc = 0x800F7464u;
    // 800F7464: fcmpu   cr0, f12, f8
    if (!ppc_fp_available_inline(ctx, 0x800F7464u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[12], ctx->fpr[8], false);

label_800F7468:
    ctx->pc = 0x800F7468u;
    // 800F7468: bc    4, 0, 0x800F7478
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800F7478;
        }
    }

label_800F746C:
    ctx->pc = 0x800F746Cu;
    ctx->downcount -= 3;
    // 800F746C: lfs     f0, 84(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F746Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(84);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F7470:
    ctx->pc = 0x800F7470u;
    // 800F7470: fsubs   f0, f0, f12
    if (!ppc_fp_available_inline(ctx, 0x800F7470u)) return;
    ppc_fsubs(ctx, 0, 0, 12);

label_800F7474:
    ctx->pc = 0x800F7474u;
    // 800F7474: stfs     f0, 84(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7474u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(84);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F7478:
    ctx->pc = 0x800F7478u;
    ctx->downcount -= 18;
    // 800F7478: addi    r9, r3, 40
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(40);

label_800F747C:
    ctx->pc = 0x800F747Cu;
    // 800F747C: lfs     f12, 4(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F747Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F7480:
    ctx->pc = 0x800F7480u;
    // 800F7480: lfs     f13, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F7480u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800F7484:
    ctx->pc = 0x800F7484u;
    // 800F7484: lfs     f10, 40(r3)
    if (!ppc_fp_available_inline(ctx, 0x800F7484u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800F7488:
    ctx->pc = 0x800F7488u;
    // 800F7488: lfs     f0, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F7488u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800F748C:
    ctx->pc = 0x800F748Cu;
    // 800F748C: stfs     f13, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F748Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800F7490:
    ctx->pc = 0x800F7490u;
    // 800F7490: stfs     f10, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7490u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_800F7494:
    ctx->pc = 0x800F7494u;
    // 800F7494: fmuls   f13, f13, f12
    if (!ppc_fp_available_inline(ctx, 0x800F7494u)) return;
    ppc_fmuls(ctx, 13, 13, 12);

label_800F7498:
    ctx->pc = 0x800F7498u;
    // 800F7498: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800F7498u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800F749C:
    ctx->pc = 0x800F749Cu;
    // 800F749C: lfs     f12, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F749Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800F74A0:
    ctx->pc = 0x800F74A0u;
    // 800F74A0: lfs     f9, 8(r4)
    if (!ppc_fp_available_inline(ctx, 0x800F74A0u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800F74A4:
    ctx->pc = 0x800F74A4u;
    // 800F74A4: fmadds f10, f10, f12, f13
    if (!ppc_fp_available_inline(ctx, 0x800F74A4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[12], ctx->fpr[13], true, false, false, &result))
            ctx->fpr[10] = ctx->ps1[10] = result;
    }

label_800F74A8:
    ctx->pc = 0x800F74A8u;
    // 800F74A8: lfs     f11, 12(r9)
    if (!ppc_fp_available_inline(ctx, 0x800F74A8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800F74AC:
    ctx->pc = 0x800F74ACu;
    // 800F74AC: fmadds f0, f0, f9, f10
    if (!ppc_fp_available_inline(ctx, 0x800F74ACu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[9], ctx->fpr[10], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_800F74B0:
    ctx->pc = 0x800F74B0u;
    // 800F74B0: fadds   f0, f0, f11
    if (!ppc_fp_available_inline(ctx, 0x800F74B0u)) return;
    ppc_fadds(ctx, 0, 0, 11);

label_800F74B4:
    ctx->pc = 0x800F74B4u;
    // 800F74B4: fsubs   f12, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800F74B4u)) return;
    ppc_fsubs(ctx, 12, 0, 1);

label_800F74B8:
    ctx->pc = 0x800F74B8u;
    // 800F74B8: fcmpu   cr0, f12, f8
    if (!ppc_fp_available_inline(ctx, 0x800F74B8u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[12], ctx->fpr[8], false);

label_800F74BC:
    ctx->pc = 0x800F74BCu;
    // 800F74BC: bc    4, 0, 0x800F74CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x800F74CCu;
            return;
        }
    }

    ctx->pc = 0x800F74C0u;
    return;
return_dispatch_800F34C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x800F34F8u: goto label_800F34F8;
    case 0x800F3554u: goto label_800F3554;
    case 0x800F35C0u: goto label_800F35C0;
    case 0x800F35E4u: goto label_800F35E4;
    case 0x800F366Cu: goto label_800F366C;
    case 0x800F3690u: goto label_800F3690;
    case 0x800F3708u: goto label_800F3708;
    case 0x800F374Cu: goto label_800F374C;
    case 0x800F3790u: goto label_800F3790;
    case 0x800F37D8u: goto label_800F37D8;
    case 0x800F382Cu: goto label_800F382C;
    case 0x800F3850u: goto label_800F3850;
    case 0x800F38D0u: goto label_800F38D0;
    case 0x800F3938u: goto label_800F3938;
    case 0x800F395Cu: goto label_800F395C;
    case 0x800F39E4u: goto label_800F39E4;
    case 0x800F3A08u: goto label_800F3A08;
    case 0x800F3A90u: goto label_800F3A90;
    case 0x800F3AB4u: goto label_800F3AB4;
    case 0x800F3B3Cu: goto label_800F3B3C;
    case 0x800F3B60u: goto label_800F3B60;
    case 0x800F3BE8u: goto label_800F3BE8;
    case 0x800F3C0Cu: goto label_800F3C0C;
    case 0x800F3C98u: goto label_800F3C98;
    case 0x800F3CB8u: goto label_800F3CB8;
    case 0x800F3D50u: goto label_800F3D50;
    case 0x800F3D64u: goto label_800F3D64;
    case 0x800F3D8Cu: goto label_800F3D8C;
    case 0x800F3D94u: goto label_800F3D94;
    case 0x800F3DA4u: goto label_800F3DA4;
    case 0x800F3DD8u: goto label_800F3DD8;
    case 0x800F3E1Cu: goto label_800F3E1C;
    case 0x800F3E64u: goto label_800F3E64;
    case 0x800F3EBCu: goto label_800F3EBC;
    case 0x800F3EC0u: goto label_800F3EC0;
    case 0x800F3EC8u: goto label_800F3EC8;
    case 0x800F3EE8u: goto label_800F3EE8;
    case 0x800F3F1Cu: goto label_800F3F1C;
    case 0x800F3F9Cu: goto label_800F3F9C;
    case 0x800F3FC0u: goto label_800F3FC0;
    case 0x800F3FF8u: goto label_800F3FF8;
    case 0x800F4034u: goto label_800F4034;
    case 0x800F4060u: goto label_800F4060;
    case 0x800F4098u: goto label_800F4098;
    case 0x800F40D4u: goto label_800F40D4;
    case 0x800F4100u: goto label_800F4100;
    case 0x800F4138u: goto label_800F4138;
    case 0x800F4174u: goto label_800F4174;
    case 0x800F41A0u: goto label_800F41A0;
    case 0x800F41D8u: goto label_800F41D8;
    case 0x800F4220u: goto label_800F4220;
    case 0x800F4268u: goto label_800F4268;
    case 0x800F42BCu: goto label_800F42BC;
    case 0x800F42E0u: goto label_800F42E0;
    case 0x800F4368u: goto label_800F4368;
    case 0x800F438Cu: goto label_800F438C;
    case 0x800F4408u: goto label_800F4408;
    case 0x800F445Cu: goto label_800F445C;
    case 0x800F4480u: goto label_800F4480;
    case 0x800F4508u: goto label_800F4508;
    case 0x800F452Cu: goto label_800F452C;
    case 0x800F45A0u: goto label_800F45A0;
    case 0x800F45F0u: goto label_800F45F0;
    case 0x800F462Cu: goto label_800F462C;
    case 0x800F4678u: goto label_800F4678;
    case 0x800F46C4u: goto label_800F46C4;
    case 0x800F4710u: goto label_800F4710;
    case 0x800F475Cu: goto label_800F475C;
    case 0x800F47A8u: goto label_800F47A8;
    case 0x800F47F4u: goto label_800F47F4;
    case 0x800F4840u: goto label_800F4840;
    case 0x800F487Cu: goto label_800F487C;
    case 0x800F4890u: goto label_800F4890;
    case 0x800F48E4u: goto label_800F48E4;
    case 0x800F48F4u: goto label_800F48F4;
    case 0x800F4934u: goto label_800F4934;
    case 0x800F4938u: goto label_800F4938;
    case 0x800F495Cu: goto label_800F495C;
    case 0x800F4960u: goto label_800F4960;
    case 0x800F498Cu: goto label_800F498C;
    case 0x800F49A8u: goto label_800F49A8;
    case 0x800F49CCu: goto label_800F49CC;
    case 0x800F4A48u: goto label_800F4A48;
    case 0x800F4A64u: goto label_800F4A64;
    case 0x800F4A88u: goto label_800F4A88;
    case 0x800F4AFCu: goto label_800F4AFC;
    case 0x800F4B10u: goto label_800F4B10;
    case 0x800F4B64u: goto label_800F4B64;
    case 0x800F4B80u: goto label_800F4B80;
    case 0x800F4BA4u: goto label_800F4BA4;
    case 0x800F4C18u: goto label_800F4C18;
    case 0x800F4C34u: goto label_800F4C34;
    case 0x800F4C58u: goto label_800F4C58;
    case 0x800F4CC8u: goto label_800F4CC8;
    case 0x800F4CD8u: goto label_800F4CD8;
    case 0x800F4D10u: goto label_800F4D10;
    case 0x800F4D14u: goto label_800F4D14;
    case 0x800F4D38u: goto label_800F4D38;
    case 0x800F4D3Cu: goto label_800F4D3C;
    case 0x800F4D60u: goto label_800F4D60;
    case 0x800F4D64u: goto label_800F4D64;
    case 0x800F4D90u: goto label_800F4D90;
    case 0x800F4DACu: goto label_800F4DAC;
    case 0x800F4DD0u: goto label_800F4DD0;
    case 0x800F4E40u: goto label_800F4E40;
    case 0x800F4E50u: goto label_800F4E50;
    case 0x800F4E90u: goto label_800F4E90;
    case 0x800F4EA4u: goto label_800F4EA4;
    case 0x800F4EF8u: goto label_800F4EF8;
    case 0x800F4F0Cu: goto label_800F4F0C;
    case 0x800F4F60u: goto label_800F4F60;
    case 0x800F4F74u: goto label_800F4F74;
    case 0x800F4FCCu: goto label_800F4FCC;
    case 0x800F4FE8u: goto label_800F4FE8;
    case 0x800F5008u: goto label_800F5008;
    case 0x800F507Cu: goto label_800F507C;
    case 0x800F508Cu: goto label_800F508C;
    case 0x800F50C4u: goto label_800F50C4;
    case 0x800F50C8u: goto label_800F50C8;
    case 0x800F50F0u: goto label_800F50F0;
    case 0x800F5100u: goto label_800F5100;
    case 0x800F5138u: goto label_800F5138;
    case 0x800F513Cu: goto label_800F513C;
    case 0x800F5164u: goto label_800F5164;
    case 0x800F5174u: goto label_800F5174;
    case 0x800F51B0u: goto label_800F51B0;
    case 0x800F51C0u: goto label_800F51C0;
    case 0x800F51FCu: goto label_800F51FC;
    case 0x800F520Cu: goto label_800F520C;
    case 0x800F5250u: goto label_800F5250;
    case 0x800F5260u: goto label_800F5260;
    case 0x800F529Cu: goto label_800F529C;
    case 0x800F52B0u: goto label_800F52B0;
    case 0x800F52ECu: goto label_800F52EC;
    case 0x800F5300u: goto label_800F5300;
    case 0x800F533Cu: goto label_800F533C;
    case 0x800F5350u: goto label_800F5350;
    case 0x800F538Cu: goto label_800F538C;
    case 0x800F53A0u: goto label_800F53A0;
    case 0x800F53E4u: goto label_800F53E4;
    case 0x800F53F8u: goto label_800F53F8;
    case 0x800F5434u: goto label_800F5434;
    case 0x800F5448u: goto label_800F5448;
    case 0x800F5484u: goto label_800F5484;
    case 0x800F5498u: goto label_800F5498;
    case 0x800F54F8u: goto label_800F54F8;
    case 0x800F54FCu: goto label_800F54FC;
    case 0x800F5520u: goto label_800F5520;
    case 0x800F5524u: goto label_800F5524;
    case 0x800F554Cu: goto label_800F554C;
    case 0x800F5560u: goto label_800F5560;
    case 0x800F5598u: goto label_800F5598;
    case 0x800F559Cu: goto label_800F559C;
    case 0x800F55C0u: goto label_800F55C0;
    case 0x800F55C4u: goto label_800F55C4;
    case 0x800F560Cu: goto label_800F560C;
    case 0x800F562Cu: goto label_800F562C;
    case 0x800F564Cu: goto label_800F564C;
    case 0x800F566Cu: goto label_800F566C;
    case 0x800F568Cu: goto label_800F568C;
    case 0x800F56ACu: goto label_800F56AC;
    case 0x800F56CCu: goto label_800F56CC;
    case 0x800F56ECu: goto label_800F56EC;
    case 0x800F570Cu: goto label_800F570C;
    case 0x800F572Cu: goto label_800F572C;
    case 0x800F574Cu: goto label_800F574C;
    case 0x800F576Cu: goto label_800F576C;
    case 0x800F578Cu: goto label_800F578C;
    case 0x800F57ACu: goto label_800F57AC;
    case 0x800F57CCu: goto label_800F57CC;
    case 0x800F57ECu: goto label_800F57EC;
    case 0x800F580Cu: goto label_800F580C;
    case 0x800F5844u: goto label_800F5844;
    case 0x800F585Cu: goto label_800F585C;
    case 0x800F5884u: goto label_800F5884;
    case 0x800F588Cu: goto label_800F588C;
    case 0x800F589Cu: goto label_800F589C;
    case 0x800F58E0u: goto label_800F58E0;
    case 0x800F58F8u: goto label_800F58F8;
    case 0x800F5920u: goto label_800F5920;
    case 0x800F5928u: goto label_800F5928;
    case 0x800F5938u: goto label_800F5938;
    case 0x800F5964u: goto label_800F5964;
    case 0x800F5984u: goto label_800F5984;
    case 0x800F59A4u: goto label_800F59A4;
    case 0x800F59C4u: goto label_800F59C4;
    case 0x800F59E4u: goto label_800F59E4;
    case 0x800F5A04u: goto label_800F5A04;
    case 0x800F5A24u: goto label_800F5A24;
    case 0x800F5A44u: goto label_800F5A44;
    case 0x800F5A64u: goto label_800F5A64;
    case 0x800F5A84u: goto label_800F5A84;
    case 0x800F5AA4u: goto label_800F5AA4;
    case 0x800F5AC4u: goto label_800F5AC4;
    case 0x800F5AE4u: goto label_800F5AE4;
    case 0x800F5B04u: goto label_800F5B04;
    case 0x800F5B30u: goto label_800F5B30;
    case 0x800F5B84u: goto label_800F5B84;
    case 0x800F5BA4u: goto label_800F5BA4;
    case 0x800F5BC4u: goto label_800F5BC4;
    case 0x800F5BE4u: goto label_800F5BE4;
    case 0x800F5C04u: goto label_800F5C04;
    case 0x800F5C24u: goto label_800F5C24;
    case 0x800F5C44u: goto label_800F5C44;
    case 0x800F5C64u: goto label_800F5C64;
    case 0x800F5C84u: goto label_800F5C84;
    case 0x800F5CA4u: goto label_800F5CA4;
    case 0x800F5CD4u: goto label_800F5CD4;
    case 0x800F5D00u: goto label_800F5D00;
    case 0x800F5D34u: goto label_800F5D34;
    case 0x800F5D54u: goto label_800F5D54;
    case 0x800F5D68u: goto label_800F5D68;
    case 0x800F5DC0u: goto label_800F5DC0;
    case 0x800F5DCCu: goto label_800F5DCC;
    case 0x800F5EA0u: goto label_800F5EA0;
    case 0x800F5EF0u: goto label_800F5EF0;
    case 0x800F5F78u: goto label_800F5F78;
    case 0x800F602Cu: goto label_800F602C;
    case 0x800F6040u: goto label_800F6040;
    case 0x800F6054u: goto label_800F6054;
    case 0x800F6068u: goto label_800F6068;
    case 0x800F607Cu: goto label_800F607C;
    case 0x800F6090u: goto label_800F6090;
    case 0x800F60A4u: goto label_800F60A4;
    case 0x800F60B8u: goto label_800F60B8;
    case 0x800F60CCu: goto label_800F60CC;
    case 0x800F60E0u: goto label_800F60E0;
    case 0x800F60F4u: goto label_800F60F4;
    case 0x800F6108u: goto label_800F6108;
    case 0x800F6134u: goto label_800F6134;
    case 0x800F613Cu: goto label_800F613C;
    case 0x800F6168u: goto label_800F6168;
    case 0x800F61ACu: goto label_800F61AC;
    case 0x800F61D8u: goto label_800F61D8;
    case 0x800F62A8u: goto label_800F62A8;
    case 0x800F62F8u: goto label_800F62F8;
    case 0x800F6380u: goto label_800F6380;
    case 0x800F6434u: goto label_800F6434;
    case 0x800F6448u: goto label_800F6448;
    case 0x800F645Cu: goto label_800F645C;
    case 0x800F6470u: goto label_800F6470;
    case 0x800F6484u: goto label_800F6484;
    case 0x800F6498u: goto label_800F6498;
    case 0x800F64ACu: goto label_800F64AC;
    case 0x800F64C0u: goto label_800F64C0;
    case 0x800F64D4u: goto label_800F64D4;
    case 0x800F64E8u: goto label_800F64E8;
    case 0x800F64FCu: goto label_800F64FC;
    case 0x800F6510u: goto label_800F6510;
    case 0x800F653Cu: goto label_800F653C;
    case 0x800F6544u: goto label_800F6544;
    case 0x800F6570u: goto label_800F6570;
    case 0x800F65DCu: goto label_800F65DC;
    case 0x800F6608u: goto label_800F6608;
    case 0x800F6650u: goto label_800F6650;
    case 0x800F6678u: goto label_800F6678;
    case 0x800F6684u: goto label_800F6684;
    case 0x800F66B0u: goto label_800F66B0;
    case 0x800F66D0u: goto label_800F66D0;
    case 0x800F671Cu: goto label_800F671C;
    case 0x800F6764u: goto label_800F6764;
    case 0x800F6778u: goto label_800F6778;
    case 0x800F678Cu: goto label_800F678C;
    case 0x800F67A0u: goto label_800F67A0;
    case 0x800F67B4u: goto label_800F67B4;
    case 0x800F67E0u: goto label_800F67E0;
    case 0x800F67E8u: goto label_800F67E8;
    case 0x800F6814u: goto label_800F6814;
    case 0x800F686Cu: goto label_800F686C;
    case 0x800F687Cu: goto label_800F687C;
    case 0x800F68DCu: goto label_800F68DC;
    case 0x800F6944u: goto label_800F6944;
    case 0x800F69ACu: goto label_800F69AC;
    case 0x800F69B8u: goto label_800F69B8;
    case 0x800F69E8u: goto label_800F69E8;
    case 0x800F6AB8u: goto label_800F6AB8;
    case 0x800F6B08u: goto label_800F6B08;
    case 0x800F6B90u: goto label_800F6B90;
    case 0x800F6C44u: goto label_800F6C44;
    case 0x800F6C58u: goto label_800F6C58;
    case 0x800F6C6Cu: goto label_800F6C6C;
    case 0x800F6C94u: goto label_800F6C94;
    case 0x800F6CD8u: goto label_800F6CD8;
    case 0x800F6D1Cu: goto label_800F6D1C;
    case 0x800F6D40u: goto label_800F6D40;
    case 0x800F6D78u: goto label_800F6D78;
    case 0x800F6DBCu: goto label_800F6DBC;
    case 0x800F6EECu: goto label_800F6EEC;
    case 0x800F734Cu: goto label_800F734C;
    case 0x800F7364u: goto label_800F7364;
    case 0x800F7390u: goto label_800F7390;
    case 0x800F73A8u: goto label_800F73A8;
    default: return;
    }
}

