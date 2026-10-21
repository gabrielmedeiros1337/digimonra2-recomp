// DolRecomp output
#include "../generated.h"

static void loop_80003298(CPUState* ctx) {
label_80003298:
    ctx->downcount -= 5;
    // 80003298: addi    r6, r6, 4
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(4);

    ctx->pc = 0x8000329Cu;
    // 8000329C: lwz     r7, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

    // 800032A0: add   r7, r7, r5
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

    ctx->pc = 0x800032A4u;
    // 800032A4: stw     r7, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

    // 800032A8: bc    16, 0, 0x80003298
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80003298u;
                return;
            }
            goto label_80003298;
        }
    }

    ctx->pc = 0x800032ACu;
}

void func_80003100(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x80003100u: goto label_80003100;
    case 0x80003104u: goto label_80003104;
    case 0x80003108u: goto label_80003108;
    case 0x8000310Cu: goto label_8000310C;
    case 0x80003110u: goto label_80003110;
    case 0x80003114u: goto label_80003114;
    case 0x80003118u: goto label_80003118;
    case 0x8000311Cu: goto label_8000311C;
    case 0x80003120u: goto label_80003120;
    case 0x80003124u: goto label_80003124;
    case 0x80003128u: goto label_80003128;
    case 0x8000312Cu: goto label_8000312C;
    case 0x80003130u: goto label_80003130;
    case 0x80003134u: goto label_80003134;
    case 0x80003138u: goto label_80003138;
    case 0x8000313Cu: goto label_8000313C;
    case 0x80003140u: goto label_80003140;
    case 0x80003144u: goto label_80003144;
    case 0x80003148u: goto label_80003148;
    case 0x8000314Cu: goto label_8000314C;
    case 0x80003150u: goto label_80003150;
    case 0x80003154u: goto label_80003154;
    case 0x80003158u: goto label_80003158;
    case 0x8000315Cu: goto label_8000315C;
    case 0x80003160u: goto label_80003160;
    case 0x80003164u: goto label_80003164;
    case 0x80003168u: goto label_80003168;
    case 0x8000316Cu: goto label_8000316C;
    case 0x80003170u: goto label_80003170;
    case 0x80003174u: goto label_80003174;
    case 0x80003178u: goto label_80003178;
    case 0x8000317Cu: goto label_8000317C;
    case 0x80003180u: goto label_80003180;
    case 0x80003184u: goto label_80003184;
    case 0x80003188u: goto label_80003188;
    case 0x8000318Cu: goto label_8000318C;
    case 0x80003190u: goto label_80003190;
    case 0x80003194u: goto label_80003194;
    case 0x80003198u: goto label_80003198;
    case 0x8000319Cu: goto label_8000319C;
    case 0x800031A0u: goto label_800031A0;
    case 0x800031A4u: goto label_800031A4;
    case 0x800031A8u: goto label_800031A8;
    case 0x800031ACu: goto label_800031AC;
    case 0x800031B0u: goto label_800031B0;
    case 0x800031B4u: goto label_800031B4;
    case 0x800031B8u: goto label_800031B8;
    case 0x800031BCu: goto label_800031BC;
    case 0x800031C0u: goto label_800031C0;
    case 0x800031C4u: goto label_800031C4;
    case 0x800031C8u: goto label_800031C8;
    case 0x800031CCu: goto label_800031CC;
    case 0x800031D0u: goto label_800031D0;
    case 0x800031D4u: goto label_800031D4;
    case 0x800031D8u: goto label_800031D8;
    case 0x800031DCu: goto label_800031DC;
    case 0x800031E0u: goto label_800031E0;
    case 0x800031E4u: goto label_800031E4;
    case 0x800031E8u: goto label_800031E8;
    case 0x800031ECu: goto label_800031EC;
    case 0x800031F0u: goto label_800031F0;
    case 0x800031F4u: goto label_800031F4;
    case 0x800031F8u: goto label_800031F8;
    case 0x800031FCu: goto label_800031FC;
    case 0x80003200u: goto label_80003200;
    case 0x80003204u: goto label_80003204;
    case 0x80003208u: goto label_80003208;
    case 0x8000320Cu: goto label_8000320C;
    case 0x80003210u: goto label_80003210;
    case 0x80003214u: goto label_80003214;
    case 0x80003218u: goto label_80003218;
    case 0x8000321Cu: goto label_8000321C;
    case 0x80003220u: goto label_80003220;
    case 0x80003224u: goto label_80003224;
    case 0x80003228u: goto label_80003228;
    case 0x8000322Cu: goto label_8000322C;
    case 0x80003230u: goto label_80003230;
    case 0x80003234u: goto label_80003234;
    case 0x80003238u: goto label_80003238;
    case 0x8000323Cu: goto label_8000323C;
    case 0x80003240u: goto label_80003240;
    case 0x80003244u: goto label_80003244;
    case 0x80003248u: goto label_80003248;
    case 0x8000324Cu: goto label_8000324C;
    case 0x80003250u: goto label_80003250;
    case 0x80003254u: goto label_80003254;
    case 0x80003258u: goto label_80003258;
    case 0x8000325Cu: goto label_8000325C;
    case 0x80003260u: goto label_80003260;
    case 0x80003264u: goto label_80003264;
    case 0x80003268u: goto label_80003268;
    case 0x8000326Cu: goto label_8000326C;
    case 0x80003270u: goto label_80003270;
    case 0x80003274u: goto label_80003274;
    case 0x80003278u: goto label_80003278;
    case 0x8000327Cu: goto label_8000327C;
    case 0x80003280u: goto label_80003280;
    case 0x80003284u: goto label_80003284;
    case 0x80003288u: goto label_80003288;
    case 0x8000328Cu: goto label_8000328C;
    case 0x80003290u: goto label_80003290;
    case 0x80003294u: goto label_80003294;
    case 0x80003298u: goto label_80003298;
    case 0x8000329Cu: goto label_8000329C;
    case 0x800032A0u: goto label_800032A0;
    case 0x800032A4u: goto label_800032A4;
    case 0x800032A8u: goto label_800032A8;
    case 0x800032ACu: goto label_800032AC;
    case 0x800032B0u: goto label_800032B0;
    case 0x800032B4u: goto label_800032B4;
    case 0x800032B8u: goto label_800032B8;
    case 0x800032BCu: goto label_800032BC;
    case 0x800032C0u: goto label_800032C0;
    case 0x800032C4u: goto label_800032C4;
    case 0x800032C8u: goto label_800032C8;
    case 0x800032CCu: goto label_800032CC;
    case 0x800032D0u: goto label_800032D0;
    case 0x800032D4u: goto label_800032D4;
    case 0x800032D8u: goto label_800032D8;
    case 0x800032DCu: goto label_800032DC;
    case 0x800032E0u: goto label_800032E0;
    case 0x800032E4u: goto label_800032E4;
    case 0x800032E8u: goto label_800032E8;
    case 0x800032ECu: goto label_800032EC;
    case 0x800032F0u: goto label_800032F0;
    case 0x800032F4u: goto label_800032F4;
    case 0x800032F8u: goto label_800032F8;
    case 0x800032FCu: goto label_800032FC;
    case 0x80003300u: goto label_80003300;
    case 0x80003304u: goto label_80003304;
    case 0x80003308u: goto label_80003308;
    case 0x8000330Cu: goto label_8000330C;
    case 0x80003310u: goto label_80003310;
    case 0x80003314u: goto label_80003314;
    case 0x80003318u: goto label_80003318;
    case 0x8000331Cu: goto label_8000331C;
    case 0x80003320u: goto label_80003320;
    case 0x80003324u: goto label_80003324;
    case 0x80003328u: goto label_80003328;
    case 0x8000332Cu: goto label_8000332C;
    case 0x80003330u: goto label_80003330;
    case 0x80003334u: goto label_80003334;
    case 0x80003338u: goto label_80003338;
    case 0x8000333Cu: goto label_8000333C;
    case 0x80003340u: goto label_80003340;
    case 0x80003344u: goto label_80003344;
    case 0x80003348u: goto label_80003348;
    case 0x8000334Cu: goto label_8000334C;
    case 0x80003350u: goto label_80003350;
    case 0x80003354u: goto label_80003354;
    case 0x80003358u: goto label_80003358;
    case 0x8000335Cu: goto label_8000335C;
    case 0x80003360u: goto label_80003360;
    case 0x80003364u: goto label_80003364;
    case 0x80003368u: goto label_80003368;
    case 0x8000336Cu: goto label_8000336C;
    case 0x80003370u: goto label_80003370;
    case 0x80003374u: goto label_80003374;
    case 0x80003378u: goto label_80003378;
    case 0x8000337Cu: goto label_8000337C;
    case 0x80003380u: goto label_80003380;
    case 0x80003384u: goto label_80003384;
    case 0x80003388u: goto label_80003388;
    case 0x8000338Cu: goto label_8000338C;
    case 0x80003390u: goto label_80003390;
    case 0x80003394u: goto label_80003394;
    case 0x80003398u: goto label_80003398;
    case 0x8000339Cu: goto label_8000339C;
    case 0x800033A0u: goto label_800033A0;
    case 0x800033A4u: goto label_800033A4;
    case 0x800033A8u: goto label_800033A8;
    case 0x800033ACu: goto label_800033AC;
    case 0x800033B0u: goto label_800033B0;
    case 0x800033B4u: goto label_800033B4;
    case 0x800033B8u: goto label_800033B8;
    case 0x800033BCu: goto label_800033BC;
    case 0x800033C0u: goto label_800033C0;
    case 0x800033C4u: goto label_800033C4;
    case 0x800033C8u: goto label_800033C8;
    case 0x800033CCu: goto label_800033CC;
    case 0x800033D0u: goto label_800033D0;
    case 0x800033D4u: goto label_800033D4;
    case 0x800033D8u: goto label_800033D8;
    case 0x800033DCu: goto label_800033DC;
    case 0x800033E0u: goto label_800033E0;
    case 0x800033E4u: goto label_800033E4;
    case 0x800033E8u: goto label_800033E8;
    case 0x800033ECu: goto label_800033EC;
    case 0x800033F0u: goto label_800033F0;
    case 0x800033F4u: goto label_800033F4;
    case 0x800033F8u: goto label_800033F8;
    case 0x800033FCu: goto label_800033FC;
    case 0x80003400u: goto label_80003400;
    case 0x80003404u: goto label_80003404;
    case 0x80003408u: goto label_80003408;
    case 0x8000340Cu: goto label_8000340C;
    case 0x80003410u: goto label_80003410;
    case 0x80003414u: goto label_80003414;
    case 0x80003418u: goto label_80003418;
    case 0x8000341Cu: goto label_8000341C;
    case 0x80003420u: goto label_80003420;
    case 0x80003424u: goto label_80003424;
    case 0x80003428u: goto label_80003428;
    case 0x8000342Cu: goto label_8000342C;
    case 0x80003430u: goto label_80003430;
    case 0x80003434u: goto label_80003434;
    case 0x80003438u: goto label_80003438;
    case 0x8000343Cu: goto label_8000343C;
    case 0x80003440u: goto label_80003440;
    case 0x80003444u: goto label_80003444;
    case 0x80003448u: goto label_80003448;
    case 0x8000344Cu: goto label_8000344C;
    case 0x80003450u: goto label_80003450;
    case 0x80003454u: goto label_80003454;
    case 0x80003458u: goto label_80003458;
    case 0x8000345Cu: goto label_8000345C;
    case 0x80003460u: goto label_80003460;
    case 0x80003464u: goto label_80003464;
    case 0x80003468u: goto label_80003468;
    case 0x8000346Cu: goto label_8000346C;
    case 0x80003470u: goto label_80003470;
    case 0x80003474u: goto label_80003474;
    case 0x80003478u: goto label_80003478;
    case 0x8000347Cu: goto label_8000347C;
    case 0x80003480u: goto label_80003480;
    case 0x80003484u: goto label_80003484;
    case 0x80003488u: goto label_80003488;
    case 0x8000348Cu: goto label_8000348C;
    case 0x80003490u: goto label_80003490;
    case 0x80003494u: goto label_80003494;
    case 0x80003498u: goto label_80003498;
    case 0x8000349Cu: goto label_8000349C;
    case 0x800034A0u: goto label_800034A0;
    case 0x800034A4u: goto label_800034A4;
    case 0x800034A8u: goto label_800034A8;
    case 0x800034ACu: goto label_800034AC;
    case 0x800034B0u: goto label_800034B0;
    case 0x800034B4u: goto label_800034B4;
    case 0x800034B8u: goto label_800034B8;
    case 0x800034BCu: goto label_800034BC;
    default: return;
    }
label_80003100:
    ctx->pc = 0x80003100u;
    ctx->downcount -= 7;
    // 80003100: lis     r1, -32707
    ctx->gpr[1] = ((u32)(s32)(-32707) << 16);

label_80003104:
    ctx->pc = 0x80003104u;
    // 80003104: ori     r1, r1, 0x54E0
    ctx->gpr[1] = ctx->gpr[1] | 0x54E0u;

label_80003108:
    ctx->pc = 0x80003108u;
    // 80003108: lis     r2, -32707
    ctx->gpr[2] = ((u32)(s32)(-32707) << 16);

label_8000310C:
    ctx->pc = 0x8000310Cu;
    // 8000310C: ori     r2, r2, 0x6020
    ctx->gpr[2] = ctx->gpr[2] | 0x6020u;

label_80003110:
    ctx->pc = 0x80003110u;
    // 80003110: lis     r13, -32708
    ctx->gpr[13] = ((u32)(s32)(-32708) << 16);

label_80003114:
    ctx->pc = 0x80003114u;
    // 80003114: ori     r13, r13, 0x6020
    ctx->gpr[13] = ctx->gpr[13] | 0x6020u;

label_80003118:
    ctx->pc = 0x80003118u;
    // 80003118: bl      0x80003300
    {
            ctx->lr = 0x8000311Cu;
            goto label_80003300;
    }

label_8000311C:
    ctx->pc = 0x8000311Cu;
    ctx->downcount -= 1;
    // 8000311C: bl      0x80003334
    {
            ctx->lr = 0x80003120u;
            goto label_80003334;
    }

label_80003120:
    ctx->pc = 0x80003120u;
    ctx->downcount -= 1;
    // 80003120: bl      0x80003468
    {
            ctx->lr = 0x80003124u;
            goto label_80003468;
    }

label_80003124:
    ctx->pc = 0x80003124u;
    ctx->downcount -= 11;
    // 80003124: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80003128:
    ctx->pc = 0x80003128u;
    // 80003128: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8000312C:
    ctx->pc = 0x8000312Cu;
    // 8000312C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80003130:
    ctx->pc = 0x80003130u;
    // 80003130: stw     r0, 0(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80003134:
    ctx->pc = 0x80003134u;
    // 80003134: lis     r3, -32715
    ctx->gpr[3] = ((u32)(s32)(-32715) << 16);

label_80003138:
    ctx->pc = 0x80003138u;
    // 80003138: ori     r3, r3, 0x9200
    ctx->gpr[3] = ctx->gpr[3] | 0x9200u;

label_8000313C:
    ctx->pc = 0x8000313Cu;
    // 8000313C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80003140:
    ctx->pc = 0x80003140u;
    // 80003140: lis     r5, -32709
    ctx->gpr[5] = ((u32)(s32)(-32709) << 16);

label_80003144:
    ctx->pc = 0x80003144u;
    // 80003144: ori     r5, r5, 0xE010
    ctx->gpr[5] = ctx->gpr[5] | 0xE010u;

label_80003148:
    ctx->pc = 0x80003148u;
    // 80003148: subf   r5, r3, r5
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8000314C:
    ctx->pc = 0x8000314Cu;
    // 8000314C: bl      0x80297F28
    {
            ctx->lr = 0x80003150u;
            ctx->pc = 0x80297F28u;
            return;
    }

label_80003150:
    ctx->pc = 0x80003150u;
    ctx->downcount -= 7;
    // 80003150: lis     r3, -32709
    ctx->gpr[3] = ((u32)(s32)(-32709) << 16);

label_80003154:
    ctx->pc = 0x80003154u;
    // 80003154: ori     r3, r3, 0xF360
    ctx->gpr[3] = ctx->gpr[3] | 0xF360u;

label_80003158:
    ctx->pc = 0x80003158u;
    // 80003158: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8000315C:
    ctx->pc = 0x8000315Cu;
    // 8000315C: lis     r5, -32709
    ctx->gpr[5] = ((u32)(s32)(-32709) << 16);

label_80003160:
    ctx->pc = 0x80003160u;
    // 80003160: ori     r5, r5, 0xFE88
    ctx->gpr[5] = ctx->gpr[5] | 0xFE88u;

label_80003164:
    ctx->pc = 0x80003164u;
    // 80003164: subf   r5, r3, r5
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_80003168:
    ctx->pc = 0x80003168u;
    // 80003168: bl      0x80297F28
    {
            ctx->lr = 0x8000316Cu;
            ctx->pc = 0x80297F28u;
            return;
    }

label_8000316C:
    ctx->pc = 0x8000316Cu;
    ctx->downcount -= 9;
    // 8000316C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80003170:
    ctx->pc = 0x80003170u;
    // 80003170: lis     r5, -32768
    ctx->gpr[5] = ((u32)(s32)(-32768) << 16);

label_80003174:
    ctx->pc = 0x80003174u;
    // 80003174: stw     r4, 68(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80003178:
    ctx->pc = 0x80003178u;
    // 80003178: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8000317C:
    ctx->pc = 0x8000317Cu;
    // 8000317C: lis     r6, -32768
    ctx->gpr[6] = ((u32)(s32)(-32768) << 16);

label_80003180:
    ctx->pc = 0x80003180u;
    // 80003180: ori     r6, r6, 0x00F4
    ctx->gpr[6] = ctx->gpr[6] | 0x00F4u;

label_80003184:
    ctx->pc = 0x80003184u;
    // 80003184: lwz     r6, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80003188:
    ctx->pc = 0x80003188u;
    // 80003188: cmpwi   r6, 0
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

label_8000318C:
    ctx->pc = 0x8000318Cu;
    // 8000318C: bc    12, 2, 0x800031A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800031A4;
        }
    }

label_80003190:
    ctx->pc = 0x80003190u;
    ctx->downcount -= 3;
    // 80003190: lwz     r3, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80003194:
    ctx->pc = 0x80003194u;
    // 80003194: cmplwi  r3, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80003198:
    ctx->pc = 0x80003198u;
    // 80003198: bc    12, 0, 0x800031A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800031A4;
        }
    }

label_8000319C:
    ctx->pc = 0x8000319Cu;
    ctx->downcount -= 1;
    // 8000319C: bl      0x8028F4DC
    {
            ctx->lr = 0x800031A0u;
            ctx->pc = 0x8028F4DCu;
            return;
    }

label_800031A0:
    ctx->pc = 0x800031A0u;
    ctx->downcount -= 1;
    // 800031A0: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_800031A4:
    ctx->pc = 0x800031A4u;
    ctx->downcount -= 1;
    // 800031A4: bl      0x80003254
    {
            ctx->lr = 0x800031A8u;
            goto label_80003254;
    }

label_800031A8:
    ctx->pc = 0x800031A8u;
    ctx->downcount -= 3;
    // 800031A8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800031AC:
    ctx->pc = 0x800031ACu;
    // 800031AC: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800031B0:
    ctx->pc = 0x800031B0u;
    // 800031B0: bl      0x802AF3C8
    {
            ctx->lr = 0x800031B4u;
            ctx->pc = 0x802AF3C8u;
            return;
    }

label_800031B4:
    ctx->pc = 0x800031B4u;
    ctx->downcount -= 1;
    // 800031B4: bl      0x802BD0A8
    {
            ctx->lr = 0x800031B8u;
            ctx->pc = 0x802BD0A8u;
            return;
    }

label_800031B8:
    ctx->pc = 0x800031B8u;
    ctx->downcount -= 4;
    // 800031B8: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_800031BC:
    ctx->pc = 0x800031BCu;
    // 800031BC: lhz     r3, 12518(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12518);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_800031C0:
    ctx->pc = 0x800031C0u;
    // 800031C0: andi.   r4, r3, 0x8000
    {
        ctx->gpr[4] = ctx->gpr[3] & 0x8000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800031C4:
    ctx->pc = 0x800031C4u;
    // 800031C4: bc    12, 2, 0x800031D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800031D4;
        }
    }

label_800031C8:
    ctx->pc = 0x800031C8u;
    ctx->downcount -= 3;
    // 800031C8: andi.   r3, r3, 0x7FFF
    {
        ctx->gpr[3] = ctx->gpr[3] & 0x7FFFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800031CC:
    ctx->pc = 0x800031CCu;
    // 800031CC: cmplwi  r3, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800031D0:
    ctx->pc = 0x800031D0u;
    // 800031D0: bc    4, 2, 0x800031D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800031D8;
        }
    }

label_800031D4:
    ctx->pc = 0x800031D4u;
    ctx->downcount -= 1;
    // 800031D4: bl      0x800032C0
    {
            ctx->lr = 0x800031D8u;
            goto label_800032C0;
    }

label_800031D8:
    ctx->pc = 0x800031D8u;
    ctx->downcount -= 1;
    // 800031D8: bl      0x80003464
    {
            ctx->lr = 0x800031DCu;
            goto label_80003464;
    }

label_800031DC:
    ctx->pc = 0x800031DCu;
    ctx->downcount -= 3;
    // 800031DC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800031E0:
    ctx->pc = 0x800031E0u;
    // 800031E0: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800031E4:
    ctx->pc = 0x800031E4u;
    // 800031E4: bl      0x80003464
    {
            ctx->lr = 0x800031E8u;
            goto label_80003464;
    }

label_800031E8:
    ctx->pc = 0x800031E8u;
    ctx->downcount -= 1;
    // 800031E8: bl      0x802C9BF8
    {
            ctx->lr = 0x800031ECu;
            ctx->pc = 0x802C9BF8u;
            return;
    }

label_800031EC:
    ctx->pc = 0x800031ECu;
    ctx->downcount -= 2;
    // 800031EC: cmpwi   r29, 0
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

label_800031F0:
    ctx->pc = 0x800031F0u;
    // 800031F0: bc    12, 2, 0x80003244
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80003244;
        }
    }

label_800031F4:
    ctx->pc = 0x800031F4u;
    ctx->downcount -= 6;
    // 800031F4: lis     r3, -32716
    ctx->gpr[3] = ((u32)(s32)(-32716) << 16);

label_800031F8:
    ctx->pc = 0x800031F8u;
    // 800031F8: ori     r3, r3, 0xE340
    ctx->gpr[3] = ctx->gpr[3] | 0xE340u;

label_800031FC:
    ctx->pc = 0x800031FCu;
    // 800031FC: lis     r4, -32716
    ctx->gpr[4] = ((u32)(s32)(-32716) << 16);

label_80003200:
    ctx->pc = 0x80003200u;
    // 80003200: ori     r4, r4, 0xE364
    ctx->gpr[4] = ctx->gpr[4] | 0xE364u;

label_80003204:
    ctx->pc = 0x80003204u;
    // 80003204: lwz     r4, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80003208:
    ctx->pc = 0x80003208u;
    // 80003208: bl      0x802C06BC
    {
            ctx->lr = 0x8000320Cu;
            ctx->pc = 0x802C06BCu;
            return;
    }

label_8000320C:
    ctx->pc = 0x8000320Cu;
    ctx->downcount -= 3;
    // 8000320C: lis     r3, -32716
    ctx->gpr[3] = ((u32)(s32)(-32716) << 16);

label_80003210:
    ctx->pc = 0x80003210u;
    // 80003210: ori     r3, r3, 0xE320
    ctx->gpr[3] = ctx->gpr[3] | 0xE320u;

label_80003214:
    ctx->pc = 0x80003214u;
    // 80003214: bl      0x802C06BC
    {
            ctx->lr = 0x80003218u;
            ctx->pc = 0x802C06BCu;
            return;
    }

label_80003218:
    ctx->pc = 0x80003218u;
    ctx->downcount -= 16;
    // 80003218: mfmsr   r5
    ctx->gpr[5] = ctx->msr;

label_8000321C:
    ctx->pc = 0x8000321Cu;
    // 8000321C: ori     r4, r5, 0x8000
    ctx->gpr[4] = ctx->gpr[5] | 0x8000u;

label_80003220:
    ctx->pc = 0x80003220u;
    // 80003220: xori    r4, r4, 0x8000
    ctx->gpr[4] = ctx->gpr[4] ^ 0x8000u;

label_80003224:
    ctx->pc = 0x80003224u;
    // 80003224: mtmsr   r4
    ctx->msr = ctx->gpr[4];

label_80003228:
    ctx->pc = 0x80003228u;
    // 80003228: sync
    ppc_memory_fence();

label_8000322C:
    ctx->pc = 0x8000322Cu;
    // 8000322C: ori     r5, r5, 0x0200
    ctx->gpr[5] = ctx->gpr[5] | 0x0200u;

label_80003230:
    ctx->pc = 0x80003230u;
    // 80003230: mtsrr1    r5
    ctx->srr1 = ctx->gpr[5];

label_80003234:
    ctx->pc = 0x80003234u;
    // 80003234: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_80003238:
    ctx->pc = 0x80003238u;
    // 80003238: ori     r4, r4, 0x3244
    ctx->gpr[4] = ctx->gpr[4] | 0x3244u;

label_8000323C:
    ctx->pc = 0x8000323Cu;
    // 8000323C: mtsrr0    r4
    ctx->srr0 = ctx->gpr[4];

label_80003240:
    ctx->pc = 0x80003240u;
    // 80003240: rfi
    ppc_rfi(ctx, 0x80003240u);
    return;

label_80003244:
    ctx->pc = 0x80003244u;
    ctx->downcount -= 3;
    // 80003244: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80003248:
    ctx->pc = 0x80003248u;
    // 80003248: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8000324C:
    ctx->pc = 0x8000324Cu;
    // 8000324C: bl      0x80110818
    {
            ctx->lr = 0x80003250u;
            ctx->pc = 0x80110818u;
            return;
    }

label_80003250:
    ctx->pc = 0x80003250u;
    ctx->downcount -= 1;
    // 80003250: b       0x802969D0
    {
            ctx->pc = 0x802969D0u;
            return;
    }

label_80003254:
    ctx->pc = 0x80003254u;
    ctx->downcount -= 5;
    // 80003254: lis     r6, -32768
    ctx->gpr[6] = ((u32)(s32)(-32768) << 16);

label_80003258:
    ctx->pc = 0x80003258u;
    // 80003258: ori     r6, r6, 0x00F4
    ctx->gpr[6] = ctx->gpr[6] | 0x00F4u;

label_8000325C:
    ctx->pc = 0x8000325Cu;
    // 8000325C: lwz     r5, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80003260:
    ctx->pc = 0x80003260u;
    // 80003260: cmpwi   r5, 0
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

label_80003264:
    ctx->pc = 0x80003264u;
    // 80003264: bc    4, 2, 0x80003274
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80003274;
        }
    }

label_80003268:
    ctx->downcount -= 3;
    // 80003268: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8000326C:
    // 8000326C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80003270:
    ctx->pc = 0x80003270u;
    // 80003270: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

label_80003274:
    ctx->pc = 0x80003274u;
    ctx->downcount -= 3;
    // 80003274: lwz     r6, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80003278:
    // 80003278: cmpwi   r6, 0
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

label_8000327C:
    // 8000327C: bc    12, 2, 0x80003268
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80003268u;
                return;
            }
            goto label_80003268;
        }
    }

label_80003280:
    ctx->downcount -= 4;
    // 80003280: add   r6, r5, r6
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80003284:
    ctx->pc = 0x80003284u;
    // 80003284: lwz     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80003288:
    // 80003288: cmpwi   r3, 0
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

label_8000328C:
    // 8000328C: bc    12, 2, 0x80003268
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80003268u;
                return;
            }
            goto label_80003268;
        }
    }

label_80003290:
    ctx->pc = 0x80003290u;
    ctx->downcount -= 3;
    // 80003290: addi    r4, r6, 4
    ctx->gpr[4] = ctx->gpr[6] + (u32)(s32)(4);

label_80003294:
    ctx->pc = 0x80003294u;
    // 80003294: mtctr    r3
    ctx->ctr = ctx->gpr[3];

label_80003298:
    loop_80003298(ctx);
    if (ctx->pc == 0x800032ACu) goto label_800032AC;
    return;
label_8000329C:
    ctx->pc = 0x8000329Cu;
    // 8000329C: lwz     r7, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800032A0:
    // 800032A0: add   r7, r7, r5
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_800032A4:
    ctx->pc = 0x800032A4u;
    // 800032A4: stw     r7, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800032A8:
    // 800032A8: bc    16, 0, 0x80003298
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80003298u;
                return;
            }
            goto label_80003298;
        }
    }

label_800032AC:
    ctx->pc = 0x800032ACu;
    ctx->downcount -= 5;
    // 800032AC: lis     r5, -32768
    ctx->gpr[5] = ((u32)(s32)(-32768) << 16);

label_800032B0:
    ctx->pc = 0x800032B0u;
    // 800032B0: ori     r5, r5, 0x0034
    ctx->gpr[5] = ctx->gpr[5] | 0x0034u;

label_800032B4:
    ctx->pc = 0x800032B4u;
    // 800032B4: rlwinm r7, r4, 0, 0, 26
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFE0u;
    }

label_800032B8:
    ctx->pc = 0x800032B8u;
    // 800032B8: stw     r7, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800032BC:
    ctx->pc = 0x800032BCu;
    // 800032BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

label_800032C0:
    ctx->pc = 0x800032C0u;
    ctx->downcount -= 8;
    // 800032C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800032C4:
    ctx->pc = 0x800032C4u;
    // 800032C4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800032C8:
    ctx->pc = 0x800032C8u;
    // 800032C8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800032CC:
    ctx->pc = 0x800032CCu;
    // 800032CC: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_800032D0:
    ctx->pc = 0x800032D0u;
    // 800032D0: lhz     r0, 12516(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12516);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800032D4:
    ctx->pc = 0x800032D4u;
    // 800032D4: andi.   r0, r0, 0x0EEF
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0EEFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800032D8:
    ctx->pc = 0x800032D8u;
    // 800032D8: cmpwi   r0, 3823
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3823);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800032DC:
    ctx->pc = 0x800032DCu;
    // 800032DC: bc    4, 2, 0x800032F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800032F0;
        }
    }

label_800032E0:
    ctx->pc = 0x800032E0u;
    ctx->downcount -= 4;
    // 800032E0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800032E4:
    ctx->pc = 0x800032E4u;
    // 800032E4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800032E8:
    ctx->pc = 0x800032E8u;
    // 800032E8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800032EC:
    ctx->pc = 0x800032ECu;
    // 800032EC: bl      0x802C50DC
    {
            ctx->lr = 0x800032F0u;
            ctx->pc = 0x802C50DCu;
            return;
    }

label_800032F0:
    ctx->pc = 0x800032F0u;
    ctx->downcount -= 5;
    // 800032F0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800032F4:
    ctx->pc = 0x800032F4u;
    // 800032F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800032F8:
    ctx->pc = 0x800032F8u;
    // 800032F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800032FC:
    ctx->pc = 0x800032FCu;
    // 800032FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

label_80003300:
    ctx->pc = 0x80003300u;
    ctx->downcount -= 18;
    // 80003300: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80003304:
    ctx->pc = 0x80003304u;
    // 80003304: mtgqr0    r3
    ctx->gqr[0] = ctx->gpr[3];

label_80003308:
    ctx->pc = 0x80003308u;
    // 80003308: mtgqr1    r3
    ctx->gqr[1] = ctx->gpr[3];

label_8000330C:
    ctx->pc = 0x8000330Cu;
    // 8000330C: mtgqr2    r3
    ctx->gqr[2] = ctx->gpr[3];

label_80003310:
    ctx->pc = 0x80003310u;
    // 80003310: mtgqr3    r3
    ctx->gqr[3] = ctx->gpr[3];

label_80003314:
    ctx->pc = 0x80003314u;
    // 80003314: mtgqr4    r3
    ctx->gqr[4] = ctx->gpr[3];

label_80003318:
    ctx->pc = 0x80003318u;
    // 80003318: mtgqr5    r3
    ctx->gqr[5] = ctx->gpr[3];

label_8000331C:
    ctx->pc = 0x8000331Cu;
    // 8000331C: mtgqr6    r3
    ctx->gqr[6] = ctx->gpr[3];

label_80003320:
    ctx->pc = 0x80003320u;
    // 80003320: mtgqr7    r3
    ctx->gqr[7] = ctx->gpr[3];

label_80003324:
    ctx->pc = 0x80003324u;
    // 80003324: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

label_80003328:
    ctx->pc = 0x80003328u;
    // 80003328: .long   0x00000000
    // embedded data

label_8000332C:
    ctx->pc = 0x8000332Cu;
    // 8000332C: .long   0x00000000
    // embedded data

label_80003330:
    ctx->pc = 0x80003330u;
    // 80003330: .long   0x00000000
    // embedded data

label_80003334:
    ctx->pc = 0x80003334u;
    ctx->downcount -= 6;
    // 80003334: mfmsr   r3
    ctx->gpr[3] = ctx->msr;

label_80003338:
    ctx->pc = 0x80003338u;
    // 80003338: ori     r3, r3, 0x2000
    ctx->gpr[3] = ctx->gpr[3] | 0x2000u;

label_8000333C:
    ctx->pc = 0x8000333Cu;
    // 8000333C: mtmsr   r3
    ctx->msr = ctx->gpr[3];

label_80003340:
    ctx->pc = 0x80003340u;
    // 80003340: mfhid2    r3
    ctx->gpr[3] = ctx->hid2;

label_80003344:
    ctx->pc = 0x80003344u;
    // 80003344: rlwinm. r3, r3, 3, 31, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 3u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80003348:
    ctx->pc = 0x80003348u;
    // 80003348: bc    12, 2, 0x800033D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800033D4;
        }
    }

label_8000334C:
    ctx->pc = 0x8000334Cu;
    ctx->downcount -= 34;
    // 8000334C: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_80003350:
    ctx->pc = 0x80003350u;
    // 80003350: ori     r3, r3, 0x332C
    ctx->gpr[3] = ctx->gpr[3] | 0x332Cu;

label_80003354:
    ctx->pc = 0x80003354u;
    // 80003354: psq_l   f0, 0(r3), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80003354u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ppc_psq_load_inline(ctx, 0u, ea, false, 0u, false, 0x80003354u);
        if (ctx->exception) return;
    }

label_80003358:
    ctx->pc = 0x80003358u;
    // 80003358: ps_mr  f1, f0
    if (!ppc_fp_available_inline(ctx, 0x80003358u)) return;
    ctx->fpr[1] = ctx->fpr[0];
    ctx->ps1[1] = ctx->ps1[0];

label_8000335C:
    ctx->pc = 0x8000335Cu;
    // 8000335C: ps_mr  f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8000335Cu)) return;
    ctx->fpr[2] = ctx->fpr[0];
    ctx->ps1[2] = ctx->ps1[0];

label_80003360:
    ctx->pc = 0x80003360u;
    // 80003360: ps_mr  f3, f0
    if (!ppc_fp_available_inline(ctx, 0x80003360u)) return;
    ctx->fpr[3] = ctx->fpr[0];
    ctx->ps1[3] = ctx->ps1[0];

label_80003364:
    ctx->pc = 0x80003364u;
    // 80003364: ps_mr  f4, f0
    if (!ppc_fp_available_inline(ctx, 0x80003364u)) return;
    ctx->fpr[4] = ctx->fpr[0];
    ctx->ps1[4] = ctx->ps1[0];

label_80003368:
    ctx->pc = 0x80003368u;
    // 80003368: ps_mr  f5, f0
    if (!ppc_fp_available_inline(ctx, 0x80003368u)) return;
    ctx->fpr[5] = ctx->fpr[0];
    ctx->ps1[5] = ctx->ps1[0];

label_8000336C:
    ctx->pc = 0x8000336Cu;
    // 8000336C: ps_mr  f6, f0
    if (!ppc_fp_available_inline(ctx, 0x8000336Cu)) return;
    ctx->fpr[6] = ctx->fpr[0];
    ctx->ps1[6] = ctx->ps1[0];

label_80003370:
    ctx->pc = 0x80003370u;
    // 80003370: ps_mr  f7, f0
    if (!ppc_fp_available_inline(ctx, 0x80003370u)) return;
    ctx->fpr[7] = ctx->fpr[0];
    ctx->ps1[7] = ctx->ps1[0];

label_80003374:
    ctx->pc = 0x80003374u;
    // 80003374: ps_mr  f8, f0
    if (!ppc_fp_available_inline(ctx, 0x80003374u)) return;
    ctx->fpr[8] = ctx->fpr[0];
    ctx->ps1[8] = ctx->ps1[0];

label_80003378:
    ctx->pc = 0x80003378u;
    // 80003378: ps_mr  f9, f0
    if (!ppc_fp_available_inline(ctx, 0x80003378u)) return;
    ctx->fpr[9] = ctx->fpr[0];
    ctx->ps1[9] = ctx->ps1[0];

label_8000337C:
    ctx->pc = 0x8000337Cu;
    // 8000337C: ps_mr  f10, f0
    if (!ppc_fp_available_inline(ctx, 0x8000337Cu)) return;
    ctx->fpr[10] = ctx->fpr[0];
    ctx->ps1[10] = ctx->ps1[0];

label_80003380:
    ctx->pc = 0x80003380u;
    // 80003380: ps_mr  f11, f0
    if (!ppc_fp_available_inline(ctx, 0x80003380u)) return;
    ctx->fpr[11] = ctx->fpr[0];
    ctx->ps1[11] = ctx->ps1[0];

label_80003384:
    ctx->pc = 0x80003384u;
    // 80003384: ps_mr  f12, f0
    if (!ppc_fp_available_inline(ctx, 0x80003384u)) return;
    ctx->fpr[12] = ctx->fpr[0];
    ctx->ps1[12] = ctx->ps1[0];

label_80003388:
    ctx->pc = 0x80003388u;
    // 80003388: ps_mr  f13, f0
    if (!ppc_fp_available_inline(ctx, 0x80003388u)) return;
    ctx->fpr[13] = ctx->fpr[0];
    ctx->ps1[13] = ctx->ps1[0];

label_8000338C:
    ctx->pc = 0x8000338Cu;
    // 8000338C: ps_mr  f14, f0
    if (!ppc_fp_available_inline(ctx, 0x8000338Cu)) return;
    ctx->fpr[14] = ctx->fpr[0];
    ctx->ps1[14] = ctx->ps1[0];

label_80003390:
    ctx->pc = 0x80003390u;
    // 80003390: ps_mr  f15, f0
    if (!ppc_fp_available_inline(ctx, 0x80003390u)) return;
    ctx->fpr[15] = ctx->fpr[0];
    ctx->ps1[15] = ctx->ps1[0];

label_80003394:
    ctx->pc = 0x80003394u;
    // 80003394: ps_mr  f16, f0
    if (!ppc_fp_available_inline(ctx, 0x80003394u)) return;
    ctx->fpr[16] = ctx->fpr[0];
    ctx->ps1[16] = ctx->ps1[0];

label_80003398:
    ctx->pc = 0x80003398u;
    // 80003398: ps_mr  f17, f0
    if (!ppc_fp_available_inline(ctx, 0x80003398u)) return;
    ctx->fpr[17] = ctx->fpr[0];
    ctx->ps1[17] = ctx->ps1[0];

label_8000339C:
    ctx->pc = 0x8000339Cu;
    // 8000339C: ps_mr  f18, f0
    if (!ppc_fp_available_inline(ctx, 0x8000339Cu)) return;
    ctx->fpr[18] = ctx->fpr[0];
    ctx->ps1[18] = ctx->ps1[0];

label_800033A0:
    ctx->pc = 0x800033A0u;
    // 800033A0: ps_mr  f19, f0
    if (!ppc_fp_available_inline(ctx, 0x800033A0u)) return;
    ctx->fpr[19] = ctx->fpr[0];
    ctx->ps1[19] = ctx->ps1[0];

label_800033A4:
    ctx->pc = 0x800033A4u;
    // 800033A4: ps_mr  f20, f0
    if (!ppc_fp_available_inline(ctx, 0x800033A4u)) return;
    ctx->fpr[20] = ctx->fpr[0];
    ctx->ps1[20] = ctx->ps1[0];

label_800033A8:
    ctx->pc = 0x800033A8u;
    // 800033A8: ps_mr  f21, f0
    if (!ppc_fp_available_inline(ctx, 0x800033A8u)) return;
    ctx->fpr[21] = ctx->fpr[0];
    ctx->ps1[21] = ctx->ps1[0];

label_800033AC:
    ctx->pc = 0x800033ACu;
    // 800033AC: ps_mr  f22, f0
    if (!ppc_fp_available_inline(ctx, 0x800033ACu)) return;
    ctx->fpr[22] = ctx->fpr[0];
    ctx->ps1[22] = ctx->ps1[0];

label_800033B0:
    ctx->pc = 0x800033B0u;
    // 800033B0: ps_mr  f23, f0
    if (!ppc_fp_available_inline(ctx, 0x800033B0u)) return;
    ctx->fpr[23] = ctx->fpr[0];
    ctx->ps1[23] = ctx->ps1[0];

label_800033B4:
    ctx->pc = 0x800033B4u;
    // 800033B4: ps_mr  f24, f0
    if (!ppc_fp_available_inline(ctx, 0x800033B4u)) return;
    ctx->fpr[24] = ctx->fpr[0];
    ctx->ps1[24] = ctx->ps1[0];

label_800033B8:
    ctx->pc = 0x800033B8u;
    // 800033B8: ps_mr  f25, f0
    if (!ppc_fp_available_inline(ctx, 0x800033B8u)) return;
    ctx->fpr[25] = ctx->fpr[0];
    ctx->ps1[25] = ctx->ps1[0];

label_800033BC:
    ctx->pc = 0x800033BCu;
    // 800033BC: ps_mr  f26, f0
    if (!ppc_fp_available_inline(ctx, 0x800033BCu)) return;
    ctx->fpr[26] = ctx->fpr[0];
    ctx->ps1[26] = ctx->ps1[0];

label_800033C0:
    ctx->pc = 0x800033C0u;
    // 800033C0: ps_mr  f27, f0
    if (!ppc_fp_available_inline(ctx, 0x800033C0u)) return;
    ctx->fpr[27] = ctx->fpr[0];
    ctx->ps1[27] = ctx->ps1[0];

label_800033C4:
    ctx->pc = 0x800033C4u;
    // 800033C4: ps_mr  f28, f0
    if (!ppc_fp_available_inline(ctx, 0x800033C4u)) return;
    ctx->fpr[28] = ctx->fpr[0];
    ctx->ps1[28] = ctx->ps1[0];

label_800033C8:
    ctx->pc = 0x800033C8u;
    // 800033C8: ps_mr  f29, f0
    if (!ppc_fp_available_inline(ctx, 0x800033C8u)) return;
    ctx->fpr[29] = ctx->fpr[0];
    ctx->ps1[29] = ctx->ps1[0];

label_800033CC:
    ctx->pc = 0x800033CCu;
    // 800033CC: ps_mr  f30, f0
    if (!ppc_fp_available_inline(ctx, 0x800033CCu)) return;
    ctx->fpr[30] = ctx->fpr[0];
    ctx->ps1[30] = ctx->ps1[0];

label_800033D0:
    ctx->pc = 0x800033D0u;
    // 800033D0: ps_mr  f31, f0
    if (!ppc_fp_available_inline(ctx, 0x800033D0u)) return;
    ctx->fpr[31] = ctx->fpr[0];
    ctx->ps1[31] = ctx->ps1[0];

label_800033D4:
    ctx->pc = 0x800033D4u;
    ctx->downcount -= 38;
    // 800033D4: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_800033D8:
    ctx->pc = 0x800033D8u;
    // 800033D8: ori     r3, r3, 0x3328
    ctx->gpr[3] = ctx->gpr[3] | 0x3328u;

label_800033DC:
    ctx->pc = 0x800033DCu;
    // 800033DC: lfd     f0, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x800033DCu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800033E0:
    ctx->pc = 0x800033E0u;
    // 800033E0: fmr    f1, f0
    if (!ppc_fp_available_inline(ctx, 0x800033E0u)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800033E4:
    ctx->pc = 0x800033E4u;
    // 800033E4: fmr    f2, f0
    if (!ppc_fp_available_inline(ctx, 0x800033E4u)) return;
    ctx->fpr[2] = ctx->fpr[0];

label_800033E8:
    ctx->pc = 0x800033E8u;
    // 800033E8: fmr    f3, f0
    if (!ppc_fp_available_inline(ctx, 0x800033E8u)) return;
    ctx->fpr[3] = ctx->fpr[0];

label_800033EC:
    ctx->pc = 0x800033ECu;
    // 800033EC: fmr    f4, f0
    if (!ppc_fp_available_inline(ctx, 0x800033ECu)) return;
    ctx->fpr[4] = ctx->fpr[0];

label_800033F0:
    ctx->pc = 0x800033F0u;
    // 800033F0: fmr    f5, f0
    if (!ppc_fp_available_inline(ctx, 0x800033F0u)) return;
    ctx->fpr[5] = ctx->fpr[0];

label_800033F4:
    ctx->pc = 0x800033F4u;
    // 800033F4: fmr    f6, f0
    if (!ppc_fp_available_inline(ctx, 0x800033F4u)) return;
    ctx->fpr[6] = ctx->fpr[0];

label_800033F8:
    ctx->pc = 0x800033F8u;
    // 800033F8: fmr    f7, f0
    if (!ppc_fp_available_inline(ctx, 0x800033F8u)) return;
    ctx->fpr[7] = ctx->fpr[0];

label_800033FC:
    ctx->pc = 0x800033FCu;
    // 800033FC: fmr    f8, f0
    if (!ppc_fp_available_inline(ctx, 0x800033FCu)) return;
    ctx->fpr[8] = ctx->fpr[0];

label_80003400:
    ctx->pc = 0x80003400u;
    // 80003400: fmr    f9, f0
    if (!ppc_fp_available_inline(ctx, 0x80003400u)) return;
    ctx->fpr[9] = ctx->fpr[0];

label_80003404:
    ctx->pc = 0x80003404u;
    // 80003404: fmr    f10, f0
    if (!ppc_fp_available_inline(ctx, 0x80003404u)) return;
    ctx->fpr[10] = ctx->fpr[0];

label_80003408:
    ctx->pc = 0x80003408u;
    // 80003408: fmr    f11, f0
    if (!ppc_fp_available_inline(ctx, 0x80003408u)) return;
    ctx->fpr[11] = ctx->fpr[0];

label_8000340C:
    ctx->pc = 0x8000340Cu;
    // 8000340C: fmr    f12, f0
    if (!ppc_fp_available_inline(ctx, 0x8000340Cu)) return;
    ctx->fpr[12] = ctx->fpr[0];

label_80003410:
    ctx->pc = 0x80003410u;
    // 80003410: fmr    f13, f0
    if (!ppc_fp_available_inline(ctx, 0x80003410u)) return;
    ctx->fpr[13] = ctx->fpr[0];

label_80003414:
    ctx->pc = 0x80003414u;
    // 80003414: fmr    f14, f0
    if (!ppc_fp_available_inline(ctx, 0x80003414u)) return;
    ctx->fpr[14] = ctx->fpr[0];

label_80003418:
    ctx->pc = 0x80003418u;
    // 80003418: fmr    f15, f0
    if (!ppc_fp_available_inline(ctx, 0x80003418u)) return;
    ctx->fpr[15] = ctx->fpr[0];

label_8000341C:
    ctx->pc = 0x8000341Cu;
    // 8000341C: fmr    f16, f0
    if (!ppc_fp_available_inline(ctx, 0x8000341Cu)) return;
    ctx->fpr[16] = ctx->fpr[0];

label_80003420:
    ctx->pc = 0x80003420u;
    // 80003420: fmr    f17, f0
    if (!ppc_fp_available_inline(ctx, 0x80003420u)) return;
    ctx->fpr[17] = ctx->fpr[0];

label_80003424:
    ctx->pc = 0x80003424u;
    // 80003424: fmr    f18, f0
    if (!ppc_fp_available_inline(ctx, 0x80003424u)) return;
    ctx->fpr[18] = ctx->fpr[0];

label_80003428:
    ctx->pc = 0x80003428u;
    // 80003428: fmr    f19, f0
    if (!ppc_fp_available_inline(ctx, 0x80003428u)) return;
    ctx->fpr[19] = ctx->fpr[0];

label_8000342C:
    ctx->pc = 0x8000342Cu;
    // 8000342C: fmr    f20, f0
    if (!ppc_fp_available_inline(ctx, 0x8000342Cu)) return;
    ctx->fpr[20] = ctx->fpr[0];

label_80003430:
    ctx->pc = 0x80003430u;
    // 80003430: fmr    f21, f0
    if (!ppc_fp_available_inline(ctx, 0x80003430u)) return;
    ctx->fpr[21] = ctx->fpr[0];

label_80003434:
    ctx->pc = 0x80003434u;
    // 80003434: fmr    f22, f0
    if (!ppc_fp_available_inline(ctx, 0x80003434u)) return;
    ctx->fpr[22] = ctx->fpr[0];

label_80003438:
    ctx->pc = 0x80003438u;
    // 80003438: fmr    f23, f0
    if (!ppc_fp_available_inline(ctx, 0x80003438u)) return;
    ctx->fpr[23] = ctx->fpr[0];

label_8000343C:
    ctx->pc = 0x8000343Cu;
    // 8000343C: fmr    f24, f0
    if (!ppc_fp_available_inline(ctx, 0x8000343Cu)) return;
    ctx->fpr[24] = ctx->fpr[0];

label_80003440:
    ctx->pc = 0x80003440u;
    // 80003440: fmr    f25, f0
    if (!ppc_fp_available_inline(ctx, 0x80003440u)) return;
    ctx->fpr[25] = ctx->fpr[0];

label_80003444:
    ctx->pc = 0x80003444u;
    // 80003444: fmr    f26, f0
    if (!ppc_fp_available_inline(ctx, 0x80003444u)) return;
    ctx->fpr[26] = ctx->fpr[0];

label_80003448:
    ctx->pc = 0x80003448u;
    // 80003448: fmr    f27, f0
    if (!ppc_fp_available_inline(ctx, 0x80003448u)) return;
    ctx->fpr[27] = ctx->fpr[0];

label_8000344C:
    ctx->pc = 0x8000344Cu;
    // 8000344C: fmr    f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8000344Cu)) return;
    ctx->fpr[28] = ctx->fpr[0];

label_80003450:
    ctx->pc = 0x80003450u;
    // 80003450: fmr    f29, f0
    if (!ppc_fp_available_inline(ctx, 0x80003450u)) return;
    ctx->fpr[29] = ctx->fpr[0];

label_80003454:
    ctx->pc = 0x80003454u;
    // 80003454: fmr    f30, f0
    if (!ppc_fp_available_inline(ctx, 0x80003454u)) return;
    ctx->fpr[30] = ctx->fpr[0];

label_80003458:
    ctx->pc = 0x80003458u;
    // 80003458: fmr    f31, f0
    if (!ppc_fp_available_inline(ctx, 0x80003458u)) return;
    ctx->fpr[31] = ctx->fpr[0];

label_8000345C:
    ctx->pc = 0x8000345Cu;
    // 8000345C: mtfsf  0xFF, f0
    if (!ppc_fp_available_inline(ctx, 0x8000345Cu)) return;
    {
        u32 mask = 0;
        for (u32 i = 0; i < 8; i++) if (0xFFu & (1u << i)) mask |= 0xFu << (i * 4);
        u32 source = (u32)dolrecomp_f64_to_bits(ctx->fpr[0]);
        ctx->fpscr = (ctx->fpscr & ~mask) | (source & mask);
        ppc_fpscr_updated(ctx);
    }

label_80003460:
    ctx->pc = 0x80003460u;
    // 80003460: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

label_80003464:
    ctx->pc = 0x80003464u;
    ctx->downcount -= 1;
    // 80003464: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

label_80003468:
    ctx->pc = 0x80003468u;
    ctx->downcount -= 5;
    // 80003468: mfmsr   r0
    ctx->gpr[0] = ctx->msr;

label_8000346C:
    ctx->pc = 0x8000346Cu;
    // 8000346C: ori     r0, r0, 0x2000
    ctx->gpr[0] = ctx->gpr[0] | 0x2000u;

label_80003470:
    ctx->pc = 0x80003470u;
    // 80003470: mtmsr   r0
    ctx->msr = ctx->gpr[0];

label_80003474:
    ctx->pc = 0x80003474u;
    // 80003474: mflr    r31
    ctx->gpr[31] = ctx->lr;

label_80003478:
    ctx->pc = 0x80003478u;
    // 80003478: bl      0x802BD84C
    {
            ctx->lr = 0x8000347Cu;
            ctx->pc = 0x802BD84Cu;
            return;
    }

label_8000347C:
    ctx->pc = 0x8000347Cu;
    ctx->downcount -= 1;
    // 8000347C: bl      0x802BCDCC
    {
            ctx->lr = 0x80003480u;
            ctx->pc = 0x802BCDCCu;
            return;
    }

label_80003480:
    ctx->pc = 0x80003480u;
    ctx->downcount -= 1;
    // 80003480: bl      0x802BFBE4
    {
            ctx->lr = 0x80003484u;
            ctx->pc = 0x802BFBE4u;
            return;
    }

label_80003484:
    ctx->pc = 0x80003484u;
    ctx->downcount -= 3;
    // 80003484: mtlr    r31
    ctx->lr = ctx->gpr[31];

label_80003488:
    ctx->pc = 0x80003488u;
    // 80003488: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

label_8000348C:
    ctx->pc = 0x8000348Cu;
    ctx->downcount -= 5;
    // 8000348C: lis     r5, -1
    ctx->gpr[5] = ((u32)(s32)(-1) << 16);

label_80003490:
    ctx->pc = 0x80003490u;
    // 80003490: ori     r5, r5, 0xFFF1
    ctx->gpr[5] = ctx->gpr[5] | 0xFFF1u;

label_80003494:
    ctx->pc = 0x80003494u;
    // 80003494: and   r5, r5, r3
    {
        ctx->gpr[5] = ctx->gpr[5] & ctx->gpr[3];
    }

label_80003498:
    ctx->pc = 0x80003498u;
    // 80003498: subf   r3, r5, r3
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_8000349C:
    ctx->pc = 0x8000349Cu;
    // 8000349C: add   r4, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_800034A0:
    ctx->pc = 0x800034A0u;
    // 800034A0: dcbst    0, r5
    ppc_fallback_instruction(ctx, 0x7C00286Cu, 0x800034A0u);
    return;

label_800034A4:
    ctx->pc = 0x800034A4u;
    ctx->downcount -= 3;
    // 800034A4: sync
    ppc_memory_fence();

label_800034A8:
    ctx->pc = 0x800034A8u;
    // 800034A8: icbi    0, r5
    ppc_fallback_instruction(ctx, 0x7C002FACu, 0x800034A8u);
    return;

label_800034AC:
    ctx->downcount -= 3;
    // 800034AC: addic   r5, r5, 8
    {
        u64 a = ctx->gpr[5];
        u64 b = (u32)(s32)(8);
        u64 res = a + b;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_800034B0:
    // 800034B0: addic.  r4, r4, -8
    {
        u64 a = ctx->gpr[4];
        u64 b = (u32)(s32)(-8);
        u64 res = a + b;
        ctx->gpr[4] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800034B4:
    // 800034B4: bc    4, 0, 0x800034A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800034A0u;
                return;
            }
            goto label_800034A0;
        }
    }

label_800034B8:
    ctx->pc = 0x800034B8u;
    ctx->downcount -= 2;
    // 800034B8: isync
    ppc_memory_fence();

label_800034BC:
    ctx->pc = 0x800034BCu;
    // 800034BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

    ctx->pc = 0x800034C0u;
    return;
return_dispatch_80003100:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x8000311Cu: goto label_8000311C;
    case 0x80003120u: goto label_80003120;
    case 0x80003124u: goto label_80003124;
    case 0x80003150u: goto label_80003150;
    case 0x8000316Cu: goto label_8000316C;
    case 0x800031A0u: goto label_800031A0;
    case 0x800031A8u: goto label_800031A8;
    case 0x800031B4u: goto label_800031B4;
    case 0x800031B8u: goto label_800031B8;
    case 0x800031D8u: goto label_800031D8;
    case 0x800031DCu: goto label_800031DC;
    case 0x800031E8u: goto label_800031E8;
    case 0x800031ECu: goto label_800031EC;
    case 0x8000320Cu: goto label_8000320C;
    case 0x80003218u: goto label_80003218;
    case 0x80003250u: goto label_80003250;
    case 0x800032F0u: goto label_800032F0;
    case 0x8000347Cu: goto label_8000347C;
    case 0x80003480u: goto label_80003480;
    case 0x80003484u: goto label_80003484;
    default: return;
    }
}

